// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_update.cpp
// Functions: 20
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_update.h"

//------------------------------------------------------------------------------
// Address: 0x102C1980
// Name: public: bool CCSPlayer::IsAutoFollowAllowed(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSPlayer::IsAutoFollowAllowed(CCSPlayer *this)
{
  return gpGlobals->curtime > this->m_allowAutoFollowTime;
}

//------------------------------------------------------------------------------
// Address: 0x102C19B0
// Name: public: class Vector const __near * CCSBot::GetNoisePosition(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCSBot::GetNoisePosition(CCSBot *this)
{
  if ( this->m_noiseTimestamp <= 0.0 )
    return nullptr;
  else
    return &this->m_noisePosition;
}

//------------------------------------------------------------------------------
// Address: 0x102C19D0
// Name: public: bool CCSBot::CanAutoFollow(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::CanAutoFollow(CCSBot *this)
{
  return gpGlobals->curtime > this->m_allowAutoFollowTime;
}

//------------------------------------------------------------------------------
// Address: 0x102C19F0
// Name: public: virtual float CCSBot::GetMoveSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBot::GetMoveSpeed(CCSBot *this)
{
  return 250.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C1A60
// Name: public: bool CCSBot::IsAwareOfEnemyDeath(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsAwareOfEnemyDeath(CCSBot *this)
{
  bool result; // al
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *v10; // eax

  if ( this->m_enemyDeathTimestamp == 0.0 )
    return false;
  m_Index = this->m_enemy.m_Index;
  result = true;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = &g_pEntityList->m_EntPtrArray[v7];
      v10 = v8 ? v9->m_pEntity : nullptr;
      if ( v10->__vftable[22].GetRefEHandle(this: v10) != nullptr
        || (float)(gpGlobals->curtime - this->m_enemyDeathTimestamp) <= (float)(1.0
                                                                              - (float)(this->m_profile->m_skill
                                                                                      * 0.80000001)) )
      {
        return false;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C1B10
// Name: public: class CCSPlayer __near * CCSBot::GetBomber(void)const
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CCSBot::GetBomber(CCSBot *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_bomber.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x102C1B40
// Name: public: class CCSPlayer __near * CCSBot::GetClosestVisibleHumanFriend(void)const
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CCSBot::GetClosestVisibleHumanFriend(CCSBot *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_closestVisibleHumanFriend.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x102C1B70
// Name: public: bool CCSBot::IsEnemyPartVisible(enum CCSBot::VisiblePartType)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsEnemyPartVisible(CCSBot *this, CCSBot::VisiblePartType part)
{
  bool v4; // bl

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::IsEnemyPartVisible",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( this->m_isEnemyVisible )
  {
    v4 = ((unsigned __int8)part & this->m_visibleEnemyParts) != 0;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return v4;
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C1BD0
// Name: public: virtual void CCSBot::Upkeep(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSBot::Upkeep(CCSBot *this@<ecx>, int a2@<edi>)
{
  IUniformRandomStream *v3; // ecx
  int v4; // eax
  IUniformRandomStream *v5; // ecx
  int v6; // eax
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  float *v9; // eax
  CBaseEntity *v10; // eax
  CBaseEntity *v11; // eax
  CCSBot::VisiblePartType v12; // edi
  bool IsEnemyPartVisible; // al
  CCSBot *v14; // ecx
  CCSPlayer *BotEnemy; // eax
  const Vector *PartPosition; // eax
  double z; // st7
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *PunchAngle; // eax
  const BotProfile *m_profile; // ecx
  float v24; // xmm2_4
  CCSBot::LookAtSpotState m_lookAtSpotState; // eax
  __int32 v26; // eax
  float m_lookAtSpotDuration; // xmm0_4
  double v28; // st7
  double v29; // st7
  CCSBot::VisiblePartType angleTolerance; // [esp+0h] [ebp-4Ch]
  Vector enemyOrigin; // [esp+24h] [ebp-28h] BYREF
  QAngle idealAngle; // [esp+30h] [ebp-1Ch] BYREF
  Vector to; // [esp+3Ch] [ebp-10h] BYREF
  float driftAmplitude; // [esp+48h] [ebp-4h]
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::Upkeep",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( TheNavMesh->m_generationMode != GENERATE_NONE || !this->IsAlive(this) )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  if ( cv_bot_flipout.m_pParent != nullptr && cv_bot_flipout.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = _RandomInt(this: v3, a2: 0, a3: 2);
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
        this->MoveBackward(this);
    }
    else
    {
      this->MoveForward(this);
    }
    v6 = _RandomInt(this: v5, a2: 0, a3: 2);
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
        this->StrafeRight(this);
    }
    else
    {
      this->StrafeLeft(this);
    }
    if ( _RandomInt(this: v7, a2: 0, a3: 5) == 0 )
      this->Jump(this, a2: true);
    if ( _RandomInt(this: v8, a2: 0, a3: 2) == 0 )
      this->Crouch(this);
    this->StandUp(this);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  v9 = (float *)((int (__thiscall *)(CCSBot *, QAngle *, int))this->EyePosition)(a1: this, a2: &idealAngle, a3: a2);
  this->m_eyePosition.x = *v9;
  this->m_eyePosition.y = v9[1];
  this->m_eyePosition.z = v9[2];
  GetCentroid(result: &to, player: this);
  if ( !this->m_isAimingAtEnemy )
  {
    if ( this->m_lookAtSpotClearIfClose
      && (float)((float)((float)((float)(this->m_lookAtSpot.y - to.y) * (float)(this->m_lookAtSpot.y - to.y))
                       + (float)((float)(this->m_lookAtSpot.x - to.x) * (float)(this->m_lookAtSpot.x - to.x)))
               + (float)((float)(this->m_lookAtSpot.z - to.z) * (float)(this->m_lookAtSpot.z - to.z))) < 10000.0 )
    {
      this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
    }
    m_lookAtSpotState = this->m_lookAtSpotState;
    if ( m_lookAtSpotState != NOT_LOOKING_AT_SPOT )
    {
      v26 = m_lookAtSpotState - 1;
      if ( v26 != 0 )
      {
        if ( v26 == 1 )
        {
          CCSBot::UpdateLookAt(this);
          m_lookAtSpotDuration = this->m_lookAtSpotDuration;
          if ( m_lookAtSpotDuration >= 0.0
            && (float)(gpGlobals->curtime - this->m_lookAtSpotTimestamp) > m_lookAtSpotDuration )
          {
            this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
            this->m_lookAtSpotDuration = 0.0;
          }
        }
      }
      else
      {
        CCSBot::UpdateLookAt(this);
        if ( CBot<CCSPlayer>::IsLookingAtPosition(
               this,
               pos: &this->m_lookAtSpot,
               angleTolerance: this->m_lookAtSpotAngleTolerance) )
        {
          this->m_lookAtSpotState = LOOK_AT_SPOT;
          this->m_lookAtSpotTimestamp = gpGlobals->curtime;
        }
      }
    }
    else
    {
      this->m_lookYaw = this->m_lookAheadAngle;
      this->m_lookPitch = 0.0;
    }
    if ( !CCSBot::IsUsingSniperRifle(this) )
    {
      driftAmplitude = 2.0;
      if ( CCSPlayer::IsBlind(this) )
        driftAmplitude = 5.0;
      v28 = BotCOS(angle: gpGlobals->curtime * 33.0);
      this->m_lookYaw = v28 * driftAmplitude + this->m_lookYaw;
      v29 = BotSIN(angle: gpGlobals->curtime * 13.0);
      this->m_lookPitch = v29 * driftAmplitude + this->m_lookPitch;
    }
    goto LABEL_59;
  }
  CCSBot::UpdateAimOffset(this, a2: (int)&savedregs, a3: a2);
  if ( !CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)&this->m_enemy, val: nullptr)
    || (v10 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_enemy),
        !v10->IsAlive(this: v10)) )
  {
LABEL_59:
    CCSBot::UpdateLookAngles(this);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_enemy);
  GetCentroid(result: &enemyOrigin, player: v11);
  if ( this->m_isEnemyVisible )
  {
    if ( CCSBot::IsUsingMachinegun(this)
      || CCSBot::IsUsing(this, weaponID: WEAPON_AWP)
      || CCSBot::IsUsingShotgun(this)
      || this->m_profile->m_skill > 0.5 && CBot<CCSPlayer>::IsActiveWeaponRecoilHigh(this)
      || (v12 = HEAD, this->m_profile->m_skill < 0.80000001) )
    {
      v12 = GUT;
    }
    IsEnemyPartVisible = CCSBot::IsEnemyPartVisible(this, part: v12);
    v14 = this;
    if ( IsEnemyPartVisible )
    {
      angleTolerance = v12;
    }
    else
    {
      v18 = CCSBot::IsEnemyPartVisible(this, part: GUT);
      v14 = this;
      if ( v18 )
      {
        angleTolerance = GUT;
      }
      else
      {
        v19 = CCSBot::IsEnemyPartVisible(this, part: HEAD);
        v14 = this;
        if ( v19 )
        {
          angleTolerance = HEAD;
        }
        else
        {
          v20 = CCSBot::IsEnemyPartVisible(this, part: LEFT_SIDE);
          v14 = this;
          if ( v20 )
          {
            angleTolerance = LEFT_SIDE;
          }
          else
          {
            v21 = CCSBot::IsEnemyPartVisible(this, part: RIGHT_SIDE);
            v14 = this;
            if ( v21 )
              angleTolerance = RIGHT_SIDE;
            else
              angleTolerance = FEET;
          }
        }
      }
    }
    BotEnemy = CCSBot::GetBotEnemy(this: v14);
    PartPosition = CCSBot::GetPartPosition(this, player: BotEnemy, part: angleTolerance);
    this->m_aimSpot.x = PartPosition->x;
    this->m_aimSpot.y = PartPosition->y;
    z = PartPosition->z;
  }
  else
  {
    this->m_aimSpot.x = this->m_lastEnemyPosition.x;
    this->m_aimSpot.y = this->m_lastEnemyPosition.y;
    z = this->m_lastEnemyPosition.z;
  }
  this->m_aimSpot.z = z;
  this->m_aimSpot.x = this->m_aimOffset.x + this->m_aimSpot.x;
  this->m_aimSpot.y = this->m_aimOffset.y + this->m_aimSpot.y;
  this->m_aimSpot.z = this->m_aimOffset.z + this->m_aimSpot.z;
  to.x = this->m_aimSpot.x - this->m_eyePosition.x;
  to.y = this->m_aimSpot.y - this->m_eyePosition.y;
  to.z = this->m_aimSpot.z - this->m_eyePosition.z;
  VectorAngles(forward: &to, angles: &idealAngle);
  PunchAngle = CBasePlayer::GetPunchAngle(this);
  m_profile = this->m_profile;
  v24 = idealAngle.x - (float)(PunchAngle->m_Value.x * m_profile->m_skill);
  this->m_lookYaw = idealAngle.y - (float)(PunchAngle->m_Value.y * m_profile->m_skill);
  this->m_lookPitch = v24;
  CCSBot::UpdateLookAngles(this);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102C2260
// Name: public: bool CCSBot::HasSeenSniperRecently(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::HasSeenSniperRecently(CCSBot *this)
{
  return IntervalTimer::Now(this: (CEffectsServer *)&this->m_sawEnemySniperTimer) <= this->m_sawEnemySniperTimer.m_timestamp.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102C22A0
// Name: public: bool CCSBot::IsWaiting(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::IsWaiting(CCSBot *this)
{
  return IntervalTimer::Now(this: (CEffectsServer *)&this->m_waitTimer) <= this->m_waitTimer.m_timestamp.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102C22E0
// Name: public: bool CCSBot::HasViewBeenSteady(float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::HasViewBeenSteady(CCSBot *this, float duration)
{
  float v2; // xmm0_4
  float v4; // [esp+0h] [ebp-4h]

  if ( this->m_viewSteadyTimer.m_timestamp.m_Value <= 0.0 )
  {
    v2 = 99999.898;
  }
  else
  {
    v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_viewSteadyTimer)
       - this->m_viewSteadyTimer.m_timestamp.m_Value;
    v2 = v4;
  }
  return v2 > duration;
}

//------------------------------------------------------------------------------
// Address: 0x102C2340
// Name: public: bool DrawTravelTime::operator()(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall DrawTravelTime::operator()(DrawTravelTime *this, CCSPlayer *player)
{
  CCSBot *m_me; // ecx
  double TravelDistanceToPlayer; // st7
  char *v5; // eax
  CCSPlayer *v6; // eax
  CFmtStrN<256> msg; // [esp+24h] [ebp-10Ch] BYREF

  if ( player->IsAlive(this: player) && !CBaseEntity::InSameTeam(this: &this->m_me->CBot<CCSPlayer>, pEntity: player) )
  {
    m_me = (CCSBot *)this->m_me;
    msg.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
    *(_WORD *)&msg.m_bQuietTruncation = 1;
    msg.m_nLength = 0;
    TravelDistanceToPlayer = CCSBot::GetTravelDistanceToPlayer(this: m_me, player);
    v5 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "%3.0f", TravelDistanceToPlayer);
    CBaseEntity::EntityText(this: player, text_offset: 0, text: v5, duration: 0.1, r: 255, g: 255, b: 255, a: 255);
    if ( player->IsPlayer(this: player) )
      v6 = (CCSPlayer *)__RTDynamicCast(
                          inptr: player,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
    else
      v6 = nullptr;
    if ( CCSBot::DidPlayerJustFireWeapon(this: (CCSBot *)this->m_me, player: v6) )
      CBaseEntity::EntityText(
        this: player,
        text_offset: 1,
        text: "BANG!",
        duration: 0.1,
        r: 255,
        g: 255,
        b: 255,
        a: 255);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102C26A0
// Name: private: void CCSBot::DebugDisplay(void)const
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSBot::DebugDisplay(CCSBot *this@<ecx>, int a2@<edi>, float a3@<esi>)
{
  const BotProfile *m_profile; // eax
  char *v5; // eax
  const CNavLadder *m_pathLadder; // eax
  char *v7; // eax
  double SafeTimeRemaining; // st7
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  const char *v15; // eax
  char *v16; // eax
  float v17; // xmm0_4
  const char *v18; // eax
  char *v19; // eax
  char *TaskName; // eax
  char *v21; // eax
  char *DispositionName; // eax
  char *v23; // eax
  char *MoraleName; // eax
  CCSBot::LookAtSpotState m_lookAtSpotState; // eax
  bool v26; // zf
  const char *v27; // eax
  char *v28; // eax
  const char *v29; // eax
  char *v30; // eax
  char *v31; // eax
  char *v32; // eax
  CNavArea *m_lastNavArea; // eax
  char *v34; // eax
  CBotManager *v35; // edx
  int m_debugMessageCount; // eax
  int v37; // ecx
  int v38; // eax
  int m_string; // ebx
  double v40; // st7
  double v41; // st6
  double v42; // st7
  double v43; // st6
  float v44; // xmm0_4
  int v45; // eax
  int v46; // eax
  unsigned int v47; // eax
  CCSPlayer **v48; // ecx
  CCSPlayer *v49; // edi
  const Vector *PartPosition; // eax
  const Vector *v51; // eax
  const Vector *v52; // eax
  const Vector *v53; // eax
  const Vector *v54; // eax
  int v55; // [esp+1Ch] [ebp-13Ch]
  int duration; // [esp+20h] [ebp-138h]
  int v57; // [esp+24h] [ebp-134h]
  CFmtStrN<256> msg; // [esp+2Ch] [ebp-12Ch] BYREF
  Vector startPos; // [esp+138h] [ebp-20h] BYREF
  float v61; // [esp+144h] [ebp-14h]
  float y; // [esp+148h] [ebp-10h]
  int alpha; // [esp+14Ch] [ebp-Ch] BYREF
  float v64; // [esp+150h] [ebp-8h]
  int i; // [esp+154h] [ebp-4h]

  v57 = a2;
  m_profile = this->m_profile;
  msg.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  *(_WORD *)&msg.m_bQuietTruncation = 1;
  msg.m_nLength = 0;
  v5 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
         this: &msg,
         pszFormat: "Skill: %d%%",
         (int)(float)(m_profile->m_skill * 100.0));
  NDebugOverlay::ScreenText(flXpos: 0.5, flYpos: 0.34, text: v5, r: 255, g: 255, b: 255, a: 150, duration: 0.15000001);
  m_pathLadder = this->m_pathLadder;
  if ( m_pathLadder != nullptr )
  {
    v7 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "Ladder: %d", m_pathLadder->m_id);
    NDebugOverlay::ScreenText(
      flXpos: 0.5,
      flYpos: 0.36000001,
      text: v7,
      r: 255,
      g: 255,
      b: 255,
      a: 150,
      duration: 0.15000001);
  }
  SafeTimeRemaining = CCSBot::GetSafeTimeRemaining(this);
  *(float *)&i = SafeTimeRemaining;
  if ( SafeTimeRemaining > 0.0 )
  {
    v9 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "SafeTime: %3.2f", *(float *)&i);
    NDebugOverlay::ScreenText(flXpos: 0.5, flYpos: 0.38, text: v9, r: 255, g: 255, b: 255, a: 150, duration: 0.15000001);
  }
  if ( this->m_blindUntilTime > gpGlobals->curtime )
  {
    v10 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "<<< BLIND >>>");
    NDebugOverlay::ScreenText(
      flXpos: 0.5,
      flYpos: 0.38,
      text: v10,
      r: 255,
      g: 255,
      b: 255,
      a: 255,
      duration: 0.15000001);
  }
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_alertTimer) <= this->m_alertTimer.m_timestamp.m_Value )
  {
    v11 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "ALERT");
    NDebugOverlay::ScreenText(flXpos: 0.5, flYpos: 0.38, text: v11, r: 255, g: 0, b: 0, a: 255, duration: 0.15000001);
  }
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_panicTimer) <= this->m_panicTimer.m_timestamp.m_Value )
  {
    v12 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "PANIC");
    NDebugOverlay::ScreenText(
      flXpos: 0.5,
      flYpos: 0.36000001,
      text: v12,
      r: 255,
      g: 255,
      b: 0,
      a: 255,
      duration: 0.15000001);
  }
  if ( this->m_isAttacking )
  {
    m_Index = this->m_enemy.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    duration = 1041865114;
    v55 = 255;
    v15 = (const char *)((int (__stdcall *)(int, _DWORD))m_pEntity->__vftable[13].SetRefEHandle)(a1: 255, a2: 0);
    v16 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "ATTACKING: %s", v15);
    v17 = 0.40000001;
  }
  else
  {
    v18 = (const char *)((int (__stdcall *)(int, int))this->m_state->GetName)(a1: 255, a2: 255);
    v19 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "State: %s", v18);
    NDebugOverlay::ScreenText(
      flXpos: 0.5,
      flYpos: 0.40000001,
      text: v19,
      r: 0,
      g: 255,
      b: 1041865114,
      a: a2,
      duration: a3);
    TaskName = CCSBot::GetTaskName(this);
    v21 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "Task: %s", TaskName);
    NDebugOverlay::ScreenText(
      flXpos: 0.5,
      flYpos: 0.41999999,
      text: v21,
      r: 0,
      g: 255,
      b: 0,
      a: 255,
      duration: 0.15000001);
    DispositionName = CCSBot::GetDispositionName(this);
    v23 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "Disposition: %s", DispositionName);
    NDebugOverlay::ScreenText(
      flXpos: 0.5,
      flYpos: 0.44,
      text: v23,
      r: 100,
      g: 100,
      b: 255,
      a: 255,
      duration: 0.15000001);
    a3 = 0.15000001;
    v57 = 255;
    duration = 200;
    v55 = 200;
    MoraleName = CCSBot::GetMoraleName(this);
    v16 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "Morale: %s", MoraleName);
    v17 = 0.46000001;
  }
  NDebugOverlay::ScreenText(flXpos: 0.5, flYpos: v17, text: v16, r: 0, g: v55, b: duration, a: v57, duration: a3);
  m_lookAtSpotState = this->m_lookAtSpotState;
  if ( m_lookAtSpotState != NOT_LOOKING_AT_SPOT )
  {
    v26 = m_lookAtSpotState == LOOK_TOWARDS_SPOT;
    v27 = "LOOK_TOWARDS_SPOT";
    if ( !v26 )
      v27 = "LOOK_AT_SPOT";
    v28 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
            this: &msg,
            pszFormat: "LookAt: %s (%s)",
            this->m_lookAtDesc,
            v27);
    NDebugOverlay::ScreenText(
      flXpos: 0.5,
      flYpos: 0.60000002,
      text: v28,
      r: 255,
      g: 255,
      b: 0,
      a: 150,
      duration: 0.15000001);
  }
  if ( this->m_viewSteadyTimer.m_timestamp.m_Value > 0.0
    && (*(float *)&i = IntervalTimer::Now(this: (CEffectsServer *)&this->m_viewSteadyTimer)
                     - this->m_viewSteadyTimer.m_timestamp.m_Value,
        *(float *)&i <= 0.2) )
  {
    v29 = "NO";
  }
  else
  {
    v29 = "YES";
  }
  v30 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &msg, pszFormat: "Steady view = %s", v29);
  NDebugOverlay::ScreenText(flXpos: 0.5, flYpos: 0.62, text: v30, r: 255, g: 255, b: 0, a: 150, duration: 0.15000001);
  v31 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &msg,
          pszFormat: "Nearby friends = %d",
          this->m_nearbyFriendCount);
  NDebugOverlay::ScreenText(
    flXpos: 0.5,
    flYpos: 0.63999999,
    text: v31,
    r: 100,
    g: 255,
    b: 100,
    a: 150,
    duration: 0.15000001);
  v32 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &msg,
          pszFormat: "Nearby enemies = %d",
          this->m_nearbyEnemyCount);
  NDebugOverlay::ScreenText(
    flXpos: 0.5,
    flYpos: 0.66000003,
    text: v32,
    r: 255,
    g: 100,
    b: 100,
    a: 150,
    duration: 0.15000001);
  m_lastNavArea = this->CBot<CCSPlayer>::CCSPlayer::m_lastNavArea;
  if ( m_lastNavArea != nullptr )
  {
    v34 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
            this: &msg,
            pszFormat: "Nav Area: %d (%s)",
            m_lastNavArea->m_id,
            this->m_szLastPlaceName.m_Value);
    NDebugOverlay::ScreenText(
      flXpos: 0.5,
      flYpos: 0.68000001,
      text: v34,
      r: 255,
      g: 255,
      b: 255,
      a: 150,
      duration: 0.15000001);
  }
  v35 = TheBots;
  m_debugMessageCount = TheBots->m_debugMessageCount;
  *(float *)&v37 = 0.0;
  y = 0.80000001;
  *(float *)&i = 0.0;
  if ( m_debugMessageCount > 0 )
  {
    do
    {
      v38 = v35->m_currentDebugMessage - v37 + (v35->m_currentDebugMessage - v37 < 0 ? 6 : 0);
      m_string = (int)v35->m_debugMessage[v38].m_string;
      if ( v35->m_debugMessage[v38].m_age.m_timestamp.m_Value > 0.0 )
      {
        v40 = IntervalTimer::Now(this: (CEffectsServer *)&v35->m_debugMessage[v38].m_age);
        v41 = *(float *)(m_string + 1028);
        v61 = *(float *)(m_string + 1028);
        v64 = v40 - v41;
        if ( v64 < 10.0 )
        {
          alpha = 255;
          if ( v61 > 0.0
            && (v42 = IntervalTimer::Now(this: (CEffectsServer *)(m_string + 1024)),
                v43 = *(float *)(m_string + 1028),
                v61 = *(float *)(m_string + 1028),
                (v64 = v42 - v43) <= 7.0) )
          {
            v45 = alpha;
          }
          else
          {
            if ( v61 <= 0.0 )
            {
              v44 = 99999.898;
            }
            else
            {
              v64 = IntervalTimer::Now(this: (CEffectsServer *)(m_string + 1024)) - *(float *)(m_string + 1028);
              v44 = v64;
            }
            v45 = (int)(float)((float)(1.0 - (float)((float)(v44 - 7.0) * 0.33333334)) * 255.0);
          }
          NDebugOverlay::ScreenText(
            flXpos: 0.5,
            flYpos: y,
            text: (const char *)m_string,
            r: 255,
            g: 255,
            b: 255,
            a: v45,
            duration: 0.15000001);
          y = y + 0.02;
        }
        v37 = i;
        v35 = TheBots;
      }
      v46 = v35->m_debugMessageCount;
      i = ++v37;
    }
    while ( v37 < v46 );
  }
  if ( this->m_noiseTimestamp > 0.0 && this != (CCSBot *)-14820 )
  {
    startPos.x = this->m_noisePosition.x;
    startPos.y = this->m_noisePosition.y;
    startPos.z = this->m_noisePosition.z + 25.0;
    NDebugOverlay::VertArrow(
      &startPos,
      endPos: &this->m_noisePosition,
      width: 6.25,
      r: 255,
      g: 255,
      b: 0,
      a: 0,
      noDepthTest: 1,
      flDuration: 0.15000001);
  }
  if ( this->m_isAimingAtEnemy )
    NDebugOverlay::Cross3D(
      position: &this->m_aimSpot,
      size: 5.0,
      r: 255,
      g: 0,
      b: 0,
      noDepthTest: 1,
      flDuration: 0.15000001);
  if ( CCSBot::IsHiding(this) )
    CCSBot::DrawApproachPoints(this);
  alpha = (int)this;
  ForEachPlayer<DrawTravelTime>(func: (DrawTravelTime *)&alpha);
  if ( CCSBot::IsAttacking(this) )
  {
    v47 = this->m_enemy.m_Index;
    if ( v47 != -1 )
    {
      v48 = (CCSPlayer **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v47];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_SerialNumber == HIWORD(v47) )
      {
        v49 = *v48;
        if ( *v48 != nullptr )
        {
          PartPosition = CCSBot::GetPartPosition(this, player: v49, part: GUT);
          NDebugOverlay::Cross3D(position: PartPosition, size: 2.0, r: 0, g: 255, b: 0, noDepthTest: 1, flDuration: 0.1);
          v51 = CCSBot::GetPartPosition(this, player: v49, part: HEAD);
          NDebugOverlay::Cross3D(position: v51, size: 2.0, r: 0, g: 255, b: 0, noDepthTest: 1, flDuration: 0.1);
          v52 = CCSBot::GetPartPosition(this, player: v49, part: FEET);
          NDebugOverlay::Cross3D(position: v52, size: 2.0, r: 0, g: 255, b: 0, noDepthTest: 1, flDuration: 0.1);
          v53 = CCSBot::GetPartPosition(this, player: v49, part: LEFT_SIDE);
          NDebugOverlay::Cross3D(position: v53, size: 2.0, r: 0, g: 255, b: 0, noDepthTest: 1, flDuration: 0.1);
          v54 = CCSBot::GetPartPosition(this, player: v49, part: RIGHT_SIDE);
          NDebugOverlay::Cross3D(position: v54, size: 2.0, r: 0, g: 255, b: 0, noDepthTest: 1, flDuration: 0.1);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C31A0
// Name: private: void CCSBot::UpdateTravelDistanceToAllPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::UpdateTravelDistanceToAllPlayers(CCSBot *this)
{
  CountdownTimer *p_m_updateTravelDistanceTimer; // ecx
  float *p_m_Value; // ebx
  int v4; // eax
  CBasePlayer *v5; // eax
  CBaseEntity *v6; // esi
  edict_t *m_pPev; // eax
  signed int v8; // eax
  int v9; // ebx
  float v10; // xmm0_4
  const Vector *v11; // eax
  double v12; // st7
  ShortestPathCost *v13; // [esp-8h] [ebp-34h]
  Vector goalPos; // [esp+8h] [ebp-24h] BYREF
  _BYTE v15[12]; // [esp+14h] [ebp-18h] BYREF
  float v16; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  ShortestPathCost pathCost; // [esp+2Bh] [ebp-1h] BYREF

  p_m_updateTravelDistanceTimer = &this->m_updateTravelDistanceTimer;
  p_m_Value = &p_m_updateTravelDistanceTimer->m_timestamp.m_Value;
  LODWORD(v16) = &p_m_updateTravelDistanceTimer->m_timestamp;
  if ( IntervalTimer::Now(this: (CEffectsServer *)p_m_updateTravelDistanceTimer) <= p_m_updateTravelDistanceTimer->m_timestamp.m_Value )
    return;
  v4 = 1;
  i = 1;
  if ( gpGlobals->maxClients < 1 )
    goto LABEL_20;
  do
  {
    v5 = UTIL_PlayerByIndex(playerIndex: v4);
    v6 = v5;
    if ( v5 != nullptr )
    {
      m_pPev = v5->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v6->IsPlayer(this: v6)
        && v6->IsAlive(this: v6)
        && !CBaseEntity::InSameTeam(this: v6, pEntity: this) )
      {
        v8 = (signed int)v6->m_Network.m_pPev;
        if ( v8 != 0 )
          v8 = (signed int)(v8 - (unsigned int)gpGlobals->pEdicts) >> 4;
        v9 = v8 % 64;
        v10 = this->m_playerTravelDistance[v8 % 64];
        if ( v10 < 0.0 || v10 > 4000.0 )
        {
          if ( this->m_travelDistancePhase != 0 )
            goto LABEL_18;
LABEL_17:
          v13 = (ShortestPathCost *)((int (__thiscall *)(CBaseEntity *, _BYTE *, ShortestPathCost *))v6->EyePosition)(
                                      a1: v6,
                                      a2: v15,
                                      a3: &pathCost);
          v11 = (const Vector *)((int (__thiscall *)(CCSBot *))this->EyePosition)(a1: this);
          this->m_playerTravelDistance[v9] = NavAreaTravelDistance<ShortestPathCost>(
                                               startPos: v11,
                                               &goalPos,
                                               costFunc: v13);
          goto LABEL_18;
        }
        if ( v10 <= 2000.0 || this->m_travelDistancePhase != 0 )
          goto LABEL_17;
      }
    }
LABEL_18:
    v4 = i + 1;
    i = v4;
  }
  while ( v4 <= gpGlobals->maxClients );
  p_m_Value = (float *)LODWORD(v16);
LABEL_20:
  v12 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_updateTravelDistanceTimer) + 1.0;
  v16 = v12;
  if ( *p_m_Value != v12 )
  {
    (**((void (__thiscall ***)(int, float *))p_m_Value - 2))(a1: (int)(p_m_Value - 2), a2: p_m_Value);
    *p_m_Value = v16;
  }
  if ( this->m_updateTravelDistanceTimer.m_duration.m_Value != 1.0 )
  {
    this->m_updateTravelDistanceTimer.NetworkStateChanged(
      this: &this->m_updateTravelDistanceTimer,
      a2: &this->m_updateTravelDistanceTimer.m_duration);
    this->m_updateTravelDistanceTimer.m_duration.m_Value = 1.0;
  }
  if ( ++this->m_travelDistancePhase >= 3u )
    this->m_travelDistancePhase = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102C3380
// Name: public: virtual void CCSBot::Update(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CCSBot::Update(CCSBot *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  float v3; // xmm0_4
  CNavArea *v4; // ecx
  int v5; // eax
  IntervalTimer *v6; // ecx
  const Vector *AbsOrigin; // ebx
  const Vector *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm1_4
  CCSPlayer *v11; // eax
  CBaseEntity *v12; // eax
  CBaseEntity *v13; // eax
  double curtime; // st7
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseEntity *v16; // eax
  const Vector *Centroid; // eax
  CCSPlayer *Bomber; // eax
  CBaseEntity *LooseBomb; // eax
  unsigned __int8 v20; // al
  bool v21; // zf
  float v22; // xmm0_4
  double BombTimeLeft; // st7
  int v24; // ecx
  double v25; // st7
  CCSPlayer *ClosestVisibleHumanFriend; // eax
  CNavArea *NavArea; // eax
  int (__thiscall *v28)(_DWORD); // eax
  CNavArea *v29; // eax
  double v30; // st7
  const char *v31; // eax
  CBaseEntity *v32; // eax
  float v33; // xmm0_4
  int v34; // ecx
  CBaseCombatWeapon *v35; // eax
  int v36; // eax
  CNavArea *cosTolerance; // [esp+4h] [ebp-44h]
  CNavArea *beneathLimit; // [esp+8h] [ebp-40h]
  Vector leaderOrigin; // [esp+24h] [ebp-24h] BYREF
  Vector myOrigin; // [esp+30h] [ebp-18h] BYREF
  float gonnaBlowTime; // [esp+3Ch] [ebp-Ch] BYREF
  PathCost costFunc; // [esp+40h] [ebp-8h] BYREF
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  HIDWORD(a3) = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::Update",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( cv_bot_flipout.m_pParent != nullptr && cv_bot_flipout.m_pParent->m_Value.m_nValue != 0 )
    goto LABEL_5;
  GetCentroid(result: &myOrigin, player: (CBaseEntity *)HIDWORD(a3));
  if ( CBaseEntity::GetTeamNumber(this: (CBaseEntity *)HIDWORD(a3)) == 0 )
  {
    CCSPlayer::HandleCommand_JoinTeam(this: (CCSPlayer *)HIDWORD(a3), team: *(_DWORD *)(HIDWORD(a3) + 14788));
    CCSPlayer::HandleCommand_JoinClass(this: (CCSPlayer *)HIDWORD(a3), a2: a3);
LABEL_5:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  BotChatterInterface::Update(this: (BotChatterInterface *)(HIDWORD(a3) + 16800));
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(a3) + 272))(a1: HIDWORD(a3)) == 0 )
  {
    *(_BYTE *)(HIDWORD(a3) + 7324) = 1;
    CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)HIDWORD(a3));
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  *(_BYTE *)(HIDWORD(a3) + 14792) = 1;
  if ( cv_bot_debug.m_pParent != nullptr
    && cv_bot_debug.m_pParent->m_Value.m_nValue != 0
    && CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this: (CBot<CCSPlayer> *)HIDWORD(a3)) )
  {
    CCSBot::DebugDisplay(this: (CCSBot *)HIDWORD(a3), a2: a3, a3: *((float *)&a3 + 1));
  }
  if ( cv_bot_stop.m_pParent != nullptr && cv_bot_stop.m_pParent->m_Value.m_nValue != 0 )
    goto LABEL_5;
  CCSBot::StuckCheck(this: (CCSBot *)HIDWORD(a3), a2: (int)&savedregs);
  CCSBot::BreakablesCheck(this: (CCSBot *)HIDWORD(a3), a2);
  CCSBot::DoorCheck(this: (CCSBot *)HIDWORD(a3));
  CCSBot::UpdateTravelDistanceToAllPlayers(this: (CCSBot *)HIDWORD(a3));
  v3 = *(float *)(HIDWORD(a3) + 14836);
  if ( v3 > 0.0 && (float)(gpGlobals->curtime - v3) > 20.0 )
    *(_DWORD *)(HIDWORD(a3) + 14836) = 0;
  v4 = *(CNavArea **)(HIDWORD(a3) + 7868);
  if ( v4 == nullptr || !CNavArea::Contains(this: v4, pos: &myOrigin) )
    *(_DWORD *)(HIDWORD(a3) + 7868) = CNavMesh::GetNavArea(this: TheNavMesh, pos: &myOrigin, beneathLimit: 120.0);
  v5 = *(_DWORD *)(HIDWORD(a3) + 7868);
  if ( v5 != 0 && v5 != *(_DWORD *)(HIDWORD(a3) + 7872) )
  {
    beneathLimit = *(CNavArea **)(HIDWORD(a3) + 7868);
    *(_DWORD *)(HIDWORD(a3) + 7872) = v5;
    CCSBot::OnEnteredNavArea(this: (CCSBot *)HIDWORD(a3), newArea: beneathLimit);
  }
  if ( (*(_DWORD *)(HIDWORD(a3) + 196) & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: (CBaseEntity *)HIDWORD(a3), a2: (int)&savedregs);
  v6 = (IntervalTimer *)(HIDWORD(a3) + 7888);
  if ( (float)((float)((float)(*(float *)(HIDWORD(a3) + 364) * *(float *)(HIDWORD(a3) + 364))
                     + (float)(*(float *)(HIDWORD(a3) + 368) * *(float *)(HIDWORD(a3) + 368)))
             + (float)(*(float *)(HIDWORD(a3) + 372) * *(float *)(HIDWORD(a3) + 372))) >= 100.0 )
    IntervalTimer::Invalidate(this: v6);
  else
    IntervalTimer::Start(this: v6);
  if ( *(float *)(HIDWORD(a3) + 4796) > gpGlobals->curtime && *(_BYTE *)(HIDWORD(a3) + 7340) != 0 )
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(a3) + 2100))(a1: HIDWORD(a3));
  CCSBot::UpdatePanicLookAround(this: (CCSBot *)HIDWORD(a3));
  CCSBot::UpdateReactionQueue(this: (CCSBot *)HIDWORD(a3));
  LODWORD(a3) = CCSBot::GetRecognizedEnemy(this: (CCSBot *)HIDWORD(a3));
  if ( (_DWORD)a3 != 0 )
  {
    GetCentroid(result: (Vector *)&gonnaBlowTime, player: (CBaseEntity *)a3);
    CCSBot::AdjustSafeTime(this: (CCSBot *)HIDWORD(a3));
    CCSBot::BecomeAlert(this: (CCSBot *)HIDWORD(a3));
    switch ( CCSBot::GetDisposition(this: (CCSBot *)HIDWORD(a3)) )
    {
      case ENGAGE_AND_INVESTIGATE:
      case OPPORTUNITY_FIRE:
        if ( (float)((float)((float)((float)(myOrigin.x - gonnaBlowTime) * (float)(myOrigin.x - gonnaBlowTime))
                           + (float)((float)(myOrigin.y - *(float *)&costFunc.m_bot)
                                   * (float)(myOrigin.y - *(float *)&costFunc.m_bot)))
                   + (float)((float)(myOrigin.z - *(float *)&costFunc.m_route)
                           * (float)(myOrigin.z - *(float *)&costFunc.m_route))) <= 4000000.0
          || CCSBot::IsSniper(this: (CCSBot *)HIDWORD(a3))
          || CBot<CCSPlayer>::IsPlayerLookingAtMe(
               this: (CBot<CCSPlayer> *)HIDWORD(a3),
               other: (CBasePlayer *)a3,
               cosTolerance: 0.99000001)
          && CCSBot::DidPlayerJustFireWeapon(this: (CCSBot *)HIDWORD(a3), player: (CCSPlayer *)a3) )
        {
          goto LABEL_45;
        }
        goto $LN368;
      case SELF_DEFENSE:
        if ( (!CBot<CCSPlayer>::IsPlayerLookingAtMe(
                 this: (CBot<CCSPlayer> *)HIDWORD(a3),
                 other: (CBasePlayer *)a3,
                 cosTolerance: 0.99000001)
           || !CCSBot::DidPlayerJustFireWeapon(this: (CCSBot *)HIDWORD(a3), player: (CCSPlayer *)a3))
          && (float)((float)((float)((float)(myOrigin.x - gonnaBlowTime) * (float)(myOrigin.x - gonnaBlowTime))
                           + (float)((float)(myOrigin.y - *(float *)&costFunc.m_bot)
                                   * (float)(myOrigin.y - *(float *)&costFunc.m_bot)))
                   + (float)((float)(myOrigin.z - *(float *)&costFunc.m_route)
                           * (float)(myOrigin.z - *(float *)&costFunc.m_route))) >= 250000.0 )
        {
          goto $LN368;
        }
        goto LABEL_45;
      default:
$LN368:
        if ( CCSBot::IsAttacking(this: (CCSBot *)HIDWORD(a3))
          || CCSBot::GetDisposition(this: (CCSBot *)HIDWORD(a3)) == IGNORE_ENEMIES
          || (float)(gpGlobals->curtime - *(float *)(HIDWORD(a3) + 16440)) >= 1.0 )
        {
          CCSBot::SetBotEnemy(this: (CCSBot *)HIDWORD(a3), enemy: (CCSPlayer *)a3);
          *(_BYTE *)(HIDWORD(a3) + 15852) = 1;
        }
        else
        {
          CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)HIDWORD(a3), format: "Ouch! Retaliating!\n");
LABEL_45:
          if ( !CCSBot::IsAttacking(this: (CCSBot *)HIDWORD(a3))
            || (CCSPlayer *)a3 != CCSBot::GetBotEnemy(this: (CCSBot *)HIDWORD(a3)) )
          {
            if ( !CCSBot::IsUsingKnife(this: (CCSBot *)HIDWORD(a3))
              || !CCSBot::IsHiding(this: (CCSBot *)HIDWORD(a3))
              || (AbsOrigin = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)a3),
                  v8 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)HIDWORD(a3)),
                  v9 = v8->y - AbsOrigin->y,
                  (float)((float)((float)((float)(v8->x - AbsOrigin->x) * (float)(v8->x - AbsOrigin->x))
                                + (float)(v9 * v9))
                        + (float)((float)(v8->z - AbsOrigin->z) * (float)(v8->z - AbsOrigin->z))) < 62500.0) )
            {
              CCSBot::Attack(this: (CCSBot *)HIDWORD(a3), victim: (CCSPlayer *)a3);
            }
          }
        }
        *(float *)&TheBots[1].m_debugMessage[0].m_string[692] = gpGlobals->curtime;
        break;
    }
  }
  if ( !CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)(HIDWORD(a3) + 15848), val: nullptr) )
    goto LABEL_56;
  if ( CCSBot::IsAwareOfEnemyDeath(this: (CCSBot *)HIDWORD(a3)) )
  {
    *(_DWORD *)(HIDWORD(a3) + 15848) = -1;
LABEL_56:
    *(_BYTE *)(HIDWORD(a3) + 15852) = 0;
    goto LABEL_57;
  }
  v11 = (CCSPlayer *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)(HIDWORD(a3) + 15848));
  if ( CCSBot::IsVisible(
         this: (CCSBot *)HIDWORD(a3),
         player: v11,
         testFOV: false,
         visParts: (unsigned __int8 *)(HIDWORD(a3) + 15853)) )
  {
    *(_BYTE *)(HIDWORD(a3) + 15852) = 1;
    *(float *)(HIDWORD(a3) + 15868) = gpGlobals->curtime;
    v12 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)(HIDWORD(a3) + 15848));
    *(Vector *)(HIDWORD(a3) + 15856) = *GetCentroid(result: &leaderOrigin, player: v12);
  }
  else
  {
    *(_BYTE *)(HIDWORD(a3) + 15852) = 0;
  }
  v13 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)(HIDWORD(a3) + 15848));
  if ( v13->IsAlive(this: v13) )
  {
    *(_DWORD *)(HIDWORD(a3) + 15880) = 0;
    *(_BYTE *)(HIDWORD(a3) + 15888) = 0;
  }
  else if ( *(float *)(HIDWORD(a3) + 15880) == 0.0 )
  {
    curtime = gpGlobals->curtime;
    *(_BYTE *)(HIDWORD(a3) + 15888) = 1;
    *(float *)(HIDWORD(a3) + 15880) = curtime;
  }
LABEL_57:
  v10 = *(float *)(HIDWORD(a3) + 4796);
  costFunc.m_route = LODWORD(gpGlobals->curtime);
  if ( v10 > *(float *)&costFunc.m_route
    || CCSBot::IsLookingAtSpot(this: (CCSBot *)HIDWORD(a3), pri: PRIORITY_UNINTERRUPTABLE) )
  {
    if ( *(_BYTE *)(HIDWORD(a3) + 16456) == 0 )
      goto LABEL_71;
  }
  else if ( CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)(HIDWORD(a3) + 15848), val: nullptr)
         && (float)(*(float *)&costFunc.m_route - *(float *)(HIDWORD(a3) + 15868)) < 3.0 )
  {
    *(_BYTE *)(HIDWORD(a3) + 16456) = 1;
    goto LABEL_71;
  }
  *(_BYTE *)(HIDWORD(a3) + 16456) = 0;
LABEL_71:
  if ( CCSBot::GetDisposition(this: (CCSBot *)HIDWORD(a3)) == IGNORE_ENEMIES )
    CCSBot::FireWeaponAtEnemy(this: (CCSBot *)HIDWORD(a3), a2: a3);
  CCSBot::LookForGrenadeTargets(this: (CCSBot *)HIDWORD(a3), a2: COERCE_FLOAT(&savedregs));
  CCSBot::UpdateGrenadeThrow(this: (CCSBot *)HIDWORD(a3));
  CCSBot::AvoidEnemyGrenades(this: (CCSBot *)HIDWORD(a3));
  if ( !CCSBot::IsSafe(this: (CCSBot *)HIDWORD(a3))
    && !CCSBot::IsUsingGrenade(this: (CCSBot *)HIDWORD(a3))
    && CBot<CCSPlayer>::IsActiveWeaponOutOfAmmo(this: (CBot<CCSPlayer> *)HIDWORD(a3)) )
  {
    CCSBot::EquipBestWeapon(this: (CCSBot *)HIDWORD(a3), mustEquip: false);
  }
  if ( !CCSBot::IsSafe(this: (CCSBot *)HIDWORD(a3))
    && !CCSBot::IsUsingGrenade(this: (CCSBot *)HIDWORD(a3))
    && CCSBot::IsUsingKnife(this: (CCSBot *)HIDWORD(a3))
    && !CCSBot::IsEscapingFromBomb(this: (CCSBot *)HIDWORD(a3)) )
  {
    CCSBot::EquipBestWeapon(this: (CCSBot *)HIDWORD(a3), mustEquip: false);
  }
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: (CBaseCombatCharacter *)HIDWORD(a3));
  if ( (ActiveWeapon == nullptr || !ActiveWeapon->m_bInReload.m_Value)
    && CCSBot::IsUsingPistol(this: (CCSBot *)HIDWORD(a3))
    && !CCSBot::IsPrimaryWeaponEmpty(this: (CCSBot *)HIDWORD(a3))
    && (float)(gpGlobals->curtime - *(float *)(HIDWORD(a3) + 15868)) > 5.0 )
  {
    CCSBot::EquipBestWeapon(this: (CCSBot *)HIDWORD(a3), mustEquip: false);
  }
  CCSBot::ReloadCheck(this: (CCSBot *)HIDWORD(a3));
  CCSBot::SilencerCheck(this: (CCSBot *)HIDWORD(a3));
  CCSBot::RespondToRadioCommands(this: (CCSBot *)HIDWORD(a3));
  if ( (float)(gpGlobals->curtime - *(float *)(HIDWORD(a3) + 7880)) < 0.33000001
    && CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)(HIDWORD(a3) + 7876), val: nullptr) )
  {
    v16 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)(HIDWORD(a3) + 7876));
    Centroid = GetCentroid(result: &leaderOrigin, player: v16);
    CCSBot::StrafeAwayFromPosition(
      this: (CCSBot *)HIDWORD(a3),
      a2: COERCE_FLOAT(&savedregs),
      a3: SHIDWORD(a3),
      pos: Centroid);
  }
  else
  {
    *(_DWORD *)(HIDWORD(a3) + 7876) = -1;
  }
  if ( !CCSBot::IsAtHidingSpot(this: (CCSBot *)HIDWORD(a3))
    && !CCSBot::IsAttacking(this: (CCSBot *)HIDWORD(a3))
    && CCSBot::IsUsingSniperRifle(this: (CCSBot *)HIDWORD(a3))
    && CBot<CCSPlayer>::IsUsingScope(this: (CBot<CCSPlayer> *)HIDWORD(a3)) )
  {
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(a3) + 2112))(a1: HIDWORD(a3));
  }
  if ( *(float *)(HIDWORD(a3) + 4796) <= gpGlobals->curtime )
  {
    CCSBot::UpdatePeripheralVision(this: (CCSBot *)HIDWORD(a3));
    if ( *(_BYTE *)(HIDWORD(a3) + 16484) != 0 && !CCSBot::HasSeenSniperRecently(this: (CCSBot *)HIDWORD(a3)) )
    {
      BotChatterInterface::SpottedSniper(this: (BotChatterInterface *)(HIDWORD(a3) + 16800));
      CountdownTimer::Start(this: (CountdownTimer *)(HIDWORD(a3) + 16488), duration: 20.0);
    }
    if ( CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)(HIDWORD(a3) + 16412), val: nullptr) )
    {
      Bomber = CCSBot::GetBomber(this: (CCSBot *)HIDWORD(a3));
      BotChatterInterface::SpottedBomber(this: (BotChatterInterface *)(HIDWORD(a3) + 16800), bomber: Bomber);
    }
    if ( CCSBot::CanSeeLooseBomb(this: (CCSBot *)HIDWORD(a3), a2: (int)&savedregs) )
    {
      LooseBomb = CCSBotManager::GetLooseBomb(this: (CCSBotManager *)TheBots);
      BotChatterInterface::SpottedLooseBomb(this: (BotChatterInterface *)(HIDWORD(a3) + 16800), bomb: LooseBomb);
    }
  }
  if ( *(float *)(HIDWORD(a3) + 16448) > 0.0 )
  {
    *(float *)&costFunc.m_route = IntervalTimer::Now(this: (CEffectsServer *)(HIDWORD(a3) + 16444))
                                - *(float *)(HIDWORD(a3) + 16448);
    if ( *(float *)&costFunc.m_route < 1.0 && !CCSBot::IsEscapingFromFlames(this: (CCSBot *)HIDWORD(a3)) )
    {
      CCSBot::EscapeFromFlames(this: (CCSBot *)HIDWORD(a3));
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return;
    }
  }
  if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1 )
  {
    v21 = *(_BYTE *)(HIDWORD(a3) + 4956) == 0;
    v22 = 8.0 - (float)(*(float *)(*(_DWORD *)(HIDWORD(a3) + 7072) + 4) * 2.0);
    *(float *)&costFunc.m_route = v22;
    if ( !v21 )
      *(float *)&costFunc.m_route = v22 * 0.66000003;
    if ( !CCSBot::IsEscapingFromBomb(this: (CCSBot *)HIDWORD(a3))
      && TheBots[1].m_debugMessage[0].m_string[460] != 0
      && CSGameState::IsPlantedBombLocationKnown(this: (CSGameState *)(HIDWORD(a3) + 14420)) )
    {
      BombTimeLeft = CCSBotManager::GetBombTimeLeft(this: (CCSBotManager *)TheBots);
      if ( *(float *)&costFunc.m_route > BombTimeLeft
        && !CCSBot::IsDefusingBomb(this: (CCSBot *)HIDWORD(a3))
        && !CCSBot::IsAttacking(this: (CCSBot *)HIDWORD(a3)) )
      {
        CCSBot::EscapeFromBomb(this: (CCSBot *)HIDWORD(a3));
      }
    }
  }
  else if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)2 )
  {
    if ( CBaseEntity::GetTeamNumber(this: (CBaseEntity *)HIDWORD(a3)) == 3 )
    {
      CCSBot::UpdateHostageEscortCount(this: (CCSBot *)HIDWORD(a3));
    }
    else
    {
      v20 = CSGameState::ValidateHostagePositions(this: (CSGameState *)(HIDWORD(a3) + 14420));
      if ( (v20 & 4) != 0 )
      {
        BotChatterInterface::HostagesTaken(this: (BotChatterInterface *)(HIDWORD(a3) + 16800));
        CCSBot::Idle(this: (CCSBot *)HIDWORD(a3));
      }
      else if ( (v20 & 2) != 0 )
      {
        *(_BYTE *)(HIDWORD(a3) + 14777) = 1;
        CCSBot::Idle(this: (CCSBot *)HIDWORD(a3));
      }
    }
  }
  if ( cv_bot_auto_follow.m_pParent != nullptr
    && cv_bot_auto_follow.m_pParent->m_Value.m_nValue != 0
    && (float)(gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]) > 5.0
    && *(float *)(*(_DWORD *)(HIDWORD(a3) + 7072) + 12) > 0.40000001
    && CCSBot::CanAutoFollow(this: (CCSBot *)HIDWORD(a3))
    && !CCSBot::IsBusy(this: (CCSBot *)HIDWORD(a3)) )
  {
    if ( *(_BYTE *)(HIDWORD(a3) + 7356) != 0 )
      goto LABEL_146;
    if ( !CCSPlayer::IsBlind(this: (CCSPlayer *)HIDWORD(a3))
      && !CSGameState::IsAtPlantedBombsite(this: (CSGameState *)(HIDWORD(a3) + 14420)) )
    {
      v24 = *(_DWORD *)(HIDWORD(a3) + 7072);
      costFunc.m_route = *(RouteType *)(v24 + 12);
      v25 = _RandomFloat(this: (IUniformRandomStream *)v24, a2: 0.0, a3: 1.0);
      if ( *(float *)&costFunc.m_route <= v25 )
      {
        *(float *)(HIDWORD(a3) + 7368) = (float)((float)(1.0 - *(float *)(*(_DWORD *)(HIDWORD(a3) + 7072) + 12)) * 30.0)
                                       + (float)(gpGlobals->curtime + 15.0);
      }
      else
      {
        ClosestVisibleHumanFriend = CCSBot::GetClosestVisibleHumanFriend(this: (CCSBot *)HIDWORD(a3));
        LODWORD(a3) = ClosestVisibleHumanFriend;
        if ( ClosestVisibleHumanFriend != nullptr
          && CCSPlayer::IsAutoFollowAllowed(this: ClosestVisibleHumanFriend)
          && (float)GetBotFollowCount(leader: (CCSPlayer *)a3) < 2.0 )
        {
          GetCentroid(result: &leaderOrigin, player: (CBaseEntity *)a3);
          if ( (float)((float)((float)((float)(leaderOrigin.x - myOrigin.x) * (float)(leaderOrigin.x - myOrigin.x))
                             + (float)((float)(leaderOrigin.y - myOrigin.y) * (float)(leaderOrigin.y - myOrigin.y)))
                     + (float)((float)(leaderOrigin.z - myOrigin.z) * (float)(leaderOrigin.z - myOrigin.z))) < 90000.0 )
          {
            NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: &leaderOrigin, beneathLimit: 120.0);
            if ( NavArea != nullptr )
            {
              cosTolerance = NavArea;
              v28 = *(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(a3) + 1320);
              costFunc.m_bot = (CCSBot *)HIDWORD(a3);
              costFunc.m_route = FASTEST_ROUTE;
              v29 = (CNavArea *)v28(a1: HIDWORD(a3));
              v30 = NavAreaTravelDistance<PathCost>(
                      startArea: v29,
                      endArea: cosTolerance,
                      &costFunc,
                      maxPathLength: 0.0);
              *(float *)&costFunc.m_route = v30;
              if ( v30 >= 0.0 && *(float *)&costFunc.m_route < 300.0 )
              {
                CCSBot::Follow(this: (CCSBot *)HIDWORD(a3), player: (CCSPlayer *)a3);
                v31 = (const char *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a3 + 160))(a1: a3);
                CBot<CCSPlayer>::PrintIfWatched(
                  this: (CBot<CCSPlayer> *)HIDWORD(a3),
                  format: "Auto-Following %s\n",
                  v31);
                BotChatterInterface::Say(
                  this: (BotChatterInterface *)(HIDWORD(a3) + 16800),
                  phraseName: "FollowingSir",
                  lifetime: 10.0,
                  delay: 0.0);
              }
            }
          }
        }
      }
    }
  }
  if ( *(_BYTE *)(HIDWORD(a3) + 7356) != 0 )
  {
LABEL_146:
    v32 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)(HIDWORD(a3) + 7360));
    if ( v32 == nullptr || !v32->IsAlive(this: v32) )
      CCSBot::StopFollowing(this: (CCSBot *)HIDWORD(a3));
    v33 = *(float *)(*(_DWORD *)(HIDWORD(a3) + 7072) + 12);
    if ( v33 < 0.85000002
      && (float)(gpGlobals->curtime - *(float *)(HIDWORD(a3) + 7364)) > (float)((float)(v33 * 40.0) + 15.0) )
    {
      CCSBot::StopFollowing(this: (CCSBot *)HIDWORD(a3));
      CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)HIDWORD(a3), format: "Stopping following - bored\n");
    }
  }
  if ( *(_BYTE *)(HIDWORD(a3) + 7841) != 0 )
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)(HIDWORD(a3) + 7784) + 4))(a1: HIDWORD(a3) + 7784, a2: HIDWORD(a3));
    if ( *(_BYTE *)(HIDWORD(a3) + 7796) != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)(HIDWORD(a3) + 7784) + 8))(
        a1: HIDWORD(a3) + 7784,
        a2: HIDWORD(a3));
      *(_BYTE *)(HIDWORD(a3) + 7841) = 0;
    }
  }
  else
  {
    v34 = HIDWORD(a3) + 7432;
    if ( *(_BYTE *)(HIDWORD(a3) + 7840) == 0 )
      v34 = *(_DWORD *)(HIDWORD(a3) + 7832);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v34 + 4))(a1: v34, a2: HIDWORD(a3));
  }
  if ( !CCSBot::IsAttacking(this: (CCSBot *)HIDWORD(a3)) && CCSBot::IsWaiting(this: (CCSBot *)HIDWORD(a3)) )
  {
    CCSBot::ResetStuckMonitor(this: (CCSBot *)HIDWORD(a3));
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(a3) + 2092))(a1: HIDWORD(a3));
  }
  v35 = CBaseCombatCharacter::GetActiveWeapon(this: (CBaseCombatCharacter *)HIDWORD(a3));
  if ( v35 != nullptr && v35->m_bInReload.m_Value && *(_BYTE *)(HIDWORD(a3) + 15852) == 0 )
  {
    CCSBot::ResetStuckMonitor(this: (CCSBot *)HIDWORD(a3));
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(a3) + 2092))(a1: HIDWORD(a3));
  }
  if ( !CCSBot::IsAttacking(this: (CCSBot *)HIDWORD(a3))
    && CountdownTimer::IsElapsed(this: (CountdownTimer *)(HIDWORD(a3) + 14796)) )
  {
    v36 = *(_DWORD *)(HIDWORD(a3) + 7844);
    if ( (v36 == 14 || v36 == 15) && CCSBot::GetRangeToFarthestEscortedHostage(this: (CCSBot *)HIDWORD(a3)) > 500.0 )
    {
      if ( *(_BYTE *)(HIDWORD(a3) + 14793) != 0 )
      {
        if ( CountdownTimer::IsElapsed(this: (CountdownTimer *)(HIDWORD(a3) + 14808)) )
        {
          *(_BYTE *)(HIDWORD(a3) + 14793) = 0;
          CountdownTimer::Start(this: (CountdownTimer *)(HIDWORD(a3) + 14796), duration: 3.0);
        }
        else
        {
          CCSBot::ResetStuckMonitor(this: (CCSBot *)HIDWORD(a3));
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(a3) + 2092))(a1: HIDWORD(a3));
        }
      }
      else
      {
        *(_BYTE *)(HIDWORD(a3) + 14793) = 1;
        CountdownTimer::Start(this: (CountdownTimer *)(HIDWORD(a3) + 14808), duration: 10.0);
      }
    }
  }
  *(_BYTE *)(HIDWORD(a3) + 7332) = CCSBot::IsSafe(this: (CCSBot *)HIDWORD(a3));
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102C19A0
// Name: __CreateCServerGameTagsIServerGameTags_interface_26
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_26()
{
  return &_g_CServerGameTags_singleton_26;
}

//------------------------------------------------------------------------------
// Address: 0x102C2450
// Name: bool ForEachPlayer<class DrawTravelTime>(class DrawTravelTime __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<DrawTravelTime>(DrawTravelTime *func)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CCSPlayer *v3; // esi
  edict_t *m_pPev; // eax

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = (CCSPlayer *)v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v3->IsPlayer(this: v3)
        && v3->m_iConnected != PlayerDisconnected
        && DrawTravelTime::operator()(this: func, player: v3) == 0 )
      {
        break;
      }
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102C24D0
// Name: float NavAreaTravelDistance<class ShortestPathCost>(class Vector const __near &,class Vector const __near &,class ShortestPathCost __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall NavAreaTravelDistance<ShortestPathCost>@<st0>(
        CNavArea *a1@<ebp>,
        const Vector *startPos,
        const Vector *goalPos,
        ShortestPathCost *costFunc)
{
  CNavArea *NearestNavArea; // eax
  CNavArea *m_parent; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  CNavArea *v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  CNavArea *v14[3]; // [esp+38h] [ebp-10h] BYREF
  CNavArea *retaddr; // [esp+48h] [ebp+0h]

  v14[1] = a1;
  v14[2] = retaddr;
  NearestNavArea = CNavMesh::GetNearestNavArea(
                     this: TheNavMesh,
                     pos: startPos,
                     anyZ: false,
                     maxDist: 10000.0,
                     checkLOS: false,
                     checkGround: true);
  if ( NearestNavArea == nullptr )
    return -1.0;
  v14[0] = nullptr;
  if ( NavAreaBuildPath<ShortestPathCost>(
         startArea: NearestNavArea,
         goalArea: nullptr,
         goalPos,
         costFunc,
         closestArea: v14,
         maxPathLength: 0.0,
         teamID: -1,
         ignoreNavBlockers: false) == 0 )
    return -1.0;
  m_parent = v14[0]->m_parent;
  x = goalPos->x;
  y = goalPos->y;
  z = goalPos->z;
  if ( m_parent == nullptr )
    return fsqrt(
             (float)((float)((float)(y - startPos->y) * (float)(y - startPos->y))
                   + (float)((float)(z - startPos->z) * (float)(z - startPos->z)))
           + (float)((float)(x - startPos->x) * (float)(x - startPos->x)));
  v10 = m_parent->m_parent;
  v11 = fsqrt(
          (float)((float)((float)(y - m_parent->m_center.y) * (float)(y - m_parent->m_center.y))
                + (float)((float)(z - m_parent->m_center.z) * (float)(z - m_parent->m_center.z)))
        + (float)((float)(x - m_parent->m_center.x) * (float)(x - m_parent->m_center.x)));
  v14[0] = (CNavArea *)LODWORD(v11);
  if ( v10 != nullptr )
  {
    do
    {
      v12 = m_parent->m_center.x - v10->m_center.x;
      v13 = (float)((float)((float)(m_parent->m_center.y - v10->m_center.y)
                          * (float)(m_parent->m_center.y - v10->m_center.y))
                  + (float)((float)(m_parent->m_center.z - v10->m_center.z)
                          * (float)(m_parent->m_center.z - v10->m_center.z)))
          + (float)(v12 * v12);
      m_parent = v10;
      v10 = v10->m_parent;
      v11 = v11 + fsqrt(v13);
    }
    while ( v10 != nullptr );
    v14[0] = (CNavArea *)LODWORD(v11);
  }
  return fsqrt(
           (float)((float)((float)(startPos->y - m_parent->m_center.y) * (float)(startPos->y - m_parent->m_center.y))
                 + (float)((float)(startPos->z - m_parent->m_center.z) * (float)(startPos->z - m_parent->m_center.z)))
         + (float)((float)(startPos->x - m_parent->m_center.x) * (float)(startPos->x - m_parent->m_center.x)))
       + *(float *)v14;
}

//------------------------------------------------------------------------------
// Address: 0x102C4150
// Name: __CreateCServerGameTagsIServerGameTags_interface_27
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_27()
{
  return &_g_CServerGameTags_singleton_27;
}
