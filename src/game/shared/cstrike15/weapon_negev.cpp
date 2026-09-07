// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_negev.cpp
// Functions: 13
// ============================================================

#include "game\shared\cstrike15\weapon_negev.h"

//------------------------------------------------------------------------------
// Address: 0x10232EB0
// Name: public: virtual class ClientClass __near * C_WeaponNegev::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponNegev::GetClientClass(C_WeaponNegev *this)
{
  return &__g_C_WeaponNegevClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10232F30
// Name: public: virtual struct datamap_t __near * C_WeaponNegev::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponNegev::GetPredDescMap(C_WeaponNegev *this)
{
  return &C_WeaponNegev::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10232F40
// Name: public: virtual void weapon_negevPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_negevPrecache::CResourcePrecacher::Cache(
        weapon_negevPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_negev",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10232F70
// Name: public: virtual enum CSWeaponID C_WeaponNegev::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponNegev::GetCSWeaponID(C_WeaponNegev *this)
{
  return 19;
}

//------------------------------------------------------------------------------
// Address: 0x10232FF0
// Name: CC_WeaponNegevFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponNegevFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponNegev::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponNegev::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponNegev::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponNegev::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponNegev::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429400
// Name: DT_WeaponNegev::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponNegev::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponNegev::g_RecvTable);
  return atexit(func: DT_WeaponNegev::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429420
// Name: DT_WeaponNegev::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponNegev::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponNegev::ignored>();
  DT_WeaponNegev::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429430
// Name: C_WeaponNegev_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponNegev_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponNegev::m_PredMap.dataNumFields = 1;
  C_WeaponNegev::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C07C;
}

//------------------------------------------------------------------------------
// Address: 0x10429480
// Name: weapon_negevPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_negevPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_negevPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_negevPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436160
// Name: DT_WeaponNegev::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponNegev::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponNegev::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10232F80
// Name: _C_WeaponNegev_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponNegev_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponNegev::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponNegev::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponNegev::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponNegev::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponNegev::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429450
// Name: _dynamic_initializer_for__g_Cweapon_negevFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_negevFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_negev",
             a3: "C_WeaponNegev",
             a4: 3504,
             a5: CC_WeaponNegevFactory);
  __g_C_WeaponNegevClientClass.m_pMapClassname = "weapon_negev";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104294A0
// Name: _dynamic_initializer_for____g_C_WeaponNOVAClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponNOVAClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponNOVAClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponNOVAClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F07C0
// Name: public: virtual class ServerClass __near * CWeaponNegev::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponNegev::GetServerClass(CWeaponNegev *this)
{
  return &g_CWeaponNegev_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F07D0
// Name: public: virtual void weapon_negevPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_negevPrecache::CResourcePrecacher::Cache(
        weapon_negevPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_negev",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F0880
// Name: public: virtual enum CSWeaponID CWeaponNegev::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponNegev::GetCSWeaponID(CWeaponNegev *this)
{
  return 19;
}

//------------------------------------------------------------------------------
// Address: 0x10412E70
// Name: DT_WeaponNegev::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponNegev::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponNegev::g_SendTable);
  return atexit(func: DT_WeaponNegev::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412E90
// Name: DT_WeaponNegev::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponNegev::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponNegev::ignored>();
  DT_WeaponNegev::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412EC0
// Name: weapon_negevPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_negevPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_negevPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_negevPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420D60
// Name: DT_WeaponNegev::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponNegev::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponNegev::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412EE0
// Name: _dynamic_initializer_for__g_CWeaponNOVA_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponNOVA_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponNOVA_ClassReg,
           pNetworkName: "CWeaponNOVA",
           pTable: &DT_WeaponNOVA::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420D70
// Name: _ServerClassInit_DT_WeaponNegev::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponNegev::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_293;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
