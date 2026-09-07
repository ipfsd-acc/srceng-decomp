// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_sg556.cpp
// Functions: 18
// ============================================================

#include "game\shared\cstrike15\weapon_sg556.h"

//------------------------------------------------------------------------------
// Address: 0x10229690
// Name: public: virtual bool C_WeaponSG556::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponSG556::Deploy(C_WeaponAug *this)
{
  if ( this->m_weaponMode.m_Value != Primary_Mode )
    this->m_weaponMode.m_Value = Primary_Mode;
  return C_WeaponCSBase::Deploy(this);
}

//------------------------------------------------------------------------------
// Address: 0x10234580
// Name: public: virtual class ClientClass __near * C_WeaponSG556::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponSG556::GetClientClass(C_WeaponSG556 *this)
{
  return &__g_C_WeaponSG556ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10234600
// Name: public: virtual struct datamap_t __near * C_WeaponSG556::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponSG556::GetPredDescMap(C_WeaponSG556 *this)
{
  return &C_WeaponSG556::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10234610
// Name: public: virtual void weapon_sg556Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_sg556Precache::CResourcePrecacher::Cache(
        weapon_sg556Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_sg556",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10234640
// Name: public: virtual float C_WeaponSG556::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_WeaponSG556::GetMaxSpeed(C_WeaponSG556 *this)
{
  int v2; // eax
  int v3; // esi
  float v5; // [esp+8h] [ebp-8h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 == 0 )
    return C_WeaponCSBase::GetMaxSpeed(this);
  v5 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v2 + 1148))(a1: v2);
  if ( v5 == (double)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 1152))(a1: v3) )
    return C_WeaponCSBase::GetMaxSpeed(this);
  else
    return 200.0;
}

//------------------------------------------------------------------------------
// Address: 0x102346A0
// Name: public: virtual void C_WeaponSG556::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponSG556::PrimaryAttack(C_WeaponSG556 *this)
{
  int v2; // eax
  int v3; // esi
  float flCycleTime; // xmm0_4
  C_BaseEntity *v5; // eax
  C_CSPlayer *v6; // esi
  int m_fFlags; // eax
  float v8; // [esp+40h] [ebp-18h]
  bool v9; // [esp+4Bh] [ebp-Dh]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != 0 )
  {
    v8 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v2 + 1148))(a1: v2);
    v9 = (double)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 1152))(a1: v3) > v8;
    flCycleTime = C_WeaponCSBase::GetCSWpnData(this)->m_flCycleTime;
    if ( v9 )
      flCycleTime = 0.13500001;
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime, weaponMode: this->m_weaponMode.m_Value) )
    {
      C_WeaponCSBase::GetPlayerOwner(this);
      v6 = (C_CSPlayer *)v5;
      if ( v5 != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        C_BaseEntity::CalcAbsoluteVelocity(this: v5);
        if ( fsqrt(
               (float)(v6->m_vecAbsVelocity.x * v6->m_vecAbsVelocity.x)
             + (float)(v6->m_vecAbsVelocity.y * v6->m_vecAbsVelocity.y)) <= 5.0 )
        {
          m_fFlags = v6->m_fFlags;
          if ( (m_fFlags & 1) != 0 )
          {
            if ( (m_fFlags & 2) != 0 )
              C_CSPlayer::KickBack(
                this: v6,
                up_base: 0.60000002,
                lateral_base: 0.34999999,
                up_modifier: 0.2,
                lateral_modifier: 0.0125,
                up_max: 3.7,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)0xA);
            else
              C_CSPlayer::KickBack(
                this: v6,
                up_base: 0.625,
                lateral_base: 0.375,
                up_modifier: 0.25,
                lateral_modifier: 0.0125,
                up_max: 4.0,
                lateral_max: 2.25,
                direction_change: (IUniformRandomStream *)9);
          }
          else
          {
            C_CSPlayer::KickBack(
              this: v6,
              up_base: 1.25,
              lateral_base: 0.44999999,
              up_modifier: 0.22,
              lateral_modifier: 0.18000001,
              up_max: 6.0,
              lateral_max: 4.0,
              direction_change: (IUniformRandomStream *)5);
          }
        }
        else
        {
          C_CSPlayer::KickBack(
            this: v6,
            up_base: 1.0,
            lateral_base: 0.44999999,
            up_modifier: 0.28,
            lateral_modifier: 0.039999999,
            up_max: 4.25,
            lateral_max: 2.5,
            direction_change: (IUniformRandomStream *)7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234920
// Name: public: virtual void C_WeaponSG556::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponSG556::SecondaryAttack(C_WeaponSG556 *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // esi
  int v4; // eax
  float v5; // xmm0_4
  float v6; // [esp+10h] [ebp-8h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v6 = v2->GetFOV(this: v2);
    if ( v6 == (double)v3->GetDefaultFOV(this: v3) )
    {
      C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 55, zoomRate: 0.2, iZoomStart: 0);
    }
    else
    {
      if ( ((double (__thiscall *)(C_BasePlayer *))v3->GetFOV)(a1: v3) != 55.0 )
      {
        v4 = v3->GetDefaultFOV(this: v3);
        C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: v4, zoomRate: 0.15000001, iZoomStart: 0);
        if ( this->m_weaponMode.m_Value != Primary_Mode )
          this->m_weaponMode.m_Value = Primary_Mode;
        goto LABEL_10;
      }
      C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 0, zoomRate: 0.15000001, iZoomStart: 0);
    }
    if ( this->m_weaponMode.m_Value != Secondary_Mode )
      this->m_weaponMode.m_Value = Secondary_Mode;
LABEL_10:
    v5 = *(float *)(gpGlobals.m_Index + 12) + 0.30000001;
    if ( this->m_flNextSecondaryAttack.m_Value != v5 )
      this->m_flNextSecondaryAttack.m_Value = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234A30
// Name: public: virtual bool C_WeaponSG556::Reload(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponSG556::Reload(C_WeaponAug *this)
{
  if ( this->m_weaponMode.m_Value != Primary_Mode )
    this->m_weaponMode.m_Value = Primary_Mode;
  return C_WeaponCSBaseGun::Reload(this);
}

//------------------------------------------------------------------------------
// Address: 0x10234A50
// Name: public: virtual enum CSWeaponID C_WeaponSG556::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponSG556::GetCSWeaponID(C_WeaponSG556 *this)
{
  return 29;
}

//------------------------------------------------------------------------------
// Address: 0x10234AD0
// Name: CC_WeaponSG556Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponSG556Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponSG556::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponSG556::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponSG556::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponSG556::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponSG556::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429880
// Name: DT_WeaponSG556::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSG556::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponSG556::g_RecvTable);
  return atexit(func: DT_WeaponSG556::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104298A0
// Name: DT_WeaponSG556::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSG556::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponSG556::ignored>();
  DT_WeaponSG556::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104298B0
// Name: C_WeaponSG556_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponSG556_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponSG556::m_PredMap.dataNumFields = 1;
  C_WeaponSG556::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C58C;
}

//------------------------------------------------------------------------------
// Address: 0x10429900
// Name: weapon_sg556Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_sg556Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_sg556Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_sg556Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104361C0
// Name: DT_WeaponSG556::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponSG556::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponSG556::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10234A60
// Name: _C_WeaponSG556_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponSG556_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponSG556::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponSG556::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponSG556::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponSG556::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponSG556::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104298D0
// Name: _dynamic_initializer_for__g_Cweapon_sg556Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_sg556Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_sg556",
             a3: "C_WeaponSG556",
             a4: 3504,
             a5: CC_WeaponSG556Factory);
  __g_C_WeaponSG556ClientClass.m_pMapClassname = "weapon_sg556";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429920
// Name: _dynamic_initializer_for____g_C_SmokeGrenadeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SmokeGrenadeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SmokeGrenadeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SmokeGrenadeClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F2340
// Name: public: virtual class ServerClass __near * CWeaponSG556::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponSG556::GetServerClass(CWeaponSG556 *this)
{
  return &g_CWeaponSG556_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F2350
// Name: public: virtual void weapon_sg556Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_sg556Precache::CResourcePrecacher::Cache(
        weapon_sg556Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_sg556",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F2380
// Name: public: virtual float CWeaponSG556::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWeaponSG556::GetMaxSpeed(CWeaponSG556 *this)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v3; // esi
  int FOV; // ebx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v3 = PlayerOwner;
  if ( PlayerOwner == nullptr )
    return CWeaponCSBase::GetMaxSpeed(this);
  FOV = CBasePlayer::GetFOV(this: PlayerOwner);
  if ( FOV == CBasePlayer::GetDefaultFOV(this: v3) )
    return CWeaponCSBase::GetMaxSpeed(this);
  else
    return 200.0;
}

//------------------------------------------------------------------------------
// Address: 0x102F2440
// Name: public: virtual void CWeaponSG556::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponSG556::PrimaryAttack(CWeaponSG556 *this@<ecx>, int a2@<ebp>)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v4; // edi
  float flCycleTime; // xmm0_4
  CCSPlayer *v6; // esi
  int m_Value; // eax
  int FOV; // [esp+44h] [ebp-14h]
  bool v9; // [esp+4Bh] [ebp-Dh]
  _DWORD v10[2]; // [esp+4Ch] [ebp-Ch] BYREF
  int v11; // [esp+54h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+58h] [ebp+0h]

  v10[0] = a2;
  v10[1] = retaddr;
  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v4 = PlayerOwner;
  if ( PlayerOwner != nullptr )
  {
    FOV = CBasePlayer::GetFOV(this: PlayerOwner);
    v9 = FOV < CBasePlayer::GetDefaultFOV(this: v4);
    flCycleTime = CWeaponCSBase::GetCSWpnData(this)->m_flCycleTime;
    if ( v9 )
      flCycleTime = 0.13500001;
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2: (int)&v11, flCycleTime, weaponMode: this->m_weaponMode.m_Value) != 0 )
    {
      v6 = CWeaponCSBase::GetPlayerOwner(this);
      if ( v6 != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (v6->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: v6, a2: (int)v10);
        if ( fsqrt(
               (float)(v6->m_vecAbsVelocity.x * v6->m_vecAbsVelocity.x)
             + (float)(v6->m_vecAbsVelocity.y * v6->m_vecAbsVelocity.y)) <= 5.0 )
        {
          m_Value = v6->m_fFlags.m_Value;
          if ( (m_Value & 1) != 0 )
          {
            if ( (m_Value & 2) != 0 )
              CCSPlayer::KickBack(
                this: v6,
                up_base: 0.60000002,
                lateral_base: 0.34999999,
                up_modifier: 0.2,
                lateral_modifier: 0.0125,
                up_max: 3.7,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)0xA);
            else
              CCSPlayer::KickBack(
                this: v6,
                up_base: 0.625,
                lateral_base: 0.375,
                up_modifier: 0.25,
                lateral_modifier: 0.0125,
                up_max: 4.0,
                lateral_max: 2.25,
                direction_change: (IUniformRandomStream *)9);
          }
          else
          {
            CCSPlayer::KickBack(
              this: v6,
              up_base: 1.25,
              lateral_base: 0.44999999,
              up_modifier: 0.22,
              lateral_modifier: 0.18000001,
              up_max: 6.0,
              lateral_max: 4.0,
              direction_change: (IUniformRandomStream *)5);
          }
        }
        else
        {
          CCSPlayer::KickBack(
            this: v6,
            up_base: 1.0,
            lateral_base: 0.44999999,
            up_modifier: 0.28,
            lateral_modifier: 0.039999999,
            up_max: 4.25,
            lateral_max: 2.5,
            direction_change: (IUniformRandomStream *)7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F26B0
// Name: public: virtual void CWeaponSG556::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponSG556::SecondaryAttack(CWeaponSG556 *this)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v3; // esi
  edict_t *v4; // ecx
  int DefaultFOV; // eax
  edict_t *m_pPev; // ecx
  float v7; // xmm0_4
  edict_t *v8; // ecx
  int FOV; // [esp+14h] [ebp-4h]

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v3 = PlayerOwner;
  if ( PlayerOwner == nullptr )
    return;
  FOV = CBasePlayer::GetFOV(this: PlayerOwner);
  if ( FOV == CBasePlayer::GetDefaultFOV(this: v3) )
  {
    CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 55, zoomRate: 0.2, iZoomStart: 0);
  }
  else
  {
    if ( CBasePlayer::GetFOV(this: v3) != 55 )
    {
      DefaultFOV = CBasePlayer::GetDefaultFOV(this: v3);
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: DefaultFOV, zoomRate: 0.15000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Primary_Mode )
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
        this->m_weaponMode.m_Value = Primary_Mode;
      }
      goto LABEL_18;
    }
    CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 0, zoomRate: 0.15000001, iZoomStart: 0);
  }
  if ( this->m_weaponMode.m_Value != Secondary_Mode )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_weaponMode.m_Value = Secondary_Mode;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x57Cu);
      this->m_weaponMode.m_Value = Secondary_Mode;
    }
  }
LABEL_18:
  v7 = gpGlobals->curtime + 0.30000001;
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

//------------------------------------------------------------------------------
// Address: 0x102F2870
// Name: public: virtual enum CSWeaponID CWeaponSG556::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponSG556::GetCSWeaponID(CWeaponSG556 *this)
{
  return 29;
}

//------------------------------------------------------------------------------
// Address: 0x104131D0
// Name: DT_WeaponSG556::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSG556::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponSG556::g_SendTable);
  return atexit(func: DT_WeaponSG556::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104131F0
// Name: DT_WeaponSG556::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSG556::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponSG556::ignored>();
  DT_WeaponSG556::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413220
// Name: weapon_sg556Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_sg556Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_sg556Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_sg556Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420E80
// Name: DT_WeaponSG556::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponSG556::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponSG556::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10413240
// Name: _dynamic_initializer_for__g_CSmokeGrenade_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSmokeGrenade_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSmokeGrenade_ClassReg,
           pNetworkName: "CSmokeGrenade",
           pTable: &DT_SmokeGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420E90
// Name: _ServerClassInit_DT_WeaponSG556::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponSG556::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_299;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
