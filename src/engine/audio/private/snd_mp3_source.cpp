// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_mp3_source.cpp
// Functions: 33
// ============================================================

#include "engine\audio\private\snd_mp3_source.h"

//------------------------------------------------------------------------------
// Address: 0x10035550
// Name: public: virtual void CAudioSourceMP3::ReferenceAdd(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::ReferenceAdd(CAudioSourceMP3 *this, CAudioMixer *__formal)
{
  ++this->m_refCount;
}

//------------------------------------------------------------------------------
// Address: 0x10035560
// Name: public: virtual void CAudioSourceMP3::ReferenceRemove(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::ReferenceRemove(CAudioSourceMP3 *this, CAudioMixer *__formal)
{
  if ( this->m_refCount-- == 1 && this->IsPlayOnce(this) )
  {
    this->SetPlayOnce(this, a2: false);
    this->CacheUnload(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035590
// Name: public: virtual bool CAudioSourceMP3::CanDelete(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceMP3::CanDelete(CAudioSourceMP3 *this)
{
  return this->m_refCount <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x100355A0
// Name: public: virtual char const __near * CAudioSourceMP3::GetFileName(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAudioSourceMP3::GetFileName(CAudioSourceMP3 *this, char *pOutBuf, unsigned int bufLen)
{
  CSfxTable *m_pSfx; // ecx

  m_pSfx = this->m_pSfx;
  if ( m_pSfx != nullptr )
    return CSfxTable::GetFileName(this: m_pSfx, pOutBuf, bufLen);
  else
    return "NULL m_pSfx";
}

//------------------------------------------------------------------------------
// Address: 0x100355C0
// Name: public: virtual int CAudioSourceMP3Cache::GetCacheStatus(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceMP3Cache::GetCacheStatus(CAudioSourceMP3Cache *this)
{
  BOOL v2; // ebx
  CSfxTable *m_pSfx; // ecx
  const char *FileName; // eax
  int m_dataSize; // [esp-8h] [ebp-120h]
  int m_dataStart; // [esp-4h] [ebp-11Ch]
  char nameBuf[260]; // [esp+Ch] [ebp-10Ch] BYREF
  IAsyncWavDataCache_vtbl *v9; // [esp+110h] [ebp-8h]
  bool bCacheValid; // [esp+117h] [ebp-1h] BYREF

  v2 = wavedatacache->IsDataLoadCompleted(this: wavedatacache, a2: this->m_hCache, a3: &bCacheValid, a4: nullptr);
  if ( !bCacheValid )
  {
    m_dataStart = this->m_dataStart;
    m_dataSize = this->m_dataSize;
    m_pSfx = this->m_pSfx;
    v9 = wavedatacache->__vftable;
    FileName = CSfxTable::GetFileName(this: m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    v9->RestartDataLoad(this: wavedatacache, a2: &this->m_hCache, a3: FileName, a4: m_dataSize, a5: m_dataStart);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10035640
// Name: public: virtual void CAudioSourceMP3Cache::CacheLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3Cache::CacheLoad(CAudioSourceMP3Cache *this)
{
  IAsyncWavDataCache_vtbl *v2; // edi
  const char *FileName; // eax
  int m_dataSize; // [esp-10h] [ebp-118h]
  int m_dataStart; // [esp-Ch] [ebp-114h]
  char nameBuf[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_hCache != 0 )
  {
    this->GetCacheStatus(this);
  }
  else
  {
    v2 = wavedatacache->__vftable;
    m_dataStart = this->m_dataStart;
    m_dataSize = this->m_dataSize;
    FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    this->m_hCache = v2->AsyncLoadCache(this: wavedatacache, a2: FileName, a3: m_dataSize, a4: m_dataStart, a5: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100356A0
// Name: public: virtual void CAudioSourceMP3Cache::CacheUnload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3Cache::CacheUnload(CAudioSourceMP3Cache *this)
{
  unsigned int m_hCache; // eax

  m_hCache = this->m_hCache;
  if ( m_hCache != 0 )
    wavedatacache->Unload(this: wavedatacache, a2: m_hCache);
}

//------------------------------------------------------------------------------
// Address: 0x100356C0
// Name: protected: virtual char __near * CAudioSourceMP3Cache::GetDataPointer(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAudioSourceMP3Cache::GetDataPointer(CAudioSourceMP3Cache *this)
{
  bool v2; // zf
  unsigned int *p_m_hCache; // edi
  IAsyncWavDataCache_vtbl *v4; // ebx
  const char *FileName; // eax
  int m_dataSize; // [esp-14h] [ebp-12Ch]
  int m_dataStart; // [esp-10h] [ebp-128h]
  char nameBuf[260]; // [esp+Ch] [ebp-10Ch] BYREF
  char *pMP3Data; // [esp+110h] [ebp-8h] BYREF
  bool dummy; // [esp+117h] [ebp-1h] BYREF

  v2 = this->m_hCache == 0;
  p_m_hCache = &this->m_hCache;
  pMP3Data = nullptr;
  dummy = false;
  if ( v2 )
    this->CacheLoad(this);
  v4 = wavedatacache->__vftable;
  m_dataStart = this->m_dataStart;
  m_dataSize = this->m_dataSize;
  FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  v4->GetDataPointer(
    this: wavedatacache,
    a2: p_m_hCache,
    a3: FileName,
    a4: m_dataSize,
    a5: m_dataStart,
    a6: (void **)&pMP3Data,
    a7: 0,
    a8: &dummy);
  return pMP3Data;
}

//------------------------------------------------------------------------------
// Address: 0x10035730
// Name: public: virtual class CAudioMixer __near * CAudioSourceMP3Cache::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CAudioSourceMP3Cache::CreateMixer(
        CAudioSourceMP3Cache *this,
        int initialStreamPosition,
        int skipInitialSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  IWaveData *WaveDataMemory; // eax
  CAudioMixer *result; // eax
  CAudioMixer *v8; // edi
  int *p_m_sampleRate; // [esp-4h] [ebp-Ch]

  p_m_sampleRate = &this->m_sampleRate;
  WaveDataMemory = CreateWaveDataMemory(source: this);
  result = CreateMP3Mixer(data: WaveDataMemory, pSampleRate: p_m_sampleRate);
  v8 = result;
  if ( result != nullptr )
  {
    this->ReferenceAdd(this, a2: result);
    *soundError = SE_OK;
    return v8;
  }
  else
  {
    *soundError = SE_CANT_CREATE_MIXER;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10035780
// Name: public: virtual void CAudioSourceStreamMP3::Prefetch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamMP3::Prefetch(CAudioSourceStreamMP3 *this)
{
  const char *FileName; // eax
  int m_dataSize; // [esp-4h] [ebp-108h]
  char nameBuf[260]; // [esp+0h] [ebp-104h] BYREF

  m_dataSize = this->m_dataSize;
  FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  PrefetchDataStream(pFileName: FileName, dataOffset: 0, dataSize: m_dataSize);
}

//------------------------------------------------------------------------------
// Address: 0x100357B0
// Name: public: virtual class CAudioMixer __near * CAudioSourceStreamMP3::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CAudioSourceStreamMP3::CreateMixer(
        CAudioSourceStreamMP3 *this,
        int intialStreamPosition,
        int initialSkipSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  IWaveStreamSource *v6; // edi
  const char *FileName; // eax
  IWaveData *WaveDataStream; // eax
  CAudioMixer *MP3Mixer; // edi
  int m_dataSize; // [esp-14h] [ebp-124h]
  CSfxTable *m_pSfx; // [esp-10h] [ebp-120h]
  char nameBuf[260]; // [esp+Ch] [ebp-104h] BYREF

  if ( this != nullptr )
    v6 = &this->IWaveStreamSource;
  else
    v6 = nullptr;
  m_pSfx = this->m_pSfx;
  m_dataSize = this->m_dataSize;
  FileName = CSfxTable::GetFileName(this: m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  WaveDataStream = CreateWaveDataStream(
                     source: this,
                     pStreamSource: v6,
                     pFileName: FileName,
                     dataStart: 0,
                     dataSize: m_dataSize,
                     pSfx: m_pSfx,
                     startOffset: 0,
                     skipInitialSamples: 0,
                     soundError);
  if ( WaveDataStream != nullptr
    && (MP3Mixer = CreateMP3Mixer(data: WaveDataStream, pSampleRate: &this->m_sampleRate)) != nullptr )
  {
    this->ReferenceAdd(this, a2: MP3Mixer);
    *soundError = SE_OK;
    return MP3Mixer;
  }
  else
  {
    *soundError = SE_CANT_CREATE_MIXER;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035840
// Name: bool Audio_IsMP3(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Audio_IsMP3(const char *pName)
{
  int v1; // eax

  v1 = strlen(pName);
  return v1 > 4 && V_strnicmp(s1: &pName[v1 - 4], s2: ".mp3", n: 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035880
// Name: public: class CAudioSourceCachedInfo __near * CAudioSourceCachedInfoHandle_t::Get(int,bool,class CSfxTable __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CAudioSourceCachedInfoHandle_t::Get(
        CAudioSourceCachedInfoHandle_t *this,
        int audiosourcetype,
        BOOL soundisprecached,
        CSfxTable *sfx,
        int *pcacheddatasize)
{
  CAudioSourceCachedInfo *v6; // eax

  if ( this->m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
  {
    v6 = audiosourcecache->GetInfo(this: audiosourcecache, a2: audiosourcetype, a3: soundisprecached, a4: sfx);
    this->info = v6;
    if ( pcacheddatasize != nullptr && v6 != nullptr )
      *pcacheddatasize = v6->m_usCachedDataSize;
    this->m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
  }
  return this->info;
}

//------------------------------------------------------------------------------
// Address: 0x100358D0
// Name: protected: unsigned char __near * CAudioSourceMP3::GetCachedDataPointer(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CAudioSourceMP3::GetCachedDataPointer(CAudioSourceMP3 *this)
{
  CSfxTable *m_pSfx; // edi
  int *p_m_nCachedDataSize; // ebx
  CAudioSourceCachedInfo *v4; // eax
  CAudioSourceCachedInfo *info; // esi
  bool IsPrecachedSound; // [esp+Ch] [ebp-4h]

  m_pSfx = this->m_pSfx;
  p_m_nCachedDataSize = &this->m_nCachedDataSize;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx);
  if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
  {
    v4 = audiosourcecache->GetInfo(this: audiosourcecache, a2: 2, a3: IsPrecachedSound, a4: m_pSfx);
    this->m_AudioCacheHandle.info = v4;
    if ( this != (CAudioSourceMP3 *)-12 && v4 != nullptr )
      *p_m_nCachedDataSize = v4->m_usCachedDataSize;
    this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
  }
  info = this->m_AudioCacheHandle.info;
  if ( info != nullptr )
    return info->m_pCachedData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10035940
// Name: public: CAudioSourceMP3::CAudioSourceMP3(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3 *__thiscall CAudioSourceMP3::CAudioSourceMP3(CAudioSourceMP3 *this, CSfxTable *pSfx)
{
  IFileReadBinary_vtbl *v3; // edi
  const char *FileName; // eax
  int v5; // edi
  char nameBuf[260]; // [esp+Ch] [ebp-104h] BYREF

  this->__vftable = (CAudioSourceMP3_vtbl *)&CAudioSourceMP3::`vftable';
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  this->m_sampleRate = 44100;
  this->m_pSfx = pSfx;
  this->m_refCount = 0;
  this->m_dataStart = 0;
  v3 = g_pSndIO->__vftable;
  FileName = CSfxTable::GetFileName(this: pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  v5 = v3->open(this: g_pSndIO, a2: FileName);
  if ( v5 == -1 )
  {
    *((_BYTE *)this + 36) &= 0xFCu;
    this->m_dataSize = 0;
  }
  else
  {
    this->m_dataSize = g_pSndIO->size(this: g_pSndIO, a2: v5);
    g_pSndIO->close(this: g_pSndIO, a2: v5);
    *((_BYTE *)this + 36) &= 0xFCu;
  }
  this->m_nCachedDataSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035A00
// Name: public: virtual void CAudioSourceMP3::SetPlayOnce(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::SetPlayOnce(CAudioSourceMP3 *this, bool isPlayOnce)
{
  *((_BYTE *)this + 36) ^= (isPlayOnce ^ *((_BYTE *)this + 36)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035A20
// Name: public: virtual bool CAudioSourceMP3::IsPlayOnce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceMP3::IsPlayOnce(CAudioSourceMP3 *this)
{
  return *((_BYTE *)this + 36) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035A30
// Name: public: virtual void CAudioSourceMP3::SetSentenceWord(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::SetSentenceWord(CAudioSourceMP3 *this, bool bIsWord)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (2 * bIsWord)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x10035A50
// Name: public: virtual bool CAudioSourceMP3::IsSentenceWord(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceMP3::IsSentenceWord(CAudioSourceMP3 *this)
{
  return (*((_BYTE *)this + 36) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035A60
// Name: public: virtual bool CAudioSourceMP3::IsAsyncLoad(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceMP3::IsAsyncLoad(CAudioSourceMP3 *this)
{
  CSfxTable *m_pSfx; // edi
  int v3; // eax
  CAudioSourceCachedInfo *v4; // eax
  bool IsPrecachedSound; // [esp+4h] [ebp-4h]

  if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
  {
    m_pSfx = this->m_pSfx;
    IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx);
    v3 = this->GetType(this);
    if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
    {
      v4 = audiosourcecache->GetInfo(this: audiosourcecache, a2: v3, a3: IsPrecachedSound, a4: m_pSfx);
      this->m_AudioCacheHandle.info = v4;
      if ( this != (CAudioSourceMP3 *)-12 && v4 != nullptr )
        this->m_nCachedDataSize = v4->m_usCachedDataSize;
      this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
  }
  return this->m_nCachedDataSize <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035AE0
// Name: public: virtual void CAudioSourceMP3::GetCacheData(class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::GetCacheData(CAudioSourceMP3 *this, CAudioSourceCachedInfo *info)
{
  unsigned int v3; // eax
  IFileReadBinary_vtbl *v4; // ebx
  const char *FileName; // eax
  int v6; // ebx
  char pOutBuf[260]; // [esp+Ch] [ebp-104h] BYREF

  v3 = info->infolong ^ (this->m_sampleRate << 14);
  info->m_dataStart = 0;
  info->infolong ^= v3 & 0x7FFFC000;
  v4 = g_pSndIO->__vftable;
  FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf, bufLen: 0x104u);
  v6 = v4->open(this: g_pSndIO, a2: FileName);
  if ( v6 != 0 )
  {
    this->m_dataSize = g_pSndIO->size(this: g_pSndIO, a2: v6);
    g_pSndIO->close(this: g_pSndIO, a2: v6);
  }
  info->m_dataSize = this->m_dataSize;
}

//------------------------------------------------------------------------------
// Address: 0x10035B80
// Name: public: virtual void CAudioSourceMP3::CheckAudioSourceCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::CheckAudioSourceCache(CAudioSourceMP3 *this)
{
  CSfxTable *m_pSfx; // ebx
  int v3; // eax
  CAudioSourceCachedInfo *v4; // eax

  if ( CSfxTable::IsPrecachedSound(this: this->m_pSfx) )
  {
    m_pSfx = this->m_pSfx;
    v3 = this->GetType(this);
    if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
    {
      v4 = audiosourcecache->GetInfo(this: audiosourcecache, a2: v3, a3: 1, a4: m_pSfx);
      this->m_AudioCacheHandle.info = v4;
      if ( this != (CAudioSourceMP3 *)-12 && v4 != nullptr )
        this->m_nCachedDataSize = v4->m_usCachedDataSize;
      this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035BE0
// Name: public: CAudioSourceMP3Cache::CAudioSourceMP3Cache(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3Cache *__thiscall CAudioSourceMP3Cache::CAudioSourceMP3Cache(
        CAudioSourceMP3Cache *this,
        CSfxTable *pSfx)
{
  CAudioSourceMP3::CAudioSourceMP3(this, pSfx);
  this->__vftable = (CAudioSourceMP3Cache_vtbl *)&CAudioSourceMP3Cache::`vftable';
  this->m_hCache = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035C10
// Name: public: CAudioSourceMP3Cache::CAudioSourceMP3Cache(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3Cache *__thiscall CAudioSourceMP3Cache::CAudioSourceMP3Cache(
        CAudioSourceMP3Cache *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  int m_dataStart; // esi

  this->__vftable = (CAudioSourceMP3Cache_vtbl *)&CAudioSourceMP3::`vftable';
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  this->m_pSfx = pSfx;
  this->m_sampleRate = 44100;
  this->m_refCount = 0;
  this->m_dataSize = info->m_dataSize;
  m_dataStart = info->m_dataStart;
  *((_BYTE *)&this->CAudioSourceMP3 + 36) &= ~1u;
  this->m_dataStart = m_dataStart;
  this->m_nCachedDataSize = 0;
  this->__vftable = (CAudioSourceMP3Cache_vtbl *)&CAudioSourceMP3Cache::`vftable';
  this->m_hCache = 0;
  this->m_dataSize = info->m_dataSize;
  this->m_dataStart = info->m_dataStart;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035C70
// Name: public: virtual int CAudioSourceMP3Cache::GetOutputData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMP3Cache::GetOutputData(
        CAudioSourceMP3Cache *this,
        void **pData,
        __int64 samplePosition,
        int sampleCount,
        char *copyBuf)
{
  int v5; // ebx
  int v7; // eax
  int v8; // edi
  unsigned __int8 *CachedDataPointer; // eax

  v5 = samplePosition;
  v7 = this->m_dataSize - samplePosition;
  if ( v7 < 0 )
    v7 = 0;
  v8 = sampleCount;
  if ( sampleCount > v7 )
  {
    sampleCount = v7;
    v8 = v7;
  }
  if ( v8 == 0 )
    return v8;
  if ( samplePosition < this->m_nCachedDataSize )
  {
    this->CacheLoad(this);
    if ( samplePosition + v8 >= this->m_nCachedDataSize )
      sampleCount = this->m_nCachedDataSize - samplePosition;
    CachedDataPointer = CAudioSourceMP3::GetCachedDataPointer(this);
    v8 = sampleCount;
    v5 = samplePosition;
  }
  else
  {
    CachedDataPointer = (unsigned __int8 *)this->GetDataPointer(this);
  }
  *pData = CachedDataPointer;
  if ( CachedDataPointer != nullptr )
  {
    *pData = &CachedDataPointer[v5];
    return v8;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035D10
// Name: public: virtual __int64 CAudioSourceStreamMP3::UpdateLoopingSamplePosition(__int64)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CAudioSourceStreamMP3::UpdateLoopingSamplePosition(
        CAudioSourceStreamMP3 *this,
        __int64 samplePosition)
{
  return samplePosition;
}

//------------------------------------------------------------------------------
// Address: 0x10035D20
// Name: public: CAudioSourceStreamMP3::CAudioSourceStreamMP3(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceStreamMP3 *__thiscall CAudioSourceStreamMP3::CAudioSourceStreamMP3(
        CAudioSourceStreamMP3 *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  int m_dataStart; // esi

  this->CAudioSourceMP3::CAudioSource::__vftable = (CAudioSourceStreamMP3_vtbl *)&CAudioSourceMP3::`vftable';
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  this->m_pSfx = pSfx;
  this->m_sampleRate = 44100;
  this->m_refCount = 0;
  this->m_dataSize = info->m_dataSize;
  m_dataStart = info->m_dataStart;
  *((_BYTE *)&this->CAudioSourceMP3 + 36) &= ~1u;
  this->m_dataStart = m_dataStart;
  this->m_nCachedDataSize = 0;
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&IWaveStreamSource::`vftable';
  this->CAudioSourceMP3::CAudioSource::__vftable = (CAudioSourceStreamMP3_vtbl *)&CAudioSourceStreamMP3::`vftable'{for `CAudioSourceMP3'};
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&CAudioSourceStreamMP3::`vftable'{for `IWaveStreamSource'};
  this->m_dataSize = info->m_dataSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035D80
// Name: class CAudioSource __near * Audio_CreateStreamedMP3(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceStreamMP3 *__cdecl Audio_CreateStreamedMP3(CSfxTable *pSfx)
{
  IAudioSourceCache_vtbl *v1; // esi
  bool IsPrecachedSound; // al
  int v3; // eax
  CAudioSourceCachedInfo *v4; // esi
  CAudioSourceStreamMP3 *v5; // eax
  CAudioSourceMP3 *v7; // eax
  _DWORD *v8; // esi

  v1 = audiosourcecache->__vftable;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: pSfx);
  v3 = (int)v1->GetInfo(this: audiosourcecache, a2: 2, a3: IsPrecachedSound, a4: pSfx);
  v4 = (CAudioSourceCachedInfo *)v3;
  if ( v3 != 0 && *(_DWORD *)(v3 + 24) != 0 )
  {
    v5 = (CAudioSourceStreamMP3 *)MemAlloc_Alloc(nSize: 0x2Cu);
    if ( v5 != nullptr )
      return CAudioSourceStreamMP3::CAudioSourceStreamMP3(this: v5, pSfx, info: v4);
  }
  else
  {
    v7 = (CAudioSourceMP3 *)MemAlloc_Alloc(nSize: 0x2Cu);
    v8 = &v7->__vftable;
    if ( v7 != nullptr )
    {
      CAudioSourceMP3::CAudioSourceMP3(this: v7, pSfx);
      v8[10] = &IWaveStreamSource::`vftable';
      *v8 = &CAudioSourceStreamMP3::`vftable'{for `CAudioSourceMP3'};
      v8[10] = &CAudioSourceStreamMP3::`vftable'{for `IWaveStreamSource'};
      return (CAudioSourceStreamMP3 *)v8;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10035E10
// Name: class CAudioSource __near * Audio_CreateMemoryMP3(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3Cache *__cdecl Audio_CreateMemoryMP3(CSfxTable *pSfx)
{
  IAudioSourceCache_vtbl *v1; // esi
  bool IsPrecachedSound; // al
  CAudioSourceCachedInfo *v3; // esi
  CAudioSourceMP3Cache *v4; // eax
  _DWORD *v6; // esi

  v1 = audiosourcecache->__vftable;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: pSfx);
  v3 = v1->GetInfo(this: audiosourcecache, a2: 2, a3: IsPrecachedSound, a4: pSfx);
  v4 = (CAudioSourceMP3Cache *)MemAlloc_Alloc(nSize: 0x2Cu);
  if ( v3 != nullptr )
  {
    if ( v4 != nullptr )
      return CAudioSourceMP3Cache::CAudioSourceMP3Cache(this: v4, pSfx, info: v3);
  }
  else
  {
    v6 = &v4->__vftable;
    if ( v4 != nullptr )
    {
      CAudioSourceMP3::CAudioSourceMP3(this: v4, pSfx);
      *v6 = &CAudioSourceMP3Cache::`vftable';
      v6[10] = 0;
      return (CAudioSourceMP3Cache *)v6;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003D9D0
// Name: public: virtual int CAudioSourceMP3::GetType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMP3::GetType(CAudioDeviceNull *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x101D7D80
// Name: public: virtual int CAudioSourceMP3::SampleCount(void)
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CAudioSourceMP3::SampleCount(CVTFTexture *this)
{
  return this->m_Format;
}

//------------------------------------------------------------------------------
// Address: 0x10222540
// Name: public: virtual int CAudioSourceMP3::SampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMP3::SampleSize(CEngineSingleUserFilter *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10222570
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

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10035270
// Name: public: virtual void CAudioSourceMP3::ReferenceAdd(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::ReferenceAdd(CAudioSourceMP3 *this, CAudioMixer *__formal)
{
  ++this->m_refCount;
}

//------------------------------------------------------------------------------
// Address: 0x10035280
// Name: public: virtual void CAudioSourceMP3::ReferenceRemove(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::ReferenceRemove(CAudioSourceMP3 *this, CAudioMixer *__formal)
{
  if ( this->m_refCount-- == 1 && this->IsPlayOnce(this) )
  {
    this->SetPlayOnce(this, a2: false);
    this->CacheUnload(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100352B0
// Name: public: virtual bool CAudioSourceMP3::CanDelete(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceMP3::CanDelete(CAudioSourceMP3 *this)
{
  return this->m_refCount <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x100352C0
// Name: public: virtual char const __near * CAudioSourceMP3::GetFileName(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAudioSourceMP3::GetFileName(CAudioSourceMP3 *this, char *pOutBuf, unsigned int bufLen)
{
  CSfxTable *m_pSfx; // ecx

  m_pSfx = this->m_pSfx;
  if ( m_pSfx != nullptr )
    return CSfxTable::GetFileName(this: m_pSfx, pOutBuf, bufLen);
  else
    return "NULL m_pSfx";
}

//------------------------------------------------------------------------------
// Address: 0x100352E0
// Name: public: virtual int CAudioSourceMP3Cache::GetCacheStatus(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceMP3Cache::GetCacheStatus(CAudioSourceMP3Cache *this)
{
  BOOL v2; // ebx
  CSfxTable *m_pSfx; // ecx
  char *FileName; // eax
  int m_dataSize; // [esp-8h] [ebp-120h]
  int m_dataStart; // [esp-4h] [ebp-11Ch]
  char nameBuf[260]; // [esp+Ch] [ebp-10Ch] BYREF
  IAsyncWavDataCache_vtbl *v9; // [esp+110h] [ebp-8h]
  bool bCacheValid; // [esp+117h] [ebp-1h] BYREF

  v2 = wavedatacache->IsDataLoadCompleted(this: wavedatacache, a2: this->m_hCache, a3: &bCacheValid, a4: nullptr);
  if ( !bCacheValid )
  {
    m_dataStart = this->m_dataStart;
    m_dataSize = this->m_dataSize;
    m_pSfx = this->m_pSfx;
    v9 = wavedatacache->__vftable;
    FileName = CSfxTable::GetFileName(this: m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    v9->RestartDataLoad(this: wavedatacache, a2: &this->m_hCache, a3: FileName, a4: m_dataSize, a5: m_dataStart);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10035360
// Name: public: virtual void CAudioSourceMP3Cache::CacheLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3Cache::CacheLoad(CAudioSourceMP3Cache *this)
{
  IAsyncWavDataCache_vtbl *v2; // edi
  char *FileName; // eax
  int m_dataSize; // [esp-10h] [ebp-118h]
  int m_dataStart; // [esp-Ch] [ebp-114h]
  char nameBuf[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_hCache != 0 )
  {
    this->GetCacheStatus(this);
  }
  else
  {
    v2 = wavedatacache->__vftable;
    m_dataStart = this->m_dataStart;
    m_dataSize = this->m_dataSize;
    FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    this->m_hCache = v2->AsyncLoadCache(this: wavedatacache, a2: FileName, a3: m_dataSize, a4: m_dataStart, a5: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100353C0
// Name: public: virtual void CAudioSourceMP3Cache::CacheUnload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3Cache::CacheUnload(CAudioSourceMP3Cache *this)
{
  unsigned int m_hCache; // eax

  m_hCache = this->m_hCache;
  if ( m_hCache != 0 )
    wavedatacache->Unload(this: wavedatacache, a2: m_hCache);
}

//------------------------------------------------------------------------------
// Address: 0x100353E0
// Name: protected: virtual char __near * CAudioSourceMP3Cache::GetDataPointer(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAudioSourceMP3Cache::GetDataPointer(CAudioSourceMP3Cache *this)
{
  bool v2; // zf
  unsigned int *p_m_hCache; // edi
  IAsyncWavDataCache_vtbl *v4; // ebx
  char *FileName; // eax
  int m_dataSize; // [esp-14h] [ebp-12Ch]
  int m_dataStart; // [esp-10h] [ebp-128h]
  char nameBuf[260]; // [esp+Ch] [ebp-10Ch] BYREF
  char *pMP3Data; // [esp+110h] [ebp-8h] BYREF
  bool dummy; // [esp+117h] [ebp-1h] BYREF

  v2 = this->m_hCache == 0;
  p_m_hCache = &this->m_hCache;
  pMP3Data = nullptr;
  dummy = false;
  if ( v2 )
    this->CacheLoad(this);
  v4 = wavedatacache->__vftable;
  m_dataStart = this->m_dataStart;
  m_dataSize = this->m_dataSize;
  FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  v4->GetDataPointer(
    this: wavedatacache,
    a2: p_m_hCache,
    a3: FileName,
    a4: m_dataSize,
    a5: m_dataStart,
    a6: (void **)&pMP3Data,
    a7: 0,
    a8: &dummy);
  return pMP3Data;
}

//------------------------------------------------------------------------------
// Address: 0x10035450
// Name: public: virtual class CAudioMixer __near * CAudioSourceMP3Cache::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CAudioSourceMP3Cache::CreateMixer(
        CAudioSourceMP3Cache *this,
        int initialStreamPosition,
        int skipInitialSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  IWaveData *WaveDataMemory; // eax
  CAudioMixer *result; // eax
  CAudioMixer *v8; // edi
  int *p_m_sampleRate; // [esp-4h] [ebp-Ch]

  p_m_sampleRate = &this->m_sampleRate;
  WaveDataMemory = CreateWaveDataMemory(source: this);
  result = CreateMP3Mixer(data: WaveDataMemory, pSampleRate: p_m_sampleRate);
  v8 = result;
  if ( result != nullptr )
  {
    this->ReferenceAdd(this, a2: result);
    *soundError = SE_OK;
    return v8;
  }
  else
  {
    *soundError = SE_CANT_CREATE_MIXER;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100354A0
// Name: public: virtual void CAudioSourceStreamMP3::Prefetch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamMP3::Prefetch(CAudioSourceStreamMP3 *this)
{
  char *FileName; // eax
  int m_dataSize; // [esp-4h] [ebp-108h]
  char nameBuf[260]; // [esp+0h] [ebp-104h] BYREF

  m_dataSize = this->m_dataSize;
  FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  PrefetchDataStream(pFileName: FileName, dataOffset: 0, dataSize: m_dataSize);
}

//------------------------------------------------------------------------------
// Address: 0x100354D0
// Name: public: virtual class CAudioMixer __near * CAudioSourceStreamMP3::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CAudioSourceStreamMP3::CreateMixer(
        CAudioSourceStreamMP3 *this,
        int intialStreamPosition,
        int initialSkipSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  IWaveStreamSource *v6; // edi
  char *FileName; // eax
  IWaveData *WaveDataStream; // eax
  CAudioMixer *MP3Mixer; // edi
  int m_dataSize; // [esp-14h] [ebp-124h]
  CSfxTable *m_pSfx; // [esp-10h] [ebp-120h]
  char nameBuf[260]; // [esp+Ch] [ebp-104h] BYREF

  if ( this != nullptr )
    v6 = &this->IWaveStreamSource;
  else
    v6 = nullptr;
  m_pSfx = this->m_pSfx;
  m_dataSize = this->m_dataSize;
  FileName = CSfxTable::GetFileName(this: m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  WaveDataStream = CreateWaveDataStream(
                     source: this,
                     pStreamSource: v6,
                     pFileName: FileName,
                     dataStart: 0,
                     dataSize: m_dataSize,
                     pSfx: m_pSfx,
                     startOffset: 0,
                     skipInitialSamples: 0,
                     soundError);
  if ( WaveDataStream != nullptr
    && (MP3Mixer = CreateMP3Mixer(data: WaveDataStream, pSampleRate: &this->m_sampleRate)) != nullptr )
  {
    this->ReferenceAdd(this, a2: MP3Mixer);
    *soundError = SE_OK;
    return MP3Mixer;
  }
  else
  {
    *soundError = SE_CANT_CREATE_MIXER;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035620
// Name: protected: unsigned char __near * CAudioSourceMP3::GetCachedDataPointer(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CAudioSourceMP3::GetCachedDataPointer(CAudioSourceMP3 *this)
{
  CSfxTable *m_pSfx; // edi
  int *p_m_nCachedDataSize; // ebx
  CAudioSourceCachedInfo *v4; // eax
  CAudioSourceCachedInfo *info; // esi
  bool IsPrecachedSound; // [esp+Ch] [ebp-4h]

  m_pSfx = this->m_pSfx;
  p_m_nCachedDataSize = &this->m_nCachedDataSize;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx);
  if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
  {
    v4 = audiosourcecache->GetInfo(this: audiosourcecache, a2: 2, a3: IsPrecachedSound, a4: m_pSfx);
    this->m_AudioCacheHandle.info = v4;
    if ( this != (CAudioSourceMP3 *)-12 && v4 != nullptr )
      *p_m_nCachedDataSize = v4->m_usCachedDataSize;
    this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
  }
  info = this->m_AudioCacheHandle.info;
  if ( info != nullptr )
    return info->m_pCachedData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10035690
// Name: public: CAudioSourceMP3::CAudioSourceMP3(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3 *__thiscall CAudioSourceMP3::CAudioSourceMP3(CAudioSourceMP3 *this, CSfxTable *pSfx)
{
  IFileReadBinary_vtbl *v3; // edi
  char *FileName; // eax
  int v5; // edi
  char nameBuf[260]; // [esp+Ch] [ebp-104h] BYREF

  this->__vftable = (CAudioSourceMP3_vtbl *)&CAudioSourceMP3::`vftable';
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  this->m_sampleRate = 44100;
  this->m_pSfx = pSfx;
  this->m_refCount = 0;
  this->m_dataStart = 0;
  v3 = g_pSndIO->__vftable;
  FileName = CSfxTable::GetFileName(this: pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  v5 = v3->open(this: g_pSndIO, a2: FileName);
  if ( v5 == -1 )
  {
    *((_BYTE *)this + 36) &= 0xFCu;
    this->m_dataSize = 0;
  }
  else
  {
    this->m_dataSize = g_pSndIO->size(this: g_pSndIO, a2: v5);
    g_pSndIO->close(this: g_pSndIO, a2: v5);
    *((_BYTE *)this + 36) &= 0xFCu;
  }
  this->m_nCachedDataSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035740
// Name: public: virtual void CAudioSourceMP3::SetPlayOnce(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::SetPlayOnce(CAudioSourceMP3 *this, bool isPlayOnce)
{
  *((_BYTE *)this + 36) ^= (isPlayOnce ^ *((_BYTE *)this + 36)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035760
// Name: public: virtual bool CAudioSourceMP3::IsPlayOnce(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceMP3::IsPlayOnce(CAudioSourceMP3 *this)
{
  return *((_BYTE *)this + 36) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035770
// Name: public: virtual void CAudioSourceMP3::SetSentenceWord(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::SetSentenceWord(CAudioSourceMP3 *this, bool bIsWord)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (2 * bIsWord)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x10035790
// Name: public: virtual bool CAudioSourceMP3::IsSentenceWord(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceMP3::IsSentenceWord(CAudioSourceMP3 *this)
{
  return (*((_BYTE *)this + 36) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035830
// Name: public: virtual void CAudioSourceMP3::GetCacheData(class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMP3::GetCacheData(CAudioSourceMP3 *this, CAudioSourceCachedInfo *info)
{
  unsigned int v3; // eax
  IFileReadBinary_vtbl *v4; // ebx
  char *FileName; // eax
  int v6; // ebx
  char pOutBuf[260]; // [esp+Ch] [ebp-104h] BYREF

  v3 = info->infolong ^ (this->m_sampleRate << 14);
  info->m_dataStart = 0;
  info->infolong ^= v3 & 0x7FFFC000;
  v4 = g_pSndIO->__vftable;
  FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf, bufLen: 0x104u);
  v6 = v4->open(this: g_pSndIO, a2: FileName);
  if ( v6 != 0 )
  {
    this->m_dataSize = g_pSndIO->size(this: g_pSndIO, a2: v6);
    g_pSndIO->close(this: g_pSndIO, a2: v6);
  }
  info->m_dataSize = this->m_dataSize;
}

//------------------------------------------------------------------------------
// Address: 0x10035930
// Name: public: CAudioSourceMP3Cache::CAudioSourceMP3Cache(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3Cache *__thiscall CAudioSourceMP3Cache::CAudioSourceMP3Cache(
        CAudioSourceMP3Cache *this,
        CSfxTable *pSfx)
{
  CAudioSourceMP3::CAudioSourceMP3(this, pSfx);
  this->__vftable = (CAudioSourceMP3Cache_vtbl *)&CAudioSourceMP3Cache::`vftable';
  this->m_hCache = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035960
// Name: public: CAudioSourceMP3Cache::CAudioSourceMP3Cache(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3Cache *__thiscall CAudioSourceMP3Cache::CAudioSourceMP3Cache(
        CAudioSourceMP3Cache *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  int m_dataStart; // esi

  this->__vftable = (CAudioSourceMP3Cache_vtbl *)&CAudioSourceMP3::`vftable';
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  this->m_pSfx = pSfx;
  this->m_sampleRate = 44100;
  this->m_refCount = 0;
  this->m_dataSize = info->m_dataSize;
  m_dataStart = info->m_dataStart;
  *((_BYTE *)&this->CAudioSourceMP3 + 36) &= ~1u;
  this->m_dataStart = m_dataStart;
  this->m_nCachedDataSize = 0;
  this->__vftable = (CAudioSourceMP3Cache_vtbl *)&CAudioSourceMP3Cache::`vftable';
  this->m_hCache = 0;
  this->m_dataSize = info->m_dataSize;
  this->m_dataStart = info->m_dataStart;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100359C0
// Name: public: virtual int CAudioSourceMP3Cache::GetOutputData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMP3Cache::GetOutputData(
        CAudioSourceMP3Cache *this,
        void **pData,
        __int64 samplePosition,
        int sampleCount,
        char *copyBuf)
{
  int v5; // ebx
  int v7; // eax
  int v8; // edi
  unsigned __int8 *CachedDataPointer; // eax

  v5 = samplePosition;
  v7 = this->m_dataSize - samplePosition;
  if ( v7 < 0 )
    v7 = 0;
  v8 = sampleCount;
  if ( sampleCount > v7 )
  {
    sampleCount = v7;
    v8 = v7;
  }
  if ( v8 == 0 )
    return v8;
  if ( samplePosition < this->m_nCachedDataSize )
  {
    this->CacheLoad(this);
    if ( samplePosition + v8 >= this->m_nCachedDataSize )
      sampleCount = this->m_nCachedDataSize - samplePosition;
    CachedDataPointer = CAudioSourceMP3::GetCachedDataPointer(this);
    v8 = sampleCount;
    v5 = samplePosition;
  }
  else
  {
    CachedDataPointer = (unsigned __int8 *)this->GetDataPointer(this);
  }
  *pData = CachedDataPointer;
  if ( CachedDataPointer != nullptr )
  {
    *pData = &CachedDataPointer[v5];
    return v8;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035A80
// Name: public: CAudioSourceStreamMP3::CAudioSourceStreamMP3(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceStreamMP3 *__thiscall CAudioSourceStreamMP3::CAudioSourceStreamMP3(
        CAudioSourceStreamMP3 *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  int m_dataStart; // esi

  this->CAudioSourceMP3::CAudioSource::__vftable = (CAudioSourceStreamMP3_vtbl *)&CAudioSourceMP3::`vftable';
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  this->m_pSfx = pSfx;
  this->m_sampleRate = 44100;
  this->m_refCount = 0;
  this->m_dataSize = info->m_dataSize;
  m_dataStart = info->m_dataStart;
  *((_BYTE *)&this->CAudioSourceMP3 + 36) &= ~1u;
  this->m_dataStart = m_dataStart;
  this->m_nCachedDataSize = 0;
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&IWaveStreamSource::`vftable';
  this->CAudioSourceMP3::CAudioSource::__vftable = (CAudioSourceStreamMP3_vtbl *)&CAudioSourceStreamMP3::`vftable'{for `CAudioSourceMP3'};
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&CAudioSourceStreamMP3::`vftable'{for `IWaveStreamSource'};
  this->m_dataSize = info->m_dataSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035B70
// Name: class CAudioSource __near * Audio_CreateMemoryMP3(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3Cache *__cdecl Audio_CreateMemoryMP3(CSfxTable *pSfx)
{
  IAudioSourceCache_vtbl *v1; // esi
  bool IsPrecachedSound; // al
  CAudioSourceCachedInfo *v3; // esi
  CAudioSourceMP3Cache *v4; // eax
  _DWORD *v6; // esi

  v1 = audiosourcecache->__vftable;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: pSfx);
  v3 = v1->GetInfo(this: audiosourcecache, a2: 2, a3: IsPrecachedSound, a4: pSfx);
  v4 = (CAudioSourceMP3Cache *)MemAlloc_Alloc(nSize: 0x2Cu);
  if ( v3 != nullptr )
  {
    if ( v4 != nullptr )
      return CAudioSourceMP3Cache::CAudioSourceMP3Cache(this: v4, pSfx, info: v3);
  }
  else
  {
    v6 = &v4->__vftable;
    if ( v4 != nullptr )
    {
      CAudioSourceMP3::CAudioSourceMP3(this: v4, pSfx);
      *v6 = &CAudioSourceMP3Cache::`vftable';
      v6[10] = 0;
      return (CAudioSourceMP3Cache *)v6;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003D670
// Name: public: virtual int CAudioSourceMP3::GetType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMP3::GetType(CAudioDeviceNull *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10090F10
// Name: public: virtual int CAudioSourceMP3::SampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMP3::SampleSize(CEngineSingleUserFilter *this)
{
  return 1;
}

} // namespace engine_xlsp
