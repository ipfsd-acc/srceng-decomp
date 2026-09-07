// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/settings_scaleform.cpp
// Functions: 11
// ============================================================

#include "game\client\cstrike15\scaleform\settings_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x10212A50
// Name: protected: virtual CSettingsScaleform::~CSettingsScaleform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSettingsScaleform::~CSettingsScaleform(CSettingsScaleform *this)
{
  CGameEventListener *v2; // edi
  IVEngineClient_vtbl *v3; // edi
  int v4; // eax
  char *v5; // eax
  CGameUI *v6; // eax
  CCStrike15BasePanel *v7; // eax
  CCStrike15BasePanel *v8; // eax
  CCStrike15BasePanel *v9; // eax
  CCStrike15BasePanel *v10; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-4h] BYREF

  v2 = &this->CGameEventListener;
  this->CControlsScaleform::ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CSettingsScaleform_vtbl *)&CSettingsScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->CControlsScaleform::IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CSettingsScaleform::`vftable'{for `IMessageBoxEventCallback'};
  this->CControlsScaleform::CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CSettingsScaleform::`vftable'{for `CGameEventListener'};
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  if ( this->m_bOptionsChanged )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iSplitScreenSlot);
    v3 = engine->__vftable;
    v4 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: (vgui::CTreeViewListControl *)engine);
    v5 = VarArgs(format: "host_writeconfig_ss %d", v4);
    v3->ClientCmd_Unrestricted(this: engine, a2: v5);
    this->m_bOptionsChanged = false;
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  v6 = GameUI();
  if ( v6->IsInLevel(this: v6) )
  {
    if ( BasePanel()->m_bScaleformPauseMenuEnabled )
    {
      v7 = BasePanel();
      CBaseModPanel::ShowMainMenu(this: v7, bShow: false);
      v8 = BasePanel();
      v8->RestorePauseMenu(this: v8);
      CControlsScaleform::~CControlsScaleform(this);
      return;
    }
  }
  else if ( BasePanel()->m_bScaleformMainMenuEnabled )
  {
    v9 = BasePanel();
    CBaseModPanel::ShowMainMenu(this: v9, bShow: false);
    v10 = BasePanel();
    v10->RestoreMainMenuScreen(this: v10);
  }
  CControlsScaleform::~CControlsScaleform(this);
}

//------------------------------------------------------------------------------
// Address: 0x10212B60
// Name: public: static void CSettingsScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSettingsScaleform::LoadDialog()
{
  CControlsScaleform *v0; // eax
  CSettingsScaleform *v1; // esi

  if ( CSettingsScaleform::m_pInstanceSettings == nullptr )
  {
    v0 = (CControlsScaleform *)MemAlloc_Alloc(nSize: 0xB0u);
    v1 = (CSettingsScaleform *)v0;
    if ( v0 != nullptr )
    {
      CControlsScaleform::CControlsScaleform(this: v0);
      v1->CControlsScaleform::CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CSettingsScaleform::`vftable'{for `CGameEventListener'};
      v1->CControlsScaleform::ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CSettingsScaleform_vtbl *)&CSettingsScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
      v1->CControlsScaleform::IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CSettingsScaleform::`vftable'{for `IMessageBoxEventCallback'};
      v1->m_bRegisteredForEvents = true;
      gameeventmanager->AddListener(
        this: gameeventmanager,
        a2: &v1->CGameEventListener,
        a3: "cs_game_disconnected",
        a4: false);
    }
    else
    {
      v1 = nullptr;
    }
    CSettingsScaleform::m_pInstanceSettings = v1;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "SettingsMenu",
      a4: (ScaleformUIFunctionHandlerObject *)v1,
      a5: pScaleformFunctionHandler_CSettingsScaleform_SettingsMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212BE0
// Name: public: static void CSettingsScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSettingsScaleform::UnloadDialog()
{
  if ( CSettingsScaleform::m_pInstanceSettings != nullptr )
    CControlsScaleform::Hide(this: CSettingsScaleform::m_pInstanceSettings);
}

//------------------------------------------------------------------------------
// Address: 0x10212BF0
// Name: public: static void CSettingsScaleform::ShowMenu(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSettingsScaleform::ShowMenu(bool bShow)
{
  if ( !bShow || CSettingsScaleform::m_pInstanceSettings != nullptr )
  {
    if ( bShow != CSettingsScaleform::m_pInstanceSettings->m_bVisible )
    {
      if ( bShow )
        CControlsScaleform::Show(this: CSettingsScaleform::m_pInstanceSettings);
      else
        CControlsScaleform::Hide(this: CSettingsScaleform::m_pInstanceSettings);
    }
  }
  else
  {
    CSettingsScaleform::LoadDialog();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212C30
// Name: public: virtual void CSettingsScaleform::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSettingsScaleform::FireGameEvent(CSettingsScaleform *this, IGameEvent *event)
{
  const char *v2; // eax

  v2 = event->GetName(this: event);
  if ( _V_strcmp(s1: v2, s2: "cs_game_disconnected") == 0 && CSettingsScaleform::m_pInstanceSettings != nullptr )
    CControlsScaleform::Hide(this: CSettingsScaleform::m_pInstanceSettings);
}

//------------------------------------------------------------------------------
// Address: 0x10212C70
// Name: public: virtual void CSettingsScaleform::OnResetToDefaults(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSettingsScaleform::OnResetToDefaults(CSettingsScaleform *this, IScaleformUI *pui, IScaleformUI *obj)
{
  IMessageBoxEventCallback *v4; // edi
  CCStrike15BasePanel *v5; // eax

  if ( this != nullptr )
    v4 = &this->IMessageBoxEventCallback;
  else
    v4 = nullptr;
  v5 = BasePanel();
  v5->OnOpenMessageBox(
    this: v5,
    a2: "#SFUI_Settings_Confirm_Title",
    a3: "#SFUI_Settings_Confirm_Msg",
    a4: "#SFUI_Settings_Confirm_Nav",
    a5: 15u,
    a6: v4,
    a7: &this->m_pConfirmDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10212D00
// Name: public: void CSettingsScaleform::OnResizeVertical(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSettingsScaleform::OnResizeVertical(CSettingsScaleform *this, IScaleformUI *pui, void *obj)
{
  int v3; // esi
  const char *Default; // eax
  float v5; // xmm1_4
  int GameUIActiveSplitScreenPlayerSlot; // eax
  int v7; // [esp+8h] [ebp-18h]
  CGameUIConVarRef varOption; // [esp+Ch] [ebp-14h] BYREF
  float fNewSafe; // [esp+1Ch] [ebp-4h]
  float objb; // [esp+2Ch] [ebp+Ch]
  float obja; // [esp+2Ch] [ebp+Ch]

  v3 = (int)((double (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Params_GetArgAsNumber)(
              a1: this->m_pScaleformUI,
              a2: obj);
  CGameUIConVarRef::CGameUIConVarRef(this: &varOption, pName: "safezoney");
  fNewSafe = (float)((float)v3 * 0.0049999999)
           + varOption.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_fValue;
  Default = ConVar::GetDefault(this: varOption.m_Info[0].m_pConVarState);
  objb = V_atof(str: Default);
  v5 = objb;
  if ( objb > fNewSafe || (v5 = 1.0, fNewSafe > 1.0) )
    obja = v5;
  else
    obja = fNewSafe;
  GameUIActiveSplitScreenPlayerSlot = GetGameUIActiveSplitScreenPlayerSlot();
  ((void (__stdcall *)(_DWORD, int))varOption.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar->SetValue_3)(
    a1: LODWORD(obja),
    a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10212DB0
// Name: public: void CSettingsScaleform::OnResizeHorizontal(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSettingsScaleform::OnResizeHorizontal(CSettingsScaleform *this, IScaleformUI *pui, void *obj)
{
  int v3; // esi
  const char *Default; // eax
  float v5; // xmm1_4
  int GameUIActiveSplitScreenPlayerSlot; // eax
  int v7; // [esp+8h] [ebp-18h]
  CGameUIConVarRef varOption; // [esp+Ch] [ebp-14h] BYREF
  float fNewSafe; // [esp+1Ch] [ebp-4h]
  float objb; // [esp+2Ch] [ebp+Ch]
  float obja; // [esp+2Ch] [ebp+Ch]

  v3 = (int)((double (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Params_GetArgAsNumber)(
              a1: this->m_pScaleformUI,
              a2: obj);
  CGameUIConVarRef::CGameUIConVarRef(this: &varOption, pName: "safezonex");
  fNewSafe = (float)((float)v3 * 0.0049999999)
           + varOption.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_fValue;
  Default = ConVar::GetDefault(this: varOption.m_Info[0].m_pConVarState);
  objb = V_atof(str: Default);
  v5 = objb;
  if ( objb > fNewSafe || (v5 = 1.0, fNewSafe > 1.0) )
    obja = v5;
  else
    obja = fNewSafe;
  GameUIActiveSplitScreenPlayerSlot = GetGameUIActiveSplitScreenPlayerSlot();
  ((void (__stdcall *)(_DWORD, int))varOption.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar->SetValue_3)(
    a1: LODWORD(obja),
    a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10212E60
// Name: protected: virtual void CSettingsScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSettingsScaleform::FlashReady(CSettingsScaleform *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  IScaleformUI *m_pScaleformUI; // ecx
  int m_iSplitScreenSlot; // eax
  IScaleformUI *v6; // ecx
  void *m_FlashAPI; // eax
  void *v8; // edi
  void *v9; // ebx
  void *v10; // edi
  ISFTextObject *v11; // eax
  IScaleformUI *v12; // ecx
  ISFTextObject *v13; // ebx
  void (__thiscall *ReleaseValue)(IScaleformUI *, void *); // edx
  IMatchSystem *v15; // eax
  int *v16; // eax
  int v17; // edi
  vgui::CTreeViewListControl *v18; // ecx
  int v19; // eax
  int v20; // eax
  const char *v21; // eax
  vgui::ILocalize_vtbl *v22; // edi
  int v23; // eax
  int v24; // edi
  ISFTextObject **m_rgTextBySlot; // ebx
  wchar_t wcTitle[128]; // [esp+4h] [ebp-154h] BYREF
  char szLabelName[64]; // [esp+104h] [ebp-54h] BYREF
  ISFTextObject *pTitleText; // [esp+144h] [ebp-14h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+148h] [ebp-10h] BYREF
  void *topPanel; // [esp+14Ch] [ebp-Ch]
  void *panel; // [esp+150h] [ebp-8h]
  void *textPanel; // [esp+154h] [ebp-4h]

  if ( this->m_FlashAPI != nullptr && this->m_pScaleformUI != nullptr )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iSplitScreenSlot);
    m_pScaleformUI = this->m_pScaleformUI;
    m_iSplitScreenSlot = this->m_iSplitScreenSlot;
    if ( m_pScaleformUI != nullptr )
    {
      if ( m_iSplitScreenSlot == -1 )
        m_iSplitScreenSlot = this->m_iFlashSlot - 2;
      m_pScaleformUI->LockInputToSlot(this: m_pScaleformUI, a2: m_iSplitScreenSlot);
    }
    v6 = this->m_pScaleformUI;
    m_FlashAPI = this->m_FlashAPI;
    this->m_bLoading = false;
    v8 = v6->Value_GetMember(this: v6, a2: m_FlashAPI, a3: "TopPanel");
    topPanel = v8;
    if ( v8 != nullptr )
    {
      v9 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))this->m_pScaleformUI->Value_GetMember)(
                     a1: this->m_pScaleformUI,
                     a2: v8,
                     a3: "Panel",
                     a4: a2);
      panel = v9;
      if ( v9 != nullptr )
      {
        v10 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))this->m_pScaleformUI->Value_GetMember)(
                        a1: this->m_pScaleformUI,
                        a2: v9,
                        a3: "TitleText",
                        a4: a3);
        if ( v10 != nullptr )
        {
          v11 = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                  this: this->m_pScaleformUI,
                  a2: v10,
                  a3: "Title");
          v12 = this->m_pScaleformUI;
          v13 = v11;
          ReleaseValue = v12->ReleaseValue;
          pTitleText = v11;
          ReleaseValue(this: v12, a2: v10);
          if ( v13 != nullptr )
          {
            v15 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
            v16 = (int *)v15->GetPlayerManager(this: v15);
            v17 = *v16;
            textPanel = v16;
            v19 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v18);
            v20 = (*(int (__thiscall **)(void *, int))(v17 + 4))(a1: textPanel, a2: v19);
            if ( v20 == 0 || (v21 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 8))(a1: v20)) == nullptr )
              v21 = "Player1";
            g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v21, a3: (wchar_t *)szLabelName, a4: 64);
            wcTitle[0] = 0;
            v22 = g_pVGuiLocalize->__vftable;
            v23 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, char *, _DWORD))g_pVGuiLocalize->Find)(
                    a1: g_pVGuiLocalize,
                    a2: "#SFUI_Settings_Title",
                    a3: 1,
                    a4: szLabelName,
                    a5: *(_DWORD *)wcTitle);
            ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v22->ConstructString_3)(
              a1: g_pVGuiLocalize,
              a2: wcTitle,
              a3: 256,
              a4: v23);
            v13->SetText(this: v13, a2: wcTitle);
            ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &pTitleText);
          }
          v9 = panel;
        }
        textPanel = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v9, a3: "ControlText");
        if ( textPanel != nullptr )
        {
          v24 = 0;
          m_rgTextBySlot = this->m_rgTextBySlot;
          do
          {
            V_snprintf(pDest: szLabelName, maxLen: 0x40u, pFormat: "Control_%i_Text", v24);
            *m_rgTextBySlot = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                this: this->m_pScaleformUI,
                                a2: textPanel,
                                a3: szLabelName);
            ++v24;
            ++m_rgTextBySlot;
          }
          while ( v24 < 13 );
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: textPanel);
          v9 = panel;
        }
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v9);
        v8 = topPanel;
      }
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v8);
    }
    CControlsScaleform::ReadOptionsFromFile(this, szFileName: "scripts/game_options.txt");
    CControlsScaleform::LayoutDialog(this, nVecOptionsOffset: 0);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102130A0
// Name: protected: virtual void CSettingsScaleform::ResetToDefaults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSettingsScaleform::ResetToDefaults(CSettingsScaleform *this)
{
  int v2; // eax
  CControlsScaleform::Option_t *v3; // esi
  CControlsScaleform::OptionType_e m_Type; // eax
  const char *Default; // ebx
  int GameUIActiveSplitScreenPlayerSlot; // eax
  const char *v7; // ebx
  int v8; // eax
  CGameUIConVarRef v9; // [esp+4h] [ebp-24h] BYREF
  CGameUIConVarRef varOption; // [esp+14h] [ebp-14h] BYREF
  int iOption; // [esp+24h] [ebp-4h]

  v2 = 0;
  this->m_bOptionsChanged = true;
  for ( iOption = 0; v2 < this->m_vecOptions.m_Size; iOption = v2 )
  {
    v3 = this->m_vecOptions.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      m_Type = v3->m_Type;
      if ( m_Type == OPTION_TYPE_CHOICE )
      {
        if ( v3 != (CControlsScaleform::Option_t *)-142 )
        {
          CGameUIConVarRef::CGameUIConVarRef(this: &varOption, pName: v3->m_szConVar);
          Default = ConVar::GetDefault(this: varOption.m_Info[0].m_pConVarState);
          GameUIActiveSplitScreenPlayerSlot = GetGameUIActiveSplitScreenPlayerSlot();
          varOption.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar->SetValue_4(
            this: varOption.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar,
            a2: Default);
          v3[1].__vftable = (CControlsScaleform::Option_t_vtbl *)-1;
          CControlsScaleform::SetChoiceWithConVar(this, pOption: (CControlsScaleform::OptionChoice_t *)v3);
        }
      }
      else if ( m_Type != OPTION_TYPE_SLIDER )
      {
        if ( m_Type == OPTION_TYPE_BIND )
          CControlsScaleform::UnbindOption(this, pOptionBind: (const CControlsScaleform::OptionBind_t *const)v3);
      }
      else if ( v3 != (CControlsScaleform::Option_t *)-142 )
      {
        CGameUIConVarRef::CGameUIConVarRef(this: &v9, pName: v3->m_szConVar);
        v7 = ConVar::GetDefault(this: v9.m_Info[0].m_pConVarState);
        v8 = GetGameUIActiveSplitScreenPlayerSlot();
        v9.m_Info[v8].m_pConVar->SetValue_4(this: v9.m_Info[v8].m_pConVar, a2: v7);
        CControlsScaleform::SetSliderWithConVar(this, pOption: (CControlsScaleform::OptionSlider_t *)v3);
      }
    }
    v2 = iOption + 1;
  }
  CControlsScaleform::LayoutDialog(this, nVecOptionsOffset: this->m_nScrollPos);
}

//------------------------------------------------------------------------------
// Address: 0x10213190
// Name: public: virtual void CSettingsScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSettingsScaleform::PostUnloadFlash(CSettingsScaleform *this)
{
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockInput(this: this->m_pScaleformUI);
  if ( CSettingsScaleform::m_pInstanceSettings != nullptr )
  {
    CUtlVector<CControlsScaleform::Option_t *,CUtlMemory<CControlsScaleform::Option_t *,int>>::PurgeAndDeleteElements(this: &CSettingsScaleform::m_pInstanceSettings->m_vecOptions);
    ((void (__thiscall *)(CSettingsScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
      a1: this,
      a2: 1);
    CSettingsScaleform::m_pInstanceSettings = nullptr;
  }
}
