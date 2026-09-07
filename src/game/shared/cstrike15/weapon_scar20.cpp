// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_scar20.cpp
// Functions: 16
// ============================================================

#include "game\shared\cstrike15\weapon_scar20.h"

//------------------------------------------------------------------------------
// Address: 0x1022EE40
// Name: public: virtual float C_WeaponSCAR20::GetMaxSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_WeaponSCAR20::GetMaxSpeed(C_WeaponG3SG1 *this)
{
  int v2; // eax
  int v3; // esi
  float v5; // [esp+8h] [ebp-8h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != 0
    && (v5 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v2 + 1148))(a1: v2)) == (double)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 1152))(a1: v3) )
  {
    return C_WeaponCSBase::GetMaxSpeed(this);
  }
  else
  {
    return 150.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022EFA0
// Name: public: virtual void C_WeaponSCAR20::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponSCAR20::SecondaryAttack(C_WeaponG3SG1 *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // esi
  const CCSWeaponInfo *CSWpnData; // eax
  float m_Value; // xmm1_4
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm0_4
  float v9; // [esp+10h] [ebp-8h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v9 = v2->GetFOV(this: v2);
    if ( v9 == (double)v3->GetDefaultFOV(this: v3) )
    {
      C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 40, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
        this->m_weaponMode.m_Value = Secondary_Mode;
      CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
      m_Value = this->m_fAccuracyPenalty.m_Value;
      v6 = CSWpnData->m_fInaccuracyAltSwitch + m_Value;
      if ( m_Value != v6 )
        this->m_fAccuracyPenalty.m_Value = v6;
    }
    else if ( ((double (__thiscall *)(C_BasePlayer *))v3->GetFOV)(a1: v3) == 40.0 )
    {
      C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 15, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
        this->m_weaponMode.m_Value = Secondary_Mode;
    }
    else if ( ((double (__thiscall *)(C_BasePlayer *))v3->GetFOV)(a1: v3) == 15.0 )
    {
      v7 = v3->GetDefaultFOV(this: v3);
      C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: v7, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Primary_Mode )
        this->m_weaponMode.m_Value = Primary_Mode;
    }
    v8 = *(float *)(gpGlobals.m_Index + 12) + 0.30000001;
    if ( this->m_flNextSecondaryAttack.m_Value != v8 )
      this->m_flNextSecondaryAttack.m_Value = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102342F0
// Name: public: virtual class ClientClass __near * C_WeaponSCAR20::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponSCAR20::GetClientClass(C_WeaponSCAR20 *this)
{
  return &__g_C_WeaponSCAR20ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10234370
// Name: public: virtual struct datamap_t __near * C_WeaponSCAR20::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponSCAR20::GetPredDescMap(C_WeaponSCAR20 *this)
{
  return &C_WeaponSCAR20::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10234380
// Name: public: virtual void weapon_scar20Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_scar20Precache::CResourcePrecacher::Cache(
        weapon_scar20Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_scar20",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102343B0
// Name: public: virtual void C_WeaponSCAR20::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponSCAR20::PrimaryAttack(C_WeaponSCAR20 *this)
{
  int v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  C_BasePlayer *v4; // eax
  C_BasePlayer *v5; // esi
  CSWeaponMode m_Value; // [esp+8h] [ebp-14h]
  QAngle angle; // [esp+10h] [ebp-Ch] BYREF

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0 )
    {
      C_WeaponCSBase::GetPlayerOwner(this);
      v5 = v4;
      if ( v4 != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        angle = *v4->GetPunchAngle(this: v4);
        angle.x = angle.x
                - (SharedRandomFloat(sharedname: "SCAR20PunchAngleX", flMinVal: 0.75, flMaxVal: 1.75, additionalSeed: 0)
                 + 0.25 * angle.x);
        angle.y = SharedRandomFloat(sharedname: "SCAR20PunchAngleY", flMinVal: -0.75, flMaxVal: 0.75, additionalSeed: 0)
                + angle.y;
        C_BasePlayer::SetPunchAngle(this: v5, &angle);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234530
// Name: CC_WeaponSCAR20Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponSCAR20Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponSCAR20::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponSCAR20::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponSCAR20::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponSCAR20::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponSCAR20::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x104297C0
// Name: DT_WeaponSCAR20::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSCAR20::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponSCAR20::g_RecvTable);
  return atexit(func: DT_WeaponSCAR20::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104297E0
// Name: DT_WeaponSCAR20::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSCAR20::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponSCAR20::ignored>();
  DT_WeaponSCAR20::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104297F0
// Name: C_WeaponSCAR20_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponSCAR20_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponSCAR20::m_PredMap.dataNumFields = 1;
  C_WeaponSCAR20::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C4B4;
}

//------------------------------------------------------------------------------
// Address: 0x10429840
// Name: weapon_scar20Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_scar20Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_scar20Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_scar20Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104361B0
// Name: DT_WeaponSCAR20::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponSCAR20::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponSCAR20::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022F120
// Name: _C_WeaponG3SG1_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponG3SG1_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponG3SG1::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponG3SG1::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponG3SG1::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponG3SG1::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponG3SG1::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x102344C0
// Name: _C_WeaponSCAR20_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponSCAR20_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponSCAR20::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponSCAR20::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponSCAR20::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponSCAR20::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponSCAR20::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429810
// Name: _dynamic_initializer_for__g_Cweapon_scar20Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_scar20Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_scar20",
             a3: "C_WeaponSCAR20",
             a4: 3504,
             a5: CC_WeaponSCAR20Factory);
  __g_C_WeaponSCAR20ClientClass.m_pMapClassname = "weapon_scar20";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429860
// Name: _dynamic_initializer_for____g_C_WeaponSG556ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponSG556ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponSG556ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponSG556ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F1DF0
// Name: public: virtual class ServerClass __near * CWeaponSCAR20::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponSCAR20::GetServerClass(CWeaponSCAR20 *this)
{
  return &g_CWeaponSCAR20_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F1E00
// Name: public: virtual void weapon_scar20Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_scar20Precache::CResourcePrecacher::Cache(
        weapon_scar20Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_scar20",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F1E30
// Name: public: virtual float CWeaponSCAR20::GetMaxSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWeaponSCAR20::GetMaxSpeed(CWeaponG3SG1 *this)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v3; // esi
  int FOV; // ebx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v3 = PlayerOwner;
  if ( PlayerOwner != nullptr && (FOV = CBasePlayer::GetFOV(this: PlayerOwner)) == CBasePlayer::GetDefaultFOV(this: v3) )
    return CWeaponCSBase::GetMaxSpeed(this);
  else
    return 150.0;
}

//------------------------------------------------------------------------------
// Address: 0x102F1EF0
// Name: public: virtual void CWeaponSCAR20::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponSCAR20::PrimaryAttack(CWeaponSCAR20 *this@<ecx>, int a2@<ebx>)
{
  const CCSWeaponInfo *CSWpnData; // eax
  CCSPlayer *PlayerOwner; // esi
  CSWeaponMode m_Value; // [esp+8h] [ebp-14h]
  QAngle angle; // [esp+10h] [ebp-Ch] BYREF

  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0 )
    {
      PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
      if ( PlayerOwner != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        angle = CBasePlayer::GetPunchAngle(this: PlayerOwner)->m_Value;
        angle.x = angle.x
                - (SharedRandomFloat(sharedname: "SCAR20PunchAngleX", flMinVal: 0.75, flMaxVal: 1.75, additionalSeed: 0)
                 + 0.25 * angle.x);
        angle.y = SharedRandomFloat(sharedname: "SCAR20PunchAngleY", flMinVal: -0.75, flMaxVal: 0.75, additionalSeed: 0)
                + angle.y;
        CBasePlayer::SetPunchAngle(this: PlayerOwner, punchAngle: &angle);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2000
// Name: public: virtual void CWeaponSCAR20::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponSCAR20::SecondaryAttack(CWeaponSCAR20 *this)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v3; // esi
  int FOV; // edi
  edict_t *m_pPev; // ecx
  const CCSWeaponInfo *CSWpnData; // eax
  float m_Value; // xmm1_4
  float v8; // xmm0_4
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  int DefaultFOV; // eax
  edict_t *v12; // ecx
  IGameEvent *v13; // edi
  int v14; // eax
  float v15; // xmm0_4
  edict_t *v16; // ecx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v3 = PlayerOwner;
  if ( PlayerOwner != nullptr )
  {
    FOV = CBasePlayer::GetFOV(this: PlayerOwner);
    if ( FOV == CBasePlayer::GetDefaultFOV(this: v3) )
    {
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 40, zoomRate: 0.050000001, iZoomStart: 0);
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
      CSWpnData = CWeaponCSBase::GetCSWpnData(this);
      m_Value = this->m_fAccuracyPenalty.m_Value;
      v8 = CSWpnData->m_fInaccuracyAltSwitch + m_Value;
      if ( m_Value != v8 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_fAccuracyPenalty.m_Value = v8;
        }
        else
        {
          v9 = this->m_Network.m_pPev;
          if ( v9 != nullptr )
            CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x580u);
          this->m_fAccuracyPenalty.m_Value = v8;
        }
      }
    }
    else if ( CBasePlayer::GetFOV(this: v3) == 40 )
    {
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 15, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_weaponMode.m_Value = Secondary_Mode;
        }
        else
        {
          v10 = this->m_Network.m_pPev;
          if ( v10 != nullptr )
            CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x57Cu);
          this->m_weaponMode.m_Value = Secondary_Mode;
        }
      }
    }
    else if ( CBasePlayer::GetFOV(this: v3) == 15 )
    {
      DefaultFOV = CBasePlayer::GetDefaultFOV(this: v3);
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: DefaultFOV, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Primary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = this->m_Network.m_pPev;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x57Cu);
        }
        this->m_weaponMode.m_Value = Primary_Mode;
      }
    }
    CBaseEntity::EmitSound(this: v3, soundname: "Default.Zoom", soundtime: 0.0, duration: nullptr);
    v13 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "weapon_zoom", a3: 0, a4: 0);
    if ( v13 != nullptr )
    {
      v14 = engine->GetPlayerUserId(this: engine, a2: v3->m_Network.m_pPev);
      v13->SetInt(this: v13, a2: "userid", a3: v14);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v13, a3: false);
    }
    v15 = gpGlobals->curtime + 0.30000001;
    if ( this->m_flNextSecondaryAttack.m_Value != v15 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flNextSecondaryAttack.m_Value = v15;
      }
      else
      {
        v16 = this->m_Network.m_pPev;
        if ( v16 != nullptr )
          CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x498u);
        this->m_flNextSecondaryAttack.m_Value = v15;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F22F0
// Name: public: virtual enum CSWeaponID CWeaponSCAR20::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponSCAR20::GetCSWeaponID(CWeaponSCAR20 *this)
{
  return 28;
}

//------------------------------------------------------------------------------
// Address: 0x102F2810
// Name: public: virtual bool CWeaponSCAR20::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponSCAR20::Reload(CWeaponAug *this)
{
  edict_t *m_pPev; // ecx

  if ( this->m_weaponMode.m_Value != Primary_Mode )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_weaponMode.m_Value = Primary_Mode;
      return CWeaponCSBaseGun::Reload(this);
    }
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x57Cu);
    this->m_weaponMode.m_Value = Primary_Mode;
  }
  return CWeaponCSBaseGun::Reload(this);
}

//------------------------------------------------------------------------------
// Address: 0x10413140
// Name: DT_WeaponSCAR20::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSCAR20::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponSCAR20::g_SendTable);
  return atexit(func: DT_WeaponSCAR20::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413160
// Name: DT_WeaponSCAR20::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponSCAR20::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponSCAR20::ignored>();
  DT_WeaponSCAR20::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413190
// Name: weapon_scar20Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_scar20Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_scar20Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_scar20Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420E50
// Name: DT_WeaponSCAR20::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponSCAR20::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponSCAR20::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104131B0
// Name: _dynamic_initializer_for__g_CWeaponSG556_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponSG556_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponSG556_ClassReg,
           pNetworkName: "CWeaponSG556",
           pTable: &DT_WeaponSG556::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420E60
// Name: _ServerClassInit_DT_WeaponSCAR20::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponSCAR20::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_298;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
