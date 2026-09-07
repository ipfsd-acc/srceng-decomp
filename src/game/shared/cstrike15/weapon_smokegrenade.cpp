// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_smokegrenade.cpp
// Functions: 13
// ============================================================

#include "game\shared\cstrike15\weapon_smokegrenade.h"

//------------------------------------------------------------------------------
// Address: 0x10234B20
// Name: public: virtual class ClientClass __near * C_SmokeGrenade::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SmokeGrenade::GetClientClass(C_SmokeGrenade *this)
{
  return &__g_C_SmokeGrenadeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10234BA0
// Name: public: virtual struct datamap_t __near * C_SmokeGrenade::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_SmokeGrenade::GetPredDescMap(C_SmokeGrenade *this)
{
  return &C_SmokeGrenade::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10234BB0
// Name: public: virtual void weapon_smokegrenadePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_smokegrenadePrecache::CResourcePrecacher::Cache(
        weapon_smokegrenadePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_smokegrenade",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10234BE0
// Name: public: virtual enum CSWeaponID C_SmokeGrenade::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_SmokeGrenade::GetCSWeaponID(C_SmokeGrenade *this)
{
  return 34;
}

//------------------------------------------------------------------------------
// Address: 0x10234C60
// Name: CC_SmokeGrenadeFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_SmokeGrenadeFactory()
{
  C_BaseCSGrenade *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v0);
  *v1 = &C_SmokeGrenade::`vftable'{for `IClientUnknown'};
  v1[1] = &C_SmokeGrenade::`vftable'{for `IClientRenderable'};
  v1[2] = &C_SmokeGrenade::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_SmokeGrenade::`vftable'{for `IClientThinkable'};
  v1[4] = &C_SmokeGrenade::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429940
// Name: DT_SmokeGrenade::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeGrenade::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SmokeGrenade::g_RecvTable);
  return atexit(func: DT_SmokeGrenade::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429960
// Name: DT_SmokeGrenade::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeGrenade::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SmokeGrenade::ignored>();
  DT_SmokeGrenade::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429970
// Name: C_SmokeGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_SmokeGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_SmokeGrenade::m_PredMap.dataNumFields = 1;
  C_SmokeGrenade::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C664;
}

//------------------------------------------------------------------------------
// Address: 0x104299C0
// Name: weapon_smokegrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_smokegrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_smokegrenadePrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_smokegrenadePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104361D0
// Name: DT_SmokeGrenade::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SmokeGrenade::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SmokeGrenade::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10234BF0
// Name: _C_SmokeGrenade_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SmokeGrenade_CreateObject(int entnum, int serialNum)
{
  C_BaseCSGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v2);
  *v3 = &C_SmokeGrenade::`vftable'{for `IClientUnknown'};
  v3[1] = &C_SmokeGrenade::`vftable'{for `IClientRenderable'};
  v3[2] = &C_SmokeGrenade::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_SmokeGrenade::`vftable'{for `IClientThinkable'};
  v3[4] = &C_SmokeGrenade::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429990
// Name: _dynamic_initializer_for__g_Cweapon_smokegrenadeFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_smokegrenadeFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_smokegrenade",
             a3: "C_SmokeGrenade",
             a4: 3520,
             a5: CC_SmokeGrenadeFactory);
  __g_C_SmokeGrenadeClientClass.m_pMapClassname = "weapon_smokegrenade";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104299E0
// Name: _dynamic_initializer_for____g_C_WeaponSSG08ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponSSG08ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponSSG08ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponSSG08ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F28C0
// Name: public: virtual class ServerClass __near * CSmokeGrenade::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSmokeGrenade::GetServerClass(CSmokeGrenade *this)
{
  return &g_CSmokeGrenade_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F28D0
// Name: public: virtual void weapon_smokegrenadePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_smokegrenadePrecache::CResourcePrecacher::Cache(
        weapon_smokegrenadePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_smokegrenade",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F2900
// Name: public: virtual struct datamap_t __near * CSmokeGrenade::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSmokeGrenade::GetDataDescMap(CSmokeGrenade *this)
{
  return &CSmokeGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102F2910
// Name: public: virtual void CSmokeGrenade::EmitGrenade(class Vector,class QAngle,class Vector,class Vector,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeGrenade::EmitGrenade(
        CSmokeGrenade *this,
        Vector vecSrc,
        QAngle vecAngles,
        Vector vecVel,
        Vector angImpulse,
        CBasePlayer *pPlayer)
{
  const CCSWeaponInfo *CSWpnData; // eax

  CSWpnData = CWeaponCSBase::GetCSWpnData(this);
  CSmokeGrenadeProjectile::Create(
    position: &vecSrc,
    angles: &vecAngles,
    velocity: &vecVel,
    angVelocity: &angImpulse,
    pOwner: pPlayer,
    color: (QAngle *)&CSWpnData->m_vSmokeColor);
}

//------------------------------------------------------------------------------
// Address: 0x102F29C0
// Name: public: virtual enum CSWeaponID CSmokeGrenade::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSmokeGrenade::GetCSWeaponID(CSmokeGrenade *this)
{
  return 34;
}

//------------------------------------------------------------------------------
// Address: 0x10413260
// Name: DT_SmokeGrenade::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeGrenade::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SmokeGrenade::g_SendTable);
  return atexit(func: DT_SmokeGrenade::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413280
// Name: DT_SmokeGrenade::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeGrenade::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SmokeGrenade::ignored>();
  DT_SmokeGrenade::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104132B0
// Name: weapon_smokegrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_smokegrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_smokegrenadePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_smokegrenadePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104132D0
// Name: CSmokeGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSmokeGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSmokeGrenade>(__formal: nullptr);
  CSmokeGrenade_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420EB0
// Name: DT_SmokeGrenade::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SmokeGrenade::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SmokeGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102F29D0
// Name: struct datamap_t __near * DataMapInit<class CSmokeGrenade>(class CSmokeGrenade __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSmokeGrenade>()
{
  if ( (_S3_163 & 1) == 0 )
  {
    _S3_163 |= 1u;
    nameHolder_500.m_pszBase = "CSmokeGrenade";
    nameHolder_500.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_500.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_500.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_500.m_Names.m_Size = 0;
    nameHolder_500.m_Names.m_pElements = nullptr;
    nameHolder_500.m_nLenBase = 13;
    atexit(func: DataMapInit_CSmokeGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSmokeGrenade::m_DataMap.baseMap = &CBaseCSGrenade::m_DataMap;
  CSmokeGrenade::m_DataMap.dataNumFields = 1;
  CSmokeGrenade::m_DataMap.dataDesc = dataDesc_515;
  return &CSmokeGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104132E0
// Name: _dynamic_initializer_for__g_CWeaponSSG08_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponSSG08_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponSSG08_ClassReg,
           pNetworkName: "CWeaponSSG08",
           pTable: &DT_WeaponSSG08::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420EC0
// Name: _ServerClassInit_DT_SmokeGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SmokeGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_300;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420EE0
// Name: _DataMapInit_CSmokeGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSmokeGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_500);
}

} // namespace server
