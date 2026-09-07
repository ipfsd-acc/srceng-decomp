// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_blended_movement.cpp
// Functions: 31
// ============================================================

#include "game\server\ai_blended_movement.h"

//------------------------------------------------------------------------------
// Address: 0x10049650
// Name: public: struct AIMoveTrace_t __near & AIMoveTrace_t::operator=(struct AIMoveTrace_t const __near &)
// Source: json
//------------------------------------------------------------------------------
AIMoveTrace_t *__thiscall AIMoveTrace_t::operator=(AIMoveTrace_t *this, const AIMoveTrace_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100496B0
// Name: protected: class QAngle const __near & CAI_Component::GetAbsAngles(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__usercall CAI_Component::GetAbsAngles@<eax>(CAI_Component *this@<ecx>, int a2@<ebp>)
{
  CAI_BaseNPC *m_pOuter; // esi

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2);
  return &m_pOuter->m_angAbsRotation;
}

//------------------------------------------------------------------------------
// Address: 0x100496D0
// Name: public: virtual void CAI_BlendedMotor::MoveStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::MoveStop(CAI_BlendedMotor *this)
{
  int m_iPrimaryLayer; // eax
  int m_iSecondaryLayer; // eax

  CAI_Motor::MoveStop(this);
  m_iPrimaryLayer = this->m_iPrimaryLayer;
  if ( m_iPrimaryLayer != -1 )
  {
    CBaseAnimatingOverlay::RemoveLayer(this: this->m_pOuter, iLayer: m_iPrimaryLayer, flKillRate: 0.2, flKillDelay: 0.1);
    this->m_iPrimaryLayer = -1;
  }
  m_iSecondaryLayer = this->m_iSecondaryLayer;
  if ( m_iSecondaryLayer != -1 )
  {
    CBaseAnimatingOverlay::RemoveLayer(
      this: this->m_pOuter,
      iLayer: m_iSecondaryLayer,
      flKillRate: 0.2,
      flKillDelay: 0.1);
    this->m_iSecondaryLayer = -1;
  }
  this->m_nPrimarySequence = -1;
  this->m_nSecondarySequence = -1;
  this->m_nPrevMovementSequence = -1;
  this->m_nInteriorSequence = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10049770
// Name: private: int CAI_BlendedMotor::GetInteriorSequence(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BlendedMotor::GetInteriorSequence(CAI_BlendedMotor *this, int fromSequence)
{
  CAI_Navigator *Navigator; // eax
  int MovementSequence; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  KeyValues *SequenceKeyValues; // eax
  KeyValues *v8; // edi
  KeyValues *Key; // eax
  const char *String; // ebx
  Activity ActivityID; // eax
  CAI_BaseNPC *v12; // edi
  Activity v13; // eax
  int v14; // eax
  CAI_Navigator *v15; // eax
  Activity MovementActivity; // eax
  bool v17; // zf
  Activity v18; // eax
  CAI_BaseNPC *v19; // edi
  Activity v20; // eax
  int v21; // eax
  int m_nInteriorSequence; // esi
  int v23; // [esp-Ch] [ebp-14h]
  KeyValues *seqKeyValues; // [esp+4h] [ebp-4h]

  Navigator = CAI_Motor::GetNavigator(this);
  MovementSequence = CAI_Navigator::GetMovementSequence(this: Navigator);
  if ( this->m_nInteriorSequence != -1 && MovementSequence == this->m_nPrevMovementSequence )
    return this->m_nInteriorSequence;
  m_pOuter = this->m_pOuter;
  this->m_nPrevMovementSequence = MovementSequence;
  SequenceKeyValues = CBaseAnimating::GetSequenceKeyValues(this: m_pOuter, iSequence: MovementSequence);
  v8 = SequenceKeyValues;
  seqKeyValues = SequenceKeyValues;
  if ( SequenceKeyValues != nullptr )
  {
    Key = KeyValues::FindKey(this: SequenceKeyValues, keyName: "interior", bCreate: false);
    if ( Key != nullptr )
    {
      String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: locale);
      ActivityID = CBaseAnimating::LookupActivity(this: this->m_pOuter, label: String);
      if ( ActivityID == ACT_INVALID )
      {
        ActivityID = CAI_BaseNPC::GetActivityID(actName: String);
        if ( ActivityID == ACT_INVALID )
        {
LABEL_11:
          this->m_nInteriorSequence = CBaseAnimating::LookupSequence(this: this->m_pOuter, label: String);
          goto LABEL_12;
        }
        v23 = fromSequence;
      }
      else
      {
        v23 = fromSequence;
      }
      v12 = this->m_pOuter;
      v13 = CAI_BaseNPC::TranslateActivity(this: v12, idealActivity: ActivityID, pIdealWeaponActivity: nullptr);
      v14 = CBaseAnimating::SelectWeightedSequence(this: v12, activity: v13, curSequence: v23);
      v8 = seqKeyValues;
      this->m_nInteriorSequence = v14;
      if ( v14 == -1 )
        goto LABEL_11;
    }
  }
LABEL_12:
  if ( this->m_nInteriorSequence == -1 )
  {
    v15 = CAI_Motor::GetNavigator(this);
    MovementActivity = CAI_Navigator::GetMovementActivity(this: v15);
    if ( MovementActivity == ACT_WALK_AIM || (v17 = MovementActivity == ACT_RUN_AIM, v18 = ACT_IDLE, v17) )
      v18 = ACT_IDLE_ANGRY;
    v19 = this->m_pOuter;
    v20 = CAI_BaseNPC::TranslateActivity(this: v19, idealActivity: v18, pIdealWeaponActivity: nullptr);
    v21 = CBaseAnimating::SelectWeightedSequence(this: v19, activity: v20, curSequence: fromSequence);
    v8 = seqKeyValues;
    this->m_nInteriorSequence = v21;
  }
  m_nInteriorSequence = this->m_nInteriorSequence;
  if ( v8 != nullptr )
    KeyValues::deleteThis(this: v8);
  return m_nInteriorSequence;
}

//------------------------------------------------------------------------------
// Address: 0x100498A0
// Name: public: virtual float CAI_BlendedMotor::OverrideMaxYawSpeed(enum Activity)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BlendedMotor::OverrideMaxYawSpeed(CAI_BlendedMotor *this, Activity activity)
{
  if ( this->m_bYawLocked )
    return 0.0;
  if ( (activity < ACT_TURN_LEFT || activity > ACT_TURN_RIGHT) && this->m_pOuter->IsMoving(this: this->m_pOuter) )
    return 15.0;
  return 45.0;
}

//------------------------------------------------------------------------------
// Address: 0x100498F0
// Name: public: virtual void CAI_BlendedMotor::UpdateYaw(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::UpdateYaw(CAI_BlendedMotor *this, int speed)
{
  if ( !this->m_bYawLocked )
  {
    CAI_BaseNPC::UpdateTurnGesture(this: this->m_pOuter);
    CAI_Motor::UpdateYaw(this, yawSpeed: speed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049920
// Name: public: virtual void CAI_BlendedMotor::RecalculateYawSpeed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::RecalculateYawSpeed(CAI_BlendedMotor *this)
{
  if ( this->m_bYawLocked )
  {
    this->m_YawSpeed = 0.0;
  }
  else if ( (this->m_pOuter->m_afMemory & 0x2000) == 0 )
  {
    this->m_YawSpeed = this->CalcYawSpeed(this: &this->CAI_ProxyMovementSink);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049960
// Name: public: virtual void CAI_BlendedMotor::MoveClimbStart(class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::MoveClimbStart(
        CAI_BlendedMotor *this,
        const Vector *climbDest,
        const Vector *climbDir,
        float climbDist,
        float yaw)
{
  int m_iPrimaryLayer; // eax
  int m_iSecondaryLayer; // eax

  m_iPrimaryLayer = this->m_iPrimaryLayer;
  if ( m_iPrimaryLayer != -1 )
    CBaseAnimatingOverlay::SetLayerWeight(this: this->m_pOuter, iLayer: m_iPrimaryLayer, flWeight: 0.0);
  m_iSecondaryLayer = this->m_iSecondaryLayer;
  if ( m_iSecondaryLayer != -1 )
    CBaseAnimatingOverlay::SetLayerWeight(this: this->m_pOuter, iLayer: m_iSecondaryLayer, flWeight: 0.0);
  CAI_Motor::MoveClimbStart(this, climbDest, climbDir, climbDist, yaw);
}

//------------------------------------------------------------------------------
// Address: 0x100499D0
// Name: public: virtual void CAI_BlendedMotor::MoveJumpStart(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::MoveJumpStart(CAI_BlendedMotor *this, const Vector *velocity)
{
  int m_iPrimaryLayer; // eax
  int m_iSecondaryLayer; // eax

  m_iPrimaryLayer = this->m_iPrimaryLayer;
  if ( m_iPrimaryLayer != -1 )
    CBaseAnimatingOverlay::SetLayerWeight(this: this->m_pOuter, iLayer: m_iPrimaryLayer, flWeight: 0.0);
  m_iSecondaryLayer = this->m_iSecondaryLayer;
  if ( m_iSecondaryLayer != -1 )
    CBaseAnimatingOverlay::SetLayerWeight(this: this->m_pOuter, iLayer: m_iSecondaryLayer, flWeight: 0.0);
  CAI_Motor::MoveJumpStart(this, velocity);
}

//------------------------------------------------------------------------------
// Address: 0x10049A20
// Name: public: virtual void CAI_BlendedMotor::MaintainTurnActivity(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BlendedMotor::MaintainTurnActivity(CAI_BlendedMotor *this@<ecx>, int a2@<edi>)
{
  float curtime; // xmm0_4
  CAI_BaseNPC *v4; // edi
  float destAngle; // xmm0_4
  const QAngle *AbsAngles; // eax
  double v7; // st7
  CAI_BaseNPC *m_pOuter; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // edi
  float v12; // xmm0_4
  int flPlaybackRate; // [esp+Ch] [ebp-Ch]
  float rate; // [esp+14h] [ebp-4h]
  float ratea; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  curtime = gpGlobals->curtime;
  flPlaybackRate = a2;
  if ( this->m_flNextTurnGesture > curtime
    || this->m_flNextTurnAct > curtime
    || ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *, int))this->m_pOuter->IsMoving)(a1: this->m_pOuter, a2) != 0 )
  {
    m_pOuter = this->m_pOuter;
    this->m_doLeft = 0.0;
    this->m_doRight = 0.0;
    this->m_doTurn = 0.0;
    if ( ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *, int))m_pOuter->IsMoving)(a1: m_pOuter, a2: flPlaybackRate) != 0 )
      this->m_flNextTurnAct = gpGlobals->curtime + 0.3;
  }
  else
  {
    v4 = this->m_pOuter;
    if ( (v4->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    destAngle = this->m_prevYaw;
    if ( destAngle != v4->m_angAbsRotation.y )
    {
      AbsAngles = CAI_Component::GetAbsAngles(this, a2: (int)&savedregs);
      v7 = AngleDiff(destAngle, srcAngle: AbsAngles->y);
      rate = v7;
      if ( v7 >= 0.0 )
        this->m_doRight = this->m_doRight + rate;
      else
        this->m_doLeft = this->m_doLeft - rate;
      this->m_prevYaw = CAI_Component::GetAbsAngles(this, a2: (int)&savedregs)->y;
    }
    this->m_doTurn = (float)(this->m_doRight + this->m_doLeft) + this->m_doTurn;
    this->m_doTurn = ((double (__thiscall *)(IUniformRandomStream *, int, int, int))random->RandomFloat)(
                       a1: random,
                       a2: 1053609165,
                       a3: 1058642330,
                       a4: flPlaybackRate)
                   + this->m_doTurn;
  }
  if ( this->m_doTurn > 15.0 )
  {
    if ( this->m_doLeft <= this->m_doRight )
      v9 = CAI_Motor::SelectWeightedSequence(this, activity: ACT_GESTURE_TURN_RIGHT);
    else
      v9 = CAI_Motor::SelectWeightedSequence(this, activity: ACT_GESTURE_TURN_LEFT);
    this->m_doLeft = 0.0;
    this->m_doRight = 0.0;
    if ( v9 != -1 )
    {
      v10 = CBaseAnimatingOverlay::AddGestureSequence(this: this->m_pOuter, sequence: v9, autokill: true);
      v11 = v10;
      if ( v10 == -1 )
      {
        this->m_flNextTurnAct = gpGlobals->curtime + 0.3;
      }
      else
      {
        CBaseAnimatingOverlay::SetLayerPriority(this: this->m_pOuter, iLayer: v10, iPriority: 100);
        ratea = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1061997773,
                  a3: 1067030938);
        v12 = ratea;
        if ( this->m_doTurn > 90.0 )
          v12 = ratea * 1.5;
        CBaseAnimatingOverlay::SetLayerPlaybackRate(this: this->m_pOuter, iLayer: v11, flPlaybackRate: v12);
        this->m_flNextTurnAct = CBaseAnimatingOverlay::GetLayerDuration(this: this->m_pOuter, iLayer: v11)
                              + gpGlobals->curtime;
      }
    }
    this->m_doLeft = 0.0;
    this->m_doRight = 0.0;
    this->m_doTurn = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049CF0
// Name: public: void CAI_BlendedMotor::ResetGoalSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::ResetGoalSequence(CAI_BlendedMotor *this)
{
  CAI_Navigator *Navigator; // eax
  Activity ArrivalActivity; // eax
  Activity v4; // eax
  CAI_Navigator *v5; // eax
  int ArrivalSequence; // eax
  int m_nPrimarySequence; // [esp-4h] [ebp-8h]
  int v8; // [esp-4h] [ebp-8h]

  Navigator = CAI_Motor::GetNavigator(this);
  ArrivalActivity = CAI_Navigator::GetArrivalActivity(this: Navigator);
  this->m_nSavedGoalActivity = ArrivalActivity;
  if ( ArrivalActivity == ACT_INVALID )
    this->m_nSavedGoalActivity = CAI_BaseNPC::GetStoppedActivity(this: this->m_pOuter);
  v4 = this->m_pOuter->NPC_TranslateActivity(this: this->m_pOuter, a2: this->m_nSavedGoalActivity);
  m_nPrimarySequence = this->m_nPrimarySequence;
  this->m_nSavedTranslatedGoalActivity = v4;
  v5 = CAI_Motor::GetNavigator(this);
  ArrivalSequence = CAI_Navigator::GetArrivalSequence(this: v5, curSequence: m_nPrimarySequence);
  v8 = this->m_nPrimarySequence;
  this->m_nGoalSequence = ArrivalSequence;
  this->m_nGoalSequence = CAI_BlendedMotor::GetInteriorSequence(this, fromSequence: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10049D70
// Name: public: void CAI_BlendedMotor::MoveContinue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::MoveContinue(CAI_BlendedMotor *this)
{
  int InteriorSequence; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  int v4; // eax
  CAI_BaseNPC *v5; // ecx

  InteriorSequence = CAI_BlendedMotor::GetInteriorSequence(this, fromSequence: -1);
  this->m_nPrimarySequence = InteriorSequence;
  this->m_nGoalSequence = InteriorSequence;
  if ( InteriorSequence != -1 )
  {
    m_pOuter = this->m_pOuter;
    this->m_flStartCycle = 0.0;
    v4 = CBaseAnimatingOverlay::AddLayeredSequence(this: m_pOuter, sequence: InteriorSequence, iPriority: 0);
    v5 = this->m_pOuter;
    this->m_iPrimaryLayer = v4;
    CBaseAnimatingOverlay::SetLayerWeight(this: v5, iLayer: v4, flWeight: 0.0);
    CBaseAnimatingOverlay::SetLayerPlaybackRate(
      this: this->m_pOuter,
      iLayer: this->m_iPrimaryLayer,
      flPlaybackRate: 0.0);
    CBaseAnimatingOverlay::SetLayerNoRestore(this: this->m_pOuter, iLayer: this->m_iPrimaryLayer, bNoRestore: true);
    CBaseAnimatingOverlay::SetLayerCycle(
      this: this->m_pOuter,
      iLayer: this->m_iPrimaryLayer,
      flCycle: this->m_flStartCycle,
      flPrevCycle: this->m_flStartCycle);
    CBaseAnimatingOverlay::SetLayerNoEvents(this: this->m_pOuter, iLayer: this->m_iPrimaryLayer, bNoEvents: true);
    this->m_bDeceleratingToGoal = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049E30
// Name: private: float CAI_BlendedMotor::GetMoveScriptDist(float __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BlendedMotor::GetMoveScriptDist(CAI_BlendedMotor *this, float *flNewSpeed)
{
  float v2; // xmm3_4
  float m_flMoveInterval; // xmm1_4
  int v4; // esi
  int i; // eax
  CAI_BlendedMotor::AI_Movementscript_t *m_pMemory; // edx
  CAI_BlendedMotor::AI_Movementscript_t *v7; // edx
  float v9; // xmm0_4
  float flTotalDist; // [esp+0h] [ebp-4h]

  v2 = 0.0;
  m_flMoveInterval = this->m_flMoveInterval;
  *flNewSpeed = 0.0;
  v4 = 0;
  flTotalDist = 0.0;
  if ( this->m_scriptMove.m_Size - 1 > 0 )
  {
    for ( i = 0; ; ++i )
    {
      m_pMemory = this->m_scriptMove.m_Memory.m_pMemory;
      if ( m_pMemory[i].flTime > m_flMoveInterval )
        break;
      ++v4;
      *flNewSpeed = m_pMemory[i + 1].flMaxVelocity;
      v7 = this->m_scriptMove.m_Memory.m_pMemory;
      v2 = v2 + v7[i].flDist;
      m_flMoveInterval = m_flMoveInterval - v7[i].flTime;
      if ( v4 >= this->m_scriptMove.m_Size - 1 )
        return v2;
    }
    v9 = (float)((float)(1.0 - (float)(m_flMoveInterval / m_pMemory[v4].flTime)) * m_pMemory[v4].flMaxVelocity)
       + (float)(m_pMemory[v4 + 1].flMaxVelocity * (float)(m_flMoveInterval / m_pMemory[v4].flTime));
    *flNewSpeed = v9;
    return (float)((float)((float)((float)(this->m_scriptMove.m_Memory.m_pMemory[v4].flMaxVelocity + v9) * 0.5)
                         * m_flMoveInterval)
                 + v2);
  }
  return flTotalDist;
}

//------------------------------------------------------------------------------
// Address: 0x10049F10
// Name: public: float CAI_BlendedMotor::GetMoveScriptTotalTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BlendedMotor::GetMoveScriptTotalTime(CAI_BlendedMotor *this)
{
  CAI_Navigator *Navigator; // eax
  int v3; // eax
  float v5; // xmm0_4
  int v6; // edx
  CAI_BlendedMotor::AI_Movementscript_t *m_pMemory; // ecx
  float v8; // xmm0_4
  CAI_BlendedMotor::AI_Movementscript_t *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm0_4
  int v12; // ecx
  float flDist; // [esp+4h] [ebp-4h]

  Navigator = CAI_Motor::GetNavigator(this);
  flDist = CAI_Navigator::GetArrivalDistance(this: Navigator);
  v3 = this->m_scriptMove.m_Size - 1;
  if ( v3 < 0 )
    return -1.0;
  v5 = flDist;
  if ( v3 < 4 )
  {
LABEL_10:
    if ( v3 > 0 )
    {
      v12 = v3;
      do
      {
        if ( v5 <= 1.0 )
          break;
        v5 = v5 - this->m_scriptMove.m_Memory.m_pMemory[v12].flDist;
        --v3;
        --v12;
      }
      while ( v3 > 0 );
    }
  }
  else
  {
    v6 = v3;
    while ( v5 > 1.0 )
    {
      m_pMemory = this->m_scriptMove.m_Memory.m_pMemory;
      v8 = v5 - m_pMemory[v6].flDist;
      v9 = &m_pMemory[v6];
      if ( v8 <= 1.0 )
        return this->m_scriptMove.m_Memory.m_pMemory[--v3].flElapsedTime;
      v10 = v8 - v9[-1].flDist;
      if ( v10 <= 1.0 )
      {
        v3 -= 2;
        return this->m_scriptMove.m_Memory.m_pMemory[v3].flElapsedTime;
      }
      v11 = v10 - v9[-2].flDist;
      if ( v11 <= 1.0 )
      {
        v3 -= 3;
        return this->m_scriptMove.m_Memory.m_pMemory[v3].flElapsedTime;
      }
      v5 = v11 - v9[-3].flDist;
      v3 -= 4;
      v6 -= 4;
      if ( v3 <= 3 )
        goto LABEL_10;
    }
  }
  return this->m_scriptMove.m_Memory.m_pMemory[v3].flElapsedTime;
}

//------------------------------------------------------------------------------
// Address: 0x10049FF0
// Name: private: float CAI_BlendedMotor::GetMoveScriptYaw(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BlendedMotor::GetMoveScriptYaw(CAI_BlendedMotor *this)
{
  CAI_BaseNPC *m_pOuter; // esi
  int v3; // ecx
  int v4; // eax
  float m_flMoveInterval; // xmm0_4
  CAI_BlendedMotor::AI_Movementscript_t *i; // edx
  float flTime; // xmm1_4
  CAI_BlendedMotor::AI_Movementscript_t *m_pMemory; // ecx
  int v10; // esi
  float a; // [esp+10h] [ebp-Ch]
  float deltaYaw; // [esp+14h] [ebp-8h]
  float flNewYaw; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
  v3 = this->m_scriptTurn.m_Size - 1;
  v4 = 0;
  flNewYaw = m_pOuter->m_angAbsRotation.y;
  m_flMoveInterval = this->m_flMoveInterval;
  if ( v3 > 0 )
  {
    for ( i = this->m_scriptTurn.m_Memory.m_pMemory; ; ++i )
    {
      flTime = i->flTime;
      if ( i->flTime > m_flMoveInterval )
        break;
      ++v4;
      m_flMoveInterval = m_flMoveInterval - flTime;
      if ( v4 >= v3 )
        return flNewYaw;
    }
    m_pMemory = this->m_scriptTurn.m_Memory.m_pMemory;
    v10 = v4;
    a = m_flMoveInterval / m_pMemory[v4].flTime;
    deltaYaw = AngleDiff(destAngle: m_pMemory[v4 + 1].flYaw, srcAngle: m_pMemory[v4].flYaw);
    return (float)((float)(unsigned __int16)(int)(float)((float)((float)(deltaYaw * a)
                                                               + this->m_scriptTurn.m_Memory.m_pMemory[v10].flYaw)
                                                       * 182.04445)
                 * 0.0054931641);
  }
  return flNewYaw;
}

//------------------------------------------------------------------------------
// Address: 0x1004A0E0
// Name: private: void CAI_BlendedMotor::SetMoveScriptAnim(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::SetMoveScriptAnim(CAI_BlendedMotor *this, float flNewSpeed)
{
  CAI_Navigator *Navigator; // edi
  double v4; // st7
  float v5; // xmm0_4
  float m_flCurrRate; // xmm1_4
  double v7; // xmm0_8
  Activity v8; // eax
  int ArrivalSequence; // eax
  int m_nSecondarySequence; // ecx
  int m_nGoalSequence; // eax
  int m_nPrimarySequence; // edx
  int TransitionSequence; // eax
  int v14; // eax
  int v15; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  double v17; // xmm0_8
  float v18; // xmm0_4
  float v19; // xmm0_4
  int m_iPrimaryLayer; // edx
  int m_iSecondaryLayer; // eax
  int flRate; // [esp+8h] [ebp-14h]
  float flWeight; // [esp+18h] [ebp-4h]
  float flWeighta; // [esp+18h] [ebp-4h]

  if ( this->m_pOuter->IsAlive(this: this->m_pOuter) )
  {
    Navigator = CAI_Motor::GetNavigator(this);
    CAI_Motor::SetPlaybackRate(this, flRate: this->m_flCurrRate);
    flWeight = 0.0;
    if ( CAI_Motor::GetIdealSpeed(this) > 0.0 )
    {
      flWeighta = CAI_Motor::GetIdealSpeed(this);
      v4 = 1.0 - flNewSpeed / (CAI_Motor::GetPlaybackRate(this) * flWeighta);
      flWeight = v4;
      if ( v4 < 0.0 )
      {
        v5 = 0.0;
        this->m_flCurrRate = flNewSpeed / CAI_Motor::GetIdealSpeed(this);
        m_flCurrRate = this->m_flCurrRate;
        if ( m_flCurrRate >= 0.0 )
        {
          v5 = 1.0;
          if ( m_flCurrRate <= 1.0 )
            v5 = this->m_flCurrRate;
        }
        this->m_flCurrRate = v5;
        CAI_Motor::SetPlaybackRate(this, flRate: v5);
        flWeight = 0.0;
      }
    }
    v7 = (float)(1.0 - this->m_flCurrRate) * 0.8 + this->m_flCurrRate;
    if ( v7 >= 1.0 )
      v7 = 1.0;
    this->m_flCurrRate = v7;
    if ( this->m_nSavedGoalActivity == ACT_INVALID )
      CAI_BlendedMotor::ResetGoalSequence(this);
    v8 = this->m_pOuter->NPC_TranslateActivity(this: this->m_pOuter, a2: this->m_nSavedGoalActivity);
    if ( v8 != this->m_nSavedTranslatedGoalActivity )
    {
      flRate = this->m_nPrimarySequence;
      this->m_nSavedTranslatedGoalActivity = v8;
      this->m_nInteriorSequence = -1;
      this->m_nGoalSequence = CAI_Navigator::GetArrivalSequence(this: Navigator, curSequence: flRate);
    }
    if ( this->m_bDeceleratingToGoal )
    {
      ArrivalSequence = CAI_Navigator::GetArrivalSequence(this: Navigator, curSequence: this->m_nPrimarySequence);
      this->m_nGoalSequence = ArrivalSequence;
      if ( ArrivalSequence == -1 )
        this->m_nGoalSequence = CAI_BlendedMotor::GetInteriorSequence(this, fromSequence: this->m_nPrimarySequence);
    }
    if ( this->m_flSecondaryWeight == 1.0
      || this->m_iSecondaryLayer != -1 && this->m_nPrimarySequence == this->m_nSecondarySequence )
    {
      CBaseAnimatingOverlay::RemoveLayer(
        this: this->m_pOuter,
        iLayer: this->m_iPrimaryLayer,
        flKillRate: 0.0,
        flKillDelay: 0.0);
      m_nSecondarySequence = this->m_nSecondarySequence;
      this->m_iPrimaryLayer = this->m_iSecondaryLayer;
      this->m_nPrimarySequence = m_nSecondarySequence;
      this->m_iSecondaryLayer = -1;
      this->m_nSecondarySequence = -1;
      this->m_flSecondaryWeight = 0.0;
    }
    if ( this->m_nSecondarySequence == -1 )
    {
      if ( !this->m_bDeceleratingToGoal
        && this->m_nGoalSequence != CAI_BlendedMotor::GetInteriorSequence(this, fromSequence: this->m_nPrimarySequence) )
      {
        this->m_nGoalSequence = CAI_BlendedMotor::GetInteriorSequence(this, fromSequence: this->m_nPrimarySequence);
      }
      m_nGoalSequence = this->m_nGoalSequence;
      if ( m_nGoalSequence != -1 )
      {
        m_nPrimarySequence = this->m_nPrimarySequence;
        if ( m_nPrimarySequence != m_nGoalSequence )
        {
          TransitionSequence = CBaseAnimating::FindTransitionSequence(
                                 this: this->m_pOuter,
                                 iCurrentSequence: m_nPrimarySequence,
                                 iGoalSequence: m_nGoalSequence,
                                 piDir: 0);
          this->m_nSecondarySequence = TransitionSequence;
          if ( TransitionSequence == -1 )
            this->m_nSecondarySequence = this->m_nGoalSequence;
        }
      }
    }
    v14 = this->m_nSecondarySequence;
    if ( v14 == -1 )
    {
      if ( this->m_iPrimaryLayer == -1 )
        CAI_BlendedMotor::MoveContinue(this);
      m_iSecondaryLayer = this->m_iSecondaryLayer;
      if ( m_iSecondaryLayer != -1 )
      {
        CBaseAnimatingOverlay::RemoveLayer(
          this: this->m_pOuter,
          iLayer: m_iSecondaryLayer,
          flKillRate: 0.0,
          flKillDelay: 0.0);
        this->m_iSecondaryLayer = -1;
        this->m_nSecondarySequence = -1;
        this->m_flSecondaryWeight = 0.0;
      }
      v19 = flWeight;
      m_iPrimaryLayer = this->m_iPrimaryLayer;
    }
    else
    {
      if ( this->m_iSecondaryLayer == -1 )
      {
        v15 = CBaseAnimatingOverlay::AddLayeredSequence(this: this->m_pOuter, sequence: v14, iPriority: 0);
        m_pOuter = this->m_pOuter;
        this->m_iSecondaryLayer = v15;
        CBaseAnimatingOverlay::SetLayerWeight(this: m_pOuter, iLayer: v15, flWeight: 0.0);
        if ( this->m_nSecondarySequence == this->m_nGoalSequence )
          CBaseAnimatingOverlay::SetLayerPlaybackRate(
            this: this->m_pOuter,
            iLayer: this->m_iSecondaryLayer,
            flPlaybackRate: 0.0);
        else
          CBaseAnimatingOverlay::SetLayerPlaybackRate(
            this: this->m_pOuter,
            iLayer: this->m_iSecondaryLayer,
            flPlaybackRate: 1.0);
        CBaseAnimatingOverlay::SetLayerNoRestore(
          this: this->m_pOuter,
          iLayer: this->m_iSecondaryLayer,
          bNoRestore: true);
        CBaseAnimatingOverlay::SetLayerNoEvents(this: this->m_pOuter, iLayer: this->m_iSecondaryLayer, bNoEvents: true);
        this->m_flSecondaryWeight = 0.0;
      }
      v17 = this->m_flSecondaryWeight + 0.3;
      if ( v17 >= 1.0 )
        v17 = 1.0;
      v18 = v17;
      this->m_flSecondaryWeight = v18;
      if ( v18 >= 1.0 )
      {
        CBaseAnimatingOverlay::SetLayerWeight(this: this->m_pOuter, iLayer: this->m_iPrimaryLayer, flWeight: 0.0);
        CBaseAnimatingOverlay::SetLayerWeight(this: this->m_pOuter, iLayer: this->m_iSecondaryLayer, flWeight);
        return;
      }
      CBaseAnimatingOverlay::SetLayerWeight(
        this: this->m_pOuter,
        iLayer: this->m_iPrimaryLayer,
        flWeight: (float)(flWeight - (float)(v18 * flWeight)) / (float)(1.0 - (float)(v18 * flWeight)));
      v19 = flWeight * this->m_flSecondaryWeight;
      m_iPrimaryLayer = this->m_iSecondaryLayer;
    }
    CBaseAnimatingOverlay::SetLayerWeight(this: this->m_pOuter, iLayer: m_iPrimaryLayer, flWeight: v19);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A530
// Name: public: virtual void CAI_BlendedMotor::ResetMoveCalculations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::ResetMoveCalculations(CAI_BlendedMotor *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->m_scriptMove.m_Size = 0;
  this->m_scriptTurn.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A550
// Name: public: virtual void CAI_BlendedMotor::MoveStart(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BlendedMotor::MoveStart(CAI_BlendedMotor *this@<ecx>, int a2@<ebp>)
{
  CAI_BaseNPC *m_pOuter; // ecx
  int m_Value; // eax
  int v5; // eax
  CAI_BaseNPC *v6; // ecx
  CAI_BaseNPC *v7; // edi
  CAI_BaseNPC *v8; // edi

  if ( this->m_nPrimarySequence == -1 )
  {
    m_pOuter = this->m_pOuter;
    m_Value = m_pOuter->m_nSequence.m_Value;
    this->m_nPrimarySequence = m_Value;
    this->m_flStartCycle = m_pOuter->m_flCycle.m_Value;
    this->m_flCurrRate = 0.40000001;
    this->m_nSecondarySequence = -1;
    v5 = CBaseAnimatingOverlay::AddLayeredSequence(this: m_pOuter, sequence: m_Value, iPriority: 0);
    v6 = this->m_pOuter;
    this->m_iPrimaryLayer = v5;
    CBaseAnimatingOverlay::SetLayerWeight(this: v6, iLayer: v5, flWeight: 0.0);
    CBaseAnimatingOverlay::SetLayerPlaybackRate(
      this: this->m_pOuter,
      iLayer: this->m_iPrimaryLayer,
      flPlaybackRate: 0.0);
    CBaseAnimatingOverlay::SetLayerNoRestore(this: this->m_pOuter, iLayer: this->m_iPrimaryLayer, bNoRestore: true);
    CBaseAnimatingOverlay::SetLayerCycle(
      this: this->m_pOuter,
      iLayer: this->m_iPrimaryLayer,
      flCycle: this->m_flStartCycle,
      flPrevCycle: this->m_flStartCycle);
    CBaseAnimatingOverlay::SetLayerNoEvents(this: this->m_pOuter, iLayer: this->m_iPrimaryLayer, bNoEvents: true);
    this->m_flSecondaryWeight = 0.0;
  }
  if ( this->m_nGoalSequence == -1 )
    CAI_BlendedMotor::ResetGoalSequence(this);
  v7 = this->m_pOuter;
  if ( (v7->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2);
  this->m_vecPrevOrigin2.x = v7->m_vecAbsOrigin.x;
  this->m_vecPrevOrigin2.y = v7->m_vecAbsOrigin.y;
  this->m_vecPrevOrigin2.z = v7->m_vecAbsOrigin.z;
  v8 = this->m_pOuter;
  if ( (v8->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2);
  this->m_vecPrevOrigin1.x = v8->m_vecAbsOrigin.x;
  this->m_vecPrevOrigin1.y = v8->m_vecAbsOrigin.y;
  this->m_vecPrevOrigin1.z = v8->m_vecAbsOrigin.z;
  this->m_bDeceleratingToGoal = false;
}

//------------------------------------------------------------------------------
// Address: 0x1004A6B0
// Name: public: virtual void CAI_BlendedMotor::MovePaused(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::MovePaused(CAI_BlendedMotor *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CAI_BlendedMotor::SetMoveScriptAnim(this, flNewSpeed: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1004A760
// Name: private: int CAI_BlendedMotor::BuildInsertNode(int,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BlendedMotor::BuildInsertNode(CAI_BlendedMotor *this, int i, float flTime)
{
  int v4; // edx
  int v5; // eax
  CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> > *p_m_scriptTurn; // ecx
  CAI_BlendedMotor::AI_Movementscript_t *j; // esi
  float v9; // xmm0_4
  float v11; // xmm1_4
  float *p_flTime; // eax
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  int v22; // esi
  float v23; // xmm2_4
  CAI_BlendedMotor::AI_Movementscript_t script; // [esp+4h] [ebp-38h] BYREF

  memset(dst: (unsigned __int8 *)&script, value: 0, count: sizeof(script));
  v4 = i;
  v5 = this->m_scriptTurn.m_Size - 1;
  if ( i >= v5 )
    return 0;
  p_m_scriptTurn = &this->m_scriptTurn;
  for ( j = &this->m_scriptTurn.m_Memory.m_pMemory[i]; ; ++j )
  {
    v9 = j->flTime;
    if ( flTime <= j->flTime )
      break;
    ++v4;
    flTime = flTime - v9;
    if ( v4 >= v5 )
      return 0;
  }
  v11 = p_m_scriptTurn->m_Memory.m_pMemory[v4].flTime;
  p_m_scriptTurn->m_Memory.m_pMemory[v4].flTime = flTime;
  p_flTime = &p_m_scriptTurn->m_Memory.m_pMemory[v4].flTime;
  v13 = flTime / v11;
  v14 = p_flTime[15];
  v15 = p_flTime[26];
  v16 = p_flTime[27];
  v17 = v11 - flTime;
  v18 = p_flTime[1];
  script.flTime = v17;
  v19 = (float)(v18 * (float)(1.0 - v13)) + (float)(v14 * v13);
  v20 = p_flTime[25];
  v21 = p_flTime[12];
  v22 = v4 + 1;
  script.flElapsedTime = v19;
  v23 = (float)(p_flTime[13] * (float)(1.0 - v13)) + (float)(v16 * v13);
  script.vecLocation.x = (float)((float)(1.0 - v13) * p_flTime[11]) + (float)(v20 * v13);
  script.vecLocation.y = (float)(v21 * (float)(1.0 - v13)) + (float)(v15 * v13);
  script.vecLocation.z = v23;
  CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int>>::InsertBefore(
    this: p_m_scriptTurn,
    elem: v4 + 1,
    src: &script);
  return v22;
}

//------------------------------------------------------------------------------
// Address: 0x1004A880
// Name: private: void CAI_BlendedMotor::InsertSlowdown(float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::InsertSlowdown(
        CAI_BlendedMotor *this,
        float distToObstruction,
        float idealAccel,
        char bAlwaysSlowdown)
{
  float v5; // xmm7_4
  int v6; // eax
  int v7; // esi
  CAI_BlendedMotor::AI_Movementscript_t *m_pMemory; // edx
  CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> > *p_m_scriptMove; // ebx
  float *i; // ecx
  float v11; // xmm0_4
  float *p_flTime; // eax
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float *p_flDist; // eax
  float v17; // xmm0_4
  CAI_BlendedMotor::AI_Movementscript_t script; // [esp+20h] [ebp-38h] BYREF

  memset(dst: (unsigned __int8 *)&script, value: 0, count: sizeof(script));
  v5 = distToObstruction;
  if ( distToObstruction > 0.0 )
  {
    v6 = this->m_scriptMove.m_Size - 1;
    v7 = 0;
    if ( v6 > 0 )
    {
      m_pMemory = this->m_scriptMove.m_Memory.m_pMemory;
      p_m_scriptMove = &this->m_scriptMove;
      for ( i = &m_pMemory->flDist; ; i += 14 )
      {
        v11 = *i;
        if ( *i > 0.0 && (float)(v5 - v11) < 0.0 )
          break;
        ++v7;
        v5 = v5 - v11;
        if ( v7 >= v6 )
          return;
      }
      p_flTime = &m_pMemory[v7].flTime;
      v13 = v5 / p_flTime[2];
      v14 = (float)(p_flTime[12] * (float)(1.0 - v13)) + (float)(p_flTime[26] * v13);
      v15 = (float)(p_flTime[27] * v13) + (float)(p_flTime[13] * (float)(1.0 - v13));
      script.vecLocation.x = (float)(p_flTime[11] * (float)(1.0 - v13)) + (float)(p_flTime[25] * v13);
      script.vecLocation.y = v14;
      script.vecLocation.z = v15;
      if ( bAlwaysSlowdown == 0 )
        SolveQuadratic(
          a: idealAccel * -0.5,
          b: m_pMemory->flMaxVelocity,
          c: COERCE_FLOAT(LODWORD(v5) ^ _mask__NegFloat_),
          root1: &idealAccel,
          root2: (float *)&bAlwaysSlowdown);
      p_flDist = &p_m_scriptMove->m_Memory.m_pMemory[v7].flDist;
      script.flMaxVelocity = 1.0;
      v17 = *p_flDist;
      *p_flDist = v5;
      script.pWaypoint = nullptr;
      script.flDist = v17 - v5;
      CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int>>::InsertBefore(
        this: p_m_scriptMove,
        elem: v7 + 1,
        src: &script);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AA80
// Name: private: int CAI_BlendedMotor::BuildTurnScript(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BlendedMotor::BuildTurnScript(CAI_BlendedMotor *this, int i, int j)
{
  CAI_BlendedMotor::AI_Movementscript_t *m_pMemory; // eax
  int v5; // ebx
  long double v6; // st7
  float destAngle; // xmm0_4
  long double v8; // st7
  CAI_BlendedMotor::AI_Movementscript_t *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  Vector vecDir; // [esp+14h] [ebp-14h] BYREF
  float t2; // [esp+20h] [ebp-8h]
  float t1; // [esp+24h] [ebp-4h]
  float interiorYaw; // [esp+34h] [ebp+Ch]

  m_pMemory = this->m_scriptTurn.m_Memory.m_pMemory;
  v5 = j;
  vecDir.x = m_pMemory[j].vecLocation.x - m_pMemory[i].vecLocation.x;
  vecDir.y = m_pMemory[j].vecLocation.y - m_pMemory[i].vecLocation.y;
  vecDir.z = m_pMemory[j].vecLocation.z - m_pMemory[i].vecLocation.z;
  interiorYaw = UTIL_VecToYaw(vec: &vecDir);
  v6 = AngleDiff(destAngle: interiorYaw, srcAngle: this->m_scriptTurn.m_Memory.m_pMemory[i].flYaw);
  destAngle = this->m_scriptTurn.m_Memory.m_pMemory[v5].flYaw;
  t1 = fabs(v6) * 0.0066666668;
  v8 = AngleDiff(destAngle, srcAngle: interiorYaw);
  v9 = this->m_scriptTurn.m_Memory.m_pMemory;
  v10 = v9[v5].flElapsedTime - v9[i].flElapsedTime;
  t2 = fabs(v8) * 0.0066666668;
  v11 = t2;
  if ( t1 >= 0.01 )
  {
    if ( t2 >= 0.01 )
    {
      if ( (float)(t2 + t1) <= v10 && v10 * 0.8 > (float)(t2 + t1) )
      {
        this->m_scriptTurn.m_Memory.m_pMemory[CAI_BlendedMotor::BuildInsertNode(this, i, flTime: t1)].flYaw = interiorYaw;
        this->m_scriptTurn.m_Memory.m_pMemory[CAI_BlendedMotor::BuildInsertNode(this, i, flTime: t2)].flYaw = interiorYaw;
        return 2;
      }
    }
    else if ( t1 <= v10 * 0.8 )
    {
      this->m_scriptTurn.m_Memory.m_pMemory[CAI_BlendedMotor::BuildInsertNode(this, i, flTime: t1)].flYaw = interiorYaw;
      return 1;
    }
  }
  else if ( t2 <= v10 * 0.8 )
  {
    v9[i].flYaw = interiorYaw;
    this->m_scriptTurn.m_Memory.m_pMemory[CAI_BlendedMotor::BuildInsertNode(this, i, flTime: v10 - v11)].flYaw = interiorYaw;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004ACC0
// Name: private: void CAI_BlendedMotor::BuildVelocityScript(struct AILocalMoveGoal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CAI_BlendedMotor::BuildVelocityScript(
        CAI_BlendedMotor *this@<ecx>,
        int a2@<ebp>,
        const AILocalMoveGoal_t *move)
{
  float v3; // edi
  double IdealSpeed; // st7
  double v5; // st7
  _DWORD *v6; // esi
  float v7; // xmm1_4
  float v8; // xmm2_4
  int v9; // eax
  __int128 v10; // xmm0
  CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> *p_m_Memory; // esi
  ConVar *m_pParent; // ecx
  CAI_BlendedMotor::AI_Movementscript_t *m_pMemory; // eax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  __int128 v17; // xmm1
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  double v22; // xmm1_8
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  __int128 v27; // xmm1
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  double v32; // xmm1_8
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // ecx
  unsigned int v36; // eax
  float v37; // xmm0_4
  int v38; // eax
  float v39; // eax
  float curExpectedDist; // xmm0_4
  float y; // xmm1_4
  float v42; // eax
  unsigned int v43; // ecx
  float z; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm4_4
  float v50; // xmm5_4
  int v51; // edx
  CAI_BlendedMotor::AI_Movementscript_t *v52; // ecx
  float *p_x; // ecx
  __int128 v54; // xmm0
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  __int128 v59; // xmm1
  float v60; // xmm0_4
  float v61; // xmm2_4
  __int128 v62; // xmm0
  __int128 v63; // xmm0
  CAI_Navigator *Navigator; // eax
  CAI_BlendedMotor::AI_Movementscript_t *v65; // edi
  int m_nAllocationCount; // eax
  CAI_BlendedMotor::AI_Movementscript_t *v67; // ecx
  int v68; // eax
  CAI_BlendedMotor::AI_Movementscript_t *v69; // edi
  int v70; // eax
  int v71; // ecx
  float d; // xmm2_4
  int v73; // edx
  float v74; // xmm1_4
  float v75; // xmm0_4
  CAI_BlendedMotor::AI_Movementscript_t *v76; // eax
  float v77; // xmm0_4
  __int128 v78; // xmm1
  float v79; // xmm0_4
  int v80; // eax
  double v81; // st7
  float v82; // xmm1_4
  float v83; // xmm0_4
  float v84; // xmm0_4
  __int128 v85; // xmm1
  CAI_Navigator *v86; // eax
  CAI_Navigator *v87; // eax
  double ArrivalDistance; // st7
  CAI_BlendedMotor::AI_Movementscript_t *v89; // eax
  float v90; // xmm0_4
  float v91; // xmm1_4
  int v92; // ecx
  int v93; // edi
  float flMaxVelocity; // xmm3_4
  CAI_BlendedMotor::AI_Movementscript_t *v95; // eax
  float v96; // xmm0_4
  bool v97; // al
  int v98; // edx
  int v99; // edi
  int v100; // ecx
  float v101; // xmm3_4
  float *v102; // eax
  float v103; // xmm0_4
  bool v104; // al
  float v105; // edi
  int v106; // edx
  float v107; // xmm6_4
  int v108; // edi
  float v109; // xmm5_4
  float v110; // xmm4_4
  float *v111; // eax
  float v112; // xmm3_4
  float v113; // xmm2_4
  float v114; // xmm5_4
  float v115; // xmm4_4
  __int128 v116; // xmm5
  float v117; // xmm0_4
  float v118; // xmm1_4
  float v119; // xmm4_4
  float x; // xmm1_4
  char *v121; // eax
  float v122; // xmm0_4
  float v123; // edx
  __int64 v124; // xmm5_8
  float v125; // eax
  CAI_BlendedMotor::AI_Movementscript_t *v126; // eax
  int v127; // ecx
  CAI_BlendedMotor::AI_Movementscript_t *v128; // ecx
  int v129; // eax
  long double v130; // st7
  float v131; // xmm2_4
  float v132; // xmm3_4
  float v133; // xmm0_4
  float v134; // xmm1_4
  float v135; // xmm2_4
  float v136; // xmm6_4
  float v137; // xmm1_4
  CAI_BlendedMotor::AI_Movementscript_t *v138; // eax
  int v139; // ecx
  CAI_BlendedMotor::AI_Movementscript_t *v140; // ecx
  int v141; // eax
  int v142; // edx
  int v143; // ecx
  int v144; // edx
  float v145; // xmm0_4
  int v146; // edx
  int v147; // ecx
  float v148; // xmm0_4
  float v149; // xmm1_4
  CAI_BlendedMotor::AI_Movementscript_t *v150; // eax
  float v151; // xmm1_4
  __int128 v152; // xmm0
  CAI_BlendedMotor::AI_Movementscript_t *v153; // edi
  float v0; // [esp+8h] [ebp-F8h]
  float maxHorzVelocity; // [esp+Ch] [ebp-F4h]
  Vector v156; // [esp+20h] [ebp-E0h] BYREF
  Vector rawJumpVel; // [esp+2Ch] [ebp-D4h]
  float v158; // [esp+38h] [ebp-C8h]
  float *v159; // [esp+3Ch] [ebp-C4h]
  float v160; // [esp+40h] [ebp-C0h]
  float v161; // [esp+44h] [ebp-BCh]
  float v162; // [esp+48h] [ebp-B8h]
  _BYTE t2[72]; // [esp+4Ch] [ebp-B4h] OVERLAPPED BYREF
  __int128 vecApex; // [esp+94h] [ebp-6Ch] OVERLAPPED
  float v165; // [esp+ACh] [ebp-54h] BYREF
  float v166; // [esp+B0h] [ebp-50h]
  CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> > *v167; // [esp+B4h] [ebp-4Ch]
  __int64 r2; // [esp+B8h] [ebp-48h] OVERLAPPED BYREF
  float v169; // [esp+C0h] [ebp-40h]
  Vector end; // [esp+C4h] [ebp-3Ch] BYREF
  Vector start; // [esp+D0h] [ebp-30h]
  float idealVelocity; // [esp+DCh] [ebp-24h] BYREF
  char v173; // [esp+E3h] [ebp-1Dh]
  float a; // [esp+E4h] [ebp-1Ch]
  int r1; // [esp+E8h] [ebp-18h]
  int v176; // [esp+ECh] [ebp-14h] OVERLAPPED
  int idealAccel; // [esp+F0h] [ebp-10h]
  int i; // [esp+F4h] [ebp-Ch] BYREF
  AI_Waypoint_t *pNext; // [esp+F8h] [ebp-8h]
  AI_Waypoint_t *retaddr; // [esp+100h] [ebp+0h]

  i = a2;
  pNext = retaddr;
  v3 = *(float *)&this;
  LODWORD(start.y) = this;
  IdealSpeed = CAI_Motor::GetIdealSpeed(this);
  start.x = IdealSpeed;
  if ( IdealSpeed == 0.0 )
    start.x = 50.0;
  v5 = CAI_Motor::GetIdealAccel(this: (CAI_Motor *)LODWORD(v3));
  a = v5;
  if ( v5 == 0.0 )
    a = 100.0;
  memset(dst: t2, value: 0, count: 0x38u);
  v6 = *(_DWORD **)(LODWORD(v3) + 4);
  if ( (v6[49] & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: *(CBaseEntity **)(LODWORD(v3) + 4), a2: (int)&i);
  v7 = *(float *)(LODWORD(v3) + 32);
  v8 = *(float *)(LODWORD(v3) + 28);
  v9 = *(_DWORD *)(LODWORD(v3) + 108);
  *(_DWORD *)&t2[44] = v6[115];
  *(_DWORD *)&t2[48] = v6[116];
  *(_DWORD *)&t2[52] = v6[117];
  v10 = 0;
  p_m_Memory = (CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> *)(LODWORD(v3) + 96);
  *(float *)&v10 = fsqrt(
                     (float)((float)(v8 * v8) + (float)(v7 * v7))
                   + (float)(*(float *)(LODWORD(v3) + 36) * *(float *)(LODWORD(v3) + 36)));
  *(_OWORD *)&t2[56] = v10;
  *(_DWORD *)&t2[12] = v10;
  v167 = (CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> > *)(LODWORD(v3) + 96);
  CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int>>::InsertBefore(
    this: (CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> > *)(LODWORD(v3) + 96),
    elem: v9,
    src: (const CAI_BlendedMotor::AI_Movementscript_t *)t2);
  m_pParent = npc_height_adjust.m_pParent;
  if ( npc_height_adjust.m_pParent != nullptr )
  {
    if ( npc_height_adjust.m_pParent->m_Value.m_nValue != 0
      && move->bHasTraced
      && move->directTrace.flTotalDist != move->thinkTrace.flTotalDist )
    {
      m_pMemory = p_m_Memory->m_pMemory;
      v14 = move->directTrace.vEndPosition.y - p_m_Memory->m_pMemory->vecLocation.y;
      v15 = move->directTrace.vEndPosition.x - p_m_Memory->m_pMemory->vecLocation.x;
      v16 = (float)(v15 * v15) + (float)(v14 * v14);
      v17 = 0;
      *(float *)&v17 = fsqrt(v16);
      *(_OWORD *)&t2[56] = v17;
      v18 = *(float *)&v17;
      v19 = move->directTrace.vEndPosition.z - m_pMemory->vecLocation.z;
      if ( v18 <= 0.0 )
        v20 = 0.0;
      else
        v20 = v19 / *(float *)&t2[56];
      v21 = 1.1 - fabs(v20);
      *(float *)(LODWORD(v3) + 188) = v21;
      if ( v19 <= 0.0 )
        v22 = 0.8;
      else
        v22 = 0.5;
      v23 = *(float *)(LODWORD(v3) + 188);
      if ( v22 <= v23 )
      {
        if ( v23 > 1.0 )
          v23 = 1.0;
      }
      else
      {
        v23 = v22;
      }
      *(float *)(LODWORD(v3) + 188) = v23;
      m_pParent = npc_height_adjust.m_pParent;
    }
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      v24 = move->thinkTrace.vEndPosition.y - *(float *)(LODWORD(v3) + 212);
      v25 = move->thinkTrace.vEndPosition.x - *(float *)(LODWORD(v3) + 208);
      v26 = (float)(v25 * v25) + (float)(v24 * v24);
      v27 = 0;
      *(float *)&v27 = fsqrt(v26);
      *(_OWORD *)&t2[56] = v27;
      v28 = *(float *)&v27;
      v29 = move->thinkTrace.vEndPosition.z - *(float *)(LODWORD(v3) + 216);
      if ( v28 <= 0.0 )
        v30 = 0.0;
      else
        v30 = v29 / *(float *)&t2[56];
      v31 = 1.1 - fabs(v30);
      if ( v29 <= 0.0 )
        v32 = 0.8;
      else
        v32 = 0.5;
      if ( v32 <= v31 )
      {
        if ( v31 > 1.0 )
          v31 = 1.0;
      }
      else
      {
        v31 = v32;
      }
      v33 = *(float *)(LODWORD(v3) + 192);
      if ( v33 <= v31 )
        v34 = (float)(v31 + v33) * 0.5;
      else
        v34 = v31 * 0.8 + v33 * 0.2;
      *(float *)(LODWORD(v3) + 192) = v34;
      *(float *)(LODWORD(v3) + 208) = *(float *)(LODWORD(v3) + 196);
      *(float *)(LODWORD(v3) + 212) = *(float *)(LODWORD(v3) + 200);
      *(float *)(LODWORD(v3) + 216) = *(float *)(LODWORD(v3) + 204);
      v35 = *(float *)(LODWORD(v3) + 4);
      v36 = *(_DWORD *)(LODWORD(v35) + 196) >> 11;
      idealVelocity = v35;
      if ( (v36 & 1) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(v35), a2: (int)&i);
        v35 = idealVelocity;
      }
      *(float *)(LODWORD(v3) + 196) = *(float *)(LODWORD(v35) + 460);
      *(float *)(LODWORD(v3) + 200) = *(float *)(LODWORD(v35) + 464);
      *(float *)(LODWORD(v3) + 204) = *(float *)(LODWORD(v35) + 468);
    }
  }
  v37 = *(float *)(LODWORD(v3) + 192);
  if ( *(float *)(LODWORD(v3) + 188) <= v37 )
    v37 = *(float *)(LODWORD(v3) + 188);
  start.x = v37 * start.x;
  v173 = 0;
  idealAccel = (int)CAI_Motor::GetNavigator(this: (CAI_Motor *)LODWORD(v3))->m_pPath->m_Waypoints.m_pFirstWaypoint;
  if ( *(float *)&idealAccel != 0.0 )
  {
    do
    {
      v38 = *(_DWORD *)(idealAccel + 36);
      if ( v38 != 0 && v38 != 2 )
        break;
      memset(dst: t2, value: 0, count: 0x38u);
      v39 = *(float *)(idealAccel + 40);
      *(float *)&v176 = v39;
      if ( ai_path_adjust_speed_on_immediate_turns.m_pParent != nullptr
        && ai_path_adjust_speed_on_immediate_turns.m_pParent->m_Value.m_nValue != 0
        && v173 == 0 )
      {
        curExpectedDist = move->curExpectedDist;
        y = curExpectedDist * move->dir.x;
        v42 = *(float *)(LODWORD(v3) + 4);
        v43 = *(_DWORD *)(LODWORD(v42) + 196) >> 11;
        z = move->dir.y * curExpectedDist;
        v45 = move->dir.z * curExpectedDist;
        rawJumpVel.y = y;
        rawJumpVel.z = z;
        v158 = v45;
        start.z = v42;
        if ( (v43 & 1) != 0 )
        {
          CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(v42), a2: (int)&i);
          v45 = v158;
          z = rawJumpVel.z;
          y = rawJumpVel.y;
          v42 = start.z;
        }
        v46 = *(float *)(LODWORD(v42) + 460) + y;
        v47 = *(float *)(LODWORD(v42) + 464) + z;
        v48 = *(float *)(LODWORD(v42) + 468) + v45;
        *(float *)&t2[44] = v46;
        *(float *)&t2[48] = v47;
        v173 = 1;
        v176 = idealAccel;
        v39 = *(float *)&idealAccel;
      }
      else
      {
        v46 = *(float *)idealAccel;
        *(_DWORD *)&t2[44] = *(_DWORD *)idealAccel;
        v47 = *(float *)(idealAccel + 4);
        *(float *)&t2[48] = v47;
        v48 = *(float *)(idealAccel + 8);
        *(_DWORD *)&t2[32] = idealAccel;
      }
      *(float *)&t2[52] = v48;
      if ( v39 == 0.0 )
      {
        Navigator = CAI_Motor::GetNavigator(this: (CAI_Motor *)LODWORD(v3));
        *(float *)&t2[12] = CAI_Navigator::GetArrivalSpeed(this: Navigator);
      }
      else
      {
        switch ( *(_DWORD *)(LODWORD(v39) + 36) )
        {
          case 0:
          case 2:
            v49 = *(float *)(LODWORD(v39) + 4);
            v50 = *(float *)(LODWORD(v39) + 8);
            v51 = *(_DWORD *)(LODWORD(v3) + 108);
            v52 = p_m_Memory->m_pMemory;
            end.x = *(float *)LODWORD(v39) - v46;
            end.y = v49 - v47;
            p_x = &v52[v51 - 1].vecLocation.x;
            end.z = v50 - v48;
            *(float *)&r2 = v46 - *p_x;
            *((float *)&r2 + 1) = v47 - p_x[1];
            v54 = 0;
            v169 = v48 - p_x[2];
            *(float *)&v54 = fsqrt((float)(end.x * end.x) + (float)(end.y * end.y));
            vecApex = v54;
            if ( *(float *)&v54 < 1.0 )
            {
              *(float *)&idealAccel = v39;
              continue;
            }
            end.z = 0.0;
            VectorNormalize(vec: &end);
            v169 = 0.0;
            VectorNormalize(vec: (Vector *)&r2);
            v55 = (float)((float)((float)(*(float *)&r2 * end.x) + (float)(*((float *)&r2 + 1) * end.y))
                        + (float)(v169 * end.z))
                + 0.2;
            if ( v55 <= 0.0 )
            {
              *(_DWORD *)&t2[12] = 0;
            }
            else
            {
              if ( v55 > 1.0 )
                v55 = 1.0;
              *(float *)&t2[12] = v55 * start.x;
            }
            break;
          case 1:
            v56 = *(float *)(LODWORD(v3) + 32);
            v57 = *(float *)(LODWORD(v3) + 36) * *(float *)(LODWORD(v3) + 36);
            idealVelocity = 0.0;
            v58 = (float)(v56 * v56) + v57;
            v59 = 0;
            v60 = *(float *)(LODWORD(v3) + 28) * *(float *)(LODWORD(v3) + 28);
            *(float *)&v59 = fsqrt(v58 + v60);
            vecApex = v59;
            if ( *(float *)&v59 <= 100.0 )
            {
              LODWORD(v62) = 1120403456;
            }
            else
            {
              v61 = (float)((float)(*(float *)(LODWORD(v3) + 32) * *(float *)(LODWORD(v3) + 32))
                          + (float)(*(float *)(LODWORD(v3) + 36) * *(float *)(LODWORD(v3) + 36)))
                  + v60;
              v62 = 0;
              *(float *)&v62 = fsqrt(v61);
              vecApex = v62;
            }
            CAI_MoveProbe::CalcJumpLaunchVelocity(
              this: *(CAI_MoveProbe **)(LODWORD(v3) + 88),
              result: &v156,
              startPos: (const Vector *)&t2[44],
              endPos: (const Vector *)LODWORD(v39),
              flGravity: *(float *)(*(_DWORD *)(LODWORD(v3) + 4) + 768) * sv_gravity.m_pParent->m_Value.m_fValue,
              pminHeight: &idealVelocity,
              maxHorzVelocity: *(float *)&v62,
              pvecApex: (Vector *)&t2[60]);
            v166 = v156.x * v156.x;
            v63 = 0;
            *(float *)&v63 = fsqrt((float)(v156.x * v156.x) + (float)(v156.y * v156.y));
            vecApex = v63;
            *(_DWORD *)&t2[12] = v63;
            break;
          case 3:
            *(_DWORD *)&t2[12] = 0;
            break;
          default:
            break;
        }
      }
      v65 = p_m_Memory[1].m_pMemory;
      m_nAllocationCount = p_m_Memory->m_nAllocationCount;
      if ( (int)&v65->flTime + 1 > m_nAllocationCount )
        CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
          this: p_m_Memory,
          num: (int)&v65->flTime - m_nAllocationCount + 1);
      ++p_m_Memory[1].m_pMemory;
      v67 = p_m_Memory->m_pMemory;
      v68 = (char *)p_m_Memory[1].m_pMemory - (char *)v65 - 1;
      p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
      if ( v68 > 0 )
        _V_memmove(dest: &v67[(int)v65 + 1], src: &v67[(_DWORD)v65], count: 56 * v68);
      v69 = &p_m_Memory->m_pMemory[(_DWORD)v65];
      if ( v69 != nullptr )
      {
        qmemcpy(v69, t2, sizeof(CAI_BlendedMotor::AI_Movementscript_t));
        p_m_Memory = &v167->m_Memory;
      }
      v3 = start.y;
      idealAccel = v176;
      v39 = *(float *)&v176;
    }
    while ( v39 != 0.0 );
  }
  v70 = *(_DWORD *)(LODWORD(v3) + 108) - 1;
  v71 = 0;
  d = 0.0;
  start.z = 0.0;
  if ( v70 > 0 )
  {
    v73 = 0;
    do
    {
      v74 = p_m_Memory->m_pMemory[v73 + 1].vecLocation.y - p_m_Memory->m_pMemory[v73].vecLocation.y;
      v75 = p_m_Memory->m_pMemory[v73 + 1].vecLocation.x - p_m_Memory->m_pMemory[v73].vecLocation.x;
      v76 = &p_m_Memory->m_pMemory[v73];
      v77 = (float)(v75 * v75) + (float)(v74 * v74);
      v78 = 0;
      *(float *)&v78 = fsqrt(v77);
      *(_OWORD *)&t2[56] = v78;
      LODWORD(v76->flDist) = v78;
      ++v71;
      ++v73;
      v79 = *(float *)&v78 + d;
      d = *(float *)&v78 + d;
    }
    while ( v71 < *(_DWORD *)(LODWORD(v3) + 108) - 1 );
    start.z = v79;
  }
  if ( *(_BYTE *)(LODWORD(v3) + 136) == 0 )
  {
    v80 = *(_DWORD *)(LODWORD(v3) + 108);
    if ( v80 != 0 && d > 0.0 )
    {
      v81 = DeltaV(v0: p_m_Memory->m_pMemory->flMaxVelocity, v1: p_m_Memory->m_pMemory[v80 - 1].flMaxVelocity, d);
      *(_BYTE *)(LODWORD(v3) + 136) = -a > v81;
    }
  }
  if ( ai_path_insert_pause_at_obstruction.m_pParent != nullptr
    && ai_path_insert_pause_at_obstruction.m_pParent->m_Value.m_nValue != 0
    && move->directTrace.pObstruction != nullptr )
  {
    v82 = move->directTrace.vEndPosition.y - p_m_Memory->m_pMemory->vecLocation.y;
    v83 = move->directTrace.vEndPosition.x - p_m_Memory->m_pMemory->vecLocation.x;
    v84 = (float)(v83 * v83) + (float)(v82 * v82);
    v85 = 0;
    *(float *)&v85 = fsqrt(v84);
    vecApex = v85;
    CAI_BlendedMotor::InsertSlowdown(
      this: (CAI_BlendedMotor *)LODWORD(v3),
      distToObstruction: *(float *)&v85 + 16.0,
      idealAccel: a,
      bAlwaysSlowdown: 0);
  }
  if ( ai_path_insert_pause_at_est_end.m_pParent != nullptr
    && ai_path_insert_pause_at_est_end.m_pParent->m_Value.m_nValue != 0 )
  {
    v86 = CAI_Motor::GetNavigator(this: (CAI_Motor *)LODWORD(v3));
    if ( CAI_Navigator::GetArrivalDistance(this: v86) > 0.0 )
    {
      maxHorzVelocity = a;
      v87 = CAI_Motor::GetNavigator(this: (CAI_Motor *)LODWORD(v3));
      ArrivalDistance = CAI_Navigator::GetArrivalDistance(this: v87);
      v0 = start.z - ArrivalDistance;
      CAI_BlendedMotor::InsertSlowdown(
        this: (CAI_BlendedMotor *)LODWORD(v3),
        distToObstruction: v0,
        idealAccel: maxHorzVelocity,
        bAlwaysSlowdown: 1);
    }
  }
  if ( ai_path_adjust_speed_on_immediate_turns.m_pParent != nullptr
    && ai_path_adjust_speed_on_immediate_turns.m_pParent->m_Value.m_nValue != 0
    && *(int *)(LODWORD(v3) + 108) > 1 )
  {
    v89 = p_m_Memory->m_pMemory;
    *(float *)&r2 = p_m_Memory->m_pMemory[1].vecLocation.x - p_m_Memory->m_pMemory->vecLocation.x;
    *((float *)&r2 + 1) = v89[1].vecLocation.y - v89->vecLocation.y;
    v169 = 0.0;
    VectorNormalize(vec: (Vector *)&r2);
    *(_QWORD *)&end.x = *(_QWORD *)(LODWORD(v3) + 28);
    end.z = 0.0;
    VectorNormalize(vec: &end);
    v90 = (float)((float)(*(float *)&r2 * end.x) + (float)(end.y * *((float *)&r2 + 1))) + (float)(end.z * v169);
    if ( v90 >= 0.0 )
    {
      if ( v90 > 1.0 )
        v90 = 1.0;
      p_m_Memory->m_pMemory->flMaxVelocity = v90 * p_m_Memory->m_pMemory->flMaxVelocity;
    }
    else
    {
      p_m_Memory->m_pMemory->flMaxVelocity = 0.0 * p_m_Memory->m_pMemory->flMaxVelocity;
    }
  }
  v91 = a;
  v92 = *(_DWORD *)(LODWORD(v3) + 108) - 1;
  r1 = 0;
  if ( v92 > 0 )
  {
    v93 = 0;
    do
    {
      flMaxVelocity = p_m_Memory->m_pMemory[v93].flMaxVelocity;
      v95 = &p_m_Memory->m_pMemory[v93];
      v96 = v95[1].flMaxVelocity - flMaxVelocity;
      if ( v96 > 0.0
        && (float)((float)((float)((float)(v91 * 0.5) * (float)(v96 / v91)) + flMaxVelocity) * (float)(v96 / v91)) > v95->flDist )
      {
        v97 = SolveQuadratic(a: v91 * 0.5, b: flMaxVelocity, c: -v95->flDist, root1: &idealVelocity, root2: &v165);
        v91 = a;
        if ( v97 )
          p_m_Memory->m_pMemory[v93 + 1].flMaxVelocity = (float)(idealVelocity * a)
                                                       + p_m_Memory->m_pMemory[v93].flMaxVelocity;
      }
      v98 = *(_DWORD *)(LODWORD(start.y) + 108) - 1;
      ++v93;
      ++r1;
    }
    while ( r1 < v98 );
    v3 = start.y;
  }
  v99 = *(_DWORD *)(LODWORD(v3) + 108) - 1;
  if ( v99 > 0 )
  {
    v100 = 56 * v99;
    v176 = 56 * v99;
    do
    {
      v101 = *(float *)((char *)&p_m_Memory->m_pMemory->flMaxVelocity + v100);
      v102 = (float *)((char *)&p_m_Memory->m_pMemory->flTime + v100);
      v103 = v101 - *(v102 - 11);
      if ( v103 < 0.0
        && (float)((float)((float)((float)(v91 * 0.5) * (float)-(float)(v103 / v91)) + v101)
                 * (float)-(float)(v103 / v91)) > *(v102 - 12) )
      {
        v104 = SolveQuadratic(a: v91 * 0.5, b: v101, c: -*(v102 - 12), root1: &idealVelocity, root2: &v165);
        v100 = v176;
        v91 = a;
        if ( v104 )
          *(float *)((char *)p_m_Memory->m_pMemory + v176 - 44) = (float)(idealVelocity * a)
                                                                + *(float *)((char *)&p_m_Memory->m_pMemory->flMaxVelocity
                                                                           + v176);
      }
      --v99;
      v100 -= 56;
      v176 = v100;
    }
    while ( v99 > 0 );
  }
  v105 = start.y;
  v106 = *(_DWORD *)(LODWORD(start.y) + 108) - 1;
  r1 = 0;
  if ( v106 > 0 )
  {
    v107 = v91 * 0.5;
    v108 = 0;
    v109 = 1.0 / v91;
    v166 = 1.0 / v91;
    idealVelocity = v91 * 0.5;
    idealAccel = 1;
    *(float *)&v176 = 0.0;
    while ( 1 )
    {
      v110 = *(float *)((char *)&p_m_Memory->m_pMemory[1].vecLocation.x + v108)
           - *(float *)((char *)&p_m_Memory->m_pMemory->vecLocation.x + v108);
      v111 = (float *)((char *)&p_m_Memory->m_pMemory->flTime + v108);
      v112 = (float)(start.x - v111[17]) * v109;
      v113 = (float)(start.x - v111[3]) * v109;
      v114 = v111[26] - v111[12];
      v115 = (float)(v110 * v110) + (float)(v114 * v114);
      v116 = 0;
      *(float *)&v116 = fsqrt(v115);
      vecApex = v116;
      v117 = (float)(v107 * v113) + v111[3];
      v118 = (float)(v107 * v112) + v111[17];
      *((_DWORD *)v111 + 2) = v116;
      v119 = *(float *)((char *)&p_m_Memory->m_pMemory->flDist + v108);
      x = v118 * v112;
      v121 = (char *)p_m_Memory->m_pMemory + v108;
      v122 = v117 * v113;
      v160 = v112;
      rawJumpVel.x = x;
      if ( v119 <= (float)(x + v122) )
        break;
      v123 = *((float *)v121 + 13);
      *(_QWORD *)&end.x = *(_QWORD *)(v121 + 44);
      v124 = *(_QWORD *)(v121 + 100);
      v125 = *((float *)v121 + 27);
      end.z = v123;
      r2 = v124;
      v169 = v125;
      v162 = v119;
      if ( v122 > 1.0 && v113 > 0.1 )
      {
        start.z = v122 / v119;
        memset(dst: t2, value: 0, count: 0x38u);
        v126 = p_m_Memory[1].m_pMemory;
        v127 = p_m_Memory->m_nAllocationCount;
        *(float *)&t2[44] = (float)(*(float *)&r2 * start.z) + (float)((float)(1.0 - start.z) * end.x);
        *(float *)&t2[48] = (float)(start.z * *((float *)&r2 + 1)) + (float)((float)(1.0 - start.z) * end.y);
        *(float *)&t2[52] = (float)(start.z * v169) + (float)((float)(1.0 - start.z) * end.z);
        *(float *)&t2[12] = start.x;
        if ( (int)&v126->flTime + 1 > v127 )
          CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
            this: p_m_Memory,
            num: (int)&v126->flTime - v127 + 1);
        ++p_m_Memory[1].m_pMemory;
        v128 = p_m_Memory->m_pMemory;
        v129 = (int)p_m_Memory[1].m_pMemory - idealAccel - 1;
        p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
        if ( v129 > 0 )
          _V_memmove(dest: (char *)&v128[2] + v108, src: (char *)&v128[1] + v108, count: 56 * v129);
        if ( (CAI_BlendedMotor::AI_Movementscript_t *)((char *)p_m_Memory->m_pMemory + v108) != (CAI_BlendedMotor::AI_Movementscript_t *)-56 )
        {
          qmemcpy((char *)&p_m_Memory->m_pMemory[1] + v108, t2, 56);
          v108 = v176;
          p_m_Memory = &v167->m_Memory;
        }
        v119 = v162;
        x = rawJumpVel.x;
        v112 = v160;
        ++r1;
        v108 += 56;
        ++idealAccel;
        v176 = v108;
      }
      if ( (float)(v119 - x) > 1.0 && v112 > 0.1 )
      {
        start.z = (float)(v119 - x) / v119;
        memset(dst: t2, value: 0, count: 0x38u);
        *(float *)&t2[44] = (float)(*(float *)&r2 * start.z) + (float)((float)(1.0 - start.z) * end.x);
        *(float *)&t2[48] = (float)(start.z * *((float *)&r2 + 1)) + (float)((float)(1.0 - start.z) * end.y);
        *(float *)&t2[52] = (float)(start.z * v169) + (float)((float)(1.0 - start.z) * end.z);
        *(float *)&t2[12] = start.x;
LABEL_134:
        v138 = p_m_Memory[1].m_pMemory;
        v139 = p_m_Memory->m_nAllocationCount;
        if ( (int)&v138->flTime + 1 > v139 )
          CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
            this: p_m_Memory,
            num: (int)&v138->flTime - v139 + 1);
        ++p_m_Memory[1].m_pMemory;
        v140 = p_m_Memory->m_pMemory;
        v141 = (int)p_m_Memory[1].m_pMemory - idealAccel - 1;
        p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
        if ( v141 > 0 )
          _V_memmove(dest: (char *)&v140[2] + v108, src: (char *)&v140[1] + v108, count: 56 * v141);
        if ( (CAI_BlendedMotor::AI_Movementscript_t *)((char *)p_m_Memory->m_pMemory + v108) != (CAI_BlendedMotor::AI_Movementscript_t *)-56 )
        {
          qmemcpy((char *)&p_m_Memory->m_pMemory[1] + v108, t2, 56);
          v108 = v176;
          p_m_Memory = &v167->m_Memory;
        }
        ++r1;
        v108 += 56;
        ++idealAccel;
      }
LABEL_141:
      v142 = *(_DWORD *)(LODWORD(start.y) + 108);
      ++r1;
      ++idealAccel;
      v108 += 56;
      v176 = v108;
      if ( r1 >= v142 - 1 )
      {
        v105 = start.y;
        goto LABEL_143;
      }
      v107 = idealVelocity;
      v109 = v166;
    }
    v130 = DeltaV(v0: *((float *)v121 + 3), v1: *((float *)v121 + 17), d: *((float *)v121 + 2));
    if ( a <= fabs(v130) )
      goto LABEL_141;
    v131 = *(float *)((char *)&p_m_Memory->m_pMemory->flMaxVelocity + v108);
    v132 = *(float *)((char *)&p_m_Memory->m_pMemory->flDist + v108);
    v133 = *(float *)((char *)&p_m_Memory->m_pMemory[1].flMaxVelocity + v108);
    v134 = (float)(fsqrt(
                     (float)((float)((float)(v131 * 0.5) * v131) + (float)(v132 * a))
                   + (float)((float)(v133 * 0.5) * v133))
                 - v131)
         * v166;
    v159 = (float *)((char *)&p_m_Memory->m_pMemory->flTime + v108);
    if ( v134 <= 0.0 )
      goto LABEL_141;
    v165 = v134 * a;
    if ( (float)((float)((float)((float)(v134 * a) + v131) - v133) * v166) <= 0.0 )
      goto LABEL_141;
    v161 = (float)((float)((float)(idealVelocity * v134) + v131) * v134) / v132;
    memset(dst: t2, value: 0, count: 0x38u);
    v135 = v159[27];
    v136 = v159[13] * (float)(1.0 - v161);
    v137 = (float)(v159[26] * v161) + (float)(v159[12] * (float)(1.0 - v161));
    *(float *)&t2[44] = (float)(v159[25] * v161) + (float)((float)(1.0 - v161) * v159[11]);
    *(float *)&t2[48] = v137;
    *(float *)&t2[52] = (float)(v135 * v161) + v136;
    *(float *)&t2[12] = v165 + v159[3];
    if ( start.x <= *(float *)&t2[12] )
      goto LABEL_141;
    goto LABEL_134;
  }
LABEL_143:
  v143 = 0;
  if ( *(int *)(LODWORD(v105) + 108) > 0 )
  {
    v144 = 0;
    do
    {
      v145 = p_m_Memory->m_pMemory[v144].flMaxVelocity;
      if ( v145 <= 0.0 )
        v145 = 0.0;
      ++v143;
      p_m_Memory->m_pMemory[v144++].flMaxVelocity = v145;
    }
    while ( v143 < *(_DWORD *)(LODWORD(v105) + 108) );
  }
  p_m_Memory->m_pMemory->flElapsedTime = 0.0;
  v146 = 0;
  if ( *(_DWORD *)(LODWORD(v105) + 108) - 1 > 0 )
  {
    v147 = 0;
    do
    {
      v148 = p_m_Memory->m_pMemory[v147 + 1].vecLocation.x - p_m_Memory->m_pMemory[v147].vecLocation.x;
      v149 = p_m_Memory->m_pMemory[v147 + 1].vecLocation.y - p_m_Memory->m_pMemory[v147].vecLocation.y;
      v150 = &p_m_Memory->m_pMemory[v147];
      v151 = (float)(v149 * v149) + (float)(v148 * v148);
      v152 = 0;
      *(float *)&v152 = fsqrt(v151);
      vecApex = v152;
      LODWORD(v150->flDist) = v152;
      v153 = &p_m_Memory->m_pMemory[v147];
      if ( v153->flMaxVelocity == 0.0 && v153[1].flMaxVelocity == 0.0 )
        v153[1].flMaxVelocity = 1.0;
      p_m_Memory->m_pMemory[v147].flTime = p_m_Memory->m_pMemory[v147].flDist
                                         / (float)((float)(p_m_Memory->m_pMemory[v147 + 1].flMaxVelocity
                                                         + p_m_Memory->m_pMemory[v147].flMaxVelocity)
                                                 * 0.5);
      p_m_Memory->m_pMemory[v147 + 1].flElapsedTime = p_m_Memory->m_pMemory[v147].flElapsedTime
                                                    + p_m_Memory->m_pMemory[v147].flTime;
      ++v146;
      ++v147;
    }
    while ( v146 < *(_DWORD *)(LODWORD(start.y) + 108) - 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BEF0
// Name: private: void CAI_BlendedMotor::BuildTurnScript(struct AILocalMoveGoal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BlendedMotor::BuildTurnScript(CAI_BlendedMotor *this, const AILocalMoveGoal_t *move)
{
  CAI_BaseNPC *m_pOuter; // esi
  float z; // xmm0_4
  CAI_BaseNPC *v5; // esi
  unsigned int v6; // edx
  int m_Size; // ecx
  int v8; // eax
  char *v9; // eax
  AI_Waypoint_t *v10; // esi
  CAI_BlendedMotor::AI_Movementscript_t *m_pMemory; // eax
  unsigned int v12; // ecx
  float x; // xmm0_4
  float y; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float *p_x; // esi
  CAI_BlendedMotor::AI_Movementscript_t *v18; // eax
  float *v19; // eax
  long double v20; // st7
  float v21; // xmm0_4
  double v22; // st7
  CAI_Navigator *Navigator; // eax
  int v24; // eax
  int v25; // esi
  CAI_BlendedMotor::AI_Movementscript_t *v26; // eax
  float v27; // xmm0_4
  int j; // esi
  int destAngle; // [esp+4h] [ebp-88h]
  CAI_BlendedMotor::AI_Movementscript_t script; // [esp+18h] [ebp-74h] BYREF
  Vector vecDir; // [esp+50h] [ebp-3Ch] BYREF
  Vector d2; // [esp+5Ch] [ebp-30h] BYREF
  Vector d1; // [esp+68h] [ebp-24h] BYREF
  float deltaYaw; // [esp+74h] [ebp-18h]
  int v35; // [esp+78h] [ebp-14h]
  int i; // [esp+7Ch] [ebp-10h]
  float y1; // [esp+80h] [ebp-Ch]
  float y2; // [esp+84h] [ebp-8h]
  unsigned int v39; // [esp+88h] [ebp-4h]
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  memset(dst: (unsigned __int8 *)&script, value: 0, count: sizeof(script));
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
  script.vecLocation.x = m_pOuter->m_vecAbsOrigin.x;
  script.vecLocation.y = m_pOuter->m_vecAbsOrigin.y;
  z = m_pOuter->m_vecAbsOrigin.z;
  v5 = this->m_pOuter;
  v6 = (unsigned int)v5->m_iEFlags >> 11;
  script.vecLocation.z = z;
  if ( (v6 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
  m_Size = this->m_scriptTurn.m_Size;
  script.flYaw = v5->m_angAbsRotation.y;
  CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int>>::InsertBefore(
    this: &this->m_scriptTurn,
    elem: m_Size,
    src: &script);
  v8 = 0;
  i = 0;
  if ( this->m_scriptMove.m_Size > 0 )
  {
    v39 = 0;
    v35 = 0;
    do
    {
      v9 = (char *)this->m_scriptMove.m_Memory.m_pMemory + v8;
      v10 = *((AI_Waypoint_t **)v9 + 8);
      y1 = *(float *)&v9;
      if ( v10 != nullptr )
      {
        memset(dst: (unsigned __int8 *)&script, value: 0, count: sizeof(script));
        m_pMemory = this->m_scriptTurn.m_Memory.m_pMemory;
        v12 = v39;
        x = v10->vecLocation.x;
        y = v10->vecLocation.y;
        v15 = v10->vecLocation.z;
        script.flElapsedTime = *(float *)(LODWORD(y1) + 4);
        v16 = script.flElapsedTime - m_pMemory[v39 / 0x38].flElapsedTime;
        script.pWaypoint = v10;
        m_pMemory[v39 / 0x38].flTime = v16;
        p_x = &v10->pNext->vecLocation.x;
        script.vecLocation.x = x;
        script.vecLocation.y = y;
        script.vecLocation.z = v15;
        if ( p_x == nullptr )
        {
          Navigator = CAI_Motor::GetNavigator(this);
          CAI_Navigator::GetArrivalDirection(this: Navigator, result: &vecDir);
          v22 = UTIL_VecToYaw(vec: &vecDir);
          destAngle = this->m_scriptTurn.m_Size;
          goto LABEL_12;
        }
        v18 = this->m_scriptTurn.m_Memory.m_pMemory;
        d1.x = *p_x - x;
        d1.y = p_x[1] - y;
        v19 = (float *)((char *)&v18->vecLocation.x + v12);
        d1.z = p_x[2] - v15;
        d2.x = x - *v19;
        d2.y = y - v19[1];
        d2.z = v15 - v19[2];
        d1.z = 0.0;
        VectorNormalize(vec: &d1);
        d2.z = 0.0;
        VectorNormalize(vec: &d2);
        y1 = UTIL_VecToYaw(vec: &d1);
        y2 = UTIL_VecToYaw(vec: &d2);
        v20 = fabs(AngleDiff(destAngle: y1, srcAngle: y2));
        deltaYaw = v20;
        if ( v20 > 0.1 )
        {
          v21 = deltaYaw * 0.8;
          v22 = ApproachAngle(target: y1, value: y2, speed: v21);
          destAngle = this->m_scriptTurn.m_Size;
LABEL_12:
          script.flYaw = v22;
          CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int>>::InsertBefore(
            this: &this->m_scriptTurn,
            elem: destAngle,
            src: &script);
          v39 += 56;
        }
      }
      v8 = v35 + 56;
      ++i;
      v35 += 56;
    }
    while ( i < this->m_scriptMove.m_Size );
  }
  v24 = this->m_scriptTurn.m_Size - 1;
  if ( v24 > 1 )
  {
    v25 = v24;
    v35 = this->m_scriptTurn.m_Size - 2;
    do
    {
      deltaYaw = AngleDiff(
                   destAngle: this->m_scriptTurn.m_Memory.m_pMemory[v25 - 1].flYaw,
                   srcAngle: this->m_scriptTurn.m_Memory.m_pMemory[v25].flYaw);
      v26 = this->m_scriptTurn.m_Memory.m_pMemory;
      v27 = v26[v25 - 1].flTime * 150.0;
      if ( COERCE_FLOAT(LODWORD(deltaYaw) & _mask__AbsFloat_) > v27 )
        this->m_scriptTurn.m_Memory.m_pMemory[v25 - 1].flYaw = ApproachAngle(
                                                                 target: v26[v25 - 1].flYaw,
                                                                 value: v26[v25].flYaw,
                                                                 speed: v27);
      --v25;
      --v35;
    }
    while ( v35 != 0 );
  }
  for ( j = 0; j < this->m_scriptTurn.m_Size - 1; j += CAI_BlendedMotor::BuildTurnScript(this, i: j, j: j + 1) + 1 )
    ;
}

//------------------------------------------------------------------------------
// Address: 0x1004C240
// Name: private: virtual enum AIMotorMoveResult_t CAI_BlendedMotor::MoveGroundExecute(struct AILocalMoveGoal_t const __near &,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
AIMotorMoveResult_t __userpurge CAI_BlendedMotor::MoveGroundExecute@<eax>(
        CAI_BlendedMotor *this@<ecx>,
        float a2@<ebp>,
        const AILocalMoveGoal_t *move,
        AIMoveTrace_t *pTraceResult)
{
  double curExpectedDist; // xmm0_8
  AIMotorMoveResult_t v6; // esi
  __int128 v8; // xmm0
  Vector *v9; // eax
  CAI_BlendedMotor *v10; // esi
  void (__thiscall *MoveFacing)(struct CAI_BlendedMotor *, const AILocalMoveGoal_t *); // edx
  CAI_BaseNPC *m_pOuter; // edi
  _BYTE v13[200]; // [esp+18h] [ebp-E4h] OVERLAPPED BYREF
  float yaw; // [esp+E0h] [ebp-1Ch]
  float dist; // [esp+E4h] [ebp-18h]
  CAI_BlendedMotor *v16; // [esp+E8h] [ebp-14h]
  float flNewYaw; // [esp+ECh] [ebp-10h] BYREF
  float flTotalDist; // [esp+F0h] [ebp-Ch] BYREF
  void *v19; // [esp+F4h] [ebp-8h]
  void *retaddr; // [esp+FCh] [ebp+0h]

  flTotalDist = a2;
  v19 = retaddr;
  curExpectedDist = move->curExpectedDist;
  v16 = this;
  if ( curExpectedDist >= 0.001 )
  {
    this->m_scriptMove.m_Size = 0;
    this->m_scriptTurn.m_Size = 0;
    CAI_BlendedMotor::BuildVelocityScript(this, a2: (int)&flTotalDist, move);
    CAI_BlendedMotor::BuildTurnScript(this, move);
    v8 = 0;
    *(float *)&v8 = fsqrt(
                      (float)((float)(this->m_vecVelocity.x * this->m_vecVelocity.x)
                            + (float)(this->m_vecVelocity.y * this->m_vecVelocity.y))
                    + (float)(this->m_vecVelocity.z * this->m_vecVelocity.z));
    *(_OWORD *)&v13[184] = v8;
    LODWORD(flNewYaw) = v8;
    dist = CAI_BlendedMotor::GetMoveScriptDist(this, flNewSpeed: &flNewYaw);
    yaw = CAI_BlendedMotor::GetMoveScriptYaw(this);
    *(AILocalMoveGoal_t *)v13 = *move;
    v9 = UTIL_YawToVector(result: (Vector *)&v13[188], yaw);
    v10 = v16;
    *(float *)&v13[24] = v9->x;
    *(float *)&v13[28] = v9->y;
    MoveFacing = v16->MoveFacing;
    *(float *)&v13[32] = v9->z;
    MoveFacing(this: v16, a2: (const AILocalMoveGoal_t *)v13);
    m_pOuter = v10->m_pOuter;
    m_pOuter->m_flGroundSpeed = CAI_Motor::GetSequenceGroundSpeed(this: v10, iSequence: m_pOuter->m_nSequence.m_Value);
    CAI_BlendedMotor::SetMoveScriptAnim(this: v10, flNewSpeed: flNewYaw);
    return CAI_Motor::MoveGroundExecuteWalk(this: v10, move, speed: flNewYaw, dist, pTraceResult);
  }
  else
  {
    v6 = CAI_Motor::MoveGroundExecute(this, move, pTraceResult);
    CAI_BlendedMotor::SetMoveScriptAnim(this, flNewSpeed: 0.0);
    return v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C3D0
// Name: private: virtual enum AIMotorMoveResult_t CAI_BlendedMotor::MoveFlyExecute(struct AILocalMoveGoal_t const __near &,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
AIMotorMoveResult_t __userpurge CAI_BlendedMotor::MoveFlyExecute@<eax>(
        CAI_BlendedMotor *this@<ecx>,
        float a2@<ebp>,
        const AILocalMoveGoal_t *move,
        AIMoveTrace_t *pTraceResult)
{
  double curExpectedDist; // xmm0_8
  __int128 v7; // xmm0
  Vector *v8; // eax
  float x; // esi
  void (__thiscall *v10)(_DWORD, _BYTE *); // edx
  int v11; // edi
  float maxDist; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float *v16; // eax
  float v17; // xmm4_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  CBaseEntity *pMoveTarget; // edi
  _BYTE v22[256]; // [esp+20h] [ebp-13Ch] OVERLAPPED BYREF
  Vector v23; // [esp+128h] [ebp-34h] BYREF
  Vector vecStart; // [esp+134h] [ebp-28h] BYREF
  Vector vecEnd; // [esp+140h] [ebp-1Ch] BYREF
  float MoveScriptDist; // [esp+14Ch] [ebp-10h]
  float flNewYaw; // [esp+150h] [ebp-Ch] BYREF
  float flNewSpeed; // [esp+154h] [ebp-8h]
  float retaddr; // [esp+15Ch] [ebp+0h]

  flNewYaw = a2;
  flNewSpeed = retaddr;
  curExpectedDist = move->curExpectedDist;
  LODWORD(vecEnd.x) = this;
  if ( curExpectedDist < 0.001 )
    return CAI_Motor::MoveFlyExecute(this, move, pTraceResult);
  this->m_scriptMove.m_Size = 0;
  this->m_scriptTurn.m_Size = 0;
  CAI_BlendedMotor::BuildVelocityScript(this, a2: (int)&flNewYaw, move);
  CAI_BlendedMotor::BuildTurnScript(this, move);
  v7 = 0;
  *(float *)&v7 = fsqrt(
                    (float)((float)(this->m_vecVelocity.x * this->m_vecVelocity.x)
                          + (float)(this->m_vecVelocity.y * this->m_vecVelocity.y))
                  + (float)(this->m_vecVelocity.z * this->m_vecVelocity.z));
  *(_OWORD *)&v22[240] = v7;
  LODWORD(vecEnd.z) = v7;
  MoveScriptDist = CAI_BlendedMotor::GetMoveScriptDist(this, flNewSpeed: &vecEnd.z);
  vecEnd.y = CAI_BlendedMotor::GetMoveScriptYaw(this);
  *(AILocalMoveGoal_t *)v22 = *move;
  v8 = UTIL_YawToVector(result: (Vector *)&v22[244], yaw: vecEnd.y);
  x = vecEnd.x;
  *(float *)&v22[24] = v8->x;
  *(float *)&v22[28] = v8->y;
  v10 = *(void (__thiscall **)(_DWORD, _BYTE *))(*(_DWORD *)LODWORD(vecEnd.x) + 100);
  *(float *)&v22[32] = v8->z;
  v10(a1: LODWORD(vecEnd.x), a2: v22);
  v11 = *(_DWORD *)(LODWORD(x) + 4);
  *(float *)(v11 + 852) = CAI_Motor::GetSequenceGroundSpeed(
                            this: (CAI_Motor *)LODWORD(x),
                            iSequence: *(_DWORD *)(v11 + 944));
  CAI_BlendedMotor::SetMoveScriptAnim(this: (CAI_BlendedMotor *)LODWORD(x), flNewSpeed: vecEnd.z);
  maxDist = move->maxDist;
  v13 = MoveScriptDist;
  if ( MoveScriptDist <= maxDist )
  {
    *(_DWORD *)(LODWORD(x) + 16) = 0;
  }
  else
  {
    if ( (move->flags & 2) != 0 )
      *(_DWORD *)(LODWORD(x) + 16) = 0;
    else
      *(float *)(LODWORD(x) + 16) = (float)(1.0 - (float)(maxDist / MoveScriptDist)) * *(float *)(LODWORD(x) + 16);
    v13 = move->maxDist;
    MoveScriptDist = v13;
  }
  v14 = move->dir.x * vecEnd.z;
  v15 = vecEnd.z * move->dir.y;
  *(float *)(LODWORD(x) + 36) = vecEnd.z * move->dir.z;
  *(float *)(LODWORD(x) + 28) = v14;
  *(float *)(LODWORD(x) + 32) = v15;
  v16 = *(float **)(LODWORD(x) + 4);
  v17 = move->dir.x;
  v23.x = v16[175];
  v18 = (float)(v17 * v13) + v23.x;
  v23.y = v16[176];
  v19 = v13 * move->dir.y;
  v20 = v13 * move->dir.z;
  v23.z = v16[177];
  vecStart.x = v18;
  vecStart.y = v19 + v23.y;
  vecStart.z = v20 + v23.z;
  memset(dst: &v22[184], value: 0, count: 0x38u);
  CAI_MoveProbe::MoveLimit(
    this: *(CAI_MoveProbe **)(LODWORD(x) + 88),
    navType: NAV_FLY,
    vecStart: &v23,
    vecEnd: &vecStart,
    collisionMask: *(_DWORD *)(*(_DWORD *)(LODWORD(x) + 4) + 3712),
    pTarget: nullptr,
    pctToCheckStandPositions: 100.0,
    flags: 0,
    pTrace: (AIMoveTrace_t *)&v22[184]);
  if ( pTraceResult != nullptr )
    AIMoveTrace_t::operator=(this: pTraceResult, __that: (const AIMoveTrace_t *)&v22[184]);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v22[220] - MoveScriptDist) & _mask__AbsFloat_) > 0.1 )
  {
    UTIL_SetOrigin(entity: *(CBaseEntity **)(LODWORD(x) + 4), vecOrigin: (const Vector *)&v22[188], bFireTriggers: true);
    return 2 * (*(int *)&v22[184] < 0) + 1;
  }
  else
  {
    pMoveTarget = move->pMoveTarget;
    if ( pMoveTarget != nullptr && *(CBaseEntity **)&v22[212] == pMoveTarget )
      return AIM_PARTIAL_HIT_TARGET;
    else
      return AIM_FAILED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FBA10
// Name: CAI_BlendedMotor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_BlendedMotor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_BlendedMotor>(__formal: nullptr);
  CAI_BlendedMotor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA00
// Name: struct datamap_t __near * DataMapInit<class CAI_BlendedMotor>(class CAI_BlendedMotor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_BlendedMotor>()
{
  if ( (_S2_13 & 1) == 0 )
  {
    _S2_13 |= 1u;
    nameHolder_37.m_pszBase = "CAI_BlendedMotor";
    nameHolder_37.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_37.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_37.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_37.m_Names.m_Size = 0;
    nameHolder_37.m_Names.m_pElements = nullptr;
    nameHolder_37.m_nLenBase = 16;
    atexit(func: DataMapInit_CAI_BlendedMotor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_BlendedMotor::m_DataMap.baseMap = nullptr;
  CAI_BlendedMotor::m_DataMap.dataNumFields = 1;
  CAI_BlendedMotor::m_DataMap.dataDesc = dataDesc_467;
  return &CAI_BlendedMotor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FBA20
// Name: _dynamic_initializer_for__ai_path_insert_pause_at_obstruction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_path_insert_pause_at_obstruction__()
{
  ConVar::ConVar(
    this: &ai_path_insert_pause_at_obstruction,
    pName: "ai_path_insert_pause_at_obstruction",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_path_insert_pause_at_obstruction__);
}

//------------------------------------------------------------------------------
// Address: 0x103FBA50
// Name: _dynamic_initializer_for__ai_path_adjust_speed_on_immediate_turns__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_path_adjust_speed_on_immediate_turns__()
{
  ConVar::ConVar(
    this: &ai_path_adjust_speed_on_immediate_turns,
    pName: "ai_path_adjust_speed_on_immediate_turns",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_path_adjust_speed_on_immediate_turns__);
}

//------------------------------------------------------------------------------
// Address: 0x103FBA80
// Name: _dynamic_initializer_for__ai_path_insert_pause_at_est_end__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_path_insert_pause_at_est_end__()
{
  ConVar::ConVar(
    this: &ai_path_insert_pause_at_est_end,
    pName: "ai_path_insert_pause_at_est_end",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_path_insert_pause_at_est_end__);
}
