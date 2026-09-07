// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_attack.cpp
// Functions: 6
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_attack.h"

//------------------------------------------------------------------------------
// Address: 0x102D0800
// Name: protected: void AttackState::StopAttacking(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AttackState::StopAttacking(AttackState *this, CCSBot *me)
{
  CCSNavArea *v2; // eax

  if ( me->m_task == SNIPING )
  {
    v2 = (CCSNavArea *)me->GetLastKnownArea(this: me);
    CCSBot::Hide(this: me, searchFromArea: v2, duration: -1.0, hideRange: 50.0, holdPosition: false);
  }
  else
  {
    CCSBot::StopAttacking(this: me);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D0860
// Name: protected: void AttackState::Dodge(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge AttackState::Dodge(AttackState *this@<ecx>, float a2@<ebp>, CCSBot *me)
{
  CCSPlayer *BotEnemy; // eax
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  __int128 v8; // xmm0
  BOOL v9; // ecx
  float y; // xmm0_4
  AttackState::DodgeStateType v11; // eax
  double v12; // st7
  __int32 v13; // edi
  __int32 v14; // edi
  const Vector *AbsOrigin; // eax
  const Vector *v16; // eax
  const Vector *v17; // eax
  const Vector *v18; // eax
  Vector v19; // [esp+1Ch] [ebp-58h] BYREF
  __int128 forward; // [esp+28h] [ebp-4Ch] OVERLAPPED BYREF
  Vector pos; // [esp+38h] [ebp-3Ch]
  float v22; // [esp+44h] [ebp-30h]
  float v23; // [esp+48h] [ebp-2Ch]
  Vector v24; // [esp+4Ch] [ebp-28h] BYREF
  Vector right; // [esp+58h] [ebp-1Ch] BYREF
  CCSPlayer *minRange; // [esp+64h] [ebp-10h]
  float maxRange; // [esp+68h] [ebp-Ch] BYREF
  float ground; // [esp+6Ch] [ebp-8h]
  float retaddr; // [esp+74h] [ebp+0h]

  maxRange = a2;
  ground = retaddr;
  if ( this->m_shouldDodge && !CCSBot::IsUsingSniperRifle(this: me) && !this->m_crouchAndHold )
  {
    BotEnemy = CCSBot::GetBotEnemy(this: me);
    minRange = BotEnemy;
    if ( BotEnemy != nullptr )
    {
      if ( (me->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&maxRange);
        BotEnemy = minRange;
      }
      if ( (BotEnemy->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: BotEnemy, a2: (int)&maxRange);
        BotEnemy = minRange;
      }
      v5 = BotEnemy->m_vecAbsOrigin.x - me->m_vecAbsOrigin.x;
      v6 = BotEnemy->m_vecAbsOrigin.y - me->m_vecAbsOrigin.y;
      v7 = (float)((float)((float)(BotEnemy->m_vecAbsOrigin.z - me->m_vecAbsOrigin.z)
                         * (float)(BotEnemy->m_vecAbsOrigin.z - me->m_vecAbsOrigin.z))
                 + (float)(v6 * v6))
         + (float)(v5 * v5);
      v8 = 0;
      *(float *)&v8 = fsqrt(v7);
      forward = v8;
      *(float *)&v8 = me->m_combatRange + 125.0;
      right.x = me->m_combatRange - 125.0;
      LODWORD(right.y) = v8;
      if ( CCSBot::IsUsingKnife(this: me) )
        y = 999999.88;
      else
        y = right.y;
      if ( me->m_profile->m_skill < 0.66000003 || !me->m_isEnemyVisible )
      {
        if ( *(float *)&forward <= y )
        {
          if ( right.x > *(float *)&forward )
            me->MoveBackward(this: me);
        }
        else
        {
          me->MoveForward(this: me);
        }
      }
      if ( me->m_isEnemySniperVisible
        || *(float *)&forward <= 2000.0 && CBot<CCSPlayer>::IsPlayerFacingMe(this: me, other: minRange) )
      {
        if ( gpGlobals->curtime >= this->m_nextDodgeStateTimestamp )
        {
          if ( me->m_profile->m_skill > 0.5 && me->m_isEnemySniperVisible )
          {
            if ( this->m_firstDodge )
            {
              v9 = _RandomInt(this: (IUniformRandomStream *)v9, a2: 0, a3: 100) < 50;
              v11 = v9 + 1;
            }
            else
            {
              v11 = 2 - (this->m_dodgeState != SLIDE_LEFT);
            }
          }
          else
          {
            do
            {
              if ( !this->m_firstDodge
                || me->m_profile->m_skill >= 0.5
                || _RandomFloat(this: (IUniformRandomStream *)v9, a2: 0.0, a3: 100.0) >= 33.299999
                || CCSBot::IsNotMoving(this: me, minDuration: 0.0) )
              {
                v11 = _RandomInt(this: (IUniformRandomStream *)v9, a2: 0, a3: 2);
              }
              else
              {
                v11 = _RandomInt(this: (IUniformRandomStream *)v9, a2: 0, a3: 3);
              }
            }
            while ( !this->m_firstDodge && v11 == this->m_dodgeState );
          }
          this->m_dodgeState = v11;
          v12 = _RandomFloat(this: (IUniformRandomStream *)v9, a2: 0.30000001, a3: 1.0) + gpGlobals->curtime;
          this->m_firstDodge = false;
          this->m_nextDodgeStateTimestamp = v12;
        }
      }
      else
      {
        this->m_dodgeState = STEADY_ON;
        this->m_nextDodgeStateTimestamp = 0.0;
      }
      CBasePlayer::EyeVectors(this: me, pForward: &v19, pRight: &v24, pUp: nullptr);
      v13 = this->m_dodgeState - 1;
      if ( v13 != 0 )
      {
        v14 = v13 - 1;
        if ( v14 != 0 )
        {
          if ( v14 == 1 && me->m_isEnemyVisible )
            ((void (__thiscall *)(CCSBot *))me->Jump)(a1: me);
        }
        else
        {
          pos.z = v24.x * 30.0;
          v22 = v24.y * 30.0;
          v23 = v24.z * 30.0;
          AbsOrigin = CBaseEntity::GetAbsOrigin(this: me);
          *((float *)&forward + 1) = AbsOrigin->x + pos.z;
          *((float *)&forward + 2) = AbsOrigin->y + v22;
          *((float *)&forward + 3) = AbsOrigin->z + v23;
          if ( CCSBot::GetSimpleGroundHeightWithFloor(
                 this: me,
                 pos: (const Vector *)((char *)&forward + 4),
                 height: &right.z,
                 normal: nullptr) != 0 )
          {
            v16 = CBaseEntity::GetAbsOrigin(this: me);
            if ( (float)(v16->z - right.z) < 18.0 )
              me->StrafeRight(this: me);
          }
        }
      }
      else
      {
        pos.z = v24.x * 30.0;
        v22 = v24.y * 30.0;
        v23 = v24.z * 30.0;
        v17 = CBaseEntity::GetAbsOrigin(this: me);
        *((float *)&forward + 1) = v17->x - pos.z;
        *((float *)&forward + 2) = v17->y - v22;
        *((float *)&forward + 3) = v17->z - v23;
        if ( CCSBot::GetSimpleGroundHeightWithFloor(
               this: me,
               pos: (const Vector *)((char *)&forward + 4),
               height: &right.z,
               normal: nullptr) != 0 )
        {
          v18 = CBaseEntity::GetAbsOrigin(this: me);
          if ( (float)(v18->z - right.z) < 18.0 )
            me->StrafeLeft(this: me);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D0CC0
// Name: public: virtual void AttackState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge AttackState::OnUpdate(AttackState *this@<ecx>, int a2@<ebp>, CCSBot *me)
{
  CBaseCombatWeapon *ActiveWeapon; // edi
  unsigned int m_Index; // ecx
  CCSNavArea *v5; // eax
  CCSPlayer *z_low; // edi
  bool v7; // zf
  IUniformRandomStream *v8; // ecx
  CBaseEntity *v9; // edi
  float v10; // xmm0_4
  float v11; // xmm1_4
  IntervalTimer_vtbl *v12; // xmm2_4
  float z; // edi
  const Vector *AbsOrigin; // eax
  bool IsCurTaskContinuousMove; // al
  double v16; // st7
  bool v17; // al
  bool v18; // cc
  __int128 v19; // xmm0
  edict_t *m_pPev; // eax
  edict_t *v21; // eax
  IUniformRandomStream *v22; // ecx
  float x; // xmm0_4
  const Vector *NoisePosition; // eax
  IUniformRandomStream *v25; // ecx
  IUniformRandomStream *v26; // ecx
  const Vector *NearbyRetreatSpot; // edi
  bool IsUsingSniperRifle; // al
  float y; // xmm0_4
  CCSPlayer *Attacker; // eax
  CCSPlayer *v31; // eax
  float cosTolerance; // [esp+10h] [ebp-48h]
  __int128 range; // [esp+1Ch] [ebp-3Ch] BYREF
  Vector enemyPos; // [esp+2Ch] [ebp-2Ch] BYREF
  Vector myOrigin; // [esp+38h] [ebp-20h]
  CBasePlayer *notSeenEnemyTime; // [esp+44h] [ebp-14h]
  float ambushTime; // [esp+48h] [ebp-10h]
  _DWORD v38[2]; // [esp+4Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+58h] [ebp+0h]

  v38[0] = a2;
  v38[1] = retaddr;
  LODWORD(myOrigin.z) = this;
  CCSBot::ResetStuckMonitor(this: me);
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: me);
  if ( ActiveWeapon != nullptr
    && (((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 37
     || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 33
     || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 32
     || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 34
     || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 35
     || ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon) == 36) )
  {
    CCSBot::EquipBestWeapon(this: me, mustEquip: false);
  }
  m_Index = me->m_enemy.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || (notSeenEnemyTime = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr )
  {
    if ( me->m_task == SNIPING )
    {
      v5 = (CCSNavArea *)me->GetLastKnownArea(this: me);
      CCSBot::Hide(this: me, searchFromArea: v5, duration: -1.0, hideRange: 50.0, holdPosition: false);
    }
    else
    {
      CCSBot::StopAttacking(this: me);
    }
    return;
  }
  GetCentroid(result: &enemyPos, player: me);
  GetCentroid(result: (Vector *)((char *)&range + 4), player: notSeenEnemyTime);
  z_low = (CCSPlayer *)LODWORD(myOrigin.z);
  if ( *(_BYTE *)(LODWORD(myOrigin.z) + 28) == 0 )
    *(_BYTE *)(LODWORD(myOrigin.z) + 28) = me->m_isEnemyVisible;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&z_low->m_Network.m_PVSInfo.m_pClustersInline[2]) > *(float *)&z_low->m_Network.m_hParent.m_Index )
  {
    if ( gpGlobals->curtime <= z_low->m_Network.m_PVSInfo.m_vCenter[1] )
    {
      v7 = !me->m_isEnemySniperVisible;
      HIBYTE(ambushTime) = 0;
      if ( (v7 || CCSBot::IsSniper(this: me))
        && (!CCSBot::IsOutnumbered(this: me) || LOBYTE(z_low->m_Network.m_PVSInfo.m_pClustersInline[0]) == 0)
        && (CCSBot::OutnumberedCount(this: me) < 2 || me->m_profile->m_aggression >= 1.0) )
      {
        goto LABEL_35;
      }
    }
    else
    {
      HIBYTE(ambushTime) = 1;
    }
    if ( CCSBot::IsAnyVisibleEnemyLookingAtMe(this: me, testFOV: true) )
    {
      if ( HIBYTE(ambushTime) != 0 )
      {
        BotChatterInterface::PinnedDown(this: &me->m_chatter);
      }
      else if ( !me->m_isEnemySniperVisible )
      {
        BotChatterInterface::Scared(this: &me->m_chatter);
      }
      cosTolerance = _RandomFloat(this: v8, a2: 3.0, a3: 15.0);
      CountdownTimer::Start(
        this: (CountdownTimer *)&z_low->m_Network.m_PVSInfo.m_pClustersInline[2],
        duration: cosTolerance);
      if ( CCSBot::TryToRetreat(this: me, maxRange: 1000.0, duration: -1.0) != 0 )
      {
        if ( CCSBot::IsOutnumbered(this: me) )
          BotChatterInterface::NeedBackup(this: &me->m_chatter);
      }
      else
      {
        CBot<CCSPlayer>::PrintIfWatched(this: me, format: "I want to retreat, but no safe spots nearby!\n");
      }
    }
  }
LABEL_35:
  if ( CCSBot::IsUsingKnife(this: me) )
  {
    LOBYTE(z_low->m_Network.m_PVSInfo.m_vCenter[2]) = 0;
    me->StandUp(this: me);
    if ( CBot<CCSPlayer>::IsPlayerFacingMe(this: me, other: notSeenEnemyTime) )
    {
      CCSBot::ForceRun(this: me, duration: 5.0);
      CCSBot::Hurry(this: me, duration: 10.0);
    }
    CCSBot::FireWeaponAtEnemy(this: me, a2: (int)z_low);
    if ( (me->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)v38);
    v9 = notSeenEnemyTime;
    if ( (notSeenEnemyTime->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: notSeenEnemyTime, a2: (int)v38);
    if ( (float)((float)((float)((float)(v9->m_vecAbsOrigin.y - me->m_vecAbsOrigin.y)
                               * (float)(v9->m_vecAbsOrigin.y - me->m_vecAbsOrigin.y))
                       + (float)((float)(v9->m_vecAbsOrigin.x - me->m_vecAbsOrigin.x)
                               * (float)(v9->m_vecAbsOrigin.x - me->m_vecAbsOrigin.x)))
               + (float)((float)(v9->m_vecAbsOrigin.z - me->m_vecAbsOrigin.z)
                       * (float)(v9->m_vecAbsOrigin.z - me->m_vecAbsOrigin.z))) > 4900.0 )
    {
      if ( me->m_pathLength == 0 )
        goto LABEL_47;
      if ( (v9->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)v38);
      v10 = *(&me->m_avoidTimestamp + 6 * me->m_pathLength);
      v11 = *((float *)&me->m_isStopping + 6 * me->m_pathLength);
      v12 = (&me->m_stillTimer.__vftable)[6 * me->m_pathLength];
      if ( (float)((float)((float)((float)(v11 - v9->m_vecAbsOrigin.y) * (float)(v11 - v9->m_vecAbsOrigin.y))
                         + (float)((float)(v10 - v9->m_vecAbsOrigin.x) * (float)(v10 - v9->m_vecAbsOrigin.x)))
                 + (float)((float)(*(float *)&v12 - v9->m_vecAbsOrigin.z)
                         * (float)(*(float *)&v12 - v9->m_vecAbsOrigin.z))) > 10000.0 )
      {
LABEL_47:
        z = myOrigin.z;
        if ( IntervalTimer::Now(this: (CEffectsServer *)(LODWORD(myOrigin.z) + 12)) > *(float *)(LODWORD(z) + 20) )
        {
          AbsOrigin = CBaseEntity::GetAbsOrigin(this: notSeenEnemyTime);
          *(_QWORD *)((char *)&range + 4) = *(_QWORD *)&AbsOrigin->x;
          *((float *)&range + 3) = AbsOrigin->z + 35.5;
          CCSBot::ComputePath(this: me, goal: (const Vector *)((char *)&range + 4), route: FASTEST_ROUTE);
          CountdownTimer::Start(this: (CountdownTimer *)(LODWORD(z) + 12), duration: 0.5);
        }
      }
      if ( CCSBot::UpdatePathMovement(this: me, a2: (int)v38, allowSpeedChange: false) != 0 )
      {
        me->m_isStopping = false;
        me->m_pathLength = 0;
        me->m_pathLadder = nullptr;
      }
    }
    return;
  }
  if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me) )
  {
    if ( !me->m_isEnemyVisible || LOBYTE(z_low->m_Network.m_PVSInfo.m_vCenter[0]) != 0 )
    {
      if ( !IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me) )
        goto LABEL_64;
      IsCurTaskContinuousMove = IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me);
    }
    else
    {
      if ( !CCSBot::IsRecognizedEnemyReloading(this: me)
        && !CCSPlayer::IsReloading(this: me)
        && CBot<CCSPlayer>::IsPlayerLookingAtMe(this: me, other: notSeenEnemyTime, cosTolerance: 0.89999998) )
      {
        if ( !CCSPlayer::IsProtectedByShield(this: me) )
LABEL_63:
          me->SecondaryAttack(this: me);
LABEL_64:
        if ( gpGlobals->curtime > *(float *)&z_low->m_Network.m_PVSInfo.m_nAreaNum )
        {
          v16 = _RandomFloat(this: (IUniformRandomStream *)gpGlobals, a2: 0.5, a3: 2.0);
          v17 = LOBYTE(z_low->m_Network.m_PVSInfo.m_vCenter[0]) == 0;
          *(float *)&z_low->m_Network.m_PVSInfo.m_nAreaNum = v16 + gpGlobals->curtime;
          LOBYTE(z_low->m_Network.m_PVSInfo.m_vCenter[0]) = v17;
        }
        goto LABEL_66;
      }
      IsCurTaskContinuousMove = CCSPlayer::IsProtectedByShield(this: me);
    }
    if ( !IsCurTaskContinuousMove )
      goto LABEL_64;
    goto LABEL_63;
  }
LABEL_66:
  if ( CCSBot::IsUsingSniperRifle(this: me) )
  {
    v18 = (float)((float)((float)((float)(*((float *)&range + 2) - enemyPos.y)
                                * (float)(*((float *)&range + 2) - enemyPos.y))
                        + (float)((float)(*((float *)&range + 1) - enemyPos.x)
                                * (float)(*((float *)&range + 1) - enemyPos.x)))
                + (float)((float)(*((float *)&range + 3) - enemyPos.z) * (float)(*((float *)&range + 3) - enemyPos.z))) >= 25600.0;
    goto LABEL_70;
  }
  if ( CCSBot::IsUsingShotgun(this: me) )
  {
    v18 = (float)((float)((float)((float)(*((float *)&range + 2) - enemyPos.y)
                                * (float)(*((float *)&range + 2) - enemyPos.y))
                        + (float)((float)(*((float *)&range + 1) - enemyPos.x)
                                * (float)(*((float *)&range + 1) - enemyPos.x)))
                + (float)((float)(*((float *)&range + 3) - enemyPos.z) * (float)(*((float *)&range + 3) - enemyPos.z))) <= 360000.0;
LABEL_70:
    if ( !v18 )
      CCSBot::EquipPistol(this: me);
  }
  if ( !CCSBot::IsUsingSniperRifle(this: me) )
    goto LABEL_123;
  if ( me->m_bResumeZoom.m_Value )
  {
    *(float *)&z_low->m_Network.m_pPev = gpGlobals->curtime;
    return;
  }
  v19 = 0;
  *(float *)&v19 = fsqrt(
                     (float)((float)((float)(me->m_aimSpot.y - enemyPos.y) * (float)(me->m_aimSpot.y - enemyPos.y))
                           + (float)((float)(me->m_aimSpot.z - enemyPos.z) * (float)(me->m_aimSpot.z - enemyPos.z)))
                   + (float)((float)(me->m_aimSpot.x - enemyPos.x) * (float)(me->m_aimSpot.x - enemyPos.x)));
  range = v19;
  if ( CCSBot::GetZoomLevel(this: me) == NO_ZOOM && CCSBot::AdjustZoom(this: me, range: *(float *)&range) != 0 )
    *(float *)&z_low->m_Network.m_pPev = gpGlobals->curtime;
  if ( (float)(me->m_profile->m_reactionTime + 0.30000001) <= (float)(gpGlobals->curtime
                                                                    - *(float *)&z_low->m_Network.m_pPev) )
  {
LABEL_123:
    if ( CCSBot::IsAwareOfEnemyDeath(this: me) )
    {
      m_pPev = notSeenEnemyTime->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      if ( (edict_t *)me->m_lastVictimID == m_pPev && CCSBot::GetNearbyEnemyCount(this: me) <= 1 )
      {
        v21 = CBaseEntity::entindex(this: notSeenEnemyTime);
        BotChatterInterface::KilledMyEnemy(this: &me->m_chatter, victimID: (int)v21);
        if ( CBot<CCSPlayer>::GetEnemiesRemaining(this: me) != 0 )
        {
          *((float *)&range + 1) = _RandomFloat(this: v22, a2: 1.0, a3: 3.0);
          CCSBot::Wait(this: me, duration: *((float *)&range + 1));
        }
      }
      goto LABEL_86;
    }
    x = gpGlobals->curtime - me->m_lastSawEnemyTimestamp;
    myOrigin.x = x;
    if ( me->m_isEnemyVisible )
    {
      BYTE1(z_low->m_Network.m_PVSInfo.m_vCenter[2]) = 0;
      if ( HIBYTE(z_low->m_Network.m_PVSInfo.m_nHeadNode) != 0 )
      {
        *(float *)&z_low->m_Network.m_PVSInfo.m_pClusters = me->m_profile->m_reactionTime + gpGlobals->curtime;
        HIBYTE(z_low->m_Network.m_PVSInfo.m_nHeadNode) = 0;
      }
    }
    else
    {
      if ( x > 0.5 )
      {
        if ( CCSBot::CanHearNearbyEnemyGunfire(this: me, range: -1.0) != 0 )
        {
          AttackState::StopAttacking(this: (AttackState *)z_low, me);
          NoisePosition = CCSBot::GetNoisePosition(this: me);
          if ( NoisePosition != nullptr )
          {
            CCSBot::SetLookAt(
              this: me,
              desc: "Nearby enemy gunfire",
              pos: NoisePosition,
              pri: PRIORITY_HIGH,
              duration: 0.0,
              clearIfClose: false,
              angleTolerance: 5.0,
              attack: false);
            CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Checking nearby threatening enemy gunfire!\n");
            return;
          }
        }
        x = myOrigin.x;
      }
      if ( x > 0.25 )
        HIBYTE(z_low->m_Network.m_PVSInfo.m_nHeadNode) = 1;
      if ( x > 0.1 )
      {
        if ( CCSBot::GetDisposition(this: me) != ENGAGE_AND_INVESTIGATE )
          goto LABEL_86;
        if ( LOBYTE(z_low->m_Network.m_PVSInfo.m_nHeadNode) != 0 && BYTE1(z_low->m_Network.m_PVSInfo.m_vCenter[2]) == 0 )
        {
          if ( _RandomFloat(this: v25, a2: 0.0, a3: 100.0) < 33.299999 )
          {
            myOrigin.y = _RandomFloat(this: v26, a2: 3.0, a3: 15.0);
            NearbyRetreatSpot = FindNearbyRetreatSpot(me, maxRange: 200.0);
            if ( NearbyRetreatSpot != nullptr )
            {
              CCSBot::IgnoreEnemies(this: me, duration: 1.0);
              me->Run(this: me);
              me->StandUp(this: me);
              CCSBot::Hide(this: me, hidingSpot: NearbyRetreatSpot, duration: myOrigin.y, holdPosition: true);
              return;
            }
            z_low = (CCSPlayer *)LODWORD(myOrigin.z);
          }
          BYTE1(z_low->m_Network.m_PVSInfo.m_vCenter[2]) = 1;
        }
      }
    }
    myOrigin.y = (float)((float)(1.0 - me->m_profile->m_aggression) + 1.0) * 2.0;
    IsUsingSniperRifle = CCSBot::IsUsingSniperRifle(this: me);
    y = myOrigin.y;
    if ( IsUsingSniperRifle )
    {
      y = myOrigin.y + 3.0;
    }
    else if ( me->m_isCrouching )
    {
      y = myOrigin.y + 1.0;
    }
    if ( me->m_isEnemyVisible )
      goto LABEL_120;
    if ( myOrigin.x > y || LOBYTE(z_low->m_Network.m_PVSInfo.m_nHeadNode) == 0 )
    {
      if ( me->m_task != SNIPING )
      {
        CCSBot::SetTask(this: me, task: MOVE_TO_LAST_KNOWN_ENEMY_POSITION, entity: notSeenEnemyTime);
        CCSBot::MoveTo(this: me, pos: &me->m_lastEnemyPosition, route: SAFEST_ROUTE);
        return;
      }
LABEL_86:
      AttackState::StopAttacking(this: (AttackState *)z_low, me);
      return;
    }
    if ( (float)(gpGlobals->curtime - me->m_attackedTimestamp) >= 3.0
      || CCSBot::GetAttacker(this: me) == nullptr
      || (z_low = CCSBot::GetBotEnemy(this: me), CCSBot::GetAttacker(this: me) == z_low) )
    {
LABEL_120:
      CCSBot::FireWeaponAtEnemy(this: me, a2: (int)z_low);
      AttackState::Dodge(this: (AttackState *)LODWORD(myOrigin.z), a2: COERCE_FLOAT(v38), me);
      return;
    }
    *((_QWORD *)&range + 1) = 1;
    Attacker = CCSBot::GetAttacker(this: me);
    if ( CCSBot::IsVisible(
           this: me,
           player: Attacker,
           testFOV: SBYTE8(range),
           visParts: (unsigned __int8 *)HIDWORD(range)) != 0 )
    {
      v31 = CCSBot::GetAttacker(this: me);
      CCSBot::Attack(this: me, victim: v31);
      CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Switching targets to retaliate against new attacker!\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1730
// Name: public: virtual void AttackState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge AttackState::OnEnter(AttackState *this@<ecx>, int a2@<ebx>, CCSBot *me)
{
  unsigned int m_Index; // eax
  int m_postureStackIndex; // eax
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  double v9; // st7
  int *v10; // ebx
  IUniformRandomStream *v11; // ecx
  float v12; // xmm0_4
  Vector *Centroid; // ebx
  Vector *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  double v18; // st7
  int v19; // eax
  int (__thiscall *v20)(int *); // edx
  const Vector *v21; // eax
  const BotProfile *m_profile; // ecx
  IUniformRandomStream *v23; // ecx
  CGameTrace result; // [esp+18h] [ebp-70h] BYREF
  Vector v25; // [esp+6Ch] [ebp-1Ch] BYREF
  Vector origin; // [esp+78h] [ebp-10h] BYREF
  float crouchChance; // [esp+84h] [ebp-4h]
  IHandleEntity savedregs; // [esp+88h] [ebp+0h] BYREF
  CBasePlayer *dodgeChance; // [esp+90h] [ebp+8h]
  float dodgeChancea; // [esp+90h] [ebp+8h]
  float dodgeChanceb; // [esp+90h] [ebp+8h]

  m_Index = me->m_enemy.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    dodgeChance = nullptr;
  else
    dodgeChance = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  m_postureStackIndex = me->m_postureStackIndex;
  if ( m_postureStackIndex == 8 )
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "PushPostureContext() overflow error!\n");
  }
  else
  {
    me->m_postureStack[m_postureStackIndex].isRunning = me->m_isRunning;
    me->m_postureStack[me->m_postureStackIndex++].isCrouching = me->m_isCrouching;
  }
  me->m_isStopping = false;
  me->m_pathLength = 0;
  me->m_pathLadder = nullptr;
  if ( dodgeChance != nullptr
    && CCSBot::IsUsingKnife(this: me)
    && !CBot<CCSPlayer>::IsPlayerFacingMe(this: me, other: dodgeChance) )
  {
    ((void (__thiscall *)(CCSBot *, int))me->Walk)(a1: me, a2);
  }
  else
  {
    ((void (__thiscall *)(CCSBot *, int))me->Run)(a1: me, a2);
  }
  CCSBot::GetOffLadder(this: me);
  CCSBot::ResetStuckMonitor(this: me);
  if ( this->m_repathTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_repathTimer.NetworkStateChanged(this: &this->m_repathTimer, a2: &this->m_repathTimer.m_timestamp);
    this->m_repathTimer.m_timestamp.m_Value = -1.0;
  }
  LOBYTE(v7) = me->m_isEnemyVisible;
  this->m_nextDodgeStateTimestamp = 0.0;
  this->m_reacquireTimestamp = 0.0;
  this->m_haveSeenEnemy = (char)v7;
  this->m_firstDodge = true;
  this->m_isEnemyHidden = false;
  this->m_pinnedDownTimestamp = _RandomFloat(this: v7, a2: 7.0, a3: 10.0) + gpGlobals->curtime;
  v9 = _RandomFloat(this: v8, a2: 2.0, a3: 10.0) + gpGlobals->curtime;
  this->m_shieldForceOpen = false;
  this->m_shieldToggleTimestamp = v9;
  if ( CCSBot::IsEscapingFromBomb(this: me) )
    CCSBot::EquipBestWeapon(this: me, mustEquip: false);
  if ( CCSBot::IsUsingKnife(this: me) || me->m_isEnemySniperVisible && !CCSBot::IsSniper(this: me) )
  {
    this->m_crouchAndHold = false;
    me->StandUp(this: me);
  }
  else
  {
    if ( this->m_crouchAndHold )
      goto LABEL_34;
    v10 = (int *)dodgeChance;
    if ( dodgeChance != nullptr )
    {
      if ( CCSBot::IsUsingSniperRifle(this: me) )
      {
        v12 = 50.0;
      }
      else
      {
        Centroid = GetCentroid(result: &origin, player: dodgeChance);
        v14 = GetCentroid(result: &v25, player: me);
        v15 = v14->x - Centroid->x;
        v16 = v14->y - Centroid->y;
        v17 = v14->z - Centroid->z;
        v10 = (int *)dodgeChance;
        v12 = (float)((float)((float)(v16 * v16) + (float)(v15 * v15)) + (float)(v17 * v17)) <= 562500.0
            ? (float)(1.0 - me->m_profile->m_aggression) * 20.0
            : 50.0;
      }
      crouchChance = v12;
      v18 = _RandomFloat(this: v11, a2: 0.0, a3: 100.0);
      if ( crouchChance > v18 )
      {
        GetCentroid(result: &origin, player: me);
        if ( !me->m_isCrouching )
          origin.z = origin.z - 20.0;
        v19 = *v10;
        LODWORD(result.startpos.y) = &result;
        v20 = *(int (__thiscall **)(int *))(v19 + 504);
        result.startpos.x = 0.0;
        v21 = (const Vector *)v20(a1: v10);
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)me,
          vecAbsStart: &origin,
          vecAbsEnd: v21,
          mask: (unsigned int)&v25,
          ignore: (const IHandleEntity *)0x201400B,
          collisionGroup: (int)me,
          ptr: (CGameTrace *)LODWORD(result.startpos.x));
        if ( result.fraction == 1.0 )
          this->m_crouchAndHold = true;
      }
    }
    if ( this->m_crouchAndHold )
    {
LABEL_34:
      me->Crouch(this: me);
      CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Crouch and hold attack!\n");
    }
  }
  this->m_scopeTimestamp = 0.0;
  this->m_didAmbushCheck = false;
  m_profile = me->m_profile;
  dodgeChancea = m_profile->m_skill * 80.0;
  if ( m_profile->m_skill > 0.5 && (CCSBot::IsOutnumbered(this: me) || me->m_isEnemySniperVisible) )
    dodgeChancea = 100.0;
  this->m_shouldDodge = (double)dodgeChancea >= _RandomFloat(
                                                  this: (IUniformRandomStream *)m_profile,
                                                  a2: 0.0,
                                                  a3: 100.0);
  dodgeChanceb = me->m_profile->m_aggression;
  this->m_isCoward = _RandomFloat(this: v23, a2: 0.0, a3: 100.0) > dodgeChanceb * 100.0;
}

//------------------------------------------------------------------------------
// Address: 0x102D1B40
// Name: public: virtual void AttackState::OnExit(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AttackState::OnExit(AttackState *this, CCSBot *me)
{
  int m_postureStackIndex; // eax
  int v4; // eax

  CBot<CCSPlayer>::PrintIfWatched(this: me, format: "AttackState:OnExit()\n");
  this->m_crouchAndHold = false;
  me->m_noiseTimestamp = 0.0;
  CCSBot::ResetStuckMonitor(this: me);
  m_postureStackIndex = me->m_postureStackIndex;
  if ( m_postureStackIndex != 0 )
  {
    v4 = m_postureStackIndex - 1;
    me->m_postureStackIndex = v4;
    *(CBot<CCSPlayer>::PostureContext *)&me->m_isRunning = me->m_postureStack[v4];
  }
  else
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "PopPostureContext() underflow error!\n");
    *(_WORD *)&me->m_isRunning = 1;
  }
  if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me)
    && IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me) )
  {
    me->SecondaryAttack(this: me);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1BE0
// Name: __CreateCServerGameTagsIServerGameTags_interface_37
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_37()
{
  return &_g_CServerGameTags_singleton_37;
}
