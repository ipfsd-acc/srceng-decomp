// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/entityfreezing.cpp
// Functions: 57
// ============================================================

#include "game\server\entityfreezing.h"

//------------------------------------------------------------------------------
// Address: 0x1010D0E0
// Name: public: virtual struct datamap_t __near * CEntityFreezing::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEntityFreezing::GetDataDescMap(CEntityFreezing *this)
{
  return &CEntityFreezing::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010D0F0
// Name: public: virtual class ServerClass __near * CEntityFreezing::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEntityFreezing::GetServerClass(CEntityFreezing *this)
{
  return &g_CEntityFreezing_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1010D100
// Name: public: virtual void env_entity_freezingPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall env_entity_freezingPrecache::CResourcePrecacher::Cache(
        env_entity_freezingPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "env_entity_freezing",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1010D180
// Name: public: virtual void CEntityFreezing::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFreezing::Spawn(CEntityFreezing *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->Precache(this);
  v2 = *(const char **)((int (__thiscall *)(CEntityFreezing *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  UTIL_SetModel(pEntity: this, pModelName: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1010D1C0
// Name: protected: void CEntityFreezing::InputFreeze(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFreezing::InputFreeze(CEntityFreezing *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax
  const char *iVal; // ebx
  CBaseEntity *EntityGeneric; // esi
  const char *v6; // eax
  int v7; // eax
  int v8; // [esp+18h] [ebp-4h] BYREF

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    v8 = 0;
    p_value = (variant_t *)&v8;
  }
  iVal = (const char *)p_value->iVal;
  if ( p_value->iVal == 0 )
    iVal = this->m_target.pszValue;
  EntityGeneric = nullptr;
  while ( 1 )
  {
    v6 = iVal;
    if ( iVal == nullptr )
      v6 = locale;
    EntityGeneric = CGlobalEntityList::FindEntityGeneric(
                      this: &gEntList,
                      pStartEntity: EntityGeneric,
                      szName: v6,
                      pSearchingEntity: this,
                      pActivator: inputdata->pActivator,
                      pCaller: nullptr);
    if ( EntityGeneric == nullptr )
      break;
    v7 = (int)EntityGeneric->GetBaseAnimating(this: EntityGeneric);
    if ( v7 != 0 )
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 896))(
        a1: v7,
        a2: LODWORD(this->m_flFrozen.m_Value),
        a3: 0,
        a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FEF60
// Name: _dynamic_initializer_for__free_pass_peek_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__free_pass_peek_debug__()
{
  ConVar::ConVar(this: &free_pass_peek_debug, pName: "free_pass_peek_debug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__free_pass_peek_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10402200
// Name: CEntityFreezing_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEntityFreezing_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEntityFreezing>();
  CEntityFreezing_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402230
// Name: DT_EntityFreezing::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityFreezing::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EntityFreezing::g_SendTable);
  return atexit(func: DT_EntityFreezing::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10402250
// Name: DT_EntityFreezing::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityFreezing::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EntityFreezing::ignored>();
  DT_EntityFreezing::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402280
// Name: env_entity_freezingPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int env_entity_freezingPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  env_entity_freezingPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&env_entity_freezingPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419530
// Name: _dynamic_atexit_destructor_for__free_pass_peek_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__free_pass_peek_debug__()
{
  ConVar::~ConVar(this: &free_pass_peek_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1041AB60
// Name: DT_EntityFreezing::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityFreezing::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EntityFreezing::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402210
// Name: _dynamic_initializer_for__g_CEntityFreezing_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEntityFreezing_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEntityFreezing_ClassReg,
           pNetworkName: "CEntityFreezing",
           pTable: &DT_EntityFreezing::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402260
// Name: _dynamic_initializer_for__env_entity_freezing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_entity_freezing__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEntityFreezing> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_entity_freezing,
           a3: "env_entity_freezing");
}

//------------------------------------------------------------------------------
// Address: 0x104022A0
// Name: _dynamic_initializer_for__g_DeleteList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DeleteList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DeleteList__);
}

//------------------------------------------------------------------------------
// Address: 0x104022B0
// Name: _dynamic_initializer_for__gEntList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gEntList__()
{
  CBaseEntityList::CBaseEntityList(this: &gEntList);
  gEntList.__vftable = (CGlobalEntityList_vtbl *)&CGlobalEntityList::`vftable';
  gEntList.m_entityListeners.m_Memory.m_pMemory = nullptr;
  gEntList.m_entityListeners.m_Memory.m_nAllocationCount = 0;
  gEntList.m_entityListeners.m_Memory.m_nGrowSize = 0;
  gEntList.m_entityListeners.m_Size = 0;
  gEntList.m_entityListeners.m_pElements = nullptr;
  gEntList.m_iNumEdicts = 0;
  gEntList.m_iNumEnts = 0;
  gEntList.m_iHighestEnt = 0;
  gEntList.m_bClearingEntities = false;
  return atexit(func: dynamic_atexit_destructor_for__gEntList__);
}

//------------------------------------------------------------------------------
// Address: 0x10402300
// Name: _dynamic_initializer_for__g_AimManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AimManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AimManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10402310
// Name: _dynamic_initializer_for__g_SimThinkManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SimThinkManager__()
{
  CSimThinkManager::Clear(this: &g_SimThinkManager);
  return atexit(func: dynamic_atexit_destructor_for__g_SimThinkManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10402330
// Name: _dynamic_initializer_for__g_PostClientManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PostClientManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PostClientManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10402340
// Name: _dynamic_initializer_for__g_EntsByClassname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__g_EntsByClassname__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CEntsByStringHashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
    this: &g_EntsByClassname,
    bucketCount: 512,
    growCount: 0,
    initCount: 0,
    compareFunc: (CEntsByStringHashFuncs)a1,
    keyFunc: v3);
  return atexit(func: dynamic_atexit_destructor_for__g_EntsByClassname__);
}

//------------------------------------------------------------------------------
// Address: 0x10402370
// Name: _dynamic_initializer_for__g_NotifyList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NotifyList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_NotifyList__);
}

//------------------------------------------------------------------------------
// Address: 0x10402380
// Name: _dynamic_initializer_for__g_TouchManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TouchManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_TouchManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10402390
// Name: _dynamic_initializer_for__g_EntityListSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EntityListSystem__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_EntityListSystem, name: "CEntityListSystem");
  g_EntityListSystem.__vftable = (CEntityListSystem_vtbl *)&CEntityListSystem::`vftable';
  g_EntityListSystem.m_bRespawnAllEntities = false;
  return atexit(func: dynamic_atexit_destructor_for__g_EntityListSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x104023C0
// Name: _dynamic_initializer_for__restart_entities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__restart_entities__()
{
  ConCommand::ConCommand(
    this: &restart_entities,
    pName: "respawn_entities",
    callback: RespawnEntities,
    pHelpString: "Respawn all the entities in the map.",
    flags: 16448,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__restart_entities__);
}

//------------------------------------------------------------------------------
// Address: 0x104023F0
// Name: _dynamic_initializer_for__report_entities_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__report_entities_command__()
{
  ConCommand::ConCommand(
    this: &report_entities_command,
    pName: "report_entities",
    callback: (void (__cdecl *)())report_entities,
    pHelpString: "Lists all entities",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__report_entities_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10402420
// Name: _dynamic_initializer_for__report_touchlinks_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__report_touchlinks_command__()
{
  ConCommand::ConCommand(
    this: &report_touchlinks_command,
    pName: "report_touchlinks",
    callback: (void (__cdecl *)())report_touchlinks,
    pHelpString: "Lists all touchlinks",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__report_touchlinks_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10402450
// Name: _dynamic_initializer_for__report_simthinklist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__report_simthinklist_command__()
{
  ConCommand::ConCommand(
    this: &report_simthinklist_command,
    pName: "report_simthinklist",
    callback: (void (__cdecl *)())report_simthinklist,
    pHelpString: "Lists all simulating/thinking entities",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__report_simthinklist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10419540
// Name: _DataMapInit_CAI_MoveMonitor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_MoveMonitor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_74);
}

//------------------------------------------------------------------------------
// Address: 0x10419550
// Name: _DataMapInit_CAI_ShotRegulator__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_ShotRegulator__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_75);
}

//------------------------------------------------------------------------------
// Address: 0x10419560
// Name: _DataMapInit_CAI_AccelDecay__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_AccelDecay__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_76);
}

//------------------------------------------------------------------------------
// Address: 0x10419570
// Name: _DataMapInit_AI_FreePassParams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AI_FreePassParams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_77);
}

//------------------------------------------------------------------------------
// Address: 0x10419580
// Name: _DataMapInit_CAI_FreePass__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_FreePass__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_78);
}

//------------------------------------------------------------------------------
// Address: 0x10419590
// Name: _dynamic_atexit_destructor_for__AI_Waypoint_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__AI_Waypoint_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &AI_Waypoint_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x104195A0
// Name: _DataMapInit_AI_Waypoint_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AI_Waypoint_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_79);
}

//------------------------------------------------------------------------------
// Address: 0x104195B0
// Name: _DataMapInit_CAmbientGeneric__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAmbientGeneric__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_80);
}

//------------------------------------------------------------------------------
// Address: 0x104195C0
// Name: _SelectWeightedSequence_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl SelectWeightedSequence_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x104195D0
// Name: _dynamic_atexit_destructor_for__sv_showanimstate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_showanimstate__()
{
  ConVar::~ConVar(this: &sv_showanimstate);
}

//------------------------------------------------------------------------------
// Address: 0x104195E0
// Name: _dynamic_atexit_destructor_for__showanimstate_log__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showanimstate_log__()
{
  ConVar::~ConVar(this: &showanimstate_log);
}

//------------------------------------------------------------------------------
// Address: 0x104195F0
// Name: _dynamic_atexit_destructor_for__showanimstate_activities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showanimstate_activities__()
{
  ConVar::~ConVar(this: &showanimstate_activities);
}

//------------------------------------------------------------------------------
// Address: 0x10419600
// Name: _dynamic_atexit_destructor_for__mp_feetyawrate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_feetyawrate__()
{
  ConVar::~ConVar(this: &mp_feetyawrate);
}

//------------------------------------------------------------------------------
// Address: 0x10419610
// Name: _dynamic_atexit_destructor_for__mp_facefronttime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_facefronttime__()
{
  ConVar::~ConVar(this: &mp_facefronttime);
}

//------------------------------------------------------------------------------
// Address: 0x10419620
// Name: _dynamic_atexit_destructor_for__mp_ik__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ik__()
{
  ConVar::~ConVar(this: &mp_ik);
}

//------------------------------------------------------------------------------
// Address: 0x1041AB70
// Name: _ServerClassInit_DT_EntityFreezing::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EntityFreezing::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_44;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AB90
// Name: _DataMapInit_CEntityFreezing__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEntityFreezing__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_154);
}

//------------------------------------------------------------------------------
// Address: 0x1041ABA0
// Name: _dynamic_atexit_destructor_for__restart_entities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__restart_entities__()
{
  ConCommand::~ConCommand(this: &restart_entities);
}

//------------------------------------------------------------------------------
// Address: 0x1041ABB0
// Name: _dynamic_atexit_destructor_for__report_entities_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__report_entities_command__()
{
  ConCommand::~ConCommand(this: &report_entities_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041ABC0
// Name: _dynamic_atexit_destructor_for__report_touchlinks_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__report_touchlinks_command__()
{
  ConCommand::~ConCommand(this: &report_touchlinks_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041ABD0
// Name: _dynamic_atexit_destructor_for__report_simthinklist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__report_simthinklist_command__()
{
  ConCommand::~ConCommand(this: &report_simthinklist_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041ABE0
// Name: _dynamic_atexit_destructor_for__g_EntityListSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntityListSystem__()
{
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_EntityListSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041ABF0
// Name: _dynamic_atexit_destructor_for__g_DeleteList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DeleteList__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_DeleteList);
}

//------------------------------------------------------------------------------
// Address: 0x1041AC00
// Name: _dynamic_atexit_destructor_for__gEntList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gEntList__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&gEntList.m_entityListeners);
  CBaseEntityList::~CBaseEntityList(this: &gEntList);
}

//------------------------------------------------------------------------------
// Address: 0x1041AC20
// Name: _dynamic_atexit_destructor_for__g_AimManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AimManager__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_AimManager.m_targetList);
}

//------------------------------------------------------------------------------
// Address: 0x1041AC30
// Name: _dynamic_atexit_destructor_for__g_TouchManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TouchManager__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_TouchManager.m_updateList);
}

//------------------------------------------------------------------------------
// Address: 0x1041AC40
// Name: _dynamic_atexit_destructor_for__g_SimThinkManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SimThinkManager__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_SimThinkManager.m_simThinkList);
}

//------------------------------------------------------------------------------
// Address: 0x1041AC50
// Name: _dynamic_atexit_destructor_for__g_PostClientManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PostClientManager__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PostClientManager);
}

//------------------------------------------------------------------------------
// Address: 0x1041AC60
// Name: _dynamic_atexit_destructor_for__g_NotifyList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_NotifyList__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_NotifyList.m_notifyList);
}

//------------------------------------------------------------------------------
// Address: 0x1041AC70
// Name: _dynamic_atexit_destructor_for__g_EntsByClassname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntsByClassname__()
{
  CUtlHash<CEntityDataInstantiator<physicspushlist_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &,CEntityDataInstantiator<physicspushlist_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &)>::Purge(this: &g_EntsByClassname);
  CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&g_EntsByClassname);
}
