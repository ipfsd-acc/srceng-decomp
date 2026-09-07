// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_csbasegun.cpp
// Functions: 16
// ============================================================

#include "game\shared\cstrike15\weapon_csbasegun.h"

//------------------------------------------------------------------------------
// Address: 0x1022D450
// Name: public: virtual class ClientClass __near * C_WeaponCSBaseGun::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponCSBaseGun::GetClientClass(C_WeaponCSBaseGun *this)
{
  return &__g_C_WeaponCSBaseGunClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022D4D0
// Name: public: virtual struct datamap_t __near * C_WeaponCSBaseGun::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponCSBaseGun::GetPredDescMap(C_WeaponCSBaseGun *this)
{
  return &C_WeaponCSBaseGun::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022D4E0
// Name: public: virtual void C_WeaponCSBaseGun::DoFireEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBaseGun::DoFireEffects(C_WeaponCSBaseGun *this)
{
  int v1; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v1 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 824))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1022D500
// Name: public: virtual void C_WeaponCSBaseGun::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBaseGun::WeaponIdle(C_WeaponCSBaseGun *this)
{
  C_WeaponCSBaseGun_vtbl *v2; // edi
  const CCSWeaponInfo *CSWpnData; // eax

  if ( this->m_flTimeWeaponIdle.m_Value <= *(float *)(gpGlobals.m_Index + 12) && this->m_iClip1.m_Value != 0 )
  {
    v2 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    ((void (__thiscall *)(C_WeaponCSBaseGun *, _DWORD))v2->SetWeaponIdleTime)(
      a1: this,
      a2: CSWpnData->m_flIdleInterval + *(float *)(gpGlobals.m_Index + 12));
    this->SendWeaponAnim(this, a2: 183);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D560
// Name: public: virtual void C_WeaponCSBaseGun::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBaseGun::ItemPostFrame(C_WeaponCSBaseGun *this)
{
  int v2; // eax
  int v3; // edi

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != 0 )
  {
    if ( *(float *)(gpGlobals.m_Index + 12) >= this->m_flNextPrimaryAttack.m_Value && *(_BYTE *)(v2 + 6764) == 1 )
    {
      if ( *(_BYTE *)(v2 + 6764) != 0 )
        *(_BYTE *)(v2 + 6764) = 0;
      if ( (this->m_iClip1.m_Value != 0 || (this->GetWeaponFlags(this) & 2) != 0)
        && (this->GetCSWeaponID(this) == WEAPON_SSG08 || this->GetCSWeaponID(this) == WEAPON_AWP) )
      {
        if ( this->m_weaponMode.m_Value != Secondary_Mode )
          this->m_weaponMode.m_Value = Secondary_Mode;
        C_BasePlayer::SetFOV(
          this: (C_BasePlayer *)v3,
          pRequester: (C_BaseEntity *)v3,
          FOV: *(_DWORD *)(v3 + 6768),
          zoomRate: 0.050000001,
          iZoomStart: 0);
      }
    }
    C_WeaponCSBase::ItemPostFrame(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D620
// Name: public: virtual bool C_WeaponCSBaseGun::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponCSBaseGun::Reload(C_WeaponCSBaseGun *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int zoomRate; // [esp+4h] [ebp-18h]
  float v9; // [esp+14h] [ebp-8h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 == nullptr )
    return 0;
  v5 = this->GetPrimaryAmmoType(this);
  if ( C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v5) <= 0 )
    return 0;
  zoomRate = this->GetMaxClip2(this);
  v6 = this->GetMaxClip1(this);
  if ( C_BaseCombatWeapon::DefaultReload(this, iClipSize1: v6, iClipSize2: zoomRate, iActivity: 192) == 0 )
    return 0;
  v3->SetAnimation(this: v3, a2: PLAYER_RELOAD);
  v9 = v3->GetFOV(this: v3);
  if ( v9 != (double)v3->GetDefaultFOV(this: v3) )
  {
    v7 = v3->GetDefaultFOV(this: v3);
    C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: v7, zoomRate: 0.0, iZoomStart: 0);
  }
  if ( v3[1].m_cellbits != 0 )
    v3[1].m_cellbits = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022D700
// Name: public: bool C_WeaponCSBaseGun::CSBaseGunFire(float,enum CSWeaponMode)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponCSBaseGun::CSBaseGunFire(C_WeaponCSBaseGun *this, float flCycleTime, CSWeaponMode weaponMode)
{
  C_CSPlayer *v4; // eax
  C_CSPlayer *v5; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  bool v7; // zf
  float v8; // xmm0_4
  char v10; // bl
  float *v11; // eax
  C_CSPlayer_vtbl *v12; // edx
  float v13; // xmm1_4
  const QAngle *(__thiscall *EyeAngles)(C_BaseEntity *); // eax
  float *v15; // eax
  C_WeaponCSBaseGun_vtbl *v16; // edx
  CSWeaponID v17; // xmm0_4
  float (__thiscall *GetSpread)(C_WeaponCSBase *); // eax
  int v19; // eax
  const CCSWeaponInfo *v20; // ebx
  float m_Value; // xmm1_4
  float v22; // xmm0_4
  const Vector *v23; // [esp+0h] [ebp-58h]
  CSWeaponID v24; // [esp+Ch] [ebp-4Ch]
  float fSpread; // [esp+18h] [ebp-40h]
  float flSoundTime; // [esp+1Ch] [ebp-3Ch]
  QAngle vAngles; // [esp+2Ch] [ebp-2Ch] BYREF
  CSWeaponID iWeaponID[3]; // [esp+38h] [ebp-20h] BYREF
  float v29; // [esp+44h] [ebp-14h]
  float v30; // [esp+48h] [ebp-10h]
  float v31; // [esp+4Ch] [ebp-Ch]
  const CCSWeaponInfo *weaponInfo; // [esp+50h] [ebp-8h]
  float flCurAttack; // [esp+54h] [ebp-4h]
  float flCycleTimea; // [esp+60h] [ebp+8h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
  v7 = this->m_iClip1.m_Value == 0;
  weaponInfo = CSWpnData;
  if ( v7 )
  {
    if ( this->m_bFireOnEmpty )
    {
      C_WeaponCSBase::PlayEmptySound(this);
      ++v5->m_iShotsFired.m_Value;
      v8 = *(float *)(gpGlobals.m_Index + 12) + 0.2;
      if ( this->m_flNextPrimaryAttack.m_Value != v8 )
        this->m_flNextPrimaryAttack.m_Value = v8;
    }
    return 0;
  }
  flCurAttack = C_WeaponCSBase::CalculateNextAttackTime(this, fCycleTime: flCycleTime);
  this->SendWeaponAnim(this, a2: 190);
  ++v5->m_iShotsFired.m_Value;
  --this->m_iClip1.m_Value;
  v5->SetAnimation(this: v5, a2: PLAYER_ATTACK1);
  v10 = C_BaseEntity::m_nPredictionRandomSeed;
  flCycleTimea = weapon_recoil_extra.m_pParent->m_Value.m_fValue + 1.0;
  v11 = (float *)v5->GetPunchAngle(this: v5);
  v12 = v5->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v29 = flCycleTimea * *v11;
  v30 = v11[1] * flCycleTimea;
  v13 = v11[2];
  EyeAngles = v12->EyeAngles;
  v31 = v13 * flCycleTimea;
  v15 = (float *)EyeAngles(this: v5);
  v16 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  *(float *)iWeaponID = v29 + *v15;
  *(float *)&iWeaponID[1] = v15[1] + v30;
  *(float *)&v17 = v15[2] + (float)(v13 * flCycleTimea);
  GetSpread = v16->GetSpread;
  iWeaponID[2] = v17;
  flSoundTime = ((double (__thiscall *)(C_WeaponCSBaseGun *, _DWORD))GetSpread)(a1: this, a2: LODWORD(flCurAttack));
  fSpread = this->GetInaccuracy(this);
  v24 = this->GetCSWeaponID(this);
  v23 = (const Vector *)((int (__thiscall *)(C_CSPlayer *))v5->Weapon_ShootPosition)(a1: v5);
  v19 = v5->entindex(this: &v5->IClientNetworkable);
  FX_FireBullets(
    iPlayerIndex: v19,
    vOrigin: v23,
    &vAngles,
    (CSWeaponID)iWeaponID,
    iMode: v24,
    iSeed: weaponMode,
    fInaccuracy: COERCE_FLOAT(v10),
    fSpread,
    flSoundTime);
  this->DoFireEffects(this);
  v20 = weaponInfo;
  ((void (__thiscall *)(C_WeaponCSBaseGun *, _DWORD))this->SetWeaponIdleTime)(
    a1: this,
    a2: weaponInfo->m_flTimeToIdleAfterFire + *(float *)(gpGlobals.m_Index + 12));
  m_Value = this->m_fAccuracyPenalty.m_Value;
  v22 = v20->m_fInaccuracyImpulseFire[weaponMode] + m_Value;
  if ( m_Value != v22 )
    this->m_fAccuracyPenalty.m_Value = v22;
  if ( weapon_recoil_legacy.m_pParent == nullptr || weapon_recoil_legacy.m_pParent->m_Value.m_nValue == 0 )
    C_CSPlayer::KickBack(
      this: v5,
      fAngle: v20->m_fRecoilAngle[weaponMode],
      fAngleVariance: v20->m_fRecoilAngleVariance[weaponMode],
      fMagnitude: v20->m_fRecoilMagnitude[weaponMode],
      fMagnitudeVariance: v20->m_fRecoilMagnitudeVariance[weaponMode]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022D9A0
// Name: public: C_WeaponCSBaseGun::C_WeaponCSBaseGun(void)
// Source: json
//------------------------------------------------------------------------------
C_WeaponCSBaseGun *__thiscall C_WeaponCSBaseGun::C_WeaponCSBaseGun(C_WeaponCSBaseGun *this)
{
  C_WeaponCSBase::C_WeaponCSBase(this);
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_WeaponCSBaseGun_vtbl *)&C_WeaponCSBaseGun::`vftable'{for `IClientUnknown'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_WeaponCSBaseGun::`vftable'{for `IClientRenderable'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_WeaponCSBaseGun::`vftable'{for `IClientNetworkable'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_WeaponCSBaseGun::`vftable'{for `IClientThinkable'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_WeaponCSBaseGun::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022DA40
// Name: CC_WeaponCSBaseGunFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponCSBaseGunFactory()
{
  C_WeaponCSBase *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v0);
  *v1 = &C_WeaponCSBaseGun::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponCSBaseGun::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponCSBaseGun::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponCSBaseGun::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponCSBaseGun::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x104284D0
// Name: DT_WeaponCSBaseGun::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCSBaseGun::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponCSBaseGun::g_RecvTable);
  return atexit(func: DT_WeaponCSBaseGun::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104284F0
// Name: DT_WeaponCSBaseGun::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCSBaseGun::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponCSBaseGun::ignored>();
  DT_WeaponCSBaseGun::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428500
// Name: C_WeaponCSBaseGun_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponCSBaseGun_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponCSBaseGun::m_PredMap.dataNumFields = 1;
  C_WeaponCSBaseGun::m_PredMap.dataDesc = (typedescription_t *)&unk_1066AE1C;
}

//------------------------------------------------------------------------------
// Address: 0x10436010
// Name: DT_WeaponCSBaseGun::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponCSBaseGun::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponCSBaseGun::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022D9D0
// Name: _C_WeaponCSBaseGun_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponCSBaseGun_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBase *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v2);
  *v3 = &C_WeaponCSBaseGun::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponCSBaseGun::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponCSBaseGun::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponCSBaseGun::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponCSBaseGun::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10428520
// Name: _dynamic_initializer_for__g_Cweapon_csbase_gunFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_csbase_gunFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_csbase_gun",
             a3: "C_WeaponCSBaseGun",
             a4: 3504,
             a5: CC_WeaponCSBaseGunFactory);
  __g_C_WeaponCSBaseGunClientClass.m_pMapClassname = "weapon_csbase_gun";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428550
// Name: _dynamic_initializer_for____g_C_DEagleClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_DEagleClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_DEagleClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_DEagleClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EA720
// Name: public: virtual class ServerClass __near * CWeaponCSBaseGun::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponCSBaseGun::GetServerClass(CWeaponCSBaseGun *this)
{
  return &g_CWeaponCSBaseGun_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EA730
// Name: public: virtual void CWeaponCSBaseGun::DoFireEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBaseGun::DoFireEffects(CWeaponCSBaseGun *this)
{
  CCSPlayer *PlayerOwner; // eax

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
    PlayerOwner->DoMuzzleFlash(this: PlayerOwner);
}

//------------------------------------------------------------------------------
// Address: 0x102EA750
// Name: public: virtual void CWeaponCSBaseGun::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBaseGun::WeaponIdle(CWeaponCSBaseGun *this)
{
  CWeaponCSBaseGun_vtbl *v2; // edi
  const CCSWeaponInfo *CSWpnData; // eax

  if ( this->m_flTimeWeaponIdle.m_Value <= gpGlobals->curtime && this->m_iClip1.m_Value != 0 )
  {
    v2 = this->__vftable;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    ((void (__thiscall *)(CWeaponCSBaseGun *, _DWORD))v2->SetWeaponIdleTime)(
      a1: this,
      a2: CSWpnData->m_flIdleInterval + gpGlobals->curtime);
    this->SendWeaponAnim(this, a2: 183);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EA830
// Name: public: virtual void CWeaponCSBaseGun::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBaseGun::ItemPostFrame(CWeaponCSBaseGun *this)
{
  CCSPlayer *PlayerOwner; // ebx
  CBaseEdict *v3; // ecx
  edict_t *m_pPev; // ecx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    if ( gpGlobals->curtime >= this->m_flNextPrimaryAttack.m_Value && PlayerOwner->m_bResumeZoom.m_Value )
    {
      if ( PlayerOwner->m_bResumeZoom.m_Value )
      {
        if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
        }
        else
        {
          v3 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
          if ( v3 != nullptr )
            CBaseEdict::StateChanged(this: v3, offset: 0x1308u);
        }
        PlayerOwner->m_bResumeZoom.m_Value = false;
      }
      if ( (this->m_iClip1.m_Value != 0 || (this->GetWeaponFlags(this) & 2) != 0)
        && (this->GetCSWeaponID(this) == WEAPON_SSG08 || this->GetCSWeaponID(this) == WEAPON_AWP) )
      {
        if ( this->m_weaponMode.m_Value != Secondary_Mode )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x57Cu);
          }
          this->m_weaponMode.m_Value = Secondary_Mode;
        }
        CBasePlayer::SetFOV(
          this: PlayerOwner,
          pRequester: PlayerOwner,
          FOV: PlayerOwner->m_iLastZoom.m_Value,
          zoomRate: 0.050000001,
          iZoomStart: 0);
      }
    }
    CWeaponCSBase::ItemPostFrame(this, a2: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EA940
// Name: public: virtual bool CWeaponCSBaseGun::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCSBaseGun::Reload(CWeaponCSBaseGun *this)
{
  CCSPlayer *PlayerOwner; // edi
  int v4; // eax
  CWeaponCSBaseGun_vtbl *v5; // ebx
  int v6; // eax
  int v7; // eax
  int FOV; // esi
  int DefaultFOV; // eax
  CBaseEdict *v10; // ecx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner == nullptr )
    return 0;
  v4 = this->GetPrimaryAmmoType(this);
  if ( CBaseCombatCharacter::GetAmmoCount(this: PlayerOwner, iAmmoIndex: v4) <= 0 )
    return 0;
  v5 = this->__vftable;
  v6 = ((int (__thiscall *)(CWeaponCSBaseGun *, int))this->GetMaxClip2)(a1: this, a2: 192);
  v7 = ((int (__thiscall *)(CWeaponCSBaseGun *, int))this->GetMaxClip1)(a1: this, a2: v6);
  if ( ((unsigned __int8 (__thiscall *)(CWeaponCSBaseGun *, int))v5->DefaultReload)(a1: this, a2: v7) == 0 )
    return 0;
  PlayerOwner->SetAnimation(this: PlayerOwner, a2: PLAYER_RELOAD);
  FOV = CBasePlayer::GetFOV(this: PlayerOwner);
  if ( FOV != CBasePlayer::GetDefaultFOV(this: PlayerOwner) )
  {
    DefaultFOV = CBasePlayer::GetDefaultFOV(this: PlayerOwner);
    CBasePlayer::SetFOV(this: PlayerOwner, pRequester: PlayerOwner, FOV: DefaultFOV, zoomRate: 0.0, iZoomStart: 0);
  }
  if ( PlayerOwner->m_iShotsFired.m_Value != 0 )
  {
    if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
      PlayerOwner->m_iShotsFired.m_Value = 0;
      return 1;
    }
    v10 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
    if ( v10 != nullptr )
      CBaseEdict::StateChanged(this: v10, offset: 0x1788u);
    PlayerOwner->m_iShotsFired.m_Value = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EAA30
// Name: public: bool CWeaponCSBaseGun::CSBaseGunFire(float,enum CSWeaponMode)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CWeaponCSBaseGun::CSBaseGunFire@<al>(
        CWeaponCSBaseGun *this@<ecx>,
        int a2@<ebx>,
        float flCycleTime,
        CSWeaponMode weaponMode)
{
  CCSPlayer *PlayerOwner; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  bool v8; // zf
  int v9; // ebx
  CBaseEdict *v10; // ecx
  float v11; // xmm0_4
  edict_t *m_pPev; // ecx
  int v13; // edx
  CBaseEdict *v14; // ecx
  int v15; // edx
  edict_t *v16; // ecx
  char v17; // bl
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // eax
  CCSPlayer_vtbl *v19; // edx
  float z; // xmm1_4
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // eax
  float *v22; // eax
  float v23; // xmm0_4
  edict_t *v24; // eax
  const Vector *v25; // eax
  const CCSWeaponInfo *v26; // edx
  float m_Value; // xmm1_4
  float v28; // xmm0_4
  edict_t *v29; // ecx
  CSWeaponID v30; // [esp+Ch] [ebp-4Ch]
  float fSpread; // [esp+18h] [ebp-40h]
  float fCycleTime; // [esp+1Ch] [ebp-3Ch]
  QAngle vAngles; // [esp+2Ch] [ebp-2Ch] BYREF
  CSWeaponID iWeaponID[3]; // [esp+38h] [ebp-20h] BYREF
  float v35; // [esp+44h] [ebp-14h]
  float v36; // [esp+48h] [ebp-10h]
  float v37; // [esp+4Ch] [ebp-Ch]
  float flCurAttack; // [esp+50h] [ebp-8h]
  const CCSWeaponInfo *weaponInfo; // [esp+54h] [ebp-4h]
  int savedregs; // [esp+58h] [ebp+0h] BYREF
  int flCycleTimea; // [esp+60h] [ebp+8h]
  int flCycleTimeb; // [esp+60h] [ebp+8h]
  float flCycleTimed; // [esp+60h] [ebp+8h]
  signed int flCycleTimec; // [esp+60h] [ebp+8h]

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner == nullptr )
    return 0;
  CSWpnData = CWeaponCSBase::GetCSWpnData(this);
  v8 = this->m_iClip1.m_Value == 0;
  weaponInfo = CSWpnData;
  if ( v8 )
  {
    if ( this->m_bFireOnEmpty )
    {
      CWeaponCSBase::PlayEmptySound(this);
      v9 = PlayerOwner->m_iShotsFired.m_Value + 1;
      if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: v10, offset: 0x1788u);
      }
      PlayerOwner->m_iShotsFired.m_Value = v9;
      v11 = gpGlobals->curtime + 0.2;
      if ( this->m_flNextPrimaryAttack.m_Value != v11 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flNextPrimaryAttack.m_Value = v11;
          return 0;
        }
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
        this->m_flNextPrimaryAttack.m_Value = v11;
      }
    }
    return 0;
  }
  else
  {
    flCurAttack = CWeaponCSBase::CalculateNextAttackTime(this, fCycleTime: flCycleTime);
    ((void (__thiscall *)(CWeaponCSBaseGun *, int, int))this->SendWeaponAnim)(a1: this, a2: 190, a3: a2);
    v13 = PlayerOwner->m_iShotsFired.m_Value + 1;
    flCycleTimea = v13;
    if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
      if ( v14 != nullptr )
      {
        CBaseEdict::StateChanged(this: v14, offset: 0x1788u);
        v13 = flCycleTimea;
      }
    }
    PlayerOwner->m_iShotsFired.m_Value = v13;
    v15 = this->m_iClip1.m_Value - 1;
    flCycleTimeb = v15;
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
        v15 = flCycleTimeb;
      }
    }
    this->m_iClip1.m_Value = v15;
    PlayerOwner->SetAnimation(this: PlayerOwner, a2: PLAYER_ATTACK1);
    v17 = CBaseEntity::m_nPredictionRandomSeed;
    flCycleTimed = weapon_recoil_extra.m_pParent->m_Value.m_fValue + 1.0;
    PunchAngle = CBasePlayer::GetPunchAngle(this: PlayerOwner);
    v19 = PlayerOwner->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v35 = PunchAngle->m_Value.x * flCycleTimed;
    v36 = PunchAngle->m_Value.y * flCycleTimed;
    z = PunchAngle->m_Value.z;
    EyeAngles = v19->EyeAngles;
    v37 = z * flCycleTimed;
    v22 = (float *)EyeAngles(this: PlayerOwner);
    *(float *)iWeaponID = *v22 + v35;
    *(float *)&iWeaponID[1] = v22[1] + v36;
    v23 = v22[2];
    v24 = PlayerOwner->m_Network.m_pPev;
    *(float *)&iWeaponID[2] = v23 + (float)(z * flCycleTimed);
    if ( v24 != nullptr )
      flCycleTimec = v24 - gpGlobals->pEdicts;
    else
      flCycleTimec = 0;
    fCycleTime = ((double (__thiscall *)(CWeaponCSBaseGun *, _DWORD))this->GetSpread)(
                   a1: this,
                   a2: LODWORD(flCurAttack));
    fSpread = ((double (__thiscall *)(CWeaponCSBaseGun *, _DWORD))this->GetInaccuracy)(
                a1: this,
                a2: LODWORD(fCycleTime));
    v30 = this->GetCSWeaponID(this);
    v25 = (const Vector *)((int (__thiscall *)(CCSPlayer *))PlayerOwner->Weapon_ShootPosition)(a1: PlayerOwner);
    FX_FireBullets(
      a1: COERCE_FLOAT(&savedregs),
      iPlayerIndex: flCycleTimec,
      vOrigin: v25,
      &vAngles,
      (CSWeaponID)iWeaponID,
      iMode: v30,
      iSeed: weaponMode,
      fInaccuracy: COERCE_FLOAT(v17),
      fSpread);
    this->DoFireEffects(this);
    ((void (__thiscall *)(CWeaponCSBaseGun *, _DWORD))this->SetWeaponIdleTime)(
      a1: this,
      a2: weaponInfo->m_flTimeToIdleAfterFire + gpGlobals->curtime);
    v26 = weaponInfo;
    m_Value = this->m_fAccuracyPenalty.m_Value;
    v28 = weaponInfo->m_fInaccuracyImpulseFire[weaponMode] + m_Value;
    if ( m_Value != v28 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v29 = this->m_Network.m_pPev;
        if ( v29 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v29->CBaseEdict, offset: 0x580u);
          v26 = weaponInfo;
        }
      }
      this->m_fAccuracyPenalty.m_Value = v28;
    }
    if ( weapon_recoil_legacy.m_pParent == nullptr || weapon_recoil_legacy.m_pParent->m_Value.m_nValue == 0 )
      CCSPlayer::KickBack(
        this: PlayerOwner,
        fAngle: v26->m_fRecoilAngle[weaponMode],
        fAngleVariance: v26->m_fRecoilAngleVariance[weaponMode],
        fMagnitude: v26->m_fRecoilMagnitude[weaponMode],
        fMagnitudeVariance: v26->m_fRecoilMagnitudeVariance[weaponMode]);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EADD0
// Name: public: CWeaponCSBaseGun::CWeaponCSBaseGun(void)
// Source: json
//------------------------------------------------------------------------------
CWeaponCSBaseGun *__thiscall CWeaponCSBaseGun::CWeaponCSBaseGun(CWeaponCSBaseGun *this)
{
  CWeaponCSBase::CWeaponCSBase(this);
  this->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponCSBaseGun::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10412290
// Name: DT_WeaponCSBaseGun::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCSBaseGun::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponCSBaseGun::g_SendTable);
  return atexit(func: DT_WeaponCSBaseGun::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104122B0
// Name: DT_WeaponCSBaseGun::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCSBaseGun::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponCSBaseGun::ignored>();
  DT_WeaponCSBaseGun::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420910
// Name: DT_WeaponCSBaseGun::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponCSBaseGun::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponCSBaseGun::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420920
// Name: _ServerClassInit_DT_WeaponCSBaseGun::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponCSBaseGun::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_273;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
