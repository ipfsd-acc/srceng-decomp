// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_decoy.cpp
// Functions: 13
// ============================================================

#include "game\shared\cstrike15\weapon_decoy.h"

//------------------------------------------------------------------------------
// Address: 0x1022DC40
// Name: public: virtual class ClientClass __near * C_DecoyGrenade::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_DecoyGrenade::GetClientClass(C_DecoyGrenade *this)
{
  return &__g_C_DecoyGrenadeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022DCC0
// Name: public: virtual struct datamap_t __near * C_DecoyGrenade::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_DecoyGrenade::GetPredDescMap(C_DecoyGrenade *this)
{
  return &C_DecoyGrenade::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022DCD0
// Name: public: virtual void weapon_decoyPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_decoyPrecache::CResourcePrecacher::Cache(
        weapon_decoyPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_decoy",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022DD00
// Name: public: virtual enum CSWeaponID C_DecoyGrenade::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_DecoyGrenade::GetCSWeaponID(C_DecoyGrenade *this)
{
  return 36;
}

//------------------------------------------------------------------------------
// Address: 0x1022DD80
// Name: CC_DecoyGrenadeFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_DecoyGrenadeFactory()
{
  C_BaseCSGrenade *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v0);
  *v1 = &C_DecoyGrenade::`vftable'{for `IClientUnknown'};
  v1[1] = &C_DecoyGrenade::`vftable'{for `IClientRenderable'};
  v1[2] = &C_DecoyGrenade::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_DecoyGrenade::`vftable'{for `IClientThinkable'};
  v1[4] = &C_DecoyGrenade::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10428630
// Name: DT_DecoyGrenade::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DecoyGrenade::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_DecoyGrenade::g_RecvTable);
  return atexit(func: DT_DecoyGrenade::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428650
// Name: DT_DecoyGrenade::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DecoyGrenade::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_DecoyGrenade::ignored>();
  DT_DecoyGrenade::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428660
// Name: C_DecoyGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_DecoyGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_DecoyGrenade::m_PredMap.dataNumFields = 1;
  C_DecoyGrenade::m_PredMap.dataDesc = (typedescription_t *)&unk_1066AFCC;
}

//------------------------------------------------------------------------------
// Address: 0x104286B0
// Name: weapon_decoyPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_decoyPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_decoyPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_decoyPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436030
// Name: DT_DecoyGrenade::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DecoyGrenade::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_DecoyGrenade::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022DD10
// Name: _C_DecoyGrenade_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_DecoyGrenade_CreateObject(int entnum, int serialNum)
{
  C_BaseCSGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseCSGrenade::C_BaseCSGrenade(this: v2);
  *v3 = &C_DecoyGrenade::`vftable'{for `IClientUnknown'};
  v3[1] = &C_DecoyGrenade::`vftable'{for `IClientRenderable'};
  v3[2] = &C_DecoyGrenade::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_DecoyGrenade::`vftable'{for `IClientThinkable'};
  v3[4] = &C_DecoyGrenade::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10428680
// Name: _dynamic_initializer_for__g_Cweapon_decoyFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_decoyFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_decoy",
             a3: "C_DecoyGrenade",
             a4: 3520,
             a5: CC_DecoyGrenadeFactory);
  __g_C_DecoyGrenadeClientClass.m_pMapClassname = "weapon_decoy";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104286D0
// Name: _dynamic_initializer_for____g_C_WeaponEliteClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponEliteClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponEliteClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponEliteClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EAF60
// Name: public: virtual class ServerClass __near * CDecoyGrenade::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CDecoyGrenade::GetServerClass(CDecoyGrenade *this)
{
  return &g_CDecoyGrenade_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EAF70
// Name: public: virtual void weapon_decoyPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_decoyPrecache::CResourcePrecacher::Cache(
        weapon_decoyPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_decoy",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EAFA0
// Name: public: virtual struct datamap_t __near * CDecoyGrenade::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CDecoyGrenade::GetDataDescMap(CDecoyGrenade *this)
{
  return &CDecoyGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102EAFB0
// Name: public: virtual void CDecoyGrenade::EmitGrenade(class Vector,class QAngle,class Vector,class Vector,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecoyGrenade::EmitGrenade(
        CDecoyGrenade *this,
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
  CDecoyProjectile::Create(
    position: &vecSrc,
    angles: &vecAngles,
    velocity: &vecVel,
    angVelocity: &angImpulse,
    pOwner: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102EB090
// Name: public: virtual enum CSWeaponID CDecoyGrenade::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDecoyGrenade::GetCSWeaponID(CDecoyGrenade *this)
{
  return 36;
}

//------------------------------------------------------------------------------
// Address: 0x1040F580
// Name: _dynamic_initializer_for__decoy_projectile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__decoy_projectile__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CDecoyProjectile> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &decoy_projectile,
           a3: "decoy_projectile");
}

//------------------------------------------------------------------------------
// Address: 0x10412390
// Name: DT_DecoyGrenade::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DecoyGrenade::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_DecoyGrenade::g_SendTable);
  return atexit(func: DT_DecoyGrenade::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104123B0
// Name: DT_DecoyGrenade::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DecoyGrenade::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_DecoyGrenade::ignored>();
  DT_DecoyGrenade::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104123E0
// Name: weapon_decoyPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_decoyPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_decoyPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_decoyPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412400
// Name: CDecoyGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CDecoyGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CDecoyGrenade>(__formal: nullptr);
  CDecoyGrenade_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420970
// Name: DT_DecoyGrenade::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DecoyGrenade::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_DecoyGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102EB0A0
// Name: struct datamap_t __near * DataMapInit<class CDecoyGrenade>(class CDecoyGrenade __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CDecoyGrenade>()
{
  if ( (_S3_158 & 1) == 0 )
  {
    _S3_158 |= 1u;
    nameHolder_495.m_pszBase = "CDecoyGrenade";
    nameHolder_495.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_495.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_495.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_495.m_Names.m_Size = 0;
    nameHolder_495.m_Names.m_pElements = nullptr;
    nameHolder_495.m_nLenBase = 13;
    atexit(func: DataMapInit_CDecoyGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CDecoyGrenade::m_DataMap.baseMap = &CBaseCSGrenade::m_DataMap;
  CDecoyGrenade::m_DataMap.dataNumFields = 1;
  CDecoyGrenade::m_DataMap.dataDesc = dataDesc_510;
  return &CDecoyGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10412410
// Name: _dynamic_initializer_for__g_CWeaponElite_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponElite_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponElite_ClassReg,
           pNetworkName: "CWeaponElite",
           pTable: &DT_WeaponElite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420980
// Name: _ServerClassInit_DT_DecoyGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_DecoyGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_275;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104209A0
// Name: _DataMapInit_CDecoyGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CDecoyGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_495);
}

} // namespace server
