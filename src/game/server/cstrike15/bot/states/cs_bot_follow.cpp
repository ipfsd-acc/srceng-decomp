// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_follow.cpp
// Functions: 6
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_follow.h"

//------------------------------------------------------------------------------
// Address: 0x102D3580
// Name: public: FollowTargetCollector::FollowTargetCollector(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
FollowTargetCollector *__userpurge FollowTargetCollector::FollowTargetCollector@<eax>(
        FollowTargetCollector *this@<ecx>,
        float a2@<ebp>,
        CBasePlayer *player)
{
  float z; // ecx
  float y; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v10; // [esp-20h] [ebp-2Ch]
  Vector v11; // [esp-Ch] [ebp-18h] BYREF
  Vector playerOrigin; // [esp+0h] [ebp-Ch] BYREF
  float retaddr; // [esp+Ch] [ebp+0h]

  playerOrigin.x = a2;
  playerOrigin.y = retaddr;
  this->m_player = player;
  if ( (player->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: player, a2: (int)&playerOrigin);
  z = player->m_vecAbsVelocity.z;
  *(_QWORD *)&v11.x = *(_QWORD *)&player->m_vecAbsVelocity.x;
  this->m_forward.x = v11.x;
  y = v11.y;
  this->m_forward.y = v11.y;
  v10 = fsqrt((float)(this->m_forward.x * this->m_forward.x) + (float)(y * y));
  v6 = 0.0;
  v11.z = z;
  if ( v10 == 0.0 )
  {
    this->m_forward.x = 0.0;
  }
  else
  {
    v6 = (float)(1.0 / v10) * this->m_forward.y;
    this->m_forward.x = this->m_forward.x * (float)(1.0 / v10);
  }
  this->m_forward.y = v6;
  GetCentroid(result: &v11, player);
  if ( v10 >= 100.0 )
  {
    v7 = 200.0;
    if ( v10 < 200.0 )
      v7 = v10;
    v8 = v7 * 1.5;
    this->m_cutoff.x = (float)(v8 * this->m_forward.x) + v11.x;
    this->m_cutoff.y = (float)(this->m_forward.y * v8) + v11.y;
  }
  else
  {
    this->m_cutoff.x = v11.x;
    this->m_cutoff.y = v11.y;
    this->m_forward.x = 0.0;
    this->m_forward.y = 0.0;
  }
  this->m_targetAreaCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D36E0
// Name: public: bool FollowTargetCollector::operator()(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall FollowTargetCollector::operator()(FollowTargetCollector *this, CNavArea *area)
{
  CNavArea *m_parent; // eax
  float x; // xmm0_4
  float y; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4

  if ( this->m_targetAreaCount >= 128 )
    return false;
  m_parent = area->m_parent;
  if ( m_parent == nullptr || CNavArea::IsConnected(this: area, area: m_parent, dir: NUM_DIRECTIONS) != 0 )
  {
    x = this->m_forward.x;
    if ( x <= -0.0099999998 || x >= 0.0099999998 || (y = this->m_forward.y) <= -0.0099999998 || y >= 0.0099999998 )
    {
      v7 = area->m_center.x - this->m_cutoff.x;
      v8 = area->m_center.y - this->m_cutoff.y;
      v9 = 0.0;
      v10 = fsqrt((float)(v7 * v7) + (float)(v8 * v8));
      if ( v10 == 0.0 )
      {
        v12 = 0.0;
      }
      else
      {
        v11 = 1.0 / v10;
        v12 = (float)(1.0 / v10) * v7;
        v9 = v11 * v8;
      }
      if ( (float)((float)(this->m_forward.y * v9) + (float)(this->m_forward.x * v12)) <= 0.70709997 )
        return this->m_targetAreaCount < 128;
      this->m_targetArea[this->m_targetAreaCount] = area;
    }
    else
    {
      this->m_targetArea[this->m_targetAreaCount] = area;
    }
    ++this->m_targetAreaCount;
  }
  return this->m_targetAreaCount < 128;
}

//------------------------------------------------------------------------------
// Address: 0x102D4100
// Name: public: virtual void FollowState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FollowState::OnEnter(FollowState *this, CCSBot *me)
{
  IUniformRandomStream *v3; // ecx
  double v4; // st7
  float m_Value; // xmm0_4
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *p_m_duration; // esi
  float v7; // [esp+1Ch] [ebp-4h]
  float mea; // [esp+28h] [ebp+8h]

  me->StandUp(this: me);
  me->Run(this: me);
  me->m_isStopping = false;
  me->m_pathLength = 0;
  me->m_pathLadder = nullptr;
  this->m_lastLeaderPos.x = -100000000.0;
  this->m_lastLeaderPos.y = -100000000.0;
  this->m_lastLeaderPos.z = -100000000.0;
  this->m_isStopped = false;
  this->m_stoppedTimestamp = 0.0;
  this->m_lastSawLeaderTime = 0.0;
  if ( this->m_repathInterval.m_timestamp.m_Value != -1.0 )
  {
    this->m_repathInterval.NetworkStateChanged(this: &this->m_repathInterval, a2: &this->m_repathInterval.m_timestamp);
    this->m_repathInterval.m_timestamp.m_Value = -1.0;
  }
  this->m_isSneaking = false;
  if ( this->m_walkTime.m_timestamp.m_Value != -1.0 )
  {
    this->m_walkTime.NetworkStateChanged(this: &this->m_walkTime, a2: &this->m_walkTime.m_timestamp);
    this->m_walkTime.m_timestamp.m_Value = -1.0;
  }
  this->m_isAtWalkSpeed = false;
  this->m_leaderMotionState = 0;
  mea = _RandomFloat(this: v3, a2: 2.0, a3: 5.0);
  v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_idleTimer) + mea;
  if ( this->m_idleTimer.m_timestamp.m_Value != v4 )
  {
    this->m_idleTimer.NetworkStateChanged(this: &this->m_idleTimer, a2: &this->m_idleTimer.m_timestamp);
    v7 = v4;
    this->m_idleTimer.m_timestamp.m_Value = v7;
  }
  m_Value = this->m_idleTimer.m_duration.m_Value;
  p_m_duration = &this->m_idleTimer.m_duration;
  if ( m_Value != mea )
  {
    (*(void (__thiscall **)(int, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))LODWORD(p_m_duration[-1].m_Value))(
      a1: (int)&p_m_duration[-1],
      a2: p_m_duration);
    p_m_duration->m_Value = mea;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4250
// Name: private: void FollowState::ComputeLeaderMotionState(float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge FollowState::ComputeLeaderMotionState(FollowState *this@<ecx>, int a2@<edi>, float leaderSpeed)
{
  FollowState::LeaderMotionStateType m_leaderMotionState; // ebx
  double v5; // st7
  IUniformRandomStream *v6; // ecx
  double v7; // st7
  float leaderSpeeda; // [esp+20h] [ebp+8h]
  float leaderSpeedb; // [esp+20h] [ebp+8h]
  float leaderSpeedc; // [esp+20h] [ebp+8h]

  m_leaderMotionState = this->m_leaderMotionState;
  if ( leaderSpeed > 140.0 )
  {
    this->m_leaderMotionState = STOPPED|WALKING;
LABEL_12:
    this->m_isAtWalkSpeed = false;
    goto LABEL_13;
  }
  if ( leaderSpeed <= 10.0 )
  {
    this->m_leaderMotionState = STOPPED;
    goto LABEL_12;
  }
  if ( !this->m_isAtWalkSpeed )
  {
    v5 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_walkTime);
    if ( this->m_walkTime.m_timestamp.m_Value != v5 )
    {
      ((void (__thiscall *)(IntervalTimer *, CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *, int))this->m_walkTime.NetworkStateChanged)(
        a1: &this->m_walkTime,
        a2: &this->m_walkTime.m_timestamp,
        a3: a2);
      leaderSpeeda = v5;
      this->m_walkTime.m_timestamp.m_Value = leaderSpeeda;
    }
    this->m_isAtWalkSpeed = true;
  }
  if ( this->m_walkTime.m_timestamp.m_Value <= 0.0
    || (leaderSpeedb = IntervalTimer::Now(this: (CEffectsServer *)&this->m_walkTime)
                     - this->m_walkTime.m_timestamp.m_Value) > 0.25 )
  {
    this->m_leaderMotionState = WALKING;
  }
LABEL_13:
  if ( m_leaderMotionState != this->m_leaderMotionState )
  {
    v7 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_leaderMotionStateTime);
    if ( this->m_leaderMotionStateTime.m_timestamp.m_Value != v7 )
    {
      this->m_leaderMotionStateTime.NetworkStateChanged(
        this: &this->m_leaderMotionStateTime,
        a2: &this->m_leaderMotionStateTime.m_timestamp);
      leaderSpeedc = v7;
      this->m_leaderMotionStateTime.m_timestamp.m_Value = leaderSpeedc;
    }
    this->m_waitTime = _RandomFloat(this: v6, a2: 1.0, a3: 3.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4360
// Name: public: virtual void FollowState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge FollowState::OnUpdate(FollowState *this@<ecx>, int a2@<ebp>, CCSBot *me)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  CEntInfo *v9; // eax
  IHandleEntity *v10; // eax
  unsigned int Place; // eax
  IUniformRandomStream *v12; // ecx
  unsigned int v13; // eax
  IHandleEntity *m_pEntity; // esi
  __int64 v15; // xmm0_8
  float z; // esi
  float v17; // xmm1_4
  __int128 v18; // xmm0
  unsigned int v19; // eax
  CBaseEntity *v20; // ecx
  double curtime; // st7
  int v22; // eax
  CCSBot_vtbl *v23; // edx
  IUniformRandomStream *v24; // ecx
  double v25; // st7
  float v26; // xmm0_4
  float v27; // xmm1_4
  double v28; // st7
  double v29; // st7
  const Vector *v30; // esi
  float v31; // xmm0_4
  CBasePlayer *v32; // eax
  CNavArea *NearestNavArea; // eax
  int v34; // edi
  int v35; // esi
  bool v36; // zf
  IUniformRandomStream *v37; // ecx
  CHandle<CBaseEntity> *v38; // esi
  int v39; // esi
  float duration_4; // [esp+1Ch] [ebp-268h]
  float duration_4a; // [esp+1Ch] [ebp-268h]
  unsigned __int64 v42; // [esp+20h] [ebp-264h] BYREF
  _BYTE collector_8[532]; // [esp+34h] [ebp-250h] OVERLAPPED BYREF
  Vector close; // [esp+248h] [ebp-3Ch] BYREF
  float v45; // [esp+254h] [ebp-30h]
  Vector leaderOrigin; // [esp+258h] [ebp-2Ch] BYREF
  Vector myOrigin; // [esp+264h] [ebp-20h]
  CHandle<CBaseEntity> *p_m_leader; // [esp+270h] [ebp-14h]
  float closeRangeSq; // [esp+274h] [ebp-10h]
  int v50; // [esp+278h] [ebp-Ch] BYREF
  CNavArea *target; // [esp+27Ch] [ebp-8h]
  CNavArea *retaddr; // [esp+284h] [ebp+0h]

  v50 = a2;
  target = retaddr;
  m_Index = this->m_leader.m_Index;
  LODWORD(myOrigin.z) = this;
  p_m_leader = (CHandle<CBaseEntity> *)&this->m_leader;
  if ( m_Index != -1
    && (v5 = (unsigned __int16)m_Index,
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v7 = HIWORD(m_Index),
        v6->m_SerialNumber == v7)
    && v6->m_pEntity != nullptr
    && ((v8 = v5,
         v36 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7,
         v9 = &g_pEntityList->m_EntPtrArray[v8],
         !v36)
      ? (v10 = nullptr)
      : (v10 = v9->m_pEntity),
        v10->__vftable[22].GetRefEHandle(this: v10) != nullptr) )
  {
    if ( CCSPlayer::HasC4(this: me) && me->m_bInBombZone.m_Value )
    {
      me->m_task = PLANT_BOMB;
      me->m_taskEntity.m_Index = -1;
      CCSBot::PlantBomb(this: me);
      Place = CCSBot::GetPlace(this: me);
      BotChatterInterface::PlantingTheBomb(this: &me->m_chatter, place: Place);
      return;
    }
    CCSBot::UpdateLookAround(this: me, a2: COERCE_FLOAT(&v50), a3: (int)me, updateNow: false);
    if ( me->m_stillTimer.m_timestamp.m_Value <= 0.0
      || (myOrigin.x = IntervalTimer::Now(this: (CEffectsServer *)&me->m_stillTimer)
                     - me->m_stillTimer.m_timestamp.m_Value,
          myOrigin.x < 0.0) )
    {
      duration_4 = _RandomFloat(this: v12, a2: 2.0, a3: 5.0);
      CountdownTimer::Start(this: &this->m_idleTimer, duration: duration_4);
    }
    v13 = p_m_leader->m_Index;
    if ( p_m_leader->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    if ( ((int)m_pEntity[49].__vftable & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: (CBaseEntity *)m_pEntity, a2: (int)&v50);
    v15 = *(_QWORD *)&m_pEntity[91].__vftable;
    z = myOrigin.z;
    v17 = (float)(*((float *)&v15 + 1) * *((float *)&v15 + 1)) + (float)(*(float *)&v15 * *(float *)&v15);
    v18 = 0;
    *(float *)&v18 = fsqrt(v17);
    *(_OWORD *)&collector_8[516] = v18;
    FollowState::ComputeLeaderMotionState(
      this: (FollowState *)LODWORD(myOrigin.z),
      a2: (int)me,
      leaderSpeed: *(float *)&v18);
    v19 = p_m_leader->m_Index;
    if ( p_m_leader->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
      v20 = nullptr;
    else
      v20 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
    GetCentroid(result: (Vector *)&close.y, player: v20);
    if ( CCSBot::IsVisible(this: me, pos: (Vector *)&close.y, testFOV: false, ignore: nullptr) != 0 )
    {
      curtime = gpGlobals->curtime;
      HIBYTE(closeRangeSq) = 1;
      *(float *)(LODWORD(z) + 44) = curtime;
    }
    else
    {
      HIBYTE(closeRangeSq) = 0;
    }
    GetCentroid(result: &leaderOrigin, player: me);
    if ( (float)((float)((float)((float)(close.y - leaderOrigin.x) * (float)(close.y - leaderOrigin.x))
                       + (float)((float)(close.z - leaderOrigin.y) * (float)(close.z - leaderOrigin.y)))
               + (float)((float)(v45 - leaderOrigin.z) * (float)(v45 - leaderOrigin.z))) > 562500.0 )
      goto LABEL_33;
    if ( HIBYTE(closeRangeSq) != 0 )
    {
      v22 = *(_DWORD *)(LODWORD(z) + 28);
      if ( v22 == 2 )
        *(_BYTE *)(LODWORD(z) + 40) = 1;
      if ( *(_BYTE *)(LODWORD(z) + 40) != 0 && v22 == 3 )
LABEL_33:
        *(_BYTE *)(LODWORD(z) + 40) = 0;
    }
    if ( (float)(gpGlobals->curtime - *(float *)(LODWORD(z) + 44)) > 20.0 )
      *(_BYTE *)(LODWORD(z) + 40) = 0;
    v23 = me->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    if ( *(_BYTE *)(LODWORD(z) + 40) != 0 )
      ((void (__fastcall *)(CCSBot *))v23->Walk)(a1: me);
    else
      ((void (__fastcall *)(CCSBot *))v23->Run)(a1: me);
    v36 = me->m_pathLength == 0;
    HIBYTE(closeRangeSq) = 0;
    if ( v36
      && *(_DWORD *)(LODWORD(z) + 28) == 1
      && IntervalTimer::GetElapsedTime(this: (IntervalTimer *)(LODWORD(z) + 32)) > *(float *)(LODWORD(z) + 72) )
    {
      v25 = _RandomFloat(this: v24, a2: 1.0, a3: 3.0);
      v26 = close.y - leaderOrigin.x;
      v27 = close.z;
      *(float *)(LODWORD(z) + 72) = v25 + *(float *)(LODWORD(z) + 72);
      if ( (float)((float)((float)(v26 * v26) + (float)((float)(v27 - leaderOrigin.y) * (float)(v27 - leaderOrigin.y)))
                 + (float)((float)(v45 - leaderOrigin.z) * (float)(v45 - leaderOrigin.z))) < 62500.0
        && CCSBot::TryToHide(
             this: me,
             searchFromArea: nullptr,
             duration: -1.0,
             hideRange: 250.0,
             holdPosition: false,
             useNearest: true) != 0 )
      {
        CCSBot::ResetStuckMonitor(this: me);
        return;
      }
    }
    LODWORD(myOrigin.z) = LODWORD(z) + 76;
    v28 = IntervalTimer::Now(this: (CEffectsServer *)(LODWORD(z) + 76));
    if ( v28 > *(float *)(LODWORD(myOrigin.z) + 8) )
    {
      HIBYTE(closeRangeSq) = 1;
      *(_BYTE *)(LODWORD(z) + 40) = 1;
    }
    if ( *(float *)&collector_8[516] > 100.0 && *(_DWORD *)(LODWORD(z) + 28) != 1 )
      HIBYTE(closeRangeSq) = 1;
    if ( CCSBot::UpdatePathMovement(this: me, a2: (int)&v50, allowSpeedChange: false) != 0 )
    {
      me->m_isStopping = false;
      me->m_pathLength = 0;
      me->m_pathLadder = nullptr;
    }
    if ( HIBYTE(closeRangeSq) != 0 )
    {
      LODWORD(myOrigin.x) = LODWORD(z) + 48;
      v29 = IntervalTimer::Now(this: (CEffectsServer *)(LODWORD(z) + 48));
      if ( v29 > *(float *)(LODWORD(myOrigin.x) + 8) && !CBasePlayer::IsOnLadder(this: me) )
      {
        v30 = (const Vector *)(LODWORD(z) + 8);
        v30->x = close.y;
        v30->y = close.z;
        v30->z = v45;
        CCSBot::ResetStuckMonitor(this: me);
        if ( *(float *)&collector_8[516] <= 200.0 )
          v31 = 400.0;
        else
          v31 = 600.0;
        myOrigin.y = v31;
        v32 = (CBasePlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_leader);
        FollowTargetCollector::FollowTargetCollector(
          this: (FollowTargetCollector *)&v42,
          a2: COERCE_FLOAT(&v50),
          player: v32);
        v42 = 0xFFFFFFFF00000000uLL;
        duration_4a = myOrigin.y;
        NearestNavArea = CNavMesh::GetNearestNavArea(
                           this: TheNavMesh,
                           pos: v30,
                           anyZ: false,
                           maxDist: 10000.0,
                           checkLOS: false,
                           checkGround: true);
        SearchSurroundingAreas<FollowTargetCollector>(
          a1: (const CNavLadder *)&v50,
          startArea: NearestNavArea,
          startPos: v30,
          func: (FollowTargetCollector *)&v42,
          maxRange: duration_4a,
          options: v42,
          teamID: SHIDWORD(v42));
        v34 = *(_DWORD *)&collector_8[512];
        if ( cv_bot_debug.m_pParent != nullptr && cv_bot_debug.m_pParent->m_Value.m_nValue != 0 )
        {
          v35 = 0;
          v36 = *(_DWORD *)&collector_8[512] == 0;
          if ( *(int *)&collector_8[512] <= 0 )
            goto LABEL_63;
          do
          {
            (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&collector_8[4 * v35] + 76))(a1: *(_DWORD *)&collector_8[4 * v35]);
            ++v35;
          }
          while ( v35 < v34 );
        }
        v36 = v34 == 0;
LABEL_63:
        if ( v36 )
          return;
        p_m_leader = nullptr;
        if ( CountdownTimer::IsElapsed(this: (CountdownTimer *)LODWORD(myOrigin.z)) )
        {
          v38 = *(CHandle<CBaseEntity> **)&collector_8[4 * _RandomInt(this: v37, a2: 0, a3: v34 - 1)];
          CBot<CCSPlayer>::PrintIfWatched(
            this: me,
            format: "%4.1f: Bored. Repathing to a new nearby area\n",
            gpGlobals->curtime);
        }
        else
        {
          CBot<CCSPlayer>::PrintIfWatched(
            this: me,
            format: "%4.1f: Repathing to stay with leader.\n",
            gpGlobals->curtime);
          v39 = 0;
          myOrigin.y = 1.0e10;
          if ( v34 <= 0 )
          {
LABEL_73:
            CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Pathfind to leader failed.\n");
LABEL_74:
            CountdownTimer::Start(this: (CountdownTimer *)LODWORD(myOrigin.x), duration: 0.5);
            CountdownTimer::Reset(this: (CountdownTimer *)LODWORD(myOrigin.z));
            return;
          }
          do
          {
            CNavArea::GetClosestPointOnArea(
              this: *(CNavArea **)&collector_8[4 * v39],
              pPos: &leaderOrigin,
              close: (Vector *)&collector_8[520]);
            if ( myOrigin.y > (float)((float)((float)((float)(leaderOrigin.y - *(float *)&collector_8[524])
                                                    * (float)(leaderOrigin.y - *(float *)&collector_8[524]))
                                            + (float)((float)(leaderOrigin.x - *(float *)&collector_8[520])
                                                    * (float)(leaderOrigin.x - *(float *)&collector_8[520])))
                                    + (float)((float)(leaderOrigin.z - *(float *)&collector_8[528])
                                            * (float)(leaderOrigin.z - *(float *)&collector_8[528]))) )
            {
              p_m_leader = *(CHandle<CBaseEntity> **)&collector_8[4 * v39];
              myOrigin.y = (float)((float)((float)(leaderOrigin.y - *(float *)&collector_8[524])
                                         * (float)(leaderOrigin.y - *(float *)&collector_8[524]))
                                 + (float)((float)(leaderOrigin.x - *(float *)&collector_8[520])
                                         * (float)(leaderOrigin.x - *(float *)&collector_8[520])))
                         + (float)((float)(leaderOrigin.z - *(float *)&collector_8[528])
                                 * (float)(leaderOrigin.z - *(float *)&collector_8[528]));
            }
            ++v39;
          }
          while ( v39 < v34 );
          v38 = p_m_leader;
        }
        if ( v38 != nullptr && CCSBot::ComputePath(this: me, goal: (const Vector *)&v38[11], route: FASTEST_ROUTE) != 0 )
          goto LABEL_74;
        goto LABEL_73;
      }
    }
  }
  else
  {
    CCSBot::Idle(this: me);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D49E0
// Name: __CreateCServerGameTagsIServerGameTags_interface_43
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_43()
{
  return &_g_CServerGameTags_singleton_43;
}
