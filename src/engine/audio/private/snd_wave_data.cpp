// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_wave_data.cpp
// Functions: 69
// ============================================================

#include "engine\audio\private\snd_wave_data.h"

//------------------------------------------------------------------------------
// Address: 0x10036EA0
// Name: public: void CAsyncWaveData::DestroyResource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWaveData::DestroyResource(CAsyncWaveData *this)
{
  FSAsyncControl_t__ *m_hAsyncControl; // eax

  m_hAsyncControl = this->m_hAsyncControl;
  if ( m_hAsyncControl != nullptr )
  {
    if ( (*((_BYTE *)this + 84) & 3) == 0 )
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: m_hAsyncControl, a3: true);
    g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: this->m_hAsyncControl);
    this->m_hAsyncControl = nullptr;
  }
  g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: this->m_pAlloc);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x10036F00
// Name: public: char const __near * CAsyncWaveData::GetFileName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAsyncWaveData::GetFileName(CAsyncWaveData *this)
{
  bool v1; // zf
  char *result; // eax

  if ( this->m_hFileNameHandle == nullptr )
    return (char *)defaultValue;
  v1 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260);
  result = sz;
  if ( v1 )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036F40
// Name: public: void CAsyncWaveData::OnAsyncCompleted(struct FileAsyncRequest_t const __near *,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWaveData::OnAsyncCompleted(
        CAsyncWaveData *this,
        const FileAsyncRequest_t *asyncFilePtr,
        int numReadBytes,
        FSAsyncStatus_t err)
{
  int nBytes; // eax
  char *m_pAlloc; // edx
  int v7; // ecx
  int v8; // edx

  if ( err == FSASYNC_OK || err == FSASYNC_ERR_READING )
  {
    this->m_arrival = _Plat_FloatTime();
    nBytes = this->m_async.nBytes;
    this->m_pAlloc = asyncFilePtr->pData;
    m_pAlloc = (char *)this->m_pAlloc;
    v7 = nBytes - this->m_nDataSize;
    this->m_async.nBytes = this->m_nDataSize;
    this->m_pvData = &m_pAlloc[v7];
    v8 = *((_DWORD *)this + 21);
    this->m_async.nOffset = v7;
    this->m_nReadSize = numReadBytes - v7;
    *((_DWORD *)this + 21) = v8 & 0xFFFFFFFA | 1;
  }
  else if ( err == FSASYNC_ERR_FILEOPEN )
  {
    *((_DWORD *)this + 21) |= 2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036FB0
// Name: private: static bool CAsyncWavDataCache::BufferHandleLessFunc(struct CAsyncWavDataCache::BufferEntry_t const __near &,struct CAsyncWavDataCache::BufferEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CAsyncWavDataCache::BufferHandleLessFunc(
        const CAsyncWavDataCache::BufferEntry_t *lhs,
        const CAsyncWavDataCache::BufferEntry_t *rhs)
{
  int v2; // ebx
  int v3; // edi
  bool v4; // cf
  int m_StartPos; // edx
  int v6; // esi

  v2 = *((_DWORD *)rhs + 3);
  v3 = *((_DWORD *)lhs + 3);
  v4 = (v3 & 1u) < (v2 & 1u);
  if ( (v3 & 1) == (v2 & 1) )
  {
    v4 = lhs->m_hName < rhs->m_hName;
    if ( lhs->m_hName == rhs->m_hName )
    {
      m_StartPos = lhs->m_StartPos;
      v6 = rhs->m_StartPos;
      if ( m_StartPos != v6 )
        return m_StartPos < v6;
      return (unsigned __int8)(v3 & 2) < (unsigned __int8)(v2 & 2);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10037010
// Name: public: virtual void CAsyncWavDataCache::PrefetchCache(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::PrefetchCache(
        CAsyncWavDataCache *this,
        const char *filename,
        int datasize,
        int startpos)
{
  this->AsyncLoadCache(this, a2: filename, a3: datasize, a4: startpos, a5: true);
}

//------------------------------------------------------------------------------
// Address: 0x10037030
// Name: void PrefetchDataStream(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrefetchDataStream(const char *pFileName, int dataOffset, int dataSize)
{
  wavedatacache->PrefetchCache(this: wavedatacache, a2: pFileName, a3: dataSize, a4: dataOffset);
}

//------------------------------------------------------------------------------
// Address: 0x10037050
// Name: private: char const __near * CWaveDataStreamAsync::GetFileName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveDataStreamAsync::GetFileName(CWaveDataStreamAsync *this)
{
  bool v1; // zf
  char *result; // eax

  if ( this->m_hFileName == nullptr )
    return (char *)defaultValue;
  v1 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileName, a3: fn, a4: 260);
  result = fn;
  if ( v1 )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037090
// Name: public: virtual void CWaveDataStreamAsync::UpdateLoopPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveDataStreamAsync::UpdateLoopPosition(CWaveDataStreamAsync *this, int nLoopPosition)
{
  int m_hStream; // eax

  m_hStream = this->m_hStream;
  if ( m_hStream != -1 )
    wavedatacache->UpdateLoopPosition(this: wavedatacache, a2: m_hStream, a3: nLoopPosition);
}

//------------------------------------------------------------------------------
// Address: 0x100370C0
// Name: public: virtual int CWaveDataMemoryAsync::ReadSourceData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveDataMemoryAsync::ReadSourceData(
        CWaveDataMemoryAsync *this,
        void **pData,
        __int64 sampleIndex,
        int sampleCount,
        char *copyBuf)
{
  return ((int (__thiscall *)(CAudioSource *, void **, _DWORD, _DWORD, int, char *))this->m_source->GetOutputData)(
           a1: this->m_source,
           a2: pData,
           a3: sampleIndex,
           a4: HIDWORD(sampleIndex),
           a5: sampleCount,
           a6: copyBuf);
}

//------------------------------------------------------------------------------
// Address: 0x100370F0
// Name: bool StringHasPrefix(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl StringHasPrefix(const char *str, const char *prefix)
{
  return StringAfterPrefix(str, prefix) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10037110
// Name: public: static void CAsyncWaveData::AsyncCallback(struct FileAsyncRequest_t const __near &,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAsyncWaveData::AsyncCallback(
        const FileAsyncRequest_t *asyncRequest,
        int numReadBytes,
        FSAsyncStatus_t err)
{
  CAsyncWaveData *pContext; // ecx

  pContext = (CAsyncWaveData *)asyncRequest->pContext;
  if ( pContext != nullptr )
    CAsyncWaveData::OnAsyncCompleted(this: pContext, asyncFilePtr: asyncRequest, numReadBytes, err);
}

//------------------------------------------------------------------------------
// Address: 0x10037130
// Name: public: void CAsyncWaveData::SetAsyncPriority(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWaveData::SetAsyncPriority(CAsyncWaveData *this, int priority)
{
  const char *v3; // edi
  double v4; // [esp+Ch] [ebp-10h]

  if ( this->m_async.priority != priority )
  {
    this->m_async.priority = priority;
    g_pFileSystem->AsyncSetPriority(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: priority);
    if ( snd_async_spew_blocking.m_pParent != nullptr && snd_async_spew_blocking.m_pParent->m_Value.m_nValue >= 2 )
    {
      if ( this->m_hFileNameHandle == nullptr
        || (v3 = sz, !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260)) )
      {
        v3 = defaultValue;
      }
      v4 = (_Plat_FloatTime() - this->m_start) * 1000.0;
      DevMsg(a1: "%f Async I/O Bumped priority for %s (%8.2f msec)\n", realtime, v3, v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100371E0
// Name: public: void CAsyncWaveData::StartAsyncLoading(struct asyncwaveparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWaveData::StartAsyncLoading(CAsyncWaveData *this, const asyncwaveparams_t *params)
{
  void *hFilename; // eax
  bool v4; // zf
  const char *v5; // eax
  BOOL v6; // eax
  int v7; // ecx
  char szFilename[260]; // [esp+8h] [ebp-104h] BYREF

  hFilename = params->hFilename;
  this->m_hFileNameHandle = params->hFilename;
  if ( hFilename == nullptr
    || (v4 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260), v5 = sz, v4) )
  {
    v5 = defaultValue;
  }
  V_snprintf(pDest: szFilename, maxLen: 260, pFormat: "sound\\%s", v5);
  v6 = (*((_BYTE *)params + 16) & 1) == 0;
  this->m_async.pData = nullptr;
  this->m_async.nOffset = 0;
  v7 = params->datasize + params->seekpos;
  *((_DWORD *)this + 21) &= 0xFFFFFFFC;
  this->m_async.nBytes = v7;
  this->m_async.pfnCallback = CAsyncWaveData::AsyncCallback;
  this->m_async.pContext = this;
  this->m_async.priority = v6;
  this->m_async.flags = 1;
  this->m_async.pszPathID = "GAME";
  this->m_nDataSize = params->datasize;
  this->m_start = _Plat_FloatTime();
  *((_DWORD *)this + 21) &= ~4u;
  this->m_arrival = 0.0;
  this->m_nReadSize = 0;
  this->m_async.pszFilename = szFilename;
  g_pFileSystem->AsyncReadMultiple(this: g_pFileSystem, a2: &this->m_async, a3: 1, a4: &this->m_hAsyncControl);
}

//------------------------------------------------------------------------------
// Address: 0x100372D0
// Name: public: virtual bool CAsyncWavDataCache::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncWavDataCache::Init(CAsyncWavDataCache *this, unsigned int memSize)
{
  unsigned int v3; // eax

  if ( this->m_bInitialized )
    return 1;
  v3 = memSize;
  if ( memSize < 0x1400000 )
    v3 = 20971520;
  s_WaveCache.m_nMaxMemorySize = v3;
  this->m_bInitialized = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10037310
// Name: private: void CAsyncWavDataCache::CopyFromCurrentBuffers(struct CAsyncWavDataCache::StreamedEntry_t __near &,struct CAsyncWavDataCache::StreamData_t __near &,int,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::CopyFromCurrentBuffers(
        CAsyncWavDataCache *this,
        CStatTime *streamedEntry,
        CAsyncWavDataCache::StreamData_t *streamData,
        int hStream,
        char *pBuffer,
        int bufferSize,
        int bytesToCopy)
{
  CAsyncWavDataCache::StreamData_t *v7; // esi
  CAsyncWaveData *v8; // edi
  int v9; // ebx
  float m_start; // xmm0_4
  int v11; // esi
  bool v12; // zf
  const char *v13; // eax
  int m_nReadSize; // eax
  int v15; // esi
  char *FileName; // eax
  char v17; // bl
  int v18; // edi
  CAsyncWaveData **pWaveData; // edx
  int *v20; // ecx
  int v21; // eax
  float intervala; // [esp+Ch] [ebp-Ch]
  int interval; // [esp+Ch] [ebp-Ch]
  int nRemainingBytesToCopy; // [esp+10h] [ebp-8h]
  bool bCompleted; // [esp+17h] [ebp-1h]

  nRemainingBytesToCopy = bytesToCopy;
  while ( 1 )
  {
    v7 = streamData;
    v8 = streamData->pWaveData[streamData->index % (int)streamedEntry[11].__vftable];
    v9 = streamData->copyStartPos - v8->m_async.nOffset;
    bCompleted = (*((_BYTE *)v8 + 84) & 3) != 0;
    if ( snd_async_stream_spew.m_pParent != nullptr && snd_async_stream_spew.m_pParent->m_Value.m_nValue >= 1 )
    {
      intervala = _Plat_FloatTime(this: streamedEntry);
      m_start = v8->m_start;
      interval = (int)(float)((float)(intervala - m_start) * 1000.0);
      if ( bCompleted && (*((_BYTE *)v8 + 84) & 1) != 0 )
        v11 = (int)(float)((float)(v8->m_arrival - m_start) * 1000.0);
      else
        v11 = -1;
      if ( v8->m_hFileNameHandle == nullptr
        || (v12 = !g_pFileSystem->String(this: g_pFileSystem, a2: &v8->m_hFileNameHandle, a3: sz, a4: 260), v13 = sz, v12) )
      {
        v13 = defaultValue;
      }
      _Msg(
        a1: "Stream:%2d interval:%5dms latency:%5dms offset:%d length:%d (%s)\n",
        hStream,
        interval,
        v11,
        v8->m_async.nOffset,
        v8->m_nReadSize,
        v13);
      v7 = streamData;
    }
    if ( !bCompleted )
      break;
    if ( v8->m_hAsyncControl != nullptr && (*((_BYTE *)v8 + 84) & 3) != 0 )
    {
      g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: v8->m_hAsyncControl);
      v8->m_hAsyncControl = nullptr;
    }
    if ( (*((_BYTE *)v8 + 84) & 1) == 0 )
    {
      if ( (*((_BYTE *)v8 + 84) & 2) != 0 )
      {
        FileName = CAsyncWaveData::GetFileName(this: v8);
        MaybeReportMissingWav(wav: FileName);
        goto LABEL_34;
      }
      break;
    }
    if ( v9 < 0 )
      goto LABEL_45;
    m_nReadSize = v8->m_nReadSize;
    if ( v9 < m_nReadSize )
    {
      v15 = nRemainingBytesToCopy;
      if ( v9 + nRemainingBytesToCopy > m_nReadSize )
        v15 = m_nReadSize - v9;
      if ( v15 + v9 > bufferSize )
        v15 = bufferSize - v9;
      if ( v15 <= 0 )
      {
        _Warning(
          a1: "%s(%d): Protecting against negative memcpy. BufferSize = %d. Buffer Pos = %d. Count = %d.\n",
          "audio\\private\\snd_wave_data.cpp",
          2051,
          bufferSize,
          v9,
          v15);
        return;
      }
      _V_memcpy(dest: pBuffer, src: (char *)v8->m_pvData + v9, count: v15);
      streamData->actualCopied += v15;
      streamData->copyStartPos += v15;
      nRemainingBytesToCopy -= v15;
      pBuffer += v15;
      v9 += v15;
      bufferSize -= v15;
      v7 = streamData;
    }
    if ( v9 < 0 || v9 >= v8->m_nReadSize )
    {
LABEL_45:
      if ( (signed int)(++v7->index - (unsigned int)streamedEntry[5].__vftable) >= (int)streamedEntry[11].__vftable )
        goto LABEL_34;
    }
    if ( v7->actualCopied == bytesToCopy )
      return;
  }
  v7->bWaiting = true;
LABEL_34:
  v17 = 0;
  if ( (int)streamedEntry[11].__vftable <= 0 )
    goto LABEL_42;
  v18 = (int)streamedEntry[11].__vftable;
  pWaveData = v7->pWaveData;
  do
  {
    v20 = (int *)*pWaveData;
    if ( (*((_BYTE *)*pWaveData + 84) & 2) == 0 )
    {
      v21 = v7->copyStartPos - v20[6];
      if ( v21 >= 0 && v21 < *v20 )
        v17 = 1;
    }
    ++pWaveData;
    --v18;
  }
  while ( v18 != 0 );
  if ( v17 == 0 )
LABEL_42:
    streamedEntry[6].__vftable = (CStatTime_vtbl *)(v7->copyStartPos - (unsigned int)streamedEntry[8].__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x10037550
// Name: public: CWaveDataStreamAsync::CWaveDataStreamAsync(class CAudioSource __near &,class IWaveStreamSource __near *,char const __near *,int,int,class CSfxTable __near *,int,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CWaveDataStreamAsync *__thiscall CWaveDataStreamAsync::CWaveDataStreamAsync(
        CWaveDataStreamAsync *this,
        CAudioSource *source,
        IWaveStreamSource *pStreamSource,
        const char *pFileName,
        int fileStart,
        int fileSize,
        CSfxTable *sfx,
        int startOffset,
        SoundError *soundError)
{
  void **p_m_hFileName; // edi
  void *v11; // eax
  bool v12; // zf
  const char *v13; // eax
  const char *v15; // eax
  char *v16; // eax
  int v17; // eax
  CSfxTable *m_pSfx; // edi
  CAudioSourceCachedInfo *v19; // eax

  this->m_source = source;
  this->m_pStreamSource = pStreamSource;
  this->m_dataStart = fileStart;
  this->m_dataSize = fileSize;
  this->__vftable = (CWaveDataStreamAsync_vtbl *)&CWaveDataStreamAsync::`vftable';
  this->m_pBuffer = nullptr;
  this->m_hCache = 0;
  this->m_hStream = -1;
  this->m_hFileName = nullptr;
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  *((_DWORD *)this + 22) &= ~1u;
  p_m_hFileName = &this->m_hFileName;
  this->m_pSfx = sfx;
  *soundError = SE_OK;
  v11 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: pFileName);
  *p_m_hFileName = v11;
  this->m_sampleIndex = 0;
  this->m_bufferCount = 0;
  this->m_nCachedDataSize = 0;
  if ( this->m_dataSize > 0 )
  {
    if ( v11 == nullptr
      || (v12 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileName, a3: fn, a4: 260), v15 = fn, v12) )
    {
      v15 = defaultValue;
    }
    this->m_hCache = wavedatacache->AsyncLoadCache(
                       this: wavedatacache,
                       a2: v15,
                       a3: this->m_dataSize,
                       a4: this->m_dataStart,
                       a5: false);
    v16 = (char *)MemAlloc_Alloc(nSize: 0x4000u);
    this->m_pBuffer = v16;
    _V_memset(dest: v16, fill: 0, count: 0x4000);
    v17 = source->SampleSize(this: source);
    m_pSfx = this->m_pSfx;
    this->m_sampleSize = v17;
    this->m_bufferSize = 0x4000 / v17;
    this->m_waveSize = fileSize / v17;
    LOBYTE(soundError) = CSfxTable::IsPrecachedSound(this: m_pSfx);
    if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
    {
      v19 = audiosourcecache->GetInfo(this: audiosourcecache, a2: 1, a3: soundError, a4: m_pSfx);
      this->m_AudioCacheHandle.info = v19;
      if ( this != (CWaveDataStreamAsync *)-72 && v19 != nullptr )
        this->m_nCachedDataSize = v19->m_usCachedDataSize;
      this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    _V_memset(dest: this->m_LastSample, fill: 0, count: 8);
    *((_DWORD *)this + 22) |= 1u;
    return this;
  }
  else
  {
    if ( v11 == nullptr
      || (v12 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileName, a3: fn, a4: 260), v13 = fn, v12) )
    {
      v13 = defaultValue;
    }
    _DevMsg(a1: 1, a2: "Can't find streaming wav file: sound\\%s\n", v13);
    *soundError = SE_FILE_NOT_FOUND;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037740
// Name: class IWaveData __near * CreateWaveDataStream(class CAudioSource __near &,class IWaveStreamSource __near *,char const __near *,int,int,class CSfxTable __near *,int,int,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CWaveDataStreamAsync *__cdecl CreateWaveDataStream(
        CAudioSource *source,
        IWaveStreamSource *pStreamSource,
        const char *pFileName,
        int dataStart,
        int dataSize,
        CSfxTable *pSfx,
        int startOffset,
        int skipInitialSamples,
        SoundError *soundError)
{
  CWaveDataStreamAsync *v9; // eax
  CWaveDataStreamAsync *result; // eax

  v9 = (CWaveDataStreamAsync *)MemAlloc_Alloc(nSize: 0x60u);
  if ( v9 != nullptr )
  {
    result = CWaveDataStreamAsync::CWaveDataStreamAsync(
               this: v9,
               source,
               pStreamSource,
               pFileName,
               fileStart: dataStart,
               fileSize: dataSize,
               sfx: pSfx,
               startOffset,
               soundError);
    if ( result != nullptr )
    {
      if ( (*((_BYTE *)result + 88) & 1) != 0 )
        return result;
      ((void (__thiscall *)(CWaveDataStreamAsync *, int))result->dtr_IWaveData)(a1: result, a2: 1);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10037790
// Name: class IWaveData __near * CreateWaveDataMemory(class CAudioSource __near &)
// Source: json
//------------------------------------------------------------------------------
IWaveData *__cdecl CreateWaveDataMemory(CAudioSource *source)
{
  IWaveData *result; // eax

  result = (IWaveData *)MemAlloc_Alloc(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IWaveData_vtbl *)&CWaveDataMemoryAsync::`vftable';
  result[1].__vftable = (IWaveData_vtbl *)source;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100378A0
// Name: public: static class CAsyncWaveData __near * CAsyncWaveData::CreateResource(struct asyncwaveparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAsyncWaveData *__cdecl CAsyncWaveData::CreateResource(const asyncwaveparams_t *params)
{
  unsigned __int8 *v1; // eax
  CAsyncWaveData *v2; // esi

  v1 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x58u);
  v2 = (CAsyncWaveData *)v1;
  if ( v1 == nullptr )
    return nullptr;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  memset(dst: v1 + 16, value: 0, count: 0x2Cu);
  v2->m_async.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
  *((_DWORD *)v2 + 21) &= 0xFFFFFFE0;
  v2->m_hAsyncControl = nullptr;
  v2->m_start = 0.0;
  v2->m_arrival = 0.0;
  v2->m_hFileNameHandle = nullptr;
  v2->m_nBufferBytes = 0;
  v2->m_hBuffer = -1;
  CAsyncWaveData::StartAsyncLoading(this: v2, params);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10037920
// Name: public: bool CAsyncWaveData::BlockingCopyData(void __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CAsyncWaveData::BlockingCopyData(
        CAsyncWaveData *this,
        void *destbuffer,
        int destbufsize,
        int startoffset,
        int count)
{
  bool v6; // zf
  const char *v7; // eax
  int v8; // eax
  char *FileName; // eax
  int m_nReadSize; // eax
  int v12; // ecx
  double v13; // [esp+20h] [ebp-11Ch]
  char wav[48]; // [esp+30h] [ebp-10Ch] BYREF
  __int64 fn_212; // [esp+134h] [ebp-8h] OVERLAPPED

  if ( (*((_BYTE *)this + 84) & 1) == 0 )
  {
    if ( snd_async_spew_blocking.m_pParent != nullptr && snd_async_spew_blocking.m_pParent->m_Value.m_nValue != 0 )
    {
      *((float *)&fn_212 + 1) = _Plat_FloatTime();
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
      *(float *)&fn_212 = _Plat_FloatTime();
      if ( this->m_hFileNameHandle == nullptr
        || (v6 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260), v7 = sz, v6) )
      {
        v7 = defaultValue;
      }
      DevMsg(
        a1: "%f BCD:  Async I/O Force %s (%8.2f msec / %8.2f msec total)\n",
        realtime,
        v7,
        1000.0 * (*(float *)&fn_212 - *((float *)&fn_212 + 1)),
        (this->m_arrival - this->m_start) * 1000.0);
    }
    else
    {
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
    }
  }
  v8 = *((_DWORD *)this + 21);
  if ( (v8 & 2) != 0 )
  {
    *((_DWORD *)this + 21) = v8 & 0xFFFFFFFD;
    if ( g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: wav, a4: 260) )
      MaybeReportMissingWav(wav);
  }
  if ( (*((_BYTE *)this + 84) & 1) == 0 )
    return 0;
  HIDWORD(fn_212) = LODWORD(this->m_arrival);
  if ( *((float *)&fn_212 + 1) != 0.0
    && snd_async_spew_blocking.m_pParent != nullptr
    && snd_async_spew_blocking.m_pParent->m_Value.m_nValue >= 2 )
  {
    v13 = (*((float *)&fn_212 + 1) - this->m_start) * 1000.0;
    FileName = CAsyncWaveData::GetFileName(this);
    DevMsg(a1: "%f Async I/O Read successful %s (%8.2f msec)\n", realtime, FileName, v13);
    this->m_arrival = 0.0;
  }
  m_nReadSize = this->m_nReadSize;
  v12 = count;
  if ( count > m_nReadSize )
    v12 = m_nReadSize - startoffset;
  if ( v12 < 0 )
    return 0;
  _V_memcpy(dest: destbuffer, src: (char *)this->m_pvData + startoffset - this->m_async.nOffset, count: v12);
  g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: this->m_hAsyncControl);
  this->m_hAsyncControl = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10037B00
// Name: public: bool CAsyncWaveData::BlockingGetDataPointer(void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CAsyncWaveData::BlockingGetDataPointer(CAsyncWaveData *this, void **ppData)
{
  bool v3; // zf
  const char *v4; // eax
  int v5; // eax
  char *FileName; // eax
  double v8; // [esp+20h] [ebp-11Ch]
  char wav[48]; // [esp+30h] [ebp-10Ch] BYREF
  __int64 fn_212; // [esp+134h] [ebp-8h] OVERLAPPED

  if ( (*((_BYTE *)this + 84) & 1) == 0 )
  {
    if ( snd_async_spew_blocking.m_pParent != nullptr && snd_async_spew_blocking.m_pParent->m_Value.m_nValue != 0 )
    {
      *((float *)&fn_212 + 1) = _Plat_FloatTime();
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
      *(float *)&fn_212 = _Plat_FloatTime();
      if ( this->m_hFileNameHandle == nullptr
        || (v3 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260), v4 = sz, v3) )
      {
        v4 = defaultValue;
      }
      DevMsg(
        a1: "%f BlockingGetDataPointer:  Async I/O Force %s (%8.2f msec / %8.2f msec total )\n",
        realtime,
        v4,
        1000.0 * (*(float *)&fn_212 - *((float *)&fn_212 + 1)),
        (this->m_arrival - this->m_start) * 1000.0);
    }
    else
    {
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
    }
  }
  v5 = *((_DWORD *)this + 21);
  if ( (v5 & 2) != 0 )
  {
    *((_DWORD *)this + 21) = v5 & 0xFFFFFFFD;
    if ( g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: wav, a4: 260) )
      MaybeReportMissingWav(wav);
  }
  if ( (*((_BYTE *)this + 84) & 1) == 0 )
    return 0;
  HIDWORD(fn_212) = LODWORD(this->m_arrival);
  if ( *((float *)&fn_212 + 1) != 0.0
    && snd_async_spew_blocking.m_pParent != nullptr
    && snd_async_spew_blocking.m_pParent->m_Value.m_nValue >= 2 )
  {
    v8 = (*((float *)&fn_212 + 1) - this->m_start) * 1000.0;
    FileName = CAsyncWaveData::GetFileName(this);
    DevMsg(a1: "%f Async I/O Read successful %s (%8.2f msec)\n", realtime, FileName, v8);
    this->m_arrival = 0.0;
  }
  *ppData = this->m_pvData;
  g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: this->m_hAsyncControl);
  this->m_hAsyncControl = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10037CC0
// Name: public: virtual void CAsyncWavDataCache::UpdateLoopPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::UpdateLoopPosition(CAsyncWavDataCache *this, int hStream, int nLoopPosition)
{
  this->m_StreamedHandles.m_Memory.m_pMemory[hStream].m_Element.m_LoopStart = nLoopPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10037D50
// Name: public: virtual bool CWaveDataStreamAsync::IsReadyToMix(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaveDataStreamAsync::IsReadyToMix(CWaveDataStreamAsync *this)
{
  bool result; // al
  bool v3; // zf
  const char *v4; // eax
  bool bLoaded; // [esp+6h] [ebp-2h]
  bool bCacheValid; // [esp+7h] [ebp-1h] BYREF

  if ( !this->m_source->IsAsyncLoad(this: this->m_source)
    && (snd_async_fullyasync.m_pParent == nullptr || snd_async_fullyasync.m_pParent->m_Value.m_nValue == 0) )
  {
    return true;
  }
  bLoaded = wavedatacache->IsDataLoadCompleted(this: wavedatacache, a2: this->m_hCache, a3: &bCacheValid, a4: nullptr);
  if ( !bCacheValid )
  {
    if ( this->m_hFileName == nullptr
      || (v3 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileName, a3: fn, a4: 260), v4 = fn, v3) )
    {
      v4 = defaultValue;
    }
    wavedatacache->RestartDataLoad(
      this: wavedatacache,
      a2: &this->m_hCache,
      a3: v4,
      a4: this->m_dataSize,
      a5: this->m_dataStart);
  }
  v3 = !g_pEngineToolInternal->IsRecordingMovie(this: g_pEngineToolInternal);
  result = true;
  if ( v3 )
    return bLoaded;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037E10
// Name: public: virtual int CWaveDataStreamAsync::ReadSourceData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveDataStreamAsync::ReadSourceData(
        CWaveDataStreamAsync *this,
        void **pData,
        __int64 sampleIndex,
        int sampleCount,
        char *copyBuf)
{
  __int64 v6; // rax
  unsigned int v7; // ebx
  unsigned int v8; // edi
  const char *FileName; // eax
  unsigned int m_sampleIndex_high; // eax
  unsigned int m_sampleIndex; // ecx
  unsigned int v12; // ebx
  unsigned int v13; // edi
  unsigned int v14; // kr00_4
  __int64 m_bufferCount; // rax
  __int64 v16; // rax
  int v17; // eax
  int v18; // ecx
  int m_dataStart; // edx
  int v20; // eax
  int v21; // edi
  int m_bufferSize; // ecx
  int v23; // ecx
  CAudioSourceCachedInfo *info; // eax
  bool IsPrecachedSound; // al
  int m_nCachedDataSize; // edx
  int m_sampleSize; // edi
  int v28; // eax
  int v29; // eax
  const char *v30; // eax
  int v31; // esi
  int m_dataSize; // [esp-1Ch] [ebp-30h]
  int v34; // [esp-18h] [ebp-2Ch]
  char *m_pBuffer; // [esp-14h] [ebp-28h]
  int v36; // [esp-10h] [ebp-24h]
  CSfxTable *m_pSfx; // [esp-8h] [ebp-1Ch]
  int v38; // [esp-8h] [ebp-1Ch]
  const unsigned __int8 *cacheddata; // [esp+Ch] [ebp-8h]
  const unsigned __int8 *cacheddataa; // [esp+Ch] [ebp-8h]
  IAsyncWavDataCache_vtbl *cacheddatab; // [esp+Ch] [ebp-8h]
  bool postprocessed; // [esp+13h] [ebp-1h] BYREF
  unsigned int sampleIndexa; // [esp+20h] [ebp+Ch]

  if ( this->m_source->IsLooped(this: this->m_source) )
  {
    v6 = ((__int64 (__thiscall *)(IWaveStreamSource *, _DWORD, _DWORD))this->m_pStreamSource->UpdateLoopingSamplePosition)(
           a1: this->m_pStreamSource,
           a2: sampleIndex,
           a3: HIDWORD(sampleIndex));
    v7 = HIDWORD(v6);
    v8 = v6;
    if ( v6 < this->m_sampleIndex )
    {
      if ( snd_report_loop_sound.m_pParent != nullptr && snd_report_loop_sound.m_pParent->m_Value.m_nValue != 0 )
      {
        FileName = CWaveDataStreamAsync::GetFileName(this);
        _Warning(a1: "[Sound] Sound \"%s\" just looped.\n", FileName);
      }
      LODWORD(this->m_sampleIndex) = v8;
      HIDWORD(this->m_sampleIndex) = v7;
      this->m_bufferCount = 0;
    }
  }
  else
  {
    v7 = HIDWORD(sampleIndex);
    v8 = sampleIndex;
  }
  m_sampleIndex_high = HIDWORD(this->m_sampleIndex);
  m_sampleIndex = this->m_sampleIndex;
  if ( __SPAIR64__(v7, v8) < __SPAIR64__(m_sampleIndex_high, m_sampleIndex) )
  {
    v7 = HIDWORD(this->m_sampleIndex);
    v8 = this->m_sampleIndex;
  }
  v14 = v8 - m_sampleIndex;
  v12 = (__PAIR64__(v7, v8) - __PAIR64__(m_sampleIndex_high, m_sampleIndex)) >> 32;
  v13 = v14;
  m_bufferCount = this->m_bufferCount;
  if ( __SPAIR64__(v12, v14) >= m_bufferCount )
  {
    v16 = this->m_sampleIndex + m_bufferCount;
    LODWORD(this->m_sampleIndex) = v16;
    v17 = this->m_bufferCount;
    HIDWORD(this->m_sampleIndex) = HIDWORD(v16);
    v12 = (__PAIR64__(v12, v14) - v17) >> 32;
    sampleIndexa = v14 - v17;
    if ( (unsigned int)(__SPAIR64__(v12, v14 - v17) / this->m_bufferSize) != 0 )
    {
      this->m_sampleIndex += __PAIR64__(v12, v14 - v17);
      v12 = 0;
      sampleIndexa = 0;
    }
    v18 = this->m_sampleIndex;
    m_dataStart = this->m_dataStart;
    v20 = this->m_waveSize - v18;
    v21 = m_dataStart + v18 * this->m_sampleSize;
    this->m_bufferCount = v20;
    if ( v20 <= 0 )
      return 0;
    m_bufferSize = this->m_bufferSize;
    if ( v20 > m_bufferSize )
      this->m_bufferCount = m_bufferSize;
    v23 = v21 - m_dataStart;
    cacheddata = (const unsigned __int8 *)(v21 - m_dataStart);
    if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount
      || (info = this->m_AudioCacheHandle.info) == nullptr )
    {
      m_pSfx = this->m_pSfx;
      IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx);
      info = CAudioSourceCachedInfoHandle_t::Get(
               this: &this->m_AudioCacheHandle,
               audiosourcetype: 1,
               soundisprecached: IsPrecachedSound,
               sfx: m_pSfx,
               pcacheddatasize: &this->m_nCachedDataSize);
      if ( info == nullptr )
        goto LABEL_26;
      v23 = (int)cacheddata;
    }
    m_nCachedDataSize = this->m_nCachedDataSize;
    if ( m_nCachedDataSize > 0 && v23 < m_nCachedDataSize )
    {
      cacheddataa = info->m_pCachedData;
      if ( cacheddataa != nullptr )
      {
        m_sampleSize = this->m_sampleSize;
        v28 = (m_nCachedDataSize - v23) / m_sampleSize;
        if ( v28 > this->m_bufferSize )
          v28 = this->m_bufferSize;
        this->m_bufferCount = v28;
        _V_memcpy(dest: this->m_pBuffer, src: &cacheddataa[v23], count: v28 * m_sampleSize);
LABEL_29:
        v13 = sampleIndexa;
        goto LABEL_30;
      }
    }
LABEL_26:
    v29 = this->m_sampleSize;
    postprocessed = false;
    cacheddatab = wavedatacache->__vftable;
    v38 = v29 * this->m_bufferCount;
    v36 = v29 * this->m_bufferSize;
    m_pBuffer = this->m_pBuffer;
    v34 = this->m_dataStart;
    m_dataSize = this->m_dataSize;
    v30 = CWaveDataStreamAsync::GetFileName(this);
    if ( !cacheddatab->CopyDataIntoMemory(
            this: wavedatacache,
            a2: &this->m_hCache,
            a3: v30,
            a4: m_dataSize,
            a5: v34,
            a6: m_pBuffer,
            a7: v36,
            a8: v21,
            a9: v38,
            a10: &postprocessed) )
      return 0;
    if ( !postprocessed )
      this->m_pStreamSource->UpdateSamples(this: this->m_pStreamSource, a2: this->m_pBuffer, a3: this->m_bufferCount);
    goto LABEL_29;
  }
LABEL_30:
  if ( __SPAIR64__(v12, v13) >= this->m_bufferCount )
    return 0;
  *pData = &this->m_pBuffer[v13 * this->m_sampleSize];
  v31 = this->m_bufferCount - v13;
  if ( v31 > sampleCount )
    return sampleCount;
  return v31;
}

//------------------------------------------------------------------------------
// Address: 0x10038040
// Name: public: virtual bool CWaveDataMemoryAsync::IsReadyToMix(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaveDataMemoryAsync::IsReadyToMix(CWaveDataMemoryAsync *this)
{
  if ( this->m_source->IsAsyncLoad(this: this->m_source)
    || snd_async_fullyasync.m_pParent != nullptr && snd_async_fullyasync.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_source->GetCacheStatus(this: this->m_source) == 1 )
      return true;
    this->m_source->CacheLoad(this: this->m_source);
    return false;
  }
  else
  {
    if ( this->m_source->GetCacheStatus(this: this->m_source) != 0
      && this->m_source->GetCacheStatus(this: this->m_source) != 3 )
    {
      return true;
    }
    return g_pEngineToolInternal->IsRecordingMovie(this: g_pEngineToolInternal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AC20
// Name: public: class CAsyncWaveData __near * CWaveCache::CacheGet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAsyncWaveData *__thiscall CWaveCache::CacheGet(CWaveCache *this, unsigned int hData)
{
  CAsyncWaveData *result; // eax
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // eax
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  WaveCache_t *m_pData; // eax
  bool v9; // zf

  if ( hData == 0 )
    return nullptr;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_WaveCacheMutex.m_depth;
  }
  if ( hData != -1
    && (v6 = hData & 0x7FF) < this->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (m_pData = v7->m_pData) != nullptr )
  {
    m_pData->m_nAgeStamp = this->m_nAgeStamp++;
    result = m_pData->m_pWaveData;
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
  else
  {
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003ACE0
// Name: public: class CAsyncWaveData __near * CWaveCache::CacheGetNoTouch(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAsyncWaveData *__thiscall CWaveCache::CacheGetNoTouch(CWaveCache *this, unsigned int hData)
{
  CWaveCache *v2; // ebx
  CAsyncWaveData *result; // eax
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  CAsyncWaveData **p_m_pWaveData; // ecx
  bool v9; // zf

  v2 = this;
  if ( hData == 0 )
    return nullptr;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
      v2 = this;
      goto LABEL_8;
    }
    v2 = this;
  }
  ++p_m_WaveCacheMutex->m_depth;
LABEL_8:
  if ( hData != -1
    && (v6 = hData & 0x7FF) < v2->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &v2->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (p_m_pWaveData = &v7->m_pData->m_pWaveData) != nullptr )
  {
    result = *p_m_pWaveData;
    v9 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
  else
  {
    v9 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003ADA0
// Name: public: void CWaveCache::Age(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveCache::Age(CWaveCache *this, unsigned int hData)
{
  CWaveCache *v2; // ebx
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v5; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v6; // ecx
  WaveCache_t *m_pData; // ecx
  bool v8; // zf

  v2 = this;
  if ( hData == 0 )
    return;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == p_m_WaveCacheMutex->m_ownerID )
    goto LABEL_5;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) == 0 )
  {
    v2 = this;
LABEL_5:
    ++p_m_WaveCacheMutex->m_depth;
    goto LABEL_7;
  }
  _mm_pause();
  CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  v2 = this;
LABEL_7:
  if ( hData != -1
    && (v5 = hData & 0x7FF) < v2->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v6 = &v2->m_HandleTable.m_list.m_Memory.m_pMemory[v5]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v6 & 0x80000000) != 0x80000000
    && (m_pData = v6->m_pData) != nullptr )
  {
    m_pData->m_nAgeStamp = 0;
    v8 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( !v8 )
      return;
  }
  else
  {
    v8 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( !v8 )
      return;
  }
  _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003AE60
// Name: public: int CWaveCache::GetLockCount(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWaveCache::GetLockCount(CWaveCache *this, unsigned int hData)
{
  CWaveCache *v2; // ebx
  unsigned int result; // eax
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  WaveCache_t *m_pData; // ecx
  bool v9; // zf

  v2 = this;
  if ( hData == 0 )
    return 0;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
      v2 = this;
      goto LABEL_8;
    }
    v2 = this;
  }
  ++p_m_WaveCacheMutex->m_depth;
LABEL_8:
  if ( hData != -1
    && (v6 = hData & 0x7FF) < v2->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &v2->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (m_pData = v7->m_pData) != nullptr )
  {
    result = m_pData->m_nLockCount;
    v9 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
  else
  {
    v9 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003AF20
// Name: public: virtual bool CAsyncWavDataCache::CopyDataIntoMemory(char const __near *,int,int,void __near *,int,int,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::CopyDataIntoMemory(
        CAsyncWavDataCache *this,
        const char *filename,
        int datasize,
        int startpos,
        void *buffer,
        int bufsize,
        int copystartpos,
        int bytestocopy,
        bool *pbPostProcessed)
{
  int v10; // eax
  CAsyncWavDataCache::CacheEntry_t search; // [esp+Ch] [ebp-8h] BYREF

  this->AsyncLoadCache(this, a2: filename, a3: datasize, a4: startpos, a5: false);
  search.name = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: filename);
  search.handle = 0;
  v10 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Find(
          this: &this->m_CacheHandles,
          &search);
  return v10 != -1
      && this->CopyDataIntoMemory(
           this,
           a2: &this->m_CacheHandles.m_Elements.m_pMemory[v10].m_Data.handle,
           a3: filename,
           a4: datasize,
           a5: startpos,
           a6: buffer,
           a7: bufsize,
           a8: copystartpos,
           a9: bytestocopy,
           a10: pbPostProcessed);
}

//------------------------------------------------------------------------------
// Address: 0x1003AFB0
// Name: private: bool CAsyncWavDataCache::InitializeStreamData(struct CAsyncWavDataCache::StreamedEntry_t const __near &,struct CAsyncWavDataCache::StreamData_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncWavDataCache::InitializeStreamData(
        CAsyncWavDataCache *this,
        const CAsyncWavDataCache::StreamedEntry_t *streamedEntry,
        CAsyncWavDataCache::StreamData_t *streamData,
        int copyStartPos)
{
  const CAsyncWavDataCache::StreamedEntry_t *v4; // ecx
  CAsyncWavDataCache::StreamData_t *v5; // eax
  int v6; // ecx
  CAsyncWaveData **pWaveData; // edi
  unsigned int v8; // esi
  CAsyncWaveData *m_pWaveData; // eax
  DWORD CurrentThreadId; // ecx
  int v11; // eax
  WaveCache_t *m_pData; // eax
  int i; // [esp+14h] [ebp-4h]

  v4 = streamedEntry;
  v5 = streamData;
  i = 0;
  if ( streamedEntry->m_numBuffers <= 0 )
  {
LABEL_23:
    v5->index = v4->m_Front;
    v5->actualCopied = 0;
    v5->bWaiting = false;
    v5->copyStartPos = copyStartPos;
    return 1;
  }
  else
  {
    v6 = (char *)streamedEntry - (char *)streamData;
    pWaveData = streamData->pWaveData;
    while ( 1 )
    {
      v8 = *(unsigned int *)((char *)pWaveData + v6);
      if ( v8 != 0 )
      {
        CurrentThreadId = GetCurrentThreadId();
        if ( CurrentThreadId != s_WaveCache.m_WaveCacheMutex.m_ownerID
          && _InterlockedCompareExchange((volatile signed __int32 *)&s_WaveCache.m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
        {
          _mm_pause();
          CThreadFastMutex::Lock(a1: &s_WaveCache.m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
        }
        else
        {
          ++s_WaveCache.m_WaveCacheMutex.m_depth;
        }
        if ( v8 != -1
          && (unsigned int)(v11 = v8 & 0x7FF) < s_WaveCache.m_HandleTable.m_list.m_Size
          && (*(_DWORD *)&s_WaveCache.m_HandleTable.m_list.m_Memory.m_pMemory[v11] & 0x7FFFFFFF) == v8 >> 11
          && (*(_DWORD *)&s_WaveCache.m_HandleTable.m_list.m_Memory.m_pMemory[v11] & 0x80000000) != 0x80000000
          && (m_pData = s_WaveCache.m_HandleTable.m_list.m_Memory.m_pMemory[v11].m_pData) != nullptr )
        {
          m_pWaveData = m_pData->m_pWaveData;
          if ( --s_WaveCache.m_WaveCacheMutex.m_depth == 0 )
            _InterlockedExchange((volatile __int32 *)&s_WaveCache.m_WaveCacheMutex, 0);
        }
        else
        {
          if ( --s_WaveCache.m_WaveCacheMutex.m_depth == 0 )
            _InterlockedExchange((volatile __int32 *)&s_WaveCache.m_WaveCacheMutex, 0);
          m_pWaveData = nullptr;
        }
      }
      else
      {
        m_pWaveData = nullptr;
      }
      *pWaveData = m_pWaveData;
      if ( m_pWaveData == nullptr )
        return 0;
      v4 = streamedEntry;
      ++pWaveData;
      if ( ++i >= streamedEntry->m_numBuffers )
      {
        v5 = streamData;
        goto LABEL_23;
      }
      v6 = (char *)streamedEntry - (char *)streamData;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B0F0
// Name: public: virtual void __near * CAsyncWavDataCache::GetStreamedDataPointer(int,bool)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CAsyncWavDataCache::GetStreamedDataPointer(CAsyncWavDataCache *this, int hStream, bool bSync)
{
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v3; // esi
  int v4; // edx
  CAsyncWaveData *NoTouch; // eax
  int v6; // ecx
  void *pData; // [esp+4h] [ebp-4h] BYREF

  v3 = &this->m_StreamedHandles.m_Memory.m_pMemory[hStream];
  v4 = v3->m_Element.m_Front % v3->m_Element.m_numBuffers;
  pData = nullptr;
  NoTouch = CWaveCache::CacheGetNoTouch(this: &s_WaveCache, hData: v3->m_Element.m_hWaveData[v4]);
  if ( NoTouch == nullptr )
    return nullptr;
  v6 = *((_DWORD *)NoTouch + 21);
  if ( (v6 & 2) == 0 && (v6 & 1) != 0 )
    return NoTouch->m_pvData;
  if ( bSync && CAsyncWaveData::BlockingGetDataPointer(this: NoTouch, ppData: &pData) )
    return pData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003B160
// Name: public: virtual bool CAsyncWavDataCache::IsStreamedDataReady(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::IsStreamedDataReady(CAsyncWavDataCache *this, int hStream)
{
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v3; // eax
  CAsyncWaveData *NoTouch; // eax

  if ( hStream == -1 )
    return false;
  v3 = &this->m_StreamedHandles.m_Memory.m_pMemory[hStream];
  return v3->m_Element.m_Front != 0
      || (NoTouch = CWaveCache::CacheGetNoTouch(this: &s_WaveCache, hData: v3->m_Element.m_hWaveData[0])) == nullptr
      || (*((_BYTE *)NoTouch + 84) & 3) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003B1B0
// Name: public: virtual void CAsyncWavDataCache::SetPostProcessed(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::SetPostProcessed(CAsyncWavDataCache *this, unsigned int handle, bool proc)
{
  CAsyncWaveData *v3; // eax

  v3 = CWaveCache::CacheGet(this: &s_WaveCache, hData: handle);
  if ( v3 != nullptr )
    *((_DWORD *)v3 + 21) ^= (*((_DWORD *)v3 + 21) ^ (4 * proc)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x1003B1E0
// Name: public: virtual void CAsyncWavDataCache::Unload(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::Unload(CAsyncWavDataCache *this, unsigned int handle)
{
  CWaveCache::Age(this: &s_WaveCache, hData: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1003B1F0
// Name: public: virtual bool CAsyncWavDataCache::IsDataLoadCompleted(unsigned int,bool __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::IsDataLoadCompleted(
        CAsyncWavDataCache *this,
        unsigned int handle,
        bool *pIsValid,
        bool *pIsMissing)
{
  CAsyncWaveData *v4; // esi
  int v5; // eax

  v4 = CWaveCache::CacheGet(this: &s_WaveCache, hData: handle);
  if ( v4 != nullptr )
  {
    *pIsValid = true;
    if ( pIsMissing != nullptr )
      *pIsMissing = (*((_DWORD *)v4 + 21) & 2) != 0;
    CAsyncWaveData::SetAsyncPriority(this: v4, priority: 1);
    return *((_DWORD *)v4 + 21) & 1;
  }
  else
  {
    *pIsValid = false;
    LOBYTE(v5) = 0;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1003B240
// Name: public: virtual void CAsyncWavDataCache::RestartDataLoad(unsigned int __near *,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::RestartDataLoad(
        CAsyncWavDataCache *this,
        unsigned int *pHandle,
        const char *pFilename,
        int dataSize,
        int startpos)
{
  if ( CWaveCache::CacheGet(this: &s_WaveCache, hData: *pHandle) == nullptr )
    *pHandle = this->AsyncLoadCache(this, a2: pFilename, a3: dataSize, a4: startpos, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x1003B280
// Name: public: virtual bool CAsyncWavDataCache::IsDataLoadInProgress(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::IsDataLoadInProgress(CAsyncWavDataCache *this, unsigned int handle)
{
  CAsyncWaveData *v2; // eax
  int v3; // ecx
  FSAsyncStatus_t v4; // eax
  bool result; // al

  v2 = CWaveCache::CacheGet(this: &s_WaveCache, hData: handle);
  result = false;
  if ( v2 != nullptr )
  {
    v3 = *((_DWORD *)v2 + 21);
    if ( (v3 & 1) != 0 )
      return true;
    if ( (v3 & 2) == 0 )
    {
      v4 = g_pFileSystem->AsyncStatus(this: g_pFileSystem, a2: v2->m_hAsyncControl);
      if ( v4 == FSASYNC_STATUS_INPROGRESS || v4 == FSASYNC_OK )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B2D0
// Name: public: void CAsyncWavDataCache::SpewMemoryUsage(enum CAsyncWavDataCache::MemoryUsageType)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CAsyncWavDataCache::SpewMemoryUsage(
        CAsyncWavDataCache *this,
        CAsyncWavDataCache::MemoryUsageType level)
{
  CAsyncWavDataCache *v2; // ebx
  __int64 v3; // kr00_8
  CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl*)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int> > *p_m_CacheHandles; // esi
  int Inorder; // eax
  int v6; // edi
  CAsyncWaveData *NoTouch; // eax
  const char *v8; // eax
  float v9; // xmm0_4
  int m_NumElements; // ebx
  const char *v11; // eax
  float v12; // [esp+0h] [ebp-130h]
  char pStr[8]; // [esp+1Ch] [ebp-114h] BYREF
  __int128 name_224; // [esp+120h] [ebp-10h] OVERLAPPED

  v2 = this;
  DWORD1(name_224) = s_WaveCache.m_nCurrentMemorySize;
  *((_QWORD *)&name_224 + 1) = __PAIR64__((unsigned int)this, s_WaveCache.m_nMaxMemorySize);
  v3 = *(_QWORD *)&s_WaveCache.m_nCurrentMemorySize;
  if ( level != SPEW_BASIC )
  {
    p_m_CacheHandles = &this->m_CacheHandles;
    Inorder = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::FirstInorder(this: &this->m_CacheHandles);
    while ( 1 )
    {
      v6 = Inorder;
      if ( Inorder < 0
        || Inorder >= p_m_CacheHandles->m_Elements.m_nAllocationCount
        || Inorder > p_m_CacheHandles->m_LastAlloc.index
        || CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::LeftChild(
             this: p_m_CacheHandles,
             i: Inorder) == Inorder )
      {
        break;
      }
      if ( g_pFileSystem->String(
             this: g_pFileSystem,
             a2: (void *const *)&v2->m_CacheHandles.m_Elements.m_pMemory[v6].m_Data,
             a3: pStr,
             a4: 260)
        && (level != SPEW_MUSIC_NONSTREAMING || V_stristr(pStr, pSearch: "music") != nullptr) )
      {
        v2 = (CAsyncWavDataCache *)HIDWORD(name_224);
        NoTouch = CWaveCache::CacheGetNoTouch(
                    this: &s_WaveCache,
                    hData: *(_DWORD *)(*(_DWORD *)(HIDWORD(name_224) + 84) + 24 * v6 + 20));
        if ( NoTouch != nullptr )
        {
          LODWORD(name_224) = NoTouch->m_nDataSize + 88;
          v12 = (float)(unsigned int)name_224;
          v8 = V_pretifymem(value: v12, digitsafterdecimal: 2, usebinaryonek: false);
          _Msg(a1: "\t%16.16s : %s\n", v8, pStr);
        }
        else
        {
          _Msg(a1: "\t%16.16s : %s\n", "not resident", pStr);
        }
        p_m_CacheHandles = &v2->m_CacheHandles;
        Inorder = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::NextInorder(
                    this: &v2->m_CacheHandles,
                    i: v6);
      }
      else
      {
        v2 = (CAsyncWavDataCache *)HIDWORD(name_224);
        p_m_CacheHandles = (CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl*)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int> > *)(HIDWORD(name_224) + 80);
        Inorder = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::NextInorder(
                    this: (CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl*)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int> > *)(HIDWORD(name_224) + 80),
                    i: v6);
      }
    }
    v3 = *(_QWORD *)((char *)&name_224 + 4);
  }
  if ( SHIDWORD(v3) > 0 )
    v9 = (float)((float)(int)v3 * 100.0) / (float)SHIDWORD(v3);
  else
    v9 = 0.0;
  m_NumElements = v2->m_CacheHandles.m_NumElements;
  v11 = V_pretifymem(value: (float)(int)v3, digitsafterdecimal: 2, usebinaryonek: false);
  _Msg(a1: "CAsyncWavDataCache:  %i .wavs total %s, %.2f %% of capacity\n", m_NumElements, v11, v9);
}

//------------------------------------------------------------------------------
// Address: 0x1003B4A0
// Name: snd_async_showmem
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_async_showmem()
{
  CAsyncWavDataCache::SpewMemoryUsage(this: &g_AsyncWaveDataCache, level: SPEW_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x1003B4B0
// Name: snd_async_showmem_summary
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_async_showmem_summary()
{
  CAsyncWavDataCache::SpewMemoryUsage(this: &g_AsyncWaveDataCache, level: SPEW_BASIC);
}

//------------------------------------------------------------------------------
// Address: 0x1003B4C0
// Name: snd_async_showmem_music
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_async_showmem_music()
{
  CAsyncWavDataCache::SpewMemoryUsage(this: &g_AsyncWaveDataCache, level: SPEW_MUSIC_NONSTREAMING);
}

//------------------------------------------------------------------------------
// Address: 0x1003B940
// Name: public: CAsyncWavDataCache::CAsyncWavDataCache(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncWavDataCache *__thiscall CAsyncWavDataCache::CAsyncWavDataCache(CAsyncWavDataCache *this)
{
  this->__vftable = (CAsyncWavDataCache_vtbl *)&CAsyncWavDataCache::`vftable';
  this->m_BufferList.m_LessFunc = (bool (__cdecl *)(const CAsyncWavDataCache::BufferEntry_t *, const CAsyncWavDataCache::BufferEntry_t *))CAsyncWavDataCache::BufferHandleLessFunc;
  this->m_BufferList.m_Elements.m_pMemory = nullptr;
  this->m_BufferList.m_Elements.m_nAllocationCount = 0;
  this->m_BufferList.m_Elements.m_nGrowSize = 0;
  this->m_BufferList.m_NumElements = 0;
  this->m_BufferList.m_Root = -1;
  this->m_BufferList.m_FirstFree = -1;
  this->m_BufferList.m_LastAlloc.index = -1;
  this->m_BufferList.m_pElements = this->m_BufferList.m_Elements.m_pMemory;
  this->m_StreamedHandles.m_Memory.m_pMemory = nullptr;
  this->m_StreamedHandles.m_Memory.m_nAllocationCount = 0;
  this->m_StreamedHandles.m_Memory.m_nGrowSize = 0;
  this->m_StreamedHandles.m_LastAlloc.index = -1;
  this->m_StreamedHandles.m_pElements = this->m_StreamedHandles.m_Memory.m_pMemory;
  this->m_StreamedHandles.m_Head = -1;
  this->m_StreamedHandles.m_Tail = -1;
  this->m_StreamedHandles.m_FirstFree = -1;
  this->m_StreamedHandles.m_ElementCount = 0;
  this->m_StreamedHandles.m_NumAlloced = 0;
  this->m_CacheHandles.m_LessFunc = (bool (__cdecl *)(const CAsyncWavDataCache::CacheEntry_t *, const CAsyncWavDataCache::CacheEntry_t *))CDmxSerializationDictionary::LessFunc;
  this->m_CacheHandles.m_Elements.m_pMemory = nullptr;
  this->m_CacheHandles.m_Elements.m_nAllocationCount = 0;
  this->m_CacheHandles.m_Elements.m_nGrowSize = 0;
  this->m_CacheHandles.m_Root = -1;
  this->m_CacheHandles.m_FirstFree = -1;
  this->m_CacheHandles.m_NumElements = 0;
  this->m_CacheHandles.m_LastAlloc.index = -1;
  this->m_CacheHandles.m_pElements = this->m_CacheHandles.m_Elements.m_pMemory;
  this->m_DeadBuffers.m_Memory.m_pMemory = nullptr;
  this->m_DeadBuffers.m_Memory.m_nAllocationCount = 0;
  this->m_DeadBuffers.m_Memory.m_nGrowSize = 0;
  this->m_DeadBuffers.m_Size = 0;
  this->m_DeadBuffers.m_pElements = nullptr;
  this->m_bInitialized = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003B9D0
// Name: public: unsigned int CUtlHandleTable<struct WaveCache_t,11>::AddHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHandleTable<WaveCache_t,11>::AddHandle(CUtlHandleTable<WaveCache_t,11> *this)
{
  int *m_pMemory; // ecx
  int m_current; // ecx
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v4; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v5; // eax

  if ( this->m_unused.m_heap.m_Size <= 0 )
  {
    m_current = CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
                  this: (CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *)&this->m_list,
                  elem: this->m_list.m_Size);
  }
  else
  {
    m_pMemory = this->m_unused.m_heap.m_Memory.m_pMemory;
    this->m_unused.m_current = *m_pMemory;
    if ( this->m_unused.m_heap.m_Size - 1 > 0 )
      _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: 4 * (this->m_unused.m_heap.m_Size - 1));
    --this->m_unused.m_heap.m_Size;
    m_current = this->m_unused.m_current;
  }
  v4 = this->m_list.m_Memory.m_pMemory;
  *(_DWORD *)&v4[m_current] &= ~0x80000000;
  v5 = &v4[m_current];
  v5->m_pData = nullptr;
  ++this->m_nValidHandles;
  return m_current & 0x7FF | (*(_DWORD *)v5 << 11);
}

//------------------------------------------------------------------------------
// Address: 0x1003BAC0
// Name: public: CWaveCache::CWaveCache(void)
// Source: json
//------------------------------------------------------------------------------
CWaveCache *__thiscall CWaveCache::CWaveCache(CWaveCache *this)
{
  CUtlHandleTable<WaveCache_t,11> *p_m_HandleTable; // ecx

  this->m_WaveCacheMutex.m_ownerID = 0;
  this->m_WaveCacheMutex.m_depth = 0;
  this->m_HandleTable.m_nValidHandles = 0;
  this->m_HandleTable.m_list.m_Memory.m_pMemory = nullptr;
  this->m_HandleTable.m_list.m_Memory.m_nAllocationCount = 0;
  this->m_HandleTable.m_list.m_Memory.m_nGrowSize = 0;
  this->m_HandleTable.m_list.m_Size = 0;
  this->m_HandleTable.m_list.m_pElements = nullptr;
  p_m_HandleTable = &this->m_HandleTable;
  p_m_HandleTable->m_unused.m_heap.m_Memory.m_pMemory = nullptr;
  p_m_HandleTable->m_unused.m_heap.m_Memory.m_nAllocationCount = 0;
  p_m_HandleTable->m_unused.m_heap.m_Memory.m_nGrowSize = 0;
  p_m_HandleTable->m_unused.m_heap.m_Size = 0;
  p_m_HandleTable->m_unused.m_heap.m_pElements = nullptr;
  this->m_UnlockedList.m_Memory.m_pMemory = nullptr;
  this->m_UnlockedList.m_Memory.m_nAllocationCount = 0;
  this->m_UnlockedList.m_Memory.m_nGrowSize = 0;
  this->m_UnlockedList.m_LastAlloc.index = -1;
  this->m_UnlockedList.m_Head = -1;
  this->m_UnlockedList.m_Tail = -1;
  this->m_UnlockedList.m_FirstFree = -1;
  this->m_UnlockedList.m_ElementCount = 0;
  this->m_UnlockedList.m_NumAlloced = 0;
  this->m_UnlockedList.m_pElements = this->m_UnlockedList.m_Memory.m_pMemory;
  this->m_nCurrentMemorySize = 0;
  this->m_nMaxMemorySize = -1;
  this->m_nAgeStamp = 1;
  CUtlHandleTable<WaveCache_t,11>::AddHandle(this: p_m_HandleTable);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB40
// Name: public: class CAsyncWaveData __near * CWaveCache::CacheLock(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAsyncWaveData *__thiscall CWaveCache::CacheLock(CWaveCache *this, unsigned int hData)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // ebx
  DWORD CurrentThreadId; // eax
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  WaveCache_t *m_pData; // esi
  bool v9; // zf
  CAsyncWaveData *m_pWaveData; // esi
  unsigned __int16 hDataa; // [esp+10h] [ebp+8h]

  if ( hData == 0 )
    return nullptr;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_WaveCacheMutex.m_depth;
  }
  if ( hData != -1
    && (v6 = hData & 0x7FF) < this->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (m_pData = v7->m_pData) != nullptr )
  {
    m_pData->m_nAgeStamp = this->m_nAgeStamp++;
    if ( ++m_pData->m_nLockCount == 1 && m_pData->m_hUnlock != 0xFFFF )
    {
      hDataa = m_pData->m_hUnlock;
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_UnlockedList,
        elem: hDataa);
      this->m_UnlockedList.m_Memory.m_pMemory[hDataa].m_Next = this->m_UnlockedList.m_FirstFree;
      this->m_UnlockedList.m_FirstFree = hDataa;
      m_pData->m_hUnlock = 0xFFFF;
    }
    m_pWaveData = m_pData->m_pWaveData;
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return m_pWaveData;
  }
  else
  {
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BC40
// Name: public: virtual void CAsyncWavDataCache::MarkBufferDiscarded(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::MarkBufferDiscarded(CAsyncWavDataCache *this, int hBuffer)
{
  CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl*)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int> > *p_m_BufferList; // esi
  int v3; // eax

  p_m_BufferList = &this->m_BufferList;
  if ( hBuffer != -1 )
  {
    CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int>>::Unlink(
      this: &this->m_BufferList,
      elem: hBuffer);
    v3 = hBuffer;
    p_m_BufferList->m_Elements.m_pMemory[v3].m_Left = hBuffer;
    p_m_BufferList->m_Elements.m_pMemory[v3].m_Right = p_m_BufferList->m_FirstFree;
    --p_m_BufferList->m_NumElements;
    p_m_BufferList->m_FirstFree = hBuffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BD30
// Name: public: void CUtlQueue<int,class CUtlMemory<int,int>>::Insert(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlQueue<int,CUtlMemory<int,int>>::Insert(
        CUtlQueue<int,CUtlMemory<int,int> > *this,
        const int *element)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  m_Size = this->m_heap.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_heap.m_Size;
  m_pMemory = this->m_heap.m_Memory.m_pMemory;
  v6 = this->m_heap.m_Size - m_Size - 1;
  this->m_heap.m_pElements = this->m_heap.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  this->m_heap.m_Memory.m_pMemory[m_Size] = *element;
}

//------------------------------------------------------------------------------
// Address: 0x1003BD90
// Name: public: int CWaveCache::CacheUnlock(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWaveCache::CacheUnlock(CWaveCache *this, unsigned int hData)
{
  unsigned int result; // eax
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v6; // ecx
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // edx
  WaveCache_t *m_pData; // edi
  bool v9; // zf
  unsigned int m_nLockCount; // eax
  unsigned int v11; // eax

  if ( hData == 0 )
    return 0;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_WaveCacheMutex.m_depth;
  }
  if ( hData != -1
    && (v6 = hData & 0x7FF) < this->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (m_pData = v7->m_pData) != nullptr )
  {
    m_nLockCount = m_pData->m_nLockCount;
    if ( m_nLockCount != 0 )
    {
      v11 = m_nLockCount - 1;
      m_pData->m_nLockCount = v11;
      if ( v11 == 0 )
        m_pData->m_hUnlock = CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AddToTail(
                               this: &this->m_UnlockedList,
                               src: &hData);
    }
    result = m_pData->m_nLockCount;
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
  else
  {
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003BE70
// Name: public: void CWaveCache::BreakLock(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveCache::BreakLock(CWaveCache *this, unsigned int hData)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v5; // ecx
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v6; // edx
  WaveCache_t *m_pData; // edi
  bool v8; // zf

  if ( hData != 0 )
  {
    p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_WaveCacheMutex.m_depth;
    }
    if ( hData == -1
      || (v5 = hData & 0x7FF) >= this->m_HandleTable.m_list.m_Size
      || (*(_DWORD *)(v6 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v5]) & 0x7FFFFFFF) != hData >> 11
      || (*(_DWORD *)v6 & 0x80000000) == 0x80000000
      || (m_pData = v6->m_pData) == nullptr )
    {
      v8 = this->m_WaveCacheMutex.m_depth-- == 1;
      if ( !v8 )
        return;
      goto LABEL_16;
    }
    if ( m_pData->m_nLockCount != 0 )
    {
      m_pData->m_nLockCount = 0;
      m_pData->m_hUnlock = CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AddToTail(
                             this: &this->m_UnlockedList,
                             src: &hData);
    }
    v8 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v8 )
LABEL_16:
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BF40
// Name: public: void CUtlHandleTable<struct WaveCache_t,11>::RemoveHandle(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHandleTable<WaveCache_t,11>::RemoveHandle(
        CUtlHandleTable<WaveCache_t,11> *this,
        unsigned int handle)
{
  unsigned int v2; // edi
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v3; // edx
  int v4; // eax

  v2 = handle & 0x7FF;
  if ( v2 < this->m_list.m_Size )
  {
    v3 = &this->m_list.m_Memory.m_pMemory[v2];
    v4 = *(_DWORD *)v3 ^ (*(_DWORD *)v3 ^ (*(_DWORD *)v3 + 1)) & 0x7FFFFFFF;
    *(_DWORD *)v3 = v4;
    if ( v4 >= 0 )
    {
      *(_DWORD *)v3 = v4 | 0x80000000;
      --this->m_nValidHandles;
    }
    v3->m_pData = nullptr;
    if ( (*(_DWORD *)v3 & 0x7FFFFFFFu) < 0xFFFFF )
    {
      handle = v2;
      CUtlQueue<int,CUtlMemory<int,int>>::Insert(this: &this->m_unused, element: (const int *)&handle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BFA0
// Name: public: bool CWaveCache::CacheRemove(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWaveCache::CacheRemove(CWaveCache *this, unsigned int hData)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  CUtlHandleTable<WaveCache_t,11> *p_m_HandleTable; // ebx
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  WaveCache_t *m_pData; // edi
  char *FileName; // eax
  CWaveCache *v10; // ecx
  CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *p_m_UnlockedList; // ebx
  bool v12; // zf
  CUtlHandleTable<WaveCache_t,11> *v13; // [esp+4h] [ebp-8h]
  unsigned __int16 m_hUnlock; // [esp+8h] [ebp-4h]

  if ( hData == 0 )
    return 0;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WaveCacheMutex->m_depth;
  }
  p_m_HandleTable = &this->m_HandleTable;
  v13 = &this->m_HandleTable;
  if ( hData == -1
    || (v6 = hData & 0x7FF) >= this->m_HandleTable.m_list.m_Size
    || (*(_DWORD *)(v7 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) != hData >> 11
    || (*(_DWORD *)v7 & 0x80000000) == 0x80000000
    || (m_pData = v7->m_pData) == nullptr
    || m_pData->m_nLockCount != 0 )
  {
    v12 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v12 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 0;
  }
  else
  {
    if ( snd_async_stream_purges.m_pParent != nullptr && snd_async_stream_purges.m_pParent->m_Value.m_nValue != 0 )
    {
      FileName = CAsyncWaveData::GetFileName(this: m_pData->m_pWaveData);
      _Msg(a1: "CacheRemove: Age:%d %s\n", m_pData->m_nAgeStamp, FileName);
    }
    CAsyncWaveData::DestroyResource(this: m_pData->m_pWaveData);
    v10 = this;
    this->m_nCurrentMemorySize -= m_pData->m_nDataSize;
    if ( m_pData->m_hUnlock != 0xFFFF )
    {
      p_m_UnlockedList = &this->m_UnlockedList;
      m_hUnlock = m_pData->m_hUnlock;
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        this: &v10->m_UnlockedList,
        elem: m_hUnlock);
      p_m_UnlockedList->m_Memory.m_pMemory[m_hUnlock].m_Next = p_m_UnlockedList->m_FirstFree;
      p_m_UnlockedList->m_FirstFree = m_hUnlock;
      p_m_HandleTable = v13;
    }
    CUtlHandleTable<WaveCache_t,11>::RemoveHandle(this: p_m_HandleTable, handle: hData);
    free(pMem: m_pData);
    v12 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v12 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C100
// Name: public: void CWaveCache::Purge(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveCache::Purge(CWaveCache *this, unsigned int nBytesToPurge)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // edi
  DWORD CurrentThreadId; // ecx
  int m_Head; // eax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v6; // eax
  unsigned int m_Element; // ecx
  unsigned int v8; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v9; // edx
  WaveCache_t *m_pData; // eax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v12; // [esp+Ch] [ebp-18h]
  CThreadFastMutex *generated_id_25; // [esp+10h] [ebp-14h]
  unsigned int nBytesPurged; // [esp+14h] [ebp-10h]
  unsigned int nCandidateSize; // [esp+18h] [ebp-Ch]
  unsigned int hCandidate; // [esp+1Ch] [ebp-8h]
  unsigned int nCandidateAge; // [esp+20h] [ebp-4h]

  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  generated_id_25 = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WaveCacheMutex->m_depth;
  }
  nBytesPurged = 0;
  if ( nBytesToPurge != 0 )
  {
    while ( 1 )
    {
      m_Head = this->m_UnlockedList.m_Head;
      nCandidateSize = 0;
      nCandidateAge = -1;
      hCandidate = 0;
      if ( m_Head == 0xFFFF )
        break;
      do
      {
        v6 = &this->m_UnlockedList.m_Memory.m_pMemory[(unsigned __int16)m_Head];
        m_Element = v6->m_Element;
        v12 = v6;
        if ( v6->m_Element != -1 )
        {
          v8 = v6->m_Element & 0x7FF;
          if ( v8 < this->m_HandleTable.m_list.m_Size )
          {
            v9 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v8];
            if ( (*(_DWORD *)v9 & 0x7FFFFFFF) == m_Element >> 11 && (*(_DWORD *)v9 & 0x80000000) != 0x80000000 )
            {
              m_pData = v9->m_pData;
              if ( m_pData != nullptr && m_pData->m_nAgeStamp < nCandidateAge )
              {
                nCandidateAge = m_pData->m_nAgeStamp;
                nCandidateSize = m_pData->m_nDataSize;
                hCandidate = m_Element;
              }
            }
          }
        }
        m_Head = v12->m_Next;
      }
      while ( m_Head != 0xFFFF );
      if ( hCandidate == 0
        || CWaveCache::CacheRemove(this, hData: hCandidate) == 0
        || (nBytesPurged += nCandidateSize, nBytesPurged >= nBytesToPurge) )
      {
        p_m_WaveCacheMutex = generated_id_25;
        break;
      }
      p_m_WaveCacheMutex = generated_id_25;
    }
  }
  if ( p_m_WaveCacheMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003C220
// Name: public: void CWaveCache::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveCache::Flush(CWaveCache *this)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  int m_ElementCount; // eax
  int m_Size; // esi
  unsigned int *m_pMemory; // edi
  int m_Head; // eax
  int v8; // ebx
  UtlLinkedListElem_t<unsigned int,unsigned short> *v9; // edx
  int v10; // ecx
  unsigned int *v11; // ecx
  int i; // ebx
  int m_nGrowSize; // esi
  CThreadFastMutex *m_lock; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > purgeList; // [esp+Ch] [ebp-24h] BYREF
  CAutoLockT<CThreadFastMutex> generated_id_26; // [esp+20h] [ebp-10h]
  int v18; // [esp+24h] [ebp-Ch]
  UtlLinkedListElem_t<unsigned int,unsigned short> *v19; // [esp+28h] [ebp-8h]
  CWaveCache *v20; // [esp+2Ch] [ebp-4h]

  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  v20 = this;
  generated_id_26.m_lock = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WaveCacheMutex->m_depth;
  }
  m_ElementCount = this->m_UnlockedList.m_ElementCount;
  m_Size = 0;
  m_pMemory = nullptr;
  purgeList.m_Memory.m_pMemory = nullptr;
  purgeList.m_Memory.m_nAllocationCount = m_ElementCount;
  purgeList.m_Memory.m_nGrowSize = 0;
  if ( m_ElementCount != 0 )
  {
    m_pMemory = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_ElementCount);
    purgeList.m_Memory.m_pMemory = m_pMemory;
  }
  m_Head = this->m_UnlockedList.m_Head;
  purgeList.m_Size = 0;
  for ( purgeList.m_pElements = m_pMemory; m_Head != 0xFFFF; m_Head = v20->m_UnlockedList.m_Memory.m_pMemory[v8].m_Next )
  {
    v8 = (unsigned __int16)m_Head;
    v9 = &v20->m_UnlockedList.m_Memory.m_pMemory[v8];
    v10 = m_Size;
    v19 = v9;
    v18 = m_Size;
    if ( m_Size + 1 > purgeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&purgeList,
        num: m_Size - purgeList.m_Memory.m_nAllocationCount + 1);
      m_Size = purgeList.m_Size;
      m_pMemory = purgeList.m_Memory.m_pMemory;
      v9 = v19;
      v10 = v18;
    }
    purgeList.m_Size = ++m_Size;
    purgeList.m_pElements = m_pMemory;
    if ( m_Size - v10 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
      v9 = v19;
      v10 = v18;
    }
    v11 = &m_pMemory[v10];
    if ( v11 != nullptr )
      *v11 = v9->m_Element;
  }
  for ( i = 0; i < m_Size; ++i )
    CWaveCache::CacheRemove(this: v20, hData: m_pMemory[i]);
  m_nGrowSize = purgeList.m_Memory.m_nGrowSize;
  purgeList.m_Size = 0;
  if ( purgeList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      purgeList.m_Memory.m_pMemory = nullptr;
    }
    purgeList.m_Memory.m_nAllocationCount = 0;
  }
  purgeList.m_pElements = m_pMemory;
  if ( m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      purgeList.m_Memory.m_pMemory = nullptr;
    }
    purgeList.m_Memory.m_nAllocationCount = 0;
  }
  m_lock = generated_id_26.m_lock;
  if ( generated_id_26.m_lock->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)m_lock, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003C3C0
// Name: public: virtual void CAsyncWavDataCache::CloseStreamedLoad(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::CloseStreamedLoad(CAsyncWavDataCache *this, int hStream)
{
  int v2; // eax
  CAsyncWavDataCache *v3; // edi
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *m_pMemory; // ebx
  CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *p_m_StreamedHandles; // ecx
  int v6; // esi
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v7; // ebx
  unsigned int v8; // esi
  CAsyncWaveData *NoTouch; // eax
  int v10; // eax
  CAsyncWavDataCache::DeadBufferEntry_t *v11; // ecx
  CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *v13; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  unsigned int *m_hWaveData; // [esp+14h] [ebp-4h]

  v2 = hStream;
  v3 = this;
  if ( hStream != -1 )
  {
    m_pMemory = this->m_StreamedHandles.m_Memory.m_pMemory;
    p_m_StreamedHandles = &this->m_StreamedHandles;
    v6 = hStream << 6;
    v7 = &m_pMemory[hStream];
    v13 = &v3->m_StreamedHandles;
    i = 0;
    if ( v7->m_Element.m_numBuffers > 0 )
    {
      m_hWaveData = v7->m_Element.m_hWaveData;
      do
      {
        v8 = *m_hWaveData;
        if ( *m_hWaveData != 0 )
        {
          if ( CWaveCache::GetLockCount(this: &s_WaveCache, hData: *m_hWaveData) <= 1 )
          {
            NoTouch = CWaveCache::CacheGetNoTouch(this: &s_WaveCache, hData: v8);
            if ( NoTouch == nullptr || (*((_BYTE *)NoTouch + 84) & 3) != 0 )
            {
              CWaveCache::CacheUnlock(this: &s_WaveCache, hData: v8);
              if ( v7->m_Element.m_bSinglePlay )
                CWaveCache::CacheRemove(this: &s_WaveCache, hData: v8);
            }
            else
            {
              v10 = CUtlVector<CAsyncWavDataCache::DeadBufferEntry_t,CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>>::AddToTail(this: &v3->m_DeadBuffers);
              v3->m_DeadBuffers.m_Memory.m_pMemory[v10].hWaveData = v8;
              v11 = v3->m_DeadBuffers.m_Memory.m_pMemory;
              v3 = this;
              v11[v10].bSinglePlay = v7->m_Element.m_bSinglePlay;
            }
          }
          else
          {
            CWaveCache::CacheUnlock(this: &s_WaveCache, hData: v8);
          }
        }
        ++m_hWaveData;
        ++i;
      }
      while ( i < v7->m_Element.m_numBuffers );
      v6 = hStream << 6;
      v2 = hStream;
      p_m_StreamedHandles = v13;
    }
    CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::Unlink(
      this: p_m_StreamedHandles,
      elem: v2);
    *(int *)((char *)&v13->m_Memory.m_pMemory->m_Next + v6) = v13->m_FirstFree;
    v13->m_FirstFree = hStream;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C4B0
// Name: public: virtual void CAsyncWavDataCache::Flush(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::Flush(CAsyncWavDataCache *this, bool bTearDownStaticPool)
{
  if ( this->m_bInitialized )
  {
    CWaveCache::Flush(this: &s_WaveCache);
    CAsyncWavDataCache::SpewMemoryUsage(this, level: SPEW_BASIC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C4E0
// Name: private: void CAsyncWavDataCache::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::Clear(CAsyncWavDataCache *this)
{
  CAsyncWavDataCache *v1; // edi
  int i; // eax
  int v3; // esi
  int j; // eax
  int v5; // eax
  char *v6; // edi
  int v7; // ebx
  unsigned int *v8; // esi
  int k; // esi
  int v10; // [esp+Ch] [ebp-8h]

  v1 = this;
  for ( i = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::FirstInorder(this: &this->m_CacheHandles);
        ;
        i = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::NextInorder(
              this: &v1->m_CacheHandles,
              i: v3) )
  {
    v3 = i;
    if ( i < 0 || i >= v1->m_CacheHandles.m_Elements.m_nAllocationCount || i > v1->m_CacheHandles.m_LastAlloc.index )
      break;
    if ( (`CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_104BF0AC = -1;
      dword_104BF0B0 = -1;
      dword_104BF0B4 = 1;
    }
    if ( v1->m_CacheHandles.m_Elements.m_pMemory[i].m_Left == i )
      break;
    CWaveCache::CacheRemove(this: &s_WaveCache, hData: v1->m_CacheHandles.m_Elements.m_pMemory[i].m_Data.handle);
  }
  CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::RemoveAll(this: &v1->m_CacheHandles);
  for ( j = v1->m_StreamedHandles.m_Head; j != -1; v1 = this )
  {
    v5 = j << 6;
    v6 = (char *)v1->m_StreamedHandles.m_Memory.m_pMemory + v5;
    v7 = 0;
    v10 = v5;
    if ( *((int *)v6 + 11) > 0 )
    {
      v8 = (unsigned int *)(v6 + 4);
      do
      {
        CWaveCache::BreakLock(this: &s_WaveCache, hData: *v8);
        CWaveCache::CacheRemove(this: &s_WaveCache, hData: *v8);
        ++v7;
        ++v8;
      }
      while ( v7 < *((_DWORD *)v6 + 11) );
      v5 = v10;
    }
    j = *(int *)((char *)&this->m_StreamedHandles.m_Memory.m_pMemory->m_Next + v5);
  }
  CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::RemoveAll(this: &v1->m_StreamedHandles);
  for ( k = 0; k < v1->m_DeadBuffers.m_Size; ++k )
  {
    CWaveCache::BreakLock(this: &s_WaveCache, hData: v1->m_DeadBuffers.m_Memory.m_pMemory[k].hWaveData);
    CWaveCache::CacheRemove(this: &s_WaveCache, hData: v1->m_DeadBuffers.m_Memory.m_pMemory[k].hWaveData);
  }
  v1->m_DeadBuffers.m_Size = 0;
  if ( v1->m_DeadBuffers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_DeadBuffers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_DeadBuffers.m_Memory.m_pMemory);
      v1->m_DeadBuffers.m_Memory.m_pMemory = nullptr;
    }
    v1->m_DeadBuffers.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_DeadBuffers.m_pElements = v1->m_DeadBuffers.m_Memory.m_pMemory;
  CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int>>::RemoveAll(this: &v1->m_BufferList);
}

//------------------------------------------------------------------------------
// Address: 0x1003C660
// Name: snd_async_flush
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_async_flush()
{
  if ( g_AsyncWaveDataCache.m_bInitialized )
  {
    CWaveCache::Flush(this: &s_WaveCache);
    CAsyncWavDataCache::SpewMemoryUsage(this: &g_AsyncWaveDataCache, level: SPEW_BASIC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C680
// Name: public: unsigned int CWaveCache::CacheCreate(struct asyncwaveparams_t,enum WaveCacheAddFlags_t)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWaveCache::CacheCreate(CWaveCache *this, asyncwaveparams_t params, WaveCacheAddFlags_t flags)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // edi
  DWORD CurrentThreadId; // ecx
  unsigned int m_nMaxMemorySize; // eax
  int v7; // ebx
  bool v8; // zf
  unsigned int result; // eax
  CAsyncWaveData *v10; // ebx
  CAsyncWaveData **v11; // edi
  CUtlHandleTable<WaveCache_t,11> *p_m_HandleTable; // ebx
  CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *p_m_UnlockedList; // ebx
  unsigned __int16 v14; // ax
  int v15; // esi
  unsigned __int16 v16; // ax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v17; // eax
  unsigned int v18; // ecx
  int *v19; // ecx
  CThreadFastMutex *generated_id_19; // [esp+Ch] [ebp-Ch]
  CUtlHandleTable<WaveCache_t,11> *v21; // [esp+10h] [ebp-8h]
  unsigned int hData; // [esp+14h] [ebp-4h]

  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  generated_id_19 = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WaveCacheMutex->m_depth;
  }
  m_nMaxMemorySize = this->m_nMaxMemorySize;
  if ( (m_nMaxMemorySize == -1
     || (v7 = params.datasize + 88, params.datasize + 88 + this->m_nCurrentMemorySize <= m_nMaxMemorySize)
     || (CWaveCache::Purge(this, nBytesToPurge: params.datasize + 88),
         v7 + this->m_nCurrentMemorySize <= this->m_nMaxMemorySize))
    && (v10 = CAsyncWaveData::CreateResource(&params)) != nullptr )
  {
    v11 = (CAsyncWaveData **)MemAlloc_Alloc(nSize: 0x14u);
    *v11 = v10;
    v11[1] = (CAsyncWaveData *)(v10->m_nDataSize + 88);
    v11[2] = (CAsyncWaveData *)this->m_nAgeStamp++;
    this->m_nCurrentMemorySize += (unsigned int)v11[1];
    p_m_HandleTable = &this->m_HandleTable;
    v21 = &this->m_HandleTable;
    result = CUtlHandleTable<WaveCache_t,11>::AddHandle(this: &this->m_HandleTable);
    hData = result;
    if ( (flags & 1) != 0 )
    {
      v11[3] = (CAsyncWaveData *)1;
      v11[4] = (CAsyncWaveData *)0xFFFF;
    }
    else
    {
      p_m_UnlockedList = &this->m_UnlockedList;
      v11[3] = nullptr;
      v14 = CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal(
              this: &this->m_UnlockedList,
              multilist: false);
      v15 = v14;
      if ( v14 == 0xFFFF )
      {
        v16 = -1;
      }
      else
      {
        CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
          this: p_m_UnlockedList,
          before: 0xFFFFu,
          elem: v14);
        v17 = &p_m_UnlockedList->m_Memory.m_pMemory[v15];
        if ( v17 != nullptr )
          v17->m_Element = hData;
        v16 = v15;
      }
      p_m_HandleTable = v21;
      v11[4] = (CAsyncWaveData *)v16;
      result = hData;
    }
    if ( result != -1 )
    {
      v18 = result & 0x7FF;
      if ( v18 < p_m_HandleTable->m_list.m_Size )
      {
        v19 = (int *)&p_m_HandleTable->m_list.m_Memory.m_pMemory[v18];
        if ( (*v19 & 0x7FFFFFFF) == result >> 11 )
        {
          if ( *v19 < 0 )
          {
            ++p_m_HandleTable->m_nValidHandles;
            *v19 &= ~0x80000000;
          }
          v19[1] = (int)v11;
        }
      }
    }
    v8 = generated_id_19->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)generated_id_19, 0);
  }
  else
  {
    v8 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003C800
// Name: public: virtual void CAsyncWavDataCache::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::Shutdown(CAsyncWavDataCache *this)
{
  CUtlMemoryPool *v2; // edi

  if ( this->m_bInitialized )
  {
    CAsyncWavDataCache::Clear(this);
    v2 = g_pAudioStreamPool;
    if ( g_pAudioStreamPool != nullptr )
    {
      CUtlMemoryPool::~CUtlMemoryPool(this: g_pAudioStreamPool);
      free(pMem: v2);
    }
    this->m_bInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C840
// Name: public: virtual unsigned int CAsyncWavDataCache::AsyncLoadCache(char const __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAsyncWavDataCache::AsyncLoadCache(
        CAsyncWavDataCache *this,
        const char *filename,
        unsigned int datasize,
        unsigned int startpos,
        bool bIsPrefetch)
{
  void *v6; // edi
  int v7; // eax
  UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int> *m_pMemory; // ecx
  int v9; // eax
  int p_m_Data; // esi
  asyncwaveparams_t v12; // [esp-18h] [ebp-40h]
  unsigned int params_12; // [esp+18h] [ebp-10h]
  int params_16; // [esp+1Ch] [ebp-Ch]
  CAsyncWavDataCache::CacheEntry_t search; // [esp+20h] [ebp-8h] BYREF

  v6 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: filename);
  search.name = v6;
  search.handle = 0;
  v7 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Find(
         this: &this->m_CacheHandles,
         &search);
  if ( v7 == -1 )
    v7 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Insert(
           this: &this->m_CacheHandles,
           insert: &search);
  m_pMemory = this->m_CacheHandles.m_Elements.m_pMemory;
  v9 = v7;
  p_m_Data = (int)&m_pMemory[v9].m_Data;
  if ( CWaveCache::CacheGet(this: &s_WaveCache, hData: m_pMemory[v9].m_Data.handle) == nullptr )
  {
    *(_QWORD *)&v12.hFilename = __PAIR64__(datasize, (unsigned int)v6);
    *(_QWORD *)&v12.seekpos = __PAIR64__(params_12, startpos);
    *((_DWORD *)&v12 + 4) = (params_16 & 0xF0 ^ bIsPrefetch) & 1 ^ params_16 & 0xFFFFFFF0;
    *(_DWORD *)(p_m_Data + 4) = CWaveCache::CacheCreate(this: &s_WaveCache, params: v12, flags: WCAF_DEFAULT);
  }
  return *(_DWORD *)(p_m_Data + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1003C8F0
// Name: private: unsigned int CAsyncWavDataCache::FindOrCreateBuffer(struct asyncwaveparams_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAsyncWavDataCache::FindOrCreateBuffer(
        CAsyncWavDataCache *this,
        asyncwaveparams_t *params,
        bool bFind)
{
  int seekpos; // ecx
  int v5; // eax
  CAsyncWaveData *v6; // edi
  int v7; // esi
  double v9; // st7
  char tempBuff[260]; // [esp+Ch] [ebp-114h] BYREF
  CAsyncWavDataCache::BufferEntry_t search; // [esp+110h] [ebp-10h] BYREF

  seekpos = params->seekpos;
  search.m_hName = params->hFilename;
  search.m_StartPos = seekpos;
  *((_DWORD *)&search + 3) = *((_DWORD *)&search + 3) & 0xFFFFFFFC | ((*((_DWORD *)params + 4) & 4) != 0) | (2 * bFind);
  search.m_hWaveData = 0;
  if ( bFind )
  {
    v5 = CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int>>::Find(
           this: &this->m_BufferList,
           &search);
    if ( v5 != -1 )
    {
      search.m_hWaveData = this->m_BufferList.m_Elements.m_pMemory[v5].m_Data.m_hWaveData;
      if ( snd_async_stream_spew.m_pParent != nullptr && snd_async_stream_spew.m_pParent->m_Value.m_nValue >= 2 )
      {
        g_pFileSystem->String(this: g_pFileSystem, a2: (void *const *)params, a3: tempBuff, a4: 260);
        _Msg(a1: "Found Buffer: %s, offset: %d\n", tempBuff, params->seekpos);
      }
    }
  }
  v6 = CWaveCache::CacheLock(this: &s_WaveCache, hData: search.m_hWaveData);
  if ( v6 != nullptr )
  {
    v9 = _Plat_FloatTime();
    v6->m_arrival = v9;
    v6->m_start = v9;
    return search.m_hWaveData;
  }
  else
  {
    search.m_hWaveData = CWaveCache::CacheCreate(this: &s_WaveCache, params: *params, flags: WCAF_LOCK);
    if ( search.m_hWaveData != 0 )
    {
LABEL_11:
      v7 = CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int>>::Insert(
             this: &this->m_BufferList,
             insert: &search);
      CWaveCache::CacheGet(this: &s_WaveCache, hData: search.m_hWaveData)->m_hBuffer = v7;
      return search.m_hWaveData;
    }
    else
    {
      while ( (*((_BYTE *)params + 16) & 4) != 0 )
      {
        v6 = (CAsyncWaveData *)((char *)v6 + 1);
        if ( (int)v6 >= 2 )
        {
          if ( snd_async_stream_fail.m_pParent != nullptr && snd_async_stream_fail.m_pParent->m_Value.m_nValue != 0 )
            _Warning(a1: "Stream pool: No buffers available! (dead:%d)\n", this->m_DeadBuffers.m_Size);
          return 0;
        }
        CWaveCache::Purge(this: &s_WaveCache, nBytesToPurge: 0x10000u);
        search.m_hWaveData = CWaveCache::CacheCreate(this: &s_WaveCache, params: *params, flags: WCAF_LOCK);
        if ( search.m_hWaveData != 0 )
          goto LABEL_11;
      }
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CAC0
// Name: public: virtual int CAsyncWavDataCache::OpenStreamedLoad(char const __near *,int,int,int,int,int,int,unsigned int,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncWavDataCache::OpenStreamedLoad(
        CAsyncWavDataCache *this,
        const char *pFileName,
        int dataSize,
        int dataStart,
        int startPos,
        int loopPos,
        int bufferSize,
        int numBuffers,
        unsigned int flags,
        SoundError *soundError)
{
  unsigned int v10; // ebx
  int v11; // edi
  void *v12; // esi
  int v13; // esi
  int v14; // ebx
  unsigned int v15; // eax
  CAsyncWavDataCache *v16; // edi
  int v17; // eax
  int v18; // ebx
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *m_pMemory; // eax
  int v20; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v22; // eax
  CAsyncWavDataCache::StreamedEntry_t *v23; // eax
  CAsyncWavDataCache::StreamedEntry_t streamedEntry; // [esp+8h] [ebp-50h]
  asyncwaveparams_t params; // [esp+40h] [ebp-18h] BYREF
  CAsyncWavDataCache *v27; // [esp+54h] [ebp-4h]
  bool bFailed_3; // [esp+77h] [ebp+1Fh]
  bool bFindBuffer; // [esp+7Ch] [ebp+24h]

  *((_DWORD *)&params + 4) &= 0xFFFFFFF0;
  v10 = flags;
  v27 = this;
  if ( (flags & 4) != 0 )
  {
    if ( numBuffers != 1 )
      numBuffers = 1;
    if ( (flags & 8) != 0 )
      v10 = flags & 0xFFFFFFF7;
  }
  v11 = bufferSize;
  if ( (v10 & 8) != 0 && bufferSize != 0x10000 )
    v11 = 0x10000;
  if ( (v10 & 8) == 0 && (v10 & 2) != 0 )
    v10 &= ~2u;
  v12 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: pFileName);
  streamedEntry.m_DataSize = dataSize;
  streamedEntry.m_DataStart = dataStart;
  streamedEntry.m_numBuffers = numBuffers;
  streamedEntry.m_LoopStart = loopPos;
  streamedEntry.m_NextStartPos = startPos + numBuffers * v11;
  streamedEntry.m_hName = v12;
  streamedEntry.m_Front = 0;
  streamedEntry.m_BufferSize = v11;
  streamedEntry.m_bSinglePlay = (v10 & 2) != 0;
  streamedEntry.m_SectorSize = 1;
  streamedEntry.m_bIsTransient = false;
  bFindBuffer = (v10 & 0xC) != 0 && (v10 & 2) == 0;
  params.alignment = 1;
  params.hFilename = v12;
  v13 = 0;
  params.datasize = v11;
  *((_DWORD *)&params + 4) = *((_DWORD *)&params + 4) & 0xFFFFFFF1 | (v10 >> 1) & 2 | (2 * (v10 & 4));
  bFailed_3 = false;
  if ( numBuffers > 0 )
  {
    v14 = startPos;
    do
    {
      params.seekpos = dataStart + streamedEntry.m_SectorSize * (v14 / streamedEntry.m_SectorSize);
      v15 = 0;
      if ( !bFailed_3 )
      {
        v15 = CAsyncWavDataCache::FindOrCreateBuffer(this: v27, &params, bFind: bFindBuffer);
        bFailed_3 = v15 == 0;
      }
      streamedEntry.m_hWaveData[v13++] = v15;
      v14 += v11;
    }
    while ( v13 < numBuffers );
  }
  v16 = v27;
  v17 = CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal(
          this: &v27->m_StreamedHandles,
          multilist: false);
  v18 = v17;
  if ( v17 == -1 )
  {
    v18 = -1;
  }
  else
  {
    CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::Unlink(
      this: &v16->m_StreamedHandles,
      elem: v17);
    m_pMemory = v16->m_StreamedHandles.m_Memory.m_pMemory;
    v20 = v18 << 6;
    *(int *)((char *)&m_pMemory->m_Next + v20) = -1;
    m_Tail = v16->m_StreamedHandles.m_Tail;
    *(int *)((char *)&m_pMemory->m_Previous + v20) = m_Tail;
    v16->m_StreamedHandles.m_Tail = v18;
    if ( m_Tail == -1 )
      v16->m_StreamedHandles.m_Head = v18;
    else
      v16->m_StreamedHandles.m_Memory.m_pMemory[m_Tail].m_Next = v18;
    v22 = v16->m_StreamedHandles.m_Memory.m_pMemory;
    ++v16->m_StreamedHandles.m_ElementCount;
    v23 = (CAsyncWavDataCache::StreamedEntry_t *)((char *)&v22->m_Element + v20);
    if ( v23 != nullptr )
    {
      *v23 = streamedEntry;
      v16 = v27;
    }
  }
  if ( bFailed_3 )
  {
    v16->CloseStreamedLoad(this: v16, a2: v18);
    *soundError = SE_NO_STREAM_BUFFER;
    return -1;
  }
  else
  {
    *soundError = SE_OK;
    return v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CC90
// Name: public: virtual bool CAsyncWavDataCache::CopyDataIntoMemory(unsigned int __near &,char const __near *,int,int,void __near *,int,int,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::CopyDataIntoMemory(
        CAsyncWavDataCache *this,
        unsigned int *handle,
        const char *filename,
        unsigned int datasize,
        int startpos,
        void *buffer,
        int bufsize,
        int copystartpos,
        int bytestocopy,
        bool *pbPostProcessed)
{
  unsigned int *v10; // edi
  bool v11; // bl
  CAsyncWaveData *v12; // esi
  void *v13; // ebx
  int v14; // esi
  unsigned int v16; // eax
  asyncwaveparams_t v17; // [esp-18h] [ebp-48h]
  unsigned int v18; // [esp-4h] [ebp-34h]
  __int64 params_12; // [esp+18h] [ebp-18h]
  CAsyncWavDataCache::CacheEntry_t search; // [esp+20h] [ebp-10h] BYREF
  CAsyncWavDataCache *v21; // [esp+28h] [ebp-8h]
  bool bret; // [esp+2Fh] [ebp-1h]

  v10 = handle;
  v21 = this;
  *pbPostProcessed = false;
  v18 = *handle;
  v11 = false;
  bret = false;
  v12 = CWaveCache::CacheLock(this: &s_WaveCache, hData: v18);
  if ( v12 == nullptr )
  {
    v13 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: filename);
    search.name = v13;
    search.handle = 0;
    v14 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Find(
            this: &v21->m_CacheHandles,
            &search);
    if ( v14 == -1 )
      return false;
    *(_QWORD *)&v17.hFilename = __PAIR64__(datasize, (unsigned int)v13);
    v17.seekpos = startpos;
    *(_QWORD *)&v17.alignment = params_12 & 0xFFFFFFF0FFFFFFFFuLL;
    v16 = CWaveCache::CacheCreate(this: &s_WaveCache, params: v17, flags: WCAF_DEFAULT);
    v10 = handle;
    v21->m_CacheHandles.m_Elements.m_pMemory[v14].m_Data.handle = v16;
    *handle = v16;
    v12 = CWaveCache::CacheLock(this: &s_WaveCache, hData: v16);
    if ( v12 == nullptr )
      return false;
    v11 = bret;
  }
  if ( v12->m_nDataSize != 0 )
    v11 = CAsyncWaveData::BlockingCopyData(
            this: v12,
            destbuffer: buffer,
            destbufsize: bufsize,
            startoffset: copystartpos,
            count: bytestocopy);
  *pbPostProcessed = (*((_DWORD *)v12 + 21) & 4) != 0;
  CWaveCache::CacheUnlock(this: &s_WaveCache, hData: *v10);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1003CDA0
// Name: private: void CAsyncWavDataCache::PrefetchNextBuffers(struct CAsyncWavDataCache::StreamedEntry_t __near &,struct CAsyncWavDataCache::StreamData_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::PrefetchNextBuffers(
        CAsyncWavDataCache *this,
        CAsyncWavDataCache::StreamedEntry_t *streamedEntry,
        CAsyncWavDataCache::StreamData_t *streamData)
{
  bool v3; // cc
  CAsyncWavDataCache::StreamData_t *v4; // edi
  int m_LoopStart; // eax
  int m_DataSize; // edi
  void *m_hName; // ebx
  int v8; // eax
  unsigned int v9; // edx
  int m_BufferSize; // ecx
  int v11; // edi
  int v12; // edx
  bool v13; // zf
  int v14; // ebx
  unsigned int v15; // eax
  asyncwaveparams_t params; // [esp+4h] [ebp-18h] BYREF
  CAsyncWavDataCache *v17; // [esp+18h] [ebp-4h]

  v3 = streamedEntry->m_numBuffers <= 1;
  v17 = this;
  if ( !v3 )
  {
    v4 = streamData;
    if ( streamedEntry->m_Front < streamData->index )
    {
      while ( 1 )
      {
        m_LoopStart = v4->actualCopied != 0 || v4->bWaiting
                    ? streamedEntry->m_NextStartPos
                    : v4->copyStartPos - streamedEntry->m_DataStart;
        m_DataSize = streamedEntry->m_DataSize;
        if ( m_LoopStart >= m_DataSize )
        {
          m_LoopStart = streamedEntry->m_LoopStart;
          if ( m_LoopStart < 0 )
            break;
        }
        m_hName = streamedEntry->m_hName;
        params.alignment = streamedEntry->m_SectorSize;
        params.hFilename = m_hName;
        v8 = params.alignment * (m_LoopStart / params.alignment);
        v9 = (*((_BYTE *)&params + 16)
            & 0xF0
            ^ (unsigned __int8)(4 * streamedEntry->m_bIsTransient))
           & 4
           ^ *((_DWORD *)&params + 4)
           & 0xFFFFFFF0;
        m_BufferSize = streamedEntry->m_BufferSize;
        v11 = m_DataSize - v8;
        params.seekpos = v8 + streamedEntry->m_DataStart;
        params.datasize = v11;
        *((_DWORD *)&params + 4) = v9;
        if ( v11 > m_BufferSize )
        {
          v11 = m_BufferSize;
          params.datasize = m_BufferSize;
        }
        v12 = streamedEntry->m_Front % streamedEntry->m_numBuffers;
        v13 = !streamedEntry->m_bSinglePlay;
        streamedEntry->m_NextStartPos = v8 + v11;
        v14 = v12;
        if ( v13 )
        {
          CWaveCache::CacheUnlock(this: &s_WaveCache, hData: streamedEntry->m_hWaveData[v12]);
          v15 = CAsyncWavDataCache::FindOrCreateBuffer(this: v17, &params, bFind: true);
          streamedEntry->m_hWaveData[v14] = v15;
          if ( v15 == 0 )
            return;
          v4 = streamData;
        }
        else
        {
          v4 = streamData;
          CAsyncWaveData::StartAsyncLoading(this: streamData->pWaveData[v12], &params);
        }
        v4->bWaiting = true;
        ++streamedEntry->m_Front;
        v4->copyStartPos += streamedEntry->m_BufferSize;
        if ( streamedEntry->m_Front >= v4->index )
          return;
      }
      ++streamedEntry->m_Front;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CEB0
// Name: public: virtual int CAsyncWavDataCache::CopyStreamedDataIntoMemory(int,void __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncWavDataCache::CopyStreamedDataIntoMemory(
        CAsyncWavDataCache *this,
        int hStream,
        void *pBuffer,
        int bufferSize,
        int copyStartPos,
        int bytesToCopy)
{
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v7; // esi
  CAsyncWavDataCache::StreamData_t streamData; // [esp+Ch] [ebp-20h] BYREF

  v7 = &this->m_StreamedHandles.m_Memory.m_pMemory[hStream];
  if ( copyStartPos >= v7->m_Element.m_DataSize + v7->m_Element.m_DataStart
    || !CAsyncWavDataCache::InitializeStreamData(this, streamedEntry: &v7->m_Element, &streamData, copyStartPos) )
  {
    return 0;
  }
  CAsyncWavDataCache::CopyFromCurrentBuffers(
    this,
    streamedEntry: &v7->m_Element,
    &streamData,
    hStream,
    pBuffer,
    bufferSize,
    bytesToCopy);
  CAsyncWavDataCache::PrefetchNextBuffers(this, streamedEntry: &v7->m_Element, &streamData);
  return streamData.actualCopied;
}

//------------------------------------------------------------------------------
// Address: 0x1003CF20
// Name: public: virtual bool CAsyncWavDataCache::GetDataPointer(unsigned int __near &,char const __near *,int,int,void __near * __near *,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::GetDataPointer(
        CAsyncWavDataCache *this,
        unsigned int *handle,
        const char *filename,
        unsigned int datasize,
        int startpos,
        void **pData,
        int copystartpos,
        bool *pbPostProcessed)
{
  unsigned int *v8; // ebx
  CAsyncWaveData *v10; // esi
  void *v11; // ebx
  int v12; // esi
  unsigned int v14; // eax
  asyncwaveparams_t v15; // [esp-18h] [ebp-44h]
  unsigned int v16; // [esp-4h] [ebp-30h]
  __int64 params_12; // [esp+18h] [ebp-14h]
  CAsyncWavDataCache::CacheEntry_t search; // [esp+20h] [ebp-Ch] BYREF
  bool bret; // [esp+2Bh] [ebp-1h]

  v8 = handle;
  *pbPostProcessed = false;
  *pData = nullptr;
  v16 = *handle;
  bret = false;
  v10 = CWaveCache::CacheLock(this: &s_WaveCache, hData: v16);
  if ( v10 == nullptr )
  {
    v11 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: filename);
    search.name = v11;
    search.handle = 0;
    v12 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Find(
            this: &this->m_CacheHandles,
            &search);
    if ( v12 == -1 )
      return false;
    *(_QWORD *)&v15.hFilename = __PAIR64__(datasize, (unsigned int)v11);
    v15.seekpos = startpos;
    *(_QWORD *)&v15.alignment = params_12 & 0xFFFFFFF0FFFFFFFFuLL;
    v14 = CWaveCache::CacheCreate(this: &s_WaveCache, params: v15, flags: WCAF_DEFAULT);
    v8 = handle;
    this->m_CacheHandles.m_Elements.m_pMemory[v12].m_Data.handle = v14;
    *handle = v14;
    v10 = CWaveCache::CacheLock(this: &s_WaveCache, hData: v14);
    if ( v10 == nullptr )
      return false;
  }
  if ( v10->m_nDataSize != 0
    && copystartpos < v10->m_nDataSize
    && CAsyncWaveData::BlockingGetDataPointer(this: v10, ppData: pData) )
  {
    *pData = (char *)*pData + copystartpos;
    bret = true;
  }
  *pbPostProcessed = (*((_DWORD *)v10 + 21) & 4) != 0;
  CWaveCache::CacheUnlock(this: &s_WaveCache, hData: *v8);
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x100FEF60
// Name: public: void CUtlMemory<struct CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
        CUtlMemory<ResourceEntryInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ResourceEntryInfo *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2820
// Name: public: virtual class CAudioSource __near & CWaveDataStreamAsync::Source(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveDataStreamAsync::Source(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10036B40
// Name: public: void CAsyncWaveData::DestroyResource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWaveData::DestroyResource(CAsyncWaveData *this)
{
  FSAsyncControl_t__ *m_hAsyncControl; // eax

  m_hAsyncControl = this->m_hAsyncControl;
  if ( m_hAsyncControl != nullptr )
  {
    if ( (*((_BYTE *)this + 84) & 3) == 0 )
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: m_hAsyncControl, a3: true);
    g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: this->m_hAsyncControl);
    this->m_hAsyncControl = nullptr;
  }
  g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: this->m_pAlloc);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x10036BA0
// Name: public: char const __near * CAsyncWaveData::GetFileName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAsyncWaveData::GetFileName(CAsyncWaveData *this)
{
  bool v1; // zf
  char *result; // eax

  if ( this->m_hFileNameHandle == nullptr )
    return (char *)defaultValue;
  v1 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260);
  result = sz;
  if ( v1 )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036BE0
// Name: public: void CAsyncWaveData::OnAsyncCompleted(struct FileAsyncRequest_t const __near *,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWaveData::OnAsyncCompleted(
        CAsyncWaveData *this,
        const FileAsyncRequest_t *asyncFilePtr,
        int numReadBytes,
        FSAsyncStatus_t err)
{
  int nBytes; // eax
  char *m_pAlloc; // edx
  int v7; // ecx
  int v8; // edx

  if ( err == FSASYNC_OK || err == FSASYNC_ERR_READING )
  {
    this->m_arrival = _Plat_FloatTime();
    nBytes = this->m_async.nBytes;
    this->m_pAlloc = asyncFilePtr->pData;
    m_pAlloc = (char *)this->m_pAlloc;
    v7 = nBytes - this->m_nDataSize;
    this->m_async.nBytes = this->m_nDataSize;
    this->m_pvData = &m_pAlloc[v7];
    v8 = *((_DWORD *)this + 21);
    this->m_async.nOffset = v7;
    this->m_nReadSize = numReadBytes - v7;
    *((_DWORD *)this + 21) = v8 & 0xFFFFFFFA | 1;
  }
  else if ( err == FSASYNC_ERR_FILEOPEN )
  {
    *((_DWORD *)this + 21) |= 2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036C50
// Name: private: static bool CAsyncWavDataCache::BufferHandleLessFunc(struct CAsyncWavDataCache::BufferEntry_t const __near &,struct CAsyncWavDataCache::BufferEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CAsyncWavDataCache::BufferHandleLessFunc(
        const CAsyncWavDataCache::BufferEntry_t *lhs,
        const CAsyncWavDataCache::BufferEntry_t *rhs)
{
  int v2; // ebx
  int v3; // edi
  bool v4; // cf
  int m_StartPos; // edx
  int v6; // esi

  v2 = *((_DWORD *)rhs + 3);
  v3 = *((_DWORD *)lhs + 3);
  v4 = (v3 & 1u) < (v2 & 1u);
  if ( (v3 & 1) == (v2 & 1) )
  {
    v4 = lhs->m_hName < rhs->m_hName;
    if ( lhs->m_hName == rhs->m_hName )
    {
      m_StartPos = lhs->m_StartPos;
      v6 = rhs->m_StartPos;
      if ( m_StartPos != v6 )
        return m_StartPos < v6;
      return (unsigned __int8)(v3 & 2) < (unsigned __int8)(v2 & 2);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10036CB0
// Name: public: virtual void CAsyncWavDataCache::PrefetchCache(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::PrefetchCache(
        CAsyncWavDataCache *this,
        const char *filename,
        int datasize,
        int startpos)
{
  this->AsyncLoadCache(this, a2: filename, a3: datasize, a4: startpos, a5: true);
}

//------------------------------------------------------------------------------
// Address: 0x10036CD0
// Name: void PrefetchDataStream(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrefetchDataStream(const char *pFileName, int dataOffset, int dataSize)
{
  wavedatacache->PrefetchCache(this: wavedatacache, a2: pFileName, a3: dataSize, a4: dataOffset);
}

//------------------------------------------------------------------------------
// Address: 0x10036CF0
// Name: private: char const __near * CWaveDataStreamAsync::GetFileName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveDataStreamAsync::GetFileName(CWaveDataStreamAsync *this)
{
  bool v1; // zf
  char *result; // eax

  if ( this->m_hFileName == nullptr )
    return (char *)defaultValue;
  v1 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileName, a3: fn, a4: 260);
  result = fn;
  if ( v1 )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036D30
// Name: public: virtual void CWaveDataStreamAsync::UpdateLoopPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveDataStreamAsync::UpdateLoopPosition(CWaveDataStreamAsync *this, int nLoopPosition)
{
  int m_hStream; // eax

  m_hStream = this->m_hStream;
  if ( m_hStream != -1 )
    wavedatacache->UpdateLoopPosition(this: wavedatacache, a2: m_hStream, a3: nLoopPosition);
}

//------------------------------------------------------------------------------
// Address: 0x10036D60
// Name: public: virtual int CWaveDataMemoryAsync::ReadSourceData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveDataMemoryAsync::ReadSourceData(
        CWaveDataMemoryAsync *this,
        void **pData,
        __int64 sampleIndex,
        int sampleCount,
        char *copyBuf)
{
  return ((int (__thiscall *)(CAudioSource *, void **, _DWORD, _DWORD, int, char *))this->m_source->GetOutputData)(
           a1: this->m_source,
           a2: pData,
           a3: sampleIndex,
           a4: HIDWORD(sampleIndex),
           a5: sampleCount,
           a6: copyBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10036D90
// Name: bool StringHasPrefix(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl StringHasPrefix(const char *str, const char *prefix)
{
  return StringAfterPrefix(str, prefix) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10036DE0
// Name: public: static void CAsyncWaveData::AsyncCallback(struct FileAsyncRequest_t const __near &,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAsyncWaveData::AsyncCallback(
        const FileAsyncRequest_t *asyncRequest,
        int numReadBytes,
        FSAsyncStatus_t err)
{
  CAsyncWaveData *pContext; // ecx

  pContext = (CAsyncWaveData *)asyncRequest->pContext;
  if ( pContext != nullptr )
    CAsyncWaveData::OnAsyncCompleted(this: pContext, asyncFilePtr: asyncRequest, numReadBytes, err);
}

//------------------------------------------------------------------------------
// Address: 0x10036E00
// Name: public: void CAsyncWaveData::SetAsyncPriority(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWaveData::SetAsyncPriority(CAsyncWaveData *this, int priority)
{
  const char *v3; // edi
  double v4; // [esp+20h] [ebp-10h]

  if ( this->m_async.priority != priority )
  {
    this->m_async.priority = priority;
    g_pFileSystem->AsyncSetPriority(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: priority);
    if ( snd_async_spew_blocking.m_pParent != nullptr && snd_async_spew_blocking.m_pParent->m_Value.m_nValue >= 2 )
    {
      if ( this->m_hFileNameHandle == nullptr
        || (v3 = sz, !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260)) )
      {
        v3 = defaultValue;
      }
      v4 = (_Plat_FloatTime() - this->m_start) * 1000.0;
      DevMsg(a1: "%f Async I/O Bumped priority for %s (%8.2f msec)\n", realtime, v3, v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036EB0
// Name: public: void CAsyncWaveData::StartAsyncLoading(struct asyncwaveparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWaveData::StartAsyncLoading(CAsyncWaveData *this, const asyncwaveparams_t *params)
{
  void *hFilename; // eax
  bool v4; // zf
  const char *v5; // eax
  BOOL v6; // eax
  int v7; // ecx
  char szFilename[260]; // [esp+8h] [ebp-104h] BYREF

  hFilename = params->hFilename;
  this->m_hFileNameHandle = params->hFilename;
  if ( hFilename == nullptr
    || (v4 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260), v5 = sz, v4) )
  {
    v5 = defaultValue;
  }
  V_snprintf(pDest: szFilename, maxLen: 260, pFormat: "sound\\%s", v5);
  v6 = (*((_BYTE *)params + 16) & 1) == 0;
  this->m_async.pData = nullptr;
  this->m_async.nOffset = 0;
  v7 = params->datasize + params->seekpos;
  *((_DWORD *)this + 21) &= 0xFFFFFFFC;
  this->m_async.nBytes = v7;
  this->m_async.pfnCallback = CAsyncWaveData::AsyncCallback;
  this->m_async.pContext = this;
  this->m_async.priority = v6;
  this->m_async.flags = 1;
  this->m_async.pszPathID = "GAME";
  this->m_nDataSize = params->datasize;
  this->m_start = _Plat_FloatTime();
  *((_DWORD *)this + 21) &= ~4u;
  this->m_arrival = 0.0;
  this->m_nReadSize = 0;
  this->m_async.pszFilename = szFilename;
  g_pFileSystem->AsyncReadMultiple(this: g_pFileSystem, a2: &this->m_async, a3: 1, a4: &this->m_hAsyncControl);
}

//------------------------------------------------------------------------------
// Address: 0x10036FA0
// Name: public: virtual bool CAsyncWavDataCache::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncWavDataCache::Init(CAsyncWavDataCache *this, unsigned int memSize)
{
  unsigned int v3; // eax

  if ( this->m_bInitialized )
    return 1;
  v3 = memSize;
  if ( memSize < 0x1400000 )
    v3 = 20971520;
  s_WaveCache.m_nMaxMemorySize = v3;
  this->m_bInitialized = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10036FE0
// Name: private: void CAsyncWavDataCache::CopyFromCurrentBuffers(struct CAsyncWavDataCache::StreamedEntry_t __near &,struct CAsyncWavDataCache::StreamData_t __near &,int,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::CopyFromCurrentBuffers(
        CAsyncWavDataCache *this,
        CAsyncWavDataCache::StreamedEntry_t *streamedEntry,
        CAsyncWavDataCache::StreamData_t *streamData,
        int hStream,
        char *pBuffer,
        int bufferSize,
        int bytesToCopy)
{
  CAsyncWavDataCache::StreamData_t *v7; // esi
  CAsyncWaveData *v8; // edi
  int v9; // ebx
  float m_start; // xmm0_4
  int v11; // esi
  bool v12; // zf
  const char *v13; // eax
  int m_nReadSize; // eax
  int v15; // esi
  char *FileName; // eax
  char v17; // bl
  int m_numBuffers; // edi
  CAsyncWaveData **pWaveData; // edx
  int *v20; // ecx
  int v21; // eax
  float intervala; // [esp+Ch] [ebp-Ch]
  int interval; // [esp+Ch] [ebp-Ch]
  int nRemainingBytesToCopy; // [esp+10h] [ebp-8h]
  bool bCompleted; // [esp+17h] [ebp-1h]

  nRemainingBytesToCopy = bytesToCopy;
  while ( 1 )
  {
    v7 = streamData;
    v8 = streamData->pWaveData[streamData->index % streamedEntry->m_numBuffers];
    v9 = streamData->copyStartPos - v8->m_async.nOffset;
    bCompleted = (*((_BYTE *)v8 + 84) & 3) != 0;
    if ( snd_async_stream_spew.m_pParent != nullptr && snd_async_stream_spew.m_pParent->m_Value.m_nValue >= 1 )
    {
      intervala = _Plat_FloatTime(a1: streamedEntry);
      m_start = v8->m_start;
      interval = (int)(float)((float)(intervala - m_start) * 1000.0);
      if ( bCompleted && (*((_BYTE *)v8 + 84) & 1) != 0 )
        v11 = (int)(float)((float)(v8->m_arrival - m_start) * 1000.0);
      else
        v11 = -1;
      if ( v8->m_hFileNameHandle == nullptr
        || (v12 = !g_pFileSystem->String(this: g_pFileSystem, a2: &v8->m_hFileNameHandle, a3: sz, a4: 260), v13 = sz, v12) )
      {
        v13 = defaultValue;
      }
      _Msg(
        a1: "Stream:%2d interval:%5dms latency:%5dms offset:%d length:%d (%s)\n",
        hStream,
        interval,
        v11,
        v8->m_async.nOffset,
        v8->m_nReadSize,
        v13);
      v7 = streamData;
    }
    if ( !bCompleted )
      break;
    if ( v8->m_hAsyncControl != nullptr && (*((_BYTE *)v8 + 84) & 3) != 0 )
    {
      g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: v8->m_hAsyncControl);
      v8->m_hAsyncControl = nullptr;
    }
    if ( (*((_BYTE *)v8 + 84) & 1) == 0 )
    {
      if ( (*((_BYTE *)v8 + 84) & 2) != 0 )
      {
        FileName = CAsyncWaveData::GetFileName(this: v8);
        MaybeReportMissingWav(wav: FileName);
        goto LABEL_34;
      }
      break;
    }
    if ( v9 < 0 )
      goto LABEL_45;
    m_nReadSize = v8->m_nReadSize;
    if ( v9 < m_nReadSize )
    {
      v15 = nRemainingBytesToCopy;
      if ( v9 + nRemainingBytesToCopy > m_nReadSize )
        v15 = m_nReadSize - v9;
      if ( v15 + v9 > bufferSize )
        v15 = bufferSize - v9;
      if ( v15 <= 0 )
      {
        _Warning(
          a1: "%s(%d): Protecting against negative memcpy. BufferSize = %d. Buffer Pos = %d. Count = %d.\n",
          "..\\engine\\audio\\private\\snd_wave_data.cpp",
          2051,
          bufferSize,
          v9,
          v15);
        return;
      }
      _V_memcpy(dest: pBuffer, src: (char *)v8->m_pvData + v9, count: v15);
      streamData->actualCopied += v15;
      streamData->copyStartPos += v15;
      nRemainingBytesToCopy -= v15;
      pBuffer += v15;
      v9 += v15;
      bufferSize -= v15;
      v7 = streamData;
    }
    if ( v9 < 0 || v9 >= v8->m_nReadSize )
    {
LABEL_45:
      if ( ++v7->index - streamedEntry->m_Front >= streamedEntry->m_numBuffers )
        goto LABEL_34;
    }
    if ( v7->actualCopied == bytesToCopy )
      return;
  }
  v7->bWaiting = true;
LABEL_34:
  v17 = 0;
  if ( streamedEntry->m_numBuffers <= 0 )
    goto LABEL_42;
  m_numBuffers = streamedEntry->m_numBuffers;
  pWaveData = v7->pWaveData;
  do
  {
    v20 = (int *)*pWaveData;
    if ( (*((_BYTE *)*pWaveData + 84) & 2) == 0 )
    {
      v21 = v7->copyStartPos - v20[6];
      if ( v21 >= 0 && v21 < *v20 )
        v17 = 1;
    }
    ++pWaveData;
    --m_numBuffers;
  }
  while ( m_numBuffers != 0 );
  if ( v17 == 0 )
LABEL_42:
    streamedEntry->m_NextStartPos = v7->copyStartPos - streamedEntry->m_DataStart;
}

//------------------------------------------------------------------------------
// Address: 0x10037220
// Name: public: CWaveDataStreamAsync::CWaveDataStreamAsync(class CAudioSource __near &,class IWaveStreamSource __near *,char const __near *,int,int,class CSfxTable __near *,int,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CWaveDataStreamAsync *__thiscall CWaveDataStreamAsync::CWaveDataStreamAsync(
        CWaveDataStreamAsync *this,
        CAudioSource *source,
        IWaveStreamSource *pStreamSource,
        const char *pFileName,
        int fileStart,
        int fileSize,
        CSfxTable *sfx,
        int startOffset,
        SoundError *soundError)
{
  void **p_m_hFileName; // edi
  void *v11; // eax
  bool v12; // zf
  const char *v13; // eax
  const char *v15; // eax
  char *v16; // eax
  int v17; // eax
  CSfxTable *m_pSfx; // edi
  CAudioSourceCachedInfo *v19; // eax

  this->m_source = source;
  this->m_pStreamSource = pStreamSource;
  this->m_dataStart = fileStart;
  this->m_dataSize = fileSize;
  this->__vftable = (CWaveDataStreamAsync_vtbl *)&CWaveDataStreamAsync::`vftable';
  this->m_pBuffer = nullptr;
  this->m_hCache = 0;
  this->m_hStream = -1;
  this->m_hFileName = nullptr;
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  *((_DWORD *)this + 22) &= ~1u;
  p_m_hFileName = &this->m_hFileName;
  this->m_pSfx = sfx;
  *soundError = SE_OK;
  v11 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: pFileName);
  *p_m_hFileName = v11;
  this->m_sampleIndex = 0;
  this->m_bufferCount = 0;
  this->m_nCachedDataSize = 0;
  if ( this->m_dataSize > 0 )
  {
    if ( v11 == nullptr
      || (v12 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileName, a3: fn, a4: 260), v15 = fn, v12) )
    {
      v15 = defaultValue;
    }
    this->m_hCache = wavedatacache->AsyncLoadCache(
                       this: wavedatacache,
                       a2: v15,
                       a3: this->m_dataSize,
                       a4: this->m_dataStart,
                       a5: false);
    v16 = (char *)MemAlloc_Alloc(nSize: 0x4000u);
    this->m_pBuffer = v16;
    _V_memset(dest: v16, fill: 0, count: 0x4000);
    v17 = source->SampleSize(this: source);
    m_pSfx = this->m_pSfx;
    this->m_sampleSize = v17;
    this->m_bufferSize = 0x4000 / v17;
    this->m_waveSize = fileSize / v17;
    LOBYTE(soundError) = CSfxTable::IsPrecachedSound(this: m_pSfx);
    if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
    {
      v19 = audiosourcecache->GetInfo(this: audiosourcecache, a2: 1, a3: soundError, a4: m_pSfx);
      this->m_AudioCacheHandle.info = v19;
      if ( this != (CWaveDataStreamAsync *)-72 && v19 != nullptr )
        this->m_nCachedDataSize = v19->m_usCachedDataSize;
      this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    _V_memset(dest: this->m_LastSample, fill: 0, count: 8);
    *((_DWORD *)this + 22) |= 1u;
    return this;
  }
  else
  {
    if ( v11 == nullptr
      || (v12 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileName, a3: fn, a4: 260), v13 = fn, v12) )
    {
      v13 = defaultValue;
    }
    _DevMsg(a1: 1, a2: "Can't find streaming wav file: sound\\%s\n", v13);
    *soundError = SE_FILE_NOT_FOUND;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100373E0
// Name: class IWaveData __near * CreateWaveDataStream(class CAudioSource __near &,class IWaveStreamSource __near *,char const __near *,int,int,class CSfxTable __near *,int,int,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CWaveDataStreamAsync *__cdecl CreateWaveDataStream(
        CAudioSource *source,
        IWaveStreamSource *pStreamSource,
        const char *pFileName,
        int dataStart,
        int dataSize,
        CSfxTable *pSfx,
        int startOffset,
        int skipInitialSamples,
        SoundError *soundError)
{
  CWaveDataStreamAsync *v9; // eax
  CWaveDataStreamAsync *result; // eax

  v9 = (CWaveDataStreamAsync *)MemAlloc_Alloc(nSize: 0x60u);
  if ( v9 != nullptr )
  {
    result = CWaveDataStreamAsync::CWaveDataStreamAsync(
               this: v9,
               source,
               pStreamSource,
               pFileName,
               fileStart: dataStart,
               fileSize: dataSize,
               sfx: pSfx,
               startOffset,
               soundError);
    if ( result != nullptr )
    {
      if ( (*((_BYTE *)result + 88) & 1) != 0 )
        return result;
      ((void (__thiscall *)(CWaveDataStreamAsync *, int))result->dtr_IWaveData)(a1: result, a2: 1);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10037430
// Name: class IWaveData __near * CreateWaveDataMemory(class CAudioSource __near &)
// Source: json
//------------------------------------------------------------------------------
IWaveData *__cdecl CreateWaveDataMemory(CAudioSource *source)
{
  IWaveData *result; // eax

  result = (IWaveData *)MemAlloc_Alloc(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IWaveData_vtbl *)&CWaveDataMemoryAsync::`vftable';
  result[1].__vftable = (IWaveData_vtbl *)source;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100374B0
// Name: public: static class CAsyncWaveData __near * CAsyncWaveData::CreateResource(struct asyncwaveparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAsyncWaveData *__cdecl CAsyncWaveData::CreateResource(const asyncwaveparams_t *params)
{
  unsigned __int8 *v1; // eax
  CAsyncWaveData *v2; // esi

  v1 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x58u);
  v2 = (CAsyncWaveData *)v1;
  if ( v1 == nullptr )
    return nullptr;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  memset(dst: v1 + 16, value: 0, count: 0x2Cu);
  v2->m_async.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
  *((_DWORD *)v2 + 21) &= 0xFFFFFFE0;
  v2->m_hAsyncControl = nullptr;
  v2->m_start = 0.0;
  v2->m_arrival = 0.0;
  v2->m_hFileNameHandle = nullptr;
  v2->m_nBufferBytes = 0;
  v2->m_hBuffer = -1;
  CAsyncWaveData::StartAsyncLoading(this: v2, params);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10037530
// Name: public: bool CAsyncWaveData::BlockingCopyData(void __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncWaveData::BlockingCopyData(
        CAsyncWaveData *this,
        void *destbuffer,
        int destbufsize,
        int startoffset,
        int count)
{
  int v6; // ecx
  bool v7; // zf
  const char *v8; // eax
  int v9; // eax
  char *FileName; // eax
  int m_nReadSize; // eax
  int v13; // ecx
  double v14; // [esp+28h] [ebp-11Ch]
  char fn[260]; // [esp+38h] [ebp-10Ch] BYREF
  float ed; // [esp+13Ch] [ebp-8h]
  float st; // [esp+140h] [ebp-4h]

  if ( (*((_BYTE *)this + 84) & 1) == 0 )
  {
    if ( snd_async_spew_blocking.m_pParent != nullptr && snd_async_spew_blocking.m_pParent->m_Value.m_nValue != 0 )
    {
      st = _Plat_FloatTime(a1: this);
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
      ed = _Plat_FloatTime(a1: v6);
      if ( this->m_hFileNameHandle == nullptr
        || (v7 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260), v8 = sz, v7) )
      {
        v8 = defaultValue;
      }
      DevMsg(
        a1: "%f BCD:  Async I/O Force %s (%8.2f msec / %8.2f msec total)\n",
        realtime,
        v8,
        1000.0 * (ed - st),
        (this->m_arrival - this->m_start) * 1000.0);
    }
    else
    {
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
    }
  }
  v9 = *((_DWORD *)this + 21);
  if ( (v9 & 2) != 0 )
  {
    *((_DWORD *)this + 21) = v9 & 0xFFFFFFFD;
    if ( g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: fn, a4: 260) )
      MaybeReportMissingWav(wav: fn);
  }
  if ( (*((_BYTE *)this + 84) & 1) == 0 )
    return 0;
  st = this->m_arrival;
  if ( st != 0.0
    && snd_async_spew_blocking.m_pParent != nullptr
    && snd_async_spew_blocking.m_pParent->m_Value.m_nValue >= 2 )
  {
    v14 = (st - this->m_start) * 1000.0;
    FileName = CAsyncWaveData::GetFileName(this);
    DevMsg(a1: "%f Async I/O Read successful %s (%8.2f msec)\n", realtime, FileName, v14);
    this->m_arrival = 0.0;
  }
  m_nReadSize = this->m_nReadSize;
  v13 = count;
  if ( count > m_nReadSize )
    v13 = m_nReadSize - startoffset;
  if ( v13 < 0 )
    return 0;
  _V_memcpy(dest: destbuffer, src: (char *)this->m_pvData + startoffset - this->m_async.nOffset, count: v13);
  g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: this->m_hAsyncControl);
  this->m_hAsyncControl = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10037710
// Name: public: bool CAsyncWaveData::BlockingGetDataPointer(void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncWaveData::BlockingGetDataPointer(CAsyncWaveData *this, void **ppData)
{
  int v3; // ecx
  bool v4; // zf
  const char *v5; // eax
  int v6; // eax
  char *FileName; // eax
  double v9; // [esp+28h] [ebp-11Ch]
  char fn[260]; // [esp+38h] [ebp-10Ch] BYREF
  float ed; // [esp+13Ch] [ebp-8h]
  float st; // [esp+140h] [ebp-4h]

  if ( (*((_BYTE *)this + 84) & 1) == 0 )
  {
    if ( snd_async_spew_blocking.m_pParent != nullptr && snd_async_spew_blocking.m_pParent->m_Value.m_nValue != 0 )
    {
      st = _Plat_FloatTime(a1: this);
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
      ed = _Plat_FloatTime(a1: v3);
      if ( this->m_hFileNameHandle == nullptr
        || (v4 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: sz, a4: 260), v5 = sz, v4) )
      {
        v5 = defaultValue;
      }
      DevMsg(
        a1: "%f BlockingGetDataPointer:  Async I/O Force %s (%8.2f msec / %8.2f msec total )\n",
        realtime,
        v5,
        1000.0 * (ed - st),
        (this->m_arrival - this->m_start) * 1000.0);
    }
    else
    {
      g_pFileSystem->AsyncFinish(this: g_pFileSystem, a2: this->m_hAsyncControl, a3: true);
    }
  }
  v6 = *((_DWORD *)this + 21);
  if ( (v6 & 2) != 0 )
  {
    *((_DWORD *)this + 21) = v6 & 0xFFFFFFFD;
    if ( g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileNameHandle, a3: fn, a4: 260) )
      MaybeReportMissingWav(wav: fn);
  }
  if ( (*((_BYTE *)this + 84) & 1) == 0 )
    return 0;
  st = this->m_arrival;
  if ( st != 0.0
    && snd_async_spew_blocking.m_pParent != nullptr
    && snd_async_spew_blocking.m_pParent->m_Value.m_nValue >= 2 )
  {
    v9 = (st - this->m_start) * 1000.0;
    FileName = CAsyncWaveData::GetFileName(this);
    DevMsg(a1: "%f Async I/O Read successful %s (%8.2f msec)\n", realtime, FileName, v9);
    this->m_arrival = 0.0;
  }
  *ppData = this->m_pvData;
  g_pFileSystem->AsyncRelease(this: g_pFileSystem, a2: this->m_hAsyncControl);
  this->m_hAsyncControl = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100378D0
// Name: public: virtual void CAsyncWavDataCache::UpdateLoopPosition(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::UpdateLoopPosition(CAsyncWavDataCache *this, int hStream, int nLoopPosition)
{
  this->m_StreamedHandles.m_Memory.m_pMemory[hStream].m_Element.m_LoopStart = nLoopPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10037960
// Name: public: virtual bool CWaveDataStreamAsync::IsReadyToMix(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaveDataStreamAsync::IsReadyToMix(CWaveDataStreamAsync *this)
{
  bool result; // al
  bool v3; // zf
  const char *v4; // eax
  bool bLoaded; // [esp+6h] [ebp-2h]
  bool bCacheValid; // [esp+7h] [ebp-1h] BYREF

  if ( !this->m_source->IsAsyncLoad(this: this->m_source)
    && (snd_async_fullyasync.m_pParent == nullptr || snd_async_fullyasync.m_pParent->m_Value.m_nValue == 0) )
  {
    return true;
  }
  bLoaded = wavedatacache->IsDataLoadCompleted(this: wavedatacache, a2: this->m_hCache, a3: &bCacheValid, a4: nullptr);
  if ( !bCacheValid )
  {
    if ( this->m_hFileName == nullptr
      || (v3 = !g_pFileSystem->String(this: g_pFileSystem, a2: &this->m_hFileName, a3: fn, a4: 260), v4 = fn, v3) )
    {
      v4 = defaultValue;
    }
    wavedatacache->RestartDataLoad(
      this: wavedatacache,
      a2: &this->m_hCache,
      a3: v4,
      a4: this->m_dataSize,
      a5: this->m_dataStart);
  }
  v3 = !g_pEngineToolInternal->IsRecordingMovie(this: g_pEngineToolInternal);
  result = true;
  if ( v3 )
    return bLoaded;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037A20
// Name: public: virtual int CWaveDataStreamAsync::ReadSourceData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveDataStreamAsync::ReadSourceData(
        CWaveDataStreamAsync *this,
        void **pData,
        __int64 sampleIndex,
        int sampleCount,
        char *copyBuf)
{
  __int64 v6; // rax
  unsigned int v7; // ebx
  unsigned int v8; // edi
  char *FileName; // eax
  unsigned int m_sampleIndex_high; // eax
  unsigned int m_sampleIndex; // ecx
  unsigned int v12; // ebx
  unsigned int v13; // edi
  unsigned int v14; // kr00_4
  __int64 m_bufferCount; // rax
  __int64 v16; // rax
  int v17; // eax
  int v18; // ecx
  int m_dataStart; // edx
  int v20; // eax
  int v21; // edi
  int m_bufferSize; // ecx
  int v23; // ecx
  CAudioSourceCachedInfo *info; // eax
  bool IsPrecachedSound; // al
  int m_nCachedDataSize; // edx
  int m_sampleSize; // edi
  int v28; // eax
  int v29; // eax
  char *v30; // eax
  int v31; // esi
  int m_dataSize; // [esp-1Ch] [ebp-30h]
  int v34; // [esp-18h] [ebp-2Ch]
  char *m_pBuffer; // [esp-14h] [ebp-28h]
  int v36; // [esp-10h] [ebp-24h]
  CSfxTable *m_pSfx; // [esp-8h] [ebp-1Ch]
  int v38; // [esp-8h] [ebp-1Ch]
  const unsigned __int8 *cacheddata; // [esp+Ch] [ebp-8h]
  const unsigned __int8 *cacheddataa; // [esp+Ch] [ebp-8h]
  IAsyncWavDataCache_vtbl *cacheddatab; // [esp+Ch] [ebp-8h]
  bool postprocessed; // [esp+13h] [ebp-1h] BYREF
  unsigned int sampleIndexa; // [esp+20h] [ebp+Ch]

  if ( this->m_source->IsLooped(this: this->m_source) )
  {
    v6 = ((__int64 (__thiscall *)(IWaveStreamSource *, _DWORD, _DWORD))this->m_pStreamSource->UpdateLoopingSamplePosition)(
           a1: this->m_pStreamSource,
           a2: sampleIndex,
           a3: HIDWORD(sampleIndex));
    v7 = HIDWORD(v6);
    v8 = v6;
    if ( v6 < this->m_sampleIndex )
    {
      if ( snd_report_loop_sound.m_pParent != nullptr && snd_report_loop_sound.m_pParent->m_Value.m_nValue != 0 )
      {
        FileName = CWaveDataStreamAsync::GetFileName(this);
        _Warning(a1: "[Sound] Sound \"%s\" just looped.\n", FileName);
      }
      LODWORD(this->m_sampleIndex) = v8;
      HIDWORD(this->m_sampleIndex) = v7;
      this->m_bufferCount = 0;
    }
  }
  else
  {
    v7 = HIDWORD(sampleIndex);
    v8 = sampleIndex;
  }
  m_sampleIndex_high = HIDWORD(this->m_sampleIndex);
  m_sampleIndex = this->m_sampleIndex;
  if ( __SPAIR64__(v7, v8) < __SPAIR64__(m_sampleIndex_high, m_sampleIndex) )
  {
    v7 = HIDWORD(this->m_sampleIndex);
    v8 = this->m_sampleIndex;
  }
  v14 = v8 - m_sampleIndex;
  v12 = (__PAIR64__(v7, v8) - __PAIR64__(m_sampleIndex_high, m_sampleIndex)) >> 32;
  v13 = v14;
  m_bufferCount = this->m_bufferCount;
  if ( __SPAIR64__(v12, v14) >= m_bufferCount )
  {
    v16 = this->m_sampleIndex + m_bufferCount;
    LODWORD(this->m_sampleIndex) = v16;
    v17 = this->m_bufferCount;
    HIDWORD(this->m_sampleIndex) = HIDWORD(v16);
    v12 = (__PAIR64__(v12, v14) - v17) >> 32;
    sampleIndexa = v14 - v17;
    if ( (unsigned int)(__SPAIR64__(v12, v14 - v17) / this->m_bufferSize) != 0 )
    {
      this->m_sampleIndex += __PAIR64__(v12, v14 - v17);
      v12 = 0;
      sampleIndexa = 0;
    }
    v18 = this->m_sampleIndex;
    m_dataStart = this->m_dataStart;
    v20 = this->m_waveSize - v18;
    v21 = m_dataStart + v18 * this->m_sampleSize;
    this->m_bufferCount = v20;
    if ( v20 <= 0 )
      return 0;
    m_bufferSize = this->m_bufferSize;
    if ( v20 > m_bufferSize )
      this->m_bufferCount = m_bufferSize;
    v23 = v21 - m_dataStart;
    cacheddata = (const unsigned __int8 *)(v21 - m_dataStart);
    if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount
      || (info = this->m_AudioCacheHandle.info) == nullptr )
    {
      m_pSfx = this->m_pSfx;
      IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx);
      info = CAudioSourceCachedInfoHandle_t::Get(
               this: &this->m_AudioCacheHandle,
               audiosourcetype: 1,
               soundisprecached: IsPrecachedSound,
               sfx: m_pSfx,
               pcacheddatasize: &this->m_nCachedDataSize);
      if ( info == nullptr )
        goto LABEL_26;
      v23 = (int)cacheddata;
    }
    m_nCachedDataSize = this->m_nCachedDataSize;
    if ( m_nCachedDataSize > 0 && v23 < m_nCachedDataSize )
    {
      cacheddataa = info->m_pCachedData;
      if ( cacheddataa != nullptr )
      {
        m_sampleSize = this->m_sampleSize;
        v28 = (m_nCachedDataSize - v23) / m_sampleSize;
        if ( v28 > this->m_bufferSize )
          v28 = this->m_bufferSize;
        this->m_bufferCount = v28;
        _V_memcpy(dest: this->m_pBuffer, src: &cacheddataa[v23], count: v28 * m_sampleSize);
LABEL_29:
        v13 = sampleIndexa;
        goto LABEL_30;
      }
    }
LABEL_26:
    v29 = this->m_sampleSize;
    postprocessed = false;
    cacheddatab = wavedatacache->__vftable;
    v38 = v29 * this->m_bufferCount;
    v36 = v29 * this->m_bufferSize;
    m_pBuffer = this->m_pBuffer;
    v34 = this->m_dataStart;
    m_dataSize = this->m_dataSize;
    v30 = CWaveDataStreamAsync::GetFileName(this);
    if ( !cacheddatab->CopyDataIntoMemory(
            this: wavedatacache,
            a2: &this->m_hCache,
            a3: v30,
            a4: m_dataSize,
            a5: v34,
            a6: m_pBuffer,
            a7: v36,
            a8: v21,
            a9: v38,
            a10: &postprocessed) )
      return 0;
    if ( !postprocessed )
      this->m_pStreamSource->UpdateSamples(this: this->m_pStreamSource, a2: this->m_pBuffer, a3: this->m_bufferCount);
    goto LABEL_29;
  }
LABEL_30:
  if ( __SPAIR64__(v12, v13) >= this->m_bufferCount )
    return 0;
  *pData = &this->m_pBuffer[v13 * this->m_sampleSize];
  v31 = this->m_bufferCount - v13;
  if ( v31 > sampleCount )
    return sampleCount;
  return v31;
}

//------------------------------------------------------------------------------
// Address: 0x10037C50
// Name: public: virtual bool CWaveDataMemoryAsync::IsReadyToMix(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaveDataMemoryAsync::IsReadyToMix(CWaveDataMemoryAsync *this)
{
  if ( this->m_source->IsAsyncLoad(this: this->m_source)
    || snd_async_fullyasync.m_pParent != nullptr && snd_async_fullyasync.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_source->GetCacheStatus(this: this->m_source) == 1 )
      return true;
    this->m_source->CacheLoad(this: this->m_source);
    return false;
  }
  else
  {
    if ( this->m_source->GetCacheStatus(this: this->m_source) != 0
      && this->m_source->GetCacheStatus(this: this->m_source) != 3 )
    {
      return true;
    }
    return g_pEngineToolInternal->IsRecordingMovie(this: g_pEngineToolInternal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A8B0
// Name: public: class CAsyncWaveData __near * CWaveCache::CacheGet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAsyncWaveData *__thiscall CWaveCache::CacheGet(CWaveCache *this, unsigned int hData)
{
  CAsyncWaveData *result; // eax
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // eax
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  WaveCache_t *m_pData; // eax
  bool v9; // zf

  if ( hData == 0 )
    return nullptr;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_WaveCacheMutex.m_depth;
  }
  if ( hData != -1
    && (v6 = hData & 0x7FF) < this->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (m_pData = v7->m_pData) != nullptr )
  {
    m_pData->m_nAgeStamp = this->m_nAgeStamp++;
    result = m_pData->m_pWaveData;
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
  else
  {
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A970
// Name: public: class CAsyncWaveData __near * CWaveCache::CacheGetNoTouch(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAsyncWaveData *__thiscall CWaveCache::CacheGetNoTouch(CWaveCache *this, unsigned int hData)
{
  CWaveCache *v2; // ebx
  CAsyncWaveData *result; // eax
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  CAsyncWaveData **p_m_pWaveData; // ecx
  bool v9; // zf

  v2 = this;
  if ( hData == 0 )
    return nullptr;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
      v2 = this;
      goto LABEL_8;
    }
    v2 = this;
  }
  ++p_m_WaveCacheMutex->m_depth;
LABEL_8:
  if ( hData != -1
    && (v6 = hData & 0x7FF) < v2->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &v2->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (p_m_pWaveData = &v7->m_pData->m_pWaveData) != nullptr )
  {
    result = *p_m_pWaveData;
    v9 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
  else
  {
    v9 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003AA30
// Name: public: void CWaveCache::Age(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveCache::Age(CWaveCache *this, unsigned int hData)
{
  CWaveCache *v2; // ebx
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v5; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v6; // ecx
  WaveCache_t *m_pData; // ecx
  bool v8; // zf

  v2 = this;
  if ( hData == 0 )
    return;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == p_m_WaveCacheMutex->m_ownerID )
    goto LABEL_5;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) == 0 )
  {
    v2 = this;
LABEL_5:
    ++p_m_WaveCacheMutex->m_depth;
    goto LABEL_7;
  }
  _mm_pause();
  CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  v2 = this;
LABEL_7:
  if ( hData != -1
    && (v5 = hData & 0x7FF) < v2->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v6 = &v2->m_HandleTable.m_list.m_Memory.m_pMemory[v5]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v6 & 0x80000000) != 0x80000000
    && (m_pData = v6->m_pData) != nullptr )
  {
    m_pData->m_nAgeStamp = 0;
    v8 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( !v8 )
      return;
  }
  else
  {
    v8 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( !v8 )
      return;
  }
  _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003AAF0
// Name: public: int CWaveCache::GetLockCount(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWaveCache::GetLockCount(CWaveCache *this, unsigned int hData)
{
  CWaveCache *v2; // ebx
  unsigned int result; // eax
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  WaveCache_t *m_pData; // ecx
  bool v9; // zf

  v2 = this;
  if ( hData == 0 )
    return 0;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
      v2 = this;
      goto LABEL_8;
    }
    v2 = this;
  }
  ++p_m_WaveCacheMutex->m_depth;
LABEL_8:
  if ( hData != -1
    && (v6 = hData & 0x7FF) < v2->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &v2->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (m_pData = v7->m_pData) != nullptr )
  {
    result = m_pData->m_nLockCount;
    v9 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
  else
  {
    v9 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003ABB0
// Name: public: virtual bool CAsyncWavDataCache::CopyDataIntoMemory(char const __near *,int,int,void __near *,int,int,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::CopyDataIntoMemory(
        CAsyncWavDataCache *this,
        const char *filename,
        int datasize,
        int startpos,
        void *buffer,
        int bufsize,
        int copystartpos,
        int bytestocopy,
        bool *pbPostProcessed)
{
  int v10; // eax
  CAsyncWavDataCache::CacheEntry_t search; // [esp+Ch] [ebp-8h] BYREF

  this->AsyncLoadCache(this, a2: filename, a3: datasize, a4: startpos, a5: false);
  search.name = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: filename);
  search.handle = 0;
  v10 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Find(
          this: &this->m_CacheHandles,
          &search);
  return v10 != -1
      && this->CopyDataIntoMemory(
           this,
           a2: &this->m_CacheHandles.m_Elements.m_pMemory[v10].m_Data.handle,
           a3: filename,
           a4: datasize,
           a5: startpos,
           a6: buffer,
           a7: bufsize,
           a8: copystartpos,
           a9: bytestocopy,
           a10: pbPostProcessed);
}

//------------------------------------------------------------------------------
// Address: 0x1003AC40
// Name: private: bool CAsyncWavDataCache::InitializeStreamData(struct CAsyncWavDataCache::StreamedEntry_t const __near &,struct CAsyncWavDataCache::StreamData_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncWavDataCache::InitializeStreamData(
        CAsyncWavDataCache *this,
        const CAsyncWavDataCache::StreamedEntry_t *streamedEntry,
        CAsyncWavDataCache::StreamData_t *streamData,
        int copyStartPos)
{
  const CAsyncWavDataCache::StreamedEntry_t *v4; // ecx
  CAsyncWavDataCache::StreamData_t *v5; // eax
  int v6; // ecx
  CAsyncWaveData **pWaveData; // edi
  unsigned int v8; // esi
  CAsyncWaveData *m_pWaveData; // eax
  DWORD CurrentThreadId; // ecx
  int v11; // eax
  WaveCache_t *m_pData; // eax
  int i; // [esp+14h] [ebp-4h]

  v4 = streamedEntry;
  v5 = streamData;
  i = 0;
  if ( streamedEntry->m_numBuffers <= 0 )
  {
LABEL_23:
    v5->index = v4->m_Front;
    v5->actualCopied = 0;
    v5->bWaiting = false;
    v5->copyStartPos = copyStartPos;
    return 1;
  }
  else
  {
    v6 = (char *)streamedEntry - (char *)streamData;
    pWaveData = streamData->pWaveData;
    while ( 1 )
    {
      v8 = *(unsigned int *)((char *)pWaveData + v6);
      if ( v8 != 0 )
      {
        CurrentThreadId = GetCurrentThreadId();
        if ( CurrentThreadId != s_WaveCache.m_WaveCacheMutex.m_ownerID
          && _InterlockedCompareExchange((volatile signed __int32 *)&s_WaveCache.m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
        {
          _mm_pause();
          CThreadFastMutex::Lock(a1: &s_WaveCache.m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
        }
        else
        {
          ++s_WaveCache.m_WaveCacheMutex.m_depth;
        }
        if ( v8 != -1
          && (unsigned int)(v11 = v8 & 0x7FF) < s_WaveCache.m_HandleTable.m_list.m_Size
          && (*(_DWORD *)&s_WaveCache.m_HandleTable.m_list.m_Memory.m_pMemory[v11] & 0x7FFFFFFF) == v8 >> 11
          && (*(_DWORD *)&s_WaveCache.m_HandleTable.m_list.m_Memory.m_pMemory[v11] & 0x80000000) != 0x80000000
          && (m_pData = s_WaveCache.m_HandleTable.m_list.m_Memory.m_pMemory[v11].m_pData) != nullptr )
        {
          m_pWaveData = m_pData->m_pWaveData;
          if ( --s_WaveCache.m_WaveCacheMutex.m_depth == 0 )
            _InterlockedExchange((volatile __int32 *)&s_WaveCache.m_WaveCacheMutex, 0);
        }
        else
        {
          if ( --s_WaveCache.m_WaveCacheMutex.m_depth == 0 )
            _InterlockedExchange((volatile __int32 *)&s_WaveCache.m_WaveCacheMutex, 0);
          m_pWaveData = nullptr;
        }
      }
      else
      {
        m_pWaveData = nullptr;
      }
      *pWaveData = m_pWaveData;
      if ( m_pWaveData == nullptr )
        return 0;
      v4 = streamedEntry;
      ++pWaveData;
      if ( ++i >= streamedEntry->m_numBuffers )
      {
        v5 = streamData;
        goto LABEL_23;
      }
      v6 = (char *)streamedEntry - (char *)streamData;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AD80
// Name: public: virtual void __near * CAsyncWavDataCache::GetStreamedDataPointer(int,bool)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CAsyncWavDataCache::GetStreamedDataPointer(CAsyncWavDataCache *this, int hStream, bool bSync)
{
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v3; // esi
  int v4; // edx
  CAsyncWaveData *NoTouch; // eax
  int v6; // ecx
  void *pData; // [esp+4h] [ebp-4h] BYREF

  v3 = &this->m_StreamedHandles.m_Memory.m_pMemory[hStream];
  v4 = v3->m_Element.m_Front % v3->m_Element.m_numBuffers;
  pData = nullptr;
  NoTouch = CWaveCache::CacheGetNoTouch(this: &s_WaveCache, hData: v3->m_Element.m_hWaveData[v4]);
  if ( NoTouch == nullptr )
    return nullptr;
  v6 = *((_DWORD *)NoTouch + 21);
  if ( (v6 & 2) == 0 && (v6 & 1) != 0 )
    return NoTouch->m_pvData;
  if ( bSync && CAsyncWaveData::BlockingGetDataPointer(this: NoTouch, ppData: &pData) != 0 )
    return pData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003ADF0
// Name: public: virtual bool CAsyncWavDataCache::IsStreamedDataReady(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::IsStreamedDataReady(CAsyncWavDataCache *this, int hStream)
{
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v3; // eax
  CAsyncWaveData *NoTouch; // eax

  if ( hStream == -1 )
    return false;
  v3 = &this->m_StreamedHandles.m_Memory.m_pMemory[hStream];
  return v3->m_Element.m_Front != 0
      || (NoTouch = CWaveCache::CacheGetNoTouch(this: &s_WaveCache, hData: v3->m_Element.m_hWaveData[0])) == nullptr
      || (*((_BYTE *)NoTouch + 84) & 3) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003AE40
// Name: public: virtual void CAsyncWavDataCache::SetPostProcessed(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::SetPostProcessed(CAsyncWavDataCache *this, unsigned int handle, bool proc)
{
  CAsyncWaveData *v3; // eax

  v3 = CWaveCache::CacheGet(this: &s_WaveCache, hData: handle);
  if ( v3 != nullptr )
    *((_DWORD *)v3 + 21) ^= (*((_DWORD *)v3 + 21) ^ (4 * proc)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x1003AE70
// Name: public: virtual void CAsyncWavDataCache::Unload(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::Unload(CAsyncWavDataCache *this, unsigned int handle)
{
  CWaveCache::Age(this: &s_WaveCache, hData: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1003AE80
// Name: public: virtual bool CAsyncWavDataCache::IsDataLoadCompleted(unsigned int,bool __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::IsDataLoadCompleted(
        CAsyncWavDataCache *this,
        unsigned int handle,
        bool *pIsValid,
        bool *pIsMissing)
{
  CAsyncWaveData *v4; // esi
  int v5; // eax

  v4 = CWaveCache::CacheGet(this: &s_WaveCache, hData: handle);
  if ( v4 != nullptr )
  {
    *pIsValid = true;
    if ( pIsMissing != nullptr )
      *pIsMissing = (*((_DWORD *)v4 + 21) & 2) != 0;
    CAsyncWaveData::SetAsyncPriority(this: v4, priority: 1);
    return *((_DWORD *)v4 + 21) & 1;
  }
  else
  {
    *pIsValid = false;
    LOBYTE(v5) = 0;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1003AED0
// Name: public: virtual void CAsyncWavDataCache::RestartDataLoad(unsigned int __near *,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::RestartDataLoad(
        CAsyncWavDataCache *this,
        unsigned int *pHandle,
        const char *pFilename,
        int dataSize,
        int startpos)
{
  if ( CWaveCache::CacheGet(this: &s_WaveCache, hData: *pHandle) == nullptr )
    *pHandle = this->AsyncLoadCache(this, a2: pFilename, a3: dataSize, a4: startpos, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x1003AF10
// Name: public: virtual bool CAsyncWavDataCache::IsDataLoadInProgress(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::IsDataLoadInProgress(CAsyncWavDataCache *this, unsigned int handle)
{
  CAsyncWaveData *v2; // eax
  int v3; // ecx
  FSAsyncStatus_t v4; // eax
  bool result; // al

  v2 = CWaveCache::CacheGet(this: &s_WaveCache, hData: handle);
  result = false;
  if ( v2 != nullptr )
  {
    v3 = *((_DWORD *)v2 + 21);
    if ( (v3 & 1) != 0 )
      return true;
    if ( (v3 & 2) == 0 )
    {
      v4 = g_pFileSystem->AsyncStatus(this: g_pFileSystem, a2: v2->m_hAsyncControl);
      if ( v4 == FSASYNC_STATUS_INPROGRESS || v4 == FSASYNC_OK )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003AF60
// Name: public: void CAsyncWavDataCache::SpewMemoryUsage(enum CAsyncWavDataCache::MemoryUsageType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::SpewMemoryUsage(
        CAsyncWavDataCache *this,
        CAsyncWavDataCache::MemoryUsageType level)
{
  int m_nCurrentMemorySize; // eax
  int m_nMaxMemorySize; // ecx
  CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl*)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int> > *p_m_CacheHandles; // esi
  int Inorder; // eax
  int v7; // edi
  CAsyncWaveData *NoTouch; // eax
  const char *v9; // eax
  float v10; // xmm0_4
  int m_NumElements; // ebx
  const char *v12; // eax
  float value; // [esp+Ch] [ebp-130h]
  char name[260]; // [esp+28h] [ebp-114h] BYREF
  int v15; // [esp+12Ch] [ebp-10h]
  int bytesUsed; // [esp+130h] [ebp-Ch]
  int bytesTotal; // [esp+134h] [ebp-8h]
  CAsyncWavDataCache *v18; // [esp+138h] [ebp-4h]

  m_nCurrentMemorySize = s_WaveCache.m_nCurrentMemorySize;
  m_nMaxMemorySize = s_WaveCache.m_nMaxMemorySize;
  v18 = this;
  bytesUsed = s_WaveCache.m_nCurrentMemorySize;
  bytesTotal = s_WaveCache.m_nMaxMemorySize;
  if ( level != SPEW_BASIC )
  {
    p_m_CacheHandles = &this->m_CacheHandles;
    Inorder = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::FirstInorder(this: &this->m_CacheHandles);
    while ( 1 )
    {
      v7 = Inorder;
      if ( Inorder < 0
        || Inorder >= p_m_CacheHandles->m_Elements.m_nAllocationCount
        || Inorder > p_m_CacheHandles->m_LastAlloc.index
        || CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::LeftChild(
             this: p_m_CacheHandles,
             i: Inorder) == Inorder )
      {
        break;
      }
      if ( g_pFileSystem->String(
             this: g_pFileSystem,
             a2: (void *const *)&this->m_CacheHandles.m_Elements.m_pMemory[v7].m_Data,
             a3: name,
             a4: 260)
        && (level != SPEW_MUSIC_NONSTREAMING || V_stristr(pStr: name, pSearch: "music") != nullptr) )
      {
        this = v18;
        NoTouch = CWaveCache::CacheGetNoTouch(
                    this: &s_WaveCache,
                    hData: v18->m_CacheHandles.m_Elements.m_pMemory[v7].m_Data.handle);
        if ( NoTouch != nullptr )
        {
          v15 = NoTouch->m_nDataSize + 88;
          value = (float)(unsigned int)v15;
          v9 = V_pretifymem(value, digitsafterdecimal: 2, usebinaryonek: false);
          _Msg(a1: "\t%16.16s : %s\n", v9, name);
        }
        else
        {
          _Msg(a1: "\t%16.16s : %s\n", "not resident", name);
        }
        p_m_CacheHandles = &this->m_CacheHandles;
        Inorder = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::NextInorder(
                    this: &this->m_CacheHandles,
                    i: v7);
      }
      else
      {
        this = v18;
        p_m_CacheHandles = &v18->m_CacheHandles;
        Inorder = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::NextInorder(
                    this: &v18->m_CacheHandles,
                    i: v7);
      }
    }
    m_nCurrentMemorySize = bytesUsed;
    m_nMaxMemorySize = bytesTotal;
  }
  if ( m_nMaxMemorySize > 0 )
    v10 = (float)((float)m_nCurrentMemorySize * 100.0) / (float)m_nMaxMemorySize;
  else
    v10 = 0.0;
  m_NumElements = this->m_CacheHandles.m_NumElements;
  v12 = V_pretifymem(value: (float)m_nCurrentMemorySize, digitsafterdecimal: 2, usebinaryonek: false);
  _Msg(a1: "CAsyncWavDataCache:  %i .wavs total %s, %.2f %% of capacity\n", m_NumElements, v12, v10);
}

//------------------------------------------------------------------------------
// Address: 0x1003B130
// Name: snd_async_showmem
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_async_showmem()
{
  CAsyncWavDataCache::SpewMemoryUsage(this: &g_AsyncWaveDataCache, level: SPEW_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x1003B140
// Name: snd_async_showmem_summary
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_async_showmem_summary()
{
  CAsyncWavDataCache::SpewMemoryUsage(this: &g_AsyncWaveDataCache, level: SPEW_BASIC);
}

//------------------------------------------------------------------------------
// Address: 0x1003B150
// Name: snd_async_showmem_music
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_async_showmem_music()
{
  CAsyncWavDataCache::SpewMemoryUsage(this: &g_AsyncWaveDataCache, level: SPEW_MUSIC_NONSTREAMING);
}

//------------------------------------------------------------------------------
// Address: 0x1003B5D0
// Name: public: CAsyncWavDataCache::CAsyncWavDataCache(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncWavDataCache *__thiscall CAsyncWavDataCache::CAsyncWavDataCache(CAsyncWavDataCache *this)
{
  this->__vftable = (CAsyncWavDataCache_vtbl *)&CAsyncWavDataCache::`vftable';
  this->m_BufferList.m_LessFunc = (bool (__cdecl *)(const CAsyncWavDataCache::BufferEntry_t *, const CAsyncWavDataCache::BufferEntry_t *))CAsyncWavDataCache::BufferHandleLessFunc;
  this->m_BufferList.m_Elements.m_pMemory = nullptr;
  this->m_BufferList.m_Elements.m_nAllocationCount = 0;
  this->m_BufferList.m_Elements.m_nGrowSize = 0;
  this->m_BufferList.m_NumElements = 0;
  this->m_BufferList.m_Root = -1;
  this->m_BufferList.m_FirstFree = -1;
  this->m_BufferList.m_LastAlloc.index = -1;
  this->m_BufferList.m_pElements = this->m_BufferList.m_Elements.m_pMemory;
  this->m_StreamedHandles.m_Memory.m_pMemory = nullptr;
  this->m_StreamedHandles.m_Memory.m_nAllocationCount = 0;
  this->m_StreamedHandles.m_Memory.m_nGrowSize = 0;
  this->m_StreamedHandles.m_LastAlloc.index = -1;
  this->m_StreamedHandles.m_pElements = this->m_StreamedHandles.m_Memory.m_pMemory;
  this->m_StreamedHandles.m_Head = -1;
  this->m_StreamedHandles.m_Tail = -1;
  this->m_StreamedHandles.m_FirstFree = -1;
  this->m_StreamedHandles.m_ElementCount = 0;
  this->m_StreamedHandles.m_NumAlloced = 0;
  this->m_CacheHandles.m_LessFunc = (bool (__cdecl *)(const CAsyncWavDataCache::CacheEntry_t *, const CAsyncWavDataCache::CacheEntry_t *))CDmxSerializationDictionary::LessFunc;
  this->m_CacheHandles.m_Elements.m_pMemory = nullptr;
  this->m_CacheHandles.m_Elements.m_nAllocationCount = 0;
  this->m_CacheHandles.m_Elements.m_nGrowSize = 0;
  this->m_CacheHandles.m_Root = -1;
  this->m_CacheHandles.m_FirstFree = -1;
  this->m_CacheHandles.m_NumElements = 0;
  this->m_CacheHandles.m_LastAlloc.index = -1;
  this->m_CacheHandles.m_pElements = this->m_CacheHandles.m_Elements.m_pMemory;
  this->m_DeadBuffers.m_Memory.m_pMemory = nullptr;
  this->m_DeadBuffers.m_Memory.m_nAllocationCount = 0;
  this->m_DeadBuffers.m_Memory.m_nGrowSize = 0;
  this->m_DeadBuffers.m_Size = 0;
  this->m_DeadBuffers.m_pElements = nullptr;
  this->m_bInitialized = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003B660
// Name: public: unsigned int CUtlHandleTable<struct WaveCache_t,11>::AddHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHandleTable<WaveCache_t,11>::AddHandle(CUtlHandleTable<WaveCache_t,11> *this)
{
  int *m_pMemory; // ecx
  int m_current; // ecx
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v4; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v5; // eax

  if ( this->m_unused.m_heap.m_Size <= 0 )
  {
    m_current = CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
                  this: (CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *)&this->m_list,
                  elem: this->m_list.m_Size);
  }
  else
  {
    m_pMemory = this->m_unused.m_heap.m_Memory.m_pMemory;
    this->m_unused.m_current = *m_pMemory;
    if ( this->m_unused.m_heap.m_Size - 1 > 0 )
      _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: 4 * (this->m_unused.m_heap.m_Size - 1));
    --this->m_unused.m_heap.m_Size;
    m_current = this->m_unused.m_current;
  }
  v4 = this->m_list.m_Memory.m_pMemory;
  *(_DWORD *)&v4[m_current] &= ~0x80000000;
  v5 = &v4[m_current];
  v5->m_pData = nullptr;
  ++this->m_nValidHandles;
  return m_current & 0x7FF | (*(_DWORD *)v5 << 11);
}

//------------------------------------------------------------------------------
// Address: 0x1003B750
// Name: public: CWaveCache::CWaveCache(void)
// Source: json
//------------------------------------------------------------------------------
CWaveCache *__thiscall CWaveCache::CWaveCache(CWaveCache *this)
{
  CUtlHandleTable<WaveCache_t,11> *p_m_HandleTable; // ecx

  this->m_WaveCacheMutex.m_ownerID = 0;
  this->m_WaveCacheMutex.m_depth = 0;
  this->m_HandleTable.m_nValidHandles = 0;
  this->m_HandleTable.m_list.m_Memory.m_pMemory = nullptr;
  this->m_HandleTable.m_list.m_Memory.m_nAllocationCount = 0;
  this->m_HandleTable.m_list.m_Memory.m_nGrowSize = 0;
  this->m_HandleTable.m_list.m_Size = 0;
  this->m_HandleTable.m_list.m_pElements = nullptr;
  p_m_HandleTable = &this->m_HandleTable;
  p_m_HandleTable->m_unused.m_heap.m_Memory.m_pMemory = nullptr;
  p_m_HandleTable->m_unused.m_heap.m_Memory.m_nAllocationCount = 0;
  p_m_HandleTable->m_unused.m_heap.m_Memory.m_nGrowSize = 0;
  p_m_HandleTable->m_unused.m_heap.m_Size = 0;
  p_m_HandleTable->m_unused.m_heap.m_pElements = nullptr;
  this->m_UnlockedList.m_Memory.m_pMemory = nullptr;
  this->m_UnlockedList.m_Memory.m_nAllocationCount = 0;
  this->m_UnlockedList.m_Memory.m_nGrowSize = 0;
  this->m_UnlockedList.m_LastAlloc.index = -1;
  this->m_UnlockedList.m_Head = -1;
  this->m_UnlockedList.m_Tail = -1;
  this->m_UnlockedList.m_FirstFree = -1;
  this->m_UnlockedList.m_ElementCount = 0;
  this->m_UnlockedList.m_NumAlloced = 0;
  this->m_UnlockedList.m_pElements = this->m_UnlockedList.m_Memory.m_pMemory;
  this->m_nCurrentMemorySize = 0;
  this->m_nMaxMemorySize = -1;
  this->m_nAgeStamp = 1;
  CUtlHandleTable<WaveCache_t,11>::AddHandle(this: p_m_HandleTable);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003B7D0
// Name: public: class CAsyncWaveData __near * CWaveCache::CacheLock(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAsyncWaveData *__thiscall CWaveCache::CacheLock(CWaveCache *this, unsigned int hData)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // ebx
  DWORD CurrentThreadId; // eax
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  WaveCache_t *m_pData; // esi
  bool v9; // zf
  CAsyncWaveData *m_pWaveData; // esi
  unsigned __int16 hDataa; // [esp+10h] [ebp+8h]

  if ( hData == 0 )
    return nullptr;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_WaveCacheMutex.m_depth;
  }
  if ( hData != -1
    && (v6 = hData & 0x7FF) < this->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (m_pData = v7->m_pData) != nullptr )
  {
    m_pData->m_nAgeStamp = this->m_nAgeStamp++;
    if ( ++m_pData->m_nLockCount == 1 && m_pData->m_hUnlock != 0xFFFF )
    {
      hDataa = m_pData->m_hUnlock;
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_UnlockedList,
        elem: hDataa);
      this->m_UnlockedList.m_Memory.m_pMemory[hDataa].m_Next = this->m_UnlockedList.m_FirstFree;
      this->m_UnlockedList.m_FirstFree = hDataa;
      m_pData->m_hUnlock = 0xFFFF;
    }
    m_pWaveData = m_pData->m_pWaveData;
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return m_pWaveData;
  }
  else
  {
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B8D0
// Name: public: virtual void CAsyncWavDataCache::MarkBufferDiscarded(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::MarkBufferDiscarded(CAsyncWavDataCache *this, int hBuffer)
{
  CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl*)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int> > *p_m_BufferList; // esi
  int v3; // eax

  p_m_BufferList = &this->m_BufferList;
  if ( hBuffer != -1 )
  {
    CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int>>::Unlink(
      this: &this->m_BufferList,
      elem: hBuffer);
    v3 = hBuffer;
    p_m_BufferList->m_Elements.m_pMemory[v3].m_Left = hBuffer;
    p_m_BufferList->m_Elements.m_pMemory[v3].m_Right = p_m_BufferList->m_FirstFree;
    --p_m_BufferList->m_NumElements;
    p_m_BufferList->m_FirstFree = hBuffer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B9C0
// Name: public: void CUtlQueue<int,class CUtlMemory<int,int>>::Insert(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlQueue<int,CUtlMemory<int,int>>::Insert(
        CUtlQueue<int,CUtlMemory<int,int> > *this,
        const int *element)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  m_Size = this->m_heap.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_heap.m_Size;
  m_pMemory = this->m_heap.m_Memory.m_pMemory;
  v6 = this->m_heap.m_Size - m_Size - 1;
  this->m_heap.m_pElements = this->m_heap.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  this->m_heap.m_Memory.m_pMemory[m_Size] = *element;
}

//------------------------------------------------------------------------------
// Address: 0x1003BA20
// Name: public: int CWaveCache::CacheUnlock(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWaveCache::CacheUnlock(CWaveCache *this, unsigned int hData)
{
  unsigned int result; // eax
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v6; // ecx
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // edx
  WaveCache_t *m_pData; // edi
  bool v9; // zf
  unsigned int m_nLockCount; // eax
  unsigned int v11; // eax

  if ( hData == 0 )
    return 0;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_WaveCacheMutex.m_depth;
  }
  if ( hData != -1
    && (v6 = hData & 0x7FF) < this->m_HandleTable.m_list.m_Size
    && (*(_DWORD *)(v7 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) == hData >> 11
    && (*(_DWORD *)v7 & 0x80000000) != 0x80000000
    && (m_pData = v7->m_pData) != nullptr )
  {
    m_nLockCount = m_pData->m_nLockCount;
    if ( m_nLockCount != 0 )
    {
      v11 = m_nLockCount - 1;
      m_pData->m_nLockCount = v11;
      if ( v11 == 0 )
        m_pData->m_hUnlock = CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AddToTail(
                               this: &this->m_UnlockedList,
                               src: &hData);
    }
    result = m_pData->m_nLockCount;
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
  else
  {
    v9 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB00
// Name: public: void CWaveCache::BreakLock(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveCache::BreakLock(CWaveCache *this, unsigned int hData)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v5; // ecx
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v6; // edx
  WaveCache_t *m_pData; // edi
  bool v8; // zf

  if ( hData != 0 )
  {
    p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_WaveCacheMutex.m_depth;
    }
    if ( hData == -1
      || (v5 = hData & 0x7FF) >= this->m_HandleTable.m_list.m_Size
      || (*(_DWORD *)(v6 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v5]) & 0x7FFFFFFF) != hData >> 11
      || (*(_DWORD *)v6 & 0x80000000) == 0x80000000
      || (m_pData = v6->m_pData) == nullptr )
    {
      v8 = this->m_WaveCacheMutex.m_depth-- == 1;
      if ( !v8 )
        return;
      goto LABEL_16;
    }
    if ( m_pData->m_nLockCount != 0 )
    {
      m_pData->m_nLockCount = 0;
      m_pData->m_hUnlock = CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AddToTail(
                             this: &this->m_UnlockedList,
                             src: &hData);
    }
    v8 = this->m_WaveCacheMutex.m_depth-- == 1;
    if ( v8 )
LABEL_16:
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BBD0
// Name: public: void CUtlHandleTable<struct WaveCache_t,11>::RemoveHandle(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHandleTable<WaveCache_t,11>::RemoveHandle(
        CUtlHandleTable<WaveCache_t,11> *this,
        unsigned int handle)
{
  unsigned int v2; // edi
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v3; // edx
  int v4; // eax

  v2 = handle & 0x7FF;
  if ( v2 < this->m_list.m_Size )
  {
    v3 = &this->m_list.m_Memory.m_pMemory[v2];
    v4 = *(_DWORD *)v3 ^ (*(_DWORD *)v3 ^ (*(_DWORD *)v3 + 1)) & 0x7FFFFFFF;
    *(_DWORD *)v3 = v4;
    if ( v4 >= 0 )
    {
      *(_DWORD *)v3 = v4 | 0x80000000;
      --this->m_nValidHandles;
    }
    v3->m_pData = nullptr;
    if ( (*(_DWORD *)v3 & 0x7FFFFFFFu) < 0xFFFFF )
    {
      handle = v2;
      CUtlQueue<int,CUtlMemory<int,int>>::Insert(this: &this->m_unused, element: (const int *)&handle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BC30
// Name: public: bool CWaveCache::CacheRemove(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWaveCache::CacheRemove(CWaveCache *this, unsigned int hData)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  CUtlHandleTable<WaveCache_t,11> *p_m_HandleTable; // ebx
  unsigned int v6; // eax
  CUtlHandleTable<WaveCache_t,11>::EntryType_t *v7; // ecx
  WaveCache_t *m_pData; // edi
  char *FileName; // eax
  CWaveCache *v10; // ecx
  CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *p_m_UnlockedList; // ebx
  bool v12; // zf
  CUtlHandleTable<WaveCache_t,11> *v13; // [esp+4h] [ebp-8h]
  unsigned __int16 m_hUnlock; // [esp+8h] [ebp-4h]

  if ( hData == 0 )
    return 0;
  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WaveCacheMutex->m_depth;
  }
  p_m_HandleTable = &this->m_HandleTable;
  v13 = &this->m_HandleTable;
  if ( hData == -1
    || (v6 = hData & 0x7FF) >= this->m_HandleTable.m_list.m_Size
    || (*(_DWORD *)(v7 = &this->m_HandleTable.m_list.m_Memory.m_pMemory[v6]) & 0x7FFFFFFF) != hData >> 11
    || (*(_DWORD *)v7 & 0x80000000) == 0x80000000
    || (m_pData = v7->m_pData) == nullptr
    || m_pData->m_nLockCount != 0 )
  {
    v12 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v12 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 0;
  }
  else
  {
    if ( snd_async_stream_purges.m_pParent != nullptr && snd_async_stream_purges.m_pParent->m_Value.m_nValue != 0 )
    {
      FileName = CAsyncWaveData::GetFileName(this: m_pData->m_pWaveData);
      _Msg(a1: "CacheRemove: Age:%d %s\n", m_pData->m_nAgeStamp, FileName);
    }
    CAsyncWaveData::DestroyResource(this: m_pData->m_pWaveData);
    v10 = this;
    this->m_nCurrentMemorySize -= m_pData->m_nDataSize;
    if ( m_pData->m_hUnlock != 0xFFFF )
    {
      p_m_UnlockedList = &this->m_UnlockedList;
      m_hUnlock = m_pData->m_hUnlock;
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        this: &v10->m_UnlockedList,
        elem: m_hUnlock);
      p_m_UnlockedList->m_Memory.m_pMemory[m_hUnlock].m_Next = p_m_UnlockedList->m_FirstFree;
      p_m_UnlockedList->m_FirstFree = m_hUnlock;
      p_m_HandleTable = v13;
    }
    CUtlHandleTable<WaveCache_t,11>::RemoveHandle(this: p_m_HandleTable, handle: hData);
    free(pMem: m_pData);
    v12 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v12 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BEB0
// Name: public: void CWaveCache::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveCache::Flush(CWaveCache *this)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // esi
  DWORD CurrentThreadId; // ecx
  int m_ElementCount; // eax
  int m_Size; // esi
  unsigned int *m_pMemory; // edi
  int m_Head; // eax
  int v8; // ebx
  UtlLinkedListElem_t<unsigned int,unsigned short> *v9; // edx
  int v10; // ecx
  unsigned int *v11; // ecx
  int i; // ebx
  int m_nGrowSize; // esi
  CThreadFastMutex *m_lock; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > purgeList; // [esp+Ch] [ebp-24h] BYREF
  CAutoLockT<CThreadFastMutex> generated_id_26; // [esp+20h] [ebp-10h]
  int v18; // [esp+24h] [ebp-Ch]
  UtlLinkedListElem_t<unsigned int,unsigned short> *v19; // [esp+28h] [ebp-8h]
  CWaveCache *v20; // [esp+2Ch] [ebp-4h]

  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  v20 = this;
  generated_id_26.m_lock = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WaveCacheMutex->m_depth;
  }
  m_ElementCount = this->m_UnlockedList.m_ElementCount;
  m_Size = 0;
  m_pMemory = nullptr;
  purgeList.m_Memory.m_pMemory = nullptr;
  purgeList.m_Memory.m_nAllocationCount = m_ElementCount;
  purgeList.m_Memory.m_nGrowSize = 0;
  if ( m_ElementCount != 0 )
  {
    m_pMemory = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_ElementCount);
    purgeList.m_Memory.m_pMemory = m_pMemory;
  }
  m_Head = this->m_UnlockedList.m_Head;
  purgeList.m_Size = 0;
  for ( purgeList.m_pElements = m_pMemory; m_Head != 0xFFFF; m_Head = v20->m_UnlockedList.m_Memory.m_pMemory[v8].m_Next )
  {
    v8 = (unsigned __int16)m_Head;
    v9 = &v20->m_UnlockedList.m_Memory.m_pMemory[v8];
    v10 = m_Size;
    v19 = v9;
    v18 = m_Size;
    if ( m_Size + 1 > purgeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&purgeList,
        num: m_Size - purgeList.m_Memory.m_nAllocationCount + 1);
      m_Size = purgeList.m_Size;
      m_pMemory = purgeList.m_Memory.m_pMemory;
      v9 = v19;
      v10 = v18;
    }
    purgeList.m_Size = ++m_Size;
    purgeList.m_pElements = m_pMemory;
    if ( m_Size - v10 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
      v9 = v19;
      v10 = v18;
    }
    v11 = &m_pMemory[v10];
    if ( v11 != nullptr )
      *v11 = v9->m_Element;
  }
  for ( i = 0; i < m_Size; ++i )
    CWaveCache::CacheRemove(this: v20, hData: m_pMemory[i]);
  m_nGrowSize = purgeList.m_Memory.m_nGrowSize;
  purgeList.m_Size = 0;
  if ( purgeList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      purgeList.m_Memory.m_pMemory = nullptr;
    }
    purgeList.m_Memory.m_nAllocationCount = 0;
  }
  purgeList.m_pElements = m_pMemory;
  if ( m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      purgeList.m_Memory.m_pMemory = nullptr;
    }
    purgeList.m_Memory.m_nAllocationCount = 0;
  }
  m_lock = generated_id_26.m_lock;
  if ( generated_id_26.m_lock->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)m_lock, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003C050
// Name: public: virtual void CAsyncWavDataCache::CloseStreamedLoad(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::CloseStreamedLoad(CAsyncWavDataCache *this, int hStream)
{
  int v2; // eax
  CAsyncWavDataCache *v3; // edi
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *m_pMemory; // ebx
  CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *p_m_StreamedHandles; // ecx
  int v6; // esi
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v7; // ebx
  unsigned int v8; // esi
  CAsyncWaveData *NoTouch; // eax
  int v10; // eax
  CAsyncWavDataCache::DeadBufferEntry_t *v11; // ecx
  CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int> > *v13; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  unsigned int *m_hWaveData; // [esp+14h] [ebp-4h]

  v2 = hStream;
  v3 = this;
  if ( hStream != -1 )
  {
    m_pMemory = this->m_StreamedHandles.m_Memory.m_pMemory;
    p_m_StreamedHandles = &this->m_StreamedHandles;
    v6 = hStream << 6;
    v7 = &m_pMemory[hStream];
    v13 = &v3->m_StreamedHandles;
    i = 0;
    if ( v7->m_Element.m_numBuffers > 0 )
    {
      m_hWaveData = v7->m_Element.m_hWaveData;
      do
      {
        v8 = *m_hWaveData;
        if ( *m_hWaveData != 0 )
        {
          if ( (int)CWaveCache::GetLockCount(this: &s_WaveCache, hData: *m_hWaveData) <= 1 )
          {
            NoTouch = CWaveCache::CacheGetNoTouch(this: &s_WaveCache, hData: v8);
            if ( NoTouch == nullptr || (*((_BYTE *)NoTouch + 84) & 3) != 0 )
            {
              CWaveCache::CacheUnlock(this: &s_WaveCache, hData: v8);
              if ( v7->m_Element.m_bSinglePlay )
                CWaveCache::CacheRemove(this: &s_WaveCache, hData: v8);
            }
            else
            {
              v10 = CUtlVector<CAsyncWavDataCache::DeadBufferEntry_t,CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>>::AddToTail(this: &v3->m_DeadBuffers);
              v3->m_DeadBuffers.m_Memory.m_pMemory[v10].hWaveData = v8;
              v11 = v3->m_DeadBuffers.m_Memory.m_pMemory;
              v3 = this;
              v11[v10].bSinglePlay = v7->m_Element.m_bSinglePlay;
            }
          }
          else
          {
            CWaveCache::CacheUnlock(this: &s_WaveCache, hData: v8);
          }
        }
        ++m_hWaveData;
        ++i;
      }
      while ( i < v7->m_Element.m_numBuffers );
      v6 = hStream << 6;
      v2 = hStream;
      p_m_StreamedHandles = v13;
    }
    CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::Unlink(
      this: p_m_StreamedHandles,
      elem: v2);
    *(int *)((char *)&v13->m_Memory.m_pMemory->m_Next + v6) = v13->m_FirstFree;
    v13->m_FirstFree = hStream;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C140
// Name: public: virtual void CAsyncWavDataCache::Flush(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::Flush(CAsyncWavDataCache *this, bool bTearDownStaticPool)
{
  if ( this->m_bInitialized )
  {
    CWaveCache::Flush(this: &s_WaveCache);
    CAsyncWavDataCache::SpewMemoryUsage(this, level: SPEW_BASIC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C170
// Name: private: void CAsyncWavDataCache::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::Clear(CAsyncWavDataCache *this)
{
  CAsyncWavDataCache *v1; // edi
  int i; // eax
  int v3; // esi
  int j; // eax
  int v5; // eax
  char *v6; // edi
  int v7; // ebx
  unsigned int *v8; // esi
  int k; // esi
  int v10; // [esp+Ch] [ebp-8h]

  v1 = this;
  for ( i = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::FirstInorder(this: &this->m_CacheHandles);
        ;
        i = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::NextInorder(
              this: &v1->m_CacheHandles,
              i: v3) )
  {
    v3 = i;
    if ( i < 0 || i >= v1->m_CacheHandles.m_Elements.m_nAllocationCount || i > v1->m_CacheHandles.m_LastAlloc.index )
      break;
    if ( (`CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_104BF0AC = -1;
      dword_104BF0B0 = -1;
      dword_104BF0B4 = 1;
    }
    if ( v1->m_CacheHandles.m_Elements.m_pMemory[i].m_Left == i )
      break;
    CWaveCache::CacheRemove(this: &s_WaveCache, hData: v1->m_CacheHandles.m_Elements.m_pMemory[i].m_Data.handle);
  }
  CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::RemoveAll(this: &v1->m_CacheHandles);
  for ( j = v1->m_StreamedHandles.m_Head; j != -1; v1 = this )
  {
    v5 = j << 6;
    v6 = (char *)v1->m_StreamedHandles.m_Memory.m_pMemory + v5;
    v7 = 0;
    v10 = v5;
    if ( *((int *)v6 + 11) > 0 )
    {
      v8 = (unsigned int *)(v6 + 4);
      do
      {
        CWaveCache::BreakLock(this: &s_WaveCache, hData: *v8);
        CWaveCache::CacheRemove(this: &s_WaveCache, hData: *v8);
        ++v7;
        ++v8;
      }
      while ( v7 < *((_DWORD *)v6 + 11) );
      v5 = v10;
    }
    j = *(int *)((char *)&this->m_StreamedHandles.m_Memory.m_pMemory->m_Next + v5);
  }
  CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::RemoveAll(this: &v1->m_StreamedHandles);
  for ( k = 0; k < v1->m_DeadBuffers.m_Size; ++k )
  {
    CWaveCache::BreakLock(this: &s_WaveCache, hData: v1->m_DeadBuffers.m_Memory.m_pMemory[k].hWaveData);
    CWaveCache::CacheRemove(this: &s_WaveCache, hData: v1->m_DeadBuffers.m_Memory.m_pMemory[k].hWaveData);
  }
  v1->m_DeadBuffers.m_Size = 0;
  if ( v1->m_DeadBuffers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_DeadBuffers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_DeadBuffers.m_Memory.m_pMemory);
      v1->m_DeadBuffers.m_Memory.m_pMemory = nullptr;
    }
    v1->m_DeadBuffers.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_DeadBuffers.m_pElements = v1->m_DeadBuffers.m_Memory.m_pMemory;
  CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int>>::RemoveAll(this: &v1->m_BufferList);
}

//------------------------------------------------------------------------------
// Address: 0x1003C2F0
// Name: snd_async_flush
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_async_flush()
{
  if ( g_AsyncWaveDataCache.m_bInitialized )
  {
    CWaveCache::Flush(this: &s_WaveCache);
    CAsyncWavDataCache::SpewMemoryUsage(this: &g_AsyncWaveDataCache, level: SPEW_BASIC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C310
// Name: public: unsigned int CWaveCache::CacheCreate(struct asyncwaveparams_t,enum WaveCacheAddFlags_t)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWaveCache::CacheCreate(CWaveCache *this, asyncwaveparams_t params, WaveCacheAddFlags_t flags)
{
  CThreadFastMutex *p_m_WaveCacheMutex; // edi
  DWORD CurrentThreadId; // ecx
  unsigned int m_nMaxMemorySize; // eax
  int v7; // ebx
  bool v8; // zf
  unsigned int result; // eax
  CAsyncWaveData *v10; // ebx
  CAsyncWaveData **v11; // edi
  CUtlHandleTable<WaveCache_t,11> *p_m_HandleTable; // ebx
  CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *p_m_UnlockedList; // ebx
  unsigned __int16 v14; // ax
  int v15; // esi
  unsigned __int16 v16; // ax
  UtlLinkedListElem_t<unsigned int,unsigned short> *v17; // eax
  unsigned int v18; // ecx
  int *v19; // ecx
  CThreadFastMutex *generated_id_19; // [esp+Ch] [ebp-Ch]
  CUtlHandleTable<WaveCache_t,11> *v21; // [esp+10h] [ebp-8h]
  unsigned int hData; // [esp+14h] [ebp-4h]

  p_m_WaveCacheMutex = &this->m_WaveCacheMutex;
  generated_id_19 = &this->m_WaveCacheMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WaveCacheMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WaveCacheMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WaveCacheMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WaveCacheMutex->m_depth;
  }
  m_nMaxMemorySize = this->m_nMaxMemorySize;
  if ( (m_nMaxMemorySize == -1
     || (v7 = params.datasize + 88, params.datasize + 88 + this->m_nCurrentMemorySize <= m_nMaxMemorySize)
     || (CWaveCache::Purge(this, nBytesToPurge: params.datasize + 88),
         v7 + this->m_nCurrentMemorySize <= this->m_nMaxMemorySize))
    && (v10 = CAsyncWaveData::CreateResource(&params)) != nullptr )
  {
    v11 = (CAsyncWaveData **)MemAlloc_Alloc(nSize: 0x14u);
    *v11 = v10;
    v11[1] = (CAsyncWaveData *)(v10->m_nDataSize + 88);
    v11[2] = (CAsyncWaveData *)this->m_nAgeStamp++;
    this->m_nCurrentMemorySize += (unsigned int)v11[1];
    p_m_HandleTable = &this->m_HandleTable;
    v21 = &this->m_HandleTable;
    result = CUtlHandleTable<WaveCache_t,11>::AddHandle(this: &this->m_HandleTable);
    hData = result;
    if ( (flags & 1) != 0 )
    {
      v11[3] = (CAsyncWaveData *)1;
      v11[4] = (CAsyncWaveData *)0xFFFF;
    }
    else
    {
      p_m_UnlockedList = &this->m_UnlockedList;
      v11[3] = nullptr;
      v14 = CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short>>::AllocInternal(
              this: &this->m_UnlockedList,
              multilist: false);
      v15 = v14;
      if ( v14 == 0xFFFF )
      {
        v16 = -1;
      }
      else
      {
        CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
          this: p_m_UnlockedList,
          before: 0xFFFFu,
          elem: v14);
        v17 = &p_m_UnlockedList->m_Memory.m_pMemory[v15];
        if ( v17 != nullptr )
          v17->m_Element = hData;
        v16 = v15;
      }
      p_m_HandleTable = v21;
      v11[4] = (CAsyncWaveData *)v16;
      result = hData;
    }
    if ( result != -1 )
    {
      v18 = result & 0x7FF;
      if ( v18 < p_m_HandleTable->m_list.m_Size )
      {
        v19 = (int *)&p_m_HandleTable->m_list.m_Memory.m_pMemory[v18];
        if ( (*v19 & 0x7FFFFFFF) == result >> 11 )
        {
          if ( *v19 < 0 )
          {
            ++p_m_HandleTable->m_nValidHandles;
            *v19 &= ~0x80000000;
          }
          v19[1] = (int)v11;
        }
      }
    }
    v8 = generated_id_19->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)generated_id_19, 0);
  }
  else
  {
    v8 = p_m_WaveCacheMutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_WaveCacheMutex, 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003C490
// Name: public: virtual void CAsyncWavDataCache::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::Shutdown(CAsyncWavDataCache *this)
{
  CUtlMemoryPool *v2; // edi

  if ( this->m_bInitialized )
  {
    CAsyncWavDataCache::Clear(this);
    v2 = g_pAudioStreamPool;
    if ( g_pAudioStreamPool != nullptr )
    {
      CUtlMemoryPool::~CUtlMemoryPool(this: g_pAudioStreamPool);
      free(pMem: v2);
    }
    this->m_bInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C4D0
// Name: public: virtual unsigned int CAsyncWavDataCache::AsyncLoadCache(char const __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAsyncWavDataCache::AsyncLoadCache(
        CAsyncWavDataCache *this,
        const char *filename,
        unsigned int datasize,
        unsigned int startpos,
        bool bIsPrefetch)
{
  void *v6; // edi
  int v7; // eax
  UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int> *m_pMemory; // ecx
  int v9; // eax
  int p_m_Data; // esi
  asyncwaveparams_t v12; // [esp-18h] [ebp-40h]
  unsigned int params_12; // [esp+18h] [ebp-10h]
  int params_16; // [esp+1Ch] [ebp-Ch]
  CAsyncWavDataCache::CacheEntry_t search; // [esp+20h] [ebp-8h] BYREF

  v6 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: filename);
  search.name = v6;
  search.handle = 0;
  v7 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Find(
         this: &this->m_CacheHandles,
         &search);
  if ( v7 == -1 )
    v7 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Insert(
           this: &this->m_CacheHandles,
           insert: &search);
  m_pMemory = this->m_CacheHandles.m_Elements.m_pMemory;
  v9 = v7;
  p_m_Data = (int)&m_pMemory[v9].m_Data;
  if ( CWaveCache::CacheGet(this: &s_WaveCache, hData: m_pMemory[v9].m_Data.handle) == nullptr )
  {
    *(_QWORD *)&v12.hFilename = __PAIR64__(datasize, (unsigned int)v6);
    *(_QWORD *)&v12.seekpos = __PAIR64__(params_12, startpos);
    *((_DWORD *)&v12 + 4) = (params_16 & 0xF0 ^ bIsPrefetch) & 1 ^ params_16 & 0xFFFFFFF0;
    *(_DWORD *)(p_m_Data + 4) = CWaveCache::CacheCreate(this: &s_WaveCache, params: v12, flags: WCAF_DEFAULT);
  }
  return *(_DWORD *)(p_m_Data + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1003C580
// Name: private: unsigned int CAsyncWavDataCache::FindOrCreateBuffer(struct asyncwaveparams_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAsyncWavDataCache::FindOrCreateBuffer(
        CAsyncWavDataCache *this,
        asyncwaveparams_t *params,
        bool bFind)
{
  int seekpos; // ecx
  int v5; // eax
  int v6; // ecx
  CAsyncWaveData *v7; // edi
  int v8; // esi
  double v10; // st7
  char tempBuff[260]; // [esp+Ch] [ebp-114h] BYREF
  CAsyncWavDataCache::BufferEntry_t search; // [esp+110h] [ebp-10h] BYREF

  seekpos = params->seekpos;
  search.m_hName = params->hFilename;
  search.m_StartPos = seekpos;
  *((_DWORD *)&search + 3) = *((_DWORD *)&search + 3) & 0xFFFFFFFC | ((*((_DWORD *)params + 4) & 4) != 0) | (2 * bFind);
  search.m_hWaveData = 0;
  if ( bFind )
  {
    v5 = CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int>>::Find(
           this: &this->m_BufferList,
           &search);
    if ( v5 != -1 )
    {
      search.m_hWaveData = this->m_BufferList.m_Elements.m_pMemory[v5].m_Data.m_hWaveData;
      if ( snd_async_stream_spew.m_pParent != nullptr && snd_async_stream_spew.m_pParent->m_Value.m_nValue >= 2 )
      {
        g_pFileSystem->String(this: g_pFileSystem, a2: (void *const *)params, a3: tempBuff, a4: 260);
        _Msg(a1: "Found Buffer: %s, offset: %d\n", tempBuff, params->seekpos);
      }
    }
  }
  v7 = CWaveCache::CacheLock(this: &s_WaveCache, hData: search.m_hWaveData);
  if ( v7 != nullptr )
  {
    v10 = _Plat_FloatTime(a1: v6);
    v7->m_arrival = v10;
    v7->m_start = v10;
    return search.m_hWaveData;
  }
  else
  {
    search.m_hWaveData = CWaveCache::CacheCreate(this: &s_WaveCache, params: *params, flags: WCAF_LOCK);
    if ( search.m_hWaveData != 0 )
    {
LABEL_11:
      v8 = CUtlRBTree<CAsyncWavDataCache::BufferEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::BufferEntry_t const &,CAsyncWavDataCache::BufferEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::BufferEntry_t,int>,int>>::Insert(
             this: &this->m_BufferList,
             insert: &search);
      CWaveCache::CacheGet(this: &s_WaveCache, hData: search.m_hWaveData)->m_hBuffer = v8;
      return search.m_hWaveData;
    }
    else
    {
      while ( (*((_BYTE *)params + 16) & 4) != 0 )
      {
        v7 = (CAsyncWaveData *)((char *)v7 + 1);
        if ( (int)v7 >= 2 )
        {
          if ( snd_async_stream_fail.m_pParent != nullptr && snd_async_stream_fail.m_pParent->m_Value.m_nValue != 0 )
            _Warning(a1: "Stream pool: No buffers available! (dead:%d)\n", this->m_DeadBuffers.m_Size);
          return 0;
        }
        CWaveCache::Purge(this: &s_WaveCache, nBytesToPurge: 0x10000u);
        search.m_hWaveData = CWaveCache::CacheCreate(this: &s_WaveCache, params: *params, flags: WCAF_LOCK);
        if ( search.m_hWaveData != 0 )
          goto LABEL_11;
      }
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C750
// Name: public: virtual int CAsyncWavDataCache::OpenStreamedLoad(char const __near *,int,int,int,int,int,int,unsigned int,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncWavDataCache::OpenStreamedLoad(
        CAsyncWavDataCache *this,
        const char *pFileName,
        int dataSize,
        int dataStart,
        int startPos,
        int loopPos,
        int bufferSize,
        int numBuffers,
        unsigned int flags,
        SoundError *soundError)
{
  unsigned int v10; // ebx
  int v11; // edi
  void *v12; // esi
  int v13; // esi
  int v14; // ebx
  unsigned int v15; // eax
  CAsyncWavDataCache *v16; // edi
  int v17; // eax
  int v18; // ebx
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *m_pMemory; // eax
  int v20; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v22; // eax
  CAsyncWavDataCache::StreamedEntry_t *v23; // eax
  CAsyncWavDataCache::StreamedEntry_t streamedEntry; // [esp+8h] [ebp-50h]
  asyncwaveparams_t params; // [esp+40h] [ebp-18h] BYREF
  CAsyncWavDataCache *v27; // [esp+54h] [ebp-4h]
  bool bFailed_3; // [esp+77h] [ebp+1Fh]
  bool bFindBuffer; // [esp+7Ch] [ebp+24h]

  *((_DWORD *)&params + 4) &= 0xFFFFFFF0;
  v10 = flags;
  v27 = this;
  if ( (flags & 4) != 0 )
  {
    if ( numBuffers != 1 )
      numBuffers = 1;
    if ( (flags & 8) != 0 )
      v10 = flags & 0xFFFFFFF7;
  }
  v11 = bufferSize;
  if ( (v10 & 8) != 0 && bufferSize != 0x10000 )
    v11 = 0x10000;
  if ( (v10 & 8) == 0 && (v10 & 2) != 0 )
    v10 &= ~2u;
  v12 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: pFileName);
  streamedEntry.m_DataSize = dataSize;
  streamedEntry.m_DataStart = dataStart;
  streamedEntry.m_numBuffers = numBuffers;
  streamedEntry.m_LoopStart = loopPos;
  streamedEntry.m_NextStartPos = startPos + numBuffers * v11;
  streamedEntry.m_hName = v12;
  streamedEntry.m_Front = 0;
  streamedEntry.m_BufferSize = v11;
  streamedEntry.m_bSinglePlay = (v10 & 2) != 0;
  streamedEntry.m_SectorSize = 1;
  streamedEntry.m_bIsTransient = false;
  bFindBuffer = (v10 & 0xC) != 0 && (v10 & 2) == 0;
  params.alignment = 1;
  params.hFilename = v12;
  v13 = 0;
  params.datasize = v11;
  *((_DWORD *)&params + 4) = *((_DWORD *)&params + 4) & 0xFFFFFFF1 | (v10 >> 1) & 2 | (2 * (v10 & 4));
  bFailed_3 = false;
  if ( numBuffers > 0 )
  {
    v14 = startPos;
    do
    {
      params.seekpos = dataStart + streamedEntry.m_SectorSize * (v14 / streamedEntry.m_SectorSize);
      v15 = 0;
      if ( !bFailed_3 )
      {
        v15 = CAsyncWavDataCache::FindOrCreateBuffer(this: v27, &params, bFind: bFindBuffer);
        bFailed_3 = v15 == 0;
      }
      streamedEntry.m_hWaveData[v13++] = v15;
      v14 += v11;
    }
    while ( v13 < numBuffers );
  }
  v16 = v27;
  v17 = CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::AllocInternal(
          this: &v27->m_StreamedHandles,
          multilist: false);
  v18 = v17;
  if ( v17 == -1 )
  {
    v18 = -1;
  }
  else
  {
    CUtlLinkedList<CAsyncWavDataCache::StreamedEntry_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int>,int>>::Unlink(
      this: &v16->m_StreamedHandles,
      elem: v17);
    m_pMemory = v16->m_StreamedHandles.m_Memory.m_pMemory;
    v20 = v18 << 6;
    *(int *)((char *)&m_pMemory->m_Next + v20) = -1;
    m_Tail = v16->m_StreamedHandles.m_Tail;
    *(int *)((char *)&m_pMemory->m_Previous + v20) = m_Tail;
    v16->m_StreamedHandles.m_Tail = v18;
    if ( m_Tail == -1 )
      v16->m_StreamedHandles.m_Head = v18;
    else
      v16->m_StreamedHandles.m_Memory.m_pMemory[m_Tail].m_Next = v18;
    v22 = v16->m_StreamedHandles.m_Memory.m_pMemory;
    ++v16->m_StreamedHandles.m_ElementCount;
    v23 = (CAsyncWavDataCache::StreamedEntry_t *)((char *)&v22->m_Element + v20);
    if ( v23 != nullptr )
    {
      *v23 = streamedEntry;
      v16 = v27;
    }
  }
  if ( bFailed_3 )
  {
    v16->CloseStreamedLoad(this: v16, a2: v18);
    *soundError = SE_NO_STREAM_BUFFER;
    return -1;
  }
  else
  {
    *soundError = SE_OK;
    return v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C920
// Name: public: virtual bool CAsyncWavDataCache::CopyDataIntoMemory(unsigned int __near &,char const __near *,int,int,void __near *,int,int,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncWavDataCache::CopyDataIntoMemory(
        CAsyncWavDataCache *this,
        unsigned int *handle,
        const char *filename,
        unsigned int datasize,
        int startpos,
        void *buffer,
        int bufsize,
        int copystartpos,
        int bytestocopy,
        bool *pbPostProcessed)
{
  unsigned int *v10; // edi
  char v11; // bl
  CAsyncWaveData *v12; // esi
  void *v13; // ebx
  int v14; // esi
  unsigned int v16; // eax
  asyncwaveparams_t v17; // [esp-18h] [ebp-48h]
  unsigned int v18; // [esp-4h] [ebp-34h]
  __int64 params_12; // [esp+18h] [ebp-18h]
  CAsyncWavDataCache::CacheEntry_t search; // [esp+20h] [ebp-10h] BYREF
  CAsyncWavDataCache *v21; // [esp+28h] [ebp-8h]
  bool bret; // [esp+2Fh] [ebp-1h]

  v10 = handle;
  v21 = this;
  *pbPostProcessed = false;
  v18 = *handle;
  v11 = 0;
  bret = false;
  v12 = CWaveCache::CacheLock(this: &s_WaveCache, hData: v18);
  if ( v12 == nullptr )
  {
    v13 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: filename);
    search.name = v13;
    search.handle = 0;
    v14 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Find(
            this: &v21->m_CacheHandles,
            &search);
    if ( v14 == -1 )
      return 0;
    *(_QWORD *)&v17.hFilename = __PAIR64__(datasize, (unsigned int)v13);
    v17.seekpos = startpos;
    *(_QWORD *)&v17.alignment = params_12 & 0xFFFFFFF0FFFFFFFFuLL;
    v16 = CWaveCache::CacheCreate(this: &s_WaveCache, params: v17, flags: WCAF_DEFAULT);
    v10 = handle;
    v21->m_CacheHandles.m_Elements.m_pMemory[v14].m_Data.handle = v16;
    *handle = v16;
    v12 = CWaveCache::CacheLock(this: &s_WaveCache, hData: v16);
    if ( v12 == nullptr )
      return 0;
    v11 = bret;
  }
  if ( v12->m_nDataSize != 0 )
    v11 = CAsyncWaveData::BlockingCopyData(
            this: v12,
            destbuffer: buffer,
            destbufsize: bufsize,
            startoffset: copystartpos,
            count: bytestocopy);
  *pbPostProcessed = (*((_DWORD *)v12 + 21) & 4) != 0;
  CWaveCache::CacheUnlock(this: &s_WaveCache, hData: *v10);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1003CA30
// Name: private: void CAsyncWavDataCache::PrefetchNextBuffers(struct CAsyncWavDataCache::StreamedEntry_t __near &,struct CAsyncWavDataCache::StreamData_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncWavDataCache::PrefetchNextBuffers(
        CAsyncWavDataCache *this,
        CAsyncWavDataCache::StreamedEntry_t *streamedEntry,
        CAsyncWavDataCache::StreamData_t *streamData)
{
  bool v3; // cc
  CAsyncWavDataCache::StreamData_t *v4; // edi
  int m_LoopStart; // eax
  int m_DataSize; // edi
  void *m_hName; // ebx
  int v8; // eax
  unsigned int v9; // edx
  int m_BufferSize; // ecx
  int v11; // edi
  int v12; // edx
  bool v13; // zf
  int v14; // ebx
  unsigned int v15; // eax
  asyncwaveparams_t params; // [esp+4h] [ebp-18h] BYREF
  CAsyncWavDataCache *v17; // [esp+18h] [ebp-4h]

  v3 = streamedEntry->m_numBuffers <= 1;
  v17 = this;
  if ( !v3 )
  {
    v4 = streamData;
    if ( streamedEntry->m_Front < streamData->index )
    {
      while ( 1 )
      {
        m_LoopStart = v4->actualCopied != 0 || v4->bWaiting
                    ? streamedEntry->m_NextStartPos
                    : v4->copyStartPos - streamedEntry->m_DataStart;
        m_DataSize = streamedEntry->m_DataSize;
        if ( m_LoopStart >= m_DataSize )
        {
          m_LoopStart = streamedEntry->m_LoopStart;
          if ( m_LoopStart < 0 )
            break;
        }
        m_hName = streamedEntry->m_hName;
        params.alignment = streamedEntry->m_SectorSize;
        params.hFilename = m_hName;
        v8 = params.alignment * (m_LoopStart / params.alignment);
        v9 = (*((_BYTE *)&params + 16)
            & 0xF0
            ^ (unsigned __int8)(4 * streamedEntry->m_bIsTransient))
           & 4
           ^ *((_DWORD *)&params + 4)
           & 0xFFFFFFF0;
        m_BufferSize = streamedEntry->m_BufferSize;
        v11 = m_DataSize - v8;
        params.seekpos = v8 + streamedEntry->m_DataStart;
        params.datasize = v11;
        *((_DWORD *)&params + 4) = v9;
        if ( v11 > m_BufferSize )
        {
          v11 = m_BufferSize;
          params.datasize = m_BufferSize;
        }
        v12 = streamedEntry->m_Front % streamedEntry->m_numBuffers;
        v13 = !streamedEntry->m_bSinglePlay;
        streamedEntry->m_NextStartPos = v8 + v11;
        v14 = v12;
        if ( v13 )
        {
          CWaveCache::CacheUnlock(this: &s_WaveCache, hData: streamedEntry->m_hWaveData[v12]);
          v15 = CAsyncWavDataCache::FindOrCreateBuffer(this: v17, &params, bFind: true);
          streamedEntry->m_hWaveData[v14] = v15;
          if ( v15 == 0 )
            return;
          v4 = streamData;
        }
        else
        {
          v4 = streamData;
          CAsyncWaveData::StartAsyncLoading(this: streamData->pWaveData[v12], &params);
        }
        v4->bWaiting = true;
        ++streamedEntry->m_Front;
        v4->copyStartPos += streamedEntry->m_BufferSize;
        if ( streamedEntry->m_Front >= v4->index )
          return;
      }
      ++streamedEntry->m_Front;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CB40
// Name: public: virtual int CAsyncWavDataCache::CopyStreamedDataIntoMemory(int,void __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncWavDataCache::CopyStreamedDataIntoMemory(
        CAsyncWavDataCache *this,
        int hStream,
        char *pBuffer,
        int bufferSize,
        int copyStartPos,
        int bytesToCopy)
{
  UtlLinkedListElem_t<CAsyncWavDataCache::StreamedEntry_t,int> *v7; // esi
  CAsyncWavDataCache::StreamData_t streamData; // [esp+Ch] [ebp-20h] BYREF

  v7 = &this->m_StreamedHandles.m_Memory.m_pMemory[hStream];
  if ( copyStartPos >= v7->m_Element.m_DataSize + v7->m_Element.m_DataStart
    || CAsyncWavDataCache::InitializeStreamData(this, streamedEntry: &v7->m_Element, &streamData, copyStartPos) == 0 )
  {
    return 0;
  }
  CAsyncWavDataCache::CopyFromCurrentBuffers(
    this,
    streamedEntry: &v7->m_Element,
    &streamData,
    hStream,
    pBuffer,
    bufferSize,
    bytesToCopy);
  CAsyncWavDataCache::PrefetchNextBuffers(this, streamedEntry: &v7->m_Element, &streamData);
  return streamData.actualCopied;
}

//------------------------------------------------------------------------------
// Address: 0x1003CBB0
// Name: public: virtual bool CAsyncWavDataCache::GetDataPointer(unsigned int __near &,char const __near *,int,int,void __near * __near *,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncWavDataCache::GetDataPointer(
        CAsyncWavDataCache *this,
        unsigned int *handle,
        const char *filename,
        unsigned int datasize,
        int startpos,
        void **pData,
        int copystartpos,
        bool *pbPostProcessed)
{
  unsigned int *v8; // ebx
  CAsyncWaveData *v10; // esi
  void *v11; // ebx
  int v12; // esi
  unsigned int v14; // eax
  asyncwaveparams_t v15; // [esp-18h] [ebp-44h]
  unsigned int v16; // [esp-4h] [ebp-30h]
  __int64 params_12; // [esp+18h] [ebp-14h]
  CAsyncWavDataCache::CacheEntry_t search; // [esp+20h] [ebp-Ch] BYREF
  bool bret; // [esp+2Bh] [ebp-1h]

  v8 = handle;
  *pbPostProcessed = false;
  *pData = nullptr;
  v16 = *handle;
  bret = false;
  v10 = CWaveCache::CacheLock(this: &s_WaveCache, hData: v16);
  if ( v10 == nullptr )
  {
    v11 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: filename);
    search.name = v11;
    search.handle = 0;
    v12 = CUtlRBTree<CAsyncWavDataCache::CacheEntry_t,int,bool (__cdecl *)(CAsyncWavDataCache::CacheEntry_t const &,CAsyncWavDataCache::CacheEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CAsyncWavDataCache::CacheEntry_t,int>,int>>::Find(
            this: &this->m_CacheHandles,
            &search);
    if ( v12 == -1 )
      return false;
    *(_QWORD *)&v15.hFilename = __PAIR64__(datasize, (unsigned int)v11);
    v15.seekpos = startpos;
    *(_QWORD *)&v15.alignment = params_12 & 0xFFFFFFF0FFFFFFFFuLL;
    v14 = CWaveCache::CacheCreate(this: &s_WaveCache, params: v15, flags: WCAF_DEFAULT);
    v8 = handle;
    this->m_CacheHandles.m_Elements.m_pMemory[v12].m_Data.handle = v14;
    *handle = v14;
    v10 = CWaveCache::CacheLock(this: &s_WaveCache, hData: v14);
    if ( v10 == nullptr )
      return false;
  }
  if ( v10->m_nDataSize != 0
    && copystartpos < v10->m_nDataSize
    && CAsyncWaveData::BlockingGetDataPointer(this: v10, ppData: pData) != 0 )
  {
    *pData = (char *)*pData + copystartpos;
    bret = true;
  }
  *pbPostProcessed = (*((_DWORD *)v10 + 21) & 4) != 0;
  CWaveCache::CacheUnlock(this: &s_WaveCache, hData: *v8);
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x10222700
// Name: public: virtual class CAudioSource __near & CWaveDataStreamAsync::Source(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveDataStreamAsync::Source(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x102E7E30
// Name: public: void CUtlMemory<struct CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
        CUtlMemory<ResourceEntryInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ResourceEntryInfo *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10222730
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace engine_xlsp
