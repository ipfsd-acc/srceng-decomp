// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_mac10.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_mac10.h"

//------------------------------------------------------------------------------
// Address: 0x10231C00
// Name: public: virtual class ClientClass __near * C_WeaponMAC10::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponMAC10::GetClientClass(C_WeaponMAC10 *this)
{
  return &__g_C_WeaponMAC10ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10231C80
// Name: public: virtual struct datamap_t __near * C_WeaponMAC10::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponMAC10::GetPredDescMap(C_WeaponMAC10 *this)
{
  return &C_WeaponMAC10::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10231C90
// Name: public: virtual void weapon_mac10Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_mac10Precache::CResourcePrecacher::Cache(
        weapon_mac10Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_mac10",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10231CC0
// Name: public: virtual void C_WeaponMAC10::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponMAC10::PrimaryAttack(C_WeaponMAC10 *this)
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
                lateral_base: 0.40000001,
                up_modifier: 0.175,
                lateral_modifier: 0.029999999,
                up_max: 2.75,
                lateral_max: 2.5,
                direction_change: (IUniformRandomStream *)0xA);
            else
              C_CSPlayer::KickBack(
                this: (C_CSPlayer *)v5,
                up_base: 0.77499998,
                lateral_base: 0.42500001,
                up_modifier: 0.2,
                lateral_modifier: 0.029999999,
                up_max: 3.0,
                lateral_max: 2.75,
                direction_change: (IUniformRandomStream *)9);
          }
          else
          {
            C_CSPlayer::KickBack(
              this: (C_CSPlayer *)v5,
              up_base: 0.89999998,
              lateral_base: 0.44999999,
              up_modifier: 0.25,
              lateral_modifier: 0.035,
              up_max: 3.5,
              lateral_max: 2.75,
              direction_change: (IUniformRandomStream *)7);
          }
        }
        else
        {
          C_CSPlayer::KickBack(
            this: (C_CSPlayer *)v4,
            up_base: 1.3,
            lateral_base: 0.55000001,
            up_modifier: 0.40000001,
            lateral_modifier: 0.050000001,
            up_max: 4.75,
            lateral_max: 3.75,
            direction_change: (IUniformRandomStream *)5);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231F30
// Name: public: virtual enum CSWeaponID C_WeaponMAC10::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponMAC10::GetCSWeaponID(C_WeaponMAC10 *this)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10231FB0
// Name: CC_WeaponMAC10Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponMAC10Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponMAC10::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponMAC10::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponMAC10::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponMAC10::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponMAC10::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429020
// Name: DT_WeaponMAC10::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMAC10::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponMAC10::g_RecvTable);
  return atexit(func: DT_WeaponMAC10::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429040
// Name: DT_WeaponMAC10::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMAC10::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponMAC10::ignored>();
  DT_WeaponMAC10::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429050
// Name: C_WeaponMAC10_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponMAC10_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponMAC10::m_PredMap.dataNumFields = 1;
  C_WeaponMAC10::m_PredMap.dataDesc = (typedescription_t *)&unk_1066BC44;
}

//------------------------------------------------------------------------------
// Address: 0x104290A0
// Name: weapon_mac10Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_mac10Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_mac10Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_mac10Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436110
// Name: DT_WeaponMAC10::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponMAC10::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponMAC10::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10231F40
// Name: _C_WeaponMAC10_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponMAC10_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponMAC10::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponMAC10::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponMAC10::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponMAC10::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponMAC10::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429070
// Name: _dynamic_initializer_for__g_Cweapon_mac10Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_mac10Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_mac10",
             a3: "C_WeaponMAC10",
             a4: 3504,
             a5: CC_WeaponMAC10Factory);
  __g_C_WeaponMAC10ClientClass.m_pMapClassname = "weapon_mac10";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104290C0
// Name: _dynamic_initializer_for____g_C_WeaponMag7ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponMag7ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponMag7ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponMag7ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EFA10
// Name: public: virtual class ServerClass __near * CWeaponMAC10::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponMAC10::GetServerClass(CWeaponMAC10 *this)
{
  return &g_CWeaponMAC10_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EFA20
// Name: public: virtual void weapon_mac10Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_mac10Precache::CResourcePrecacher::Cache(
        weapon_mac10Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_mac10",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EFAD0
// Name: public: virtual void CWeaponMAC10::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponMAC10::PrimaryAttack(CWeaponMAC10 *this)
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
                lateral_base: 0.40000001,
                up_modifier: 0.175,
                lateral_modifier: 0.029999999,
                up_max: 2.75,
                lateral_max: 2.5,
                direction_change: (IUniformRandomStream *)0xA);
            else
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.77499998,
                lateral_base: 0.42500001,
                up_modifier: 0.2,
                lateral_modifier: 0.029999999,
                up_max: 3.0,
                lateral_max: 2.75,
                direction_change: (IUniformRandomStream *)9);
          }
          else
          {
            CCSPlayer::KickBack(
              this: PlayerOwner,
              up_base: 0.89999998,
              lateral_base: 0.44999999,
              up_modifier: 0.25,
              lateral_modifier: 0.035,
              up_max: 3.5,
              lateral_max: 2.75,
              direction_change: (IUniformRandomStream *)7);
          }
        }
        else
        {
          CCSPlayer::KickBack(
            this: PlayerOwner,
            up_base: 1.3,
            lateral_base: 0.55000001,
            up_modifier: 0.40000001,
            lateral_modifier: 0.050000001,
            up_max: 4.75,
            lateral_max: 3.75,
            direction_change: (IUniformRandomStream *)5);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EFD30
// Name: public: virtual enum CSWeaponID CWeaponMAC10::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponMAC10::GetCSWeaponID(CWeaponMAC10 *this)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10412B90
// Name: DT_WeaponMAC10::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMAC10::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponMAC10::g_SendTable);
  return atexit(func: DT_WeaponMAC10::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412BB0
// Name: DT_WeaponMAC10::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMAC10::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponMAC10::ignored>();
  DT_WeaponMAC10::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412BE0
// Name: weapon_mac10Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_mac10Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_mac10Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_mac10Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420C60
// Name: DT_WeaponMAC10::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponMAC10::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponMAC10::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412C00
// Name: _dynamic_initializer_for__g_CWeaponMag7_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponMag7_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponMag7_ClassReg,
           pNetworkName: "CWeaponMag7",
           pTable: &DT_WeaponMag7::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420C70
// Name: _ServerClassInit_DT_WeaponMAC10::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponMAC10::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_288;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
