// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/item_defuser.cpp
// Functions: 10
// ============================================================

#include "game\server\cstrike15\item_defuser.h"

//------------------------------------------------------------------------------
// Address: 0x102A40F0
// Name: public: virtual void item_defuserPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall item_defuserPrecache::CResourcePrecacher::Cache(
        item_defuserPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "item_defuser",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102A4120
// Name: public: virtual struct datamap_t __near * CItemDefuser::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CItemDefuser::GetDataDescMap(CItemDefuser *this)
{
  return &CItemDefuser::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102A4130
// Name: public: virtual void CItemDefuser::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CItemDefuser::Precache(CItemDefuser *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/weapons/w_defuser.mdl", bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "BaseCombatCharacter.ItemPickup2");
}

//------------------------------------------------------------------------------
// Address: 0x102A41D0
// Name: public: void CItemDefuser::DefuserTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItemDefuser::DefuserTouch(CItemDefuser *this, CCSPlayer *pOther)
{
  IGameEvent *v3; // esi
  edict_t *v4; // eax
  CPASAttenuationFilter filter; // [esp+2Ch] [ebp-20h] BYREF

  if ( pOther->IsPlayer(this: pOther)
    && CBaseEntity::GetTeamNumber(this: pOther) == 3
    && !CCSPlayer::HasDefuser(this: pOther) )
  {
    CCSPlayer::GiveDefuser(this: pOther, bPickedUp: true);
    if ( mp_defuser_allocation.m_pParent != nullptr && mp_defuser_allocation.m_pParent->m_Value.m_nValue == 1 )
    {
      v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "defuser_pickup", a3: 0, a4: 0);
      if ( v3 != nullptr )
      {
        v3->SetInt(this: v3, a2: "priority", a3: 6);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
      }
    }
    if ( !CBasePlayer::IsDead(this: pOther) )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: pOther, attenuation: 0.80000001);
      v4 = CBaseEntity::entindex(this);
      CBaseEntity::EmitSound(
        &filter,
        iEntIndex: (int)v4,
        soundname: "BaseCombatCharacter.ItemPickup2",
        pOrigin: nullptr,
        soundtime: 0.0,
        duration: nullptr);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4320
// Name: public: void CItemDefuser::ActivateThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItemDefuser::ActivateThink(CItemDefuser *this)
{
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CItemDefuser::DefuserTouch;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102A4340
// Name: public: virtual void CItemDefuser::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CItemDefuser::Spawn(CItemDefuser *this@<ecx>, int a2@<ebp>)
{
  IGameEvent *v3; // edi

  this->Precache(this);
  this->SetModel(this, a2: "models/weapons/w_defuser.mdl");
  CItem::Spawn(this);
  if ( mp_defuser_allocation.m_pParent != nullptr && mp_defuser_allocation.m_pParent->m_Value.m_nValue == 1 )
  {
    v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "defuser_dropped", a3: 0, a4: 0);
    if ( v3 != nullptr )
    {
      v3->SetInt(this: v3, a2: "priority", a3: 6);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
    }
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  g_vecDefuserPosition = this->m_vecAbsOrigin;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CItemDefuser::ActivateThink,
    thinkTime: 0.0,
    szContext: nullptr);
  this->m_pfnTouch = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104103B0
// Name: item_defuserPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int item_defuserPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  item_defuserPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&item_defuserPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104103D0
// Name: CItemDefuser_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CItemDefuser_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CItemDefuser>(__formal: nullptr);
  CItemDefuser_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A4440
// Name: struct datamap_t __near * DataMapInit<class CItemDefuser>(class CItemDefuser __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CItemDefuser>()
{
  if ( (_S2_254 & 1) == 0 )
  {
    _S2_254 |= 1u;
    nameHolder_483.m_pszBase = "CItemDefuser";
    nameHolder_483.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_483.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_483.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_483.m_Names.m_Size = 0;
    nameHolder_483.m_Names.m_pElements = nullptr;
    nameHolder_483.m_nLenBase = 12;
    atexit(func: DataMapInit_CItemDefuser__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CItemDefuser::m_DataMap.baseMap = &CItem::m_DataMap;
  if ( (_S2_254 & 2) == 0 )
  {
    _S2_254 |= 2u;
    dataDesc_503[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_483,
                                  pszIdentifier: "ActivateThink");
    dataDesc_503[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_503[1].fieldSize = 2097153;
    dataDesc_503[1].externalName = nullptr;
    dataDesc_503[1].pSaveRestoreOps = nullptr;
    dataDesc_503[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CItemDefuser::ActivateThink;
    *(_QWORD *)&dataDesc_503[1].td = 0;
    *(_QWORD *)&dataDesc_503[1].override_field = 0;
    *(_QWORD *)&dataDesc_503[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_503[1].flatOffset[1] = 0;
    dataDesc_503[2].fieldType = FIELD_VOID;
    dataDesc_503[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_483,
                                  pszIdentifier: "DefuserTouch");
    dataDesc_503[2].fieldOffset = 0;
    *(_DWORD *)&dataDesc_503[2].fieldSize = 2097153;
    dataDesc_503[2].externalName = nullptr;
    dataDesc_503[2].pSaveRestoreOps = nullptr;
    dataDesc_503[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CItemDefuser::DefuserTouch;
    *(_QWORD *)&dataDesc_503[2].td = 0;
    *(_QWORD *)&dataDesc_503[2].override_field = 0;
    *(_QWORD *)&dataDesc_503[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_503[2].flatOffset[1] = 0;
  }
  CItemDefuser::m_DataMap.dataNumFields = 2;
  CItemDefuser::m_DataMap.dataDesc = &dataDesc_503[1];
  return &CItemDefuser::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104103E0
// Name: _dynamic_initializer_for__g_vecDefuserPosition__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_vecDefuserPosition__()
{
  g_vecDefuserPosition = vec3_origin;
  return LODWORD(vec3_origin.z);
}
