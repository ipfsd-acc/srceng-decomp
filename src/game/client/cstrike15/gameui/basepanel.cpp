// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/basepanel.cpp
// Functions: 146
// ============================================================

#include "game\client\cstrike15\gameui\basepanel.h"

//------------------------------------------------------------------------------
// Address: 0x101EFB80
// Name: public: virtual void CSaveBeforeQuitQueryDialog::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveBeforeQuitQueryDialog::OnKeyCodePressed(CCustomTabExplanationDialog *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    this->Close(this);
  else
    vgui::Panel::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x101F5390
// Name: public: class vgui::Panel __near * vgui::PHandle::operator->(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
vgui::Panel *__thiscall vgui::PHandle::operator->(vgui::PHandle *this)
{
  return vgui::PHandle::Get(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F53A0
// Name: public: static char const __near * CMainMenuGameLogo::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMainMenuGameLogo::GetPanelClassName()
{
  return "CMainMenuGameLogo";
}

//------------------------------------------------------------------------------
// Address: 0x101F53B0
// Name: public: static char const __near * CGameMenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CGameMenuItem::GetPanelClassName()
{
  return "CGameMenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x101F53C0
// Name: public: static char const __near * CBaseModPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseModPanel::GetPanelClassName()
{
  return "CBaseModPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101F53D0
// Name: private: static void __near * CBaseModPanel::GetVar_m_flBackgroundFillAlpha(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelAnimationVar_m_nBgTextureId1 *__cdecl CBaseModPanel::GetVar_m_flBackgroundFillAlpha(
        vgui::Panel *panel)
{
  return &panel[1].m_m_nBgTextureId1_register;
}

//------------------------------------------------------------------------------
// Address: 0x101F53E0
// Name: public: static char const __near * CGameMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CGameMenu::GetPanelClassName()
{
  return "CGameMenu";
}

//------------------------------------------------------------------------------
// Address: 0x101F53F0
// Name: public: void CGameMenu::UpdateMenuItemState(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenu::UpdateMenuItemState(CGameMenu *this, bool isInGame, bool isMultiplayer)
{
  int v4; // eax
  CGameUI *v5; // eax
  int v6; // edi
  vgui::Panel *Child; // eax
  vgui::MenuItem *v8; // eax
  vgui::MenuItem *v9; // ebx
  KeyValues *UserData; // eax
  KeyValues *v11; // edi
  int v12; // eax
  int v13; // edi
  int v14; // ebx
  vgui::MenuItem *MenuItem; // edi
  KeyValues *v16; // eax
  int Int; // edi
  vgui::CFooterPanel *m_pConsoleFooter; // ecx
  const char *v19; // edi
  const char *HelpName; // eax
  int v21; // [esp+Ch] [ebp-10h]
  KeyValues *kv1; // [esp+10h] [ebp-Ch]
  vgui::MenuItem *kv1a; // [esp+10h] [ebp-Ch]
  KeyValues *kv1b; // [esp+10h] [ebp-Ch]
  bool iID2; // [esp+14h] [ebp-8h]
  int iID2a; // [esp+14h] [ebp-8h]
  bool bIsConsoleUI; // [esp+1Ah] [ebp-2h]
  bool isSteam; // [esp+1Bh] [ebp-1h]
  int isMultiplayera; // [esp+28h] [ebp+Ch]

  v4 = _CommandLine(a1: this);
  isSteam = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-steam") != 0;
  v5 = GameUI();
  v6 = 0;
  bIsConsoleUI = CGameUI::IsConsoleUI(this: v5);
  kv1 = nullptr;
  if ( vgui::Panel::GetChildCount(this) > 0 )
  {
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this, index: v6);
      v8 = (vgui::MenuItem *)__RTDynamicCast(
                               inptr: Child,
                               VfDelta: 0,
                               SrcType: &vgui::Panel `RTTI Type Descriptor',
                               TargetType: &vgui::MenuItem `RTTI Type Descriptor',
                               isReference: 0);
      v9 = v8;
      if ( v8 != nullptr )
      {
        iID2 = true;
        UserData = vgui::MenuItem::GetUserData(this: v8);
        v11 = UserData;
        if ( UserData == nullptr )
          goto LABEL_20;
        if ( !isInGame )
          break;
        if ( KeyValues::GetInt(this: UserData, keyName: "MainMenuOnly", defaultValue: 0) == 0 )
          goto LABEL_7;
LABEL_18:
        iID2 = false;
LABEL_19:
        v9->SetVisible(this: v9, a2: iID2);
      }
LABEL_20:
      kv1 = (KeyValues *)((char *)kv1 + 1);
      v6 = (int)kv1;
      if ( (int)kv1 >= vgui::Panel::GetChildCount(this) )
        goto LABEL_21;
    }
    iID2 = KeyValues::GetInt(this: UserData, keyName: "OnlyInGame", defaultValue: 0) == 0;
LABEL_7:
    if ( (!isMultiplayer || KeyValues::GetInt(this: v11, keyName: "notmulti", defaultValue: 0) == 0)
      && (!isInGame || isMultiplayer || KeyValues::GetInt(this: v11, keyName: "notsingle", defaultValue: 0) == 0)
      && (!isSteam || KeyValues::GetInt(this: v11, keyName: "notsteam", defaultValue: 0) == 0) )
    {
      v12 = bIsConsoleUI
          ? KeyValues::GetInt(this: v11, keyName: "PCOnly", defaultValue: 0)
          : KeyValues::GetInt(this: v11, keyName: "ConsoleOnly", defaultValue: 0);
      if ( v12 == 0 )
        goto LABEL_19;
    }
    goto LABEL_18;
  }
LABEL_21:
  v13 = 0;
  if ( isInGame )
  {
    isMultiplayera = 0;
    if ( vgui::Panel::GetChildCount(this) > 0 )
    {
      do
      {
        if ( v13 < vgui::Panel::GetChildCount(this) - 2 )
        {
          do
          {
            v14 = this->GetMenuID(this, a2: v13);
            v21 = v13 + 1;
            iID2a = this->GetMenuID(this, a2: v13 + 1);
            kv1a = vgui::Menu::GetMenuItem(this, itemID: v14);
            MenuItem = vgui::Menu::GetMenuItem(this, itemID: iID2a);
            kv1b = vgui::MenuItem::GetUserData(this: kv1a);
            v16 = vgui::MenuItem::GetUserData(this: MenuItem);
            Int = KeyValues::GetInt(this: v16, keyName: "InGameOrder", defaultValue: 0);
            if ( KeyValues::GetInt(this: kv1b, keyName: "InGameOrder", defaultValue: 0) > Int )
              this->MoveMenuItem(this, a2: iID2a, a3: v14);
            v13 = v21;
          }
          while ( v21 < vgui::Panel::GetChildCount(this) - 2 );
          v13 = isMultiplayera;
        }
        isMultiplayera = ++v13;
      }
      while ( v13 < vgui::Panel::GetChildCount(this) );
    }
  }
  else if ( vgui::Panel::GetChildCount(this) - 2 > 0 )
  {
    do
    {
      this->MoveMenuItem(this, a2: v13, a3: v13 + 1);
      ++v13;
    }
    while ( v13 < vgui::Panel::GetChildCount(this) - 2 );
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  m_pConsoleFooter = this->m_pConsoleFooter;
  if ( m_pConsoleFooter != nullptr )
  {
    v19 = "MainMenu";
    if ( isInGame )
      v19 = "GameMenu";
    if ( vgui::CFooterPanel::GetHelpName(this: m_pConsoleFooter) == nullptr
      || (HelpName = vgui::CFooterPanel::GetHelpName(this: this->m_pConsoleFooter),
          _V_stricmp(s1: v19, s2: HelpName) != 0) )
    {
      vgui::CFooterPanel::SetHelpNameAndReset(this: this->m_pConsoleFooter, pName: v19);
      vgui::CFooterPanel::AddNewButtonLabel(
        this: this->m_pConsoleFooter,
        text: "#GameUI_Action",
        icon: "#GameUI_Icons_A_BUTTON");
      if ( isInGame )
        vgui::CFooterPanel::AddNewButtonLabel(
          this: this->m_pConsoleFooter,
          text: "#GameUI_Close",
          icon: "#GameUI_Icons_B_BUTTON");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F56E0
// Name: public: virtual void CGameMenu::OnCursorEnteredMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenu::OnCursorEnteredMenuItem(CGameMenu *this, unsigned int VPanel)
{
  vgui::IPanel *v2; // esi
  const char *v4; // eax
  int v5; // eax
  int v6; // esi
  KeyValues *v7; // esi
  KeyValues *FirstSubKey; // eax
  char *String; // eax
  vgui::IPanel_vtbl *v10; // [esp+Ch] [ebp-4h]

  v2 = g_pVGuiPanel;
  v10 = g_pVGuiPanel->__vftable;
  v4 = this->GetModuleName(this);
  v5 = (int)v10->GetPanel(this: v2, a2: VPanel, a3: v4);
  v6 = v5;
  if ( v5 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
  {
    v7 = (KeyValues *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 1128))(a1: v6);
    if ( KeyValues::GetFirstSubKey(this: v7) != nullptr )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: v7);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
      if ( String != nullptr && *String != 0 )
        vgui::Menu::OnCursorEnteredMenuItem(this, VPanel);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5770
// Name: CreateMenuButton
// Source: json
//------------------------------------------------------------------------------
CBackgroundMenuButton *__cdecl CreateMenuButton(CBaseModPanel *parent, const char *panelName, const wchar_t *panelText)
{
  CBackgroundMenuButton *v3; // eax
  CBackgroundMenuButton *v4; // esi

  v3 = (CBackgroundMenuButton *)MemAlloc_Alloc(nSize: 0x200u);
  if ( v3 != nullptr )
    v4 = CBackgroundMenuButton::CBackgroundMenuButton(this: v3, parent, name: panelName);
  else
    v4 = nullptr;
  v4->SetProportional(this: v4, a2: true);
  v4->SetCommand(this: v4, a2: "OpenGameMenu");
  v4->SetText(this: v4, a2: panelText, a3: false);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101F57D0
// Name: public: class KeyValues __near * CBaseModPanel::GetConsoleControlSettings(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall CBaseModPanel::GetConsoleControlSettings(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

//------------------------------------------------------------------------------
// Address: 0x101F57E0
// Name: CC_GameMenuCommand
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_GameMenuCommand(const CCommand *args)
{
  KeyValues *v1; // eax
  const char *v2; // edx
  KeyValues *v3; // eax
  vgui::IVGui *v4; // esi
  vgui::IVGui_vtbl *v5; // edi
  int v6; // eax

  if ( args->m_nArgc >= 2 )
  {
    if ( g_pBasePanel != nullptr )
    {
      v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v1 != nullptr )
      {
        v2 = prType;
        if ( args->m_nArgc > 1 )
          v2 = args->m_ppArgv[1];
        v3 = KeyValues::KeyValues(this: v1, setName: "Command", firstKey: "command", firstValue: v2);
      }
      else
      {
        v3 = nullptr;
      }
      v4 = g_pVGui;
      v5 = g_pVGui->__vftable;
      v6 = ((int (__thiscall *)(CBaseModPanel *, KeyValues *, _DWORD, _DWORD))g_pBasePanel->GetVPanel)(
             a1: g_pBasePanel,
             a2: v3,
             a3: 0,
             a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v5->PostMessage)(a1: v4, a2: v6);
    }
  }
  else
  {
    _Msg(a1: "Usage:  gamemenucommand <commandname>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5870
// Name: UtlStringLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UtlStringLessFunc(CUtlString *lhs, CUtlString *rhs)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: rhs);
  v3 = CUtlString::operator char const *(this: lhs);
  return _V_stricmp(s1: v3, s2: v2) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F58A0
// Name: protected: virtual void CBaseModPanel::StartExitingProcess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::StartExitingProcess(CBaseModPanel *this)
{
  double v2; // st7
  int v3; // [esp+0h] [ebp-4h]

  v2 = _Plat_FloatTime(a1: v3);
  this->m_flTransitionStartTime = v2;
  this->m_ExitingFrameCount = 30;
  this->m_flTransitionEndTime = v2 + 0.5;
  g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
  engine->StartXboxExitingProcess(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x101F58F0
// Name: public: virtual void CBaseModPanel::OnLevelLoadingStarted(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnLevelLoadingStarted(
        CBaseModPanel *this,
        const char *levelName,
        bool bShowProgressDialog)
{
  this->m_bLevelLoading = true;
}

//------------------------------------------------------------------------------
// Address: 0x101F5900
// Name: private: void CBaseModPanel::UpdateGameMenus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::UpdateGameMenus(CBaseModPanel *this)
{
  CGameUI *v2; // eax
  bool isInGame; // [esp+4h] [ebp-8h]
  bool isMulti; // [esp+8h] [ebp-4h]

  v2 = GameUI();
  isInGame = v2->IsInLevel(this: v2);
  if ( !isInGame || (isMulti = true, engine->GetMaxClients(this: engine) <= 1) )
    isMulti = false;
  CGameMenu::UpdateMenuItemState(this: this->m_pGameMenu, isInGame, isMultiplayer: isMulti);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->m_pGameMenu->SetVisible(this: this->m_pGameMenu, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x101F5980
// Name: protected: virtual void CBaseModPanel::UnlockInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::UnlockInput(CBaseModPanel *this)
{
  s_idUser1 = -1;
}

//------------------------------------------------------------------------------
// Address: 0x101F5990
// Name: private: virtual void CBaseModPanel::OnActivateModule(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnActivateModule(CBaseModPanel *this, int moduleIndex)
{
  CVGuiSystemModuleLoader::ActivateModule(this: &g_VModuleLoader, moduleIndex);
}

//------------------------------------------------------------------------------
// Address: 0x101F59A0
// Name: protected: virtual void CBaseModPanel::RunSlottedMenuCommand(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::RunSlottedMenuCommand(CBaseModPanel *this, int slot, const char *command)
{
  this->RunMenuCommand(this, a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x101F59C0
// Name: PanelJobWrapperFn
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl PanelJobWrapperFn(float *pvContext)
{
  double v2; // st7
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-4h]
  float v7; // [esp+8h] [ebp-4h]
  float flElapsedTime; // [esp+14h] [ebp+8h]

  v6 = _Plat_FloatTime(a1: v4);
  (*(void (__thiscall **)(float *))(*(_DWORD *)pvContext + 4))(a1: pvContext);
  v2 = _Plat_FloatTime(a1: v5) - v6;
  v7 = pvContext[2];
  flElapsedTime = v2;
  if ( v7 > flElapsedTime )
    _ThreadSleep(a1: (__int64)((v7 - v2) * 1000.0));
  _ReleaseThreadHandle(a1: *((_DWORD *)pvContext + 1));
  pvContext[1] = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F5A50
// Name: public: void CBaseModPanel::ExecuteAsync(class CBaseModPanel::CAsyncJobContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::ExecuteAsync(CBaseModPanel *this, CBaseModPanel::CAsyncJobContext *pAsync)
{
  this->m_pAsyncJob = pAsync;
  pAsync->m_hThreadHandle = (void *volatile)_CreateSimpleThread(a1: PanelJobWrapperFn, a2: pAsync, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101F5A80
// Name: private: void CBaseModPanel::IssuePostPromptCommand(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::IssuePostPromptCommand(CBaseModPanel *this)
{
  CBaseModPanel_vtbl *v2; // ebx
  const char *v3; // eax

  if ( CUtlString::Length(this: &this->m_strPostPromptCommand) != 0 && this->m_bSinglePlayer )
  {
    v2 = this->__vftable;
    v3 = CUtlString::operator char const *(this: &this->m_strPostPromptCommand);
    v2->OnCommand(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5AC0
// Name: public: void CBaseModPanel::RunAnimationWithCallback(class vgui::Panel __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::RunAnimationWithCallback(
        CBaseModPanel *this,
        vgui::Panel *parent,
        const char *animName,
        KeyValues *msgFunc)
{
  vgui::AnimationController *m_pConsoleAnimationController; // ecx
  double AnimationSequenceLength; // st7
  float v7; // xmm0_4
  float sequenceLength; // [esp+14h] [ebp+Ch]

  m_pConsoleAnimationController = this->m_pConsoleAnimationController;
  if ( m_pConsoleAnimationController != nullptr )
  {
    vgui::AnimationController::StartAnimationSequence(this: m_pConsoleAnimationController, sequenceName: animName);
    AnimationSequenceLength = vgui::AnimationController::GetAnimationSequenceLength(
                                this: this->m_pConsoleAnimationController,
                                sequenceName: animName);
    if ( AnimationSequenceLength == 0.0 )
    {
      v7 = AnimationSequenceLength;
    }
    else
    {
      sequenceLength = AnimationSequenceLength;
      v7 = g_flAnimationPadding + sequenceLength;
    }
    if ( parent != nullptr && msgFunc != nullptr )
      ((void (__thiscall *)(CBaseModPanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: parent,
        a3: msgFunc,
        a4: LODWORD(v7));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5B40
// Name: public: static char const __near * CSaveBeforeQuitQueryDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveBeforeQuitQueryDialog::GetPanelClassName()
{
  return "CSaveBeforeQuitQueryDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101F5B50
// Name: public: static char const __near * CQuitQueryBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CQuitQueryBox::GetPanelClassName()
{
  return "CQuitQueryBox";
}

//------------------------------------------------------------------------------
// Address: 0x101F5B60
// Name: public: virtual void CBaseModPanel::HandleOpenCreateStartScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::HandleOpenCreateStartScreen(CBaseModPanel *this)
{
  void (__thiscall *OnOpenCreateStartScreen)(CBaseModPanel *); // edx

  this->DismissAllMainMenuScreens(this);
  this->m_bWaitingForUserSignIn = false;
  OnOpenCreateStartScreen = this->OnOpenCreateStartScreen;
  *(_WORD *)&this->m_bShowStartScreen = 1;
  OnOpenCreateStartScreen(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F5B90
// Name: public: void CBaseModPanel::NotifySignInCompleted(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::NotifySignInCompleted(CBaseModPanel *this, int userID)
{
  if ( this->m_bShowStartScreen && this->m_bWaitingForUserSignIn )
  {
    s_idUser1 = userID;
    this->m_bWaitingForUserSignIn = false;
    this->m_bUserRefusedSignIn = false;
    this->m_bStartScreenPlayerSigninCompleted = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5BD0
// Name: public: void CBaseModPanel::NotifySignInCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::NotifySignInCancelled(CBaseModPanel *this)
{
  if ( this->m_bShowStartScreen )
  {
    this->UnlockInput(this);
    this->m_bWaitingForUserSignIn = false;
    this->m_bStartScreenPlayerSigninCompleted = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5C00
// Name: public: void CBaseModPanel::OnPlayCreditsVideo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnPlayCreditsVideo(CBaseModPanel *this)
{
  engine->ClientCmd_Unrestricted(this: engine, a2: "playvideo credits");
}

//------------------------------------------------------------------------------
// Address: 0x101F5C20
// Name: public: void CBaseModPanel::OnOpenCSAchievementsDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenCSAchievementsDialog(CBaseModPanel *this)
{
  IGameClientExports *v2; // eax
  int v3; // eax
  ISteamFriends *m_pSteamFriends; // ecx
  IGameClientExports *v5; // eax
  IGameClientExports *v6; // eax
  int screenHeight; // [esp+4h] [ebp-8h] BYREF
  int screenWide; // [esp+8h] [ebp-4h] BYREF

  if ( GameClientExports() != nullptr )
  {
    screenWide = 0;
    screenHeight = 0;
    engine->GetScreenSize(this: engine, a2: &screenWide, a3: &screenHeight);
    v2 = GameClientExports();
    v3 = v2->GetAchievementsPanelMinWidth(this: v2);
    if ( screenWide >= v3 )
    {
      v5 = GameClientExports();
      v5->CreateAchievementsPanel(this: v5, a2: this);
      v6 = GameClientExports();
      v6->DisplayAchievementPanel(this: v6);
    }
    else
    {
      m_pSteamFriends = steamapicontext->m_pSteamFriends;
      if ( m_pSteamFriends != nullptr )
        m_pSteamFriends->ActivateGameOverlay(this: m_pSteamFriends, a2: "Achievements");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5CB0
// Name: public: void CBaseModPanel::PositionDialog(class vgui::PHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::PositionDialog(CBaseModPanel *this, vgui::PHandle dlg)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  int x; // [esp+0h] [ebp-18h] BYREF
  int wide; // [esp+4h] [ebp-14h] BYREF
  int ww; // [esp+8h] [ebp-10h] BYREF
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int wt; // [esp+14h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &dlg) != nullptr )
  {
    g_pVGuiSurface->GetWorkspaceBounds(this: g_pVGuiSurface, a2: &x, a3: &y, a4: &ww, a5: &wt);
    v2 = vgui::PHandle::Get(this: &dlg);
    vgui::Panel::GetSize(this: v2, &wide, &tall);
    v3 = vgui::PHandle::Get(this: &dlg);
    vgui::Panel::SetPos(this: v3, x: x + (ww - wide) / 2, y: y + (wt - tall) / 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5D30
// Name: public: void CBaseModPanel::OnChangeStorageDevice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnChangeStorageDevice(CBaseModPanel *this)
{
  unsigned int *p_m_iStorageID; // eax
  IXboxSystem_vtbl *v3; // esi
  int v4; // eax
  unsigned int *v5; // [esp-Ch] [ebp-10h]
  void **p_m_hStorageDeviceChangeHandle; // [esp-8h] [ebp-Ch]

  if ( !this->m_bWaitingForStorageDeviceHandle )
  {
    this->m_bWaitingForStorageDeviceHandle = true;
    this->m_hStorageDeviceChangeHandle = (void *)xboxsystem->CreateAsyncHandle(this: xboxsystem);
    p_m_iStorageID = &this->m_iStorageID;
    p_m_hStorageDeviceChangeHandle = &this->m_hStorageDeviceChangeHandle;
    this->m_iStorageID = -1;
    v3 = xboxsystem->__vftable;
    v5 = p_m_iStorageID;
    v4 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: (vgui::CTreeViewListControl *)xboxsystem);
    v3->ShowDeviceSelector(this: xboxsystem, a2: v4, a3: true, a4: v5, a5: p_m_hStorageDeviceChangeHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5D90
// Name: public: void CBaseModPanel::FadeToBlackAndRunEngineCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::FadeToBlackAndRunEngineCommand(CBaseModPanel *this, char *engineCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "RunEngineCommand", firstKey: "command", firstValue: engineCommand);
  else
    v4 = nullptr;
  ((void (__thiscall *)(CBaseModPanel *, CBaseModPanel *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v4,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101F5DE0
// Name: public: void CBaseModPanel::SetMenuItemBlinkingState(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::SetMenuItemBlinkingState(CBaseModPanel *this, const char *itemName, int state)
{
  int i; // esi
  vgui::Panel *Child; // eax
  void *v6; // eax

  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &CGameMenu `RTTI Type Descriptor',
           isReference: 0);
    if ( v6 != nullptr )
      (*(void (__thiscall **)(void *, const char *, int))(*(_DWORD *)v6 + 1080))(a1: v6, a2: itemName, a3: state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5E60
// Name: public: void CBaseModPanel::RunCloseAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::RunCloseAnimation(CBaseModPanel *this, const char *animName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "FinishDialogClose");
    CBaseModPanel::RunAnimationWithCallback(this, parent: this, animName, msgFunc: v4);
  }
  else
  {
    CBaseModPanel::RunAnimationWithCallback(this, parent: this, animName, msgFunc: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5EB0
// Name: public: virtual void CMainMenuGameLogo::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMainMenuGameLogo::ApplySettings(
        CMainMenuGameLogo *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::EditablePanel::ApplySettings(this, a2, inResourceData);
  this->m_nOffsetX = KeyValues::GetInt(this: inResourceData, keyName: "offsetX", defaultValue: 0);
  this->m_nOffsetY = KeyValues::GetInt(this: inResourceData, keyName: "offsetY", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101F5EF0
// Name: public: virtual void CMainMenuGameLogo::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainMenuGameLogo::ApplySchemeSettings(CMainMenuGameLogo *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->LoadControlSettings(this, a2: "Resource/GameLogo.res", a3: nullptr, a4: nullptr, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101F5F80
// Name: public: CGameMenuItem::CGameMenuItem(class vgui::Menu __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameMenuItem *__userpurge CGameMenuItem::CGameMenuItem@<eax>(
        CGameMenuItem *this@<ecx>,
        vgui::PanelMessageMap *a2@<edi>,
        vgui::Menu *parent,
        const char *name)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::MenuItem::MenuItem(
    this,
    a2,
    parent,
    panelName: name,
    text: "GameMenuItem",
    cascadeMenu: nullptr,
    checkable: false);
  this->__vftable = (CGameMenuItem_vtbl *)&CGameMenuItem::`vftable';
  if ( `CGameMenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `CGameMenuItem::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CGameMenuItem");
    v5->pfnClassName = CGameMenuItem::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::MenuItem");
  }
  if ( `CGameMenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CGameMenuItem::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CGameMenuItem");
    v6->pfnClassName = CGameMenuItem::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::MenuItem");
  }
  if ( `CGameMenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CGameMenuItem::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CGameMenuItem");
    v7->pfnClassName = CGameMenuItem::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::MenuItem");
  }
  this->m_bRightAligned = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F6050
// Name: public: virtual struct vgui::PanelMessageMap __near * CGameMenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CGameMenuItem::GetMessageMap(CGameMenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CGameMenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameMenuItem::GetMessageMap'::`2'::s_pMap;
  `CGameMenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CGameMenuItem");
  `CGameMenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F6080
// Name: public: virtual struct PanelAnimationMap __near * CGameMenuItem::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CGameMenuItem::GetAnimMap(CGameMenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "CGameMenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x101F6090
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CGameMenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CGameMenuItem::GetKBMap(CGameMenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CGameMenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameMenuItem::GetKBMap'::`2'::s_pMap;
  `CGameMenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CGameMenuItem");
  `CGameMenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F60C0
// Name: public: virtual void CGameMenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenuItem::ApplySchemeSettings(CGameMenuItem *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  CGameMenuItem_vtbl *v4; // ebx
  Color *v5; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  vgui::IScheme *v7; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v9; // eax
  vgui::IScheme *v10; // eax
  Color *(__thiscall *v11)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v12; // eax
  vgui::IScheme *v13; // eax
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v15; // eax
  int v16; // eax
  CGameMenuItem_vtbl *v17; // edx
  unsigned int (__thiscall *GetFont)(vgui::IScheme *, const char *, bool); // eax
  CGameUI *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  Color *v21; // eax
  _BYTE v22[4]; // [esp+Ch] [ebp-Ch] BYREF
  Color v23; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v24; // [esp+14h] [ebp-4h]

  v2 = pScheme;
  vgui::MenuItem::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "MainMenu.TextColor", a4: v2);
  ((void (__thiscall *)(CGameMenuItem *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  SetBgColor = this->SetBgColor;
  pScheme = nullptr;
  ((void (__thiscall *)(CGameMenuItem *, _DWORD))SetBgColor)(a1: this, a2: 0);
  v7 = (vgui::IScheme *)this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  v24 = nullptr;
  pScheme = v7;
  v9 = (_DWORD *)GetSchemeColor_2(this, result: &v23, a3: "MainMenu.TextColor", a4: v2);
  ((void (__thiscall *)(CGameMenuItem *, _DWORD, _DWORD))pScheme[271].__vftable)(a1: this, a2: *v9, a3: 0);
  v10 = (vgui::IScheme *)this->__vftable;
  v11 = this->GetSchemeColor_2;
  v24 = nullptr;
  pScheme = v10;
  v12 = (_DWORD *)v11(this, result: &v23, a3: "MainMenu.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(CGameMenuItem *, _DWORD, _DWORD))pScheme[272].__vftable)(a1: this, a2: *v12, a3: 0);
  v13 = (vgui::IScheme *)this->__vftable;
  v14 = this->GetSchemeColor_2;
  v24 = nullptr;
  pScheme = v13;
  v15 = (_DWORD *)v14(this, result: &v23, a3: "MainMenu.DepressedTextColor", a4: v2);
  ((void (__thiscall *)(CGameMenuItem *, _DWORD, _DWORD))pScheme[273].__vftable)(a1: this, a2: *v15, a3: 0);
  this->SetContentAlignment(this, a2: a_west);
  this->SetBorder(this, a2: nullptr);
  this->SetDefaultBorder(this, a2: nullptr);
  this->SetDepressedBorder(this, a2: nullptr);
  this->SetKeyFocusBorder(this, a2: nullptr);
  v16 = v2->GetFont(this: v2, a2: "MainMenuFont", a3: false);
  if ( v16 != 0 )
  {
    v17 = this->__vftable;
  }
  else
  {
    GetFont = v2->GetFont;
    pScheme = (vgui::IScheme *)this->__vftable;
    v16 = GetFont(this: v2, a2: "MenuLarge", a3: false);
    v17 = (CGameMenuItem_vtbl *)pScheme;
  }
  v17->SetFont(this, a2: v16);
  this->SetTextInset(this, a2: 0, a3: 0);
  vgui::Button::SetArmedSound(this, sound: "UI/buttonrollover.wav");
  vgui::Button::SetDepressedSound(this, sound: "UI/buttonclick.wav");
  vgui::Button::SetReleasedSound(this, sound: "UI/buttonclickrelease.wav");
  this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
  v19 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v19) )
  {
    v20 = this->GetSchemeColor_2;
    pScheme = (vgui::IScheme *)this->__vftable;
    v24 = (_DWORD *)v20(this, result: &v23, a3: "Button.ArmedBgColor", a4: v2);
    v21 = this->GetSchemeColor_2(this, result: v22, a3: "MainMenu.ArmedTextColor", a4: v2);
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme[272].__vftable)(a1: this, a2: *v21, a3: *v24);
    this->SetTextInset(this, a2: 10, a3: 0);
  }
  if ( this->m_bRightAligned )
    this->SetContentAlignment(this, a2: a_east);
}

//------------------------------------------------------------------------------
// Address: 0x101F62E0
// Name: public: virtual void CGameMenuItem::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenuItem::PaintBackground(CGameMenuItem *this)
{
  CGameUI *v2; // eax
  vgui::Panel *v3; // eax
  CGameMenuItem_vtbl *v4; // edi
  Color *v5; // eax
  CGameMenuItem_vtbl *v6; // eax
  int wide; // [esp+48h] [ebp-Ch] BYREF
  int tall; // [esp+4Ch] [ebp-8h] BYREF
  int v9; // [esp+50h] [ebp-4h] BYREF

  v2 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v2) )
  {
    if ( this->IsArmed(this) && this->IsVisible(this) )
    {
      v3 = this->GetParent(this);
      if ( vgui::Panel::GetAlpha(this: v3) >= 32 )
      {
        vgui::Panel::GetSize(this, &wide, &tall);
        v4 = this->__vftable;
        v5 = this->GetButtonBgColor(this, result: &v9);
        ((void (__thiscall *)(CGameMenuItem *, _DWORD, _DWORD, int, int, _DWORD, int, int, _DWORD, int, _DWORD))v4->DrawBoxFade)(
          a1: this,
          a2: 0,
          a3: 0,
          a4: wide,
          a5: tall,
          a6: *v5,
          a7: 1065353216,
          a8: 255,
          a9: 0,
          a10: 1,
          a11: 0);
        v6 = this->__vftable;
        v9 = 1610612736;
        ((void (__thiscall *)(CGameMenuItem *, int, int, int, int, int, int, int, _DWORD, int, _DWORD))v6->DrawBoxFade)(
          a1: this,
          a2: 2,
          a3: 2,
          a4: wide - 4,
          a5: tall - 4,
          a6: 1610612736,
          a7: 1065353216,
          a8: 255,
          a9: 0,
          a10: 1,
          a11: 0);
      }
    }
  }
  else
  {
    vgui::Panel::PaintBackground(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F63F0
// Name: public: void CBaseModPanel::ArmFirstMenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::ArmFirstMenuItem(CBaseModPanel *this)
{
  int v2; // esi
  vgui::MenuItem *MenuItem; // eax
  bool v4; // al
  CGameMenu *m_pGameMenu; // ecx

  CBaseModPanel::UpdateGameMenus(this);
  v2 = 0;
  if ( this->m_pGameMenu->GetItemCount(this: this->m_pGameMenu) > 0 )
  {
    while ( 1 )
    {
      MenuItem = vgui::Menu::GetMenuItem(this: this->m_pGameMenu, itemID: v2);
      v4 = MenuItem->IsVisible(this: MenuItem);
      m_pGameMenu = this->m_pGameMenu;
      if ( v4 )
        break;
      if ( ++v2 >= m_pGameMenu->GetItemCount(this: m_pGameMenu) )
        return;
    }
    vgui::Menu::SetCurrentlyHighlightedItem(this: m_pGameMenu, itemID: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6450
// Name: private: void CBaseModPanel::DrawBackgroundImage(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseModPanel::DrawBackgroundImage(CBaseModPanel *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int m_iBackgroundImageID; // ebx
  CGameUI *v7; // eax
  int v8; // edi
  int twide; // [esp+4h] [ebp-14h] BYREF
  int ttall; // [esp+8h] [ebp-10h] BYREF
  float frametime; // [esp+Ch] [ebp-Ch]
  int wide; // [esp+10h] [ebp-8h] BYREF
  int tall; // [esp+14h] [ebp-4h] BYREF

  if ( !this->m_bScaleformMainMenuEnabled || !this->IsScaleformMainMenuActive(this) )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    frametime = _Plat_FloatTime(a1: a2);
    v3 = 255;
    if ( this->m_bRenderingBackgroundTransition )
    {
      v4 = (int)(float)((float)((float)(this->m_flTransitionEndTime - frametime)
                              / (float)(this->m_flTransitionEndTime - this->m_flTransitionStartTime))
                      * 255.0);
      if ( v4 >= 0 )
      {
        if ( v4 > 255 )
          v4 = 255;
      }
      else
      {
        v4 = 0;
      }
      v3 = v4;
    }
    if ( this->m_ExitingFrameCount != 0 )
    {
      v5 = (int)(float)((float)((float)(this->m_flTransitionEndTime - frametime)
                              / (float)(this->m_flTransitionEndTime - this->m_flTransitionStartTime))
                      * 255.0);
      if ( v5 >= 0 )
      {
        if ( v5 > 255 )
          v5 = 255;
      }
      else
      {
        v5 = 0;
      }
      v3 = 255 - v5;
    }
    m_iBackgroundImageID = this->m_iBackgroundImageID;
    ((void (__thiscall *)(vgui::ISurface *, int, int, int))g_pVGuiSurface->DrawSetColor_2)(
      a1: g_pVGuiSurface,
      a2: 255,
      a3: 255,
      a4: 255);
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: m_iBackgroundImageID);
    g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
    if ( this->m_bRenderingBackgroundTransition || this->m_eBackgroundState == BACKGROUND_LOADING )
    {
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v3);
      g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iLoadingImageID);
      g_pVGuiSurface->DrawGetTextureSize(this: g_pVGuiSurface, a2: this->m_iLoadingImageID, a3: &twide, a4: &ttall);
      g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: wide - twide, a3: tall - ttall, a4: wide, a5: tall);
    }
    if ( !this->m_bShowStartScreen && this->m_bFadingInMenus )
    {
      v7 = GameUI();
      if ( CGameUI::IsConsoleUI(this: v7) )
      {
        vgui::AnimationController::StartAnimationSequence(
          this: this->m_pConsoleAnimationController,
          sequenceName: "OpenMainMenu");
        this->m_bFadingInMenus = false;
      }
      else
      {
        v8 = (int)(float)((float)((float)(frametime - this->m_flFadeMenuStartTime)
                                / (float)(this->m_flFadeMenuEndTime - this->m_flFadeMenuStartTime))
                        * 255.0);
        if ( v8 >= 0 )
        {
          if ( v8 > 255 )
            v8 = 255;
        }
        else
        {
          v8 = 0;
        }
        vgui::Panel::SetAlpha(this: this->m_pGameMenu, alpha: v8);
        if ( v8 == 255 )
          this->m_bFadingInMenus = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F66B0
// Name: private: virtual void CBaseModPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnCommand(CBaseModPanel *this, char *command)
{
  CGameUI *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  const char *v6; // eax

  v3 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v3) )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "RunMenuCommand", firstKey: "command", firstValue: command);
    else
      v5 = nullptr;
    CBaseModPanel::RunAnimationWithCallback(this, parent: this, animName: command, msgFunc: v5);
    v6 = CUtlString::operator char const *(this: &this->m_strPostPromptCommand);
    if ( _V_stricmp(s1: v6, s2: command) == 0 )
      CUtlString::operator=(this: &this->m_strPostPromptCommand, src: prType);
  }
  else
  {
    this->RunMenuCommand(this, a2: command);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6740
// Name: public: CSaveBeforeQuitQueryDialog::CSaveBeforeQuitQueryDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveBeforeQuitQueryDialog *__thiscall CSaveBeforeQuitQueryDialog::CSaveBeforeQuitQueryDialog(
        CSaveBeforeQuitQueryDialog *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CSaveBeforeQuitQueryDialog_vtbl *)&CSaveBeforeQuitQueryDialog::`vftable';
  if ( `CSaveBeforeQuitQueryDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveBeforeQuitQueryDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSaveBeforeQuitQueryDialog");
    v4->pfnClassName = CSaveBeforeQuitQueryDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CSaveBeforeQuitQueryDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveBeforeQuitQueryDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSaveBeforeQuitQueryDialog");
    v5->pfnClassName = CSaveBeforeQuitQueryDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSaveBeforeQuitQueryDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveBeforeQuitQueryDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveBeforeQuitQueryDialog");
    v6->pfnClassName = CSaveBeforeQuitQueryDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/SaveBeforeQuitDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F6830
// Name: public: virtual void CSaveBeforeQuitQueryDialog::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveBeforeQuitQueryDialog::DoModal(CSaveBeforeQuitQueryDialog *this)
{
  vgui::IInput *v2; // edi
  vgui::IInput_vtbl *v3; // ebx
  int v4; // eax
  vgui::ISurface *v5; // edi
  vgui::ISurface_vtbl *v6; // ebx
  int v7; // eax
  CGameUI *v8; // eax

  vgui::Frame::Activate(this);
  v2 = g_pVGuiInput;
  v3 = g_pVGuiInput->__vftable;
  v4 = this->GetVPanel(this);
  v3->SetAppModalSurface(this: v2, a2: v4);
  this->MoveToCenterOfScreen(this);
  v5 = g_pVGuiSurface;
  v6 = g_pVGuiSurface->__vftable;
  v7 = ((int (__thiscall *)(CSaveBeforeQuitQueryDialog *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  ((void (__thiscall *)(vgui::ISurface *, int))v6->RestrictPaintToSinglePanel)(a1: v5, a2: v7);
  v8 = GameUI();
  CGameUI::PreventEngineHideGameUI(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x101F6890
// Name: public: virtual void CSaveBeforeQuitQueryDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveBeforeQuitQueryDialog::OnCommand(CSaveBeforeQuitQueryDialog *this, const char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  CSaveBeforeQuitQueryDialog_vtbl *v5; // edi
  int v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CSaveBeforeQuitQueryDialog_vtbl *v9; // edi
  int v10; // eax
  char sz[256]; // [esp+10h] [ebp-180h] BYREF
  char saveName[128]; // [esp+110h] [ebp-80h] BYREF

  if ( _V_stricmp(s1: command, s2: "Quit") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "SaveAndQuit") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
        vgui::Frame::OnCommand(this, command);
      else
        this->Close(this);
    }
    else
    {
      CSaveGameDialog::FindSaveSlot(buffer: saveName, bufsize: 128);
      if ( saveName[0] != 0 )
      {
        V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "save %s\n", saveName);
        engine->ClientCmd_Unrestricted(this: engine, a2: sz);
      }
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(this: v7, setName: "Command", firstKey: "command", firstValue: "QuitNoConfirm");
      else
        v8 = nullptr;
      v9 = this->__vftable;
      v10 = ((int (__thiscall *)(CSaveBeforeQuitQueryDialog *, KeyValues *, _DWORD))this->GetVParent)(
              a1: this,
              a2: v8,
              a3: 0);
      ((void (__thiscall *)(CSaveBeforeQuitQueryDialog *, int))v9->PostMessage_2)(a1: this, a2: v10);
    }
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "command", firstValue: "QuitNoConfirm");
    else
      v4 = nullptr;
    v5 = this->__vftable;
    v6 = ((int (__thiscall *)(CSaveBeforeQuitQueryDialog *, KeyValues *, _DWORD))this->GetVParent)(
           a1: this,
           a2: v4,
           a3: 0);
    ((void (__thiscall *)(CSaveBeforeQuitQueryDialog *, int))v5->PostMessage_2)(a1: this, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F69F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveBeforeQuitQueryDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveBeforeQuitQueryDialog::GetMessageMap(CSaveBeforeQuitQueryDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveBeforeQuitQueryDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveBeforeQuitQueryDialog::GetMessageMap'::`2'::s_pMap;
  `CSaveBeforeQuitQueryDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSaveBeforeQuitQueryDialog");
  `CSaveBeforeQuitQueryDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F6A20
// Name: public: virtual struct PanelAnimationMap __near * CSaveBeforeQuitQueryDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveBeforeQuitQueryDialog::GetAnimMap(CSaveBeforeQuitQueryDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveBeforeQuitQueryDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101F6A30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveBeforeQuitQueryDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveBeforeQuitQueryDialog::GetKBMap(CSaveBeforeQuitQueryDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveBeforeQuitQueryDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveBeforeQuitQueryDialog::GetKBMap'::`2'::s_pMap;
  `CSaveBeforeQuitQueryDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveBeforeQuitQueryDialog");
  `CSaveBeforeQuitQueryDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F6A60
// Name: public: CQuitQueryBox::CQuitQueryBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CQuitQueryBox *__thiscall CQuitQueryBox::CQuitQueryBox(
        CQuitQueryBox *this,
        const char *title,
        const char *info,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::QueryBox::QueryBox(this, title, queryText: info, parent);
  this->__vftable = (CQuitQueryBox_vtbl *)&CQuitQueryBox::`vftable';
  if ( `CQuitQueryBox::ChainToMap'::`2'::chained == 0 )
  {
    `CQuitQueryBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CQuitQueryBox");
    v5->pfnClassName = CQuitQueryBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::QueryBox");
  }
  if ( `CQuitQueryBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CQuitQueryBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CQuitQueryBox");
    v6->pfnClassName = CQuitQueryBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::QueryBox");
  }
  if ( `CQuitQueryBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CQuitQueryBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CQuitQueryBox");
    v7->pfnClassName = CQuitQueryBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::QueryBox");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F6B30
// Name: public: virtual void CQuitQueryBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQuitQueryBox::DoModal(CQuitQueryBox *this, vgui::Frame *pFrameOver)
{
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  int v5; // eax
  CGameUI *v6; // eax

  vgui::MessageBox::DoModal(this, pFrameOver);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v5 = ((int (__thiscall *)(CQuitQueryBox *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  ((void (__thiscall *)(vgui::ISurface *, int))v4->RestrictPaintToSinglePanel)(a1: v3, a2: v5);
  v6 = GameUI();
  CGameUI::PreventEngineHideGameUI(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101F6B80
// Name: public: virtual void CSaveBeforeQuitQueryDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveBeforeQuitQueryDialog::OnClose(CQuitQueryBox *this)
{
  CGameUI *v1; // eax

  vgui::Frame::OnClose(this);
  g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
  v1 = GameUI();
  CGameUI::AllowEngineHideGameUI(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101F6BB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CQuitQueryBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CQuitQueryBox::GetMessageMap(CQuitQueryBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CQuitQueryBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CQuitQueryBox::GetMessageMap'::`2'::s_pMap;
  `CQuitQueryBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CQuitQueryBox");
  `CQuitQueryBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F6BE0
// Name: public: virtual struct PanelAnimationMap __near * CQuitQueryBox::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CQuitQueryBox::GetAnimMap(CQuitQueryBox *this)
{
  return FindOrAddPanelAnimationMap(className: "CQuitQueryBox");
}

//------------------------------------------------------------------------------
// Address: 0x101F6BF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CQuitQueryBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CQuitQueryBox::GetKBMap(CQuitQueryBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CQuitQueryBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CQuitQueryBox::GetKBMap'::`2'::s_pMap;
  `CQuitQueryBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CQuitQueryBox");
  `CQuitQueryBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F6C50
// Name: public: void CBaseModPanel::OnOpenNewGameDialog(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenNewGameDialog(CBaseModPanel *this, const char *chapter)
{
  CNewGameDialog *v3; // eax
  CNewGameDialog *v4; // eax
  CNewGameDialog *v5; // eax
  vgui::Panel *v6; // eax

  if ( vgui::PHandle::Get(this: &this->m_hNewGameDialog) == nullptr )
  {
    v3 = (CNewGameDialog *)MemAlloc_Alloc(nSize: 0x2D0u);
    if ( v3 != nullptr )
      v4 = CNewGameDialog::CNewGameDialog(this: v3, parent: this, bCommentaryMode: false);
    else
      v4 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hNewGameDialog, pPanel: v4);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hNewGameDialog.vgui::PHandle);
  }
  if ( chapter != nullptr )
  {
    v5 = (CNewGameDialog *)vgui::PHandle::Get(this: &this->m_hNewGameDialog);
    CNewGameDialog::SetSelectedChapter(this: v5, chapter);
  }
  LOBYTE(vgui::PHandle::Get(this: &this->m_hNewGameDialog)[1].m_NavRight.m_iPanelID) = 0;
  v6 = vgui::PHandle::Get(this: &this->m_hNewGameDialog);
  v6->__vftable[1].OnTick(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101F6CF0
// Name: public: void CBaseModPanel::OnOpenBonusMapsDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenBonusMapsDialog(CBaseModPanel *this)
{
  CBonusMapsDialog *v2; // eax
  CBonusMapsDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hBonusMapsDialog) == nullptr )
  {
    v2 = (CBonusMapsDialog *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v2 != nullptr )
      v3 = CBonusMapsDialog::CBonusMapsDialog(this: v2, parent: this);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hBonusMapsDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hBonusMapsDialog.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hBonusMapsDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F6D60
// Name: public: void CBaseModPanel::OnOpenLoadGameDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenLoadGameDialog(CBaseModPanel *this)
{
  CLoadGameDialog *v2; // eax
  CLoadGameDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hLoadGameDialog) == nullptr )
  {
    v2 = (CLoadGameDialog *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v2 != nullptr )
      v3 = CLoadGameDialog::CLoadGameDialog(this: v2, parent: this);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hLoadGameDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hLoadGameDialog.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hLoadGameDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F6DD0
// Name: public: void CBaseModPanel::OnOpenLoadGameDialog_Xbox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenLoadGameDialog_Xbox(CBaseModPanel *this)
{
  CLoadGameDialogXbox *v2; // eax
  CLoadGameDialogXbox *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hLoadGameDialog_Xbox) == nullptr )
  {
    v2 = (CLoadGameDialogXbox *)MemAlloc_Alloc(nSize: 0x474u);
    if ( v2 != nullptr )
      v3 = CLoadGameDialogXbox::CLoadGameDialogXbox(this: v2, parent: this);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hLoadGameDialog_Xbox, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hLoadGameDialog_Xbox.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hLoadGameDialog_Xbox);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F6E40
// Name: public: void CBaseModPanel::OnOpenSaveGameDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenSaveGameDialog(CBaseModPanel *this)
{
  CSaveGameDialog *v2; // eax
  CSaveGameDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hSaveGameDialog) == nullptr )
  {
    v2 = (CSaveGameDialog *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v2 != nullptr )
      v3 = CSaveGameDialog::CSaveGameDialog(this: v2, parent: this);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hSaveGameDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hSaveGameDialog.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hSaveGameDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F6EB0
// Name: public: void CBaseModPanel::OnOpenSaveGameDialog_Xbox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenSaveGameDialog_Xbox(CBaseModPanel *this)
{
  CSaveGameDialogXbox *v2; // eax
  CSaveGameDialogXbox *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hSaveGameDialog_Xbox) == nullptr )
  {
    v2 = (CSaveGameDialogXbox *)MemAlloc_Alloc(nSize: 0x630u);
    if ( v2 != nullptr )
      v3 = CSaveGameDialogXbox::CSaveGameDialogXbox(this: v2, parent: this);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hSaveGameDialog_Xbox, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hSaveGameDialog_Xbox.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hSaveGameDialog_Xbox);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F6F20
// Name: public: void CBaseModPanel::OnOpenOptionsDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenOptionsDialog(CBaseModPanel *this)
{
  COptionsDialog *v2; // eax
  COptionsDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hOptionsDialog) == nullptr )
  {
    v2 = (COptionsDialog *)MemAlloc_Alloc(nSize: 0x238u);
    if ( v2 != nullptr )
      v3 = COptionsDialog::COptionsDialog(this: v2, parent: this, iTabStyle: OPTIONS_DIALOG_ALL_TABS);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hOptionsDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hOptionsDialog.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hOptionsDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F6F90
// Name: public: void CBaseModPanel::ApplyOptionsDialogSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::ApplyOptionsDialogSettings(CBaseModPanel *this)
{
  vgui::DHANDLE<vgui::PropertyDialog> *p_m_hOptionsDialog; // esi
  vgui::Panel *v2; // eax

  p_m_hOptionsDialog = &this->m_hOptionsDialog;
  if ( vgui::PHandle::Get(this: &this->m_hOptionsDialog) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: p_m_hOptionsDialog);
    ((void (__thiscall *)(vgui::Panel *))v2->__vftable[1].SetPaintEnabled)(a1: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6FC0
// Name: public: void CBaseModPanel::OnOpenBenchmarkDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenBenchmarkDialog(CBaseModPanel *this)
{
  CBenchmarkDialog *v2; // eax
  CBenchmarkDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hBenchmarkDialog) == nullptr )
  {
    v2 = (CBenchmarkDialog *)MemAlloc_Alloc(nSize: 0x214u);
    if ( v2 != nullptr )
      v3 = CBenchmarkDialog::CBenchmarkDialog(this: v2, parent: this, name: "BenchmarkDialog");
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hBenchmarkDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hBenchmarkDialog.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hBenchmarkDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F7030
// Name: public: void CBaseModPanel::OnOpenServerBrowser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenServerBrowser(CBaseModPanel *this)
{
  CCustomTabExplanationDialog *v1; // esi
  CCStrike15BasePanel *v2; // eax
  CCustomTabExplanationDialog *v3; // eax
  vgui::Panel *v4; // eax
  vgui::DHANDLE<CCustomTabExplanationDialog> hCustomTabExplanationDialog; // [esp+0h] [ebp-4h] BYREF

  hCustomTabExplanationDialog.m_iPanelID = (unsigned int)this;
  CVGuiSystemModuleLoader::ActivateModule(this: &g_VModuleLoader, moduleName: "Servers");
  if ( cl_showncustomtabhelp.m_pParent == nullptr || cl_showncustomtabhelp.m_pParent->m_Value.m_nValue == 0 )
  {
    hCustomTabExplanationDialog.m_iPanelID = -1;
    if ( vgui::PHandle::Get(this: &hCustomTabExplanationDialog) == nullptr )
    {
      v1 = (CCustomTabExplanationDialog *)MemAlloc_Alloc(nSize: 0x214u);
      if ( v1 != nullptr )
      {
        v2 = BasePanel();
        v3 = CCustomTabExplanationDialog::CCustomTabExplanationDialog(this: v1, parent: v2);
      }
      else
      {
        v3 = nullptr;
      }
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &hCustomTabExplanationDialog, pPanel: v3);
    }
    v4 = vgui::PHandle::Get(this: &hCustomTabExplanationDialog);
    v4->__vftable[1].OnTick(this: v4);
    ConVar::SetValue(this: (ConVar *)&cl_showncustomtabhelp.IConVar, value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F70C0
// Name: public: virtual void CBaseModPanel::OnOpenCreateMultiplayerGameDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenCreateMultiplayerGameDialog(CBaseModPanel *this)
{
  CCreateMultiplayerGameDialog *v2; // eax
  CCreateMultiplayerGameDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hCreateMultiplayerGameDialog) == nullptr )
  {
    v2 = (CCreateMultiplayerGameDialog *)MemAlloc_Alloc(nSize: 0x244u);
    if ( v2 != nullptr )
      v3 = CCreateMultiplayerGameDialog::CCreateMultiplayerGameDialog(this: v2, parent: this);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hCreateMultiplayerGameDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hCreateMultiplayerGameDialog.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hCreateMultiplayerGameDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F7130
// Name: public: void CBaseModPanel::OnOpenChangeGameDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenChangeGameDialog(CBaseModPanel *this)
{
  CChangeGameDialog *v2; // eax
  CChangeGameDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hChangeGameDialog) == nullptr )
  {
    v2 = (CChangeGameDialog *)MemAlloc_Alloc(nSize: 0x214u);
    if ( v2 != nullptr )
      v3 = CChangeGameDialog::CChangeGameDialog(this: v2, a2: (char *)this, parent: this);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hChangeGameDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hChangeGameDialog.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hChangeGameDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F71A0
// Name: public: void CBaseModPanel::OnMakeGamePublic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnMakeGamePublic(CBaseModPanel *this)
{
  IMatchSession *v1; // esi
  KeyValues *v2; // eax
  char *String; // eax
  KeyValues *v4; // edi

  v1 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
  if ( v1 != nullptr )
  {
    v2 = v1->GetSessionSettings(this: v1);
    if ( v2 == nullptr
      || (String = KeyValues::GetString(this: v2, keyName: "system/access", defaultValue: nullptr)) == nullptr
      || _V_stricmp(s1: "public", s2: String) != 0 )
    {
      v4 = KeyValues::FromString(
             szName: "update",
             szStringVal: (KeyValues *)" update {  system {  access public  }  } ",
             ppEndOfParse: nullptr);
      v1->UpdateSessionSettings(this: v1, a2: v4);
      if ( v4 != nullptr )
        KeyValues::deleteThis(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7220
// Name: public: void CBaseModPanel::OnOpenPlayerListDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenPlayerListDialog(CBaseModPanel *this)
{
  CPlayerListDialog *v2; // eax
  CPlayerListDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hPlayerListDialog) == nullptr )
  {
    v2 = (CPlayerListDialog *)MemAlloc_Alloc(nSize: 0x21Cu);
    if ( v2 != nullptr )
      v3 = CPlayerListDialog::CPlayerListDialog(this: v2, parent: this);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hPlayerListDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hPlayerListDialog.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hPlayerListDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F7290
// Name: public: void CBaseModPanel::OnOpenLoadCommentaryDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenLoadCommentaryDialog(CBaseModPanel *this)
{
  CLoadCommentaryDialog *v2; // eax
  CLoadCommentaryDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hPlayerListDialog) == nullptr )
  {
    v2 = (CLoadCommentaryDialog *)MemAlloc_Alloc(nSize: 0x230u);
    if ( v2 != nullptr )
      v3 = CLoadCommentaryDialog::CLoadCommentaryDialog(this: v2, parent: this);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hLoadCommentaryDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hLoadCommentaryDialog.vgui::PHandle);
  }
  v4 = vgui::PHandle::Get(this: &this->m_hLoadCommentaryDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F7300
// Name: public: void CBaseModPanel::OpenLoadSingleplayerCommentaryDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OpenLoadSingleplayerCommentaryDialog(CBaseModPanel *this)
{
  CNewGameDialog *v2; // eax
  CNewGameDialog *v3; // eax
  vgui::Panel *v4; // eax

  if ( vgui::PHandle::Get(this: &this->m_hNewGameDialog) == nullptr )
  {
    v2 = (CNewGameDialog *)MemAlloc_Alloc(nSize: 0x2D0u);
    if ( v2 != nullptr )
      v3 = CNewGameDialog::CNewGameDialog(this: v2, parent: this, bCommentaryMode: true);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hNewGameDialog, pPanel: v3);
    CBaseModPanel::PositionDialog(this, dlg: this->m_hNewGameDialog.vgui::PHandle);
  }
  LOBYTE(vgui::PHandle::Get(this: &this->m_hNewGameDialog)[1].m_NavRight.m_iPanelID) = 1;
  v4 = vgui::PHandle::Get(this: &this->m_hNewGameDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F7380
// Name: public: void CBaseModPanel::OnGameUIHidden(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnGameUIHidden(CBaseModPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  vgui::Panel *v4; // eax

  if ( this->m_bScaleformPauseMenuEnabled && this->IsScaleformPauseMenuActive(this) )
    this->DismissPauseMenu(this);
  if ( vgui::PHandle::Get(this: &this->m_hOptionsDialog) != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "GameUIHidden");
    else
      v3 = nullptr;
    v4 = vgui::PHandle::Get(this: &this->m_hOptionsDialog);
    ((void (__thiscall *)(CBaseModPanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: v4,
      a3: v3,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7400
// Name: public: void CMessageDialogHandler::CloseAllMessageDialogs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialogHandler::CloseAllMessageDialogs(CMessageDialogHandler *this)
{
  int i; // ebx
  vgui::Panel *v3; // esi

  for ( i = 3; i != 0; --i )
  {
    v3 = vgui::PHandle::Get((vgui::PHandle *)this);
    if ( v3 != nullptr )
    {
      g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
      if ( vgui_message_dialog_modal.m_pParent != nullptr && vgui_message_dialog_modal.m_pParent->m_Value.m_nValue != 0 )
        g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
      v3->__vftable[1].GetAnimMap(this: v3);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=((vgui::PHandle *)this, pPanel: nullptr);
    }
    this = (CMessageDialogHandler *)((char *)this + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7470
// Name: public: void CMessageDialogHandler::CloseMessageDialog(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialogHandler::CloseMessageDialog(CMessageDialogHandler *this, char nType)
{
  int v2; // eax
  vgui::PHandle *v3; // edi
  vgui::Panel *v4; // esi

  v2 = 0;
  if ( (nType & 1) != 0 )
  {
    v2 = 1;
  }
  else if ( (nType & 2) != 0 )
  {
    v2 = 2;
  }
  v3 = &this->m_hMessageDialogs[v2];
  v4 = vgui::PHandle::Get(this: v3);
  if ( v4 != nullptr )
  {
    g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
    if ( vgui_message_dialog_modal.m_pParent != nullptr && vgui_message_dialog_modal.m_pParent->m_Value.m_nValue != 0 )
      g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
    v4->__vftable[1].GetAnimMap(this: v4);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: v3, pPanel: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F74F0
// Name: public: void CMessageDialogHandler::ActivateMessageDialog(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialogHandler::ActivateMessageDialog(CMessageDialogHandler *this, int nStackIdx)
{
  void (__thiscall *GetWorkspaceBounds)(vgui::ISurface *, int *, int *, int *, int *); // eax
  unsigned int m_iPanelID; // eax
  int v5; // edi
  int v6; // ebx
  vgui::PHandle *v7; // esi
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  CMessageDialog *v10; // eax
  char Type; // al
  int v12; // ebx
  vgui::Panel *v13; // eax
  vgui::PHandle *i; // edi
  vgui::Panel *v15; // eax
  vgui::Panel *v16; // esi
  vgui::IInput_vtbl *v17; // edi
  int v18; // eax
  int v19; // [esp-4h] [ebp-30h]
  int x; // [esp+Ch] [ebp-20h] BYREF
  int y; // [esp+10h] [ebp-1Ch] BYREF
  int v22; // [esp+14h] [ebp-18h] BYREF
  int v23; // [esp+18h] [ebp-14h] BYREF
  int wide; // [esp+1Ch] [ebp-10h] BYREF
  int tall; // [esp+20h] [ebp-Ch] BYREF
  CMessageDialogHandler *v26; // [esp+24h] [ebp-8h]
  vgui::PHandle v27; // [esp+28h] [ebp-4h] BYREF
  vgui::IInput *nStackIdxa; // [esp+34h] [ebp+8h]

  GetWorkspaceBounds = g_pVGuiSurface->GetWorkspaceBounds;
  v26 = this;
  GetWorkspaceBounds(this: g_pVGuiSurface, a2: &x, a3: &y, a4: &wide, a5: &tall);
  m_iPanelID = this->m_hMessageDialogs[nStackIdx].m_iPanelID;
  v5 = tall;
  v6 = wide;
  v7 = &this->m_hMessageDialogs[nStackIdx];
  v27.m_iPanelID = m_iPanelID;
  v8 = vgui::PHandle::Get(this: &v27);
  vgui::Panel::GetSize(this: v8, wide: &v22, tall: &v23);
  v9 = vgui::PHandle::Get(this: &v27);
  vgui::Panel::SetPos(this: v9, x: (v6 - v22) / 2, y: (v5 - v23) / 2);
  v10 = (CMessageDialog *)vgui::PHandle::Get(this: v7);
  Type = CMessageDialog::GetType(this: v10);
  v12 = 2;
  if ( (Type & 1) != 0 )
  {
    v19 = 75;
  }
  else
  {
    if ( (Type & 2) == 0 )
      goto LABEL_6;
    v19 = 100;
  }
  v13 = vgui::PHandle::Get(this: v7);
  vgui::Panel::SetZPos(this: v13, z: v19);
LABEL_6:
  if ( nStackIdx <= 2 )
  {
    for ( i = &v26->m_hMessageDialogs[2]; ; --i )
    {
      v15 = vgui::PHandle::Get(this: i);
      v16 = v15;
      if ( v15 != nullptr )
        break;
      if ( --v12 < nStackIdx )
        return;
    }
    v15->__vftable[1].OnTick(this: v15);
    if ( vgui_message_dialog_modal.m_pParent != nullptr && vgui_message_dialog_modal.m_pParent->m_Value.m_nValue != 0 )
    {
      v17 = g_pVGuiInput->__vftable;
      nStackIdxa = g_pVGuiInput;
      v18 = v16->GetVPanel(this: v16);
      v17->SetAppModalSurface(this: nStackIdxa, a2: v18);
    }
    v26->m_iDialogStackTop = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7610
// Name: public: void CMessageDialogHandler::PositionDialogs(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialogHandler::PositionDialogs(CMessageDialogHandler *this, int wide, unsigned int tall)
{
  unsigned int v3; // ebx
  int i; // edi
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  int v8; // [esp+Ch] [ebp-8h] BYREF
  int v9; // [esp+10h] [ebp-4h] BYREF

  v3 = tall;
  for ( i = 3; i != 0; --i )
  {
    if ( vgui::PHandle::Get((vgui::PHandle *)this) != nullptr )
    {
      tall = this->m_hMessageDialogs[0].m_iPanelID;
      v6 = vgui::PHandle::Get(this: (vgui::PHandle *)&tall);
      vgui::Panel::GetSize(this: v6, wide: &v8, tall: &v9);
      v7 = vgui::PHandle::Get(this: (vgui::PHandle *)&tall);
      vgui::Panel::SetPos(this: v7, x: (wide - v8) / 2, y: (int)(v3 - v9) / 2);
    }
    this = (CMessageDialogHandler *)((char *)this + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7680
// Name: public: CMainMenuGameLogo::CMainMenuGameLogo(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMainMenuGameLogo *__thiscall CMainMenuGameLogo::CMainMenuGameLogo(
        CMainMenuGameLogo *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CMainMenuGameLogo_vtbl *)&CMainMenuGameLogo::`vftable';
  if ( `CMainMenuGameLogo::ChainToMap'::`2'::chained == 0 )
  {
    `CMainMenuGameLogo::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMainMenuGameLogo");
    v4->pfnClassName = CMainMenuGameLogo::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CMainMenuGameLogo::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMainMenuGameLogo::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMainMenuGameLogo");
    v5->pfnClassName = CMainMenuGameLogo::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CMainMenuGameLogo::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMainMenuGameLogo::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMainMenuGameLogo");
    v6->pfnClassName = CMainMenuGameLogo::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_nOffsetX = 0;
  this->m_nOffsetY = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F7750
// Name: public: virtual struct vgui::PanelMessageMap __near * CMainMenuGameLogo::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMainMenuGameLogo::GetMessageMap(CMainMenuGameLogo *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMainMenuGameLogo::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMainMenuGameLogo::GetMessageMap'::`2'::s_pMap;
  `CMainMenuGameLogo::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMainMenuGameLogo");
  `CMainMenuGameLogo::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F7780
// Name: public: virtual struct PanelAnimationMap __near * CMainMenuGameLogo::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMainMenuGameLogo::GetAnimMap(CMainMenuGameLogo *this)
{
  return FindOrAddPanelAnimationMap(className: "CMainMenuGameLogo");
}

//------------------------------------------------------------------------------
// Address: 0x101F7790
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMainMenuGameLogo::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMainMenuGameLogo::GetKBMap(CMainMenuGameLogo *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMainMenuGameLogo::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMainMenuGameLogo::GetKBMap'::`2'::s_pMap;
  `CMainMenuGameLogo::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMainMenuGameLogo");
  `CMainMenuGameLogo::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F77C0
// Name: public: virtual void CBaseModPanel::CloseBaseDialogs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::CloseBaseDialogs(CBaseModPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax

  if ( vgui::PHandle::Get(this: &this->m_hNewGameDialog) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hNewGameDialog);
    v2->__vftable[1].GetAnimMap(this: v2);
  }
  if ( vgui::PHandle::Get(this: &this->m_hBonusMapsDialog) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hBonusMapsDialog);
    v3->__vftable[1].GetAnimMap(this: v3);
  }
  if ( vgui::PHandle::Get(this: &this->m_hLoadGameDialog_Xbox) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hLoadGameDialog_Xbox);
    v4->__vftable[1].GetAnimMap(this: v4);
  }
  if ( vgui::PHandle::Get(this: &this->m_hSaveGameDialog_Xbox) != nullptr )
  {
    v5 = vgui::PHandle::Get(this: &this->m_hSaveGameDialog_Xbox);
    v5->__vftable[1].GetAnimMap(this: v5);
  }
  if ( vgui::PHandle::Get(this: &this->m_hLoadCommentaryDialog) != nullptr )
  {
    v6 = vgui::PHandle::Get(this: &this->m_hLoadCommentaryDialog);
    v6->__vftable[1].GetAnimMap(this: v6);
  }
  if ( vgui::PHandle::Get(this: &this->m_hCreateMultiplayerGameDialog) != nullptr )
  {
    v7 = vgui::PHandle::Get(this: &this->m_hCreateMultiplayerGameDialog);
    v7->__vftable[1].GetAnimMap(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7960
// Name: protected: virtual void CBaseModPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseModPanel::PaintBackground(CBaseModPanel *this@<ecx>, int a2@<edi>)
{
  CGameUI *v3; // eax
  CCStrike15BasePanel *v4; // eax
  CCStrike15BasePanel *v5; // eax
  int swide; // [esp+4h] [ebp-8h] BYREF
  int stall; // [esp+8h] [ebp-4h] BYREF

  v3 = GameUI();
  if ( !v3->IsInLevel(this: v3) || this->m_ExitingFrameCount != 0 )
    CBaseModPanel::DrawBackgroundImage(this, a2);
  v4 = BasePanel();
  if ( !v4->IsScaleformMainMenuActive(this: v4) )
  {
    v5 = BasePanel();
    if ( !v5->IsScaleformPauseMenuActive(this: v5) && this->m_flBackgroundFillAlpha != 0.0 )
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, int))g_pVGuiSurface->DrawSetColor_2)(
        a1: 0,
        a2: 0,
        a3: 0,
        a4: (int)this->m_flBackgroundFillAlpha);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: swide, a5: stall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7A20
// Name: public: virtual void CBaseModPanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnSizeChanged(CBaseModPanel *this, int newWide, int newTall)
{
  CMessageDialogHandler::PositionDialogs(this: &this->m_MessageDialogHandler, wide: newWide, tall: newTall);
}

//------------------------------------------------------------------------------
// Address: 0x101F7A30
// Name: private: void CBaseModPanel::CreateGameLogo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::CreateGameLogo(CBaseModPanel *this)
{
  CModInfo *v2; // eax
  CMainMenuGameLogo *v3; // eax
  CMainMenuGameLogo *v4; // eax

  v2 = ModInfo();
  if ( CModInfo::UseGameLogo(this: v2) )
  {
    v3 = (CMainMenuGameLogo *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v3 != nullptr )
      v4 = CMainMenuGameLogo::CMainMenuGameLogo(this: v3, parent: this, name: "GameLogo");
    else
      v4 = nullptr;
    this->m_pGameLogo = v4;
    if ( v4 != nullptr )
    {
      vgui::Panel::MakeReadyForUse(this: v4);
      this->m_pGameLogo->InvalidateLayout(this: this->m_pGameLogo, a2: true, a3: true);
      vgui::Panel::SetAlpha(this: this->m_pGameLogo, alpha: 0);
    }
  }
  else
  {
    this->m_pGameLogo = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7AB0
// Name: private: virtual void CBaseModPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::PerformLayout(CBaseModPanel *this)
{
  int y; // ecx
  int m_iGameMenuInset; // edx
  int v4; // ebx
  int v5; // edi
  int i; // ebx
  CBackgroundMenuButton *v7; // ecx
  CMainMenuGameLogo *m_pGameLogo; // ecx
  int m_nOffsetY; // edi
  int m_nOffsetX; // ebx
  int v11; // eax
  CGameUI *v12; // eax
  CGameUI *v13; // eax
  int v14; // eax
  int posy; // [esp+Ch] [ebp-1Ch] BYREF
  int menuWide; // [esp+10h] [ebp-18h] BYREF
  int wide; // [esp+14h] [ebp-14h] BYREF
  int posx; // [esp+18h] [ebp-10h] BYREF
  int tall; // [esp+1Ch] [ebp-Ch] BYREF
  int menuTall; // [esp+20h] [ebp-8h] BYREF
  int idealMenuY; // [esp+24h] [ebp-4h]

  vgui::Panel::PerformLayout(this);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
  vgui::Panel::GetSize(this: this->m_pGameMenu, wide: &menuWide, tall: &menuTall);
  y = this->m_iGameMenuPos.y;
  m_iGameMenuInset = this->m_iGameMenuInset;
  idealMenuY = y;
  v4 = y;
  if ( menuTall + m_iGameMenuInset + y > tall )
  {
    idealMenuY = tall - m_iGameMenuInset - menuTall;
    v4 = idealMenuY;
  }
  v5 = 0;
  for ( i = v4 - y; v5 < this->m_pGameMenuButtons.m_Size; ++v5 )
  {
    v7 = this->m_pGameMenuButtons.m_Memory.m_pMemory[v5];
    v7->SizeToContents(this: v7);
    vgui::Panel::SetPos(
      this: this->m_pGameMenuButtons.m_Memory.m_pMemory[v5],
      x: this->m_iGameTitlePos.m_Memory.m_pMemory[v5].x,
      y: i + this->m_iGameTitlePos.m_Memory.m_pMemory[v5].y);
  }
  m_pGameLogo = this->m_pGameLogo;
  if ( m_pGameLogo != nullptr )
  {
    m_nOffsetY = m_pGameLogo->m_nOffsetY;
    m_nOffsetX = m_pGameLogo->m_nOffsetX;
    v11 = vgui::Panel::GetTall(this: m_pGameLogo);
    vgui::Panel::SetPos(
      this: this->m_pGameLogo,
      x: m_nOffsetX + this->m_iGameMenuPos.x,
      y: idealMenuY + m_nOffsetY - v11);
  }
  v12 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v12) )
  {
    vgui::Panel::GetPos(this: this->m_pGameMenu, x: &posx, y: &posy);
    this->m_iGameMenuPos.x = posx;
  }
  vgui::Panel::SetPos(this: this->m_pGameMenu, x: this->m_iGameMenuPos.x, y: idealMenuY);
  v13 = GameUI();
  LOBYTE(posx) = v13->IsInLevel(this: v13);
  if ( (_BYTE)posx == 0 || (v14 = engine->GetMaxClients(this: engine), LOBYTE(idealMenuY) = 1, v14 <= 1) )
    LOBYTE(idealMenuY) = 0;
  CGameMenu::UpdateMenuItemState(this: this->m_pGameMenu, isInGame: posx, isMultiplayer: idealMenuY);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->m_pGameMenu->SetVisible(this: this->m_pGameMenu, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x101F7C50
// Name: public: void CBaseModPanel::CloseMessageDialog(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::CloseMessageDialog(CBaseModPanel *this, unsigned int nType)
{
  CMessageDialogHandler::CloseMessageDialog(this: &this->m_MessageDialogHandler, nType);
}

//------------------------------------------------------------------------------
// Address: 0x101F7C60
// Name: private: void CBaseModPanel::SetMenuAlpha(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::SetMenuAlpha(CBaseModPanel *this, int alpha)
{
  CGameUI *v3; // eax
  CMainMenuGameLogo *m_pGameLogo; // ecx
  int i; // edi

  v3 = GameUI();
  if ( !CGameUI::IsConsoleUI(this: v3) )
  {
    vgui::Panel::SetAlpha(this: this->m_pGameMenu, alpha);
    m_pGameLogo = this->m_pGameLogo;
    if ( m_pGameLogo != nullptr )
      vgui::Panel::SetAlpha(this: m_pGameLogo, alpha);
    for ( i = 0; i < this->m_pGameMenuButtons.m_Size; ++i )
      vgui::Panel::SetAlpha(this: this->m_pGameMenuButtons.m_Memory.m_pMemory[i], alpha);
    this->m_bForceTitleTextUpdate = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7CD0
// Name: private: bool CBaseModPanel::LoadVersionNumber(char const __near *,char const __near *,wchar_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseModPanel::LoadVersionNumber(
        CBaseModPanel *this,
        unsigned int fileNameA,
        const char *fileNameB,
        wchar_t *pVersionBuffer,
        unsigned int versionBufferSizeBytes)
{
  const char *v5; // edi
  int v6; // eax
  const char *v7; // ebx
  int v8; // esi
  int v9; // eax
  const char *v10; // esi
  void *v12; // edi
  unsigned int v13; // ebx
  unsigned int v14; // esi
  _WORD *v15; // ebx
  int v16; // eax
  void (__thiscall *Close)(IBaseFileSystem *, void *); // edx
  int v18; // esi
  unsigned __int16 *v19; // edi
  const char *v20; // esi
  int fileSize; // [esp+Ch] [ebp-4h]

  v5 = (const char *)fileNameA;
  v6 = g_pFullFileSystem->GetFileTime(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: (const char *)fileNameA,
         a3: nullptr);
  v7 = fileNameB;
  v8 = v6;
  v9 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: fileNameB, a3: nullptr);
  if ( v8 == -1 || v8 <= v9 )
  {
    fileNameB = v7;
    v10 = v7;
  }
  else
  {
    if ( v9 != -1 && v9 > v8 )
      goto LABEL_8;
    v10 = v5;
    fileNameB = v5;
  }
  if ( v10 == nullptr )
  {
LABEL_8:
    _Msg(a1: "Error opening version files \"%s\" and \"%s\"\n", v5, v7);
    return 0;
  }
  v12 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v10, a3: "rb", a4: 0);
  if ( v12 == nullptr )
  {
    _Msg(a1: "Error opening version file \"%s\"\n", v10);
    return 0;
  }
  v13 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12);
  fileSize = v13;
  v14 = v13 + 2;
  if ( g_pFullFileSystem->GetOptimalIOConstraints(
         this: g_pFullFileSystem,
         a2: v12,
         a3: &fileNameA,
         a4: nullptr,
         a5: nullptr) )
  {
    v14 = ~(fileNameA - 1) & (fileNameA + v14 - 1);
  }
  if ( v13 != 0 && v14 != 0 )
  {
    v15 = g_pFullFileSystem->AllocOptimalReadBuffer(this: g_pFullFileSystem, a2: v12, a3: v14, a4: 0);
    _V_memset(dest: (int)v15, fill: nullptr, count: v14);
    v16 = g_pFullFileSystem->ReadEx(this: g_pFullFileSystem, a2: v15, a3: v14, a4: fileSize, a5: v12);
    Close = g_pFullFileSystem->Close;
    HIBYTE(fileNameA) = v16 != 0;
    v18 = v14 >> 1;
    Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12);
    if ( HIBYTE(fileNameA) == 0 )
    {
      _Msg(a1: "Error reading version file \"%s\"\n", fileNameB);
LABEL_17:
      g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: v15);
      return 0;
    }
    v19 = v15;
    if ( *v15 != 0xFEFF )
    {
      _Msg(a1: "Invalid non-unicode version file \"%s\"\n", fileNameB);
      goto LABEL_17;
    }
    fileNameA &= 0xFFFFFFFC;
    CByteswap::SwapBufferToTargetEndian<unsigned short>(
      this: (CByteswap *)&fileNameA,
      outputBuffer: v15,
      inputBuffer: v15,
      count: v18);
    fileNameA = (unsigned int)&v15[v18];
    if ( v15 != (_WORD *)fileNameA )
    {
      do
      {
        if ( *v19 == 0 )
          break;
        if ( iswalnum(c: *v19) != 0 )
          break;
        if ( iswpunct(c: *v19) != 0 )
          break;
        ++v19;
      }
      while ( v19 != (unsigned __int16 *)fileNameA );
    }
    v20 = (const char *)v19;
    if ( v19 != (unsigned __int16 *)fileNameA )
    {
      while ( iswalnum(c: *(_WORD *)v20) != 0 || iswpunct(c: *(_WORD *)v20) != 0 || *(_WORD *)v20 == 32 )
      {
        v20 += 2;
        if ( v20 == (const char *)fileNameA )
          goto LABEL_31;
      }
      *(_WORD *)v20 = 0;
    }
LABEL_31:
    V_wcsncpy(pDest: pVersionBuffer, pSrc: v19, maxLenInBytes: versionBufferSizeBytes);
    g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: v15);
    return 1;
  }
  else
  {
    _Msg(a1: "Invalid version file \"%s\"\n", fileNameB);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7F60
// Name: public: void CMessageDialogHandler::CreateMessageDialog(unsigned int,char const __near *,char const __near *,char const __near *,char const __near *,class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialogHandler::CreateMessageDialog(
        CMessageDialogHandler *this,
        unsigned int nType,
        const char *pTitle,
        const char *pMsg,
        const char *pCmdA,
        const char *pCmdB,
        vgui::Panel *pCreator,
        bool bShowActivity)
{
  vgui::PHandle *v8; // esi
  CMessageDialog *v9; // edi
  CCStrike15BasePanel *v10; // eax
  CMessageDialog *v11; // eax
  KeyValues *m_pConsoleControlSettings; // edi
  CMessageDialog *v13; // ebx
  KeyValues *Key; // eax
  vgui::Panel *v15; // eax
  vgui::ISurface *v16; // esi
  vgui::ISurface_vtbl *v17; // edi
  int v18; // eax
  int nStackIdx; // [esp+10h] [ebp-4h]

  nStackIdx = 0;
  if ( (nType & 1) != 0 )
  {
    nStackIdx = 1;
  }
  else if ( (nType & 2) != 0 )
  {
    nStackIdx = 2;
  }
  v8 = &this->m_hMessageDialogs[nStackIdx];
  if ( vgui::PHandle::Get(this: v8) != nullptr )
  {
    _Warning(a1: "Tried to create two dialogs of type %d\n", nStackIdx);
  }
  else
  {
    v9 = (CMessageDialog *)MemAlloc_Alloc(nSize: 0x284u);
    if ( v9 != nullptr )
    {
      v10 = BasePanel();
      v11 = CMessageDialog::CMessageDialog(
              this: v9,
              pParent: v10,
              nType,
              pTitle,
              pMsg,
              pCmdA,
              pCmdB,
              pCreator,
              bShowActivity);
    }
    else
    {
      v11 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: v8, pPanel: v11);
    m_pConsoleControlSettings = BasePanel()->m_pConsoleControlSettings;
    v13 = (CMessageDialog *)vgui::PHandle::Get(this: v8);
    Key = KeyValues::FindKey(this: m_pConsoleControlSettings, keyName: "MessageDialog.res", bCreate: false);
    CMessageDialog::SetControlSettingsKeys(this: v13, pKeys: Key);
    if ( (nType & 0x400) != 0 )
    {
      v15 = vgui::PHandle::Get(this: v8);
      v16 = g_pVGuiSurface;
      v17 = g_pVGuiSurface->__vftable;
      v18 = ((int (__thiscall *)(vgui::Panel *, _DWORD))v15->GetVPanel)(a1: v15, a2: 0);
      ((void (__thiscall *)(vgui::ISurface *, int))v17->RestrictPaintToSinglePanel)(a1: v16, a2: v18);
    }
    CMessageDialogHandler::ActivateMessageDialog(this, nStackIdx);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8070
// Name: public: void CBaseModPanel::ShowMainMenu(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::ShowMainMenu(CBaseModPanel *this, BOOL bShow)
{
  CMainMenuGameLogo *m_pGameLogo; // ecx
  CGameMenu *m_pGameMenu; // eax
  int i; // edi
  vgui::MenuItem *MenuItem; // eax
  vgui::MenuItem *v7; // eax
  int j; // edi
  CBackgroundMenuButton *v9; // ecx
  CBackgroundMenuButton *v10; // ecx
  CGameUI *v11; // eax

  if ( this->m_bMainMenuShown != bShow )
  {
    this->SetVisible(this, a2: bShow);
    CBaseModPanel::SetMenuAlpha(this, alpha: (unsigned __int8)-bShow);
    m_pGameLogo = this->m_pGameLogo;
    if ( m_pGameLogo != nullptr )
      m_pGameLogo->SetVisible(this: m_pGameLogo, a2: bShow);
    m_pGameMenu = this->m_pGameMenu;
    if ( m_pGameMenu != nullptr )
    {
      if ( m_pGameMenu->m_pConsoleFooter != nullptr )
        m_pGameMenu->m_pConsoleFooter->SetVisible(this: m_pGameMenu->m_pConsoleFooter, a2: bShow);
      this->m_pGameMenu->SetEnabled(this: this->m_pGameMenu, a2: bShow);
      this->m_pGameMenu->SetVisible(this: this->m_pGameMenu, a2: bShow);
      for ( i = 0; i < this->m_pGameMenu->GetItemCount(this: this->m_pGameMenu); ++i )
      {
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pGameMenu, itemID: i);
        MenuItem->SetEnabled(this: MenuItem, a2: bShow);
        v7 = vgui::Menu::GetMenuItem(this: this->m_pGameMenu, itemID: i);
        v7->SetVisible(this: v7, a2: bShow);
      }
    }
    for ( j = 0; j < this->m_pGameMenuButtons.m_Size; ++j )
    {
      v9 = this->m_pGameMenuButtons.m_Memory.m_pMemory[j];
      v9->SetEnabled(this: v9, a2: bShow);
      v10 = this->m_pGameMenuButtons.m_Memory.m_pMemory[j];
      v10->SetVisible(this: v10, a2: bShow);
    }
    if ( bShow )
    {
      v11 = GameUI();
      if ( CGameUI::IsConsoleUI(this: v11) )
      {
        CBaseModPanel::ArmFirstMenuItem(this);
        vgui::AnimationController::StartAnimationSequence(
          this: this->m_pConsoleAnimationController,
          sequenceName: "InitializeUILayout");
        vgui::AnimationController::StartAnimationSequence(
          this: this->m_pConsoleAnimationController,
          sequenceName: "OpenMainMenu");
        this->m_bFadingInMenus = false;
      }
    }
    this->m_bMainMenuShown = bShow;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8750
// Name: private: void CBaseModPanel::SetBackgroundRenderState(enum CBaseModPanel::EBackgroundState)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::SetBackgroundRenderState(CBaseModPanel *this, CBaseModPanel::EBackgroundState state)
{
  CGameUI *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  void (__thiscall *HandleOpenCreateStartScreen)(CBaseModPanel *); // edx
  int v8; // [esp+0h] [ebp-8h]
  float frametime; // [esp+10h] [ebp+8h]

  if ( state == this->m_eBackgroundState )
    return;
  frametime = _Plat_FloatTime(a1: v8);
  this->m_bRenderingBackgroundTransition = false;
  this->m_bFadingInMenus = false;
  if ( state == BACKGROUND_EXITING )
  {
    this->m_eBackgroundState = BACKGROUND_EXITING;
    this->m_bCopyFrameBuffer = false;
    return;
  }
  if ( state == BACKGROUND_DISCONNECTED || state == BACKGROUND_MAINMENU )
  {
    if ( this->m_bForceStartScreen )
    {
      HandleOpenCreateStartScreen = this->HandleOpenCreateStartScreen;
      this->m_bForceStartScreen = false;
      HandleOpenCreateStartScreen(this);
      this->m_eBackgroundState = state;
      return;
    }
    if ( this->m_eBackgroundState == BACKGROUND_LEVEL )
    {
      if ( this->m_bScaleformMainMenuEnabled )
      {
        if ( !this->m_bShowStartScreen )
        {
          CBaseModPanel::ShowMainMenu(this, bShow: false);
          this->ShowScaleformMainMenu(this, a2: true);
        }
      }
      else
      {
        CBaseModPanel::ShowMainMenu(this, bShow: true);
      }
    }
    this->m_bFadingInMenus = true;
    this->m_flFadeMenuStartTime = frametime;
    this->m_flFadeMenuEndTime = frametime + 3.0;
    if ( state == BACKGROUND_MAINMENU )
    {
      this->m_bRenderingBackgroundTransition = true;
      this->m_flTransitionStartTime = frametime;
      this->m_flTransitionEndTime = frametime + 3.0;
    }
    goto LABEL_24;
  }
  if ( state != BACKGROUND_LOADING )
  {
    if ( state == BACKGROUND_LEVEL )
    {
      CBaseModPanel::SetMenuAlpha(this, alpha: 255);
      this->m_eBackgroundState = BACKGROUND_LEVEL;
      return;
    }
LABEL_24:
    this->m_eBackgroundState = state;
    return;
  }
  v4 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v4) )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "LoadMap");
    else
      v6 = nullptr;
    CBaseModPanel::RunAnimationWithCallback(this, parent: this, animName: "InstantHideMainMenu", msgFunc: v6);
  }
  CBaseModPanel::SetMenuAlpha(this, alpha: 0);
  this->DismissMainMenuScreen(this);
  this->m_eBackgroundState = BACKGROUND_LOADING;
}

//------------------------------------------------------------------------------
// Address: 0x101F88E0
// Name: public: virtual void CBaseModPanel::OnLevelLoadingFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnLevelLoadingFinished(CBaseModPanel *this)
{
  if ( this->m_bScaleformPauseMenuEnabled )
    CBaseModPanel::ShowMainMenu(this, bShow: false);
  this->m_bLevelLoading = false;
}

//------------------------------------------------------------------------------
// Address: 0x101F8900
// Name: public: void CBaseModPanel::CompleteStartScreenSignIn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::CompleteStartScreenSignIn(CBaseModPanel *this)
{
  void (__thiscall *DismissStartScreen)(CBaseModPanel *); // edx
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMatchEventsSubscription *v5; // eax

  this->LockInput(this);
  DismissStartScreen = this->DismissStartScreen;
  this->m_bStartScreenPlayerSigninCompleted = false;
  this->m_bWaitingForUserSignIn = false;
  this->m_bUserRefusedSignIn = false;
  DismissStartScreen(this);
  this->m_bShowStartScreen = false;
  if ( this->m_bScaleformMainMenuEnabled )
    this->OnOpenCreateMainMenuScreen(this);
  else
    CBaseModPanel::ShowMainMenu(this, bShow: true);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "OnProfilesChanged", firstKey: "numProfiles", firstValue: 1);
  else
    v4 = nullptr;
  v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v5->BroadcastEvent(this: v5, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F89A0
// Name: public: virtual void CBaseModPanel::OnOpenCreateStartScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenCreateStartScreen(CBaseModPanel *this)
{
  this->m_bShowStartScreen = false;
  CBaseModPanel::ShowMainMenu(this, bShow: true);
}

//------------------------------------------------------------------------------
// Address: 0x101F89B0
// Name: public: virtual void CBaseModPanel::DismissMainMenuScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::DismissMainMenuScreen(CBaseModPanel *this)
{
  CBaseModPanel::ShowMainMenu(this, bShow: false);
}

//------------------------------------------------------------------------------
// Address: 0x101F89C0
// Name: public: virtual void CBaseModPanel::RestoreMainMenuScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::RestoreMainMenuScreen(CBaseModPanel *this)
{
  CBaseModPanel::ShowMainMenu(this, bShow: true);
}

//------------------------------------------------------------------------------
// Address: 0x101F89D0
// Name: public: void CBaseModPanel::NotifyVguiDialogClosed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::NotifyVguiDialogClosed(CBaseModPanel *this)
{
  CGameUI *v2; // eax

  v2 = GameUI();
  if ( v2->IsInLevel(this: v2) )
  {
    if ( this->m_bScaleformPauseMenuEnabled && this->m_bMainMenuShown )
    {
      g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
      CBaseModPanel::ShowMainMenu(this, bShow: false);
      this->RestorePauseMenu(this);
    }
  }
  else if ( this->m_bScaleformMainMenuEnabled && this->m_bMainMenuShown )
  {
    CBaseModPanel::ShowMainMenu(this, bShow: false);
    this->RestoreMainMenuScreen(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8A50
// Name: private: void CBaseModPanel::LoadVersionNumbers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::LoadVersionNumbers(CBaseModPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  vgui::Label_vtbl *v5; // ebx
  KeyValues *Key; // eax
  vgui::Label_vtbl *v7; // ebx
  KeyValues *v8; // eax
  bool v9; // zf
  wchar_t *v10; // eax
  wchar_t *v11; // eax
  wchar_t contentVersion[256]; // [esp+8h] [ebp-400h] BYREF
  wchar_t codeVersion[256]; // [esp+208h] [ebp-200h] BYREF

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "MainGameMenuScreen.res");
  else
    v3 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: "resource/MainGameMenuScreen.res",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    v5 = this->m_pCodeVersionLabel->__vftable;
    Key = KeyValues::FindKey(this: v3, keyName: "CodeVersionLabel", bCreate: false);
    v5->ApplySettings(this: this->m_pCodeVersionLabel, a2: Key);
    v7 = this->m_pContentVersionLabel->__vftable;
    v8 = KeyValues::FindKey(this: v3, keyName: "ContentVersionLabel", bCreate: false);
    v7->ApplySettings(this: this->m_pContentVersionLabel, a2: v8);
  }
  codeVersion[0] = 0;
  v9 = CBaseModPanel::LoadVersionNumber(
         this,
         fileNameA: (unsigned int)"resource\\css_code_version.txt",
         fileNameB: "resource\\css_code_version_local.txt",
         pVersionBuffer: codeVersion,
         versionBufferSizeBytes: 0xFFu) == 0;
  v10 = codeVersion;
  if ( v9 )
    v10 = L"_ _ _ _ _ _";
  this->m_pCodeVersionLabel->SetText(this: this->m_pCodeVersionLabel, a2: v10, a3: false);
  contentVersion[0] = 0;
  v9 = CBaseModPanel::LoadVersionNumber(
         this,
         fileNameA: (unsigned int)"resource\\css_content_version.txt",
         fileNameB: "resource\\css_content_version_local.txt",
         pVersionBuffer: contentVersion,
         versionBufferSizeBytes: 0xFFu) == 0;
  v11 = contentVersion;
  if ( v9 )
    v11 = L"_ _ _ _ _ _";
  this->m_pContentVersionLabel->SetText(this: this->m_pContentVersionLabel, a2: v11, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101F8BA0
// Name: public: void CMessageDialogHandler::ShowMessageDialog(int,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialogHandler::ShowMessageDialog(CMessageDialogHandler *this, int nType, vgui::Panel *pOwner)
{
  int v4; // esi
  CModInfo *v5; // eax

  v4 = 0;
  v5 = ModInfo();
  if ( CModInfo::IsSinglePlayerOnly(this: v5) )
    v4 = 256;
  switch ( nType )
  {
    case 0:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x420,
        pTitle: "#GameUI_QuitConfirmationTitle",
        pMsg: "#GameUI_Console_QuitWarning",
        pCmdA: "QuitNoConfirm",
        pCmdB: "CloseQuitDialog_OpenMainMenu",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 1:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x420,
        pTitle: "#GameUI_QuitConfirmationTitle",
        pMsg: "#GameUI_QuitConfirmationText",
        pCmdA: "QuitNoConfirm",
        pCmdB: "CloseQuitDialog_OpenMainMenu",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 2:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x420u,
        pTitle: "#GameUI_QuitConfirmationTitle",
        pMsg: "#GameUI_QuitConfirmationText",
        pCmdA: "QuitNoConfirm",
        pCmdB: "CloseQuitDialog_OpenMatchmakingMenu",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 3:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x20u,
        pTitle: prType,
        pMsg: "#TF_Dlg_ConfirmKick",
        pCmdA: "KickPlayer",
        pCmdB: "close_dialog",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 4:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x404u,
        pTitle: prType,
        pMsg: "#TF_Dlg_ClientKicked",
        pCmdA: "close_dialog",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 5:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x404u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_LostHost",
        pCmdA: "ReturnToMainMenu",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 6:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x404u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_LostServer",
        pCmdA: "ReturnToMainMenu",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 7:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x408u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_SearchingForGames",
        pCmdA: nullptr,
        pCmdB: "CancelOperation",
        pCreator: pOwner,
        bShowActivity: true);
      break;
    case 8:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x400u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_CreatingGame",
        pCmdA: nullptr,
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: true);
      break;
    case 9:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x400u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_ModifyingSession",
        pCmdA: nullptr,
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: true);
      break;
    case 10:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x420u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_NoGamesFound",
        pCmdA: "ShowSessionOptionsDialog",
        pCmdB: "ReturnToMainMenu",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 11:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 4u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_CreateFailed",
        pCmdA: "ReturnToMainMenu",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 12:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_Connecting",
        pCmdA: nullptr,
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: true);
      break;
    case 13:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 4u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_JoinRefused",
        pCmdA: "ReturnToMainMenu",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 14:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 4u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_GameFull",
        pCmdA: "ReturnToMainMenu",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 15:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 4u,
        pTitle: nullptr,
        pMsg: "#TF_Dlg_JoinFailed",
        pCmdA: "ReturnToMainMenu",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 16:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x20u,
        pTitle: prType,
        pMsg: "#TF_Dlg_ExitSessionText",
        pCmdA: "ReturnToMainMenu",
        pCmdB: "close_dialog",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 17:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x621,
        pTitle: "#GameUI_Console_StorageRemovedTitle",
        pMsg: "#GameUI_Console_StorageNeededBody",
        pCmdA: "ShowDeviceSelector",
        pCmdB: "QuitNoConfirm",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 18:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x621,
        pTitle: "#GameUI_Console_StorageRemovedTitle",
        pMsg: "#GameUI_Console_StorageRemovedBody",
        pCmdA: "ShowDeviceSelector",
        pCmdB: "clear_storage_deviceID",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 19:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x621,
        pTitle: "#GameUI_Console_StorageTooFullTitle",
        pMsg: "#GameUI_Console_StorageTooFullBody",
        pCmdA: "ShowDeviceSelector",
        pCmdB: "StorageDeviceDenied",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 20:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x21u,
        pTitle: prType,
        pMsg: "#TF_Dlg_NotOnlineEnabled",
        pCmdA: "ShowSigninUI",
        pCmdB: "close_dialog",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 21:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x21u,
        pTitle: prType,
        pMsg: "#TF_Dlg_NotOnlineSignedIn",
        pCmdA: "ShowSigninUI",
        pCmdB: "close_dialog",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 22:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x421,
        pTitle: "#GameUI_RestoreDefaults",
        pMsg: "#GameUI_ControllerSettingsText",
        pCmdA: "DefaultControls",
        pCmdB: "close_dialog",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 23:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x405,
        pTitle: "#GameUI_ConfirmNewGame_Title",
        pMsg: "#GameUI_AutoSave_Console_Explanation",
        pCmdA: "StartNewGameNoCommentaryExplanation",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 24:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x405,
        pTitle: "#GameUI_CommentaryDialogTitle",
        pMsg: "#GAMEUI_Commentary_Console_Explanation",
        pCmdA: "StartNewGameNoCommentaryExplanation",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 25:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 5u,
        pTitle: "#GameUI_CommentaryDialogTitle",
        pMsg: "#GAMEUI_Commentary_Console_Explanation",
        pCmdA: "StartNewGameNoCommentaryExplanation",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 26:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x405,
        pTitle: "#GameUI_CommentaryDialogTitle",
        pMsg: "#GameUI_CommentaryUnlock",
        pCmdA: "close_dialog",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 27:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x721u,
        pTitle: "#GameUI_ChangeLanguageRestart_Title",
        pMsg: "#GameUI_ChangeLanguageRestart_Info",
        pCmdA: "AcceptVocalsLanguageChange",
        pCmdB: "CancelVocalsLanguageChange",
        pCreator: pOwner,
        bShowActivity: false);
      goto $LN14_18;
    case 28:
$LN14_18:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x611,
        pTitle: "#GameUI_ConfirmNewGame_Title",
        pMsg: "#GameUI_NewGameWarning",
        pCmdA: "StartNewGame",
        pCmdB: "close_dialog",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 29:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x611,
        pTitle: "#GameUI_ConfirmLoadGame_Title",
        pMsg: "#GameUI_LoadWarning",
        pCmdA: "LoadGame",
        pCmdB: "LoadGameCancelled",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 30:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x211,
        pTitle: "#GameUI_ConfirmDeleteSaveGame_Title",
        pMsg: "#GameUI_ConfirmDeleteSaveGame_Info",
        pCmdA: "DeleteGame",
        pCmdB: "DeleteGameCancelled",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 31:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x211,
        pTitle: "#GameUI_ConfirmOverwriteSaveGame_Title",
        pMsg: "#GameUI_ConfirmOverwriteSaveGame_Info",
        pCmdA: "SaveGame",
        pCmdB: "OverwriteGameCancelled",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 32:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x801,
        pTitle: prType,
        pMsg: "#GameUI_SavingWarning",
        pCmdA: "SaveSuccess",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: true);
      break;
    case 33:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x204,
        pTitle: "#GameUI_ConfirmOverwriteSaveGame_Title",
        pMsg: "#GameUI_GameSaved",
        pCmdA: "CloseAndSelectResume",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 34:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 4u,
        pTitle: "Standard Dialog",
        pMsg: "This is a standard dialog",
        pCmdA: "close_dialog",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 35:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 5u,
        pTitle: "#GameUI_Dialog_Warning",
        pMsg: "This is a warning dialog",
        pCmdA: "close_dialog",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 36:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 6u,
        pTitle: "Error Dialog",
        pMsg: "This is an error dialog",
        pCmdA: "close_dialog",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 37:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x221,
        pTitle: "#GameUI_Console_NoUserProfileSelectedTitle",
        pMsg: "#GameUI_Console_NoUserProfileSelectedBody",
        pCmdA: "ShowSignInUI",
        pCmdB: "SignInDenied",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 38:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x221,
        pTitle: "#GameUI_Console_NoUserProfileSelectedTitle",
        pMsg: "#GameUI_Console_UserProfileRequiredBody",
        pCmdA: "ShowSignInUI",
        pCmdB: "RequiredSignInDenied",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 39:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x621,
        pTitle: "#GameUI_Console_NoStorageDeviceSelectedTitle",
        pMsg: "#GameUI_Console_NoStorageDeviceSelectedBody",
        pCmdA: "ShowDeviceSelector",
        pCmdB: "StorageDeviceDenied",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 40:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x321u,
        pTitle: "#GameUI_Console_NoStorageDeviceSelectedTitle",
        pMsg: "#GameUI_Console_StorageDeviceRequiredBody",
        pCmdA: "ShowDeviceSelector",
        pCmdB: "RequiredStorageDenied",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 41:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x420u,
        pTitle: prType,
        pMsg: "#GameUI_DisconnectConfirmationText",
        pCmdA: "DisconnectNoConfirm",
        pCmdB: "close_dialog",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 42:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: 0x420u,
        pTitle: prType,
        pMsg: "#GameUI_DisconnectHostConfirmationText",
        pCmdA: "DisconnectNoConfirm",
        pCmdB: "close_dialog",
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 43:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 5,
        pTitle: "#GameUI_LoadFailed",
        pMsg: "#GameUI_LoadFailed_Description",
        pCmdA: "close_dialog",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 44:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x404,
        pTitle: "#GameUI_SettingChangeFromX360Dashboard_Title",
        pMsg: "#GameUI_SettingChangeFromX360Dashboard_Info",
        pCmdA: "close_dialog",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 45:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x405,
        pTitle: prType,
        pMsg: "#GameUI_Console_FileCorrupt",
        pCmdA: "close_dialog",
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: false);
      break;
    case 46:
      CMessageDialogHandler::CreateMessageDialog(
        this,
        nType: v4 | 0x400,
        pTitle: nullptr,
        pMsg: "#GameUI_Dlg_CheckingStorageDevice",
        pCmdA: nullptr,
        pCmdB: nullptr,
        pCreator: pOwner,
        bShowActivity: true);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9430
// Name: show_main_menu
// Source: json
//------------------------------------------------------------------------------
void __cdecl show_main_menu()
{
  CBaseModPanel *v0; // eax

  v0 = BasePanel();
  CBaseModPanel::ShowMainMenu(this: v0, bShow: true);
}

//------------------------------------------------------------------------------
// Address: 0x101F9440
// Name: hide_main_menu
// Source: json
//------------------------------------------------------------------------------
void __cdecl hide_main_menu()
{
  CCStrike15BasePanel *v0; // eax

  v0 = BasePanel();
  CBaseModPanel::ShowMainMenu(this: v0, bShow: false);
}

//------------------------------------------------------------------------------
// Address: 0x101F9450
// Name: show_sf_main_menu
// Source: json
//------------------------------------------------------------------------------
void __cdecl show_sf_main_menu()
{
  CBaseModPanel *v0; // eax
  CBaseModPanel *v1; // eax

  BasePanel()->m_bScaleformMainMenuEnabled = true;
  v0 = BasePanel();
  CBaseModPanel::ShowMainMenu(this: v0, bShow: false);
  v1 = BasePanel();
  v1->OnOpenCreateMainMenuScreen(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101F9480
// Name: hide_sf_main_menu
// Source: json
//------------------------------------------------------------------------------
void __cdecl hide_sf_main_menu()
{
  CCStrike15BasePanel *v0; // eax
  CCStrike15BasePanel *v1; // eax

  BasePanel()->m_bScaleformMainMenuEnabled = false;
  v0 = BasePanel();
  v0->DismissMainMenuScreen(this: v0);
  v1 = BasePanel();
  CBaseModPanel::ShowMainMenu(this: v1, bShow: true);
}

//------------------------------------------------------------------------------
// Address: 0x101F9D30
// Name: private: void CBaseModPanel::UpdateBackgroundState(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseModPanel::UpdateBackgroundState(CBaseModPanel *this@<ecx>, int a2@<ebx>)
{
  CBaseModPanel::EBackgroundState v3; // edi
  CGameUI *v4; // eax
  CGameUI *v5; // eax
  CGameUI *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  bool v9; // zf
  void (__thiscall *HandleOpenCreateStartScreen)(CBaseModPanel *); // eax
  CGameUI *v11; // eax
  CGameUI *v12; // eax
  CGameUI *v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  unsigned int v17; // edi
  unsigned int v18; // edi
  int v19; // ebx
  unsigned int v20; // edi
  bool v21; // al
  float m_flFrameFadeInTime; // xmm2_4
  float targetValue; // xmm1_4
  vgui::AnimationController *AnimationController; // eax
  float v25; // xmm1_4
  float v26; // xmm2_4
  vgui::AnimationController *v27; // eax
  int i; // edi
  vgui::AnimationController *v29; // eax
  CMainMenuGameLogo *m_pGameLogo; // [esp+20h] [ebp-34h]
  CBackgroundMenuButton *v31; // [esp+20h] [ebp-34h]
  unsigned int v32; // [esp+3Ch] [ebp-18h]
  int v33; // [esp+40h] [ebp-14h]
  float targetTitleAlpha; // [esp+48h] [ebp-Ch]
  int duration; // [esp+4Ch] [ebp-8h]
  unsigned int durationa; // [esp+4Ch] [ebp-8h]
  char bIsInLevel; // [esp+52h] [ebp-2h]
  bool bHaveActiveDialogs; // [esp+53h] [ebp-1h]

  if ( this->m_ExitingFrameCount != 0 )
  {
    v3 = BACKGROUND_EXITING;
    if ( this->m_eBackgroundState == BACKGROUND_EXITING )
      goto LABEL_30;
    _Plat_FloatTime(a1: v33);
    this->m_bRenderingBackgroundTransition = false;
    this->m_bFadingInMenus = false;
    this->m_bCopyFrameBuffer = false;
    goto LABEL_29;
  }
  v4 = GameUI();
  if ( v4->IsInLevel(this: v4) )
  {
    v3 = BACKGROUND_LEVEL;
    if ( this->m_eBackgroundState == BACKGROUND_LEVEL )
      goto LABEL_30;
    _Plat_FloatTime(a1: v33);
    this->m_bRenderingBackgroundTransition = false;
    this->m_bFadingInMenus = false;
    CBaseModPanel::SetMenuAlpha(this, alpha: 255);
    goto LABEL_29;
  }
  v5 = GameUI();
  if ( CGameUI::IsInBackgroundLevel(this: v5) )
  {
    if ( !this->m_bLevelLoading )
    {
      CBaseModPanel::SetBackgroundRenderState(this, state: BACKGROUND_MAINMENU);
      goto LABEL_30;
    }
    goto LABEL_11;
  }
  if ( this->m_bLevelLoading )
  {
LABEL_11:
    v3 = BACKGROUND_LOADING;
    if ( this->m_eBackgroundState == BACKGROUND_LOADING )
      goto LABEL_30;
    _Plat_FloatTime(a1: v33);
    this->m_bRenderingBackgroundTransition = false;
    this->m_bFadingInMenus = false;
    v6 = GameUI();
    if ( CGameUI::IsConsoleUI(this: v6) )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(this: v7, setName: "LoadMap");
      else
        v8 = nullptr;
      CBaseModPanel::RunAnimationWithCallback(this, parent: this, animName: "InstantHideMainMenu", msgFunc: v8);
    }
    CBaseModPanel::SetMenuAlpha(this, alpha: 0);
    this->DismissMainMenuScreen(this);
    goto LABEL_29;
  }
  if ( this->m_bEverActivated && this->m_bPlatformMenuInitialized )
  {
    v3 = BACKGROUND_DISCONNECTED;
    if ( this->m_eBackgroundState != BACKGROUND_DISCONNECTED )
    {
      targetTitleAlpha = _Plat_FloatTime(a1: v33);
      v9 = !this->m_bForceStartScreen;
      this->m_bRenderingBackgroundTransition = false;
      this->m_bFadingInMenus = false;
      if ( v9 )
      {
        if ( this->m_eBackgroundState == BACKGROUND_LEVEL )
        {
          if ( this->m_bScaleformMainMenuEnabled )
          {
            if ( !this->m_bShowStartScreen )
            {
              CBaseModPanel::ShowMainMenu(this, bShow: false);
              this->ShowScaleformMainMenu(this, a2: true);
            }
          }
          else
          {
            CBaseModPanel::ShowMainMenu(this, bShow: true);
          }
        }
        this->m_flFadeMenuStartTime = targetTitleAlpha;
        this->m_bFadingInMenus = true;
        this->m_flFadeMenuEndTime = targetTitleAlpha + 3.0;
      }
      else
      {
        HandleOpenCreateStartScreen = this->HandleOpenCreateStartScreen;
        this->m_bForceStartScreen = false;
        HandleOpenCreateStartScreen(this);
      }
LABEL_29:
      this->m_eBackgroundState = v3;
    }
  }
LABEL_30:
  v11 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v11) )
  {
    if ( this->m_ExitingFrameCount != 0
      || this->m_bLevelLoading
      || CLoadingScreenScaleform::IsOpen()
      || (v12 = GameUI(), !v12->IsInLevel(this: v12)) )
    {
      this->m_flBackgroundFillAlpha = 0.0;
    }
    else if ( this->m_flBackgroundFillAlpha == 0.0 )
    {
      this->m_flBackgroundFillAlpha = 120.0;
    }
  }
  else if ( this->m_bPlatformMenuInitialized )
  {
    bHaveActiveDialogs = false;
    v13 = GameUI();
    bIsInLevel = ((int (__thiscall *)(CGameUI *, int))v13->IsInLevel)(a1: v13, a2);
    for ( duration = 0; duration < vgui::Panel::GetChildCount(this); ++duration )
    {
      v14 = g_pVGuiPanel;
      v15 = g_pVGuiPanel->__vftable;
      v16 = ((int (__thiscall *)(CBaseModPanel *, int))this->GetVPanel)(a1: this, a2: duration);
      v17 = ((int (__thiscall *)(vgui::IPanel *, int))v15->GetChild)(a1: v14, a2: v16);
      if ( v17 != 0
        && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v17)
        && g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: v17)
        && v17 != this->m_pGameMenu->GetVPanel(this: this->m_pGameMenu) )
      {
        bHaveActiveDialogs = true;
      }
    }
    v18 = this->GetVParent(this);
    durationa = v18;
    v19 = 0;
    if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v18) > 0 )
    {
      while ( 1 )
      {
        v20 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, int, unsigned int))g_pVGuiPanel->GetChild)(
                a1: g_pVGuiPanel,
                a2: v18,
                a3: v19,
                a4: v32);
        if ( v20 != 0
          && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v20)
          && g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: v20)
          && v20 != this->GetVPanel(this) )
        {
          bHaveActiveDialogs = true;
        }
        v32 = durationa;
        if ( ++v19 >= ((int (__thiscall *)(vgui::IPanel *))g_pVGuiPanel->GetChildCount)(a1: g_pVGuiPanel) )
          break;
        v18 = durationa;
      }
    }
    v21 = bHaveActiveDialogs || bIsInLevel != 0;
    if ( this->m_bHaveDarkenedBackground != v21 )
    {
      if ( v21 )
      {
        m_flFrameFadeInTime = this->m_flFrameFadeInTime;
        targetValue = (float)this->m_BackdropColor._color[3];
      }
      else
      {
        m_flFrameFadeInTime = 2.0;
        targetValue = 0.0;
      }
      this->m_bHaveDarkenedBackground = v21;
      AnimationController = vgui::GetAnimationController();
      vgui::AnimationController::RunAnimationCommand(
        this: AnimationController,
        panel: this,
        variable: "m_flBackgroundFillAlpha",
        targetValue,
        startDelaySeconds: 0.0,
        duration: m_flFrameFadeInTime,
        interpolator: (vgui::AnimationController::Interpolators_e)0,
        animParameter: 0.0);
    }
    if ( !this->m_bLevelLoading
      && (this->m_bHaveDarkenedTitleText != bHaveActiveDialogs || this->m_bForceTitleTextUpdate) )
    {
      if ( bHaveActiveDialogs )
      {
        v25 = this->m_flFrameFadeInTime;
        v26 = 32.0;
      }
      else
      {
        v25 = 2.0;
        v26 = 255.0;
      }
      if ( this->m_pGameLogo != nullptr )
      {
        m_pGameLogo = this->m_pGameLogo;
        v27 = vgui::GetAnimationController();
        vgui::AnimationController::RunAnimationCommand(
          this: v27,
          panel: m_pGameLogo,
          variable: "alpha",
          targetValue: v26,
          startDelaySeconds: 0.0,
          duration: v25,
          interpolator: (vgui::AnimationController::Interpolators_e)0,
          animParameter: 0.0);
      }
      for ( i = 0; i < this->m_pGameMenuButtons.m_Size; ++i )
      {
        v31 = this->m_pGameMenuButtons.m_Memory.m_pMemory[i];
        v29 = vgui::GetAnimationController();
        vgui::AnimationController::RunAnimationCommand(
          this: v29,
          panel: v31,
          variable: "alpha",
          targetValue: v26,
          startDelaySeconds: 0.0,
          duration: v25,
          interpolator: (vgui::AnimationController::Interpolators_e)0,
          animParameter: 0.0);
      }
      this->m_bHaveDarkenedTitleText = bHaveActiveDialogs;
      this->m_bForceTitleTextUpdate = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA270
// Name: public: virtual void CBaseModPanel::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseModPanel::RunFrame(CBaseModPanel *this@<ecx>, int a2@<ebx>)
{
  vgui::AnimationController *AnimationController; // eax
  CGameConsole *v4; // eax
  bool v5; // zf
  void (__thiscall *EnableWindowsMessages)(IMatSystemSurface *, bool); // eax
  char v7; // bl
  int v8; // esi
  IInputSystem_vtbl *v9; // ebx
  ButtonCode_t v10; // eax
  IInputSystem_vtbl *v11; // ebx
  ButtonCode_t v12; // eax
  CCStrike15BasePanel *v13; // eax
  CGameUI *v14; // eax
  CBaseModPanel::CAsyncJobContext *m_pAsyncJob; // eax
  CBaseModPanel::CAsyncJobContext *v16; // ecx
  float currentTimea; // [esp+28h] [ebp-Ch]
  int currentTime; // [esp+28h] [ebp-Ch]
  float currentTimeb; // [esp+28h] [ebp-Ch]
  int v20; // [esp+2Ch] [ebp-8h]
  int v21; // [esp+2Ch] [ebp-8h]
  bool bStartPressed; // [esp+33h] [ebp-1h]

  this->InvalidateLayout(this, a2: false, a3: false);
  currentTimea = _Plat_FloatTime(a1: v20);
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime: currentTimea);
  if ( this->IsScaleformPauseMenuVisible(this) )
  {
    v4 = GameConsole();
    v5 = !v4->IsConsoleVisible(this: v4);
    EnableWindowsMessages = g_pMatSystemSurface->EnableWindowsMessages;
    if ( v5 )
    {
      ((void (__stdcall *)(_DWORD, int))EnableWindowsMessages)(a1: 0, a2: v21);
      v21 = 1;
    }
    else
    {
      ((void (__stdcall *)(int, int))EnableWindowsMessages)(a1: 1, a2: v21);
      v21 = 0;
    }
    ((void (__thiscall *)(IScaleformUI *))g_pScaleformUI->DenyInputToGame)(a1: g_pScaleformUI);
  }
  this->UpdateLeaderboardsDialog(this);
  if ( this->m_bShowStartScreen )
  {
    if ( this->m_bWaitingForUserSignIn )
      goto LABEL_27;
    currentTime = a2;
    v7 = 0;
    bStartPressed = false;
    v8 = 0;
    while ( v7 == 0 )
    {
      v9 = g_pInputSystem->__vftable;
      v10 = ButtonCodeToJoystickButtonCode(code: KEY_XBUTTON_START, nDesiredJoystick: v8);
      if ( v9->IsButtonDown(this: g_pInputSystem, a2: v10)
        || (v11 = g_pInputSystem->__vftable,
            v12 = ButtonCodeToJoystickButtonCode(code: JOYSTICK_FIRST, nDesiredJoystick: v8),
            v11->IsButtonDown(this: g_pInputSystem, a2: v12)) )
      {
        v7 = 1;
        bStartPressed = true;
      }
      else
      {
        v7 = bStartPressed;
      }
      if ( ++v8 >= 4 )
      {
        if ( v7 == 0
          && (g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: KEY_LBRACKET)
           || g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: KEY_SPACE)
           || g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: KEY_ENTER)) )
        {
          v7 = 1;
        }
        break;
      }
    }
    if ( (_S1_5 & 1) == 0 )
    {
      _S1_5 |= 1u;
      ConVarRef::ConVarRef(this: &testscript_running, pName: "testscript_running");
    }
    if ( testscript_running.m_pConVarState->m_Value.m_nValue != 0 )
    {
      s_idUser1 = 0;
    }
    else if ( v7 == 0 )
    {
LABEL_26:
      a2 = currentTime;
LABEL_27:
      if ( this->m_bStartScreenPlayerSigninCompleted )
        CBaseModPanel::CompleteStartScreenSignIn(this);
      goto LABEL_29;
    }
    g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "UI\\buttonclick.wav");
    v13 = BasePanel();
    CBaseModPanel::CompleteStartScreenSignIn(this: v13);
    goto LABEL_26;
  }
LABEL_29:
  v14 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v14) )
  {
    currentTimeb = _Plat_FloatTime(a1: v21);
    vgui::AnimationController::UpdateAnimations(this: this->m_pConsoleAnimationController, currentTime: currentTimeb);
  }
  CBaseModPanel::UpdateBackgroundState(this, a2);
  if ( !this->m_bPlatformMenuInitialized && CExampleEffect::IsEnabled(this: (CExampleEffect *)&g_VModuleLoader) )
    this->m_bPlatformMenuInitialized = true;
  m_pAsyncJob = this->m_pAsyncJob;
  if ( m_pAsyncJob != nullptr && m_pAsyncJob->m_hThreadHandle == nullptr )
  {
    this->m_pAsyncJob->Completed(this: this->m_pAsyncJob);
    v16 = this->m_pAsyncJob;
    if ( v16 != nullptr )
      ((void (__thiscall *)(CBaseModPanel::CAsyncJobContext *, int))v16->dtr_CAsyncJobContext)(a1: v16, a2: 1);
    this->m_pAsyncJob = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA4B0
// Name: protected: virtual void CBaseModPanel::RunMenuCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseModPanel::RunMenuCommand(CBaseModPanel *this@<ecx>, const char *a2@<ebx>, HKEY__ *command)
{
  CGameUI *v4; // eax
  bool v5; // al
  char *v6; // edi
  bool v7; // zf
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CGameUI *v10; // eax
  CGameUI *v11; // eax
  CGameUI *v12; // eax
  vgui::MessageBox *v13; // eax
  vgui::MessageBox *v14; // eax
  vgui::MessageBox *v15; // eax
  vgui::ISurface *v16; // edi
  vgui::ISurface_vtbl *v17; // ebx
  int v18; // eax
  CGameUI *v19; // eax
  const char *v20; // ecx
  int v21; // eax
  const char *v22; // eax
  CBaseModPanel_vtbl *v23; // ebx
  const char *v24; // eax
  vgui::CTreeViewListControl *v25; // ecx
  int *m_pStorageDeviceValidatedNotify; // eax
  vgui::CTreeViewListControl *v27; // ecx
  vgui::ISurface *v28; // edi
  vgui::ISurface_vtbl *v29; // ebx
  int v30; // eax
  int v31; // eax
  char szAppId[52]; // [esp+10h] [ebp-70h] BYREF
  BYTE szSteamURL[52]; // [esp+44h] [ebp-3Ch] BYREF
  ConVarRef commentary; // [esp+78h] [ebp-8h] BYREF

  v4 = GameUI();
  v5 = v4->IsInLevel(this: v4);
  v6 = (char *)command;
  if ( v5 )
    v7 = !BasePanel()->m_bScaleformPauseMenuEnabled;
  else
    v7 = !BasePanel()->m_bScaleformMainMenuEnabled;
  if ( !v7 && _V_stricmp(s1: v6, s2: "OpenOptionsDialog") == 0 )
  {
    g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
    CBaseModPanel::ShowMainMenu(this, bShow: true);
  }
  if ( _V_stricmp(s1: v6, s2: "OpenGameMenu") == 0 )
  {
    if ( this->m_pGameMenu != nullptr )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "Command", firstKey: "command", firstValue: "Open");
      else
        v9 = nullptr;
      ((void (__thiscall *)(CBaseModPanel *, CGameMenu *, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: this->m_pGameMenu,
        a3: v9,
        a4: 0);
    }
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenPlayerListDialog") == 0 )
  {
    CBaseModPanel::OnOpenPlayerListDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenNewGameDialog") == 0 )
  {
    CBaseModPanel::OnOpenNewGameDialog(this, chapter: nullptr);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenLoadGameDialog") == 0 )
  {
    v10 = GameUI();
    if ( CGameUI::IsConsoleUI(this: v10) )
      CBaseModPanel::OnOpenLoadGameDialog_Xbox(this);
    else
      CBaseModPanel::OnOpenLoadGameDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenSaveGameDialog") == 0 )
  {
    v11 = GameUI();
    if ( CGameUI::IsConsoleUI(this: v11) )
      CBaseModPanel::OnOpenSaveGameDialog_Xbox(this);
    else
      CBaseModPanel::OnOpenSaveGameDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenBonusMapsDialog") == 0 )
  {
    CBaseModPanel::OnOpenBonusMapsDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenOptionsDialog") == 0 )
  {
    v12 = GameUI();
    if ( !CGameUI::IsConsoleUI(this: v12) )
      CBaseModPanel::OnOpenOptionsDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenControllerDialog") == 0 )
  {
    this->OnOpenControllerDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenSettingsDialog") == 0 )
  {
    this->OnOpenSettingsDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "MakeGamePublic") == 0 )
  {
    CBaseModPanel::OnMakeGamePublic(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenBenchmarkDialog") == 0 )
  {
    CBaseModPanel::OnOpenBenchmarkDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenServerBrowser") == 0 )
  {
    CBaseModPanel::OnOpenServerBrowser(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenCreateStartScreen") == 0 )
  {
    this->HandleOpenCreateStartScreen(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenCreateSinglePlayerGameDialog") == 0
    || _V_stricmp(s1: v6, s2: "OpenCreateSinglePlayerGameDialog_AcceptNotConnectedToLive") == 0 )
  {
    this->OnOpenCreateSingleplayerGameDialog(this, a2: false);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenLeaderboardsDialog") == 0 )
  {
    this->OnOpenLeaderboardsDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenMarketplaceDialog") == 0 )
  {
    this->OnOpenMarketplace(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenUpsellDialog") == 0 )
  {
    this->OnOpenUpsellDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "PlayCreditsVideo") == 0 )
  {
    CBaseModPanel::OnPlayCreditsVideo(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "RestoreMainMenu") == 0 )
  {
    this->RestoreMainMenuScreen(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "CloseLeaderboardsDialog") == 0 )
  {
    this->CloseLeaderboardsDialog(this);
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenFriendsDialog") == 0 )
  {
    CVGuiSystemModuleLoader::ActivateModule(this: &g_VModuleLoader, moduleName: "Friends");
    return;
  }
  if ( _V_stricmp(s1: v6, s2: "OpenLoadDemoDialog") != 0 )
  {
    if ( _V_stricmp(s1: v6, s2: "OpenCreateMultiplayerGameDialog") == 0 )
    {
      this->OnOpenCreateMultiplayerGameDialog(this);
      return;
    }
    if ( _V_stricmp(s1: v6, s2: "OpenMedalsStatsDialog") == 0 )
    {
      this->OnOpenMedalsStatsDialog(this);
      return;
    }
    if ( _V_stricmp(s1: v6, s2: "CloseMedalsStatsDialog") == 0 )
    {
      this->CloseMedalsStatsDialog(this);
      return;
    }
    if ( _V_stricmp(s1: v6, s2: "OpenChangeGameDialog") == 0 )
    {
      CBaseModPanel::OnOpenChangeGameDialog(this);
      return;
    }
    if ( _V_stricmp(s1: v6, s2: "OpenLoadCommentaryDialog") == 0 )
    {
      CBaseModPanel::OnOpenLoadCommentaryDialog(this);
      return;
    }
    if ( _V_stricmp(s1: v6, s2: "OpenLoadSingleplayerCommentaryDialog") == 0 )
    {
      CBaseModPanel::OpenLoadSingleplayerCommentaryDialog(this);
      return;
    }
    if ( _V_stricmp(s1: v6, s2: "OpenHowToPlayDialog") == 0 )
    {
      this->OnOpenHowToPlayDialog(this);
      return;
    }
    if ( _V_stricmp(s1: v6, s2: "OpenAchievementsDialog") == 0 )
    {
      if ( steamapicontext->m_pSteamUser != nullptr
        && steamapicontext->m_pSteamUser->BLoggedOn(this: steamapicontext->m_pSteamUser) )
      {
        return;
      }
      v13 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v13 != nullptr )
      {
        v14 = vgui::MessageBox::MessageBox(
                this: v13,
                title: "#GameUI_Achievements_SteamRequired_Title",
                text: "#GameUI_Achievements_SteamRequired_Message",
                parent: nullptr);
LABEL_78:
        v14->DoModal_2(this: v14, a2: nullptr);
        return;
      }
      goto LABEL_79;
    }
    if ( _V_stricmp(s1: v6, s2: "OpenCSAchievementsDialog") == 0 )
    {
      if ( steamapicontext->m_pSteamUser != nullptr
        && steamapicontext->m_pSteamUser->BLoggedOn(this: steamapicontext->m_pSteamUser) )
      {
        CBaseModPanel::OnOpenCSAchievementsDialog(this);
        return;
      }
      v15 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v15 != nullptr )
      {
        v14 = vgui::MessageBox::MessageBox(
                this: v15,
                title: "#GameUI_Achievements_SteamRequired_Title",
                text: "#GameUI_Achievements_SteamRequired_Message",
                parent: this);
        goto LABEL_78;
      }
LABEL_79:
      (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
      return;
    }
    if ( _V_stricmp(s1: v6, s2: "OpenAchievementsBlade") != 0 )
    {
      if ( _V_stricmp(s1: v6, s2: "Quit") != 0 )
      {
        if ( _V_stricmp(s1: v6, s2: "QuitNoConfirm") != 0 )
        {
          if ( _V_stricmp(s1: v6, s2: "QuitRestartNoConfirm") != 0 )
          {
            if ( _V_stricmp(s1: v6, s2: "ResumeGame") != 0 )
            {
              if ( _V_stricmp(s1: v6, s2: "Disconnect") != 0 )
              {
                if ( _V_stricmp(s1: v6, s2: "DisconnectNoConfirm") != 0 )
                {
                  if ( _V_stricmp(s1: v6, s2: "ReleaseModalWindow") != 0 )
                  {
                    if ( V_stristr(a1: v20, a2, pStr: v6, pSearch: "engine ") != nullptr )
                    {
                      strstr(str1: (unsigned __int8 *)v6, str2: "engine ");
                      v22 = (const char *)(v21 + 7);
                      if ( strlen(v22) != 0 )
                        engine->ClientCmd_Unrestricted(this: engine, a2: v22);
                    }
                    else if ( _V_stricmp(s1: v6, s2: "ShowSigninUI") != 0 )
                    {
                      if ( _V_stricmp(s1: v6, s2: "ShowDeviceSelector") != 0 )
                      {
                        if ( _V_stricmp(s1: v6, s2: "SignInDenied") != 0 )
                        {
                          if ( _V_stricmp(s1: v6, s2: "RequiredSignInDenied") != 0
                            && _V_stricmp(s1: v6, s2: "RequiredStorageDenied") != 0 )
                          {
                            if ( _V_stricmp(s1: v6, s2: "StorageDeviceDenied") != 0 )
                            {
                              if ( _V_stricmp(s1: v6, s2: "clear_storage_deviceID") != 0 )
                              {
                                if ( _V_stricmp(s1: v6, s2: "RestartWithNewLanguage") != 0 )
                                {
                                  vgui::Panel::OnCommand(this, command: v6);
                                }
                                else
                                {
                                  this->SetVisible(this, a2: false);
                                  v28 = g_pVGuiSurface;
                                  v29 = g_pVGuiSurface->__vftable;
                                  v30 = ((int (__thiscall *)(CBaseModPanel *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
                                  ((void (__thiscall *)(vgui::ISurface *, int))v29->RestrictPaintToSinglePanel)(
                                    a1: v28,
                                    a2: v30);
                                  engine->ClientCmd_Unrestricted(this: engine, a2: "quit\n");
                                  _V_strcpy(dest: (char *)szSteamURL, src: "steam://run/");
                                  v31 = engine->GetAppID(this: engine);
                                  itoa(val: v31, buf: szAppId, radix: 0xAu);
                                  V_strncat(
                                    pDest: (char *)szSteamURL,
                                    pSrc: szAppId,
                                    destBufferSize: 0x32u,
                                    max_chars_to_copy: -1);
                                  V_strncat(
                                    pDest: (char *)szSteamURL,
                                    pSrc: "/",
                                    destBufferSize: 0x32u,
                                    max_chars_to_copy: -1);
                                  V_strncat(
                                    pDest: (char *)szSteamURL,
                                    pSrc: COptionsSubAudio::m_pchUpdatedAudioLanguage,
                                    destBufferSize: 0x32u,
                                    max_chars_to_copy: -1);
                                  if ( RegOpenKeyExA(
                                         hKey: HKEY_CURRENT_USER,
                                         lpSubKey: "Software\\Valve\\Source",
                                         ulOptions: 0,
                                         samDesired: 0x20006u,
                                         phkResult: &command) == 0 )
                                  {
                                    RegSetValueExA(
                                      hKey: command,
                                      lpValueName: "Relaunch URL",
                                      Reserved: 0,
                                      dwType: 1u,
                                      lpData: szSteamURL,
                                      cbData: 0x32u);
                                    RegCloseKey(hKey: command);
                                  }
                                }
                              }
                              else
                              {
                                C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v27);
                              }
                            }
                            else
                            {
                              this->m_bUserRefusedStorageDevice = true;
                              CBaseModPanel::IssuePostPromptCommand(this);
                              C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v25);
                              m_pStorageDeviceValidatedNotify = this->m_pStorageDeviceValidatedNotify;
                              this->m_iStorageID = -1;
                              if ( m_pStorageDeviceValidatedNotify != nullptr )
                              {
                                *m_pStorageDeviceValidatedNotify = 2;
                                this->m_pStorageDeviceValidatedNotify = nullptr;
                              }
                            }
                          }
                          else
                          {
                            CUtlString::operator=(this: &this->m_strPostPromptCommand, src: prType);
                          }
                        }
                        else
                        {
                          this->m_bUserRefusedSignIn = true;
                          if ( CUtlString::Length(this: &this->m_strPostPromptCommand) != 0 )
                          {
                            v23 = this->__vftable;
                            v24 = CUtlString::operator char const *(this: &this->m_strPostPromptCommand);
                            v23->OnCommand(this, a2: v24);
                          }
                        }
                      }
                      else
                      {
                        CBaseModPanel::OnChangeStorageDevice(this);
                      }
                    }
                    else
                    {
                      this->m_bWaitingForUserSignIn = true;
                      xboxsystem->ShowSigninUI(this: xboxsystem, a2: 1u, a3: 0);
                    }
                  }
                  else
                  {
                    g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
                    if ( this->IsScaleformMainMenuActive(this) || this->IsScaleformPauseMenuActive(this) )
                    {
                      CMessageDialogHandler::CloseAllMessageDialogs(this: &this->m_MessageDialogHandler);
                      CBaseModPanel::NotifyVguiDialogClosed(this);
                    }
                  }
                }
                else
                {
                  engine->ClientCmd_Unrestricted(this: engine, a2: "disconnect");
                  ConVarRef::ConVarRef(this: &commentary, pName: "commentary");
                }
              }
              else
              {
                engine->ClientCmd_Unrestricted(this: engine, a2: "disconnect");
              }
            }
            else
            {
              v19 = GameUI();
              CGameUI::HideGameUI(this: v19);
            }
          }
        }
        else
        {
          this->SetVisible(this, a2: false);
          v16 = g_pVGuiSurface;
          v17 = g_pVGuiSurface->__vftable;
          v18 = ((int (__thiscall *)(CBaseModPanel *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
          ((void (__thiscall *)(vgui::ISurface *, int))v17->RestrictPaintToSinglePanel)(a1: v16, a2: v18);
          engine->ClientCmd_Unrestricted(this: engine, a2: "quit\n");
        }
      }
      else
      {
        this->OnOpenQuitConfirmationDialog(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FAF00
// Name: public: void CBaseModPanel::ShowMessageDialog(unsigned int,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::ShowMessageDialog(CBaseModPanel *this, unsigned int nType, CBaseModPanel *pOwner)
{
  CBaseModPanel *v3; // eax

  v3 = pOwner;
  if ( pOwner == nullptr )
    v3 = this;
  CMessageDialogHandler::ShowMessageDialog(this: &this->m_MessageDialogHandler, nType, pOwner: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101FB040
// Name: public: static void CBaseModPanel::PanelMessageFunc_OnActivateModule::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseModPanel::PanelMessageFunc_OnActivateModule::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseModPanel::PanelMessageFunc_OnActivateModule::InitVar'::`2'::bAdded )
  {
    `CBaseModPanel::PanelMessageFunc_OnActivateModule::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseModPanel::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseModPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ActivateModule";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "moduleIndex";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB0E0
// Name: public: static void CBaseModPanel::PanelMessageFunc_RunEngineCommand::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseModPanel::PanelMessageFunc_RunEngineCommand::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseModPanel::PanelMessageFunc_RunEngineCommand::InitVar'::`2'::bAdded )
  {
    `CBaseModPanel::PanelMessageFunc_RunEngineCommand::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseModPanel::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseModPanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RunEngineCommand";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB180
// Name: public: static void CBaseModPanel::PanelMessageFunc_RunMenuCommand::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseModPanel::PanelMessageFunc_RunMenuCommand::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseModPanel::PanelMessageFunc_RunMenuCommand::InitVar'::`2'::bAdded )
  {
    `CBaseModPanel::PanelMessageFunc_RunMenuCommand::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseModPanel::`vcall'{1008,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseModPanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RunMenuCommand";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB220
// Name: public: static void CBaseModPanel::PanelMessageFunc_RunSlottedMenuCommand::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseModPanel::PanelMessageFunc_RunSlottedMenuCommand::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseModPanel::PanelMessageFunc_RunSlottedMenuCommand::InitVar'::`2'::bAdded )
  {
    `CBaseModPanel::PanelMessageFunc_RunSlottedMenuCommand::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseModPanel::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseModPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x200000002LL;
    memset(&v4.m[3][1], 0, 12);
    LODWORD(v4.m[0][0]) = "RunSlottedMenuCommand";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][2]) = "slot";
    LODWORD(v4.m[2][3]) = 1;
    LODWORD(v4.m[3][0]) = "command";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB2C0
// Name: public: static void CBaseModPanel::PanelMessageFunc_FinishDialogClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseModPanel::PanelMessageFunc_FinishDialogClose::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseModPanel::PanelMessageFunc_FinishDialogClose::InitVar'::`2'::bAdded )
  {
    `CBaseModPanel::PanelMessageFunc_FinishDialogClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseModPanel::`vcall'{1016,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseModPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FinishDialogClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB350
// Name: public: static void CGameMenu::PanelMessageFunc_OnCursorEnteredMenuItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGameMenu::PanelMessageFunc_OnCursorEnteredMenuItem::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CGameMenu::PanelMessageFunc_OnCursorEnteredMenuItem::InitVar'::`2'::bAdded )
  {
    `CGameMenu::PanelMessageFunc_OnCursorEnteredMenuItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1064,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CGameMenu");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CursorEnteredMenuItem";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "VPanel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB3F0
// Name: protected: virtual void CBaseModPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::ApplySchemeSettings(CBaseModPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // esi
  const char *v4; // eax
  vgui::ISchemeManager_vtbl *v5; // edi
  unsigned int v6; // eax
  int v7; // edi
  int v8; // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBaseModPanel::coord *m_pMemory; // edx
  int v12; // ecx
  CBaseModPanel::coord *v13; // eax
  CFmtStrN<256> *v14; // eax
  int v15; // edx
  const char *v16; // eax
  int v17; // eax
  int (__thiscall *GetProportionalScaledValue)(vgui::ISchemeManager *, int); // edx
  int v19; // eax
  CFmtStrN<256> *v20; // eax
  int v21; // edx
  const char *v22; // eax
  int v23; // eax
  int (__thiscall *v24)(vgui::ISchemeManager *, int); // edx
  int v25; // eax
  CGameUI *v26; // eax
  CFmtStrN<256> *v27; // eax
  int v28; // eax
  int v29; // ecx
  Color *v30; // edx
  int v31; // eax
  int *v32; // ecx
  const char *v33; // eax
  int v34; // eax
  const char *v35; // eax
  int v36; // eax
  const char *v37; // eax
  int v38; // eax
  CBackgroundMenuButton *v39; // esi
  CBackgroundMenuButton_vtbl *v40; // edi
  unsigned int v41; // eax
  int v42; // eax
  int v43; // esi
  Color *v44; // edi
  int v45; // eax
  int *v46; // esi
  int v47; // edi
  CBackgroundMenuButton *v48; // ecx
  CBackgroundMenuButton *v49; // ecx
  Color *v50; // esi
  CBackgroundMenuButton *v51; // ecx
  const char *v52; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // eax
  const char *v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // [esp-4h] [ebp-260h]
  char filename[260]; // [esp+Ch] [ebp-250h] BYREF
  CFmtStrN<256> v60; // [esp+110h] [ebp-14Ch] BYREF
  char v61[4]; // [esp+21Ch] [ebp-40h] BYREF
  CBaseModPanel::coord v62; // [esp+220h] [ebp-3Ch]
  int screenTall; // [esp+228h] [ebp-34h] BYREF
  int screenWide; // [esp+22Ch] [ebp-30h] BYREF
  CUtlVector<Color,CUtlMemory<Color,int> > buttonColor; // [esp+230h] [ebp-2Ch] BYREF
  CBaseModPanel::coord *v66; // [esp+244h] [ebp-18h]
  int i; // [esp+248h] [ebp-14h]
  int v68; // [esp+24Ch] [ebp-10h]
  CBaseModPanel::coord *v69; // [esp+250h] [ebp-Ch]
  unsigned int v70; // [esp+254h] [ebp-8h]
  int v71; // [esp+258h] [ebp-4h]

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = v2->GetResourceString(this: v2, a2: "MainMenu.Inset");
  this->m_iGameMenuInset = 2 * atoi(nptr: v4);
  v5 = g_pVGuiSchemeManager->__vftable;
  i = (int)g_pVGuiSchemeManager;
  v6 = g_pVGuiSchemeManager->GetScheme(this: g_pVGuiSchemeManager, a2: "ClientScheme");
  v7 = (int)v5->GetIScheme(this: (vgui::ISchemeManager *)i, a2: v6);
  memset(&buttonColor, 0, sizeof(buttonColor));
  if ( v7 != 0 )
  {
    this->m_iGameTitlePos.m_Size = 0;
    if ( this->m_pGameMenuButtons.m_Size > 0 )
    {
      v71 = -1;
      v68 = 1;
      v70 = 0;
      i = 0;
      do
      {
        v69 = *(CBaseModPanel::coord **)((char *)this->m_pGameMenuButtons.m_Memory.m_pMemory + i);
        v66 = (CBaseModPanel::coord *)(v69->x + 896);
        v8 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v7 + 12))(a1: v7, a2: "ClientTitleFont", a3: 1);
        ((void (__thiscall *)(CBaseModPanel::coord *, int))v66->x)(a1: v69, a2: v8);
        m_Size = this->m_iGameTitlePos.m_Size;
        m_nAllocationCount = this->m_iGameTitlePos.m_Memory.m_nAllocationCount;
        v62 = 0;
        v69 = (CBaseModPanel::coord *)m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
            this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_iGameTitlePos,
            num: m_Size - m_nAllocationCount + 1);
          m_Size = (int)v69;
        }
        ++this->m_iGameTitlePos.m_Size;
        m_pMemory = this->m_iGameTitlePos.m_Memory.m_pMemory;
        v12 = this->m_iGameTitlePos.m_Size - m_Size - 1;
        this->m_iGameTitlePos.m_pElements = m_pMemory;
        if ( v12 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 8 * v12);
          m_Size = (int)v69;
        }
        v13 = &this->m_iGameTitlePos.m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = v62;
        v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v60, pszFormat: "Main.Title%d.X", v68);
        v15 = *(_DWORD *)v7;
        v66 = &this->m_iGameTitlePos.m_Memory.m_pMemory[v70 / 8];
        v16 = (const char *)(*(int (__thiscall **)(int, char *))(v15 + 4))(a1: v7, a2: v14->m_szBuf);
        v17 = atoi(nptr: v16);
        v66->x = v17;
        GetProportionalScaledValue = g_pVGuiSchemeManager->GetProportionalScaledValue;
        v69 = &this->m_iGameTitlePos.m_Memory.m_pMemory[v70 / 8];
        v19 = GetProportionalScaledValue(this: g_pVGuiSchemeManager, a2: v69->x);
        v58 = v68;
        v69->x = v19;
        v20 = CFmtStrN<256>::CFmtStrN<256>(this: &v60, pszFormat: "Main.Title%d.Y", v58);
        v21 = *(_DWORD *)v7;
        v66 = &this->m_iGameTitlePos.m_Memory.m_pMemory[v70 / 8];
        v22 = (const char *)(*(int (__thiscall **)(int, char *))(v21 + 4))(a1: v7, a2: v20->m_szBuf);
        v23 = atoi(nptr: v22);
        v66->y = v23;
        v24 = g_pVGuiSchemeManager->GetProportionalScaledValue;
        v69 = &this->m_iGameTitlePos.m_Memory.m_pMemory[v70 / 8];
        v25 = v24(this: g_pVGuiSchemeManager, a2: v69->y);
        v69->y = v25;
        v26 = GameUI();
        if ( CGameUI::IsConsoleUI(this: v26) )
          this->m_iGameTitlePos.m_Memory.m_pMemory[v70 / 8].x += 10;
        v27 = CFmtStrN<256>::CFmtStrN<256>(this: &v60, pszFormat: "Main.Title%d.Color", v68);
        v66 = (CBaseModPanel::coord *)(*(int (__thiscall **)(int, char *, char *, int))(*(_DWORD *)v7 + 20))(
                                        a1: v7,
                                        a2: v61,
                                        a3: v27->m_szBuf,
                                        a4: v71);
        v28 = buttonColor.m_Size;
        v29 = buttonColor.m_Size;
        v69 = (CBaseModPanel::coord *)buttonColor.m_Size;
        if ( buttonColor.m_Size + 1 > buttonColor.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&buttonColor,
            num: buttonColor.m_Size - buttonColor.m_Memory.m_nAllocationCount + 1);
          v28 = buttonColor.m_Size;
          v29 = (int)v69;
        }
        v30 = buttonColor.m_Memory.m_pMemory;
        buttonColor.m_Size = v28 + 1;
        v31 = v28 - v29;
        buttonColor.m_pElements = buttonColor.m_Memory.m_pMemory;
        if ( v31 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&buttonColor.m_Memory.m_pMemory[v29 + 1],
            src: (unsigned __int8 *)&buttonColor.m_Memory.m_pMemory[v29],
            count: 4 * v31);
          v29 = (int)v69;
          v30 = buttonColor.m_Memory.m_pMemory;
        }
        v32 = (int *)&v30[v29];
        if ( v32 != nullptr )
          *v32 = v66->x;
        i += 4;
        v70 += 8;
        ++v68;
      }
      while ( v68 - 1 < this->m_pGameMenuButtons.m_Size );
    }
    v33 = (const char *)(*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: "Main.Menu.X");
    v34 = atoi(nptr: v33);
    this->m_iGameMenuPos.x = v34;
    this->m_iGameMenuPos.x = g_pVGuiSchemeManager->GetProportionalScaledValue(this: g_pVGuiSchemeManager, a2: v34);
    v35 = (const char *)(*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: "Main.Menu.Y");
    v36 = atoi(nptr: v35);
    this->m_iGameMenuPos.y = v36;
    this->m_iGameMenuPos.y = g_pVGuiSchemeManager->GetProportionalScaledValue(this: g_pVGuiSchemeManager, a2: v36);
    v37 = (const char *)(*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: "Main.BottomBorder");
    v38 = atoi(nptr: v37);
    this->m_iGameMenuInset = v38;
    this->m_iGameMenuInset = g_pVGuiSchemeManager->GetProportionalScaledValue(this: g_pVGuiSchemeManager, a2: v38);
  }
  else
  {
    i = 0;
    if ( this->m_pGameMenuButtons.m_Size > 0 )
    {
      v71 = -1;
      do
      {
        v39 = this->m_pGameMenuButtons.m_Memory.m_pMemory[i];
        v40 = v39->__vftable;
        v41 = pScheme->GetFont(this: pScheme, a2: "TitleFont", a3: false);
        v40->SetFont(this: v39, a2: v41);
        v42 = buttonColor.m_Size;
        v43 = buttonColor.m_Size;
        if ( buttonColor.m_Size + 1 > buttonColor.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&buttonColor,
            num: buttonColor.m_Size - buttonColor.m_Memory.m_nAllocationCount + 1);
          v42 = buttonColor.m_Size;
        }
        v44 = buttonColor.m_Memory.m_pMemory;
        buttonColor.m_Size = v42 + 1;
        v45 = v42 - v43;
        buttonColor.m_pElements = buttonColor.m_Memory.m_pMemory;
        if ( v45 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&buttonColor.m_Memory.m_pMemory[v43 + 1],
            src: (unsigned __int8 *)&buttonColor.m_Memory.m_pMemory[v43],
            count: 4 * v45);
        v46 = (int *)&v44[v43];
        if ( v46 != nullptr )
          *v46 = v71;
        ++i;
      }
      while ( i < this->m_pGameMenuButtons.m_Size );
      v2 = pScheme;
    }
  }
  v47 = 0;
  if ( this->m_pGameMenuButtons.m_Size > 0 )
  {
    v71 = 0;
    v68 = 0;
    v70 = 0;
    do
    {
      v48 = this->m_pGameMenuButtons.m_Memory.m_pMemory[v47];
      ((void (__thiscall *)(CBackgroundMenuButton *, _DWORD, int))v48->SetDefaultColor)(
        a1: v48,
        a2: *(_DWORD *)&buttonColor.m_Memory.m_pMemory[v47],
        a3: v71);
      v49 = this->m_pGameMenuButtons.m_Memory.m_pMemory[v47];
      v50 = buttonColor.m_Memory.m_pMemory;
      ((void (__thiscall *)(CBackgroundMenuButton *, _DWORD, int))v49->SetArmedColor)(
        a1: v49,
        a2: *(_DWORD *)&buttonColor.m_Memory.m_pMemory[v47],
        a3: v68);
      v51 = this->m_pGameMenuButtons.m_Memory.m_pMemory[v47];
      ((void (__thiscall *)(CBackgroundMenuButton *, _DWORD, unsigned int))v51->SetDepressedColor)(
        a1: v51,
        a2: *(_DWORD *)&v50[v47++],
        a3: v70);
    }
    while ( v47 < this->m_pGameMenuButtons.m_Size );
    v2 = pScheme;
  }
  v52 = v2->GetResourceString(this: v2, a2: "Frame.TransitionEffectTime");
  this->m_flFrameFadeInTime = atof(nptr: v52);
  SetBgColor = this->SetBgColor;
  pScheme = nullptr;
  ((void (__thiscall *)(CBaseModPanel *, _DWORD))SetBgColor)(a1: this, a2: 0);
  GetColor = v2->GetColor;
  pScheme = (vgui::IScheme *)0x80000000;
  this->m_BackdropColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, unsigned int))GetColor)(
                                      a1: v2,
                                      a2: &pScheme,
                                      a3: "mainmenu.backdrop",
                                      a4: 0x80000000);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenWide, a3: &screenTall);
  HIBYTE(pScheme) = (float)((float)screenWide / (float)screenTall) >= 1.5999;
  engine->GetMainMenuBackgroundName(this: engine, a2: &v60.m_szBuf[3], a3: 260);
  v55 = "_widescreen";
  if ( HIBYTE(pScheme) == 0 )
    v55 = prType;
  V_snprintf(pDest: filename, maxLen: 0x104u, pFormat: "console/%s%s", &v60.m_szBuf[3], v55);
  v56 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  this->m_iBackgroundImageID = v56;
  g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v56, a3: filename, a4: 0, a5: false);
  v57 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  this->m_iLoadingImageID = v57;
  g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v57, a3: "console/startup_loading", a4: 0, a5: false);
  CBaseModPanel::LoadVersionNumbers(this);
  if ( buttonColor.m_Memory.m_nGrowSize >= 0 && buttonColor.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buttonColor.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101FBA10
// Name: public: virtual void CBaseModPanel::OnGameUIActivated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnGameUIActivated(CBaseModPanel *this)
{
  CGameUI *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  void (__thiscall *RunMenuCommand)(CBaseModPanel *, const char *); // edx
  void (__thiscall *OnOpenCreateStartScreen)(CBaseModPanel *); // edx
  CGameUI *v7; // eax
  CGameUI *v8; // eax
  bool v9; // al
  CBaseModPanel_vtbl *v10; // edx

  if ( engine->MapLoadFailed(this: engine) )
  {
    engine->SetMapLoadFailed(this: engine, a2: false);
    CMessageDialogHandler::ShowMessageDialog(this: &this->m_MessageDialogHandler, nType: 43, pOwner: this);
  }
  if ( !this->m_bEverActivated )
  {
    CBaseModPanel::UpdateGameMenus(this);
    this->m_bEverActivated = true;
    v2 = GameUI();
    if ( CGameUI::IsConsoleUI(this: v2) )
    {
      v3 = engine->GetGameDirectory(this: engine);
      v4 = V_UnqualifiedFileName(in: v3);
      if ( _V_stricmp(s1: v4, s2: "tf") == 0 )
      {
        RunMenuCommand = this->RunMenuCommand;
        this->m_bUseMatchmaking = true;
        RunMenuCommand(this, a2: "OpenMatchmakingBasePanel");
      }
    }
  }
  if ( this->m_bShowStartScreen )
  {
    CBaseModPanel::ShowMainMenu(this, bShow: false);
    this->UnlockInput(this);
    OnOpenCreateStartScreen = this->OnOpenCreateStartScreen;
    this->m_bStartScreenPlayerSigninCompleted = false;
    OnOpenCreateStartScreen(this);
  }
  else
  {
    v7 = GameUI();
    if ( CGameUI::IsConsoleUI(this: v7) )
      CBaseModPanel::ArmFirstMenuItem(this);
  }
  v8 = GameUI();
  v9 = v8->IsInLevel(this: v8);
  v10 = this->__vftable;
  if ( v9 )
  {
    if ( this->m_bUseMatchmaking )
    {
      ((void (__stdcall *)(const char *))v10->RunMenuCommand)(a1: "OpenMatchmakingBasePanel");
    }
    else if ( this->m_bScaleformPauseMenuEnabled )
    {
      ((void (__fastcall *)(CBaseModPanel *))v10->OnOpenPauseMenu)(a1: this);
    }
    else
    {
      ((void (__stdcall *)(const char *))v10->OnCommand)(a1: "OpenPauseMenu");
    }
  }
  else if ( v10->IsScaleformPauseMenuActive(this) )
  {
    this->DismissPauseMenu(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBB70
// Name: public: virtual void CBaseModPanel::OnOpenQuitConfirmationDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseModPanel::OnOpenQuitConfirmationDialog(CBaseModPanel *this@<ecx>, int a2@<esi>)
{
  CGameUI *v3; // eax
  CGameUI *v4; // eax
  CGameUI *v5; // eax
  CMessageDialogHandler *p_m_MessageDialogHandler; // ecx
  CGameUI *v7; // eax
  CSaveBeforeQuitQueryDialog *v8; // eax
  CSaveBeforeQuitQueryDialog *Dialog; // eax
  CQuitQueryBox *v10; // eax
  CQuitQueryBox *Box; // esi
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax

  v3 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v3) )
  {
    v4 = GameUI();
    if ( !CGameUI::HasSavedThisMenuSession(this: v4)
      && (v5 = GameUI(), v5->IsInLevel(this: v5))
      && engine->GetMaxClients(this: engine) == 1 )
    {
      CMessageDialogHandler::ShowMessageDialog(this: &this->m_MessageDialogHandler, nType: 0, pOwner: this);
    }
    else
    {
      p_m_MessageDialogHandler = &this->m_MessageDialogHandler;
      if ( this->m_bUseMatchmaking )
        CMessageDialogHandler::ShowMessageDialog(this: p_m_MessageDialogHandler, nType: 2, pOwner: this);
      else
        CMessageDialogHandler::ShowMessageDialog(this: p_m_MessageDialogHandler, nType: 1, pOwner: this);
    }
  }
  else
  {
    v7 = GameUI();
    if ( v7->IsInLevel(this: v7) && engine->GetMaxClients(this: engine) == 1 )
    {
      v8 = (CSaveBeforeQuitQueryDialog *)MemAlloc_Alloc(nSize: 0x214u);
      if ( v8 != nullptr )
        Dialog = CSaveBeforeQuitQueryDialog::CSaveBeforeQuitQueryDialog(
                   this: v8,
                   parent: this,
                   name: "SaveBeforeQuitQueryDialog");
      else
        Dialog = nullptr;
      Dialog->DoModal(this: Dialog);
    }
    else
    {
      v10 = (CQuitQueryBox *)MemAlloc_Alloc(nSize: 0x248u);
      if ( v10 != nullptr )
        Box = CQuitQueryBox::CQuitQueryBox(
                this: v10,
                title: "#GameUI_QuitConfirmationTitle",
                info: "#GameUI_QuitConfirmationText",
                parent: this);
      else
        Box = nullptr;
      ((void (__thiscall *)(CQuitQueryBox *, const char *, int))Box->SetOKButtonText_2)(
        a1: Box,
        a2: "#GameUI_Quit",
        a3: a2);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v13 = KeyValues::KeyValues(this: v12, setName: "Command", firstKey: "command", firstValue: "QuitNoConfirm");
      else
        v13 = nullptr;
      vgui::QueryBox::SetOKCommand(this: Box, keyValues: v13);
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "Command", firstKey: "command", firstValue: "ReleaseModalWindow");
      else
        v15 = nullptr;
      vgui::QueryBox::SetCancelCommand(this: Box, keyValues: v15);
      Box->AddActionSignalTarget_2(this: Box, a2: this);
      Box->DoModal_2(this: Box, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBD00
// Name: public: virtual void CBaseModPanel::OnOpenDisconnectConfirmationDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::OnOpenDisconnectConfirmationDialog(CBaseModPanel *this)
{
  CGameUI *v2; // eax
  CGameUI *v3; // eax
  int v4; // eax
  CMessageDialogHandler *p_m_MessageDialogHandler; // ecx

  v2 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v2) )
  {
    v3 = GameUI();
    if ( v3->IsInLevel(this: v3) )
    {
      v4 = engine->GetLocalPlayer(this: engine);
      p_m_MessageDialogHandler = &this->m_MessageDialogHandler;
      if ( v4 == 1 )
        CMessageDialogHandler::ShowMessageDialog(this: p_m_MessageDialogHandler, nType: 42, pOwner: this);
      else
        CMessageDialogHandler::ShowMessageDialog(this: p_m_MessageDialogHandler, nType: 41, pOwner: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBD50
// Name: public: CGameMenu::CGameMenu(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameMenu *__thiscall CGameMenu::CGameMenu(CGameMenu *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CGameUI *v7; // eax
  vgui::CFooterPanel *v8; // eax
  vgui::CFooterPanel *v9; // eax

  vgui::Menu::Menu(this, parent, panelName: name);
  this->__vftable = (CGameMenu_vtbl *)&CGameMenu::`vftable';
  if ( `CGameMenu::ChainToMap'::`2'::chained == 0 )
  {
    `CGameMenu::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CGameMenu");
    v4->pfnClassName = CGameMenu::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Menu");
  }
  if ( `CGameMenu::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CGameMenu::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CGameMenu");
    v5->pfnClassName = CGameMenu::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Menu");
  }
  if ( `CGameMenu::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CGameMenu::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CGameMenu");
    v6->pfnClassName = CGameMenu::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Menu");
  }
  CGameMenu::PanelMessageFunc_OnCursorEnteredMenuItem::InitVar();
  v7 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v7) )
  {
    v8 = (vgui::CFooterPanel *)MemAlloc_Alloc(nSize: 0x2C4u);
    if ( v8 != nullptr )
      v9 = vgui::CFooterPanel::CFooterPanel(this: v8, parent, panelName: "MainMenuFooter");
    else
      v9 = nullptr;
    this->m_pConsoleFooter = v9;
    vgui::Menu::SetFixedWidth(this, width: 245);
    return this;
  }
  else
  {
    this->m_pConsoleFooter = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBE70
// Name: public: virtual void CGameMenu::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenu::SetVisible(CGameMenu *this, bool state)
{
  vgui::IPanel *v3; // esi
  vgui::IPanel_vtbl *v4; // ebx
  int v5; // eax

  vgui::Menu::SetVisible(this, state: 1);
  if ( !state )
  {
    v3 = g_pVGuiPanel;
    v4 = g_pVGuiPanel->__vftable;
    v5 = this->GetVPanel(this);
    v4->MoveToBack(this: v3, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBEB0
// Name: public: virtual void CGameMenu::SetMenuItemBlinkingState(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenu::SetMenuItemBlinkingState(CGameMenu *this, const char *itemName, int state)
{
  int i; // ebx
  vgui::Panel *Child; // eax
  void *v6; // eax
  void *v7; // esi
  KeyValues *v8; // eax
  char *String; // eax

  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::MenuItem `RTTI Type Descriptor',
           isReference: 0);
    v7 = v6;
    if ( v6 != nullptr )
    {
      v8 = (KeyValues *)(*(int (__thiscall **)(void *))(*(_DWORD *)v6 + 1128))(a1: v6);
      String = KeyValues::GetString(this: v8, keyName: "command", defaultValue: prType);
      if ( _V_strcmp(s1: String, s2: itemName) == 0 )
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)v7 + 1028))(a1: v7, a2: state);
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101FBF50
// Name: public: virtual void CGameMenu::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenu::OnCommand(CGameMenu *this, char *command)
{
  if ( _V_stricmp(s1: command, s2: "Open") != 0 )
  {
    vgui::Menu::OnCommand(this, command);
  }
  else
  {
    this->MoveToFront(this);
    this->RequestFocus(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBFA0
// Name: public: virtual void CGameMenu::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenu::OnKeyCodePressed(CGameMenu *this, ButtonCode_t code)
{
  char *v2; // eax
  char szCommand[256]; // [esp+4h] [ebp-100h] BYREF

  vgui::Menu::OnKeyCodePressed(this, code);
  if ( (unsigned int)(code - 92) <= 0xB )
  {
    v2 = (char *)gameuifuncs->GetBindingForButtonCode(this: gameuifuncs, a2: code);
    if ( v2 != nullptr && *v2 != 0 )
    {
      V_strncpy(pDest: szCommand, pSrc: v2, maxLen: 256);
      engine->ClientCmd_Unrestricted(this: engine, a2: szCommand);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FC010
// Name: public: virtual void CGameMenu::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenu::OnKillFocus(CGameMenu *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  int v4; // eax

  vgui::Menu::OnKillFocus(this);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = this->GetVPanel(this);
  v3->MovePopupToBack(this: v2, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101FC040
// Name: public: virtual struct vgui::PanelMessageMap __near * CGameMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CGameMenu::GetMessageMap(CGameMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CGameMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameMenu::GetMessageMap'::`2'::s_pMap;
  `CGameMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CGameMenu");
  `CGameMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FC070
// Name: public: virtual struct PanelAnimationMap __near * CGameMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CGameMenu::GetAnimMap(CGameMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CGameMenu");
}

//------------------------------------------------------------------------------
// Address: 0x101FC080
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CGameMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CGameMenu::GetKBMap(CGameMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CGameMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameMenu::GetKBMap'::`2'::s_pMap;
  `CGameMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CGameMenu");
  `CGameMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FC0B0
// Name: public: virtual void CGameMenu::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameMenu::ApplySchemeSettings(CGameMenu *this, vgui::IScheme *pScheme)
{
  CGameMenu_vtbl *v3; // ebx
  const char *v4; // eax
  int v5; // eax

  vgui::Menu::ApplySchemeSettings(this, (int)pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetResourceString(this: pScheme, a2: "MainMenu.MenuItemHeight");
  v5 = atoi(nptr: v4);
  v3->SetMenuItemHeight(this, a2: v5);
  ((void (__thiscall *)(CGameMenu *, _DWORD))this->SetBgColor)(a1: this, a2: 0);
  this->SetBorder(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101FC110
// Name: public: virtual int CGameMenu::AddMenuItem(char const __near *,char const __near *,char const __near *,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMenu::AddMenuItem(
        CGameMenu *this,
        const char *itemName,
        const char *itemText,
        const char *command,
        vgui::Panel *target,
        KeyValues *userData)
{
  CGameMenuItem *v7; // eax
  CGameMenuItem *v8; // esi

  v7 = (CGameMenuItem *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v7 != nullptr )
    v8 = CGameMenuItem::CGameMenuItem(this: v7, a2: (vgui::PanelMessageMap *)this, parent: this, name: itemName);
  else
    v8 = nullptr;
  v8->AddActionSignalTarget_2(this: v8, a2: target);
  v8->SetCommand(this: v8, a2: command);
  v8->SetText(this: v8, a2: itemText);
  vgui::MenuItem::SetUserData(this: v8, kv: userData);
  return vgui::Menu::AddMenuItem(this, panel: v8);
}

//------------------------------------------------------------------------------
// Address: 0x101FC190
// Name: public: virtual int CGameMenu::AddMenuItem(char const __near *,char const __near *,class KeyValues __near *,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameMenu::AddMenuItem(
        CGameMenu *this,
        const char *itemName,
        const char *itemText,
        KeyValues *command,
        vgui::Panel *target,
        KeyValues *userData)
{
  CGameMenuItem *v7; // eax
  CGameMenuItem *v8; // esi

  v7 = (CGameMenuItem *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v7 != nullptr )
    v8 = CGameMenuItem::CGameMenuItem(this: v7, a2: (vgui::PanelMessageMap *)this, parent: this, name: itemName);
  else
    v8 = nullptr;
  v8->AddActionSignalTarget_2(this: v8, a2: target);
  v8->SetCommand(this: v8, a2: command);
  v8->SetText(this: v8, a2: itemText);
  v8->m_bRightAligned = true;
  vgui::MenuItem::SetUserData(this: v8, kv: userData);
  return vgui::Menu::AddMenuItem(this, panel: v8);
}

//------------------------------------------------------------------------------
// Address: 0x101FC210
// Name: private: class CGameMenu __near * CBaseModPanel::RecursiveLoadGameMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CGameMenu *__thiscall CBaseModPanel::RecursiveLoadGameMenu(CBaseModPanel *this, KeyValues *datafile)
{
  CGameMenu *v4; // esi
  const char *v5; // eax
  KeyValues *i; // esi
  char *String; // ebx
  char *v8; // edi
  char *name; // [esp+Ch] [ebp-8h]
  CGameMenu *menu; // [esp+1Ch] [ebp+8h]

  v4 = (CGameMenu *)MemAlloc_Alloc(nSize: 0x428u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::GetName(this: datafile);
    menu = CGameMenu::CGameMenu(this: v4, parent: this, name: v5);
  }
  else
  {
    menu = nullptr;
  }
  for ( i = KeyValues::GetFirstSubKey(this: datafile); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    String = KeyValues::GetString(this: i, keyName: "label", defaultValue: "<unknown>");
    v8 = KeyValues::GetString(this: i, keyName: "command", defaultValue: nullptr);
    name = KeyValues::GetString(this: i, keyName: "name", defaultValue: String);
    if ( v8 == nullptr || _V_stricmp(s1: v8, s2: "OpenFriendsDialog") != 0 || !bSteamCommunityFriendsVersion )
      menu->AddMenuItem(this: menu, a2: name, a3: String, a4: v8, a5: this, a6: i);
  }
  return menu;
}

//------------------------------------------------------------------------------
// Address: 0x101FC2F0
// Name: public: virtual CBaseModPanel::~CBaseModPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::~CBaseModPanel(CBaseModPanel *this)
{
  this->__vftable = (CBaseModPanel_vtbl *)&CBaseModPanel::`vftable';
  g_pBasePanel = nullptr;
  this->m_strPostPromptCommand.m_Storage.m_nActualLength = 0;
  if ( this->m_strPostPromptCommand.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_strPostPromptCommand.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_strPostPromptCommand.m_Storage.m_Memory.m_pMemory);
      this->m_strPostPromptCommand.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_strPostPromptCommand.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_CommandQueue);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_iGameTitlePos);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_pGameMenuButtons);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FC360
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseModPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseModPanel::GetMessageMap(CBaseModPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseModPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseModPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseModPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseModPanel");
  `CBaseModPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FC390
// Name: public: virtual struct PanelAnimationMap __near * CBaseModPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseModPanel::GetAnimMap(CBaseModPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseModPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101FC3A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseModPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseModPanel::GetKBMap(CBaseModPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseModPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseModPanel::GetKBMap'::`2'::s_pMap;
  `CBaseModPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseModPanel");
  `CBaseModPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FC3D0
// Name: CC_GameMenuCompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl CC_GameMenuCompletionFunc(char *partial, char (*commands)[64])
{
  char *v2; // esi
  const char **v3; // ebx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // dx
  unsigned __int16 v6; // cx
  int v7; // esi
  UtlRBTreeNode_t<CUtlString,unsigned short> *m_pMemory; // eax
  int v9; // esi
  int v10; // edx
  int v11; // ebx
  int v12; // esi
  char *v13; // edi
  const char *v14; // eax
  char buf[512]; // [esp+Ch] [ebp-238h] BYREF
  int checklen; // [esp+20Ch] [ebp-38h]
  CUtlString str; // [esp+210h] [ebp-34h] BYREF
  unsigned __int16 parent[2]; // [esp+220h] [ebp-24h] BYREF
  CUtlRBTree<CUtlString,unsigned short,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short> > symbols; // [esp+224h] [ebp-20h] BYREF
  char *substring; // [esp+240h] [ebp-4h]

  v2 = partial;
  substring = partial;
  if ( _V_strstr(s1: partial, search: "gamemenucommand") != nullptr )
    substring = v2 + 16;
  checklen = _V_strlen(str: substring);
  symbols.m_LessFunc = UtlStringLessFunc;
  memset(&symbols.m_Elements, 0, sizeof(symbols.m_Elements));
  *(_DWORD *)&symbols.m_Root = 0xFFFF;
  *(_DWORD *)&symbols.m_FirstFree = -1;
  symbols.m_pElements = nullptr;
  v3 = (const char **)g_rgValidCommands;
  while ( V_strnicmp(s1: *v3, s2: substring, n: checklen) != 0 )
  {
LABEL_17:
    if ( (int)++v3 >= (int)&vec2_invalid_80 )
      goto LABEL_22;
  }
  CUtlString::CUtlString(this: &str);
  CUtlString::operator=(this: &str, src: *v3);
  *(_DWORD *)parent = 0xFFFF;
  HIBYTE(partial) = 0;
  CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: &symbols,
    insert: &str,
    parent,
    leftchild: (bool *)&partial + 3);
  v4 = CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::NewNode(this: &symbols);
  v5 = parent[0];
  v6 = v4;
  v7 = 3 * v4;
  m_pMemory = symbols.m_Elements.m_pMemory;
  v9 = 8 * v7;
  *(unsigned __int16 *)((char *)&symbols.m_Elements.m_pMemory->m_Right + v9) = -1;
  *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v9) = -1;
  *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v9) = 0;
  *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v9) = v5;
  if ( v5 == 0xFFFF )
  {
    symbols.m_Root = v6;
  }
  else
  {
    v10 = v5;
    if ( HIBYTE(partial) != 0 )
      m_pMemory[v10].m_Left = v6;
    else
      m_pMemory[v10].m_Right = v6;
  }
  CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::InsertRebalance(
    this: &symbols,
    elem: v6);
  ++symbols.m_NumElements;
  if ( (UtlRBTreeNode_t<CUtlString,unsigned short> *)((char *)symbols.m_Elements.m_pMemory + v9) != (UtlRBTreeNode_t<CUtlString,unsigned short> *)-8 )
    CUtlString::CUtlString(this: (CUtlString *)((char *)&symbols.m_Elements.m_pMemory->m_Data + v9), string: &str);
  str.m_Storage.m_nActualLength = 0;
  if ( symbols.m_NumElements < 0x40u )
  {
    if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( str.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
        str.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      str.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    goto LABEL_17;
  }
  if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
LABEL_22:
  v11 = 0;
  v12 = CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::FirstInorder(this: &symbols);
  if ( v12 != 0xFFFF )
  {
    v13 = (char *)commands;
    do
    {
      v14 = CUtlString::operator char const *(this: &symbols.m_Elements.m_pMemory[(unsigned __int16)v12].m_Data);
      V_strncpy(pDest: buf, pSrc: v14, maxLen: 512);
      _V_strlower(start: buf);
      V_snprintf(pDest: v13, maxLen: 64, pFormat: "%s %s", "gamemenucommand", buf);
      ++v11;
      v13 += 64;
      v12 = CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::NextInorder(
              this: &symbols,
              i: v12);
    }
    while ( v12 != 0xFFFF );
  }
  CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::RemoveAll(this: &symbols);
  if ( symbols.m_Elements.m_nGrowSize >= 0 && symbols.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: symbols.m_Elements.m_pMemory);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x101FC620
// Name: private: void CBaseModPanel::CreateGameMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModPanel::CreateGameMenu(CBaseModPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  CGameMenu *m_pGameMenu; // ecx
  const char *v6; // [esp+0h] [ebp-8h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "GameMenu");
  else
    v3 = nullptr;
  KeyValues::UsesEscapeSequences(this: v3, state: 1);
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: "Resource/GameMenu.res",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    this->m_pGameMenu = CBaseModPanel::RecursiveLoadGameMenu(this, datafile: v3);
  }
  m_pGameMenu = this->m_pGameMenu;
  if ( m_pGameMenu != nullptr )
  {
    vgui::Panel::MakeReadyForUse(this: m_pGameMenu);
    vgui::Panel::SetAlpha(this: this->m_pGameMenu, alpha: 0);
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_104C01D0, a2: v6);
  }
  KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101FC6C0
// Name: protected: CBaseModPanel::CBaseModPanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseModPanel *__thiscall CBaseModPanel::CBaseModPanel(CBaseModPanel *this, const char *panelName)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  PanelAnimationMap *v6; // eax
  int m_Size; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  CGameUI *v16; // eax
  vgui::AnimationController *v17; // eax
  vgui::AnimationController *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  IBaseFileSystem *v21; // ecx
  CModInfo *v22; // eax
  CModInfo *GameTitle; // eax
  CBackgroundMenuButton *MenuButton; // eax
  int v25; // ecx
  int m_nAllocationCount; // eax
  CBackgroundMenuButton **m_pMemory; // edx
  int v28; // eax
  CBackgroundMenuButton **v29; // ecx
  CModInfo *v30; // eax
  const wchar_t *GameTitle2; // eax
  CBackgroundMenuButton *v32; // eax
  int v33; // ecx
  int v34; // eax
  CBackgroundMenuButton **v35; // edx
  int v36; // eax
  CBackgroundMenuButton **v37; // ecx
  int (__thiscall ***v38)(_DWORD); // eax
  int v39; // eax
  int v40; // eax
  CBonusMapsDatabase *v41; // eax
  CGameUI *v42; // eax
  CGameUI *v43; // eax
  CNewGameDialog *v44; // eax
  CNewGameDialog *v45; // eax
  vgui::Panel *v46; // eax
  vgui::Label *v47; // eax
  vgui::Label *v48; // eax
  vgui::Label *v49; // eax
  unsigned int vpanel; // [esp-Ch] [ebp-34h]
  const char *v52; // [esp+0h] [ebp-28h]
  PanelAnimationMapEntry src; // [esp+Ch] [ebp-1Ch] BYREF
  CBackgroundMenuButton *v54; // [esp+24h] [ebp-4h]
  int steamPipe; // [esp+30h] [ebp+8h]
  int steamPipea; // [esp+30h] [ebp+8h]
  int steamPipeb; // [esp+30h] [ebp+8h]

  vgui::Panel::Panel(this, parent: nullptr, panelName);
  this->__vftable = (CBaseModPanel_vtbl *)&CBaseModPanel::`vftable';
  if ( `CBaseModPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseModPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBaseModPanel");
    v3->pfnClassName = CBaseModPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CBaseModPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseModPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBaseModPanel");
    v4->pfnClassName = CBaseModPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CBaseModPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseModPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseModPanel");
    v5->pfnClassName = CBaseModPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CBaseModPanel::PanelMessageFunc_OnActivateModule::InitVar();
  this->m_pGameMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pGameMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pGameMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pGameMenuButtons.m_Size = 0;
  this->m_pGameMenuButtons.m_pElements = nullptr;
  this->m_iGameTitlePos.m_Memory.m_pMemory = nullptr;
  this->m_iGameTitlePos.m_Memory.m_nAllocationCount = 0;
  this->m_iGameTitlePos.m_Memory.m_nGrowSize = 0;
  this->m_iGameTitlePos.m_Size = 0;
  this->m_iGameTitlePos.m_pElements = nullptr;
  this->m_hNewGameDialog.m_iPanelID = -1;
  this->m_hBonusMapsDialog.m_iPanelID = -1;
  this->m_hLoadGameDialog.m_iPanelID = -1;
  this->m_hLoadGameDialog_Xbox.m_iPanelID = -1;
  this->m_hSaveGameDialog.m_iPanelID = -1;
  this->m_hSaveGameDialog_Xbox.m_iPanelID = -1;
  this->m_hOptionsDialog.m_iPanelID = -1;
  this->m_hCreateMultiplayerGameDialog.m_iPanelID = -1;
  this->m_hChangeGameDialog.m_iPanelID = -1;
  this->m_hPlayerListDialog.m_iPanelID = -1;
  this->m_hBenchmarkDialog.m_iPanelID = -1;
  this->m_hLoadCommentaryDialog.m_iPanelID = -1;
  this->m_MessageDialogHandler.m_hMessageDialogs[0].m_iPanelID = -1;
  this->m_MessageDialogHandler.m_hMessageDialogs[1].m_iPanelID = -1;
  this->m_MessageDialogHandler.m_hMessageDialogs[2].m_iPanelID = -1;
  this->m_MessageDialogHandler.m_iDialogStackTop = -1;
  this->m_CommandQueue.m_Memory.m_pMemory = nullptr;
  this->m_CommandQueue.m_Memory.m_nAllocationCount = 0;
  this->m_CommandQueue.m_Memory.m_nGrowSize = 0;
  this->m_CommandQueue.m_Size = 0;
  this->m_CommandQueue.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_strPostPromptCommand);
  this->m_BackdropColor = 0;
  if ( `CBaseModPanel::PanelAnimationVar_m_flBackgroundFillAlpha::InitVar'::`2'::bAdded == 0 )
  {
    `CBaseModPanel::PanelAnimationVar_m_flBackgroundFillAlpha::InitVar'::`2'::bAdded = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseModPanel");
    m_Size = v6->entries.m_Size;
    src.m_pszScriptName = "m_flBackgroundFillAlpha";
    src.m_pszVariable = "m_flBackgroundFillAlpha";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CBaseModPanel::GetVar_m_flBackgroundFillAlpha;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v6->entries,
      elem: m_Size,
      &src);
  }
  CBaseModPanel::PanelMessageFunc_RunEngineCommand::InitVar();
  CBaseModPanel::PanelMessageFunc_RunMenuCommand::InitVar();
  CBaseModPanel::PanelMessageFunc_RunSlottedMenuCommand::InitVar();
  CBaseModPanel::PanelMessageFunc_FinishDialogClose::InitVar();
  this->m_flTransitionStartTime = 0.0;
  this->m_flTransitionEndTime = 0.0;
  this->m_eBackgroundState = BACKGROUND_INITIAL;
  this->m_flFrameFadeInTime = 0.5;
  this->m_bRenderingBackgroundTransition = false;
  this->m_bFadingInMenus = false;
  *(_WORD *)&this->m_bLevelLoading = 0;
  this->m_iGameMenuInset = 24;
  this->m_bPlatformMenuInitialized = false;
  *(_WORD *)&this->m_bHaveDarkenedBackground = 256;
  this->m_bForceTitleTextUpdate = true;
  this->m_BackdropColor = (Color)0x80000000;
  g_pBasePanel = this;
  this->m_pConsoleAnimationController = nullptr;
  this->m_pConsoleControlSettings = nullptr;
  *(_WORD *)&this->m_bCopyFrameBuffer = 0;
  this->m_ExitingFrameCount = 0;
  *(_DWORD *)&this->m_bXUIVisible = 0;
  *(_WORD *)&this->m_bWaitingForStorageDeviceHandle = 0;
  *(_DWORD *)&this->m_bUserRefusedSignIn = 0;
  this->m_iStorageID = -1;
  this->m_pAsyncJob = nullptr;
  this->m_pStorageDeviceValidatedNotify = nullptr;
  *(_WORD *)&this->m_bMainMenuShown = 1;
  *(_DWORD *)&this->m_bShowStartScreen = 16842753;
  v9 = _CommandLine(a1: v8);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 40))(a1: v9, a2: "+map") != 0 )
    this->m_bShowStartScreen = false;
  v11 = _CommandLine(a1: v10);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: "-hijack") != 0
    || (v13 = _CommandLine(a1: v12),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-tools") != 0)
    || (v15 = _CommandLine(a1: v14),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v15 + 40))(a1: v15, a2: "-no_scaleform_menu_on_boot") != 0) )
  {
    this->m_bShowStartScreen = false;
    this->m_bScaleformMainMenuEnabled = false;
  }
  v16 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v16) )
  {
    v17 = (vgui::AnimationController *)MemAlloc_Alloc(nSize: 0x1C8u);
    v18 = v17 != nullptr ? vgui::AnimationController::AnimationController(this: v17, parent: this) : nullptr;
    vpanel = this->_vpanel;
    this->m_pConsoleAnimationController = v18;
    vgui::AnimationController::SetScriptFile(
      this: v18,
      sizingPanel: vpanel,
      fileName: "scripts/GameUIAnimations.txt",
      wipeAll: false);
    vgui::AnimationController::SetAutoReloadScript(this: this->m_pConsoleAnimationController, state: false);
    v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v20 = v19 != nullptr ? KeyValues::KeyValues(this: v19, setName: "XboxDialogs.res") : nullptr;
    this->m_pConsoleControlSettings = v20;
    v21 = g_pFullFileSystem != nullptr ? &g_pFullFileSystem->IBaseFileSystem : nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v20,
            filesystem: v21,
            resourceName: "resource/UI/XboxDialogs.res",
            pathID: "GAME",
            pfnEvaluateSymbolProc: nullptr) )
      _Error(this: (ISceneTokenProcessor *)&stru_104C0244, a2: v52);
  }
  v22 = ModInfo();
  GameTitle = CModInfo::GetGameTitle(this: v22);
  MenuButton = CreateMenuButton(parent: this, panelName: "GameMenuButton", panelText: GameTitle->m_wcsGameTitle);
  v25 = this->m_pGameMenuButtons.m_Size;
  v54 = MenuButton;
  m_nAllocationCount = this->m_pGameMenuButtons.m_Memory.m_nAllocationCount;
  steamPipe = v25;
  if ( v25 + 1 > m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pGameMenuButtons,
      num: v25 - m_nAllocationCount + 1);
    v25 = steamPipe;
  }
  ++this->m_pGameMenuButtons.m_Size;
  m_pMemory = this->m_pGameMenuButtons.m_Memory.m_pMemory;
  v28 = this->m_pGameMenuButtons.m_Size - v25 - 1;
  this->m_pGameMenuButtons.m_pElements = m_pMemory;
  if ( v28 > 0 )
  {
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v25 + 1], src: (unsigned __int8 *)&m_pMemory[v25], count: 4 * v28);
    v25 = steamPipe;
  }
  v29 = &this->m_pGameMenuButtons.m_Memory.m_pMemory[v25];
  if ( v29 != nullptr )
    *v29 = v54;
  v30 = ModInfo();
  GameTitle2 = CModInfo::GetGameTitle2(this: v30);
  v32 = CreateMenuButton(parent: this, panelName: "GameMenuButton2", panelText: GameTitle2);
  v33 = this->m_pGameMenuButtons.m_Size;
  v54 = v32;
  v34 = this->m_pGameMenuButtons.m_Memory.m_nAllocationCount;
  steamPipea = v33;
  if ( v33 + 1 > v34 )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pGameMenuButtons,
      num: v33 - v34 + 1);
    v33 = steamPipea;
  }
  ++this->m_pGameMenuButtons.m_Size;
  v35 = this->m_pGameMenuButtons.m_Memory.m_pMemory;
  v36 = this->m_pGameMenuButtons.m_Size - v33 - 1;
  this->m_pGameMenuButtons.m_pElements = v35;
  if ( v36 > 0 )
  {
    _V_memmove(dest: (unsigned __int8 *)&v35[v33 + 1], src: (unsigned __int8 *)&v35[v33], count: 4 * v36);
    v33 = steamPipea;
  }
  v37 = &this->m_pGameMenuButtons.m_Memory.m_pMemory[v33];
  if ( v37 != nullptr )
    *v37 = v54;
  this->m_pGameMenu = nullptr;
  this->m_pGameLogo = nullptr;
  if ( _SteamClient() != 0 )
  {
    v38 = (int (__thiscall ***)(_DWORD))_SteamClient();
    steamPipeb = (**v38)(a1: v38);
    v39 = _SteamClient();
    if ( (*(int (__thiscall **)(int, int, const char *))(*(_DWORD *)v39 + 36))(
           a1: v39,
           a2: steamPipeb,
           a3: "SteamUtils002") != 0 )
      bSteamCommunityFriendsVersion = true;
    v40 = _SteamClient();
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v40 + 4))(a1: v40, a2: steamPipeb);
  }
  CBaseModPanel::CreateGameMenu(this);
  CBaseModPanel::CreateGameLogo(this);
  v41 = BonusMapsDatabase();
  if ( CBonusMapsDatabase::GetBlink(this: v41) )
  {
    v42 = GameUI();
    if ( CGameUI::IsConsoleUI(this: v42) )
      CBaseModPanel::SetMenuItemBlinkingState(this, itemName: "OpenNewGameDialog", state: 1);
    else
      CBaseModPanel::SetMenuItemBlinkingState(this, itemName: "OpenBonusMapsDialog", state: 1);
  }
  CBaseModPanel::SetMenuAlpha(this, alpha: 0);
  v43 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v43) )
  {
    g_bIsCreatingNewGameMenuForPreFetching = true;
    v44 = (CNewGameDialog *)MemAlloc_Alloc(nSize: 0x2D0u);
    v45 = v44 != nullptr ? CNewGameDialog::CNewGameDialog(this: v44, parent: this, bCommentaryMode: false) : nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hNewGameDialog, pPanel: v45);
    v46 = vgui::PHandle::Get(this: &this->m_hNewGameDialog);
    v46->MarkForDeletion(this: v46);
    g_bIsCreatingNewGameMenuForPreFetching = false;
    if ( !this->m_bShowStartScreen )
    {
      CBaseModPanel::ArmFirstMenuItem(this);
      vgui::AnimationController::StartAnimationSequence(
        this: this->m_pConsoleAnimationController,
        sequenceName: "InitializeUILayout");
    }
  }
  v47 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v47 != nullptr )
    v48 = vgui::Label::Label(this: v47, parent: this, panelName: "CodeVersionLabel", text: prType);
  else
    v48 = nullptr;
  this->m_pCodeVersionLabel = v48;
  v49 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v49 != nullptr )
    this->m_pContentVersionLabel = vgui::Label::Label(
                                     this: v49,
                                     parent: this,
                                     panelName: "ContentVersionLabel",
                                     text: prType);
  else
    this->m_pContentVersionLabel = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103753E0
// Name: public: class vgui::Panel __near * vgui::PHandle::Get(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::PHandle::Get(vgui::PHandle *this)
{
  unsigned int v1; // esi
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // ebx
  char *ControlsModuleName; // eax

  if ( this->m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: this->m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x103AD140
// Name: private: class vgui::MenuItem __near * vgui::Menu::GetParentMenuItem(void)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::Menu::GetParentMenuItem(vgui::Menu *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  return (vgui::MenuItem *)__RTDynamicCast(
                             inptr: v1,
                             VfDelta: 0,
                             SrcType: &vgui::Panel `RTTI Type Descriptor',
                             TargetType: &vgui::MenuItem `RTTI Type Descriptor',
                             isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103ADA90
// Name: public: class vgui::MenuItem __near * vgui::Menu::GetMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::Menu::GetMenuItem(vgui::Menu *this, int itemID)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_MenuItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_MenuItems.m_LastAlloc.index
    && ((m_pMemory = this->m_MenuItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AF810
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Menu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Menu::GetMessageMap(vgui::Menu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Menu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Menu::GetMessageMap'::`2'::s_pMap;
  `vgui::Menu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Menu");
  `vgui::Menu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AF840
// Name: public: virtual struct PanelAnimationMap __near * vgui::Menu::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Menu::GetAnimMap(vgui::Menu *this)
{
  return FindOrAddPanelAnimationMap(className: "Menu");
}

//------------------------------------------------------------------------------
// Address: 0x103AF850
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Menu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Menu::GetKBMap(vgui::Menu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Menu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Menu::GetKBMap'::`2'::s_pMap;
  `vgui::Menu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Menu");
  `vgui::Menu::GetKBMap'::`2'::s_pMap = result;
  return result;
}
