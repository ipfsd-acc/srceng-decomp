// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_mag7.cpp
// Functions: 13
// ============================================================

#include "game\shared\cstrike15\weapon_mag7.h"

//------------------------------------------------------------------------------
// Address: 0x10232000
// Name: public: virtual class ClientClass __near * C_WeaponMag7::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponMag7::GetClientClass(C_WeaponMag7 *this)
{
  return &__g_C_WeaponMag7ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10232080
// Name: public: virtual struct datamap_t __near * C_WeaponMag7::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponMag7::GetPredDescMap(C_WeaponMag7 *this)
{
  return &C_WeaponMag7::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10232090
// Name: public: virtual void weapon_mag7Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_mag7Precache::CResourcePrecacher::Cache(
        weapon_mag7Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_mag7",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102320C0
// Name: public: virtual enum CSWeaponID C_WeaponMag7::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponMag7::GetCSWeaponID(C_WeaponMag7 *this)
{
  return 18;
}

//------------------------------------------------------------------------------
// Address: 0x10232140
// Name: CC_WeaponMag7Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponMag7Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponMag7::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponMag7::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponMag7::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponMag7::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponMag7::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x104290E0
// Name: DT_WeaponMag7::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMag7::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponMag7::g_RecvTable);
  return atexit(func: DT_WeaponMag7::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429100
// Name: DT_WeaponMag7::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMag7::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponMag7::ignored>();
  DT_WeaponMag7::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429110
// Name: C_WeaponMag7_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponMag7_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponMag7::m_PredMap.dataNumFields = 1;
  C_WeaponMag7::m_PredMap.dataDesc = (typedescription_t *)&unk_1066BD1C;
}

//------------------------------------------------------------------------------
// Address: 0x10429160
// Name: weapon_mag7Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_mag7Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_mag7Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_mag7Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436120
// Name: DT_WeaponMag7::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponMag7::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponMag7::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102320D0
// Name: _C_WeaponMag7_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponMag7_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponMag7::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponMag7::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponMag7::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponMag7::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponMag7::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429130
// Name: _dynamic_initializer_for__g_Cweapon_mag7Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_mag7Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_mag7",
             a3: "C_WeaponMag7",
             a4: 3504,
             a5: CC_WeaponMag7Factory);
  __g_C_WeaponMag7ClientClass.m_pMapClassname = "weapon_mag7";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429180
// Name: _dynamic_initializer_for____g_C_MolotovGrenadeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_MolotovGrenadeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_MolotovGrenadeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_MolotovGrenadeClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EFD80
// Name: public: virtual class ServerClass __near * CWeaponMag7::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponMag7::GetServerClass(CWeaponMag7 *this)
{
  return &g_CWeaponMag7_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EFD90
// Name: public: virtual void weapon_mag7Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_mag7Precache::CResourcePrecacher::Cache(
        weapon_mag7Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_mag7",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EFE40
// Name: public: virtual enum CSWeaponID CWeaponMag7::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponMag7::GetCSWeaponID(CWeaponMag7 *this)
{
  return 18;
}

//------------------------------------------------------------------------------
// Address: 0x10412C20
// Name: DT_WeaponMag7::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMag7::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponMag7::g_SendTable);
  return atexit(func: DT_WeaponMag7::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412C40
// Name: DT_WeaponMag7::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponMag7::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponMag7::ignored>();
  DT_WeaponMag7::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412C70
// Name: weapon_mag7Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_mag7Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_mag7Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_mag7Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420C90
// Name: DT_WeaponMag7::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponMag7::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponMag7::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412C90
// Name: _dynamic_initializer_for__g_CMolotovGrenade_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CMolotovGrenade_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CMolotovGrenade_ClassReg,
           pNetworkName: "CMolotovGrenade",
           pTable: &DT_MolotovGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420CA0
// Name: _ServerClassInit_DT_WeaponMag7::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponMag7::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_289;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
