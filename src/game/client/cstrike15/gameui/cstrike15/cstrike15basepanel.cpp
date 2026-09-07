// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/cstrike15/cstrike15basepanel.cpp
// Functions: 46
// ============================================================

#include "game\client\cstrike15\gameui\cstrike15\cstrike15basepanel.h"

//------------------------------------------------------------------------------
// Address: 0x101FE260
// Name: public: static char const __near * CCStrike15BasePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCStrike15BasePanel::GetPanelClassName()
{
  return "CCStrike15BasePanel";
}

//------------------------------------------------------------------------------
// Address: 0x101FE270
// Name: class CBaseModPanel __near * BasePanel(void)
// Source: json
//------------------------------------------------------------------------------
CCStrike15BasePanel *__cdecl BasePanel()
{
  return g_pCStrike15BasePanel;
}

//------------------------------------------------------------------------------
// Address: 0x101FE280
// Name: public: virtual void CCStrike15BasePanel::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnEvent(CCStrike15BasePanel *this, KeyValues *pEvent)
{
  const char *Name; // eax
  char *String; // eax
  CGameUI *v5; // eax
  char *v6; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_strcmp(s1: Name, s2: "OnSysSigninChange") == 0 )
  {
    String = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: prType);
    if ( _V_stricmp(s1: "signout", s2: String) == 0
      && KeyValues::GetInt(this: pEvent, keyName: "user0", defaultValue: -1) != -1 )
    {
      v5 = GameUI();
      if ( v5->IsInLevel(this: v5) )
      {
        *((_BYTE *)this - 11) = 1;
        engine->ClientCmd_Unrestricted(this: engine, a2: "disconnect");
      }
      else
      {
        (*(void (__thiscall **)(char *))(*((_DWORD *)this - 161) + 924))(a1: (char *)this - 644);
      }
    }
    v6 = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: prType);
    _V_stricmp(s1: "signin", s2: v6);
    C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)((char *)this - 644));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE350
// Name: public: virtual void CCStrike15BasePanel::OnOpenCreateStartScreen(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::OnOpenCreateStartScreen(CCStrike15BasePanel *this)
{
  CCreateStartScreenScaleform::LoadDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE360
// Name: public: virtual void CCStrike15BasePanel::DismissStartScreen(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::DismissStartScreen(CCStrike15BasePanel *this)
{
  CCreateStartScreenScaleform::UnloadDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE370
// Name: public: virtual void CCStrike15BasePanel::OnOpenCreateMainMenuScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenCreateMainMenuScreen(CCStrike15BasePanel *this)
{
  SplitScreenSignonWidget *v2; // eax

  if ( this->m_bScaleformMainMenuEnabled )
  {
    v2 = (SplitScreenSignonWidget *)MemAlloc_Alloc(nSize: 0x34u);
    if ( v2 != nullptr )
      this->m_pSplitScreenSignon = SplitScreenSignonWidget::SplitScreenSignonWidget(this: v2);
    else
      this->m_pSplitScreenSignon = nullptr;
    CCreateMainMenuScreenScaleform::LoadDialog();
  }
  else
  {
    CBaseModPanel::RestoreMainMenuScreen(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE3C0
// Name: public: virtual void CCStrike15BasePanel::DismissMainMenuScreen(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::DismissMainMenuScreen(CCStrike15BasePanel *this)
{
  CCreateMainMenuScreenScaleform::UnloadDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE3D0
// Name: public: virtual void CCStrike15BasePanel::RestoreMainMenuScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::RestoreMainMenuScreen(CCStrike15BasePanel *this)
{
  if ( this->m_bScaleformMainMenuEnabled )
    CCreateMainMenuScreenScaleform::RestorePanel();
}

//------------------------------------------------------------------------------
// Address: 0x101FE3E0
// Name: public: virtual void CCStrike15BasePanel::ShowScaleformMainMenu(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::ShowScaleformMainMenu(CCStrike15BasePanel *this, bool bShow)
{
  if ( !bShow || this->m_bScaleformMainMenuEnabled )
    CCreateMainMenuScreenScaleform::ShowPanel(bShow, immediate: false);
}

//------------------------------------------------------------------------------
// Address: 0x101FE410
// Name: public: virtual bool CCStrike15BasePanel::IsScaleformMainMenuActive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCStrike15BasePanel::IsScaleformMainMenuActive(CCStrike15BasePanel *this)
{
  return CCreateMainMenuScreenScaleform::m_pInstance != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FE420
// Name: public: virtual void CCStrike15BasePanel::OnOpenCreateSingleplayerGameDialog(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenCreateSingleplayerGameDialog(
        CCStrike15BasePanel *this,
        bool bMatchmakingFilter)
{
  CCreateSinglePlayerGameDialogScaleform::LoadDialog(bMatchmakingFilter);
}

//------------------------------------------------------------------------------
// Address: 0x101FE440
// Name: public: virtual void CCStrike15BasePanel::OnOpenCreateMultiplayerGameDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenCreateMultiplayerGameDialog(CCStrike15BasePanel *this)
{
  if ( this->m_bScaleformMainMenuEnabled )
    CCreateSinglePlayerGameDialogScaleform::LoadDialog(bMatchmakingFilter: true);
  else
    CBaseModPanel::OnOpenCreateMultiplayerGameDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE460
// Name: public: virtual void CCStrike15BasePanel::OnOpenMessageBox(char const __near *,char const __near *,char const __near *,unsigned long,class IMessageBoxEventCallback __near *,class CMessageBoxScaleform __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenMessageBox(
        CCStrike15BasePanel *this,
        const char *pszTitle,
        const char *pszMessage,
        const char *pszButtonLegend,
        unsigned int dwFlags,
        IMessageBoxEventCallback *pEventCallback,
        CMessageBoxScaleform **ppInstance)
{
  CMessageBoxScaleform::LoadDialog(
    pszTitle,
    pszMessage,
    pszButtonLegend,
    dwFlags,
    pEventCallback,
    ppMessageBoxInstance: ppInstance);
}

//------------------------------------------------------------------------------
// Address: 0x101FE490
// Name: public: virtual void CCStrike15BasePanel::OnOpenMessageBoxInSlot(int,char const __near *,char const __near *,char const __near *,unsigned long,class IMessageBoxEventCallback __near *,class CMessageBoxScaleform __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenMessageBoxInSlot(
        CCStrike15BasePanel *this,
        int slot,
        const char *pszTitle,
        const char *pszMessage,
        const char *pszButtonLegend,
        unsigned int dwFlags,
        IMessageBoxEventCallback *pEventCallback,
        CMessageBoxScaleform **ppInstance)
{
  CMessageBoxScaleform::LoadDialogInSlot(
    slot,
    pszTitle,
    pszMessage,
    pszButtonLegend,
    dwFlags,
    pEventCallback,
    ppMessageBoxInstance: ppInstance);
}

//------------------------------------------------------------------------------
// Address: 0x101FE4C0
// Name: public: virtual void CCStrike15BasePanel::CreateCommandMsgBox(char const __near *,char const __near *,bool,bool,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::CreateCommandMsgBox(
        CCStrike15BasePanel *this,
        const char *pszTitle,
        const char *pszMessage,
        bool showOk,
        bool showCancel,
        const char *okCommand,
        const char *cancelCommand,
        const char *closedCommand,
        const char *pszLegend)
{
  CCommandMsgBox::CreateAndShow(
    pszTitle,
    pszMessage,
    showOk,
    showCancel,
    okCommand,
    cancelCommand,
    closedCommand,
    pszLegend);
}

//------------------------------------------------------------------------------
// Address: 0x101FE4F0
// Name: public: virtual void CCStrike15BasePanel::CreateCommandMsgBoxInSlot(enum ECommandMsgBoxSlot,char const __near *,char const __near *,bool,bool,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::CreateCommandMsgBoxInSlot(
        CCStrike15BasePanel *this,
        ECommandMsgBoxSlot slot,
        const char *pszTitle,
        const char *pszMessage,
        bool showOk,
        bool showCancel,
        const char *okCommand,
        const char *cancelCommand,
        const char *closedCommand,
        const char *pszLegend)
{
  CCommandMsgBox::CreateAndShowInSlot(
    slot,
    pszTitle,
    pszMessage,
    showOk,
    showCancel,
    okCommand,
    cancelCommand,
    closedCommand,
    pszLegend);
}

//------------------------------------------------------------------------------
// Address: 0x101FE530
// Name: public: virtual void CCStrike15BasePanel::ShowMatchmakingStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::ShowMatchmakingStatus(CCStrike15BasePanel *this)
{
  CMatchmakingStatus *v1; // eax

  v1 = (CMatchmakingStatus *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v1 != nullptr )
    CMatchmakingStatus::CMatchmakingStatus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101FE550
// Name: public: virtual void CCStrike15BasePanel::OnOpenPauseMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenPauseMenu(CCStrike15BasePanel *this)
{
  if ( this->m_bScaleformPauseMenuEnabled )
  {
    if ( CPauseMenuScreenScaleform::m_pInstance != nullptr )
      CPauseMenuScreenScaleform::ShowMenu(bShow: true);
    else
      CPauseMenuScreenScaleform::LoadDialog();
  }
  else
  {
    CBaseModPanel::RestoreMainMenuScreen(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE580
// Name: public: virtual void CCStrike15BasePanel::OnOpenControllerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenControllerDialog(CCStrike15BasePanel *this)
{
  CControlsScaleform::ShowMenu(bShow: true);
}

//------------------------------------------------------------------------------
// Address: 0x101FE590
// Name: public: virtual void CCStrike15BasePanel::OnOpenSettingsDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenSettingsDialog(CCStrike15BasePanel *this)
{
  CSettingsScaleform::ShowMenu(bShow: true);
}

//------------------------------------------------------------------------------
// Address: 0x101FE5A0
// Name: public: virtual void CCStrike15BasePanel::OnOpenHowToPlayDialog(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::OnOpenHowToPlayDialog(CCStrike15BasePanel *this)
{
  CHowToPlayDialogScaleform::LoadDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE5B0
// Name: public: virtual void CCStrike15BasePanel::DismissPauseMenu(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::DismissPauseMenu(CCStrike15BasePanel *this)
{
  CPauseMenuScreenScaleform::UnloadDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE5C0
// Name: public: virtual void CCStrike15BasePanel::RestorePauseMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::RestorePauseMenu(CCStrike15BasePanel *this)
{
  if ( this->m_bScaleformPauseMenuEnabled )
    CPauseMenuScreenScaleform::RestorePanel();
}

//------------------------------------------------------------------------------
// Address: 0x101FE5D0
// Name: public: virtual void CCStrike15BasePanel::ShowScaleformPauseMenu(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::ShowScaleformPauseMenu(CCStrike15BasePanel *this, bool bShow)
{
  if ( !bShow || this->m_bScaleformPauseMenuEnabled )
    CPauseMenuScreenScaleform::ShowMenu(bShow);
}

//------------------------------------------------------------------------------
// Address: 0x101FE5F0
// Name: public: virtual bool CCStrike15BasePanel::IsScaleformPauseMenuActive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCStrike15BasePanel::IsScaleformPauseMenuActive(CCStrike15BasePanel *this)
{
  return CPauseMenuScreenScaleform::m_pInstance != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FE600
// Name: public: virtual bool CCStrike15BasePanel::IsScaleformPauseMenuVisible(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCStrike15BasePanel::IsScaleformPauseMenuVisible(CCStrike15BasePanel *this)
{
  return CPauseMenuScreenScaleform::m_pInstance != nullptr && CPauseMenuScreenScaleform::m_pInstance->m_bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x101FE620
// Name: public: virtual void CCStrike15BasePanel::OnOpenDisconnectConfirmationDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenDisconnectConfirmationDialog(CCStrike15BasePanel *this)
{
  IMessageBoxEventCallback *v1; // eax

  if ( this != nullptr )
    v1 = &this->IMessageBoxEventCallback;
  else
    v1 = nullptr;
  this->OnOpenMessageBox(
    this,
    a2: "#SFUI_PauseMenu_ExitGameConfirmation_Title",
    a3: "#SFUI_PauseMenu_ExitGameConfirmation_Message",
    a4: "#SFUI_PauseMenu_ExitGameConfirmation_Navigation",
    a5: 15u,
    a6: v1,
    a7: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101FE650
// Name: public: virtual void CCStrike15BasePanel::OnOpenQuitConfirmationDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenQuitConfirmationDialog(CCStrike15BasePanel *this)
{
  IMessageBoxEventCallback *v1; // eax

  if ( this != nullptr )
    v1 = &this->IMessageBoxEventCallback;
  else
    v1 = nullptr;
  this->OnOpenMessageBox(
    this,
    a2: "#SFUI_MainMenu_ExitGameConfirmation_Title",
    a3: "#SFUI_MainMenu_ExitGameConfirmation_Message",
    a4: "#SFUI_MainMenu_ExitGameConfirmation_Navigation",
    a5: 7u,
    a6: v1,
    a7: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101FE680
// Name: public: virtual void CCStrike15BasePanel::OnOpenMedalsStatsDialog(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::OnOpenMedalsStatsDialog(CCStrike15BasePanel *this)
{
  CCreateMedalStatsDialogScaleform::LoadDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE690
// Name: public: virtual void CCStrike15BasePanel::CloseMedalsStatsDialog(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::CloseMedalsStatsDialog(CCStrike15BasePanel *this)
{
  CCreateMedalStatsDialogScaleform::UnloadDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE6A0
// Name: public: virtual void CCStrike15BasePanel::OnOpenLeaderboardsDialog(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::OnOpenLeaderboardsDialog(CCStrike15BasePanel *this)
{
  CCreateLeaderboardsDialogScaleform::LoadDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE6B0
// Name: public: virtual void CCStrike15BasePanel::UpdateLeaderboardsDialog(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::UpdateLeaderboardsDialog(CCStrike15BasePanel *this)
{
  CCreateLeaderboardsDialogScaleform::UpdateDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE6C0
// Name: public: virtual void CCStrike15BasePanel::CloseLeaderboardsDialog(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCStrike15BasePanel::CloseLeaderboardsDialog(CCStrike15BasePanel *this)
{
  CCreateLeaderboardsDialogScaleform::UnloadDialog();
}

//------------------------------------------------------------------------------
// Address: 0x101FE6D0
// Name: public: virtual void CCStrike15BasePanel::OnOpenUpsellDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::OnOpenUpsellDialog(CCStrike15BasePanel *this)
{
  CUpsellScaleform::ShowMenu(bShow: true);
}

//------------------------------------------------------------------------------
// Address: 0x101FE6E0
// Name: public: virtual void CCStrike15BasePanel::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCStrike15BasePanel::RunFrame(CCStrike15BasePanel *this@<ecx>, int a2@<ebx>)
{
  SplitScreenSignonWidget *m_pSplitScreenSignon; // ecx

  m_pSplitScreenSignon = this->m_pSplitScreenSignon;
  if ( m_pSplitScreenSignon != nullptr )
    C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)m_pSplitScreenSignon);
  CBaseModPanel::RunFrame(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101FE700
// Name: protected: virtual void CCStrike15BasePanel::LockInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::LockInput(CCStrike15BasePanel *this)
{
  SplitScreenSignonWidget *m_pSplitScreenSignon; // ecx

  m_pSplitScreenSignon = this->m_pSplitScreenSignon;
  if ( m_pSplitScreenSignon != nullptr )
    SplitScreenSignonWidget::RevertUIToOnePlayerMode(this: m_pSplitScreenSignon);
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE720
// Name: protected: virtual void CCStrike15BasePanel::UnlockInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::UnlockInput(CCStrike15BasePanel *this)
{
  SplitScreenSignonWidget *m_pSplitScreenSignon; // ecx

  m_pSplitScreenSignon = this->m_pSplitScreenSignon;
  if ( m_pSplitScreenSignon != nullptr )
    SplitScreenSignonWidget::RevertUIToOnePlayerMode(this: m_pSplitScreenSignon);
  CBaseModPanel::UnlockInput(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FE740
// Name: public: CCStrike15BasePanel::CCStrike15BasePanel(void)
// Source: json
//------------------------------------------------------------------------------
CCStrike15BasePanel *__thiscall CCStrike15BasePanel::CCStrike15BasePanel(CCStrike15BasePanel *this)
{
  vgui::PanelMessageMap *v2; // ebx
  PanelAnimationMap *v3; // ebx
  vgui::PanelKeyBindingMap *v4; // ebx
  IMatchEventsSubscription *v5; // eax

  CBaseModPanel::CBaseModPanel(this, panelName: "CStrike15BasePanel");
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&IMessageBoxEventCallback::`vftable';
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->CBaseModPanel::vgui::Panel::vgui::IClientPanel::__vftable = (CCStrike15BasePanel_vtbl *)&CCStrike15BasePanel::`vftable'{for `CBaseModPanel'};
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CCStrike15BasePanel::`vftable'{for `IMessageBoxEventCallback'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CCStrike15BasePanel::`vftable'{for `IMatchEventsSink'};
  if ( `CCStrike15BasePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CCStrike15BasePanel::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CCStrike15BasePanel");
    v2->pfnClassName = CCStrike15BasePanel::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseModPanel");
  }
  if ( `CCStrike15BasePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCStrike15BasePanel::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CCStrike15BasePanel");
    v3->pfnClassName = CCStrike15BasePanel::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "CBaseModPanel");
  }
  if ( `CCStrike15BasePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCStrike15BasePanel::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CCStrike15BasePanel");
    v4->pfnClassName = CCStrike15BasePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseModPanel");
  }
  this->m_OnClosedCommand = ON_CLOSED_NULL;
  this->m_pSplitScreenSignon = nullptr;
  v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v5->Subscribe(this: v5, a2: &this->IMatchEventsSink);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FE840
// Name: public: virtual struct vgui::PanelMessageMap __near * CCStrike15BasePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCStrike15BasePanel::GetMessageMap(CCStrike15BasePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCStrike15BasePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCStrike15BasePanel::GetMessageMap'::`2'::s_pMap;
  `CCStrike15BasePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCStrike15BasePanel");
  `CCStrike15BasePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FE870
// Name: public: virtual struct PanelAnimationMap __near * CCStrike15BasePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCStrike15BasePanel::GetAnimMap(CCStrike15BasePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CCStrike15BasePanel");
}

//------------------------------------------------------------------------------
// Address: 0x101FE880
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCStrike15BasePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCStrike15BasePanel::GetKBMap(CCStrike15BasePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCStrike15BasePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCStrike15BasePanel::GetKBMap'::`2'::s_pMap;
  `CCStrike15BasePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCStrike15BasePanel");
  `CCStrike15BasePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FE8B0
// Name: public: virtual void CCStrike15BasePanel::DismissAllMainMenuScreens(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::DismissAllMainMenuScreens(CCStrike15BasePanel *this)
{
  CCreateMainMenuScreenScaleform::UnloadDialog();
  CPauseMenuScreenScaleform::UnloadDialog();
  CCreateSinglePlayerGameDialogScaleform::UnloadDialog();
  CCreateMedalStatsDialogScaleform::UnloadDialog();
  CCreateLeaderboardsDialogScaleform::UnloadDialog();
  CControlsScaleform::UnloadDialog();
  CSettingsScaleform::UnloadDialog();
  CUpsellScaleform::UnloadDialog();
  CHowToPlayDialogScaleform::UnloadDialog();
  CMessageBoxScaleform::UnloadAllDialogs();
}

//------------------------------------------------------------------------------
// Address: 0x101FE8F0
// Name: public: virtual bool CCStrike15BasePanel::OnMessageBoxEvent(enum MessageBoxFlags_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCStrike15BasePanel::OnMessageBoxEvent(CCStrike15BasePanel *this, MessageBoxFlags_t buttonPressed)
{
  CGameUI *v3; // eax
  CGameUI *v5; // eax
  void (__thiscall *v6)(char *, const char *); // eax
  char *v7; // ecx
  CGameUI *v8; // eax
  ConVarRef xbox_arcade_title_unlocked; // [esp+4h] [ebp-8h] BYREF

  if ( (buttonPressed & 1) != 0 )
  {
    v3 = GameUI();
    *(_DWORD *)&this->m_OnDelete_register = 2 - v3->IsInLevel(this: v3);
    return 1;
  }
  else if ( (buttonPressed & 2) != 0 )
  {
    v5 = GameUI();
    *(_DWORD *)&this->m_OnDelete_register = 4 - v5->IsInLevel(this: v5);
    return 1;
  }
  else
  {
    if ( (buttonPressed & 4) != 0 )
    {
      switch ( *(_DWORD *)&this->m_OnDelete_register )
      {
        case 1:
          engine->ClientCmd_Unrestricted(this: engine, a2: "disconnect");
          *(_DWORD *)&this->m_OnDelete_register = 0;
          return 1;
        case 2:
          ConVarRef::ConVarRef(this: &xbox_arcade_title_unlocked, pName: "xbox_arcade_title_unlocked");
          v6 = *(void (__thiscall **)(char *, const char *))(*((_DWORD *)this - 160) + 1008);
          v7 = (char *)this - 640;
          if ( xbox_arcade_title_unlocked.m_pConVarState->m_Value.m_nValue != 0 )
            v6(a1: v7, a2: "QuitNoConfirm");
          else
            v6(a1: v7, a2: "OpenUpsellDialog");
          *(_DWORD *)&this->m_OnDelete_register = 0;
          return 1;
        case 3:
          goto $LN5_35;
        case 4:
          goto $LN2_39;
        default:
          v8 = GameUI();
          if ( v8->IsInLevel(this: v8) )
          {
$LN5_35:
            (*(void (__thiscall **)(char *))(*((_DWORD *)this - 160) + 956))(a1: (char *)this - 640);
            *(_DWORD *)&this->m_OnDelete_register = 0;
            return 1;
          }
$LN2_39:
          (*(void (__thiscall **)(char *))(*((_DWORD *)this - 160) + 940))(a1: (char *)this - 640);
          *(_DWORD *)&this->m_OnDelete_register = 0;
          break;
      }
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FEA50
// Name: class CBaseModPanel __near * BasePanelSingleton(void)
// Source: json
//------------------------------------------------------------------------------
CCStrike15BasePanel *__cdecl BasePanelSingleton()
{
  CCStrike15BasePanel *result; // eax
  CCStrike15BasePanel *v1; // eax

  result = g_pCStrike15BasePanel;
  if ( g_pCStrike15BasePanel == nullptr )
  {
    v1 = (CCStrike15BasePanel *)MemAlloc_Alloc(nSize: 0x294u);
    if ( v1 != nullptr )
    {
      result = CCStrike15BasePanel::CCStrike15BasePanel(this: v1);
      g_pCStrike15BasePanel = result;
    }
    else
    {
      g_pCStrike15BasePanel = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FEA80
// Name: public: virtual CCStrike15BasePanel::~CCStrike15BasePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::~CCStrike15BasePanel(CCStrike15BasePanel *this)
{
  this->CBaseModPanel::vgui::Panel::vgui::IClientPanel::__vftable = (CCStrike15BasePanel_vtbl *)&CCStrike15BasePanel::`vftable'{for `CBaseModPanel'};
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CCStrike15BasePanel::`vftable'{for `IMessageBoxEventCallback'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CCStrike15BasePanel::`vftable'{for `IMatchEventsSink'};
  CCreateStartScreenScaleform::UnloadDialog();
  CCreateMainMenuScreenScaleform::UnloadDialog();
  CPauseMenuScreenScaleform::UnloadDialog();
  CCreateSinglePlayerGameDialogScaleform::UnloadDialog();
  CCreateMedalStatsDialogScaleform::UnloadDialog();
  CCreateLeaderboardsDialogScaleform::UnloadDialog();
  CControlsScaleform::UnloadDialog();
  CSettingsScaleform::UnloadDialog();
  CUpsellScaleform::UnloadDialog();
  CHowToPlayDialogScaleform::UnloadDialog();
  CMessageBoxScaleform::UnloadAllDialogs();
  CBaseModPanel::~CBaseModPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FEAE0
// Name: public: virtual void CCStrike15BasePanel::StartExitingProcess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCStrike15BasePanel::StartExitingProcess(CCStrike15BasePanel *this)
{
  SplitScreenSignonWidget *m_pSplitScreenSignon; // eax

  m_pSplitScreenSignon = this->m_pSplitScreenSignon;
  if ( m_pSplitScreenSignon != nullptr )
  {
    if ( m_pSplitScreenSignon->m_bFlashAPIIsValid )
      m_pSplitScreenSignon->m_pScaleformUI->RemoveElement(
        this: m_pSplitScreenSignon->m_pScaleformUI,
        a2: m_pSplitScreenSignon->m_iFlashSlot,
        a3: m_pSplitScreenSignon->m_FlashAPI);
    this->m_pSplitScreenSignon = nullptr;
  }
  CBaseModPanel::StartExitingProcess(this);
}
