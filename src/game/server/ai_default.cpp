// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_default.cpp
// Functions: 13
// ============================================================

#include "game\server\ai_default.h"

//------------------------------------------------------------------------------
// Address: 0x10001BA0
// Name: public: virtual char const __near * CAutoGameSystem::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAutoGameSystem::Name(CAutoGameSystemPerFrame *this)
{
  const char *result; // eax

  result = this->m_pszName;
  if ( result == nullptr )
    return "unnamed";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004CF60
// Name: private: static void CAI_BaseNPC::InitDefaultScheduleSR(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_BaseNPC::InitDefaultScheduleSR()
{
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_NONE",
    localId: 0,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_IDLE_STAND",
    localId: 1,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_IDLE_WALK",
    localId: 2,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_IDLE_WANDER",
    localId: 3,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_WAKE_ANGRY",
    localId: 4,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_ALERT_FACE",
    localId: 5,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_ALERT_FACE_BESTSOUND",
    localId: 6,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_ALERT_REACT_TO_COMBAT_SOUND",
    localId: 7,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_ALERT_SCAN",
    localId: 8,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_ALERT_STAND",
    localId: 9,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_ALERT_WALK",
    localId: 10,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_INVESTIGATE_SOUND",
    localId: 11,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_COMBAT_FACE",
    localId: 12,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_COMBAT_SWEEP",
    localId: 13,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FEAR_FACE",
    localId: 14,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_COMBAT_STAND",
    localId: 15,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_COMBAT_WALK",
    localId: 16,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_CHASE_ENEMY",
    localId: 17,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_CHASE_ENEMY_FAILED",
    localId: 18,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_VICTORY_DANCE",
    localId: 19,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_TARGET_FACE",
    localId: 20,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_TARGET_CHASE",
    localId: 21,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SMALL_FLINCH",
    localId: 22,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_BIG_FLINCH",
    localId: 23,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_BACK_AWAY_FROM_ENEMY",
    localId: 24,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_MOVE_AWAY_FROM_ENEMY",
    localId: 25,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_BACK_AWAY_FROM_SAVE_POSITION",
    localId: 26,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_TAKE_COVER_FROM_ENEMY",
    localId: 27,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_TAKE_COVER_FROM_BEST_SOUND",
    localId: 28,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FLEE_FROM_BEST_SOUND",
    localId: 29,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_TAKE_COVER_FROM_ORIGIN",
    localId: 30,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FAIL_TAKE_COVER",
    localId: 31,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_RUN_FROM_ENEMY",
    localId: 32,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_RUN_FROM_ENEMY_FALLBACK",
    localId: 33,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_MOVE_TO_WEAPON_RANGE",
    localId: 34,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_MOVE_OFF_OF_NPC",
    localId: 35,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_ESTABLISH_LINE_OF_FIRE",
    localId: 36,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SHOOT_ENEMY_COVER",
    localId: 40,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_ESTABLISH_LINE_OF_FIRE_FALLBACK",
    localId: 37,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_PRE_FAIL_ESTABLISH_LINE_OF_FIRE",
    localId: 38,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FAIL_ESTABLISH_LINE_OF_FIRE",
    localId: 39,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_COWER",
    localId: 41,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_MELEE_ATTACK1",
    localId: 42,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_MELEE_ATTACK2",
    localId: 43,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_RANGE_ATTACK1",
    localId: 44,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_RANGE_ATTACK2",
    localId: 45,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SPECIAL_ATTACK1",
    localId: 46,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SPECIAL_ATTACK2",
    localId: 47,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_STANDOFF",
    localId: 48,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_ARM_WEAPON",
    localId: 49,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_DISARM_WEAPON",
    localId: 50,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_HIDE_AND_RELOAD",
    localId: 51,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_RELOAD",
    localId: 52,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_AMBUSH",
    localId: 53,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_DIE",
    localId: 54,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_DIE_RAGDOLL",
    localId: 55,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_WAIT_FOR_SCRIPT",
    localId: 56,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_AISCRIPT",
    localId: 57,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SCRIPTED_WALK",
    localId: 58,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SCRIPTED_RUN",
    localId: 59,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SCRIPTED_CUSTOM_MOVE",
    localId: 60,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SCRIPTED_WAIT",
    localId: 61,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SCRIPTED_FACE",
    localId: 62,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SCENE_GENERIC",
    localId: 63,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_NEW_WEAPON",
    localId: 64,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_NEW_WEAPON_CHEAT",
    localId: 65,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SWITCH_TO_PENDING_WEAPON",
    localId: 66,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_GET_HEALTHKIT",
    localId: 67,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_MOVE_AWAY",
    localId: 69,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_MOVE_AWAY_FAIL",
    localId: 70,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_MOVE_AWAY_END",
    localId: 71,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_WAIT_FOR_SPEAK_FINISH",
    localId: 68,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FORCED_GO",
    localId: 72,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FORCED_GO_RUN",
    localId: 73,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_PATROL_WALK",
    localId: 75,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_COMBAT_PATROL",
    localId: 76,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_PATROL_RUN",
    localId: 77,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_RUN_RANDOM",
    localId: 78,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FAIL",
    localId: 82,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FAIL_NOSTOP",
    localId: 83,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FALL_TO_GROUND",
    localId: 79,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_DROPSHIP_DUSTOFF",
    localId: 80,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_NPC_FREEZE",
    localId: 74,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_FLINCH_PHYSICS",
    localId: 81,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_RUN_FROM_ENEMY_MOB",
    localId: 84,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_DUCK_DODGE",
    localId: 85,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_INTERACTION_MOVE_TO_PARTNER",
    localId: 86,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_INTERACTION_WAIT_FOR_PARTNER",
    localId: 87,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds,
    pszSymbol: "SCHED_SLEEP",
    localId: 88,
    pszDebugSymbolType: "schedule",
    pszDebugOwner: "CAI_BaseNPC");
}

//------------------------------------------------------------------------------
// Address: 0x1004D8D0
// Name: private: static bool CAI_BaseNPC::LoadDefaultSchedules(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAI_BaseNPC::LoadDefaultSchedules()
{
  return CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_IDLE_STAND,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_IDLE_WALK,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_IDLE_WANDER,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_WAKE_ANGRY,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_ALERT_FACE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_ALERT_FACE_BESTSOUND,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_ALERT_REACT_TO_COMBAT_SOUND,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_ALERT_SCAN,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_ALERT_STAND,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_ALERT_WALK,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_INVESTIGATE_SOUND,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_COMBAT_FACE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_COMBAT_SWEEP,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_COMBAT_WALK,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FEAR_FACE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_COMBAT_STAND,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_CHASE_ENEMY,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_CHASE_ENEMY_FAILED,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_VICTORY_DANCE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_TARGET_FACE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_TARGET_CHASE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SMALL_FLINCH,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_BIG_FLINCH,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_BACK_AWAY_FROM_ENEMY,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_MOVE_AWAY_FROM_ENEMY,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_BACK_AWAY_FROM_SAVE_POSITION,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_TAKE_COVER_FROM_ENEMY,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_TAKE_COVER_FROM_BEST_SOUND,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FLEE_FROM_BEST_SOUND,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_TAKE_COVER_FROM_ORIGIN,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FAIL_TAKE_COVER,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_RUN_FROM_ENEMY,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_RUN_FROM_ENEMY_FALLBACK,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_MOVE_TO_WEAPON_RANGE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_MOVE_OFF_OF_NPC,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_ESTABLISH_LINE_OF_FIRE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SHOOT_ENEMY_COVER,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_ESTABLISH_LINE_OF_FIRE_FALLBACK,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_PRE_FAIL_ESTABLISH_LINE_OF_FIRE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FAIL_ESTABLISH_LINE_OF_FIRE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_COWER,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_MELEE_ATTACK1,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_MELEE_ATTACK2,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_RANGE_ATTACK1,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_RANGE_ATTACK2,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SPECIAL_ATTACK1,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SPECIAL_ATTACK2,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_STANDOFF,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_ARM_WEAPON,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_DISARM_WEAPON,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_HIDE_AND_RELOAD,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_RELOAD,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_AMBUSH,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_DIE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_DIE_RAGDOLL,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_WAIT_FOR_SCRIPT,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SCRIPTED_WALK,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SCRIPTED_RUN,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SCRIPTED_CUSTOM_MOVE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SCRIPTED_WAIT,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SCRIPTED_FACE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SCENE_GENERIC,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_NEW_WEAPON,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_NEW_WEAPON_CHEAT,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SWITCH_TO_PENDING_WEAPON,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_GET_HEALTHKIT,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_MOVE_AWAY,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_MOVE_AWAY_FAIL,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_MOVE_AWAY_END,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_WAIT_FOR_SPEAK_FINISH,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FORCED_GO,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FORCED_GO_RUN,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_PATROL_WALK,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_COMBAT_PATROL,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_PATROL_RUN,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_RUN_RANDOM,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FAIL,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FAIL_NOSTOP,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FALL_TO_GROUND,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_DROPSHIP_DUSTOFF,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_FLINCH_PHYSICS,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_RUN_FROM_ENEMY_MOB,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_DUCK_DODGE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_NPC_FREEZE,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_INTERACTION_MOVE_TO_PARTNER,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_INTERACTION_WAIT_FOR_PARTNER,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols)
      && CAI_SchedulesManager::LoadSchedulesFromBuffer(
           this: &g_AI_SchedulesManager,
           prefix: "CAI_BaseNPC",
           pStartFile: (char *)g_pszSCHED_SLEEP,
           pIdSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace,
           pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x1004E640
// Name: protected: class CAI_Schedule __near * CAI_BaseNPC::GetScheduleOfType(int)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_BaseNPC::GetScheduleOfType(CAI_BaseNPC *this, int scheduleType)
{
  int v3; // edi
  CAI_Schedule *result; // eax

  v3 = this->TranslateSchedule(this, a2: scheduleType);
  result = this->GetSchedule(this, a2: v3);
  if ( result == nullptr )
  {
    DevMsg(a1: "GetScheduleOfType(): No CASE for Schedule Type %d!\n", v3);
    return this->GetSchedule(this, a2: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004E690
// Name: public: virtual class CAI_Schedule __near * CAI_BaseNPC::GetSchedule(int)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_BaseNPC::GetSchedule(CAI_BaseNPC *this, int schedule)
{
  const char *v3; // eax
  int v5; // edi
  CAI_ClassScheduleIdSpace *v6; // eax

  if ( this->GetClassScheduleIdSpace(this)->m_ScheduleIds.m_globalBase == -1 )
  {
    v3 = this->GetSchedulingErrorName(this);
    _Warning(a1: "ERROR: %s missing schedule!\n", v3);
    return CAI_SchedulesManager::GetScheduleFromID(this: &g_AI_SchedulesManager, schedID: 1);
  }
  else
  {
    v5 = schedule;
    if ( schedule < 1000000000 )
    {
      v6 = this->GetClassScheduleIdSpace(this);
      v5 = CAI_LocalIdSpace::LocalToGlobal(this: &v6->m_ScheduleIds, localID: schedule);
    }
    return CAI_SchedulesManager::GetScheduleFromID(this: &g_AI_SchedulesManager, schedID: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E710
// Name: public: bool CAI_BaseNPC::IsCurSchedule(int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsCurSchedule(CAI_BaseNPC *this, int schedId, bool fIdeal)
{
  int v5; // edi
  CAI_ClassScheduleIdSpace *v6; // eax

  if ( this->m_pSchedule == nullptr )
    return schedId == 0 || schedId == 1000000000;
  v5 = schedId;
  if ( schedId < 1000000000 )
  {
    v6 = this->GetClassScheduleIdSpace(this);
    v5 = CAI_LocalIdSpace::LocalToGlobal(this: &v6->m_ScheduleIds, localID: schedId);
  }
  if ( fIdeal )
    return v5 == this->m_IdealSchedule;
  else
    return this->m_pSchedule->m_iScheduleID == v5;
}

//------------------------------------------------------------------------------
// Address: 0x1004E790
// Name: public: virtual char const __near * CAI_BaseNPC::ConditionName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_BaseNPC::ConditionName(CAI_BaseNPC *this, int conditionID)
{
  int v2; // esi
  CAI_ClassScheduleIdSpace *v3; // eax

  v2 = conditionID;
  if ( conditionID < 1000000000 )
  {
    v3 = this->GetClassScheduleIdSpace(this);
    v2 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_ConditionIds, localID: conditionID);
  }
  return CAI_GlobalNamespace::IdToSymbol(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ConditionNamespace, symbolID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1004E7D0
// Name: public: virtual char const __near * CAI_BaseNPC::TaskName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_BaseNPC::TaskName(CAI_BaseNPC *this, int taskID)
{
  int v2; // esi
  CAI_ClassScheduleIdSpace *v3; // eax

  v2 = taskID;
  if ( taskID < 1000000000 )
  {
    v3 = this->GetClassScheduleIdSpace(this);
    v2 = CAI_LocalIdSpace::LocalToGlobal(this: &v3->m_TaskIds, localID: taskID);
  }
  return CAI_GlobalNamespace::IdToSymbol(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_TaskNamespace, symbolID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1004E810
// Name: public: virtual void CAI_SystemHook::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SystemHook::LevelInitPreEntity(CAI_SystemHook *this)
{
  g_AINextDisabledMessageTime = 0.0;
  CAI_SchedulesManager::CreateStringRegistries(this: &g_AI_SchedulesManager);
  CAI_BaseNPC::gm_iNextThinkRebalanceTick = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004E830
// Name: public: virtual void CAI_SystemHook::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SystemHook::LevelInitPostEntity(CAI_SystemHook *this)
{
  CAI_SensedObjectsManager::Init(this: &g_AI_SensedObjectsManager);
}

//------------------------------------------------------------------------------
// Address: 0x1004E840
// Name: public: virtual void CAI_SystemHook::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SystemHook::LevelShutdownPreEntity(CAI_SystemHook *this)
{
  CBaseCombatCharacter::ResetVisibilityCache(pBCC: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1004E850
// Name: public: virtual void CAI_SystemHook::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SystemHook::LevelShutdownPostEntity(CAI_SystemHook *this)
{
  CAI_SensedObjectsManager::Term(this: &g_AI_SensedObjectsManager);
  CAI_NetworkManager::DeleteAllAINetworks();
  CAI_SchedulesManager::DeleteAllSchedules(this: &g_AI_SchedulesManager);
  CAI_SchedulesManager::DeleteAllSchedules(this: &g_AI_AgentSchedulesManager);
  CAI_SquadManager::DeleteAllSquads(this: &g_AI_SquadManager);
  CAI_SchedulesManager::DestroyStringRegistries(this: &g_AI_SchedulesManager);
  CAI_SchedulesManager::DestroyStringRegistries(this: &g_AI_AgentSchedulesManager);
}

//------------------------------------------------------------------------------
// Address: 0x1004E8B0
// Name: public: virtual int CAI_BaseNPC::TranslateSchedule(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::TranslateSchedule(CAI_BaseNPC *this, int scheduleType)
{
  int result; // eax
  unsigned int m_Index; // edx
  int v5; // ecx
  CEntInfo *v6; // esi
  unsigned int v7; // edx
  const char *pszValue; // eax
  int v9; // ecx
  bool v10; // zf
  CEntInfo *v11; // ecx
  IHandleEntity *m_pEntity; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  result = scheduleType;
  if ( scheduleType == 2 )
  {
    if ( this->m_NPCState == NPC_STATE_ALERT )
    {
      return 10;
    }
    else if ( this->m_NPCState == NPC_STATE_COMBAT )
    {
      return 16;
    }
  }
  else if ( scheduleType == 57 )
  {
    m_Index = this->m_hCine.m_Index;
    if ( m_Index != -1
      && (v5 = (unsigned __int16)m_Index,
          v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v7 = HIWORD(m_Index),
          v6->m_SerialNumber == v7)
      && v6->m_pEntity != nullptr )
    {
      v9 = v5;
      v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v7;
      v11 = &g_pEntityList->m_EntPtrArray[v9];
      if ( v10 )
        m_pEntity = v11->m_pEntity;
      else
        m_pEntity = nullptr;
      switch ( (unsigned int)m_pEntity[220].__vftable )
      {
        case 0u:
        case 4u:
          result = 61;
          break;
        case 1u:
          result = 58;
          break;
        case 2u:
          result = 59;
          break;
        case 3u:
          result = 60;
          break;
        case 5u:
          result = 62;
          break;
        default:
          return result;
      }
    }
    else
    {
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      _DevWarning(a1: 2, a2: "Script failed for %s\n", pszValue);
      CAI_BaseNPC::CineCleanup(this, a2: (int)&savedregs);
      return 1;
    }
  }
  return result;
}
