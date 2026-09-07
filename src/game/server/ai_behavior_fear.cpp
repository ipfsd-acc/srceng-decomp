// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_behavior_fear.cpp
// Functions: 4
// ============================================================

#include "game\server\ai_behavior_fear.h"

//------------------------------------------------------------------------------
// Address: 0x103FB5D0
// Name: CAI_FearBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_FearBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_FearBehavior>();
  CAI_FearBehavior_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB5E0
// Name: _dynamic_initializer_for__ai_enable_fear_behavior__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_enable_fear_behavior__()
{
  ConVar::ConVar(this: &ai_enable_fear_behavior, pName: "ai_enable_fear_behavior", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_enable_fear_behavior__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB610
// Name: _dynamic_initializer_for__ai_fear_player_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_fear_player_dist__()
{
  ConVar::ConVar(this: &ai_fear_player_dist, pName: "ai_fear_player_dist", pDefaultValue: "720", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_fear_player_dist__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB640
// Name: _dynamic_initializer_for__CAI_FearBehavior::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_FearBehavior::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_FearBehavior::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_FearBehavior::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(
           this: &CAI_FearBehavior::gm_ClassScheduleIdSpace.m_ConditionIds,
           fIsRoot: false);
}
