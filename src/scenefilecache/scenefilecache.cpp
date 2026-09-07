// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: scenefilecache/scenefilecache.cpp
// Functions: 17
// ============================================================

#include "scenefilecache\scenefilecache.h"

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: public: virtual bool CSceneFileCache::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneFileCache::Connect(CSceneFileCache *this, void *(__cdecl *factory)(const char *, int *))
{
  filesystem = (IFileSystem *)factory(a1: "VFileSystem017", a2: nullptr);
  return filesystem != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: public: virtual void CSceneFileCache::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneFileCache::Disconnect(CSceneFileCache *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100010F0
// Name: public: virtual void CSceneFileCache::Reload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneFileCache::Reload(CSceneFileCache *this)
{
  this->Shutdown(this);
  this->Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001120
// Name: public: virtual short CSceneFileCache::GetSceneCachedSound(int,int)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CSceneFileCache::GetSceneCachedSound(CSceneFileCache *this, int iScene, int iSound)
{
  unsigned __int8 *m_pMemory; // eax
  unsigned __int8 *v4; // ecx

  m_pMemory = this->m_SceneImageFile.m_Memory.m_pMemory;
  if ( m_pMemory != nullptr
    && iScene >= 0
    && iScene < *((_DWORD *)m_pMemory + 2)
    && (v4 = &m_pMemory[*(_DWORD *)&m_pMemory[16 * iScene + 12 + *((_DWORD *)m_pMemory + 4)]], iSound >= 0)
    && iSound < *((_DWORD *)v4 + 2) )
  {
    return *(_WORD *)&v4[4 * iSound + 12];
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001160
// Name: public: virtual char const __near * CSceneFileCache::GetSceneString(short)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSceneFileCache::GetSceneString(CSceneFileCache *this, __int16 stringId)
{
  unsigned __int8 *m_pMemory; // ecx

  m_pMemory = this->m_SceneImageFile.m_Memory.m_pMemory;
  if ( m_pMemory != nullptr && stringId >= 0 && stringId < *((_DWORD *)m_pMemory + 3) )
    return (const char *)&m_pMemory[*(_DWORD *)&m_pMemory[4 * stringId + 20]];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001190
// Name: private: int CSceneFileCache::FindSceneInImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSceneFileCache::FindSceneInImage(CSceneFileCache *this, const char *pSceneName)
{
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *v4; // ebx
  int v5; // kr04_4
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  unsigned int v9; // edx
  char szCleanName[260]; // [esp+4h] [ebp-104h] BYREF

  m_pMemory = this->m_SceneImageFile.m_Memory.m_pMemory;
  if ( m_pMemory == nullptr )
    return -1;
  v4 = &m_pMemory[*((_DWORD *)m_pMemory + 4)];
  V_strncpy(pDest: szCleanName, pSrc: pSceneName, maxLen: 260);
  _V_strlower(start: szCleanName);
  V_FixSlashes(pname: szCleanName, separator: 92);
  V_SetExtension(path: szCleanName, extension: ".vcd", pathStringLength: 260);
  v5 = strlen(szCleanName);
  CRC32_Init(pulCRC: (unsigned int *)&pSceneName);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pSceneName, pBuffer: szCleanName, nBuffer: v5);
  CRC32_Final(pulCRC: (unsigned int *)&pSceneName);
  v6 = *((_DWORD *)m_pMemory + 2);
  v7 = 1;
  if ( v6 < 1 )
    return -1;
  while ( 1 )
  {
    v8 = (v6 + v7) / 2;
    v9 = *(_DWORD *)&v4[16 * v8 - 16];
    if ( (unsigned int)pSceneName >= v9 )
      break;
    v6 = v8 - 1;
LABEL_8:
    if ( v6 < v7 )
      return -1;
  }
  if ( (unsigned int)pSceneName > v9 )
  {
    v7 = v8 + 1;
    goto LABEL_8;
  }
  return v8 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001280
// Name: private: bool CSceneFileCache::GetSceneDataFromImage(char const __near *,int,unsigned char __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneFileCache::GetSceneDataFromImage(
        CSceneFileCache *this,
        const char *pFileName,
        int iScene,
        unsigned __int8 *pSceneData,
        unsigned int *pSceneLength)
{
  unsigned __int8 *m_pMemory; // eax
  int v6; // edi
  unsigned __int8 *v7; // esi
  signed int ActualSize; // eax
  unsigned int v9; // ebx
  unsigned __int8 *v10; // edi
  unsigned int *v12; // ebx
  int v13; // eax
  signed int nMaxLen; // [esp+0h] [ebp-4h]

  m_pMemory = this->m_SceneImageFile.m_Memory.m_pMemory;
  if ( m_pMemory != nullptr && iScene >= 0 && iScene < *((_DWORD *)m_pMemory + 2) )
  {
    v6 = (int)&m_pMemory[16 * iScene + *((_DWORD *)m_pMemory + 4)];
    v7 = &m_pMemory[*(_DWORD *)(v6 + 4)];
    if ( CLZMA::IsCompressed(this: (CLZMA *)&iScene + 3, pInput: v7) )
    {
      ActualSize = CLZMA::GetActualSize(this: (CLZMA *)&iScene + 3, pInput: v7);
      v9 = ActualSize;
      if ( pSceneData != nullptr )
      {
        nMaxLen = *pSceneLength;
        if ( ActualSize > (int)*pSceneLength )
        {
          v10 = (unsigned __int8 *)MemAlloc_Alloc(size: ActualSize);
          CLZMA::Uncompress(this: (CLZMA *)&iScene + 3, pInput: v7, pOutput: v10, pCallback: nullptr);
          _V_memcpy(dest: pSceneData, src: v10, count: nMaxLen);
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
        }
        else
        {
          CLZMA::Uncompress(this: (CLZMA *)&iScene + 3, pInput: v7, pOutput: pSceneData, pCallback: nullptr);
        }
      }
      if ( pSceneLength != nullptr )
      {
        *pSceneLength = v9;
        return 1;
      }
    }
    else
    {
      v12 = pSceneLength;
      if ( pSceneData != nullptr )
      {
        v13 = *pSceneLength;
        if ( *pSceneLength >= *(_DWORD *)(v6 + 8) )
          v13 = *(_DWORD *)(v6 + 8);
        _V_memcpy(dest: pSceneData, src: v7, count: v13);
      }
      if ( v12 != nullptr )
        *v12 = *(_DWORD *)(v6 + 8);
    }
    return 1;
  }
  else
  {
    if ( pSceneData != nullptr )
      *pSceneData = 0;
    if ( pSceneLength != nullptr )
      *pSceneLength = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001390
// Name: public: virtual enum InitReturnVal_t CSceneFileCache::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSceneFileCache::Init(CSceneFileCache *this)
{
  CUtlBuffer *p_m_SceneImageFile; // esi
  unsigned __int8 *m_pMemory; // esi

  if ( this->m_SceneImageFile.m_nMaxPut == 0 )
  {
    p_m_SceneImageFile = &this->m_SceneImageFile;
    if ( filesystem->ReadFile(
           this: &filesystem->IBaseFileSystem,
           a2: "scenes/scenes.image",
           a3: "GAME",
           a4: &this->m_SceneImageFile,
           a5: 0,
           a6: 0,
           a7: nullptr) )
    {
      m_pMemory = p_m_SceneImageFile->m_Memory.m_pMemory;
      if ( *(_DWORD *)m_pMemory != 1179210582 || *((_DWORD *)m_pMemory + 1) != 3 )
      {
        _Error(a1: "CSceneFileCache: Bad scene image file %s\n", "scenes/scenes.image");
        return 1;
      }
    }
    else
    {
      p_m_SceneImageFile->m_Get = 0;
      p_m_SceneImageFile->m_Put = 0;
      p_m_SceneImageFile->m_nOffset = 0;
      p_m_SceneImageFile->m_nMaxPut = 0;
      p_m_SceneImageFile->m_Error = 0;
      if ( p_m_SceneImageFile->m_Memory.m_nGrowSize >= 0 )
      {
        if ( p_m_SceneImageFile->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_SceneImageFile->m_Memory.m_pMemory);
          p_m_SceneImageFile->m_Memory.m_pMemory = nullptr;
        }
        p_m_SceneImageFile->m_Memory.m_nAllocationCount = 0;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001430
// Name: public: virtual void CSceneFileCache::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneFileCache::Shutdown(CSceneFileCache *this)
{
  this->m_SceneImageFile.m_Get = 0;
  this->m_SceneImageFile.m_Put = 0;
  this->m_SceneImageFile.m_nOffset = 0;
  this->m_SceneImageFile.m_nMaxPut = 0;
  this->m_SceneImageFile.m_Error = 0;
  if ( this->m_SceneImageFile.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SceneImageFile.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SceneImageFile.m_Memory.m_pMemory);
      this->m_SceneImageFile.m_Memory.m_pMemory = nullptr;
    }
    this->m_SceneImageFile.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001470
// Name: public: virtual unsigned int CSceneFileCache::GetSceneBufferSize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSceneFileCache::GetSceneBufferSize(CSceneFileCache *this, const char *pFilename)
{
  int SceneInImage; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v5; // edi
  unsigned __int8 *v6; // esi
  char fn[260]; // [esp+4h] [ebp-104h] BYREF

  V_strncpy(pDest: fn, pSrc: pFilename, maxLen: 260);
  V_FixSlashes(pname: fn, separator: 92);
  _V_strlower(start: fn);
  SceneInImage = CSceneFileCache::FindSceneInImage(this, pSceneName: fn);
  m_pMemory = this->m_SceneImageFile.m_Memory.m_pMemory;
  if ( m_pMemory == nullptr || SceneInImage < 0 || SceneInImage >= *((_DWORD *)m_pMemory + 2) )
    return 0;
  v5 = (int)&m_pMemory[16 * SceneInImage + *((_DWORD *)m_pMemory + 4)];
  v6 = &m_pMemory[*(_DWORD *)(v5 + 4)];
  if ( CLZMA::IsCompressed(this: (CLZMA *)&pFilename + 3, pInput: v6) )
    return CLZMA::GetActualSize(this: (CLZMA *)&pFilename + 3, pInput: v6);
  else
    return *(_DWORD *)(v5 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x10001510
// Name: public: virtual bool CSceneFileCache::GetSceneData(char const __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneFileCache::GetSceneData(
        CSceneFileCache *this,
        const char *pFilename,
        unsigned __int8 *buf,
        const char *bufsize)
{
  const char *v4; // edi
  int SceneInImage; // eax
  unsigned __int8 *v8; // [esp-8h] [ebp-114h]
  char fn[260]; // [esp+8h] [ebp-104h] BYREF

  v4 = pFilename;
  V_strncpy(pDest: fn, pSrc: pFilename, maxLen: 260);
  V_FixSlashes(pname: fn, separator: 92);
  _V_strlower(start: fn);
  pFilename = bufsize;
  v8 = buf;
  SceneInImage = CSceneFileCache::FindSceneInImage(this, pSceneName: fn);
  return CSceneFileCache::GetSceneDataFromImage(
           this,
           pFileName: v4,
           iScene: SceneInImage,
           pSceneData: v8,
           pSceneLength: (unsigned int *)&pFilename);
}

//------------------------------------------------------------------------------
// Address: 0x10001580
// Name: public: virtual bool CSceneFileCache::GetSceneCachedData(char const __near *,struct SceneCachedData_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneFileCache::GetSceneCachedData(
        CSceneFileCache *this,
        const char *pFilename,
        SceneCachedData_t *pData)
{
  int SceneInImage; // eax
  unsigned __int8 *m_pMemory; // edx
  int v6; // ecx
  double v7; // st7
  unsigned __int8 *v8; // ecx

  SceneInImage = CSceneFileCache::FindSceneInImage(this, pSceneName: pFilename);
  m_pMemory = this->m_SceneImageFile.m_Memory.m_pMemory;
  if ( m_pMemory != nullptr && SceneInImage >= 0 && SceneInImage < *((_DWORD *)m_pMemory + 2) )
  {
    v6 = *(_DWORD *)&m_pMemory[16 * SceneInImage + 12 + *((_DWORD *)m_pMemory + 4)];
    v7 = (double)*(unsigned int *)&m_pMemory[v6 + 4];
    v8 = &m_pMemory[v6];
    pData->sceneId = SceneInImage;
    pData->msecs = *(_DWORD *)v8;
    pData->numSounds = *((_DWORD *)v8 + 2);
    pData->m_fLastSpeakSecs = v7 * 0.001;
    return 1;
  }
  else
  {
    pData->sceneId = -1;
    pData->msecs = 0;
    *(_QWORD *)&pData->m_fLastSpeakSecs = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001610
// Name: public: virtual void __near * CBaseAppSystem<class ISceneFileCache>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseAppSystem<ISceneFileCache>::QueryInterface(
        CBaseAppSystem<ISceneFileCache> *this,
        const char *pInterfaceName)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001620
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class ISceneFileCache>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CBaseAppSystem<ISceneFileCache>::GetDependencies(
        CBaseAppSystem<ISceneFileCache> *this)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001630
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class ISceneFileCache>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<ISceneFileCache>::GetTier(CBaseAppSystem<ISceneFileCache> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10001640
// Name: public: virtual void CBaseAppSystem<class ISceneFileCache>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<ISceneFileCache>::Reconnect(
        CBaseAppSystem<ISceneFileCache> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: __CreateCSceneFileCacheISceneFileCache_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSceneFileCache *__cdecl _CreateCSceneFileCacheISceneFileCache_interface()
{
  return &g_SceneFileCache;
}
