// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_event_player.cpp
// Functions: 6
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_event_player.h"

//------------------------------------------------------------------------------
// Address: 0x102AFC60
// Name: public: void CCSBot::OnPlayerFootstep(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnPlayerFootstep(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // eax
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this )
      CCSBot::OnAudibleEvent(
        this,
        a2: COERCE_FLOAT(&savedregs),
        event,
        player: v4,
        range: 1100.0,
        priority: PRIORITY_LOW,
        isHostile: false,
        isFootstep: true,
        actualOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AFCC0
// Name: public: class CCSPlayer __near * CCSBot::GetBotEnemy(void)const
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CCSBot::GetBotEnemy(CCSBot *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_enemy.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x102AFCF0
// Name: public: void CCSBot::OnPlayerRadio(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnPlayerRadio(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CBasePlayer *v4; // edi
  CCSBot *v5; // edi
  int TeamNumber; // ebx
  RadioType v7; // eax
  Vector result; // [esp+4h] [ebp-Ch] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = UTIL_PlayerByUserId(userID: v3);
    if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                       TargetType: &CCSPlayer `RTTI Type Descriptor',
                       isReference: 0);
    else
      v5 = nullptr;
    if ( v5 != this && v5 != nullptr )
    {
      TeamNumber = CBaseEntity::GetTeamNumber(this: v5);
      if ( TeamNumber == CBaseEntity::GetTeamNumber(this) )
      {
        v7 = event->GetInt(this: event, a2: "slot", a3: 0);
        if ( v7 != RADIO_INVALID && v7 != RADIO_AFFIRMATIVE && v7 != RADIO_NEGATIVE && v7 != RADIO_REPORTING_IN )
        {
          this->m_lastRadioCommand = v7;
          this->m_lastRadioRecievedTimestamp = gpGlobals->curtime;
          CHandle<CBaseEntity>::operator=(this: (CHandle<CBaseEntity> *)&this->m_radioSubject, val: v5);
          this->m_radioPosition = *GetCentroid(&result, player: v5);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AFE00
// Name: public: void CCSBot::Hurry(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Hurry(CCSBot *this, float duration)
{
  CountdownTimer *p_m_hurryTimer; // edi
  double v3; // st7
  float v4; // [esp+8h] [ebp-4h]

  p_m_hurryTimer = &this->m_hurryTimer;
  v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_hurryTimer) + duration;
  if ( p_m_hurryTimer->m_timestamp.m_Value != v3 )
  {
    p_m_hurryTimer->NetworkStateChanged(this: p_m_hurryTimer, a2: &p_m_hurryTimer->m_timestamp);
    v4 = v3;
    p_m_hurryTimer->m_timestamp.m_Value = v4;
  }
  if ( p_m_hurryTimer->m_duration.m_Value != duration )
  {
    p_m_hurryTimer->NetworkStateChanged(this: p_m_hurryTimer, a2: &p_m_hurryTimer->m_duration);
    p_m_hurryTimer->m_duration.m_Value = duration;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AFE70
// Name: public: void CCSBot::OnPlayerDeath(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnPlayerDeath(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // ebx
  Vector *p_victimOrigin; // eax
  IGameEvent_vtbl *v6; // edx
  float z; // ecx
  int (__thiscall *GetInt)(IGameEvent *, const char *, int); // eax
  int v9; // eax
  CBasePlayer *v10; // eax
  CCSBot *v11; // edi
  signed int m_pPev; // eax
  int TeamNumber; // ebx
  int v14; // ebx
  CCSPlayer *BotEnemy; // eax
  int v16; // eax
  CBasePlayer *v17; // eax
  CCSPlayer *v18; // edi
  int v19; // ebx
  IUniformRandomStream *v20; // ecx
  IUniformRandomStream *v21; // ecx
  const Vector *AbsOrigin; // eax
  int v23; // ebx
  IUniformRandomStream *v24; // ecx
  IUniformRandomStream *v25; // ecx
  float duration; // [esp+Ch] [ebp-3Ch]
  Vector victimOrigin; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector playerOrigin; // [esp+38h] [ebp-10h] BYREF
  CBasePlayer *player; // [esp+44h] [ebp-4h]
  float delay; // [esp+50h] [ebp+8h]

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    player = v4;
    if ( v4 != this )
    {
      p_victimOrigin = &victimOrigin;
      if ( v4 != nullptr )
        p_victimOrigin = GetCentroid(result: &victimOrigin, player: v4);
      else
        memset((void *)&victimOrigin, 0, sizeof(victimOrigin));
      v6 = event->__vftable;
      *(_QWORD *)&playerOrigin.x = *(_QWORD *)&p_victimOrigin->x;
      z = p_victimOrigin->z;
      GetInt = v6->GetInt;
      playerOrigin.z = z;
      v9 = GetInt(this: event, a2: "attacker", a3: 0);
      v10 = UTIL_PlayerByUserId(userID: v9);
      v11 = (CCSBot *)v10;
      if ( v10 == nullptr || !v10->IsPlayer(this: v10) )
        v11 = nullptr;
      if ( v11 == this )
      {
        m_pPev = (signed int)v4->m_Network.m_pPev;
        if ( m_pPev != 0 )
          m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
        this->m_lastVictimID = m_pPev;
      }
      TeamNumber = CBaseEntity::GetTeamNumber(this: v4);
      if ( TeamNumber == CBaseEntity::GetTeamNumber(this) )
      {
        this->m_friendDeathTimestamp = gpGlobals->curtime;
        if ( v11 != nullptr && !v11->IsBot(this: v11) )
        {
          v14 = CBaseEntity::GetTeamNumber(this: v11);
          if ( v14 == CBaseEntity::GetTeamNumber(this) && v11 != this )
            BotChatterInterface::KilledFriend(this: &this->m_chatter);
        }
        if ( CCSBot::IsAttacking(this) )
        {
          if ( (float)(gpGlobals->curtime - this->m_lastSawEnemyTimestamp) > 0.40000001 )
          {
            CBot<CCSPlayer>::PrintIfWatched(this, format: "Rethinking my attack due to teammate death\n");
            CCSBot::IgnoreEnemies(this, duration: 1.0);
            BotEnemy = CCSBot::GetBotEnemy(this);
            CCSBot::SetTask(this, task: MOVE_TO_LAST_KNOWN_ENEMY_POSITION, entity: BotEnemy);
            CCSBot::MoveTo(this, pos: &this->m_lastEnemyPosition, route: SAFEST_ROUTE);
          }
        }
        else if ( CCSBot::GetDisposition(this) == ENGAGE_AND_INVESTIGATE
               || CCSBot::GetDisposition(this) == OPPORTUNITY_FIRE )
        {
          v16 = event->GetInt(this: event, a2: "attacker", a3: 0);
          v17 = UTIL_PlayerByUserId(userID: v16);
          v18 = (CCSPlayer *)v17;
          if ( v17 != nullptr && v17->IsPlayer(this: v17) )
          {
            v19 = CBaseEntity::GetTeamNumber(this: v18);
            if ( v19 != CBaseEntity::GetTeamNumber(this) )
            {
              if ( CCSBot::IsSniper(this)
                || !CCSBot::IsVisible(this, pos: &playerOrigin, testFOV: false, ignore: nullptr)
                || (duration = _RandomFloat(this: v20, a2: 10.0, a3: 15.0),
                    CCSBot::Hurry(this, duration),
                    CCSBot::IsHiding(this))
                && CCSBot::IsUsingKnife(this)
                && _RandomFloat(this: v21, a2: 0.0, a3: 100.0) >= 50.0 )
              {
                if ( (CCSBot::IsHunting(this)
                   || CCSBot::IsInvestigatingNoise(this)
                   || CCSBot::IsHiding(this) && this->m_task != FOLLOW && CCSBot::GetHidingTime(this) > 20.0)
                  && (float)(gpGlobals->curtime - this->m_lastSawEnemyTimestamp) > 10.0 )
                {
                  AbsOrigin = CBaseEntity::GetAbsOrigin(this);
                  if ( (float)((float)((float)((float)(playerOrigin.x - AbsOrigin->x)
                                             * (float)(playerOrigin.x - AbsOrigin->x))
                                     + (float)((float)(playerOrigin.y - AbsOrigin->y)
                                             * (float)(playerOrigin.y - AbsOrigin->y)))
                             + (float)((float)(playerOrigin.z - AbsOrigin->z) * (float)(playerOrigin.z - AbsOrigin->z))) > 562500.0 )
                  {
                    CBot<CCSPlayer>::PrintIfWatched(this, format: "Checking out where our friend was killed\n");
                    CCSBot::MoveTo(this, pos: &playerOrigin, route: FASTEST_ROUTE);
                  }
                }
              }
              else
              {
                CBot<CCSPlayer>::PrintIfWatched(this, format: "Attacking our friend's killer!\n");
                CCSBot::Attack(this, victim: v18);
              }
            }
          }
        }
      }
      else
      {
        this->m_noiseTimestamp = 0.0;
        if ( v11 != nullptr )
        {
          v23 = CBaseEntity::GetTeamNumber(this: v11);
          if ( v23 == CBaseEntity::GetTeamNumber(this) && CCSBot::GetNearbyEnemyCount(this) <= 1 )
          {
            BotChatterInterface::EnemiesRemaining(this: &this->m_chatter);
            GetCentroid(result: &victimOrigin, player);
            if ( CCSBot::IsVisible(this, pos: &victimOrigin, testFOV: true, ignore: nullptr) && v11 != this )
            {
              delay = _RandomFloat(this: v24, a2: 2.0, a3: 3.0);
              if ( v11->IsBot(this: v11) )
              {
                if ( _RandomFloat(this: v25, a2: 0.0, a3: 100.0) < 40.0 )
                  BotChatterInterface::Say(this: &this->m_chatter, phraseName: "NiceShot", lifetime: 3.0, delay);
              }
              else
              {
                BotChatterInterface::Say(this: &this->m_chatter, phraseName: "NiceShotSir", lifetime: 3.0, delay);
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B0350
// Name: __CreateCServerGameTagsIServerGameTags_interface_18
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_18()
{
  return &_g_CServerGameTags_singleton_18;
}
