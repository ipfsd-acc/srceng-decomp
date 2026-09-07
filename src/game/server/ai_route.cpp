// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_route.cpp
// Functions: 37
// ============================================================

#include "game\server\ai_route.h"

//------------------------------------------------------------------------------
// Address: 0x10080330
// Name: public: void CAI_Path::PrependWaypoints(struct AI_Waypoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::PrependWaypoints(CAI_Path *this, AI_Waypoint_t *pWaypoints)
{
  CAI_WaypointList::PrependWaypoints(this: &this->m_Waypoints, pWaypoints);
  CAI_WaypointList::GetLast(this: &this->m_Waypoints)->flPathDistGoal = -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10080360
// Name: public: void CAI_Path::PrependWaypoint(class Vector const __near &,enum Navigation_t,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::PrependWaypoint(
        CAI_Path *this,
        const Vector *newPoint,
        Navigation_t navType,
        unsigned int waypointFlags)
{
  CAI_WaypointList::PrependWaypoint(this: &this->m_Waypoints, newPoint, navType, waypointFlags, flYaw: 0.0);
  CAI_WaypointList::GetLast(this: &this->m_Waypoints)->flPathDistGoal = -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100803A0
// Name: public: enum Activity CAI_Path::SetMovementActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_Path::SetMovementActivity(CAI_Path *this, Activity activity)
{
  this->m_sequence = -1;
  this->m_activity = activity;
  return activity;
}

//------------------------------------------------------------------------------
// Address: 0x100803C0
// Name: public: enum Activity CAI_Path::GetArrivalActivity(void)const
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_Path::GetArrivalActivity(CAI_Path *this)
{
  if ( this->m_Waypoints.m_pFirstWaypoint != nullptr )
    return this->m_arrivalActivity;
  else
    return ACT_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x100803D0
// Name: public: void CAI_Path::SetArrivalActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetArrivalActivity(CAI_Path *this, Activity activity)
{
  this->m_arrivalActivity = activity;
  this->m_arrivalSequence = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100803F0
// Name: public: int CAI_Path::GetArrivalSequence(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Path::GetArrivalSequence(CAI_Path *this)
{
  if ( this->m_Waypoints.m_pFirstWaypoint != nullptr )
    return this->m_arrivalSequence;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10080400
// Name: public: void CAI_Path::SetArrivalSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetArrivalSequence(CAI_Path *this, int sequence)
{
  this->m_arrivalSequence = sequence;
}

//------------------------------------------------------------------------------
// Address: 0x10080410
// Name: public: void CAI_Path::SetGoalSpeed(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetGoalSpeed(CAI_Path *this, float flSpeed)
{
  this->m_goalSpeed = flSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x10080430
// Name: public: void CAI_Path::SetGoalStoppingDistance(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetGoalStoppingDistance(CAI_Path *this, float flDistance)
{
  this->m_goalStoppingDistance = flDistance;
}

//------------------------------------------------------------------------------
// Address: 0x10080450
// Name: public: float CAI_Path::GetGoalStoppingDistance(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Path::GetGoalStoppingDistance(CAI_Path *this)
{
  return this->m_goalStoppingDistance;
}

//------------------------------------------------------------------------------
// Address: 0x10080460
// Name: public: class Vector const __near & CAI_Path::CurWaypointPos(void)const
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Path::CurWaypointPos(CAI_Path *this)
{
  AI_Waypoint_t *result; // eax

  result = this->m_Waypoints.m_pFirstWaypoint;
  if ( this->m_Waypoints.m_pFirstWaypoint == nullptr )
    return &CAI_Path::gm_InvalidWaypoint;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10080470
// Name: public: float CAI_Path::CurWaypointYaw(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Path::CurWaypointYaw(CAI_Path *this)
{
  return this->m_Waypoints.m_pFirstWaypoint->flYaw;
}

//------------------------------------------------------------------------------
// Address: 0x10080480
// Name: public: void CAI_Path::SetLastNodeAsGoal(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetLastNodeAsGoal(CAI_Path *this, bool bReset)
{
  AI_Waypoint_t *m_pFirstWaypoint; // eax

  m_pFirstWaypoint = this->m_Waypoints.m_pFirstWaypoint;
  if ( this->m_Waypoints.m_pFirstWaypoint != nullptr )
  {
    while ( m_pFirstWaypoint->pNext != nullptr )
      m_pFirstWaypoint = m_pFirstWaypoint->pNext;
    this->m_goalPos = m_pFirstWaypoint->vecLocation;
    this->m_bGoalPosSet = true;
    m_pFirstWaypoint->m_fWaypointFlags |= 8u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100804C0
// Name: public: void CAI_Path::ResetGoalPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::ResetGoalPosition(CAI_Path *this, const Vector *goalPos)
{
  this->m_bGoalPosSet = true;
  this->m_goalPos.x = this->m_vecTargetOffset.x + goalPos->x;
  this->m_goalPos.y = this->m_vecTargetOffset.y + goalPos->y;
  this->m_goalPos.z = this->m_vecTargetOffset.z + goalPos->z;
}

//------------------------------------------------------------------------------
// Address: 0x10080500
// Name: public: class Vector const __near & CAI_Path::BaseGoalPosition(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_Path::BaseGoalPosition(CAI_Path *this)
{
  if ( (_S4_6 & 1) == 0 )
    _S4_6 |= 1u;
  vecResult.x = this->m_goalPos.x - this->m_vecTargetOffset.x;
  vecResult.y = this->m_goalPos.y - this->m_vecTargetOffset.y;
  vecResult.z = this->m_goalPos.z - this->m_vecTargetOffset.z;
  return &vecResult;
}

//------------------------------------------------------------------------------
// Address: 0x10080550
// Name: public: void CAI_Path::SetGoalType(enum GoalType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetGoalType(CAI_Path *this, GoalType_t goalType)
{
  if ( this->m_goalType != GOALTYPE_NONE )
  {
    this->m_routeStartTime = gpGlobals->curtime;
    this->m_bGoalTypeSet = true;
  }
  else
  {
    this->m_bGoalTypeSet = false;
  }
  this->m_goalType = goalType;
}

//------------------------------------------------------------------------------
// Address: 0x10080580
// Name: public: enum Navigation_t CAI_Path::CurWaypointNavType(void)const
// Source: json
//------------------------------------------------------------------------------
Navigation_t __thiscall CAI_Path::CurWaypointNavType(CAI_Path *this)
{
  if ( this->m_Waypoints.m_pFirstWaypoint != nullptr )
    return this->m_Waypoints.m_pFirstWaypoint->m_iWPType;
  else
    return NAV_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x100805A0
// Name: public: bool CAI_Path::CurWaypointIsGoal(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Path::CurWaypointIsGoal(CAI_Path *this)
{
  return this->m_Waypoints.m_pFirstWaypoint != nullptr
      && (this->m_Waypoints.m_pFirstWaypoint->m_fWaypointFlags & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100805C0
// Name: public: CAI_Path::~CAI_Path(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::~CAI_Path(CAI_Path *this)
{
  DeleteAll(pWaypointList: this->m_Waypoints.m_pFirstWaypoint);
}

//------------------------------------------------------------------------------
// Address: 0x100805D0
// Name: public: void CAI_Path::SetWaypoints(struct AI_Waypoint_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetWaypoints(CAI_Path *this, CChoreoActor *route, bool fSetGoalFromLast)
{
  AI_Waypoint_t *Last; // eax

  CAI_WaypointList::Set((CChoreoChannel *)this, actor: route);
  Last = CAI_WaypointList::GetLast(this: &this->m_Waypoints);
  if ( Last != nullptr )
  {
    Last->flPathDistGoal = -1.0;
    if ( fSetGoalFromLast )
    {
      this->m_bGoalPosSet = false;
      Last->m_fWaypointFlags |= 8u;
      this->m_bGoalPosSet = true;
      this->m_goalPos.x = Last->vecLocation.x + this->m_vecTargetOffset.x;
      this->m_goalPos.y = this->m_vecTargetOffset.y + Last->vecLocation.y;
      this->m_goalPos.z = this->m_vecTargetOffset.z + Last->vecLocation.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080640
// Name: public: void CAI_Path::SetGoalDirection(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetGoalDirection(CAI_Path *this, const Vector *goalDirection)
{
  this->m_goalDirectionTarget.m_Index = -1;
  this->m_goalDirection = *goalDirection;
  VectorNormalize(vec: &this->m_goalDirection);
}

//------------------------------------------------------------------------------
// Address: 0x10080670
// Name: public: void CAI_Path::SetGoalDirection(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetGoalDirection(CAI_Path *this, CBaseEntity *pTarget)
{
  AI_Waypoint_t *Last; // edi
  float v4; // xmm1_4
  float v5; // xmm2_4
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( pTarget != nullptr )
  {
    this->m_goalDirectionTarget.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
    Last = CAI_WaypointList::GetLast(this: &this->m_Waypoints);
    if ( Last != nullptr )
    {
      if ( (pTarget->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pTarget, a2: (int)&savedregs);
      v4 = pTarget->m_vecAbsOrigin.y - Last->vecLocation.y;
      v5 = pTarget->m_vecAbsOrigin.z - Last->vecLocation.z;
      this->m_goalDirection.x = pTarget->m_vecAbsOrigin.x - Last->vecLocation.x;
      this->m_goalDirection.y = v4;
      this->m_goalDirection.z = v5;
      VectorNormalize(vec: &this->m_goalDirection);
    }
  }
  else
  {
    this->m_goalDirectionTarget.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080710
// Name: public: void CAI_Path::SetGoalSpeed(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::SetGoalSpeed(CAI_Path *this, CBaseEntity *pTarget)
{
  if ( pTarget != nullptr )
    this->m_goalSpeedTarget.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
  else
    this->m_goalSpeedTarget.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10080740
// Name: public: void CAI_Path::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::Clear(CAI_Path *this)
{
  CAI_WaypointList::RemoveAll(this: &this->m_Waypoints);
  this->m_goalType = GOALTYPE_NONE;
  this->m_goalPos = vec3_origin;
  this->m_bGoalPosSet = false;
  this->m_bGoalTypeSet = false;
  this->m_goalFlags = 0;
  this->m_vecTargetOffset = vec3_origin;
  this->m_routeStartTime = 3.4028235e38;
  this->m_goalTolerance = 0.0;
  this->m_activity = ACT_INVALID;
  this->m_sequence = -1;
  this->m_target.m_Index = -1;
  this->m_arrivalActivity = ACT_INVALID;
  this->m_arrivalSequence = -1;
  this->m_goalDirectionTarget.m_Index = -1;
  this->m_goalDirection = vec3_origin;
  this->m_goalSpeedTarget.m_Index = -1;
  this->m_goalSpeed = -1.0;
  this->m_goalStoppingDistance = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10080810
// Name: private: static void CAI_Path::ComputeRouteGoalDistances(struct AI_Waypoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_Path::ComputeRouteGoalDistances(AI_Waypoint_t *pGoalWaypoint)
{
  AI_Waypoint_t *v1; // eax
  AI_Waypoint_t *pPrev; // ecx
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // [esp-10h] [ebp-1Ch]

  v1 = pGoalWaypoint;
  pGoalWaypoint->flPathDistGoal = 0.0;
  if ( pGoalWaypoint->pPrev != nullptr )
  {
    do
    {
      pPrev = v1->pPrev;
      v3 = (float)(v1->vecLocation.x - pPrev->vecLocation.x) * (float)(v1->vecLocation.x - pPrev->vecLocation.x);
      v4 = (float)(v1->vecLocation.y - pPrev->vecLocation.y) * (float)(v1->vecLocation.y - pPrev->vecLocation.y);
      if ( v1->m_iWPType != NAV_GROUND )
        v5 = fsqrt(
               (float)(v4
                     + (float)((float)(v1->vecLocation.z - pPrev->vecLocation.z)
                             * (float)(v1->vecLocation.z - pPrev->vecLocation.z)))
             + v3);
      else
        v5 = fsqrt(v3 + v4);
      pPrev->flPathDistGoal = v1->flPathDistGoal + v5;
      v1 = pPrev;
    }
    while ( pPrev->pPrev != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100808C0
// Name: public: CAI_Path::CAI_Path(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Path *__thiscall CAI_Path::CAI_Path(CAI_Path *this)
{
  this->m_Waypoints.m_pFirstWaypoint = nullptr;
  this->m_target.m_Index = -1;
  this->m_goalDirectionTarget.m_Index = -1;
  this->m_goalSpeedTarget.m_Index = -1;
  this->m_goalType = GOALTYPE_NONE;
  this->m_goalPos = vec3_origin;
  this->m_goalTolerance = 0.0;
  this->m_activity = ACT_INVALID;
  this->m_sequence = -1;
  this->m_target.m_Index = -1;
  this->m_routeStartTime = 3.4028235e38;
  this->m_goalFlags = 0;
  this->m_arrivalActivity = ACT_INVALID;
  this->m_arrivalSequence = -1;
  this->m_iLastNodeReached = -1;
  this->m_waypointTolerance = 0.1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10080940
// Name: public: float CAI_Path::GetPathLength(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Path::GetPathLength(CAI_Path *this)
{
  AI_Waypoint_t *Last; // eax
  AI_Waypoint_t *m_pFirstWaypoint; // esi

  Last = CAI_WaypointList::GetLast(this: &this->m_Waypoints);
  if ( Last != nullptr && Last->flPathDistGoal == -1.0 )
    CAI_Path::ComputeRouteGoalDistances(pGoalWaypoint: Last);
  m_pFirstWaypoint = this->m_Waypoints.m_pFirstWaypoint;
  if ( m_pFirstWaypoint != nullptr )
    return m_pFirstWaypoint->flPathDistGoal;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100809A0
// Name: public: float CAI_Path::GetPathDistanceToGoal(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Path::GetPathDistanceToGoal(CAI_Path *this, const Vector *startPos)
{
  AI_Waypoint_t *m_pFirstWaypoint; // esi
  AI_Waypoint_t *Last; // eax
  AI_Waypoint_t *v5; // edi
  float flPathDistGoal; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4

  m_pFirstWaypoint = this->m_Waypoints.m_pFirstWaypoint;
  if ( this->m_Waypoints.m_pFirstWaypoint == nullptr )
    return 0.0;
  Last = CAI_WaypointList::GetLast(this: &this->m_Waypoints);
  if ( Last != nullptr && Last->flPathDistGoal == -1.0 )
    CAI_Path::ComputeRouteGoalDistances(pGoalWaypoint: Last);
  v5 = this->m_Waypoints.m_pFirstWaypoint;
  if ( v5 != nullptr )
    flPathDistGoal = v5->flPathDistGoal;
  else
    flPathDistGoal = 0.0;
  v7 = m_pFirstWaypoint->vecLocation.y - startPos->y;
  v8 = v7 * v7;
  if ( m_pFirstWaypoint->m_iWPType != NAV_GROUND )
    v8 = v8
       + (float)((float)(m_pFirstWaypoint->vecLocation.z - startPos->z)
               * (float)(m_pFirstWaypoint->vecLocation.z - startPos->z));
  return flPathDistGoal
       + fsqrt(
           v8
         + (float)((float)(m_pFirstWaypoint->vecLocation.x - startPos->x)
                 * (float)(m_pFirstWaypoint->vecLocation.x - startPos->x)));
}

//------------------------------------------------------------------------------
// Address: 0x10080A80
// Name: public: class Vector CAI_Path::GetGoalDirection(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_Path::GetGoalDirection(CAI_Path *this, Vector *result, const Vector *startPos)
{
  unsigned int m_Index; // eax
  AI_Waypoint_t *v5; // eax
  float *p_x; // edi
  unsigned int v7; // eax
  CBaseEntity *m_pEntity; // esi
  float v9; // xmm0_4
  CBaseEntity *v10; // esi
  AI_Waypoint_t *Last; // eax
  const Vector *p_vecLocation; // ecx
  float x; // xmm0_4
  float z; // edx
  Vector goalDirection; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  m_Index = this->m_goalDirectionTarget.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    if ( vec3_origin.x == this->m_goalDirection.x
      && vec3_origin.y == this->m_goalDirection.y
      && vec3_origin.z == this->m_goalDirection.z )
    {
      Last = CAI_WaypointList::GetLast(this: &this->m_Waypoints);
      if ( Last != nullptr )
      {
        p_vecLocation = &Last->pPrev->vecLocation;
        x = Last->vecLocation.x;
        if ( p_vecLocation != nullptr )
        {
          goalDirection.x = x - p_vecLocation->x;
          goalDirection.y = Last->vecLocation.y - p_vecLocation->y;
        }
        else
        {
          p_vecLocation = startPos;
          goalDirection.x = x - startPos->x;
          goalDirection.y = Last->vecLocation.y - startPos->y;
        }
        goalDirection.z = Last->vecLocation.z - p_vecLocation->z;
        VectorNormalize(vec: &goalDirection);
        *result = goalDirection;
        return result;
      }
    }
LABEL_29:
    z = this->m_goalDirection.z;
    *(_QWORD *)&result->x = *(_QWORD *)&this->m_goalDirection.x;
    result->z = z;
    return result;
  }
  v5 = CAI_WaypointList::GetLast(this: &this->m_Waypoints);
  if ( v5 == nullptr )
    goto LABEL_29;
  p_x = &v5->pPrev->vecLocation.x;
  v7 = this->m_goalDirectionTarget.m_Index;
  if ( p_x != nullptr )
  {
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
    goalDirection.x = m_pEntity->m_vecAbsOrigin.x - *p_x;
    goalDirection.y = m_pEntity->m_vecAbsOrigin.y - p_x[1];
    v9 = m_pEntity->m_vecAbsOrigin.z - p_x[2];
  }
  else
  {
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      v10 = nullptr;
    else
      v10 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    if ( (v10->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v10, a2: (int)&savedregs);
    goalDirection.x = v10->m_vecAbsOrigin.x - startPos->x;
    goalDirection.y = v10->m_vecAbsOrigin.y - startPos->y;
    v9 = v10->m_vecAbsOrigin.z - startPos->z;
  }
  goalDirection.z = v9;
  VectorNormalize(vec: &goalDirection);
  *result = goalDirection;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10080CD0
// Name: public: float CAI_Path::GetGoalSpeed(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Path::GetGoalSpeed(CAI_Path *this, const Vector *startPos)
{
  unsigned int m_Index; // eax
  unsigned int v4; // eax
  IHandleEntity *m_pEntity; // ecx
  Vector targetVelocity; // [esp+4h] [ebp-1Ch] BYREF
  Vector goalDirection; // [esp+10h] [ebp-10h] BYREF
  float m_goalSpeed; // [esp+1Ch] [ebp-4h]
  float dot; // [esp+28h] [ebp+8h]

  m_Index = this->m_goalSpeedTarget.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    return this->m_goalSpeed;
  }
  CAI_Path::GetGoalDirection(this, result: &goalDirection, startPos);
  v4 = this->m_goalSpeedTarget.m_Index;
  if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *, Vector *))m_pEntity->__vftable[45].dtr_IHandleEntity)(
    a1: m_pEntity,
    a2: &targetVelocity);
  dot = (float)((float)(goalDirection.y * targetVelocity.y) + (float)(targetVelocity.x * goalDirection.x))
      + (float)(goalDirection.z * targetVelocity.z);
  if ( dot < 0.0 )
    dot = 0.0;
  m_goalSpeed = this->m_goalSpeed;
  if ( m_goalSpeed <= 0.0 )
    return dot;
  else
    return m_goalSpeed + dot;
}

//------------------------------------------------------------------------------
// Address: 0x10080DC0
// Name: public: void CAI_Path::Advance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Path::Advance(CAI_Path *this)
{
  AI_Waypoint_t *m_pFirstWaypoint; // eax
  CChoreoActor *pNext; // edi
  AI_Waypoint_t *v4; // ecx
  AI_Waypoint_t *pPrev; // ecx
  AI_Waypoint_t *Last; // eax

  m_pFirstWaypoint = this->m_Waypoints.m_pFirstWaypoint;
  if ( this->m_Waypoints.m_pFirstWaypoint == nullptr || (m_pFirstWaypoint->m_fWaypointFlags & 8) == 0 )
  {
    pNext = (CChoreoActor *)m_pFirstWaypoint->pNext;
    if ( pNext != nullptr )
    {
      if ( (m_pFirstWaypoint->m_fWaypointFlags & 4) != 0 )
        this->m_iLastNodeReached = m_pFirstWaypoint->iNodeID;
      if ( m_pFirstWaypoint != nullptr )
      {
        v4 = m_pFirstWaypoint->pNext;
        if ( v4 != nullptr )
          v4->pPrev = m_pFirstWaypoint->pPrev;
        pPrev = m_pFirstWaypoint->pPrev;
        if ( pPrev != nullptr )
          pPrev->pNext = m_pFirstWaypoint->pNext;
        CUtlMemoryPool::Free(this: &AI_Waypoint_t::s_Allocator, memBlock: m_pFirstWaypoint);
      }
      CAI_WaypointList::Set((CChoreoChannel *)this, actor: pNext);
      Last = CAI_WaypointList::GetLast(this: &this->m_Waypoints);
      if ( Last != nullptr )
        Last->flPathDistGoal = -1.0;
    }
    else
    {
      DevMsg(a1: "!!ERROR!! Force end of route with no goal!\n");
      this->m_Waypoints.m_pFirstWaypoint->m_fWaypointFlags |= 8u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101413A0
// Name: public: class Vector const __near & CAI_Path::ActualGoalPosition(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_Path::ActualGoalPosition(CAI_Path *this)
{
  return &this->m_goalPos;
}

//------------------------------------------------------------------------------
// Address: 0x103FEB30
// Name: CAI_Path_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Path_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Path>(__formal: nullptr);
  CAI_Path_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10080E50
// Name: struct datamap_t __near * DataMapInit<class CAI_Path>(class CAI_Path __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Path>()
{
  CActivityDataOps *v0; // eax

  if ( (_S2_30 & 1) == 0 )
  {
    _S2_30 |= 1u;
    nameHolder_61.m_pszBase = "CAI_Path";
    nameHolder_61.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_61.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_61.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_61.m_Names.m_Size = 0;
    nameHolder_61.m_Names.m_pElements = nullptr;
    nameHolder_61.m_nLenBase = 8;
    atexit(func: DataMapInit_CAI_Path__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Path::m_DataMap.baseMap = nullptr;
  if ( (_S2_30 & 2) == 0 )
  {
    _S2_30 |= 2u;
    dataDesc_59[2].pSaveRestoreOps = ActivityDataOps();
    *(_QWORD *)&dataDesc_59[2].td = 0;
    *(_QWORD *)&dataDesc_59[2].override_field = 0;
    *(_QWORD *)&dataDesc_59[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_59[2].flatOffset[1] = 0;
    dataDesc_59[3].fieldSize = 1;
    *(_QWORD *)dataDesc_59[3].flatOffset = 0;
    dataDesc_59[4].fieldOffset = 12;
    dataDesc_59[5].fieldSizeInBytes = 12;
    dataDesc_59[3].fieldTolerance = 0.0;
    dataDesc_59[4].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_59[4].flatOffset = 0;
    dataDesc_59[5].fieldTolerance = 0.0;
    dataDesc_59[6].fieldTolerance = 0.0;
    dataDesc_59[2].inputFunc = nullptr;
    dataDesc_59[3].fieldType = FIELD_EHANDLE;
    dataDesc_59[3].fieldName = "m_target";
    dataDesc_59[3].fieldOffset = 16;
    dataDesc_59[3].flags = 2;
    dataDesc_59[3].externalName = nullptr;
    dataDesc_59[3].pSaveRestoreOps = nullptr;
    dataDesc_59[3].inputFunc = nullptr;
    dataDesc_59[3].td = nullptr;
    dataDesc_59[3].fieldSizeInBytes = 4;
    dataDesc_59[3].override_field = nullptr;
    dataDesc_59[3].override_count = 0;
    *(_DWORD *)&dataDesc_59[3].flatGroup = 0;
    dataDesc_59[4].fieldType = FIELD_INTEGER;
    dataDesc_59[4].fieldName = "m_sequence";
    dataDesc_59[4].fieldSize = 1;
    dataDesc_59[4].flags = 2;
    dataDesc_59[4].externalName = nullptr;
    dataDesc_59[4].pSaveRestoreOps = nullptr;
    dataDesc_59[4].inputFunc = nullptr;
    dataDesc_59[4].td = nullptr;
    dataDesc_59[4].fieldSizeInBytes = 4;
    dataDesc_59[4].override_field = nullptr;
    dataDesc_59[4].override_count = 0;
    *(_DWORD *)&dataDesc_59[4].flatGroup = 0;
    dataDesc_59[5].fieldType = FIELD_VECTOR;
    dataDesc_59[5].fieldName = "m_vecTargetOffset";
    dataDesc_59[5].fieldOffset = 20;
    dataDesc_59[5].fieldSize = 1;
    dataDesc_59[5].flags = 2;
    dataDesc_59[5].externalName = nullptr;
    dataDesc_59[5].pSaveRestoreOps = nullptr;
    dataDesc_59[5].inputFunc = nullptr;
    dataDesc_59[5].td = nullptr;
    dataDesc_59[5].override_field = nullptr;
    dataDesc_59[5].override_count = 0;
    *(_QWORD *)dataDesc_59[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_59[5].flatGroup = 0;
    dataDesc_59[6].fieldType = FIELD_FLOAT;
    dataDesc_59[6].fieldName = "m_waypointTolerance";
    dataDesc_59[6].fieldOffset = 32;
    dataDesc_59[6].fieldSize = 1;
    dataDesc_59[6].flags = 2;
    dataDesc_59[6].externalName = nullptr;
    dataDesc_59[6].pSaveRestoreOps = nullptr;
    dataDesc_59[6].inputFunc = nullptr;
    dataDesc_59[6].td = nullptr;
    dataDesc_59[6].fieldSizeInBytes = 4;
    dataDesc_59[6].override_field = nullptr;
    dataDesc_59[6].override_count = 0;
    *(_QWORD *)dataDesc_59[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_59[6].flatGroup = 0;
    dataDesc_59[7].fieldType = FIELD_CUSTOM;
    dataDesc_59[7].fieldName = "m_arrivalActivity";
    dataDesc_59[7].fieldOffset = 36;
    dataDesc_59[7].fieldSize = 1;
    dataDesc_59[7].flags = 2;
    dataDesc_59[7].externalName = nullptr;
    v0 = ActivityDataOps();
    dataDesc_59[8].fieldSize = 1;
    dataDesc_59[9].fieldSize = 1;
    dataDesc_59[8].flags = 2;
    dataDesc_59[9].flags = 2;
    dataDesc_59[9].fieldType = FIELD_BOOLEAN;
    dataDesc_59[10].fieldSize = 1;
    dataDesc_59[11].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)dataDesc_59[8].flatOffset = 0;
    dataDesc_59[7].pSaveRestoreOps = v0;
    dataDesc_59[10].flags = 2;
    dataDesc_59[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_59[7].td = 0;
    *(_QWORD *)&dataDesc_59[7].override_field = 0;
    *(_QWORD *)&dataDesc_59[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_59[7].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_59[9].flatOffset = 0;
    dataDesc_59[7].inputFunc = nullptr;
    dataDesc_59[8].fieldType = FIELD_INTEGER;
    dataDesc_59[8].fieldName = "m_arrivalSequence";
    dataDesc_59[8].fieldOffset = 40;
    dataDesc_59[8].externalName = nullptr;
    dataDesc_59[8].pSaveRestoreOps = nullptr;
    dataDesc_59[8].inputFunc = nullptr;
    dataDesc_59[8].td = nullptr;
    dataDesc_59[8].fieldSizeInBytes = 4;
    dataDesc_59[8].override_field = nullptr;
    dataDesc_59[8].override_count = 0;
    dataDesc_59[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_59[8].flatGroup = 0;
    dataDesc_59[9].fieldName = "m_bGoalPosSet";
    dataDesc_59[9].fieldOffset = 48;
    dataDesc_59[9].externalName = nullptr;
    dataDesc_59[9].pSaveRestoreOps = nullptr;
    dataDesc_59[9].inputFunc = nullptr;
    dataDesc_59[9].td = nullptr;
    dataDesc_59[9].fieldSizeInBytes = 1;
    dataDesc_59[9].override_field = nullptr;
    dataDesc_59[9].override_count = 0;
    dataDesc_59[9].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_59[9].flatGroup = 0;
    dataDesc_59[10].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_59[10].fieldName = "m_goalPos";
    dataDesc_59[10].fieldOffset = 52;
    dataDesc_59[10].externalName = nullptr;
    dataDesc_59[10].pSaveRestoreOps = nullptr;
    dataDesc_59[10].inputFunc = nullptr;
    dataDesc_59[10].td = nullptr;
    dataDesc_59[10].fieldSizeInBytes = 12;
    dataDesc_59[10].override_field = nullptr;
    dataDesc_59[10].override_count = 0;
    dataDesc_59[10].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_59[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_59[10].flatGroup = 0;
    dataDesc_59[11].fieldName = "m_bGoalTypeSet";
    dataDesc_59[11].fieldOffset = 64;
    dataDesc_59[11].flags = 2;
    dataDesc_59[11].externalName = nullptr;
    *(_QWORD *)dataDesc_59[11].flatOffset = 0;
    *(_QWORD *)dataDesc_59[12].flatOffset = 0;
    dataDesc_59[12].fieldType = FIELD_INTEGER;
    dataDesc_59[13].fieldType = FIELD_INTEGER;
    *(_QWORD *)dataDesc_59[13].flatOffset = 0;
    dataDesc_59[12].fieldSize = 1;
    dataDesc_59[13].fieldSize = 1;
    dataDesc_59[14].fieldSize = 1;
    dataDesc_59[15].fieldSize = 1;
    *(_QWORD *)dataDesc_59[14].flatOffset = 0;
    dataDesc_59[11].pSaveRestoreOps = nullptr;
    dataDesc_59[11].inputFunc = nullptr;
    dataDesc_59[11].td = nullptr;
    dataDesc_59[11].fieldSizeInBytes = 1;
    dataDesc_59[11].override_field = nullptr;
    dataDesc_59[11].override_count = 0;
    dataDesc_59[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_59[11].flatGroup = 0;
    dataDesc_59[12].fieldName = "m_goalType";
    dataDesc_59[12].fieldOffset = 68;
    dataDesc_59[12].flags = 2;
    dataDesc_59[12].externalName = nullptr;
    dataDesc_59[12].pSaveRestoreOps = nullptr;
    dataDesc_59[12].inputFunc = nullptr;
    dataDesc_59[12].td = nullptr;
    dataDesc_59[12].fieldSizeInBytes = 4;
    dataDesc_59[12].override_field = nullptr;
    dataDesc_59[12].override_count = 0;
    dataDesc_59[12].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_59[12].flatGroup = 0;
    dataDesc_59[13].fieldName = "m_goalFlags";
    dataDesc_59[13].fieldOffset = 72;
    dataDesc_59[13].flags = 2;
    dataDesc_59[13].externalName = nullptr;
    dataDesc_59[13].pSaveRestoreOps = nullptr;
    dataDesc_59[13].inputFunc = nullptr;
    dataDesc_59[13].td = nullptr;
    dataDesc_59[13].fieldSizeInBytes = 4;
    dataDesc_59[13].override_field = nullptr;
    dataDesc_59[13].override_count = 0;
    dataDesc_59[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_59[13].flatGroup = 0;
    dataDesc_59[14].fieldType = FIELD_TIME;
    dataDesc_59[14].fieldName = "m_routeStartTime";
    dataDesc_59[14].fieldOffset = 76;
    dataDesc_59[14].flags = 2;
    dataDesc_59[14].externalName = nullptr;
    dataDesc_59[14].pSaveRestoreOps = nullptr;
    dataDesc_59[14].inputFunc = nullptr;
    dataDesc_59[14].td = nullptr;
    dataDesc_59[14].fieldSizeInBytes = 4;
    dataDesc_59[14].override_field = nullptr;
    dataDesc_59[14].override_count = 0;
    dataDesc_59[14].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_59[14].flatGroup = 0;
    dataDesc_59[15].fieldType = FIELD_VECTOR;
    dataDesc_59[15].fieldName = "m_goalDirection";
    dataDesc_59[15].fieldOffset = 80;
    dataDesc_59[15].flags = 2;
    dataDesc_59[15].externalName = nullptr;
    dataDesc_59[15].pSaveRestoreOps = nullptr;
    dataDesc_59[15].inputFunc = nullptr;
    dataDesc_59[15].td = nullptr;
    dataDesc_59[15].fieldSizeInBytes = 12;
    dataDesc_59[15].override_field = nullptr;
    dataDesc_59[15].override_count = 0;
    dataDesc_59[15].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_59[15].flatOffset = 0;
    *(_DWORD *)&dataDesc_59[15].flatGroup = 0;
    dataDesc_59[16].fieldType = FIELD_EHANDLE;
    dataDesc_59[16].fieldName = "m_goalDirectionTarget";
    dataDesc_59[16].fieldOffset = 92;
    *(_QWORD *)dataDesc_59[16].flatOffset = 0;
    dataDesc_59[16].fieldSize = 1;
    dataDesc_59[17].fieldSize = 1;
    dataDesc_59[18].fieldType = FIELD_EHANDLE;
    dataDesc_59[16].fieldTolerance = 0.0;
    dataDesc_59[17].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_59[17].flatOffset = 0;
    dataDesc_59[18].fieldTolerance = 0.0;
    dataDesc_59[19].fieldTolerance = 0.0;
    dataDesc_59[16].fieldSizeInBytes = 4;
    dataDesc_59[17].fieldSizeInBytes = 4;
    dataDesc_59[18].fieldSizeInBytes = 4;
    dataDesc_59[19].fieldSizeInBytes = 4;
    dataDesc_59[16].flags = 2;
    dataDesc_59[16].externalName = nullptr;
    dataDesc_59[16].pSaveRestoreOps = nullptr;
    dataDesc_59[16].inputFunc = nullptr;
    dataDesc_59[16].td = nullptr;
    dataDesc_59[16].override_field = nullptr;
    dataDesc_59[16].override_count = 0;
    *(_DWORD *)&dataDesc_59[16].flatGroup = 0;
    dataDesc_59[17].fieldType = FIELD_FLOAT;
    dataDesc_59[17].fieldName = "m_goalSpeed";
    dataDesc_59[17].fieldOffset = 96;
    dataDesc_59[17].flags = 2;
    dataDesc_59[17].externalName = nullptr;
    dataDesc_59[17].pSaveRestoreOps = nullptr;
    dataDesc_59[17].inputFunc = nullptr;
    dataDesc_59[17].td = nullptr;
    dataDesc_59[17].override_field = nullptr;
    dataDesc_59[17].override_count = 0;
    *(_DWORD *)&dataDesc_59[17].flatGroup = 0;
    dataDesc_59[18].fieldName = "m_goalSpeedTarget";
    dataDesc_59[18].fieldOffset = 100;
    *(_DWORD *)&dataDesc_59[18].fieldSize = 131073;
    dataDesc_59[18].externalName = nullptr;
    dataDesc_59[18].pSaveRestoreOps = nullptr;
    dataDesc_59[18].inputFunc = nullptr;
    dataDesc_59[18].td = nullptr;
    dataDesc_59[18].override_field = nullptr;
    dataDesc_59[18].override_count = 0;
    *(_QWORD *)dataDesc_59[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_59[18].flatGroup = 0;
    dataDesc_59[19].fieldType = FIELD_FLOAT;
    dataDesc_59[19].fieldName = "m_goalStoppingDistance";
    dataDesc_59[19].fieldOffset = 104;
    *(_DWORD *)&dataDesc_59[19].fieldSize = 131073;
    dataDesc_59[19].externalName = nullptr;
    dataDesc_59[19].pSaveRestoreOps = nullptr;
    dataDesc_59[19].inputFunc = nullptr;
    dataDesc_59[19].td = nullptr;
    dataDesc_59[19].override_field = nullptr;
    dataDesc_59[19].override_count = 0;
    *(_QWORD *)dataDesc_59[19].flatOffset = 0;
    *(_DWORD *)&dataDesc_59[19].flatGroup = 0;
  }
  CAI_Path::m_DataMap.dataNumFields = 19;
  CAI_Path::m_DataMap.dataDesc = &dataDesc_59[1];
  return &CAI_Path::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FEB40
// Name: _dynamic_initializer_for__CAI_Path::gm_InvalidWaypoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CAI_Path::gm_InvalidWaypoint__()
{
  Vector initPosition; // [esp+10h] [ebp-Ch] BYREF

  memset((void *)&initPosition, 0, sizeof(initPosition));
  AI_Waypoint_t::AI_Waypoint_t(
    this: &CAI_Path::gm_InvalidWaypoint,
    &initPosition,
    initYaw: 0.0,
    initNavType: NAV_NONE,
    initWaypointFlags: 0,
    initNodeID: 0);
  return atexit(func: dynamic_atexit_destructor_for__CAI_Path::gm_InvalidWaypoint__);
}

//------------------------------------------------------------------------------
// Address: 0x103FEB90
// Name: _dynamic_initializer_for__debugscriptconditions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__debugscriptconditions__()
{
  ConVar::ConVar(this: &debugscriptconditions, pName: "ai_debugscriptconditions", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__debugscriptconditions__);
}

//------------------------------------------------------------------------------
// Address: 0x103FEBC0
// Name: _dynamic_initializer_for__ai_script_conditions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_script_conditions__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_ScriptConditions> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_script_conditions,
           a3: "ai_script_conditions");
}
