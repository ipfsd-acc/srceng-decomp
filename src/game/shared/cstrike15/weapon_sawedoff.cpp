// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_sawedoff.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_sawedoff.h"

//------------------------------------------------------------------------------
// Address: 0x10233AD0
// Name: public: virtual class ClientClass __near * C_WeaponSawedoff::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponSawedoff::GetClientClass(C_WeaponSawedoff *this)
{
  return &__g_C_WeaponSawedoffClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10233B60
// Name: public: virtual struct datamap_t __near * C_WeaponSawedoff::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponSawedoff::GetPredDescMap(C_WeaponSawedoff *this)
{
  return &C_WeaponSawedoff::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10233B70
// Name: public: virtual void weapon_sawedoffPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_sawedoffPrecache::CResourcePrecacher::Cache(
        weapon_sawedoffPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_sawedoff",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10233EA0
// Name: public: virtual void C_WeaponSawedoff::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_WeaponSawedoff::PrimaryAttack(C_WeaponSawedoff *this@<ecx>, int a2@<ebx>)
{
  C_CSPlayer *v3; // eax
  C_CSPlayer *v4; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  bool v6; // zf
  float m_flCycleTime; // xmm0_4
  float v8; // xmm0_4
  C_WeaponSawedoff_vtbl *v9; // edx
  const QAngle *(__thiscall *GetPunchAngle)(C_BasePlayer *); // eax
  char v11; // bl
  float *v12; // eax
  C_CSPlayer_vtbl *v13; // edx
  float v14; // xmm1_4
  const QAngle *(__thiscall *EyeAngles)(C_BaseEntity *); // eax
  float *v16; // eax
  C_WeaponSawedoff_vtbl *v17; // edx
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
      ((void (__fastcall *)(C_WeaponSawedoff *))v9->Reload)(a1: this);
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
    flSoundTime = ((double (__thiscall *)(C_WeaponSawedoff *, _DWORD))GetSpread)(a1: this, a2: LODWORD(flCurAttack));
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
      ((void (__thiscall *)(C_WeaponSawedoff *, _DWORD))SetWeaponIdleTime)(
        a1: this,
        a2: *(float *)(gpGlobals.m_Index + 12) + 2.5);
    }
    else
    {
      ((void (__thiscall *)(C_WeaponSawedoff *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: v21 + 0.875);
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
                sharedname: "SawedoffPunchAngleAir",
                iMinVal: 8,
                iMaxVal: (IUniformRandomStream *)0xB,
                additionalSeed: 0);
      else
        v27 = SharedRandomInt(
                sharedname: "SawedoffPunchAngleGround",
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
// Address: 0x10234280
// Name: CC_WeaponSawedoffFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponSawedoffFactory()
{
  C_WeaponCSBase *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v1 = &v0->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v0);
  *v1 = &C_WeaponSawedoff::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponSawedoff::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponSawedoff::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponSawedoff::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponSawedoff::`vftable';
  v1[876] = 0;
  if ( v1[877] != 0 )
    v1[877] = 0;
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x102E71A0
// Name: public: virtual enum CSWeaponID C_WeaponSawedoff::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_WeaponSawedoff::GetCSWeaponID(C_OP_NoiseEmitter *this)
{
  return 20;
}

//------------------------------------------------------------------------------
// Address: 0x10429700
// Name: DT_WeaponSawedoff::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSawedoff::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponSawedoff::g_RecvTable);
  return atexit(func: DT_WeaponSawedoff::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429720
// Name: DT_WeaponSawedoff::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSawedoff::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponSawedoff::ignored>();
  DT_WeaponSawedoff::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429730
// Name: C_WeaponSawedoff_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponSawedoff_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponSawedoff::m_PredMap.dataNumFields = 1;
  C_WeaponSawedoff::m_PredMap.dataDesc = (typedescription_t *)&unk_105B6B6C;
}

//------------------------------------------------------------------------------
// Address: 0x10429780
// Name: weapon_sawedoffPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_sawedoffPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_sawedoffPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_sawedoffPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104361A0
// Name: DT_WeaponSawedoff::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponSawedoff::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponSawedoff::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10234200
// Name: _C_WeaponSawedoff_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponSawedoff_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBase *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v3 = &v2->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v2);
  *v3 = &C_WeaponSawedoff::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponSawedoff::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponSawedoff::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponSawedoff::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponSawedoff::`vftable';
  v3[876] = 0;
  if ( v3[877] != 0 )
    v3[877] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429750
// Name: _dynamic_initializer_for__g_Cweapon_sawedoffFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_sawedoffFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_sawedoff",
             a3: "C_WeaponSawedoff",
             a4: 3512,
             a5: CC_WeaponSawedoffFactory);
  __g_C_WeaponSawedoffClientClass.m_pMapClassname = "weapon_sawedoff";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104297A0
// Name: _dynamic_initializer_for____g_C_WeaponSCAR20ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponSCAR20ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponSCAR20ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponSCAR20ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F09B0
// Name: public: virtual void CWeaponSawedoff::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponSawedoff::WeaponIdle(CWeaponNOVA *this@<ecx>, int a2@<edi>)
{
  CCSPlayer *PlayerOwner; // ebx
  float m_flPumpTime; // xmm0_4
  CWeaponNOVA_vtbl *v5; // eax
  edict_t *m_pPev; // ecx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    m_flPumpTime = this->m_flPumpTime;
    if ( m_flPumpTime != 0.0 && gpGlobals->curtime > m_flPumpTime )
      this->m_flPumpTime = 0.0;
    if ( gpGlobals->curtime > this->m_flTimeWeaponIdle.m_Value )
    {
      if ( this->m_iClip1.m_Value == 0
        && this->m_reloadState.m_Value == 0
        && CBaseCombatCharacter::GetAmmoCount(this: PlayerOwner, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) != 0 )
      {
        goto LABEL_9;
      }
      v5 = this->__vftable;
      if ( this->m_reloadState.m_Value != 0 )
      {
        if ( this->m_iClip1.m_Value != v5->GetMaxClip1(this)
          && CBaseCombatCharacter::GetAmmoCount(this: PlayerOwner, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) != 0 )
        {
LABEL_9:
          this->Reload(this);
          return;
        }
        ((void (__thiscall *)(CWeaponNOVA *, int, int))this->SendWeaponAnim)(a1: this, a2: 259, a3: a2);
        CCSPlayer::DoAnimationEvent(this: PlayerOwner, event: PLAYERANIMEVENT_RELOAD_END, nData: 0);
        if ( this->m_reloadState.m_Value != 0 )
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
          this->m_reloadState.m_Value = 0;
        }
        ((void (__thiscall *)(CWeaponNOVA *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 1.5);
      }
      else
      {
        v5->SendWeaponAnim(this, a2: 183);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F1490
// Name: public: virtual class ServerClass __near * CWeaponSawedoff::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponSawedoff::GetServerClass(CWeaponSawedoff *this)
{
  return &g_CWeaponSawedoff_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F14A0
// Name: public: virtual void weapon_sawedoffPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_sawedoffPrecache::CResourcePrecacher::Cache(
        weapon_sawedoffPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_sawedoff",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F18C0
// Name: public: virtual void CWeaponSawedoff::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponSawedoff::PrimaryAttack(CWeaponSawedoff *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // edi
  const CCSWeaponInfo *v4; // eax
  bool v5; // zf
  float m_flCycleTime; // xmm0_4
  float v7; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  CWeaponSawedoff_vtbl *v10; // eax
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
        fCycleTime = ((double (__thiscall *)(CWeaponSawedoff *, _DWORD))this->GetSpread)(
                       a1: this,
                       a2: LODWORD(flCurAttack));
        fSpread = ((double (__thiscall *)(CWeaponSawedoff *, _DWORD))this->GetInaccuracy)(
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
          ((void (__thiscall *)(CWeaponSawedoff *, _DWORD))SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 2.5);
        }
        else
        {
          ((void (__thiscall *)(CWeaponSawedoff *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: curtime + 0.875);
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
                    sharedname: "SawedoffPunchAngleAir",
                    iMinVal: 8,
                    iMaxVal: (IUniformRandomStream *)0xB,
                    additionalSeed: 0);
          else
            v33 = SharedRandomInt(
                    sharedname: "SawedoffPunchAngleGround",
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
        ((void (__fastcall *)(CWeaponSawedoff *))v10->Reload)(a1: this);
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
// Address: 0x102F1D40
// Name: public: CWeaponSawedoff::CWeaponSawedoff(void)
// Source: json
//------------------------------------------------------------------------------
CWeaponSawedoff *__thiscall CWeaponSawedoff::CWeaponSawedoff(CWeaponSawedoff *this)
{
  CWeaponSawedoff *result; // eax
  edict_t *m_pPev; // ecx

  CWeaponCSBase::CWeaponCSBase(this);
  this->__vftable = (CWeaponSawedoff_vtbl *)&CWeaponSawedoff::`vftable';
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
// Address: 0x102F1DA0
// Name: public: virtual enum CSWeaponID CWeaponSawedoff::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponSawedoff::GetCSWeaponID(CWeaponSawedoff *this)
{
  return 20;
}

//------------------------------------------------------------------------------
// Address: 0x104130B0
// Name: DT_WeaponSawedoff::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSawedoff::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponSawedoff::g_SendTable);
  return atexit(func: DT_WeaponSawedoff::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104130D0
// Name: DT_WeaponSawedoff::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSawedoff::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponSawedoff::ignored>();
  DT_WeaponSawedoff::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413100
// Name: weapon_sawedoffPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_sawedoffPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_sawedoffPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_sawedoffPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420E20
// Name: DT_WeaponSawedoff::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponSawedoff::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponSawedoff::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10413120
// Name: _dynamic_initializer_for__g_CWeaponSCAR20_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponSCAR20_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponSCAR20_ClassReg,
           pNetworkName: "CWeaponSCAR20",
           pTable: &DT_WeaponSCAR20::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420E30
// Name: _ServerClassInit_DT_WeaponSawedoff::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponSawedoff::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_297;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
