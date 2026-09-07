// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_famas.cpp
// Functions: 17
// ============================================================

#include "game\shared\cstrike15\weapon_famas.h"

//------------------------------------------------------------------------------
// Address: 0x1022E1F0
// Name: public: virtual class ClientClass __near * C_WeaponFamas::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponFamas::GetClientClass(C_WeaponFamas *this)
{
  return &__g_C_WeaponFamasClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022E2A0
// Name: public: virtual struct datamap_t __near * C_WeaponFamas::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponFamas::GetPredDescMap(C_WeaponFamas *this)
{
  return &C_WeaponFamas::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022E2B0
// Name: public: virtual void weapon_famasPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_famasPrecache::CResourcePrecacher::Cache(
        weapon_famasPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_famas",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022E310
// Name: public: virtual void C_WeaponFamas::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponFamas::SecondaryAttack(C_WeaponFamas *this)
{
  vgui::PropertyPage *v2; // ecx
  int v3; // eax
  float v4; // xmm0_4

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v3 != 0 )
  {
    if ( this->m_bBurstMode.m_Value )
    {
      C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v2);
      if ( this->m_bBurstMode.m_Value )
        this->m_bBurstMode.m_Value = false;
      if ( this->m_weaponMode.m_Value != Primary_Mode )
        this->m_weaponMode.m_Value = Primary_Mode;
    }
    else
    {
      C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v2);
      if ( !this->m_bBurstMode.m_Value )
        this->m_bBurstMode.m_Value = true;
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
        this->m_weaponMode.m_Value = Secondary_Mode;
    }
    v4 = *(float *)(gpGlobals.m_Index + 12) + 0.3;
    if ( this->m_flNextSecondaryAttack.m_Value != v4 )
      this->m_flNextSecondaryAttack.m_Value = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E3D0
// Name: public: virtual void C_WeaponFamas::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponFamas::PrimaryAttack(C_WeaponFamas *this)
{
  int v2; // eax
  C_CSPlayer *v3; // eax
  C_CSPlayer *v4; // edi
  float flCycleTime; // xmm0_4
  int m_fFlags; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    C_WeaponCSBase::GetPlayerOwner(this);
    v4 = v3;
    if ( v3 != nullptr )
    {
      flCycleTime = C_WeaponCSBase::GetCSWpnData(this)->m_flCycleTime;
      if ( this->m_bBurstMode.m_Value )
      {
        flCycleTime = 0.55000001;
        if ( this->m_iBurstShotsRemaining.m_Value != 2 )
          this->m_iBurstShotsRemaining.m_Value = 2;
        this->m_fNextBurstShot = *(float *)(gpGlobals.m_Index + 12) + 0.075000003;
      }
      if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime, weaponMode: this->m_weaponMode.m_Value) != 0
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        C_BaseEntity::CalcAbsoluteVelocity(this: v4);
        if ( fsqrt(
               (float)(v4->m_vecAbsVelocity.x * v4->m_vecAbsVelocity.x)
             + (float)(v4->m_vecAbsVelocity.y * v4->m_vecAbsVelocity.y)) <= 5.0 )
        {
          m_fFlags = v4->m_fFlags;
          if ( (m_fFlags & 1) != 0 )
          {
            if ( (m_fFlags & 2) != 0 )
              C_CSPlayer::KickBack(
                this: v4,
                up_base: 0.57499999,
                lateral_base: 0.32499999,
                up_modifier: 0.2,
                lateral_modifier: 0.011,
                up_max: 3.25,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)8);
            else
              C_CSPlayer::KickBack(
                this: v4,
                up_base: 0.625,
                lateral_base: 0.375,
                up_modifier: 0.25,
                lateral_modifier: 0.0125,
                up_max: 3.5,
                lateral_max: 2.25,
                direction_change: (IUniformRandomStream *)8);
          }
          else
          {
            C_CSPlayer::KickBack(
              this: v4,
              up_base: 1.25,
              lateral_base: 0.44999999,
              up_modifier: 0.22,
              lateral_modifier: 0.18000001,
              up_max: 5.5,
              lateral_max: 4.0,
              direction_change: (IUniformRandomStream *)5);
          }
        }
        else
        {
          C_CSPlayer::KickBack(
            this: v4,
            up_base: 1.0,
            lateral_base: 0.44999999,
            up_modifier: 0.27500001,
            lateral_modifier: 0.050000001,
            up_max: 4.0,
            lateral_max: 2.5,
            direction_change: (IUniformRandomStream *)7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E650
// Name: public: void C_WeaponFamas::FireRemaining(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_WeaponFamas::FireRemaining(C_WeaponFamas *this@<ecx>, const char *a2@<edi>)
{
  C_CSPlayer *v3; // eax
  C_CSPlayer *v4; // edi
  const QAngle *(__thiscall *GetPunchAngle)(C_BasePlayer *); // eax
  char v6; // bl
  float *v7; // eax
  C_CSPlayer_vtbl *v8; // edx
  float v9; // xmm1_4
  const QAngle *(__thiscall *EyeAngles)(C_BaseEntity *); // eax
  float *v11; // eax
  C_WeaponFamas_vtbl *v12; // edx
  CSWeaponID v13; // xmm0_4
  float (__thiscall *GetSpread)(C_WeaponCSBase *); // eax
  int v15; // eax
  float v16; // xmm0_4
  const CCSWeaponInfo *CSWpnData; // eax
  float m_Value; // xmm1_4
  float v19; // xmm0_4
  const Vector *v20; // [esp-4h] [ebp-58h]
  CSWeaponID v21; // [esp+8h] [ebp-4Ch]
  float fSpread; // [esp+14h] [ebp-40h]
  float flSoundTime; // [esp+18h] [ebp-3Ch]
  QAngle vAngles; // [esp+28h] [ebp-2Ch] BYREF
  CSWeaponID iWeaponID[3]; // [esp+34h] [ebp-20h] BYREF
  float v27; // [esp+40h] [ebp-14h]
  float v28; // [esp+44h] [ebp-10h]
  float v29; // [esp+48h] [ebp-Ch]
  float fInaccuracy; // [esp+4Ch] [ebp-8h]
  float v31; // [esp+50h] [ebp-4h]

  if ( --this->m_iClip1.m_Value >= 0 )
  {
    C_WeaponCSBase::GetPlayerOwner(this);
    v4 = v3;
    if ( v3 == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_104CEB60, a2);
    fInaccuracy = this->GetInaccuracy(this);
    GetPunchAngle = v4->GetPunchAngle;
    v6 = C_BaseEntity::m_nPredictionRandomSeed;
    v31 = weapon_recoil_extra.m_pParent->m_Value.m_fValue + 1.0;
    v7 = (float *)GetPunchAngle(this: v4);
    v8 = v4->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    v27 = *v7 * v31;
    v28 = v7[1] * v31;
    v9 = v7[2];
    EyeAngles = v8->EyeAngles;
    v29 = v9 * v31;
    v11 = (float *)EyeAngles(this: v4);
    v12 = this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    *(float *)iWeaponID = *v11 + v27;
    *(float *)&iWeaponID[1] = v11[1] + v28;
    *(float *)&v13 = v11[2] + (float)(v9 * v31);
    GetSpread = v12->GetSpread;
    iWeaponID[2] = v13;
    flSoundTime = ((double (__thiscall *)(C_WeaponFamas *, _DWORD))GetSpread)(
                    a1: this,
                    a2: LODWORD(this->m_fNextBurstShot));
    fSpread = fInaccuracy;
    v21 = this->GetCSWeaponID(this);
    v20 = (const Vector *)((int (__thiscall *)(C_CSPlayer *))v4->Weapon_ShootPosition)(a1: v4);
    v15 = v4->entindex(this: &v4->IClientNetworkable);
    FX_FireBullets(
      iPlayerIndex: v15,
      vOrigin: v20,
      &vAngles,
      (CSWeaponID)iWeaponID,
      iMode: v21,
      iSeed: 1,
      fInaccuracy: COERCE_FLOAT(v6),
      fSpread,
      flSoundTime);
    this->SendWeaponAnim(this, a2: 190);
    v4->DoMuzzleFlash(this: v4);
    v4->SetAnimation(this: v4, a2: PLAYER_ATTACK1);
    ++v4->m_iShotsFired.m_Value;
    if ( --this->m_iBurstShotsRemaining.m_Value <= 0 )
      v16 = 0.0;
    else
      v16 = this->m_fNextBurstShot + 0.075000003;
    this->m_fNextBurstShot = v16;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    m_Value = this->m_fAccuracyPenalty.m_Value;
    v19 = CSWpnData->m_fInaccuracyImpulseFire[1] + m_Value;
    if ( m_Value != v19 )
      this->m_fAccuracyPenalty.m_Value = v19;
    if ( weapon_recoil_legacy.m_pParent == nullptr || weapon_recoil_legacy.m_pParent->m_Value.m_nValue == 0 )
      C_CSPlayer::KickBack(
        this: v4,
        fAngle: CSWpnData->m_fRecoilAngle[1],
        fAngleVariance: CSWpnData->m_fRecoilAngleVariance[1],
        fMagnitude: CSWpnData->m_fRecoilMagnitude[1],
        fMagnitudeVariance: CSWpnData->m_fRecoilMagnitudeVariance[1]);
  }
  else
  {
    this->m_iClip1.m_Value = 0;
    if ( this->m_iBurstShotsRemaining.m_Value != 0 )
      this->m_iBurstShotsRemaining.m_Value = 0;
    this->m_fNextBurstShot = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E8C0
// Name: public: virtual void C_WeaponFamas::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_WeaponFamas::ItemPostFrame(C_WeaponFamas *this@<ecx>, const char *a2@<edi>)
{
  if ( this->m_iBurstShotsRemaining.m_Value > 0 && *(float *)(gpGlobals.m_Index + 12) >= this->m_fNextBurstShot )
    C_WeaponFamas::FireRemaining(this, a2);
  C_WeaponCSBase::ItemPostFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022E8F0
// Name: public: virtual bool C_WeaponFamas::IsFullAuto(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_WeaponFamas::IsFullAuto(C_WeaponFamas *this)
{
  return this->m_weaponMode.m_Value == Primary_Mode;
}

//------------------------------------------------------------------------------
// Address: 0x1022E980
// Name: CC_WeaponFamasFactory
// Source: json
//------------------------------------------------------------------------------
C_WeaponCSBaseGun *__cdecl CC_WeaponFamasFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  C_WeaponCSBaseGun *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_WeaponCSBaseGun_vtbl *)&C_WeaponFamas::`vftable'{for `IClientUnknown'};
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_WeaponFamas::`vftable'{for `IClientRenderable'};
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_WeaponFamas::`vftable'{for `IClientNetworkable'};
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_WeaponFamas::`vftable'{for `IClientThinkable'};
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_WeaponFamas::`vftable';
  if ( LOBYTE(v1[1].C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable) != 0 )
    LOBYTE(v1[1].C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable) = 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x104287B0
// Name: DT_WeaponFamas::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponFamas::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponFamas::g_RecvTable);
  return atexit(func: DT_WeaponFamas::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104287D0
// Name: DT_WeaponFamas::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponFamas::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponFamas::ignored>();
  DT_WeaponFamas::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104287E0
// Name: C_WeaponFamas_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponFamas_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponFamas::m_PredMap.dataNumFields = 2;
  C_WeaponFamas::m_PredMap.dataDesc = (typedescription_t *)&unk_105B5C1C;
}

//------------------------------------------------------------------------------
// Address: 0x10428830
// Name: weapon_famasPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_famasPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_famasPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_famasPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436050
// Name: DT_WeaponFamas::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponFamas::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponFamas::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022E900
// Name: _C_WeaponFamas_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponFamas_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  C_WeaponCSBaseGun *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_WeaponCSBaseGun_vtbl *)&C_WeaponFamas::`vftable'{for `IClientUnknown'};
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_WeaponFamas::`vftable'{for `IClientRenderable'};
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_WeaponFamas::`vftable'{for `IClientNetworkable'};
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_WeaponFamas::`vftable'{for `IClientThinkable'};
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_WeaponFamas::`vftable';
  if ( LOBYTE(v3[1].C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable) != 0 )
    LOBYTE(v3[1].C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable) = 0;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10428800
// Name: _dynamic_initializer_for__g_Cweapon_famasFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_famasFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_WeaponCSBaseGun *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_famas",
             a3: "C_WeaponFamas",
             a4: 3520,
             a5: CC_WeaponFamasFactory);
  __g_C_WeaponFamasClientClass.m_pMapClassname = "weapon_famas";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428850
// Name: _dynamic_initializer_for____g_C_WeaponFiveSevenClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponFiveSevenClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponFiveSevenClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponFiveSevenClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EB4B0
// Name: public: virtual class ServerClass __near * CWeaponFamas::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponFamas::GetServerClass(CWeaponFamas *this)
{
  return &g_CWeaponFamas_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EB4C0
// Name: public: virtual void weapon_famasPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_famasPrecache::CResourcePrecacher::Cache(
        weapon_famasPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_famas",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EB5B0
// Name: public: virtual void CWeaponFamas::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponFamas::SecondaryAttack(CWeaponFamas *this)
{
  CCSPlayer *PlayerOwner; // eax
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  float v7; // xmm0_4
  edict_t *v8; // ecx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    if ( this->m_bBurstMode.m_Value )
    {
      ClientPrint(
        player: PlayerOwner,
        msg_dest: 4u,
        msg_name: "#Switch_To_FullAuto",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      if ( this->m_bBurstMode.m_Value )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C0u);
        }
        this->m_bBurstMode.m_Value = false;
      }
      if ( this->m_weaponMode.m_Value != Primary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_weaponMode.m_Value = Primary_Mode;
        }
        else
        {
          v4 = this->m_Network.m_pPev;
          if ( v4 != nullptr )
            CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x57Cu);
          this->m_weaponMode.m_Value = Primary_Mode;
        }
      }
    }
    else
    {
      ClientPrint(
        player: PlayerOwner,
        msg_dest: 4u,
        msg_name: "#Switch_To_BurstFire",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      if ( !this->m_bBurstMode.m_Value )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v5 = this->m_Network.m_pPev;
          if ( v5 != nullptr )
            CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x5C0u);
        }
        this->m_bBurstMode.m_Value = true;
      }
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v6 = this->m_Network.m_pPev;
          if ( v6 != nullptr )
            CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x57Cu);
        }
        this->m_weaponMode.m_Value = Secondary_Mode;
      }
    }
    v7 = gpGlobals->curtime + 0.3;
    if ( this->m_flNextSecondaryAttack.m_Value != v7 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flNextSecondaryAttack.m_Value = v7;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x498u);
        this->m_flNextSecondaryAttack.m_Value = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EB760
// Name: public: virtual void CWeaponFamas::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponFamas::PrimaryAttack(CWeaponFamas *this@<ecx>, int a2@<ebp>)
{
  CCSPlayer *PlayerOwner; // edi
  float m_flCycleTime; // xmm0_4
  edict_t *m_pPev; // ecx
  int m_Value; // eax
  int v7; // [esp+4Ch] [ebp-Ch] BYREF
  CCSPlayer *pPlayer; // [esp+50h] [ebp-8h]
  float flCycleTime; // [esp+54h] [ebp-4h] BYREF
  CCSPlayer *retaddr; // [esp+58h] [ebp+0h]

  v7 = a2;
  pPlayer = retaddr;
  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
    if ( PlayerOwner != nullptr )
    {
      m_flCycleTime = CWeaponCSBase::GetCSWpnData(this)->m_flCycleTime;
      if ( this->m_bBurstMode.m_Value )
      {
        m_flCycleTime = 0.55000001;
        if ( this->m_iBurstShotsRemaining.m_Value != 2 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
            {
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C4u);
              m_flCycleTime = 0.55000001;
            }
          }
          this->m_iBurstShotsRemaining.m_Value = 2;
        }
        this->m_fNextBurstShot = gpGlobals->curtime + 0.075000003;
      }
      if ( CWeaponCSBaseGun::CSBaseGunFire(
             this,
             a2: (int)&flCycleTime,
             flCycleTime: m_flCycleTime,
             weaponMode: this->m_weaponMode.m_Value) != 0
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (PlayerOwner->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: PlayerOwner, a2: (int)&v7);
        if ( fsqrt(
               (float)(PlayerOwner->m_vecAbsVelocity.x * PlayerOwner->m_vecAbsVelocity.x)
             + (float)(PlayerOwner->m_vecAbsVelocity.y * PlayerOwner->m_vecAbsVelocity.y)) <= 5.0 )
        {
          m_Value = PlayerOwner->m_fFlags.m_Value;
          if ( (m_Value & 1) != 0 )
          {
            if ( (m_Value & 2) != 0 )
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.57499999,
                lateral_base: 0.32499999,
                up_modifier: 0.2,
                lateral_modifier: 0.011,
                up_max: 3.25,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)8);
            else
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.625,
                lateral_base: 0.375,
                up_modifier: 0.25,
                lateral_modifier: 0.0125,
                up_max: 3.5,
                lateral_max: 2.25,
                direction_change: (IUniformRandomStream *)8);
          }
          else
          {
            CCSPlayer::KickBack(
              this: PlayerOwner,
              up_base: 1.25,
              lateral_base: 0.44999999,
              up_modifier: 0.22,
              lateral_modifier: 0.18000001,
              up_max: 5.5,
              lateral_max: 4.0,
              direction_change: (IUniformRandomStream *)5);
          }
        }
        else
        {
          CCSPlayer::KickBack(
            this: PlayerOwner,
            up_base: 1.0,
            lateral_base: 0.44999999,
            up_modifier: 0.27500001,
            lateral_modifier: 0.050000001,
            up_max: 4.0,
            lateral_max: 2.5,
            direction_change: (IUniformRandomStream *)7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EBA10
// Name: public: void CWeaponFamas::FireRemaining(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponFamas::FireRemaining(CWeaponFamas *this)
{
  int v2; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  CCSPlayer *PlayerOwner; // edi
  char v7; // bl
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // eax
  CCSPlayer_vtbl *v9; // edx
  float z; // xmm1_4
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // eax
  float *v12; // eax
  float v13; // xmm0_4
  edict_t *v14; // eax
  const Vector *v15; // eax
  float v16; // edx
  CBaseEdict *v17; // ecx
  float v18; // edx
  edict_t *v19; // ecx
  float v20; // xmm0_4
  const CCSWeaponInfo *CSWpnData; // eax
  float m_Value; // xmm1_4
  float *v23; // ebx
  float v24; // xmm0_4
  edict_t *v25; // ecx
  CSWeaponID v26; // [esp+8h] [ebp-4Ch]
  float fSpread; // [esp+14h] [ebp-40h]
  const char *v28; // [esp+1Ch] [ebp-38h]
  QAngle vAngles; // [esp+28h] [ebp-2Ch] BYREF
  CSWeaponID iWeaponID[3]; // [esp+34h] [ebp-20h] BYREF
  float v31; // [esp+40h] [ebp-14h]
  float v32; // [esp+44h] [ebp-10h]
  float v33; // [esp+48h] [ebp-Ch]
  float fInaccuracy; // [esp+4Ch] [ebp-8h]
  int iPlayerIndex; // [esp+50h] [ebp-4h]
  int savedregs; // [esp+54h] [ebp+0h] BYREF

  v2 = this->m_iClip1.m_Value - 1;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
  }
  this->m_iClip1.m_Value = v2;
  if ( this->m_iClip1.m_Value >= 0 )
  {
    PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
    if ( PlayerOwner == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_104F2D7C, a2: v28);
    fInaccuracy = this->GetInaccuracy(this);
    v7 = CBaseEntity::m_nPredictionRandomSeed;
    *(float *)&iPlayerIndex = weapon_recoil_extra.m_pParent->m_Value.m_fValue + 1.0;
    PunchAngle = CBasePlayer::GetPunchAngle(this: PlayerOwner);
    v9 = PlayerOwner->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v31 = PunchAngle->m_Value.x * *(float *)&iPlayerIndex;
    v32 = PunchAngle->m_Value.y * *(float *)&iPlayerIndex;
    z = PunchAngle->m_Value.z;
    EyeAngles = v9->EyeAngles;
    v33 = z * *(float *)&iPlayerIndex;
    v12 = (float *)EyeAngles(this: PlayerOwner);
    *(float *)iWeaponID = *v12 + v31;
    *(float *)&iWeaponID[1] = v12[1] + v32;
    v13 = v12[2];
    v14 = PlayerOwner->m_Network.m_pPev;
    *(float *)&iWeaponID[2] = v13 + (float)(z * *(float *)&iPlayerIndex);
    if ( v14 != nullptr )
      iPlayerIndex = v14 - gpGlobals->pEdicts;
    else
      *(float *)&iPlayerIndex = 0.0;
    ((void (__thiscall *)(CWeaponFamas *, _DWORD))this->GetSpread)(a1: this, a2: LODWORD(this->m_fNextBurstShot));
    fSpread = fInaccuracy;
    v26 = this->GetCSWeaponID(this);
    v15 = (const Vector *)((int (__thiscall *)(CCSPlayer *))PlayerOwner->Weapon_ShootPosition)(a1: PlayerOwner);
    FX_FireBullets(
      a1: COERCE_FLOAT(&savedregs),
      iPlayerIndex,
      vOrigin: v15,
      &vAngles,
      (CSWeaponID)iWeaponID,
      iMode: v26,
      iSeed: 1,
      fInaccuracy: COERCE_FLOAT(v7),
      fSpread);
    this->SendWeaponAnim(this, a2: 190);
    PlayerOwner->DoMuzzleFlash(this: PlayerOwner);
    PlayerOwner->SetAnimation(this: PlayerOwner, a2: PLAYER_ATTACK1);
    LODWORD(v16) = PlayerOwner->m_iShotsFired.m_Value + 1;
    fInaccuracy = v16;
    if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
    }
    else
    {
      v17 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
      if ( v17 != nullptr )
      {
        CBaseEdict::StateChanged(this: v17, offset: 0x1788u);
        v16 = fInaccuracy;
      }
    }
    *(float *)&PlayerOwner->m_iShotsFired.m_Value = v16;
    LODWORD(v18) = this->m_iBurstShotsRemaining.m_Value - 1;
    fInaccuracy = v18;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v19 = this->m_Network.m_pPev;
      if ( v19 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0x5C4u);
        v18 = fInaccuracy;
      }
    }
    *(float *)&this->m_iBurstShotsRemaining.m_Value = v18;
    if ( this->m_iBurstShotsRemaining.m_Value <= 0 )
      v20 = 0.0;
    else
      v20 = this->m_fNextBurstShot + 0.075000003;
    this->m_fNextBurstShot = v20;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    m_Value = this->m_fAccuracyPenalty.m_Value;
    v23 = (float *)CSWpnData;
    fInaccuracy = CSWpnData->m_fInaccuracyImpulseFire[1] + m_Value;
    v24 = fInaccuracy;
    if ( m_Value != fInaccuracy )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v25 = this->m_Network.m_pPev;
        if ( v25 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v25->CBaseEdict, offset: 0x580u);
          v24 = fInaccuracy;
        }
      }
      this->m_fAccuracyPenalty.m_Value = v24;
    }
    if ( weapon_recoil_legacy.m_pParent == nullptr || weapon_recoil_legacy.m_pParent->m_Value.m_nValue == 0 )
      CCSPlayer::KickBack(
        this: PlayerOwner,
        fAngle: v23[593],
        fAngleVariance: v23[595],
        fMagnitude: v23[597],
        fMagnitudeVariance: v23[599]);
  }
  else
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x4B0u);
    }
    this->m_iClip1.m_Value = 0;
    if ( this->m_iBurstShotsRemaining.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x5C4u);
      }
      this->m_iBurstShotsRemaining.m_Value = 0;
    }
    this->m_fNextBurstShot = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EBD80
// Name: public: virtual void CWeaponFamas::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponFamas::ItemPostFrame(CWeaponFamas *this@<ecx>, int a2@<edi>)
{
  if ( this->m_iBurstShotsRemaining.m_Value > 0 && gpGlobals->curtime >= this->m_fNextBurstShot )
    CWeaponFamas::FireRemaining(this);
  CWeaponCSBase::ItemPostFrame(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x102EBDB0
// Name: public: CWeaponFamas::CWeaponFamas(void)
// Source: json
//------------------------------------------------------------------------------
CWeaponFamas *__thiscall CWeaponFamas::CWeaponFamas(CWeaponFamas *this)
{
  CWeaponFamas *result; // eax
  edict_t *m_pPev; // ecx

  CWeaponCSBaseGun::CWeaponCSBaseGun(this);
  this->__vftable = (CWeaponFamas_vtbl *)&CWeaponFamas::`vftable';
  result = this;
  if ( this->m_bBurstMode.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bBurstMode.m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C0u);
      this->m_bBurstMode.m_Value = false;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EBE00
// Name: public: virtual bool CWeaponFamas::IsFullAuto(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWeaponFamas::IsFullAuto(CWeaponFamas *this)
{
  return this->m_weaponMode.m_Value == Primary_Mode;
}

//------------------------------------------------------------------------------
// Address: 0x104124C0
// Name: DT_WeaponFamas::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponFamas::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponFamas::g_SendTable);
  return atexit(func: DT_WeaponFamas::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104124E0
// Name: DT_WeaponFamas::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponFamas::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponFamas::ignored>();
  DT_WeaponFamas::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412510
// Name: weapon_famasPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_famasPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_famasPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_famasPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104209E0
// Name: DT_WeaponFamas::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponFamas::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponFamas::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412530
// Name: _dynamic_initializer_for__g_CWeaponFiveSeven_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponFiveSeven_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponFiveSeven_ClassReg,
           pNetworkName: "CWeaponFiveSeven",
           pTable: &DT_WeaponFiveSeven::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104209F0
// Name: _ServerClassInit_DT_WeaponFamas::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponFamas::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_277;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
