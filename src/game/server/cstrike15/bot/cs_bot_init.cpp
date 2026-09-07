// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_init.cpp
// Functions: 26
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_init.h"

//------------------------------------------------------------------------------
// Address: 0x102B0630
// Name: public: virtual char const __near * IdleState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IdleState::GetName(IdleState *this)
{
  return "Idle";
}

//------------------------------------------------------------------------------
// Address: 0x102B0640
// Name: public: virtual char const __near * HuntState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall HuntState::GetName(HuntState *this)
{
  return "Hunt";
}

//------------------------------------------------------------------------------
// Address: 0x102B0650
// Name: public: virtual char const __near * BuyState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall BuyState::GetName(BuyState *this)
{
  return "Buy";
}

//------------------------------------------------------------------------------
// Address: 0x102B0660
// Name: public: virtual char const __near * MoveToState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall MoveToState::GetName(MoveToState *this)
{
  return "MoveTo";
}

//------------------------------------------------------------------------------
// Address: 0x102B0670
// Name: public: virtual char const __near * FetchBombState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall FetchBombState::GetName(FetchBombState *this)
{
  return "FetchBomb";
}

//------------------------------------------------------------------------------
// Address: 0x102B0680
// Name: public: virtual char const __near * PlantBombState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall PlantBombState::GetName(PlantBombState *this)
{
  return "PlantBomb";
}

//------------------------------------------------------------------------------
// Address: 0x102B0690
// Name: public: virtual char const __near * DefuseBombState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DefuseBombState::GetName(DefuseBombState *this)
{
  return "DefuseBomb";
}

//------------------------------------------------------------------------------
// Address: 0x102B06A0
// Name: public: virtual char const __near * EscapeFromBombState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall EscapeFromBombState::GetName(EscapeFromBombState *this)
{
  return "EscapeFromBomb";
}

//------------------------------------------------------------------------------
// Address: 0x102B06B0
// Name: public: virtual char const __near * UseEntityState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall UseEntityState::GetName(UseEntityState *this)
{
  return "UseEntity";
}

//------------------------------------------------------------------------------
// Address: 0x102B0760
// Name: PrefixChanged
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrefixChanged()
{
  int i; // edi
  CBasePlayer *v1; // eax
  _DWORD *v2; // esi
  int v3; // eax
  const BotProfile **v4; // eax
  const BotProfile **v5; // esi
  char botName[32]; // [esp+0h] [ebp-20h] BYREF

  if ( TheBots != nullptr && LOBYTE(TheBots[1].__vftable) != 0 )
  {
    for ( i = 1; i <= gpGlobals->maxClients; ++i )
    {
      v1 = UTIL_PlayerByIndex(playerIndex: i);
      v2 = &v1->__vftable;
      if ( v1 != nullptr && v1->IsBot(this: v1) )
      {
        v3 = v2[6];
        if ( v3 != 0 && (signed int)(v3 - (unsigned int)gpGlobals->pEdicts) >> 4 != 0 )
        {
          v4 = (const BotProfile **)__RTDynamicCast(
                                      inptr: v2,
                                      VfDelta: 0,
                                      SrcType: &CBasePlayer `RTTI Type Descriptor',
                                      TargetType: &CCSBot `RTTI Type Descriptor',
                                      isReference: 0);
          v5 = v4;
          if ( v4 != nullptr )
          {
            UTIL_ConstructBotNetName(name: botName, nameLength: 32, profile: v4[1768]);
            engine->SetFakeClientConVarValue(this: engine, a2: (edict_t *)v5[6], a3: "name", a4: botName);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B0830
// Name: public: AttackState::AttackState(void)
// Source: json
//------------------------------------------------------------------------------
AttackState *__thiscall AttackState::AttackState(AttackState *this)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *p_m_duration; // eax
  CountdownTimer *p_m_repathTimer; // ecx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx

  p_m_duration = &this->m_repathTimer.m_duration;
  this->__vftable = (AttackState_vtbl *)&AttackState::`vftable';
  p_m_repathTimer = &this->m_repathTimer;
  this->m_repathTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = p_m_repathTimer->__vftable;
  p_m_duration->m_Value = 0.0;
  v4->NetworkStateChanged(this: p_m_repathTimer, a2: p_m_duration);
  v5 = this->m_repathTimer.__vftable;
  this->m_repathTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_repathTimer, a2: &this->m_repathTimer.m_timestamp);
  this->m_retreatTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v6 = this->m_retreatTimer.__vftable;
  this->m_retreatTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v6->NetworkStateChanged)(a1: &this->m_retreatTimer.m_duration);
  v7 = this->m_retreatTimer.__vftable;
  this->m_retreatTimer.m_timestamp.m_Value = -1.0;
  v7->NetworkStateChanged(this: &this->m_retreatTimer, a2: &this->m_retreatTimer.m_timestamp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102B08B0
// Name: public: virtual char const __near * AttackState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall AttackState::GetName(AttackState *this)
{
  return "Attack";
}

//------------------------------------------------------------------------------
// Address: 0x102B08C0
// Name: public: virtual char const __near * InvestigateNoiseState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall InvestigateNoiseState::GetName(InvestigateNoiseState *this)
{
  return "InvestigateNoise";
}

//------------------------------------------------------------------------------
// Address: 0x102B08D0
// Name: public: HideState::HideState(void)
// Source: json
//------------------------------------------------------------------------------
HideState *__thiscall HideState::HideState(HideState *this)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *p_m_duration; // eax
  CountdownTimer *p_m_hideTimer; // ecx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx

  p_m_duration = &this->m_hideTimer.m_duration;
  this->__vftable = (HideState_vtbl *)&HideState::`vftable';
  p_m_hideTimer = &this->m_hideTimer;
  this->m_hideTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = p_m_hideTimer->__vftable;
  p_m_duration->m_Value = 0.0;
  v4->NetworkStateChanged(this: p_m_hideTimer, a2: p_m_duration);
  v5 = this->m_hideTimer.__vftable;
  this->m_hideTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_hideTimer, a2: &this->m_hideTimer.m_timestamp);
  this->m_pauseTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v6 = this->m_pauseTimer.__vftable;
  this->m_pauseTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v6->NetworkStateChanged)(a1: &this->m_pauseTimer.m_duration);
  v7 = this->m_pauseTimer.__vftable;
  this->m_pauseTimer.m_timestamp.m_Value = -1.0;
  v7->NetworkStateChanged(this: &this->m_pauseTimer, a2: &this->m_pauseTimer.m_timestamp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102B0950
// Name: public: virtual char const __near * HideState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall HideState::GetName(HideState *this)
{
  return "Hide";
}

//------------------------------------------------------------------------------
// Address: 0x102B0960
// Name: public: FollowState::FollowState(void)
// Source: json
//------------------------------------------------------------------------------
FollowState *__thiscall FollowState::FollowState(FollowState *this)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // eax
  IntervalTimer *p_m_leaderMotionStateTime; // ecx
  IntervalTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  IntervalTimer_vtbl *v7; // edx
  CountdownTimer_vtbl *v8; // edx
  CountdownTimer_vtbl *v9; // edx

  p_m_timestamp = &this->m_leaderMotionStateTime.m_timestamp;
  this->__vftable = (FollowState_vtbl *)&FollowState::`vftable';
  this->m_leader.m_Index = -1;
  p_m_leaderMotionStateTime = &this->m_leaderMotionStateTime;
  this->m_leaderMotionStateTime.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v4 = p_m_leaderMotionStateTime->__vftable;
  p_m_timestamp->m_Value = -1.0;
  v4->NetworkStateChanged(this: p_m_leaderMotionStateTime, a2: p_m_timestamp);
  this->m_repathInterval.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v5 = this->m_repathInterval.__vftable;
  this->m_repathInterval.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v5->NetworkStateChanged)(a1: &this->m_repathInterval.m_duration);
  v6 = this->m_repathInterval.__vftable;
  this->m_repathInterval.m_timestamp.m_Value = -1.0;
  v6->NetworkStateChanged(this: &this->m_repathInterval, a2: &this->m_repathInterval.m_timestamp);
  this->m_walkTime.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v7 = this->m_walkTime.__vftable;
  this->m_walkTime.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v7->NetworkStateChanged)(a1: &this->m_walkTime.m_timestamp);
  this->m_idleTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v8 = this->m_idleTimer.__vftable;
  this->m_idleTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v8->NetworkStateChanged)(a1: &this->m_idleTimer.m_duration);
  v9 = this->m_idleTimer.__vftable;
  this->m_idleTimer.m_timestamp.m_Value = -1.0;
  v9->NetworkStateChanged(this: &this->m_idleTimer, a2: &this->m_idleTimer.m_timestamp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102B0A20
// Name: public: virtual char const __near * FollowState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall FollowState::GetName(FollowState *this)
{
  return "Follow";
}

//------------------------------------------------------------------------------
// Address: 0x102B0A30
// Name: public: virtual char const __near * OpenDoorState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall OpenDoorState::GetName(OpenDoorState *this)
{
  return "OpenDoor";
}

//------------------------------------------------------------------------------
// Address: 0x102B0A40
// Name: public: virtual char const __near * EscapeFromFlamesState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall EscapeFromFlamesState::GetName(EscapeFromFlamesState *this)
{
  return "EscapeFromFlames";
}

//------------------------------------------------------------------------------
// Address: 0x102B0A50
// Name: private: void CCSBot::ResetValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ResetValues(CCSBot *this)
{
  IUniformRandomStream *m_playerTravelDistance; // ecx
  bool *p_isEnemy; // eax
  int i; // edx
  double v5; // st7
  int *p_m_validFrame; // eax
  unsigned int v7; // eax
  float v8; // xmm0_4
  void (__thiscall *StandUp)(CBot<CCSPlayer> *); // eax
  bool *p_isReloading; // eax
  int j; // ecx
  __int64 v12; // [esp+38h] [ebp-14h]
  float z; // [esp+40h] [ebp-Ch]
  float v14; // [esp+44h] [ebp-8h]
  const Vector *v15; // [esp+44h] [ebp-8h]
  float v16; // [esp+48h] [ebp-4h]
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  BotChatterInterface::Reset(this: &this->m_chatter);
  CSGameState::Reset(this: &this->m_gameState);
  this->m_avoid.m_Index = -1;
  this->m_avoidTimestamp = 0.0;
  if ( this->m_hurryTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_hurryTimer.NetworkStateChanged(this: &this->m_hurryTimer, a2: &this->m_hurryTimer.m_timestamp);
    this->m_hurryTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_alertTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_alertTimer.NetworkStateChanged(this: &this->m_alertTimer, a2: &this->m_alertTimer.m_timestamp);
    this->m_alertTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_sneakTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_sneakTimer.NetworkStateChanged(this: &this->m_sneakTimer, a2: &this->m_sneakTimer.m_timestamp);
    this->m_sneakTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_noiseBendTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_noiseBendTimer.NetworkStateChanged(this: &this->m_noiseBendTimer, a2: &this->m_noiseBendTimer.m_timestamp);
    this->m_noiseBendTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_bendNoisePositionValid = false;
  this->m_isStuck = false;
  this->m_stuckTimestamp = 0.0;
  if ( this->m_wiggleTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_wiggleTimer.NetworkStateChanged(this: &this->m_wiggleTimer, a2: &this->m_wiggleTimer.m_timestamp);
    this->m_wiggleTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_stuckJumpTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_stuckJumpTimer.NetworkStateChanged(this: &this->m_stuckJumpTimer, a2: &this->m_stuckJumpTimer.m_timestamp);
    this->m_stuckJumpTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_pathLength = 0;
  this->m_pathIndex = 0;
  this->m_areaEnteredTimestamp = 0.0;
  this->m_currentArea = nullptr;
  this->m_lastKnownArea = nullptr;
  this->m_isStopping = false;
  if ( this->m_avoidFriendTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_avoidFriendTimer.NetworkStateChanged(
      this: &this->m_avoidFriendTimer,
      a2: &this->m_avoidFriendTimer.m_timestamp);
    this->m_avoidFriendTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_isFriendInTheWay = false;
  this->m_isWaitingBehindFriend = false;
  if ( this->m_isAvoidingGrenade.m_timestamp.m_Value != -1.0 )
  {
    this->m_isAvoidingGrenade.NetworkStateChanged(
      this: &this->m_isAvoidingGrenade,
      a2: &this->m_isAvoidingGrenade.m_timestamp);
    this->m_isAvoidingGrenade.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_panicTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_panicTimer.NetworkStateChanged(this: &this->m_panicTimer, a2: &this->m_panicTimer.m_timestamp);
    this->m_panicTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_disposition = ENGAGE_AND_INVESTIGATE;
  this->m_enemy.m_Index = -1;
  this->m_grenadeTossState = NOT_THROWING;
  this->m_initialEncounterArea = nullptr;
  this->m_wasSafe = true;
  this->m_nearbyEnemyCount = 0;
  this->m_enemyPlace = 0;
  this->m_nearbyFriendCount = 0;
  this->m_closestVisibleFriend.m_Index = -1;
  this->m_closestVisibleHumanFriend.m_Index = -1;
  m_playerTravelDistance = (IUniformRandomStream *)this->m_playerTravelDistance;
  p_isEnemy = &this->m_watchInfo[0].isEnemy;
  for ( i = 64; i != 0; --i )
  {
    *((_DWORD *)p_isEnemy - 1) = 0;
    *p_isEnemy = false;
    m_playerTravelDistance->__vftable = (IUniformRandomStream_vtbl *)-1082130432;
    ++m_playerTravelDistance;
    p_isEnemy += 8;
  }
  v16 = _RandomFloat(this: m_playerTravelDistance, a2: 0.0, a3: 0.89999998);
  v5 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_updateTravelDistanceTimer) + v16;
  if ( this->m_updateTravelDistanceTimer.m_timestamp.m_Value != v5 )
  {
    this->m_updateTravelDistanceTimer.NetworkStateChanged(
      this: &this->m_updateTravelDistanceTimer,
      a2: &this->m_updateTravelDistanceTimer.m_timestamp);
    v14 = v5;
    this->m_updateTravelDistanceTimer.m_timestamp.m_Value = v14;
  }
  if ( this->m_updateTravelDistanceTimer.m_duration.m_Value != v16 )
  {
    this->m_updateTravelDistanceTimer.NetworkStateChanged(
      this: &this->m_updateTravelDistanceTimer,
      a2: &this->m_updateTravelDistanceTimer.m_duration);
    this->m_updateTravelDistanceTimer.m_duration.m_Value = v16;
  }
  this->m_lastSawEnemyTimestamp = -999.90002;
  this->m_travelDistancePhase = 0;
  *(_WORD *)&this->m_isEnemyVisible = 0;
  this->m_firstSawEnemyTimestamp = 0.0;
  this->m_currentEnemyAcquireTimestamp = 0.0;
  this->m_isLastEnemyDead = true;
  this->m_attacker.m_Index = -1;
  this->m_attackedTimestamp = 0.0;
  this->m_enemyDeathTimestamp = 0.0;
  this->m_friendDeathTimestamp = 0.0;
  this->m_lastVictimID = 0;
  this->m_isAimingAtEnemy = false;
  this->m_fireWeaponTimestamp = 0.0;
  if ( this->m_equipTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_equipTimer.NetworkStateChanged(this: &this->m_equipTimer, a2: &this->m_equipTimer.m_timestamp);
    this->m_equipTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_zoomTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_zoomTimer.NetworkStateChanged(this: &this->m_zoomTimer, a2: &this->m_zoomTimer.m_timestamp);
    this->m_zoomTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_isFollowing = false;
  this->m_leader.m_Index = -1;
  this->m_followTimestamp = 0.0;
  this->m_allowAutoFollowTime = 0.0;
  *(_WORD *)&this->m_enemyQueueIndex = 0;
  this->m_enemyQueueAttendIndex = 0;
  this->m_bomber.m_Index = -1;
  this->m_isEnemySniperVisible = false;
  if ( this->m_sawEnemySniperTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_sawEnemySniperTimer.NetworkStateChanged(
      this: &this->m_sawEnemySniperTimer,
      a2: &this->m_sawEnemySniperTimer.m_timestamp);
    this->m_sawEnemySniperTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_lookAroundStateTimestamp = 0.0;
  this->m_inhibitLookAroundTimestamp = 0.0;
  this->m_lookPitch = 0.0;
  this->m_lookPitchVel = 0.0;
  this->m_lookYaw = 0.0;
  this->m_lookYawVel = 0.0;
  this->m_aimOffsetTimestamp = 0.0;
  this->m_aimSpreadTimestamp = 0.0;
  this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
  p_m_validFrame = &CCSBot::m_partInfo[0].m_validFrame;
  do
  {
    *p_m_validFrame = 0;
    p_m_validFrame += 16;
  }
  while ( (int)p_m_validFrame < (int)&freePos[3] );
  v7 = (unsigned int)this->m_iEFlags >> 11;
  this->m_spotEncounter = nullptr;
  this->m_spotCheckTimestamp = 0.0;
  this->m_peripheralTimestamp = 0.0;
  this->m_avgVelIndex = 0;
  this->m_avgVelCount = 0;
  if ( (v7 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  v12 = *(_QWORD *)&this->m_vecAbsOrigin.x;
  v15 = this->m_Collision.OBBMins(this: &this->m_Collision);
  v8 = (float)((float)(this->m_Collision.OBBMaxs(this: &this->m_Collision)->z - v15->z) * 0.5) + z;
  LODWORD(this->m_lastOrigin.x) = v12;
  this->m_lastOrigin.z = v8;
  this->m_lastOrigin.y = *((float *)&v12 + 1);
  this->m_lastRadioCommand = RADIO_INVALID;
  this->m_lastRadioRecievedTimestamp = 0.0;
  this->m_lastRadioSentTimestamp = 0.0;
  this->m_radioSubject.m_Index = -1;
  this->m_voiceEndTimestamp = 0.0;
  this->m_hostageEscortCount = 0;
  this->m_hostageEscortCountTimestamp = 0.0;
  this->m_noisePosition.x = 0.0;
  this->m_noisePosition.y = 0.0;
  this->m_noisePosition.z = 0.0;
  this->m_noiseTimestamp = 0.0;
  this->m_stateTimestamp = 0.0;
  this->m_task = SEEK_AND_DESTROY;
  this->m_taskEntity.m_Index = -1;
  StandUp = this->StandUp;
  this->m_approachPointCount = 0;
  this->m_approachPointViewPosition.x = 9.9999998e10;
  this->m_approachPointViewPosition.y = 0.0;
  this->m_approachPointViewPosition.z = 0.0;
  this->m_checkedHidingSpotCount = 0;
  StandUp(this);
  this->Run(this);
  if ( this->m_mustRunTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_mustRunTimer.NetworkStateChanged(this: &this->m_mustRunTimer, a2: &this->m_mustRunTimer.m_timestamp);
    this->m_mustRunTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_waitTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_waitTimer.NetworkStateChanged(this: &this->m_waitTimer, a2: &this->m_waitTimer.m_timestamp);
    this->m_waitTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_pathLadder = nullptr;
  if ( this->m_repathTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_repathTimer.NetworkStateChanged(this: &this->m_repathTimer, a2: &this->m_repathTimer.m_timestamp);
    this->m_repathTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_huntState.m_huntArea = nullptr;
  this->m_hasVisitedEnemySpawn = false;
  if ( this->m_stillTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_stillTimer.NetworkStateChanged(this: &this->m_stillTimer, a2: &this->m_stillTimer.m_timestamp);
    this->m_stillTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_diedLastRound )
    CCSBot::DecreaseMorale(this);
  this->m_diedLastRound = false;
  this->m_isRogue = false;
  if ( this->m_surpriseTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_surpriseTimer.NetworkStateChanged(this: &this->m_surpriseTimer, a2: &this->m_surpriseTimer.m_timestamp);
    this->m_surpriseTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_goalEntity.m_Index = -1;
  this->m_avoid.m_Index = -1;
  this->m_enemy.m_Index = -1;
  p_isReloading = &this->m_enemyQueue[0].isReloading;
  for ( j = 20; j != 0; --j )
  {
    *((_DWORD *)p_isReloading - 1) = -1;
    *(_WORD *)p_isReloading = 0;
    p_isReloading += 8;
  }
  if ( this->m_burnedByFlamesTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_burnedByFlamesTimer.NetworkStateChanged(
      this: &this->m_burnedByFlamesTimer,
      a2: &this->m_burnedByFlamesTimer.m_timestamp);
    this->m_burnedByFlamesTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_isOpeningDoor = false;
  CCSBot::StopAttacking(this);
  CCSBot::Idle(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B11E0
// Name: public: virtual void CCSBot::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Spawn(CCSBot *this)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl

  CBot<CCSPlayer>::Spawn(this);
  CCSBot::ResetValues(this);
  v2 = (char *)this->GetPlayerName(this);
  v3 = (char *)(this->m_name - v2);
  do
  {
    v4 = *v2;
    v2[(_DWORD)v3] = *v2;
    ++v2;
  }
  while ( v4 != 0 );
  CCSBot::Buy(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B1220
// Name: public: virtual bool CCSBot::Initialize(class BotProfile const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __userpurge CCSBot::Initialize@<al>(CCSBot *this@<ecx>, __int64 a2@<esi:edi>, const BotProfile *profile, int team)
{
  HIDWORD(a2) = this;
  this->m_profile = profile;
  this->m_diedLastRound = false;
  this->m_morale = POSITIVE;
  this->m_combatRange = _RandomFloat((IUniformRandomStream *)this, a2: 325.0, a3: 425.0);
  *(float *)(HIDWORD(a2) + 7328) = (float)(*(float *)(*(_DWORD *)(HIDWORD(a2) + 7072) + 4) * 5.0) + 15.0;
  *(_BYTE *)(HIDWORD(a2) + 7236) = 0;
  CCSBot::ResetValues(this: (CCSBot *)HIDWORD(a2));
  *(_DWORD *)(HIDWORD(a2) + 14788) = team;
  if ( CBaseEntity::GetTeamNumber(this: (CBaseEntity *)HIDWORD(a2)) == 0 )
  {
    CCSPlayer::HandleCommand_JoinTeam(this: (CCSPlayer *)HIDWORD(a2), team: *(_DWORD *)(HIDWORD(a2) + 14788));
    CCSPlayer::HandleCommand_JoinClass(this: (CCSPlayer *)HIDWORD(a2), a2);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102B17A0
// Name: public: CCSBot::CCSBot(void)
// Source: json
//------------------------------------------------------------------------------
CCSBot *__thiscall CCSBot::CCSBot(CCSBot *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx
  CountdownTimer_vtbl *v8; // edx
  CountdownTimer_vtbl *v9; // edx
  CountdownTimer_vtbl *v10; // edx
  CountdownTimer_vtbl *v11; // edx
  CountdownTimer_vtbl *v12; // edx
  CountdownTimer_vtbl *v13; // edx
  CountdownTimer_vtbl *v14; // edx
  CountdownTimer_vtbl *v15; // edx
  CountdownTimer_vtbl *v16; // edx
  CountdownTimer_vtbl *v17; // edx
  CountdownTimer_vtbl *v18; // edx
  IntervalTimer_vtbl *v19; // edx
  CountdownTimer_vtbl *v20; // edx
  CountdownTimer_vtbl *v21; // edx
  CountdownTimer_vtbl *v22; // edx
  CountdownTimer_vtbl *v23; // edx
  CountdownTimer_vtbl *v24; // edx
  CountdownTimer_vtbl *v25; // edx
  CountdownTimer_vtbl *v26; // edx
  CountdownTimer_vtbl *v27; // edx
  CountdownTimer_vtbl *v28; // edx
  CountdownTimer_vtbl *v29; // edx
  CountdownTimer_vtbl *v30; // edx
  CountdownTimer_vtbl *v31; // edx
  CountdownTimer_vtbl *v32; // edx
  CountdownTimer_vtbl *v33; // edx
  CountdownTimer_vtbl *v34; // edx
  CountdownTimer_vtbl *v35; // edx
  IntervalTimer_vtbl *v36; // edx
  CountdownTimer_vtbl *v37; // edx
  CountdownTimer_vtbl *v38; // edx
  CountdownTimer_vtbl *v39; // edx
  CountdownTimer_vtbl *v40; // edx
  CountdownTimer_vtbl *v41; // edx
  CountdownTimer_vtbl *v42; // edx
  IntervalTimer_vtbl *v43; // edx
  IntervalTimer_vtbl *v44; // edx
  IntervalTimer_vtbl *v45; // edx
  CountdownTimer_vtbl *v46; // edx
  CountdownTimer_vtbl *v47; // edx
  CountdownTimer_vtbl *v48; // edx
  CountdownTimer_vtbl *v49; // edx
  CCSBot::ReactionState *m_enemyQueue; // eax
  int i; // ecx
  CountdownTimer_vtbl *v52; // edx
  CountdownTimer_vtbl *v53; // edx
  CountdownTimer_vtbl *v54; // edx
  CountdownTimer_vtbl *v55; // edx

  CBot<CCSPlayer>::CBot<CCSPlayer>(this);
  this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CCSBot_vtbl *)&CCSBot::`vftable'{for `CBasePlayer'};
  this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CCSBot::`vftable'{for `CAI_ExpresserSink'};
  this->CBot<CCSPlayer>::CCSPlayer::ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&CCSBot::`vftable';
  this->m_rogueTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_rogueTimer.__vftable;
  this->m_rogueTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_rogueTimer.m_duration);
  v3 = this->m_rogueTimer.__vftable;
  this->m_rogueTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_rogueTimer, a2: &this->m_rogueTimer.m_timestamp);
  this->m_surpriseTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = this->m_surpriseTimer.__vftable;
  this->m_surpriseTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v4->NetworkStateChanged)(a1: &this->m_surpriseTimer.m_duration);
  v5 = this->m_surpriseTimer.__vftable;
  this->m_surpriseTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_surpriseTimer, a2: &this->m_surpriseTimer.m_timestamp);
  this->m_leader.m_Index = -1;
  this->m_hurryTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v6 = this->m_hurryTimer.__vftable;
  this->m_hurryTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v6->NetworkStateChanged)(a1: &this->m_hurryTimer.m_duration);
  v7 = this->m_hurryTimer.__vftable;
  this->m_hurryTimer.m_timestamp.m_Value = -1.0;
  v7->NetworkStateChanged(this: &this->m_hurryTimer, a2: &this->m_hurryTimer.m_timestamp);
  this->m_alertTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v8 = this->m_alertTimer.__vftable;
  this->m_alertTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v8->NetworkStateChanged)(a1: &this->m_alertTimer.m_duration);
  v9 = this->m_alertTimer.__vftable;
  this->m_alertTimer.m_timestamp.m_Value = -1.0;
  v9->NetworkStateChanged(this: &this->m_alertTimer, a2: &this->m_alertTimer.m_timestamp);
  this->m_sneakTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v10 = this->m_sneakTimer.__vftable;
  this->m_sneakTimer.m_duration.m_Value = 0.0;
  v10->NetworkStateChanged(this: &this->m_sneakTimer, a2: &this->m_sneakTimer.m_duration);
  v11 = this->m_sneakTimer.__vftable;
  this->m_sneakTimer.m_timestamp.m_Value = -1.0;
  v11->NetworkStateChanged(this: &this->m_sneakTimer, a2: &this->m_sneakTimer.m_timestamp);
  this->m_panicTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v12 = this->m_panicTimer.__vftable;
  this->m_panicTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v12->NetworkStateChanged)(a1: &this->m_panicTimer.m_duration);
  v13 = this->m_panicTimer.__vftable;
  this->m_panicTimer.m_timestamp.m_Value = -1.0;
  v13->NetworkStateChanged(this: &this->m_panicTimer, a2: &this->m_panicTimer.m_timestamp);
  this->m_idleState.__vftable = (IdleState_vtbl *)&IdleState::`vftable';
  this->m_huntState.__vftable = (HuntState_vtbl *)&HuntState::`vftable';
  AttackState::AttackState(this: &this->m_attackState);
  this->m_investigateNoiseState.__vftable = (InvestigateNoiseState_vtbl *)&InvestigateNoiseState::`vftable';
  this->m_investigateNoiseState.m_minTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v14 = this->m_investigateNoiseState.m_minTimer.__vftable;
  this->m_investigateNoiseState.m_minTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v14->NetworkStateChanged)(a1: &this->m_investigateNoiseState.m_minTimer.m_duration);
  v15 = this->m_investigateNoiseState.m_minTimer.__vftable;
  this->m_investigateNoiseState.m_minTimer.m_timestamp.m_Value = -1.0;
  v15->NetworkStateChanged(
    this: &this->m_investigateNoiseState.m_minTimer,
    a2: &this->m_investigateNoiseState.m_minTimer.m_timestamp);
  this->m_buyState.__vftable = (BuyState_vtbl *)&BuyState::`vftable';
  this->m_moveToState.__vftable = (MoveToState_vtbl *)&MoveToState::`vftable';
  this->m_fetchBombState.__vftable = (FetchBombState_vtbl *)&FetchBombState::`vftable';
  this->m_plantBombState.__vftable = (PlantBombState_vtbl *)&PlantBombState::`vftable';
  this->m_defuseBombState.__vftable = (DefuseBombState_vtbl *)&DefuseBombState::`vftable';
  HideState::HideState(this: &this->m_hideState);
  this->m_escapeFromBombState.__vftable = (EscapeFromBombState_vtbl *)&EscapeFromBombState::`vftable';
  FollowState::FollowState(this: &this->m_followState);
  this->m_useEntityState.__vftable = (UseEntityState_vtbl *)&UseEntityState::`vftable';
  this->m_useEntityState.m_entity.m_Index = -1;
  this->m_openDoorState.__vftable = (OpenDoorState_vtbl *)&OpenDoorState::`vftable';
  this->m_openDoorState.m_funcDoor.m_Index = -1;
  this->m_openDoorState.m_propDoor.m_Index = -1;
  this->m_openDoorState.m_timeout.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v16 = this->m_openDoorState.m_timeout.__vftable;
  this->m_openDoorState.m_timeout.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v16->NetworkStateChanged)(a1: &this->m_openDoorState.m_timeout.m_duration);
  this->m_openDoorState.m_timeout.m_timestamp.m_Value = -1.0;
  this->m_openDoorState.m_timeout.NetworkStateChanged(
    this: &this->m_openDoorState.m_timeout,
    a2: &this->m_openDoorState.m_timeout.m_timestamp);
  this->m_escapeFromFlamesState.__vftable = (EscapeFromFlamesState_vtbl *)&EscapeFromFlamesState::`vftable';
  this->m_escapeFromFlamesState.m_searchTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v17 = this->m_escapeFromFlamesState.m_searchTimer.__vftable;
  this->m_escapeFromFlamesState.m_searchTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v17->NetworkStateChanged)(a1: &this->m_escapeFromFlamesState.m_searchTimer.m_duration);
  v18 = this->m_escapeFromFlamesState.m_searchTimer.__vftable;
  this->m_escapeFromFlamesState.m_searchTimer.m_timestamp.m_Value = -1.0;
  v18->NetworkStateChanged(
    this: &this->m_escapeFromFlamesState.m_searchTimer,
    a2: &this->m_escapeFromFlamesState.m_searchTimer.m_timestamp);
  this->m_taskEntity.m_Index = -1;
  this->m_goalEntity.m_Index = -1;
  this->m_avoid.m_Index = -1;
  this->m_stillTimer.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v19 = this->m_stillTimer.__vftable;
  this->m_stillTimer.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v19->NetworkStateChanged)(a1: &this->m_stillTimer.m_timestamp);
  this->m_repathTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v20 = this->m_repathTimer.__vftable;
  this->m_repathTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v20->NetworkStateChanged)(a1: &this->m_repathTimer.m_duration);
  v21 = this->m_repathTimer.__vftable;
  this->m_repathTimer.m_timestamp.m_Value = -1.0;
  v21->NetworkStateChanged(this: &this->m_repathTimer, a2: &this->m_repathTimer.m_timestamp);
  this->m_avoidFriendTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v22 = this->m_avoidFriendTimer.__vftable;
  this->m_avoidFriendTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v22->NetworkStateChanged)(a1: &this->m_avoidFriendTimer.m_duration);
  v23 = this->m_avoidFriendTimer.__vftable;
  this->m_avoidFriendTimer.m_timestamp.m_Value = -1.0;
  v23->NetworkStateChanged(this: &this->m_avoidFriendTimer, a2: &this->m_avoidFriendTimer.m_timestamp);
  this->m_politeTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v24 = this->m_politeTimer.__vftable;
  this->m_politeTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v24->NetworkStateChanged)(a1: &this->m_politeTimer.m_duration);
  this->m_politeTimer.m_timestamp.m_Value = -1.0;
  this->m_politeTimer.NetworkStateChanged(this: &this->m_politeTimer, a2: &this->m_politeTimer.m_timestamp);
  this->m_mustRunTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v25 = this->m_mustRunTimer.__vftable;
  this->m_mustRunTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v25->NetworkStateChanged)(a1: &this->m_mustRunTimer.m_duration);
  v26 = this->m_mustRunTimer.__vftable;
  this->m_mustRunTimer.m_timestamp.m_Value = -1.0;
  v26->NetworkStateChanged(this: &this->m_mustRunTimer, a2: &this->m_mustRunTimer.m_timestamp);
  this->m_waitTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v27 = this->m_waitTimer.__vftable;
  this->m_waitTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v27->NetworkStateChanged)(a1: &this->m_waitTimer.m_duration);
  v28 = this->m_waitTimer.__vftable;
  this->m_waitTimer.m_timestamp.m_Value = -1.0;
  v28->NetworkStateChanged(this: &this->m_waitTimer, a2: &this->m_waitTimer.m_timestamp);
  this->m_updateTravelDistanceTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v29 = this->m_updateTravelDistanceTimer.__vftable;
  this->m_updateTravelDistanceTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v29->NetworkStateChanged)(a1: &this->m_updateTravelDistanceTimer.m_duration);
  v30 = this->m_updateTravelDistanceTimer.__vftable;
  this->m_updateTravelDistanceTimer.m_timestamp.m_Value = -1.0;
  v30->NetworkStateChanged(this: &this->m_updateTravelDistanceTimer, a2: &this->m_updateTravelDistanceTimer.m_timestamp);
  CSGameState::CSGameState(this: &this->m_gameState, a2: (int)&CountdownTimer::`vftable', a3: (int)this, owner: this);
  this->m_inhibitWaitingForHostageTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v31 = this->m_inhibitWaitingForHostageTimer.__vftable;
  this->m_inhibitWaitingForHostageTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v31->NetworkStateChanged)(a1: &this->m_inhibitWaitingForHostageTimer.m_duration);
  v32 = this->m_inhibitWaitingForHostageTimer.__vftable;
  this->m_inhibitWaitingForHostageTimer.m_timestamp.m_Value = -1.0;
  v32->NetworkStateChanged(
    this: &this->m_inhibitWaitingForHostageTimer,
    a2: &this->m_inhibitWaitingForHostageTimer.m_timestamp);
  this->m_waitForHostageTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  this->m_waitForHostageTimer.m_duration.m_Value = 0.0;
  this->m_waitForHostageTimer.NetworkStateChanged(
    this: &this->m_waitForHostageTimer,
    a2: &this->m_waitForHostageTimer.m_duration);
  v33 = this->m_waitForHostageTimer.__vftable;
  this->m_waitForHostageTimer.m_timestamp.m_Value = -1.0;
  v33->NetworkStateChanged(this: &this->m_waitForHostageTimer, a2: &this->m_waitForHostageTimer.m_timestamp);
  this->m_noiseBendTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v34 = this->m_noiseBendTimer.__vftable;
  this->m_noiseBendTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v34->NetworkStateChanged)(a1: &this->m_noiseBendTimer.m_duration);
  v35 = this->m_noiseBendTimer.__vftable;
  this->m_noiseBendTimer.m_timestamp.m_Value = -1.0;
  v35->NetworkStateChanged(this: &this->m_noiseBendTimer, a2: &this->m_noiseBendTimer.m_timestamp);
  this->m_viewSteadyTimer.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v36 = this->m_viewSteadyTimer.__vftable;
  this->m_viewSteadyTimer.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v36->NetworkStateChanged)(a1: &this->m_viewSteadyTimer.m_timestamp);
  this->m_tossGrenadeTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v37 = this->m_tossGrenadeTimer.__vftable;
  this->m_tossGrenadeTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v37->NetworkStateChanged)(a1: &this->m_tossGrenadeTimer.m_duration);
  v38 = this->m_tossGrenadeTimer.__vftable;
  this->m_tossGrenadeTimer.m_timestamp.m_Value = -1.0;
  v38->NetworkStateChanged(this: &this->m_tossGrenadeTimer, a2: &this->m_tossGrenadeTimer.m_timestamp);
  this->m_isAvoidingGrenade.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v39 = this->m_isAvoidingGrenade.__vftable;
  this->m_isAvoidingGrenade.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v39->NetworkStateChanged)(a1: &this->m_isAvoidingGrenade.m_duration);
  v40 = this->m_isAvoidingGrenade.__vftable;
  this->m_isAvoidingGrenade.m_timestamp.m_Value = -1.0;
  v40->NetworkStateChanged(this: &this->m_isAvoidingGrenade, a2: &this->m_isAvoidingGrenade.m_timestamp);
  this->m_ignoreEnemiesTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v41 = this->m_ignoreEnemiesTimer.__vftable;
  this->m_ignoreEnemiesTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v41->NetworkStateChanged)(a1: &this->m_ignoreEnemiesTimer.m_duration);
  v42 = this->m_ignoreEnemiesTimer.__vftable;
  this->m_ignoreEnemiesTimer.m_timestamp.m_Value = -1.0;
  v42->NetworkStateChanged(this: &this->m_ignoreEnemiesTimer, a2: &this->m_ignoreEnemiesTimer.m_timestamp);
  this->m_enemy.m_Index = -1;
  this->m_bomber.m_Index = -1;
  this->m_closestVisibleFriend.m_Index = -1;
  this->m_closestVisibleHumanFriend.m_Index = -1;
  this->m_attentionInterval.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v43 = this->m_attentionInterval.__vftable;
  this->m_attentionInterval.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v43->NetworkStateChanged)(a1: &this->m_attentionInterval.m_timestamp);
  this->m_attacker.m_Index = -1;
  this->m_burnedByFlamesTimer.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v44 = this->m_burnedByFlamesTimer.__vftable;
  this->m_burnedByFlamesTimer.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v44->NetworkStateChanged)(a1: &this->m_burnedByFlamesTimer.m_timestamp);
  this->m_equipTimer.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v45 = this->m_equipTimer.__vftable;
  this->m_equipTimer.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v45->NetworkStateChanged)(a1: &this->m_equipTimer.m_timestamp);
  this->m_zoomTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v46 = this->m_zoomTimer.__vftable;
  this->m_zoomTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v46->NetworkStateChanged)(a1: &this->m_zoomTimer.m_duration);
  v47 = this->m_zoomTimer.__vftable;
  this->m_zoomTimer.m_timestamp.m_Value = -1.0;
  v47->NetworkStateChanged(this: &this->m_zoomTimer, a2: &this->m_zoomTimer.m_timestamp);
  this->m_sawEnemySniperTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v48 = this->m_sawEnemySniperTimer.__vftable;
  this->m_sawEnemySniperTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v48->NetworkStateChanged)(a1: &this->m_sawEnemySniperTimer.m_duration);
  v49 = this->m_sawEnemySniperTimer.__vftable;
  this->m_sawEnemySniperTimer.m_timestamp.m_Value = -1.0;
  v49->NetworkStateChanged(this: &this->m_sawEnemySniperTimer, a2: &this->m_sawEnemySniperTimer.m_timestamp);
  m_enemyQueue = this->m_enemyQueue;
  for ( i = 19; i >= 0; --i )
  {
    m_enemyQueue->player.m_Index = -1;
    ++m_enemyQueue;
  }
  this->m_wiggleTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v52 = this->m_wiggleTimer.__vftable;
  this->m_wiggleTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v52->NetworkStateChanged)(a1: &this->m_wiggleTimer.m_duration);
  v53 = this->m_wiggleTimer.__vftable;
  this->m_wiggleTimer.m_timestamp.m_Value = -1.0;
  v53->NetworkStateChanged(this: &this->m_wiggleTimer, a2: &this->m_wiggleTimer.m_timestamp);
  this->m_stuckJumpTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v54 = this->m_stuckJumpTimer.__vftable;
  this->m_stuckJumpTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v54->NetworkStateChanged)(a1: &this->m_stuckJumpTimer.m_duration);
  v55 = this->m_stuckJumpTimer.__vftable;
  this->m_stuckJumpTimer.m_timestamp.m_Value = -1.0;
  v55->NetworkStateChanged(this: &this->m_stuckJumpTimer, a2: &this->m_stuckJumpTimer.m_timestamp);
  this->m_radioSubject.m_Index = -1;
  BotChatterInterface::BotChatterInterface(
    this: &this->m_chatter,
    a2: (int)&CountdownTimer::`vftable',
    a3: (int)this,
    me: this);
  this->m_hasJoined = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102B1F60
// Name: public: virtual class CNavArea __near * CCSBot::GetLastKnownArea(void)const
// Source: json
//------------------------------------------------------------------------------
CCSNavArea *__thiscall CCSBot::GetLastKnownArea(CCSBot *this)
{
  return this->m_lastKnownArea;
}

//------------------------------------------------------------------------------
// Address: 0x102B1F70
// Name: public: virtual void CCSBot::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::PrimaryAttack(CCSBot *this)
{
  if ( !CCSBot::IsUsingPistol(this) || CCSBot::CanActiveWeaponFire(this) )
    this->m_buttonFlags |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x102B1F90
// Name: public: virtual CCSBot::~CCSBot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::~CCSBot(CCSBot *this)
{
  this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CCSBot_vtbl *)&CCSBot::`vftable'{for `CBasePlayer'};
  this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CCSBot::`vftable'{for `CAI_ExpresserSink'};
  this->CBot<CCSPlayer>::CCSPlayer::ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&CCSBot::`vftable';
  BotChatterInterface::~BotChatterInterface(this: &this->m_chatter);
  this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CCSBot_vtbl *)&CBot<CCSPlayer>::`vftable'{for `CBasePlayer'};
  this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CBot<CCSPlayer>::`vftable'{for `CAI_ExpresserSink'};
  this->CBot<CCSPlayer>::CCSPlayer::ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&CBot<CCSPlayer>::`vftable';
  this->m_userCmd.CBot<CCSPlayer>::__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_args);
  CCSPlayer::~CCSPlayer(this);
}
