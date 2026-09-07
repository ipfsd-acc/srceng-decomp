// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_basenpc_schedule.cpp
// Functions: 54
// ============================================================

#include "game\server\ai_basenpc_schedule.h"

//------------------------------------------------------------------------------
// Address: 0x1002D4D0
// Name: private: virtual int CAI_BaseNPC::StartTask(struct Task_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::StartTask(CAI_BaseNPC *this, Task_t *pTask)
{
  DevMsg(a1: "Called wrong StartTask()\n");
  this->StartTask(this, a2: pTask);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002D500
// Name: private: virtual int CAI_BaseNPC::RunTask(struct Task_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::RunTask(CAI_BaseNPC *this, Task_t *pTask)
{
  DevMsg(a1: "Called wrong RunTask()\n");
  this->RunTask(this, a2: pTask);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10038EB0
// Name: protected: bool CAI_BaseNPC::FScheduleDone(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::FScheduleDone(CAI_BaseNPC *this)
{
  return this->m_ScheduleState.iCurTask == this->m_pSchedule->m_iNumTasks;
}

//------------------------------------------------------------------------------
// Address: 0x10038ED0
// Name: public: virtual bool CAI_BaseNPC::FindCoverPos(class CSound __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CAI_BaseNPC::FindCoverPos@<al>(
        CAI_BaseNPC *this@<ecx>,
        int a2@<ebx>,
        Vector *a3@<edi>,
        CSound *pSound,
        Vector *pResult)
{
  CAI_TacticalServices *m_pTacticalServices; // ebx
  const Vector *v7; // eax
  double v8; // xmm0_8
  CAI_TacticalServices *v9; // esi
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *SoundReactOrigin; // [esp+4h] [ebp-1Ch]
  float flMinDist; // [esp+8h] [ebp-18h]
  float flMaxDista; // [esp+Ch] [ebp-14h]
  double m_iVolume; // [esp+18h] [ebp-8h]

  if ( (double)pSound->m_iVolume >= 120.0 )
    m_iVolume = 120.0;
  else
    m_iVolume = (double)pSound->m_iVolume;
  m_pTacticalServices = this->m_pTacticalServices;
  flMaxDista = ((double (__thiscall *)(CAI_BaseNPC *, Vector *, int))this->CoverRadius)(a1: this, a2: pResult, a3: a2);
  flMinDist = m_iVolume;
  SoundReactOrigin = CSound::GetSoundReactOrigin(this: pSound);
  v7 = CSound::GetSoundReactOrigin(this: pSound);
  if ( CAI_TacticalServices::FindCoverPos(
         this: m_pTacticalServices,
         vThreatPos: v7,
         vThreatEyePos: SoundReactOrigin,
         flMinDist,
         flMaxDist: flMaxDista,
         pResult: a3) )
  {
    return true;
  }
  v8 = (double)pSound->m_iVolume;
  if ( v8 >= 60.0 )
    v8 = 60.0;
  v9 = this->m_pTacticalServices;
  v10 = v8;
  v11 = CSound::GetSoundReactOrigin(this: pSound);
  return CAI_TacticalServices::FindLateralCover(this: v9, vecThreat: v11, flMinDist: v10, pResult);
}

//------------------------------------------------------------------------------
// Address: 0x10038FA0
// Name: private: bool CAI_BaseNPC::FindCoverFromBestSound(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::FindCoverFromBestSound(CAI_BaseNPC *this, Vector *pCoverPos)
{
  CSound *v3; // eax

  v3 = this->GetBestSound(this, a2: 1048351);
  if ( v3 != nullptr )
    return this->FindCoverPos(this, a2: v3, a3: pCoverPos);
  _DevMsg(a1: 2, a2: "Attempting to find cover from best sound, but best sound not founc.\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10038FF0
// Name: protected: void CAI_BaseNPC::StartTaskOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::StartTaskOverlay(CAI_BaseNPC *this)
{
  bool v2; // al
  CAI_MoveAndShootOverlay *p_m_MoveAndShootOverlay; // ecx

  if ( this->IsCurTaskContinuousMove(this) )
  {
    v2 = this->ShouldMoveAndShoot(this);
    p_m_MoveAndShootOverlay = &this->m_MoveAndShootOverlay;
    if ( v2 )
      CAI_MoveAndShootOverlay::StartShootWhileMove(this: p_m_MoveAndShootOverlay);
    else
      CAI_MoveAndShootOverlay::NoShootWhileMove(this: p_m_MoveAndShootOverlay);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039030
// Name: private: void CAI_BaseNPC::RunAttackTask(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RunAttackTask(CAI_BaseNPC *this, int task)
{
  Vector vecEnemyLKP; // [esp+14h] [ebp-Ch] BYREF

  CAI_BaseNPC::AutoMovement(this, pTarget: nullptr, pTraceResult: nullptr);
  vecEnemyLKP = *this->GetEnemyLKP(this);
  if ( vec3_origin.x != vecEnemyLKP.x || vec3_origin.y != vecEnemyLKP.y || vec3_origin.z != vecEnemyLKP.z )
  {
    if ( (task == 75 || task == 79)
      && (this->CapabilitiesGet(this) & 0x20000000) != 0
      && this->FInAimCone(this, a2: &vecEnemyLKP) )
    {
      CAI_Motor::SetIdealYawAndUpdate(this: this->m_pMotor, idealYaw: this->m_pMotor->m_IdealYaw, yawSpeed: -2.0);
    }
    else
    {
      CAI_Motor::SetIdealYawToTargetAndUpdate(this: this->m_pMotor, target: &vecEnemyLKP, yawSpeed: -2.0);
    }
  }
  if ( this->IsActivityFinished(this) )
  {
    if ( task == 79 && this != (CAI_BaseNPC *)-2944 )
      CAI_ShotRegulator::Reset(this: &this->m_ShotRegulator, bStartShooting: false);
    CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039150
// Name: protected: virtual void CAI_BaseNPC::RunTaskOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RunTaskOverlay(CAI_BaseNPC *this)
{
  if ( this->IsCurTaskContinuousMove(this) )
    CAI_MoveAndShootOverlay::RunShootWhileMove(this: &this->m_MoveAndShootOverlay);
}

//------------------------------------------------------------------------------
// Address: 0x10039170
// Name: protected: void CAI_BaseNPC::EndTaskOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::EndTaskOverlay(CAI_BaseNPC *this)
{
  CAI_MoveAndShootOverlay::EndShootWhileMove(this: &this->m_MoveAndShootOverlay);
}

//------------------------------------------------------------------------------
// Address: 0x10039180
// Name: public: virtual void CAI_BaseNPC::SetTurnActivity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetTurnActivity(CAI_BaseNPC *this)
{
  double v2; // st7
  float v3; // xmm0_4
  float flYD; // [esp+4h] [ebp-4h]

  if ( this->IsCrouching(this) )
    goto LABEL_23;
  v2 = CAI_Motor::DeltaIdealYaw(this: this->m_pMotor);
  flYD = v2;
  v3 = flYD;
  if ( v2 <= -80.0 && flYD >= -100.0 )
  {
    if ( CBaseAnimating::SelectWeightedSequence(this, activity: ACT_90_RIGHT) != -1 )
    {
      this->m_afMemory |= 0x2000u;
      CAI_BaseNPC::SetIdealActivity(this, NewActivity: ACT_90_RIGHT);
      return;
    }
    v3 = v2;
  }
  if ( v3 >= 80.0 && v3 <= 100.0 )
  {
    if ( CBaseAnimating::SelectWeightedSequence(this, activity: ACT_90_LEFT) != -1 )
    {
      this->m_afMemory |= 0x2000u;
      CAI_BaseNPC::SetIdealActivity(this, NewActivity: ACT_90_LEFT);
      return;
    }
    v3 = v2;
  }
  if ( COERCE_FLOAT(LODWORD(v3) & _mask__AbsFloat_) >= 160.0 )
  {
    if ( CBaseAnimating::SelectWeightedSequence(this, activity: ACT_180_LEFT) != -1 )
    {
      this->m_afMemory |= 0x2000u;
      CAI_BaseNPC::SetIdealActivity(this, NewActivity: ACT_180_LEFT);
      return;
    }
    v3 = v2;
  }
  if ( v3 <= -45.0 )
  {
    if ( CBaseAnimating::SelectWeightedSequence(this, activity: ACT_TURN_RIGHT) != -1 )
    {
      CAI_BaseNPC::SetIdealActivity(this, NewActivity: ACT_TURN_RIGHT);
      return;
    }
    v3 = v2;
  }
  if ( v3 < 45.0 || CBaseAnimating::SelectWeightedSequence(this, activity: ACT_TURN_LEFT) == -1 )
LABEL_23:
    CAI_BaseNPC::SetIdealActivity(this, NewActivity: ACT_IDLE);
  else
    CAI_BaseNPC::SetIdealActivity(this, NewActivity: ACT_TURN_LEFT);
}

//------------------------------------------------------------------------------
// Address: 0x100392E0
// Name: public: bool CAI_BaseNPC::UpdateTurnGesture(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::UpdateTurnGesture(CAI_BaseNPC *this)
{
  float flYD; // [esp+8h] [ebp-4h]

  flYD = CAI_Motor::DeltaIdealYaw(this: this->m_pMotor);
  return ((bool (__stdcall *)(_DWORD))this->m_pMotor->AddTurnGesture)(a1: LODWORD(flYD));
}

//------------------------------------------------------------------------------
// Address: 0x10039320
// Name: public: void CAI_BaseNPC::ResetIdealActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ResetIdealActivity(CAI_BaseNPC *this, Activity newIdealActivity)
{
  if ( this->m_Activity == newIdealActivity )
    this->m_Activity = ACT_RESET;
  CAI_BaseNPC::SetIdealActivity(this, NewActivity: newIdealActivity);
}

//------------------------------------------------------------------------------
// Address: 0x10039350
// Name: public: struct Task_t const __near * CAI_BaseNPC::GetTask(void)
// Source: json
//------------------------------------------------------------------------------
const Task_t *__thiscall CAI_BaseNPC::GetTask(CAI_BaseNPC *this)
{
  int iCurTask; // eax
  CAI_Schedule *m_pSchedule; // ecx

  iCurTask = this->m_ScheduleState.iCurTask;
  m_pSchedule = this->m_pSchedule;
  if ( m_pSchedule != nullptr && iCurTask >= 0 && iCurTask < m_pSchedule->m_iNumTasks )
    return &m_pSchedule->m_pTaskList[iCurTask];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10039380
// Name: public: virtual void CAI_BaseNPC::TranslateAddOnAttachment(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::TranslateAddOnAttachment(CAI_BaseNPC *this, char *pchAttachmentName, int iCount)
{
  if ( _V_strcmp(s1: pchAttachmentName, s2: "addon_baseshooter") == 0 )
  {
    if ( iCount == 0 )
    {
      _V_strcpy(dest: pchAttachmentName, src: "anim_attachment_lh");
      return;
    }
    if ( iCount == 1 )
    {
      _V_strcpy(dest: pchAttachmentName, src: "anim_attachment_rh");
      return;
    }
  }
  _V_strcpy(dest: pchAttachmentName, src: locale);
}

//------------------------------------------------------------------------------
// Address: 0x100393E0
// Name: public: virtual int CAI_BaseNPC::SelectFailSchedule(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::SelectFailSchedule(CAI_BaseNPC *this, int failedSchedule, int failedTask, int taskFailCode)
{
  int result; // eax

  result = this->m_failSchedule;
  if ( result == 0 )
    return 82;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039400
// Name: public: void CAI_MoveMonitor::SetMark(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_MoveMonitor::SetMark(CAI_MoveMonitor *this, CBaseEntity *pEntity, float tolerance)
{
  double z; // st7
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( pEntity != nullptr )
  {
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    this->m_vMark.x = pEntity->m_vecAbsOrigin.x;
    this->m_vMark.y = pEntity->m_vecAbsOrigin.y;
    z = pEntity->m_vecAbsOrigin.z;
    this->m_flMarkTolerance = tolerance;
    this->m_vMark.z = z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039450
// Name: public: void CAI_Navigator::SetAllowBigStep(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Navigator::SetAllowBigStep(CAI_Navigator *this, CWorld *pEntToStepOff)
{
  if ( pEntToStepOff != nullptr )
  {
    if ( pEntToStepOff != g_WorldEntity )
      this->m_hBigStepGroundEnt.m_Index = *(_DWORD *)((int (*)(void))pEntToStepOff->GetRefEHandle)();
  }
  else
  {
    this->m_hBigStepGroundEnt.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039490
// Name: public: class CBaseEntity __near * CAI_Hint::User(void)const
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_Hint::User(CAI_Hint *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hHintOwner.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100394C0
// Name: public: void CAI_BaseNPC::DumpTaskTimings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::DumpTaskTimings(CAI_BaseNPC *this)
{
  int v1; // edi
  CFastTimer *p_startTimer; // esi

  DevMsg(a1: " Tasks timings:\n");
  v1 = 0;
  if ( g_nAITasksRun > 0 )
  {
    p_startTimer = &g_AITaskTimings[0].startTimer;
    do
    {
      DevMsg(
        a1: "   %32s -- select %5.2f, start %5.2f, run %5.2f\n",
        (const char *)LODWORD(p_startTimer[-2].m_Duration.m_Int64),
        (double)(_g_ClockSpeedMillisecondsMultiplier * (double)p_startTimer[-1].m_Duration.m_Int64),
        (double)((double)p_startTimer->m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier),
        (double)((double)p_startTimer[1].m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier));
      ++v1;
      p_startTimer += 4;
    }
    while ( v1 < g_nAITasksRun );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100395B0
// Name: protected: virtual class CAI_Schedule __near * CAI_BaseNPC::GetFailSchedule(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_BaseNPC::GetFailSchedule(CAI_BaseNPC *this)
{
  CAI_Schedule *m_pSchedule; // eax
  int v3; // eax
  CAI_Schedule *v4; // ecx
  int iCurTask; // edx
  int *p_iTask; // ecx
  int v7; // ecx
  int v8; // eax

  m_pSchedule = this->m_pSchedule;
  if ( m_pSchedule != nullptr )
    v3 = this->GetLocalScheduleId(this, a2: m_pSchedule->m_iScheduleID);
  else
    v3 = 0;
  v4 = this->m_pSchedule;
  iCurTask = this->m_ScheduleState.iCurTask;
  if ( v4 != nullptr
    && iCurTask >= 0
    && iCurTask < v4->m_iNumTasks
    && (p_iTask = &v4->m_pTaskList[iCurTask].iTask) != nullptr )
  {
    v7 = *p_iTask;
  }
  else
  {
    v7 = 0;
  }
  v8 = this->SelectFailSchedule(this, a2: v3, a3: v7, a4: this->m_ScheduleState.taskFailureCode);
  return CAI_BaseNPC::GetScheduleOfType(this, scheduleType: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10039620
// Name: public: virtual bool CAI_BaseNPC::FindCoverPos(class CBaseEntity __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CAI_BaseNPC::FindCoverPos@<al>(
        CAI_BaseNPC *this@<ecx>,
        Vector *a2@<ebx>,
        int a3@<edi>,
        float a4@<esi>,
        CBaseEntity *pEntity,
        Vector *pResult)
{
  CAI_TacticalServices *m_pTacticalServices; // ebx
  const Vector *v8; // eax
  CAI_TacticalServices *v9; // ebx
  const Vector *v10; // eax
  bool result; // al
  Vector *v14; // [esp+18h] [ebp-10h]
  float flMinDist[3]; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  m_pTacticalServices = this->m_pTacticalServices;
  v8 = (const Vector *)((int (__thiscall *)(CBaseEntity *, float *, _DWORD, Vector *, int))pEntity->EyePosition)(
                         a1: pEntity,
                         a2: flMinDist,
                         a3: 0,
                         a4: pResult,
                         a5: a3);
  if ( CAI_TacticalServices::FindLateralCover(this: m_pTacticalServices, vecThreat: v8, flMinDist: a4, pResult: a2) )
    return true;
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  v9 = this->m_pTacticalServices;
  *(float *)&v14 = ((double (__thiscall *)(CAI_BaseNPC *, Vector *))this->CoverRadius)(a1: this, a2: pResult);
  v10 = (const Vector *)((int (__thiscall *)(CBaseEntity *))pEntity->EyePosition)(a1: pEntity);
  result = CAI_TacticalServices::FindCoverPos(
             this: v9,
             vThreatPos: &pEntity->m_vecAbsOrigin,
             vThreatEyePos: v10,
             flMinDist: COERCE_FLOAT(flMinDist),
             flMaxDist: 0.0,
             pResult: v14);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100396D0
// Name: public: virtual bool CAI_BaseNPC::FindCoverPosInRadius(class CBaseEntity __near *,class Vector const __near &,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::FindCoverPosInRadius(
        CAI_BaseNPC *this,
        CAI_BaseNPC *pEntity,
        const Vector *goalPos,
        float coverRadius,
        Vector *pResult)
{
  CAI_BaseNPC *v5; // edi
  CAI_TacticalServices *m_pTacticalServices; // ecx
  unsigned int v8; // edx
  const Vector *p_m_vecAbsOrigin; // ebx
  CAI_Squad *m_pSquad; // ecx
  const Vector *v11; // eax
  float v12; // xmm0_4
  bool (__thiscall *IsCoverPosition)(CAI_BaseNPC *, const Vector *, const Vector *); // eax
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  CAI_TacticalServices *v17; // esi
  float flMinDist; // xmm0_4
  float v20[3]; // [esp+20h] [ebp-28h] BYREF
  Vector enemyEyePos; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector coverPos; // [esp+38h] [ebp-10h] BYREF
  CAI_TacticalServices *pTacticalServices; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF
  float pEntitya; // [esp+50h] [ebp+8h]

  v5 = pEntity;
  m_pTacticalServices = this->m_pTacticalServices;
  if ( pEntity == nullptr )
    v5 = this;
  v8 = (unsigned int)v5->m_iEFlags >> 11;
  coverPos = vec3_invalid;
  pTacticalServices = m_pTacticalServices;
  if ( (v8 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
  p_m_vecAbsOrigin = &v5->m_vecAbsOrigin;
  v5->EyePosition(this: v5, result: &enemyEyePos);
  m_pSquad = this->m_pSquad;
  if ( (m_pSquad == nullptr
     || CAI_Squad::GetFirstMember(this: m_pSquad, pIter: nullptr, bIgnoreSilentMembers: true) == this)
    && (v11 = this->GetViewOffset(this),
        v20[0] = v11->x + goalPos->x,
        v20[1] = v11->y + goalPos->y,
        v12 = v11->z + goalPos->z,
        IsCoverPosition = this->IsCoverPosition,
        v20[2] = v12,
        IsCoverPosition(this, a2: &enemyEyePos, a3: (const Vector *)v20))
    && this->IsValidCover(this, a2: goalPos, a3: nullptr) )
  {
    x = goalPos->x;
    y = goalPos->y;
    z = goalPos->z;
  }
  else
  {
    v17 = pTacticalServices;
    pEntitya = coverRadius * 0.5;
    if ( !CAI_TacticalServices::FindCoverPos(
            this: pTacticalServices,
            vNearPos: goalPos,
            vThreatPos: p_m_vecAbsOrigin,
            vThreatEyePos: &enemyEyePos,
            flMinDist: 0.0,
            flMaxDist: coverRadius * 0.5,
            pResult: &coverPos)
      && !CAI_TacticalServices::FindLateralCover(
            this: v17,
            vNearPos: goalPos,
            vecThreat: &enemyEyePos,
            flMinDist: 0.0,
            distToCheck: pEntitya,
            numChecksPerDir: 3,
            pResult: &coverPos) )
    {
      flMinDist = pEntitya - 0.1;
      if ( !CAI_TacticalServices::FindCoverPos(
              this: v17,
              vNearPos: goalPos,
              vThreatPos: p_m_vecAbsOrigin,
              vThreatEyePos: &enemyEyePos,
              flMinDist,
              flMaxDist: coverRadius,
              pResult: &coverPos) )
        CAI_TacticalServices::FindLateralCover(
          this: v17,
          vNearPos: goalPos,
          vecThreat: &enemyEyePos,
          flMinDist: 0.0,
          distToCheck: coverRadius,
          numChecksPerDir: 5,
          pResult: &coverPos);
    }
    x = coverPos.x;
    y = coverPos.y;
    z = coverPos.z;
  }
  if ( vec3_invalid.x == x && vec3_invalid.y == y && vec3_invalid.z == z )
    return 0;
  pResult->x = x;
  pResult->y = y;
  pResult->z = z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100398F0
// Name: protected: virtual float CAI_BaseNPC::GetReasonableFacingDist(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CAI_BaseNPC::GetReasonableFacingDist@<st0>(CAI_BaseNPC *this@<ecx>, int a2@<ebp>)
{
  CAI_Schedule *m_pSchedule; // ecx
  int iCurTask; // eax
  int m_iNumTasks; // edi
  Task_t *m_pTaskList; // ecx
  Task_t *v7; // eax
  CBaseEntity *v8; // eax
  CBaseEntity *v9; // edi
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  _DWORD v15[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v15[0] = a2;
  v15[1] = retaddr;
  m_pSchedule = this->m_pSchedule;
  iCurTask = this->m_ScheduleState.iCurTask;
  if ( m_pSchedule == nullptr )
    return 60.0;
  if ( iCurTask < 0 )
    return 60.0;
  m_iNumTasks = m_pSchedule->m_iNumTasks;
  if ( iCurTask >= m_iNumTasks )
    return 60.0;
  m_pTaskList = m_pSchedule->m_pTaskList;
  if ( &m_pTaskList[iCurTask] == nullptr )
    return 60.0;
  v7 = iCurTask >= m_iNumTasks ? nullptr : &m_pTaskList[iCurTask];
  if ( v7->iTask != 67 )
    return 60.0;
  if ( this->GetEnemy_2(this) == nullptr )
    return 42.0;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)v15);
  v8 = this->GetEnemy_2(this);
  v9 = v8;
  if ( (v8->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v8, a2: (int)v15);
  v10 = v9->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
  v11 = v9->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
  v12 = fsqrt((float)(v11 * v11) + (float)(v10 * v10)) - 1.0;
  if ( v12 >= 42.0 )
    return 42.0;
  else
    return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10039A40
// Name: public: virtual void CAI_BaseNPC::TranslateNavGoal(class CBaseEntity __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::TranslateNavGoal(CAI_BaseNPC *this, CBaseEntity *pEnemy, Vector *chasePosition)
{
  Vector *v3; // eax
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  _BYTE v7[12]; // [esp+0h] [ebp-Ch] BYREF
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( CAI_BaseNPC::GetNavType(this) == NAV_FLY )
  {
    if ( (pEnemy->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEnemy, a2: (int)&savedregs);
    v3 = pEnemy->EyePosition(this: pEnemy, result: v7);
    v4 = v3->z - pEnemy->m_vecAbsOrigin.z;
    v5 = chasePosition->x + (float)(v3->x - pEnemy->m_vecAbsOrigin.x);
    chasePosition->y = chasePosition->y + (float)(v3->y - pEnemy->m_vecAbsOrigin.y);
    v6 = chasePosition->z + v4;
    chasePosition->x = v5;
    chasePosition->z = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039AD0
// Name: protected: virtual int CAI_BaseNPC::SelectDeadSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::SelectDeadSchedule(CAI_BaseNPC *this)
{
  if ( this->BecomeRagdollOnClient(this, a2: &vec3_origin) )
  {
    this->CleanupOnDeath(this, a2: nullptr, a3: true);
    return 55;
  }
  else if ( this->m_lifeState.m_Value == 2 )
  {
    return 0;
  }
  else
  {
    this->CleanupOnDeath(this, a2: nullptr, a3: true);
    return 54;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039B30
// Name: protected: int CAI_BaseNPC::SelectFlinchSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::SelectFlinchSchedule(CAI_BaseNPC *this)
{
  Activity v3; // eax

  if ( !CAI_BaseNPC::HasCondition(this, iCondition: 18) || (this->m_afMemory & 0x40) != 0 || !this->CanFlinch(this) )
    return 0;
  v3 = this->GetFlinchActivity(this, a2: true, a3: false);
  return CAI_BaseNPC::HaveSequenceForActivity(this, activity: v3) ? 0x17 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x10039B80
// Name: public: float CBaseAnimating::GetPlaybackRate(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetPlaybackRate(CBaseAnimating *this)
{
  float v1; // xmm0_4

  v1 = 1.0 - this->m_flFrozen.m_Value;
  if ( v1 < 0.0 )
    return this->m_flPlaybackRate.m_Value * 0.0;
  if ( v1 <= 1.0 )
    return this->m_flPlaybackRate.m_Value * v1;
  return this->m_flPlaybackRate.m_Value * 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10039BE0
// Name: public: void CAI_BaseNPC::ClearSchedule(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearSchedule(CAI_BaseNPC *this, const char *szReason)
{
  if ( szReason != nullptr && (this->m_debugOverlays & 0x8000000) != 0 )
    DevMsg(pAI: this, flags: 1, pszFormat: "  Schedule cleared: %s\n", szReason);
  this->m_ScheduleState.fTaskStatus = TASKSTATUS_NEW;
  this->m_IdealSchedule = 0;
  this->m_pSchedule = nullptr;
  this->m_ScheduleState.iCurTask = 0;
  this->m_ScheduleState.iTaskInterrupt = 0;
  *(_WORD *)&this->m_ScheduleState.bTaskRanAutomovement = 0;
  this->m_ScheduleState.timeStarted = 0.0;
  this->m_ScheduleState.timeCurTaskStarted = 0.0;
  this->m_ScheduleState.bScheduleWasInterrupted = true;
  if ( this != (CAI_BaseNPC *)-2484 )
  {
    this->m_InverseIgnoreConditions.m_Ints[0] = -1;
    this->m_InverseIgnoreConditions.m_Ints[1] = -1;
    this->m_InverseIgnoreConditions.m_Ints[2] = -1;
    this->m_InverseIgnoreConditions.m_Ints[3] = -1;
    this->m_InverseIgnoreConditions.m_Ints[4] = -1;
    this->m_InverseIgnoreConditions.m_Ints[5] = -1;
    this->m_InverseIgnoreConditions.m_Ints[6] = -1;
    this->m_InverseIgnoreConditions.m_Ints[7] = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039C80
// Name: public: void CAI_BaseNPC::SetSchedule(class CAI_Schedule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetSchedule(CAI_BaseNPC *this, CAI_Schedule *pNewSchedule)
{
  float curtime; // xmm0_4
  bool HasCondition; // al
  CAI_Navigator *m_pNavigator; // ecx
  CGlobalEvent *Event; // eax

  this->OnSetSchedule(this);
  curtime = gpGlobals->curtime;
  this->m_ScheduleState.timeStarted = curtime;
  this->m_ScheduleState.timeCurTaskStarted = curtime;
  this->m_ScheduleState.bScheduleWasInterrupted = false;
  this->m_pSchedule = pNewSchedule;
  this->m_ScheduleState.iCurTask = 0;
  this->m_ScheduleState.iTaskInterrupt = 0;
  *(_WORD *)&this->m_ScheduleState.bTaskRanAutomovement = 0;
  this->m_ScheduleState.fTaskStatus = TASKSTATUS_NEW;
  this->m_failSchedule = 0;
  HasCondition = CAI_BaseNPC::HasCondition(this, iCondition: 1);
  if ( this != (CAI_BaseNPC *)-2388 )
  {
    *(_QWORD *)this->m_Conditions.m_Ints = 0;
    *(_QWORD *)&this->m_Conditions.m_Ints[2] = 0;
    *(_QWORD *)&this->m_Conditions.m_Ints[4] = 0;
    *(_QWORD *)&this->m_Conditions.m_Ints[6] = 0;
  }
  if ( HasCondition )
    CAI_BaseNPC::SetCondition(this, iCondition: 1);
  m_pNavigator = this->m_pNavigator;
  this->m_bConditionsGathered = false;
  CAI_Navigator::ClearGoal(this: m_pNavigator);
  if ( this != (CAI_BaseNPC *)-2484 )
  {
    this->m_InverseIgnoreConditions.m_Ints[0] = -1;
    this->m_InverseIgnoreConditions.m_Ints[1] = -1;
    this->m_InverseIgnoreConditions.m_Ints[2] = -1;
    this->m_InverseIgnoreConditions.m_Ints[3] = -1;
    this->m_InverseIgnoreConditions.m_Ints[4] = -1;
    this->m_InverseIgnoreConditions.m_Ints[5] = -1;
    this->m_InverseIgnoreConditions.m_Ints[6] = -1;
    this->m_InverseIgnoreConditions.m_Ints[7] = -1;
  }
  this->m_afMemory &= ~0x2000u;
  if ( (this->m_debugOverlays & 0x8000000) != 0 )
    DevMsg(pAI: this, flags: 1, pszFormat: "Schedule: %s (time: %.2f)\n", pNewSchedule->m_pName, gpGlobals->curtime);
  if ( this->m_pEvent != nullptr )
  {
    if ( this->m_pScheduleEvent != nullptr )
      CGlobalEventLog::RemoveEvent(this: &GlobalEventLog, pEvent: this->m_pScheduleEvent);
    Event = CGlobalEventLog::CreateEvent(
              this: &GlobalEventLog,
              pszName: "Schedule",
              bIsHighLevel: false,
              pParent: this->m_pEvent);
    this->m_pScheduleEvent = Event;
    CGlobalEventLog::AddKeyValue(
      this: &GlobalEventLog,
      pEvent: Event,
      bVarying: false,
      pszKey: "Schedule",
      pszValueFormat: pNewSchedule->m_pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039DF0
// Name: protected: bool CAI_BaseNPC::ShouldSelectIdealState(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::ShouldSelectIdealState(CAI_BaseNPC *this)
{
  NPC_STATE m_IdealNPCState; // eax
  bool result; // al
  CAI_Schedule *m_pSchedule; // eax
  NPC_STATE m_NPCState; // eax

  m_IdealNPCState = this->m_IdealNPCState;
  result = false;
  if ( m_IdealNPCState != NPC_STATE_DEAD
    && (m_IdealNPCState != NPC_STATE_SCRIPT || this->m_NPCState == NPC_STATE_SCRIPT) )
  {
    if ( !CAI_BaseNPC::HasCondition(this, iCondition: 36) )
      return true;
    m_pSchedule = this->m_pSchedule;
    if ( m_pSchedule != nullptr && (m_pSchedule->m_InterruptMask.m_Ints[1] & 0x10) != 0 )
      return true;
    if ( this->m_NPCState == NPC_STATE_COMBAT && this->GetEnemy_2(this) == nullptr )
      return true;
    m_NPCState = this->m_NPCState;
    if ( (m_NPCState == NPC_STATE_IDLE || m_NPCState == NPC_STATE_ALERT) && this->GetEnemy_2(this) != nullptr )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039E70
// Name: ShouldStopProcessingTasks
// Source: json
//------------------------------------------------------------------------------
bool __usercall ShouldStopProcessingTasks@<al>(CAI_BaseNPC *pNPC@<esi>, int taskTime, int timeLimit)
{
  bool IsCurSchedule; // al
  Activity m_IdealActivity; // eax

  if ( pNPC->m_bDeferredNavigation )
    return true;
  if ( AIStrongOpt() )
  {
    if ( pNPC->m_NPCState == NPC_STATE_SCRIPT
      || (IsCurSchedule = CAI_BaseNPC::IsCurSchedule(this: pNPC, schedId: 63, fIdeal: false)) )
    {
      IsCurSchedule = true;
    }
    if ( (pNPC->m_afMemory & 8) != 0 && !IsCurSchedule )
      return true;
  }
  return taskTime > timeLimit
      && (ai_use_think_optimizations.m_pParent != nullptr
       && ai_use_think_optimizations.m_pParent->m_Value.m_nValue != 0
       && ai_use_efficiency.m_pParent != nullptr
       && ai_use_efficiency.m_pParent->m_Value.m_nValue != 0
       || pNPC->IsMoving(this: pNPC)
       || (m_IdealActivity = pNPC->m_IdealActivity) != ACT_RUN && m_IdealActivity != ACT_WALK);
}

//------------------------------------------------------------------------------
// Address: 0x10039F00
// Name: private: void CAI_BaseNPC::StartTurn(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::StartTurn(CAI_BaseNPC *this, float flDeltaYaw)
{
  this->m_pMotor->m_IdealYaw = (float)(unsigned __int16)(int)(float)((float)((float)((float)(unsigned __int16)(int)(float)(this->m_angRotation.m_Value.y * 182.04445)
                                                                                   * 0.0054931641)
                                                                           + flDeltaYaw)
                                                                   * 182.04445)
                             * 0.0054931641;
  this->SetTurnActivity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10039F70
// Name: public: void CAI_BaseNPC::ClearHintNode(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::ClearHintNode(CAI_BaseNPC *this, float reuseDelay)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CAI_Hint **v9; // eax
  CAI_Hint *v10; // eax
  unsigned int v11; // eax
  CAI_Hint *m_pEntity; // ecx

  m_Index = this->m_pHintNode.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = (CAI_Hint **)&g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        v10 = *v9;
      else
        v10 = nullptr;
      if ( CAI_Hint::IsLockedBy(this: v10, pNPC: this) )
      {
        v11 = this->m_pHintNode.m_Index;
        if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CAI_Hint *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
        CAI_Hint::Unlock(this: m_pEntity, flSeconds: reuseDelay);
      }
      this->m_pHintNode.m_Index = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A020
// Name: public: void CAI_BaseNPC::SetHintNode(class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::SetHintNode(CAI_BaseNPC *this, CAI_Hint *pHintNode)
{
  if ( pHintNode != nullptr )
    this->m_pHintNode.m_Index = pHintNode->GetRefEHandle(this: pHintNode)->m_Index;
  else
    this->m_pHintNode.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A050
// Name: public: bool CAI_BaseNPC::FindCoverFromEnemy(bool,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::FindCoverFromEnemy(
        CAI_BaseNPC *this,
        bool bNodesOnly,
        float flMinDistance,
        float flMaxDistance)
{
  CAI_BaseNPC *v5; // edi
  CAI_TacticalServices *m_pTacticalServices; // ebx
  const Vector *v7; // eax
  bool result; // al
  CAI_Navigator *m_pNavigator; // ecx
  unsigned int m_Index; // eax
  CAI_Navigator *v11; // edi
  CAI_BaseNPC_vtbl *v12; // ebx
  CAI_Hint *VehicleEntity; // eax
  Activity v14; // eax
  CAI_Navigator *v15; // edi
  CAI_Hint *v16; // eax
  const Vector *Direction; // eax
  AI_NavGoal_t goal; // [esp+18h] [ebp-48h] BYREF
  Vector v19; // [esp+48h] [ebp-18h] BYREF
  Vector coverPos; // [esp+54h] [ebp-Ch] BYREF
  int savedregs; // [esp+60h] [ebp+0h] BYREF

  v5 = (CAI_BaseNPC *)this->GetEnemy_2(this);
  *(_QWORD *)&coverPos.x = *(_QWORD *)&vec3_invalid.x;
  if ( v5 == nullptr )
    v5 = this;
  coverPos.z = vec3_invalid.z;
  CAI_BaseNPC::ClearHintNode(this, reuseDelay: 0.0);
  if ( bNodesOnly )
  {
    if ( flMaxDistance == 3.4028235e38 )
      flMaxDistance = this->CoverRadius(this);
    if ( (v5->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
    m_pTacticalServices = this->m_pTacticalServices;
    v7 = v5->EyePosition(this: v5, result: &v19);
    if ( !CAI_TacticalServices::FindCoverPos(
            this: m_pTacticalServices,
            vThreatPos: &v5->m_vecAbsOrigin,
            vThreatEyePos: v7,
            flMinDist: flMinDistance,
            flMaxDist: flMaxDistance,
            pResult: &coverPos) )
      return false;
  }
  else
  {
    result = this->FindCoverPos(this, a2: v5, a3: &coverPos);
    if ( !result )
      return result;
  }
  *(_QWORD *)&goal.dest.x = *(_QWORD *)&coverPos.x;
  goal.tolerance = -2.0;
  goal.pTarget = AIN_DEF_TARGET_8;
  m_pNavigator = this->m_pNavigator;
  goal.dest.z = coverPos.z;
  goal.type = GOALTYPE_COVER;
  goal.destNode = (AI_PathNode_t__ *)-1;
  goal.activity = ACT_RUN;
  goal.arrivalActivity = ACT_INVALID;
  goal.arrivalSequence = -1;
  goal.maxInitialSimplificationDist = -1.0;
  goal.flags = 0;
  if ( !m_pNavigator->SetGoal(this: m_pNavigator, a2: &goal, a3: 0) )
    return false;
  m_Index = this->m_pHintNode.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v11 = this->m_pNavigator;
    v12 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    VehicleEntity = CBasePlayer::GetVehicleEntity(this);
    v14 = v12->GetCoverActivity(this, a2: VehicleEntity);
    CAI_Navigator::SetArrivalActivity(this: v11, activity: v14);
    v15 = this->m_pNavigator;
    v16 = CBasePlayer::GetVehicleEntity(this);
    Direction = CAI_Hint::GetDirection(this: v16, result: &v19);
    CAI_Navigator::SetArrivalDirection(this: v15, goalDirection: Direction);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1003A230
// Name: protected: virtual float CAI_BaseNPC::CalcReasonableFacing(bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BaseNPC::CalcReasonableFacing(CAI_BaseNPC *this, bool bIgnoreOriginalFacing)
{
  CAI_Motor *m_pMotor; // eax
  CAI_BaseNPC_vtbl *v5; // edx
  float m_IdealYaw; // xmm0_4
  float (__thiscall *GetReasonableFacingDist)(CAI_BaseNPC *); // eax
  double v8; // st7
  int v9; // ebx
  float v10; // xmm0_4
  int v11; // esi
  double v12; // st7
  float v13; // xmm0_4
  Vector forward; // [esp+18h] [ebp-30h] BYREF
  QAngle angles; // [esp+24h] [ebp-24h] BYREF
  float MIN_DIST; // [esp+30h] [ebp-18h]
  float zEye; // [esp+34h] [ebp-14h]
  float offset; // [esp+38h] [ebp-10h]
  float curTrace; // [esp+3Ch] [ebp-Ch]
  float idealYaw; // [esp+40h] [ebp-8h]
  float flReasonableYaw; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF
  float longestTrace; // [esp+50h] [ebp+8h]

  if ( !bIgnoreOriginalFacing && (this->m_afMemory & 0x40000) == 0 && !CAI_BaseNPC::HasCondition(this, iCondition: 10) )
    return this->m_flOriginalYaw;
  m_pMotor = this->m_pMotor;
  v5 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  memset((void *)&angles, 0, sizeof(angles));
  m_IdealYaw = m_pMotor->m_IdealYaw;
  GetReasonableFacingDist = v5->GetReasonableFacingDist;
  idealYaw = m_IdealYaw;
  flReasonableYaw = m_IdealYaw;
  v8 = ((double (__thiscall *)(CAI_BaseNPC *))GetReasonableFacingDist)(a1: this);
  MIN_DIST = v8;
  longestTrace = 0.0;
  if ( v8 == 0.0 )
    return idealYaw;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  zEye = this->m_vDefaultEyeOffset.z + this->m_vecAbsOrigin.z;
  v9 = 0;
LABEL_10:
  v10 = (float)v9 * 45.0;
  offset = v10;
  v11 = -1;
  while ( 1 )
  {
    angles.y = (float)((float)v11 * v10) + idealYaw;
    AngleVectors(&angles, &forward, right: nullptr, up: nullptr);
    v12 = ((double (__thiscall *)(CAI_BaseNPC *, Vector *, _DWORD))this->LineOfSightDist)(
            a1: this,
            a2: &forward,
            a3: LODWORD(zEye));
    curTrace = v12;
    if ( v12 > longestTrace
      && ((unsigned __int8 (__thiscall *)(CAI_BaseNPC *, Vector *, _DWORD))this->IsValidReasonableFacing)(
           a1: this,
           a2: &forward,
           a3: LODWORD(curTrace)) != 0 )
    {
      flReasonableYaw = angles.y;
      v13 = curTrace;
      longestTrace = curTrace;
    }
    else
    {
      v13 = longestTrace;
    }
    if ( v13 > MIN_DIST )
      return flReasonableYaw;
    if ( v9 == 0 || v9 == 4 || (v11 += 2, v11 > 1) )
    {
      if ( v13 <= MIN_DIST && ++v9 <= 4 )
        goto LABEL_10;
      return flReasonableYaw;
    }
    v10 = offset;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A3E0
// Name: public: enum Activity CAI_BaseNPC::GetScriptCustomMoveActivity(void)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_BaseNPC::GetScriptCustomMoveActivity(CAI_BaseNPC *this)
{
  unsigned int m_Index; // edx
  Activity result; // eax
  int v4; // ecx
  CEntInfo *v5; // esi
  unsigned int v6; // edx
  IHandleEntity *v7; // esi
  IHandleEntity *m_pEntity; // eax
  const char *v9; // eax
  unsigned int v10; // eax
  IHandleEntity *v11; // ecx
  const char *v12; // eax

  m_Index = this->m_hCine.m_Index;
  result = ACT_WALK;
  if ( m_Index != -1
    && (v4 = (unsigned __int16)m_Index,
        v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v6 = HIWORD(m_Index),
        v5->m_SerialNumber == v6)
    && v5->m_pEntity != nullptr
    && (g_pEntityList->m_EntPtrArray[v4].m_SerialNumber != v6
      ? (v7 = nullptr)
      : (v7 = g_pEntityList->m_EntPtrArray[v4].m_pEntity),
        v7[217].__vftable != nullptr) )
  {
    if ( g_pEntityList->m_EntPtrArray[v4].m_SerialNumber == v6 )
      m_pEntity = g_pEntityList->m_EntPtrArray[v4].m_pEntity;
    else
      m_pEntity = nullptr;
    v9 = (const char *)m_pEntity[217].__vftable;
    if ( v9 == nullptr )
      v9 = locale;
    result = CBaseAnimating::LookupActivity(this, label: v9);
    if ( result == ACT_INVALID )
    {
      v10 = this->m_hCine.m_Index;
      if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
        v11 = nullptr;
      else
        v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
      v12 = (const char *)v11[217].__vftable;
      if ( v12 == nullptr )
        v12 = locale;
      return CBaseAnimating::LookupSequence(this, label: v12) != -1 ? 15 : 6;
    }
  }
  else if ( this->m_iszSceneCustomMoveSeq.pszValue != nullptr )
  {
    return ACT_SCRIPT_CUSTOM_MOVE;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A4E0
// Name: public: int CAI_BaseNPC::GetScriptCustomMoveSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::GetScriptCustomMoveSequence(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax
  const char *v10; // eax
  int result; // eax
  unsigned int v12; // eax
  IHandleEntity *v13; // ecx
  const char *v14; // ecx
  const char *pszValue; // eax
  const char *v16; // eax
  const char *v17; // ecx

  m_Index = this->m_hCine.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber == v5)
    && v4->m_pEntity != nullptr )
  {
    v6 = v3;
    v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
    v8 = &g_pEntityList->m_EntPtrArray[v6];
    if ( v7 )
      m_pEntity = v8->m_pEntity;
    else
      m_pEntity = nullptr;
    v10 = (const char *)m_pEntity[217].__vftable;
    if ( v10 == nullptr )
      v10 = locale;
    result = CBaseAnimating::LookupSequence(this, label: v10);
    if ( result == -1 )
    {
      v12 = this->m_hCine.m_Index;
      if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
        v13 = nullptr;
      else
        v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
      v14 = (const char *)v13[217].__vftable;
      if ( v14 == nullptr )
        v14 = locale;
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      DevMsg(a1: "SCRIPT_CUSTOM_MOVE: %s has no sequence:%s\n", pszValue, v14);
      return CBaseAnimating::SelectWeightedSequence(this, activity: ACT_WALK);
    }
  }
  else
  {
    if ( this->m_iszSceneCustomMoveSeq.pszValue != nullptr )
    {
      result = CBaseAnimating::LookupSequence(this, label: this->m_iszSceneCustomMoveSeq.pszValue);
      if ( result != -1 )
        return result;
      v16 = this->m_iszSceneCustomMoveSeq.pszValue;
      if ( v16 == nullptr )
        v16 = locale;
      v17 = this->m_iClassname.pszValue;
      if ( v17 == nullptr )
        v17 = locale;
      _Warning(a1: "SCRIPT_CUSTOM_MOVE: %s failed scripted custom move. Has no sequence called: %s\n", v17, v16);
    }
    return CBaseAnimating::SelectWeightedSequence(this, activity: ACT_WALK);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A610
// Name: public: virtual bool CAI_BaseNPC::IsInterruptable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BaseNPC::IsInterruptable(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  CAI_ScriptedSequence *v9; // eax

  if ( this->m_NPCState != NPC_STATE_SCRIPT )
    return this->IsAlive(this);
  m_Index = this->m_hCine.m_Index;
  if ( m_Index == -1 )
    return this->IsAlive(this);
  v3 = (unsigned __int16)m_Index;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v5 = HIWORD(m_Index);
  if ( v4->m_SerialNumber != v5 || v4->m_pEntity == nullptr )
    return this->IsAlive(this);
  v6 = v3;
  v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
  v8 = &g_pEntityList->m_EntPtrArray[v6];
  v9 = v7 ? (CAI_ScriptedSequence *)v8->m_pEntity : nullptr;
  return CAI_ScriptedSequence::CanInterrupt(this: v9)
      && ((this->m_fFlags.m_Value & 0x800) == 0
       || ((int)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine)[1].m_Network.m_TimerEvent.m_pEventMgr
         & 0x800) != 0)
      && this->IsAlive(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003A6A0
// Name: protected: int CAI_BaseNPC::SelectIdleSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::SelectIdleSchedule(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax
  int result; // eax

  m_Index = this->m_hForcedInteractionPartner.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber == v5)
    && v4->m_pEntity != nullptr )
  {
    v6 = v3;
    v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
    v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
    if ( v7 )
      v9 = *v8;
    else
      v9 = nullptr;
    CAI_BaseNPC::SetTarget(this, pTarget: v9);
    return (this->m_iInteractionPlaying == -1) + 86;
  }
  else
  {
    result = CAI_BaseNPC::SelectFlinchSchedule(this);
    if ( result == 0 )
    {
      if ( CAI_BaseNPC::HasCondition(this, iCondition: 50)
        || CAI_BaseNPC::HasCondition(this, iCondition: 53)
        || CAI_BaseNPC::HasCondition(this, iCondition: 54)
        || CAI_BaseNPC::HasCondition(this, iCondition: 56)
        || CAI_BaseNPC::HasCondition(this, iCondition: 55) )
      {
        return 6;
      }
      else
      {
        return (CAI_Navigator::GetGoalType(this: this->m_pNavigator) != GOALTYPE_NONE) + 1;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A770
// Name: protected: int CAI_BaseNPC::SelectAlertSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::SelectAlertSchedule(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax
  int result; // eax
  CGlobalVars *v11; // edi
  CAI_Enemies *v12; // eax

  m_Index = this->m_hForcedInteractionPartner.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber == v5)
    && v4->m_pEntity != nullptr )
  {
    v6 = v3;
    v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
    v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
    if ( v7 )
      v9 = *v8;
    else
      v9 = nullptr;
    CAI_BaseNPC::SetTarget(this, pTarget: v9);
    return (this->m_iInteractionPlaying == -1) + 86;
  }
  else
  {
    result = CAI_BaseNPC::SelectFlinchSchedule(this);
    if ( result == 0 )
    {
      if ( !CAI_BaseNPC::HasCondition(this, iCondition: 30)
        || CBaseAnimating::SelectWeightedSequence(this, activity: ACT_VICTORY_DANCE) == -1 )
      {
        if ( this->IsPlayerAlly(this, a2: nullptr) && CAI_BaseNPC::HasCondition(this, iCondition: 53) )
        {
          return 7;
        }
        else if ( CAI_BaseNPC::HasCondition(this, iCondition: 50)
               || CAI_BaseNPC::HasCondition(this, iCondition: 55)
               || CAI_BaseNPC::HasCondition(this, iCondition: 54)
               || CAI_BaseNPC::HasCondition(this, iCondition: 56)
               || CAI_BaseNPC::HasCondition(this, iCondition: 53) )
        {
          return 6;
        }
        else
        {
          v11 = gpGlobals;
          v12 = this->GetEnemies(this);
          if ( v11->curtime
             - CAI_Enemies::LastTimeSeen(this: v12, pEnemy: (CBaseEntity *)0x354, bCheckDangerMemory: true) >= 3.0 )
            return 9;
          else
            return 5;
        }
      }
      else
      {
        return 8;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A8B0
// Name: protected: int CAI_BaseNPC::SelectCombatSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::SelectCombatSchedule(CAI_BaseNPC *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax
  int result; // eax
  CGlobalVars *v11; // edi
  CAI_Enemies *v12; // eax
  CAI_BaseNPC_vtbl *v13; // edi
  CBaseEntity *v14; // eax
  CAI_Enemies *v15; // eax
  AI_EnemyInfo_t *v16; // eax
  CBaseEntity *v17; // eax
  CAI_BaseNPC_vtbl *v18; // edi
  int v19; // eax
  CBaseEntity *v20; // [esp-8h] [ebp-1Ch]
  CBaseEntity *v21; // [esp-4h] [ebp-18h]
  Vector v22; // [esp+8h] [ebp-Ch] BYREF

  m_Index = this->m_hForcedInteractionPartner.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        v9 = *v8;
      else
        v9 = nullptr;
      CAI_BaseNPC::SetTarget(this, pTarget: v9);
      return (this->m_iInteractionPlaying == -1) + 86;
    }
  }
  result = CAI_BaseNPC::SelectFlinchSchedule(this);
  if ( result != 0 )
    return result;
  if ( CAI_BaseNPC::HasCondition(this, iCondition: 26) )
  {
    v11 = gpGlobals;
    v21 = this->GetEnemy_2(this);
    v12 = this->GetEnemies(this);
    if ( v11->curtime - CAI_Enemies::FirstTimeSeen(this: v12, pEnemy: v21) < 2.0 )
      return 4;
  }
  if ( !CAI_BaseNPC::HasCondition(this, iCondition: 30) )
  {
    v13 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v14 = this->GetEnemy_2(this);
    if ( v13->IRelationType(this, a2: v14) == D_FR )
    {
      if ( CAI_BaseNPC::HasCondition(this, iCondition: 10)
        || CAI_BaseNPC::HasCondition(this, iCondition: 17)
        || CAI_BaseNPC::HasCondition(this, iCondition: 18) )
      {
        this->FearSound(this);
        return 32;
      }
      v20 = this->GetEnemy_2(this);
      v15 = this->GetEnemies(this);
      v16 = CAI_Enemies::Find(this: v15, pEntity: v20, bTryDangerMemory: false);
      if ( v16 != nullptr && v16->bUnforgettable || CAI_BaseNPC::GetEnemyLastTimeSeen(this) > gpGlobals->curtime - 5.0 )
      {
        v17 = this->GetEnemy_2(this);
        v18 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v19 = (int)v17->EyePosition(this: v17, result: &v22);
        return v18->FInAimCone(this, a2: (const Vector *)v19) + 14;
      }
    }
    if ( CAI_BaseNPC::HasCondition(this, iCondition: 3) || CAI_BaseNPC::HasCondition(this, iCondition: 4) )
      return 51;
    if ( CAI_BaseNPC::HasCondition(this, iCondition: 10) )
    {
      if ( CAI_BaseNPC::HasCondition(this, iCondition: 38) )
        return 24;
      if ( !CAI_BaseNPC::HasCondition(this, iCondition: 43)
        && !CAI_BaseNPC::HasCondition(this, iCondition: 42)
        && !CAI_BaseNPC::HasCondition(this, iCondition: 45) )
      {
        if ( CAI_ShotRegulator::IsInRestInterval(this: &this->m_ShotRegulator)
          && CAI_BaseNPC::HasCondition(this, iCondition: 21) )
        {
          return 12;
        }
        if ( CAI_BaseNPC::HasCondition(this, iCondition: 21) )
        {
          if ( !this->UseAttackSquadSlots(this)
            || CAI_BaseNPC::OccupyStrategySlotRange(this, slotIDStart: 0, slotIDEnd: 1) )
          {
            return 44;
          }
        }
        else
        {
          if ( CAI_BaseNPC::HasCondition(this, iCondition: 22) )
            return 45;
          if ( CAI_BaseNPC::HasCondition(this, iCondition: 23) )
            return 42;
          if ( CAI_BaseNPC::HasCondition(this, iCondition: 24) )
            return 43;
          if ( !CAI_BaseNPC::HasCondition(this, iCondition: 40) )
          {
            if ( CAI_BaseNPC::HasCondition(this, iCondition: 21) || CAI_BaseNPC::HasCondition(this, iCondition: 23) )
            {
              _DevWarning(a1: 2, a2: "No suitable combat schedule!\n");
              return 82;
            }
            if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr
              || CAI_BaseNPC::HasCondition(this, iCondition: 39) && (this->CapabilitiesGet(this) & 0x60000) != 0 )
            {
              return 34;
            }
            return (this->CapabilitiesGet(this) & 0x180000) != 0 ? 17 : 27;
          }
        }
        return 12;
      }
    }
    else
    {
      if ( !CAI_BaseNPC::HasCondition(this, iCondition: 13) )
        return 12;
      if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr && (this->CapabilitiesGet(this) & 0x60000) == 0 )
        return (this->CapabilitiesGet(this) & 0x180000) != 0 ? 17 : 27;
    }
    return 36;
  }
  CAI_BaseNPC::SetEnemy(this, pEnemy: nullptr, bSetCondNewEnemy: true);
  if ( CAI_BaseNPC::ChooseEnemy(this) )
    CAI_BaseNPC::ClearCondition(this, iCondition: 30);
  else
    CAI_BaseNPC::SetState(this, State: NPC_STATE_ALERT);
  return this->SelectSchedule(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003ACC0
// Name: protected: virtual int CAI_BaseNPC::SelectScriptSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CAI_BaseNPC::SelectScriptSchedule@<eax>(CAI_BaseNPC *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax

  m_Index = this->m_hCine.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    return 57;
  }
  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  _DevWarning(a1: 2, a2: "Script failed for %s\n", pszValue);
  CAI_BaseNPC::CineCleanup(this, a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AD30
// Name: protected: virtual void CAI_BaseNPC::PlayFlinchGesture(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BaseNPC::PlayFlinchGesture(CAI_BaseNPC *this@<ecx>, int a2@<edi>)
{
  Activity (__thiscall *GetFlinchActivity)(CAI_BaseNPC *, bool, bool); // edx
  Activity v4; // edi
  int GestureLayer; // eax
  int LayerSequence; // eax
  float flNextFlinch; // [esp+10h] [ebp-4h]

  if ( this->CanFlinch(this) )
  {
    flNextFlinch = ((double (__thiscall *)(IUniformRandomStream *, int, int, int))random->RandomFloat)(
                     a1: random,
                     a2: 1056964608,
                     a3: 1065353216,
                     a4: a2);
    GetFlinchActivity = this->GetFlinchActivity;
    if ( (this->m_afMemory & 0x40) != 0 )
    {
      v4 = GetFlinchActivity(this, a2: false, a3: true);
      if ( CAI_BaseNPC::HaveSequenceForActivity(this, activity: v4) )
        CBaseAnimatingOverlay::RestartGesture(this, activity: v4, addifmissing: true, autokill: true);
    }
    else
    {
      v4 = GetFlinchActivity(this, a2: true, a3: true);
      if ( CAI_BaseNPC::HaveSequenceForActivity(this, activity: v4) )
        CBaseAnimatingOverlay::RestartGesture(this, activity: v4, addifmissing: true, autokill: true);
      this->m_afMemory |= 0x40u;
    }
    if ( v4 != ACT_INVALID )
    {
      GestureLayer = CBaseAnimatingOverlay::FindGestureLayer(this, activity: v4);
      LayerSequence = CBaseAnimatingOverlay::GetLayerSequence(this, iLayer: GestureLayer);
      if ( LayerSequence != -1 )
        flNextFlinch = CBaseAnimating::SequenceDuration(this, iSequence: LayerSequence) + flNextFlinch;
      this->m_flNextFlinchTime = gpGlobals->curtime + flNextFlinch;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AE20
// Name: public: virtual int CAI_BaseNPC::SelectSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BaseNPC::SelectSchedule(CAI_BaseNPC *this)
{
  int result; // eax

  if ( CAI_BaseNPC::HasCondition(this, iCondition: 61) )
  {
    this->m_flGravity = 1.0;
    CBaseEntity::SetGroundEntity(this, ground: nullptr);
    return 79;
  }
  else
  {
    switch ( this->m_NPCState )
    {
      case NPC_STATE_NONE:
        _DevWarning(a1: 2, a2: "NPC_STATE IS NONE!\n");
        result = 82;
        break;
      case NPC_STATE_IDLE:
        result = CAI_BaseNPC::SelectIdleSchedule(this);
        break;
      case NPC_STATE_ALERT:
        result = CAI_BaseNPC::SelectAlertSchedule(this);
        break;
      case NPC_STATE_COMBAT:
        result = CAI_BaseNPC::SelectCombatSchedule(this);
        break;
      case NPC_STATE_SCRIPT:
        result = this->SelectScriptSchedule(this);
        break;
      case NPC_STATE_PRONE:
        result = 1;
        break;
      case NPC_STATE_DEAD:
        result = this->SelectDeadSchedule(this);
        break;
      default:
        _DevWarning(a1: 2, a2: "Invalid State for SelectSchedule!\n");
        result = 82;
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003AEF0
// Name: public: bool CAI_BaseNPC::SetSchedule(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::SetSchedule(CAI_BaseNPC *this, int localScheduleID)
{
  CAI_Schedule *ScheduleOfType; // edi

  ScheduleOfType = CAI_BaseNPC::GetScheduleOfType(this, scheduleType: localScheduleID);
  if ( ScheduleOfType == nullptr )
    return 0;
  this->m_IdealSchedule = this->GetGlobalScheduleId(this, a2: localScheduleID);
  CAI_BaseNPC::SetSchedule(this, pNewSchedule: ScheduleOfType);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AF40
// Name: protected: virtual class CAI_Schedule __near * CAI_BaseNPC::GetNewSchedule(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_BaseNPC::GetNewSchedule(CAI_BaseNPC *this)
{
  NPC_STATE m_NPCState; // eax
  int v4; // eax
  int v5; // edi

  if ( CAI_BaseNPC::HasCondition(this, iCondition: 67) )
    return CAI_BaseNPC::GetScheduleOfType(this, scheduleType: 74);
  if ( this->m_NPCState == NPC_STATE_COMBAT && this->GetEnemy_2(this) == nullptr )
  {
    DevMsg(a1: "**ERROR: Combat State with no enemy! slamming to ALERT\n");
    CAI_BaseNPC::SetState(this, State: NPC_STATE_ALERT);
  }
  m_NPCState = this->m_NPCState;
  if ( m_NPCState == NPC_STATE_SCRIPT || m_NPCState == NPC_STATE_DEAD || this->m_iInteractionState == 3 )
    v4 = CAI_BaseNPC::SelectSchedule(this);
  else
    v4 = this->SelectSchedule(this);
  v5 = v4;
  this->m_IdealSchedule = this->GetGlobalScheduleId(this, a2: v4);
  return CAI_BaseNPC::GetScheduleOfType(this, scheduleType: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1003AFE0
// Name: private: void CAI_BaseNPC::StartScriptMoveToTargetTask(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CAI_BaseNPC::StartScriptMoveToTargetTask(CAI_BaseNPC *this@<ecx>, int a2@<ebp>, int task)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  CBaseEntity *v11; // edi
  float v12; // xmm0_4
  float v13; // xmm1_4
  __int128 v14; // xmm0
  Activity ScriptCustomMoveActivity; // edi
  const char *pszValue; // eax
  const char *DebugName; // eax
  const char *v18; // eax
  CAI_Navigator *m_pNavigator; // edi
  CBaseEntity *v20; // eax
  const QAngle *AbsAngles; // eax
  const char *v22; // [esp-24h] [ebp-64h]
  const char *v23; // [esp-20h] [ebp-60h]
  _DWORD v24[3]; // [esp-Ch] [ebp-4Ch] BYREF
  _BYTE goal[52]; // [esp+0h] [ebp-40h] OVERLAPPED
  _DWORD v26[3]; // [esp+34h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+40h] [ebp+0h]

  v26[0] = a2;
  v26[1] = retaddr;
  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index == -1 )
    goto LABEL_19;
  v5 = (unsigned __int16)m_Index;
  v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v7 = HIWORD(m_Index);
  if ( v6->m_SerialNumber != v7 || v6->m_pEntity == nullptr )
    goto LABEL_19;
  v8 = v5;
  v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
  v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
  if ( v9 )
    v11 = *v10;
  else
    v11 = nullptr;
  if ( (v11->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)v26);
  v12 = v11->m_vecAbsOrigin.x - this->m_vecOrigin.m_Value.x;
  v13 = (float)((float)((float)(v11->m_vecAbsOrigin.y - this->m_vecOrigin.m_Value.y)
                      * (float)(v11->m_vecAbsOrigin.y - this->m_vecOrigin.m_Value.y))
              + (float)((float)(v11->m_vecAbsOrigin.z - this->m_vecOrigin.m_Value.z)
                      * (float)(v11->m_vecAbsOrigin.z - this->m_vecOrigin.m_Value.z)))
      + (float)(v12 * v12);
  v14 = 0;
  *(float *)&v14 = fsqrt(v13);
  *(_OWORD *)&goal[36] = v14;
  if ( *(float *)&v14 < 1.0 )
  {
    CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
    goto LABEL_33;
  }
  if ( task == 9 )
  {
    ScriptCustomMoveActivity = ACT_WALK;
    goto LABEL_17;
  }
  if ( task == 10 )
  {
    ScriptCustomMoveActivity = ACT_RUN;
    goto LABEL_17;
  }
  ScriptCustomMoveActivity = CAI_BaseNPC::GetScriptCustomMoveActivity(this);
  if ( ScriptCustomMoveActivity != ACT_SCRIPT_CUSTOM_MOVE )
  {
LABEL_17:
    if ( CAI_BaseNPC::TranslateActivity(this, idealActivity: ScriptCustomMoveActivity, pIdealWeaponActivity: nullptr) == ACT_INVALID )
      goto LABEL_33;
  }
  if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTargetEnt, val: nullptr) )
  {
LABEL_19:
    this->TaskFail(this, a2: 1);
    goto LABEL_33;
  }
  *(float *)goal = AIN_NO_DEST.z;
  v9 = this->m_NPCState == NPC_STATE_SCRIPT;
  *(_QWORD *)&v24[1] = *(_QWORD *)&AIN_NO_DEST.x;
  v24[0] = 1;
  *(_DWORD *)&goal[4] = -1;
  *(_DWORD *)&goal[8] = ScriptCustomMoveActivity;
  *(_DWORD *)&goal[12] = -1;
  *(_DWORD *)&goal[16] = -1;
  *(_DWORD *)&goal[20] = -1082130432;
  *(_QWORD *)&goal[24] = 3212836864LL;
  *(_DWORD *)&goal[32] = AIN_DEF_TARGET_8;
  if ( v9 )
  {
    if ( this->m_ScriptArrivalActivity == ACT_INVALID )
    {
      if ( this->m_strScriptArrivalSequence.pszValue != nullptr )
      {
        pszValue = this->m_strScriptArrivalSequence.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        *(_DWORD *)&goal[16] = CBaseAnimating::LookupSequence(this, label: pszValue);
      }
    }
    else
    {
      *(_DWORD *)&goal[12] = this->m_ScriptArrivalActivity;
    }
  }
  if ( this->m_pNavigator->SetGoal(this: this->m_pNavigator, a2: (const AI_NavGoal_t *)v24, a3: 4u) )
  {
    m_pNavigator = this->m_pNavigator;
    v20 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTargetEnt);
    AbsAngles = CBaseEntity::GetAbsAngles(this: v20);
    CAI_Navigator::SetArrivalDirection(this: m_pNavigator, goalAngle: AbsAngles);
  }
  else
  {
    if ( CBreakable::GetMaxBreakableSize(this: this->m_pNavigator) == 0 )
    {
      v22 = this->TaskName(this, a2: task);
      DebugName = CBaseEntity::GetDebugName(this);
      DevWarning(a1: "%s %s failed Urgent Movement, retrying\n", DebugName, v22);
      return;
    }
    v23 = this->TaskName(this, a2: task);
    v18 = CBaseEntity::GetDebugName(this);
    DevWarning(a1: "%s %s failed Urgent Movement, abandoning schedule\n", v18, v23);
    this->TaskFail(this, a2: 11);
  }
LABEL_33:
  this->m_ScriptArrivalActivity = ACT_INVALID;
  this->m_strScriptArrivalSequence.pszValue = nullptr;
  CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
}

//------------------------------------------------------------------------------
// Address: 0x1003B2A0
// Name: public: virtual void CAI_BaseNPC::RunTask(struct Task_t const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_BaseNPC::RunTask(CAI_BaseNPC *this@<ecx>, int a2@<ebp>, const Task_t *pTask)
{
  const Task_t *v4; // edi
  int iTask; // eax
  bool IsWaitFinished; // al
  CBaseEntity *v7; // eax
  const Vector *v8; // eax
  CAI_Motor *v9; // edi
  CAI_Hint *VehicleEntity; // eax
  CAI_Hint *v11; // eax
  const char *DebugName; // eax
  void (__thiscall *v13)(CAI_BaseNPC *, const Task_t *); // edx
  CFmtStrN<256> *v14; // eax
  CFmtStrN<256> *v15; // eax
  Vector *v16; // eax
  __int128 v17; // xmm0
  CFmtStrN<256> *v18; // eax
  CFmtStrN<256> *v19; // eax
  Activity StoppedActivity; // eax
  int v21; // eax
  bool (__thiscall *v22)(CBaseCombatCharacter *, const Vector *); // edx
  CAI_Motor *v23; // edi
  double v24; // st7
  CAI_Motor *v25; // ecx
  CBasePlayer *v26; // eax
  CAI_Motor *v27; // edi
  const Vector *v28; // eax
  int v29; // eax
  int v30; // eax
  Activity v31; // xmm0_4
  CAI_Navigator *v32; // ecx
  bool (__thiscall *v33)(CAI_Navigator *, const AI_NavGoal_t *, unsigned int); // eax
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // edx
  CGlobalVars *v35; // edi
  CAI_Enemies *v36; // eax
  const Vector *v37; // eax
  bool (__thiscall *FInAimCone)(CBaseCombatCharacter *, const Vector *); // edx
  float v39; // ecx
  CAI_Navigator *m_pNavigator; // ecx
  const Vector *GoalPos; // eax
  float z; // ecx
  float flTaskData; // xmm2_4
  float v44; // xmm0_4
  __int128 v45; // xmm1
  const Vector *v46; // eax
  __int128 v47; // xmm1
  const Vector *AbsOrigin; // eax
  float v49; // xmm1_4
  float v50; // xmm0_4
  CAI_Navigator *v51; // eax
  float v52; // xmm0_4
  __int128 v53; // xmm1
  const Vector *v54; // eax
  Activity v55; // edi
  Activity MovementActivity; // eax
  int v57; // eax
  CAI_BaseNPC_vtbl *v58; // edx
  CBaseEntity *v59; // eax
  const Vector *v60; // eax
  CAI_Navigator *v61; // ecx
  bool (__thiscall *SetGoal)(CAI_Navigator *, const AI_NavGoal_t *, unsigned int); // edx
  CAI_Navigator *v63; // ecx
  float v64; // xmm0_4
  void (__thiscall *RunTask)(CAI_BaseNPC *, const Task_t *); // edx
  const Vector *v66; // eax
  __int64 v67; // xmm0_8
  float v68; // eax
  const Vector *v69; // eax
  __int128 v70; // xmm1
  CAI_Navigator *v71; // edi
  CWorld *LocalPlayer; // eax
  void (__thiscall *v73)(CAI_BaseNPC *, const Task_t *); // edx
  __int64 v74; // xmm0_8
  CAI_Motor *m_pMotor; // ecx
  int iTaskInterrupt; // eax
  int v77; // eax
  CAI_BaseNPC_vtbl *v78; // edx
  CAI_TacticalServices *m_pTacticalServices; // edi
  double v80; // st7
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  const Vector *v82; // eax
  CAI_BaseNPC_vtbl *v83; // edi
  const Vector *v84; // eax
  CAI_Navigator *v85; // eax
  CAI_Navigator_vtbl *v86; // edi
  AI_NavGoal_t *v87; // eax
  float v88; // xmm0_4
  float v89; // xmm1_4
  CAI_BaseNPC_vtbl *v90; // edi
  const Vector *v91; // eax
  float i; // xmm0_4
  float v93; // xmm0_4
  float v94; // xmm1_4
  CAI_BaseNPC_vtbl *v95; // edi
  const Vector *v96; // eax
  const Vector *v97; // eax
  const Vector *v98; // eax
  CAI_Hint *Hint; // edi
  const Vector *v100; // eax
  CBaseEntity *z_low; // edx
  const Vector *v102; // eax
  const Vector *v103; // eax
  float v104; // xmm1_4
  float v105; // xmm0_4
  float v106; // xmm2_4
  float v107; // xmm0_4
  float v108; // xmm1_4
  CAI_BaseNPC_vtbl *v109; // edi
  const Vector *v110; // eax
  float v111; // xmm0_4
  float v112; // xmm1_4
  CAI_BaseNPC_vtbl *v113; // edi
  const Vector *v114; // eax
  CBaseEntity *v115; // eax
  float v116; // xmm0_4
  Activity v117; // eax
  CAI_Expresser *(__thiscall *GetExpresser)(CAI_BaseNPC *); // eax
  CAI_Expresser *v119; // eax
  int v120; // eax
  CAI_ScriptedSequence *v121; // eax
  CAI_ScriptedSequence *v122; // eax
  bool v123; // zf
  CHandle<CBaseEntity> *p_m_hCine; // ecx
  CAI_ScriptedSequence *v125; // eax
  edict_t *m_pPev; // ecx
  CAI_ScriptedSequence *v127; // eax
  bool v128; // al
  CHandle<CBaseEntity> *v129; // ecx
  CAI_ScriptedSequence *v130; // eax
  CAI_ScriptedSequence *v131; // eax
  CHandle<CBaseEntity> *v132; // eax
  CAI_ScriptedSequence *v133; // eax
  CAI_ScriptedSequence *v134; // eax
  CAI_ScriptedSequence *v135; // eax
  float v136; // xmm0_4
  float v137; // xmm1_4
  __int128 v138; // xmm0
  const Vector *v139; // eax
  CBaseEntity *v140; // eax
  CBaseCombatWeapon *v141; // eax
  CBaseCombatCharacter *Owner; // eax
  CAI_BaseNPC *v143; // ecx
  int m_Value; // eax
  const Vector *BoundingMaxs; // eax
  const Vector *BoundingMins; // eax
  const Vector *v147; // eax
  const Vector *v148; // eax
  unsigned int m_nAITraceMask; // edx
  float v150; // xmm0_4
  const char *v151; // eax
  CFmtStrN<256> v152; // [esp+40h] [ebp-588h] BYREF
  CFmtStrN<256> v153; // [esp+14Ch] [ebp-47Ch] BYREF
  CFmtStrN<256> v154; // [esp+258h] [ebp-370h] BYREF
  CFmtStrN<256> v155; // [esp+364h] [ebp-264h] BYREF
  AI_NavGoal_t v156; // [esp+470h] [ebp-158h] BYREF
  AI_NavGoal_t v157; // [esp+4A0h] [ebp-128h] BYREF
  int v158; // [esp+4D0h] [ebp-F8h] BYREF
  __int128 v159; // [esp+4DCh] [ebp-ECh] BYREF
  _BYTE v160[40]; // [esp+4F4h] [ebp-D4h] BYREF
  float v161[3]; // [esp+51Ch] [ebp-ACh] BYREF
  AI_NavGoal_t goal; // [esp+528h] [ebp-A0h] BYREF
  float v163; // [esp+558h] [ebp-70h]
  Vector v164; // [esp+55Ch] [ebp-6Ch] BYREF
  Vector v165; // [esp+568h] [ebp-60h] BYREF
  Vector maxs; // [esp+574h] [ebp-54h] BYREF
  Vector vecStart; // [esp+580h] [ebp-48h] BYREF
  CBaseEntity *pTarget; // [esp+58Ch] [ebp-3Ch]
  Vector mins; // [esp+590h] [ebp-38h] BYREF
  __int128 v170; // [esp+59Ch] [ebp-2Ch] OVERLAPPED BYREF
  Vector vecDown; // [esp+5ACh] [ebp-1Ch]
  int offset; // [esp+5B8h] [ebp-10h]
  _DWORD v173[2]; // [esp+5BCh] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+5C8h] [ebp+0h]

  v173[0] = a2;
  v173[1] = retaddr;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CAI_BaseNPC::RunTask",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  v4 = pTask;
  iTask = pTask->iTask;
  switch ( pTask->iTask )
  {
    case 2:
    case 0x7B:
      goto $LN144;
    case 4:
    case 5:
      v37 = this->GetEnemyLKP(this);
      FInAimCone = this->FInAimCone;
      *(_QWORD *)((char *)&v170 + 4) = *(_QWORD *)&v37->x;
      HIDWORD(v170) = LODWORD(v37->z);
      if ( !FInAimCone(this, a2: (const Vector *)((char *)&v170 + 4)) )
      {
        vecDown.z = v39;
        CAI_Motor::SetIdealYawToTargetAndUpdate(
          this: this->m_pMotor,
          target: (const Vector *)((char *)&v170 + 4),
          yawSpeed: -2.0);
      }
$LN144:
      IsWaitFinished = CAI_BaseNPC::IsWaitFinished(this);
      goto LABEL_3;
    case 6:
      if ( this->ShouldAlwaysThink(this) )
        goto LABEL_244;
      if ( UTIL_FindClientInPVS(pEdict: this->m_Network.m_pPev) != nullptr )
        goto LABEL_244;
      if ( this->m_NPCState == NPC_STATE_COMBAT && this->GetEnemy_2(this) != nullptr )
      {
        GetEnemy_2 = this->GetEnemy_2;
        v35 = gpGlobals;
        LODWORD(vecDown.z) = 1;
        LODWORD(vecDown.y) = GetEnemy_2(this);
        v36 = this->GetEnemies(this);
        if ( v35->curtime
           - CAI_Enemies::LastTimeSeen(this: v36, pEnemy: (CBaseEntity *)LODWORD(vecDown.y), bCheckDangerMemory: true) < 15.0 )
          goto LABEL_244;
      }
      goto $LN218;
    case 9:
    case 0xA:
    case 0xB:
      CAI_BaseNPC::StartScriptMoveToTargetTask(this, a2: (int)v173, task: pTask->iTask);
      goto $LN218;
    case 0xC:
    case 0xD:
      if ( iTask != 13
        || (LODWORD(vecStart.x) = CAI_Navigator::GetGoalTarget(this: this->m_pNavigator), LODWORD(vecStart.x) == 0) )
      {
        LODWORD(vecStart.x) = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTargetEnt);
        if ( LODWORD(vecStart.x) == 0 )
        {
          this->TaskFail(this, a2: 1);
          goto $LN218;
        }
      }
      if ( CAI_Navigator::GetGoalType(this: this->m_pNavigator) == GOALTYPE_NONE )
      {
        CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
        CAI_Navigator::ClearGoal(this: this->m_pNavigator);
        goto $LN218;
      }
      m_pNavigator = this->m_pNavigator;
      HIBYTE(offset) = 0;
      GoalPos = CAI_Navigator::GetGoalPos(this: m_pNavigator);
      z = GoalPos->z;
      flTaskData = pTask->flTaskData;
      *(_QWORD *)&vecStart.y = *(_QWORD *)&GoalPos->x;
      *(float *)&pTarget = z;
      LODWORD(v44) = COERCE_UNSIGNED_INT(z - this->m_vecOrigin.m_Value.z) & _mask__AbsFloat_;
      mins.z = v44;
      if ( flTaskData <= v44 )
      {
        HIBYTE(offset) = 1;
      }
      else
      {
        v45 = 0;
        *(float *)&v45 = fsqrt(
                           (float)((float)(vecStart.y - this->m_vecOrigin.m_Value.x)
                                 * (float)(vecStart.y - this->m_vecOrigin.m_Value.x))
                         + (float)((float)(vecStart.z - this->m_vecOrigin.m_Value.y)
                                 * (float)(vecStart.z - this->m_vecOrigin.m_Value.y)));
        v170 = v45;
        v44 = *(float *)&v45;
        LODWORD(mins.z) = v45;
      }
      if ( this->m_pNavigator->m_navType == NAV_JUMP )
        goto LABEL_92;
      if ( flTaskData > v44
        || (v46 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)LODWORD(vecStart.x)),
            v47 = 0,
            *(float *)&v47 = fsqrt(
                               (float)((float)((float)(vecStart.y - v46->x) * (float)(vecStart.y - v46->x))
                                     + (float)((float)(vecStart.z - v46->y) * (float)(vecStart.z - v46->y)))
                             + (float)((float)(*(float *)&pTarget - v46->z) * (float)(*(float *)&pTarget - v46->z))),
            v170 = v47,
            *(float *)&v47 > pTask->flTaskData * 0.5) )
      {
        AbsOrigin = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)LODWORD(vecStart.x));
        v49 = AbsOrigin->y - this->m_vecOrigin.m_Value.y;
        v50 = AbsOrigin->x - this->m_vecOrigin.m_Value.x;
        v51 = this->m_pNavigator;
        v52 = (float)(v50 * v50) + (float)(v49 * v49);
        v53 = 0;
        *(float *)&v53 = fsqrt(v52);
        v170 = v53;
        LODWORD(mins.z) = v53;
        LODWORD(mins.y) = v51;
        v54 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)LODWORD(vecStart.x));
        if ( !CAI_Navigator::UpdateGoalPos(this: (CAI_Navigator *)LODWORD(mins.y), goalPos: v54) )
          goto LABEL_90;
      }
      v44 = mins.z;
LABEL_92:
      if ( pTask->flTaskData > v44 )
        goto LABEL_177;
      if ( HIBYTE(offset) != 0 || v44 >= 190.0 || (v55 = ACT_WALK, this->m_NPCState == NPC_STATE_COMBAT) )
        v55 = ACT_RUN;
      MovementActivity = CAI_Navigator::GetMovementActivity(this: this->m_pNavigator);
      if ( MovementActivity == ACT_WALK_AIM )
      {
        MovementActivity = ACT_WALK;
      }
      else if ( MovementActivity == ACT_RUN_AIM )
      {
        MovementActivity = ACT_RUN;
      }
      if ( MovementActivity != v55 )
        CAI_Navigator::SetMovementActivity(this: this->m_pNavigator, activity: v55);
      CAI_Navigator::SetArrivalDirection(this: this->m_pNavigator, pTarget: (CBaseEntity *)LODWORD(vecStart.x));
      goto $LN218;
    case 0xE:
      v74 = *(_QWORD *)&this->m_angRotation.m_Value.x;
      m_pMotor = this->m_pMotor;
      maxs.z = this->m_angRotation.m_Value.z;
      iTaskInterrupt = this->m_ScheduleState.iTaskInterrupt;
      *(_QWORD *)&maxs.x = v74;
      maxs.y = m_pMotor->m_IdealYaw + 180.0;
      if ( iTaskInterrupt == 0 )
      {
        if ( this->IsPlayerAlly(this, a2: nullptr) )
        {
          CHintCriteria::CHintCriteria(this: (CHintCriteria *)v160);
          CHintCriteria::AddHintType(this: (CHintCriteria *)v160, hintType: 950);
          CHintCriteria::SetFlag(this: (CHintCriteria *)v160, bitmask: 2);
          vecDown.z = 240.0;
          v97 = CBaseEntity::GetAbsOrigin(this);
          CHintCriteria::AddIncludePosition(this: (CHintCriteria *)v160, position: v97, radius: vecDown.z);
          vecDown.z = 28.0;
          v98 = CBaseEntity::GetAbsOrigin(this);
          CHintCriteria::AddExcludePosition(this: (CHintCriteria *)v160, position: v98, radius: vecDown.z);
          Hint = CAI_HintManager::FindHint(pNPC: this, hintCriteria: (const CHintCriteria *)v160);
          if ( Hint != nullptr )
          {
            LODWORD(mins.z) = gpGlobals->maxClients <= 1 ? UTIL_GetLocalPlayer() : nullptr;
            v100 = CBaseEntity::GetAbsOrigin(this: Hint);
            z_low = (CBaseEntity *)LODWORD(v100->z);
            *(_QWORD *)&vecStart.y = *(_QWORD *)&v100->x;
            pTarget = z_low;
            v102 = CBaseEntity::GetAbsOrigin(this);
            *((float *)&v170 + 1) = vecStart.y - v102->x;
            *((float *)&v170 + 2) = vecStart.z - v102->y;
            *((float *)&v170 + 3) = *(float *)&pTarget - v102->z;
            v103 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)LODWORD(mins.z));
            v104 = vecStart.z - v103->y;
            v105 = vecStart.y - v103->x;
            v106 = *(float *)&pTarget - v103->z;
            mins.y = *((float *)&v170 + 2) * *((float *)&v170 + 2);
            if ( (float)((float)((float)(v104 * v104) + (float)(v105 * v105)) + (float)(v106 * v106)) > (float)((float)((float)(*((float *)&v170 + 2) * *((float *)&v170 + 2)) + (float)(*((float *)&v170 + 1) * *((float *)&v170 + 1))) + (float)(*((float *)&v170 + 3) * *((float *)&v170 + 3))) )
            {
              AI_NavGoal_t::AI_NavGoal_t(
                this: &v157,
                dest: (Vector *)&vecStart.y,
                activity: ACT_INVALID,
                tolerance: -1.0,
                flags: 0,
                pTarget: AIN_DEF_TARGET_8);
              if ( this->m_pNavigator->SetGoal(this: this->m_pNavigator, a2: &v157, a3: 0) )
              {
                CAI_Hint::Unlock(this: Hint, flSeconds: 0.1);
                CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
                CHintCriteria::~CHintCriteria(this: (CHintCriteria *)v160);
                goto $LN218;
              }
            }
          }
          CHintCriteria::~CHintCriteria(this: (CHintCriteria *)v160);
          v4 = pTask;
        }
        AngleVectors(angles: (const QAngle *)&maxs, forward: &v165);
        v107 = v4->flTaskData;
        v108 = 36.0;
        if ( v107 <= 36.0 )
          v108 = v4->flTaskData;
        if ( CAI_Navigator::SetVectorGoal(
               this: this->m_pNavigator,
               dir: &v165,
               targetDist: v107,
               minDist: v108,
               fShouldDeflect: true) )
        {
          v109 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v110 = CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
          if ( v109->IsValidMoveAwayDest(this, a2: v110) )
            goto LABEL_244;
          v4 = pTask;
        }
        maxs.y = this->m_pMotor->m_IdealYaw + 91.0;
        AngleVectors(angles: (const QAngle *)&maxs, forward: &v165);
        v111 = v4->flTaskData;
        v112 = 24.0;
        if ( v111 <= 24.0 )
          v112 = v4->flTaskData;
        if ( CAI_Navigator::SetVectorGoal(
               this: this->m_pNavigator,
               dir: &v165,
               targetDist: v111,
               minDist: v112,
               fShouldDeflect: true) )
        {
          v113 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v114 = CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
          if ( v113->IsValidMoveAwayDest(this, a2: v114) )
          {
LABEL_244:
            v143 = this;
LABEL_245:
            CAI_BaseNPC::TaskComplete(this: v143, fIgnoreSetFailedCondition: false);
            goto $LN218;
          }
        }
        goto LABEL_164;
      }
      v77 = iTaskInterrupt - 1;
      if ( v77 != 0 )
      {
        if ( v77 == 1 )
        {
          v78 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          m_pTacticalServices = this->m_pTacticalServices;
          this->m_ScheduleState.iTaskInterrupt = 0;
          v80 = ((double (__thiscall *)(CAI_BaseNPC *, char *))v78->CoverRadius)(a1: this, a2: (char *)&v170 + 4);
          EyePosition = this->EyePosition;
          vecDown.z = v80;
          vecDown.y = 0.0;
          LODWORD(vecDown.x) = (char *)&v159 + 4;
          v82 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))EyePosition)(a1: this);
          if ( CAI_TacticalServices::FindCoverPos(
                 this: m_pTacticalServices,
                 vThreatPos: &this->m_vecOrigin.m_Value,
                 vThreatEyePos: v82,
                 flMinDist: vecDown.x,
                 flMaxDist: vecDown.y,
                 pResult: (Vector *)LODWORD(vecDown.z))
            && (v83 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable,
                v84 = CAI_Navigator::GetGoalPos(this: this->m_pNavigator),
                v83->IsValidMoveAwayDest(this, a2: v84)) )
          {
            v85 = this->m_pNavigator;
            v86 = v85->CAI_Component::__vftable;
            vecDown.z = 0.0;
            LODWORD(mins.y) = v85;
            v87 = AI_NavGoal_t::AI_NavGoal_t(
                    this: &v156,
                    dest: (const Vector *)((char *)&v170 + 4),
                    activity: ACT_RUN,
                    tolerance: -1.0,
                    flags: 0,
                    pTarget: AIN_DEF_TARGET_8);
            v86->SetGoal(this: (CAI_Navigator *)LODWORD(mins.y), a2: v87, a3: LODWORD(vecDown.z));
            this->m_flMoveWaitFinished = gpGlobals->curtime + 2.0;
          }
          else
          {
LABEL_90:
            this->TaskFail(this, a2: 11);
          }
        }
        goto $LN218;
      }
      maxs.y = m_pMotor->m_IdealYaw + 271.0;
      AngleVectors(angles: (const QAngle *)&maxs, forward: &v165);
      v88 = pTask->flTaskData;
      v89 = 24.0;
      if ( v88 <= 24.0 )
        v89 = pTask->flTaskData;
      if ( CAI_Navigator::SetVectorGoal(
             this: this->m_pNavigator,
             dir: &v165,
             targetDist: v88,
             minDist: v89,
             fShouldDeflect: true) )
      {
        v90 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v91 = CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
        if ( v90->IsValidMoveAwayDest(this, a2: v91) )
          goto LABEL_244;
        v4 = pTask;
      }
      for ( i = this->m_pMotor->m_IdealYaw + 180.0; i < 0.0; i = i + 360.0 )
        ;
      for ( ; i >= 360.0; i = i - 360.0 )
        ;
      if ( i < 45.0 || i >= 315.0 )
      {
        maxs.y = 0.0;
      }
      else if ( i >= 135.0 )
      {
        if ( i >= 225.0 )
          maxs.y = 270.0;
        else
          maxs.y = 180.0;
      }
      else
      {
        maxs.y = 90.0;
      }
      AngleVectors(angles: (const QAngle *)&maxs, forward: &v165);
      v93 = v4->flTaskData;
      v94 = 6.0;
      if ( v93 <= 6.0 )
        v94 = v4->flTaskData;
      if ( !CAI_Navigator::SetVectorGoal(
              this: this->m_pNavigator,
              dir: &v165,
              targetDist: v93,
              minDist: v94,
              fShouldDeflect: false) )
      {
LABEL_164:
        ++this->m_ScheduleState.iTaskInterrupt;
        goto $LN218;
      }
      v95 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v96 = CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
      if ( v95->IsValidMoveAwayDest(this, a2: v96) )
        goto LABEL_244;
      ++this->m_ScheduleState.iTaskInterrupt;
$LN218:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return;
    case 0xF:
      v64 = pTask->flTaskData;
      RunTask = this->RunTask;
      LODWORD(mins.x) = 14;
      mins.y = v64;
      RunTask(this, a2: (const Task_t *)&mins);
      if ( CAI_Navigator::IsGoalActive(this: this->m_pNavigator) )
      {
        v66 = CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
        v67 = *(_QWORD *)&v66->x;
        v68 = v66->z;
        *(_QWORD *)((char *)&v170 + 4) = v67;
        *((float *)&v170 + 3) = v68;
        v69 = CBaseEntity::GetAbsOrigin(this);
        v70 = 0;
        *(float *)&v70 = fsqrt(
                           (float)((float)((float)(v69->x - *((float *)&v170 + 1))
                                         * (float)(v69->x - *((float *)&v170 + 1)))
                                 + (float)((float)(v69->y - *((float *)&v170 + 2))
                                         * (float)(v69->y - *((float *)&v170 + 2))))
                         + (float)((float)(v69->z - *((float *)&v170 + 3)) * (float)(v69->z - *((float *)&v170 + 3))));
        v170 = v70;
        if ( *(float *)&v70 < 120.0 )
          this->TaskFail(this, a2: (int)"Path away from best sound too short!\n");
      }
      goto $LN218;
    case 0x15:
    case 0x18:
    case 0x19:
    case 0x1A:
      if ( this->GetEnemy_2(this) != nullptr )
      {
        v57 = this->m_ScheduleState.iTaskInterrupt;
        if ( v57 <= 0 )
        {
          this->m_ScheduleState.iTaskInterrupt = v57 + 1;
        }
        else
        {
          v58 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          this->m_ScheduleState.iTaskInterrupt = 0;
          if ( pTask->iTask == 24 )
          {
            v59 = (CBaseEntity *)((int (__thiscall *)(CAI_BaseNPC *, int))v58->GetEnemy_2)(a1: this, a2: offset);
            v60 = CBaseEntity::GetAbsOrigin(this: v59);
          }
          else
          {
            v60 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *, int))v58->GetEnemyLKP)(a1: this, a2: offset);
          }
          *(_QWORD *)((char *)&v170 + 4) = *(_QWORD *)&v60->x;
          AI_NavGoal_t::AI_NavGoal_t(
            this: (AI_NavGoal_t *)v161,
            dest: &this->m_vInterruptSavePosition,
            activity: ACT_RUN,
            tolerance: -2.0,
            flags: 0,
            pTarget: AIN_DEF_TARGET_8);
          v61 = this->m_pNavigator;
          SetGoal = v61->SetGoal;
          offset = 2;
          ((void (__thiscall *)(CAI_Navigator *, float *))SetGoal)(a1: v61, a2: v161);
          v63 = this->m_pNavigator;
          v164.x = *((float *)&v170 + 1) - v161[1];
          v164.y = *((float *)&v170 + 2) - v161[2];
          v164.z = *((float *)&v170 + 3) - *(float *)&goal.type;
          CAI_Navigator::SetArrivalDirection(this: v63, goalDirection: &v164);
        }
      }
      else
      {
        this->TaskFail(this, a2: 6);
      }
      goto $LN218;
    case 0x1E:
      if ( gpGlobals->maxClients == 1 )
      {
        v71 = this->m_pNavigator;
        LocalPlayer = (CWorld *)UTIL_GetLocalPlayer();
        CAI_Navigator::SetAllowBigStep(this: v71, pEntToStepOff: LocalPlayer);
      }
      v73 = this->RunTask;
      LODWORD(mins.x) = 14;
      mins.y = 48.0;
      v73(this, a2: (const Task_t *)&mins);
      goto $LN218;
    case 0x2E:
    case 0x7C:
    case 0x8D:
      goto $LN218;
    case 0x33:
    case 0x37:
      if ( !CAI_BaseNPC::IsWaitFinished(this) )
        goto LABEL_225;
      goto LABEL_244;
    case 0x34:
    case 0x36:
    case 0x39:
      v139 = CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
      if ( pTask->flTaskData >= fsqrt(
                                  (float)((float)((float)(this->m_vecOrigin.m_Value.y - v139->y)
                                                * (float)(this->m_vecOrigin.m_Value.y - v139->y))
                                        + (float)((float)(this->m_vecOrigin.m_Value.z - v139->z)
                                                * (float)(this->m_vecOrigin.m_Value.z - v139->z)))
                                + (float)((float)(this->m_vecOrigin.m_Value.x - v139->x)
                                        * (float)(this->m_vecOrigin.m_Value.x - v139->x))) )
        goto LABEL_244;
      goto $LN218;
    case 0x35:
    case 0x38:
      v136 = this->m_vecLastPosition.x - this->m_vecOrigin.m_Value.x;
      v137 = (float)((float)(this->m_vecLastPosition.y - this->m_vecOrigin.m_Value.y)
                   * (float)(this->m_vecLastPosition.y - this->m_vecOrigin.m_Value.y))
           + (float)(v136 * v136);
      v138 = 0;
      *(float *)&v138 = fsqrt(v137);
      v159 = v138;
      if ( *(float *)&v138 <= pTask->flTaskData )
        goto LABEL_225;
      goto LABEL_244;
    case 0x3C:
    case 0x3D:
    case 0x89:
      IsWaitFinished = this->IsActivityFinished(this);
      goto LABEL_3;
    case 0x3F:
    case 0x40:
    case 0x41:
    case 0x44:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x79:
    case 0x7E:
    case 0x7F:
      this->m_pMotor->UpdateYaw(this: this->m_pMotor, a2: -1);
      IsWaitFinished = CAI_BaseNPC::FacingIdeal(this, flTolerance: 0.0);
      goto LABEL_3;
    case 0x42:
      if ( gpGlobals->maxClients > 1 || (v26 = UTIL_GetLocalPlayer()) == nullptr )
      {
        this->TaskFail(this, a2: 21);
        goto $LN218;
      }
      v27 = this->m_pMotor;
      v28 = CBaseEntity::GetAbsOrigin(this: v26);
      CAI_Motor::SetIdealYawToTargetAndUpdate(this: v27, target: v28, yawSpeed: -2.0);
      this->SetTurnActivity(this);
      if ( CAI_BaseNPC::IsWaitFinished(this) && CAI_Motor::DeltaIdealYaw(this: this->m_pMotor) < 10.0 )
        goto LABEL_244;
      goto $LN218;
    case 0x43:
      v21 = ((int (__thiscall *)(CAI_BaseNPC *, int))this->GetEnemyLKP)(a1: this, a2: offset);
      v22 = this->FInAimCone;
      *(_QWORD *)((char *)&v170 + 4) = *(_QWORD *)v21;
      HIDWORD(v170) = *(_DWORD *)(v21 + 8);
      if ( v22(this, a2: (const Vector *)((char *)&v170 + 4)) )
      {
        v24 = ((double (__thiscall *)(CAI_BaseNPC *, int))this->CalcReasonableFacing)(a1: this, a2: 1);
        mins.z = v24;
        v25 = this->m_pMotor;
        if ( fabs(v24 - v25->m_IdealYaw) > 1.0 )
          v25->m_IdealYaw = mins.z;
      }
      else
      {
        CAI_Motor::SetIdealYawToTarget(
          this: this->m_pMotor,
          target: (const Vector *)((char *)&v170 + 4),
          noise: 0.0,
          offset: 0.0);
        v23 = this->m_pMotor;
        v23->m_IdealYaw = this->CalcReasonableFacing(this, a2: true);
      }
      this->m_pMotor->UpdateYaw(this: this->m_pMotor, a2: -1);
      if ( CAI_BaseNPC::FacingIdeal(this, flTolerance: this->m_flFaceEnemyTolerance) )
        goto LABEL_244;
      goto $LN218;
    case 0x45:
      if ( CBasePlayer::GetVehicleEntity(this) == nullptr )
        this->TaskFail(this, a2: 4);
      VehicleEntity = CBasePlayer::GetVehicleEntity(this);
      if ( CAI_Hint::User(this: VehicleEntity) != this )
      {
        v11 = CBasePlayer::GetVehicleEntity(this);
        DebugName = CBaseEntity::GetDebugName(this: v11);
        DevMsg(a1: "Hint node (%s) being used by non-owner!\n", DebugName);
      }
      if ( this->IsActivityFinished(this) )
        goto LABEL_244;
      goto $LN218;
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
    case 0x50:
    case 0x51:
      CAI_BaseNPC::RunAttackTask(this, task: pTask->iTask);
      goto $LN218;
    case 0x5D:
      if ( this->GetExpresser(this) == nullptr )
        goto $LN218;
      GetExpresser = this->GetExpresser;
      if ( pTask->flTaskData == 0.0 )
      {
        v120 = (int)GetExpresser(this);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v120 + 16))(a1: v120) != 0 )
          goto $LN218;
      }
      else
      {
        v119 = GetExpresser(this);
        IsWaitFinished = CAI_Expresser::CanSpeakAfterMyself(this: v119);
LABEL_3:
        if ( !IsWaitFinished )
          goto $LN218;
      }
      goto LABEL_244;
    case 0x5E:
      if ( this->m_nSequence.m_Value == this->m_nIdealSequence )
        goto LABEL_244;
      goto $LN218;
    case 0x65:
    case 0x66:
      CAI_BaseNPC::AutoMovement(this, pTarget: nullptr, pTraceResult: nullptr);
      if ( this->IsActivityFinished(this) )
        goto LABEL_244;
      goto $LN218;
    case 0x67:
    case 0x68:
    case 0x69:
      if ( iTask == 105 )
        v7 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTargetEnt);
      else
        v7 = this->GetEnemy_2(this);
      if ( v7 != nullptr )
      {
        v8 = CBaseEntity::GetAbsOrigin(this: v7);
        v9 = this->m_pMotor;
        *(float *)&goal.flags = v8->x - this->m_vecOrigin.m_Value.x;
        *(float *)&goal.pTarget = v8->y - this->m_vecOrigin.m_Value.y;
        v163 = v8->z - this->m_vecOrigin.m_Value.z;
        vecDown.z = -2.0;
        vecDown.y = UTIL_VecToYaw(vec: (const Vector *)&goal.flags);
        CAI_Motor::SetIdealYawAndUpdate(this: v9, idealYaw: vecDown.y, yawSpeed: vecDown.z);
      }
      if ( this->IsActivityFinished(this) )
        goto LABEL_244;
      goto $LN218;
    case 0x6A:
      v29 = this->m_ScheduleState.iTaskInterrupt;
      if ( v29 != 0 )
      {
        if ( v29 == 1 )
        {
          AI_NavGoal_t::AI_NavGoal_t(
            this: (AI_NavGoal_t *)v161,
            dest: &this->m_vInterruptSavePosition,
            activity: ACT_RUN,
            tolerance: -2.0,
            flags: 0,
            pTarget: AIN_DEF_TARGET_8);
          v30 = ((int (__thiscall *)(CAI_BaseNPC *, int, int))this->GetBestSound)(a1: this, a2: 1048351, a3: offset);
          if ( v30 != 0 )
          {
            *(float *)&v31 = (double)*(int *)(v30 + 8) * 0.5;
            goal.arrivalActivity = v31;
          }
          v32 = this->m_pNavigator;
          v33 = v32->SetGoal;
          offset = 0;
          if ( ((unsigned __int8 (__thiscall *)(CAI_Navigator *, float *))v33)(a1: v32, a2: v161) != 0 )
            this->m_flMoveWaitFinished = gpGlobals->curtime + pTask->flTaskData;
        }
      }
      else if ( CAI_BaseNPC::FindCoverFromBestSound(this, pCoverPos: &this->m_vInterruptSavePosition) )
      {
        CAI_Navigator::IgnoreStoppingPath(this: this->m_pNavigator);
        CAI_BaseNPC::LockBestSound(this);
        ++this->m_ScheduleState.iTaskInterrupt;
      }
      else
      {
        this->TaskFail(this, a2: 8);
      }
      goto $LN218;
    case 0x72:
      this->RunDieTask(this);
      goto $LN218;
    case 0x73:
      if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine) != nullptr
        && (v121 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine),
            CAI_ScriptedSequence::IsTimeToStart(this: v121)) )
      {
        CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
        v122 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine);
        CAI_ScriptedSequence::OnBeginSequence(this: v122);
        v123 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine)[1].__vftable == nullptr;
        LODWORD(vecDown.z) = 1;
        p_m_hCine = (CHandle<CBaseEntity> *)&this->m_hCine;
        if ( v123 )
          LODWORD(vecDown.y) = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hCine)[1].m_pfnThink;
        else
          LODWORD(vecDown.y) = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hCine)[1].__vftable;
        v125 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine);
        CAI_ScriptedSequence::StartSequence(
          this: v125,
          pTarget: this,
          iszSeq: LODWORD(vecDown.y),
          completeOnEmpty: SLOBYTE(vecDown.z));
        if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hCine) )
          CAI_BaseNPC::ClearSchedule(this, szReason: "Waiting for script, but lost script!");
        if ( this->m_flPlaybackRate.m_Value != 1.0 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
          }
          this->m_flPlaybackRate.m_Value = 1.0;
        }
      }
      else
      {
        if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hCine) )
        {
          DevMsg(a1: "Cine died!\n");
          goto LABEL_244;
        }
        if ( CAI_BaseNPC::IsRunningDynamicInteraction(this)
          && CHandle<CAI_BaseNPC>::operator!(this: &this->m_hInteractionPartner) )
        {
          CAI_BaseNPC::CineCleanup(this, a2: (int)v173);
        }
      }
      goto $LN218;
    case 0x75:
      CAI_BaseNPC::AutoMovement(this, pTarget: nullptr, pTraceResult: nullptr);
      if ( !this->m_bSequenceFinished )
        goto $LN218;
      v127 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine);
      v128 = CAI_ScriptedSequence::FinishedActionSequence(this: v127, pNPC: this);
      v129 = (CHandle<CBaseEntity> *)&this->m_hCine;
      if ( v128 )
      {
        if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v129) != nullptr )
        {
          v130 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine);
          CAI_ScriptedSequence::SequenceDone(this: v130, pNPC: this);
        }
        goto LABEL_244;
      }
      if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v129) != nullptr
        && BYTE1(CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine)[1].m_flAnimTime.m_Value) != 0 )
      {
        v131 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine);
        CAI_ScriptedSequence::SynchronizeSequence(this: v131, pNPC: this);
      }
      goto $LN218;
    case 0x76:
      if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hCine) )
        goto LABEL_213;
      if ( this->m_bSequenceFinished
        || (v132 = (CHandle<CBaseEntity> *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine),
            CHandle<CBaseEntity>::operator!=(this: v132 + 234, val: nullptr)) )
      {
        v133 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine);
        CAI_ScriptedSequence::PostIdleDone(this: v133, pNPC: this);
      }
      goto $LN218;
    case 0x77:
      if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hCine) )
      {
LABEL_213:
        DevMsg(a1: "Scripted sequence destroyed while in use\n");
        this->TaskFail(this, a2: 5);
        goto $LN218;
      }
      v134 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine);
      if ( CWorld::GetDisplayTitle(this: v134) )
        goto $LN218;
      v135 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine);
      CAI_ScriptedSequence::DelayStart(this: v135, bDelay: false);
      goto LABEL_244;
    case 0x7A:
      if ( !CAI_BaseNPC::IsInLockedScene(this) )
        CAI_BaseNPC::ClearSchedule(this, szReason: "Playing a scene, but not in a scene!");
      if ( CAI_Navigator::GetGoalType(this: this->m_pNavigator) != GOALTYPE_NONE )
        goto LABEL_244;
      goto $LN218;
    case 0x7D:
      if ( pTask->flTaskData == 1.0 )
      {
        v13 = this->RunTask;
        LODWORD(mins.x) = 130;
        mins.y = 0.0;
        v13(this, a2: (const Task_t *)&mins);
        if ( this->m_ScheduleState.fTaskStatus == TASKSTATUS_COMPLETE
          && ai_debug_nav.m_pParent != nullptr
          && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
        {
          v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v153, pszFormat: "[Nav] %s", "TASK_STOP_MOVING Complete\n");
          DevMsg(pAI: this, pszFormat: v14->m_szBuf);
        }
        goto $LN218;
      }
      if ( CAI_BaseNPC::GetNavType(this) == NAV_JUMP )
      {
        if ( (this->m_fFlags.m_Value & 1) != 0 )
        {
          if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
          {
            v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v155, pszFormat: "[Nav] %s", "Jump landed\n");
            DevMsg(pAI: this, pszFormat: v15->m_szBuf);
          }
          CAI_BaseNPC::SetNavType(this, navType: NAV_GROUND);
        }
        else
        {
          v16 = this->GetSmoothedVelocity(this, result: &v158);
          v17 = 0;
          *(float *)&v17 = fsqrt((float)((float)(v16->x * v16->x) + (float)(v16->y * v16->y)) + (float)(v16->z * v16->z));
          v170 = v17;
          if ( *(float *)&v17 > 0.01 )
            goto $LN218;
          if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
          {
            v18 = CFmtStrN<256>::CFmtStrN<256>(this: &v154, pszFormat: "[Nav] %s", "Jump stuck\n");
            DevMsg(pAI: this, pszFormat: v18->m_szBuf);
          }
          CAI_BaseNPC::SetNavType(this, navType: NAV_GROUND);
          this->TaskFail(this, a2: 26);
        }
      }
      if ( CAI_BaseNPC::GetNavType(this) == NAV_CLIMB )
        goto $LN218;
      if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
      {
        v19 = CFmtStrN<256>::CFmtStrN<256>(this: &v152, pszFormat: "[Nav] %s", "TASK_STOP_MOVING Complete\n");
        DevMsg(pAI: this, pszFormat: v19->m_szBuf);
      }
      StoppedActivity = CAI_BaseNPC::GetStoppedActivity(this);
      CAI_BaseNPC::SetIdealActivity(this, NewActivity: StoppedActivity);
      goto LABEL_244;
    case 0x82:
    case 0x83:
      if ( this->IsMovementFrozen(this) )
      {
        this->TaskFail(this, a2: 28);
      }
      else
      {
        v116 = pTask->flTaskData;
        if ( (v116 == 0.0 || (float)(gpGlobals->curtime - this->m_ScheduleState.timeCurTaskStarted) <= v116)
          && CAI_Navigator::GetGoalType(this: this->m_pNavigator) != GOALTYPE_NONE )
        {
          if ( CAI_Navigator::IsGoalActive(this: this->m_pNavigator) )
          {
            this->ValidateNavGoal(this);
          }
          else
          {
            v117 = CAI_BaseNPC::GetStoppedActivity(this);
            CAI_BaseNPC::SetIdealActivity(this, NewActivity: v117);
          }
        }
        else
        {
LABEL_177:
          CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
          CAI_Navigator::StopMoving(this: this->m_pNavigator, bImmediate: true);
        }
      }
      goto $LN218;
    case 0x84:
      if ( !CAI_BaseNPC::HasCondition(this, iCondition: 50) )
        goto LABEL_244;
      goto $LN218;
    case 0x86:
      if ( !this->IsActivityFinished(this) )
        goto $LN218;
      v140 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTargetEnt);
      v141 = ToBaseCombatWeapon(pEntity: v140);
      Owner = CBaseCombatWeapon::GetOwner(this: v141);
      v143 = this;
      if ( Owner != nullptr )
        goto LABEL_167;
      goto LABEL_245;
    case 0x87:
    case 0x8A:
      v115 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hTargetEnt);
      if ( v115 == nullptr )
      {
        this->TaskFail(this, a2: 3);
        goto $LN218;
      }
      if ( CBaseEntity::GetOwnerEntity(this: v115) != nullptr )
      {
LABEL_167:
        this->TaskFail(this, a2: 2);
        goto $LN218;
      }
LABEL_225:
      if ( CAI_Navigator::GetGoalType(this: this->m_pNavigator) == GOALTYPE_NONE )
        goto LABEL_244;
      goto $LN218;
    case 0x8C:
      m_Value = this->m_fFlags.m_Value;
      if ( (m_Value & 1) != 0 )
        goto LABEL_244;
      if ( (m_Value & 0x800) != 0 )
      {
        CBaseEntity::RemoveFlag(this, flagsToRemove: 2048);
        goto $LN218;
      }
      if ( !CAI_BaseNPC::IsWaitFinished(this) )
        goto $LN218;
      BoundingMaxs = CBaseEntity::ScriptGetBoundingMaxs(this);
      v165.x = BoundingMaxs->x - 0.1;
      v165.y = BoundingMaxs->y - 0.1;
      v165.z = BoundingMaxs->z - 0.2;
      BoundingMins = CBaseEntity::ScriptGetBoundingMins(this);
      vecStart.y = BoundingMins->x + 0.1;
      vecStart.z = BoundingMins->y + 0.1;
      pTarget = (CBaseEntity *)LODWORD(BoundingMins->z);
      v147 = CBaseEntity::GetAbsOrigin(this);
      maxs.x = v147->x;
      maxs.y = v147->y;
      maxs.z = v147->z + 0.1;
      v148 = CBaseEntity::GetAbsOrigin(this);
      m_nAITraceMask = this->m_nAITraceMask;
      *(_QWORD *)((char *)&v170 + 4) = *(_QWORD *)&v148->x;
      v150 = v148->z;
      HIDWORD(v170) = &vecStart.y;
      CAI_MoveProbe::TraceHull(
        this: this->m_pMoveProbe,
        vecStart: &maxs,
        vecEnd: (const Vector *)((char *)&v170 + 4),
        hullMin: COERCE_CONST_VECTOR_(v150 - 0.2),
        hullMax: &v165,
        mask: m_nAITraceMask,
        pResult: (CGameTrace *)v160);
      if ( goal.arrivalActivity != ACT_RESET )
      {
        CBaseEntity::SetGroundEntity(this, ground: (CBaseEntity *)goal.arrivalActivity);
        goto LABEL_244;
      }
      CAI_BaseNPC::SetWait(this, minWait: 4.0, maxWait: 0.0);
      goto $LN218;
    case 0x8E:
      if ( this->m_flFrozen.m_Value < 1.0 )
        this->Unfreeze(this);
      goto $LN218;
    case 0x93:
      if ( CAI_BaseNPC::IsWaitFinished(this) )
        goto LABEL_244;
      goto $LN218;
    default:
      v151 = this->TaskName(this, a2: pTask->iTask);
      DevMsg(a1: "No RunTask entry for %s\n", v151);
      goto LABEL_244;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CBF0
// Name: public: void CBaseAnimating::SetPlaybackRate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetPlaybackRate(CBaseAnimating *this, float rate)
{
  CNetworkVarBase<float,CBaseAnimating::NetworkVar_m_flPlaybackRate> *p_m_flPlaybackRate; // esi
  edict_t *m_pPev; // ecx

  p_m_flPlaybackRate = &this->m_flPlaybackRate;
  this->m_bSequenceFinished = false;
  if ( this->m_flPlaybackRate.m_Value != rate )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flPlaybackRate->m_Value = rate;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
      p_m_flPlaybackRate->m_Value = rate;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CC50
// Name: protected: bool CAI_BaseNPC::IsScheduleValid(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BaseNPC::IsScheduleValid(CAI_BaseNPC *this)
{
  CAI_Schedule *m_pSchedule; // eax
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // edi
  unsigned int v8; // ebx
  unsigned int v9; // ebx
  CAI_Schedule *v10; // edx
  int v11; // eax
  int v12; // eax
  const char *v13; // eax
  CBaseEntity *v14; // eax
  const char *DebugName; // eax
  CBitVec<256> testBits; // [esp+4h] [ebp-20h] BYREF

  m_pSchedule = this->m_pSchedule;
  if ( m_pSchedule == nullptr || m_pSchedule->m_iNumTasks == 0 )
    return 0;
  this->m_CustomInterruptConditions = m_pSchedule->m_InterruptMask;
  if ( this->m_NPCState != NPC_STATE_SCRIPT
    && this->m_flSceneTime <= gpGlobals->curtime
    && (this->m_CustomInterruptConditions.m_Ints[2] & 0x40) == 0 )
  {
    this->BuildScheduleTestBits(this);
  }
  CAI_BaseNPC::SetCustomInterruptCondition(this, nCondition: 67);
  v3 = this->m_CustomInterruptConditions.m_Ints[4] & this->m_Conditions.m_Ints[4];
  v4 = this->m_Conditions.m_Ints[0] & this->m_CustomInterruptConditions.m_Ints[0];
  v5 = this->m_CustomInterruptConditions.m_Ints[1] & this->m_Conditions.m_Ints[1];
  v6 = this->m_CustomInterruptConditions.m_Ints[2] & this->m_Conditions.m_Ints[2];
  v7 = this->m_CustomInterruptConditions.m_Ints[3] & this->m_Conditions.m_Ints[3];
  memset(&testBits.m_Ints[5], 0, 12);
  testBits.m_Ints[4] = v3;
  testBits.m_Ints[5] = this->m_CustomInterruptConditions.m_Ints[5] & this->m_Conditions.m_Ints[5];
  v8 = this->m_CustomInterruptConditions.m_Ints[6] & this->m_Conditions.m_Ints[6];
  *(_QWORD *)testBits.m_Ints = 0;
  testBits.m_Ints[6] = v8;
  v9 = this->m_CustomInterruptConditions.m_Ints[7] & this->m_Conditions.m_Ints[7];
  testBits.m_Ints[0] = v4;
  testBits.m_Ints[1] = v5;
  testBits.m_Ints[2] = v6;
  testBits.m_Ints[3] = v7;
  testBits.m_Ints[7] = v9;
  if ( v4 != 0
    || v5 != 0
    || v6 != 0
    || v7 != 0
    || testBits.m_Ints[4] != 0
    || testBits.m_Ints[5] != 0
    || testBits.m_Ints[6] != 0
    || v9 != 0 )
  {
    if ( g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue != 0 )
    {
      v10 = this->m_pSchedule;
      this->m_failedSchedule = nullptr;
      this->m_interuptSchedule = v10;
      v11 = 0;
      while ( ((1 << (v11 & 0x1F)) & testBits.m_Ints[v11 >> 5]) == 0 )
      {
        if ( ++v11 >= 256 )
          goto LABEL_28;
      }
      if ( v11 == -1 )
        v12 = -1;
      else
        v12 = v11 + 1000000000;
      v13 = this->ConditionName(this, a2: v12);
      this->m_interruptText = v13;
      if ( v13 == nullptr )
        this->m_interruptText = "(UNKNOWN CONDITION)";
      if ( (this->m_debugOverlays & 0x8000000) != 0 )
        DevMsg(pAI: this, flags: 1, pszFormat: "      Break condition -> %s\n", this->m_interruptText);
LABEL_28:
      if ( CAI_BaseNPC::HasCondition(this, iCondition: 26) && (this->m_debugOverlays & 0x8000000) != 0 )
      {
        if ( this->GetEnemy_2(this) != nullptr )
        {
          v14 = this->GetEnemy_2(this);
          DebugName = CBaseEntity::GetDebugName(this: v14);
        }
        else
        {
          DebugName = "<NULL>";
        }
        DevMsg(pAI: this, flags: 1, pszFormat: "      New enemy: %s\n", DebugName);
      }
    }
  }
  else if ( !CAI_BaseNPC::HasCondition(this, iCondition: 36) && !CAI_BaseNPC::HasCondition(this, iCondition: 35) )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003CEE0
// Name: private: void CAI_BaseNPC::MaintainSchedule(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::MaintainSchedule(CAI_BaseNPC *this)
{
  int v2; // eax
  CAI_Schedule *m_pSchedule; // ecx
  int v4; // eax
  void (__thiscall *OnScheduleChange)(CAI_BaseNPC *); // edx
  NPC_STATE v6; // eax
  CAI_Schedule *v7; // edi
  CAI_Schedule *v8; // eax
  const char *m_pName; // edx
  const char *pszValue; // eax
  CFastTimer *p_selectSchedule; // edi
  CFastTimer *v12; // edi
  CAI_Schedule *v13; // ebx
  CAI_Schedule *v14; // eax
  int m_iScheduleID; // edi
  int v16; // eax
  const Task_t *Task; // ebx
  const char *v18; // edi
  CGlobalEvent *TempEvent; // eax
  void (__thiscall *StartTask)(CAI_BaseNPC *, const Task_t *); // eax
  TaskStatus_e fTaskStatus; // eax
  const Task_t *v22; // ebx
  const char *v23; // eax
  int v24; // edi
  int v25; // eax
  int v26; // eax
  int i; // edi
  edict_t *m_pPev; // ecx
  CAI_Schedule *v29; // [esp-4h] [ebp-40h]
  unsigned __int64 v30; // [esp+Ch] [ebp-30h] BYREF
  unsigned __int64 v31; // [esp+14h] [ebp-28h] BYREF
  unsigned __int64 v32; // [esp+1Ch] [ebp-20h] BYREF
  CFastTimer *p_startTimer; // [esp+24h] [ebp-18h]
  CFastTimer *p_runTimer; // [esp+28h] [ebp-14h]
  int taskTime; // [esp+2Ch] [ebp-10h]
  TaskTimings *v36; // [esp+30h] [ebp-Ch]
  int curTiming; // [esp+34h] [ebp-8h]
  bool bDebugTaskNames; // [esp+3Ah] [ebp-2h]
  bool bStopProcessing; // [esp+3Bh] [ebp-1h]

  taskTime = (int)&g_AIMaintainScheduleTimer;
  g_AIMaintainScheduleTimer.m_Duration.m_Int64 = __rdtsc();
  bDebugTaskNames = developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0;
  memset(dst: (unsigned __int8 *)g_AITaskTimings, value: 0, count: sizeof(g_AITaskTimings));
  g_nAITasksRun = 0;
  v2 = _Plat_MSTime();
  this->m_afMemory &= ~8u;
  taskTime = v2;
  bStopProcessing = false;
  v36 = g_AITaskTimings;
  while ( !bStopProcessing )
  {
    m_pSchedule = this->m_pSchedule;
    if ( m_pSchedule != nullptr && this->m_ScheduleState.fTaskStatus == TASKSTATUS_COMPLETE )
    {
      v4 = ++this->m_ScheduleState.iCurTask;
      this->m_ScheduleState.fTaskStatus = TASKSTATUS_NEW;
      this->m_ScheduleState.iTaskInterrupt = 0;
      *(_WORD *)&this->m_ScheduleState.bTaskRanAutomovement = 0;
      if ( v4 == m_pSchedule->m_iNumTasks )
      {
        this->m_failedSchedule = nullptr;
        this->m_interuptSchedule = nullptr;
        CAI_BaseNPC::SetCondition(this, iCondition: 36);
      }
      if ( CAI_BaseNPC::HasCondition(this, iCondition: 36) )
      {
        this->m_Conditions.m_Ints[0] = this->m_ConditionsPreIgnore.m_Ints[0];
        this->m_Conditions.m_Ints[1] = this->m_ConditionsPreIgnore.m_Ints[1];
        this->m_Conditions.m_Ints[2] = this->m_ConditionsPreIgnore.m_Ints[2];
        this->m_Conditions.m_Ints[3] = this->m_ConditionsPreIgnore.m_Ints[3];
        this->m_Conditions.m_Ints[4] = this->m_ConditionsPreIgnore.m_Ints[4];
        this->m_Conditions.m_Ints[5] = this->m_ConditionsPreIgnore.m_Ints[5];
        this->m_Conditions.m_Ints[6] = this->m_ConditionsPreIgnore.m_Ints[6];
        this->m_Conditions.m_Ints[7] = this->m_ConditionsPreIgnore.m_Ints[7];
        CAI_BaseNPC::SetCondition(this, iCondition: 36);
        if ( this != (CAI_BaseNPC *)-2484 )
        {
          this->m_InverseIgnoreConditions.m_Ints[0] = -1;
          this->m_InverseIgnoreConditions.m_Ints[1] = -1;
          this->m_InverseIgnoreConditions.m_Ints[2] = -1;
          this->m_InverseIgnoreConditions.m_Ints[3] = -1;
          this->m_InverseIgnoreConditions.m_Ints[4] = -1;
          this->m_InverseIgnoreConditions.m_Ints[5] = -1;
          this->m_InverseIgnoreConditions.m_Ints[6] = -1;
          this->m_InverseIgnoreConditions.m_Ints[7] = -1;
        }
      }
      if ( (CAI_BaseNPC::m_nDebugBits & 2) != 0 )
      {
        ++this->m_nDebugCurIndex;
        p_startTimer = (CFastTimer *)&v30;
        v30 = __rdtsc();
LABEL_94:
        g_AIMaintainScheduleTimer.m_Duration.m_Int64 = v30 - g_AIMaintainScheduleTimer.m_Duration.m_Int64;
        return;
      }
    }
    curTiming = g_nAITasksRun++;
    if ( CAI_BaseNPC::IsScheduleValid(this) == 0 || this->m_NPCState != this->m_IdealNPCState )
    {
      OnScheduleChange = this->OnScheduleChange;
      this->m_ScheduleState.bScheduleWasInterrupted = true;
      OnScheduleChange(this);
      if ( !CAI_BaseNPC::HasCondition(this, iCondition: 67)
        && (!this->m_bConditionsGathered || this->m_bSkippedChooseEnemy) )
      {
        this->GatherConditions(this);
      }
      if ( CAI_BaseNPC::ShouldSelectIdealState(this) )
      {
        v6 = this->SelectIdealState(this);
        if ( v6 != this->m_IdealNPCState )
          this->m_IdealNPCState = v6;
      }
      if ( CAI_BaseNPC::HasCondition(this, iCondition: 35) && this->m_NPCState == this->m_IdealNPCState )
      {
        if ( (this->m_debugOverlays & 0x8000000) != 0 )
          DevMsg(pAI: this, flags: 1, pszFormat: "      (failed)\n");
        v7 = this->GetFailSchedule(this);
        v8 = this->m_pSchedule;
        this->m_IdealSchedule = v7->m_iScheduleID;
        if ( v8 != nullptr )
          m_pName = v8->m_pName;
        else
          m_pName = "GetCurSchedule() == NULL";
        pszValue = this->m_iName.m_Value.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        _DevWarning(a1: 2, a2: "(%s) Schedule (%s) Failed at %d!\n", pszValue, m_pName, this->m_ScheduleState.iCurTask);
        CAI_BaseNPC::SetSchedule(this, pNewSchedule: v7);
      }
      else
      {
        CAI_BaseNPC::SetState(this, State: this->m_IdealNPCState);
        p_selectSchedule = &g_AITaskTimings[curTiming].selectSchedule;
        p_runTimer = p_selectSchedule;
        p_selectSchedule->m_Duration.m_Int64 = __rdtsc();
        v29 = this->GetNewSchedule(this);
        p_runTimer = (CFastTimer *)&v32;
        v32 = __rdtsc();
        p_selectSchedule->m_Duration.m_Int64 = v32 - p_selectSchedule->m_Duration.m_Int64;
        CAI_BaseNPC::SetSchedule(this, pNewSchedule: v29);
      }
    }
    if ( this->m_pSchedule == nullptr )
    {
      v12 = &g_AITaskTimings[curTiming].selectSchedule;
      p_runTimer = v12;
      v12->m_Duration.m_Int64 = __rdtsc();
      v13 = this->GetNewSchedule(this);
      p_runTimer = (CFastTimer *)&v31;
      v31 = __rdtsc();
      v12->m_Duration.m_Int64 = v31 - v12->m_Duration.m_Int64;
      if ( v13 != nullptr )
        CAI_BaseNPC::SetSchedule(this, pNewSchedule: v13);
    }
    v14 = this->m_pSchedule;
    if ( v14 == nullptr || v14->m_iNumTasks == 0 )
    {
      DevMsg(a1: "ERROR: Missing or invalid schedule!\n");
      this->SetActivity(this, a2: ACT_IDLE);
      p_startTimer = (CFastTimer *)&v30;
      v30 = __rdtsc();
      goto LABEL_94;
    }
    if ( this->m_ScheduleState.fTaskStatus == TASKSTATUS_NEW )
    {
      if ( this->m_ScheduleState.iCurTask == 0 )
      {
        m_iScheduleID = v14->m_iScheduleID;
        v16 = this->GetLocalScheduleId(this, a2: v14->m_iScheduleID);
        if ( v16 == -1 )
          v16 = m_iScheduleID;
        this->OnStartSchedule(this, a2: v16);
      }
      p_startTimer = &g_AITaskTimings[curTiming].startTimer;
      p_runTimer = p_startTimer;
      p_startTimer->m_Duration.m_Int64 = __rdtsc();
      Task = CAI_BaseNPC::GetTask(this);
      if ( bDebugTaskNames )
        v18 = this->TaskName(this, a2: Task->iTask);
      else
        v18 = "ai_task";
      v36->pszTask = v18;
      if ( (this->m_debugOverlays & 0x8000000) != 0 )
        DevMsg(pAI: this, flags: 1, pszFormat: "  Task: %s\n", v18);
      if ( this->m_pScheduleEvent != nullptr )
      {
        TempEvent = CGlobalEventLog::CreateTempEvent(
                      this: &GlobalEventLog,
                      pszName: "New Task",
                      pParent: this->m_pScheduleEvent);
        CGlobalEventLog::AddKeyValue(
          this: &GlobalEventLog,
          pEvent: TempEvent,
          bVarying: false,
          pszKey: "Task",
          pszValueFormat: v18);
      }
      StartTask = this->StartTask;
      this->m_ScheduleState.fTaskStatus = TASKSTATUS_RUN_MOVE_AND_TASK;
      this->m_ScheduleState.taskFailureCode = 0;
      this->m_ScheduleState.timeCurTaskStarted = gpGlobals->curtime;
      StartTask(this, a2: Task);
      if ( CAI_BaseNPC::TaskIsRunning(this) && !CAI_BaseNPC::HasCondition(this, iCondition: 35) )
        CAI_BaseNPC::StartTaskOverlay(this);
      p_runTimer = (CFastTimer *)&v30;
      v30 = __rdtsc();
      p_startTimer->m_Duration.m_Int64 = v30 - p_startTimer->m_Duration.m_Int64;
    }
    CAI_BaseNPC::MaintainActivity(this);
    fTaskStatus = this->m_ScheduleState.fTaskStatus;
    if ( fTaskStatus == TASKSTATUS_COMPLETE || fTaskStatus == TASKSTATUS_NEW )
      goto LABEL_82;
    if ( !CAI_BaseNPC::TaskIsRunning(this) || CAI_BaseNPC::HasCondition(this, iCondition: 35) )
      goto LABEL_83;
    v22 = CAI_BaseNPC::GetTask(this);
    v23 = bDebugTaskNames ? this->TaskName(this, a2: v22->iTask) : "ai_task";
    v36->pszTask = v23;
    p_runTimer = &g_AITaskTimings[curTiming].runTimer;
    p_startTimer = p_runTimer;
    p_runTimer->m_Duration.m_Int64 = __rdtsc();
    v24 = 0;
    do
    {
      this->RunTask(this, a2: v22);
      if ( this->m_ScheduleState.iTaskInterrupt == 0
        || this->m_ScheduleState.fTaskStatus == TASKSTATUS_COMPLETE
        || CAI_BaseNPC::HasCondition(this, iCondition: 35) )
      {
        break;
      }
      if ( ai_use_think_optimizations.m_pParent != nullptr
        && ai_use_think_optimizations.m_pParent->m_Value.m_nValue != 0
        && ai_use_efficiency.m_pParent != nullptr
        && ai_use_efficiency.m_pParent->m_Value.m_nValue != 0 )
      {
        v25 = _Plat_MSTime();
        if ( ShouldStopProcessingTasks(pNPC: this, taskTime: v25 - taskTime, timeLimit: 8) )
        {
          bStopProcessing = true;
          break;
        }
      }
    }
    while ( ++v24 < 8 );
    if ( CAI_BaseNPC::TaskIsRunning(this) && !CAI_BaseNPC::HasCondition(this, iCondition: 35) )
    {
      if ( this->IsCurTaskContinuousMove(this) )
        this->m_afMemory |= 0x40000u;
      this->RunTaskOverlay(this);
    }
    CFastTimer::End(this: p_runTimer);
    if ( this->m_ScheduleState.fTaskStatus != TASKSTATUS_COMPLETE )
    {
LABEL_83:
      bStopProcessing = true;
      goto LABEL_84;
    }
    if ( !bStopProcessing )
    {
LABEL_82:
      v26 = _Plat_MSTime();
      if ( ShouldStopProcessingTasks(pNPC: this, taskTime: v26 - taskTime, timeLimit: 8) )
        goto LABEL_83;
    }
LABEL_84:
    if ( (int)++v36 >= (int)&`CAI_Network::GetNode'::`8'::warningCount )
      break;
  }
  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
    CAI_BehaviorBase::MaintainChannelSchedules(this: this->m_Behaviors.m_Memory.m_pMemory[i]);
  CAI_BaseNPC::MaintainActivity(this);
  if ( (CAI_BaseNPC::m_nDebugBits & 2) != 0
    && !CAI_Navigator::IsGoalActive(this: this->m_pNavigator)
    && this->m_nDebugCurIndex >= CAI_BaseNPC::m_nDebugPauseIndex
    && this->m_flPlaybackRate.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flPlaybackRate.m_Value = 0.0;
  }
  g_AIMaintainScheduleTimer.m_Duration.m_Int64 = __rdtsc() - g_AIMaintainScheduleTimer.m_Duration.m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x1003D690
// Name: public: virtual void CAI_BaseNPC::StartTask(struct Task_t const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CAI_BaseNPC::StartTask(
        CAI_BaseNPC *this@<ecx>,
        float a2@<ebp>,
        float a3@<edi>,
        Vector *a4@<esi>,
        const Task_t *pTask)
{
  CAI_BaseNPC *v5; // esi
  CAI_Hint *Hint; // eax
  CAI_Hint *v7; // eax
  bool v8; // al
  CSound *v9; // eax
  CHandle<CBaseEntity> *p_m_hOwner; // edi
  CBaseEntity *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  CSound *v14; // eax
  const Vector *SoundReactOrigin; // eax
  bool v16; // zf
  CAI_BaseNPC_vtbl *v17; // eax
  CBaseEntity *v18; // eax
  const Vector *v19; // eax
  double y; // st7
  ConVar *m_pParent; // ecx
  CFmtStrN<256> *v22; // eax
  CFmtStrN<256> *v23; // eax
  int m_poseMove_Yaw; // eax
  ConVar *v25; // eax
  CFmtStrN<256> *v26; // eax
  CFmtStrN<256> *v27; // eax
  Activity StoppedActivity; // eax
  int v29; // eax
  CAI_Hint *v30; // eax
  CAI_BaseNPC *v31; // ecx
  const char *v32; // eax
  int v33; // edi
  CAI_Hint *v34; // eax
  Activity v35; // eax
  const char *v36; // eax
  int v37; // eax
  CAI_Navigator_vtbl *v38; // edi
  AI_NavGoal_t *v39; // eax
  char v40; // al
  CAI_BaseNPC_vtbl *v41; // edx
  double v42; // xmm0_8
  float v43; // xmm1_4
  float v44; // xmm0_4
  CAI_BaseNPC_vtbl *v45; // eax
  const Vector *v46; // eax
  CAI_Motor *v47; // edi
  CAI_Hint *v48; // eax
  CAI_Motor *v49; // edi
  bool v50; // al
  CAI_Motor *v51; // edi
  CBaseEntity *v52; // eax
  const Vector *v53; // eax
  const Vector *v54; // eax
  bool (__thiscall *FInAimCone)(CBaseCombatCharacter *, const Vector *); // edx
  double v56; // st7
  CAI_Motor *v57; // ecx
  CAI_Motor *m_pMotor; // edi
  const Vector *v59; // eax
  long double v60; // st7
  CBaseEntity *GoalTarget; // eax
  const Vector *AbsOrigin; // eax
  float v63; // xmm1_4
  float v64; // xmm0_4
  __int128 v65; // xmm1
  char HasCondition; // al
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v68; // eax
  const Vector *v69; // eax
  bool v70; // cc
  void (__thiscall *v71)(CAI_BaseNPC *, const Task_t *); // edx
  CBaseEntity *v72; // edi
  const Vector *v73; // eax
  CBaseEntity *v74; // eax
  CBaseEntity *v75; // eax
  CAI_BaseNPC_vtbl *v76; // edi
  CBaseEntity *v77; // eax
  CBaseEntity *v78; // eax
  int (__thiscall *CapabilitiesGet)(CAI_BaseNPC *); // edx
  float v80; // xmm0_4
  CBaseEntity *v81; // eax
  double v82; // st7
  CAI_Navigator *v83; // edi
  CBaseEntity *v84; // eax
  const Vector *v85; // eax
  float m_fMaxRange1; // xmm0_4
  CAI_BaseNPC_vtbl *v87; // eax
  CBaseEntity *v88; // eax
  const Vector *v89; // eax
  CAI_BaseNPC_vtbl *v90; // edx
  int v91; // eax
  float *v92; // eax
  __int128 v93; // xmm1
  FlankType_t v94; // eax
  float v95; // xmm0_4
  CBaseEntity *v96; // eax
  CBaseEntity *(__thiscall *GetEnemy_2)(CBaseEntity *); // edx
  const CBaseEntity *v98; // eax
  float *v99; // eax
  double z; // st7
  CBaseEntity *v101; // eax
  unsigned int m_Index; // eax
  CBaseEntity *v103; // eax
  int v104; // eax
  int v105; // eax
  CHandle<CBaseEntity> *v106; // eax
  CBaseEntity *v107; // edi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  const Vector *v109; // eax
  float v110; // xmm0_4
  const Vector *v111; // eax
  CBaseEntity *v112; // eax
  char v113; // al
  float *p_m_fMaxRange1; // edi
  float m_fMaxRange2; // xmm0_4
  float *p_m_fMinRange1; // edi
  CBaseEntity *v117; // eax
  Vector *p_m_vecStoredPathGoal; // eax
  CAI_TacticalServices *m_pTacticalServices; // ecx
  CAI_Navigator *m_pNavigator; // ecx
  CAI_Navigator *v121; // ecx
  CAI_BaseNPC_vtbl *v122; // edi
  int v123; // eax
  CAI_BaseNPC_vtbl *v124; // eax
  CBaseEntity *v125; // eax
  int v126; // eax
  float v127; // ecx
  CBaseEntity *v128; // edi
  int v129; // eax
  CAI_Navigator *v130; // ecx
  float *v131; // edi
  float v132; // xmm0_4
  float *v133; // edi
  float m_fMinRange2; // xmm1_4
  float m_flDistTooFar; // xmm2_4
  int *v136; // esi
  int v137; // edi
  AI_NavGoal_t *v138; // eax
  CBaseEntity *v139; // eax
  const Vector *v140; // eax
  int v141; // eax
  CAI_Network *m_pAINetwork; // ecx
  CAI_Node *v143; // eax
  CBaseEntity *v144; // eax
  const Vector *v145; // eax
  float v146; // xmm0_4
  CBaseEntity *v147; // eax
  CBaseCombatWeapon *v148; // eax
  CBaseEntity *v149; // eax
  const Vector *v150; // eax
  __int128 v151; // xmm0
  CBaseEntity *v152; // eax
  CBaseEntity *v153; // eax
  CAI_Navigator *v154; // ecx
  bool v155; // al
  CBaseEntity *v156; // eax
  const Vector *v157; // eax
  CBaseEntity *v158; // eax
  CAI_Navigator *v159; // ecx
  CBaseEntity *v160; // eax
  CBaseCombatWeapon *v161; // eax
  CAI_Navigator *v162; // edi
  CWorld *GroundEntity; // eax
  void (__thiscall *v164)(CAI_BaseNPC *, const Task_t *); // edx
  CBaseEntity *v165; // eax
  const Vector *v166; // eax
  CBaseEntity *v167; // eax
  CAI_Navigator *v168; // ecx
  CAI_Hint *VehicleEntity; // eax
  AI_NavGoal_t *v170; // eax
  CAI_Navigator *v171; // edi
  CAI_Hint *v172; // eax
  const Vector *Direction; // eax
  const char *pszValue; // eax
  int ActivityID; // edi
  CAI_Hint *v176; // eax
  int nHintType; // eax
  Activity v178; // eax
  const char *v179; // eax
  int v180; // eax
  bool v181; // al
  CSound *v182; // eax
  const Vector *v183; // eax
  CAI_Navigator *v184; // ecx
  bool (__thiscall *SetGoal)(CAI_Navigator *, const AI_NavGoal_t *, unsigned int); // edx
  CSound *v186; // eax
  const Vector *v187; // eax
  CAI_Navigator *v188; // ecx
  bool (__thiscall *v189)(CAI_Navigator *, const AI_NavGoal_t *, unsigned int); // edx
  CSound *v190; // eax
  const Vector *SoundOrigin; // eax
  float v192; // xmm0_4
  void (__thiscall *StartTask)(CAI_BaseNPC *, const Task_t *); // edx
  Activity v194; // eax
  CAI_Navigator *v195; // ecx
  unsigned __int8 m_Value; // al
  const Vector *GoalPos; // eax
  CAI_Navigator *v198; // ecx
  __int128 v199; // xmm0
  const Vector *CurWaypointPos; // eax
  float v201; // xmm1_4
  CAI_Navigator *v202; // ecx
  bool v203; // al
  bool v204; // al
  bool IsGoalActive; // al
  Activity v206; // eax
  Activity (__thiscall *GetFlinchActivity)(CAI_BaseNPC *, bool, bool); // eax
  Activity v208; // eax
  Activity v209; // eax
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_lifeState> *p_m_lifeState; // esi
  CAI_Expresser *(__thiscall *GetExpresser)(CAI_BaseNPC *); // edx
  CAI_Expresser *v212; // eax
  int v213; // eax
  CBaseEntity *v214; // eax
  CHandle<CBaseEntity> *p_m_hCine; // ecx
  const char *m_pfnThink; // edi
  CBaseEntity *v217; // eax
  CHandle<CBaseEntity> *v218; // ecx
  int v219; // eax
  CAI_ScriptedSequence *v220; // eax
  CAI_ScriptedSequence *v221; // eax
  CAI_ScriptedSequence *v222; // eax
  const char *m_pfnMoveDone; // eax
  Activity m_IdealActivity; // eax
  CBaseEntity *v225; // eax
  const Vector *v226; // eax
  NPC_STATE flTaskData; // eax
  const CBaseEntity *Usable; // eax
  CBaseEntity *v229; // eax
  CAI_BaseNPC_vtbl *v230; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseEntity *Target; // eax
  CBaseCombatWeapon *v233; // eax
  bool v234; // al
  CBaseEntity *v235; // eax
  CBaseCombatWeapon *v236; // eax
  const char *v237; // eax
  CBaseCombatWeapon *v238; // eax
  bool v239; // al
  CBaseEdict *v240; // ecx
  int (*v241)(void); // eax
  CBaseEntity *v242; // eax
  const char *v243; // eax
  const Vector *tolerance; // [esp+10h] [ebp-778h]
  int flMaxDist; // [esp+14h] [ebp-774h]
  void (__thiscall *flMaxDista)(CBaseEntity *); // [esp+14h] [ebp-774h]
  float flDeltaYawa; // [esp+18h] [ebp-770h]
  int flDeltaYaw; // [esp+18h] [ebp-770h]
  CBaseEntity *flDeltaYawb; // [esp+18h] [ebp-770h]
  CBaseEntity *flDeltaYawc; // [esp+18h] [ebp-770h]
  Vector *pResulta; // [esp+1Ch] [ebp-76Ch]
  CFmtStrN<256> v254; // [esp+2Ch] [ebp-75Ch] BYREF
  CFmtStrN<256> v255; // [esp+138h] [ebp-650h] BYREF
  CFmtStrN<256> v256; // [esp+244h] [ebp-544h] BYREF
  CFmtStrN<256> v257; // [esp+350h] [ebp-438h] BYREF
  AI_NavGoal_t v258; // [esp+45Ch] [ebp-32Ch] BYREF
  AI_NavGoal_t v259; // [esp+48Ch] [ebp-2FCh] BYREF
  AI_NavGoal_t v260; // [esp+4BCh] [ebp-2CCh] BYREF
  AI_NavGoal_t v261; // [esp+4ECh] [ebp-29Ch] BYREF
  AI_NavGoal_t v262; // [esp+51Ch] [ebp-26Ch] BYREF
  AI_NavGoal_t v263; // [esp+54Ch] [ebp-23Ch] BYREF
  AI_NavGoal_t v264; // [esp+57Ch] [ebp-20Ch] BYREF
  AI_NavGoal_t v265; // [esp+5ACh] [ebp-1DCh] BYREF
  AI_NavGoal_t v266; // [esp+5DCh] [ebp-1ACh] BYREF
  AI_NavGoal_t v267; // [esp+60Ch] [ebp-17Ch] BYREF
  _BYTE v268[44]; // [esp+63Ch] [ebp-14Ch] BYREF
  _BYTE v269[12]; // [esp+668h] [ebp-120h] BYREF
  AI_NavGoal_t coverGoal; // [esp+674h] [ebp-114h] BYREF
  int v271; // [esp+6ACh] [ebp-DCh] BYREF
  Vector v272; // [esp+6B8h] [ebp-D0h] BYREF
  int v273; // [esp+6C4h] [ebp-C4h] BYREF
  int v274; // [esp+6D0h] [ebp-B8h] BYREF
  int v275; // [esp+6DCh] [ebp-ACh] BYREF
  Vector v276; // [esp+6E8h] [ebp-A0h] BYREF
  CHandle<CBaseEntity> v277; // [esp+6F4h] [ebp-94h] BYREF
  Vector v278; // [esp+6F8h] [ebp-90h] BYREF
  int v279; // [esp+704h] [ebp-84h] BYREF
  __int64 v280; // [esp+708h] [ebp-80h] BYREF
  AI_NavGoal_t goal; // [esp+710h] [ebp-78h] BYREF
  Vector vecEnemyEye; // [esp+740h] [ebp-48h] BYREF
  __int128 vecNodePos; // [esp+74Ch] [ebp-3Ch] OVERLAPPED BYREF
  __int128 right; // [esp+75Ch] [ebp-2Ch] OVERLAPPED BYREF
  float flDistZ; // [esp+76Ch] [ebp-1Ch]
  Vector2D vec2RightSide; // [esp+770h] [ebp-18h] BYREF
  float flRange; // [esp+778h] [ebp-10h]
  float flMaxRange; // [esp+77Ch] [ebp-Ch] BYREF
  void *v289; // [esp+780h] [ebp-8h]
  void *retaddr; // [esp+788h] [ebp+0h]

  flMaxRange = a2;
  v289 = retaddr;
  flDistZ = *(float *)&pTask->iTask;
  v5 = this;
  switch ( LODWORD(flDistZ) )
  {
    case 1:
      this->m_Activity = ACT_RESET;
      goto $LN375;
    case 2:
    case 4:
    case 0x42:
      CAI_BaseNPC::SetWait(this, minWait: pTask->flTaskData, maxWait: 0.0);
      return;
    case 3:
      goto $LN375;
    case 5:
    case 0x7B:
      CAI_BaseNPC::SetWait(this, minWait: 0.0, maxWait: pTask->flTaskData);
      return;
    case 6:
    case 0x6A:
    case 0x7A:
    case 0x7C:
      return;
    case 7:
      flTaskData = (int)pTask->flTaskData;
      if ( flTaskData == this->m_IdealNPCState )
        goto LABEL_113;
      this->m_IdealNPCState = flTaskData;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 8:
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: "!player",
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName != nullptr )
      {
        CAI_BaseNPC::SetTarget(this: v5, pTarget: EntityByName);
        CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      }
      else
      {
        v5->TaskFail(this: v5, a2: 21);
      }
      return;
    case 9:
    case 0xA:
    case 0xB:
      CAI_BaseNPC::StartScriptMoveToTargetTask(this, a2: (int)&flMaxRange, task: SLODWORD(flDistZ));
      return;
    case 0xC:
    case 0xD:
      if ( LODWORD(flDistZ) == 13 && (GoalTarget = CAI_Navigator::GetGoalTarget(this: this->m_pNavigator)) != nullptr
        || (GoalTarget = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt)) != nullptr )
      {
        AbsOrigin = CBaseEntity::GetAbsOrigin(this: GoalTarget);
        v63 = AbsOrigin->y - v5->m_vecOrigin.m_Value.y;
        v64 = (float)((float)((float)(AbsOrigin->x - v5->m_vecOrigin.m_Value.x)
                            * (float)(AbsOrigin->x - v5->m_vecOrigin.m_Value.x))
                    + (float)(v63 * v63))
            + (float)((float)(AbsOrigin->z - v5->m_vecOrigin.m_Value.z)
                    * (float)(AbsOrigin->z - v5->m_vecOrigin.m_Value.z));
        v65 = 0;
        *(float *)&v65 = fsqrt(v64);
        vecNodePos = v65;
        if ( *(float *)&v65 < 1.0 )
          CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      }
      else
      {
        v5->TaskFail(this: v5, a2: 1);
      }
      if ( CAI_Navigator::GetGoalType(this: v5->m_pNavigator) == GOALTYPE_NONE )
        goto LABEL_122;
      goto LABEL_333;
    case 0xE:
      this->m_bCrouchDesired = false;
      return;
    case 0xF:
      v190 = this->GetBestSound(this, a2: 1048351);
      if ( v190 == nullptr )
        goto LABEL_316;
      HIDWORD(right) = v5->m_pMotor;
      SoundOrigin = CSound::GetSoundOrigin(this: v190);
      CAI_Motor::SetIdealYawToTarget(this: (CAI_Motor *)HIDWORD(right), target: SoundOrigin, noise: 0.0, offset: 0.0);
      v192 = pTask->flTaskData;
      StartTask = v5->StartTask;
      DWORD2(right) = 14;
      *((float *)&right + 3) = v192;
      StartTask(this: v5, a2: (const Task_t *)&right + 1);
      CAI_BaseNPC::LockBestSound(this: v5);
      return;
    case 0x10:
      switch ( (int)pTask->flTaskData )
      {
        case 0:
          v16 = this->GetEnemy_2(this) == nullptr;
          v17 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          if ( v16 )
            goto LABEL_252;
          v96 = v17->GetEnemy_2(this: v5);
          v5->m_vecStoredPathGoal = *CBaseEntity::GetAbsOrigin(this: v96);
          GetEnemy_2 = v5->GetEnemy_2;
          v5->m_nStoredPathType = GOALTYPE_ENEMY;
          v5->m_fStoredPathFlags = 0;
          v98 = GetEnemy_2(this: v5);
          CHandle<CBaseEntity>::operator=(this: &v5->m_hStoredPathTarget, val: v98);
          goto LABEL_210;
        case 1:
          if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTargetEnt, val: nullptr) )
            goto LABEL_206;
          v101 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
          v5->m_vecStoredPathGoal = *CBaseEntity::GetAbsOrigin(this: v101);
          m_Index = v5->m_hTargetEnt.m_Index;
          v5->m_nStoredPathType = GOALTYPE_TARGETENT;
          v5->m_fStoredPathFlags = 0;
          v5->m_hStoredPathTarget.m_Index = m_Index;
          goto LABEL_210;
        case 2:
          v16 = this->GetEnemy_2(this) == nullptr;
          v17 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          if ( v16 )
            goto LABEL_252;
          v99 = (float *)v17->GetEnemyLKP(this: v5);
          v5->m_vecStoredPathGoal.x = *v99;
          v5->m_vecStoredPathGoal.y = v99[1];
          z = v99[2];
          goto LABEL_209;
        case 3:
          this->m_vecStoredPathGoal.x = this->m_vSavePosition.x;
          this->m_vecStoredPathGoal.y = this->m_vSavePosition.y;
          z = this->m_vSavePosition.z;
LABEL_209:
          v5->m_vecStoredPathGoal.z = z;
          v5->m_nStoredPathType = GOALTYPE_LOCATION;
          v5->m_fStoredPathFlags = 0;
          v5->m_hStoredPathTarget.m_Index = -1;
LABEL_210:
          CAI_Navigator::SetMovementActivity(this: v5->m_pNavigator, activity: ACT_RUN);
          break;
        default:
          goto LABEL_369;
      }
      goto LABEL_369;
    case 0x11:
      v103 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hStoredPathTarget);
      AI_NavGoal_t::AI_NavGoal_t(
        this: (AI_NavGoal_t *)&v279,
        type: v5->m_nStoredPathType,
        activity: ACT_INVALID,
        tolerance: -2.0,
        flags: 0,
        pTarget: v103);
      v104 = (int)pTask->flTaskData;
      LODWORD(flRange) = &pTask->flTaskData;
      if ( v104 != 0 )
      {
        v105 = v104 - 1;
        if ( v105 != 0 )
        {
          if ( v105 != 1 )
            goto LABEL_148;
          if ( CHandle<CBaseEntity>::operator==(this: &v5->m_hStoredPathTarget, val: nullptr) )
          {
            v106 = CHandle<CBaseEntity>::CHandle<CBaseEntity>(this: &v277, pObj: v5);
          }
          else
          {
            HIDWORD(right) = v5->m_hStoredPathTarget.m_Index;
            v106 = (CHandle<CBaseEntity> *)&right + 3;
          }
          v107 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v106);
          EyePosition = v107->EyePosition;
          HIDWORD(right) = v5->m_pTacticalServices;
          v109 = (const Vector *)((int (__thiscall *)(CBaseEntity *, int *, _DWORD, char *))EyePosition)(
                                   a1: v107,
                                   a2: &v271,
                                   a3: 0,
                                   a4: (char *)&vecNodePos + 4);
          if ( CAI_TacticalServices::FindLateralCover(
                 this: (CAI_TacticalServices *)HIDWORD(right),
                 vecThreat: v109,
                 flMinDist: a3,
                 pResult: a4) )
          {
            AI_NavGoal_t::AI_NavGoal_t(
              this: (AI_NavGoal_t *)v269,
              dest: (const Vector *)((char *)&vecNodePos + 4),
              activity: ACT_RUN,
              tolerance: -1.0,
              flags: 0,
              pTarget: AIN_DEF_TARGET_8);
            v5->m_pNavigator->SetGoal(this: v5->m_pNavigator, a2: (const AI_NavGoal_t *)v269, a3: 1u);
            v110 = gpGlobals->curtime + *(float *)LODWORD(flRange);
            LOBYTE(flDistZ) = 0;
            v5->m_flMoveWaitFinished = v110;
            CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: SLOBYTE(flDistZ));
            return;
          }
          HIDWORD(right) = v5->m_pTacticalServices;
          *(float *)&pResulta = ((double (__thiscall *)(CAI_BaseNPC *, char *))v5->CoverRadius)(
                                  a1: v5,
                                  a2: (char *)&vecNodePos + 4);
          tolerance = (const Vector *)((int (__thiscall *)(CBaseEntity *))v107->EyePosition)(a1: v107);
          v111 = CBaseEntity::GetAbsOrigin(this: v107);
          if ( !CAI_TacticalServices::FindCoverPos(
                  this: (CAI_TacticalServices *)HIDWORD(right),
                  vThreatPos: v111,
                  vThreatEyePos: tolerance,
                  flMinDist: COERCE_FLOAT(&v274),
                  flMaxDist: 0.0,
                  pResult: pResulta) )
          {
            v5->TaskFail(this: v5, a2: 8);
            goto LABEL_148;
          }
          v112 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hStoredPathTarget);
          AI_NavGoal_t::AI_NavGoal_t(
            this: (AI_NavGoal_t *)v269,
            type: GOALTYPE_COVER,
            dest: (const Vector *)((char *)&vecNodePos + 4),
            activity: ACT_RUN,
            tolerance: -2.0,
            flags: 0,
            pTarget: v112);
          v113 = ((int (__thiscall *)(CAI_Navigator *, int *))v5->m_pNavigator->SetGoal)(
                   a1: v5->m_pNavigator,
                   a2: &v279);
          v5->m_flMoveWaitFinished = gpGlobals->curtime + *(float *)LODWORD(flRange);
        }
        else
        {
          vec2RightSide.x = 2000.0;
          flRange = 0.0;
          if ( CBaseCombatCharacter::GetActiveWeapon(this: v5) != nullptr )
          {
            p_m_fMaxRange1 = &CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange1;
            if ( *p_m_fMaxRange1 <= CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange2 )
              m_fMaxRange2 = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange2;
            else
              m_fMaxRange2 = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange1;
            vec2RightSide.x = m_fMaxRange2;
            p_m_fMinRange1 = &CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange1;
            if ( CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange2 <= *p_m_fMinRange1 )
              flRange = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange2;
            else
              flRange = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange1;
          }
          else if ( (v5->CapabilitiesGet(this: v5) & 0x20000) != 0 )
          {
            vec2RightSide.x = v5->InnateRange1MaxRange(this: v5);
            flRange = v5->InnateRange1MinRange(this: v5);
          }
          if ( vec2RightSide.x > v5->m_flDistTooFar )
            vec2RightSide.x = v5->m_flDistTooFar;
          if ( CHandle<CBaseEntity>::operator!=(this: &v5->m_hStoredPathTarget, val: nullptr) )
          {
            v117 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hStoredPathTarget);
            p_m_vecStoredPathGoal = v117->EyePosition(this: v117, result: (Vector *)&coverGoal.pTarget);
          }
          else
          {
            p_m_vecStoredPathGoal = &v5->m_vecStoredPathGoal;
          }
          m_pTacticalServices = v5->m_pTacticalServices;
          vecEnemyEye = *p_m_vecStoredPathGoal;
          if ( !CAI_TacticalServices::FindLos(
                  this: m_pTacticalServices,
                  threatPos: &v5->m_vecStoredPathGoal,
                  threatEyePos: &vecEnemyEye,
                  minThreatDist: flRange,
                  maxThreatDist: vec2RightSide.x,
                  blockTime: 1.0,
                  pResult: (Vector *)((char *)&vecNodePos + 4)) )
          {
            v5->TaskFail(this: v5, a2: 10);
            return;
          }
          m_pNavigator = v5->m_pNavigator;
          v280 = *(_QWORD *)((char *)&vecNodePos + 4);
          goal.type = HIDWORD(vecNodePos);
          v113 = m_pNavigator->SetGoal(this: m_pNavigator, a2: (const AI_NavGoal_t *)&v279, a3: 0);
        }
      }
      else
      {
        v121 = v5->m_pNavigator;
        v280 = *(_QWORD *)&v5->m_vecStoredPathGoal.x;
        goal.type = LODWORD(v5->m_vecStoredPathGoal.z);
        v113 = v121->SetGoal(this: v121, a2: (const AI_NavGoal_t *)&v279, a3: 0);
      }
      if ( v113 != 0 )
      {
        CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
        return;
      }
LABEL_148:
      v5->TaskFail(this: v5, a2: 11);
      return;
    case 0x12:
      v122 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v123 = ((int (__thiscall *)(CAI_BaseNPC *, _DWORD, Vector *))this->GetEnemy_2)(a1: this, a2: LODWORD(a3), a3: a4);
      v16 = !v122->IsUnreachable(this: v5, a2: (CBaseEntity *)v123);
      v124 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      if ( !v16 )
      {
        v124->TaskFail(this: v5, a2: 11);
        return;
      }
      if ( v124->GetEnemy_2(this: v5) == nullptr )
      {
LABEL_245:
        v5->TaskFail(this: v5, a2: 6);
        return;
      }
      AI_NavGoal_t::AI_NavGoal_t(
        this: &v266,
        type: GOALTYPE_ENEMY,
        activity: ACT_INVALID,
        tolerance: -1.0,
        flags: 0,
        pTarget: AIN_DEF_TARGET_8);
      if ( v5->m_pNavigator->SetGoal(this: v5->m_pNavigator, a2: &v266, a3: 0) )
        goto LABEL_5;
      _DevWarning(a1: 2, a2: "GetPathToEnemy failed!!\n");
      v125 = (CBaseEntity *)((int (__thiscall *)(CAI_BaseNPC *, int))v5->GetEnemy_2)(a1: v5, a2: -1082130432);
      CAI_BaseNPC::RememberUnreachable(this: v5, pEntity: v125, duration: vec2RightSide.x);
      v5->TaskFail(this: v5, a2: 11);
      return;
    case 0x13:
      v72 = this->GetEnemy_2(this);
      if ( v72 == nullptr || v5->IsUnreachable(this: v5, a2: v72) )
        goto LABEL_153;
      flDeltaYawb = AIN_DEF_TARGET_8;
      v73 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *, int, int))v5->GetEnemyLKP)(
                              a1: v5,
                              a2: -1,
                              a3: -1082130432);
      AI_NavGoal_t::AI_NavGoal_t(
        this: (AI_NavGoal_t *)&v279,
        dest: v73,
        activity: ACT_RESET,
        tolerance: *(float *)&flDeltaYawb,
        flags: LODWORD(a3),
        pTarget: (CBaseEntity *)a4);
      ((void (__thiscall *)(CAI_BaseNPC *))v5->TranslateNavGoal)(a1: v5);
      if ( v5->m_pNavigator->SetGoal(this: v5->m_pNavigator, a2: (const AI_NavGoal_t *)&v279, a3: 2u) )
        goto LABEL_5;
      _DevWarning(a1: 2, a2: "GetPathToEnemyLKP failed!!\n");
      v74 = v5->GetEnemy_2(this: v5);
      CAI_BaseNPC::RememberUnreachable(this: v5, pEntity: v74, duration: -1.0);
      goto LABEL_153;
    case 0x14:
      *(float *)&v68 = COERCE_FLOAT((int)this->GetEnemy_2(this));
      v41 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      flRange = *(float *)&v68;
      if ( *(float *)&v68 == 0.0 )
        goto LABEL_78;
      LODWORD(vec2RightSide.x) = ((int (__thiscall *)(CAI_BaseNPC *, float))v41->GetEnemyLKP)(
                                   a1: v5,
                                   a2: COERCE_FLOAT(LODWORD(a3)));
      v69 = CBaseEntity::GetAbsOrigin(this: (CBaseEntity *)LODWORD(flRange));
      v70 = (float)(pTask->flTaskData * pTask->flTaskData) <= (float)((float)((float)((float)(v69->x
                                                                                            - *(float *)LODWORD(vec2RightSide.x))
                                                                                    * (float)(v69->x
                                                                                            - *(float *)LODWORD(vec2RightSide.x)))
                                                                            + (float)((float)(v69->y
                                                                                            - *(float *)(LODWORD(vec2RightSide.x) + 4))
                                                                                    * (float)(v69->y
                                                                                            - *(float *)(LODWORD(vec2RightSide.x) + 4))))
                                                                    + (float)((float)(v69->z
                                                                                    - *(float *)(LODWORD(vec2RightSide.x)
                                                                                               + 8))
                                                                            * (float)(v69->z
                                                                                    - *(float *)(LODWORD(vec2RightSide.x)
                                                                                               + 8))));
      HIDWORD(right) = 0;
      v71 = v5->StartTask;
      if ( v70 )
        DWORD2(right) = 19;
      else
        DWORD2(right) = 18;
      v71(this: v5, a2: (const Task_t *)&right + 1);
      if ( v5->m_ScheduleState.fTaskStatus != TASKSTATUS_COMPLETE
        && !CAI_BaseNPC::HasCondition(this: v5, iCondition: 35) )
      {
        goto LABEL_148;
      }
      return;
    case 0x15:
    case 0x18:
    case 0x19:
    case 0x1A:
      if ( this->GetEnemy_2(this) == nullptr )
      {
        v5->TaskFail(this: v5, a2: 6);
        return;
      }
      vec2RightSide.x = 2000.0;
      flRange = 0.0;
      if ( CBaseCombatCharacter::GetActiveWeapon(this: v5) != nullptr )
      {
        HIDWORD(right) = &CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange1;
        if ( *(float *)HIDWORD(right) <= CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange2 )
          m_fMaxRange1 = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange2;
        else
          m_fMaxRange1 = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange1;
        vec2RightSide.x = m_fMaxRange1;
        HIDWORD(right) = &CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange1;
        if ( CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange2 <= *(float *)HIDWORD(right) )
          flRange = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange2;
        else
          flRange = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange1;
      }
      else if ( (v5->CapabilitiesGet(this: v5) & 0x20000) != 0 )
      {
        vec2RightSide.x = v5->InnateRange1MaxRange(this: v5);
        flRange = v5->InnateRange1MinRange(this: v5);
      }
      if ( vec2RightSide.x > v5->m_flDistTooFar )
        vec2RightSide.x = v5->m_flDistTooFar;
      v87 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      if ( LODWORD(flDistZ) == 19 )
      {
        v89 = v87->GetEnemyLKP(this: v5);
      }
      else
      {
        v88 = v87->GetEnemy_2(this: v5);
        v89 = CBaseEntity::GetAbsOrigin(this: v88);
      }
      v90 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      *(_QWORD *)((char *)&vecNodePos + 4) = *(_QWORD *)&v89->x;
      HIDWORD(vecNodePos) = LODWORD(v89->z);
      v91 = (int)v90->GetEnemy_2(this: v5);
      v92 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v91 + 532))(a1: v91);
      goal.maxInitialSimplificationDist = *((float *)&vecNodePos + 1) + *v92;
      *(float *)&goal.flags = v92[1] + *((float *)&vecNodePos + 2);
      *(float *)&goal.pTarget = v92[2] + *((float *)&vecNodePos + 3);
      if ( LODWORD(flDistZ) != 25
        && LODWORD(flDistZ) != 26
        && CAI_TacticalServices::FindLateralLos(
             this: v5->m_pTacticalServices,
             vecThreat: (const Vector *)&goal.maxInitialSimplificationDist,
             pResult: &vecEnemyEye) )
      {
        v93 = 0;
        *(float *)&v93 = fsqrt(
                           (float)((float)((float)(vecEnemyEye.x - goal.maxInitialSimplificationDist)
                                         * (float)(vecEnemyEye.x - goal.maxInitialSimplificationDist))
                                 + (float)((float)(vecEnemyEye.y - *(float *)&goal.flags)
                                         * (float)(vecEnemyEye.y - *(float *)&goal.flags)))
                         + (float)((float)(vecEnemyEye.z - *(float *)&goal.pTarget)
                                 * (float)(vecEnemyEye.z - *(float *)&goal.pTarget)));
        right = v93;
        if ( vec2RightSide.x > *(float *)&v93 && *(float *)&right > flRange )
          goto LABEL_199;
      }
      *(Vector *)((char *)&right + 4) = vec3_origin;
      v94 = FLANKTYPE_NONE;
      v95 = 0.0;
      if ( LODWORD(flDistZ) == 25 )
      {
        v94 = FLANKTYPE_RADIUS;
      }
      else
      {
        if ( LODWORD(flDistZ) != 26 )
          goto LABEL_198;
        v94 = FLANKTYPE_ARC;
      }
      *(_QWORD *)((char *)&right + 4) = *(_QWORD *)&v5->m_vSavePosition.x;
      HIDWORD(right) = LODWORD(v5->m_vSavePosition.z);
      v95 = pTask->flTaskData;
LABEL_198:
      if ( !CAI_TacticalServices::FindLos(
              this: v5->m_pTacticalServices,
              threatPos: (const Vector *)((char *)&vecNodePos + 4),
              threatEyePos: (const Vector *)&goal.maxInitialSimplificationDist,
              minThreatDist: flRange,
              maxThreatDist: vec2RightSide.x,
              blockTime: 1.0,
              eFlankType: v94,
              vecFlankRefPos: (const Vector *)((char *)&right + 4),
              flFlankParam: v95,
              pResult: &vecEnemyEye) )
        goto LABEL_267;
LABEL_199:
      v5->m_vInterruptSavePosition = vecEnemyEye;
      return;
    case 0x16:
      AngleVectors(angles: &this->m_angRotation.m_Value, forward: &vecEnemyEye);
      v126 = (int)v5->GetEnemyLKP(this: v5);
      v127 = *(float *)(v126 + 8);
      *(_QWORD *)((char *)&vecNodePos + 4) = *(_QWORD *)v126;
      *(float *)&goal.flags = *((float *)&vecNodePos + 2) - (float)(vecEnemyEye.y * 64.0);
      *((float *)&vecNodePos + 3) = v127;
      *(float *)&goal.pTarget = v127 - (float)(vecEnemyEye.z * 64.0);
      goal.maxInitialSimplificationDist = *((float *)&vecNodePos + 1) - (float)(vecEnemyEye.x * 64.0);
      AI_NavGoal_t::AI_NavGoal_t(
        this: &v262,
        dest: (const Vector *)&goal.maxInitialSimplificationDist,
        activity: ACT_INVALID,
        tolerance: -1.0,
        flags: 0,
        pTarget: AIN_DEF_TARGET_8);
      v5->m_pNavigator->SetGoal(this: v5->m_pNavigator, a2: &v262, a3: 2u);
      return;
    case 0x17:
      v128 = CGlobalEntityList::FindEntityByName(
               this: &gEntList,
               pStartEntity: nullptr,
               szName: "!player",
               pSearchingEntity: nullptr,
               pActivator: nullptr,
               pCaller: nullptr,
               pFilter: nullptr);
      AI_NavGoal_t::AI_NavGoal_t(
        this: (AI_NavGoal_t *)&v279,
        type: GOALTYPE_INVALID,
        activity: ACT_INVALID,
        tolerance: -1.0,
        flags: 0,
        pTarget: AIN_DEF_TARGET_8);
      v279 = 4;
      v129 = (int)v128->WorldSpaceCenter(this: v128);
      v130 = v5->m_pNavigator;
      v280 = *(_QWORD *)v129;
      goal.type = *(_DWORD *)(v129 + 8);
      LODWORD(goal.tolerance) = v128;
      v130->SetGoal(this: v130, a2: (const AI_NavGoal_t *)&v279, a3: 0);
      return;
    case 0x1B:
      if ( this->GetEnemy_2(this) == nullptr )
        goto LABEL_153;
      CapabilitiesGet = v5->CapabilitiesGet;
      flDistZ = -1.0;
      if ( (CapabilitiesGet(this: v5) & 0x60000) != 0 )
      {
        flDistZ = v5->InnateRange1MaxRange(this: v5);
      }
      else if ( CBaseCombatCharacter::GetActiveWeapon(this: v5) != nullptr )
      {
        LODWORD(flRange) = &CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange1;
        if ( *(float *)LODWORD(flRange) <= CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange2 )
          flDistZ = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange2;
        else
          flDistZ = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange1;
      }
      else
      {
        v5->TaskFail(this: v5, a2: 11);
      }
      v80 = pTask->flTaskData;
      if ( v80 != 0.0 && flDistZ > v80 )
        flDistZ = pTask->flTaskData;
      v81 = v5->GetEnemy_2(this: v5);
      v82 = CAI_BaseNPC::EnemyDistance(this: v5, a2: (int)pTask, a3: (int)v5, pEnemy: v81);
      flRange = v82;
      if ( flDistZ >= v82 )
        goto LABEL_5;
      v83 = v5->m_pNavigator;
      v84 = v5->GetEnemy_2(this: v5);
      v85 = CBaseEntity::GetAbsOrigin(this: v84);
      if ( CAI_Navigator::SetVectorGoalFromTarget(
             this: v83,
             goalPos: v85,
             minDist: flRange - flDistZ,
             fShouldDeflect: false) )
      {
        goto LABEL_369;
      }
      goto LABEL_153;
    case 0x1C:
      if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTargetEnt, val: nullptr) )
        goto LABEL_206;
      v165 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
      v166 = (const Vector *)((int (__thiscall *)(CBaseEntity *, int *, int, int, _DWORD, CBaseEntity *const))v165->EyePosition)(
                               a1: v165,
                               a2: &v275,
                               a3: -1,
                               a4: -1082130432,
                               a5: 0,
                               a6: AIN_DEF_TARGET_8);
      AI_NavGoal_t::AI_NavGoal_t(
        this: (AI_NavGoal_t *)&v279,
        dest: v166,
        activity: SHIDWORD(right),
        tolerance: flDistZ,
        flags: LODWORD(vec2RightSide.x),
        pTarget: (CBaseEntity *)LODWORD(vec2RightSide.y));
      v167 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
      v168 = v5->m_pNavigator;
      LODWORD(goal.tolerance) = v167;
      v168->SetGoal(this: v168, a2: (const AI_NavGoal_t *)&v279, a3: 0);
      return;
    case 0x1D:
      if ( CHandle<CBaseEntity>::operator==(this: &this->m_hTargetEnt, val: nullptr) )
        goto LABEL_206;
      HIDWORD(right) = v5->m_pNavigator->m_pAINetwork;
      v139 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
      v140 = CBaseEntity::GetAbsOrigin(this: v139);
      v141 = CAI_Network::NearestNodeToPoint(
               this: (CAI_Network *)HIDWORD(right),
               pNPC: v5,
               vecOrigin: v140,
               bCheckVisibility: false,
               pFilter: nullptr);
      m_pAINetwork = v5->m_pNavigator->m_pAINetwork;
      if ( v141 < 0 || v141 >= m_pAINetwork->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
        goto LABEL_153;
      }
      v143 = m_pAINetwork->m_pAInode[v141];
      if ( v143 == nullptr )
      {
LABEL_153:
        v5->TaskFail(this: v5, a2: 11);
        return;
      }
      vecEnemyEye = *CAI_Node::GetPosition(this: v143, result: &v272, hull: v5->m_eHull);
      v144 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
      v145 = CBaseEntity::GetAbsOrigin(this: v144);
      LODWORD(v146) = COERCE_UNSIGNED_INT(vecEnemyEye.z - v145->z) & _mask__AbsFloat_;
      *((float *)&right + 3) = v146;
      if ( v146 > 72.0 )
      {
        v5->TaskFail(this: v5, a2: (int)"Target not within Z_LENIENCY!\n");
        v147 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
        v148 = ToBaseCombatWeapon(pEntity: v147);
        if ( v148 != nullptr )
        {
LABEL_274:
          CBaseCombatWeapon::Lock(this: v148, lockTime: 30.0, pLocker: v148);
          return;
        }
        v146 = *((float *)&right + 3);
      }
      if ( v146 < 16.0 )
      {
        flDeltaYawc = AIN_DEF_TARGET_8;
        v156 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
        v157 = CBaseEntity::GetAbsOrigin(this: v156);
        AI_NavGoal_t::AI_NavGoal_t(
          this: (AI_NavGoal_t *)&v279,
          dest: v157,
          activity: ACT_INVALID,
          tolerance: -1.0,
          flags: 0,
          pTarget: flDeltaYawc);
        v158 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
        v159 = v5->m_pNavigator;
        LODWORD(goal.tolerance) = v158;
        v155 = v159->SetGoal(this: v159, a2: (const AI_NavGoal_t *)&v279, a3: 0);
      }
      else
      {
        v149 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
        v150 = CBaseEntity::GetAbsOrigin(this: v149);
        v151 = 0;
        *(float *)&v151 = fsqrt(
                            (float)((float)(vecEnemyEye.y - v150->y) * (float)(vecEnemyEye.y - v150->y))
                          + (float)((float)(vecEnemyEye.x - v150->x) * (float)(vecEnemyEye.x - v150->x)));
        vecNodePos = v151;
        if ( *(float *)&v151 > 64.0 )
        {
          v5->TaskFail(this: v5, a2: (int)"Target not within XY_LENIENCY!\n");
          v152 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
          v148 = ToBaseCombatWeapon(pEntity: v152);
          if ( v148 != nullptr )
            goto LABEL_274;
        }
        AI_NavGoal_t::AI_NavGoal_t(
          this: (AI_NavGoal_t *)&v279,
          dest: &vecEnemyEye,
          activity: ACT_INVALID,
          tolerance: -1.0,
          flags: 0,
          pTarget: AIN_DEF_TARGET_8);
        v153 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
        v154 = v5->m_pNavigator;
        LODWORD(goal.tolerance) = v153;
        v155 = v154->SetGoal(this: v154, a2: (const AI_NavGoal_t *)&v279, a3: 0);
      }
      if ( !v155 )
      {
        v160 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
        v161 = ToBaseCombatWeapon(pEntity: v160);
        if ( v161 != nullptr )
          CBaseCombatWeapon::Lock(this: v161, lockTime: 15.0, pLocker: v161);
      }
      return;
    case 0x1E:
      v162 = this->m_pNavigator;
      GroundEntity = (CWorld *)CBaseEntity::GetGroundEntity(this);
      CAI_Navigator::SetAllowBigStep(this: v162, pEntToStepOff: GroundEntity);
      v164 = v5->StartTask;
      *((_QWORD *)&right + 1) = 0x424000000000000ELL;
      v164(this: v5, a2: (const Task_t *)&right + 1);
      return;
    case 0x1F:
      ((void (__thiscall *)(CAI_BaseNPC *, const char *))this->GiveWeapon)(
        a1: this,
        a2: this->m_iszPendingWeapon.pszValue);
      v5->m_iszPendingWeapon.pszValue = nullptr;
      goto LABEL_5;
    case 0x20:
      if ( CBasePlayer::GetVehicleEntity(this) == nullptr )
        goto LABEL_19;
      VehicleEntity = CBasePlayer::GetVehicleEntity(this: v5);
      CAI_Hint::GetPosition(this: VehicleEntity, pBCC: v5, vPosition: (Vector *)((char *)&vecNodePos + 4));
      flRange = *(float *)&v5->m_pNavigator;
      HIDWORD(right) = *(_DWORD *)LODWORD(flRange) + 20;
      v170 = AI_NavGoal_t::AI_NavGoal_t(
               this: &v258,
               dest: (const Vector *)((char *)&vecNodePos + 4),
               activity: ACT_RUN,
               tolerance: -1.0,
               flags: 0,
               pTarget: AIN_DEF_TARGET_8);
      (*(void (__thiscall **)(float, AI_NavGoal_t *, _DWORD))HIDWORD(right))(
        a1: COERCE_FLOAT(LODWORD(flRange)),
        a2: v170,
        a3: 0);
      if ( pTask->flTaskData == 0.0 )
      {
        v171 = v5->m_pNavigator;
        v172 = CBasePlayer::GetVehicleEntity(this: v5);
        Direction = CAI_Hint::GetDirection(this: v172, result: &v276);
        CAI_Navigator::SetArrivalDirection(this: v171, goalDirection: Direction);
      }
      if ( CBasePlayer::GetVehicleEntity(this: v5)->m_NodeData.iszActivityName.pszValue != nullptr )
      {
        pszValue = CBasePlayer::GetVehicleEntity(this: v5)->m_NodeData.iszActivityName.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        ActivityID = CAI_BaseNPC::GetActivityID(actName: pszValue);
        v176 = CBasePlayer::GetVehicleEntity(this: v5);
        if ( ActivityID == -1 )
        {
          v179 = v176->m_NodeData.iszActivityName.pszValue;
          if ( v179 == nullptr )
            v179 = locale;
          v180 = CBaseAnimating::LookupSequence(this: v5, label: v179);
          if ( v180 != -1 )
            CAI_Navigator::SetArrivalSequence(this: v5->m_pNavigator, sequence: v180);
        }
        else
        {
          nHintType = v176->m_NodeData.nHintType;
          HIDWORD(right) = v5->m_pNavigator;
          v178 = v5->GetHintActivity(this: v5, a2: nHintType, a3: (Activity)ActivityID);
          CAI_Navigator::SetArrivalActivity(this: (CAI_Navigator *)HIDWORD(right), activity: v178);
        }
      }
      return;
    case 0x21:
      this->m_vecLastPosition = this->m_vecOrigin.m_Value;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x22:
      this->m_vecLastPosition = vec3_origin;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x23:
      this->m_vSavePosition = this->m_vecOrigin.m_Value;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x24:
      v9 = this->GetBestSound(this, a2: 1048351);
      p_m_hOwner = &v9->m_hOwner;
      if ( v9 == nullptr )
        goto LABEL_316;
      v5->m_vSavePosition = *CSound::GetSoundOrigin(this: v9);
      v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hOwner);
      if ( v11 != nullptr )
      {
        v11->GetVelocity(this: v11, a2: (Vector *)((char *)&vecNodePos + 4), a3: nullptr);
        v12 = *((float *)&vecNodePos + 2);
        v13 = *((float *)&vecNodePos + 3);
        v5->m_vSavePosition.x = (float)(*((float *)&vecNodePos + 1) * 2.0) + v5->m_vSavePosition.x;
        v5->m_vSavePosition.y = v5->m_vSavePosition.y + (float)(v12 * 2.0);
        v5->m_vSavePosition.z = v5->m_vSavePosition.z + (float)(v13 * 2.0);
      }
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x25:
      v14 = this->GetBestSound(this, a2: 1048351);
      if ( v14 != nullptr )
      {
        SoundReactOrigin = CSound::GetSoundReactOrigin(this: v14);
        v5->m_vSavePosition.x = SoundReactOrigin->x;
        vec2RightSide.y = 0.0;
        v5->m_vSavePosition.y = SoundReactOrigin->y;
        v5->m_vSavePosition.z = SoundReactOrigin->z;
        CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: SLOBYTE(vec2RightSide.y));
      }
      else
      {
LABEL_316:
        v5->TaskFail(this: v5, a2: (int)"No Sound!");
      }
      return;
    case 0x27:
      v16 = this->GetEnemy_2(this) == nullptr;
      v17 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      if ( v16 )
        goto LABEL_252;
      v18 = v17->GetEnemy_2(this: v5);
      v19 = CBaseEntity::GetAbsOrigin(this: v18);
      v5->m_vSavePosition.x = v19->x;
      y = v19->y;
      flDistZ = 0.0;
      v5->m_vSavePosition.y = y;
      v5->m_vSavePosition.z = v19->z;
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: SLOBYTE(flDistZ));
      return;
    case 0x28:
      AI_NavGoal_t::AI_NavGoal_t(
        this: &v264,
        dest: &this->m_vecCommandGoal,
        activity: ACT_INVALID,
        tolerance: -1.0,
        flags: 0,
        pTarget: AIN_DEF_TARGET_8);
      if ( !v5->m_pNavigator->SetGoal(this: v5->m_pNavigator, a2: &v264, a3: 0) )
      {
        v5->OnMoveToCommandGoalFailed(this: v5);
        v5->TaskFail(this: v5, a2: 11);
      }
      return;
    case 0x29:
      CAI_MoveMonitor::SetMark(this: &this->m_CommandMoveMonitor, pEntity: this, tolerance: 48.0);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x2A:
      this->m_vecCommandGoal = vec3_invalid;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x2B:
      AI_NavGoal_t::AI_NavGoal_t(
        this: &v267,
        dest: &this->m_vecLastPosition,
        activity: ACT_INVALID,
        tolerance: -1.0,
        flags: 0,
        pTarget: AIN_DEF_TARGET_8);
      if ( !v5->m_pNavigator->SetGoal(this: v5->m_pNavigator, a2: &v267, a3: 0) )
        goto LABEL_153;
      CAI_Navigator::SetGoalTolerance(this: v5->m_pNavigator, tolerance: 48.0);
      return;
    case 0x2C:
      AI_NavGoal_t::AI_NavGoal_t(
        this: &v265,
        dest: &this->m_vSavePosition,
        activity: ACT_INVALID,
        tolerance: -1.0,
        flags: 0,
        pTarget: AIN_DEF_TARGET_8);
      v5->m_pNavigator->SetGoal(this: v5->m_pNavigator, a2: &v265, a3: 0);
      return;
    case 0x2D:
      if ( this->GetEnemy_2(this) != nullptr )
      {
        flRange = 2000.0;
        vec2RightSide.x = 0.0;
        if ( CBaseCombatCharacter::GetActiveWeapon(this: v5) != nullptr )
        {
          v131 = &CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange1;
          if ( *v131 <= CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange2 )
            v132 = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange2;
          else
            v132 = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMaxRange1;
          flRange = v132;
          v133 = &CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange1;
          if ( CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange2 <= *v133 )
            m_fMinRange2 = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange2;
          else
            m_fMinRange2 = CBaseCombatCharacter::GetActiveWeapon(this: v5)->m_fMinRange1;
        }
        else
        {
          if ( (v5->CapabilitiesGet(this: v5) & 0x20000) != 0 )
          {
            flRange = v5->InnateRange1MaxRange(this: v5);
            vec2RightSide.x = v5->InnateRange1MinRange(this: v5);
          }
          m_fMinRange2 = vec2RightSide.x;
        }
        m_flDistTooFar = flRange;
        if ( flRange > v5->m_flDistTooFar )
          m_flDistTooFar = v5->m_flDistTooFar;
        if ( CAI_TacticalServices::FindLos(
               this: v5->m_pTacticalServices,
               threatPos: &v5->m_vSavePosition,
               threatEyePos: &v5->m_vSavePosition,
               minThreatDist: m_fMinRange2,
               maxThreatDist: m_flDistTooFar,
               blockTime: 1.0,
               pResult: (Vector *)((char *)&vecNodePos + 4)) )
        {
          v136 = (int *)v5->m_pNavigator;
          v137 = *v136;
          v138 = AI_NavGoal_t::AI_NavGoal_t(
                   this: &v259,
                   dest: (const Vector *)((char *)&vecNodePos + 4),
                   activity: ACT_RUN,
                   tolerance: -2.0,
                   flags: 0,
                   pTarget: AIN_DEF_TARGET_8);
          (*(void (__thiscall **)(int *, AI_NavGoal_t *, _DWORD))(v137 + 20))(a1: v136, a2: v138, a3: 0);
        }
        else
        {
LABEL_267:
          v5->TaskFail(this: v5, a2: 10);
        }
      }
      else
      {
        v17 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
LABEL_252:
        ((void (__cdecl *)(int))v17->TaskFail)(a1: 6);
      }
      return;
    case 0x2E:
      v181 = CAI_Navigator::SetRandomGoal(this: this->m_pNavigator, minPathLength: pTask->flTaskData, dir: &vec3_origin);
      this = v5;
      if ( !v181 )
        goto LABEL_308;
      goto $LN375;
    case 0x2F:
      v182 = this->GetBestSound(this, a2: 1048351);
      if ( v182 != nullptr )
      {
        LODWORD(vec2RightSide.x) = AIN_DEF_TARGET_8;
        v183 = CSound::GetSoundReactOrigin(this: v182);
        AI_NavGoal_t::AI_NavGoal_t(
          this: &v263,
          dest: v183,
          activity: ACT_INVALID,
          tolerance: -1.0,
          flags: 0,
          pTarget: (CBaseEntity *)LODWORD(vec2RightSide.x));
        v184 = v5->m_pNavigator;
        SetGoal = v184->SetGoal;
        vec2RightSide.x = 0.0;
        ((void (__thiscall *)(CAI_Navigator *, AI_NavGoal_t *))SetGoal)(a1: v184, a2: &v263);
      }
      else
      {
        v5->TaskFail(this: v5, a2: 17);
      }
      return;
    case 0x30:
      v186 = this->GetBestScent(this);
      if ( v186 != nullptr )
      {
        LODWORD(vec2RightSide.x) = AIN_DEF_TARGET_8;
        v187 = CSound::GetSoundOrigin(this: v186);
        AI_NavGoal_t::AI_NavGoal_t(
          this: &v261,
          dest: v187,
          activity: ACT_INVALID,
          tolerance: -1.0,
          flags: 0,
          pTarget: (CBaseEntity *)LODWORD(vec2RightSide.x));
        v188 = v5->m_pNavigator;
        v189 = v188->SetGoal;
        vec2RightSide.x = 0.0;
        ((void (__thiscall *)(CAI_Navigator *, AI_NavGoal_t *))v189)(a1: v188, a2: &v261);
      }
      else
      {
        v5->TaskFail(this: v5, a2: 18);
      }
      return;
    case 0x31:
      v194 = CAI_BaseNPC::TranslateActivity(this, idealActivity: ACT_RUN, pIdealWeaponActivity: nullptr);
      v195 = v5->m_pNavigator;
      if ( v194 == ACT_INVALID )
        CAI_Navigator::SetMovementActivity(this: v195, activity: ACT_WALK);
      else
        CAI_Navigator::SetMovementActivity(this: v195, activity: ACT_RUN);
      goto LABEL_323;
    case 0x32:
      m_Value = this->m_MoveType.m_Value;
      if ( (m_Value == 4 || m_Value == 5)
        && CAI_BaseNPC::TranslateActivity(this, idealActivity: ACT_FLY, pIdealWeaponActivity: nullptr) != ACT_INVALID )
      {
        CAI_Navigator::SetMovementActivity(this: v5->m_pNavigator, activity: ACT_FLY);
      }
      else if ( CAI_BaseNPC::TranslateActivity(this: v5, idealActivity: ACT_WALK, pIdealWeaponActivity: nullptr) == ACT_INVALID )
      {
        CAI_Navigator::SetMovementActivity(this: v5->m_pNavigator, activity: ACT_RUN);
      }
      else
      {
        CAI_Navigator::SetMovementActivity(this: v5->m_pNavigator, activity: ACT_WALK);
      }
LABEL_323:
      v5->m_afMemory &= ~2u;
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x33:
      CAI_Navigator::SetMovementActivity(this: this->m_pNavigator, activity: ACT_WALK);
      goto LABEL_339;
    case 0x34:
      CAI_Navigator::SetMovementActivity(this: this->m_pNavigator, activity: ACT_WALK);
      goto LABEL_333;
    case 0x35:
      CAI_Navigator::SetMovementActivity(this: this->m_pNavigator, activity: ACT_WALK);
      return;
    case 0x36:
      GoalPos = CAI_Navigator::GetGoalPos(this: this->m_pNavigator);
      v198 = v5->m_pNavigator;
      v199 = 0;
      *(float *)&v199 = fsqrt(
                          (float)((float)((float)(v5->m_vecOrigin.m_Value.y - GoalPos->y)
                                        * (float)(v5->m_vecOrigin.m_Value.y - GoalPos->y))
                                + (float)((float)(v5->m_vecOrigin.m_Value.z - GoalPos->z)
                                        * (float)(v5->m_vecOrigin.m_Value.z - GoalPos->z)))
                        + (float)((float)(v5->m_vecOrigin.m_Value.x - GoalPos->x)
                                * (float)(v5->m_vecOrigin.m_Value.x - GoalPos->x)));
      vecNodePos = v199;
      if ( pTask->flTaskData < *(float *)&v199 )
      {
        CAI_Navigator::SetMovementActivity(this: v198, activity: ACT_RUN);
      }
      else
      {
        CAI_Navigator::StopMoving(this: v198, bImmediate: true);
        v5->TaskFail(this: v5, a2: (int)"Flee path shorter than task parameter");
      }
      return;
    case 0x37:
      CAI_Navigator::SetMovementActivity(this: this->m_pNavigator, activity: ACT_RUN);
LABEL_339:
      CAI_BaseNPC::SetWait(this: v5, minWait: pTask->flTaskData, maxWait: 0.0);
      return;
    case 0x38:
    case 0x87:
    case 0x8A:
      CAI_Navigator::SetMovementActivity(this: this->m_pNavigator, activity: ACT_RUN);
      return;
    case 0x39:
      CAI_Navigator::SetMovementActivity(this: this->m_pNavigator, activity: ACT_RUN);
LABEL_333:
      CAI_Navigator::SetArrivalDistance(this: v5->m_pNavigator, flDistance: pTask->flTaskData);
      return;
    case 0x3A:
      AngleVectors(
        angles: &this->m_angRotation.m_Value,
        forward: nullptr,
        right: (Vector *)((char *)&vecNodePos + 4),
        up: nullptr);
      CurWaypointPos = CAI_Navigator::GetCurWaypointPos(this: v5->m_pNavigator);
      v201 = CurWaypointPos->y - v5->m_vecOrigin.m_Value.y;
      vec2RightSide.y = CurWaypointPos->x - v5->m_vecOrigin.m_Value.x;
      flRange = v201;
      Vector2DNormalize(v: (Vector2D *)&vec2RightSide.y);
      *((_QWORD *)&right + 1) = *(_QWORD *)((char *)&vecNodePos + 4);
      Vector2DNormalize(v: (Vector2D *)&right + 1);
      v202 = v5->m_pNavigator;
      if ( (float)((float)(*((float *)&right + 3) * flRange) + (float)(*((float *)&right + 2) * vec2RightSide.y)) <= 0.0 )
        CAI_Navigator::SetMovementActivity(this: v202, activity: ACT_STRAFE_LEFT);
      else
        CAI_Navigator::SetMovementActivity(this: v202, activity: ACT_STRAFE_RIGHT);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x3B:
      this->m_flMoveWaitFinished = gpGlobals->curtime;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x3C:
      flMaxDist = 0;
      goto LABEL_356;
    case 0x3D:
      flMaxDist = 1;
LABEL_356:
      GetFlinchActivity = this->GetFlinchActivity;
      this->m_afMemory |= 0x40u;
      v208 = ((int (__cdecl *)(int, _DWORD))GetFlinchActivity)(a1: flMaxDist, a2: 0);
      CAI_BaseNPC::SetIdealActivity(this: v5, NewActivity: v208);
      v5->m_flNextFlinchTime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                 a1: random,
                                 a2: 1077936128,
                                 a3: 1084227584)
                             + gpGlobals->curtime;
      return;
    case 0x3E:
      this->m_flNextDodgeTime = gpGlobals->curtime + pTask->flTaskData;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x3F:
      goto $LN290;
    case 0x40:
      flDeltaYaw = 0;
      goto LABEL_96;
    case 0x41:
      if ( !CAI_Navigator::IsGoalActive(this: this->m_pNavigator) )
      {
        _DevWarning(a1: 2, a2: "No route to face!\n");
        v5->TaskFail(this: v5, a2: 11);
        return;
      }
      m_pMotor = v5->m_pMotor;
      v59 = CAI_Navigator::GetCurWaypointPos(this: v5->m_pNavigator);
      CAI_Motor::SetIdealYawToTarget(this: m_pMotor, target: v59, noise: 0.0, offset: 0.0);
      v60 = CAI_Motor::DeltaIdealYaw(this: v5->m_pMotor);
      this = v5;
      if ( fabs(v60) > 15.0 )
      {
$LN290:
        ((void (*)(void))v5->SetTurnActivity)();
        return;
      }
      goto LABEL_113;
    case 0x43:
      v54 = this->GetEnemyLKP(this);
      FInAimCone = v5->FInAimCone;
      *(_QWORD *)((char *)&vecNodePos + 4) = *(_QWORD *)&v54->x;
      HIDWORD(vecNodePos) = LODWORD(v54->z);
      if ( FInAimCone(this: v5, a2: (const Vector *)((char *)&vecNodePos + 4)) )
      {
        v56 = ((double (__thiscall *)(CAI_BaseNPC *, int))v5->CalcReasonableFacing)(a1: v5, a2: 1);
        flRange = v56;
        v57 = v5->m_pMotor;
        if ( fabs(v56 - v57->m_IdealYaw) < 1.0 )
        {
LABEL_5:
          CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
          return;
        }
        v57->m_IdealYaw = flRange;
      }
      else
      {
        CAI_Motor::SetIdealYawToTarget(
          this: v5->m_pMotor,
          target: (const Vector *)((char *)&vecNodePos + 4),
          noise: 0.0,
          offset: 0.0);
LABEL_95:
        flDeltaYaw = 1;
LABEL_96:
        v51 = v5->m_pMotor;
        v51->m_IdealYaw = ((double (__stdcall *)(int))v5->CalcReasonableFacing)(a1: flDeltaYaw);
      }
      goto LABEL_97;
    case 0x44:
      v47 = this->m_pMotor;
      v48 = CBasePlayer::GetVehicleEntity(this);
      v47->m_IdealYaw = CAI_Hint::Yaw(this: v48);
      v49 = v5->m_pMotor;
      v49->m_IdealYaw = v5->CalcReasonableFacing(this: v5, a2: true);
      v50 = CAI_BaseNPC::FacingIdeal(this: v5, flTolerance: 0.0);
      this = v5;
      if ( !v50 )
        goto $LN290;
      goto $LN375;
    case 0x45:
      v30 = CBasePlayer::GetVehicleEntity(this);
      v31 = v5;
      if ( v30->m_NodeData.iszActivityName.pszValue == nullptr )
        goto LABEL_70;
      v32 = CBasePlayer::GetVehicleEntity(this: v5)->m_NodeData.iszActivityName.pszValue;
      if ( v32 == nullptr )
        v32 = locale;
      v33 = CAI_BaseNPC::GetActivityID(actName: v32);
      v34 = CBasePlayer::GetVehicleEntity(this: v5);
      if ( v33 == -1 )
      {
        v36 = v34->m_NodeData.iszActivityName.pszValue;
        if ( v36 == nullptr )
          v36 = locale;
        v37 = CBaseAnimating::LookupSequence(this: v5, label: v36);
        v31 = v5;
        if ( v37 <= -1 )
        {
LABEL_70:
          CAI_BaseNPC::SetIdealActivity(this: v31, NewActivity: ACT_IDLE);
        }
        else
        {
          CAI_BaseNPC::SetSequenceById(this: v5, iSequence: v37);
          CAI_BaseNPC::SetIdealActivity(this: v5, NewActivity: ACT_DO_NOT_DISTURB);
        }
      }
      else
      {
        v35 = v5->GetHintActivity(this: v5, a2: v34->m_NodeData.nHintType, a3: (Activity)v33);
        CAI_BaseNPC::SetIdealActivity(this: v5, NewActivity: v35);
      }
      return;
    case 0x46:
      if ( CHandle<CBaseEntity>::operator!=(this: &this->m_hTargetEnt, val: nullptr) )
      {
        flRange = *(float *)&v5->m_pMotor;
        v52 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
        v53 = CBaseEntity::GetAbsOrigin(this: v52);
        CAI_Motor::SetIdealYawToTarget(this: (CAI_Motor *)LODWORD(flRange), target: v53, noise: 0.0, offset: 0.0);
LABEL_97:
        v5->SetTurnActivity(this: v5);
      }
      else
      {
LABEL_206:
        v5->TaskFail(this: v5, a2: 1);
      }
      return;
    case 0x47:
      CAI_Motor::SetIdealYawToTarget(this: this->m_pMotor, target: &this->m_vecLastPosition, noise: 0.0, offset: 0.0);
      goto LABEL_95;
    case 0x48:
      CAI_Motor::SetIdealYawToTarget(this: this->m_pMotor, target: &this->m_vSavePosition, noise: 0.0, offset: 0.0);
      goto LABEL_95;
    case 0x49:
      CAI_Motor::SetIdealYawToTarget(this: this->m_pMotor, target: &this->m_vSavePosition, noise: 0.0, offset: 180.0);
      goto LABEL_95;
    case 0x4A:
      this->m_pMotor->m_IdealYaw = (float)(unsigned __int16)(int)(float)(this->m_angRotation.m_Value.y * 182.04445)
                                 * 0.0054931641;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x4B:
      this->m_flLastAttackTime = gpGlobals->curtime;
      CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_RANGE_ATTACK1);
      return;
    case 0x4C:
      this->m_flLastAttackTime = gpGlobals->curtime;
      CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_RANGE_ATTACK2);
      return;
    case 0x4D:
      this->m_flLastAttackTime = gpGlobals->curtime;
      CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_MELEE_ATTACK1);
      return;
    case 0x4E:
      this->m_flLastAttackTime = gpGlobals->curtime;
      CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_MELEE_ATTACK2);
      return;
    case 0x4F:
      CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_RELOAD);
      return;
    case 0x50:
      CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_SPECIAL_ATTACK1);
      return;
    case 0x51:
      CAI_BaseNPC::ResetIdealActivity(this, newIdealActivity: ACT_SPECIAL_ATTACK2);
      return;
    case 0x52:
    case 0x53:
      if ( CBasePlayer::GetVehicleEntity(this) == nullptr )
      {
        Hint = CAI_HintManager::FindHint(
                 pNPC: v5,
                 nHintType: HINT_NONE,
                 nFlags: (int)pTask->flTaskData,
                 flMaxDist: 2000.0,
                 pMaxDistFrom: nullptr);
        CAI_BaseNPC::SetHintNode(this: v5, pHintNode: Hint);
      }
      if ( CBasePlayer::GetVehicleEntity(this: v5) != nullptr )
        CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      else
        v5->TaskFail(this: v5, a2: 4);
      if ( LODWORD(flDistZ) != 82 )
        goto $LN366;
      return;
    case 0x54:
      CAI_BaseNPC::ClearHintNode(this, reuseDelay: pTask->flTaskData);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x55:
$LN366:
      if ( CBasePlayer::GetVehicleEntity(this: v5) == nullptr )
      {
LABEL_19:
        v5->TaskFail(this: v5, a2: 4);
        return;
      }
      v7 = CBasePlayer::GetVehicleEntity(this: v5);
      v8 = CAI_Hint::Lock(this: v7, pNPC: v5);
      this = v5;
      if ( v8 )
        goto $LN375;
      v5->TaskFail(this: v5, a2: 16);
      v5->m_pHintNode.m_Index = -1;
      return;
    case 0x56:
      _DevMsg(a1: 2, a2: "SOUND\n");
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x58:
      this->IdleSound(this);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x59:
      this->AlertSound(this);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x5A:
      CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)v268);
      v5->PainSound(this: v5, a2: (const CTakeDamageInfo *)v268);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x5B:
      CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)v268);
      v5->DeathSound(this: v5, a2: (const CTakeDamageInfo *)v268);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x5C:
      this->SpeakSentence(this, a2: (int)pTask->flTaskData);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x5D:
      if ( this->GetExpresser(this) == nullptr )
        goto LABEL_5;
      GetExpresser = v5->GetExpresser;
      if ( pTask->flTaskData != 0.0 )
      {
        v212 = GetExpresser(this: v5);
        if ( CAI_Expresser::CanSpeakAfterMyself(this: v212) )
LABEL_369:
          CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
        return;
      }
      v213 = (int)GetExpresser(this: v5);
      HasCondition = (*(int (__thiscall **)(int))(*(_DWORD *)v213 + 16))(a1: v213);
LABEL_124:
      if ( HasCondition == 0 )
        goto LABEL_125;
      return;
    case 0x5E:
      if ( (int)pTask->flTaskData != 0 )
        goto LABEL_140;
      this->m_Activity = ACT_RESET;
      return;
    case 0x5F:
      flRange = CBaseAnimating::GetPlaybackRate(this);
      flRange = ((double (__thiscall *)(IUniformRandomStream *, unsigned int, _DWORD))random->RandomFloat)(
                  a1: random,
                  a2: COERCE_UNSIGNED_INT(pTask->flTaskData * 0.0099999998) ^ (unsigned int)_mask__NegFloat_,
                  a3: pTask->flTaskData * 0.0099999998)
              * flRange
              + flRange;
      CBaseAnimating::SetPlaybackRate(this: v5, rate: flRange);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x60:
      if ( CAI_BaseNPC::SetSchedule(this, localScheduleID: (int)pTask->flTaskData) == 0 )
        v5->TaskFail(this: v5, a2: 5);
      return;
    case 0x61:
      this->m_failSchedule = (int)pTask->flTaskData;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x62:
      CAI_Navigator::SetGoalTolerance(this: this->m_pNavigator, tolerance: (float)(int)pTask->flTaskData);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x63:
      this->m_pNavigator->m_timePathRebuildMax = (float)(int)pTask->flTaskData;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x64:
      this->m_failSchedule = 0;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
LABEL_140:
      CAI_BaseNPC::SetIdealActivity(this, NewActivity: (Activity)pTask->flTaskData);
      return;
    case 0x6B:
    case 0x6E:
    case 0x6F:
    case 0x70:
      LOBYTE(flRange) = LODWORD(flDistZ) != 107;
      if ( LODWORD(flDistZ) == 112 )
        v42 = pTask->flTaskData;
      else
        v42 = 0.0;
      v43 = v42;
      if ( LODWORD(flDistZ) == 111 )
        v44 = pTask->flTaskData;
      else
        v44 = 3.4028235e38;
      if ( !CAI_BaseNPC::FindCoverFromEnemy(this, bNodesOnly: SLOBYTE(flRange), flMinDistance: v43, flMaxDistance: v44) )
        goto LABEL_89;
      if ( LODWORD(flDistZ) != 107 )
        goto LABEL_125;
      v5->m_flMoveWaitFinished = gpGlobals->curtime + pTask->flTaskData;
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x6D:
      if ( ((int (__thiscall *)(CAI_BaseNPC *, _DWORD, Vector *))this->GetEnemy_2)(a1: this, a2: LODWORD(a3), a3: a4) == 0 )
        goto LABEL_245;
      if ( !CAI_TacticalServices::FindBackAwayPos(
              this: v5->m_pTacticalServices,
              vecThreat: &v5->m_vSavePosition,
              pResult: (Vector *)((char *)&vecNodePos + 4)) )
      {
        v5->TaskFail(this: v5, a2: 7);
        return;
      }
      v38 = v5->m_pNavigator->__vftable;
      flRange = *(float *)&v5->m_pNavigator;
      v39 = AI_NavGoal_t::AI_NavGoal_t(
              this: &v260,
              dest: (const Vector *)((char *)&vecNodePos + 4),
              activity: ACT_RUN,
              tolerance: -1.0,
              flags: 0,
              pTarget: AIN_DEF_TARGET_8);
      v40 = ((int (__thiscall *)(float, AI_NavGoal_t *))v38->SetGoal)(a1: COERCE_FLOAT(LODWORD(flRange)), a2: v39);
      this = v5;
      if ( v40 != 0 )
        goto $LN375;
      v41 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
LABEL_78:
      ((void (__cdecl *)(int))v41->TaskFail)(a1: 11);
      return;
    case 0x71:
      v45 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      flRange = *(float *)&this->m_pTacticalServices;
      flDeltaYawa = ((double (__thiscall *)(CAI_BaseNPC *, char *))v45->CoverRadius)(
                      a1: this,
                      a2: (char *)&vecNodePos + 4);
      v46 = (const Vector *)((int (__thiscall *)(CAI_BaseNPC *))v5->EyePosition)(a1: v5);
      if ( CAI_TacticalServices::FindCoverPos(
             this: (CAI_TacticalServices *)LODWORD(flRange),
             vThreatPos: &v5->m_vecOrigin.m_Value,
             vThreatEyePos: v46,
             flMinDist: COERCE_FLOAT(&v273),
             flMaxDist: 0.0,
             pResult: (Vector *)LODWORD(flDeltaYawa)) )
      {
        AI_NavGoal_t::AI_NavGoal_t(
          this: (AI_NavGoal_t *)&v279,
          dest: (const Vector *)((char *)&vecNodePos + 4),
          activity: ACT_RUN,
          tolerance: -2.0,
          flags: 0,
          pTarget: AIN_DEF_TARGET_8);
        v5->m_pNavigator->SetGoal(this: v5->m_pNavigator, a2: (const AI_NavGoal_t *)&v279, a3: 0);
        v5->m_flMoveWaitFinished = gpGlobals->curtime + pTask->flTaskData;
      }
      else
      {
LABEL_89:
        v5->TaskFail(this: v5, a2: 8);
      }
      return;
    case 0x72:
      CAI_Navigator::StopMoving(this: this->m_pNavigator, bImmediate: true);
      v209 = v5->GetDeathActivity(this: v5);
      CAI_BaseNPC::SetIdealActivity(this: v5, NewActivity: v209);
      p_m_lifeState = &v5->m_lifeState;
      if ( p_m_lifeState->m_Value != 1 )
      {
        (*(void (__thiscall **)(char *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_lifeState> *))(*(_DWORD *)&p_m_lifeState[-553].m_Value + 748))(
          a1: &p_m_lifeState[-553].m_Value,
          a2: p_m_lifeState);
        p_m_lifeState->m_Value = 1;
      }
      return;
    case 0x73:
      if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hCine) )
        goto LABEL_372;
      return;
    case 0x74:
      if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hCine) )
      {
LABEL_372:
        DevMsg(a1: "Scripted sequence destroyed while in use\n");
        v5->TaskFail(this: v5, a2: 5);
      }
      else
      {
        v214 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine);
        p_m_hCine = (CHandle<CBaseEntity> *)&v5->m_hCine;
        if ( v214[1].__vftable != nullptr )
        {
          m_pfnThink = (const char *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hCine)[1].__vftable;
        }
        else
        {
          v217 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hCine);
          v218 = (CHandle<CBaseEntity> *)&v5->m_hCine;
          if ( v217[1].m_pfnThink != nullptr )
          {
            m_pfnThink = (const char *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v218)[1].m_pfnThink;
          }
          else if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v218)[1].m_Network.__vftable != nullptr )
          {
            m_pfnThink = (const char *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine)[1].m_Network.__vftable;
          }
          else
          {
            m_pfnThink = nullptr;
          }
        }
        v5->m_ScriptArrivalActivity = ACT_INVALID;
        v5->m_strScriptArrivalSequence.pszValue = nullptr;
        if ( m_pfnThink != nullptr
          && (v219 = CAI_BaseNPC::GetActivityID(actName: m_pfnThink), v5->m_ScriptArrivalActivity = v219, v219 == -1) )
        {
          v5->m_strScriptArrivalSequence.pszValue = m_pfnThink;
          CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
        }
        else
        {
LABEL_125:
          this = v5;
LABEL_113:
          CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
        }
      }
      return;
    case 0x75:
      CAI_Navigator::IgnoreStoppingPath(this: this->m_pNavigator);
      if ( CBaseAnimating::HasMovement(this: v5, iSequence: v5->m_nSequence.m_Value)
        || HIBYTE(CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine)[1].m_Network.m_PVSInfo.m_pClusters) != 0 )
      {
        CBaseEntity::AddFlag(this: v5, flags: 2048);
        CBaseEntity::SetGroundEntity(this: v5, ground: nullptr);
      }
      if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine) != nullptr )
      {
        v220 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine);
        CAI_ScriptedSequence::SynchronizeSequence(this: v220, pNPC: v5);
      }
      v5->m_scriptState = SCRIPT_PLAYING;
      return;
    case 0x76:
      this->m_scriptState = SCRIPT_POST_IDLE;
      return;
    case 0x77:
      if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCine)[1].m_pfnMoveDone != nullptr )
      {
        flMaxDista = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine)[1].m_pfnMoveDone;
        v222 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine);
        CAI_ScriptedSequence::StartSequence(
          this: v222,
          pTarget: v5,
          iszSeq: (string_t)flMaxDista,
          completeOnEmpty: false);
        flRange = *(float *)&CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine)[1].m_pfnThink;
        if ( flRange == 0.0 )
          flRange = COERCE_FLOAT(locale);
        m_pfnMoveDone = (const char *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine)[1].m_pfnMoveDone;
        if ( m_pfnMoveDone == nullptr )
          m_pfnMoveDone = locale;
        if ( FStrEq(sz1: m_pfnMoveDone, sz2: (const char *)LODWORD(flRange)) )
        {
$LN8_3:
          if ( v5->m_flPlaybackRate.m_Value != 0.0 )
          {
            if ( v5->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v5->m_Network + 76) |= 1u;
            }
            else
            {
              v240 = &v5->m_Network.m_pPev->CBaseEdict;
              if ( v240 != nullptr )
                CBaseEdict::StateChanged(this: v240, offset: 0x37Cu);
            }
            v5->m_flPlaybackRate.m_Value = 0.0;
          }
        }
      }
      else if ( v5->m_scriptState != SCRIPT_CUSTOM_MOVE_TO_MARK )
      {
        m_IdealActivity = v5->m_IdealActivity;
        if ( m_IdealActivity == ACT_WALK
          || m_IdealActivity == ACT_RUN
          || m_IdealActivity == ACT_WALK_AIM
          || m_IdealActivity == ACT_RUN_AIM )
        {
          v5->SetActivity(this: v5, a2: ACT_IDLE);
        }
      }
      return;
    case 0x78:
      if ( !CHandle<CBaseEntity>::operator!=(this: &this->m_hTargetEnt, val: nullptr) )
        goto LABEL_125;
      v225 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
      v226 = CBaseEntity::GetAbsOrigin(this: v225);
      CBaseEntity::SetLocalOrigin(this: v5, origin: v226);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x79:
      if ( CHandle<CBaseEntity>::operator!=(this: &this->m_hTargetEnt, val: nullptr) )
        v5->m_pMotor->m_IdealYaw = (float)(unsigned __int16)(int)(float)(CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt)->m_angRotation.m_Value.y
                                                                       * 182.04445)
                                 * 0.0054931641;
      if ( v5->m_scriptState != SCRIPT_CUSTOM_MOVE_TO_MARK )
      {
        v5->SetTurnActivity(this: v5);
        v5->SetActivity(this: v5, a2: v5->m_IdealActivity);
      }
      CAI_Navigator::StopMoving(this: v5->m_pNavigator, bImmediate: true);
      return;
    case 0x7D:
      if ( CAI_Navigator::IsGoalSet(this: this->m_pNavigator) && CAI_Navigator::IsGoalActive(this: v5->m_pNavigator)
        || CAI_BaseNPC::GetNavType(this: v5) == NAV_JUMP )
      {
        m_pParent = ai_debug_nav.m_pParent;
        if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
        {
          v22 = CFmtStrN<256>::CFmtStrN<256>(this: &v257, pszFormat: "[Nav] %s", "Start TASK_STOP_MOVING\n");
          DevMsg(pAI: v5, pszFormat: v22->m_szBuf);
          m_pParent = ai_debug_nav.m_pParent;
        }
        if ( pTask->flTaskData == 1.0 )
        {
          if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
          {
            v23 = CFmtStrN<256>::CFmtStrN<256>(this: &v255, pszFormat: "[Nav] %s", "Initiating stopping path\n");
            DevMsg(pAI: v5, pszFormat: v23->m_szBuf);
          }
          CAI_Navigator::StopMoving(this: v5->m_pNavigator, bImmediate: false);
        }
        else
        {
          CAI_Navigator::ClearGoal(this: v5->m_pNavigator);
        }
        m_poseMove_Yaw = v5->m_poseMove_Yaw;
        if ( m_poseMove_Yaw >= 0 )
          CBaseAnimating::SetPoseParameter(this: v5, iParameter: m_poseMove_Yaw, flValue: 0.0);
      }
      else if ( pTask->flTaskData == 1.0 && CAI_Navigator::SetGoalFromStoppingPath(this: v5->m_pNavigator) )
      {
        v25 = ai_debug_nav.m_pParent;
        if ( ai_debug_nav.m_pParent != nullptr )
        {
          if ( ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
          {
            v26 = CFmtStrN<256>::CFmtStrN<256>(this: &v256, pszFormat: "[Nav] %s", "Start TASK_STOP_MOVING\n");
            DevMsg(pAI: v5, pszFormat: v26->m_szBuf);
            v25 = ai_debug_nav.m_pParent;
          }
          if ( v25 != nullptr && v25->m_Value.m_nValue != 0 )
          {
            v27 = CFmtStrN<256>::CFmtStrN<256>(this: &v254, pszFormat: "[Nav] %s", "Initiating stopping path\n");
            DevMsg(pAI: v5, pszFormat: v27->m_szBuf);
          }
        }
      }
      else
      {
        CAI_Navigator::ClearGoal(this: v5->m_pNavigator);
        StoppedActivity = CAI_BaseNPC::GetStoppedActivity(this: v5);
        CAI_BaseNPC::SetIdealActivity(this: v5, NewActivity: StoppedActivity);
        CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      }
      return;
    case 0x7E:
      CAI_BaseNPC::StartTurn(this, flDeltaYaw: pTask->flTaskData);
      return;
    case 0x7F:
      CAI_BaseNPC::StartTurn(this, flDeltaYaw: COERCE_FLOAT(LODWORD(pTask->flTaskData) ^ _mask__NegFloat_));
      return;
    case 0x80:
      this->m_afMemory |= (int)pTask->flTaskData;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x81:
      this->m_afMemory &= ~(int)pTask->flTaskData;
      CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
      return;
    case 0x82:
      if ( this->IsMovementFrozen(this) )
        goto LABEL_347;
      if ( CAI_Navigator::GetGoalType(this: v5->m_pNavigator) == GOALTYPE_NONE )
      {
LABEL_122:
        CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
        CAI_Navigator::ClearGoal(this: v5->m_pNavigator);
        return;
      }
      IsGoalActive = CAI_Navigator::IsGoalActive(this: v5->m_pNavigator);
      this = v5;
      if ( IsGoalActive )
        goto LABEL_350;
      v206 = CAI_BaseNPC::GetStoppedActivity(this: v5);
      CAI_BaseNPC::SetIdealActivity(this: v5, NewActivity: v206);
      return;
    case 0x83:
      if ( this->IsMovementFrozen(this) )
      {
LABEL_347:
        v5->TaskFail(this: v5, a2: 28);
      }
      else
      {
        v203 = CAI_Navigator::IsGoalActive(this: v5->m_pNavigator);
        this = v5;
        if ( !v203 || (v204 = v5->IsActivityFinished(this: v5), this = v5, v204) )
$LN375:
          CAI_BaseNPC::TaskComplete(this, fIgnoreSetFailedCondition: false);
        else
LABEL_350:
          v5->ValidateNavGoal(this);
      }
      return;
    case 0x84:
      HasCondition = CAI_BaseNPC::HasCondition(this, iCondition: 50);
      goto LABEL_124;
    case 0x85:
      v278.x = 1000.0;
      v278.y = 1000.0;
      v278.z = 1000.0;
      Usable = CBaseCombatCharacter::Weapon_FindUsable(this, range: &v278);
      CHandle<CBaseEntity>::operator=(this: &v5->m_hTargetEnt, val: Usable);
      v229 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &v5->m_hTargetEnt);
      this = v5;
      if ( v229 != nullptr )
        goto $LN375;
      v5->TaskFail(this: v5, a2: 3);
      return;
    case 0x86:
      if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
      {
        v230 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v5);
        v230->Weapon_Drop(this: v5, a2: ActiveWeapon, a3: nullptr, a4: nullptr);
      }
      if ( CAI_BaseNPC::GetTarget(this: v5) != nullptr
        && (Target = CAI_BaseNPC::GetTarget(this: v5), (v233 = ToBaseCombatWeapon(pEntity: Target)) != nullptr) )
      {
        v234 = CBaseCombatCharacter::Weapon_IsOnGround(this: v5, pWeapon: v233);
        this = v5;
        if ( v234 )
$LN24:
          CAI_BaseNPC::SetIdealActivity(this, NewActivity: ACT_PICKUP_GROUND);
        else
          CAI_BaseNPC::SetIdealActivity(this: v5, NewActivity: ACT_PICKUP_RACK);
      }
      else
      {
        v5->TaskFail(this: v5, a2: (int)"Weapon went away!\n");
      }
      return;
    case 0x88:
      if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr && CAI_BaseNPC::GetTarget(this: v5) != nullptr )
      {
        v235 = CAI_BaseNPC::GetTarget(this: v5);
        v236 = ToBaseCombatWeapon(pEntity: v235);
        if ( v236 != nullptr )
        {
          v237 = v236->m_iClassname.pszValue;
          if ( v237 == nullptr )
            v237 = locale;
          v238 = CBaseCombatCharacter::Weapon_Create(this: v5, pWeaponName: v237);
          if ( v238 != nullptr )
            v5->Weapon_Equip(this: v5, a2: v238);
        }
      }
      CAI_BaseNPC::SetTarget(this: v5, pTarget: nullptr);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x89:
      goto $LN24;
    case 0x8B:
      CAI_BaseNPC::SetHullSizeSmall(this, force: false);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x8C:
      CAI_BaseNPC::SetWait(this, minWait: 4.0, maxWait: 0.0);
      return;
    case 0x8D:
      v239 = CAI_Navigator::SetWanderGoal(
               this: this->m_pNavigator,
               minRadius: (float)((int)pTask->flTaskData / 10000),
               maxRadius: (float)((int)pTask->flTaskData % 10000));
      this = v5;
      if ( v239 )
        goto $LN375;
LABEL_308:
      v5->TaskFail(this, a2: 22);
      return;
    case 0x8E:
      goto $LN8_3;
    case 0x8F:
      this->GatherConditions(this);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x90:
      v241 = (int (*)(void))this->GetEnemy_2;
      this->m_flAcceptableTimeSeenEnemy = gpGlobals->curtime;
      if ( v241() == 0 || (double)v5->m_flAcceptableTimeSeenEnemy <= CAI_BaseNPC::GetEnemyLastTimeSeen(this: v5) )
        goto LABEL_125;
      v242 = v5->BestEnemy(this: v5);
      LODWORD(vec2RightSide.y) = 1;
      if ( v242 != nullptr )
      {
        CAI_BaseNPC::SetEnemy(this: v5, pEnemy: v242, bSetCondNewEnemy: SLOBYTE(vec2RightSide.y));
        CAI_BaseNPC::SetState(this: v5, State: NPC_STATE_COMBAT);
      }
      else
      {
        CAI_BaseNPC::SetEnemy(this: v5, pEnemy: nullptr, bSetCondNewEnemy: SLOBYTE(vec2RightSide.y));
        v5->ClearAttackConditions(this: v5);
      }
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x92:
      ((void (__cdecl *)(_DWORD, _DWORD))this->TakeHealth)(a1: (float)(int)pTask->flTaskData, a2: 0);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x93:
      v29 = CBaseAnimatingOverlay::AddGesture(this, activity: (Activity)pTask->flTaskData, autokill: true);
      if ( v29 <= 0 )
      {
        v5->TaskFail(this: v5, a2: (int)"Unable to allocate gesture");
      }
      else
      {
        flRange = CBaseAnimatingOverlay::GetLayerDuration(this: v5, iLayer: v29);
        CAI_BaseNPC::SetWait(this: v5, minWait: flRange, maxWait: 0.0);
      }
      return;
    case 0x94:
      CBaseAnimatingOverlay::AddGesture(this, activity: (Activity)pTask->flTaskData, autokill: true);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    case 0x95:
      if ( CHandle<CAI_BaseNPC>::operator!(this: &this->m_hForcedInteractionPartner) )
        goto LABEL_148;
      v75 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hForcedInteractionPartner);
      if ( v5->IsUnreachable(this: v5, a2: v75) )
        goto LABEL_148;
      CAI_BaseNPC::CalculateForcedInteractionPosition(this: v5);
      AI_NavGoal_t::AI_NavGoal_t(
        this: (AI_NavGoal_t *)&v279,
        dest: &v5->m_vecForcedWorldPosition,
        activity: ACT_INVALID,
        tolerance: -1.0,
        flags: 0,
        pTarget: AIN_DEF_TARGET_8);
      v76 = v5->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v77 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hForcedInteractionPartner);
      v76->TranslateNavGoal(this: v5, a2: v77, a3: (Vector *)&v280);
      if ( v5->m_pNavigator->SetGoal(this: v5->m_pNavigator, a2: (const AI_NavGoal_t *)&v279, a3: 2u) )
        goto LABEL_5;
      _DevWarning(a1: 2, a2: "GetPathToInteractionPartner failed!!\n");
      v78 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hForcedInteractionPartner);
      CAI_BaseNPC::RememberUnreachable(this: v5, pEntity: v78, duration: -1.0);
      v5->TaskFail(this: v5, a2: 11);
      return;
    case 0x96:
      if ( ai_task_pre_script.m_pParent == nullptr || ai_task_pre_script.m_pParent->m_Value.m_nValue == 0 )
        goto $LN375;
      if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hCine) )
        goto LABEL_5;
      v221 = (CAI_ScriptedSequence *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v5->m_hCine);
      CAI_ScriptedSequence::DelayStart(this: v221, bDelay: true);
      CAI_BaseNPC::TaskComplete(this: v5, fIgnoreSetFailedCondition: false);
      return;
    default:
      v243 = this->TaskName(this, a2: LODWORD(flDistZ));
      DevMsg(a1: "No StartTask entry for %s\n", v243);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040D40
// Name: protected: virtual void CAI_BaseNPC::RunDieTask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseNPC::RunDieTask(CAI_BaseNPC *this)
{
  edict_t *m_pPev; // ecx
  const Vector *v3; // ebx
  const Vector *v4; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v5; // edx
  float *v6; // eax
  float y; // xmm1_4
  float v8; // xmm0_4
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  const Vector *v10; // eax
  Vector vecMin; // [esp+14h] [ebp-1Ch] BYREF
  Vector vecMax; // [esp+20h] [ebp-10h] BYREF
  const Vector *v13; // [esp+2Ch] [ebp-4h]
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  CAI_BaseNPC::AutoMovement(this, pTarget: nullptr, pTraceResult: nullptr);
  if ( this->IsActivityFinished(this) && this->m_flCycle.m_Value >= 1.0 )
  {
    if ( this->m_lifeState.m_Value != 2 )
    {
      this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
      this->m_lifeState.m_Value = 2;
    }
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    if ( this->m_flPlaybackRate.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flPlaybackRate.m_Value = 0.0;
    }
    if ( CAI_BaseNPC::BBoxFlat(this, a2: COERCE_FLOAT(&savedregs)) )
    {
      v3 = this->m_Collision.OBBMins(this: &this->m_Collision);
      v4 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
      v5 = this->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
      v13 = v4;
      v6 = (float *)v5->OBBMaxs(this: &this->m_Collision);
      y = v13->y;
      v8 = v3->z + 1.0;
      OBBMins = this->m_Collision.OBBMins;
      vecMin.x = *v6;
      vecMin.y = y;
      vecMin.z = v8;
      v10 = OBBMins(this: &this->m_Collision);
      UTIL_SetSize(pEnt: this, vecMin: v10, vecMax: &vecMin);
    }
    else
    {
      vecMax.x = 4.0;
      vecMax.y = 4.0;
      vecMax.z = 1.0;
      vecMin.x = -4.0;
      vecMin.y = -4.0;
      vecMin.z = 0.0;
      UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
    }
  }
}
