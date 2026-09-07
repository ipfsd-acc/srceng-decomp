// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makesoundcache.cpp
// Functions: 51
// ============================================================

#include "utils\xbox\makegamedata\makesoundcache.h"

//------------------------------------------------------------------------------
// Address: 0x004102A0
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410300
// Name: public: virtual int MakeSoundCache_ReadBinary::open(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall MakeSoundCache_ReadBinary::open(MakeSoundCache_ReadBinary *this, const char *pFileName)
{
  void *v2; // esi
  int v3; // ecx
  double v4; // st7
  double flStart; // [esp+4h] [ebp-8h]

  flStart = _Plat_FloatTime(a1: this);
  v2 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: "GAME");
  v4 = _Plat_FloatTime(a1: v3);
  g_flFileIOTime = v4 - flStart + g_flFileIOTime;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00410350
// Name: public: virtual int MakeSoundCache_ReadBinary::read(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall MakeSoundCache_ReadBinary::read(MakeSoundCache_ReadBinary *this, void *pOutput, int size, void *file)
{
  int v5; // esi
  int v6; // ecx
  double flStart; // [esp+4h] [ebp-8h]

  if ( file == nullptr )
    return 0;
  flStart = _Plat_FloatTime(a1: this);
  v5 = g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: pOutput, a3: size, a4: file);
  g_flFileIOTime = _Plat_FloatTime(a1: v6) - flStart + g_flFileIOTime;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004103B0
// Name: public: virtual void MakeSoundCache_ReadBinary::seek(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MakeSoundCache_ReadBinary::seek(MakeSoundCache_ReadBinary *this, void *file, int pos)
{
  int v3; // ecx
  double flStart; // [esp+4h] [ebp-8h]

  if ( file != nullptr )
  {
    flStart = _Plat_FloatTime(a1: this);
    g_pFullFileSystem->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: file, a3: pos, a4: FILESYSTEM_SEEK_HEAD);
    g_flFileIOTime = _Plat_FloatTime(a1: v3) - flStart + g_flFileIOTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410400
// Name: public: virtual unsigned int MakeSoundCache_ReadBinary::tell(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall MakeSoundCache_ReadBinary::tell(MakeSoundCache_ReadBinary *this, void *file)
{
  unsigned int v3; // esi
  int v4; // ecx
  double flStart; // [esp+4h] [ebp-8h]

  if ( file == nullptr )
    return 0;
  flStart = _Plat_FloatTime(a1: this);
  v3 = g_pFullFileSystem->Tell(this: &g_pFullFileSystem->IBaseFileSystem, a2: file);
  g_flFileIOTime = _Plat_FloatTime(a1: v4) - flStart + g_flFileIOTime;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00410460
// Name: public: virtual unsigned int MakeSoundCache_ReadBinary::size(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall MakeSoundCache_ReadBinary::size(MakeSoundCache_ReadBinary *this, void *file)
{
  unsigned int v3; // esi
  int v4; // ecx
  double flStart; // [esp+4h] [ebp-8h]

  if ( file == nullptr )
    return 0;
  flStart = _Plat_FloatTime(a1: this);
  v3 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: file);
  g_flFileIOTime = _Plat_FloatTime(a1: v4) - flStart + g_flFileIOTime;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004104C0
// Name: public: virtual void MakeSoundCache_ReadBinary::close(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MakeSoundCache_ReadBinary::close(MakeSoundCache_ReadBinary *this, void *file)
{
  int v2; // ecx
  double flStart; // [esp+4h] [ebp-8h]

  if ( file != nullptr )
  {
    flStart = _Plat_FloatTime(a1: this);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: file);
    g_flFileIOTime = _Plat_FloatTime(a1: v2) - flStart + g_flFileIOTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410510
// Name: public: virtual char const __near * CAudioSourceWave::GetFileName(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAudioSourceWave::GetFileName(CAudioSourceWave *this, char *pOutBuf, unsigned int bufLen)
{
  const char *v3; // eax

  v3 = CUtlString::operator char const *(this: &this->m_filename);
  V_strncpy(pDest: pOutBuf, pSrc: v3, maxLen: bufLen);
  return pOutBuf;
}

//------------------------------------------------------------------------------
// Address: 0x00410540
// Name: protected: void CAudioSourceWave::Init(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::Init(CAudioSourceWave *this, char *pHeaderBuffer, int headerSize)
{
  int m_bits; // eax
  int v5; // ecx
  int v6; // eax
  char *v7; // eax

  this->m_format = *(unsigned __int16 *)pHeaderBuffer;
  this->m_bits = *((unsigned __int16 *)pHeaderBuffer + 7);
  m_bits = this->m_bits;
  this->m_rate = *((_DWORD *)pHeaderBuffer + 1);
  v5 = *((unsigned __int16 *)pHeaderBuffer + 1);
  v6 = v5 * m_bits / 8;
  this->m_channels = v5;
  this->m_sampleSize = v6;
  if ( v6 <= 0 )
    this->m_sampleSize = 1;
  if ( this->m_format == 2 )
  {
    v7 = (char *)MemAlloc_Alloc(nSize: headerSize);
    this->m_pHeader = v7;
    memcpy(dst: (unsigned __int8 *)v7, src: (unsigned __int8 *)pHeaderBuffer, count: headerSize);
    this->m_nHeaderSize = headerSize;
    this->m_sampleSize = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004105B0
// Name: public: void CAudioSourceWave::ParseDataChunk(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ParseDataChunk(CAudioSourceWave *this, IterateRIFF *walk)
{
  int NumEvents; // eax
  int m_format; // ecx

  this->m_dataStart = walk->m_chunkPosition + 8;
  NumEvents = CChoreoScene::GetNumEvents(this: (CVTFTexture *)walk);
  m_format = this->m_format;
  this->m_dataSize = NumEvents;
  if ( m_format == 1 )
  {
    this->m_sampleCount = NumEvents / this->m_sampleSize;
  }
  else if ( m_format == 2 )
  {
    this->m_sampleSize = 1;
    this->m_bits = 16;
    this->m_sampleCount = NumEvents;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410600
// Name: public: class CAudioSourceCachedInfo __near & CAudioSourceCachedInfo::operator=(class CAudioSourceCachedInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CAudioSourceCachedInfo::operator=(
        CAudioSourceCachedInfo *this,
        const CAudioSourceCachedInfo *src)
{
  CSentence *v3; // ebx
  CSentence *v4; // eax
  void *v5; // ebx
  char v6; // dl

  if ( this != src )
  {
    this->infolong = src->infolong;
    this->flagsbyte = src->flagsbyte;
    this->m_dataStart = src->m_dataStart;
    this->m_dataSize = src->m_dataSize;
    this->m_loopStart = src->m_loopStart;
    v3 = nullptr;
    this->m_sampleCount = src->m_sampleCount;
    if ( src->m_pSentence != nullptr )
    {
      v4 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
      if ( v4 != nullptr )
        v3 = CSentence::CSentence(this: v4);
      else
        v3 = nullptr;
      CSentence::operator=(this: v3, src: src->m_pSentence);
    }
    this->flagsbyte ^= (this->flagsbyte ^ (v3 != nullptr)) & 1;
    this->m_pSentence = v3;
    *(_DWORD *)&this->m_usCachedDataSize = 0;
    v5 = nullptr;
    if ( src->m_pHeader != nullptr && src->m_usHeaderSize != 0 )
    {
      this->m_usHeaderSize = src->m_usHeaderSize;
      v5 = MemAlloc_Alloc(nSize: src->m_usHeaderSize);
      _V_memcpy(dest: v5, src: src->m_pHeader, count: src->m_usHeaderSize);
    }
    v6 = this->flagsbyte ^ (4 * (v5 != nullptr));
    this->m_pHeader = (unsigned __int8 *)v5;
    this->flagsbyte ^= v6 & 4;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004106D0
// Name: public: void CAudioSourceCachedInfo::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Clear(CAudioSourceCachedInfo *this)
{
  CSentence *m_pSentence; // edi
  unsigned __int8 *m_pHeader; // [esp-8h] [ebp-14h]
  unsigned __int8 *m_pCachedData; // [esp-4h] [ebp-10h]

  m_pSentence = this->m_pSentence;
  this->infolong = 0;
  this->flagsbyte = 0;
  this->m_dataStart = 0;
  this->m_dataSize = 0;
  this->m_loopStart = 0;
  this->m_sampleCount = 0;
  if ( m_pSentence != nullptr )
  {
    CSentence::~CSentence(this: m_pSentence);
    free(pMem: m_pSentence);
  }
  m_pCachedData = this->m_pCachedData;
  this->m_pSentence = nullptr;
  free(pMem: m_pCachedData);
  m_pHeader = this->m_pHeader;
  this->m_pCachedData = nullptr;
  this->m_usCachedDataSize = 0;
  free(pMem: m_pHeader);
  this->m_pHeader = nullptr;
  this->m_usHeaderSize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410730
// Name: private: void CMasterCacheBuilder::Spew(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMasterCacheBuilder::Spew(CMasterCacheBuilder *this, const char *pFmt, ...)
{
  char string[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+810h] [ebp+10h] BYREF

  va_start(params, pFmt);
  if ( !this->m_bQuiet )
  {
    V_vsnprintf(pDest: string, maxLen: 2048, pFormat: pFmt, params);
    _Msg(a1: "%s", string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410780
// Name: private: void CMasterCacheBuilder::RemoveCache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterCacheBuilder::RemoveCache(CMasterCacheBuilder *this, const char *cachename)
{
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: cachename, a3: "MOD") )
  {
    if ( !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: cachename, a3: "MOD") )
      g_pFullFileSystem->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: cachename, a3: true, a4: "MOD");
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: cachename, a3: "MOD");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410810
// Name: public: bool CUtlCachedFileData<class CAudioSourceCachedInfo>::ManifestExists(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::ManifestExists(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  const char *v1; // eax
  char manifest_name[512]; // [esp+0h] [ebp-200h] BYREF

  v1 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  V_strncpy(pDest: manifest_name, pSrc: v1, maxLen: 512);
  V_SetExtension(path: manifest_name, extension: ".manifest", pathStringLength: 512);
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD");
}

//------------------------------------------------------------------------------
// Address: 0x00410940
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlCachedFileData<class CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411100
// Name: public: CMasterCacheBuilder::CacheBuild_t::CacheBuild_t(struct CMasterCacheBuilder::CacheBuild_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CMasterCacheBuilder::CacheBuild_t *__thiscall CMasterCacheBuilder::CacheBuild_t::CacheBuild_t(
        CMasterCacheBuilder::CacheBuild_t *this,
        const CMasterCacheBuilder::CacheBuild_t *__that)
{
  this->m_RelativePath = __that->m_RelativePath;
  this->m_Info.__vftable = (CAudioSourceCachedInfo_vtbl *)&CAudioSourceCachedInfo::`vftable';
  this->m_Info.infolong = __that->m_Info.infolong;
  this->m_Info.infolong = __that->m_Info.infolong;
  this->m_Info.flagsbyte = __that->m_Info.flagsbyte;
  this->m_Info.flagsbyte = __that->m_Info.flagsbyte;
  this->m_Info.m_loopStart = __that->m_Info.m_loopStart;
  this->m_Info.m_sampleCount = __that->m_Info.m_sampleCount;
  this->m_Info.m_dataStart = __that->m_Info.m_dataStart;
  this->m_Info.m_dataSize = __that->m_Info.m_dataSize;
  this->m_Info.m_usCachedDataSize = __that->m_Info.m_usCachedDataSize;
  this->m_Info.m_usHeaderSize = __that->m_Info.m_usHeaderSize;
  this->m_Info.m_pSentence = __that->m_Info.m_pSentence;
  this->m_Info.m_pCachedData = __that->m_Info.m_pCachedData;
  this->m_Info.m_pHeader = __that->m_Info.m_pHeader;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00411870
// Name: public: CAudioSourceMP3::CAudioSourceMP3(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3 *__thiscall CAudioSourceMP3::CAudioSourceMP3(CAudioSourceMP3 *this, const char *filename)
{
  IFileReadBinary *v3; // ecx
  int v4; // edi
  int v5; // eax
  IFileReadBinary *v6; // ecx

  this->__vftable = (CAudioSourceMP3_vtbl *)&CAudioSourceMP3::`vftable';
  CUtlString::CUtlString(this: &this->m_filename);
  CUtlString::operator=(this: &this->m_filename, src: filename);
  v3 = g_pMakeSoundCache_ReadBinary;
  this->m_sampleRate = 44100;
  this->m_dataStart = 0;
  v4 = v3->open(this: v3, a2: filename);
  if ( v4 == -1 )
  {
    this->m_dataSize = 0;
  }
  else
  {
    v5 = g_pMakeSoundCache_ReadBinary->size(this: g_pMakeSoundCache_ReadBinary, a2: v4);
    v6 = g_pMakeSoundCache_ReadBinary;
    this->m_dataSize = v5;
    v6->close(this: v6, a2: v4);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004118F0
// Name: public: CAudioSourceWave::CAudioSourceWave(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceWave *__thiscall CAudioSourceWave::CAudioSourceWave(CAudioSourceWave *this, const char *filename)
{
  this->__vftable = (CAudioSourceWave_vtbl *)&CAudioSourceWave::`vftable';
  CUtlString::CUtlString(this: &this->m_filename);
  CUtlString::operator=(this: &this->m_filename, src: filename);
  this->m_format = 0;
  this->m_pHeader = nullptr;
  this->m_nHeaderSize = 0;
  this->m_sampleCount = 0;
  this->m_bits = 0;
  this->m_channels = 0;
  this->m_dataStart = 0;
  this->m_dataSize = 0;
  this->m_rate = 0;
  this->m_pTempSentence = nullptr;
  this->m_nCachedDataSize = 0;
  this->m_loopStart = -1;
  this->m_sampleSize = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00411950
// Name: public: CAudioSourceWave::~CAudioSourceWave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::~CAudioSourceWave(CAudioSourceWave *this)
{
  CSentence *m_pTempSentence; // edi
  bool v3; // sf
  char *m_pHeader; // [esp-4h] [ebp-Ch]

  m_pHeader = this->m_pHeader;
  this->__vftable = (CAudioSourceWave_vtbl *)&CAudioSourceWave::`vftable';
  free(pMem: m_pHeader);
  m_pTempSentence = this->m_pTempSentence;
  if ( m_pTempSentence != nullptr )
  {
    CSentence::~CSentence(this: this->m_pTempSentence);
    free(pMem: m_pTempSentence);
  }
  v3 = this->m_filename.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_filename.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( this->m_filename.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_filename.m_Storage.m_Memory.m_pMemory);
      this->m_filename.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_filename.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004119C0
// Name: public: CMasterCacheBuilder::~CMasterCacheBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterCacheBuilder::~CMasterCacheBuilder(CMasterCacheBuilder *this)
{
  this->m_szCurrentLanguage.m_Storage.m_nActualLength = 0;
  if ( this->m_szCurrentLanguage.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory);
      this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szCurrentLanguage.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szMasterCache.m_Storage.m_nActualLength = 0;
  if ( this->m_szMasterCache.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szMasterCache.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szMasterCache.m_Storage.m_Memory.m_pMemory);
      this->m_szMasterCache.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szMasterCache.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szModPath.m_Storage.m_nActualLength = 0;
  if ( this->m_szModPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szModPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szModPath.m_Storage.m_Memory.m_pMemory);
      this->m_szModPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szModPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szMODPath.m_Storage.m_nActualLength = 0;
  if ( this->m_szMODPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szMODPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szMODPath.m_Storage.m_Memory.m_pMemory);
      this->m_szMODPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szMODPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412C80
// Name: public: void CAudioSourceWave::ParseSentence(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ParseSentence(CAudioSourceWave *this, IterateRIFF *walk)
{
  int NumEvents; // eax
  int v4; // eax
  CSentence *v5; // eax
  CSentence *v6; // eax
  unsigned __int8 *m_pMemory; // [esp-8h] [ebp-40h]
  int m_Put; // [esp-4h] [ebp-3Ch]
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  NumEvents = CChoreoScene::GetNumEvents(this: (CVTFTexture *)walk);
  CUtlBuffer::EnsureCapacity(this: &buf, num: NumEvents);
  IterateRIFF::ChunkRead(this: walk, pOutput: buf.m_Memory.m_pMemory);
  v4 = CChoreoScene::GetNumEvents(this: (CVTFTexture *)walk);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v4);
  v5 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
  if ( v5 != nullptr )
    v6 = CSentence::CSentence(this: v5);
  else
    v6 = nullptr;
  m_Put = buf.m_Put;
  m_pMemory = buf.m_Memory.m_pMemory;
  this->m_pTempSentence = v6;
  CSentence::InitFromDataChunk(this: v6, data: m_pMemory, size: m_Put);
  CSentence::MakeRuntimeOnly(this: this->m_pTempSentence);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00412D20
// Name: public: virtual void CAudioSourceCachedInfo::Save(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Save(CAudioSourceCachedInfo *this, CUtlBuffer *buf)
{
  unsigned __int8 flagsbyte; // bl
  int m_Put; // eax
  unsigned int infolong; // [esp-4h] [ebp-Ch]
  int m_dataStart; // [esp-4h] [ebp-Ch]
  int m_dataSize; // [esp-4h] [ebp-Ch]
  int m_loopStart; // [esp-4h] [ebp-Ch]
  int m_sampleCount; // [esp-4h] [ebp-Ch]
  int m_usCachedDataSize; // [esp-4h] [ebp-Ch]

  infolong = this->infolong;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", infolong);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: infolong);
  flagsbyte = this->flagsbyte;
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = flagsbyte;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
  m_dataStart = this->m_dataStart;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_dataStart);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_dataStart);
  m_dataSize = this->m_dataSize;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_dataSize);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_dataSize);
  m_loopStart = this->m_loopStart;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_loopStart);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_loopStart);
  m_sampleCount = this->m_sampleCount;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_sampleCount);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_sampleCount);
  if ( (this->flagsbyte & 1) != 0 )
    CSentence::CacheSaveToBuffer(this: this->m_pSentence, buf, version: 1);
  if ( (this->flagsbyte & 2) != 0 && this->m_pCachedData != nullptr )
  {
    m_usCachedDataSize = this->m_usCachedDataSize;
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%d", m_usCachedDataSize);
    else
      CUtlBuffer::PutTypeBin<int>(this: buf, src: m_usCachedDataSize);
    CUtlBuffer::Put(this: buf, pMem: this->m_pCachedData, size: this->m_usCachedDataSize);
  }
  if ( (this->flagsbyte & 4) != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%hd", (__int16)this->m_usHeaderSize);
    else
      CUtlBuffer::PutTypeBin<short>(this: buf, src: this->m_usHeaderSize);
    CUtlBuffer::Put(this: buf, pMem: this->m_pHeader, size: this->m_usHeaderSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412EB0
// Name: public: virtual void CAudioSourceCachedInfo::Restore(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Restore(CAudioSourceCachedInfo *this, CUtlBuffer *buf)
{
  unsigned __int8 v3; // al
  int Int; // eax
  bool v5; // zf
  CSentence *v6; // eax
  CSentence *v7; // eax
  unsigned __int16 v8; // ax
  void *v9; // ebx
  char v10; // dl
  unsigned __int16 Short; // ax
  void *v12; // ebx
  char v13; // dl

  CAudioSourceCachedInfo::Clear(this);
  this->infolong = CUtlBuffer::GetInt(this: buf);
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    ++buf->m_Get;
  }
  else
  {
    v3 = 0;
  }
  this->flagsbyte = v3;
  this->m_dataStart = CUtlBuffer::GetInt(this: buf);
  this->m_dataSize = CUtlBuffer::GetInt(this: buf);
  this->m_loopStart = CUtlBuffer::GetInt(this: buf);
  Int = CUtlBuffer::GetInt(this: buf);
  v5 = (this->flagsbyte & 1) == 0;
  this->m_sampleCount = Int;
  if ( !v5 )
  {
    v6 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v6 != nullptr )
      v7 = CSentence::CSentence(this: v6);
    else
      v7 = nullptr;
    this->m_pSentence = v7;
    CSentence::CacheRestoreFromBuffer(this: v7, buf);
  }
  if ( (this->flagsbyte & 2) != 0 )
  {
    v8 = CUtlBuffer::GetInt(this: buf);
    this->m_usCachedDataSize = v8;
    if ( v8 != 0 )
    {
      v9 = MemAlloc_Alloc(nSize: v8);
      CUtlBuffer::Get(this: buf, pMem: v9, size: this->m_usCachedDataSize);
      v10 = this->flagsbyte ^ (2 * (v9 != nullptr));
      this->m_pCachedData = (unsigned __int8 *)v9;
      this->flagsbyte ^= v10 & 2;
    }
  }
  if ( (this->flagsbyte & 4) != 0 )
  {
    Short = CUtlBuffer::GetShort(this: buf);
    this->m_usHeaderSize = Short;
    if ( Short != 0 )
    {
      v12 = MemAlloc_Alloc(nSize: Short);
      CUtlBuffer::Get(this: buf, pMem: v12, size: this->m_usHeaderSize);
      v13 = this->flagsbyte ^ (4 * (v12 != nullptr));
      this->m_pHeader = (unsigned __int8 *)v12;
      this->flagsbyte ^= v13 & 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004130A0
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::ForceRecheckDiskInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::ForceRecheckDiskInfo(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  unsigned __int16 i; // ax

  for ( i = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements,
              i) )
  {
    this->m_Elements.m_Elements.m_pMemory[i].m_Data.diskfileinfo = -2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004131D0
// Name: public: void CAudioSourceWave::ParseChunk(class IterateRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ParseChunk(CAudioSourceWave *this, IterateRIFF *walk, int chunkName)
{
  _BYTE v4[28]; // [esp+4h] [ebp-54h] BYREF
  int v5; // [esp+20h] [ebp-38h]
  int v6; // [esp+2Ch] [ebp-2Ch]
  int v7; // [esp+30h] [ebp-28h]
  _BYTE pOutput[20]; // [esp+40h] [ebp-18h] BYREF
  int v9; // [esp+54h] [ebp-4h]

  if ( chunkName > 1635017060 )
  {
    if ( chunkName == 1819307379 )
    {
      IterateRIFF::ChunkReadPartial(this: walk, pOutput: v4, dataSize: 60);
      if ( v5 != 0 && v6 == 0 )
        this->m_loopStart = v7;
    }
  }
  else
  {
    switch ( chunkName )
    {
      case 1635017060:
        CAudioSourceWave::ParseDataChunk(this, walk);
        break;
      case 543520099:
        if ( IterateRIFF::ChunkReadInt(this: walk) > 0 )
        {
          IterateRIFF::ChunkReadPartial(this: walk, pOutput, dataSize: 24);
          this->m_loopStart = v9;
        }
        break;
      case 1413563478:
        CAudioSourceWave::ParseSentence(this, walk);
        break;
      default:
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413270
// Name: public: void CAudioSourceWave::Setup(char const __near *,int,class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::Setup(CAudioSourceWave *this, char *pFormatBuffer, int formatSize, IterateRIFF *walk)
{
  int Count; // eax

  CAudioSourceWave::Init(this, pHeaderBuffer: pFormatBuffer, headerSize: formatSize);
  while ( IterateRIFF::ChunkAvailable(this: walk) )
  {
    Count = CCurveData::GetCount(this: (CVTFTexture *)walk);
    CAudioSourceWave::ParseChunk(this, walk, chunkName: Count);
    IterateRIFF::ChunkNext(this: walk);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004132C0
// Name: public: bool CAudioSourceWave::GetStartupData(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioSourceWave::GetStartupData(CAudioSourceWave *this)
{
  const char *(__thiscall *GetFileName)(CAudioSourceWave *, char *, unsigned int); // eax
  int v3; // esi
  int v4; // edi
  int NumEvents; // eax
  CAudioSourceWave *v6; // esi
  char formatBuffer[1024]; // [esp+0h] [ebp-534h] BYREF
  char nameBuf[260]; // [esp+400h] [ebp-134h] BYREF
  IterateRIFF walk; // [esp+504h] [ebp-30h] BYREF
  const char *pName; // [esp+51Ch] [ebp-18h]
  CAudioSourceWave *v11; // [esp+520h] [ebp-14h]
  InFileRIFF riff; // [esp+524h] [ebp-10h] BYREF

  GetFileName = this->GetFileName;
  v11 = this;
  pName = (const char *)((int (__stdcall *)(char *, int))GetFileName)(a1: nameBuf, a2: 260);
  InFileRIFF::InFileRIFF(this: &riff, pFileName: pName, io: g_pMakeSoundCache_ReadBinary);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    v3 = 0;
    v4 = 0;
    if ( !IterateRIFF::ChunkAvailable(this: &walk) )
      goto LABEL_14;
    while ( v3 == 0 )
    {
      if ( CCurveData::GetCount(this: (CVTFTexture *)&walk) == 544501094
        && (unsigned int)CChoreoScene::GetNumEvents(this: (CVTFTexture *)&walk) <= 0x400 )
      {
        IterateRIFF::ChunkRead(this: &walk, pOutput: formatBuffer);
        NumEvents = CChoreoScene::GetNumEvents(this: (CVTFTexture *)&walk);
        v3 = *(unsigned __int16 *)formatBuffer;
        v4 = NumEvents;
        if ( *(_WORD *)&formatBuffer[14] > 0x10u )
          _Warning(a1: "Unsupported %d-bit wave file %s\n", *(unsigned __int16 *)&formatBuffer[14], pName);
      }
      IterateRIFF::ChunkNext(this: &walk);
      if ( !IterateRIFF::ChunkAvailable(this: &walk) )
      {
        if ( v3 == 0 )
          goto LABEL_14;
        break;
      }
    }
    v6 = v11;
    CAudioSourceWave::Setup(this: v11, pFormatBuffer: formatBuffer, formatSize: v4, &walk);
    if ( v6->m_dataStart != 0 && v6->m_dataSize != 0 )
    {
      InFileRIFF::~InFileRIFF(this: &riff);
      return 1;
    }
    else
    {
LABEL_14:
      InFileRIFF::~InFileRIFF(this: &riff);
      return 0;
    }
  }
  else
  {
    InFileRIFF::~InFileRIFF(this: &riff);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413400
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::SaveManifest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::SaveManifest(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  signed int m_Size; // esi
  CUtlCachedFileData<CAudioSourceCachedInfo> *v2; // ebx
  int Inorder; // edi
  signed int v4; // ebx
  CSortedCacheFile *m_pMemory; // ecx
  CSortedCacheFile *v6; // ebx
  int *p_index; // edi
  const char *v8; // eax
  const char *v9; // eax
  void *v10; // eax
  void *v11; // esi
  char fn[512]; // [esp+Ch] [ebp-660h] BYREF
  char path[512]; // [esp+20Ch] [ebp-460h] BYREF
  char manifest_name[512]; // [esp+40Ch] [ebp-260h] BYREF
  char v15; // [esp+60Ch] [ebp-60h] BYREF
  CUtlBuffer buf; // [esp+614h] [ebp-58h] BYREF
  CSortedCacheFile insert; // [esp+644h] [ebp-28h] BYREF
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+64Ch] [ebp-20h] BYREF
  CUtlCachedFileData<CAudioSourceCachedInfo> *i; // [esp+668h] [ebp-4h]

  m_Size = 0;
  v2 = this;
  i = this;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  memset(&list, 0, 25);
  Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &v2->m_Elements);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      insert.handle = v2->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
      list.m_bNeedsSort = true;
      v4 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v4 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v4 + 1],
          src: &list.m_Memory.m_pMemory[v4],
          count: 8 * (m_Size - v4 - 1));
        m_pMemory = list.m_Memory.m_pMemory;
      }
      v6 = &m_pMemory[v4];
      if ( v6 != nullptr )
      {
        v6->handle = insert.handle;
        v6->index = Inorder;
      }
      Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                    this: &i->m_Elements,
                                    i: Inorder);
      if ( Inorder == 0xFFFF )
        break;
      v2 = i;
    }
    if ( list.m_bNeedsSort && m_Size > 1 )
    {
      insert.handle = list.m_pLessContext;
      insert.index = (int)&v15;
      qsort_s(
        base: list.m_Memory.m_pMemory,
        num: m_Size,
        width: 8u,
        comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper,
        context: &insert);
    }
    v2 = i;
  }
  if ( m_Size > 0 )
  {
    p_index = &list.m_Memory.m_pMemory->index;
    for ( i = (CUtlCachedFileData<CAudioSourceCachedInfo> *)m_Size;
          i != nullptr;
          i = (CUtlCachedFileData<CAudioSourceCachedInfo> *)((char *)i - 1) )
    {
      ((void (__stdcall *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *, char *, int))g_pFullFileSystem->String)(
        a1: &v2->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)p_index].m_Data,
        a2: fn,
        a3: 512);
      CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\"\r\n", fn);
      p_index += 2;
    }
  }
  v8 = CUtlString::operator char const *(this: &v2->m_sRepositoryFileName);
  V_strncpy(pDest: path, pSrc: v8, maxLen: 512);
  V_StripFilename(path);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: path, a3: "MOD");
  v9 = CUtlString::operator char const *(this: &v2->m_sRepositoryFileName);
  V_strncpy(pDest: manifest_name, pSrc: v9, maxLen: 512);
  V_SetExtension(path: manifest_name, extension: ".manifest", pathStringLength: 512);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD")
    && !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD") )
  {
    g_pFullFileSystem->SetFileWritable(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: manifest_name,
      a3: true,
      a4: "MOD");
  }
  v10 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "wb", a4: 0);
  v11 = v10;
  if ( v10 != nullptr )
  {
    g_pFullFileSystem->Write(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: buf.m_Memory.m_pMemory,
      a3: buf.m_Put,
      a4: v10);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v11);
  }
  else
  {
    _Warning(a1: "Unable to persist cache manifest '%s', check file permissions\n", manifest_name);
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00413750
// Name: public: void CUtlDict<struct CMasterCacheBuilder::CacheBuild_t,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CMasterCacheBuilder::CacheBuild_t,int>::RemoveAll(
        CUtlDict<CMasterCacheBuilder::CacheBuild_t,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004137A0
// Name: public: virtual void CAudioSourceWave::GetCacheData(class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::GetCacheData(CAudioSourceWave *this, CAudioSourceCachedInfo *info)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  CSentence *v5; // eax
  CSentence *v6; // ebx
  char v7; // al
  CSentence *m_pTempSentence; // ebx
  void *v9; // ebx
  char v10; // cl

  CAudioSourceWave::GetStartupData(this);
  info->infolong ^= (info->infolong ^ (4 * this->m_bits)) & 0x7C;
  v3 = info->infolong
     ^ ((unsigned __int16)info->infolong
      ^ (unsigned __int16)((unsigned __int16)this->m_channels << 7))
     & 0x180;
  info->infolong = v3;
  v4 = v3 ^ ((unsigned __int16)v3 ^ (unsigned __int16)((unsigned __int16)this->m_sampleSize << 9)) & 0xE00;
  info->infolong = v4;
  info->infolong = v4 ^ ((unsigned __int16)v4 ^ (unsigned __int16)((unsigned __int16)this->m_format << 12)) & 0x3000;
  info->m_dataStart = this->m_dataStart;
  info->m_dataSize = this->m_dataSize;
  info->infolong ^= (info->infolong ^ (this->m_rate << 14)) & 0x7FFFC000;
  info->m_loopStart = this->m_loopStart;
  info->m_sampleCount = this->m_sampleCount;
  if ( this->m_pTempSentence != nullptr )
  {
    v5 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v5 != nullptr )
      v6 = CSentence::CSentence(this: v5);
    else
      v6 = nullptr;
    CSentence::operator=(this: v6, src: this->m_pTempSentence);
    v7 = info->flagsbyte ^ (v6 != nullptr);
    info->m_pSentence = v6;
    info->flagsbyte ^= v7 & 1;
    m_pTempSentence = this->m_pTempSentence;
    if ( m_pTempSentence != nullptr )
    {
      CSentence::~CSentence(this: this->m_pTempSentence);
      free(pMem: m_pTempSentence);
    }
    this->m_pTempSentence = nullptr;
  }
  if ( this->m_pHeader != nullptr && this->m_nHeaderSize > 0 )
  {
    v9 = MemAlloc_Alloc(nSize: this->m_nHeaderSize);
    _V_memcpy(dest: v9, src: this->m_pHeader, count: this->m_nHeaderSize);
    v10 = info->flagsbyte ^ (4 * (v9 != nullptr));
    info->m_usHeaderSize = this->m_nHeaderSize;
    info->flagsbyte ^= v10 & 4;
    info->m_pHeader = (unsigned __int8 *)v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004138D0
// Name: public: virtual void CAudioSourceCachedInfo::Rebuild(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Rebuild(CAudioSourceCachedInfo *this, const char *filename)
{
  const char *FileExtension; // edi
  int m_dataSize; // ecx
  unsigned int v5; // edx
  bool v6; // sf
  CAudioSourceWave wave; // [esp+Ch] [ebp-68h] BYREF
  CAudioSourceMP3 mp3; // [esp+54h] [ebp-20h] BYREF

  g_bSoundRebuilt = true;
  CAudioSourceCachedInfo::Clear(this);
  FileExtension = V_GetFileExtension(path: filename);
  if ( _V_stricmp(s1: FileExtension, s2: "wav") != 0 )
  {
    if ( _V_stricmp(s1: FileExtension, s2: "mp3") != 0 )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_58E670, a2: FileExtension);
    }
    else
    {
      this->infolong = this->infolong & 0xFFFFFFFC | 2;
      CAudioSourceMP3::CAudioSourceMP3(this: &mp3, filename);
      m_dataSize = mp3.m_dataSize;
      v5 = this->infolong ^ (mp3.m_sampleRate << 14);
      this->m_dataStart = mp3.m_dataStart;
      this->infolong ^= v5 & 0x7FFFC000;
      v6 = mp3.m_filename.m_Storage.m_Memory.m_nGrowSize < 0;
      this->m_dataSize = m_dataSize;
      mp3.__vftable = (CAudioSourceMP3_vtbl *)&CAudioSourceMP3::`vftable';
      mp3.m_filename.m_Storage.m_nActualLength = 0;
      if ( !v6 && mp3.m_filename.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: mp3.m_filename.m_Storage.m_Memory.m_pMemory);
    }
  }
  else
  {
    this->infolong = this->infolong & 0xFFFFFFFC | 1;
    CAudioSourceWave::CAudioSourceWave(this: &wave, filename);
    CAudioSourceWave::GetCacheData(this: &wave, info: this);
    CAudioSourceWave::~CAudioSourceWave(this: &wave);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004139D0
// Name: public: CUtlCachedFileData<class CAudioSourceCachedInfo>::CUtlCachedFileData<class CAudioSourceCachedInfo>(char const __near *,int,unsigned int (*)(void),enum UtlCachedFileDataType_t,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CUtlCachedFileData<CAudioSourceCachedInfo> *__thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::CUtlCachedFileData<CAudioSourceCachedInfo>(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        const char *repositoryFileName,
        int version,
        unsigned int (__cdecl *checksumfunc)(),
        UtlCachedFileDataType_t fileCheckType,
        bool nevercheckdisk,
        bool readonly,
        bool savemanifest)
{
  char v9; // dl

  this->__vftable = (CUtlCachedFileData<CAudioSourceCachedInfo>_vtbl *)&CUtlCachedFileData<CAudioSourceCachedInfo>::`vftable';
  this->m_Elements.m_LessFunc = (bool (__cdecl *)(const CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *, const CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *))CDefOps<CDmAttribute *>::LessFunc;
  this->m_Elements.m_Elements.m_pMemory = nullptr;
  this->m_Elements.m_Elements.m_nAllocationCount = 0;
  this->m_Elements.m_Elements.m_nGrowSize = 0;
  this->m_Elements.m_pElements = this->m_Elements.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Elements.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Elements.m_FirstFree = -1;
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_sRepositoryFileName, pString: repositoryFileName);
  this->m_nVersion = version;
  this->m_pfnMetaChecksum = checksumfunc;
  this->m_fileCheckType = fileCheckType;
  v9 = *((_BYTE *)this + 84) & 0xE0;
  this->m_uCurrentMetaChecksum = 0;
  *((_BYTE *)this + 84) = nevercheckdisk | v9 | (2 * (readonly | (2 * savemanifest)));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413A60
// Name: public: virtual CUtlCachedFileData<class CAudioSourceCachedInfo>::~CUtlCachedFileData<class CAudioSourceCachedInfo>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::~CUtlCachedFileData<CAudioSourceCachedInfo>(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl*)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short> > *p_m_Elements; // ebx
  int m_Size; // eax
  int v4; // edi
  CAudioSourceCachedInfo *v5; // ecx
  CAudioSourceCachedInfo **m_pMemory; // eax
  int c; // [esp+Ch] [ebp-4h]

  p_m_Elements = &this->m_Elements;
  this->__vftable = (CUtlCachedFileData<CAudioSourceCachedInfo>_vtbl *)&CUtlCachedFileData<CAudioSourceCachedInfo>::`vftable';
  CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements);
  m_Size = this->m_Data.m_Size;
  v4 = 0;
  for ( c = m_Size; v4 < m_Size; ++v4 )
  {
    v5 = this->m_Data.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      ((void (__thiscall *)(CAudioSourceCachedInfo *, int))v5->dtr_CAudioSourceCachedInfo)(a1: v5, a2: 1);
      m_Size = c;
    }
  }
  this->m_Data.m_Size = 0;
  this->m_sRepositoryFileName.m_Storage.m_nActualLength = 0;
  if ( this->m_sRepositoryFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sRepositoryFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sRepositoryFileName.m_Storage.m_Memory.m_pMemory);
      this->m_sRepositoryFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sRepositoryFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Data.m_Size = 0;
  if ( this->m_Data.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Data.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Data.m_Memory.m_pMemory);
      this->m_Data.m_Memory.m_pMemory = nullptr;
    }
    this->m_Data.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  this->m_Data.m_pElements = m_pMemory;
  if ( this->m_Data.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Data.m_Memory.m_pMemory = nullptr;
    }
    this->m_Data.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: p_m_Elements);
  p_m_Elements->m_FirstFree = -1;
  if ( p_m_Elements->m_Elements.m_nGrowSize >= 0 )
  {
    if ( p_m_Elements->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Elements->m_Elements.m_pMemory);
      p_m_Elements->m_Elements.m_pMemory = nullptr;
    }
    p_m_Elements->m_Elements.m_nAllocationCount = 0;
  }
  p_m_Elements->m_LastAlloc.index = -1;
  if ( p_m_Elements->m_Elements.m_nGrowSize >= 0 )
  {
    if ( p_m_Elements->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Elements->m_Elements.m_pMemory);
      p_m_Elements->m_Elements.m_pMemory = nullptr;
    }
    p_m_Elements->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413BC0
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::Save(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Save(CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  void *v7; // eax
  void *v8; // edi
  const char *v9; // eax
  int m_Size; // ebx
  int Inorder; // ecx
  CSortedCacheFile *v12; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // ebx
  int fileinfo; // eax
  CAudioSourceCachedInfo *v15; // ecx
  char fn[512]; // [esp+Ch] [ebp-470h] BYREF
  char path[512]; // [esp+20Ch] [ebp-270h] BYREF
  char v18; // [esp+40Ch] [ebp-70h] BYREF
  int inputBuffer; // [esp+410h] [ebp-6Ch] BYREF
  CUtlBuffer buf; // [esp+414h] [ebp-68h] BYREF
  int c; // [esp+444h] [ebp-38h] BYREF
  int j; // [esp+448h] [ebp-34h]
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+44Ch] [ebp-30h] BYREF
  CSortedCacheFile insert; // [esp+468h] [ebp-14h] BYREF
  int v; // [esp+470h] [ebp-Ch] BYREF
  int bufsize; // [esp+474h] [ebp-8h] BYREF
  int i; // [esp+478h] [ebp-4h]

  v2 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  V_strncpy(pDest: path, pSrc: v2, maxLen: 512);
  V_StripFilename(path);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: path, a3: "MOD");
  v3 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: "MOD") )
  {
    v4 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    if ( !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4, a3: "MOD") )
    {
      v5 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      g_pFullFileSystem->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: true, a4: "MOD");
    }
  }
  v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  v7 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6, a3: "wb", a4: 0);
  v8 = v7;
  if ( v7 != nullptr )
  {
    *((_BYTE *)this + 84) &= ~8u;
    v = 2;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v7);
    v = this->m_nVersion;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v8);
    v = this->m_uCurrentMetaChecksum;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v8);
    c = this->m_Elements.m_NumElements;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &c, a3: 4, a4: v8);
    m_Size = 0;
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    memset(&list, 0, 25);
    Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements);
    i = Inorder;
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        insert.handle = this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
        list.m_bNeedsSort = true;
        bufsize = m_Size;
        if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
            this: (CUtlMemory<ResourceEntryInfo,int> *)&list,
            num: m_Size - list.m_Memory.m_nAllocationCount + 1);
          m_Size = list.m_Size;
          Inorder = i;
        }
        ++m_Size;
        list.m_pElements = list.m_Memory.m_pMemory;
        list.m_Size = m_Size;
        if ( m_Size - bufsize - 1 > 0 )
        {
          _V_memmove(
            dest: &list.m_Memory.m_pMemory[bufsize + 1],
            src: &list.m_Memory.m_pMemory[bufsize],
            count: 8 * (m_Size - bufsize - 1));
          Inorder = i;
        }
        v12 = &list.m_Memory.m_pMemory[bufsize];
        if ( v12 != nullptr )
        {
          v12->handle = insert.handle;
          v12->index = Inorder;
        }
        i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_Elements,
                                i: Inorder);
        if ( i == 0xFFFF )
          break;
        Inorder = i;
      }
      if ( list.m_bNeedsSort && m_Size > 1 )
      {
        insert.handle = list.m_pLessContext;
        insert.index = (int)&v18;
        qsort_s(
          base: list.m_Memory.m_pMemory,
          num: m_Size,
          width: 8u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper,
          context: &insert);
      }
    }
    if ( m_Size > 0 )
    {
      i = (int)&list.m_Memory.m_pMemory->index;
      for ( j = m_Size; j != 0; --j )
      {
        p_m_Data = &this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)i].m_Data;
        CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
        g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)p_m_Data, a3: fn, a4: 512);
        CUtlBuffer::PutString(this: &buf, pString: fn);
        fileinfo = p_m_Data->fileinfo;
        insert.index = fileinfo;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%d", fileinfo);
        }
        else
        {
          inputBuffer = fileinfo;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &buf.m_Byteswap,
                outputBuffer: (int *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = insert.index;
            buf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        v15 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
        v15->Save(this: v15, a2: &buf);
        bufsize = buf.m_Put;
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bufsize, a3: 4, a4: v8);
        g_pFullFileSystem->Write(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: buf.m_Memory.m_pMemory,
          a3: bufsize,
          a4: v8);
        i += 8;
      }
    }
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
    if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  else
  {
    v9 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Warning(a1: "Unable to persist cache '%s', check file permissions\n", v9);
  }
  if ( (*((_BYTE *)this + 84) & 4) != 0 )
    CUtlCachedFileData<CAudioSourceCachedInfo>::SaveManifest(this);
}

//------------------------------------------------------------------------------
// Address: 0x004140D0
// Name: private: int CUtlCachedFileData<class CAudioSourceCachedInfo>::GetIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  int result; // eax
  CAudioSourceCachedInfo *v4; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAudioSourceCachedInfo **m_pMemory; // ecx
  int v8; // eax
  CAudioSourceCachedInfo **v9; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t element; // [esp+8h] [ebp-14h] BYREF
  CAudioSourceCachedInfo *data; // [esp+24h] [ebp+8h]

  element.handle = nullptr;
  element.fileinfo = 0;
  element.diskfileinfo = -2;
  element.dataIndex = -1;
  element.handle = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: filename);
  result = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_Elements,
             search: &element);
  if ( (unsigned __int16)result == 0xFFFF )
  {
    v4 = (CAudioSourceCachedInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
    if ( v4 != nullptr )
    {
      v4->__vftable = (CAudioSourceCachedInfo_vtbl *)&CAudioSourceCachedInfo::`vftable';
      v4->infolong = 0;
      v4->flagsbyte = 0;
      v4->m_loopStart = 0;
      v4->m_sampleCount = 0;
      v4->m_dataStart = 0;
      v4->m_dataSize = 0;
      *(_DWORD *)&v4->m_usCachedDataSize = 0;
      v4->m_pSentence = nullptr;
      v4->m_pCachedData = nullptr;
      v4->m_pHeader = nullptr;
      data = v4;
    }
    else
    {
      data = nullptr;
    }
    m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
    m_Size = this->m_Data.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_Data,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Data.m_Size;
    m_pMemory = this->m_Data.m_Memory.m_pMemory;
    v8 = this->m_Data.m_Size - m_Size - 1;
    this->m_Data.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_Data.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = data;
    result = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::Insert(
               this: &this->m_Elements,
               a2: (const char *)m_Size,
               insert: &element);
    this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)result].m_Data.dataIndex = m_Size;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004141E0
// Name: public: int CUtlMap<char const __near *,struct CMasterCacheBuilder::CacheBuild_t,int>::Insert(char const __near * const __near &,struct CMasterCacheBuilder::CacheBuild_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Insert@<eax>(
        CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        const CMasterCacheBuilder::CacheBuild_t *insert)
{
  void *m_RelativePath; // edx
  int v6; // esi
  CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t node; // [esp+4h] [ebp-34h] BYREF

  node.elem.m_Info.infolong = 0;
  node.elem.m_Info.flagsbyte = 0;
  memset(&node.elem.m_Info.m_loopStart, 0, 32);
  m_RelativePath = insert->m_RelativePath;
  node.key = *key;
  node.elem.m_Info.__vftable = (CAudioSourceCachedInfo_vtbl *)&CAudioSourceCachedInfo::`vftable';
  node.elem.m_RelativePath = m_RelativePath;
  CAudioSourceCachedInfo::operator=(this: &node.elem.m_Info, src: &insert->m_Info);
  v6 = CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::Insert(
         this: &this->m_Tree,
         a2,
         insert: &node);
  node.elem.m_Info.__vftable = (CAudioSourceCachedInfo_vtbl *)&CAudioSourceCachedInfo::`vftable';
  CAudioSourceCachedInfo::Clear(this: &node.elem.m_Info);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00414260
// Name: private: void CUtlCachedFileData<class CAudioSourceCachedInfo>::InitSmallBuffer(void __near * __near &,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::InitSmallBuffer(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        void **fh,
        int fileSize,
        bool *deleteFile)
{
  int Int; // eax
  const char *v6; // eax
  int v7; // esi
  int v8; // esi
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // esi
  int v10; // eax
  CAudioSourceCachedInfo *v11; // ecx
  const char *v12; // eax
  const char *v13; // eax
  char elementFileName[512]; // [esp+Ch] [ebp-264h] BYREF
  CUtlBuffer loadBuf; // [esp+20Ch] [ebp-64h] BYREF
  CUtlBuffer buf; // [esp+23Ch] [ebp-34h] BYREF
  int cacheversion; // [esp+26Ch] [ebp-4h] BYREF
  bool *deleteFilea; // [esp+280h] [ebp+10h]

  *deleteFile = false;
  CUtlBuffer::CUtlBuffer(this: &loadBuf, growSize: 0, initSize: 0, nFlags: 0);
  g_pFullFileSystem->ReadToBuffer(this: g_pFullFileSystem, a2: *fh, a3: &loadBuf, a4: 0, a5: nullptr);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: *fh);
  cacheversion = 0;
  CUtlBuffer::Get(this: &loadBuf, pMem: &cacheversion, size: 4);
  if ( cacheversion != 2 )
  {
    v13 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    DevMsg(a1: "Discarding repository '%s' due to cache system version change\n", v13);
    goto LABEL_17;
  }
  if ( CUtlBuffer::GetInt(this: &loadBuf) != this->m_nVersion )
  {
    v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Msg(a1: "Discarding repository '%s' due to version change\n", v12);
    *deleteFile = true;
    goto LABEL_18;
  }
  Int = CUtlBuffer::GetInt(this: &loadBuf);
  if ( this->m_pfnMetaChecksum != nullptr && Int != this->m_uCurrentMetaChecksum )
  {
    v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Msg(a1: "Discarding repository '%s' due to meta checksum change\n", v6);
LABEL_17:
    *deleteFile = true;
    goto LABEL_18;
  }
  v7 = CUtlBuffer::GetInt(this: &loadBuf);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( v7 > 0 )
  {
    for ( deleteFilea = (bool *)v7; deleteFilea != nullptr; --deleteFilea )
    {
      v8 = CUtlBuffer::GetInt(this: &loadBuf);
      memset(&buf.m_Get, 0, 9);
      buf.m_nOffset = 0;
      buf.m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
      CUtlBuffer::EnsureCapacity(this: &buf, num: v8);
      CUtlBuffer::Get(this: &loadBuf, pMem: buf.m_Memory.m_pMemory, size: v8);
      CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v8);
      CUtlBuffer::GetString(this: &buf, pString: elementFileName, nMaxChars: 512);
      p_m_Data = &this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(
                                                                            this,
                                                                            filename: (CAudioSourceCachedInfo *)elementFileName)].m_Data;
      v10 = CUtlBuffer::GetInt(this: &buf);
      p_m_Data->fileinfo = v10;
      if ( v10 == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
        p_m_Data->fileinfo = 0;
      v11 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
      v11->Restore(this: v11, a2: &buf);
    }
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
LABEL_18:
  if ( loadBuf.m_Memory.m_nGrowSize >= 0 && loadBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00414460
// Name: private: void CUtlCachedFileData<class CAudioSourceCachedInfo>::InitLargeBuffer(void __near * __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::InitLargeBuffer(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        void **fh,
        bool *deleteFile)
{
  void **v3; // edi
  const char *v5; // eax
  int v6; // edi
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // edi
  int Int; // eax
  CAudioSourceCachedInfo *v9; // ecx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  void *v13; // [esp-4h] [ebp-258h]
  void *v14; // [esp-4h] [ebp-258h]
  void *v15; // [esp-4h] [ebp-258h]
  void *v16; // [esp-4h] [ebp-258h]
  void *v17; // [esp-4h] [ebp-258h]
  char elementFileName[512]; // [esp+Ch] [ebp-248h] BYREF
  CUtlBuffer buf; // [esp+20Ch] [ebp-48h] BYREF
  unsigned int cache_meta_checksum; // [esp+23Ch] [ebp-18h] BYREF
  int cacheversion; // [esp+240h] [ebp-14h] BYREF
  int i; // [esp+244h] [ebp-10h]
  int version; // [esp+248h] [ebp-Ch] BYREF
  int count; // [esp+24Ch] [ebp-8h] BYREF
  int bufsize; // [esp+250h] [ebp-4h] BYREF

  v3 = fh;
  *deleteFile = false;
  v13 = *fh;
  cacheversion = 0;
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &cacheversion, a3: 4, a4: v13);
  if ( cacheversion == 2 )
  {
    v14 = *fh;
    version = 0;
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &version, a3: 4, a4: v14);
    if ( version == this->m_nVersion )
    {
      v15 = *fh;
      cache_meta_checksum = 0;
      g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &cache_meta_checksum, a3: 4, a4: v15);
      if ( this->m_pfnMetaChecksum == nullptr || cache_meta_checksum == this->m_uCurrentMetaChecksum )
      {
        v16 = *fh;
        count = 0;
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &count, a3: 4, a4: v16);
        CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
        i = 0;
        if ( count > 0 )
        {
          while ( 1 )
          {
            v17 = *v3;
            bufsize = 0;
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bufsize, a3: 4, a4: v17);
            if ( bufsize > 1000000 )
              break;
            memset(&buf.m_Get, 0, 9);
            buf.m_nOffset = 0;
            buf.m_nMaxPut = -1;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
            CUtlBuffer::EnsureCapacity(this: &buf, num: bufsize);
            v6 = g_pFullFileSystem->Read(
                   this: &g_pFullFileSystem->IBaseFileSystem,
                   a2: buf.m_Memory.m_pMemory,
                   a3: bufsize,
                   a4: *v3);
            CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
            CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v6);
            CUtlBuffer::GetString(this: &buf, pString: elementFileName, nMaxChars: 512);
            p_m_Data = &this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(
                                                                                  this,
                                                                                  filename: (CAudioSourceCachedInfo *)elementFileName)].m_Data;
            Int = CUtlBuffer::GetInt(this: &buf);
            p_m_Data->fileinfo = Int;
            if ( Int == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
              p_m_Data->fileinfo = 0;
            v9 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
            v9->Restore(this: v9, a2: &buf);
            v3 = fh;
            if ( ++i >= count )
              goto LABEL_14;
          }
          v10 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
          _Msg(a1: "Discarding repository '%s' due to corruption\n", v10);
          *deleteFile = true;
        }
LABEL_14:
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      }
      else
      {
        v5 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
        _Msg(a1: "Discarding repository '%s' due to meta checksum change\n", v5);
        *deleteFile = true;
      }
    }
    else
    {
      v11 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      _Msg(a1: "Discarding repository '%s' due to version change\n", v11);
      *deleteFile = true;
    }
  }
  else
  {
    v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    DevMsg(a1: "Discarding repository '%s' due to cache system version change\n", v12);
    *deleteFile = true;
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: *v3);
}

//------------------------------------------------------------------------------
// Address: 0x004146D0
// Name: public: bool CMasterCacheBuilder::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterCacheBuilder::Init(
        CMasterCacheBuilder *this,
        const char *pModPath,
        const char *pLanguageSuffix,
        bool bQuiet)
{
  CMasterCacheBuilder *v4; // edi
  ELanguage v6; // eax
  CFmtStrN<256> *v7; // eax
  KeyValues *v8; // eax
  IBaseFileSystem *v9; // eax
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // eax
  int m_Size; // esi
  KeyValues *FirstValue; // ebx
  const char *String; // edi
  const char *LanguageShortName; // eax
  CFmtStrN<256> *v17; // eax
  CUtlString *m_pMemory; // edi
  CUtlString *v19; // edi
  const char *v20; // eax
  int v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  CFmtStrN<256> *v24; // eax
  CFmtStrN<256> v26; // [esp+Ch] [ebp-240h] BYREF
  CFmtStrN<256> v27; // [esp+118h] [ebp-134h] BYREF
  CUtlString szFullSearchPath; // [esp+224h] [ebp-28h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vSearchPaths; // [esp+234h] [ebp-18h] BYREF
  CMasterCacheBuilder *v30; // [esp+248h] [ebp-4h]
  const char *pPathID; // [esp+254h] [ebp+8h]
  ELanguage eAudioLanguage; // [esp+258h] [ebp+Ch]
  KeyValues *modinfo; // [esp+25Ch] [ebp+10h]

  v4 = this;
  v30 = this;
  CUtlString::operator=(this: &this->m_szModPath, src: pModPath);
  v4->m_bQuiet = bQuiet;
  CMasterCacheBuilder::Spew(this: v4, pFmt: "CMasterCacheBuilder: Init\n");
  CUtlString::operator=(this: &v4->m_szCurrentLanguage, src: pDefaultValue);
  if ( pLanguageSuffix != nullptr && *pLanguageSuffix != 0 && _V_stricmp(s1: pLanguageSuffix, s2: "english") != 0 )
  {
    v6 = PchLanguageToELanguage(pchShortName: pLanguageSuffix);
    eAudioLanguage = v6;
    if ( v6 != k_Lang_None && v6 != k_Lang_English )
    {
      v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "_%s", pLanguageSuffix);
      CUtlString::operator=(this: &v4->m_szCurrentLanguage, src: v7->m_szBuf);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        modinfo = KeyValues::KeyValues(this: v8, setName: "ModInfo");
      else
        modinfo = nullptr;
      if ( g_pFullFileSystem != nullptr )
        v9 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v9 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: modinfo,
             filesystem: v9,
             resourceName: "gameinfo.txt",
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        memset(&v27.m_szBuf[3], 0, 260);
        v10 = CUtlString::operator char const *(this: &v4->m_szModPath);
        V_strncpy(pDest: &v27.m_szBuf[3], pSrc: v10, maxLen: 260);
        V_StripLastDir(dirName: &v27.m_szBuf[3], maxlen: 260);
        V_StripLastDir(dirName: &v27.m_szBuf[3], maxlen: 260);
        V_StripTrailingSlash(ppath: &v27.m_szBuf[3]);
        Key = KeyValues::FindKey(this: modinfo, keyName: "FileSystem", bCreate: false);
        v12 = KeyValues::FindKey(this: Key, keyName: "SearchPaths", bCreate: false);
        m_Size = 0;
        memset(&vSearchPaths, 0, sizeof(vSearchPaths));
        FirstValue = KeyValues::GetFirstValue(this: v12);
        if ( FirstValue != nullptr )
        {
          do
          {
            pPathID = KeyValues::GetName(this: FirstValue);
            String = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: pDefaultValue);
            if ( _V_stricmp(s1: pPathID, s2: "game") == 0 && _V_strstr(s1: String, search: "|gameinfo_path|") == nullptr )
            {
              CUtlString::CUtlString(this: &szFullSearchPath);
              LanguageShortName = GetLanguageShortName(eLang: eAudioLanguage);
              v17 = CFmtStrN<256>::CFmtStrN<256>(
                      this: &v26,
                      pszFormat: "%s%clocalization%c%s_%s%c",
                      &v27.m_szBuf[3],
                      92,
                      92,
                      String,
                      LanguageShortName,
                      92);
              CUtlString::operator=(this: &szFullSearchPath, src: v17->m_szBuf);
              if ( m_Size + 1 > vSearchPaths.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<ResourceCopy_t,int>::Grow(
                  this: (CUtlMemory<ResourceCopy_t,int> *)&vSearchPaths,
                  num: m_Size - vSearchPaths.m_Memory.m_nAllocationCount + 1);
                m_Size = vSearchPaths.m_Size;
              }
              m_pMemory = vSearchPaths.m_Memory.m_pMemory;
              vSearchPaths.m_Size = ++m_Size;
              vSearchPaths.m_pElements = vSearchPaths.m_Memory.m_pMemory;
              if ( m_Size - 1 > 0 )
                _V_memmove(
                  dest: &vSearchPaths.m_Memory.m_pMemory[1],
                  src: vSearchPaths.m_Memory.m_pMemory,
                  count: 16 * (m_Size - 1));
              if ( m_pMemory != nullptr )
                CUtlString::CUtlString(this: m_pMemory, string: &szFullSearchPath);
              CUtlString::~CUtlString(this: &szFullSearchPath);
            }
            FirstValue = KeyValues::GetNextValue(this: FirstValue);
          }
          while ( FirstValue != nullptr );
          v4 = v30;
        }
        if ( m_Size > 0 )
        {
          v19 = vSearchPaths.m_Memory.m_pMemory;
          do
          {
            v20 = CUtlString::operator char const *(this: v19);
            g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: v20, a3: "GAME", a4: PATH_ADD_TO_HEAD);
            ++v19;
            --m_Size;
          }
          while ( m_Size != 0 );
          v4 = v30;
        }
        g_pFullFileSystem->PrintSearchPaths(this: g_pFullFileSystem);
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vSearchPaths);
      }
      KeyValues::deleteThis(this: modinfo);
    }
  }
  CMasterCacheBuilder::Spew(
    this: v4,
    pFmt: "Audio Caches using '%s' as suffix\n",
    (const char *)v4->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: "maps/soundcache", a3: "MOD");
  if ( v4->m_pMasterSoundCache != nullptr )
    v4->m_pMasterSoundCache = nullptr;
  CUtlString::operator=(this: &v4->m_szMODPath, src: g_szModPath);
  v21 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v21 + 40))(a1: v21, a2: "-tempcontent") != 0 )
  {
    v22 = CUtlString::operator char const *(this: &v4->m_szMODPath);
    V_strncpy(pDest: &v27.m_szBuf[3], pSrc: v22, maxLen: 260);
    V_StripTrailingSlash(ppath: &v27.m_szBuf[3]);
    V_strncat(pDest: &v27.m_szBuf[3], pSrc: "_tempcontent/", destBufferSize: 0x104u, max_chars_to_copy: -1);
    CUtlString::operator=(this: &v4->m_szMODPath, src: &v27.m_szBuf[3]);
    v23 = CUtlString::operator char const *(this: &v4->m_szMODPath);
    v24 = CFmtStrN<256>::CFmtStrN<256>(this: &v26, pszFormat: "%s%s", v23, "maps/soundcache");
    g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: v24->m_szBuf, a3: "GAME");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414AB0
// Name: public: void CMasterCacheBuilder::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterCacheBuilder::Shutdown(CMasterCacheBuilder *this)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // esi
  char v3; // al
  char v4; // al
  CUtlCachedFileData<CAudioSourceCachedInfo> *v5; // ecx

  CMasterCacheBuilder::Spew(this, pFmt: "CMasterCacheBuilder: Shutdown\n");
  m_pMasterSoundCache = this->m_pMasterSoundCache;
  if ( m_pMasterSoundCache != nullptr )
  {
    v3 = *((_BYTE *)m_pMasterSoundCache + 84);
    if ( (v3 & 0x10) != 0 )
    {
      v4 = v3 & 0xEF;
      *((_BYTE *)m_pMasterSoundCache + 84) = v4;
      if ( (v4 & 8) != 0 )
      {
        CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this: m_pMasterSoundCache);
      }
      else if ( (v4 & 4) != 0 && !CUtlCachedFileData<CAudioSourceCachedInfo>::ManifestExists(this: m_pMasterSoundCache) )
      {
        CUtlCachedFileData<CAudioSourceCachedInfo>::SaveManifest(this: m_pMasterSoundCache);
      }
      CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &m_pMasterSoundCache->m_Elements);
    }
    v5 = this->m_pMasterSoundCache;
    if ( v5 != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))v5->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: v5,
        a2: 1);
  }
  if ( this->m_pMasterSoundCache != nullptr )
    this->m_pMasterSoundCache = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00414B20
// Name: public: class CAudioSourceCachedInfo __near * CUtlCachedFileData<class CAudioSourceCachedInfo>::Get(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Get(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  unsigned __int16 Index; // ax
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *m_pMemory; // ecx
  int v5; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // esi
  IBaseFileSystem_vtbl *v7; // edx
  IBaseFileSystem *v8; // ecx
  int v9; // eax
  CAudioSourceCachedInfo *v10; // ebx
  char v11; // al
  int cachefileinfo; // [esp+Ch] [ebp-4h]

  Index = CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(this, filename);
  m_pMemory = this->m_Elements.m_Elements.m_pMemory;
  v5 = Index;
  p_m_Data = &m_pMemory[v5].m_Data;
  if ( m_pMemory[v5].m_Data.fileinfo == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
    m_pMemory[v5].m_Data.fileinfo = 0;
  cachefileinfo = m_pMemory[v5].m_Data.fileinfo;
  if ( m_pMemory[v5].m_Data.diskfileinfo == -2 )
  {
    if ( (*((_BYTE *)this + 84) & 1) != 0 )
    {
      m_pMemory[v5].m_Data.diskfileinfo = m_pMemory[v5].m_Data.fileinfo;
    }
    else
    {
      v7 = g_pFullFileSystem->IBaseFileSystem::__vftable;
      v8 = &g_pFullFileSystem->IBaseFileSystem;
      if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
      {
        v9 = v7->Size(this: v8, a2: (const char *)filename, a3: "GAME");
        p_m_Data->diskfileinfo = v9;
        if ( v9 == -1 )
          p_m_Data->diskfileinfo = 0;
      }
      else
      {
        p_m_Data->diskfileinfo = v7->GetFileTime(this: v8, a2: (const char *)filename, a3: "GAME");
      }
    }
  }
  v10 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
  if ( cachefileinfo != p_m_Data->diskfileinfo )
  {
    v11 = *((_BYTE *)this + 84);
    if ( (v11 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v11 | 8;
      v10->Rebuild(this: v10, a2: (const char *)filename);
    }
    p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00414BE0
// Name: public: int CUtlDict<struct CMasterCacheBuilder::CacheBuild_t,int>::Insert(char const __near *,struct CMasterCacheBuilder::CacheBuild_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CMasterCacheBuilder::CacheBuild_t,int>::Insert(
        CUtlDict<CMasterCacheBuilder::CacheBuild_t,int> *this,
        char *pName,
        const CMasterCacheBuilder::CacheBuild_t *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Insert(
           this: &this->m_Elements,
           a2: v3,
           key: (const char **)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x00414C40
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::CheckDiskInfo(bool,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::CheckDiskInfo(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        bool forcerebuild,
        int cacheFileTime)
{
  CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl*)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short> > *p_m_Elements; // ecx
  int i; // esi
  CSortedCacheFile *v6; // esi
  int m_Size; // ebx
  int Inorder; // edx
  void *handle; // ecx
  int v10; // esi
  CSortedCacheFile *m_pMemory; // ecx
  _DWORD *p_handle; // esi
  int v13; // esi
  int *v14; // ebx
  int v15; // eax
  int *p_index; // ebx
  int v17; // eax
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *v18; // ecx
  int p_m_Data; // esi
  IBaseFileSystem *v20; // ecx
  int v21; // eax
  const char *v22; // [esp+0h] [ebp-238h]
  char fn[512]; // [esp+Ch] [ebp-22Ch] BYREF
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+20Ch] [ebp-2Ch] BYREF
  int listEnd; // [esp+228h] [ebp-10h]
  int v26; // [esp+22Ch] [ebp-Ch]
  int pathIndex; // [esp+230h] [ebp-8h]
  bool bSteam; // [esp+237h] [ebp-1h]
  int bCheck; // [esp+240h] [ebp+8h]
  int *bChecka; // [esp+240h] [ebp+8h]
  bool bCheck_3; // [esp+243h] [ebp+Bh]

  p_m_Elements = &this->m_Elements;
  if ( forcerebuild )
  {
    for ( i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: p_m_Elements);
          i != 0xFFFF;
          i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                  this: &this->m_Elements,
                                  i) )
    {
      g_pFullFileSystem->String(
        this: g_pFullFileSystem,
        a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)i].m_Data,
        a3: fn,
        a4: 512);
      CUtlCachedFileData<CAudioSourceCachedInfo>::Get(this, filename: (CAudioSourceCachedInfo *)fn);
    }
    return;
  }
  v6 = nullptr;
  m_Size = 0;
  memset(&list, 0, 25);
  Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: p_m_Elements);
  bCheck = Inorder;
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      handle = this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
      pathIndex = (int)&this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data;
      listEnd = (int)handle;
      list.m_bNeedsSort = true;
      v10 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
        Inorder = bCheck;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v10 + 1],
          src: &list.m_Memory.m_pMemory[v10],
          count: 8 * (m_Size - v10 - 1));
        Inorder = bCheck;
        m_pMemory = list.m_Memory.m_pMemory;
      }
      p_handle = &m_pMemory[v10].handle;
      if ( p_handle != nullptr )
      {
        *p_handle = listEnd;
        p_handle[1] = Inorder;
      }
      if ( (*((_BYTE *)this + 84) & 1) != 0 && *(_DWORD *)(pathIndex + 8) == -2 )
        *(_DWORD *)(pathIndex + 8) = *(_DWORD *)(pathIndex + 4);
      bCheck = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                   this: &this->m_Elements,
                                   i: Inorder);
      if ( bCheck == 0xFFFF )
        break;
      Inorder = bCheck;
    }
    if ( m_Size != 0 && (*((_BYTE *)this + 84) & 1) == 0 )
    {
      v13 = 0;
      bSteam = g_pFullFileSystem->IsSteam(this: g_pFullFileSystem);
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          bChecka = &list.m_Memory.m_pMemory[v13].index;
          pathIndex = g_pFullFileSystem->GetPathIndex(
                        this: g_pFullFileSystem,
                        a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)bChecka].m_Data);
          v26 = v13;
          if ( v13 < m_Size )
          {
            v14 = bChecka;
            do
            {
              v15 = g_pFullFileSystem->GetPathIndex(
                      this: g_pFullFileSystem,
                      a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)v14].m_Data);
              if ( v15 != pathIndex )
                break;
              v14 += 2;
              ++v26;
            }
            while ( v26 < list.m_Size );
          }
          p_index = &list.m_Memory.m_pMemory[v13].index;
          g_pFullFileSystem->String(
            this: g_pFullFileSystem,
            a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)p_index].m_Data,
            a3: fn,
            a4: 512);
          V_StripFilename(path: fn);
          bCheck_3 = true;
          if ( !bSteam )
            bCheck_3 = g_pFullFileSystem->GetPathTime(this: g_pFullFileSystem, a2: fn, a3: "GAME") > cacheFileTime;
          v17 = v26;
          if ( v13 < v26 )
          {
            pathIndex = v26 - v13;
            do
            {
              v18 = this->m_Elements.m_Elements.m_pMemory;
              p_m_Data = (int)&v18[*(unsigned __int16 *)p_index].m_Data;
              if ( v18[*(unsigned __int16 *)p_index].m_Data.diskfileinfo == -2 )
              {
                if ( bCheck_3 )
                {
                  ((void (__thiscall *)(IFileSystem *, int, char *, int, const char *))g_pFullFileSystem->String)(
                    a1: g_pFullFileSystem,
                    a2: p_m_Data,
                    a3: fn,
                    a4: 512,
                    a5: v22);
                  v20 = &g_pFullFileSystem->IBaseFileSystem;
                  v22 = "GAME";
                  if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
                  {
                    v21 = ((int (__thiscall *)(IBaseFileSystem *, char *))v20->Size)(a1: v20, a2: fn);
                    *(_DWORD *)(p_m_Data + 8) = v21;
                    if ( v21 == -1 )
                      *(_DWORD *)(p_m_Data + 8) = 0;
                  }
                  else
                  {
                    *(_DWORD *)(p_m_Data + 8) = ((int (__thiscall *)(IBaseFileSystem *, char *))v20->GetFileTime)(
                                                  a1: v20,
                                                  a2: fn);
                  }
                }
                else
                {
                  *(_DWORD *)(p_m_Data + 8) = *(_DWORD *)(p_m_Data + 4);
                }
              }
              p_index += 2;
              --pathIndex;
            }
            while ( pathIndex != 0 );
            v17 = v26;
          }
          v13 = v17 + 1;
          if ( v17 + 1 >= list.m_Size )
            break;
          m_Size = list.m_Size;
        }
      }
      if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      return;
    }
    v6 = list.m_Memory.m_pMemory;
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00414FA0
// Name: private: void CMasterCacheBuilder::RecursiveBuildSoundList(class CUtlDict<struct CMasterCacheBuilder::CacheBuild_t,int> __near &,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterCacheBuilder::RecursiveBuildSoundList(
        CMasterCacheBuilder *this,
        CUtlDict<CMasterCacheBuilder::CacheBuild_t,int> *root,
        const char *pLanguage,
        const char *pCurrentDir,
        const char *pathID)
{
  const char *v6; // esi
  void *(__thiscall *FindOrAddFileName)(IFileSystem *, const char *); // edx
  char path[512]; // [esp+Ch] [ebp-640h] BYREF
  char fullpath[260]; // [esp+20Ch] [ebp-440h] BYREF
  char relative[512]; // [esp+310h] [ebp-33Ch] BYREF
  char ext[260]; // [esp+510h] [ebp-13Ch] BYREF
  CMasterCacheBuilder::CacheBuild_t build; // [esp+614h] [ebp-38h] BYREF
  CMasterCacheBuilder *v13; // [esp+644h] [ebp-8h]
  int fh; // [esp+648h] [ebp-4h] BYREF
  char bHasPlatformExtension_3; // [esp+65Fh] [ebp+13h]

  v13 = this;
  V_snprintf(pDest: path, maxLen: 512, pFormat: "%s/*.*", pCurrentDir);
  V_FixSlashes(pname: path, separator: 92);
  v6 = g_pFullFileSystem->FindFirstEx(this: g_pFullFileSystem, a2: path, a3: pathID, a4: &fh);
  if ( v6 != nullptr )
  {
    do
    {
      if ( *v6 != 46 )
      {
        if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: fh) )
        {
          V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/%s", pCurrentDir, v6);
          CMasterCacheBuilder::RecursiveBuildSoundList(this: v13, root, pLanguage, pCurrentDir: relative, pathID);
        }
        else
        {
          V_ExtractFileExtension(path: v6, dest: ext, destSize: 260);
          if ( V_stristr(pStr: v6, pSearch: ".360.") != nullptr
            || (bHasPlatformExtension_3 = 0, V_stristr(pStr: v6, pSearch: ".ps3.") != nullptr) )
          {
            bHasPlatformExtension_3 = 1;
          }
          if ( (_V_stricmp(s1: ext, s2: "wav") == 0 || _V_stricmp(s1: ext, s2: "mp3") == 0)
            && bHasPlatformExtension_3 == 0 )
          {
            V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/%s", pCurrentDir, v6);
            V_FixSlashes(pname: relative, separator: 92);
            FindOrAddFileName = g_pFullFileSystem->FindOrAddFileName;
            build.m_Info.__vftable = (CAudioSourceCachedInfo_vtbl *)&CAudioSourceCachedInfo::`vftable';
            build.m_Info.infolong = 0;
            build.m_Info.flagsbyte = 0;
            memset(&build.m_Info.m_loopStart, 0, 32);
            build.m_RelativePath = FindOrAddFileName(this: g_pFullFileSystem, a2: relative);
            g_pFullFileSystem->RelativePathToFullPath(
              this: g_pFullFileSystem,
              a2: relative,
              a3: pathID,
              a4: fullpath,
              a5: 260,
              a6: FILTER_NONE,
              a7: nullptr);
            CUtlDict<CMasterCacheBuilder::CacheBuild_t,int>::Insert(this: root, pName: fullpath, element: &build);
            build.m_Info.__vftable = (CAudioSourceCachedInfo_vtbl *)&CAudioSourceCachedInfo::`vftable';
            CAudioSourceCachedInfo::Clear(this: &build.m_Info);
          }
        }
      }
      v6 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: fh);
    }
    while ( v6 != nullptr );
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: fh);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004151D0
// Name: public: bool CUtlCachedFileData<class CAudioSourceCachedInfo>::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CUtlCachedFileData<CAudioSourceCachedInfo>::Init@<al>(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this@<ecx>,
        const char *a2@<ebx>)
{
  char v3; // al
  int (*m_pfnMetaChecksum)(void); // eax
  unsigned int v6; // eax
  const char *v7; // eax
  void *v8; // edi
  char v9; // al
  const char *v10; // eax
  int v11; // eax
  const char *v12; // eax
  int fileTime; // [esp+4h] [ebp-Ch]
  void *fh; // [esp+8h] [ebp-8h] BYREF
  bool deletefile; // [esp+Fh] [ebp-1h] BYREF

  v3 = *((_BYTE *)this + 84);
  if ( (v3 & 0x10) != 0 )
    return 1;
  *((_BYTE *)this + 84) = v3 | 0x10;
  if ( CUtlString::Length(this: &this->m_sRepositoryFileName) == 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_58E804, a2);
    return 0;
  }
  m_pfnMetaChecksum = (int (*)(void))this->m_pfnMetaChecksum;
  if ( m_pfnMetaChecksum != nullptr )
    v6 = m_pfnMetaChecksum();
  else
    v6 = 0;
  this->m_uCurrentMetaChecksum = v6;
  v7 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  v8 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v7, a3: "rb", a4: "MOD");
  fh = v8;
  if ( v8 != nullptr )
  {
    v10 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    fileTime = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: v10, a3: "MOD");
    v11 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
    deletefile = false;
    if ( v11 <= 0x100000 )
      CUtlCachedFileData<CAudioSourceCachedInfo>::InitSmallBuffer(this, &fh, fileSize: v11, deleteFile: &deletefile);
    else
      CUtlCachedFileData<CAudioSourceCachedInfo>::InitLargeBuffer(this, &fh, deleteFile: &deletefile);
    if ( deletefile && (*((_BYTE *)this + 84) & 2) == 0 )
    {
      v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: v12, a3: "MOD");
      *((_BYTE *)this + 84) |= 8u;
    }
    CUtlCachedFileData<CAudioSourceCachedInfo>::CheckDiskInfo(this, forcerebuild: false, cacheFileTime: fileTime);
  }
  else
  {
    v9 = *((_BYTE *)this + 84);
    if ( (v9 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v9 | 8;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415300
// Name: public: bool CMasterCacheBuilder::UpdateMasterPrecachedSoundsCache(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterCacheBuilder::UpdateMasterPrecachedSoundsCache(CMasterCacheBuilder *this)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *v2; // ebx
  const char *v3; // eax
  CFmtStrN<256> *v4; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *v5; // ebx
  int v6; // ecx
  const char *v7; // eax
  int i; // ebx
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // ecx
  CAudioSourceCachedInfo *v10; // eax
  int v11; // ecx
  double v12; // st7
  UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int> *m_pMemory; // eax
  CFmtStrN<256> v15; // [esp+20h] [ebp-538h] BYREF
  char fn[512]; // [esp+12Ch] [ebp-42Ch] BYREF
  char soundname[512]; // [esp+32Ch] [ebp-22Ch] BYREF
  float flStart; // [esp+52Ch] [ebp-2Ch]
  CUtlDict<CMasterCacheBuilder::CacheBuild_t,int> soundsOnDisk; // [esp+530h] [ebp-28h] BYREF
  int nUpdated; // [esp+554h] [ebp-4h]

  V_snprintf(
    pDest: fn,
    maxLen: 512,
    pFormat: "%s/%s%s.cache",
    "maps/soundcache",
    "_master",
    (const char *)this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory);
  CMasterCacheBuilder::Spew(this, pFmt: "Updating '%s'\n", fn);
  v2 = (CUtlCachedFileData<CAudioSourceCachedInfo> *)MemAlloc_Alloc(nSize: 0x58u);
  if ( v2 != nullptr )
  {
    v3 = CUtlString::operator char const *(this: &this->m_szMODPath);
    v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v15, pszFormat: "%s%s", v3, fn);
    v5 = CUtlCachedFileData<CAudioSourceCachedInfo>::CUtlCachedFileData<CAudioSourceCachedInfo>(
           this: v2,
           repositoryFileName: v4->m_szBuf,
           version: 3,
           checksumfunc: nullptr,
           fileCheckType: UTL_CACHED_FILE_USE_FILESIZE,
           nevercheckdisk: false,
           readonly: false,
           savemanifest: false);
  }
  else
  {
    v5 = nullptr;
  }
  if ( CUtlCachedFileData<CAudioSourceCachedInfo>::Init(this: v5, a2: (const char *)v5) != 0
    && this->m_pMasterSoundCache != v5 )
  {
    this->m_pMasterSoundCache = v5;
  }
  if ( this->m_pMasterSoundCache != nullptr )
  {
    flStart = _Plat_FloatTime(a1: v6);
    CMasterCacheBuilder::Spew(
      this,
      pFmt: "Updating sound cache [%d entries]\n",
      this->m_pMasterSoundCache->m_Elements.m_NumElements);
    memset(&soundsOnDisk.m_Elements.m_Tree.m_Elements, 0, sizeof(soundsOnDisk.m_Elements.m_Tree.m_Elements));
    soundsOnDisk.m_Elements.m_Tree.m_Root = -1;
    soundsOnDisk.m_Elements.m_Tree.m_NumElements = 0;
    soundsOnDisk.m_Elements.m_Tree.m_FirstFree = -1;
    soundsOnDisk.m_Elements.m_Tree.m_LastAlloc.index = -1;
    soundsOnDisk.m_Elements.m_Tree.m_pElements = nullptr;
    soundsOnDisk.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    v7 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
    CMasterCacheBuilder::RecursiveBuildSoundList(
      this,
      root: &soundsOnDisk,
      pLanguage: v7,
      pCurrentDir: "sound",
      pathID: "GAME");
    CMasterCacheBuilder::Spew(
      this,
      pFmt: "Found %d sound files on disk\n",
      soundsOnDisk.m_Elements.m_Tree.m_NumElements);
    *((_BYTE *)this->m_pMasterSoundCache + 84) &= ~1u;
    CUtlCachedFileData<CAudioSourceCachedInfo>::ForceRecheckDiskInfo(this: this->m_pMasterSoundCache);
    nUpdated = 0;
    for ( i = CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::FirstInorder(this: &soundsOnDisk.m_Elements.m_Tree);
          i != -1;
          i = CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::NextInorder(
                this: &soundsOnDisk.m_Elements.m_Tree,
                i) )
    {
      soundname[0] = 0;
      g_pFullFileSystem->String(
        this: g_pFullFileSystem,
        a2: (void *const *)&soundsOnDisk.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem,
        a3: soundname,
        a4: 512);
      m_pMasterSoundCache = this->m_pMasterSoundCache;
      g_bSoundRebuilt = false;
      v10 = CUtlCachedFileData<CAudioSourceCachedInfo>::Get(
              this: m_pMasterSoundCache,
              filename: (CAudioSourceCachedInfo *)soundname);
      CAudioSourceCachedInfo::operator=(
        this: &soundsOnDisk.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem.m_Info,
        src: v10);
      if ( g_bSoundRebuilt )
      {
        ++nUpdated;
        CMasterCacheBuilder::Spew(this, pFmt: " updated '%s'\n", &soundname[6]);
      }
    }
    *((_BYTE *)this->m_pMasterSoundCache + 84) |= 1u;
    CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this: this->m_pMasterSoundCache);
    v12 = _Plat_FloatTime(a1: v11);
    CMasterCacheBuilder::Spew(
      this,
      pFmt: "Updated %i out of %i cached files [%.3f msec]\n",
      nUpdated,
      soundsOnDisk.m_Elements.m_Tree.m_NumElements,
      (v12 - flStart) * 1000.0);
    CUtlDict<CMasterCacheBuilder::CacheBuild_t,int>::RemoveAll(this: &soundsOnDisk);
    CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::RemoveAll(this: &soundsOnDisk.m_Elements.m_Tree);
    m_pMemory = soundsOnDisk.m_Elements.m_Tree.m_Elements.m_pMemory;
    soundsOnDisk.m_Elements.m_Tree.m_FirstFree = -1;
    if ( soundsOnDisk.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( soundsOnDisk.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: soundsOnDisk.m_Elements.m_Tree.m_Elements.m_pMemory);
        m_pMemory = nullptr;
        soundsOnDisk.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      soundsOnDisk.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    soundsOnDisk.m_Elements.m_Tree.m_LastAlloc.index = -1;
    if ( soundsOnDisk.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415590
// Name: private: class CUtlCachedFileData<class CAudioSourceCachedInfo> __near * CMasterCacheBuilder::BuildCacheFromList(char const __near *,class CUtlDict<struct CMasterCacheBuilder::CacheBuild_t,int> __near &,bool,bool,float,float)
// Source: json
//------------------------------------------------------------------------------
CUtlCachedFileData<CAudioSourceCachedInfo> *__thiscall CMasterCacheBuilder::BuildCacheFromList(
        CMasterCacheBuilder *this,
        const char *cachename,
        CUtlDict<CMasterCacheBuilder::CacheBuild_t,int> *soundlist,
        bool fulldata,
        bool showprogress,
        float flProgressStart,
        float flProgressEnd)
{
  CMasterCacheBuilder *v7; // ebx
  CUtlCachedFileData<CAudioSourceCachedInfo> *v8; // esi
  const char *v9; // eax
  CFmtStrN<256> *v10; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *v11; // edi
  int v12; // ecx
  int Inorder; // esi
  CMasterCacheBuilder::CacheBuild_t *p_elem; // edi
  CAudioSourceCachedInfo *v15; // eax
  int v16; // eax
  CMasterCacheBuilder *v17; // esi
  double v18; // st7
  CFmtStrN<256> v20; // [esp+20h] [ebp-320h] BYREF
  char base[256]; // [esp+12Ch] [ebp-214h] BYREF
  char soundname[260]; // [esp+22Ch] [ebp-114h] BYREF
  float flStart; // [esp+330h] [ebp-10h]
  CUtlCachedFileData<CAudioSourceCachedInfo> *newCache; // [esp+334h] [ebp-Ch]
  CMasterCacheBuilder *v25; // [esp+338h] [ebp-8h]
  CUtlCachedFileData<CAudioSourceCachedInfo> *v26; // [esp+33Ch] [ebp-4h]
  int visited; // [esp+348h] [ebp+8h]

  v7 = this;
  v25 = this;
  flStart = _Plat_FloatTime(a1: this);
  v8 = (CUtlCachedFileData<CAudioSourceCachedInfo> *)MemAlloc_Alloc(nSize: 0x58u);
  if ( v8 != nullptr )
  {
    v9 = CUtlString::operator char const *(this: &v7->m_szMODPath);
    v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v20, pszFormat: "%s%s", v9, cachename);
    v11 = CUtlCachedFileData<CAudioSourceCachedInfo>::CUtlCachedFileData<CAudioSourceCachedInfo>(
            this: v8,
            repositoryFileName: v10->m_szBuf,
            version: 3,
            checksumfunc: nullptr,
            fileCheckType: UTL_CACHED_FILE_USE_FILESIZE,
            nevercheckdisk: false,
            readonly: false,
            savemanifest: false);
    v26 = v11;
  }
  else
  {
    v26 = nullptr;
    v11 = nullptr;
  }
  newCache = v11;
  if ( CUtlCachedFileData<CAudioSourceCachedInfo>::Init(this: v11, a2: (const char *)&v7->m_bQuiet) != 0 )
  {
    if ( v7->m_pBuildingCache != v11 )
      v7->m_pBuildingCache = v11;
    visited = 0;
    g_flFileIOTime = 0.0;
    Inorder = CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::FirstInorder(this: &soundlist->m_Elements.m_Tree);
    if ( Inorder != -1 )
    {
      do
      {
        p_elem = &soundlist->m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
        memset(soundname, 0, sizeof(soundname));
        g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)p_elem, a3: soundname, a4: 260);
        v15 = CUtlCachedFileData<CAudioSourceCachedInfo>::Get(this: v26, filename: (CAudioSourceCachedInfo *)soundname);
        if ( v15 != nullptr )
          CAudioSourceCachedInfo::operator=(this: &p_elem->m_Info, src: v15);
        v16 = 100 * (++visited / 100);
        if ( visited == v16 )
          CMasterCacheBuilder::Spew(
            this: v25,
            pFmt: "  progress %i/%i (%i %%)\n",
            visited,
            soundlist->m_Elements.m_Tree.m_NumElements,
            (int)((double)visited * 100.0 / (double)(unsigned int)soundlist->m_Elements.m_Tree.m_NumElements));
        if ( showprogress )
        {
          V_FileBase(in: soundname, out: base, maxlen: 256);
          _V_strlower(start: base);
        }
        Inorder = CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::NextInorder(
                    this: &soundlist->m_Elements.m_Tree,
                    i: Inorder);
      }
      while ( Inorder != -1 );
      v11 = v26;
    }
    v17 = v25;
    CMasterCacheBuilder::Spew(this: v25, pFmt: "Touched %i cached files\n", soundlist->m_Elements.m_Tree.m_NumElements);
    if ( v17->m_pBuildingCache != nullptr )
      v17->m_pBuildingCache = nullptr;
    CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this: v11);
    v7 = v17;
  }
  else
  {
    if ( v11 != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))v11->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: v11,
        a2: 1);
    newCache = nullptr;
  }
  v18 = _Plat_FloatTime(a1: v12);
  CMasterCacheBuilder::Spew(
    this: v7,
    pFmt: "Elapsed time:  %.2f seconds [file io %.2f seconds]\n",
    v18 - flStart,
    (double)g_flFileIOTime);
  return newCache;
}

//------------------------------------------------------------------------------
// Address: 0x004157C0
// Name: bool UpdateAudioCacheFile(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UpdateAudioCacheFile(const char *pchModPath, bool bQuiet)
{
  int v2; // eax
  const char *v3; // eax

  v2 = _CommandLine();
  v3 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v2 + 32))(
                       a1: v2,
                       a2: "-language",
                       a3: pDefaultValue);
  CMasterCacheBuilder::Init(this: &g_ASCache, pModPath: pchModPath, pLanguageSuffix: v3, bQuiet);
  CMasterCacheBuilder::UpdateMasterPrecachedSoundsCache(this: &g_ASCache);
  CMasterCacheBuilder::Shutdown(this: &g_ASCache);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415810
// Name: public: bool CMasterCacheBuilder::BuildMasterPrecachedSoundsCache(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterCacheBuilder::BuildMasterPrecachedSoundsCache(CMasterCacheBuilder *this)
{
  const char *v2; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *v3; // edi
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // ecx
  char fn[512]; // [esp+14h] [ebp-224h] BYREF
  CUtlDict<CMasterCacheBuilder::CacheBuild_t,int> other; // [esp+214h] [ebp-24h] BYREF

  V_snprintf(
    pDest: fn,
    maxLen: 512,
    pFormat: "%s/%s%s.cache",
    "maps/soundcache",
    "_master",
    (const char *)this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory);
  CMasterCacheBuilder::Spew(this, pFmt: "Rebuilding '%s'\n", fn);
  CMasterCacheBuilder::RemoveCache(this, cachename: fn);
  memset(&other.m_Elements.m_Tree.m_Elements, 0, sizeof(other.m_Elements.m_Tree.m_Elements));
  other.m_Elements.m_Tree.m_Root = -1;
  other.m_Elements.m_Tree.m_NumElements = 0;
  other.m_Elements.m_Tree.m_FirstFree = -1;
  other.m_Elements.m_Tree.m_LastAlloc.index = -1;
  other.m_Elements.m_Tree.m_pElements = nullptr;
  other.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  v2 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
  CMasterCacheBuilder::RecursiveBuildSoundList(this, root: &other, pLanguage: v2, pCurrentDir: "sound", pathID: "GAME");
  CMasterCacheBuilder::Spew(this, pFmt: "Found %d sounds in tree\n", other.m_Elements.m_Tree.m_NumElements);
  v3 = CMasterCacheBuilder::BuildCacheFromList(
         this,
         cachename: fn,
         soundlist: &other,
         fulldata: false,
         showprogress: true,
         flProgressStart: 0.0,
         flProgressEnd: 1.0);
  if ( v3 != nullptr )
  {
    m_pMasterSoundCache = this->m_pMasterSoundCache;
    if ( m_pMasterSoundCache != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))m_pMasterSoundCache->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: m_pMasterSoundCache,
        a2: 1);
    if ( this->m_pMasterSoundCache != v3 )
      this->m_pMasterSoundCache = v3;
  }
  CUtlDict<CMasterCacheBuilder::CacheBuild_t,int>::RemoveAll(this: &other);
  CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int,CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMasterCacheBuilder::CacheBuild_t,int>::Node_t,int>,int>>(this: &other.m_Elements.m_Tree);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415930
// Name: bool CreateAudioCacheFile(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateAudioCacheFile(const char *pchModPath, bool bQuiet)
{
  int v2; // eax
  const char *v3; // eax

  v2 = _CommandLine();
  v3 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v2 + 32))(
                       a1: v2,
                       a2: "-language",
                       a3: pDefaultValue);
  CMasterCacheBuilder::Init(this: &g_ASCache, pModPath: pchModPath, pLanguageSuffix: v3, bQuiet);
  CMasterCacheBuilder::BuildMasterPrecachedSoundsCache(this: &g_ASCache);
  CMasterCacheBuilder::Shutdown(this: &g_ASCache);
  return 1;
}
