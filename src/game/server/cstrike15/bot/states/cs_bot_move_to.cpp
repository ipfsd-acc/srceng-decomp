// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_move_to.cpp
// Functions: 6
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_move_to.h"

//------------------------------------------------------------------------------
// Address: 0x102D7AF0
// Name: public: virtual void MoveToState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MoveToState::OnEnter(MoveToState *this, CCSBot *me)
{
  CCSBot::TaskType m_task; // eax
  RouteType v4; // eax

  if ( CCSBot::IsUsingKnife(this: me) && CCSBot::IsWellPastSafe(this: me) && !CCSBot::IsHurrying(this: me) )
    me->Walk(this: me);
  else
    me->Run(this: me);
  m_task = me->m_task;
  if ( m_task >= FIND_TICKING_BOMB && (m_task <= DEFUSE_BOMB || m_task == MOVE_TO_LAST_KNOWN_ENEMY_POSITION) )
    v4 = FASTEST_ROUTE;
  else
    v4 = SAFEST_ROUTE;
  CCSBot::ComputePath(this: me, goal: &this->m_goalPosition, route: v4);
  *(_WORD *)&this->m_radioedPlan = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102D7B70
// Name: public: virtual void MoveToState::OnExit(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MoveToState::OnExit(MoveToState *this, CCSBot *me)
{
  me->Run(this: me);
  CCSBot::SetDisposition(this: me, disposition: ENGAGE_AND_INVESTIGATE);
}

//------------------------------------------------------------------------------
// Address: 0x102D7BA0
// Name: public: class CBaseEntity __near * CCSBot::GetTaskEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CCSBot::GetTaskEntity(CCSBot *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_taskEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x102D7BD0
// Name: public: class CBaseEntity __near * CCSBot::GetGoalEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CCSBot::GetGoalEntity(CCSBot *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_goalEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x102D7C00
// Name: public: virtual void MoveToState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge MoveToState::OnUpdate(MoveToState *this@<ecx>, int a2@<edi>, CCSBot *me)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CCSBot::TaskType m_task; // eax
  CHostage *GoalEntity; // eax
  CHostage *v9; // edi
  float y; // xmm4_4
  float z; // xmm5_4
  Vector *v12; // eax
  IUniformRandomStream *v13; // ecx
  CBaseEntity *v14; // eax
  CCSBot *v15; // ecx
  int v16; // ebx
  int v17; // edi
  double PathDistanceRemaining; // st7
  CCSBot_vtbl *v19; // edx
  CCSBot *v20; // ecx
  const Vector *BombPosition; // edi
  Vector *v22; // eax
  float v23; // xmm1_4
  unsigned int Place; // eax
  unsigned int v25; // eax
  CBaseEntity *TaskEntity; // eax
  BotStatement *v27; // eax
  BotStatement *v28; // edi
  const BotPhrase *Phrase; // eax
  IUniformRandomStream *v30; // ecx
  _BYTE v31[12]; // [esp+24h] [ebp-24h] BYREF
  _BYTE v32[12]; // [esp+30h] [ebp-18h] BYREF
  Vector pos; // [esp+3Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+48h] [ebp+0h] BYREF
  float mea; // [esp+50h] [ebp+8h]

  GetCentroid(result: &pos, player: me);
  if ( me->m_task == MOVE_TO_LAST_KNOWN_ENEMY_POSITION )
  {
    m_Index = me->m_taskEntity.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
      || m_pEntity->__vftable[22].GetRefEHandle(this: m_pEntity) == nullptr )
    {
      CBot<CCSPlayer>::PrintIfWatched(this: me, format: "The enemy I was chasing was killed - giving up.\n");
      CCSBot::Idle(this: me);
      return;
    }
  }
  CCSBot::UpdateLookAround(this: me, a2: COERCE_FLOAT(&savedregs), a3: a2, updateNow: false);
  if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1 )
  {
    if ( me->m_task == FIND_TICKING_BOMB )
    {
      if ( me->m_gameState.m_bombState != 2 || CSGameState::GetPlantedBombsite(this: &me->m_gameState) != -1 )
        goto LABEL_26;
      v16 = 0;
      if ( *(int *)&TheBots[1].m_debugMessage[0].m_string[456] > 0 )
      {
        v17 = 0;
        while ( CSGameState::IsBombsiteClear(this: &me->m_gameState, zoneIndex: v16)
             || pos.x < *(float *)&TheBots[1].m_debugMessage[0].m_string[v17 + 72]
             || *(float *)&TheBots[1].m_debugMessage[0].m_string[v17 + 84] < pos.x
             || pos.y < *(float *)&TheBots[1].m_debugMessage[0].m_string[v17 + 76]
             || *(float *)&TheBots[1].m_debugMessage[0].m_string[v17 + 88] < pos.y
             || pos.z < *(float *)&TheBots[1].m_debugMessage[0].m_string[v17 + 80]
             || *(float *)&TheBots[1].m_debugMessage[0].m_string[v17 + 92] < pos.z )
        {
          ++v16;
          v17 += 120;
          if ( v16 >= *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[456] )
            goto LABEL_73;
        }
        CSGameState::ClearBombsite(this: &me->m_gameState, zoneIndex: v16);
        if ( CBaseEntity::GetTeamNumber(this: me) == 3 )
        {
          BotChatterInterface::BombsiteClear(this: &me->m_chatter, zoneIndex: v16);
          CCSBot::Idle(this: me);
          return;
        }
        goto LABEL_26;
      }
      goto LABEL_73;
    }
    if ( CBaseEntity::GetTeamNumber(this: me) != 3 )
    {
      if ( me->m_task == PLANT_BOMB && CBot<CCSPlayer>::GetFriendsRemaining(this: me) != 0 && !this->m_askedForCover )
      {
        if ( me->m_bInBombZone.m_Value && CCSBot::GetPathDistanceRemaining(this: me) < 50.0 )
        {
          Place = CCSBot::GetPlace(this: me);
          BotChatterInterface::PlantingTheBomb(this: &me->m_chatter, place: Place);
          this->m_askedForCover = true;
        }
        if ( !this->m_radioedPlan && (float)(gpGlobals->curtime - me->m_stateTimestamp) > 2.0 )
        {
          if ( CCSBot::GetPathDistanceRemaining(this: me) >= 2400.0 )
          {
            v25 = CNavMesh::GetPlace(this: TheNavMesh, pos: &this->m_goalPosition);
            BotChatterInterface::GoingToPlantTheBomb(this: &me->m_chatter, place: v25);
          }
          this->m_radioedPlan = true;
        }
      }
      goto LABEL_73;
    }
    if ( me->m_gameState.m_bombState != 2 )
      goto LABEL_73;
    v15 = me;
    if ( me->m_task != DEFUSE_BOMB )
      goto LABEL_27;
    if ( CBot<CCSPlayer>::GetEnemiesRemaining(this: me) != 0 )
    {
      if ( CCSBotManager::GetBombTimeLeft(this: (CCSBotManager *)TheBots) <= 15.0 )
      {
LABEL_54:
        if ( CCSBot::CanSeePlantedBomb(this: me) && *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[472] != 0 )
        {
          BotChatterInterface::Say(this: &me->m_chatter, phraseName: "CoveringFriend", lifetime: 3.0, delay: 0.0);
          CCSBot::Idle(this: me);
          return;
        }
        BombPosition = CSGameState::GetBombPosition(this: &me->m_gameState);
        if ( BombPosition != nullptr && !CCSPlayer::IsReloading(this: me) )
        {
          v22 = me->EyePosition(this: me, result: v31);
          v23 = BombPosition->y - v22->y;
          if ( (float)((float)((float)((float)(BombPosition->x - v22->x) * (float)(BombPosition->x - v22->x))
                             + (float)(v23 * v23))
                     + (float)((float)(BombPosition->z - v22->z) * (float)(BombPosition->z - v22->z))) < 10000.0
            && CCSBot::IsVisible(this: me, pos: BombPosition, testFOV: false, ignore: nullptr) != 0 )
          {
            CCSBot::DefuseBomb(this: me);
            return;
          }
        }
        goto LABEL_73;
      }
      PathDistanceRemaining = CCSBot::GetPathDistanceRemaining(this: me);
      v19 = me->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v20 = me;
      if ( PathDistanceRemaining < 1500.0 )
      {
        ((void (__fastcall *)(CCSBot *))v19->Walk)(a1: me);
        goto LABEL_54;
      }
    }
    else
    {
      v19 = me->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v20 = me;
    }
    ((void (__fastcall *)(CCSBot *))v19->Run)(a1: v20);
    goto LABEL_54;
  }
  if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)2 )
  {
    m_task = me->m_task;
    if ( m_task == COLLECT_HOSTAGES )
    {
      GoalEntity = (CHostage *)CCSBot::GetGoalEntity(this: me);
      v9 = GoalEntity;
      if ( GoalEntity == nullptr || !CHostage::IsValid(this: GoalEntity) || CHostage::IsFollowingSomeone(this: v9) )
        goto LABEL_26;
      GetCentroid(result: &pos, player: v9);
      y = pos.y;
      z = pos.z;
      if ( (float)((float)((float)((float)(pos.x - this->m_goalPosition.x) * (float)(pos.x - this->m_goalPosition.x))
                         + (float)((float)(pos.y - this->m_goalPosition.y) * (float)(pos.y - this->m_goalPosition.y)))
                 + (float)((float)(pos.z - this->m_goalPosition.z) * (float)(pos.z - this->m_goalPosition.z))) > 5625.0 )
      {
        this->m_goalPosition.x = pos.x;
        this->m_goalPosition.y = y;
        this->m_goalPosition.z = z;
        CCSBot::ComputePath(this: me, goal: &this->m_goalPosition, route: SAFEST_ROUTE);
      }
      if ( me->m_pathLadder == nullptr )
      {
        v9->EyePosition(this: v9, result: &pos);
        v12 = me->EyePosition(this: me, result: v32);
        mea = (float)((float)((float)(pos.x - v12->x) * (float)(pos.x - v12->x))
                    + (float)((float)(pos.y - v12->y) * (float)(pos.y - v12->y)))
            + (float)((float)(pos.z - v12->z) * (float)(pos.z - v12->z));
        if ( mea < 10000.0 )
        {
          CCSBot::SetLookAt(
            this: me,
            desc: "Hostage",
            &pos,
            pri: PRIORITY_LOW,
            duration: 0.5,
            clearIfClose: false,
            angleTolerance: 5.0,
            attack: false);
          switch ( _RandomInt(this: v13, a2: 0, a3: 3) )
          {
            case 0:
              me->MoveForward(this: me);
              break;
            case 1:
              me->StrafeRight(this: me);
              break;
            case 2:
              me->MoveBackward(this: me);
              break;
            case 3:
              me->StrafeLeft(this: me);
              break;
            default:
              break;
          }
          if ( mea < 4900.0 )
          {
            v14 = CCSBot::GetGoalEntity(this: me);
            CCSBot::UseEntity(this: me, entity: v14);
            return;
          }
        }
      }
    }
    else if ( m_task == RESCUE_HOSTAGES && me->m_hostageEscortCount == 0 )
    {
      goto LABEL_26;
    }
  }
LABEL_73:
  if ( CCSBot::UpdatePathMovement(this: me, a2: (int)&savedregs, allowSpeedChange: true) == 0 )
    return;
  if ( me->m_task == PLANT_BOMB )
  {
    if ( me->m_bInBombZone.m_Value && CCSPlayer::HasC4(this: me) )
    {
      CCSBot::PlantBomb(this: me);
      return;
    }
    goto LABEL_26;
  }
  if ( me->m_task != MOVE_TO_LAST_KNOWN_ENEMY_POSITION
    || (TaskEntity = CCSBot::GetTaskEntity(this: me)) == nullptr
    || !TaskEntity->IsAlive(this: TaskEntity) )
  {
LABEL_26:
    v15 = me;
LABEL_27:
    CCSBot::Idle(this: v15);
    return;
  }
  v27 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v27 != nullptr )
    v28 = BotStatement::BotStatement(this: v27, chatter: &me->m_chatter, type: REPORT_ENEMY_LOST, expireDuration: 8.0);
  else
    v28 = nullptr;
  Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "LostEnemy");
  BotStatement::AppendPhrase(this: v28, phrase: Phrase);
  v28->m_startTime = _RandomFloat(this: v30, a2: 3.0, a3: 5.0) + gpGlobals->curtime;
  BotChatterInterface::AddStatement(this: &me->m_chatter, statement: v28, mustAdd: false);
  CCSBot::Idle(this: me);
}

//------------------------------------------------------------------------------
// Address: 0x102D82B0
// Name: __CreateCServerGameTagsIServerGameTags_interface_48
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_48()
{
  return &_g_CServerGameTags_singleton_48;
}
