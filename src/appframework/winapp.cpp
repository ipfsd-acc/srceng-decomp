// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: appframework/winapp.cpp
// Functions: 2
// ============================================================

#include "appframework\winapp.h"

//------------------------------------------------------------------------------
// Address: 0x10213D20
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213D70
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
    _Plat_DebugString(a1: pMessage);
}

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x004021C0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402210
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x00402220
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004022D0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402370
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00402390
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004023A0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004023D0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( vgui::BuildGroup::GetResourceName((vgui::BuildGroup *)this) != (const char *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00402420
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00402440
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00402480
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428830
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(vgui::Panel *this)
{
  ;
}

} // namespace avitest

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x00403540
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CDataManagerBase *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00405A80
// Name: enum SpewRetval_t WinAppDefaultSpewFunc(enum SpewType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl WinAppDefaultSpewFunc(SpewType_t spewType, const char *pMsg)
{
  _Plat_DebugString(a1: pMsg);
  return spewType >= SPEW_MESSAGE && (spewType <= SPEW_WARNING || spewType == SPEW_LOG);
}

//------------------------------------------------------------------------------
// Address: 0x00405AB0
// Name: enum SpewRetval_t ConsoleAppDefaultSpewFunc(enum SpewType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ConsoleAppDefaultSpewFunc(SpewType_t spewType, const char *pMsg)
{
  printf(format: pMsg);
  _Plat_DebugString(a1: pMsg);
  return spewType >= SPEW_MESSAGE && (spewType <= SPEW_WARNING || spewType == SPEW_LOG);
}

//------------------------------------------------------------------------------
// Address: 0x00405AF0
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax

  g_DefaultSpewFunc = (SpewRetval_t (__cdecl *)(SpewType_t, const char *))ConsoleAppDefaultSpewFunc;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine_Tier0();
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00405B30
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[264]; // [esp+0h] [ebp-108h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: &pFileSystemDLL[4], nMaxLen: 260, bSteam: &this->m_bSteam) != FS_OK )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: &pFileSystemDLL[4]);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_4300B0, a2: &pFileSystemDLL[4]);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405BD0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405BE0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00405C10
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetErrorStage(this) != NONE )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00405C60
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00405C80
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace choreogen

// ============================================================
// Overlay from concatworlds (Missing functions)
// ============================================================
namespace concatworlds {

//------------------------------------------------------------------------------
// Address: 0x00401050
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CSteamApplication *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00402880
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(ConCommandBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404B10
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404B60
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00404BA0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404C40
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00404C60
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00404C70
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404CA0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404CF0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00404D10
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00404D50
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace concatworlds

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10029B00
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029B50
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x10029B60
// Name: void SetAppInstance(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetAppInstance(void *hInstance)
{
  s_HInstance = hInstance;
}

//------------------------------------------------------------------------------
// Address: 0x10029B70
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029C10
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10029C30
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10029C40
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(vgui::Panel *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10029C50
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x10029C80
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAsyncFileRequest::GetIOTransferredSize((vgui::BuildGroup *)this) != (char *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x10029CD0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x10029CF0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x10029D30
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace dedicated

// ============================================================
// Overlay from dmxconvert (Missing functions)
// ============================================================
namespace dmxconvert {

//------------------------------------------------------------------------------
// Address: 0x004018A0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CBaseAppSystem<IDmSerializers> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00403970
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004039C0
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403A00
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403AA0
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00403AC0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403AD0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403B00
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403B50
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403B70
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00403BB0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004018B0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

} // namespace dmxconvert

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0040CC40
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CC90
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040CCD0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040CD70
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x0040CD90
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040CDA0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040CDD0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040CE20
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040CE40
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x0040CE80
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace dmxedit

// ============================================================
// Overlay from dumpworld (Missing functions)
// ============================================================
namespace dumpworld {

//------------------------------------------------------------------------------
// Address: 0x00404B70
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BC0
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00404C00
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404CC0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00404CD0
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(ConCommandBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404CE0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CSteamApplication *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00404D20
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404D70
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00404D90
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00404DD0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace dumpworld

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00403860
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004038B0
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x004038C0
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // ecx
  int v8; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v8 = _CommandLine(a1: v7);
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v8 + 4))(a1: v8, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403A10
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00403A30
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403A40
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403A70
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CDmeTransformControl::GetPositionAttr((vgui::BuildGroup *)this) != (const char *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403AE0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10213EF0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213F40
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer (Missing functions)
// ============================================================
namespace hammer {

//------------------------------------------------------------------------------
// Address: 0x00401C80
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener_0;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(size: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  operator delete(p: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00401D30
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

} // namespace hammer

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x00490350
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSteamApplication::PostShutdown()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004953F0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495440
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_4F770C, a2: pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004954E0
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00495500
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00495510
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00495540
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00495590
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004955B0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x004955F0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0042BDD0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042BE70
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x0042BE90
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042BEA0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0042BED0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0042BF20
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042BF40
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x0042BF80
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace hlmv

// ============================================================
// Overlay from inputtest (Missing functions)
// ============================================================
namespace inputtest {

//------------------------------------------------------------------------------
// Address: 0x00401AF0
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(ConCommandBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403E30
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403E80
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x00403E90
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403F40
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403FE0
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00404000
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00404010
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CSteamApplication *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00404020
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404050
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004040A0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004040C0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace inputtest

// ============================================================
// Overlay from launcher (Missing functions)
// ============================================================
namespace launcher {

//------------------------------------------------------------------------------
// Address: 0x10004CC0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSteamApplication::PostShutdown()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10008FF0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009040
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x10009050
// Name: void SetAppInstance(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetAppInstance(void *hInstance)
{
  s_HInstance = hInstance;
}

//------------------------------------------------------------------------------
// Address: 0x10009060
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009100
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10009120
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10009130
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(ConCommandBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009140
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x10009170
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x100091C0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x100091E0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x10009220
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace launcher

// ============================================================
// Overlay from lightworld (Missing functions)
// ============================================================
namespace lightworld {

//------------------------------------------------------------------------------
// Address: 0x004064C0
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(ConCommandBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004088F0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408940
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00408980
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408A20
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00408A40
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00408A50
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CSteamApplication *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00408A60
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00408A90
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00408AE0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00408B00
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00408B40
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace lightworld

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x004162C0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSteamApplication::PostShutdown()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0041CD00
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CD50
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  int v3; // ecx
  void (__thiscall ***v4)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v4 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine(a1: v3);
  (**v4)(a1: v4, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0041CD90
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_447DDC, a2: pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041CE30
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x0041CE50
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041CE60
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0041CE90
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0041CEE0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041CF00
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x0041CF40
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace localization_check

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x004B3520
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3570
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004B35B0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_5B2B8C, a2: pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B3650
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x004B3670
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B3680
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004B36B0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004B3700
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B3720
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x004B3760
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CC3D0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CBaseAppSystem<IDmSerializers> *this)
{
  ;
}

} // namespace makegamedata

// ============================================================
// Overlay from materialsystemtest (Missing functions)
// ============================================================
namespace materialsystemtest {

//------------------------------------------------------------------------------
// Address: 0x00404990
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004049E0
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x004049F0
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  int v9; // [esp+0h] [ebp-110h]
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine(a1: v9);
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404AA0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404B40
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00404B80
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CSteamApplication *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00404B90
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404C10
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00404C30
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace materialsystemtest

// ============================================================
// Overlay from mdlbuild (Missing functions)
// ============================================================
namespace mdlbuild {

//------------------------------------------------------------------------------
// Address: 0x00401D60
// Name: enum SpewRetval_t WinAppDefaultSpewFunc(enum SpewType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl WinAppDefaultSpewFunc(SpewType_t spewType, const char *pMsg)
{
  _Plat_DebugString(a1: pMsg);
  return spewType >= SPEW_MESSAGE && (spewType <= SPEW_WARNING || spewType == SPEW_LOG);
}

//------------------------------------------------------------------------------
// Address: 0x00401D90
// Name: enum SpewRetval_t ConsoleAppDefaultSpewFunc(enum SpewType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ConsoleAppDefaultSpewFunc(SpewType_t spewType, const char *pMsg)
{
  printf(format: pMsg);
  _Plat_DebugString(a1: pMsg);
  return spewType >= SPEW_MESSAGE && (spewType <= SPEW_WARNING || spewType == SPEW_LOG);
}

//------------------------------------------------------------------------------
// Address: 0x00401DD0
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  int v3; // ecx
  void (__thiscall ***v4)(_DWORD, int, char **); // eax

  g_DefaultSpewFunc = (SpewRetval_t (__cdecl *)(SpewType_t, const char *))ConsoleAppDefaultSpewFunc;
  s_HInstance = nullptr;
  v4 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine_Tier0(a1: v3);
  (**v4)(a1: v4, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00401E10
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[264]; // [esp+0h] [ebp-108h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: &pFileSystemDLL[4], nMaxLen: 260, bSteam: &this->m_bSteam) != FS_OK )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar005");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: &pFileSystemDLL[4]);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", &pFileSystemDLL[4]);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401EB0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401EC0
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(CSteamApplication *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401ED0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CSteamApplication *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00401EE0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00401F10
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetErrorStage(this) != NONE )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00401F60
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00401F80
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace mdlbuild

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004759A0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004759F0
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax
  int savedregs; // [esp+0h] [ebp+0h]

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine(a1: savedregs);
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00475A30
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CSteamApplication::Create@<al>(CSteamApplication *this@<ecx>, int a2@<ebx>)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v5; // eax
  IFileSystem *v6; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath(a1: a2);
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v5 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v6 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v5, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v6;
  if ( v6 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00475AD0
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __userpurge CSteamApplication::GetFileSystemDLLName@<eax>(
        CSteamApplication *this@<ecx>,
        int a2@<ebx>,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(a1: a2, pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00475AF0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00475B00
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CSteamApplication::Main@<eax>(CSteamApplication *this@<ecx>, int a2@<ebx>)
{
  if ( FileSystem_SetBasePaths(a1: a2, pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00475B30
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CSteamApplication::Startup@<eax>(CSteamApplication *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi

  v3 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v3;
  if ( FileSystem_SetBasePaths(a1: a2, pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00475B80
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00475BA0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00475BE0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace mdlcompile

// ============================================================
// Overlay from meshutilstest (Missing functions)
// ============================================================
namespace meshutilstest {

//------------------------------------------------------------------------------
// Address: 0x00401390
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CSteamApplication *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004040E0
// Name: enum SpewRetval_t WinAppDefaultSpewFunc(enum SpewType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WinAppDefaultSpewFunc(SpewType_t spewType, const char *pMsg)
{
  if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
  {
    _Plat_DebugString(a1: pMsg);
    if ( spewType == SPEW_ASSERT )
      return 0;
  }
  if ( spewType != SPEW_ERROR )
    return 1;
  if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
    __debugbreak();
  _Plat_MessageBox(a1: "Error", a2: pMsg);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00404140
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x00404150
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[264]; // [esp+8h] [ebp-108h] BYREF

  g_DefaultSpewFunc = (SpewRetval_t (__cdecl *)(SpewType_t, const char *))WinAppDefaultSpewFunc;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: &szModuleFilename[4], a2: 260);
  v5 = strlen(&szModuleFilename[4]) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", &szModuleFilename[4], lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404200
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[264]; // [esp+8h] [ebp-108h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: &pFileSystemDLL[4], a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: &pFileSystemDLL[4]);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", &pFileSystemDLL[4]);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004042A0
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x004042D0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004042E0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404310
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetErrorStage(this) != NONE )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404360
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00404380
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00409420
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(ConCommandBase *this)
{
  return 1;
}

} // namespace meshutilstest

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00403D40
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D90
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  int v3; // ecx
  void (__thiscall ***v4)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener_0;
  s_HInstance = nullptr;
  v4 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine(a1: v3);
  (**v4)(a1: v4, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403DD0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403E70
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00403EA0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403ED0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403F20
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00410440
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSteamApplication::PostShutdown()
{
  ;
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00404350
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004043A0
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x004043B0
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404460
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404500
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00404520
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00404530
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404560
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( vgui::BuildGroup::GetResourceName((vgui::BuildGroup *)this) != (char *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004045B0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004045D0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00404610
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004142D0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(vgui::PropertyPage *this)
{
  ;
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004038D0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403920
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403960
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403A20
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403A60
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403AB0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403B10
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x004046B0
// Name: enum SpewRetval_t WinAppDefaultSpewFunc(enum SpewType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl WinAppDefaultSpewFunc(SpewType_t spewType, const char *pMsg)
{
  OutputDebugStringA(lpOutputString: pMsg);
  return spewType >= SPEW_MESSAGE && (spewType <= SPEW_WARNING || spewType == SPEW_LOG);
}

//------------------------------------------------------------------------------
// Address: 0x004046E0
// Name: enum SpewRetval_t ConsoleAppDefaultSpewFunc(enum SpewType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ConsoleAppDefaultSpewFunc(SpewType_t spewType, const char *pMsg)
{
  printf(format: pMsg);
  OutputDebugStringA(lpOutputString: pMsg);
  return spewType >= SPEW_MESSAGE && (spewType <= SPEW_WARNING || spewType == SPEW_LOG);
}

//------------------------------------------------------------------------------
// Address: 0x00404720
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax

  g_DefaultSpewFunc = (SpewRetval_t (__cdecl *)(SpewType_t, const char *))ConsoleAppDefaultSpewFunc;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine_Tier0();
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404760
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[264]; // [esp+0h] [ebp-10Ch] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: &pFileSystemDLL[4], nMaxLen: 260, bSteam: &this->m_bSteam) != FS_OK )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: (IAppSystem *)"VEngineCvar004");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: &pFileSystemDLL[4]);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: (IAppSystem *)"VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", &pFileSystemDLL[4]);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404820
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00404830
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404860
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetErrorStage(this) != NONE )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004048B0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004048D0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004078F0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CBaseAppSystem<IDmSerializers> *this)
{
  ;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00403F50
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403FA0
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  int v3; // ecx
  void (__thiscall ***v4)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener_0;
  s_HInstance = nullptr;
  v4 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine(a1: v3);
  (**v4)(a1: v4, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404080
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x004040B0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404130
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004061B0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CBaseAppSystem<IDmSerializers> *this)
{
  ;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00407B40
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407B90
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00407BD0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407C70
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00407C90
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00407CA0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00407CD0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CDmeTransformControl::GetPositionAttr((CDmeTransformControl *)this) != (CDmAttribute *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00407D20
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00407D40
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00407D80
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace phogen

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00406480
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004064D0
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x004064E0
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // ecx
  int v8; // eax
  char szModuleFilename[264]; // [esp+8h] [ebp-108h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: &szModuleFilename[4], a2: 260);
  v5 = strlen(&szModuleFilename[4]) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", &szModuleFilename[4], lpCmdLine);
  v8 = _CommandLine(a1: v7);
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v8 + 4))(a1: v8, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00406590
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[264]; // [esp+8h] [ebp-108h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: &pFileSystemDLL[4], a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: (IAppSystem *)"VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: &pFileSystemDLL[4]);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: (IAppSystem *)"VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", &pFileSystemDLL[4]);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406630
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00406660
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00406670
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004066A0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( vgui::BuildGroup::GetResourceName((vgui::BuildGroup *)this) != (const char *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004066F0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00406710
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00406750
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412F40
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(vgui::Panel *this)
{
  ;
}

} // namespace QCGenerator

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0041FE80
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FED0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_44F9E4, a2: pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041FF70
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x0041FF90
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041FFB0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0041FFE0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CFileLoaderThread::GetShutdownHandle(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00420030
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00420050
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00420090
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B2A0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSteamApplication::PostShutdown()
{
  ;
}

} // namespace scenemanager

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0040A5E0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A630
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x0040A640
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040A6F0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A790
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x0040A7B0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040A7C0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040A7F0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CDmeTransformControl::GetPositionAttr((vgui::BuildGroup *)this) != (const char *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040A840
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040A860
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x0040A8A0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00408960
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004089B0
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  int v3; // ecx
  void (__thiscall ***v4)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v4 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine(a1: v3);
  (**v4)(a1: v4, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004089F0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: (struct CSysModule *)pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408AB0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00408AC0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00408AF0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CDmeTransformControl::GetPositionAttr((CDmeTransformControl *)this) != (CDmAttribute *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00408B60
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00408BA0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace sfmgen

// ============================================================
// Overlay from ShaderAPITest (Missing functions)
// ============================================================
namespace ShaderAPITest {

//------------------------------------------------------------------------------
// Address: 0x00402670
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CSteamApplication *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00405400
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405450
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x00405460
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00405510
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004055B0
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x004055D0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004055E0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00405610
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00405660
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00405680
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x004056C0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00407850
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(ConCommandBase *this)
{
  return 1;
}

} // namespace ShaderAPITest

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0046EBB0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046EC00
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax
  int savedregs; // [esp+0h] [ebp+0h]

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine(a1: savedregs);
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0046EC40
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CSteamApplication::Create@<al>(CSteamApplication *this@<ecx>, int a2@<ebx>)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v5; // eax
  IFileSystem *v6; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath(a1: a2);
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v5 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v6 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v5, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v6;
  if ( v6 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046ECE0
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __userpurge CSteamApplication::GetFileSystemDLLName@<eax>(
        CSteamApplication *this@<ecx>,
        int a2@<ebx>,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(a1: a2, pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x0046ED00
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046ED10
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CSteamApplication::Main@<eax>(CSteamApplication *this@<ecx>, int a2@<ebx>)
{
  if ( FileSystem_SetBasePaths(a1: a2, pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0046ED40
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CSteamApplication::Startup@<eax>(CSteamApplication *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi

  v3 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v3;
  if ( FileSystem_SetBasePaths(a1: a2, pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0046ED90
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046EDB0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x0046EDF0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace studiomdl

// ============================================================
// Overlay from unittest (Missing functions)
// ============================================================
namespace unittest {

//------------------------------------------------------------------------------
// Address: 0x00401920
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CAppSystemGroup *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00401930
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401980
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  int v3; // ecx
  void (__thiscall ***v4)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v4 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine(a1: v3);
  (**v4)(a1: v4, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004019C0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401A60
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00401A80
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401A90
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(ConCommandBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401AA0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00401AD0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00401B40
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00401B80
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace unittest

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x004120E0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412130
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00412170
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412210
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00412230
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00412240
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00412270
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetCurrentStage(this) != RUNNING )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004122C0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004122E0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00412320
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00403360
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSteamApplication::PostShutdown()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004054D0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405520
// Name: int AppMain(int,char __near * __near *,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(int argc, char **argv, CAppSystemGroup *pAppSystemGroup)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax

  g_pDefaultLoggingListener = &s_SimpleLoggingListener;
  s_HInstance = nullptr;
  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00405560
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_43273C, a2: pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405600
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00405620
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405630
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004056B0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004056D0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00405710
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace vcdupdate

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00401E90
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(vgui::Panel *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0040D550
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D5A0
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x0040D5B0
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040D660
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040D700
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x0040D720
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040D730
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040D760
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( vgui::BuildGroup::GetResourceName((vgui::BuildGroup *)this) != (const char *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040D7B0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040D7D0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x0040D810
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00403DE0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403E40
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[264]; // [esp+8h] [ebp-108h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: &szModuleFilename[4], a2: 260);
  v5 = strlen(&szModuleFilename[4]) + strlen(lpCmdLine) + 4;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", &szModuleFilename[4], lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403EF0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[264]; // [esp+8h] [ebp-108h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: &pFileSystemDLL[4], a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: &pFileSystemDLL[4]);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", &pFileSystemDLL[4]);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403F90
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00403FC0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403FD0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00404070
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042D340
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CFontManager *this)
{
  ;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x004035E0
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403630
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004036E0
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  int Module; // eax
  int v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403780
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x004037A0
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004037B0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004037E0
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( vgui::BuildGroup::GetResourceName((vgui::BuildGroup *)this) != (char *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00403830
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403850
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00403890
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00459A40
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(vgui::PropertyPage *this)
{
  ;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00408430
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408480
// Name: void __near * GetAppInstance(void)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x00408490
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppMain(
        void *hInstance,
        void *hPrevInstance,
        const char *lpCmdLine,
        int nCmdShow,
        CAppSystemGroup *pAppSystemGroup)
{
  unsigned int v5; // edi
  char *v6; // esi
  int v7; // eax
  char szModuleFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pDefaultLoggingListener = &s_SimpleWindowsLoggingListener;
  s_HInstance = hInstance;
  _Plat_GetModuleFilename(a1: szModuleFilename, a2: 260);
  v5 = strlen(szModuleFilename) + strlen(lpCmdLine) + 4;
  v6 = (char *)operator new(nSize: v5);
  _snprintf(string: v6, count: v5, format: "\"%s\" %s", szModuleFilename, lpCmdLine);
  v7 = _CommandLine();
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: v6);
  free(pMem: v6);
  return CAppSystemGroup::Run(this: pAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00408540
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  void *Module; // eax
  void *v4; // eax
  IFileSystem *v5; // eax
  char pFileSystemDLL[260]; // [esp+4h] [ebp-104h] BYREF

  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( !this->GetFileSystemDLLName(this, a2: pFileSystemDLL, a3: 260, a4: &this->m_bSteam) )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  Module = (void *)CAppSystemGroup::LoadModule(this, factory: ICVarFactory);
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VEngineCvar007");
  v4 = (void *)CAppSystemGroup::LoadModule(this, pDLLName: pFileSystemDLL);
  v5 = (IFileSystem *)CAppSystemGroup::AddSystem(this, module: v4, pInterfaceName: "VFileSystem017");
  this->m_pFileSystem = v5;
  if ( v5 == nullptr )
  {
    _Error(a1: "Unable to load %s", pFileSystemDLL);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004085E0
// Name: public: virtual bool CSteamApplication::GetFileSystemDLLName(char __near *,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamApplication::GetFileSystemDLLName(
        CSteamApplication *this,
        char *pOut,
        int nMaxBytes,
        bool *bIsSteam)
{
  return FileSystem_GetFileSystemDLLName(pFileSystemDLL: pOut, nMaxLen: nMaxBytes, bSteam: bIsSteam) == FS_OK;
}

//------------------------------------------------------------------------------
// Address: 0x00408600
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00408610
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00408640
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // edi

  v2 = CAppSystemGroup::Startup(this);
  if ( vgui::BuildGroup::GetResourceName((vgui::BuildGroup *)this) != (char *)6 )
    return v2;
  if ( FileSystem_SetBasePaths(pFileSystem: this->m_pFileSystem) != FS_OK )
    return 0;
  CSteamAppSystemGroup::Setup(
    this: this->m_pChildAppSystemGroup,
    pFileSystem: this->m_pFileSystem,
    pParentAppSystem: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00408690
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004086B0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x004086F0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        CSteamAppSystemGroup *pAppSystemGroup)
{
  CAppSystemGroup::CAppSystemGroup(this, pAppSystemParent: nullptr);
  this->m_pChildAppSystemGroup = pAppSystemGroup;
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

} // namespace vtex_gui
