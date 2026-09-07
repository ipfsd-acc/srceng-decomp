// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_behavior.cpp
// Functions: 14
// ============================================================

#include "game\server\ai_behavior.h"

//------------------------------------------------------------------------------
// Address: 0x10041270
// Name: public: static void CAI_BehaviorBase::SaveBehaviors(class ISave __near &,class CAI_BehaviorBase __near *,class CAI_BehaviorBase __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_BehaviorBase::SaveBehaviors(
        ISave *save,
        CAI_BehaviorBase *pCurrentBehavior,
        CAI_BehaviorBase **ppBehavior,
        int nBehaviors,
        bool bTestIfNPCSave)
{
  ISave *v5; // esi
  void (__thiscall *WriteShort_2)(ISave *, const __int16 *, int); // edx
  int v7; // edi
  void (__thiscall *v8)(ISave *, const __int16 *, int); // edx
  int v9; // ebx
  ISave_vtbl *v10; // edi
  datamap_t *v11; // eax
  CAI_BehaviorBase **v12; // edi
  void (__thiscall *WriteBool_2)(ISave *, const bool *, int); // edx
  const char *v14; // eax
  int temp; // [esp+Ch] [ebp-4h] BYREF

  v5 = save;
  save->StartBlock_2(this: save, a2: "AI_Behaviors");
  WriteShort_2 = v5->WriteShort_2;
  temp = 2;
  WriteShort_2(this: v5, a2: (const __int16 *)&temp, a3: 1);
  v7 = nBehaviors;
  v8 = v5->WriteShort_2;
  temp = (unsigned __int16)nBehaviors;
  v8(this: v5, a2: (const __int16 *)&temp, a3: 1);
  v9 = 0;
  if ( v7 > 0 )
  {
    do
    {
      if ( !bTestIfNPCSave || ppBehavior[v9]->ShouldNPCSave(this: ppBehavior[v9]) )
      {
        if ( strcmp(
               ppBehavior[v9]->GetDataDescMap(this: ppBehavior[v9])->dataClassName,
               CAI_BehaviorBase::m_DataMap.dataClassName) == 0 )
        {
          v14 = ppBehavior[v9]->GetName(this: ppBehavior[v9]);
          DevMsg(a1: "Note: behavior \"%s\" lacks a datadesc and probably won't save/restore correctly\n", v14);
        }
        else
        {
          v5->StartBlock(this: v5);
          v10 = v5->__vftable;
          v11 = ppBehavior[v9]->GetDataDescMap(this: ppBehavior[v9]);
          v10->WriteString_4(this: v5, a2: v11->dataClassName);
          v12 = ppBehavior;
          WriteBool_2 = v5->WriteBool_2;
          HIBYTE(save) = pCurrentBehavior == ppBehavior[v9];
          WriteBool_2(this: v5, a2: (const bool *)&save + 3, a3: 1);
          v12[v9]->Save(this: v12[v9], a2: v5);
          v5->EndBlock(this: v5);
        }
      }
      ++v9;
    }
    while ( v9 < nBehaviors );
  }
  v5->EndBlock(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100413C0
// Name: public: static int CAI_BehaviorBase::RestoreBehaviors(class IRestore __near &,class CAI_BehaviorBase __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CAI_BehaviorBase::RestoreBehaviors(
        IRestore *restore,
        CAI_BehaviorBase **ppBehavior,
        int nBehaviors,
        bool bTestIfNPCSave)
{
  IRestore *v4; // ebx
  void (__thiscall *StartBlock_2)(IRestore *, char *); // edx
  int j; // edi
  char szClassNameCurrent[256]; // [esp+4h] [ebp-130h] BYREF
  char szBlockName[32]; // [esp+104h] [ebp-30h] BYREF
  int iCurrent; // [esp+124h] [ebp-10h]
  int i; // [esp+128h] [ebp-Ch]
  __int16 version; // [esp+12Ch] [ebp-8h] BYREF
  __int16 nToRestore; // [esp+130h] [ebp-4h] BYREF

  v4 = restore;
  StartBlock_2 = restore->StartBlock_2;
  iCurrent = -1;
  StartBlock_2(this: restore, a2: szBlockName);
  if ( strcmp(szBlockName, "AI_Behaviors") == 0 )
  {
    v4->ReadShort(this: v4, a2: &version, a3: 1, a4: 0);
    if ( version == 2 )
    {
      v4->ReadShort(this: v4, a2: &nToRestore, a3: 1, a4: 0);
      for ( i = 0; i < nToRestore; ++i )
      {
        v4->StartBlock(this: v4);
        v4->ReadString_2(this: v4, a2: szClassNameCurrent, a3: 256, a4: 0);
        v4->ReadBool(this: v4, a2: (bool *)&restore + 3, a3: 1, a4: 0);
        for ( j = 0; j < nBehaviors; ++j )
        {
          if ( (!bTestIfNPCSave || ppBehavior[j]->ShouldNPCSave(this: ppBehavior[j]))
            && strcmp(ppBehavior[j]->GetDataDescMap(this: ppBehavior[j])->dataClassName, szClassNameCurrent) == 0 )
          {
            if ( HIBYTE(restore) != 0 )
              iCurrent = j;
            ppBehavior[j]->Restore(this: ppBehavior[j], a2: v4);
          }
        }
        v4->EndBlock(this: v4);
      }
    }
  }
  v4->EndBlock(this: v4);
  return iCurrent;
}

//------------------------------------------------------------------------------
// Address: 0x10041550
// Name: private: class CAI_Schedule __near * CAI_BehaviorBase::GetFailSchedule(struct AIChannelScheduleState_t __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_BehaviorBase::GetFailSchedule(
        CAI_BehaviorBase *this,
        AIChannelScheduleState_t *pScheduleState)
{
  CAI_Schedule *pSchedule; // eax
  int m_iScheduleID; // edi
  CAI_ClassScheduleIdSpace *v5; // eax
  int v6; // eax
  CAI_Schedule *v7; // ecx
  int iCurTask; // edx
  int *p_iTask; // ecx
  int v10; // ecx
  int v11; // eax

  pSchedule = pScheduleState->pSchedule;
  if ( pSchedule != nullptr )
  {
    m_iScheduleID = pSchedule->m_iScheduleID;
    v5 = this->GetClassScheduleIdSpace(this);
    v6 = CAI_LocalIdSpace::GlobalToLocal(this: &v5->m_ScheduleIds, globalID: m_iScheduleID);
  }
  else
  {
    v6 = 0;
  }
  v7 = pScheduleState->pSchedule;
  iCurTask = pScheduleState->iCurTask;
  if ( v7 != nullptr
    && iCurTask >= 0
    && iCurTask < v7->m_iNumTasks
    && (p_iTask = &v7->m_pTaskList[iCurTask].iTask) != nullptr )
  {
    v10 = *p_iTask;
  }
  else
  {
    v10 = 0;
  }
  v11 = this->SelectFailSchedule(this, a2: v6, a3: v10, a4: pScheduleState->taskFailureCode);
  return this->GetSchedule(this, a2: v11);
}

//------------------------------------------------------------------------------
// Address: 0x100415D0
// Name: public: void CAI_BehaviorBase::SetSchedule(int,class CAI_Schedule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorBase::SetSchedule(CAI_BehaviorBase *this, int channel, CAI_Schedule *pNewSchedule)
{
  AIChannelScheduleState_t *v3; // eax
  float curtime; // xmm0_4
  CAI_BaseNPC *m_pOuter; // edi
  const char *v6; // eax
  int v7; // [esp-8h] [ebp-1Ch]
  const char *v8; // [esp-4h] [ebp-18h]
  double v9; // [esp+0h] [ebp-14h]

  if ( channel >= 0 && channel < this->m_ScheduleChannels.m_Size )
  {
    v3 = &this->m_ScheduleChannels.m_Memory.m_pMemory[channel];
    curtime = gpGlobals->curtime;
    v3->timeStarted = curtime;
    v3->timeCurTaskStarted = curtime;
    v3->bScheduleWasInterrupted = false;
    v3->pSchedule = pNewSchedule;
    v3->iCurTask = 0;
    v3->fTaskStatus = TASKSTATUS_NEW;
    v3->failSchedule = 0;
    if ( pNewSchedule != nullptr )
    {
      m_pOuter = this->m_pOuter;
      if ( (m_pOuter->m_debugOverlays & 0x8000000) != 0 )
      {
        v6 = (const char *)((int (__thiscall *)(CAI_BehaviorBase *, int, char *, _DWORD, _DWORD))this->GetName)(
                             a1: this,
                             a2: channel,
                             a3: pNewSchedule->m_pName,
                             a4: COERCE_UNSIGNED_INT64(gpGlobals->curtime),
                             a5: HIDWORD(COERCE_UNSIGNED_INT64(gpGlobals->curtime)));
        DevMsg(pAI: m_pOuter, flags: 1, pszFormat: "Behavior %s channel %d Schedule: %s (time: %.2f)\n", v6, v7, v8, v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041670
// Name: public: struct Task_t const __near * CAI_BehaviorBase::GetCurTask(int)
// Source: json
//------------------------------------------------------------------------------
const Task_t *__thiscall CAI_BehaviorBase::GetCurTask(CAI_BehaviorBase *this, int channel)
{
  AIChannelScheduleState_t *v2; // eax
  int iCurTask; // ecx
  CAI_Schedule *pSchedule; // eax

  if ( channel >= 0
    && channel < this->m_ScheduleChannels.m_Size
    && (v2 = &this->m_ScheduleChannels.m_Memory.m_pMemory[channel],
        iCurTask = v2->iCurTask,
        (pSchedule = v2->pSchedule) != nullptr)
    && iCurTask >= 0
    && iCurTask < pSchedule->m_iNumTasks )
  {
    return &pSchedule->m_pTaskList[iCurTask];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041830
// Name: protected: bool CAI_BehaviorBase::NotifyChangeBehaviorStatus(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorBase::NotifyChangeBehaviorStatus(CAI_BehaviorBase *this, BOOL fCanFinishSchedule)
{
  bool v3; // bl
  bool result; // al
  CAI_BaseNPC *m_pOuter; // edi
  unsigned int m_Index; // eax
  unsigned int v7; // eax
  IHandleEntity *m_pEntity; // ecx
  bool v9; // zf
  CHandle<CBaseEntity> *p_m_hCine; // ecx
  CBaseEntity *v11; // eax
  CBaseEntity *v12; // eax
  unsigned int v13; // eax
  CAI_ScriptedSequence *v14; // ecx
  const char *v15; // [esp-Ch] [ebp-14h]
  const char *v16; // [esp-Ch] [ebp-14h]
  const char *v17; // [esp-8h] [ebp-10h]
  const char *DebugName; // [esp-8h] [ebp-10h]

  v3 = this->m_pOuter->OnBehaviorChangeStatus(this: this->m_pOuter, a2: this, a3: fCanFinishSchedule);
  result = this->m_pOuter->IsInterruptable(this: this->m_pOuter);
  if ( result )
  {
    if ( v3 )
    {
      m_pOuter = this->m_pOuter;
      m_Index = m_pOuter->m_hCine.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v7 = m_pOuter->m_hCine.m_Index;
        if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
        v9 = BYTE1(m_pEntity[232].__vftable) == 0;
        p_m_hCine = (CHandle<CBaseEntity> *)&m_pOuter->m_hCine;
        if ( v9 )
        {
          v12 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hCine);
          DebugName = CBaseEntity::GetDebugName(this: v12);
          v16 = CBaseEntity::GetDebugName(this: m_pOuter);
          DevWarning(a1: "NPC: %s canceled script %s without playing, due to behavior change\n", v16, DebugName);
        }
        else
        {
          v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hCine);
          v17 = CBaseEntity::GetDebugName(this: v11);
          v15 = CBaseEntity::GetDebugName(this: m_pOuter);
          DevWarning(a1: "NPC: %s canceled running script %s due to behavior change\n", v15, v17);
        }
        v13 = this->m_pOuter->m_hCine.m_Index;
        if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
          v14 = nullptr;
        else
          v14 = (CAI_ScriptedSequence *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
        CAI_ScriptedSequence::CancelScript(this: v14);
      }
      CAI_BaseNPC::ClearSchedule(this: this->m_pOuter, szReason: "Changed behavior status");
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10041970
// Name: private: bool CAI_BehaviorBase::IsScheduleValid(struct AIChannelScheduleState_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BehaviorBase::IsScheduleValid(CAI_BehaviorBase *this, AIChannelScheduleState_t *pScheduleState)
{
  CAI_Schedule *pSchedule; // ecx
  int m_iNumTasks; // eax
  CAI_BaseNPC *m_pOuter; // esi
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // ebx
  int v11; // edi
  int v12; // ebx
  int v13; // eax
  const char *v14; // esi
  CAI_BaseNPC *v15; // edi
  int v16; // eax
  const char *v17; // [esp-Ch] [ebp-34h]
  CBitVec<256> testBits; // [esp+4h] [ebp-24h] BYREF
  CAI_BehaviorBase *v19; // [esp+24h] [ebp-4h]

  pSchedule = pScheduleState->pSchedule;
  v19 = this;
  if ( pSchedule == nullptr )
    return 0;
  m_iNumTasks = pSchedule->m_iNumTasks;
  if ( m_iNumTasks == 0 || pScheduleState->iCurTask == m_iNumTasks || pScheduleState->taskFailureCode != 0 )
    return 0;
  memset(&testBits, 0, sizeof(testBits));
  CAI_Schedule::GetInterruptMask(this: pSchedule, pBits: &testBits);
  m_pOuter = this->m_pOuter;
  *(_QWORD *)&testBits.m_Ints[4] &= *(_QWORD *)&m_pOuter->m_Conditions.m_Ints[4];
  testBits.m_Ints[6] &= m_pOuter->m_Conditions.m_Ints[6];
  v7 = m_pOuter->m_Conditions.m_Ints[1] & testBits.m_Ints[1];
  v8 = m_pOuter->m_Conditions.m_Ints[2] & testBits.m_Ints[2];
  v9 = m_pOuter->m_Conditions.m_Ints[3] & testBits.m_Ints[3];
  v10 = m_pOuter->m_Conditions.m_Ints[7] & testBits.m_Ints[7];
  testBits.m_Ints[0] &= m_pOuter->m_Conditions.m_Ints[0];
  testBits.m_Ints[1] = v7;
  testBits.m_Ints[2] = v8;
  testBits.m_Ints[3] = v9;
  testBits.m_Ints[7] = v10;
  if ( testBits.m_Ints[0] == 0
    && v7 == 0
    && v8 == 0
    && v9 == 0
    && testBits.m_Ints[4] == 0
    && testBits.m_Ints[5] == 0
    && testBits.m_Ints[6] == 0
    && v10 == 0 )
  {
    return 1;
  }
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    v11 = 0;
    while ( ((1 << (v11 & 0x1F)) & testBits.m_Ints[v11 >> 5]) == 0 )
    {
      if ( ++v11 >= 256 )
        return 0;
    }
    v12 = pScheduleState - v19->m_ScheduleChannels.m_Memory.m_pMemory;
    if ( v11 == -1 )
      v13 = -1;
    else
      v13 = v11 + 1000000000;
    v14 = m_pOuter->ConditionName(this: m_pOuter, a2: v13);
    if ( v14 == nullptr )
      v14 = "(UNKNOWN CONDITION)";
    v15 = v19->m_pOuter;
    if ( (v15->m_debugOverlays & 0x8000000) != 0 )
    {
      v16 = ((int (__thiscall *)(CAI_BehaviorBase *, int))v19->GetName)(a1: v19, a2: v12);
      DevMsg(pAI: v15, flags: 1, pszFormat: "      Behavior %s channel %d Break condition -> %s\n", v14, v16, v17);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10041D40
// Name: public: void CAI_BehaviorBase::MaintainChannelSchedules(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BehaviorBase::MaintainChannelSchedules(CAI_BehaviorBase *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  AIChannelScheduleState_t *v4; // ebx
  const char *v5; // eax
  CAI_Schedule *FailSchedule; // eax
  int m_iScheduleID; // ecx
  CAI_Schedule *v8; // eax
  const char *m_pName; // ecx
  const char *pszValue; // eax
  CAI_Schedule *v11; // eax
  int v12; // eax
  int v13; // eax
  CAI_Schedule *v14; // eax
  CAI_Schedule *pSchedule; // eax
  int v16; // eax
  int v17; // eax
  const Task_t *CurTask; // eax
  CAI_ClassScheduleIdSpace *v19; // eax
  int v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  TaskStatus_e fTaskStatus; // eax
  CAI_BehaviorBase_vtbl *v24; // ebx
  const Task_t *v25; // eax
  int v26; // [esp-Ch] [ebp-2Ch]
  int v27; // [esp-8h] [ebp-28h]
  const char *v28; // [esp-8h] [ebp-28h]
  const Task_t *v30; // [esp+8h] [ebp-18h]
  int v31; // [esp+Ch] [ebp-14h]
  AIChannelScheduleState_t *v32; // [esp+10h] [ebp-10h]
  CAI_BaseNPC *pAI; // [esp+14h] [ebp-Ch]
  CAI_BaseNPC *pAIa; // [esp+14h] [ebp-Ch]
  CAI_BaseNPC *pAIb; // [esp+14h] [ebp-Ch]
  CAI_BaseNPC *pAIc; // [esp+14h] [ebp-Ch]
  CAI_BaseNPC *pAId; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  char v39; // [esp+1Fh] [ebp-1h]

  v3 = 0;
  if ( this->m_ScheduleChannels.m_Size > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v4 = &this->m_ScheduleChannels.m_Memory.m_pMemory[i];
      v32 = v4;
      if ( v4->bActive )
        break;
LABEL_49:
      if ( ++v3 >= this->m_ScheduleChannels.m_Size )
        return;
    }
    v39 = 0;
    v31 = 0;
    while ( 1 )
    {
      if ( v39 != 0 )
        goto LABEL_49;
      if ( v4->pSchedule != nullptr && v4->fTaskStatus == TASKSTATUS_COMPLETE )
      {
        ++v4->iCurTask;
        v4->fTaskStatus = TASKSTATUS_NEW;
      }
      if ( CAI_BehaviorBase::IsScheduleValid(this, pScheduleState: v4) == 0 )
        break;
LABEL_26:
      if ( v4->pSchedule == nullptr && v3 >= 0 && v3 < this->m_ScheduleChannels.m_Size )
      {
        v13 = this->SelectSchedule_2(this, a2: v3);
        v14 = this->GetSchedule(this, a2: v13);
        if ( v14 != nullptr )
        {
          this->m_ScheduleChannels.m_Memory.m_pMemory[i].idealSchedule = v14->m_iScheduleID;
          CAI_BehaviorBase::SetSchedule(this, channel: v3, pNewSchedule: v14);
        }
      }
      pSchedule = v4->pSchedule;
      if ( pSchedule != nullptr && pSchedule->m_iNumTasks != 0 )
      {
        if ( v4->fTaskStatus == TASKSTATUS_NEW )
        {
          if ( v4->iCurTask == 0 )
          {
            pAIb = (CAI_BaseNPC *)pSchedule->m_iScheduleID;
            v16 = ((int (__thiscall *)(CAI_BehaviorBase *, int))this->GetClassScheduleIdSpace)(a1: this, a2);
            v17 = CAI_LocalIdSpace::GlobalToLocal(this: (CAI_LocalIdSpace *)(v16 + 4), globalID: (int)pAIb);
            if ( v17 == -1 )
              v17 = (int)pAIb;
            a2 = v17;
            ((void (__thiscall *)(CAI_BehaviorBase *, int))this->OnStartSchedule_2)(a1: this, a2: v3);
          }
          CurTask = CAI_BehaviorBase::GetCurTask(this, channel: v3);
          v30 = CurTask;
          if ( (this->m_pOuter->m_debugOverlays & 0x8000000) != 0 )
          {
            pAIc = (CAI_BaseNPC *)CurTask->iTask;
            v19 = this->GetClassScheduleIdSpace(this);
            v20 = CAI_LocalIdSpace::LocalToGlobal(this: &v19->m_TaskIds, localID: (int)pAIc);
            v21 = CAI_GlobalNamespace::IdToSymbol(
                    this: &CAI_BaseNPC::gm_SchedulingSymbols.m_TaskNamespace,
                    symbolID: v20);
            pAId = this->m_pOuter;
            v22 = (const char *)((int (__thiscall *)(CAI_BehaviorBase *, int, const char *))this->GetName)(
                                  a1: this,
                                  a2: v3,
                                  a3: v21);
            DevMsg(pAI: pAId, flags: 1, pszFormat: "  Behavior %s channel %d Task: %s\n", v22, v26, v28);
            CurTask = v30;
          }
          v4->fTaskStatus = TASKSTATUS_RUN_MOVE_AND_TASK;
          v4->taskFailureCode = 0;
          v4->timeCurTaskStarted = gpGlobals->curtime;
          this->StartTask_2(this, a2: v3, a3: CurTask);
        }
        if ( this->m_ScheduleChannels.m_Memory.m_pMemory[i].fTaskStatus != TASKSTATUS_COMPLETE )
        {
          fTaskStatus = v4->fTaskStatus;
          if ( fTaskStatus != TASKSTATUS_NEW )
          {
            if ( fTaskStatus == TASKSTATUS_COMPLETE
              || fTaskStatus == TASKSTATUS_RUN_MOVE
              || v4->taskFailureCode != 0
              || (v24 = this->CAI_Component::__vftable,
                  v25 = CAI_BehaviorBase::GetCurTask(this, channel: v3),
                  v24->RunTask_2(this, a2: v3, a3: v25),
                  v4 = v32,
                  this->m_ScheduleChannels.m_Memory.m_pMemory[i].fTaskStatus != TASKSTATUS_COMPLETE) )
            {
              v39 = 1;
            }
          }
        }
        if ( ++v31 < 10 )
          continue;
      }
      goto LABEL_49;
    }
    v4->bScheduleWasInterrupted = true;
    this->OnScheduleChange(this, a2: v3);
    if ( v4->taskFailureCode != 0 )
    {
      pAI = this->m_pOuter;
      if ( (pAI->m_debugOverlays & 0x8000000) != 0 )
      {
        v5 = (const char *)((int (__thiscall *)(CAI_BehaviorBase *, int))this->GetName)(a1: this, a2: v3);
        DevMsg(pAI, flags: 1, pszFormat: "      Behavior %s channel %d (failed)\n", v5, v27);
      }
      FailSchedule = CAI_BehaviorBase::GetFailSchedule(this, pScheduleState: v4);
      m_iScheduleID = FailSchedule->m_iScheduleID;
      pAIa = (CAI_BaseNPC *)FailSchedule;
      v8 = v4->pSchedule;
      v4->idealSchedule = m_iScheduleID;
      if ( v8 != nullptr )
        m_pName = v8->m_pName;
      else
        m_pName = "GetCurSchedule() == NULL";
      pszValue = this->m_pOuter->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      _DevWarning(a1: 2, a2: "(%s) Schedule (%s) Failed at %d!\n", pszValue, m_pName, v4->iCurTask);
      goto LABEL_24;
    }
    if ( v3 >= 0 && v3 < this->m_ScheduleChannels.m_Size )
    {
      v12 = this->SelectSchedule_2(this, a2: v3);
      v11 = this->GetSchedule(this, a2: v12);
      pAIa = (CAI_BaseNPC *)v11;
      if ( v11 != nullptr )
      {
        this->m_ScheduleChannels.m_Memory.m_pMemory[i].idealSchedule = v11->m_iScheduleID;
LABEL_24:
        v11 = (CAI_Schedule *)pAIa;
      }
    }
    else
    {
      v11 = nullptr;
    }
    CAI_BehaviorBase::SetSchedule(this, channel: v3, pNewSchedule: v11);
    goto LABEL_26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FB480
// Name: AIChannelScheduleState_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AIChannelScheduleState_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AIChannelScheduleState_t>();
  AIChannelScheduleState_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB490
// Name: CAI_BehaviorBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_BehaviorBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_BehaviorBase>();
  CAI_BehaviorBase_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB4A0
// Name: AIBehaviorChannelSaveHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AIBehaviorChannelSaveHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AIBehaviorChannelSaveHeader_t>();
  AIBehaviorChannelSaveHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB4B0
// Name: _dynamic_initializer_for__ai_debug_assault__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_assault__()
{
  ConVar::ConVar(this: &ai_debug_assault, pName: "ai_debug_assault", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_assault__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB4E0
// Name: _dynamic_initializer_for__g_AssaultPointString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AssaultPointString__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AssaultPointString__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB4F0
// Name: _dynamic_initializer_for__g_RallyPointString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RallyPointString__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_RallyPointString__);
}
