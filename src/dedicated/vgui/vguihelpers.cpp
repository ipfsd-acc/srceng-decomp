// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/vgui/vguihelpers.cpp
// Functions: 16
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10027810
// Name: int StartVGUI(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
int __usercall StartVGUI@<eax>(int a1@<edi>, int a2@<esi>, void *(__cdecl *dedicatedFactory)(const char *, int *))
{
  const char *v3; // eax
  CMainPanel *v4; // eax
  CMainPanel *v5; // eax
  CMainPanel_vtbl *v6; // edx
  vgui::ISurface *v7; // esi
  vgui::ISurface_vtbl *v8; // edi
  int v9; // eax
  CSysModule *v10; // eax
  IVGuiModule *v11; // eax
  IVGuiModule_vtbl *v12; // esi
  int v13; // eax
  char szConfigDir[512]; // [esp+0h] [ebp-204h] BYREF
  void *(__cdecl *adminFactory)(const char *, int *); // [esp+200h] [ebp-4h] BYREF

  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "MAIN", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "platform", a3: "PLATFORM", a4: PATH_ADD_TO_HEAD);
  g_pVGui->SetSleep(this: g_pVGui, a2: false);
  v3 = getenv(option: "SteamInstallPath");
  if ( v3 != nullptr )
    V_snprintf(pDest: szConfigDir, maxLen: 512, pFormat: "%s/config", v3);
  else
    V_strncpy(pDest: szConfigDir, pSrc: "platform/config", maxLen: 512);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: "config", a3: "PLATFORM");
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: szConfigDir, a3: "CONFIG", a4: PATH_ADD_TO_HEAD);
  g_pVGuiSystem->SetUserConfigFile(this: g_pVGuiSystem, a2: "DedicatedServerDialogConfig.vdf", a3: "CONFIG");
  v4 = (CMainPanel *)operator new(nSize: 0x2A4u);
  if ( v4 != nullptr )
    v5 = CMainPanel::CMainPanel(this: v4);
  else
    v5 = nullptr;
  v6 = v5->__vftable;
  g_pMainPanel = v5;
  ((void (__thiscall *)(CMainPanel *, int, int, int))v6->SetVisible)(a1: v5, a2: 1, a3: a1, a4: a2);
  v7 = g_pVGuiSurface;
  v8 = g_pVGuiSurface->__vftable;
  v9 = g_pMainPanel->GetVPanel(this: g_pMainPanel);
  v8->SetEmbeddedPanel(this: v7, a2: v9);
  g_pVGuiSchemeManager->LoadSchemeFromFile(
    this: g_pVGuiSchemeManager,
    a2: "Resource/SourceScheme.res",
    a3: "SourceScheme");
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/platform_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/vgui_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Admin/server_%language%.txt", a3: nullptr, a4: false);
  g_pVGui->Start(this: g_pVGui);
  g_pFullFileSystem->GetLocalCopy(this: g_pFullFileSystem, a2: "bin/AdminServer.dll");
  v10 = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: "AdminServer", a3: 0, a4: 1);
  g_hAdminServerModule = v10;
  adminFactory = nullptr;
  if ( v10 == nullptr
    || (adminFactory = Sys_GetFactory(pModule: v10),
        g_pAdminServer = (IAdminServer *)adminFactory(a1: "AdminServer002", a2: nullptr),
        v11 = (IVGuiModule *)adminFactory(a1: "VGuiModuleAdminServer001", a2: nullptr),
        g_pAdminVGuiModule = v11,
        g_pAdminServer == nullptr)
    || v11 == nullptr )
  {
    g_pVGui->DPrintf2(
      this: g_pVGui,
      a2: "Admin Error: module version (Admin/AdminServer.dll, %s) invalid, not loading\n",
      "IManageServer002");
    v11 = g_pAdminVGuiModule;
  }
  v11->Initialize(this: v11, a2: &dedicatedFactory, a3: 1);
  g_pAdminVGuiModule->PostInitialize(this: g_pAdminVGuiModule, a2: &adminFactory, a3: 1);
  v12 = g_pAdminVGuiModule->__vftable;
  v13 = g_pMainPanel->GetVPanel(this: g_pMainPanel);
  v12->SetParent(this: g_pAdminVGuiModule, a2: v13);
  g_pMainPanel->Initialize(this: g_pMainPanel);
  g_pMainPanel->Open(this: g_pMainPanel);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10027AA0
// Name: void StopVGUI(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StopVGUI()
{
  SetEvent(hEvent: g_pMainPanel->m_hShutdown);
  if ( g_pMainPanel != nullptr )
    ((void (__thiscall *)(CMainPanel *, int))g_pMainPanel->dtr_Panel)(a1: g_pMainPanel, a2: 1);
  g_pMainPanel = nullptr;
  if ( g_hAdminServerModule != nullptr )
  {
    g_pAdminVGuiModule->Shutdown(this: g_pAdminVGuiModule);
    Sys_UnloadModule(pModule: g_hAdminServerModule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027B00
// Name: void RunVGUIFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunVGUIFrame()
{
  g_pVGui->RunFrame(this: g_pVGui);
}

//------------------------------------------------------------------------------
// Address: 0x10027B10
// Name: bool VGUIIsStopping(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VGUIIsStopping()
{
  return g_pMainPanel->m_bClosing;
}

//------------------------------------------------------------------------------
// Address: 0x10027B20
// Name: bool VGUIIsRunning(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VGUIIsRunning()
{
  return g_pVGui->IsRunning(this: g_pVGui);
}

//------------------------------------------------------------------------------
// Address: 0x10027B30
// Name: bool VGUIIsInConfig(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VGUIIsInConfig()
{
  return g_pMainPanel->m_bIsInConfig;
}

//------------------------------------------------------------------------------
// Address: 0x10027B40
// Name: void VGUIFinishedConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGUIFinishedConfig()
{
  if ( g_pMainPanel != nullptr )
    SetEvent(hEvent: g_pMainPanel->m_hShutdown);
}

//------------------------------------------------------------------------------
// Address: 0x10027B60
// Name: void VGUIPrintf(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGUIPrintf(const char *msg)
{
  if ( g_pMainPanel == nullptr || g_pMainPanel->m_bIsInConfig || g_pMainPanel->m_bClosing )
    MessageBoxA(hWnd: nullptr, lpText: msg, lpCaption: "Dedicated Server Message", uType: 0x40000u);
  else
    CMainPanel::AddConsoleText(this: g_pMainPanel, msg);
}

//------------------------------------------------------------------------------
// Address: 0x10027BA2
// Name: ntohs(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
u_short __stdcall ntohs(u_short netshort)
{
  return __imp__ntohs@4(netshort);
}

//------------------------------------------------------------------------------
// Address: 0x10027BA8
// Name: gethostbyname(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
struct hostent *__stdcall gethostbyname(const char *name)
{
  return __imp__gethostbyname@4(name);
}

//------------------------------------------------------------------------------
// Address: 0x10027BAE
// Name: inet_addr(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int __stdcall inet_addr(const char *cp)
{
  return __imp__inet_addr@4(cp);
}

//------------------------------------------------------------------------------
// Address: 0x10027BB4
// Name: htons(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
u_short __stdcall htons(u_short hostshort)
{
  return __imp__htons@4(hostshort);
}

//------------------------------------------------------------------------------
// Address: 0x10027BBA
// Name: getsockname(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall getsockname(SOCKET s, struct sockaddr *name, int *namelen)
{
  return __imp__getsockname@12(s, name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x10027BC0
// Name: gethostname(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall gethostname(char *name, int namelen)
{
  return __imp__gethostname@8(name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x10027BC6
// Name: WSAStartup(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData)
{
  return __imp__WSAStartup@8(wVersionRequested, lpWSAData);
}

//------------------------------------------------------------------------------
// Address: 0x10027BCC
// Name: WSACleanup()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall WSACleanup()
{
  return __imp__WSACleanup@0();
}
