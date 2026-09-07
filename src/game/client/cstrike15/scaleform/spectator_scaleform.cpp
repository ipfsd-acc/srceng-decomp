// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/spectator_scaleform.cpp
// Functions: 17
// ============================================================

#include "game\client\cstrike15\scaleform\spectator_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x102131D0
// Name: public: virtual void SFSpectator::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::PostUnloadFlash(SFSpectator *this)
{
  this->m_bShowRequest = false;
  *(_WORD *)&this->m_bVisible = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102131E0
// Name: public: void SFSpectator::SwitchTarget(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::SwitchTarget(SFSpectator *this, IScaleformUI *pui, void *obj)
{
  bool v4; // zf
  void (__thiscall *ClientCmd)(IVEngineClient *, const char *); // edx
  int v6; // [esp+0h] [ebp-8h]
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_nSplitScreenSlot);
  v4 = ((unsigned __int8 (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Params_GetArgAsBool)(
         a1: this->m_pScaleformUI,
         a2: obj) == 0;
  ClientCmd = engine->ClientCmd;
  if ( v4 )
    ((void (__stdcall *)(const char *, int))ClientCmd)(a1: "spec_prev", a2: v6);
  else
    ((void (__stdcall *)(const char *, int))ClientCmd)(a1: "spec_next", a2: v6);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10213240
// Name: public: void SFSpectator::SwitchMode(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::SwitchMode(SFSpectator *this, IScaleformUI *pui, void *obj)
{
  int v3; // esi
  C_BasePlayer *LocalPlayer; // eax
  int v5; // eax
  char szCommand[32]; // [esp+4h] [ebp-24h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+24h] [ebp-4h] BYREF

  v3 = 0;
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_nSplitScreenSlot);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v5 = LocalPlayer->GetObserverMode(this: LocalPlayer);
    v3 = v5;
    if ( v5 == 4 )
    {
      v3 = 5;
    }
    else if ( v5 == 5 )
    {
      v3 = 4;
    }
  }
  V_snprintf(pDest: szCommand, maxLen: 0x20u, pFormat: "spec_mode %i", v3);
  engine->ClientCmd(this: engine, a2: szCommand);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102132C0
// Name: public: void SFSpectator::ShowGamerCard(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::ShowGamerCard(SFSpectator *this, IScaleformUI *pui, void *obj)
{
  C_CSPlayer *LocalPlayer; // eax
  player_info_s playerInfo; // [esp+4h] [ebp-90h] BYREF

  if ( g_PR == nullptr
    || this->m_nTargetID == -1
    || g_PR->IsFakePlayer(this: &g_PR->IGameResources, a2: this->m_nTargetID) )
  {
    LocalPlayer = CClientTools::GetLocalPlayer();
    if ( LocalPlayer != nullptr && LocalPlayer->m_bCanControlObservedBot )
      engine->ClientCmd(this: engine, a2: "bot_take_control");
  }
  else
  {
    engine->GetPlayerInfo(this: engine, a2: this->m_nTargetID, a3: &playerInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213340
// Name: public: void SFSpectator::ShowScoreboard(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::ShowScoreboard(SFSpectator *this, IScaleformUI *pui, void *obj)
{
  IViewPort *ViewPortInterface; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+0h] [ebp-4h] BYREF

  g_UISSGuard.m_nSaveSlot = (int)this;
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_nSplitScreenSlot);
  if ( GetViewPortInterface() != nullptr )
  {
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "scores", a3: true);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10213390
// Name: public: void SFSpectator::Unload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::Unload(SFSpectator *this)
{
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_nSplitScreenSlot);
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->CGameEventListener);
    this->m_bRegisteredForEvents = false;
  }
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTextNavigation);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTextTargetHealth);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTextTargetArmor);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTextFollowing);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTextTargetName);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10213410
// Name: public: void SFSpectator::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::Show(SFSpectator *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IGameResources *v4; // eax
  C_CS_PlayerResource *v5; // edi
  char j; // al
  IScaleformUI *v7; // ecx
  int v8; // ebx
  void *v9; // edi
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-8h] BYREF
  C_CS_PlayerResource *pCSPR; // [esp+8h] [ebp-4h]

  if ( !this->m_bLoading )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_nSplitScreenSlot);
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
          a3: "ShowPanel",
          a4: nullptr,
          a5: 0);
      }
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      v4 = GameResources();
      if ( v4 != nullptr )
      {
        v5 = (C_CS_PlayerResource *)&v4[-608];
        pCSPR = (C_CS_PlayerResource *)&v4[-608];
        if ( v4 != (IGameResources *)2432 && this->m_nTargetID > 0 )
        {
          for ( j = 1; ; j = 0 )
          {
            v7 = this->m_pScaleformUI;
            if ( j == 0 )
              break;
            if ( v7 != nullptr )
              v7->LockSlot(this: v7, a2: this->m_iFlashSlot);
            v8 = v5->GetTeam(this: &v5->IGameResources, a2: this->m_nTargetID);
            v9 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
            this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v9, a3: 0, a4: v8);
            this->m_pScaleformUI->Value_InvokeWithoutReturn(
              this: this->m_pScaleformUI,
              a2: this->m_FlashAPI,
              a3: "SetTeamTint",
              a4: v9,
              a5: 1u);
            this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v9, a3: 1u);
            v5 = pCSPR;
          }
          if ( v7 != nullptr )
          {
            v7->UnlockSlot(this: v7, a2: this->m_iFlashSlot);
            CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
            this->m_bVisible = true;
            return;
          }
        }
      }
    }
    else
    {
      this->m_bLoading = true;
      g_pScaleformUI->RequestElement(
        this: g_pScaleformUI,
        a2: this->m_nSplitScreenSlot + 2,
        a3: "Spectator",
        a4: (ScaleformUIFunctionHandlerObject *)this,
        a5: pScaleformFunctionHandler_SFSpectator_Spectator);
    }
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  this->m_bVisible = true;
}

//------------------------------------------------------------------------------
// Address: 0x10213590
// Name: public: void SFSpectator::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::Hide(SFSpectator *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  CHud *Hud; // eax
  SFHudInfoPanel *Element; // eax
  CHud *v6; // eax
  SFHudInfoPanel *v7; // eax
  CHud *v8; // eax
  SFHudInfoPanel *v9; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

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
        a3: "HidePanel",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_nSplitScreenSlot);
    Hud = GetHud(nSlot: -1);
    Element = (SFHudInfoPanel *)CHud::FindElement(this: Hud, pName: "SFHudVoiceStatus");
    if ( Element != nullptr )
      SFHudInfoPanel::ApplyYOffset(this: Element, nOffset: 0);
    v6 = GetHud(nSlot: -1);
    v7 = (SFHudInfoPanel *)CHud::FindElement(this: v6, pName: "SFHudInfoPanel");
    if ( v7 != nullptr )
      SFHudInfoPanel::ApplyYOffset(this: v7, nOffset: 0);
    v8 = GetHud(nSlot: -1);
    v9 = (SFHudInfoPanel *)CHud::FindElement(this: v8, pName: "SFHudWinPanel");
    if ( v9 != nullptr )
      SFHudInfoPanel::ApplyYOffset(this: v9, nOffset: 0);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  this->m_bVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x10213670
// Name: public: virtual void SFSpectator::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::ShowPanel(SFSpectator *this, bool state)
{
  if ( state != LOBYTE(this->m_pTextTargetHealth) )
  {
    if ( state )
    {
      LOBYTE(this->m_pTextFollowing) = 1;
      LOBYTE(this->m_pTextTargetHealth) = 1;
    }
    else if ( LOBYTE(this->m_pTextFollowing) == 0 )
    {
      SFSpectator::Hide(this: (SFSpectator *)((char *)this - 20));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102136A0
// Name: public: virtual void SFSpectator::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFSpectator::FlashReady(SFSpectator *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  void *v4; // edi
  void *v5; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  void *v7; // ebx
  void *v8; // edi
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  void *v13; // eax
  IScaleformUI *v14; // ecx
  C_CSPlayer *LocalPlayer; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-10h] BYREF
  void *panel; // [esp+8h] [ebp-Ch] BYREF
  void *panelTargetName; // [esp+Ch] [ebp-8h] BYREF
  void *panelText; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FlashAPI != nullptr && this->m_pScaleformUI != nullptr )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_nSplitScreenSlot);
    v4 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int, int))this->m_pScaleformUI->Value_GetMember)(
                   a1: this->m_pScaleformUI,
                   a2: this->m_FlashAPI,
                   a3: "FollowingPanel",
                   a4: a3,
                   a5: a2);
    if ( v4 != nullptr )
    {
      v5 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v4, a3: "FollowText");
      panelText = v5;
      if ( v5 != nullptr )
      {
        this->m_pTextFollowing = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                   this: this->m_pScaleformUI,
                                   a2: v5,
                                   a3: "Text");
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFVALUE(this, value: &panelText);
      }
      m_pScaleformUI = this->m_pScaleformUI;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: v4);
    }
    v7 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "SpectatorMode");
    if ( v7 != nullptr )
    {
      v8 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v7, a3: "Panel");
      panel = v8;
      if ( v8 != nullptr )
      {
        v9 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v8, a3: "TargetName");
        panelTargetName = v9;
        if ( v9 != nullptr )
        {
          v10 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v9, a3: "Name_Text");
          panelText = v10;
          if ( v10 != nullptr )
          {
            this->m_pTextTargetName = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                        this: this->m_pScaleformUI,
                                        a2: v10,
                                        a3: "Text");
            ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFVALUE(this, value: &panelText);
          }
          ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFVALUE(this, value: &panelTargetName);
        }
        v11 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v8, a3: "Nav_Text");
        panelTargetName = v11;
        if ( v11 != nullptr )
        {
          this->m_pTextNavigation = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                      this: this->m_pScaleformUI,
                                      a2: v11,
                                      a3: "Text");
          ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFVALUE(this, value: &panelTargetName);
        }
        v12 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v8, a3: "Health_Text");
        panelTargetName = v12;
        if ( v12 != nullptr )
        {
          this->m_pTextTargetHealth = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                        this: this->m_pScaleformUI,
                                        a2: v12,
                                        a3: "Text");
          ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFVALUE(this, value: &panelTargetName);
        }
        v13 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v8, a3: "Armor_Text");
        panelTargetName = v13;
        if ( v13 != nullptr )
        {
          this->m_pTextTargetArmor = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                       this: this->m_pScaleformUI,
                                       a2: v13,
                                       a3: "Text");
          ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFVALUE(this, value: &panelTargetName);
        }
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFVALUE(this, value: &panel);
      }
      v14 = this->m_pScaleformUI;
      if ( v14 != nullptr )
        v14->ReleaseValue(this: v14, a2: v7);
    }
    this->m_bRegisteredForEvents = true;
    ((void (__thiscall *)(IGameEventManager2 *, CGameEventListener *))gameeventmanager->AddListener)(
      a1: gameeventmanager,
      a2: &this->CGameEventListener);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(
      this: gameeventmanager,
      a2: &this->CGameEventListener,
      a3: "cs_game_disconnected",
      a4: false);
    this->m_bLoading = false;
    SFSpectator::Hide(this);
    LocalPlayer = CClientTools::GetLocalPlayer();
    if ( LocalPlayer != nullptr && LocalPlayer->GetObserverMode(this: LocalPlayer) != 0 )
    {
      this->m_bShowRequest = true;
      this->m_bVisible = true;
    }
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213910
// Name: public: virtual bool SFSpectator::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFSpectator::PreUnloadFlash(SFSpectator *this)
{
  this->m_bLoading = true;
  SFSpectator::Unload(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10213920
// Name: public: virtual void SFSpectator::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFSpectator::FireGameEvent(
        SFSpectator *this@<ecx>,
        wchar_t *a2@<ebx>,
        int a3@<edi>,
        IGameEvent *event)
{
  const char *v5; // edi
  IGameResources *v6; // eax
  C_CS_PlayerResource *v7; // edi
  int SpectatorTarget; // eax
  char i; // al
  int (__thiscall *GetTeam)(IGameResources *, int); // edx
  int v11; // edi
  int v12; // ebx
  int v13; // eax
  vgui::ILocalize_vtbl *v14; // ebx
  wchar_t *v15; // eax
  const wchar_t *v16; // eax
  void *v17; // ebx
  int Armor; // ebx
  void *v19; // ebx
  int v20; // eax
  const wchar_t *v21; // ebx
  const wchar_t *v22; // edi
  const wchar_t *v23; // eax
  void (__thiscall *dtr_IGameEventListener2)(struct CGameEventListener *); // edi
  int v25; // eax
  C_BasePlayer *LocalPlayer; // eax
  C_BaseEntity *v27; // eax
  ISFTextObject *m_pTextTargetArmor; // [esp-8h] [ebp-BD4h]
  int v31; // [esp+0h] [ebp-BCCh]
  wchar_t navBarText[1024]; // [esp+4h] [ebp-BC8h] BYREF
  char xuidText[256]; // [esp+804h] [ebp-3C8h] BYREF
  wchar_t wcTargetNameFormatted[128]; // [esp+904h] [ebp-2C8h] BYREF
  wchar_t wcDeadAndFollowing[128]; // [esp+A04h] [ebp-1C8h] BYREF
  wchar_t wcArmor[32]; // [esp+B04h] [ebp-C8h] BYREF
  wchar_t wcHealth[32]; // [esp+B44h] [ebp-88h] BYREF
  wchar_t wcTargetName[32]; // [esp+B84h] [ebp-48h] BYREF
  C_CS_PlayerResource *pCSPR; // [esp+BC4h] [ebp-8h]
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+BC8h] [ebp-4h] BYREF
  void *dataArmora; // [esp+BD4h] [ebp+8h]
  void *dataArmorb; // [esp+BD4h] [ebp+8h]
  void *dataArmorc; // [esp+BD4h] [ebp+8h]
  void *dataArmord; // [esp+BD4h] [ebp+8h]
  const wchar_t *dataArmor; // [esp+BD4h] [ebp+8h]

  if ( *((_BYTE *)this - 8) == 0 )
    return;
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: (int)this->m_pTextTargetHealth);
  v5 = event->GetName(this: event);
  if ( _V_strcmp(s1: "spec_target_updated", s2: v5) != 0 )
  {
    if ( _V_strcmp(s1: "cs_game_disconnected", s2: v5) == 0 && *((_BYTE *)this - 8) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**((_DWORD **)this - 5) + 76))(
        a1: *((_DWORD *)this - 5),
        a2: *((_DWORD *)this - 3),
        a3: *((_DWORD *)this - 4));
    goto LABEL_37;
  }
  v6 = GameResources();
  if ( v6 == nullptr
    || (v7 = (C_CS_PlayerResource *)&v6[-608], pCSPR = (C_CS_PlayerResource *)&v6[-608], v6 == (IGameResources *)2432) )
  {
LABEL_37:
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    return;
  }
  SpectatorTarget = GetSpectatorTarget();
  this->m_pTextTargetArmor = (ISFTextObject *)SpectatorTarget;
  if ( SpectatorTarget >= 1 && SpectatorTarget <= 64 )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( *((_DWORD *)this - 5) != 0 )
        (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this - 5) + 64))(
          a1: *((_DWORD *)this - 5),
          a2: *((_DWORD *)this - 3));
      GetTeam = v7->GetTeam;
      v11 = (int)&v7->IGameResources;
      dataArmora = (void *)((int (__thiscall *)(int, ISFTextObject *, wchar_t *, int, int))GetTeam)(
                             a1: v11,
                             a2: this->m_pTextTargetArmor,
                             a3: a2,
                             a4: a3,
                             a5: v31);
      v12 = (*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this - 5) + 432))(a1: *((_DWORD *)this - 5), a2: 1);
      (*(void (__thiscall **)(_DWORD, int, _DWORD, void *))(**((_DWORD **)this - 5) + 480))(
        a1: *((_DWORD *)this - 5),
        a2: v12,
        a3: 0,
        a4: dataArmora);
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, int, int))(**((_DWORD **)this - 5) + 544))(
        a1: *((_DWORD *)this - 5),
        a2: *((_DWORD *)this - 4),
        a3: "SetTeamTint",
        a4: v12,
        a5: 1);
      (*(void (__thiscall **)(_DWORD, int, int))(**((_DWORD **)this - 5) + 436))(
        a1: *((_DWORD *)this - 5),
        a2: v12,
        a3: 1);
      v31 = 64;
      m_pTextTargetArmor = this->m_pTextTargetArmor;
      v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 32))(a1: v11);
      _V_UTF8ToUnicode(a1: v13, a2: m_pTextTargetArmor, a3: wcTargetName);
      v14 = g_pVGuiLocalize->__vftable;
      v15 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#SFUIHUD_Spectate_You_Are_Dead");
      ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, wchar_t *))v14->ConstructString_3)(
        a1: g_pVGuiLocalize,
        a2: wcDeadAndFollowing,
        a3: 256,
        a4: v15);
      (*(void (__cdecl **)(int, wchar_t *))(*(_DWORD *)this->m_nDebugID + 16))(
        a1: this->m_nDebugID,
        a2: wcDeadAndFollowing);
      v16 = L"#6e7d5c";
      if ( dataArmora != (void *)3 )
        v16 = L"#9d511b";
      V_snwprintf(
        pDest: wcTargetNameFormatted,
        maxLen: 128,
        pFormat: L"<font color=\"%s\">%s</font>",
        v16,
        wcTargetName);
      (*(void (__cdecl **)(int, wchar_t *))(*(_DWORD *)this->m_iFlashSlot + 16))(
        a1: this->m_iFlashSlot,
        a2: wcTargetNameFormatted);
      dataArmorb = (void *)(*(int (__thiscall **)(int, ISFTextObject *))(*(_DWORD *)v11 + 56))(
                             a1: v11,
                             a2: this->m_pTextTargetArmor);
      V_snwprintf(pDest: wcHealth, maxLen: 32, pFormat: L"%i", dataArmorb);
      (***(void (__cdecl ****)(_DWORD, wchar_t *))&this->m_bFlashAPIIsValid)(
        a1: *(_DWORD *)&this->m_bFlashAPIIsValid,
        a2: wcHealth);
      v17 = (void *)(*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this - 5) + 432))(
                      a1: *((_DWORD *)this - 5),
                      a2: 1);
      (*(void (__thiscall **)(_DWORD, void *, _DWORD, void *))(**((_DWORD **)this - 5) + 480))(
        a1: *((_DWORD *)this - 5),
        a2: v17,
        a3: 0,
        a4: dataArmorb);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: *((void **)this - 4),
        a3: "SetHealthBar",
        a4: v17,
        a5: 1u);
      (*(void (__thiscall **)(_DWORD, void *, int))(**((_DWORD **)this - 5) + 436))(
        a1: *((_DWORD *)this - 5),
        a2: v17,
        a3: 1);
      Armor = C_CS_PlayerResource::GetArmor(this: pCSPR, iIndex: (int)this->m_pTextTargetArmor);
      V_snwprintf(pDest: wcArmor, maxLen: 32, pFormat: L"%i", Armor);
      (*((void (__thiscall **)(IViewPortPanel_vtbl *, int))this->dtr_IViewPortPanel + 3))(
        a1: this->IViewPortPanel::__vftable,
        a2: Armor);
      dataArmorc = (void *)(*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this - 5) + 432))(
                             a1: *((_DWORD *)this - 5),
                             a2: 1);
      (*(void (__thiscall **)(_DWORD, void *, _DWORD, int))(**((_DWORD **)this - 5) + 480))(
        a1: *((_DWORD *)this - 5),
        a2: dataArmorc,
        a3: 0,
        a4: Armor);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: *((void **)this - 4),
        a3: "SetArmorBar",
        a4: dataArmorc,
        a5: 1u);
      (*(void (__thiscall **)(_DWORD, void *, int))(**((_DWORD **)this - 5) + 436))(
        a1: *((_DWORD *)this - 5),
        a2: dataArmorc,
        a3: 1);
      v19 = (void *)(*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this - 5) + 432))(
                      a1: *((_DWORD *)this - 5),
                      a2: 2);
      if ( v19 != nullptr )
      {
        C_PlayerResource::FillXuidText(this: g_PR, iIndex: (int)this->m_pTextTargetArmor, buf: xuidText, bufSize: 0xFFu);
        dataArmord = (void *)(**((_DWORD **)this - 5) + 480);
        v20 = (*(int (__thiscall **)(int, ISFTextObject *))(*(_DWORD *)v11 + 52))(a1: v11, a2: this->m_pTextTargetArmor);
        (*(void (__thiscall **)(_DWORD, void *, _DWORD, int))dataArmord)(
          a1: *((_DWORD *)this - 5),
          a2: v19,
          a3: 0,
          a4: v20);
        (*(void (__thiscall **)(_DWORD, void *, int, char *))(**((_DWORD **)this - 5) + 468))(
          a1: *((_DWORD *)this - 5),
          a2: v19,
          a3: 1,
          a4: xuidText);
        g_pScaleformUI->Value_InvokeWithoutReturn(
          this: g_pScaleformUI,
          a2: *((void **)this - 4),
          a3: "ShowAvatar",
          a4: v19,
          a5: 2u);
        (*(void (__thiscall **)(_DWORD, void *, int))(**((_DWORD **)this - 5) + 436))(
          a1: *((_DWORD *)this - 5),
          a2: v19,
          a3: 2);
      }
      v21 = &szFunFact;
      dataArmor = &szFunFact;
      if ( (*(unsigned __int8 (__thiscall **)(int, ISFTextObject *))(*(_DWORD *)v11 + 24))(
             a1: v11,
             a2: this->m_pTextTargetArmor) != 0 )
      {
        if ( CanControlSpectatedTarget(a1: v11) )
        {
          dataArmor = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#SFUIHUD_Spectate_Navigation_Control_Bot");
          if ( dataArmor == nullptr )
            dataArmor = &szFunFact;
        }
      }
      else
      {
        v21 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#SFUIHUD_Spectate_Navigation_Gamer_Card");
        if ( v21 == nullptr )
          v21 = &szFunFact;
      }
      v22 = &szFunFact;
      if ( g_pGameRules != nullptr
        && (unsigned __int8)C_CSGameRules::IsPlayingClassicCompetitive(this: (C_CSGameRules *)g_pGameRules) == 0 )
      {
        v22 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#SFUIHUD_Spectate_Navigation_Camera");
        if ( v22 == nullptr )
          v22 = &szFunFact;
      }
      v23 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#SFUIHUD_Spectate_Navigation_Scoreboard");
      if ( v23 == nullptr )
        v23 = &szFunFact;
      V_snwprintf(pDest: navBarText, maxLen: 1024, pFormat: L"%s%s%s%s", v21, dataArmor, v22, v23);
      dtr_IGameEventListener2 = this->dtr_IGameEventListener2;
      a3 = 0;
      a2 = navBarText;
      v25 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this - 5) + 236))(a1: *((_DWORD *)this - 5));
      (*((void (__cdecl **)(CGameEventListener_vtbl *, int))dtr_IGameEventListener2 + 4))(
        a1: this->CGameEventListener::IGameEventListener2::__vftable,
        a2: v25);
      v7 = pCSPR;
    }
    if ( *((_DWORD *)this - 5) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this - 5) + 68))(
        a1: *((_DWORD *)this - 5),
        a2: *((_DWORD *)this - 3));
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
      return;
    }
    goto LABEL_37;
  }
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr
    && (v27 = LocalPlayer->GetObserverTarget(this: LocalPlayer),
        __RTDynamicCast(
          inptr: v27,
          VfDelta: 0,
          SrcType: &C_BaseEntity `RTTI Type Descriptor',
          TargetType: &C_PlantedC4 `RTTI Type Descriptor',
          isReference: 0) != nullptr) )
  {
    SFSpectator::Hide(this: (SFSpectator *)((char *)this - 24));
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  else
  {
    BYTE1(this->m_pTextNavigation) = 1;
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213E50
// Name: public: virtual void SFSpectator::ViewportThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::ViewportThink(SFSpectator *this)
{
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v3; // edi
  IViewPort *ViewPortInterface; // eax
  ISFTextObject *SpectatorTarget; // eax
  CHud *Hud; // eax
  SFHudInfoPanel *Element; // eax
  CHud *v8; // eax
  SFHudInfoPanel *v9; // eax
  CHud *v10; // eax
  SFHudInfoPanel *v11; // eax
  IGameEvent *v12; // eax
  IGameEvent *v13; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+Ch] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: (int)this->m_pTextTargetArmor);
  LocalPlayer = CClientTools::GetLocalPlayer();
  v3 = LocalPlayer;
  if ( LOBYTE(this->m_pTextFollowing) != 0 )
  {
    if ( LocalPlayer != nullptr )
    {
      if ( LocalPlayer->m_iPlayerState.m_Value != STATE_ACTIVE )
      {
        if ( LocalPlayer->GetTeamNumber(this: LocalPlayer) == 0 )
        {
          LOBYTE(this->m_pTextFollowing) = 0;
          LOBYTE(this->m_pTextTargetHealth) = 0;
          ViewPortInterface = GetViewPortInterface();
          ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "team", a3: true);
        }
      }
      else if ( *((_BYTE *)this - 4) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**((_DWORD **)this - 4) + 76))(
          a1: *((_DWORD *)this - 4),
          a2: *((_DWORD *)this - 2),
          a3: *((_DWORD *)this - 3));
      }
      SpectatorTarget = (ISFTextObject *)GetSpectatorTarget();
      this->m_pTextNavigation = SpectatorTarget;
      if ( (int)SpectatorTarget > 0 && (v3->GetObserverMode(this: v3) == 4 || v3->GetObserverMode(this: v3) == 5) )
      {
        Hud = GetHud(nSlot: -1);
        Element = (SFHudInfoPanel *)CHud::FindElement(this: Hud, pName: "SFHudVoiceStatus");
        if ( Element != nullptr )
          SFHudInfoPanel::ApplyYOffset(this: Element, nOffset: -100);
        v8 = GetHud(nSlot: -1);
        v9 = (SFHudInfoPanel *)CHud::FindElement(this: v8, pName: "SFHudInfoPanel");
        if ( v9 != nullptr )
          SFHudInfoPanel::ApplyYOffset(this: v9, nOffset: -100);
        v10 = GetHud(nSlot: -1);
        v11 = (SFHudInfoPanel *)CHud::FindElement(this: v10, pName: "SFHudWinPanel");
        if ( v11 != nullptr )
          SFHudInfoPanel::ApplyYOffset(this: v11, nOffset: -150);
        SFSpectator::Show(this: (SFSpectator *)((char *)this - 20));
        v12 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "spec_target_updated", a3: 0, a4: 0);
        if ( v12 != nullptr )
          gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v12);
        LOBYTE(this->m_pTextFollowing) = 0;
      }
    }
  }
  else if ( LocalPlayer != nullptr
         && LocalPlayer->m_iPlayerState.m_Value == STATE_ACTIVE
         && LocalPlayer->GetObserverMode(this: LocalPlayer) != 4
         && v3->GetObserverMode(this: v3) != 5
         && *((_BYTE *)this - 4) != 0 )
  {
    ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::RemoveFlashElement(this: (SFSpectator *)((char *)this - 20));
  }
  if ( BYTE1(this->m_pTextFollowing) != 0 && GetSpectatorTarget() > 0 )
  {
    v13 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "spec_target_updated", a3: 0, a4: 0);
    if ( v13 != nullptr )
      gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v13);
    BYTE1(this->m_pTextFollowing) = 0;
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10214030
// Name: public: SFSpectator::SFSpectator(class CounterStrikeViewport __near *)
// Source: json
//------------------------------------------------------------------------------
SFSpectator *__thiscall SFSpectator::SFSpectator(SFSpectator *this, CounterStrikeViewport *pViewPort)
{
  this->m_bFlashAPIIsValid = false;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->m_iFlashSlot = -1;
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (SFSpectator_vtbl *)&SFSpectator::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&SFSpectator::`vftable'{for `IViewPortPanel'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&SFSpectator::`vftable'{for `CGameEventListener'};
  this->m_pTextTargetName = nullptr;
  this->m_pTextTargetHealth = nullptr;
  this->m_pTextTargetArmor = nullptr;
  this->m_pTextNavigation = nullptr;
  this->m_pTextFollowing = nullptr;
  this->m_PanelIcon = nullptr;
  *(_WORD *)&this->m_bVisible = 0;
  this->m_nTargetID = -1;
  *(_WORD *)&this->m_bShowRequest = 0;
  g_pSFSpectatorGUI = this;
  this->m_nSplitScreenSlot = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102140A0
// Name: public: virtual char const __near * SFSpectator::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SFSpectator::GetName(SFSpectator *this)
{
  return "specgui";
}

//------------------------------------------------------------------------------
// Address: 0x102140B0
// Name: public: virtual bool SFSpectator::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SFSpectator::IsVisible(SFSpectator *this)
{
  return (bool)this->m_pTextTargetHealth;
}

//------------------------------------------------------------------------------
// Address: 0x102140E0
// Name: public: virtual SFSpectator::~SFSpectator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFSpectator::~SFSpectator(SFSpectator *this)
{
  CGameEventListener *v2; // edi
  bool v3; // zf

  v2 = &this->CGameEventListener;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (SFSpectator_vtbl *)&SFSpectator::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&SFSpectator::`vftable'{for `IViewPortPanel'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&SFSpectator::`vftable'{for `CGameEventListener'};
  g_pSFSpectatorGUI = nullptr;
  v3 = !this->m_bRegisteredForEvents;
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v3 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  v2->__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  v3 = !this->m_bFlashAPIIsValid;
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (SFSpectator_vtbl *)&ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::`vftable';
  if ( !v3 )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
}
