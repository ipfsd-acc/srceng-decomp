// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: filesystem/filesystem_steam.cpp
// Functions: 73
// ============================================================

#include "filesystem\filesystem_steam.h"

//------------------------------------------------------------------------------
// Address: 0x10019AA0
// Name: void CheckError(unsigned int,struct TSteamError __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckError(unsigned int fp, TSteamError *steamError)
{
  ESteamError eSteamError; // eax
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax

  eSteamError = steamError->eSteamError;
  if ( steamError->eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
  }
  else if ( fp != 0 )
  {
    if ( eSteamError != eSteamErrorNone || g_tLastError.eSteamError != eSteamErrorNone )
    {
      g_pLastErrorFile = fp;
      g_tLastError = *steamError;
    }
  }
  else if ( eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
  {
    g_tLastErrorNoFile = *steamError;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019B30
// Name: class CBaseFileSystem __near * BaseFileSystem_Steam(void)
// Source: json
//------------------------------------------------------------------------------
CFileSystem_Steam *__cdecl BaseFileSystem_Steam()
{
  return &g_FileSystem_Steam;
}

//------------------------------------------------------------------------------
// Address: 0x10019B40
// Name: private: bool CFileSystem_Steam::IsFileInSteamCache2(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileSystem_Steam::IsFileInSteamCache2(CFileSystem_Steam *this, const char *file)
{
  unsigned int v2; // eax
  TSteamElemInfo info; // [esp+0h] [ebp-224h] BYREF
  TSteamError error; // [esp+118h] [ebp-10Ch] BYREF

  if ( this->m_bContentLoaded && !this->m_bSDKToolMode )
  {
    v2 = steam->FindFirst(this: steam, a2: file, a3: eSteamFindRemoteOnly, a4: &info, a5: &error);
    if ( v2 == 0 )
      return 0;
    steam->FindClose(this: steam, a2: v2, a3: &error);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019BB0
// Name: public: virtual void CFileSystem_Steam::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::Shutdown(CFileSystem_Steam *this)
{
  int v2; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  if ( steam != nullptr )
  {
    v2 = _CommandLine(a1: this);
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-steamlocal", a3: 0) == 0
      && !this->m_bSelfMounted
      && steam->UnmountAppFilesystem(this: steam, a2: &steamError) == 0 )
    {
      OutputDebugStringA(lpOutputString: steamError.szDesc);
    }
    steam->Cleanup(this: steam, a2: &steamError);
    if ( this->m_hSteamDLL != nullptr )
    {
      Sys_UnloadModule(pModule: (CSysModule *)this->m_hSteamDLL);
      this->m_hSteamDLL = nullptr;
    }
    this->m_bSteamInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019C50
// Name: private: void CFileSystem_Steam::LoadAndStartSteam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::LoadAndStartSteam(CFileSystem_Steam *this)
{
  const char *SteamInstallPath; // eax
  HINSTANCE__ *m_hSteamDLL; // esi
  FARPROC _f; // eax
  ISteamInterface *v5; // eax
  HWND ForegroundWindow; // eax
  HWND v7; // eax
  char szSteamDLLPath[260]; // [esp+4h] [ebp-210h] BYREF
  TSteamError steamError; // [esp+108h] [ebp-10Ch] BYREF

  if ( this->m_hSteamDLL == nullptr )
  {
    SteamInstallPath = (const char *)_SteamAPI_GetSteamInstallPath();
    if ( SteamInstallPath != nullptr )
    {
      V_ComposeFileName(path: SteamInstallPath, filename: "steam.dll", dest: szSteamDLLPath, destSize: 260);
      this->m_hSteamDLL = (HINSTANCE__ *)Sys_LoadModule(pModuleName: szSteamDLLPath);
    }
    if ( this->m_hSteamDLL == nullptr )
      this->m_hSteamDLL = (HINSTANCE__ *)Sys_LoadModule(pModuleName: "steam.dll");
  }
  m_hSteamDLL = this->m_hSteamDLL;
  if ( m_hSteamDLL != nullptr && (_f = GetProcAddress(hModule: m_hSteamDLL, lpProcName: "_f")) != nullptr )
  {
    v5 = (ISteamInterface *)((int (__cdecl *)(const char *))_f)(a1: "Steam006");
    steam = v5;
  }
  else
  {
    v5 = steam;
  }
  if ( v5 == nullptr )
  {
    _Error(a1: "CFileSystem_Steam::Init() failed: failed to find steam interface\n");
    ForegroundWindow = GetForegroundWindow();
    DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "CFileSystem_Steam::Init() failed: failed to find steam interface",
      lpCaption: "Half-Life FileSystem_Steam Error",
      uType: 0);
    _exit(code: -1);
  }
  if ( v5->Startup(this: v5, a2: 15u, a3: &steamError) == 0 )
  {
    _Error(a1: "SteamStartup() failed: %s\n", steamError.szDesc);
    v7 = GetForegroundWindow();
    DestroyWindow(hWnd: v7);
    MessageBoxA(hWnd: nullptr, lpText: steamError.szDesc, lpCaption: "Half-Life FileSystem_Steam Error", uType: 0);
    _exit(code: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019D80
// Name: protected: virtual struct _iobuf __near * CFileSystem_Steam::FS_fopen(char const __near *,char const __near *,unsigned int,__int64 __near *,class CFileLoadInfo __near *)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__thiscall CFileSystem_Steam::FS_fopen(
        CFileSystem_Steam *this,
        const char *filename,
        const char *options,
        unsigned int flags,
        __int64 *size,
        CFileLoadInfo *pInfo)
{
  const char *v6; // edi
  const char **p_filename; // esi
  unsigned int v9; // edi
  __int64 *v10; // eax
  int v11; // [esp-14h] [ebp-12Ch]
  TSteamError steamError; // [esp+4h] [ebp-114h] BYREF
  unsigned int fileSize; // [esp+110h] [ebp-8h] BYREF
  int bLocal; // [esp+114h] [ebp-4h] BYREF

  v6 = filename;
  if ( this->m_bAssertFilesImmediatelyAvailable
    && !this->m_bCurrentlyLoading
    && !this->IsFileImmediatelyAvailable(this, a2: filename) )
  {
    _Msg(a1: "Steam FS: '%s' not immediately available when not in loading dialog", v6);
  }
  if ( steam == nullptr )
    return nullptr;
  p_filename = (const char **)pInfo;
  if ( pInfo == nullptr )
  {
    LOBYTE(filename) = 0;
    p_filename = &filename;
  }
  v11 = *(unsigned __int8 *)p_filename;
  bLocal = 0;
  v9 = ((int (__stdcall *)(const char *, const char *, int, unsigned int *, int *, TSteamError *))steam->OpenFileEx)(
         a1: v6,
         a2: options,
         a3: v11,
         a4: &fileSize,
         a5: &bLocal,
         a6: &steamError);
  v10 = size;
  *((_BYTE *)p_filename + 1) = bLocal == 0;
  if ( v10 != nullptr )
  {
    *(_DWORD *)v10 = fileSize;
    *((_DWORD *)v10 + 1) = 0;
  }
  CheckError(fp: v9, &steamError);
  return (_iobuf *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x10019E40
// Name: protected: virtual void CFileSystem_Steam::FS_setbufsize(struct _iobuf __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::FS_setbufsize(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10019E50
// Name: public: virtual int CFileSystem_Steam::WaitForResources(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::WaitForResources(CFileSystem_Steam *this, const char *resourcelist)
{
  unsigned int v3; // eax
  bool v4; // zf
  int result; // eax
  TSteamError steamError; // [esp+4h] [ebp-210h] BYREF
  char szResourceList[260]; // [esp+110h] [ebp-104h] BYREF

  V_strncpy(pDest: szResourceList, pSrc: resourcelist, maxLen: 260);
  V_DefaultExtension(path: szResourceList, extension: ".lst", pathStringLength: 260);
  v3 = steam->WaitForResources(this: steam, a2: szResourceList, a3: &steamError);
  v4 = steamError.eSteamError == eSteamErrorNone;
  this->m_hWaitForResourcesCallHandle = v3;
  if ( v4 )
  {
    result = this->m_iCurrentReturnedCallHandle + 1;
    this->m_iCurrentReturnedCallHandle = result;
  }
  else
  {
    _Msg(a1: "SteamWaitForResources() failed: %s\n", steamError.szDesc);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019EF0
// Name: public: virtual bool CFileSystem_Steam::GetWaitForResourcesProgress(int,float __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileSystem_Steam::GetWaitForResourcesProgress(
        CFileSystem_Steam *this,
        int handle,
        float *progress,
        bool *complete)
{
  unsigned int m_hWaitForResourcesCallHandle; // eax
  int bValid; // eax
  bool v8; // bl
  TSteamError steamError; // [esp+Ch] [ebp-214h] BYREF
  TSteamProgress steamProgress; // [esp+118h] [ebp-108h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "GetWaitForResourcesProgress (steam)",
    a3: 0,
    a4: "Steam",
    a5: false,
    a6: 4);
  *progress = 0.0;
  *complete = true;
  if ( this->m_iCurrentReturnedCallHandle != handle )
    goto LABEL_8;
  m_hWaitForResourcesCallHandle = this->m_hWaitForResourcesCallHandle;
  if ( m_hWaitForResourcesCallHandle == 0 )
    goto LABEL_8;
  if ( steam->ProcessCall(this: steam, a2: m_hWaitForResourcesCallHandle, a3: &steamProgress, a4: &steamError) != 0
    && steamError.eSteamError == eSteamErrorNone )
  {
    this->m_hWaitForResourcesCallHandle = 0;
    *complete = true;
    *progress = 1.0;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( steamError.eSteamError != eSteamErrorNotFinishedProcessing )
  {
    this->m_hWaitForResourcesCallHandle = 0;
    _Msg(a1: "SteamProcessCall(SteamWaitForResources()) failed: %s\n", steamError.szDesc);
LABEL_8:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  bValid = steamProgress.bValid;
  if ( steamProgress.bValid != 0 )
    *progress = (double)steamProgress.uPercentDone * 0.0000024414062;
  else
    *progress = 0.0;
  *complete = false;
  v8 = bValid != 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1001A030
// Name: public: virtual void CFileSystem_Steam::CancelWaitForResources(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::CancelWaitForResources(CFileSystem_Steam *this, int handle)
{
  unsigned int m_hWaitForResourcesCallHandle; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  if ( this->m_iCurrentReturnedCallHandle == handle )
  {
    m_hWaitForResourcesCallHandle = this->m_hWaitForResourcesCallHandle;
    if ( m_hWaitForResourcesCallHandle != 0 )
    {
      steam->AbortCall(this: steam, a2: m_hWaitForResourcesCallHandle, a3: &steamError);
      this->m_hWaitForResourcesCallHandle = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A080
// Name: protected: virtual void CFileSystem_Steam::FS_fclose(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::FS_fclose(CFileSystem_Steam *this, _iobuf *fp)
{
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  steam->CloseFile(this: steam, a2: (unsigned int)fp, a3: &steamError);
  CheckError((unsigned int)fp, &steamError);
}

//------------------------------------------------------------------------------
// Address: 0x1001A0C0
// Name: protected: virtual void CFileSystem_Steam::FS_fseek(struct _iobuf __near *,__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::FS_fseek(
        CFileSystem_Steam *this,
        _iobuf *fp,
        __int64 pos,
        ESteamSeekMethod seekType)
{
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  steam->SeekFile(this: steam, a2: (unsigned int)fp, a3: pos, a4: seekType, a5: &steamError);
  CheckError((unsigned int)fp, &steamError);
}

//------------------------------------------------------------------------------
// Address: 0x1001A110
// Name: protected: virtual long CFileSystem_Steam::FS_ftell(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_ftell(CFileSystem_Steam *this, _iobuf *fp)
{
  int result; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  result = steam->TellFile(this: steam, a2: (unsigned int)fp, a3: &steamError);
  if ( steamError.eSteamError != eSteamErrorNone )
  {
    CheckError((unsigned int)fp, &steamError);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A160
// Name: protected: virtual int CFileSystem_Steam::FS_feof(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_feof(CFileSystem_Steam *this, _iobuf *fp)
{
  int v3; // ebx

  v3 = this->FS_ftell(this, a2: fp);
  if ( fp == (_iobuf *)g_pLastErrorFile && g_tLastError.eSteamError == eSteamErrorEOF )
    return 1;
  if ( g_tLastError.eSteamError == eSteamErrorNone )
  {
    ((void (__thiscall *)(CFileSystem_Steam *, _iobuf *, _DWORD, _DWORD, int))this->FS_fseek)(
      a1: this,
      a2: fp,
      a3: 0,
      a4: 0,
      a5: 2);
    if ( v3 == this->FS_ftell(this, a2: fp) )
      return 1;
    ((void (__thiscall *)(CFileSystem_Steam *, _iobuf *, int, int, _DWORD))this->FS_fseek)(
      a1: this,
      a2: fp,
      a3: v3,
      a4: v3 >> 31,
      a5: 0);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A1E0
// Name: protected: virtual unsigned int CFileSystem_Steam::FS_fread(void __near *,unsigned int,unsigned int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileSystem_Steam::FS_fread(
        CFileSystem_Steam *this,
        void *dest,
        unsigned int destSize,
        unsigned int size,
        _iobuf *fp)
{
  unsigned int v5; // edi
  TSteamError steamError; // [esp+8h] [ebp-10Ch] BYREF

  v5 = steam->ReadFile(this: steam, a2: dest, a3: 1u, a4: size, a5: (unsigned int)fp, a6: &steamError);
  CheckError((unsigned int)fp, &steamError);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001A230
// Name: protected: virtual unsigned int CFileSystem_Steam::FS_fwrite(void const __near *,unsigned int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileSystem_Steam::FS_fwrite(
        CFileSystem_Steam *this,
        const void *src,
        unsigned int size,
        _iobuf *fp)
{
  unsigned int v4; // edi
  TSteamError steamError; // [esp+8h] [ebp-10Ch] BYREF

  v4 = steam->WriteFile(this: steam, a2: src, a3: 1u, a4: size, a5: (unsigned int)fp, a6: &steamError);
  CheckError((unsigned int)fp, &steamError);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1001A280
// Name: protected: virtual unsigned int CFileSystem_Steam::FS_vfprintf(struct _iobuf __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__userpurge CFileSystem_Steam::FS_vfprintf@<eax>(
        CFileSystem_Steam *this@<ecx>,
        int a2@<edi>,
        _iobuf *fp,
        const char *fmt,
        char *list)
{
  _iobuf *result; // eax
  _iobuf *v6; // esi
  unsigned int v7; // edi
  char *v8; // esi
  int v9; // ebx

  if ( fp == nullptr || fmt == nullptr )
    return nullptr;
  result = fopen(file: "nul:", mode: "w");
  v6 = result;
  if ( result == nullptr )
    return result;
  v7 = vfprintf(str: result, format: fmt, ap: list);
  fclose(stream: v6);
  if ( v7 == 0 )
    return nullptr;
  v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 1);
  if ( v8 == nullptr )
    return nullptr;
  v9 = _vsnprintf(string: v8, count: v7, format: fmt, ap: list);
  if ( v9 != v7 )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
    return nullptr;
  }
  v8[v7] = 0;
  if ( v9 == ((int (__thiscall *)(CFileSystem_Steam *, char *, int, _iobuf *, int))this->FS_fwrite)(
               a1: this,
               a2: v8,
               a3: v9,
               a4: fp,
               a5: a2) )
  {
    ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
    return (_iobuf *)v9;
  }
  else
  {
    ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A380
// Name: protected: virtual int CFileSystem_Steam::FS_ferror(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Steam::FS_ferror(CFileSystem_Steam *this, _iobuf *fp)
{
  if ( fp == nullptr )
    return g_tLastErrorNoFile.eSteamError != eSteamErrorNone;
  if ( fp == (_iobuf *)g_pLastErrorFile )
    return g_tLastError.eSteamError != eSteamErrorNone;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1001A3C0
// Name: protected: virtual int CFileSystem_Steam::FS_fflush(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_fflush(CFileSystem_Steam *this, _iobuf *fp)
{
  int v2; // edi
  TSteamError steamError; // [esp+8h] [ebp-10Ch] BYREF

  v2 = steam->FlushFile(this: steam, a2: (unsigned int)fp, a3: &steamError);
  CheckError((unsigned int)fp, &steamError);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001A400
// Name: protected: virtual char __near * CFileSystem_Steam::FS_fgets(char __near *,int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileSystem_Steam::FS_fgets(CFileSystem_Steam *this, char *dest, int destSize, _iobuf *fp)
{
  char *v5; // esi
  unsigned __int8 v6; // al
  int v7; // edi
  bool v8; // zf
  unsigned __int8 c; // [esp+Fh] [ebp-1h] BYREF

  v5 = dest;
  v6 = 0;
  v7 = 0;
  c = 0;
  *dest = 0;
  if ( destSize - 1 > 0 )
  {
    while ( v6 != 10 )
    {
      v8 = this->FS_fread(this, a2: &c, a3: 1u, a4: 1u, a5: fp) == 1;
      v6 = c;
      if ( v8 )
      {
        *v5++ = c;
        *v5 = 0;
        ++v7;
      }
      else
      {
        if ( g_tLastError.eSteamError != eSteamErrorEOF || v7 == 0 )
          return nullptr;
        v7 = destSize;
      }
      if ( v7 >= destSize - 1 )
        return v5;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001A480
// Name: protected: virtual int CFileSystem_Steam::FS_stat(char const __near *,struct _stat64i32 __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CFileSystem_Steam::FS_stat@<eax>(
        CFileSystem_Steam *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *path,
        _stat64i32 *buf)
{
  int v7; // ebx
  __int16 v8; // cx
  __int64 v9; // rax
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  TSteamError steamError; // [esp+0h] [ebp-254h] BYREF
  TSteamElemInfo Info; // [esp+10Ch] [ebp-148h] BYREF
  _stat64i32 testBuf; // [esp+224h] [ebp-30h] BYREF

  if ( steam == nullptr )
    return -1;
  memset(dst: (unsigned __int8 *)buf, value: 0, count: sizeof(_stat64i32));
  v7 = ((int (__thiscall *)(ISteamInterface *, const char *, TSteamElemInfo *, TSteamError *, int, int, int))steam->Stat)(
         a1: steam,
         a2: path,
         a3: &Info,
         a4: &steamError,
         a5: a3,
         a6: a4,
         a7: a2);
  if ( v7 == 0 )
  {
    if ( Info.bIsDir != 0 )
    {
      v8 = 0x4000;
      buf->st_size = 0;
    }
    else
    {
      if ( _stat64i32(name: path, buf: &testBuf) == 0 && SLOBYTE(testBuf.st_mode) < 0 )
        buf->st_mode |= 0x80u;
      v8 = 0x8000;
      buf->st_size = Info.uSizeOrCount;
    }
    LODWORD(v9) = Info.lLastAccessTime;
    buf->st_mode |= v8;
    v9 = (int)v9;
    LODWORD(buf->st_atime) = v9;
    LODWORD(v9) = Info.lLastModificationTime;
    HIDWORD(buf->st_atime) = HIDWORD(v9);
    v9 = (int)v9;
    LODWORD(buf->st_mtime) = v9;
    LODWORD(v9) = Info.lCreationTime;
    HIDWORD(buf->st_mtime) = HIDWORD(v9);
    buf->st_ctime = (int)v9;
  }
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
    return v7;
  }
  else
  {
    if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
      g_tLastErrorNoFile = steamError;
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A5B0
// Name: protected: virtual int CFileSystem_Steam::FS_chmod(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_chmod(CFileSystem_Steam *this, const char *path, int pmode)
{
  return _chmod(path, mode: pmode);
}

//------------------------------------------------------------------------------
// Address: 0x1001A5D0
// Name: protected: virtual void __near * CFileSystem_Steam::FS_FindFirstFile(char const __near *,struct _WIN32_FIND_DATAA __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_FindFirstFile(
        CFileSystem_Steam *this,
        const char *findname,
        _WIN32_FIND_DATAA *dat)
{
  int v3; // ebx
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  int result; // eax
  TSteamError steamError; // [esp+8h] [ebp-224h] BYREF
  TSteamElemInfo steamFindInfo; // [esp+114h] [ebp-118h] BYREF

  v3 = steam->FindFirst(this: steam, a2: findname, a3: eSteamFindAll, a4: &steamFindInfo, a5: &steamError);
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
  }
  else if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
  {
    g_tLastErrorNoFile = steamError;
  }
  if ( v3 == 0 )
    return -1;
  strcpy(dat->cFileName, steamFindInfo.cszName);
  if ( steamFindInfo.bIsDir != 0 )
    dat->dwFileAttributes |= 0x10u;
  else
    dat->dwFileAttributes &= ~0x10u;
  result = v3;
  if ( steamFindInfo.bIsLocal != 0 )
    dat->dwFileAttributes &= ~0x1000u;
  else
    dat->dwFileAttributes |= 0x1000u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A6D0
// Name: protected: virtual bool CFileSystem_Steam::FS_FindNextFile(void __near *,struct _WIN32_FIND_DATAA __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystem_Steam::FS_FindNextFile(CFileSystem_Steam *this, void *handle, _WIN32_FIND_DATAA *dat)
{
  bool v3; // bl
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  bool result; // al
  TSteamError steamError; // [esp+8h] [ebp-224h] BYREF
  TSteamElemInfo steamFindInfo; // [esp+114h] [ebp-118h] BYREF

  v3 = steam->FindNext(this: steam, a2: (unsigned int)handle, a3: &steamFindInfo, a4: &steamError) == 0;
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
  }
  else if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
  {
    g_tLastErrorNoFile = steamError;
  }
  if ( !v3 )
    return false;
  strcpy(dat->cFileName, steamFindInfo.cszName);
  result = v3;
  if ( steamFindInfo.bIsDir != 0 )
    dat->dwFileAttributes |= 0x10u;
  else
    dat->dwFileAttributes &= ~0x10u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A7B0
// Name: protected: virtual bool CFileSystem_Steam::FS_FindClose(void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Steam::FS_FindClose(CFileSystem_Steam *this, void *handle)
{
  BOOL v2; // ebx
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  v2 = steam->FindClose(this: steam, a2: (unsigned int)handle, a3: &steamError) == 0;
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
    return v2;
  }
  else
  {
    if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
      g_tLastErrorNoFile = steamError;
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A860
// Name: public: virtual bool CFileSystem_Steam::IsFileImmediatelyAvailable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Steam::IsFileImmediatelyAvailable(CFileSystem_Steam *this, const char *pFileName)
{
  TSteamError steamError; // [esp+0h] [ebp-10Ch] BYREF

  return steam->IsFileImmediatelyAvailable(this: steam, a2: pFileName, a3: &steamError) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A890
// Name: public: virtual void CFileSystem_Steam::GetLocalCopy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::GetLocalCopy(CFileSystem_Steam *this, const char *pFileName)
{
  int (__thiscall *FS_stat)(CBaseFileSystem *, const char *, _stat64i32 *); // eax
  unsigned __int8 *v3; // edi
  HMODULE ModuleHandleA; // eax
  int v5; // eax
  int v6; // ebx
  char *v7; // eax
  unsigned int v8; // esi
  TSteamError steamError; // [esp+4h] [ebp-24Ch] BYREF
  char srchPath[260]; // [esp+110h] [ebp-140h] BYREF
  _stat64i32 StatBuf; // [esp+214h] [ebp-3Ch] BYREF
  CFileSystem_Steam *v12; // [esp+244h] [ebp-Ch]
  char *pEnd; // [esp+248h] [ebp-8h]
  bool bSearch; // [esp+24Fh] [ebp-1h]

  FS_stat = this->FS_stat;
  v12 = this;
  if ( ((int (__stdcall *)(const char *, _stat64i32 *))FS_stat)(a1: pFileName, a2: &StatBuf) == -1 )
  {
    v3 = (unsigned __int8 *)getenv(option: "PATH");
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: srchPath, nSize: 0x104u) != 0 )
    {
      strrchr(string: (unsigned __int8 *)srchPath, chr: 0x5Cu);
      v6 = 0;
      if ( v5 != 0 )
        v6 = v5 - (_DWORD)srchPath;
      bSearch = true;
      if ( v3 != nullptr )
      {
        while ( bSearch )
        {
          strstr(str1: v3, str2: ";");
          pEnd = v7;
          if ( v7 == nullptr )
            bSearch = false;
          if ( v7 - (char *)v3 > v6 )
          {
            v8 = -1 - v6 + v7 - (char *)v3;
            memcpy(dst: (unsigned __int8 *)srchPath, src: &v3[v6 + 1], count: v8);
            strcpy(&srchPath[v8], pFileName);
            if ( v12->FS_stat(this: v12, a2: srchPath, a3: &StatBuf) == 0 )
            {
              steam->GetLocalFileCopy(this: steam, a2: srchPath, a3: &steamError);
              return;
            }
            v7 = pEnd;
          }
          v3 = (unsigned __int8 *)(v7 + 1);
          if ( v7 == (char *)-1 )
            return;
        }
      }
    }
    else
    {
      MessageBoxA(
        hWnd: nullptr,
        lpText: "Failed calling GetModuleFileName",
        lpCaption: "Half-Life Steam Filesystem Error",
        uType: 0);
    }
  }
  else
  {
    steam->GetLocalFileCopy(this: steam, a2: pFileName, a3: &steamError);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AA20
// Name: public: virtual int CFileSystem_Steam::HintResourceNeed(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::HintResourceNeed(CFileSystem_Steam *this, const char *hintlist, int forgetEverything)
{
  int v3; // ebx
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  v3 = steam->HintResourceNeed(this: steam, a2: hintlist, a3: forgetEverything, a4: &steamError);
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
    return v3;
  }
  else
  {
    if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
      g_tLastErrorNoFile = steamError;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AAC0
// Name: public: virtual enum InitReturnVal_t CFileSystem_Steam::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::Init(CFileSystem_Steam *this)
{
  this->m_bSteamInitialized = true;
  this->m_bSelfMounted = false;
  CFileSystem_Steam::LoadAndStartSteam(this);
  return CBaseFileSystem::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001AAE0
// Name: public: virtual class CSysModule __near * CFileSystem_Steam::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CSysModule *__thiscall CFileSystem_Steam::LoadModule(
        CFileSystem_Steam *this,
        const char *pFileName,
        const char *pPathID,
        bool bValidatedDllOnly)
{
  const char *v5; // esi
  int m_Size; // esi
  int v7; // eax
  char *v8; // eax
  int m_nReaders; // ecx
  const char *v10; // eax
  bool v11; // bl
  CSysModule *Module; // esi
  unsigned int v13; // eax
  _BYTE v15[280]; // [esp+Ch] [ebp-448h] BYREF
  _BYTE v16[268]; // [esp+124h] [ebp-330h] BYREF
  char newPathName[260]; // [esp+230h] [ebp-224h] BYREF
  char szNewPath[260]; // [esp+334h] [ebp-120h] BYREF
  int c; // [esp+438h] [ebp-1Ch]
  int v20; // [esp+43Ch] [ebp-18h]
  int i; // [esp+440h] [ebp-14h]
  char szExtension[8]; // [esp+444h] [ebp-10h] BYREF
  CUtlSymbol lookup; // [esp+44Ch] [ebp-8h] BYREF
  CUtlSymbol v24; // [esp+452h] [ebp-2h]

  CBaseFileSystem::ParsePathID(this, pFilename: &pFileName, &pPathID, tempPathID: szNewPath);
  strcpy(szExtension, ".dll");
  V_strncpy(pDest: szNewPath, pSrc: pFileName, maxLen: 260);
  if ( V_stristr(pStr: szNewPath, pSearch: szExtension) == nullptr )
    V_strncat(pDest: szNewPath, pSrc: szExtension, destBufferSize: 0x104u, max_chars_to_copy: -1);
  CBaseFileSystem::LogFileAccess(this, pFullFileName: szNewPath);
  v5 = pPathID;
  if ( pPathID == nullptr )
  {
    v5 = "EXECUTABLE_PATH";
    pPathID = "EXECUTABLE_PATH";
  }
  if ( (g_PathIDTable.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)&g_PathIDTable.m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &g_PathIDTable.m_lock);
  }
  else
  {
    g_PathIDTable.m_lock.m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::AddString(this: &g_PathIDTable, result: &lookup, pString: v5);
  g_PathIDTable.m_lock.m_writerId = 0;
  g_PathIDTable.m_lock.m_lockInfo.m_i32 = 0;
  m_Size = this->m_SearchPaths.m_Size;
  c = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    v7 = 0;
    v20 = 0;
    do
    {
      v8 = (char *)this->m_SearchPaths.m_Memory.m_pMemory + v7;
      if ( *((_DWORD *)v8 + 4) == 0 && *(_WORD *)(*((_DWORD *)v8 + 1) + 2) == lookup.m_Id )
      {
        v24.m_Id = *((_WORD *)v8 + 5);
        if ( (g_PathIDTable.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
          || (m_nReaders = g_PathIDTable.m_lock.m_lockInfo.m_nReaders,
              _InterlockedCompareExchange(
                (volatile signed __int32 *)&g_PathIDTable.m_lock,
                g_PathIDTable.m_lock.m_lockInfo.m_nReaders + 1,
                g_PathIDTable.m_lock.m_lockInfo.m_nReaders) != m_nReaders) )
        {
          CThreadSpinRWLock::SpinLockForRead(this: &g_PathIDTable.m_lock);
        }
        v10 = CUtlSymbolTable::String(this: &g_PathIDTable, id: v24);
        _InterlockedExchangeAdd((volatile signed __int32 *)&g_PathIDTable.m_lock, 0xFFFFFFFF);
        V_snprintf(pDest: newPathName, maxLen: 260, pFormat: "%s%s", v10, szNewPath);
        if ( !bValidatedDllOnly || CFileSystem_Steam::IsFileInSteamCache2(this, file: newPathName) != 0 )
        {
          v11 = !this->m_bSDKToolMode;
          if ( !IsDebuggerPresent() && v11 )
            this->GetLocalCopy(this, a2: newPathName);
          Module = Sys_LoadModule(pModuleName: newPathName);
          if ( Module != nullptr )
          {
            if ( !bValidatedDllOnly || CFileSystem_Steam::IsFileInSteamCache2(this, file: newPathName) != 0 )
              return Module;
            return nullptr;
          }
          m_Size = c;
        }
      }
      v7 = v20 + 24;
      ++i;
      v20 += 24;
    }
    while ( i < m_Size );
  }
  if ( bValidatedDllOnly )
  {
    if ( this->m_bContentLoaded && !this->m_bSDKToolMode )
    {
      v13 = steam->FindFirst(
              this: steam,
              a2: szNewPath,
              a3: eSteamFindRemoteOnly,
              a4: (TSteamElemInfo *)v15,
              a5: (TSteamError *)v16);
      if ( v13 == 0 )
        return nullptr;
      steam->FindClose(this: steam, a2: v13, a3: (TSteamError *)v16);
    }
    return Sys_LoadModule(pModuleName: szNewPath);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001ADA0
// Name: void MountDependencies(int,class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MountDependencies(unsigned int iAppId, CUtlMemory<vgui::TreeNode *,int> *depList)
{
  unsigned int v2; // edi
  unsigned int v3; // ebx
  int m_pMemory; // edi
  int v5; // eax
  unsigned int *v6; // ecx
  int m_nAllocationCount; // eax
  unsigned int *v8; // ecx
  int v9; // eax
  unsigned int *v10; // eax
  char v11; // [esp+8h] [ebp-2260h] BYREF
  char v12; // [esp+808h] [ebp-1A60h] BYREF
  char v13; // [esp+1008h] [ebp-1260h] BYREF
  char v14; // [esp+1808h] [ebp-A60h] BYREF
  unsigned int v15[66]; // [esp+2008h] [ebp-260h] BYREF
  _DWORD v16[3]; // [esp+2110h] [ebp-158h] BYREF
  char v17[256]; // [esp+211Ch] [ebp-14Ch] BYREF
  _DWORD v18[16]; // [esp+221Ch] [ebp-4Ch] BYREF
  int v19; // [esp+225Ch] [ebp-Ch]
  int v20; // [esp+2260h] [ebp-8h] BYREF
  int v21; // [esp+2264h] [ebp-4h] BYREF

  v18[0] = &v11;
  v2 = iAppId;
  v18[1] = 2048;
  v18[2] = &v12;
  v18[3] = 2048;
  v18[5] = 2048;
  v18[7] = 2048;
  v18[6] = &v14;
  v18[4] = &v13;
  steam->EnumerateApp(this: steam, a2: iAppId, a3: (TSteamApp *)v18, a4: (TSteamError *)v16);
  if ( v16[0] != 0 )
    _Error(a1: "EnumerateApp( %d ) failed: %s", iAppId, v17);
  v3 = 0;
  if ( v19 > 0 )
  {
    while ( 1 )
    {
      steam->EnumerateAppDependency(
        this: steam,
        a2: v2,
        a3: v3,
        a4: (TSteamAppDependencyInfo *)v15,
        a5: (TSteamError *)v16);
      if ( v16[0] != 0 )
        _Error(a1: "EnumerateAppDependency( %d, %d ) failed: %s", v2, v3, v17);
      m_pMemory = (int)depList[1].m_pMemory;
      v5 = 0;
      if ( m_pMemory <= 0 )
        goto LABEL_14;
      v6 = (unsigned int *)depList->m_pMemory;
      while ( *v6 != v15[0] )
      {
        ++v5;
        ++v6;
        if ( v5 >= m_pMemory )
          goto LABEL_14;
      }
      if ( v5 == -1 )
      {
LABEL_14:
        m_nAllocationCount = depList->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CPackedStore *,int>::Grow(this: depList, num: m_pMemory - m_nAllocationCount + 1);
        ++depList[1].m_pMemory;
        v8 = (unsigned int *)depList->m_pMemory;
        v9 = (int)depList[1].m_pMemory - m_pMemory - 1;
        depList[1].m_nAllocationCount = (int)depList->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (unsigned int *)&depList->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = v15[0];
        v21 = 0;
        v20 = 0;
        steam->IsAppSubscribed(this: steam, a2: v15[0], a3: &v21, a4: &v20, a5: (TSteamError *)v16);
        if ( v21 != 0 )
        {
          steam->MountFilesystem(this: steam, a2: v15[0], a3: defaultValue, a4: (TSteamError *)v16);
          if ( v16[0] != 0 && v16[0] != 104 )
            _Error(a1: "MountFilesystem( %d ) failed: %s", v15[0], v17);
        }
      }
      if ( (int)++v3 >= v19 )
        break;
      v2 = iAppId;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AF80
// Name: public: virtual enum FilesystemMountRetval_t CFileSystem_Steam::MountSteamContent(int)
// Source: json
//------------------------------------------------------------------------------
FilesystemMountRetval_t __thiscall CFileSystem_Steam::MountSteamContent(CFileSystem_Steam *this, int nExtraAppId)
{
  ISteamInterface *v3; // ecx
  char *v4; // ebx
  HWND ForegroundWindow; // eax
  unsigned int v7; // [esp-8h] [ebp-1B8h]
  TSteamError steamError; // [esp+Ch] [ebp-1A4h] BYREF
  char szMainAppId[128]; // [esp+118h] [ebp-98h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > depList; // [esp+198h] [ebp-18h] BYREF
  int loggedIn; // [esp+1ACh] [ebp-4h] BYREF

  this->m_bContentLoaded = true;
  v3 = steam;
  v4 = nullptr;
  if ( steam == nullptr )
  {
    CFileSystem_Steam::LoadAndStartSteam(this);
    v3 = steam;
  }
  loggedIn = 0;
  if ( v3->IsLoggedIn(this: v3, a2: &loggedIn, a3: &steamError) != 0 && loggedIn == 0 )
  {
    this->m_bSelfMounted = true;
    return FILESYSTEM_MOUNT_OK;
  }
  if ( nExtraAppId == -1 )
  {
    if ( steam->MountAppFilesystem(this: steam, a2: &steamError) == 0 )
    {
      _Error(a1: "MountAppFilesystem() failed: %s\n", steamError.szDesc);
      ForegroundWindow = GetForegroundWindow();
      DestroyWindow(hWnd: ForegroundWindow);
      MessageBoxA(hWnd: nullptr, lpText: steamError.szDesc, lpCaption: "Half-Life FileSystem_Steam Error", uType: 0);
      _exit(code: -1);
    }
    return FILESYSTEM_MOUNT_OK;
  }
  this->m_bSDKToolMode = true;
  memset(&depList, 0, sizeof(depList));
  if ( nExtraAppId >= -1 )
  {
    if ( GetEnvironmentVariableA(lpName: "steamappid", lpBuffer: szMainAppId, nSize: 0x80u) != 0 )
      v4 = szMainAppId;
    else
      _Error(a1: "Extra App ID set to %d, but no SteamAppId.", nExtraAppId);
    MountDependencies(iAppId: nExtraAppId, (CUtlMemory<vgui::TreeNode *,int> *)&depList);
    v7 = atoi(nptr: v4);
    MountDependencies(iAppId: v7, (CUtlMemory<vgui::TreeNode *,int> *)&depList);
  }
  else
  {
    MountDependencies(iAppId: -nExtraAppId, (CUtlMemory<vgui::TreeNode *,int> *)&depList);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&depList);
  return FILESYSTEM_MOUNT_OK;
}

//------------------------------------------------------------------------------
// Address: 0x100B28B0
// Name: _dynamic_initializer_for__filesystem_buffer_size__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_buffer_size__()
{
  ConVar::ConVar(
    this: &filesystem_buffer_size,
    pName: "filesystem_buffer_size",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Size of per file buffers. 0 for none");
  return atexit(func: dynamic_atexit_destructor_for__filesystem_buffer_size__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2CF0
// Name: _dynamic_initializer_for__filesystem_unbuffered_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_unbuffered_io__()
{
  ConVar::ConVar(
    this: &filesystem_unbuffered_io,
    pName: "filesystem_unbuffered_io",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: defaultValue);
  return atexit(func: dynamic_atexit_destructor_for__filesystem_unbuffered_io__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2D20
// Name: _dynamic_initializer_for__filesystem_native__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_native__()
{
  ConVar::ConVar(
    this: &filesystem_native,
    pName: "filesystem_native",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use native FS or STDIO");
  return atexit(func: dynamic_atexit_destructor_for__filesystem_native__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2D50
// Name: _dynamic_initializer_for__filesystem_max_stdio_read__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_max_stdio_read__()
{
  ConVar::ConVar(
    this: &filesystem_max_stdio_read,
    pName: "filesystem_max_stdio_read",
    pDefaultValue: "16",
    flags: 0,
    pHelpString: defaultValue);
  return atexit(func: dynamic_atexit_destructor_for__filesystem_max_stdio_read__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2D80
// Name: _dynamic_initializer_for__filesystem_report_buffered_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_report_buffered_io__()
{
  ConVar::ConVar(
    this: &filesystem_report_buffered_io,
    pName: "filesystem_report_buffered_io",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__filesystem_report_buffered_io__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2DB0
// Name: _dynamic_initializer_for__filesystem_use_overlapped_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filesystem_use_overlapped_io__()
{
  ConVar::ConVar(
    this: &filesystem_use_overlapped_io,
    pName: "filesystem_use_overlapped_io",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: defaultValue);
  return atexit(func: dynamic_atexit_destructor_for__filesystem_use_overlapped_io__);
}

//------------------------------------------------------------------------------
// Address: 0x100B39B0
// Name: _dynamic_atexit_destructor_for__filesystem_buffer_size__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_buffer_size__()
{
  ConVar::~ConVar(this: &filesystem_buffer_size);
}

//------------------------------------------------------------------------------
// Address: 0x100B3BA0
// Name: _dynamic_atexit_destructor_for__filesystem_unbuffered_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_unbuffered_io__()
{
  ConVar::~ConVar(this: &filesystem_unbuffered_io);
}

//------------------------------------------------------------------------------
// Address: 0x100B3BB0
// Name: _dynamic_atexit_destructor_for__filesystem_native__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_native__()
{
  ConVar::~ConVar(this: &filesystem_native);
}

//------------------------------------------------------------------------------
// Address: 0x100B3BC0
// Name: _dynamic_atexit_destructor_for__filesystem_max_stdio_read__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_max_stdio_read__()
{
  ConVar::~ConVar(this: &filesystem_max_stdio_read);
}

//------------------------------------------------------------------------------
// Address: 0x100B3BD0
// Name: _dynamic_atexit_destructor_for__filesystem_report_buffered_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_report_buffered_io__()
{
  ConVar::~ConVar(this: &filesystem_report_buffered_io);
}

//------------------------------------------------------------------------------
// Address: 0x100B3BE0
// Name: _dynamic_atexit_destructor_for__filesystem_use_overlapped_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__filesystem_use_overlapped_io__()
{
  ConVar::~ConVar(this: &filesystem_use_overlapped_io);
}

//------------------------------------------------------------------------------
// Address: 0x100B28E0
// Name: _dynamic_initializer_for__g_FileOpenDuplicateTimes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileOpenDuplicateTimes__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FileOpenDuplicateTimes__);
}

//------------------------------------------------------------------------------
// Address: 0x100B28F0
// Name: _dynamic_initializer_for__g_FileOpenDuplicateTimesMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileOpenDuplicateTimesMutex__()
{
  g_FileOpenDuplicateTimesMutex.m_ownerID = 0;
  g_FileOpenDuplicateTimesMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B2DE0
// Name: _dynamic_initializer_for__g_ThreadIOEvents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ThreadIOEvents__()
{
  if ( ((unsigned __int8)&g_ThreadIOEvents & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_ThreadIOEvents = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_ThreadIOEvents__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2E10
// Name: _dynamic_initializer_for__g_FileSystem_Steam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileSystem_Steam__()
{
  CBaseFileSystem::CBaseFileSystem(this: &g_FileSystem_Steam);
  g_FileSystem_Steam.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystem_Steam_vtbl *)&CFileSystem_Steam::`vftable'{for `IAppSystem'};
  g_FileSystem_Steam.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CFileSystem_Steam::`vftable'{for `IBaseFileSystem'};
  *(_DWORD *)&g_FileSystem_Steam.m_bSteamInitialized = 0x1000000;
  g_FileSystem_Steam.m_hWaitForResourcesCallHandle = 0;
  g_FileSystem_Steam.m_iCurrentReturnedCallHandle = 1;
  g_FileSystem_Steam.m_hSteamDLL = nullptr;
  *(_WORD *)&g_FileSystem_Steam.m_bContentLoaded = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_FileSystem_Steam__);
}

//------------------------------------------------------------------------------
// Address: 0x100B39C0
// Name: _dynamic_atexit_destructor_for__fs_dump_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_dump_open_duplicate_times_command__()
{
  ConCommand::~ConCommand(this: &fs_dump_open_duplicate_times_command);
}

//------------------------------------------------------------------------------
// Address: 0x100B39D0
// Name: _dynamic_atexit_destructor_for__fs_clear_open_duplicate_times_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_clear_open_duplicate_times_command__()
{
  ConCommand::~ConCommand(this: &fs_clear_open_duplicate_times_command);
}

//------------------------------------------------------------------------------
// Address: 0x100B39E0
// Name: _dynamic_atexit_destructor_for__fs_fios_flush_cache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_flush_cache_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_flush_cache_command);
}

//------------------------------------------------------------------------------
// Address: 0x100B39F0
// Name: _dynamic_atexit_destructor_for__fs_fios_print_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_print_prefetches_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_print_prefetches_command);
}

//------------------------------------------------------------------------------
// Address: 0x100B3A00
// Name: _dynamic_atexit_destructor_for__fs_fios_prefetch_file_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_prefetch_file_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_prefetch_file_command);
}

//------------------------------------------------------------------------------
// Address: 0x100B3A10
// Name: _dynamic_atexit_destructor_for__fs_fios_prefetch_file_in_pack_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_prefetch_file_in_pack_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_prefetch_file_in_pack_command);
}

//------------------------------------------------------------------------------
// Address: 0x100B3A20
// Name: _dynamic_atexit_destructor_for__fs_fios_cancel_prefetches_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_fios_cancel_prefetches_command__()
{
  ConCommand::~ConCommand(this: &fs_fios_cancel_prefetches_command);
}

//------------------------------------------------------------------------------
// Address: 0x100B3A30
// Name: _dynamic_atexit_destructor_for__g_PathIDTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PathIDTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_PathIDTable);
}

//------------------------------------------------------------------------------
// Address: 0x100B3A40
// Name: _dynamic_atexit_destructor_for__s_IoStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_IoStats__()
{
  s_IoStats.__vftable = (CIoStats_vtbl *)&IIoStats::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100B3A50
// Name: _dynamic_atexit_destructor_for__g_pszReadFilename__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pszReadFilename__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_pszReadFilename);
}

//------------------------------------------------------------------------------
// Address: 0x100B3A60
// Name: _dynamic_atexit_destructor_for__g_XLSPPatchZipBuffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_XLSPPatchZipBuffer__()
{
  if ( g_XLSPPatchZipBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_XLSPPatchZipBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_XLSPPatchZipBuffer.m_Memory.m_pMemory);
      g_XLSPPatchZipBuffer.m_Memory.m_pMemory = nullptr;
    }
    g_XLSPPatchZipBuffer.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3AA0
// Name: _dynamic_atexit_destructor_for__g_FileOpenDuplicateTimes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileOpenDuplicateTimes__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_FileOpenDuplicateTimes);
}

//------------------------------------------------------------------------------
// Address: 0x100B3BF0
// Name: _dynamic_atexit_destructor_for__g_FileSystem_Stdio__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileSystem_Stdio__()
{
  g_FileSystem_Stdio.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystem_Stdio_vtbl *)&CFileSystem_Stdio::`vftable'{for `IAppSystem'};
  g_FileSystem_Stdio.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CFileSystem_Stdio::`vftable'{for `IBaseFileSystem'};
  CBaseFileSystem::~CBaseFileSystem(this: &g_FileSystem_Stdio);
}

//------------------------------------------------------------------------------
// Address: 0x100B3C10
// Name: _dynamic_atexit_destructor_for__g_ThreadIOEvents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ThreadIOEvents__()
{
  CTSPool<CThreadEvent>::~CTSPool<CThreadEvent>(this: &g_ThreadIOEvents.m_Events);
}

//------------------------------------------------------------------------------
// Address: 0x100B3C20
// Name: _dynamic_atexit_destructor_for__g_FileSystem_Steam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileSystem_Steam__()
{
  g_FileSystem_Steam.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystem_Steam_vtbl *)&CFileSystem_Steam::`vftable'{for `IAppSystem'};
  g_FileSystem_Steam.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CFileSystem_Steam::`vftable'{for `IBaseFileSystem'};
  g_FileSystem_Steam.m_bSteamInitialized = false;
  CBaseFileSystem::~CBaseFileSystem(this: &g_FileSystem_Steam);
}

//------------------------------------------------------------------------------
// Address: 0x100B3C50
// Name: _DataMapInit_ZIP_EndOfCentralDirRecord__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_EndOfCentralDirRecord__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x100B3C60
// Name: _DataMapInit_ZIP_FileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_FileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x100B3C70
// Name: _DataMapInit_ZIP_LocalFileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_LocalFileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

//------------------------------------------------------------------------------
// Address: 0x100B3C80
// Name: _DataMapInit_ZIP_PreloadHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_PreloadHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x100B3C90
// Name: _DataMapInit_ZIP_PreloadDirectoryEntry__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_PreloadDirectoryEntry__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x100B3CA0
// Name: _dynamic_atexit_destructor_for__g_ZipUtils__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ZipUtils__()
{
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short> > *)&g_ZipUtils);
  if ( g_ZipUtils.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ZipUtils.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ZipUtils.m_Memory.m_pMemory);
      g_ZipUtils.m_Memory.m_pMemory = nullptr;
    }
    g_ZipUtils.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3CF0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x100B3D00
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100B3D50
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B3D90
// Name: _dynamic_atexit_destructor_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_OverridenColorSymbols);
}

// ============================================================
// Overlay from FileSystem_Steam (Missing functions)
// ============================================================
namespace FileSystem_Steam {

//------------------------------------------------------------------------------
// Address: 0x10014010
// Name: void CheckError(unsigned int,struct TSteamError __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckError(unsigned int fp, TSteamError *steamError)
{
  ESteamError eSteamError; // eax
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax

  eSteamError = steamError->eSteamError;
  if ( steamError->eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
  }
  else if ( fp != 0 )
  {
    if ( eSteamError != eSteamErrorNone || g_tLastError.eSteamError != eSteamErrorNone )
    {
      g_pLastErrorFile = fp;
      g_tLastError = *steamError;
    }
  }
  else if ( eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
  {
    g_tLastErrorNoFile = *steamError;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100140C0
// Name: private: bool CFileSystem_Steam::IsFileInSteamCache2(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileSystem_Steam::IsFileInSteamCache2(CFileSystem_Steam *this, const char *file)
{
  unsigned int v2; // eax
  TSteamElemInfo info; // [esp+0h] [ebp-224h] BYREF
  TSteamError error; // [esp+118h] [ebp-10Ch] BYREF

  if ( this->m_bContentLoaded && !this->m_bSDKToolMode )
  {
    v2 = steam->FindFirst(this: steam, a2: file, a3: eSteamFindRemoteOnly, a4: &info, a5: &error);
    if ( v2 == 0 )
      return 0;
    steam->FindClose(this: steam, a2: v2, a3: &error);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014130
// Name: public: virtual void __near * CFileSystem_Steam::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFileSystem_Steam *__thiscall CFileSystem_Steam::QueryInterface(CFileSystem_Steam *this, const char *pInterfaceName)
{
  int v3; // eax

  v3 = _V_strlen(str: "VFileSystem017");
  if ( V_strncmp(s1: pInterfaceName, s2: "VFileSystem017", count: v3 + 1) != 0 )
    return (CFileSystem_Steam *)CBaseFileSystem::QueryInterface(this, pInterfaceName);
  else
    return this;
}

//------------------------------------------------------------------------------
// Address: 0x10014170
// Name: public: virtual void CFileSystem_Steam::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::Shutdown(CFileSystem_Steam *this)
{
  int v2; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  if ( steam != nullptr )
  {
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-steamlocal", a3: 0) == 0
      && !this->m_bSelfMounted
      && steam->UnmountAppFilesystem(this: steam, a2: &steamError) == 0 )
    {
      OutputDebugStringA(lpOutputString: steamError.szDesc);
    }
    steam->Cleanup(this: steam, a2: &steamError);
    if ( this->m_hSteamDLL != nullptr )
    {
      Sys_UnloadModule(pModule: (struct CSysModule *)this->m_hSteamDLL);
      this->m_hSteamDLL = nullptr;
    }
    this->m_bSteamInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014210
// Name: private: void CFileSystem_Steam::LoadAndStartSteam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::LoadAndStartSteam(CFileSystem_Steam *this)
{
  const char *SteamInstallPath; // eax
  HINSTANCE__ *m_hSteamDLL; // esi
  FARPROC _f; // eax
  ISteamInterface *v5; // eax
  HWND ForegroundWindow; // eax
  HWND v7; // eax
  char szSteamDLLPath[260]; // [esp+4h] [ebp-210h] BYREF
  TSteamError steamError; // [esp+108h] [ebp-10Ch] BYREF

  if ( this->m_hSteamDLL == nullptr )
  {
    SteamInstallPath = (const char *)_SteamAPI_GetSteamInstallPath();
    if ( SteamInstallPath != nullptr )
    {
      V_ComposeFileName(path: SteamInstallPath, filename: "steam.dll", dest: szSteamDLLPath, destSize: 260);
      this->m_hSteamDLL = (HINSTANCE__ *)Sys_LoadModule(pModuleName: szSteamDLLPath);
    }
    if ( this->m_hSteamDLL == nullptr )
      this->m_hSteamDLL = (HINSTANCE__ *)Sys_LoadModule(pModuleName: "steam.dll");
  }
  m_hSteamDLL = this->m_hSteamDLL;
  if ( m_hSteamDLL != nullptr && (_f = GetProcAddress(hModule: m_hSteamDLL, lpProcName: "_f")) != nullptr )
  {
    v5 = (ISteamInterface *)((int (__cdecl *)(const char *))_f)(a1: "Steam006");
    steam = v5;
  }
  else
  {
    v5 = steam;
  }
  if ( v5 == nullptr )
  {
    _Error(a1: "CFileSystem_Steam::Init() failed: failed to find steam interface\n");
    ForegroundWindow = GetForegroundWindow();
    DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "CFileSystem_Steam::Init() failed: failed to find steam interface",
      lpCaption: "Half-Life FileSystem_Steam Error",
      uType: 0);
    _exit(code: -1);
  }
  if ( v5->Startup(this: v5, a2: 15u, a3: &steamError) == 0 )
  {
    _Error(a1: "SteamStartup() failed: %s\n", steamError.szDesc);
    v7 = GetForegroundWindow();
    DestroyWindow(hWnd: v7);
    MessageBoxA(hWnd: nullptr, lpText: steamError.szDesc, lpCaption: "Half-Life FileSystem_Steam Error", uType: 0);
    _exit(code: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014340
// Name: protected: virtual struct _iobuf __near * CFileSystem_Steam::FS_fopen(char const __near *,char const __near *,unsigned int,__int64 __near *,class CFileLoadInfo __near *)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__thiscall CFileSystem_Steam::FS_fopen(
        CFileSystem_Steam *this,
        const char *filename,
        const char *options,
        unsigned int flags,
        __int64 *size,
        CFileLoadInfo *pInfo)
{
  const char *v6; // edi
  const char **p_filename; // esi
  unsigned int v9; // edi
  __int64 *v10; // eax
  int v11; // [esp-14h] [ebp-12Ch]
  TSteamError steamError; // [esp+4h] [ebp-114h] BYREF
  unsigned int fileSize; // [esp+110h] [ebp-8h] BYREF
  int bLocal; // [esp+114h] [ebp-4h] BYREF

  v6 = filename;
  if ( this->m_bAssertFilesImmediatelyAvailable
    && !this->m_bCurrentlyLoading
    && !this->IsFileImmediatelyAvailable(this, a2: filename) )
  {
    _Msg(a1: "Steam FS: '%s' not immediately available when not in loading dialog", v6);
  }
  if ( steam == nullptr )
    return nullptr;
  p_filename = (const char **)pInfo;
  if ( pInfo == nullptr )
  {
    LOBYTE(filename) = 0;
    p_filename = &filename;
  }
  v11 = *(unsigned __int8 *)p_filename;
  bLocal = 0;
  v9 = ((int (__stdcall *)(const char *, const char *, int, unsigned int *, int *, TSteamError *))steam->OpenFileEx)(
         a1: v6,
         a2: options,
         a3: v11,
         a4: &fileSize,
         a5: &bLocal,
         a6: &steamError);
  v10 = size;
  *((_BYTE *)p_filename + 1) = bLocal == 0;
  if ( v10 != nullptr )
  {
    *(_DWORD *)v10 = fileSize;
    *((_DWORD *)v10 + 1) = 0;
  }
  CheckError(fp: v9, &steamError);
  return (_iobuf *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x10014400
// Name: protected: virtual void CFileSystem_Steam::FS_setbufsize(struct _iobuf __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::FS_setbufsize(CFileSystem_Steam *this, _iobuf *fp, _iobuf *nBytes)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10014410
// Name: public: virtual int CFileSystem_Steam::WaitForResources(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::WaitForResources(CFileSystem_Steam *this, const char *resourcelist)
{
  unsigned int v3; // eax
  bool v4; // zf
  int result; // eax
  TSteamError steamError; // [esp+4h] [ebp-210h] BYREF
  char szResourceList[260]; // [esp+110h] [ebp-104h] BYREF

  V_strncpy(pDest: szResourceList, pSrc: resourcelist, maxLen: 260);
  V_DefaultExtension(path: szResourceList, extension: ".lst", pathStringLength: 260);
  v3 = steam->WaitForResources(this: steam, a2: szResourceList, a3: &steamError);
  v4 = steamError.eSteamError == eSteamErrorNone;
  this->m_hWaitForResourcesCallHandle = v3;
  if ( v4 )
  {
    result = this->m_iCurrentReturnedCallHandle + 1;
    this->m_iCurrentReturnedCallHandle = result;
  }
  else
  {
    _Msg(a1: "SteamWaitForResources() failed: %s\n", steamError.szDesc);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100144B0
// Name: public: virtual bool CFileSystem_Steam::GetWaitForResourcesProgress(int,float __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileSystem_Steam::GetWaitForResourcesProgress(
        CFileSystem_Steam *this,
        int handle,
        float *progress,
        bool *complete)
{
  unsigned int m_hWaitForResourcesCallHandle; // eax
  int bValid; // eax
  bool v8; // bl
  TSteamError steamError; // [esp+Ch] [ebp-214h] BYREF
  TSteamProgress steamProgress; // [esp+118h] [ebp-108h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "GetWaitForResourcesProgress (steam)",
    a3: 0,
    a4: "Steam",
    a5: false,
    a6: 4);
  *progress = 0.0;
  *complete = true;
  if ( this->m_iCurrentReturnedCallHandle != handle )
    goto LABEL_8;
  m_hWaitForResourcesCallHandle = this->m_hWaitForResourcesCallHandle;
  if ( m_hWaitForResourcesCallHandle == 0 )
    goto LABEL_8;
  if ( steam->ProcessCall(this: steam, a2: m_hWaitForResourcesCallHandle, a3: &steamProgress, a4: &steamError) != 0
    && steamError.eSteamError == eSteamErrorNone )
  {
    this->m_hWaitForResourcesCallHandle = 0;
    *complete = true;
    *progress = 1.0;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( steamError.eSteamError != eSteamErrorNotFinishedProcessing )
  {
    this->m_hWaitForResourcesCallHandle = 0;
    _Msg(a1: "SteamProcessCall(SteamWaitForResources()) failed: %s\n", steamError.szDesc);
LABEL_8:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  bValid = steamProgress.bValid;
  if ( steamProgress.bValid != 0 )
    *progress = (double)steamProgress.uPercentDone * 0.0000024414062;
  else
    *progress = 0.0;
  *complete = false;
  v8 = bValid != 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100145F0
// Name: public: virtual void CFileSystem_Steam::CancelWaitForResources(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::CancelWaitForResources(CFileSystem_Steam *this, int handle)
{
  unsigned int m_hWaitForResourcesCallHandle; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  if ( this->m_iCurrentReturnedCallHandle == handle )
  {
    m_hWaitForResourcesCallHandle = this->m_hWaitForResourcesCallHandle;
    if ( m_hWaitForResourcesCallHandle != 0 )
    {
      steam->AbortCall(this: steam, a2: m_hWaitForResourcesCallHandle, a3: &steamError);
      this->m_hWaitForResourcesCallHandle = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014640
// Name: protected: virtual void CFileSystem_Steam::FS_fclose(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::FS_fclose(CFileSystem_Steam *this, _iobuf *fp)
{
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  steam->CloseFile(this: steam, a2: (unsigned int)fp, a3: &steamError);
  CheckError((unsigned int)fp, &steamError);
}

//------------------------------------------------------------------------------
// Address: 0x10014680
// Name: protected: virtual void CFileSystem_Steam::FS_fseek(struct _iobuf __near *,__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::FS_fseek(
        CFileSystem_Steam *this,
        _iobuf *fp,
        __int64 pos,
        ESteamSeekMethod seekType)
{
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  steam->SeekFile(this: steam, a2: (unsigned int)fp, a3: pos, a4: seekType, a5: &steamError);
  CheckError((unsigned int)fp, &steamError);
}

//------------------------------------------------------------------------------
// Address: 0x100146D0
// Name: protected: virtual long CFileSystem_Steam::FS_ftell(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_ftell(CFileSystem_Steam *this, _iobuf *fp)
{
  int result; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  result = steam->TellFile(this: steam, a2: (unsigned int)fp, a3: &steamError);
  if ( steamError.eSteamError != eSteamErrorNone )
  {
    CheckError((unsigned int)fp, &steamError);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014720
// Name: protected: virtual int CFileSystem_Steam::FS_feof(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_feof(CFileSystem_Steam *this, _iobuf *fp)
{
  int v3; // ebx

  v3 = this->FS_ftell(this, a2: fp);
  if ( fp == (_iobuf *)g_pLastErrorFile && g_tLastError.eSteamError == eSteamErrorEOF )
    return 1;
  if ( g_tLastError.eSteamError == eSteamErrorNone )
  {
    ((void (__thiscall *)(CFileSystem_Steam *, _iobuf *, _DWORD, _DWORD, int))this->FS_fseek)(
      a1: this,
      a2: fp,
      a3: 0,
      a4: 0,
      a5: 2);
    if ( v3 == this->FS_ftell(this, a2: fp) )
      return 1;
    ((void (__thiscall *)(CFileSystem_Steam *, _iobuf *, int, int, _DWORD))this->FS_fseek)(
      a1: this,
      a2: fp,
      a3: v3,
      a4: v3 >> 31,
      a5: 0);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100147A0
// Name: protected: virtual unsigned int CFileSystem_Steam::FS_fread(void __near *,unsigned int,unsigned int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileSystem_Steam::FS_fread(
        CFileSystem_Steam *this,
        void *dest,
        unsigned int destSize,
        unsigned int size,
        _iobuf *fp)
{
  unsigned int v5; // edi
  TSteamError steamError; // [esp+8h] [ebp-10Ch] BYREF

  v5 = steam->ReadFile(this: steam, a2: dest, a3: 1u, a4: size, a5: (unsigned int)fp, a6: &steamError);
  CheckError((unsigned int)fp, &steamError);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100147F0
// Name: protected: virtual unsigned int CFileSystem_Steam::FS_fwrite(void const __near *,unsigned int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileSystem_Steam::FS_fwrite(
        CFileSystem_Steam *this,
        const void *src,
        unsigned int size,
        _iobuf *fp)
{
  unsigned int v4; // edi
  TSteamError steamError; // [esp+8h] [ebp-10Ch] BYREF

  v4 = steam->WriteFile(this: steam, a2: src, a3: 1u, a4: size, a5: (unsigned int)fp, a6: &steamError);
  CheckError((unsigned int)fp, &steamError);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10014840
// Name: protected: virtual unsigned int CFileSystem_Steam::FS_vfprintf(struct _iobuf __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__userpurge CFileSystem_Steam::FS_vfprintf@<eax>(
        CFileSystem_Steam *this@<ecx>,
        int a2@<edi>,
        _iobuf *fp,
        const char *fmt,
        char *list)
{
  _iobuf *result; // eax
  _iobuf *v6; // esi
  unsigned int v7; // edi
  char *v8; // esi
  int v9; // ebx

  if ( fp == nullptr || fmt == nullptr )
    return nullptr;
  result = fopen(file: "nul:", mode: "w");
  v6 = result;
  if ( result == nullptr )
    return result;
  v7 = vfprintf(str: result, format: fmt, ap: list);
  fclose(stream: v6);
  if ( v7 == 0 )
    return nullptr;
  v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 1);
  if ( v8 == nullptr )
    return nullptr;
  v9 = _vsnprintf(string: v8, count: v7, format: fmt, ap: list);
  if ( v9 != v7 )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
    return nullptr;
  }
  v8[v7] = 0;
  if ( v9 == ((int (__thiscall *)(CFileSystem_Steam *, char *, int, _iobuf *, int))this->FS_fwrite)(
               a1: this,
               a2: v8,
               a3: v9,
               a4: fp,
               a5: a2) )
  {
    ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
    return (_iobuf *)v9;
  }
  else
  {
    ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014940
// Name: protected: virtual int CFileSystem_Steam::FS_ferror(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Steam::FS_ferror(CFileSystem_Steam *this, _iobuf *fp)
{
  if ( fp == nullptr )
    return g_tLastErrorNoFile.eSteamError != eSteamErrorNone;
  if ( fp == (_iobuf *)g_pLastErrorFile )
    return g_tLastError.eSteamError != eSteamErrorNone;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10014980
// Name: protected: virtual int CFileSystem_Steam::FS_fflush(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_fflush(CFileSystem_Steam *this, _iobuf *fp)
{
  int v2; // edi
  TSteamError steamError; // [esp+8h] [ebp-10Ch] BYREF

  v2 = steam->FlushFile(this: steam, a2: (unsigned int)fp, a3: &steamError);
  CheckError((unsigned int)fp, &steamError);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100149C0
// Name: protected: virtual char __near * CFileSystem_Steam::FS_fgets(char __near *,int,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFileSystem_Steam::FS_fgets(CFileSystem_Steam *this, char *dest, int destSize, _iobuf *fp)
{
  char *v5; // esi
  unsigned __int8 v6; // al
  int v7; // edi
  bool v8; // zf
  unsigned __int8 c; // [esp+Fh] [ebp-1h] BYREF

  v5 = dest;
  v6 = 0;
  v7 = 0;
  c = 0;
  *dest = 0;
  if ( destSize - 1 > 0 )
  {
    while ( v6 != 10 )
    {
      v8 = this->FS_fread(this, a2: &c, a3: 1u, a4: 1u, a5: fp) == 1;
      v6 = c;
      if ( v8 )
      {
        *v5++ = c;
        *v5 = 0;
        ++v7;
      }
      else
      {
        if ( g_tLastError.eSteamError != eSteamErrorEOF || v7 == 0 )
          return nullptr;
        v7 = destSize;
      }
      if ( v7 >= destSize - 1 )
        return v5;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10014A40
// Name: protected: virtual int CFileSystem_Steam::FS_stat(char const __near *,struct _stat64i32 __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CFileSystem_Steam::FS_stat@<eax>(
        CFileSystem_Steam *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *path,
        _stat64i32 *buf)
{
  int v7; // ebx
  __int16 v8; // cx
  __int64 v9; // rax
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  TSteamError steamError; // [esp+0h] [ebp-254h] BYREF
  TSteamElemInfo Info; // [esp+10Ch] [ebp-148h] BYREF
  _stat64i32 testBuf; // [esp+224h] [ebp-30h] BYREF

  if ( steam == nullptr )
    return -1;
  memset(dst: (unsigned __int8 *)buf, value: 0, count: sizeof(_stat64i32));
  v7 = ((int (__thiscall *)(ISteamInterface *, const char *, TSteamElemInfo *, TSteamError *, int, int, int))steam->Stat)(
         a1: steam,
         a2: path,
         a3: &Info,
         a4: &steamError,
         a5: a3,
         a6: a4,
         a7: a2);
  if ( v7 == 0 )
  {
    if ( Info.bIsDir != 0 )
    {
      v8 = 0x4000;
      buf->st_size = 0;
    }
    else
    {
      if ( _stat64i32(name: path, buf: &testBuf) == 0 && SLOBYTE(testBuf.st_mode) < 0 )
        buf->st_mode |= 0x80u;
      v8 = 0x8000;
      buf->st_size = Info.uSizeOrCount;
    }
    LODWORD(v9) = Info.lLastAccessTime;
    buf->st_mode |= v8;
    v9 = (int)v9;
    LODWORD(buf->st_atime) = v9;
    LODWORD(v9) = Info.lLastModificationTime;
    HIDWORD(buf->st_atime) = HIDWORD(v9);
    v9 = (int)v9;
    LODWORD(buf->st_mtime) = v9;
    LODWORD(v9) = Info.lCreationTime;
    HIDWORD(buf->st_mtime) = HIDWORD(v9);
    buf->st_ctime = (int)v9;
  }
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
    return v7;
  }
  else
  {
    if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
      g_tLastErrorNoFile = steamError;
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014B70
// Name: protected: virtual int CFileSystem_Steam::FS_chmod(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_chmod(CFileSystem_Steam *this, const char *path, int pmode)
{
  return _chmod(path, mode: pmode);
}

//------------------------------------------------------------------------------
// Address: 0x10014B90
// Name: protected: virtual void __near * CFileSystem_Steam::FS_FindFirstFile(char const __near *,struct _WIN32_FIND_DATAA __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::FS_FindFirstFile(
        CFileSystem_Steam *this,
        const char *findname,
        _WIN32_FIND_DATAA *dat)
{
  int v3; // ebx
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  int result; // eax
  TSteamError steamError; // [esp+8h] [ebp-224h] BYREF
  TSteamElemInfo steamFindInfo; // [esp+114h] [ebp-118h] BYREF

  v3 = steam->FindFirst(this: steam, a2: findname, a3: eSteamFindAll, a4: &steamFindInfo, a5: &steamError);
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
  }
  else if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
  {
    g_tLastErrorNoFile = steamError;
  }
  if ( v3 == 0 )
    return -1;
  strcpy(dat->cFileName, steamFindInfo.cszName);
  if ( steamFindInfo.bIsDir != 0 )
    dat->dwFileAttributes |= 0x10u;
  else
    dat->dwFileAttributes &= ~0x10u;
  result = v3;
  if ( steamFindInfo.bIsLocal != 0 )
    dat->dwFileAttributes &= ~0x1000u;
  else
    dat->dwFileAttributes |= 0x1000u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014C90
// Name: protected: virtual bool CFileSystem_Steam::FS_FindNextFile(void __near *,struct _WIN32_FIND_DATAA __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFileSystem_Steam::FS_FindNextFile(CFileSystem_Steam *this, void *handle, _WIN32_FIND_DATAA *dat)
{
  bool v3; // bl
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  bool result; // al
  TSteamError steamError; // [esp+8h] [ebp-224h] BYREF
  TSteamElemInfo steamFindInfo; // [esp+114h] [ebp-118h] BYREF

  v3 = steam->FindNext(this: steam, a2: (unsigned int)handle, a3: &steamFindInfo, a4: &steamError) == 0;
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
  }
  else if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
  {
    g_tLastErrorNoFile = steamError;
  }
  if ( !v3 )
    return false;
  strcpy(dat->cFileName, steamFindInfo.cszName);
  result = v3;
  if ( steamFindInfo.bIsDir != 0 )
    dat->dwFileAttributes |= 0x10u;
  else
    dat->dwFileAttributes &= ~0x10u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014D70
// Name: protected: virtual bool CFileSystem_Steam::FS_FindClose(void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Steam::FS_FindClose(CFileSystem_Steam *this, void *handle)
{
  BOOL v2; // ebx
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  v2 = steam->FindClose(this: steam, a2: (unsigned int)handle, a3: &steamError) == 0;
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
    return v2;
  }
  else
  {
    if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
      g_tLastErrorNoFile = steamError;
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014E20
// Name: public: virtual bool CFileSystem_Steam::IsFileImmediatelyAvailable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFileSystem_Steam::IsFileImmediatelyAvailable(CFileSystem_Steam *this, const char *pFileName)
{
  TSteamError steamError; // [esp+0h] [ebp-10Ch] BYREF

  return steam->IsFileImmediatelyAvailable(this: steam, a2: pFileName, a3: &steamError) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014E50
// Name: public: virtual void CFileSystem_Steam::GetLocalCopy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileSystem_Steam::GetLocalCopy(CFileSystem_Steam *this, const char *pFileName)
{
  int (__thiscall *FS_stat)(CBaseFileSystem *, const char *, _stat64i32 *); // eax
  unsigned __int8 *v3; // edi
  HMODULE ModuleHandleA; // eax
  int v5; // eax
  int v6; // ebx
  char *v7; // eax
  unsigned int v8; // esi
  TSteamError steamError; // [esp+4h] [ebp-24Ch] BYREF
  char srchPath[260]; // [esp+110h] [ebp-140h] BYREF
  _stat64i32 StatBuf; // [esp+214h] [ebp-3Ch] BYREF
  CFileSystem_Steam *v12; // [esp+244h] [ebp-Ch]
  char *pEnd; // [esp+248h] [ebp-8h]
  bool bSearch; // [esp+24Fh] [ebp-1h]

  FS_stat = this->FS_stat;
  v12 = this;
  if ( ((int (__stdcall *)(const char *, _stat64i32 *))FS_stat)(a1: pFileName, a2: &StatBuf) == -1 )
  {
    v3 = (unsigned __int8 *)getenv(option: "PATH");
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: srchPath, nSize: 0x104u) != 0 )
    {
      strrchr(string: (unsigned __int8 *)srchPath, chr: 0x5Cu);
      v6 = 0;
      if ( v5 != 0 )
        v6 = v5 - (_DWORD)srchPath;
      bSearch = true;
      if ( v3 != nullptr )
      {
        while ( bSearch )
        {
          strstr(str1: v3, str2: ";");
          pEnd = v7;
          if ( v7 == nullptr )
            bSearch = false;
          if ( v7 - (char *)v3 > v6 )
          {
            v8 = -1 - v6 + v7 - (char *)v3;
            memcpy(dst: (unsigned __int8 *)srchPath, src: &v3[v6 + 1], count: v8);
            strcpy(&srchPath[v8], pFileName);
            if ( v12->FS_stat(this: v12, a2: srchPath, a3: &StatBuf) == 0 )
            {
              steam->GetLocalFileCopy(this: steam, a2: srchPath, a3: &steamError);
              return;
            }
            v7 = pEnd;
          }
          v3 = (unsigned __int8 *)(v7 + 1);
          if ( v7 == (char *)-1 )
            return;
        }
      }
    }
    else
    {
      MessageBoxA(
        hWnd: nullptr,
        lpText: "Failed calling GetModuleFileName",
        lpCaption: "Half-Life Steam Filesystem Error",
        uType: 0);
    }
  }
  else
  {
    steam->GetLocalFileCopy(this: steam, a2: pFileName, a3: &steamError);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014FE0
// Name: public: virtual int CFileSystem_Steam::HintResourceNeed(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::HintResourceNeed(CFileSystem_Steam *this, const char *hintlist, int forgetEverything)
{
  int v3; // ebx
  HWND ForegroundWindow; // eax
  HANDLE CurrentProcess; // eax
  TSteamError steamError; // [esp+4h] [ebp-10Ch] BYREF

  v3 = steam->HintResourceNeed(this: steam, a2: hintlist, a3: forgetEverything, a4: &steamError);
  if ( steamError.eSteamError == eSteamErrorContentServerConnect )
  {
    ForegroundWindow = GetForegroundWindow();
    if ( ForegroundWindow != nullptr )
      DestroyWindow(hWnd: ForegroundWindow);
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Could not acquire necessary game files because the connection to Steam servers was lost.",
      lpCaption: "Source - Fatal Error",
      uType: 0x30u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 0);
    return v3;
  }
  else
  {
    if ( steamError.eSteamError != eSteamErrorNone || g_tLastErrorNoFile.eSteamError != eSteamErrorNone )
      g_tLastErrorNoFile = steamError;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015080
// Name: public: virtual enum InitReturnVal_t CFileSystem_Steam::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileSystem_Steam::Init(CFileSystem_Steam *this)
{
  this->m_bSteamInitialized = true;
  this->m_bSelfMounted = false;
  CFileSystem_Steam::LoadAndStartSteam(this);
  return CBaseFileSystem::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x100150A0
// Name: public: virtual class CSysModule __near * CFileSystem_Steam::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CFileSystem_Steam::LoadModule(
        CFileSystem_Steam *this,
        const char *pFileName,
        const char *pPathID,
        bool bValidatedDllOnly)
{
  const char *v5; // esi
  int m_Size; // esi
  int v7; // eax
  char *v8; // eax
  int m_nReaders; // ecx
  const char *v10; // eax
  bool v11; // bl
  struct CSysModule *Module; // esi
  unsigned int v13; // eax
  _BYTE v15[280]; // [esp+Ch] [ebp-448h] BYREF
  _BYTE v16[268]; // [esp+124h] [ebp-330h] BYREF
  char newPathName[260]; // [esp+230h] [ebp-224h] BYREF
  char szNewPath[260]; // [esp+334h] [ebp-120h] BYREF
  int c; // [esp+438h] [ebp-1Ch]
  int v20; // [esp+43Ch] [ebp-18h]
  int i; // [esp+440h] [ebp-14h]
  char szExtension[8]; // [esp+444h] [ebp-10h] BYREF
  CUtlSymbol lookup; // [esp+44Ch] [ebp-8h] BYREF
  CUtlSymbol v24; // [esp+452h] [ebp-2h]

  CBaseFileSystem::ParsePathID(this, pFilename: &pFileName, &pPathID, tempPathID: szNewPath);
  strcpy(szExtension, ".dll");
  V_strncpy(pDest: szNewPath, pSrc: pFileName, maxLen: 260);
  if ( V_stristr(pStr: szNewPath, pSearch: szExtension) == nullptr )
    V_strncat(pDest: szNewPath, pSrc: szExtension, destBufferSize: 0x104u, max_chars_to_copy: -1);
  CBaseFileSystem::LogFileAccess(this, pFullFileName: szNewPath);
  v5 = pPathID;
  if ( pPathID == nullptr )
  {
    v5 = "EXECUTABLE_PATH";
    pPathID = "EXECUTABLE_PATH";
  }
  if ( (g_PathIDTable.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)&g_PathIDTable.m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &g_PathIDTable.m_lock);
  }
  else
  {
    g_PathIDTable.m_lock.m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::AddString(this: &g_PathIDTable, result: &lookup, pString: v5);
  g_PathIDTable.m_lock.m_writerId = 0;
  g_PathIDTable.m_lock.m_lockInfo.m_i32 = 0;
  m_Size = this->m_SearchPaths.m_Size;
  c = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    v7 = 0;
    v20 = 0;
    do
    {
      v8 = (char *)this->m_SearchPaths.m_Memory.m_pMemory + v7;
      if ( *((_DWORD *)v8 + 4) == 0 && *(_WORD *)(*((_DWORD *)v8 + 1) + 2) == lookup.m_Id )
      {
        v24.m_Id = *((_WORD *)v8 + 5);
        if ( (g_PathIDTable.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
          || (m_nReaders = g_PathIDTable.m_lock.m_lockInfo.m_nReaders,
              _InterlockedCompareExchange(
                (volatile signed __int32 *)&g_PathIDTable.m_lock,
                g_PathIDTable.m_lock.m_lockInfo.m_nReaders + 1,
                g_PathIDTable.m_lock.m_lockInfo.m_nReaders) != m_nReaders) )
        {
          CThreadSpinRWLock::SpinLockForRead(this: &g_PathIDTable.m_lock);
        }
        v10 = CUtlSymbolTable::String(this: &g_PathIDTable, id: v24);
        _InterlockedExchangeAdd((volatile signed __int32 *)&g_PathIDTable.m_lock, 0xFFFFFFFF);
        V_snprintf(pDest: newPathName, maxLen: 260, pFormat: "%s%s", v10, szNewPath);
        if ( !bValidatedDllOnly || CFileSystem_Steam::IsFileInSteamCache2(this, file: newPathName) != 0 )
        {
          v11 = !this->m_bSDKToolMode;
          if ( !IsDebuggerPresent() && v11 )
            this->GetLocalCopy(this, a2: newPathName);
          Module = Sys_LoadModule(pModuleName: newPathName);
          if ( Module != nullptr )
          {
            if ( !bValidatedDllOnly || CFileSystem_Steam::IsFileInSteamCache2(this, file: newPathName) != 0 )
              return Module;
            return nullptr;
          }
          m_Size = c;
        }
      }
      v7 = v20 + 24;
      ++i;
      v20 += 24;
    }
    while ( i < m_Size );
  }
  if ( bValidatedDllOnly )
  {
    if ( this->m_bContentLoaded && !this->m_bSDKToolMode )
    {
      v13 = steam->FindFirst(
              this: steam,
              a2: szNewPath,
              a3: eSteamFindRemoteOnly,
              a4: (TSteamElemInfo *)v15,
              a5: (TSteamError *)v16);
      if ( v13 == 0 )
        return nullptr;
      steam->FindClose(this: steam, a2: v13, a3: (TSteamError *)v16);
    }
    return Sys_LoadModule(pModuleName: szNewPath);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10015360
// Name: void MountDependencies(int,class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MountDependencies(unsigned int iAppId, CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *depList)
{
  unsigned int v2; // edi
  unsigned int v3; // ebx
  int m_pMemory; // edi
  int v5; // eax
  unsigned int *v6; // ecx
  int m_nAllocationCount; // eax
  unsigned int *v8; // ecx
  int v9; // eax
  unsigned int *v10; // eax
  char v11; // [esp+8h] [ebp-2260h] BYREF
  char v12; // [esp+808h] [ebp-1A60h] BYREF
  char v13; // [esp+1008h] [ebp-1260h] BYREF
  char v14; // [esp+1808h] [ebp-A60h] BYREF
  unsigned int v15[66]; // [esp+2008h] [ebp-260h] BYREF
  _DWORD v16[3]; // [esp+2110h] [ebp-158h] BYREF
  char v17[256]; // [esp+211Ch] [ebp-14Ch] BYREF
  _DWORD v18[16]; // [esp+221Ch] [ebp-4Ch] BYREF
  int v19; // [esp+225Ch] [ebp-Ch]
  int v20; // [esp+2260h] [ebp-8h] BYREF
  int v21; // [esp+2264h] [ebp-4h] BYREF

  v18[0] = &v11;
  v2 = iAppId;
  v18[1] = 2048;
  v18[2] = &v12;
  v18[3] = 2048;
  v18[5] = 2048;
  v18[7] = 2048;
  v18[6] = &v14;
  v18[4] = &v13;
  steam->EnumerateApp(this: steam, a2: iAppId, a3: (TSteamApp *)v18, a4: (TSteamError *)v16);
  if ( v16[0] != 0 )
    _Error(a1: "EnumerateApp( %d ) failed: %s", iAppId, v17);
  v3 = 0;
  if ( v19 > 0 )
  {
    while ( 1 )
    {
      steam->EnumerateAppDependency(
        this: steam,
        a2: v2,
        a3: v3,
        a4: (TSteamAppDependencyInfo *)v15,
        a5: (TSteamError *)v16);
      if ( v16[0] != 0 )
        _Error(a1: "EnumerateAppDependency( %d, %d ) failed: %s", v2, v3, v17);
      m_pMemory = (int)depList[1].m_pMemory;
      v5 = 0;
      if ( m_pMemory <= 0 )
        goto LABEL_14;
      v6 = (unsigned int *)depList->m_pMemory;
      while ( *v6 != v15[0] )
      {
        ++v5;
        ++v6;
        if ( v5 >= m_pMemory )
          goto LABEL_14;
      }
      if ( v5 == -1 )
      {
LABEL_14:
        m_nAllocationCount = depList->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CPackedStore *,int>::Grow(this: depList, num: m_pMemory - m_nAllocationCount + 1);
        ++depList[1].m_pMemory;
        v8 = (unsigned int *)depList->m_pMemory;
        v9 = (int)depList[1].m_pMemory - m_pMemory - 1;
        depList[1].m_nAllocationCount = (int)depList->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (unsigned int *)&depList->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = v15[0];
        v21 = 0;
        v20 = 0;
        steam->IsAppSubscribed(this: steam, a2: v15[0], a3: &v21, a4: &v20, a5: (TSteamError *)v16);
        if ( v21 != 0 )
        {
          steam->MountFilesystem(this: steam, a2: v15[0], a3: setName, a4: (TSteamError *)v16);
          if ( v16[0] != 0 && v16[0] != 104 )
            _Error(a1: "MountFilesystem( %d ) failed: %s", v15[0], v17);
        }
      }
      if ( (int)++v3 >= v19 )
        break;
      v2 = iAppId;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015540
// Name: public: virtual enum FilesystemMountRetval_t CFileSystem_Steam::MountSteamContent(int)
// Source: json
//------------------------------------------------------------------------------
FilesystemMountRetval_t __thiscall CFileSystem_Steam::MountSteamContent(CFileSystem_Steam *this, int nExtraAppId)
{
  ISteamInterface *v3; // ecx
  char *v4; // ebx
  HWND ForegroundWindow; // eax
  unsigned int v7; // [esp-8h] [ebp-1B8h]
  TSteamError steamError; // [esp+Ch] [ebp-1A4h] BYREF
  char szMainAppId[128]; // [esp+118h] [ebp-98h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > depList; // [esp+198h] [ebp-18h] BYREF
  int loggedIn; // [esp+1ACh] [ebp-4h] BYREF

  this->m_bContentLoaded = true;
  v3 = steam;
  v4 = nullptr;
  if ( steam == nullptr )
  {
    CFileSystem_Steam::LoadAndStartSteam(this);
    v3 = steam;
  }
  loggedIn = 0;
  if ( v3->IsLoggedIn(this: v3, a2: &loggedIn, a3: &steamError) != 0 && loggedIn == 0 )
  {
    this->m_bSelfMounted = true;
    return FILESYSTEM_MOUNT_OK;
  }
  if ( nExtraAppId == -1 )
  {
    if ( steam->MountAppFilesystem(this: steam, a2: &steamError) == 0 )
    {
      _Error(a1: "MountAppFilesystem() failed: %s\n", steamError.szDesc);
      ForegroundWindow = GetForegroundWindow();
      DestroyWindow(hWnd: ForegroundWindow);
      MessageBoxA(hWnd: nullptr, lpText: steamError.szDesc, lpCaption: "Half-Life FileSystem_Steam Error", uType: 0);
      _exit(code: -1);
    }
    return FILESYSTEM_MOUNT_OK;
  }
  this->m_bSDKToolMode = true;
  memset(&depList, 0, sizeof(depList));
  if ( nExtraAppId >= -1 )
  {
    if ( GetEnvironmentVariableA(lpName: "steamappid", lpBuffer: szMainAppId, nSize: 0x80u) != 0 )
      v4 = szMainAppId;
    else
      _Error(a1: "Extra App ID set to %d, but no SteamAppId.", nExtraAppId);
    MountDependencies(iAppId: nExtraAppId, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depList);
    v7 = atoi(nptr: v4);
    MountDependencies(iAppId: v7, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depList);
  }
  else
  {
    MountDependencies(iAppId: -nExtraAppId, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&depList);
  }
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&depList);
  return FILESYSTEM_MOUNT_OK;
}

//------------------------------------------------------------------------------
// Address: 0x100140A0
// Name: __CreateCFileSystem_SteamIFileSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFileSystem_Steam *__cdecl _CreateCFileSystem_SteamIFileSystem_interface()
{
  return &g_FileSystem_Steam;
}

//------------------------------------------------------------------------------
// Address: 0x100140B0
// Name: __CreateCFileSystem_SteamIBaseFileSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IBaseFileSystem *__cdecl _CreateCFileSystem_SteamIBaseFileSystem_interface()
{
  return &g_FileSystem_Steam.IBaseFileSystem;
}

} // namespace FileSystem_Steam
