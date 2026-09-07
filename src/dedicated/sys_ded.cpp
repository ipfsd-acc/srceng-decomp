// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/sys_ded.cpp
// Functions: 16
// ============================================================

#include "dedicated\sys_ded.h"

//------------------------------------------------------------------------------
// Address: 0x100035D0
// Name: public: virtual bool CVguiSteamApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVguiSteamApp::PreInit(CVguiSteamApp *this)
{
  vgui::Panel *v1; // ecx
  void *(__cdecl *factory)(const char *, int *); // [esp+0h] [ebp-Ch] BYREF
  void *(__cdecl *v4)(const char *, int *); // [esp+4h] [ebp-8h]
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  v4 = CAppSystemGroup::GetFactory();
  CSteamApplication::PostShutdown(this: v1);
  factory = CAppSystemGroup::GetFactory();
  return vgui::VGui_InitInterfacesList(moduleName: "CVguiSteamApp", factoryList: &factory, numFactories: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10003660
// Name: public: virtual void CDedicatedServerLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedServerLoggingListener::Log(
        CDedicatedServerLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  HANDLE CurrentProcess; // eax

  if ( sys != nullptr )
  {
    if ( g_nSubProcessId != 0 )
      sys->Printf(this: sys, a2: " #%0x2d:%s", g_nSubProcessId, pMessage);
    else
      sys->Printf(this: sys, a2: "#%s", pMessage);
  }
  _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( g_bVGui )
      MessageBoxA(hWnd: nullptr, lpText: pMessage, lpCaption: "Error", uType: 0x2000u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(hProcess: CurrentProcess, uExitCode: 1u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100036F0
// Name: void RunServer(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RunServer(int a1@<ebx>, bool bSupressStdIOBecauseWeAreAForkedChild)
{
  char v2; // bl
  tagMSG Msg; // [esp+0h] [ebp-20h] BYREF
  __int16 v5; // [esp+1Ch] [ebp-4h]

  if ( gpszCvars != nullptr )
    engine->AddConsoleText(this: engine, a2: gpszCvars);
  if ( g_bVGui )
    RunVGUIFrame();
  if ( engine->RunFrame(this: engine) )
  {
    if ( g_bVGui )
      RunVGUIFrame();
    if ( engine->RunFrame(this: engine) )
    {
      if ( g_bVGui )
      {
        VGUIFinishedConfig();
        RunVGUIFrame();
      }
      do
      {
        v2 = 0;
        if ( (unsigned __int8)_Plat_IsInBenchmarkMode() == 0 )
          sys->Sleep(this: sys, a2: 1);
        if ( PeekMessageA(lpMsg: &Msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
        {
          while ( Msg.message != 18 )
          {
            TranslateMessage(lpMsg: &Msg);
            DispatchMessageA(lpMsg: &Msg);
            if ( !PeekMessageA(lpMsg: &Msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
              goto LABEL_18;
          }
          v2 = 1;
        }
LABEL_18:
        v5 &= 0xFCC0u;
        v5 |= 0x23Fu;
        if ( v2 != 0 )
          break;
        if ( g_bVGui )
        {
          RunVGUIFrame();
        }
        else if ( !bSupressStdIOBecauseWeAreAForkedChild )
        {
          ProcessConsoleInput();
        }
        if ( ((unsigned __int8 (__thiscall *)(IDedicatedServerAPI *, int))engine->RunFrame)(a1: engine, a2: a1) == 0 )
          v2 = 1;
        a1 = 0;
        ((void (__thiscall *)(ISys *))sys->UpdateStatus)(a1: sys);
      }
      while ( v2 == 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003830
// Name: bool ConsoleStartup(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __cdecl ConsoleStartup(void *(__cdecl *dedicatedFactory)(const char *, int *))
{
  if ( g_bVGui )
  {
    StartVGUI(dedicatedFactory);
    RunVGUIFrame();
    while ( VGUIIsInConfig() )
    {
      if ( !VGUIIsRunning() )
        break;
      RunVGUIFrame();
    }
    if ( VGUIIsStopping() )
      return 0;
  }
  else if ( !CTextConsoleWin32::Init(this: &console) )
  {
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003890
// Name: public: virtual bool CDedicatedAppSystemGroup::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDedicatedAppSystemGroup::Create(CDedicatedAppSystemGroup *this)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax
  int Module; // eax

  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_SetLoggingResponsePolicy(a1: &s_NonFatalLoggingResponsePolicy);
  _LoggingSystem_RegisterLoggingListener(a1: &s_DedicatedServerLoggingListener);
  FactoryThis = Sys_GetFactoryThis();
  Module = CAppSystemGroup::LoadModule(this, factory: FactoryThis);
  return CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VENGINE_DEDICATEDEXPORTS_API_VERSION003") != nullptr
      && sys->LoadModules(this: sys, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100038F0
// Name: public: virtual bool CDedicatedAppSystemGroup::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDedicatedAppSystemGroup::PreInit(CDedicatedAppSystemGroup *this)
{
  int v2; // eax
  int v3; // eax
  CFSSearchPathsInit initInfo; // [esp+4h] [ebp-424h] BYREF
  CFSSteamSetupInfo steamInfo; // [esp+210h] [ebp-218h] BYREF
  CFSMountContentInfo fsInfo; // [esp+41Ch] [ebp-Ch] BYREF

  g_pFullFileSystem = nullptr;
  if ( !CVguiSteamApp::PreInit(this) )
    return false;
  CFSSteamSetupInfo::CFSSteamSetupInfo(this: &steamInfo);
  steamInfo.m_pDirectoryName = nullptr;
  *(_WORD *)&steamInfo.m_bOnlyUseDirectoryName = 0;
  steamInfo.m_bSetSteamDLLPath = false;
  steamInfo.m_bSteam = g_pFullFileSystem->IsSteam(this: g_pFullFileSystem);
  steamInfo.m_bNoGameInfo = steamInfo.m_bSteam;
  if ( FileSystem_SetupSteamEnvironment(fsInfo: (KeyValues *)&steamInfo) != FS_OK )
    return false;
  CFSMountContentInfo::CFSMountContentInfo(this: &fsInfo);
  fsInfo.m_pFileSystem = g_pFullFileSystem;
  fsInfo.m_bToolsMode = false;
  fsInfo.m_pDirectoryName = steamInfo.m_GameInfoPath;
  if ( FileSystem_MountContent(mountContentInfo: (int)&fsInfo) != FS_OK || !NET_Init() )
    return false;
  CFSSearchPathsInit::CFSSearchPathsInit(this: &initInfo);
  initInfo.m_pFileSystem = g_pFullFileSystem;
  v2 = _CommandLine();
  initInfo.m_pDirectoryName = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 32))(
                                              a1: v2,
                                              a2: "-game",
                                              a3: 0);
  FileSystem_LoadSearchPaths((KeyValues *)&initInfo);
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-console", a3: 0) != 0 )
  {
    g_bVGui = false;
    return sys->CreateConsoleWindow(this: sys);
  }
  g_bVGui = true;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10003A20
// Name: public: virtual void CDedicatedAppSystemGroup::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedAppSystemGroup::PostShutdown(CDedicatedAppSystemGroup *this)
{
  vgui::Panel *v1; // ecx

  if ( g_bVGui )
    StopVGUI();
  sys->DestroyConsoleWindow(this: sys);
  CTextConsoleWin32::ShutDown(this: &console);
  NET_Shutdown();
  CSteamApplication::PostShutdown(this: v1);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10003A60
// Name: public: virtual void CDedicatedAppSystemGroup::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedAppSystemGroup::Destroy(CDedicatedAppSystemGroup *this)
{
  _LoggingSystem_PopLoggingState(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10003A70
// Name: void UTIL_ComputeBaseDir(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ComputeBaseDir(char *pBaseDir, DWORD nMaxLen)
{
  HMODULE ModuleHandleA; // eax
  _BYTE *v3; // eax
  int v4; // eax
  char v5; // cl
  int v6; // eax
  int v7; // eax
  char *v8; // edx
  char v9; // cl

  *pBaseDir = 0;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: pBaseDir, nSize: nMaxLen) != 0 )
  {
    strrchr(string: (unsigned __int8 *)pBaseDir, chr: 0x5Cu);
    if ( v3 != nullptr && *v3 != 0 )
      v3[1] = 0;
    v4 = strlen(pBaseDir);
    if ( v4 > 0 )
    {
      v5 = pBaseDir[v4 - 1];
      if ( v5 == 92 || v5 == 47 )
        pBaseDir[v4 - 1] = 0;
    }
  }
  v6 = _CommandLine();
  v7 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-basedir", a3: 0);
  if ( v7 != 0 )
  {
    v8 = &pBaseDir[-v7];
    do
    {
      v9 = *(_BYTE *)v7;
      v8[v7] = *(_BYTE *)v7;
      ++v7;
    }
    while ( v9 != 0 );
  }
  _V_strlower(start: pBaseDir);
  V_FixSlashes(pname: pBaseDir, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x10003B10
// Name: public: virtual bool CDedicatedSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDedicatedSteamApplication::Create(CDedicatedSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax

  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, factory: (void *(__cdecl *)(const char *, int *))FileSystemFactory);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 != nullptr )
    return 1;
  _Warning(a1: "Unable to load the file system!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003B70
// Name: s_GameInfoSuggestFN
// Source: json
//------------------------------------------------------------------------------
char __cdecl s_GameInfoSuggestFN(const CFSSteamSetupInfo *pFsSteamSetupInfo, char *pchPathBuffer, int nBufferLength)
{
  V_strncpy(pDest: pchPathBuffer, pSrc: "left4dead", maxLen: nBufferLength);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003B90
// Name: public: virtual enum LoggingResponse_t CNonFatalLoggingResponsePolicy::OnLog(struct LoggingContext_t const __near *)
// Source: json
//------------------------------------------------------------------------------
LoggingResponse_t __thiscall CNonFatalLoggingResponsePolicy::OnLog(
        CNonFatalLoggingResponsePolicy *this,
        const LoggingContext_t *pContext)
{
  int v2; // eax
  LoggingResponse_t result; // eax

  result = pContext->m_Severity == LS_ASSERT
        && (v2 = _CommandLine(a1: this),
            (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-noassert") == 0)
        || pContext->m_Severity == LS_ERROR;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004060
// Name: public: virtual int CDedicatedAppSystemGroup::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDedicatedAppSystemGroup::Main(CDedicatedAppSystemGroup *this)
{
  void *(__cdecl *Factory)(const char *, int *); // eax
  int v2; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  const char *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  IBaseFileSystem *v10; // eax
  KeyValues *Key; // eax
  int Int; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  char gameInfoFilename[260]; // [esp+0h] [ebp-238h] BYREF
  char fullLocationPath[260]; // [esp+104h] [ebp-134h] BYREF
  ModInfo_t info; // [esp+208h] [ebp-30h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > depList; // [esp+220h] [ebp-18h] BYREF
  CDedicatedAppSystemGroup *v23; // [esp+234h] [ebp-4h]

  v23 = this;
  Factory = CAppSystemGroup::GetFactory();
  if ( ConsoleStartup(dedicatedFactory: Factory) == 0 )
    return -1;
  if ( g_bVGui )
  {
    RunVGUIFrame();
  }
  else
  {
    v4 = _CommandLine(a1: v2);
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-steam", a3: 0) != 0 )
    {
      if ( _getcwd(pnbuf: fullLocationPath, maxlen: 260) != nullptr )
        g_pFullFileSystem->AddSearchPath(
          this: g_pFullFileSystem,
          a2: fullLocationPath,
          a3: "MAIN",
          a4: PATH_ADD_TO_TAIL);
      v6 = _CommandLine(a1: v5);
      v7 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v6 + 32))(
                           a1: v6,
                           a2: "-game",
                           a3: g_gameName);
      V_snprintf(pDest: gameInfoFilename, maxLen: 259, pFormat: "%s\\gameinfo.txt", v7);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "GameInfo");
      else
        v9 = nullptr;
      if ( g_pFullFileSystem != nullptr )
        v10 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v10 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v9,
             filesystem: v10,
             resourceName: gameInfoFilename,
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        Key = KeyValues::FindKey(this: v9, keyName: "FileSystem", bCreate: false);
        Int = KeyValues::GetInt(this: Key, keyName: "SteamAppId", defaultValue: 0);
        if ( Int != 0 )
        {
          memset(&depList, 0, sizeof(depList));
          MountDependencies(iAppId: Int, &depList);
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&depList);
        }
      }
      KeyValues::deleteThis(this: v9);
      g_pFullFileSystem->RemoveSearchPaths(this: g_pFullFileSystem, a2: "MAIN");
    }
  }
  info.m_pInstance = GetAppInstance();
  info.m_pBaseDirectory = UTIL_GetBaseDir();
  v14 = _CommandLine(a1: v13);
  info.m_pInitialMod = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v14 + 32))(
                                       a1: v14,
                                       a2: "-game",
                                       a3: g_gameName);
  v16 = _CommandLine(a1: v15);
  info.m_pInitialGame = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v16 + 32))(
                                        a1: v16,
                                        a2: "-defaultgamedir",
                                        a3: g_gameName);
  info.m_pParentAppSystemGroup = v23;
  v18 = _CommandLine(a1: v17);
  info.m_bTextMode = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v18 + 12))(
                       a1: v18,
                       a2: "-textmode",
                       a3: 0) != 0;
  if ( engine->ModInit(this: engine, a2: &info) )
    engine->ModShutdown(this: engine);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100042C0
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
// Address: 0x10004320
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main()
{
  int v0; // ecx
  int *v1; // edi
  int v2; // esi
  LPSTR CommandLineA; // eax
  int v4; // ecx
  int *v5; // edi
  int v6; // esi
  LPSTR v7; // eax
  int v9; // esi
  char pBasedir[260]; // [esp+2Ch] [ebp-2E4h] BYREF
  CDedicatedAppSystemGroup dedicatedSystems; // [esp+130h] [ebp-1E0h] BYREF
  CDedicatedSteamApplication steamApplication; // [esp+29Ch] [ebp-74h] BYREF
  __int16 v13; // [esp+30Ch] [ebp-4h]

  __asm { fninit }
  v13 = v13 & 0xFCC0 | 0x23F;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  v1 = (int *)_CommandLine(a1: v0);
  v2 = *v1;
  CommandLineA = GetCommandLineA();
  (*(void (__thiscall **)(int *, LPSTR))(v2 + 4))(a1: v1, a2: CommandLineA);
  UTIL_ComputeBaseDir(pBaseDir: pBasedir, nMaxLen: 0x104u);
  _chdir(path: pBasedir);
  v5 = (int *)_CommandLine(a1: v4);
  v6 = *v5;
  v7 = GetCommandLineA();
  (*(void (__thiscall **)(int *, LPSTR))(v6 + 4))(a1: v5, a2: v7);
  if ( InitInstance() == 0 )
    return -1;
  SetSuggestGameInfoDirFn(pfnNewFn: (bool (__cdecl *)(const CFSSteamSetupInfo *, char *, int, bool *))s_GameInfoSuggestFN);
  CSteamAppSystemGroup::CSteamAppSystemGroup(this: &dedicatedSystems, pFileSystem: nullptr, pAppSystemParent: nullptr);
  dedicatedSystems.__vftable = (CDedicatedAppSystemGroup_vtbl *)&CDedicatedAppSystemGroup::`vftable';
  CSteamApplication::CSteamApplication(this: &steamApplication, pAppSystemGroup: &dedicatedSystems);
  steamApplication.__vftable = (CDedicatedSteamApplication_vtbl *)&CDedicatedSteamApplication::`vftable';
  v9 = CAppSystemGroup::Run(this: &steamApplication);
  CUtlDict<int,unsigned short>::RemoveAll(this: &steamApplication.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &steamApplication.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&steamApplication.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&steamApplication.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&steamApplication.m_Modules);
  CUtlDict<int,unsigned short>::RemoveAll(this: &dedicatedSystems.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &dedicatedSystems.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dedicatedSystems.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dedicatedSystems.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dedicatedSystems.m_Modules);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100290C0
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}
