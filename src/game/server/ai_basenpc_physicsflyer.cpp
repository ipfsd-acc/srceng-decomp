// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_basenpc_physicsflyer.cpp
// Functions: 3
// ============================================================

#include "game\server\ai_basenpc_physicsflyer.h"

//------------------------------------------------------------------------------
// Address: 0x103FB2D0
// Name: CAI_BasePhysicsFlyingBot_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_BasePhysicsFlyingBot_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_BasePhysicsFlyingBot>();
  CAI_BasePhysicsFlyingBot_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB2E0
// Name: _dynamic_initializer_for__ai_simulate_task_overtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_simulate_task_overtime__()
{
  ConVar::ConVar(this: &ai_simulate_task_overtime, pName: "ai_simulate_task_overtime", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_simulate_task_overtime__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB310
// Name: _dynamic_initializer_for__g_AITaskTimings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_AITaskTimings__()
{
  g_AITaskTimings[0].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[0].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[0].runTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[1].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[1].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[1].runTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[2].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[2].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[2].runTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[3].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[3].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[3].runTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[4].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[4].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[4].runTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[5].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[5].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[5].runTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[6].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[6].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[6].runTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[7].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[7].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[7].runTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[8].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[8].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[8].runTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[9].selectSchedule.m_Duration.m_Int64 = 0;
  g_AITaskTimings[9].startTimer.m_Duration.m_Int64 = 0;
  g_AITaskTimings[9].runTimer.m_Duration.m_Int64 = 0;
}
