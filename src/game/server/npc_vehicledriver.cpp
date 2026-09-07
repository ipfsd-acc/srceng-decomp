// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/npc_vehicledriver.cpp
// Functions: 52
// ============================================================

#include "game\server\npc_vehicledriver.h"

//------------------------------------------------------------------------------
// Address: 0x10177FA0
// Name: public: void CVehicleWaypoint::RecalculateSpline(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVehicleWaypoint::RecalculateSpline(CVehicleWaypoint *this@<ecx>, float a2@<ebp>)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  cplane_t *p_planeWaypoint; // edi
  int v6; // eax
  float z; // edx
  __int64 v8; // xmm0_8
  int v9; // edi
  float y; // xmm4_4
  float v11; // xmm5_4
  float x; // xmm3_4
  Vector v13; // [esp+30h] [ebp-24h] BYREF
  Vector vecCurr; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecPrev; // [esp+48h] [ebp-Ch]
  float retaddr; // [esp+54h] [ebp+0h]

  vecPrev.x = a2;
  vecPrev.y = retaddr;
  v3 = this->splinePoints[2].y - this->splinePoints[1].y;
  v4 = this->splinePoints[2].z - this->splinePoints[1].z;
  p_planeWaypoint = &this->planeWaypoint;
  this->planeWaypoint.normal.x = this->splinePoints[2].x - this->splinePoints[1].x;
  this->planeWaypoint.normal.y = v3;
  this->planeWaypoint.normal.z = v4;
  VectorNormalize(vec: &this->planeWaypoint.normal);
  this->planeWaypoint.type = 5;
  this->planeWaypoint.dist = (float)((float)(p_planeWaypoint->normal.x * this->splinePoints[2].x)
                                   + (float)(p_planeWaypoint->normal.y * this->splinePoints[2].y))
                           + (float)(p_planeWaypoint->normal.z * this->splinePoints[2].z);
  this->planeWaypoint.signbits = SignbitsForPlane(out: p_planeWaypoint);
  vecCurr.x = 32.0;
  vecCurr.y = 32.0;
  vecCurr.z = 32.0;
  v13.x = -32.0;
  v13.y = -32.0;
  v13.z = -32.0;
  v6 = BoxOnPlaneSide(emins: &v13.x, emaxs: &vecCurr.x, p: p_planeWaypoint);
  z = this->splinePoints[1].z;
  this->flSplineLength = 0.0;
  v8 = *(_QWORD *)&this->splinePoints[1].x;
  this->iInitialPlaneSide = v6;
  *(_QWORD *)&vecCurr.x = v8;
  vecCurr.z = z;
  v9 = 1;
  do
  {
    Catmull_Rom_Spline(
      p1: this->splinePoints,
      p2: &this->splinePoints[1],
      p3: &this->splinePoints[2],
      p4: &this->splinePoints[3],
      t: (float)v9 * 0.1,
      output: &v13);
    y = v13.y;
    v11 = v13.z;
    x = v13.x;
    ++v9;
    this->flSplineLength = this->flSplineLength
                         + fsqrt(
                             (float)((float)((float)(v13.y - vecCurr.y) * (float)(v13.y - vecCurr.y))
                                   + (float)((float)(v13.z - vecCurr.z) * (float)(v13.z - vecCurr.z)))
                           + (float)((float)(v13.x - vecCurr.x) * (float)(v13.x - vecCurr.x)));
    vecCurr.x = x;
    vecCurr.y = y;
    vecCurr.z = v11;
  }
  while ( v9 <= 10 );
}

//------------------------------------------------------------------------------
// Address: 0x10178140
// Name: public: virtual struct datamap_t __near * CNPC_VehicleDriver::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CNPC_VehicleDriver::GetDataDescMap(CNPC_VehicleDriver *this)
{
  return &CNPC_VehicleDriver::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10178150
// Name: public: virtual void CNPC_VehicleDriver::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNPC_VehicleDriver::Precache(CNPC_VehicleDriver *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/roller_vehicledriver.mdl", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10178160
// Name: public: virtual void CNPC_VehicleDriver::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::UpdateOnRemove(CNPC_VehicleDriver *this)
{
  if ( this->m_pVehicleInterface != nullptr )
    this->m_pVehicleInterface->NPC_SetDriver(this: this->m_pVehicleInterface, a2: nullptr);
  CAI_BaseNPC::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10178190
// Name: public: virtual int CNPC_VehicleDriver::RangeAttack2Conditions(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNPC_VehicleDriver::RangeAttack2Conditions(CNPC_VehicleDriver *this, float flDot, float flDist)
{
  int result; // eax
  float flMaxRange; // [esp+4h] [ebp-8h] BYREF
  float flMinRange; // [esp+8h] [ebp-4h] BYREF

  if ( ((double (__thiscall *)(IServerVehicle *))this->m_pVehicleInterface->Weapon_SecondaryCanFireAt)(a1: this->m_pVehicleInterface) > gpGlobals->curtime )
    return 0;
  this->m_pVehicleInterface->Weapon_SecondaryRanges(this: this->m_pVehicleInterface, a2: &flMinRange, a3: &flMaxRange);
  if ( flMinRange > flDist )
    return 38;
  result = 39;
  if ( flDist <= flMaxRange )
    return 22;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10178210
// Name: public: virtual int CNPC_VehicleDriver::TranslateSchedule(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNPC_VehicleDriver::TranslateSchedule(CNPC_VehicleDriver *this, int scheduleType)
{
  int result; // eax

  switch ( scheduleType )
  {
    case 5:
      result = 9;
      break;
    case 12:
      result = this->TranslateSchedule(this, a2: 17);
      break;
    case 18:
    case 82:
      result = 82;
      break;
    default:
      result = CAI_BaseNPC::TranslateSchedule(this, scheduleType);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101782C0
// Name: public: virtual void CNPC_VehicleDriver::GatherEnemyConditions(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CNPC_VehicleDriver::GatherEnemyConditions(
        CNPC_VehicleDriver *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseEntity *pEnemy)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  CAI_BaseNPC::GatherEnemyConditions(this, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: a3, pEnemy);
}

//------------------------------------------------------------------------------
// Address: 0x101782D0
// Name: public: virtual enum Disposition_t CNPC_VehicleDriver::IRelationType(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
Disposition_t __thiscall CNPC_VehicleDriver::IRelationType(CNPC_VehicleDriver *this, CBaseEntity *pTarget)
{
  int Index; // eax

  if ( pTarget != nullptr
    && pTarget->Classify(this: pTarget) == CLASS_PLAYER
    && (Index = GlobalEntity_GetIndex(pGlobalname: "gordon_precriminal"),
        GlobalEntity_GetState(globalIndex: Index) == GLOBAL_ON) )
  {
    return D_NU;
  }
  else
  {
    return CBaseCombatCharacter::IRelationType(this, pTarget);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178320
// Name: public: void CNPC_VehicleDriver::CalculatePostPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::CalculatePostPoints(CNPC_VehicleDriver *this)
{
  double x; // st7
  CAI_Navigator *m_pNavigator; // ecx
  AI_Waypoint_t *pNext; // eax
  bool v5; // zf
  float *p_x; // eax

  x = this->m_vecDesiredPosition.x;
  m_pNavigator = this->m_pNavigator;
  this->m_vecPostPoint.x = x;
  this->m_vecPostPoint.y = this->m_vecDesiredPosition.y;
  this->m_vecPostPoint.z = this->m_vecDesiredPosition.z;
  this->m_vecPostPostPoint = this->m_vecDesiredPosition;
  if ( !CAI_Navigator::CurWaypointIsGoal(this: m_pNavigator) )
  {
    pNext = this->m_pNavigator->m_pPath->m_Waypoints.m_pFirstWaypoint->pNext;
    v5 = pNext->pNext == nullptr;
    this->m_vecPostPoint.x = pNext->vecLocation.x;
    this->m_vecPostPoint.y = pNext->vecLocation.y;
    this->m_vecPostPoint.z = pNext->vecLocation.z;
    if ( v5 )
    {
      this->m_vecPostPostPoint.x = this->m_vecPostPoint.x;
      this->m_vecPostPostPoint.y = this->m_vecPostPoint.y;
      this->m_vecPostPostPoint.z = this->m_vecPostPoint.z;
    }
    else
    {
      p_x = &pNext->pNext->vecLocation.x;
      this->m_vecPostPostPoint.x = *p_x;
      this->m_vecPostPostPoint.y = p_x[1];
      this->m_vecPostPostPoint.z = p_x[2];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101783F0
// Name: public: void CNPC_VehicleDriver::ClearWaypoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::ClearWaypoints(CNPC_VehicleDriver *this)
{
  this->m_vecDesiredPosition = vec3_origin;
  if ( this->m_pCurrentWaypoint != nullptr )
  {
    free(pMem: this->m_pCurrentWaypoint);
    this->m_pCurrentWaypoint = nullptr;
  }
  if ( this->m_pNextWaypoint != nullptr )
  {
    free(pMem: this->m_pNextWaypoint);
    this->m_pNextWaypoint = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178460
// Name: public: virtual float CNPC_VehicleDriver::GetDefaultNavGoalTolerance(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNPC_VehicleDriver::GetDefaultNavGoalTolerance(CNPC_VehicleDriver *this)
{
  return 48.0;
}

//------------------------------------------------------------------------------
// Address: 0x10178470
// Name: public: void CNPC_VehicleDriver::RecalculateSpeeds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::RecalculateSpeeds(CNPC_VehicleDriver *this)
{
  const vehicleparams_t *v2; // eax

  v2 = this->m_pVehicleInterface->GetVehicleParams(this: this->m_pVehicleInterface);
  if ( v2 != nullptr )
  {
    this->m_flMaxSpeed = this->m_flDriversMaxSpeed * v2->engine.maxSpeed;
    this->m_flSteering = v2->steering.degreesSlow;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101784B0
// Name: public: void CNPC_VehicleDriver::InputStop(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::InputStop(CNPC_VehicleDriver *this, inputdata_t *inputdata)
{
  this->m_flMaxSpeed = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101784C0
// Name: public: void CNPC_VehicleDriver::InputStopFiring(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::InputStopFiring(CNPC_VehicleDriver *this, inputdata_t *inputdata)
{
  CAI_BaseNPC::CapabilitiesRemove(this, capability: 0x20000);
  CAI_BaseNPC::CapabilitiesRemove(this, capability: 0x40000);
}

//------------------------------------------------------------------------------
// Address: 0x101784E0
// Name: public: virtual bool CNPC_VehicleDriver::LoadedSchedules(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNPC_VehicleDriver::LoadedSchedules(CNPC_VehicleDriver *this)
{
  return CNPC_VehicleDriver::gm_SchedLoadStatus.fValid;
}

//------------------------------------------------------------------------------
// Address: 0x101784F0
// Name: public: virtual char const __near * CNPC_VehicleDriver::SquadSlotName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNPC_VehicleDriver::SquadSlotName(CNPC_VehicleDriver *this, int slotEN)
{
  int v2; // eax

  v2 = CAI_LocalIdSpace::LocalToGlobal(this: &CNPC_VehicleDriver::gm_SquadSlotIdSpace, localID: slotEN);
  return CAI_GlobalNamespace::IdToSymbol(this: &CAI_BaseNPC::gm_SquadSlotNamespace, symbolID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10178510
// Name: public: CVehicleWaypoint::CVehicleWaypoint(class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
CVehicleWaypoint *__thiscall CVehicleWaypoint::CVehicleWaypoint(
        CVehicleWaypoint *this,
        Vector *pPrevPoint,
        Vector *pCurPoint,
        Vector *pNextPoint,
        Vector *pNextNextPoint)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  this->splinePoints[0] = *pPrevPoint;
  this->splinePoints[1] = *pCurPoint;
  this->splinePoints[2] = *pNextPoint;
  this->splinePoints[3] = *pNextNextPoint;
  CVehicleWaypoint::RecalculateSpline(this, a2: COERCE_FLOAT(&savedregs));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10178580
// Name: public: virtual CNPC_VehicleDriver::~CNPC_VehicleDriver(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::~CNPC_VehicleDriver(CNPC_VehicleDriver *this)
{
  this->CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CNPC_VehicleDriver_vtbl *)&CNPC_VehicleDriver::`vftable'{for `CBaseCombatCharacter'};
  this->CAI_BaseNPC::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CNPC_VehicleDriver::`vftable'{for `CAI_DefMovementSink'};
  this->CAI_BaseNPC::IAI_BehaviorBridge::__vftable = (IAI_BehaviorBridge_vtbl *)&CNPC_VehicleDriver::`vftable'{for `IAI_BehaviorBridge'};
  this->m_vecDesiredPosition = vec3_origin;
  if ( this->m_pCurrentWaypoint != nullptr )
  {
    free(pMem: this->m_pCurrentWaypoint);
    this->m_pCurrentWaypoint = nullptr;
  }
  if ( this->m_pNextWaypoint != nullptr )
  {
    free(pMem: this->m_pNextWaypoint);
    this->m_pNextWaypoint = nullptr;
  }
  CAI_BaseNPC::~CAI_BaseNPC(this);
}

//------------------------------------------------------------------------------
// Address: 0x10178610
// Name: public: virtual class CAI_ClassScheduleIdSpace __near * CNPC_VehicleDriver::GetClassScheduleIdSpace(void)
// Source: json
//------------------------------------------------------------------------------
CAI_ClassScheduleIdSpace *__thiscall CNPC_VehicleDriver::GetClassScheduleIdSpace(CNPC_VehicleDriver *this)
{
  return &CNPC_VehicleDriver::gm_ClassScheduleIdSpace;
}

//------------------------------------------------------------------------------
// Address: 0x10178620
// Name: public: virtual char const __near * CNPC_VehicleDriver::GetSchedulingErrorName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNPC_VehicleDriver::GetSchedulingErrorName(CNPC_VehicleDriver *this)
{
  return CNPC_VehicleDriver::gm_pszErrorClassName;
}

//------------------------------------------------------------------------------
// Address: 0x10178650
// Name: public: virtual void CNPC_VehicleDriver::RunTask(struct Task_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::RunTask(CNPC_VehicleDriver *this, const Task_t *pTask)
{
  float flTaskData; // xmm0_4
  void (__thiscall *RunTask)(CAI_BaseNPC *, const Task_t *); // edx
  float v5; // xmm0_4
  void (__thiscall *v6)(CAI_BaseNPC *, const Task_t *); // edx
  CBaseEntity *v7; // eax
  CNPC_VehicleDriver *v8; // ecx
  CBaseEntity *v9; // edi
  CBaseEntity *v10; // eax
  CBaseEntity *v11; // edi
  Vector vecTarget; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( pTask->iTask != 75 )
  {
    if ( pTask->iTask != 76 )
    {
      if ( pTask->iTask == 130 )
      {
        CAI_BaseNPC::RunTask(this, a2: (int)&savedregs, pTask);
        if ( CAI_BaseNPC::HasCondition(this, iCondition: 10) )
        {
          if ( CAI_BaseNPC::HasCondition(this, iCondition: 22) )
          {
            flTaskData = pTask->flTaskData;
            RunTask = this->RunTask;
            LODWORD(vecTarget.y) = 76;
            vecTarget.z = flTaskData;
            RunTask(this, a2: (const Task_t *)&vecTarget.y);
          }
          if ( CAI_BaseNPC::HasCondition(this, iCondition: 21) )
          {
            v5 = pTask->flTaskData;
            v6 = this->RunTask;
            LODWORD(vecTarget.y) = 75;
            vecTarget.z = v5;
            v6(this, a2: (const Task_t *)&vecTarget.y);
          }
        }
      }
      else
      {
        CAI_BaseNPC::RunTask(this, a2: (int)&savedregs, pTask);
      }
      return;
    }
    v7 = this->GetEnemy_2(this);
    v8 = this;
    if ( v7 != nullptr )
    {
      v9 = this->GetEnemy_2(this);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v9->BodyTarget(this: v9, result: &vecTarget, a3: &this->m_vecAbsOrigin, a4: false);
      ((void (__thiscall *)(IServerVehicle *, _DWORD, _DWORD, _DWORD))this->m_pVehicleInterface->NPC_AimSecondaryWeapon)(
        a1: this->m_pVehicleInterface,
        a2: LODWORD(vecTarget.x),
        a3: LODWORD(vecTarget.y),
        a4: LODWORD(vecTarget.z));
      this->m_pVehicleInterface->NPC_SecondaryFire(this: this->m_pVehicleInterface);
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    }
LABEL_18:
    this->TaskFail(this: v8, a2: 6);
    return;
  }
  v10 = this->GetEnemy_2(this);
  v8 = this;
  if ( v10 == nullptr )
    goto LABEL_18;
  v11 = this->GetEnemy_2(this);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v11->BodyTarget(this: v11, result: &vecTarget, a3: &this->m_vecAbsOrigin, a4: false);
  ((void (__thiscall *)(IServerVehicle *, _DWORD, _DWORD, _DWORD))this->m_pVehicleInterface->NPC_AimPrimaryWeapon)(
    a1: this->m_pVehicleInterface,
    a2: LODWORD(vecTarget.x),
    a3: LODWORD(vecTarget.y),
    a4: LODWORD(vecTarget.z));
  this->m_pVehicleInterface->NPC_PrimaryFire(this: this->m_pVehicleInterface);
  CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
}

//------------------------------------------------------------------------------
// Address: 0x10178840
// Name: public: void CNPC_VehicleDriver::InputSetDriversMaxSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::InputSetDriversMaxSpeed(CNPC_VehicleDriver *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  IServerVehicle *m_pVehicleInterface; // ecx
  int v5; // eax

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  m_pVehicleInterface = this->m_pVehicleInterface;
  LODWORD(this->m_flDriversMaxSpeed) = pszValue;
  v5 = (int)m_pVehicleInterface->GetVehicleParams(this: m_pVehicleInterface);
  if ( v5 != 0 )
  {
    this->m_flMaxSpeed = *(float *)(v5 + 516) * this->m_flDriversMaxSpeed;
    this->m_flSteering = *(float *)(v5 + 600);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101788A0
// Name: public: void CNPC_VehicleDriver::InputSetDriversMinSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::InputSetDriversMinSpeed(CNPC_VehicleDriver *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  IServerVehicle *m_pVehicleInterface; // ecx
  int v5; // eax

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  m_pVehicleInterface = this->m_pVehicleInterface;
  LODWORD(this->m_flDriversMinSpeed) = pszValue;
  v5 = (int)m_pVehicleInterface->GetVehicleParams(this: m_pVehicleInterface);
  if ( v5 != 0 )
  {
    this->m_flMaxSpeed = this->m_flDriversMaxSpeed * *(float *)(v5 + 516);
    this->m_flSteering = *(float *)(v5 + 600);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178940
// Name: public: virtual void CNPC_VehicleDriver::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::Activate(CNPC_VehicleDriver *this)
{
  unsigned int m_Index; // eax
  const char *v3; // eax
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int v6; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  const char *v10; // ecx
  const char *v11; // eax
  int v12; // eax
  bool v13; // zf
  CEntInfo *v14; // eax
  IHandleEntity *m_pEntity; // ecx
  IServerVehicle *v16; // eax
  bool v17; // al
  CHandle<CBaseEntity> *p_m_hVehicleEntity; // ecx
  const char *v19; // ecx
  const char *v20; // eax
  CBaseEntity *v21; // eax
  const Vector *v22; // eax

  CAI_BaseNPC::Activate(this);
  m_Index = this->m_hVehicleEntity.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    if ( this->m_iszVehicleName.pszValue != nullptr )
    {
      pszValue = this->m_iszVehicleName.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName != nullptr )
        this->m_hVehicleEntity.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
      else
        this->m_hVehicleEntity.m_Index = -1;
      v6 = this->m_hVehicleEntity.m_Index;
      if ( v6 != -1
        && (v7 = (unsigned __int16)v6,
            v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v6],
            v9 = HIWORD(v6),
            v8->m_SerialNumber == v9)
        && v8->m_pEntity != nullptr )
      {
        v12 = v7;
        v13 = g_pEntityList->m_EntPtrArray[v12].m_SerialNumber == v9;
        v14 = &g_pEntityList->m_EntPtrArray[v12];
        if ( v13 )
          m_pEntity = v14->m_pEntity;
        else
          m_pEntity = nullptr;
        v16 = (IServerVehicle *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[30].SetRefEHandle)(a1: m_pEntity);
        this->m_pVehicleInterface = v16;
        v17 = v16->NPC_CanDrive(this: v16);
        p_m_hVehicleEntity = &this->m_hVehicleEntity;
        if ( v17 )
        {
          v21 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hVehicleEntity);
          v22 = v21->WorldSpaceCenter(this: v21);
          CBaseEntity::SetAbsOrigin(this, absOrigin: v22);
          this->m_pVehicleInterface->NPC_SetDriver(this: this->m_pVehicleInterface, a2: this);
          CNPC_VehicleDriver::RecalculateSpeeds(this);
        }
        else
        {
          v19 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hVehicleEntity)->m_iName.m_Value.pszValue;
          if ( v19 == nullptr )
            v19 = locale;
          v20 = this->m_iName.m_Value.pszValue;
          if ( v20 == nullptr )
            v20 = locale;
          _Warning(a1: "npc_vehicledriver %s doesn't know how to drive vehicle %s.\n", v20, v19);
          UTIL_Remove(oldObj: this);
        }
      }
      else
      {
        v10 = this->m_iszVehicleName.pszValue;
        if ( v10 == nullptr )
          v10 = locale;
        v11 = this->m_iName.m_Value.pszValue;
        if ( v11 == nullptr )
          v11 = locale;
        _Warning(a1: "npc_vehicledriver %s couldn't find his vehicle named %s.\n", v11, v10);
        UTIL_Remove(oldObj: this);
      }
    }
    else
    {
      v3 = this->m_iName.m_Value.pszValue;
      if ( v3 == nullptr )
        v3 = locale;
      _Warning(a1: "npc_vehicledriver %s has no vehicle to drive.\n", v3);
      UTIL_Remove(oldObj: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178B10
// Name: public: virtual void CNPC_VehicleDriver::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::OnRestore(CNPC_VehicleDriver *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  CAI_BaseNPC::OnRestore(this);
  m_Index = this->m_hVehicleEntity.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      this->m_pVehicleInterface = (IServerVehicle *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[30].SetRefEHandle)(a1: m_pEntity);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178B70
// Name: public: virtual void CNPC_VehicleDriver::PrescheduleThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNPC_VehicleDriver::PrescheduleThink(CNPC_VehicleDriver *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // ecx
  const Vector *v11; // eax
  unsigned int v12; // eax
  CBaseEntity *v13; // edi
  unsigned int v14; // eax
  IHandleEntity *v15; // ecx
  IHandleEntity_vtbl *v16; // eax

  m_Index = this->m_hVehicleEntity.m_Index;
  if ( m_Index != -1
    && (v4 = (unsigned __int16)m_Index,
        v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v6 = HIWORD(m_Index),
        v5->m_SerialNumber == v6)
    && v5->m_pEntity != nullptr )
  {
    v7 = v4;
    v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
    v9 = &g_pEntityList->m_EntPtrArray[v7];
    if ( v8 )
      m_pEntity = v9->m_pEntity;
    else
      m_pEntity = nullptr;
    v11 = (const Vector *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].dtr_IHandleEntity)(a1: m_pEntity);
    CBaseEntity::SetAbsOrigin(this, absOrigin: v11);
    v12 = this->m_hVehicleEntity.m_Index;
    if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
      v13 = nullptr;
    else
      v13 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
    if ( (v13->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v13, a2);
    CBaseEntity::SetAbsAngles(this, absAngles: &v13->m_angAbsRotation);
    CAI_BaseNPC::PrescheduleThink(this);
    if ( this->m_NPCState == NPC_STATE_IDLE )
    {
      this->m_pVehicleInterface->NPC_Brake(this: this->m_pVehicleInterface);
    }
    else
    {
      v14 = this->m_hVehicleEntity.m_Index;
      if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
        v15 = nullptr;
      else
        v15 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
      v16 = v15[52].__vftable;
      if ( v16 != (IHandleEntity_vtbl *)-1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber == (unsigned int)v16 >> 16
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity != nullptr )
      {
        CAI_BaseNPC::SetState(this, State: NPC_STATE_IDLE);
        CNPC_VehicleDriver::ClearWaypoints(this);
        this->m_hGoalEnt.m_Index = -1;
      }
      else
      {
        this->DriveVehicle(this);
      }
    }
  }
  else
  {
    this->m_pVehicleInterface = nullptr;
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178CD0
// Name: public: virtual int CNPC_VehicleDriver::SelectSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNPC_VehicleDriver::SelectSchedule(CNPC_VehicleDriver *this)
{
  unsigned int m_Index; // ecx

  CAI_BaseNPC::ClearCondition(this, iCondition: 61);
  if ( (this->m_spawnflags.m_Value & 0x10000) != 0 )
  {
    CAI_BaseNPC::SetState(this, State: NPC_STATE_IDLE);
    return 89;
  }
  m_Index = this->m_hGoalEnt.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    return 91;
  }
  if ( this->m_NPCState != NPC_STATE_COMBAT )
    return CAI_BaseNPC::SelectSchedule(this);
  if ( CAI_BaseNPC::HasCondition(this, iCondition: 26) || CAI_BaseNPC::HasCondition(this, iCondition: 30) )
    return CAI_BaseNPC::SelectSchedule(this);
  if ( CAI_BaseNPC::HasCondition(this, iCondition: 10) )
  {
    if ( CAI_BaseNPC::HasCondition(this, iCondition: 22) )
      return 45;
    if ( CAI_BaseNPC::HasCondition(this, iCondition: 21) )
      return 44;
  }
  return 90;
}

//------------------------------------------------------------------------------
// Address: 0x10178DA0
// Name: public: virtual int CNPC_VehicleDriver::RangeAttack1Conditions(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNPC_VehicleDriver::RangeAttack1Conditions(CNPC_VehicleDriver *this, float flDot, float flDist)
{
  int result; // eax
  CBaseEntity *v5; // eax
  float *v6; // edi
  unsigned int m_Index; // esi
  IHandleEntity *m_pEntity; // ecx
  Vector vecForward; // [esp+4h] [ebp-20h] BYREF
  Vector vecToTarget; // [esp+10h] [ebp-14h] BYREF
  float flMaxRange; // [esp+1Ch] [ebp-8h] BYREF
  float flMinRange; // [esp+20h] [ebp-4h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( ((double (__thiscall *)(IServerVehicle *))this->m_pVehicleInterface->Weapon_PrimaryCanFireAt)(a1: this->m_pVehicleInterface) > gpGlobals->curtime )
    return 0;
  this->m_pVehicleInterface->Weapon_PrimaryRanges(this: this->m_pVehicleInterface, a2: &flMinRange, a3: &flMaxRange);
  if ( flMinRange > flDist )
    return 38;
  if ( flDist > flMaxRange )
    return 39;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v5 = this->GetEnemy_2(this);
  v6 = (float *)v5;
  if ( (v5->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
  vecToTarget.x = v6[115] - this->m_vecAbsOrigin.x;
  vecToTarget.y = v6[116] - this->m_vecAbsOrigin.y;
  vecToTarget.z = v6[117] - this->m_vecAbsOrigin.z;
  VectorNormalize(vec: &vecToTarget);
  m_Index = this->m_hVehicleEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *, Vector *, _DWORD, _DWORD))m_pEntity->__vftable[44].dtr_IHandleEntity)(
    a1: m_pEntity,
    a2: &vecForward,
    a3: 0,
    a4: 0);
  if ( (float)((float)((float)(vecForward.y * vecToTarget.y) + (float)(vecToTarget.x * vecForward.x))
             + (float)(vecForward.z * vecToTarget.z)) >= 0.0 )
    return 21;
  result = 40;
  if ( COERCE_FLOAT(LODWORD(flDot) & _mask__AbsFloat_) >= 0.5 )
    return 21;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10178F40
// Name: public: bool CNPC_VehicleDriver::WaypointReached(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CNPC_VehicleDriver::WaypointReached@<al>(CNPC_VehicleDriver *this@<ecx>, int a2@<ebp>)
{
  Vector *p_m_vecPrevPoint; // ebx
  bool IsGoal; // al
  CAI_Navigator *m_pNavigator; // ecx
  AI_Waypoint_t *m_pFirstWaypoint; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  float v10; // xmm0_4
  const char *v11; // ecx
  CAI_Navigator *v12; // ecx
  CVehicleWaypoint *v13; // eax
  CVehicleWaypoint *v14; // eax
  float v15; // xmm0_4
  double v16; // xmm0_8

  p_m_vecPrevPoint = &this->m_vecPrevPoint;
  this->m_vecPrevPrevPoint = this->m_vecPrevPoint;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  p_m_vecPrevPoint->x = this->m_vecAbsOrigin.x;
  p_m_vecPrevPoint->y = this->m_vecAbsOrigin.y;
  p_m_vecPrevPoint->z = this->m_vecAbsOrigin.z;
  IsGoal = CAI_Navigator::CurWaypointIsGoal(this: this->m_pNavigator);
  m_pNavigator = this->m_pNavigator;
  if ( IsGoal )
  {
    CAI_Navigator::AdvancePath(this: m_pNavigator);
LABEL_5:
    CNPC_VehicleDriver::ClearWaypoints(this);
    CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
    this->m_hGoalEnt.m_Index = -1;
    return 1;
  }
  m_pFirstWaypoint = m_pNavigator->m_pPath->m_Waypoints.m_pFirstWaypoint;
  if ( m_pFirstWaypoint != nullptr )
  {
    if ( (m_pFirstWaypoint->m_fWaypointFlags & 2) != 0 )
    {
      m_Index = m_pFirstWaypoint->hPathCorner.m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr )
        {
          v10 = *(float *)&m_pEntity[130].__vftable;
          if ( v10 > 0.0 )
          {
            if ( v10 > 1.0 )
            {
              v11 = (const char *)m_pEntity[51].__vftable;
              if ( v11 == nullptr )
                v11 = locale;
              _Warning(
                a1: "path_track %s tried to tell the npc_vehicledriver to set speed to %.3f. npc_vehicledriver only accepts v"
                "alues between 0 and 1.\n",
                v11,
                v10);
            }
            else
            {
              this->m_flDriversMaxSpeed = v10;
              CNPC_VehicleDriver::RecalculateSpeeds(this);
            }
          }
        }
      }
    }
    CAI_Navigator::AdvancePath(this: this->m_pNavigator);
    v12 = this->m_pNavigator;
    if ( v12->m_pPath->m_Waypoints.m_pFirstWaypoint == nullptr )
      goto LABEL_5;
    this->m_vecDesiredPosition = *CAI_Navigator::GetCurWaypointPos(this: v12);
    CNPC_VehicleDriver::CalculatePostPoints(this);
    free(pMem: this->m_pCurrentWaypoint);
    this->m_pCurrentWaypoint = this->m_pNextWaypoint;
    v13 = (CVehicleWaypoint *)operator new(nSize: 0x4Cu);
    if ( v13 != nullptr )
      v14 = CVehicleWaypoint::CVehicleWaypoint(
              this: v13,
              pPrevPoint: p_m_vecPrevPoint,
              pCurPoint: &this->m_vecDesiredPosition,
              pNextPoint: &this->m_vecPostPoint,
              pNextNextPoint: &this->m_vecPostPostPoint);
    else
      v14 = nullptr;
    v15 = this->m_flDistanceAlongSpline - 1.0;
    this->m_Waypoints[1] = v14;
    this->m_pNextWaypoint = v14;
    if ( v15 >= 0.0 )
      v16 = v15;
    else
      v16 = 0.0;
    this->m_flDistanceAlongSpline = v16;
    CNPC_VehicleDriver::CheckForTeleport(this);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10179140
// Name: public: bool CNPC_VehicleDriver::OverridePathMove(float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CNPC_VehicleDriver::OverridePathMove@<al>(
        CNPC_VehicleDriver *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        float flInterval)
{
  CVehicleWaypoint *v6; // eax
  CVehicleWaypoint *v7; // eax
  CVehicleWaypoint *v8; // eax
  CVehicleWaypoint *v9; // eax
  CVehicleWaypoint *v10; // ecx
  CVehicleWaypoint *m_pNextWaypoint; // eax
  CVehicleWaypoint *m_pCurrentWaypoint; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v15; // ecx
  __int128 v16; // xmm0
  double LastThink; // st7
  float v18; // xmm0_4
  float v19; // ecx
  const Vector *splinePoints; // edi
  float m_flDistanceAlongSpline; // xmm0_4
  double v22; // st7
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm4_4
  CBaseEntity *v27; // eax
  float z; // eax
  float y; // xmm1_4
  float v30; // xmm3_4
  float m_flDriversMinSpeed; // xmm4_4
  float v32; // xmm0_4
  ConVar *m_pParent; // ecx
  int m_nValue; // eax
  CVehicleWaypoint *v35; // eax
  float x; // xmm2_4
  float v37; // ecx
  float v38; // xmm1_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  CVehicleWaypoint *v44; // eax
  float v45; // xmm2_4
  float v46; // xmm5_4
  float v47; // xmm1_4
  float v48; // xmm3_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm4_4
  float v53; // xmm2_4
  int v54; // ecx
  int i; // edi
  CVehicleWaypoint *v56; // eax
  CVehicleWaypoint *v57; // eax
  const Vector *v59; // [esp+14h] [ebp-D4h]
  float v60; // [esp+14h] [ebp-D4h]
  const Vector *flDuration; // [esp+18h] [ebp-D0h]
  const Vector *v63; // [esp+1Ch] [ebp-CCh]
  int v65; // [esp+24h] [ebp-C4h] BYREF
  Vector angVel; // [esp+30h] [ebp-B8h] BYREF
  Vector vecAbsMins; // [esp+3Ch] [ebp-ACh] BYREF
  Vector vecAbsMaxs; // [esp+48h] [ebp-A0h] BYREF
  Vector vecVelocity; // [esp+54h] [ebp-94h] BYREF
  float v70[3]; // [esp+60h] [ebp-88h] BYREF
  __int128 vecRight; // [esp+6Ch] [ebp-7Ch] OVERLAPPED BYREF
  Vector v72; // [esp+7Ch] [ebp-6Ch] BYREF
  Vector vecNormVel; // [esp+88h] [ebp-60h] BYREF
  Vector vecToDesired; // [esp+94h] [ebp-54h] BYREF
  Vector vSplineTangent; // [esp+A0h] [ebp-48h] BYREF
  Vector v76; // [esp+ACh] [ebp-3Ch] BYREF
  Vector vSplinePoint; // [esp+B8h] [ebp-30h] BYREF
  float flTangentLength; // [esp+C4h] [ebp-24h]
  float v79; // [esp+C8h] [ebp-20h]
  Vector vecTarget; // [esp+CCh] [ebp-1Ch] BYREF
  float flIncTime; // [esp+D8h] [ebp-10h]
  Vector vecTangent; // [esp+DCh] [ebp-Ch] BYREF
  float retaddr; // [esp+E8h] [ebp+0h]

  vecTangent.x = a2;
  vecTangent.y = retaddr;
  if ( this->m_pCurrentWaypoint == nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecTangent);
    this->m_vecPrevPoint.x = this->m_vecAbsOrigin.x;
    this->m_vecPrevPoint.y = this->m_vecAbsOrigin.y;
    this->m_vecPrevPoint.z = this->m_vecAbsOrigin.z;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecTangent);
    this->m_vecPrevPrevPoint.x = this->m_vecAbsOrigin.x;
    this->m_vecPrevPrevPoint.y = this->m_vecAbsOrigin.y;
    this->m_vecPrevPrevPoint.z = this->m_vecAbsOrigin.z;
    this->m_vecDesiredPosition = *CAI_Navigator::GetCurWaypointPos(this: this->m_pNavigator);
    CNPC_VehicleDriver::CalculatePostPoints(this);
    v6 = (CVehicleWaypoint *)operator new(nSize: 0x4Cu);
    if ( v6 != nullptr )
      v7 = CVehicleWaypoint::CVehicleWaypoint(
             this: v6,
             pPrevPoint: &this->m_vecPrevPrevPoint,
             pCurPoint: &this->m_vecPrevPoint,
             pNextPoint: &this->m_vecDesiredPosition,
             pNextNextPoint: &this->m_vecPostPoint);
    else
      v7 = nullptr;
    this->m_Waypoints[0] = v7;
    v8 = (CVehicleWaypoint *)operator new(nSize: 0x4Cu);
    if ( v8 != nullptr )
      v9 = CVehicleWaypoint::CVehicleWaypoint(
             this: v8,
             pPrevPoint: &this->m_vecPrevPoint,
             pCurPoint: &this->m_vecDesiredPosition,
             pNextPoint: &this->m_vecPostPoint,
             pNextNextPoint: &this->m_vecPostPostPoint);
    else
      v9 = nullptr;
    v10 = this->m_Waypoints[0];
    this->m_Waypoints[1] = v9;
    this->m_pCurrentWaypoint = v10;
    this->m_pNextWaypoint = v9;
    this->m_flDistanceAlongSpline = 0.2;
  }
  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &angVel,
    pWorldMaxs: &vecAbsMins);
  if ( BoxOnPlaneSide(emins: &angVel.x, emaxs: &vecAbsMins.x, p: &this->m_pCurrentWaypoint->planeWaypoint) == 3
    && CNPC_VehicleDriver::WaypointReached(this, a2: (int)&vecTangent) != 0 )
  {
    return 1;
  }
  m_pNextWaypoint = this->m_pNextWaypoint;
  if ( m_pNextWaypoint != nullptr
    && BoxOnPlaneSide(emins: &angVel.x, emaxs: &vecAbsMins.x, p: &m_pNextWaypoint->planeWaypoint) == 3
    && CNPC_VehicleDriver::WaypointReached(this, a2: (int)&vecTangent) != 0 )
  {
    return 1;
  }
  m_pCurrentWaypoint = this->m_pCurrentWaypoint;
  if ( m_pCurrentWaypoint != nullptr && this->m_pNextWaypoint != nullptr )
  {
    if ( this->m_flDistanceAlongSpline > 1.0 )
      m_pCurrentWaypoint = this->m_pNextWaypoint;
    m_Index = this->m_hVehicleEntity.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v15 = m_pEntity[82].__vftable;
    if ( v15 != nullptr )
    {
      (*((void (__thiscall **)(IHandleEntity_vtbl *, Vector *, int *, int, int))v15->dtr_IHandleEntity + 52))(
        a1: v15,
        a2: &vecAbsMaxs,
        a3: &v65,
        a4: a3,
        a5: a4);
      v16 = 0;
      *(float *)&v16 = fsqrt(
                         (float)((float)(vecAbsMaxs.x * vecAbsMaxs.x) + (float)(vecAbsMaxs.z * vecAbsMaxs.z))
                       + (float)(vecAbsMaxs.y * vecAbsMaxs.y));
      vecRight = v16;
      LODWORD(vecTarget.x) = &gpGlobals->curtime;
      LastThink = CBaseEntity::GetLastThink(this, szContext: nullptr);
      *(float *)&v16 = *(float *)&vecRight / m_pCurrentWaypoint->flSplineLength;
      vecTarget.x = *(float *)LODWORD(vecTarget.x) - LastThink;
      v18 = (float)(*(float *)&v16 * vecTarget.x) + this->m_flDistanceAlongSpline;
      if ( v18 >= 0.0 )
      {
        if ( v18 > 2.0 )
          v18 = 2.0;
      }
      else
      {
        v18 = 0.0;
      }
      this->m_flDistanceAlongSpline = v18;
      if ( v18 > 1.0 )
      {
        m_pCurrentWaypoint = this->m_pNextWaypoint;
        v18 = v18 - 1.0;
      }
      LODWORD(vSplinePoint.x) = &m_pCurrentWaypoint->splinePoints[1];
      LODWORD(v19) = &m_pCurrentWaypoint->splinePoints[2];
      v63 = &m_pCurrentWaypoint->splinePoints[3];
      LODWORD(vecTarget.x) = &m_pCurrentWaypoint->splinePoints[3];
      flDuration = &m_pCurrentWaypoint->splinePoints[2];
      v59 = &m_pCurrentWaypoint->splinePoints[1];
      splinePoints = m_pCurrentWaypoint->splinePoints;
      memset((void *)&v76, 0, sizeof(v76));
      vSplinePoint.y = v19;
      Catmull_Rom_Spline(p1: splinePoints, p2: v59, p3: flDuration, p4: v63, t: v18, output: &v76);
      m_flDistanceAlongSpline = this->m_flDistanceAlongSpline;
      if ( m_flDistanceAlongSpline > 1.0 )
        m_flDistanceAlongSpline = m_flDistanceAlongSpline - 1.0;
      memset((void *)&vecToDesired, 0, sizeof(vecToDesired));
      Catmull_Rom_Spline_Tangent(
        p1: splinePoints,
        p2: (const Vector *)LODWORD(vSplinePoint.x),
        p3: (const Vector *)LODWORD(vSplinePoint.y),
        p4: (const Vector *)LODWORD(vecTarget.x),
        t: m_flDistanceAlongSpline,
        output: &vecToDesired);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecTangent);
      vecNormVel.x = v76.x - this->m_vecAbsOrigin.x;
      vecNormVel.y = v76.y - this->m_vecAbsOrigin.y;
      vecNormVel.z = v76.z - this->m_vecAbsOrigin.z;
      vecTarget.x = VectorNormalize(vec: &vecNormVel);
      v22 = VectorNormalize(vec: &vecToDesired);
      vSplinePoint.x = v22;
      v23 = vecNormVel.x * vSplinePoint.x;
      v24 = vecNormVel.y * vSplinePoint.x;
      v25 = vecNormVel.z * vSplinePoint.x;
      if ( vecTarget.x <= v22 * 0.75 )
      {
        v26 = vecTarget.x / (float)(vSplinePoint.x * 0.5);
        v24 = (float)((float)(v24 - vecToDesired.y) * v26) + vecToDesired.y;
        v25 = (float)((float)(v25 - vecToDesired.z) * v26) + vecToDesired.z;
        v23 = (float)((float)(v23 - vecToDesired.x) * v26) + vecToDesired.x;
      }
      this->m_vecDesiredVelocity.z = v25;
      this->m_vecDesiredVelocity.y = v24;
      this->m_vecDesiredVelocity.x = v23;
      v27 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hVehicleEntity);
      v27->GetVectors(this: v27, a2: nullptr, a3: (Vector *)v70, a4: nullptr);
      z = this->m_vecDesiredVelocity.z;
      *(_QWORD *)&v72.x = *(_QWORD *)&this->m_vecDesiredVelocity.x;
      v72.z = z;
      VectorNormalize(vec: &v72);
      y = v72.y;
      v30 = v72.z;
      m_flDriversMinSpeed = 1.0
                          - COERCE_FLOAT(
                              COERCE_UNSIGNED_INT((float)((float)(v70[1] * v72.y) + (float)(v72.x * v70[0])) + (float)(v70[2] * v72.z))
                            & _mask__AbsFloat_);
      if ( this->m_flDriversMinSpeed > m_flDriversMinSpeed )
        m_flDriversMinSpeed = this->m_flDriversMinSpeed;
      v32 = this->m_flMaxSpeed * m_flDriversMinSpeed;
      this->m_vecDesiredVelocity.x = v72.x * v32;
      this->m_vecDesiredVelocity.y = y * v32;
      this->m_vecDesiredVelocity.z = v30 * v32;
      m_pParent = g_debug_vehicledriver.m_pParent;
      if ( g_debug_vehicledriver.m_pParent != nullptr )
        m_nValue = g_debug_vehicledriver.m_pParent->m_Value.m_nValue;
      else
        LOBYTE(m_nValue) = 0;
      if ( (m_nValue & 1) != 0 )
      {
        vecTarget.y = 15.0;
        vecTarget.z = 15.0;
        flIncTime = 15.0;
        vSplinePoint.z = -15.0;
        flTangentLength = -15.0;
        v79 = -15.0;
        NDebugOverlay::Box(
          origin: &this->m_vecPrevPrevPoint,
          mins: (Vector *)&vSplinePoint.z,
          maxs: (Vector *)&vecTarget.y,
          r: 192,
          g: 0,
          b: 0,
          a: 1,
          flDuration: 0.1);
        vecTarget.y = 20.0;
        vecTarget.z = 20.0;
        flIncTime = 20.0;
        vSplinePoint.z = -20.0;
        flTangentLength = -20.0;
        v79 = -20.0;
        NDebugOverlay::Box(
          origin: &this->m_vecPrevPoint,
          mins: (Vector *)&vSplinePoint.z,
          maxs: (Vector *)&vecTarget.y,
          r: 255,
          g: 0,
          b: 0,
          a: 1,
          flDuration: 0.1);
        vecTarget.y = 20.0;
        vecTarget.z = 20.0;
        flIncTime = 20.0;
        vSplinePoint.z = -20.0;
        flTangentLength = -20.0;
        v79 = -20.0;
        NDebugOverlay::Box(
          origin: &this->m_vecPostPoint,
          mins: (Vector *)&vSplinePoint.z,
          maxs: (Vector *)&vecTarget.y,
          r: 0,
          g: 192,
          b: 0,
          a: 1,
          flDuration: 0.1);
        vecTarget.y = 20.0;
        vecTarget.z = 20.0;
        flIncTime = 20.0;
        vSplinePoint.z = -20.0;
        flTangentLength = -20.0;
        v79 = -20.0;
        NDebugOverlay::Box(
          origin: &this->m_vecPostPostPoint,
          mins: (Vector *)&vSplinePoint.z,
          maxs: (Vector *)&vecTarget.y,
          r: 0,
          g: 128,
          b: 0,
          a: 1,
          flDuration: 0.1);
        vecTarget.y = 10.0;
        vecTarget.z = 10.0;
        flIncTime = 10.0;
        vSplinePoint.z = -10.0;
        flTangentLength = -10.0;
        v79 = -10.0;
        NDebugOverlay::Box(
          origin: &v76,
          mins: (Vector *)&vSplinePoint.z,
          maxs: (Vector *)&vecTarget.y,
          r: 0,
          g: 0,
          b: 255,
          a: 1,
          flDuration: 0.1);
        vecTarget.y = (float)(vecToDesired.x * 40.0) + v76.x;
        vecTarget.z = (float)(vecToDesired.y * 40.0) + v76.y;
        flIncTime = (float)(vecToDesired.z * 40.0) + v76.z;
        NDebugOverlay::Line(
          origin: &v76,
          target: (Vector *)&vecTarget.y,
          r: 0,
          g: 0,
          b: 255,
          noDepthTest: 1,
          duration: 0.1);
        v35 = this->m_pCurrentWaypoint;
        x = v35->planeWaypoint.normal.x;
        v37 = v35->splinePoints[2].z;
        v38 = v35->planeWaypoint.normal.y;
        v39 = v38 * 0.0;
        v40 = v35->planeWaypoint.normal.z * 0.0;
        v41 = v38 - v40;
        v42 = v40 - x;
        v43 = (float)(x * 0.0) - v39;
        *(_QWORD *)&vecTarget.y = *(_QWORD *)&v35->splinePoints[2].x;
        vSplinePoint.z = (float)(v41 * 100.0) + vecTarget.y;
        flIncTime = v37;
        flTangentLength = vecTarget.z + (float)(v42 * 100.0);
        v79 = v37 + (float)(v43 * 100.0);
        vSplineTangent.x = (float)(v41 * -100.0) + vecTarget.y;
        vSplineTangent.y = vecTarget.z + (float)(v42 * -100.0);
        vSplineTangent.z = v37 + (float)(v43 * -100.0);
        NDebugOverlay::Line(
          origin: &vSplineTangent,
          target: (Vector *)&vSplinePoint.z,
          r: 255,
          g: 0,
          b: 0,
          noDepthTest: 1,
          duration: 0.1);
        v44 = this->m_pNextWaypoint;
        v45 = v44->planeWaypoint.normal.x;
        v46 = v44->splinePoints[2].z;
        v47 = v44->planeWaypoint.normal.y;
        v48 = v47 * 0.0;
        v49 = v44->planeWaypoint.normal.z * 0.0;
        v50 = v47 - v49;
        v51 = v49 - v45;
        v52 = v44->splinePoints[2].y;
        v53 = (float)(v45 * 0.0) - v48;
        vecTarget.y = v44->splinePoints[2].x;
        vSplineTangent.x = (float)(v50 * 100.0) + vecTarget.y;
        vSplinePoint.y = v51 * 100.0;
        vSplineTangent.y = v52 + (float)(v51 * 100.0);
        vSplineTangent.z = v46 + (float)(v53 * 100.0);
        vecTarget.y = (float)(v50 * -100.0) + vecTarget.y;
        vecTarget.z = v52 + (float)(v51 * -100.0);
        flIncTime = v46 + (float)(v53 * -100.0);
        NDebugOverlay::Line(
          origin: (Vector *)&vecTarget.y,
          target: &vSplineTangent,
          r: 192,
          g: 0,
          b: 0,
          noDepthTest: 1,
          duration: 0.1);
        m_pParent = g_debug_vehicledriver.m_pParent;
      }
      if ( m_pParent != nullptr )
        v54 = m_pParent->m_Value.m_nValue;
      else
        LOBYTE(v54) = 0;
      if ( (v54 & 2) != 0 )
      {
        for ( i = 0; i < 10; ++i )
        {
          v56 = this->m_pCurrentWaypoint;
          vSplinePoint.z = 0.0;
          flTangentLength = 0.0;
          v79 = 0.0;
          v60 = (double)i * 0.1;
          vSplinePoint.y = v60;
          Catmull_Rom_Spline(
            p1: v56->splinePoints,
            p2: &v56->splinePoints[1],
            p3: &v56->splinePoints[2],
            p4: &v56->splinePoints[3],
            t: v60,
            output: (Vector *)&vSplinePoint.z);
          v57 = this->m_pCurrentWaypoint;
          vecTarget.y = 0.0;
          vecTarget.z = 0.0;
          flIncTime = 0.0;
          Catmull_Rom_Spline_Tangent(
            p1: v57->splinePoints,
            p2: &v57->splinePoints[1],
            p3: &v57->splinePoints[2],
            p4: &v57->splinePoints[3],
            t: vSplinePoint.y,
            output: (Vector *)&vecTarget.y);
          VectorNormalize(vec: (Vector *)&vecTarget.y);
          vSplineTangent.x = 10.0;
          vSplineTangent.y = 10.0;
          vSplineTangent.z = 10.0;
          vecVelocity.x = -10.0;
          vecVelocity.y = -10.0;
          vecVelocity.z = -10.0;
          NDebugOverlay::Box(
            origin: (Vector *)&vSplinePoint.z,
            mins: &vecVelocity,
            maxs: &vSplineTangent,
            r: 255,
            g: 0,
            b: 0,
            a: 1,
            flDuration: 0.1);
          *((float *)&vecRight + 1) = (float)(vecTarget.y * 10.0) + vSplinePoint.z;
          *((float *)&vecRight + 2) = (float)(vecTarget.z * 10.0) + flTangentLength;
          *((float *)&vecRight + 3) = (float)(flIncTime * 10.0) + v79;
          NDebugOverlay::Line(
            origin: (Vector *)&vSplinePoint.z,
            target: (const Vector *)((char *)&vecRight + 4),
            r: 255,
            g: 255,
            b: 0,
            noDepthTest: 1,
            duration: 0.1);
        }
      }
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10179C60
// Name: public: virtual void CNPC_VehicleDriver::DriveVehicle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::DriveVehicle(CNPC_VehicleDriver *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v4; // ecx
  int m_nValue; // eax
  int m_iEFlags; // edx
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx
  float y; // xmm0_4
  float x; // xmm1_4
  float z; // xmm2_4
  char v12; // bl
  float m_flGoalSpeed; // xmm1_4
  IServerVehicle_vtbl *v14; // edx
  void (*NPC_ThrottleReverse)(void); // eax
  IServerVehicle_vtbl *v16; // edx
  float v17; // xmm1_4
  IServerVehicle_vtbl *v18; // edx
  float v19; // xmm0_4
  Vector angVel; // [esp+1Ch] [ebp-50h] BYREF
  Vector vecRight; // [esp+28h] [ebp-44h] BYREF
  Vector vecForward; // [esp+34h] [ebp-38h] BYREF
  Vector mins; // [esp+40h] [ebp-2Ch] BYREF
  Vector maxs; // [esp+4Ch] [ebp-20h] BYREF
  Vector vecVelocity; // [esp+58h] [ebp-14h] BYREF
  float flSpeed; // [esp+64h] [ebp-8h]
  bool bBehind; // [esp+6Bh] [ebp-1h]
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF

  m_Index = this->m_hVehicleEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v4 = m_pEntity[82].__vftable;
  if ( v4 != nullptr )
  {
    (*((void (__thiscall **)(IHandleEntity_vtbl *, Vector *, Vector *))v4->dtr_IHandleEntity + 52))(
      a1: v4,
      a2: &vecVelocity,
      a3: &angVel);
    flSpeed = VectorNormalize(vec: &vecVelocity);
    if ( this->m_flMaxSpeed == 0.0
      || vec3_origin.x == this->m_vecDesiredPosition.x
      && vec3_origin.y == this->m_vecDesiredPosition.y
      && vec3_origin.z == this->m_vecDesiredPosition.z )
    {
      if ( flSpeed > 1.0 )
        this->m_pVehicleInterface->NPC_Brake(this: this->m_pVehicleInterface);
    }
    else
    {
      if ( g_debug_vehicledriver.m_pParent != nullptr )
        m_nValue = g_debug_vehicledriver.m_pParent->m_Value.m_nValue;
      else
        LOBYTE(m_nValue) = 0;
      if ( (m_nValue & 1) != 0 )
      {
        maxs.x = 20.0;
        maxs.y = 20.0;
        maxs.z = 20.0;
        mins.x = -20.0;
        mins.y = -20.0;
        mins.z = -20.0;
        NDebugOverlay::Box(origin: &this->m_vecDesiredPosition, &mins, &maxs, r: 0, g: 255, b: 0, a: 1, flDuration: 0.1);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        m_iEFlags = this->m_iEFlags;
        mins.x = this->m_vecAbsOrigin.x + this->m_vecDesiredVelocity.x;
        mins.y = this->m_vecAbsOrigin.y + this->m_vecDesiredVelocity.y;
        mins.z = this->m_vecAbsOrigin.z + this->m_vecDesiredVelocity.z;
        if ( (m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        NDebugOverlay::Line(
          origin: &this->m_vecAbsOrigin,
          target: &mins,
          r: 0,
          g: 255,
          b: 0,
          noDepthTest: 1,
          duration: 0.1);
      }
      this->m_flGoalSpeed = VectorNormalize(vec: &this->m_vecDesiredVelocity);
      v7 = this->m_hVehicleEntity.m_Index;
      if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
        v8 = nullptr;
      else
        v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      ((void (__thiscall *)(IHandleEntity *, Vector *, Vector *, _DWORD))v8->__vftable[44].dtr_IHandleEntity)(
        a1: v8,
        a2: &vecForward,
        a3: &vecRight,
        a4: 0);
      y = this->m_vecDesiredVelocity.y;
      x = this->m_vecDesiredVelocity.x;
      z = this->m_vecDesiredVelocity.z;
      if ( (float)((float)((float)(y * vecForward.y) + (float)(x * vecForward.x)) + (float)(z * vecForward.z)) >= 0.0 )
      {
        bBehind = false;
        v12 = 0;
      }
      else
      {
        v12 = 1;
      }
      if ( (float)((float)((float)(y * vecVelocity.y) + (float)(x * vecVelocity.x)) + (float)(z * vecVelocity.z)) < 0.0
        || (m_flGoalSpeed = this->m_flGoalSpeed) > flSpeed )
      {
        v16 = this->m_pVehicleInterface->__vftable;
        if ( v12 != 0 )
          NPC_ThrottleReverse = (void (*)(void))v16->NPC_ThrottleReverse;
        else
          NPC_ThrottleReverse = (void (*)(void))v16->NPC_ThrottleForward;
      }
      else
      {
        v14 = this->m_pVehicleInterface->__vftable;
        if ( (float)(flSpeed - 200.0) <= m_flGoalSpeed )
          NPC_ThrottleReverse = (void (*)(void))v14->NPC_ThrottleCenter;
        else
          NPC_ThrottleReverse = (void (*)(void))v14->NPC_Brake;
      }
      NPC_ThrottleReverse();
      v17 = (float)((float)(vecRight.x * this->m_vecDesiredVelocity.x)
                  + (float)(this->m_vecDesiredVelocity.y * vecRight.y))
          + (float)(vecRight.z * this->m_vecDesiredVelocity.z);
      if ( v12 != 0 )
        v17 = v17 * -1.0;
      v18 = this->m_pVehicleInterface->__vftable;
      v19 = (float)(this->m_flSteering * 0.011111111) * v17;
      if ( v19 >= 0.0 )
      {
        if ( v19 <= 0.0 )
          ((void (*)(void))v18->NPC_TurnCenter)();
        else
          ((void (__stdcall *)(float))v18->NPC_TurnRight)(a1: COERCE_FLOAT(LODWORD(v19)));
      }
      else
      {
        ((void (__stdcall *)(_DWORD))v18->NPC_TurnLeft)(a1: LODWORD(v19) ^ _mask__NegFloat_);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10179FF0
// Name: public: void CNPC_VehicleDriver::CheckForTeleport(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNPC_VehicleDriver::CheckForTeleport(CNPC_VehicleDriver *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *v11; // eax
  CPathTrack *v12; // eax
  CPathTrack *v13; // edi
  unsigned int v14; // eax
  IHandleEntity *m_pEntity; // eax
  int v16; // eax
  float v17; // xmm0_4
  unsigned int v18; // eax
  IHandleEntity *v19; // ecx
  float *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  unsigned int v24; // eax
  int m_iEFlags; // ecx
  float z; // edx
  CPathTrack *Next; // eax
  float *v28; // esi
  float v29; // xmm1_4
  float v30; // xmm2_4
  unsigned int v31; // eax
  IHandleEntity *v32; // ecx
  unsigned int v33; // eax
  IHandleEntity *v34; // ecx
  const Vector *v35; // eax
  unsigned int v36; // eax
  CBaseEntity *v37; // esi
  Vector vecTarget; // [esp+10h] [ebp-3Ch] BYREF
  QAngle vecAngles; // [esp+1Ch] [ebp-30h] BYREF
  float v41; // [esp+28h] [ebp-24h]
  float v42; // [esp+2Ch] [ebp-20h]
  float v43; // [esp+30h] [ebp-1Ch]
  Vector vecToTarget; // [esp+34h] [ebp-18h] BYREF
  Vector vecMins; // [esp+40h] [ebp-Ch]
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  m_Index = this->m_hGoalEnt.m_Index;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = &g_pEntityList->m_EntPtrArray[v8];
      v11 = v9 ? v10->m_pEntity : nullptr;
      v12 = (CPathTrack *)__RTDynamicCast(
                            inptr: v11,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CPathTrack `RTTI Type Descriptor',
                            isReference: 0);
      v13 = v12;
      if ( v12 != nullptr && (v12->m_spawnflags.m_Value & 0x10) != 0 )
      {
        CBaseEntity::AddEffects(this, nEffects: 8);
        v14 = this->m_hVehicleEntity.m_Index;
        if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
        v16 = ((int (__thiscall *)(IHandleEntity *, int, int))m_pEntity[57].SetRefEHandle)(a1: &m_pEntity[57], a2, a3);
        vecMins.x = *(float *)v16;
        vecMins.y = *(float *)(v16 + 4);
        v17 = *(float *)(v16 + 8);
        v18 = this->m_hVehicleEntity.m_Index;
        vecMins.z = v17;
        if ( v18 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
          v19 = nullptr;
        else
          v19 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
        v20 = (float *)v19[57].GetRefEHandle(this: v19 + 57);
        v21 = v20[2];
        v22 = *v20;
        v23 = v20[1];
        v24 = (unsigned int)v13->m_iEFlags >> 11;
        v41 = (float)(v22 + vecMins.x) * 0.5;
        v42 = (float)(v23 + vecMins.y) * 0.5;
        v43 = (float)(vecMins.z + v21) * 0.5;
        if ( (v24 & 1) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
        m_iEFlags = v13->m_iEFlags;
        vecTarget.x = v13->m_vecAbsOrigin.x - v41;
        vecTarget.y = v13->m_vecAbsOrigin.y - v42;
        vecTarget.z = (float)((float)((float)(v21 - vecMins.z) * 0.5) + 8.0) + (float)(v13->m_vecAbsOrigin.z - v43);
        if ( (m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
        z = v13->m_angAbsRotation.z;
        *(_QWORD *)&vecAngles.x = *(_QWORD *)&v13->m_angAbsRotation.x;
        vecAngles.z = z;
        vecToTarget = vec3_origin;
        if ( CPathTrack::GetNext(this: v13) != nullptr )
        {
          if ( (v13->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
          Next = CPathTrack::GetNext(this: v13);
          v28 = (float *)Next;
          if ( (Next->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: Next, a2: (int)&savedregs);
          v29 = v28[116] - v13->m_vecAbsOrigin.y;
          v30 = v28[117] - v13->m_vecAbsOrigin.z;
          vecToTarget.x = v28[115] - v13->m_vecAbsOrigin.x;
          vecToTarget.y = v29;
          vecToTarget.z = v30;
          VectorNormalize(vec: &vecToTarget);
          VectorAngles(forward: &vecToTarget, angles: &vecAngles);
          vecAngles.y = vecAngles.y - 90.0;
        }
        v31 = this->m_hVehicleEntity.m_Index;
        if ( v31 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v31].m_SerialNumber != HIWORD(v31) )
          v32 = nullptr;
        else
          v32 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v31].m_pEntity;
        ((void (__thiscall *)(IHandleEntity *, Vector *, QAngle *))v32->__vftable[37].dtr_IHandleEntity)(
          a1: v32,
          a2: &vecTarget,
          a3: &vecAngles);
        v33 = this->m_hVehicleEntity.m_Index;
        if ( v33 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_SerialNumber != HIWORD(v33) )
          v34 = nullptr;
        else
          v34 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_pEntity;
        v35 = (const Vector *)((int (__thiscall *)(IHandleEntity *))v34->__vftable[49].dtr_IHandleEntity)(a1: v34);
        CBaseEntity::SetAbsOrigin(this, absOrigin: v35);
        v36 = this->m_hVehicleEntity.m_Index;
        if ( v36 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_SerialNumber != HIWORD(v36) )
          v37 = nullptr;
        else
          v37 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_pEntity;
        if ( (v37->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v37, a2: (int)&savedregs);
        CBaseEntity::SetAbsAngles(this, absAngles: &v37->m_angAbsRotation);
        if ( (v13->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
        this->m_vecPrevPoint.x = v13->m_vecAbsOrigin.x;
        this->m_vecPrevPoint.y = v13->m_vecAbsOrigin.y;
        this->m_vecPrevPoint.z = v13->m_vecAbsOrigin.z;
        if ( this->m_pNavigator->m_pPath != nullptr )
          CNPC_VehicleDriver::WaypointReached(this, a2: (int)&savedregs);
        CNPC_VehicleDriver::ClearWaypoints(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A400
// Name: public: virtual void CNPC_VehicleDriver::StartTask(struct Task_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNPC_VehicleDriver::StartTask(CNPC_VehicleDriver *this@<ecx>, int a2@<edi>, const Task_t *pTask)
{
  int m_nValue; // eax
  CBaseEntity *GoalEnt; // eax
  const Vector *AbsOrigin; // eax
  CBaseEntity *v7; // eax
  Activity StoppedActivity; // eax
  CBaseEntity *flDuration; // [esp+8h] [ebp-50h]
  AI_NavGoal_t goal; // [esp+10h] [ebp-48h] BYREF
  Vector mins; // [esp+40h] [ebp-18h] BYREF
  Vector maxs; // [esp+4Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  switch ( pTask->iTask )
  {
    case 0x31:
    case 0x32:
    case 0x3F:
    case 0x43:
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      break;
    case 0x82:
      if ( CAI_Navigator::GetGoalType(this: this->m_pNavigator) != 0 )
      {
        if ( CAI_Navigator::IsGoalActive(this: this->m_pNavigator) )
        {
          this->ValidateNavGoal(this);
        }
        else
        {
          StoppedActivity = CAI_BaseNPC::GetStoppedActivity(this);
          CAI_BaseNPC::SetIdealActivity(this, NewActivity: StoppedActivity);
        }
      }
      else
      {
        CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
        CAI_Navigator::StopMoving(this: this->m_pNavigator, bImmediate: true);
      }
      break;
    case 0x97:
      if ( CAI_BaseNPC::GetGoalEnt(this) != nullptr )
      {
        CNPC_VehicleDriver::CheckForTeleport(this, a2, a3: (int)this);
        if ( g_debug_vehicledriver.m_pParent != nullptr )
          m_nValue = g_debug_vehicledriver.m_pParent->m_Value.m_nValue;
        else
          LOBYTE(m_nValue) = 0;
        if ( (m_nValue & 1) != 0 )
        {
          maxs.x = 50.0;
          maxs.y = 50.0;
          maxs.z = 50.0;
          mins.x = -50.0;
          mins.y = -50.0;
          mins.z = -50.0;
          GoalEnt = CAI_BaseNPC::GetGoalEnt(this);
          AbsOrigin = CBaseEntity::GetAbsOrigin(this: GoalEnt);
          NDebugOverlay::Box(origin: AbsOrigin, &mins, &maxs, r: 255, g: 255, b: 255, a: 1, flDuration: 5.0);
        }
        flDuration = AIN_DEF_TARGET_71;
        v7 = CAI_BaseNPC::GetGoalEnt(this);
        AI_NavGoal_t::AI_NavGoal_t(
          this: &goal,
          type: GOALTYPE_PATHCORNER,
          dest: &v7->m_vecOrigin.m_Value,
          activity: ACT_WALK,
          tolerance: -1.0,
          flags: 1u,
          pTarget: flDuration);
        if ( this->m_pNavigator->SetGoal(this: this->m_pNavigator, a2: &goal, a3: 0) )
          CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
        else
          this->TaskFail(this, a2: 11);
      }
      else
      {
        this->TaskFail(this, a2: 1);
      }
      break;
    default:
      CAI_BaseNPC::StartTask(this, a2: COERCE_FLOAT(&savedregs), a3: *(float *)&a2, a4: (Vector *)this, pTask);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A630
// Name: public: virtual bool CNPC_VehicleDriver::OverrideMove(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNPC_VehicleDriver::OverrideMove(CNPC_VehicleDriver *this, float flInterval)
{
  unsigned int m_Index; // edx
  CBaseEntityList *v4; // esi
  int v5; // ecx
  CEntInfo *v6; // eax
  unsigned int v7; // edx
  int v8; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v10; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  m_Index = this->m_hVehicleEntity.m_Index;
  if ( m_Index != -1 )
  {
    v4 = g_pEntityList;
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      if ( this->m_flMaxSpeed == 0.0
        || ((v8 = v5, g_pEntityList->m_EntPtrArray[v8].m_SerialNumber != v7)
          ? (m_pEntity = nullptr)
          : (m_pEntity = g_pEntityList->m_EntPtrArray[v8].m_pEntity),
            (v10 = m_pEntity[52].__vftable) != (IHandleEntity_vtbl *)-1
         && g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == (unsigned int)v10 >> 16
         && g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity != nullptr) )
      {
        this->m_pVehicleInterface->NPC_Brake(this: this->m_pVehicleInterface);
      }
      else if ( CAI_Navigator::IsGoalActive(this: this->m_pNavigator) )
      {
        CNPC_VehicleDriver::OverridePathMove(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this, a4: (int)v4, flInterval);
        return 1;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017A710
// Name: public: virtual void CNPC_VehicleDriver::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::Spawn(CNPC_VehicleDriver *this)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  edict_t *m_pPev; // ecx
  CAI_Navigator *m_pNavigator; // eax
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi

  this->Precache(this);
  CBaseCombatCharacter::Spawn(this);
  CAI_BaseNPC::CapabilitiesClear(this);
  CAI_BaseNPC::CapabilitiesAdd(this, capability: 1);
  CAI_BaseNPC::CapabilitiesAdd(this, capability: 64);
  this->SetModel(this, a2: "models/roller_vehicledriver.mdl");
  this->m_eHull = HULL_LARGE;
  CAI_BaseNPC::SetHullSizeNormal(this, force: false);
  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value != 1 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    p_m_iHealth->m_Value = 1;
  }
  if ( this->m_iMaxHealth.m_Value != p_m_iHealth->m_Value )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    this->m_iMaxHealth.m_Value = p_m_iHealth->m_Value;
  }
  this->m_flFieldOfView = -1.0;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::AddEffects(this, nEffects: 32);
  if ( this->m_lifeState.m_Value != 0 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    this->m_lifeState.m_Value = 0;
  }
  if ( this->m_flCycle.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flCycle.m_Value = 0.0;
  }
  CBaseAnimating::ResetSequenceInfo(this);
  CBaseEntity::AddFlag(this, flags: 0x4000);
  this->m_flGoalSpeed = this->m_flInitialSpeed;
  this->m_flMaxSpeed = 0.0;
  this->m_vecDesiredVelocity = vec3_origin;
  this->m_vecPrevPoint = vec3_origin;
  this->m_vecPrevPrevPoint = vec3_origin;
  this->m_vecPostPoint = vec3_origin;
  this->m_vecPostPostPoint = vec3_origin;
  this->m_vecDesiredPosition = vec3_origin;
  m_pNavigator = this->m_pNavigator;
  this->m_flSteering = 45.0;
  this->m_flDistanceAlongSpline = 0.2;
  this->m_pNextWaypoint = nullptr;
  this->m_pCurrentWaypoint = nullptr;
  m_pNavigator->m_bNoPathcornerPathfinds = true;
  this->NPCInit(this);
  p_m_takedamage = &this->m_takedamage;
  if ( p_m_takedamage->m_Value != 0 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *))(*(_DWORD *)&p_m_takedamage[-554].m_Value + 756))(
      a1: p_m_takedamage - 554,
      a2: p_m_takedamage);
    p_m_takedamage->m_Value = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017AA10
// Name: public: void CNPC_VehicleDriver::InputStartForward(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::InputStartForward(CNPC_VehicleDriver *this, inputdata_t *inputdata)
{
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx
  const vehicleparams_t *v5; // eax

  v3 = this->m_spawnflags.m_Value & 0xFFFEFFFF;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
    }
    this->m_spawnflags.m_Value = v3;
  }
  if ( this->m_NPCState == NPC_STATE_IDLE )
    CAI_BaseNPC::SetState(this, State: NPC_STATE_ALERT);
  CAI_BaseNPC::SetCondition(this, iCondition: 25);
  v5 = this->m_pVehicleInterface->GetVehicleParams(this: this->m_pVehicleInterface);
  if ( v5 != nullptr )
  {
    this->m_flMaxSpeed = this->m_flDriversMaxSpeed * v5->engine.maxSpeed;
    this->m_flSteering = v5->steering.degreesSlow;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017AAB0
// Name: public: void CNPC_VehicleDriver::InputStartFiring(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::InputStartFiring(CNPC_VehicleDriver *this, inputdata_t *inputdata)
{
  unsigned int v3; // ebx
  edict_t *m_pPev; // ecx
  float flDistLook; // xmm0_4
  float v6; // xmm0_4
  float flMinRange; // [esp+20h] [ebp-8h] BYREF
  float flMaxRange; // [esp+24h] [ebp-4h] BYREF

  v3 = this->m_spawnflags.m_Value & 0xFFFEFFFF;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
    }
    this->m_spawnflags.m_Value = v3;
  }
  CAI_BaseNPC::SetCondition(this, iCondition: 25);
  if ( this->m_pVehicleInterface->NPC_HasPrimaryWeapon(this: this->m_pVehicleInterface) )
  {
    CAI_BaseNPC::CapabilitiesAdd(this, capability: 0x20000);
    this->m_pVehicleInterface->Weapon_PrimaryRanges(this: this->m_pVehicleInterface, a2: &flMinRange, a3: &flMaxRange);
    flDistLook = flMaxRange;
    if ( flMaxRange > this->m_flDistTooFar || flMaxRange > this->m_pSenses->m_LookDist )
    {
      this->m_flDistTooFar = flMaxRange;
      CAI_BaseNPC::SetDistLook(this, flDistLook);
    }
  }
  if ( this->m_pVehicleInterface->NPC_HasSecondaryWeapon(this: this->m_pVehicleInterface) )
  {
    CAI_BaseNPC::CapabilitiesAdd(this, capability: 0x40000);
    this->m_pVehicleInterface->Weapon_SecondaryRanges(this: this->m_pVehicleInterface, a2: &flMinRange, a3: &flMaxRange);
    v6 = flMaxRange;
    if ( flMaxRange > this->m_flDistTooFar || flMaxRange > this->m_pSenses->m_LookDist )
    {
      this->m_flDistTooFar = flMaxRange;
      CAI_BaseNPC::SetDistLook(this, flDistLook: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017ABE0
// Name: public: void CNPC_VehicleDriver::InputGotoPathCorner(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_VehicleDriver::InputGotoPathCorner(CNPC_VehicleDriver *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax
  const char *iVal; // ebx
  CBasePlayer *EntityByName; // edi
  const char *pszValue; // esi
  int v7; // [esp+8h] [ebp-4h] BYREF

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    v7 = 0;
    p_value = (variant_t *)&v7;
  }
  iVal = (const char *)p_value->iVal;
  if ( p_value->iVal != 0 )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: iVal,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
    {
      CNPC_VehicleDriver::ClearWaypoints(this);
      this->m_hGoalEnt.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
      if ( this->m_NPCState == NPC_STATE_IDLE )
        CAI_BaseNPC::SetState(this, State: NPC_STATE_ALERT);
      CAI_BaseNPC::SetCondition(this, iCondition: 25);
      CNPC_VehicleDriver::InputStartForward(this, inputdata);
    }
    else
    {
      pszValue = this->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      _Warning(a1: "npc_vehicledriver %s couldn't find entity named %s\n", pszValue, iVal);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017ACA0
// Name: public: static void CNPC_VehicleDriver::InitCustomSchedules(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CNPC_VehicleDriver::InitCustomSchedules()
{
  char **m_pMemory; // esi
  int m_Size; // edi
  int v2; // eax
  int localId; // ecx
  int v4; // edi
  int v5; // eax
  char **v6; // eax
  int v7; // ecx
  int v8; // edi
  int v9; // eax
  char **v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  char fValid; // al
  CUtlVector<bool (__cdecl*)(void),CUtlMemory<bool (__cdecl*)(void),int> > reqiredOthers; // [esp+Ch] [ebp-80h] BYREF
  CAI_NamespaceInfos squadSlotIds; // [esp+20h] [ebp-6Ch] BYREF
  CAI_NamespaceInfos conditionIds; // [esp+34h] [ebp-58h] BYREF
  CAI_NamespaceInfos taskIds; // [esp+48h] [ebp-44h] BYREF
  CAI_NamespaceInfos scheduleIds; // [esp+5Ch] [ebp-30h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > schedulesToLoad; // [esp+70h] [ebp-1Ch] BYREF
  AI_NamespaceAddInfo_t src; // [esp+84h] [ebp-8h] BYREF

  memset(&schedulesToLoad, 0, sizeof(schedulesToLoad));
  memset(&reqiredOthers, 0, sizeof(reqiredOthers));
  memset(&scheduleIds, 0, sizeof(scheduleIds));
  memset(&taskIds, 0, sizeof(taskIds));
  memset(&conditionIds, 0, sizeof(conditionIds));
  memset(&squadSlotIds, 0, sizeof(squadSlotIds));
  src.pszName = "TASK_VEHICLEDRIVER_GET_PATH";
  src.localId = 151;
  CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
    this: &taskIds,
    elem: 0,
    &src);
  src.pszName = "SCHED_VEHICLEDRIVER_INACTIVE";
  src.localId = 89;
  CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
    this: &scheduleIds,
    elem: 0,
    &src);
  CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&schedulesToLoad, num: 1);
  m_pMemory = schedulesToLoad.m_Memory.m_pMemory;
  m_Size = schedulesToLoad.m_Size + 1;
  v2 = schedulesToLoad.m_Size++;
  schedulesToLoad.m_pElements = schedulesToLoad.m_Memory.m_pMemory;
  if ( v2 > 0 )
    _V_memmove(dest: schedulesToLoad.m_Memory.m_pMemory + 1, src: schedulesToLoad.m_Memory.m_pMemory, count: 4 * v2);
  if ( m_pMemory != nullptr )
    *m_pMemory = "\n"
                 "\tSchedule\n"
                 "\t\tSCHED_VEHICLEDRIVER_INACTIVE\tTasks\t\tTASK_WAIT_INDEFINITE\t0\tInterrupts\t\tCOND_PROVOKED\n";
  src.pszName = "SCHED_VEHICLEDRIVER_COMBAT_WAIT";
  src.localId = 90;
  CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
    this: &scheduleIds,
    elem: scheduleIds.m_Size,
    &src);
  localId = m_Size;
  src.localId = m_Size;
  if ( m_Size + 1 > schedulesToLoad.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&schedulesToLoad,
      num: m_Size - schedulesToLoad.m_Memory.m_nAllocationCount + 1);
    m_Size = schedulesToLoad.m_Size;
    m_pMemory = schedulesToLoad.m_Memory.m_pMemory;
    localId = src.localId;
  }
  v4 = m_Size + 1;
  v5 = v4 - localId - 1;
  schedulesToLoad.m_Size = v4;
  schedulesToLoad.m_pElements = m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(dest: &m_pMemory[localId + 1], src: &m_pMemory[localId], count: 4 * v5);
    localId = src.localId;
  }
  v6 = &m_pMemory[localId];
  if ( v6 != nullptr )
    *v6 = "\n"
          "\tSchedule\n"
          "\t\tSCHED_VEHICLEDRIVER_COMBAT_WAIT\tTasks\t\tTASK_WAIT\t\t\t\t5\tInterrupts\t\tCOND_NEW_ENEMY\t\tCOND_LIGHT_D"
          "AMAGE\t\tCOND_HEAVY_DAMAGE\t\tCOND_PROVOKED\t\tCOND_CAN_RANGE_ATTACK1\t\tCOND_CAN_RANGE_ATTACK2\n";
  src.pszName = "SCHED_VEHICLEDRIVER_DRIVE_PATH";
  src.localId = 91;
  CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
    this: &scheduleIds,
    elem: scheduleIds.m_Size,
    &src);
  v7 = v4;
  src.localId = v4;
  if ( v4 + 1 > schedulesToLoad.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&schedulesToLoad,
      num: v4 - schedulesToLoad.m_Memory.m_nAllocationCount + 1);
    v4 = schedulesToLoad.m_Size;
    m_pMemory = schedulesToLoad.m_Memory.m_pMemory;
    v7 = src.localId;
  }
  v8 = v4 + 1;
  v9 = v8 - v7 - 1;
  schedulesToLoad.m_Size = v8;
  schedulesToLoad.m_pElements = m_pMemory;
  if ( v9 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * v9);
    v7 = src.localId;
  }
  v10 = &m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = "\n"
           "\tSchedule\n"
           "\t\tSCHED_VEHICLEDRIVER_DRIVE_PATH\tTasks\t\tTASK_VEHICLEDRIVER_GET_PATH\t\t0\t\tTASK_WALK_PATH\t\t\t\t\t9999"
           "\t\tTASK_WAIT_FOR_MOVEMENT\t\t\t0\t\tTASK_WAIT_PVS\t\t\t\t\t0\tInterrupts\t\tCOND_NEW_ENEMY\t\tCOND_PROVOKED\n";
  CAI_ClassScheduleIdSpace::Init(
    this: &CNPC_VehicleDriver::gm_ClassScheduleIdSpace,
    pszClassName: "CNPC_VehicleDriver",
    pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols,
    pParentIDSpace: &CAI_BaseNPC::gm_ClassScheduleIdSpace);
  CAI_LocalIdSpace::Init(
    this: &CNPC_VehicleDriver::gm_SquadSlotIdSpace,
    pGlobalNamespace: &CAI_BaseNPC::gm_SquadSlotNamespace,
    pParentIDSpace: &CAI_BaseNPC::gm_SquadSlotIdSpace);
  CUtlVector<CPassengerSeatTransition,CUtlMemory<CPassengerSeatTransition,int>>::Sort(
    this: &scheduleIds,
    pfnCompare: (int (__cdecl *)(const void *, const void *))CAI_NamespaceInfos::Compare);
  CUtlVector<CPassengerSeatTransition,CUtlMemory<CPassengerSeatTransition,int>>::Sort(
    this: &taskIds,
    pfnCompare: (int (__cdecl *)(const void *, const void *))CAI_NamespaceInfos::Compare);
  CUtlVector<CPassengerSeatTransition,CUtlMemory<CPassengerSeatTransition,int>>::Sort(
    this: &conditionIds,
    pfnCompare: (int (__cdecl *)(const void *, const void *))CAI_NamespaceInfos::Compare);
  CUtlVector<CPassengerSeatTransition,CUtlMemory<CPassengerSeatTransition,int>>::Sort(
    this: &squadSlotIds,
    pfnCompare: (int (__cdecl *)(const void *, const void *))CAI_NamespaceInfos::Compare);
  v11 = 0;
  if ( scheduleIds.m_Size <= 0 )
  {
LABEL_20:
    v12 = 0;
    if ( taskIds.m_Size <= 0 )
    {
LABEL_23:
      v13 = 0;
      if ( v8 > 0 )
      {
        fValid = CNPC_VehicleDriver::gm_SchedLoadStatus.fValid;
        do
        {
          if ( fValid == 0 )
            break;
          fValid = CAI_SchedulesManager::LoadSchedulesFromBuffer(
                     this: &g_AI_SchedulesManager,
                     prefix: "CNPC_VehicleDriver",
                     pStartFile: schedulesToLoad.m_Memory.m_pMemory[v13++],
                     pIdSpace: &CNPC_VehicleDriver::gm_ClassScheduleIdSpace,
                     pGlobalNamespace: &CAI_BaseNPC::gm_SchedulingSymbols);
          CNPC_VehicleDriver::gm_SchedLoadStatus.fValid = fValid;
        }
        while ( v13 < v8 );
      }
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&conditionIds);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&taskIds);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&scheduleIds);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&reqiredOthers);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&schedulesToLoad);
      return;
    }
    while ( CAI_LocalIdSpace::AddSymbol(
              this: &CNPC_VehicleDriver::gm_ClassScheduleIdSpace.m_TaskIds,
              pszSymbol: taskIds.m_Memory.m_pMemory[v12].pszName,
              localId: taskIds.m_Memory.m_pMemory[v12].localId,
              pszDebugSymbolType: "task",
              pszDebugOwner: CNPC_VehicleDriver::gm_pszErrorClassName) != 0 )
    {
      if ( ++v12 >= taskIds.m_Size )
        goto LABEL_23;
    }
  }
  else
  {
    while ( CAI_LocalIdSpace::AddSymbol(
              this: &CNPC_VehicleDriver::gm_ClassScheduleIdSpace.m_ScheduleIds,
              pszSymbol: scheduleIds.m_Memory.m_pMemory[v11].pszName,
              localId: scheduleIds.m_Memory.m_pMemory[v11].localId,
              pszDebugSymbolType: "schedule",
              pszDebugOwner: CNPC_VehicleDriver::gm_pszErrorClassName) != 0 )
    {
      if ( ++v11 >= scheduleIds.m_Size )
        goto LABEL_20;
    }
  }
  if ( taskIds.m_Memory.m_nGrowSize >= 0 && taskIds.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: taskIds.m_Memory.m_pMemory);
  if ( scheduleIds.m_Memory.m_nGrowSize >= 0 && scheduleIds.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: scheduleIds.m_Memory.m_pMemory);
  if ( schedulesToLoad.m_Memory.m_nGrowSize >= 0 && schedulesToLoad.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: schedulesToLoad.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1017B080
// Name: public: CNPC_VehicleDriver::CNPC_VehicleDriver(void)
// Source: json
//------------------------------------------------------------------------------
CNPC_VehicleDriver *__thiscall CNPC_VehicleDriver::CNPC_VehicleDriver(CNPC_VehicleDriver *this)
{
  vgui::Panel *v2; // ecx

  CAI_BaseNPC::CAI_BaseNPC(this);
  this->CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CNPC_VehicleDriver_vtbl *)&CNPC_VehicleDriver::`vftable'{for `CBaseCombatCharacter'};
  this->CAI_BaseNPC::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CNPC_VehicleDriver::`vftable'{for `CAI_DefMovementSink'};
  this->CAI_BaseNPC::IAI_BehaviorBridge::__vftable = (IAI_BehaviorBridge_vtbl *)&CNPC_VehicleDriver::`vftable'{for `IAI_BehaviorBridge'};
  CAI_BaseNPC::CreateBehaviors(this: v2);
  if ( CNPC_VehicleDriver::gm_SchedLoadStatus.signature != g_AI_SchedulesManager.m_CurLoadSig )
  {
    CNPC_VehicleDriver::InitCustomSchedules();
    CNPC_VehicleDriver::gm_SchedLoadStatus.fValid = true;
    CNPC_VehicleDriver::gm_SchedLoadStatus.signature = g_AI_SchedulesManager.m_CurLoadSig;
  }
  this->m_hVehicleEntity.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10406870
// Name: CNPC_VehicleDriver_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CNPC_VehicleDriver_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CNPC_VehicleDriver>(__formal: nullptr);
  CNPC_VehicleDriver_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017B000
// Name: struct datamap_t __near * DataMapInit<class CNPC_VehicleDriver>(class CNPC_VehicleDriver __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CNPC_VehicleDriver>()
{
  if ( (_S2_157 & 1) == 0 )
  {
    _S2_157 |= 1u;
    nameHolder_284.m_pszBase = "CNPC_VehicleDriver";
    nameHolder_284.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_284.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_284.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_284.m_Names.m_Size = 0;
    nameHolder_284.m_Names.m_pElements = nullptr;
    nameHolder_284.m_nLenBase = 18;
    atexit(func: DataMapInit_CNPC_VehicleDriver__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CNPC_VehicleDriver::m_DataMap.baseMap = &CAI_BaseNPC::m_DataMap;
  CNPC_VehicleDriver::m_DataMap.dataNumFields = 21;
  CNPC_VehicleDriver::m_DataMap.dataDesc = &dataDesc_271[1];
  return &CNPC_VehicleDriver::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10406880
// Name: _dynamic_initializer_for__npc_vehicledriver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__npc_vehicledriver__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CNPC_VehicleDriver> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &npc_vehicledriver,
           a3: "npc_vehicledriver");
}

//------------------------------------------------------------------------------
// Address: 0x104068A0
// Name: _dynamic_initializer_for__CNPC_VehicleDriver::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CNPC_VehicleDriver::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CNPC_VehicleDriver::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CNPC_VehicleDriver::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(
           this: &CNPC_VehicleDriver::gm_ClassScheduleIdSpace.m_ConditionIds,
           fIsRoot: false);
}

//------------------------------------------------------------------------------
// Address: 0x104068D0
// Name: _dynamic_initializer_for__CNPC_VehicleDriver::gm_SquadSlotIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CNPC_VehicleDriver::gm_SquadSlotIdSpace__()
{
  return CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CNPC_VehicleDriver::gm_SquadSlotIdSpace, fIsRoot: false);
}

//------------------------------------------------------------------------------
// Address: 0x104068E0
// Name: _dynamic_initializer_for__sv_pushaway_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_force__()
{
  ConVar::ConVar(
    this: &sv_pushaway_force,
    pName: "sv_pushaway_force",
    pDefaultValue: "30000",
    flags: 8194,
    pHelpString: "How hard physics objects are pushed away from the players on the server.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_force__);
}

//------------------------------------------------------------------------------
// Address: 0x10406910
// Name: _dynamic_initializer_for__sv_pushaway_min_player_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_min_player_speed__()
{
  ConVar::ConVar(
    this: &sv_pushaway_min_player_speed,
    pName: "sv_pushaway_min_player_speed",
    pDefaultValue: "75",
    flags: 8194,
    pHelpString: "If a player is moving slower than this, don't push away physics objects (enables ducking behind things).");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_min_player_speed__);
}

//------------------------------------------------------------------------------
// Address: 0x10406940
// Name: _dynamic_initializer_for__sv_pushaway_max_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_max_force__()
{
  ConVar::ConVar(
    this: &sv_pushaway_max_force,
    pName: "sv_pushaway_max_force",
    pDefaultValue: "1000",
    flags: 8194,
    pHelpString: "Maximum amount of force applied to physics objects by players.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_max_force__);
}

//------------------------------------------------------------------------------
// Address: 0x10406970
// Name: _dynamic_initializer_for__sv_pushaway_clientside__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_clientside__()
{
  ConVar::ConVar(
    this: &sv_pushaway_clientside,
    pName: "sv_pushaway_clientside",
    pDefaultValue: "0",
    flags: 8194,
    pHelpString: "Clientside physics push away (0=off, 1=only localplayer, 1=all players)");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_clientside__);
}

//------------------------------------------------------------------------------
// Address: 0x104069A0
// Name: _dynamic_initializer_for__sv_pushaway_player_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_player_force__()
{
  ConVar::ConVar(
    this: &sv_pushaway_player_force,
    pName: "sv_pushaway_player_force",
    pDefaultValue: "200000",
    flags: 24578,
    pHelpString: "How hard the player is pushed away from physics objects (falls off with inverse square of distance).");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_player_force__);
}

//------------------------------------------------------------------------------
// Address: 0x104069D0
// Name: _dynamic_initializer_for__sv_pushaway_max_player_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_max_player_force__()
{
  ConVar::ConVar(
    this: &sv_pushaway_max_player_force,
    pName: "sv_pushaway_max_player_force",
    pDefaultValue: "10000",
    flags: 24578,
    pHelpString: "Maximum of how hard the player is pushed away from physics objects.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_max_player_force__);
}

//------------------------------------------------------------------------------
// Address: 0x10406A00
// Name: _dynamic_initializer_for__env_particlelight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_particlelight__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CParticleLight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_particlelight,
           a3: "env_particlelight");
}
