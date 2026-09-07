// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_hegrenade.cpp
// Functions: 13
// ============================================================

#include "game\shared\cstrike15\weapon_hegrenade.h"

//------------------------------------------------------------------------------
// Address: 0x1022FC20
// Name: public: virtual class ClientClass __near * C_HEGrenade::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_HEGrenade::GetClientClass(C_HEGrenade *this)
{
  return &__g_C_HEGrenadeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022FCA0
// Name: public: virtual struct datamap_t __near * C_HEGrenade::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_HEGrenade::GetPredDescMap(C_HEGrenade *this)
{
  return &C_HEGrenade::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022FCB0
// Name: public: virtual void weapon_hegrenadePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_hegrenadePrecache::CResourcePrecacher::Cache(
        weapon_hegrenadePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_hegrenade",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022FCE0
// Name: public: virtual enum CSWeaponID C_HEGrenade::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_HEGrenade::GetCSWeaponID(C_HEGrenade *this)
{
  return 33;
}

//------------------------------------------------------------------------------
// Address: 0x1022FD60
// Name: CC_HEGrenadeFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_HEGrenadeFactory()
{
  C_BaseCSGrenade *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v0);
  *v1 = &C_HEGrenade::`vftable'{for `IClientUnknown'};
  v1[1] = &C_HEGrenade::`vftable'{for `IClientRenderable'};
  v1[2] = &C_HEGrenade::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_HEGrenade::`vftable'{for `IClientThinkable'};
  v1[4] = &C_HEGrenade::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10428C30
// Name: DT_HEGrenade::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_HEGrenade::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_HEGrenade::g_RecvTable);
  return atexit(func: DT_HEGrenade::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428C50
// Name: DT_HEGrenade::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_HEGrenade::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_HEGrenade::ignored>();
  DT_HEGrenade::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428C60
// Name: C_HEGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_HEGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_HEGrenade::m_PredMap.dataNumFields = 1;
  C_HEGrenade::m_PredMap.dataDesc = (typedescription_t *)&unk_1066B6FC;
}

//------------------------------------------------------------------------------
// Address: 0x10428CB0
// Name: weapon_hegrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_hegrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_hegrenadePrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_hegrenadePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104360B0
// Name: DT_HEGrenade::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_HEGrenade::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_HEGrenade::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022FCF0
// Name: _C_HEGrenade_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_HEGrenade_CreateObject(int entnum, int serialNum)
{
  C_BaseCSGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v2);
  *v3 = &C_HEGrenade::`vftable'{for `IClientUnknown'};
  v3[1] = &C_HEGrenade::`vftable'{for `IClientRenderable'};
  v3[2] = &C_HEGrenade::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_HEGrenade::`vftable'{for `IClientThinkable'};
  v3[4] = &C_HEGrenade::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10428C80
// Name: _dynamic_initializer_for__g_Cweapon_hegrenadeFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_hegrenadeFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_hegrenade",
             a3: "C_HEGrenade",
             a4: 3520,
             a5: CC_HEGrenadeFactory);
  __g_C_HEGrenadeClientClass.m_pMapClassname = "weapon_hegrenade";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428CD0
// Name: _dynamic_initializer_for____g_C_WeaponHKP2000ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponHKP2000ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponHKP2000ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponHKP2000ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100AE130
// Name: public: virtual int CHEGrenade::YouForgotToImplementOrDeclareServerClass(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHEGrenade::YouForgotToImplementOrDeclareServerClass(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102ED340
// Name: public: virtual class ServerClass __near * CHEGrenade::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CHEGrenade::GetServerClass(CHEGrenade *this)
{
  return &g_CHEGrenade_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102ED350
// Name: public: virtual void weapon_hegrenadePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_hegrenadePrecache::CResourcePrecacher::Cache(
        weapon_hegrenadePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_hegrenade",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102ED380
// Name: public: virtual struct datamap_t __near * CHEGrenade::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CHEGrenade::GetDataDescMap(CHEGrenade *this)
{
  return &CHEGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102ED390
// Name: public: virtual void CHEGrenade::EmitGrenade(class Vector,class QAngle,class Vector,class Vector,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHEGrenade::EmitGrenade(
        CHEGrenade *this,
        Vector vecSrc,
        QAngle vecAngles,
        Vector vecVel,
        Vector angImpulse,
        CBasePlayer *pPlayer)
{
  CBasePlayer *v6; // esi

  v6 = pPlayer;
  if ( pPlayer != nullptr
    && pPlayer->IsPlayer(this: pPlayer)
    && __RTDynamicCast(
         inptr: v6,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CCSPlayer `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    CCSPlayer::StartNewBulletGroup();
  }
  CHEGrenadeProjectile::Create(
    position: &vecSrc,
    angles: &vecAngles,
    velocity: &vecVel,
    angVelocity: &angImpulse,
    pOwner: v6,
    timer: 3.0);
}

//------------------------------------------------------------------------------
// Address: 0x102ED480
// Name: public: virtual enum CSWeaponID CHEGrenade::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHEGrenade::GetCSWeaponID(CHEGrenade *this)
{
  return 33;
}

//------------------------------------------------------------------------------
// Address: 0x10412830
// Name: DT_HEGrenade::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_HEGrenade::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_HEGrenade::g_SendTable);
  return atexit(func: DT_HEGrenade::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412850
// Name: DT_HEGrenade::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_HEGrenade::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_HEGrenade::ignored>();
  DT_HEGrenade::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412880
// Name: weapon_hegrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_hegrenadePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_hegrenadePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_hegrenadePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104128A0
// Name: CHEGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CHEGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CHEGrenade>(__formal: nullptr);
  CHEGrenade_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420B10
// Name: DT_HEGrenade::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_HEGrenade::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_HEGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102ED490
// Name: struct datamap_t __near * DataMapInit<class CHEGrenade>(class CHEGrenade __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CHEGrenade>()
{
  if ( (_S3_160 & 1) == 0 )
  {
    _S3_160 |= 1u;
    nameHolder_497.m_pszBase = "CHEGrenade";
    nameHolder_497.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_497.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_497.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_497.m_Names.m_Size = 0;
    nameHolder_497.m_Names.m_pElements = nullptr;
    nameHolder_497.m_nLenBase = 10;
    atexit(func: DataMapInit_CHEGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CHEGrenade::m_DataMap.baseMap = &CBaseCSGrenade::m_DataMap;
  CHEGrenade::m_DataMap.dataNumFields = 1;
  CHEGrenade::m_DataMap.dataDesc = dataDesc_512;
  return &CHEGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104128B0
// Name: _dynamic_initializer_for__g_CWeaponHKP2000_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponHKP2000_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponHKP2000_ClassReg,
           pNetworkName: "CWeaponHKP2000",
           pTable: &DT_WeaponHKP2000::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420B20
// Name: _ServerClassInit_DT_HEGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_HEGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_283;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420B40
// Name: _DataMapInit_CHEGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CHEGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_497);
}

} // namespace server
