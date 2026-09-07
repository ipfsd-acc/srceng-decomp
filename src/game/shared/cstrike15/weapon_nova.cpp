// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_nova.cpp
// Functions: 15
// ============================================================

#include "game\shared\cstrike15\weapon_nova.h"

//------------------------------------------------------------------------------
// Address: 0x10233040
// Name: public: virtual class ClientClass __near * C_WeaponNOVA::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponNOVA::GetClientClass(C_WeaponNOVA *this)
{
  return &__g_C_WeaponNOVAClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102330D0
// Name: public: virtual struct datamap_t __near * C_WeaponNOVA::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponNOVA::GetPredDescMap(C_WeaponNOVA *this)
{
  return &C_WeaponNOVA::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x102330E0
// Name: public: virtual void weapon_novaPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_novaPrecache::CResourcePrecacher::Cache(
        weapon_novaPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_nova",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10233110
// Name: public: virtual void C_WeaponNOVA::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_WeaponNOVA::PrimaryAttack(C_WeaponNOVA *this@<ecx>, int a2@<ebx>)
{
  C_CSPlayer *v3; // eax
  C_CSPlayer *v4; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  bool v6; // zf
  float m_flCycleTime; // xmm0_4
  float v8; // xmm0_4
  C_WeaponNOVA_vtbl *v9; // edx
  const QAngle *(__thiscall *GetPunchAngle)(C_BasePlayer *); // eax
  char v11; // bl
  float *v12; // eax
  C_CSPlayer_vtbl *v13; // edx
  float v14; // xmm1_4
  const QAngle *(__thiscall *EyeAngles)(C_BaseEntity *); // eax
  float *v16; // eax
  C_WeaponNOVA_vtbl *v17; // edx
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
      ((void (__fastcall *)(C_WeaponNOVA *))v9->Reload)(a1: this);
      if ( this->m_iClip1.m_Value != 0 )
        return;
      C_WeaponCSBase::PlayEmptySound(this);
      v8 = *(float *)(gpGlobals.m_Index + 12) + 0.2;
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
    flSoundTime = ((double (__thiscall *)(C_WeaponNOVA *, _DWORD))GetSpread)(a1: this, a2: LODWORD(flCurAttack));
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
      ((void (__thiscall *)(C_WeaponNOVA *, _DWORD))SetWeaponIdleTime)(
        a1: this,
        a2: *(float *)(gpGlobals.m_Index + 12) + 2.5);
    }
    else
    {
      ((void (__thiscall *)(C_WeaponNOVA *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: v21 + 0.875);
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
                sharedname: "NOVAPunchAngleAir",
                iMinVal: 8,
                iMaxVal: (IUniformRandomStream *)0xB,
                additionalSeed: 0);
      else
        v27 = SharedRandomInt(
                sharedname: "NOVAPunchAngleGround",
                iMinVal: 4,
                iMaxVal: (IUniformRandomStream *)6,
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
// Address: 0x10233470
// Name: public: virtual enum CSWeaponID C_WeaponNOVA::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponNOVA::GetCSWeaponID(C_WeaponNOVA *this)
{
  return 26;
}

//------------------------------------------------------------------------------
// Address: 0x10233500
// Name: CC_WeaponNOVAFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponNOVAFactory()
{
  C_WeaponCSBase *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v1 = &v0->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v0);
  *v1 = &C_WeaponNOVA::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponNOVA::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponNOVA::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponNOVA::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponNOVA::`vftable';
  v1[876] = 0;
  if ( v1[877] != 0 )
    v1[877] = 0;
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10233BA0
// Name: public: virtual bool C_WeaponNOVA::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponNOVA::Reload(C_WeaponNOVA *this)
{
  C_BaseCombatCharacter *v2; // eax
  C_BaseCombatCharacter *v3; // edi
  float v5; // xmm0_4
  int m_Value; // eax
  float *v7; // ecx
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
    v7 = (float *)(gpGlobals.m_Index + 12);
    v8 = *(float *)(gpGlobals.m_Index + 12) + 0.5;
    if ( this->m_flNextPrimaryAttack.m_Value != v8 )
      this->m_flNextPrimaryAttack.m_Value = v8;
    v9 = *v7 + 0.5;
    if ( this->m_flNextSecondaryAttack.m_Value != v9 )
      this->m_flNextSecondaryAttack.m_Value = v9;
    ((void (__thiscall *)(C_WeaponNOVA *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: *v7 + 0.5);
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
  ((void (__thiscall *)(C_WeaponNOVA *, _DWORD))this->SetWeaponIdleTime)(
    a1: this,
    a2: *(float *)(gpGlobals.m_Index + 12) + 0.5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104294C0
// Name: DT_WeaponNOVA::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponNOVA::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponNOVA::g_RecvTable);
  return atexit(func: DT_WeaponNOVA::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104294E0
// Name: DT_WeaponNOVA::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponNOVA::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponNOVA::ignored>();
  DT_WeaponNOVA::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104294F0
// Name: C_WeaponNOVA_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponNOVA_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponNOVA::m_PredMap.dataNumFields = 1;
  C_WeaponNOVA::m_PredMap.dataDesc = (typedescription_t *)&unk_105B6914;
}

//------------------------------------------------------------------------------
// Address: 0x10429540
// Name: weapon_novaPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_novaPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_novaPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_novaPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436170
// Name: DT_WeaponNOVA::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponNOVA::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponNOVA::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10233480
// Name: _C_WeaponNOVA_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponNOVA_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBase *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v3 = &v2->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v2);
  *v3 = &C_WeaponNOVA::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponNOVA::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponNOVA::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponNOVA::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponNOVA::`vftable';
  v3[876] = 0;
  if ( v3[877] != 0 )
    v3[877] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429510
// Name: _dynamic_initializer_for__g_Cweapon_novaFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_novaFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_nova",
             a3: "C_WeaponNOVA",
             a4: 3512,
             a5: CC_WeaponNOVAFactory);
  __g_C_WeaponNOVAClientClass.m_pMapClassname = "weapon_nova";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429560
// Name: _dynamic_initializer_for____g_C_WeaponP250ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponP250ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponP250ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponP250ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F08D0
// Name: public: virtual class ServerClass __near * CWeaponNOVA::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponNOVA::GetServerClass(CWeaponNOVA *this)
{
  return &g_CWeaponNOVA_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F08E0
// Name: public: virtual void weapon_novaPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_novaPrecache::CResourcePrecacher::Cache(
        weapon_novaPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_nova",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F0B10
// Name: public: virtual void CWeaponNOVA::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponNOVA::PrimaryAttack(CWeaponNOVA *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // edi
  const CCSWeaponInfo *v4; // eax
  bool v5; // zf
  float m_flCycleTime; // xmm0_4
  float v7; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  CWeaponNOVA_vtbl *v10; // eax
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
        fCycleTime = ((double (__thiscall *)(CWeaponNOVA *, _DWORD))this->GetSpread)(a1: this, a2: LODWORD(flCurAttack));
        fSpread = ((double (__thiscall *)(CWeaponNOVA *, _DWORD))this->GetInaccuracy)(a1: this, a2: LODWORD(fCycleTime));
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
          ((void (__thiscall *)(CWeaponNOVA *, _DWORD))SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 2.5);
        }
        else
        {
          ((void (__thiscall *)(CWeaponNOVA *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: curtime + 0.875);
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
                    sharedname: "NOVAPunchAngleAir",
                    iMinVal: 8,
                    iMaxVal: (IUniformRandomStream *)0xB,
                    additionalSeed: 0);
          else
            v33 = SharedRandomInt(
                    sharedname: "NOVAPunchAngleGround",
                    iMinVal: 4,
                    iMaxVal: (IUniformRandomStream *)6,
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
        ((void (__fastcall *)(CWeaponNOVA *))v10->Reload)(a1: this);
        if ( this->m_iClip1.m_Value == 0 )
        {
          CWeaponCSBase::PlayEmptySound(this);
          v12 = this->m_flNextPrimaryAttack.m_Value;
          *(float *)&iPlayerIndex = gpGlobals->curtime + 0.2;
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
// Address: 0x102F0F90
// Name: public: CWeaponNOVA::CWeaponNOVA(void)
// Source: json
//------------------------------------------------------------------------------
CWeaponNOVA *__thiscall CWeaponNOVA::CWeaponNOVA(CWeaponNOVA *this)
{
  CWeaponNOVA *result; // eax
  edict_t *m_pPev; // ecx

  CWeaponCSBase::CWeaponCSBase(this);
  this->__vftable = (CWeaponNOVA_vtbl *)&CWeaponNOVA::`vftable';
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
// Address: 0x102F0FF0
// Name: public: virtual enum CSWeaponID CWeaponNOVA::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponNOVA::GetCSWeaponID(CWeaponNOVA *this)
{
  return 26;
}

//------------------------------------------------------------------------------
// Address: 0x102F1570
// Name: public: virtual bool CWeaponNOVA::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CWeaponNOVA::Reload@<al>(CWeaponNOVA *this@<ecx>, int a2@<esi>)
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
    ((void (__thiscall *)(CWeaponNOVA *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 0.5);
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
    ((void (__thiscall *)(CWeaponNOVA *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 0.5);
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
// Address: 0x10412F00
// Name: DT_WeaponNOVA::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponNOVA::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponNOVA::g_SendTable);
  return atexit(func: DT_WeaponNOVA::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412F20
// Name: DT_WeaponNOVA::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponNOVA::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponNOVA::ignored>();
  DT_WeaponNOVA::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412F50
// Name: weapon_novaPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_novaPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_novaPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_novaPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420D90
// Name: DT_WeaponNOVA::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponNOVA::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponNOVA::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412F70
// Name: _dynamic_initializer_for__g_CWeaponP250_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponP250_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponP250_ClassReg,
           pNetworkName: "CWeaponP250",
           pTable: &DT_WeaponP250::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420DA0
// Name: _ServerClassInit_DT_WeaponNOVA::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponNOVA::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_294;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
