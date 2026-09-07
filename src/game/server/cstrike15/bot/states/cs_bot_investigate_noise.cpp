// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_investigate_noise.cpp
// Functions: 5
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_investigate_noise.h"

//------------------------------------------------------------------------------
// Address: 0x102D77E0
// Name: public: virtual void InvestigateNoiseState::OnExit(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InvestigateNoiseState::OnExit(InvestigateNoiseState *this, CCSBot *me)
{
  me->Run(this: me);
}

//------------------------------------------------------------------------------
// Address: 0x102D7800
// Name: private: void InvestigateNoiseState::AttendCurrentNoise(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InvestigateNoiseState::AttendCurrentNoise(InvestigateNoiseState *this, CCSBot *me)
{
  Vector *p_m_noisePosition; // eax
  Vector *v5; // eax
  IUniformRandomStream *v6; // ecx
  CountdownTimer *p_m_minTimer; // edi
  double v8; // st7
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // ebx
  float m_Value; // xmm0_4
  float *p_m_Value; // edi
  float v12; // [esp+14h] [ebp-4h]
  float mea; // [esp+20h] [ebp+8h]

  if ( CCSBot::IsNoiseHeard(this: me) || me->m_noiseTimestamp <= 0.0 || me == (CCSBot *)-14820 )
  {
    if ( me->m_noiseTimestamp <= 0.0 )
      p_m_noisePosition = nullptr;
    else
      p_m_noisePosition = &me->m_noisePosition;
    this->m_checkNoisePosition.x = p_m_noisePosition->x;
    this->m_checkNoisePosition.y = p_m_noisePosition->y;
    this->m_checkNoisePosition.z = p_m_noisePosition->z;
    if ( CCSBot::IsWellPastSafe(this: me)
      && CCSBot::HasNotSeenEnemyForLongTime(this: me)
      && me->m_noisePriority != PRIORITY_HIGH )
    {
      if ( me->m_noiseTimestamp <= 0.0 )
        v5 = nullptr;
      else
        v5 = &me->m_noisePosition;
      BotChatterInterface::HeardNoise(this: &me->m_chatter, pos: v5);
    }
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Attending to noise...\n");
    CCSBot::ComputePath(this: me, goal: &this->m_checkNoisePosition, route: FASTEST_ROUTE);
    mea = _RandomFloat(this: v6, a2: 3.0, a3: 10.0);
    p_m_minTimer = &this->m_minTimer;
    v8 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_minTimer) + mea;
    p_m_timestamp = &this->m_minTimer.m_timestamp;
    if ( p_m_minTimer->m_timestamp.m_Value != v8 )
    {
      p_m_minTimer->NetworkStateChanged(this: p_m_minTimer, a2: &p_m_minTimer->m_timestamp);
      v12 = v8;
      p_m_timestamp->m_Value = v12;
    }
    m_Value = p_m_minTimer->m_duration.m_Value;
    p_m_Value = &p_m_minTimer->m_duration.m_Value;
    if ( m_Value != mea )
    {
      (**((void (__thiscall ***)(int))p_m_Value - 1))(a1: (int)(p_m_Value - 1));
      *p_m_Value = mea;
    }
    me->m_noiseTimestamp = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D7960
// Name: public: virtual void InvestigateNoiseState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InvestigateNoiseState::OnEnter(InvestigateNoiseState *this, CCSBot *me)
{
  InvestigateNoiseState::AttendCurrentNoise(this, me);
}

//------------------------------------------------------------------------------
// Address: 0x102D7970
// Name: public: virtual void InvestigateNoiseState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge InvestigateNoiseState::OnUpdate(InvestigateNoiseState *this@<ecx>, int a2@<edi>, CCSBot *me)
{
  CCSBot *v5; // ecx
  bool IsUsingKnife; // al
  CCSBot *v7; // ecx
  bool IsHurrying; // al
  CCSBot_vtbl *v9; // edx
  int m_nearbyFriendCount; // edi
  int FriendsRemaining; // eax
  Vector myOrigin; // [esp+Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  float range; // [esp+20h] [ebp+8h]

  GetCentroid(result: &myOrigin, player: me);
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_minTimer) > this->m_minTimer.m_timestamp.m_Value
    && CCSBot::HeardInterestingNoise(this: me)
    && CCSBot::IsNoiseHeard(this: me)
    && me->m_noiseTravelDistance < 500.0 )
  {
    InvestigateNoiseState::AttendCurrentNoise(this, me);
  }
  v5 = me;
  if ( me->m_pathLength == 0 )
    goto LABEL_26;
  CCSBot::UpdateLookAround(this: me, a2: COERCE_FLOAT(&savedregs), a3: a2, updateNow: false);
  range = CCSBot::GetPathDistanceRemaining(this: me);
  IsUsingKnife = CCSBot::IsUsingKnife(this: me);
  v7 = me;
  if ( !IsUsingKnife )
  {
    if ( range < 1500.0 )
    {
      m_nearbyFriendCount = me->m_nearbyFriendCount;
      if ( CBot<CCSPlayer>::GetFriendsRemaining(this: me) >= m_nearbyFriendCount )
        FriendsRemaining = m_nearbyFriendCount;
      else
        FriendsRemaining = CBot<CCSPlayer>::GetFriendsRemaining(this: me);
      if ( (FriendsRemaining == 0 || CBot<CCSPlayer>::GetFriendsRemaining(this: me) <= 2)
        && !CCSBot::IsHurrying(this: me) )
      {
        ((void (__fastcall *)(CCSBot *))me->Walk)(a1: me);
        goto LABEL_21;
      }
      v7 = me;
    }
    v9 = me->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
LABEL_20:
    ((void (__fastcall *)(CCSBot *))v9->Run)(a1: v7);
    goto LABEL_21;
  }
  IsHurrying = CCSBot::IsHurrying(this: me);
  v9 = me->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  v7 = me;
  if ( IsHurrying )
    goto LABEL_20;
  ((void (__fastcall *)(CCSBot *))v9->Walk)(a1: me);
LABEL_21:
  if ( range < 500.0
    && CCSBot::IsVisible(this: me, pos: &this->m_checkNoisePosition, testFOV: true, ignore: nullptr) != 0 )
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Noise location is clear.\n");
    me->m_noiseTimestamp = 0.0;
    CCSBot::Idle(this: me);
    return;
  }
  if ( CCSBot::UpdatePathMovement(this: me, a2: (int)&savedregs, allowSpeedChange: true) != 0 )
  {
    v5 = me;
LABEL_26:
    CCSBot::Idle(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D7AE0
// Name: __CreateCServerGameTagsIServerGameTags_interface_47
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_47()
{
  return &_g_CServerGameTags_singleton_47;
}
