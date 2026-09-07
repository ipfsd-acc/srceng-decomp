// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_basenpc_movement.cpp
// Functions: 24
// ============================================================

#include "game\server\ai_basenpc_movement.h"

//------------------------------------------------------------------------------
// Address: 0x10018540
// Name: public: AI_NavGoal_t::AI_NavGoal_t(enum GoalType_t,class Vector const __near &,enum Activity,float,unsigned int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
AI_NavGoal_t *__thiscall AI_NavGoal_t::AI_NavGoal_t(
        AI_NavGoal_t *this,
        GoalType_t type,
        const Vector *dest,
        Activity activity,
        float tolerance,
        unsigned int flags,
        CBaseEntity *pTarget)
{
  this->type = type;
  this->dest = *dest;
  this->destNode = (AI_PathNode_t__ *)-1;
  this->activity = activity;
  this->arrivalActivity = ACT_INVALID;
  this->arrivalSequence = -1;
  this->tolerance = tolerance;
  this->maxInitialSimplificationDist = -1.0;
  this->flags = flags;
  this->pTarget = pTarget;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002D9D0
// Name: public: virtual bool CBaseEntity::CanStandOn(struct edict_t __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::CanStandOn(CBaseEntity *this, edict_t *ent)
{
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v4; // eax

  if ( ent == nullptr )
    return this->CanStandOn_2(this, a2: nullptr);
  m_pUnk = ent->m_pUnk;
  if ( m_pUnk == nullptr )
    return this->CanStandOn_2(this, a2: nullptr);
  v4 = m_pUnk->GetBaseEntity(this: m_pUnk);
  return this->CanStandOn_2(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10038370
// Name: public: AI_NavGoal_t::AI_NavGoal_t(enum GoalType_t,enum Activity,float,unsigned int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
AI_NavGoal_t *__thiscall AI_NavGoal_t::AI_NavGoal_t(
        AI_NavGoal_t *this,
        GoalType_t type,
        Activity activity,
        float tolerance,
        unsigned int flags,
        CBaseEntity *pTarget)
{
  this->type = type;
  this->dest = AIN_NO_DEST;
  this->destNode = (AI_PathNode_t__ *)-1;
  this->activity = activity;
  this->arrivalActivity = ACT_INVALID;
  this->arrivalSequence = -1;
  this->tolerance = tolerance;
  this->maxInitialSimplificationDist = -1.0;
  this->flags = flags;
  this->pTarget = pTarget;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10038450
// Name: public: AI_NavGoal_t::AI_NavGoal_t(class Vector const __near &,enum Activity,float,unsigned int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
AI_NavGoal_t *__thiscall AI_NavGoal_t::AI_NavGoal_t(
        AI_NavGoal_t *this,
        const Vector *dest,
        Activity activity,
        float tolerance,
        unsigned int flags,
        CBaseEntity *pTarget)
{
  this->type = GOALTYPE_LOCATION;
  this->dest = *dest;
  this->destNode = (AI_PathNode_t__ *)-1;
  this->activity = activity;
  this->arrivalActivity = ACT_INVALID;
  this->arrivalSequence = -1;
  this->tolerance = tolerance;
  this->maxInitialSimplificationDist = -1.0;
  this->flags = flags;
  this->pTarget = pTarget;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100384B0
// Name: public: virtual bool CAI_BaseNPC::IsMoving(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsMoving(CAI_BaseNPC *this)
{
  return CAI_Navigator::IsGoalSet(this: this->m_pNavigator);
}

//------------------------------------------------------------------------------
// Address: 0x100384C0
// Name: public: virtual bool CAI_BaseNPC::IsCurTaskContinuousMove(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsCurTaskContinuousMove(CAI_BaseNPC *this)
{
  const Task_t *Task; // eax
  bool result; // al

  Task = CAI_BaseNPC::GetTask(this);
  if ( Task == nullptr )
    return true;
  switch ( Task->iTask )
  {
    case 0xC:
    case 0xD:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x7A:
    case 0x82:
    case 0x87:
      return true;
    default:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038570
// Name: public: virtual bool CAI_BaseNPC::IsJumpLegal(class Vector const __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsJumpLegal(
        CAI_BaseNPC *this,
        const Vector *startPos,
        const Vector *apex,
        const Vector *endPos)
{
  return ((bool (__thiscall *)(CAI_BaseNPC *, const Vector *, const Vector *, const Vector *, int, int, int))this->IsJumpLegal)(
           a1: this,
           a2: startPos,
           a3: apex,
           a4: endPos,
           a5: 1117782016,
           a6: 1128267776,
           a7: 1132068864);
}

//------------------------------------------------------------------------------
// Address: 0x100385C0
// Name: public: bool CAI_BaseNPC::ShouldMoveWait(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BaseNPC::ShouldMoveWait(CAI_BaseNPC *this)
{
  return this->m_flMoveWaitFinished > gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x100385E0
// Name: public: float CAI_BaseNPC::GetStepDownMultiplier(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::GetStepDownMultiplier(CAI_BaseNPC *this)
{
  return CAI_Navigator::GetStepDownMultiplier(this: this->m_pNavigator);
}

//------------------------------------------------------------------------------
// Address: 0x100385F0
// Name: public: virtual float CAI_BaseNPC::MaxYawSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::MaxYawSpeed(CAI_BaseNPC *this)
{
  return 45.0;
}

//------------------------------------------------------------------------------
// Address: 0x10038600
// Name: public: virtual float CAI_BaseNPC::GetTimeToNavGoal(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::GetTimeToNavGoal(CAI_BaseNPC *this)
{
  double PathDistToGoal; // st7
  double result; // st7
  double v4; // st6
  float flDist; // [esp+4h] [ebp-4h]

  PathDistToGoal = CAI_Navigator::BuildAndGetPathDistToGoal(this: this->m_pNavigator);
  flDist = PathDistToGoal;
  if ( PathDistToGoal < 0.0 )
    return -1.0;
  v4 = ((double (__thiscall *)(CAI_BaseNPC *))this->GetIdealSpeed)(a1: this);
  result = 0.0;
  if ( v4 > 0.0 && flDist > 0.0 )
    return flDist / v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038660
// Name: public: virtual bool CBaseEntity::CanStandOn(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::CanStandOn(CBaseEntity *this, CBaseEntity *pSurface)
{
  bool result; // al

  if ( pSurface == nullptr )
    return true;
  result = CBaseEntity::IsStandable(this: pSurface);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038680
// Name: public: float CBaseEntity::GetMoveDoneTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseEntity::GetMoveDoneTime(CBaseEntity *this)
{
  float m_flMoveDoneTime; // xmm0_4

  m_flMoveDoneTime = this->m_flMoveDoneTime;
  if ( m_flMoveDoneTime < 0.0 )
    return -1.0;
  else
    return (float)(m_flMoveDoneTime - this->m_flLocalTime);
}

//------------------------------------------------------------------------------
// Address: 0x100386C0
// Name: bool FClassnameIs(class CBaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FClassnameIs(CBaseEntity *pEntity, const char *szClassname)
{
  return pEntity != nullptr
      && (pEntity->m_iClassname.pszValue == szClassname
       || CBaseEntity::ClassMatchesComplex(this: pEntity, pszClassOrWildcard: szClassname));
}

//------------------------------------------------------------------------------
// Address: 0x100386F0
// Name: public: virtual bool CAI_BaseNPC::ScheduledMoveToGoalEntity(int,class CBaseEntity __near *,enum Activity)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ScheduledMoveToGoalEntity(
        CAI_BaseNPC *this,
        int scheduleType,
        CBaseEntity *pGoalEntity,
        Activity movementActivity)
{
  float z; // eax
  __int64 v6; // xmm0_8
  CAI_BaseNPC_vtbl *v7; // eax
  void (__thiscall *TranslateNavGoal)(CAI_BaseNPC *, CBaseEntity *, Vector *); // edx
  AI_NavGoal_t goal; // [esp+Ch] [ebp-30h] BYREF

  CAI_BaseNPC::SetPrimaryBehavior(this, pNewBehavior: nullptr);
  if ( this->m_NPCState == NPC_STATE_NONE )
    this->m_NPCState = this->m_IdealNPCState;
  CAI_BaseNPC::SetSchedule(this, localScheduleID: scheduleType);
  if ( pGoalEntity != nullptr )
    this->m_hGoalEnt.m_Index = pGoalEntity->GetRefEHandle(this: pGoalEntity)->m_Index;
  else
    this->m_hGoalEnt.m_Index = -1;
  if ( (pGoalEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pGoalEntity);
  z = pGoalEntity->m_vecAbsOrigin.z;
  v6 = *(_QWORD *)&pGoalEntity->m_vecAbsOrigin.x;
  goal.activity = movementActivity;
  goal.dest.z = z;
  v7 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  *(_QWORD *)&goal.dest.x = v6;
  goal.pTarget = AIN_DEF_TARGET_6;
  TranslateNavGoal = v7->TranslateNavGoal;
  goal.type = GOALTYPE_LOCATION;
  goal.destNode = (AI_PathNode_t__ *)-1;
  goal.arrivalActivity = ACT_INVALID;
  goal.arrivalSequence = -1;
  goal.tolerance = -1.0;
  goal.maxInitialSimplificationDist = -1.0;
  goal.flags = 1;
  TranslateNavGoal(this, a2: pGoalEntity, a3: &goal.dest);
  return this->m_pNavigator->SetGoal(this: this->m_pNavigator, a2: &goal, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100387E0
// Name: public: virtual bool CAI_BaseNPC::IsUnusableNode(int,class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsUnusableNode(CAI_BaseNPC *this, int iNodeID, CAI_Hint *pHint)
{
  const char *pszValue; // eax
  bool result; // al

  result = false;
  if ( this->m_bHintGroupNavLimiting )
  {
    pszValue = this->m_strHintGroup.pszValue;
    if ( pszValue != nullptr && *pszValue != 0 && (pHint == nullptr || pHint->m_NodeData.strGroup.pszValue != pszValue) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038820
// Name: public: virtual bool CAI_BaseNPC::CanStandOn(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::CanStandOn(CAI_BaseNPC *this, CBaseEntity *pSurface)
{
  bool result; // al
  CAI_Navigator *m_pNavigator; // esi

  result = CBaseEntity::IsAIWalkable(this: pSurface)
        && ((m_pNavigator = this->m_pNavigator, !CAI_Navigator::IsGoalActive(this: m_pNavigator))
         || pSurface != CAI_Navigator::GetGoalTarget(this: m_pNavigator))
        && (pSurface == nullptr || CBaseEntity::IsStandable(this: pSurface));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038870
// Name: public: virtual bool CAI_BaseNPC::IsJumpLegal(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float,float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsJumpLegal(
        CAI_BaseNPC *this,
        const Vector *startPos,
        const Vector *apex,
        const Vector *endPos,
        float maxUp,
        float maxDown,
        float maxDist)
{
  float z; // xmm1_4
  float v8; // xmm0_4
  bool result; // al
  float v10; // xmm2_4
  float v11; // xmm1_4

  z = endPos->z;
  v8 = startPos->z;
  result = false;
  if ( (float)(z - v8) <= maxUp + 0.1 )
  {
    v10 = v8 - z;
    if ( (float)(v8 - z) <= maxDown + 0.1 && (float)(apex->z - v8) <= maxUp * 1.25 )
    {
      v11 = startPos->y - endPos->y;
      if ( fsqrt(
             (float)((float)(v11 * v11) + (float)(v10 * v10))
           + (float)((float)(startPos->x - endPos->x) * (float)(startPos->x - endPos->x))) <= maxDist + 0.1 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038970
// Name: public: virtual bool CAI_BaseNPC::ScheduledFollowPath(int,class CBaseEntity __near *,enum Activity)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ScheduledFollowPath(
        CAI_BaseNPC *this,
        int scheduleType,
        CBaseEntity *pPathStart,
        Activity movementActivity)
{
  float z; // edx
  __int64 v6; // xmm0_8
  void (__thiscall *TranslateNavGoal)(CAI_BaseNPC *, CBaseEntity *, Vector *); // edx
  AI_NavGoal_t goal; // [esp+Ch] [ebp-30h] BYREF

  CAI_BaseNPC::SetPrimaryBehavior(this, pNewBehavior: nullptr);
  if ( this->m_NPCState == NPC_STATE_NONE )
    this->m_NPCState = this->m_IdealNPCState;
  CAI_BaseNPC::SetSchedule(this, localScheduleID: scheduleType);
  if ( pPathStart != nullptr )
    this->m_hGoalEnt.m_Index = pPathStart->GetRefEHandle(this: pPathStart)->m_Index;
  else
    this->m_hGoalEnt.m_Index = -1;
  z = pPathStart->m_vecOrigin.m_Value.z;
  v6 = *(_QWORD *)&pPathStart->m_vecOrigin.m_Value.x;
  goal.activity = movementActivity;
  goal.dest.z = z;
  TranslateNavGoal = this->TranslateNavGoal;
  *(_QWORD *)&goal.dest.x = v6;
  goal.pTarget = AIN_DEF_TARGET_6;
  goal.type = GOALTYPE_PATHCORNER;
  goal.destNode = (AI_PathNode_t__ *)-1;
  goal.arrivalActivity = ACT_INVALID;
  goal.arrivalSequence = -1;
  goal.tolerance = -1.0;
  goal.maxInitialSimplificationDist = -1.0;
  goal.flags = 1;
  TranslateNavGoal(this, a2: pPathStart, a3: &goal.dest);
  return this->m_pNavigator->SetGoal(this: this->m_pNavigator, a2: &goal, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10038A40
// Name: public: virtual bool CAI_BaseNPC::ValidateNavGoal(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::ValidateNavGoal(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  CAI_Hint *m_pEntity; // eax
  Activity v4; // edi
  Vector *v5; // eax
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // edx
  int v7; // eax
  CAI_BaseNPC_vtbl *v8; // edi
  int v9; // eax
  _BYTE v11[12]; // [esp+4h] [ebp-24h] BYREF
  Vector vEyePos; // [esp+10h] [ebp-18h] BYREF
  Vector vCoverLocation; // [esp+1Ch] [ebp-Ch] BYREF

  if ( CAI_Navigator::GetGoalType(this: this->m_pNavigator) != GOALTYPE_COVER || this->GetEnemy_2(this) == nullptr )
    return 1;
  m_Index = this->m_pHintNode.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CAI_Hint *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v4 = this->GetCoverActivity(this, a2: m_pEntity);
  vCoverLocation = *CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
  vCoverLocation.z = GetFloorZ(origin: &vCoverLocation);
  v5 = this->EyeOffset(this, result: v11, a3: v4);
  vEyePos.x = v5->x + vCoverLocation.x;
  vEyePos.y = v5->y + vCoverLocation.y;
  GetEnemy_2 = this->GetEnemy_2;
  vEyePos.z = v5->z + vCoverLocation.z;
  v7 = (int)GetEnemy_2(this);
  v8 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  v9 = (*(int (__thiscall **)(int, _BYTE *, Vector *))(*(_DWORD *)v7 + 504))(a1: v7, a2: v11, a3: &vEyePos);
  if ( ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *, int))v8->IsCoverPosition)(a1: this, a2: v9) != 0 )
    return 1;
  this->TaskFail(this, a2: 25);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10038B60
// Name: public: bool CAI_BaseNPC::AutoMovement(float,class CBaseEntity __near *,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::AutoMovement(
        CAI_BaseNPC *this,
        float flInterval,
        CBaseEntity *pTarget,
        AIMoveTrace_t *pTraceResult)
{
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CAI_ScriptedSequence **v12; // eax
  CAI_ScriptedSequence *v13; // eax
  unsigned __int8 m_Value; // al
  CBaseEntity *NavTargetEntity; // edi
  const Vector *AbsOrigin; // eax
  __int64 v17; // xmm0_8
  float z; // eax
  bool v19; // bl
  const Vector *v20; // eax
  CAI_Motor *m_pMotor; // esi
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  QAngle newAngles; // [esp+20h] [ebp-28h] BYREF
  Vector dist; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector newPos; // [esp+38h] [ebp-10h] BYREF
  bool ignored; // [esp+47h] [ebp-1h] BYREF

  if ( flInterval <= 0.0 )
    return true;
  this->m_ScheduleState.bTaskRanAutomovement = true;
  if ( CBaseAnimating::GetIntervalMovement(
         this,
         flIntervalUsed: flInterval,
         bMoveSeqFinished: &ignored,
         newPosition: &newPos,
         &newAngles) == 0 )
    return false;
  m_Index = this->m_hCine.m_Index;
  if ( m_Index != -1 )
  {
    v7 = (unsigned __int16)m_Index;
    v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v9 = HIWORD(m_Index);
    if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
    {
      v10 = v7;
      v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
      v12 = (CAI_ScriptedSequence **)&g_pEntityList->m_EntPtrArray[v10];
      if ( v11 )
        v13 = *v12;
      else
        v13 = nullptr;
      CAI_ScriptedSequence::ModifyScriptedAutoMovement(this: v13, vecNewPos: &newPos);
    }
  }
  m_Value = this->m_MoveType.m_Value;
  if ( m_Value != 3 )
  {
    if ( m_Value == 4 )
    {
      v24 = 1.0 / flInterval;
      v25 = (float)(newPos.y - this->m_vecOrigin.m_Value.y) * v24;
      v26 = (float)(newPos.z - this->m_vecOrigin.m_Value.z) * v24;
      dist.x = (float)(newPos.x - this->m_vecOrigin.m_Value.x) * v24;
      dist.y = v25;
      dist.z = v26;
      CBaseEntity::SetLocalVelocity(this, vecVelocity: &dist);
      return true;
    }
    return false;
  }
  if ( (this->m_fFlags.m_Value & 0x800) != 0 )
  {
    CBaseEntity::SetLocalOrigin(this, origin: &newPos);
    CBaseEntity::SetLocalAngles(this, angles: &newAngles);
    return true;
  }
  else
  {
    NavTargetEntity = pTarget;
    if ( pTarget == nullptr )
      NavTargetEntity = CAI_BaseNPC::GetNavTargetEntity(this);
    if ( this->ModifyAutoMovement(this, a2: &newPos) )
    {
      AbsOrigin = CBaseEntity::GetAbsOrigin(this);
      v17 = *(_QWORD *)&AbsOrigin->x;
      z = AbsOrigin->z;
      v19 = false;
      v11 = this->m_ScheduleState.fTaskStatus == TASKSTATUS_COMPLETE;
      *(_QWORD *)&dist.x = v17;
      dist.z = z;
      if ( !v11 )
        v19 = CAI_Motor::MoveGroundStep(
                this: this->m_pMotor,
                &newPos,
                pMoveTarget: NavTargetEntity,
                yaw: newAngles.y,
                bAsFarAsCan: false,
                bTestZ: true,
                pTraceResult) == AIM_SUCCESS;
      v20 = CBaseEntity::GetAbsOrigin(this);
      m_pMotor = this->m_pMotor;
      v22 = (float)(v20->y - dist.y) * (float)(1.0 / flInterval);
      v23 = (float)(v20->z - dist.z) * (float)(1.0 / flInterval);
      m_pMotor->m_vecVelocity.x = (float)(v20->x - dist.x) * (float)(1.0 / flInterval);
      m_pMotor->m_vecVelocity.y = v22;
      m_pMotor->m_vecVelocity.z = v23;
      return v19;
    }
    else
    {
      return CAI_Motor::MoveGroundStep(
               this: this->m_pMotor,
               &newPos,
               pMoveTarget: NavTargetEntity,
               yaw: newAngles.y,
               bAsFarAsCan: false,
               bTestZ: true,
               pTraceResult) == AIM_SUCCESS;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038DB0
// Name: public: bool CAI_BaseNPC::AutoMovement(class CBaseEntity __near *,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::AutoMovement(CAI_BaseNPC *this, CBaseEntity *pTarget, AIMoveTrace_t *pTraceResult)
{
  float flInterval; // [esp+0h] [ebp-10h]

  flInterval = CBaseAnimating::GetAnimTimeInterval(this);
  return CAI_BaseNPC::AutoMovement(this, flInterval, pTarget, pTraceResult);
}

//------------------------------------------------------------------------------
// Address: 0x100383D0
// Name: struct datamap_t __near * DataMapInit<class CAI_BaseFlyingBot>(class CAI_BaseFlyingBot __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_BaseFlyingBot>()
{
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    nameHolder_11.m_pszBase = "CAI_BaseFlyingBot";
    nameHolder_11.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_11.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_11.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_11.m_Names.m_Size = 0;
    nameHolder_11.m_Names.m_pElements = nullptr;
    nameHolder_11.m_nLenBase = 17;
    atexit(func: DataMapInit_CAI_BaseFlyingBot__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_BaseFlyingBot::m_DataMap.baseMap = &CAI_BaseNPC::m_DataMap;
  CAI_BaseFlyingBot::m_DataMap.dataNumFields = 6;
  CAI_BaseFlyingBot::m_DataMap.dataDesc = &dataDesc_11[1];
  return &CAI_BaseFlyingBot::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10038DE0
// Name: struct datamap_t __near * DataMapInit<class CAI_BasePhysicsFlyingBot>(class CAI_BasePhysicsFlyingBot __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_BasePhysicsFlyingBot>()
{
  if ( (_S2_4 & 1) == 0 )
  {
    _S2_4 |= 1u;
    nameHolder_12.m_pszBase = "CAI_BasePhysicsFlyingBot";
    nameHolder_12.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_12.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_12.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_12.m_Names.m_Size = 0;
    nameHolder_12.m_Names.m_pElements = nullptr;
    nameHolder_12.m_nLenBase = 24;
    atexit(func: DataMapInit_CAI_BasePhysicsFlyingBot__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_BasePhysicsFlyingBot::m_DataMap.baseMap = &CAI_BaseNPC::m_DataMap;
  if ( (_S2_4 & 2) == 0 )
  {
    _S2_4 |= 2u;
    dataDesc_12[6].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSMOTIONCONTROLLER);
    dataDesc_12[6].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_12[6].td = 0;
    *(_QWORD *)&dataDesc_12[6].override_field = 0;
    *(_QWORD *)&dataDesc_12[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_12[6].flatOffset[1] = 0;
  }
  CAI_BasePhysicsFlyingBot::m_DataMap.dataNumFields = 6;
  CAI_BasePhysicsFlyingBot::m_DataMap.dataDesc = &dataDesc_12[1];
  return &CAI_BasePhysicsFlyingBot::m_DataMap;
}
