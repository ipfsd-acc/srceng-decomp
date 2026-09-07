// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_planesolver.cpp
// Functions: 18
// ============================================================

#include "game\server\ai_planesolver.h"

//------------------------------------------------------------------------------
// Address: 0x10077770
// Name: private: float CAI_PlaneSolver::AdjustRegulationWeight(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CAI_PlaneSolver::AdjustRegulationWeight@<st0>(
        CAI_PlaneSolver *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseEntity *pEntity,
        float weight)
{
  CAI_Motor *m_pMotor; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  CBaseEntity *m_pOuter; // eax
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v20; // [esp-30h] [ebp-3Ch]
  float v21; // [esp-20h] [ebp-2Ch]
  float v22; // [esp-8h] [ebp-14h]

  if ( ((int (__thiscall *)(CBaseEntity *, int, int))pEntity->MyNPCPointer)(a1: pEntity, a2, a3) != 0 )
  {
    m_pMotor = this->m_pNpc->m_pMotor;
    x = m_pMotor->m_vecVelocity.x;
    y = m_pMotor->m_vecVelocity.y;
    m_pOuter = pEntity[3].m_Collision.m_pOuter;
    v10 = *(float *)&m_pOuter->m_Network.m_PVSInfo.m_nHeadNode;
    v11 = *(float *)&m_pOuter->m_Network.m_PVSInfo.m_pClusters;
    v20 = fsqrt((float)(y * y) + (float)(x * x));
    if ( v20 == 0.0 )
    {
      v22 = 0.0;
      v12 = 0.0;
    }
    else
    {
      v12 = (float)(1.0 / v20) * x;
      v22 = y * (float)(1.0 / v20);
    }
    v13 = fsqrt((float)(v11 * v11) + (float)(v10 * v10));
    v21 = v13;
    if ( v13 == 0.0 )
    {
      v16 = 0.0;
      v15 = 0.0;
    }
    else
    {
      v14 = 1.0 / v13;
      v15 = (float)(1.0 / v13) * v10;
      v16 = v14 * v11;
    }
    v17 = (float)(v16 * v22) + (float)(v15 * v12);
    if ( v21 > 0.0 && v17 > 0.0 && v21 >= v20 * 0.9 )
    {
      if ( v17 > 0.86 )
        return 0.0;
      if ( v17 > 0.7 )
        return (float)((float)(weight * weight) * weight);
      return (float)(weight * weight);
    }
  }
  return weight;
}

//------------------------------------------------------------------------------
// Address: 0x10077920
// Name: private: void CAI_PlaneSolver::VisualizeSolution(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlaneSolver::VisualizeSolution(
        CAI_PlaneSolver *this,
        const Vector *vecGoal,
        const Vector *vecActual)
{
  CAI_BaseNPC *m_pNpc; // ecx
  float x; // xmm2_4
  float y; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  Vector actualPt; // [esp+4h] [ebp-24h] BYREF
  Vector goalPt; // [esp+10h] [ebp-18h] BYREF
  Vector centroid; // [esp+1Ch] [ebp-Ch] BYREF

  m_pNpc = this->m_pNpc;
  if ( (m_pNpc->m_debugOverlays & 0x4000000) != 0 )
  {
    centroid = *m_pNpc->WorldSpaceCenter(this: m_pNpc);
    x = vecGoal->x;
    y = vecGoal->y;
    v6 = (float)(vecActual->y * 20.0) + centroid.y;
    goalPt.z = (float)(vecGoal->z * 20.0) + centroid.z;
    v7 = vecActual->x;
    actualPt.y = v6;
    v8 = (float)(vecActual->z * 20.0) + centroid.z;
    goalPt.x = (float)(x * 20.0) + centroid.x;
    goalPt.y = (float)(y * 20.0) + centroid.y;
    actualPt.x = (float)(v7 * 20.0) + centroid.x;
    actualPt.z = v8;
    NDebugOverlay::Line(origin: &centroid, target: &goalPt, r: 255, g: 255, b: 255, noDepthTest: true, duration: 0.1);
    NDebugOverlay::Line(origin: &centroid, target: &actualPt, r: 255, g: 255, b: 0, noDepthTest: true, duration: 0.1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077A30
// Name: public: float CAI_PlaneSolver::CalcProbeDist(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_PlaneSolver::CalcProbeDist(CAI_PlaneSolver *this, float speed)
{
  if ( NAI_Hull::Width(id: this->m_pNpc->m_pMoveProbe->m_pOuter->m_eHull) > speed )
    return NAI_Hull::Width(id: this->m_pNpc->m_pMoveProbe->m_pOuter->m_eHull);
  if ( speed <= MAX_PROBE_DIST[AIStrongOpt()] )
    return speed;
  return MAX_PROBE_DIST[AIStrongOpt()];
}

//------------------------------------------------------------------------------
// Address: 0x10077B30
// Name: private: bool CAI_PlaneSolver::DetectUnsolvable(struct AILocalMoveGoal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_PlaneSolver::DetectUnsolvable(CAI_PlaneSolver *this, const AILocalMoveGoal_t *goal)
{
  float v2; // xmm0_4

  v2 = fsqrt(
         (float)((float)(goal->target.y - this->m_pNpc->m_vecOrigin.m_Value.y)
               * (float)(goal->target.y - this->m_pNpc->m_vecOrigin.m_Value.y))
       + (float)((float)(goal->target.x - this->m_pNpc->m_vecOrigin.m_Value.x)
               * (float)(goal->target.x - this->m_pNpc->m_vecOrigin.m_Value.x)));
  if ( goal->target.x != this->m_PrevTarget.x
    || goal->target.y != this->m_PrevTarget.y
    || goal->target.z != this->m_PrevTarget.z )
  {
    this->m_TimeLastProgress = gpGlobals->curtime;
    this->m_ClosestHaveBeenToCurrent = v2;
    this->m_fCannotSolveCurrent = false;
    return 0;
  }
  if ( this->m_fCannotSolveCurrent )
    return 1;
  if ( (float)(this->m_ClosestHaveBeenToCurrent - v2) <= 0.0 )
  {
    if ( (float)(gpGlobals->curtime - this->m_TimeLastProgress) <= 0.75 )
      return 0;
    this->m_fCannotSolveCurrent = true;
    return 1;
  }
  else
  {
    this->m_TimeLastProgress = gpGlobals->curtime;
    this->m_ClosestHaveBeenToCurrent = v2;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077C40
// Name: private: void CAI_PlaneSolver::AdjustSolutionForFliers(struct AILocalMoveGoal_t const __near &,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlaneSolver::AdjustSolutionForFliers(
        CAI_PlaneSolver *this,
        const AILocalMoveGoal_t *goal,
        float flSolutionYaw,
        Vector *pSolution)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float z; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  Vector vecDir; // [esp+0h] [ebp-Ch] BYREF

  v4 = goal->target.y - this->m_pNpc->m_vecOrigin.m_Value.y;
  v5 = goal->target.z - this->m_pNpc->m_vecOrigin.m_Value.z;
  vecDir.x = goal->target.x - this->m_pNpc->m_vecOrigin.m_Value.x;
  vecDir.y = v4;
  vecDir.z = v5;
  VectorNormalize(vec: &vecDir);
  z = vecDir.z;
  v7 = fsqrt((float)(vecDir.y * vecDir.y) + (float)(vecDir.x * vecDir.x));
  pSolution->x = pSolution->x * v7;
  pSolution->y = pSolution->y * v7;
  pSolution->z = z;
  if ( z < (float)(v7 * -0.1) )
  {
    if ( COERCE_FLOAT(LODWORD(v7) ^ _mask__NegFloat_) >= z || COERCE_FLOAT(LODWORD(z) & _mask__AbsFloat_) < 0.001 )
      v8 = 0.0;
    else
      v8 = (float)((float)((float)(-1.0 / z) * v7) - 1.0) * 0.1;
  }
  else
  {
    v8 = 1.0;
  }
  pSolution->z = (float)(v8 * 5.0) + z;
  VectorNormalize(vec: pSolution);
}

//------------------------------------------------------------------------------
// Address: 0x10077D80
// Name: private: bool CAI_PlaneSolver::RunMoveSolver(struct AILocalMoveGoal_t const __near &,struct AIMoveTrace_t const __near &,float,bool,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_PlaneSolver::RunMoveSolver(
        CAI_PlaneSolver *this,
        const AILocalMoveGoal_t *goal,
        const AIMoveTrace_t *directTrace,
        float degreesPositiveArc,
        bool fDeterOscillation,
        Vector *pResult)
{
  float z; // xmm1_4
  CAI_BaseNPC *v9; // ecx
  const Vector *v10; // eax
  int v11; // edi
  double v12; // st7
  float v13; // xmm0_4
  float v14; // xmm0_4
  AIMoveResult_t fStatus; // eax
  unsigned int v16; // eax
  float m_PrevSolution; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float x; // xmm7_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  CAI_BaseNPC *m_pNpc; // esi
  AI_MoveSuggestion_t moveSuggestions[2]; // [esp+14h] [ebp-54h] BYREF
  Vector v31; // [esp+44h] [ebp-24h] BYREF
  Vector curVelocity; // [esp+50h] [ebp-18h] BYREF
  float v33; // [esp+5Ch] [ebp-Ch]
  float v34; // [esp+60h] [ebp-8h]
  AI_MoveSolution_t solution; // [esp+64h] [ebp-4h] BYREF
  char fNewTarget_3; // [esp+73h] [ebp+Bh]

  solution.dir = 0.0;
  if ( this->m_Solver.m_Regulations.m_Size <= 0 )
  {
    if ( goal->navType == NAV_FLY )
    {
      m_pNpc = this->m_pNpc;
      pResult->x = goal->target.x - this->m_pNpc->m_vecOrigin.m_Value.x;
      pResult->y = goal->target.y - m_pNpc->m_vecOrigin.m_Value.y;
      pResult->z = goal->target.z - m_pNpc->m_vecOrigin.m_Value.z;
      VectorNormalize(vec: pResult);
    }
    else
    {
      *pResult = goal->dir;
    }
    return 1;
  }
  else
  {
    if ( !this->m_fSolvedPrev
      || goal->target.x != this->m_PrevTarget.x
      || goal->target.y != this->m_PrevTarget.y
      || (z = goal->target.z, fNewTarget_3 = 0, z != this->m_PrevTarget.z) )
    {
      fNewTarget_3 = 1;
    }
    v9 = this->m_pNpc;
    if ( (this->m_pNpc->m_debugOverlays & 0x4000000) != 0 )
    {
      v10 = v9->WorldSpaceCenter(this: v9);
      CAI_MoveSolver::VisualizeRegulations(this: &this->m_Solver, origin: v10);
    }
    moveSuggestions[1].hObstacleEntity.m_Index = -1;
    moveSuggestions[0].flags = 0;
    moveSuggestions[1].flags = 0;
    moveSuggestions[0].arc.center = 0.0;
    moveSuggestions[0].arc.span = 0.0;
    moveSuggestions[1].type = AIMS_INVALID;
    moveSuggestions[1].weight = 0.0;
    moveSuggestions[1].arc.center = 0.0;
    moveSuggestions[1].arc.span = 0.0;
    v11 = 1;
    v12 = UTIL_VecToYaw(vec: &goal->dir);
    v34 = v12;
    v33 = v12;
    moveSuggestions[0].type = AIMST_MOVE;
    moveSuggestions[0].weight = 1.0;
    moveSuggestions[0].hObstacleEntity.m_Index = -1;
    if ( v12 >= 0.0 )
    {
      if ( v34 < 360.0 )
        v13 = v33;
      else
        v13 = v34 - 360.0;
    }
    else
    {
      v13 = v34 + 360.0;
    }
    moveSuggestions[0].arc.center = v13;
    v14 = degreesPositiveArc;
    if ( degreesPositiveArc >= 0.0 )
    {
      if ( degreesPositiveArc >= 360.0 )
        v14 = degreesPositiveArc - 360.0;
    }
    else
    {
      v14 = degreesPositiveArc + 360.0;
    }
    fStatus = directTrace->fStatus;
    moveSuggestions[0].arc.span = v14;
    v16 = fStatus != AIMR_BLOCKED_WORLD && fStatus == AIMR_BLOCKED_NPC;
    moveSuggestions[0].flags = v16;
    if ( fDeterOscillation && fNewTarget_3 == 0 )
    {
      m_PrevSolution = this->m_PrevSolution;
      moveSuggestions[1].weight = 1.0;
      v18 = m_PrevSolution - 180.0;
      v11 = 2;
      moveSuggestions[1].type = AIMST_OSCILLATION_DETERRANCE;
      moveSuggestions[1].hObstacleEntity.m_Index = -1;
      moveSuggestions[1].flags = 0;
      if ( v18 >= 0.0 )
      {
        if ( v18 >= 360.0 )
          v18 = v18 - 360.0;
      }
      else
      {
        v18 = v18 + 360.0;
      }
      moveSuggestions[1].arc.center = v18;
      moveSuggestions[1].arc.span = 180.0;
    }
    if ( CAI_MoveSolver::Solve(
           this: &this->m_Solver,
           pSuggestions: moveSuggestions,
           nSuggestions: v11,
           pResult: &solution) == 0 )
      return 0;
    *pResult = *UTIL_YawToVector(result: &v31, yaw: solution.dir);
    if ( goal->navType == NAV_FLY )
      CAI_PlaneSolver::AdjustSolutionForFliers(this, goal, flSolutionYaw: solution.dir, pSolution: pResult);
    if ( fNewTarget_3 != 0 )
      goto LABEL_36;
    v19 = solution.dir - this->m_PrevSolution;
    if ( v19 < 0.0 )
      v19 = v19 + 360.0;
    if ( v19 <= 165.0 || v19 >= 195.0 )
    {
LABEL_36:
      this->m_PrevSolution = solution.dir;
      this->m_PrevSolutionVector = *pResult;
      this->m_pNpc->GetSmoothedVelocity(this: this->m_pNpc, result: &curVelocity);
      if ( vec3_origin.x != curVelocity.x || vec3_origin.y != curVelocity.y || vec3_origin.z != curVelocity.z )
      {
        VectorNormalize(vec: &curVelocity);
        if ( fNewTarget_3 == 0 )
        {
          x = this->m_PrevSolutionVector.x;
          v21 = pResult->x * 0.80000001;
          v22 = pResult->y * 0.80000001;
          v23 = pResult->z * 0.80000001;
          v31.y = this->m_PrevSolutionVector.y * 0.1;
          v31.z = this->m_PrevSolutionVector.z * 0.1;
          v24 = (float)((float)(curVelocity.y * 0.1) + v31.y) + v22;
          v25 = (float)((float)(curVelocity.z * 0.1) + v31.z) + v23;
          pResult->x = (float)((float)(curVelocity.x * 0.1) + (float)(x * 0.1)) + v21;
          pResult->y = v24;
          pResult->z = v25;
          return 1;
        }
        v27 = (float)(curVelocity.y * 0.2) + (float)(pResult->y * 0.80000001);
        v28 = (float)(curVelocity.z * 0.2) + (float)(pResult->z * 0.80000001);
        pResult->x = (float)(curVelocity.x * 0.2) + (float)(pResult->x * 0.80000001);
        pResult->y = v27;
        pResult->z = v28;
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100781C0
// Name: public: static bool CAI_PlaneSolver::IsSegmentBlockedByGlobalObstacles(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CAI_PlaneSolver::IsSegmentBlockedByGlobalObstacles(const Vector *vecStart, const Vector *vecEnd)
{
  int m_Head; // esi
  float flDistSqr; // [esp+Ch] [ebp-4h]

  m_Head = CAI_PlaneSolver::s_GlobalObstacles.m_Head;
  if ( CAI_PlaneSolver::s_GlobalObstacles.m_Head == 0 )
    return 0;
  while ( 1 )
  {
    if ( *(_DWORD *)(m_Head + 16) != 0 )
    {
      flDistSqr = CalcDistanceSqrToLineSegment(
                    P: (const Vector *)m_Head,
                    vLineA: vecStart,
                    vLineB: vecEnd,
                    outT: nullptr);
      if ( (float)(*(float *)(m_Head + 12) * *(float *)(m_Head + 12)) > flDistSqr )
        break;
    }
    m_Head = *(_DWORD *)(m_Head + 28);
    if ( m_Head == 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10078480
// Name: public: CAI_PlaneSolver::CAI_PlaneSolver(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_PlaneSolver *__thiscall CAI_PlaneSolver::CAI_PlaneSolver(CAI_PlaneSolver *this, CAI_BaseNPC *pNpc)
{
  float v3; // xmm0_4
  AI_MoveSuggestion_t *v4; // eax

  this->m_pNpc = pNpc;
  this->m_PrevTarget.x = 3.4028235e38;
  this->m_PrevTarget.y = 3.4028235e38;
  this->m_PrevTarget.z = 3.4028235e38;
  this->m_fSolvedPrev = false;
  this->m_PrevSolution = 0.0;
  this->m_ClosestHaveBeenToCurrent = 3.4028235e38;
  this->m_TimeLastProgress = 3.4028235e38;
  this->m_fCannotSolveCurrent = false;
  v3 = PLANE_SOLVER_THINK_FREQUENCY[AIStrongOpt()] - 0.05;
  this->m_RefreshSamplesTimer.m_interval = v3;
  this->m_RefreshSamplesTimer.m_next = -1.0;
  this->m_Obstacles.m_Memory.m_pMemory = nullptr;
  this->m_Obstacles.m_Memory.m_nAllocationCount = 0;
  this->m_Obstacles.m_Memory.m_nGrowSize = 0;
  this->m_Obstacles.m_Size = 0;
  this->m_Obstacles.m_pElements = nullptr;
  this->m_Solver.m_Regulations.m_Memory.m_pMemory = nullptr;
  this->m_Solver.m_Regulations.m_Memory.m_nGrowSize = 0;
  this->m_Solver.m_Regulations.m_Size = 0;
  this->m_Solver.m_Regulations.m_pElements = nullptr;
  this->m_Solver.m_Regulations.m_Memory.m_nAllocationCount = 8;
  v4 = (AI_MoveSuggestion_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 192);
  this->m_Solver.m_Regulations.m_Memory.m_pMemory = v4;
  this->m_Solver.m_Regulations.m_pElements = v4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078540
// Name: private: void CAI_PlaneSolver::GenerateSuggestionFromTrace(struct AILocalMoveGoal_t const __near &,struct AIMoveTrace_t const __near &,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlaneSolver::GenerateSuggestionFromTrace(
        CAI_PlaneSolver *this,
        const AILocalMoveGoal_t *goal,
        const AIMoveTrace_t *moveTrace,
        float probeDist,
        float arcCenter,
        float arcSpan,
        int probeOffset)
{
  __int32 v8; // eax
  CBaseEntity *pMoveTarget; // eax
  CBaseEntity *pObstruction; // ecx
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  char v20; // bl
  float v21; // xmm0_4
  bool v22; // cc
  float x; // xmm2_4
  float v24; // xmm0_4
  CBaseEntity *v25; // ecx
  float v26; // xmm5_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  int v29; // edx
  CAI_MoveSolver *p_m_Solver; // edi
  float v31; // xmm0_4
  CBaseEntity *v32; // ecx
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  CBaseEntity *v36; // ecx
  float v37; // xmm1_4
  float v38; // xmm0_4
  int m_Size; // [esp-4h] [ebp-30h]
  int v40; // [esp-4h] [ebp-30h]
  int v41; // [esp-4h] [ebp-30h]
  AI_MoveSuggestion_t suggestion; // [esp+10h] [ebp-1Ch] BYREF
  float favoredWeight; // [esp+28h] [ebp-4h]
  float goala; // [esp+34h] [ebp+8h]
  AI_MoveSuggType_t type; // [esp+38h] [ebp+Ch]
  float thirdSpan; // [esp+3Ch] [ebp+10h]
  bool favorLeft_3; // [esp+47h] [ebp+1Bh]

  v8 = moveTrace->fStatus + 4;
  suggestion.type = AIMS_INVALID;
  memset(&suggestion.weight, 0, 12);
  suggestion.hObstacleEntity.m_Index = -1;
  suggestion.flags = 0;
  switch ( v8 )
  {
    case 0:
      type = AIMST_AVOID_DANGER;
      break;
    case 1:
      type = AIMST_AVOID_NPC;
      break;
    case 2:
      type = AIMST_AVOID_WORLD;
      break;
    case 3:
      type = AIMST_AVOID_OBJECT;
      break;
    default:
      type = AIMST_NO_KNOWLEDGE;
      break;
  }
  pMoveTarget = goal->pMoveTarget;
  if ( pMoveTarget != nullptr )
  {
    pObstruction = moveTrace->pObstruction;
    if ( pMoveTarget == pObstruction )
    {
      suggestion.type = type;
      suggestion.weight = 0.0;
      if ( pObstruction != nullptr )
        suggestion.hObstacleEntity.m_Index = pObstruction->GetRefEHandle(this: pObstruction)->m_Index;
      else
        suggestion.hObstacleEntity.m_Index = -1;
      v12 = arcCenter;
      suggestion.flags = 0;
      if ( arcCenter >= 0.0 )
      {
        if ( arcCenter >= 360.0 )
          v12 = arcCenter - 360.0;
      }
      else
      {
        v12 = arcCenter + 360.0;
      }
      suggestion.arc.center = v12;
      v13 = arcSpan;
      if ( arcSpan >= 0.0 )
      {
        if ( arcSpan >= 360.0 )
          v13 = arcSpan - 360.0;
      }
      else
      {
        v13 = arcSpan + 360.0;
      }
      m_Size = this->m_Solver.m_Regulations.m_Size;
      suggestion.arc.span = v13;
      CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertBefore(
        this: &this->m_Solver.m_Regulations,
        elem: m_Size,
        src: &suggestion);
      return;
    }
  }
  thirdSpan = 1.0 - (float)((float)(probeDist - moveTrace->flDistObstructed) / probeDist);
  v14 = thirdSpan;
  if ( thirdSpan <= 0.9 )
  {
    if ( thirdSpan >= 0.1 )
    {
      v16 = (thirdSpan - 0.1) * 1.25;
      goala = CAI_PlaneSolver::AdjustRegulationWeight(
                this,
                a2: (int)this,
                a3: (int)moveTrace,
                pEntity: moveTrace->pObstruction,
                weight: v16 * v16);
      v15 = goala;
      v14 = thirdSpan;
    }
    else
    {
      v15 = 0.0;
      goala = 0.0;
    }
  }
  else
  {
    v15 = 1.0;
    goala = 1.0;
  }
  if ( v15 < 0.001 )
    return;
  if ( v14 >= 0.5 )
    v17 = arcSpan;
  else
    v17 = (float)(v14 * 2.0) * arcSpan;
  v18 = moveTrace->vEndPosition.x - this->m_pNpc->m_vecOrigin.m_Value.x;
  v19 = moveTrace->vEndPosition.y - this->m_pNpc->m_vecOrigin.m_Value.y;
  favorLeft_3 = false;
  v20 = 0;
  if ( moveTrace->fStatus == AIMR_BLOCKED_NPC )
  {
    v21 = (float)((float)(moveTrace->pObstruction->m_vecOrigin.m_Value.y - this->m_pNpc->m_vecOrigin.m_Value.y) * v18)
        - (float)(v19 * (float)(moveTrace->pObstruction->m_vecOrigin.m_Value.x - this->m_pNpc->m_vecOrigin.m_Value.x));
    favorLeft_3 = v21 < 0.0;
    v22 = v21 <= 0.0;
    goto LABEL_36;
  }
  x = moveTrace->vHitNormal.x;
  if ( vec3_origin.x != x || vec3_origin.y != moveTrace->vHitNormal.y || vec3_origin.z != moveTrace->vHitNormal.z )
  {
    v24 = (float)(moveTrace->vHitNormal.y * v18) - (float)(x * v19);
    favorLeft_3 = v24 > 0.0;
    v22 = v24 >= 0.0;
LABEL_36:
    v20 = !v22;
  }
  v25 = moveTrace->pObstruction;
  v26 = v17 * 0.33333334;
  favoredWeight = v15 * v14;
  suggestion.type = type;
  suggestion.weight = v15;
  if ( v25 != nullptr )
    suggestion.hObstacleEntity.m_Index = v25->GetRefEHandle(this: v25)->m_Index;
  else
    suggestion.hObstacleEntity.m_Index = -1;
  v27 = arcCenter;
  suggestion.flags = 0;
  if ( arcCenter >= 0.0 )
  {
    if ( arcCenter >= 360.0 )
      v27 = arcCenter - 360.0;
  }
  else
  {
    v27 = arcCenter + 360.0;
  }
  suggestion.arc.center = v27;
  v28 = v26;
  if ( v26 >= 0.0 )
  {
    if ( v26 >= 360.0 )
      v28 = v26 - 360.0;
  }
  else
  {
    v28 = v26 + 360.0;
  }
  v29 = this->m_Solver.m_Regulations.m_Size;
  p_m_Solver = &this->m_Solver;
  suggestion.arc.span = v28;
  CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertBefore(
    this: &p_m_Solver->m_Regulations,
    elem: v29,
    src: &suggestion);
  if ( v20 != 0 )
    v31 = favoredWeight;
  else
    v31 = goala;
  v32 = moveTrace->pObstruction;
  suggestion.type = type;
  suggestion.weight = v31;
  if ( v32 != nullptr )
    suggestion.hObstacleEntity.m_Index = v32->GetRefEHandle(this: v32)->m_Index;
  else
    suggestion.hObstacleEntity.m_Index = -1;
  v33 = arcCenter - v26;
  suggestion.flags = 0;
  if ( (float)(arcCenter - v26) >= 0.0 )
  {
    if ( v33 >= 360.0 )
      v33 = v33 - 360.0;
  }
  else
  {
    v33 = v33 + 360.0;
  }
  suggestion.arc.center = v33;
  v34 = v26;
  if ( v26 >= 0.0 )
  {
    if ( v26 >= 360.0 )
      v34 = v26 - 360.0;
  }
  else
  {
    v34 = v26 + 360.0;
  }
  v40 = p_m_Solver->m_Regulations.m_Size;
  suggestion.arc.span = v34;
  CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertBefore(
    this: &p_m_Solver->m_Regulations,
    elem: v40,
    src: &suggestion);
  if ( favorLeft_3 )
    v35 = favoredWeight;
  else
    v35 = goala;
  v36 = moveTrace->pObstruction;
  suggestion.type = type;
  suggestion.weight = v35;
  if ( v36 != nullptr )
    suggestion.hObstacleEntity.m_Index = v36->GetRefEHandle(this: v36)->m_Index;
  else
    suggestion.hObstacleEntity.m_Index = -1;
  v37 = v26;
  v38 = v26 + arcCenter;
  suggestion.flags = 0;
  if ( (float)(v26 + arcCenter) >= 0.0 )
  {
    if ( v38 >= 360.0 )
      v38 = v38 - 360.0;
  }
  else
  {
    v38 = v38 + 360.0;
  }
  suggestion.arc.center = v38;
  if ( v26 >= 0.0 )
  {
    if ( v26 >= 360.0 )
      v37 = v26 - 360.0;
  }
  else
  {
    v37 = v26 + 360.0;
  }
  v41 = p_m_Solver->m_Regulations.m_Size;
  suggestion.arc.span = v37;
  CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertBefore(
    this: &p_m_Solver->m_Regulations,
    elem: v41,
    src: &suggestion);
}

//------------------------------------------------------------------------------
// Address: 0x100789E0
// Name: private: enum AI_SuggestorResult_t CAI_PlaneSolver::GenerateObstacleSuggestion(struct AILocalMoveGoal_t const __near &,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_PlaneSolver::GenerateObstacleSuggestion(
        CAI_PlaneSolver *this,
        const AILocalMoveGoal_t *goal,
        float yawScanCenter,
        float probeDist,
        float spanPerProbe,
        int probeOffset)
{
  CAI_PlaneSolver *v6; // esi
  float v7; // xmm0_4
  float yaw; // xmm0_4
  CAI_BaseNPC *m_pNpc; // ecx
  float v11; // xmm3_4
  Navigation_t navType; // edi
  const Vector *p_m_Value; // esi
  const CBaseEntity *NavTargetEntity; // eax
  CAI_BaseNPC *v15; // ecx
  Navigation_t v16; // edi
  const Vector *v17; // esi
  const CBaseEntity *v18; // eax
  AIMoveTrace_t moveTrace; // [esp+1Ch] [ebp-5Ch] BYREF
  Vector vecEnd; // [esp+54h] [ebp-24h] BYREF
  Vector probeDir; // [esp+60h] [ebp-18h] BYREF
  float requiredMovement; // [esp+6Ch] [ebp-Ch]
  CAI_MoveProbe *m_pMoveProbe; // [esp+70h] [ebp-8h]
  CAI_PlaneSolver *v25; // [esp+74h] [ebp-4h]
  int savedregs; // [esp+78h] [ebp+0h] BYREF
  const AILocalMoveGoal_t *goala; // [esp+80h] [ebp+8h]
  const AILocalMoveGoal_t *goalb; // [esp+80h] [ebp+8h]

  v6 = this;
  v25 = this;
  memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
  if ( probeOffset == 0 )
  {
    yaw = yawScanCenter;
    goto LABEL_12;
  }
  yawScanCenter = (float)((float)probeOffset * spanPerProbe) + yawScanCenter;
  v7 = yawScanCenter;
  if ( yawScanCenter >= 0.0 )
  {
    if ( yawScanCenter < 360.0 )
      goto LABEL_7;
    v7 = yawScanCenter - 360.0;
  }
  else
  {
    v7 = yawScanCenter + 360.0;
  }
  yawScanCenter = v7;
LABEL_7:
  yaw = v7 - (float)((float)((float)(2 * (probeOffset > 0) - 1) * spanPerProbe) * 0.5);
  if ( yaw >= 0.0 )
  {
    if ( yaw >= 360.0 )
      yaw = yaw - 360.0;
  }
  else
  {
    yaw = yaw + 360.0;
  }
LABEL_12:
  UTIL_YawToVector(result: &probeDir, yaw);
  m_pNpc = v6->m_pNpc;
  v11 = probeDist;
  requiredMovement = v6->m_pNpc->m_pMotor->m_flMoveInterval * goal->speed;
  if ( probeDist > requiredMovement )
  {
    navType = goal->navType;
    p_m_Value = &m_pNpc->m_vecOrigin.m_Value;
    vecEnd.x = m_pNpc->m_vecOrigin.m_Value.x + (float)(probeDir.x * requiredMovement);
    vecEnd.y = m_pNpc->m_vecOrigin.m_Value.y + (float)(probeDir.y * requiredMovement);
    vecEnd.z = m_pNpc->m_vecOrigin.m_Value.z + (float)(probeDir.z * requiredMovement);
    goala = (const AILocalMoveGoal_t *)m_pNpc->m_nAITraceMask;
    m_pMoveProbe = m_pNpc->m_pMoveProbe;
    NavTargetEntity = CAI_BaseNPC::GetNavTargetEntity(this: m_pNpc);
    if ( !CAI_MoveProbe::MoveLimit(
            this: m_pMoveProbe,
            a2: (int)&savedregs,
            navType,
            vecStart: p_m_Value,
            &vecEnd,
            collisionMask: (unsigned int)goala,
            pTarget: NavTargetEntity,
            pctToCheckStandPositions: 100.0,
            flags: (navType == NAV_GROUND) | 4,
            pTrace: &moveTrace) )
    {
      moveTrace.flDistObstructed = (float)(probeDist - requiredMovement) + moveTrace.flDistObstructed;
LABEL_17:
      CAI_PlaneSolver::GenerateSuggestionFromTrace(
        this: v25,
        goal,
        &moveTrace,
        probeDist,
        arcCenter: yawScanCenter,
        arcSpan: spanPerProbe,
        probeOffset);
      return 1;
    }
    v11 = probeDist;
    v6 = v25;
  }
  v15 = v6->m_pNpc;
  v16 = goal->navType;
  v17 = &v6->m_pNpc->m_vecOrigin.m_Value;
  vecEnd.x = v17->x + (float)(probeDir.x * v11);
  vecEnd.y = v17->y + (float)(probeDir.y * v11);
  vecEnd.z = v17->z + (float)(probeDir.z * v11);
  goalb = (const AILocalMoveGoal_t *)v15->m_nAITraceMask;
  requiredMovement = *(float *)&v15->m_pMoveProbe;
  v18 = CAI_BaseNPC::GetNavTargetEntity(this: v15);
  if ( !CAI_MoveProbe::MoveLimit(
          this: (CAI_MoveProbe *)LODWORD(requiredMovement),
          a2: (int)&savedregs,
          navType: v16,
          vecStart: v17,
          &vecEnd,
          collisionMask: (unsigned int)goalb,
          pTarget: v18,
          pctToCheckStandPositions: 0.0,
          flags: (v16 == NAV_GROUND) | 4,
          pTrace: &moveTrace) )
    goto LABEL_17;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10078C60
// Name: public: void CAI_PlaneSolver::AddObstacle(class Vector const __near &,float,class CBaseEntity __near *,enum AI_MoveSuggType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_PlaneSolver::AddObstacle(
        CAI_PlaneSolver *this,
        const Vector *center,
        float radius,
        CBaseEntity *pEntity,
        AI_MoveSuggType_t type)
{
  __int64 v5; // xmm0_8
  float z; // eax
  CAI_PlaneSolver::CircleObstacles_t src; // [esp+0h] [ebp-18h] BYREF

  v5 = *(_QWORD *)&center->x;
  z = center->z;
  src.type = type;
  *(_QWORD *)&src.center.x = v5;
  src.center.z = z;
  src.radius = radius;
  if ( pEntity != nullptr )
    src.hEntity.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    src.hEntity.m_Index = -1;
  CUtlVector<CAI_PlaneSolver::CircleObstacles_t,CUtlMemory<CAI_PlaneSolver::CircleObstacles_t,int>>::InsertBefore(
    this: &this->m_Obstacles,
    elem: this->m_Obstacles.m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x10078CC0
// Name: private: bool CAI_PlaneSolver::GenerateCircleObstacleSuggestion(struct CAI_PlaneSolver::CircleObstacles_t const __near &,struct AILocalMoveGoal_t const __near &,float,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CAI_PlaneSolver::GenerateCircleObstacleSuggestion@<al>(
        CAI_PlaneSolver *this@<ecx>,
        float a2@<ebp>,
        CBaseEntity *a3@<esi>,
        const CAI_PlaneSolver::CircleObstacles_t *obstacle,
        const AILocalMoveGoal_t *moveGoal,
        float probeDist,
        const Vector *npcLoc,
        float radiusNpc)
{
  unsigned int m_Index; // ecx
  int v9; // eax
  CEntInfo *v10; // edx
  unsigned int v11; // ecx
  IHandleEntity *m_pEntity; // edx
  int v13; // eax
  bool v14; // zf
  CBaseEntity **v15; // eax
  double v16; // st7
  double v17; // st7
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v24; // xmm3_4
  __int128 v25; // xmm0
  float v26; // xmm0_4
  CBaseEntity *v27; // eax
  double v28; // st7
  float v29; // xmm0_4
  float y; // xmm0_4
  int v31; // [esp-4h] [ebp-74h]
  float v32; // [esp+0h] [ebp-70h]
  _BYTE v33[24]; // [esp+14h] [ebp-5Ch] OVERLAPPED BYREF
  float v34; // [esp+3Ch] [ebp-34h] BYREF
  float v35; // [esp+40h] [ebp-30h]
  float v36; // [esp+44h] [ebp-2Ch]
  Vector maxs; // [esp+48h] [ebp-28h] BYREF
  Vector vecToObstacle; // [esp+54h] [ebp-1Ch]
  float distToObstacle; // [esp+60h] [ebp-10h]
  float distToObstacleSq; // [esp+64h] [ebp-Ch]
  void *v41; // [esp+68h] [ebp-8h]
  void *retaddr; // [esp+70h] [ebp+0h]

  distToObstacleSq = a2;
  v41 = retaddr;
  LODWORD(vecToObstacle.z) = this;
  m_Index = obstacle->hEntity.m_Index;
  if ( m_Index == -1
    || (a3 = (CBaseEntity *)g_pEntityList,
        v9 = (unsigned __int16)m_Index,
        v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v11 = HIWORD(m_Index),
        v10->m_SerialNumber != v11)
    || v10->m_pEntity == nullptr
    || (g_pEntityList->m_EntPtrArray[v9].m_SerialNumber != v11
      ? (m_pEntity = nullptr)
      : (m_pEntity = g_pEntityList->m_EntPtrArray[v9].m_pEntity),
        m_pEntity == (IHandleEntity *)-228) )
  {
    v17 = NAI_Hull::Height(id: *(_DWORD *)(*(_DWORD *)LODWORD(vecToObstacle.z) + 1672));
  }
  else
  {
    v13 = v9;
    v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v11;
    v15 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v13];
    if ( v14 )
      a3 = *v15;
    else
      a3 = nullptr;
    if ( a3 == moveGoal->pMoveTarget && (a3->IsNPC(this: a3) || a3->IsPlayer(this: a3)) )
      return 0;
    a3->m_Collision.WorldSpaceSurroundingBounds(this: &a3->m_Collision, a2: (Vector *)&v33[12], a3: (Vector *)&v34);
    v16 = NAI_Hull::Height(id: *(_DWORD *)(*(_DWORD *)LODWORD(vecToObstacle.z) + 1672));
    v17 = (v16 + v36 - *(float *)&v33[20]) * 0.5;
  }
  vecToObstacle.y = v17;
  if ( fabs(obstacle->center.z - npcLoc->z) > vecToObstacle.y )
    return 0;
  v18 = npcLoc->x - obstacle->center.x;
  v19 = npcLoc->y - obstacle->center.y;
  v20 = (float)(v19 * v19) + (float)(v18 * v18);
  v21 = obstacle->radius + radiusNpc;
  v34 = v18;
  v35 = v19;
  vecToObstacle.y = v20;
  distToObstacle = v21;
  if ( v20 <= 0.001 || v20 >= (float)((float)(v21 + probeDist) * (float)(v21 + probeDist)) )
    return 0;
  maxs.x = v18 * -1.0;
  maxs.y = v19 * -1.0;
  maxs.z = -0.0;
  vecToObstacle.x = VectorNormalize(vec: &maxs);
  v22 = distToObstacle * distToObstacle;
  if ( (float)((float)((float)(moveGoal->dir.y * maxs.y) + (float)(maxs.x * moveGoal->dir.x))
             + (float)(moveGoal->dir.z * maxs.z)) >= 0.0 )
  {
    if ( vecToObstacle.y > v22 )
    {
      v24 = vecToObstacle.y - v22;
      v25 = 0;
      *(float *)&v25 = fsqrt(v24);
      *(_OWORD *)v33 = v25;
      *(double *)&v25 = (float)((float)((float)(maxs.y
                                              * (float)((float)(COERCE_FLOAT(
                                                                  COERCE_UNSIGNED_INT(*(float *)&v25 * v35)
                                                                ^ _mask__NegFloat_)
                                                              - (float)(distToObstacle * v34))
                                                      * (float)(1.0 / vecToObstacle.y)))
                                      + (float)(maxs.x
                                              * (float)((float)((float)(distToObstacle * v35)
                                                              - (float)(*(float *)&v25 * v34))
                                                      * (float)(1.0 / vecToObstacle.y))))
                              + (float)(maxs.z * 0.0));
      __libm_sse2_acos();
      *(float *)&v25 = *(double *)&v25;
      v26 = (float)(*(float *)&v25 * 57.29578) * 2.0;
      vecToObstacle.y = v26;
      distToObstacle = 1.0 - (float)((float)(vecToObstacle.x - distToObstacle) / probeDist);
      if ( distToObstacle > 0.75 )
        vecToObstacle.y = (float)((float)((float)(distToObstacle - 0.75) * (float)(v26 * 0.5)) * 4.0) + v26;
      goto LABEL_26;
    }
  }
  else if ( vecToObstacle.y > v22 )
  {
    return 0;
  }
  vecToObstacle.y = 210.0;
  distToObstacle = 1.0;
LABEL_26:
  if ( CHandle<CBaseEntity>::operator!=(this: &obstacle->hEntity, val: nullptr) )
  {
    v32 = distToObstacle;
    v27 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &obstacle->hEntity);
    distToObstacle = CAI_PlaneSolver::AdjustRegulationWeight(
                       this: (CAI_PlaneSolver *)LODWORD(vecToObstacle.z),
                       a2: (int)obstacle,
                       (int)a3,
                       pEntity: v27,
                       weight: v32);
  }
  *(_DWORD *)v33 = obstacle->type;
  *(float *)&v33[4] = distToObstacle;
  *(_DWORD *)&v33[16] = -1;
  *(_DWORD *)&v33[20] = 0;
  v28 = UTIL_VecToYaw(vec: &maxs);
  distToObstacle = v28;
  v29 = distToObstacle;
  if ( v28 >= 0.0 )
  {
    if ( distToObstacle >= 360.0 )
      v29 = distToObstacle - 360.0;
  }
  else
  {
    v29 = distToObstacle + 360.0;
  }
  *(float *)&v33[8] = v29;
  y = vecToObstacle.y;
  if ( vecToObstacle.y >= 0.0 )
  {
    if ( vecToObstacle.y >= 360.0 )
      y = vecToObstacle.y - 360.0;
  }
  else
  {
    y = vecToObstacle.y + 360.0;
  }
  v31 = *(_DWORD *)(LODWORD(vecToObstacle.z) + 88);
  *(float *)&v33[12] = y;
  CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertBefore(
    this: (CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *)(LODWORD(vecToObstacle.z) + 76),
    elem: v31,
    src: (const AI_MoveSuggestion_t *)v33);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100790C0
// Name: private: bool CAI_PlaneSolver::GenerateCircleObstacleSuggestions(struct AILocalMoveGoal_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
bool __userpurge CAI_PlaneSolver::GenerateCircleObstacleSuggestions@<al>(
        CAI_PlaneSolver *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const AILocalMoveGoal_t *moveGoal,
        float probeDist)
{
  CAI_BaseNPC *m_pNpc; // ecx
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // edx
  int v9; // eax
  __int64 v10; // xmm0_8
  CAI_BaseNPC *v11; // ecx
  void (__thiscall *WorldSpaceSurroundingBounds)(struct CBaseEntity::NetworkVar_m_Collision *, Vector *, Vector *); // edx
  float x; // xmm0_4
  int v14; // edi
  int m_Head; // edi
  float v18[3]; // [esp+34h] [ebp-3Ch] BYREF
  Vector maxs; // [esp+40h] [ebp-30h] BYREF
  Vector mins; // [esp+4Ch] [ebp-24h] BYREF
  Vector npcLoc; // [esp+58h] [ebp-18h]
  float radiusNpc; // [esp+64h] [ebp-Ch] BYREF
  void *v23; // [esp+68h] [ebp-8h]
  void *retaddr; // [esp+70h] [ebp+0h]

  radiusNpc = a2;
  v23 = retaddr;
  m_pNpc = this->m_pNpc;
  WorldSpaceCenter = m_pNpc->WorldSpaceCenter;
  HIBYTE(npcLoc.z) = 0;
  v9 = ((int (__thiscall *)(CAI_BaseNPC *, int, int))WorldSpaceCenter)(a1: m_pNpc, a2: a3, a3: a4);
  v10 = *(_QWORD *)v9;
  v11 = this->m_pNpc;
  WorldSpaceSurroundingBounds = this->m_pNpc->m_Collision.WorldSpaceSurroundingBounds;
  mins.z = *(float *)(v9 + 8);
  *(_QWORD *)&mins.x = v10;
  WorldSpaceSurroundingBounds(this: &v11->m_Collision, a2: &maxs, a3: (Vector *)v18);
  x = fsqrt(
        (float)((float)(maxs.y - v18[1]) * (float)(maxs.y - v18[1]))
      + (float)((float)(maxs.x - v18[0]) * (float)(maxs.x - v18[0])))
    * 0.5;
  v14 = 0;
  npcLoc.x = x;
  if ( this->m_Obstacles.m_Size > 0 )
  {
    npcLoc.y = 0.0;
    do
    {
      if ( CAI_PlaneSolver::GenerateCircleObstacleSuggestion(
             this,
             a2: COERCE_FLOAT(&radiusNpc),
             a3: (CBaseEntity *)this,
             obstacle: (const CAI_PlaneSolver::CircleObstacles_t *)((char *)this->m_Obstacles.m_Memory.m_pMemory
                                                        + LODWORD(npcLoc.y)),
             moveGoal,
             probeDist,
             npcLoc: &mins,
             radiusNpc: x) != 0 )
        HIBYTE(npcLoc.z) = 1;
      LODWORD(npcLoc.y) += 24;
      x = npcLoc.x;
      ++v14;
    }
    while ( v14 < this->m_Obstacles.m_Size );
  }
  this->m_Obstacles.m_Size = 0;
  m_Head = CAI_PlaneSolver::s_GlobalObstacles.m_Head;
  if ( CAI_PlaneSolver::s_GlobalObstacles.m_Head != 0 )
  {
    while ( 1 )
    {
      if ( CAI_PlaneSolver::GenerateCircleObstacleSuggestion(
             this,
             a2: COERCE_FLOAT(&radiusNpc),
             a3: (CBaseEntity *)this,
             obstacle: (const CAI_PlaneSolver::CircleObstacles_t *)m_Head,
             moveGoal,
             probeDist,
             npcLoc: &mins,
             radiusNpc: x) != 0 )
        HIBYTE(npcLoc.z) = 1;
      m_Head = *(_DWORD *)(m_Head + 28);
      if ( m_Head == 0 )
        break;
      x = npcLoc.x;
    }
  }
  return HIBYTE(npcLoc.z);
}

//------------------------------------------------------------------------------
// Address: 0x10079200
// Name: private: void CAI_PlaneSolver::GenerateObstacleNpcs(struct AILocalMoveGoal_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_PlaneSolver::GenerateObstacleNpcs(
        CAI_PlaneSolver *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const AILocalMoveGoal_t *goal,
        float probeDist)
{
  CAI_PlaneSolver *v6; // edi
  CAI_BaseNPC **v7; // eax
  CAI_BaseNPC *m_pNpc; // ecx
  CBaseEntity *v9; // esi
  CAI_Path *pPath; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v13; // edi
  float z; // xmm2_4
  unsigned int v15; // ecx
  float v16; // xmm0_4
  float v17; // xmm1_4
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // edx
  const Vector *v19; // eax
  CAI_BaseNPC **v20; // esi
  CBasePlayer *v21; // eax
  CBaseEntity *v22; // esi
  CBaseEntity *v23; // edi
  float v24; // xmm0_4
  float v25; // xmm1_4
  const Vector *(__thiscall *v26)(CBaseEntity *); // edx
  const Vector *v27; // eax
  float v29; // [esp+44h] [ebp-6Ch]
  float v30[3]; // [esp+60h] [ebp-50h] BYREF
  Vector maxs; // [esp+6Ch] [ebp-44h] BYREF
  Vector mins; // [esp+78h] [ebp-38h] BYREF
  Vector minsSelf; // [esp+84h] [ebp-2Ch] BYREF
  Vector maxsSelf; // [esp+90h] [ebp-20h]
  CAI_BaseNPC **ppAIs; // [esp+9Ch] [ebp-14h]
  CAI_PlaneSolver *radiusSelf; // [esp+A0h] [ebp-10h]
  float radius; // [esp+A4h] [ebp-Ch] BYREF
  int i; // [esp+A8h] [ebp-8h]
  int retaddr; // [esp+B0h] [ebp+0h]

  radius = a2;
  i = retaddr;
  v6 = this;
  radiusSelf = this;
  v7 = CAI_Manager::AccessAIs(this: &g_AI_Manager);
  m_pNpc = v6->m_pNpc;
  LODWORD(maxsSelf.x) = v7;
  ((void (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, Vector *, Vector *, int, int))m_pNpc->m_Collision.WorldSpaceSurroundingBounds)(
    a1: &m_pNpc->m_Collision,
    a2: &mins,
    a3: &minsSelf,
    a4: a3,
    a5: a4);
  maxsSelf.y = fsqrt(
                 (float)((float)(mins.y - minsSelf.y) * (float)(mins.y - minsSelf.y))
               + (float)((float)(mins.x - minsSelf.x) * (float)(mins.x - minsSelf.x)))
             * 0.5;
  ppAIs = nullptr;
  if ( vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager) > 0 )
  {
    do
    {
      v9 = *(CBaseEntity **)(LODWORD(maxsSelf.x) + 4 * (_DWORD)ppAIs);
      if ( v9 != v6->m_pNpc && v9->IsAlive(this: v9) )
      {
        pPath = goal->pPath;
        if ( pPath == nullptr
          || ((m_Index = pPath->m_target.m_Index) == -1
           || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
            ? (m_pEntity = nullptr)
            : (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity),
              v9 != m_pEntity) )
        {
          v9->m_Collision.WorldSpaceSurroundingBounds(this: &v9->m_Collision, a2: &maxs, a3: (Vector *)v30);
          if ( (float)(minsSelf.z + 12.0) > maxs.z && v30[2] > (float)(mins.z - 12.0) )
          {
            v13 = v6->m_pNpc;
            z = fsqrt(
                  (float)((float)(maxs.y - v30[1]) * (float)(maxs.y - v30[1]))
                + (float)((float)(maxs.x - v30[0]) * (float)(maxs.x - v30[0])))
              * 0.5;
            v15 = (unsigned int)v13->m_iEFlags >> 11;
            maxsSelf.z = z;
            if ( (v15 & 1) != 0 )
            {
              CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&radius);
              z = maxsSelf.z;
            }
            if ( (v9->m_iEFlags & 0x800) != 0 )
            {
              CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&radius);
              z = maxsSelf.z;
            }
            v16 = v9->m_vecAbsOrigin.x - v13->m_vecAbsOrigin.x;
            v17 = v9->m_vecAbsOrigin.y - v13->m_vecAbsOrigin.y;
            if ( (float)(maxsSelf.y + probeDist) > (float)(fsqrt((float)(v17 * v17) + (float)(v16 * v16)) - z) )
            {
              WorldSpaceCenter = v9->WorldSpaceCenter;
              ppAIs = (CAI_BaseNPC **)3;
              LODWORD(maxsSelf.z) = v9;
              maxsSelf.y = z;
              v19 = WorldSpaceCenter(this: v9);
              CAI_PlaneSolver::AddObstacle(
                this: radiusSelf,
                center: v19,
                radius: maxsSelf.y,
                pEntity: (CBaseEntity *)LODWORD(maxsSelf.z),
                type: (AI_MoveSuggType_t)ppAIs);
            }
            v6 = radiusSelf;
          }
        }
      }
      ppAIs = (CAI_BaseNPC **)((char *)ppAIs + 1);
      v20 = ppAIs;
    }
    while ( (int)v20 < vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager) );
  }
  v21 = UTIL_PlayerByIndex(playerIndex: 1);
  v22 = v21;
  if ( v21 != nullptr )
  {
    v21->m_Collision.WorldSpaceSurroundingBounds(this: &v21->m_Collision, a2: (Vector *)v30, a3: &maxs);
    if ( (float)(minsSelf.z + 12.0) > v30[2] && maxs.z > (float)(mins.z - 12.0) )
    {
      v23 = v6->m_pNpc;
      v29 = fsqrt(
              (float)((float)(v30[1] - maxs.y) * (float)(v30[1] - maxs.y))
            + (float)((float)(v30[0] - maxs.x) * (float)(v30[0] - maxs.x)));
      if ( (v23->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v23, a2: (int)&radius);
      if ( (v22->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v22, a2: (int)&radius);
      v24 = v22->m_vecAbsOrigin.x - v23->m_vecAbsOrigin.x;
      v25 = v22->m_vecAbsOrigin.y - v23->m_vecAbsOrigin.y;
      if ( (float)(maxsSelf.y + probeDist) > (float)(fsqrt((float)(v25 * v25) + (float)(v24 * v24)) - v29) )
      {
        v26 = v22->WorldSpaceCenter;
        ppAIs = (CAI_BaseNPC **)3;
        LODWORD(maxsSelf.z) = v22;
        maxsSelf.y = v29;
        v27 = v26(this: v22);
        CAI_PlaneSolver::AddObstacle(
          this: radiusSelf,
          center: v27,
          radius: maxsSelf.y,
          pEntity: (CBaseEntity *)LODWORD(maxsSelf.z),
          type: (AI_MoveSuggType_t)ppAIs);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079590
// Name: private: enum AI_SuggestorResult_t CAI_PlaneSolver::GenerateObstacleSuggestions(struct AILocalMoveGoal_t const __near &,struct AIMoveTrace_t const __near &,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
AI_SuggestorResult_t __thiscall CAI_PlaneSolver::GenerateObstacleSuggestions(
        CAI_PlaneSolver *this,
        const AILocalMoveGoal_t *goal,
        const AIMoveTrace_t *directTrace,
        float distClear,
        float probeDist,
        float degreesToProbe,
        int nProbes)
{
  AI_SuggestorResult_t result; // eax
  int v9; // ebx
  float yawScanCenter; // xmm2_4
  int v11; // esi
  float v12; // xmm0_4
  float v13; // xmm0_4
  int m_Size; // edx
  int v15; // esi
  int v16; // ebx
  float v17; // xmm0_4
  float v18; // xmm0_4
  int v19; // edx
  AI_SuggestorResult_t v20; // esi
  float v21; // xmm2_4
  float v22; // xmm0_4
  int v23; // edx
  float v24; // xmm0_4
  AI_MoveSuggestion_t src; // [esp+1Ch] [ebp-24h] BYREF
  AI_SuggestorResult_t seekResult; // [esp+34h] [ebp-Ch]
  float yawGoalDir; // [esp+38h] [ebp-8h]
  float spanPerProbe; // [esp+3Ch] [ebp-4h]
  int savedregs; // [esp+40h] [ebp+0h] BYREF
  char foundClear_3; // [esp+5Fh] [ebp+1Fh]
  char foundClear_3a; // [esp+5Fh] [ebp+1Fh]

  seekResult = SR_NONE;
  if ( !this->m_fSolvedPrev
    || goal->target.x != this->m_PrevTarget.x
    || goal->target.y != this->m_PrevTarget.y
    || goal->target.z != this->m_PrevTarget.z )
  {
    this->m_RefreshSamplesTimer.m_next = -1.0;
  }
  if ( PLANE_SOLVER_THINK_FREQUENCY[AIStrongOpt()] != 0.0
    && (float)(gpGlobals->curtime - this->m_RefreshSamplesTimer.m_next) <= -0.001 )
  {
    return this->m_Solver.m_Regulations.m_Size > 0;
  }
  this->m_Solver.m_Regulations.m_Size = 0;
  CAI_PlaneSolver::GenerateObstacleNpcs(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)this,
    a4: (int)goal,
    goal,
    probeDist);
  if ( CAI_PlaneSolver::GenerateCircleObstacleSuggestions(
         this,
         a2: COERCE_FLOAT(&savedregs),
         a3: (int)this,
         a4: (int)goal,
         moveGoal: goal,
         probeDist) )
  {
    seekResult = SR_OK;
  }
  spanPerProbe = degreesToProbe / (float)nProbes;
  v9 = (nProbes - 1) / 2;
  yawGoalDir = UTIL_VecToYaw(vec: &goal->dir);
  yawScanCenter = yawGoalDir;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(probeDist - (float)(directTrace->flDistObstructed + distClear)) & _mask__AbsFloat_) >= 0.1
    || directTrace->fStatus == AIMR_BLOCKED_NPC )
  {
    if ( CAI_PlaneSolver::GenerateObstacleSuggestion(
           this,
           goal,
           yawScanCenter: yawGoalDir,
           probeDist,
           spanPerProbe,
           probeOffset: 0) == 1 )
      seekResult = SR_OK;
    goto LABEL_17;
  }
  if ( directTrace->fStatus != AIMR_OK )
  {
    seekResult = SR_OK;
    CAI_PlaneSolver::GenerateSuggestionFromTrace(
      this,
      goal,
      moveTrace: directTrace,
      probeDist,
      arcCenter: yawGoalDir,
      arcSpan: spanPerProbe,
      probeOffset: 0);
LABEL_17:
    yawScanCenter = yawGoalDir;
  }
  v11 = 1;
  for ( foundClear_3 = 0; v11 <= v9; ++v11 )
  {
    if ( foundClear_3 != 0 )
    {
      if ( v11 != 0 )
      {
        v12 = (float)((float)v11 * spanPerProbe) + yawScanCenter;
        if ( v12 >= 0.0 )
        {
          if ( v12 >= 360.0 )
            v12 = v12 - 360.0;
        }
        else
        {
          v12 = v12 + 360.0;
        }
      }
      else
      {
        v12 = yawScanCenter;
      }
      src.type = AIMST_NO_KNOWLEDGE;
      src.weight = 1.0;
      src.hObstacleEntity.m_Index = -1;
      src.flags = 0;
      if ( v12 >= 0.0 )
      {
        if ( v12 >= 360.0 )
          v12 = v12 - 360.0;
      }
      else
      {
        v12 = v12 + 360.0;
      }
      src.arc.center = v12;
      v13 = spanPerProbe;
      if ( spanPerProbe >= 0.0 )
      {
        if ( spanPerProbe >= 360.0 )
          v13 = spanPerProbe - 360.0;
      }
      else
      {
        v13 = spanPerProbe + 360.0;
      }
      m_Size = this->m_Solver.m_Regulations.m_Size;
      src.arc.span = v13;
      CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertBefore(
        this: &this->m_Solver.m_Regulations,
        elem: m_Size,
        &src);
    }
    else if ( CAI_PlaneSolver::GenerateObstacleSuggestion(
                this,
                goal,
                yawScanCenter,
                probeDist,
                spanPerProbe,
                probeOffset: v11) == 1 )
    {
      seekResult = SR_OK;
    }
    else
    {
      foundClear_3 = 1;
    }
    yawScanCenter = yawGoalDir;
  }
  v15 = -1;
  v16 = -v9;
  foundClear_3a = 0;
  if ( v16 <= -1 )
  {
    do
    {
      if ( foundClear_3a != 0 )
      {
        if ( v15 != 0 )
        {
          v17 = (float)((float)v15 * spanPerProbe) + yawScanCenter;
          if ( v17 >= 0.0 )
          {
            if ( v17 >= 360.0 )
              v17 = v17 - 360.0;
          }
          else
          {
            v17 = v17 + 360.0;
          }
        }
        else
        {
          v17 = yawScanCenter;
        }
        src.type = AIMST_NO_KNOWLEDGE;
        src.weight = 1.0;
        src.hObstacleEntity.m_Index = -1;
        src.flags = 0;
        if ( v17 >= 0.0 )
        {
          if ( v17 >= 360.0 )
            v17 = v17 - 360.0;
        }
        else
        {
          v17 = v17 + 360.0;
        }
        src.arc.center = v17;
        v18 = spanPerProbe;
        if ( spanPerProbe >= 0.0 )
        {
          if ( spanPerProbe >= 360.0 )
            v18 = spanPerProbe - 360.0;
        }
        else
        {
          v18 = spanPerProbe + 360.0;
        }
        v19 = this->m_Solver.m_Regulations.m_Size;
        src.arc.span = v18;
        CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertBefore(
          this: &this->m_Solver.m_Regulations,
          elem: v19,
          &src);
      }
      else if ( CAI_PlaneSolver::GenerateObstacleSuggestion(
                  this,
                  goal,
                  yawScanCenter,
                  probeDist,
                  spanPerProbe,
                  probeOffset: v15) == 1 )
      {
        seekResult = SR_OK;
      }
      else
      {
        foundClear_3a = 1;
      }
      yawScanCenter = yawGoalDir;
      --v15;
    }
    while ( v15 >= v16 );
  }
  v20 = seekResult;
  if ( seekResult == SR_OK )
  {
    v21 = yawScanCenter - 180.0;
    if ( v21 < 0.0 )
      v21 = v21 + 360.0;
    src.type = AIMST_NO_KNOWLEDGE;
    src.weight = 1.0;
    src.hObstacleEntity.m_Index = -1;
    src.flags = 0;
    if ( v21 >= 0.0 )
    {
      if ( v21 >= 360.0 )
        v21 = v21 - 360.0;
    }
    else
    {
      v21 = v21 + 360.0;
    }
    v22 = 360.0 - degreesToProbe;
    src.arc.center = v21;
    if ( (float)(360.0 - degreesToProbe) >= 0.0 )
    {
      if ( v22 >= 360.0 )
        v22 = v22 - 360.0;
    }
    else
    {
      v22 = v22 + 360.0;
    }
    v23 = this->m_Solver.m_Regulations.m_Size;
    src.arc.span = v22;
    CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertBefore(
      this: &this->m_Solver.m_Regulations,
      elem: v23,
      &src);
  }
  v24 = PLANE_SOLVER_THINK_FREQUENCY[AIStrongOpt()];
  result = v20;
  if ( v24 == -1.0 )
    this->m_RefreshSamplesTimer.m_next = this->m_RefreshSamplesTimer.m_interval + gpGlobals->curtime;
  else
    this->m_RefreshSamplesTimer.m_next = gpGlobals->curtime + v24;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079A50
// Name: public: static void CAI_PlaneSolver::RemoveGlobalObstacle(struct Obstacle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_PlaneSolver::RemoveGlobalObstacle(Obstacle_t__ *hObstacle)
{
  CUtlLinkedList<CAI_PlaneSolver::CircleObstacles_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CAI_PlaneSolver::CircleObstacles_t,int>>>::Free(
    this: &CAI_PlaneSolver::s_GlobalObstacles,
    elem: (int)hObstacle);
}

//------------------------------------------------------------------------------
// Address: 0x10079A70
// Name: public: bool CAI_PlaneSolver::Solve(struct AILocalMoveGoal_t const __near &,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_PlaneSolver::Solve(
        CAI_PlaneSolver *this,
        const AILocalMoveGoal_t *goal,
        float distClear,
        Vector *pSolution)
{
  float speed; // xmm0_4
  bool result; // al
  CAI_PlaneSolver *v8; // ecx
  float maxDist; // xmm0_4
  CAI_BaseNPC *m_pNpc; // ecx
  float v11; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  Navigation_t navType; // eax
  CNetworkVectorXY_SeparateZBase<Vector,CBaseEntity::NetworkVar_m_vecOrigin> *p_m_vecOrigin; // edi
  const CBaseEntity *NavTargetEntity; // eax
  float v17; // xmm0_4
  bool v18; // al
  char degreesToProbe; // [esp+8h] [ebp-64h]
  AIMoveTrace_t moveTrace; // [esp+1Ch] [ebp-50h] BYREF
  Vector vecEnd; // [esp+54h] [ebp-18h] BYREF
  float degreesPositiveArc; // [esp+60h] [ebp-Ch]
  float probeDist; // [esp+64h] [ebp-8h]
  bool solved; // [esp+6Bh] [ebp-1h]
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF
  Navigation_t fVeryClose; // [esp+74h] [ebp+8h]
  unsigned int distCleara; // [esp+78h] [ebp+Ch]
  Vector *pSolutiona; // [esp+7Ch] [ebp+10h]

  speed = goal->speed;
  solved = false;
  if ( speed == 0.0 || CAI_PlaneSolver::DetectUnsolvable(this, goal) != 0 )
    return false;
  degreesPositiveArc = (float)(distClear < 1.0 ? 340 : 270);
  probeDist = CAI_PlaneSolver::CalcProbeDist(this: v8, speed: goal->speed);
  maxDist = probeDist;
  if ( (goal->flags & 5) != 0 && probeDist > goal->maxDist )
    maxDist = goal->maxDist;
  if ( CAI_PlaneSolver::GenerateObstacleSuggestions(
         this,
         goal,
         directTrace: &goal->directTrace,
         distClear,
         probeDist: maxDist,
         degreesToProbe: degreesPositiveArc,
         nProbes: 5) == SR_FAIL
    || CAI_PlaneSolver::RunMoveSolver(
         this,
         goal,
         directTrace: &goal->directTrace,
         degreesPositiveArc,
         fDeterOscillation: distClear >= 1.0,
         pResult: pSolution) == 0 )
  {
    goto LABEL_13;
  }
  CAI_PlaneSolver::VisualizeSolution(this, vecGoal: &goal->dir, vecActual: pSolution);
  memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
  m_pNpc = this->m_pNpc;
  v11 = this->m_pNpc->m_pMotor->m_flMoveInterval * goal->speed;
  y = pSolution->y;
  z = pSolution->z;
  navType = goal->navType;
  p_m_vecOrigin = &this->m_pNpc->m_vecOrigin;
  vecEnd.x = (float)(pSolution->x * v11) + p_m_vecOrigin->m_Value.x;
  vecEnd.y = p_m_vecOrigin->m_Value.y + (float)(y * v11);
  vecEnd.z = p_m_vecOrigin->m_Value.z + (float)(z * v11);
  distCleara = m_pNpc->m_nAITraceMask;
  fVeryClose = navType;
  pSolutiona = (Vector *)m_pNpc->m_pMoveProbe;
  degreesToProbe = navType == NAV_GROUND;
  NavTargetEntity = CAI_BaseNPC::GetNavTargetEntity(this: m_pNpc);
  CAI_MoveProbe::MoveLimit(
    this: (CAI_MoveProbe *)pSolutiona,
    a2: (int)&savedregs,
    navType: fVeryClose,
    vecStart: &p_m_vecOrigin->m_Value,
    &vecEnd,
    collisionMask: distCleara,
    pTarget: NavTargetEntity,
    pctToCheckStandPositions: 100.0,
    flags: degreesToProbe,
    pTrace: &moveTrace);
  if ( moveTrace.fStatus < AIMR_OK )
  {
    solved = false;
    goto LABEL_13;
  }
  v17 = goal->speed;
  solved = true;
  if ( v17 == 0.0 )
  {
LABEL_13:
    v18 = false;
    goto LABEL_14;
  }
  v18 = true;
LABEL_14:
  this->m_fSolvedPrev = v18;
  result = solved;
  this->m_PrevTarget.x = goal->target.x;
  this->m_PrevTarget.y = goal->target.y;
  this->m_PrevTarget.z = goal->target.z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079C80
// Name: __CreateCServerGameTagsIServerGameTags_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface()
{
  return &_g_CServerGameTags_singleton;
}
