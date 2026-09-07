// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_flashbang.cpp
// Functions: 13
// ============================================================

#include "game\shared\cstrike15\weapon_flashbang.h"

//------------------------------------------------------------------------------
// Address: 0x1022EBF0
// Name: public: virtual class ClientClass __near * C_Flashbang::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Flashbang::GetClientClass(C_Flashbang *this)
{
  return &__g_C_FlashbangClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022EC70
// Name: public: virtual struct datamap_t __near * C_Flashbang::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_Flashbang::GetPredDescMap(C_Flashbang *this)
{
  return &C_Flashbang::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022EC80
// Name: public: virtual void weapon_flashbangPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_flashbangPrecache::CResourcePrecacher::Cache(
        weapon_flashbangPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_flashbang",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022ECB0
// Name: public: virtual enum CSWeaponID C_Flashbang::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Flashbang::GetCSWeaponID(C_Flashbang *this)
{
  return 32;
}

//------------------------------------------------------------------------------
// Address: 0x1022ED30
// Name: CC_FlashbangFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_FlashbangFactory()
{
  C_BaseCSGrenade *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v0);
  *v1 = &C_Flashbang::`vftable'{for `IClientUnknown'};
  v1[1] = &C_Flashbang::`vftable'{for `IClientRenderable'};
  v1[2] = &C_Flashbang::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_Flashbang::`vftable'{for `IClientThinkable'};
  v1[4] = &C_Flashbang::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10428930
// Name: DT_Flashbang::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Flashbang::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Flashbang::g_RecvTable);
  return atexit(func: DT_Flashbang::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428950
// Name: DT_Flashbang::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Flashbang::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Flashbang::ignored>();
  DT_Flashbang::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428960
// Name: C_Flashbang_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_Flashbang_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_Flashbang::m_PredMap.dataNumFields = 1;
  C_Flashbang::m_PredMap.dataDesc = (typedescription_t *)&unk_1066B364;
}

//------------------------------------------------------------------------------
// Address: 0x104289B0
// Name: weapon_flashbangPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_flashbangPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_flashbangPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_flashbangPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436070
// Name: DT_Flashbang::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Flashbang::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Flashbang::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022ECC0
// Name: _C_Flashbang_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Flashbang_CreateObject(int entnum, int serialNum)
{
  C_BaseCSGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v2);
  *v3 = &C_Flashbang::`vftable'{for `IClientUnknown'};
  v3[1] = &C_Flashbang::`vftable'{for `IClientRenderable'};
  v3[2] = &C_Flashbang::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_Flashbang::`vftable'{for `IClientThinkable'};
  v3[4] = &C_Flashbang::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10428980
// Name: _dynamic_initializer_for__g_Cweapon_flashbangFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_flashbangFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_flashbang",
             a3: "C_Flashbang",
             a4: 3520,
             a5: CC_FlashbangFactory);
  __g_C_FlashbangClientClass.m_pMapClassname = "weapon_flashbang";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104289D0
// Name: _dynamic_initializer_for____g_C_WeaponG3SG1ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponG3SG1ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponG3SG1ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponG3SG1ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EBFF0
// Name: public: virtual class ServerClass __near * CFlashbang::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFlashbang::GetServerClass(CFlashbang *this)
{
  return &g_CFlashbang_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EC000
// Name: public: virtual void weapon_flashbangPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_flashbangPrecache::CResourcePrecacher::Cache(
        weapon_flashbangPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_flashbang",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EC030
// Name: public: virtual struct datamap_t __near * CFlashbang::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFlashbang::GetDataDescMap(CFlashbang *this)
{
  return &CFlashbang::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102EC040
// Name: public: virtual void CFlashbang::EmitGrenade(class Vector,class QAngle,class Vector,class Vector,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashbang::EmitGrenade(
        CFlashbang *this,
        Vector vecSrc,
        QAngle vecAngles,
        Vector vecVel,
        Vector angImpulse,
        CBasePlayer *pPlayer)
{
  CFlashbangProjectile::Create(
    position: &vecSrc,
    angles: &vecAngles,
    velocity: &vecVel,
    angVelocity: &angImpulse,
    pOwner: pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x102EC0F0
// Name: public: virtual enum CSWeaponID CFlashbang::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFlashbang::GetCSWeaponID(CFlashbang *this)
{
  return 32;
}

//------------------------------------------------------------------------------
// Address: 0x104125E0
// Name: DT_Flashbang::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Flashbang::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Flashbang::g_SendTable);
  return atexit(func: DT_Flashbang::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412600
// Name: DT_Flashbang::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Flashbang::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Flashbang::ignored>();
  DT_Flashbang::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412630
// Name: weapon_flashbangPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_flashbangPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_flashbangPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_flashbangPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412650
// Name: CFlashbang_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFlashbang_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFlashbang>(__formal: nullptr);
  CFlashbang_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420A40
// Name: DT_Flashbang::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Flashbang::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Flashbang::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102EC100
// Name: struct datamap_t __near * DataMapInit<class CFlashbang>(class CFlashbang __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFlashbang>()
{
  if ( (_S3_159 & 1) == 0 )
  {
    _S3_159 |= 1u;
    nameHolder_496.m_pszBase = "CFlashbang";
    nameHolder_496.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_496.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_496.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_496.m_Names.m_Size = 0;
    nameHolder_496.m_Names.m_pElements = nullptr;
    nameHolder_496.m_nLenBase = 10;
    atexit(func: DataMapInit_CFlashbang__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFlashbang::m_DataMap.baseMap = &CBaseCSGrenade::m_DataMap;
  CFlashbang::m_DataMap.dataNumFields = 1;
  CFlashbang::m_DataMap.dataDesc = dataDesc_511;
  return &CFlashbang::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10412660
// Name: _dynamic_initializer_for__g_CWeaponG3SG1_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponG3SG1_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponG3SG1_ClassReg,
           pNetworkName: "CWeaponG3SG1",
           pTable: &DT_WeaponG3SG1::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420A50
// Name: _ServerClassInit_DT_Flashbang::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Flashbang::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_279;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420A70
// Name: _DataMapInit_CFlashbang__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFlashbang__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_496);
}

} // namespace server
