// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_mp9.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_mp9.h"

//------------------------------------------------------------------------------
// Address: 0x10232AB0
// Name: public: virtual class ClientClass __near * C_WeaponMP9::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponMP9::GetClientClass(C_WeaponMP9 *this)
{
  return &__g_C_WeaponMP9ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10232B30
// Name: public: virtual struct datamap_t __near * C_WeaponMP9::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponMP9::GetPredDescMap(C_WeaponMP9 *this)
{
  return &C_WeaponMP9::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10232B40
// Name: public: virtual void weapon_mp9Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_mp9Precache::CResourcePrecacher::Cache(
        weapon_mp9Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_mp9",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10232B70
// Name: public: virtual void C_WeaponMP9::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponMP9::PrimaryAttack(C_WeaponMP9 *this)
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
                up_base: 0.69999999,
                lateral_base: 0.34999999,
                up_modifier: 0.125,
                lateral_modifier: 0.025,
                up_max: 2.5,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)0xA);
            else
              C_CSPlayer::KickBack(
                this: (C_CSPlayer *)v5,
                up_base: 0.72500002,
                lateral_base: 0.375,
                up_modifier: 0.15000001,
                lateral_modifier: 0.025,
                up_max: 2.75,
                lateral_max: 2.25,
                direction_change: (IUniformRandomStream *)9);
          }
          else
          {
            C_CSPlayer::KickBack(
              this: (C_CSPlayer *)v5,
              up_base: 0.80000001,
              lateral_base: 0.40000001,
              up_modifier: 0.2,
              lateral_modifier: 0.029999999,
              up_max: 3.0,
              lateral_max: 2.5,
              direction_change: (IUniformRandomStream *)7);
          }
        }
        else
        {
          C_CSPlayer::KickBack(
            this: (C_CSPlayer *)v4,
            up_base: 1.1,
            lateral_base: 0.5,
            up_modifier: 0.34999999,
            lateral_modifier: 0.045000002,
            up_max: 4.5,
            lateral_max: 3.5,
            direction_change: (IUniformRandomStream *)6);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10232DE0
// Name: public: virtual enum CSWeaponID C_WeaponMP9::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponMP9::GetCSWeaponID(C_WeaponMP9 *this)
{
  return 25;
}

//------------------------------------------------------------------------------
// Address: 0x10232E60
// Name: CC_WeaponMP9Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponMP9Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponMP9::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponMP9::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponMP9::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponMP9::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponMP9::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429340
// Name: DT_WeaponMP9::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMP9::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponMP9::g_RecvTable);
  return atexit(func: DT_WeaponMP9::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429360
// Name: DT_WeaponMP9::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMP9::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponMP9::ignored>();
  DT_WeaponMP9::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429370
// Name: C_WeaponMP9_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponMP9_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponMP9::m_PredMap.dataNumFields = 1;
  C_WeaponMP9::m_PredMap.dataDesc = (typedescription_t *)&unk_1066BFA4;
}

//------------------------------------------------------------------------------
// Address: 0x104293C0
// Name: weapon_mp9Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_mp9Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_mp9Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_mp9Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436150
// Name: DT_WeaponMP9::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponMP9::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponMP9::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10232DF0
// Name: _C_WeaponMP9_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponMP9_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponMP9::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponMP9::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponMP9::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponMP9::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponMP9::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429390
// Name: _dynamic_initializer_for__g_Cweapon_mp9Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_mp9Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_mp9",
             a3: "C_WeaponMP9",
             a4: 3504,
             a5: CC_WeaponMP9Factory);
  __g_C_WeaponMP9ClientClass.m_pMapClassname = "weapon_mp9";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104293E0
// Name: _dynamic_initializer_for____g_C_WeaponNegevClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponNegevClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponNegevClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponNegevClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F0450
// Name: public: virtual class ServerClass __near * CWeaponMP9::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponMP9::GetServerClass(CWeaponMP9 *this)
{
  return &g_CWeaponMP9_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F0460
// Name: public: virtual void weapon_mp9Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_mp9Precache::CResourcePrecacher::Cache(
        weapon_mp9Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_mp9",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F0510
// Name: public: virtual void CWeaponMP9::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponMP9::PrimaryAttack(CWeaponMP9 *this)
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
                up_base: 0.69999999,
                lateral_base: 0.34999999,
                up_modifier: 0.125,
                lateral_modifier: 0.025,
                up_max: 2.5,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)0xA);
            else
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.72500002,
                lateral_base: 0.375,
                up_modifier: 0.15000001,
                lateral_modifier: 0.025,
                up_max: 2.75,
                lateral_max: 2.25,
                direction_change: (IUniformRandomStream *)9);
          }
          else
          {
            CCSPlayer::KickBack(
              this: PlayerOwner,
              up_base: 0.80000001,
              lateral_base: 0.40000001,
              up_modifier: 0.2,
              lateral_modifier: 0.029999999,
              up_max: 3.0,
              lateral_max: 2.5,
              direction_change: (IUniformRandomStream *)7);
          }
        }
        else
        {
          CCSPlayer::KickBack(
            this: PlayerOwner,
            up_base: 1.1,
            lateral_base: 0.5,
            up_modifier: 0.34999999,
            lateral_modifier: 0.045000002,
            up_max: 4.5,
            lateral_max: 3.5,
            direction_change: (IUniformRandomStream *)6);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F0770
// Name: public: virtual enum CSWeaponID CWeaponMP9::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponMP9::GetCSWeaponID(CWeaponMP9 *this)
{
  return 25;
}

//------------------------------------------------------------------------------
// Address: 0x10412DE0
// Name: DT_WeaponMP9::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMP9::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponMP9::g_SendTable);
  return atexit(func: DT_WeaponMP9::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412E00
// Name: DT_WeaponMP9::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMP9::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponMP9::ignored>();
  DT_WeaponMP9::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412E30
// Name: weapon_mp9Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_mp9Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_mp9Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_mp9Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420D30
// Name: DT_WeaponMP9::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponMP9::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponMP9::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412E50
// Name: _dynamic_initializer_for__g_CWeaponNegev_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponNegev_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponNegev_ClassReg,
           pNetworkName: "CWeaponNegev",
           pTable: &DT_WeaponNegev::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420D40
// Name: _ServerClassInit_DT_WeaponMP9::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponMP9::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_292;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
