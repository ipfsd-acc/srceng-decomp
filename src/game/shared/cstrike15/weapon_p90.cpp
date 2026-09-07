// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_p90.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_p90.h"

//------------------------------------------------------------------------------
// Address: 0x10233700
// Name: public: virtual class ClientClass __near * C_WeaponP90::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponP90::GetClientClass(C_WeaponP90 *this)
{
  return &__g_C_WeaponP90ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10233780
// Name: public: virtual struct datamap_t __near * C_WeaponP90::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponP90::GetPredDescMap(C_WeaponP90 *this)
{
  return &C_WeaponP90::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10233790
// Name: public: virtual void weapon_p90Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_p90Precache::CResourcePrecacher::Cache(
        weapon_p90Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_p90",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102337C0
// Name: public: virtual void C_WeaponP90::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponP90::PrimaryAttack(C_WeaponP90 *this)
{
  int v2; // eax
  int v3; // esi
  const CCSWeaponInfo *CSWpnData; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != 0 )
  {
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode) != 0
      && weapon_recoil_legacy.m_pParent != nullptr
      && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (*(_BYTE *)(v3 + 248) & 1) != 0 )
      {
        C_BaseEntity::CalcAbsoluteVelocity(this: (C_BaseEntity *)v3);
        if ( fsqrt(
               (float)(*(float *)(v3 + 144) * *(float *)(v3 + 144))
             + (float)(*(float *)(v3 + 148) * *(float *)(v3 + 148))) <= 5.0 )
        {
          if ( (*(_BYTE *)(v3 + 248) & 2) != 0 )
            C_CSPlayer::KickBack(
              this: (C_CSPlayer *)v3,
              up_base: 0.27500001,
              lateral_base: 0.2,
              up_modifier: 0.125,
              lateral_modifier: 0.02,
              up_max: 3.0,
              lateral_max: 1.0,
              direction_change: (IUniformRandomStream *)9);
          else
            C_CSPlayer::KickBack(
              this: (C_CSPlayer *)v3,
              up_base: 0.30000001,
              lateral_base: 0.22499999,
              up_modifier: 0.125,
              lateral_modifier: 0.02,
              up_max: 3.25,
              lateral_max: 1.25,
              direction_change: (IUniformRandomStream *)8);
        }
        else
        {
          C_CSPlayer::KickBack(
            this: (C_CSPlayer *)v3,
            up_base: 0.44999999,
            lateral_base: 0.30000001,
            up_modifier: 0.2,
            lateral_modifier: 0.0275,
            up_max: 4.0,
            lateral_max: 2.25,
            direction_change: (IUniformRandomStream *)7);
        }
      }
      else
      {
        C_CSPlayer::KickBack(
          this: (C_CSPlayer *)v3,
          up_base: 0.89999998,
          lateral_base: 0.44999999,
          up_modifier: 0.34999999,
          lateral_modifier: 0.039999999,
          up_max: 5.25,
          lateral_max: 3.5,
          direction_change: (IUniformRandomStream *)4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10233A00
// Name: public: virtual enum CSWeaponID C_WeaponP90::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponP90::GetCSWeaponID(C_WeaponP90 *this)
{
  return 14;
}

//------------------------------------------------------------------------------
// Address: 0x10233A80
// Name: CC_WeaponP90Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponP90Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponP90::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponP90::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponP90::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponP90::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponP90::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429640
// Name: DT_WeaponP90::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponP90::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponP90::g_RecvTable);
  return atexit(func: DT_WeaponP90::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429660
// Name: DT_WeaponP90::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponP90::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponP90::ignored>();
  DT_WeaponP90::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429670
// Name: C_WeaponP90_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponP90_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponP90::m_PredMap.dataNumFields = 1;
  C_WeaponP90::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C304;
}

//------------------------------------------------------------------------------
// Address: 0x104296C0
// Name: weapon_p90Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_p90Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_p90Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_p90Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436190
// Name: DT_WeaponP90::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponP90::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponP90::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10233A10
// Name: _C_WeaponP90_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponP90_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponP90::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponP90::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponP90::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponP90::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponP90::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429690
// Name: _dynamic_initializer_for__g_Cweapon_p90Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_p90Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_p90",
             a3: "C_WeaponP90",
             a4: 3504,
             a5: CC_WeaponP90Factory);
  __g_C_WeaponP90ClientClass.m_pMapClassname = "weapon_p90";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104296E0
// Name: _dynamic_initializer_for____g_C_WeaponSawedoffClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponSawedoffClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponSawedoffClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponSawedoffClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F1140
// Name: public: virtual class ServerClass __near * CWeaponP90::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponP90::GetServerClass(CWeaponP90 *this)
{
  return &g_CWeaponP90_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F1150
// Name: public: virtual void weapon_p90Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_p90Precache::CResourcePrecacher::Cache(
        weapon_p90Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_p90",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F1200
// Name: public: virtual void CWeaponP90::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponP90::PrimaryAttack(CWeaponP90 *this@<ecx>, int a2@<ebp>)
{
  CCSPlayer *PlayerOwner; // esi
  const CCSWeaponInfo *CSWpnData; // eax
  _DWORD v5[2]; // [esp+3Ch] [ebp-Ch] BYREF
  int v6; // [esp+44h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+48h] [ebp+0h]

  v5[0] = a2;
  v5[1] = retaddr;
  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(
           this,
           a2: (int)&v6,
           flCycleTime: CSWpnData->m_flCycleTime,
           weaponMode: Primary_Mode) != 0
      && weapon_recoil_legacy.m_pParent != nullptr
      && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (PlayerOwner->m_fFlags.m_Value & 1) != 0 )
      {
        if ( (PlayerOwner->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: PlayerOwner, a2: (int)v5);
        if ( fsqrt(
               (float)(PlayerOwner->m_vecAbsVelocity.x * PlayerOwner->m_vecAbsVelocity.x)
             + (float)(PlayerOwner->m_vecAbsVelocity.y * PlayerOwner->m_vecAbsVelocity.y)) <= 5.0 )
        {
          if ( (PlayerOwner->m_fFlags.m_Value & 2) != 0 )
            CCSPlayer::KickBack(
              this: PlayerOwner,
              up_base: 0.27500001,
              lateral_base: 0.2,
              up_modifier: 0.125,
              lateral_modifier: 0.02,
              up_max: 3.0,
              lateral_max: 1.0,
              direction_change: (IUniformRandomStream *)9);
          else
            CCSPlayer::KickBack(
              this: PlayerOwner,
              up_base: 0.30000001,
              lateral_base: 0.22499999,
              up_modifier: 0.125,
              lateral_modifier: 0.02,
              up_max: 3.25,
              lateral_max: 1.25,
              direction_change: (IUniformRandomStream *)8);
        }
        else
        {
          CCSPlayer::KickBack(
            this: PlayerOwner,
            up_base: 0.44999999,
            lateral_base: 0.30000001,
            up_modifier: 0.2,
            lateral_modifier: 0.0275,
            up_max: 4.0,
            lateral_max: 2.25,
            direction_change: (IUniformRandomStream *)7);
        }
      }
      else
      {
        CCSPlayer::KickBack(
          this: PlayerOwner,
          up_base: 0.89999998,
          lateral_base: 0.44999999,
          up_modifier: 0.34999999,
          lateral_modifier: 0.039999999,
          up_max: 5.25,
          lateral_max: 3.5,
          direction_change: (IUniformRandomStream *)4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F1440
// Name: public: virtual enum CSWeaponID CWeaponP90::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponP90::GetCSWeaponID(CWeaponP90 *this)
{
  return 14;
}

//------------------------------------------------------------------------------
// Address: 0x10413020
// Name: DT_WeaponP90::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponP90::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponP90::g_SendTable);
  return atexit(func: DT_WeaponP90::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413040
// Name: DT_WeaponP90::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponP90::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponP90::ignored>();
  DT_WeaponP90::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413070
// Name: weapon_p90Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_p90Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_p90Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_p90Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420DF0
// Name: DT_WeaponP90::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponP90::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponP90::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10413090
// Name: _dynamic_initializer_for__g_CWeaponSawedoff_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponSawedoff_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponSawedoff_ClassReg,
           pNetworkName: "CWeaponSawedoff",
           pTable: &DT_WeaponSawedoff::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420E00
// Name: _ServerClassInit_DT_WeaponP90::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponP90::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_296;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
