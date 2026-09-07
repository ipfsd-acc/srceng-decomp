// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/vgui/counterstrikeviewport.cpp
// Functions: 12
// ============================================================

#include "game\client\cstrike15\vgui\counterstrikeviewport.h"

//------------------------------------------------------------------------------
// Address: 0x10227660
// Name: void PrintBuyTimeOverMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall PrintBuyTimeOverMessage(int a1@<esi>)
{
  CHud *Hud; // eax
  SFHudInfoPanel *Element; // edi
  double BuyTimeLength; // st7
  vgui::ILocalize_vtbl *v4; // esi
  int v5; // eax
  wchar_t buffer[128]; // [esp+4h] [ebp-130h] BYREF
  wchar_t buytime[16]; // [esp+104h] [ebp-30h] BYREF
  char strBuyTime[16]; // [esp+124h] [ebp-10h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = (SFHudInfoPanel *)CHud::FindElement(this: Hud, pName: "SFHudInfoPanel");
  if ( Element != nullptr )
  {
    BuyTimeLength = C_CSGameRules::GetBuyTimeLength(this: (C_CSGameRules *)g_pGameRules);
    V_snprintf(pDest: strBuyTime, maxLen: 0x10u, pFormat: "%d", (int)BuyTimeLength);
    ((void (__thiscall *)(vgui::ILocalize *, char *, wchar_t *, int, int))g_pVGuiLocalize->ConvertANSIToUnicode)(
      a1: g_pVGuiLocalize,
      a2: strBuyTime,
      a3: buytime,
      a4: 32,
      a5: a1);
    v4 = g_pVGuiLocalize->__vftable;
    v5 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
           a1: g_pVGuiLocalize,
           a2: "#SFUI_BuyMenu_OutOfTime",
           a3: 1,
           a4: buytime);
    ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v4->ConstructString_3)(
      a1: g_pVGuiLocalize,
      a2: buffer,
      a3: 256,
      a4: v5);
    SFHudInfoPanel::SetPriorityText(this: Element, pMsg: buffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227710
// Name: buymenu
// Source: json
//------------------------------------------------------------------------------
void __cdecl buymenu()
{
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v1; // esi
  C_CSGameRules *v2; // edi
  int UserID; // eax

  LocalPlayer = CClientTools::GetLocalPlayer();
  v1 = LocalPlayer;
  if ( LocalPlayer != nullptr
    && (LocalPlayer->m_lifeState == 0 || C_CSPlayer::State_Get(this: LocalPlayer) == STATE_ACTIVE)
    && C_CSPlayer::IsInBuyZone(this: v1)
    && !C_CSGameRules::IsPlayingGunGame(this: (C_CSGameRules *)g_pGameRules) )
  {
    if ( C_CSGameRules::IsBuyTimeElapsed(this: (C_CSGameRules *)g_pGameRules) )
    {
      PrintBuyTimeOverMessage();
    }
    else
    {
      v2 = (C_CSGameRules *)g_pGameRules;
      UserID = C_BasePlayer::GetUserID(this: v1);
      C_CSGameRules::OpenBuyMenu(this: v2, nPlayerID: UserID);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227780
// Name: togglescores
// Source: json
//------------------------------------------------------------------------------
void __cdecl togglescores()
{
  IViewPort *ViewPortInterface; // eax
  int v1; // eax
  IViewPortPanel *v2; // esi
  IViewPort *v3; // eax
  CVoiceStatus *ClientVoiceMgr; // eax
  CBaseModPanel *v5; // eax
  IViewPort *v6; // eax

  if ( GetViewPortInterface() != nullptr )
  {
    ViewPortInterface = GetViewPortInterface();
    v1 = (int)ViewPortInterface->FindPanelByName(this: ViewPortInterface, a2: "scores");
    v2 = (IViewPortPanel *)v1;
    if ( v1 != 0 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v1 + 48))(a1: v1) != 0 )
      {
        v3 = GetViewPortInterface();
        v3->ShowPanel(this: v3, a2: v2, a3: false);
        ClientVoiceMgr = GetClientVoiceMgr();
        CVoiceStatus::StopSquelchMode(this: ClientVoiceMgr);
      }
      else if ( BasePanel() == nullptr || (v5 = BasePanel(), !v5->IsScaleformPauseMenuActive(this: v5)) )
      {
        v6 = GetViewPortInterface();
        v6->ShowPanel(this: v6, a2: v2, a3: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227800
// Name: hidescores
// Source: json
//------------------------------------------------------------------------------
void __cdecl hidescores()
{
  IViewPort *ViewPortInterface; // eax
  int v1; // eax
  IViewPortPanel *v2; // esi
  IViewPort *v3; // eax
  CVoiceStatus *ClientVoiceMgr; // eax

  if ( GetViewPortInterface() != nullptr )
  {
    ViewPortInterface = GetViewPortInterface();
    v1 = (int)ViewPortInterface->FindPanelByName(this: ViewPortInterface, a2: "scores");
    v2 = (IViewPortPanel *)v1;
    if ( v1 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v1 + 48))(a1: v1) != 0 )
    {
      v3 = GetViewPortInterface();
      v3->ShowPanel(this: v3, a2: v2, a3: false);
      ClientVoiceMgr = GetClientVoiceMgr();
      CVoiceStatus::StopSquelchMode(this: ClientVoiceMgr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227850
// Name: public: virtual void CounterStrikeViewport::Start(class IGameUIFuncs __near *,class IGameEventManager2 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CounterStrikeViewport::Start(
        CounterStrikeViewport *this,
        IGameUIFuncs *pGameUIFuncs,
        IGameEventManager2 *pGameEventManager)
{
  CBaseViewport::Start(this, pGameUIFuncs, pGameEventManager);
  this->m_bChoseTeamAndClass = false;
}

//------------------------------------------------------------------------------
// Address: 0x10227880
// Name: public: virtual void CounterStrikeViewport::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CounterStrikeViewport::ApplySchemeSettings(CounterStrikeViewport *this, vgui::IScheme *pScheme)
{
  CHud *Hud; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "cs_win_panel_match",
    a4: false);
  Hud = GetHud(nSlot: -1);
  CHud::InitColors(this: Hud, scheme: (int)pScheme);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102278E0
// Name: public: virtual class IViewPortPanel __near * CounterStrikeViewport::CreatePanelByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IViewPortPanel *__thiscall CounterStrikeViewport::CreatePanelByName(
        CounterStrikeViewport *this,
        const char *szPanelName)
{
  CScoreboardScaleform *v3; // eax
  CScoreboardScaleform *v4; // eax
  SFSpectator *v6; // eax
  SFSpectator *v7; // eax
  CCSBuyMenuScaleform *v8; // eax
  CCSBuyMenuScaleform *v9; // eax
  CCSTeamMenuScaleform *v10; // eax
  CCSTeamMenuScaleform *v11; // eax

  if ( _V_strcmp(s1: "scores", s2: szPanelName) == 0 )
  {
    v3 = (CScoreboardScaleform *)MemAlloc_Alloc(nSize: 0xFCu);
    if ( v3 != nullptr )
    {
      v4 = CScoreboardScaleform::CScoreboardScaleform(this: v3);
      if ( v4 != nullptr )
        return &v4->IViewPortPanel;
    }
    return nullptr;
  }
  if ( _V_strcmp(s1: "specgui", s2: szPanelName) == 0 )
  {
    v6 = (SFSpectator *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v6 != nullptr )
    {
      v7 = SFSpectator::SFSpectator(this: v6, pViewPort: this);
      if ( v7 != nullptr )
        return &v7->IViewPortPanel;
    }
    return nullptr;
  }
  if ( _V_strcmp(s1: "buy", s2: szPanelName) == 0 )
  {
    v8 = (CCSBuyMenuScaleform *)MemAlloc_Alloc(nSize: 0xFCu);
    if ( v8 != nullptr )
    {
      v9 = CCSBuyMenuScaleform::CCSBuyMenuScaleform(this: v8, pViewPort: this);
      if ( v9 != nullptr )
        return &v9->IViewPortPanel;
    }
    return nullptr;
  }
  if ( _V_strcmp(s1: "team", s2: szPanelName) == 0 )
  {
    v10 = (CCSTeamMenuScaleform *)MemAlloc_Alloc(nSize: 0x6Cu);
    if ( v10 != nullptr )
    {
      v11 = CCSTeamMenuScaleform::CCSTeamMenuScaleform(this: v10, pViewPort: this);
      if ( v11 != nullptr )
        return &v11->IViewPortPanel;
    }
    return nullptr;
  }
  return CBaseViewport::CreatePanelByName(this, szPanelName);
}

//------------------------------------------------------------------------------
// Address: 0x102279F0
// Name: public: virtual void CounterStrikeViewport::CreateDefaultPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CounterStrikeViewport::CreateDefaultPanels(CounterStrikeViewport *this)
{
  CounterStrikeViewport_vtbl *v2; // edi
  int v3; // eax
  CounterStrikeViewport_vtbl *v4; // edi
  int v5; // eax

  v2 = this->CBaseViewport::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v3 = ((int (__thiscall *)(CounterStrikeViewport *, const char *, const char *))this->CreatePanelByName)(
         a1: this,
         a2: "team",
         a3: "PANEL_TEAM");
  ((void (__thiscall *)(CounterStrikeViewport *, int))v2->AddNewPanel)(a1: this, a2: v3);
  v4 = this->CBaseViewport::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v5 = ((int (__thiscall *)(CounterStrikeViewport *, const char *, const char *))this->CreatePanelByName)(
         a1: this,
         a2: "buy",
         a3: "PANEL_BUY");
  ((void (__thiscall *)(CounterStrikeViewport *, int))v4->AddNewPanel)(a1: this, a2: v5);
  CBaseViewport::CreateDefaultPanels(this);
}

//------------------------------------------------------------------------------
// Address: 0x10227A40
// Name: public: virtual void CounterStrikeViewport::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CounterStrikeViewport::FireGameEvent(CounterStrikeViewport *this, IGameEvent *event)
{
  const char *v3; // edi

  v3 = event->GetName(this: event);
  if ( _V_strcmp(s1: v3, s2: "game_newmap") == 0 || _V_strcmp(s1: v3, s2: "cs_win_panel_match") == 0 )
    HIBYTE(this->_actionSignalTargetDar.m_Memory.m_nGrowSize) = 0;
  CBaseViewport::FireGameEvent(this, event);
}

//------------------------------------------------------------------------------
// Address: 0x10227A90
// Name: spec_menu
// Source: json
//------------------------------------------------------------------------------
void __cdecl spec_menu(const CCommand *args)
{
  C_CSPlayer *LocalPlayer; // eax
  IViewPort *ViewPortInterface; // eax
  bool bShowIt; // [esp+0h] [ebp-4h]

  bShowIt = true;
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer == nullptr || LocalPlayer->GetObserverMode(this: LocalPlayer) != 0 )
  {
    if ( args->m_nArgc == 2 )
      bShowIt = atoi(nptr: args->m_ppArgv[1]) == 1;
    if ( GetViewPortInterface() != nullptr )
    {
      ViewPortInterface = GetViewPortInterface();
      ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "specmenu", a3: bShowIt);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227B00
// Name: spec_gui
// Source: json
//------------------------------------------------------------------------------
void __cdecl spec_gui(const CCommand *args)
{
  C_CSPlayer *LocalPlayer; // eax
  int v2; // eax
  IViewPort *v3; // eax
  IViewPort *v4; // eax
  int v5; // eax
  const char *v6; // eax
  IViewPort *ViewPortInterface; // eax
  bool bShowIt; // [esp+0h] [ebp-4h]

  bShowIt = true;
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer == nullptr || LocalPlayer->GetObserverMode(this: LocalPlayer) != 0 )
  {
    if ( args->m_nArgc == 2 && (v2 = atoi(nptr: args->m_ppArgv[1]), bShowIt = v2 == 1, v2 != 1)
      || GetViewPortInterface() == nullptr
      || (v3 = GetViewPortInterface(), v3->GetActivePanel(this: v3) == nullptr)
      || (v4 = GetViewPortInterface(),
          v5 = (int)v4->GetActivePanel(this: v4),
          v6 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5),
          _V_strcmp(s1: v6, s2: "team") != 0) )
    {
      if ( GetViewPortInterface() != nullptr )
      {
        ViewPortInterface = GetViewPortInterface();
        ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "specgui", a3: bShowIt);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227BC0
// Name: public: virtual void CounterStrikeViewport::UpdateAllPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CounterStrikeViewport::UpdateAllPanels(CounterStrikeViewport *this)
{
  int v2; // ebx
  int v3; // esi
  CCStrike15BasePanel *v4; // eax
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v6; // esi
  int v7; // eax
  const char *v8; // eax
  CHud *Hud; // eax
  SFHudWinPanel *Element; // eax
  bool bSomethingIsVisible; // [esp+Fh] [ebp-1h]

  v2 = 0;
  bSomethingIsVisible = false;
  if ( this->_panelName.m_Storage.m_Memory.m_nAllocationCount <= 0 )
    goto LABEL_19;
  do
  {
    v3 = *(_DWORD *)(this->m_hKeyBindingsContext + 4 * v2);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 48))(a1: v3) != 0 )
    {
      bSomethingIsVisible = true;
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 16))(a1: v3);
    }
    ++v2;
  }
  while ( v2 < this->_panelName.m_Storage.m_Memory.m_nAllocationCount );
  if ( !bSomethingIsVisible )
  {
LABEL_19:
    v4 = BasePanel();
    if ( !v4->IsScaleformPauseMenuActive(this: v4) )
    {
      LocalPlayer = CClientTools::GetLocalPlayer();
      v6 = LocalPlayer;
      if ( LocalPlayer != nullptr )
      {
        if ( LocalPlayer->GetObserverMode(this: LocalPlayer) == 0 )
          return;
        if ( v6->GetTeamNumber(this: v6) == 0 )
        {
          if ( ((int (__thiscall *)(CounterStrikeViewport *))this->GetInset)(a1: this) != 0
            && (v7 = ((int (__thiscall *)(CounterStrikeViewport *))this->GetInset)(a1: this),
                v8 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7),
                _V_strcmp(s1: v8, s2: "team") == 0)
            || ((int (__thiscall *)(CounterStrikeViewport *))this->GetInset)(a1: this) == 0 )
          {
            ((void (__thiscall *)(CounterStrikeViewport *, const char *, int))this->PerformApplySchemeSettings)(
              a1: this,
              a2: "team",
              a3: 1);
          }
          return;
        }
        Hud = GetHud(nSlot: -1);
        Element = (SFHudWinPanel *)CHud::FindElement(this: Hud, pName: "SFHudWinPanel");
        if ( Element == nullptr || SFHudWinPanel::IsVisible(this: Element) )
          return;
      }
      ((void (__thiscall *)(CounterStrikeViewport *, const char *, int))this->PerformApplySchemeSettings)(
        a1: this,
        a2: "specgui",
        a3: 1);
    }
  }
}
