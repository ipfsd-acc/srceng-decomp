// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_xm1014.cpp
// Functions: 27
// ============================================================

#include "game\shared\cstrike15\weapon_xm1014.h"

//------------------------------------------------------------------------------
// Address: 0x10233D70
// Name: public: virtual void C_WeaponXM1014::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponXM1014::WeaponIdle(C_WeaponNOVA *this)
{
  C_BaseCombatCharacter *v2; // eax
  C_BaseCombatCharacter *v3; // edi
  float m_flPumpTime; // xmm0_4

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 == nullptr )
    return;
  m_flPumpTime = this->m_flPumpTime;
  if ( m_flPumpTime != 0.0 && *(float *)(gpGlobals.m_Index + 12) > m_flPumpTime )
    this->m_flPumpTime = 0.0;
  if ( *(float *)(gpGlobals.m_Index + 12) <= this->m_flTimeWeaponIdle.m_Value )
    return;
  if ( this->m_iClip1.m_Value != 0 )
    goto LABEL_10;
  if ( this->m_reloadState.m_Value == 0 )
  {
    if ( C_BaseCombatCharacter::GetAmmoCount(this: v2, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) != 0 )
    {
LABEL_9:
      this->Reload(this);
      return;
    }
LABEL_10:
    if ( this->m_reloadState.m_Value == 0 )
    {
      this->SendWeaponAnim(this, a2: 183);
      return;
    }
  }
  if ( this->m_iClip1.m_Value != this->GetMaxClip1(this)
    && C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) != 0 )
  {
    goto LABEL_9;
  }
  this->SendWeaponAnim(this, a2: 259);
  if ( this->m_reloadState.m_Value != 0 )
    this->m_reloadState.m_Value = 0;
  ((void (__thiscall *)(C_WeaponNOVA *, _DWORD))this->SetWeaponIdleTime)(
    a1: this,
    a2: *(float *)(gpGlobals.m_Index + 12) + 1.5);
}

//------------------------------------------------------------------------------
// Address: 0x10235740
// Name: public: virtual class ClientClass __near * C_WeaponXM1014::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponXM1014::GetClientClass(C_WeaponXM1014 *this)
{
  return &__g_C_WeaponXM1014ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102357D0
// Name: public: virtual struct datamap_t __near * C_WeaponXM1014::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponXM1014::GetPredDescMap(C_WeaponXM1014 *this)
{
  return &C_WeaponXM1014::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x102357E0
// Name: public: virtual void weapon_xm1014Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_xm1014Precache::CResourcePrecacher::Cache(
        weapon_xm1014Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_xm1014",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10235810
// Name: public: virtual bool C_WeaponXM1014::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponXM1014::Reload(C_WeaponXM1014 *this)
{
  C_BaseCombatCharacter *v2; // eax
  C_BaseCombatCharacter *v3; // edi
  float v5; // xmm0_4
  int m_Value; // eax
  unsigned int m_Index; // ecx
  float v8; // xmm0_4
  float v9; // xmm0_4

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 == nullptr )
    return 0;
  if ( C_BaseCombatCharacter::GetAmmoCount(this: v2, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0 )
    return 1;
  if ( this->m_iClip1.m_Value == this->GetMaxClip1(this) )
    return 1;
  v5 = *(float *)(gpGlobals.m_Index + 12);
  if ( this->m_flNextPrimaryAttack.m_Value > v5 )
    return 1;
  m_Value = this->m_reloadState.m_Value;
  if ( m_Value == 0 )
  {
    ((void (__thiscall *)(C_BaseCombatCharacter *, int))v3->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].ObjectCaps)(
      a1: v3,
      a2: 7);
    this->SendWeaponAnim(this, a2: 258);
    if ( this->m_reloadState.m_Value != 1 )
      this->m_reloadState.m_Value = 1;
    v3->m_flNextAttack = *(float *)(gpGlobals.m_Index + 12) + 0.5;
    ((void (__thiscall *)(C_WeaponXM1014 *, _DWORD))this->SetWeaponIdleTime)(
      a1: this,
      a2: *(float *)(gpGlobals.m_Index + 12) + 0.5);
    m_Index = gpGlobals.m_Index;
    v8 = *(float *)(gpGlobals.m_Index + 12) + 0.5;
    if ( this->m_flNextPrimaryAttack.m_Value != v8 )
      this->m_flNextPrimaryAttack.m_Value = v8;
    v9 = *(float *)(m_Index + 12) + 0.5;
    if ( this->m_flNextSecondaryAttack.m_Value != v9 )
    {
      this->m_flNextSecondaryAttack.m_Value = v9;
      return 1;
    }
    return 1;
  }
  if ( m_Value != 1 )
  {
    ++this->m_iClip1.m_Value;
    C_BaseCombatCharacter::RemoveAmmo(this: v3, iCount: 1, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
    if ( this->m_reloadState.m_Value != 1 )
      this->m_reloadState.m_Value = 1;
    return 1;
  }
  if ( this->m_flTimeWeaponIdle.m_Value > v5 )
    return 1;
  if ( this->m_reloadState.m_Value != 2 )
    this->m_reloadState.m_Value = 2;
  this->SendWeaponAnim(this, a2: 192);
  ((void (__thiscall *)(C_WeaponXM1014 *, _DWORD))this->SetWeaponIdleTime)(
    a1: this,
    a2: *(float *)(gpGlobals.m_Index + 12) + 0.5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102359F0
// Name: public: virtual void C_WeaponXM1014::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_WeaponXM1014::PrimaryAttack(C_WeaponXM1014 *this@<ecx>, int a2@<ebx>)
{
  C_CSPlayer *v3; // eax
  C_CSPlayer *v4; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  bool v6; // zf
  float m_flCycleTime; // xmm0_4
  float v8; // xmm0_4
  C_WeaponXM1014_vtbl *v9; // edx
  const QAngle *(__thiscall *GetPunchAngle)(C_BasePlayer *); // eax
  char v11; // bl
  float *v12; // eax
  C_CSPlayer_vtbl *v13; // edx
  float v14; // xmm1_4
  const QAngle *(__thiscall *EyeAngles)(C_BaseEntity *); // eax
  float *v16; // eax
  C_WeaponXM1014_vtbl *v17; // edx
  CSWeaponID v18; // xmm0_4
  float (__thiscall *GetSpread)(C_WeaponCSBase *); // eax
  int v20; // eax
  float v21; // xmm0_4
  void (__thiscall *SetWeaponIdleTime)(C_BaseCombatWeapon *, float); // edx
  const CCSWeaponInfo *v23; // ecx
  float m_Value; // xmm1_4
  float v25; // xmm0_4
  QAngle *v26; // eax
  int v27; // eax
  const Vector *v28; // [esp-4h] [ebp-5Ch]
  CSWeaponID v29; // [esp+8h] [ebp-50h]
  float fSpread; // [esp+14h] [ebp-44h]
  float flSoundTime; // [esp+18h] [ebp-40h]
  QAngle vAngles; // [esp+28h] [ebp-30h] BYREF
  CSWeaponID iWeaponID[3]; // [esp+34h] [ebp-24h] BYREF
  QAngle angle; // [esp+40h] [ebp-18h] BYREF
  const CCSWeaponInfo *weaponInfo; // [esp+4Ch] [ebp-Ch]
  float flCurAttack; // [esp+50h] [ebp-8h]
  float flCycleTime; // [esp+54h] [ebp-4h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    v6 = v4->m_nWaterLevel == 3;
    m_flCycleTime = CSWpnData->m_flCycleTime;
    weaponInfo = CSWpnData;
    flCycleTime = m_flCycleTime;
    if ( v6 )
    {
      C_WeaponCSBase::PlayEmptySound(this);
      v8 = *(float *)(gpGlobals.m_Index + 12) + 0.15000001;
LABEL_4:
      if ( this->m_flNextPrimaryAttack.m_Value != v8 )
        this->m_flNextPrimaryAttack.m_Value = v8;
      return;
    }
    v9 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    if ( this->m_iClip1.m_Value <= 0 )
    {
      ((void (__fastcall *)(C_WeaponXM1014 *))v9->Reload)(a1: this);
      if ( this->m_iClip1.m_Value != 0 )
        return;
      C_WeaponCSBase::PlayEmptySound(this);
      v8 = *(float *)(gpGlobals.m_Index + 12) + 0.25;
      goto LABEL_4;
    }
    ((void (__stdcall *)(int))v9->SendWeaponAnim)(a1: 190);
    --this->m_iClip1.m_Value;
    ((void (__thiscall *)(C_CSPlayer *, int))v4->DoMuzzleFlash)(a1: v4, a2);
    v4->SetAnimation(this: v4, a2: PLAYER_ATTACK1);
    flCurAttack = C_WeaponCSBase::CalculateNextAttackTime(this, fCycleTime: flCycleTime);
    GetPunchAngle = v4->GetPunchAngle;
    v11 = C_BaseEntity::m_nPredictionRandomSeed;
    flCycleTime = weapon_recoil_extra.m_pParent->m_Value.m_fValue + 1.0;
    v12 = (float *)GetPunchAngle(this: v4);
    v13 = v4->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    angle.x = *v12 * flCycleTime;
    angle.y = v12[1] * flCycleTime;
    v14 = v12[2];
    EyeAngles = v13->EyeAngles;
    angle.z = v14 * flCycleTime;
    v16 = (float *)EyeAngles(this: v4);
    v17 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    *(float *)iWeaponID = *v16 + angle.x;
    *(float *)&iWeaponID[1] = v16[1] + angle.y;
    *(float *)&v18 = v16[2] + (float)(v14 * flCycleTime);
    GetSpread = v17->GetSpread;
    iWeaponID[2] = v18;
    flSoundTime = ((double (__thiscall *)(C_WeaponXM1014 *, _DWORD))GetSpread)(a1: this, a2: LODWORD(flCurAttack));
    fSpread = this->GetInaccuracy(this);
    v29 = this->GetCSWeaponID(this);
    v28 = (const Vector *)((int (__thiscall *)(C_CSPlayer *))v4->Weapon_ShootPosition)(a1: v4);
    v20 = v4->entindex(this: &v4->IClientNetworkable);
    FX_FireBullets(
      iPlayerIndex: v20,
      vOrigin: v28,
      &vAngles,
      (CSWeaponID)iWeaponID,
      iMode: v29,
      iSeed: 0,
      fInaccuracy: COERCE_FLOAT(v11),
      fSpread,
      flSoundTime);
    v21 = *(float *)(gpGlobals.m_Index + 12);
    if ( this->m_iClip1.m_Value != 0 )
    {
      SetWeaponIdleTime = this->SetWeaponIdleTime;
      this->m_flPumpTime = v21 + 0.5;
      ((void (__thiscall *)(C_WeaponXM1014 *, _DWORD))SetWeaponIdleTime)(
        a1: this,
        a2: *(float *)(gpGlobals.m_Index + 12) + 2.5);
    }
    else
    {
      ((void (__thiscall *)(C_WeaponXM1014 *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: v21 + 0.25);
    }
    if ( this->m_reloadState.m_Value != 0 )
      this->m_reloadState.m_Value = 0;
    v23 = weaponInfo;
    m_Value = this->m_fAccuracyPenalty.m_Value;
    v25 = weaponInfo->m_fInaccuracyImpulseFire[0] + m_Value;
    if ( m_Value != v25 )
      this->m_fAccuracyPenalty.m_Value = v25;
    if ( weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
    {
      v26 = v4->GetPunchAngle(this: v4);
      v6 = (v4->m_fFlags & 1) == 0;
      angle = *v26;
      if ( v6 )
        v27 = SharedRandomInt(
                sharedname: "XM1014PunchAngleAir",
                iMinVal: 7,
                iMaxVal: (IUniformRandomStream *)0xA,
                additionalSeed: 0);
      else
        v27 = SharedRandomInt(
                sharedname: "XM1014PunchAngleGround",
                iMinVal: 3,
                iMaxVal: (IUniformRandomStream *)5,
                additionalSeed: 0);
      angle.x = angle.x - (float)v27;
      C_BasePlayer::SetPunchAngle(this: v4, &angle);
    }
    else
    {
      C_CSPlayer::KickBack(
        this: v4,
        fAngle: v23->m_fRecoilAngle[this->m_weaponMode.m_Value],
        fAngleVariance: v23->m_fRecoilAngleVariance[this->m_weaponMode.m_Value],
        fMagnitude: v23->m_fRecoilMagnitude[this->m_weaponMode.m_Value],
        fMagnitudeVariance: v23->m_fRecoilMagnitudeVariance[this->m_weaponMode.m_Value]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10235DD0
// Name: CC_WeaponXM1014Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponXM1014Factory()
{
  C_WeaponCSBase *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v1 = &v0->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v0);
  *v1 = &C_WeaponXM1014::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponXM1014::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponXM1014::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponXM1014::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponXM1014::`vftable';
  v1[876] = 0;
  if ( v1[877] != 0 )
    v1[877] = 0;
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429D00
// Name: DT_WeaponXM1014::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponXM1014::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponXM1014::g_RecvTable);
  return atexit(func: DT_WeaponXM1014::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429D20
// Name: DT_WeaponXM1014::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponXM1014::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponXM1014::ignored>();
  DT_WeaponXM1014::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429D30
// Name: C_WeaponXM1014_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponXM1014_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponXM1014::m_PredMap.dataNumFields = 1;
  C_WeaponXM1014::m_PredMap.dataDesc = (typedescription_t *)&unk_105B70FC;
}

//------------------------------------------------------------------------------
// Address: 0x10429D80
// Name: weapon_xm1014Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_xm1014Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_xm1014Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_xm1014Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436220
// Name: DT_WeaponXM1014::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponXM1014::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponXM1014::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10235D50
// Name: _C_WeaponXM1014_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponXM1014_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBase *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v3 = &v2->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v2);
  *v3 = &C_WeaponXM1014::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponXM1014::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponXM1014::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponXM1014::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponXM1014::`vftable';
  v3[876] = 0;
  if ( v3[877] != 0 )
    v3[877] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429D50
// Name: _dynamic_initializer_for__g_Cweapon_xm1014Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_xm1014Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_xm1014",
             a3: "C_WeaponXM1014",
             a4: 3512,
             a5: CC_WeaponXM1014Factory);
  __g_C_WeaponXM1014ClientClass.m_pMapClassname = "weapon_xm1014";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429DA0
// Name: _dynamic_initializer_for__g_CBaseModelPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CBaseModelPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CBaseModelPanel_Helper,
           className: "CBaseModelPanel",
           func: (vgui::Panel *(__cdecl *)())Create_CBaseModelPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10429DC0
// Name: _dynamic_initializer_for__hud_autoreloadscript__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_autoreloadscript__()
{
  ConVar::ConVar(
    this: &hud_autoreloadscript,
    pName: "hud_autoreloadscript",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Automatically reloads the animation script each time one is ran");
  return atexit(func: dynamic_atexit_destructor_for__hud_autoreloadscript__);
}

//------------------------------------------------------------------------------
// Address: 0x10429DF0
// Name: _dynamic_initializer_for__cl_leveloverviewmarker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_leveloverviewmarker__()
{
  ConVar::ConVar(this: &cl_leveloverviewmarker, pName: "cl_leveloverviewmarker", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_leveloverviewmarker__);
}

//------------------------------------------------------------------------------
// Address: 0x10429E20
// Name: _dynamic_initializer_for__showpanel_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showpanel_command__()
{
  ConCommand::ConCommand(
    this: &showpanel_command,
    pName: "showpanel",
    callback: (void (__cdecl *)())showpanel,
    pHelpString: "Shows a viewport panel <name>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showpanel_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10429E50
// Name: _dynamic_initializer_for__hidepanel_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hidepanel_command__()
{
  ConCommand::ConCommand(
    this: &hidepanel_command,
    pName: "hidepanel",
    callback: (void (__cdecl *)())hidepanel,
    pHelpString: "Hides a viewport panel <name>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hidepanel_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10429E80
// Name: _dynamic_initializer_for__g_CIconPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CIconPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CIconPanel_Helper,
           className: "CIconPanel",
           func: (vgui::Panel *(__cdecl *)())Create_CIconPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10429EA0
// Name: _dynamic_initializer_for__NextBotShadowDist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__NextBotShadowDist__()
{
  ConVar::ConVar(this: &NextBotShadowDist, pName: "nb_shadow_dist", pDefaultValue: "400", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__NextBotShadowDist__);
}

//------------------------------------------------------------------------------
// Address: 0x10429ED0
// Name: _dynamic_initializer_for____g_C_NextBotCombatCharacterClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_NextBotCombatCharacterClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_NextBotCombatCharacterClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_NextBotCombatCharacterClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436230
// Name: _dynamic_atexit_destructor_for__hud_autoreloadscript__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_autoreloadscript__()
{
  ConVar::~ConVar(this: &hud_autoreloadscript);
}

//------------------------------------------------------------------------------
// Address: 0x10436240
// Name: _dynamic_atexit_destructor_for__cl_leveloverviewmarker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_leveloverviewmarker__()
{
  ConVar::~ConVar(this: &cl_leveloverviewmarker);
}

//------------------------------------------------------------------------------
// Address: 0x10436250
// Name: _dynamic_atexit_destructor_for__showpanel_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showpanel_command__()
{
  ConCommand::~ConCommand(this: &showpanel_command);
}

//------------------------------------------------------------------------------
// Address: 0x10436260
// Name: _dynamic_atexit_destructor_for__hidepanel_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hidepanel_command__()
{
  ConCommand::~ConCommand(this: &hidepanel_command);
}

//------------------------------------------------------------------------------
// Address: 0x10436270
// Name: _dynamic_atexit_destructor_for__NextBotShadowDist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__NextBotShadowDist__()
{
  ConVar::~ConVar(this: &NextBotShadowDist);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F3700
// Name: public: virtual class ServerClass __near * CWeaponXM1014::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponXM1014::GetServerClass(CWeaponXM1014 *this)
{
  return &g_CWeaponXM1014_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F3710
// Name: public: virtual void weapon_xm1014Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_xm1014Precache::CResourcePrecacher::Cache(
        weapon_xm1014Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_xm1014",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F37E0
// Name: public: virtual bool CWeaponXM1014::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CWeaponXM1014::Reload@<al>(CWeaponXM1014 *this@<ecx>, int a2@<esi>)
{
  CCSPlayer *PlayerOwner; // eax
  float curtime; // xmm0_4
  int m_Value; // eax
  edict_t *m_pPev; // ecx
  float v8; // xmm0_4
  CBaseEdict *v9; // ecx
  float v10; // xmm0_4
  edict_t *v11; // ecx
  float v12; // xmm0_4
  edict_t *v13; // ecx
  edict_t *v14; // ecx
  int v15; // edx
  edict_t *v16; // ecx
  edict_t *v17; // ecx
  int v18; // [esp+18h] [ebp-8h]
  CCSPlayer *pPlayer; // [esp+1Ch] [ebp-4h]

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  pPlayer = PlayerOwner;
  if ( PlayerOwner == nullptr )
    return 0;
  if ( CBaseCombatCharacter::GetAmmoCount(this: PlayerOwner, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0 )
    return 1;
  if ( this->m_iClip1.m_Value == this->GetMaxClip1(this) )
    return 1;
  curtime = gpGlobals->curtime;
  if ( this->m_flNextPrimaryAttack.m_Value > curtime )
    return 1;
  m_Value = this->m_reloadState.m_Value;
  if ( m_Value == 0 )
  {
    ((void (__thiscall *)(CCSPlayer *, int, int))pPlayer->SetAnimation)(a1: pPlayer, a2: 7, a3: a2);
    this->SendWeaponAnim(this, a2: 258);
    if ( this->m_reloadState.m_Value != 1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C4u);
      }
      this->m_reloadState.m_Value = 1;
    }
    v8 = gpGlobals->curtime + 0.5;
    if ( pPlayer->m_flNextAttack.m_Value != v8 )
    {
      if ( pPlayer->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&pPlayer->m_Network + 76) |= 1u;
      }
      else
      {
        v9 = &pPlayer->m_Network.m_pPev->CBaseEdict;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: v9, offset: 0x684u);
      }
      pPlayer->m_flNextAttack.m_Value = v8;
    }
    ((void (__thiscall *)(CWeaponXM1014 *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 0.5);
    v10 = gpGlobals->curtime + 0.5;
    if ( this->m_flNextPrimaryAttack.m_Value != v10 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v11 = this->m_Network.m_pPev;
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x494u);
      }
      this->m_flNextPrimaryAttack.m_Value = v10;
    }
    v12 = gpGlobals->curtime + 0.5;
    if ( this->m_flNextSecondaryAttack.m_Value != v12 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v13 = this->m_Network.m_pPev;
        if ( v13 != nullptr )
          CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x498u);
      }
      this->m_flNextSecondaryAttack.m_Value = v12;
    }
    CCSPlayer::DoAnimationEvent(this: pPlayer, event: PLAYERANIMEVENT_RELOAD_START, nData: 0);
    return 1;
  }
  if ( m_Value == 1 )
  {
    if ( this->m_flTimeWeaponIdle.m_Value > curtime )
      return 1;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x5C4u);
    }
    this->m_reloadState.m_Value = 2;
    this->SendWeaponAnim(this, a2: 192);
    ((void (__thiscall *)(CWeaponXM1014 *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 0.5);
    CCSPlayer::DoAnimationEvent(this: pPlayer, event: PLAYERANIMEVENT_RELOAD_LOOP, nData: 0);
    return 1;
  }
  else
  {
    v15 = this->m_iClip1.m_Value + 1;
    v18 = v15;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v16 = this->m_Network.m_pPev;
      if ( v16 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x4B0u);
        v15 = v18;
      }
    }
    this->m_iClip1.m_Value = v15;
    CWeaponCSBase::SendReloadEvents(this);
    CBaseCombatCharacter::RemoveAmmo(this: pPlayer, iCount: 1, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
    if ( this->m_reloadState.m_Value == 1 )
      return 1;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_reloadState.m_Value = 1;
      return 1;
    }
    else
    {
      v17 = this->m_Network.m_pPev;
      if ( v17 != nullptr )
        CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x5C4u);
      this->m_reloadState.m_Value = 1;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F3B30
// Name: public: virtual void CWeaponXM1014::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponXM1014::PrimaryAttack(CWeaponXM1014 *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // edi
  const CCSWeaponInfo *v4; // eax
  bool v5; // zf
  float m_flCycleTime; // xmm0_4
  float v7; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  CWeaponXM1014_vtbl *v10; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  edict_t *v13; // ecx
  int v14; // edx
  edict_t *v15; // ecx
  char v16; // bl
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // eax
  CCSPlayer_vtbl *v18; // edx
  float z; // xmm1_4
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // eax
  float *v21; // eax
  float v22; // xmm0_4
  edict_t *v23; // eax
  const Vector *v24; // eax
  float curtime; // xmm0_4
  void (__thiscall *SetWeaponIdleTime)(CBaseCombatWeapon *, float); // edx
  edict_t *v27; // ecx
  const CCSWeaponInfo *v28; // ebx
  float v29; // xmm1_4
  const CCSWeaponInfo *v30; // xmm0_4
  edict_t *v31; // ecx
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *v32; // eax
  int v33; // eax
  CSWeaponID fAngle; // [esp+10h] [ebp-50h]
  float fSpread; // [esp+1Ch] [ebp-44h]
  float fCycleTime; // [esp+20h] [ebp-40h]
  QAngle vAngles; // [esp+2Ch] [ebp-34h] BYREF
  CSWeaponID iWeaponID[3]; // [esp+38h] [ebp-28h] BYREF
  QAngle angle; // [esp+44h] [ebp-1Ch] BYREF
  const CCSWeaponInfo *weaponInfo; // [esp+50h] [ebp-10h]
  float flCurAttack; // [esp+54h] [ebp-Ch]
  float flCycleTime; // [esp+58h] [ebp-8h]
  int iPlayerIndex; // [esp+5Ch] [ebp-4h]
  int savedregs; // [esp+60h] [ebp+0h] BYREF

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    *(float *)&v4 = COERCE_FLOAT(CWeaponCSBase::GetCSWpnData(this));
    v5 = PlayerOwner->m_nWaterLevel.m_Value == 3;
    m_flCycleTime = v4->m_flCycleTime;
    weaponInfo = v4;
    flCycleTime = m_flCycleTime;
    if ( v5 )
    {
      CWeaponCSBase::PlayEmptySound(this);
      m_Value = this->m_flNextPrimaryAttack.m_Value;
      *(float *)&iPlayerIndex = gpGlobals->curtime + 0.15000001;
      v7 = *(float *)&iPlayerIndex;
      if ( m_Value != *(float *)&iPlayerIndex )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flNextPrimaryAttack.m_Value = v7;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
          {
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
            v7 = *(float *)&iPlayerIndex;
          }
          this->m_flNextPrimaryAttack.m_Value = v7;
        }
      }
    }
    else
    {
      v10 = this->__vftable;
      if ( this->m_iClip1.m_Value > 0 )
      {
        ((void (__stdcall *)(int, int))v10->SendWeaponAnim)(a1: 190, a2);
        v14 = this->m_iClip1.m_Value - 1;
        iPlayerIndex = v14;
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v15 = this->m_Network.m_pPev;
          if ( v15 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x4B0u);
            v14 = iPlayerIndex;
          }
        }
        this->m_iClip1.m_Value = v14;
        PlayerOwner->DoMuzzleFlash(this: PlayerOwner);
        PlayerOwner->SetAnimation(this: PlayerOwner, a2: PLAYER_ATTACK1);
        flCurAttack = CWeaponCSBase::CalculateNextAttackTime(this, fCycleTime: flCycleTime);
        v16 = CBaseEntity::m_nPredictionRandomSeed;
        flCycleTime = weapon_recoil_extra.m_pParent->m_Value.m_fValue + 1.0;
        PunchAngle = CBasePlayer::GetPunchAngle(this: PlayerOwner);
        v18 = PlayerOwner->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        angle.x = PunchAngle->m_Value.x * flCycleTime;
        angle.y = PunchAngle->m_Value.y * flCycleTime;
        z = PunchAngle->m_Value.z;
        EyeAngles = v18->EyeAngles;
        angle.z = z * flCycleTime;
        v21 = (float *)EyeAngles(this: PlayerOwner);
        *(float *)iWeaponID = *v21 + angle.x;
        *(float *)&iWeaponID[1] = v21[1] + angle.y;
        v22 = v21[2];
        v23 = PlayerOwner->m_Network.m_pPev;
        *(float *)&iWeaponID[2] = v22 + (float)(z * flCycleTime);
        if ( v23 != nullptr )
          iPlayerIndex = v23 - gpGlobals->pEdicts;
        else
          *(float *)&iPlayerIndex = 0.0;
        fCycleTime = ((double (__thiscall *)(CWeaponXM1014 *, _DWORD))this->GetSpread)(
                       a1: this,
                       a2: LODWORD(flCurAttack));
        fSpread = ((double (__thiscall *)(CWeaponXM1014 *, _DWORD))this->GetInaccuracy)(
                    a1: this,
                    a2: LODWORD(fCycleTime));
        fAngle = this->GetCSWeaponID(this);
        v24 = (const Vector *)((int (__thiscall *)(CCSPlayer *))PlayerOwner->Weapon_ShootPosition)(a1: PlayerOwner);
        FX_FireBullets(
          a1: COERCE_FLOAT(&savedregs),
          iPlayerIndex,
          vOrigin: v24,
          &vAngles,
          (CSWeaponID)iWeaponID,
          iMode: fAngle,
          iSeed: 0,
          fInaccuracy: COERCE_FLOAT(v16),
          fSpread);
        curtime = gpGlobals->curtime;
        if ( this->m_iClip1.m_Value != 0 )
        {
          SetWeaponIdleTime = this->SetWeaponIdleTime;
          this->m_flPumpTime = curtime + 0.5;
          ((void (__thiscall *)(CWeaponXM1014 *, _DWORD))SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 2.5);
        }
        else
        {
          ((void (__thiscall *)(CWeaponXM1014 *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: curtime + 0.25);
        }
        if ( this->m_reloadState.m_Value != 0 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v27 = this->m_Network.m_pPev;
            if ( v27 != nullptr )
              CBaseEdict::StateChanged(this: &v27->CBaseEdict, offset: 0x5C4u);
          }
          this->m_reloadState.m_Value = 0;
        }
        v28 = weaponInfo;
        v29 = this->m_fAccuracyPenalty.m_Value;
        *(float *)&weaponInfo = weaponInfo->m_fInaccuracyImpulseFire[0] + v29;
        v30 = weaponInfo;
        if ( v29 != *(float *)&weaponInfo )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v31 = this->m_Network.m_pPev;
            if ( v31 != nullptr )
            {
              CBaseEdict::StateChanged(this: &v31->CBaseEdict, offset: 0x580u);
              v30 = weaponInfo;
            }
          }
          this->m_fAccuracyPenalty.m_Value = *(float *)&v30;
        }
        if ( weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
        {
          v32 = CBasePlayer::GetPunchAngle(this: PlayerOwner);
          v5 = (PlayerOwner->m_fFlags.m_Value & 1) == 0;
          angle = v32->m_Value;
          if ( v5 )
            v33 = SharedRandomInt(
                    sharedname: "XM1014PunchAngleAir",
                    iMinVal: 7,
                    iMaxVal: (IUniformRandomStream *)0xA,
                    additionalSeed: 0);
          else
            v33 = SharedRandomInt(
                    sharedname: "XM1014PunchAngleGround",
                    iMinVal: 3,
                    iMaxVal: (IUniformRandomStream *)5,
                    additionalSeed: 0);
          angle.x = angle.x - (float)v33;
          CBasePlayer::SetPunchAngle(this: PlayerOwner, punchAngle: &angle);
        }
        else
        {
          CCSPlayer::KickBack(
            this: PlayerOwner,
            fAngle: v28->m_fRecoilAngle[this->m_weaponMode.m_Value],
            fAngleVariance: v28->m_fRecoilAngleVariance[this->m_weaponMode.m_Value],
            fMagnitude: v28->m_fRecoilMagnitude[this->m_weaponMode.m_Value],
            fMagnitudeVariance: v28->m_fRecoilMagnitudeVariance[this->m_weaponMode.m_Value]);
        }
      }
      else
      {
        ((void (__fastcall *)(CWeaponXM1014 *))v10->Reload)(a1: this);
        if ( this->m_iClip1.m_Value == 0 )
        {
          CWeaponCSBase::PlayEmptySound(this);
          v12 = this->m_flNextPrimaryAttack.m_Value;
          *(float *)&iPlayerIndex = gpGlobals->curtime + 0.25;
          v11 = *(float *)&iPlayerIndex;
          if ( v12 != *(float *)&iPlayerIndex )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
              this->m_flNextPrimaryAttack.m_Value = v11;
            }
            else
            {
              v13 = this->m_Network.m_pPev;
              if ( v13 != nullptr )
              {
                CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x494u);
                v11 = *(float *)&iPlayerIndex;
              }
              this->m_flNextPrimaryAttack.m_Value = v11;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F3FB0
// Name: public: CWeaponXM1014::CWeaponXM1014(void)
// Source: json
//------------------------------------------------------------------------------
CWeaponXM1014 *__thiscall CWeaponXM1014::CWeaponXM1014(CWeaponXM1014 *this)
{
  CWeaponXM1014 *result; // eax
  edict_t *m_pPev; // ecx

  CWeaponCSBase::CWeaponCSBase(this);
  this->__vftable = (CWeaponXM1014_vtbl *)&CWeaponXM1014::`vftable';
  this->m_flPumpTime = 0.0;
  result = this;
  if ( this->m_reloadState.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_reloadState.m_Value = 0;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C4u);
      this->m_reloadState.m_Value = 0;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413540
// Name: DT_WeaponXM1014::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponXM1014::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponXM1014::g_SendTable);
  return atexit(func: DT_WeaponXM1014::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413560
// Name: DT_WeaponXM1014::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponXM1014::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponXM1014::ignored>();
  DT_WeaponXM1014::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413590
// Name: weapon_xm1014Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_xm1014Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_xm1014Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_xm1014Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420FB0
// Name: DT_WeaponXM1014::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponXM1014::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponXM1014::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104135B0
// Name: _dynamic_initializer_for__TheNavAreas__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__TheNavAreas__()
{
  return atexit(func: dynamic_atexit_destructor_for__TheNavAreas__);
}

//------------------------------------------------------------------------------
// Address: 0x104135C0
// Name: _dynamic_initializer_for__nav_coplanar_slope_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_coplanar_slope_limit__()
{
  ConVar::ConVar(
    this: &nav_coplanar_slope_limit,
    pName: "nav_coplanar_slope_limit",
    pDefaultValue: "0.99",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_coplanar_slope_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x104135F0
// Name: _dynamic_initializer_for__nav_coplanar_slope_limit_displacement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_coplanar_slope_limit_displacement__()
{
  ConVar::ConVar(
    this: &nav_coplanar_slope_limit_displacement,
    pName: "nav_coplanar_slope_limit_displacement",
    pDefaultValue: "0.7",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_coplanar_slope_limit_displacement__);
}

//------------------------------------------------------------------------------
// Address: 0x10413620
// Name: _dynamic_initializer_for__nav_split_place_on_ground__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_split_place_on_ground__()
{
  ConVar::ConVar(
    this: &nav_split_place_on_ground,
    pName: "nav_split_place_on_ground",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "If true, nav areas will be placed flush with the ground when split.");
  return atexit(func: dynamic_atexit_destructor_for__nav_split_place_on_ground__);
}

//------------------------------------------------------------------------------
// Address: 0x10413650
// Name: _dynamic_initializer_for__nav_area_bgcolor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_area_bgcolor__()
{
  ConVar::ConVar(
    this: &nav_area_bgcolor,
    pName: "nav_area_bgcolor",
    pDefaultValue: "0 0 0 30",
    flags: 0x4000,
    pHelpString: "RGBA color to draw as the background color for nav areas while editing.");
  return atexit(func: dynamic_atexit_destructor_for__nav_area_bgcolor__);
}

//------------------------------------------------------------------------------
// Address: 0x10413680
// Name: _dynamic_initializer_for__nav_corner_adjust_adjacent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_corner_adjust_adjacent__()
{
  ConVar::ConVar(
    this: &nav_corner_adjust_adjacent,
    pName: "nav_corner_adjust_adjacent",
    pDefaultValue: "18",
    flags: 0x4000,
    pHelpString: "radius used to raise/lower corners in nearby areas when raising/lowering corners.");
  return atexit(func: dynamic_atexit_destructor_for__nav_corner_adjust_adjacent__);
}

//------------------------------------------------------------------------------
// Address: 0x104136B0
// Name: _dynamic_initializer_for__nav_show_light_intensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_light_intensity__()
{
  ConVar::ConVar(this: &nav_show_light_intensity, pName: "nav_show_light_intensity", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_show_light_intensity__);
}

//------------------------------------------------------------------------------
// Address: 0x104136E0
// Name: _dynamic_initializer_for__nav_debug_blocked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_debug_blocked__()
{
  ConVar::ConVar(this: &nav_debug_blocked, pName: "nav_debug_blocked", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_debug_blocked__);
}

//------------------------------------------------------------------------------
// Address: 0x10413710
// Name: _dynamic_initializer_for__nav_show_contiguous__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_contiguous__()
{
  ConVar::ConVar(
    this: &nav_show_contiguous,
    pName: "nav_show_continguous",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Highlight non-contiguous connections");
  return atexit(func: dynamic_atexit_destructor_for__nav_show_contiguous__);
}

//------------------------------------------------------------------------------
// Address: 0x10413740
// Name: _dynamic_initializer_for__nav_max_view_distance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_max_view_distance__()
{
  ConVar::ConVar(
    this: &nav_max_view_distance,
    pName: "nav_max_view_distance",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Maximum range for precomputed nav mesh visibility (0 = default 1500 units)");
  return atexit(func: dynamic_atexit_destructor_for__nav_max_view_distance__);
}

//------------------------------------------------------------------------------
// Address: 0x10413770
// Name: _dynamic_initializer_for__nav_update_visibility_on_edit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_update_visibility_on_edit__()
{
  ConVar::ConVar(
    this: &nav_update_visibility_on_edit,
    pName: "nav_update_visibility_on_edit",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "If nonzero editing the mesh will incrementally recompue visibility");
  return atexit(func: dynamic_atexit_destructor_for__nav_update_visibility_on_edit__);
}

//------------------------------------------------------------------------------
// Address: 0x104137A0
// Name: _dynamic_initializer_for__nav_potentially_visible_dot_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_potentially_visible_dot_tolerance__()
{
  ConVar::ConVar(
    this: &nav_potentially_visible_dot_tolerance,
    pName: "nav_potentially_visible_dot_tolerance",
    pDefaultValue: "0.98",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__nav_potentially_visible_dot_tolerance__);
}

//------------------------------------------------------------------------------
// Address: 0x104137D0
// Name: _dynamic_initializer_for__nav_show_potentially_visible__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_show_potentially_visible__()
{
  ConVar::ConVar(
    this: &nav_show_potentially_visible,
    pName: "nav_show_potentially_visible",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Show areas that are potentially visible from the current nav area");
  return atexit(func: dynamic_atexit_destructor_for__nav_show_potentially_visible__);
}

//------------------------------------------------------------------------------
// Address: 0x10413800
// Name: _dynamic_initializer_for__nav_selected_set_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_selected_set_color__()
{
  ConVar::ConVar(
    this: &nav_selected_set_color,
    pName: "nav_selected_set_color",
    pDefaultValue: "255 255 200 96",
    flags: 0x4000,
    pHelpString: "Color used to draw the selected set background while editing.",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))SelectedSetColorChaged);
  return atexit(func: dynamic_atexit_destructor_for__nav_selected_set_color__);
}

//------------------------------------------------------------------------------
// Address: 0x10413850
// Name: _dynamic_initializer_for__nav_selected_set_border_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_selected_set_border_color__()
{
  ConVar::ConVar(
    this: &nav_selected_set_border_color,
    pName: "nav_selected_set_border_color",
    pDefaultValue: "100 100 0 255",
    flags: 0x4000,
    pHelpString: "Color used to draw the selected set borders while editing.",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))SelectedSetColorChaged);
  return atexit(func: dynamic_atexit_destructor_for__nav_selected_set_border_color__);
}

//------------------------------------------------------------------------------
// Address: 0x10420FC0
// Name: _ServerClassInit_DT_WeaponXM1014::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponXM1014::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_305;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420FE0
// Name: _dynamic_atexit_destructor_for__nav_coplanar_slope_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_coplanar_slope_limit__()
{
  ConVar::~ConVar(this: &nav_coplanar_slope_limit);
}

//------------------------------------------------------------------------------
// Address: 0x10420FF0
// Name: _dynamic_atexit_destructor_for__nav_coplanar_slope_limit_displacement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_coplanar_slope_limit_displacement__()
{
  ConVar::~ConVar(this: &nav_coplanar_slope_limit_displacement);
}

//------------------------------------------------------------------------------
// Address: 0x10421000
// Name: _dynamic_atexit_destructor_for__nav_split_place_on_ground__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_split_place_on_ground__()
{
  ConVar::~ConVar(this: &nav_split_place_on_ground);
}

//------------------------------------------------------------------------------
// Address: 0x10421010
// Name: _dynamic_atexit_destructor_for__nav_area_bgcolor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_area_bgcolor__()
{
  ConVar::~ConVar(this: &nav_area_bgcolor);
}

//------------------------------------------------------------------------------
// Address: 0x10421020
// Name: _dynamic_atexit_destructor_for__nav_corner_adjust_adjacent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_corner_adjust_adjacent__()
{
  ConVar::~ConVar(this: &nav_corner_adjust_adjacent);
}

//------------------------------------------------------------------------------
// Address: 0x10421030
// Name: _dynamic_atexit_destructor_for__nav_show_light_intensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_light_intensity__()
{
  ConVar::~ConVar(this: &nav_show_light_intensity);
}

//------------------------------------------------------------------------------
// Address: 0x10421040
// Name: _dynamic_atexit_destructor_for__nav_debug_blocked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_debug_blocked__()
{
  ConVar::~ConVar(this: &nav_debug_blocked);
}

//------------------------------------------------------------------------------
// Address: 0x10421050
// Name: _dynamic_atexit_destructor_for__nav_show_contiguous__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_contiguous__()
{
  ConVar::~ConVar(this: &nav_show_contiguous);
}

//------------------------------------------------------------------------------
// Address: 0x10421060
// Name: _dynamic_atexit_destructor_for__nav_max_view_distance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_max_view_distance__()
{
  ConVar::~ConVar(this: &nav_max_view_distance);
}

//------------------------------------------------------------------------------
// Address: 0x10421070
// Name: _dynamic_atexit_destructor_for__nav_update_visibility_on_edit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_update_visibility_on_edit__()
{
  ConVar::~ConVar(this: &nav_update_visibility_on_edit);
}

//------------------------------------------------------------------------------
// Address: 0x10421080
// Name: _dynamic_atexit_destructor_for__nav_potentially_visible_dot_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_potentially_visible_dot_tolerance__()
{
  ConVar::~ConVar(this: &nav_potentially_visible_dot_tolerance);
}

//------------------------------------------------------------------------------
// Address: 0x10421090
// Name: _dynamic_atexit_destructor_for__nav_show_potentially_visible__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_potentially_visible__()
{
  ConVar::~ConVar(this: &nav_show_potentially_visible);
}

//------------------------------------------------------------------------------
// Address: 0x104210A0
// Name: _dynamic_atexit_destructor_for__nav_selected_set_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_selected_set_color__()
{
  ConVar::~ConVar(this: &nav_selected_set_color);
}

//------------------------------------------------------------------------------
// Address: 0x104210B0
// Name: _dynamic_atexit_destructor_for__nav_selected_set_border_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_selected_set_border_color__()
{
  ConVar::~ConVar(this: &nav_selected_set_border_color);
}

} // namespace server
