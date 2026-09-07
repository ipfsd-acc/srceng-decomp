// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_tec9.cpp
// Functions: 11
// ============================================================

#include "game\shared\cstrike15\weapon_tec9.h"

//------------------------------------------------------------------------------
// Address: 0x102351C0
// Name: public: virtual class ClientClass __near * C_WeaponTec9::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponTec9::GetClientClass(C_WeaponTec9 *this)
{
  return &__g_C_WeaponTec9ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10235240
// Name: public: virtual struct datamap_t __near * C_WeaponTec9::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponTec9::GetPredDescMap(C_WeaponTec9 *this)
{
  return &C_WeaponTec9::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10235250
// Name: public: virtual void weapon_tec9Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_tec9Precache::CResourcePrecacher::Cache(
        weapon_tec9Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_tec9",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10235300
// Name: CC_WeaponTec9Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponTec9Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponTec9::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponTec9::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponTec9::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponTec9::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponTec9::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429B80
// Name: DT_WeaponTec9::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponTec9::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponTec9::g_RecvTable);
  return atexit(func: DT_WeaponTec9::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429BA0
// Name: DT_WeaponTec9::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponTec9::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponTec9::ignored>();
  DT_WeaponTec9::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429BB0
// Name: C_WeaponTec9_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponTec9_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponTec9::m_PredMap.dataNumFields = 1;
  C_WeaponTec9::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C8EC;
}

//------------------------------------------------------------------------------
// Address: 0x10429C00
// Name: weapon_tec9Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_tec9Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_tec9Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_tec9Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436200
// Name: DT_WeaponTec9::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponTec9::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponTec9::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10429BD0
// Name: _dynamic_initializer_for__g_Cweapon_tec9Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_tec9Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_tec9",
             a3: "C_WeaponTec9",
             a4: 3504,
             a5: CC_WeaponTec9Factory);
  __g_C_WeaponTec9ClientClass.m_pMapClassname = "weapon_tec9";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429C20
// Name: _dynamic_initializer_for____g_C_WeaponUMP45ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponUMP45ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponUMP45ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponUMP45ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F3240
// Name: public: virtual class ServerClass __near * CWeaponTec9::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponTec9::GetServerClass(CWeaponTec9 *this)
{
  return &g_CWeaponTec9_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F3250
// Name: public: virtual void weapon_tec9Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_tec9Precache::CResourcePrecacher::Cache(
        weapon_tec9Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_tec9",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F3310
// Name: public: virtual enum CSWeaponID CWeaponTec9::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponTec9::GetCSWeaponID(CWeaponTec9 *this)
{
  return 21;
}

//------------------------------------------------------------------------------
// Address: 0x10413420
// Name: DT_WeaponTec9::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponTec9::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponTec9::g_SendTable);
  return atexit(func: DT_WeaponTec9::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413440
// Name: DT_WeaponTec9::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponTec9::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponTec9::ignored>();
  DT_WeaponTec9::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413470
// Name: weapon_tec9Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_tec9Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_tec9Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_tec9Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420F50
// Name: DT_WeaponTec9::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponTec9::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponTec9::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10413490
// Name: _dynamic_initializer_for__g_CWeaponUMP45_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponUMP45_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponUMP45_ClassReg,
           pNetworkName: "CWeaponUMP45",
           pTable: &DT_WeaponUMP45::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420F60
// Name: _ServerClassInit_DT_WeaponTec9::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponTec9::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_303;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
