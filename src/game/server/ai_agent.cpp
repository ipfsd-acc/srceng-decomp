// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_agent.cpp
// Functions: 11
// ============================================================

#include "game\server\ai_agent.h"

//------------------------------------------------------------------------------
// Address: 0x10011870
// Name: public: virtual void CAI_Agent::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Agent::Think(CAI_Agent *this)
{
  this->RunAI(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011880
// Name: private: static void CAI_Agent::InitDefaultTaskSR(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_Agent::InitDefaultTaskSR()
{
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_Agent::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_INVALID",
    localId: 0,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_Agent");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_Agent::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SET_SCHEDULE",
    localId: 1,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_Agent");
}

//------------------------------------------------------------------------------
// Address: 0x100118C0
// Name: private: static void CAI_Agent::InitDefaultConditionSR(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_Agent::InitDefaultConditionSR()
{
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NONE",
    localId: 0,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_Agent");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_TASK_FAILED",
    localId: 1,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_Agent");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_SCHEDULE_DONE",
    localId: 2,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_Agent");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NO_CUSTOM_INTERRUPTS",
    localId: 3,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_Agent");
}

//------------------------------------------------------------------------------
// Address: 0x10011930
// Name: private: static void CAI_Agent::InitDefaultScheduleSR(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_Agent::InitDefaultScheduleSR()
{
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_NONE",
    localId: 0,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_Agent");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_Agent::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FAIL",
    localId: 1,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_Agent");
}

//------------------------------------------------------------------------------
// Address: 0x100119F0
// Name: public: void CFastTimer::End(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFastTimer::End(CFastTimer *this)
{
  CCycleCount cnt; // [esp+4h] [ebp-Ch] BYREF
  CCycleCount *p_cnt; // [esp+Ch] [ebp-4h]

  p_cnt = &cnt;
  cnt.m_Int64 = __rdtsc();
  this->m_Duration.m_Int64 = cnt.m_Int64 - this->m_Duration.m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x10011A30
// Name: public: void CAI_Schedule::GetInterruptMask(class CBitVec<256> __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Schedule::GetInterruptMask(CAI_Schedule *this, CBitVec<256> *pBits)
{
  *pBits = this->m_InterruptMask;
}

//------------------------------------------------------------------------------
// Address: 0x103FA610
// Name: CAI_Agent_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Agent_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Agent>(__formal: nullptr);
  CAI_Agent_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FA620
// Name: AIAgentScheduleState_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AIAgentScheduleState_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AIAgentScheduleState_t>(__formal: nullptr);
  AIAgentScheduleState_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FA630
// Name: AIAgentSaveHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AIAgentSaveHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AIAgentSaveHeader_t>(__formal: nullptr);
  AIAgentSaveHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011A70
// Name: struct datamap_t __near * DataMapInit<class CAI_Agent>(class CAI_Agent __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Agent>()
{
  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    nameHolder_0.m_pszBase = "CAI_Agent";
    nameHolder_0.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_0.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_0.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_0.m_Names.m_Size = 0;
    nameHolder_0.m_Names.m_pElements = nullptr;
    nameHolder_0.m_nLenBase = 9;
    atexit(func: DataMapInit_CAI_Agent__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Agent::m_DataMap.baseMap = nullptr;
  CAI_Agent::m_DataMap.dataNumFields = 5;
  CAI_Agent::m_DataMap.dataDesc = &dataDesc_0[1];
  return &CAI_Agent::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FA640
// Name: _dynamic_initializer_for__g_AIAgentTaskTimings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_AIAgentTaskTimings__()
{
  g_AIAgentTaskTimings[0].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[0].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[0].runTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[1].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[1].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[1].runTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[2].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[2].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[2].runTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[3].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[3].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[3].runTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[4].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[4].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[4].runTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[5].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[5].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[5].runTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[6].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[6].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[6].runTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[7].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[7].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[7].runTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[8].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[8].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[8].runTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[9].selectSchedule.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[9].startTimer.m_Duration.m_Int64 = 0;
  g_AIAgentTaskTimings[9].runTimer.m_Duration.m_Int64 = 0;
}
