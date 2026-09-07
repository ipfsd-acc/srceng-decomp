// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/logicauto.cpp
// Functions: 29
// ============================================================

#include "game\server\logicauto.h"

//------------------------------------------------------------------------------
// Address: 0x101677B0
// Name: public: virtual struct datamap_t __near * CLogicAuto::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicAuto::GetDataDescMap(CLogicAuto *this)
{
  return &CLogicAuto::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101677C0
// Name: public: virtual void CLogicAuto::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicAuto::Activate(CLogicAuto *this)
{
  CBaseEntity::Activate(this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10167800
// Name: public: virtual void CLogicAuto::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicAuto::Think(CLogicAuto *this)
{
  int Index; // eax
  MapLoadType_t eLoadType; // eax
  COutputEvent *p_m_OnMapTransition; // ecx
  bool v5; // al
  COutputEvent *p_m_OnMultiNewRound; // ecx

  if ( this->m_globalstate.pszValue != nullptr )
  {
    Index = GlobalEntity_GetIndex(pGlobalname: this->m_globalstate.pszValue);
    if ( GlobalEntity_GetState(globalIndex: Index) != GLOBAL_ON )
      return;
  }
  eLoadType = gpGlobals->eLoadType;
  switch ( eLoadType )
  {
    case MapLoad_Transition:
      p_m_OnMapTransition = &this->m_OnMapTransition;
LABEL_11:
      COutputEvent::FireOutput(this: p_m_OnMapTransition, pActivator: nullptr, pCaller: this, fDelay: 0.0);
      break;
    case MapLoad_NewGame:
      p_m_OnMapTransition = &this->m_OnNewGame;
      goto LABEL_11;
    case MapLoad_LoadGame:
      p_m_OnMapTransition = &this->m_OnLoadGame;
      goto LABEL_11;
    case MapLoad_Background:
      p_m_OnMapTransition = &this->m_OnBackgroundMap;
      goto LABEL_11;
    default:
      break;
  }
  COutputEvent::FireOutput(this: &this->m_OnMapSpawn, pActivator: nullptr, pCaller: this, fDelay: 0.0);
  if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    v5 = g_pGameRules->InRoundRestart(this: g_pGameRules);
    p_m_OnMultiNewRound = &this->m_OnMultiNewRound;
    if ( !v5 )
      p_m_OnMultiNewRound = &this->m_OnMultiNewMap;
    COutputEvent::FireOutput(this: p_m_OnMultiNewRound, pActivator: nullptr, pCaller: this, fDelay: 0.0);
  }
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10167900
// Name: public: CLogicAuto::CLogicAuto(void)
// Source: json
//------------------------------------------------------------------------------
CLogicAuto *__thiscall CLogicAuto::CLogicAuto(CLogicAuto *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CLogicAuto_vtbl *)&CLogicAuto::`vftable';
  this->m_OnMapSpawn.m_Value.iVal = 0;
  this->m_OnMapSpawn.m_Value.eVal.m_Index = -1;
  this->m_OnMapSpawn.m_Value.fieldType = FIELD_VOID;
  this->m_OnNewGame.m_Value.iVal = 0;
  this->m_OnNewGame.m_Value.eVal.m_Index = -1;
  this->m_OnNewGame.m_Value.fieldType = FIELD_VOID;
  this->m_OnLoadGame.m_Value.iVal = 0;
  this->m_OnLoadGame.m_Value.eVal.m_Index = -1;
  this->m_OnLoadGame.m_Value.fieldType = FIELD_VOID;
  this->m_OnMapTransition.m_Value.iVal = 0;
  this->m_OnMapTransition.m_Value.eVal.m_Index = -1;
  this->m_OnMapTransition.m_Value.fieldType = FIELD_VOID;
  this->m_OnBackgroundMap.m_Value.iVal = 0;
  this->m_OnBackgroundMap.m_Value.eVal.m_Index = -1;
  this->m_OnBackgroundMap.m_Value.fieldType = FIELD_VOID;
  this->m_OnMultiNewMap.m_Value.iVal = 0;
  this->m_OnMultiNewMap.m_Value.eVal.m_Index = -1;
  this->m_OnMultiNewMap.m_Value.fieldType = FIELD_VOID;
  this->m_OnMultiNewRound.m_Value.iVal = 0;
  this->m_OnMultiNewRound.m_Value.eVal.m_Index = -1;
  this->m_OnMultiNewRound.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104056B0
// Name: _dynamic_initializer_for__logic_eventlistener__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_eventlistener__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicEventListener> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_eventlistener,
           a3: "logic_eventlistener");
}

//------------------------------------------------------------------------------
// Address: 0x104056E0
// Name: _dynamic_initializer_for__logic_measure_movement__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_measure_movement__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicMeasureMovement> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_measure_movement,
           a3: "logic_measure_movement");
}

//------------------------------------------------------------------------------
// Address: 0x10405710
// Name: _dynamic_initializer_for__logic_navigation__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_navigation__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicNavigation> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_navigation,
           a3: "logic_navigation");
}

//------------------------------------------------------------------------------
// Address: 0x10405740
// Name: _dynamic_initializer_for__logic_playerproxy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_playerproxy__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicPlayerProxy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_playerproxy,
           a3: "logic_playerproxy");
}

//------------------------------------------------------------------------------
// Address: 0x10405770
// Name: _dynamic_initializer_for__logic_playmovie__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_playmovie__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicPlayMovie> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_playmovie,
           a3: "logic_playmovie");
}

//------------------------------------------------------------------------------
// Address: 0x104057A0
// Name: _dynamic_initializer_for__logic_random_outputs__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_random_outputs__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicRandomOutputs> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_random_outputs,
           a3: "logic_random_outputs");
}

//------------------------------------------------------------------------------
// Address: 0x104057D0
// Name: _dynamic_initializer_for__logic_auto__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_auto__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicAuto> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_auto,
           a3: "logic_auto");
}

//------------------------------------------------------------------------------
// Address: 0x104057F0
// Name: CLogicAuto_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicAuto_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicAuto>();
  CLogicAuto_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405820
// Name: _dynamic_initializer_for__logic_script__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_script__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicScript> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_script,
           a3: "logic_script");
}

//------------------------------------------------------------------------------
// Address: 0x10405850
// Name: _dynamic_initializer_for__logic_multicompare__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_multicompare__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicCompareInteger> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_multicompare,
           a3: "logic_multicompare");
}

//------------------------------------------------------------------------------
// Address: 0x10405880
// Name: _dynamic_initializer_for__logic_register_activator__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_register_activator__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicRegisterActivator> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_register_activator,
           a3: "logic_register_activator");
}

//------------------------------------------------------------------------------
// Address: 0x104058B0
// Name: _dynamic_initializer_for__logic_timer__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_timer__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTimerEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_timer,
           a3: "logic_timer");
}

//------------------------------------------------------------------------------
// Address: 0x104058E0
// Name: _dynamic_initializer_for__logic_lineto__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_lineto__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicLineToEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_lineto,
           a3: "logic_lineto");
}

//------------------------------------------------------------------------------
// Address: 0x10405A30
// Name: _dynamic_initializer_for__logic_case__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_case__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicCase> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_case,
           a3: "logic_case");
}

//------------------------------------------------------------------------------
// Address: 0x10405A60
// Name: _dynamic_initializer_for__logic_compare__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_compare__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicCompare> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_compare,
           a3: "logic_compare");
}

//------------------------------------------------------------------------------
// Address: 0x10405A90
// Name: _dynamic_initializer_for__logic_branch__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_branch__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicBranch> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_branch,
           a3: "logic_branch");
}

//------------------------------------------------------------------------------
// Address: 0x10405AC0
// Name: _dynamic_initializer_for__logic_autosave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_autosave__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicAutosave> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_autosave,
           a3: "logic_autosave");
}

//------------------------------------------------------------------------------
// Address: 0x10405AF0
// Name: _dynamic_initializer_for__logic_active_autosave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_active_autosave__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicActiveAutosave> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_active_autosave,
           a3: "logic_active_autosave");
}

//------------------------------------------------------------------------------
// Address: 0x10405B30
// Name: _dynamic_initializer_for__logic_collision_pair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_collision_pair__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicCollisionPair> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_collision_pair,
           a3: "logic_collision_pair");
}

//------------------------------------------------------------------------------
// Address: 0x10405B50
// Name: _dynamic_initializer_for__logic_branch_listener__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_branch_listener__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicBranchList> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_branch_listener,
           a3: "logic_branch_listener");
}

//------------------------------------------------------------------------------
// Address: 0x10405B80
// Name: _dynamic_initializer_for__logic_relay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_relay__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLogicRelay> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_relay,
           a3: "logic_relay");
}

//------------------------------------------------------------------------------
// Address: 0x104097B0
// Name: _dynamic_initializer_for__logic_choreographed_scene__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_choreographed_scene__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSceneEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_choreographed_scene,
           a3: "logic_choreographed_scene");
}

//------------------------------------------------------------------------------
// Address: 0x10409990
// Name: _dynamic_initializer_for__logic_scene_list_manager__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_scene_list_manager__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSceneListManager> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_scene_list_manager,
           a3: "logic_scene_list_manager");
}

//------------------------------------------------------------------------------
// Address: 0x1040BEA0
// Name: _dynamic_initializer_for__logic_proximity__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__logic_proximity__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &logic_proximity,
           a3: "logic_proximity");
}

//------------------------------------------------------------------------------
// Address: 0x10405800
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___2()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_2,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_2,
           pName: "ServerGameTags001");
}
