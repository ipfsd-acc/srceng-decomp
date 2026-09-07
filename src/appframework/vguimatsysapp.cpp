// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: appframework/vguimatsysapp.cpp
// Functions: 6
// ============================================================

#include "appframework\vguimatsysapp.h"

//------------------------------------------------------------------------------
// Address: 0x00404570
// Name: public: virtual bool CVguiMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::Create(CVguiMatSysApp *this)
{
  char result; // al
  AppSystemInfo_t appSystems[4]; // [esp+4h] [ebp-20h] BYREF

  result = CMatSysApp::Create(this);
  if ( result != 0 )
  {
    appSystems[3].m_pModuleName = defaultValue;
    appSystems[3].m_pInterfaceName = defaultValue;
    appSystems[0].m_pModuleName = "inputsystem.dll";
    appSystems[0].m_pInterfaceName = "InputStackSystemVersion001";
    appSystems[1].m_pModuleName = "vguimatsurface.dll";
    appSystems[1].m_pInterfaceName = "VGUI_Surface031";
    appSystems[2].m_pModuleName = "vgui2.dll";
    appSystems[2].m_pInterfaceName = "VGUI_ivgui008";
    return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004045D0
// Name: public: virtual bool CVguiMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PreInit(CVguiMatSysApp *this)
{
  vgui::Panel *v1; // ecx
  void *(__cdecl *factory)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  factory = (void *(__cdecl *)(const char *, int *))this;
  if ( !CMatSysApp::PreInit(this) )
    return 0;
  factory = (void *(__cdecl *)(const char *, int *))CAppSystemGroup::GetFactory();
  CSteamApplication::PostShutdown(this: v1);
  if ( !vgui::VGui_InitInterfacesList(moduleName: "CVguiSteamApp", factoryList: &factory, numFactories: 1) )
    return 0;
  if ( g_pMatSystemSurface == nullptr )
  {
    _Warning(a1: "CVguiMatSysApp::PreInit: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IMatSystemSurface *, int, void *(__cdecl *)(const char *, int *)))g_pMatSystemSurface->EnableWindowsMessages)(
    a1: g_pMatSystemSurface,
    a2: 1,
    a3: factory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404640
// Name: public: virtual bool CVguiMatSysApp::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PostInit(CVguiMatSysApp *this)
{
  InputContextHandle_t__ *v1; // eax

  this->m_hAppInputContext = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  v1 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: v1);
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404690
// Name: public: virtual void CVguiMatSysApp::PreShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PreShutdown(CVguiMatSysApp *this)
{
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: nullptr);
  if ( this->m_hAppInputContext != nullptr )
  {
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004046E0
// Name: public: virtual void CVguiMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PostShutdown(CVguiMatSysApp *this)
{
  CSteamApplication::PostShutdown((vgui::Panel *)this);
  CMatSysApp::PostShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004046F0
// Name: public: CVguiMatSysApp::CVguiMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CVguiMatSysApp *__thiscall CVguiMatSysApp::CVguiMatSysApp(CVguiMatSysApp *this)
{
  CMatSysApp::CMatSysApp(this);
  this->__vftable = (CVguiMatSysApp_vtbl *)&CVguiMatSysApp::`vftable';
  this->m_hAppInputContext = nullptr;
  return this;
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00405BD0
// Name: public: virtual bool CVguiMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::Create(CVguiMatSysApp *this)
{
  char result; // al
  AppSystemInfo_t appSystems[4]; // [esp+4h] [ebp-20h] BYREF

  result = CMatSysApp::Create(this);
  if ( result != 0 )
  {
    appSystems[3].m_pModuleName = defaultValue;
    appSystems[3].m_pInterfaceName = defaultValue;
    appSystems[0].m_pModuleName = "inputsystem.dll";
    appSystems[0].m_pInterfaceName = "InputStackSystemVersion001";
    appSystems[1].m_pModuleName = "vguimatsurface.dll";
    appSystems[1].m_pInterfaceName = "VGUI_Surface031";
    appSystems[2].m_pModuleName = "vgui2.dll";
    appSystems[2].m_pInterfaceName = "VGUI_ivgui008";
    return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405C30
// Name: public: virtual bool CVguiMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PreInit(CVguiMatSysApp *this)
{
  vgui::PropertyPage *v1; // ecx
  void *(__cdecl *factory)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  factory = (void *(__cdecl *)(const char *, int *))this;
  if ( !CMatSysApp::PreInit(this) )
    return 0;
  factory = (void *(__cdecl *)(const char *, int *))CAppSystemGroup::GetFactory();
  CDmeFXClip::OnDestruction(this: v1);
  if ( !vgui::VGui_InitInterfacesList(moduleName: "CVguiSteamApp", factoryList: &factory, numFactories: 1) )
    return 0;
  if ( g_pMatSystemSurface == nullptr )
  {
    _Warning(a1: "CVguiMatSysApp::PreInit: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IMatSystemSurface *, int, void *(__cdecl *)(const char *, int *)))g_pMatSystemSurface->EnableWindowsMessages)(
    a1: g_pMatSystemSurface,
    a2: 1,
    a3: factory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405CA0
// Name: public: virtual bool CVguiMatSysApp::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PostInit(CVguiMatSysApp *this)
{
  InputContextHandle_t__ *v1; // eax

  this->m_hAppInputContext = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  v1 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: v1);
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405CF0
// Name: public: virtual void CVguiMatSysApp::PreShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PreShutdown(CVguiMatSysApp *this)
{
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: nullptr);
  if ( this->m_hAppInputContext != nullptr )
  {
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405D40
// Name: public: virtual void CVguiMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PostShutdown(CVguiMatSysApp *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CMatSysApp::PostShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00405D50
// Name: public: CVguiMatSysApp::CVguiMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CVguiMatSysApp *__thiscall CVguiMatSysApp::CVguiMatSysApp(CVguiMatSysApp *this)
{
  CMatSysApp::CMatSysApp(this);
  this->__vftable = (CVguiMatSysApp_vtbl *)&CVguiMatSysApp::`vftable';
  this->m_hAppInputContext = nullptr;
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00406730
// Name: public: virtual bool CVguiMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::Create(CVguiMatSysApp *this)
{
  char result; // al
  AppSystemInfo_t appSystems[4]; // [esp+4h] [ebp-20h] BYREF

  result = CMatSysApp::Create(this);
  if ( result != 0 )
  {
    appSystems[3].m_pModuleName = defaultValue;
    appSystems[3].m_pInterfaceName = defaultValue;
    appSystems[0].m_pModuleName = "inputsystem.dll";
    appSystems[0].m_pInterfaceName = "InputStackSystemVersion001";
    appSystems[1].m_pModuleName = "vguimatsurface.dll";
    appSystems[1].m_pInterfaceName = "VGUI_Surface031";
    appSystems[2].m_pModuleName = "vgui2.dll";
    appSystems[2].m_pInterfaceName = "VGUI_ivgui008";
    return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406790
// Name: public: virtual bool CVguiMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PreInit(CVguiMatSysApp *this)
{
  vgui::PropertyPage *v1; // ecx
  void *(__cdecl *factory)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  factory = (void *(__cdecl *)(const char *, int *))this;
  if ( !CMatSysApp::PreInit(this) )
    return 0;
  factory = CAppSystemGroup::GetFactory();
  CSteamApplication::PostShutdown(this: v1);
  if ( !vgui::VGui_InitInterfacesList(moduleName: "CVguiSteamApp", factoryList: &factory, numFactories: 1) )
    return 0;
  if ( g_pMatSystemSurface == nullptr )
  {
    _Warning(a1: "CVguiMatSysApp::PreInit: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IMatSystemSurface *, int, void *(__cdecl *)(const char *, int *)))g_pMatSystemSurface->EnableWindowsMessages)(
    a1: g_pMatSystemSurface,
    a2: 1,
    a3: factory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406800
// Name: public: virtual bool CVguiMatSysApp::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PostInit(CVguiMatSysApp *this)
{
  InputContextHandle_t__ *v1; // eax

  this->m_hAppInputContext = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  v1 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: v1);
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406850
// Name: public: virtual void CVguiMatSysApp::PreShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PreShutdown(CVguiMatSysApp *this)
{
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: nullptr);
  if ( this->m_hAppInputContext != nullptr )
  {
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004068A0
// Name: public: virtual void CVguiMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PostShutdown(CVguiMatSysApp *this)
{
  CSteamApplication::PostShutdown((vgui::PropertyPage *)this);
  CMatSysApp::PostShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x004068B0
// Name: public: CVguiMatSysApp::CVguiMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CVguiMatSysApp *__thiscall CVguiMatSysApp::CVguiMatSysApp(CVguiMatSysApp *this)
{
  CMatSysApp::CMatSysApp(this);
  this->__vftable = (CVguiMatSysApp_vtbl *)&CVguiMatSysApp::`vftable';
  this->m_hAppInputContext = nullptr;
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00409EF0
// Name: public: virtual bool CVguiMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::Create(CVguiMatSysApp *this)
{
  char result; // al
  AppSystemInfo_t appSystems[4]; // [esp+4h] [ebp-20h] BYREF

  result = CMatSysApp::Create(this);
  if ( result != 0 )
  {
    appSystems[3].m_pModuleName = defaultValue;
    appSystems[3].m_pInterfaceName = defaultValue;
    appSystems[0].m_pModuleName = "inputsystem.dll";
    appSystems[0].m_pInterfaceName = "InputStackSystemVersion001";
    appSystems[1].m_pModuleName = "vguimatsurface.dll";
    appSystems[1].m_pInterfaceName = "VGUI_Surface031";
    appSystems[2].m_pModuleName = "vgui2.dll";
    appSystems[2].m_pInterfaceName = "VGUI_ivgui008";
    return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409F50
// Name: public: virtual bool CVguiMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PreInit(CVguiMatSysApp *this)
{
  vgui::PropertyPage *v1; // ecx
  void *(__cdecl *factory)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  factory = (void *(__cdecl *)(const char *, int *))this;
  if ( !CMatSysApp::PreInit(this) )
    return 0;
  factory = (void *(__cdecl *)(const char *, int *))CAppSystemGroup::GetFactory();
  CDmeFXClip::OnDestruction(this: v1);
  if ( !vgui::VGui_InitInterfacesList(moduleName: "CVguiSteamApp", factoryList: &factory, numFactories: 1) )
    return 0;
  if ( g_pMatSystemSurface == nullptr )
  {
    _Warning(a1: "CVguiMatSysApp::PreInit: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IMatSystemSurface *, int, void *(__cdecl *)(const char *, int *)))g_pMatSystemSurface->EnableWindowsMessages)(
    a1: g_pMatSystemSurface,
    a2: 1,
    a3: factory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409FC0
// Name: public: virtual bool CVguiMatSysApp::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PostInit(CVguiMatSysApp *this)
{
  InputContextHandle_t__ *v1; // eax

  this->m_hAppInputContext = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  v1 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: v1);
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A010
// Name: public: virtual void CVguiMatSysApp::PreShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PreShutdown(CVguiMatSysApp *this)
{
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: nullptr);
  if ( this->m_hAppInputContext != nullptr )
  {
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A060
// Name: public: virtual void CVguiMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PostShutdown(CVguiMatSysApp *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CMatSysApp::PostShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040A070
// Name: public: CVguiMatSysApp::CVguiMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CVguiMatSysApp *__thiscall CVguiMatSysApp::CVguiMatSysApp(CVguiMatSysApp *this)
{
  CMatSysApp::CMatSysApp(this);
  this->__vftable = (CVguiMatSysApp_vtbl *)&CVguiMatSysApp::`vftable';
  this->m_hAppInputContext = nullptr;
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0040FE40
// Name: public: virtual bool CVguiMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::Create(CVguiMatSysApp *this)
{
  char result; // al
  AppSystemInfo_t appSystems[4]; // [esp+4h] [ebp-20h] BYREF

  result = CMatSysApp::Create(this);
  if ( result != 0 )
  {
    appSystems[3].m_pModuleName = &defaultValue;
    appSystems[3].m_pInterfaceName = &defaultValue;
    appSystems[0].m_pModuleName = "inputsystem.dll";
    appSystems[0].m_pInterfaceName = "InputStackSystemVersion001";
    appSystems[1].m_pModuleName = "vguimatsurface.dll";
    appSystems[1].m_pInterfaceName = "VGUI_Surface031";
    appSystems[2].m_pModuleName = "vgui2.dll";
    appSystems[2].m_pInterfaceName = "VGUI_ivgui008";
    return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FEA0
// Name: public: virtual bool CVguiMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CVguiMatSysApp::PreInit@<al>(CVguiMatSysApp *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v2; // ecx
  void *(__cdecl *factory)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  factory = (void *(__cdecl *)(const char *, int *))this;
  if ( CMatSysApp::PreInit(this, a2) == 0 )
    return 0;
  factory = CAppSystemGroup::GetFactory();
  CSteamApplication::PostShutdown(this: v2);
  if ( !vgui::VGui_InitInterfacesList(moduleName: "CVguiSteamApp", factoryList: &factory, numFactories: 1) )
    return 0;
  if ( g_pMatSystemSurface == nullptr )
  {
    _Warning(a1: "CVguiMatSysApp::PreInit: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IMatSystemSurface *, int, void *(__cdecl *)(const char *, int *)))g_pMatSystemSurface->EnableWindowsMessages)(
    a1: g_pMatSystemSurface,
    a2: 1,
    a3: factory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FF10
// Name: public: virtual bool CVguiMatSysApp::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PostInit(CVguiMatSysApp *this)
{
  InputContextHandle_t__ *v1; // eax

  this->m_hAppInputContext = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  v1 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: v1);
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FF60
// Name: public: virtual void CVguiMatSysApp::PreShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PreShutdown(CVguiMatSysApp *this)
{
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: nullptr);
  if ( this->m_hAppInputContext != nullptr )
  {
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FFB0
// Name: public: virtual void CVguiMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PostShutdown(CVguiMatSysApp *this)
{
  CSteamApplication::PostShutdown((vgui::Panel *)this);
  CMatSysApp::PostShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040FFC0
// Name: public: CVguiMatSysApp::CVguiMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CVguiMatSysApp *__thiscall CVguiMatSysApp::CVguiMatSysApp(CVguiMatSysApp *this)
{
  CMatSysApp::CMatSysApp(this);
  this->__vftable = (CVguiMatSysApp_vtbl *)&CVguiMatSysApp::`vftable';
  this->m_hAppInputContext = nullptr;
  return this;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004060A0
// Name: public: virtual bool CVguiMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::Create(CVguiMatSysApp *this)
{
  char result; // al
  AppSystemInfo_t appSystems[4]; // [esp+0h] [ebp-24h] BYREF
  const char *v4; // [esp+20h] [ebp-4h]

  result = CMatSysApp::Create(this);
  if ( result != 0 )
  {
    appSystems[3].m_pInterfaceName = defaultValue;
    v4 = defaultValue;
    appSystems[0].m_pInterfaceName = "inputsystem.dll";
    appSystems[1].m_pModuleName = "InputStackSystemVersion001";
    appSystems[1].m_pInterfaceName = "vguimatsurface.dll";
    appSystems[2].m_pModuleName = "VGUI_Surface031";
    appSystems[2].m_pInterfaceName = "vgui2.dll";
    appSystems[3].m_pModuleName = "VGUI_ivgui008";
    return CAppSystemGroup::AddSystems(this, pSystemList: (AppSystemInfo_t *)&appSystems[0].m_pInterfaceName);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406110
// Name: public: virtual bool CVguiMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PreInit(CVguiMatSysApp *this)
{
  CFontManager *v1; // ecx
  void *(__cdecl *factoryList)(const char *, int *); // [esp+4h] [ebp-4h] BYREF

  factoryList = (void *(__cdecl *)(const char *, int *))this;
  if ( !CMatSysApp::PreInit(this) )
    return 0;
  factoryList = CAppSystemGroup::GetFactory();
  CSteamApplication::PostShutdown(this: v1);
  if ( !vgui::VGui_InitInterfacesList(moduleName: "CVguiSteamApp", &factoryList, numFactories: 1) )
    return 0;
  if ( g_pMatSystemSurface == nullptr )
  {
    _Warning(a1: "CVguiMatSysApp::PreInit: Unable to connect to necessary interface!\n");
    return 0;
  }
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406180
// Name: public: virtual bool CVguiMatSysApp::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVguiMatSysApp::PostInit(CVguiMatSysApp *this)
{
  InputContextHandle_t__ *v1; // eax

  this->m_hAppInputContext = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  v1 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: v1);
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004061D0
// Name: public: virtual void CVguiMatSysApp::PreShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PreShutdown(CVguiMatSysApp *this)
{
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: nullptr);
  if ( this->m_hAppInputContext != nullptr )
  {
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406220
// Name: public: virtual void CVguiMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVguiMatSysApp::PostShutdown(CVguiMatSysApp *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  CMatSysApp::PostShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00406230
// Name: public: CVguiMatSysApp::CVguiMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CVguiMatSysApp *__thiscall CVguiMatSysApp::CVguiMatSysApp(CVguiMatSysApp *this)
{
  CMatSysApp::CMatSysApp(this);
  this->__vftable = (CVguiMatSysApp_vtbl *)&CVguiMatSysApp::`vftable';
  this->m_hAppInputContext = nullptr;
  return this;
}

} // namespace vgui_perftest
