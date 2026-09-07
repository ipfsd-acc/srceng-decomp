// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_event_bomb.cpp
// Functions: 7
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_event_bomb.h"

//------------------------------------------------------------------------------
// Address: 0x102AF8A0
// Name: public: void CCSBot::OnBombPlanted(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnBombPlanted(CCSBot *this, IGameEvent *event)
{
  int v3; // eax

  CSGameState::OnBombPlanted(this: &this->m_gameState, event);
  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    if ( UTIL_PlayerByUserId(userID: v3) != this )
    {
      if ( CBaseEntity::GetTeamNumber(this) == 3 )
        CCSBot::Idle(this);
      if ( this->m_isFollowing )
      {
        CCSBot::StopFollowing(this);
        CCSBot::Idle(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF920
// Name: public: void CCSBot::OnBombDefused(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnBombDefused(CCSBot *this, IGameEvent *event)
{
  int v3; // eax

  CSGameState::OnBombDefused(this: &this->m_gameState, event);
  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    if ( UTIL_PlayerByUserId(userID: v3) != this
      && CBaseEntity::GetTeamNumber(this) == 3
      && CCSBotManager::GetBombTimeLeft(this: (CCSBotManager *)TheBots) < 2.0 )
    {
      BotChatterInterface::Say(this: &this->m_chatter, phraseName: "BarelyDefused", lifetime: 3.0, delay: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF9C0
// Name: public: void CCSBot::OnBombExploded(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnBombExploded(CCSBot *this, IGameEvent *event)
{
  CSGameState::OnBombExploded(this: &this->m_gameState, event);
}

//------------------------------------------------------------------------------
// Address: 0x102AF9D0
// Name: public: void CCSBot::OnBombPickedUp(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnBombPickedUp(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // esi
  const Vector *AbsOrigin; // eax
  Vector myOrigin; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this && CBaseEntity::GetTeamNumber(this) == 3 && v4 != nullptr )
    {
      GetCentroid(result: &myOrigin, player: this);
      if ( (v4->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
      if ( (float)((float)((float)((float)(myOrigin.x - v4->m_vecAbsOrigin.x)
                                 * (float)(myOrigin.x - v4->m_vecAbsOrigin.x))
                         + (float)((float)(myOrigin.y - v4->m_vecAbsOrigin.y)
                                 * (float)(myOrigin.y - v4->m_vecAbsOrigin.y)))
                 + (float)((float)(myOrigin.z - v4->m_vecAbsOrigin.z) * (float)(myOrigin.z - v4->m_vecAbsOrigin.z))) < 1000000.0 )
      {
        BotChatterInterface::TheyPickedUpTheBomb(this: &this->m_chatter);
        AbsOrigin = CBaseEntity::GetAbsOrigin(this: v4);
        CSGameState::UpdateBomber(this: &this->m_gameState, pos: AbsOrigin);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AFAC0
// Name: public: void CCSBot::OnBombBeep(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnBombBeep(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  int v4; // eax
  CBaseEntity *v5; // esi
  CSGameState *p_m_gameState; // ebx
  CCSBotManager *v7; // ebx
  const Vector *AbsOrigin; // eax
  const CCSBotManager::Zone *Zone; // eax
  const Vector *v10; // eax
  Vector myOrigin; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    if ( UTIL_PlayerByUserId(userID: v3) != this )
    {
      v4 = event->GetInt(this: event, a2: "entindex", a3: 0);
      v5 = UTIL_EntityByIndex(entityIndex: v4);
      GetCentroid(result: &myOrigin, player: this);
      p_m_gameState = &this->m_gameState;
      if ( !CSGameState::IsPlantedBombLocationKnown(this: &this->m_gameState) && v5 != nullptr )
      {
        if ( (v5->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
        if ( (float)((float)((float)((float)(myOrigin.x - v5->m_vecAbsOrigin.x)
                                   * (float)(myOrigin.x - v5->m_vecAbsOrigin.x))
                           + (float)((float)(myOrigin.y - v5->m_vecAbsOrigin.y)
                                   * (float)(myOrigin.y - v5->m_vecAbsOrigin.y)))
                   + (float)((float)(myOrigin.z - v5->m_vecAbsOrigin.z) * (float)(myOrigin.z - v5->m_vecAbsOrigin.z))) < 2250000.0 )
        {
          if ( CBaseEntity::GetTeamNumber(this) == 3 && CSGameState::GetPlantedBombsite(this: &this->m_gameState) == -1 )
          {
            v7 = (CCSBotManager *)TheBots;
            AbsOrigin = CBaseEntity::GetAbsOrigin(this: v5);
            Zone = CCSBotManager::GetZone(this: v7, pos: AbsOrigin);
            if ( Zone != nullptr )
              BotChatterInterface::FoundPlantedBomb(this: &this->m_chatter, zoneIndex: Zone->m_index);
            p_m_gameState = &this->m_gameState;
          }
          v10 = CBaseEntity::GetAbsOrigin(this: v5);
          CSGameState::UpdatePlantedBomb(this: p_m_gameState, pos: v10);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AFC00
// Name: public: void CCSBot::OnBombDefuseAbort(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnBombDefuseAbort(CCSBot *this, IGameEvent *event)
{
  int v3; // eax

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    if ( UTIL_PlayerByUserId(userID: v3) != this )
      CBot<CCSPlayer>::PrintIfWatched(this, format: "BOMB DEFUSE ABORTED\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AFC50
// Name: __CreateCServerGameTagsIServerGameTags_interface_17
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_17()
{
  return &_g_CServerGameTags_singleton_17;
}
