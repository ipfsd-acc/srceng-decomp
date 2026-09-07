// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_hide.cpp
// Functions: 4
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_hide.h"

//------------------------------------------------------------------------------
// Address: 0x102D49F0
// Name: public: virtual void HideState::OnExit(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall HideState::OnExit(HideState *this, CCSBot *me)
{
  this->m_isHoldingPosition = false;
  me->StandUp(this: me);
  CCSBot::ResetStuckMonitor(this: me);
  me->m_approachPointCount = 0;
  if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me)
    && IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me)
    && IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me) )
  {
    me->SecondaryAttack(this: me);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4A50
// Name: public: virtual void HideState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge HideState::OnEnter(HideState *this@<ecx>, float a2@<edi>, CCSBot *me)
{
  bool v4; // cc
  IUniformRandomStream *v5; // ecx
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax
  float m_Value; // xmm0_4
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  void (__thiscall *v10)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *); // eax
  Vector result; // [esp+10h] [ebp-Ch] BYREF

  v4 = this->m_duration >= 0.0;
  *(_WORD *)&this->m_isLookingOutward = 0;
  if ( !v4 )
    this->m_duration = _RandomFloat((IUniformRandomStream *)this, a2: 30.0, a3: 60.0);
  if ( _RandomFloat((IUniformRandomStream *)this, a2: 0.0, a3: 100.0) < 50.0 )
    this->m_isHoldingPosition = true;
  if ( this->m_isHoldingPosition )
    this->m_holdPositionTime = _RandomFloat(this: v5, a2: 3.0, a3: 10.0);
  else
    this->m_holdPositionTime = 0.0;
  result.z = a2;
  this->m_heardEnemy = false;
  this->m_firstHeardEnemyTime = 0.0;
  this->m_retry = 0;
  if ( me->m_isFollowing )
  {
    m_Index = me->m_leader.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    this->m_leaderAnchorPos = *GetCentroid(&result, player: m_pEntity);
  }
  if ( CCSBot::IsSniper(this: me) )
  {
    this->m_isPaused = false;
    m_Value = this->m_pauseTimer.m_timestamp.m_Value;
    p_m_timestamp = &this->m_pauseTimer.m_timestamp;
    if ( m_Value != -1.0 )
    {
      v10 = *(void (__thiscall **)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))LODWORD(p_m_timestamp[-2].m_Value);
      LODWORD(result.z) = p_m_timestamp;
      v10(a1: p_m_timestamp - 2);
      p_m_timestamp->m_Value = -1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4BB0
// Name: public: virtual void HideState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge HideState::OnUpdate(HideState *this@<ecx>, float a2@<ebp>, float a3@<esi>, CCSBot *me)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  unsigned int m_Index; // eax
  CCSBot::TaskType v7; // eax
  bool v8; // zf
  CBaseCombatWeapon *v9; // eax
  CHostage *NearestVisibleFreeHostage; // eax
  CCSNavArea *NearestNavArea; // eax
  CCSBot::TaskType m_task; // eax
  float m_holdPositionTime; // xmm0_4
  CNavArea *NavArea; // eax
  CCSBot::TaskType v15; // eax
  const CCSBotManager::Zone *ClosestZone; // eax
  CCSNavArea *RandomAreaInZone; // eax
  IUniformRandomStream *v18; // ecx
  IUniformRandomStream *v19; // ecx
  IUniformRandomStream *v20; // ecx
  CountdownTimer *p_m_pauseTimer; // ecx
  IUniformRandomStream *v22; // ecx
  double v23; // st7
  IUniformRandomStream *v24; // ecx
  CCSBot *ClosestPlayer; // eax
  int m_retry; // eax
  CCSNavArea *v27; // eax
  float v28; // xmm2_4
  float v29; // xmm5_4
  unsigned int v30; // ecx
  float v31; // xmm3_4
  __int128 v32; // xmm1
  float v33; // xmm0_4
  float v34; // xmm1_4
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v36; // eax
  float m_duration; // xmm0_4
  bool IsUsingGrenade; // al
  IUniformRandomStream *v39; // ecx
  CCSBot::TaskType v40; // eax
  float v41; // xmm0_4
  Vector *(__thiscall *v42)(CBaseEntity *, Vector *); // edx
  float *v43; // eax
  Vector *(__thiscall *v44)(CBaseEntity *, Vector *); // edx
  const Vector *v45; // eax
  char IsSniper; // al
  const Vector *NearbyHidingSpot; // eax
  float y; // ecx
  float repeatInterval; // [esp+10h] [ebp-DCh]
  float repeatIntervala; // [esp+10h] [ebp-DCh]
  float repeatIntervalb; // [esp+10h] [ebp-DCh]
  float durationa; // [esp+14h] [ebp-D8h]
  char *duration; // [esp+14h] [ebp-D8h]
  float delay; // [esp+18h] [ebp-D4h]
  float v55; // [esp+1Ch] [ebp-D0h]
  CGameTrace result; // [esp+24h] [ebp-C8h] BYREF
  float v57[6]; // [esp+80h] [ebp-6Ch] BYREF
  Vector v58; // [esp+98h] [ebp-54h] BYREF
  Vector hostageOrigin; // [esp+A4h] [ebp-48h] BYREF
  Vector v60; // [esp+B0h] [ebp-3Ch] BYREF
  Vector myOrigin; // [esp+BCh] [ebp-30h] BYREF
  float outAngleRange; // [esp+C8h] [ebp-24h]
  float range; // [esp+CCh] [ebp-20h] BYREF
  float outAngle; // [esp+D0h] [ebp-1Ch]
  float angle; // [esp+D4h] [ebp-18h]
  Vector toSpot; // [esp+D8h] [ebp-14h] BYREF
  void *v67; // [esp+E4h] [ebp-8h] OVERLAPPED
  void *retaddr; // [esp+ECh] [ebp+0h]

  toSpot.z = a2;
  v67 = retaddr;
  GetCentroid(result: &v60, player: me);
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: me);
  if ( ActiveWeapon == nullptr || !ActiveWeapon->m_bInReload.m_Value )
  {
    if ( me->m_isFollowing )
    {
      m_Index = me->m_leader.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        toSpot.y = 0.0;
      else
        LODWORD(toSpot.y) = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      GetCentroid(result: (Vector *)&range, player: (CBaseEntity *)LODWORD(toSpot.y));
      if ( (*(_DWORD *)(LODWORD(toSpot.y) + 196) & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: (CBaseEntity *)LODWORD(toSpot.y), a2: (int)&toSpot.z);
      if ( (float)((float)((float)(*(float *)(LODWORD(toSpot.y) + 364) * *(float *)(LODWORD(toSpot.y) + 364))
                         + (float)(*(float *)(LODWORD(toSpot.y) + 368) * *(float *)(LODWORD(toSpot.y) + 368)))
                 + (float)(*(float *)(LODWORD(toSpot.y) + 372) * *(float *)(LODWORD(toSpot.y) + 372))) > 40000.0
        || (float)((float)((float)((float)(this->m_leaderAnchorPos.y - outAngle)
                                 * (float)(this->m_leaderAnchorPos.y - outAngle))
                         + (float)((float)(this->m_leaderAnchorPos.x - range)
                                 * (float)(this->m_leaderAnchorPos.x - range)))
                 + (float)((float)(this->m_leaderAnchorPos.z - angle) * (float)(this->m_leaderAnchorPos.z - angle))) > 62500.0 )
      {
        CCSBot::Follow(this: me, player: (CCSPlayer *)LODWORD(toSpot.y));
        return;
      }
    }
    if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1 )
    {
      if ( CBaseEntity::GetTeamNumber(this: me) == 3 )
      {
        m_task = me->m_task;
        if ( m_task == HOLD_POSITION
          && TheBots[1].m_debugMessage[0].m_string[460] != 0
          && *(float *)&TheBots[1].m_debugMessage[0].m_string[464] > me->m_stateTimestamp
          || m_task == GUARD_BOMB_DEFUSER && *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[472] == 0 )
        {
          goto LABEL_138;
        }
        if ( m_task == GUARD_LOOSE_BOMB )
        {
          if ( CCSBotManager::GetLooseBomb(this: (CCSBotManager *)TheBots) == nullptr )
          {
            BotChatterInterface::TheyPickedUpTheBomb(this: &me->m_chatter);
            CCSBot::Idle(this: me);
            return;
          }
          m_task = me->m_task;
        }
        if ( m_task == GUARD_BOMB_ZONE && CSGameState::IsLooseBombLocationKnown(this: &me->m_gameState) )
          goto LABEL_138;
        if ( CCSBot::IsDoingScenario(this: me)
          && me->m_task != GUARD_BOMB_DEFUSER
          && TheBots[1].m_debugMessage[0].m_string[460] != 0 )
        {
          CCSBot::Idle(this: me);
          return;
        }
      }
      else if ( *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[472] != 0 )
      {
        GetCentroid(result: (Vector *)&range, player: *(CBaseEntity **)&TheBots[1].m_debugMessage[0].m_string[472]);
        if ( (float)((float)((float)((float)(outAngle - v60.y) * (float)(outAngle - v60.y))
                           + (float)((float)(range - v60.x) * (float)(range - v60.x)))
                   + (float)((float)(angle - v60.z) * (float)(angle - v60.z))) < 4000000.0 )
        {
          if ( CCSBot::CanSeePlantedBomb(this: me) )
          {
            CCSBot::Attack(this: me, victim: *(CCSPlayer **)&TheBots[1].m_debugMessage[0].m_string[472]);
          }
          else
          {
            CCSBot::MoveTo(this: me, pos: (const Vector *)&range, route: FASTEST_ROUTE);
            CCSBot::InhibitLookAround(this: me, duration: 10.0);
          }
          return;
        }
      }
    }
    else if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)2 )
    {
      v7 = me->m_task;
      if ( v7 == GUARD_HOSTAGES )
      {
        if ( CSGameState::AreAllHostagesBeingRescued(this: &me->m_gameState)
          || CSGameState::AreAllHostagesGone(this: &me->m_gameState) != 0 )
        {
          goto LABEL_138;
        }
      }
      else if ( v7 == GUARD_HOSTAGE_RESCUE_ZONE )
      {
        NearestVisibleFreeHostage = CSGameState::GetNearestVisibleFreeHostage(this: &me->m_gameState);
        if ( NearestVisibleFreeHostage != nullptr )
        {
          GetCentroid(result: &v58, player: NearestVisibleFreeHostage);
          NearestNavArea = (CCSNavArea *)CNavMesh::GetNearestNavArea(
                                           this: TheNavMesh,
                                           pos: &v58,
                                           anyZ: false,
                                           maxDist: 10000.0,
                                           checkLOS: false,
                                           checkGround: true);
          if ( NearestNavArea != nullptr )
          {
            me->m_task = GUARD_HOSTAGES;
            me->m_taskEntity.m_Index = -1;
            CCSBot::Hide(
              this: me,
              searchFromArea: NearestNavArea,
              duration: -1.0,
              hideRange: 750.0,
              holdPosition: false);
            CBot<CCSPlayer>::PrintIfWatched(this: me, format: "I'm guarding hostages I found\n");
            return;
          }
        }
      }
    }
    if ( !CCSBot::IsSniper(this: me) || (v8 = !this->m_isAtSpot, HIBYTE(toSpot.x) = 1, v8) )
      HIBYTE(toSpot.x) = 0;
    v9 = CBaseCombatCharacter::GetActiveWeapon(this: me);
    if ( (v9 == nullptr || !v9->m_bInReload.m_Value)
      && HIBYTE(toSpot.x) == 0
      && CCSBot::GetDisposition(this: me) == ENGAGE_AND_INVESTIGATE )
    {
      if ( this->m_isHoldingPosition
        && this->m_heardEnemy
        && (float)(gpGlobals->curtime - this->m_firstHeardEnemyTime) > this->m_holdPositionTime )
      {
        goto LABEL_28;
      }
      if ( CCSBot::HeardInterestingNoise(this: me) )
      {
        if ( !this->m_isAtSpot || !this->m_isHoldingPosition )
        {
LABEL_28:
          CCSBot::InvestigateNoise(this: me);
          return;
        }
        if ( !this->m_heardEnemy )
        {
          m_holdPositionTime = this->m_holdPositionTime;
          this->m_heardEnemy = true;
          this->m_firstHeardEnemyTime = gpGlobals->curtime;
          CBot<CCSPlayer>::PrintIfWatched(
            this: me,
            format: "Heard enemy, holding position for %f2.1 seconds...\n",
            m_holdPositionTime);
        }
      }
    }
  }
  CCSBot::UpdateLookAround(this: me, a2: COERCE_FLOAT((Vector *)&toSpot.z), a3: (int)this, updateNow: false);
  if ( this->m_isAtSpot )
  {
    CCSBot::ResetStuckMonitor(this: me);
    NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: &this->m_hidingSpot, beneathLimit: 120.0);
    if ( NavArea == nullptr || (NavArea->m_attributeFlags & 0x400) == 0 )
      me->Crouch(this: me);
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_hideTimer) > this->m_hideTimer.m_timestamp.m_Value )
    {
      v15 = me->m_task;
      if ( v15 == GUARD_LOOSE_BOMB )
      {
        CCSBot::Hide(
          this: me,
          searchFromArea: *(CCSNavArea **)&TheBots[1].m_debugMessage[0].m_string[480],
          duration: -1.0,
          hideRange: 750.0,
          holdPosition: false);
        return;
      }
      if ( v15 == GUARD_BOMB_ZONE )
      {
        ClosestZone = CCSBotManager::GetClosestZone(this: (CCSBotManager *)TheBots, pos: &v60);
        if ( ClosestZone != nullptr )
        {
          RandomAreaInZone = (CCSNavArea *)CCSBotManager::GetRandomAreaInZone(
                                             this: (CCSBotManager *)TheBots,
                                             zone: ClosestZone);
          if ( RandomAreaInZone != nullptr )
          {
            CCSBot::Hide(
              this: me,
              searchFromArea: RandomAreaInZone,
              duration: -1.0,
              hideRange: 750.0,
              holdPosition: false);
            return;
          }
        }
      }
      else if ( v15 == GUARD_HOSTAGE_RESCUE_ZONE && CCSBot::GuardRandomZone(this: me, range: 500.0) != 0 )
      {
        me->m_task = GUARD_HOSTAGE_RESCUE_ZONE;
        me->m_taskEntity.m_Index = -1;
        CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Continuing to guard hostage rescue zones\n");
        CCSBot::SetDisposition(this: me, disposition: OPPORTUNITY_FIRE);
        BotChatterInterface::GuardingHostageEscapeZone(this: &me->m_chatter, isPlan: true);
        return;
      }
      goto LABEL_138;
    }
    if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me)
      && (!IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me)
       || !IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me)) )
    {
      me->SecondaryAttack(this: me);
    }
    if ( me->m_isEnemyVisible || (float)(gpGlobals->curtime - me->m_attackedTimestamp) >= 1.0 )
    {
      if ( !CCSBot::IsDoingScenario(this: me) && CBaseEntity::GetTeamNumber(this: me) == 3 )
      {
        if ( me->m_task == GUARD_BOMB_ZONE
          && CCSBot::IsAtHidingSpot(this: me)
          && TheBots[1].m_debugMessage[0].m_string[460] != 0
          && CCSBot::GetNearbyEnemyCount(this: me) == 0 )
        {
          if ( CCSBotManager::GetBombTimeLeft(this: (CCSBotManager *)TheBots) <= 30.0 )
          {
            if ( CCSBotManager::GetBombTimeLeft(this: (CCSBotManager *)TheBots) <= 11.0 )
            {
              repeatIntervalb = _RandomFloat(this: v19, a2: 3.0, a3: 4.0);
              BotChatterInterface::Encourage(
                this: &me->m_chatter,
                phraseName: "WaitingForHumanToDefuseBombPanic",
                repeatInterval: repeatIntervalb,
                lifetime: a3);
            }
            else
            {
              repeatIntervala = _RandomFloat(this: v19, a2: 5.0, a3: 8.0);
              BotChatterInterface::Encourage(
                this: &me->m_chatter,
                phraseName: "WaitingForHumanToDefuseBomb",
                repeatInterval: repeatIntervala,
                lifetime: a3);
            }
          }
          else
          {
            repeatInterval = _RandomFloat(this: v18, a2: 10.0, a3: 15.0);
            BotChatterInterface::Encourage(
              this: &me->m_chatter,
              phraseName: "BombsiteSecure",
              repeatInterval,
              lifetime: a3);
          }
        }
        if ( me->m_task == GUARD_HOSTAGES
          && CCSBot::IsAtHidingSpot(this: me)
          && CCSBot::GetNearbyEnemyCount(this: me) == 0
          && CSGameState::GetNearestVisibleFreeHostage(this: &me->m_gameState) != nullptr )
        {
          delay = _RandomFloat(this: v20, a2: 10.0, a3: 15.0);
          BotChatterInterface::Encourage(
            this: &me->m_chatter,
            phraseName: "WaitingForHumanToRescueHostages",
            repeatInterval: delay,
            lifetime: v55);
        }
      }
      return;
    }
LABEL_138:
    CCSBot::Idle(this: me);
    return;
  }
  if ( CCSBot::IsSniper(this: me) && me->m_isEnemyVisible )
  {
    p_m_pauseTimer = &this->m_pauseTimer;
    if ( this->m_isPaused )
    {
      if ( CountdownTimer::IsElapsed(this: p_m_pauseTimer) )
      {
        this->m_isPaused = false;
        v23 = _RandomFloat(this: v22, a2: 1.0, a3: 3.0);
LABEL_103:
        durationa = v23;
        CountdownTimer::Start(this: &this->m_pauseTimer, duration: durationa);
        goto LABEL_104;
      }
      CCSBot::Wait(this: me, duration: 0.2);
    }
    else if ( CountdownTimer::IsElapsed(this: p_m_pauseTimer) )
    {
      this->m_isPaused = true;
      v23 = _RandomFloat(this: v24, a2: 0.5, a3: 1.5);
      goto LABEL_103;
    }
  }
LABEL_104:
  LODWORD(toSpot.y) = &this->m_hidingSpot;
  ClosestPlayer = (CCSBot *)UTIL_GetClosestPlayer(pos: &this->m_hidingSpot, distance: &myOrigin.y);
  if ( ClosestPlayer != nullptr
    && ClosestPlayer != me
    && myOrigin.y < 75.0
    && CCSBot::IsVisible(this: me, player: ClosestPlayer, testFOV: true, visParts: nullptr) != 0 )
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Someone's in my hiding spot - picking another...\n");
    m_retry = this->m_retry;
    this->m_retry = m_retry + 1;
    if ( m_retry < 3 )
    {
      v27 = (CCSNavArea *)CNavMesh::GetNavArea(
                            this: TheNavMesh,
                            pos: (const Vector *)LODWORD(toSpot.y),
                            beneathLimit: 120.0);
      CCSBot::Hide(this: me, searchFromArea: v27, duration: -1.0, hideRange: 750.0, holdPosition: false);
      return;
    }
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Can't find a free hiding spot, giving up.\n");
    goto LABEL_138;
  }
  v28 = *(float *)LODWORD(toSpot.y) - v60.x;
  v29 = this->m_hidingSpot.y - v60.y;
  v30 = (unsigned int)me->m_iEFlags >> 11;
  range = v28;
  outAngle = v29;
  if ( (v30 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&toSpot.z);
    v29 = outAngle;
    v28 = range;
  }
  v8 = !me->m_isEnemyVisible;
  v31 = this->m_hidingSpot.z - me->m_vecAbsOrigin.z;
  v32 = 0;
  *(float *)&v32 = fsqrt((float)((float)(v29 * v29) + (float)(v31 * v31)) + (float)(v28 * v28));
  *(_OWORD *)v57 = v32;
  LODWORD(myOrigin.y) = v32;
  if ( v8 && !this->m_isLookingOutward && v57[0] < 200.0 && v57[0] > 10.0 )
  {
    v33 = 1.0 / v57[0];
    v34 = (float)(1.0 / v57[0]) * v28;
    this->m_isLookingOutward = true;
    EyePosition = me->EyePosition;
    range = v34 * 1000.0;
    outAngle = (float)(v33 * v29) * 1000.0;
    angle = (float)(v33 * v31) * 1000.0;
    v36 = (float *)EyePosition(this: me, result: &v58);
    hostageOrigin.x = *v36 - range;
    hostageOrigin.y = v36[1] - outAngle;
    hostageOrigin.z = v36[2] - angle;
    CCSBot::SetLookAt(
      this: me,
      desc: "Face outward",
      pos: &hostageOrigin,
      pri: PRIORITY_HIGH,
      duration: 3.0,
      clearIfClose: false,
      angleTolerance: 5.0,
      attack: false);
  }
  if ( myOrigin.y < 20.0 )
  {
    m_duration = this->m_duration;
    this->m_isAtSpot = true;
    CountdownTimer::Start(this: &this->m_hideTimer, duration: m_duration);
    CCSBot::ComputeApproachPoints(this: me);
    me->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
    me->m_lookAtDesc = nullptr;
    IsUsingGrenade = CCSBot::IsUsingGrenade(this: me);
    CCSBot::EquipBestWeapon(this: me, mustEquip: IsUsingGrenade);
    CCSBot::SetDisposition(this: me, disposition: OPPORTUNITY_FIRE);
    v40 = me->m_task;
    v41 = 0.0;
    if ( v40 == MOVE_TO_SNIPER_SPOT )
    {
      me->m_task = SNIPING;
      me->m_taskEntity.m_Index = -1;
    }
    else if ( v40 == GUARD_INITIAL_ENCOUNTER )
    {
      v41 = 0.0;
      if ( _RandomFloat(this: v39, a2: 0.0, a3: 100.0) < 20.0 )
      {
        BotChatterInterface::Say(this: &me->m_chatter, phraseName: "WaitingHere", lifetime: 3.0, delay: 0.0);
        v41 = 0.0;
      }
    }
    myOrigin.z = 0.0;
    myOrigin.x = 0.0;
    outAngleRange = 0.0;
    do
    {
      hostageOrigin.x = BotCOS(angle: v41);
      hostageOrigin.y = BotSIN(angle: outAngleRange);
      v42 = me->EyePosition;
      range = hostageOrigin.x * 1000.0;
      outAngle = hostageOrigin.y * 1000.0;
      v43 = (float *)v42(this: me, result: (Vector *)&result.hitbox);
      v44 = me->EyePosition;
      v58.x = range + *v43;
      v58.y = v43[1] + outAngle;
      v58.z = v43[2];
      v45 = (const Vector *)((int (__thiscall *)(CCSBot *))v44)(a1: me);
      UTIL_TraceLine(
        a1: (const IHandleEntity *)&toSpot.z,
        a2: (int)me,
        vecAbsStart: v45,
        vecAbsEnd: (const Vector *)&v57[1],
        mask: (unsigned int)&v58,
        ignore: (const IHandleEntity *)0x201400B,
        collisionGroup: (int)me,
        ptr: nullptr);
      if ( result.plane.normal.z > myOrigin.x )
      {
        myOrigin.z = outAngleRange;
        myOrigin.x = result.plane.normal.z;
      }
      v41 = outAngleRange + 45.0;
      outAngleRange = v41;
    }
    while ( v41 < 360.0 );
    me->m_lookAheadAngle = myOrigin.z;
  }
  if ( CCSBot::UpdatePathMovement(this: me, a2: (int)&toSpot.z, allowSpeedChange: true) != 0 && !this->m_isAtSpot )
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Can't get to my hiding spot - finding another...\n");
    IsSniper = CCSBot::IsSniper(this: me);
    NearbyHidingSpot = FindNearbyHidingSpot(
                         me,
                         pos: (const Vector *)LODWORD(toSpot.y),
                         maxRange: this->m_range,
                         isSniper: IsSniper,
                         useNearest: false);
    if ( NearbyHidingSpot != nullptr )
    {
      y = toSpot.y;
      *(float *)LODWORD(toSpot.y) = NearbyHidingSpot->x;
      *(float *)(LODWORD(y) + 4) = NearbyHidingSpot->y;
      *(float *)(LODWORD(y) + 8) = NearbyHidingSpot->z;
    }
    else
    {
      CBot<CCSPlayer>::PrintIfWatched(this: me, format: "No available hiding spots - hiding where I'm at.\n");
      *(_DWORD *)LODWORD(toSpot.y) = LODWORD(v60.y);
      if ( (me->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&toSpot.z);
      y = toSpot.y;
      this->m_hidingSpot.z = me->m_vecAbsOrigin.z;
    }
    if ( CCSBot::ComputePath(this: me, goal: (const Vector *)LODWORD(y), route: FASTEST_ROUTE) == 0 )
    {
      CBot<CCSPlayer>::PrintIfWatched(this: me, format: duration);
      goto LABEL_138;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D59A0
// Name: __CreateCServerGameTagsIServerGameTags_interface_44
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_44()
{
  return &_g_CServerGameTags_singleton_44;
}
