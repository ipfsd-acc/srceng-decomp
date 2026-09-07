// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_navigator.cpp
// Functions: 123
// ============================================================

#include "game\server\ai_navigator.h"

//------------------------------------------------------------------------------
// Address: 0x10062700
// Name: public: void AI_Waypoint_t::SetNext(struct AI_Waypoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AI_Waypoint_t::SetNext(AI_Waypoint_t *this, AI_Waypoint_t *p)
{
  AI_Waypoint_t *pNext; // eax
  AI_Waypoint_t *pPrev; // eax

  pNext = this->pNext;
  if ( pNext != nullptr )
    pNext->pPrev = nullptr;
  this->pNext = p;
  if ( p != nullptr )
  {
    pPrev = p->pPrev;
    if ( pPrev != nullptr )
      pPrev->pNext = nullptr;
    this->pNext->pPrev = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062730
// Name: private: static void CAI_Navigator::CalculateDeflection(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_Navigator::CalculateDeflection(
        const Vector *start,
        const Vector *dir,
        const Vector *normal,
        Vector *pResult)
{
  float z; // xmm2_4
  float y; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm4_4
  float v8; // xmm3_4

  z = normal->z;
  y = normal->y;
  v6 = (float)(z * dir->y) - (float)(y * dir->z);
  v7 = (float)(normal->x * dir->z) - (float)(dir->x * z);
  v8 = (float)(dir->x * y) - (float)(normal->x * dir->y);
  pResult->x = (float)(y * v8) - (float)(z * v7);
  pResult->y = (float)(normal->z * v6) - (float)(normal->x * v8);
  pResult->z = (float)(normal->x * v7) - (float)(v6 * normal->y);
  VectorNormalize(vec: pResult);
}

//------------------------------------------------------------------------------
// Address: 0x100627D0
// Name: public: class Vector const __near & CAI_Navigator::GetGoalPos(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_Navigator::GetGoalPos(CAI_Navigator *this)
{
  return CAI_Path::BaseGoalPosition(this: this->m_pPath);
}

//------------------------------------------------------------------------------
// Address: 0x100627E0
// Name: public: void CAI_Navigator::SetGoalTolerance(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SetGoalTolerance(CAI_Navigator *this, float tolerance)
{
  this->m_pPath->m_goalTolerance = tolerance;
}

//------------------------------------------------------------------------------
// Address: 0x10062800
// Name: public: enum Activity CAI_Navigator::SetMovementActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_Navigator::SetMovementActivity(CAI_Navigator *this, Activity activity)
{
  return CAI_Path::SetMovementActivity(this: this->m_pPath, activity);
}

//------------------------------------------------------------------------------
// Address: 0x10062810
// Name: public: enum Activity CAI_Navigator::GetMovementActivity(void)const
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_Navigator::GetMovementActivity(CAI_Navigator *this)
{
  return this->m_pPath->m_activity;
}

//------------------------------------------------------------------------------
// Address: 0x10062820
// Name: public: void CAI_Navigator::SetArrivalActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SetArrivalActivity(CAI_Navigator *this, Activity activity)
{
  CAI_Path::SetArrivalActivity(this: this->m_pPath, activity);
}

//------------------------------------------------------------------------------
// Address: 0x10062830
// Name: public: void CAI_Navigator::SetArrivalSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SetArrivalSequence(CAI_Navigator *this, int sequence)
{
  CAI_Path::SetArrivalActivity(this: this->m_pPath, activity: ACT_INVALID);
  CAI_Path::SetArrivalSequence(this: this->m_pPath, sequence);
}

//------------------------------------------------------------------------------
// Address: 0x10062860
// Name: public: enum Activity CAI_Navigator::GetArrivalActivity(void)const
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_Navigator::GetArrivalActivity(CAI_Navigator *this)
{
  return CAI_Path::GetArrivalActivity(this: this->m_pPath);
}

//------------------------------------------------------------------------------
// Address: 0x10062870
// Name: public: void CAI_Navigator::SetArrivalDirection(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SetArrivalDirection(CAI_Navigator *this, const Vector *goalDirection)
{
  CAI_Path::SetGoalDirection(this: this->m_pPath, goalDirection);
}

//------------------------------------------------------------------------------
// Address: 0x10062880
// Name: public: void CAI_Navigator::SetArrivalDirection(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SetArrivalDirection(CAI_Navigator *this, const QAngle *goalAngle)
{
  Vector goalDirection; // [esp+4h] [ebp-Ch] BYREF

  AngleVectors(angles: goalAngle, forward: &goalDirection);
  CAI_Path::SetGoalDirection(this: this->m_pPath, &goalDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100628B0
// Name: public: void CAI_Navigator::SetArrivalDirection(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SetArrivalDirection(CAI_Navigator *this, CBaseEntity *pTarget)
{
  CAI_Path::SetGoalDirection(this: this->m_pPath, pTarget);
}

//------------------------------------------------------------------------------
// Address: 0x100628C0
// Name: public: void CAI_Navigator::SetArrivalDistance(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SetArrivalDistance(CAI_Navigator *this, float flDistance)
{
  CAI_Path::SetGoalStoppingDistance(this: this->m_pPath, flDistance);
}

//------------------------------------------------------------------------------
// Address: 0x100628E0
// Name: public: float CAI_Navigator::GetArrivalDistance(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Navigator::GetArrivalDistance(CAI_Navigator *this)
{
  return CAI_Path::GetGoalStoppingDistance(this: this->m_pPath);
}

//------------------------------------------------------------------------------
// Address: 0x100628F0
// Name: public: class Vector const __near & CAI_Navigator::GetCurWaypointPos(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CAI_Navigator::GetCurWaypointPos(CAI_Navigator *this)
{
  return CAI_Path::CurWaypointPos(this: this->m_pPath);
}

//------------------------------------------------------------------------------
// Address: 0x10062900
// Name: public: enum GoalType_t CAI_Navigator::GetGoalType(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall CAI_Navigator::GetGoalType(CAI_Navigator *this)
{
  return CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath);
}

//------------------------------------------------------------------------------
// Address: 0x10062910
// Name: public: int CAI_Navigator::GetGoalFlags(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAI_Navigator::GetGoalFlags(CAI_Navigator *this)
{
  return vgui::BuildGroup::GetCurrentPanel(this: (vgui::Panel *)this->m_pPath);
}

//------------------------------------------------------------------------------
// Address: 0x10062920
// Name: public: bool CAI_Navigator::CurWaypointIsGoal(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Navigator::CurWaypointIsGoal(CAI_Navigator *this)
{
  return CAI_Path::CurWaypointIsGoal(this: this->m_pPath);
}

//------------------------------------------------------------------------------
// Address: 0x10062930
// Name: public: bool CAI_Navigator::IsGoalSet(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_Navigator::IsGoalSet(CAI_Navigator *this)
{
  return CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10062940
// Name: public: bool CAI_Navigator::IsGoalActive(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_Navigator::IsGoalActive(CAI_Navigator *this)
{
  CAI_Path *m_pPath; // eax

  m_pPath = this->m_pPath;
  return m_pPath != nullptr && m_pPath->m_Waypoints.m_pFirstWaypoint != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10062960
// Name: public: void CAI_Navigator::SetNavType(enum Navigation_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SetNavType(CAI_Navigator *this, Navigation_t navType)
{
  this->m_navType = navType;
}

//------------------------------------------------------------------------------
// Address: 0x10062970
// Name: private: bool CAI_Navigator::IsMovingOutOfWay(struct AILocalMoveGoal_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Navigator::IsMovingOutOfWay(
        CAI_Navigator *this,
        const AILocalMoveGoal_t *moveGoal,
        float distClear)
{
  CAI_BaseNPC *v3; // esi
  bool result; // al
  CAI_Motor *m_pMotor; // esi
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm0_4

  result = false;
  if ( moveGoal->directTrace.pObstruction != nullptr )
  {
    v3 = moveGoal->directTrace.pObstruction->MyNPCPointer(this: moveGoal->directTrace.pObstruction);
    if ( v3 != nullptr && v3->IsMoving(this: v3) )
    {
      if ( distClear > moveGoal->curExpectedDist * 0.75 )
        return true;
      m_pMotor = v3->m_pMotor;
      v6 = 0.0;
      v7 = fsqrt(
             (float)(m_pMotor->m_vecVelocity.y * m_pMotor->m_vecVelocity.y)
           + (float)(m_pMotor->m_vecVelocity.x * m_pMotor->m_vecVelocity.x));
      if ( v7 == 0.0 )
      {
        v8 = 0.0;
      }
      else
      {
        v6 = (float)(1.0 / v7) * m_pMotor->m_vecVelocity.x;
        v8 = (float)(1.0 / v7) * m_pMotor->m_vecVelocity.y;
      }
      if ( (float)((float)(moveGoal->dir.y * v8) + (float)(moveGoal->dir.x * v6)) > -0.25 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062A80
// Name: public: virtual bool CAI_Navigator::ShouldMove(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Navigator::ShouldMove(CAI_Navigator *this, bool bHasAGoal)
{
  int result; // eax

  if ( !bHasAGoal )
    return 0;
  result = 1;
  if ( this->m_pPath->m_activity <= ACT_IDLE )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062AA0
// Name: private: void CAI_Navigator::SimplifyPathInsertSimplification(struct AI_Waypoint_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SimplifyPathInsertSimplification(
        CAI_Navigator *this,
        AI_Waypoint_t *pSegmentStart,
        const Vector *point)
{
  AI_Waypoint_t *pNext; // edi
  AI_Waypoint_t *v5; // eax
  AI_Waypoint_t *v6; // esi
  CAI_Path *j; // ecx
  AI_Waypoint_t *v8; // eax
  AI_Waypoint_t *pPrev; // edi
  CAI_Path *i; // ecx

  if ( pSegmentStart->vecLocation.x == point->x
    && pSegmentStart->vecLocation.y == point->y
    && pSegmentStart->vecLocation.z == point->z )
  {
    for ( i = this->m_pPath; i->m_Waypoints.m_pFirstWaypoint != pSegmentStart; i = this->m_pPath )
      CAI_Path::Advance(this: i);
  }
  else
  {
    pNext = pSegmentStart->pNext;
    v5 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
    if ( v5 != nullptr )
      v6 = AI_Waypoint_t::AI_Waypoint_t(
             this: v5,
             initPosition: point,
             initYaw: 0.0,
             initNavType: pSegmentStart->m_iWPType,
             initWaypointFlags: 0,
             initNodeID: -1);
    else
      v6 = nullptr;
    for ( j = this->m_pPath; j->m_Waypoints.m_pFirstWaypoint != pNext; j = this->m_pPath )
      CAI_Path::Advance(this: j);
    v8 = v6->pNext;
    if ( v8 != nullptr )
      v8->pPrev = nullptr;
    v6->pNext = pNext;
    if ( pNext != nullptr )
    {
      pPrev = pNext->pPrev;
      if ( pPrev != nullptr )
        pPrev->pNext = nullptr;
      v6->pNext->pPrev = v6;
    }
    CAI_Path::SetWaypoints(this: this->m_pPath, route: v6, fSetGoalFromLast: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062B90
// Name: public: class CBaseEntity __near * CAI_Navigator::GetNextPathcorner(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Hint *__thiscall CAI_Navigator::GetNextPathcorner(CAI_Navigator *this, CBaseEntity *pPathCorner)
{
  CAI_Hint *result; // eax
  _DWORD *v4; // eax
  int v5; // eax
  CAI_Network *m_pAINetwork; // ecx

  result = nullptr;
  if ( pPathCorner != nullptr )
  {
    result = (CAI_Hint *)CBaseEntity::GetNextTarget(this: pPathCorner);
    if ( result == nullptr )
    {
      v4 = __RTDynamicCast(
             inptr: pPathCorner,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CAI_Hint `RTTI Type Descriptor',
             isReference: 0);
      if ( v4 == nullptr )
        return nullptr;
      v5 = v4[229];
      if ( v5 == -1 )
      {
        return nullptr;
      }
      else
      {
        m_pAINetwork = this->m_pAINetwork;
        if ( v5 < 0 || v5 >= m_pAINetwork->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
          return (CAI_Hint *)MEMORY[0x68];
        }
        else
        {
          return m_pAINetwork->m_pAInode[v5]->m_pHint;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062C10
// Name: public: void CAI_Navigator::IgnoreStoppingPath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::IgnoreStoppingPath(CAI_Navigator *this)
{
  CAI_WaypointList *m_pClippedWaypoints; // ecx
  Navigation_t m_iWPType; // eax

  m_pClippedWaypoints = this->m_pClippedWaypoints;
  if ( m_pClippedWaypoints != nullptr && m_pClippedWaypoints->m_pFirstWaypoint != nullptr )
  {
    m_iWPType = m_pClippedWaypoints->m_pFirstWaypoint->m_iWPType;
    if ( m_iWPType != NAV_JUMP && m_iWPType != NAV_CLIMB )
      CAI_WaypointList::RemoveAll(this: m_pClippedWaypoints);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062C30
// Name: protected: class CBaseEntity __near * CAI_Component::GetGoalEnt(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_Component::GetGoalEnt(CAI_Component *this)
{
  unsigned int m_Index; // eax

  m_Index = this->m_pOuter->m_hGoalEnt.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10062C70
// Name: public: class CBaseEntity __near * CAI_Path::GetTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_Path::GetTarget(CAI_Path *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_target.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10062CA0
// Name: public: virtual bool CAI_NavInHintGroupFilter::IsValid(class CAI_Node __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_NavInHintGroupFilter::IsValid(CAI_NavInHintGroupFilter *this, CAI_Node *pNode)
{
  CAI_Hint *m_pHint; // eax

  m_pHint = pNode->m_pHint;
  return m_pHint != nullptr && m_pHint->m_NodeData.strGroup.pszValue == this->m_iszGroup.pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x10062CD0
// Name: public: virtual void CAI_Navigator::Init(class CAI_Network __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::Init(CAI_Navigator *this, CAI_Network *pNetwork)
{
  CAI_BaseNPC *m_pOuter; // eax

  m_pOuter = this->m_pOuter;
  this->m_pMotor = m_pOuter->m_pMotor;
  this->m_pMoveProbe = m_pOuter->m_pMoveProbe;
  this->m_pLocalNavigator = m_pOuter->m_pLocalNavigator;
  this->m_pAINetwork = pNetwork;
}

//------------------------------------------------------------------------------
// Address: 0x10062D00
// Name: protected: class CBaseEntity __near * CAI_Navigator::GetNavTargetEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_Navigator::GetNavTargetEntity(CAI_Navigator *this)
{
  unsigned int m_Index; // eax

  if ( CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath) == 2
    || CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath) == 1 )
  {
    return CAI_BaseNPC::GetNavTargetEntity(this: this->m_pOuter);
  }
  m_Index = this->m_pPath->m_target.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10062D60
// Name: public: class CBaseEntity __near * CAI_Navigator::GetGoalTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_Navigator::GetGoalTarget(CAI_Navigator *this)
{
  unsigned int m_Index; // eax

  m_Index = this->m_pPath->m_target.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10062D90
// Name: public: int CAI_Navigator::GetMovementSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Navigator::GetMovementSequence(CAI_Navigator *this)
{
  CAI_Path *m_pPath; // ecx
  int result; // eax
  Activity m_activity; // ebx
  CAI_BaseNPC *m_pOuter; // edi
  Activity v6; // eax
  CAI_Path *v7; // edi
  Activity v8; // eax
  const char *ActivityName; // eax
  CAI_BaseNPC *v10; // edi
  Activity v11; // eax
  Activity ArrivalActivity; // [esp-Ch] [ebp-14h]
  CAI_BaseNPC *pAI; // [esp+4h] [ebp-4h]

  m_pPath = this->m_pPath;
  result = m_pPath->m_sequence;
  if ( result == -1 )
  {
    m_activity = m_pPath->m_activity;
    m_pOuter = this->m_pOuter;
    v6 = CAI_BaseNPC::TranslateActivity(this: m_pOuter, idealActivity: m_activity, pIdealWeaponActivity: nullptr);
    result = CBaseAnimating::SelectWeightedSequence(this: m_pOuter, activity: v6);
    if ( result == -1 )
    {
      v7 = this->m_pPath;
      pAI = this->m_pOuter;
      ArrivalActivity = CAI_Path::GetArrivalActivity(this: v7);
      v8 = CAI_Path::GetArrivalActivity(this: v7);
      ActivityName = CAI_BaseNPC::GetActivityName(actID: v8);
      DevMsg(pAI, pszFormat: "No appropriate sequence for movement activity %s (%d)\n", ActivityName, ArrivalActivity);
      if ( m_activity == ACT_SCRIPT_CUSTOM_MOVE )
      {
        result = CAI_BaseNPC::GetScriptCustomMoveSequence(this: this->m_pOuter);
        this->m_pPath->m_sequence = result;
        return result;
      }
      v10 = this->m_pOuter;
      v11 = CAI_BaseNPC::TranslateActivity(this: v10, idealActivity: ACT_WALK, pIdealWeaponActivity: nullptr);
      result = CBaseAnimating::SelectWeightedSequence(this: v10, activity: v11);
    }
    this->m_pPath->m_sequence = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062E40
// Name: public: int CAI_Navigator::GetArrivalSequence(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Navigator::GetArrivalSequence(CAI_Navigator *this, int curSequence)
{
  int result; // eax
  Activity StoppedActivity; // eax
  CAI_BaseNPC *m_pOuter; // edi
  Activity v6; // eax
  int v7; // edi
  CAI_Path *m_pPath; // edi
  CAI_BaseNPC *v9; // ebx
  Activity v10; // eax
  const char *ActivityName; // eax
  CAI_BaseNPC *v12; // edi
  Activity v13; // eax
  Activity ArrivalActivity; // [esp-Ch] [ebp-10h]

  result = CAI_Path::GetArrivalSequence(this: this->m_pPath);
  if ( result == -1 )
  {
    StoppedActivity = CAI_BaseNPC::GetStoppedActivity(this: this->m_pOuter);
    if ( StoppedActivity == ACT_INVALID )
      StoppedActivity = ACT_IDLE;
    m_pOuter = this->m_pOuter;
    v6 = CAI_BaseNPC::TranslateActivity(this: m_pOuter, idealActivity: StoppedActivity, pIdealWeaponActivity: nullptr);
    v7 = CBaseAnimating::SelectWeightedSequence(this: m_pOuter, activity: v6, curSequence);
    if ( v7 == -1 )
    {
      m_pPath = this->m_pPath;
      v9 = this->m_pOuter;
      ArrivalActivity = CAI_Path::GetArrivalActivity(this: m_pPath);
      v10 = CAI_Path::GetArrivalActivity(this: m_pPath);
      ActivityName = CAI_BaseNPC::GetActivityName(actID: v10);
      DevMsg(
        pAI: v9,
        pszFormat: "No appropriate sequence for arrival activity %s (%d)\n",
        ActivityName,
        ArrivalActivity);
      v12 = this->m_pOuter;
      v13 = CAI_BaseNPC::TranslateActivity(this: v12, idealActivity: ACT_IDLE, pIdealWeaponActivity: nullptr);
      v7 = CBaseAnimating::SelectWeightedSequence(this: v12, activity: v13, curSequence);
    }
    CAI_Path::SetArrivalSequence(this: this->m_pPath, sequence: v7);
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062EF0
// Name: public: class Vector CAI_Navigator::GetArrivalDirection(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_Navigator::GetArrivalDirection(CAI_Navigator *this, Vector *result)
{
  CAI_BaseNPC *m_pOuter; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
  CAI_Path::GetGoalDirection(this: this->m_pPath, result, startPos: &m_pOuter->m_vecAbsOrigin);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062F30
// Name: public: float CAI_Navigator::GetArrivalSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Navigator::GetArrivalSpeed(CAI_Navigator *this)
{
  CAI_BaseNPC *m_pOuter; // edi
  double result; // st7
  int ArrivalSequence; // eax
  float flSpeed; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
  result = CAI_Path::GetGoalSpeed(this: this->m_pPath, startPos: &m_pOuter->m_vecAbsOrigin);
  if ( result < 0.0 )
  {
    ArrivalSequence = CAI_Navigator::GetArrivalSequence(this, curSequence: -1);
    if ( ArrivalSequence == -1 )
    {
      return 0.0;
    }
    else
    {
      flSpeed = CBaseAnimating::GetEntryVelocity(this: this->m_pOuter, a2: (int)&savedregs, iSequence: ArrivalSequence);
      CAI_Path::SetGoalSpeed(this: this->m_pPath, flSpeed);
      return flSpeed;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062FC0
// Name: public: float CAI_Navigator::GetPathTimeToGoal(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CAI_Navigator::GetPathTimeToGoal@<st0>(CAI_Navigator *this@<ecx>, int a2@<ebp>)
{
  CAI_BaseNPC *m_pOuter; // edi

  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_flGroundSpeed == 0.0 )
    return 0.0;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2);
  return CAI_Path::GetPathDistanceToGoal(this: this->m_pPath, startPos: &m_pOuter->m_vecAbsOrigin)
       / this->m_pOuter->m_flGroundSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x10063010
// Name: public: class Vector CAI_Navigator::GetNodePos(struct AI_PathNode_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_Navigator::GetNodePos(CAI_Navigator *this, Vector *result, AI_PathNode_t__ *node)
{
  Hull_t m_eHull; // edx
  CAI_Network *m_pAINetwork; // ecx

  m_eHull = this->m_pOuter->m_eHull;
  m_pAINetwork = this->m_pAINetwork;
  if ( (int)node < 0 || (int)node >= m_pAINetwork->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    CAI_Node::GetPosition(this: nullptr, result, hull: m_eHull);
    return result;
  }
  else
  {
    CAI_Node::GetPosition(this: m_pAINetwork->m_pAInode[(_DWORD)node], result, hull: m_eHull);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063070
// Name: private: void CAI_Navigator::ResetCalculations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::ResetCalculations(CAI_Navigator *this)
{
  CAI_LocalNavigator *m_pLocalNavigator; // ecx

  this->m_hPeerWaitingOn.m_Index = -1;
  this->m_PeerWaitMoveTimer.m_next = -1.0;
  this->m_PeerWaitClearTimer.m_next = -1.0;
  this->m_hBigStepGroundEnt.m_Index = -1;
  this->m_NextSidestepTimer.m_next = -1.0;
  this->m_bCalledStartMove = false;
  this->m_vPosBeginFailedSteer = vec3_invalid;
  m_pLocalNavigator = this->m_pLocalNavigator;
  this->m_timeBeginFailedSteer = 3.4028235e38;
  this->m_flLastSuccessfulSimplifyTime = -1.0;
  CAI_LocalNavigator::ResetMoveCalculations(this: m_pLocalNavigator);
  this->m_pMotor->ResetMoveCalculations(this: this->m_pMotor);
  this->m_pMoveProbe->m_hLastBlockingEnt.m_Index = -1;
  this->m_nNavFailCounter = 0;
  this->m_flLastNavFailTime = -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10063120
// Name: private: virtual bool CAI_Navigator::OnCalcBaseMove(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Navigator::OnCalcBaseMove(
        CAI_Navigator *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  return (*(unsigned __int8 (__stdcall **)(AILocalMoveGoal_t *, _DWORD, AIMoveResult_t *))(*(_DWORD *)(*((_DWORD *)this - 1) + 2284)
                                                                                         + 4))(
           a1: pMoveGoal,
           a2: LODWORD(distClear),
           a3: pResult) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10063160
// Name: protected: virtual enum AIMoveResult_t CAI_Navigator::MoveEnact(struct AILocalMoveGoal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
AIMoveResult_t __userpurge CAI_Navigator::MoveEnact@<eax>(
        CAI_Navigator *this@<ecx>,
        char a2@<efl>,
        const AILocalMoveGoal_t *baseMove)
{
  int v3; // eax
  float m_flLastSuccessfulSimplifyTime; // xmm0_4
  bool v6; // cf
  bool v7; // zf
  char v8; // sf
  char v9; // of
  char v10; // pf
  AIMoveResult_t result; // eax
  AILocalMoveGoal_t move; // [esp+8h] [ebp-B8h] BYREF
  AIMoveResult_t v13; // [esp+BCh] [ebp-4h] BYREF

  HIWORD(v3) = HIWORD(gpGlobals);
  m_flLastSuccessfulSimplifyTime = this->m_flLastSuccessfulSimplifyTime;
  v13 = AIMR_ILLEGAL;
  move = *baseMove;
  v6 = m_flLastSuccessfulSimplifyTime < gpGlobals->curtime;
  v10 = 0;
  v7 = m_flLastSuccessfulSimplifyTime == gpGlobals->curtime;
  v8 = 0;
  v9 = 0;
  BYTE1(v3) = a2;
  LOBYTE(v3) = v7;
  result = CAI_LocalNavigator::MoveCalc(this: this->m_pLocalNavigator, pMoveGoal: &move, bPreviouslyValidated: v3);
  v13 = result;
  if ( result != AIMR_OK )
  {
    if ( move.directTrace.pObstruction == nullptr )
    {
      this->m_hLastBlockingEnt.m_Index = -1;
      goto LABEL_7;
    }
    this->m_hLastBlockingEnt.m_Index = move.directTrace.pObstruction->GetRefEHandle(this: move.directTrace.pObstruction)->m_Index;
  }
  else
  {
    this->m_hLastBlockingEnt.m_Index = -1;
    this->m_pMoveProbe->m_hLastBlockingEnt.m_Index = -1;
  }
  result = v13;
LABEL_7:
  if ( result != AIMR_OK )
  {
    if ( result == AIMR_CHANGE_TYPE )
      goto LABEL_12;
  }
  else if ( !this->m_fNavComplete )
  {
    result = (AIMoveResult_t)CAI_Motor::MoveNormalExecute(this: this->m_pMotor, &move);
    v13 = result;
    goto LABEL_12;
  }
  this->m_pMotor->MoveStop(this: this->m_pMotor);
  result = v13;
LABEL_12:
  if ( result < AIMR_OK )
  {
    this->OnMoveBlocked(this: &this->CAI_DefMovementSink, a2: &v13);
    return v13;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063240
// Name: public: float CAI_Navigator::MovementCost(int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CAI_Navigator::MovementCost@<st0>(
        CAI_Navigator *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int moveType,
        Vector *vecStart,
        Vector *vecEnd)
{
  __int128 v7; // xmm0
  float v8; // xmm0_4
  float v10[3]; // [esp-4h] [ebp-10h] BYREF
  float retaddr; // [esp+Ch] [ebp+0h]

  v10[1] = a2;
  v10[2] = retaddr;
  v7 = 0;
  v8 = fsqrt(
         (float)((float)((float)(vecStart->y - vecEnd->y) * (float)(vecStart->y - vecEnd->y))
               + (float)((float)(vecStart->x - vecEnd->x) * (float)(vecStart->x - vecEnd->x)))
       + (float)((float)(vecStart->z - vecEnd->z) * (float)(vecStart->z - vecEnd->z)));
  v10[0] = v8;
  if ( moveType == 2 || moveType == 8 )
    v10[0] = v8 * 2.0;
  ((void (__thiscall *)(CAI_BaseNPC *, int, Vector *, Vector *, float *, int, int))this->m_pOuter->MovementCost)(
    a1: this->m_pOuter,
    a2: moveType,
    a3: vecStart,
    a4: vecEnd,
    a5: v10,
    a6: a3,
    a7: a4);
  return v10[0];
}

//------------------------------------------------------------------------------
// Address: 0x100632F0
// Name: private: void CAI_Navigator::SaveStoppingPath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SaveStoppingPath(CAI_Navigator *this)
{
  CAI_WaypointList *m_pClippedWaypoints; // ecx
  AI_Waypoint_t *m_pFirstWaypoint; // eax
  Navigation_t m_iWPType; // eax

  m_pClippedWaypoints = this->m_pClippedWaypoints;
  this->m_flTimeClipped = -1.0;
  CAI_WaypointList::RemoveAll(this: m_pClippedWaypoints);
  m_pFirstWaypoint = this->m_pPath->m_Waypoints.m_pFirstWaypoint;
  if ( m_pFirstWaypoint != nullptr )
  {
    m_iWPType = m_pFirstWaypoint->m_iWPType;
    if ( (m_iWPType == NAV_CLIMB
       || m_iWPType == NAV_JUMP
       || ai_use_clipped_paths.m_pParent != nullptr && ai_use_clipped_paths.m_pParent->m_Value.m_nValue != 0)
      && this->GetStoppingPath(this, a2: this->m_pClippedWaypoints) )
    {
      this->m_flTimeClipped = gpGlobals->curtime;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063350
// Name: public: bool CAI_Navigator::SetGoalFromStoppingPath(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::SetGoalFromStoppingPath(CAI_Navigator *this)
{
  CAI_WaypointList *m_pClippedWaypoints; // eax
  CAI_WaypointList *v3; // ecx
  Activity m_activity; // edi
  CAI_BaseNPC *m_pOuter; // ebx
  const char *DebugName; // eax
  Navigation_t m_iWPType; // eax
  const Task_t *Task; // eax
  CAI_Path *m_pPath; // edi
  const char *v11; // [esp-10h] [ebp-14h]
  const char *v12; // [esp-Ch] [ebp-10h]

  m_pClippedWaypoints = this->m_pClippedWaypoints;
  if ( m_pClippedWaypoints != nullptr && m_pClippedWaypoints->m_pFirstWaypoint == nullptr )
    CAI_Navigator::SaveStoppingPath(this);
  v3 = this->m_pClippedWaypoints;
  if ( v3 == nullptr || v3->m_pFirstWaypoint == nullptr )
    return 0;
  if ( this->m_PreviousMoveActivity > ACT_RESET || this->m_pPath->m_activity > ACT_RESET )
  {
    m_iWPType = v3->m_pFirstWaypoint->m_iWPType;
    if ( (m_iWPType == NAV_CLIMB || m_iWPType == NAV_JUMP)
      && (Task = CAI_BaseNPC::GetTask(this: this->m_pOuter)) != nullptr
      && Task->iTask == 125 )
    {
      CAI_WaypointList::RemoveAll(this: this->m_pClippedWaypoints);
      return 0;
    }
    else
    {
      m_pPath = this->m_pPath;
      if ( m_pPath->m_Waypoints.m_pFirstWaypoint != nullptr )
      {
        CAI_WaypointList::RemoveAll(this: &this->m_pPath->m_Waypoints);
        m_pPath->m_iLastNodeReached = -1;
      }
      CAI_Path::SetWaypoints(
        this: this->m_pPath,
        route: this->m_pClippedWaypoints->m_pFirstWaypoint,
        fSetGoalFromLast: true);
      CAI_WaypointList::Set(this: (CChoreoChannel *)this->m_pClippedWaypoints, actor: nullptr);
      CAI_Path::SetGoalType(this: this->m_pPath, goalType: GOALTYPE_NONE);
      CAI_Path::SetGoalType(this: this->m_pPath, goalType: GOALTYPE_LOCATION);
      this->m_pPath->m_goalTolerance = 6.0;
      if ( this->m_PreviousMoveActivity != ACT_RESET )
        CAI_Path::SetMovementActivity(this: this->m_pPath, activity: this->m_PreviousMoveActivity);
      if ( this->m_PreviousArrivalActivity != ACT_RESET )
        CAI_Path::SetArrivalActivity(this: this->m_pPath, activity: this->m_PreviousArrivalActivity);
      return 1;
    }
  }
  else
  {
    CAI_WaypointList::RemoveAll(this: v3);
    m_activity = this->m_pPath->m_activity;
    m_pOuter = this->m_pOuter;
    v12 = ActivityList_NameForIndex(activityIndex: this->m_PreviousMoveActivity);
    v11 = ActivityList_NameForIndex(activityIndex: m_activity);
    DebugName = CBaseEntity::GetDebugName(this: m_pOuter);
    _DevWarning(
      a1: 2,
      a2: "%s has a stopping path and no valid. Movement activity: %s (prev %s)\n",
      DebugName,
      v11,
      v12);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063480
// Name: struct AI_Waypoint_t __near * CopyConstruct<struct AI_Waypoint_t>(struct AI_Waypoint_t __near *,struct AI_Waypoint_t const __near &)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__cdecl CopyConstruct<AI_Waypoint_t>(AI_Waypoint_t *pMemory, const AI_Waypoint_t *src)
{
  AI_Waypoint_t *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->hPathCorner.m_Index = -1;
  pMemory->m_hData.m_Index = -1;
  *pMemory = *src;
  pMemory->flPathDistGoal = -1.0;
  pMemory->pPrev = nullptr;
  pMemory->pNext = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063590
// Name: public: CAI_Navigator::CAI_Navigator(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Navigator *__thiscall CAI_Navigator::CAI_Navigator(CAI_Navigator *this, CAI_BaseNPC *pOuter)
{
  CAI_Path *v3; // eax
  CAI_Path *v4; // eax
  CAI_WaypointList *v5; // eax

  this->m_pOuter = pOuter;
  this->CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CAI_DefMovementSink::`vftable';
  this->CAI_Component::__vftable = (CAI_Navigator_vtbl *)&CAI_Navigator::`vftable'{for `CAI_Component'};
  this->CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CAI_Navigator::`vftable'{for `CAI_DefMovementSink'};
  this->m_hPeerWaitingOn.m_Index = -1;
  this->m_PeerWaitMoveTimer = (CSimTimer)3212836864LL;
  this->m_PeerWaitClearTimer = (CSimTimer)3212836864LL;
  this->m_NextSidestepTimer = (CSimTimer)3212836864LL;
  this->m_hBigStepGroundEnt.m_Index = -1;
  this->m_hLastBlockingEnt.m_Index = -1;
  v3 = (CAI_Path *)operator new(nSize: 0x6Cu);
  if ( v3 != nullptr )
    v4 = CAI_Path::CAI_Path(this: v3);
  else
    v4 = nullptr;
  this->m_flNextSimplifyTime = 0.0;
  this->m_pPath = v4;
  this->m_pAINetwork = nullptr;
  this->m_bNotOnNetwork = false;
  this->m_flLastSuccessfulSimplifyTime = -1.0;
  v5 = (CAI_WaypointList *)operator new(nSize: 4u);
  if ( v5 != nullptr )
    v5->m_pFirstWaypoint = nullptr;
  else
    v5 = nullptr;
  this->m_pClippedWaypoints = v5;
  this->m_navType = NAV_GROUND;
  *(_WORD *)&this->m_fNavComplete = 0;
  this->m_flTimeClipped = -1.0;
  *(_WORD *)&this->m_bValidateActivitySpeed = 1;
  this->m_PeerWaitMoveTimer.m_interval = 0.25;
  this->m_PeerWaitMoveTimer.m_next = -1.0;
  this->m_PeerWaitClearTimer.m_interval = 3.0;
  this->m_PeerWaitClearTimer.m_next = -1.0;
  this->m_NextSidestepTimer.m_interval = 5.0;
  this->m_NextSidestepTimer.m_next = -1.0;
  this->m_vPosBeginFailedSteer = vec3_invalid;
  this->m_pMotor = nullptr;
  this->m_pMoveProbe = nullptr;
  this->m_pLocalNavigator = nullptr;
  this->m_nNavFailCounter = 0;
  this->m_timeBeginFailedSteer = 3.4028235e38;
  this->m_flTimeLastAvoidanceTriangulate = -1.0;
  *(_WORD *)&this->m_fRememberStaleNodes = 1;
  this->m_flLastNavFailTime = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063760
// Name: public: bool CAI_Navigator::SetRandomGoal(class Vector const __near &,float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::SetRandomGoal(
        CAI_Navigator *this,
        const Vector *from,
        float minPathLength,
        const Vector *dir)
{
  CFmtStrN<256> *v5; // eax
  CAI_Network *m_pAINetwork; // ecx
  CAI_BaseNPC *m_pOuter; // eax
  CAI_NavInHintGroupFilter *p_filter; // edx
  int v10; // eax
  AI_Waypoint_t *ShortRandomPath; // edi
  CAI_Path *m_pPath; // edi
  CFmtStrN<256> v13; // [esp+10h] [ebp-114h] BYREF
  CAI_NavInHintGroupFilter filter; // [esp+11Ch] [ebp-8h] BYREF

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "[Nav] %s", "Set random goal\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v5->m_szBuf);
  }
  this->OnNewGoal(this);
  m_pAINetwork = this->m_pAINetwork;
  if ( m_pAINetwork->m_iNumNodes <= 0 )
    return 0;
  m_pOuter = this->m_pOuter;
  p_filter = nullptr;
  filter.__vftable = (CAI_NavInHintGroupFilter_vtbl *)&CAI_NavInHintGroupFilter::`vftable';
  filter.m_iszGroup.pszValue = nullptr;
  if ( m_pOuter->m_strHintGroup.pszValue != nullptr )
  {
    filter.m_iszGroup.pszValue = m_pOuter->m_strHintGroup.pszValue;
    p_filter = &filter;
  }
  v10 = CAI_Network::NearestNodeToPoint(
          this: m_pAINetwork,
          pNPC: m_pOuter,
          vecOrigin: from,
          bCheckVisibility: true,
          pFilter: p_filter);
  if ( v10 == -1 )
    return 0;
  ShortRandomPath = CAI_Pathfinder::FindShortRandomPath(
                      this: this->m_pOuter->m_pPathfinder,
                      startID: v10,
                      minPathLength,
                      directionIn: dir);
  if ( ShortRandomPath == nullptr )
    return 0;
  CAI_Path::SetGoalType(this: this->m_pPath, goalType: GOALTYPE_LOCATION);
  CAI_Path::SetWaypoints(this: this->m_pPath, route: ShortRandomPath, fSetGoalFromLast: false);
  CAI_Path::SetLastNodeAsGoal(this: this->m_pPath, bReset: false);
  m_pPath = this->m_pPath;
  m_pPath->m_goalTolerance = this->m_pOuter->GetDefaultNavGoalTolerance(this: this->m_pOuter);
  ((void (__thiscall *)(CAI_Navigator *, int, int))this->SimplifyPath)(a1: this, a2: 1, a3: -1082130432);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10063880
// Name: public: bool CAI_Navigator::FindVectorGoal(class Vector __near *,class Vector const __near &,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::FindVectorGoal(
        CAI_Navigator *this,
        Vector *pResult,
        const Vector *dir,
        float targetDist,
        float minDist,
        bool fShouldDeflect)
{
  CAI_BaseNPC *m_pOuter; // eax
  CAI_BaseNPC *v8; // ecx
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  bool v13; // zf
  float z; // xmm5_4
  float x; // xmm6_4
  float y; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  CAI_BaseNPC *v22; // edx
  AIMoveTrace_t moveTrace; // [esp+14h] [ebp-5Ch] BYREF
  Vector temp; // [esp+4Ch] [ebp-24h] BYREF
  Vector vecDeflect; // [esp+58h] [ebp-18h] BYREF
  Vector testLoc; // [esp+64h] [ebp-Ch] BYREF
  int savedregs; // [esp+70h] [ebp+0h] BYREF
  float distAchieved; // [esp+7Ch] [ebp+Ch]

  memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  v8 = this->m_pOuter;
  v10 = dir->y * targetDist;
  v11 = dir->z * targetDist;
  testLoc.x = v8->m_vecOrigin.m_Value.x + (float)(dir->x * targetDist);
  testLoc.y = v8->m_vecOrigin.m_Value.y + v10;
  testLoc.z = v8->m_vecOrigin.m_Value.z + v11;
  CAI_MoveProbe::MoveLimit(
    this: this->m_pMoveProbe,
    a2: (int)&savedregs,
    navType: this->m_navType,
    vecStart: &v8->m_vecOrigin.m_Value,
    vecEnd: &testLoc,
    collisionMask: v8->m_nAITraceMask,
    pTarget: nullptr,
    pctToCheckStandPositions: 100.0,
    flags: 0,
    pTrace: &moveTrace);
  if ( moveTrace.fStatus != AIMR_OK )
  {
    v12 = targetDist - moveTrace.flDistObstructed;
    distAchieved = targetDist - moveTrace.flDistObstructed;
    if ( fShouldDeflect
      && (vec3_origin.x != moveTrace.vHitNormal.x
       || vec3_origin.y != moveTrace.vHitNormal.y
       || vec3_origin.z != moveTrace.vHitNormal.z) )
    {
      v13 = this->m_navType == NAV_GROUND;
      vecDeflect = moveTrace.vHitNormal;
      if ( v13 )
        z = 0.0;
      else
        z = vecDeflect.z;
      x = vecDeflect.x;
      y = dir->y;
      v17 = y * vecDeflect.x;
      v18 = (float)(y * z) - (float)(dir->z * vecDeflect.y);
      v19 = (float)(dir->z * vecDeflect.x) - (float)(dir->x * z);
      v20 = (float)(dir->x * vecDeflect.y) - v17;
      vecDeflect.x = (float)(v20 * vecDeflect.y) - (float)(v19 * z);
      v21 = (float)(v19 * x) - (float)(vecDeflect.y * v18);
      vecDeflect.y = (float)(v18 * z) - (float)(v20 * x);
      vecDeflect.z = v21;
      VectorNormalize(vec: &vecDeflect);
      v22 = this->m_pOuter;
      temp = moveTrace.vEndPosition;
      testLoc.x = moveTrace.vEndPosition.x + (float)((float)(targetDist - distAchieved) * vecDeflect.x);
      testLoc.y = moveTrace.vEndPosition.y + (float)((float)(targetDist - distAchieved) * vecDeflect.y);
      testLoc.z = moveTrace.vEndPosition.z + (float)((float)(targetDist - distAchieved) * vecDeflect.z);
      CAI_MoveProbe::MoveLimit(
        this: this->m_pMoveProbe,
        a2: (int)&savedregs,
        navType: this->m_navType,
        vecStart: &temp,
        vecEnd: &testLoc,
        collisionMask: v22->m_nAITraceMask,
        pTarget: nullptr,
        pctToCheckStandPositions: 100.0,
        flags: 0,
        pTrace: &moveTrace);
      v12 = (float)((float)(targetDist - distAchieved) - moveTrace.flDistObstructed) + distAchieved;
    }
    if ( minDist + 0.01 > v12 )
      return 0;
  }
  *pResult = moveTrace.vEndPosition;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10063B30
// Name: public: bool CAI_Navigator::SetRandomGoal(float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::SetRandomGoal(CAI_Navigator *this, float minPathLength, const Vector *dir)
{
  return CAI_Navigator::SetRandomGoal(this, from: &this->m_pOuter->m_vecOrigin.m_Value, minPathLength, dir);
}

//------------------------------------------------------------------------------
// Address: 0x10063B60
// Name: public: bool CAI_Navigator::PrependLocalAvoidance(float,struct AIMoveTrace_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::PrependLocalAvoidance(
        CAI_Navigator *this,
        float distObstacle,
        const AIMoveTrace_t *directTrace)
{
  CAI_BaseNPC *m_pOuter; // eax
  float curtime; // xmm0_4
  AI_Waypoint_t *v7; // ebx
  CAI_BaseNPC *v8; // edi
  const Vector *v9; // eax
  CAI_BaseNPC *v10; // edi
  CAI_MoveProbe *m_pMoveProbe; // ecx
  Navigation_t m_navType; // eax
  float z; // xmm0_4
  const CBaseEntity *NavTargetEntity; // eax
  AI_Waypoint_t *v15; // eax
  CAI_Pathfinder *m_pPathfinder; // edi
  const Vector *v17; // eax
  unsigned int v18; // edx
  CBaseEntity *v19; // eax
  AI_Waypoint_t *v20; // eax
  AI_Waypoint_t *pNext; // eax
  AI_Waypoint_t *pPrev; // eax
  CAI_BaseNPC *v23; // eax
  CAI_BaseNPC *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  unsigned int m_nAITraceMask; // ecx
  Navigation_t v28; // edi
  CAI_MoveProbe *v29; // edx
  const CBaseEntity *v30; // eax
  CFmtStrN<256> *v31; // eax
  char v32; // [esp+24h] [ebp-198h]
  CAI_MoveProbe *v33; // [esp+28h] [ebp-194h]
  CFmtStrN<256> v34; // [esp+38h] [ebp-184h] BYREF
  AIMoveTrace_t backawayTrace; // [esp+144h] [ebp-78h] BYREF
  Vector dir; // [esp+17Ch] [ebp-40h] BYREF
  Vector testPos; // [esp+188h] [ebp-34h] BYREF
  Vector vStart; // [esp+194h] [ebp-28h] BYREF
  CAI_MoveProbe *v39[2]; // [esp+1A0h] [ebp-1Ch]
  Vector vTestBackaway; // [esp+1A8h] [ebp-14h] BYREF
  unsigned int collisionMask; // [esp+1B4h] [ebp-8h]
  Navigation_t navType; // [esp+1B8h] [ebp-4h]
  int savedregs; // [esp+1BCh] [ebp+0h] BYREF
  float moveThisInterval; // [esp+1C4h] [ebp+8h]
  unsigned int moveThisIntervala; // [esp+1C4h] [ebp+8h]

  if ( AIStrongOpt() )
    return 0;
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_spawnflags.m_Value & 0x10) != 0 )
    return 0;
  curtime = gpGlobals->curtime;
  if ( this->m_flTimeLastAvoidanceTriangulate >= curtime )
    return 0;
  this->m_flTimeLastAvoidanceTriangulate = curtime;
  *(double *)v39 = distObstacle;
  vStart = (Vector)m_pOuter->m_vecOrigin;
  v7 = nullptr;
  if ( NAI_Hull::Width(id: m_pOuter->m_eHull) * 0.5 > distObstacle )
  {
    memset(dst: (int)&backawayTrace, value: nullptr, count: sizeof(backawayTrace));
    v8 = this->m_pOuter;
    v9 = CAI_Path::CurWaypointPos(this: this->m_pPath);
    vTestBackaway.x = v9->x - v8->m_vecOrigin.m_Value.x;
    vTestBackaway.y = v9->y - v8->m_vecOrigin.m_Value.y;
    vTestBackaway.z = v9->z - v8->m_vecOrigin.m_Value.z;
    VectorNormalize(vec: &vTestBackaway);
    *(float *)&collisionMask = -NAI_Hull::Width(id: this->m_pOuter->m_eHull);
    v10 = this->m_pOuter;
    m_pMoveProbe = this->m_pMoveProbe;
    m_navType = this->m_navType;
    vTestBackaway.x = vTestBackaway.x * *(float *)&collisionMask;
    vTestBackaway.y = vTestBackaway.y * *(float *)&collisionMask;
    vTestBackaway.z = vTestBackaway.z * *(float *)&collisionMask;
    vTestBackaway.x = v10->m_vecOrigin.m_Value.x + vTestBackaway.x;
    vTestBackaway.y = v10->m_vecOrigin.m_Value.y + vTestBackaway.y;
    z = v10->m_vecOrigin.m_Value.z;
    v39[1] = m_pMoveProbe;
    vTestBackaway.z = z + vTestBackaway.z;
    collisionMask = v10->m_nAITraceMask;
    v32 = m_navType == NAV_GROUND;
    navType = m_navType;
    NavTargetEntity = CAI_Navigator::GetNavTargetEntity(this);
    if ( CAI_MoveProbe::MoveLimit(
           this: v39[1],
           a2: (int)&savedregs,
           navType,
           vecStart: &v10->m_vecOrigin.m_Value,
           vecEnd: &vTestBackaway,
           collisionMask,
           pTarget: NavTargetEntity,
           pctToCheckStandPositions: 100.0,
           flags: v32,
           pTrace: &backawayTrace) )
    {
      vStart = backawayTrace.vEndPosition;
      v15 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
      if ( v15 != nullptr )
        v7 = AI_Waypoint_t::AI_Waypoint_t(
               this: v15,
               initPosition: &vStart,
               initYaw: 0.0,
               initNavType: this->m_navType,
               initWaypointFlags: 1,
               initNodeID: -1);
      else
        v7 = nullptr;
    }
  }
  m_pPathfinder = this->m_pOuter->m_pPathfinder;
  v39[1] = (CAI_MoveProbe *)this->m_navType;
  v17 = CAI_Path::CurWaypointPos(this: this->m_pPath);
  v18 = (unsigned int)m_pPathfinder->__vftable;
  navType = (Navigation_t)v17;
  v33 = v39[1];
  collisionMask = v18;
  v19 = CAI_Navigator::GetNavTargetEntity(this);
  v20 = (AI_Waypoint_t *)(*(int (__thiscall **)(CAI_Pathfinder *, Vector *, Navigation_t, CBaseEntity *, int, int, _DWORD, _DWORD, CAI_MoveProbe *))(collisionMask + 32))(
                           a1: m_pPathfinder,
                           a2: &vStart,
                           a3: navType,
                           a4: v19,
                           a5: 1,
                           a6: -1,
                           a7: 0,
                           a8: LODWORD(distObstacle),
                           a9: v33);
  if ( v20 != nullptr )
  {
    if ( v7 != nullptr )
      AI_Waypoint_t::SetNext(this: v7, p: v20);
    else
      v7 = v20;
    moveThisInterval = CAI_Motor::CalcIntervalMove(this: this->m_pMotor, a2: (int)this);
    v23 = this->m_pOuter;
    dir.x = v7->vecLocation.x - v23->m_vecOrigin.m_Value.x;
    dir.y = v7->vecLocation.y - v23->m_vecOrigin.m_Value.y;
    dir.z = v7->vecLocation.z - v23->m_vecOrigin.m_Value.z;
    if ( VectorNormalize(vec: &dir) <= (double)moveThisInterval )
    {
      testPos = v7->vecLocation;
    }
    else
    {
      v24 = this->m_pOuter;
      v25 = v24->m_vecOrigin.m_Value.y + (float)(dir.y * moveThisInterval);
      v26 = v24->m_vecOrigin.m_Value.z + (float)(dir.z * moveThisInterval);
      testPos.x = v24->m_vecOrigin.m_Value.x + (float)(dir.x * moveThisInterval);
      testPos.y = v25;
      testPos.z = v26;
    }
    m_nAITraceMask = this->m_pOuter->m_nAITraceMask;
    v28 = this->m_navType;
    v29 = this->m_pMoveProbe;
    v39[1] = (CAI_MoveProbe *)this->m_pOuter;
    moveThisIntervala = m_nAITraceMask;
    navType = (Navigation_t)v29;
    v30 = CAI_Navigator::GetNavTargetEntity(this);
    if ( CAI_MoveProbe::MoveLimit(
           this: (CAI_MoveProbe *)navType,
           a2: (int)&savedregs,
           navType: v28,
           vecStart: (const Vector *)&v39[1][35],
           vecEnd: &testPos,
           collisionMask: moveThisIntervala,
           pTarget: v30,
           pctToCheckStandPositions: 100.0,
           flags: v28 == NAV_GROUND,
           pTrace: nullptr) )
    {
      if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
      {
        v31 = CFmtStrN<256>::CFmtStrN<256>(this: &v34, pszFormat: "[Nav] %s", "Adding triangulation\n");
        DevMsg(pAI: this->m_pOuter, pszFormat: v31->m_szBuf);
      }
      CAI_Path::PrependWaypoints(this: this->m_pPath, pWaypoints: v7);
      return 1;
    }
    else
    {
      DeleteAll(pWaypointList: v7);
      return 0;
    }
  }
  else
  {
    if ( v7 != nullptr )
    {
      pNext = v7->pNext;
      if ( pNext != nullptr )
        pNext->pPrev = v7->pPrev;
      pPrev = v7->pPrev;
      if ( pPrev != nullptr )
        pPrev->pNext = v7->pNext;
      CUtlMemoryPool::Free(this: &AI_Waypoint_t::s_Allocator, memBlock: v7);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063F90
// Name: public: bool CAI_Navigator::GetPointAlongPath(class Vector __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::GetPointAlongPath(
        CAI_Navigator *this,
        Vector *pResult,
        float distance,
        bool fReducibleOnly)
{
  AI_Waypoint_t *m_pFirstWaypoint; // eax
  CAI_BaseNPC *m_pOuter; // edx
  AI_Waypoint_t *pNext; // esi
  float v8; // xmm7_4
  float y; // xmm5_4
  float x; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // [esp-1Ch] [ebp-2Ch]
  float vPosPrev; // [esp+0h] [ebp-10h]
  CNetworkVectorXY_SeparateZBase<Vector,CBaseEntity::NetworkVar_m_vecOrigin> m_vecOrigin; // 0:^24.12

  m_pFirstWaypoint = this->m_pPath->m_Waypoints.m_pFirstWaypoint;
  if ( m_pFirstWaypoint == nullptr )
    return 0;
  m_pOuter = this->m_pOuter;
  pNext = m_pFirstWaypoint->pNext;
  v8 = distance;
  m_vecOrigin = m_pOuter->m_vecOrigin;
  y = m_pOuter->m_vecOrigin.m_Value.y;
  x = m_pOuter->m_vecOrigin.m_Value.x;
  vPosPrev = distance;
  if ( pNext != nullptr )
  {
    do
    {
      v11 = (float)(m_pFirstWaypoint->vecLocation.y - y) * (float)(m_pFirstWaypoint->vecLocation.y - y);
      if ( this->m_navType != NAV_GROUND )
      {
        v8 = vPosPrev;
        v11 = v11
            + (float)((float)(m_pFirstWaypoint->vecLocation.z - m_vecOrigin.m_Value.z)
                    * (float)(m_pFirstWaypoint->vecLocation.z - m_vecOrigin.m_Value.z));
      }
      v12 = fsqrt(v11 + (float)((float)(m_pFirstWaypoint->vecLocation.x - x)
                              * (float)(m_pFirstWaypoint->vecLocation.x - x)));
      if ( v12 > v8 )
        break;
      v8 = v8 - v12;
      vPosPrev = v8;
      x = m_pFirstWaypoint->vecLocation.x;
      y = m_pFirstWaypoint->vecLocation.y;
      m_vecOrigin.m_Value.z = m_pFirstWaypoint->vecLocation.z;
      if ( fReducibleOnly
        && (m_pFirstWaypoint->m_iWPType != pNext->m_iWPType || (m_pFirstWaypoint->m_fWaypointFlags & 0x2A) != 0) )
      {
        break;
      }
      m_pFirstWaypoint = pNext;
      pNext = pNext->pNext;
    }
    while ( pNext != nullptr );
    *(_QWORD *)&m_vecOrigin.m_Value.x = __PAIR64__(LODWORD(y), LODWORD(x));
  }
  v13 = m_pFirstWaypoint->vecLocation.y - y;
  v14 = m_pFirstWaypoint->vecLocation.x - x;
  if ( this->m_navType != NAV_GROUND )
    v17 = fsqrt(
            (float)((float)(v13 * v13)
                  + (float)((float)(m_pFirstWaypoint->vecLocation.z - m_vecOrigin.m_Value.z)
                          * (float)(m_pFirstWaypoint->vecLocation.z - m_vecOrigin.m_Value.z)))
          + (float)(v14 * v14));
  else
    v17 = fsqrt((float)(v13 * v13) + (float)(v14 * v14));
  if ( (float)(v17 - v8) >= 0.1 )
  {
    v15 = m_pFirstWaypoint->vecLocation.z - m_vecOrigin.m_Value.z;
    pResult->x = v14;
    pResult->y = v13;
    pResult->z = v15;
    VectorNormalize(vec: pResult);
    pResult->x = (float)(pResult->x * vPosPrev) + m_vecOrigin.m_Value.x;
    v16 = (float)(vPosPrev * pResult->z) + m_vecOrigin.m_Value.z;
    pResult->y = (float)(vPosPrev * pResult->y) + m_vecOrigin.m_Value.y;
    pResult->z = v16;
  }
  else
  {
    *pResult = m_pFirstWaypoint->vecLocation;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100641B0
// Name: public: virtual void CAI_Navigator::OnScheduleChange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::OnScheduleChange(CAI_Navigator *this)
{
  CFmtStrN<256> *v2; // eax
  CFmtStrN<256> v3; // [esp+4h] [ebp-10Ch] BYREF

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v3, pszFormat: "[Nav] %s", "Schedule change\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v2->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064200
// Name: protected: virtual void CAI_Navigator::OnNewGoal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::OnNewGoal(CAI_Navigator *this)
{
  CFmtStrN<256> *v2; // eax
  CFmtStrN<256> v3; // [esp+4h] [ebp-10Ch] BYREF

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v3, pszFormat: "[Nav] %s", "New Goal\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v2->m_szBuf);
  }
  CAI_Navigator::ResetCalculations(this);
  this->m_fNavComplete = true;
}

//------------------------------------------------------------------------------
// Address: 0x10064260
// Name: protected: virtual void CAI_Navigator::OnNavComplete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::OnNavComplete(CAI_Navigator *this)
{
  CFmtStrN<256> *v2; // eax
  CFmtStrN<256> v3; // [esp+4h] [ebp-10Ch] BYREF

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v3, pszFormat: "[Nav] %s", "Nav complete\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v2->m_szBuf);
  }
  CAI_Navigator::ResetCalculations(this);
  CAI_BaseNPC::TaskMovementComplete(this: this->m_pOuter);
  this->m_fNavComplete = true;
}

//------------------------------------------------------------------------------
// Address: 0x100642C0
// Name: protected: void CAI_Navigator::OnNavFailed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::OnNavFailed(CAI_Navigator *this, bool bMovement)
{
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+4h] [ebp-10Ch] BYREF

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "[Nav] %s", "Nav failed\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v3->m_szBuf);
  }
  if ( bMovement )
    this->m_pOuter->OnMovementFailed(this: this->m_pOuter);
  CAI_Navigator::ResetCalculations(this);
  *(_WORD *)&this->m_fNavComplete = 257;
}

//------------------------------------------------------------------------------
// Address: 0x10064330
// Name: protected: virtual void CAI_Navigator::MoveCalcBaseGoal(struct AILocalMoveGoal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::MoveCalcBaseGoal(CAI_Navigator *this, AILocalMoveGoal_t *pMoveGoal)
{
  CAI_Motor *m_pMotor; // ebx
  int MovementSequence; // eax
  double SequenceGroundSpeed; // st7
  unsigned int m_Index; // eax
  CBaseEntity *NavTargetEntity; // eax
  float maxDist; // xmm0_4
  float curExpectedDist; // xmm1_4
  CAI_Path *m_pPath; // edx
  AI_Waypoint_t *pNext; // ecx
  const Task_t *Task; // eax

  pMoveGoal->navType = this->m_navType;
  pMoveGoal->target = *CAI_Path::CurWaypointPos(this: this->m_pPath);
  pMoveGoal->maxDist = ComputePathDirection(
                         navType: this->m_navType,
                         start: &this->m_pOuter->m_vecOrigin.m_Value,
                         end: &pMoveGoal->target,
                         pDirection: &pMoveGoal->dir);
  pMoveGoal->facing = pMoveGoal->dir;
  m_pMotor = this->m_pMotor;
  MovementSequence = CAI_Navigator::GetMovementSequence(this);
  SequenceGroundSpeed = CAI_Motor::GetSequenceGroundSpeed(this: m_pMotor, iSequence: MovementSequence);
  pMoveGoal->speed = SequenceGroundSpeed;
  pMoveGoal->curExpectedDist = SequenceGroundSpeed * this->m_pMotor->m_flMoveInterval;
  if ( CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath) == 2
    || CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath) == 1 )
  {
    NavTargetEntity = CAI_BaseNPC::GetNavTargetEntity(this: this->m_pOuter);
  }
  else
  {
    m_Index = this->m_pPath->m_target.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      NavTargetEntity = nullptr;
    else
      NavTargetEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  maxDist = pMoveGoal->maxDist;
  curExpectedDist = pMoveGoal->curExpectedDist;
  pMoveGoal->pMoveTarget = NavTargetEntity;
  if ( curExpectedDist > maxDist )
    pMoveGoal->curExpectedDist = maxDist;
  if ( CAI_Path::CurWaypointIsGoal(this: this->m_pPath) )
  {
    pMoveGoal->flags |= 1u;
  }
  else
  {
    m_pPath = this->m_pPath;
    pNext = m_pPath->m_Waypoints.m_pFirstWaypoint->pNext;
    if ( pNext != nullptr && pNext->m_iWPType != m_pPath->m_Waypoints.m_pFirstWaypoint->m_iWPType )
      pMoveGoal->flags |= 4u;
  }
  Task = CAI_BaseNPC::GetTask(this: this->m_pOuter);
  if ( Task != nullptr )
  {
    if ( Task->iTask == 125 )
      pMoveGoal->flags |= 0x18u;
    pMoveGoal->pPath = this->m_pPath;
  }
  else
  {
    pMoveGoal->pPath = this->m_pPath;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064480
// Name: private: virtual bool CAI_Navigator::OnInsufficientStopDist(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CAI_Navigator::OnInsufficientStopDist@<al>(
        CAI_Navigator *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        AILocalMoveGoal_t *pMoveGoal,
        __int64 distClear)
{
  CBaseEntity *v7; // ecx
  unsigned int v8; // edx
  const Vector *v9; // eax
  float v10; // xmm1_4
  __int128 v11; // xmm0
  CAI_BaseNPC *m_pOuter; // xmm1_4
  float x; // ecx
  float v15; // xmm0_4
  float v16; // ecx
  float v17; // xmm2_4
  float v18; // xmm0_4
  int v19; // eax
  _DWORD v21[3]; // [esp+20h] [ebp-84h] BYREF
  _BYTE moveTrace[60]; // [esp+2Ch] [ebp-78h] OVERLAPPED BYREF
  Vector vNewWaypoint; // [esp+68h] [ebp-3Ch] BYREF
  float v24; // [esp+74h] [ebp-30h]
  float v25; // [esp+78h] [ebp-2Ch]
  Vector testLoc; // [esp+7Ch] [ebp-28h] BYREF
  Vector vDeflection; // [esp+88h] [ebp-1Ch]
  int v28; // [esp+94h] [ebp-10h]
  _DWORD v29[2]; // [esp+98h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+A4h] [ebp+0h]

  v29[0] = a2;
  v29[1] = retaddr;
  if ( (*(unsigned __int8 (__stdcall **)(AILocalMoveGoal_t *, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, float, float, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(*((_DWORD *)this - 1) + 2284) + 20))(
         a1: pMoveGoal,
         a2: distClear,
         a3: HIDWORD(distClear),
         a4: a3,
         a5: a4,
         a6: v21[0],
         a7: v21[1],
         a8: v21[2],
         a9: *(_DWORD *)moveTrace,
         a10: *(_DWORD *)&moveTrace[4],
         a11: *(_DWORD *)&moveTrace[8],
         a12: *(_DWORD *)&moveTrace[12],
         a13: *(_DWORD *)&moveTrace[16],
         a14: *(_DWORD *)&moveTrace[20],
         a15: *(_DWORD *)&moveTrace[24],
         a16: *(_DWORD *)&moveTrace[28],
         a17: *(_DWORD *)&moveTrace[32],
         a18: *(_DWORD *)&moveTrace[36],
         a19: *(_DWORD *)&moveTrace[40],
         a20: *(_DWORD *)&moveTrace[44],
         a21: *(_DWORD *)&moveTrace[48],
         a22: *(_DWORD *)&moveTrace[52],
         a23: *(_DWORD *)&moveTrace[56],
         a24: LODWORD(vNewWaypoint.x),
         a25: LODWORD(vNewWaypoint.y),
         a26: LODWORD(vNewWaypoint.z),
         a27: COERCE_FLOAT(LODWORD(v24)),
         a28: COERCE_FLOAT(LODWORD(v25)),
         a29: LODWORD(testLoc.x),
         a30: LODWORD(testLoc.y),
         a31: LODWORD(testLoc.z),
         a32: LODWORD(vDeflection.x),
         a33: LODWORD(vDeflection.y),
         a34: LODWORD(vDeflection.z)) != 0 )
    return 1;
  LODWORD(vDeflection.x) = (char *)this - 8;
  if ( CAI_Navigator::IsMovingOutOfWay(
         this: (CAI_Navigator *)((char *)this - 8),
         moveGoal: pMoveGoal,
         distClear: *(float *)&distClear) )
  {
    *(_DWORD *)HIDWORD(distClear) = 0;
    pMoveGoal->flags |= 2u;
    LODWORD(pMoveGoal->maxDist) = distClear;
    return 1;
  }
  LODWORD(vDeflection.z) = this->m_pLocalNavigator;
  v7 = *((CBaseEntity **)this - 1);
  v8 = (unsigned int)v7->m_iEFlags >> 11;
  v28 = (int)v7;
  if ( (v8 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)v29);
  LODWORD(vDeflection.y) = this->m_pOuter;
  v9 = CAI_Path::ActualGoalPosition(this: (CAI_Path *)LODWORD(vDeflection.z));
  v10 = (float)(v9->y - *(float *)(v28 + 464)) * (float)(v9->y - *(float *)(v28 + 464));
  if ( LODWORD(vDeflection.y) != 0 )
    v10 = v10 + (float)((float)(v9->z - *(float *)(v28 + 468)) * (float)(v9->z - *(float *)(v28 + 468)));
  v11 = 0;
  *(float *)&v11 = v10 + (float)((float)(v9->x - *(float *)(v28 + 460)) * (float)(v9->x - *(float *)(v28 + 460)));
  m_pOuter = this->m_pLocalNavigator->m_pOuter;
  *(float *)&v11 = fsqrt(*(float *)&v11);
  *(_OWORD *)&moveTrace[44] = v11;
  if ( *(float *)&m_pOuter + 0.01 <= *(float *)&v11 )
  {
    if ( (float)(gpGlobals->curtime - this->m_PeerWaitClearTimer.m_next) <= -0.001 )
    {
LABEL_14:
      if ( *(float *)&distClear >= 1.0 )
      {
        return 0;
      }
      else
      {
        *(_DWORD *)HIDWORD(distClear) = pMoveGoal->directTrace.fStatus;
        pMoveGoal->maxDist = 0.0;
        return 1;
      }
    }
    else
    {
      v15 = this->m_PeerWaitClearTimer.m_interval + gpGlobals->curtime;
      LODWORD(vDeflection.z) = 56;
      vDeflection.y = 0.0;
      LODWORD(vDeflection.x) = v21;
      this->m_PeerWaitClearTimer.m_next = v15;
      memset(
        dst: SLODWORD(vDeflection.x),
        value: (unsigned __int8 *)LODWORD(vDeflection.y),
        count: LODWORD(vDeflection.z));
      CAI_Navigator::CalculateDeflection(
        start: (const Vector *)(*((_DWORD *)this - 1) + 700),
        dir: &pMoveGoal->dir,
        normal: &pMoveGoal->directTrace.vHitNormal,
        pResult: &testLoc);
      v28 = 1;
      while ( 1 )
      {
        vDeflection.x = NAI_Hull::Width(id: *(_DWORD *)(*((_DWORD *)this - 1) + 1672));
        v16 = *((float *)this - 1);
        v17 = (float)((float)(testLoc.z * vDeflection.x) * 2.0) * (float)v28;
        vNewWaypoint.z = *(float *)(LODWORD(v16) + 700)
                       + (float)((float)((float)(testLoc.x * vDeflection.x) * 2.0) * (float)v28);
        v24 = *(float *)(LODWORD(v16) + 704) + (float)((float)((float)(testLoc.y * vDeflection.x) * 2.0) * (float)v28);
        v18 = *(float *)(LODWORD(v16) + 708);
        vDeflection.x = v16;
        v25 = v18 + v17;
        CAI_MoveProbe::MoveLimit(
          this: *(CAI_MoveProbe **)&this->m_fNavComplete,
          a2: (int)v29,
          navType: (Navigation_t)this->m_pOuter,
          vecStart: (const Vector *)(LODWORD(v16) + 700),
          vecEnd: (Vector *)&vNewWaypoint.z,
          collisionMask: *(_DWORD *)(LODWORD(v16) + 3712),
          pTarget: nullptr,
          pctToCheckStandPositions: 100.0,
          flags: 0,
          pTrace: (AIMoveTrace_t *)v21);
        if ( v21[0] == 0 )
        {
          v19 = *((_DWORD *)this - 1);
          LODWORD(vDeflection.z) = v21;
          vDeflection.y = 0.0;
          vDeflection.x = *(float *)moveTrace;
          *(_DWORD *)&moveTrace[56] = *(_DWORD *)moveTrace;
          *(_QWORD *)&moveTrace[48] = *(_QWORD *)&v21[1];
          CAI_MoveProbe::MoveLimit(
            this: *(CAI_MoveProbe **)&this->m_fNavComplete,
            a2: (int)v29,
            navType: (Navigation_t)this->m_pOuter,
            vecStart: (const Vector *)&moveTrace[48],
            vecEnd: &pMoveGoal->target,
            collisionMask: *(_DWORD *)(v19 + 3712) & 0xFDFFFFFF,
            pTarget: nullptr,
            pctToCheckStandPositions: 100.0,
            flags: 0,
            pTrace: (AIMoveTrace_t *)v21);
          if ( v21[0] == 0 )
            break;
        }
        v28 -= 2;
        if ( v28 <= -2 )
          goto LABEL_14;
      }
      CAI_Path::PrependWaypoint(
        this: (CAI_Path *)this->m_pLocalNavigator,
        newPoint: (const Vector *)&moveTrace[48],
        navType: (Navigation_t)this->m_pOuter,
        waypointFlags: 1u);
      *(_DWORD *)HIDWORD(distClear) = 1;
      return 1;
    }
  }
  else
  {
    x = vDeflection.x;
    pMoveGoal->flags |= 2u;
    LODWORD(pMoveGoal->maxDist) = distClear;
    (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(x) + 52))(a1: COERCE_FLOAT(LODWORD(x)));
    *(_DWORD *)HIDWORD(distClear) = 0;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100647D0
// Name: private: bool CAI_Navigator::DelayNavigationFailure(struct AIMoveTrace_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Navigator::DelayNavigationFailure(CAI_Navigator *this, const AIMoveTrace_t *trace)
{
  CAI_BaseNPC *v3; // edi
  unsigned int v4; // eax
  IHandleEntity *v5; // ecx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CGlobalVars *v9; // eax
  CAI_BaseNPC *m_pOuter; // ebx
  int m_iEFlags; // ecx
  CGameTrace bumpTrace; // [esp+8h] [ebp-60h] BYREF
  Vector vecEnd; // [esp+5Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+68h] [ebp+0h] BYREF
  float tracea; // [esp+70h] [ebp+8h]
  const AIMoveTrace_t *traceb; // [esp+70h] [ebp+8h]

  if ( trace->pObstruction != nullptr )
    v3 = trace->pObstruction->MyNPCPointer(this: trace->pObstruction);
  else
    v3 = nullptr;
  if ( !this->m_fPeerMoveWait
    || ((v4 = this->m_hPeerWaitingOn.m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4)
      ? (v5 = nullptr)
      : (v5 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity),
        v3 != v5) )
  {
    if ( v3 != nullptr )
    {
      m_Index = this->m_hPeerWaitingOn.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity == v3 && (float)((tracea = gpGlobals->curtime) - this->m_PeerWaitClearTimer.m_next) <= -0.001 )
      {
        if ( CHandle<CBaseEntity>::operator==(this: &this->m_hPeerWaitingOn, val: v3)
          && (float)(tracea - this->m_PeerWaitMoveTimer.m_next) <= -0.001 )
        {
          this->m_fPeerMoveWait = true;
          return this->m_fPeerMoveWait;
        }
      }
      else
      {
        this->m_fPeerMoveWait = true;
        this->m_hPeerWaitingOn.m_Index = v3->GetRefEHandle(this: v3)->m_Index;
        v9 = gpGlobals;
        this->m_PeerWaitMoveTimer.m_next = this->m_PeerWaitMoveTimer.m_interval + gpGlobals->curtime;
        this->m_PeerWaitClearTimer.m_next = this->m_PeerWaitClearTimer.m_interval + v9->curtime;
        m_pOuter = this->m_pOuter;
        if ( CBaseEntity::GetGroundEntity(this: v3) == m_pOuter )
        {
          traceb = (const AIMoveTrace_t *)this->m_pOuter->m_nAITraceMask;
          if ( (v3->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
          m_iEFlags = v3->m_iEFlags;
          vecEnd.x = v3->m_vecAbsOrigin.x;
          vecEnd.y = v3->m_vecAbsOrigin.y;
          vecEnd.z = v3->m_vecAbsOrigin.z + 2.0;
          if ( (m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
          CAI_MoveProbe::TraceHull(
            this: v3->m_pMoveProbe,
            a2: (int)v3,
            vecStart: &v3->m_vecAbsOrigin,
            &vecEnd,
            mask: (unsigned int)traceb,
            pResult: &bumpTrace);
          if ( bumpTrace.fraction == 1.0 )
            UTIL_SetOrigin(entity: v3, vecOrigin: &bumpTrace.endpos, bFireTriggers: true);
        }
      }
    }
  }
  return this->m_fPeerMoveWait;
}

//------------------------------------------------------------------------------
// Address: 0x100649B0
// Name: private: virtual bool CAI_Navigator::OnMoveStalled(struct AILocalMoveGoal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::OnMoveStalled(CAI_Navigator *this, const AILocalMoveGoal_t *move)
{
  CFmtStrN<256> *v3; // eax
  Activity StoppedActivity; // eax
  CFmtStrN<256> v6; // [esp+4h] [ebp-10Ch] BYREF

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = CFmtStrN<256>::CFmtStrN<256>(
           this: &v6,
           pszFormat: "[Nav] %s",
           "CAI_Navigator::OnMoveStalled calling SetActivity(GetStoppedActivity)");
    DevMsg(pAI: *((CAI_BaseNPC **)this - 1), pszFormat: v3->m_szBuf);
  }
  StoppedActivity = CAI_BaseNPC::GetStoppedActivity(this: *((CAI_BaseNPC **)this - 1));
  (*(void (__thiscall **)(_DWORD, Activity))(**((_DWORD **)this - 1) + 1652))(
    a1: *((_DWORD *)this - 1),
    a2: StoppedActivity);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10064A10
// Name: private: virtual bool CAI_Navigator::OnMoveExecuteFailed(struct AILocalMoveGoal_t const __near &,struct AIMoveTrace_t const __near &,enum AIMotorMoveResult_t,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::OnMoveExecuteFailed(
        CAI_Navigator *this,
        const AILocalMoveGoal_t *move,
        const AIMoveTrace_t *trace,
        AIMotorMoveResult_t fMotorResult,
        AIMoveResult_t *pResult)
{
  float m_next; // eax

  if ( (*(unsigned __int8 (__thiscall **)(int, const AILocalMoveGoal_t *, const AIMoveTrace_t *, AIMotorMoveResult_t, AIMoveResult_t *))(*(_DWORD *)(*((_DWORD *)this - 1) + 2284) + 32))(
         a1: *((_DWORD *)this - 1) + 2284,
         a2: move,
         a3: trace,
         a4: fMotorResult,
         a5: pResult) == 0 )
  {
    m_next = this->m_NextSidestepTimer.m_next;
    if ( (m_next == NAN
       || g_pEntityList->m_EntPtrArray[LOWORD(m_next)].m_SerialNumber != HIWORD(LODWORD(m_next))
       || g_pEntityList->m_EntPtrArray[LOWORD(m_next)].m_pEntity == nullptr)
      && trace->pObstruction != nullptr
      && NAI_Hull::Width(id: *(_DWORD *)(*((_DWORD *)this - 1) + 1672)) > trace->flTotalDist - trace->flDistObstructed
      && trace->pObstruction == CBaseEntity::GetGroundEntity(this: *((CBaseEntity **)this - 1))
      && (trace->pObstruction->IsPlayer(this: trace->pObstruction)
       || __RTDynamicCast(
            inptr: trace->pObstruction,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CPhysicsProp `RTTI Type Descriptor',
            isReference: 0) != nullptr) )
    {
      CHandle<CBaseEntity>::operator=(
        this: (CHandle<CBaseEntity> *)&this->m_NextSidestepTimer,
        val: trace->pObstruction);
      *pResult = AIMR_CHANGE_TYPE;
      return 1;
    }
    if ( fMotorResult == AIM_PARTIAL_HIT_TARGET )
    {
      (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 52))(a1: (char *)this - 8);
      *pResult = AIMR_OK;
      return 1;
    }
    if ( fMotorResult == AIM_PARTIAL_HIT_NPC
      && CAI_Navigator::DelayNavigationFailure(this: (CAI_Navigator *)((char *)this - 8), trace) )
    {
      *pResult = AIMR_OK;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10064B40
// Name: private: bool CAI_Navigator::PreMove(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::PreMove(CAI_Navigator *this)
{
  Navigation_t v2; // eax
  Navigation_t m_navType; // edi
  CAI_BaseNPC *m_pOuter; // ecx
  const char *pszValue; // eax
  const char *v6; // ecx
  void (*MoveJumpStop)(void); // edx

  v2 = CAI_Path::CurWaypointNavType(this: this->m_pPath);
  m_navType = this->m_navType;
  this->m_fPeerMoveWait = false;
  if ( v2 == NAV_GROUND )
  {
    if ( m_navType == NAV_GROUND )
    {
LABEL_15:
      ((void (__thiscall *)(CAI_Navigator *, _DWORD, int))this->SimplifyPath)(a1: this, a2: 0, a3: -1082130432);
      return 1;
    }
    if ( m_navType != NAV_CRAWL )
    {
      m_pOuter = this->m_pOuter;
      pszValue = m_pOuter->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v6 = m_pOuter->m_iClassname.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      DevMsg(a1: "Warning: %s(%s) appears to have wrong nav type in CAI_Navigator::MoveGround()\n", v6, pszValue);
    }
    if ( m_navType == NAV_JUMP )
    {
      MoveJumpStop = (void (*)(void))this->m_pMotor->MoveJumpStop;
    }
    else
    {
      if ( m_navType != NAV_CLIMB )
      {
LABEL_14:
        this->m_navType = NAV_GROUND;
        goto LABEL_15;
      }
      MoveJumpStop = (void (*)(void))this->m_pMotor->MoveClimbStop;
    }
    MoveJumpStop();
    goto LABEL_14;
  }
  if ( v2 != NAV_FLY || m_navType == NAV_FLY )
    goto LABEL_15;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10064BE0
// Name: public: virtual float CAI_Navigator::CalcYawSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CAI_Navigator::CalcYawSpeed@<st0>(CAI_Navigator *this@<ecx>, int a2@<esi>)
{
  double result; // st7
  CAI_Path *m_pLocalNavigator; // ecx
  float *v5; // esi
  const Vector *v6; // eax
  float v8; // [esp-20h] [ebp-2Ch]
  float v9; // [esp-4h] [ebp-10h]

  result = ((double (__thiscall *)(int, int))**(_DWORD **)(*((_DWORD *)this - 1) + 2284))(
             a1: *((_DWORD *)this - 1) + 2284,
             a2);
  if ( result < 0.0 )
  {
    v9 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)this - 1) + 1944))(a1: *((_DWORD *)this - 1));
    if ( CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pLocalNavigator) != 0
      && ((double (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)this - 1) + 776))(a1: *((_DWORD *)this - 1)) != 0.0
      && this->m_pLocalNavigator->__vftable != nullptr
      && ((double (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)this - 1) + 776))(a1: *((_DWORD *)this - 1)) > 0.0
      && (m_pLocalNavigator = (CAI_Path *)this->m_pLocalNavigator,
          v5 = *((float **)this - 1),
          v6 = CAI_Path::CurWaypointPos(this: m_pLocalNavigator),
          (v8 = fsqrt(
                  (float)((float)((float)(v6->y - v5[176]) * (float)(v6->y - v5[176]))
                        + (float)((float)(v6->z - v5[177]) * (float)(v6->z - v5[177])))
                + (float)((float)(v6->x - v5[175]) * (float)(v6->x - v5[175])))) < 100.0) )
    {
      return ((100.0 - v8) * 0.01 + 1.0) * v9;
    }
    else
    {
      return v9;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064D20
// Name: public: float CAI_Navigator::GetStepDownMultiplier(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Navigator::GetStepDownMultiplier(CAI_Navigator *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hBigStepGroundEnt.m_Index;
  if ( m_Index == -1 )
    return 1.0;
  v2 = (unsigned __int16)m_Index;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v4 = HIWORD(m_Index);
  if ( v3->m_SerialNumber != v4 || v3->m_pEntity == nullptr )
    return 1.0;
  v5 = v2;
  v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
  v7 = &g_pEntityList->m_EntPtrArray[v5];
  if ( v6 )
    m_pEntity = v7->m_pEntity;
  else
    m_pEntity = nullptr;
  if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) != 0 )
    return 10.0;
  else
    return 2.5999999;
}

//------------------------------------------------------------------------------
// Address: 0x10064D90
// Name: private: bool CAI_Navigator::ShouldAttemptSimplifyTo(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Navigator::ShouldAttemptSimplifyTo(CAI_Navigator *this, const Vector *pos)
{
  CAI_BaseNPC *m_pOuter; // eax
  CAI_BaseNPC *v5; // esi
  const Vector *v6; // eax
  Vector vecCurrentDirectionOfMovement; // [esp+4h] [ebp-18h] BYREF
  Vector vecToPos; // [esp+10h] [ebp-Ch] BYREF

  if ( this->m_bForcedSimplify )
    return true;
  m_pOuter = this->m_pOuter;
  vecToPos.x = pos->x - m_pOuter->m_vecOrigin.m_Value.x;
  vecToPos.y = pos->y - m_pOuter->m_vecOrigin.m_Value.y;
  vecToPos.z = 0.0;
  VectorNormalize(vec: &vecToPos);
  v5 = this->m_pOuter;
  v6 = CAI_Path::CurWaypointPos(this: this->m_pPath);
  vecCurrentDirectionOfMovement.x = v6->x - v5->m_vecOrigin.m_Value.x;
  vecCurrentDirectionOfMovement.y = v6->y - v5->m_vecOrigin.m_Value.y;
  vecCurrentDirectionOfMovement.z = 0.0;
  VectorNormalize(vec: &vecCurrentDirectionOfMovement);
  return this->m_bForcedSimplify
      || (float)((float)(vecCurrentDirectionOfMovement.x * vecToPos.x)
               + (float)(vecToPos.y * vecCurrentDirectionOfMovement.y)) > 0.76599997;
}

//------------------------------------------------------------------------------
// Address: 0x10064E70
// Name: private: bool CAI_Navigator::ShouldSimplifyTo(bool,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_Navigator::ShouldSimplifyTo(CAI_Navigator *this, bool passedDetour, const Vector *pos)
{
  char v4; // di
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  AIMoveTrace_t moveTrace; // [esp+14h] [ebp-38h] BYREF
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  v4 = 8;
  if ( !passedDetour )
    v4 = 12;
  memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
  m_Index = this->m_pPath->m_target.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CAI_MoveProbe::MoveLimit(
    this: this->m_pMoveProbe,
    a2: (int)&savedregs,
    navType: this->m_navType,
    vecStart: &this->m_pOuter->m_vecOrigin.m_Value,
    vecEnd: pos,
    collisionMask: this->m_pOuter->m_nAITraceMask,
    pTarget: m_pEntity,
    pctToCheckStandPositions: 100.0,
    flags: v4,
    pTrace: &moveTrace);
  return moveTrace.fStatus >= AIMR_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10064F10
// Name: private: bool CAI_Navigator::SimplifyPathForwardScan(struct CAI_Navigator::SimplifyForwardScanParams const __near &,struct AI_Waypoint_t __near *,class Vector const __near &,float,bool,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CAI_Navigator::SimplifyPathForwardScan@<al>(
        CAI_Navigator *this@<ecx>,
        int a2@<ebp>,
        const CAI_Navigator::SimplifyForwardScanParams *params,
        AI_Waypoint_t *pCurWaypoint,
        const Vector *curPoint,
        float distRemaining,
        bool skipTest,
        bool passedDetour,
        int *pTestCount)
{
  AI_Waypoint_t *pNext; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float v12; // xmm3_4
  float increment; // xmm4_4
  __int128 v14; // xmm2
  float v15; // xmm3_4
  float z; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  unsigned int v19; // xmm1_4
  float v20; // xmm0_4
  bool v21; // zf
  CAI_BaseNPC *m_pOuter; // edx
  __int128 v23; // xmm0
  float v24; // xmm4_4
  float v25; // xmm1_4
  float radius; // xmm1_4
  __int128 v28; // [esp+20h] [ebp-3Ch] BYREF
  __int128 nextPoint; // [esp+30h] [ebp-2Ch] OVERLAPPED BYREF
  Vector offset; // [esp+40h] [ebp-1Ch]
  CAI_Navigator *v31; // [esp+4Ch] [ebp-10h]
  int v32; // [esp+50h] [ebp-Ch]
  void *skipTestNext; // [esp+54h] [ebp-8h]
  void *retaddr; // [esp+5Ch] [ebp+0h]

  v32 = a2;
  skipTestNext = retaddr;
  pNext = pCurWaypoint->pNext;
  v31 = this;
  if ( !passedDetour )
    passedDetour = pCurWaypoint->m_fWaypointFlags & 1;
  if ( distRemaining > 0.0
    && pNext != nullptr
    && pCurWaypoint->m_iWPType == pNext->m_iWPType
    && (pCurWaypoint->m_fWaypointFlags & 0x2A) == 0 )
  {
    x = pNext->vecLocation.x;
    y = pNext->vecLocation.y;
    v12 = (float)(y - curPoint->y) * (float)(y - curPoint->y);
    if ( this->m_navType != NAV_GROUND )
      v12 = v12 + (float)((float)(pNext->vecLocation.z - curPoint->z) * (float)(pNext->vecLocation.z - curPoint->z));
    increment = params->increment;
    v14 = 0;
    *(float *)&v14 = fsqrt(
                       v12
                     + (float)((float)(pNext->vecLocation.x - curPoint->x) * (float)(pNext->vecLocation.x - curPoint->x)));
    v28 = v14;
    v15 = *(float *)&v14;
    if ( increment * 1.1 <= *(float *)&v14 )
    {
      *(float *)&v19 = y - pCurWaypoint->vecLocation.y;
      *((float *)&nextPoint + 1) = x - pCurWaypoint->vecLocation.x;
      *((_QWORD *)&nextPoint + 1) = __PAIR64__(pNext->vecLocation.z - pCurWaypoint->vecLocation.z, v19);
      VectorNormalize(vec: (Vector *)((char *)&nextPoint + 4));
      v20 = params->increment;
      this = v31;
      v17 = curPoint->x + (float)(*((float *)&nextPoint + 1) * v20);
      y = curPoint->y + (float)(*((float *)&nextPoint + 2) * v20);
      z = curPoint->z + (float)(*((float *)&nextPoint + 3) * v20);
      v18 = distRemaining - v20;
      pNext = pCurWaypoint;
    }
    else
    {
      z = pNext->vecLocation.z;
      v17 = x;
      v18 = distRemaining - v15;
    }
    v21 = this->m_navType == NAV_GROUND;
    m_pOuter = this->m_pOuter;
    *(_QWORD *)((char *)&v28 + 4) = __PAIR64__(LODWORD(y), LODWORD(v17));
    *((float *)&v28 + 3) = z;
    v23 = 0;
    v24 = (float)(v17 - m_pOuter->m_vecOrigin.m_Value.x) * (float)(v17 - m_pOuter->m_vecOrigin.m_Value.x);
    v25 = (float)(y - m_pOuter->m_vecOrigin.m_Value.y) * (float)(y - m_pOuter->m_vecOrigin.m_Value.y);
    if ( !v21 )
      v25 = v25 + (float)((float)(z - m_pOuter->m_vecOrigin.m_Value.z) * (float)(z - m_pOuter->m_vecOrigin.m_Value.z));
    *(float *)&v23 = v25 + v24;
    radius = params->radius;
    *(float *)&v23 = fsqrt(*(float *)&v23);
    nextPoint = v23;
    LOBYTE(offset.z) = *(float *)&v23 > radius + 0.1;
    if ( CAI_Navigator::SimplifyPathForwardScan(
           this,
           params,
           pCurWaypoint: pNext,
           curPoint: (const Vector *)((char *)&v28 + 4),
           distRemaining: v18,
           skipTest: SLOBYTE(offset.z),
           passedDetour,
           pTestCount) )
    {
      return 1;
    }
    this = v31;
  }
  if ( !skipTest && *pTestCount < params->maxSamples && CAI_Navigator::ShouldAttemptSimplifyTo(this, pos: curPoint) )
  {
    ++*pTestCount;
    if ( CAI_Navigator::ShouldSimplifyTo(this: v31, passedDetour, pos: curPoint) )
    {
      CAI_Navigator::SimplifyPathInsertSimplification(this: v31, pSegmentStart: pCurWaypoint, point: curPoint);
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10065170
// Name: private: bool CAI_Navigator::SimplifyPathBacktrack(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CAI_Navigator::SimplifyPathBacktrack@<al>(
        CAI_Navigator *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  CAI_Path *m_pPath; // eax
  float v6; // edi
  float v7; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  float v9; // xmm2_4
  float v10; // xmm1_4
  CAI_Path *v11; // edx
  __int128 v12; // xmm0
  float v13; // xmm0_4
  CAI_BaseNPC *v14; // ecx
  int (__thiscall *CapabilitiesGet)(CAI_BaseNPC *); // edx
  int v16; // edi
  CAI_Path *v17; // ecx
  AI_Waypoint_t *m_pPathfinder; // eax
  CBaseEntity *Target; // eax
  CAI_Path *v20; // ecx
  CAI_Pathfinder_vtbl *v21; // edi
  CBaseEntity *v22; // eax
  AI_Waypoint_t *v23; // eax
  AI_Waypoint_t *v25; // edi
  float x; // eax
  _DWORD *v27; // edi
  int v28; // ecx
  int v29; // eax
  int v30; // eax
  int v31; // [esp+18h] [ebp-64h]
  AI_Waypoint_t *v32; // [esp+1Ch] [ebp-60h]
  __int128 v35; // [esp+30h] [ebp-4Ch] BYREF
  Vector v36; // [esp+4Ch] [ebp-30h] BYREF
  Vector firstToNext; // [esp+58h] [ebp-24h]
  AI_Waypoint_t *pCurWaypoint; // [esp+64h] [ebp-18h]
  AI_Waypoint_t *v39; // [esp+68h] [ebp-14h]
  int v40; // [esp+6Ch] [ebp-10h]
  float goalTolerance; // [esp+70h] [ebp-Ch]
  AI_Waypoint_t *route1; // [esp+74h] [ebp-8h]
  AI_Waypoint_t *retaddr; // [esp+7Ch] [ebp+0h]

  goalTolerance = a2;
  route1 = retaddr;
  m_pPath = this->m_pPath;
  v6 = *(float *)&m_pPath->m_Waypoints.m_pFirstWaypoint;
  v7 = *(float *)&m_pPath->m_Waypoints.m_pFirstWaypoint->pNext;
  firstToNext.x = v6;
  firstToNext.z = v7;
  if ( v7 == 0.0 )
    return 0;
  if ( (*(_BYTE *)(LODWORD(v7) + 32) & 4) == 0 )
    return 0;
  if ( *(_DWORD *)(LODWORD(v7) + 36) != 0 )
    return 0;
  if ( *(_DWORD *)(LODWORD(v6) + 36) != 0 )
    return 0;
  if ( (*(_BYTE *)(LODWORD(v6) + 32) & 4) == 0 )
    return 0;
  m_pOuter = this->m_pOuter;
  *((float *)&v35 + 1) = m_pOuter->m_vecOrigin.m_Value.x - *(float *)LODWORD(v6);
  *((float *)&v35 + 2) = m_pOuter->m_vecOrigin.m_Value.y - *(float *)(LODWORD(v6) + 4);
  v36.x = *(float *)LODWORD(v7) - *(float *)LODWORD(v6);
  v36.y = *(float *)(LODWORD(v7) + 4) - *(float *)(LODWORD(v6) + 4);
  v36.z = *(float *)(LODWORD(v7) + 8) - *(float *)(LODWORD(v6) + 8);
  VectorNormalize(vec: &v36);
  v9 = *((float *)&v35 + 2);
  v10 = *((float *)&v35 + 1);
  v11 = this->m_pPath;
  v12 = 0;
  v36.z = 0.0;
  *(float *)&v12 = fsqrt((float)((float)(v9 * v9) + (float)(0.0 * 0.0)) + (float)(v10 * v10));
  v35 = v12;
  v13 = (float)(v36.y * v9) + (float)(v36.x * v10);
  pCurWaypoint = (AI_Waypoint_t *)LODWORD(v11->m_goalTolerance);
  if ( v13 <= *(float *)&v35 * 0.5 )
    return 0;
  v14 = this->m_pOuter;
  *((float *)&v35 + 1) = *(float *)LODWORD(v6) + (float)(v36.x * v13);
  *((float *)&v35 + 2) = *(float *)(LODWORD(v6) + 4) + (float)(v36.y * v13);
  *((float *)&v35 + 3) = *(float *)(LODWORD(v6) + 8) + (float)(v13 * 0.0);
  CapabilitiesGet = v14->CapabilitiesGet;
  v16 = 0;
  v40 = 0;
  if ( (((int (__thiscall *)(CAI_BaseNPC *, int, int))CapabilitiesGet)(a1: v14, a2: a3, a3: a4) & 1) != 0 )
  {
    v16 = 1;
    v40 = 1;
  }
  if ( (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 2) != 0 )
  {
    v16 |= 2u;
    v40 = v16;
  }
  v17 = this->m_pPath;
  m_pPathfinder = (AI_Waypoint_t *)this->m_pOuter->m_pPathfinder;
  *(_QWORD *)((char *)&v35 + 4) = __PAIR64__((unsigned int)pCurWaypoint, v16);
  v39 = m_pPathfinder;
  firstToNext.y = m_pPathfinder->vecLocation.x;
  Target = CAI_Path::GetTarget(this: v17);
  v39 = (AI_Waypoint_t *)(*(int (__thiscall **)(AI_Waypoint_t *, CNetworkVectorXY_SeparateZBase<Vector,CBaseEntity::NetworkVar_m_vecOrigin> *, char *, CBaseEntity *, int, int))(LODWORD(firstToNext.y) + 24))(
                           a1: v39,
                           a2: &this->m_pOuter->m_vecOrigin,
                           a3: (char *)&v35 + 4,
                           a4: Target,
                           a5: 1,
                           a6: -1);
  if ( v39 == nullptr )
    return 0;
  v20 = this->m_pPath;
  v21 = this->m_pOuter->m_pPathfinder->__vftable;
  v32 = pCurWaypoint;
  v31 = v40;
  LODWORD(firstToNext.y) = this->m_pOuter->m_pPathfinder;
  v22 = CAI_Path::GetTarget(this: v20);
  v23 = (AI_Waypoint_t *)((int (__thiscall *)(_DWORD, char *, _DWORD, CBaseEntity *, int, int, int, AI_Waypoint_t *))v21->BuildLocalRoute)(
                           a1: LODWORD(firstToNext.y),
                           a2: (char *)&v35 + 4,
                           a3: LODWORD(firstToNext.z),
                           a4: v22,
                           a5: 1,
                           a6: -1,
                           a7: v31,
                           a8: v32);
  if ( v23 == nullptr )
  {
    DeleteAll(pWaypointList: v39);
    return 0;
  }
  v25 = v39;
  AddWaypointLists(oldRoute: v39, addRoute: v23);
  AddWaypointLists(oldRoute: v25, addRoute: *(AI_Waypoint_t **)(LODWORD(firstToNext.z) + 40));
  x = firstToNext.x;
  v27 = *(_DWORD **)(LODWORD(firstToNext.x) + 40);
  if ( v27 != nullptr )
    v27[11] = *(_DWORD *)(LODWORD(firstToNext.x) + 44);
  v28 = *(_DWORD *)(LODWORD(x) + 44);
  if ( v28 != 0 )
    *(_DWORD *)(v28 + 40) = *(_DWORD *)(LODWORD(x) + 40);
  CUtlMemoryPool::Free(this: &AI_Waypoint_t::s_Allocator, memBlock: (void *)LODWORD(x));
  if ( v27 != nullptr )
  {
    v29 = v27[10];
    if ( v29 != 0 )
      *(_DWORD *)(v29 + 44) = v27[11];
    v30 = v27[11];
    if ( v30 != 0 )
      *(_DWORD *)(v30 + 40) = v27[10];
    CUtlMemoryPool::Free(this: &AI_Waypoint_t::s_Allocator, memBlock: v27);
  }
  CAI_Path::SetWaypoints(this: this->m_pPath, route: v39, fSetGoalFromLast: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10065440
// Name: public: bool CAI_Navigator::CanFitAtPosition(class Vector const __near &,unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
bool __userpurge CAI_Navigator::CanFitAtPosition@<al>(
        CAI_Navigator *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vStartPos,
        unsigned int collisionMask,
        bool bIgnoreTransients,
        bool bAllowPlayerAvoid)
{
  float z; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  const Vector *v11; // eax
  CAI_BaseNPC *v12; // edx
  const Vector *v13; // eax
  int m_eHull; // [esp+10h] [ebp-F0h]
  Ray_t v17; // [esp+24h] [ebp-DCh] BYREF
  Vector v18; // [esp+74h] [ebp-8Ch] BYREF
  CGameTrace tr; // [esp+80h] [ebp-80h] BYREF
  CTraceFilterNav traceFilter; // [esp+D8h] [ebp-28h] BYREF
  Vector vEndPos; // [esp+F0h] [ebp-10h]
  float retaddr; // [esp+100h] [ebp+0h]

  vEndPos.y = a2;
  vEndPos.z = retaddr;
  CTraceFilterNav::CTraceFilterNav(
    this: (CTraceFilterNav *)&tr.m_pEnt,
    pProber: this->m_pOuter,
    bIgnoreTransientEntities: bIgnoreTransients,
    passedict: this->m_pOuter,
    collisionGroup: 0,
    bAllowPlayerAvoid);
  z = vStartPos->z;
  m_pOuter = this->m_pOuter;
  *(_QWORD *)&traceFilter.m_pExtraShouldHitCheckFunction = *(_QWORD *)&vStartPos->x;
  *(float *)&traceFilter.m_bIgnoreTransientEntities = z;
  m_eHull = m_pOuter->m_eHull;
  *(float *)&traceFilter.m_bIgnoreTransientEntities = z + 0.01;
  v11 = NAI_Hull::Maxs(id: m_eHull);
  v12 = this->m_pOuter;
  LODWORD(vEndPos.x) = v11;
  v13 = NAI_Hull::Mins(id: v12->m_eHull);
  v17.m_pWorldAxisTransform = nullptr;
  Ray_t::Init(
    this: &v17,
    start: vStartPos,
    end: (const Vector *)&traceFilter.m_pExtraShouldHitCheckFunction,
    mins: v13,
    maxs: (const Vector *)LODWORD(vEndPos.x));
  ((void (__thiscall *)(IEngineTrace *, Ray_t *, unsigned int, CBaseEntity **, Vector *, int, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: &v17,
    a3: collisionMask,
    a4: &tr.m_pEnt,
    a5: &v18,
    a6: a3,
    a7: a4);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v18, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
  return tr.plane.pad[1] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10065560
// Name: public: float CAI_Navigator::GetPathDistToCurWaypoint(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Navigator::GetPathDistToCurWaypoint(CAI_Navigator *this)
{
  CAI_Path *m_pPath; // ecx
  CAI_BaseNPC *m_pOuter; // esi
  Navigation_t m_navType; // edi
  const Vector *v5; // eax
  float v6; // xmm1_4

  m_pPath = this->m_pPath;
  if ( m_pPath->m_Waypoints.m_pFirstWaypoint == nullptr )
    return 0.0;
  m_pOuter = this->m_pOuter;
  m_navType = this->m_navType;
  v5 = CAI_Path::CurWaypointPos(this: m_pPath);
  v6 = (float)(v5->y - m_pOuter->m_vecOrigin.m_Value.y) * (float)(v5->y - m_pOuter->m_vecOrigin.m_Value.y);
  if ( m_navType != NAV_GROUND )
    v6 = v6
       + (float)((float)(v5->z - m_pOuter->m_vecOrigin.m_Value.z) * (float)(v5->z - m_pOuter->m_vecOrigin.m_Value.z));
  return fsqrt(
           v6
         + (float)((float)(v5->x - m_pOuter->m_vecOrigin.m_Value.x) * (float)(v5->x - m_pOuter->m_vecOrigin.m_Value.x)));
}

//------------------------------------------------------------------------------
// Address: 0x10065610
// Name: public: float CAI_Navigator::GetPathDistToGoal(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Navigator::GetPathDistToGoal(CAI_Navigator *this)
{
  CAI_Path *m_pPath; // ecx
  CAI_BaseNPC *m_pOuter; // edi
  const Vector *v4; // eax
  float v5; // xmm1_4
  Navigation_t m_navType; // [esp-4h] [ebp-10h]

  m_pPath = this->m_pPath;
  if ( m_pPath->m_Waypoints.m_pFirstWaypoint == nullptr )
    return 0.0;
  m_pOuter = this->m_pOuter;
  m_navType = this->m_navType;
  v4 = CAI_Path::CurWaypointPos(this: m_pPath);
  v5 = (float)(v4->y - m_pOuter->m_vecOrigin.m_Value.y) * (float)(v4->y - m_pOuter->m_vecOrigin.m_Value.y);
  if ( m_navType != NAV_GROUND )
    v5 = v5
       + (float)((float)(v4->z - m_pOuter->m_vecOrigin.m_Value.z) * (float)(v4->z - m_pOuter->m_vecOrigin.m_Value.z));
  return (float)(this->m_pPath->m_Waypoints.m_pFirstWaypoint->flPathDistGoal
               + fsqrt(
                   v5
                 + (float)((float)(v4->x - m_pOuter->m_vecOrigin.m_Value.x)
                         * (float)(v4->x - m_pOuter->m_vecOrigin.m_Value.x))));
}

//------------------------------------------------------------------------------
// Address: 0x100656D0
// Name: protected: virtual bool CAI_Navigator::MarkCurWaypointFailedLink(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::MarkCurWaypointFailedLink(CAI_Navigator *this)
{
  CAI_Path *m_pPath; // eax
  int m_iLastNodeReached; // edi
  int iNodeID; // eax
  CBaseEntity *v5; // eax
  CBaseEntity *v6; // eax
  CBaseEntity *v7; // eax
  CBaseEntity *v8; // eax
  CBaseEntity *v9; // esi
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float *v11; // edi
  float *v12; // eax
  int v13; // eax
  float v14; // xmm0_4
  Hull_t m_eHull; // edx
  CAI_Network *v16; // ecx
  CAI_Node *v17; // ecx
  const Vector *HullMins; // eax
  CAI_Network *v19; // eax
  CAI_Node *v20; // edx
  int v21; // ecx
  CAI_Link *v22; // eax
  CAI_Network *m_pAINetwork; // eax
  CAI_Node *v25; // ecx
  CAI_Link *v26; // eax
  const Vector *HullMaxs; // [esp-18h] [ebp-94h]
  CBaseEntity *v28; // [esp-14h] [ebp-90h]
  CGameTrace tr; // [esp+4h] [ebp-78h] BYREF
  Vector vEndPos; // [esp+58h] [ebp-24h] BYREF
  Vector vStartPos; // [esp+64h] [ebp-18h] BYREF
  int startID; // [esp+70h] [ebp-Ch]
  int endID; // [esp+74h] [ebp-8h]
  bool bFoundSmall; // [esp+79h] [ebp-3h]
  bool bFoundLarge; // [esp+7Ah] [ebp-2h]
  bool didMark; // [esp+7Bh] [ebp-1h]

  if ( !this->m_fRememberStaleNodes )
    return 0;
  m_pPath = this->m_pPath;
  if ( m_pPath == nullptr || m_pPath->m_Waypoints.m_pFirstWaypoint == nullptr )
    return 0;
  m_iLastNodeReached = m_pPath->m_iLastNodeReached;
  iNodeID = m_pPath->m_Waypoints.m_pFirstWaypoint->iNodeID;
  didMark = false;
  startID = m_iLastNodeReached;
  endID = iNodeID;
  if ( iNodeID == -1 )
    return didMark;
  if ( !CHandle<CBaseEntity>::operator!=(this: &this->m_hLastBlockingEnt, val: nullptr)
    || (v5 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hLastBlockingEnt), v5->IsPlayer(this: v5))
    || (v6 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hLastBlockingEnt), v6->IsNPC(this: v6))
    || CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hLastBlockingEnt)->m_MoveType.m_Value != 6
    || CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hLastBlockingEnt)->m_pPhysicsObject == nullptr
    || (v7 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hLastBlockingEnt),
        v7->m_pPhysicsObject->IsMoveable(this: v7->m_pPhysicsObject))
    && (v8 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hLastBlockingEnt),
        ((double (__thiscall *)(IPhysicsObject *))v8->m_pPhysicsObject->GetMass)(a1: v8->m_pPhysicsObject) <= 200.0) )
  {
LABEL_35:
    if ( m_iLastNodeReached != -1 )
    {
      m_pAINetwork = this->m_pAINetwork;
      if ( m_iLastNodeReached < 0 || m_iLastNodeReached >= m_pAINetwork->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v25 = nullptr;
      }
      else
      {
        v25 = m_pAINetwork->m_pAInode[m_iLastNodeReached];
      }
      v26 = CAI_Node::HasLink(this: v25, nNodeID: endID);
      if ( v26 != nullptr )
      {
        v26->m_LinkInfo |= 1u;
        v26->m_timeStaleExpires = gpGlobals->curtime + 4.0;
        return 1;
      }
    }
    return didMark;
  }
  v9 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hLastBlockingEnt);
  OBBMins = v9->m_Collision.OBBMins;
  bFoundLarge = false;
  bFoundSmall = false;
  v11 = (float *)OBBMins(this: &v9->m_Collision);
  v12 = (float *)v9->m_Collision.OBBMaxs(this: &v9->m_Collision);
  vStartPos.x = *v12 - *v11;
  vStartPos.y = v12[1] - v11[1];
  vStartPos.z = v12[2] - v11[2];
  v13 = 0;
  while ( 1 )
  {
    v14 = *(&vStartPos.x + v13);
    if ( v14 > 40.0 )
      bFoundLarge = true;
    if ( v14 < 30.0 )
      break;
    if ( ++v13 >= 3 )
      goto LABEL_19;
  }
  bFoundSmall = true;
LABEL_19:
  if ( bFoundLarge && !bFoundSmall )
  {
    m_eHull = this->m_pOuter->m_eHull;
    v16 = this->m_pAINetwork;
    if ( endID < 0 || endID >= v16->m_iNumNodes )
    {
      ++`CAI_Network::GetNode'::`8'::warningCount;
      v17 = nullptr;
    }
    else
    {
      v17 = v16->m_pAInode[endID];
    }
    CAI_Node::GetPosition(this: v17, result: &vStartPos, hull: m_eHull);
    *(_QWORD *)&vEndPos.x = *(_QWORD *)&vStartPos.x;
    vEndPos.z = vStartPos.z + 0.01;
    v28 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hLastBlockingEnt);
    HullMaxs = CAI_Component::GetHullMaxs(this);
    HullMins = CAI_Component::GetHullMins(this);
    UTIL_TraceModel(
      vecStart: &vStartPos,
      vecEnd: &vEndPos,
      hullMin: HullMins,
      hullMax: HullMaxs,
      pentModel: v28,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.startsolid )
    {
      v19 = this->m_pAINetwork;
      if ( endID < 0 || endID >= v19->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        v20 = nullptr;
      }
      else
      {
        v20 = v19->m_pAInode[endID];
      }
      v21 = 0;
      if ( v20->m_Links.m_Size <= 0 )
        return didMark;
      didMark = true;
      do
      {
        v22 = v20->m_Links.m_Memory.m_pMemory[v21];
        v22->m_LinkInfo |= 1u;
        ++v21;
        v22->m_timeStaleExpires = gpGlobals->curtime + 4.0;
      }
      while ( v21 < v20->m_Links.m_Size );
      return didMark;
    }
  }
  m_iLastNodeReached = startID;
  goto LABEL_35;
}

//------------------------------------------------------------------------------
// Address: 0x100659F0
// Name: protected: virtual bool CAI_Navigator::DoFindPathToPos(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall CAI_Navigator::DoFindPathToPos@<al>(CAI_Navigator *this@<ecx>, float a2@<ebp>)
{
  CAI_Path *m_pPath; // edi
  unsigned int m_Index; // eax
  CAI_WaypointList *m_pClippedWaypoints; // ecx
  CAI_BaseNPC *m_pOuter; // eax
  float z; // xmm0_4
  AI_Waypoint_t *Last; // eax
  int v9; // edi
  AI_Waypoint_t *v10; // eax
  AI_Waypoint_t *m_pActor; // edi
  CChoreoChannel *v13; // ecx
  CAI_Path *v14; // ecx
  AI_Waypoint_t *pNext; // eax
  Navigation_t m_iWPType; // eax
  __int128 v17; // xmm0
  __int64 v18; // xmm0_8
  double v19; // st6
  Vector v20; // [esp+14h] [ebp-44h] BYREF
  Vector vClosest; // [esp+20h] [ebp-38h] BYREF
  __int128 origin; // [esp+2Ch] [ebp-2Ch] OVERLAPPED
  const Vector *v23; // [esp+3Ch] [ebp-1Ch]
  float goalTolerance; // [esp+40h] [ebp-18h]
  CAI_Pathfinder *pPathfinder; // [esp+44h] [ebp-14h]
  const Vector *actualGoalPos; // [esp+48h] [ebp-10h]
  float tolerance; // [esp+4Ch] [ebp-Ch]
  CAI_Path *pPath; // [esp+50h] [ebp-8h]
  CAI_Path *retaddr; // [esp+58h] [ebp+0h]

  tolerance = a2;
  pPath = retaddr;
  m_pPath = this->m_pPath;
  HIDWORD(origin) = this->m_pOuter->m_pPathfinder;
  pPathfinder = (CAI_Pathfinder *)m_pPath;
  v23 = CAI_Path::ActualGoalPosition(this: m_pPath);
  m_Index = m_pPath->m_target.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    actualGoalPos = nullptr;
  else
    actualGoalPos = (const Vector *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  goalTolerance = m_pPath->m_goalTolerance;
  if ( (float)(gpGlobals->curtime - this->m_flTimeClipped) > 0.11 || this->m_bLastNavFailed )
    CAI_WaypointList::RemoveAll(this: this->m_pClippedWaypoints);
  m_pClippedWaypoints = this->m_pClippedWaypoints;
  if ( m_pClippedWaypoints->m_pFirstWaypoint != nullptr )
  {
    Last = CAI_WaypointList::GetLast(this: m_pClippedWaypoints);
    vClosest.x = Last->vecLocation.x;
    vClosest.y = Last->vecLocation.y;
    z = Last->vecLocation.z;
  }
  else
  {
    m_pOuter = this->m_pOuter;
    vClosest.x = m_pOuter->m_vecOrigin.m_Value.x;
    vClosest.y = m_pOuter->m_vecOrigin.m_Value.y;
    z = m_pOuter->m_vecOrigin.m_Value.z;
  }
  vClosest.z = z;
  this->m_bLastNavFailed = false;
  CAI_WaypointList::RemoveAll(this: &m_pPath->m_Waypoints);
  m_pPath->m_iLastNodeReached = -1;
  v9 = 0;
  if ( (vgui::BuildGroup::GetCurrentPanel(this: (vgui::Panel *)this->m_pPath) & 8) != 0 )
    v9 = 512;
  if ( (vgui::BuildGroup::GetCurrentPanel(this: (vgui::Panel *)this->m_pPath) & 0x10) != 0 )
    v9 |= 0x400u;
  if ( (vgui::BuildGroup::GetCurrentPanel(this: (vgui::Panel *)this->m_pPath) & 0x20) != 0 )
    v9 |= 0x800u;
  v10 = CAI_Pathfinder::BuildRoute(
          this: (CAI_Pathfinder *)HIDWORD(origin),
          vStart: &vClosest,
          vEnd: v23,
          pTarget: (CBaseEntity *)actualGoalPos,
          goalTolerance,
          curNavType: this->m_navType,
          nBuildFlags: v9);
  m_pActor = v10;
  if ( v10 == nullptr )
    return 0;
  CAI_Path::SetWaypoints(this: (CAI_Path *)pPathfinder, route: v10, fSetGoalFromLast: false);
  v13 = (CChoreoChannel *)this->m_pClippedWaypoints;
  if ( v13->m_pActor != nullptr )
  {
    m_pActor = (AI_Waypoint_t *)v13->m_pActor;
    CAI_WaypointList::Set(this: v13, actor: nullptr);
    v14 = (CAI_Path *)pPathfinder;
    m_pActor->m_fWaypointFlags |= 0x20u;
    CAI_Path::PrependWaypoints(this: v14, pWaypoints: m_pActor);
  }
  pNext = m_pActor->pNext;
  if ( pNext != nullptr )
  {
    m_iWPType = pNext->m_iWPType;
    if ( m_pActor->m_iWPType == m_iWPType
      && (m_pActor->m_fWaypointFlags & 0x2A) == 0
      && m_iWPType == this->m_navType
      && this->ShouldOptimizeInitialPathSegment(this, a2: m_pActor) )
    {
      CalcClosestPointOnLineSegment(
        P: &vClosest,
        vLineA: &m_pActor->vecLocation,
        vLineB: &m_pActor->pNext->vecLocation,
        vClosest: &v20,
        outT: nullptr);
      v17 = 0;
      *(float *)&v17 = fsqrt(
                         (float)((float)((float)(m_pActor->vecLocation.y - v20.y)
                                       * (float)(m_pActor->vecLocation.y - v20.y))
                               + (float)((float)(m_pActor->vecLocation.z - v20.z)
                                       * (float)(m_pActor->vecLocation.z - v20.z)))
                       + (float)((float)(m_pActor->vecLocation.x - v20.x) * (float)(m_pActor->vecLocation.x - v20.x)));
      origin = v17;
      if ( *(float *)&v17 > 0.1 )
      {
        HIDWORD(v18) = 0;
        *(float *)&v18 = fsqrt(
                           (float)((float)((float)(vClosest.y - v20.y) * (float)(vClosest.y - v20.y))
                                 + (float)((float)(vClosest.z - v20.z) * (float)(vClosest.z - v20.z)))
                         + (float)((float)(vClosest.x - v20.x) * (float)(vClosest.x - v20.x)));
        *(_QWORD *)&origin = v18;
        *((double *)&origin + 1) = *(float *)&v18;
        v19 = CAI_Component::GetHullWidth(this) * 0.5;
        if ( v19 > *((double *)&origin + 1) )
          CAI_Path::Advance(this: (CAI_Path *)pPathfinder);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10065CB0
// Name: private: bool CAI_Navigator::DoFindPathToPathcorner(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Navigator::DoFindPathToPathcorner(CAI_Navigator *this, CBaseEntity *pPathCorner)
{
  bool result; // al
  __int64 v5; // xmm0_8
  CAI_BaseNPC *m_pOuter; // ecx
  CAI_BaseNPC *v7; // ecx
  float (__thiscall *GetDefaultNavGoalTolerance)(CAI_BaseNPC *); // eax
  float v9; // xmm0_4
  AI_Waypoint_t *Last; // ebx
  CAI_Hint *v11; // edi
  AI_Waypoint_t *v12; // eax
  AI_Waypoint_t *v13; // edi
  CAI_BaseNPC *v14; // ecx
  float m_flSpeed; // xmm0_4
  CAI_Path *m_pPath; // ebx
  AI_Waypoint_t *v17; // eax
  AI_Waypoint_t *v18; // ebx
  CAI_Hint *NextPathcorner; // edi
  AI_Waypoint_t *v20; // eax
  AI_Waypoint_t *pNext; // eax
  AI_Waypoint_t *pPrev; // eax
  Vector initPos; // [esp+24h] [ebp-20h] BYREF
  Vector waypointPos; // [esp+30h] [ebp-14h] BYREF
  float tolerance; // [esp+3Ch] [ebp-8h]
  bool returnCode; // [esp+43h] [ebp-1h]
  float outerTolerance; // [esp+4Ch] [ebp+8h]
  const CBaseEntity *outerTolerancea; // [esp+4Ch] [ebp+8h]
  AI_Waypoint_t *outerToleranceb; // [esp+4Ch] [ebp+8h]

  result = false;
  if ( pPathCorner != nullptr )
  {
    if ( (vgui::BuildGroup::GetCurrentPanel(this: (vgui::Panel *)this->m_pPath) & 4) != 0
      || this->m_bNoPathcornerPathfinds )
    {
      m_flSpeed = pPathCorner->m_flSpeed;
      if ( m_flSpeed != 0.0 )
        this->m_pOuter->m_flSpeed = m_flSpeed;
      m_pPath = this->m_pPath;
      CAI_WaypointList::RemoveAll(this: &m_pPath->m_Waypoints);
      m_pPath->m_iLastNodeReached = -1;
      v17 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
      if ( v17 != nullptr )
        v18 = AI_Waypoint_t::AI_Waypoint_t(
                this: v17,
                initPosition: &pPathCorner->m_vecOrigin.m_Value,
                initYaw: 0.0,
                initNavType: this->m_navType,
                initWaypointFlags: 2,
                initNodeID: -1);
      else
        v18 = nullptr;
      v18->hPathCorner.m_Index = pPathCorner->GetRefEHandle(this: pPathCorner)->m_Index;
      outerToleranceb = v18;
      NextPathcorner = CAI_Navigator::GetNextPathcorner(this, pPathCorner);
      if ( NextPathcorner != nullptr )
      {
        v20 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
        if ( v20 != nullptr )
          outerToleranceb = AI_Waypoint_t::AI_Waypoint_t(
                              this: v20,
                              initPosition: &NextPathcorner->m_vecOrigin.m_Value,
                              initYaw: 0.0,
                              initNavType: this->m_navType,
                              initWaypointFlags: 2,
                              initNodeID: -1);
        else
          outerToleranceb = nullptr;
        outerToleranceb->hPathCorner.m_Index = NextPathcorner->GetRefEHandle(this: NextPathcorner)->m_Index;
        pNext = v18->pNext;
        if ( pNext != nullptr )
          pNext->pPrev = nullptr;
        v18->pNext = outerToleranceb;
        if ( outerToleranceb != nullptr )
        {
          pPrev = outerToleranceb->pPrev;
          if ( pPrev != nullptr )
            pPrev->pNext = nullptr;
          v18->pNext->pPrev = v18;
        }
      }
      outerToleranceb->m_fWaypointFlags |= 8u;
      CAI_Path::SetWaypoints(this: this->m_pPath, route: v18, fSetGoalFromLast: true);
      return true;
    }
    else
    {
      v5 = *(_QWORD *)&pPathCorner->m_vecOrigin.m_Value.x;
      m_pOuter = this->m_pOuter;
      initPos.z = pPathCorner->m_vecOrigin.m_Value.z;
      *(_QWORD *)&initPos.x = v5;
      m_pOuter->TranslateNavGoal(this: m_pOuter, a2: pPathCorner, a3: &initPos);
      CAI_Path::ResetGoalPosition(this: this->m_pPath, goalPos: &initPos);
      v7 = this->m_pOuter;
      GetDefaultNavGoalTolerance = v7->GetDefaultNavGoalTolerance;
      tolerance = this->m_pPath->m_goalTolerance;
      outerTolerance = GetDefaultNavGoalTolerance(this: v7);
      if ( outerTolerance > tolerance )
      {
        this->m_pPath->m_goalTolerance = outerTolerance;
        tolerance = outerTolerance;
      }
      result = this->DoFindPathToPos(this);
      returnCode = result;
      if ( result )
      {
        v9 = pPathCorner->m_flSpeed;
        if ( v9 != 0.0 )
          this->m_pOuter->m_flSpeed = v9;
        Last = CAI_WaypointList::GetLast(this: &this->m_pPath->m_Waypoints);
        Last->m_fWaypointFlags |= 2u;
        CHandle<CBaseEntity>::operator=(this: &Last->hPathCorner, val: pPathCorner);
        v11 = CAI_Navigator::GetNextPathcorner(this, pPathCorner);
        outerTolerancea = v11;
        if ( v11 != nullptr )
        {
          Last->m_fWaypointFlags &= ~8u;
          v12 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
          if ( v12 != nullptr )
            v13 = AI_Waypoint_t::AI_Waypoint_t(
                    this: v12,
                    initPosition: &v11->m_vecOrigin.m_Value,
                    initYaw: 0.0,
                    initNavType: this->m_navType,
                    initWaypointFlags: 10,
                    initNodeID: -1);
          else
            v13 = nullptr;
          v14 = this->m_pOuter;
          waypointPos = v13->vecLocation;
          v14->TranslateNavGoal(this: v14, a2: (CBaseEntity *)outerTolerancea, a3: &waypointPos);
          v13->vecLocation = waypointPos;
          this->m_pPath->m_goalTolerance = tolerance;
          CHandle<CBaseEntity>::operator=(this: &v13->hPathCorner, val: outerTolerancea);
          AI_Waypoint_t::SetNext(this: Last, p: v13);
          CAI_Path::ResetGoalPosition(this: this->m_pPath, goalPos: &v13->vecLocation);
        }
        return returnCode;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065F80
// Name: private: bool CAI_Navigator::DoFindPath(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Navigator::DoFindPath(CAI_Navigator *this)
{
  CFmtStrN<256> *v2; // eax
  CAI_Path *m_pPath; // edi
  bool v4; // bl
  CBaseEntity *GoalEnt; // eax
  bool result; // al
  CBaseEntity *v7; // edi
  Vector *v8; // eax
  CAI_Path *v9; // edx
  CAI_BaseNPC *m_pOuter; // ecx
  float m_goalTolerance; // xmm0_4
  float (__thiscall *GetDefaultNavGoalTolerance)(CAI_BaseNPC *); // edx
  float v13; // xmm0_4
  bool (__thiscall *DoFindPathToPos)(CAI_Navigator *); // eax
  int v15; // edi
  CAI_Path *v16; // ecx
  const Vector *v17; // eax
  int v18; // eax
  AI_Waypoint_t *v19; // eax
  CBaseEntity *Target; // eax
  CBaseEntity *v21; // edi
  CFmtStrN<256> v22; // [esp+Ch] [ebp-120h] BYREF
  Vector initPos; // [esp+118h] [ebp-14h] BYREF
  float tolerance; // [esp+124h] [ebp-8h]
  float outerTolerance; // [esp+128h] [ebp-4h]

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v22, pszFormat: "[Nav] %s", "Finding new path\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v2->m_szBuf);
  }
  m_pPath = this->m_pPath;
  CAI_WaypointList::RemoveAll(this: &m_pPath->m_Waypoints);
  m_pPath->m_iLastNodeReached = -1;
  v4 = false;
  switch ( CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath) )
  {
    case 1:
      Target = CAI_Path::GetTarget(this: this->m_pPath);
      v21 = Target;
      if ( Target == nullptr )
        goto LABEL_17;
      initPos = *CBaseEntity::GetAbsOrigin(this: Target);
      this->m_pOuter->TranslateNavGoal(this: this->m_pOuter, a2: v21, a3: &initPos);
      CAI_Path::ResetGoalPosition(this: this->m_pPath, goalPos: &initPos);
      goto $LN91;
    case 2:
      v7 = CAI_Path::GetTarget(this: this->m_pPath);
      if ( v7 == nullptr )
        goto LABEL_17;
      v8 = this->m_pOuter->GetEnemyLKP(this: this->m_pOuter);
      v9 = this->m_pPath;
      initPos = *v8;
      m_pOuter = this->m_pOuter;
      m_goalTolerance = v9->m_goalTolerance;
      GetDefaultNavGoalTolerance = m_pOuter->GetDefaultNavGoalTolerance;
      tolerance = m_goalTolerance;
      outerTolerance = GetDefaultNavGoalTolerance(this: m_pOuter);
      v13 = outerTolerance;
      if ( outerTolerance > tolerance )
      {
        this->m_pPath->m_goalTolerance = outerTolerance;
        tolerance = v13;
      }
      this->m_pOuter->TranslateNavGoal(this: this->m_pOuter, a2: v7, a3: &initPos);
      CAI_Path::ResetGoalPosition(this: this->m_pPath, goalPos: &initPos);
      DoFindPathToPos = this->DoFindPathToPos;
      this->m_pPath->m_goalTolerance = tolerance;
      result = DoFindPathToPos(this);
      break;
    case 3:
      GoalEnt = CAI_Component::GetGoalEnt(this);
      return CAI_Navigator::DoFindPathToPathcorner(this, pPathCorner: GoalEnt);
    case 4:
    case 6:
    case 7:
$LN91:
      v4 = this->DoFindPathToPos(this);
      goto LABEL_17;
    case 5:
      v4 = false;
      v15 = CAI_Pathfinder::NearestNodeToNPC(this: this->m_pOuter->m_pPathfinder);
      if ( v15 == -1 )
        goto LABEL_17;
      v16 = this->m_pPath;
      outerTolerance = *(float *)&this->m_pAINetwork;
      v17 = CAI_Path::ActualGoalPosition(this: v16);
      v18 = CAI_Network::NearestNodeToPoint(
              this: (CAI_Network *)LODWORD(outerTolerance),
              vPosition: v17,
              bCheckVisibility: false);
      if ( v18 == -1 )
        goto LABEL_17;
      v19 = this->m_pOuter->m_pPathfinder->FindBestPath(this: this->m_pOuter->m_pPathfinder, a2: v15, a3: v18);
      if ( v19 == nullptr )
        goto LABEL_17;
      CAI_Path::SetWaypoints(this: this->m_pPath, route: v19, fSetGoalFromLast: false);
      CAI_Path::SetLastNodeAsGoal(this: this->m_pPath, bReset: true);
      result = true;
      break;
    default:
LABEL_17:
      result = v4;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066190
// Name: private: void CAI_Navigator::ClearPath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::ClearPath(CAI_Navigator *this)
{
  CAI_BaseNPC *m_pOuter; // eax
  AI_Waypoint_t *m_pFirstWaypoint; // edi
  CAI_WaypointList *m_pClippedWaypoints; // ecx
  AI_Waypoint_t *v5; // eax
  Navigation_t m_iWPType; // eax
  CAI_Path *m_pPath; // ecx
  int iNodeID; // eax
  CAI_Network *m_pAINetwork; // ecx
  CAI_Node *v10; // eax
  float curtime; // xmm0_4

  this->OnClearPath(this);
  m_pOuter = this->m_pOuter;
  this->m_timePathRebuildMax = 0.0;
  this->m_timePathRebuildFail = 0.0;
  this->m_timePathRebuildNext = 0.0;
  this->m_timePathRebuildDelay = 0.0;
  m_pOuter->m_afMemory &= ~0x20u;
  m_pFirstWaypoint = this->m_pPath->m_Waypoints.m_pFirstWaypoint;
  if ( m_pFirstWaypoint != nullptr )
  {
    m_pClippedWaypoints = this->m_pClippedWaypoints;
    this->m_flTimeClipped = -1.0;
    CAI_WaypointList::RemoveAll(this: m_pClippedWaypoints);
    v5 = this->m_pPath->m_Waypoints.m_pFirstWaypoint;
    if ( v5 != nullptr )
    {
      m_iWPType = v5->m_iWPType;
      if ( (m_iWPType == NAV_CLIMB
         || m_iWPType == NAV_JUMP
         || ai_use_clipped_paths.m_pParent != nullptr && ai_use_clipped_paths.m_pParent->m_Value.m_nValue != 0)
        && this->GetStoppingPath(this, a2: this->m_pClippedWaypoints) )
      {
        this->m_flTimeClipped = gpGlobals->curtime;
      }
    }
    m_pPath = this->m_pPath;
    this->m_PreviousMoveActivity = m_pPath->m_activity;
    this->m_PreviousArrivalActivity = CAI_Path::GetArrivalActivity(this: m_pPath);
    do
    {
      iNodeID = m_pFirstWaypoint->iNodeID;
      if ( iNodeID != -1 )
      {
        m_pAINetwork = this->m_pAINetwork;
        if ( iNodeID < 0 || iNodeID >= m_pAINetwork->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
        }
        else
        {
          v10 = m_pAINetwork->m_pAInode[iNodeID];
          if ( v10 != nullptr )
          {
            curtime = gpGlobals->curtime;
            if ( v10->m_flNextUseTime > curtime )
              v10->m_flNextUseTime = curtime;
          }
        }
      }
      m_pFirstWaypoint = m_pFirstWaypoint->pNext;
    }
    while ( m_pFirstWaypoint != nullptr );
  }
  CAI_Path::Clear(this: this->m_pPath);
}

//------------------------------------------------------------------------------
// Address: 0x10066290
// Name: protected: virtual bool CAI_Navigator::GetStoppingPath(class CAI_WaypointList __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CAI_Navigator::GetStoppingPath@<al>(
        CAI_Navigator *this@<ecx>,
        AI_Waypoint_t *a2@<ebp>,
        CAI_WaypointList *pClippedWaypoints)
{
  AI_Waypoint_t *m_pFirstWaypoint; // esi
  Navigation_t m_iWPType; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  Navigation_t v7; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float v10; // xmm1_4
  __int128 v11; // xmm0
  float v12; // xmm5_4
  AI_Waypoint_t *pNext; // eax
  __int128 v14; // xmm0
  double v15; // st7
  float v16; // xmm4_4
  CAI_BaseNPC *v17; // eax
  float v18; // edi
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  Navigation_t v22; // ecx
  AI_Waypoint_t *v23; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  __int128 v26; // xmm6
  __int128 v27; // xmm2
  float v28; // eax
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  AI_Waypoint_t *v32; // eax
  AI_Waypoint_t *v33; // eax
  int v34; // ecx
  AI_Waypoint_t *pPrev; // eax
  _BYTE v37[72]; // [esp+1Ch] [ebp-94h] OVERLAPPED BYREF
  __int128 v38; // [esp+64h] [ebp-4Ch] BYREF
  __int64 remainder_8; // [esp+7Ch] [ebp-34h] OVERLAPPED BYREF
  float z; // [esp+84h] [ebp-2Ch]
  Vector vPosPrev; // [esp+88h] [ebp-28h]
  float yaw; // [esp+94h] [ebp-1Ch]
  float v43; // [esp+98h] [ebp-18h]
  float distToNext; // [esp+9Ch] [ebp-14h]
  AI_Waypoint_t *pSavedWaypoints; // [esp+A0h] [ebp-10h]
  AI_Waypoint_t *pLastSavedWaypoint; // [esp+A4h] [ebp-Ch] BYREF
  float distRemaining; // [esp+A8h] [ebp-8h]
  float retaddr; // [esp+B0h] [ebp+0h]

  pLastSavedWaypoint = a2;
  distRemaining = retaddr;
  LODWORD(vPosPrev.y) = this;
  CAI_WaypointList::RemoveAll(this: pClippedWaypoints);
  m_pFirstWaypoint = this->m_pPath->m_Waypoints.m_pFirstWaypoint;
  if ( m_pFirstWaypoint == nullptr )
    return 0;
  m_iWPType = m_pFirstWaypoint->m_iWPType;
  if ( m_iWPType == NAV_CLIMB || (HIBYTE(pSavedWaypoints) = 0, m_iWPType == NAV_JUMP) )
    HIBYTE(pSavedWaypoints) = 1;
  distToNext = ((double (__stdcall *)(_DWORD))this->m_pMotor->MinStoppingDist)(a1: 0);
  if ( HIBYTE(pSavedWaypoints) != 0 )
  {
    m_pOuter = this->m_pOuter;
    v7 = m_pFirstWaypoint->m_iWPType;
    x = m_pFirstWaypoint->vecLocation.x;
    y = m_pFirstWaypoint->vecLocation.y;
    v10 = (float)(y - m_pOuter->m_vecOrigin.m_Value.y) * (float)(y - m_pOuter->m_vecOrigin.m_Value.y);
    if ( v7 != NAV_GROUND )
      v10 = v10
          + (float)((float)(m_pFirstWaypoint->vecLocation.z - m_pOuter->m_vecOrigin.m_Value.z)
                  * (float)(m_pFirstWaypoint->vecLocation.z - m_pOuter->m_vecOrigin.m_Value.z));
    v11 = 0;
    *(float *)&v11 = fsqrt(
                       v10
                     + (float)((float)(m_pFirstWaypoint->vecLocation.x - m_pOuter->m_vecOrigin.m_Value.x)
                             * (float)(m_pFirstWaypoint->vecLocation.x - m_pOuter->m_vecOrigin.m_Value.x)));
    v38 = v11;
    v12 = *(float *)&v11;
    v43 = *(float *)&v11;
    if ( v7 == NAV_CLIMB )
    {
      pNext = m_pFirstWaypoint->pNext;
      if ( pNext != nullptr && pNext->m_iWPType == NAV_CLIMB )
      {
        v14 = 0;
        *(float *)&v14 = fsqrt(
                           (float)((float)((float)(pNext->vecLocation.y - y) * (float)(pNext->vecLocation.y - y))
                                 + (float)((float)(pNext->vecLocation.z - m_pFirstWaypoint->vecLocation.z)
                                         * (float)(pNext->vecLocation.z - m_pFirstWaypoint->vecLocation.z)))
                         + (float)((float)(pNext->vecLocation.x - x) * (float)(pNext->vecLocation.x - x)));
        v38 = v14;
        v43 = *(float *)&v14 + v12;
      }
      v15 = NAI_Hull::Width(id: m_pOuter->m_eHull);
      v43 = v15 + v15 + v43;
      v12 = v43;
    }
    v16 = distToNext;
    if ( v12 > distToNext )
    {
      v16 = v12;
      distToNext = v12;
    }
  }
  else
  {
    v16 = distToNext;
    if ( distToNext <= 0.1 )
      return 0;
  }
  v17 = this->m_pOuter;
  remainder_8 = *(_QWORD *)&v17->m_vecOrigin.m_Value.x;
  v18 = 0.0;
  z = v17->m_vecOrigin.m_Value.z;
  yaw = 0.0;
  v43 = 0.0;
  if ( v16 > 0.01 )
  {
    v19 = z;
    v20 = *((float *)&remainder_8 + 1);
    v21 = *(float *)&remainder_8;
    do
    {
      if ( m_pFirstWaypoint == nullptr )
        break;
      v22 = m_pFirstWaypoint->m_iWPType;
      if ( (v22 == NAV_CLIMB || v22 == NAV_JUMP) && HIBYTE(pSavedWaypoints) == 0 )
        break;
      if ( v22 == NAV_CLIMB )
      {
        v23 = m_pFirstWaypoint->pNext;
        if ( v23 != nullptr && v23->m_iWPType == NAV_CLIMB )
          continue;
      }
      HIBYTE(pSavedWaypoints) = 0;
      v24 = m_pFirstWaypoint->vecLocation.x - v21;
      v25 = m_pFirstWaypoint->vecLocation.y - v20;
      if ( v22 != NAV_GROUND )
      {
        v27 = 0;
        *(float *)&v27 = fsqrt(
                           (float)((float)(v25 * v25)
                                 + (float)((float)(m_pFirstWaypoint->vecLocation.z - v19)
                                         * (float)(m_pFirstWaypoint->vecLocation.z - v19)))
                         + (float)(v24 * v24));
        *(_OWORD *)&v37[56] = v27;
      }
      else
      {
        v26 = 0;
        *(float *)&v26 = fsqrt((float)(v25 * v25) + (float)(v24 * v24));
        *(_OWORD *)&v37[56] = v26;
      }
      vPosPrev.z = *(float *)&v37[56];
      if ( v16 + 0.01 < *(float *)&v37[56] )
      {
        *(_QWORD *)((char *)&v38 + 4) = __PAIR64__(LODWORD(v25), LODWORD(v24));
        *((float *)&v38 + 3) = m_pFirstWaypoint->vecLocation.z - v19;
        VectorNormalize(vec: (Vector *)((char *)&v38 + 4));
        vPosPrev.x = UTIL_VecToYaw(vec: (const Vector *)((char *)&v38 + 4));
        *((float *)&v38 + 1) = (float)(*((float *)&v38 + 1) * distToNext) + *(float *)&remainder_8;
        *((float *)&v38 + 2) = (float)(*((float *)&v38 + 2) * distToNext) + *((float *)&remainder_8 + 1);
        *((float *)&v38 + 3) = (float)(*((float *)&v38 + 3) * distToNext) + z;
        memset(dst: (int)v37, value: nullptr, count: 0x38u);
        if ( CAI_MoveProbe::MoveLimit(
               this: *(CAI_MoveProbe **)(LODWORD(vPosPrev.y) + 24),
               a2: (int)&pLastSavedWaypoint,
               navType: m_pFirstWaypoint->m_iWPType,
               vecStart: (const Vector *)&remainder_8,
               vecEnd: (const Vector *)((char *)&v38 + 4),
               collisionMask: *(_DWORD *)(*(_DWORD *)(LODWORD(vPosPrev.y) + 4) + 3712),
               pTarget: nullptr,
               pctToCheckStandPositions: 100.0,
               flags: 1,
               pTrace: (AIMoveTrace_t *)v37) )
        {
          v32 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
          v33 = v32 != nullptr
              ? AI_Waypoint_t::AI_Waypoint_t(
                  this: v32,
                  initPosition: (const Vector *)&v37[4],
                  initYaw: vPosPrev.x,
                  initNavType: m_pFirstWaypoint->m_iWPType,
                  initWaypointFlags: 8,
                  initNodeID: 0)
              : nullptr;
          v18 = v43;
          if ( v43 == 0.0 )
          {
            yaw = *(float *)&v33;
          }
          else
          {
            v34 = *(_DWORD *)(LODWORD(v43) + 40);
            if ( v34 != 0 )
              *(_DWORD *)(v34 + 44) = 0;
            *(_DWORD *)(LODWORD(v18) + 40) = v33;
            if ( v33 != nullptr )
            {
              pPrev = v33->pPrev;
              if ( pPrev != nullptr )
                pPrev->pNext = nullptr;
              *(float *)(*(_DWORD *)(LODWORD(v18) + 40) + 44) = v18;
            }
          }
        }
        else
        {
          v18 = v43;
        }
        v16 = 0.0;
        v19 = z;
        v20 = *((float *)&remainder_8 + 1);
        v21 = *(float *)&remainder_8;
      }
      else
      {
        v28 = COERCE_FLOAT(CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u));
        if ( v28 == 0.0 )
        {
          v28 = 0.0;
        }
        else
        {
          *(_DWORD *)(LODWORD(v28) + 24) = -1;
          *(_DWORD *)(LODWORD(v28) + 28) = -1;
          *(_QWORD *)LODWORD(v28) = *(_QWORD *)&m_pFirstWaypoint->vecLocation.x;
          *(_QWORD *)(LODWORD(v28) + 8) = *(_QWORD *)&m_pFirstWaypoint->vecLocation.z;
          *(_QWORD *)(LODWORD(v28) + 16) = *(_QWORD *)&m_pFirstWaypoint->iNodeID;
          *(_QWORD *)(LODWORD(v28) + 24) = *(_QWORD *)&m_pFirstWaypoint->hPathCorner.m_Index;
          *(_QWORD *)(LODWORD(v28) + 32) = *(_QWORD *)&m_pFirstWaypoint->m_fWaypointFlags;
          *(_QWORD *)(LODWORD(v28) + 40) = *(_QWORD *)&m_pFirstWaypoint->pNext;
          *(_DWORD *)(LODWORD(v28) + 20) = -1082130432;
          *(_DWORD *)(LODWORD(v28) + 44) = 0;
          *(_DWORD *)(LODWORD(v28) + 40) = 0;
        }
        v29 = *(_DWORD *)(LODWORD(v28) + 32);
        if ( (v29 & 2) != 0 )
        {
          *(_DWORD *)(LODWORD(v28) + 32) = v29 & 0xFFFFFFFD;
          *(_DWORD *)(LODWORD(v28) + 24) = -1;
        }
        *(_DWORD *)(LODWORD(v28) + 32) &= 0xFFFFFFF3;
        *(_DWORD *)(LODWORD(v28) + 16) = -1;
        if ( v18 == 0.0 )
        {
          yaw = v28;
        }
        else
        {
          v30 = *(_DWORD *)(LODWORD(v18) + 40);
          if ( v30 != 0 )
            *(_DWORD *)(v30 + 44) = 0;
          *(float *)(LODWORD(v18) + 40) = v28;
          v31 = *(_DWORD *)(LODWORD(v28) + 44);
          if ( v31 != 0 )
            *(_DWORD *)(v31 + 40) = 0;
          *(float *)(*(_DWORD *)(LODWORD(v18) + 40) + 44) = v18;
        }
        v21 = m_pFirstWaypoint->vecLocation.x;
        v16 = distToNext - vPosPrev.z;
        *(float *)&remainder_8 = m_pFirstWaypoint->vecLocation.x;
        v20 = m_pFirstWaypoint->vecLocation.y;
        *((float *)&remainder_8 + 1) = v20;
        v19 = m_pFirstWaypoint->vecLocation.z;
        v18 = v28;
        z = v19;
        m_pFirstWaypoint = m_pFirstWaypoint->pNext;
        v43 = v28;
      }
      distToNext = v16;
    }
    while ( v16 > 0.01 );
    if ( yaw != 0.0 )
    {
      CAI_WaypointList::Set(this: (CChoreoChannel *)pClippedWaypoints, actor: (CChoreoActor *)LODWORD(yaw));
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10066770
// Name: public: void CAI_Navigator::DrawDebugRouteOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::DrawDebugRouteOverlay(CAI_Navigator *this)
{
  AI_Waypoint_t *m_pFirstWaypoint; // esi
  int m_fWaypointFlags; // eax
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  AI_Waypoint_t *pNext; // edx
  int v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  Vector *v15; // eax
  CAI_BaseNPC *m_pOuter; // esi
  double v17; // st7
  CFmtStrN<256> *v18; // eax
  CFmtStrN<256> v19; // [esp+10h] [ebp-154h] BYREF
  Vector v20; // [esp+11Ch] [ebp-48h] BYREF
  Vector maxs; // [esp+128h] [ebp-3Ch] BYREF
  Vector mins; // [esp+134h] [ebp-30h] BYREF
  Vector target; // [esp+140h] [ebp-24h] BYREF
  Vector vecGoalDir; // [esp+14Ch] [ebp-18h] BYREF
  Vector vecGoalPos; // [esp+158h] [ebp-Ch] BYREF
  int savedregs; // [esp+164h] [ebp+0h] BYREF

  m_pFirstWaypoint = this->m_pPath->m_Waypoints.m_pFirstWaypoint;
  if ( m_pFirstWaypoint != nullptr )
  {
    m_fWaypointFlags = m_pFirstWaypoint->m_fWaypointFlags;
    v4 = 200.0;
    if ( m_pFirstWaypoint->m_iWPType == NAV_JUMP )
    {
      v5 = 255.0;
      v4 = 0.0;
      v6 = 0.0;
    }
    else if ( (m_fWaypointFlags & 8) != 0 )
    {
      v6 = 255.0;
      v5 = 200.0;
      v4 = 0.0;
    }
    else
    {
      if ( (m_fWaypointFlags & 1) != 0 )
      {
        v6 = 255.0;
      }
      else if ( (m_fWaypointFlags & 4) != 0 )
      {
        v6 = 255.0;
        v4 = 0.0;
      }
      else
      {
        v4 = 255.0;
        v6 = 150.0;
      }
      v5 = 0.0;
    }
    NDebugOverlay::Line(
      origin: &this->m_pOuter->m_vecOrigin.m_Value,
      target: &m_pFirstWaypoint->vecLocation,
      r: (int)v5,
      g: (int)v4,
      b: (int)v6,
      noDepthTest: true,
      duration: 0.0);
    while ( 2 )
    {
      v7 = 90.0;
      switch ( m_pFirstWaypoint->m_iWPType )
      {
        case NAV_GROUND:
          v8 = 0.0;
          v7 = 255.0;
          goto LABEL_20;
        case NAV_JUMP:
          goto $LN60;
        case NAV_FLY:
          v9 = 255.0;
          v8 = 90.0;
          goto LABEL_21;
        case NAV_CLIMB:
          v8 = 90.0;
          v7 = 255.0;
          goto LABEL_20;
        case NAV_CRAWL:
          v8 = 255.0;
          v9 = 0.0;
          v7 = 255.0;
          goto LABEL_21;
        default:
          v7 = 0.0;
$LN60:
          v8 = 255.0;
LABEL_20:
          v9 = v7;
LABEL_21:
          vecGoalDir.x = 3.0;
          vecGoalDir.y = 3.0;
          vecGoalDir.z = 3.0;
          vecGoalPos.x = -3.0;
          vecGoalPos.y = -3.0;
          vecGoalPos.z = -3.0;
          NDebugOverlay::Box(
            origin: &m_pFirstWaypoint->vecLocation,
            mins: &vecGoalPos,
            maxs: &vecGoalDir,
            r: (int)v8,
            g: (int)v7,
            b: (int)v9,
            a: 1,
            flDuration: 0.0);
          if ( (m_pFirstWaypoint->m_fWaypointFlags & 0x40) != 0 )
          {
            maxs.x = 6.0;
            maxs.y = 6.0;
            maxs.z = 6.0;
            mins.x = -6.0;
            mins.y = -6.0;
            mins.z = -6.0;
            NDebugOverlay::Box(
              origin: &m_pFirstWaypoint->vecLocation,
              &mins,
              &maxs,
              r: 255,
              g: 0,
              b: 0,
              a: 1,
              flDuration: 0.0);
          }
          if ( (m_pFirstWaypoint->m_fWaypointFlags & 0x20) != 0 )
          {
            v20.x = 9.0;
            v20.y = 9.0;
            v20.z = 9.0;
            target.x = -9.0;
            target.y = -9.0;
            target.z = -9.0;
            NDebugOverlay::Box(
              origin: &m_pFirstWaypoint->vecLocation,
              mins: &target,
              maxs: &v20,
              r: 255,
              g: 0,
              b: 255,
              a: 1,
              flDuration: 0.0);
          }
          pNext = m_pFirstWaypoint->pNext;
          if ( pNext != nullptr )
          {
            v11 = pNext->m_fWaypointFlags;
            if ( pNext->m_iWPType == NAV_JUMP )
            {
              v12 = 255.0;
              v13 = 0.0;
              v14 = 0.0;
            }
            else if ( (v11 & 8) != 0 )
            {
              v12 = 200.0;
              v14 = 255.0;
              v13 = 0.0;
            }
            else
            {
              if ( (v11 & 1) != 0 )
              {
                v13 = 200.0;
                v14 = 255.0;
              }
              else if ( (v11 & 4) != 0 )
              {
                v14 = 255.0;
                v13 = 0.0;
              }
              else
              {
                v13 = 255.0;
                v14 = 150.0;
              }
              v12 = 0.0;
            }
            NDebugOverlay::Line(
              origin: &m_pFirstWaypoint->vecLocation,
              target: &pNext->vecLocation,
              r: (int)v12,
              g: (int)v13,
              b: (int)v14,
              noDepthTest: true,
              duration: 0.0);
          }
          m_pFirstWaypoint = m_pFirstWaypoint->pNext;
          if ( m_pFirstWaypoint == nullptr )
            break;
          continue;
      }
      break;
    }
  }
  if ( CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath) != 0 )
  {
    v15 = CAI_Path::ActualGoalPosition(this: this->m_pPath);
    m_pOuter = this->m_pOuter;
    vecGoalPos = *v15;
    if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pOuter, a2: (int)&savedregs);
    CAI_Path::GetGoalDirection(this: this->m_pPath, result: &vecGoalDir, startPos: &m_pOuter->m_vecAbsOrigin);
    target.y = vecGoalPos.y + (float)(vecGoalDir.y * 32.0);
    target.z = vecGoalPos.z + (float)(vecGoalDir.z * 32.0);
    target.x = vecGoalPos.x + (float)(vecGoalDir.x * 32.0);
    NDebugOverlay::Line(origin: &vecGoalPos, &target, r: 0, g: 0, b: 255, noDepthTest: true, duration: 2.0);
    v17 = UTIL_VecToYaw(vec: &vecGoalDir);
    v18 = CFmtStrN<256>::CFmtStrN<256>(this: &v19, pszFormat: "yaw: %f", v17);
    NDebugOverlay::Text(origin: &vecGoalPos, text: v18->m_szBuf, bViewCheck: true, duration: 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066D10
// Name: public: bool CAI_Navigator::SetVectorGoal(class Vector const __near &,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Navigator::SetVectorGoal(
        CAI_Navigator *this,
        const Vector *dir,
        float targetDist,
        float minDist,
        bool fShouldDeflect)
{
  CFmtStrN<256> *v6; // eax
  bool (__thiscall *SetGoal)(CAI_Navigator *, const AI_NavGoal_t *, unsigned int); // edx
  CFmtStrN<256> v9; // [esp+10h] [ebp-148h] BYREF
  Vector v10; // [esp+11Ch] [ebp-3Ch] BYREF
  int v11; // [esp+128h] [ebp-30h] BYREF
  __int64 v12; // [esp+12Ch] [ebp-2Ch]
  float z; // [esp+134h] [ebp-24h]
  int v14; // [esp+138h] [ebp-20h]
  int v15; // [esp+13Ch] [ebp-1Ch]
  int v16; // [esp+140h] [ebp-18h]
  int v17; // [esp+144h] [ebp-14h]
  int v18; // [esp+148h] [ebp-10h]
  int v19; // [esp+14Ch] [ebp-Ch]
  int v20; // [esp+150h] [ebp-8h]
  CBaseEntity *v21; // [esp+154h] [ebp-4h]

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "[Nav] %s", "Set vector goal\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v6->m_szBuf);
  }
  if ( CAI_Navigator::FindVectorGoal(this, pResult: &v10, dir, targetDist, minDist, fShouldDeflect) == 0 )
    return false;
  v14 = -1;
  v15 = -1;
  v16 = -1;
  v17 = -1;
  z = v10.z;
  SetGoal = this->SetGoal;
  v21 = AIN_DEF_TARGET_31;
  v12 = *(_QWORD *)&v10.x;
  v11 = 4;
  v18 = -1082130432;
  v19 = -1082130432;
  v20 = 0;
  return SetGoal(this, a2: (const AI_NavGoal_t *)&v11, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10066DF0
// Name: public: bool CAI_Navigator::SetVectorGoalFromTarget(class Vector const __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CAI_Navigator::SetVectorGoalFromTarget@<al>(
        CAI_Navigator *this@<ecx>,
        float a2@<ebp>,
        const Vector *goalPos,
        __int64 minDist)
{
  Navigation_t m_navType; // edx
  CAI_BaseNPC *m_pOuter; // eax
  float targetDist; // xmm0_4
  float v8; // xmm1_4
  float y; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  Vector v14; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector vDir; // [esp+38h] [ebp-10h]
  float retaddr; // [esp+48h] [ebp+0h]

  vDir.y = a2;
  vDir.z = retaddr;
  m_navType = this->m_navType;
  v14.z = goalPos->z;
  m_pOuter = this->m_pOuter;
  *(_QWORD *)&v14.x = *(_QWORD *)&goalPos->x;
  if ( m_navType == NAV_GROUND || m_navType == NAV_CRAWL )
  {
    v8 = goalPos->x - m_pOuter->m_vecOrigin.m_Value.x;
    y = goalPos->y;
    v10 = 0.0;
    v14.x = v8;
    v11 = y - m_pOuter->m_vecOrigin.m_Value.y;
    v14.y = v11;
    v14.z = 0.0;
    v12 = fsqrt((float)(v8 * v8) + (float)(v11 * v11));
    if ( v12 == 0.0 )
    {
      v14.x = 0.0;
    }
    else
    {
      v14.x = (float)(1.0 / v12) * v8;
      v10 = (float)(1.0 / v12) * v11;
    }
    v14.y = v10;
    targetDist = v12;
  }
  else
  {
    v14.x = goalPos->x - m_pOuter->m_vecOrigin.m_Value.x;
    v14.y = goalPos->y - m_pOuter->m_vecOrigin.m_Value.y;
    v14.z = goalPos->z - m_pOuter->m_vecOrigin.m_Value.z;
    vDir.x = VectorNormalize(vec: &v14);
    targetDist = vDir.x;
  }
  return CAI_Navigator::SetVectorGoal(
           this,
           dir: &v14,
           targetDist,
           minDist: *(float *)&minDist,
           fShouldDeflect: SBYTE4(minDist));
}

//------------------------------------------------------------------------------
// Address: 0x10066F30
// Name: public: bool CAI_Navigator::ClearGoal(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::ClearGoal(CAI_Navigator *this)
{
  CFmtStrN<256> *v2; // eax
  CFmtStrN<256> v4; // [esp+4h] [ebp-10Ch] BYREF

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "[Nav] %s", "CAI_Navigator::ClearGoal()\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v2->m_szBuf);
  }
  CAI_Navigator::ClearPath(this);
  this->OnNewGoal(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10066F90
// Name: protected: virtual enum AIMoveResult_t CAI_Navigator::MoveCrawl(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __usercall CAI_Navigator::MoveCrawl@<eax>(CAI_Navigator *this@<ecx>, int a2@<ebp>)
{
  bool (__thiscall *MoveUpdateWaypoint)(CAI_Navigator *, AIMoveResult_t *); // edx
  CAI_BaseNPC *m_pOuter; // edi
  float v6; // ecx
  unsigned int v7; // edx
  CAI_BaseNPC *v8; // ecx
  __int64 v9; // xmm0_8
  void (__thiscall *SetActivity)(CAI_BaseNPC *, Activity); // edx
  CAI_BaseNPC *v11; // ecx
  const char *pszValue; // edi
  const char *SequenceName; // eax
  CFmtStrN<256> *v14; // eax
  const Vector *AbsOrigin; // eax
  __int128 v16; // xmm0
  CFmtStrN<256> v17; // [esp-118h] [ebp-1F0h] BYREF
  _BYTE v18[12]; // [esp-Ch] [ebp-E4h] BYREF
  __int128 move_172; // [esp+ACh] [ebp-2Ch] OVERLAPPED
  Vector vStart; // [esp+BCh] [ebp-1Ch]
  Activity preMoveSpeed; // [esp+C8h] [ebp-10h] BYREF
  int nPreMoveSequence; // [esp+CCh] [ebp-Ch] BYREF
  Activity preMoveActivity; // [esp+D0h] [ebp-8h]
  Activity retaddr; // [esp+D8h] [ebp+0h]

  nPreMoveSequence = a2;
  preMoveActivity = retaddr;
  if ( CAI_Navigator::PreMove(this) == 0 )
    return -4;
  MoveUpdateWaypoint = this->MoveUpdateWaypoint;
  preMoveSpeed = -4;
  if ( !MoveUpdateWaypoint(this, a2: (AIMoveResult_t *)&preMoveSpeed) )
  {
    vStart.x = ((double (__thiscall *)(CAI_BaseNPC *, Activity))this->m_pOuter->GetIdealSpeed)(
                 a1: this->m_pOuter,
                 a2: preMoveSpeed);
    m_pOuter = this->m_pOuter;
    v6 = *(float *)&m_pOuter->m_nSequence.m_Value;
    v7 = (unsigned int)m_pOuter->m_iEFlags >> 11;
    LODWORD(vStart.z) = m_pOuter->m_Activity;
    vStart.y = v6;
    if ( (v7 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pOuter, a2: (int)&nPreMoveSequence);
    v8 = this->m_pOuter;
    v9 = *(_QWORD *)&m_pOuter->m_vecAbsOrigin.x;
    SetActivity = v8->SetActivity;
    HIDWORD(move_172) = LODWORD(m_pOuter->m_vecAbsOrigin.z);
    preMoveSpeed = this->m_pPath->m_activity;
    *(_QWORD *)((char *)&move_172 + 4) = v9;
    SetActivity(this: v8, a2: preMoveSpeed);
    if ( this->m_bValidateActivitySpeed
      && ((double (__thiscall *)(CAI_BaseNPC *))this->m_pOuter->GetIdealSpeed)(a1: this->m_pOuter) <= 0.0 )
    {
      v11 = this->m_pOuter;
      if ( v11->m_Activity == ACT_TRANSITION )
        return 0;
      pszValue = v11->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      SequenceName = CBaseAnimating::GetSequenceName(this: v11, iSequence: v11->m_nSequence.m_Value);
      DevMsg(a1: "%s moving with speed <= 0 (%s)\n", pszValue, SequenceName);
    }
    if ( this->m_navType != NAV_CRAWL
      && ai_debug_nav.m_pParent != nullptr
      && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v17, pszFormat: "[Nav] %s", "Crawl start\n");
      DevMsg(pAI: this->m_pOuter, pszFormat: v14->m_szBuf);
    }
    LODWORD(vStart.z) = 180;
    vStart.y = 0.0;
    LODWORD(vStart.x) = v18;
    this->m_navType = NAV_CRAWL;
    memset(dst: SLODWORD(vStart.x), value: (unsigned __int8 *)LODWORD(vStart.y), count: LODWORD(vStart.z));
    this->MoveCalcBaseGoal(this, a2: (AILocalMoveGoal_t *)v18);
    preMoveSpeed = this->MoveEnact(this, a2: (const AILocalMoveGoal_t *)v18);
    if ( preMoveSpeed == ACT_RESET && vStart.x < 0.01 )
    {
      AbsOrigin = CAI_Component::GetAbsOrigin(this, a2: (int)&nPreMoveSequence);
      v16 = 0;
      *(float *)&v16 = fsqrt(
                         (float)((float)((float)(AbsOrigin->y - *((float *)&move_172 + 2))
                                       * (float)(AbsOrigin->y - *((float *)&move_172 + 2)))
                               + (float)((float)(AbsOrigin->z - *((float *)&move_172 + 3))
                                       * (float)(AbsOrigin->z - *((float *)&move_172 + 3))))
                       + (float)((float)(AbsOrigin->x - *((float *)&move_172 + 1))
                               * (float)(AbsOrigin->x - *((float *)&move_172 + 1))));
      move_172 = v16;
      if ( *(float *)&v16 < 0.01 )
      {
        CBaseAnimating::SetSequence(this: this->m_pOuter, nSequence: SLODWORD(vStart.y));
        this->m_pOuter->SetActivity(this: this->m_pOuter, a2: SLODWORD(vStart.z));
      }
    }
  }
  return preMoveSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x100671D0
// Name: private: virtual bool CAI_Navigator::OnFailedSteer(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CAI_Navigator::OnFailedSteer@<al>(
        CAI_Navigator *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  double v9; // st7
  float curExpectedDist; // xmm0_4
  float v11; // ecx
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // edi
  int v15; // edi
  AIMoveTrace_t moveTrace; // [esp+24h] [ebp-54h] BYREF
  Vector testLoc; // [esp+5Ch] [ebp-1Ch] BYREF
  Vector vDeflection; // [esp+68h] [ebp-10h] BYREF
  float halfHull; // [esp+74h] [ebp-4h]
  int savedregs; // [esp+78h] [ebp+0h] BYREF
  float distToWaypoint; // [esp+80h] [ebp+8h]

  if ( (*(unsigned __int8 (__stdcall **)(AILocalMoveGoal_t *, _DWORD, AIMoveResult_t *, int, int, AIMoveResult_t, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, CBaseEntity *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(*((_DWORD *)this - 1) + 2284) + 12))(
         a1: pMoveGoal,
         a2: LODWORD(distClear),
         a3: pResult,
         a4: a3,
         a5: a2,
         a6: moveTrace.fStatus,
         a7: LODWORD(moveTrace.vEndPosition.x),
         a8: LODWORD(moveTrace.vEndPosition.y),
         a9: LODWORD(moveTrace.vEndPosition.z),
         a10: LODWORD(moveTrace.vHitNormal.x),
         a11: LODWORD(moveTrace.vHitNormal.y),
         a12: LODWORD(moveTrace.vHitNormal.z),
         a13: moveTrace.pObstruction,
         a14: LODWORD(moveTrace.flTotalDist),
         a15: LODWORD(moveTrace.flDistObstructed),
         a16: LODWORD(moveTrace.vJumpVelocity.x),
         a17: LODWORD(moveTrace.vJumpVelocity.y),
         a18: LODWORD(moveTrace.vJumpVelocity.z),
         a19: LODWORD(moveTrace.flStepUpDistance),
         a20: LODWORD(testLoc.x),
         a21: LODWORD(testLoc.y),
         a22: LODWORD(testLoc.z),
         a23: LODWORD(vDeflection.x),
         a24: LODWORD(vDeflection.y)) != 0 )
    return 1;
  if ( (pMoveGoal->flags & 1) != 0 )
  {
    if ( distClear >= CAI_Navigator::GetPathDistToGoal(this: (CAI_Navigator *)((char *)this - 8)) )
    {
LABEL_22:
      *pResult = AIMR_OK;
      return 1;
    }
    if ( distClear > (float)(pMoveGoal->maxDist - *(float *)&this->m_pLocalNavigator->m_pOuter) )
    {
      if ( pMoveGoal->maxDist > distClear )
        pMoveGoal->maxDist = distClear;
      if ( distClear < 0.125 )
        (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 52))(a1: (char *)this - 8);
      pMoveGoal->flags |= 2u;
      *pResult = AIMR_OK;
      return 1;
    }
  }
  if ( (pMoveGoal->flags & 4) == 0 )
  {
    distToWaypoint = CAI_Navigator::GetPathDistToCurWaypoint(this: (CAI_Navigator *)((char *)this - 8));
    v9 = NAI_Hull::Width(id: *(_DWORD *)(*((_DWORD *)this - 1) + 1672)) * 0.5;
    halfHull = v9;
    if ( v9 > distToWaypoint && distClear > (float)(halfHull + distToWaypoint) )
    {
      *pResult = AIMR_OK;
      return 1;
    }
  }
  if ( pMoveGoal->directTrace.fStatus == AIMR_BLOCKED_NPC
    && (vec3_origin.x != pMoveGoal->directTrace.vHitNormal.x
     || vec3_origin.y != pMoveGoal->directTrace.vHitNormal.y
     || vec3_origin.z != pMoveGoal->directTrace.vHitNormal.z) )
  {
    memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
    CAI_Navigator::CalculateDeflection(
      start: (const Vector *)(*((_DWORD *)this - 1) + 700),
      dir: &pMoveGoal->dir,
      normal: &pMoveGoal->directTrace.vHitNormal,
      pResult: &vDeflection);
    if ( (float)((float)(pMoveGoal->dir.y * vDeflection.y) + (float)(vDeflection.x * pMoveGoal->dir.x)) > 0.7 )
    {
      curExpectedDist = pMoveGoal->curExpectedDist;
      v11 = *((float *)this - 1);
      v12 = vDeflection.z * curExpectedDist;
      testLoc.x = *(float *)(LODWORD(v11) + 700) + (float)(vDeflection.x * curExpectedDist);
      testLoc.y = *(float *)(LODWORD(v11) + 704) + (float)(vDeflection.y * curExpectedDist);
      v13 = *(float *)(LODWORD(v11) + 708);
      testLoc.y = v11;
      testLoc.z = v13 + v12;
      CAI_MoveProbe::MoveLimit(
        this: *(CAI_MoveProbe **)&this->m_fNavComplete,
        a2: (int)&savedregs,
        navType: (Navigation_t)this->m_pOuter,
        vecStart: (const Vector *)(LODWORD(v11) + 700),
        vecEnd: &testLoc,
        collisionMask: *(_DWORD *)(LODWORD(v11) + 3712),
        pTarget: nullptr,
        pctToCheckStandPositions: 100.0,
        flags: SLOBYTE(testLoc.z),
        pTrace: &moveTrace);
      if ( moveTrace.fStatus == AIMR_OK )
      {
        pMoveGoal->dir = vDeflection;
        pMoveGoal->maxDist = pMoveGoal->curExpectedDist;
        goto LABEL_22;
      }
    }
  }
  if ( vec3_invalid.x == *(float *)&this->m_hBigStepGroundEnt.m_Index
    && vec3_invalid.y == *(float *)&this->m_hLastBlockingEnt.m_Index
    && vec3_invalid.z == this->m_vPosBeginFailedSteer.x )
  {
    goto LABEL_33;
  }
  v14 = *((_DWORD *)this - 1);
  if ( (*(_DWORD *)(v14 + 196) & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: *((CBaseEntity **)this - 1), a2: (int)&savedregs);
  if ( (float)((float)((float)((float)(*(float *)&this->m_hLastBlockingEnt.m_Index - *(float *)(v14 + 464))
                             * (float)(*(float *)&this->m_hLastBlockingEnt.m_Index - *(float *)(v14 + 464)))
                     + (float)((float)(*(float *)&this->m_hBigStepGroundEnt.m_Index - *(float *)(v14 + 460))
                             * (float)(*(float *)&this->m_hBigStepGroundEnt.m_Index - *(float *)(v14 + 460))))
             + (float)((float)(this->m_vPosBeginFailedSteer.x - *(float *)(v14 + 468))
                     * (float)(this->m_vPosBeginFailedSteer.x - *(float *)(v14 + 468)))) > 144.0 )
  {
LABEL_33:
    v15 = *((_DWORD *)this - 1);
    if ( (*(_DWORD *)(v15 + 196) & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: *((CBaseEntity **)this - 1), a2: (int)&savedregs);
    this->m_hBigStepGroundEnt.m_Index = *(unsigned int *)(v15 + 460);
    this->m_hLastBlockingEnt.m_Index = *(unsigned int *)(v15 + 464);
    this->m_vPosBeginFailedSteer.x = *(float *)(v15 + 468);
    this->m_vPosBeginFailedSteer.y = gpGlobals->curtime;
  }
  else if ( this->m_pOuter == nullptr
         && (float)(gpGlobals->curtime - this->m_vPosBeginFailedSteer.y) > 1.0
         && *(float *)(*((_DWORD *)this - 1) + 852) > 12.0 )
  {
    *pResult = AIMR_ILLEGAL;
    return 1;
  }
  if ( (pMoveGoal->flags & 0x10) != 0
    || pMoveGoal->maxDist <= distClear
    || CAI_Navigator::PrependLocalAvoidance(
         this: (CAI_Navigator *)((char *)this - 8),
         distObstacle: distClear,
         directTrace: &pMoveGoal->directTrace) == 0 )
  {
    return 0;
  }
  *pResult = AIMR_CHANGE_TYPE;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100675C0
// Name: private: virtual bool CAI_Navigator::OnFailedLocalNavigation(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::OnFailedLocalNavigation(
        CAI_Navigator *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  if ( (*(unsigned __int8 (__stdcall **)(AILocalMoveGoal_t *, _DWORD, AIMoveResult_t *))(*(_DWORD *)(*((_DWORD *)this - 1) + 2284)
                                                                                       + 16))(
         a1: pMoveGoal,
         a2: LODWORD(distClear),
         a3: pResult) != 0 )
    return 1;
  if ( CAI_Navigator::DelayNavigationFailure(this: (CAI_Navigator *)((char *)this - 8), trace: &pMoveGoal->directTrace) )
  {
    *pResult = AIMR_OK;
    pMoveGoal->flags |= 2u;
    pMoveGoal->maxDist = distClear;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10067630
// Name: protected: virtual enum AIMoveResult_t CAI_Navigator::MoveNormal(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __usercall CAI_Navigator::MoveNormal@<eax>(CAI_Navigator *this@<ecx>, Activity a2@<ebp>)
{
  bool (__thiscall *MoveUpdateWaypoint)(CAI_Navigator *, AIMoveResult_t *); // edx
  CAI_BaseNPC *m_pOuter; // edi
  float v6; // ecx
  unsigned int v7; // edx
  CAI_BaseNPC *v8; // ecx
  __int64 v9; // xmm0_8
  void (__thiscall *SetActivity)(CAI_BaseNPC *, Activity); // edx
  CAI_BaseNPC *v11; // eax
  const char *pszValue; // edi
  const char *SequenceName; // eax
  const Vector *AbsOrigin; // eax
  __int128 v15; // xmm0
  CAI_BaseNPC *v16; // edi
  const char *ActivityName; // eax
  int z_low; // ecx
  const char *v19; // eax
  CFmtStrN<256> *v20; // eax
  CFmtStrN<256> *v21; // eax
  CFmtStrN<256> v22; // [esp-224h] [ebp-2FCh] BYREF
  CFmtStrN<256> v23; // [esp-118h] [ebp-1F0h] BYREF
  _BYTE v24[200]; // [esp-Ch] [ebp-E4h] OVERLAPPED BYREF
  Vector vStart; // [esp+BCh] [ebp-1Ch]
  Activity preMoveSpeed; // [esp+C8h] [ebp-10h] BYREF
  Activity preMoveActivity; // [esp+CCh] [ebp-Ch] BYREF
  int nPreMoveSequence; // [esp+D0h] [ebp-8h]
  int retaddr; // [esp+D8h] [ebp+0h]

  preMoveActivity = a2;
  nPreMoveSequence = retaddr;
  if ( CAI_Navigator::PreMove(this) == 0 )
    return -4;
  MoveUpdateWaypoint = this->MoveUpdateWaypoint;
  preMoveSpeed = -4;
  if ( !MoveUpdateWaypoint(this, a2: (AIMoveResult_t *)&preMoveSpeed) )
  {
    vStart.x = ((double (__thiscall *)(CAI_BaseNPC *, Activity))this->m_pOuter->GetIdealSpeed)(
                 a1: this->m_pOuter,
                 a2: preMoveSpeed);
    m_pOuter = this->m_pOuter;
    v6 = *(float *)&m_pOuter->m_nSequence.m_Value;
    v7 = (unsigned int)m_pOuter->m_iEFlags >> 11;
    LODWORD(vStart.y) = m_pOuter->m_Activity;
    vStart.z = v6;
    if ( (v7 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pOuter, a2: (int)&preMoveActivity);
    v8 = this->m_pOuter;
    v9 = *(_QWORD *)&m_pOuter->m_vecAbsOrigin.x;
    SetActivity = v8->SetActivity;
    *(float *)&v24[196] = m_pOuter->m_vecAbsOrigin.z;
    preMoveSpeed = this->m_pPath->m_activity;
    *(_QWORD *)&v24[188] = v9;
    SetActivity(this: v8, a2: preMoveSpeed);
    if ( this->m_bValidateActivitySpeed
      && ((double (__thiscall *)(CAI_BaseNPC *))this->m_pOuter->GetIdealSpeed)(a1: this->m_pOuter) <= 0.0 )
    {
      v11 = this->m_pOuter;
      if ( v11->m_Activity == ACT_TRANSITION )
        return 0;
      pszValue = v11->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      SequenceName = CBaseAnimating::GetSequenceName(
                       this: this->m_pOuter,
                       iSequence: this->m_pOuter->m_nSequence.m_Value);
      DevMsg(a1: "%s moving with speed <= 0 (%s)\n", pszValue, SequenceName);
    }
    memset(dst: (int)v24, value: nullptr, count: 0xB4u);
    this->MoveCalcBaseGoal(this, a2: (AILocalMoveGoal_t *)v24);
    preMoveSpeed = this->MoveEnact(this, a2: (const AILocalMoveGoal_t *)v24);
    if ( preMoveSpeed == ACT_RESET && vStart.x < 0.01 )
    {
      AbsOrigin = CAI_Component::GetAbsOrigin(this, a2: (int)&preMoveActivity);
      v15 = 0;
      *(float *)&v15 = fsqrt(
                         (float)((float)((float)(AbsOrigin->y - *(float *)&v24[192])
                                       * (float)(AbsOrigin->y - *(float *)&v24[192]))
                               + (float)((float)(AbsOrigin->z - *(float *)&v24[196])
                                       * (float)(AbsOrigin->z - *(float *)&v24[196])))
                       + (float)((float)(AbsOrigin->x - *(float *)&v24[188])
                               * (float)(AbsOrigin->x - *(float *)&v24[188])));
      *(_OWORD *)&v24[184] = v15;
      if ( *(float *)&v15 < 0.01 )
      {
        if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
        {
          v16 = this->m_pOuter;
          ActivityName = CAI_BaseNPC::GetActivityName(actID: SLODWORD(vStart.y));
          z_low = LODWORD(vStart.z);
          LODWORD(vStart.z) = ActivityName;
          v19 = CBaseAnimating::GetSequenceName(this: v16, iSequence: z_low);
          v20 = CFmtStrN<256>::CFmtStrN<256>(
                  this: &v23,
                  pszFormat: "CAI_Navigator::MoveNormal calling SetSequence(%s) and SetActivity(%s)",
                  v19,
                  (const char *)LODWORD(vStart.z));
          v21 = CFmtStrN<256>::CFmtStrN<256>(this: &v22, pszFormat: "[Nav] %s", v20->m_szBuf);
          DevMsg(pAI: this->m_pOuter, pszFormat: v21->m_szBuf);
        }
        CBaseAnimating::SetSequence(this: this->m_pOuter, nSequence: SLODWORD(vStart.z));
        this->m_pOuter->SetActivity(this: this->m_pOuter, a2: SLODWORD(vStart.y));
      }
    }
  }
  return preMoveSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x10067890
// Name: public: void CAI_Navigator::AdvancePath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::AdvancePath(CAI_Navigator *this)
{
  CFmtStrN<256> *v2; // eax
  CAI_Path *m_pPath; // eax
  AI_Waypoint_t *m_pFirstWaypoint; // esi
  bool v5; // bl
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v8; // eax
  CBasePropDoor *v9; // ecx
  const char *DebugName; // eax
  AI_Waypoint_t *v11; // ebx
  unsigned int v12; // eax
  IHandleEntity *v13; // ecx
  CAI_BaseNPC *m_pOuter; // esi
  unsigned int v15; // eax
  CFmtStrN<256> v16; // [esp+Ch] [ebp-120h] BYREF
  variant_t emptyVariant; // [esp+118h] [ebp-14h]

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v16, pszFormat: "[Nav] %s", "Advancing path\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v2->m_szBuf);
  }
  m_pPath = this->m_pPath;
  m_pFirstWaypoint = m_pPath->m_Waypoints.m_pFirstWaypoint;
  v5 = (m_pPath->m_Waypoints.m_pFirstWaypoint->m_fWaypointFlags & 2) != 0;
  if ( (m_pPath->m_Waypoints.m_pFirstWaypoint->m_fWaypointFlags & 2) != 0 )
  {
    m_Index = m_pFirstWaypoint->hPathCorner.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
      {
        emptyVariant.iVal = 0;
        ((void (__thiscall *)(IHandleEntity *, const char *, CAI_BaseNPC *, IHandleEntity *, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD))m_pEntity->__vftable[13].dtr_IHandleEntity)(
          a1: m_pEntity,
          a2: "InPass",
          a3: this->m_pOuter,
          a4: m_pEntity,
          a5: 0,
          a6: LODWORD(emptyVariant.vecVal[1]),
          a7: LODWORD(emptyVariant.vecVal[2]),
          a8: -1,
          a9: 0,
          a10: 0);
      }
    }
  }
  if ( !CAI_Path::CurWaypointIsGoal(this: this->m_pPath) )
  {
    if ( (m_pFirstWaypoint->m_fWaypointFlags & 0x10) != 0 )
    {
      v8 = m_pFirstWaypoint->m_hData.m_Index;
      if ( v8 != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber == HIWORD(v8)
        && (v9 = (CBasePropDoor *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity) != nullptr )
      {
        CAI_BaseNPC::OpenPropDoorBegin(this: this->m_pOuter, pDoor: v9);
      }
      else
      {
        DebugName = CBaseEntity::GetDebugName(this: this->m_pOuter);
        DevMsg(a1: "%s trying to open a door that has been deleted!\n", DebugName);
      }
    }
    CAI_Path::Advance(this: this->m_pPath);
    if ( v5 )
    {
      v11 = this->m_pPath->m_Waypoints.m_pFirstWaypoint;
      if ( v11 != nullptr )
      {
        v12 = v11->hPathCorner.m_Index;
        if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
          v13 = nullptr;
        else
          v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        m_pOuter = this->m_pOuter;
        if ( v13 != nullptr )
          m_pOuter->m_hGoalEnt.m_Index = v13->GetRefEHandle(this: v13)->m_Index;
        else
          m_pOuter->m_hGoalEnt.m_Index = -1;
        v15 = v11->hPathCorner.m_Index;
        if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
          CAI_Navigator::DoFindPathToPathcorner(this, pPathCorner: nullptr);
        else
          CAI_Navigator::DoFindPathToPathcorner(
            this,
            pPathCorner: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067A80
// Name: private: bool CAI_Navigator::SimplifyPathForwardScan(struct CAI_Navigator::SimplifyForwardScanParams const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CAI_Navigator::SimplifyPathForwardScan@<al>(
        CAI_Navigator *this@<ecx>,
        int a2@<ebp>,
        const CAI_Navigator::SimplifyForwardScanParams *params)
{
  AI_Waypoint_t *m_pFirstWaypoint; // eax
  Navigation_t m_navType; // edx
  CAI_Path *m_pPath; // ecx
  CAI_BaseNPC *m_pOuter; // edi
  const Vector *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float distRemaining; // xmm1_4
  int v14; // [esp+34h] [ebp-18h] BYREF
  Navigation_t v15; // [esp+38h] [ebp-14h]
  AI_Waypoint_t *v16; // [esp+3Ch] [ebp-10h]
  int testCount; // [esp+40h] [ebp-Ch] BYREF
  void *v18; // [esp+44h] [ebp-8h]
  void *retaddr; // [esp+4Ch] [ebp+0h]

  testCount = a2;
  v18 = retaddr;
  m_pFirstWaypoint = this->m_pPath->m_Waypoints.m_pFirstWaypoint;
  v16 = m_pFirstWaypoint;
  if ( m_pFirstWaypoint != nullptr )
  {
    m_navType = this->m_navType;
    m_pPath = this->m_pPath;
    m_pOuter = this->m_pOuter;
    v15 = m_navType;
    v8 = CAI_Path::CurWaypointPos(this: m_pPath);
    v9 = (float)(v8->x - m_pOuter->m_vecOrigin.m_Value.x) * (float)(v8->x - m_pOuter->m_vecOrigin.m_Value.x);
    v10 = (float)(v8->y - m_pOuter->m_vecOrigin.m_Value.y) * (float)(v8->y - m_pOuter->m_vecOrigin.m_Value.y);
    if ( v15 != NAV_GROUND )
      v10 = v10
          + (float)((float)(v8->z - m_pOuter->m_vecOrigin.m_Value.z) * (float)(v8->z - m_pOuter->m_vecOrigin.m_Value.z));
    m_pFirstWaypoint = v16;
    v11 = fsqrt(v10 + v9);
  }
  else
  {
    v11 = 0.0;
  }
  distRemaining = params->scanDist - v11;
  v14 = 0;
  return distRemaining >= 0.1
      && CAI_Navigator::SimplifyPathForwardScan(
           this,
           a2: (int)&testCount,
           params,
           pCurWaypoint: m_pFirstWaypoint,
           curPoint: &m_pFirstWaypoint->vecLocation,
           distRemaining,
           skipTest: true,
           passedDetour: false,
           pTestCount: &v14) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10067B70
// Name: private: bool CAI_Navigator::SimplifyPathForward(float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CAI_Navigator::SimplifyPathForward@<al>(CAI_Navigator *this@<ecx>, int a2@<ebp>, float maxDist)
{
  CAI_Path *m_pPath; // eax
  AI_Waypoint_t *m_pFirstWaypoint; // esi
  AI_Waypoint_t *pNext; // edi
  float radius; // xmm2_4
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  int v10; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  AI_Waypoint_t *v13; // eax
  AI_Waypoint_t *pPrev; // eax
  __int64 v16; // [esp-Ch] [ebp-20h] BYREF
  _BYTE v17[20]; // [esp-4h] [ebp-18h] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+14h] [ebp+0h]

  *(_DWORD *)&v17[12] = a2;
  *(_DWORD *)&v17[16] = retaddr;
  m_pPath = this->m_pPath;
  m_pFirstWaypoint = m_pPath->m_Waypoints.m_pFirstWaypoint;
  pNext = m_pPath->m_Waypoints.m_pFirstWaypoint->pNext;
  *(_DWORD *)&v17[8] = this;
  if ( pNext != nullptr )
  {
    radius = fullScanParams.radius;
    v16 = *(_QWORD *)&fullScanParams.scanDist;
    *(_QWORD *)v17 = *(_QWORD *)&fullScanParams.increment;
    if ( maxDist > fullScanParams.radius )
    {
      fullScanParams.radius = maxDist;
      fullScanParams.scanDist = fullScanParams.scanDist * (float)(maxDist / radius);
      fullScanParams.increment = fullScanParams.increment * (float)(maxDist / radius);
    }
    if ( CAI_Navigator::SimplifyPathForwardScan(
           this,
           a2: (int)&v17[12],
           params: (const CAI_Navigator::SimplifyForwardScanParams *)&v16) )
    {
      return 1;
    }
    if ( CAI_Navigator::ShouldAttemptSimplifyTo(this: *(CAI_Navigator **)&v17[8], pos: &pNext->vecLocation) )
    {
      v7 = *(_DWORD *)(*(_DWORD *)&v17[8] + 4);
      v8 = pNext->vecLocation.x - *(float *)(v7 + 700);
      v9 = pNext->vecLocation.y - *(float *)(v7 + 704);
      v10 = v7 + 700;
      v11 = v8 * v8;
      v12 = v9 * v9;
      if ( *(_DWORD *)(*(_DWORD *)&v17[8] + 12) != 0 )
        v12 = v12
            + (float)((float)(pNext->vecLocation.z - *(float *)(v10 + 8))
                    * (float)(pNext->vecLocation.z - *(float *)(v10 + 8)));
      if ( *(float *)&v16 > fsqrt(v12 + v11)
        && CAI_Navigator::ShouldSimplifyTo(
             this: *(CAI_Navigator **)&v17[8],
             passedDetour: m_pFirstWaypoint->m_fWaypointFlags & 1,
             pos: &pNext->vecLocation) )
      {
        v13 = m_pFirstWaypoint->pNext;
        if ( v13 != nullptr )
          v13->pPrev = m_pFirstWaypoint->pPrev;
        pPrev = m_pFirstWaypoint->pPrev;
        if ( pPrev != nullptr )
          pPrev->pNext = m_pFirstWaypoint->pNext;
        CUtlMemoryPool::Free(this: &AI_Waypoint_t::s_Allocator, memBlock: m_pFirstWaypoint);
        CAI_Path::SetWaypoints(this: *(CAI_Path **)(*(_DWORD *)&v17[8] + 36), route: pNext, fSetGoalFromLast: false);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10067CF0
// Name: private: bool CAI_Navigator::SimplifyPathQuick(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CAI_Navigator::SimplifyPathQuick@<al>(CAI_Navigator *this@<ecx>, int a2@<ebp>)
{
  bool v3; // al

  v3 = AIStrongOpt();
  return CAI_Navigator::SimplifyPathForwardScan(this, a2, params: &quickScanParams[v3]);
}

//------------------------------------------------------------------------------
// Address: 0x10067D20
// Name: public: virtual bool CAI_Navigator::SimplifyPath(bool,float)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CAI_Navigator::SimplifyPath@<al>(
        CAI_Navigator *this@<ecx>,
        int a2@<edi>,
        bool bFirstForPath,
        float scanDist)
{
  bool HasCondition; // al
  CAI_BaseNPC *m_pOuter; // ecx
  Navigation_t NavType; // eax
  AI_Waypoint_t *m_pFirstWaypoint; // eax
  AI_Waypoint_t *pNext; // ecx
  bool v10; // bl
  bool v11; // al
  float v12; // xmm0_4
  double curtime; // st7
  CFmtStrN<256> *v14; // eax
  CFmtStrN<256> v16; // [esp+8h] [ebp-110h] BYREF
  bool bInPVS; // [esp+116h] [ebp-2h]
  bool bRetVal; // [esp+117h] [ebp-1h]
  int savedregs; // [esp+118h] [ebp+0h] BYREF
  float bFirstForPatha; // [esp+120h] [ebp+8h]

  HasCondition = CAI_BaseNPC::HasCondition(this: this->m_pOuter, iCondition: 1);
  m_pOuter = this->m_pOuter;
  bInPVS = HasCondition;
  bRetVal = false;
  NavType = CAI_BaseNPC::GetNavType(this: m_pOuter);
  if ( NavType != NAV_GROUND && NavType != NAV_FLY )
    return bRetVal;
  m_pFirstWaypoint = this->m_pPath->m_Waypoints.m_pFirstWaypoint;
  if ( m_pFirstWaypoint != nullptr )
  {
    pNext = m_pFirstWaypoint->pNext;
    if ( pNext != nullptr
      && m_pFirstWaypoint->m_iWPType == pNext->m_iWPType
      && (m_pFirstWaypoint->m_fWaypointFlags & 0x2A) == 0 )
    {
      v10 = gpGlobals->curtime >= this->m_flNextSimplifyTime;
      if ( bFirstForPath && gpGlobals->curtime < this->m_flNextSimplifyTime )
        v10 = bInPVS;
      if ( AIStrongOpt() && v10 )
      {
        if ( g_iFrameLastSimplified == gpGlobals->framecount )
          v10 = false;
        else
          g_iFrameLastSimplified = gpGlobals->framecount;
      }
      this->m_bForcedSimplify = bFirstForPath;
      if ( v10 )
      {
        v11 = AIStrongOpt();
        if ( bInPVS )
          v12 = ROUTE_SIMPLIFY_TIME_DELAY[v11];
        else
          v12 = NO_PVS_ROUTE_SIMPLIFY_TIME_DELAY[v11];
        if ( this->m_pOuter->m_MoveEfficiency > AIME_NORMAL )
          v12 = v12 * 2.0;
        this->m_flNextSimplifyTime = gpGlobals->curtime + v12;
        if ( CAI_Navigator::SimplifyPathForward(this, a2: (int)&savedregs, maxDist: scanDist) != 0
          || CAI_Navigator::SimplifyPathBacktrack(this, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: (int)this) != 0 )
        {
          goto LABEL_30;
        }
      }
      else
      {
        if ( !bFirstForPath && (!bInPVS || this->m_pOuter->m_MoveEfficiency != AIME_NORMAL) )
          return bRetVal;
        if ( AIStrongOpt() )
        {
          bFirstForPatha = gpGlobals->curtime - this->m_flLastSuccessfulSimplifyTime;
          if ( bFirstForPatha <= QUICK_SIMPLIFY_TIME_DELAY[AIStrongOpt()] )
            return bRetVal;
        }
      }
      if ( CAI_Navigator::SimplifyPathQuick(this, a2: (int)&savedregs) )
      {
LABEL_30:
        curtime = gpGlobals->curtime;
        bRetVal = true;
        this->m_flLastSuccessfulSimplifyTime = curtime;
        if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
        {
          v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v16, pszFormat: "[Nav] %s", "Simplified path\n");
          DevMsg(pAI: this->m_pOuter, pszFormat: v14->m_szBuf);
        }
      }
      return bRetVal;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10067F00
// Name: public: bool CAI_Navigator::CanFitAtNode(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Navigator::CanFitAtNode(CAI_Navigator *this, int nodeNum, unsigned int collisionMask)
{
  CAI_Network *m_pAINetwork; // eax
  bool result; // al
  CAI_Node *v6; // ebx
  double v7; // st7
  Vector startPos; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  m_pAINetwork = this->m_pAINetwork;
  if ( m_pAINetwork != nullptr )
  {
    if ( nodeNum < 0 || nodeNum >= m_pAINetwork->m_iNumNodes )
    {
      ++`CAI_Network::GetNode'::`8'::warningCount;
      v6 = nullptr;
    }
    else
    {
      v6 = m_pAINetwork->m_pAInode[nodeNum];
    }
    CAI_Node::GetPosition(this: v6, result: &startPos, hull: this->m_pOuter->m_eHull);
    result = false;
    if ( (v6->m_eNodeType != NODE_GROUND
       || CAI_MoveProbe::CheckStandPosition(this: this->m_pMoveProbe, vecStart: &startPos, collisionMask))
      && (v6->m_eNodeType != NODE_CLIMB
       || (v6->m_eNodeInfo & 0x1D) == 0
       || CAI_MoveProbe::CheckStandPosition(this: this->m_pMoveProbe, vecStart: &startPos, collisionMask)) )
    {
      if ( CAI_Navigator::CanFitAtPosition(
             this,
             a2: COERCE_FLOAT(&savedregs),
             a3: collisionMask,
             a4: (int)this,
             vStartPos: &startPos,
             collisionMask,
             bIgnoreTransients: false,
             bAllowPlayerAvoid: true) )
      {
        return true;
      }
      v7 = ((double (__thiscall *)(CAI_BaseNPC *))this->m_pOuter->StepHeight)(a1: this->m_pOuter);
      startPos.z = v7 + startPos.z;
      if ( CAI_Navigator::CanFitAtPosition(
             this,
             a2: COERCE_FLOAT(&savedregs),
             a3: collisionMask,
             a4: (int)this,
             vStartPos: &startPos,
             collisionMask,
             bIgnoreTransients: false,
             bAllowPlayerAvoid: true) )
      {
        return true;
      }
    }
  }
  else
  {
    DevMsg(a1: "CanFitAtNode() called with no network!\n");
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067FF0
// Name: public: float CAI_Navigator::BuildAndGetPathDistToGoal(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Navigator::BuildAndGetPathDistToGoal(CAI_Navigator *this)
{
  CAI_Path *m_pPath; // ecx
  AI_Waypoint_t *m_pFirstWaypoint; // eax

  m_pPath = this->m_pPath;
  if ( m_pPath != nullptr
    && (CAI_Path::GetPathLength(this: m_pPath),
        (m_pFirstWaypoint = this->m_pPath->m_Waypoints.m_pFirstWaypoint) != nullptr)
    && m_pFirstWaypoint->flPathDistGoal >= 0.0 )
  {
    return CAI_Navigator::GetPathDistToGoal(this);
  }
  else
  {
    return -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068030
// Name: public: CMemberFunctor2<class CAI_Navigator __near *,bool (CAI_Navigator::*)(struct AI_NavGoal_t const __near &,unsigned int),struct AI_NavGoal_t,unsigned int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::CMemberFunctor2<class CAI_Navigator __near *,bool (CAI_Navigator::*)(struct AI_NavGoal_t const __near &,unsigned int),struct AI_NavGoal_t,unsigned int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>(class CAI_Navigator __near *,bool (CAI_Navigator::*)(struct AI_NavGoal_t const __near &,unsigned int),struct AI_NavGoal_t const __near &,unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
        CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this,
        CAI_Navigator *pObject,
        bool (__thiscall *__ptr64 pfnProxied)(CAI_Navigator *this, const AI_NavGoal_t *, unsigned int),
        const AI_NavGoal_t *arg1,
        unsigned int *arg2)
{
  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  LODWORD(this->m_Proxy.m_pfnProxied) = (_DWORD)pfnProxied;
  this->m_Proxy.m_pObject = pObject;
  HIDWORD(this->m_Proxy.m_pfnProxied) = HIDWORD(pfnProxied);
  this->m_arg1 = *arg1;
  this->m_arg2 = *arg2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100680B0
// Name: public: virtual void CMemberFunctor2<class CAI_Navigator __near *,bool (CAI_Navigator::*)(struct AI_NavGoal_t const __near &,unsigned int),struct AI_NavGoal_t,unsigned int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, AI_NavGoal_t *, unsigned int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + HIDWORD(this->m_Proxy.m_pfnProxied),
    a2: &this->m_arg1,
    a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x100680D0
// Name: public: virtual void CMemberFunctor1<class CAI_Navigator __near *,bool (CAI_Navigator::*)(class Vector const __near &),class Vector,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(Vector const &),Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(Vector const &),Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, Vector *))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + HIDWORD(this->m_Proxy.m_pfnProxied),
    a2: &this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10068160
// Name: SetWanderGoalByRandomVector
// Source: json
//------------------------------------------------------------------------------
char __usercall SetWanderGoalByRandomVector@<al>(
        CAI_Navigator *pNav@<esi>,
        float minRadius,
        float maxRadius,
        int numTries)
{
  CFmtStrN<256> *v4; // eax
  CAI_BaseNPC *m_pOuter; // eax
  CAI_BaseNPC *v6; // ecx
  CAI_Navigator_vtbl *v7; // eax
  bool (__thiscall *SetGoal)(CAI_Navigator *, const AI_NavGoal_t *, unsigned int); // edx
  float v10; // [esp+18h] [ebp-1A4h]
  CFmtStrN<256> v11; // [esp+20h] [ebp-19Ch] BYREF
  AIMoveTrace_t dst; // [esp+12Ch] [ebp-90h] BYREF
  int v13; // [esp+164h] [ebp-58h] BYREF
  Vector v14; // [esp+168h] [ebp-54h]
  int v15; // [esp+174h] [ebp-48h]
  int v16; // [esp+178h] [ebp-44h]
  int v17; // [esp+17Ch] [ebp-40h]
  int v18; // [esp+180h] [ebp-3Ch]
  int v19; // [esp+184h] [ebp-38h]
  int v20; // [esp+188h] [ebp-34h]
  int v21; // [esp+18Ch] [ebp-30h]
  CBaseEntity *v22; // [esp+190h] [ebp-2Ch]
  Vector dir; // [esp+194h] [ebp-28h] BYREF
  Vector vecEnd; // [esp+1A0h] [ebp-1Ch] BYREF
  Vector vEndPosition; // [esp+1ACh] [ebp-10h]
  float dist; // [esp+1B8h] [ebp-4h]
  int savedregs; // [esp+1BCh] [ebp+0h] BYREF
  int numTriesa; // [esp+1CCh] [ebp+10h]

  numTriesa = numTries - 1;
  if ( numTriesa < 0 )
    return 0;
  while ( 1 )
  {
    dist = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
             a1: random,
             a2: LODWORD(minRadius),
             a3: LODWORD(maxRadius));
    v10 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
            a1: random,
            a2: 0,
            a3: 1135869624);
    UTIL_YawToVector(result: &dir, yaw: v10);
    if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "[Nav] %s", "Set vector goal\n");
      DevMsg(pAI: pNav->m_pOuter, pszFormat: v4->m_szBuf);
    }
    memset((int)&dst, value: nullptr, count: sizeof(dst));
    m_pOuter = pNav->m_pOuter;
    if ( m_pOuter != nullptr )
      m_pOuter->m_afMemory |= 8u;
    v6 = pNav->m_pOuter;
    vecEnd.x = v6->m_vecOrigin.m_Value.x + (float)(dir.x * dist);
    vecEnd.y = v6->m_vecOrigin.m_Value.y + (float)(dir.y * dist);
    vecEnd.z = v6->m_vecOrigin.m_Value.z + (float)(dir.z * dist);
    CAI_MoveProbe::MoveLimit(
      this: pNav->m_pMoveProbe,
      a2: (int)&savedregs,
      navType: pNav->m_navType,
      vecStart: &v6->m_vecOrigin.m_Value,
      &vecEnd,
      collisionMask: v6->m_nAITraceMask,
      pTarget: nullptr,
      pctToCheckStandPositions: 100.0,
      flags: 0,
      pTrace: &dst);
    if ( dst.fStatus == AIMR_OK || minRadius + 0.01 <= (float)(dist - dst.flDistObstructed) )
    {
      v7 = pNav->CAI_Component::__vftable;
      vEndPosition = dst.vEndPosition;
      v14 = dst.vEndPosition;
      v22 = AIN_DEF_TARGET_31;
      SetGoal = v7->SetGoal;
      v13 = 4;
      v15 = -1;
      v16 = -1;
      v17 = -1;
      v18 = -1;
      v19 = -1082130432;
      v20 = -1082130432;
      v21 = 0;
      if ( SetGoal(this: pNav, a2: (const AI_NavGoal_t *)&v13, a3: 0) )
        break;
    }
    if ( --numTriesa < 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10068380
// Name: public: bool CAI_Navigator::SetWanderGoal(float,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_Navigator::SetWanderGoal(CAI_Navigator *this, float minRadius, float maxRadius)
{
  CAI_BaseNPC *m_pOuter; // eax
  char v5; // al

  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_strHintGroup.pszValue != nullptr )
  {
    if ( CAI_Navigator::SetRandomGoal(this, from: &m_pOuter->m_vecOrigin.m_Value, minPathLength: 1.0, dir: &vec3_origin) != 0 )
      return true;
    v5 = SetWanderGoalByRandomVector(pNav: this, minRadius, maxRadius, numTries: 5);
  }
  else
  {
    if ( SetWanderGoalByRandomVector(pNav: this, minRadius, maxRadius, numTries: 5) != 0 )
      return true;
    v5 = CAI_Navigator::SetRandomGoal(
           this,
           from: &this->m_pOuter->m_vecOrigin.m_Value,
           minPathLength: 1.0,
           dir: &vec3_origin);
  }
  return v5 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10068440
// Name: public: void CAI_Navigator::StopMoving(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::StopMoving(CAI_Navigator *this, bool bImmediate)
{
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> *v4; // eax
  CFmtStrN<256> *v5; // eax
  CFmtStrN<256> v6; // [esp+8h] [ebp-218h] BYREF
  CFmtStrN<256> v7; // [esp+114h] [ebp-10Ch] BYREF

  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v6, pszFormat: "CAI_Navigator::StopMoving( %d )\n", bImmediate);
    v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v7, pszFormat: "[Nav] %s", v3->m_szBuf);
    DevMsg(pAI: this->m_pOuter, pszFormat: v4->m_szBuf);
  }
  if ( CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath) != 0 )
  {
    if ( bImmediate || CAI_Navigator::SetGoalFromStoppingPath(this) == 0 )
      this->OnNavComplete(this);
  }
  else
  {
    if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v7, pszFormat: "[Nav] %s", "CAI_Navigator::ClearGoal()\n");
      DevMsg(pAI: this->m_pOuter, pszFormat: v5->m_szBuf);
    }
    CAI_Navigator::ClearPath(this);
    this->OnNewGoal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068520
// Name: public: bool CAI_Navigator::TeleportAlongPath(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::TeleportAlongPath(CAI_Navigator *this)
{
  CAI_Path *m_pPath; // ecx
  CAI_BaseNPC *m_pOuter; // ecx
  int m_nAITraceMask; // edi
  CAI_MoveProbe *m_pMoveProbe; // ebx
  float flStartZ; // [esp+0h] [ebp-30h]
  Vector vecStart; // [esp+18h] [ebp-18h] BYREF
  Vector vTestPoint; // [esp+24h] [ebp-Ch] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  m_pPath = this->m_pPath;
  if ( m_pPath->m_Waypoints.m_pFirstWaypoint == nullptr )
    return 0;
  while ( 1 )
  {
    vecStart = *CAI_Path::CurWaypointPos(this: m_pPath);
    CAI_Navigator::AdvancePath(this);
    m_pOuter = this->m_pOuter;
    m_nAITraceMask = m_pOuter->m_nAITraceMask;
    m_pMoveProbe = m_pOuter->m_pMoveProbe;
    flStartZ = ((double (*)(void))m_pOuter->StepHeight)();
    CAI_MoveProbe::FloorPoint(
      this: m_pMoveProbe,
      a2: COERCE_FLOAT(&savedregs),
      a3: m_nAITraceMask,
      a4: (int)this,
      &vecStart,
      collisionMask: *(float *)&m_nAITraceMask,
      flStartZ,
      flEndZ: -64.0,
      pVecResult: &vTestPoint);
    if ( CAI_Navigator::CanFitAtPosition(
           this,
           a2: COERCE_FLOAT(&savedregs),
           a3: m_nAITraceMask,
           a4: (int)this,
           vStartPos: &vTestPoint,
           collisionMask: this->m_pOuter->m_nAITraceMask,
           bIgnoreTransients: false,
           bAllowPlayerAvoid: false)
      && CAI_MoveProbe::CheckStandPosition(
           this: this->m_pOuter->m_pMoveProbe,
           vecStart: &vTestPoint,
           collisionMask: this->m_pOuter->m_nAITraceMask) )
    {
      break;
    }
    if ( !CAI_Path::CurWaypointIsGoal(this: this->m_pPath) )
    {
      m_pPath = this->m_pPath;
      if ( m_pPath->m_Waypoints.m_pFirstWaypoint != nullptr )
        continue;
    }
    return 0;
  }
  this->m_pOuter->Teleport(this: this->m_pOuter, a2: &vTestPoint, a3: nullptr, a4: nullptr, a5: true);
  CBaseEntity::SetGroundEntity(this: this->m_pOuter, ground: nullptr);
  CBaseEntity::PhysicsTouchTriggers(this: this->m_pOuter, pPrevAbsOrigin: &vTestPoint);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10068630
// Name: protected: virtual enum AIMoveResult_t CAI_Navigator::MoveJump(void)
// Source: json
//------------------------------------------------------------------------------
AIMoveResult_t __thiscall CAI_Navigator::MoveJump(CAI_Navigator *this)
{
  CAI_BaseNPC *m_pOuter; // edi
  CAI_MoveProbe *m_pMoveProbe; // edx
  unsigned int m_nAITraceMask; // ebx
  const Vector *v5; // eax
  AIMoveResult_t result; // eax
  CFmtStrN<256> *v7; // eax
  CFmtStrN<256> *v8; // eax
  CAI_Path *m_pPath; // ecx
  CFmtStrN<256> v10; // [esp+18h] [ebp-150h] BYREF
  AIMoveTrace_t moveTrace; // [esp+124h] [ebp-44h] BYREF
  CBaseEntity *pTarget; // [esp+15Ch] [ebp-Ch]
  CAI_Path *v13; // [esp+160h] [ebp-8h]
  CAI_MoveProbe *v14; // [esp+164h] [ebp-4h]
  int savedregs; // [esp+168h] [ebp+0h] BYREF

  if ( this->m_navType == NAV_JUMP )
  {
    if ( (this->m_pOuter->m_fFlags.m_Value & 1) != 0 )
    {
      if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
      {
        v8 = CFmtStrN<256>::CFmtStrN<256>(this: &v10, pszFormat: "[Nav] %s", "Jump stop\n");
        DevMsg(pAI: this->m_pOuter, pszFormat: v8->m_szBuf);
      }
      if ( this->m_pMotor->MoveJumpStop(this: this->m_pMotor) == AIMR_CHANGE_TYPE )
      {
        m_pPath = this->m_pPath;
        this->m_navType = NAV_GROUND;
        if ( CAI_Path::CurWaypointIsGoal(this: m_pPath) )
        {
          this->OnNavComplete(this);
          return AIMR_OK;
        }
        else
        {
          CAI_Navigator::AdvancePath(this);
          return AIMR_CHANGE_TYPE;
        }
      }
      return AIMR_OK;
    }
LABEL_17:
    this->m_pMotor->MoveJumpExecute(this: this->m_pMotor);
    return AIMR_OK;
  }
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_fFlags.m_Value & 1) == 0 )
    goto LABEL_17;
  memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
  m_pMoveProbe = this->m_pMoveProbe;
  m_nAITraceMask = m_pOuter->m_nAITraceMask;
  v13 = this->m_pPath;
  v14 = m_pMoveProbe;
  pTarget = CAI_Navigator::GetNavTargetEntity(this);
  v5 = CAI_Path::CurWaypointPos(this: v13);
  CAI_MoveProbe::MoveLimit(
    this: v14,
    a2: (int)&savedregs,
    navType: NAV_JUMP,
    vecStart: &m_pOuter->m_vecOrigin.m_Value,
    vecEnd: v5,
    collisionMask: m_nAITraceMask,
    pTarget,
    pctToCheckStandPositions: 100.0,
    flags: 0,
    pTrace: &moveTrace);
  result = moveTrace.fStatus;
  if ( moveTrace.fStatus >= AIMR_OK )
  {
    this->m_navType = NAV_JUMP;
    if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v10, pszFormat: "[Nav] %s", "Jump start\n");
      DevMsg(pAI: this->m_pOuter, pszFormat: v7->m_szBuf);
    }
    this->m_pMotor->MoveJumpStart(this: this->m_pMotor, a2: &moveTrace.vJumpVelocity);
    return AIMR_OK;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100687C0
// Name: private: virtual bool CAI_Navigator::OnObstructionPreSteer(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::OnObstructionPreSteer(
        CAI_Navigator *this,
        AILocalMoveGoal_t *pMoveGoal,
        float distClear,
        AIMoveResult_t *pResult)
{
  float v4; // xmm2_4
  char v6; // bl
  float x; // xmm1_4
  float maxDist; // xmm0_4
  float v9; // xmm0_4
  float m_next; // eax
  CHandle<CBaseEntity> *p_m_NextSidestepTimer; // ebx
  CBaseEntity *v13; // ecx
  CBaseEntity *pObstruction; // edi

  v4 = distClear;
  v6 = 0;
  if ( (pMoveGoal->flags & 1) != 0 )
  {
    x = *(float *)&this->m_pLocalNavigator->m_pOuter;
  }
  else
  {
    if ( (pMoveGoal->flags & 4) != 0 )
      goto LABEL_19;
    maxDist = pMoveGoal->maxDist;
    x = this->m_pLocalNavigator->m_LastMoveGoal.dir.x;
    v6 = 1;
    if ( maxDist < 48.0 && x > (float)(maxDist - distClear) )
      x = maxDist + 1.0;
  }
  v9 = pMoveGoal->maxDist;
  if ( distClear > v9 )
  {
    *pResult = AIMR_OK;
    return 1;
  }
  if ( x > v9 )
  {
    if ( (pMoveGoal->flags & 1) == 0
      || pMoveGoal->directTrace.fStatus != AIMR_BLOCKED_NPC
      || (v4 = distClear, !pMoveGoal->directTrace.pObstruction->IsMoving(this: pMoveGoal->directTrace.pObstruction)) )
    {
      pMoveGoal->maxDist = v4;
      *pResult = AIMR_OK;
      if ( v6 != 0 )
      {
        CAI_Navigator::AdvancePath(this: (CAI_Navigator *)((char *)this - 8));
        return 1;
      }
      else
      {
        if ( v4 < 0.025 )
          *pResult = pMoveGoal->directTrace.fStatus;
        return 1;
      }
    }
  }
LABEL_19:
  if ( (*(unsigned __int8 (__stdcall **)(AILocalMoveGoal_t *, float, AIMoveResult_t *))(*(_DWORD *)(*((_DWORD *)this - 1)
                                                                                                  + 2284)
                                                                                      + 8))(
         a1: pMoveGoal,
         a2: COERCE_FLOAT(LODWORD(v4)),
         a3: pResult) != 0 )
    return 1;
  m_next = this->m_NextSidestepTimer.m_next;
  p_m_NextSidestepTimer = (CHandle<CBaseEntity> *)&this->m_NextSidestepTimer;
  if ( m_next != NAN
    && g_pEntityList->m_EntPtrArray[LOWORD(m_next)].m_SerialNumber == HIWORD(LODWORD(m_next))
    && g_pEntityList->m_EntPtrArray[LOWORD(m_next)].m_pEntity != nullptr )
  {
    return 0;
  }
  if ( pMoveGoal->directTrace.pObstruction == nullptr )
    return 0;
  if ( NAI_Hull::Width(id: *(_DWORD *)(*((_DWORD *)this - 1) + 1672)) <= distClear )
    return 0;
  v13 = *((CBaseEntity **)this - 1);
  pObstruction = pMoveGoal->directTrace.pObstruction;
  if ( pObstruction != CBaseEntity::GetGroundEntity(this: v13)
    || !pObstruction->IsPlayer(this: pObstruction)
    && __RTDynamicCast(
         inptr: pMoveGoal->directTrace.pObstruction,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CPhysicsProp `RTTI Type Descriptor',
         isReference: 0) == nullptr )
  {
    return 0;
  }
  CHandle<CBaseEntity>::operator=(this: p_m_NextSidestepTimer, val: pMoveGoal->directTrace.pObstruction);
  *pResult = AIMR_CHANGE_TYPE;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10068980
// Name: private: virtual bool CAI_Navigator::MoveUpdateWaypoint(enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::MoveUpdateWaypoint(CAI_Navigator *this, AIMoveResult_t *pResult)
{
  CAI_Path *m_pPath; // ecx
  CAI_BaseNPC *m_pOuter; // eax
  float *p_x; // edi
  float v6; // xmm0_4
  float v7; // xmm1_4
  CNetworkVectorXY_SeparateZBase<Vector,CBaseEntity::NetworkVar_m_vecOrigin> *p_m_vecOrigin; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  __int128 v12; // xmm0
  bool IsGoal; // al
  double v14; // xmm0_8
  float v15; // xmm1_4
  int v16; // ecx
  __int128 v18; // [esp-20h] [ebp-2Ch]
  float v19; // [esp-4h] [ebp-10h]

  m_pPath = this->m_pPath;
  m_pOuter = this->m_pOuter;
  p_x = &m_pPath->m_Waypoints.m_pFirstWaypoint->vecLocation.x;
  v6 = m_pPath->m_Waypoints.m_pFirstWaypoint->vecLocation.x - m_pOuter->m_vecOrigin.m_Value.x;
  v7 = m_pPath->m_Waypoints.m_pFirstWaypoint->vecLocation.y - m_pOuter->m_vecOrigin.m_Value.y;
  p_m_vecOrigin = &m_pOuter->m_vecOrigin;
  v9 = v6 * v6;
  v10 = v7 * v7;
  if ( this->m_navType != NAV_GROUND )
    v10 = v10 + (float)((float)(p_x[2] - p_m_vecOrigin->m_Value.z) * (float)(p_x[2] - p_m_vecOrigin->m_Value.z));
  v11 = v10 + v9;
  v12 = 0;
  *(float *)&v12 = fsqrt(v11);
  v18 = v12;
  v19 = *(float *)&v12;
  IsGoal = CAI_Path::CurWaypointIsGoal(this: m_pPath);
  if ( npc_vphysics.m_pParent != nullptr && npc_vphysics.m_pParent->m_Value.m_nValue != 0 )
    v14 = 0.25;
  else
    v14 = 0.0625;
  v15 = v14;
  if ( v15 < v19 )
    return 0;
  if ( test_it )
  {
    v16 = *((_DWORD *)p_x + 10);
    if ( v16 != 0 && *(_DWORD *)(v16 + 36) != *((_DWORD *)p_x + 9) && v19 >= 0.001 )
      return 0;
  }
  if ( IsGoal )
  {
    this->OnNavComplete(this);
    *pResult = AIMR_OK;
  }
  else
  {
    CAI_Navigator::AdvancePath(this);
    *pResult = AIMR_CHANGE_TYPE;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10068AB0
// Name: private: virtual bool CAI_Navigator::OnMoveBlocked(enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CAI_Navigator::OnMoveBlocked@<al>(CAI_Navigator *this@<ecx>, int a2@<ebp>, AIMoveResult_t *pResult)
{
  CAI_LocalNavigator_vtbl *v4; // eax
  void (__thiscall *TaskComplete)(struct CAI_LocalNavigator *, bool); // ecx
  CBasePropDoor *m_pEntity; // eax
  CAI_Path *m_pLocalNavigator; // ecx
  AI_Waypoint_t *m_pFirstWaypoint; // eax
  AI_Waypoint_t *pNext; // edx
  const Vector *v11; // eax
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // ecx
  float v16; // xmm1_4
  __int128 v17; // xmm0
  CFmtStrN<256> *v18; // eax
  Activity StoppedActivity; // eax
  CAI_Path *v20; // ecx
  float *v21; // edi
  const Vector *v22; // eax
  float v23; // xmm1_4
  __int128 v24; // xmm0
  float v25; // xmm1_4
  CFmtStrN<256> v26; // [esp-12Ch] [ebp-138h] BYREF
  __int128 v27; // [esp-20h] [ebp-2Ch]
  CAI_BaseNPC *m_pOuter; // [esp-4h] [ebp-10h]
  int v29; // [esp+0h] [ebp-Ch]
  void *v30; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v29 = a2;
  v30 = retaddr;
  if ( *pResult == AIMR_BLOCKED_NPC )
  {
    v4 = this->m_pLocalNavigator->__vftable;
    if ( v4 != nullptr && ((int)v4[2].dtr_CAI_Component & 0x10) != 0 )
    {
      TaskComplete = v4[1].TaskComplete;
      if ( TaskComplete != (void (__thiscall *)(struct CAI_LocalNavigator *, bool))-1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)TaskComplete].m_SerialNumber == (unsigned int)TaskComplete >> 16 )
      {
        m_pEntity = (CBasePropDoor *)g_pEntityList->m_EntPtrArray[(unsigned __int16)TaskComplete].m_pEntity;
        if ( m_pEntity != nullptr )
        {
          CAI_BaseNPC::OpenPropDoorBegin(this: *((CAI_BaseNPC **)this - 1), pDoor: m_pEntity);
          *pResult = AIMR_OK;
          return 1;
        }
      }
    }
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, AIMoveResult_t *))(*(_DWORD *)(*((_DWORD *)this - 1) + 2284) + 24))(
         a1: *((_DWORD *)this - 1) + 2284,
         a2: pResult) != 0 )
    return 1;
  if ( !CAI_Path::CurWaypointIsGoal(this: (CAI_Path *)this->m_pLocalNavigator) )
  {
    m_pLocalNavigator = (CAI_Path *)this->m_pLocalNavigator;
    m_pFirstWaypoint = m_pLocalNavigator->m_Waypoints.m_pFirstWaypoint;
    pNext = m_pLocalNavigator->m_Waypoints.m_pFirstWaypoint->pNext;
    if ( pNext != nullptr
      && m_pFirstWaypoint->m_iWPType == pNext->m_iWPType
      && (m_pFirstWaypoint->m_fWaypointFlags & 0x2A) == 0 )
    {
      v11 = CAI_Path::CurWaypointPos(this: m_pLocalNavigator);
      v12 = *((_DWORD *)this - 1);
      v13 = (float)(v11->x - *(float *)(v12 + 700)) * (float)(v11->x - *(float *)(v12 + 700));
      v14 = (float)(v11->y - *(float *)(v12 + 704)) * (float)(v11->y - *(float *)(v12 + 704));
      if ( this->m_pOuter != nullptr )
        v14 = v14 + (float)((float)(v11->z - *(float *)(v12 + 708)) * (float)(v11->z - *(float *)(v12 + 708)));
      v15 = *(_DWORD *)(v12 + 1672);
      v16 = v14 + v13;
      v17 = 0;
      *(float *)&v17 = fsqrt(v16);
      v27 = v17;
      m_pOuter = (CAI_BaseNPC *)v17;
      if ( NAI_Hull::Width(id: v15) > *(float *)&v17 )
      {
        CAI_Navigator::AdvancePath(this: (CAI_Navigator *)((char *)this - 8));
        *pResult = AIMR_CHANGE_TYPE;
      }
    }
  }
  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v18 = CFmtStrN<256>::CFmtStrN<256>(
            this: &v26,
            pszFormat: "[Nav] %s",
            "CAI_Navigator::OnMoveBlocked calling SetActivity(GetStoppedActivity)");
    DevMsg(pAI: *((CAI_BaseNPC **)this - 1), pszFormat: v18->m_szBuf);
  }
  StoppedActivity = CAI_BaseNPC::GetStoppedActivity(this: *((CAI_BaseNPC **)this - 1));
  (*(void (__thiscall **)(_DWORD, Activity))(**((_DWORD **)this - 1) + 1652))(
    a1: *((_DWORD *)this - 1),
    a2: StoppedActivity);
  v20 = (CAI_Path *)this->m_pLocalNavigator;
  v21 = *((float **)this - 1);
  m_pOuter = this->m_pOuter;
  v22 = CAI_Path::ActualGoalPosition(this: v20);
  v23 = (float)(v22->y - v21[176]) * (float)(v22->y - v21[176]);
  if ( m_pOuter != nullptr )
    v23 = v23 + (float)((float)(v22->z - v21[177]) * (float)(v22->z - v21[177]));
  v24 = 0;
  *(float *)&v24 = v23 + (float)((float)(v22->x - v21[175]) * (float)(v22->x - v21[175]));
  v25 = *(float *)&this->m_pLocalNavigator->m_pOuter + 0.1;
  *(float *)&v24 = fsqrt(*(float *)&v24);
  v27 = v24;
  if ( v25 <= *(float *)&v24 )
    return 0;
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 52))(a1: (char *)this - 8);
  *pResult = AIMR_OK;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10068D60
// Name: public: void CAI_Navigator::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::Save(CAI_Navigator *this, ISave *save)
{
  ISave *v2; // ebx
  CAI_Path *m_pPath; // eax
  AI_Waypoint_t *m_pFirstWaypoint; // eax
  Navigation_t m_iWPType; // eax
  bool (__thiscall *GetStoppingPath)(CAI_Navigator *, CAI_WaypointList *); // edx
  AI_Waypoint_t *i; // esi
  void (__thiscall *v9)(int *, _DWORD *, ISave *); // edx
  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > minPathArray; // [esp+Ch] [ebp-20h] BYREF
  _DWORD v11[3]; // [esp+20h] [ebp-Ch] BYREF

  v2 = save;
  save->WriteShort_2(this: save, a2: &AI_NAVIGATOR_SAVE_VERSION, a3: 1);
  m_pPath = this->m_pPath;
  memset(&minPathArray, 0, sizeof(minPathArray));
  m_pFirstWaypoint = m_pPath->m_Waypoints.m_pFirstWaypoint;
  if ( m_pFirstWaypoint != nullptr )
  {
    m_iWPType = m_pFirstWaypoint->m_iWPType;
    if ( m_iWPType == NAV_CLIMB || m_iWPType == NAV_JUMP )
    {
      GetStoppingPath = this->GetStoppingPath;
      save = nullptr;
      if ( GetStoppingPath(this, a2: (CAI_WaypointList *)&save) && save != nullptr )
      {
        for ( i = CAI_WaypointList::GetLast(this: (CAI_WaypointList *)&save); i != nullptr; i = i->pPrev )
          CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::InsertBefore(
            this: &minPathArray,
            elem: minPathArray.m_Size,
            src: i);
        CAI_WaypointList::RemoveAll(this: (CAI_WaypointList *)&save);
      }
    }
  }
  if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::`local static guard' |= 1u;
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>,10>::`vftable';
  }
  v11[0] = &minPathArray;
  v9 = *(void (__thiscall **)(int *, _DWORD *, ISave *))`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::ops;
  v11[1] = 0;
  v11[2] = 0;
  v9(
    a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::ops,
    a2: v11,
    a3: v2);
  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::~CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>(this: &minPathArray);
}

//------------------------------------------------------------------------------
// Address: 0x10068E40
// Name: public: void CAI_Navigator::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::Restore(CAI_Navigator *this, IRestore *restore)
{
  int v3; // edi
  void (__thiscall *v4)(int *, _DWORD *, IRestore *); // eax
  int m_Size; // eax
  int i; // esi
  AI_Waypoint_t *m_pMemory; // edx
  int v8; // edi
  int v9; // esi
  AI_Waypoint_t *pNext; // ecx
  AI_Waypoint_t *v11; // eax
  AI_Waypoint_t *pPrev; // ecx
  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > minPathArray; // [esp+18h] [ebp-20h] BYREF
  _DWORD v14[3]; // [esp+2Ch] [ebp-Ch] BYREF

  if ( restore->ReadShort_2(this: restore) == 1 )
  {
    v3 = 0;
    memset(&minPathArray, 0, sizeof(minPathArray));
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>,10>::`vftable';
    }
    v14[0] = &minPathArray;
    v4 = *(void (__thiscall **)(int *, _DWORD *, IRestore *))(`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::ops
                                                            + 4);
    v14[1] = 0;
    v14[2] = 0;
    v4(
      a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>>'::`2'::ops,
      a2: v14,
      a3: restore);
    m_Size = minPathArray.m_Size;
    if ( minPathArray.m_Size != 0 )
    {
      for ( i = 0; i < minPathArray.m_Size; ++v3 )
      {
        CAI_WaypointList::PrependWaypoint(
          this: this->m_pClippedWaypoints,
          newPoint: &minPathArray.m_Memory.m_pMemory[v3].vecLocation,
          navType: minPathArray.m_Memory.m_pMemory[v3].m_iWPType,
          waypointFlags: minPathArray.m_Memory.m_pMemory[v3].m_fWaypointFlags & 0xFFFFFFFD,
          flYaw: minPathArray.m_Memory.m_pMemory[v3].flYaw);
        m_Size = minPathArray.m_Size;
        ++i;
      }
      this->m_flTimeClipped = gpGlobals->curtime + 1000.0;
    }
    m_pMemory = minPathArray.m_Memory.m_pMemory;
    v8 = m_Size - 1;
    if ( m_Size - 1 >= 0 )
    {
      v9 = v8;
      do
      {
        pNext = m_pMemory[v9].pNext;
        v11 = &m_pMemory[v9];
        if ( pNext != nullptr )
        {
          pNext->pPrev = v11->pPrev;
          m_pMemory = minPathArray.m_Memory.m_pMemory;
        }
        pPrev = v11->pPrev;
        if ( pPrev != nullptr )
        {
          pPrev->pNext = v11->pNext;
          m_pMemory = minPathArray.m_Memory.m_pMemory;
        }
        --v8;
        --v9;
      }
      while ( v8 >= 0 );
    }
    minPathArray.m_Size = 0;
    if ( minPathArray.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        minPathArray.m_Memory.m_pMemory = nullptr;
      }
      minPathArray.m_Memory.m_nAllocationCount = 0;
    }
    minPathArray.m_pElements = m_pMemory;
    if ( minPathArray.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068FA0
// Name: protected: void CAI_Navigator::OnNavFailed(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::OnNavFailed(CAI_Navigator *this, int code, BOOL bMovement)
{
  CFmtStrN<256> *v4; // eax
  Activity StoppedActivity; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  CWorld *BlockingEntity; // eax
  CBaseEntity *v8; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  CFmtStrN<256> v11; // [esp+14h] [ebp-10Ch] BYREF

  if ( this->m_pOuter->ShouldFailNav(this: this->m_pOuter, a2: bMovement) )
  {
    CAI_Navigator::OnNavFailed(this, bMovement);
    if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v4 = CFmtStrN<256>::CFmtStrN<256>(
             this: &v11,
             pszFormat: "[Nav] %s",
             "CAI_Navigator::OnNavFailed calling SetActivity(GetStoppedActivity)");
      DevMsg(pAI: this->m_pOuter, pszFormat: v4->m_szBuf);
    }
    StoppedActivity = CAI_BaseNPC::GetStoppedActivity(this: this->m_pOuter);
    this->m_pOuter->SetActivity(this: this->m_pOuter, a2: StoppedActivity);
    this->TaskFail(this, a2: code);
  }
  else
  {
    ++this->m_nNavFailCounter;
    m_pOuter = this->m_pOuter;
    this->m_flLastNavFailTime = gpGlobals->curtime;
    if ( m_pOuter->ShouldBruteForceFailedNav(this: m_pOuter) )
    {
      if ( bMovement )
      {
        this->m_timeBeginFailedSteer = 3.4028235e38;
        BlockingEntity = (CWorld *)CAI_Navigator::GetBlockingEntity(this);
        v8 = BlockingEntity;
        if ( BlockingEntity != nullptr
          && BlockingEntity != g_WorldEntity
          && !BlockingEntity->IsPlayer(this: BlockingEntity)
          && !FClassnameIs(pEntity: v8, szClassname: "func_tracktrain")
          && NPCPhysics_CreateSolver(
               pNPC: this->m_pOuter,
               pPhysicsObject: v8,
               disableCollisions: true,
               separationDuration: 10.0) != nullptr )
        {
          this->m_nNavFailCounter = 0;
        }
        if ( this->m_nNavFailCounter > 0 && CAI_Navigator::TeleportAlongPath(this) != 0 )
          this->m_nNavFailCounter = 0;
      }
      else
      {
        m_Index = this->m_pMoveProbe->m_hLastBlockingEnt.m_Index;
        if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          if ( m_pEntity != nullptr
            && NPCPhysics_CreateSolver(
                 pNPC: this->m_pOuter,
                 pPhysicsObject: m_pEntity,
                 disableCollisions: true,
                 separationDuration: 10.0) != nullptr )
          {
            this->m_nNavFailCounter = 0;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069150
// Name: private: bool CAI_Navigator::FindPath(bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::FindPath(CAI_Navigator *this, bool fSignalTaskStatus, bool bDontIgnoreBadLinks)
{
  float curtime; // xmm0_4
  char v5; // bl
  CFmtStrN<256> *v7; // eax
  bool Path; // al
  CFmtStrN<256> v9; // [esp+8h] [ebp-110h] BYREF

  if ( (this->m_pOuter->m_afMemory & 0x20) == 0 || this->m_timePathRebuildMax == 0.0 )
  {
    v5 = 0;
  }
  else
  {
    curtime = gpGlobals->curtime;
    v5 = 1;
    if ( curtime > this->m_timePathRebuildFail )
    {
      if ( fSignalTaskStatus )
      {
LABEL_5:
        CAI_Navigator::OnNavFailed(this, code: 11, bMovement: false);
        return 0;
      }
      goto LABEL_7;
    }
    if ( this->m_timePathRebuildNext > curtime )
      return 0;
  }
  Path = CAI_Navigator::DoFindPath(this);
  if ( bDontIgnoreBadLinks )
    goto LABEL_16;
  if ( !Path )
  {
    if ( !this->m_pOuter->IsNavigationUrgent(this: this->m_pOuter) )
    {
LABEL_20:
      if ( this->m_timePathRebuildMax == 0.0 )
      {
        if ( fSignalTaskStatus )
          goto LABEL_5;
LABEL_7:
        if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
        {
          v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "[Nav] %s", "Nav failed\n");
          DevMsg(pAI: this->m_pOuter, pszFormat: v7->m_szBuf);
        }
        CAI_Navigator::ResetCalculations(this);
        *(_WORD *)&this->m_fNavComplete = 257;
        return 0;
      }
      if ( v5 == 0 )
      {
        this->m_pOuter->m_afMemory |= 0x20u;
        this->m_timePathRebuildFail = gpGlobals->curtime + this->m_timePathRebuildMax;
      }
      this->m_timePathRebuildNext = gpGlobals->curtime + this->m_timePathRebuildDelay;
      return 0;
    }
    this->m_pOuter->m_pPathfinder->m_bIgnoreStaleLinks = true;
    Path = CAI_Navigator::DoFindPath(this);
LABEL_16:
    if ( Path )
      goto LABEL_17;
    goto LABEL_20;
  }
LABEL_17:
  this->m_pOuter->m_afMemory &= ~0x20u;
  if ( fSignalTaskStatus )
    this->TaskComplete(this, a2: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10069450
// Name: private: bool CAI_Navigator::FindPath(struct AI_NavGoal_t const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::FindPath(CAI_Navigator *this, CBaseEntity *goal, char flags)
{
  CAI_BaseNPC *m_pOuter; // eax
  CAI_Path *m_pPath; // esi
  float v7; // xmm0_4
  double v8; // st7
  GoalType_t v9; // eax
  const Vector *NodePos; // eax
  unsigned int m_Index; // eax
  float v12; // xmm0_4
  char Path; // bl
  CAI_BaseNPC *v15; // edi
  const Vector *v16; // eax
  Vector v17; // [esp+Ch] [ebp-10h] BYREF
  CAI_Navigator *v18; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF
  CBaseEntity *pPathTarget; // [esp+24h] [ebp+8h]

  m_pOuter = this->m_pOuter;
  m_pPath = this->m_pPath;
  v18 = this;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  if ( (flags & 1) != 0 )
  {
    CAI_Path::Clear(this: m_pPath);
  }
  else if ( (flags & 2) != 0 )
  {
    m_pPath->m_target.m_Index = -1;
    m_pPath->m_vecTargetOffset = vec3_origin;
  }
  if ( goal->m_Network.m_pOuter == (CBaseEntity *)-1 )
  {
    if ( m_pPath->m_activity == ACT_INVALID )
      CAI_Path::SetMovementActivity(
        this: m_pPath,
        activity: (Activity)(4 * (this->m_pOuter->m_NPCState == NPC_STATE_COMBAT) + 6));
  }
  else
  {
    CAI_Path::SetMovementActivity(this: m_pPath, activity: (Activity)goal->m_Network.m_pOuter);
  }
  v7 = *(float *)&goal->m_Network.m_PVSInfo.m_pClusters;
  if ( v7 == -2.0 )
  {
    v8 = NAI_Hull::Width(id: this->m_pOuter->m_eHull);
LABEL_17:
    m_pPath->m_goalTolerance = v8;
    goto LABEL_18;
  }
  if ( v7 != -1.0 )
  {
    m_pPath->m_goalTolerance = v7;
    goto LABEL_18;
  }
  if ( m_pPath->m_goalTolerance == 0.0 )
  {
    v8 = ((double (__thiscall *)(CAI_BaseNPC *))this->m_pOuter->GetDefaultNavGoalTolerance)(a1: this->m_pOuter);
    goto LABEL_17;
  }
LABEL_18:
  if ( m_pPath->m_goalTolerance < 0.1 )
    DevMsg(pAI: this->m_pOuter, pszFormat: "Suspicious navigation goal tolerance specified\n");
  m_pPath->m_waypointTolerance = NAI_Hull::Width(id: this->m_pOuter->m_eHull) * 0.5;
  CAI_Path::SetGoalType(this: m_pPath, goalType: GOALTYPE_NONE);
  CAI_Path::SetGoalType(this: m_pPath, goalType: (GoalType_t)goal->__vftable);
  m_pPath->m_goalFlags = LODWORD(goal->m_Network.m_PVSInfo.m_vCenter[0]);
  v9 = (GoalType_t)goal->__vftable;
  pPathTarget = (CBaseEntity *)LODWORD(goal->m_Network.m_PVSInfo.m_vCenter[1]);
  if ( goal->__vftable == (CBaseEntity_vtbl *)1 )
  {
    m_Index = this->m_pOuter->m_hTargetEnt.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      pPathTarget = nullptr;
    else
      pPathTarget = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  else
  {
    if ( v9 != GOALTYPE_ENEMY )
    {
      if ( AIN_NO_DEST.x == *(float *)&goal->m_pfnMoveDone
        && AIN_NO_DEST.y == *(float *)&goal->m_pfnThink
        && AIN_NO_DEST.z == *(float *)&goal->m_Network.__vftable )
      {
        if ( goal->m_Network.__vftable != (IEventRegisterCallback_vtbl *)-1 )
        {
          NodePos = CAI_Navigator::GetNodePos(this, result: &v17, node: (AI_PathNode_t__ *)goal->m_Network.__vftable);
          CAI_Path::ResetGoalPosition(this: m_pPath, goalPos: NodePos);
        }
      }
      else
      {
        CAI_Path::ResetGoalPosition(this: m_pPath, goalPos: (const Vector *)&goal->m_pfnMoveDone);
      }
      goto LABEL_37;
    }
    pPathTarget = this->m_pOuter->GetEnemy_2(this: this->m_pOuter);
  }
  v12 = *(float *)&goal->m_pfnMoveDone;
  if ( AIN_NO_DEST.x != v12
    || AIN_NO_DEST.y != *(float *)&goal->m_pfnThink
    || AIN_NO_DEST.z != *(float *)&goal->m_Network.__vftable )
  {
    m_pPath->m_vecTargetOffset.x = v12;
    m_pPath->m_vecTargetOffset.y = *(float *)&goal->m_pfnThink;
    m_pPath->m_vecTargetOffset.z = *(float *)&goal->m_Network.__vftable;
  }
LABEL_37:
  if ( pPathTarget > AIN_DEF_TARGET_31 )
  {
    if ( pPathTarget != nullptr )
      m_pPath->m_target.m_Index = *(_DWORD *)((int (*)(void))pPathTarget->GetRefEHandle)();
    else
      m_pPath->m_target.m_Index = -1;
  }
  CAI_WaypointList::RemoveAll(this: &m_pPath->m_Waypoints);
  m_pPath->m_iLastNodeReached = -1;
  Path = CAI_Navigator::FindPath(this, fSignalTaskStatus: (flags & 8) == 0, bDontIgnoreBadLinks: false);
  if ( Path != 0 )
  {
    if ( (int)goal->m_Network.m_pPev <= 0 )
    {
      if ( *(_DWORD *)&goal->m_Network.m_PVSInfo.m_nHeadNode != -1 )
        CAI_Path::SetArrivalSequence(this: m_pPath, sequence: *(_DWORD *)&goal->m_Network.m_PVSInfo.m_nHeadNode);
    }
    else
    {
      CAI_Path::SetArrivalActivity(this: m_pPath, activity: (Activity)goal->m_Network.m_pPev);
    }
    if ( goal->__vftable == (CBaseEntity_vtbl *)2 )
    {
      CAI_Path::SetGoalDirection(this: m_pPath, pTarget: pPathTarget);
      CAI_Path::SetGoalSpeed(this: m_pPath, pTarget: pPathTarget);
      return Path;
    }
    else
    {
      v15 = v18->m_pOuter;
      if ( (v15->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v18->m_pOuter, a2: (int)&savedregs);
      v16 = CAI_Path::ActualGoalPosition(this: m_pPath);
      v17.x = v16->x - v15->m_vecAbsOrigin.x;
      v17.y = v16->y - v15->m_vecAbsOrigin.y;
      v17.z = v16->z - v15->m_vecAbsOrigin.z;
      CAI_Path::SetGoalDirection(this: m_pPath, goalDirection: &v17);
      return Path;
    }
  }
  else
  {
    if ( (flags & 4) != 0 )
      CAI_Path::Clear(this: m_pPath);
    else
      CAI_Path::SetGoalType(this: m_pPath, goalType: GOALTYPE_NONE);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100697E0
// Name: public: virtual bool CAI_Navigator::SetGoal(struct AI_NavGoal_t const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::SetGoal(CAI_Navigator *this, const AI_NavGoal_t *goal, unsigned int flags)
{
  CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v4; // eax
  CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *v5; // eax
  CPostFrameNavigationHook *v6; // eax
  CAI_Navigator_vtbl *v8; // edx
  unsigned int v9; // ebx
  const AI_NavGoal_t *v10; // ebx
  ConVar *m_pParent; // eax
  CFmtStrN<256> *v12; // eax
  CFmtStrN<256> *v13; // eax
  CFmtStrN<256> *v14; // eax
  char *v15; // eax
  CFmtStrN<256> *v16; // eax
  CFmtStrN<256> *v17; // eax
  CFmtStrN<256> *v18; // eax
  CFmtStrN<256> *v19; // eax
  CFmtStrN<256> *v20; // eax
  CFmtStrN<256> *v21; // eax
  CFmtStrN<256> *v22; // eax
  CFmtStrN<256> *v23; // eax
  CFmtStrN<256> *v24; // eax
  char *m_szBuf; // eax
  CFmtStrN<256> *v26; // eax
  CFmtStrN<256> *v27; // eax
  CFmtStrN<256> *v28; // eax
  CFmtStrN<256> *v29; // eax
  CFmtStrN<256> *v30; // eax
  CFmtStrN<256> *v31; // eax
  CFmtStrN<256> *v32; // eax
  CFmtStrN<256> *v33; // eax
  CFmtStrN<256> *v34; // eax
  CFmtStrN<256> *v35; // eax
  const char *ActivityName; // eax
  CFmtStrN<256> *v37; // eax
  CFmtStrN<256> *v38; // eax
  Activity ArrivalActivity; // eax
  const char *v40; // eax
  CFmtStrN<256> *v41; // eax
  CFmtStrN<256> *v42; // eax
  int ArrivalSequence; // eax
  CFmtStrN<256> *v44; // eax
  CFmtStrN<256> *v45; // eax
  CAI_BaseNPC *m_pOuter; // edi
  Vector *GoalDirection; // ecx
  char *v48; // eax
  CAI_BaseNPC *v49; // ecx
  unsigned int v50; // eax
  CAI_BaseNPC *v51; // ebx
  unsigned int v52; // edx
  CAI_BaseNPC *v53; // edi
  unsigned int v54; // ecx
  Vector *v55; // edi
  Vector *v56; // eax
  CFmtStrN<256> *v57; // eax
  CFmtStrN<256> *v58; // eax
  CFmtStrN<256> *v59; // eax
  CAI_Motor *m_pMotor; // edi
  const Vector *v61; // eax
  CAI_BaseNPC *noise; // [esp+10h] [ebp-3A8h]
  double noisea; // [esp+10h] [ebp-3A8h]
  CFunctor *noise_4; // [esp+14h] [ebp-3A4h]
  char noise_4a; // [esp+14h] [ebp-3A4h]
  CFmtStrN<256> v66; // [esp+24h] [ebp-394h] BYREF
  CFmtStrN<256> v67; // [esp+130h] [ebp-288h] BYREF
  CFmtStrN<256> v68; // [esp+23Ch] [ebp-17Ch] BYREF
  Vector v69; // [esp+348h] [ebp-70h] BYREF
  Vector v70; // [esp+354h] [ebp-64h] BYREF
  Vector v71; // [esp+360h] [ebp-58h] BYREF
  Vector v72; // [esp+36Ch] [ebp-4Ch] BYREF
  AI_NavGoal_t arg1; // [esp+378h] [ebp-40h] BYREF
  CAI_Path *m_pPath; // [esp+3A8h] [ebp-10h]
  CAI_Path *pPath; // [esp+3ACh] [ebp-Ch]
  CAI_Path *v76; // [esp+3B0h] [ebp-8h]
  bool Path; // [esp+3B7h] [ebp-1h]
  int savedregs; // [esp+3B8h] [ebp+0h] BYREF

  if ( PostFrameNavigationSystem()->m_bGameFrameRunning )
  {
    arg1 = *goal;
    v4 = (CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)operator new(nSize: 0x58u);
    if ( v4 != nullptr )
      v5 = CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::CMemberFunctor2<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(AI_NavGoal_t const &,unsigned int),AI_NavGoal_t,unsigned int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>(
             this: v4,
             pObject: this,
             pfnProxied: (bool (__thiscall *__ptr64)(CAI_Navigator *, const AI_NavGoal_t *, unsigned int))(unsigned int) __thiscall IGameSystem::`vcall'{20,{flat}},
             &arg1,
             arg2: &flags);
    else
      v5 = nullptr;
    noise_4 = v5;
    noise = this->m_pOuter;
    v6 = PostFrameNavigationSystem();
    CPostFrameNavigationHook::EnqueueEntityNavigationQuery(this: v6, pNPC: noise, pFunctor: noise_4);
    if ( (flags & 8) == 0 || this->m_pOuter->IsCurTaskContinuousMove(this: this->m_pOuter) )
      this->TaskComplete(this, a2: false);
    return 1;
  }
  else
  {
    v8 = this->CAI_Component::__vftable;
    pPath = this->m_pPath;
    v8->OnNewGoal(this);
    v9 = flags;
    if ( (flags & 1) != 0 )
      CAI_Navigator::ClearPath(this);
    if ( this->m_pOuter->IsCurTaskContinuousMove(this: this->m_pOuter)
      || ai_post_frame_navigation.m_pParent != nullptr && ai_post_frame_navigation.m_pParent->m_Value.m_nValue != 0 )
    {
      v9 |= 8u;
      flags = v9;
    }
    noise_4a = v9;
    v10 = goal;
    Path = CAI_Navigator::FindPath(this, (CBaseEntity *)goal, flags: noise_4a);
    m_pParent = ai_debug_nav.m_pParent;
    if ( Path )
    {
      if ( ai_debug_nav.m_pParent != nullptr )
      {
        if ( ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
        {
          v22 = CFmtStrN<256>::CFmtStrN<256>(this: &v68, pszFormat: "[Nav] %s", "New goal set:\n");
          DevMsg(pAI: this->m_pOuter, pszFormat: v22->m_szBuf);
          m_pParent = ai_debug_nav.m_pParent;
        }
        if ( m_pParent != nullptr )
        {
          if ( m_pParent->m_Value.m_nValue != 0 )
          {
            v23 = CFmtStrN<256>::CFmtStrN<256>(
                    this: &v68,
                    pszFormat: "   Type:         %s\n",
                    g_ppszGoalTypes[goal->type]);
            v24 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v23->m_szBuf);
            DevMsg(pAI: this->m_pOuter, pszFormat: v24->m_szBuf);
            m_pParent = ai_debug_nav.m_pParent;
          }
          if ( m_pParent != nullptr )
          {
            if ( m_pParent->m_Value.m_nValue != 0 )
            {
              if ( AIN_NO_DEST.x == goal->dest.x && AIN_NO_DEST.y == goal->dest.y && AIN_NO_DEST.z == goal->dest.z )
                m_szBuf = "AIN_NO_DEST";
              else
                m_szBuf = CFmtStrN<256>::CFmtStrN<256>(
                            this: &v68,
                            pszFormat: "(%f, %f, %f)",
                            goal->dest.x,
                            goal->dest.y,
                            goal->dest.z)->m_szBuf;
              v26 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "   Dest:         %s\n", m_szBuf);
              v27 = CFmtStrN<256>::CFmtStrN<256>(this: &v66, pszFormat: "[Nav] %s", v26->m_szBuf);
              DevMsg(pAI: this->m_pOuter, pszFormat: v27->m_szBuf);
              m_pParent = ai_debug_nav.m_pParent;
            }
            if ( m_pParent != nullptr )
            {
              if ( m_pParent->m_Value.m_nValue != 0 )
              {
                v28 = CFmtStrN<256>::CFmtStrN<256>(this: &v68, pszFormat: "   Dest node:    %d\n", goal->destNode);
                v29 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v28->m_szBuf);
                DevMsg(pAI: this->m_pOuter, pszFormat: v29->m_szBuf);
                m_pParent = ai_debug_nav.m_pParent;
              }
              if ( m_pParent != nullptr )
              {
                if ( m_pParent->m_Value.m_nValue != 0 )
                {
                  v30 = CFmtStrN<256>::CFmtStrN<256>(this: &v68, pszFormat: "   Target:       %#x\n", goal->pTarget);
                  v31 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v30->m_szBuf);
                  DevMsg(pAI: this->m_pOuter, pszFormat: v31->m_szBuf);
                  m_pParent = ai_debug_nav.m_pParent;
                }
                if ( m_pParent != nullptr )
                {
                  if ( m_pParent->m_Value.m_nValue != 0 )
                  {
                    v32 = CFmtStrN<256>::CFmtStrN<256>(
                            this: &v68,
                            pszFormat: "   Tolerance:    %.1f\n",
                            this->m_pPath->m_goalTolerance);
                    v33 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v32->m_szBuf);
                    DevMsg(pAI: this->m_pOuter, pszFormat: v33->m_szBuf);
                    m_pParent = ai_debug_nav.m_pParent;
                  }
                  if ( m_pParent != nullptr )
                  {
                    if ( m_pParent->m_Value.m_nValue != 0 )
                    {
                      v34 = CFmtStrN<256>::CFmtStrN<256>(
                              this: &v68,
                              pszFormat: "   Waypoint tol: %.1f\n",
                              this->m_pPath->m_waypointTolerance);
                      v35 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v34->m_szBuf);
                      DevMsg(pAI: this->m_pOuter, pszFormat: v35->m_szBuf);
                      m_pParent = ai_debug_nav.m_pParent;
                    }
                    if ( m_pParent != nullptr )
                    {
                      if ( m_pParent->m_Value.m_nValue != 0 )
                      {
                        ActivityName = CAI_BaseNPC::GetActivityName(actID: this->m_pPath->m_activity);
                        v37 = CFmtStrN<256>::CFmtStrN<256>(this: &v68, pszFormat: "   Activity:     %s\n", ActivityName);
                        v38 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v37->m_szBuf);
                        DevMsg(pAI: this->m_pOuter, pszFormat: v38->m_szBuf);
                        m_pParent = ai_debug_nav.m_pParent;
                      }
                      if ( m_pParent != nullptr )
                      {
                        if ( m_pParent->m_Value.m_nValue != 0 )
                        {
                          ArrivalActivity = CAI_Path::GetArrivalActivity(this: this->m_pPath);
                          v40 = CAI_BaseNPC::GetActivityName(actID: ArrivalActivity);
                          v41 = CFmtStrN<256>::CFmtStrN<256>(this: &v68, pszFormat: "   Arrival act:  %s\n", v40);
                          v42 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v41->m_szBuf);
                          DevMsg(pAI: this->m_pOuter, pszFormat: v42->m_szBuf);
                          m_pParent = ai_debug_nav.m_pParent;
                        }
                        if ( m_pParent != nullptr )
                        {
                          if ( m_pParent->m_Value.m_nValue != 0 )
                          {
                            ArrivalSequence = CAI_Path::GetArrivalSequence(this: this->m_pPath);
                            v44 = CFmtStrN<256>::CFmtStrN<256>(
                                    this: &v68,
                                    pszFormat: "   Arrival seq:  %d\n",
                                    ArrivalSequence);
                            v45 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v44->m_szBuf);
                            DevMsg(pAI: this->m_pOuter, pszFormat: v45->m_szBuf);
                            m_pParent = ai_debug_nav.m_pParent;
                          }
                          if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
                          {
                            m_pOuter = this->m_pOuter;
                            if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
                              CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
                            GoalDirection = CAI_Path::GetGoalDirection(
                                              this: this->m_pPath,
                                              result: &v71,
                                              startPos: &m_pOuter->m_vecAbsOrigin);
                            if ( AIN_NO_DEST.x == GoalDirection->x
                              && AIN_NO_DEST.y == GoalDirection->y
                              && AIN_NO_DEST.z == GoalDirection->z )
                            {
                              v48 = "AIN_NO_DEST";
                            }
                            else
                            {
                              v49 = this->m_pOuter;
                              v50 = (unsigned int)v49->m_iEFlags >> 11;
                              flags = (unsigned int)v49;
                              if ( (v50 & 1) != 0 )
                                CBaseEntity::CalcAbsolutePosition(this: v49, a2: (int)&savedregs);
                              v51 = this->m_pOuter;
                              v52 = (unsigned int)v51->m_iEFlags >> 11;
                              m_pPath = this->m_pPath;
                              if ( (v52 & 1) != 0 )
                                CBaseEntity::CalcAbsolutePosition(this: v51, a2: (int)&savedregs);
                              v53 = this->m_pOuter;
                              v54 = (unsigned int)v53->m_iEFlags >> 11;
                              v76 = this->m_pPath;
                              if ( (v54 & 1) != 0 )
                                CBaseEntity::CalcAbsolutePosition(this: v53, a2: (int)&savedregs);
                              v55 = CAI_Path::GetGoalDirection(
                                      this: this->m_pPath,
                                      result: &v72,
                                      startPos: &v53->m_vecAbsOrigin);
                              noisea = CAI_Path::GetGoalDirection(
                                         this: m_pPath,
                                         result: &v70,
                                         startPos: (const Vector *)(flags + 460))->z;
                              v56 = CAI_Path::GetGoalDirection(this: v76, result: &v69, startPos: &v51->m_vecAbsOrigin);
                              v10 = goal;
                              v48 = CFmtStrN<256>::CFmtStrN<256>(
                                      this: &v68,
                                      pszFormat: "(%f, %f, %f)",
                                      v55->x,
                                      v56->y,
                                      noisea)->m_szBuf;
                            }
                            v57 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "   Goal dir:     %s\n", v48);
                            v58 = CFmtStrN<256>::CFmtStrN<256>(this: &v66, pszFormat: "[Nav] %s", v57->m_szBuf);
                            DevMsg(pAI: this->m_pOuter, pszFormat: v58->m_szBuf);
                            m_pParent = ai_debug_nav.m_pParent;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if ( (v10->flags & 1) != 0 )
      {
        if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
        {
          v59 = CFmtStrN<256>::CFmtStrN<256>(this: &v68, pszFormat: "[Nav] %s", "   Yaw to dest\n");
          DevMsg(pAI: this->m_pOuter, pszFormat: v59->m_szBuf);
        }
        m_pMotor = this->m_pMotor;
        v61 = CAI_Path::ActualGoalPosition(this: pPath);
        CAI_Motor::SetIdealYawToTarget(this: m_pMotor, target: v61, noise: 0.0, offset: 0.0);
      }
      ((void (__thiscall *)(CAI_Navigator *, int, _DWORD))this->SimplifyPath)(
        a1: this,
        a2: 1,
        a3: LODWORD(v10->maxInitialSimplificationDist));
    }
    else
    {
      if ( ai_debug_nav.m_pParent != nullptr )
      {
        if ( ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
        {
          v12 = CFmtStrN<256>::CFmtStrN<256>(this: &v66, pszFormat: "[Nav] %s", "Failed to pathfind to nav goal:\n");
          DevMsg(pAI: this->m_pOuter, pszFormat: v12->m_szBuf);
          m_pParent = ai_debug_nav.m_pParent;
        }
        if ( m_pParent != nullptr )
        {
          if ( m_pParent->m_Value.m_nValue != 0 )
          {
            v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v66, pszFormat: "   Type:      %s\n", g_ppszGoalTypes[goal->type]);
            v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v13->m_szBuf);
            DevMsg(pAI: this->m_pOuter, pszFormat: v14->m_szBuf);
            m_pParent = ai_debug_nav.m_pParent;
          }
          if ( m_pParent != nullptr )
          {
            if ( m_pParent->m_Value.m_nValue != 0 )
            {
              if ( AIN_NO_DEST.x == goal->dest.x && AIN_NO_DEST.y == goal->dest.y && AIN_NO_DEST.z == goal->dest.z )
                v15 = "AIN_NO_DEST";
              else
                v15 = CFmtStrN<256>::CFmtStrN<256>(
                        this: &v67,
                        pszFormat: "(%f, %f, %f)",
                        goal->dest.x,
                        goal->dest.y,
                        goal->dest.z)->m_szBuf;
              v16 = CFmtStrN<256>::CFmtStrN<256>(this: &v66, pszFormat: "   Dest:      %s\n", v15);
              v17 = CFmtStrN<256>::CFmtStrN<256>(this: &v68, pszFormat: "[Nav] %s", v16->m_szBuf);
              DevMsg(pAI: this->m_pOuter, pszFormat: v17->m_szBuf);
              m_pParent = ai_debug_nav.m_pParent;
            }
            if ( m_pParent != nullptr )
            {
              if ( m_pParent->m_Value.m_nValue != 0 )
              {
                v18 = CFmtStrN<256>::CFmtStrN<256>(this: &v68, pszFormat: "   Dest node: %d\n", goal->destNode);
                v19 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v18->m_szBuf);
                DevMsg(pAI: this->m_pOuter, pszFormat: v19->m_szBuf);
                m_pParent = ai_debug_nav.m_pParent;
              }
              if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
              {
                v20 = CFmtStrN<256>::CFmtStrN<256>(this: &v68, pszFormat: "   Target:    %#x\n", goal->pTarget);
                v21 = CFmtStrN<256>::CFmtStrN<256>(this: &v67, pszFormat: "[Nav] %s", v20->m_szBuf);
                DevMsg(pAI: this->m_pOuter, pszFormat: v21->m_szBuf);
              }
            }
          }
        }
      }
      if ( (flags & 4) != 0 )
      {
        CAI_Navigator::ClearPath(this);
        return Path;
      }
    }
    return Path;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A0D0
// Name: public: virtual bool CAI_Navigator::SetGoalTarget(class CBaseEntity __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::SetGoalTarget(CAI_Navigator *this, CBaseEntity *pEntity, const Vector *offset)
{
  CAI_Path *m_pPath; // esi
  bool v5; // al

  this->OnNewGoal(this);
  m_pPath = this->m_pPath;
  m_pPath->m_vecTargetOffset = *offset;
  if ( pEntity != nullptr )
    m_pPath->m_target.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    m_pPath->m_target.m_Index = -1;
  CAI_WaypointList::RemoveAll(this: &m_pPath->m_Waypoints);
  m_pPath->m_iLastNodeReached = -1;
  v5 = this->m_pOuter->IsCurTaskContinuousMove(this: this->m_pOuter);
  return CAI_Navigator::FindPath(this, fSignalTaskStatus: !v5, bDontIgnoreBadLinks: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006A150
// Name: public: bool CAI_Navigator::RefindPathToGoal(bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::RefindPathToGoal(CAI_Navigator *this, bool fSignalTaskStatus, bool bDontIgnoreBadLinks)
{
  return CAI_Navigator::FindPath(this, fSignalTaskStatus, bDontIgnoreBadLinks);
}

//------------------------------------------------------------------------------
// Address: 0x1006A160
// Name: public: bool CAI_Navigator::UpdateGoalPos(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Navigator::UpdateGoalPos(CAI_Navigator *this, const Vector *goalPos)
{
  float z; // eax
  CFunctor *v4; // eax
  CFunctor v5; // xmm0_8
  float v6; // ecx
  CPostFrameNavigationHook *v7; // eax
  CFmtStrN<256> *v9; // eax
  bool v10; // al
  CAI_BaseNPC *m_pOuter; // [esp-Ch] [ebp-12Ch]
  CFunctor *v12; // [esp-8h] [ebp-128h]
  CFmtStrN<256> v13; // [esp+8h] [ebp-118h] BYREF
  CFunctor v14; // [esp+114h] [ebp-Ch]
  float v15; // [esp+11Ch] [ebp-4h]

  if ( !PostFrameNavigationSystem()->m_bGameFrameRunning )
  {
    if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "[Nav] %s", "Updating goal pos\n");
      DevMsg(pAI: this->m_pOuter, pszFormat: v9->m_szBuf);
    }
    if ( this->m_navType == NAV_JUMP )
    {
      DevMsg(a1: "Updating goal pos while jumping!\n");
    }
    else
    {
      CAI_Path::ResetGoalPosition(this: this->m_pPath, goalPos);
      v10 = this->m_pOuter->IsCurTaskContinuousMove(this: this->m_pOuter);
      if ( CAI_Navigator::FindPath(this, fSignalTaskStatus: !v10, bDontIgnoreBadLinks: false) != 0 )
      {
        ((void (__thiscall *)(CAI_Navigator *, int, int))this->SimplifyPath)(a1: this, a2: 1, a3: -1082130432);
        return 1;
      }
    }
    return 0;
  }
  z = goalPos->z;
  v14 = *(CFunctor *)&goalPos->x;
  v15 = z;
  v4 = (CFunctor *)operator new(nSize: 0x30u);
  if ( v4 != nullptr )
  {
    v5 = v14;
    v6 = v15;
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(Vector const &),Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CAI_Navigator *,bool (__thiscall CAI_Navigator::*)(Vector const &),Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)CAI_Navigator::UpdateGoalPos;
    v4[2].m_nUserID = 0;
    v4[3].__vftable = (CFunctor_vtbl *)this;
    v4[4] = v5;
    *(float *)&v4[5].__vftable = v6;
  }
  else
  {
    v4 = nullptr;
  }
  v12 = v4;
  m_pOuter = this->m_pOuter;
  v7 = PostFrameNavigationSystem();
  CPostFrameNavigationHook::EnqueueEntityNavigationQuery(this: v7, pNPC: m_pOuter, pFunctor: v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006A290
// Name: protected: virtual enum AIMoveResult_t CAI_Navigator::MoveClimb(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Navigator::MoveClimb(CAI_Navigator *this)
{
  const Vector *v2; // edi
  CAI_BaseNPC *m_pOuter; // eax
  float v4; // xmm0_4
  CFmtStrN<256> *v5; // eax
  CAI_Path *m_pPath; // ecx
  CAI_Motor_vtbl *v7; // ebx
  double v8; // xmm0_8
  CAI_BaseNPC *v9; // edi
  unsigned int m_nAITraceMask; // ebx
  CAI_MoveProbe *m_pMoveProbe; // ecx
  float v12; // xmm0_4
  float z; // xmm1_4
  const CBaseEntity *NavTargetEntity; // eax
  CAI_BaseNPC *v15; // eax
  CAI_BaseNPC *v16; // edi
  const Vector *v17; // eax
  CAI_BaseNPC *v18; // ecx
  bool v19; // bl
  CFmtStrN<256> *v20; // eax
  CAI_Path *v22; // ecx
  AI_Waypoint_t *m_pFirstWaypoint; // eax
  int i; // edx
  CAI_Motor *v25; // edi
  CAI_Motor_vtbl *v26; // ebx
  int v27; // eax
  int v28; // edi
  CAI_Path *v29; // ecx
  CFmtStrN<256> *v30; // eax
  CFmtStrN<256> *v31; // eax
  float v32; // [esp+14h] [ebp-17Ch]
  float v33; // [esp+18h] [ebp-178h]
  int v34; // [esp+18h] [ebp-178h]
  CFmtStrN<256> v35; // [esp+28h] [ebp-168h] BYREF
  AIMoveTrace_t moveTrace; // [esp+134h] [ebp-5Ch] BYREF
  const Vector *climbDest; // [esp+16Ch] [ebp-24h]
  Vector otherClimbDir; // [esp+170h] [ebp-20h] BYREF
  CAI_MoveProbe *m_pMotor; // [esp+17Ch] [ebp-14h]
  float climbDist; // [esp+180h] [ebp-10h]
  Vector climbDir; // [esp+184h] [ebp-Ch] BYREF
  int savedregs; // [esp+190h] [ebp+0h] BYREF

  v2 = CAI_Path::CurWaypointPos(this: this->m_pPath);
  m_pOuter = this->m_pOuter;
  climbDir.x = v2->x - m_pOuter->m_vecOrigin.m_Value.x;
  climbDir.y = v2->y - m_pOuter->m_vecOrigin.m_Value.y;
  v4 = v2->z - m_pOuter->m_vecOrigin.m_Value.z;
  climbDest = v2;
  climbDir.z = v4;
  climbDist = VectorNormalize(vec: &climbDir);
  if ( this->m_navType != NAV_CLIMB )
  {
    if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v35, pszFormat: "[Nav] %s", "Climb start\n");
      DevMsg(pAI: this->m_pOuter, pszFormat: v5->m_szBuf);
    }
    m_pPath = this->m_pPath;
    v7 = this->m_pMotor->__vftable;
    m_pMotor = (CAI_MoveProbe *)this->m_pMotor;
    v33 = CAI_Path::CurWaypointYaw(this: m_pPath);
    ((void (__thiscall *)(CAI_MoveProbe *, const Vector *, Vector *, float, _DWORD))v7->MoveClimbStart)(
      a1: m_pMotor,
      a2: v2,
      a3: &climbDir,
      a4: COERCE_FLOAT(LODWORD(climbDist)),
      a5: LODWORD(v33));
  }
  this->m_navType = NAV_CLIMB;
  memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
  if ( climbDist > 0.01 )
  {
    v8 = climbDist - 0.005;
    if ( v8 > 0.1 )
      v8 = 0.1;
    v9 = this->m_pOuter;
    m_nAITraceMask = v9->m_nAITraceMask;
    m_pMoveProbe = this->m_pMoveProbe;
    v12 = v8;
    otherClimbDir.x = v9->m_vecOrigin.m_Value.x + (float)(v12 * climbDir.x);
    otherClimbDir.y = v9->m_vecOrigin.m_Value.y + (float)(climbDir.y * v12);
    z = v9->m_vecOrigin.m_Value.z;
    m_pMotor = m_pMoveProbe;
    otherClimbDir.z = z + (float)(v12 * climbDir.z);
    NavTargetEntity = CAI_Navigator::GetNavTargetEntity(this);
    if ( !CAI_MoveProbe::MoveLimit(
            this: m_pMotor,
            a2: (int)&savedregs,
            navType: NAV_CLIMB,
            vecStart: &v9->m_vecOrigin.m_Value,
            vecEnd: &otherClimbDir,
            collisionMask: m_nAITraceMask,
            pTarget: NavTargetEntity,
            pctToCheckStandPositions: 100.0,
            flags: 0,
            pTrace: &moveTrace)
      && moveTrace.pObstruction != nullptr )
    {
      v15 = moveTrace.pObstruction->MyNPCPointer(this: moveTrace.pObstruction);
      v16 = v15;
      if ( v15 != nullptr )
      {
        if ( !v15->IsMoving(this: v15) )
          goto LABEL_18;
        if ( CAI_BaseNPC::GetNavType(this: v16) == NAV_CLIMB && climbDir.z <= 0.01 )
        {
          v17 = CAI_Path::CurWaypointPos(this: v16->m_pNavigator->m_pPath);
          otherClimbDir.x = v17->x - v16->m_vecOrigin.m_Value.x;
          otherClimbDir.y = v17->y - v16->m_vecOrigin.m_Value.y;
          otherClimbDir.z = v17->z - v16->m_vecOrigin.m_Value.z;
          VectorNormalize(vec: &otherClimbDir);
          if ( (float)((float)((float)(otherClimbDir.y * climbDir.y) + (float)(otherClimbDir.x * climbDir.x))
                     + (float)(otherClimbDir.z * climbDir.z)) < 0.0 )
          {
            if ( !v16->m_pNavigator->GetStoppingPath(this: v16->m_pNavigator, a2: this->m_pClippedWaypoints)
              || (v18 = this->m_pOuter,
                  this->m_flTimeClipped = gpGlobals->curtime,
                  this->m_navType = NAV_GROUND,
                  v18->m_flGravity = 1.0,
                  v19 = CAI_Navigator::FindPath(this, fSignalTaskStatus: false, bDontIgnoreBadLinks: false) == 0,
                  this->m_pOuter->m_flGravity = 0.0,
                  this->m_navType = NAV_CLIMB,
                  v19) )
            {
LABEL_18:
              if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
              {
                v20 = CFmtStrN<256>::CFmtStrN<256>(this: &v35, pszFormat: "[Nav] %s", "Climb fail\n");
                DevMsg(pAI: this->m_pOuter, pszFormat: v20->m_szBuf);
              }
              this->m_pMotor->MoveClimbStop(this: this->m_pMotor);
              this->m_navType = NAV_GROUND;
              return -3;
            }
          }
        }
      }
    }
  }
  v22 = this->m_pPath;
  m_pFirstWaypoint = v22->m_Waypoints.m_pFirstWaypoint;
  for ( i = 0; m_pFirstWaypoint != nullptr; ++i )
  {
    if ( m_pFirstWaypoint->m_iWPType != NAV_CLIMB )
      break;
    m_pFirstWaypoint = m_pFirstWaypoint->pNext;
  }
  v25 = this->m_pMotor;
  v26 = v25->CAI_Component::__vftable;
  v34 = i;
  v32 = CAI_Path::CurWaypointYaw(this: v22);
  v27 = ((int (__thiscall *)(CAI_Motor *, const Vector *, Vector *, float, _DWORD, int))v26->MoveClimbExecute)(
          a1: v25,
          a2: climbDest,
          a3: &climbDir,
          a4: COERCE_FLOAT(LODWORD(climbDist)),
          a5: LODWORD(v32),
          a6: v34);
  v28 = v27;
  if ( v27 != 1 )
  {
    if ( v27 != 0 )
    {
      if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
      {
        v31 = CFmtStrN<256>::CFmtStrN<256>(this: &v35, pszFormat: "[Nav] %s", "Climb fail (2)\n");
        DevMsg(pAI: this->m_pOuter, pszFormat: v31->m_szBuf);
      }
      this->m_pMotor->MoveClimbStop(this: this->m_pMotor);
      this->m_navType = NAV_GROUND;
    }
    return v28;
  }
  if ( this->m_pPath->m_Waypoints.m_pFirstWaypoint->pNext != nullptr )
    CAI_Navigator::AdvancePath(this);
  else
    this->OnNavComplete(this);
  v29 = this->m_pPath;
  if ( v29->m_Waypoints.m_pFirstWaypoint != nullptr
    && v29->m_Waypoints.m_pFirstWaypoint->pNext != nullptr
    && CAI_Path::CurWaypointNavType(this: v29) == NAV_CLIMB )
  {
    return v28;
  }
  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v30 = CFmtStrN<256>::CFmtStrN<256>(this: &v35, pszFormat: "[Nav] %s", "Climb stop\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v30->m_szBuf);
  }
  this->m_pMotor->MoveClimbStop(this: this->m_pMotor);
  this->m_navType = NAV_GROUND;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006A710
// Name: public: virtual bool CAI_Navigator::Move(float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CAI_Navigator::Move@<al>(CAI_Navigator *this@<ecx>, int a2@<ebx>, int a3@<esi>, float flInterval)
{
  float v4; // xmm0_4
  CAI_Path *m_pPath; // ecx
  bool v8; // zf
  CAI_BaseNPC *m_pOuter; // eax
  bool v10; // dl
  CFmtStrN<256> *v11; // eax
  Activity m_PreviousMoveActivity; // eax
  Activity v13; // eax
  int v14; // eax
  AIMoveResult_t v15; // eax
  CAI_Motor *m_pMotor; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *GroundEntity; // eax
  unsigned int v19; // ecx
  IHandleEntity *m_pEntity; // edx
  const char *DebugName; // eax
  CAI_Path *v22; // ecx
  Navigation_t v23; // eax
  __int32 v24; // eax
  Navigation_t m_navType; // eax
  CAI_Path *v26; // ecx
  AI_Waypoint_t *m_pFirstWaypoint; // edi
  CFmtStrN<256> v29; // [esp+8h] [ebp-114h] BYREF
  int nLoopCount; // [esp+114h] [ebp-8h]
  AIMoveResult_t moveResult; // [esp+118h] [ebp-4h] BYREF
  char bMoved_3; // [esp+127h] [ebp+Bh]

  v4 = flInterval;
  if ( flInterval > 1.0 )
  {
    v4 = 1.0;
    flInterval = 1.0;
  }
  if ( ((unsigned __int8 (__cdecl *)(_DWORD, int))this->m_pOuter->OverrideMove)(a1: LODWORD(v4), a2: a3) != 0 )
    return 1;
  m_pPath = this->m_pPath;
  nLoopCount = a2;
  v8 = CBaseAchievement::GetNumComponents(this: (vgui::Panel *)m_pPath) == 0;
  m_pOuter = this->m_pOuter;
  v10 = (m_pOuter->m_afMemory & 0x2000) != 0;
  LOBYTE(nLoopCount) = !v8;
  if ( v8 )
  {
    this->m_PreviousMoveActivity = ACT_RESET;
    this->m_PreviousArrivalActivity = ACT_RESET;
  }
  else
  {
    if ( v10 && (float)(gpGlobals->curtime - this->m_pPath->m_routeStartTime) > 5.0 )
    {
      m_pOuter->m_afMemory &= ~0x2000u;
      if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
      {
        v11 = CFmtStrN<256>::CFmtStrN<256>(
                this: &v29,
                pszFormat: "[Nav] %s",
                "NPC appears stuck turning. Proceeding.\n");
        DevMsg(pAI: this->m_pOuter, pszFormat: v11->m_szBuf);
      }
    }
    m_PreviousMoveActivity = this->m_PreviousMoveActivity;
    if ( m_PreviousMoveActivity > ACT_IDLE && this->m_pPath->m_activity <= ACT_IDLE )
    {
      v13 = CAI_BaseNPC::TranslateActivity(
              this: this->m_pOuter,
              idealActivity: m_PreviousMoveActivity,
              pIdealWeaponActivity: nullptr);
      CAI_Path::SetMovementActivity(this: this->m_pPath, activity: v13);
    }
  }
  if ( !this->ShouldMove(this, a2: nLoopCount) )
  {
    if ( this->m_navType == NAV_CLIMB )
    {
      this->m_pMotor->MoveClimbStop(this: this->m_pMotor);
      this->m_navType = NAV_GROUND;
    }
    this->m_pMotor->MoveStop(this: this->m_pMotor);
    return 0;
  }
  this->m_pMotor->m_flMoveInterval = flInterval;
  if ( CBaseAchievement::GetNumComponents(this: (vgui::Panel *)this->m_pPath) == 0 )
  {
    DevWarning(a1: "Move requested with no route!\n");
    v14 = 1;
LABEL_21:
    CAI_Navigator::OnNavFailed(this, code: failures[v14], bMovement: false);
    return 0;
  }
  if ( this->m_pPath->m_Waypoints.m_pFirstWaypoint == nullptr )
  {
    DevWarning(a1: "Move goal with no route!\n");
    CAI_Path::Clear(this: this->m_pPath);
    v14 = 2;
    goto LABEL_21;
  }
  if ( CAI_BaseNPC::ShouldMoveWait(this: this->m_pOuter) )
  {
    this->m_pMotor->MovePaused(this: this->m_pMotor);
    return 0;
  }
  else
  {
    v15 = AIMR_CHANGE_TYPE;
    nLoopCount = 0;
    bMoved_3 = 0;
    moveResult = AIMR_CHANGE_TYPE;
    this->m_fNavComplete = false;
    while ( !this->m_fNavComplete )
    {
      m_pMotor = this->m_pMotor;
      if ( m_pMotor->m_flMoveInterval <= 0.0 )
        return bMoved_3;
      if ( !this->m_bCalledStartMove )
      {
        m_pMotor->MoveStart(this: m_pMotor);
        this->m_bCalledStartMove = true;
      }
      m_Index = this->m_hBigStepGroundEnt.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        GroundEntity = CBaseEntity::GetGroundEntity(this: this->m_pOuter);
        v19 = this->m_hBigStepGroundEnt.m_Index;
        if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
        if ( m_pEntity != GroundEntity )
          this->m_hBigStepGroundEnt.m_Index = -1;
      }
      switch ( CAI_Path::CurWaypointNavType(this: this->m_pPath) )
      {
        case NAV_GROUND:
        case NAV_FLY:
          v15 = this->MoveNormal(this);
          goto LABEL_42;
        case NAV_JUMP:
          v15 = this->MoveJump(this);
          goto LABEL_42;
        case NAV_CLIMB:
          v15 = this->MoveClimb(this);
          goto LABEL_42;
        case NAV_CRAWL:
          v15 = this->MoveCrawl(this);
LABEL_42:
          moveResult = v15;
          if ( v15 == AIMR_OK )
            bMoved_3 = 1;
          break;
        default:
          DevMsg(a1: "Bogus route move type!");
          v15 = AIMR_ILLEGAL;
          moveResult = AIMR_ILLEGAL;
          break;
      }
      if ( ++nLoopCount > 16 )
      {
        DebugName = CBaseEntity::GetDebugName(this: this->m_pOuter);
        DevMsg(a1: "ERROR: %s navigation not terminating. Possibly bad cyclical solving?\n", DebugName);
        v22 = this->m_pPath;
        moveResult = AIMR_ILLEGAL;
        v23 = CAI_Path::CurWaypointNavType(this: v22);
        if ( v23 == NAV_GROUND || (v24 = v23 - 2) == 0 || v24 == 2 )
          this->OnMoveBlocked(this: &this->CAI_DefMovementSink, a2: &moveResult);
        v15 = moveResult;
        break;
      }
      if ( v15 < AIMR_OK )
        goto LABEL_57;
    }
    if ( v15 >= AIMR_OK )
      return bMoved_3;
LABEL_57:
    if ( (v15 != AIMR_BLOCKED_NPC
       || (m_navType = this->m_navType) == NAV_CLIMB
       || m_navType == NAV_JUMP
       || CAI_Path::CurWaypointNavType(this: this->m_pPath) == NAV_JUMP)
      && this->MarkCurWaypointFailedLink(this) )
    {
      v26 = this->m_pPath;
      m_pFirstWaypoint = v26->m_Waypoints.m_pFirstWaypoint;
      if ( v26->m_Waypoints.m_pFirstWaypoint != nullptr )
      {
        CAI_Path::SetWaypoints(this: v26, route: nullptr, fSetGoalFromLast: false);
        if ( CAI_Navigator::FindPath(this, fSignalTaskStatus: false, bDontIgnoreBadLinks: true) != 0 )
        {
          DeleteAll(pWaypointList: m_pFirstWaypoint);
          return bMoved_3;
        }
        CAI_Path::SetWaypoints(this: this->m_pPath, route: m_pFirstWaypoint, fSetGoalFromLast: false);
      }
    }
    CAI_Navigator::OnNavFailed(this, code: (moveResult == AIMR_ILLEGAL) + 13, bMovement: true);
    return bMoved_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FC990
// Name: CAI_Navigator_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Navigator_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Navigator>();
  CAI_Navigator_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FC9A0
// Name: _dynamic_initializer_for__ai_navigator_generate_spikes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_navigator_generate_spikes__()
{
  ConVar::ConVar(
    this: &ai_navigator_generate_spikes,
    pName: "ai_navigator_generate_spikes",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_navigator_generate_spikes__);
}

//------------------------------------------------------------------------------
// Address: 0x103FC9D0
// Name: _dynamic_initializer_for__ai_navigator_generate_spikes_strength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_navigator_generate_spikes_strength__()
{
  ConVar::ConVar(
    this: &ai_navigator_generate_spikes_strength,
    pName: "ai_navigator_generate_spikes_strength",
    pDefaultValue: "8",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_navigator_generate_spikes_strength__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCA00
// Name: _dynamic_initializer_for__ai_use_clipped_paths__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_use_clipped_paths__()
{
  ConVar::ConVar(this: &ai_use_clipped_paths, pName: "ai_use_clipped_paths", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_use_clipped_paths__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCA30
// Name: _dynamic_initializer_for__ai_no_node_cache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_no_node_cache__()
{
  ConVar::ConVar(this: &ai_no_node_cache, pName: "ai_no_node_cache", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_no_node_cache__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCA60
// Name: _dynamic_initializer_for__ai_nav_debug_experimental_pathing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_nav_debug_experimental_pathing__()
{
  ConVar::ConVar(
    this: &ai_nav_debug_experimental_pathing,
    pName: "ai_nav_debug_experimental_pathing",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw paths tried during search for bodysnatcher pathing");
  return atexit(func: dynamic_atexit_destructor_for__ai_nav_debug_experimental_pathing__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCA90
// Name: _dynamic_initializer_for__ai_debug_node_connect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_node_connect_command__()
{
  ConCommand::ConCommand(
    this: &ai_debug_node_connect_command,
    pName: "ai_debug_node_connect",
    callback: ai_debug_node_connect,
    pHelpString: "Debug the attempted connection between two nodes",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_node_connect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCAC0
// Name: _dynamic_initializer_for__g_ai_norebuildgraph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ai_norebuildgraph__()
{
  ConVar::ConVar(this: &g_ai_norebuildgraph, pName: "ai_norebuildgraph", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_ai_norebuildgraph__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCAF0
// Name: _dynamic_initializer_for__g_ai_threadedgraphbuild__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ai_threadedgraphbuild__()
{
  ConVar::ConVar(
    this: &g_ai_threadedgraphbuild,
    pName: "g_ai_threadedgraphbuild",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If true, use experimental threaded node graph building.");
  return atexit(func: dynamic_atexit_destructor_for__g_ai_threadedgraphbuild__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCB20
// Name: _dynamic_initializer_for__ai_network__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_network__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_NetworkManager> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_network,
           a3: "ai_network");
}
