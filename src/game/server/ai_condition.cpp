// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_condition.cpp
// Functions: 1
// ============================================================

#include "game\server\ai_condition.h"

//------------------------------------------------------------------------------
// Address: 0x1004C6C0
// Name: private: static void CAI_BaseNPC::InitDefaultConditionSR(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_BaseNPC::InitDefaultConditionSR()
{
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NONE",
    localId: 0,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_IN_PVS",
    localId: 1,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_IDLE_INTERRUPT",
    localId: 2,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_LOW_PRIMARY_AMMO",
    localId: 3,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NO_PRIMARY_AMMO",
    localId: 4,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NO_SECONDARY_AMMO",
    localId: 5,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NO_WEAPON",
    localId: 6,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_SEE_HATE",
    localId: 7,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_SEE_FEAR",
    localId: 8,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_SEE_DISLIKE",
    localId: 9,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_SEE_ENEMY",
    localId: 10,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_LOST_ENEMY",
    localId: 11,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_ENEMY_WENT_NULL",
    localId: 12,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HAVE_ENEMY_LOS",
    localId: 15,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HAVE_TARGET_LOS",
    localId: 16,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_ENEMY_OCCLUDED",
    localId: 13,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_TARGET_OCCLUDED",
    localId: 14,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_ENEMY_TOO_FAR",
    localId: 27,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_LIGHT_DAMAGE",
    localId: 17,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAVY_DAMAGE",
    localId: 18,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_PHYSICS_DAMAGE",
    localId: 19,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_REPEATED_DAMAGE",
    localId: 20,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_CAN_RANGE_ATTACK1",
    localId: 21,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_CAN_RANGE_ATTACK2",
    localId: 22,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_CAN_MELEE_ATTACK1",
    localId: 23,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_CAN_MELEE_ATTACK2",
    localId: 24,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_PROVOKED",
    localId: 25,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NEW_ENEMY",
    localId: 26,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_ENEMY_FACING_ME",
    localId: 28,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_BEHIND_ENEMY",
    localId: 29,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_ENEMY_DEAD",
    localId: 30,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_ENEMY_UNREACHABLE",
    localId: 31,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_SEE_PLAYER",
    localId: 32,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_LOST_PLAYER",
    localId: 33,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_SEE_NEMESIS",
    localId: 34,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_TASK_FAILED",
    localId: 35,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_SCHEDULE_DONE",
    localId: 36,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_SMELL",
    localId: 37,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_TOO_CLOSE_TO_ATTACK",
    localId: 38,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_TOO_FAR_TO_ATTACK",
    localId: 39,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NOT_FACING_ATTACK",
    localId: 40,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_WEAPON_HAS_LOS",
    localId: 41,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_WEAPON_BLOCKED_BY_FRIEND",
    localId: 42,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_WEAPON_PLAYER_IN_SPREAD",
    localId: 43,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_WEAPON_PLAYER_NEAR_TARGET",
    localId: 44,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_WEAPON_SIGHT_OCCLUDED",
    localId: 45,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_BETTER_WEAPON_AVAILABLE",
    localId: 46,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEALTH_ITEM_AVAILABLE",
    localId: 47,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_FLOATING_OFF_GROUND",
    localId: 61,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_MOBBED_BY_ENEMIES",
    localId: 62,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_GIVE_WAY",
    localId: 48,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_WAY_CLEAR",
    localId: 49,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAR_DANGER",
    localId: 50,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAR_THUMPER",
    localId: 51,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAR_COMBAT",
    localId: 53,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAR_WORLD",
    localId: 54,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAR_PLAYER",
    localId: 55,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAR_BULLET_IMPACT",
    localId: 56,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAR_BUGBAIT",
    localId: 52,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAR_PHYSICS_DANGER",
    localId: 57,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_HEAR_MOVE_AWAY",
    localId: 58,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NO_HEAR_DANGER",
    localId: 60,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_PLAYER_PUSHING",
    localId: 66,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_RECEIVED_ORDERS",
    localId: 63,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_PLAYER_ADDED_TO_SQUAD",
    localId: 64,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_PLAYER_REMOVED_FROM_SQUAD",
    localId: 65,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NPC_FREEZE",
    localId: 67,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NPC_UNFREEZE",
    localId: 68,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_TALKER_RESPOND_TO_QUESTION",
    localId: 69,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_NO_CUSTOM_INTERRUPTS",
    localId: 70,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
  CAI_LocalIdSpace::AddSymbol(
    this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds,
    pszSymbol: "COND_BEHAVIOR_PARAMETERS_CHANGED",
    localId: 71,
    pszDebugSymbolType: "condition",
    pszDebugOwner: "CAI_BaseNPC");
}
