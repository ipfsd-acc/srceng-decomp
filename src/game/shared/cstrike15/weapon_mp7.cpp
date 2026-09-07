// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_mp7.cpp
// Functions: 12
// ============================================================

#include "game\shared\cstrike15\weapon_mp7.h"

//------------------------------------------------------------------------------
// Address: 0x10232690
// Name: public: virtual class ClientClass __near * C_WeaponMP7::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponMP7::GetClientClass(C_WeaponMP7 *this)
{
  return &__g_C_WeaponMP7ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10232710
// Name: public: virtual struct datamap_t __near * C_WeaponMP7::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponMP7::GetPredDescMap(C_WeaponMP7 *this)
{
  return &C_WeaponMP7::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10232720
// Name: public: virtual void weapon_mp7Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_mp7Precache::CResourcePrecacher::Cache(
        weapon_mp7Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_mp7",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10232750
// Name: public: virtual void C_WeaponMP7::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponMP7::PrimaryAttack(C_WeaponMP7 *this)
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
                up_base: 0.22499999,
                lateral_base: 0.15000001,
                up_modifier: 0.1,
                lateral_modifier: 0.015,
                up_max: 2.0,
                lateral_max: 1.0,
                direction_change: (IUniformRandomStream *)0xA);
            else
              C_CSPlayer::KickBack(
                this: (C_CSPlayer *)v5,
                up_base: 0.25,
                lateral_base: 0.175,
                up_modifier: 0.125,
                lateral_modifier: 0.02,
                up_max: 2.25,
                lateral_max: 1.25,
                direction_change: (IUniformRandomStream *)0xA);
          }
          else
          {
            C_CSPlayer::KickBack(
              this: (C_CSPlayer *)v5,
              up_base: 0.5,
              lateral_base: 0.27500001,
              up_modifier: 0.2,
              lateral_modifier: 0.029999999,
              up_max: 3.0,
              lateral_max: 2.0,
              direction_change: (IUniformRandomStream *)0xA);
          }
        }
        else
        {
          C_CSPlayer::KickBack(
            this: (C_CSPlayer *)v4,
            up_base: 0.89999998,
            lateral_base: 0.47499999,
            up_modifier: 0.34999999,
            lateral_modifier: 0.0425,
            up_max: 5.0,
            lateral_max: 3.0,
            direction_change: (IUniformRandomStream *)6);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10232A60
// Name: CC_WeaponMP7Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponMP7Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponMP7::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponMP7::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponMP7::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponMP7::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponMP7::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429280
// Name: DT_WeaponMP7::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMP7::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponMP7::g_RecvTable);
  return atexit(func: DT_WeaponMP7::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104292A0
// Name: DT_WeaponMP7::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMP7::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponMP7::ignored>();
  DT_WeaponMP7::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104292B0
// Name: C_WeaponMP7_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponMP7_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponMP7::m_PredMap.dataNumFields = 1;
  C_WeaponMP7::m_PredMap.dataDesc = (typedescription_t *)&unk_1066BECC;
}

//------------------------------------------------------------------------------
// Address: 0x10429300
// Name: weapon_mp7Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_mp7Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_mp7Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_mp7Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436140
// Name: DT_WeaponMP7::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponMP7::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponMP7::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104292D0
// Name: _dynamic_initializer_for__g_Cweapon_mp7Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_mp7Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_mp7",
             a3: "C_WeaponMP7",
             a4: 3504,
             a5: CC_WeaponMP7Factory);
  __g_C_WeaponMP7ClientClass.m_pMapClassname = "weapon_mp7";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429320
// Name: _dynamic_initializer_for____g_C_WeaponMP9ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponMP9ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponMP9ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponMP9ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F00E0
// Name: public: virtual class ServerClass __near * CWeaponMP7::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponMP7::GetServerClass(CWeaponMP7 *this)
{
  return &g_CWeaponMP7_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F00F0
// Name: public: virtual void weapon_mp7Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_mp7Precache::CResourcePrecacher::Cache(
        weapon_mp7Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_mp7",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F01A0
// Name: public: virtual void CWeaponMP7::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponMP7::PrimaryAttack(CWeaponMP7 *this)
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
                up_base: 0.22499999,
                lateral_base: 0.15000001,
                up_modifier: 0.1,
                lateral_modifier: 0.015,
                up_max: 2.0,
                lateral_max: 1.0,
                direction_change: (IUniformRandomStream *)0xA);
            else
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.25,
                lateral_base: 0.175,
                up_modifier: 0.125,
                lateral_modifier: 0.02,
                up_max: 2.25,
                lateral_max: 1.25,
                direction_change: (IUniformRandomStream *)0xA);
          }
          else
          {
            CCSPlayer::KickBack(
              this: PlayerOwner,
              up_base: 0.5,
              lateral_base: 0.27500001,
              up_modifier: 0.2,
              lateral_modifier: 0.029999999,
              up_max: 3.0,
              lateral_max: 2.0,
              direction_change: (IUniformRandomStream *)0xA);
          }
        }
        else
        {
          CCSPlayer::KickBack(
            this: PlayerOwner,
            up_base: 0.89999998,
            lateral_base: 0.47499999,
            up_modifier: 0.34999999,
            lateral_modifier: 0.0425,
            up_max: 5.0,
            lateral_max: 3.0,
            direction_change: (IUniformRandomStream *)6);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F0400
// Name: public: virtual enum CSWeaponID CWeaponMP7::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponMP7::GetCSWeaponID(CWeaponMP7 *this)
{
  return 24;
}

//------------------------------------------------------------------------------
// Address: 0x10412D50
// Name: DT_WeaponMP7::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMP7::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponMP7::g_SendTable);
  return atexit(func: DT_WeaponMP7::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412D70
// Name: DT_WeaponMP7::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMP7::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponMP7::ignored>();
  DT_WeaponMP7::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412DA0
// Name: weapon_mp7Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_mp7Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_mp7Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_mp7Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420D00
// Name: DT_WeaponMP7::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponMP7::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponMP7::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412DC0
// Name: _dynamic_initializer_for__g_CWeaponMP9_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponMP9_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponMP9_ClassReg,
           pNetworkName: "CWeaponMP9",
           pTable: &DT_WeaponMP9::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420D10
// Name: _ServerClassInit_DT_WeaponMP7::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponMP7::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_291;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
