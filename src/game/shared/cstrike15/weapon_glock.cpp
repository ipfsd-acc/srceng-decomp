// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_glock.cpp
// Functions: 19
// ============================================================

#include "game\shared\cstrike15\weapon_glock.h"

//------------------------------------------------------------------------------
// Address: 0x1022E2E0
// Name: public: virtual bool C_WeaponGlock::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponGlock::Deploy(C_WeaponFamas *this)
{
  if ( this->m_iBurstShotsRemaining.m_Value != 0 )
    this->m_iBurstShotsRemaining.m_Value = 0;
  this->m_fNextBurstShot = 0.0;
  return C_WeaponCSBase::Deploy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022F620
// Name: public: virtual class ClientClass __near * C_WeaponGlock::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponGlock::GetClientClass(C_WeaponGlock *this)
{
  return &__g_C_WeaponGlockClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022F6D0
// Name: public: virtual struct datamap_t __near * C_WeaponGlock::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponGlock::GetPredDescMap(C_WeaponGlock *this)
{
  return &C_WeaponGlock::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022F6E0
// Name: public: virtual void weapon_glockPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_glockPrecache::CResourcePrecacher::Cache(
        weapon_glockPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_glock",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022F710
// Name: public: virtual void C_WeaponGlock::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponGlock::Spawn(C_WeaponGlock *this)
{
  C_BaseCombatWeapon::Spawn(this);
  if ( this->m_bBurstMode.m_Value )
    this->m_bBurstMode.m_Value = false;
  if ( this->m_iBurstShotsRemaining.m_Value != 0 )
    this->m_iBurstShotsRemaining.m_Value = 0;
  this->m_fNextBurstShot = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1022F750
// Name: public: virtual void C_WeaponGlock::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponGlock::SecondaryAttack(C_WeaponGlock *this)
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
// Address: 0x1022F810
// Name: public: virtual void C_WeaponGlock::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponGlock::PrimaryAttack(C_WeaponGlock *this)
{
  int v2; // eax
  float flCycleTime; // xmm0_4
  int v4; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    flCycleTime = C_WeaponCSBase::GetCSWpnData(this)->m_flCycleTime;
    if ( this->m_bBurstMode.m_Value )
      flCycleTime = 0.5;
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime, weaponMode: this->m_weaponMode.m_Value) != 0 )
    {
      C_WeaponCSBase::GetPlayerOwner(this);
      if ( v4 != 0 && this->m_bBurstMode.m_Value )
      {
        this->m_fNextBurstShot = *(float *)(gpGlobals.m_Index + 12) + 0.050000001;
        if ( this->m_iBurstShotsRemaining.m_Value != 2 )
          this->m_iBurstShotsRemaining.m_Value = 2;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022F8A0
// Name: public: void C_WeaponGlock::FireRemaining(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponGlock::FireRemaining(C_WeaponGlock *this, float fSpread)
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
  C_WeaponGlock_vtbl *v12; // edx
  CSWeaponID v13; // xmm0_4
  float (__thiscall *GetSpread)(C_WeaponCSBase *); // eax
  int v15; // eax
  float v16; // xmm0_4
  const CCSWeaponInfo *CSWpnData; // eax
  float m_Value; // xmm1_4
  float v19; // xmm0_4
  const Vector *v20; // [esp-4h] [ebp-54h]
  CSWeaponID v21; // [esp+8h] [ebp-48h]
  float fMagnitude; // [esp+14h] [ebp-3Ch]
  float flSoundTime; // [esp+18h] [ebp-38h]
  const char *v24; // [esp+1Ch] [ebp-34h]
  QAngle vAngles; // [esp+28h] [ebp-28h] BYREF
  CSWeaponID iWeaponID[3]; // [esp+34h] [ebp-1Ch] BYREF
  float v27; // [esp+40h] [ebp-10h]
  float v28; // [esp+44h] [ebp-Ch]
  float v29; // [esp+48h] [ebp-8h]
  float v30; // [esp+4Ch] [ebp-4h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v4 = v3;
  if ( v3 == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_104CEB60, a2: v24);
  if ( this->m_iBurstShotsRemaining.m_Value != 0 )
  {
    if ( this->m_iClip1.m_Value > 0 )
    {
      --this->m_iClip1.m_Value;
      GetPunchAngle = v4->GetPunchAngle;
      v6 = C_BaseEntity::m_nPredictionRandomSeed;
      v30 = weapon_recoil_extra.m_pParent->m_Value.m_fValue + 1.0;
      v7 = (float *)GetPunchAngle(this: v4);
      v8 = v4->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v27 = *v7 * v30;
      v28 = v7[1] * v30;
      v9 = v7[2];
      EyeAngles = v8->EyeAngles;
      v29 = v9 * v30;
      v11 = (float *)EyeAngles(this: v4);
      v12 = this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      *(float *)iWeaponID = *v11 + v27;
      *(float *)&iWeaponID[1] = v11[1] + v28;
      *(float *)&v13 = v11[2] + (float)(v9 * v30);
      GetSpread = v12->GetSpread;
      iWeaponID[2] = v13;
      flSoundTime = ((double (__thiscall *)(C_WeaponGlock *, _DWORD))GetSpread)(
                      a1: this,
                      a2: LODWORD(this->m_fNextBurstShot));
      fMagnitude = this->GetInaccuracy(this);
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
        fSpread: fMagnitude,
        flSoundTime);
      this->SendWeaponAnim(this, a2: 190);
      v4->DoMuzzleFlash(this: v4);
      v4->SetAnimation(this: v4, a2: PLAYER_ATTACK1);
      ++v4->m_iShotsFired.m_Value;
      if ( --this->m_iBurstShotsRemaining.m_Value <= 0 )
        v16 = 0.0;
      else
        v16 = this->m_fNextBurstShot + 0.050000001;
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
      if ( this->m_iClip1.m_Value != 0 )
        this->m_iClip1.m_Value = 0;
      if ( this->m_iBurstShotsRemaining.m_Value != 0 )
        this->m_iBurstShotsRemaining.m_Value = 0;
      this->m_fNextBurstShot = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022FB10
// Name: public: virtual void C_WeaponGlock::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponGlock::ItemPostFrame(C_WeaponGlock *this)
{
  float fSpread; // [esp+0h] [ebp-8h]

  if ( this->m_iBurstShotsRemaining.m_Value > 0 && *(float *)(gpGlobals.m_Index + 12) > this->m_fNextBurstShot )
  {
    fSpread = this->GetSpread(this);
    C_WeaponGlock::FireRemaining(this, fSpread);
  }
  C_WeaponCSBaseGun::ItemPostFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022FB50
// Name: public: C_WeaponGlock::C_WeaponGlock(void)
// Source: json
//------------------------------------------------------------------------------
C_WeaponGlock *__thiscall C_WeaponGlock::C_WeaponGlock(C_WeaponGlock *this)
{
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this);
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_WeaponGlock_vtbl *)&C_WeaponGlock::`vftable'{for `IClientUnknown'};
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_WeaponGlock::`vftable'{for `IClientRenderable'};
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_WeaponGlock::`vftable'{for `IClientNetworkable'};
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_WeaponGlock::`vftable'{for `IClientThinkable'};
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_WeaponGlock::`vftable';
  if ( this->m_bBurstMode.m_Value )
    this->m_bBurstMode.m_Value = false;
  if ( this->m_iBurstShotsRemaining.m_Value != 0 )
    this->m_iBurstShotsRemaining.m_Value = 0;
  this->m_fNextBurstShot = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022FC00
// Name: CC_WeaponGlockFactory
// Source: json
//------------------------------------------------------------------------------
C_WeaponGlock *__cdecl CC_WeaponGlockFactory()
{
  C_WeaponGlock *v0; // eax

  v0 = (C_WeaponGlock *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  if ( v0 != nullptr )
    return C_WeaponGlock::C_WeaponGlock(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10428B70
// Name: DT_WeaponGlock::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponGlock::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponGlock::g_RecvTable);
  return atexit(func: DT_WeaponGlock::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428B90
// Name: DT_WeaponGlock::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponGlock::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponGlock::ignored>();
  DT_WeaponGlock::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428BA0
// Name: C_WeaponGlock_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponGlock_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponGlock::m_PredMap.dataNumFields = 2;
  C_WeaponGlock::m_PredMap.dataDesc = (typedescription_t *)&unk_105B5FFC;
}

//------------------------------------------------------------------------------
// Address: 0x10428BF0
// Name: weapon_glockPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_glockPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_glockPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_glockPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104360A0
// Name: DT_WeaponGlock::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponGlock::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponGlock::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022FBB0
// Name: _C_WeaponGlock_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponGlock_CreateObject(int entnum, int serialNum)
{
  C_WeaponGlock *v2; // eax
  C_WeaponGlock *v3; // eax
  C_WeaponGlock *v4; // esi

  v2 = (C_WeaponGlock *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_WeaponGlock::C_WeaponGlock(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10428BC0
// Name: _dynamic_initializer_for__g_Cweapon_glockFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_glockFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_WeaponGlock *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_glock",
             a3: "C_WeaponGlock",
             a4: 3520,
             a5: CC_WeaponGlockFactory);
  __g_C_WeaponGlockClientClass.m_pMapClassname = "weapon_glock";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428C10
// Name: _dynamic_initializer_for____g_C_HEGrenadeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_HEGrenadeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_HEGrenadeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_HEGrenadeClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102ECA50
// Name: public: virtual class ServerClass __near * CWeaponGlock::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponGlock::GetServerClass(CWeaponGlock *this)
{
  return &g_CWeaponGlock_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102ECA60
// Name: public: virtual void weapon_glockPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_glockPrecache::CResourcePrecacher::Cache(
        weapon_glockPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_glock",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102ECB50
// Name: public: virtual void CWeaponGlock::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponGlock::Spawn(CWeaponGlock *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  CWeaponCSBase::Spawn(this);
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
  if ( this->m_iBurstShotsRemaining.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x5C4u);
    }
    this->m_iBurstShotsRemaining.m_Value = 0;
  }
  this->m_fNextBurstShot = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102ECBD0
// Name: public: virtual bool CWeaponGlock::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponGlock::Deploy(CWeaponFamas *this)
{
  edict_t *m_pPev; // ecx

  if ( this->m_iBurstShotsRemaining.m_Value != 0 )
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
    this->m_iBurstShotsRemaining.m_Value = 0;
  }
  this->m_fNextBurstShot = 0.0;
  return CWeaponCSBase::Deploy(this);
}

//------------------------------------------------------------------------------
// Address: 0x102ECC20
// Name: public: virtual void CWeaponGlock::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponGlock::SecondaryAttack(CWeaponGlock *this)
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
        msg_name: "#Switch_To_SemiAuto",
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
// Address: 0x102ECDD0
// Name: public: virtual void CWeaponGlock::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponGlock::PrimaryAttack(CWeaponGlock *this@<ecx>, int a2@<ebx>)
{
  float flCycleTime; // xmm0_4
  edict_t *m_pPev; // ecx

  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    flCycleTime = CWeaponCSBase::GetCSWpnData(this)->m_flCycleTime;
    if ( this->m_bBurstMode.m_Value )
      flCycleTime = 0.5;
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2, flCycleTime, weaponMode: this->m_weaponMode.m_Value) != 0
      && CWeaponCSBase::GetPlayerOwner(this) != nullptr
      && this->m_bBurstMode.m_Value )
    {
      this->m_fNextBurstShot = gpGlobals->curtime + 0.050000001;
      if ( this->m_iBurstShotsRemaining.m_Value != 2 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_iBurstShotsRemaining.m_Value = 2;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C4u);
          this->m_iBurstShotsRemaining.m_Value = 2;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ECE90
// Name: public: void CWeaponGlock::FireRemaining(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWeaponGlock::FireRemaining(CWeaponGlock *this@<ecx>, int a2@<ebx>, float fSpread)
{
  CCSPlayer *PlayerOwner; // edi
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  int v7; // edx
  edict_t *m_pPev; // ecx
  char v9; // bl
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // eax
  CCSPlayer_vtbl *v11; // edx
  float z; // xmm1_4
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // eax
  float *v14; // eax
  float v15; // xmm0_4
  edict_t *v16; // eax
  const Vector *v17; // eax
  int v18; // edx
  CBaseEdict *v19; // ecx
  int v20; // edx
  edict_t *v21; // ecx
  float v22; // xmm0_4
  const CCSWeaponInfo *CSWpnData; // eax
  float m_Value; // xmm1_4
  float *v25; // ebx
  float v26; // xmm0_4
  edict_t *v27; // ecx
  CSWeaponID v28; // [esp+8h] [ebp-48h]
  float fMagnitude; // [esp+14h] [ebp-3Ch]
  float flSoundTime; // [esp+18h] [ebp-38h]
  const char *v32; // [esp+20h] [ebp-30h]
  QAngle vAngles; // [esp+28h] [ebp-28h] BYREF
  CSWeaponID iWeaponID[3]; // [esp+34h] [ebp-1Ch] BYREF
  float v35; // [esp+40h] [ebp-10h]
  float v36; // [esp+44h] [ebp-Ch]
  float v37; // [esp+48h] [ebp-8h]
  int iPlayerIndex; // [esp+4Ch] [ebp-4h]
  int savedregs; // [esp+50h] [ebp+0h] BYREF

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_104F2D7C, a2: v32);
  if ( this->m_iBurstShotsRemaining.m_Value != 0 )
  {
    if ( this->m_iClip1.m_Value > 0 )
    {
      v7 = this->m_iClip1.m_Value - 1;
      iPlayerIndex = v7;
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
          v7 = iPlayerIndex;
        }
      }
      this->m_iClip1.m_Value = v7;
      v9 = CBaseEntity::m_nPredictionRandomSeed;
      *(float *)&iPlayerIndex = weapon_recoil_extra.m_pParent->m_Value.m_fValue + 1.0;
      PunchAngle = CBasePlayer::GetPunchAngle(this: PlayerOwner);
      v11 = PlayerOwner->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v35 = PunchAngle->m_Value.x * *(float *)&iPlayerIndex;
      v36 = PunchAngle->m_Value.y * *(float *)&iPlayerIndex;
      z = PunchAngle->m_Value.z;
      EyeAngles = v11->EyeAngles;
      v37 = z * *(float *)&iPlayerIndex;
      v14 = (float *)((int (__thiscall *)(CCSPlayer *, int))EyeAngles)(a1: PlayerOwner, a2);
      *(float *)iWeaponID = v35 + *v14;
      *(float *)&iWeaponID[1] = v14[1] + v36;
      v15 = v14[2];
      v16 = PlayerOwner->m_Network.m_pPev;
      *(float *)&iWeaponID[2] = v15 + (float)(z * *(float *)&iPlayerIndex);
      if ( v16 != nullptr )
        iPlayerIndex = v16 - gpGlobals->pEdicts;
      else
        *(float *)&iPlayerIndex = 0.0;
      flSoundTime = ((double (__thiscall *)(CWeaponGlock *, _DWORD))this->GetSpread)(
                      a1: this,
                      a2: LODWORD(this->m_fNextBurstShot));
      fMagnitude = ((double (__thiscall *)(CWeaponGlock *, _DWORD))this->GetInaccuracy)(
                     a1: this,
                     a2: LODWORD(flSoundTime));
      v28 = this->GetCSWeaponID(this);
      v17 = (const Vector *)((int (__thiscall *)(CCSPlayer *))PlayerOwner->Weapon_ShootPosition)(a1: PlayerOwner);
      FX_FireBullets(
        a1: COERCE_FLOAT(&savedregs),
        iPlayerIndex,
        vOrigin: v17,
        &vAngles,
        (CSWeaponID)iWeaponID,
        iMode: v28,
        iSeed: 1,
        fInaccuracy: COERCE_FLOAT(v9),
        fSpread: fMagnitude);
      this->SendWeaponAnim(this, a2: 190);
      PlayerOwner->DoMuzzleFlash(this: PlayerOwner);
      PlayerOwner->SetAnimation(this: PlayerOwner, a2: PLAYER_ATTACK1);
      v18 = PlayerOwner->m_iShotsFired.m_Value + 1;
      iPlayerIndex = v18;
      if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
      }
      else
      {
        v19 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
        if ( v19 != nullptr )
        {
          CBaseEdict::StateChanged(this: v19, offset: 0x1788u);
          v18 = iPlayerIndex;
        }
      }
      PlayerOwner->m_iShotsFired.m_Value = v18;
      v20 = this->m_iBurstShotsRemaining.m_Value - 1;
      iPlayerIndex = v20;
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v21 = this->m_Network.m_pPev;
        if ( v21 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v21->CBaseEdict, offset: 0x5C4u);
          v20 = iPlayerIndex;
        }
      }
      this->m_iBurstShotsRemaining.m_Value = v20;
      if ( this->m_iBurstShotsRemaining.m_Value <= 0 )
        v22 = 0.0;
      else
        v22 = this->m_fNextBurstShot + 0.050000001;
      this->m_fNextBurstShot = v22;
      CSWpnData = CWeaponCSBase::GetCSWpnData(this);
      m_Value = this->m_fAccuracyPenalty.m_Value;
      v25 = (float *)CSWpnData;
      *(float *)&iPlayerIndex = CSWpnData->m_fInaccuracyImpulseFire[1] + m_Value;
      v26 = *(float *)&iPlayerIndex;
      if ( m_Value != *(float *)&iPlayerIndex )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v27 = this->m_Network.m_pPev;
          if ( v27 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v27->CBaseEdict, offset: 0x580u);
            v26 = *(float *)&iPlayerIndex;
          }
        }
        this->m_fAccuracyPenalty.m_Value = v26;
      }
      if ( weapon_recoil_legacy.m_pParent == nullptr || weapon_recoil_legacy.m_pParent->m_Value.m_nValue == 0 )
        CCSPlayer::KickBack(
          this: PlayerOwner,
          fAngle: v25[593],
          fAngleVariance: v25[595],
          fMagnitude: v25[597],
          fMagnitudeVariance: v25[599]);
    }
    else
    {
      if ( this->m_iClip1.m_Value != 0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v5 = this->m_Network.m_pPev;
          if ( v5 != nullptr )
            CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x4B0u);
        }
        this->m_iClip1.m_Value = 0;
      }
      if ( this->m_iBurstShotsRemaining.m_Value != 0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v6 = this->m_Network.m_pPev;
          if ( v6 != nullptr )
            CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x5C4u);
        }
        this->m_iBurstShotsRemaining.m_Value = 0;
      }
      this->m_fNextBurstShot = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED220
// Name: public: virtual void CWeaponGlock::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponGlock::ItemPostFrame(CWeaponGlock *this@<ecx>, int a2@<ebx>)
{
  float fSpread; // [esp+0h] [ebp-8h]

  if ( this->m_iBurstShotsRemaining.m_Value > 0 && gpGlobals->curtime > this->m_fNextBurstShot )
  {
    fSpread = this->GetSpread(this);
    CWeaponGlock::FireRemaining(this, a2, fSpread);
  }
  CWeaponCSBaseGun::ItemPostFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x102ED260
// Name: public: CWeaponGlock::CWeaponGlock(void)
// Source: json
//------------------------------------------------------------------------------
CWeaponGlock *__thiscall CWeaponGlock::CWeaponGlock(CWeaponGlock *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  CWeaponCSBaseGun::CWeaponCSBaseGun(this);
  this->__vftable = (CWeaponGlock_vtbl *)&CWeaponGlock::`vftable';
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
  if ( this->m_iBurstShotsRemaining.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x5C4u);
    }
    this->m_iBurstShotsRemaining.m_Value = 0;
  }
  this->m_fNextBurstShot = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102ED2F0
// Name: public: virtual enum CSWeaponID CWeaponGlock::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponGlock::GetCSWeaponID(CBaseAppSystem<IParticleSystemQuery> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x104127A0
// Name: DT_WeaponGlock::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponGlock::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponGlock::g_SendTable);
  return atexit(func: DT_WeaponGlock::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104127C0
// Name: DT_WeaponGlock::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponGlock::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponGlock::ignored>();
  DT_WeaponGlock::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104127F0
// Name: weapon_glockPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_glockPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_glockPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_glockPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420AE0
// Name: DT_WeaponGlock::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponGlock::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponGlock::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412810
// Name: _dynamic_initializer_for__g_CHEGrenade_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CHEGrenade_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CHEGrenade_ClassReg,
           pNetworkName: "CHEGrenade",
           pTable: &DT_HEGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420AF0
// Name: _ServerClassInit_DT_WeaponGlock::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponGlock::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_282;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
