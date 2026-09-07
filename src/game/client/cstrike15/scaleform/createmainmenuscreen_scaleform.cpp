// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/createmainmenuscreen_scaleform.cpp
// Functions: 18
// ============================================================

#include "game\client\cstrike15\scaleform\createmainmenuscreen_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1020A170
// Name: protected: virtual void CCreateMainMenuScreenScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::PostUnloadFlash(CCreateMainMenuScreenScaleform *this)
{
  IMatchEventsSink *v2; // edi
  IMatchEventsSubscription *v3; // eax

  if ( this != nullptr )
    v2 = &this->IMatchEventsSink;
  else
    v2 = nullptr;
  v3 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v3->Unsubscribe(this: v3, a2: v2);
  CCreateMainMenuScreenScaleform::m_pInstance = nullptr;
  if ( this != nullptr )
    ((void (__thiscall *)(CCreateMainMenuScreenScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
      a1: this,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1020A1C0
// Name: public: void CCreateMainMenuScreenScaleform::IsMultiplayerPrivilegeEnabled(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::IsMultiplayerPrivilegeEnabled(
        CCreateMainMenuScreenScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  const char *v4; // eax

  if ( pui->Params_GetNumArgs(this: pui, a2: obj) != 0 )
  {
    v4 = pui->Params_GetArgAsString(this: pui, a2: obj, a3: 0);
    _V_stricmp(s1: v4, s2: "bShowWarning");
  }
  this->m_pScaleformUI->Params_SetResult_3(this: this->m_pScaleformUI, a2: obj, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1020A230
// Name: protected: void CCreateMainMenuScreenScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::Show(CCreateMainMenuScreenScaleform *this)
{
  CGameUI *v2; // eax
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v5; // eax

  v2 = GameUI();
  CGameUI::SetBackgroundMusicDesired(this: v2, bPlayMusic: true);
  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      v5 = ScaleformUI();
      v5->Value_InvokeWithoutReturn(this: v5, a2: this->m_FlashAPI, a3: "showPanel", a4: nullptr, a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_bVisible = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A2A0
// Name: protected: void CCreateMainMenuScreenScaleform::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::Hide(CCreateMainMenuScreenScaleform *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v4; // eax

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      v4 = ScaleformUI();
      v4->Value_InvokeWithoutReturn(this: v4, a2: this->m_FlashAPI, a3: "hidePanel", a4: nullptr, a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_bVisible = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A300
// Name: protected: void CCreateMainMenuScreenScaleform::HideImmediate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::HideImmediate(CCreateMainMenuScreenScaleform *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v4; // eax

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      v4 = ScaleformUI();
      v4->Value_InvokeWithoutReturn(this: v4, a2: this->m_FlashAPI, a3: "hidePanelImmediate", a4: nullptr, a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_bVisible = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A360
// Name: protected: void CCreateMainMenuScreenScaleform::InnerRestorePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::InnerRestorePanel(CCreateMainMenuScreenScaleform *this)
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
// Address: 0x1020A3C0
// Name: public: static float CCreateMainMenuScreenScaleform::CalculateTrialTimeRemaining(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl CCreateMainMenuScreenScaleform::CalculateTrialTimeRemaining()
{
  bool v0; // zf
  float m_fValue; // xmm1_4
  ConVarRef xbox_arcade_title_unlocked; // [esp+0h] [ebp-14h] BYREF
  ConVarRef xbox_arcade_remaining_trial_time; // [esp+8h] [ebp-Ch] BYREF
  float timeLeft; // [esp+10h] [ebp-4h]

  ConVarRef::ConVarRef(this: &xbox_arcade_title_unlocked, pName: "xbox_arcade_title_unlocked");
  ConVarRef::ConVarRef(this: &xbox_arcade_remaining_trial_time, pName: "xbox_arcade_remaining_trial_time");
  v0 = xbox_arcade_title_unlocked.m_pConVarState->m_Value.m_nValue == 0;
  m_fValue = xbox_arcade_remaining_trial_time.m_pConVarState->m_Value.m_fValue;
  timeLeft = m_fValue;
  if ( v0 )
  {
    if ( m_fValue < 0.0 )
      return 0.0;
    return timeLeft;
  }
  else
  {
    timeLeft = -1.0;
    return -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A420
// Name: public: static void CCreateMainMenuScreenScaleform::TryShowTrialWelcome(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateMainMenuScreenScaleform::TryShowTrialWelcome()
{
  float m_fValue; // xmm0_4
  const char *v1; // esi
  CCStrike15BasePanel *v2; // eax
  ConVarRef v3; // [esp+0h] [ebp-10h] BYREF
  ConVarRef v4; // [esp+8h] [ebp-8h] BYREF

  if ( !g_bShowedTrialWelcomeMessage )
  {
    g_bShowedTrialWelcomeMessage = true;
    ConVarRef::ConVarRef(this: &v3, pName: "xbox_arcade_title_unlocked");
    ConVarRef::ConVarRef(this: &v4, pName: "xbox_arcade_remaining_trial_time");
    m_fValue = v4.m_pConVarState->m_Value.m_fValue;
    if ( v3.m_pConVarState->m_Value.m_nValue == 0 )
    {
      if ( m_fValue < 0.0 )
        m_fValue = 0.0;
      v1 = "#SFUI_TrialWelcomeMessageExpired";
      if ( m_fValue > 0.0 )
        v1 = "#SFUI_TrialWelcomeMessage";
      v2 = BasePanel();
      v2->OnOpenMessageBox(
        this: v2,
        a2: "#SFUI_TrialWelcomeTitle",
        a3: v1,
        a4: "#SFUI_Legend_Ok",
        a5: 1u,
        a6: nullptr,
        a7: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A4B0
// Name: public: static void CCreateMainMenuScreenScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateMainMenuScreenScaleform::UnloadDialog()
{
  if ( CCreateMainMenuScreenScaleform::m_pInstance != nullptr )
  {
    CCreateMainMenuScreenScaleform::HideImmediate(this: CCreateMainMenuScreenScaleform::m_pInstance);
    if ( CCreateMainMenuScreenScaleform::m_pInstance->m_bFlashAPIIsValid )
      CCreateMainMenuScreenScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
        this: CCreateMainMenuScreenScaleform::m_pInstance->m_pScaleformUI,
        a2: CCreateMainMenuScreenScaleform::m_pInstance->m_iFlashSlot,
        a3: CCreateMainMenuScreenScaleform::m_pInstance->m_FlashAPI);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A4E0
// Name: protected: virtual void CCreateMainMenuScreenScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::FlashReady(CCreateMainMenuScreenScaleform *this)
{
  void *v2; // ebx
  IMatchSystem *v3; // eax
  IScaleformUI_vtbl *v4; // eax
  bool (__thiscall *Connect)(IAppSystem *, void *(__cdecl *)(const char *, int *)); // edi
  vgui::CTreeViewListControl *v6; // ecx
  int v7; // eax
  int v8; // eax
  __int64 (__thiscall ***v9)(_DWORD); // edi
  int (__thiscall *v10)(_DWORD); // eax
  int v11; // eax
  __int64 (__thiscall *v12)(_DWORD); // eax
  __int64 v13; // rax
  __int64 (__thiscall **v14)(_DWORD); // edx
  __int64 v15; // rax
  int m_nValue; // eax
  int v17; // eax
  void (__thiscall ***v18)(_DWORD, IMatchEventsSink *); // eax
  char *v19; // [esp+0h] [ebp-110h]
  char xuidText[256]; // [esp+Ch] [ebp-104h] BYREF
  IScaleformUI_vtbl *v21; // [esp+10Ch] [ebp-4h]

  v2 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 4);
  if ( v2 != nullptr )
  {
    v3 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
    v4 = (IScaleformUI_vtbl *)v3->GetPlayerManager(this: v3);
    Connect = v4->Connect;
    v21 = v4;
    v7 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v6);
    v8 = (*((int (__thiscall **)(IScaleformUI_vtbl *, int))Connect + 1))(a1: v21, a2: v7);
    v9 = (__int64 (__thiscall ***)(_DWORD))v8;
    if ( v8 != 0 )
    {
      v10 = *(int (__thiscall **)(_DWORD))(*(_DWORD *)v8 + 8);
      v21 = this->m_pScaleformUI->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable;
      v11 = v10(a1: v9);
      v21->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v2, a3: 0, a4: (const char *)v11);
      v12 = **v9;
      xuidText[0] = 0;
      v13 = v12(a1: v9);
      V_snprintf(pDest: xuidText, maxLen: 0xFFu, pFormat: "%llu", v13);
      v14 = *v9;
      v21 = this->m_pScaleformUI->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable;
      v15 = (*v14)(a1: v9);
      ((void (__thiscall *)(IScaleformUI *, _DWORD, _DWORD))v21->AvatarImageAddRef)(
        a1: this->m_pScaleformUI,
        a2: v15,
        a3: HIDWORD(v15));
      v19 = xuidText;
    }
    else
    {
      this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v2, a3: 0, a4: "Player1");
      v19 = "0";
    }
    ((void (__stdcall *)(void *, int))this->m_pScaleformUI->ValueArray_SetElement_2)(a1: v2, a2: 3);
    if ( player_teamplayedlast.m_pParent != nullptr )
      m_nValue = player_teamplayedlast.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v2, a3: 1, a4: m_nValue);
    if ( player_classplayedlast.m_pParent != nullptr )
      v17 = player_classplayedlast.m_pParent->m_Value.m_nValue;
    else
      v17 = 0;
    this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v2, a3: 2, a4: v17);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "SetPlayerData",
      a4: v2,
      a5: 4u);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v2, a3: 4u);
  }
  v18 = (void (__thiscall ***)(_DWORD, IMatchEventsSink *))((int (__thiscall *)(IMatchFramework *, char *))g_pMatchFramework->GetEventsSubscription)(
                                                             a1: g_pMatchFramework,
                                                             a2: v19);
  (**v18)(a1: v18, a2: &this->IMatchEventsSink);
  CCreateMainMenuScreenScaleform::Show(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020A670
// Name: public: void CCreateMainMenuScreenScaleform::GetTrialTimeRemaining(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::GetTrialTimeRemaining(
        CCreateMainMenuScreenScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  float m_fValue; // xmm0_4
  ConVarRef v5; // [esp+8h] [ebp-10h] BYREF
  ConVarRef v6; // [esp+10h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &v5, pName: "xbox_arcade_title_unlocked");
  ConVarRef::ConVarRef(this: &v6, pName: "xbox_arcade_remaining_trial_time");
  m_fValue = v6.m_pConVarState->m_Value.m_fValue;
  if ( v5.m_pConVarState->m_Value.m_nValue != 0 )
  {
    m_fValue = -1.0;
  }
  else if ( m_fValue < 0.0 )
  {
    m_fValue = 0.0;
  }
  ((void (__stdcall *)(void *, _DWORD))this->m_pScaleformUI->Params_SetResult_4)(a1: obj, a2: LODWORD(m_fValue));
}

//------------------------------------------------------------------------------
// Address: 0x1020A6E0
// Name: public: static void CCreateMainMenuScreenScaleform::RestorePanel(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateMainMenuScreenScaleform::RestorePanel()
{
  if ( CCreateMainMenuScreenScaleform::m_pInstance != nullptr
    && !CCreateMainMenuScreenScaleform::m_pInstance->m_bVisible )
  {
    CCreateMainMenuScreenScaleform::InnerRestorePanel(this: CCreateMainMenuScreenScaleform::m_pInstance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A700
// Name: public: void CCreateMainMenuScreenScaleform::LaunchTraining(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::LaunchTraining(
        CCreateMainMenuScreenScaleform *this,
        IScaleformUI *pui,
        IScaleformUI *obj)
{
  KeyValues *v3; // ebx
  IMatchSession *v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  CCStrike15BasePanel *v7; // eax

  BasePanel()->m_bSinglePlayer = true;
  v3 = KeyValues::FromString(
         szName: "Settings",
         szStringVal: (KeyValues *)"System { network offline }Game { type training mode training bspname training1 }Options { action c"
                      "reate }Contexts {}Properties {}",
         ppEndOfParse: nullptr);
  BasePanel()->m_bSinglePlayer = true;
  g_pMatchFramework->CreateSession(this: g_pMatchFramework, a2: v3);
  v4 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
  if ( v4 != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "Start");
    else
      v6 = nullptr;
    v4->Command(this: v4, a2: v6);
    if ( v6 != nullptr )
      KeyValues::deleteThis(this: v6);
  }
  else
  {
    _Warning(a1: "CCreateMainMenuScreenScaleform: unable to create single player session.\n");
    v7 = BasePanel();
    v7->RestoreMainMenuScreen(this: v7);
  }
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1020A7C0
// Name: public: static void CCreateMainMenuScreenScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateMainMenuScreenScaleform::LoadDialog()
{
  CCreateMainMenuScreenScaleform *v0; // eax

  if ( CCreateMainMenuScreenScaleform::m_pInstance == nullptr )
  {
    v0 = (CCreateMainMenuScreenScaleform *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v0 != nullptr )
    {
      v0->m_bFlashAPIIsValid = false;
      v0->m_iFlashSlot = -1;
      v0->m_pScaleformUI = nullptr;
      v0->m_FlashAPI = nullptr;
      v0->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
      v0->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&IMessageBoxEventCallback::`vftable';
      v0->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CCreateMainMenuScreenScaleform_vtbl *)&CCreateMainMenuScreenScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
      v0->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CCreateMainMenuScreenScaleform::`vftable'{for `IMatchEventsSink'};
      v0->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CCreateMainMenuScreenScaleform::`vftable'{for `IMessageBoxEventCallback'};
      v0->m_pConfirmDialog = nullptr;
      v0->m_bVisible = false;
    }
    else
    {
      v0 = nullptr;
    }
    CCreateMainMenuScreenScaleform::m_pInstance = v0;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "MainMenu",
      a4: (ScaleformUIFunctionHandlerObject *)v0,
      a5: pScaleformFunctionHandler_CCreateMainMenuScreenScaleform_MainMenu);
    CCreateMainMenuScreenScaleform::TryShowTrialWelcome();
    CCreateMainMenuScreenScaleform::m_pInstance->m_bVisible = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A850
// Name: public: static void CCreateMainMenuScreenScaleform::ShowPanel(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCreateMainMenuScreenScaleform::ShowPanel(bool bShow, bool immediate)
{
  CCreateMainMenuScreenScaleform *v2; // ecx

  if ( !bShow )
  {
LABEL_4:
    v2 = CCreateMainMenuScreenScaleform::m_pInstance;
    if ( CCreateMainMenuScreenScaleform::m_pInstance == nullptr )
      return;
    goto LABEL_5;
  }
  v2 = CCreateMainMenuScreenScaleform::m_pInstance;
  if ( CCreateMainMenuScreenScaleform::m_pInstance == nullptr )
  {
    CCreateMainMenuScreenScaleform::LoadDialog();
    goto LABEL_4;
  }
LABEL_5:
  if ( bShow != v2->m_bVisible )
  {
    if ( bShow )
    {
      CCreateMainMenuScreenScaleform::Show(this: v2);
    }
    else if ( immediate )
    {
      CCreateMainMenuScreenScaleform::HideImmediate(this: v2);
    }
    else
    {
      CCreateMainMenuScreenScaleform::Hide(this: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A8A0
// Name: public: void CCreateMainMenuScreenScaleform::BasePanelRunCommand(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::BasePanelRunCommand(
        CCreateMainMenuScreenScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  IScaleformUI *v3; // esi
  void *v4; // edi
  char *v5; // eax
  const char *v6; // eax
  bool v7; // bl
  char v8; // bl
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  KeyValues *v11; // eax
  CCStrike15BasePanel *v12; // edi
  CCStrike15BasePanel_vtbl *v13; // esi
  CCStrike15BasePanel *v14; // eax
  int v15; // [esp+4h] [ebp-428h]
  char RunCommandStr[1024]; // [esp+1Ch] [ebp-410h] BYREF
  ConVarRef v17; // [esp+41Ch] [ebp-10h] BYREF
  ConVarRef v18; // [esp+424h] [ebp-8h] BYREF

  v3 = pui;
  v4 = obj;
  v15 = (int)obj;
  v5 = (char *)((int (__thiscall *)(IScaleformUI *))pui->Params_GetArgAsString)(a1: pui);
  V_strncpy(pDest: RunCommandStr, pSrc: v5, maxLen: v15);
  v7 = false;
  if ( (unsigned int)((int (__thiscall *)(IScaleformUI *, void *, _DWORD, int))v3->Params_GetNumArgs)(
                       a1: v3,
                       a2: v4,
                       a3: 0,
                       a4: 1024) > 1 )
  {
    v6 = v3->Params_GetArgAsString(this: v3, a2: v4, a3: 1);
    if ( _V_stricmp(s1: v6, s2: "bHidePanel") == 0 )
      v7 = true;
  }
  ConVarRef::ConVarRef(this: &v18, pName: "xbox_arcade_title_unlocked");
  ConVarRef::ConVarRef(this: &v17, pName: "xbox_arcade_remaining_trial_time");
  if ( v18.m_pConVarState->m_Value.m_nValue != 0
    || v17.m_pConVarState->m_Value.m_fValue > 0.0
    || _V_strcmp(s1: RunCommandStr, s2: "Quit") == 0 )
  {
    HIBYTE(pui) = 0;
    if ( !v7 )
      goto LABEL_18;
    v8 = HIBYTE(pui);
  }
  else
  {
    v8 = 1;
  }
  if ( CCreateMainMenuScreenScaleform::m_pInstance != nullptr && CCreateMainMenuScreenScaleform::m_pInstance->m_bVisible )
    CCreateMainMenuScreenScaleform::Hide(this: CCreateMainMenuScreenScaleform::m_pInstance);
  if ( v8 != 0 )
  {
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(
              this: v9,
              setName: "RunMenuCommand",
              firstKey: "command",
              firstValue: "OpenUpsellDialog");
    else
      v10 = nullptr;
    goto LABEL_21;
  }
LABEL_18:
  LOWORD(pui) = 48;
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v10 = KeyValues::KeyValues(
            this: v11,
            setName: "RunSlottedMenuCommand",
            firstKey: "slot",
            firstValue: (char *)&pui,
            secondKey: "command",
            secondValue: RunCommandStr);
  else
    v10 = nullptr;
LABEL_21:
  v12 = BasePanel();
  v13 = v12->CBaseModPanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v14 = BasePanel();
  ((void (__thiscall *)(CCStrike15BasePanel *, CCStrike15BasePanel *, KeyValues *, _DWORD))v13->PostMessage)(
    a1: v12,
    a2: v14,
    a3: v10,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020AA50
// Name: public: void CCreateMainMenuScreenScaleform::IsArcadeTitleUnlocked(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMainMenuScreenScaleform::IsArcadeTitleUnlocked(
        CCreateMainMenuScreenScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  const char *v4; // eax
  bool v5; // bl
  IMessageBoxEventCallback *v6; // esi
  CCStrike15BasePanel *v7; // eax
  ConVarRef xbox_arcade_title_unlocked; // [esp+Ch] [ebp-8h] BYREF

  v5 = false;
  if ( pui->Params_GetNumArgs(this: pui, a2: obj) != 0 )
  {
    v4 = pui->Params_GetArgAsString(this: pui, a2: obj, a3: 0);
    if ( _V_stricmp(s1: v4, s2: "bShowWarning") == 0 )
      v5 = true;
  }
  ConVarRef::ConVarRef(this: &xbox_arcade_title_unlocked, pName: "xbox_arcade_title_unlocked");
  LOBYTE(pui) = xbox_arcade_title_unlocked.m_pConVarState->m_Value.m_nValue != 0;
  if ( xbox_arcade_title_unlocked.m_pConVarState->m_Value.m_nValue == 0 && v5 )
  {
    if ( CCreateMainMenuScreenScaleform::m_pInstance != nullptr
      && CCreateMainMenuScreenScaleform::m_pInstance->m_bVisible )
    {
      CCreateMainMenuScreenScaleform::Hide(this: CCreateMainMenuScreenScaleform::m_pInstance);
    }
    if ( this != nullptr )
      v6 = &this->IMessageBoxEventCallback;
    else
      v6 = nullptr;
    v7 = BasePanel();
    v7->OnOpenMessageBox(
      this: v7,
      a2: "#SFUI_GameUI_ArcadeNotUnlockedTitle",
      a3: "#SFUI_GameUI_ArcadeNotUnlocked",
      a4: "#SFUI_GameUI_ErrorDismiss",
      a5: 1u,
      a6: v6,
      a7: &this->m_pConfirmDialog);
  }
  this->m_pScaleformUI->Params_SetResult_3(this: this->m_pScaleformUI, a2: obj, a3: (bool)pui);
}

//------------------------------------------------------------------------------
// Address: 0x1020AB20
// Name: public: virtual bool CCreateMainMenuScreenScaleform::OnMessageBoxEvent(enum MessageBoxFlags_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCreateMainMenuScreenScaleform::OnMessageBoxEvent(
        CCreateMainMenuScreenScaleform *this,
        MessageBoxFlags_t buttonPressed)
{
  IScaleformUI *m_pScaleformUI; // ecx
  CCreateMainMenuScreenScaleform *v5; // ecx

  m_pScaleformUI = this->m_pScaleformUI;
  if ( m_pScaleformUI == nullptr )
    return 0;
  if ( (buttonPressed & 1) != 0 )
  {
    CMessageBoxScaleform::Hide(this: (CMessageBoxScaleform *)m_pScaleformUI);
    this->m_pScaleformUI = nullptr;
    v5 = CCreateMainMenuScreenScaleform::m_pInstance;
    if ( CCreateMainMenuScreenScaleform::m_pInstance != nullptr
      || (CCreateMainMenuScreenScaleform::LoadDialog(),
          v5 = CCreateMainMenuScreenScaleform::m_pInstance,
          CCreateMainMenuScreenScaleform::m_pInstance != nullptr) )
    {
      if ( !v5->m_bVisible )
        CCreateMainMenuScreenScaleform::Show(this: v5);
    }
  }
  return 1;
}
