// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_moveprobe.cpp
// Functions: 29
// ============================================================

#include "game\server\ai_moveprobe.h"

//------------------------------------------------------------------------------
// Address: 0x1005D910
// Name: public: class Vector CAI_MoveProbe::CalcJumpLaunchVelocity(class Vector const __near &,class Vector const __near &,float,float __near *,float,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_MoveProbe::CalcJumpLaunchVelocity(
        CAI_MoveProbe *this,
        Vector *result,
        const Vector *startPos,
        const Vector *endPos,
        float flGravity,
        float *pminHeight,
        float maxHorzVelocity,
        Vector *pvecApex)
{
  float v10; // xmm0_4
  float v11; // xmm5_4
  Vector *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  Vector targetDir2D; // [esp+0h] [ebp-Ch] BYREF
  float distance; // [esp+18h] [ebp+Ch]
  float stepHeight; // [esp+1Ch] [ebp+10h]

  stepHeight = endPos->z - startPos->z;
  targetDir2D.x = endPos->x - startPos->x;
  targetDir2D.y = endPos->y - startPos->y;
  targetDir2D.z = 0.0;
  distance = VectorNormalize(vec: &targetDir2D);
  v10 = (float)((float)(flGravity * 0.5) * (float)((float)(distance / maxHorzVelocity) * 0.5))
      * (float)((float)(distance / maxHorzVelocity) * 0.5);
  if ( *pminHeight > v10 )
    v10 = *pminHeight;
  *pminHeight = v10;
  if ( v10 <= stepHeight )
    v11 = stepHeight;
  else
    v11 = v10;
  *pminHeight = v11;
  v12 = result;
  v13 = fsqrt((float)(v11 * 2.0) * (float)(1.0 / flGravity));
  v14 = distance
      / (float)(fsqrt(
                  (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v11 - stepHeight) & _mask__AbsFloat_) * 2.0)
                * (float)(1.0 / flGravity))
              + v13);
  v15 = targetDir2D.x * v14;
  v16 = targetDir2D.y * v14;
  v17 = v14 * targetDir2D.z;
  result->x = v15;
  result->y = v16;
  result->z = fsqrt((float)(flGravity * 2.0) * v11);
  if ( pvecApex != nullptr )
  {
    v18 = startPos->x + (float)(v15 * v13);
    v19 = startPos->y + (float)(v16 * v13);
    v20 = (float)(startPos->z + (float)(v17 * v13)) + v11;
    pvecApex->x = v18;
    pvecApex->y = v19;
    pvecApex->z = v20;
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1005DA80
// Name: struct edict_t __near * INDEXENT(int)
// Source: json
//------------------------------------------------------------------------------
edict_t *__cdecl INDEXENT(int iEdictNum)
{
  if ( gpGlobals->pEdicts != nullptr )
    return (gpGlobals->pEdicts[iEdictNum].m_fStateFlags & 2) == 0 ? &gpGlobals->pEdicts[iEdictNum] : nullptr;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005DAB0
// Name: protected: class Vector const __near & CAI_Component::WorldAlignMins(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_Component::WorldAlignMins(CAI_Component *this)
{
  return this->m_pOuter->m_Collision.OBBMins(this: &this->m_pOuter->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x1005DAD0
// Name: protected: class Vector const __near & CAI_Component::WorldAlignMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_Component::WorldAlignMaxs(CAI_Component *this)
{
  return this->m_pOuter->m_Collision.OBBMaxs(this: &this->m_pOuter->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x1005DAF0
// Name: public: class Vector const __near & CAI_Component::GetHullMins(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_Component::GetHullMins(CAI_Component *this)
{
  return NAI_Hull::Mins(id: this->m_pOuter->m_eHull);
}

//------------------------------------------------------------------------------
// Address: 0x1005DB10
// Name: public: class Vector const __near & CAI_Component::GetHullMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_Component::GetHullMaxs(CAI_Component *this)
{
  return NAI_Hull::Maxs(id: this->m_pOuter->m_eHull);
}

//------------------------------------------------------------------------------
// Address: 0x1005DB30
// Name: float ComputePathDirection(enum Navigation_t,class Vector const __near &,class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ComputePathDirection(Navigation_t navType, const Vector *start, const Vector *end, Vector *pDirection)
{
  double result; // st7
  float v5; // xmm0_4
  float x; // xmm1_4
  float v7; // xmm0_4

  if ( navType == NAV_GROUND || navType == NAV_CRAWL )
  {
    pDirection->x = end->x - start->x;
    v5 = end->y - start->y;
    x = pDirection->x;
    pDirection->y = v5;
    pDirection->z = 0.0;
    v7 = fsqrt((float)(x * x) + (float)(v5 * v5));
    result = v7;
    if ( v7 == 0.0 )
    {
      pDirection->y = 0.0;
      pDirection->x = 0.0;
    }
    else
    {
      pDirection->x = pDirection->x * (float)(1.0 / v7);
      pDirection->y = pDirection->y * (float)(1.0 / v7);
    }
  }
  else
  {
    pDirection->x = end->x - start->x;
    pDirection->y = end->y - start->y;
    pDirection->z = end->z - start->z;
    return VectorNormalize(vec: pDirection);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005DC40
// Name: ai_set_move_height_epsilon
// Source: json
//------------------------------------------------------------------------------
void __cdecl ai_set_move_height_epsilon(const CCommand *args)
{
  long double v1; // st7
  float newEps; // [esp+10h] [ebp+8h]

  if ( args->m_nArgc > 1 )
  {
    v1 = atof(nptr: args->m_ppArgv[1]);
    if ( v1 >= 0.0 )
    {
      newEps = v1;
      if ( newEps < 1.0 )
        MOVE_HEIGHT_EPSILON = v1;
    }
    _Msg(a1: "Epsilon now %f\n", MOVE_HEIGHT_EPSILON);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005DCB0
// Name: enum AIMoveResult_t AIComputeBlockerMoveResult(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AIComputeBlockerMoveResult(CBaseEntity *pBlocker)
{
  edict_t *m_pPev; // eax

  if ( pBlocker->MyNPCPointer(this: pBlocker) != nullptr )
    return -3;
  m_pPev = pBlocker->m_Network.m_pPev;
  if ( m_pPev != nullptr && m_pPev - gpGlobals->pEdicts != 0 )
    return -1;
  else
    return -2;
}

//------------------------------------------------------------------------------
// Address: 0x1005DD00
// Name: public: bool CAI_MoveProbe::ShouldBrushBeIgnored(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_MoveProbe::ShouldBrushBeIgnored(CAI_MoveProbe *this, CBaseEntity *pEntity)
{
  void (__thiscall *m_pfnThink)(CBaseEntity *); // eax
  bool v3; // cl

  if ( pEntity->m_iClassname.pszValue != g_iszFuncBrushClassname.pszValue )
    return false;
  m_pfnThink = pEntity[1].m_pfnThink;
  if ( m_pfnThink == nullptr )
    return false;
  v3 = m_pfnThink == (void (__thiscall *)(CBaseEntity *))this->m_pOuter->m_iClassname.pszValue;
  if ( BYTE1(pEntity[1].m_Network.__vftable) != 0 )
    return !v3;
  else
    return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1005DD50
// Name: public: CAI_MoveProbe::CAI_MoveProbe(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_MoveProbe *__thiscall CAI_MoveProbe::CAI_MoveProbe(CAI_MoveProbe *this, CAI_BaseNPC *pOuter)
{
  this->m_pOuter = pOuter;
  this->__vftable = (CAI_MoveProbe_vtbl *)&CAI_MoveProbe::`vftable';
  this->m_bIgnoreTransientEntities = false;
  this->m_pTraceListData = nullptr;
  this->m_hLastBlockingEnt.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005DD80
// Name: public: class CBaseTrace __near & CBaseTrace::operator=(class CBaseTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseTrace *__thiscall CBaseTrace::operator=(CBaseTrace *this, const CBaseTrace *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005DE50
// Name: public: void CAI_MoveProbe::TraceHull(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned int,class CGameTrace __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAI_MoveProbe::TraceHull(
        CAI_MoveProbe *this@<ecx>,
        bool (__cdecl *a2)(IHandleEntity *, int)@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vecStart,
        const Vector *vecEnd,
        const Vector *hullMin,
        const Vector *hullMax,
        unsigned int mask,
        CGameTrace *pResult)
{
  CGameTrace *v11; // edi
  int v12; // [esp+14h] [ebp-8Ch]
  int v13; // [esp+18h] [ebp-88h]
  _BYTE v14[12]; // [esp+24h] [ebp-7Ch] BYREF
  Ray_t ray; // [esp+30h] [ebp-70h] BYREF
  CTraceFilterNav traceFilter; // [esp+88h] [ebp-18h]
  CAI_BaseNPC *retaddr; // [esp+A0h] [ebp+0h]

  traceFilter.m_pExtraShouldHitCheckFunction = a2;
  traceFilter.m_pProber = retaddr;
  v13 = a4;
  v12 = a3;
  CTraceFilterNav::CTraceFilterNav(
    this: (CTraceFilterNav *)(&ray.m_IsSwept + 7),
    pProber: this->m_pOuter,
    bIgnoreTransientEntities: this->m_bIgnoreTransientEntities,
    passedict: this->m_pOuter,
    collisionGroup: this->m_pOuter->m_CollisionGroup.m_Value,
    bAllowPlayerAvoid: true);
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v14, start: vecStart, end: vecEnd, mins: hullMin, maxs: hullMax);
  if ( this->m_pTraceListData == nullptr
    || ((unsigned __int8 (__thiscall *)(ITraceListData *, int, int))this->m_pTraceListData->IsEmpty)(
         a1: this->m_pTraceListData,
         a2: a3,
         a3: v13) != 0 )
  {
    v11 = pResult;
    ((void (__thiscall *)(IEngineTrace *, _BYTE *, unsigned int, bool *, CGameTrace *, int, int))enginetrace->TraceRay)(
      a1: enginetrace,
      a2: v14,
      a3: mask,
      a4: &ray.m_IsSwept + 7,
      a5: pResult,
      a6: v12,
      a7: v13);
  }
  else
  {
    v11 = pResult;
    ((void (__thiscall *)(IEngineTrace *, _BYTE *, ITraceListData *, unsigned int, bool *, CGameTrace *, int, int))enginetrace->TraceRayAgainstLeafAndEntityList)(
      a1: enginetrace,
      a2: v14,
      a3: this->m_pTraceListData,
      a4: mask,
      a5: &ray.m_IsSwept + 7,
      a6: pResult,
      a7: v12,
      a8: v13);
  }
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: &v11->startpos,
      vecAbsEnd: &v11->endpos,
      r: 255,
      g: 255,
      b: 0,
      test: true,
      duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1005DF40
// Name: public: void CAI_MoveProbe::TraceHull(class Vector const __near &,class Vector const __near &,unsigned int,class CGameTrace __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAI_MoveProbe::TraceHull(
        CAI_MoveProbe *this@<ecx>,
        int a2@<edi>,
        const Vector *vecStart,
        const Vector *vecEnd,
        unsigned int mask,
        CGameTrace *pResult)
{
  const Vector *v7; // eax
  const Vector *v8; // [esp-Ch] [ebp-10h]
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v8 = this->m_pOuter->m_Collision.OBBMaxs(this: &this->m_pOuter->m_Collision);
  v7 = this->m_pOuter->m_Collision.OBBMins(this: &this->m_pOuter->m_Collision);
  CAI_MoveProbe::TraceHull(
    this,
    a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
    a3: a2,
    a4: (int)this,
    vecStart,
    vecEnd,
    hullMin: v7,
    hullMax: v8,
    mask,
    pResult);
}

//------------------------------------------------------------------------------
// Address: 0x1005DF90
// Name: private: void CAI_MoveProbe::SetupCheckStepTraceListData(struct CAI_MoveProbe::CheckStepArgs_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAI_MoveProbe::SetupCheckStepTraceListData(
        CAI_MoveProbe *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        const CAI_MoveProbe::CheckStepArgs_t *args)
{
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ecx
  int v6; // eax
  __int64 v7; // xmm0_8
  CAI_BaseNPC *m_pOuter; // ecx
  CBaseEntity::NetworkVar_m_Collision_vtbl *v9; // edx
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  int v11; // eax
  float v12; // ecx
  bool v13; // zf
  float stepHeight; // xmm1_4
  float v15; // xmm0_4
  float minStepLanding; // xmm0_4
  float v17; // xmm1_4
  float z; // xmm0_4
  _BYTE v20[12]; // [esp-Ch] [ebp-8Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-80h]
  Vector v22; // [esp+50h] [ebp-30h] BYREF
  Vector vecEnd; // [esp+5Ch] [ebp-24h] BYREF
  Vector hullMax; // [esp+68h] [ebp-18h] BYREF
  Vector hullMin; // [esp+74h] [ebp-Ch]
  float retaddr; // [esp+80h] [ebp+0h]

  hullMin.x = a2;
  hullMin.y = retaddr;
  if ( ai_moveprobe_usetracelist.m_pParent != nullptr && ai_moveprobe_usetracelist.m_pParent->m_Value.m_nValue != 0 )
  {
    p_m_Collision = &this->m_pOuter->m_Collision;
    ray.m_Extents.y = 0.0;
    v6 = ((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int))p_m_Collision->OBBMins)(
           a1: p_m_Collision,
           a2: a3);
    v7 = *(_QWORD *)v6;
    m_pOuter = this->m_pOuter;
    v9 = m_pOuter->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
    hullMax.z = *(float *)(v6 + 8);
    OBBMaxs = v9->OBBMaxs;
    *(_QWORD *)&hullMax.x = v7;
    v11 = (int)OBBMaxs(this: &m_pOuter->m_Collision);
    v12 = *(float *)(v11 + 8);
    v13 = args->groundTest == STEP_DONT_CHECK_GROUND;
    stepHeight = args->stepHeight;
    *(_QWORD *)&vecEnd.x = *(_QWORD *)v11;
    vecEnd.z = (float)(MOVE_HEIGHT_EPSILON + v12) + stepHeight;
    v15 = (float)(hullMax.z - MOVE_HEIGHT_EPSILON) - stepHeight;
    hullMax.z = v15;
    if ( !v13 )
      hullMax.z = v15 - stepHeight;
    minStepLanding = args->minStepLanding;
    vecEnd.x = minStepLanding + vecEnd.x;
    hullMax.x = hullMax.x - minStepLanding;
    vecEnd.y = minStepLanding + vecEnd.y;
    v17 = hullMax.y - minStepLanding;
    z = args->vecStart.z;
    hullMax.y = v17;
    v22.x = (float)(args->stepSize * args->vecStepDir.x) + args->vecStart.x;
    v22.y = (float)(args->vecStepDir.y * args->stepSize) + args->vecStart.y;
    v22.z = z;
    Ray_t::Init(this: (Ray_t *)v20, start: &args->vecStart, end: &v22, mins: &hullMax, maxs: &vecEnd);
    if ( this->m_pTraceListData == nullptr )
      this->m_pTraceListData = enginetrace->AllocTraceListData(this: enginetrace);
    enginetrace->SetupLeafAndEntityListRay(this: enginetrace, a2: (const Ray_t *)v20, a3: this->m_pTraceListData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E110
// Name: private: void CAI_MoveProbe::CheckStepOverLargeCrawl(struct CAI_MoveProbe::CheckStepResult_t __near *,struct CAI_MoveProbe::CheckStepArgs_t const __near &,class Vector const __near &,class Vector const __near &,class CGameTrace const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_MoveProbe::CheckStepOverLargeCrawl(
        CAI_MoveProbe *this,
        CAI_MoveProbe::CheckStepResult_t *pResult,
        const CAI_MoveProbe::CheckStepArgs_t *args,
        const Vector *vecStart,
        const Vector *vecEnd,
        const CGameTrace *blockedTrace)
{
  __int64 v6; // xmm0_8
  float z; // ecx
  CAI_BaseNPC *m_pOuter; // ecx
  CBaseEntity::NetworkVar_m_Collision_vtbl *v10; // eax
  unsigned int collisionMask; // ebx
  float v12; // xmm0_4
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  const Vector *v14; // eax
  CAI_BaseNPC *v15; // ecx
  const Vector *(__thiscall *v16)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  unsigned int v17; // ebx
  const Vector *v18; // eax
  const CGameTrace *v19; // ecx
  float v20; // xmm0_4
  const Vector *v21; // [esp-18h] [ebp-E4h]
  const Vector *v22; // [esp-18h] [ebp-E4h]
  CGameTrace stepTrace; // [esp+0h] [ebp-CCh] BYREF
  CGameTrace upTrace; // [esp+54h] [ebp-78h] BYREF
  Vector vecStepUp; // [esp+A8h] [ebp-24h] BYREF
  Vector vecStepEnd; // [esp+B4h] [ebp-18h] BYREF
  Vector vecStepStart; // [esp+C0h] [ebp-Ch] BYREF
  int savedregs; // [esp+CCh] [ebp+0h] BYREF
  bool bHitCeiling_3; // [esp+E3h] [ebp+17h]

  v6 = *(_QWORD *)&blockedTrace->endpos.x;
  vecStepStart.z = blockedTrace->endpos.z;
  z = vecEnd->z;
  *(_QWORD *)&vecStepStart.x = v6;
  *(_QWORD *)&vecStepEnd.x = *(_QWORD *)&vecEnd->x;
  vecStepEnd.z = z;
  while ( 1 )
  {
    m_pOuter = this->m_pOuter;
    v10 = m_pOuter->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
    collisionMask = args->collisionMask;
    *(_QWORD *)&vecStepUp.x = *(_QWORD *)&vecStepStart.x;
    v12 = args->stepHeight + vecStepStart.z;
    vecStepUp.z = vecStepStart.z;
    OBBMaxs = v10->OBBMaxs;
    vecStepUp.z = v12;
    v21 = OBBMaxs(this: &m_pOuter->m_Collision);
    v14 = this->m_pOuter->m_Collision.OBBMins(this: &this->m_pOuter->m_Collision);
    CAI_MoveProbe::TraceHull(
      this,
      a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
      a3: (int)args,
      a4: (int)this,
      vecStart: &vecStepStart,
      vecEnd: &vecStepUp,
      hullMin: v14,
      hullMax: v21,
      mask: collisionMask,
      pResult: &upTrace);
    bHitCeiling_3 = upTrace.fraction < 1.0;
    v15 = this->m_pOuter;
    v16 = v15->m_Collision.OBBMaxs;
    v17 = args->collisionMask;
    vecStepStart = upTrace.endpos;
    vecStepEnd.z = upTrace.endpos.z;
    v22 = v16(this: &v15->m_Collision);
    v18 = this->m_pOuter->m_Collision.OBBMins(this: &this->m_pOuter->m_Collision);
    CAI_MoveProbe::TraceHull(
      this,
      a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
      a3: (int)args,
      a4: (int)this,
      vecStart: &vecStepStart,
      vecEnd: &vecStepEnd,
      hullMin: v18,
      hullMax: v22,
      mask: v17,
      pResult: &stepTrace);
    if ( stepTrace.fraction == 1.0 )
    {
      pResult->endPoint.x = vecStepEnd.x;
      pResult->endPoint.y = vecStepEnd.y;
      v20 = vecStepEnd.z;
      pResult->bCrawling = true;
      pResult->endPoint.z = v20;
      pResult->pBlocker = nullptr;
      pResult->fStartSolid = blockedTrace->startsolid;
      return;
    }
    if ( bHitCeiling_3 )
      break;
    if ( stepTrace.startsolid )
    {
      v19 = blockedTrace;
      if ( blockedTrace->startsolid )
        goto LABEL_9;
    }
  }
  v19 = blockedTrace;
LABEL_9:
  pResult->bCrawling = false;
  pResult->endPoint = v19->endpos;
  pResult->hitNormal = v19->plane.normal;
  pResult->pBlocker = v19->m_pEnt;
  pResult->fStartSolid = v19->startsolid;
}

//------------------------------------------------------------------------------
// Address: 0x1005E2E0
// Name: public: class CGameTrace __near & CGameTrace::operator=(class CGameTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CGameTrace *__thiscall CGameTrace::operator=(CGameTrace *this, const CGameTrace *__that)
{
  CBaseTrace::operator=(this, __that);
  this->fractionleftsolid = __that->fractionleftsolid;
  this->surface = __that->surface;
  this->hitgroup = __that->hitgroup;
  this->physicsbone = __that->physicsbone;
  this->worldSurfaceIndex = __that->worldSurfaceIndex;
  this->m_pEnt = __that->m_pEnt;
  this->hitbox = __that->hitbox;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005E330
// Name: private: bool CAI_MoveProbe::Confirm3DConnectivity(struct AIMoveTrace_t __near *,unsigned int,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_MoveProbe::Confirm3DConnectivity(
        CAI_MoveProbe *this,
        AIMoveTrace_t *pMoveTrace,
        char flags,
        const Vector *vecDesiredEnd)
{
  double v5; // st7
  int *m_pOuter; // ecx
  double v7; // st7
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v10; // eax
  float v12; // [esp-4h] [ebp-10h]

  if ( (flags & 4) != 0 )
    return 1;
  v12 = NAI_Hull::Height(id: this->m_pOuter->m_eHull) * 0.5;
  v5 = ((double (__thiscall *)(CAI_BaseNPC *))this->m_pOuter->StepHeight)(a1: this->m_pOuter);
  m_pOuter = (int *)this->m_pOuter;
  v7 = v12 <= v5 + 0.1
     ? ((double (__thiscall *)(int *))*(_DWORD *)(*m_pOuter + 1972))(a1: m_pOuter) + 0.1
     : NAI_Hull::Height(id: m_pOuter[418]) * 0.5;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(pMoveTrace->vEndPosition.z - vecDesiredEnd->z) & _mask__AbsFloat_) <= (float)v7 )
    return 1;
  if ( gpGlobals->pEdicts != nullptr
    && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0
    && (m_pUnk = pEdicts->m_pUnk) != nullptr )
  {
    v10 = m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    v10 = nullptr;
  }
  pMoveTrace->pObstruction = v10;
  pMoveTrace->vHitNormal = vec3_origin;
  pMoveTrace->fStatus = AIMR_BLOCKED_WORLD;
  pMoveTrace->flDistObstructed = fsqrt(
                                   (float)((float)(vecDesiredEnd->y - pMoveTrace->vEndPosition.y)
                                         * (float)(vecDesiredEnd->y - pMoveTrace->vEndPosition.y))
                                 + (float)((float)(vecDesiredEnd->x - pMoveTrace->vEndPosition.x)
                                         * (float)(vecDesiredEnd->x - pMoveTrace->vEndPosition.x)));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005E490
// Name: private: void CAI_MoveProbe::FlyMoveLimit(class Vector const __near &,class Vector const __near &,unsigned int,class CBaseEntity const __near *,struct AIMoveTrace_t __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_MoveProbe::FlyMoveLimit(
        CAI_MoveProbe *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vecStart,
        const Vector *vecEnd,
        unsigned int collisionMask,
        const CBaseEntity *pTarget,
        AIMoveTrace_t *pMoveTrace)
{
  int v10; // eax
  const Vector *v11; // eax
  int v12; // eax
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm3_4
  __int128 v16; // xmm0
  _DWORD v18[3]; // [esp-Ch] [ebp-74h] BYREF
  _BYTE tr[92]; // [esp+0h] [ebp-68h] OVERLAPPED
  _DWORD v20[3]; // [esp+5Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+68h] [ebp+0h]

  v20[0] = a2;
  v20[1] = retaddr;
  v10 = ((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->m_pOuter->m_Collision.OBBMaxs)(
          a1: &this->m_pOuter->m_Collision,
          a2: a3,
          a3: a4,
          a4: v18[0],
          a5: v18[1],
          a6: v18[2],
          a7: *(_DWORD *)tr,
          a8: *(_DWORD *)&tr[4],
          a9: *(_DWORD *)&tr[8],
          a10: *(_DWORD *)&tr[12],
          a11: *(_DWORD *)&tr[16],
          a12: *(_DWORD *)&tr[20],
          a13: *(_DWORD *)&tr[24],
          a14: *(_DWORD *)&tr[28],
          a15: *(_DWORD *)&tr[32],
          a16: *(_DWORD *)&tr[36],
          a17: *(_DWORD *)&tr[40],
          a18: *(_DWORD *)&tr[44],
          a19: *(_DWORD *)&tr[48],
          a20: *(_DWORD *)&tr[52],
          a21: *(_DWORD *)&tr[56],
          a22: *(_DWORD *)&tr[60],
          a23: *(_DWORD *)&tr[64],
          a24: *(_DWORD *)&tr[68],
          a25: *(_DWORD *)&tr[72]);
  v11 = (const Vector *)((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int, unsigned int, _DWORD *))this->m_pOuter->m_Collision.OBBMins)(
                          a1: &this->m_pOuter->m_Collision,
                          a2: v10,
                          a3: collisionMask,
                          a4: v18);
  CAI_MoveProbe::TraceHull(
    this,
    a2: (bool (__cdecl *)(IHandleEntity *, int))v20,
    a3: (int)vecEnd,
    a4: (int)this,
    vecStart,
    vecEnd,
    hullMin: v11,
    hullMax: *(const Vector **)&tr[76],
    mask: *(unsigned int *)&tr[80],
    pResult: *(CGameTrace **)&tr[84]);
  if ( *(float *)&tr[32] >= 1.0 )
  {
    pMoveTrace->vEndPosition = *vecEnd;
  }
  else
  {
    v12 = *(_DWORD *)&tr[64];
    if ( *(_DWORD *)&tr[64] != 0 )
    {
      if ( pTarget == *(const CBaseEntity **)&tr[64] )
      {
        pMoveTrace->vEndPosition = *(Vector *)tr;
        return;
      }
      pMoveTrace->pObstruction = *(CBaseEntity **)&tr[64];
      pMoveTrace->vHitNormal.x = vec3_origin.x;
      pMoveTrace->vHitNormal.y = vec3_origin.y;
      *(_DWORD *)&tr[84] = v12;
      pMoveTrace->vHitNormal.z = vec3_origin.z;
      pMoveTrace->fStatus = AIComputeBlockerMoveResult(pBlocker: *(CBaseEntity **)&tr[84]);
    }
    v13 = *(float *)&tr[4];
    v14 = *(float *)&tr[8];
    v15 = *(float *)tr;
    v16 = 0;
    *(float *)&v16 = fsqrt(
                       (float)((float)((float)(vecEnd->y - v13) * (float)(vecEnd->y - v13))
                             + (float)((float)(vecEnd->z - v14) * (float)(vecEnd->z - v14)))
                     + (float)((float)(vecEnd->x - v15) * (float)(vecEnd->x - v15)));
    *(_OWORD *)&tr[76] = v16;
    LODWORD(pMoveTrace->flDistObstructed) = v16;
    pMoveTrace->vEndPosition.x = v15;
    pMoveTrace->vEndPosition.y = v13;
    pMoveTrace->vEndPosition.z = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E600
// Name: private: void CAI_MoveProbe::ClimbMoveLimit(class Vector const __near &,class Vector const __near &,class CBaseEntity const __near *,struct AIMoveTrace_t __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_MoveProbe::ClimbMoveLimit(
        CAI_MoveProbe *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vecStart,
        const Vector *vecEnd,
        const CBaseEntity *pTarget,
        AIMoveTrace_t *pMoveTrace)
{
  CAI_BaseNPC *m_pOuter; // eax
  unsigned int m_nAITraceMask; // edi
  int v11; // eax
  const Vector *v12; // eax
  int v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  __int128 v16; // xmm0
  float v17; // xmm0_4
  _DWORD v20[3]; // [esp-Ch] [ebp-74h] BYREF
  _BYTE tr[92]; // [esp+0h] [ebp-68h] OVERLAPPED
  _DWORD v22[3]; // [esp+5Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+68h] [ebp+0h]

  v22[0] = a2;
  v22[1] = retaddr;
  m_pOuter = this->m_pOuter;
  m_nAITraceMask = m_pOuter->m_nAITraceMask;
  v11 = ((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))m_pOuter->m_Collision.OBBMaxs)(
          a1: &m_pOuter->m_Collision,
          a2: a3,
          a3: a4,
          a4: v20[0],
          a5: v20[1],
          a6: v20[2],
          a7: *(_DWORD *)tr,
          a8: *(_DWORD *)&tr[4],
          a9: *(_DWORD *)&tr[8],
          a10: *(_DWORD *)&tr[12],
          a11: *(_DWORD *)&tr[16],
          a12: *(_DWORD *)&tr[20],
          a13: *(_DWORD *)&tr[24],
          a14: *(_DWORD *)&tr[28],
          a15: *(_DWORD *)&tr[32],
          a16: *(_DWORD *)&tr[36],
          a17: *(_DWORD *)&tr[40],
          a18: *(_DWORD *)&tr[44],
          a19: *(_DWORD *)&tr[48],
          a20: *(_DWORD *)&tr[52],
          a21: *(_DWORD *)&tr[56],
          a22: *(_DWORD *)&tr[60],
          a23: *(_DWORD *)&tr[64],
          a24: *(_DWORD *)&tr[68],
          a25: *(_DWORD *)&tr[72]);
  v12 = (const Vector *)((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int, unsigned int, _DWORD *))this->m_pOuter->m_Collision.OBBMins)(
                          a1: &this->m_pOuter->m_Collision,
                          a2: v11,
                          a3: m_nAITraceMask,
                          a4: v20);
  CAI_MoveProbe::TraceHull(
    this,
    a2: (bool (__cdecl *)(IHandleEntity *, int))v22,
    a3: (int)vecEnd,
    a4: (int)this,
    vecStart,
    vecEnd,
    hullMin: v12,
    hullMax: *(const Vector **)&tr[76],
    mask: *(unsigned int *)&tr[80],
    pResult: *(CGameTrace **)&tr[84]);
  if ( *(float *)&tr[32] < 1.0 )
  {
    v13 = *(_DWORD *)&tr[64];
    if ( *(const CBaseEntity **)&tr[64] != pTarget )
    {
      pMoveTrace->pObstruction = *(CBaseEntity **)&tr[64];
      pMoveTrace->vHitNormal.x = vec3_origin.x;
      pMoveTrace->vHitNormal.y = vec3_origin.y;
      *(_DWORD *)&tr[84] = v13;
      pMoveTrace->vHitNormal.z = vec3_origin.z;
      pMoveTrace->fStatus = AIComputeBlockerMoveResult(pBlocker: *(CBaseEntity **)&tr[84]);
      v14 = vecEnd->y - vecStart->y;
      v15 = vecEnd->z - vecStart->z;
      v16 = 0;
      *(float *)&v16 = fsqrt(
                         (float)((float)(v14 * v14) + (float)(v15 * v15))
                       + (float)((float)(vecEnd->x - vecStart->x) * (float)(vecEnd->x - vecStart->x)));
      *(_OWORD *)&tr[76] = v16;
      v17 = (float)(1.0 - *(float *)&tr[32]) * *(float *)&v16;
      if ( v17 <= 0.001 )
        v17 = 0.001;
      pMoveTrace->flDistObstructed = v17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E730
// Name: public: bool CAI_MoveProbe::FloorPoint(class Vector const __near &,unsigned int,float,float,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
bool __userpurge CAI_MoveProbe::FloorPoint@<al>(
        CAI_MoveProbe *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vecStart,
        float collisionMask,
        float flStartZ,
        float flEndZ,
        Vector *pVecResult)
{
  int v10; // eax
  __int64 v11; // xmm0_8
  CAI_BaseNPC *m_pOuter; // ecx
  CBaseEntity::NetworkVar_m_Collision_vtbl *v13; // edx
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  int v15; // edi
  float x; // xmm1_4
  float y; // xmm2_4
  float v18; // xmm3_4
  char x_high; // cl
  CAI_BaseNPC *v20; // eax
  float v21; // xmm1_4
  __int128 v22; // xmm0
  _DWORD v25[3]; // [esp-Ch] [ebp-B4h] BYREF
  _BYTE trace[92]; // [esp+0h] [ebp-A8h] OVERLAPPED
  int v27; // [esp+5Ch] [ebp-4Ch]
  int v28; // [esp+60h] [ebp-48h]
  int v29; // [esp+64h] [ebp-44h]
  Vector v30; // [esp+68h] [ebp-40h] BYREF
  Vector maxs; // [esp+74h] [ebp-34h] BYREF
  Vector vecDown; // [esp+80h] [ebp-28h] BYREF
  Vector mins; // [esp+8Ch] [ebp-1Ch] BYREF
  Vector vecUp; // [esp+98h] [ebp-10h] BYREF
  float retaddr; // [esp+A8h] [ebp+0h]

  vecUp.y = a2;
  vecUp.z = retaddr;
  v10 = ((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->m_pOuter->m_Collision.OBBMins)(
          a1: &this->m_pOuter->m_Collision,
          a2: a3,
          a3: a4,
          a4: v25[0],
          a5: v25[1],
          a6: v25[2],
          a7: *(_DWORD *)trace,
          a8: *(_DWORD *)&trace[4],
          a9: *(_DWORD *)&trace[8],
          a10: *(_DWORD *)&trace[12],
          a11: *(_DWORD *)&trace[16],
          a12: *(_DWORD *)&trace[20],
          a13: *(_DWORD *)&trace[24],
          a14: *(_DWORD *)&trace[28],
          a15: *(_DWORD *)&trace[32],
          a16: *(_DWORD *)&trace[36],
          a17: *(_DWORD *)&trace[40],
          a18: *(_DWORD *)&trace[44],
          a19: *(_DWORD *)&trace[48],
          a20: *(_DWORD *)&trace[52],
          a21: *(_DWORD *)&trace[56],
          a22: *(_DWORD *)&trace[60],
          a23: *(_DWORD *)&trace[64],
          a24: *(_DWORD *)&trace[68],
          a25: *(_DWORD *)&trace[72],
          a26: *(_DWORD *)&trace[76],
          a27: *(_DWORD *)&trace[80],
          a28: *(_DWORD *)&trace[84],
          a29: *(_DWORD *)&trace[88],
          a30: v27,
          a31: v28,
          a32: v29,
          a33: LODWORD(v30.x),
          a34: LODWORD(v30.y),
          a35: LODWORD(v30.z),
          a36: LODWORD(maxs.x),
          a37: LODWORD(maxs.y),
          a38: LODWORD(maxs.z),
          a39: LODWORD(vecDown.x),
          a40: LODWORD(vecDown.y),
          a41: LODWORD(vecDown.z),
          a42: LODWORD(mins.x),
          a43: LODWORD(mins.y),
          a44: LODWORD(mins.z));
  v11 = *(_QWORD *)v10;
  m_pOuter = this->m_pOuter;
  v13 = m_pOuter->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
  vecDown.z = *(float *)(v10 + 8);
  OBBMaxs = v13->OBBMaxs;
  *(_QWORD *)&vecDown.x = v11;
  v15 = (int)OBBMaxs(this: &m_pOuter->m_Collision);
  *(float *)&v11 = this->m_pOuter->m_Collision.OBBMaxs(this: &this->m_pOuter->m_Collision)->x;
  LODWORD(mins.z) = v25;
  mins.y = collisionMask;
  LODWORD(v30.x) = v11;
  x = vecStart->x;
  y = vecStart->y;
  v30.y = *(float *)(v15 + 4);
  *(float *)&v11 = vecDown.z;
  LODWORD(mins.x) = &v30;
  LODWORD(vecDown.z) = &vecDown;
  LODWORD(v30.z) = v11;
  v18 = (float)(vecStart->z + flStartZ) + MOVE_HEIGHT_EPSILON;
  *(float *)&v11 = vecStart->z + flEndZ;
  maxs.x = x;
  maxs.y = y;
  LODWORD(maxs.z) = v11;
  CAI_MoveProbe::TraceHull(
    this,
    a2: (bool (__cdecl *)(IHandleEntity *, int))&vecUp.y,
    a3: (int)vecStart,
    a4: (int)this,
    vecStart: &mins,
    vecEnd: &maxs,
    hullMin: &vecDown,
    hullMax: (const Vector *)LODWORD(x),
    mask: LODWORD(y),
    pResult: (CGameTrace *)LODWORD(v18));
  x_high = 0;
  HIBYTE(vecUp.x) = 0;
  if ( trace[43] != 0 )
  {
    if ( *(_DWORD *)&trace[64] != 0
      && (*(_BYTE *)(*(_DWORD *)&trace[64] + 214) == 6
       || (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&trace[64] + 292))(a1: *(_DWORD *)&trace[64]) != 0) )
    {
      v20 = this->m_pOuter;
      v21 = vecStart->y - v20->m_vecOrigin.m_Value.y;
      v22 = 0;
      *(float *)&v22 = fsqrt(
                         (float)((float)(v21 * v21)
                               + (float)((float)(vecStart->z - v20->m_vecOrigin.m_Value.z)
                                       * (float)(vecStart->z - v20->m_vecOrigin.m_Value.z)))
                       + (float)((float)(vecStart->x - v20->m_vecOrigin.m_Value.x)
                               * (float)(vecStart->x - v20->m_vecOrigin.m_Value.x)));
      *(_OWORD *)&trace[76] = v22;
      if ( *(float *)&v22 < 0.1 )
        HIBYTE(vecUp.x) = 1;
    }
    CAI_MoveProbe::TraceHull(
      this,
      a2: (bool (__cdecl *)(IHandleEntity *, int))&vecUp.y,
      a3: (int)vecStart,
      a4: (int)this,
      vecStart: &mins,
      vecEnd: &maxs,
      hullMin: &vecDown,
      hullMax: &v30,
      mask: LODWORD(collisionMask),
      pResult: COERCE_CGAMETRACE_(vecStart->z + MOVE_HEIGHT_EPSILON));
    x_high = HIBYTE(vecUp.x);
  }
  if ( *(float *)&trace[32] == 1.0 || trace[42] != 0 || x_high != 0 && trace[43] != 0 )
  {
    *pVecResult = *vecStart;
    return x_high != 0;
  }
  else
  {
    *pVecResult = *(Vector *)trace;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E970
// Name: public: bool CAI_MoveProbe::CheckStandPosition(class Vector const __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_MoveProbe::CheckStandPosition(
        CAI_MoveProbe *this,
        const Vector *vecStart,
        unsigned int collisionMask)
{
  CAI_BaseNPC *m_pOuter; // ecx
  float (__thiscall *StepHeight)(CAI_BaseNPC *); // edx
  float x; // xmm0_4
  CAI_BaseNPC *v9; // ecx
  double StepDownMultiplier; // st7
  CAI_BaseNPC *v11; // ecx
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  int v13; // eax
  __int64 v14; // xmm0_8
  CAI_BaseNPC *v15; // ecx
  CBaseEntity::NetworkVar_m_Collision_vtbl *v16; // edx
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  int v18; // eax
  float v19; // ecx
  float v20; // xmm1_4
  float y; // xmm0_4
  const Vector *HullMaxs; // eax
  int m_Value; // eax
  CGameTrace trace2; // [esp+4h] [ebp-100h] BYREF
  CGameTrace trace1; // [esp+58h] [ebp-ACh] BYREF
  float z; // [esp+ACh] [ebp-58h]
  Vector contactMax; // [esp+B0h] [ebp-54h] BYREF
  Vector vecUp; // [esp+BCh] [ebp-48h] BYREF
  Vector testMax; // [esp+C8h] [ebp-3Ch] BYREF
  Vector vecDown; // [esp+D4h] [ebp-30h] BYREF
  Vector vHullBottomCenter; // [esp+E0h] [ebp-24h] BYREF
  Vector vHullMaxs; // [esp+ECh] [ebp-18h] BYREF
  Vector vHullMins; // [esp+F8h] [ebp-Ch]
  int savedregs; // [esp+104h] [ebp+0h] BYREF
  float vecStarta; // [esp+10Ch] [ebp+8h]

  if ( (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x80u) != 0
    || ai_strong_optimizations_no_checkstand.m_pParent != nullptr
    && ai_strong_optimizations_no_checkstand.m_pParent->m_Value.m_nValue != 0 )
  {
    return true;
  }
  m_pOuter = this->m_pOuter;
  StepHeight = m_pOuter->StepHeight;
  vecUp.x = vecStart->x;
  vecUp.y = vecStart->y;
  vecUp.z = vecStart->z + 0.1;
  vecStarta = StepHeight(this: m_pOuter);
  x = vecStart->x;
  v9 = this->m_pOuter;
  z = vecStart->z;
  vecDown.x = x;
  vecDown.y = vecStart->y;
  StepDownMultiplier = CAI_BaseNPC::GetStepDownMultiplier(this: v9);
  v11 = this->m_pOuter;
  OBBMins = v11->m_Collision.OBBMins;
  vecDown.z = z - StepDownMultiplier * vecStarta;
  v13 = (int)OBBMins(this: &v11->m_Collision);
  v14 = *(_QWORD *)v13;
  v15 = this->m_pOuter;
  v16 = v15->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
  vHullMins.z = *(float *)(v13 + 8);
  OBBMaxs = v16->OBBMaxs;
  *(_QWORD *)&vHullMins.x = v14;
  v18 = (int)OBBMaxs(this: &v15->m_Collision);
  v19 = *(float *)(v18 + 8);
  *(_QWORD *)&vHullMaxs.x = *(_QWORD *)v18;
  v20 = vHullMaxs.x;
  y = vHullMaxs.y;
  vHullMaxs.z = v19;
  if ( vec3_origin.x == vHullMaxs.x
    && vec3_origin.y == vHullMaxs.y
    && vec3_origin.z == vHullMaxs.z
    && vHullMaxs.x == vHullMins.x
    && vHullMaxs.y == vHullMins.y
    && vHullMaxs.z == vHullMins.z )
  {
    vHullMins = *CAI_Component::GetHullMins(this);
    HullMaxs = CAI_Component::GetHullMaxs(this);
    v20 = HullMaxs->x;
    y = HullMaxs->y;
  }
  m_Value = this->m_pOuter->m_spawnflags.m_Value;
  contactMax.x = (float)(v20 * 0.75) + (float)(vHullMins.x * 0.25);
  vHullMaxs.x = (float)(v20 * 0.25) + (float)(vHullMins.x * 0.75);
  vHullMaxs.y = (float)(y * 0.25) + (float)(vHullMins.y * 0.75);
  contactMax.y = (float)(y * 0.75) + (float)(vHullMins.y * 0.25);
  vHullMaxs.z = vHullMins.z;
  contactMax.z = vHullMins.z;
  if ( (m_Value & 0x10) != 0 )
  {
    CAI_MoveProbe::TraceHull(
      this,
      a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
      a3: (int)vecStart,
      a4: (int)this,
      vecStart: &vecUp,
      vecEnd: &vecDown,
      hullMin: &vHullMaxs,
      hullMax: &contactMax,
      mask: collisionMask,
      pResult: &trace1);
    if ( trace1.fraction != 1.0 && this->m_pOuter->CanStandOn_2(this: this->m_pOuter, a2: trace1.m_pEnt) )
      return true;
  }
  else
  {
    vHullBottomCenter.x = 0.0;
    vHullBottomCenter.y = 0.0;
    vHullBottomCenter.z = vHullMins.z;
    CAI_MoveProbe::TraceHull(
      this,
      a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
      a3: collisionMask,
      a4: (int)this,
      vecStart: &vecUp,
      vecEnd: &vecDown,
      hullMin: &vHullMaxs,
      hullMax: &vHullBottomCenter,
      mask: collisionMask,
      pResult: &trace1);
    if ( trace1.fraction != 1.0 && this->m_pOuter->CanStandOn_2(this: this->m_pOuter, a2: trace1.m_pEnt) )
    {
      CAI_MoveProbe::TraceHull(
        this,
        a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
        a3: collisionMask,
        a4: (int)this,
        vecStart: &vecUp,
        vecEnd: &vecDown,
        hullMin: &vHullBottomCenter,
        hullMax: &contactMax,
        mask: collisionMask,
        pResult: &trace2);
      if ( trace2.fraction != 1.0
        && (trace1.m_pEnt == trace2.m_pEnt || this->m_pOuter->CanStandOn_2(this: this->m_pOuter, a2: trace2.m_pEnt)) )
      {
        return true;
      }
    }
    vHullBottomCenter.x = vHullMaxs.x;
    vHullBottomCenter.y = 0.0;
    testMax.x = 0.0;
    vHullBottomCenter.z = vHullMins.z;
    testMax.y = contactMax.y;
    testMax.z = vHullMins.z;
    CAI_MoveProbe::TraceHull(
      this,
      a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
      a3: collisionMask,
      a4: (int)this,
      vecStart: &vecUp,
      vecEnd: &vecDown,
      hullMin: &vHullBottomCenter,
      hullMax: &testMax,
      mask: collisionMask,
      pResult: &trace1);
    if ( trace1.fraction != 1.0 && this->m_pOuter->CanStandOn_2(this: this->m_pOuter, a2: trace1.m_pEnt) )
    {
      vHullBottomCenter.y = vHullMaxs.y;
      vHullBottomCenter.x = 0.0;
      vHullBottomCenter.z = vHullMins.z;
      testMax.x = contactMax.x;
      testMax.y = 0.0;
      testMax.z = vHullMins.z;
      CAI_MoveProbe::TraceHull(
        this,
        a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
        a3: collisionMask,
        a4: (int)this,
        vecStart: &vecUp,
        vecEnd: &vecDown,
        hullMin: &vHullBottomCenter,
        hullMax: &testMax,
        mask: collisionMask,
        pResult: &trace2);
      if ( trace2.fraction != 1.0 )
      {
        if ( trace1.m_pEnt != trace2.m_pEnt )
          return this->m_pOuter->CanStandOn_2(this: this->m_pOuter, a2: trace2.m_pEnt);
        return true;
      }
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1005ED90
// Name: private: bool CAI_MoveProbe::CheckStep(struct CAI_MoveProbe::CheckStepArgs_t const __near &,struct CAI_MoveProbe::CheckStepResult_t __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_MoveProbe::CheckStep(
        CAI_MoveProbe *this,
        const CAI_MoveProbe::CheckStepArgs_t *args,
        CBaseEntity *pResult)
{
  unsigned int v6; // eax
  float x; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  double z; // st7
  float v11; // xmm2_4
  const Vector *v12; // eax
  const Vector *v14; // eax
  const Vector *v15; // eax
  float v16; // xmm0_4
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ecx
  const Vector *v18; // eax
  const Vector *v19; // eax
  float v20; // xmm2_4
  float minStepLanding; // xmm0_4
  const Vector *v22; // eax
  const Vector *v23; // eax
  const Vector *v24; // eax
  const Vector *v25; // eax
  CBaseEntity *m_pEnt; // ecx
  float v27; // xmm0_4
  float v28; // xmm1_4
  CAI_BaseNPC *m_pOuter; // ecx
  const Vector *v30; // eax
  float v31; // xmm1_4
  float y; // xmm1_4
  const Vector *v33; // eax
  edict_t *v34; // eax
  const Vector *v35; // eax
  CBaseEntity *GroundEntity; // eax
  CWorld *v37; // edx
  bool v38; // al
  float v39; // xmm0_4
  const Vector *size; // [esp+4h] [ebp-150h]
  const Vector *sizea; // [esp+4h] [ebp-150h]
  const Vector *sizeb; // [esp+4h] [ebp-150h]
  const Vector *sizec; // [esp+4h] [ebp-150h]
  const Vector *sized; // [esp+4h] [ebp-150h]
  const Vector *v45; // [esp+10h] [ebp-144h]
  const Vector *v46; // [esp+10h] [ebp-144h]
  const Vector *v47; // [esp+10h] [ebp-144h]
  CGameTrace landingTrace; // [esp+28h] [ebp-12Ch] BYREF
  CGameTrace stepTrace; // [esp+7Ch] [ebp-D8h] BYREF
  CGameTrace trace; // [esp+D0h] [ebp-84h] BYREF
  Vector mins; // [esp+124h] [ebp-30h] BYREF
  Vector stepEndWithLanding; // [esp+130h] [ebp-24h] BYREF
  Vector stepEnd; // [esp+13Ch] [ebp-18h] BYREF
  Vector stepStart; // [esp+148h] [ebp-Ch] BYREF
  int savedregs; // [esp+154h] [ebp+0h] BYREF
  unsigned int collisionMask; // [esp+15Ch] [ebp+8h]
  CBaseEntity *pFloor; // [esp+160h] [ebp+Ch]

  v6 = args->collisionMask;
  x = args->vecStart.x;
  v8 = args->vecStepDir.x * args->stepSize;
  v9 = (float)(args->vecStepDir.y * args->stepSize) + args->vecStart.y;
  pResult->__vftable = (CBaseEntity_vtbl *)LODWORD(args->vecStart.x);
  *(float *)&pResult->m_pfnMoveDone = args->vecStart.y;
  z = args->vecStart.z;
  LOBYTE(pResult->m_Network.m_pPev) = 0;
  *(float *)&pResult->m_pfnThink = z;
  *(Vector *)&pResult->m_Network.__vftable = vec3_origin;
  *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode = 0;
  LOBYTE(pResult->m_Network.m_PVSInfo.m_pClusters) = 0;
  stepStart.x = args->vecStart.x;
  stepStart.y = args->vecStart.y;
  v11 = MOVE_HEIGHT_EPSILON + args->vecStart.z;
  collisionMask = v6;
  stepStart.z = v11;
  stepEnd.x = v8 + x;
  stepEnd.y = v9;
  stepEnd.z = v11;
  if ( g_bAIDebugStep )
  {
    NDebugOverlay::Line(origin: &stepStart, target: &stepEnd, r: 255, g: 255, b: 255, noDepthTest: true, duration: 5.0);
    NDebugOverlay::Cross3D(position: &stepEnd, size: 32.0, r: 255, g: 255, b: 255, noDepthTest: true, flDuration: 5.0);
  }
  v45 = this->m_pOuter->m_Collision.OBBMaxs(this: &this->m_pOuter->m_Collision);
  v12 = this->m_pOuter->m_Collision.OBBMins(this: &this->m_pOuter->m_Collision);
  CAI_MoveProbe::TraceHull(
    this,
    a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
    a3: (int)args,
    a4: (int)this,
    vecStart: &stepStart,
    vecEnd: &stepEnd,
    hullMin: v12,
    hullMax: v45,
    mask: collisionMask,
    pResult: &trace);
  if ( !trace.startsolid && trace.fraction >= 1.0 )
    goto LABEL_35;
  if ( (args->flags & 0x10) != 0 )
  {
    CAI_MoveProbe::CheckStepOverLargeCrawl(
      this,
      (CAI_MoveProbe::CheckStepResult_t *)pResult,
      args,
      vecStart: &stepStart,
      vecEnd: &stepEnd,
      blockedTrace: &trace);
    return *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode == 0;
  }
  if ( trace.startsolid )
  {
    v16 = args->stepHeight + stepStart.z;
  }
  else
  {
    if ( g_bAIDebugStep )
    {
      size = this->m_pOuter->m_Collision.OBBMaxs(this: &this->m_pOuter->m_Collision);
      v14 = (const Vector *)((int (*)(void))this->m_pOuter->m_Collision.OBBMins)();
      NDebugOverlay::Box(origin: &trace.endpos, mins: v14, maxs: size, r: 64, g: 64, b: 64, a: 0, flDuration: 5.0);
    }
    stepStart = trace.endpos;
    stepEndWithLanding = trace.endpos;
    stepEndWithLanding.z = args->stepHeight + trace.endpos.z;
    CAI_MoveProbe::TraceHull(
      this,
      a2: (int)args,
      vecStart: &stepStart,
      vecEnd: &stepEndWithLanding,
      mask: collisionMask,
      pResult: &stepTrace);
    if ( g_bAIDebugStep )
    {
      sizea = this->m_pOuter->m_Collision.OBBMaxs(this: &this->m_pOuter->m_Collision);
      v15 = (const Vector *)((int (*)(void))this->m_pOuter->m_Collision.OBBMins)();
      NDebugOverlay::Box(origin: &stepTrace.endpos, mins: v15, maxs: sizea, r: 96, g: 96, b: 96, a: 0, flDuration: 5.0);
    }
    stepStart.x = stepTrace.endpos.x;
    stepStart.y = stepTrace.endpos.y;
    v16 = stepTrace.endpos.z;
  }
  p_m_Collision = &this->m_pOuter->m_Collision;
  stepStart.z = v16;
  stepEnd.z = v16;
  v46 = p_m_Collision->OBBMaxs(this: p_m_Collision);
  v18 = this->m_pOuter->m_Collision.OBBMins(this: &this->m_pOuter->m_Collision);
  CAI_MoveProbe::TraceHull(
    this,
    a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
    a3: (int)args,
    a4: (int)this,
    vecStart: &stepStart,
    vecEnd: &stepEnd,
    hullMin: v18,
    hullMax: v46,
    mask: collisionMask,
    pResult: &stepTrace);
  if ( stepTrace.startsolid || stepTrace.fraction <= 0.01 )
  {
    if ( trace.startsolid )
    {
      m_pEnt = trace.m_pEnt;
      v27 = trace.plane.normal.x;
      LOBYTE(pResult->m_Network.m_pPev) = 1;
      *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode = m_pEnt;
      *(float *)&pResult->m_Network.__vftable = v27;
      pResult->m_Network.__vftable = (IEventRegisterCallback_vtbl *)LODWORD(trace.plane.normal.y);
      pResult->m_Network.m_pOuter = (CBaseEntity *)LODWORD(trace.plane.normal.z);
      return false;
    }
    goto LABEL_30;
  }
  if ( g_bAIDebugStep )
  {
    sizeb = CAI_Component::WorldAlignMaxs(this);
    v19 = CAI_Component::WorldAlignMins(this);
    NDebugOverlay::Box(origin: &stepTrace.endpos, mins: v19, maxs: sizeb, r: 128, g: 128, b: 128, a: 0, flDuration: 5.0);
  }
  v20 = args->minStepLanding * args->minStepLanding;
  if ( v20 <= (float)((float)((float)(stepEnd.y - stepStart.y) * (float)(stepEnd.y - stepStart.y))
                    + (float)((float)(stepEnd.x - stepStart.x) * (float)(stepEnd.x - stepStart.x))) )
  {
    if ( v20 > (float)((float)((float)(stepTrace.endpos.y - stepStart.y) * (float)(stepTrace.endpos.y - stepStart.y))
                     + (float)((float)(stepTrace.endpos.x - stepStart.x) * (float)(stepTrace.endpos.x - stepStart.x))) )
    {
      if ( g_bAIDebugStep )
      {
        v24 = CAI_Component::WorldAlignMaxs(this);
        mins.x = v24->x;
        mins.y = v24->y;
        mins.z = v24->z + 0.1;
        v25 = CAI_Component::WorldAlignMins(this);
        stepEndWithLanding.x = v25->x;
        stepEndWithLanding.y = v25->y;
        stepEndWithLanding.z = v25->z + 0.1;
        NDebugOverlay::Box(
          origin: &stepTrace.endpos,
          mins: &stepEndWithLanding,
          maxs: &mins,
          r: 255,
          g: 0,
          b: 0,
          a: 0,
          flDuration: 5.0);
      }
      goto LABEL_30;
    }
  }
  else
  {
    minStepLanding = args->minStepLanding;
    stepEndWithLanding.x = (float)(args->vecStepDir.x * minStepLanding) + stepStart.x;
    stepEndWithLanding.y = (float)(args->vecStepDir.y * minStepLanding) + stepStart.y;
    stepEndWithLanding.z = (float)(args->vecStepDir.z * minStepLanding) + stepStart.z;
    CAI_MoveProbe::TraceHull(
      this,
      a2: (int)args,
      vecStart: &stepStart,
      vecEnd: &stepEndWithLanding,
      mask: collisionMask,
      pResult: &landingTrace);
    if ( landingTrace.fraction < 1.0 )
    {
      if ( g_bAIDebugStep )
      {
        v22 = CAI_Component::WorldAlignMaxs(this);
        stepEndWithLanding.x = v22->x;
        stepEndWithLanding.y = v22->y;
        stepEndWithLanding.z = v22->z + 0.1;
        v23 = CAI_Component::WorldAlignMins(this);
        mins.x = v23->x;
        mins.y = v23->y;
        mins.z = v23->z + 0.1;
        NDebugOverlay::Box(
          origin: &landingTrace.endpos,
          &mins,
          maxs: &stepEndWithLanding,
          r: 255,
          g: 0,
          b: 0,
          a: 0,
          flDuration: 5.0);
      }
      if ( landingTrace.m_pEnt != nullptr )
        *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode = landingTrace.m_pEnt;
      goto LABEL_30;
    }
  }
  CGameTrace::operator=(this: &trace, __that: &stepTrace);
LABEL_30:
  if ( trace.fraction < 1.0 )
  {
    if ( *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode == 0 )
      *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode = trace.m_pEnt;
    *(Vector *)&pResult->m_Network.__vftable = trace.plane.normal;
  }
  stepEnd = trace.endpos;
LABEL_35:
  if ( LOBYTE(pResult->m_Network.m_PVSInfo.m_pClusters) != 0 )
    goto LABEL_70;
  v28 = args->vecStart.z;
  m_pOuter = this->m_pOuter;
  stepStart = stepEnd;
  stepEnd.z = (float)(v28 - (float)(args->stepDownMultiplier * args->stepHeight)) - MOVE_HEIGHT_EPSILON;
  v47 = m_pOuter->m_Collision.OBBMaxs(this: &m_pOuter->m_Collision);
  v30 = this->m_pOuter->m_Collision.OBBMins(this: &this->m_pOuter->m_Collision);
  CAI_MoveProbe::TraceHull(
    this,
    a2: (bool (__cdecl *)(IHandleEntity *, int))&savedregs,
    a3: (int)args,
    a4: (int)this,
    vecStart: &stepStart,
    vecEnd: &stepEnd,
    hullMin: v30,
    hullMax: v47,
    mask: collisionMask,
    pResult: &trace);
  if ( (args->flags & 0x10) != 0 )
  {
    if ( trace.fraction >= 1.0 )
    {
      v31 = args->vecStart.x;
      stepStart.x = trace.endpos.x;
      stepStart.y = trace.endpos.y;
      stepEnd.x = v31;
      y = args->vecStart.y;
      stepStart.z = trace.endpos.z;
      stepEnd.y = y;
      stepEnd.z = trace.endpos.z;
      CAI_MoveProbe::TraceHull(
        this,
        a2: (int)args,
        vecStart: &stepStart,
        vecEnd: &stepEnd,
        mask: collisionMask,
        pResult: &landingTrace);
      trace.endpos = landingTrace.endpos;
      LOBYTE(pResult->m_Network.m_PVSInfo.m_pClusters) = 1;
    }
    if ( (args->flags & 0x10) != 0 )
      goto LABEL_70;
  }
  if ( trace.fraction == 1.0 )
  {
    if ( g_bAIDebugStep )
    {
      sizec = CAI_Component::WorldAlignMaxs(this);
      v33 = CAI_Component::WorldAlignMins(this);
      NDebugOverlay::Box(origin: &trace.endpos, mins: v33, maxs: sizec, r: 255, g: 0, b: 0, a: 0, flDuration: 5.0);
    }
    if ( CBaseEntity::GetGroundEntity(this: this->m_pOuter) != nullptr )
    {
      *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode = CBaseEntity::GetGroundEntity(this: this->m_pOuter);
    }
    else
    {
      v34 = INDEXENT(iEdictNum: 0);
      *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode = GetContainingEntity(pent: v34);
    }
    return false;
  }
  if ( g_bAIDebugStep )
  {
    sized = CAI_Component::WorldAlignMaxs(this);
    v35 = CAI_Component::WorldAlignMins(this);
    NDebugOverlay::Box(origin: &trace.endpos, mins: v35, maxs: sized, r: 160, g: 160, b: 160, a: 0, flDuration: 5.0);
  }
  if ( (args->flags & 0x10) != 0 )
    goto LABEL_70;
  pFloor = trace.m_pEnt;
  GroundEntity = CBaseEntity::GetGroundEntity(this: this->m_pOuter);
  v37 = (CWorld *)pFloor;
  if ( pFloor != GroundEntity )
  {
    if ( !this->m_pOuter->CanStandOn_2(this: this->m_pOuter, a2: pFloor) )
    {
      if ( g_bAIDebugStep )
        NDebugOverlay::Cross3D(
          position: &trace.endpos,
          size: 32.0,
          r: 255,
          g: 0,
          b: 0,
          noDepthTest: true,
          flDuration: 5.0);
      *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode = pFloor;
      return false;
    }
    v37 = (CWorld *)pFloor;
  }
  if ( (float)(trace.endpos.z - args->vecStart.z) > args->stepHeight * 0.5 )
  {
    if ( v37 == g_WorldEntity && trace.hitbox > 0 )
    {
LABEL_61:
      if ( COERCE_FLOAT(
             COERCE_UNSIGNED_INT((float)((float)(trace.plane.normal.y * 0.0) + trace.plane.normal.x) + (float)(trace.plane.normal.z * 0.0))
           & _mask__AbsFloat_) > 0.4 )
      {
        *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode = v37;
        if ( g_bAIDebugStep )
          NDebugOverlay::Cross3D(
            position: &trace.endpos,
            size: 32.0,
            r: 0,
            g: 0,
            b: 255,
            noDepthTest: true,
            flDuration: 5.0);
        return false;
      }
      goto LABEL_65;
    }
    if ( __RTDynamicCast(
           inptr: v37,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CPhysicsProp `RTTI Type Descriptor',
           isReference: 0) != nullptr )
    {
      v37 = (CWorld *)pFloor;
      goto LABEL_61;
    }
  }
LABEL_65:
  if ( args->groundTest != STEP_DONT_CHECK_GROUND )
  {
    v38 = CAI_MoveProbe::CheckStandPosition(this, vecStart: &trace.endpos, collisionMask);
    if ( args->groundTest != STEP_ON_INVALID_GROUND && !v38 )
    {
      *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode = pFloor;
      if ( g_bAIDebugStep )
      {
        NDebugOverlay::Cross3D(
          position: &trace.endpos,
          size: 32.0,
          r: 255,
          g: 0,
          b: 255,
          noDepthTest: true,
          flDuration: 5.0);
        return false;
      }
      return false;
    }
  }
LABEL_70:
  pResult->__vftable = (CBaseEntity_vtbl *)LODWORD(trace.endpos.x);
  pResult->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))LODWORD(trace.endpos.y);
  v39 = trace.endpos.z;
  pResult->m_pfnThink = (void (__thiscall *)(CBaseEntity *))LODWORD(trace.endpos.z);
  *(float *)&pResult->m_pfnThink = v39 + MOVE_HEIGHT_EPSILON;
  if ( g_bAIDebugStep )
    NDebugOverlay::Cross3D(position: &trace.endpos, size: 32.0, r: 0, g: 255, b: 0, noDepthTest: true, flDuration: 5.0);
  return *(_DWORD *)&pResult->m_Network.m_PVSInfo.m_nHeadNode == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005F830
// Name: private: void CAI_MoveProbe::JumpMoveLimit(class Vector const __near &,class Vector const __near &,unsigned int,class CBaseEntity const __near *,struct AIMoveTrace_t __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_MoveProbe::JumpMoveLimit(
        CAI_MoveProbe *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vecStart,
        const Vector *vecEnd,
        float collisionMask,
        const CBaseEntity *pTarget,
        AIMoveTrace_t *pMoveTrace)
{
  float v9; // xmm1_4
  CAI_BaseNPC *m_pOuter; // ecx
  float v12; // xmm0_4
  __int128 v13; // xmm1
  bool (__thiscall *IsJumpLegal)(CAI_BaseNPC *, const Vector *, const Vector *, const Vector *); // eax
  float v15; // xmm0_4
  CAI_BaseNPC *v16; // ecx
  double StepDownMultiplier; // st7
  double v18; // st7
  CAI_BaseNPC *v19; // ecx
  float (__thiscall *StepHeight)(CAI_BaseNPC *); // eax
  CAI_BaseNPC *v21; // ecx
  double v22; // st7
  float v23; // ecx
  __int128 v24; // xmm1
  CAI_BaseNPC *v25; // ecx
  float (__thiscall *GetJumpGravity)(CAI_BaseNPC *); // edx
  double v27; // st7
  double v28; // st7
  float v29; // xmm0_4
  double v30; // st7
  Vector *v31; // eax
  float x; // xmm0_4
  CAI_BaseNPC *v33; // ecx
  float z; // xmm0_4
  bool (__thiscall *v35)(CAI_BaseNPC *, const Vector *, const Vector *, const Vector *); // eax
  float v36; // xmm0_4
  float y; // xmm2_4
  __int128 v38; // xmm1
  float v39; // xmm1_4
  __int128 v40; // xmm3
  CBaseEntity *v41; // xmm0_4
  float v42; // xmm7_4
  float v43; // xmm6_4
  float v44; // xmm4_4
  float v45; // xmm5_4
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ecx
  float v47; // eax
  CAI_BaseNPC *v48; // ecx
  const Vector *v49; // eax
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm3_4
  float v55; // xmm4_4
  int (*v56)(void); // eax
  edict_t *m_pPev; // eax
  __int128 v58; // xmm0
  float v59; // edx
  float v60; // xmm0_4
  int v62; // [esp+24h] [ebp-144h] BYREF
  _BYTE trace_20[72]; // [esp+44h] [ebp-124h] OVERLAPPED
  __int128 v64; // [esp+8Ch] [ebp-DCh]
  __int128 v65; // [esp+9Ch] [ebp-CCh]
  Vector v66; // [esp+B8h] [ebp-B0h] BYREF
  Vector vecApex; // [esp+C4h] [ebp-A4h]
  float v68; // [esp+D8h] [ebp-90h]
  __int128 gravity; // [esp+DCh] [ebp-8Ch] OVERLAPPED BYREF
  float v70; // [esp+F4h] [ebp-74h]
  float v71; // [esp+F8h] [ebp-70h]
  CBaseEntity *v72; // [esp+FCh] [ebp-6Ch]
  float v73; // [esp+100h] [ebp-68h]
  float minSuccessfulJumpHeight; // [esp+104h] [ebp-64h]
  CBaseEntity *pObstruction; // [esp+108h] [ebp-60h]
  Vector baselineJumpHeight; // [esp+10Ch] [ebp-5Ch] OVERLAPPED BYREF
  Vector vecTest; // [esp+118h] [ebp-50h] BYREF
  Vector vecFrom; // [esp+124h] [ebp-44h]
  Vector rawJumpVel; // [esp+130h] [ebp-38h] BYREF
  Vector nextPos; // [esp+13Ch] [ebp-2Ch] BYREF
  AIMoveResult_t fStatus; // [esp+148h] [ebp-20h]
  Vector vecTo; // [esp+14Ch] [ebp-1Ch]
  float flTime; // [esp+158h] [ebp-10h] BYREF
  float flDistObstructed; // [esp+15Ch] [ebp-Ch] BYREF
  float minJumpStep; // [esp+160h] [ebp-8h]
  float retaddr; // [esp+168h] [ebp+0h]

  flDistObstructed = a2;
  minJumpStep = retaddr;
  pMoveTrace->vJumpVelocity.x = 0.0;
  pMoveTrace->vJumpVelocity.y = 0.0;
  pMoveTrace->vJumpVelocity.z = 0.0;
  v9 = vecEnd->y - vecStart->y;
  m_pOuter = this->m_pOuter;
  v12 = (float)((float)((float)(vecEnd->x - vecStart->x) * (float)(vecEnd->x - vecStart->x))
              + (float)((float)(vecEnd->z - vecStart->z) * (float)(vecEnd->z - vecStart->z)))
      + (float)(v9 * v9);
  v13 = 0;
  IsJumpLegal = m_pOuter->IsJumpLegal;
  *(float *)&v13 = fsqrt(v12);
  gravity = v13;
  if ( ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *, const Vector *, const Vector *, const Vector *, int, int))IsJumpLegal)(
         a1: m_pOuter,
         a2: vecStart,
         a3: vecEnd,
         a4: vecEnd,
         a5: a3,
         a6: a4) == 0 )
    goto LABEL_2;
  vecTo.y = this->m_pOuter->StepHeight(this: this->m_pOuter);
  v16 = this->m_pOuter;
  LODWORD(vecTo.z) = &vecTest;
  vecTo.y = -720.0;
  StepDownMultiplier = CAI_BaseNPC::GetStepDownMultiplier(this: v16);
  vecTo.x = StepDownMultiplier * vecTo.y;
  CAI_MoveProbe::FloorPoint(
    this,
    a2: COERCE_FLOAT(&flDistObstructed),
    a3: (int)vecEnd,
    a4: (int)this,
    vecStart,
    collisionMask,
    flStartZ: vecTo.x,
    flEndZ: vecTo.y,
    pVecResult: (Vector *)LODWORD(vecTo.z));
  v18 = ((double (__thiscall *)(CAI_BaseNPC *))this->m_pOuter->StepHeight)(a1: this->m_pOuter);
  v19 = this->m_pOuter;
  StepHeight = v19->StepHeight;
  vecTo.x = v18 * 0.5;
  vecTo.y = StepHeight(this: v19);
  v21 = this->m_pOuter;
  LODWORD(vecTo.z) = &nextPos.y;
  vecTo.y = -720.0;
  v22 = CAI_BaseNPC::GetStepDownMultiplier(this: v21);
  vecTo.x = v22 * vecTo.y + v23;
  CAI_MoveProbe::FloorPoint(
    this,
    a2: COERCE_FLOAT(&flDistObstructed),
    a3: (int)vecEnd,
    a4: (int)this,
    vecStart: vecEnd,
    collisionMask,
    flStartZ: vecTo.x,
    flEndZ: vecTo.y,
    pVecResult: (Vector *)LODWORD(vecTo.z));
  if ( !CAI_MoveProbe::CheckStandPosition(this, vecStart: (Vector *)&nextPos.y, collisionMask: LODWORD(collisionMask))
    || nextPos.y == vecTest.x && nextPos.z == vecTest.y && *(float *)&fStatus == vecTest.z )
  {
    goto LABEL_2;
  }
  v24 = 0;
  *(float *)&v24 = fsqrt(
                     (float)((float)(vecTest.x - nextPos.y) * (float)(vecTest.x - nextPos.y))
                   + (float)((float)(vecTest.y - nextPos.z) * (float)(vecTest.y - nextPos.z)));
  v64 = v24;
  if ( *(float *)&v24 == 0.0 )
  {
LABEL_2:
    v15 = *(float *)&gravity;
    pMoveTrace->fStatus = AIMR_ILLEGAL;
    pMoveTrace->flDistObstructed = v15;
    return;
  }
  minSuccessfulJumpHeight = this->m_pOuter->GetMaxJumpSpeed(this: this->m_pOuter);
  v25 = this->m_pOuter;
  GetJumpGravity = v25->GetJumpGravity;
  vecTo.y = sv_gravity.m_pParent->m_Value.m_fValue;
  v27 = ((double (__thiscall *)(CAI_BaseNPC *))GetJumpGravity)(a1: v25);
  v28 = v27 * vecTo.y;
  v29 = *(float *)&gravity;
  v68 = v28;
  if ( v28 < 0.01 )
  {
    pMoveTrace->fStatus = AIMR_ILLEGAL;
    pMoveTrace->flDistObstructed = v29;
    return;
  }
  v71 = 1024.0;
  v72 = nullptr;
  flTime = 0.0;
  CAI_MoveProbe::CalcJumpLaunchVelocity(
    this,
    result: (Vector *)0xFFFFFFFC,
    startPos: &vecTest,
    endPos: (Vector *)&nextPos.y,
    flGravity: v68,
    pminHeight: &flTime,
    maxHorzVelocity: minSuccessfulJumpHeight,
    pvecApex: (Vector *)0x44800000);
  v30 = ((double (__thiscall *)(CAI_BaseNPC *))this->m_pOuter->GetMinJumpHeight)(a1: this->m_pOuter);
  vecTo.x = v30;
  if ( v30 != 0.0 && vecTo.x > flTime )
    flTime = vecTo.x;
  v73 = flTime;
  do
  {
    v31 = CAI_MoveProbe::CalcJumpLaunchVelocity(
            this,
            result: (Vector *)((char *)&gravity + 4),
            startPos: &vecTest,
            endPos: (Vector *)&nextPos.y,
            flGravity: v68,
            pminHeight: &flTime,
            maxHorzVelocity: minSuccessfulJumpHeight,
            pvecApex: &v66);
    x = v31->x;
    v33 = this->m_pOuter;
    LODWORD(vecTo.z) = &nextPos.y;
    vecFrom.x = x;
    vecFrom.y = v31->y;
    z = v31->z;
    v35 = v33->IsJumpLegal;
    vecFrom.z = z;
    if ( !v35(this: v33, a2: &vecTest, a3: &v66, a4: (Vector *)&nextPos.y) )
    {
      v36 = flTime;
LABEL_26:
      v50 = vecTo.z * 0.5;
      v51 = v36 - (float)(vecTo.z * 0.5);
      flTime = v51;
      vecTo.z = vecTo.z * 0.5;
      continue;
    }
    y = vecFrom.y;
    v38 = 0;
    *(float *)&v38 = fsqrt(
                       (float)((float)(vecTest.x - nextPos.y) * (float)(vecTest.x - nextPos.y))
                     + (float)((float)(vecTest.y - nextPos.z) * (float)(vecTest.y - nextPos.z)));
    *(_OWORD *)&trace_20[56] = v38;
    v39 = vecFrom.x;
    v40 = 0;
    *(float *)&v40 = fsqrt((float)(v39 * v39) + (float)(y * y));
    v65 = v40;
    *(float *)&v41 = (float)(*(float *)&trace_20[56] / *(float *)&v40) * 0.1;
    pObstruction = v41;
    baselineJumpHeight = vecTest;
    vecTo.x = 0.0;
    *(double *)&vecApex.x = (float)(*(float *)&trace_20[56] / *(float *)&v40) - 0.01;
    if ( *(double *)&vecApex.x <= 0.0 )
    {
LABEL_25:
      v36 = flTime;
      v71 = flTime;
      goto LABEL_26;
    }
    v42 = baselineJumpHeight.y;
    v43 = baselineJumpHeight.x;
    v44 = *(float *)&v41 * 0.0;
    v45 = baselineJumpHeight.z;
    *((float *)&v64 + 3) = (float)(v68 * 0.5) * *(float *)&v41;
    v70 = *(float *)&v41 * 0.0;
    while ( 1 )
    {
      p_m_Collision = &this->m_pOuter->m_Collision;
      rawJumpVel.x = v43 + (float)((float)(v39 - v44) * *(float *)&v41);
      rawJumpVel.y = v42 + (float)((float)(y - v44) * *(float *)&v41);
      rawJumpVel.z = v45 + (float)((float)(vecFrom.z - *((float *)&v64 + 3)) * *(float *)&v41);
      v47 = COERCE_FLOAT((int)p_m_Collision->OBBMaxs(this: p_m_Collision));
      v48 = this->m_pOuter;
      LODWORD(vecTo.z) = &v62;
      vecTo.y = collisionMask;
      vecTo.x = v47;
      v49 = v48->m_Collision.OBBMins(this: &v48->m_Collision);
      CAI_MoveProbe::TraceHull(
        this,
        a2: (bool (__cdecl *)(IHandleEntity *, int))&flDistObstructed,
        a3: SLODWORD(collisionMask),
        a4: (int)this,
        vecStart: &baselineJumpHeight,
        vecEnd: &rawJumpVel,
        hullMin: v49,
        hullMax: (const Vector *)LODWORD(vecTo.x),
        mask: LODWORD(vecTo.y),
        pResult: (CGameTrace *)LODWORD(vecTo.z));
      if ( trace_20[23] != 0 || *(float *)&trace_20[12] < 0.99 )
        break;
      if ( ai_moveprobe_jump_debug.m_pParent != nullptr && ai_moveprobe_jump_debug.m_pParent->m_Value.m_nValue != 0 )
        NDebugOverlay::Line(
          origin: &baselineJumpHeight,
          target: &rawJumpVel,
          r: 0,
          g: 255,
          b: 0,
          noDepthTest: true,
          duration: 2.0);
      v41 = pObstruction;
      v44 = v70;
      v43 = rawJumpVel.x;
      v42 = rawJumpVel.y;
      v39 = vecFrom.x - v70;
      vecFrom.y = vecFrom.y - v70;
      vecTo.x = vecTo.x + *(float *)&pObstruction;
      vecFrom.z = vecFrom.z - (float)(*(float *)&pObstruction * v68);
      v45 = rawJumpVel.z;
      vecFrom.x = vecFrom.x - v70;
      baselineJumpHeight = rawJumpVel;
      if ( *(double *)&vecApex.x <= vecTo.x )
        goto LABEL_25;
      y = vecFrom.y;
    }
    v56 = *(int (**)(void))(**(_DWORD **)&trace_20[44] + 296);
    v72 = *(CBaseEntity **)&trace_20[44];
    if ( v56() != 0 )
    {
      nextPos.x = NAN;
    }
    else
    {
      m_pPev = v72->m_Network.m_pPev;
      if ( m_pPev != nullptr && m_pPev - gpGlobals->pEdicts != 0 )
        nextPos.x = NAN;
      else
        nextPos.x = NAN;
    }
    v58 = 0;
    v50 = vecTo.z * 0.5;
    *(float *)&v58 = fsqrt(
                       (float)((float)((float)(nextPos.z - baselineJumpHeight.y)
                                     * (float)(nextPos.z - baselineJumpHeight.y))
                             + (float)((float)(*(float *)&fStatus - baselineJumpHeight.z)
                                     * (float)(*(float *)&fStatus - baselineJumpHeight.z)))
                     + (float)((float)(nextPos.y - baselineJumpHeight.x) * (float)(nextPos.y - baselineJumpHeight.x)));
    v65 = v58;
    LODWORD(vecTo.y) = v58;
    vecTo.z = vecTo.z * 0.5;
    if ( *(float *)trace_20 >= 0.0 )
      v51 = v50 + flTime;
    else
      v51 = flTime - v50;
    flTime = v51;
    if ( ai_moveprobe_jump_debug.m_pParent != nullptr && ai_moveprobe_jump_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      NDebugOverlay::Line(
        origin: &baselineJumpHeight,
        target: &rawJumpVel,
        r: 255,
        g: 0,
        b: 0,
        noDepthTest: true,
        duration: 2.0);
      v51 = flTime;
      v50 = vecTo.z;
    }
  }
  while ( v51 > v73 && v51 <= 1024.0 && v50 >= 16.0 );
  if ( v71 == 1024.0 )
  {
    v59 = nextPos.x;
    pMoveTrace->pObstruction = v72;
    pMoveTrace->vHitNormal = vec3_origin;
    v60 = vecTo.y;
    *(float *)&pMoveTrace->fStatus = v59;
    pMoveTrace->flDistObstructed = v60;
  }
  else
  {
    *(float *)&pObstruction = *(float *)&fStatus - vecTest.z;
    rawJumpVel.x = nextPos.y - vecTest.x;
    rawJumpVel.y = nextPos.z - vecTest.y;
    rawJumpVel.z = 0.0;
    v73 = VectorNormalize(vec: &rawJumpVel);
    v52 = v68;
    v53 = v71;
    if ( v71 <= (float)((float)((float)(v68 * 0.5) * (float)((float)(v73 / minSuccessfulJumpHeight) * 0.5))
                      * (float)((float)(v73 / minSuccessfulJumpHeight) * 0.5)) )
      v53 = (float)((float)(v68 * 0.5) * (float)((float)(v73 / minSuccessfulJumpHeight) * 0.5))
          * (float)((float)(v73 / minSuccessfulJumpHeight) * 0.5);
    if ( v53 <= *(float *)&pObstruction )
      v53 = *(float *)&pObstruction;
    v54 = v73
        / (float)(fsqrt(
                    (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v53 - *(float *)&pObstruction) & _mask__AbsFloat_) * 2.0)
                  * (float)(1.0 / v68))
                + fsqrt((float)(v53 * 2.0) * (float)(1.0 / v68)));
    v55 = rawJumpVel.y * v54;
    pMoveTrace->vJumpVelocity.x = rawJumpVel.x * v54;
    pMoveTrace->vJumpVelocity.y = v55;
    pMoveTrace->vJumpVelocity.z = fsqrt((float)(v52 * 2.0) * v53);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100600B0
// Name: public: bool CAI_MoveProbe::TestGroundMove(class Vector const __near &,class Vector const __near &,unsigned int,float,unsigned int,struct AIMoveTrace_t __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CAI_MoveProbe::TestGroundMove@<al>(
        CAI_MoveProbe *this@<ecx>,
        float a2@<ebp>,
        const Vector *vecActualStart,
        const Vector *vecDesiredEnd,
        float collisionMask,
        float pctToCheckStandPositions,
        float flags,
        AIMoveTrace_t *pMoveTrace)
{
  AIMoveTrace_t *v9; // esi
  float v10; // xmm3_4
  float v11; // xmm1_4
  __int128 v12; // xmm4
  bool v13; // zf
  int x_low; // xmm0_4
  int y_low; // xmm1_4
  float z; // xmm2_4
  float y; // ecx
  double flTotalDist; // xmm3_8
  CAI_BaseNPC *m_pOuter; // eax
  double v21; // xmm0_8
  double v22; // xmm0_8
  float v23; // xmm0_4
  float v24; // xmm1_4
  double v25; // xmm1_8
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  unsigned int v29; // xmm2_4
  unsigned int v30; // xmm1_4
  const Vector *v31; // esi
  float *v32; // eax
  CBaseEntity *v33; // ecx
  CBaseEntity **m_pMemory; // eax
  CBaseEntity **v35; // esi
  int v36; // eax
  float *v37; // esi
  bool v38; // al
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ecx
  float v40; // eax
  CBaseEntity::NetworkVar_m_Collision *v41; // ecx
  const Vector *v42; // eax
  float v43; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v44; // edx
  const Vector *v45; // eax
  CBaseEntity **m_pElements; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm2_4
  __int128 v49; // xmm0
  int v50; // eax
  char *v51; // ecx
  int v52; // edx
  float x; // xmm0_4
  int (*v54)(void); // edx
  int v55; // eax
  int v56; // eax
  float v57; // xmm0_4
  const Vector *v58; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v59; // edx
  const Vector *v60; // eax
  _BYTE v61[68]; // [esp+20h] [ebp-F4h] OVERLAPPED BYREF
  CBaseEntity **distStartToIgnoreGround; // [esp+64h] [ebp-B0h]
  CAI_MoveProbe::CheckStepArgs_t checkStepArgs; // [esp+68h] [ebp-ACh] BYREF
  Vector vObstacleDir; // [esp+9Ch] [ebp-78h]
  __int128 vecMoveDir; // [esp+A8h] [ebp-6Ch] OVERLAPPED BYREF
  Vector vMoveDir; // [esp+B8h] [ebp-5Ch]
  char *v67; // [esp+C4h] [ebp-50h] BYREF
  int flStepSize; // [esp+C8h] [ebp-4Ch]
  int v69; // [esp+CCh] [ebp-48h]
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > ignoredEntities; // [esp+D0h] [ebp-44h] BYREF
  CAI_MoveProbe::CheckStepResult_t checkStepResult; // [esp+E4h] [ebp-30h] BYREF
  float distClear; // [esp+108h] [ebp-Ch] BYREF
  int i; // [esp+10Ch] [ebp-8h]
  int retaddr; // [esp+114h] [ebp+0h]

  distClear = a2;
  i = retaddr;
  memset(dst: (int)v61, value: nullptr, count: 0x38u);
  v9 = pMoveTrace;
  if ( pMoveTrace == nullptr )
  {
    v9 = (AIMoveTrace_t *)v61;
    pMoveTrace = (AIMoveTrace_t *)v61;
  }
  v9->flDistObstructed = 0.0;
  v9->pObstruction = nullptr;
  v9->vHitNormal = vec3_origin;
  v9->fStatus = AIMR_OK;
  v9->vEndPosition.x = vecActualStart->x;
  vObstacleDir.z = 0.0;
  v9->vEndPosition.y = vecActualStart->y;
  v9->vEndPosition.z = vecActualStart->z;
  v9->flStepUpDistance = 0.0;
  v10 = vecDesiredEnd->x - vecActualStart->x;
  v11 = vecDesiredEnd->y - vecActualStart->y;
  v12 = 0;
  vObstacleDir.x = v10;
  vObstacleDir.y = v11;
  *(float *)&v12 = fsqrt((float)(v10 * v10) + (float)(v11 * v11));
  vecMoveDir = v12;
  if ( *(float *)&v12 == 0.0 )
  {
    vObstacleDir.y = 0.0;
    vObstacleDir.x = 0.0;
  }
  else
  {
    vObstacleDir.x = (float)(1.0 / *(float *)&vecMoveDir) * v10;
    vObstacleDir.y = v11 * (float)(1.0 / *(float *)&vecMoveDir);
  }
  v13 = *(float *)&vecMoveDir == 0.0;
  LODWORD(v9->flTotalDist) = vecMoveDir;
  if ( v13 )
    return CAI_MoveProbe::Confirm3DConnectivity(this, pMoveTrace: v9, flags: SLOBYTE(flags), vecDesiredEnd);
  if ( (LOBYTE(flags) & 1) != 0 || pctToCheckStandPositions < 0.001 )
  {
    checkStepResult.pBlocker = nullptr;
    pctToCheckStandPositions = 0.0;
  }
  else
  {
    if ( pctToCheckStandPositions > 99.999 )
      pctToCheckStandPositions = 100.0;
    if ( (LOBYTE(flags) & 2) != 0
      || CAI_MoveProbe::CheckStandPosition(this, vecStart: vecActualStart, collisionMask: LODWORD(collisionMask)) )
    {
      checkStepResult.pBlocker = (CBaseEntity *)1;
    }
    else
    {
      checkStepResult.pBlocker = (CBaseEntity *)2;
    }
  }
  LODWORD(vMoveDir.z) = LOBYTE(flags) & 8;
  if ( (LOBYTE(flags) & 8) != 0
    && !CAI_MoveProbe::CheckStandPosition(this, vecStart: vecActualStart, collisionMask: LODWORD(collisionMask)) )
  {
    NDebugOverlay::Cross3D(position: vecActualStart, size: 16.0, r: 128, g: 0, b: 0, noDepthTest: true, flDuration: 2.0);
  }
  checkStepArgs.vecStepDir.y = this->m_pOuter->StepHeight(this: this->m_pOuter);
  checkStepArgs.vecStepDir.z = CAI_BaseNPC::GetStepDownMultiplier(this: this->m_pOuter);
  checkStepArgs.stepSize = NAI_Hull::Width(id: this->m_pOuter->m_eHull) * 0.3333333;
  checkStepResult.endPoint.x = vec3_origin.x;
  checkStepResult.endPoint.y = vec3_origin.y;
  LODWORD(checkStepArgs.stepDownMultiplier) = checkStepResult.pBlocker;
  x_low = SLODWORD(vecActualStart->x);
  y_low = SLODWORD(vecActualStart->y);
  z = vecActualStart->z;
  checkStepArgs.stepHeight = collisionMask;
  checkStepArgs.minStepLanding = flags;
  y = 0.0;
  checkStepResult.endPoint.z = vec3_origin.z;
  ignoredEntities.m_Memory.m_nGrowSize = x_low;
  ignoredEntities.m_Size = y_low;
  *(float *)&ignoredEntities.m_pElements = z;
  checkStepResult.hitNormal.y = 0.0;
  if ( pctToCheckStandPositions == 100.0 )
    flTotalDist = v9->flTotalDist;
  else
    flTotalDist = pctToCheckStandPositions * 0.01 * v9->flTotalDist;
  m_pOuter = this->m_pOuter;
  v21 = (float)((float)((float)(*(float *)&x_low - m_pOuter->m_vecOrigin.m_Value.x)
                      * (float)(*(float *)&x_low - m_pOuter->m_vecOrigin.m_Value.x))
              + (float)((float)(*(float *)&y_low - m_pOuter->m_vecOrigin.m_Value.y)
                      * (float)(*(float *)&y_low - m_pOuter->m_vecOrigin.m_Value.y)));
  *(float *)&v61[56] = flTotalDist;
  if ( v21 >= 0.1
    || (v22 = COERCE_FLOAT(COERCE_UNSIGNED_INT(z - m_pOuter->m_vecOrigin.m_Value.z) & _mask__AbsFloat_),
        *(&checkStepResult.bCrawling + 3) = true,
        checkStepArgs.vecStepDir.y * 0.5 <= v22) )
  {
    *(&checkStepResult.bCrawling + 3) = false;
  }
  v23 = *(float *)&checkStepResult.fStartSolid;
  v67 = nullptr;
  flStepSize = 0;
  v69 = 0;
  ignoredEntities.m_Memory.m_pMemory = nullptr;
  ignoredEntities.m_Memory.m_nAllocationCount = 0;
  while ( 1 )
  {
    v24 = v9->flTotalDist - v23;
    v25 = v24 <= 16.0 ? v24 : 16.0;
    v26 = v25;
    vMoveDir.y = v26;
    if ( v26 < 0.001 )
      break;
    checkStepArgs.vecStepDir.x = v26;
    if ( (float)(v23 - *(float *)&v61[56]) > 0.001 )
      checkStepArgs.stepDownMultiplier = 0.0;
    CAI_MoveProbe::SetupCheckStepTraceListData(
      this,
      a2: COERCE_FLOAT(&distClear),
      a3: (int)v9,
      args: (const CAI_MoveProbe::CheckStepArgs_t *)&v61[60]);
    checkStepResult.pBlocker = nullptr;
    while ( 1 )
    {
      CAI_MoveProbe::CheckStep(
        this,
        args: (const CAI_MoveProbe::CheckStepArgs_t *)&v61[60],
        pResult: (CBaseEntity *)&ignoredEntities.m_Memory.m_nGrowSize);
      if ( !*(&checkStepResult.bCrawling + 3) )
        break;
      y = checkStepResult.hitNormal.y;
      if ( LODWORD(checkStepResult.hitNormal.y) == 0 || LOBYTE(checkStepResult.hitNormal.x) == 0 )
        goto LABEL_63;
      if ( *(_BYTE *)(LODWORD(checkStepResult.hitNormal.y) + 214) != 6 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(checkStepResult.hitNormal.y) + 292))(a1: LODWORD(checkStepResult.hitNormal.y)) == 0 )
          break;
        y = checkStepResult.hitNormal.y;
      }
      if ( *(float *)&v61[60] != vecActualStart->x
        || (v27 = vecActualStart->y, *(float *)&v61[64] != v27)
        || (v28 = vecActualStart->z, *(float *)&distStartToIgnoreGround != v28) )
      {
        *(&checkStepResult.bCrawling + 3) = false;
        goto LABEL_63;
      }
      if ( *(_BYTE *)(LODWORD(y) + 214) == 6 )
      {
        *(float *)&v29 = vecDesiredEnd->y - v27;
        *(float *)&v30 = vecDesiredEnd->z - v28;
        *((float *)&vecMoveDir + 1) = vecDesiredEnd->x - vecActualStart->x;
        *((_QWORD *)&vecMoveDir + 1) = __PAIR64__(v30, v29);
        VectorNormalize(vec: (Vector *)((char *)&vecMoveDir + 4));
        v31 = this->m_pOuter->WorldSpaceCenter(this: this->m_pOuter);
        v32 = (float *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(checkStepResult.hitNormal.y) + 588))(a1: LODWORD(checkStepResult.hitNormal.y));
        *(float *)&checkStepArgs.collisionMask = *v32 - v31->x;
        *(float *)&checkStepArgs.groundTest = v32[1] - v31->y;
        *(float *)&checkStepArgs.flags = v32[2] - v31->z;
        VectorNormalize(vec: (Vector *)&checkStepArgs.collisionMask);
        if ( (float)((float)((float)(*(float *)&checkStepArgs.collisionMask * *((float *)&vecMoveDir + 1))
                           + (float)(*(float *)&checkStepArgs.groundTest * *((float *)&vecMoveDir + 2)))
                   + (float)(*(float *)&checkStepArgs.flags * *((float *)&vecMoveDir + 3))) >= 0.0 )
          break;
        y = checkStepResult.hitNormal.y;
      }
      if ( LODWORD(vMoveDir.z) != 0 && LOBYTE(checkStepResult.hitNormal.x) != 0 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(float))(*(_DWORD *)LODWORD(y) + 292))(a1: COERCE_FLOAT(LODWORD(y))) != 0 )
        {
          checkStepResult.pBlocker = v33;
          NDebugOverlay::EntityBounds(pEntity: this->m_pOuter, r: 0, g: 0, b: 255, a: 0, flDuration: 0.5);
          NDebugOverlay::EntityBounds(
            pEntity: (const CBaseEntity *)LODWORD(checkStepResult.hitNormal.y),
            r: 255,
            g: 0,
            b: 0,
            a: 0,
            flDuration: 0.5);
        }
        y = checkStepResult.hitNormal.y;
      }
      m_pMemory = ignoredEntities.m_Memory.m_pMemory;
      v35 = ignoredEntities.m_Memory.m_pMemory;
      if ( (int)ignoredEntities.m_Memory.m_pMemory + 1 > flStepSize )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&v67,
          num: (int)ignoredEntities.m_Memory.m_pMemory - flStepSize + 1);
        y = checkStepResult.hitNormal.y;
        m_pMemory = ignoredEntities.m_Memory.m_pMemory;
      }
      ignoredEntities.m_Memory.m_pMemory = (CBaseEntity **)((char *)m_pMemory + 1);
      v36 = (char *)m_pMemory - (char *)v35;
      ignoredEntities.m_Memory.m_nAllocationCount = (int)v67;
      if ( v36 > 0 )
      {
        _V_memmove(dest: &v67[4 * (_DWORD)v35 + 4], src: &v67[4 * (_DWORD)v35], count: 4 * v36);
        y = checkStepResult.hitNormal.y;
      }
      v37 = (float *)&v67[4 * (_DWORD)v35];
      if ( v37 != nullptr )
      {
        *v37 = y;
        y = checkStepResult.hitNormal.y;
      }
      if ( *(float *)(LODWORD(y) + 340) < 3.4028235e38 )
      {
        *(_DWORD *)(LODWORD(y) + 340) = 2139095039;
        y = checkStepResult.hitNormal.y;
      }
      if ( (int)++checkStepResult.pBlocker >= 16 )
        goto LABEL_63;
    }
    y = checkStepResult.hitNormal.y;
LABEL_63:
    if ( this->m_pTraceListData != nullptr )
    {
      this->m_pTraceListData->Reset(this: this->m_pTraceListData);
      y = checkStepResult.hitNormal.y;
    }
    if ( LODWORD(vMoveDir.z) != 0 )
    {
      v38 = CAI_MoveProbe::CheckStandPosition(
              this,
              vecStart: (const Vector *)&ignoredEntities.m_Memory.m_nGrowSize,
              collisionMask: LODWORD(collisionMask));
      p_m_Collision = &this->m_pOuter->m_Collision;
      if ( v38 )
      {
        v43 = COERCE_FLOAT((int)p_m_Collision->OBBMaxs(this: p_m_Collision));
        v44 = this->m_pOuter->m_Collision.__vftable;
        checkStepResult.pBlocker = (CBaseEntity *)1036831949;
        *(_DWORD *)&checkStepResult.fStartSolid = 0;
        checkStepResult.hitNormal.z = 0.0;
        LODWORD(checkStepResult.hitNormal.y) = 255;
        checkStepResult.hitNormal.x = 0.0;
        checkStepResult.endPoint.z = v43;
        v45 = (const Vector *)((int (*)(void))v44->OBBMins)();
        NDebugOverlay::Box(
          origin: (const Vector *)&ignoredEntities.m_Memory.m_nGrowSize,
          mins: v45,
          maxs: (const Vector *)LODWORD(checkStepResult.endPoint.z),
          r: SLODWORD(checkStepResult.hitNormal.x),
          g: SLODWORD(checkStepResult.hitNormal.y),
          b: SLODWORD(checkStepResult.hitNormal.z),
          a: *(int *)&checkStepResult.fStartSolid,
          flDuration: *(float *)&checkStepResult.pBlocker);
        checkStepResult.pBlocker = (CBaseEntity *)1036831949;
        *(_DWORD *)&checkStepResult.fStartSolid = 1;
        checkStepResult.hitNormal.z = 0.0;
        LODWORD(checkStepResult.hitNormal.y) = 255;
        checkStepResult.hitNormal.x = 0.0;
      }
      else
      {
        v40 = COERCE_FLOAT((int)p_m_Collision->OBBMaxs(this: p_m_Collision));
        v41 = &this->m_pOuter->m_Collision;
        checkStepResult.pBlocker = (CBaseEntity *)1036831949;
        memset(&checkStepResult.hitNormal.y, 0, 12);
        LODWORD(checkStepResult.hitNormal.x) = 255;
        checkStepResult.endPoint.z = v40;
        v42 = v41->OBBMins(this: v41);
        NDebugOverlay::Box(
          origin: (const Vector *)&ignoredEntities.m_Memory.m_nGrowSize,
          mins: v42,
          maxs: (const Vector *)LODWORD(checkStepResult.endPoint.z),
          r: SLODWORD(checkStepResult.hitNormal.x),
          g: SLODWORD(checkStepResult.hitNormal.y),
          b: SLODWORD(checkStepResult.hitNormal.z),
          a: *(int *)&checkStepResult.fStartSolid,
          flDuration: *(float *)&checkStepResult.pBlocker);
        checkStepResult.pBlocker = (CBaseEntity *)1036831949;
        *(_DWORD *)&checkStepResult.fStartSolid = 1;
        checkStepResult.hitNormal.z = 0.0;
        checkStepResult.hitNormal.y = 0.0;
        LODWORD(checkStepResult.hitNormal.x) = 255;
      }
      NDebugOverlay::Cross3D(
        position: (const Vector *)&ignoredEntities.m_Memory.m_nGrowSize,
        size: 16.0,
        r: SLODWORD(checkStepResult.hitNormal.x),
        g: SLODWORD(checkStepResult.hitNormal.y),
        b: SLODWORD(checkStepResult.hitNormal.z),
        noDepthTest: checkStepResult.fStartSolid,
        flDuration: *(float *)&checkStepResult.pBlocker);
      y = checkStepResult.hitNormal.y;
    }
    if ( y != 0.0 )
    {
      v9 = pMoveTrace;
      v49 = 0;
      *(float *)&v49 = fsqrt(
                         (float)((float)(*(float *)&ignoredEntities.m_Size - *(float *)&v61[64])
                               * (float)(*(float *)&ignoredEntities.m_Size - *(float *)&v61[64]))
                       + (float)((float)(*(float *)&ignoredEntities.m_Memory.m_nGrowSize - *(float *)&v61[60])
                               * (float)(*(float *)&ignoredEntities.m_Memory.m_nGrowSize - *(float *)&v61[60])));
      vecMoveDir = v49;
      *(float *)&checkStepResult.fStartSolid = *(float *)&v49 + *(float *)&checkStepResult.fStartSolid;
      if ( LOBYTE(checkStepResult.hitNormal.z) != 0 )
      {
        y = 0.0;
        checkStepResult.hitNormal.y = 0.0;
      }
      break;
    }
    m_pElements = ignoredEntities.m_pElements;
    v47 = *(float *)&ignoredEntities.m_pElements - *(float *)&distStartToIgnoreGround;
    if ( (float)(*(float *)&ignoredEntities.m_pElements - *(float *)&distStartToIgnoreGround) < 0.0 )
      v47 = 0.0;
    v9 = pMoveTrace;
    v48 = pMoveTrace->flStepUpDistance + v47;
    v23 = vMoveDir.y + *(float *)&checkStepResult.fStartSolid;
    pMoveTrace->flStepUpDistance = v48;
    *(_DWORD *)&v61[60] = ignoredEntities.m_Memory.m_nGrowSize;
    *(float *)&checkStepResult.fStartSolid = v23;
    *(_DWORD *)&v61[64] = ignoredEntities.m_Size;
    distStartToIgnoreGround = m_pElements;
  }
  v50 = 0;
  if ( (int)ignoredEntities.m_Memory.m_pMemory > 0 )
  {
    v51 = v67;
    do
    {
      v52 = *(_DWORD *)&v51[4 * v50++];
      *(_DWORD *)(v52 + 340) = 0;
    }
    while ( v50 < (int)ignoredEntities.m_Memory.m_pMemory );
    y = checkStepResult.hitNormal.y;
  }
  LODWORD(v9->vEndPosition.x) = ignoredEntities.m_Memory.m_nGrowSize;
  LODWORD(v9->vEndPosition.y) = ignoredEntities.m_Size;
  LODWORD(v9->vEndPosition.z) = ignoredEntities.m_pElements;
  if ( y == 0.0 )
  {
    *(&checkStepResult.bCrawling + 3) = CAI_MoveProbe::Confirm3DConnectivity(
                                          this,
                                          pMoveTrace: v9,
                                          flags: SLOBYTE(flags),
                                          vecDesiredEnd);
    if ( v69 >= 0 && v67 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v67);
    return *(&checkStepResult.bCrawling + 3);
  }
  else
  {
    x = checkStepResult.endPoint.x;
    *(float *)&v9->pObstruction = y;
    v54 = *(int (**)(void))(*(_DWORD *)LODWORD(y) + 296);
    v9->vHitNormal.x = x;
    v9->vHitNormal.y = checkStepResult.endPoint.y;
    v9->vHitNormal.z = checkStepResult.endPoint.z;
    vMoveDir.y = y;
    if ( v54() != 0 )
    {
      v55 = -3;
    }
    else
    {
      v56 = *(_DWORD *)(LODWORD(vMoveDir.y) + 24);
      if ( v56 != 0 && (signed int)(v56 - (unsigned int)gpGlobals->pEdicts) >> 4 != 0 )
        v55 = -1;
      else
        v55 = -2;
    }
    v13 = LODWORD(vMoveDir.z) == 0;
    v57 = v9->flTotalDist - *(float *)&checkStepResult.fStartSolid;
    v9->fStatus = v55;
    v9->flDistObstructed = v57;
    if ( !v13 )
    {
      v58 = this->m_pOuter->m_Collision.OBBMaxs(this: &this->m_pOuter->m_Collision);
      v59 = this->m_pOuter->m_Collision.__vftable;
      checkStepResult.pBlocker = (CBaseEntity *)1056964608;
      memset(&checkStepResult.hitNormal.y, 0, 12);
      LODWORD(checkStepResult.hitNormal.x) = 255;
      LODWORD(checkStepResult.endPoint.z) = v58;
      v60 = (const Vector *)((int (*)(void))v59->OBBMins)();
      NDebugOverlay::Box(
        origin: (const Vector *)&ignoredEntities.m_Memory.m_nGrowSize,
        mins: v60,
        maxs: (const Vector *)LODWORD(checkStepResult.endPoint.z),
        r: SLODWORD(checkStepResult.hitNormal.x),
        g: SLODWORD(checkStepResult.hitNormal.y),
        b: SLODWORD(checkStepResult.hitNormal.z),
        a: *(int *)&checkStepResult.fStartSolid,
        flDuration: *(float *)&checkStepResult.pBlocker);
    }
    if ( v69 >= 0 && v67 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v67);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060AA0
// Name: private: void CAI_MoveProbe::GroundMoveLimit(class Vector const __near &,class Vector const __near &,unsigned int,class CBaseEntity const __near *,unsigned int,float,struct AIMoveTrace_t __near *)const
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_MoveProbe::GroundMoveLimit(
        CAI_MoveProbe *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vecStart,
        const Vector *vecEnd,
        float collisionMask,
        const CBaseEntity *pTarget,
        float testGroundMoveFlags,
        float pctToCheckStandPositions,
        AIMoveTrace_t *pTrace)
{
  __int128 v12; // xmm0
  CAI_BaseNPC *m_pOuter; // ecx
  double StepDownMultiplier; // st7
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v17; // eax
  CAI_BaseNPC *v18; // ecx
  double v19; // st7
  CBaseCombatCharacter *v20; // edi
  __int128 vecActualStart; // [esp+1Ch] [ebp-3Ch] BYREF
  Vector flStartZ; // [esp+38h] [ebp-20h] BYREF
  Vector vecDesiredEnd; // [esp+44h] [ebp-14h] BYREF
  void *v25; // [esp+50h] [ebp-8h]
  void *retaddr; // [esp+58h] [ebp+0h]

  vecDesiredEnd.z = a2;
  v25 = retaddr;
  v12 = 0;
  *(float *)&v12 = fsqrt(
                     (float)((float)(vecEnd->y - vecStart->y) * (float)(vecEnd->y - vecStart->y))
                   + (float)((float)(vecEnd->x - vecStart->x) * (float)(vecEnd->x - vecStart->x)));
  vecActualStart = v12;
  LODWORD(pTrace->flTotalDist) = v12;
  vecDesiredEnd.x = ((double (__thiscall *)(CAI_BaseNPC *, int, int))this->m_pOuter->StepHeight)(
                      a1: this->m_pOuter,
                      a2: a3,
                      a3: a4);
  m_pOuter = this->m_pOuter;
  LODWORD(vecDesiredEnd.x) = (char *)&vecActualStart + 4;
  flStartZ.z = -720.0;
  StepDownMultiplier = CAI_BaseNPC::GetStepDownMultiplier(this: m_pOuter);
  flStartZ.y = StepDownMultiplier * vecDesiredEnd.x;
  if ( CAI_MoveProbe::FloorPoint(
         this,
         a2: COERCE_FLOAT((Vector *)&vecDesiredEnd.z),
         a3: (int)this,
         a4: (int)pTrace,
         vecStart,
         collisionMask,
         flStartZ: flStartZ.y,
         flEndZ: flStartZ.z,
         pVecResult: (Vector *)LODWORD(vecDesiredEnd.x)) )
  {
    if ( (LOBYTE(testGroundMoveFlags) & 4) != 0 )
    {
      flStartZ = *vecEnd;
    }
    else
    {
      vecDesiredEnd.x = this->m_pOuter->StepHeight(this: this->m_pOuter);
      v18 = this->m_pOuter;
      LODWORD(vecDesiredEnd.x) = &flStartZ;
      flStartZ.z = -720.0;
      v19 = CAI_BaseNPC::GetStepDownMultiplier(this: v18);
      flStartZ.y = v19 * vecDesiredEnd.x;
      CAI_MoveProbe::FloorPoint(
        this,
        a2: COERCE_FLOAT((Vector *)&vecDesiredEnd.z),
        a3: (int)this,
        a4: (int)pTrace,
        vecStart: vecEnd,
        collisionMask,
        flStartZ: flStartZ.y,
        flEndZ: flStartZ.z,
        pVecResult: (Vector *)LODWORD(vecDesiredEnd.x));
    }
    CAI_MoveProbe::TestGroundMove(
      this,
      a2: COERCE_FLOAT((Vector *)&vecDesiredEnd.z),
      vecActualStart: (const Vector *)((char *)&vecActualStart + 4),
      vecDesiredEnd: &flStartZ,
      collisionMask,
      pctToCheckStandPositions,
      flags: testGroundMoveFlags,
      pMoveTrace: pTrace);
    HIBYTE(vecDesiredEnd.y) = 0;
    if ( pTarget != nullptr )
    {
      v20 = pTarget->MyCombatCharacterPointer(this: pTarget);
      if ( v20 != nullptr && v20->IsInAVehicle(this: v20) && v20->GetVehicleEntity(this: v20) == pTrace->pObstruction )
        HIBYTE(vecDesiredEnd.y) = 1;
      if ( pTarget == pTrace->pObstruction || HIBYTE(vecDesiredEnd.y) != 0 )
      {
        pTrace->flDistObstructed = 0.0;
        pTrace->pObstruction = nullptr;
        pTrace->vHitNormal = vec3_origin;
        pTrace->fStatus = AIMR_OK;
      }
    }
  }
  else
  {
    pTrace->flDistObstructed = pTrace->flTotalDist;
    if ( gpGlobals->pEdicts != nullptr
      && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0
      && (m_pUnk = pEdicts->m_pUnk) != nullptr )
    {
      v17 = m_pUnk->GetBaseEntity(this: m_pUnk);
    }
    else
    {
      v17 = nullptr;
    }
    pTrace->pObstruction = v17;
    pTrace->vHitNormal = vec3_origin;
    pTrace->fStatus = AIMR_BLOCKED_WORLD;
    pTrace->vEndPosition = *vecStart;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060CE0
// Name: public: bool CAI_MoveProbe::MoveLimit(enum Navigation_t,class Vector const __near &,class Vector const __near &,unsigned int,class CBaseEntity const __near *,float,unsigned int,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
BOOL __userpurge CAI_MoveProbe::MoveLimit@<eax>(
        CAI_MoveProbe *this@<ecx>,
        int a2@<ebp>,
        Navigation_t navType,
        const Vector *vecStart,
        const Vector *vecEnd,
        unsigned int collisionMask,
        const CBaseEntity *pTarget,
        float pctToCheckStandPositions,
        char flags,
        AIMoveTrace_t *pTrace)
{
  AIMoveTrace_t *v10; // esi
  const Vector *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  __int128 v14; // xmm0
  bool v15; // cl
  edict_t *v16; // eax
  IServerUnknown *m_pUnk; // ecx
  int v18; // eax
  __int128 v19; // xmm0
  CWorld *pObstruction; // ecx
  unsigned int *v21; // eax
  float v23; // xmm1_4
  __int128 v24; // xmm0
  int v25; // [esp+1Ch] [ebp-DCh] BYREF
  _BYTE tr_32[105]; // [esp+48h] [ebp-B0h] OVERLAPPED BYREF
  const Vector *v27; // [esp+C8h] [ebp-30h]
  __int128 v28; // [esp+CCh] [ebp-2Ch] BYREF
  float v29; // [esp+E4h] [ebp-14h]
  CAI_MoveProbe *v30; // [esp+E8h] [ebp-10h]
  int v31; // [esp+ECh] [ebp-Ch] BYREF
  unsigned int testGroundMoveFlags; // [esp+F0h] [ebp-8h]
  unsigned int retaddr; // [esp+F8h] [ebp+0h]

  v31 = a2;
  testGroundMoveFlags = retaddr;
  v30 = this;
  memset(dst: (int)&tr_32[48], value: nullptr, count: 0x38u);
  v10 = pTrace;
  if ( pTrace == nullptr )
    v10 = (AIMoveTrace_t *)&tr_32[48];
  v11 = vecEnd;
  v12 = (float)(vecEnd->y - vecStart->y) * (float)(vecEnd->y - vecStart->y);
  if ( navType != NAV_GROUND )
    v12 = v12 + (float)((float)(vecEnd->z - vecStart->z) * (float)(vecEnd->z - vecStart->z));
  v13 = v12 + (float)((float)(vecEnd->x - vecStart->x) * (float)(vecEnd->x - vecStart->x));
  v14 = 0;
  v10->pObstruction = nullptr;
  *(float *)&v14 = fsqrt(v13);
  v28 = v14;
  *(_QWORD *)&v10->flTotalDist = (unsigned int)v14;
  v10->vHitNormal = vec3_origin;
  v10->fStatus = AIMR_OK;
  v10->vEndPosition = *vecStart;
  switch ( navType )
  {
    case NAV_GROUND:
    case NAV_CRAWL:
      v29 = 0.0;
      if ( (flags & 1) != 0 )
        LODWORD(v29) = 4;
      if ( (flags & 2) != 0 )
        LODWORD(v29) |= 8u;
      if ( ai_moveprobe_debug.m_pParent != nullptr
        && ai_moveprobe_debug.m_pParent->m_Value.m_nValue != 0
        && (v30->m_pOuter->m_debugOverlays & 0x1000) != 0 )
      {
        LODWORD(v29) |= 8u;
      }
      if ( (flags & 4) != 0 )
        v30->m_bIgnoreTransientEntities = true;
      v15 = true;
      if ( (flags & 8) != 0 )
      {
        v27 = v30->m_pOuter->EyePosition(this: v30->m_pOuter, result: (char *)&v28 + 4);
        CTraceFilterNav::CTraceFilterNav(
          this: (CTraceFilterNav *)&tr_32[104],
          pProber: v30->m_pOuter,
          bIgnoreTransientEntities: v30->m_bIgnoreTransientEntities,
          passedict: v30->m_pOuter,
          collisionGroup: v30->m_pOuter->m_CollisionGroup.m_Value,
          bAllowPlayerAvoid: true);
        UTIL_TraceLine(
          a1: (int)&v31,
          a2: (int)v10,
          vecAbsStart: v27,
          vecAbsEnd: vecEnd,
          mask: collisionMask,
          pFilter: (ITraceFilter *)&tr_32[104],
          ptr: (CGameTrace *)&v25);
        v11 = vecEnd;
        v15 = *(float *)tr_32 > 0.99;
      }
      if ( navType == NAV_CRAWL )
        LODWORD(v29) |= 0x10u;
      if ( v15 )
      {
        CAI_MoveProbe::GroundMoveLimit(
          this: v30,
          a2: COERCE_FLOAT(&v31),
          a3: (int)vecStart,
          a4: (int)v10,
          vecStart,
          vecEnd: v11,
          collisionMask: *(float *)&collisionMask,
          pTarget,
          testGroundMoveFlags: v29,
          pctToCheckStandPositions,
          pTrace: v10);
      }
      else
      {
        v16 = INDEXENT(iEdictNum: 0);
        if ( v16 != nullptr && (m_pUnk = v16->m_pUnk) != nullptr )
          v18 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
        else
          v18 = 0;
        v10->pObstruction = (CBaseEntity *)v18;
        v10->vHitNormal = vec3_origin;
        v10->fStatus = AIMR_BLOCKED_WORLD;
        v19 = 0;
        *(float *)&v19 = fsqrt(
                           (float)((float)(vecEnd->y - vecStart->y) * (float)(vecEnd->y - vecStart->y))
                         + (float)((float)(vecEnd->x - vecStart->x) * (float)(vecEnd->x - vecStart->x)));
        v28 = v19;
        LODWORD(v10->flDistObstructed) = v19;
      }
      v30->m_bIgnoreTransientEntities = false;
      goto LABEL_28;
    case NAV_JUMP:
      CAI_MoveProbe::JumpMoveLimit(
        this: v30,
        a2: COERCE_FLOAT(&v31),
        a3: (int)vecStart,
        a4: (int)v10,
        vecStart,
        vecEnd,
        collisionMask: *(float *)&collisionMask,
        pTarget,
        pMoveTrace: v10);
      goto LABEL_28;
    case NAV_FLY:
      CAI_MoveProbe::FlyMoveLimit(
        this: v30,
        a2: (int)&v31,
        a3: (int)vecStart,
        a4: (int)v10,
        vecStart,
        vecEnd,
        collisionMask,
        pTarget,
        pMoveTrace: v10);
      goto LABEL_28;
    case NAV_CLIMB:
      CAI_MoveProbe::ClimbMoveLimit(
        this: v30,
        a2: (int)&v31,
        a3: (int)vecStart,
        a4: (int)v10,
        vecStart,
        vecEnd,
        pTarget,
        pMoveTrace: v10);
LABEL_28:
      if ( v10->fStatus < AIMR_OK )
        goto LABEL_29;
      return v10->fStatus >= AIMR_OK;
    default:
      v10->fStatus = AIMR_ILLEGAL;
      v23 = (float)(vecEnd->y - vecStart->y) * (float)(vecEnd->y - vecStart->y);
      if ( navType != NAV_GROUND )
        v23 = v23 + (float)((float)(vecEnd->z - vecStart->z) * (float)(vecEnd->z - vecStart->z));
      v24 = 0;
      *(float *)&v24 = fsqrt(v23 + (float)((float)(vecEnd->x - vecStart->x) * (float)(vecEnd->x - vecStart->x)));
      v28 = v24;
      LODWORD(v10->flDistObstructed) = v24;
LABEL_29:
      pObstruction = (CWorld *)v10->pObstruction;
      if ( pObstruction != nullptr && pObstruction != g_WorldEntity )
      {
        v21 = (unsigned int *)pObstruction->GetRefEHandle(this: pObstruction);
        v30->m_hLastBlockingEnt.m_Index = *v21;
      }
      return v10->fStatus >= AIMR_OK;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FC910
// Name: CAI_MoveProbe_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_MoveProbe_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_MoveProbe>(__formal: nullptr);
  CAI_MoveProbe_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061030
// Name: struct datamap_t __near * DataMapInit<class CAI_MoveProbe>(class CAI_MoveProbe __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_MoveProbe>()
{
  if ( (_S2_23 & 1) == 0 )
  {
    _S2_23 |= 1u;
    nameHolder_52.m_pszBase = "CAI_MoveProbe";
    nameHolder_52.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_52.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_52.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_52.m_Names.m_Size = 0;
    nameHolder_52.m_Names.m_pElements = nullptr;
    nameHolder_52.m_nLenBase = 13;
    atexit(func: DataMapInit_CAI_MoveProbe__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_MoveProbe::m_DataMap.baseMap = nullptr;
  CAI_MoveProbe::m_DataMap.dataNumFields = 2;
  CAI_MoveProbe::m_DataMap.dataDesc = &dataDesc_50[1];
  return &CAI_MoveProbe::m_DataMap;
}
