// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: launcher/launcher.cpp
// Functions: 35
// ============================================================

#include "launcher\launcher.h"

//------------------------------------------------------------------------------
// Address: 0x10002410
// Name: char const __near * GetExecutableFilename(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetExecutableFilename()
{
  HMODULE ModuleHandleA; // eax
  char exepath[260]; // [esp+0h] [ebp-104h] BYREF

  filename[0] = 0;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: exepath, nSize: 0x104u) != 0 )
    _splitpath(path: exepath, drive: nullptr, dir: nullptr, fname: filename, ext: nullptr);
  _V_strlower(start: filename);
  return filename;
}

//------------------------------------------------------------------------------
// Address: 0x10002470
// Name: void UTIL_ComputeBaseDir(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ComputeBaseDir()
{
  HMODULE ModuleHandleA; // eax
  _BYTE *v1; // eax
  int v2; // eax
  char v3; // cl
  int v4; // eax
  int v5; // eax
  char *v6; // edx
  char v7; // cl

  g_szBasedir[0] = 0;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: g_szBasedir, nSize: 0x104u) != 0 )
  {
    strrchr(string: (unsigned __int8 *)g_szBasedir, chr: 0x5Cu);
    if ( *v1 != 0 )
      v1[1] = 0;
    v2 = strlen(g_szBasedir);
    if ( v2 > 0 )
    {
      v3 = *((_BYTE *)&g_pEngineAPI + v2 + 3);
      if ( v3 == 92 || v3 == 47 )
        *((_BYTE *)&g_pEngineAPI + v2 + 3) = 0;
    }
  }
  v4 = _CommandLine();
  v5 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-basedir", a3: 0);
  if ( v5 != 0 )
  {
    v6 = &g_szBasedir[-v5];
    do
    {
      v7 = *(_BYTE *)v5;
      v6[v5] = *(_BYTE *)v5;
      ++v5;
    }
    while ( v7 != 0 );
  }
  _V_strlower(start: g_szBasedir);
  V_FixSlashes(pname: g_szBasedir, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x10002530
// Name: int MyHandlerRoutine(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall MyHandlerRoutine(unsigned int dwCtrlType)
{
  HANDLE CurrentProcess; // eax

  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 2u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002550
// Name: void InitTextMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitTextMode()
{
  _iobuf *v0; // eax
  _iobuf *v1; // eax
  _iobuf *v2; // eax

  AllocConsole();
  SetConsoleCtrlHandler(HandlerRoutine: MyHandlerRoutine, Add: true);
  v0 = __iob_func();
  freopen(filename: "CONIN$", mode: "rb", str: v0);
  v1 = __iob_func();
  freopen(filename: "CONOUT$", mode: "wb", str: v1 + 1);
  v2 = __iob_func();
  freopen(filename: "CONOUT$", mode: "wb", str: v2 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100025B0
// Name: public: virtual bool CSourceAppSystemGroup::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSourceAppSystemGroup::Create(CSourceAppSystemGroup *this)
{
  void *System; // eax
  int v3; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int Module; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  void *v13; // ebx
  IEngineAPI *v14; // eax
  bool v15; // zf
  int v16; // eax
  const char *v17; // esi
  int v18; // eax
  int v19; // eax
  double v20; // st7
  double start; // [esp+44h] [ebp-9Ch]
  AppSystemInfo_t appSystems[18]; // [esp+4Ch] [ebp-94h] BYREF
  const char *pArg; // [esp+DCh] [ebp-4h] BYREF

  _COM_TimestampedLog(a1: "CSourceAppSystemGroup::Create()");
  start = _Plat_FloatTime();
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VFileSystem017");
  (*(void (__thiscall **)(void *, void (__cdecl *)(void *(__cdecl **)(const char *, int *), int)))(*(_DWORD *)System
                                                                                                 + 408))(
    a1: System,
    a2: CSteamApplication::PostShutdown);
  CoInitialize(pvReserved: nullptr);
  v3 = _CommandLine();
  this->m_bEditMode = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(
                        a1: v3,
                        a2: "-edit",
                        a3: 0) != 0;
  appSystems[0].m_pModuleName = "engine.dll";
  appSystems[16].m_pModuleName = "engine.dll";
  appSystems[11].m_pModuleName = "valve_avi.dll";
  appSystems[12].m_pModuleName = "valve_avi.dll";
  appSystems[4].m_pModuleName = "materialsystem.dll";
  appSystems[15].m_pModuleName = "materialsystem.dll";
  appSystems[0].m_pInterfaceName = "VCvarQuery001";
  appSystems[1].m_pModuleName = "filesystem_stdio.dll";
  appSystems[1].m_pInterfaceName = "QueuedLoaderVersion001";
  appSystems[2].m_pModuleName = "inputsystem.dll";
  appSystems[2].m_pInterfaceName = "InputSystemVersion001";
  appSystems[3].m_pModuleName = "vphysics.dll";
  appSystems[3].m_pInterfaceName = "VPhysics031";
  appSystems[4].m_pInterfaceName = "VMaterialSystem080";
  appSystems[5].m_pModuleName = "datacache.dll";
  appSystems[5].m_pInterfaceName = "VDataCache003";
  appSystems[6].m_pModuleName = "datacache.dll";
  appSystems[6].m_pInterfaceName = "MDLCache004";
  appSystems[7].m_pModuleName = "datacache.dll";
  appSystems[7].m_pInterfaceName = "VStudioDataCache005";
  appSystems[8].m_pModuleName = "studiorender.dll";
  appSystems[8].m_pInterfaceName = "VStudioRender026";
  appSystems[9].m_pModuleName = "soundemittersystem.dll";
  appSystems[9].m_pInterfaceName = "VSoundEmitter003";
  appSystems[10].m_pModuleName = "vscript.dll";
  appSystems[10].m_pInterfaceName = "VScriptManager009";
  appSystems[11].m_pInterfaceName = "VAvi001";
  appSystems[12].m_pInterfaceName = "VBik001";
  appSystems[13].m_pModuleName = "vguimatsurface.dll";
  appSystems[13].m_pInterfaceName = "VGUI_Surface031";
  appSystems[14].m_pModuleName = "vgui2.dll";
  appSystems[14].m_pInterfaceName = "VGUI_ivgui008";
  appSystems[15].m_pInterfaceName = "ScaleformUI001";
  appSystems[16].m_pInterfaceName = "VENGINE_LAUNCHER_API_VERSION004";
  appSystems[17].m_pModuleName = str;
  appSystems[17].m_pInterfaceName = str;
  if ( !CAppSystemGroup::AddSystems(this, pSystemList: appSystems) )
    return 0;
  if ( (v5 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-tools") != 0)
    && (v6 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-nop4") == 0)
    || (v7 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-p4") != 0) )
  {
    Module = CAppSystemGroup::LoadModule(this, pDLLName: "p4lib.dll");
    if ( CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VP4002") == nullptr )
    {
      v9 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 40))(a1: v9, a2: "-steam") == 0 )
        return 0;
    }
  }
  v10 = CAppSystemGroup::LoadModule(this, pDLLName: "vstdlib.dll");
  if ( CAppSystemGroup::AddSystem(this, module: v10, pInterfaceName: "VProcessUtils002") == nullptr )
    return 0;
  v11 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: "-dev") != 0 )
  {
    v12 = CAppSystemGroup::LoadModule(this, pDLLName: "datacache.dll");
    if ( CAppSystemGroup::AddSystem(this, module: v12, pInterfaceName: "VResourceAccessControl001") == nullptr )
      return 0;
  }
  v13 = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( v13 == nullptr )
    return 0;
  v14 = (IEngineAPI *)CAppSystemGroup::FindSystem(this, pSystemName: "VENGINE_LAUNCHER_API_VERSION004");
  v15 = !this->m_bEditMode;
  g_pEngineAPI = v14;
  if ( !v15 )
  {
    v16 = CAppSystemGroup::LoadModule(this, pDLLName: "hammer_dll.dll");
    g_pHammer = (IHammer *)CAppSystemGroup::AddSystem(this, module: v16, pInterfaceName: "Hammer001");
    if ( g_pHammer == nullptr )
      return 0;
  }
  v17 = "shaderapidx9.dll";
  pArg = nullptr;
  v18 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v18 + 40))(a1: v18, a2: "-noshaderapi") != 0 )
    v17 = "shaderapiempty.dll";
  v19 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v19 + 12))(
         a1: v19,
         a2: "-shaderapi",
         a3: &pArg) != 0 )
    v17 = pArg;
  (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v13 + 36))(a1: v13, a2: v17);
  v20 = _Plat_FloatTime();
  _COM_TimestampedLog(
    a1: "CSourceAppSystemGroup::Create() - Took %.4f secs to load libraries and get factories.",
    v20 - start);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100028C0
// Name: public: virtual int CSourceAppSystemGroup::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSourceAppSystemGroup::Main(CSourceAppSystemGroup *this)
{
  return g_pEngineAPI->Run(this: g_pEngineAPI);
}

//------------------------------------------------------------------------------
// Address: 0x100028D0
// Name: public: virtual void CSourceAppSystemGroup::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSourceAppSystemGroup::Destroy(CSourceAppSystemGroup *this)
{
  g_pEngineAPI = nullptr;
  g_pMaterialSystem = nullptr;
  g_pHammer = nullptr;
  g_pVJobs = nullptr;
  CoUninitialize();
}

//------------------------------------------------------------------------------
// Address: 0x100028F0
// Name: private: char const __near * CSourceAppSystemGroup::DetermineDefaultMod(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSourceAppSystemGroup::DetermineDefaultMod(CSourceAppSystemGroup *this)
{
  int v1; // eax

  if ( this->m_bEditMode )
    return g_pHammer->GetDefaultMod(this: g_pHammer);
  v1 = _CommandLine();
  return (*(const char *(__thiscall **)(int, const char *, const char *))(*(_DWORD *)v1 + 32))(
           a1: v1,
           a2: "-game",
           a3: "hl2");
}

//------------------------------------------------------------------------------
// Address: 0x10002920
// Name: private: char const __near * CSourceAppSystemGroup::DetermineDefaultGame(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSourceAppSystemGroup::DetermineDefaultGame(CSourceAppSystemGroup *this)
{
  int v1; // eax

  if ( this->m_bEditMode )
    return g_pHammer->GetDefaultGame(this: g_pHammer);
  v1 = _CommandLine();
  return (*(const char *(__thiscall **)(int, const char *, const char *))(*(_DWORD *)v1 + 32))(
           a1: v1,
           a2: "-defaultgamedir",
           a3: "hl2");
}

//------------------------------------------------------------------------------
// Address: 0x10002950
// Name: bool GrabSourceMutex(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GrabSourceMutex()
{
  DWORD v0; // eax

  g_hMutex = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: "hl2_singleton_mutex");
  v0 = WaitForSingleObject(hHandle: g_hMutex, dwMilliseconds: 0);
  if ( v0 == 0 || v0 == 128 )
    return true;
  CloseHandle(hObject: g_hMutex);
  return getenv(option: "VPROJECT") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100029A0
// Name: void RemoveSpuriousGameParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveSpuriousGameParameters()
{
  int v0; // ebx
  const char *v1; // esi
  int v2; // eax
  int v3; // eax
  const char *v4; // eax
  int v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  char lastGameArg[260]; // [esp+Ch] [ebp-104h] BYREF

  v0 = 0;
  v1 = nullptr;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 36))(a1: v2) - 1 > 0 )
  {
    do
    {
      v3 = _CommandLine();
      v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 44))(a1: v3);
      if ( _V_stricmp(s1: v4, s2: v1) == 0 )
      {
        v5 = _CommandLine();
        v6 = (const char *)(*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 44))(a1: v5, a2: ++v1);
        V_snprintf(pDest: lastGameArg, maxLen: 260, pFormat: "\"%s\"", v6);
        ++v0;
      }
      ++v1;
      v7 = _CommandLine();
    }
    while ( (int)v1 < (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 36))(a1: v7) - 1 );
    if ( v0 > 1 )
    {
      v8 = _CommandLine();
      (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 16))(a1: v8, a2: "-game");
      v9 = _CommandLine();
      (*(void (__thiscall **)(int, const char *, char *))(*(_DWORD *)v9 + 20))(a1: v9, a2: "-game", a3: lastGameArg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002A60
// Name: public: virtual void CLauncherLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLauncherLoggingListener::Log(
        CLauncherLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  LoggingSeverity_t m_Severity; // eax

  m_Severity = pContext->m_Severity;
  if ( m_Severity == LS_WARNING
    && (this = (CLauncherLoggingListener *)pContext->m_ChannelID, pContext->m_ChannelID == LOG_EngineInitialization) )
  {
    MessageBoxA(hWnd: nullptr, lpText: pMessage, lpCaption: "Warning!", uType: 0x1010u);
  }
  else if ( m_Severity != LS_ASSERT || (unsigned __int8)_ShouldUseNewAssertDialog(a1: this) != 0 )
  {
    if ( pContext->m_Severity == LS_ERROR )
      MessageBoxA(hWnd: nullptr, lpText: pMessage, lpCaption: "Error!", uType: 0x1010u);
  }
  else
  {
    MessageBoxA(hWnd: nullptr, lpText: pMessage, lpCaption: "Assert!", uType: 0x1010u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002AE0
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10002B80
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10002C40
// Name: private: void CLogAllFiles::LogToAllReslist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogAllFiles::LogToAllReslist(CLogAllFiles *this, const char *line)
{
  const char *v3; // edi
  const char *v4; // eax
  CFmtStrN<256> *v5; // eax
  void *v6; // esi
  IBaseFileSystem_vtbl *v7; // edi
  int v8; // eax
  CFmtStrN<256> v9; // [esp+8h] [ebp-10Ch] BYREF

  v3 = CUtlString::operator char const *(this: &this->m_sResListDir);
  v4 = CUtlString::operator char const *(this: &this->m_sFullGamePath);
  v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "%s\\%s\\%s", v4, v3, "all.lst");
  v6 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5->m_szBuf, a3: "at", a4: "GAME");
  if ( v6 != nullptr )
  {
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: "\"", a3: 1, a4: v6);
    v7 = g_pFullFileSystem->IBaseFileSystem::__vftable;
    v8 = _V_strlen(str: line);
    v7->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: line, a3: v8, a4: v6);
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: v6);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D20
// Name: Cmd_TranslateFileAssociation
// Source: json
//------------------------------------------------------------------------------
char *__usercall Cmd_TranslateFileAssociation@<eax>(const char *param@<eax>)
{
  char *result; // eax
  const char *v2; // ebx
  FileAssociationInfo *v3; // esi
  int v4; // edi
  CFmtStrN<256> *v5; // eax
  CFmtStrN<256> v6; // [esp+4h] [ebp-310h] BYREF
  char temp[512]; // [esp+110h] [ebp-204h] BYREF
  char *retval; // [esp+310h] [ebp-4h]

  retval = nullptr;
  V_strncpy(pDest: temp, pSrc: param, maxLen: 512);
  V_FixSlashes(pname: temp, separator: 92);
  _V_strlower(start: temp);
  result = (char *)V_GetFileExtension(path: temp);
  if ( result != nullptr )
  {
    v2 = result - 1;
    v3 = g_FileAssociations;
    while ( 1 )
    {
      if ( _V_strcmp(s1: v2, s2: v3->extension) == 0 )
      {
        v4 = _CommandLine();
        v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v6, pszFormat: "+%s", v3->command_to_issue);
        if ( (*(int (__thiscall **)(int, char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: v5->m_szBuf) == 0 )
          break;
      }
      if ( (int)++v3 >= (int)&g_LauncherLoggingListener )
        return retval;
    }
    V_strncpy(pDest: sz, pSrc: temp, maxLen: 512);
    V_FileBase(in: sz, out: temp, maxlen: 512);
    V_snprintf(pDest: sz, maxLen: 512, pFormat: "%s %s", v3->command_to_issue, temp);
    return sz;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002E40
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100036D0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003720
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003780
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100037C0
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004110
// Name: BuildCommand
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl BuildCommand()
{
  int v0; // edi
  int v1; // eax
  int v2; // eax
  _BYTE *v3; // eax
  _BYTE *v4; // esi
  char v5; // al
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  const char *v9; // esi
  CFmtStrN<256> *v10; // eax
  int v11; // eax
  const char *v12; // eax
  char *v13; // eax
  int v14; // eax
  bool v15; // zf
  const char *result; // eax
  CFmtStrN<256> v17; // [esp+0h] [ebp-10Ch] BYREF

  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    CUtlBuffer::CUtlBuffer(this: &build, growSize: 0, initSize: 0, nFlags: 1);
    atexit(func: BuildCommand_::_2_::_dynamic_atexit_destructor_for__build__);
  }
  build.m_Get = 0;
  build.m_Put = 0;
  build.m_Error = 0;
  build.m_nOffset = 0;
  build.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &build, nPut: 0);
  v0 = 1;
  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 36))(a1: v1) > 1 )
  {
    do
    {
      v2 = _CommandLine();
      v3 = (_BYTE *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 44))(a1: v2, a2: v0);
      v4 = v3;
      if ( v3 != nullptr )
      {
        v5 = *v3;
        if ( *v4 == 45 )
        {
          v6 = _CommandLine();
          if ( (*(int (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)v6 + 32))(a1: v6, a2: v4, a3: 0) != 0 )
            ++v0;
          goto LABEL_15;
        }
        if ( v5 == 43 )
        {
          v7 = _CommandLine();
          v8 = (const char *)(*(int (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)v7 + 32))(a1: v7, a2: v4, a3: 0);
          v9 = v4 + 1;
          if ( v8 == nullptr )
          {
            CUtlBuffer::PutString(this: &build, pString: v9);
LABEL_14:
            CUtlBuffer::PutChar(this: &build, c: 59);
            goto LABEL_15;
          }
          v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v17, pszFormat: "%s %s;", v9, v8);
          CUtlBuffer::PutString(this: &build, pString: v10->m_szBuf);
          ++v0;
        }
        else
        {
          v11 = _CommandLine();
          v12 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v11 + 44))(a1: v11, a2: v0);
          v13 = Cmd_TranslateFileAssociation(param: v12);
          if ( v13 != nullptr )
          {
            CUtlBuffer::PutString(this: &build, pString: v13);
            goto LABEL_14;
          }
        }
      }
LABEL_15:
      ++v0;
      v14 = _CommandLine();
    }
    while ( v0 < (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 36))(a1: v14) );
  }
  if ( (build.m_Flags & 1) != 0 && build.m_Put != 0 && build.m_Memory.m_pMemory[build.m_Put - build.m_nOffset - 1] == 10 )
    CUtlBuffer::PutTabs(this: &build);
  v15 = !CUtlBuffer::CheckPut(this: &build, nSize: 1);
  result = (const char *)build.m_Memory.m_pMemory;
  if ( !v15 )
  {
    build.m_Memory.m_pMemory[build.m_Put - build.m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: &build, nPut: ++build.m_Put);
    return (const char *)build.m_Memory.m_pMemory;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100043D0
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10004500
// Name: public: CLogAllFiles::~CLogAllFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogAllFiles::~CLogAllFiles(CLogAllFiles *this)
{
  this->m_sFullGamePath.m_Storage.m_nActualLength = 0;
  if ( this->m_sFullGamePath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sFullGamePath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sFullGamePath.m_Storage.m_Memory.m_pMemory);
      this->m_sFullGamePath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sFullGamePath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_sResListDir.m_Storage.m_nActualLength = 0;
  if ( this->m_sResListDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sResListDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sResListDir.m_Storage.m_Memory.m_pMemory);
      this->m_sResListDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sResListDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::~CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>(this: &this->m_Logged);
}

//------------------------------------------------------------------------------
// Address: 0x10004580
// Name: public: CLogAllFiles::CLogAllFiles(void)
// Source: json
//------------------------------------------------------------------------------
CLogAllFiles *__thiscall CLogAllFiles::CLogAllFiles(CLogAllFiles *this)
{
  this->m_bActive = false;
  this->m_Logged.m_LessFunc = AllLogLessFunc;
  this->m_Logged.m_Elements.m_pMemory = nullptr;
  this->m_Logged.m_Elements.m_nAllocationCount = 0;
  this->m_Logged.m_Elements.m_nGrowSize = 0;
  this->m_Logged.m_Root = -1;
  this->m_Logged.m_NumElements = 0;
  this->m_Logged.m_FirstFree = -1;
  this->m_Logged.m_LastAlloc.index = -1;
  this->m_Logged.m_pElements = this->m_Logged.m_Elements.m_pMemory;
  CUtlString::CUtlString(this: &this->m_sResListDir);
  CUtlString::CUtlString(this: &this->m_sFullGamePath);
  CUtlString::operator=(this: &this->m_sResListDir, src: "reslists");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004600
// Name: public: void CLogAllFiles::LogFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogAllFiles::LogFile(CLogAllFiles *this, const char *fullPathFileName, const char *options)
{
  const char *v5; // esi
  int v6; // eax
  char rel[260]; // [esp+4h] [ebp-114h] BYREF
  CUtlString search; // [esp+108h] [ebp-10h] BYREF
  int idx; // [esp+120h] [ebp+8h]

  if ( this->m_bActive )
  {
    CUtlString::CUtlString(this: &search, pString: fullPathFileName);
    idx = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
            this: &this->m_Logged,
            &search);
    search.m_Storage.m_nActualLength = 0;
    if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
    if ( idx == -1 )
    {
      CUtlString::CUtlString(this: &search, pString: fullPathFileName);
      CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Insert(
        this: &this->m_Logged,
        insert: &search);
      search.m_Storage.m_nActualLength = 0;
      if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
      v5 = V_stristr(pStr: fullPathFileName, pSearch: g_szBasedir);
      if ( v5 != nullptr )
      {
        v6 = _V_strlen(str: g_szBasedir);
        V_strncpy(pDest: rel, pSrc: &v5[v6 + 1], maxLen: 260);
        _V_strlower(start: rel);
        V_FixSlashes(pname: rel, separator: 92);
        CLogAllFiles::LogToAllReslist(this, line: rel);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004710
// Name: private: static void CLogAllFiles::LogAllFilesFunc(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CLogAllFiles::LogAllFilesFunc(const char *fullPathFileName, const char *options)
{
  CLogAllFiles::LogFile(this: &g_LogFiles, fullPathFileName, options);
}

//------------------------------------------------------------------------------
// Address: 0x10004730
// Name: public: void CLogAllFiles::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogAllFiles::Init(CLogAllFiles *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  int v8; // eax
  int v9; // eax
  const char *v10; // ebx
  const char *v11; // eax
  CFmtStrN<256> *v12; // eax
  char *m_szCurrentDir; // edi
  const char *v14; // [esp-8h] [ebp-328h]
  char szDir[260]; // [esp+8h] [ebp-318h] BYREF
  char path[260]; // [esp+10Ch] [ebp-214h] BYREF
  CFmtStrN<256> v17; // [esp+210h] [ebp-110h] BYREF
  const char *pszDir; // [esp+31Ch] [ebp-4h] BYREF

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-edit", a3: 0) == 0 )
  {
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-makereslists", a3: 0) != 0 )
    {
      this->m_bActive = true;
      pszDir = nullptr;
      v4 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v4 + 12))(
             a1: v4,
             a2: "-reslistdir",
             a3: &pszDir) != 0
        && pszDir != nullptr )
      {
        V_strncpy(pDest: &v17.m_szBuf[3], pSrc: pszDir, maxLen: 260);
        V_StripTrailingSlash(ppath: &v17.m_szBuf[3]);
        _V_strlower(start: &v17.m_szBuf[3]);
        V_FixSlashes(pname: &v17.m_szBuf[3], separator: 92);
        if ( _V_strlen(str: &v17.m_szBuf[3]) > 0 )
          CUtlString::operator=(this: &this->m_sResListDir, src: &v17.m_szBuf[3]);
      }
      v5 = _CommandLine();
      v6 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v5 + 32))(
                           a1: v5,
                           a2: "-game",
                           a3: "hl2");
      V_snprintf(pDest: path, maxLen: 260, pFormat: "%s/%s", g_szBasedir, v6);
      V_FixSlashes(pname: path, separator: 92);
      _V_strlower(start: path);
      CUtlString::operator=(this: &this->m_sFullGamePath, src: path);
      v14 = CUtlString::operator char const *(this: &this->m_sResListDir);
      v7 = CUtlString::operator char const *(this: &this->m_sFullGamePath);
      V_snprintf(pDest: szDir, maxLen: 260, pFormat: "%s\\%s", v7, v14);
      g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: szDir, a3: "GAME");
      g_pFullFileSystem->AddLoggingFunc(this: g_pFullFileSystem, a2: CLogAllFiles::LogAllFilesFunc);
      v8 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-startmap") == 0 )
      {
        v9 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 40))(a1: v9, a2: "-startstage") == 0 )
        {
          CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &this->m_Logged);
          v10 = CUtlString::operator char const *(this: &this->m_sResListDir);
          v11 = CUtlString::operator char const *(this: &this->m_sFullGamePath);
          v12 = CFmtStrN<256>::CFmtStrN<256>(this: &v17, pszFormat: "%s\\%s\\%s", v11, v10, "all.lst");
          g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: v12->m_szBuf, a3: "GAME");
        }
      }
      m_szCurrentDir = this->m_szCurrentDir;
      GetCurrentDirectoryA(nBufferLength: 0x104u, lpBuffer: m_szCurrentDir);
      V_strncat(pDest: m_szCurrentDir, pSrc: "\\", destBufferSize: 0x104u, max_chars_to_copy: 1);
      strlwr(string: m_szCurrentDir);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004970
// Name: public: void CLogAllFiles::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogAllFiles::Shutdown(CLogAllFiles *this)
{
  int v2; // eax
  const char *v3; // eax
  CFmtStrN<256> *v4; // eax
  const char *v5; // edi
  const char *v6; // eax
  CFmtStrN<256> *v7; // eax
  CFmtStrN<256> v8; // [esp+4h] [ebp-110h] BYREF
  const char *v9; // [esp+110h] [ebp-4h]

  if ( this->m_bActive )
  {
    this->m_bActive = false;
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-makereslists", a3: 0) != 0 )
      g_pFullFileSystem->RemoveLoggingFunc(this: g_pFullFileSystem, a2: CLogAllFiles::LogAllFilesFunc);
    v9 = CUtlString::operator char const *(this: &this->m_sResListDir);
    v3 = CUtlString::operator char const *(this: &this->m_sFullGamePath);
    v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "%s\\%s\\%s", v3, v9, "all.lst");
    SortResList(pchFileName: v4->m_szBuf, pchSearchPath: "GAME");
    v5 = CUtlString::operator char const *(this: &this->m_sResListDir);
    v6 = CUtlString::operator char const *(this: &this->m_sFullGamePath);
    v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "%s\\%s\\%s", v6, v5, "engine.lst");
    SortResList(pchFileName: v7->m_szBuf, pchSearchPath: "GAME");
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &this->m_Logged);
    this->m_Logged.m_FirstFree = -1;
    if ( this->m_Logged.m_Elements.m_nGrowSize >= 0 )
    {
      if ( this->m_Logged.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Logged.m_Elements.m_pMemory);
        this->m_Logged.m_Elements.m_pMemory = nullptr;
      }
      this->m_Logged.m_Elements.m_nAllocationCount = 0;
    }
    this->m_Logged.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004A90
// Name: public: virtual bool CSourceAppSystemGroup::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CSourceAppSystemGroup::PreInit@<al>(CSourceAppSystemGroup *this@<ecx>, int a2@<edi>)
{
  bool v3; // al
  bool v4; // zf
  int v5; // eax
  const char *v6; // eax
  bool m_bEditMode; // al
  int v9; // eax
  IResListGenerator_vtbl *v10; // edi
  int v11; // eax
  CFSSteamSetupInfo steamInfo; // [esp+4h] [ebp-234h] BYREF
  StartupInfo_t info; // [esp+210h] [ebp-28h] BYREF
  CFSMountContentInfo fsInfo; // [esp+228h] [ebp-10h] BYREF
  void *(__cdecl *factory)(const char *, int *); // [esp+234h] [ebp-4h] BYREF

  factory = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  CSteamApplication::PostShutdown(pFactoryList: &factory, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pMaterialSystem == nullptr )
    return false;
  CFSSteamSetupInfo::CFSSteamSetupInfo(this: &steamInfo);
  *(_WORD *)&steamInfo.m_bToolsMode = 0;
  v3 = g_pFullFileSystem->IsSteam(this: g_pFullFileSystem);
  v4 = !this->m_bEditMode;
  steamInfo.m_bSteam = v3;
  steamInfo.m_bOnlyUseDirectoryName = true;
  if ( v4 )
  {
    v5 = _CommandLine();
    v6 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v5 + 32))(
                         a1: v5,
                         a2: "-game",
                         a3: "hl2");
  }
  else
  {
    v6 = g_pHammer->GetDefaultMod(this: g_pHammer);
  }
  steamInfo.m_pDirectoryName = v6;
  if ( v6 == nullptr )
  {
    steamInfo.m_pDirectoryName = CSourceAppSystemGroup::DetermineDefaultGame(this);
    if ( steamInfo.m_pDirectoryName == nullptr )
      _Error(a1: "FileSystem_LoadFileSystemModule: no -defaultgamedir or -game specified.");
  }
  if ( FileSystem_SetupSteamEnvironment(fsInfo: (KeyValues *)&steamInfo) != FS_OK )
    return false;
  CFSMountContentInfo::CFSMountContentInfo(this: &fsInfo);
  m_bEditMode = this->m_bEditMode;
  fsInfo.m_pFileSystem = g_pFullFileSystem;
  fsInfo.m_bToolsMode = m_bEditMode;
  fsInfo.m_pDirectoryName = steamInfo.m_GameInfoPath;
  if ( FileSystem_MountContent(mountContentInfo: (int)&fsInfo) != FS_OK )
    return false;
  ((void (__thiscall *)(IFileSystem *, const char *, const char *, int, int))fsInfo.m_pFileSystem->AddSearchPath)(
    a1: fsInfo.m_pFileSystem,
    a2: "platform",
    a3: "PLATFORM",
    a4: 1,
    a5: a2);
  v9 = _CommandLine();
  v10 = reslistgenerator->__vftable;
  v11 = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v9 + 32))(a1: v9, a2: "-game", a3: "hl2");
  v10->Init(this: reslistgenerator, a2: g_szBasedir, a3: (const char *)v11);
  reslistgenerator->TickAndFixupCommandLine(this: reslistgenerator);
  CLogAllFiles::Init(this: &g_LogFiles);
  if ( this->m_bEditMode )
    g_pMaterialSystem->EnableEditorMaterials(this: g_pMaterialSystem);
  info.m_pInstance = GetAppInstance();
  info.m_pBaseDirectory = g_szBasedir;
  info.m_pInitialMod = CSourceAppSystemGroup::DetermineDefaultMod(this);
  info.m_pInitialGame = CSourceAppSystemGroup::DetermineDefaultGame(this);
  info.m_bTextMode = g_bTextMode;
  info.m_pParentAppSystemGroup = this;
  return g_pEngineAPI->SetStartupInfo(this: g_pEngineAPI, a2: &info);
}

//------------------------------------------------------------------------------
// Address: 0x10004C90
// Name: public: virtual void CSourceAppSystemGroup::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10004CD0
// Name: _LauncherMain
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __usercall LauncherMain@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, HINSTANCE__ *hInstance)
{
  LPSTR CommandLineA; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  char *ExecutableFilename; // eax
  char *v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  const char *SteamInstallPath; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // ebx
  int v20; // eax
  HWND WindowA; // edi
  char *v22; // esi
  int v23; // eax
  HANDLE CurrentProcess; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // edi
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  void *(__cdecl **v45)(const char *, int *); // eax
  IAppSystem **v46; // eax
  CAppSystemGroup::Module_t *v47; // eax
  void *v48; // eax
  void *v49; // eax
  void *v50; // eax
  void *v51; // eax
  int v52; // eax
  DWORD v54; // [esp-4h] [ebp-21Ch]
  WSAData szValue; // [esp+0h] [ebp-218h] BYREF
  tagCOPYDATASTRUCT copyData; // [esp+190h] [ebp-88h] BYREF
  CSteamApplication steamApplication; // [esp+19Ch] [ebp-7Ch] BYREF
  unsigned int dwValueLen; // [esp+20Ch] [ebp-Ch] BYREF
  HKEY__ *hKey; // [esp+210h] [ebp-8h] BYREF
  bool bRestart; // [esp+217h] [ebp-1h]

  SetAppInstance(hInstance);
  _LoggingSystem_RegisterLoggingListener(a1: &g_LauncherLoggingListener);
  if ( (unsigned __int8)_Plat_VerifyHardwareKeyPrompt() == 0 )
    return -1;
  CommandLineA = GetCommandLineA();
  v6 = _CommandLine(a1: a2, a2: a3);
  (*(void (__thiscall **)(int, LPSTR))(*(_DWORD *)v6 + 4))(a1: v6, a2: CommandLineA);
  UTIL_ComputeBaseDir();
  v7 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v7 + 12))(a1: v7, a2: "-dvddev", a3: 0);
  v8 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-dllinfo", a3: 0);
  v9 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 12))(a1: v9, a2: "-vxconsole", a3: 0);
  ExecutableFilename = GetExecutableFilename();
  v11 = ExecutableFilename;
  if ( *ExecutableFilename != 0 && _V_strcmp(s1: ExecutableFilename, s2: "hl2") != 0 )
  {
    v12 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 16))(a1: v12, a2: "-game");
    v13 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *, char *))(*(_DWORD *)v13 + 20))(a1: v13, a2: "-game", a3: v11);
  }
  v14 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v14 + 12))(a1: v14, a2: "-tslist", a3: 0) != 0 )
  {
    DevMsg(a1: "Running TSList tests\n");
    _RunTSListTests(a1: 10000, a2: 1);
    DevMsg(a1: "Running TSQueue tests\n");
    _RunTSQueueTests(a1: 10000, a2: 1);
    DevMsg(a1: "Running Thread Pool tests\n");
    _RunThreadPoolTests();
  }
  if ( GetModuleHandleA(lpModuleName: "GameOverlayRenderer.dll") == nullptr )
  {
    SteamInstallPath = (const char *)_SteamAPI_GetSteamInstallPath();
    if ( SteamInstallPath != nullptr )
    {
      V_ComposeFileName(
        path: SteamInstallPath,
        filename: "GameOverlayRenderer.dll",
        dest: &szValue.szDescription[136],
        destSize: 260);
      LoadLibraryA(lpLibFileName: &szValue.szDescription[136]);
    }
  }
  RemoveSpuriousGameParameters();
  v16 = WSAStartup(wVersionRequested: 2u, lpWSAData: &szValue);
  if ( v16 != 0 )
    _Msg(a1: "Warning! Failed to start Winsock via WSAStartup = 0x%x.\n", v16);
  v17 = _CommandLine(a1, a2: *(_DWORD *)&szValue.wVersion);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v17 + 12))(a1: v17, a2: "-textmode", a3: 0) != 0 )
  {
    g_bTextMode = true;
    InitTextMode();
  }
  else
  {
    v19 = -1;
    if ( !GrabSourceMutex() )
    {
      v20 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
      if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v20 + 12))(a1: v20, a2: "-hijack", a3: 0) != 0 )
      {
        WindowA = FindWindowA(lpClassName: "Valve001", lpWindowName: nullptr);
        if ( WindowA != nullptr )
        {
          v22 = (char *)BuildCommand();
          copyData.cbData = strlen(v22) + 1;
          copyData.dwData = 0;
          copyData.lpData = v22;
          if ( SendMessageA(hWnd: WindowA, Msg: 0x4Au, wParam: 0, lParam: (LPARAM)&copyData) != 0 )
            v19 = 0;
          else
            MessageBoxA(
              hWnd: nullptr,
              lpText: "The Source Engine was found running, but did not accept the request to load a savegame. It may be an old v"
              "ersion of the engine that does not support this functionality.",
              lpCaption: "Source Engine Declined Request",
              uType: 0x30u);
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
          return v19;
        }
        else
        {
          MessageBoxA(
            hWnd: nullptr,
            lpText: "The modified entity keyvalues could not be sent to the Source Engine because the engine does not appear to be running.",
            lpCaption: "Source Engine Not Running",
            uType: 0x30u);
          return -1;
        }
      }
      else
      {
        MessageBoxA(
          hWnd: nullptr,
          lpText: "Only one instance of the game can be running at one time.",
          lpCaption: "Source - Warning",
          uType: 0x40u);
        return -1;
      }
    }
  }
  v18 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v18 + 12))(a1: v18, a2: "-low", a3: 0) != 0 )
  {
    v54 = 64;
LABEL_28:
    CurrentProcess = GetCurrentProcess();
    SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: v54);
    goto LABEL_29;
  }
  v23 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v23 + 12))(a1: v23, a2: "-high", a3: 0) != 0 )
  {
    v54 = 128;
    goto LABEL_28;
  }
LABEL_29:
  v25 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v25 + 12))(a1: v25, a2: "-steam", a3: 0) == 0 )
  {
    v26 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v26 + 20))(a1: v26, a2: "-insecure", a3: 0);
  }
  _chdir(path: g_szBasedir);
  v27 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v27 + 12))(a1: v27, a2: "-buildcubemaps", a3: 0) != 0 )
  {
    v28 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v28 + 20))(a1: v28, a2: "-nosound", a3: 0);
    v29 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v29 + 20))(a1: v29, a2: "-noasync", a3: 0);
  }
  v30 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
  g_LeakDump.m_bCheckLeaks = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v30 + 12))(
                               a1: v30,
                               a2: "-leakcheck",
                               a3: 0) != 0;
  do
  {
    CSteamAppSystemGroup::CSteamAppSystemGroup(
      this: (CSteamAppSystemGroup *)&szValue.szDescription[28],
      pFileSystem: nullptr,
      pAppSystemParent: nullptr);
    *(_DWORD *)&szValue.szDescription[28] = &CSourceAppSystemGroup::`vftable';
    CSteamApplication::CSteamApplication(
      this: &steamApplication,
      pAppSystemGroup: (CSteamAppSystemGroup *)&szValue.szDescription[28]);
    v31 = CAppSystemGroup::Run(this: &steamApplication);
    if ( CAppSystemGroup::GetCurrentStage(this: &steamApplication) == INITIALIZATION )
    {
      bRestart = v31 == 2;
      if ( v31 != 2 )
        goto LABEL_36;
    }
    else
    {
      if ( v31 != 4 )
      {
LABEL_36:
        bRestart = reslistgenerator->ShouldContinue(this: reslistgenerator);
        if ( bRestart )
          goto LABEL_38;
        goto LABEL_37;
      }
      bRestart = true;
    }
LABEL_37:
    v32 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v32 + 16))(a1: v32, a2: "-w");
    v33 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v33 + 16))(a1: v33, a2: "-h");
    v34 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v34 + 16))(a1: v34, a2: "-width");
    v35 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v35 + 16))(a1: v35, a2: "-height");
    v36 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v36 + 16))(a1: v36, a2: "-sw");
    v37 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v37 + 16))(a1: v37, a2: "-startwindowed");
    v38 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v38 + 16))(a1: v38, a2: "-windowed");
    v39 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v39 + 16))(a1: v39, a2: "-window");
    v40 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v40 + 16))(a1: v40, a2: "-full");
    v41 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v41 + 16))(a1: v41, a2: "-fullscreen");
    v42 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v42 + 16))(a1: v42, a2: "-autoconfig");
    v43 = _CommandLine(a1: *(_DWORD *)&szValue.wVersion, a2: *(_DWORD *)szValue.szDescription);
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v43 + 16))(a1: v43, a2: "+mat_hdr_level");
LABEL_38:
    CUtlDict<int,unsigned short>::RemoveAll(this: &steamApplication.m_SystemDict);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &steamApplication.m_SystemDict.m_Elements.m_Tree);
    m_pMemory = steamApplication.m_SystemDict.m_Elements.m_Tree.m_Elements.m_pMemory;
    steamApplication.m_SystemDict.m_Elements.m_Tree.m_FirstFree = -1;
    if ( steamApplication.m_SystemDict.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( steamApplication.m_SystemDict.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: steamApplication.m_SystemDict.m_Elements.m_Tree.m_Elements.m_pMemory);
        m_pMemory = nullptr;
        steamApplication.m_SystemDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      steamApplication.m_SystemDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    steamApplication.m_SystemDict.m_Elements.m_Tree.m_LastAlloc.index = -1;
    if ( steamApplication.m_SystemDict.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        steamApplication.m_SystemDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      steamApplication.m_SystemDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    v45 = steamApplication.m_NonAppSystemFactories.m_Memory.m_pMemory;
    steamApplication.m_NonAppSystemFactories.m_Size = 0;
    if ( steamApplication.m_NonAppSystemFactories.m_Memory.m_nGrowSize >= 0 )
    {
      if ( steamApplication.m_NonAppSystemFactories.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: steamApplication.m_NonAppSystemFactories.m_Memory.m_pMemory);
        v45 = nullptr;
        steamApplication.m_NonAppSystemFactories.m_Memory.m_pMemory = nullptr;
      }
      steamApplication.m_NonAppSystemFactories.m_Memory.m_nAllocationCount = 0;
    }
    steamApplication.m_NonAppSystemFactories.m_pElements = v45;
    if ( steamApplication.m_NonAppSystemFactories.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v45 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v45);
        steamApplication.m_NonAppSystemFactories.m_Memory.m_pMemory = nullptr;
      }
      steamApplication.m_NonAppSystemFactories.m_Memory.m_nAllocationCount = 0;
    }
    v46 = steamApplication.m_Systems.m_Memory.m_pMemory;
    steamApplication.m_Systems.m_Size = 0;
    if ( steamApplication.m_Systems.m_Memory.m_nGrowSize >= 0 )
    {
      if ( steamApplication.m_Systems.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: steamApplication.m_Systems.m_Memory.m_pMemory);
        v46 = nullptr;
        steamApplication.m_Systems.m_Memory.m_pMemory = nullptr;
      }
      steamApplication.m_Systems.m_Memory.m_nAllocationCount = 0;
    }
    steamApplication.m_Systems.m_pElements = v46;
    if ( steamApplication.m_Systems.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v46 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v46);
        steamApplication.m_Systems.m_Memory.m_pMemory = nullptr;
      }
      steamApplication.m_Systems.m_Memory.m_nAllocationCount = 0;
    }
    v47 = steamApplication.m_Modules.m_Memory.m_pMemory;
    steamApplication.m_Modules.m_Size = 0;
    if ( steamApplication.m_Modules.m_Memory.m_nGrowSize >= 0 )
    {
      if ( steamApplication.m_Modules.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: steamApplication.m_Modules.m_Memory.m_pMemory);
        v47 = nullptr;
        steamApplication.m_Modules.m_Memory.m_pMemory = nullptr;
      }
      steamApplication.m_Modules.m_Memory.m_nAllocationCount = 0;
    }
    steamApplication.m_Modules.m_pElements = v47;
    if ( steamApplication.m_Modules.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v47 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v47);
        steamApplication.m_Modules.m_Memory.m_pMemory = nullptr;
      }
      steamApplication.m_Modules.m_Memory.m_nAllocationCount = 0;
    }
    CUtlDict<int,unsigned short>::RemoveAll(this: (CUtlDict<int,unsigned short> *)&szValue.szDescription[92]);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&szValue.szDescription[92]);
    v48 = *(void **)&szValue.szDescription[96];
    *(_WORD *)&szValue.szDescription[112] = -1;
    if ( *(int *)&szValue.szDescription[104] >= 0 )
    {
      if ( *(_DWORD *)&szValue.szDescription[96] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&szValue.szDescription[96]);
        v48 = nullptr;
        *(_DWORD *)&szValue.szDescription[96] = 0;
      }
      *(_DWORD *)&szValue.szDescription[100] = 0;
    }
    *(_WORD *)&szValue.szDescription[114] = -1;
    if ( *(int *)&szValue.szDescription[104] >= 0 )
    {
      if ( v48 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v48);
        *(_DWORD *)&szValue.szDescription[96] = 0;
      }
      *(_DWORD *)&szValue.szDescription[100] = 0;
    }
    v49 = *(void **)&szValue.szDescription[72];
    *(_DWORD *)&szValue.szDescription[84] = 0;
    if ( *(int *)&szValue.szDescription[80] >= 0 )
    {
      if ( *(_DWORD *)&szValue.szDescription[72] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&szValue.szDescription[72]);
        v49 = nullptr;
        *(_DWORD *)&szValue.szDescription[72] = 0;
      }
      *(_DWORD *)&szValue.szDescription[76] = 0;
    }
    *(_DWORD *)&szValue.szDescription[88] = v49;
    if ( *(int *)&szValue.szDescription[80] >= 0 )
    {
      if ( v49 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v49);
        *(_DWORD *)&szValue.szDescription[72] = 0;
      }
      *(_DWORD *)&szValue.szDescription[76] = 0;
    }
    v50 = *(void **)&szValue.szDescription[52];
    *(_DWORD *)&szValue.szDescription[64] = 0;
    if ( *(int *)&szValue.szDescription[60] >= 0 )
    {
      if ( *(_DWORD *)&szValue.szDescription[52] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&szValue.szDescription[52]);
        v50 = nullptr;
        *(_DWORD *)&szValue.szDescription[52] = 0;
      }
      *(_DWORD *)&szValue.szDescription[56] = 0;
    }
    *(_DWORD *)&szValue.szDescription[68] = v50;
    if ( *(int *)&szValue.szDescription[60] >= 0 )
    {
      if ( v50 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50);
        *(_DWORD *)&szValue.szDescription[52] = 0;
      }
      *(_DWORD *)&szValue.szDescription[56] = 0;
    }
    v51 = *(void **)&szValue.szDescription[32];
    *(_DWORD *)&szValue.szDescription[44] = 0;
    if ( *(int *)&szValue.szDescription[40] >= 0 )
    {
      if ( *(_DWORD *)&szValue.szDescription[32] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&szValue.szDescription[32]);
        v51 = nullptr;
        *(_DWORD *)&szValue.szDescription[32] = 0;
      }
      *(_DWORD *)&szValue.szDescription[36] = 0;
    }
    *(_DWORD *)&szValue.szDescription[48] = v51;
    if ( *(int *)&szValue.szDescription[40] >= 0 && v51 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v51);
  }
  while ( bRestart );
  v52 = WSACleanup();
  if ( v52 != 0 )
    _Msg(a1: "Warning! Failed to complete WSACleanup = 0x%x.\n", v52);
  if ( g_hMutex != nullptr )
  {
    ReleaseMutex(hMutex: g_hMutex);
    CloseHandle(hObject: g_hMutex);
    g_hMutex = nullptr;
  }
  if ( RegOpenKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: "Software\\Valve\\Source",
         ulOptions: 0,
         samDesired: 0xF003Fu,
         phkResult: &hKey) == 0 )
  {
    dwValueLen = 260;
    if ( RegQueryValueExA(
           hKey,
           lpValueName: "Relaunch URL",
           lpReserved: nullptr,
           lpType: nullptr,
           lpData: (LPBYTE)&szValue.szDescription[136],
           lpcbData: &dwValueLen) == 0 )
    {
      ShellExecuteA(
        hwnd: nullptr,
        lpOperation: "open",
        lpFile: &szValue.szDescription[136],
        lpParameters: nullptr,
        lpDirectory: nullptr,
        nShowCmd: 5);
      RegDeleteValueA(hKey, lpValueName: "Relaunch URL");
    }
    RegCloseKey(hKey);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10005660
// Name: AllLogLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AllLogLessFunc(CUtlString *pLHS, CUtlString *pRHS)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: pRHS);
  v3 = CUtlString::operator char const *(this: pLHS);
  if ( v3 == nullptr )
    return false;
  if ( v2 != nullptr )
    return _V_stricmp(s1: v3, s2: v2) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100085B0
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}

//------------------------------------------------------------------------------
// Address: 0x10005510
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
