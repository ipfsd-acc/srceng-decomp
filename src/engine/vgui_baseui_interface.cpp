// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vgui_baseui_interface.cpp
// Functions: 91
// ============================================================

#include "engine\vgui_baseui_interface.h"

//------------------------------------------------------------------------------
// Address: 0x10205670
// Name: public: static void CFocusOverlayPanel::GetColorForSlot(int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CFocusOverlayPanel::GetColorForSlot(int slot, int *r, int *g, int *b)
{
  double v4; // st7

  v4 = (double)slot;
  *r = (unsigned __int8)(int)(47.3 * v4 + 124.0);
  *g = (unsigned __int8)(int)(63.78 - 71.40000000000001 * v4);
  *b = (unsigned __int8)(int)(v4 * 13.57 + 188.42);
}

//------------------------------------------------------------------------------
// Address: 0x102056D0
// Name: public: CTransitionEffectPanel::CTransitionEffectPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTransitionEffectPanel *__thiscall CTransitionEffectPanel::CTransitionEffectPanel(
        CTransitionEffectPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CTransitionEffectPanel_vtbl *)&CTransitionEffectPanel::`vftable';
  v6 = videomode->GetModeHeight(this: videomode);
  v4 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: v4, tall: v6);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetCursor(this, cursor: 1u);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10205760
// Name: class IEngineVGuiInternal __near * EngineVGui(void)
// Source: json
//------------------------------------------------------------------------------
CEngineVGui *__cdecl EngineVGui()
{
  return &g_EngineVGuiImp;
}

//------------------------------------------------------------------------------
// Address: 0x10205770
// Name: private: void CEngineVGui::PreparePanel(class vgui::Panel __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::PreparePanel(CEngineVGui *this, vgui::Panel *panel, int nZPos, BOOL bVisible)
{
  int v4; // eax
  int v5; // eax
  int v7; // [esp+0h] [ebp-4h]

  v4 = videomode->GetModeHeight(this: videomode);
  v5 = ((int (__thiscall *)(IVideoMode *, int))videomode->GetModeWidth)(a1: videomode, a2: v4);
  vgui::Panel::SetBounds(this: panel, x: 0, y: 0, wide: v5, tall: v7);
  panel->SetPaintBorderEnabled(this: panel, a2: false);
  panel->SetPaintBackgroundEnabled(this: panel, a2: false);
  panel->SetPaintEnabled(this: panel, a2: false);
  panel->SetVisible(this: panel, a2: true);
  panel->SetCursor(this: panel, a2: 1u);
  panel->SetVisible(this: panel, a2: bVisible);
  vgui::Panel::SetZPos(this: panel, z: nZPos);
}

//------------------------------------------------------------------------------
// Address: 0x10205810
// Name: public: virtual void CEngineVGui::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::PostInit(CEngineVGui *this)
{
  staticGameUIFuncs->PostInit(this: staticGameUIFuncs);
}

//------------------------------------------------------------------------------
// Address: 0x10205820
// Name: public: virtual void CEngineVGui::Connect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::Connect(CEngineVGui *this)
{
  this->m_pInputInternal = (vgui::IInputInternal *)g_GameSystemFactory(a1: "VGUI_InputInternal001", a2: nullptr);
  staticGameUIFuncs->Connect(this: staticGameUIFuncs, a2: g_GameSystemFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10205850
// Name: private: void CEngineVGui::CreateVProfPanels(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::CreateVProfPanels(CEngineVGui *this, vgui::Panel *pParent)
{
  CVProfPanel *v3; // eax
  CVProfPanel *v4; // eax
  CBudgetPanelEngine *v5; // eax
  CBudgetPanelEngine *v6; // eax
  CTextureBudgetPanel *v7; // eax

  v3 = (CVProfPanel *)MemAlloc_Alloc(nSize: 0x260u);
  if ( v3 != nullptr )
    v4 = CVProfPanel::CVProfPanel(this: v3, pParent, pElementName: "VProfPanel");
  else
    v4 = nullptr;
  this->m_pVProfPanel = v4;
  v5 = (CBudgetPanelEngine *)MemAlloc_Alloc(nSize: 0x208u);
  if ( v5 != nullptr )
    v6 = CBudgetPanelEngine::CBudgetPanelEngine(this: v5, pParent, pElementName: "BudgetPanel");
  else
    v6 = nullptr;
  this->m_pBudgetPanel = v6;
  CreateVProfGraphPanel(pParent);
  v7 = (CTextureBudgetPanel *)MemAlloc_Alloc(nSize: 0x268u);
  if ( v7 != nullptr )
    this->m_pTextureBudgetPanel = CTextureBudgetPanel::CTextureBudgetPanel(
                                    this: v7,
                                    pParent,
                                    pElementName: "TextureBudgetPanel");
  else
    this->m_pTextureBudgetPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102058F0
// Name: private: void CEngineVGui::DestroyVProfPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::DestroyVProfPanels(CEngineVGui *this)
{
  CVProfPanel *m_pVProfPanel; // ecx
  CBudgetPanelEngine *m_pBudgetPanel; // ecx
  CTextureBudgetPanel *m_pTextureBudgetPanel; // ecx

  m_pVProfPanel = this->m_pVProfPanel;
  if ( m_pVProfPanel != nullptr )
  {
    ((void (__thiscall *)(CVProfPanel *, int))m_pVProfPanel->dtr_Panel)(a1: m_pVProfPanel, a2: 1);
    this->m_pVProfPanel = nullptr;
  }
  m_pBudgetPanel = this->m_pBudgetPanel;
  if ( m_pBudgetPanel != nullptr )
  {
    ((void (__thiscall *)(CBudgetPanelEngine *, int))m_pBudgetPanel->dtr_Panel)(a1: m_pBudgetPanel, a2: 1);
    this->m_pBudgetPanel = nullptr;
  }
  DestroyVProfGraphPanel();
  m_pTextureBudgetPanel = this->m_pTextureBudgetPanel;
  if ( m_pTextureBudgetPanel != nullptr )
  {
    ((void (__thiscall *)(CTextureBudgetPanel *, int))m_pTextureBudgetPanel->dtr_Panel)(
      a1: m_pTextureBudgetPanel,
      a2: 1);
    this->m_pTextureBudgetPanel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205960
// Name: public: virtual bool CEngineVGui::IsInitialized(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineVGui::IsInitialized(CEngineVGui *this)
{
  return this->staticPanel != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10205970
// Name: private: class vgui::Panel __near * CEngineVGui::GetRootPanel(enum VGuiPanel_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CEngineVGui::GetRootPanel(CEngineVGui *this, VGuiPanel_t type)
{
  vgui::Panel *result; // eax

  if ( sv.m_bIsDedicated )
    return nullptr;
  switch ( type )
  {
    case PANEL_GAMEUIDLL:
      result = this->staticGameUIPanel;
      break;
    case PANEL_CLIENTDLL:
      result = this->staticClientDLLPanel;
      break;
    case PANEL_TOOLS:
      result = this->staticEngineToolsPanel;
      break;
    case PANEL_GAMEDLL:
      result = this->staticGameDLLPanel;
      break;
    case PANEL_CLIENTDLL_TOOLS:
      result = this->staticClientDLLToolsPanel;
      break;
    case PANEL_GAMEUIBACKGROUND:
      result = this->staticGameUIBackgroundPanel;
      break;
    case PANEL_TRANSITIONEFFECT:
      result = this->staticTransitionPanel;
      break;
    case PANEL_STEAMOVERLAY:
      result = this->staticSteamOverlayPanel;
      break;
    default:
      result = this->staticPanel;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10205A10
// Name: public: virtual unsigned int CEngineVGui::GetPanel(enum VGuiPanel_t)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEngineVGui::GetPanel(CEngineVGui *this, VGuiPanel_t type)
{
  vgui::Panel *RootPanel; // eax

  RootPanel = CEngineVGui::GetRootPanel(this, type);
  return RootPanel->GetVPanel(this: RootPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10205A30
// Name: public: virtual bool CEngineVGui::ShouldPause(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineVGui::ShouldPause(CEngineVGui *this)
{
  return bugreporter->ShouldPause(this: bugreporter) || perftools->ShouldPause(this: perftools);
}

//------------------------------------------------------------------------------
// Address: 0x10205A60
// Name: public: virtual bool CEngineVGui::HideGameUI(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineVGui::HideGameUI(CEngineVGui *this)
{
  const char *v3; // eax
  const char *v4; // edi
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax

  if ( (*((_BYTE *)this + 220) & 4) != 0 )
    return 0;
  v3 = engineClient->GetLevelName(this: engineClient);
  v4 = v3;
  if ( v3 != nullptr && *v3 != 0 )
  {
    if ( !engineClient->IsLevelMainMenuBackground(this: engineClient) )
    {
      this->staticGameUIPanel->SetVisible(this: this->staticGameUIPanel, a2: false);
      this->staticGameUIBackgroundPanel->SetVisible(this: this->staticGameUIBackgroundPanel, a2: false);
      this->staticGameUIPanel->SetPaintBackgroundEnabled(this: this->staticGameUIPanel, a2: false);
      this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: true);
      this->staticClientDLLPanel->MoveToFront(this: this->staticClientDLLPanel);
      this->staticClientDLLPanel->SetMouseInputEnabled(this: this->staticClientDLLPanel, a2: true);
      if ( this->staticClientDLLPanel != nullptr )
        this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: true);
      staticGameUIFuncs->OnGameUIHidden(this: staticGameUIFuncs);
    }
    if ( *v4 != 0
      && (engineClient->GetMaxClients(this: engineClient) <= 1 || CBaseServer::IsPlayingSoloAgainstBots(this: &sv))
      && engineClient->IsPaused(this: engineClient) )
    {
      TraceType = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: TraceType, pText: "unpause\n", nTickDelay: 0);
    }
  }
  VGui_MoveDrawTreePanelToFront();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10205B90
// Name: public: virtual void CEngineVGui::HideConsole(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::HideConsole(CEngineVGui *this)
{
  if ( staticGameConsole != nullptr )
    staticGameConsole->Hide(this: staticGameConsole);
}

//------------------------------------------------------------------------------
// Address: 0x10205BB0
// Name: public: virtual void CEngineVGui::ShowConsole(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::ShowConsole(CEngineVGui *this)
{
  this->ActivateGameUI(this);
  if ( staticGameConsole != nullptr )
    staticGameConsole->Activate(this: staticGameConsole);
}

//------------------------------------------------------------------------------
// Address: 0x10205BD0
// Name: public: virtual bool CEngineVGui::IsConsoleVisible(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineVGui::IsConsoleVisible(CEngineVGui *this)
{
  return this->IsGameUIVisible(this)
      && staticGameConsole != nullptr
      && staticGameConsole->IsConsoleVisible(this: staticGameConsole);
}

//------------------------------------------------------------------------------
// Address: 0x10205C00
// Name: public: virtual void CEngineVGui::ClearConsole(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::ClearConsole(CEngineVGui *this)
{
  if ( staticGameConsole != nullptr )
    staticGameConsole->Clear(this: staticGameConsole);
}

//------------------------------------------------------------------------------
// Address: 0x10205C20
// Name: public: virtual bool CEngineVGui::IsGameUIVisible(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineVGui::IsGameUIVisible(CEngineVGui *this)
{
  return this->staticGameUIPanel != nullptr && this->staticGameUIPanel->IsVisible(this: this->staticGameUIPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10205C50
// Name: struct LoadingProgressDescription_t __near & GetProgressDescription(enum LevelLoadingProgress_e)
// Source: json
//------------------------------------------------------------------------------
LoadingProgressDescription_t *__cdecl GetProgressDescription(LevelLoadingProgress_e eProgress)
{
  LevelLoadingProgress_e v1; // ecx
  int v2; // eax

  v1 = g_pLoadingProgressDescriptions->eProgress;
  v2 = 0;
  if ( g_pLoadingProgressDescriptions->eProgress >= eProgress )
    return &g_pLoadingProgressDescriptions[v2];
  while ( v1 != PROGRESS_HIGHESTITEM )
  {
    v1 = g_pLoadingProgressDescriptions[++v2].eProgress;
    if ( v1 >= eProgress )
      return &g_pLoadingProgressDescriptions[v2];
  }
  return g_pLoadingProgressDescriptions;
}

//------------------------------------------------------------------------------
// Address: 0x10205C90
// Name: public: virtual void CEngineVGui::StartLoadingScreenForCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::StartLoadingScreenForCommand(CEngineVGui *this, const char *command)
{
  staticGameUIFuncs->StartLoadingScreenForCommand(this: staticGameUIFuncs, a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x10205CB0
// Name: public: virtual void CEngineVGui::StartLoadingScreenForKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::StartLoadingScreenForKeyValues(CEngineVGui *this, KeyValues *keyValues)
{
  staticGameUIFuncs->StartLoadingScreenForKeyValues(this: staticGameUIFuncs, a2: keyValues);
}

//------------------------------------------------------------------------------
// Address: 0x10205CD0
// Name: public: virtual void CEngineVGui::OnLevelLoadingFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::OnLevelLoadingFinished(CEngineVGui *this)
{
  bool v2; // cc
  ConVar *v3; // eax

  if ( staticGameUIFuncs != nullptr )
  {
    staticGameUIFuncs->OnLevelLoadingFinished(
      this: staticGameUIFuncs,
      a2: gfExtendedError,
      a3: gszDisconnectReason,
      a4: gszExtendedDisconnectReason);
    v2 = g_syncReportLevel <= 1;
    this->m_eLastProgressPoint = PROGRESS_NONE;
    gfExtendedError = false;
    gszDisconnectReason[0] = 0;
    gszExtendedDisconnectReason[0] = 0;
    if ( !v2 )
    {
      v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: "fs_report_sync_opens");
      if ( v3 != nullptr )
        v3->SetValue_2(this: &v3->IConVar, a2: g_syncReportLevel);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205D50
// Name: public: virtual void CEngineVGui::ShowErrorMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::ShowErrorMessage(CEngineVGui *this)
{
  if ( staticGameUIFuncs != nullptr && gfExtendedError )
  {
    staticGameUIFuncs->OnLevelLoadingFinished(
      this: staticGameUIFuncs,
      a2: gfExtendedError,
      a3: gszDisconnectReason,
      a4: gszExtendedDisconnectReason);
    this->m_eLastProgressPoint = PROGRESS_NONE;
    gfExtendedError = false;
    gszDisconnectReason[0] = 0;
    gszExtendedDisconnectReason[0] = 0;
    this->HideGameUI(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205DB0
// Name: public: virtual void CEngineVGui::StartCustomProgress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::StartCustomProgress(CEngineVGui *this)
{
  if ( staticGameUIFuncs != nullptr )
  {
    staticGameUIFuncs->OnLevelLoadingStarted(this: staticGameUIFuncs, a2: nullptr, a3: true);
    *((_BYTE *)this + 220) ^= (((int (__thiscall *)(IGameUI *, int))staticGameUIFuncs->SetShowProgressText)(
                                 a1: staticGameUIFuncs,
                                 a2: 1)
                             ^ *((_BYTE *)this + 220))
                            & 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205DF0
// Name: public: virtual void CEngineVGui::FinishCustomProgress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::FinishCustomProgress(CEngineVGui *this)
{
  if ( staticGameUIFuncs != nullptr )
  {
    staticGameUIFuncs->SetShowProgressText(this: staticGameUIFuncs, a2: *((_BYTE *)this + 220) & 1);
    staticGameUIFuncs->OnLevelLoadingFinished(this: staticGameUIFuncs, a2: false, a3: defaultValue, a4: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205E30
// Name: public: void CEngineVGui::UpdateProgressBar(float,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::UpdateProgressBar(CEngineVGui *this, float progress, const char *pDesc, int showDialog)
{
  const char *v4; // eax
  char v5; // bl

  if ( staticGameUIFuncs != nullptr )
  {
    v4 = pDesc;
    if ( pDesc == nullptr )
      v4 = defaultValue;
    v5 = ((int (__stdcall *)(_DWORD, const char *, int))staticGameUIFuncs->UpdateProgressBar)(
           a1: LODWORD(progress),
           a2: v4,
           a3: showDialog);
    if ( staticGameUIFuncs->LoadingProgressWantsIsolatedRender(this: staticGameUIFuncs, a2: false) )
    {
      while ( staticGameUIFuncs->LoadingProgressWantsIsolatedRender(this: staticGameUIFuncs, a2: true) )
        V_RenderVGuiOnly();
    }
    else if ( v5 != 0 )
    {
      V_RenderVGuiOnly();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205EC0
// Name: public: virtual void CEngineVGui::UpdateButtonState(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::UpdateButtonState(CEngineVGui *this, const InputEvent_t *event)
{
  this->m_pInputInternal->UpdateButtonState(this: this->m_pInputInternal, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x10205EE0
// Name: public: virtual void CEngineVGui::BackwardCompatibility_Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::BackwardCompatibility_Paint(CEngineVGui *this)
{
  this->Paint(this, a2: PAINT_UIPANELS|PAINT_INGAMEPANELS);
}

//------------------------------------------------------------------------------
// Address: 0x10205EF0
// Name: private: bool CEngineVGui::IsDebugSystemVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVGui::IsDebugSystemVisible(CEngineVGui *this)
{
  return this->staticDebugSystemPanel != nullptr
      && this->staticDebugSystemPanel->IsVisible(this: this->staticDebugSystemPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10205F10
// Name: private: virtual void CEngineVGui::HideDebugSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::HideDebugSystem(CEngineVGui *this)
{
  if ( this->staticDebugSystemPanel != nullptr )
  {
    this->staticDebugSystemPanel->SetVisible(this: this->staticDebugSystemPanel, a2: false);
    if ( this->staticClientDLLPanel != nullptr )
      this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205F50
// Name: public: virtual void CEngineVGui::NotifyOfServerConnect(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::NotifyOfServerConnect(
        CEngineVGui *this,
        const char *game,
        int IP,
        int connectionPort,
        int queryPort)
{
  if ( staticGameUIFuncs != nullptr )
    staticGameUIFuncs->OnConnectToServer2(this: staticGameUIFuncs, a2: game, a3: IP, a4: connectionPort, a5: queryPort);
}

//------------------------------------------------------------------------------
// Address: 0x10205F70
// Name: public: virtual void CEngineVGui::NotifyOfServerDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::NotifyOfServerDisconnect(CEngineVGui *this)
{
  if ( staticGameUIFuncs != nullptr )
  {
    staticGameUIFuncs->OnDisconnectFromServer(this: staticGameUIFuncs, a2: g_eSteamLoginFailure);
    g_eSteamLoginFailure = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205FA0
// Name: public: CFocusOverlayPanel::CFocusOverlayPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFocusOverlayPanel *__thiscall CFocusOverlayPanel::CFocusOverlayPanel(
        CFocusOverlayPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CFocusOverlayPanel_vtbl *)&CFocusOverlayPanel::`vftable';
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::MakePopup(this, showTaskbarIcon: true, disabled: false);
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 0);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10206010
// Name: public: virtual void CEngineVGui::OnToolModeChanged(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::OnToolModeChanged(CEngineVGui *this, bool bGameMode)
{
  int (__thiscall ***staticPanel)(_DWORD); // ecx
  unsigned int v4; // eax

  if ( bGameMode )
    staticPanel = (int (__thiscall ***)(_DWORD))this->staticPanel;
  else
    staticPanel = (int (__thiscall ***)(_DWORD))this->staticGameDLLPanel;
  v4 = (**staticPanel)(a1: staticPanel);
  this->staticEngineToolsPanel->SetParent(this: this->staticEngineToolsPanel, a2: v4);
  this->staticEngineToolsPanel->SetMouseInputEnabled(this: this->staticEngineToolsPanel, a2: false);
  this->staticEngineToolsPanel->SetKeyBoardInputEnabled(this: this->staticEngineToolsPanel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10206070
// Name: public: virtual void CEngineVGui::NeedConnectionProblemWaitScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::NeedConnectionProblemWaitScreen(CEngineVGui *this)
{
  staticGameUIFuncs->NeedConnectionProblemWaitScreen(this: staticGameUIFuncs);
}

//------------------------------------------------------------------------------
// Address: 0x10206080
// Name: public: virtual bool CEngineVGui::IsPlayingFullScreenVideo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVGui::IsPlayingFullScreenVideo(CEngineVGui *this)
{
  return staticGameUIFuncs->IsPlayingFullScreenVideo(this: staticGameUIFuncs);
}

//------------------------------------------------------------------------------
// Address: 0x10206140
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10206150
// Name: gameui_hide
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_hide()
{
  g_EngineVGuiImp.HideGameUI(this: &g_EngineVGuiImp);
}

//------------------------------------------------------------------------------
// Address: 0x10206160
// Name: gameui_activate
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_activate()
{
  g_EngineVGuiImp.ActivateGameUI(this: &g_EngineVGuiImp);
}

//------------------------------------------------------------------------------
// Address: 0x10206170
// Name: gameui_preventescape
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_preventescape()
{
  g_EngineVGuiImp.SetNotAllowedToHideGameUI(this: &g_EngineVGuiImp, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10206190
// Name: gameui_allowescapetoshow
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_allowescapetoshow()
{
  g_EngineVGuiImp.SetNotAllowedToShowGameUI(this: &g_EngineVGuiImp, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102061B0
// Name: gameui_preventescapetoshow
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_preventescapetoshow()
{
  g_EngineVGuiImp.SetNotAllowedToShowGameUI(this: &g_EngineVGuiImp, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x102061D0
// Name: gameui_allowescape
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_allowescape()
{
  g_EngineVGuiImp.SetNotAllowedToHideGameUI(this: &g_EngineVGuiImp, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102061F0
// Name: void BaseUI_ProgressEnabled_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BaseUI_ProgressEnabled_f()
{
  g_EngineVGuiImp.EnabledProgressBarForNextLoad(this: &g_EngineVGuiImp);
}

//------------------------------------------------------------------------------
// Address: 0x10206230
// Name: public: virtual void CLoaderProgress::PauseNonInteractiveProgress(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderProgress::PauseNonInteractiveProgress(CLoaderProgress *this, bool bPause)
{
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10206250
// Name: public: virtual void CLoaderProgress::BeginProgress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderProgress::BeginProgress(CLoaderProgress *this)
{
  g_EngineVGuiImp.m_ProgressBias = 0.0;
  this->m_SnappedProgress = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10206270
// Name: public: virtual void CLoaderProgress::UpdateProgress(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderProgress::UpdateProgress(CLoaderProgress *this, float progress, bool bForce)
{
  int m_SnappedProgress; // esi
  int v4; // eax
  float v5; // xmm0_4

  if ( !bForce )
    this->m_flLastProgress = progress;
  m_SnappedProgress = this->m_SnappedProgress;
  if ( m_SnappedProgress != -1 || bForce )
  {
    v4 = (int)(float)(progress * 15.0);
    if ( v4 > m_SnappedProgress )
    {
      this->m_SnappedProgress = v4;
      if ( bForce )
        v5 = 1.0;
      else
        v5 = progress * 0.5;
      CEngineVGui::UpdateProgressBar(this: &g_EngineVGuiImp, progress: v5, pDesc: nullptr, showDialog: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102062E0
// Name: public: virtual void CLoaderProgress::EndProgress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderProgress::EndProgress(CLoaderProgress *this)
{
  g_EngineVGuiImp.m_ProgressBias = 0.5;
  this->m_SnappedProgress = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10206300
// Name: public: virtual bool CEngineVGui::SetVGUIDirectories(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineVGui::SetVGUIDirectories(CEngineVGui *this)
{
  char temp[512]; // [esp+0h] [ebp-280h] BYREF
  char skin[128]; // [esp+200h] [ebp-80h] BYREF

  skin[0] = 0;
  Sys_GetRegKeyValue(
    pszSubKey: "Software\\Valve\\Steam",
    pszElement: "Skin",
    pszReturnString: skin,
    nReturnLength: 128,
    pszDefaultValue: (char *)defaultValue);
  if ( strlen(skin) != 0 )
  {
    sprintf(string: temp, format: "%s/platform/skins/%s", host_parms.basedir, skin);
    g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: temp, a3: "SKIN", a4: PATH_ADD_TO_TAIL);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10206380
// Name: public: virtual void CEngineVGui::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::Shutdown(CEngineVGui *this)
{
  CStaticPanel *staticPanel; // ecx

  if ( CL_IsHL2Demo() )
    g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: "steam://store_demo/220");
  if ( CL_IsPortalDemo() )
    g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: "steam://store_demo/400");
  CEngineVGui::DestroyVProfPanels(this);
  bugreporter->Shutdown(this: bugreporter);
  colorcorrectiontools->Shutdown(this: colorcorrectiontools);
  perftools->Shutdown(this: perftools);
  demoaction->Shutdown(this: demoaction);
  if ( g_PluginManager != nullptr )
    CPluginUIManager::Shutdown(this: g_PluginManager);
  if ( g_bUsingLegacyAppSystems )
    this->staticClientDLLPanel->SetParent(this: this->staticClientDLLPanel, a2: 0);
  staticGameConsole = nullptr;
  staticPanel = this->staticPanel;
  this->staticGameUIPanel = nullptr;
  this->staticClientDLLToolsPanel = nullptr;
  this->staticClientDLLPanel = nullptr;
  this->staticEngineToolsPanel = nullptr;
  this->staticDebugSystemPanel = nullptr;
  this->staticSteamOverlayPanel = nullptr;
  this->staticFocusOverlayPanel = nullptr;
  this->staticGameDLLPanel = nullptr;
  if ( staticPanel != nullptr )
    ((void (__thiscall *)(CStaticPanel *, int))staticPanel->dtr_Panel)(a1: staticPanel, a2: 1);
  this->staticPanel = nullptr;
  g_pVGui->RunFrame(this: g_pVGui);
  staticGameUIFuncs->Shutdown(this: staticGameUIFuncs);
  staticGameUIFuncs = nullptr;
  g_pVGui->Stop(this: g_pVGui);
  if ( this->m_hGameUIInputContext != nullptr )
  {
    g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: nullptr);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    this->m_hGameUIInputContext = nullptr;
  }
  if ( this->m_hStaticGameUIModule != nullptr )
    Sys_UnloadModule(pModule: this->m_hStaticGameUIModule);
  this->m_hStaticGameUIModule = nullptr;
  this->m_GameUIFactory = nullptr;
  this->m_pInputInternal = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10206500
// Name: public: virtual void CEngineVGui::ActivateGameUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::ActivateGameUI(CEngineVGui *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax

  if ( (*((_BYTE *)this + 220) & 8) == 0 && staticGameUIFuncs != nullptr )
  {
    ClearIOStates();
    this->staticGameUIPanel->SetVisible(this: this->staticGameUIPanel, a2: true);
    this->staticGameUIBackgroundPanel->SetVisible(this: this->staticGameUIBackgroundPanel, a2: true);
    this->staticGameUIPanel->MoveToFront(this: this->staticGameUIPanel);
    this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: false);
    this->staticClientDLLPanel->SetMouseInputEnabled(this: this->staticClientDLLPanel, a2: false);
    g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 2u);
    if ( this->staticClientDLLPanel != nullptr )
      this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: false);
    staticGameUIFuncs->OnGameUIActivated(this: staticGameUIFuncs);
    if ( CBaseServer::IsPlayingSoloAgainstBots(this: &sv) )
    {
      TraceType = CTraceFilter::GetTraceType(this: v2);
      Cbuf_AddText(eTarget: TraceType, pText: "pause\n", nTickDelay: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102065D0
// Name: public: virtual void CEngineVGui::UpdateProgressBar(enum LevelLoadingProgress_e,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::UpdateProgressBar(CEngineVGui *this, LevelLoadingProgress_e progress, bool showDialog)
{
  CStatTime *v4; // ecx
  LevelLoadingProgress_e m_eLastProgressPoint; // eax
  LevelLoadingProgress_e v6; // edi
  bool v7; // bl
  LoadingProgressDescription_t *ProgressDescription; // ebx
  int nRepeat; // eax
  float v10; // xmm1_4
  int m_nLastProgressPointRepeatCount; // ecx
  int v12; // edi
  float v13; // xmm0_4
  CClientState *BaseLocalClient; // eax
  CStatTime *v15; // ecx
  float v16; // [esp+4h] [ebp-4h]
  float v17; // [esp+10h] [ebp+8h]

  if ( staticGameUIFuncs != nullptr
    && (unsigned __int8)_ThreadInMainThread() != 0
    && !toolframework->InToolMode(this: toolframework)
    && g_pLoadingProgressDescriptions != nullptr )
  {
    m_eLastProgressPoint = this->m_eLastProgressPoint;
    v6 = progress;
    if ( progress >= m_eLastProgressPoint )
    {
      v7 = progress != m_eLastProgressPoint;
      v16 = _Plat_FloatTime(this: v4);
      if ( (v7 || (float)(v16 - g_flLastUpdateTime) >= 0.050000001)
        && !g_pMaterialSystem->IsInFrame(this: g_pMaterialSystem) )
      {
        if ( v7 )
          this->m_nLastProgressPointRepeatCount = 0;
        else
          ++this->m_nLastProgressPointRepeatCount;
        ProgressDescription = GetProgressDescription(eProgress: progress);
        nRepeat = ProgressDescription->nRepeat;
        v10 = (float)ProgressDescription->nPercent * 0.0099999998;
        if ( nRepeat > 1 )
        {
          m_nLastProgressPointRepeatCount = this->m_nLastProgressPointRepeatCount;
          if ( m_nLastProgressPointRepeatCount != 0 )
          {
            v12 = this->m_nLastProgressPointRepeatCount;
            if ( m_nLastProgressPointRepeatCount >= nRepeat )
              v12 = ProgressDescription->nRepeat;
            this->m_nLastProgressPointRepeatCount = v12;
            v13 = (float)v12;
            v6 = progress;
            v10 = v10
                + (float)((float)((float)((float)GetProgressDescription(eProgress: (LevelLoadingProgress_e)(progress + 1))->nPercent
                                        * 0.0099999998)
                                - v10)
                        * (float)(v13 / (float)ProgressDescription->nRepeat));
          }
        }
        v17 = (float)((float)(1.0 - this->m_ProgressBias) * v10) + this->m_ProgressBias;
        BaseLocalClient = GetBaseLocalClient();
        CClientState::SendLoadingProgress(this: BaseLocalClient, nProgress: (int)(float)(v17 * 100.0));
        CEngineVGui::UpdateProgressBar(this, progress: v17, pDesc: ProgressDescription->pszDesc, showDialog);
        this->m_eLastProgressPoint = v6;
        g_flLastUpdateTime = _Plat_FloatTime(this: v15);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206770
// Name: public: virtual void CEngineVGui::UpdateCustomProgressBar(float,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::UpdateCustomProgressBar(CEngineVGui *this, float progress, const wchar_t *desc)
{
  char pDesc[24]; // [esp+10h] [ebp-400h] BYREF

  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: desc, a3: pDesc, a4: 1024);
  CEngineVGui::UpdateProgressBar(this, progress, pDesc, showDialog: true);
}

//------------------------------------------------------------------------------
// Address: 0x102067C0
// Name: private: void CVGuiPaintHelper::MapHide(struct CVGuiPaintHelper::Entry_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::MapHide(CVGuiPaintHelper *this, CVGuiPaintHelper::Entry_t *entry)
{
  g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: entry->m_pVPanel, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102067E0
// Name: private: void CVGuiPaintHelper::MapRestore(struct CVGuiPaintHelper::Entry_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::MapRestore(CVGuiPaintHelper *this, CVGuiPaintHelper::Entry_t *entry)
{
  g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: entry->m_pVPanel, a3: entry->m_bWasVisible);
}

//------------------------------------------------------------------------------
// Address: 0x10206810
// Name: private: void CVGuiPaintHelper::MapPaintTraverse(struct CVGuiPaintHelper::Entry_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::MapPaintTraverse(CVGuiPaintHelper *this, CVGuiPaintHelper::Entry_t *entry)
{
  g_pVGuiPanel->SetParent(this: g_pVGuiPanel, a2: entry->m_pVPanel, a3: 0);
  g_pVGuiSurface->PaintTraverseEx(this: g_pVGuiSurface, a2: entry->m_pVPanel, a3: true);
  g_pVGuiPanel->SetParent(this: g_pVGuiPanel, a2: entry->m_pVPanel, a3: entry->m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x10206860
// Name: private: void CEngineVGui::ToggleDebugSystemUI(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::ToggleDebugSystemUI(CEngineVGui *this, const CCommand *args)
{
  bool v3; // al
  const char *v4; // eax

  if ( this->staticDebugSystemPanel != nullptr )
  {
    if ( args->m_nArgc == 1 )
    {
      v3 = !this->staticDebugSystemPanel->IsVisible(this: this->staticDebugSystemPanel);
    }
    else
    {
      v4 = defaultValue;
      if ( args->m_nArgc > 1 )
        v4 = args->m_ppArgv[1];
      v3 = atoi(nptr: v4) != 0;
    }
    if ( v3 )
    {
      ClearIOStates();
      this->staticDebugSystemPanel->SetVisible(this: this->staticDebugSystemPanel, a2: true);
      if ( this->staticClientDLLPanel != nullptr )
        this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: false);
    }
    else
    {
      this->staticDebugSystemPanel->SetVisible(this: this->staticDebugSystemPanel, a2: false);
      if ( this->staticClientDLLPanel != nullptr )
        this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206910
// Name: private: bool CEngineVGui::IsCtrlKeyDown(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVGui::IsCtrlKeyDown(CEngineVGui *this)
{
  if ( g_pVGuiInput == nullptr )
    return false;
  return g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
}

//------------------------------------------------------------------------------
// Address: 0x10206950
// Name: VGui_PlaySound
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_PlaySound(const char *pFileName)
{
  CSfxTable *v1; // edi
  CClientState *LocalClient; // eax
  StartSoundParams_t params; // [esp+8h] [ebp-64h] BYREF

  v1 = S_PrecacheSound(name: pFileName);
  if ( v1 != nullptr )
  {
    S_MarkUISound(pSfx: v1);
    params.userdata = 0;
    params.delay = 0.0;
    params.speakerentity = -1;
    params.initialStreamPosition = 0;
    params.skipInitialSamples = 0;
    params.m_nQueuedGUID = -1;
    params.m_nSoundScriptHandle = -1;
    memset(&params.m_pSoundEntryName, 0, 16);
    *((_BYTE *)&params + 96) = *((_BYTE *)&params + 96) & 0xC0 | 2;
    LocalClient = GetLocalClient(nSlot: -1);
    params.soundsource = CBaseClientState::GetViewEntity(this: LocalClient);
    memset(&params.origin, 0, 24);
    params.entchannel = 0;
    params.pSfx = v1;
    params.pitch = 100;
    params.soundlevel = SNDLVL_IDLE;
    params.flags = 0;
    params.fvol = 1.0;
    S_StartSound(&params);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206A60
// Name: void VGui_ActivateMouse(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_ActivateMouse()
{
  if ( g_ClientDLL != nullptr )
  {
    if ( game->IsActiveApp(this: game) && g_pVGuiSurface->IsCursorLocked(this: g_pVGuiSurface) && !g_bTextMode )
      g_ClientDLL->IN_ActivateMouse(this: g_ClientDLL);
    else
      g_ClientDLL->IN_DeactivateMouse(this: g_ClientDLL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206AC0
// Name: void DumpPanels_r(unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpPanels_r(unsigned int panel, int level, bool bVisibleOnly)
{
  const char *v3; // edi
  bool v4; // al
  int v5; // ecx
  const char *v6; // ecx
  const char *v7; // eax
  int v8; // edi
  int v9; // esi
  unsigned int v10; // eax
  char indentBuff[32]; // [esp+8h] [ebp-28h] BYREF
  int v12; // [esp+28h] [ebp-8h]
  bool bVisible; // [esp+2Fh] [ebp-1h]

  v3 = g_pVGuiPanel->GetName(this: g_pVGuiPanel, a2: panel);
  v4 = g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: panel);
  bVisible = v4;
  if ( !bVisibleOnly || v4 )
  {
    v5 = 0;
    if ( level > 0 )
    {
      memset(dst: (unsigned __int8 *)indentBuff, value: 0x2Eu, count: level);
      v4 = bVisible;
      v5 = level;
    }
    indentBuff[v5] = 0;
    v6 = " (Visible)";
    if ( !v4 )
      v6 = " (Not Visible)";
    v7 = v3;
    if ( *v3 == 0 )
      v7 = "???";
    ConMsg(a1: "%s%s%s\n", indentBuff, v7, v6);
    v8 = g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: panel);
    v9 = 0;
    if ( v8 > 0 )
    {
      v12 = level + 1;
      do
      {
        v10 = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: panel, a3: v9);
        DumpPanels_r(panel: v10, level: v12, bVisibleOnly);
        ++v9;
      }
      while ( v9 < v8 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206BA0
// Name: vgui_dump_panels
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui_dump_panels(const CCommand *args)
{
  int v1; // eax
  unsigned int v2; // eax
  bool bVisibleOnly; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc != 2 || (v1 = _V_stricmp(s1: args->m_ppArgv[1], s2: "visible"), bVisibleOnly = true, v1 != 0) )
    bVisibleOnly = false;
  v2 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  DumpPanels_r(panel: v2, level: 0, bVisibleOnly);
}

//------------------------------------------------------------------------------
// Address: 0x10206C90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10206CC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10206CD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10206D00
// Name: public: virtual void CEngineVGui::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::Init(CEngineVGui *this)
{
  bool v2; // bl
  int v3; // eax
  const char *v4; // ebx
  struct CSysModule *v5; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  InputContextHandle_t__ *v7; // eax
  InputContextHandle_t__ *v8; // eax
  int v9; // eax
  vgui::Panel *v10; // eax
  CStaticPanel *v11; // ebx
  CStaticPanel_vtbl *v12; // ebx
  unsigned int v13; // eax
  vgui::EditablePanel *v14; // eax
  CEnginePanel *v15; // ebx
  vgui::EditablePanel *v16; // eax
  CEnginePanel *v17; // ebx
  unsigned int v18; // eax
  CEnginePanel *v19; // ebx
  vgui::EditablePanel *v20; // eax
  CEnginePanel *v21; // ebx
  vgui::EditablePanel *v22; // eax
  CEnginePanel *v23; // ebx
  CEnginePanel *v24; // ebx
  int (__thiscall ***staticGameDLLPanel)(_DWORD); // ecx
  CDebugSystemPanel *v26; // eax
  CDebugSystemPanel *v27; // eax
  CTransitionEffectPanel *v28; // eax
  CTransitionEffectPanel *v29; // eax
  CFocusOverlayPanel *v30; // eax
  CFocusOverlayPanel *v31; // eax
  int v32; // eax
  IGameConsole_vtbl *v33; // ebx
  unsigned int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  unsigned int v42; // [esp-4h] [ebp-11Ch]
  int v43; // [esp-4h] [ebp-11Ch]
  char szFileName[260]; // [esp+Ch] [ebp-10Ch] BYREF
  unsigned int newParent; // [esp+110h] [ebp-8h]
  bool bTools; // [esp+117h] [ebp-1h]

  v2 = _V_stricmp(s1: "swarm", s2: host_parms.mod) != 0;
  if ( _V_stricmp(s1: "portal2", s2: host_parms.mod) == 0 )
    v2 = false;
  if ( _V_stricmp(s1: "cstrike15", s2: host_parms.mod) != 0
    && v2
    && (v3 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-nogameui") == 0) )
  {
    _COM_TimestampedLog(a1: "Loading gameui.dll");
    v4 = "gameui";
    v5 = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: "gameui", a3: "GAMEBIN", a4: 1);
    this->m_hStaticGameUIModule = v5;
    Factory = Sys_GetFactory(pModule: v5);
    this->m_GameUIFactory = Factory;
    if ( Factory == nullptr )
      _Error(a1: "Could not load: %s\n", "gameui");
  }
  else
  {
    DevMsg(a1: "Running -nogameui mode, using client module instead of gameui\n");
    this->m_GameUIFactory = g_ClientFactory;
    v4 = "client";
  }
  staticGameUIFuncs = (IGameUI *)this->m_GameUIFactory(a1: "GameUI011", a2: 0);
  if ( staticGameUIFuncs == nullptr )
    _Error(a1: "Could not get IGameUI interface %s from %s\n", "GameUI011", v4);
  staticGameConsole = (IGameConsole *)this->m_GameUIFactory(a1: "GameConsole004", a2: 0);
  if ( staticGameConsole == nullptr )
    Sys_Error(error: "Could not get IGameConsole interface %s from %s\n", "GameConsole004", v4);
  v7 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  this->m_hGameUIInputContext = v7;
  g_pInputStackSystem->EnableInputContext(this: g_pInputStackSystem, a2: v7, a3: false);
  v8 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: v8);
  vgui::VGui_InitMatSysInterfacesList(moduleName: "BaseUI", factoryList: &g_AppSystemFactory, numFactories: 1);
  _COM_TimestampedLog(a1: "AttachToWindow");
  g_pMatSystemSurface->InstallPlaySoundFunc(this: g_pMatSystemSurface, a2: VGui_PlaySound);
  _COM_TimestampedLog(a1: "Load Scheme File");
  if ( g_pVGuiSchemeManager->LoadSchemeFromFile(
         this: g_pVGuiSchemeManager,
         a2: "Resource/SourceScheme.res",
         a3: "Tracker") != 0 )
  {
    _COM_TimestampedLog(a1: "ivgui()->Start()");
    g_pVGui->Start(this: g_pVGui);
    g_pVGui->SetSleep(this: g_pVGui, a2: false);
    v9 = _CommandLine();
    bTools = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 12))(a1: v9, a2: "-tools", a3: 0) != 0;
    _COM_TimestampedLog(a1: "Building Panels (staticPanel)");
    v10 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
    v11 = (CStaticPanel *)v10;
    if ( v10 != nullptr )
    {
      vgui::Panel::Panel(this: v10, parent: nullptr, panelName: "staticPanel");
      v11->__vftable = (CStaticPanel_vtbl *)&CStaticPanel::`vftable';
      vgui::Panel::SetCursor(this: v11, cursor: 1u);
      vgui::Panel::SetKeyBoardInputEnabled(this: v11, state: 0);
      vgui::Panel::SetMouseInputEnabled(this: v11, state: 0);
    }
    else
    {
      v11 = nullptr;
    }
    this->staticPanel = v11;
    v12 = v11->__vftable;
    v13 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
    v12->SetParent(this: this->staticPanel, a2: v13);
    CEngineVGui::PreparePanel(this, panel: this->staticPanel, nZPos: 0, bVisible: true);
    _COM_TimestampedLog(a1: "Building Panels (staticGameUIBackgroundPanel)");
    v14 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    v15 = (CEnginePanel *)v14;
    if ( v14 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v14, parent: this->staticPanel, panelName: "GameUI Background Panel");
      v15->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v15, state: 1);
      vgui::Panel::SetKeyBoardInputEnabled(this: v15, state: 1);
    }
    else
    {
      v15 = nullptr;
    }
    this->staticGameUIBackgroundPanel = v15;
    CEngineVGui::PreparePanel(this, panel: v15, nZPos: 0, bVisible: true);
    _COM_TimestampedLog(a1: "Building Panels (staticClientDLLPanel)");
    v16 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    v17 = (CEnginePanel *)v16;
    if ( v16 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v16, parent: this->staticPanel, panelName: "staticClientDLLPanel");
      v17->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v17, state: 1);
      vgui::Panel::SetKeyBoardInputEnabled(this: v17, state: 1);
    }
    else
    {
      v17 = nullptr;
    }
    this->staticClientDLLPanel = v17;
    CEngineVGui::PreparePanel(this, panel: v17, nZPos: 25, bVisible: false);
    this->staticClientDLLPanel->SetKeyBoardInputEnabled(this: this->staticClientDLLPanel, a2: false);
    _COM_TimestampedLog(a1: "Building Panels (CreateAskConnectPanel)");
    v18 = this->staticPanel->GetVPanel(this: this->staticPanel);
    CreateAskConnectPanel(parent: v18);
    _COM_TimestampedLog(a1: "Building Panels (staticClientDLLToolsPanel)");
    v19 = (CEnginePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    if ( v19 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v19, parent: this->staticPanel, panelName: "staticClientDLLToolsPanel");
      v19->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v19, state: 1);
      vgui::Panel::SetKeyBoardInputEnabled(this: v19, state: 1);
    }
    else
    {
      v19 = nullptr;
    }
    this->staticClientDLLToolsPanel = v19;
    CEngineVGui::PreparePanel(this, panel: v19, nZPos: 28, bVisible: true);
    this->staticClientDLLToolsPanel->SetKeyBoardInputEnabled(this: this->staticClientDLLToolsPanel, a2: false);
    _COM_TimestampedLog(a1: "Building Panels (staticGameUIPanel)");
    v20 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    v21 = (CEnginePanel *)v20;
    if ( v20 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v20, parent: this->staticPanel, panelName: "GameUI Panel");
      v21->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v21, state: 1);
      vgui::Panel::SetKeyBoardInputEnabled(this: v21, state: 1);
    }
    else
    {
      v21 = nullptr;
    }
    this->staticGameUIPanel = v21;
    CEngineVGui::PreparePanel(this, panel: v21, nZPos: 100, bVisible: true);
    _COM_TimestampedLog(a1: "Building Panels (staticGameDLLPanel)");
    v22 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    v23 = (CEnginePanel *)v22;
    if ( v22 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v22, parent: this->staticPanel, panelName: "staticGameDLLPanel");
      v23->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v23, state: 1);
      vgui::Panel::SetKeyBoardInputEnabled(this: v23, state: 1);
    }
    else
    {
      v23 = nullptr;
    }
    this->staticGameDLLPanel = v23;
    CEngineVGui::PreparePanel(this, panel: v23, nZPos: 135, bVisible: true);
    this->staticGameDLLPanel->SetKeyBoardInputEnabled(this: this->staticGameDLLPanel, a2: false);
    _COM_TimestampedLog(a1: "Building Panels (Engine Tools)");
    v24 = (CEnginePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    if ( v24 != nullptr )
    {
      if ( bTools )
        staticGameDLLPanel = (int (__thiscall ***)(_DWORD))this->staticGameDLLPanel;
      else
        staticGameDLLPanel = (int (__thiscall ***)(_DWORD))this->staticPanel;
      newParent = (**staticGameDLLPanel)(a1: staticGameDLLPanel);
      vgui::EditablePanel::EditablePanel(this: v24, parent: nullptr, panelName: "Engine Tools");
      v42 = newParent;
      v24->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetParent(this: v24, newParent: v42);
      vgui::Panel::SetMouseInputEnabled(this: v24, state: 1);
      vgui::Panel::SetKeyBoardInputEnabled(this: v24, state: 1);
    }
    else
    {
      v24 = nullptr;
    }
    this->staticEngineToolsPanel = v24;
    CEngineVGui::PreparePanel(this, panel: v24, nZPos: 100, bVisible: true);
    this->staticEngineToolsPanel->SetKeyBoardInputEnabled(this: this->staticEngineToolsPanel, a2: false);
    this->staticEngineToolsPanel->SetMouseInputEnabled(this: this->staticEngineToolsPanel, a2: false);
    _COM_TimestampedLog(a1: "Building Panels (staticDebugSystemPanel)");
    v26 = (CDebugSystemPanel *)MemAlloc_Alloc(nSize: 0x154u);
    if ( v26 != nullptr )
      v27 = CDebugSystemPanel::CDebugSystemPanel(this: v26, parent: this->staticPanel, panelName: "Engine Debug System");
    else
      v27 = nullptr;
    this->staticDebugSystemPanel = v27;
    vgui::Panel::SetZPos(this: v27, z: 125);
    CDemoUIPanel::InstallDemoUI(parent: this->staticEngineToolsPanel);
    CDemoUIPanel2::Install(
      pParentBkgnd: this->staticClientDLLPanel,
      pParentFgnd: this->staticEngineToolsPanel,
      bPutToForeground: true);
    CFogUIPanel::InstallFogUI(parent: this->staticEngineToolsPanel);
    TxViewPanel::Install(parent: this->staticEngineToolsPanel);
    _COM_TimestampedLog(a1: "Install bug reporter");
    bugreporter->InstallBugReportingUI(this: bugreporter, a2: this->staticGameUIPanel, a3: BR_AUTOSELECT);
    bugreporter->Init(this: bugreporter);
    _COM_TimestampedLog(a1: "Install perf tools");
    perftools->InstallPerformanceToolsUI(this: perftools, a2: this->staticEngineToolsPanel);
    perftools->Init(this: perftools);
    colorcorrectiontools->InstallColorCorrectionUI(this: colorcorrectiontools, a2: this->staticEngineToolsPanel);
    colorcorrectiontools->Init(this: colorcorrectiontools);
    _COM_TimestampedLog(a1: "Building Panels (staticTransitionPanel)");
    v28 = (CTransitionEffectPanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    if ( v28 != nullptr )
      v29 = CTransitionEffectPanel::CTransitionEffectPanel(
              this: v28,
              pParent: this->staticPanel,
              pName: "TransitionEffect");
    else
      v29 = nullptr;
    this->staticTransitionPanel = v29;
    vgui::Panel::SetZPos(this: v29, z: 135);
    _COM_TimestampedLog(a1: "Building Panels (FocusOverlayPanel)");
    v30 = (CFocusOverlayPanel *)MemAlloc_Alloc(nSize: 0x14Cu);
    if ( v30 != nullptr )
      v31 = CFocusOverlayPanel::CFocusOverlayPanel(this: v30, pParent: this->staticPanel, pName: "FocusOverlayPanel");
    else
      v31 = nullptr;
    this->staticFocusOverlayPanel = v31;
    v43 = videomode->GetModeHeight(this: videomode);
    v32 = videomode->GetModeWidth(this: videomode);
    vgui::Panel::SetBounds(this: this->staticFocusOverlayPanel, x: 0, y: 0, wide: v32, tall: v43);
    vgui::Panel::SetZPos(this: this->staticFocusOverlayPanel, z: 150);
    this->staticFocusOverlayPanel->MoveToFront(this: this->staticFocusOverlayPanel);
    _COM_TimestampedLog(a1: "Building Panels (console, entity report, drawtree, texturelist, vprof)");
    Con_CreateConsolePanel(parent: this->staticEngineToolsPanel);
    CL_CreateEntityReportPanel(parent: this->staticEngineToolsPanel);
    VGui_CreateDrawTreePanel(parent: this->staticEngineToolsPanel);
    CL_CreateTextureListPanel(parent: this->staticEngineToolsPanel);
    CEngineVGui::CreateVProfPanels(this, pParent: this->staticEngineToolsPanel);
    this->staticEngineToolsPanel->LoadControlSettings(
      this: this->staticEngineToolsPanel,
      a2: "scripts/EngineVGuiLayout.res",
      a3: nullptr,
      a4: nullptr,
      a5: nullptr);
    this->m_pVProfPanel->SetVisible(this: this->m_pVProfPanel, a2: false);
    this->m_pBudgetPanel->SetVisible(this: this->m_pBudgetPanel, a2: false);
    HideVProfGraphPanel();
    this->m_pTextureBudgetPanel->SetVisible(this: this->m_pTextureBudgetPanel, a2: false);
    _COM_TimestampedLog(a1: "materials->CacheUsedMaterials()");
    materials->CacheUsedMaterials(this: materials);
    _COM_TimestampedLog(a1: "g_pVGuiLocalize->AddFile");
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/valve_%language%.txt", a3: nullptr, a4: false);
    V_snprintf(pDest: szFileName, maxLen: 259, pFormat: "resource/%s_%%language%%.txt", host_parms.mod);
    szFileName[259] = 0;
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: szFileName, a3: nullptr, a4: false);
    if ( g_bLowViolence )
    {
      V_snprintf(pDest: szFileName, maxLen: 259, pFormat: "resource/%s_%%language%%_lv.txt", host_parms.mod);
      szFileName[259] = 0;
      g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: szFileName, a3: nullptr, a4: false);
    }
    _COM_TimestampedLog(a1: "staticGameUIFuncs->Initialize");
    staticGameUIFuncs->Initialize(this: staticGameUIFuncs, a2: g_GameSystemFactory);
    _COM_TimestampedLog(a1: "staticGameUIFuncs->Start");
    staticGameUIFuncs->Start(this: staticGameUIFuncs);
    if ( staticGameConsole != nullptr )
    {
      staticGameConsole->Initialize(this: staticGameConsole);
      v33 = staticGameConsole->__vftable;
      v34 = this->staticGameUIPanel->GetVPanel(this: this->staticGameUIPanel);
      v33->SetParent(this: staticGameConsole, a2: v34);
    }
    _COM_TimestampedLog(a1: "ActivateGameUI()");
    this->ActivateGameUI(this);
    if ( staticGameConsole != nullptr )
    {
      v35 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v35 + 12))(
             a1: v35,
             a2: "-forcestartupmenu",
             a3: 0) == 0 )
      {
        v36 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v36 + 12))(
               a1: v36,
               a2: "-hideconsole",
               a3: 0) == 0 )
        {
          v37 = _CommandLine();
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v37 + 40))(a1: v37, a2: "-toconsole") != 0
            || (v38 = _CommandLine(),
                (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v38 + 40))(a1: v38, a2: "-console") != 0)
            || (v39 = _CommandLine(),
                (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v39 + 40))(a1: v39, a2: "-rpt") != 0)
            || (v40 = _CommandLine(),
                (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v40 + 40))(a1: v40, a2: "-allowdebug") != 0) )
          {
            staticGameConsole->Activate(this: staticGameConsole);
          }
        }
      }
    }
    v41 = _CommandLine();
    *((_BYTE *)this + 220) ^= (*((_BYTE *)this + 220)
                             ^ (2
                              * ((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v41 + 40))(
                                   a1: v41,
                                   a2: "-noshaderapi") != 0)))
                            & 2;
  }
  else
  {
    Sys_Error(error: "Error loading file %s\n", "Resource/SourceScheme.res");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207680
// Name: public: virtual bool CEngineVGui::Key_Event(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVGui::Key_Event(CEngineVGui *this, const InputEvent_t *event)
{
  bool v2; // bl
  vgui::IInput *v3; // ecx
  ButtonCode_t m_nData; // esi
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  ButtonCode_t BaseButtonCode; // eax
  const char *v9; // eax
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t v11; // eax
  const char *v12; // [esp-8h] [ebp-18h]

  v2 = event->m_nType == 0 || event->m_nType == 2;
  v3 = g_pVGuiInput;
  m_nData = event->m_nData;
  if ( g_pVGuiInput != nullptr )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
    {
      if ( m_nData == KEY_F1 )
      {
        if ( v2 )
        {
          v12 = "debugsystemui";
          goto LABEL_14;
        }
        return true;
      }
      if ( m_nData == KEY_F2 )
      {
        if ( v2 )
        {
          v12 = "demoui";
LABEL_14:
          TraceType = CTraceFilter::GetTraceType(this: v5);
          Cbuf_AddText(eTarget: TraceType, pText: v12, nTickDelay: 0);
          return true;
        }
        return true;
      }
    }
    v3 = g_pVGuiInput;
  }
  if ( m_nData == KEY_BACKQUOTE
    && (v3 != nullptr
     && (v3->IsKeyDown(this: v3, a2: KEY_LALT) || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT))
     || CEngineVGui::IsCtrlKeyDown(this)) )
  {
    return true;
  }
  if ( v2 )
  {
    BaseButtonCode = GetBaseButtonCode(code: m_nData);
    if ( BaseButtonCode == KEY_ESCAPE || BaseButtonCode == KEY_XBUTTON_START )
    {
      if ( this->IsGameUIVisible(this) )
      {
        v9 = engineClient->GetLevelName(this: engineClient);
        if ( v9 == nullptr )
          return true;
        if ( *v9 == 0 )
          return true;
        v11 = CTraceFilter::GetTraceType(this: v10);
        Cbuf_AddText(eTarget: v11, pText: "gameui_hide", nTickDelay: 0);
        if ( !CEngineVGui::IsDebugSystemVisible(this) )
          return true;
        v12 = "debugsystemui 0";
      }
      else
      {
        v12 = "gameui_activate";
      }
      goto LABEL_14;
    }
  }
  return g_pMatSystemSurface != nullptr
      && g_pMatSystemSurface->HandleInputEvent(this: g_pMatSystemSurface, a2: event)
      && m_nData != KEY_BACKQUOTE;
}

//------------------------------------------------------------------------------
// Address: 0x10207800
// Name: public: void CVGuiPaintHelper::Paint(unsigned int,enum PaintMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::Paint(CVGuiPaintHelper *this, unsigned int rootPanel, BOOL mode)
{
  int v4; // edi
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // ebx

  if ( mode )
  {
    v4 = 0;
    if ( this->m_Entries.m_Size > 0 )
    {
      v5 = 0;
      do
      {
        CVGuiPaintHelper::MapHide(this, entry: &this->m_Entries.m_Memory.m_pMemory[v5]);
        ++v4;
        ++v5;
      }
      while ( v4 < this->m_Entries.m_Size );
    }
    g_pVGuiSurface->PaintTraverseEx(this: g_pVGuiSurface, a2: rootPanel, a3: true);
    v6 = 0;
    if ( this->m_Entries.m_Size > 0 )
    {
      v7 = 0;
      do
      {
        CVGuiPaintHelper::MapRestore(this, entry: &this->m_Entries.m_Memory.m_pMemory[v7]);
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_Entries.m_Size );
    }
  }
  if ( (mode & 2) != 0 )
  {
    LOBYTE(mode) = g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: rootPanel);
    g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: rootPanel, a3: false);
    v8 = 0;
    if ( this->m_Entries.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        CVGuiPaintHelper::MapPaintTraverse(this, entry: &this->m_Entries.m_Memory.m_pMemory[v9]);
        ++v8;
        ++v9;
      }
      while ( v8 < this->m_Entries.m_Size );
    }
    g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: rootPanel, a3: mode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102078D0
// Name: public: bool CFocusOverlayPanel::DrawTitleSafeOverlay(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFocusOverlayPanel::DrawTitleSafeOverlay(CFocusOverlayPanel *this)
{
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // ebx
  int backBufferHeight; // [esp+0h] [ebp-Ch] BYREF
  int backBufferWidth; // [esp+4h] [ebp-8h] BYREF
  int y1; // [esp+8h] [ebp-4h]

  if ( mat_drawTitleSafe.m_pParent == nullptr || mat_drawTitleSafe.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  materials->GetBackBufferDimensions(this: materials, a2: &backBufferWidth, a3: &backBufferHeight);
  v2 = (int)(float)((float)backBufferWidth * 0.050000001);
  v3 = (int)(float)((float)backBufferHeight * 0.050000001);
  y1 = backBufferHeight - v3;
  v4 = backBufferWidth - v2;
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v2, a3: v3, a4: v4, a5: y1);
  v5 = (int)(float)((float)backBufferWidth * 0.075000003);
  v6 = (int)(float)((float)backBufferHeight * 0.075000003);
  y1 = backBufferHeight - v6;
  v7 = backBufferWidth - v5;
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 0, a5: 255);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v5, a3: v6, a4: v7, a5: y1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102079E0
// Name: public: bool CFocusOverlayPanel::DrawKeyFocusPanel(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFocusOverlayPanel::DrawKeyFocusPanel(CFocusOverlayPanel *this)
{
  int v2; // eax
  int v3; // eax
  void (__thiscall *v4)(vgui::ISurface *, Color); // edx
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  int x; // [esp+0h] [ebp-14h] BYREF
  int y; // [esp+4h] [ebp-10h] BYREF
  int x1; // [esp+8h] [ebp-Ch] BYREF
  int y1; // [esp+Ch] [ebp-8h] BYREF
  int v10; // [esp+10h] [ebp-4h]

  if ( vgui_drawkeyfocus.m_pParent == nullptr || vgui_drawkeyfocus.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  if ( g_KeyFocusPanel != 0 )
  {
    g_pVGuiPanel->GetClipRect(this: g_pVGuiPanel, a2: g_KeyFocusPanel, a3: &x, a4: &y, a5: &x1, a6: &y1);
    v2 = videomode->GetModeWidth(this: videomode);
    if ( x1 - x == v2 )
    {
      v3 = videomode->GetModeHeight(this: videomode);
      if ( y1 - y == v3 )
      {
        ++x;
        ++y;
        --x1;
        --y1;
      }
    }
    if ( g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) % 500 <= 250 )
    {
      DrawSetColor = g_pVGuiSurface->DrawSetColor;
      v10 = -1;
      ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -1);
    }
    else
    {
      v4 = g_pVGuiSurface->DrawSetColor;
      v10 = -16777216;
      ((void (__thiscall *)(vgui::ISurface *, int))v4)(a1: g_pVGuiSurface, a2: -16777216);
    }
    g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x1, a5: y1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10207AE0
// Name: public: bool CFocusOverlayPanel::DrawFocusPanelList(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CFocusOverlayPanel::DrawFocusPanelList@<al>(
        CFocusOverlayPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>)
{
  int m_Size; // ecx
  int v6; // eax
  int v7; // ebx
  int v8; // esi
  unsigned int v9; // edi
  int v10; // eax
  int v11; // eax
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  int c; // [esp+0h] [ebp-28h]
  int b; // [esp+4h] [ebp-24h] BYREF
  int g; // [esp+8h] [ebp-20h] BYREF
  int r; // [esp+Ch] [ebp-1Ch] BYREF
  int i; // [esp+10h] [ebp-18h]
  int x; // [esp+14h] [ebp-14h] BYREF
  int y; // [esp+18h] [ebp-10h] BYREF
  int x1; // [esp+1Ch] [ebp-Ch] BYREF
  int y1; // [esp+20h] [ebp-8h] BYREF
  int v25; // [esp+24h] [ebp-4h]

  if ( vgui_drawfocus.m_pParent == nullptr )
    return 0;
  if ( vgui_drawfocus.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  m_Size = g_FocusPanelList.m_Size;
  c = g_FocusPanelList.m_Size;
  if ( g_FocusPanelList.m_Size <= 0 )
    return 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  i = 0;
  while ( 1 )
  {
    if ( v7 > 31 )
      return 1;
    v9 = g_FocusPanelList.m_Memory.m_pMemory[v6];
    if ( v9 != 0 )
      break;
LABEL_13:
    i = ++v6;
    if ( v6 >= m_Size )
      return 1;
  }
  if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, unsigned int, int, int, int))g_pVGuiPanel->IsFullyVisible)(
         a1: g_pVGuiPanel,
         a2: v9,
         a3,
         a4,
         a5: a2) != 0 )
  {
    CFocusOverlayPanel::GetColorForSlot(slot: v7, &r, &g, &b);
    g_pVGuiPanel->GetClipRect(this: g_pVGuiPanel, a2: v9, a3: &x, a4: &y, a5: &x1, a6: &y1);
    v10 = videomode->GetModeWidth(this: videomode);
    if ( x1 - x == v10 )
    {
      v11 = videomode->GetModeHeight(this: videomode);
      if ( y1 - y == v11 )
      {
        x += v8;
        y += v8;
        x1 -= v8;
        y1 -= v8++;
      }
    }
    LOBYTE(v25) = r;
    BYTE1(v25) = g;
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    BYTE2(v25) = b;
    HIBYTE(v25) = -1;
    ((void (__thiscall *)(vgui::ISurface *, int, int))DrawSetColor)(a1: g_pVGuiSurface, a2: v25, a3: c);
    c = y1;
    a2 = x1;
    a4 = y;
    a3 = x;
    ((void (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->DrawOutlinedRect)(a1: g_pVGuiSurface);
    m_Size = c;
    v6 = i;
    ++v7;
    goto LABEL_13;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10207C30
// Name: public: virtual void CEngineVGui::OnLevelLoadingStarted(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::OnLevelLoadingStarted(CEngineVGui *this, const char *levelName, bool bLocalServer)
{
  ConVar *v4; // eax
  ConVar *m_pParent; // ecx
  CStatTime *v6; // ecx

  if ( staticGameUIFuncs != nullptr )
  {
    v4 = g_pCVar->FindVar_2(this: g_pCVar, a2: "fs_report_sync_opens");
    if ( v4 != nullptr )
    {
      m_pParent = v4->m_pParent;
      if ( m_pParent != nullptr )
      {
        g_syncReportLevel = m_pParent->m_Value.m_nValue;
        if ( g_syncReportLevel > 1 )
          v4->SetValue_2(this: &v4->IConVar, a2: 0);
      }
      else
      {
        g_syncReportLevel = 0;
      }
    }
    ((void (__stdcall *)(const char *, bool))staticGameUIFuncs->OnLevelLoadingStarted)(
      a1: levelName,
      a2: this->m_bShowProgressDialog);
    this->m_flLoadingStartTime = _Plat_FloatTime(this: v6);
    this->m_LoadingProgress.m_Size = 0;
    this->m_eLastProgressPoint = PROGRESS_NONE;
    this->m_nLastProgressPointRepeatCount = 0;
    this->m_ProgressBias = 0.0;
    g_pLoadingProgressDescriptions = g_RemoteConnectLoadingProgressDescriptions;
    if ( bLocalServer )
      g_pLoadingProgressDescriptions = g_ListenServerLoadingProgressDescriptions;
    if ( this->m_bShowProgressDialog )
      this->ActivateGameUI(this);
    this->m_bShowProgressDialog = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207D00
// Name: public: virtual void CFocusOverlayPanel::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFocusOverlayPanel::PostChildPaint(CFocusOverlayPanel *this)
{
  char v2; // bl
  vgui::IPanel *v3; // esi
  unsigned int v4; // eax
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  int x; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int x1; // [esp+10h] [ebp-Ch] BYREF
  int y1; // [esp+14h] [ebp-8h] BYREF
  int v10; // [esp+18h] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  v2 = 0;
  if ( vgui::VPanelHandle::Get(this: &g_DrawTreeSelectedPanel) != 0 )
  {
    v3 = g_pVGuiPanel;
    v4 = vgui::VPanelHandle::Get(this: &g_DrawTreeSelectedPanel);
    v3->GetClipRect(this: v3, a2: v4, a3: &x, a4: &y, a5: &x1, a6: &y1);
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    v10 = -16776961;
    ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -16776961);
    g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x1, a5: y1);
    v2 = 1;
  }
  if ( CFocusOverlayPanel::DrawTitleSafeOverlay(this) )
    v2 = 1;
  if ( CFocusOverlayPanel::DrawFocusPanelList(this) )
    v2 = 1;
  if ( CFocusOverlayPanel::DrawKeyFocusPanel(this) || v2 != 0 )
    this->MoveToFront(this);
}

//------------------------------------------------------------------------------
// Address: 0x10207DC0
// Name: public: virtual void __near * (*CEngineVGui::GetGameUIFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__thiscall CEngineVGui::GetGameUIFactory(CEngineVGui *this))(const char *, int *)
{
  return this->m_GameUIFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10207DD0
// Name: public: virtual void CEngineVGui::EnabledProgressBarForNextLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::EnabledProgressBarForNextLoad(CEngineVGui *this)
{
  this->m_bShowProgressDialog = true;
}

//------------------------------------------------------------------------------
// Address: 0x10207DE0
// Name: public: virtual void CEngineVGui::SetNotAllowedToHideGameUI(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::SetNotAllowedToHideGameUI(CEngineVGui *this, bool bNotAllowedToHide)
{
  *((_BYTE *)this + 220) ^= (*((_BYTE *)this + 220) ^ (4 * bNotAllowedToHide)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x10207E00
// Name: public: virtual void CEngineVGui::SetNotAllowedToShowGameUI(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::SetNotAllowedToShowGameUI(CEngineVGui *this, bool bNotAllowedToShow)
{
  *((_BYTE *)this + 220) ^= (*((_BYTE *)this + 220) ^ (8 * bNotAllowedToShow)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10207E20
// Name: public: virtual void CEngineVGui::HideLoadingPlaque(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::HideLoadingPlaque(CEngineVGui *this)
{
  if ( scr_drawloading )
  {
    this->OnLevelLoadingFinished(this);
    S_OnLoadScreen(value: false);
  }
  S_PreventSound(bSetting: false);
  scr_disabled_for_loading = false;
  scr_drawloading = false;
}

//------------------------------------------------------------------------------
// Address: 0x10207E60
// Name: public: virtual void CEngineVGui::SetGameDLLPanelsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::SetGameDLLPanelsVisible(CEngineVGui *this, BOOL show)
{
  if ( this->staticGameDLLPanel != nullptr )
    this->staticGameDLLPanel->SetVisible(this: this->staticGameDLLPanel, a2: show);
}

//------------------------------------------------------------------------------
// Address: 0x10207E90
// Name: public: virtual struct InputContextHandle_t__ __near * CEngineVGui::GetGameUIInputContext(void)
// Source: json
//------------------------------------------------------------------------------
InputContextHandle_t__ *__thiscall CEngineVGui::GetGameUIInputContext(CEngineVGui *this)
{
  return this->m_hGameUIInputContext;
}

//------------------------------------------------------------------------------
// Address: 0x10207EA0
// Name: VGui_RecursiveFindPanels
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_RecursiveFindPanels(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *panelList,
        unsigned int check,
        const char *panelname)
{
  vgui::Panel *v3; // ebx
  const char *v4; // eax
  int v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned int *m_pMemory; // ecx
  int v9; // eax
  unsigned int *v10; // edi
  int v11; // edi
  vgui::Panel *Child; // eax
  unsigned int v13; // eax
  int v14; // [esp-Ch] [ebp-14h]
  int childcount; // [esp+4h] [ebp-4h]
  int childcounta; // [esp+4h] [ebp-4h]

  v3 = g_pVGuiPanel->GetPanel(this: g_pVGuiPanel, a2: check, a3: "ENGINE");
  if ( v3 != nullptr )
  {
    v14 = strlen(panelname);
    v4 = v3->GetName(this: v3);
    if ( V_strncmp(s1: v4, s2: panelname, count: v14) == 0 )
    {
      v5 = v3->GetVPanel(this: v3);
      m_Size = panelList->m_Size;
      childcount = v5;
      m_nAllocationCount = panelList->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)panelList,
          num: m_Size - m_nAllocationCount + 1);
      ++panelList->m_Size;
      m_pMemory = panelList->m_Memory.m_pMemory;
      v9 = panelList->m_Size - m_Size - 1;
      panelList->m_pElements = panelList->m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v10 = &panelList->m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        *v10 = childcount;
    }
    v11 = 0;
    childcounta = vgui::Panel::GetChildCount(this: v3);
    if ( childcounta > 0 )
    {
      do
      {
        Child = vgui::Panel::GetChild(this: v3, index: v11);
        v13 = Child->GetVPanel(this: Child);
        VGui_RecursiveFindPanels(panelList, check: v13, panelname);
        ++v11;
      }
      while ( v11 < childcounta );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207F90
// Name: void VGui_FindNamedPanels(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_FindNamedPanels(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *panelList,
        const char *panelname)
{
  unsigned int v2; // edi
  int i; // esi

  v2 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  for ( i = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1; i >= 0; --i )
    g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: i);
  VGui_RecursiveFindPanels(panelList, check: v2, panelname);
}

//------------------------------------------------------------------------------
// Address: 0x10207FF0
// Name: vgui_togglepanel
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui_togglepanel(const CCommand *args)
{
  int m_nArgc; // eax
  int v3; // eax
  bool v4; // cc
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  int v8; // edi
  BOOL v9; // ebx
  unsigned int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // esi
  const char *v13; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > panelList; // [esp+4h] [ebp-1Ch] BYREF
  BOOL flip; // [esp+1Bh] [ebp-5h]
  bool bg; // [esp+1Fh] [ebp-1h]
  bool fg_3; // [esp+2Bh] [ebp+Bh]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    LOBYTE(flip) = 0;
    fg_3 = true;
    bg = true;
    if ( m_nArgc == 5 )
    {
      v3 = atoi(nptr: args->m_ppArgv[2]);
      v4 = args->m_nArgc <= 3;
      LOBYTE(flip) = v3 != 0;
      v5 = defaultValue;
      if ( !v4 )
        v5 = args->m_ppArgv[3];
      fg_3 = atoi(nptr: v5) != 0;
      v6 = defaultValue;
      if ( args->m_nArgc > 4 )
        v6 = args->m_ppArgv[4];
      bg = atoi(nptr: v6) != 0;
    }
    if ( args->m_nArgc > 1 )
    {
      v7 = args->m_ppArgv[1];
      v8 = 0;
      if ( v7 != nullptr && *v7 != 0 )
      {
        memset(&panelList, 0, sizeof(panelList));
        VGui_FindNamedPanels(&panelList, panelname: v7);
        if ( panelList.m_Size != 0 )
        {
          if ( panelList.m_Size > 0 )
          {
            v9 = flip;
            do
            {
              v10 = panelList.m_Memory.m_pMemory[v8];
              if ( v10 != 0 )
              {
                v11 = g_pVGuiPanel->GetPanel(this: g_pVGuiPanel, a2: v10, a3: "ENGINE");
                v12 = v11;
                if ( v11 != nullptr )
                {
                  v13 = v11->GetName(this: v11);
                  _Msg(a1: "Toggling %s\n", v13);
                  if ( fg_3 )
                    v12->SetPaintEnabled(this: v12, a2: v9);
                  if ( bg )
                    v12->SetPaintBackgroundEnabled(this: v12, a2: v9);
                }
              }
              ++v8;
            }
            while ( v8 < panelList.m_Size );
          }
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&panelList);
        }
        else
        {
          ConMsg(a1: "No panels starting with %s\n", v7);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&panelList);
        }
      }
    }
  }
  else
  {
    ConMsg(a1: "Usage:  vgui_showpanel panelname\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208160
// Name: VGui_RecursePanel
// Source: json
//------------------------------------------------------------------------------
void __usercall VGui_RecursePanel(
        int a1@<edi>,
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *panelList,
        int x,
        int y,
        unsigned int check,
        bool include_hidden)
{
  int m_Size; // edi
  int v7; // eax
  unsigned int *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  unsigned int *v10; // ecx
  int v11; // eax
  unsigned int *v12; // edi
  int v13; // ebx
  int i; // edi
  unsigned int v15; // eax

  if ( include_hidden || g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: check) )
  {
    if ( ((int (__thiscall *)(vgui::IPanel *, unsigned int, int, int, _DWORD, int))g_pVGuiPanel->IsWithinTraverse)(
           a1: g_pVGuiPanel,
           a2: check,
           a3: x,
           a4: y,
           a5: 0,
           a6: a1) != 0 )
    {
      m_Size = panelList->m_Size;
      v7 = 0;
      if ( m_Size <= 0 )
        goto LABEL_10;
      m_pMemory = panelList->m_Memory.m_pMemory;
      while ( *m_pMemory != check )
      {
        ++v7;
        ++m_pMemory;
        if ( v7 >= m_Size )
          goto LABEL_10;
      }
      if ( v7 == -1 )
      {
LABEL_10:
        m_nAllocationCount = panelList->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)panelList,
            num: m_Size - m_nAllocationCount + 1);
        ++panelList->m_Size;
        v10 = panelList->m_Memory.m_pMemory;
        v11 = panelList->m_Size - m_Size - 1;
        panelList->m_pElements = panelList->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 4 * v11);
        v12 = &panelList->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = check;
      }
    }
    v13 = g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: check);
    for ( i = 0; i < v13; ++i )
    {
      v15 = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: check, a3: i);
      VGui_RecursePanel(panelList, x, y, check: v15, include_hidden);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208260
// Name: private: void CEngineVGui::DrawMouseFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEngineVGui::DrawMouseFocus(CEngineVGui *this@<ecx>, int a2@<edi>, unsigned int a3@<esi>)
{
  int m_nValue; // eax
  void (__thiscall *GetCursorPos)(vgui::IInput *, int *, int *); // edx
  int j; // edi
  unsigned int v6; // eax
  unsigned int v7; // esi
  int m_Size; // ecx
  int v9; // edi
  int v10; // eax
  unsigned int v11; // esi
  double v12; // st7
  int v13; // eax
  vgui::IPanel *v14; // ebx
  const char *v15; // eax
  int v16; // [esp-14h] [ebp-40h]
  int v17; // [esp-10h] [ebp-3Ch]
  con_nprint_s np; // [esp+0h] [ebp-2Ch] BYREF
  int c; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  unsigned int embedded; // [esp+20h] [ebp-Ch]
  int x; // [esp+24h] [ebp-8h] BYREF
  int y; // [esp+28h] [ebp-4h] BYREF

  g_FocusPanelList.m_Size = 0;
  if ( vgui_drawfocus.m_pParent != nullptr && vgui_drawfocus.m_pParent->m_Value.m_nValue != 0 )
  {
    this->staticFocusOverlayPanel->MoveToFront(this: this->staticFocusOverlayPanel);
    if ( vgui_drawfocus.m_pParent != nullptr )
      m_nValue = vgui_drawfocus.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    GetCursorPos = g_pVGuiInput->GetCursorPos;
    LOBYTE(i) = m_nValue == 2;
    GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    embedded = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
    if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
      && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
    {
      for ( j = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1; j >= 0; --j )
      {
        v6 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: j);
        v7 = v6;
        if ( v6 != 0 && v6 != embedded && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v6) )
          VGui_RecursePanel(panelList: &g_FocusPanelList, x, y, check: v7, include_hidden: i);
      }
      VGui_RecursePanel(panelList: &g_FocusPanelList, x, y, check: embedded, include_hidden: i);
    }
    m_Size = g_FocusPanelList.m_Size;
    v9 = 0;
    v10 = 0;
    np.time_to_live = 1.0;
    c = g_FocusPanelList.m_Size;
    embedded = 0;
    i = 0;
    if ( g_FocusPanelList.m_Size <= 0 )
    {
      do
LABEL_23:
        Con_NPrintf(idx: v9++, fmt: defaultValue);
      while ( v9 <= 31 );
    }
    else
    {
      while ( v9 <= 31 )
      {
        v11 = g_FocusPanelList.m_Memory.m_pMemory[v10];
        if ( v11 != 0 )
        {
          v12 = (double)(int)embedded;
          np.index = v9;
          np.color[0] = (float)(unsigned __int8)(int)(47.3 * v12 + 124.0) * 0.0039215689;
          np.color[1] = (float)(unsigned __int8)(int)(63.78 - 71.40000000000001 * v12) * 0.0039215689;
          np.color[2] = (float)(unsigned __int8)(int)(v12 * 13.57 + 188.42) * 0.0039215689;
          v13 = ((int (__thiscall *)(vgui::IInput *, int, unsigned int))g_pVGuiInput->GetMouseFocus)(
                  a1: g_pVGuiInput,
                  a2,
                  a3);
          embedded = (unsigned int)"-->";
          if ( v13 != v11 )
            embedded = (unsigned int)"   ";
          a3 = v11;
          v14 = g_pVGuiPanel;
          ++v9;
          a2 = ((int (*)(void))g_pVGuiPanel->GetMessageContextId)();
          v15 = (const char *)((int (__thiscall *)(vgui::IPanel *, unsigned int, unsigned int))v14->GetName)(
                                a1: v14,
                                a2: v11,
                                a3: v11);
          Con_NXPrintf(info: &np, fmt: "%s %3i:  %s(vpanel%d)(ctx%d)\n", (const char *)embedded, v9, v15, v16, v17);
          v10 = i;
          m_Size = c;
          embedded = v9;
        }
        i = ++v10;
        if ( v10 >= m_Size )
        {
          if ( v9 > 31 )
            return;
          goto LABEL_23;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208560
// Name: private: virtual void CEngineVGui::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::Simulate(CEngineVGui *this)
{
  void (__thiscall *VGui_PreSimulateAllTools)(IToolFrameworkInternal *); // edx
  CStatTime *v3; // ecx
  vgui::AnimationController *AnimationController; // eax
  IMatRenderContext *v5; // eax
  IMatRenderContext *v6; // esi
  CEngineVGui *v7; // esi
  float v8; // [esp+0h] [ebp-1Ch]
  tagRECT Rect; // [esp+8h] [ebp-14h] BYREF
  CEngineVGui *v10; // [esp+18h] [ebp-4h]

  VGui_PreSimulateAllTools = toolframework->VGui_PreSimulateAllTools;
  v10 = this;
  VGui_PreSimulateAllTools(this: toolframework);
  if ( this->staticPanel != nullptr )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CEngineVGui::Simulate",
      a3: 0,
      a4: "VGUI_Simulate",
      a5: false,
      a6: 4);
    v8 = _Plat_FloatTime(this: v3);
    AnimationController = vgui::GetAnimationController();
    vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime: v8);
    if ( IsIconic(hWnd: *pmainwindow) )
    {
      videomode->GetModeWidth(this: videomode);
      videomode->GetModeHeight(this: videomode);
    }
    else
    {
      GetClientRect(hWnd: *pmainwindow, lpRect: &Rect);
    }
    v5 = materials->GetRenderContext(this: materials);
    v6 = v5;
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD))v6->Viewport)(a1: v6, a2: 0, a3: 0);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
    staticGameUIFuncs->RunFrame(this: staticGameUIFuncs);
    g_pVGui->RunFrame(this: g_pVGui);
    v7 = v10;
    CEngineVGui::DrawMouseFocus(this: v10);
    if ( vgui_drawkeyfocus.m_pParent != nullptr && vgui_drawkeyfocus.m_pParent->m_Value.m_nValue != 0 )
    {
      v7->staticFocusOverlayPanel->MoveToFront(this: v7->staticFocusOverlayPanel);
      g_KeyFocusPanel = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
    }
    VGui_UpdateDrawTreePanel();
    VGui_UpdateTextureListPanel();
    g_pVGuiSurface->CalculateMouseVisible(this: g_pVGuiSurface);
    VGui_ActivateMouse();
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  toolframework->VGui_PostSimulateAllTools(this: toolframework);
}

//------------------------------------------------------------------------------
// Address: 0x102086E0
// Name: public: void CVGuiPaintHelper::AddUIPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::AddUIPanel(CVGuiPaintHelper *this, unsigned int panel)
{
  bool (__thiscall *IsVisible)(vgui::IPanel *, unsigned int); // edx
  unsigned int v4; // eax
  int m_Size; // ecx
  CVGuiPaintHelper::Entry_t e; // [esp+8h] [ebp-Ch] BYREF

  IsVisible = g_pVGuiPanel->IsVisible;
  e.m_pVPanel = panel;
  e.m_bWasVisible = IsVisible(this: g_pVGuiPanel, a2: panel);
  v4 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: panel);
  m_Size = this->m_Entries.m_Size;
  e.m_Parent = v4;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    (CUtlVector<Vector,CUtlMemory<Vector,int> > *)this,
    elem: m_Size,
    src: (const Vector *)&e);
}

//------------------------------------------------------------------------------
// Address: 0x10208730
// Name: public: virtual void CEngineVGui::Paint(enum PaintMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineVGui::Paint(CEngineVGui *this@<ecx>, int a2@<edi>, PaintMode_t mode)
{
  int m_nValue; // eax
  bool v5; // bl
  int right; // ebx
  int bottom; // eax
  CStaticPanel *staticPanel; // edi
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // edi
  unsigned int v11; // eax
  vgui::IPanel *v12; // ebx
  vgui::IPanel_vtbl *v13; // edi
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // edi
  int v17; // ebx
  vgui::IPanel *v18; // ebx
  vgui::IPanel_vtbl *v19; // edi
  unsigned int v20; // eax
  vgui::IPanel *v21; // ebx
  vgui::IPanel_vtbl *v22; // edi
  int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  vgui::IPanel *v26; // ebx
  vgui::IPanel_vtbl *v27; // edi
  int v28; // eax
  vgui::IPanel *v29; // ebx
  vgui::IPanel_vtbl *v30; // edi
  int v31; // eax
  vgui::IPanel *v32; // ebx
  vgui::IPanel_vtbl *v33; // edi
  int v34; // eax
  vgui::IPanel *v35; // ebx
  vgui::IPanel_vtbl *v36; // edi
  unsigned int v37; // eax
  unsigned int v38; // eax
  CTransitionEffectPanel *staticTransitionPanel; // ecx
  CTransitionEffectPanel_vtbl *v40; // edx
  vgui::IPanel *v41; // ebx
  vgui::IPanel_vtbl *v42; // edi
  int v43; // eax
  vgui::ISurface *v44; // ebx
  vgui::ISurface_vtbl *v45; // edi
  int v46; // eax
  vgui::IPanel *v47; // ebx
  vgui::IPanel_vtbl *v48; // edi
  int v49; // eax
  vgui::IPanel *v50; // ebx
  vgui::IPanel_vtbl *v51; // edi
  int v52; // eax
  vgui::IPanel *v53; // ebx
  vgui::IPanel_vtbl *v54; // edi
  unsigned int v55; // eax
  unsigned int v56; // eax
  CEnginePanel *staticSteamOverlayPanel; // ecx
  CEnginePanel_vtbl *v58; // edx
  vgui::IPanel *v59; // ebx
  vgui::IPanel_vtbl *v60; // edi
  int v61; // eax
  vgui::ISurface *v62; // ebx
  vgui::ISurface_vtbl *v63; // edi
  int v64; // eax
  vgui::IPanel *v65; // ebx
  vgui::IPanel_vtbl *v66; // edi
  int v67; // eax
  CVGuiPaintHelper helper; // [esp+4h] [ebp-34h] BYREF
  tagRECT rect; // [esp+18h] [ebp-20h] BYREF
  unsigned int vPanelRememberParent; // [esp+28h] [ebp-10h]
  int childcount; // [esp+2Ch] [ebp-Ch]
  unsigned int fullscreenClientDLLPanel; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CEngineVGui::Paint",
    a3: 0,
    a4: "VGUI",
    a5: false,
    a6: 4);
  if ( this->staticPanel == nullptr )
    goto LABEL_2;
  vPanelRememberParent = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( vPanelRememberParent == 0 )
    goto LABEL_2;
  if ( r_drawvgui.m_pParent != nullptr )
    m_nValue = r_drawvgui.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v5 = m_nValue != 0;
  if ( demoplayer->IsPlayingTimeDemo(this: demoplayer) )
  {
    if ( !v5 )
    {
LABEL_2:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return;
    }
  }
  else if ( !v5 )
  {
    goto LABEL_2;
  }
  if ( (*((_BYTE *)this + 220) & 2) != 0 )
    goto LABEL_2;
  if ( IsIconic(hWnd: *pmainwindow) )
  {
    right = videomode->GetModeWidth(this: videomode);
    bottom = videomode->GetModeHeight(this: videomode);
  }
  else
  {
    GetClientRect(hWnd: *pmainwindow, lpRect: &rect);
    right = rect.right;
    bottom = rect.bottom;
  }
  staticPanel = this->staticPanel;
  vgui::Panel::SetBounds(this: staticPanel, x: 0, y: 0, wide: right, tall: bottom);
  ((void (__thiscall *)(CStaticPanel *, int))staticPanel->Repaint)(a1: staticPanel, a2);
  toolframework->VGui_PreRenderAllTools(this: toolframework, a2: mode);
  memset(&helper, 0, sizeof(helper));
  fullscreenClientDLLPanel = ClientDLL_GetFullscreenClientDLLVPanel();
  if ( mode == PAINT_UIPANELS )
  {
    v18 = g_pVGuiPanel;
    v19 = g_pVGuiPanel->__vftable;
    v20 = this->staticClientDLLPanel->GetVPanel(this: this->staticClientDLLPanel);
    childcount = v19->GetChildCount(this: v18, a2: v20);
    for ( i = 0; i < childcount; ++i )
    {
      v21 = g_pVGuiPanel;
      v22 = g_pVGuiPanel->__vftable;
      v23 = ((int (__thiscall *)(CEnginePanel *, int))this->staticClientDLLPanel->GetVPanel)(
              a1: this->staticClientDLLPanel,
              a2: i);
      v24 = ((int (__thiscall *)(vgui::IPanel *, int))v22->GetChild)(a1: v21, a2: v23);
      if ( v24 != 0 && v24 != fullscreenClientDLLPanel )
        CVGuiPaintHelper::AddUIPanel(this: &helper, panel: v24);
    }
  }
  else if ( mode == PAINT_INGAMEPANELS )
  {
    v9 = g_pVGuiPanel;
    v10 = g_pVGuiPanel->__vftable;
    v11 = this->staticClientDLLPanel->GetVPanel(this: this->staticClientDLLPanel);
    childcount = v10->GetChildCount(this: v9, a2: v11);
    for ( i = 0; i < childcount; ++i )
    {
      v12 = g_pVGuiPanel;
      v13 = g_pVGuiPanel->__vftable;
      v14 = ((int (__thiscall *)(CEnginePanel *, int))this->staticClientDLLPanel->GetVPanel)(
              a1: this->staticClientDLLPanel,
              a2: i);
      v15 = ((int (__thiscall *)(vgui::IPanel *, int))v13->GetChild)(a1: v12, a2: v14);
      v16 = v15;
      if ( v15 != 0 && v15 != fullscreenClientDLLPanel )
      {
        v17 = g_pVGuiPanel->GetMessageContextId(this: g_pVGuiPanel, a2: v15);
        if ( v17 == splitscreen->GetActiveSplitScreenPlayerSlot(this: splitscreen) )
          CVGuiPaintHelper::AddUIPanel(this: &helper, panel: v16);
      }
    }
  }
  v25 = this->staticClientDLLToolsPanel->GetVPanel(this: this->staticClientDLLToolsPanel);
  CVGuiPaintHelper::AddUIPanel(this: &helper, panel: v25);
  if ( this->staticSteamOverlayPanel != nullptr )
  {
    v26 = g_pVGuiPanel;
    v27 = g_pVGuiPanel->__vftable;
    v28 = ((int (__thiscall *)(CEnginePanel *, _DWORD))this->staticSteamOverlayPanel->GetVPanel)(
            a1: this->staticSteamOverlayPanel,
            a2: 0);
    ((void (__thiscall *)(vgui::IPanel *, int))v27->SetVisible)(a1: v26, a2: v28);
  }
  if ( this->staticTransitionPanel != nullptr )
  {
    v29 = g_pVGuiPanel;
    v30 = g_pVGuiPanel->__vftable;
    v31 = ((int (__thiscall *)(CTransitionEffectPanel *, _DWORD))this->staticTransitionPanel->GetVPanel)(
            a1: this->staticTransitionPanel,
            a2: 0);
    ((void (__thiscall *)(vgui::IPanel *, int))v30->SetVisible)(a1: v29, a2: v31);
  }
  CVGuiPaintHelper::Paint(this: &helper, rootPanel: vPanelRememberParent, mode);
  if ( this->staticTransitionPanel != nullptr
    && (mode & 1) != 0
    && staticGameUIFuncs->IsTransitionEffectEnabled(this: staticGameUIFuncs) )
  {
    v32 = g_pVGuiPanel;
    v33 = g_pVGuiPanel->__vftable;
    v34 = ((int (__thiscall *)(CTransitionEffectPanel *, int))this->staticTransitionPanel->GetVPanel)(
            a1: this->staticTransitionPanel,
            a2: 1);
    ((void (__thiscall *)(vgui::IPanel *, int))v33->SetVisible)(a1: v32, a2: v34);
    v35 = g_pVGuiPanel;
    v36 = g_pVGuiPanel->__vftable;
    v37 = this->staticTransitionPanel->GetVPanel(this: this->staticTransitionPanel);
    v38 = v36->GetParent(this: v35, a2: v37);
    staticTransitionPanel = this->staticTransitionPanel;
    v40 = staticTransitionPanel->__vftable;
    v41 = g_pVGuiPanel;
    v42 = g_pVGuiPanel->__vftable;
    vPanelRememberParent = v38;
    v43 = ((int (__thiscall *)(CTransitionEffectPanel *, _DWORD))v40->GetVPanel)(a1: staticTransitionPanel, a2: 0);
    ((void (__thiscall *)(vgui::IPanel *, int))v42->SetParent)(a1: v41, a2: v43);
    v44 = g_pVGuiSurface;
    v45 = g_pVGuiSurface->__vftable;
    v46 = ((int (__thiscall *)(CTransitionEffectPanel *, _DWORD))this->staticTransitionPanel->GetVPanel)(
            a1: this->staticTransitionPanel,
            a2: 0);
    ((void (__thiscall *)(vgui::ISurface *, int))v45->PaintTraverseEx)(a1: v44, a2: v46);
    v47 = g_pVGuiPanel;
    v48 = g_pVGuiPanel->__vftable;
    v49 = ((int (__thiscall *)(CTransitionEffectPanel *, unsigned int))this->staticTransitionPanel->GetVPanel)(
            a1: this->staticTransitionPanel,
            a2: vPanelRememberParent);
    ((void (__thiscall *)(vgui::IPanel *, int))v48->SetParent)(a1: v47, a2: v49);
  }
  if ( this->staticSteamOverlayPanel != nullptr && (mode & 1) != 0 )
  {
    v50 = g_pVGuiPanel;
    v51 = g_pVGuiPanel->__vftable;
    v52 = ((int (__thiscall *)(CEnginePanel *, int))this->staticSteamOverlayPanel->GetVPanel)(
            a1: this->staticSteamOverlayPanel,
            a2: 1);
    ((void (__thiscall *)(vgui::IPanel *, int))v51->SetVisible)(a1: v50, a2: v52);
    v53 = g_pVGuiPanel;
    v54 = g_pVGuiPanel->__vftable;
    v55 = this->staticSteamOverlayPanel->GetVPanel(this: this->staticSteamOverlayPanel);
    v56 = v54->GetParent(this: v53, a2: v55);
    staticSteamOverlayPanel = this->staticSteamOverlayPanel;
    v58 = staticSteamOverlayPanel->__vftable;
    v59 = g_pVGuiPanel;
    v60 = g_pVGuiPanel->__vftable;
    vPanelRememberParent = v56;
    v61 = ((int (__thiscall *)(CEnginePanel *, _DWORD))v58->GetVPanel)(a1: staticSteamOverlayPanel, a2: 0);
    ((void (__thiscall *)(vgui::IPanel *, int))v60->SetParent)(a1: v59, a2: v61);
    v62 = g_pVGuiSurface;
    v63 = g_pVGuiSurface->__vftable;
    v64 = ((int (__thiscall *)(CEnginePanel *, _DWORD))this->staticSteamOverlayPanel->GetVPanel)(
            a1: this->staticSteamOverlayPanel,
            a2: 0);
    ((void (__thiscall *)(vgui::ISurface *, int))v63->PaintTraverseEx)(a1: v62, a2: v64);
    v65 = g_pVGuiPanel;
    v66 = g_pVGuiPanel->__vftable;
    v67 = ((int (__thiscall *)(CEnginePanel *, unsigned int))this->staticSteamOverlayPanel->GetVPanel)(
            a1: this->staticSteamOverlayPanel,
            a2: vPanelRememberParent);
    ((void (__thiscall *)(vgui::IPanel *, int))v66->SetParent)(a1: v65, a2: v67);
  }
  toolframework->VGui_PostRenderAllTools(this: toolframework, a2: mode);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&helper);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102A4AB0
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x102A4CF0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x102A5190
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10205860
// Name: public: static void CFocusOverlayPanel::GetColorForSlot(int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CFocusOverlayPanel::GetColorForSlot(int slot, int *r, int *g, int *b)
{
  double v4; // st7

  v4 = (double)slot;
  *r = (unsigned __int8)(int)(47.3 * v4 + 124.0);
  *g = (unsigned __int8)(int)(63.78 - 71.40000000000001 * v4);
  *b = (unsigned __int8)(int)(v4 * 13.57 + 188.42);
}

//------------------------------------------------------------------------------
// Address: 0x102058C0
// Name: public: CTransitionEffectPanel::CTransitionEffectPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTransitionEffectPanel *__thiscall CTransitionEffectPanel::CTransitionEffectPanel(
        CTransitionEffectPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CTransitionEffectPanel_vtbl *)&CTransitionEffectPanel::`vftable';
  v6 = videomode->GetModeHeight(this: videomode);
  v4 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: v4, tall: v6);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetCursor(this, cursor: 1u);
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10205950
// Name: class IEngineVGuiInternal __near * EngineVGui(void)
// Source: json
//------------------------------------------------------------------------------
CEngineVGui *__cdecl EngineVGui()
{
  return &g_EngineVGuiImp;
}

//------------------------------------------------------------------------------
// Address: 0x10205A00
// Name: public: virtual void CEngineVGui::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::PostInit(CEngineVGui *this)
{
  staticGameUIFuncs->PostInit(this: staticGameUIFuncs);
}

//------------------------------------------------------------------------------
// Address: 0x10205A40
// Name: private: void CEngineVGui::CreateVProfPanels(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::CreateVProfPanels(CEngineVGui *this, vgui::Panel *pParent)
{
  CVProfPanel *v3; // eax
  CVProfPanel *v4; // eax
  CBudgetPanelEngine *v5; // eax
  CBudgetPanelEngine *v6; // eax
  CTextureBudgetPanel *v7; // eax

  v3 = (CVProfPanel *)MemAlloc_Alloc(nSize: 0x260u);
  if ( v3 != nullptr )
    v4 = CVProfPanel::CVProfPanel(this: v3, pParent, pElementName: "VProfPanel");
  else
    v4 = nullptr;
  this->m_pVProfPanel = v4;
  v5 = (CBudgetPanelEngine *)MemAlloc_Alloc(nSize: 0x208u);
  if ( v5 != nullptr )
    v6 = CBudgetPanelEngine::CBudgetPanelEngine(this: v5, pParent, pElementName: "BudgetPanel");
  else
    v6 = nullptr;
  this->m_pBudgetPanel = v6;
  CreateVProfGraphPanel(pParent);
  v7 = (CTextureBudgetPanel *)MemAlloc_Alloc(nSize: 0x268u);
  if ( v7 != nullptr )
    this->m_pTextureBudgetPanel = CTextureBudgetPanel::CTextureBudgetPanel(
                                    this: v7,
                                    pParent,
                                    pElementName: "TextureBudgetPanel");
  else
    this->m_pTextureBudgetPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10205AE0
// Name: private: void CEngineVGui::DestroyVProfPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::DestroyVProfPanels(CEngineVGui *this)
{
  CVProfPanel *m_pVProfPanel; // ecx
  CBudgetPanelEngine *m_pBudgetPanel; // ecx
  CTextureBudgetPanel *m_pTextureBudgetPanel; // ecx

  m_pVProfPanel = this->m_pVProfPanel;
  if ( m_pVProfPanel != nullptr )
  {
    ((void (__thiscall *)(CVProfPanel *, int))m_pVProfPanel->dtr_Panel)(a1: m_pVProfPanel, a2: 1);
    this->m_pVProfPanel = nullptr;
  }
  m_pBudgetPanel = this->m_pBudgetPanel;
  if ( m_pBudgetPanel != nullptr )
  {
    ((void (__thiscall *)(CBudgetPanelEngine *, int))m_pBudgetPanel->dtr_Panel)(a1: m_pBudgetPanel, a2: 1);
    this->m_pBudgetPanel = nullptr;
  }
  DestroyVProfGraphPanel();
  m_pTextureBudgetPanel = this->m_pTextureBudgetPanel;
  if ( m_pTextureBudgetPanel != nullptr )
  {
    ((void (__thiscall *)(CTextureBudgetPanel *, int))m_pTextureBudgetPanel->dtr_Panel)(
      a1: m_pTextureBudgetPanel,
      a2: 1);
    this->m_pTextureBudgetPanel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205B50
// Name: public: virtual bool CEngineVGui::IsInitialized(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineVGui::IsInitialized(CEngineVGui *this)
{
  return this->staticPanel != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10205B60
// Name: private: class vgui::Panel __near * CEngineVGui::GetRootPanel(enum VGuiPanel_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CEngineVGui::GetRootPanel(CEngineVGui *this, VGuiPanel_t type)
{
  vgui::Panel *result; // eax

  if ( sv.m_bIsDedicated )
    return nullptr;
  switch ( type )
  {
    case PANEL_GAMEUIDLL:
      result = this->staticGameUIPanel;
      break;
    case PANEL_CLIENTDLL:
      result = this->staticClientDLLPanel;
      break;
    case PANEL_TOOLS:
      result = this->staticEngineToolsPanel;
      break;
    case PANEL_GAMEDLL:
      result = this->staticGameDLLPanel;
      break;
    case PANEL_CLIENTDLL_TOOLS:
      result = this->staticClientDLLToolsPanel;
      break;
    case PANEL_GAMEUIBACKGROUND:
      result = this->staticGameUIBackgroundPanel;
      break;
    case PANEL_TRANSITIONEFFECT:
      result = this->staticTransitionPanel;
      break;
    case PANEL_STEAMOVERLAY:
      result = this->staticSteamOverlayPanel;
      break;
    default:
      result = this->staticPanel;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10205D80
// Name: public: virtual void CEngineVGui::HideConsole(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::HideConsole(CEngineVGui *this)
{
  if ( staticGameConsole != nullptr )
    staticGameConsole->Hide(this: staticGameConsole);
}

//------------------------------------------------------------------------------
// Address: 0x10205DA0
// Name: public: virtual void CEngineVGui::ShowConsole(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::ShowConsole(CEngineVGui *this)
{
  this->ActivateGameUI(this);
  if ( staticGameConsole != nullptr )
    staticGameConsole->Activate(this: staticGameConsole);
}

//------------------------------------------------------------------------------
// Address: 0x10205DC0
// Name: public: virtual bool CEngineVGui::IsConsoleVisible(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineVGui::IsConsoleVisible(CEngineVGui *this)
{
  return this->IsGameUIVisible(this)
      && staticGameConsole != nullptr
      && staticGameConsole->IsConsoleVisible(this: staticGameConsole);
}

//------------------------------------------------------------------------------
// Address: 0x10205E10
// Name: public: virtual bool CEngineVGui::IsGameUIVisible(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineVGui::IsGameUIVisible(CEngineVGui *this)
{
  return this->staticGameUIPanel != nullptr && this->staticGameUIPanel->IsVisible(this: this->staticGameUIPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10205E40
// Name: struct LoadingProgressDescription_t __near & GetProgressDescription(enum LevelLoadingProgress_e)
// Source: json
//------------------------------------------------------------------------------
LoadingProgressDescription_t *__cdecl GetProgressDescription(LevelLoadingProgress_e eProgress)
{
  LevelLoadingProgress_e v1; // ecx
  int v2; // eax

  v1 = g_pLoadingProgressDescriptions->eProgress;
  v2 = 0;
  if ( g_pLoadingProgressDescriptions->eProgress >= eProgress )
    return &g_pLoadingProgressDescriptions[v2];
  while ( v1 != PROGRESS_HIGHESTITEM )
  {
    v1 = g_pLoadingProgressDescriptions[++v2].eProgress;
    if ( v1 >= eProgress )
      return &g_pLoadingProgressDescriptions[v2];
  }
  return g_pLoadingProgressDescriptions;
}

//------------------------------------------------------------------------------
// Address: 0x10205E80
// Name: public: virtual void CEngineVGui::StartLoadingScreenForCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::StartLoadingScreenForCommand(CEngineVGui *this, const char *command)
{
  staticGameUIFuncs->StartLoadingScreenForCommand(this: staticGameUIFuncs, a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x10205EA0
// Name: public: virtual void CEngineVGui::StartLoadingScreenForKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::StartLoadingScreenForKeyValues(CEngineVGui *this, KeyValues *keyValues)
{
  staticGameUIFuncs->StartLoadingScreenForKeyValues(this: staticGameUIFuncs, a2: keyValues);
}

//------------------------------------------------------------------------------
// Address: 0x10205F40
// Name: public: virtual void CEngineVGui::ShowErrorMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::ShowErrorMessage(CEngineVGui *this)
{
  if ( staticGameUIFuncs != nullptr && gfExtendedError )
  {
    staticGameUIFuncs->OnLevelLoadingFinished(
      this: staticGameUIFuncs,
      a2: gfExtendedError,
      a3: gszDisconnectReason,
      a4: gszExtendedDisconnectReason);
    this->m_eLastProgressPoint = PROGRESS_NONE;
    gfExtendedError = false;
    gszDisconnectReason[0] = 0;
    gszExtendedDisconnectReason[0] = 0;
    this->HideGameUI(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205FE0
// Name: public: virtual void CEngineVGui::FinishCustomProgress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::FinishCustomProgress(CEngineVGui *this)
{
  if ( staticGameUIFuncs != nullptr )
  {
    staticGameUIFuncs->SetShowProgressText(this: staticGameUIFuncs, a2: *((_BYTE *)this + 220) & 1);
    staticGameUIFuncs->OnLevelLoadingFinished(this: staticGameUIFuncs, a2: false, a3: defaultValue, a4: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206020
// Name: public: void CEngineVGui::UpdateProgressBar(float,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::UpdateProgressBar(CEngineVGui *this, float progress, const char *pDesc, int showDialog)
{
  const char *v4; // eax
  char v5; // bl

  if ( staticGameUIFuncs != nullptr )
  {
    v4 = pDesc;
    if ( pDesc == nullptr )
      v4 = defaultValue;
    v5 = ((int (__stdcall *)(_DWORD, const char *, int))staticGameUIFuncs->UpdateProgressBar)(
           a1: LODWORD(progress),
           a2: v4,
           a3: showDialog);
    if ( staticGameUIFuncs->LoadingProgressWantsIsolatedRender(this: staticGameUIFuncs, a2: false) )
    {
      while ( staticGameUIFuncs->LoadingProgressWantsIsolatedRender(this: staticGameUIFuncs, a2: true) )
        V_RenderVGuiOnly();
    }
    else if ( v5 != 0 )
    {
      V_RenderVGuiOnly();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102060B0
// Name: public: virtual void CEngineVGui::UpdateButtonState(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::UpdateButtonState(CEngineVGui *this, const InputEvent_t *event)
{
  this->m_pInputInternal->UpdateButtonState(this: this->m_pInputInternal, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102060D0
// Name: public: virtual void CEngineVGui::BackwardCompatibility_Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::BackwardCompatibility_Paint(CEngineVGui *this)
{
  this->Paint(this, a2: PAINT_UIPANELS|PAINT_INGAMEPANELS);
}

//------------------------------------------------------------------------------
// Address: 0x102060E0
// Name: private: bool CEngineVGui::IsDebugSystemVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVGui::IsDebugSystemVisible(CEngineVGui *this)
{
  return this->staticDebugSystemPanel != nullptr
      && this->staticDebugSystemPanel->IsVisible(this: this->staticDebugSystemPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10206100
// Name: private: virtual void CEngineVGui::HideDebugSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::HideDebugSystem(CEngineVGui *this)
{
  if ( this->staticDebugSystemPanel != nullptr )
  {
    this->staticDebugSystemPanel->SetVisible(this: this->staticDebugSystemPanel, a2: false);
    if ( this->staticClientDLLPanel != nullptr )
      this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206200
// Name: public: virtual void CEngineVGui::OnToolModeChanged(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::OnToolModeChanged(CEngineVGui *this, bool bGameMode)
{
  int (__thiscall ***staticPanel)(_DWORD); // ecx
  unsigned int v4; // eax

  if ( bGameMode )
    staticPanel = (int (__thiscall ***)(_DWORD))this->staticPanel;
  else
    staticPanel = (int (__thiscall ***)(_DWORD))this->staticGameDLLPanel;
  v4 = (**staticPanel)(a1: staticPanel);
  this->staticEngineToolsPanel->SetParent(this: this->staticEngineToolsPanel, a2: v4);
  this->staticEngineToolsPanel->SetMouseInputEnabled(this: this->staticEngineToolsPanel, a2: false);
  this->staticEngineToolsPanel->SetKeyBoardInputEnabled(this: this->staticEngineToolsPanel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10206260
// Name: public: virtual void CEngineVGui::NeedConnectionProblemWaitScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::NeedConnectionProblemWaitScreen(CEngineVGui *this)
{
  staticGameUIFuncs->NeedConnectionProblemWaitScreen(this: staticGameUIFuncs);
}

//------------------------------------------------------------------------------
// Address: 0x10206310
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10206320
// Name: gameui_hide
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_hide()
{
  g_EngineVGuiImp.HideGameUI(this: &g_EngineVGuiImp);
}

//------------------------------------------------------------------------------
// Address: 0x10206330
// Name: gameui_activate
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_activate()
{
  g_EngineVGuiImp.ActivateGameUI(this: &g_EngineVGuiImp);
}

//------------------------------------------------------------------------------
// Address: 0x10206340
// Name: gameui_preventescape
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_preventescape()
{
  g_EngineVGuiImp.SetNotAllowedToHideGameUI(this: &g_EngineVGuiImp, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10206360
// Name: gameui_allowescapetoshow
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_allowescapetoshow()
{
  g_EngineVGuiImp.SetNotAllowedToShowGameUI(this: &g_EngineVGuiImp, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102063A0
// Name: gameui_allowescape
// Source: json
//------------------------------------------------------------------------------
void __cdecl gameui_allowescape()
{
  g_EngineVGuiImp.SetNotAllowedToHideGameUI(this: &g_EngineVGuiImp, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102063C0
// Name: void BaseUI_ProgressEnabled_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BaseUI_ProgressEnabled_f()
{
  g_EngineVGuiImp.EnabledProgressBarForNextLoad(this: &g_EngineVGuiImp);
}

//------------------------------------------------------------------------------
// Address: 0x102063D0
// Name: public: virtual void CLoaderProgress::PauseNonInteractiveProgress(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderProgress::PauseNonInteractiveProgress(CLoaderProgress *this, bool bPause)
{
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x102063F0
// Name: public: virtual void CLoaderProgress::BeginProgress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderProgress::BeginProgress(CLoaderProgress *this)
{
  g_EngineVGuiImp.m_ProgressBias = 0.0;
  this->m_SnappedProgress = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10206410
// Name: public: virtual void CLoaderProgress::UpdateProgress(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderProgress::UpdateProgress(CLoaderProgress *this, float progress, bool bForce)
{
  int m_SnappedProgress; // esi
  int v4; // eax
  float v5; // xmm0_4

  if ( !bForce )
    this->m_flLastProgress = progress;
  m_SnappedProgress = this->m_SnappedProgress;
  if ( m_SnappedProgress != -1 || bForce )
  {
    v4 = (int)(float)(progress * 15.0);
    if ( v4 > m_SnappedProgress )
    {
      this->m_SnappedProgress = v4;
      if ( bForce )
        v5 = 1.0;
      else
        v5 = progress * 0.5;
      CEngineVGui::UpdateProgressBar(this: &g_EngineVGuiImp, progress: v5, pDesc: nullptr, showDialog: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206480
// Name: public: virtual void CLoaderProgress::EndProgress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderProgress::EndProgress(CLoaderProgress *this)
{
  g_EngineVGuiImp.m_ProgressBias = 0.5;
  this->m_SnappedProgress = -1;
}

//------------------------------------------------------------------------------
// Address: 0x102064A0
// Name: public: virtual bool CEngineVGui::SetVGUIDirectories(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineVGui::SetVGUIDirectories(CEngineVGui *this)
{
  char temp[512]; // [esp+0h] [ebp-280h] BYREF
  char skin[128]; // [esp+200h] [ebp-80h] BYREF

  skin[0] = 0;
  Sys_GetRegKeyValue(
    pszSubKey: "Software\\Valve\\Steam",
    pszElement: "Skin",
    pszReturnString: skin,
    nReturnLength: 128,
    pszDefaultValue: (char *)defaultValue);
  if ( strlen(skin) != 0 )
  {
    sprintf(string: temp, format: "%s/platform/skins/%s", host_parms.basedir, skin);
    g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: temp, a3: "SKIN", a4: PATH_ADD_TO_TAIL);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10206520
// Name: public: virtual void CEngineVGui::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::Shutdown(CEngineVGui *this)
{
  CStaticPanel *staticPanel; // ecx

  if ( CL_IsHL2Demo() )
    g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: "steam://store_demo/220");
  if ( CL_IsPortalDemo() )
    g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: "steam://store_demo/400");
  CEngineVGui::DestroyVProfPanels(this);
  bugreporter->Shutdown(this: bugreporter);
  colorcorrectiontools->Shutdown(this: colorcorrectiontools);
  perftools->Shutdown(this: perftools);
  demoaction->Shutdown(this: demoaction);
  if ( g_PluginManager != nullptr )
    CPluginUIManager::Shutdown(this: g_PluginManager);
  if ( g_bUsingLegacyAppSystems )
    this->staticClientDLLPanel->SetParent(this: this->staticClientDLLPanel, a2: 0);
  staticGameConsole = nullptr;
  staticPanel = this->staticPanel;
  this->staticGameUIPanel = nullptr;
  this->staticClientDLLToolsPanel = nullptr;
  this->staticClientDLLPanel = nullptr;
  this->staticEngineToolsPanel = nullptr;
  this->staticDebugSystemPanel = nullptr;
  this->staticSteamOverlayPanel = nullptr;
  this->staticFocusOverlayPanel = nullptr;
  this->staticGameDLLPanel = nullptr;
  if ( staticPanel != nullptr )
    ((void (__thiscall *)(CStaticPanel *, int))staticPanel->dtr_Panel)(a1: staticPanel, a2: 1);
  this->staticPanel = nullptr;
  g_pVGui->RunFrame(this: g_pVGui);
  staticGameUIFuncs->Shutdown(this: staticGameUIFuncs);
  staticGameUIFuncs = nullptr;
  g_pVGui->Stop(this: g_pVGui);
  if ( this->m_hGameUIInputContext != nullptr )
  {
    g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: nullptr);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
    this->m_hGameUIInputContext = nullptr;
  }
  if ( this->m_hStaticGameUIModule != nullptr )
    Sys_UnloadModule(pModule: this->m_hStaticGameUIModule);
  this->m_hStaticGameUIModule = nullptr;
  this->m_GameUIFactory = nullptr;
  this->m_pInputInternal = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102066A0
// Name: public: virtual void CEngineVGui::ActivateGameUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::ActivateGameUI(CEngineVGui *this)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax

  if ( (*((_BYTE *)this + 220) & 8) == 0 && staticGameUIFuncs != nullptr )
  {
    ClearIOStates();
    this->staticGameUIPanel->SetVisible(this: this->staticGameUIPanel, a2: true);
    this->staticGameUIBackgroundPanel->SetVisible(this: this->staticGameUIBackgroundPanel, a2: true);
    this->staticGameUIPanel->MoveToFront(this: this->staticGameUIPanel);
    this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: false);
    this->staticClientDLLPanel->SetMouseInputEnabled(this: this->staticClientDLLPanel, a2: false);
    g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 2u);
    if ( this->staticClientDLLPanel != nullptr )
      this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: false);
    staticGameUIFuncs->OnGameUIActivated(this: staticGameUIFuncs);
    if ( CBaseServer::IsPlayingSoloAgainstBots(this: &sv) )
    {
      TraceType = CTraceFilter::GetTraceType(this: v2);
      Cbuf_AddText(eTarget: TraceType, pText: "pause\n", nTickDelay: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206960
// Name: private: void CVGuiPaintHelper::MapHide(struct CVGuiPaintHelper::Entry_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::MapHide(CVGuiPaintHelper *this, CVGuiPaintHelper::Entry_t *entry)
{
  g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: entry->m_pVPanel, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10206980
// Name: private: void CVGuiPaintHelper::MapRestore(struct CVGuiPaintHelper::Entry_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::MapRestore(CVGuiPaintHelper *this, CVGuiPaintHelper::Entry_t *entry)
{
  g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: entry->m_pVPanel, a3: entry->m_bWasVisible);
}

//------------------------------------------------------------------------------
// Address: 0x102069B0
// Name: private: void CVGuiPaintHelper::MapPaintTraverse(struct CVGuiPaintHelper::Entry_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::MapPaintTraverse(CVGuiPaintHelper *this, CVGuiPaintHelper::Entry_t *entry)
{
  g_pVGuiPanel->SetParent(this: g_pVGuiPanel, a2: entry->m_pVPanel, a3: 0);
  g_pVGuiSurface->PaintTraverseEx(this: g_pVGuiSurface, a2: entry->m_pVPanel, a3: true);
  g_pVGuiPanel->SetParent(this: g_pVGuiPanel, a2: entry->m_pVPanel, a3: entry->m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x10206A00
// Name: private: void CEngineVGui::ToggleDebugSystemUI(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::ToggleDebugSystemUI(CEngineVGui *this, const CCommand *args)
{
  bool v3; // al
  const char *v4; // eax

  if ( this->staticDebugSystemPanel != nullptr )
  {
    if ( args->m_nArgc == 1 )
    {
      v3 = !this->staticDebugSystemPanel->IsVisible(this: this->staticDebugSystemPanel);
    }
    else
    {
      v4 = defaultValue;
      if ( args->m_nArgc > 1 )
        v4 = args->m_ppArgv[1];
      v3 = atoi(nptr: v4) != 0;
    }
    if ( v3 )
    {
      ClearIOStates();
      this->staticDebugSystemPanel->SetVisible(this: this->staticDebugSystemPanel, a2: true);
      if ( this->staticClientDLLPanel != nullptr )
        this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: false);
    }
    else
    {
      this->staticDebugSystemPanel->SetVisible(this: this->staticDebugSystemPanel, a2: false);
      if ( this->staticClientDLLPanel != nullptr )
        this->staticClientDLLPanel->SetVisible(this: this->staticClientDLLPanel, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206AB0
// Name: private: bool CEngineVGui::IsCtrlKeyDown(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVGui::IsCtrlKeyDown(CEngineVGui *this)
{
  if ( g_pVGuiInput == nullptr )
    return false;
  return g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
}

//------------------------------------------------------------------------------
// Address: 0x10206AF0
// Name: VGui_PlaySound
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_PlaySound(const char *pFileName)
{
  CSfxTable *v1; // edi
  CClientState *LocalClient; // eax
  StartSoundParams_t params; // [esp+8h] [ebp-64h] BYREF

  v1 = S_PrecacheSound(name: pFileName);
  if ( v1 != nullptr )
  {
    S_MarkUISound(pSfx: v1);
    params.userdata = 0;
    params.delay = 0.0;
    params.speakerentity = -1;
    params.initialStreamPosition = 0;
    params.skipInitialSamples = 0;
    params.m_nQueuedGUID = -1;
    params.m_nSoundScriptHandle = -1;
    memset(&params.m_pSoundEntryName, 0, 16);
    *((_BYTE *)&params + 96) = *((_BYTE *)&params + 96) & 0xC0 | 2;
    LocalClient = GetLocalClient(nSlot: -1);
    params.soundsource = CBaseClientState::GetViewEntity(this: LocalClient);
    memset(&params.origin, 0, 24);
    params.entchannel = 0;
    params.pSfx = v1;
    params.pitch = 100;
    params.soundlevel = SNDLVL_IDLE;
    params.flags = 0;
    params.fvol = 1.0;
    S_StartSound(&params);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206C00
// Name: void VGui_ActivateMouse(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_ActivateMouse()
{
  if ( g_ClientDLL != nullptr )
  {
    if ( game->IsActiveApp(this: game) && g_pVGuiSurface->IsCursorLocked(this: g_pVGuiSurface) && !g_bTextMode )
      g_ClientDLL->IN_ActivateMouse(this: g_ClientDLL);
    else
      g_ClientDLL->IN_DeactivateMouse(this: g_ClientDLL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206C60
// Name: void DumpPanels_r(unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpPanels_r(unsigned int panel, int level, bool bVisibleOnly)
{
  const char *v3; // edi
  bool v4; // al
  int v5; // ecx
  const char *v6; // ecx
  const char *v7; // eax
  int v8; // edi
  int v9; // esi
  unsigned int v10; // eax
  char indentBuff[32]; // [esp+8h] [ebp-28h] BYREF
  int v12; // [esp+28h] [ebp-8h]
  bool bVisible; // [esp+2Fh] [ebp-1h]

  v3 = g_pVGuiPanel->GetName(this: g_pVGuiPanel, a2: panel);
  v4 = g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: panel);
  bVisible = v4;
  if ( !bVisibleOnly || v4 )
  {
    v5 = 0;
    if ( level > 0 )
    {
      memset(dst: (unsigned __int8 *)indentBuff, value: 0x2Eu, count: level);
      v4 = bVisible;
      v5 = level;
    }
    indentBuff[v5] = 0;
    v6 = " (Visible)";
    if ( !v4 )
      v6 = " (Not Visible)";
    v7 = v3;
    if ( *v3 == 0 )
      v7 = "???";
    ConMsg(a1: "%s%s%s\n", indentBuff, v7, v6);
    v8 = g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: panel);
    v9 = 0;
    if ( v8 > 0 )
    {
      v12 = level + 1;
      do
      {
        v10 = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: panel, a3: v9);
        DumpPanels_r(panel: v10, level: v12, bVisibleOnly);
        ++v9;
      }
      while ( v9 < v8 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206D40
// Name: vgui_dump_panels
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui_dump_panels(const CCommand *args)
{
  int v1; // eax
  unsigned int v2; // eax
  bool bVisibleOnly; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc != 2 || (v1 = _V_stricmp(s1: args->m_ppArgv[1], s2: "visible"), bVisibleOnly = true, v1 != 0) )
    bVisibleOnly = false;
  v2 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  DumpPanels_r(panel: v2, level: 0, bVisibleOnly);
}

//------------------------------------------------------------------------------
// Address: 0x10206E30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10206E60
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10206E70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10206EC0
// Name: public: virtual void CEngineVGui::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::Init(CEngineVGui *this)
{
  bool v2; // bl
  int v3; // eax
  const char *v4; // ebx
  struct CSysModule *v5; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  InputContextHandle_t__ *v7; // eax
  InputContextHandle_t__ *v8; // eax
  int v9; // eax
  vgui::Panel *v10; // eax
  CStaticPanel *v11; // ebx
  CStaticPanel_vtbl *v12; // ebx
  unsigned int v13; // eax
  vgui::EditablePanel *v14; // eax
  CEnginePanel *v15; // ebx
  vgui::EditablePanel *v16; // eax
  CEnginePanel *v17; // ebx
  unsigned int v18; // eax
  CEnginePanel *v19; // ebx
  vgui::EditablePanel *v20; // eax
  CEnginePanel *v21; // ebx
  vgui::EditablePanel *v22; // eax
  CEnginePanel *v23; // ebx
  CEnginePanel *v24; // ebx
  int (__thiscall ***staticGameDLLPanel)(_DWORD); // ecx
  CDebugSystemPanel *v26; // eax
  CDebugSystemPanel *v27; // eax
  CTransitionEffectPanel *v28; // eax
  CTransitionEffectPanel *v29; // eax
  CFocusOverlayPanel *v30; // eax
  CFocusOverlayPanel *v31; // eax
  int v32; // eax
  IGameConsole_vtbl *v33; // ebx
  unsigned int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  unsigned int v42; // [esp-4h] [ebp-11Ch]
  int v43; // [esp-4h] [ebp-11Ch]
  int v44; // [esp+0h] [ebp-118h]
  int v45; // [esp+0h] [ebp-118h]
  char szFileName[260]; // [esp+Ch] [ebp-10Ch] BYREF
  unsigned int newParent; // [esp+110h] [ebp-8h]
  bool bTools; // [esp+117h] [ebp-1h]

  v2 = _V_stricmp(s1: "swarm", s2: host_parms.mod) != 0;
  if ( _V_stricmp(s1: "portal2", s2: host_parms.mod) == 0 )
    v2 = false;
  if ( _V_stricmp(s1: "cstrike15", s2: host_parms.mod) != 0
    && v2
    && (v3 = _CommandLine(a1: v44),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-nogameui") == 0) )
  {
    _COM_TimestampedLog(a1: "Loading gameui.dll");
    v4 = "gameui";
    v5 = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: "gameui", a3: "GAMEBIN", a4: 1);
    this->m_hStaticGameUIModule = v5;
    Factory = Sys_GetFactory(pModule: v5);
    this->m_GameUIFactory = Factory;
    if ( Factory == nullptr )
      _Error(a1: "Could not load: %s\n", "gameui");
  }
  else
  {
    DevMsg(a1: "Running -nogameui mode, using client module instead of gameui\n");
    this->m_GameUIFactory = g_ClientFactory;
    v4 = "client";
  }
  staticGameUIFuncs = (IGameUI *)this->m_GameUIFactory(a1: "GameUI011", a2: 0);
  if ( staticGameUIFuncs == nullptr )
    _Error(a1: "Could not get IGameUI interface %s from %s\n", "GameUI011", v4);
  staticGameConsole = (IGameConsole *)this->m_GameUIFactory(a1: "GameConsole004", a2: 0);
  if ( staticGameConsole == nullptr )
    Sys_Error(error: "Could not get IGameConsole interface %s from %s\n", "GameConsole004", v4);
  v7 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  this->m_hGameUIInputContext = v7;
  g_pInputStackSystem->EnableInputContext(this: g_pInputStackSystem, a2: v7, a3: false);
  v8 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: v8);
  vgui::VGui_InitMatSysInterfacesList(moduleName: "BaseUI", factoryList: &g_AppSystemFactory, numFactories: 1);
  _COM_TimestampedLog(a1: "AttachToWindow");
  g_pMatSystemSurface->InstallPlaySoundFunc(this: g_pMatSystemSurface, a2: VGui_PlaySound);
  _COM_TimestampedLog(a1: "Load Scheme File");
  if ( g_pVGuiSchemeManager->LoadSchemeFromFile(
         this: g_pVGuiSchemeManager,
         a2: "Resource/SourceScheme.res",
         a3: "Tracker") != 0 )
  {
    _COM_TimestampedLog(a1: "ivgui()->Start()");
    g_pVGui->Start(this: g_pVGui);
    g_pVGui->SetSleep(this: g_pVGui, a2: false);
    v9 = _CommandLine(a1: v44);
    bTools = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 12))(a1: v9, a2: "-tools", a3: 0) != 0;
    _COM_TimestampedLog(a1: "Building Panels (staticPanel)");
    v10 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
    v11 = (CStaticPanel *)v10;
    if ( v10 != nullptr )
    {
      vgui::Panel::Panel(this: v10, parent: nullptr, panelName: "staticPanel");
      v11->__vftable = (CStaticPanel_vtbl *)&CStaticPanel::`vftable';
      vgui::Panel::SetCursor(this: v11, cursor: 1u);
      vgui::Panel::SetKeyBoardInputEnabled(this: v11, state: false);
      vgui::Panel::SetMouseInputEnabled(this: v11, state: false);
    }
    else
    {
      v11 = nullptr;
    }
    this->staticPanel = v11;
    v12 = v11->__vftable;
    v13 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
    v12->SetParent(this: this->staticPanel, a2: v13);
    CEngineVGui::PreparePanel(this, panel: this->staticPanel, nZPos: 0, bVisible: true);
    _COM_TimestampedLog(a1: "Building Panels (staticGameUIBackgroundPanel)");
    v14 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    v15 = (CEnginePanel *)v14;
    if ( v14 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v14, parent: this->staticPanel, panelName: "GameUI Background Panel");
      v15->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v15, state: true);
      vgui::Panel::SetKeyBoardInputEnabled(this: v15, state: true);
    }
    else
    {
      v15 = nullptr;
    }
    this->staticGameUIBackgroundPanel = v15;
    CEngineVGui::PreparePanel(this, panel: v15, nZPos: 0, bVisible: true);
    _COM_TimestampedLog(a1: "Building Panels (staticClientDLLPanel)");
    v16 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    v17 = (CEnginePanel *)v16;
    if ( v16 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v16, parent: this->staticPanel, panelName: "staticClientDLLPanel");
      v17->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v17, state: true);
      vgui::Panel::SetKeyBoardInputEnabled(this: v17, state: true);
    }
    else
    {
      v17 = nullptr;
    }
    this->staticClientDLLPanel = v17;
    CEngineVGui::PreparePanel(this, panel: v17, nZPos: 25, bVisible: false);
    this->staticClientDLLPanel->SetKeyBoardInputEnabled(this: this->staticClientDLLPanel, a2: false);
    _COM_TimestampedLog(a1: "Building Panels (CreateAskConnectPanel)");
    v18 = this->staticPanel->GetVPanel(this: this->staticPanel);
    CreateAskConnectPanel(parent: v18);
    _COM_TimestampedLog(a1: "Building Panels (staticClientDLLToolsPanel)");
    v19 = (CEnginePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    if ( v19 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v19, parent: this->staticPanel, panelName: "staticClientDLLToolsPanel");
      v19->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v19, state: true);
      vgui::Panel::SetKeyBoardInputEnabled(this: v19, state: true);
    }
    else
    {
      v19 = nullptr;
    }
    this->staticClientDLLToolsPanel = v19;
    CEngineVGui::PreparePanel(this, panel: v19, nZPos: 28, bVisible: true);
    this->staticClientDLLToolsPanel->SetKeyBoardInputEnabled(this: this->staticClientDLLToolsPanel, a2: false);
    _COM_TimestampedLog(a1: "Building Panels (staticGameUIPanel)");
    v20 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    v21 = (CEnginePanel *)v20;
    if ( v20 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v20, parent: this->staticPanel, panelName: "GameUI Panel");
      v21->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v21, state: true);
      vgui::Panel::SetKeyBoardInputEnabled(this: v21, state: true);
    }
    else
    {
      v21 = nullptr;
    }
    this->staticGameUIPanel = v21;
    CEngineVGui::PreparePanel(this, panel: v21, nZPos: 100, bVisible: true);
    _COM_TimestampedLog(a1: "Building Panels (staticGameDLLPanel)");
    v22 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    v23 = (CEnginePanel *)v22;
    if ( v22 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v22, parent: this->staticPanel, panelName: "staticGameDLLPanel");
      v23->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetMouseInputEnabled(this: v23, state: true);
      vgui::Panel::SetKeyBoardInputEnabled(this: v23, state: true);
    }
    else
    {
      v23 = nullptr;
    }
    this->staticGameDLLPanel = v23;
    CEngineVGui::PreparePanel(this, panel: v23, nZPos: 135, bVisible: true);
    this->staticGameDLLPanel->SetKeyBoardInputEnabled(this: this->staticGameDLLPanel, a2: false);
    _COM_TimestampedLog(a1: "Building Panels (Engine Tools)");
    v24 = (CEnginePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    if ( v24 != nullptr )
    {
      if ( bTools )
        staticGameDLLPanel = (int (__thiscall ***)(_DWORD))this->staticGameDLLPanel;
      else
        staticGameDLLPanel = (int (__thiscall ***)(_DWORD))this->staticPanel;
      newParent = (**staticGameDLLPanel)(a1: staticGameDLLPanel);
      vgui::EditablePanel::EditablePanel(this: v24, parent: nullptr, panelName: "Engine Tools");
      v42 = newParent;
      v24->__vftable = (CEnginePanel_vtbl *)&CEnginePanel::`vftable';
      vgui::Panel::SetParent(this: v24, newParent: v42);
      vgui::Panel::SetMouseInputEnabled(this: v24, state: true);
      vgui::Panel::SetKeyBoardInputEnabled(this: v24, state: true);
    }
    else
    {
      v24 = nullptr;
    }
    this->staticEngineToolsPanel = v24;
    CEngineVGui::PreparePanel(this, panel: v24, nZPos: 100, bVisible: true);
    this->staticEngineToolsPanel->SetKeyBoardInputEnabled(this: this->staticEngineToolsPanel, a2: false);
    this->staticEngineToolsPanel->SetMouseInputEnabled(this: this->staticEngineToolsPanel, a2: false);
    _COM_TimestampedLog(a1: "Building Panels (staticDebugSystemPanel)");
    v26 = (CDebugSystemPanel *)MemAlloc_Alloc(nSize: 0x154u);
    if ( v26 != nullptr )
      v27 = CDebugSystemPanel::CDebugSystemPanel(this: v26, parent: this->staticPanel, panelName: "Engine Debug System");
    else
      v27 = nullptr;
    this->staticDebugSystemPanel = v27;
    vgui::Panel::SetZPos(this: v27, z: 125);
    CDemoUIPanel::InstallDemoUI(parent: this->staticEngineToolsPanel);
    CDemoUIPanel2::Install(
      pParentBkgnd: this->staticClientDLLPanel,
      pParentFgnd: this->staticEngineToolsPanel,
      bPutToForeground: true);
    CFogUIPanel::InstallFogUI(parent: this->staticEngineToolsPanel);
    TxViewPanel::Install(parent: this->staticEngineToolsPanel);
    _COM_TimestampedLog(a1: "Install bug reporter");
    bugreporter->InstallBugReportingUI(this: bugreporter, a2: this->staticGameUIPanel, a3: BR_AUTOSELECT);
    bugreporter->Init(this: bugreporter);
    _COM_TimestampedLog(a1: "Install perf tools");
    perftools->InstallPerformanceToolsUI(this: perftools, a2: this->staticEngineToolsPanel);
    perftools->Init(this: perftools);
    colorcorrectiontools->InstallColorCorrectionUI(this: colorcorrectiontools, a2: this->staticEngineToolsPanel);
    colorcorrectiontools->Init(this: colorcorrectiontools);
    _COM_TimestampedLog(a1: "Building Panels (staticTransitionPanel)");
    v28 = (CTransitionEffectPanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    if ( v28 != nullptr )
      v29 = CTransitionEffectPanel::CTransitionEffectPanel(
              this: v28,
              pParent: this->staticPanel,
              pName: "TransitionEffect");
    else
      v29 = nullptr;
    this->staticTransitionPanel = v29;
    vgui::Panel::SetZPos(this: v29, z: 135);
    _COM_TimestampedLog(a1: "Building Panels (FocusOverlayPanel)");
    v30 = (CFocusOverlayPanel *)MemAlloc_Alloc(nSize: 0x14Cu);
    if ( v30 != nullptr )
      v31 = CFocusOverlayPanel::CFocusOverlayPanel(this: v30, pParent: this->staticPanel, pName: "FocusOverlayPanel");
    else
      v31 = nullptr;
    this->staticFocusOverlayPanel = v31;
    v43 = videomode->GetModeHeight(this: videomode);
    v32 = videomode->GetModeWidth(this: videomode);
    vgui::Panel::SetBounds(this: this->staticFocusOverlayPanel, x: 0, y: 0, wide: v32, tall: v43);
    vgui::Panel::SetZPos(this: this->staticFocusOverlayPanel, z: 150);
    this->staticFocusOverlayPanel->MoveToFront(this: this->staticFocusOverlayPanel);
    _COM_TimestampedLog(a1: "Building Panels (console, entity report, drawtree, texturelist, vprof)");
    Con_CreateConsolePanel(parent: this->staticEngineToolsPanel);
    CL_CreateEntityReportPanel(parent: this->staticEngineToolsPanel);
    VGui_CreateDrawTreePanel(parent: this->staticEngineToolsPanel);
    CL_CreateTextureListPanel(parent: this->staticEngineToolsPanel);
    CEngineVGui::CreateVProfPanels(this, pParent: this->staticEngineToolsPanel);
    this->staticEngineToolsPanel->LoadControlSettings(
      this: this->staticEngineToolsPanel,
      a2: "scripts/EngineVGuiLayout.res",
      a3: nullptr,
      a4: nullptr,
      a5: nullptr);
    this->m_pVProfPanel->SetVisible(this: this->m_pVProfPanel, a2: false);
    this->m_pBudgetPanel->SetVisible(this: this->m_pBudgetPanel, a2: false);
    HideVProfGraphPanel();
    this->m_pTextureBudgetPanel->SetVisible(this: this->m_pTextureBudgetPanel, a2: false);
    _COM_TimestampedLog(a1: "materials->CacheUsedMaterials()");
    materials->CacheUsedMaterials(this: materials);
    _COM_TimestampedLog(a1: "g_pVGuiLocalize->AddFile");
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/valve_%language%.txt", a3: nullptr, a4: false);
    V_snprintf(pDest: szFileName, maxLen: 259, pFormat: "resource/%s_%%language%%.txt", host_parms.mod);
    szFileName[259] = 0;
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: szFileName, a3: nullptr, a4: false);
    if ( g_bLowViolence )
    {
      V_snprintf(pDest: szFileName, maxLen: 259, pFormat: "resource/%s_%%language%%_lv.txt", host_parms.mod);
      szFileName[259] = 0;
      g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: szFileName, a3: nullptr, a4: false);
    }
    _COM_TimestampedLog(a1: "staticGameUIFuncs->Initialize");
    staticGameUIFuncs->Initialize(this: staticGameUIFuncs, a2: g_GameSystemFactory);
    _COM_TimestampedLog(a1: "staticGameUIFuncs->Start");
    staticGameUIFuncs->Start(this: staticGameUIFuncs);
    if ( staticGameConsole != nullptr )
    {
      staticGameConsole->Initialize(this: staticGameConsole);
      v33 = staticGameConsole->__vftable;
      v34 = this->staticGameUIPanel->GetVPanel(this: this->staticGameUIPanel);
      v33->SetParent(this: staticGameConsole, a2: v34);
    }
    _COM_TimestampedLog(a1: "ActivateGameUI()");
    this->ActivateGameUI(this);
    if ( staticGameConsole != nullptr )
    {
      v35 = _CommandLine(a1: v45);
      if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v35 + 12))(
             a1: v35,
             a2: "-forcestartupmenu",
             a3: 0) == 0 )
      {
        v36 = _CommandLine(a1: v45);
        if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v36 + 12))(
               a1: v36,
               a2: "-hideconsole",
               a3: 0) == 0 )
        {
          v37 = _CommandLine(a1: v45);
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v37 + 40))(a1: v37, a2: "-toconsole") != 0
            || (v38 = _CommandLine(a1: v45),
                (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v38 + 40))(a1: v38, a2: "-console") != 0)
            || (v39 = _CommandLine(a1: v45),
                (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v39 + 40))(a1: v39, a2: "-rpt") != 0)
            || (v40 = _CommandLine(a1: v45),
                (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v40 + 40))(a1: v40, a2: "-allowdebug") != 0) )
          {
            staticGameConsole->Activate(this: staticGameConsole);
          }
        }
      }
    }
    v41 = _CommandLine(a1: v45);
    *((_BYTE *)this + 220) ^= (*((_BYTE *)this + 220)
                             ^ (2
                              * ((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v41 + 40))(
                                   a1: v41,
                                   a2: "-noshaderapi") != 0)))
                            & 2;
  }
  else
  {
    Sys_Error(error: "Error loading file %s\n", "Resource/SourceScheme.res");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207840
// Name: public: virtual bool CEngineVGui::Key_Event(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineVGui::Key_Event(CEngineVGui *this, const InputEvent_t *event)
{
  bool v2; // bl
  vgui::IInput *v3; // ecx
  ButtonCode_t m_nData; // esi
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  ButtonCode_t BaseButtonCode; // eax
  const char *v9; // eax
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t v11; // eax
  const char *v12; // [esp-8h] [ebp-18h]

  v2 = event->m_nType == 0 || event->m_nType == 2;
  v3 = g_pVGuiInput;
  m_nData = event->m_nData;
  if ( g_pVGuiInput != nullptr )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
    {
      if ( m_nData == KEY_F1 )
      {
        if ( v2 )
        {
          v12 = "debugsystemui";
          goto LABEL_14;
        }
        return true;
      }
      if ( m_nData == KEY_F2 )
      {
        if ( v2 )
        {
          v12 = "demoui";
LABEL_14:
          TraceType = CTraceFilter::GetTraceType(this: v5);
          Cbuf_AddText(eTarget: TraceType, pText: v12, nTickDelay: 0);
          return true;
        }
        return true;
      }
    }
    v3 = g_pVGuiInput;
  }
  if ( m_nData == KEY_BACKQUOTE
    && (v3 != nullptr
     && (v3->IsKeyDown(this: v3, a2: KEY_LALT) || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT))
     || CEngineVGui::IsCtrlKeyDown(this)) )
  {
    return true;
  }
  if ( v2 )
  {
    BaseButtonCode = GetBaseButtonCode(code: m_nData);
    if ( BaseButtonCode == KEY_ESCAPE || BaseButtonCode == KEY_XBUTTON_START )
    {
      if ( this->IsGameUIVisible(this) )
      {
        v9 = engineClient->GetLevelName(this: engineClient);
        if ( v9 == nullptr )
          return true;
        if ( *v9 == 0 )
          return true;
        v11 = CTraceFilter::GetTraceType(this: v10);
        Cbuf_AddText(eTarget: v11, pText: "gameui_hide", nTickDelay: 0);
        if ( !CEngineVGui::IsDebugSystemVisible(this) )
          return true;
        v12 = "debugsystemui 0";
      }
      else
      {
        v12 = "gameui_activate";
      }
      goto LABEL_14;
    }
  }
  return g_pMatSystemSurface != nullptr
      && g_pMatSystemSurface->HandleInputEvent(this: g_pMatSystemSurface, a2: event)
      && m_nData != KEY_BACKQUOTE;
}

//------------------------------------------------------------------------------
// Address: 0x102079C0
// Name: public: void CVGuiPaintHelper::Paint(unsigned int,enum PaintMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::Paint(CVGuiPaintHelper *this, unsigned int rootPanel, BOOL mode)
{
  int v4; // edi
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // ebx

  if ( mode )
  {
    v4 = 0;
    if ( this->m_Entries.m_Size > 0 )
    {
      v5 = 0;
      do
      {
        CVGuiPaintHelper::MapHide(this, entry: &this->m_Entries.m_Memory.m_pMemory[v5]);
        ++v4;
        ++v5;
      }
      while ( v4 < this->m_Entries.m_Size );
    }
    g_pVGuiSurface->PaintTraverseEx(this: g_pVGuiSurface, a2: rootPanel, a3: true);
    v6 = 0;
    if ( this->m_Entries.m_Size > 0 )
    {
      v7 = 0;
      do
      {
        CVGuiPaintHelper::MapRestore(this, entry: &this->m_Entries.m_Memory.m_pMemory[v7]);
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_Entries.m_Size );
    }
  }
  if ( (mode & 2) != 0 )
  {
    LOBYTE(mode) = g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: rootPanel);
    g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: rootPanel, a3: false);
    v8 = 0;
    if ( this->m_Entries.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        CVGuiPaintHelper::MapPaintTraverse(this, entry: &this->m_Entries.m_Memory.m_pMemory[v9]);
        ++v8;
        ++v9;
      }
      while ( v8 < this->m_Entries.m_Size );
    }
    g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: rootPanel, a3: mode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207A90
// Name: public: bool CFocusOverlayPanel::DrawTitleSafeOverlay(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFocusOverlayPanel::DrawTitleSafeOverlay(CFocusOverlayPanel *this)
{
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // ebx
  int backBufferHeight; // [esp+0h] [ebp-Ch] BYREF
  int backBufferWidth; // [esp+4h] [ebp-8h] BYREF
  int y1; // [esp+8h] [ebp-4h]

  if ( mat_drawTitleSafe.m_pParent == nullptr || mat_drawTitleSafe.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  materials->GetBackBufferDimensions(this: materials, a2: &backBufferWidth, a3: &backBufferHeight);
  v2 = (int)(float)((float)backBufferWidth * 0.050000001);
  v3 = (int)(float)((float)backBufferHeight * 0.050000001);
  y1 = backBufferHeight - v3;
  v4 = backBufferWidth - v2;
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v2, a3: v3, a4: v4, a5: y1);
  v5 = (int)(float)((float)backBufferWidth * 0.075000003);
  v6 = (int)(float)((float)backBufferHeight * 0.075000003);
  y1 = backBufferHeight - v6;
  v7 = backBufferWidth - v5;
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 0, a5: 255);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v5, a3: v6, a4: v7, a5: y1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10207BA0
// Name: public: bool CFocusOverlayPanel::DrawKeyFocusPanel(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFocusOverlayPanel::DrawKeyFocusPanel(CFocusOverlayPanel *this)
{
  int v2; // eax
  int v3; // eax
  void (__thiscall *v4)(vgui::ISurface *, Color); // edx
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  int x; // [esp+0h] [ebp-14h] BYREF
  int y; // [esp+4h] [ebp-10h] BYREF
  int x1; // [esp+8h] [ebp-Ch] BYREF
  int y1; // [esp+Ch] [ebp-8h] BYREF
  int v10; // [esp+10h] [ebp-4h]

  if ( vgui_drawkeyfocus.m_pParent == nullptr || vgui_drawkeyfocus.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  if ( g_KeyFocusPanel != 0 )
  {
    g_pVGuiPanel->GetClipRect(this: g_pVGuiPanel, a2: g_KeyFocusPanel, a3: &x, a4: &y, a5: &x1, a6: &y1);
    v2 = videomode->GetModeWidth(this: videomode);
    if ( x1 - x == v2 )
    {
      v3 = videomode->GetModeHeight(this: videomode);
      if ( y1 - y == v3 )
      {
        ++x;
        ++y;
        --x1;
        --y1;
      }
    }
    if ( g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) % 500 <= 250 )
    {
      DrawSetColor = g_pVGuiSurface->DrawSetColor;
      v10 = -1;
      ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -1);
    }
    else
    {
      v4 = g_pVGuiSurface->DrawSetColor;
      v10 = -16777216;
      ((void (__thiscall *)(vgui::ISurface *, int))v4)(a1: g_pVGuiSurface, a2: -16777216);
    }
    g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x1, a5: y1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10207CA0
// Name: public: bool CFocusOverlayPanel::DrawFocusPanelList(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CFocusOverlayPanel::DrawFocusPanelList@<al>(
        CFocusOverlayPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>)
{
  int m_Size; // ecx
  int v6; // eax
  int v7; // ebx
  int v8; // esi
  unsigned int v9; // edi
  int v10; // eax
  int v11; // eax
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  int c; // [esp+0h] [ebp-28h]
  int b; // [esp+4h] [ebp-24h] BYREF
  int g; // [esp+8h] [ebp-20h] BYREF
  int r; // [esp+Ch] [ebp-1Ch] BYREF
  int i; // [esp+10h] [ebp-18h]
  int x; // [esp+14h] [ebp-14h] BYREF
  int y; // [esp+18h] [ebp-10h] BYREF
  int x1; // [esp+1Ch] [ebp-Ch] BYREF
  int y1; // [esp+20h] [ebp-8h] BYREF
  int v25; // [esp+24h] [ebp-4h]

  if ( vgui_drawfocus.m_pParent == nullptr )
    return 0;
  if ( vgui_drawfocus.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  m_Size = g_FocusPanelList.m_Size;
  c = g_FocusPanelList.m_Size;
  if ( g_FocusPanelList.m_Size <= 0 )
    return 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  i = 0;
  while ( 1 )
  {
    if ( v7 > 31 )
      return 1;
    v9 = g_FocusPanelList.m_Memory.m_pMemory[v6];
    if ( v9 != 0 )
      break;
LABEL_13:
    i = ++v6;
    if ( v6 >= m_Size )
      return 1;
  }
  if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, unsigned int, int, int, int))g_pVGuiPanel->IsFullyVisible)(
         a1: g_pVGuiPanel,
         a2: v9,
         a3,
         a4,
         a5: a2) != 0 )
  {
    CFocusOverlayPanel::GetColorForSlot(slot: v7, &r, &g, &b);
    g_pVGuiPanel->GetClipRect(this: g_pVGuiPanel, a2: v9, a3: &x, a4: &y, a5: &x1, a6: &y1);
    v10 = videomode->GetModeWidth(this: videomode);
    if ( x1 - x == v10 )
    {
      v11 = videomode->GetModeHeight(this: videomode);
      if ( y1 - y == v11 )
      {
        x += v8;
        y += v8;
        x1 -= v8;
        y1 -= v8++;
      }
    }
    LOBYTE(v25) = r;
    BYTE1(v25) = g;
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    BYTE2(v25) = b;
    HIBYTE(v25) = -1;
    ((void (__thiscall *)(vgui::ISurface *, int, int))DrawSetColor)(a1: g_pVGuiSurface, a2: v25, a3: c);
    c = y1;
    a2 = x1;
    a4 = y;
    a3 = x;
    ((void (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->DrawOutlinedRect)(a1: g_pVGuiSurface);
    m_Size = c;
    v6 = i;
    ++v7;
    goto LABEL_13;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10207DF0
// Name: public: virtual void CEngineVGui::OnLevelLoadingStarted(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::OnLevelLoadingStarted(CEngineVGui *this, const char *levelName, bool bLocalServer)
{
  ConVar *v4; // eax
  ConVar *m_pParent; // ecx
  CStatTime *v6; // ecx

  if ( staticGameUIFuncs != nullptr )
  {
    v4 = g_pCVar->FindVar_2(this: g_pCVar, a2: "fs_report_sync_opens");
    if ( v4 != nullptr )
    {
      m_pParent = v4->m_pParent;
      if ( m_pParent != nullptr )
      {
        g_syncReportLevel = m_pParent->m_Value.m_nValue;
        if ( g_syncReportLevel > 1 )
          v4->SetValue_2(this: &v4->IConVar, a2: 0);
      }
      else
      {
        g_syncReportLevel = 0;
      }
    }
    ((void (__stdcall *)(const char *, bool))staticGameUIFuncs->OnLevelLoadingStarted)(
      a1: levelName,
      a2: this->m_bShowProgressDialog);
    this->m_flLoadingStartTime = _Plat_FloatTime(this: v6);
    this->m_LoadingProgress.m_Size = 0;
    this->m_eLastProgressPoint = PROGRESS_NONE;
    this->m_nLastProgressPointRepeatCount = 0;
    this->m_ProgressBias = 0.0;
    g_pLoadingProgressDescriptions = g_RemoteConnectLoadingProgressDescriptions;
    if ( bLocalServer )
      g_pLoadingProgressDescriptions = g_ListenServerLoadingProgressDescriptions;
    if ( this->m_bShowProgressDialog )
      this->ActivateGameUI(this);
    this->m_bShowProgressDialog = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207EC0
// Name: public: virtual void CFocusOverlayPanel::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFocusOverlayPanel::PostChildPaint(CFocusOverlayPanel *this@<ecx>, int a2@<esi>)
{
  char v3; // bl
  vgui::IPanel *v4; // esi
  unsigned int v5; // eax
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  int v7; // [esp-4h] [ebp-20h]
  int x; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int x1; // [esp+10h] [ebp-Ch] BYREF
  int y1; // [esp+14h] [ebp-8h] BYREF
  int v12; // [esp+18h] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  v3 = 0;
  if ( vgui::VPanelHandle::Get(this: &g_DrawTreeSelectedPanel) != 0 )
  {
    v7 = a2;
    v4 = g_pVGuiPanel;
    v5 = vgui::VPanelHandle::Get(this: &g_DrawTreeSelectedPanel);
    v4->GetClipRect(this: v4, a2: v5, a3: &x, a4: &y, a5: &x1, a6: &y1);
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    v12 = -16776961;
    ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -16776961);
    g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x1, a5: y1);
    v3 = 1;
    a2 = v7;
  }
  if ( CFocusOverlayPanel::DrawTitleSafeOverlay(this) != 0 )
    v3 = 1;
  if ( CFocusOverlayPanel::DrawFocusPanelList(this, a2: v3, a3: (int)this, a4: a2) != 0 )
    v3 = 1;
  if ( CFocusOverlayPanel::DrawKeyFocusPanel(this) != 0 || v3 != 0 )
    this->MoveToFront(this);
}

//------------------------------------------------------------------------------
// Address: 0x10207F80
// Name: public: virtual void __near * (*CEngineVGui::GetGameUIFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__thiscall CEngineVGui::GetGameUIFactory(CEngineVGui *this))(const char *, int *)
{
  return this->m_GameUIFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10207FA0
// Name: public: virtual void CEngineVGui::SetNotAllowedToHideGameUI(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::SetNotAllowedToHideGameUI(CEngineVGui *this, bool bNotAllowedToHide)
{
  *((_BYTE *)this + 220) ^= (*((_BYTE *)this + 220) ^ (4 * bNotAllowedToHide)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x10207FC0
// Name: public: virtual void CEngineVGui::SetNotAllowedToShowGameUI(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::SetNotAllowedToShowGameUI(CEngineVGui *this, bool bNotAllowedToShow)
{
  *((_BYTE *)this + 220) ^= (*((_BYTE *)this + 220) ^ (8 * bNotAllowedToShow)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10207FE0
// Name: public: virtual void CEngineVGui::HideLoadingPlaque(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::HideLoadingPlaque(CEngineVGui *this)
{
  if ( scr_drawloading )
  {
    this->OnLevelLoadingFinished(this);
    S_OnLoadScreen(value: false);
  }
  S_PreventSound(bSetting: false);
  scr_disabled_for_loading = false;
  scr_drawloading = false;
}

//------------------------------------------------------------------------------
// Address: 0x10208020
// Name: public: virtual void CEngineVGui::SetGameDLLPanelsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::SetGameDLLPanelsVisible(CEngineVGui *this, BOOL show)
{
  if ( this->staticGameDLLPanel != nullptr )
    this->staticGameDLLPanel->SetVisible(this: this->staticGameDLLPanel, a2: show);
}

//------------------------------------------------------------------------------
// Address: 0x10208050
// Name: public: virtual struct InputContextHandle_t__ __near * CEngineVGui::GetGameUIInputContext(void)
// Source: json
//------------------------------------------------------------------------------
InputContextHandle_t__ *__thiscall CEngineVGui::GetGameUIInputContext(CEngineVGui *this)
{
  return this->m_hGameUIInputContext;
}

//------------------------------------------------------------------------------
// Address: 0x10208060
// Name: VGui_RecursiveFindPanels
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_RecursiveFindPanels(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *panelList,
        unsigned int check,
        const char *panelname)
{
  vgui::Panel *v3; // ebx
  const char *v4; // eax
  int v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned int *m_pMemory; // ecx
  int v9; // eax
  unsigned int *v10; // edi
  int v11; // edi
  vgui::Panel *Child; // eax
  unsigned int v13; // eax
  int v14; // [esp-Ch] [ebp-14h]
  int childcount; // [esp+4h] [ebp-4h]
  int childcounta; // [esp+4h] [ebp-4h]

  v3 = g_pVGuiPanel->GetPanel(this: g_pVGuiPanel, a2: check, a3: "ENGINE");
  if ( v3 != nullptr )
  {
    v14 = strlen(panelname);
    v4 = v3->GetName(this: v3);
    if ( V_strncmp(s1: v4, s2: panelname, count: v14) == 0 )
    {
      v5 = v3->GetVPanel(this: v3);
      m_Size = panelList->m_Size;
      childcount = v5;
      m_nAllocationCount = panelList->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)panelList,
          num: m_Size - m_nAllocationCount + 1);
      ++panelList->m_Size;
      m_pMemory = panelList->m_Memory.m_pMemory;
      v9 = panelList->m_Size - m_Size - 1;
      panelList->m_pElements = panelList->m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v10 = &panelList->m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        *v10 = childcount;
    }
    v11 = 0;
    childcounta = vgui::Panel::GetChildCount(this: v3);
    if ( childcounta > 0 )
    {
      do
      {
        Child = vgui::Panel::GetChild(this: v3, index: v11);
        v13 = Child->GetVPanel(this: Child);
        VGui_RecursiveFindPanels(panelList, check: v13, panelname);
        ++v11;
      }
      while ( v11 < childcounta );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208150
// Name: void VGui_FindNamedPanels(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_FindNamedPanels(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *panelList,
        const char *panelname)
{
  unsigned int v2; // edi
  int i; // esi

  v2 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  for ( i = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1; i >= 0; --i )
    g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: i);
  VGui_RecursiveFindPanels(panelList, check: v2, panelname);
}

//------------------------------------------------------------------------------
// Address: 0x102081B0
// Name: vgui_togglepanel
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui_togglepanel(const CCommand *args)
{
  int m_nArgc; // eax
  int v3; // eax
  bool v4; // cc
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  int v8; // edi
  BOOL v9; // ebx
  unsigned int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // esi
  const char *v13; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > panelList; // [esp+4h] [ebp-1Ch] BYREF
  BOOL flip; // [esp+1Bh] [ebp-5h]
  bool bg; // [esp+1Fh] [ebp-1h]
  bool fg_3; // [esp+2Bh] [ebp+Bh]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    LOBYTE(flip) = 0;
    fg_3 = true;
    bg = true;
    if ( m_nArgc == 5 )
    {
      v3 = atoi(nptr: args->m_ppArgv[2]);
      v4 = args->m_nArgc <= 3;
      LOBYTE(flip) = v3 != 0;
      v5 = defaultValue;
      if ( !v4 )
        v5 = args->m_ppArgv[3];
      fg_3 = atoi(nptr: v5) != 0;
      v6 = defaultValue;
      if ( args->m_nArgc > 4 )
        v6 = args->m_ppArgv[4];
      bg = atoi(nptr: v6) != 0;
    }
    if ( args->m_nArgc > 1 )
    {
      v7 = args->m_ppArgv[1];
      v8 = 0;
      if ( v7 != nullptr && *v7 != 0 )
      {
        memset(&panelList, 0, sizeof(panelList));
        VGui_FindNamedPanels(&panelList, panelname: v7);
        if ( panelList.m_Size != 0 )
        {
          if ( panelList.m_Size > 0 )
          {
            v9 = flip;
            do
            {
              v10 = panelList.m_Memory.m_pMemory[v8];
              if ( v10 != 0 )
              {
                v11 = g_pVGuiPanel->GetPanel(this: g_pVGuiPanel, a2: v10, a3: "ENGINE");
                v12 = v11;
                if ( v11 != nullptr )
                {
                  v13 = v11->GetName(this: v11);
                  _Msg(a1: "Toggling %s\n", v13);
                  if ( fg_3 )
                    v12->SetPaintEnabled(this: v12, a2: v9);
                  if ( bg )
                    v12->SetPaintBackgroundEnabled(this: v12, a2: v9);
                }
              }
              ++v8;
            }
            while ( v8 < panelList.m_Size );
          }
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&panelList);
        }
        else
        {
          ConMsg(a1: "No panels starting with %s\n", v7);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&panelList);
        }
      }
    }
  }
  else
  {
    ConMsg(a1: "Usage:  vgui_showpanel panelname\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208320
// Name: VGui_RecursePanel
// Source: json
//------------------------------------------------------------------------------
void __usercall VGui_RecursePanel(
        int a1@<edi>,
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *panelList,
        int x,
        int y,
        unsigned int check,
        bool include_hidden)
{
  int m_Size; // edi
  int v7; // eax
  unsigned int *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  unsigned int *v10; // ecx
  int v11; // eax
  unsigned int *v12; // edi
  int v13; // ebx
  int i; // edi
  unsigned int v15; // eax

  if ( include_hidden || g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: check) )
  {
    if ( ((int (__thiscall *)(vgui::IPanel *, unsigned int, int, int, _DWORD, int))g_pVGuiPanel->IsWithinTraverse)(
           a1: g_pVGuiPanel,
           a2: check,
           a3: x,
           a4: y,
           a5: 0,
           a6: a1) != 0 )
    {
      m_Size = panelList->m_Size;
      v7 = 0;
      if ( m_Size <= 0 )
        goto LABEL_10;
      m_pMemory = panelList->m_Memory.m_pMemory;
      while ( *m_pMemory != check )
      {
        ++v7;
        ++m_pMemory;
        if ( v7 >= m_Size )
          goto LABEL_10;
      }
      if ( v7 == -1 )
      {
LABEL_10:
        m_nAllocationCount = panelList->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)panelList,
            num: m_Size - m_nAllocationCount + 1);
        ++panelList->m_Size;
        v10 = panelList->m_Memory.m_pMemory;
        v11 = panelList->m_Size - m_Size - 1;
        panelList->m_pElements = panelList->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 4 * v11);
        v12 = &panelList->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = check;
      }
    }
    v13 = g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: check);
    for ( i = 0; i < v13; ++i )
    {
      v15 = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: check, a3: i);
      VGui_RecursePanel(panelList, x, y, check: v15, include_hidden);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208420
// Name: private: void CEngineVGui::DrawMouseFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEngineVGui::DrawMouseFocus(CEngineVGui *this@<ecx>, int a2@<edi>, unsigned int a3@<esi>)
{
  int m_nValue; // eax
  void (__thiscall *GetCursorPos)(vgui::IInput *, int *, int *); // edx
  int j; // edi
  unsigned int v6; // eax
  unsigned int v7; // esi
  int m_Size; // ecx
  int v9; // edi
  int v10; // eax
  unsigned int v11; // esi
  double v12; // st7
  int v13; // eax
  vgui::IPanel *v14; // ebx
  const char *v15; // eax
  int v16; // [esp-14h] [ebp-40h]
  int v17; // [esp-10h] [ebp-3Ch]
  con_nprint_s np; // [esp+0h] [ebp-2Ch] BYREF
  int c; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  unsigned int embedded; // [esp+20h] [ebp-Ch]
  int x; // [esp+24h] [ebp-8h] BYREF
  int y; // [esp+28h] [ebp-4h] BYREF

  g_FocusPanelList.m_Size = 0;
  if ( vgui_drawfocus.m_pParent != nullptr && vgui_drawfocus.m_pParent->m_Value.m_nValue != 0 )
  {
    this->staticFocusOverlayPanel->MoveToFront(this: this->staticFocusOverlayPanel);
    if ( vgui_drawfocus.m_pParent != nullptr )
      m_nValue = vgui_drawfocus.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    GetCursorPos = g_pVGuiInput->GetCursorPos;
    LOBYTE(i) = m_nValue == 2;
    GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    embedded = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
    if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
      && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
    {
      for ( j = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1; j >= 0; --j )
      {
        v6 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: j);
        v7 = v6;
        if ( v6 != 0 && v6 != embedded && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v6) )
          VGui_RecursePanel(a1: j, panelList: &g_FocusPanelList, x, y, check: v7, include_hidden: i);
      }
      VGui_RecursePanel(a1: j, panelList: &g_FocusPanelList, x, y, check: embedded, include_hidden: i);
    }
    m_Size = g_FocusPanelList.m_Size;
    v9 = 0;
    v10 = 0;
    np.time_to_live = 1.0;
    c = g_FocusPanelList.m_Size;
    embedded = 0;
    i = 0;
    if ( g_FocusPanelList.m_Size <= 0 )
    {
      do
LABEL_23:
        Con_NPrintf(idx: v9++, fmt: defaultValue);
      while ( v9 <= 31 );
    }
    else
    {
      while ( v9 <= 31 )
      {
        v11 = g_FocusPanelList.m_Memory.m_pMemory[v10];
        if ( v11 != 0 )
        {
          v12 = (double)(int)embedded;
          np.index = v9;
          np.color[0] = (float)(unsigned __int8)(int)(47.3 * v12 + 124.0) * 0.0039215689;
          np.color[1] = (float)(unsigned __int8)(int)(63.78 - 71.40000000000001 * v12) * 0.0039215689;
          np.color[2] = (float)(unsigned __int8)(int)(v12 * 13.57 + 188.42) * 0.0039215689;
          v13 = ((int (__thiscall *)(vgui::IInput *, int, unsigned int))g_pVGuiInput->GetMouseFocus)(
                  a1: g_pVGuiInput,
                  a2,
                  a3);
          embedded = (unsigned int)"-->";
          if ( v13 != v11 )
            embedded = (unsigned int)"   ";
          a3 = v11;
          v14 = g_pVGuiPanel;
          ++v9;
          a2 = ((int (*)(void))g_pVGuiPanel->GetMessageContextId)();
          v15 = (const char *)((int (__thiscall *)(vgui::IPanel *, unsigned int, unsigned int))v14->GetName)(
                                a1: v14,
                                a2: v11,
                                a3: v11);
          Con_NXPrintf(info: &np, fmt: "%s %3i:  %s(vpanel%d)(ctx%d)\n", (const char *)embedded, v9, v15, v16, v17);
          v10 = i;
          m_Size = c;
          embedded = v9;
        }
        i = ++v10;
        if ( v10 >= m_Size )
        {
          if ( v9 > 31 )
            return;
          goto LABEL_23;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208720
// Name: private: virtual void CEngineVGui::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineVGui::Simulate(CEngineVGui *this)
{
  void (__thiscall *VGui_PreSimulateAllTools)(IToolFrameworkInternal *); // edx
  CStatTime *v3; // ecx
  vgui::AnimationController *AnimationController; // eax
  int right; // edi
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // esi
  CEngineVGui *v8; // esi
  void *v9; // ecx
  float v10; // [esp+0h] [ebp-1Ch]
  tagRECT Rect; // [esp+8h] [ebp-14h] BYREF
  CEngineVGui *v12; // [esp+18h] [ebp-4h]

  VGui_PreSimulateAllTools = toolframework->VGui_PreSimulateAllTools;
  v12 = this;
  VGui_PreSimulateAllTools(this: toolframework);
  if ( this->staticPanel != nullptr )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CEngineVGui::Simulate",
      a3: 0,
      a4: "VGUI_Simulate",
      a5: false,
      a6: 4);
    v10 = _Plat_FloatTime(this: v3);
    AnimationController = vgui::GetAnimationController();
    vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime: v10);
    if ( IsIconic(hWnd: *pmainwindow) )
    {
      right = videomode->GetModeWidth(this: videomode);
      videomode->GetModeHeight(this: videomode);
    }
    else
    {
      GetClientRect(hWnd: *pmainwindow, lpRect: &Rect);
      right = Rect.right;
    }
    v6 = materials->GetRenderContext(this: materials);
    v7 = v6;
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD))v7->Viewport)(a1: v7, a2: 0, a3: 0);
    v7->EndRender(this: v7);
    v7->Release(this: v7);
    staticGameUIFuncs->RunFrame(this: staticGameUIFuncs);
    g_pVGui->RunFrame(this: g_pVGui);
    v8 = v12;
    CEngineVGui::DrawMouseFocus(this: v12, a2: right, a3: (unsigned int)v12);
    if ( vgui_drawkeyfocus.m_pParent != nullptr && vgui_drawkeyfocus.m_pParent->m_Value.m_nValue != 0 )
    {
      v8->staticFocusOverlayPanel->MoveToFront(this: v8->staticFocusOverlayPanel);
      g_KeyFocusPanel = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
    }
    VGui_UpdateDrawTreePanel();
    VGui_UpdateTextureListPanel(this: v9);
    g_pVGuiSurface->CalculateMouseVisible(this: g_pVGuiSurface);
    VGui_ActivateMouse();
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  toolframework->VGui_PostSimulateAllTools(this: toolframework);
}

//------------------------------------------------------------------------------
// Address: 0x102088A0
// Name: public: void CVGuiPaintHelper::AddUIPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPaintHelper::AddUIPanel(CVGuiPaintHelper *this, unsigned int panel)
{
  bool (__thiscall *IsVisible)(vgui::IPanel *, unsigned int); // edx
  unsigned int v4; // eax
  int m_Size; // ecx
  CVGuiPaintHelper::Entry_t e; // [esp+8h] [ebp-Ch] BYREF

  IsVisible = g_pVGuiPanel->IsVisible;
  e.m_pVPanel = panel;
  e.m_bWasVisible = IsVisible(this: g_pVGuiPanel, a2: panel);
  v4 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: panel);
  m_Size = this->m_Entries.m_Size;
  e.m_Parent = v4;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    (CUtlVector<Vector,CUtlMemory<Vector,int> > *)this,
    elem: m_Size,
    src: (const Vector *)&e);
}

//------------------------------------------------------------------------------
// Address: 0x102088F0
// Name: public: virtual void CEngineVGui::Paint(enum PaintMode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineVGui::Paint(CEngineVGui *this@<ecx>, int a2@<edi>, PaintMode_t mode)
{
  int m_nValue; // eax
  bool v5; // bl
  int right; // ebx
  int bottom; // eax
  CStaticPanel *staticPanel; // edi
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // edi
  unsigned int v11; // eax
  vgui::IPanel *v12; // ebx
  vgui::IPanel_vtbl *v13; // edi
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // edi
  int v17; // ebx
  vgui::IPanel *v18; // ebx
  vgui::IPanel_vtbl *v19; // edi
  unsigned int v20; // eax
  vgui::IPanel *v21; // ebx
  vgui::IPanel_vtbl *v22; // edi
  int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  vgui::IPanel *v26; // ebx
  vgui::IPanel_vtbl *v27; // edi
  int v28; // eax
  vgui::IPanel *v29; // ebx
  vgui::IPanel_vtbl *v30; // edi
  int v31; // eax
  vgui::IPanel *v32; // ebx
  vgui::IPanel_vtbl *v33; // edi
  int v34; // eax
  vgui::IPanel *v35; // ebx
  vgui::IPanel_vtbl *v36; // edi
  unsigned int v37; // eax
  unsigned int v38; // eax
  CTransitionEffectPanel *staticTransitionPanel; // ecx
  CTransitionEffectPanel_vtbl *v40; // edx
  vgui::IPanel *v41; // ebx
  vgui::IPanel_vtbl *v42; // edi
  int v43; // eax
  vgui::ISurface *v44; // ebx
  vgui::ISurface_vtbl *v45; // edi
  int v46; // eax
  vgui::IPanel *v47; // ebx
  vgui::IPanel_vtbl *v48; // edi
  int v49; // eax
  vgui::IPanel *v50; // ebx
  vgui::IPanel_vtbl *v51; // edi
  int v52; // eax
  vgui::IPanel *v53; // ebx
  vgui::IPanel_vtbl *v54; // edi
  unsigned int v55; // eax
  unsigned int v56; // eax
  CEnginePanel *staticSteamOverlayPanel; // ecx
  CEnginePanel_vtbl *v58; // edx
  vgui::IPanel *v59; // ebx
  vgui::IPanel_vtbl *v60; // edi
  int v61; // eax
  vgui::ISurface *v62; // ebx
  vgui::ISurface_vtbl *v63; // edi
  int v64; // eax
  vgui::IPanel *v65; // ebx
  vgui::IPanel_vtbl *v66; // edi
  int v67; // eax
  CVGuiPaintHelper helper; // [esp+4h] [ebp-34h] BYREF
  tagRECT rect; // [esp+18h] [ebp-20h] BYREF
  unsigned int vPanelRememberParent; // [esp+28h] [ebp-10h]
  int childcount; // [esp+2Ch] [ebp-Ch]
  unsigned int fullscreenClientDLLPanel; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CEngineVGui::Paint",
    a3: 0,
    a4: "VGUI",
    a5: false,
    a6: 4);
  if ( this->staticPanel == nullptr )
    goto LABEL_2;
  vPanelRememberParent = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( vPanelRememberParent == 0 )
    goto LABEL_2;
  if ( r_drawvgui.m_pParent != nullptr )
    m_nValue = r_drawvgui.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v5 = m_nValue != 0;
  if ( demoplayer->IsPlayingTimeDemo(this: demoplayer) )
  {
    if ( !v5 )
    {
LABEL_2:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return;
    }
  }
  else if ( !v5 )
  {
    goto LABEL_2;
  }
  if ( (*((_BYTE *)this + 220) & 2) != 0 )
    goto LABEL_2;
  if ( IsIconic(hWnd: *pmainwindow) )
  {
    right = videomode->GetModeWidth(this: videomode);
    bottom = videomode->GetModeHeight(this: videomode);
  }
  else
  {
    GetClientRect(hWnd: *pmainwindow, lpRect: &rect);
    right = rect.right;
    bottom = rect.bottom;
  }
  staticPanel = this->staticPanel;
  vgui::Panel::SetBounds(this: staticPanel, x: 0, y: 0, wide: right, tall: bottom);
  ((void (__thiscall *)(CStaticPanel *, int))staticPanel->Repaint)(a1: staticPanel, a2);
  toolframework->VGui_PreRenderAllTools(this: toolframework, a2: mode);
  memset(&helper, 0, sizeof(helper));
  fullscreenClientDLLPanel = ClientDLL_GetFullscreenClientDLLVPanel();
  if ( mode == PAINT_UIPANELS )
  {
    v18 = g_pVGuiPanel;
    v19 = g_pVGuiPanel->__vftable;
    v20 = this->staticClientDLLPanel->GetVPanel(this: this->staticClientDLLPanel);
    childcount = v19->GetChildCount(this: v18, a2: v20);
    for ( i = 0; i < childcount; ++i )
    {
      v21 = g_pVGuiPanel;
      v22 = g_pVGuiPanel->__vftable;
      v23 = ((int (__thiscall *)(CEnginePanel *, int))this->staticClientDLLPanel->GetVPanel)(
              a1: this->staticClientDLLPanel,
              a2: i);
      v24 = ((int (__thiscall *)(vgui::IPanel *, int))v22->GetChild)(a1: v21, a2: v23);
      if ( v24 != 0 && v24 != fullscreenClientDLLPanel )
        CVGuiPaintHelper::AddUIPanel(this: &helper, panel: v24);
    }
  }
  else if ( mode == PAINT_INGAMEPANELS )
  {
    v9 = g_pVGuiPanel;
    v10 = g_pVGuiPanel->__vftable;
    v11 = this->staticClientDLLPanel->GetVPanel(this: this->staticClientDLLPanel);
    childcount = v10->GetChildCount(this: v9, a2: v11);
    for ( i = 0; i < childcount; ++i )
    {
      v12 = g_pVGuiPanel;
      v13 = g_pVGuiPanel->__vftable;
      v14 = ((int (__thiscall *)(CEnginePanel *, int))this->staticClientDLLPanel->GetVPanel)(
              a1: this->staticClientDLLPanel,
              a2: i);
      v15 = ((int (__thiscall *)(vgui::IPanel *, int))v13->GetChild)(a1: v12, a2: v14);
      v16 = v15;
      if ( v15 != 0 && v15 != fullscreenClientDLLPanel )
      {
        v17 = g_pVGuiPanel->GetMessageContextId(this: g_pVGuiPanel, a2: v15);
        if ( v17 == splitscreen->GetActiveSplitScreenPlayerSlot(this: splitscreen) )
          CVGuiPaintHelper::AddUIPanel(this: &helper, panel: v16);
      }
    }
  }
  v25 = this->staticClientDLLToolsPanel->GetVPanel(this: this->staticClientDLLToolsPanel);
  CVGuiPaintHelper::AddUIPanel(this: &helper, panel: v25);
  if ( this->staticSteamOverlayPanel != nullptr )
  {
    v26 = g_pVGuiPanel;
    v27 = g_pVGuiPanel->__vftable;
    v28 = ((int (__thiscall *)(CEnginePanel *, _DWORD))this->staticSteamOverlayPanel->GetVPanel)(
            a1: this->staticSteamOverlayPanel,
            a2: 0);
    ((void (__thiscall *)(vgui::IPanel *, int))v27->SetVisible)(a1: v26, a2: v28);
  }
  if ( this->staticTransitionPanel != nullptr )
  {
    v29 = g_pVGuiPanel;
    v30 = g_pVGuiPanel->__vftable;
    v31 = ((int (__thiscall *)(CTransitionEffectPanel *, _DWORD))this->staticTransitionPanel->GetVPanel)(
            a1: this->staticTransitionPanel,
            a2: 0);
    ((void (__thiscall *)(vgui::IPanel *, int))v30->SetVisible)(a1: v29, a2: v31);
  }
  CVGuiPaintHelper::Paint(this: &helper, rootPanel: vPanelRememberParent, mode);
  if ( this->staticTransitionPanel != nullptr
    && (mode & 1) != 0
    && staticGameUIFuncs->IsTransitionEffectEnabled(this: staticGameUIFuncs) )
  {
    v32 = g_pVGuiPanel;
    v33 = g_pVGuiPanel->__vftable;
    v34 = ((int (__thiscall *)(CTransitionEffectPanel *, int))this->staticTransitionPanel->GetVPanel)(
            a1: this->staticTransitionPanel,
            a2: 1);
    ((void (__thiscall *)(vgui::IPanel *, int))v33->SetVisible)(a1: v32, a2: v34);
    v35 = g_pVGuiPanel;
    v36 = g_pVGuiPanel->__vftable;
    v37 = this->staticTransitionPanel->GetVPanel(this: this->staticTransitionPanel);
    v38 = v36->GetParent(this: v35, a2: v37);
    staticTransitionPanel = this->staticTransitionPanel;
    v40 = staticTransitionPanel->__vftable;
    v41 = g_pVGuiPanel;
    v42 = g_pVGuiPanel->__vftable;
    vPanelRememberParent = v38;
    v43 = ((int (__thiscall *)(CTransitionEffectPanel *, _DWORD))v40->GetVPanel)(a1: staticTransitionPanel, a2: 0);
    ((void (__thiscall *)(vgui::IPanel *, int))v42->SetParent)(a1: v41, a2: v43);
    v44 = g_pVGuiSurface;
    v45 = g_pVGuiSurface->__vftable;
    v46 = ((int (__thiscall *)(CTransitionEffectPanel *, _DWORD))this->staticTransitionPanel->GetVPanel)(
            a1: this->staticTransitionPanel,
            a2: 0);
    ((void (__thiscall *)(vgui::ISurface *, int))v45->PaintTraverseEx)(a1: v44, a2: v46);
    v47 = g_pVGuiPanel;
    v48 = g_pVGuiPanel->__vftable;
    v49 = ((int (__thiscall *)(CTransitionEffectPanel *, unsigned int))this->staticTransitionPanel->GetVPanel)(
            a1: this->staticTransitionPanel,
            a2: vPanelRememberParent);
    ((void (__thiscall *)(vgui::IPanel *, int))v48->SetParent)(a1: v47, a2: v49);
  }
  if ( this->staticSteamOverlayPanel != nullptr && (mode & 1) != 0 )
  {
    v50 = g_pVGuiPanel;
    v51 = g_pVGuiPanel->__vftable;
    v52 = ((int (__thiscall *)(CEnginePanel *, int))this->staticSteamOverlayPanel->GetVPanel)(
            a1: this->staticSteamOverlayPanel,
            a2: 1);
    ((void (__thiscall *)(vgui::IPanel *, int))v51->SetVisible)(a1: v50, a2: v52);
    v53 = g_pVGuiPanel;
    v54 = g_pVGuiPanel->__vftable;
    v55 = this->staticSteamOverlayPanel->GetVPanel(this: this->staticSteamOverlayPanel);
    v56 = v54->GetParent(this: v53, a2: v55);
    staticSteamOverlayPanel = this->staticSteamOverlayPanel;
    v58 = staticSteamOverlayPanel->__vftable;
    v59 = g_pVGuiPanel;
    v60 = g_pVGuiPanel->__vftable;
    vPanelRememberParent = v56;
    v61 = ((int (__thiscall *)(CEnginePanel *, _DWORD))v58->GetVPanel)(a1: staticSteamOverlayPanel, a2: 0);
    ((void (__thiscall *)(vgui::IPanel *, int))v60->SetParent)(a1: v59, a2: v61);
    v62 = g_pVGuiSurface;
    v63 = g_pVGuiSurface->__vftable;
    v64 = ((int (__thiscall *)(CEnginePanel *, _DWORD))this->staticSteamOverlayPanel->GetVPanel)(
            a1: this->staticSteamOverlayPanel,
            a2: 0);
    ((void (__thiscall *)(vgui::ISurface *, int))v63->PaintTraverseEx)(a1: v62, a2: v64);
    v65 = g_pVGuiPanel;
    v66 = g_pVGuiPanel->__vftable;
    v67 = ((int (__thiscall *)(CEnginePanel *, unsigned int))this->staticSteamOverlayPanel->GetVPanel)(
            a1: this->staticSteamOverlayPanel,
            a2: vPanelRememberParent);
    ((void (__thiscall *)(vgui::IPanel *, int))v66->SetParent)(a1: v65, a2: v67);
  }
  toolframework->VGui_PostRenderAllTools(this: toolframework, a2: mode);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&helper);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102A4B90
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x102A4DD0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x102A5270
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

} // namespace engine_xlsp
