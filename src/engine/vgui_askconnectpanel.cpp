// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vgui_askconnectpanel.cpp
// Functions: 21
// ============================================================

#include "engine\vgui_askconnectpanel.h"

//------------------------------------------------------------------------------
// Address: 0x101EF370
// Name: public: static char const __near * CAskConnectPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAskConnectPanel::GetPanelClassName()
{
  return "CAskConnectPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101EF380
// Name: public: void CAskConnectPanel::SetHostName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAskConnectPanel::SetHostName(CAskConnectPanel *this, const char *pHostName)
{
  const char *v2; // edi
  vgui::ILocalize_vtbl *v4; // edi
  int v5; // eax
  const char *v6; // eax
  int m_OriginalWidth; // edx
  int v8; // [esp-4h] [ebp-428h]
  wchar_t wcMessage[512]; // [esp+8h] [ebp-41Ch] BYREF
  int y; // [esp+408h] [ebp-1Ch] BYREF
  int y2; // [esp+40Ch] [ebp-18h] BYREF
  int tall2; // [esp+410h] [ebp-14h] BYREF
  int tall; // [esp+414h] [ebp-10h] BYREF
  int x; // [esp+418h] [ebp-Ch] BYREF
  int x2; // [esp+41Ch] [ebp-8h] BYREF
  int wide; // [esp+420h] [ebp-4h] BYREF

  v2 = pHostName;
  V_strncpy(pDest: this->m_HostName, pSrc: pHostName, maxLen: 256);
  this->m_pHostNameLabel->SetText(this: this->m_pHostNameLabel, a2: v2);
  this->m_pHostNameLabel->SizeToContents(this: this->m_pHostNameLabel);
  vgui::Panel::GetBounds(this: this->m_pHostNameLabel, &x, &y, &wide, &tall);
  v4 = g_pVGuiLocalize->__vftable;
  v5 = ((int (__thiscall *)(vgui::ILocalize *, const char *, _DWORD))g_pVGuiLocalize->Find)(
         a1: g_pVGuiLocalize,
         a2: "#Valve_ServerOfferingToConnect",
         a3: 0);
  ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v4->ConstructString_3)(
    a1: g_pVGuiLocalize,
    a2: wcMessage,
    a3: 1024,
    a4: v5);
  ((void (__thiscall *)(vgui::Label *, wchar_t *, _DWORD, int))this->m_pInfoLabel->SetText)(
    a1: this->m_pInfoLabel,
    a2: wcMessage,
    a3: 0,
    a4: v8);
  this->m_pInfoLabel->SizeToContents(this: this->m_pInfoLabel);
  vgui::Panel::GetBounds(this: this->m_pInfoLabel, x: &x2, y: &y2, wide: (int *)&pHostName, tall: &tall2);
  v6 = &pHostName[x2];
  if ( x + wide > (int)&pHostName[x2] )
    v6 = (const char *)(x + wide);
  m_OriginalWidth = (int)&v6[this->m_HostNameLabelRightSidePadding];
  if ( m_OriginalWidth < this->m_OriginalWidth )
    m_OriginalWidth = this->m_OriginalWidth;
  vgui::Panel::SetWide(this, wide: m_OriginalWidth);
}

//------------------------------------------------------------------------------
// Address: 0x101EF490
// Name: public: virtual void CAskConnectPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAskConnectPanel::ApplySchemeSettings(CAskConnectPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(CAskConnectPanel *, _DWORD))this->SetBgColor)(a1: this, a2: *(_DWORD *)&this->m_bgColor);
  this->SetPaintBackgroundType(this, a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x101EF4D0
// Name: void SetupDefaultAskConnectAcceptKey(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultAskConnectAcceptKey()
{
  if ( Key_NameForBinding(pBinding: "askconnect_accept", userId: -1, iStartCount: 0, iAllowJoystick: -1) == nullptr
    && Key_BindingForKey(code: KEY_F3) == nullptr )
  {
    Key_SetBinding(keynum: KEY_F3, pBinding: "askconnect_accept");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF510
// Name: void HideAskConnectPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HideAskConnectPanel()
{
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx

  if ( CAskConnectPanel::s_pAskConnectPanel != nullptr )
  {
    SetVisible = CAskConnectPanel::s_pAskConnectPanel->SetVisible;
    CAskConnectPanel::s_pAskConnectPanel->m_flAnimationEndTime = -1.0;
    ((void (__stdcall *)(_DWORD))SetVisible)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF540
// Name: bool IsAskConnectPanelActive(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsAskConnectPanelActive(char *pHostName, int maxHostNameBytes)
{
  CAskConnectPanel *v2; // esi

  v2 = CAskConnectPanel::s_pAskConnectPanel;
  if ( CAskConnectPanel::s_pAskConnectPanel == nullptr
    || !CAskConnectPanel::s_pAskConnectPanel->IsVisible(this: CAskConnectPanel::s_pAskConnectPanel)
    || vgui::Panel::GetAlpha(this: v2) <= 0 )
  {
    return 0;
  }
  V_strncpy(pDest: pHostName, pSrc: v2->m_HostName, maxLen: maxHostNameBytes);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EF590
// Name: public: virtual struct vgui::PanelMessageMap __near * CAskConnectPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAskConnectPanel::GetMessageMap(CAskConnectPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAskConnectPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAskConnectPanel::GetMessageMap'::`2'::s_pMap;
  `CAskConnectPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAskConnectPanel");
  `CAskConnectPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF5C0
// Name: public: virtual struct PanelAnimationMap __near * CAskConnectPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAskConnectPanel::GetAnimMap(CAskConnectPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAskConnectPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101EF5D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAskConnectPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAskConnectPanel::GetKBMap(CAskConnectPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAskConnectPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAskConnectPanel::GetKBMap'::`2'::s_pMap;
  `CAskConnectPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAskConnectPanel");
  `CAskConnectPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF600
// Name: public: CAskConnectPanel::CAskConnectPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAskConnectPanel *__thiscall CAskConnectPanel::CAskConnectPanel(CAskConnectPanel *this, unsigned int parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Label *v6; // eax
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  vgui::Label *v10; // eax
  vgui::Label *v11; // eax
  unsigned int vpanel; // edx
  vgui::AnimationController *v13; // eax
  vgui::AnimationController *v14; // eax
  int v15; // eax
  int y; // [esp+8h] [ebp-10h] BYREF
  int tall; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: nullptr, panelName: "AskConnectPanel");
  this->__vftable = (CAskConnectPanel_vtbl *)&CAskConnectPanel::`vftable';
  if ( `CAskConnectPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAskConnectPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAskConnectPanel");
    v3->pfnClassName = CAskConnectPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CAskConnectPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAskConnectPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAskConnectPanel");
    v4->pfnClassName = CAskConnectPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CAskConnectPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAskConnectPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAskConnectPanel");
    v5->pfnClassName = CAskConnectPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_bgColor = (Color)-1073741824;
  vgui::Panel::SetParent(this, newParent: parent);
  CAskConnectPanel::s_pAskConnectPanel = this;
  this->m_flAnimationEndTime = -1.0;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  vgui::Panel::SetVisible(this, state: false);
  v6 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v6 != nullptr )
    v7 = vgui::Label::Label(this: v6, parent: this, panelName: "HostNameLabel", text: defaultValue);
  else
    v7 = nullptr;
  this->m_pHostNameLabel = v7;
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: "AcceptLabel", text: defaultValue);
  else
    v9 = nullptr;
  this->m_pAcceptLabel = v9;
  v10 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v10 != nullptr )
    v11 = vgui::Label::Label(this: v10, parent: this, panelName: "InfoLabel", text: defaultValue);
  else
    v11 = nullptr;
  vpanel = this->_vpanel;
  this->m_pInfoLabel = v11;
  this->m_HostName[0] = 0;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  vgui::Panel::SetAutoDelete(this, state: true);
  v13 = (vgui::AnimationController *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v13 != nullptr )
    v14 = vgui::AnimationController::AnimationController(this: v13, parent: nullptr);
  else
    v14 = nullptr;
  this->m_pAnimationController = v14;
  v14->SetParent(this: v14, a2: parent);
  vgui::AnimationController::SetScriptFile(
    this: this->m_pAnimationController,
    sizingPanel: parent,
    fileName: "scripts/plugin_animations.txt",
    wipeAll: false);
  this->m_pAnimationController->SetProportional(this: this->m_pAnimationController, a2: false);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource\\askconnectpanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::InvalidateLayout(this, layoutNow: true, reloadScheme: false);
  this->m_OriginalWidth = vgui::Panel::GetWide(this);
  vgui::Panel::GetBounds(this: this->m_pHostNameLabel, &x, &y, &wide, &tall);
  v15 = vgui::Panel::GetWide(this);
  this->m_HostNameLabelRightSidePadding = v15 - x - wide;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EF8A0
// Name: public: virtual void CAskConnectPanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAskConnectPanel::ApplySettings(CAskConnectPanel *this, KeyValues *inResourceData)
{
  const char *String; // eax
  int a; // [esp+8h] [ebp-10h] BYREF
  int b; // [esp+Ch] [ebp-Ch] BYREF
  int g; // [esp+10h] [ebp-8h] BYREF
  int r; // [esp+14h] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+20h] [ebp+8h]

  vgui::EditablePanel::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "BgColor", defaultValue: nullptr);
  if ( String != nullptr && sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) == 4 )
  {
    LOBYTE(inResourceDataa) = r;
    BYTE2(inResourceDataa) = b;
    BYTE1(inResourceDataa) = g;
    HIBYTE(inResourceDataa) = a;
    this->m_bgColor = (Color)inResourceDataa;
    ((void (__thiscall *)(CAskConnectPanel *, KeyValues *))this->SetBgColor)(a1: this, a2: inResourceDataa);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF920
// Name: public: void CAskConnectPanel::StartSlideAnimation(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAskConnectPanel::StartSlideAnimation(CAskConnectPanel *this, float flDuration)
{
  const char *v3; // eax
  vgui::ILocalize_vtbl *v4; // edi
  int v5; // eax
  int v6; // [esp-8h] [ebp-49Ch]
  wchar_t wcMessage[512]; // [esp+8h] [ebp-48Ch] BYREF
  wchar_t wcKeyName[64]; // [esp+408h] [ebp-8Ch] BYREF
  int wide; // [esp+488h] [ebp-Ch] BYREF
  int x; // [esp+48Ch] [ebp-8h] BYREF
  int y; // [esp+490h] [ebp-4h] BYREF

  this->m_flAnimationEndTime = _Plat_FloatTime() + flDuration;
  v3 = Key_NameForBinding(pBinding: "askconnect_accept", userId: -1, iStartCount: 0, iAllowJoystick: -1);
  if ( v3 != nullptr )
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v3, a3: wcKeyName, a4: 128);
    v4 = g_pVGuiLocalize->__vftable;
    v5 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
           a1: g_pVGuiLocalize,
           a2: "#Valve_PressKeyToAccept",
           a3: 1,
           a4: wcKeyName);
    ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v4->ConstructString_3)(
      a1: g_pVGuiLocalize,
      a2: wcMessage,
      a3: 1024,
      a4: v5);
    ((void (__thiscall *)(vgui::Label *, wchar_t *, _DWORD, int))this->m_pAcceptLabel->SetText)(
      a1: this->m_pAcceptLabel,
      a2: wcMessage,
      a3: 0,
      a4: v6);
  }
  else
  {
    this->m_pAcceptLabel->SetText(this: this->m_pAcceptLabel, a2: "#Valve_BindKeyToAccept");
  }
  vgui::AnimationController::StartAnimationSequence(this: this->m_pAnimationController, sequenceName: "AskConnectShow");
  this->SetVisible(this, a2: true);
  this->InvalidateLayout(this, a2: false, a3: false);
  x = 0;
  y = 0;
  wide = 0;
  flDuration = 0.0;
  if ( g_PluginManager != nullptr )
    CPluginUIManager::GetHudMessagePosition(this: g_PluginManager, &x, &y, &wide, tall: (int *)&flDuration);
  vgui::Panel::SetPos(this, x, y: y + LODWORD(flDuration));
}

//------------------------------------------------------------------------------
// Address: 0x101EFA50
// Name: public: virtual void CAskConnectPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAskConnectPanel::OnTick(CAskConnectPanel *this)
{
  vgui::AnimationController *m_pAnimationController; // ecx
  float v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+Ch] [ebp-10h] BYREF
  int wide; // [esp+10h] [ebp-Ch] BYREF
  int x; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  if ( this->m_flAnimationEndTime != -1.0 && _Plat_FloatTime() > this->m_flAnimationEndTime )
  {
    m_pAnimationController = this->m_pAnimationController;
    this->m_flAnimationEndTime = -1.0;
    vgui::AnimationController::StartAnimationSequence(this: m_pAnimationController, sequenceName: "AskConnectHide");
  }
  v3 = _Plat_FloatTime();
  vgui::AnimationController::UpdateAnimations(this: this->m_pAnimationController, currentTime: v3);
  if ( vgui::Panel::GetAlpha(this) == 0 )
    this->SetVisible(this, a2: false);
  if ( this->IsVisible(this) )
  {
    wide = 0;
    x = 0;
    v4 = 0;
    y = 0;
    if ( g_PluginManager != nullptr )
      CPluginUIManager::GetHudMessagePosition(this: g_PluginManager, x: &wide, y: &x, wide: &v4, tall: &y);
    vgui::Panel::SetPos(this, x: wide, y: x + y);
  }
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101EFB60
// Name: void ShowAskConnectPanel(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowAskConnectPanel(const char *pHostName, float flDuration)
{
  CAskConnectPanel *v2; // esi

  v2 = CAskConnectPanel::s_pAskConnectPanel;
  if ( CAskConnectPanel::s_pAskConnectPanel != nullptr )
  {
    CAskConnectPanel::SetHostName(this: CAskConnectPanel::s_pAskConnectPanel, pHostName);
    CAskConnectPanel::StartSlideAnimation(this: v2, flDuration);
    v2->MoveToFront(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103125C0
// Name: _dynamic_initializer_for__askconnect_accept__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__askconnect_accept__()
{
  ConCommand::ConCommand(
    this: &askconnect_accept,
    pName: "askconnect_accept",
    callback: askconnect_accept_f,
    pHelpString: "Accept a redirect request by the server.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__askconnect_accept__);
}

//------------------------------------------------------------------------------
// Address: 0x103135E0
// Name: _dynamic_initializer_for__connect_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__connect_command__()
{
  ConCommand::ConCommand(
    this: &connect_command,
    pName: "connect",
    callback: (void (__cdecl *)())connect_0,
    pHelpString: "Connect to specified server.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__connect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313610
// Name: _dynamic_initializer_for__connect_splitscreen_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__connect_splitscreen_command__()
{
  ConCommand::ConCommand(
    this: &connect_splitscreen_command,
    pName: "connect_splitscreen",
    callback: (void (__cdecl *)())connect_splitscreen,
    pHelpString: "Connect to specified server. With multiple players.",
    flags: 655376,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__connect_splitscreen_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103221A0
// Name: _dynamic_atexit_destructor_for__askconnect_accept__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__askconnect_accept__()
{
  ConCommand::~ConCommand(this: &askconnect_accept);
}

//------------------------------------------------------------------------------
// Address: 0x10322770
// Name: _dynamic_atexit_destructor_for__connect_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__connect_command__()
{
  ConCommand::~ConCommand(this: &connect_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322780
// Name: _dynamic_atexit_destructor_for__connect_splitscreen_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__connect_splitscreen_command__()
{
  ConCommand::~ConCommand(this: &connect_splitscreen_command);
}

//------------------------------------------------------------------------------
// Address: 0x101EFBD0
// Name: __CreateCVoiceServerIVoiceServer_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVoiceServer *__cdecl _CreateCVoiceServerIVoiceServer_interface()
{
  return &_g_CVoiceServer_singleton;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101EF620
// Name: public: static char const __near * CAskConnectPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAskConnectPanel::GetPanelClassName()
{
  return "CAskConnectPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101EF630
// Name: public: void CAskConnectPanel::SetHostName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAskConnectPanel::SetHostName(CAskConnectPanel *this, const char *pHostName)
{
  const char *v2; // edi
  vgui::ILocalize_vtbl *v4; // edi
  int v5; // eax
  const char *v6; // eax
  int m_OriginalWidth; // edx
  int v8; // [esp-4h] [ebp-428h]
  wchar_t wcMessage[512]; // [esp+8h] [ebp-41Ch] BYREF
  int y; // [esp+408h] [ebp-1Ch] BYREF
  int y2; // [esp+40Ch] [ebp-18h] BYREF
  int tall2; // [esp+410h] [ebp-14h] BYREF
  int tall; // [esp+414h] [ebp-10h] BYREF
  int x; // [esp+418h] [ebp-Ch] BYREF
  int x2; // [esp+41Ch] [ebp-8h] BYREF
  int wide; // [esp+420h] [ebp-4h] BYREF

  v2 = pHostName;
  V_strncpy(pDest: this->m_HostName, pSrc: pHostName, maxLen: 256);
  this->m_pHostNameLabel->SetText(this: this->m_pHostNameLabel, a2: v2);
  this->m_pHostNameLabel->SizeToContents(this: this->m_pHostNameLabel);
  vgui::Panel::GetBounds(this: this->m_pHostNameLabel, &x, &y, &wide, &tall);
  v4 = g_pVGuiLocalize->__vftable;
  v5 = ((int (__thiscall *)(vgui::ILocalize *, const char *, _DWORD))g_pVGuiLocalize->Find)(
         a1: g_pVGuiLocalize,
         a2: "#Valve_ServerOfferingToConnect",
         a3: 0);
  ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v4->ConstructString_3)(
    a1: g_pVGuiLocalize,
    a2: wcMessage,
    a3: 1024,
    a4: v5);
  ((void (__thiscall *)(vgui::Label *, wchar_t *, _DWORD, int))this->m_pInfoLabel->SetText)(
    a1: this->m_pInfoLabel,
    a2: wcMessage,
    a3: 0,
    a4: v8);
  this->m_pInfoLabel->SizeToContents(this: this->m_pInfoLabel);
  vgui::Panel::GetBounds(this: this->m_pInfoLabel, x: &x2, y: &y2, wide: (int *)&pHostName, tall: &tall2);
  v6 = &pHostName[x2];
  if ( x + wide > (int)&pHostName[x2] )
    v6 = (const char *)(x + wide);
  m_OriginalWidth = (int)&v6[this->m_HostNameLabelRightSidePadding];
  if ( m_OriginalWidth < this->m_OriginalWidth )
    m_OriginalWidth = this->m_OriginalWidth;
  vgui::Panel::SetWide(this, wide: m_OriginalWidth);
}

//------------------------------------------------------------------------------
// Address: 0x101EF740
// Name: public: virtual void CAskConnectPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAskConnectPanel::ApplySchemeSettings(CAskConnectPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(CAskConnectPanel *, _DWORD))this->SetBgColor)(a1: this, a2: *(_DWORD *)&this->m_bgColor);
  this->SetPaintBackgroundType(this, a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x101EF780
// Name: void SetupDefaultAskConnectAcceptKey(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultAskConnectAcceptKey()
{
  if ( Key_NameForBinding(pBinding: "askconnect_accept", userId: -1, iStartCount: 0, iAllowJoystick: -1) == nullptr
    && Key_BindingForKey(code: KEY_F3) == nullptr )
  {
    Key_SetBinding(keynum: KEY_F3, pBinding: "askconnect_accept");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF7C0
// Name: void HideAskConnectPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HideAskConnectPanel()
{
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx

  if ( CAskConnectPanel::s_pAskConnectPanel != nullptr )
  {
    SetVisible = CAskConnectPanel::s_pAskConnectPanel->SetVisible;
    CAskConnectPanel::s_pAskConnectPanel->m_flAnimationEndTime = -1.0;
    ((void (__stdcall *)(_DWORD))SetVisible)(a1: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF7F0
// Name: bool IsAskConnectPanelActive(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsAskConnectPanelActive(char *pHostName, int maxHostNameBytes)
{
  CAskConnectPanel *v2; // esi

  v2 = CAskConnectPanel::s_pAskConnectPanel;
  if ( CAskConnectPanel::s_pAskConnectPanel == nullptr
    || !CAskConnectPanel::s_pAskConnectPanel->IsVisible(this: CAskConnectPanel::s_pAskConnectPanel)
    || vgui::Panel::GetAlpha(this: v2) <= 0 )
  {
    return 0;
  }
  V_strncpy(pDest: pHostName, pSrc: v2->m_HostName, maxLen: maxHostNameBytes);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EF840
// Name: public: virtual struct vgui::PanelMessageMap __near * CAskConnectPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAskConnectPanel::GetMessageMap(CAskConnectPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAskConnectPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAskConnectPanel::GetMessageMap'::`2'::s_pMap;
  `CAskConnectPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAskConnectPanel");
  `CAskConnectPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF870
// Name: public: virtual struct PanelAnimationMap __near * CAskConnectPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAskConnectPanel::GetAnimMap(CAskConnectPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAskConnectPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101EF880
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAskConnectPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAskConnectPanel::GetKBMap(CAskConnectPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAskConnectPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAskConnectPanel::GetKBMap'::`2'::s_pMap;
  `CAskConnectPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAskConnectPanel");
  `CAskConnectPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF8B0
// Name: public: CAskConnectPanel::CAskConnectPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CAskConnectPanel *__thiscall CAskConnectPanel::CAskConnectPanel(CAskConnectPanel *this, unsigned int parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Label *v6; // eax
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  vgui::Label *v10; // eax
  vgui::Label *v11; // eax
  unsigned int vpanel; // edx
  vgui::AnimationController *v13; // eax
  vgui::AnimationController *v14; // eax
  int v15; // eax
  int y; // [esp+8h] [ebp-10h] BYREF
  int tall; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: nullptr, panelName: "AskConnectPanel");
  this->__vftable = (CAskConnectPanel_vtbl *)&CAskConnectPanel::`vftable';
  if ( `CAskConnectPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAskConnectPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAskConnectPanel");
    v3->pfnClassName = CAskConnectPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CAskConnectPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAskConnectPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAskConnectPanel");
    v4->pfnClassName = CAskConnectPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CAskConnectPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAskConnectPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAskConnectPanel");
    v5->pfnClassName = CAskConnectPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_bgColor = (Color)-1073741824;
  vgui::Panel::SetParent(this, newParent: parent);
  CAskConnectPanel::s_pAskConnectPanel = this;
  this->m_flAnimationEndTime = -1.0;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  vgui::Panel::SetVisible(this, state: false);
  v6 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v6 != nullptr )
    v7 = vgui::Label::Label(this: v6, parent: this, panelName: "HostNameLabel", text: defaultValue);
  else
    v7 = nullptr;
  this->m_pHostNameLabel = v7;
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: "AcceptLabel", text: defaultValue);
  else
    v9 = nullptr;
  this->m_pAcceptLabel = v9;
  v10 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v10 != nullptr )
    v11 = vgui::Label::Label(this: v10, parent: this, panelName: "InfoLabel", text: defaultValue);
  else
    v11 = nullptr;
  vpanel = this->_vpanel;
  this->m_pInfoLabel = v11;
  this->m_HostName[0] = 0;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  vgui::Panel::SetAutoDelete(this, state: true);
  v13 = (vgui::AnimationController *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v13 != nullptr )
    v14 = vgui::AnimationController::AnimationController(this: v13, parent: nullptr);
  else
    v14 = nullptr;
  this->m_pAnimationController = v14;
  v14->SetParent(this: v14, a2: parent);
  vgui::AnimationController::SetScriptFile(
    this: this->m_pAnimationController,
    sizingPanel: parent,
    fileName: "scripts/plugin_animations.txt",
    wipeAll: false);
  this->m_pAnimationController->SetProportional(this: this->m_pAnimationController, a2: false);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource\\askconnectpanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::InvalidateLayout(this, layoutNow: true, reloadScheme: false);
  this->m_OriginalWidth = vgui::Panel::GetWide(this);
  vgui::Panel::GetBounds(this: this->m_pHostNameLabel, &x, &y, &wide, &tall);
  v15 = vgui::Panel::GetWide(this);
  this->m_HostNameLabelRightSidePadding = v15 - x - wide;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EFB50
// Name: public: virtual void CAskConnectPanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAskConnectPanel::ApplySettings(CAskConnectPanel *this, KeyValues *inResourceData)
{
  char *String; // eax
  int a; // [esp+8h] [ebp-10h] BYREF
  int b; // [esp+Ch] [ebp-Ch] BYREF
  int g; // [esp+10h] [ebp-8h] BYREF
  int r; // [esp+14h] [ebp-4h] BYREF
  KeyValues *inResourceDataa; // [esp+20h] [ebp+8h]

  vgui::EditablePanel::ApplySettings(this, inResourceData);
  String = (char *)KeyValues::GetString(this: inResourceData, keyName: "BgColor", defaultValue: nullptr);
  if ( String != nullptr && sscanf(string: String, format: "%d %d %d %d", &r, &g, &b, &a) == 4 )
  {
    LOBYTE(inResourceDataa) = r;
    BYTE2(inResourceDataa) = b;
    BYTE1(inResourceDataa) = g;
    HIBYTE(inResourceDataa) = a;
    this->m_bgColor = (Color)inResourceDataa;
    ((void (__thiscall *)(CAskConnectPanel *, KeyValues *))this->SetBgColor)(a1: this, a2: inResourceDataa);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EFD00
// Name: public: virtual void CAskConnectPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAskConnectPanel::OnTick(CAskConnectPanel *this)
{
  vgui::AnimationController *m_pAnimationController; // ecx
  float v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+Ch] [ebp-10h] BYREF
  int wide; // [esp+10h] [ebp-Ch] BYREF
  int x; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  if ( this->m_flAnimationEndTime != -1.0 && _Plat_FloatTime((CStatTime *)this) > this->m_flAnimationEndTime )
  {
    m_pAnimationController = this->m_pAnimationController;
    this->m_flAnimationEndTime = -1.0;
    vgui::AnimationController::StartAnimationSequence(this: m_pAnimationController, sequenceName: "AskConnectHide");
  }
  v3 = _Plat_FloatTime((CStatTime *)this);
  vgui::AnimationController::UpdateAnimations(this: this->m_pAnimationController, currentTime: v3);
  if ( vgui::Panel::GetAlpha(this) == 0 )
    this->SetVisible(this, a2: false);
  if ( this->IsVisible(this) )
  {
    wide = 0;
    x = 0;
    v4 = 0;
    y = 0;
    if ( g_PluginManager != nullptr )
      CPluginUIManager::GetHudMessagePosition(this: g_PluginManager, x: &wide, y: &x, wide: &v4, tall: &y);
    vgui::Panel::SetPos(this, x: wide, y: x + y);
  }
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101EFE10
// Name: void ShowAskConnectPanel(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowAskConnectPanel(const char *pHostName, float flDuration)
{
  CAskConnectPanel *v2; // esi

  v2 = CAskConnectPanel::s_pAskConnectPanel;
  if ( CAskConnectPanel::s_pAskConnectPanel != nullptr )
  {
    CAskConnectPanel::SetHostName(this: CAskConnectPanel::s_pAskConnectPanel, pHostName);
    CAskConnectPanel::StartSlideAnimation(this: v2, flDuration);
    v2->MoveToFront(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103127A0
// Name: _dynamic_initializer_for__askconnect_accept__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__askconnect_accept__()
{
  ConCommand::ConCommand(
    this: &askconnect_accept,
    pName: "askconnect_accept",
    callback: askconnect_accept_f,
    pHelpString: "Accept a redirect request by the server.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__askconnect_accept__);
}

//------------------------------------------------------------------------------
// Address: 0x103137A0
// Name: _dynamic_initializer_for__connect_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__connect_command__()
{
  ConCommand::ConCommand(
    this: &connect_command,
    pName: "connect",
    callback: connect_0,
    pHelpString: "Connect to specified server.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__connect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103137D0
// Name: _dynamic_initializer_for__connect_splitscreen_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__connect_splitscreen_command__()
{
  ConCommand::ConCommand(
    this: &connect_splitscreen_command,
    pName: "connect_splitscreen",
    callback: connect_splitscreen,
    pHelpString: "Connect to specified server. With multiple players.",
    flags: 655376,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__connect_splitscreen_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322370
// Name: _dynamic_atexit_destructor_for__askconnect_accept__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__askconnect_accept__()
{
  ConCommand::~ConCommand(this: &askconnect_accept);
}

//------------------------------------------------------------------------------
// Address: 0x10322940
// Name: _dynamic_atexit_destructor_for__connect_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__connect_command__()
{
  ConCommand::~ConCommand(this: &connect_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322950
// Name: _dynamic_atexit_destructor_for__connect_splitscreen_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__connect_splitscreen_command__()
{
  ConCommand::~ConCommand(this: &connect_splitscreen_command);
}

//------------------------------------------------------------------------------
// Address: 0x101EFE50
// Name: __CreateCVoiceServerIVoiceServer_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVoiceServer *__cdecl _CreateCVoiceServerIVoiceServer_interface()
{
  return &_g_CVoiceServer_singleton;
}

} // namespace engine_xlsp
