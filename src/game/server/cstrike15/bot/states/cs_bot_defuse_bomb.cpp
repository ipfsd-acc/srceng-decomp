// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_defuse_bomb.cpp
// Functions: 4
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_defuse_bomb.h"

//------------------------------------------------------------------------------
// Address: 0x102D2A10
// Name: public: virtual void DefuseBombState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DefuseBombState::OnEnter(DefuseBombState *this, CCSBot *me)
{
  BotStatement *v2; // eax
  BotStatement *v3; // esi
  const BotPhrase *Phrase; // eax

  me->Crouch(this: me);
  CCSBot::SetDisposition(this: me, disposition: SELF_DEFENSE);
  v2 = (BotStatement *)operator new(nSize: 0x70u);
  if ( v2 != nullptr )
    v3 = BotStatement::BotStatement(this: v2, chatter: &me->m_chatter, type: REPORT_MY_INTENTION, expireDuration: 3.0);
  else
    v3 = nullptr;
  Phrase = BotPhraseManager::GetPhrase(this: TheBotPhrases, name: "DefusingBomb");
  BotStatement::AppendPhrase(this: v3, phrase: Phrase);
  BotChatterInterface::AddStatement(this: &me->m_chatter, statement: v3, mustAdd: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D2A90
// Name: public: virtual void DefuseBombState::OnExit(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DefuseBombState::OnExit(DefuseBombState *this, CCSBot *me)
{
  me->StandUp(this: me);
  CCSBot::ResetStuckMonitor(this: me);
  me->m_task = SEEK_AND_DESTROY;
  me->m_taskEntity.m_Index = -1;
  CCSBot::SetDisposition(this: me, disposition: ENGAGE_AND_INVESTIGATE);
  me->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
  me->m_lookAtDesc = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D2AE0
// Name: public: virtual void DefuseBombState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DefuseBombState::OnUpdate(DefuseBombState *this, CCSBot *me)
{
  const Vector *BombPosition; // eax
  CCSBot *v3; // eax

  BombPosition = CSGameState::GetBombPosition(this: &me->m_gameState);
  if ( BombPosition == nullptr )
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "In Defuse state, but don't know where the bomb is!\n");
    CCSBot::Idle(this: me);
    return;
  }
  CCSBot::SetLookAt(
    this: me,
    desc: "Defuse bomb",
    pos: BombPosition,
    pri: PRIORITY_HIGH,
    duration: -1.0,
    clearIfClose: false,
    angleTolerance: 5.0,
    attack: false);
  me->UseEnvironment(this: me);
  if ( (float)(gpGlobals->curtime - me->m_stateTimestamp) <= 1.0 )
    goto LABEL_8;
  v3 = *(CCSBot **)&TheBots[1].m_debugMessage[0].m_string[472];
  if ( v3 == nullptr )
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Failed to start defuse, giving up\n");
    CCSBot::Idle(this: me);
    return;
  }
  if ( v3 == me )
  {
LABEL_8:
    if ( TheBots[1].m_debugMessage[0].m_string[460] == 0 )
      CCSBot::Idle(this: me);
  }
  else
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Someone else started defusing, giving up\n");
    CCSBot::Idle(this: me);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2BD0
// Name: __CreateCServerGameTagsIServerGameTags_interface_39
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_39()
{
  return &_g_CServerGameTags_singleton_39;
}
