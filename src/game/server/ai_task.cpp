// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_task.cpp
// Functions: 2
// ============================================================

#include "game\server\ai_task.h"

//------------------------------------------------------------------------------
// Address: 0x1008E930
// Name: char const __near * TaskFailureToString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl TaskFailureToString(unsigned int code)
{
  const char *result; // eax

  result = (const char *)code;
  if ( code <= 0x1C )
    return g_ppszTaskFailureText[code];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E950
// Name: private: static void CAI_BaseNPC::InitDefaultTaskSR(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_BaseNPC::InitDefaultTaskSR()
{
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_INVALID",
    localId: 0,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_ANNOUNCE_ATTACK",
    localId: 3,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RESET_ACTIVITY",
    localId: 1,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT",
    localId: 2,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_FACE_ENEMY",
    localId: 4,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_FACE_ENEMY_RANDOM",
    localId: 5,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_PVS",
    localId: 6,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SUGGEST_STATE",
    localId: 7,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_TARGET_PLAYER",
    localId: 8,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SCRIPT_WALK_TO_TARGET",
    localId: 9,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SCRIPT_RUN_TO_TARGET",
    localId: 10,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SCRIPT_CUSTOM_MOVE_TO_TARGET",
    localId: 11,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_MOVE_TO_TARGET_RANGE",
    localId: 12,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_MOVE_TO_GOAL_RANGE",
    localId: 13,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_MOVE_AWAY_PATH",
    localId: 14,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_AWAY_FROM_BEST_SOUND",
    localId: 15,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SET_GOAL",
    localId: 16,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_GOAL",
    localId: 17,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_ENEMY",
    localId: 18,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_ENEMY_LKP",
    localId: 19,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_CHASE_PATH_TO_ENEMY",
    localId: 20,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_ENEMY_LKP_LOS",
    localId: 21,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_RANGE_ENEMY_LKP_LOS",
    localId: 27,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_ENEMY_CORPSE",
    localId: 22,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_PLAYER",
    localId: 23,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_ENEMY_LOS",
    localId: 24,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_FLANK_ARC_PATH_TO_ENEMY_LOS",
    localId: 26,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_FLANK_RADIUS_PATH_TO_ENEMY_LOS",
    localId: 25,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_TARGET",
    localId: 28,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_TARGET_WEAPON",
    localId: 29,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_OFF_OF_NPC",
    localId: 30,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_CREATE_PENDING_WEAPON",
    localId: 31,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_HINTNODE",
    localId: 32,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_STORE_LASTPOSITION",
    localId: 33,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_CLEAR_LASTPOSITION",
    localId: 34,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_STORE_POSITION_IN_SAVEPOSITION",
    localId: 35,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_STORE_BESTSOUND_IN_SAVEPOSITION",
    localId: 36,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_STORE_BESTSOUND_REACTORIGIN_IN_SAVEPOSITION",
    localId: 37,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_REACT_TO_COMBAT_SOUND",
    localId: 38,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_STORE_ENEMY_POSITION_IN_SAVEPOSITION",
    localId: 39,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_COMMAND_GOAL",
    localId: 40,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_MARK_COMMAND_GOAL_POS",
    localId: 41,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_CLEAR_COMMAND_GOAL",
    localId: 42,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_LASTPOSITION",
    localId: 43,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_SAVEPOSITION",
    localId: 44,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_SAVEPOSITION_LOS",
    localId: 45,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_BESTSOUND",
    localId: 47,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_BESTSCENT",
    localId: 48,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_RANDOM_NODE",
    localId: 46,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RUN_PATH",
    localId: 49,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WALK_PATH",
    localId: 50,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WALK_PATH_TIMED",
    localId: 51,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WALK_PATH_WITHIN_DIST",
    localId: 52,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RUN_PATH_WITHIN_DIST",
    localId: 57,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WALK_PATH_FOR_UNITS",
    localId: 53,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RUN_PATH_FOR_UNITS",
    localId: 56,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RUN_PATH_FLEE",
    localId: 54,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RUN_PATH_TIMED",
    localId: 55,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_STRAFE_PATH",
    localId: 58,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_CLEAR_MOVE_WAIT",
    localId: 59,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SMALL_FLINCH",
    localId: 60,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_BIG_FLINCH",
    localId: 61,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_DEFER_DODGE",
    localId: 62,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_IDEAL",
    localId: 63,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_REASONABLE",
    localId: 64,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_PATH",
    localId: 65,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_PLAYER",
    localId: 66,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_ENEMY",
    localId: 67,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_HINTNODE",
    localId: 68,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLAY_HINT_ACTIVITY",
    localId: 69,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_TARGET",
    localId: 70,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_LASTPOSITION",
    localId: 71,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_SAVEPOSITION",
    localId: 72,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_AWAY_FROM_SAVEPOSITION",
    localId: 73,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SET_IDEAL_YAW_TO_CURRENT",
    localId: 74,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RANGE_ATTACK1",
    localId: 75,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RANGE_ATTACK2",
    localId: 76,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_MELEE_ATTACK1",
    localId: 77,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_MELEE_ATTACK2",
    localId: 78,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RELOAD",
    localId: 79,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SPECIAL_ATTACK1",
    localId: 80,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SPECIAL_ATTACK2",
    localId: 81,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_HINTNODE",
    localId: 82,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_CLEAR_HINTNODE",
    localId: 84,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_LOCK_HINTNODE",
    localId: 83,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_LOCK_HINTNODE",
    localId: 85,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SOUND_ANGRY",
    localId: 86,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SOUND_DEATH",
    localId: 87,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SOUND_IDLE",
    localId: 88,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SOUND_WAKE",
    localId: 89,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SOUND_PAIN",
    localId: 90,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SOUND_DIE",
    localId: 91,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SPEAK_SENTENCE",
    localId: 92,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_FOR_SPEAK_FINISH",
    localId: 93,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SET_ACTIVITY",
    localId: 94,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_RANDOMIZE_FRAMERATE",
    localId: 95,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SET_SCHEDULE",
    localId: 96,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SET_FAIL_SCHEDULE",
    localId: 97,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SET_TOLERANCE_DISTANCE",
    localId: 98,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_SET_ROUTE_SEARCH_TIME",
    localId: 99,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_CLEAR_FAIL_SCHEDULE",
    localId: 100,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLAY_SEQUENCE",
    localId: 101,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLAY_PRIVATE_SEQUENCE",
    localId: 102,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLAY_PRIVATE_SEQUENCE_FACE_ENEMY",
    localId: 103,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLAY_SEQUENCE_FACE_ENEMY",
    localId: 104,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLAY_SEQUENCE_FACE_TARGET",
    localId: 105,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_COVER_FROM_BEST_SOUND",
    localId: 106,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_COVER_FROM_ENEMY",
    localId: 107,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_LATERAL_COVER_FROM_ENEMY",
    localId: 108,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_BACKAWAY_FROM_SAVEPOSITION",
    localId: 109,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_NODE_COVER_FROM_ENEMY",
    localId: 110,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_NEAR_NODE_COVER_FROM_ENEMY",
    localId: 111,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_FAR_NODE_COVER_FROM_ENEMY",
    localId: 112,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FIND_COVER_FROM_ORIGIN",
    localId: 113,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_DIE",
    localId: 114,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_FOR_SCRIPT",
    localId: 115,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PUSH_SCRIPT_ARRIVAL_ACTIVITY",
    localId: 116,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLAY_SCRIPT",
    localId: 117,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLAY_SCRIPT_POST_IDLE",
    localId: 118,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_ENABLE_SCRIPT",
    localId: 119,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLANT_ON_SCRIPT",
    localId: 120,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FACE_SCRIPT",
    localId: 121,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PLAY_SCENE",
    localId: 122,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_RANDOM",
    localId: 123,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_INDEFINITE",
    localId: 124,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_STOP_MOVING",
    localId: 125,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_TURN_LEFT",
    localId: 126,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_TURN_RIGHT",
    localId: 127,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_REMEMBER",
    localId: 128,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FORGET",
    localId: 129,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_FOR_MOVEMENT",
    localId: 130,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_FOR_MOVEMENT_STEP",
    localId: 131,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WAIT_UNTIL_NO_DANGER_SOUND",
    localId: 132,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WEAPON_FIND",
    localId: 133,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WEAPON_PICKUP",
    localId: 134,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WEAPON_RUN_PATH",
    localId: 135,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WEAPON_CREATE",
    localId: 136,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_ITEM_RUN_PATH",
    localId: 138,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_ITEM_PICKUP",
    localId: 137,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_USE_SMALL_HULL",
    localId: 139,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FALL_TO_GROUND",
    localId: 140,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_WANDER",
    localId: 141,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_FREEZE",
    localId: 142,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GATHER_CONDITIONS",
    localId: 143,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_IGNORE_OLD_ENEMIES",
    localId: 144,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_DEBUG_BREAK",
    localId: 145,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_ADD_HEALTH",
    localId: 146,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_GET_PATH_TO_INTERACTION_PARTNER",
    localId: 149,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds,
    pszSymbol: "TASK_PRE_SCRIPT",
    localId: 150,
    pszDebugSymbolType: "task",
    pszDebugOwner: "CAI_BaseNPC");
}
