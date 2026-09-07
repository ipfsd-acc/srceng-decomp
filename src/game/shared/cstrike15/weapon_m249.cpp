// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_m249.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_m249.h"

//------------------------------------------------------------------------------
// Address: 0x10230ED0
// Name: public: virtual class ClientClass __near * C_WeaponM249::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponM249::GetClientClass(C_WeaponM249 *this)
{
  return &__g_C_WeaponM249ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10230F50
// Name: public: virtual struct datamap_t __near * C_WeaponM249::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponM249::GetPredDescMap(C_WeaponM249 *this)
{
  return &C_WeaponM249::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10230F60
// Name: public: virtual void weapon_m249Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_m249Precache::CResourcePrecacher::Cache(
        weapon_m249Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_m249",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10230F90
// Name: public: virtual void C_WeaponM249::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponM249::PrimaryAttack(C_WeaponM249 *this)
{
  int v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  int v4; // eax
  int v5; // esi

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode) != 0 )
    {
      C_WeaponCSBase::GetPlayerOwner(this);
      v5 = v4;
      if ( v4 != 0 && weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (*(_BYTE *)(v4 + 248) & 1) != 0 )
        {
          C_BaseEntity::CalcAbsoluteVelocity(this: (C_BaseEntity *)v4);
          if ( fsqrt(
                 (float)(*(float *)(v5 + 144) * *(float *)(v5 + 144))
               + (float)(*(float *)(v5 + 148) * *(float *)(v5 + 148))) <= 5.0 )
          {
            if ( (*(_BYTE *)(v5 + 248) & 2) != 0 )
              C_CSPlayer::KickBack(
                this: (C_CSPlayer *)v5,
                up_base: 0.75,
                lateral_base: 0.32499999,
                up_modifier: 0.25,
                lateral_modifier: 0.025,
                up_max: 3.5,
                lateral_max: 2.5,
                direction_change: (IUniformRandomStream *)9);
            else
              C_CSPlayer::KickBack(
                this: (C_CSPlayer *)v5,
                up_base: 0.80000001,
                lateral_base: 0.34999999,
                up_modifier: 0.30000001,
                lateral_modifier: 0.029999999,
                up_max: 3.75,
                lateral_max: 3.0,
                direction_change: (IUniformRandomStream *)9);
          }
          else
          {
            C_CSPlayer::KickBack(
              this: (C_CSPlayer *)v5,
              up_base: 1.1,
              lateral_base: 0.5,
              up_modifier: 0.30000001,
              lateral_modifier: 0.059999999,
              up_max: 4.0,
              lateral_max: 3.0,
              direction_change: (IUniformRandomStream *)8);
          }
        }
        else
        {
          C_CSPlayer::KickBack(
            this: (C_CSPlayer *)v4,
            up_base: 1.8,
            lateral_base: 0.64999998,
            up_modifier: 0.44999999,
            lateral_modifier: 0.125,
            up_max: 5.0,
            lateral_max: 3.5,
            direction_change: (IUniformRandomStream *)8);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102311F0
// Name: public: virtual enum CSWeaponID C_WeaponM249::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponM249::GetCSWeaponID(C_WeaponM249 *this)
{
  return 11;
}

//------------------------------------------------------------------------------
// Address: 0x10231270
// Name: CC_WeaponM249Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponM249Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponM249::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponM249::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponM249::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponM249::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponM249::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10428EA0
// Name: DT_WeaponM249::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponM249::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponM249::g_RecvTable);
  return atexit(func: DT_WeaponM249::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428EC0
// Name: DT_WeaponM249::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponM249::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponM249::ignored>();
  DT_WeaponM249::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428ED0
// Name: C_WeaponM249_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponM249_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponM249::m_PredMap.dataNumFields = 1;
  C_WeaponM249::m_PredMap.dataDesc = (typedescription_t *)&unk_1066BA1C;
}

//------------------------------------------------------------------------------
// Address: 0x10428F20
// Name: weapon_m249Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_m249Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_m249Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_m249Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104360F0
// Name: DT_WeaponM249::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponM249::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponM249::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10231200
// Name: _C_WeaponM249_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponM249_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponM249::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponM249::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponM249::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponM249::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponM249::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10428EF0
// Name: _dynamic_initializer_for__g_Cweapon_m249Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_m249Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_m249",
             a3: "C_WeaponM249",
             a4: 3504,
             a5: CC_WeaponM249Factory);
  __g_C_WeaponM249ClientClass.m_pMapClassname = "weapon_m249";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428F40
// Name: _dynamic_initializer_for____g_C_WeaponM4A1ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponM4A1ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponM4A1ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponM4A1ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EEAE0
// Name: public: virtual class ServerClass __near * CWeaponM249::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponM249::GetServerClass(CWeaponM249 *this)
{
  return &g_CWeaponM249_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EEAF0
// Name: public: virtual void weapon_m249Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_m249Precache::CResourcePrecacher::Cache(
        weapon_m249Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_m249",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EEBA0
// Name: public: virtual void CWeaponM249::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponM249::PrimaryAttack(CWeaponM249 *this)
{
  const CCSWeaponInfo *CSWpnData; // eax
  CCSPlayer *PlayerOwner; // esi
  const Vector *AbsVelocity; // eax
  int v5; // [esp+44h] [ebp-4h] BYREF

  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(
           this,
           a2: (int)&v5,
           flCycleTime: CSWpnData->m_flCycleTime,
           weaponMode: Primary_Mode) != 0 )
    {
      PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
      if ( PlayerOwner != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (PlayerOwner->m_fFlags.m_Value & 1) != 0 )
        {
          AbsVelocity = CBaseEntity::GetAbsVelocity(this: PlayerOwner);
          if ( fsqrt((float)(AbsVelocity->x * AbsVelocity->x) + (float)(AbsVelocity->y * AbsVelocity->y)) <= 5.0 )
          {
            if ( (PlayerOwner->m_fFlags.m_Value & 2) != 0 )
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.75,
                lateral_base: 0.32499999,
                up_modifier: 0.25,
                lateral_modifier: 0.025,
                up_max: 3.5,
                lateral_max: 2.5,
                direction_change: (IUniformRandomStream *)9);
            else
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.80000001,
                lateral_base: 0.34999999,
                up_modifier: 0.30000001,
                lateral_modifier: 0.029999999,
                up_max: 3.75,
                lateral_max: 3.0,
                direction_change: (IUniformRandomStream *)9);
          }
          else
          {
            CCSPlayer::KickBack(
              this: PlayerOwner,
              up_base: 1.1,
              lateral_base: 0.5,
              up_modifier: 0.30000001,
              lateral_modifier: 0.059999999,
              up_max: 4.0,
              lateral_max: 3.0,
              direction_change: (IUniformRandomStream *)8);
          }
        }
        else
        {
          CCSPlayer::KickBack(
            this: PlayerOwner,
            up_base: 1.8,
            lateral_base: 0.64999998,
            up_modifier: 0.44999999,
            lateral_modifier: 0.125,
            up_max: 5.0,
            lateral_max: 3.5,
            direction_change: (IUniformRandomStream *)8);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EEE00
// Name: public: virtual enum CSWeaponID CWeaponM249::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponM249::GetCSWeaponID(CWeaponM249 *this)
{
  return 11;
}

//------------------------------------------------------------------------------
// Address: 0x10412A70
// Name: DT_WeaponM249::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponM249::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponM249::g_SendTable);
  return atexit(func: DT_WeaponM249::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412A90
// Name: DT_WeaponM249::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponM249::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponM249::ignored>();
  DT_WeaponM249::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412AC0
// Name: weapon_m249Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_m249Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_m249Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_m249Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420C00
// Name: DT_WeaponM249::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponM249::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponM249::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412AE0
// Name: _dynamic_initializer_for__g_CWeaponM4A1_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponM4A1_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponM4A1_ClassReg,
           pNetworkName: "CWeaponM4A1",
           pTable: &DT_WeaponM4A1::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420C10
// Name: _ServerClassInit_DT_WeaponM249::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponM249::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_286;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
