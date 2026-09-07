// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudweaponpanel.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudweaponpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10225150
// Name: protected: void SFHudWeaponPanel::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWeaponPanel::ShowPanel(SFHudWeaponPanel *this, bool value)
{
  char v3; // al
  void *m_FlashAPI; // eax
  IScaleformUI_vtbl *v5; // edx

  v3 = 1;
  while ( v3 != 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    m_FlashAPI = this->m_FlashAPI;
    if ( m_FlashAPI != nullptr )
    {
      v5 = this->m_pScaleformUI->SFHudFlashInterface::ScaleformFlashInterfaceMixin<CHudElement>::__vftable;
      if ( !value )
      {
        ((void (__stdcall *)(void *, const char *, _DWORD, _DWORD))v5->Value_InvokeWithoutReturn)(
          a1: m_FlashAPI,
          a2: "hideNow",
          a3: 0,
          a4: 0);
        goto LABEL_9;
      }
      ((void (__stdcall *)(void *, const char *, _DWORD, _DWORD))v5->Value_InvokeWithoutReturn)(
        a1: m_FlashAPI,
        a2: "showNow",
        a3: 0,
        a4: 0);
      v3 = 0;
    }
    else
    {
LABEL_9:
      v3 = 0;
    }
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10225270
// Name: public: virtual void SFHudWeaponPanel::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudWeaponPanel::FlashReady(SFHudWeaponPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  void *v4; // eax
  void *v5; // edi
  void *v6; // eax
  IScaleformUI *m_pScaleformUI; // ebx
  int v8; // eax
  IScaleformUI *v9; // ebx
  int v10; // eax
  IScaleformUI *v11; // ebx
  int v12; // eax
  void *v13; // eax
  IScaleformUI *v14; // ecx
  void *v15; // eax
  IScaleformUI *v16; // ecx
  void *v17; // eax
  IScaleformUI *v18; // ecx
  void *v19; // eax
  IScaleformUI *v20; // ecx
  void *v21; // eax
  IScaleformUI *v22; // ecx
  void *v23; // eax
  IScaleformUI *v24; // ecx
  void *m_UpgradeKill1; // eax
  void *m_UpgradeKill2; // eax
  void *m_UpgradeKillText; // eax
  void *v29; // [esp+4h] [ebp-4h]
  void *v30; // [esp+4h] [ebp-4h]
  void *v31; // [esp+4h] [ebp-4h]

  v4 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "HudPanel");
  this->m_PanelHandle = v4;
  if ( v4 != nullptr )
  {
    v5 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v4, a3: "WeaponPanel");
    if ( v5 != nullptr )
    {
      v6 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int, int))this->m_pScaleformUI->Value_GetMember)(
                     a1: this->m_pScaleformUI,
                     a2: v5,
                     a3: "CurrentWeapon",
                     a4: a2,
                     a5: a3);
      m_pScaleformUI = this->m_pScaleformUI;
      this->m_CurrentWeaponImageHandle = v6;
      v8 = (int)m_pScaleformUI->Value_GetMember(this: m_pScaleformUI, a2: v5, a3: "WeaponText");
      v29 = (void *)v8;
      if ( v8 != 0 )
      {
        this->m_CurrentWeaponTextHandle = m_pScaleformUI->Value_GetMember(
                                            this: m_pScaleformUI,
                                            a2: (void *)v8,
                                            a3: "TextBox");
        m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: v29);
      }
      v9 = this->m_pScaleformUI;
      v10 = (int)v9->Value_GetMember(this: v9, a2: v5, a3: "AmmoCountClip");
      v30 = (void *)v10;
      if ( v10 != 0 )
      {
        this->m_AmmoTextClipHandle = v9->Value_GetMember(this: v9, a2: (void *)v10, a3: "TextBox");
        v9->ReleaseValue(this: v9, a2: v30);
      }
      v11 = this->m_pScaleformUI;
      v12 = (int)v11->Value_GetMember(this: v11, a2: v5, a3: "AmmoCountTotal");
      v31 = (void *)v12;
      if ( v12 != 0 )
      {
        this->m_AmmoTextTotalHandle = v11->Value_GetMember(this: v11, a2: (void *)v12, a3: "TextBox");
        v11->ReleaseValue(this: v11, a2: v31);
      }
      v13 = (void *)((int (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Value_GetMember)(
                      a1: this->m_pScaleformUI,
                      a2: v5);
      v14 = this->m_pScaleformUI;
      this->m_AmmoAnimationHandle = v13;
      v15 = v14->Value_GetMember(this: v14, a2: v5, a3: "Penetration1");
      v16 = this->m_pScaleformUI;
      this->m_WeaponPenetration1 = v15;
      v17 = v16->Value_GetMember(this: v16, a2: v5, a3: "Penetration2");
      v18 = this->m_pScaleformUI;
      this->m_WeaponPenetration2 = v17;
      v19 = v18->Value_GetMember(this: v18, a2: v5, a3: "Penetration3");
      v20 = this->m_pScaleformUI;
      this->m_WeaponPenetration3 = v19;
      v21 = v20->Value_GetMember(this: v20, a2: v5, a3: "Kill1");
      v22 = this->m_pScaleformUI;
      this->m_UpgradeKill1 = v21;
      v23 = v22->Value_GetMember(this: v22, a2: v5, a3: "Kill2");
      v24 = this->m_pScaleformUI;
      this->m_UpgradeKill2 = v23;
      this->m_UpgradeKillText = v24->Value_GetMember(this: v24, a2: v5, a3: "UpgradeText");
      m_UpgradeKill1 = this->m_UpgradeKill1;
      if ( m_UpgradeKill1 != nullptr )
        this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_UpgradeKill1, a3: false);
      m_UpgradeKill2 = this->m_UpgradeKill2;
      if ( m_UpgradeKill2 != nullptr )
        this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_UpgradeKill2, a3: false);
      m_UpgradeKillText = this->m_UpgradeKillText;
      if ( m_UpgradeKillText != nullptr )
        this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_UpgradeKillText, a3: false);
      ((void (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->ReleaseValue)(a1: this->m_pScaleformUI);
    }
  }
  SFHudHealthArmorPanel::SetVisible((SFHudHealthArmorPanel *)this, bVisible: false);
}

//------------------------------------------------------------------------------
// Address: 0x10225490
// Name: public: virtual bool SFHudWeaponPanel::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudWeaponPanel::PreUnloadFlash(SFHudWeaponPanel *this)
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
      if ( this->m_CurrentWeaponImageHandle != nullptr )
      {
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_CurrentWeaponImageHandle);
        this->m_CurrentWeaponImageHandle = nullptr;
      }
      if ( this->m_pScaleformUI != nullptr )
      {
        if ( this->m_CurrentWeaponTextHandle != nullptr )
        {
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_CurrentWeaponTextHandle);
          this->m_CurrentWeaponTextHandle = nullptr;
        }
        if ( this->m_pScaleformUI != nullptr )
        {
          if ( this->m_AmmoTextClipHandle != nullptr )
          {
            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_AmmoTextClipHandle);
            this->m_AmmoTextClipHandle = nullptr;
          }
          if ( this->m_pScaleformUI != nullptr )
          {
            if ( this->m_AmmoTextTotalHandle != nullptr )
            {
              this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_AmmoTextTotalHandle);
              this->m_AmmoTextTotalHandle = nullptr;
            }
            if ( this->m_pScaleformUI != nullptr )
            {
              if ( this->m_AmmoAnimationHandle != nullptr )
              {
                this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_AmmoAnimationHandle);
                this->m_AmmoAnimationHandle = nullptr;
              }
              if ( this->m_pScaleformUI != nullptr )
              {
                if ( this->m_WeaponPenetration1 != nullptr )
                {
                  this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_WeaponPenetration1);
                  this->m_WeaponPenetration1 = nullptr;
                }
                if ( this->m_pScaleformUI != nullptr )
                {
                  if ( this->m_WeaponPenetration2 != nullptr )
                  {
                    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_WeaponPenetration2);
                    this->m_WeaponPenetration2 = nullptr;
                  }
                  if ( this->m_pScaleformUI != nullptr )
                  {
                    if ( this->m_WeaponPenetration3 != nullptr )
                    {
                      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_WeaponPenetration3);
                      this->m_WeaponPenetration3 = nullptr;
                    }
                    if ( this->m_pScaleformUI != nullptr )
                    {
                      if ( this->m_UpgradeKill1 != nullptr )
                      {
                        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_UpgradeKill1);
                        this->m_UpgradeKill1 = nullptr;
                      }
                      if ( this->m_pScaleformUI != nullptr )
                      {
                        if ( this->m_UpgradeKill2 != nullptr )
                        {
                          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_UpgradeKill2);
                          this->m_UpgradeKill2 = nullptr;
                        }
                        if ( this->m_pScaleformUI != nullptr && this->m_UpgradeKillText != nullptr )
                        {
                          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_UpgradeKillText);
                          this->m_UpgradeKillText = nullptr;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10225620
// Name: public: virtual void SFHudWeaponPanel::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWeaponPanel::LevelInit(SFHudWeaponPanel *this)
{
  if ( this->m_bFlashAPIIsValid )
    SFHudHealthArmorPanel::SetVisible((SFHudHealthArmorPanel *)this, bVisible: false);
  else
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "WeaponModule",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudWeaponPanel_WeaponModule);
  this->m_PrevAmmoClipCount = -1;
  this->m_PrevAmmoTotalCount = -1;
  this->m_PrevAmmoType = -1;
  this->m_PrevWeaponID = -1;
  this->m_PrevTRGunGameUpgradePoints = 0;
  this->m_bHiddenNoAmmo = false;
}

//------------------------------------------------------------------------------
// Address: 0x10225680
// Name: public: virtual void SFHudWeaponPanel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWeaponPanel::SetActive(SFHudWeaponPanel *this, bool bActive)
{
  if ( bActive != this->m_bActive && !this->m_bHiddenNoAmmo )
    SFHudWeaponPanel::ShowPanel(this, value: bActive);
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x102256B0
// Name: public: virtual void SFHudWeaponPanel::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWeaponPanel::ProcessInput(SFHudWeaponPanel *this)
{
  C_CSPlayer *LocalPlayer; // eax
  C_BaseCombatCharacter *v3; // ebx
  int m_Value; // edi
  int m_PrevTRGunGameUpgradePoints; // eax
  void *v6; // eax
  void *m_UpgradeKill1; // eax
  void *m_UpgradeKill2; // eax
  void *m_UpgradeKillText; // eax
  void *v10; // eax
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  C_BaseCombatWeapon *v13; // edi
  int AmmoCount; // eax
  int (__thiscall *GetPrimaryAmmoType)(C_BaseCombatWeapon *); // edx
  int v16; // eax
  int v17; // eax
  int m_PrevWeaponID; // eax
  IScaleformUI *v19; // ecx
  void *m_CurrentWeaponTextHandle; // eax
  void *v21; // edi
  CCSWeaponInfo *WeaponInfo; // edi
  void *m_WeaponPenetration1; // eax
  void *m_WeaponPenetration2; // eax
  const char *v25; // ebx
  void *m_WeaponPenetration3; // eax
  bool v27; // zf
  IScaleformUI *v28; // ecx
  IScaleformUI_vtbl *v29; // edx
  IScaleformUI *v30; // ecx
  void *m_AmmoTextClipHandle; // eax
  void *m_AmmoTextTotalHandle; // eax
  void *v33; // eax
  BOOL v34; // edi
  void *v35; // eax
  IScaleformUI *v36; // ecx
  void *v37; // edi
  int v38; // edi
  int m_PrevAmmoClipCount; // eax
  IScaleformUI *v40; // ecx
  int v41; // ecx
  int v42; // edx
  IScaleformUI *v43; // ecx
  char cNewStr[128]; // [esp+8h] [ebp-A0h] BYREF
  const char *weaponName; // [esp+88h] [ebp-20h]
  const char *shortWeaponName; // [esp+8Ch] [ebp-1Ch]
  int weaponID; // [esp+90h] [ebp-18h]
  int bAmmoShown; // [esp+94h] [ebp-14h]
  int totalAmmo; // [esp+98h] [ebp-10h]
  int ammoType; // [esp+9Ch] [ebp-Ch]
  int currentClip; // [esp+A0h] [ebp-8h]
  bool bInTRBombMode; // [esp+A5h] [ebp-3h]
  bool bHideNoAmmo; // [esp+A6h] [ebp-2h]
  bool bSlotIsLocked; // [esp+A7h] [ebp-1h]

  currentClip = 0;
  totalAmmo = 0;
  ammoType = -1;
  weaponID = -1;
  weaponName = nullptr;
  shortWeaponName = nullptr;
  bInTRBombMode = false;
  bAmmoShown = -1;
  if ( C_CSGameRules::IsPlayingGunGame(this: (C_CSGameRules *)g_pGameRules) )
    bInTRBombMode = C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules);
  LocalPlayer = CClientTools::GetLocalPlayer();
  v3 = LocalPlayer;
  if ( LocalPlayer == nullptr )
    goto LABEL_47;
  if ( bInTRBombMode )
  {
    m_Value = LocalPlayer->m_iNumGunGameTRKillPoints.m_Value;
    m_PrevTRGunGameUpgradePoints = this->m_PrevTRGunGameUpgradePoints;
    bAmmoShown = m_Value;
    if ( m_PrevTRGunGameUpgradePoints != m_Value && (m_PrevTRGunGameUpgradePoints != 99 || m_Value == 0) )
    {
      switch ( m_Value )
      {
        case 0:
          m_UpgradeKill1 = this->m_UpgradeKill1;
          if ( m_UpgradeKill1 != nullptr )
            this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_UpgradeKill1, a3: false);
          m_UpgradeKill2 = this->m_UpgradeKill2;
          if ( m_UpgradeKill2 != nullptr )
            this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_UpgradeKill2, a3: false);
          m_UpgradeKillText = this->m_UpgradeKillText;
          if ( m_UpgradeKillText != nullptr )
            this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_UpgradeKillText, a3: false);
          goto LABEL_21;
        case 1:
          v6 = this->m_UpgradeKill1;
          if ( v6 == nullptr )
            goto LABEL_21;
          break;
        case 2:
          v6 = this->m_UpgradeKill2;
          if ( v6 == nullptr )
            goto LABEL_21;
          break;
        default:
          goto LABEL_21;
      }
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: v6, a3: true);
LABEL_21:
      if ( (_S5_145 & 1) == 0 )
      {
        _S5_145 |= 1u;
        ConVarRef::ConVarRef(this: &mp_ggtr_bomb_pts_for_upgrade, pName: "mp_ggtr_bomb_pts_for_upgrade");
      }
      if ( m_Value < mp_ggtr_bomb_pts_for_upgrade.m_pConVarState->m_Value.m_nValue )
      {
        this->m_PrevTRGunGameUpgradePoints = m_Value;
      }
      else
      {
        v10 = this->m_UpgradeKillText;
        if ( v10 != nullptr )
          this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: v10, a3: true);
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
            a3: "playUpgradeAnim",
            a4: nullptr,
            a5: 0);
        }
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        this->m_PrevTRGunGameUpgradePoints = 99;
      }
    }
  }
  v13 = v3->GetActiveWeapon(this: v3);
  if ( v13 != nullptr )
  {
    weaponName = v13->GetPrintName(this: v13);
    shortWeaponName = v13->GetName(this: v13);
    weaponID = (int)v13->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetRefEHandle(this: v13);
    switch ( weaponID )
    {
      case ' ':
      case '#':
      case '$':
        ammoType = 1;
        break;
      case '!':
        ammoType = 2;
        break;
      case '"':
        ammoType = 3;
        break;
      default:
        ammoType = 0;
        break;
    }
    if ( !C_BaseCombatWeapon::UsesPrimaryAmmo(this: v13) )
    {
      AmmoCount = -1;
      currentClip = -1;
LABEL_46:
      totalAmmo = AmmoCount;
      goto LABEL_47;
    }
    currentClip = v13->m_iClip1.m_Value;
    GetPrimaryAmmoType = v13->GetPrimaryAmmoType;
    if ( currentClip >= 0 )
    {
      v17 = GetPrimaryAmmoType(this: v13);
      AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v17);
      goto LABEL_46;
    }
    v16 = GetPrimaryAmmoType(this: v13);
    currentClip = C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v16);
    totalAmmo = -1;
  }
LABEL_47:
  m_PrevWeaponID = this->m_PrevWeaponID;
  bSlotIsLocked = false;
  if ( m_PrevWeaponID == weaponID )
    goto LABEL_63;
  v19 = this->m_pScaleformUI;
  if ( v19 != nullptr )
    v19->LockSlot(this: v19, a2: this->m_iFlashSlot);
  bSlotIsLocked = true;
  if ( weaponName != nullptr )
  {
    m_CurrentWeaponTextHandle = this->m_CurrentWeaponTextHandle;
    if ( m_CurrentWeaponTextHandle != nullptr )
      this->m_pScaleformUI->Value_SetText_2(this: this->m_pScaleformUI, a2: m_CurrentWeaponTextHandle, a3: weaponName);
  }
  if ( this->m_FlashAPI != nullptr && shortWeaponName != nullptr )
  {
    v21 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
    this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v21, a3: 0, a4: shortWeaponName);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "switchWeaponName",
      a4: v21,
      a5: 1u);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v21, a3: 1u);
  }
  WeaponInfo = GetWeaponInfo((CSWeaponID)weaponID);
  if ( WeaponInfo == nullptr )
  {
LABEL_63:
    v25 = (const char *)currentClip;
  }
  else
  {
    m_WeaponPenetration1 = this->m_WeaponPenetration1;
    if ( m_WeaponPenetration1 != nullptr )
      this->m_pScaleformUI->Value_SetVisible(
        this: this->m_pScaleformUI,
        a2: m_WeaponPenetration1,
        a3: WeaponInfo->m_iPenetration == 1);
    m_WeaponPenetration2 = this->m_WeaponPenetration2;
    v25 = (const char *)currentClip;
    if ( m_WeaponPenetration2 != nullptr )
    {
      this->m_pScaleformUI->Value_SetVisible(
        this: this->m_pScaleformUI,
        a2: m_WeaponPenetration2,
        a3: WeaponInfo->m_iPenetration == 2);
      v25 = (const char *)currentClip;
    }
    m_WeaponPenetration3 = this->m_WeaponPenetration3;
    if ( m_WeaponPenetration3 != nullptr )
    {
      v27 = WeaponInfo->m_iPenetration == 3;
      v28 = this->m_pScaleformUI;
      v29 = v28->__vftable;
      shortWeaponName = v25;
      v29->Value_SetVisible(this: v28, a2: m_WeaponPenetration3, a3: v27);
    }
  }
  if ( totalAmmo >= 0 || (bHideNoAmmo = true, (int)v25 >= 0) )
    bHideNoAmmo = false;
  if ( bInTRBombMode && bAmmoShown > 0 )
    bHideNoAmmo = false;
  if ( totalAmmo != this->m_PrevAmmoTotalCount
    || v25 != (const char *)this->m_PrevAmmoClipCount
    || weaponID != this->m_PrevWeaponID )
  {
    if ( !bSlotIsLocked )
    {
      v30 = this->m_pScaleformUI;
      if ( v30 != nullptr )
        v30->LockSlot(this: v30, a2: this->m_iFlashSlot);
      bSlotIsLocked = true;
    }
    LOBYTE(bAmmoShown) = 1;
    if ( totalAmmo >= 0 )
    {
      V_snprintf(pDest: cNewStr, maxLen: 0x80u, pFormat: "%d", v25);
    }
    else
    {
      if ( (int)v25 < 0 )
        V_snprintf(pDest: cNewStr, maxLen: 0x80u, pFormat: prType);
      LOBYTE(bAmmoShown) = 0;
    }
    m_AmmoTextClipHandle = this->m_AmmoTextClipHandle;
    if ( m_AmmoTextClipHandle != nullptr )
      this->m_pScaleformUI->Value_SetText_2(this: this->m_pScaleformUI, a2: m_AmmoTextClipHandle, a3: cNewStr);
    V_snprintf(pDest: cNewStr, maxLen: 0x80u, pFormat: "/ %d", totalAmmo);
    m_AmmoTextTotalHandle = this->m_AmmoTextTotalHandle;
    if ( m_AmmoTextTotalHandle != nullptr )
      this->m_pScaleformUI->Value_SetText_2(this: this->m_pScaleformUI, a2: m_AmmoTextTotalHandle, a3: cNewStr);
    v33 = this->m_AmmoTextClipHandle;
    v34 = bAmmoShown;
    if ( v33 != nullptr )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: v33, a3: bAmmoShown);
    v35 = this->m_AmmoTextTotalHandle;
    if ( v35 != nullptr )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: v35, a3: v34);
  }
  if ( (this->m_PrevAmmoType != ammoType || (const char *)this->m_PrevAmmoClipCount != v25)
    && this->m_FlashAPI != nullptr )
  {
    if ( !bSlotIsLocked )
    {
      v36 = this->m_pScaleformUI;
      if ( v36 != nullptr )
        v36->LockSlot(this: v36, a2: this->m_iFlashSlot);
      bSlotIsLocked = true;
    }
    v37 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
    this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v37, a3: 0, a4: ammoType);
    this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v37, a3: 1, a4: (int)v25);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "updateAmmo",
      a4: v37,
      a5: 2u);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v37, a3: 2u);
  }
  v38 = weaponID;
  if ( this->m_PrevWeaponID == weaponID && ammoType == 0 )
  {
    m_PrevAmmoClipCount = this->m_PrevAmmoClipCount;
    if ( m_PrevAmmoClipCount > 0 && (int)v25 < m_PrevAmmoClipCount && this->m_FlashAPI != nullptr )
    {
      if ( !bSlotIsLocked )
      {
        v40 = this->m_pScaleformUI;
        if ( v40 != nullptr )
          v40->LockSlot(this: v40, a2: this->m_iFlashSlot);
        bSlotIsLocked = true;
      }
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "weaponFired",
        a4: nullptr,
        a5: 0);
    }
  }
  v27 = !bSlotIsLocked;
  v41 = totalAmmo;
  v42 = ammoType;
  this->m_PrevAmmoClipCount = (int)v25;
  this->m_PrevAmmoTotalCount = v41;
  this->m_PrevAmmoType = v42;
  this->m_PrevWeaponID = v38;
  if ( !v27 )
  {
    v43 = this->m_pScaleformUI;
    if ( v43 != nullptr )
      v43->UnlockSlot(this: v43, a2: this->m_iFlashSlot);
  }
  if ( bHideNoAmmo != this->m_bHiddenNoAmmo )
  {
    if ( this->m_bActive )
      SFHudWeaponPanel::ShowPanel(this, value: !bHideNoAmmo);
    this->m_bHiddenNoAmmo = bHideNoAmmo;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10225CB0
// Name: public: SFHudWeaponPanel::SFHudWeaponPanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudWeaponPanel *__thiscall SFHudWeaponPanel::SFHudWeaponPanel(SFHudWeaponPanel *this, const char *value)
{
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
  this->__vftable = (SFHudWeaponPanel_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudWeaponPanel_vtbl *)&SFHudWeaponPanel::`vftable';
  this->m_PanelHandle = nullptr;
  this->m_CurrentWeaponImageHandle = nullptr;
  this->m_CurrentWeaponTextHandle = nullptr;
  this->m_AmmoTextClipHandle = nullptr;
  this->m_AmmoTextTotalHandle = nullptr;
  this->m_AmmoAnimationHandle = nullptr;
  this->m_WeaponPenetration1 = nullptr;
  this->m_WeaponPenetration2 = nullptr;
  this->m_WeaponPenetration3 = nullptr;
  this->m_UpgradeKill1 = nullptr;
  this->m_UpgradeKill2 = nullptr;
  this->m_UpgradeKillText = nullptr;
  this->m_PrevAmmoClipCount = -1;
  this->m_PrevAmmoTotalCount = -1;
  this->m_PrevAmmoType = -1;
  this->m_PrevWeaponID = -1;
  this->m_PrevTRGunGameUpgradePoints = 0;
  this->m_bHiddenNoAmmo = false;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10225D60
// Name: Create_SFHudWeaponPanel
// Source: json
//------------------------------------------------------------------------------
SFHudWeaponPanel *__cdecl Create_SFHudWeaponPanel()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 144);
  memset(dst: v0, value: 0, count: 0x90u);
  if ( v0 != nullptr )
    return SFHudWeaponPanel::SFHudWeaponPanel(this: (SFHudWeaponPanel *)v0, value: "SFHudWeaponPanel");
  else
    return nullptr;
}
