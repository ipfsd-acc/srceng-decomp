// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudhealtharmorpanel.cpp
// Functions: 10
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudhealtharmorpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1021A4B0
// Name: protected: void SFHudHealthArmorPanel::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudHealthArmorPanel::ShowPanel(SFHudHealthArmorPanel *this, bool value)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  void *m_FlashAPI; // eax
  IScaleformUI_vtbl *v6; // edx

  for ( i = 1; ; i = 0 )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    if ( i == 0 )
      break;
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    m_FlashAPI = this->m_FlashAPI;
    if ( m_FlashAPI != nullptr )
    {
      v6 = this->m_pScaleformUI->SFHudFlashInterface::ScaleformFlashInterfaceMixin<CHudElement>::__vftable;
      if ( value )
        ((void (__stdcall *)(void *, const char *, _DWORD, _DWORD))v6->Value_InvokeWithoutReturn)(
          a1: m_FlashAPI,
          a2: "showNow",
          a3: 0,
          a4: 0);
      else
        ((void (__stdcall *)(void *, const char *, _DWORD, _DWORD))v6->Value_InvokeWithoutReturn)(
          a1: m_FlashAPI,
          a2: "hideNow",
          a3: 0,
          a4: 0);
    }
    this->m_PrevHealth = -1;
    this->m_PrevArmor = -1;
  }
  if ( m_pScaleformUI != nullptr )
    m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1021A520
// Name: public: virtual void SFHudHealthArmorPanel::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudHealthArmorPanel::FlashReady(SFHudHealthArmorPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  void *v4; // eax
  void *v5; // ebx
  IScaleformUI *m_pScaleformUI; // edi
  int v7; // eax
  IScaleformUI *v8; // edi
  int v9; // eax
  void *v10; // edi
  void *v11; // eax
  IScaleformUI *v12; // ecx
  void *v13; // eax
  IScaleformUI *v14; // ecx
  void *v17; // [esp+4h] [ebp-4h]
  void *v18; // [esp+4h] [ebp-4h]

  v4 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "HudPanel");
  this->m_PanelHandle = v4;
  if ( v4 != nullptr )
  {
    v5 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v4, a3: "HealthArmorPanel");
    if ( v5 != nullptr )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      v7 = ((int (__thiscall *)(IScaleformUI *, void *, const char *, int, int))m_pScaleformUI->Value_GetMember)(
             a1: m_pScaleformUI,
             a2: v5,
             a3: "Health",
             a4: a3,
             a5: a2);
      v17 = (void *)v7;
      if ( v7 != 0 )
      {
        this->m_HealthTextHandle = m_pScaleformUI->Value_GetMember(this: m_pScaleformUI, a2: (void *)v7, a3: "TextBox");
        m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: v17);
      }
      v8 = this->m_pScaleformUI;
      v9 = (int)v8->Value_GetMember(this: v8, a2: v5, a3: "Armor");
      v18 = (void *)v9;
      if ( v9 != 0 )
      {
        this->m_ArmorTextHandle = v8->Value_GetMember(this: v8, a2: (void *)v9, a3: "TextBox");
        v8->ReleaseValue(this: v8, a2: v18);
      }
      v10 = (void *)((int (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Value_GetMember)(
                      a1: this->m_pScaleformUI,
                      a2: v5);
      if ( v10 != nullptr )
      {
        v11 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v10, a3: "HealthBar");
        v12 = this->m_pScaleformUI;
        this->m_HealthBarHandle = v11;
        v13 = v12->Value_GetMember(this: v12, a2: v10, a3: "HealthBarRed");
        v14 = this->m_pScaleformUI;
        this->m_HealthRedBarHandle = v13;
        v14->ReleaseValue(this: v14, a2: v10);
      }
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v5);
    }
  }
  SFHudHealthArmorPanel::SetVisible(this, bVisible: false);
}

//------------------------------------------------------------------------------
// Address: 0x1021A660
// Name: public: virtual bool SFHudHealthArmorPanel::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudHealthArmorPanel::PreUnloadFlash(SFHudHealthArmorPanel *this)
{
  if ( this->m_pScaleformUI != nullptr )
  {
    if ( this->m_PanelHandle != nullptr )
    {
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_PanelHandle);
      this->m_PanelHandle = nullptr;
    }
    if ( this->m_pScaleformUI != nullptr )
    {
      if ( this->m_HealthTextHandle != nullptr )
      {
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_HealthTextHandle);
        this->m_HealthTextHandle = nullptr;
      }
      if ( this->m_pScaleformUI != nullptr )
      {
        if ( this->m_ArmorTextHandle != nullptr )
        {
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_ArmorTextHandle);
          this->m_ArmorTextHandle = nullptr;
        }
        if ( this->m_pScaleformUI != nullptr )
        {
          if ( this->m_HealthBarHandle != nullptr )
          {
            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_HealthBarHandle);
            this->m_HealthBarHandle = nullptr;
          }
          if ( this->m_pScaleformUI != nullptr && this->m_HealthRedBarHandle != nullptr )
          {
            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_HealthRedBarHandle);
            this->m_HealthRedBarHandle = nullptr;
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021A700
// Name: public: virtual void SFHudHealthArmorPanel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudHealthArmorPanel::SetActive(SFHudHealthArmorPanel *this, bool bActive)
{
  if ( bActive != this->m_bActive )
    SFHudHealthArmorPanel::ShowPanel(this, value: bActive);
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x1021A730
// Name: public: virtual void SFHudHealthArmorPanel::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudHealthArmorPanel::ProcessInput(
        SFHudHealthArmorPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>)
{
  int v4; // ebx
  C_CSPlayer *LocalPlayer; // edi
  int (__thiscall *GetMaxHealth)(C_BaseEntity *); // edx
  int m_PrevHealth; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  void *m_HealthTextHandle; // eax
  char v11; // bl
  void *m_HealthBarHandle; // eax
  void *m_HealthRedBarHandle; // eax
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  IScaleformUI *v15; // ecx
  void *v16; // eax
  void *v17; // eax
  IScaleformUI *v18; // ecx
  void *m_ArmorTextHandle; // eax
  IScaleformUI *v20; // ecx
  void *v21; // edi
  int v22; // eax
  bool v23; // zf
  IScaleformUI *v24; // ecx
  char cNewStr[128]; // [esp+1Ch] [ebp-94h] BYREF
  float healthPercent; // [esp+9Ch] [ebp-14h]
  float bTurnHealthRed; // [esp+A0h] [ebp-10h]
  int realArmor; // [esp+A4h] [ebp-Ch]
  int realHealth; // [esp+A8h] [ebp-8h]
  bool bSlotIsLocked; // [esp+AFh] [ebp-1h]

  v4 = 0;
  realHealth = 0;
  realArmor = 0;
  healthPercent = 0.0;
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    if ( LocalPlayer->GetHealth(this: LocalPlayer) <= 0 )
      realHealth = 0;
    else
      realHealth = LocalPlayer->GetHealth(this: LocalPlayer);
    if ( C_CSPlayer::ArmorValue(this: LocalPlayer) <= 0 )
      realArmor = 0;
    else
      realArmor = C_CSPlayer::ArmorValue(this: LocalPlayer);
    GetMaxHealth = LocalPlayer->GetMaxHealth;
    bTurnHealthRed = (float)realHealth;
    v4 = realArmor;
    healthPercent = (float)realHealth / (float)GetMaxHealth(this: LocalPlayer);
  }
  m_PrevHealth = this->m_PrevHealth;
  bSlotIsLocked = false;
  if ( m_PrevHealth != realHealth )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    bSlotIsLocked = true;
    V_snprintf(pDest: cNewStr, maxLen: 0x80u, pFormat: "%d", realHealth);
    m_HealthTextHandle = this->m_HealthTextHandle;
    if ( m_HealthTextHandle != nullptr )
      this->m_pScaleformUI->Value_SetText_2(this: this->m_pScaleformUI, a2: m_HealthTextHandle, a3: cNewStr);
    v11 = 0;
    LOBYTE(bTurnHealthRed) = 0;
    if ( realHealth < this->m_PrevHealth )
    {
      v11 = 1;
      LOBYTE(bTurnHealthRed) = 1;
      if ( healthPercent > 0.2 )
      {
        CountdownTimer::Start(this: &this->m_HealthFlashTimer, duration: 1.0);
      }
      else if ( this->m_HealthFlashTimer.m_timestamp.m_Value != -1.0 )
      {
        this->m_HealthFlashTimer.NetworkStateChanged(
          this: &this->m_HealthFlashTimer,
          a2: &this->m_HealthFlashTimer.m_timestamp);
        this->m_HealthFlashTimer.m_timestamp.m_Value = -1.0;
      }
    }
    m_HealthBarHandle = this->m_HealthBarHandle;
    if ( m_HealthBarHandle != nullptr )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_HealthBarHandle, a3: v11 == 0);
    m_HealthRedBarHandle = this->m_HealthRedBarHandle;
    if ( m_HealthRedBarHandle != nullptr )
      this->m_pScaleformUI->Value_SetVisible(
        this: this->m_pScaleformUI,
        a2: m_HealthRedBarHandle,
        a3: LODWORD(bTurnHealthRed));
    v4 = realArmor;
  }
  p_m_timestamp = &this->m_HealthFlashTimer.m_timestamp;
  if ( this->m_HealthFlashTimer.m_timestamp.m_Value > 0.0 )
  {
    if ( CountdownTimer::Now(this: (CEffectsClient *)&this->m_HealthFlashTimer) > this->m_HealthFlashTimer.m_timestamp.m_Value )
    {
      if ( !bSlotIsLocked )
      {
        v15 = this->m_pScaleformUI;
        if ( v15 != nullptr )
          v15->LockSlot(this: v15, a2: this->m_iFlashSlot);
        bSlotIsLocked = true;
      }
      if ( p_m_timestamp->m_Value != -1.0 )
      {
        this->m_HealthFlashTimer.NetworkStateChanged(
          this: &this->m_HealthFlashTimer,
          a2: &this->m_HealthFlashTimer.m_timestamp);
        p_m_timestamp->m_Value = -1.0;
      }
      v16 = this->m_HealthBarHandle;
      if ( v16 != nullptr )
        this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: v16, a3: true);
      v17 = this->m_HealthRedBarHandle;
      if ( v17 != nullptr )
        this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: v17, a3: false);
    }
    v4 = realArmor;
  }
  if ( this->m_PrevArmor != v4 )
  {
    if ( !bSlotIsLocked )
    {
      v18 = this->m_pScaleformUI;
      if ( v18 != nullptr )
        v18->LockSlot(this: v18, a2: this->m_iFlashSlot);
      bSlotIsLocked = true;
    }
    V_snprintf(pDest: cNewStr, maxLen: 0x80u, pFormat: "%d", v4);
    m_ArmorTextHandle = this->m_ArmorTextHandle;
    if ( m_ArmorTextHandle != nullptr )
      this->m_pScaleformUI->Value_SetText_2(this: this->m_pScaleformUI, a2: m_ArmorTextHandle, a3: cNewStr);
  }
  if ( (this->m_PrevHealth != realHealth || this->m_PrevArmor != v4) && this->m_FlashAPI != nullptr )
  {
    if ( !bSlotIsLocked )
    {
      v20 = this->m_pScaleformUI;
      if ( v20 != nullptr )
        v20->LockSlot(this: v20, a2: this->m_iFlashSlot);
      bSlotIsLocked = true;
    }
    v21 = (void *)((int (__thiscall *)(IScaleformUI *, int, int, int, int))this->m_pScaleformUI->CreateValueArray)(
                    a1: this->m_pScaleformUI,
                    a2: 2,
                    a3,
                    a4,
                    a5: a2);
    v22 = realHealth;
    if ( realHealth >= 1 )
    {
      if ( realHealth > 100 )
        v22 = 100;
    }
    else
    {
      v22 = 1;
    }
    this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v21, a3: 0, a4: v22);
    ((void (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->ValueArray_SetElement_5)(a1: this->m_pScaleformUI);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "updateValues",
      a4: v21,
      a5: 2u);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v21, a3: 2u);
  }
  v23 = !bSlotIsLocked;
  this->m_PrevHealth = realHealth;
  this->m_PrevArmor = v4;
  if ( !v23 )
  {
    v24 = this->m_pScaleformUI;
    if ( v24 != nullptr )
      v24->UnlockSlot(this: v24, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021AAB0
// Name: public: virtual void SFHudHealthArmorPanel::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudHealthArmorPanel::LevelInit(SFHudHealthArmorPanel *this)
{
  float m_Value; // xmm0_4
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi

  if ( this->m_bFlashAPIIsValid )
    SFHudHealthArmorPanel::SetVisible(this, bVisible: false);
  else
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "HealthArmorModule",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudHealthArmorPanel_HealthArmorModule);
  this->m_PrevHealth = -1;
  this->m_PrevArmor = -1;
  m_Value = this->m_HealthFlashTimer.m_timestamp.m_Value;
  p_m_timestamp = &this->m_HealthFlashTimer.m_timestamp;
  if ( m_Value != -1.0 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-2].m_Value) + 4))(
      a1: p_m_timestamp - 2,
      a2: p_m_timestamp);
    p_m_timestamp->m_Value = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021AB20
// Name: public: SFHudHealthArmorPanel::SFHudHealthArmorPanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudHealthArmorPanel *__thiscall SFHudHealthArmorPanel::SFHudHealthArmorPanel(
        SFHudHealthArmorPanel *this,
        const char *value)
{
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx

  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->m_HudRenderGroups.m_Memory.m_pMemory = nullptr;
  this->m_HudRenderGroups.m_Memory.m_nAllocationCount = 0;
  this->m_HudRenderGroups.m_Memory.m_nGrowSize = 0;
  this->m_HudRenderGroups.m_Size = 0;
  this->m_HudRenderGroups.m_pElements = nullptr;
  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->__vftable = (SFHudHealthArmorPanel_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudHealthArmorPanel_vtbl *)&SFHudHealthArmorPanel::`vftable';
  this->m_PanelHandle = nullptr;
  this->m_HealthTextHandle = nullptr;
  this->m_ArmorTextHandle = nullptr;
  this->m_HealthBarHandle = nullptr;
  this->m_HealthRedBarHandle = nullptr;
  this->m_PrevHealth = -1;
  this->m_PrevArmor = -1;
  this->m_HealthFlashTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v3 = this->m_HealthFlashTimer.__vftable;
  this->m_HealthFlashTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v3->NetworkStateChanged)(a1: &this->m_HealthFlashTimer.m_duration);
  v4 = this->m_HealthFlashTimer.__vftable;
  this->m_HealthFlashTimer.m_timestamp.m_Value = -1.0;
  v4->NetworkStateChanged(this: &this->m_HealthFlashTimer, a2: &this->m_HealthFlashTimer.m_timestamp);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)8);
  if ( this->m_HealthFlashTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_HealthFlashTimer.NetworkStateChanged(
      this: &this->m_HealthFlashTimer,
      a2: &this->m_HealthFlashTimer.m_timestamp);
    this->m_HealthFlashTimer.m_timestamp.m_Value = -1.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1021AC00
// Name: Create_SFHudHealthArmorPanel
// Source: json
//------------------------------------------------------------------------------
SFHudHealthArmorPanel *__cdecl Create_SFHudHealthArmorPanel()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 112);
  memset(dst: v0, value: 0, count: 0x70u);
  if ( v0 != nullptr )
    return SFHudHealthArmorPanel::SFHudHealthArmorPanel(
             this: (SFHudHealthArmorPanel *)v0,
             value: "SFHudHealthArmorPanel");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102251D0
// Name: protected: void SFHudHealthArmorPanel::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudHealthArmorPanel::SetVisible(SFHudHealthArmorPanel *this, BOOL bVisible)
{
  char i; // al
  void *v4; // edi

  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    if ( this->m_FlashAPI != nullptr )
    {
      v4 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v4, a3: 0, a4: bVisible);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "setVisible",
        a4: v4,
        a5: 1u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v4, a3: 1u);
    }
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10225D50
// Name: public: virtual void SFHudHealthArmorPanel::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudHealthArmorPanel::Init(SFHudHealthArmorPanel *this)
{
  SFHudHealthArmorPanel::SetVisible(this, bVisible: true);
}
