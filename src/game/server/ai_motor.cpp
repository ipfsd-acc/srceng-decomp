// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_motor.cpp
// Functions: 48
// ============================================================

#include "game\server\ai_motor.h"

//------------------------------------------------------------------------------
// Address: 0x1005BD70
// Name: float DeltaV(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl DeltaV(float v0, float v1, float d)
{
  return (v1 * v1 - v0 * v0) * 0.5 / d;
}

//------------------------------------------------------------------------------
// Address: 0x1005BD90
// Name: public: void CAI_Motor::SetIdealYawAndUpdate(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::SetIdealYawAndUpdate(CAI_Motor *this, float idealYaw, float yawSpeed)
{
  this->m_IdealYaw = idealYaw;
  if ( yawSpeed == -1.0 )
  {
    this->RecalculateYawSpeed(this);
    this->UpdateYaw(this, a2: -1);
  }
  else
  {
    if ( yawSpeed != -2.0 )
      this->m_YawSpeed = yawSpeed;
    this->UpdateYaw(this, a2: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BDF0
// Name: public: virtual void CAI_Motor::RecalculateYawSpeed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::RecalculateYawSpeed(CAI_Motor *this)
{
  this->m_YawSpeed = this->CalcYawSpeed(this: &this->CAI_ProxyMovementSink);
}

//------------------------------------------------------------------------------
// Address: 0x1005BE10
// Name: public: virtual void CAI_Motor::AddFacingTarget(class CBaseEntity __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::AddFacingTarget(
        CAI_Motor *this,
        CBaseEntity *pTarget,
        float flImportance,
        float flDuration,
        float flRamp)
{
  CAI_InterestTarget::Add(this: &this->m_facingQueue, pTarget, flImportance, flDuration, flRamp);
}

//------------------------------------------------------------------------------
// Address: 0x1005BE50
// Name: public: virtual void CAI_Motor::AddFacingTarget(class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::AddFacingTarget(
        CAI_Motor *this,
        const Vector *vecPosition,
        float flImportance,
        float flDuration,
        float flRamp)
{
  CAI_InterestTarget::Add(this: &this->m_facingQueue, vecPosition, flImportance, flDuration, flRamp);
}

//------------------------------------------------------------------------------
// Address: 0x1005BE90
// Name: public: virtual void CAI_Motor::AddFacingTarget(class CBaseEntity __near *,class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::AddFacingTarget(
        CAI_Motor *this,
        CBaseEntity *pTarget,
        const Vector *vecPosition,
        float flImportance,
        float flDuration,
        float flRamp)
{
  CAI_InterestTarget::Add(this: &this->m_facingQueue, pTarget, vecPosition, flImportance, flDuration, flRamp);
}

//------------------------------------------------------------------------------
// Address: 0x1005BED0
// Name: float clamp<float,int,float>(float const __near &,int const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,int,float>(float *val, const int *minVal, float *maxVal)
{
  float v3; // xmm1_4
  float vala; // [esp+8h] [ebp+8h]

  v3 = (float)*minVal;
  vala = *val;
  if ( v3 > vala )
    return v3;
  if ( vala <= *maxVal )
    return vala;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x1005BF20
// Name: public: void CAI_Motor::Init(class IAI_MovementSink __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::Init(CAI_Motor *this, IAI_MovementSink *pMovementServices)
{
  CAI_BaseNPC *m_pOuter; // edx

  m_pOuter = this->m_pOuter;
  this->m_pProxied = pMovementServices;
  this->m_pMoveProbe = m_pOuter->m_pMoveProbe;
}

//------------------------------------------------------------------------------
// Address: 0x1005BF40
// Name: public: virtual int CAI_Motor::MoveJumpExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Motor::MoveJumpExecute(CAI_Motor *this)
{
  CAI_BaseNPC *m_pOuter; // ecx

  this->UpdateYaw(this, a2: -1);
  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_Activity == ACT_JUMP && m_pOuter->IsActivityFinished(this: m_pOuter) )
    this->m_pOuter->SetActivity(this: this->m_pOuter, a2: ACT_GLIDE);
  this->m_flMoveInterval = 0.0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005BF90
// Name: public: float CAI_Motor::GetIdealSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_Motor::GetIdealSpeed(CAI_Motor *this)
{
  return this->m_pOuter->GetIdealSpeed(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x1005BFA0
// Name: public: float CAI_Motor::GetIdealAccel(void)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_Motor::GetIdealAccel(CAI_Motor *this)
{
  return this->m_pOuter->GetIdealAccel(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x1005BFB0
// Name: public: virtual float CAI_Motor::MinStoppingDist(float)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CAI_Motor::MinStoppingDist@<st0>(CAI_Motor *this@<ecx>, int a2@<esi>, float flMinResult)
{
  double v4; // st7
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v9; // [esp-4h] [ebp-10h]
  float v10; // [esp-4h] [ebp-10h]

  v4 = ((double (__thiscall *)(CAI_BaseNPC *, int))this->m_pOuter->GetIdealAccel)(a1: this->m_pOuter, a2);
  v9 = v4;
  if ( v4 <= 0.0 )
    return flMinResult;
  v5 = this->m_vecVelocity.x * this->m_vecVelocity.x;
  v6 = fsqrt(
         (float)((float)(this->m_vecVelocity.y * this->m_vecVelocity.y)
               + (float)(this->m_vecVelocity.z * this->m_vecVelocity.z))
       + v5)
     / v9;
  v10 = (float)(fsqrt(
                  (float)((float)(this->m_vecVelocity.y * this->m_vecVelocity.y)
                        + (float)(this->m_vecVelocity.z * this->m_vecVelocity.z))
                + v5)
              * v6)
      - (float)((float)((float)(v9 * 0.5) * v6) * v6);
  if ( v10 <= flMinResult )
    return flMinResult;
  else
    return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1005C0A0
// Name: public: virtual void CAI_Motor::MoveStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::MoveStop(CAI_Motor *this)
{
  *(_QWORD *)&this->m_vecVelocity.x = 0;
  this->m_vecVelocity.z = 0.0;
  CAI_LocalNavigator::ResetMoveCalculations(this: this->m_pOuter->m_pLocalNavigator);
}

//------------------------------------------------------------------------------
// Address: 0x1005C0C0
// Name: public: float CAI_Motor::CalcIntervalMove(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CAI_Motor::CalcIntervalMove@<st0>(CAI_Motor *this@<ecx>, int a2@<esi>)
{
  double v3; // st7
  float v6; // [esp-10h] [ebp-1Ch]

  v3 = ((double (__thiscall *)(CAI_BaseNPC *, int))this->m_pOuter->GetIdealSpeed)(a1: this->m_pOuter, a2);
  return (v3 + v6) * 0.5 * this->m_flMoveInterval;
}

//------------------------------------------------------------------------------
// Address: 0x1005C130
// Name: float AI_ClampYaw(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl AI_ClampYaw(float yawSpeedPerSec, float current, float target, float time)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  bool v6; // cc

  if ( current == target )
    return target;
  v4 = yawSpeedPerSec * time;
  v5 = target - current;
  if ( target <= current )
  {
    if ( v5 <= -180.0 )
      v5 = v5 + 360.0;
  }
  else if ( v5 >= 180.0 )
  {
    v5 = v5 - 360.0;
  }
  if ( v5 <= 0.0 )
  {
    LODWORD(v4) ^= _mask__NegFloat_;
    v6 = v4 <= v5;
  }
  else
  {
    v6 = v5 <= v4;
  }
  if ( !v6 )
    v5 = v4;
  return (double)(unsigned __int16)(int)(float)((float)(v5 + current) * 182.04445) * 0.0054931641;
}

//------------------------------------------------------------------------------
// Address: 0x1005C1D0
// Name: public: enum AIMoveResult_t CAI_Motor::MoveNormalExecute(struct AILocalMoveGoal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
const AILocalMoveGoal_t *__thiscall CAI_Motor::MoveNormalExecute(CAI_Motor *this, const AILocalMoveGoal_t *move)
{
  const AILocalMoveGoal_t *v3; // edi
  Navigation_t navType; // eax
  AIMotorMoveResult_t v5; // eax
  const AILocalMoveGoal_t *result; // eax
  AIMoveTrace_t moveTrace; // [esp+8h] [ebp-38h] BYREF

  memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
  v3 = move;
  navType = move->navType;
  if ( navType == NAV_GROUND || navType == NAV_CRAWL )
    v5 = this->MoveGroundExecute(this, a2: move, a3: &moveTrace);
  else
    v5 = this->MoveFlyExecute(this, a2: move, a3: &moveTrace);
  move = (const AILocalMoveGoal_t *)moveResults[v5];
  if ( move == nullptr )
    return nullptr;
  this->OnMoveExecuteFailed(
    this: &this->CAI_ProxyMovementSink,
    a2: v3,
    a3: &moveTrace,
    a4: v5,
    a5: (AIMoveResult_t *)&move);
  result = move;
  this->m_flMoveInterval = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005C260
// Name: public: virtual float CAI_Motor::MinCheckDist(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Motor::MinCheckDist(CAI_Motor *this)
{
  double v2; // st6
  double result; // st7
  float flMoveDista; // [esp+Ch] [ebp-4h]
  float flMoveDist; // [esp+Ch] [ebp-4h]

  flMoveDista = this->m_flMoveInterval;
  flMoveDist = ((double (__thiscall *)(CAI_BaseNPC *))this->m_pOuter->GetIdealSpeed)(a1: this->m_pOuter) * flMoveDista;
  if ( ((double (__thiscall *)(CAI_Motor *, int))this->MinStoppingDist)(a1: this, a2: 1092616192) > flMoveDist )
    flMoveDist = ((double (__thiscall *)(CAI_Motor *, int))this->MinStoppingDist)(a1: this, a2: 1092616192);
  v2 = NAI_Hull::Width(id: this->m_pOuter->m_eHull);
  result = flMoveDist;
  if ( v2 > flMoveDist )
    return NAI_Hull::Width(id: this->m_pOuter->m_eHull);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005C300
// Name: public: class CAI_Navigator __near * CAI_Motor::GetNavigator(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Navigator *__thiscall CAI_Motor::GetNavigator(CAI_Motor *this)
{
  return this->m_pOuter->m_pNavigator;
}

//------------------------------------------------------------------------------
// Address: 0x1005C310
// Name: public: int CAI_Motor::SelectWeightedSequence(enum Activity)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Motor::SelectWeightedSequence(CAI_Motor *this, Activity activity)
{
  return CBaseAnimating::SelectWeightedSequence(this: this->m_pOuter, activity);
}

//------------------------------------------------------------------------------
// Address: 0x1005C320
// Name: public: enum AIMotorMoveResult_t CAI_Motor::MoveGroundStep(class Vector const __near &,class CBaseEntity __near *,float,bool,bool,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Motor::MoveGroundStep(
        CAI_Motor *this,
        const Vector *newPos,
        CBaseEntity *pMoveTarget,
        float yaw,
        bool bAsFarAsCan,
        bool bTestZ,
        AIMoveTrace_t *pTraceResult)
{
  unsigned int v8; // ecx
  CBaseEntity *pObstruction; // ecx
  AIMoveResult_t fStatus; // edx
  float x; // xmm0_4
  float v12; // xmm0_4
  bool v13; // bl
  CAI_BaseNPC *m_pOuter; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx
  int v17; // eax
  CAI_BaseNPC *v18; // ecx
  AIMoveTrace_t moveTrace; // [esp+14h] [ebp-44h] BYREF
  QAngle angles; // [esp+4Ch] [ebp-Ch] BYREF
  float height; // [esp+6Ch] [ebp+14h]
  bool bIsBlocked; // [esp+73h] [ebp+1Bh]

  memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
  v8 = 1;
  if ( bTestZ == 2 )
  {
    v8 = 17;
  }
  else if ( !bTestZ )
  {
    v8 = 5;
  }
  CAI_MoveProbe::TestGroundMove(
    this: this->m_pMoveProbe,
    vecActualStart: &this->m_pOuter->m_vecOrigin.m_Value,
    vecDesiredEnd: newPos,
    collisionMask: this->m_pOuter->m_nAITraceMask,
    pctToCheckStandPositions: 100.0,
    flags: v8,
    pMoveTrace: &moveTrace);
  pObstruction = moveTrace.pObstruction;
  fStatus = moveTrace.fStatus;
  if ( pTraceResult != nullptr )
  {
    x = moveTrace.vEndPosition.x;
    pTraceResult->fStatus = moveTrace.fStatus;
    pTraceResult->vEndPosition.x = x;
    pTraceResult->vEndPosition.y = moveTrace.vEndPosition.y;
    pTraceResult->vEndPosition.z = moveTrace.vEndPosition.z;
    pTraceResult->vHitNormal = moveTrace.vHitNormal;
    pTraceResult->flTotalDist = moveTrace.flTotalDist;
    pTraceResult->flDistObstructed = moveTrace.flDistObstructed;
    v12 = moveTrace.vJumpVelocity.x;
    pTraceResult->pObstruction = pObstruction;
    pTraceResult->vJumpVelocity.x = v12;
    pTraceResult->vJumpVelocity.y = moveTrace.vJumpVelocity.y;
    pTraceResult->vJumpVelocity.z = moveTrace.vJumpVelocity.z;
    pTraceResult->flStepUpDistance = moveTrace.flStepUpDistance;
  }
  v13 = pObstruction != nullptr && pMoveTarget == pObstruction;
  bIsBlocked = fStatus < AIMR_OK;
  if ( fStatus < AIMR_OK && !bAsFarAsCan && !v13 )
    return 0;
  UTIL_SetOrigin(entity: this->m_pOuter, vecOrigin: &moveTrace.vEndPosition, bFireTriggers: true);
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_fFlags.m_Value & 1) != 0 )
    CBaseEntity::PhysicsStepRecheckGround(this: m_pOuter);
  if ( moveTrace.flStepUpDistance > 0.1 )
  {
    height = this->m_pOuter->StepHeight(this: this->m_pOuter);
    if ( moveTrace.flStepUpDistance >= 0.0 )
    {
      if ( moveTrace.flStepUpDistance <= height )
        height = moveTrace.flStepUpDistance;
    }
    else
    {
      height = 0.0;
    }
    m_pPhysicsObject = this->m_pOuter->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      v17 = (int)m_pPhysicsObject->GetShadowController(this: m_pPhysicsObject);
      if ( v17 != 0 )
        (*(void (__thiscall **)(int, float))(*(_DWORD *)v17 + 12))(a1: v17, a2: COERCE_FLOAT(LODWORD(height)));
    }
  }
  if ( yaw != -1.0 )
  {
    v18 = this->m_pOuter;
    angles = (QAngle)v18->m_angRotation;
    angles.y = yaw;
    CBaseEntity::SetLocalAngles(this: v18, &angles);
  }
  if ( v13 )
    return 4;
  if ( bIsBlocked )
    return (moveTrace.fStatus != AIMR_BLOCKED_NPC) + 2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005C550
// Name: public: virtual void CAI_Motor::MoveClimbStart(class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::MoveClimbStart(
        CAI_Motor *this,
        const Vector *climbDest,
        const Vector *climbDir,
        float climbDist,
        float yaw)
{
  Activity MovementActivity; // eax
  int v7; // eax

  if ( COERCE_FLOAT(LODWORD(climbDir->z) & _mask__AbsFloat_) >= 0.1 )
  {
    MovementActivity = ACT_CLIMB_UP;
    if ( climbDir->z <= -0.01 )
      MovementActivity = ACT_CLIMB_DOWN;
  }
  else
  {
    MovementActivity = CAI_Navigator::GetMovementActivity(this: this->m_pOuter->m_pNavigator);
  }
  this->m_pOuter->SetActivity(this: this->m_pOuter, a2: MovementActivity);
  v7 = CBaseAnimating::SelectWeightedSequence(this: this->m_pOuter, activity: ACT_CLIMB_DISMOUNT);
  this->m_nDismountSequence = v7;
  if ( v7 == -1 )
  {
    this->m_vecDismount.x = 0.0;
    this->m_vecDismount.y = 0.0;
    this->m_vecDismount.z = 0.0;
  }
  else
  {
    CBaseAnimating::GetSequenceLinearMotion(this: this->m_pOuter, iSequence: v7, pVec: &this->m_vecDismount);
  }
  CBaseEntity::AddFlag(this: this->m_pOuter, flags: 2048);
  CCollisionProperty::SetSolid(this: &this->m_pOuter->m_Collision, val: SOLID_BBOX);
  this->m_pOuter->m_flGravity = 0.0;
  CBaseEntity::SetGroundEntity(this: this->m_pOuter, ground: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1005C620
// Name: public: virtual void CAI_Motor::MoveClimbStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::MoveClimbStop(CAI_Motor *this)
{
  Activity MovementActivity; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  Activity v4; // eax

  MovementActivity = CAI_Navigator::GetMovementActivity(this: this->m_pOuter->m_pNavigator);
  m_pOuter = this->m_pOuter;
  if ( MovementActivity <= ACT_RESET )
  {
    m_pOuter->SetActivity(this: m_pOuter, a2: ACT_IDLE);
  }
  else
  {
    v4 = CAI_Navigator::GetMovementActivity(this: m_pOuter->m_pNavigator);
    this->m_pOuter->SetActivity(this: this->m_pOuter, a2: v4);
  }
  CBaseEntity::RemoveFlag(this: this->m_pOuter, flagsToRemove: 2048);
  CBaseEntity::SetAbsVelocity(this: this->m_pOuter, vecAbsVelocity: &vec3_origin);
  this->m_pOuter->m_flGravity = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1005C690
// Name: public: virtual void CAI_Motor::MoveJumpStart(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::MoveJumpStart(CAI_Motor *this, const Vector *velocity)
{
  CBaseEntity::SetAbsVelocity(this: this->m_pOuter, vecAbsVelocity: velocity);
  this->m_pOuter->m_flGravity = this->m_pOuter->GetJumpGravity(this: this->m_pOuter);
  CBaseEntity::SetGroundEntity(this: this->m_pOuter, ground: nullptr);
  this->m_pOuter->SetActivity(this: this->m_pOuter, a2: ACT_JUMP);
  this->m_IdealYaw = UTIL_VecToYaw(vec: velocity);
  this->RecalculateYawSpeed(this);
  this->UpdateYaw(this, a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1005C700
// Name: public: virtual enum AIMoveResult_t CAI_Motor::MoveJumpStop(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Motor::MoveJumpStop(CAI_Motor *this)
{
  CAI_BaseNPC *m_pOuter; // ecx
  CBaseEntity *v3; // ecx
  CAI_BaseNPC *v4; // ebx
  CAI_BaseNPC *v5; // edi
  CAI_BaseNPC *v6; // ecx
  CAI_BaseNPC *v7; // eax
  Vector vecAbsVelocity; // [esp+18h] [ebp-10h] BYREF
  float flTime; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  memset((void *)&vecAbsVelocity, 0, sizeof(vecAbsVelocity));
  CBaseEntity::SetAbsVelocity(this: m_pOuter, &vecAbsVelocity);
  v3 = this->m_pOuter;
  if ( v3[3].m_pfnThink == (void (__thiscall *)(CBaseEntity *))27 )
  {
    flTime = CBaseEntity::GetGroundChangeTime(this: v3);
    v4 = this->m_pOuter;
    if ( (v4->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    v5 = this->m_pOuter;
    if ( (v5->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    CBaseEntity::AddStepDiscontinuity(
      this: this->m_pOuter,
      flTime,
      vecOrigin: &v5->m_vecAbsOrigin,
      vecAngles: &v4->m_angAbsRotation);
    if ( CBaseAnimating::SelectWeightedSequence(this: this->m_pOuter, activity: ACT_LAND) == -1 )
      return 1;
    this->m_pOuter->SetActivity(this: this->m_pOuter, a2: ACT_LAND);
  }
  v6 = this->m_pOuter;
  if ( v6->m_Activity == ACT_LAND && !v6->IsActivityFinished(this: v6) )
  {
    v7 = this->m_pOuter;
    this->m_flMoveInterval = 0.0;
    v7->m_flGravity = 1.0;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005C800
// Name: protected: enum AIMotorMoveResult_t CAI_Motor::MoveGroundExecuteWalk(struct AILocalMoveGoal_t const __near &,float,float,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
AIMotorMoveResult_t __thiscall CAI_Motor::MoveGroundExecuteWalk(
        CAI_Motor *this,
        const AILocalMoveGoal_t *move,
        float speed,
        float dist,
        AIMoveTrace_t *pTraceResult)
{
  float maxDist; // xmm0_4
  float v7; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  AIMotorMoveResult_t v11; // edi
  bool v12; // zf
  CAI_BaseNPC *m_pOuter; // ecx
  __int64 v14; // xmm0_8
  float y; // xmm1_4
  float z; // xmm2_4
  float v17; // ecx
  AIMotorMoveResult_t result; // eax
  Vector vecTo; // [esp+18h] [ebp-18h] BYREF
  Vector vecFrom; // [esp+24h] [ebp-Ch]
  char bReachingLocalGoal; // [esp+38h] [ebp+8h]

  maxDist = move->maxDist;
  v7 = dist;
  if ( dist <= maxDist )
  {
    bReachingLocalGoal = 0;
    this->m_flMoveInterval = 0.0;
  }
  else
  {
    bReachingLocalGoal = 1;
    if ( (move->flags & 2) != 0 )
      this->m_flMoveInterval = 0.0;
    else
      this->m_flMoveInterval = (float)(1.0 - (float)(maxDist / dist)) * this->m_flMoveInterval;
    v7 = move->maxDist;
  }
  v9 = move->dir.y * speed;
  v10 = move->dir.z * speed;
  this->m_vecVelocity.x = move->dir.x * speed;
  this->m_vecVelocity.y = v9;
  this->m_vecVelocity.z = v10;
  v11 = AIM_SUCCESS;
  if ( v7 <= 0.0 )
  {
    if ( !this->OnMoveStalled(this: &this->CAI_ProxyMovementSink, a2: move) )
      return AIM_FAILED;
    return v11;
  }
  v12 = move->navType == NAV_CRAWL;
  m_pOuter = this->m_pOuter;
  v14 = *(_QWORD *)&m_pOuter->m_vecOrigin.m_Value.x;
  y = move->dir.y;
  z = move->dir.z;
  v17 = m_pOuter->m_vecOrigin.m_Value.z;
  *(_QWORD *)&vecFrom.x = v14;
  *(float *)&v14 = move->dir.x * v7;
  vecTo.y = vecFrom.y + (float)(y * v7);
  vecFrom.z = v17;
  vecTo.x = vecFrom.x + *(float *)&v14;
  vecTo.z = v17 + (float)(z * v7);
  if ( v12 )
    bReachingLocalGoal = 2;
  result = CAI_Motor::MoveGroundStep(
             this,
             newPos: &vecTo,
             pMoveTarget: move->pMoveTarget,
             yaw: -1.0,
             bAsFarAsCan: true,
             bTestZ: bReachingLocalGoal,
             pTraceResult);
  v11 = result;
  if ( result == AIM_FAILED )
  {
    this->MoveStop(this);
    return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005C970
// Name: protected: virtual enum AIMotorMoveResult_t CAI_Motor::MoveFlyExecute(struct AILocalMoveGoal_t const __near &,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CAI_Motor::MoveFlyExecute@<eax>(
        CAI_Motor *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const AILocalMoveGoal_t *move,
        AIMoveTrace_t *pTraceResult)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float m_flMoveInterval; // xmm2_4
  float v15; // xmm3_4
  __int128 v16; // xmm0
  float maxDist; // xmm1_4
  float v18; // xmm0_4
  CAI_BaseNPC *m_pOuter; // eax
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  CBaseEntity *v25; // ecx
  float v26; // xmm1_4
  float v27; // xmm1_4
  CBaseEntity *pMoveTarget; // edi
  AIMoveResult_t v31; // [esp+18h] [ebp-74h] BYREF
  _DWORD v32[2]; // [esp+1Ch] [ebp-70h] BYREF
  _BYTE moveTrace[60]; // [esp+24h] [ebp-68h] OVERLAPPED
  int v34; // [esp+60h] [ebp-2Ch]
  Vector v35; // [esp+64h] [ebp-28h] BYREF
  Vector vecStart; // [esp+70h] [ebp-1Ch] BYREF
  Vector vecEnd; // [esp+7Ch] [ebp-10h]
  float retaddr; // [esp+8Ch] [ebp+0h]

  vecEnd.y = a2;
  vecEnd.z = retaddr;
  ((void (__thiscall *)(CAI_Motor *, const AILocalMoveGoal_t *, int, int, AIMoveResult_t, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->MoveFacing)(
    a1: this,
    a2: move,
    a3,
    a4,
    a5: v31,
    a6: v32[0],
    a7: v32[1],
    a8: *(_DWORD *)moveTrace,
    a9: *(_DWORD *)&moveTrace[4],
    a10: *(_DWORD *)&moveTrace[8],
    a11: *(_DWORD *)&moveTrace[12],
    a12: *(_DWORD *)&moveTrace[16],
    a13: *(_DWORD *)&moveTrace[20],
    a14: *(_DWORD *)&moveTrace[24],
    a15: *(_DWORD *)&moveTrace[28],
    a16: *(_DWORD *)&moveTrace[32],
    a17: *(_DWORD *)&moveTrace[36],
    a18: *(_DWORD *)&moveTrace[40],
    a19: *(_DWORD *)&moveTrace[44],
    a20: *(_DWORD *)&moveTrace[48],
    a21: *(_DWORD *)&moveTrace[52],
    a22: *(_DWORD *)&moveTrace[56],
    a23: v34,
    a24: LODWORD(v35.x),
    a25: LODWORD(v35.y),
    a26: LODWORD(v35.z),
    a27: LODWORD(vecStart.x),
    a28: LODWORD(vecStart.y),
    a29: LODWORD(vecStart.z));
  vecEnd.x = this->m_pOuter->GetIdealSpeed(this: this->m_pOuter);
  x = vecEnd.x;
  y = move->dir.y;
  z = move->dir.z;
  this->m_vecVelocity.x = move->dir.x * vecEnd.x;
  v10 = z * x;
  this->m_vecVelocity.z = v10;
  v11 = v10;
  v12 = y * x;
  this->m_vecVelocity.y = v12;
  v13 = (float)(this->m_vecVelocity.x * this->m_vecVelocity.x) + (float)(v12 * v12);
  m_flMoveInterval = this->m_flMoveInterval;
  v15 = v13 + (float)(v11 * v11);
  v16 = 0;
  *(float *)&v16 = fsqrt(v15);
  *(_OWORD *)&moveTrace[44] = v16;
  *(float *)&v16 = (float)(*(float *)&v16 + x) * 0.5;
  maxDist = move->maxDist;
  v18 = *(float *)&v16 * m_flMoveInterval;
  vecEnd.x = v18;
  if ( v18 <= maxDist )
  {
    this->m_flMoveInterval = 0.0;
  }
  else
  {
    this->m_flMoveInterval = (float)(1.0 - (float)(maxDist / v18)) * m_flMoveInterval;
    v18 = maxDist;
    vecEnd.x = maxDist;
  }
  m_pOuter = this->m_pOuter;
  v20 = move->dir.x;
  v35.x = m_pOuter->m_vecOrigin.m_Value.x;
  v21 = (float)(move->dir.y * v18) + m_pOuter->m_vecOrigin.m_Value.y;
  v35.y = m_pOuter->m_vecOrigin.m_Value.y;
  v22 = m_pOuter->m_vecOrigin.m_Value.z;
  vecStart.y = v21;
  v23 = move->dir.z;
  v35.z = v22;
  memset(
    dst: COERCE_INT((float)(v20 * v18) + v35.x),
    value: nullptr,
    count: COERCE_UNSIGNED_INT((float)(v23 * v18) + v22));
  CAI_MoveProbe::MoveLimit(
    this: this->m_pMoveProbe,
    navType: NAV_FLY,
    vecStart: &v35,
    vecEnd: &vecStart,
    collisionMask: this->m_pOuter->m_nAITraceMask,
    pTarget: nullptr,
    pctToCheckStandPositions: 100.0,
    flags: 0,
    pTrace: (AIMoveTrace_t *)&v31);
  v24 = *(float *)&moveTrace[24];
  v25 = *(CBaseEntity **)&moveTrace[16];
  if ( pTraceResult != nullptr )
  {
    v26 = *(float *)v32;
    pTraceResult->fStatus = v31;
    pTraceResult->vEndPosition.x = v26;
    LODWORD(pTraceResult->vEndPosition.y) = v32[1];
    pTraceResult->vEndPosition.z = *(float *)moveTrace;
    pTraceResult->vHitNormal = *(Vector *)&moveTrace[4];
    pTraceResult->flTotalDist = *(float *)&moveTrace[20];
    v27 = *(float *)&moveTrace[28];
    pTraceResult->pObstruction = v25;
    pTraceResult->flDistObstructed = v24;
    pTraceResult->vJumpVelocity.x = v27;
    pTraceResult->vJumpVelocity.y = *(float *)&moveTrace[32];
    pTraceResult->vJumpVelocity.z = *(float *)&moveTrace[36];
    pTraceResult->flStepUpDistance = *(float *)&moveTrace[40];
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - vecEnd.x) & _mask__AbsFloat_) > 0.1 )
  {
    UTIL_SetOrigin(entity: this->m_pOuter, vecOrigin: (const Vector *)v32, bFireTriggers: true);
    return 2 * (v31 < AIMR_OK) + 1;
  }
  else
  {
    pMoveTarget = move->pMoveTarget;
    if ( pMoveTarget != nullptr && v25 == pMoveTarget )
      return 4;
    else
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CC00
// Name: public: virtual void CAI_Motor::UpdateYaw(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::UpdateYaw(CAI_Motor *this, int yawSpeed)
{
  int m_YawSpeed; // edi
  CAI_BaseNPC *m_pOuter; // ecx
  double v5; // xmm0_8
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  bool v9; // cc
  float v10; // xmm0_4
  CAI_BaseNPC *v11; // ecx
  QAngle angles; // [esp+4h] [ebp-10h] BYREF
  float ideal; // [esp+10h] [ebp-4h]
  float current; // [esp+1Ch] [ebp+8h]

  if ( !this->m_bYawLocked )
  {
    m_YawSpeed = yawSpeed;
    this->m_pOuter->m_ScheduleState.bTaskUpdatedYaw = true;
    if ( yawSpeed == -1 )
      m_YawSpeed = (int)this->m_YawSpeed;
    m_pOuter = this->m_pOuter;
    current = (float)(unsigned __int16)(int)(float)(m_pOuter->m_angRotation.m_Value.y * 182.04445) * 0.0054931641;
    ideal = (float)(unsigned __int16)(int)(float)(this->m_IdealYaw * 182.04445) * 0.0054931641;
    if ( gpGlobals->curtime - CBaseEntity::GetLastThink(this: m_pOuter, szContext: nullptr) <= 0.2 )
    {
      *(double *)&angles.y = gpGlobals->curtime - CBaseEntity::GetLastThink(this: this->m_pOuter, szContext: nullptr);
      v5 = *(double *)&angles.y;
    }
    else
    {
      v5 = 0.2;
    }
    if ( current == ideal )
    {
      v10 = ideal;
    }
    else
    {
      v6 = v5;
      v7 = (float)((float)m_YawSpeed * 10.0) * v6;
      v8 = ideal - current;
      if ( ideal <= current )
      {
        if ( v8 <= -180.0 )
          v8 = v8 + 360.0;
      }
      else if ( v8 >= 180.0 )
      {
        v8 = v8 - 360.0;
      }
      if ( v8 <= 0.0 )
      {
        LODWORD(v7) ^= _mask__NegFloat_;
        v9 = v7 <= v8;
      }
      else
      {
        v9 = v8 <= v7;
      }
      if ( !v9 )
        v8 = v7;
      v10 = (float)(unsigned __int16)(int)(float)((float)(v8 + current) * 182.04445) * 0.0054931641;
    }
    if ( v10 != current )
    {
      v11 = this->m_pOuter;
      angles = (QAngle)v11->m_angRotation;
      angles.y = v10;
      CBaseEntity::SetLocalAngles(this: v11, &angles);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CDB0
// Name: public: float CAI_Motor::DeltaIdealYaw(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Motor::DeltaIdealYaw(CAI_Motor *this)
{
  float destAngle; // xmm1_4
  int v2; // edx

  destAngle = this->m_IdealYaw;
  v2 = (unsigned __int16)(int)(float)(this->m_pOuter->m_angRotation.m_Value.y * 182.04445);
  if ( (float)((float)v2 * 0.0054931641) == destAngle )
    return 0.0;
  else
    return AngleDiff(destAngle, srcAngle: (float)v2 * 0.0054931641);
}

//------------------------------------------------------------------------------
// Address: 0x1005CE10
// Name: public: void CAI_Motor::SetIdealYawToTarget(class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::SetIdealYawToTarget(CAI_Motor *this, const Vector *target, float noise, float offset)
{
  double v5; // st7
  float v6; // xmm0_4
  float base; // [esp+18h] [ebp+8h]
  float basea; // [esp+18h] [ebp+8h]

  base = ((double (__thiscall *)(CAI_BaseNPC *, const Vector *))this->m_pOuter->CalcIdealYaw)(
           a1: this->m_pOuter,
           a2: target)
       + offset;
  if ( noise <= 0.0 )
  {
    v6 = base;
  }
  else
  {
    v5 = ((double (__thiscall *)(IUniformRandomStream *, unsigned int, _DWORD))random->RandomFloat)(
           a1: random,
           a2: COERCE_UNSIGNED_INT(noise * 0.5) ^ (unsigned int)_mask__NegFloat_,
           a3: noise * 0.5)
       + base;
    basea = v5;
    v6 = basea;
    if ( v5 < 0.0 )
    {
      this->m_IdealYaw = basea + 360.0;
      return;
    }
    if ( basea >= 360.0 )
    {
      this->m_IdealYaw = basea - 360.0;
      return;
    }
  }
  this->m_IdealYaw = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1005CEC0
// Name: public: void CAI_Motor::SetIdealYawToTargetAndUpdate(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::SetIdealYawToTargetAndUpdate(CAI_Motor *this, const Vector *target, float yawSpeed)
{
  this->m_IdealYaw = this->m_pOuter->CalcIdealYaw(this: this->m_pOuter, a2: target);
  if ( yawSpeed == -1.0 )
  {
    this->RecalculateYawSpeed(this);
    this->UpdateYaw(this, a2: -1);
  }
  else
  {
    if ( yawSpeed != -2.0 )
      this->m_YawSpeed = yawSpeed;
    this->UpdateYaw(this, a2: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CF30
// Name: public: float CAI_Motor::GetSequenceGroundSpeed(int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_Motor::GetSequenceGroundSpeed(CAI_Motor *this, int iSequence)
{
  CAI_BaseNPC *m_pOuter; // esi
  CStudioHdr *m_pStudioHdr; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: this->m_pOuter) != nullptr )
    CBaseAnimating::LockStudioHdr(this: m_pOuter);
  m_pStudioHdr = m_pOuter->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return m_pOuter->GetSequenceGroundSpeed(this: m_pOuter, a2: m_pStudioHdr, a3: iSequence);
}

//------------------------------------------------------------------------------
// Address: 0x1005CF80
// Name: protected: float CAI_Motor::GetPlaybackRate(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Motor::GetPlaybackRate(CAI_Motor *this)
{
  CAI_BaseNPC *m_pOuter; // eax
  float v2; // xmm0_4

  m_pOuter = this->m_pOuter;
  v2 = 1.0 - m_pOuter->m_flFrozen.m_Value;
  if ( v2 < 0.0 )
    return m_pOuter->m_flPlaybackRate.m_Value * 0.0;
  if ( v2 <= 1.0 )
    return m_pOuter->m_flPlaybackRate.m_Value * v2;
  return m_pOuter->m_flPlaybackRate.m_Value * 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1005CFE0
// Name: protected: float CAI_Motor::SetPoseParameter(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Motor::SetPoseParameter(CAI_Motor *this, int iParameter, float flValue)
{
  CAI_BaseNPC *m_pOuter; // esi
  CStudioHdr *m_pStudioHdr; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: this->m_pOuter) != nullptr )
    CBaseAnimating::LockStudioHdr(this: m_pOuter);
  m_pStudioHdr = m_pOuter->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return CBaseAnimating::SetPoseParameter(this: m_pOuter, pStudioHdr: m_pStudioHdr, iParameter, flValue);
}

//------------------------------------------------------------------------------
// Address: 0x1005D030
// Name: protected: virtual enum AIMotorMoveResult_t CAI_Motor::MoveGroundExecute(struct AILocalMoveGoal_t const __near &,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
AIMotorMoveResult_t __userpurge CAI_Motor::MoveGroundExecute@<eax>(
        CAI_Motor *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const AILocalMoveGoal_t *move,
        AIMoveTrace_t *pTraceResult)
{
  float v8; // [esp+20h] [ebp-2Ch]
  float speed; // [esp+34h] [ebp-18h]
  float m_flMoveInterval; // [esp+38h] [ebp-14h]
  float v11; // [esp+3Ch] [ebp-10h]

  ((void (__thiscall *)(CAI_Motor *, const AILocalMoveGoal_t *, int, int))this->MoveFacing)(
    a1: this,
    a2: move,
    a3: a2,
    a4: a3);
  v8 = fsqrt(
         (float)((float)(this->m_vecVelocity.x * this->m_vecVelocity.x)
               + (float)(this->m_vecVelocity.y * this->m_vecVelocity.y))
       + (float)(this->m_vecVelocity.z * this->m_vecVelocity.z));
  v11 = this->m_pOuter->GetIdealSpeed(this: this->m_pOuter);
  m_flMoveInterval = this->m_flMoveInterval;
  speed = this->m_pOuter->GetIdealSpeed(this: this->m_pOuter);
  return CAI_Motor::MoveGroundExecuteWalk(
           this,
           move,
           speed,
           dist: (float)((float)(v8 + v11) * 0.5) * m_flMoveInterval,
           pTraceResult);
}

//------------------------------------------------------------------------------
// Address: 0x1005D100
// Name: protected: virtual void CAI_Motor::MoveFacing(struct AILocalMoveGoal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::MoveFacing(CAI_Motor *this, const AILocalMoveGoal_t *move)
{
  CAI_BaseNPC *m_pOuter; // ecx
  int m_Value; // edi
  double SequenceMoveYaw; // st7
  bool HasPoseParameter; // al
  CAI_Motor_vtbl *v8; // edx
  void (__thiscall *v9)(CAI_Motor *); // eax
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  void (__thiscall *RecalculateYawSpeed)(CAI_Motor *); // eax
  Vector dir; // [esp+20h] [ebp-10h] BYREF
  float flMoveYaw; // [esp+2Ch] [ebp-4h]
  int savedregs; // [esp+30h] [ebp+0h] BYREF
  float flDiff; // [esp+38h] [ebp+8h]
  float flDiffa; // [esp+38h] [ebp+8h]
  float flDiffb; // [esp+38h] [ebp+8h]

  if ( ((unsigned __int8 (__stdcall *)(const AILocalMoveGoal_t *, _DWORD))this->m_pOuter->OverrideMoveFacing)(
         a1: move,
         a2: LODWORD(this->m_flMoveInterval)) == 0 )
  {
    flMoveYaw = UTIL_VecToYaw(vec: &move->dir);
    m_pOuter = this->m_pOuter;
    m_Value = m_pOuter->m_nSequence.m_Value;
    SequenceMoveYaw = CBaseAnimating::GetSequenceMoveYaw(
                        this: m_pOuter,
                        a2: COERCE_FLOAT(&savedregs),
                        iSequence: m_Value);
    flDiff = SequenceMoveYaw;
    if ( SequenceMoveYaw == 99999.0 )
      flDiff = 0.0;
    HasPoseParameter = CBaseAnimating::HasPoseParameter(
                         this: this->m_pOuter,
                         iSequence: m_Value,
                         iParameter: this->m_pOuter->m_poseMove_Yaw);
    v8 = this->CAI_Component::__vftable;
    if ( HasPoseParameter )
    {
      flDiffa = v8->GetFacingDirection(this, a2: &dir);
      v10 = (float)(move->facing.y * (float)(1.0 - flDiffa)) + (float)(dir.y * flDiffa);
      v11 = (float)(move->facing.z * (float)(1.0 - flDiffa)) + (float)(dir.z * flDiffa);
      dir.x = (float)((float)(1.0 - flDiffa) * move->facing.x) + (float)(dir.x * flDiffa);
      dir.y = v10;
      dir.z = v11;
      VectorNormalize(vec: &dir);
      v12 = (float)(unsigned __int16)(int)(UTIL_VecToYaw(vec: &dir) * 182.04445) * 0.0054931641;
      RecalculateYawSpeed = this->RecalculateYawSpeed;
      this->m_IdealYaw = v12;
      RecalculateYawSpeed(this);
      this->UpdateYaw(this, a2: -1);
      flDiffb = AngleDiff(destAngle: flMoveYaw, srcAngle: this->m_pOuter->m_angRotation.m_Value.y);
      CAI_Motor::SetPoseParameter(this, iParameter: this->m_pOuter->m_poseMove_Yaw, flValue: flDiffb);
    }
    else
    {
      v9 = v8->RecalculateYawSpeed;
      this->m_IdealYaw = (float)(unsigned __int16)(int)(float)((float)(flMoveYaw - flDiff) * 182.04445) * 0.0054931641;
      v9(this);
      this->UpdateYaw(this, a2: -1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D2E0
// Name: public: virtual float CAI_Motor::GetFacingDirection(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Motor::GetFacingDirection(CAI_Motor *this, Vector *vecDir)
{
  int v4; // ebx
  CAI_BaseNPC *m_pOuter; // ebx
  const Vector *Position; // eax
  float z; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  float flInterest; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  float flTotalInterest; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  Vector *vecDira; // [esp+20h] [ebp+8h]
  Vector *vecDirb; // [esp+20h] [ebp+8h]

  v4 = 0;
  vecDir->x = 0.0;
  vecDir->y = 0.0;
  vecDir->z = 0.0;
  flTotalInterest = 0.0;
  if ( this->m_facingQueue.m_Size > 0 )
  {
    vecDira = nullptr;
    do
    {
      if ( CAI_InterestTarget_t::IsActive(this: (CAI_InterestTarget_t *)((char *)vecDira
                                                                       + (unsigned int)this->m_facingQueue.m_Memory.m_pMemory)) )
      {
        ++v4;
        vecDira += 3;
      }
      else
      {
        if ( this->m_facingQueue.m_Size - v4 - 1 > 0 )
          _V_memmove(
            dest: (char *)vecDira + (unsigned int)this->m_facingQueue.m_Memory.m_pMemory,
            src: (char *)&vecDira[3] + (unsigned int)this->m_facingQueue.m_Memory.m_pMemory,
            count: 36 * (this->m_facingQueue.m_Size - v4 - 1));
        --this->m_facingQueue.m_Size;
      }
    }
    while ( v4 < this->m_facingQueue.m_Size );
  }
  i = 0;
  if ( this->m_facingQueue.m_Size > 0 )
  {
    vecDirb = nullptr;
    do
    {
      flInterest = CAI_InterestTarget_t::Interest(this: (CAI_InterestTarget_t *)((char *)vecDirb
                                                                               + (unsigned int)this->m_facingQueue.m_Memory.m_pMemory));
      m_pOuter = this->m_pOuter;
      if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
      Position = CAI_InterestTarget_t::GetPosition(this: (CAI_InterestTarget_t *)((char *)vecDirb
                                                                                + (unsigned int)this->m_facingQueue.m_Memory.m_pMemory));
      tmp.x = Position->x - m_pOuter->m_vecAbsOrigin.x;
      tmp.y = Position->y - m_pOuter->m_vecAbsOrigin.y;
      tmp.z = Position->z - m_pOuter->m_vecAbsOrigin.z;
      VectorNormalize(vec: &tmp);
      z = vecDir->z;
      v8 = 1.0 - flInterest;
      v9 = tmp.z * flInterest;
      v10 = (float)((float)(1.0 - flInterest) * vecDir->y) + (float)(tmp.y * flInterest);
      vecDir->x = (float)((float)(1.0 - flInterest) * vecDir->x) + (float)(tmp.x * flInterest);
      vecDir->y = v10;
      v11 = 1.0 - (float)((float)(1.0 - flTotalInterest) * v8);
      vecDir->z = (float)(z * v8) + v9;
      flTotalInterest = v11;
      VectorNormalize(vec: vecDir);
      vecDirb += 3;
      ++i;
    }
    while ( i < this->m_facingQueue.m_Size );
  }
  return flTotalInterest;
}

//------------------------------------------------------------------------------
// Address: 0x1005D480
// Name: public: virtual CAI_Motor::~CAI_Motor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::~CAI_Motor(CAI_Motor *this)
{
  this->CAI_Component::__vftable = (CAI_Motor_vtbl *)&CAI_Motor::`vftable'{for `CAI_Component'};
  this->CAI_ProxyMovementSink::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_ProxyMovementSink_vtbl *)&CAI_Motor::`vftable'{for `CAI_ProxyMovementSink'};
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_facingQueue);
  this->CAI_Component::__vftable = (CAI_Motor_vtbl *)&CAI_Component::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1005D4A0
// Name: public: virtual float CAI_Motor::OverrideMaxYawSpeed(enum Activity)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Motor::OverrideMaxYawSpeed(CAI_Motor *this, Activity activity)
{
  return -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1005D4B0
// Name: public: virtual enum AIMoveResult_t CAI_Motor::MoveClimbExecute(class Vector const __near &,class Vector const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Motor::MoveClimbExecute(
        CAI_Motor *this,
        const Vector *climbDest,
        const Vector *climbDir,
        float climbDist,
        float yaw,
        int climbNodesLeft)
{
  CAI_BaseNPC *m_pOuter; // ecx
  Activity m_Activity; // eax
  int v10; // edx
  CAI_BaseNPC *v11; // ecx
  Activity v12; // eax
  CAI_BaseNPC *v14; // edi
  double v15; // xmm0_8
  float v16; // xmm0_4
  CAI_BaseNPC *v17; // ecx
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  CAI_BaseNPC *v21; // ecx
  void (__thiscall *RecalculateYawSpeed)(CAI_Motor *); // eax
  float flDist; // [esp+8h] [ebp-1Ch]
  Vector vecAbsVelocity; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF
  float climbSpeed; // [esp+30h] [ebp+Ch]
  float climbSpeeda; // [esp+30h] [ebp+Ch]

  if ( fabs(climbDir->z) > 0.1 )
  {
    m_pOuter = this->m_pOuter;
    m_Activity = m_pOuter->m_Activity;
    if ( m_Activity != ACT_CLIMB_DISMOUNT )
    {
      v10 = 33;
      if ( climbDir->z <= -0.01 )
        v10 = 34;
      if ( m_Activity != v10 )
        m_pOuter->SetActivity(this: m_pOuter, a2: (Activity)v10);
    }
    v11 = this->m_pOuter;
    v12 = v11->m_Activity;
    if ( v12 != ACT_CLIMB_UP && v12 != ACT_CLIMB_DOWN && v12 != ACT_CLIMB_DISMOUNT )
    {
      DevMsg(a1: "Climber not in a climb activity!\n");
      return -4;
    }
    if ( this->m_nDismountSequence != -1
      && v12 == ACT_CLIMB_UP
      && climbNodesLeft <= 2
      && fabs(this->m_vecDismount.z) > climbDist )
    {
      v11->SetActivity(this: v11, a2: ACT_CLIMB_DISMOUNT);
      v14 = this->m_pOuter;
      flDist = CBaseAnimating::GetMovementFrame(this: v14, flDist: this->m_vecDismount.z - climbDist);
      CBaseAnimating::SetCycle(this: v14, flCycle: flDist);
    }
  }
  climbSpeed = CBaseAnimating::GetInstantaneousVelocity(this: this->m_pOuter, a2: (int)&savedregs, flInterval: 0.0);
  if ( this->m_nDismountSequence == -1 )
  {
    v16 = 100.0;
  }
  else
  {
    v15 = 30.0;
    if ( climbSpeed > 30.0 )
      v15 = climbSpeed;
    v16 = v15;
  }
  v17 = this->m_pOuter;
  vecAbsVelocity.x = climbDir->x * v16;
  v18 = climbDir->y * v16;
  climbSpeeda = v16;
  v19 = v16 * climbDir->z;
  vecAbsVelocity.y = v18;
  vecAbsVelocity.z = v19;
  CBaseEntity::SetAbsVelocity(this: v17, &vecAbsVelocity);
  v20 = climbDist;
  if ( (float)(this->m_flMoveInterval * climbSpeeda) <= climbDist )
  {
    RecalculateYawSpeed = this->RecalculateYawSpeed;
    this->m_flMoveInterval = 0.0;
    this->m_IdealYaw = yaw;
    RecalculateYawSpeed(this);
    this->UpdateYaw(this, a2: -1);
    return 0;
  }
  else
  {
    if ( climbDist <= 0.01 )
      v20 = 0.0;
    v21 = this->m_pOuter;
    this->m_flMoveInterval = this->m_flMoveInterval - (float)(v20 / climbSpeeda);
    CBaseEntity::SetLocalOrigin(this: v21, origin: climbDest);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D6B0
// Name: protected: void CAI_Motor::SetPlaybackRate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Motor::SetPlaybackRate(CAI_Motor *this, float flRate)
{
  CAI_BaseNPC *m_pOuter; // eax
  float *p_m_Value; // esi
  CBaseEdict *v4; // ecx

  m_pOuter = this->m_pOuter;
  p_m_Value = &m_pOuter->m_flPlaybackRate.m_Value;
  m_pOuter->m_bSequenceFinished = false;
  if ( m_pOuter->m_flPlaybackRate.m_Value != flRate )
  {
    if ( m_pOuter->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&m_pOuter->m_Network + 76) |= 1u;
      *p_m_Value = flRate;
    }
    else
    {
      v4 = &m_pOuter->m_Network.m_pPev->CBaseEdict;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: v4, offset: 0x37Cu);
      *p_m_Value = flRate;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D720
// Name: public: CAI_Motor::CAI_Motor(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Motor *__thiscall CAI_Motor::CAI_Motor(CAI_Motor *this, CAI_BaseNPC *pOuter)
{
  this->m_pOuter = pOuter;
  this->CAI_ProxyMovementSink::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_ProxyMovementSink_vtbl *)&CAI_ProxyMovementSink::`vftable';
  this->m_pProxied = nullptr;
  this->CAI_Component::__vftable = (CAI_Motor_vtbl *)&CAI_Motor::`vftable'{for `CAI_Component'};
  this->CAI_ProxyMovementSink::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_ProxyMovementSink_vtbl *)&CAI_Motor::`vftable'{for `CAI_ProxyMovementSink'};
  this->m_facingQueue.m_Memory.m_pMemory = nullptr;
  this->m_facingQueue.m_Memory.m_nAllocationCount = 0;
  this->m_facingQueue.m_Memory.m_nGrowSize = 0;
  this->m_facingQueue.m_Size = 0;
  this->m_facingQueue.m_pElements = nullptr;
  this->m_flMoveInterval = 0.0;
  this->m_IdealYaw = 0.0;
  this->m_YawSpeed = 0.0;
  this->m_vecVelocity.x = 0.0;
  this->m_vecVelocity.y = 0.0;
  this->m_vecVelocity.z = 0.0;
  this->m_pMoveProbe = nullptr;
  this->m_bYawLocked = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103FC810
// Name: CAI_Motor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Motor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Motor>(__formal: nullptr);
  CAI_Motor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005D7C0
// Name: struct datamap_t __near * DataMapInit<class CAI_Motor>(class CAI_Motor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Motor>()
{
  if ( (_S2_22 & 1) == 0 )
  {
    _S2_22 |= 1u;
    nameHolder_51.m_pszBase = "CAI_Motor";
    nameHolder_51.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_51.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_51.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_51.m_Names.m_Size = 0;
    nameHolder_51.m_Names.m_pElements = nullptr;
    nameHolder_51.m_nLenBase = 9;
    atexit(func: DataMapInit_CAI_Motor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Motor::m_DataMap.baseMap = nullptr;
  if ( (_S2_22 & 2) == 0 )
  {
    _S2_22 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::`local static guard' & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::ops = (int)&CUtlVectorDataOps<CAI_InterestTarget,10>::`vftable';
    }
    *(_QWORD *)&dataDesc_49[7].td = 0;
    *(_QWORD *)&dataDesc_49[7].override_field = 0;
    *(_QWORD *)&dataDesc_49[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_49[7].flatOffset[1] = 0;
    dataDesc_49[8].fieldTolerance = 0.0;
    dataDesc_49[7].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CAI_InterestTarget>'::`2'::ops;
    dataDesc_49[7].inputFunc = nullptr;
    dataDesc_49[8].fieldType = FIELD_BOOLEAN;
    dataDesc_49[8].fieldName = "m_bYawLocked";
    dataDesc_49[8].fieldOffset = 92;
    dataDesc_49[8].fieldSize = 1;
    dataDesc_49[8].flags = 2;
    dataDesc_49[8].externalName = nullptr;
    dataDesc_49[8].pSaveRestoreOps = nullptr;
    dataDesc_49[8].inputFunc = nullptr;
    dataDesc_49[8].td = nullptr;
    dataDesc_49[8].fieldSizeInBytes = 1;
    dataDesc_49[8].override_field = nullptr;
    dataDesc_49[8].override_count = 0;
    *(_QWORD *)dataDesc_49[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_49[8].flatGroup = 0;
  }
  CAI_Motor::m_DataMap.dataNumFields = 8;
  CAI_Motor::m_DataMap.dataDesc = &dataDesc_49[1];
  return &CAI_Motor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FC820
// Name: _dynamic_initializer_for__ai_moveprobe_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_moveprobe_debug__()
{
  ConVar::ConVar(this: &ai_moveprobe_debug, pName: "ai_moveprobe_debug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_moveprobe_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x103FC850
// Name: _dynamic_initializer_for__ai_moveprobe_jump_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_moveprobe_jump_debug__()
{
  ConVar::ConVar(this: &ai_moveprobe_jump_debug, pName: "ai_moveprobe_jump_debug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_moveprobe_jump_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x103FC880
// Name: _dynamic_initializer_for__ai_moveprobe_usetracelist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_moveprobe_usetracelist__()
{
  ConVar::ConVar(this: &ai_moveprobe_usetracelist, pName: "ai_moveprobe_usetracelist", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_moveprobe_usetracelist__);
}

//------------------------------------------------------------------------------
// Address: 0x103FC8B0
// Name: _dynamic_initializer_for__ai_strong_optimizations_no_checkstand__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_strong_optimizations_no_checkstand__()
{
  ConVar::ConVar(
    this: &ai_strong_optimizations_no_checkstand,
    pName: "ai_strong_optimizations_no_checkstand",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_strong_optimizations_no_checkstand__);
}

//------------------------------------------------------------------------------
// Address: 0x103FC8E0
// Name: _dynamic_initializer_for__ai_set_move_height_epsilon_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_set_move_height_epsilon_command__()
{
  ConCommand::ConCommand(
    this: &ai_set_move_height_epsilon_command,
    pName: "ai_set_move_height_epsilon",
    callback: ai_set_move_height_epsilon,
    pHelpString: "Set how high AI bumps up ground walkers when checking steps",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ai_set_move_height_epsilon_command__);
}
