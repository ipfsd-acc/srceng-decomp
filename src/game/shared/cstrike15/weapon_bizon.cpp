// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_bizon.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_bizon.h"

//------------------------------------------------------------------------------
// Address: 0x10229E10
// Name: public: virtual class ClientClass __near * C_WeaponBizon::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponBizon::GetClientClass(C_WeaponBizon *this)
{
  return &__g_C_WeaponBizonClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10229E90
// Name: public: virtual struct datamap_t __near * C_WeaponBizon::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponBizon::GetPredDescMap(C_WeaponBizon *this)
{
  return &C_WeaponBizon::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10229EA0
// Name: public: virtual void weapon_bizonPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_bizonPrecache::CResourcePrecacher::Cache(
        weapon_bizonPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_bizon",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10229ED0
// Name: public: virtual void C_WeaponBizon::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponBizon::PrimaryAttack(C_WeaponBizon *this)
{
  int v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229F00
// Name: public: virtual enum CSWeaponID C_WeaponBizon::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponBizon::GetCSWeaponID(C_WeaponBizon *this)
{
  return 17;
}

//------------------------------------------------------------------------------
// Address: 0x10229F80
// Name: CC_WeaponBizonFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponBizonFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponBizon::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponBizon::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponBizon::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponBizon::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponBizon::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10427E10
// Name: DT_WeaponBizon::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponBizon::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponBizon::g_RecvTable);
  return atexit(func: DT_WeaponBizon::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10427E30
// Name: DT_WeaponBizon::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponBizon::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponBizon::ignored>();
  DT_WeaponBizon::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427E40
// Name: C_WeaponBizon_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponBizon_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponBizon::m_PredMap.dataNumFields = 1;
  C_WeaponBizon::m_PredMap.dataDesc = (typedescription_t *)&unk_1066A23C;
}

//------------------------------------------------------------------------------
// Address: 0x10427E90
// Name: weapon_bizonPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_bizonPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_bizonPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_bizonPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435E50
// Name: DT_WeaponBizon::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponBizon::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponBizon::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10229F10
// Name: _C_WeaponBizon_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponBizon_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponBizon::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponBizon::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponBizon::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponBizon::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponBizon::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10427E60
// Name: _dynamic_initializer_for__g_Cweapon_bizonFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_bizonFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_bizon",
             a3: "C_WeaponBizon",
             a4: 3504,
             a5: CC_WeaponBizonFactory);
  __g_C_WeaponBizonClientClass.m_pMapClassname = "weapon_bizon";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427EB0
// Name: _dynamic_initializer_for____g_C_C4ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_C4ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_C4ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_C4ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102E4B90
// Name: public: virtual class ServerClass __near * CWeaponBizon::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponBizon::GetServerClass(CWeaponBizon *this)
{
  return &g_CWeaponBizon_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102E4BA0
// Name: public: virtual void weapon_bizonPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_bizonPrecache::CResourcePrecacher::Cache(
        weapon_bizonPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_bizon",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102E4BD0
// Name: public: virtual void CWeaponBizon::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponBizon::PrimaryAttack(CWeaponBizon *this)
{
  const CCSWeaponInfo *CSWpnData; // eax

  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    CWeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4C80
// Name: public: virtual enum CSWeaponID CWeaponBizon::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponBizon::GetCSWeaponID(CWeaponBizon *this)
{
  return 17;
}

//------------------------------------------------------------------------------
// Address: 0x10411F10
// Name: DT_WeaponBizon::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponBizon::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponBizon::g_SendTable);
  return atexit(func: DT_WeaponBizon::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411F30
// Name: DT_WeaponBizon::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponBizon::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponBizon::ignored>();
  DT_WeaponBizon::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411F60
// Name: weapon_bizonPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_bizonPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_bizonPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_bizonPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104207D0
// Name: DT_WeaponBizon::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponBizon::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponBizon::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10411F80
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___52
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___52()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_52,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_52,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411FA0
// Name: _dynamic_initializer_for__planted_c4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__planted_c4__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CPlantedC4> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &planted_c4,
           a3: "planted_c4");
}

//------------------------------------------------------------------------------
// Address: 0x104207E0
// Name: _ServerClassInit_DT_WeaponBizon::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponBizon::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_270;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
