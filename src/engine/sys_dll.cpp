// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sys_dll.cpp
// Functions: 68
// ============================================================

#include "engine\sys_dll.h"

//------------------------------------------------------------------------------
// Address: 0x101E51E0
// Name: int Sys_CompareFileTime(long,long)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_CompareFileTime(int ft1, int ft2)
{
  if ( ft1 >= ft2 )
    return ft1 > ft2;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5200
// Name: void Sys_mkdir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_mkdir(const char *path)
{
  int v1; // eax
  char *v2; // ecx
  const char *v3; // esi
  char testpath[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: testpath, pSrc: path, maxLen: 260);
  v1 = _V_strlen(str: testpath);
  if ( v1 > 0 )
  {
    v2 = &testpath[v1 - 1];
    if ( testpath[v1 - 1] == 92 || *v2 == 47 )
      *v2 = 0;
  }
  v3 = "MOD";
  if ( (testpath[0] == 92 || testpath[0] == 47) && (testpath[1] == 92 || testpath[1] == 47) )
    v3 = nullptr;
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: testpath, a3: v3)
    && !g_pFileSystem->IsDirectory(this: g_pFileSystem, a2: testpath, a3: v3) )
  {
    g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: testpath, a3: v3);
  }
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: path, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101E52D0
// Name: char const __near * Sys_FindNext(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_FindNext(char *basename, int namelength)
{
  const char *v2; // esi

  v2 = g_pFileSystem->FindNext(this: g_pFileSystem, a2: g_hfind);
  if ( basename != nullptr && v2 != nullptr )
    V_FileBase(in: v2, out: basename, maxlen: namelength);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101E5310
// Name: void Sys_FindClose(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_FindClose()
{
  if ( g_hfind != -1 )
  {
    g_pFileSystem->FindClose(this: g_pFileSystem, a2: g_hfind);
    g_hfind = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5340
// Name: void Sys_Printf(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_Printf(char *fmt, ...)
{
  wchar_t WideCharStr[2048]; // [esp+0h] [ebp-1400h] BYREF
  char pDest[1024]; // [esp+1000h] [ebp-400h] BYREF
  va_list params; // [esp+140Ch] [ebp+Ch] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 1024, pFormat: fmt, params);
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    MultiByteToWideChar(
      CodePage: 0xFDE9u,
      dwFlags: 0,
      lpMultiByteStr: pDest,
      cbMultiByte: -1,
      lpWideCharStr: WideCharStr,
      cchWideChar: 2048);
    WideCharStr[2047] = 0;
    OutputDebugStringW(lpOutputString: WideCharStr);
    Sleep(dwMilliseconds: 0);
  }
  if ( s_bIsDedicated )
    printf(format: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x101E53E0
// Name: bool Sys_MessageBox(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Sys_MessageBox(const char *title, const char *info, bool bShowOkAndCancel)
{
  return MessageBoxA(hWnd: nullptr, lpText: title, lpCaption: info, uType: bShowOkAndCancel | 0x30) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5410
// Name: void Sys_Error_Internal(bool,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Error_Internal(bool bMinidump, const char *error, char *argsList)
{
  _iobuf *v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  char text[1024]; // [esp+Ch] [ebp-418h] BYREF
  int v10; // [esp+420h] [ebp-4h]

  V_vsnprintf(pDest: text, maxLen: 1024, pFormat: error, params: argsList);
  if ( bReentry )
  {
    v3 = __iob_func();
    fprintf(str: v3 + 2, format: "%s\n", text);
  }
  else
  {
    bReentry = true;
    if ( s_bIsDedicated )
      printf(format: "%s\n", text);
    else
      Sys_Printf(fmt: "%s\n", text);
    g_bInErrorExit = true;
    if ( videomode != nullptr )
      videomode->Shutdown(this: videomode);
    v4 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-makereslists") == 0 )
    {
      v6 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-nomessagebox") == 0 )
        MessageBoxA(hWnd: nullptr, lpText: text, lpCaption: "Engine Error", uType: 0x40000u);
    }
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v5) != 0 )
      __debugbreak();
    BuildMinidumpComment(pchSysErrorText: text);
    g_bUpdateMinidumpComment = false;
    if ( bMinidump && (unsigned __int8)_Plat_IsInDebugSession(a1: v7) == 0 )
    {
      v8 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-nominidumps") == 0 )
      {
        v10 = 0;
        RaiseException(dwExceptionCode: 0, dwExceptionFlags: 1u, nNumberOfArguments: 0, lpArguments: nullptr);
        v10 = -1;
      }
    }
    host_initialized = false;
    _Plat_ExitProcess(a1: 100);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E55D0
// Name: void Sys_Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_Error(const char *error, ...)
{
  va_list argsList; // [esp+Ch] [ebp+Ch] BYREF

  va_start(argsList, error);
  Sys_Error_Internal(bMinidump: true, error, argsList);
}

//------------------------------------------------------------------------------
// Address: 0x101E55F0
// Name: void Sys_Exit(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_Exit(const char *error, ...)
{
  va_list argsList; // [esp+Ch] [ebp+Ch] BYREF

  va_start(argsList, error);
  Sys_Error_Internal(bMinidump: false, error, argsList);
}

//------------------------------------------------------------------------------
// Address: 0x101E5610
// Name: void Sys_Sleep(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Sleep(int msec)
{
  _ThreadSleep(a1: msec);
}

//------------------------------------------------------------------------------
// Address: 0x101E5620
// Name: DllMain(x,x,x)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  vgui::PropertyPage *v3; // ecx

  CColorBalanceUIPanel::Init(this: v3);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101E5630
// Name: void Sys_InitMemory(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Sys_InitMemory()
{
  int v0; // eax
  unsigned int ullTotalPhys; // eax
  ConVar *m_pParent; // esi
  ConVar *v3; // edi
  unsigned int v4; // eax
  int v5; // ecx
  int m_nValue; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  _OSVERSIONINFOEXA osvi; // [esp+0h] [ebp-DCh] BYREF
  _MEMORYSTATUSEX lpBuffer; // [esp+9Ch] [ebp-40h] OVERLAPPED BYREF

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-minmemory") != 0 )
  {
    if ( mem_min_heapsize.m_pParent != nullptr )
      host_parms.memsize = mem_min_heapsize.m_pParent->m_Value.m_nValue << 20;
    else
      host_parms.memsize = 0;
    return;
  }
  host_parms.memsize = 0;
  memset(dst: (unsigned __int8 *)&osvi, value: 0, count: sizeof(osvi));
  osvi.dwOSVersionInfoSize = 156;
  if ( GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi)
    && osvi.dwPlatformId >= 2
    && osvi.dwMajorVersion >= 5
    && (memset(dst: (unsigned __int8 *)&lpBuffer, value: 0, count: sizeof(lpBuffer)),
        lpBuffer.dwLength = 64,
        GlobalMemoryStatusEx(&lpBuffer)) )
  {
    if ( HIDWORD(lpBuffer.ullTotalPhys) != 0 )
    {
      m_pParent = mem_min_heapsize.m_pParent;
      v3 = mem_max_heapsize.m_pParent;
      ullTotalPhys = -1;
LABEL_12:
      v4 = ullTotalPhys >> 2;
LABEL_13:
      host_parms.memsize = v4;
      goto LABEL_14;
    }
    ullTotalPhys = lpBuffer.ullTotalPhys;
    host_parms.memsize = lpBuffer.ullTotalPhys;
  }
  else
  {
    ullTotalPhys = host_parms.memsize;
  }
  if ( ullTotalPhys != 0 )
  {
    v3 = mem_max_heapsize.m_pParent;
    goto LABEL_33;
  }
  LODWORD(lpBuffer.ullAvailPageFile) = 32;
  GlobalMemoryStatus(lpBuffer: (LPMEMORYSTATUS)&lpBuffer.ullAvailPageFile);
  ullTotalPhys = lpBuffer.ullTotalVirtual;
  v3 = mem_max_heapsize.m_pParent;
  if ( LODWORD(lpBuffer.ullTotalVirtual) != 0 )
  {
    host_parms.memsize = lpBuffer.ullTotalVirtual;
LABEL_33:
    m_pParent = mem_min_heapsize.m_pParent;
    goto LABEL_34;
  }
  if ( mem_max_heapsize.m_pParent != nullptr )
    m_nValue = mem_max_heapsize.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  m_pParent = mem_min_heapsize.m_pParent;
  if ( mem_min_heapsize.m_pParent != nullptr )
    v7 = mem_min_heapsize.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  if ( m_nValue << 20 <= (unsigned int)(v7 << 20) )
  {
    if ( mem_min_heapsize.m_pParent != nullptr )
    {
      ullTotalPhys = mem_min_heapsize.m_pParent->m_Value.m_nValue << 20;
      host_parms.memsize = ullTotalPhys;
      goto LABEL_34;
    }
  }
  else if ( mem_max_heapsize.m_pParent != nullptr )
  {
    ullTotalPhys = mem_max_heapsize.m_pParent->m_Value.m_nValue << 20;
    host_parms.memsize = ullTotalPhys;
    goto LABEL_34;
  }
  ullTotalPhys = 0;
  host_parms.memsize = 0;
LABEL_34:
  if ( ullTotalPhys < 0x8000000 )
  {
    Sys_Error(error: "Available memory less than 128MB!!! %i\n", ullTotalPhys);
    ullTotalPhys = host_parms.memsize;
    m_pParent = mem_min_heapsize.m_pParent;
    v3 = mem_max_heapsize.m_pParent;
  }
  if ( ullTotalPhys > 0x20000000 )
    goto LABEL_12;
  v4 = ullTotalPhys >> 2;
  host_parms.memsize = v4;
  if ( mem_max_heapsize_dedicated.m_pParent != nullptr )
    v8 = mem_max_heapsize_dedicated.m_pParent->m_Value.m_nValue;
  else
    v8 = 0;
  if ( v4 > v8 << 20 )
  {
    if ( mem_max_heapsize_dedicated.m_pParent != nullptr )
      v4 = mem_max_heapsize_dedicated.m_pParent->m_Value.m_nValue << 20;
    else
      v4 = 0;
    goto LABEL_13;
  }
LABEL_14:
  if ( m_pParent != nullptr )
    v5 = m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  if ( v4 < v5 << 20 )
  {
    if ( m_pParent != nullptr )
      v9 = m_pParent->m_Value.m_nValue;
    else
      v9 = 0;
    v4 = v9 << 20;
    host_parms.memsize = v4;
  }
  if ( v3 != nullptr )
    v10 = v3->m_Value.m_nValue;
  else
    v10 = 0;
  if ( m_pParent != nullptr )
    v11 = m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  if ( v10 << 20 <= (unsigned int)(v11 << 20) )
  {
    if ( m_pParent != nullptr )
    {
      v12 = m_pParent->m_Value.m_nValue;
      goto LABEL_62;
    }
LABEL_61:
    v12 = 0;
    goto LABEL_62;
  }
  if ( v3 == nullptr )
    goto LABEL_61;
  v12 = v3->m_Value.m_nValue;
LABEL_62:
  if ( v4 <= v12 << 20 )
    return;
  if ( v3 != nullptr )
    v13 = v3->m_Value.m_nValue;
  else
    v13 = 0;
  if ( m_pParent != nullptr )
    v14 = m_pParent->m_Value.m_nValue;
  else
    v14 = 0;
  if ( v13 << 20 <= (unsigned int)(v14 << 20) )
  {
    if ( m_pParent != nullptr )
    {
      host_parms.memsize = m_pParent->m_Value.m_nValue << 20;
      return;
    }
  }
  else if ( v3 != nullptr )
  {
    host_parms.memsize = v3->m_Value.m_nValue << 20;
    return;
  }
  host_parms.memsize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E58F0
// Name: void DeveloperChangeCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeveloperChangeCallback(IConVar *pConVar)
{
  int m_nValue; // esi
  ConVarRef var; // [esp+8h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  m_nValue = var.m_pConVarState->m_Value.m_nValue;
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "Developer", a2: m_nValue >= 1 ? 0 : 3);
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "DeveloperVerbose", a2: m_nValue >= 2 ? 0 : 3);
}

//------------------------------------------------------------------------------
// Address: 0x101E5950
// Name: void __near * GameFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GameFactory(const char *pName, int *pReturnCode)
{
  void *result; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IEngineVGuiInternal *v4; // eax
  IEngineVGuiInternal *v5; // eax
  int (*v6)(void); // eax

  result = g_AppSystemFactory(a1: pName, a2: pReturnCode);
  if ( result == nullptr )
  {
    result = g_pfnMatchmakingFactory(a1: pName, a2: pReturnCode);
    if ( result == nullptr )
    {
      if ( ClientDLL_GetFactory() == nullptr
        || (Factory = ClientDLL_GetFactory(), (result = Factory(a1: pName, a2: pReturnCode)) == nullptr) )
      {
        v4 = EngineVGui();
        if ( v4->GetGameUIFactory(this: v4) == nullptr )
          return nullptr;
        v5 = EngineVGui();
        v6 = (int (*)(void))((int (__thiscall *)(IEngineVGuiInternal *, const char *, int *))v5->GetGameUIFactory)(
                              a1: v5,
                              a2: pName,
                              a3: pReturnCode);
        result = (void *)v6();
        if ( result == nullptr )
          return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E59D0
// Name: int Sys_InitGame(void __near * (*)(char const __near *,int __near *),char const __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __usercall Sys_InitGame@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        void *(__cdecl *appSystemFactory)(const char *, int *),
        const char *pBaseDir,
        HWND__ **pwnd,
        int bIsDedicated)
{
  vgui::PropertyPage *v6; // ecx
  int v7; // eax
  int v8; // eax

  InitMathlib();
  CColorBalanceUIPanel::Init(this: v6);
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "Console", a2: 0);
  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &s_EngineLoggingListener);
  _LoggingSystem_RegisterLoggingListener(a1: &s_FileLoggingListener);
  ConVar::InstallChangeCallback(
    this: &developer,
    callback: (void (__cdecl *)(IConVar *, const char *, float))DeveloperChangeCallback,
    bInvoke: true);
  host_initialized = false;
  pmainwindow = pwnd;
  s_bIsDedicated = bIsDedicated != 0;
  memset(dst: (unsigned __int8 *)&gmodinfo, value: 0, count: sizeof(gmodinfo));
  V_strncpy(pDest: s_pBaseDir, pSrc: pBaseDir, maxLen: 256);
  _V_strlower(start: s_pBaseDir);
  V_FixSlashes(pname: s_pBaseDir, separator: 92);
  host_parms.basedir = s_pBaseDir;
  TraceInit(i: "Sys_Init()", s: "Sys_Shutdown()", listnum: 0);
  v7 = _CommandLine();
  v8 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-random_invariant");
  SeedRandomNumberGenerator(random_invariant: v8 != 0);
  TraceInit(i: "Sys_InitMemory()", s: "Sys_ShutdownMemory()", listnum: 0);
  Sys_InitMemory();
  TraceInit(i: "Host_Init( s_bIsDedicated )", s: "Host_Shutdown()", listnum: 0);
  Host_Init(a1, a2, a3: (int)_LoggingSystem_RegisterLoggingListener, bDedicated: s_bIsDedicated);
  if ( !host_initialized )
    return 0;
  TraceInit(i: "Sys_InitAuthentication()", s: "Sys_ShutdownAuthentication()", listnum: 0);
  MapReslistGenerator_BuildMapList();
  BuildMinidumpComment(pchSysErrorText: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5B20
// Name: void Sys_ShutdownGame(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_ShutdownGame()
{
  TraceShutdown(s: "Sys_ShutdownAuthentication()", listnum: 0);
  TraceShutdown(s: "Host_Shutdown()", listnum: 0);
  Host_Shutdown();
  TraceShutdown(s: "Sys_ShutdownMemory()", listnum: 0);
  host_parms.memsize = 0;
  TraceShutdown(s: "Sys_Shutdown()", listnum: 0);
  ConVar::RemoveChangeCallback(
    this: &developer,
    callback: (void (__cdecl *)(IConVar *, const char *, float))DeveloperChangeCallback);
  _LoggingSystem_PopLoggingState(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E5B80
// Name: LoadThisDll
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadThisDll(char *szDllFilename)
{
  struct CSysModule *pDLL; // [esp+4h] [ebp-4h]

  pDLL = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: szDllFilename, a3: "GAMEBIN", a4: 0);
  if ( pDLL == nullptr )
  {
    ConMsg(a1: "Failed to load %s\n", szDllFilename);
IgnoreThisDLL:
    if ( pDLL != nullptr )
    {
      g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: pDLL);
      serverGameDLL = nullptr;
      serverGameEnts = nullptr;
      serverGameClients = nullptr;
    }
    return 0;
  }
  g_ServerFactory = Sys_GetFactory(pModule: pDLL);
  if ( g_ServerFactory == nullptr )
  {
    ConMsg(a1: "Could not find factory interface in library %s", szDllFilename);
    goto IgnoreThisDLL;
  }
  g_bServerGameDLLGreaterThanV5 = true;
  serverGameDLL = (IServerGameDLL *)g_ServerFactory(a1: "ServerGameDLL005", a2: nullptr);
  if ( serverGameDLL == nullptr )
  {
    _Msg(a1: "Could not get IServerGameDLL interface from library %s", szDllFilename);
    goto IgnoreThisDLL;
  }
  serverGameEnts = (IServerGameEnts *)g_ServerFactory(a1: "ServerGameEnts001", a2: nullptr);
  if ( serverGameEnts == nullptr )
  {
    ConMsg(a1: "Could not get IServerGameEnts interface from library %s", szDllFilename);
    goto IgnoreThisDLL;
  }
  serverGameClients = (IServerGameClients *)g_ServerFactory(a1: "ServerGameClients004", a2: nullptr);
  if ( serverGameClients != nullptr )
  {
    g_iServerGameClientsVersion = 4;
  }
  else
  {
    serverGameClients = (IServerGameClients *)g_ServerFactory(a1: "ServerGameClients003", a2: nullptr);
    if ( serverGameClients == nullptr )
    {
      ConMsg(a1: "Could not get IServerGameClients interface from library %s", szDllFilename);
      goto IgnoreThisDLL;
    }
    g_iServerGameClientsVersion = 3;
  }
  serverGameDirector = (IHLTVDirector *)g_ServerFactory(a1: "HLTVDirector001", a2: nullptr);
  if ( serverGameDirector == nullptr )
    ConMsg(a1: "Could not get IHLTVDirector interface from library %s", szDllFilename);
  serverReplayDirector = (IReplayDirector *)g_ServerFactory(a1: "ReplayDirector001", a2: nullptr);
  if ( serverReplayDirector == nullptr )
    ConMsg(a1: "Could not get IReplayDirector interface from library %s", szDllFilename);
  serverGameTags = (IServerGameTags *)g_ServerFactory(a1: "ServerGameTags001", a2: nullptr);
  g_GameDLL = pDLL;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5DD0
// Name: void LoadEntityDLLs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadEntityDLLs()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi
  IBaseFileSystem *v2; // eax
  char *String; // eax
  char *v4; // eax
  char *v5; // eax
  const char *v6; // eax
  char szDllFilename[260]; // [esp+4h] [ebp-104h] BYREF

  memset(dst: (unsigned __int8 *)&gmodinfo, value: 0, count: sizeof(gmodinfo));
  gmodinfo.version = 1;
  gmodinfo.svonly = true;
  g_GameDLL = nullptr;
  sv_noclipduringpause = nullptr;
  v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v0 != nullptr )
    v1 = KeyValues::KeyValues(this: v0, setName: "modinfo");
  else
    v1 = nullptr;
  if ( g_pFileSystem != nullptr )
    v2 = &g_pFileSystem->IBaseFileSystem;
  else
    v2 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v1,
         filesystem: v2,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v1, keyName: "url_info", defaultValue: defaultValue);
    V_strncpy(pDest: gmodinfo.szInfo, pSrc: String, maxLen: 256);
    v4 = KeyValues::GetString(this: v1, keyName: "url_dl", defaultValue: defaultValue);
    V_strncpy(pDest: gmodinfo.szDL, pSrc: v4, maxLen: 256);
    gmodinfo.version = KeyValues::GetInt(this: v1, keyName: "version", defaultValue: 0);
    gmodinfo.size = KeyValues::GetInt(this: v1, keyName: "size", defaultValue: 0);
    gmodinfo.svonly = KeyValues::GetInt(this: v1, keyName: "svonly", defaultValue: 0) != 0;
    gmodinfo.cldll = KeyValues::GetInt(this: v1, keyName: "cldll", defaultValue: 0) != 0;
    v5 = KeyValues::GetString(this: v1, keyName: "hlversion", defaultValue: defaultValue);
    V_strncpy(pDest: gmodinfo.szHLVersion, pSrc: v5, maxLen: 32);
  }
  KeyValues::deleteThis(this: v1);
  V_snprintf(pDest: szDllFilename, maxLen: 260, pFormat: "server.dll");
  LoadThisDll(szDllFilename);
  if ( serverGameDLL != nullptr )
  {
    v6 = serverGameDLL->GetGameDescription(this: serverGameDLL);
    _Msg(a1: "Game.dll loaded for \"%s\"\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5F70
// Name: void Sys_GetRegKeyValueUnderRoot(struct HKEY__ __near *,char const __near *,char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_GetRegKeyValueUnderRoot(
        HKEY__ *rootKey,
        const char *pszSubKey,
        const char *pszElement,
        char *pszReturnString,
        int nReturnLength,
        const char *pszDefaultValue)
{
  DWORD v6; // [esp-4h] [ebp-A0h]
  HKEY__ *v7; // [esp-4h] [ebp-A0h]
  DWORD v8; // [esp-4h] [ebp-A0h]
  char szBuff[128]; // [esp+Ch] [ebp-90h] BYREF
  unsigned int dwDisposition; // [esp+8Ch] [ebp-10h] BYREF
  unsigned int dwType; // [esp+90h] [ebp-Ch] BYREF
  unsigned int dwSize; // [esp+94h] [ebp-8h] BYREF
  HKEY__ *hKey; // [esp+98h] [ebp-4h] BYREF

  V_strncpy(pDest: pszReturnString, pSrc: pszDefaultValue, maxLen: nReturnLength);
  if ( RegCreateKeyExA(
         hKey: rootKey,
         lpSubKey: pszSubKey,
         Reserved: 0,
         lpClass: (LPSTR)"String",
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &hKey,
         lpdwDisposition: &dwDisposition) == 0 )
  {
    if ( dwDisposition == 1 )
    {
      v6 = _V_strlen(str: pszDefaultValue) + 1;
      RegSetValueExA(
        hKey,
        lpValueName: pszElement,
        Reserved: 0,
        dwType: 1u,
        lpData: (const BYTE *)pszDefaultValue,
        cbData: v6);
    }
    else
    {
      dwSize = nReturnLength;
      if ( RegQueryValueExA(
             hKey,
             lpValueName: pszElement,
             lpReserved: nullptr,
             lpType: &dwType,
             lpData: (LPBYTE)szBuff,
             lpcbData: &dwSize) != 0 )
      {
        v8 = _V_strlen(str: pszDefaultValue) + 1;
        RegSetValueExA(
          hKey,
          lpValueName: pszElement,
          Reserved: 0,
          dwType: 1u,
          lpData: (const BYTE *)pszDefaultValue,
          cbData: v8);
      }
      else if ( dwType == 1 )
      {
        V_strncpy(pDest: pszReturnString, pSrc: szBuff, maxLen: nReturnLength);
        v7 = hKey;
        pszReturnString[nReturnLength - 1] = 0;
        RegCloseKey(hKey: v7);
        return;
      }
    }
    RegCloseKey(hKey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6060
// Name: void Sys_SetRegKeyValueUnderRoot(struct HKEY__ __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SetRegKeyValueUnderRoot(
        HKEY__ *rootKey,
        const char *pszSubKey,
        const char *pszElement,
        const char *pszValue)
{
  DWORD v4; // [esp-8h] [ebp-10h]
  unsigned int dwDisposition; // [esp+0h] [ebp-8h] BYREF
  HKEY__ *hKey; // [esp+4h] [ebp-4h] BYREF

  if ( RegCreateKeyExA(
         hKey: rootKey,
         lpSubKey: pszSubKey,
         Reserved: 0,
         lpClass: (LPSTR)"String",
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &hKey,
         lpdwDisposition: &dwDisposition) == 0 )
  {
    v4 = _V_strlen(str: pszValue) + 1;
    RegSetValueExA(hKey, lpValueName: pszElement, Reserved: 0, dwType: 1u, lpData: (const BYTE *)pszValue, cbData: v4);
    RegCloseKey(hKey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E60E0
// Name: void Sys_GetRegKeyValue(char __near *,char __near *,char __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_GetRegKeyValue(
        char *pszSubKey,
        char *pszElement,
        char *pszReturnString,
        int nReturnLength,
        char *pszDefaultValue)
{
  Sys_GetRegKeyValueUnderRoot(
    rootKey: (HKEY__ *)0x80000001,
    pszSubKey,
    pszElement,
    pszReturnString,
    nReturnLength,
    pszDefaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x101E6110
// Name: void Sys_SetRegKeyValue(char __near *,char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SetRegKeyValue(char *pszSubKey, char *pszElement, const char *pszValue)
{
  Sys_SetRegKeyValueUnderRoot(rootKey: (HKEY__ *)0x80000001, pszSubKey, pszElement, pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x101E6130
// Name: void Sys_CreateFileAssociations(int,struct FileAssociationInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_CreateFileAssociations(int count, FileAssociationInfo *list)
{
  const char *v2; // eax
  const char *v3; // eax
  int i; // esi
  const char *extension; // eax
  char quoted_appname_with_arg[512]; // [esp+8h] [ebp-520h] BYREF
  char appname[512]; // [esp+208h] [ebp-320h] BYREF
  char base_exe_name[256]; // [esp+408h] [ebp-120h] BYREF
  char binding[32]; // [esp+508h] [ebp-20h] BYREF

  GetModuleFileNameA(hModule: nullptr, lpFilename: appname, nSize: 0x200u);
  V_FixSlashes(pname: appname, separator: 92);
  _V_strlower(start: appname);
  V_snprintf(pDest: quoted_appname_with_arg, maxLen: 512, pFormat: "\"%s\" \"%%1\"", appname);
  V_FileBase(in: appname, out: base_exe_name, maxlen: 256);
  V_DefaultExtension(path: base_exe_name, extension: ".exe", pathStringLength: 256);
  v2 = va(format: "%s\\shell\\open\\command", "Valve.Source");
  Sys_SetRegKeyValueUnderRoot(
    rootKey: (HKEY__ *)0x80000000,
    pszSubKey: v2,
    pszElement: defaultValue,
    pszValue: quoted_appname_with_arg);
  v3 = va(format: "Applications\\%s\\shell\\open\\command", base_exe_name);
  Sys_SetRegKeyValueUnderRoot(
    rootKey: (HKEY__ *)0x80000000,
    pszSubKey: v3,
    pszElement: defaultValue,
    pszValue: quoted_appname_with_arg);
  for ( i = 0; i < count; ++i )
  {
    extension = list[i].extension;
    binding[0] = 0;
    Sys_GetRegKeyValueUnderRoot(
      rootKey: (HKEY__ *)0x80000000,
      pszSubKey: extension,
      pszElement: defaultValue,
      pszReturnString: binding,
      nReturnLength: 32,
      pszDefaultValue: defaultValue);
    if ( _V_strlen(str: binding) == 0 )
      Sys_SetRegKeyValueUnderRoot(
        rootKey: (HKEY__ *)0x80000000,
        pszSubKey: list[i].extension,
        pszElement: defaultValue,
        pszValue: "Valve.Source");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6280
// Name: void Sys_NoCrashDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_NoCrashDialog()
{
  UINT v0; // eax

  v0 = SetErrorMode(uMode: 2u);
  SetErrorMode(uMode: v0 | 2);
}

//------------------------------------------------------------------------------
// Address: 0x101E62A0
// Name: void Sys_TestSendKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_TestSendKey(const char *pKey)
{
  WPARAM v1; // edi
  HWND v2; // esi

  v1 = *pKey;
  if ( *pKey == 92 && pKey[1] == 114 )
    v1 = 13;
  v2 = (HWND)game->GetMainWindow(this: game);
  PostMessageA(hWnd: v2, Msg: 0x100u, wParam: v1, lParam: 0);
  PostMessageA(hWnd: v2, Msg: 0x101u, wParam: v1, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E62F0
// Name: void Sys_OutputDebugString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_OutputDebugString(const char *msg)
{
  _Plat_DebugString(a1: msg);
}

//------------------------------------------------------------------------------
// Address: 0x101E6300
// Name: void UnloadEntityDLLs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnloadEntityDLLs()
{
  if ( g_GameDLL != nullptr )
  {
    FileSystem_UnloadModule(pModule: g_GameDLL);
    g_GameDLL = nullptr;
    serverGameDLL = nullptr;
    serverGameEnts = nullptr;
    serverGameClients = nullptr;
    sv_noclipduringpause = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6340
// Name: star_memory
// Source: json
//------------------------------------------------------------------------------
void __cdecl star_memory()
{
  _MEMORYSTATUS Buffer; // [esp+0h] [ebp-24h] BYREF
  unsigned int dwTotalPhys; // [esp+20h] [ebp-4h]

  GlobalMemoryStatus(lpBuffer: &Buffer);
  dwTotalPhys = Buffer.dwTotalPhys;
  _Msg(
    a1: "Available: %.2f MB, Used: %.2f MB, Free: %.2f MB\n",
    0.00000095367432 * (double)Buffer.dwTotalPhys - 32.0,
    (double)(Buffer.dwTotalPhys - Buffer.dwAvailPhys) * 0.00000095367432 - 32.0,
    (double)Buffer.dwAvailPhys * 0.00000095367432);
}

//------------------------------------------------------------------------------
// Address: 0x101E63D0
// Name: warningcallstacks_length_callback
// Source: json
//------------------------------------------------------------------------------
void __cdecl warningcallstacks_length_callback(IConVar *var)
{
  IConVar *v1; // eax
  IConVar_vtbl *v2; // eax

  if ( var != nullptr )
    v1 = var - 6;
  else
    v1 = nullptr;
  v2 = v1[7].__vftable;
  if ( v2 != nullptr )
    __Warning_AlwaysSpewCallStack_Length(a1: v2[1].GetName);
  else
    __Warning_AlwaysSpewCallStack_Length(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6410
// Name: errorcallstacks_length_callback
// Source: json
//------------------------------------------------------------------------------
void __cdecl errorcallstacks_length_callback(IConVar *var)
{
  IConVar *v1; // eax
  IConVar_vtbl *v2; // eax

  if ( var != nullptr )
    v1 = var - 6;
  else
    v1 = nullptr;
  v2 = v1[7].__vftable;
  if ( v2 != nullptr )
    __Error_AlwaysSpewCallStack_Length(a1: v2[1].GetName);
  else
    __Error_AlwaysSpewCallStack_Length(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6450
// Name: char const __near * Sys_FindFirst(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_FindFirst(const char *path, char *basename, int namelength)
{
  const char *v3; // esi

  if ( g_hfind != -1 )
  {
    Sys_Error(error: "Sys_FindFirst without close");
    g_pFileSystem->FindClose(this: g_pFileSystem, a2: g_hfind);
  }
  v3 = g_pFileSystem->FindFirst(this: g_pFileSystem, a2: path, a3: &g_hfind);
  if ( basename != nullptr && v3 != nullptr )
    V_FileBase(in: v3, out: basename, maxlen: namelength);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101E64C0
// Name: char const __near * Sys_FindFirstEx(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_FindFirstEx(const char *pWildcard, const char *pPathID, char *basename, int namelength)
{
  const char *v4; // esi

  if ( g_hfind != -1 )
  {
    Sys_Error(error: "Sys_FindFirst without close");
    g_pFileSystem->FindClose(this: g_pFileSystem, a2: g_hfind);
  }
  v4 = g_pFileSystem->FindFirstEx(this: g_pFileSystem, a2: pWildcard, a3: pPathID, a4: &g_hfind);
  if ( basename != nullptr && v4 != nullptr )
    V_FileBase(in: v4, out: basename, maxlen: namelength);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101E6530
// Name: warningcallstacks_enable_callback
// Source: json
//------------------------------------------------------------------------------
void __cdecl warningcallstacks_enable_callback(IConVar *var)
{
  IConVar *v1; // eax
  IConVar_vtbl *v2; // eax

  if ( var != nullptr )
    v1 = var - 6;
  else
    v1 = nullptr;
  v2 = v1[7].__vftable;
  if ( v2 != nullptr )
    __Warning_AlwaysSpewCallStack_Enable(a1: v2[1].GetName != nullptr);
  else
    __Warning_AlwaysSpewCallStack_Enable(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6580
// Name: errorcallstacks_enable_callback
// Source: json
//------------------------------------------------------------------------------
void __cdecl errorcallstacks_enable_callback(IConVar *var)
{
  IConVar *v1; // eax
  IConVar_vtbl *v2; // eax

  if ( var != nullptr )
    v1 = var - 6;
  else
    v1 = nullptr;
  v2 = v1[7].__vftable;
  if ( v2 != nullptr )
    __Error_AlwaysSpewCallStack_Enable(a1: v2[1].GetName != nullptr);
  else
    __Error_AlwaysSpewCallStack_Enable(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6750
// Name: void GetSpew(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSpew(char *buf, const CUtlString *buflen)
{
  DWORD CurrentThreadId; // ecx
  int m_Previous; // eax
  int v4; // ebx
  UtlLinkedListElem_t<CUtlString,unsigned short> *m_pMemory; // ecx
  unsigned int v6; // esi
  int v7; // edi
  const char *v8; // eax
  CUtlString *rec; // [esp+14h] [ebp+Ch]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_SpewMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_SpewMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_SpewMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_SpewMutex.m_depth;
  }
  LOWORD(m_Previous) = g_SpewHistory.m_Tail;
  v4 = (int)&buflen[-1].m_Storage.m_nActualLength + 3;
  if ( g_SpewHistory.m_Tail != 0xFFFF )
  {
    m_pMemory = g_SpewHistory.m_Memory.m_pMemory;
    do
    {
      v6 = (unsigned __int16)m_Previous;
      rec = &m_pMemory[v6].m_Element;
      v7 = CUtlString::Length(this: &m_pMemory[v6].m_Element);
      if ( v7 >= v4 )
        v7 = v4;
      if ( v7 <= 0 )
        break;
      v8 = CUtlString::operator char const *(this: rec);
      _V_memcpy(dest: buf, src: v8, count: v7);
      buf += v7;
      v4 -= v7;
      if ( v4 <= 0 )
        break;
      m_pMemory = g_SpewHistory.m_Memory.m_pMemory;
      m_Previous = g_SpewHistory.m_Memory.m_pMemory[v6].m_Previous;
    }
    while ( m_Previous != 0xFFFF );
  }
  *buf = 0;
  if ( --g_SpewMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_SpewMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6A70
// Name: AddSpewRecord
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl AddSpewRecord(const char *pMsg)
{
  CStatTime *v1; // ecx
  double v2; // st7
  DWORD CurrentThreadId; // ecx
  int m_nValue; // eax
  int v5; // esi
  UtlLinkedListElem_t<CUtlString,unsigned short> *v6; // ecx
  CUtlString string; // [esp+Ch] [ebp-18h] BYREF
  int str; // [esp+1Ch] [ebp-8h] OVERLAPPED

  CUtlString::CUtlString(this: (CUtlString *)&string.m_Storage.m_Memory.m_nAllocationCount);
  v2 = _Plat_FloatTime(this: v1);
  CUtlString::Format(
    this: (CUtlString *)&string.m_Storage.m_Memory.m_nAllocationCount,
    pFormat: "%d(%f):  %s",
    g_nSpewLines,
    v2,
    pMsg);
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_SpewMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_SpewMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_SpewMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_SpewMutex.m_depth;
  }
  ++g_nSpewLines;
  if ( sys_minidumpspewlines.m_pParent != nullptr )
    m_nValue = sys_minidumpspewlines.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_SpewHistory.m_ElementCount > m_nValue )
    CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Remove(
      this: &g_SpewHistory,
      elem: g_SpewHistory.m_Head);
  v5 = (unsigned __int16)CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal(
                           this: &g_SpewHistory,
                           multilist: false);
  if ( (_WORD)v5 != 0xFFFF )
  {
    CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::LinkBefore(
      this: &g_SpewHistory,
      before: 0xFFFFu,
      elem: v5);
    v6 = &g_SpewHistory.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
      CUtlString::CUtlString(
        this: &v6->m_Element,
        string: (const CUtlString *)&string.m_Storage.m_Memory.m_nAllocationCount);
  }
  if ( --g_SpewMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_SpewMutex, 0);
  str = 0;
  if ( string.m_Storage.m_nActualLength >= 0 && string.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)string.m_Storage.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x101E6BA0
// Name: public: virtual void CEngineConsoleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineConsoleLoggingListener::Log(
        CEngineConsoleLoggingListener *this,
        const LoggingContext_t *pContext,
        Color pMessage)
{
  bool v3; // bl
  const char *v4; // esi
  LoggingSeverity_t m_Severity; // eax
  const char *m_Color; // ecx

  if ( (pContext->m_Flags & 2) != 0 )
  {
    if ( pContext->m_ChannelID == LOG_SERVER_LOG )
      CLog::Print(this: &g_Log, text: *(const char **)&pMessage);
  }
  else
  {
    v3 = GenericThreadLocals::CThreadLocalBase::Get(this: &g_bInSpew) != nullptr;
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_bInSpew, a2: (void *)1);
    v4 = (const char *)pMessage;
    AddSpewRecord(pMsg: *(const char **)&pMessage);
    if ( !v3 )
    {
      if ( dedicated != nullptr && g_nForkID <= 0 )
        ((void (__stdcall *)(const char *))dedicated->Sys_Printf)(a1: v4);
      if ( g_bTextMode )
        printf(format: "%s", v4);
      m_Severity = pContext->m_Severity;
      m_Color = (const char *)pContext->m_Color;
      pMessage = (Color)m_Color;
      switch ( m_Severity )
      {
        case LS_MESSAGE:
          if ( m_Color == *(const char **)&UNSPECIFIED_LOGGING_COLOR_146 )
            pMessage = (Color)-1;
          break;
        case LS_WARNING:
          pMessage = (Color)-10855681;
          break;
        case LS_ASSERT:
          pMessage = (Color)-15461121;
          break;
        case LS_ERROR:
          pMessage = (Color)-47596;
          break;
        default:
          break;
      }
      Con_ColorPrintf(clr: &pMessage, fmt: "%s", v4);
    }
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_bInSpew, a2: nullptr);
    if ( pContext->m_Severity == LS_ERROR )
      Sys_Error(error: "%s", v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031DD30
// Name: _dynamic_initializer_for__sys_minidumpspewlines__
// Source: semantic_dyn_pfx_sys
//------------------------------------------------------------------------------
int dynamic_initializer_for__sys_minidumpspewlines__()
{
  ConVar::ConVar(
    this: &sys_minidumpspewlines,
    pName: "sys_minidumpspewlines",
    pDefaultValue: "500",
    flags: 0x80000,
    pHelpString: "Lines of crash dump console spew to keep.");
  return atexit(func: dynamic_atexit_destructor_for__sys_minidumpspewlines__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DFB0
// Name: _dynamic_initializer_for__sys_minidumpexpandedspew__
// Source: semantic_dyn_pfx_sys
//------------------------------------------------------------------------------
int dynamic_initializer_for__sys_minidumpexpandedspew__()
{
  ConVar::ConVar(this: &sys_minidumpexpandedspew, pName: "sys_minidumpexpandedspew", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sys_minidumpexpandedspew__);
}

//------------------------------------------------------------------------------
// Address: 0x10326970
// Name: _dynamic_atexit_destructor_for__sys_minidumpspewlines__
// Source: semantic_dyn_pfx_sys
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sys_minidumpspewlines__()
{
  ConVar::~ConVar(this: &sys_minidumpspewlines);
}

//------------------------------------------------------------------------------
// Address: 0x10326A70
// Name: _dynamic_atexit_destructor_for__sys_minidumpexpandedspew__
// Source: semantic_dyn_pfx_sys
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sys_minidumpexpandedspew__()
{
  ConVar::~ConVar(this: &sys_minidumpexpandedspew);
}

//------------------------------------------------------------------------------
// Address: 0x101E58E0
// Name: __CreateCFileLoggingListenerIFileLoggingListener_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFileLoggingListener *__cdecl _CreateCFileLoggingListenerIFileLoggingListener_interface()
{
  return &s_FileLoggingListener;
}

//------------------------------------------------------------------------------
// Address: 0x101E6CC0
// Name: void F(class IEngineAPI __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl F(IEngineAPI **api)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  *api = (IEngineAPI *)FactoryThis(a1: "VENGINE_LAUNCHER_API_VERSION004", a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1031DD60
// Name: _dynamic_initializer_for__g_SpewHistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SpewHistory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SpewHistory__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DD70
// Name: _dynamic_initializer_for__g_SpewMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SpewMutex__()
{
  g_SpewMutex.m_ownerID = 0;
  g_SpewMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1031DFF0
// Name: _dynamic_initializer_for__errorText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__errorText__()
{
  errorText.m_errorText = (char *)MemAlloc_Alloc(nSize: 0x17318u);
  _V_memset(dest: (unsigned __int8 *)errorText.m_errorText, fill: 0, count: errorText.m_Size);
  return atexit(func: dynamic_atexit_destructor_for__errorText__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E020
// Name: _dynamic_initializer_for__g_sVersionString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_sVersionString__()
{
  CUtlString::CUtlString(this: &g_sVersionString);
  return atexit(func: dynamic_atexit_destructor_for__g_sVersionString__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E040
// Name: _dynamic_initializer_for__g_sProductString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_sProductString__()
{
  CUtlString::CUtlString(this: &g_sProductString);
  return atexit(func: dynamic_atexit_destructor_for__g_sProductString__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E060
// Name: _dynamic_initializer_for____g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg,
           fn: (void *(__cdecl *)())_CreateCDedicatedServerAPIIDedicatedServerAPI_interface,
           pName: "VENGINE_HLDS_API_VERSION002");
}

//------------------------------------------------------------------------------
// Address: 0x1031E080
// Name: _dynamic_initializer_for____g_CreateCGameUIFuncsIGameUIFuncs_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCGameUIFuncsIGameUIFuncs_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCGameUIFuncsIGameUIFuncs_reg,
           fn: (void *(__cdecl *)())_CreateCGameUIFuncsIGameUIFuncs_interface,
           pName: "VENGINE_GAMEUIFUNCS_VERSION005");
}

//------------------------------------------------------------------------------
// Address: 0x1031E0A0
// Name: _dynamic_initializer_for__fps_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fps_max__()
{
  ConVar::ConVar(this: &fps_max, pName: "fps_max", pDefaultValue: "300", flags: 0, pHelpString: "Frame rate limiter");
  return atexit(func: dynamic_atexit_destructor_for__fps_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E0D0
// Name: _dynamic_initializer_for__fps_max_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fps_max_splitscreen__()
{
  ConVar::ConVar(
    this: &fps_max_splitscreen,
    pName: "fps_max_splitscreen",
    pDefaultValue: "300",
    flags: 0,
    pHelpString: "Frame rate limiter, splitscreen");
  return atexit(func: dynamic_atexit_destructor_for__fps_max_splitscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E100
// Name: _dynamic_initializer_for__async_serialize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_serialize__()
{
  ConVar::ConVar(
    this: &async_serialize,
    pName: "async_serialize",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Force async reads to serialize for profiling");
  return atexit(func: dynamic_atexit_destructor_for__async_serialize__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E130
// Name: _dynamic_initializer_for__vx_do_not_throttle_events__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vx_do_not_throttle_events__()
{
  ConVar::ConVar(
    this: &vx_do_not_throttle_events,
    pName: "vx_do_not_throttle_events",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Force VXConsole updates every frame; smoother vprof data on PS3 but at a slight (~0.2ms) perf cost.");
  return atexit(func: dynamic_atexit_destructor_for__vx_do_not_throttle_events__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E160
// Name: _dynamic_initializer_for__g_Engine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Engine__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Engine__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E170
// Name: _dynamic_initializer_for__g_Game__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Game__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Game__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E180
// Name: _dynamic_initializer_for__g_GameMessageHandlers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__thiscall *dynamic_initializer_for__g_GameMessageHandlers__())(CGame *this, const InputEvent_t *event)
{
  dword_10422B40[0] = (int)CGame::HandleMsg_ActivateApp;
  dword_10422B58 = (int)CGame::HandleMsg_WindowMove;
  dword_10422B70 = (int)CGame::HandleMsg_Close;
  dword_10422B4C = 0;
  dword_10422B64 = 0;
  dword_10422B7C = 0;
  dword_10422B94 = 0;
  dword_10422B44[0] = 0;
  dword_10422B48 = 0;
  dword_10422B5C = 0;
  dword_10422B60 = 0;
  dword_10422B74 = 0;
  dword_10422B78 = 0;
  dword_10422B88 = (int)CGame::HandleMsg_Close;
  dword_10422B8C = 0;
  dword_10422B90 = 0;
  return CGame::HandleMsg_Close;
}

//------------------------------------------------------------------------------
// Address: 0x1031E200
// Name: _dynamic_initializer_for__g_TestScriptMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TestScriptMgr__()
{
  CTestScriptMgr::CTestScriptMgr(this: &g_TestScriptMgr);
  return atexit(func: dynamic_atexit_destructor_for__g_TestScriptMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10326A80
// Name: _dynamic_atexit_destructor_for__errorText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__errorText__()
{
  free(pMem: errorText.m_errorText);
}

//------------------------------------------------------------------------------
// Address: 0x10326A90
// Name: _dynamic_atexit_destructor_for__g_sVersionString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_sVersionString__()
{
  g_sVersionString.m_Storage.m_nActualLength = 0;
  if ( g_sVersionString.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_sVersionString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_sVersionString.m_Storage.m_Memory.m_pMemory);
      g_sVersionString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    g_sVersionString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326B10
// Name: _dynamic_atexit_destructor_for__g_sProductString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_sProductString__()
{
  g_sProductString.m_Storage.m_nActualLength = 0;
  if ( g_sProductString.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_sProductString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_sProductString.m_Storage.m_Memory.m_pMemory);
      g_sProductString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    g_sProductString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326B90
// Name: _dynamic_atexit_destructor_for__g_TextModeLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TextModeLine__()
{
  char *m_pMemory; // eax

  m_pMemory = g_TextModeLine.m_Memory.m_pMemory;
  g_TextModeLine.m_Size = 0;
  if ( g_TextModeLine.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_TextModeLine.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_TextModeLine.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_TextModeLine.m_Memory.m_pMemory = nullptr;
    }
    g_TextModeLine.m_Memory.m_nAllocationCount = 0;
  }
  g_TextModeLine.m_pElements = m_pMemory;
  if ( g_TextModeLine.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_TextModeLine.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_TextModeLine.m_Memory.m_pMemory);
      g_TextModeLine.m_Memory.m_pMemory = nullptr;
    }
    g_TextModeLine.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326C30
// Name: _dynamic_atexit_destructor_for__fps_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fps_max__()
{
  ConVar::~ConVar(this: &fps_max);
}

//------------------------------------------------------------------------------
// Address: 0x10326C40
// Name: _dynamic_atexit_destructor_for__fps_max_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fps_max_splitscreen__()
{
  ConVar::~ConVar(this: &fps_max_splitscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10326C50
// Name: _dynamic_atexit_destructor_for__async_serialize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_serialize__()
{
  ConVar::~ConVar(this: &async_serialize);
}

//------------------------------------------------------------------------------
// Address: 0x10326C60
// Name: _dynamic_atexit_destructor_for__vx_do_not_throttle_events__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vx_do_not_throttle_events__()
{
  ConVar::~ConVar(this: &vx_do_not_throttle_events);
}

//------------------------------------------------------------------------------
// Address: 0x10326C70
// Name: _dynamic_atexit_destructor_for__g_Engine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Engine__()
{
  g_Engine.__vftable = (CEngine_vtbl *)&IEngine::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10326C80
// Name: _dynamic_atexit_destructor_for__g_Game__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Game__()
{
  g_Game.__vftable = (CGame_vtbl *)&IGame::`vftable';
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101E5510
// Name: int Sys_CompareFileTime(long,long)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_CompareFileTime(int ft1, int ft2)
{
  if ( ft1 >= ft2 )
    return ft1 > ft2;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5530
// Name: void Sys_mkdir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_mkdir(const char *path)
{
  int v1; // eax
  char *v2; // ecx
  const char *v3; // esi
  char testpath[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: testpath, pSrc: path, maxLen: 260);
  v1 = _V_strlen(str: testpath);
  if ( v1 > 0 )
  {
    v2 = &testpath[v1 - 1];
    if ( testpath[v1 - 1] == 92 || *v2 == 47 )
      *v2 = 0;
  }
  v3 = "MOD";
  if ( (testpath[0] == 92 || testpath[0] == 47) && (testpath[1] == 92 || testpath[1] == 47) )
    v3 = nullptr;
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: testpath, a3: v3)
    && !g_pFileSystem->IsDirectory(this: g_pFileSystem, a2: testpath, a3: v3) )
  {
    g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: testpath, a3: v3);
  }
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: path, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101E5600
// Name: char const __near * Sys_FindNext(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_FindNext(char *basename, int namelength)
{
  const char *v2; // esi

  v2 = g_pFileSystem->FindNext(this: g_pFileSystem, a2: g_hfind);
  if ( basename != nullptr && v2 != nullptr )
    V_FileBase(in: v2, out: basename, maxlen: namelength);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101E5640
// Name: void Sys_FindClose(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_FindClose()
{
  if ( g_hfind != -1 )
  {
    g_pFileSystem->FindClose(this: g_pFileSystem, a2: g_hfind);
    g_hfind = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5670
// Name: void Sys_Printf(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_Printf(char *fmt, ...)
{
  wchar_t WideCharStr[2048]; // [esp+0h] [ebp-1400h] BYREF
  char pDest[1024]; // [esp+1000h] [ebp-400h] BYREF
  va_list params; // [esp+140Ch] [ebp+Ch] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 1024, pFormat: fmt, params);
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    MultiByteToWideChar(
      CodePage: 0xFDE9u,
      dwFlags: 0,
      lpMultiByteStr: pDest,
      cbMultiByte: -1,
      lpWideCharStr: WideCharStr,
      cchWideChar: 2048);
    WideCharStr[2047] = 0;
    OutputDebugStringW(lpOutputString: WideCharStr);
    Sleep(dwMilliseconds: 0);
  }
  if ( s_bIsDedicated )
    printf(format: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x101E5710
// Name: bool Sys_MessageBox(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Sys_MessageBox(const char *title, const char *info, bool bShowOkAndCancel)
{
  return MessageBoxA(hWnd: nullptr, lpText: title, lpCaption: info, uType: bShowOkAndCancel | 0x30) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5740
// Name: void Sys_Error_Internal(bool,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Error_Internal(bool bMinidump, const char *error, char *argsList)
{
  _iobuf *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-424h]
  int v8; // [esp+0h] [ebp-424h]
  char text[1024]; // [esp+Ch] [ebp-418h] BYREF
  int v10; // [esp+420h] [ebp-4h]

  V_vsnprintf(pDest: text, maxLen: 1024, pFormat: error, params: argsList);
  if ( bReentry )
  {
    v3 = __iob_func();
    fprintf(str: v3 + 2, format: "%s\n", text);
  }
  else
  {
    bReentry = true;
    if ( s_bIsDedicated )
      printf(format: "%s\n", text);
    else
      Sys_Printf(fmt: "%s\n", text);
    g_bInErrorExit = true;
    if ( videomode != nullptr )
      videomode->Shutdown(this: videomode);
    v4 = _CommandLine(a1: v7);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-makereslists") == 0 )
    {
      v5 = _CommandLine(a1: v8);
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-nomessagebox") == 0 )
        MessageBoxA(hWnd: nullptr, lpText: text, lpCaption: "Engine Error", uType: 0x40000u);
    }
    if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
      __debugbreak();
    BuildMinidumpComment(pchSysErrorText: text);
    g_bUpdateMinidumpComment = false;
    if ( bMinidump && (unsigned __int8)_Plat_IsInDebugSession() == 0 )
    {
      v6 = _CommandLine(a1: v8);
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-nominidumps") == 0 )
      {
        v10 = 0;
        RaiseException(dwExceptionCode: 0, dwExceptionFlags: 1u, nNumberOfArguments: 0, lpArguments: nullptr);
        v10 = -1;
      }
    }
    host_initialized = false;
    _Plat_ExitProcess(a1: 100);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5900
// Name: void Sys_Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_Error(const char *error, ...)
{
  va_list argsList; // [esp+Ch] [ebp+Ch] BYREF

  va_start(argsList, error);
  Sys_Error_Internal(bMinidump: true, error, argsList);
}

//------------------------------------------------------------------------------
// Address: 0x101E5920
// Name: void Sys_Exit(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_Exit(const char *error, ...)
{
  va_list argsList; // [esp+Ch] [ebp+Ch] BYREF

  va_start(argsList, error);
  Sys_Error_Internal(bMinidump: false, error, argsList);
}

//------------------------------------------------------------------------------
// Address: 0x101E5940
// Name: void Sys_Sleep(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Sleep()
{
  _ThreadSleep();
}

//------------------------------------------------------------------------------
// Address: 0x101E5960
// Name: void Sys_InitMemory(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Sys_InitMemory()
{
  int v0; // eax
  unsigned int ullTotalPhys; // eax
  ConVar *m_pParent; // esi
  ConVar *v3; // edi
  unsigned int v4; // eax
  int v5; // ecx
  int m_nValue; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  _OSVERSIONINFOEXA osvi; // [esp+0h] [ebp-DCh] BYREF
  _MEMORYSTATUSEX lpBuffer; // [esp+9Ch] [ebp-40h] OVERLAPPED BYREF

  v0 = _CommandLine(a1: osvi.dwOSVersionInfoSize);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-minmemory") != 0 )
  {
    if ( mem_min_heapsize.m_pParent != nullptr )
      host_parms.memsize = mem_min_heapsize.m_pParent->m_Value.m_nValue << 20;
    else
      host_parms.memsize = 0;
    return;
  }
  host_parms.memsize = 0;
  memset(dst: (unsigned __int8 *)&osvi, value: 0, count: sizeof(osvi));
  osvi.dwOSVersionInfoSize = 156;
  if ( GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi)
    && osvi.dwPlatformId >= 2
    && osvi.dwMajorVersion >= 5
    && (memset(dst: (unsigned __int8 *)&lpBuffer, value: 0, count: sizeof(lpBuffer)),
        lpBuffer.dwLength = 64,
        GlobalMemoryStatusEx(&lpBuffer)) )
  {
    if ( HIDWORD(lpBuffer.ullTotalPhys) != 0 )
    {
      m_pParent = mem_min_heapsize.m_pParent;
      v3 = mem_max_heapsize.m_pParent;
      ullTotalPhys = -1;
LABEL_12:
      v4 = ullTotalPhys >> 2;
LABEL_13:
      host_parms.memsize = v4;
      goto LABEL_14;
    }
    ullTotalPhys = lpBuffer.ullTotalPhys;
    host_parms.memsize = lpBuffer.ullTotalPhys;
  }
  else
  {
    ullTotalPhys = host_parms.memsize;
  }
  if ( ullTotalPhys != 0 )
  {
    v3 = mem_max_heapsize.m_pParent;
    goto LABEL_33;
  }
  LODWORD(lpBuffer.ullAvailPageFile) = 32;
  GlobalMemoryStatus(lpBuffer: (LPMEMORYSTATUS)&lpBuffer.ullAvailPageFile);
  ullTotalPhys = lpBuffer.ullTotalVirtual;
  v3 = mem_max_heapsize.m_pParent;
  if ( LODWORD(lpBuffer.ullTotalVirtual) != 0 )
  {
    host_parms.memsize = lpBuffer.ullTotalVirtual;
LABEL_33:
    m_pParent = mem_min_heapsize.m_pParent;
    goto LABEL_34;
  }
  if ( mem_max_heapsize.m_pParent != nullptr )
    m_nValue = mem_max_heapsize.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  m_pParent = mem_min_heapsize.m_pParent;
  if ( mem_min_heapsize.m_pParent != nullptr )
    v7 = mem_min_heapsize.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  if ( m_nValue << 20 <= (unsigned int)(v7 << 20) )
  {
    if ( mem_min_heapsize.m_pParent != nullptr )
    {
      ullTotalPhys = mem_min_heapsize.m_pParent->m_Value.m_nValue << 20;
      host_parms.memsize = ullTotalPhys;
      goto LABEL_34;
    }
  }
  else if ( mem_max_heapsize.m_pParent != nullptr )
  {
    ullTotalPhys = mem_max_heapsize.m_pParent->m_Value.m_nValue << 20;
    host_parms.memsize = ullTotalPhys;
    goto LABEL_34;
  }
  ullTotalPhys = 0;
  host_parms.memsize = 0;
LABEL_34:
  if ( ullTotalPhys < 0x8000000 )
  {
    Sys_Error(error: "Available memory less than 128MB!!! %i\n", ullTotalPhys);
    ullTotalPhys = host_parms.memsize;
    m_pParent = mem_min_heapsize.m_pParent;
    v3 = mem_max_heapsize.m_pParent;
  }
  if ( ullTotalPhys > 0x20000000 )
    goto LABEL_12;
  v4 = ullTotalPhys >> 2;
  host_parms.memsize = v4;
  if ( mem_max_heapsize_dedicated.m_pParent != nullptr )
    v8 = mem_max_heapsize_dedicated.m_pParent->m_Value.m_nValue;
  else
    v8 = 0;
  if ( v4 > v8 << 20 )
  {
    if ( mem_max_heapsize_dedicated.m_pParent != nullptr )
      v4 = mem_max_heapsize_dedicated.m_pParent->m_Value.m_nValue << 20;
    else
      v4 = 0;
    goto LABEL_13;
  }
LABEL_14:
  if ( m_pParent != nullptr )
    v5 = m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  if ( v4 < v5 << 20 )
  {
    if ( m_pParent != nullptr )
      v9 = m_pParent->m_Value.m_nValue;
    else
      v9 = 0;
    v4 = v9 << 20;
    host_parms.memsize = v4;
  }
  if ( v3 != nullptr )
    v10 = v3->m_Value.m_nValue;
  else
    v10 = 0;
  if ( m_pParent != nullptr )
    v11 = m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  if ( v10 << 20 <= (unsigned int)(v11 << 20) )
  {
    if ( m_pParent != nullptr )
    {
      v12 = m_pParent->m_Value.m_nValue;
      goto LABEL_62;
    }
LABEL_61:
    v12 = 0;
    goto LABEL_62;
  }
  if ( v3 == nullptr )
    goto LABEL_61;
  v12 = v3->m_Value.m_nValue;
LABEL_62:
  if ( v4 <= v12 << 20 )
    return;
  if ( v3 != nullptr )
    v13 = v3->m_Value.m_nValue;
  else
    v13 = 0;
  if ( m_pParent != nullptr )
    v14 = m_pParent->m_Value.m_nValue;
  else
    v14 = 0;
  if ( v13 << 20 <= (unsigned int)(v14 << 20) )
  {
    if ( m_pParent != nullptr )
    {
      host_parms.memsize = m_pParent->m_Value.m_nValue << 20;
      return;
    }
  }
  else if ( v3 != nullptr )
  {
    host_parms.memsize = v3->m_Value.m_nValue << 20;
    return;
  }
  host_parms.memsize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E5C20
// Name: void DeveloperChangeCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeveloperChangeCallback(IConVar *pConVar)
{
  int m_nValue; // esi
  ConVarRef var; // [esp+8h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  m_nValue = var.m_pConVarState->m_Value.m_nValue;
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "Developer", a2: m_nValue >= 1 ? 0 : 3);
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "DeveloperVerbose", a2: m_nValue >= 2 ? 0 : 3);
}

//------------------------------------------------------------------------------
// Address: 0x101E5C80
// Name: void __near * GameFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GameFactory(const char *pName, int *pReturnCode)
{
  void *result; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IEngineVGuiInternal *v4; // eax
  IEngineVGuiInternal *v5; // eax
  int (*v6)(void); // eax

  result = g_AppSystemFactory(a1: pName, a2: pReturnCode);
  if ( result == nullptr )
  {
    result = g_pfnMatchmakingFactory(a1: pName, a2: pReturnCode);
    if ( result == nullptr )
    {
      if ( ClientDLL_GetFactory() == nullptr
        || (Factory = ClientDLL_GetFactory(), (result = Factory(a1: pName, a2: pReturnCode)) == nullptr) )
      {
        v4 = EngineVGui();
        if ( v4->GetGameUIFactory(this: v4) == nullptr )
          return nullptr;
        v5 = EngineVGui();
        v6 = (int (*)(void))((int (__thiscall *)(IEngineVGuiInternal *, const char *, int *))v5->GetGameUIFactory)(
                              a1: v5,
                              a2: pName,
                              a3: pReturnCode);
        result = (void *)v6();
        if ( result == nullptr )
          return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E5D00
// Name: int Sys_InitGame(void __near * (*)(char const __near *,int __near *),char const __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __usercall Sys_InitGame@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        void *(__cdecl *appSystemFactory)(const char *, int *),
        const char *pBaseDir,
        HWND__ **pwnd,
        int bIsDedicated)
{
  vgui::PropertyPage *v6; // ecx
  int v7; // eax
  int v8; // eax
  int v10; // [esp+0h] [ebp-4h]

  InitMathlib();
  CColorBalanceUIPanel::Init(this: v6);
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "Console", a2: 0);
  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &s_EngineLoggingListener);
  _LoggingSystem_RegisterLoggingListener(a1: &s_FileLoggingListener);
  ConVar::InstallChangeCallback(
    this: &developer,
    callback: (void (__cdecl *)(IConVar *, const char *, float))DeveloperChangeCallback,
    bInvoke: true);
  host_initialized = false;
  pmainwindow = pwnd;
  s_bIsDedicated = bIsDedicated != 0;
  memset(dst: (unsigned __int8 *)&gmodinfo, value: 0, count: sizeof(gmodinfo));
  V_strncpy(pDest: s_pBaseDir, pSrc: pBaseDir, maxLen: 256);
  _V_strlower(start: s_pBaseDir);
  V_FixSlashes(pname: s_pBaseDir, separator: 92);
  host_parms.basedir = s_pBaseDir;
  TraceInit(i: "Sys_Init()", s: "Sys_Shutdown()", listnum: 0);
  v7 = _CommandLine(a1: v10);
  v8 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-random_invariant");
  SeedRandomNumberGenerator(random_invariant: v8 != 0);
  TraceInit(i: "Sys_InitMemory()", s: "Sys_ShutdownMemory()", listnum: 0);
  Sys_InitMemory();
  TraceInit(i: "Host_Init( s_bIsDedicated )", s: "Host_Shutdown()", listnum: 0);
  Host_Init(a1, a2, a3: (int)_LoggingSystem_RegisterLoggingListener, bDedicated: s_bIsDedicated);
  if ( !host_initialized )
    return 0;
  TraceInit(i: "Sys_InitAuthentication()", s: "Sys_ShutdownAuthentication()", listnum: 0);
  MapReslistGenerator_BuildMapList(a1: (int)_LoggingSystem_RegisterLoggingListener);
  BuildMinidumpComment(pchSysErrorText: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5E50
// Name: void Sys_ShutdownGame(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_ShutdownGame()
{
  TraceShutdown(s: "Sys_ShutdownAuthentication()", listnum: 0);
  TraceShutdown(s: "Host_Shutdown()", listnum: 0);
  Host_Shutdown();
  TraceShutdown(s: "Sys_ShutdownMemory()", listnum: 0);
  host_parms.memsize = 0;
  TraceShutdown(s: "Sys_Shutdown()", listnum: 0);
  ConVar::RemoveChangeCallback(
    this: &developer,
    callback: (void (__cdecl *)(IConVar *, const char *, float))DeveloperChangeCallback);
  _LoggingSystem_PopLoggingState(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E5EB0
// Name: LoadThisDll
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadThisDll(char *szDllFilename)
{
  struct CSysModule *pDLL; // [esp+4h] [ebp-4h]

  pDLL = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: szDllFilename, a3: "GAMEBIN", a4: 0);
  if ( pDLL == nullptr )
  {
    ConMsg(a1: "Failed to load %s\n", szDllFilename);
IgnoreThisDLL:
    if ( pDLL != nullptr )
    {
      g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: pDLL);
      serverGameDLL = nullptr;
      serverGameEnts = nullptr;
      serverGameClients = nullptr;
    }
    return 0;
  }
  g_ServerFactory = Sys_GetFactory(pModule: pDLL);
  if ( g_ServerFactory == nullptr )
  {
    ConMsg(a1: "Could not find factory interface in library %s", szDllFilename);
    goto IgnoreThisDLL;
  }
  g_bServerGameDLLGreaterThanV5 = true;
  serverGameDLL = (IServerGameDLL *)g_ServerFactory(a1: "ServerGameDLL005", a2: nullptr);
  if ( serverGameDLL == nullptr )
  {
    _Msg(a1: "Could not get IServerGameDLL interface from library %s", szDllFilename);
    goto IgnoreThisDLL;
  }
  serverGameEnts = (IServerGameEnts *)g_ServerFactory(a1: "ServerGameEnts001", a2: nullptr);
  if ( serverGameEnts == nullptr )
  {
    ConMsg(a1: "Could not get IServerGameEnts interface from library %s", szDllFilename);
    goto IgnoreThisDLL;
  }
  serverGameClients = (IServerGameClients *)g_ServerFactory(a1: "ServerGameClients004", a2: nullptr);
  if ( serverGameClients != nullptr )
  {
    g_iServerGameClientsVersion = 4;
  }
  else
  {
    serverGameClients = (IServerGameClients *)g_ServerFactory(a1: "ServerGameClients003", a2: nullptr);
    if ( serverGameClients == nullptr )
    {
      ConMsg(a1: "Could not get IServerGameClients interface from library %s", szDllFilename);
      goto IgnoreThisDLL;
    }
    g_iServerGameClientsVersion = 3;
  }
  serverGameDirector = (IHLTVDirector *)g_ServerFactory(a1: "HLTVDirector001", a2: nullptr);
  if ( serverGameDirector == nullptr )
    ConMsg(a1: "Could not get IHLTVDirector interface from library %s", szDllFilename);
  serverReplayDirector = (IReplayDirector *)g_ServerFactory(a1: "ReplayDirector001", a2: nullptr);
  if ( serverReplayDirector == nullptr )
    ConMsg(a1: "Could not get IReplayDirector interface from library %s", szDllFilename);
  serverGameTags = (IServerGameTags *)g_ServerFactory(a1: "ServerGameTags001", a2: nullptr);
  g_GameDLL = pDLL;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E6100
// Name: void LoadEntityDLLs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadEntityDLLs()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi
  IBaseFileSystem *v2; // eax
  const char *String; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  char szDllFilename[260]; // [esp+4h] [ebp-104h] BYREF

  memset(dst: (unsigned __int8 *)&gmodinfo, value: 0, count: sizeof(gmodinfo));
  gmodinfo.version = 1;
  gmodinfo.svonly = true;
  g_GameDLL = nullptr;
  sv_noclipduringpause = nullptr;
  v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v0 != nullptr )
    v1 = KeyValues::KeyValues(this: v0, setName: "modinfo");
  else
    v1 = nullptr;
  if ( g_pFileSystem != nullptr )
    v2 = &g_pFileSystem->IBaseFileSystem;
  else
    v2 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v1,
         filesystem: v2,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v1, keyName: "url_info", defaultValue: defaultValue);
    V_strncpy(pDest: gmodinfo.szInfo, pSrc: String, maxLen: 256);
    v4 = KeyValues::GetString(this: v1, keyName: "url_dl", defaultValue: defaultValue);
    V_strncpy(pDest: gmodinfo.szDL, pSrc: v4, maxLen: 256);
    gmodinfo.version = KeyValues::GetInt(this: v1, keyName: "version", defaultValue: 0);
    gmodinfo.size = KeyValues::GetInt(this: v1, keyName: "size", defaultValue: 0);
    gmodinfo.svonly = KeyValues::GetInt(this: v1, keyName: "svonly", defaultValue: 0) != 0;
    gmodinfo.cldll = KeyValues::GetInt(this: v1, keyName: "cldll", defaultValue: 0) != 0;
    v5 = KeyValues::GetString(this: v1, keyName: "hlversion", defaultValue: defaultValue);
    V_strncpy(pDest: gmodinfo.szHLVersion, pSrc: v5, maxLen: 32);
  }
  KeyValues::deleteThis(this: v1);
  V_snprintf(pDest: szDllFilename, maxLen: 260, pFormat: "server.dll");
  LoadThisDll(szDllFilename);
  if ( serverGameDLL != nullptr )
  {
    v6 = serverGameDLL->GetGameDescription(this: serverGameDLL);
    _Msg(a1: "Game.dll loaded for \"%s\"\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6390
// Name: void Sys_SetRegKeyValueUnderRoot(struct HKEY__ __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SetRegKeyValueUnderRoot(
        HKEY__ *rootKey,
        const char *pszSubKey,
        const char *pszElement,
        const char *pszValue)
{
  DWORD v4; // [esp-8h] [ebp-10h]
  unsigned int dwDisposition; // [esp+0h] [ebp-8h] BYREF
  HKEY__ *hKey; // [esp+4h] [ebp-4h] BYREF

  if ( RegCreateKeyExA(
         hKey: rootKey,
         lpSubKey: pszSubKey,
         Reserved: 0,
         lpClass: (LPSTR)"String",
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &hKey,
         lpdwDisposition: &dwDisposition) == 0 )
  {
    v4 = _V_strlen(str: pszValue) + 1;
    RegSetValueExA(hKey, lpValueName: pszElement, Reserved: 0, dwType: 1u, lpData: (const BYTE *)pszValue, cbData: v4);
    RegCloseKey(hKey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6440
// Name: void Sys_SetRegKeyValue(char __near *,char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SetRegKeyValue(char *pszSubKey, char *pszElement, const char *pszValue)
{
  Sys_SetRegKeyValueUnderRoot(rootKey: (HKEY__ *)0x80000001, pszSubKey, pszElement, pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x101E6460
// Name: void Sys_CreateFileAssociations(int,struct FileAssociationInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_CreateFileAssociations(int count, FileAssociationInfo *list)
{
  const char *v2; // eax
  const char *v3; // eax
  int i; // esi
  const char *extension; // eax
  char quoted_appname_with_arg[512]; // [esp+8h] [ebp-520h] BYREF
  char appname[512]; // [esp+208h] [ebp-320h] BYREF
  char base_exe_name[256]; // [esp+408h] [ebp-120h] BYREF
  char binding[32]; // [esp+508h] [ebp-20h] BYREF

  GetModuleFileNameA(hModule: nullptr, lpFilename: appname, nSize: 0x200u);
  V_FixSlashes(pname: appname, separator: 92);
  _V_strlower(start: appname);
  V_snprintf(pDest: quoted_appname_with_arg, maxLen: 512, pFormat: "\"%s\" \"%%1\"", appname);
  V_FileBase(in: appname, out: base_exe_name, maxlen: 256);
  V_DefaultExtension(path: base_exe_name, extension: ".exe", pathStringLength: 256);
  v2 = va(format: "%s\\shell\\open\\command", "Valve.Source");
  Sys_SetRegKeyValueUnderRoot(
    rootKey: (HKEY__ *)0x80000000,
    pszSubKey: v2,
    pszElement: defaultValue,
    pszValue: quoted_appname_with_arg);
  v3 = va(format: "Applications\\%s\\shell\\open\\command", base_exe_name);
  Sys_SetRegKeyValueUnderRoot(
    rootKey: (HKEY__ *)0x80000000,
    pszSubKey: v3,
    pszElement: defaultValue,
    pszValue: quoted_appname_with_arg);
  for ( i = 0; i < count; ++i )
  {
    extension = list[i].extension;
    binding[0] = 0;
    Sys_GetRegKeyValueUnderRoot(
      rootKey: (HKEY__ *)0x80000000,
      pszSubKey: extension,
      pszElement: defaultValue,
      pszReturnString: binding,
      nReturnLength: 32,
      pszDefaultValue: defaultValue);
    if ( _V_strlen(str: binding) == 0 )
      Sys_SetRegKeyValueUnderRoot(
        rootKey: (HKEY__ *)0x80000000,
        pszSubKey: list[i].extension,
        pszElement: defaultValue,
        pszValue: "Valve.Source");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E65B0
// Name: void Sys_NoCrashDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_NoCrashDialog()
{
  UINT v0; // eax

  v0 = SetErrorMode(uMode: 2u);
  SetErrorMode(uMode: v0 | 2);
}

//------------------------------------------------------------------------------
// Address: 0x101E65D0
// Name: void Sys_TestSendKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_TestSendKey(const char *pKey)
{
  WPARAM v1; // edi
  HWND v2; // esi

  v1 = *pKey;
  if ( *pKey == 92 && pKey[1] == 114 )
    v1 = 13;
  v2 = (HWND)game->GetMainWindow(this: game);
  PostMessageA(hWnd: v2, Msg: 0x100u, wParam: v1, lParam: 0);
  PostMessageA(hWnd: v2, Msg: 0x101u, wParam: v1, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6620
// Name: void Sys_OutputDebugString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_OutputDebugString()
{
  _Plat_DebugString();
}

//------------------------------------------------------------------------------
// Address: 0x101E6630
// Name: void UnloadEntityDLLs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnloadEntityDLLs()
{
  if ( g_GameDLL != nullptr )
  {
    FileSystem_UnloadModule(pModule: g_GameDLL);
    g_GameDLL = nullptr;
    serverGameDLL = nullptr;
    serverGameEnts = nullptr;
    serverGameClients = nullptr;
    sv_noclipduringpause = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6670
// Name: star_memory
// Source: json
//------------------------------------------------------------------------------
void __cdecl star_memory()
{
  _MEMORYSTATUS Buffer; // [esp+0h] [ebp-24h] BYREF
  unsigned int dwTotalPhys; // [esp+20h] [ebp-4h]

  GlobalMemoryStatus(lpBuffer: &Buffer);
  dwTotalPhys = Buffer.dwTotalPhys;
  _Msg(
    a1: "Available: %.2f MB, Used: %.2f MB, Free: %.2f MB\n",
    0.00000095367432 * (double)Buffer.dwTotalPhys - 32.0,
    (double)(Buffer.dwTotalPhys - Buffer.dwAvailPhys) * 0.00000095367432 - 32.0,
    (double)Buffer.dwAvailPhys * 0.00000095367432);
}

//------------------------------------------------------------------------------
// Address: 0x101E6700
// Name: warningcallstacks_length_callback
// Source: json
//------------------------------------------------------------------------------
void __cdecl warningcallstacks_length_callback(IConVar *var)
{
  IConVar *v1; // eax
  IConVar_vtbl *v2; // eax

  if ( var != nullptr )
    v1 = var - 6;
  else
    v1 = nullptr;
  v2 = v1[7].__vftable;
  if ( v2 != nullptr )
    __Warning_AlwaysSpewCallStack_Length(a1: v2[1].GetName);
  else
    __Warning_AlwaysSpewCallStack_Length(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6740
// Name: errorcallstacks_length_callback
// Source: json
//------------------------------------------------------------------------------
void __cdecl errorcallstacks_length_callback(IConVar *var)
{
  IConVar *v1; // eax
  IConVar_vtbl *v2; // eax

  if ( var != nullptr )
    v1 = var - 6;
  else
    v1 = nullptr;
  v2 = v1[7].__vftable;
  if ( v2 != nullptr )
    __Error_AlwaysSpewCallStack_Length(a1: v2[1].GetName);
  else
    __Error_AlwaysSpewCallStack_Length(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6780
// Name: char const __near * Sys_FindFirst(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_FindFirst(const char *path, char *basename, int namelength)
{
  const char *v3; // esi

  if ( g_hfind != -1 )
  {
    Sys_Error(error: "Sys_FindFirst without close");
    g_pFileSystem->FindClose(this: g_pFileSystem, a2: g_hfind);
  }
  v3 = g_pFileSystem->FindFirst(this: g_pFileSystem, a2: path, a3: &g_hfind);
  if ( basename != nullptr && v3 != nullptr )
    V_FileBase(in: v3, out: basename, maxlen: namelength);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101E67F0
// Name: char const __near * Sys_FindFirstEx(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_FindFirstEx(const char *pWildcard, const char *pPathID, char *basename, int namelength)
{
  const char *v4; // esi

  if ( g_hfind != -1 )
  {
    Sys_Error(error: "Sys_FindFirst without close");
    g_pFileSystem->FindClose(this: g_pFileSystem, a2: g_hfind);
  }
  v4 = g_pFileSystem->FindFirstEx(this: g_pFileSystem, a2: pWildcard, a3: pPathID, a4: &g_hfind);
  if ( basename != nullptr && v4 != nullptr )
    V_FileBase(in: v4, out: basename, maxlen: namelength);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101E6860
// Name: warningcallstacks_enable_callback
// Source: json
//------------------------------------------------------------------------------
void __cdecl warningcallstacks_enable_callback(IConVar *var)
{
  IConVar *v1; // eax
  IConVar_vtbl *v2; // eax

  if ( var != nullptr )
    v1 = var - 6;
  else
    v1 = nullptr;
  v2 = v1[7].__vftable;
  if ( v2 != nullptr )
    __Warning_AlwaysSpewCallStack_Enable(a1: v2[1].GetName != nullptr);
  else
    __Warning_AlwaysSpewCallStack_Enable(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E68B0
// Name: errorcallstacks_enable_callback
// Source: json
//------------------------------------------------------------------------------
void __cdecl errorcallstacks_enable_callback(IConVar *var)
{
  IConVar *v1; // eax
  IConVar_vtbl *v2; // eax

  if ( var != nullptr )
    v1 = var - 6;
  else
    v1 = nullptr;
  v2 = v1[7].__vftable;
  if ( v2 != nullptr )
    __Error_AlwaysSpewCallStack_Enable(a1: v2[1].GetName != nullptr);
  else
    __Error_AlwaysSpewCallStack_Enable(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6A80
// Name: void GetSpew(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSpew(char *buf, const CUtlString *buflen)
{
  DWORD CurrentThreadId; // ecx
  int m_Previous; // eax
  int v4; // ebx
  UtlLinkedListElem_t<CUtlString,unsigned short> *m_pMemory; // ecx
  unsigned int v6; // esi
  int v7; // edi
  const char *v8; // eax
  CUtlString *rec; // [esp+14h] [ebp+Ch]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_SpewMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_SpewMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_SpewMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_SpewMutex.m_depth;
  }
  LOWORD(m_Previous) = g_SpewHistory.m_Tail;
  v4 = (int)&buflen[-1].m_Storage.m_nActualLength + 3;
  if ( g_SpewHistory.m_Tail != 0xFFFF )
  {
    m_pMemory = g_SpewHistory.m_Memory.m_pMemory;
    do
    {
      v6 = (unsigned __int16)m_Previous;
      rec = &m_pMemory[v6].m_Element;
      v7 = CUtlString::Length(this: &m_pMemory[v6].m_Element);
      if ( v7 >= v4 )
        v7 = v4;
      if ( v7 <= 0 )
        break;
      v8 = CUtlString::operator char const *(this: rec);
      _V_memcpy(dest: buf, src: v8, count: v7);
      buf += v7;
      v4 -= v7;
      if ( v4 <= 0 )
        break;
      m_pMemory = g_SpewHistory.m_Memory.m_pMemory;
      m_Previous = g_SpewHistory.m_Memory.m_pMemory[v6].m_Previous;
    }
    while ( m_Previous != 0xFFFF );
  }
  *buf = 0;
  if ( --g_SpewMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_SpewMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E6DA0
// Name: AddSpewRecord
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl AddSpewRecord(const char *pMsg)
{
  CStatTime *v1; // ecx
  double v2; // st7
  DWORD CurrentThreadId; // ecx
  int m_nValue; // eax
  int v5; // esi
  UtlLinkedListElem_t<CUtlString,unsigned short> *v6; // ecx
  CUtlString string; // [esp+Ch] [ebp-18h] BYREF
  int str; // [esp+1Ch] [ebp-8h] OVERLAPPED

  CUtlString::CUtlString(this: (CUtlString *)&string.m_Storage.m_Memory.m_nAllocationCount);
  v2 = _Plat_FloatTime(this: v1);
  CUtlString::Format(
    this: (CUtlString *)&string.m_Storage.m_Memory.m_nAllocationCount,
    pFormat: "%d(%f):  %s",
    g_nSpewLines,
    v2,
    pMsg);
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_SpewMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_SpewMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_SpewMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_SpewMutex.m_depth;
  }
  ++g_nSpewLines;
  if ( sys_minidumpspewlines.m_pParent != nullptr )
    m_nValue = sys_minidumpspewlines.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_SpewHistory.m_ElementCount > m_nValue )
    CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::Remove(
      this: &g_SpewHistory,
      elem: g_SpewHistory.m_Head);
  v5 = (unsigned __int16)CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::AllocInternal(
                           this: &g_SpewHistory,
                           multilist: false);
  if ( (_WORD)v5 != 0xFFFF )
  {
    CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::LinkBefore(
      this: &g_SpewHistory,
      before: 0xFFFFu,
      elem: v5);
    v6 = &g_SpewHistory.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
      CUtlString::CUtlString(
        this: &v6->m_Element,
        string: (const CUtlString *)&string.m_Storage.m_Memory.m_nAllocationCount);
  }
  if ( --g_SpewMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_SpewMutex, 0);
  str = 0;
  if ( string.m_Storage.m_nActualLength >= 0 && string.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)string.m_Storage.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x101E6ED0
// Name: public: virtual void CEngineConsoleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineConsoleLoggingListener::Log(
        CEngineConsoleLoggingListener *this,
        const LoggingContext_t *pContext,
        Color pMessage)
{
  bool v3; // bl
  const char *v4; // esi
  LoggingSeverity_t m_Severity; // eax
  const char *m_Color; // ecx

  if ( (pContext->m_Flags & 2) != 0 )
  {
    if ( pContext->m_ChannelID == LOG_SERVER_LOG )
      CLog::Print(this: &g_Log, text: *(const char **)&pMessage);
  }
  else
  {
    v3 = GenericThreadLocals::CThreadLocalBase::Get(this: &g_bInSpew) != nullptr;
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_bInSpew, a2: (void *)1);
    v4 = (const char *)pMessage;
    AddSpewRecord(pMsg: *(const char **)&pMessage);
    if ( !v3 )
    {
      if ( dedicated != nullptr && g_nForkID <= 0 )
        ((void (__stdcall *)(const char *))dedicated->Sys_Printf)(a1: v4);
      if ( g_bTextMode )
        printf(format: "%s", v4);
      m_Severity = pContext->m_Severity;
      m_Color = (const char *)pContext->m_Color;
      pMessage = (Color)m_Color;
      switch ( m_Severity )
      {
        case LS_MESSAGE:
          if ( m_Color == *(const char **)&UNSPECIFIED_LOGGING_COLOR_146 )
            pMessage = (Color)-1;
          break;
        case LS_WARNING:
          pMessage = (Color)-10855681;
          break;
        case LS_ASSERT:
          pMessage = (Color)-15461121;
          break;
        case LS_ERROR:
          pMessage = (Color)-47596;
          break;
        default:
          break;
      }
      Con_ColorPrintf(clr: &pMessage, fmt: "%s", v4);
    }
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_bInSpew, a2: nullptr);
    if ( pContext->m_Severity == LS_ERROR )
      Sys_Error(error: "%s", v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031DF20
// Name: _dynamic_initializer_for__sys_minidumpspewlines__
// Source: semantic_dyn_pfx_sys
//------------------------------------------------------------------------------
int dynamic_initializer_for__sys_minidumpspewlines__()
{
  ConVar::ConVar(
    this: &sys_minidumpspewlines,
    pName: "sys_minidumpspewlines",
    pDefaultValue: "500",
    flags: 0x80000,
    pHelpString: "Lines of crash dump console spew to keep.");
  return atexit(func: dynamic_atexit_destructor_for__sys_minidumpspewlines__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E1A0
// Name: _dynamic_initializer_for__sys_minidumpexpandedspew__
// Source: semantic_dyn_pfx_sys
//------------------------------------------------------------------------------
int dynamic_initializer_for__sys_minidumpexpandedspew__()
{
  ConVar::ConVar(this: &sys_minidumpexpandedspew, pName: "sys_minidumpexpandedspew", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sys_minidumpexpandedspew__);
}

//------------------------------------------------------------------------------
// Address: 0x10326B60
// Name: _dynamic_atexit_destructor_for__sys_minidumpspewlines__
// Source: semantic_dyn_pfx_sys
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sys_minidumpspewlines__()
{
  ConVar::~ConVar(this: &sys_minidumpspewlines);
}

//------------------------------------------------------------------------------
// Address: 0x101E5C10
// Name: __CreateCFileLoggingListenerIFileLoggingListener_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFileLoggingListener *__cdecl _CreateCFileLoggingListenerIFileLoggingListener_interface()
{
  return &s_FileLoggingListener;
}

//------------------------------------------------------------------------------
// Address: 0x101E6FF0
// Name: void F(class IEngineAPI __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl F(IEngineAPI **api)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  *api = (IEngineAPI *)FactoryThis(a1: "VENGINE_LAUNCHER_API_VERSION004", a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1031DF50
// Name: _dynamic_initializer_for__g_SpewHistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SpewHistory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SpewHistory__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DF60
// Name: _dynamic_initializer_for__g_SpewMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SpewMutex__()
{
  g_SpewMutex.m_ownerID = 0;
  g_SpewMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1031E1D0
// Name: _dynamic_initializer_for__errorText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__errorText__()
{
  errorText.m_errorText = (char *)MemAlloc_Alloc(nSize: 0x17318u);
  _V_memset(dest: errorText.m_errorText, fill: 0, count: errorText.m_Size);
  return atexit(func: dynamic_atexit_destructor_for__errorText__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E220
// Name: _dynamic_initializer_for__g_sProductString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_sProductString__()
{
  CUtlString::CUtlString(this: &g_sProductString);
  return atexit(func: dynamic_atexit_destructor_for__g_sProductString__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E240
// Name: _dynamic_initializer_for____g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg,
           fn: _CreateCDedicatedServerAPIIDedicatedServerAPI_interface,
           pName: "VENGINE_HLDS_API_VERSION002");
}

//------------------------------------------------------------------------------
// Address: 0x1031E260
// Name: _dynamic_initializer_for____g_CreateCGameUIFuncsIGameUIFuncs_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCGameUIFuncsIGameUIFuncs_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCGameUIFuncsIGameUIFuncs_reg,
           fn: _CreateCGameUIFuncsIGameUIFuncs_interface,
           pName: "VENGINE_GAMEUIFUNCS_VERSION005");
}

//------------------------------------------------------------------------------
// Address: 0x1031E280
// Name: _dynamic_initializer_for__fps_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fps_max__()
{
  ConVar::ConVar(this: &fps_max, pName: "fps_max", pDefaultValue: "300", flags: 0, pHelpString: "Frame rate limiter");
  return atexit(func: dynamic_atexit_destructor_for__fps_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E2B0
// Name: _dynamic_initializer_for__fps_max_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fps_max_splitscreen__()
{
  ConVar::ConVar(
    this: &fps_max_splitscreen,
    pName: "fps_max_splitscreen",
    pDefaultValue: "300",
    flags: 0,
    pHelpString: "Frame rate limiter, splitscreen");
  return atexit(func: dynamic_atexit_destructor_for__fps_max_splitscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E2E0
// Name: _dynamic_initializer_for__async_serialize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_serialize__()
{
  ConVar::ConVar(
    this: &async_serialize,
    pName: "async_serialize",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Force async reads to serialize for profiling");
  return atexit(func: dynamic_atexit_destructor_for__async_serialize__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E310
// Name: _dynamic_initializer_for__vx_do_not_throttle_events__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vx_do_not_throttle_events__()
{
  ConVar::ConVar(
    this: &vx_do_not_throttle_events,
    pName: "vx_do_not_throttle_events",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Force VXConsole updates every frame; smoother vprof data on PS3 but at a slight (~0.2ms) perf cost.");
  return atexit(func: dynamic_atexit_destructor_for__vx_do_not_throttle_events__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E340
// Name: _dynamic_initializer_for__g_Engine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Engine__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Engine__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E350
// Name: _dynamic_initializer_for__g_Game__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Game__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Game__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E360
// Name: _dynamic_initializer_for__g_GameMessageHandlers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__thiscall *dynamic_initializer_for__g_GameMessageHandlers__())(CGame *this, const InputEvent_t *event)
{
  dword_10422B40[0] = (int)CGame::HandleMsg_ActivateApp;
  dword_10422B58 = (int)CGame::HandleMsg_WindowMove;
  dword_10422B70 = (int)CGame::HandleMsg_Close;
  dword_10422B4C = 0;
  dword_10422B64 = 0;
  dword_10422B7C = 0;
  dword_10422B94 = 0;
  dword_10422B44[0] = 0;
  dword_10422B48 = 0;
  dword_10422B5C = 0;
  dword_10422B60 = 0;
  dword_10422B74 = 0;
  dword_10422B78 = 0;
  dword_10422B88 = (int)CGame::HandleMsg_Close;
  dword_10422B8C = 0;
  dword_10422B90 = 0;
  return CGame::HandleMsg_Close;
}

//------------------------------------------------------------------------------
// Address: 0x1031E3E0
// Name: _dynamic_initializer_for__g_TestScriptMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TestScriptMgr__()
{
  CTestScriptMgr::CTestScriptMgr(this: &g_TestScriptMgr);
  return atexit(func: dynamic_atexit_destructor_for__g_TestScriptMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10326D00
// Name: _dynamic_atexit_destructor_for__g_sProductString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_sProductString__()
{
  g_sProductString.m_Storage.m_nActualLength = 0;
  if ( g_sProductString.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_sProductString.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_sProductString.m_Storage.m_Memory.m_pMemory);
      g_sProductString.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    g_sProductString.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326D80
// Name: _dynamic_atexit_destructor_for__g_TextModeLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TextModeLine__()
{
  char *m_pMemory; // eax

  m_pMemory = g_TextModeLine.m_Memory.m_pMemory;
  g_TextModeLine.m_Size = 0;
  if ( g_TextModeLine.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_TextModeLine.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_TextModeLine.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_TextModeLine.m_Memory.m_pMemory = nullptr;
    }
    g_TextModeLine.m_Memory.m_nAllocationCount = 0;
  }
  g_TextModeLine.m_pElements = m_pMemory;
  if ( g_TextModeLine.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_TextModeLine.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_TextModeLine.m_Memory.m_pMemory);
      g_TextModeLine.m_Memory.m_pMemory = nullptr;
    }
    g_TextModeLine.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326E20
// Name: _dynamic_atexit_destructor_for__fps_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fps_max__()
{
  ConVar::~ConVar(this: &fps_max);
}

//------------------------------------------------------------------------------
// Address: 0x10326E30
// Name: _dynamic_atexit_destructor_for__fps_max_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fps_max_splitscreen__()
{
  ConVar::~ConVar(this: &fps_max_splitscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10326E40
// Name: _dynamic_atexit_destructor_for__async_serialize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_serialize__()
{
  ConVar::~ConVar(this: &async_serialize);
}

//------------------------------------------------------------------------------
// Address: 0x10326E50
// Name: _dynamic_atexit_destructor_for__vx_do_not_throttle_events__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vx_do_not_throttle_events__()
{
  ConVar::~ConVar(this: &vx_do_not_throttle_events);
}

//------------------------------------------------------------------------------
// Address: 0x10326E60
// Name: _dynamic_atexit_destructor_for__g_Engine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Engine__()
{
  g_Engine.__vftable = (CEngine_vtbl *)&IEngine::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10326E70
// Name: _dynamic_atexit_destructor_for__g_Game__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Game__()
{
  g_Game.__vftable = (CGame_vtbl *)&IGame::`vftable';
}

} // namespace engine_xlsp
