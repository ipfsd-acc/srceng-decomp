// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_listen.cpp
// Functions: 7
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_listen.h"

//------------------------------------------------------------------------------
// Address: 0x102B2180
// Name: public: bool CCSBot::IsNoiseHeard(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsNoiseHeard(CCSBot *this)
{
  float m_noiseTimestamp; // xmm0_4

  m_noiseTimestamp = this->m_noiseTimestamp;
  return m_noiseTimestamp > 0.0 && (float)(gpGlobals->curtime - m_noiseTimestamp) >= this->m_profile->m_reactionTime;
}

//------------------------------------------------------------------------------
// Address: 0x102B21B0
// Name: public: float CCSBot::GetNoiseRange(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBot::GetNoiseRange(CCSBot *this)
{
  float m_noiseTimestamp; // xmm0_4

  m_noiseTimestamp = this->m_noiseTimestamp;
  if ( m_noiseTimestamp <= 0.0 || (float)(gpGlobals->curtime - m_noiseTimestamp) < this->m_profile->m_reactionTime )
    return 1000000000.0;
  else
    return this->m_noiseTravelDistance;
}

//------------------------------------------------------------------------------
// Address: 0x102B21F0
// Name: public: bool CCSBot::HeardInterestingNoise(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::HeardInterestingNoise(CCSBot *this)
{
  float m_noiseTimestamp; // xmm0_4
  IUniformRandomStream *v3; // ecx
  float v4; // xmm0_4
  float chance; // [esp+Ch] [ebp-4h]

  if ( this->m_blindUntilTime > gpGlobals->curtime )
    return false;
  if ( !CCSBot::IsWellPastSafe(this) )
    return false;
  if ( CCSBot::GetDisposition(this) != ENGAGE_AND_INVESTIGATE )
    return false;
  m_noiseTimestamp = this->m_noiseTimestamp;
  if ( m_noiseTimestamp <= 0.0
    || (float)(gpGlobals->curtime - m_noiseTimestamp) < this->m_profile->m_reactionTime
    || CCSBot::IsAtHidingSpot(this) && CCSBot::GetNoiseRange(this) > this->m_profile->m_aggression * 400.0 + 100.0 )
  {
    return false;
  }
  chance = (1.0 - CCSBot::GetNoiseRange(this) * 0.00033333333) * 100.0;
  if ( CBot<CCSPlayer>::GetFriendsRemaining(this) >= 3 )
  {
    v4 = (float)CBot<CCSPlayer>::GetFriendsRemaining(this) * 5.0;
    if ( v4 > 50.0 )
      v4 = 50.0;
    chance = chance - v4;
  }
  return (double)chance >= _RandomFloat(this: v3, a2: 0.0, a3: 100.0);
}

//------------------------------------------------------------------------------
// Address: 0x102B2330
// Name: public: bool CCSBot::CanSeeNoisePosition(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::CanSeeNoisePosition(CCSBot *this)
{
  float v2; // xmm0_4
  CGameTrace v4; // [esp+4h] [ebp-70h] BYREF
  CTraceFilterNoNPCsOrPlayer traceFilter; // [esp+58h] [ebp-1Ch] BYREF
  Vector vecAbsEnd; // [esp+68h] [ebp-Ch] BYREF
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &traceFilter,
    passedict: this,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  vecAbsEnd.x = this->m_noisePosition.x;
  vecAbsEnd.y = this->m_noisePosition.y;
  v2 = this->m_noisePosition.z + 35.5;
  traceFilter.__vftable = (CTraceFilterNoNPCsOrPlayer_vtbl *)&CTraceFilterNoNPCsOrPlayer::`vftable';
  vecAbsEnd.z = v2;
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)&this->m_eyePosition,
    vecAbsStart: &this->m_eyePosition,
    &vecAbsEnd,
    mask: 0x2006081u,
    pFilter: &traceFilter,
    ptr: &v4);
  return v4.fraction == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102B23C0
// Name: public: bool CCSBot::CanHearNearbyEnemyGunfire(float)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::CanHearNearbyEnemyGunfire(CCSBot *this, float range)
{
  CBaseEntity *v4; // eax
  Vector *Centroid; // eax
  Vector v6; // [esp+4h] [ebp-24h] BYREF
  float v7; // [esp+10h] [ebp-18h]
  float v8; // [esp+14h] [ebp-14h]
  float v9; // [esp+18h] [ebp-10h]
  Vector myOrigin; // [esp+1Ch] [ebp-Ch] BYREF

  GetCentroid(result: &myOrigin, player: this);
  if ( (float)(gpGlobals->curtime - this->m_noiseTimestamp) > 0.5
    || this->m_noisePriority < PRIORITY_HIGH
    || range > 0.0
    && (float)((float)((float)((float)(myOrigin.x - this->m_noisePosition.x)
                             * (float)(myOrigin.x - this->m_noisePosition.x))
                     + (float)((float)(myOrigin.y - this->m_noisePosition.y)
                             * (float)(myOrigin.y - this->m_noisePosition.y)))
             + (float)((float)(myOrigin.z - this->m_noisePosition.z) * (float)(myOrigin.z - this->m_noisePosition.z))) > (float)(range * range)
    || !CCSBot::CanSeeNoisePosition(this) )
  {
    return 0;
  }
  if ( CCSBot::IsAttacking(this)
    && CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)&this->m_enemy, val: nullptr)
    && (float)(gpGlobals->curtime - this->m_lastSawEnemyTimestamp) < 1.0 )
  {
    v7 = this->m_noisePosition.x - myOrigin.x;
    v8 = this->m_noisePosition.y - myOrigin.y;
    v9 = this->m_noisePosition.z - myOrigin.z;
    v4 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_enemy);
    Centroid = GetCentroid(result: &v6, player: v4);
    if ( (float)((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9)) > (float)((float)((float)((float)((float)(Centroid->y - myOrigin.y) * (float)(Centroid->y - myOrigin.y)) + (float)((float)(Centroid->x - myOrigin.x) * (float)(Centroid->x - myOrigin.x)))
                                                                                                  + (float)((float)(Centroid->z - myOrigin.z) * (float)(Centroid->z - myOrigin.z)))
                                                                                          - 10000.0) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102B2580
// Name: private: bool CCSBot::UpdateLookAtNoise(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CCSBot::UpdateLookAtNoise@<al>(CCSBot *this@<ecx>, float a2@<edi>)
{
  float m_noiseTimestamp; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  IUniformRandomStream *v7; // ecx
  const Vector *v8; // eax
  IUniformRandomStream *v9; // ecx
  float v10; // xmm0_4
  float v11; // [esp+Ch] [ebp-2Ch]
  float v12; // [esp+Ch] [ebp-2Ch]
  float v13; // [esp+Ch] [ebp-2Ch]
  float v14; // [esp+14h] [ebp-24h]
  bool duration; // [esp+18h] [ebp-20h]
  Vector target; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector spot; // [esp+28h] [ebp-10h] BYREF
  float noiseBendLOSInterval; // [esp+34h] [ebp-4h]

  m_noiseTimestamp = this->m_noiseTimestamp;
  if ( m_noiseTimestamp <= 0.0 || (float)(gpGlobals->curtime - m_noiseTimestamp) < this->m_profile->m_reactionTime )
    return 0;
  v14 = a2;
  if ( CCSBot::CanSeeNoisePosition(this) )
  {
    x = this->m_noisePosition.x;
    y = this->m_noisePosition.y;
    spot.z = this->m_noisePosition.z + 35.5;
    spot.x = x;
    spot.y = y;
    this->m_noiseTimestamp = 0.0;
    goto LABEL_13;
  }
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_noiseBendTimer) <= this->m_noiseBendTimer.m_timestamp.m_Value )
  {
    if ( !this->m_bendNoisePositionValid )
      return 0;
    spot = this->m_bentNoisePosition;
  }
  else
  {
    noiseBendLOSInterval = _RandomFloat(this: v7, a2: 0.2, a3: 0.30000001);
    CountdownTimer::Start(this: &this->m_noiseBendTimer, duration: noiseBendLOSInterval);
    duration = false;
    v8 = (const Vector *)((int (__thiscall *)(CCSBot *))this->EyePosition)(a1: this);
    if ( !CCSBot::BendLineOfSight(this, eye: v8, &target, bend: &this->m_noisePosition, angleLimit: COERCE_FLOAT(&spot)) )
    {
      this->m_bendNoisePositionValid = false;
      return 0;
    }
    this->m_bentNoisePosition = spot;
    this->m_bendNoisePositionValid = true;
  }
LABEL_13:
  if ( CCSBot::IsAtHidingSpot(this) )
  {
    if ( CBot<CCSPlayer>::GetEnemiesRemaining(this) == 1 )
    {
      v11 = _RandomFloat(this: v9, a2: 5.0, a3: 15.0);
      CCSBot::SetLookAt(
        this,
        desc: "Noise",
        pos: &spot,
        pri: PRIORITY_HIGH,
        duration: v11,
        clearIfClose: false,
        angleTolerance: v14,
        attack: duration);
      return 1;
    }
    goto LABEL_19;
  }
  v10 = this->m_noiseTimestamp;
  if ( v10 > 0.0
    && (float)(gpGlobals->curtime - v10) >= this->m_profile->m_reactionTime
    && this->m_noiseTravelDistance < 500.0 )
  {
LABEL_19:
    v12 = _RandomFloat(this: v9, a2: 3.0, a3: 5.0);
    CCSBot::SetLookAt(
      this,
      desc: "Noise",
      pos: &spot,
      pri: PRIORITY_HIGH,
      duration: v12,
      clearIfClose: false,
      angleTolerance: v14,
      attack: duration);
    return 1;
  }
  v13 = _RandomFloat(this: v9, a2: 1.0, a3: 2.0);
  CCSBot::SetLookAt(
    this,
    desc: "Noise",
    pos: &spot,
    pri: PRIORITY_HIGH,
    duration: v13,
    clearIfClose: false,
    angleTolerance: v14,
    attack: duration);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102B2850
// Name: __CreateCServerGameTagsIServerGameTags_interface_21
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_21()
{
  return &_g_CServerGameTags_singleton_21;
}
