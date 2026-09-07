// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_plant_bomb.cpp
// Functions: 4
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_plant_bomb.h"

//------------------------------------------------------------------------------
// Address: 0x102D8540
// Name: public: virtual void PlantBombState::OnExit(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlantBombState::OnExit(PlantBombState *this, CCSBot *me)
{
  CCSBot::EquipBestWeapon(this: me, mustEquip: false);
  me->StandUp(this: me);
  CCSBot::ResetStuckMonitor(this: me);
  CCSBot::SetDisposition(this: me, disposition: ENGAGE_AND_INVESTIGATE);
  me->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
  me->m_lookAtDesc = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D8590
// Name: public: virtual void PlantBombState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlantBombState::OnEnter(PlantBombState *this, CCSBot *me)
{
  Vector myOrigin; // [esp+14h] [ebp-20h] BYREF
  Vector down; // [esp+20h] [ebp-14h] BYREF
  Vector2D dir; // [esp+2Ch] [ebp-8h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF
  float yaw; // [esp+3Ch] [ebp+8h]

  me->Crouch(this: me);
  CCSBot::SetDisposition(this: me, disposition: SELF_DEFENSE);
  yaw = me->EyeAngles(this: me)->y;
  dir.x = BotCOS(angle: yaw);
  dir.y = BotSIN(angle: yaw);
  GetCentroid(result: &myOrigin, player: me);
  if ( (me->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
  down.z = me->m_vecAbsOrigin.z;
  down.x = (float)(dir.x * 10.0) + myOrigin.x;
  down.y = (float)(dir.y * 10.0) + myOrigin.y;
  CCSBot::SetLookAt(
    this: me,
    desc: "Plant bomb on floor",
    pos: &down,
    pri: PRIORITY_HIGH,
    duration: -1.0,
    clearIfClose: false,
    angleTolerance: 5.0,
    attack: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D8680
// Name: public: virtual void PlantBombState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlantBombState::OnUpdate(PlantBombState *this, CCSBot *me)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  const char *pszValue; // eax

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: me);
  if ( ActiveWeapon == nullptr )
    goto LABEL_7;
  pszValue = ActiveWeapon->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( pszValue == "weapon_c4" || _V_stricmp(s1: pszValue, s2: "weapon_c4") == 0 )
    me->PrimaryAttack(this: me);
  else
LABEL_7:
    me->SelectItem(this: me, a2: "weapon_c4", a3: 0);
  if ( !CCSPlayer::HasC4(this: me) )
  {
    me->m_task = GUARD_TICKING_BOMB;
    me->m_taskEntity.m_Index = -1;
    CCSBot::Hide(this: me, searchFromArea: nullptr, duration: -1.0, hideRange: 750.0, holdPosition: false);
  }
  if ( (float)(gpGlobals->curtime - me->m_stateTimestamp) > 5.0 )
    CCSBot::Idle(this: me);
}

//------------------------------------------------------------------------------
// Address: 0x102D8750
// Name: __CreateCServerGameTagsIServerGameTags_interface_50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_50()
{
  return &_g_CServerGameTags_singleton_50;
}
