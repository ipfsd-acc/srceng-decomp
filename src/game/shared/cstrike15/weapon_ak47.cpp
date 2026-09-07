// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_ak47.cpp
// Functions: 16
// ============================================================

#include "game\shared\cstrike15\weapon_ak47.h"

//------------------------------------------------------------------------------
// Address: 0x102289C0
// Name: public: virtual class ClientClass __near * C_AK47::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_AK47::GetClientClass(C_AK47 *this)
{
  return &__g_C_AK47ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10228A40
// Name: public: virtual struct datamap_t __near * C_AK47::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_AK47::GetPredDescMap(C_AK47 *this)
{
  return &C_AK47::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10228A50
// Name: public: virtual void weapon_ak47Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_ak47Precache::CResourcePrecacher::Cache(
        weapon_ak47Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_ak47",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10228A80
// Name: public: virtual void C_AK47::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_AK47::PrimaryAttack(C_AK47 *this)
{
  int v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  C_BaseEntity *v4; // eax
  C_CSPlayer *v5; // esi
  int m_fFlags; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode) )
    {
      C_WeaponCSBase::GetPlayerOwner(this);
      v5 = (C_CSPlayer *)v4;
      if ( v4 != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        C_BaseEntity::CalcAbsoluteVelocity(this: v4);
        if ( fsqrt(
               (float)(v5->m_vecAbsVelocity.x * v5->m_vecAbsVelocity.x)
             + (float)(v5->m_vecAbsVelocity.y * v5->m_vecAbsVelocity.y)) <= 5.0 )
        {
          m_fFlags = v5->m_fFlags;
          if ( (m_fFlags & 1) != 0 )
          {
            if ( (m_fFlags & 2) != 0 )
              C_CSPlayer::KickBack(
                this: v5,
                up_base: 0.89999998,
                lateral_base: 0.34999999,
                up_modifier: 0.15000001,
                lateral_modifier: 0.025,
                up_max: 5.5,
                lateral_max: 1.5,
                direction_change: (IUniformRandomStream *)9);
            else
              C_CSPlayer::KickBack(
                this: v5,
                up_base: 1.0,
                lateral_base: 0.375,
                up_modifier: 0.175,
                lateral_modifier: 0.037500001,
                up_max: 5.75,
                lateral_max: 1.75,
                direction_change: (IUniformRandomStream *)8);
          }
          else
          {
            C_CSPlayer::KickBack(
              this: v5,
              up_base: 2.0,
              lateral_base: 1.0,
              up_modifier: 0.5,
              lateral_modifier: 0.34999999,
              up_max: 9.0,
              lateral_max: 6.0,
              direction_change: (IUniformRandomStream *)5);
          }
        }
        else
        {
          C_CSPlayer::KickBack(
            this: v5,
            up_base: 1.5,
            lateral_base: 0.44999999,
            up_modifier: 0.22499999,
            lateral_modifier: 0.050000001,
            up_max: 6.5,
            lateral_max: 2.5,
            direction_change: (IUniformRandomStream *)7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10228CF0
// Name: public: virtual char const __near * C_WeaponCSBase::GetTracerType(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponCSBase::GetTracerType(C_WeaponCSBase *this)
{
  return C_WeaponCSBase::GetCSWpnData(this)->m_szTracerEffectName;
}

//------------------------------------------------------------------------------
// Address: 0x10228D00
// Name: public: virtual float C_WeaponCSBase::GetInaccuracy(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_WeaponCSBase::GetInaccuracy(C_WeaponCSBase *this)
{
  return this->m_fAccuracyPenalty.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10228D10
// Name: public: virtual float C_WeaponCSBase::GetSpread(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_WeaponCSBase::GetSpread(C_WeaponCSBase *this)
{
  return C_WeaponCSBase::GetCSWpnData(this)->m_fSpread[this->m_weaponMode.m_Value];
}

//------------------------------------------------------------------------------
// Address: 0x10228DA0
// Name: CC_AK47Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_AK47Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_AK47::`vftable'{for `IClientUnknown'};
  v1[1] = &C_AK47::`vftable'{for `IClientRenderable'};
  v1[2] = &C_AK47::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_AK47::`vftable'{for `IClientThinkable'};
  v1[4] = &C_AK47::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10427B30
// Name: DT_WeaponAK47::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAK47::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponAK47::g_RecvTable);
  return atexit(func: DT_WeaponAK47::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10427B50
// Name: DT_WeaponAK47::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAK47::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponAK47::ignored>();
  DT_WeaponAK47::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427B60
// Name: C_AK47_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_AK47_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_AK47::m_PredMap.dataNumFields = 1;
  C_AK47::m_PredMap.dataDesc = (typedescription_t *)&unk_10669E2C;
}

//------------------------------------------------------------------------------
// Address: 0x10427BB0
// Name: weapon_ak47Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_ak47Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_ak47Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_ak47Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435E10
// Name: DT_WeaponAK47::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponAK47::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponAK47::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10228D30
// Name: _C_AK47_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_AK47_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_AK47::`vftable'{for `IClientUnknown'};
  v3[1] = &C_AK47::`vftable'{for `IClientRenderable'};
  v3[2] = &C_AK47::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_AK47::`vftable'{for `IClientThinkable'};
  v3[4] = &C_AK47::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10427B80
// Name: _dynamic_initializer_for__g_Cweapon_ak47Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_ak47Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_ak47",
             a3: "C_AK47",
             a4: 3504,
             a5: CC_AK47Factory);
  __g_C_AK47ClientClass.m_pMapClassname = "weapon_ak47";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427BD0
// Name: _dynamic_initializer_for____g_C_WeaponAugClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponAugClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponAugClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponAugClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102E2A70
// Name: public: virtual class ServerClass __near * CAK47::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CAK47::GetServerClass(CAK47 *this)
{
  return &g_CAK47_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102E2A80
// Name: public: virtual void weapon_ak47Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_ak47Precache::CResourcePrecacher::Cache(
        weapon_ak47Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_ak47",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102E2B30
// Name: public: virtual void CAK47::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAK47::PrimaryAttack(CAK47 *this@<ecx>, int a2@<ebp>)
{
  const CCSWeaponInfo *CSWpnData; // eax
  CCSPlayer *PlayerOwner; // esi
  int m_Value; // eax
  _DWORD v6[3]; // [esp+3Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+48h] [ebp+0h]

  v6[0] = a2;
  v6[1] = retaddr;
  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode) )
    {
      PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
      if ( PlayerOwner != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (PlayerOwner->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: PlayerOwner, a2: (int)v6);
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
                up_base: 0.89999998,
                lateral_base: 0.34999999,
                up_modifier: 0.15000001,
                lateral_modifier: 0.025,
                up_max: 5.5,
                lateral_max: 1.5,
                direction_change: (IUniformRandomStream *)9);
            else
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 1.0,
                lateral_base: 0.375,
                up_modifier: 0.175,
                lateral_modifier: 0.037500001,
                up_max: 5.75,
                lateral_max: 1.75,
                direction_change: (IUniformRandomStream *)8);
          }
          else
          {
            CCSPlayer::KickBack(
              this: PlayerOwner,
              up_base: 2.0,
              lateral_base: 1.0,
              up_modifier: 0.5,
              lateral_modifier: 0.34999999,
              up_max: 9.0,
              lateral_max: 6.0,
              direction_change: (IUniformRandomStream *)5);
          }
        }
        else
        {
          CCSPlayer::KickBack(
            this: PlayerOwner,
            up_base: 1.5,
            lateral_base: 0.44999999,
            up_modifier: 0.22499999,
            lateral_modifier: 0.050000001,
            up_max: 6.5,
            lateral_max: 2.5,
            direction_change: (IUniformRandomStream *)7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E2DA0
// Name: public: virtual enum CSWeaponID CAK47::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAK47::GetCSWeaponID(CAK47 *this)
{
  return 5;
}

//------------------------------------------------------------------------------
// Address: 0x102E2DB0
// Name: public: virtual char const __near * CWeaponCSBase::GetTracerType(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWeaponCSBase::GetTracerType(CWeaponCSBase *this)
{
  return CWeaponCSBase::GetCSWpnData(this)->m_szTracerEffectName;
}

//------------------------------------------------------------------------------
// Address: 0x102E2DC0
// Name: public: virtual float CWeaponCSBase::GetInaccuracy(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWeaponCSBase::GetInaccuracy(CWeaponCSBase *this)
{
  return this->m_fAccuracyPenalty.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102E2DD0
// Name: public: virtual float CWeaponCSBase::GetSpread(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWeaponCSBase::GetSpread(CWeaponCSBase *this)
{
  return CWeaponCSBase::GetCSWpnData(this)->m_fSpread[this->m_weaponMode.m_Value];
}

//------------------------------------------------------------------------------
// Address: 0x10411CA0
// Name: DT_WeaponAK47::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAK47::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponAK47::g_SendTable);
  return atexit(func: DT_WeaponAK47::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411CC0
// Name: DT_WeaponAK47::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAK47::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponAK47::ignored>();
  DT_WeaponAK47::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411CF0
// Name: weapon_ak47Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_ak47Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_ak47Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_ak47Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104206E0
// Name: DT_WeaponAK47::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponAK47::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponAK47::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10411D10
// Name: _dynamic_initializer_for__g_CWeaponAug_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponAug_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponAug_ClassReg,
           pNetworkName: "CWeaponAug",
           pTable: &DT_WeaponAug::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104206F0
// Name: _ServerClassInit_DT_WeaponAK47::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponAK47::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_266;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
