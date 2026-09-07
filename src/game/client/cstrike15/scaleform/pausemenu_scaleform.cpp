// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/pausemenu_scaleform.cpp
// Functions: 17
// ============================================================

#include "game\client\cstrike15\scaleform\pausemenu_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1020ED80
// Name: protected: virtual void CPauseMenuScreenScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::PostUnloadFlash(CPauseMenuScreenScaleform *this)
{
  IMatchEventsSink *v2; // esi
  IMatchEventsSubscription *v3; // eax

  if ( this != nullptr )
    v2 = &this->IMatchEventsSink;
  else
    v2 = nullptr;
  v3 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v3->Unsubscribe(this: v3, a2: v2);
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->CGameEventListener);
    this->m_bRegisteredForEvents = false;
  }
  CPauseMenuScreenScaleform::m_pInstance = nullptr;
  if ( this != nullptr )
    ((void (__thiscall *)(CPauseMenuScreenScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
      a1: this,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1020EDE0
// Name: public: void CPauseMenuScreenScaleform::IsMultiplayer(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::IsMultiplayer(CPauseMenuScreenScaleform *this, IScaleformUI *pui, void *obj)
{
  IMatchSession *v4; // eax
  bool bMultiplayer; // [esp+4h] [ebp-4h]

  bMultiplayer = false;
  if ( g_pMatchFramework != nullptr )
  {
    v4 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
    if ( v4 != nullptr )
      bMultiplayer = v4->GetSessionSystemData(this: v4) != 0;
  }
  this->m_pScaleformUI->Params_SetResult_3(this: this->m_pScaleformUI, a2: obj, a3: bMultiplayer);
}

//------------------------------------------------------------------------------
// Address: 0x1020EE30
// Name: public: void CPauseMenuScreenScaleform::CanMakeSessionPublic(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::CanMakeSessionPublic(
        CPauseMenuScreenScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  IMatchSession *v4; // esi
  KeyValues *v5; // eax
  char *String; // eax
  KeyValues *v7; // eax
  char *v8; // eax
  bool bCanMakePublic; // [esp+4h] [ebp-4h]

  bCanMakePublic = false;
  if ( g_pMatchFramework != nullptr )
  {
    v4 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
    if ( v4 != nullptr )
    {
      v5 = (KeyValues *)v4->GetSessionSystemData(this: v4);
      if ( v5 != nullptr )
      {
        String = KeyValues::GetString(this: v5, keyName: "type", defaultValue: nullptr);
        if ( String != nullptr )
        {
          if ( _V_stricmp(s1: String, s2: "client") != 0 )
          {
            v7 = v4->GetSessionSettings(this: v4);
            if ( v7 != nullptr )
            {
              v8 = KeyValues::GetString(this: v7, keyName: "system/access", defaultValue: nullptr);
              if ( v8 != nullptr )
              {
                if ( _V_stricmp(s1: "public", s2: v8) != 0 )
                  bCanMakePublic = true;
                else
                  DevMsg(a1: "PauseMenu::CanMakeSessionPublic: system/access already set \"public\", returning false.\n");
              }
            }
          }
          else
          {
            DevMsg(a1: "PauseMenu::CanMakeSessionPublic: User type=\"client\", returning false.\n");
          }
        }
      }
    }
  }
  this->m_pScaleformUI->Params_SetResult_3(this: this->m_pScaleformUI, a2: obj, a3: bCanMakePublic);
}

//------------------------------------------------------------------------------
// Address: 0x1020EF00
// Name: public: void CPauseMenuScreenScaleform::SwitchTeams(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::SwitchTeams(CPauseMenuScreenScaleform *this, IScaleformUI *pui, void *obj)
{
  vgui::PropertySheet *LocalPlayer; // esi
  CGameUI *v4; // eax
  IViewPort *ViewPortInterface; // eax
  IViewPort *v6; // eax
  IViewPort *v7; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  LocalPlayer = (vgui::PropertySheet *)CClientTools::GetLocalPlayer();
  if ( GetViewPortInterface() != nullptr
    && LocalPlayer != nullptr
    && CMoveHelperClient::PlayerFallingDamage(this: LocalPlayer) != 0 )
  {
    v4 = GameUI();
    CGameUI::HideGameUI(this: v4);
    ViewPortInterface = GetViewPortInterface();
    if ( ViewPortInterface != nullptr )
      v6 = ViewPortInterface - 95;
    else
      v6 = nullptr;
    HIBYTE(v6[123].__vftable) = 1;
    v7 = GetViewPortInterface();
    v7->ShowPanel_2(this: v7, a2: "team", a3: true);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x1020EF80
// Name: public: void CPauseMenuScreenScaleform::GetTrialTimeRemaining(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::GetTrialTimeRemaining(
        CPauseMenuScreenScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  IScaleformUI_vtbl *v4; // edi
  float v5; // [esp+0h] [ebp-Ch]

  v4 = this->m_pScaleformUI->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable;
  v5 = CCreateMainMenuScreenScaleform::CalculateTrialTimeRemaining();
  ((void (__thiscall *)(IScaleformUI *, void *, _DWORD))v4->Params_SetResult_4)(
    a1: this->m_pScaleformUI,
    a2: obj,
    a3: LODWORD(v5));
}

//------------------------------------------------------------------------------
// Address: 0x1020EFB0
// Name: public: void CPauseMenuScreenScaleform::CallVote(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::CallVote(CPauseMenuScreenScaleform *this, IScaleformUI *pui, void *obj)
{
  const char *v3; // eax
  char command[64]; // [esp+0h] [ebp-40h] BYREF

  v3 = this->m_pScaleformUI->Params_GetArgAsString(this: this->m_pScaleformUI, a2: obj, a3: 0);
  V_snprintf(pDest: command, maxLen: 0x40u, pFormat: "call_vote %s", v3);
  engine->ClientCmd(this: engine, a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x1020F010
// Name: protected: void CPauseMenuScreenScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::Show(CPauseMenuScreenScaleform *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  SplitScreenConVarRef pHideHud; // [esp+4h] [ebp-14h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+14h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "showPanel",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
  }
  else
  {
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "PauseMenu",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_CPauseMenuScreenScaleform_PauseMenu);
  }
  if ( !this->m_bVisible )
  {
    engine->ExecuteClientCmd(this: engine, a2: "hidescores");
    engine->ExecuteClientCmd(this: engine, a2: "spec_gui 0");
    SplitScreenConVarRef::SplitScreenConVarRef(this: &pHideHud, pName: "hidehud");
    CPauseMenuScreenScaleform::m_pInstance->m_PrevHideHudValues[0] = pHideHud.m_Info[0].m_pConVarState->m_Value.m_nValue;
    pHideHud.m_Info[0].m_pConVar->SetValue_2(this: pHideHud.m_Info[0].m_pConVar, a2: 4);
  }
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
  this->m_bVisible = true;
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x1020F110
// Name: protected: void CPauseMenuScreenScaleform::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::Hide(CPauseMenuScreenScaleform *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "hidePanel",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
  }
  this->m_bVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x1020F170
// Name: protected: virtual void CPauseMenuScreenScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::FlashReady(CPauseMenuScreenScaleform *this)
{
  void *v2; // ebx
  IMatchSystem *v3; // eax
  _DWORD *v4; // eax
  int v5; // edi
  vgui::CTreeViewListControl *v6; // ecx
  int v7; // eax
  int v8; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI_vtbl *v10; // edi
  int v11; // eax
  CGameEventListener *v12; // esi
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+Ch] [ebp-8h] BYREF
  _DWORD *v14; // [esp+10h] [ebp-4h]

  v2 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  v3 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
  v4 = (_DWORD *)v3->GetPlayerManager(this: v3);
  v5 = *v4;
  v14 = v4;
  v7 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v6);
  v8 = (*(int (__thiscall **)(_DWORD *, int))(v5 + 4))(a1: v14, a2: v7);
  m_pScaleformUI = this->m_pScaleformUI;
  if ( v8 != 0 )
  {
    v10 = m_pScaleformUI->__vftable;
    v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
    ((void (__stdcall *)(void *, _DWORD, int))v10->ValueArray_SetElement_2)(a1: v2, a2: 0, a3: v11);
  }
  else
  {
    ((void (__stdcall *)(void *, _DWORD, const char *))m_pScaleformUI->ValueArray_SetElement_2)(
      a1: v2,
      a2: 0,
      a3: "Player1");
  }
  this->m_pScaleformUI->Value_InvokeWithoutReturn(
    this: this->m_pScaleformUI,
    a2: this->m_FlashAPI,
    a3: "SetPlayerName",
    a4: v2,
    a5: 1u);
  this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v2, a3: 1u);
  CPauseMenuScreenScaleform::Show(this);
  v12 = &this->CGameEventListener;
  v12->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v12, a3: "cs_match_end_restart", a4: false);
  v12->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v12, a3: "cs_game_disconnected", a4: false);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x1020F270
// Name: protected: void CPauseMenuScreenScaleform::InnerRestorePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::InnerRestorePanel(CPauseMenuScreenScaleform *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "restorePanel",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_bVisible = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F2D0
// Name: public: static void CPauseMenuScreenScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPauseMenuScreenScaleform::UnloadDialog(int a1@<edi>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // ebx
  CCStrike15BasePanel *v3; // edi
  CCStrike15BasePanel_vtbl *v4; // esi
  CCStrike15BasePanel *v5; // eax
  SplitScreenConVarRef pHideHud; // [esp+10h] [ebp-10h] BYREF

  if ( CPauseMenuScreenScaleform::m_pInstance != nullptr )
  {
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
      v2 = KeyValues::KeyValues(this: v1, setName: "RunMenuCommand", firstKey: "command", firstValue: "ResumeGame");
    else
      v2 = nullptr;
    v3 = BasePanel();
    v4 = v3->CBaseModPanel::vgui::Panel::vgui::IClientPanel::__vftable;
    v5 = BasePanel();
    ((void (__thiscall *)(CCStrike15BasePanel *, CCStrike15BasePanel *, KeyValues *, _DWORD, int))v4->PostMessage)(
      a1: v3,
      a2: v5,
      a3: v2,
      a4: 0,
      a5: a1);
    g_pScaleformUI->DenyInputToGame(this: g_pScaleformUI, a2: false);
    if ( CPauseMenuScreenScaleform::m_pInstance->m_bVisible )
    {
      engine->ExecuteClientCmd(this: engine, a2: "spec_gui 1");
      SplitScreenConVarRef::SplitScreenConVarRef(this: &pHideHud, pName: "hidehud");
      pHideHud.m_Info[0].m_pConVar->SetValue_2(
        this: pHideHud.m_Info[0].m_pConVar,
        a2: CPauseMenuScreenScaleform::m_pInstance->m_PrevHideHudValues[0]);
    }
    g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
    CPauseMenuScreenScaleform::Hide(this: CPauseMenuScreenScaleform::m_pInstance);
    if ( CPauseMenuScreenScaleform::m_pInstance->m_bFlashAPIIsValid )
      CPauseMenuScreenScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
        this: CPauseMenuScreenScaleform::m_pInstance->m_pScaleformUI,
        a2: CPauseMenuScreenScaleform::m_pInstance->m_iFlashSlot,
        a3: CPauseMenuScreenScaleform::m_pInstance->m_FlashAPI);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F3D0
// Name: public: void CPauseMenuScreenScaleform::BasePanelRunCommand(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::BasePanelRunCommand(
        CPauseMenuScreenScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  IScaleformUI *v3; // esi
  void *v4; // edi
  char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  CCStrike15BasePanel *v11; // edi
  CCStrike15BasePanel_vtbl *v12; // esi
  CCStrike15BasePanel *v13; // eax
  int v14; // [esp+14h] [ebp-418h]
  char RunCommandStr[1024]; // [esp+2Ch] [ebp-400h] BYREF

  v3 = pui;
  v4 = obj;
  v14 = (int)obj;
  v6 = (char *)((int (__thiscall *)(IScaleformUI *))pui->Params_GetArgAsString)(a1: pui);
  V_strncpy(pDest: RunCommandStr, pSrc: v6, maxLen: v14);
  if ( (unsigned int)((int (__thiscall *)(IScaleformUI *, void *, _DWORD, int))v3->Params_GetNumArgs)(
                       a1: v3,
                       a2: v4,
                       a3: 0,
                       a4: 1024) > 1 )
  {
    v7 = v3->Params_GetArgAsString(this: v3, a2: v4, a3: 1);
    if ( _V_stricmp(s1: v7, s2: "bCloseMenu") != 0 )
    {
      v8 = v3->Params_GetArgAsString(this: v3, a2: v4, a3: 1);
      if ( _V_stricmp(s1: v8, s2: "bHideMenu") == 0 )
        CPauseMenuScreenScaleform::Hide(this);
    }
    else
    {
      CPauseMenuScreenScaleform::UnloadDialog(a1: (int)v4);
    }
  }
  LOWORD(pui) = 48;
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "RunSlottedMenuCommand",
            firstKey: "slot",
            firstValue: (char *)&pui,
            secondKey: "command",
            secondValue: RunCommandStr);
  else
    v10 = nullptr;
  v11 = BasePanel();
  v12 = v11->CBaseModPanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v13 = BasePanel();
  ((void (__thiscall *)(CCStrike15BasePanel *, CCStrike15BasePanel *, KeyValues *, _DWORD))v12->PostMessage)(
    a1: v11,
    a2: v13,
    a3: v10,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020F4E0
// Name: public: static void CPauseMenuScreenScaleform::RestorePanel(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPauseMenuScreenScaleform::RestorePanel()
{
  if ( CPauseMenuScreenScaleform::m_pInstance != nullptr && !CPauseMenuScreenScaleform::m_pInstance->m_bVisible )
    CPauseMenuScreenScaleform::InnerRestorePanel(this: CPauseMenuScreenScaleform::m_pInstance);
}

//------------------------------------------------------------------------------
// Address: 0x1020F500
// Name: public: virtual void CPauseMenuScreenScaleform::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPauseMenuScreenScaleform::FireGameEvent(CPauseMenuScreenScaleform *this, IGameEvent *event)
{
  const char *v3; // esi

  v3 = event->GetName(this: event);
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: (CGameUiSetActiveSplitScreenPlayerGuard *)&event,
    slot: this->m_iFlashSlot);
  if ( _V_strcmp(s1: v3, s2: "cs_match_end_restart") == 0 || _V_strcmp(s1: v3, s2: "cs_game_disconnected") == 0 )
    CPauseMenuScreenScaleform::UnloadDialog(a1: (int)this);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: (CGameUiSetActiveSplitScreenPlayerGuard *)&event);
}

//------------------------------------------------------------------------------
// Address: 0x1020F560
// Name: protected: CPauseMenuScreenScaleform::CPauseMenuScreenScaleform(void)
// Source: json
//------------------------------------------------------------------------------
CPauseMenuScreenScaleform *__thiscall CPauseMenuScreenScaleform::CPauseMenuScreenScaleform(
        CPauseMenuScreenScaleform *this)
{
  IMatchEventsSink *v2; // edi
  IMatchEventsSubscription *v3; // eax

  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  v2 = &this->IMatchEventsSink;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CPauseMenuScreenScaleform_vtbl *)&CPauseMenuScreenScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CPauseMenuScreenScaleform::`vftable'{for `IMatchEventsSink'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CPauseMenuScreenScaleform::`vftable'{for `CGameEventListener'};
  this->m_bVisible = false;
  this->m_iSplitScreenSlot = 0;
  v3 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v3->Subscribe(this: v3, a2: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020F5E0
// Name: public: static void CPauseMenuScreenScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPauseMenuScreenScaleform::LoadDialog()
{
  CPauseMenuScreenScaleform *v0; // eax
  CPauseMenuScreenScaleform *v1; // eax

  if ( CPauseMenuScreenScaleform::m_pInstance == nullptr )
  {
    g_pScaleformUI->DenyInputToGame(this: g_pScaleformUI, a2: true);
    v0 = (CPauseMenuScreenScaleform *)MemAlloc_Alloc(nSize: 0x30u);
    if ( v0 != nullptr )
      v1 = CPauseMenuScreenScaleform::CPauseMenuScreenScaleform(this: v0);
    else
      v1 = nullptr;
    CPauseMenuScreenScaleform::m_pInstance = v1;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "PauseMenu",
      a4: (ScaleformUIFunctionHandlerObject *)v1,
      a5: pScaleformFunctionHandler_CPauseMenuScreenScaleform_PauseMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F640
// Name: public: static void CPauseMenuScreenScaleform::ShowMenu(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CPauseMenuScreenScaleform::ShowMenu(bool bShow)
{
  CPauseMenuScreenScaleform *v1; // ecx

  v1 = CPauseMenuScreenScaleform::m_pInstance;
  if ( bShow && CPauseMenuScreenScaleform::m_pInstance == nullptr )
  {
    CPauseMenuScreenScaleform::LoadDialog();
    v1 = CPauseMenuScreenScaleform::m_pInstance;
  }
  if ( bShow != v1->m_bVisible )
  {
    if ( bShow )
      CPauseMenuScreenScaleform::Show(this: v1);
    else
      CPauseMenuScreenScaleform::Hide(this: v1);
  }
}
