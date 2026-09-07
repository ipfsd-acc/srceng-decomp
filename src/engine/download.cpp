// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/download.cpp
// Functions: 26
// ============================================================

#include "engine\download.h"

//------------------------------------------------------------------------------
// Address: 0x10162D00
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *original@<edi>)
{
  int v1; // eax
  char *v2; // esi
  const char *v4; // [esp+0h] [ebp-8h]

  v1 = _V_strlen(str: v4);
  v2 = (char *)MemAlloc_Alloc(nSize: v1 + 1);
  _V_strcpy(dest: v2, src: original);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10162D20
// Name: private: void DownloadCache::BuildKeyNames(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::BuildKeyNames(DownloadCache *this, const char *gamePath)
{
  int v3; // eax
  char *v4; // esi
  char *i; // eax

  if ( gamePath != nullptr )
  {
    v3 = _V_strlen(str: gamePath);
    v4 = (char *)MemAlloc_Alloc(nSize: v3 + 1);
    _V_strcpy(dest: v4, src: gamePath);
    for ( i = v4; *i != 0; ++i )
    {
      if ( *i == 47 || *i == 92 )
        *i = 95;
    }
    V_snprintf(pDest: this->m_cachefileKey, maxLen: 320, pFormat: "cachefile_%s", v4);
    V_snprintf(pDest: this->m_timestampKey, maxLen: 320, pFormat: "timestamp_%s", v4);
    free(pMem: v4);
  }
  else
  {
    this->m_cachefileKey[0] = 0;
    this->m_timestampKey[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162DB0
// Name: public: void DownloadCache::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::Init(DownloadCache *this)
{
  KeyValues *m_cache; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  IBaseFileSystem *v5; // ecx

  m_cache = this->m_cache;
  if ( m_cache != nullptr )
    KeyValues::deleteThis(this: m_cache);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "DownloadCache");
  else
    v4 = nullptr;
  this->m_cache = v4;
  if ( g_pFileSystem != nullptr )
    v5 = &g_pFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  KeyValues::LoadFromFile(
    this: v4,
    filesystem: v5,
    resourceName: CacheFilename,
    pathID: nullptr,
    pfnEvaluateSymbolProc: nullptr);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: CacheDirectory, a3: "DEFAULT_WRITE_PATH");
}

//------------------------------------------------------------------------------
// Address: 0x10162E20
// Name: DecompressBZipToDisk
// Source: json
//------------------------------------------------------------------------------
char __usercall DecompressBZipToDisk@<al>(
        int a1@<esi>,
        char *outFilename,
        char *srcFilename,
        char *data,
        int bytesTotal)
{
  int v5; // eax
  char *v6; // esi
  void *v7; // esi
  int v8; // ebx
  void *v10; // edi
  void *v11; // ebx
  int v12; // esi
  IBaseFileSystem_vtbl *v13; // edx
  IBaseFileSystem *v14; // ecx
  char buf[65536]; // [esp+8h] [ebp-10104h] BYREF
  char pOut[260]; // [esp+10008h] [ebp-104h] BYREF

  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: outFilename, a3: nullptr)
    || data == nullptr
    || bytesTotal < 1 )
  {
    return 0;
  }
  v5 = _V_strlen(str: outFilename);
  v6 = (char *)MemAlloc_Alloc(nSize: v5 + 1);
  _V_strcpy(dest: v6, src: outFilename);
  COM_CreatePath(path: v6);
  free(pMem: v6);
  V_MakeAbsolutePath(pOut, outLen: 260, pPath: srcFilename, pStartingDir: com_gamedir);
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *, _DWORD, int))g_pFileSystem->FileExists)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: pOut,
         a3: 0,
         a4: a1) == 0 )
  {
    v7 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *))g_pFileSystem->Open)(
                   a1: &g_pFileSystem->IBaseFileSystem,
                   a2: pOut,
                   a3: "wb");
    if ( v7 == nullptr )
      return 0;
    v8 = ((int (__thiscall *)(IBaseFileSystem *, char *, int, void *, _DWORD))g_pFileSystem->Write)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: data,
           a3: bytesTotal,
           a4: v7,
           a5: 0);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v7);
    if ( v8 != bytesTotal )
    {
      ((void (__thiscall *)(IFileSystem *, char *))g_pFileSystem->RemoveFile)(a1: g_pFileSystem, a2: srcFilename);
      return 0;
    }
  }
  v10 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: outFilename, a3: "wb", a4: 0);
  if ( v10 != nullptr )
  {
    v11 = BZ2_bzopen(path: pOut, mode: "rb");
    v12 = BZ2_bzread(b: v11, buf, len: 0x10000);
    if ( v12 < 0 )
    {
LABEL_15:
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v10);
      BZ2_bzclose(b: v11);
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: srcFilename, a3: nullptr);
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: outFilename, a3: nullptr);
      return 0;
    }
    else
    {
      while ( 1 )
      {
        v13 = g_pFileSystem->IBaseFileSystem::__vftable;
        v14 = &g_pFileSystem->IBaseFileSystem;
        if ( v12 <= 0 )
          break;
        if ( v13->Write(this: v14, a2: buf, a3: v12, a4: v10) == v12 )
        {
          v12 = BZ2_bzread(b: v11, buf, len: 0x10000);
          if ( v12 >= 0 )
            continue;
        }
        goto LABEL_15;
      }
      ((void (__thiscall *)(IBaseFileSystem *))v13->Close)(a1: v14);
      BZ2_bzclose(b: v11);
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: srcFilename, a3: nullptr);
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(IFileSystem *, char *))g_pFileSystem->RemoveFile)(a1: g_pFileSystem, a2: srcFilename);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163050
// Name: private: void DownloadCache::GetCacheFilename(struct RequestContext const __near *,char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::GetCacheFilename(DownloadCache *this, const RequestContext *rc, char *cachePath)
{
  unsigned __int8 *String; // esi

  DownloadCache::BuildKeyNames(this, gamePath: rc->gamePath);
  String = (unsigned __int8 *)KeyValues::GetString(
                                this: this->m_cache,
                                keyName: this->m_cachefileKey,
                                defaultValue: nullptr);
  if ( String != nullptr
    && strncmp(first: (const char *)String, last: CacheDirectory, count: strlen(CacheDirectory)) == 0 )
  {
    strncpy(dest: (unsigned __int8 *)cachePath, source: String, count: 0x104u);
    cachePath[259] = 0;
  }
  else
  {
    *cachePath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101630D0
// Name: private: void DownloadCache::GenerateCacheFilename(struct RequestContext const __near *,char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::GenerateCacheFilename(DownloadCache *this, const RequestContext *rc, char *cachePath)
{
  unsigned __int8 *gamePath; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // ebx
  int v8; // edi
  const char *lastSlash; // [esp+18h] [ebp+8h]

  DownloadCache::GetCacheFilename(this, rc, cachePath);
  gamePath = (unsigned __int8 *)rc->gamePath;
  DownloadCache::BuildKeyNames(this, gamePath: rc->gamePath);
  KeyValues::SetString(this: this->m_cache, keyName: this->m_timestampKey, value: rc->cachedTimestamp);
  if ( *cachePath != 0 )
    return;
  strrchr(string: gamePath, chr: 0x2Fu);
  lastSlash = v5;
  strrchr(string: gamePath, chr: 0x5Cu);
  v7 = (const char *)gamePath;
  if ( lastSlash != nullptr )
  {
    if ( lastSlash > v6 )
      v6 = lastSlash;
  }
  else if ( v6 == nullptr )
  {
    goto LABEL_8;
  }
  v7 = v6 + 1;
LABEL_8:
  v8 = 0;
  while ( 1 )
  {
    V_snprintf(pDest: cachePath, maxLen: 260, pFormat: "%s/%s%4.4d", CacheDirectory, v7, v8);
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: cachePath, a3: nullptr) )
      break;
    if ( ++v8 >= 1000 )
    {
      V_snprintf(pDest: cachePath, maxLen: 260, pFormat: "%s/overflow", CacheDirectory);
      break;
    }
  }
  KeyValues::SetString(this: this->m_cache, keyName: this->m_cachefileKey, value: cachePath);
}

//------------------------------------------------------------------------------
// Address: 0x101631C0
// Name: bool CL_ShouldRedownloadFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_ShouldRedownloadFile(const char *filename)
{
  bool result; // al
  char extension[12]; // [esp+8h] [ebp-Ch] BYREF

  V_FileBase(in: com_gamedir, out: gamedir_5, maxlen: 260);
  result = false;
  if ( _V_stricmp(s1: gamedir_5, s2: "infested") == 0
    && (V_strnicmp(s1: filename + 5, s2: "gridrandom", n: 10) == 0
     || V_strnicmp(s1: filename + 5, s2: "output", n: 6) == 0) )
  {
    V_ExtractFileExtension(path: filename, dest: extension, destSize: 12);
    if ( _V_stricmp(s1: extension, s2: "layout") == 0 || _V_stricmp(s1: extension, s2: "bsp") == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163270
// Name: public: void DownloadCache::GetCachedData(struct RequestContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::GetCachedData(DownloadCache *this, RequestContext *rc)
{
  bool v2; // zf
  void *v4; // esi
  unsigned int v5; // edi
  unsigned __int8 *v6; // eax
  DownloadCache *v7; // esi
  unsigned __int8 *String; // eax
  char cachePath[260]; // [esp+0h] [ebp-108h] BYREF
  DownloadCache *v10; // [esp+104h] [ebp-4h]
  int status; // [esp+110h] [ebp+8h]

  v2 = this->m_cache == nullptr;
  v10 = this;
  if ( !v2 )
  {
    DownloadCache::GetCacheFilename(this, rc, cachePath);
    if ( cachePath[0] != 0 )
    {
      v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: cachePath, a3: "rb", a4: 0);
      if ( v4 != nullptr )
      {
        v5 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
        v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v5);
        rc->cacheData = v6;
        status = g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v6, a3: v5, a4: v4);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
        if ( status != 0 )
        {
          v7 = v10;
          DownloadCache::BuildKeyNames(this: v10, gamePath: rc->gamePath);
          rc->nBytesCached = v5;
          String = (unsigned __int8 *)KeyValues::GetString(
                                        this: v7->m_cache,
                                        keyName: v7->m_timestampKey,
                                        defaultValue: defaultValue);
          strncpy(dest: (unsigned __int8 *)rc->cachedTimestamp, source: String, count: 0x100u);
        }
        else
        {
          free(pMem: rc->cacheData);
          rc->cacheData = nullptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163390
// Name: public: void DownloadCache::PersistToDisk(struct RequestContext const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::PersistToDisk(DownloadCache *this, const RequestContext *rc)
{
  bool v4; // zf
  char *v5; // edi
  KeyValues *Key; // eax
  KeyValues *v7; // eax
  IBaseFileSystem *v8; // eax
  void *v9; // edi
  char cachePath[260]; // [esp+4h] [ebp-208h] BYREF
  char gamePath[260]; // [esp+108h] [ebp-104h] BYREF
  const RequestContext *rca; // [esp+214h] [ebp+8h]

  if ( this->m_cache == nullptr )
    return;
  if ( rc != nullptr && rc->data != nullptr && rc->nBytesTotal != 0 )
  {
    v4 = !rc->bIsBZ2;
    rca = (const RequestContext *)rc->gamePath;
    if ( v4 )
      V_strncpy(pDest: gamePath, pSrc: rc->gamePath, maxLen: 260);
    else
      V_StripExtension(in: rc->gamePath, out: gamePath, outSize: 260);
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: gamePath, a3: nullptr) )
    {
      v5 = CloneString(original: gamePath);
      COM_CreatePath(path: v5);
      free(pMem: v5);
      if ( rc->bIsBZ2 )
      {
        if ( DecompressBZipToDisk(
               outFilename: gamePath,
               srcFilename: (const char *)&rca->shouldStop,
               data: (char *)rc->data,
               bytesTotal: rc->nBytesTotal) )
        {
LABEL_11:
          DownloadCache::GetCacheFilename(this, rc, cachePath);
          if ( cachePath[0] != 0 )
            g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: cachePath, a3: nullptr);
          DownloadCache::BuildKeyNames(this, gamePath: (const char *)&rca->shouldStop);
          Key = KeyValues::FindKey(this: this->m_cache, keyName: this->m_cachefileKey, bCreate: false);
          if ( Key != nullptr )
            KeyValues::RemoveSubKey(this: this->m_cache, subKey: Key);
          v7 = KeyValues::FindKey(this: this->m_cache, keyName: this->m_timestampKey, bCreate: false);
          if ( v7 != nullptr )
            KeyValues::RemoveSubKey(this: this->m_cache, subKey: v7);
        }
      }
      else
      {
        v9 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: gamePath, a3: "wb", a4: 0);
        if ( v9 != nullptr )
        {
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: rc->data, a3: rc->nBytesTotal, a4: v9);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v9);
          goto LABEL_11;
        }
      }
    }
  }
  if ( g_pFileSystem != nullptr )
    v8 = &g_pFileSystem->IBaseFileSystem;
  else
    v8 = nullptr;
  KeyValues::SaveToFile(this: this->m_cache, filesystem: v8, resourceName: CacheFilename, pathID: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10163560
// Name: public: void DownloadCache::PersistToCache(struct RequestContext const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::PersistToCache(DownloadCache *this, const RequestContext *rc)
{
  void *v3; // edi
  IBaseFileSystem *v4; // eax
  char cachePath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_cache != nullptr
    && rc != nullptr
    && rc->data != nullptr
    && rc->nBytesTotal != 0
    && rc->nBytesCurrent != 0 )
  {
    DownloadCache::GenerateCacheFilename(this, rc, cachePath);
    v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: cachePath, a3: "wb", a4: 0);
    if ( v3 != nullptr )
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: rc->data, a3: rc->nBytesCurrent, a4: v3);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      if ( g_pFileSystem != nullptr )
        v4 = &g_pFileSystem->IBaseFileSystem;
      else
        v4 = nullptr;
      KeyValues::SaveToFile(this: this->m_cache, filesystem: v4, resourceName: CacheFilename, pathID: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163640
// Name: private: void DownloadManager::UpdateProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall DownloadManager::UpdateProgressBar(DownloadManager *this)
{
  RequestContext *m_activeRequest; // edi
  signed int v3; // eax
  float v4; // xmm0_4
  CClientState *BaseLocalClient; // eax
  IEngineVGuiInternal *v6; // eax
  char *gamePath; // [esp+4h] [ebp-21Ch]
  wchar_t pDest[10]; // [esp+10h] [ebp-210h] BYREF
  __int64 filenameBuf_500; // [esp+218h] [ebp-8h] OVERLAPPED BYREF

  m_activeRequest = this->m_activeRequest;
  if ( m_activeRequest != nullptr )
  {
    if ( m_activeRequest->bAsHTTP )
    {
      v3 = 0;
      if ( m_activeRequest->nBytesTotal != 0 )
        v3 = 100 * m_activeRequest->nBytesCurrent / m_activeRequest->nBytesTotal;
      v4 = (float)((float)((float)v3 / (float)this->m_totalRequests)
                 + (float)(100 * (this->m_totalRequests - this->m_queuedRequests.m_Size - 1) / this->m_totalRequests))
         * 0.0099999998;
    }
    else
    {
      BaseLocalClient = GetBaseLocalClient();
      BaseLocalClient->m_NetChannel->GetStreamProgress(
        this: BaseLocalClient->m_NetChannel,
        a2: 1,
        a3: (int *)&filenameBuf_500 + 1,
        a4: (int *)&filenameBuf_500);
      v4 = (float)SHIDWORD(filenameBuf_500) / (float)(int)filenameBuf_500;
    }
    gamePath = this->m_activeRequest->gamePath;
    *((float *)&filenameBuf_500 + 1) = v4;
    V_snwprintf(pDest, maxLen: 256, pFormat: L"Downloading %hs", gamePath);
    v6 = EngineVGui();
    ((void (__thiscall *)(IEngineVGuiInternal *, _DWORD, wchar_t *))v6->UpdateCustomProgressBar)(
      a1: v6,
      a2: HIDWORD(filenameBuf_500),
      a3: pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163730
// Name: int CL_GetDownloadQueueSize(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CL_GetDownloadQueueSize()
{
  return TheDownloadManager.m_queuedRequests.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10163740
// Name: private: void DownloadManager::PruneCompletedRequests(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::PruneCompletedRequests(DownloadManager *this)
{
  int i; // edi
  RequestContext *v3; // eax
  unsigned __int8 *cacheData; // eax

  for ( i = this->m_completedRequests.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_completedRequests.m_Memory.m_pMemory[i];
    if ( v3->threadDone || !v3->bAsHTTP )
    {
      cacheData = v3->cacheData;
      if ( cacheData != nullptr )
        free(pMem: cacheData);
      free(pMem: this->m_completedRequests.m_Memory.m_pMemory[i]);
      if ( this->m_completedRequests.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &this->m_completedRequests.m_Memory.m_pMemory[i],
          src: &this->m_completedRequests.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_completedRequests.m_Size - i - 1));
      --this->m_completedRequests.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163830
// Name: public: bool DownloadManager::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall DownloadManager::FileDenied(
        DownloadManager *this,
        const char *filename,
        unsigned int requestID,
        bool isReplayDemoFile)
{
  RequestContext *m_activeRequest; // eax
  RequestContext **p_m_activeRequest; // esi

  m_activeRequest = this->m_activeRequest;
  p_m_activeRequest = &this->m_activeRequest;
  if ( m_activeRequest == nullptr || m_activeRequest->nRequestID != requestID || m_activeRequest->bAsHTTP )
    return 0;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_DownloadManager,
      a2: LS_MESSAGE,
      a3: DownloadErrorColor,
      a4: "Error downloading %s\n",
      (*p_m_activeRequest)->gamePath);
  DownloadManager::UpdateProgressBar(this);
  CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
    this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
    elem: this->m_completedRequests.m_Size,
    src: (vgui::PageTab *const *)p_m_activeRequest);
  *p_m_activeRequest = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101638C0
// Name: public: bool DownloadManager::FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall DownloadManager::FileReceived(
        DownloadManager *this,
        const char *filename,
        unsigned int requestID,
        bool isReplayDemoFile)
{
  RequestContext *m_activeRequest; // eax
  RequestContext **p_m_activeRequest; // edi
  const char *FileExtension; // eax
  ECommandTarget_t TraceType; // eax
  char cmd[256]; // [esp+8h] [ebp-100h] BYREF

  m_activeRequest = this->m_activeRequest;
  p_m_activeRequest = &this->m_activeRequest;
  if ( m_activeRequest == nullptr || m_activeRequest->nRequestID != requestID || m_activeRequest->bAsHTTP )
    return 0;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_DownloadManager, a2: LS_MESSAGE, a3: DownloadCompleteColor, a4: "Download finished!\n");
  DownloadManager::UpdateProgressBar(this);
  CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
    this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
    elem: this->m_completedRequests.m_Size,
    src: (vgui::PageTab *const *)p_m_activeRequest);
  *p_m_activeRequest = nullptr;
  V_FileBase(in: com_gamedir, out: gamedir_6, maxlen: 260);
  if ( _V_stricmp(s1: gamedir_6, s2: "infested") == 0 )
  {
    FileExtension = V_GetFileExtension(path: filename);
    if ( _V_stricmp(s1: FileExtension, s2: "layout") == 0 )
    {
      g_bASW_Waiting_For_Map_Build = true;
      V_snprintf(pDest: cmd, maxLen: 256, pFormat: "asw_build_map %s connecting\n", filename);
      TraceType = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)cmd);
      Cbuf_AddText(eTarget: TraceType, pText: cmd, nTickDelay: 0);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101639D0
// Name: public: void DownloadManager::Queue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::Queue(DownloadManager *this, const char *baseURL, char *gamePath)
{
  int v4; // eax
  IBaseFileSystem_vtbl *v5; // ebx
  char *v6; // eax
  DownloadCache *v7; // eax
  RequestContext *v8; // eax
  int m_Size; // ebx
  RequestContext *v10; // esi
  int m_nAllocationCount; // eax
  RequestContext **m_pMemory; // ecx
  int v13; // eax
  RequestContext **v14; // ebx
  CClientState *BaseLocalClient; // eax
  netadr_s *v16; // eax
  const char *v17; // eax
  char *v18; // esi
  DownloadCache *v19; // eax
  RequestContext *v20; // eax
  int v21; // ebx
  RequestContext *v22; // esi
  int v23; // eax
  RequestContext **v24; // ecx
  int v25; // eax
  RequestContext **v26; // ebx
  CClientState *v27; // eax
  netadr_s *v28; // eax
  const char *v29; // eax
  char *v30; // esi
  bool bAsHTTP; // [esp+Bh] [ebp-1h]

  bAsHTTP = false;
  if ( gamePath != nullptr )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "DownloadManager::Queue",
      a3: 0,
      a4: "Steam",
      a5: false,
      a6: 4);
    if ( sv.m_State < ss_active )
    {
      if ( baseURL != nullptr
        && (V_strnicmp(s1: baseURL, s2: "http://", n: 7) == 0 || V_strnicmp(s1: baseURL, s2: "https://", n: 8) == 0) )
      {
        bAsHTTP = true;
      }
      if ( (!g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: gamePath, a3: nullptr)
         || CL_ShouldRedownloadFile(filename: gamePath))
        && _V_strstr(s1: gamePath, search: "//") == nullptr
        && _V_strstr(s1: gamePath, search: "\\\\") == nullptr
        && _V_strstr(s1: gamePath, search: ":") == nullptr
        && _V_strstr(s1: gamePath, search: "lua/") == nullptr
        && _V_strstr(s1: gamePath, search: "gamemodes/") == nullptr
        && _V_strstr(s1: gamePath, search: "addons/") == nullptr )
      {
        strstr(str1: (unsigned __int8 *)gamePath, str2: "..");
        if ( v4 == 0 && CNetChan::IsValidFileTransferExtension(pFilename: gamePath) )
        {
          if ( bAsHTTP )
          {
            v5 = g_pFileSystem->IBaseFileSystem::__vftable;
            v6 = va(format: "%s.bz2", gamePath);
            if ( !v5->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v6, a3: nullptr) )
            {
              ++this->m_totalRequests;
              if ( TheDownloadCache == nullptr )
              {
                v7 = (DownloadCache *)MemAlloc_Alloc(nSize: 0x284u);
                if ( v7 != nullptr )
                  v7->m_cache = nullptr;
                else
                  v7 = nullptr;
                TheDownloadCache = v7;
                DownloadCache::Init(this: v7);
              }
              v8 = (RequestContext *)MemAlloc_Alloc(nSize: 0x530u);
              m_Size = this->m_queuedRequests.m_Size;
              v10 = v8;
              m_nAllocationCount = this->m_queuedRequests.m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<INetMessage *,int>::Grow(
                  (CUtlMemory<S3RGBA,int> *)this,
                  num: m_Size - m_nAllocationCount + 1);
              ++this->m_queuedRequests.m_Size;
              m_pMemory = this->m_queuedRequests.m_Memory.m_pMemory;
              v13 = this->m_queuedRequests.m_Size - m_Size - 1;
              this->m_queuedRequests.m_pElements = this->m_queuedRequests.m_Memory.m_pMemory;
              if ( v13 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
              v14 = &this->m_queuedRequests.m_Memory.m_pMemory[m_Size];
              if ( v14 != nullptr )
                *v14 = v10;
              memset(dst: (unsigned __int8 *)v10, value: 0, count: sizeof(RequestContext));
              v10->status = HTTP_CONNECTING;
              V_strncpy(pDest: v10->basePath, pSrc: com_gamedir, maxLen: 256);
              V_strncpy(pDest: v10->gamePath, pSrc: gamePath, maxLen: 256);
              V_strncat(pDest: v10->gamePath, pSrc: ".bz2", destBufferSize: 0x100u, max_chars_to_copy: -1);
              V_FixSlashes(pname: v10->gamePath, separator: 47);
              BaseLocalClient = GetBaseLocalClient();
              v16 = (netadr_s *)BaseLocalClient->m_NetChannel->GetRemoteAddress(this: BaseLocalClient->m_NetChannel);
              v17 = netadr_s::ToString(this: v16, baseOnly: false);
              V_strncpy(pDest: v10->serverURL, pSrc: v17, maxLen: 256);
              *(_WORD *)&v10->bIsBZ2 = 257;
              v18 = v10->baseURL;
              V_strncpy(pDest: v18, pSrc: baseURL, maxLen: 256);
              V_strncat(pDest: v18, pSrc: "/", destBufferSize: 0x100u, max_chars_to_copy: -1);
            }
          }
          ++this->m_totalRequests;
          if ( TheDownloadCache == nullptr )
          {
            v19 = (DownloadCache *)MemAlloc_Alloc(nSize: 0x284u);
            if ( v19 != nullptr )
              v19->m_cache = nullptr;
            else
              v19 = nullptr;
            TheDownloadCache = v19;
            DownloadCache::Init(this: v19);
          }
          v20 = (RequestContext *)MemAlloc_Alloc(nSize: 0x530u);
          v21 = this->m_queuedRequests.m_Size;
          v22 = v20;
          v23 = this->m_queuedRequests.m_Memory.m_nAllocationCount;
          if ( v21 + 1 > v23 )
            CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v21 - v23 + 1);
          ++this->m_queuedRequests.m_Size;
          v24 = this->m_queuedRequests.m_Memory.m_pMemory;
          v25 = this->m_queuedRequests.m_Size - v21 - 1;
          this->m_queuedRequests.m_pElements = this->m_queuedRequests.m_Memory.m_pMemory;
          if ( v25 > 0 )
            _V_memmove(dest: &v24[v21 + 1], src: &v24[v21], count: 4 * v25);
          v26 = &this->m_queuedRequests.m_Memory.m_pMemory[v21];
          if ( v26 != nullptr )
            *v26 = v22;
          memset(dst: (unsigned __int8 *)v22, value: 0, count: sizeof(RequestContext));
          v22->status = HTTP_CONNECTING;
          V_strncpy(pDest: v22->basePath, pSrc: com_gamedir, maxLen: 256);
          V_strncpy(pDest: v22->gamePath, pSrc: gamePath, maxLen: 256);
          V_FixSlashes(pname: v22->gamePath, separator: 47);
          v27 = GetBaseLocalClient();
          v28 = (netadr_s *)v27->m_NetChannel->GetRemoteAddress(this: v27->m_NetChannel);
          v29 = netadr_s::ToString(this: v28, baseOnly: false);
          V_strncpy(pDest: v22->serverURL, pSrc: v29, maxLen: 256);
          if ( bAsHTTP )
          {
            v22->bAsHTTP = true;
            v30 = v22->baseURL;
            V_strncpy(pDest: v30, pSrc: baseURL, maxLen: 256);
            V_strncat(pDest: v30, pSrc: "/", destBufferSize: 0x100u, max_chars_to_copy: -1);
          }
          else
          {
            v22->bAsHTTP = false;
          }
        }
      }
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163E00
// Name: private: void DownloadManager::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::Reset(DownloadManager *this)
{
  RequestContext **p_m_activeRequest; // edi
  int i; // edi
  DownloadCache *v4; // eax

  p_m_activeRequest = &this->m_activeRequest;
  if ( this->m_activeRequest != nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
      LoggingSystem_Log(
        a1: LOG_DownloadManager,
        a2: LS_MESSAGE,
        a3: DownloadColor,
        a4: "Aborting download of %s\n",
        (*p_m_activeRequest)->gamePath);
    if ( (*p_m_activeRequest)->nBytesTotal != 0 && (*p_m_activeRequest)->nBytesCurrent != 0 )
      DownloadCache::PersistToCache(this: TheDownloadCache, rc: *p_m_activeRequest);
    (*p_m_activeRequest)->shouldStop = true;
    CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
      this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
      elem: this->m_completedRequests.m_Size,
      src: (vgui::PageTab *const *)p_m_activeRequest);
    *p_m_activeRequest = nullptr;
  }
  for ( i = 0; i < this->m_queuedRequests.m_Size; ++i )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
      LoggingSystem_Log(
        a1: LOG_DownloadManager,
        a2: LS_MESSAGE,
        a3: DownloadColor,
        a4: "Discarding queued download of %s\n",
        this->m_queuedRequests.m_Memory.m_pMemory[i]->gamePath);
    free(pMem: this->m_queuedRequests.m_Memory.m_pMemory[i]);
  }
  v4 = TheDownloadCache;
  this->m_queuedRequests.m_Size = 0;
  if ( v4 != nullptr )
  {
    free(pMem: v4);
    TheDownloadCache = nullptr;
  }
  this->m_totalRequests = 0;
  this->m_lastPercent = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10163F00
// Name: private: void DownloadManager::CheckActiveDownload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::CheckActiveDownload(DownloadManager *this)
{
  RequestContext *m_activeRequest; // eax
  RequestContext **p_m_activeRequest; // esi
  int v4; // eax
  int v5; // eax
  const RequestContext *v6; // esi
  unsigned int nBytesTotal; // ecx
  unsigned int v8; // eax

  m_activeRequest = this->m_activeRequest;
  p_m_activeRequest = &this->m_activeRequest;
  if ( m_activeRequest != nullptr )
  {
    if ( !m_activeRequest->bAsHTTP )
    {
      DownloadManager::UpdateProgressBar(this);
      return;
    }
    v4 = m_activeRequest->status - 1;
    if ( v4 != 0 )
    {
      v5 = v4 - 1;
      if ( v5 != 0 )
      {
        if ( v5 != 2 )
          return;
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
          LoggingSystem_Log(
            a1: LOG_DownloadManager,
            a2: LS_MESSAGE,
            a3: DownloadErrorColor,
            a4: "Error downloading %s%s\n",
            (*p_m_activeRequest)->baseURL,
            (*p_m_activeRequest)->gamePath);
        DownloadManager::UpdateProgressBar(this);
        (*p_m_activeRequest)->shouldStop = true;
        goto LABEL_14;
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
        LoggingSystem_Log(
          a1: LOG_DownloadManager,
          a2: LS_MESSAGE,
          a3: DownloadCompleteColor,
          a4: "Download finished!\n");
      DownloadManager::UpdateProgressBar(this);
      if ( (*p_m_activeRequest)->nBytesTotal != 0 )
      {
        DownloadCache::PersistToDisk(this: TheDownloadCache, rc: *p_m_activeRequest);
        (*p_m_activeRequest)->shouldStop = true;
LABEL_14:
        CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
          elem: this->m_completedRequests.m_Size,
          src: (vgui::PageTab *const *)p_m_activeRequest);
        *p_m_activeRequest = nullptr;
      }
    }
    else
    {
      DownloadManager::UpdateProgressBar(this);
      v6 = *p_m_activeRequest;
      nBytesTotal = v6->nBytesTotal;
      if ( nBytesTotal != 0 )
      {
        v8 = 100 * v6->nBytesCurrent / nBytesTotal;
        if ( v8 != this->m_lastPercent )
          this->m_lastPercent = v8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164020
// Name: private: void DownloadManager::StartNewDownload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::StartNewDownload(DownloadManager *this)
{
  RequestContext **p_m_activeRequest; // esi
  int m_Size; // ecx
  RequestContext **m_pMemory; // eax
  int v5; // ecx
  CClientState *BaseLocalClient; // eax
  vgui::PageTab *v7; // [esp-8h] [ebp-10h]

  p_m_activeRequest = &this->m_activeRequest;
  if ( this->m_activeRequest == nullptr && this->m_queuedRequests.m_Size != 0 )
  {
    do
    {
      m_Size = this->m_queuedRequests.m_Size;
      if ( m_Size == 0 )
        break;
      m_pMemory = this->m_queuedRequests.m_Memory.m_pMemory;
      v5 = m_Size - 1;
      *p_m_activeRequest = *this->m_queuedRequests.m_Memory.m_pMemory;
      if ( v5 > 0 )
        _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: 4 * v5);
      --this->m_queuedRequests.m_Size;
      if ( g_pFileSystem->FileExists(
             this: &g_pFileSystem->IBaseFileSystem,
             a2: (*p_m_activeRequest)->gamePath,
             a3: nullptr)
        && !CL_ShouldRedownloadFile(filename: (*p_m_activeRequest)->gamePath) )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
          LoggingSystem_Log(
            a1: LOG_DownloadManager,
            a2: LS_MESSAGE,
            a3: DownloadColor,
            a4: "Skipping existing file %s%s.\n",
            (*p_m_activeRequest)->baseURL,
            (*p_m_activeRequest)->gamePath);
        (*p_m_activeRequest)->shouldStop = true;
        (*p_m_activeRequest)->threadDone = true;
        CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
          elem: this->m_completedRequests.m_Size,
          src: (vgui::PageTab *const *)p_m_activeRequest);
        *p_m_activeRequest = nullptr;
      }
    }
    while ( *p_m_activeRequest == nullptr );
    if ( *p_m_activeRequest != nullptr )
    {
      if ( !g_pFileSystem->FileExists(
              this: &g_pFileSystem->IBaseFileSystem,
              a2: (*p_m_activeRequest)->gamePath,
              a3: nullptr)
        || CL_ShouldRedownloadFile(filename: (*p_m_activeRequest)->gamePath) )
      {
        if ( (*p_m_activeRequest)->bAsHTTP )
        {
          DownloadCache::GetCachedData(this: TheDownloadCache, rc: *p_m_activeRequest);
          DownloadManager::UpdateProgressBar(this);
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
            LoggingSystem_Log(
              a1: LOG_DownloadManager,
              a2: LS_MESSAGE,
              a3: DownloadColor,
              a4: "Downloading %s%s.\n",
              (*p_m_activeRequest)->baseURL,
              (*p_m_activeRequest)->gamePath);
          v7 = (vgui::PageTab *)*p_m_activeRequest;
          this->m_lastPercent = 0;
          _CreateSimpleThread(a1: DownloadThread, a2: v7, a3: 0);
        }
        else
        {
          DownloadManager::UpdateProgressBar(this);
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
            LoggingSystem_Log(
              a1: LOG_DownloadManager,
              a2: LS_MESSAGE,
              a3: DownloadColor,
              a4: "Downloading %s.\n",
              (*p_m_activeRequest)->gamePath);
          this->m_lastPercent = 0;
          BaseLocalClient = GetBaseLocalClient();
          (*p_m_activeRequest)->nRequestID = BaseLocalClient->m_NetChannel->RequestFile(
                                               this: BaseLocalClient->m_NetChannel,
                                               a2: (*p_m_activeRequest)->gamePath,
                                               a3: false);
        }
      }
      else
      {
        (*p_m_activeRequest)->shouldStop = true;
        (*p_m_activeRequest)->threadDone = true;
        CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
          elem: this->m_completedRequests.m_Size,
          src: (vgui::PageTab *const *)p_m_activeRequest);
        *p_m_activeRequest = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164250
// Name: bool CL_DownloadUpdate(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CL_DownloadUpdate()
{
  DownloadManager::PruneCompletedRequests(this: &TheDownloadManager);
  DownloadManager::CheckActiveDownload(this: &TheDownloadManager);
  DownloadManager::StartNewDownload(this: &TheDownloadManager);
  return TheDownloadManager.m_activeRequest != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10164280
// Name: bool CL_FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CL_FileReceived(const char *filename, unsigned int requestID, bool isReplayDemoFile)
{
  return DownloadManager::FileReceived(this: &TheDownloadManager, filename, requestID, isReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x101642A0
// Name: bool CL_FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CL_FileDenied(const char *filename, unsigned int requestID, bool isReplayDemoFile)
{
  return DownloadManager::FileDenied(this: &TheDownloadManager, filename, requestID, isReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x101642C0
// Name: void CL_QueueDownload(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_QueueDownload(char *filename)
{
  char *m_pszString; // eax

  if ( (sv_downloadurl.m_nFlags & 0x1000) != 0 )
  {
    DownloadManager::Queue(this: &TheDownloadManager, baseURL: "FCVAR_NEVER_AS_STRING", gamePath: filename);
  }
  else
  {
    m_pszString = sv_downloadurl.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
    DownloadManager::Queue(this: &TheDownloadManager, baseURL: m_pszString, gamePath: filename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164310
// Name: public: DownloadManager::~DownloadManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::~DownloadManager(DownloadManager *this)
{
  int i; // edi
  char **m_pMemory; // eax
  RequestContext **v4; // eax
  RequestContext **v5; // eax

  DownloadManager::Reset(this);
  for ( i = 0; i < this->m_downloadedMaps.m_Size; ++i )
    free(pMem: this->m_downloadedMaps.m_Memory.m_pMemory[i]);
  this->m_downloadedMaps.m_Size = 0;
  if ( this->m_downloadedMaps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_downloadedMaps.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_downloadedMaps.m_Memory.m_pMemory);
      this->m_downloadedMaps.m_Memory.m_pMemory = nullptr;
    }
    this->m_downloadedMaps.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_downloadedMaps.m_Memory.m_pMemory;
  this->m_downloadedMaps.m_pElements = m_pMemory;
  if ( this->m_downloadedMaps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_downloadedMaps.m_Memory.m_pMemory = nullptr;
    }
    this->m_downloadedMaps.m_Memory.m_nAllocationCount = 0;
  }
  this->m_completedRequests.m_Size = 0;
  if ( this->m_completedRequests.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_completedRequests.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_completedRequests.m_Memory.m_pMemory);
      this->m_completedRequests.m_Memory.m_pMemory = nullptr;
    }
    this->m_completedRequests.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_completedRequests.m_Memory.m_pMemory;
  this->m_completedRequests.m_pElements = v4;
  if ( this->m_completedRequests.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      this->m_completedRequests.m_Memory.m_pMemory = nullptr;
    }
    this->m_completedRequests.m_Memory.m_nAllocationCount = 0;
  }
  this->m_queuedRequests.m_Size = 0;
  if ( this->m_queuedRequests.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_queuedRequests.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_queuedRequests.m_Memory.m_pMemory);
      this->m_queuedRequests.m_Memory.m_pMemory = nullptr;
    }
    this->m_queuedRequests.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_queuedRequests.m_Memory.m_pMemory;
  this->m_queuedRequests.m_pElements = this->m_queuedRequests.m_Memory.m_pMemory;
  if ( this->m_queuedRequests.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_queuedRequests.m_Memory.m_pMemory = nullptr;
    }
    this->m_queuedRequests.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164420
// Name: void CL_HTTPStop_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_HTTPStop_f()
{
  DownloadManager::Reset(this: &TheDownloadManager);
}

//------------------------------------------------------------------------------
// Address: 0x102C6C80
// Name: CloneString_0
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString_0@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)MemAlloc_Alloc(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10162F80
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *original@<edi>)
{
  int v1; // eax
  char *v2; // esi
  const char *v4; // [esp+0h] [ebp-8h]

  v1 = _V_strlen(str: v4);
  v2 = (char *)MemAlloc_Alloc(nSize: v1 + 1);
  _V_strcpy(dest: v2, src: original);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10162FA0
// Name: private: void DownloadCache::BuildKeyNames(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::BuildKeyNames(DownloadCache *this, const char *gamePath)
{
  int v3; // eax
  char *v4; // esi
  char *i; // eax

  if ( gamePath != nullptr )
  {
    v3 = _V_strlen(str: gamePath);
    v4 = (char *)MemAlloc_Alloc(nSize: v3 + 1);
    _V_strcpy(dest: v4, src: gamePath);
    for ( i = v4; *i != 0; ++i )
    {
      if ( *i == 47 || *i == 92 )
        *i = 95;
    }
    V_snprintf(pDest: this->m_cachefileKey, maxLen: 320, pFormat: "cachefile_%s", v4);
    V_snprintf(pDest: this->m_timestampKey, maxLen: 320, pFormat: "timestamp_%s", v4);
    free(pMem: v4);
  }
  else
  {
    this->m_cachefileKey[0] = 0;
    this->m_timestampKey[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163030
// Name: public: void DownloadCache::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::Init(DownloadCache *this)
{
  KeyValues *m_cache; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  IBaseFileSystem *v5; // ecx

  m_cache = this->m_cache;
  if ( m_cache != nullptr )
    KeyValues::deleteThis(this: m_cache);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "DownloadCache");
  else
    v4 = nullptr;
  this->m_cache = v4;
  if ( g_pFileSystem != nullptr )
    v5 = &g_pFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  KeyValues::LoadFromFile(
    this: v4,
    filesystem: v5,
    resourceName: CacheFilename,
    pathID: nullptr,
    pfnEvaluateSymbolProc: nullptr);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: CacheDirectory, a3: "DEFAULT_WRITE_PATH");
}

//------------------------------------------------------------------------------
// Address: 0x101630A0
// Name: DecompressBZipToDisk
// Source: json
//------------------------------------------------------------------------------
char __usercall DecompressBZipToDisk@<al>(
        int a1@<esi>,
        char *outFilename,
        char *srcFilename,
        char *data,
        int bytesTotal)
{
  int v5; // eax
  char *v6; // esi
  void *v7; // esi
  int v8; // ebx
  void *v10; // edi
  void *v11; // ebx
  int v12; // esi
  IBaseFileSystem_vtbl *v13; // edx
  IBaseFileSystem *v14; // ecx
  char buf[65536]; // [esp+8h] [ebp-10104h] BYREF
  char pOut[260]; // [esp+10008h] [ebp-104h] BYREF

  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: outFilename, a3: nullptr)
    || data == nullptr
    || bytesTotal < 1 )
  {
    return 0;
  }
  v5 = _V_strlen(str: outFilename);
  v6 = (char *)MemAlloc_Alloc(nSize: v5 + 1);
  _V_strcpy(dest: v6, src: outFilename);
  COM_CreatePath(path: v6);
  free(pMem: v6);
  V_MakeAbsolutePath(pOut, outLen: 260, pPath: srcFilename, pStartingDir: com_gamedir);
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *, _DWORD, int))g_pFileSystem->FileExists)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: pOut,
         a3: 0,
         a4: a1) == 0 )
  {
    v7 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *))g_pFileSystem->Open)(
                   a1: &g_pFileSystem->IBaseFileSystem,
                   a2: pOut,
                   a3: "wb");
    if ( v7 == nullptr )
      return 0;
    v8 = ((int (__thiscall *)(IBaseFileSystem *, char *, int, void *, _DWORD))g_pFileSystem->Write)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: data,
           a3: bytesTotal,
           a4: v7,
           a5: 0);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v7);
    if ( v8 != bytesTotal )
    {
      ((void (__thiscall *)(IFileSystem *, char *))g_pFileSystem->RemoveFile)(a1: g_pFileSystem, a2: srcFilename);
      return 0;
    }
  }
  v10 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: outFilename, a3: "wb", a4: 0);
  if ( v10 != nullptr )
  {
    v11 = BZ2_bzopen(path: pOut, mode: "rb");
    v12 = BZ2_bzread(b: v11, buf, len: 0x10000);
    if ( v12 < 0 )
    {
LABEL_15:
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v10);
      BZ2_bzclose(b: v11);
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: srcFilename, a3: nullptr);
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: outFilename, a3: nullptr);
      return 0;
    }
    else
    {
      while ( 1 )
      {
        v13 = g_pFileSystem->IBaseFileSystem::__vftable;
        v14 = &g_pFileSystem->IBaseFileSystem;
        if ( v12 <= 0 )
          break;
        if ( v13->Write(this: v14, a2: buf, a3: v12, a4: v10) == v12 )
        {
          v12 = BZ2_bzread(b: v11, buf, len: 0x10000);
          if ( v12 >= 0 )
            continue;
        }
        goto LABEL_15;
      }
      ((void (__thiscall *)(IBaseFileSystem *))v13->Close)(a1: v14);
      BZ2_bzclose(b: v11);
      g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: srcFilename, a3: nullptr);
      return 1;
    }
  }
  else
  {
    ((void (__thiscall *)(IFileSystem *, char *))g_pFileSystem->RemoveFile)(a1: g_pFileSystem, a2: srcFilename);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101632D0
// Name: private: void DownloadCache::GetCacheFilename(struct RequestContext const __near *,char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::GetCacheFilename(DownloadCache *this, const RequestContext *rc, char *cachePath)
{
  unsigned __int8 *String; // esi

  DownloadCache::BuildKeyNames(this, gamePath: rc->gamePath);
  String = (unsigned __int8 *)KeyValues::GetString(
                                this: this->m_cache,
                                keyName: this->m_cachefileKey,
                                defaultValue: nullptr);
  if ( String != nullptr
    && strncmp(first: (const char *)String, last: CacheDirectory, count: strlen(CacheDirectory)) == 0 )
  {
    strncpy(dest: (unsigned __int8 *)cachePath, source: String, count: 0x104u);
    cachePath[259] = 0;
  }
  else
  {
    *cachePath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163350
// Name: private: void DownloadCache::GenerateCacheFilename(struct RequestContext const __near *,char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::GenerateCacheFilename(DownloadCache *this, const RequestContext *rc, char *cachePath)
{
  unsigned __int8 *gamePath; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // ebx
  int v8; // edi
  const char *lastSlash; // [esp+18h] [ebp+8h]

  DownloadCache::GetCacheFilename(this, rc, cachePath);
  gamePath = (unsigned __int8 *)rc->gamePath;
  DownloadCache::BuildKeyNames(this, gamePath: rc->gamePath);
  KeyValues::SetString(this: this->m_cache, keyName: this->m_timestampKey, value: rc->cachedTimestamp);
  if ( *cachePath != 0 )
    return;
  strrchr(string: gamePath, chr: 0x2Fu);
  lastSlash = v5;
  strrchr(string: gamePath, chr: 0x5Cu);
  v7 = (const char *)gamePath;
  if ( lastSlash != nullptr )
  {
    if ( lastSlash > v6 )
      v6 = lastSlash;
  }
  else if ( v6 == nullptr )
  {
    goto LABEL_8;
  }
  v7 = v6 + 1;
LABEL_8:
  v8 = 0;
  while ( 1 )
  {
    V_snprintf(pDest: cachePath, maxLen: 260, pFormat: "%s/%s%4.4d", CacheDirectory, v7, v8);
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: cachePath, a3: nullptr) )
      break;
    if ( ++v8 >= 1000 )
    {
      V_snprintf(pDest: cachePath, maxLen: 260, pFormat: "%s/overflow", CacheDirectory);
      break;
    }
  }
  KeyValues::SetString(this: this->m_cache, keyName: this->m_cachefileKey, value: cachePath);
}

//------------------------------------------------------------------------------
// Address: 0x10163440
// Name: bool CL_ShouldRedownloadFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_ShouldRedownloadFile(const char *filename)
{
  bool result; // al
  char extension[12]; // [esp+8h] [ebp-Ch] BYREF

  V_FileBase(in: com_gamedir, out: gamedir_5, maxlen: 260);
  result = false;
  if ( _V_stricmp(s1: gamedir_5, s2: "infested") == 0
    && (V_strnicmp(s1: filename + 5, s2: "gridrandom", n: 10) == 0
     || V_strnicmp(s1: filename + 5, s2: "output", n: 6) == 0) )
  {
    V_ExtractFileExtension(path: filename, dest: extension, destSize: 12);
    if ( _V_stricmp(s1: extension, s2: "layout") == 0 || _V_stricmp(s1: extension, s2: "bsp") == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101634F0
// Name: public: void DownloadCache::GetCachedData(struct RequestContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::GetCachedData(DownloadCache *this, RequestContext *rc)
{
  bool v2; // zf
  void *v4; // esi
  unsigned int v5; // edi
  unsigned __int8 *v6; // eax
  DownloadCache *v7; // esi
  unsigned __int8 *String; // eax
  char cachePath[260]; // [esp+0h] [ebp-108h] BYREF
  DownloadCache *v10; // [esp+104h] [ebp-4h]
  int status; // [esp+110h] [ebp+8h]

  v2 = this->m_cache == nullptr;
  v10 = this;
  if ( !v2 )
  {
    DownloadCache::GetCacheFilename(this, rc, cachePath);
    if ( cachePath[0] != 0 )
    {
      v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: cachePath, a3: "rb", a4: 0);
      if ( v4 != nullptr )
      {
        v5 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
        v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v5);
        rc->cacheData = v6;
        status = g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v6, a3: v5, a4: v4);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
        if ( status != 0 )
        {
          v7 = v10;
          DownloadCache::BuildKeyNames(this: v10, gamePath: rc->gamePath);
          rc->nBytesCached = v5;
          String = (unsigned __int8 *)KeyValues::GetString(
                                        this: v7->m_cache,
                                        keyName: v7->m_timestampKey,
                                        defaultValue: defaultValue);
          strncpy(dest: (unsigned __int8 *)rc->cachedTimestamp, source: String, count: 0x100u);
        }
        else
        {
          free(pMem: rc->cacheData);
          rc->cacheData = nullptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163610
// Name: public: void DownloadCache::PersistToDisk(struct RequestContext const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::PersistToDisk(DownloadCache *this, const RequestContext *rc)
{
  bool v4; // zf
  char *v5; // edi
  KeyValues *Key; // eax
  KeyValues *v7; // eax
  IBaseFileSystem *v8; // eax
  void *v9; // edi
  char cachePath[260]; // [esp+4h] [ebp-208h] BYREF
  char gamePath[260]; // [esp+108h] [ebp-104h] BYREF
  RequestContext *rca; // [esp+214h] [ebp+8h]

  if ( this->m_cache == nullptr )
    return;
  if ( rc != nullptr && rc->data != nullptr && rc->nBytesTotal != 0 )
  {
    v4 = !rc->bIsBZ2;
    rca = (RequestContext *)rc->gamePath;
    if ( v4 )
      V_strncpy(pDest: gamePath, pSrc: rc->gamePath, maxLen: 260);
    else
      V_StripExtension(in: rc->gamePath, out: gamePath, outSize: 260);
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: gamePath, a3: nullptr) )
    {
      v5 = CloneString(original: gamePath);
      COM_CreatePath(path: v5);
      free(pMem: v5);
      if ( rc->bIsBZ2 )
      {
        if ( DecompressBZipToDisk(
               a1: (int)rc,
               outFilename: gamePath,
               srcFilename: (char *)&rca->shouldStop,
               data: (char *)rc->data,
               bytesTotal: rc->nBytesTotal) != 0 )
        {
LABEL_11:
          DownloadCache::GetCacheFilename(this, rc, cachePath);
          if ( cachePath[0] != 0 )
            g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: cachePath, a3: nullptr);
          DownloadCache::BuildKeyNames(this, gamePath: (const char *)&rca->shouldStop);
          Key = KeyValues::FindKey(this: this->m_cache, keyName: this->m_cachefileKey, bCreate: false);
          if ( Key != nullptr )
            KeyValues::RemoveSubKey(this: this->m_cache, subKey: Key);
          v7 = KeyValues::FindKey(this: this->m_cache, keyName: this->m_timestampKey, bCreate: false);
          if ( v7 != nullptr )
            KeyValues::RemoveSubKey(this: this->m_cache, subKey: v7);
        }
      }
      else
      {
        v9 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: gamePath, a3: "wb", a4: 0);
        if ( v9 != nullptr )
        {
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: rc->data, a3: rc->nBytesTotal, a4: v9);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v9);
          goto LABEL_11;
        }
      }
    }
  }
  if ( g_pFileSystem != nullptr )
    v8 = &g_pFileSystem->IBaseFileSystem;
  else
    v8 = nullptr;
  KeyValues::SaveToFile(this: this->m_cache, filesystem: v8, resourceName: CacheFilename, pathID: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101637E0
// Name: public: void DownloadCache::PersistToCache(struct RequestContext const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadCache::PersistToCache(DownloadCache *this, const RequestContext *rc)
{
  void *v3; // edi
  IBaseFileSystem *v4; // eax
  char cachePath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_cache != nullptr
    && rc != nullptr
    && rc->data != nullptr
    && rc->nBytesTotal != 0
    && rc->nBytesCurrent != 0 )
  {
    DownloadCache::GenerateCacheFilename(this, rc, cachePath);
    v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: cachePath, a3: "wb", a4: 0);
    if ( v3 != nullptr )
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: rc->data, a3: rc->nBytesCurrent, a4: v3);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      if ( g_pFileSystem != nullptr )
        v4 = &g_pFileSystem->IBaseFileSystem;
      else
        v4 = nullptr;
      KeyValues::SaveToFile(this: this->m_cache, filesystem: v4, resourceName: CacheFilename, pathID: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101639B0
// Name: int CL_GetDownloadQueueSize(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CL_GetDownloadQueueSize()
{
  return TheDownloadManager.m_queuedRequests.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101639C0
// Name: private: void DownloadManager::PruneCompletedRequests(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::PruneCompletedRequests(DownloadManager *this)
{
  int i; // edi
  RequestContext *v3; // eax
  unsigned __int8 *cacheData; // eax

  for ( i = this->m_completedRequests.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_completedRequests.m_Memory.m_pMemory[i];
    if ( v3->threadDone || !v3->bAsHTTP )
    {
      cacheData = v3->cacheData;
      if ( cacheData != nullptr )
        free(pMem: cacheData);
      free(pMem: this->m_completedRequests.m_Memory.m_pMemory[i]);
      if ( this->m_completedRequests.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &this->m_completedRequests.m_Memory.m_pMemory[i],
          src: &this->m_completedRequests.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_completedRequests.m_Size - i - 1));
      --this->m_completedRequests.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163A40
// Name: public: bool DownloadManager::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall DownloadManager::FileDenied(
        DownloadManager *this,
        const char *filename,
        unsigned int requestID,
        bool isReplayDemoFile)
{
  RequestContext *m_activeRequest; // eax
  vgui::PageTab **p_m_activeRequest; // esi

  m_activeRequest = this->m_activeRequest;
  p_m_activeRequest = (vgui::PageTab **)&this->m_activeRequest;
  if ( m_activeRequest == nullptr || m_activeRequest->nRequestID != requestID || m_activeRequest->bAsHTTP )
    return 0;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_DownloadManager,
      a2: LS_MESSAGE,
      a3: DownloadErrorColor,
      a4: "Error downloading %s\n",
      (const char *)&(*p_m_activeRequest)->m_pImage);
  DownloadManager::UpdateProgressBar(this);
  CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
    this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
    elem: this->m_completedRequests.m_Size,
    src: p_m_activeRequest);
  *p_m_activeRequest = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10163AD0
// Name: public: bool DownloadManager::FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall DownloadManager::FileReceived(
        DownloadManager *this,
        const char *filename,
        unsigned int requestID,
        bool isReplayDemoFile)
{
  RequestContext *m_activeRequest; // eax
  vgui::PageTab **p_m_activeRequest; // edi
  const char *FileExtension; // eax
  ECommandTarget_t TraceType; // eax
  char cmd[256]; // [esp+8h] [ebp-100h] BYREF

  m_activeRequest = this->m_activeRequest;
  p_m_activeRequest = (vgui::PageTab **)&this->m_activeRequest;
  if ( m_activeRequest == nullptr || m_activeRequest->nRequestID != requestID || m_activeRequest->bAsHTTP )
    return 0;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_DownloadManager, a2: LS_MESSAGE, a3: DownloadCompleteColor, a4: "Download finished!\n");
  DownloadManager::UpdateProgressBar(this);
  CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
    this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
    elem: this->m_completedRequests.m_Size,
    src: p_m_activeRequest);
  *p_m_activeRequest = nullptr;
  V_FileBase(in: com_gamedir, out: gamedir_6, maxlen: 260);
  if ( _V_stricmp(s1: gamedir_6, s2: "infested") == 0 )
  {
    FileExtension = V_GetFileExtension(path: filename);
    if ( _V_stricmp(s1: FileExtension, s2: "layout") == 0 )
    {
      g_bASW_Waiting_For_Map_Build = true;
      V_snprintf(pDest: cmd, maxLen: 256, pFormat: "asw_build_map %s connecting\n", filename);
      TraceType = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)cmd);
      Cbuf_AddText(eTarget: TraceType, pText: cmd, nTickDelay: 0);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10163BE0
// Name: public: void DownloadManager::Queue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::Queue(DownloadManager *this, const char *baseURL, char *gamePath)
{
  int v4; // eax
  IBaseFileSystem_vtbl *v5; // ebx
  char *v6; // eax
  DownloadCache *v7; // eax
  RequestContext *v8; // eax
  int m_Size; // ebx
  RequestContext *v10; // esi
  int m_nAllocationCount; // eax
  RequestContext **m_pMemory; // ecx
  int v13; // eax
  RequestContext **v14; // ebx
  CClientState *BaseLocalClient; // eax
  netadr_s *v16; // eax
  const char *v17; // eax
  char *v18; // esi
  DownloadCache *v19; // eax
  RequestContext *v20; // eax
  int v21; // ebx
  RequestContext *v22; // esi
  int v23; // eax
  RequestContext **v24; // ecx
  int v25; // eax
  RequestContext **v26; // ebx
  CClientState *v27; // eax
  netadr_s *v28; // eax
  const char *v29; // eax
  char *v30; // esi
  bool bAsHTTP; // [esp+Bh] [ebp-1h]

  bAsHTTP = false;
  if ( gamePath != nullptr )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "DownloadManager::Queue",
      a3: 0,
      a4: "Steam",
      a5: false,
      a6: 4);
    if ( sv.m_State < ss_active )
    {
      if ( baseURL != nullptr
        && (V_strnicmp(s1: baseURL, s2: "http://", n: 7) == 0 || V_strnicmp(s1: baseURL, s2: "https://", n: 8) == 0) )
      {
        bAsHTTP = true;
      }
      if ( (!g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: gamePath, a3: nullptr)
         || CL_ShouldRedownloadFile(filename: gamePath))
        && _V_strstr(s1: gamePath, search: "//") == nullptr
        && _V_strstr(s1: gamePath, search: "\\\\") == nullptr
        && _V_strstr(s1: gamePath, search: ":") == nullptr
        && _V_strstr(s1: gamePath, search: "lua/") == nullptr
        && _V_strstr(s1: gamePath, search: "gamemodes/") == nullptr
        && _V_strstr(s1: gamePath, search: "addons/") == nullptr )
      {
        strstr(str1: (unsigned __int8 *)gamePath, str2: "..");
        if ( v4 == 0 && CNetChan::IsValidFileTransferExtension(pFilename: gamePath) )
        {
          if ( bAsHTTP )
          {
            v5 = g_pFileSystem->IBaseFileSystem::__vftable;
            v6 = va(format: "%s.bz2", gamePath);
            if ( !v5->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v6, a3: nullptr) )
            {
              ++this->m_totalRequests;
              if ( TheDownloadCache == nullptr )
              {
                v7 = (DownloadCache *)MemAlloc_Alloc(nSize: 0x284u);
                if ( v7 != nullptr )
                  v7->m_cache = nullptr;
                else
                  v7 = nullptr;
                TheDownloadCache = v7;
                DownloadCache::Init(this: v7);
              }
              v8 = (RequestContext *)MemAlloc_Alloc(nSize: 0x530u);
              m_Size = this->m_queuedRequests.m_Size;
              v10 = v8;
              m_nAllocationCount = this->m_queuedRequests.m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<INetMessage *,int>::Grow(
                  (CUtlMemory<S3RGBA,int> *)this,
                  num: m_Size - m_nAllocationCount + 1);
              ++this->m_queuedRequests.m_Size;
              m_pMemory = this->m_queuedRequests.m_Memory.m_pMemory;
              v13 = this->m_queuedRequests.m_Size - m_Size - 1;
              this->m_queuedRequests.m_pElements = this->m_queuedRequests.m_Memory.m_pMemory;
              if ( v13 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
              v14 = &this->m_queuedRequests.m_Memory.m_pMemory[m_Size];
              if ( v14 != nullptr )
                *v14 = v10;
              memset(dst: (unsigned __int8 *)v10, value: 0, count: sizeof(RequestContext));
              v10->status = HTTP_CONNECTING;
              V_strncpy(pDest: v10->basePath, pSrc: com_gamedir, maxLen: 256);
              V_strncpy(pDest: v10->gamePath, pSrc: gamePath, maxLen: 256);
              V_strncat(pDest: v10->gamePath, pSrc: ".bz2", destBufferSize: 0x100u, max_chars_to_copy: -1);
              V_FixSlashes(pname: v10->gamePath, separator: 47);
              BaseLocalClient = GetBaseLocalClient();
              v16 = (netadr_s *)BaseLocalClient->m_NetChannel->GetRemoteAddress(this: BaseLocalClient->m_NetChannel);
              v17 = netadr_s::ToString(this: v16, baseOnly: false);
              V_strncpy(pDest: v10->serverURL, pSrc: v17, maxLen: 256);
              *(_WORD *)&v10->bIsBZ2 = 257;
              v18 = v10->baseURL;
              V_strncpy(pDest: v18, pSrc: baseURL, maxLen: 256);
              V_strncat(pDest: v18, pSrc: "/", destBufferSize: 0x100u, max_chars_to_copy: -1);
            }
          }
          ++this->m_totalRequests;
          if ( TheDownloadCache == nullptr )
          {
            v19 = (DownloadCache *)MemAlloc_Alloc(nSize: 0x284u);
            if ( v19 != nullptr )
              v19->m_cache = nullptr;
            else
              v19 = nullptr;
            TheDownloadCache = v19;
            DownloadCache::Init(this: v19);
          }
          v20 = (RequestContext *)MemAlloc_Alloc(nSize: 0x530u);
          v21 = this->m_queuedRequests.m_Size;
          v22 = v20;
          v23 = this->m_queuedRequests.m_Memory.m_nAllocationCount;
          if ( v21 + 1 > v23 )
            CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v21 - v23 + 1);
          ++this->m_queuedRequests.m_Size;
          v24 = this->m_queuedRequests.m_Memory.m_pMemory;
          v25 = this->m_queuedRequests.m_Size - v21 - 1;
          this->m_queuedRequests.m_pElements = this->m_queuedRequests.m_Memory.m_pMemory;
          if ( v25 > 0 )
            _V_memmove(dest: &v24[v21 + 1], src: &v24[v21], count: 4 * v25);
          v26 = &this->m_queuedRequests.m_Memory.m_pMemory[v21];
          if ( v26 != nullptr )
            *v26 = v22;
          memset(dst: (unsigned __int8 *)v22, value: 0, count: sizeof(RequestContext));
          v22->status = HTTP_CONNECTING;
          V_strncpy(pDest: v22->basePath, pSrc: com_gamedir, maxLen: 256);
          V_strncpy(pDest: v22->gamePath, pSrc: gamePath, maxLen: 256);
          V_FixSlashes(pname: v22->gamePath, separator: 47);
          v27 = GetBaseLocalClient();
          v28 = (netadr_s *)v27->m_NetChannel->GetRemoteAddress(this: v27->m_NetChannel);
          v29 = netadr_s::ToString(this: v28, baseOnly: false);
          V_strncpy(pDest: v22->serverURL, pSrc: v29, maxLen: 256);
          if ( bAsHTTP )
          {
            v22->bAsHTTP = true;
            v30 = v22->baseURL;
            V_strncpy(pDest: v30, pSrc: baseURL, maxLen: 256);
            V_strncat(pDest: v30, pSrc: "/", destBufferSize: 0x100u, max_chars_to_copy: -1);
          }
          else
          {
            v22->bAsHTTP = false;
          }
        }
      }
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164010
// Name: private: void DownloadManager::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::Reset(DownloadManager *this)
{
  RequestContext **p_m_activeRequest; // edi
  int i; // edi
  DownloadCache *v4; // eax

  p_m_activeRequest = &this->m_activeRequest;
  if ( this->m_activeRequest != nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
      LoggingSystem_Log(
        a1: LOG_DownloadManager,
        a2: LS_MESSAGE,
        a3: DownloadColor,
        a4: "Aborting download of %s\n",
        (*p_m_activeRequest)->gamePath);
    if ( (*p_m_activeRequest)->nBytesTotal != 0 && (*p_m_activeRequest)->nBytesCurrent != 0 )
      DownloadCache::PersistToCache(this: TheDownloadCache, rc: *p_m_activeRequest);
    (*p_m_activeRequest)->shouldStop = true;
    CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
      this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
      elem: this->m_completedRequests.m_Size,
      src: (vgui::PageTab **)p_m_activeRequest);
    *p_m_activeRequest = nullptr;
  }
  for ( i = 0; i < this->m_queuedRequests.m_Size; ++i )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
      LoggingSystem_Log(
        a1: LOG_DownloadManager,
        a2: LS_MESSAGE,
        a3: DownloadColor,
        a4: "Discarding queued download of %s\n",
        this->m_queuedRequests.m_Memory.m_pMemory[i]->gamePath);
    free(pMem: this->m_queuedRequests.m_Memory.m_pMemory[i]);
  }
  v4 = TheDownloadCache;
  this->m_queuedRequests.m_Size = 0;
  if ( v4 != nullptr )
  {
    free(pMem: v4);
    TheDownloadCache = nullptr;
  }
  this->m_totalRequests = 0;
  this->m_lastPercent = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10164110
// Name: private: void DownloadManager::CheckActiveDownload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::CheckActiveDownload(DownloadManager *this)
{
  RequestContext *m_activeRequest; // eax
  RequestContext **p_m_activeRequest; // esi
  int v4; // eax
  int v5; // eax
  const RequestContext *v6; // esi
  unsigned int nBytesTotal; // ecx
  unsigned int v8; // eax

  m_activeRequest = this->m_activeRequest;
  p_m_activeRequest = &this->m_activeRequest;
  if ( m_activeRequest != nullptr )
  {
    if ( !m_activeRequest->bAsHTTP )
    {
      DownloadManager::UpdateProgressBar(this);
      return;
    }
    v4 = m_activeRequest->status - 1;
    if ( v4 != 0 )
    {
      v5 = v4 - 1;
      if ( v5 != 0 )
      {
        if ( v5 != 2 )
          return;
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
          LoggingSystem_Log(
            a1: LOG_DownloadManager,
            a2: LS_MESSAGE,
            a3: DownloadErrorColor,
            a4: "Error downloading %s%s\n",
            (*p_m_activeRequest)->baseURL,
            (*p_m_activeRequest)->gamePath);
        DownloadManager::UpdateProgressBar(this);
        (*p_m_activeRequest)->shouldStop = true;
        goto LABEL_14;
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
        LoggingSystem_Log(
          a1: LOG_DownloadManager,
          a2: LS_MESSAGE,
          a3: DownloadCompleteColor,
          a4: "Download finished!\n");
      DownloadManager::UpdateProgressBar(this);
      if ( (*p_m_activeRequest)->nBytesTotal != 0 )
      {
        DownloadCache::PersistToDisk(this: TheDownloadCache, rc: *p_m_activeRequest);
        (*p_m_activeRequest)->shouldStop = true;
LABEL_14:
        CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
          elem: this->m_completedRequests.m_Size,
          src: (vgui::PageTab **)p_m_activeRequest);
        *p_m_activeRequest = nullptr;
      }
    }
    else
    {
      DownloadManager::UpdateProgressBar(this);
      v6 = *p_m_activeRequest;
      nBytesTotal = v6->nBytesTotal;
      if ( nBytesTotal != 0 )
      {
        v8 = 100 * v6->nBytesCurrent / nBytesTotal;
        if ( v8 != this->m_lastPercent )
          this->m_lastPercent = v8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164230
// Name: private: void DownloadManager::StartNewDownload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::StartNewDownload(DownloadManager *this)
{
  vgui::PageTab **p_m_activeRequest; // esi
  int m_Size; // ecx
  RequestContext **m_pMemory; // eax
  int v5; // ecx
  CClientState *BaseLocalClient; // eax
  vgui::PageTab *v7; // [esp-8h] [ebp-10h]

  p_m_activeRequest = (vgui::PageTab **)&this->m_activeRequest;
  if ( this->m_activeRequest == nullptr && this->m_queuedRequests.m_Size != 0 )
  {
    do
    {
      m_Size = this->m_queuedRequests.m_Size;
      if ( m_Size == 0 )
        break;
      m_pMemory = this->m_queuedRequests.m_Memory.m_pMemory;
      v5 = m_Size - 1;
      *p_m_activeRequest = (vgui::PageTab *)*this->m_queuedRequests.m_Memory.m_pMemory;
      if ( v5 > 0 )
        _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: 4 * v5);
      --this->m_queuedRequests.m_Size;
      if ( g_pFileSystem->FileExists(
             this: &g_pFileSystem->IBaseFileSystem,
             a2: (const char *)&(*p_m_activeRequest)->m_pImage,
             a3: nullptr)
        && !CL_ShouldRedownloadFile(filename: (const char *)&(*p_m_activeRequest)->m_pImage) )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
          LoggingSystem_Log(
            a1: LOG_DownloadManager,
            a2: LS_MESSAGE,
            a3: DownloadColor,
            a4: "Skipping existing file %s%s.\n",
            (const char *)&(*p_m_activeRequest)->m_LastNavDirection,
            (const char *)&(*p_m_activeRequest)->m_pImage);
        LOBYTE((*p_m_activeRequest)->__vftable) = 1;
        BYTE1((*p_m_activeRequest)->__vftable) = 1;
        CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
          elem: this->m_completedRequests.m_Size,
          src: p_m_activeRequest);
        *p_m_activeRequest = nullptr;
      }
    }
    while ( *p_m_activeRequest == nullptr );
    if ( *p_m_activeRequest != nullptr )
    {
      if ( !g_pFileSystem->FileExists(
              this: &g_pFileSystem->IBaseFileSystem,
              a2: (const char *)&(*p_m_activeRequest)->m_pImage,
              a3: nullptr)
        || CL_ShouldRedownloadFile(filename: (const char *)&(*p_m_activeRequest)->m_pImage) )
      {
        if ( HIBYTE((*p_m_activeRequest)->__vftable) != 0 )
        {
          DownloadCache::GetCachedData(this: TheDownloadCache, rc: (RequestContext *)*p_m_activeRequest);
          DownloadManager::UpdateProgressBar(this);
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
            LoggingSystem_Log(
              a1: LOG_DownloadManager,
              a2: LS_MESSAGE,
              a3: DownloadColor,
              a4: "Downloading %s%s.\n",
              (const char *)&(*p_m_activeRequest)->m_LastNavDirection,
              (const char *)&(*p_m_activeRequest)->m_pImage);
          v7 = *p_m_activeRequest;
          this->m_lastPercent = 0;
          _CreateSimpleThread(a1: DownloadThread, a2: v7, a3: 0);
        }
        else
        {
          DownloadManager::UpdateProgressBar(this);
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_DownloadManager, a2: 0) != 0 )
            LoggingSystem_Log(
              a1: LOG_DownloadManager,
              a2: LS_MESSAGE,
              a3: DownloadColor,
              a4: "Downloading %s.\n",
              (const char *)&(*p_m_activeRequest)->m_pImage);
          this->m_lastPercent = 0;
          BaseLocalClient = GetBaseLocalClient();
          *(_DWORD *)&(*p_m_activeRequest)->vgui::Button::vgui::Label::vgui::Panel::m_RegisterClass = BaseLocalClient->m_NetChannel->RequestFile(this: BaseLocalClient->m_NetChannel, a2: (const char *)&(*p_m_activeRequest)->m_pImage, a3: false);
        }
      }
      else
      {
        LOBYTE((*p_m_activeRequest)->__vftable) = 1;
        BYTE1((*p_m_activeRequest)->__vftable) = 1;
        CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_completedRequests,
          elem: this->m_completedRequests.m_Size,
          src: p_m_activeRequest);
        *p_m_activeRequest = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164460
// Name: bool CL_DownloadUpdate(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CL_DownloadUpdate()
{
  DownloadManager::PruneCompletedRequests(this: &TheDownloadManager);
  DownloadManager::CheckActiveDownload(this: &TheDownloadManager);
  DownloadManager::StartNewDownload(this: &TheDownloadManager);
  return TheDownloadManager.m_activeRequest != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10164490
// Name: bool CL_FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CL_FileReceived(const char *filename, unsigned int requestID, bool isReplayDemoFile)
{
  return DownloadManager::FileReceived(this: &TheDownloadManager, filename, requestID, isReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x101644B0
// Name: bool CL_FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CL_FileDenied(const char *filename, unsigned int requestID, bool isReplayDemoFile)
{
  return DownloadManager::FileDenied(this: &TheDownloadManager, filename, requestID, isReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x101644D0
// Name: void CL_QueueDownload(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_QueueDownload(char *filename)
{
  char *m_pszString; // eax

  if ( (sv_downloadurl.m_nFlags & 0x1000) != 0 )
  {
    DownloadManager::Queue(this: &TheDownloadManager, baseURL: "FCVAR_NEVER_AS_STRING", gamePath: filename);
  }
  else
  {
    m_pszString = sv_downloadurl.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
    DownloadManager::Queue(this: &TheDownloadManager, baseURL: m_pszString, gamePath: filename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164520
// Name: public: DownloadManager::~DownloadManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DownloadManager::~DownloadManager(DownloadManager *this)
{
  int i; // edi
  char **m_pMemory; // eax
  RequestContext **v4; // eax
  RequestContext **v5; // eax

  DownloadManager::Reset(this);
  for ( i = 0; i < this->m_downloadedMaps.m_Size; ++i )
    free(pMem: this->m_downloadedMaps.m_Memory.m_pMemory[i]);
  this->m_downloadedMaps.m_Size = 0;
  if ( this->m_downloadedMaps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_downloadedMaps.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_downloadedMaps.m_Memory.m_pMemory);
      this->m_downloadedMaps.m_Memory.m_pMemory = nullptr;
    }
    this->m_downloadedMaps.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_downloadedMaps.m_Memory.m_pMemory;
  this->m_downloadedMaps.m_pElements = m_pMemory;
  if ( this->m_downloadedMaps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_downloadedMaps.m_Memory.m_pMemory = nullptr;
    }
    this->m_downloadedMaps.m_Memory.m_nAllocationCount = 0;
  }
  this->m_completedRequests.m_Size = 0;
  if ( this->m_completedRequests.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_completedRequests.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_completedRequests.m_Memory.m_pMemory);
      this->m_completedRequests.m_Memory.m_pMemory = nullptr;
    }
    this->m_completedRequests.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_completedRequests.m_Memory.m_pMemory;
  this->m_completedRequests.m_pElements = v4;
  if ( this->m_completedRequests.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      this->m_completedRequests.m_Memory.m_pMemory = nullptr;
    }
    this->m_completedRequests.m_Memory.m_nAllocationCount = 0;
  }
  this->m_queuedRequests.m_Size = 0;
  if ( this->m_queuedRequests.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_queuedRequests.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_queuedRequests.m_Memory.m_pMemory);
      this->m_queuedRequests.m_Memory.m_pMemory = nullptr;
    }
    this->m_queuedRequests.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_queuedRequests.m_Memory.m_pMemory;
  this->m_queuedRequests.m_pElements = this->m_queuedRequests.m_Memory.m_pMemory;
  if ( this->m_queuedRequests.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_queuedRequests.m_Memory.m_pMemory = nullptr;
    }
    this->m_queuedRequests.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164630
// Name: void CL_HTTPStop_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_HTTPStop_f()
{
  DownloadManager::Reset(this: &TheDownloadManager);
}

//------------------------------------------------------------------------------
// Address: 0x102C6D50
// Name: CloneString_0
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString_0@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)MemAlloc_Alloc(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

} // namespace engine_xlsp
