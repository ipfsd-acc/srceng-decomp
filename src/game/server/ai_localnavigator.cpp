// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_localnavigator.cpp
// Functions: 25
// ============================================================

#include "game\server\ai_localnavigator.h"

//------------------------------------------------------------------------------
// Address: 0x100581F0
// Name: public: static void CAI_LocalNavigator::RemoveGlobalObstacle(struct Obstacle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_LocalNavigator::RemoveGlobalObstacle(Obstacle_t__ *hObstacle)
{
  CAI_PlaneSolver::RemoveGlobalObstacle(hObstacle);
}

//------------------------------------------------------------------------------
// Address: 0x10058200
// Name: public: static bool CAI_LocalNavigator::IsSegmentBlockedByGlobalObstacles(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAI_LocalNavigator::IsSegmentBlockedByGlobalObstacles(const Vector *vecStart, const Vector *vecEnd)
{
  return CAI_PlaneSolver::IsSegmentBlockedByGlobalObstacles(vecStart, vecEnd);
}

//------------------------------------------------------------------------------
// Address: 0x10058210
// Name: public: struct AILocalMoveGoal_t __near & AILocalMoveGoal_t::operator=(struct AILocalMoveGoal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
AILocalMoveGoal_t *__thiscall AILocalMoveGoal_t::operator=(AILocalMoveGoal_t *this, const AILocalMoveGoal_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10058380
// Name: protected: bool CAI_LocalNavigator::MoveCalcStop(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_LocalNavigator::MoveCalcStop(
        CAI_LocalNavigator *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  if ( pMoveGoal->maxDist <= distClear )
  {
    *pResult = AIMR_OK;
    return 1;
  }
  else
  {
    if ( distClear >= 0.1 )
    {
      pMoveGoal->maxDist = distClear;
      *pResult = AIMR_OK;
    }
    else
    {
      *pResult = AIMR_ILLEGAL;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100583E0
// Name: bool VectorsAreEqual(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VectorsAreEqual(const Vector *src1, const Vector *src2, float tolerance)
{
  return fabs(src1->x - src2->x) <= tolerance
      && fabs(src1->y - src2->y) <= tolerance
      && tolerance >= fabs(src1->z - src2->z);
}

//------------------------------------------------------------------------------
// Address: 0x10058440
// Name: public: void CAI_LocalNavigator::Init(class IAI_MovementSink __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_LocalNavigator::Init(CAI_LocalNavigator *this, IAI_MovementSink *pMovementServices)
{
  CAI_BaseNPC *m_pOuter; // edx

  m_pOuter = this->m_pOuter;
  this->m_pProxied = pMovementServices;
  this->m_pMoveProbe = m_pOuter->m_pMoveProbe;
}

//------------------------------------------------------------------------------
// Address: 0x10058460
// Name: public: void CAI_LocalNavigator::ResetMoveCalculations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_LocalNavigator::ResetMoveCalculations(CAI_LocalNavigator *this)
{
  CAI_PlaneSolver *m_pPlaneSolver; // eax

  m_pPlaneSolver = this->m_pPlaneSolver;
  this->m_FullDirectTimer.m_next = -1.0;
  m_pPlaneSolver->m_RefreshSamplesTimer.m_next = -1.0;
  m_pPlaneSolver->m_fSolvedPrev = false;
  m_pPlaneSolver->m_PrevTarget.x = 3.4028235e38;
  m_pPlaneSolver->m_PrevTarget.y = 3.4028235e38;
  m_pPlaneSolver->m_PrevTarget.z = 3.4028235e38;
  m_pPlaneSolver->m_PrevSolution = 0.0;
  m_pPlaneSolver->m_ClosestHaveBeenToCurrent = 3.4028235e38;
  m_pPlaneSolver->m_TimeLastProgress = 3.4028235e38;
  m_pPlaneSolver->m_fCannotSolveCurrent = false;
}

//------------------------------------------------------------------------------
// Address: 0x100584B0
// Name: public: virtual float CAI_ProxyMovementSink::CalcYawSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_ProxyMovementSink::CalcYawSpeed(CAI_ProxyMovementSink *this)
{
  double result; // st7

  if ( this->m_pProxied == nullptr )
    return -1.0;
  result = ((double (__thiscall *)(IAI_MovementSink *))this->m_pProxied->CalcYawSpeed)(a1: this->m_pProxied);
  if ( result == -1.0 )
    return -1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100584E0
// Name: public: virtual bool CAI_ProxyMovementSink::OnCalcBaseMove(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ProxyMovementSink::OnCalcBaseMove(
        CAI_ProxyMovementSink *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  return this->m_pProxied != nullptr
      && ((unsigned __int8 (__stdcall *)(AILocalMoveGoal_t *, _DWORD, AIMoveResult_t *))this->m_pProxied->OnCalcBaseMove)(
           a1: pMoveGoal,
           a2: LODWORD(distClear),
           a3: pResult) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10058520
// Name: public: virtual bool CAI_ProxyMovementSink::OnObstructionPreSteer(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ProxyMovementSink::OnObstructionPreSteer(
        CAI_ProxyMovementSink *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  return this->m_pProxied != nullptr
      && ((unsigned __int8 (__stdcall *)(AILocalMoveGoal_t *, _DWORD, AIMoveResult_t *))this->m_pProxied->OnObstructionPreSteer)(
           a1: pMoveGoal,
           a2: LODWORD(distClear),
           a3: pResult) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10058560
// Name: public: virtual bool CAI_ProxyMovementSink::OnFailedSteer(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ProxyMovementSink::OnFailedSteer(
        CAI_ProxyMovementSink *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  return this->m_pProxied != nullptr
      && ((unsigned __int8 (__stdcall *)(AILocalMoveGoal_t *, _DWORD, AIMoveResult_t *))this->m_pProxied->OnFailedSteer)(
           a1: pMoveGoal,
           a2: LODWORD(distClear),
           a3: pResult) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100585A0
// Name: public: virtual bool CAI_ProxyMovementSink::OnFailedLocalNavigation(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ProxyMovementSink::OnFailedLocalNavigation(
        CAI_ProxyMovementSink *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  return this->m_pProxied != nullptr
      && ((unsigned __int8 (__stdcall *)(AILocalMoveGoal_t *, _DWORD, AIMoveResult_t *))this->m_pProxied->OnFailedLocalNavigation)(
           a1: pMoveGoal,
           a2: LODWORD(distClear),
           a3: pResult) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100585E0
// Name: public: virtual bool CAI_ProxyMovementSink::OnInsufficientStopDist(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ProxyMovementSink::OnInsufficientStopDist(
        CAI_ProxyMovementSink *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  return this->m_pProxied != nullptr
      && ((unsigned __int8 (__stdcall *)(AILocalMoveGoal_t *, _DWORD, AIMoveResult_t *))this->m_pProxied->OnInsufficientStopDist)(
           a1: pMoveGoal,
           a2: LODWORD(distClear),
           a3: pResult) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10058620
// Name: public: virtual bool CAI_ProxyMovementSink::OnMoveStalled(struct AILocalMoveGoal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ProxyMovementSink::OnMoveStalled(CAI_ProxyMovementSink *this, const AILocalMoveGoal_t *move)
{
  return this->m_pProxied != nullptr && this->m_pProxied->OnMoveStalled(this: this->m_pProxied, a2: move);
}

//------------------------------------------------------------------------------
// Address: 0x10058650
// Name: public: virtual bool CAI_ProxyMovementSink::OnMoveExecuteFailed(struct AILocalMoveGoal_t const __near &,struct AIMoveTrace_t const __near &,enum AIMotorMoveResult_t,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ProxyMovementSink::OnMoveExecuteFailed(
        CAI_ProxyMovementSink *this,
        const AILocalMoveGoal_t *move,
        const AIMoveTrace_t *trace,
        AIMotorMoveResult_t fMotorResult,
        AIMoveResult_t *pResult)
{
  return this->m_pProxied != nullptr
      && this->m_pProxied->OnMoveExecuteFailed(
           this: this->m_pProxied,
           a2: move,
           a3: trace,
           a4: fMotorResult,
           a5: pResult);
}

//------------------------------------------------------------------------------
// Address: 0x10058690
// Name: public: virtual bool CAI_ProxyMovementSink::OnMoveBlocked(enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ProxyMovementSink::OnMoveBlocked(CAI_ProxyMovementSink *this, AIMoveResult_t *pResult)
{
  return this->m_pProxied != nullptr && this->m_pProxied->OnMoveBlocked(this: this->m_pProxied, a2: pResult);
}

//------------------------------------------------------------------------------
// Address: 0x100586C0
// Name: public: CAI_LocalNavigator::CAI_LocalNavigator(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_LocalNavigator *__thiscall CAI_LocalNavigator::CAI_LocalNavigator(CAI_LocalNavigator *this, CAI_BaseNPC *pOuter)
{
  AILocalMoveGoal_t *p_m_LastMoveGoal; // edi
  CAI_PlaneSolver *v4; // eax
  CAI_PlaneSolver *v5; // eax

  p_m_LastMoveGoal = &this->m_LastMoveGoal;
  this->m_pOuter = pOuter;
  this->CAI_ProxyMovementSink::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_ProxyMovementSink_vtbl *)&CAI_ProxyMovementSink::`vftable';
  this->m_pProxied = nullptr;
  this->CAI_Component::__vftable = (CAI_LocalNavigator_vtbl *)&CAI_LocalNavigator::`vftable'{for `CAI_Component'};
  this->CAI_ProxyMovementSink::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_ProxyMovementSink_vtbl *)&CAI_LocalNavigator::`vftable'{for `CAI_ProxyMovementSink'};
  memset(dst: (int)&this->m_LastMoveGoal.directTrace, value: nullptr, count: sizeof(this->m_LastMoveGoal.directTrace));
  memset(dst: (int)&p_m_LastMoveGoal->thinkTrace, value: nullptr, count: sizeof(p_m_LastMoveGoal->thinkTrace));
  memset(dst: (int)p_m_LastMoveGoal, value: nullptr, count: sizeof(AILocalMoveGoal_t));
  this->m_FullDirectTimer.m_next = -1.0;
  this->m_pMoveProbe = nullptr;
  v4 = (CAI_PlaneSolver *)operator new(nSize: 0x60u);
  if ( v4 != nullptr )
    v5 = CAI_PlaneSolver::CAI_PlaneSolver(this: v4, pNpc: pOuter);
  else
    v5 = nullptr;
  this->m_pPlaneSolver = v5;
  this->m_fLastWasClear = false;
  memset(dst: (int)p_m_LastMoveGoal, value: nullptr, count: sizeof(AILocalMoveGoal_t));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10058770
// Name: protected: bool CAI_LocalNavigator::MoveCalcDirect(struct AILocalMoveGoal_t __near *,bool,float __near *,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CAI_LocalNavigator::MoveCalcDirect@<al>(
        CAI_LocalNavigator *this@<ecx>,
        int a2@<edi>,
        AILocalMoveGoal_t *pMoveGoal,
        bool bOnlyCurThink,
        float *pDistClear,
        AIMoveResult_t *pResult)
{
  float speed; // xmm0_4
  CAI_Motor *m_pMotor; // ebx
  double v10; // st7
  float maxDist; // xmm2_4
  double v12; // xmm0_8
  bool v13; // zf
  double v15; // st7
  char v16; // bl
  CAI_BaseNPC *m_pOuter; // eax
  Navigation_t navType; // edx
  float v19; // xmm3_4
  float v20; // xmm1_4
  CBaseEntity *pMoveTarget; // ebx
  bool v22; // bl
  const Vector *v23; // eax
  CBaseEntity *pObstruction; // ecx
  Vector *v25; // eax
  const Vector *v26; // eax
  CAI_BaseNPC *v27; // eax
  float z; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  CAI_BaseNPC *v32; // ebx
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  const Vector *v34; // eax
  float v35; // xmm0_4
  bool v36; // bl
  Vector *p_target; // [esp-8h] [ebp-68h]
  int v38; // [esp-4h] [ebp-64h]
  int v39; // [esp+0h] [ebp-60h]
  int pctToCheckStandPositions; // [esp+4h] [ebp-5Ch]
  Vector v42; // [esp+1Ch] [ebp-44h] BYREF
  Vector v43; // [esp+28h] [ebp-38h] BYREF
  Vector target; // [esp+34h] [ebp-2Ch] BYREF
  Vector testPos; // [esp+40h] [ebp-20h] BYREF
  float checkStepDist; // [esp+4Ch] [ebp-14h]
  float x; // [esp+50h] [ebp-10h]
  float probeDist; // [esp+54h] [ebp-Ch]
  float checkDist; // [esp+58h] [ebp-8h]
  bool bRetVal; // [esp+5Fh] [ebp-1h]
  float bExpectingArrival; // [esp+68h] [ebp+8h]
  float bExpectingArrivala; // [esp+68h] [ebp+8h]
  char bExpectingArrival_3; // [esp+6Bh] [ebp+Bh]
  bool bTraceClear; // [esp+6Fh] [ebp+Fh]

  speed = pMoveGoal->speed;
  bRetVal = false;
  if ( speed == 0.0 )
  {
    *pResult = AIMR_ILLEGAL;
    goto LABEL_58;
  }
  m_pMotor = this->m_pOuter->m_pMotor;
  bExpectingArrival = m_pMotor->MinCheckDist(this: m_pMotor);
  v10 = CAI_PlaneSolver::CalcProbeDist(this: this->m_pPlaneSolver, speed: pMoveGoal->speed);
  probeDist = v10;
  if ( bExpectingArrival <= v10 )
    maxDist = probeDist;
  else
    maxDist = bExpectingArrival;
  v12 = probeDist * 0.5;
  checkDist = maxDist;
  if ( v12 < 16.0 )
    v12 = 16.0;
  v13 = (pMoveGoal->flags & 5) == 0;
  checkStepDist = v12;
  if ( !v13 && pMoveGoal->maxDist <= maxDist )
  {
    maxDist = pMoveGoal->maxDist;
    checkDist = maxDist;
  }
  if ( maxDist <= 0.0 )
  {
    *pResult = AIMR_OK;
    return 1;
  }
  v15 = CAI_Motor::CalcIntervalMove(this: m_pMotor);
  probeDist = v15;
  if ( v15 < checkDist )
  {
    bExpectingArrival_3 = 0;
    v16 = 0;
  }
  else
  {
    v16 = 1;
    bExpectingArrival_3 = 1;
  }
  if ( (float)(gpGlobals->curtime - this->m_FullDirectTimer.m_next) <= -0.001
    && (!this->m_fLastWasClear
     || fabs(pMoveGoal->target.x - this->m_LastMoveGoal.target.x) > 0.1
     || fabs(pMoveGoal->target.y - this->m_LastMoveGoal.target.y) > 0.1
     || fabs(pMoveGoal->target.z - this->m_LastMoveGoal.target.z) > 0.1
     || !VectorsAreEqual(src1: &pMoveGoal->dir, src2: &this->m_LastMoveGoal.dir, tolerance: 0.1)
     || v16 != 0) )
  {
    this->m_FullDirectTimer.m_next = -1.0;
  }
  if ( bOnlyCurThink )
    this->m_FullDirectTimer.m_next = gpGlobals->curtime + TIME_DELAY_FULL_DIRECT_PROBE[AIStrongOpt()];
  bTraceClear = true;
  if ( v16 == 0 )
  {
    m_pOuter = this->m_pOuter;
    navType = pMoveGoal->navType;
    v19 = m_pOuter->m_vecOrigin.m_Value.x + (float)(pMoveGoal->dir.x * probeDist);
    v20 = m_pOuter->m_vecOrigin.m_Value.z + (float)(pMoveGoal->dir.z * probeDist);
    testPos.y = m_pOuter->m_vecOrigin.m_Value.y + (float)(pMoveGoal->dir.y * probeDist);
    pMoveTarget = pMoveGoal->pMoveTarget;
    testPos.x = v19;
    testPos.z = v20;
    v22 = CAI_MoveProbe::MoveLimit(
            this: this->m_pMoveProbe,
            navType,
            vecStart: &m_pOuter->m_vecOrigin.m_Value,
            vecEnd: &testPos,
            collisionMask: m_pOuter->m_nAITraceMask,
            pTarget: pMoveTarget,
            pctToCheckStandPositions: 100.0,
            flags: navType == NAV_GROUND,
            pTrace: &pMoveGoal->directTrace);
    bTraceClear = v22;
    if ( !v22 )
      pMoveGoal->directTrace.flDistObstructed = (float)(checkDist - probeDist) + pMoveGoal->directTrace.flDistObstructed;
    if ( ai_debug_directnavprobe.m_pParent != nullptr && ai_debug_directnavprobe.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( v22 )
      {
        x = testPos.x;
        probeDist = testPos.y;
        target.z = CAI_Component::WorldSpaceCenter(this, result: &v42)->z;
        pctToCheckStandPositions = 0;
        v39 = 255;
        target.x = x;
        v38 = 0;
        target.y = probeDist;
        p_target = &target;
        v25 = &v43;
      }
      else
      {
        DevMsg(
          pAI: this->m_pOuter,
          pszFormat: "Close obstruction %f\n",
          (float)(checkDist - pMoveGoal->directTrace.flDistObstructed));
        probeDist = testPos.x;
        x = testPos.y;
        target.z = CAI_Component::WorldSpaceCenter(this, result: &v43)->z;
        target.x = probeDist;
        target.y = x;
        v23 = CAI_Component::WorldSpaceCenter(this, result: &v42);
        NDebugOverlay::Line(origin: v23, &target, r: 255, g: 0, b: 0, noDepthTest: false, duration: 0.1);
        pObstruction = pMoveGoal->directTrace.pObstruction;
        if ( pObstruction == nullptr )
          goto LABEL_35;
        pctToCheckStandPositions = 255;
        v39 = 0;
        v38 = 255;
        p_target = (Vector *)((int (*)(void))pObstruction->WorldSpaceCenter)();
        v25 = &v42;
      }
      v26 = CAI_Component::WorldSpaceCenter(this, result: v25);
      NDebugOverlay::Line(
        origin: v26,
        target: p_target,
        r: v38,
        g: v39,
        b: pctToCheckStandPositions,
        noDepthTest: false,
        duration: 0.1);
    }
LABEL_35:
    AIMoveTrace_t::operator=(this: &pMoveGoal->thinkTrace, __that: &pMoveGoal->directTrace);
    if ( !v22 )
      goto LABEL_49;
  }
  if ( (float)(gpGlobals->curtime - this->m_FullDirectTimer.m_next) <= -0.001 )
  {
    if ( ai_debug_directnavprobe.m_pParent != nullptr && ai_debug_directnavprobe.m_pParent->m_Value.m_nValue != 0 )
      DevMsg(pAI: this->m_pOuter, pszFormat: "No obstruction (Near probe only)\n");
  }
  else
  {
    v27 = this->m_pOuter;
    z = pMoveGoal->dir.z;
    v29 = v27->m_vecOrigin.m_Value.y + (float)(pMoveGoal->dir.y * checkDist);
    v30 = v27->m_vecOrigin.m_Value.z;
    testPos.x = (float)(pMoveGoal->dir.x * checkDist) + v27->m_vecOrigin.m_Value.x;
    v31 = (float)(checkStepDist / checkDist) * 100.0;
    testPos.y = v29;
    testPos.z = v30 + (float)(z * checkDist);
    if ( v31 > 100.0 )
      v31 = 100.0;
    bTraceClear = CAI_MoveProbe::MoveLimit(
                    this: this->m_pMoveProbe,
                    navType: pMoveGoal->navType,
                    vecStart: &v27->m_vecOrigin.m_Value,
                    vecEnd: &testPos,
                    collisionMask: v27->m_nAITraceMask,
                    pTarget: pMoveGoal->pMoveTarget,
                    pctToCheckStandPositions: v31,
                    flags: pMoveGoal->navType == NAV_GROUND,
                    pTrace: &pMoveGoal->directTrace);
    if ( bExpectingArrival_3 != 0 )
      AIMoveTrace_t::operator=(this: &pMoveGoal->thinkTrace, __that: &pMoveGoal->directTrace);
    if ( ai_debug_directnavprobe.m_pParent != nullptr && ai_debug_directnavprobe.m_pParent->m_Value.m_nValue != 0 )
    {
      v32 = this->m_pOuter;
      EyePosition = v32->EyePosition;
      bExpectingArrivala = testPos.x;
      checkStepDist = testPos.y;
      target.z = *(float *)(((int (__thiscall *)(CAI_BaseNPC *, Vector *, int))EyePosition)(a1: v32, a2: &v42, a3: a2)
                          + 8);
      target.x = bExpectingArrivala;
      target.y = checkStepDist;
      v34 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))v32->EyePosition)(a1: v32);
      if ( bTraceClear )
      {
        NDebugOverlay::Line(origin: v34, target: &v43, r: (int)&target, g: 0, b: 255, noDepthTest: false, duration: 0.0);
        DevMsg(pAI: this->m_pOuter, pszFormat: "No obstruction\n");
      }
      else
      {
        NDebugOverlay::Line(origin: v34, target: &v43, r: (int)&target, g: 255, b: 0, noDepthTest: false, duration: 0.0);
        DevMsg(
          pAI: this->m_pOuter,
          pszFormat: "Obstruction %f\n",
          (float)(checkDist - pMoveGoal->directTrace.flDistObstructed));
      }
    }
  }
LABEL_49:
  v35 = checkDist - pMoveGoal->directTrace.flDistObstructed;
  pMoveGoal->bHasTraced = true;
  if ( v35 < 0.001 )
    v35 = 0.0;
  if ( bTraceClear )
  {
    *pResult = AIMR_OK;
    this->m_fLastWasClear = true;
LABEL_58:
    bRetVal = true;
    goto LABEL_59;
  }
  if ( (pMoveGoal->flags & 5) != 0 && v35 > pMoveGoal->maxDist )
  {
    *pResult = AIMR_OK;
    this->m_fLastWasClear = true;
    goto LABEL_58;
  }
  *pDistClear = v35;
  this->m_fLastWasClear = false;
LABEL_59:
  AILocalMoveGoal_t::operator=(this: &this->m_LastMoveGoal, __that: pMoveGoal);
  v36 = bRetVal;
  if ( bRetVal && (float)(gpGlobals->curtime - this->m_FullDirectTimer.m_next) > -0.001 )
    this->m_FullDirectTimer.m_next = gpGlobals->curtime + TIME_DELAY_FULL_DIRECT_PROBE[AIStrongOpt()];
  return v36;
}

//------------------------------------------------------------------------------
// Address: 0x10058E10
// Name: protected: bool CAI_LocalNavigator::MoveCalcSteer(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_LocalNavigator::MoveCalcSteer(
        CAI_LocalNavigator *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  float x; // xmm0_4
  float v7; // xmm1_4
  float y; // xmm2_4
  double v9; // st7
  float z; // xmm0_4
  Vector moveSolution; // [esp+10h] [ebp-Ch] BYREF
  float probeDist; // [esp+24h] [ebp+8h]

  if ( (pMoveGoal->flags & 8) != 0
    || ai_no_steer.m_pParent != nullptr && ai_no_steer.m_pParent->m_Value.m_nValue != 0
    || (this->m_pOuter->m_spawnflags.m_Value & 0x10) != 0
    || !CAI_PlaneSolver::Solve(this: this->m_pPlaneSolver, goal: pMoveGoal, distClear, pSolution: &moveSolution) )
  {
    return 0;
  }
  x = pMoveGoal->dir.x;
  v7 = moveSolution.x;
  y = moveSolution.y;
  if ( x != moveSolution.x || pMoveGoal->dir.y != moveSolution.y || pMoveGoal->dir.z != moveSolution.z )
  {
    if ( (float)((float)(pMoveGoal->dir.y * moveSolution.y) + (float)(x * moveSolution.x)) > 0.96600002 )
    {
      v9 = CAI_PlaneSolver::CalcProbeDist(this: this->m_pPlaneSolver, speed: pMoveGoal->speed);
      if ( v9 * 0.33333 > pMoveGoal->maxDist )
      {
        probeDist = v9;
        if ( distClear > probeDist * 0.6666 )
        {
          *pResult = AIMR_OK;
          return 1;
        }
      }
      y = moveSolution.y;
      v7 = moveSolution.x;
    }
    z = moveSolution.z;
    pMoveGoal->dir.y = y;
    pMoveGoal->dir.z = z;
    pMoveGoal->dir.x = v7;
    pMoveGoal->facing.x = v7;
    pMoveGoal->facing.y = pMoveGoal->dir.y;
    pMoveGoal->facing.z = pMoveGoal->dir.z;
  }
  *pResult = AIMR_OK;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10058F70
// Name: protected: enum AIMoveResult_t CAI_LocalNavigator::MoveCalcRaw(struct AILocalMoveGoal_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
AIMoveResult_t __thiscall CAI_LocalNavigator::MoveCalcRaw(
        CAI_LocalNavigator *this,
        AILocalMoveGoal_t *pMoveGoal,
        int bOnlyCurThink)
{
  AILocalMoveGoal_t *v3; // edi
  bool v5; // al
  AIMoveResult_t result; // eax
  double v7; // st6
  AIMoveResult_t v8; // [esp+54h] [ebp-4h] BYREF

  v3 = pMoveGoal;
  v8 = AIMR_OK;
  HIBYTE(bOnlyCurThink) = CAI_LocalNavigator::MoveCalcDirect(
                            this,
                            a2: (int)pMoveGoal,
                            pMoveGoal,
                            bOnlyCurThink,
                            pDistClear: (float *)&pMoveGoal,
                            pResult: &v8);
  if ( ((unsigned __int8 (__thiscall *)(CAI_ProxyMovementSink *, AILocalMoveGoal_t *, AILocalMoveGoal_t *, AIMoveResult_t *))this->OnCalcBaseMove)(
         a1: &this->CAI_ProxyMovementSink,
         a2: v3,
         a3: pMoveGoal,
         a4: &v8) != 0 )
    return v8;
  v5 = (v3->flags & 8) == 0
    && (HIBYTE(bOnlyCurThink) == 0
     || this->m_pPlaneSolver->m_Obstacles.m_Size != 0
     || CAI_PlaneSolver::s_GlobalObstacles.m_ElementCount != 0);
  if ( HIBYTE(bOnlyCurThink) != 0 )
  {
    if ( !v5 )
      return v8;
  }
  else
  {
    if ( !v5 )
      goto LABEL_14;
    if ( ((unsigned __int8 (__thiscall *)(CAI_ProxyMovementSink *, AILocalMoveGoal_t *, AILocalMoveGoal_t *, AIMoveResult_t *))this->OnObstructionPreSteer)(
           a1: &this->CAI_ProxyMovementSink,
           a2: v3,
           a3: pMoveGoal,
           a4: &v8) != 0 )
      return v8;
  }
  if ( CAI_LocalNavigator::MoveCalcSteer(this, pMoveGoal: v3, distClear: *(float *)&pMoveGoal, pResult: &v8) != 0 )
    return v8;
LABEL_14:
  if ( ((unsigned __int8 (__thiscall *)(CAI_ProxyMovementSink *, AILocalMoveGoal_t *, AILocalMoveGoal_t *, AIMoveResult_t *))this->OnFailedSteer)(
         a1: &this->CAI_ProxyMovementSink,
         a2: v3,
         a3: pMoveGoal,
         a4: &v8) != 0 )
    return v8;
  if ( ((unsigned __int8 (__thiscall *)(CAI_ProxyMovementSink *, AILocalMoveGoal_t *, AILocalMoveGoal_t *, AIMoveResult_t *))this->OnFailedLocalNavigation)(
         a1: &this->CAI_ProxyMovementSink,
         a2: v3,
         a3: pMoveGoal,
         a4: &v8) != 0 )
    return v8;
  v7 = ((double (__stdcall *)(int))this->m_pOuter->m_pMotor->MinStoppingDist)(a1: 1092616192);
  if ( v7 > *(float *)&pMoveGoal
    && (((unsigned __int8 (__thiscall *)(CAI_ProxyMovementSink *, AILocalMoveGoal_t *, AILocalMoveGoal_t *, AIMoveResult_t *))this->OnInsufficientStopDist)(
          a1: &this->CAI_ProxyMovementSink,
          a2: v3,
          a3: pMoveGoal,
          a4: &v8) != 0
     || CAI_LocalNavigator::MoveCalcStop(this, pMoveGoal: v3, distClear: *(float *)&pMoveGoal, pResult: &v8) != 0) )
  {
    return v8;
  }
  if ( *(float *)&pMoveGoal > v3->curExpectedDist )
    return AIMR_OK;
  result = v3->directTrace.fStatus;
  if ( result >= AIMR_OK )
    return AIMR_ILLEGAL;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059110
// Name: public: enum AIMoveResult_t CAI_LocalNavigator::MoveCalc(struct AILocalMoveGoal_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
AIMoveResult_t __thiscall CAI_LocalNavigator::MoveCalc(
        CAI_LocalNavigator *this,
        AILocalMoveGoal_t *pMoveGoal,
        int bPreviouslyValidated)
{
  AIMoveResult_t result; // eax
  float maxDist; // xmm0_4
  CAI_BaseNPC *m_pOuter; // eax
  Vector *p_facing; // esi
  long double v8; // st7
  double v9; // st7
  Vector v10; // [esp+1Ch] [ebp-14h] BYREF
  float deltaYaw; // [esp+28h] [ebp-8h]
  float interval; // [esp+2Ch] [ebp-4h]
  float currentYaw; // [esp+38h] [ebp+8h]
  float currentYawa; // [esp+38h] [ebp+8h]
  float goalYaw; // [esp+3Ch] [ebp+Ch]

  if ( (_BYTE)bPreviouslyValidated == 0
    || this->m_pPlaneSolver->m_Obstacles.m_Size != 0
    || (LOBYTE(bPreviouslyValidated) = 1, CAI_PlaneSolver::s_GlobalObstacles.m_ElementCount != 0) )
  {
    LOBYTE(bPreviouslyValidated) = 0;
  }
  result = CAI_LocalNavigator::MoveCalcRaw(this, pMoveGoal, bOnlyCurThink: bPreviouslyValidated);
  maxDist = pMoveGoal->maxDist;
  if ( pMoveGoal->curExpectedDist > maxDist )
    pMoveGoal->curExpectedDist = maxDist;
  if ( result == AIMR_OK )
  {
    m_pOuter = this->m_pOuter;
    interval = m_pOuter->m_pMotor->m_flMoveInterval;
    p_facing = &pMoveGoal->facing;
    currentYaw = (float)(unsigned __int16)(int)(float)(m_pOuter->m_angRotation.m_Value.y * 182.04445) * 0.0054931641;
    goalYaw = UTIL_VecToYaw(vec: p_facing);
    v8 = fabs(AngleDiff(destAngle: goalYaw, srcAngle: currentYaw));
    deltaYaw = v8;
    if ( v8 > 15.0 )
    {
      v9 = AI_ClampYaw(yawSpeedPerSec: deltaYaw * 4.0, current: currentYaw, target: goalYaw, time: interval);
      if ( v9 != goalYaw )
      {
        currentYawa = v9;
        *p_facing = *UTIL_YawToVector(result: &v10, yaw: currentYawa);
      }
    }
    return AIMR_OK;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FC7A0
// Name: CAI_LocalNavigator_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_LocalNavigator_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_LocalNavigator>(__formal: nullptr);
  CAI_LocalNavigator_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059270
// Name: struct datamap_t __near * DataMapInit<class CAI_LocalNavigator>(class CAI_LocalNavigator __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_LocalNavigator>()
{
  if ( (_S2_19 & 1) == 0 )
  {
    _S2_19 |= 1u;
    nameHolder_47.m_pszBase = "CAI_LocalNavigator";
    nameHolder_47.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_47.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_47.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_47.m_Names.m_Size = 0;
    nameHolder_47.m_Names.m_pElements = nullptr;
    nameHolder_47.m_nLenBase = 18;
    atexit(func: DataMapInit_CAI_LocalNavigator__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_LocalNavigator::m_DataMap.baseMap = nullptr;
  CAI_LocalNavigator::m_DataMap.dataNumFields = 1;
  CAI_LocalNavigator::m_DataMap.dataDesc = dataDesc_468;
  return &CAI_LocalNavigator::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10059350
// Name: struct datamap_t __near * DataMapInit<class CAI_LookTarget>(class CAI_LookTarget __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_LookTarget>()
{
  if ( (_S2_20 & 1) == 0 )
  {
    _S2_20 |= 1u;
    nameHolder_48.m_pszBase = "CAI_LookTarget";
    nameHolder_48.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_48.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_48.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_48.m_Names.m_Size = 0;
    nameHolder_48.m_Names.m_pElements = nullptr;
    nameHolder_48.m_nLenBase = 14;
    atexit(func: DataMapInit_CAI_LookTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_LookTarget::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CAI_LookTarget::m_DataMap.dataNumFields = 5;
  CAI_LookTarget::m_DataMap.dataDesc = &dataDesc_46[1];
  return &CAI_LookTarget::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FC7B0
// Name: _dynamic_initializer_for__ai_no_steer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_no_steer__()
{
  ConVar::ConVar(this: &ai_no_steer, pName: "ai_no_steer", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_no_steer__);
}
