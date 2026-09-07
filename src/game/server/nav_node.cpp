// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_node.cpp
// Functions: 200
// ============================================================

#include "game\server\nav_node.h"

//------------------------------------------------------------------------------
// Address: 0x10015300
// Name: public: int CUtlVector<class CAI_InterestTarget_t,class CUtlMemory<class CAI_InterestTarget_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAI_InterestTarget_t,CUtlMemory<CAI_InterestTarget_t,int>>::InsertMultipleBefore(
        CUtlVector<CAI_InterestTarget_t,CUtlMemory<CAI_InterestTarget_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAI_InterestTarget_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  CAI_InterestTarget_t *v11; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<touchevent_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 36 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_hTarget.m_Index = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10024490
// Name: public: void CUtlVector<struct AIRebalanceInfo_t,class CUtlMemory<struct AIRebalanceInfo_t,int>>::Sort(int (*)(struct AIRebalanceInfo_t const __near *,struct AIRebalanceInfo_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AIRebalanceInfo_t,CUtlMemory<AIRebalanceInfo_t,int>>::Sort(
        CUtlVector<AIRebalanceInfo_t,CUtlMemory<AIRebalanceInfo_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // eax
  AIRebalanceInfo_t *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  int j; // ebx
  __int64 v8; // xmm0_8
  __int64 v9; // xmm1_8
  AIRebalanceInfo_t *v10; // eax
  float distPlayer; // ecx
  int i; // [esp+4h] [ebp-4h]

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 0x14u, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      for ( i = v5; v5 >= 0; i = v5 )
      {
        if ( v5 >= 1 )
        {
          v6 = 1;
          for ( j = v5; j != 0; --j )
          {
            if ( pfnCompare(a1: &this->m_Memory.m_pMemory[v6 - 1], a2: &this->m_Memory.m_pMemory[v6]) < 0 )
            {
              v8 = *(_QWORD *)&this->m_Memory.m_pMemory[v6 - 1].pNPC;
              v9 = *(_QWORD *)&this->m_Memory.m_pMemory[v6 - 1].bInPVS;
              v10 = &this->m_Memory.m_pMemory[v6];
              distPlayer = v10[-1].distPlayer;
              *(_QWORD *)&v10[-1].pNPC = *(_QWORD *)&v10->pNPC;
              *(_QWORD *)&v10[-1].bInPVS = *(_QWORD *)&v10->bInPVS;
              v10[-1].distPlayer = v10->distPlayer;
              *(_QWORD *)&v10->pNPC = v8;
              *(_QWORD *)&v10->bInPVS = v9;
              v10->distPlayer = distPlayer;
            }
            ++v6;
          }
          v5 = i;
        }
        --v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100245A0
// Name: public: int CUtlVector<struct ScriptedNPCInteraction_t,class CUtlMemory<struct ScriptedNPCInteraction_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>::InsertMultipleBefore(
        CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ScriptedNPCInteraction_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  ScriptedNPCInteraction_t *v11; // eax
  ScriptedNPCInteraction_t *v12; // eax
  ScriptedNPCInteraction_t *v13; // eax
  ScriptedNPCInteraction_t *v14; // eax
  int v15; // ecx
  int v16; // edi
  ScriptedNPCInteraction_t *v17; // eax
  int i; // [esp+Ch] [ebp-4h]
  int numa; // [esp+1Ch] [ebp+Ch]

  if ( num != 0 )
  {
    m_Size = this->m_Size;
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( m_Size + num > m_nAllocationCount )
      CUtlMemory<ScriptedNPCInteraction_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
    this->m_Size += num;
    m_pMemory = this->m_Memory.m_pMemory;
    v8 = this->m_Size - elem - num;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v8 > 0 && num > 0 )
      _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 180 * v8);
    v9 = 0;
    if ( num >= 4 )
    {
      v10 = elem;
      numa = ((unsigned int)(num - 4) >> 2) + 1;
      i = 4 * numa;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->iszInteractionName.pszValue = nullptr;
          v11->iFlags = 0;
          v11->iTriggerMethod = 0;
          v11->iLoopBreakTriggerMethod = 0;
          v11->vecRelativeOrigin = vec3_origin;
          v11->bValidOnCurrentEnemy = false;
          v11->flDelay = 5.0;
          v11->flDistSqr = 36.0;
          v11->flNextAttemptTime = 0.0;
          v11->iszMyWeapon.pszValue = nullptr;
          v11->iszTheirWeapon.pszValue = nullptr;
          v11->sPhases[0].iszSequence.pszValue = nullptr;
          v11->sPhases[0].iActivity = -1;
          v11->sPhases[1].iszSequence.pszValue = nullptr;
          v11->sPhases[1].iActivity = -1;
          v11->sPhases[2].iszSequence.pszValue = nullptr;
          v11->sPhases[2].iActivity = -1;
        }
        v12 = &this->m_Memory.m_pMemory[v10 + 1];
        if ( &this->m_Memory.m_pMemory[v10] != (ScriptedNPCInteraction_t *)-180 )
        {
          v12->iszInteractionName.pszValue = nullptr;
          v12->iFlags = 0;
          v12->iTriggerMethod = 0;
          v12->iLoopBreakTriggerMethod = 0;
          v12->vecRelativeOrigin = vec3_origin;
          v12->bValidOnCurrentEnemy = false;
          v12->flDelay = 5.0;
          v12->flDistSqr = 36.0;
          v12->flNextAttemptTime = 0.0;
          v12->iszMyWeapon.pszValue = nullptr;
          v12->iszTheirWeapon.pszValue = nullptr;
          v12->sPhases[0].iszSequence.pszValue = nullptr;
          v12->sPhases[0].iActivity = -1;
          v12->sPhases[1].iszSequence.pszValue = nullptr;
          v12->sPhases[1].iActivity = -1;
          v12->sPhases[2].iszSequence.pszValue = nullptr;
          v12->sPhases[2].iActivity = -1;
        }
        v13 = &this->m_Memory.m_pMemory[v10 + 2];
        if ( &this->m_Memory.m_pMemory[v10] != (ScriptedNPCInteraction_t *)-360 )
        {
          v13->iszInteractionName.pszValue = nullptr;
          v13->iFlags = 0;
          v13->iTriggerMethod = 0;
          v13->iLoopBreakTriggerMethod = 0;
          v13->vecRelativeOrigin = vec3_origin;
          v13->bValidOnCurrentEnemy = false;
          v13->flDelay = 5.0;
          v13->flDistSqr = 36.0;
          v13->flNextAttemptTime = 0.0;
          v13->iszMyWeapon.pszValue = nullptr;
          v13->iszTheirWeapon.pszValue = nullptr;
          v13->sPhases[0].iszSequence.pszValue = nullptr;
          v13->sPhases[0].iActivity = -1;
          v13->sPhases[1].iszSequence.pszValue = nullptr;
          v13->sPhases[1].iActivity = -1;
          v13->sPhases[2].iszSequence.pszValue = nullptr;
          v13->sPhases[2].iActivity = -1;
        }
        v14 = &this->m_Memory.m_pMemory[v10 + 3];
        if ( &this->m_Memory.m_pMemory[v10] != (ScriptedNPCInteraction_t *)-540 )
        {
          v14->iszInteractionName.pszValue = nullptr;
          v14->iFlags = 0;
          v14->iTriggerMethod = 0;
          v14->iLoopBreakTriggerMethod = 0;
          v14->vecRelativeOrigin = vec3_origin;
          v14->bValidOnCurrentEnemy = false;
          v14->flDelay = 5.0;
          v14->flDistSqr = 36.0;
          v14->flNextAttemptTime = 0.0;
          v14->iszMyWeapon.pszValue = nullptr;
          v14->iszTheirWeapon.pszValue = nullptr;
          v14->sPhases[0].iszSequence.pszValue = nullptr;
          v14->sPhases[0].iActivity = -1;
          v14->sPhases[1].iszSequence.pszValue = nullptr;
          v14->sPhases[1].iActivity = -1;
          v14->sPhases[2].iszSequence.pszValue = nullptr;
          v14->sPhases[2].iActivity = -1;
        }
        v10 += 4;
        --numa;
      }
      while ( numa != 0 );
      v9 = i;
    }
    if ( v9 < num )
    {
      v15 = v9 + elem;
      v16 = num - v9;
      do
      {
        v17 = &this->m_Memory.m_pMemory[v15];
        if ( v17 != nullptr )
        {
          v17->iszInteractionName.pszValue = nullptr;
          v17->iFlags = 0;
          v17->iTriggerMethod = 0;
          v17->iLoopBreakTriggerMethod = 0;
          v17->vecRelativeOrigin = vec3_origin;
          v17->bValidOnCurrentEnemy = false;
          v17->flDelay = 5.0;
          v17->flDistSqr = 36.0;
          v17->flNextAttemptTime = 0.0;
          v17->iszMyWeapon.pszValue = nullptr;
          v17->iszTheirWeapon.pszValue = nullptr;
          v17->sPhases[0].iszSequence.pszValue = nullptr;
          v17->sPhases[0].iActivity = -1;
          v17->sPhases[1].iszSequence.pszValue = nullptr;
          v17->sPhases[1].iActivity = -1;
          v17->sPhases[2].iszSequence.pszValue = nullptr;
          v17->sPhases[2].iActivity = -1;
        }
        ++v15;
        --v16;
      }
      while ( v16 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002B290
// Name: public: int CUtlVector<struct ScriptedNPCInteraction_t,class CUtlMemory<struct ScriptedNPCInteraction_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int>>::InsertBefore(
        CUtlVector<ScriptedNPCInteraction_t,CUtlMemory<ScriptedNPCInteraction_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ScriptedNPCInteraction_t *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ScriptedNPCInteraction_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 180 * v6);
  Construct<ScriptedNPCInteraction_t>(pMemory: &this->m_Memory.m_pMemory[elem]);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002E660
// Name: public: int CUtlVector<struct AIRebalanceInfo_t,class CUtlMemory<struct AIRebalanceInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AIRebalanceInfo_t,CUtlMemory<AIRebalanceInfo_t,int>>::AddToTail(
        CUtlVector<AIRebalanceInfo_t,CUtlMemory<AIRebalanceInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  AIRebalanceInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10041770
// Name: public: int CUtlVector<struct AIChannelScheduleState_t,class CUtlMemory<struct AIChannelScheduleState_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int>>::InsertMultipleBefore(
        CUtlVector<AIChannelScheduleState_t,CUtlMemory<AIChannelScheduleState_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AIChannelScheduleState_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  AIChannelScheduleState_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<SaveRestoreBlockHeader_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          *(_QWORD *)&v11->bActive = 0;
          *(_QWORD *)&v11->idealSchedule = 0;
          *(_QWORD *)&v11->iCurTask = 0;
          *(_QWORD *)&v11->timeStarted = 0;
          *(_QWORD *)&v11->taskFailureCode = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10042520
// Name: public: void CUtlVector<class CPassengerSeatTransition,class CUtlMemory<class CPassengerSeatTransition,int>>::Sort(int (*)(class CPassengerSeatTransition const __near *,class CPassengerSeatTransition const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CPassengerSeatTransition,CUtlMemory<CPassengerSeatTransition,int>>::Sort(
        CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int v4; // ebx
  int j; // esi
  const char *pszName; // ecx
  int localId; // edx
  AI_NamespaceAddInfo_t *v8; // eax
  int i; // [esp+8h] [ebp-4h]

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 8u, comp: pfnCompare);
    }
    else
    {
      v4 = m_Size - 1;
      for ( i = v4; v4 >= 0; i = v4 )
      {
        for ( j = 1; j <= v4; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            pszName = this->m_Memory.m_pMemory[j - 1].pszName;
            localId = this->m_Memory.m_pMemory[j - 1].localId;
            v8 = &this->m_Memory.m_pMemory[j];
            v8[-1].pszName = v8->pszName;
            v8[-1].localId = v8->localId;
            v4 = i;
            v8->pszName = pszName;
            v8->localId = localId;
          }
        }
        --v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A6D0
// Name: public: int CUtlVector<struct CAI_BlendedMotor::AI_Movementscript_t,class CUtlMemory<struct CAI_BlendedMotor::AI_Movementscript_t,int>>::InsertBefore(int,struct CAI_BlendedMotor::AI_Movementscript_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int>>::InsertBefore(
        CUtlVector<CAI_BlendedMotor::AI_Movementscript_t,CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> > *this,
        int elem,
        const CAI_BlendedMotor::AI_Movementscript_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAI_BlendedMotor::AI_Movementscript_t *m_pMemory; // ecx
  int v7; // eax
  CAI_BlendedMotor::AI_Movementscript_t *v8; // edi
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 56 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  result = elem;
  if ( v8 != nullptr )
    qmemcpy(v8, src, sizeof(CAI_BlendedMotor::AI_Movementscript_t));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100617C0
// Name: public: int CUtlVector<struct AI_MoveSuggestion_t,class CUtlMemory<struct AI_MoveSuggestion_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertMultipleBefore(
        CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  AI_MoveSuggestion_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // edx
  AI_MoveSuggestion_t *v14; // eax
  AI_MoveSuggestion_t *v15; // eax
  AI_MoveSuggestion_t *v16; // eax
  AI_MoveSuggestion_t *v17; // eax
  int v18; // ecx
  int v19; // edi
  AI_MoveSuggestion_t *v20; // eax
  int i; // [esp+18h] [ebp+Ch]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v10);
    v8 = elem;
  }
  v11 = 0;
  i = 0;
  if ( num >= 4 )
  {
    v12 = v8;
    v13 = ((unsigned int)(num - 4) >> 2) + 1;
    i = 4 * v13;
    do
    {
      v14 = &this->m_Memory.m_pMemory[v12];
      if ( v14 != nullptr )
      {
        v14->type = AIMS_INVALID;
        v14->weight = 0.0;
        v14->arc.center = 0.0;
        v14->arc.span = 0.0;
        v14->hObstacleEntity.m_Index = -1;
        v14->flags = 0;
      }
      v15 = &this->m_Memory.m_pMemory[v12 + 1];
      if ( &this->m_Memory.m_pMemory[v12] != (AI_MoveSuggestion_t *)-24 )
      {
        v15->type = AIMS_INVALID;
        v15->weight = 0.0;
        v15->arc.center = 0.0;
        v15->arc.span = 0.0;
        v15->hObstacleEntity.m_Index = -1;
        v15->flags = 0;
      }
      v16 = &this->m_Memory.m_pMemory[v12 + 2];
      if ( &this->m_Memory.m_pMemory[v12] != (AI_MoveSuggestion_t *)-48 )
      {
        v16->type = AIMS_INVALID;
        v16->weight = 0.0;
        v16->arc.center = 0.0;
        v16->arc.span = 0.0;
        v16->hObstacleEntity.m_Index = -1;
        v16->flags = 0;
      }
      v17 = &this->m_Memory.m_pMemory[v12 + 3];
      if ( &this->m_Memory.m_pMemory[v12] != (AI_MoveSuggestion_t *)-72 )
      {
        v17->type = AIMS_INVALID;
        v17->weight = 0.0;
        v17->arc.center = 0.0;
        v17->arc.span = 0.0;
        v17->hObstacleEntity.m_Index = -1;
        v17->flags = 0;
      }
      v12 += 4;
      --v13;
    }
    while ( v13 != 0 );
    v8 = elem;
    v11 = i;
  }
  if ( v11 < num )
  {
    v18 = v8 + v11;
    v19 = num - i;
    do
    {
      v20 = &this->m_Memory.m_pMemory[v18];
      if ( v20 != nullptr )
      {
        v20->type = AIMS_INVALID;
        v20->weight = 0.0;
        v20->arc.center = 0.0;
        v20->arc.span = 0.0;
        v20->hObstacleEntity.m_Index = -1;
        v20->flags = 0;
      }
      ++v18;
      --v19;
    }
    while ( v19 != 0 );
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10061960
// Name: public: void CUtlVector<struct AI_MoveSuggestion_t,class CUtlMemory<struct AI_MoveSuggestion_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::EnsureCapacity(
        CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *this,
        int num)
{
  AI_MoveSuggestion_t *m_pMemory; // edx
  unsigned int v4; // eax
  AI_MoveSuggestion_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 24 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (AI_MoveSuggestion_t *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v4);
      goto LABEL_5;
    }
    v5 = (AI_MoveSuggestion_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100619D0
// Name: public: int CUtlVector<struct AI_MoveSuggestion_t,class CUtlMemory<struct AI_MoveSuggestion_t,int>>::AddVectorToTail(class CUtlVector<struct AI_MoveSuggestion_t,class CUtlMemory<struct AI_MoveSuggestion_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::AddVectorToTail(
        CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *this,
        const CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *src)
{
  int m_Size; // ebx
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  char *v8; // ecx
  AI_MoveSuggestion_t *v9; // edx
  AI_MoveSuggestion_t *v10; // ecx
  AI_MoveSuggestion_t *v11; // ecx
  char *v12; // ecx
  AI_MoveSuggestion_t *v13; // edx
  bool v14; // zf
  int v15; // edx
  AI_MoveSuggestion_t *v16; // eax
  AI_MoveSuggestion_t *v17; // ecx
  int i; // [esp+Ch] [ebp-14h]
  int nSrcCount; // [esp+10h] [ebp-10h]
  int nSrcCounta; // [esp+10h] [ebp-10h]
  unsigned int v22; // [esp+14h] [ebp-Ch]
  int v23; // [esp+18h] [ebp-8h]
  int base; // [esp+1Ch] [ebp-4h]
  const CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *srca; // [esp+28h] [ebp+8h]
  const CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *srcb; // [esp+28h] [ebp+8h]
  const CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *srcc; // [esp+28h] [ebp+8h]

  m_Size = src->m_Size;
  base = this->m_Size;
  nSrcCount = m_Size;
  CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::EnsureCapacity(this, num: m_Size + base);
  this->m_Size += m_Size;
  v5 = 0;
  if ( m_Size >= 4 )
  {
    v22 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    v6 = 0;
    v7 = base;
    v23 = 0;
    i = 4 * v22;
    do
    {
      v8 = (char *)src->m_Memory.m_pMemory + v6;
      v9 = &this->m_Memory.m_pMemory[v7];
      if ( v9 != nullptr )
      {
        v9->type = *(_DWORD *)v8;
        v9->weight = *((float *)v8 + 1);
        v9->arc.center = *((float *)v8 + 2);
        v9->arc.span = *((float *)v8 + 3);
        v9->hObstacleEntity.m_Index = *((_DWORD *)v8 + 4);
        v6 = v23;
        v9->flags = *((_DWORD *)v8 + 5);
      }
      v10 = &this->m_Memory.m_pMemory[v7 + 1];
      srca = (const CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *)((char *)&src->m_Memory.m_pMemory[1]
                                                                                          + v6);
      if ( &this->m_Memory.m_pMemory[v7] != (AI_MoveSuggestion_t *)-24 )
      {
        v10->type = *(AI_MoveSuggType_t *)((char *)&src->m_Memory.m_pMemory[1].type + v6);
        v10->weight = *(float *)&srca->m_Memory.m_nAllocationCount;
        LODWORD(v10->arc.center) = srca->m_Memory.m_nGrowSize;
        LODWORD(v10->arc.span) = srca->m_Size;
        v10->hObstacleEntity.m_Index = (unsigned int)srca->m_pElements;
        v10->flags = (unsigned int)srca[1].m_Memory.m_pMemory;
      }
      v11 = &this->m_Memory.m_pMemory[v7 + 2];
      srcb = (const CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *)((char *)&src->m_Memory.m_pMemory[2]
                                                                                          + v6);
      if ( &this->m_Memory.m_pMemory[v7] != (AI_MoveSuggestion_t *)-48 )
      {
        v11->type = *(AI_MoveSuggType_t *)((char *)&src->m_Memory.m_pMemory[2].type + v6);
        v11->weight = *(float *)&srcb->m_Memory.m_nAllocationCount;
        LODWORD(v11->arc.center) = srcb->m_Memory.m_nGrowSize;
        LODWORD(v11->arc.span) = srcb->m_Size;
        v11->hObstacleEntity.m_Index = (unsigned int)srcb->m_pElements;
        v11->flags = (unsigned int)srcb[1].m_Memory.m_pMemory;
      }
      v12 = (char *)&src->m_Memory.m_pMemory[3] + v6;
      v13 = &this->m_Memory.m_pMemory[v7 + 3];
      if ( &this->m_Memory.m_pMemory[v7] != (AI_MoveSuggestion_t *)-72 )
      {
        v13->type = *(_DWORD *)v12;
        v13->weight = *((float *)v12 + 1);
        v13->arc.center = *((float *)v12 + 2);
        v13->arc.span = *((float *)v12 + 3);
        v13->hObstacleEntity.m_Index = *((_DWORD *)v12 + 4);
        v6 = v23;
        v13->flags = *((_DWORD *)v12 + 5);
      }
      v6 += 96;
      v7 += 4;
      v14 = v22-- == 1;
      v23 = v6;
    }
    while ( !v14 );
    v5 = i;
    m_Size = nSrcCount;
  }
  if ( v5 < m_Size )
  {
    v15 = v5;
    srcc = (const CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *)(24 * (v5 + base));
    nSrcCounta = m_Size - v5;
    do
    {
      v16 = &src->m_Memory.m_pMemory[v15];
      v17 = (AI_MoveSuggestion_t *)((char *)srcc + (unsigned int)this->m_Memory.m_pMemory);
      if ( v17 != nullptr )
      {
        v17->type = v16->type;
        v17->weight = v16->weight;
        v17->arc.center = v16->arc.center;
        v17->arc.span = v16->arc.span;
        v17->hObstacleEntity.m_Index = v16->hObstacleEntity.m_Index;
        v17->flags = v16->flags;
      }
      srcc = (const CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *)((char *)srcc + 24);
      ++v15;
      --nSrcCounta;
    }
    while ( nSrcCounta != 0 );
  }
  return base;
}

//------------------------------------------------------------------------------
// Address: 0x10061E10
// Name: public: void CUtlVector<struct AI_MoveSuggestion_t,class CUtlMemory<struct AI_MoveSuggestion_t,int>>::CopyArray(struct AI_MoveSuggestion_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::CopyArray(
        CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *this,
        const AI_MoveSuggestion_t *pArray,
        int size)
{
  int v4; // edx
  int v5; // ecx

  this->m_Size = 0;
  CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  if ( size > 0 )
  {
    v4 = size;
    v5 = 0;
    do
    {
      this->m_Memory.m_pMemory[v5] = pArray[v5];
      ++v5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066C30
// Name: public: void CUtlVector<struct AI_Waypoint_t,class CUtlMemory<struct AI_Waypoint_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::RemoveAll(
        CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *this)
{
  int v1; // esi
  int v2; // edi
  AI_Waypoint_t *pNext; // edx
  AI_Waypoint_t *v4; // eax
  AI_Waypoint_t *pPrev; // edx

  v1 = this->m_Size - 1;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      pNext = this->m_Memory.m_pMemory[v2].pNext;
      v4 = &this->m_Memory.m_pMemory[v2];
      if ( pNext != nullptr )
        pNext->pPrev = v4->pPrev;
      pPrev = v4->pPrev;
      if ( pPrev != nullptr )
        pPrev->pNext = v4->pNext;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10066C70
// Name: public: int CUtlVector<struct AI_Waypoint_t,class CUtlMemory<struct AI_Waypoint_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::InsertMultipleBefore(
        CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  AI_Waypoint_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  AI_Waypoint_t *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<AI_Waypoint_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 48 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          AI_Waypoint_t::AI_Waypoint_t(this: v12);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100680F0
// Name: public: int CUtlVector<struct AI_Waypoint_t,class CUtlMemory<struct AI_Waypoint_t,int>>::InsertBefore(int,struct AI_Waypoint_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::InsertBefore(
        CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *this,
        int elem,
        const AI_Waypoint_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AI_Waypoint_t *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<AI_Waypoint_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v7);
  CopyConstruct<AI_Waypoint_t>(pMemory: &this->m_Memory.m_pMemory[elem], src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10068D00
// Name: public: CUtlVector<struct AI_Waypoint_t,class CUtlMemory<struct AI_Waypoint_t,int>>::~CUtlVector<struct AI_Waypoint_t,class CUtlMemory<struct AI_Waypoint_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::~CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>(
        CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int> > *this)
{
  bool v2; // sf
  AI_Waypoint_t *m_pMemory; // eax

  CUtlVector<AI_Waypoint_t,CUtlMemory<AI_Waypoint_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100701D0
// Name: public: int CUtlVector<class CVarBitVec,class CUtlMemory<class CVarBitVec,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>::InsertMultipleBefore(
        CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CVarBitVec *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CVarBitVec *v12; // eax
  unsigned __int8 *m_pInt; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          *(_QWORD *)&v12->m_numBits = 0;
          v12->m_pInt = nullptr;
          m_pInt = (unsigned __int8 *)v12->m_pInt;
          if ( m_pInt != nullptr )
          {
            memset(dst: m_pInt, value: 0, count: 4 * v12->m_numInts);
            v8 = elem;
          }
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10070450
// Name: public: void CUtlVector<class CVarBitVec,class CUtlMemory<class CVarBitVec,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>::RemoveAll(
        CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CVarBitVec *m_pMemory; // esi
  CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      m_pMemory = this->m_Memory.m_pMemory;
      if ( this->m_Memory.m_pMemory[v2].m_numInts > 1u )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory[v2].m_pInt);
        this = v4;
      }
      m_pMemory[v2--].m_pInt = nullptr;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10070CB0
// Name: public: CUtlVector<class CVarBitVec,class CUtlMemory<class CVarBitVec,int>>::~CUtlVector<class CVarBitVec,class CUtlMemory<class CVarBitVec,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>::~CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>(
        CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int> > *this)
{
  bool v2; // sf
  CVarBitVec *m_pMemory; // eax

  CUtlVector<CVarBitVec,CUtlMemory<CVarBitVec,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100782F0
// Name: public: int CUtlVector<struct AI_MoveSuggestion_t,class CUtlMemory<struct AI_MoveSuggestion_t,int>>::InsertBefore(int,struct AI_MoveSuggestion_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int>>::InsertBefore(
        CUtlVector<AI_MoveSuggestion_t,CUtlMemory<AI_MoveSuggestion_t,int> > *this,
        int elem,
        const AI_MoveSuggestion_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AI_MoveSuggestion_t *m_pMemory; // ecx
  int v7; // eax
  AI_MoveSuggestion_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10078380
// Name: public: int CUtlVector<struct CAI_PlaneSolver::CircleObstacles_t,class CUtlMemory<struct CAI_PlaneSolver::CircleObstacles_t,int>>::InsertBefore(int,struct CAI_PlaneSolver::CircleObstacles_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAI_PlaneSolver::CircleObstacles_t,CUtlMemory<CAI_PlaneSolver::CircleObstacles_t,int>>::InsertBefore(
        CUtlVector<CAI_PlaneSolver::CircleObstacles_t,CUtlMemory<CAI_PlaneSolver::CircleObstacles_t,int> > *this,
        int elem,
        const CAI_PlaneSolver::CircleObstacles_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAI_PlaneSolver::CircleObstacles_t *m_pMemory; // ecx
  int v7; // eax
  CAI_PlaneSolver::CircleObstacles_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1007E5F0
// Name: public: void CUtlVector<struct ResponseRules::ParserResponse,class CUtlMemory<struct ResponseRules::ParserResponse,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ResponseRules::ParserResponse,CUtlMemory<ResponseRules::ParserResponse,int>>::Purge(
        CUtlVector<ResponseRules::ParserResponse,CUtlMemory<ResponseRules::ParserResponse,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  ResponseRules::ParserResponse *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083710
// Name: public: int CUtlVector<class CAI_ScriptConditionsElement,class CUtlMemory<class CAI_ScriptConditionsElement,int>>::InsertBefore(int,class CAI_ScriptConditionsElement const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>::InsertBefore(
        CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int> > *this,
        int elem,
        const CAI_ScriptConditionsElement *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAI_ScriptConditionsElement *m_pMemory; // ecx
  int v7; // eax
  CAI_ScriptConditionsElement *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100837A0
// Name: public: int CUtlVector<class CAI_ScriptConditionsElement,class CUtlMemory<class CAI_ScriptConditionsElement,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>::InsertMultipleBefore(
        CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAI_ScriptConditionsElement *m_pMemory; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  CAI_ScriptConditionsElement *v13; // ecx
  CAI_ScriptConditionsElement *v14; // ecx
  CAI_ScriptConditionsElement *v15; // ecx
  CAI_ScriptConditionsElement *v16; // ecx
  int v17; // ecx
  int v18; // edi
  CAI_ScriptConditionsElement *v19; // eax
  int i; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  v10 = 0;
  if ( num >= 4 )
  {
    v11 = elem;
    v12 = ((unsigned int)(num - 4) >> 2) + 1;
    i = 4 * v12;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v11];
      if ( v13 != nullptr )
      {
        v13->m_hActor.m_Index = -1;
        v13->m_Timer.m_interval = 0.0;
        v13->m_Timer.m_next = -1.0;
        v13->m_Timeout.m_interval = 0.0;
        v13->m_Timeout.m_next = -1.0;
      }
      v14 = &this->m_Memory.m_pMemory[v11 + 1];
      if ( &this->m_Memory.m_pMemory[v11] != (CAI_ScriptConditionsElement *)-20 )
      {
        v14->m_hActor.m_Index = -1;
        v14->m_Timer.m_interval = 0.0;
        v14->m_Timer.m_next = -1.0;
        v14->m_Timeout.m_interval = 0.0;
        v14->m_Timeout.m_next = -1.0;
      }
      v15 = &this->m_Memory.m_pMemory[v11 + 2];
      if ( &this->m_Memory.m_pMemory[v11] != (CAI_ScriptConditionsElement *)-40 )
      {
        v15->m_hActor.m_Index = -1;
        v15->m_Timer.m_interval = 0.0;
        v15->m_Timer.m_next = -1.0;
        v15->m_Timeout.m_interval = 0.0;
        v15->m_Timeout.m_next = -1.0;
      }
      v16 = &this->m_Memory.m_pMemory[v11 + 3];
      if ( &this->m_Memory.m_pMemory[v11] != (CAI_ScriptConditionsElement *)-60 )
      {
        v16->m_hActor.m_Index = -1;
        v16->m_Timer.m_interval = 0.0;
        v16->m_Timer.m_next = -1.0;
        v16->m_Timeout.m_interval = 0.0;
        v16->m_Timeout.m_next = -1.0;
      }
      v11 += 4;
      --v12;
    }
    while ( v12 != 0 );
    v10 = i;
  }
  if ( v10 < num )
  {
    v17 = v10 + elem;
    v18 = num - v10;
    do
    {
      v19 = &this->m_Memory.m_pMemory[v17];
      if ( v19 != nullptr )
      {
        v19->m_hActor.m_Index = -1;
        v19->m_Timer.m_interval = 0.0;
        v19->m_Timer.m_next = -1.0;
        v19->m_Timeout.m_interval = 0.0;
        v19->m_Timeout.m_next = -1.0;
      }
      ++v17;
      --v18;
    }
    while ( v18 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1008B8D0
// Name: public: void CUtlVector<class CHandle<class CAI_BaseNPC>,class CUtlMemoryFixed<class CHandle<class CAI_BaseNPC>,16,0>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemoryFixed<CHandle<CAI_BaseNPC>,16,0>>::Remove(
        CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemoryFixed<CHandle<CAI_BaseNPC>,16,0> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: (char *)this + 4 * elem, src: &this->m_Memory.m_Memory[4 * elem + 4], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1008BF80
// Name: public: int CUtlVector<class CHandle<class CAI_BaseNPC>,class CUtlMemoryFixed<class CHandle<class CAI_BaseNPC>,16,0>>::Find(class CHandle<class CAI_BaseNPC> const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemoryFixed<CHandle<CAI_BaseNPC>,16,0>>::Find(
        CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemoryFixed<CHandle<CAI_BaseNPC>,16,0> > *this,
        CHandle<CBaseEntity> *src)
{
  int v3; // esi
  CBaseEntityList *v4; // ebx
  CBaseEntity *v5; // eax
  unsigned int v6; // ecx
  CBaseEntity *m_pEntity; // edx
  int m_Size; // [esp+Ch] [ebp-4h]

  v3 = 0;
  m_Size = this->m_Size;
  if ( m_Size <= 0 )
    return -1;
  v4 = g_pEntityList;
  while ( 1 )
  {
    v5 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: src);
    v6 = *(_DWORD *)&this->m_Memory.m_Memory[4 * v3];
    if ( v6 == -1 || v4->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)v4->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    if ( m_pEntity == v5 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008BFF0
// Name: public: int CUtlVector<struct AISquadEnemyInfo_t,class CUtlMemory<struct AISquadEnemyInfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int>>::InsertMultipleBefore(
        CUtlVector<AISquadEnemyInfo_t,CUtlMemory<AISquadEnemyInfo_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AISquadEnemyInfo_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  AISquadEnemyInfo_t *v11; // eax
  bool v12; // zf
  CBitVec<32> *p_slots; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v12 = &v11->slots == nullptr;
          p_slots = &v11->slots;
          p_slots[-1].m_Ints[0] = -1;
          if ( !v12 )
            p_slots->m_Ints[0] = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1008C200
// Name: public: int CUtlVector<class CHandle<class CAI_BaseNPC>,class CUtlMemoryFixed<class CHandle<class CAI_BaseNPC>,16,0>>::AddToTail(class CHandle<class CAI_BaseNPC> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemoryFixed<CHandle<CAI_BaseNPC>,16,0>>::AddToTail(
        CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemoryFixed<CHandle<CAI_BaseNPC>,16,0> > *this,
        const CHandle<CAI_BaseNPC> *src)
{
  int m_Size; // edi
  CHandle<CAI_BaseNPC> *v3; // eax

  m_Size = this->m_Size;
  this->m_Size = m_Size + 1;
  this->m_pElements = (CHandle<CAI_BaseNPC> *)this;
  v3 = (CHandle<CAI_BaseNPC> *)((char *)this + 4 * m_Size);
  if ( v3 != nullptr )
    v3->m_Index = src->m_Index;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1009EA90
// Name: public: int CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
        CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ScriptFunctionBinding_t *m_pMemory; // ecx
  int v6; // eax
  ScriptFunctionBinding_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<AI_Waypoint_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
    v7->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
    v7->m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
    v7->m_desc.m_Parameters.m_Size = 0;
    v7->m_desc.m_Parameters.m_pElements = nullptr;
    v7->m_desc.m_pszFunction = nullptr;
    v7->m_desc.m_ReturnType = 31;
    v7->m_desc.m_pszDescription = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1009EB20
// Name: public: void CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::RemoveAll(
        CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 48 * v1;
    v5 = 48 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 7) = 0;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 4));
          this = v6;
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      v4 = *((void **)v3 + 4);
      *((_DWORD *)v3 + 8) = v4;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      --v1;
      v2 = v5 - 48;
      v5 -= 48;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009EF40
// Name: public: CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>::~CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(
        CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *this)
{
  bool v2; // sf
  ScriptFunctionBinding_t *m_pMemory; // eax

  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1050
// Name: public: int CUtlVector<class CAnimationLayer,class CUtlMemory<class CAnimationLayer,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::InsertBefore(
        CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAnimationLayer *m_pMemory; // ecx
  int v6; // eax
  CAnimationLayer *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAnimationLayer,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 76 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CAnimationLayer::Init(this: v7, pOverlay: nullptr);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100A10C0
// Name: public: int CUtlVector<class CAnimationLayer,class CUtlMemory<class CAnimationLayer,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::InsertMultipleBefore(
        CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CAnimationLayer *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CAnimationLayer *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CAnimationLayer,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 76 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CAnimationLayer::Init(this: v12, pOverlay: nullptr);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100A4E90
// Name: public: void CUtlVector<struct Relationship_t,class CUtlMemory<struct Relationship_t,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int>>::FastRemove(
        CUtlVector<Relationship_t,CUtlMemory<Relationship_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int v3; // eax
  __int64 v4; // xmm0_8
  Relationship_t *v5; // eax
  Relationship_t *v6; // edx

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      v3 = m_Size;
      v4 = *(_QWORD *)&this->m_Memory.m_pMemory[v3 - 1].entity.m_Index;
      v5 = &this->m_Memory.m_pMemory[v3 - 1];
      v6 = &this->m_Memory.m_pMemory[elem];
      *(_QWORD *)&v6->entity.m_Index = v4;
      *(_QWORD *)&v6->faction = *(_QWORD *)&v5->faction;
      v6->priority = v5->priority;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5AA0
// Name: public: int CUtlVector<struct UnreachableEnt_t,class CUtlMemory<struct UnreachableEnt_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int>>::InsertMultipleBefore(
        CUtlVector<UnreachableEnt_t,CUtlMemory<UnreachableEnt_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  UnreachableEnt_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  UnreachableEnt_t *v11; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->hUnreachableEnt.m_Index = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100BAF60
// Name: public: int CUtlVector<struct CaptionLookup_t,class CUtlMemory<struct CaptionLookup_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::InsertMultipleBefore(
        CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResponseContext_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100BC5B0
// Name: public: int CUtlVector<struct collidelist_t,class CUtlMemory<struct collidelist_t,int>>::InsertBefore(int,struct collidelist_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<collidelist_t,CUtlMemory<collidelist_t,int>>::InsertBefore(
        CUtlVector<TeleportListEntry_t,CUtlMemory<TeleportListEntry_t,int> > *this,
        int elem,
        const TeleportListEntry_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  TeleportListEntry_t *m_pMemory; // ecx
  int v7; // eax
  TeleportListEntry_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<constraint_anchor_t,int>::Grow(
      (CUtlMemory<CEventAbsoluteTag,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100BC850
// Name: public: int CUtlVector<struct thinkfunc_t,class CUtlMemory<struct thinkfunc_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>::InsertMultipleBefore(
        CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  thinkfunc_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100C0370
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100D1AD0
// Name: public: int CUtlVector<class CSceneEventInfo,class CUtlMemory<class CSceneEventInfo,int>>::InsertBefore(int,class CSceneEventInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSceneEventInfo,CUtlMemory<CSceneEventInfo,int>>::InsertBefore(
        CUtlVector<CSceneEventInfo,CUtlMemory<CSceneEventInfo,int> > *this,
        int elem,
        const CSceneEventInfo *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSceneEventInfo *m_pMemory; // ecx
  int v7; // eax
  CSceneEventInfo *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAnimationLayer,int>::Grow((CUtlMemory<CAnimationLayer,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 76 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CSceneEventInfo::CSceneEventInfo(this: v8, __that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100D8540
// Name: public: class CUtlVector<class CHandle<class CBasePlayer>,class CUtlMemory<class CHandle<class CBasePlayer>,int>> __near & CBasePlayer::GetSplitScreenPlayers(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *__thiscall CBasePlayer::GetSplitScreenPlayers(
        CBasePlayer *this)
{
  return &this->m_hSplitScreenPlayers;
}

//------------------------------------------------------------------------------
// Address: 0x100D8550
// Name: public: class CUtlVector<class CHandle<class CBasePlayer>,class CUtlMemory<class CHandle<class CBasePlayer>,int>> __near & CBasePlayer::GetSplitScreenAndPictureInPicturePlayers(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *__thiscall CBasePlayer::GetSplitScreenAndPictureInPicturePlayers(
        CBasePlayer *this)
{
  return &this->m_hSplitScreenAndPipPlayers;
}

//------------------------------------------------------------------------------
// Address: 0x100D97F0
// Name: public: int CUtlVector<class CHandle<class CSceneEntity>,class CUtlMemory<class CHandle<class CSceneEntity>,int>>::Find(class CHandle<class CSceneEntity> const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
        CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *this,
        CHandle<CBaseEntity> *src)
{
  int v2; // edi
  CHandle<CBaseEntity> *m_pMemory; // esi
  CBaseEntityList *v4; // ebx
  CBaseEntity *v5; // eax
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // edx
  int m_Size; // [esp+Ch] [ebp-4h]

  v2 = 0;
  m_Size = this->m_Size;
  if ( m_Size <= 0 )
    return -1;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = g_pEntityList;
  while ( 1 )
  {
    v5 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: src);
    m_Index = m_pMemory->m_Index;
    if ( m_pMemory->m_Index == -1 || v4->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)v4->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == v5 )
      break;
    ++v2;
    ++m_pMemory;
    if ( v2 >= m_Size )
      return -1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100DC2C0
// Name: public: int CUtlVector<class CHandle<class CBasePlayer>,class CUtlMemory<class CHandle<class CBasePlayer>,int>>::AddVectorToTail(class CUtlVector<class CHandle<class CBasePlayer>,class CUtlMemory<class CHandle<class CBasePlayer>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int>>::AddVectorToTail(
        CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *this,
        const CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *src)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  CHandle<CBasePlayer> *m_pMemory; // edx
  CHandle<CBasePlayer> *v7; // eax
  CHandle<CBasePlayer> *v8; // ecx
  int v9; // eax
  int v10; // edx
  CHandle<CBasePlayer> *v11; // ecx
  unsigned int v13; // [esp-4h] [ebp-14h]
  int base; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Size;
  v4 = src->m_Size;
  v5 = v4 + m_Size;
  base = m_Size;
  if ( this->m_Memory.m_nAllocationCount < v4 + m_Size && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v5;
    v13 = 4 * v5;
    if ( m_pMemory != nullptr )
      v7 = (CHandle<CBasePlayer> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v13);
    else
      v7 = (CHandle<CBasePlayer> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v13);
    this->m_Memory.m_pMemory = v7;
  }
  v8 = this->m_Memory.m_pMemory;
  this->m_Size += v4;
  v9 = 0;
  this->m_pElements = v8;
  if ( v4 > 0 )
  {
    v10 = m_Size;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        v11->m_Index = (unsigned int)src->m_Memory.m_pMemory[v9];
        m_Size = base;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < v4 );
  }
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100DD9E0
// Name: public: int CUtlVector<class CHandle<class CVGuiScreen>,class CUtlMemory<class CHandle<class CVGuiScreen>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int>>::InsertBefore(
        CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CHandle<CVGuiScreen> *m_pMemory; // ecx
  int v6; // eax
  CHandle<CVGuiScreen> *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_Index = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100EDE00
// Name: public: void CUtlVector<struct CaptionLookup_t,class CUtlMemory<struct CaptionLookup_t,int>>::CopyArray(struct CaptionLookup_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::CopyArray(
        CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int> > *this,
        const CaptionLookup_t *pArray,
        int size)
{
  int v4; // edx
  int v5; // ecx

  this->m_Size = 0;
  CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::InsertMultipleBefore(
    (CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int> > *)this,
    elem: 0,
    num: size);
  if ( size > 0 )
  {
    v4 = size;
    v5 = 0;
    do
    {
      this->m_Memory.m_pMemory[v5] = pArray[v5];
      ++v5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6980
// Name: public: int CUtlVector<struct modifiedconvars_t,class CUtlMemory<struct modifiedconvars_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int>>::InsertMultipleBefore(
        CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  modifiedconvars_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<modifiedconvars_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 384 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100FAA70
// Name: public: int CUtlVector<struct visibility_target_t,class CUtlMemory<struct visibility_target_t,int>>::InsertBefore(int,struct visibility_target_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<visibility_target_t,CUtlMemory<visibility_target_t,int>>::InsertBefore(
        CUtlVector<visibility_target_t,CUtlMemory<visibility_target_t,int> > *this,
        int elem,
        const visibility_target_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  visibility_target_t *m_pMemory; // ecx
  int v7; // eax
  visibility_target_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100FDAF0
// Name: public: int CUtlVector<struct CDecalEmitterSystem::DecalListEntry,class CUtlMemory<struct CDecalEmitterSystem::DecalListEntry,int>>::InsertBefore(int,struct CDecalEmitterSystem::DecalListEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDecalEmitterSystem::DecalListEntry,CUtlMemory<CDecalEmitterSystem::DecalListEntry,int>>::InsertBefore(
        CUtlVector<CDecalEmitterSystem::DecalListEntry,CUtlMemory<CDecalEmitterSystem::DecalListEntry,int> > *this,
        int elem,
        const CDecalEmitterSystem::DecalListEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDecalEmitterSystem::DecalListEntry *m_pMemory; // ecx
  int v7; // eax
  CDecalEmitterSystem::DecalListEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1010E940
// Name: protected: bool CUtlHash<struct EntsByStringList_t,class CEntsByStringHashFuncs,class CEntsByStringHashFuncs>::DoFind(struct EntsByStringList_t const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs>::DoFind(
        CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *this,
        const EntsByStringList_t *src,
        unsigned int *pBucket,
        int *pIndex)
{
  const char *pszValue; // eax
  unsigned int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // edx
  int m_Size; // ecx
  CUtlVector<EntsByStringList_t,CUtlMemory<EntsByStringList_t,int> > *v10; // edx
  int v11; // eax
  const char **p_pszValue; // edx

  pszValue = src->iszStr.pszValue;
  if ( src->iszStr.pszValue == nullptr )
    pszValue = locale;
  v6 = HashInt(n: (const int)pszValue);
  if ( this->m_bPowerOfTwo )
    v7 = v6 & this->m_ModMask;
  else
    v7 = v6 % this->m_Buckets.m_Size;
  *pBucket = v7;
  v8 = v7;
  m_Size = this->m_Buckets.m_Memory.m_pMemory[v8].m_Size;
  v10 = &this->m_Buckets.m_Memory.m_pMemory[v8];
  v11 = 0;
  if ( m_Size > 0 )
  {
    p_pszValue = &v10->m_Memory.m_pMemory->iszStr.pszValue;
    do
    {
      if ( *p_pszValue == src->iszStr.pszValue )
        break;
      ++v11;
      p_pszValue += 2;
    }
    while ( v11 < m_Size );
  }
  if ( v11 == m_Size )
    return 0;
  *pIndex = v11;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010F370
// Name: public: int CUtlVector<struct simthinkentry_t,class CUtlMemory<struct simthinkentry_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<simthinkentry_t,CUtlMemory<simthinkentry_t,int>>::AddToTail(
        CUtlVector<simthinkentry_t,CUtlMemory<simthinkentry_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  simthinkentry_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10112650
// Name: public: int CUtlVector<class CEffectScriptElement,class CUtlMemory<class CEffectScriptElement,int>>::InsertBefore(int,class CEffectScriptElement const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEffectScriptElement,CUtlMemory<CEffectScriptElement,int>>::InsertBefore(
        CUtlVector<CEffectScriptElement,CUtlMemory<CEffectScriptElement,int> > *this,
        int elem,
        const CEffectScriptElement *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEffectScriptElement *m_pMemory; // ecx
  int v7; // eax
  CEffectScriptElement *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEffectScriptElement,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 432 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CEffectScriptElement::CEffectScriptElement(this: v8, __that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1011F580
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        const QAngle *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v7; // eax
  QAngle *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101439F0
// Name: public: CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::~CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  bool v2; // sf
  CUtlBinaryBlock *m_pMemory; // eax

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151970
// Name: public: int CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>>::InsertBefore(int,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertBefore(
        CUtlVector<char const *,CUtlMemory<char const *,int> > *this,
        int elem,
        const char **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  const char **m_pMemory; // ecx
  int v7; // eax
  const char **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10159220
// Name: public: int CUtlVector<struct globalentity_t,class CUtlMemory<struct globalentity_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>::InsertMultipleBefore(
        CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  globalentity_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  globalentity_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->name.m_Id = -1;
          v11->levelName.m_Id = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101592E0
// Name: public: int CUtlVector<struct globalentity_t,class CUtlMemory<struct globalentity_t,int>>::InsertBefore(int,struct globalentity_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int>>::InsertBefore(
        CUtlVector<globalentity_t,CUtlMemory<globalentity_t,int> > *this,
        int elem,
        const globalentity_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  globalentity_t *m_pMemory; // ecx
  int v7; // eax
  globalentity_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10173F90
// Name: public: int CUtlVector<struct CMoveHelperServer::touchlist_t,class CUtlMemory<struct CMoveHelperServer::touchlist_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMoveHelperServer::touchlist_t,CUtlMemory<CMoveHelperServer::touchlist_t,int>>::AddToTail(
        CUtlVector<CMoveHelperServer::touchlist_t,CUtlMemory<CMoveHelperServer::touchlist_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CMoveHelperServer::touchlist_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ResponseRules::ParserResponse,int>::Grow(
      (CUtlMemory<ResponseRules::ParserResponse,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 96 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10177020
// Name: public: int CUtlVector<class CUtlVector<struct VoiceCommandMenuItem_t,class CUtlMemory<struct VoiceCommandMenuItem_t,int>>,class CUtlMemory<class CUtlVector<struct VoiceCommandMenuItem_t,class CUtlMemory<struct VoiceCommandMenuItem_t,int>>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int>>,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int>>,int>>::InsertBefore(
        CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> > *m_pMemory; // ecx
  int v6; // eax
  CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> > *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Memory.m_pMemory = nullptr;
    v7->m_Memory.m_nAllocationCount = 0;
    v7->m_Memory.m_nGrowSize = 0;
    v7->m_Size = 0;
    v7->m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10183E10
// Name: public: int CUtlVector<struct constraint_anchor_t,class CUtlMemory<struct constraint_anchor_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<constraint_anchor_t,CUtlMemory<constraint_anchor_t,int>>::InsertBefore(
        CUtlVector<constraint_anchor_t,CUtlMemory<constraint_anchor_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  constraint_anchor_t *m_pMemory; // ecx
  int v6; // eax
  constraint_anchor_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<constraint_anchor_t,int>::Grow(
      (CUtlMemory<CEventAbsoluteTag,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->hEntity.m_Index = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101888D0
// Name: public: CUtlVector<class CHandle<class CAI_DynamicLink>,class CUtlMemory<class CHandle<class CAI_DynamicLink>,int>>::~CUtlVector<class CHandle<class CAI_DynamicLink>,class CUtlMemory<class CHandle<class CAI_DynamicLink>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188940
// Name: public: void CUtlVector<struct vehiclescript_t,class CUtlMemory<struct vehiclescript_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::EnsureCapacity(
        CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int> > *this,
        int num)
{
  vehiclescript_t *m_pMemory; // edx
  unsigned int v4; // eax
  vehiclescript_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 916 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (vehiclescript_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (vehiclescript_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188B20
// Name: public: int CUtlVector<struct damageevent_t,class CUtlMemory<struct damageevent_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<damageevent_t,CUtlMemory<damageevent_t,int>>::InsertBefore(
        CUtlVector<damageevent_t,CUtlMemory<damageevent_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  damageevent_t *m_pMemory; // ecx
  int v6; // eax
  damageevent_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<damageevent_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 104 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CTakeDamageInfo::CTakeDamageInfo(this: &v7->info);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10188B90
// Name: public: int CUtlVector<struct masscenteroverride_t,class CUtlMemory<struct masscenteroverride_t,int>>::InsertBefore(int,struct masscenteroverride_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<masscenteroverride_t,CUtlMemory<masscenteroverride_t,int>>::InsertBefore(
        CUtlVector<masscenteroverride_t,CUtlMemory<masscenteroverride_t,int> > *this,
        int elem,
        const masscenteroverride_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  masscenteroverride_t *m_pMemory; // ecx
  int v7; // eax
  masscenteroverride_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<masscenteroverride_t,int>::Grow(
      (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101892F0
// Name: public: int CUtlVector<double,class CUtlMemory<double,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<double,CUtlMemory<double,int>>::InsertMultipleBefore(
        CUtlVector<double,CUtlMemory<double,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  long double *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10189360
// Name: public: int CUtlVector<struct vehicle_gear_t,class CUtlMemory<struct vehicle_gear_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>::InsertMultipleBefore(
        CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vehicle_gear_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  vehicle_gear_t *v11; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->__vftable = (vehicle_gear_t_vtbl *)&vehicle_gear_t::`vftable';
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101893F0
// Name: public: int CUtlVector<struct vehicle_crashsound_t,class CUtlMemory<struct vehicle_crashsound_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>::InsertMultipleBefore(
        CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vehicle_crashsound_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  vehicle_crashsound_t *v11; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->__vftable = (vehicle_crashsound_t_vtbl *)&vehicle_crashsound_t::`vftable';
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101898A0
// Name: public: int CUtlVector<struct touchevent_t,class CUtlMemory<struct touchevent_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<touchevent_t,CUtlMemory<touchevent_t,int>>::AddToTail(
        CUtlVector<touchevent_t,CUtlMemory<touchevent_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  touchevent_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<touchevent_t,int>::Grow(
      (CUtlMemory<CAI_InterestTarget_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 36 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1018AE20
// Name: public: int CUtlVector<class CConstraintFloodEntry,class CUtlMemory<class CConstraintFloodEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CConstraintFloodEntry,CUtlMemory<CConstraintFloodEntry,int>>::InsertBefore(
        CUtlVector<CConstraintFloodEntry,CUtlMemory<CConstraintFloodEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CConstraintFloodEntry *m_pMemory; // ecx
  int v6; // eax
  CConstraintFloodEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->linkList.m_Memory.m_pMemory = nullptr;
    v7->linkList.m_Memory.m_nAllocationCount = 0;
    v7->linkList.m_Memory.m_nGrowSize = 0;
    v7->linkList.m_Size = 0;
    v7->linkList.m_pElements = nullptr;
    *(_WORD *)&v7->isMarked = 0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1018BDF0
// Name: public: int CUtlVector<struct vehiclescript_t,class CUtlMemory<struct vehiclescript_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::InsertBefore(
        CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vehiclescript_t *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vehiclescript_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 916 * v6);
  Construct<vehiclescript_t>(pMemory: &this->m_Memory.m_pMemory[elem]);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1018BE60
// Name: public: void CUtlVector<class CConstraintFloodEntry,class CUtlMemory<class CConstraintFloodEntry,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CConstraintFloodEntry,CUtlMemory<CConstraintFloodEntry,int>>::RemoveAll(
        CUtlVector<CConstraintFloodEntry,CUtlMemory<CConstraintFloodEntry,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CConstraintFloodEntry,CUtlMemory<CConstraintFloodEntry,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C550
// Name: public: class CUtlVector<struct vehicle_gear_t,class CUtlMemory<struct vehicle_gear_t,int>> __near & CUtlVector<struct vehicle_gear_t,class CUtlMemory<struct vehicle_gear_t,int>>::operator=(class CUtlVector<struct vehicle_gear_t,class CUtlMemory<struct vehicle_gear_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *__thiscall CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>::operator=(
        CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *this,
        const CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *other)
{
  int m_Size; // ebx
  signed int v5; // eax
  vehicle_gear_t *m_pMemory; // ecx
  vehicle_gear_t *v7; // edx
  float *v8; // ecx
  vehicle_gear_t *v9; // edx
  int v10; // edx
  bool v11; // zf
  vehicle_gear_t *v12; // ecx
  vehicle_gear_t *v13; // edx
  vehicle_gear_t *v14; // ecx
  vehicle_gear_t *v15; // edx
  unsigned int v16; // edx
  int v17; // ebx
  vehicle_gear_t *v18; // eax
  vehicle_gear_t *v19; // ecx
  int i; // [esp+Ch] [ebp-8h]
  const CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *othera; // [esp+1Ch] [ebp+8h]

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>::InsertMultipleBefore(this, elem: 0, num: m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    othera = (const CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *)(((unsigned int)(m_Size - 4) >> 2) + 1);
    i = 4 * (_DWORD)othera;
    do
    {
      m_pMemory = other->m_Memory.m_pMemory;
      v7 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v7->flMinSpeed + v5) = *(float *)((char *)&other->m_Memory.m_pMemory->flMinSpeed + v5);
      *(float *)((char *)&v7->flMaxSpeed + v5) = *(float *)((char *)&m_pMemory->flMaxSpeed + v5);
      *(float *)((char *)&v7->flSpeedApproachFactor + v5) = *(float *)((char *)&m_pMemory->flSpeedApproachFactor + v5);
      v8 = (float *)((char *)&other->m_Memory.m_pMemory[1] + v5);
      v9 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v9[1].flMinSpeed + v5) = *(float *)((char *)&other->m_Memory.m_pMemory[1].flMinSpeed + v5);
      v10 = (int)&v9[1] + v5;
      *(float *)(v10 + 8) = v8[2];
      v5 += 64;
      v11 = othera == (const CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *)1;
      othera = (const CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *)((char *)othera - 1);
      *(float *)(v10 + 12) = v8[3];
      v12 = other->m_Memory.m_pMemory;
      v13 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v13[-1] + v5 - 12) = *(float *)((char *)&other->m_Memory.m_pMemory[-1] + v5 - 12);
      *(float *)((char *)&v13[-1] + v5 - 8) = *(float *)((char *)&v12[-1] + v5 - 8);
      *(float *)((char *)&v13[-1] + v5 - 4) = *(float *)((char *)&v12[-1] + v5 - 4);
      v14 = other->m_Memory.m_pMemory;
      v15 = this->m_Memory.m_pMemory;
      *(float *)((char *)v15 + v5 - 12) = *(float *)((char *)other->m_Memory.m_pMemory + v5 - 12);
      *(float *)((char *)v15 + v5 - 8) = *(float *)((char *)v14 + v5 - 8);
      *(float *)((char *)v15 + v5 - 4) = *(float *)((char *)v14 + v5 - 4);
    }
    while ( !v11 );
    v5 = i;
  }
  if ( v5 < m_Size )
  {
    v16 = v5;
    v17 = m_Size - v5;
    do
    {
      v18 = other->m_Memory.m_pMemory;
      v19 = this->m_Memory.m_pMemory;
      v19[v16].flMinSpeed = other->m_Memory.m_pMemory[v16].flMinSpeed;
      ++v16;
      --v17;
      v19[v16 - 1].flMaxSpeed = v18[v16 - 1].flMaxSpeed;
      v19[v16 - 1].flSpeedApproachFactor = v18[v16 - 1].flSpeedApproachFactor;
    }
    while ( v17 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018C650
// Name: public: class CUtlVector<struct vehicle_crashsound_t,class CUtlMemory<struct vehicle_crashsound_t,int>> __near & CUtlVector<struct vehicle_crashsound_t,class CUtlMemory<struct vehicle_crashsound_t,int>>::operator=(class CUtlVector<struct vehicle_crashsound_t,class CUtlMemory<struct vehicle_crashsound_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *__thiscall CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>::operator=(
        CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *this,
        const CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *other)
{
  int m_Size; // ebx
  int v5; // eax
  int v6; // edx
  vehicle_crashsound_t *m_pMemory; // eax
  vehicle_crashsound_t *v8; // ecx
  vehicle_crashsound_t *v9; // eax
  vehicle_crashsound_t *v10; // ecx
  vehicle_crashsound_t *v11; // eax
  vehicle_crashsound_t *v12; // ecx
  int v13; // ecx
  vehicle_crashsound_t *v14; // ecx
  vehicle_crashsound_t *v15; // eax
  vehicle_crashsound_t *v16; // ecx
  vehicle_crashsound_t *v17; // eax
  vehicle_crashsound_t *v18; // ecx
  bool v19; // zf
  int v20; // edx
  vehicle_crashsound_t *v21; // ecx
  vehicle_crashsound_t *v22; // eax
  vehicle_crashsound_t *v23; // ecx
  int i; // [esp+Ch] [ebp-8h]
  const CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *othera; // [esp+1Ch] [ebp+8h]
  const CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *otherb; // [esp+1Ch] [ebp+8h]

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>::InsertMultipleBefore(
    this,
    elem: 0,
    num: m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    v6 = 0;
    othera = (const CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *)(((unsigned int)(m_Size - 4) >> 2)
                                                                                            + 1);
    i = 4 * (_DWORD)othera;
    do
    {
      m_pMemory = other->m_Memory.m_pMemory;
      v8 = this->m_Memory.m_pMemory;
      v8[v6].flMinSpeed = other->m_Memory.m_pMemory[v6].flMinSpeed;
      v9 = &m_pMemory[v6];
      v10 = &v8[v6];
      v10->flMinDeltaSpeed = v9->flMinDeltaSpeed;
      v10->gearLimit = v9->gearLimit;
      v10->iszCrashSound.pszValue = v9->iszCrashSound.pszValue;
      v11 = &other->m_Memory.m_pMemory[v6 + 1];
      v12 = this->m_Memory.m_pMemory;
      v12[v6 + 1].flMinSpeed = other->m_Memory.m_pMemory[v6 + 1].flMinSpeed;
      v13 = (int)&v12[v6 + 1];
      *(float *)(v13 + 8) = v11->flMinDeltaSpeed;
      *(_DWORD *)(v13 + 12) = v11->gearLimit;
      *(_DWORD *)(v13 + 16) = v11->iszCrashSound.pszValue;
      v14 = this->m_Memory.m_pMemory;
      v15 = &other->m_Memory.m_pMemory[v6 + 2];
      v14[v6 + 2].flMinSpeed = v15->flMinSpeed;
      v16 = &v14[v6 + 2];
      v16->flMinDeltaSpeed = v15->flMinDeltaSpeed;
      v16->gearLimit = v15->gearLimit;
      v16->iszCrashSound.pszValue = v15->iszCrashSound.pszValue;
      v17 = &other->m_Memory.m_pMemory[v6 + 3];
      v18 = &this->m_Memory.m_pMemory[v6 + 3];
      v18->flMinSpeed = v17->flMinSpeed;
      v6 += 4;
      v19 = othera == (const CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *)1;
      othera = (const CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *)((char *)othera - 1);
      v18->flMinDeltaSpeed = v17->flMinDeltaSpeed;
      v18->gearLimit = v17->gearLimit;
      v18->iszCrashSound.pszValue = v17->iszCrashSound.pszValue;
    }
    while ( !v19 );
    v5 = i;
  }
  if ( v5 < m_Size )
  {
    v20 = v5;
    otherb = (const CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *)(m_Size - v5);
    do
    {
      v21 = this->m_Memory.m_pMemory;
      v22 = &other->m_Memory.m_pMemory[v20];
      v21[v20].flMinSpeed = v22->flMinSpeed;
      v23 = &v21[v20];
      v23->flMinDeltaSpeed = v22->flMinDeltaSpeed;
      v23->gearLimit = v22->gearLimit;
      ++v20;
      v19 = otherb == (const CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *)1;
      otherb = (const CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *)((char *)otherb - 1);
      v23->iszCrashSound.pszValue = v22->iszCrashSound.pszValue;
    }
    while ( !v19 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018C970
// Name: public: void CUtlVector<struct vehiclescript_t,class CUtlMemory<struct vehiclescript_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::RemoveAll(
        CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 916 * v1;
    v7 = 916 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 178) = 0;
      if ( *((int *)v3 + 177) >= 0 )
      {
        if ( *((_DWORD *)v3 + 175) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 175));
          *((_DWORD *)v3 + 175) = 0;
        }
        *((_DWORD *)v3 + 176) = 0;
      }
      v4 = *((void **)v3 + 175);
      *((_DWORD *)v3 + 179) = v4;
      if ( *((int *)v3 + 177) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 175) = 0;
        }
        *((_DWORD *)v3 + 176) = 0;
      }
      *((_DWORD *)v3 + 173) = 0;
      if ( *((int *)v3 + 172) >= 0 )
      {
        if ( *((_DWORD *)v3 + 170) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 170));
          *((_DWORD *)v3 + 170) = 0;
        }
        *((_DWORD *)v3 + 171) = 0;
      }
      v5 = *((void **)v3 + 170);
      *((_DWORD *)v3 + 174) = v5;
      if ( *((int *)v3 + 172) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 170) = 0;
        }
        *((_DWORD *)v3 + 171) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 916;
      v7 -= 916;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CE60
// Name: public: CUtlVector<struct vehiclescript_t,class CUtlMemory<struct vehiclescript_t,int>>::~CUtlVector<struct vehiclescript_t,class CUtlMemory<struct vehiclescript_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::~CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>(
        CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int> > *this)
{
  bool v2; // sf
  vehiclescript_t *m_pMemory; // eax

  CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018DCB0
// Name: public: int CUtlVector<struct physfollower_t,class CUtlMemory<struct physfollower_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int>>::InsertBefore(
        CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  physfollower_t *m_pMemory; // ecx
  int v6; // eax
  physfollower_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->hFollower.m_Index = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101940A0
// Name: public: int CUtlVector<struct CPhysicsPushedEntities::PhysicsPusherInfo_t,class CUtlMemory<struct CPhysicsPushedEntities::PhysicsPusherInfo_t,int>>::AddVectorToTail(class CUtlVector<struct CPhysicsPushedEntities::PhysicsPusherInfo_t,class CUtlMemory<struct CPhysicsPushedEntities::PhysicsPusherInfo_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPhysicsPushedEntities::PhysicsPusherInfo_t,CUtlMemory<CPhysicsPushedEntities::PhysicsPusherInfo_t,int>>::AddVectorToTail(
        CUtlVector<CPhysicsPushedEntities::PhysicsPusherInfo_t,CUtlMemory<CPhysicsPushedEntities::PhysicsPusherInfo_t,int> > *this,
        const CUtlVector<CPhysicsPushedEntities::PhysicsPusherInfo_t,CUtlMemory<CPhysicsPushedEntities::PhysicsPusherInfo_t,int> > *src)
{
  int m_Size; // ebx
  int v4; // edx
  int v5; // eax
  CPhysicsPushedEntities::PhysicsPusherInfo_t *m_pMemory; // edx
  CPhysicsPushedEntities::PhysicsPusherInfo_t *v7; // eax
  CPhysicsPushedEntities::PhysicsPusherInfo_t *v8; // ecx
  int v9; // edi
  int v10; // edx
  CPhysicsPushedEntities::PhysicsPusherInfo_t *v11; // ecx
  CPhysicsPushedEntities::PhysicsPusherInfo_t *v12; // eax
  unsigned int v14; // [esp-4h] [ebp-14h]
  int base; // [esp+Ch] [ebp-4h]

  m_Size = src->m_Size;
  v4 = this->m_Size;
  v5 = m_Size + v4;
  base = v4;
  if ( this->m_Memory.m_nAllocationCount < m_Size + v4 && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v5;
    v14 = 16 * v5;
    if ( m_pMemory != nullptr )
      v7 = (CPhysicsPushedEntities::PhysicsPusherInfo_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v14);
    else
      v7 = (CPhysicsPushedEntities::PhysicsPusherInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v14);
    v4 = base;
    this->m_Memory.m_pMemory = v7;
  }
  v8 = this->m_Memory.m_pMemory;
  this->m_Size += m_Size;
  this->m_pElements = v8;
  if ( m_Size <= 0 )
    return v4;
  v9 = 0;
  v10 = v4;
  do
  {
    v11 = &this->m_Memory.m_pMemory[v10];
    v12 = src->m_Memory.m_pMemory;
    if ( v11 != nullptr )
    {
      *(_QWORD *)&v11->m_pEntity = *(_QWORD *)&v12[v9].m_pEntity;
      *(_QWORD *)&v11->m_vecStartAbsOrigin.y = *(_QWORD *)&v12[v9].m_vecStartAbsOrigin.y;
    }
    ++v9;
    ++v10;
    --m_Size;
  }
  while ( m_Size != 0 );
  return base;
}

//------------------------------------------------------------------------------
// Address: 0x10194780
// Name: public: int CUtlVector<struct CPhysicsPushedEntities::PhysicsPusherInfo_t,class CUtlMemory<struct CPhysicsPushedEntities::PhysicsPusherInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPhysicsPushedEntities::PhysicsPusherInfo_t,CUtlMemory<CPhysicsPushedEntities::PhysicsPusherInfo_t,int>>::AddToTail(
        CUtlVector<CPhysicsPushedEntities::PhysicsPusherInfo_t,CUtlMemory<CPhysicsPushedEntities::PhysicsPusherInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CPhysicsPushedEntities::PhysicsPusherInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10199D90
// Name: public: CUtlVector<class CUtlVector<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>>,class CUtlMemory<class CUtlVector<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<class CUtlVector<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>>,class CUtlMemory<class CUtlVector<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(
        CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6480
// Name: public: int CUtlVector<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,class CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPhysSaveRestoreBlockHandler::QueuedItem_t,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::InsertBefore(
        CUtlVector<CPhysSaveRestoreBlockHandler::QueuedItem_t,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // ecx
  int v6; // eax
  CPhysSaveRestoreBlockHandler::QueuedItem_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
      (CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 56 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->header.hEntity.m_Index = -1;
    memset(dst: (unsigned __int8 *)v7, value: 0, count: 0x34u);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101B04C0
// Name: public: int CUtlVector<struct magnetted_objects_t,class CUtlMemory<struct magnetted_objects_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<magnetted_objects_t,CUtlMemory<magnetted_objects_t,int>>::InsertMultipleBefore(
        CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  physfollower_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  physfollower_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->hFollower.m_Index = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101B0990
// Name: public: int CUtlVector<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,int>>::InsertBefore(int,struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
        CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *this,
        int elem,
        const AI_NamespaceAddInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AI_NamespaceAddInfo_t *m_pMemory; // ecx
  int v7; // eax
  AI_NamespaceAddInfo_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C6400
// Name: public: int CUtlVector<class CCommandContext,class CUtlMemory<class CCommandContext,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::InsertBefore(
        CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CCommandContext *m_pMemory; // ecx
  int v6; // eax
  CCommandContext *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<touchevent_t,int>::Grow(
      (CUtlMemory<CAI_InterestTarget_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->cmds.m_Memory.m_pMemory = nullptr;
    v7->cmds.m_Memory.m_nAllocationCount = 0;
    v7->cmds.m_Memory.m_nGrowSize = 0;
    v7->cmds.m_Size = 0;
    v7->cmds.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C6480
// Name: public: void CUtlVector<class CCommandContext,class CUtlMemory<class CCommandContext,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::RemoveMultiple(
        CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int> > *this,
        int elem,
        int num)
{
  int v3; // edx
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  int v8; // ecx
  char *v9; // esi
  int v10; // edi
  int v11; // ebx
  void *v12; // eax
  bool v13; // zf
  CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int> > *v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h]

  v3 = elem;
  v5 = num;
  v6 = elem + num;
  v7 = elem + num - 1;
  v14 = this;
  if ( v7 >= elem )
  {
    v8 = 36 * v7;
    v16 = 36 * v7;
    v15 = num;
    do
    {
      v9 = (char *)this->m_Memory.m_pMemory + v8;
      v10 = *((_DWORD *)v9 + 3) - 1;
      if ( v10 >= 0 )
      {
        v11 = 88 * v10;
        do
        {
          (**(void (__thiscall ***)(int, _DWORD))(*(_DWORD *)v9 + v11))(a1: v11 + *(_DWORD *)v9, a2: 0);
          v11 -= 88;
          --v10;
        }
        while ( v10 >= 0 );
        this = v14;
      }
      *((_DWORD *)v9 + 3) = 0;
      if ( *((int *)v9 + 2) >= 0 )
      {
        if ( *(_DWORD *)v9 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v9);
          *(_DWORD *)v9 = 0;
        }
        *((_DWORD *)v9 + 1) = 0;
      }
      v12 = *(void **)v9;
      *((_DWORD *)v9 + 4) = *(_DWORD *)v9;
      if ( *((int *)v9 + 2) >= 0 )
      {
        if ( v12 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
          *(_DWORD *)v9 = 0;
        }
        *((_DWORD *)v9 + 1) = 0;
      }
      v8 = v16 - 36;
      v13 = v15-- == 1;
      v16 -= 36;
    }
    while ( !v13 );
    v5 = num;
    v6 = elem + num;
    v3 = elem;
  }
  if ( this->m_Size - v3 - v5 > 0 && v5 > 0 )
  {
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[v3],
      src: &this->m_Memory.m_pMemory[v6],
      count: 36 * (this->m_Size - v3 - v5));
    v5 = num;
  }
  this->m_Size -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x101C6580
// Name: public: void CUtlVector<class CCommandContext,class CUtlMemory<class CCommandContext,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::RemoveAll(
        CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int> > *this)
{
  int v1; // eax
  int v2; // eax
  char *v3; // esi
  int v4; // edi
  int v5; // ebx
  void *v6; // eax
  CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int> > *v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v7 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 36 * v1;
    v8 = v2;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      v4 = *((_DWORD *)v3 + 3) - 1;
      if ( v4 >= 0 )
      {
        v5 = 88 * v4;
        do
        {
          (**(void (__thiscall ***)(int, _DWORD))(*(_DWORD *)v3 + v5))(a1: v5 + *(_DWORD *)v3, a2: 0);
          v5 -= 88;
          --v4;
        }
        while ( v4 >= 0 );
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v6 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v6 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v2 = v8 - 36;
      --i;
      this = v7;
      v8 -= 36;
    }
    while ( i >= 0 );
    v7->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7110
// Name: public: CUtlVector<class CCommandContext,class CUtlMemory<class CCommandContext,int>>::~CUtlVector<class CCommandContext,class CUtlMemory<class CCommandContext,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::~CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>(
        CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int> > *this)
{
  bool v2; // sf
  CCommandContext *m_pMemory; // eax

  CUtlVector<CCommandContext,CUtlMemory<CCommandContext,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D0850
// Name: public: int CUtlVector<enum CSWeaponID,class CUtlMemory<enum CSWeaponID,int>>::Find(enum CSWeaponID const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
        CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *this,
        CBaseEntity **src)
{
  int m_Size; // edx
  int result; // eax
  CBaseEntity **i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D6EF0
// Name: public: int CUtlVector<struct template_t,class CUtlMemory<struct template_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<template_t,CUtlMemory<template_t,int>>::InsertMultipleBefore(
        CUtlVector<template_t,CUtlMemory<template_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  template_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<template_t,int>::Grow(
      (CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 68 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101D7020
// Name: public: int CUtlVector<struct template_t,class CUtlMemory<struct template_t,int>>::InsertBefore(int,struct template_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<template_t,CUtlMemory<template_t,int>>::InsertBefore(
        CUtlVector<template_t,CUtlMemory<template_t,int> > *this,
        int elem,
        const template_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  template_t *m_pMemory; // ecx
  int v7; // eax
  template_t *v8; // edi
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<template_t,int>::Grow(
      (CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  result = elem;
  if ( v8 != nullptr )
    qmemcpy(v8, src, sizeof(template_t));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF2B0
// Name: public: void CUtlVector<struct breakmodel_t,class CUtlMemory<struct breakmodel_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int>>::EnsureCapacity(
        CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int> > *this,
        int num)
{
  breakmodel_t *m_pMemory; // edx
  unsigned int v4; // eax
  breakmodel_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 1068 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (breakmodel_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (breakmodel_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0130
// Name: public: int CUtlVector<struct CPropData::propdata_breakablechunk_t,class CUtlMemory<struct CPropData::propdata_breakablechunk_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPropData::propdata_breakablechunk_t,CUtlMemory<CPropData::propdata_breakablechunk_t,int>>::InsertBefore(
        CUtlVector<CPropData::propdata_breakablechunk_t,CUtlMemory<CPropData::propdata_breakablechunk_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPropData::propdata_breakablechunk_t *m_pMemory; // ecx
  int v6; // eax
  CPropData::propdata_breakablechunk_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->iszChunkModels.m_Memory.m_pMemory = nullptr;
    v7->iszChunkModels.m_Memory.m_nAllocationCount = 0;
    v7->iszChunkModels.m_Memory.m_nGrowSize = 0;
    v7->iszChunkModels.m_Size = 0;
    v7->iszChunkModels.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101FC970
// Name: public: int CUtlVector<class CUtlVector<struct CEntityDataInstantiator<struct touchlink_t>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct touchlink_t>::HashEntry,int>>,class CUtlMemory<class CUtlVector<struct CEntityDataInstantiator<struct touchlink_t>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101FCED0
// Name: public: int CUtlVector<struct SaveRestoreBlockHeader_t,class CUtlMemory<struct SaveRestoreBlockHeader_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>::InsertMultipleBefore(
        CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SaveRestoreBlockHeader_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<SaveRestoreBlockHeader_t,int>::Grow(
      (CUtlMemory<AIChannelScheduleState_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10203970
// Name: public: int CUtlVector<struct CSceneManager::CRestoreSceneSound,class CUtlMemory<struct CSceneManager::CRestoreSceneSound,int>>::InsertBefore(int,struct CSceneManager::CRestoreSceneSound const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSceneManager::CRestoreSceneSound,CUtlMemory<CSceneManager::CRestoreSceneSound,int>>::InsertBefore(
        CUtlVector<CSceneManager::CRestoreSceneSound,CUtlMemory<CSceneManager::CRestoreSceneSound,int> > *this,
        int elem,
        const CSceneManager::CRestoreSceneSound *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSceneManager::CRestoreSceneSound *m_pMemory; // ecx
  int v7; // eax
  CSceneManager::CRestoreSceneSound *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CSceneManager::CRestoreSceneSound,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 140 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10203A10
// Name: public: int CUtlVector<struct NPCInterjection,class CUtlMemory<struct NPCInterjection,int>>::InsertBefore(int,struct NPCInterjection const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<NPCInterjection,CUtlMemory<NPCInterjection,int>>::InsertBefore(
        CUtlVector<NPCInterjection,CUtlMemory<NPCInterjection,int> > *this,
        int elem,
        const NPCInterjection *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  NPCInterjection *m_pMemory; // ecx
  int v7; // eax
  NPCInterjection *v8; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<NPCInterjection,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 172 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    ResponseRules::CRR_Response::CRR_Response(this: &v8->response, from: &src->response);
    v8->npc = src->npc;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1021A170
// Name: public: void CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::RemoveAll(
        CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl*)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short> > *v3; // esi
  bool (__cdecl *m_LessFunc)(const AsyncCaption_t::BlockInfo_t *, const AsyncCaption_t::BlockInfo_t *); // eax
  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 84 * v1;
    for ( i = 84 * v1; ; v2 = i )
    {
      v3 = (CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl*)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short> > *)((char *)&this->m_Memory.m_pMemory->m_RequestedBlocks + v2);
      v3[1].m_Elements.m_nGrowSize = 0;
      if ( v3[1].m_Elements.m_nAllocationCount >= 0 )
      {
        if ( v3[1].m_LessFunc != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3[1].m_LessFunc);
          v3[1].m_LessFunc = nullptr;
        }
        v3[1].m_Elements.m_pMemory = nullptr;
      }
      m_LessFunc = v3[1].m_LessFunc;
      *(_DWORD *)&v3[1].m_Root = m_LessFunc;
      if ( v3[1].m_Elements.m_nAllocationCount >= 0 )
      {
        if ( m_LessFunc != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_LessFunc);
          v3[1].m_LessFunc = nullptr;
        }
        v3[1].m_Elements.m_pMemory = nullptr;
      }
      CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: v3);
      v3->m_FirstFree = -1;
      if ( v3->m_Elements.m_nGrowSize >= 0 )
      {
        if ( v3->m_Elements.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Elements.m_pMemory);
          v3->m_Elements.m_pMemory = nullptr;
        }
        v3->m_Elements.m_nAllocationCount = 0;
      }
      v3->m_LastAlloc.index = -1;
      if ( v3->m_Elements.m_nGrowSize >= 0 )
      {
        if ( v3->m_Elements.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Elements.m_pMemory);
          v3->m_Elements.m_pMemory = nullptr;
        }
        v3->m_Elements.m_nAllocationCount = 0;
      }
      i -= 84;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B1C0
// Name: public: CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>>::~CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::~CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>(
        CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *this)
{
  bool v2; // sf
  AsyncCaption_t *m_pMemory; // eax

  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102214C0
// Name: public: int CUtlVector<struct bbox_t,class CUtlMemory<struct bbox_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bbox_t,CUtlMemory<bbox_t,int>>::InsertMultipleBefore(
        CUtlVector<bbox_t,CUtlMemory<bbox_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bbox_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102216F0
// Name: public: void CUtlVector<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlMemory<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,int> > *this)
{
  int v1; // edi
  int v2; // eax
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v3; // esi
  CUtlBinaryBlock *m_pMemory; // eax
  CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    for ( i = 20 * v1; ; v2 = i )
    {
      v3 = (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)((char *)this->m_Memory.m_pMemory + v2);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: v3);
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      i -= 20;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10221B80
// Name: public: CUtlVector<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlMemory<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,int>>::~CUtlVector<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlMemory<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,int>>::~CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,int>>(
        CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10228E50
// Name: public: int CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(
        CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->activityIdx = -1;
          v11->startingIdx = -1;
          v11->count = -1;
          v11->totalWeight = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10256FA0
// Name: public: virtual class CUtlVector<class CPassengerSeatTransition,class CUtlMemory<class CPassengerSeatTransition,int>> const __near * CBaseServerVehicle::NPC_GetPassengerSeatAnims(class CBaseCombatCharacter __near *,enum PassengerSeatAnimType_t)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CPassengerSeatTransition,CUtlMemory<CPassengerSeatTransition,int> > *__thiscall CBaseServerVehicle::NPC_GetPassengerSeatAnims(
        CBaseServerVehicle *this,
        CBaseCombatCharacter *pPassenger,
        PassengerSeatAnimType_t nType)
{
  int v3; // esi
  CHandle<CBaseCombatCharacter> *i; // edi
  unsigned int m_Index; // eax
  CBaseCombatCharacter *m_pEntity; // edx
  CPassengerInfo *m_pMemory; // edx
  int v9; // eax
  int m_nSeat; // esi
  int m_nRole; // eax
  int m_Size; // [esp+Ch] [ebp-4h]

  v3 = 0;
  m_Size = this->m_PassengerInfo.m_Size;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = &this->m_PassengerInfo.m_Memory.m_pMemory->m_hPassenger; ; i += 5 )
  {
    m_Index = i->m_Index;
    if ( i->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseCombatCharacter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == pPassenger )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
  }
  m_pMemory = this->m_PassengerInfo.m_Memory.m_pMemory;
  v9 = v3;
  m_nSeat = m_pMemory[v3].m_nSeat;
  m_nRole = m_pMemory[v9].m_nRole;
  if ( nType != PASSENGER_SEAT_ENTRY )
  {
    if ( nType == PASSENGER_SEAT_EXIT )
      return &this->m_PassengerRoles.m_Memory.m_pMemory[m_nRole].m_PassengerSeats.m_Memory.m_pMemory[m_nSeat].m_ExitTransitions;
    return nullptr;
  }
  return &this->m_PassengerRoles.m_Memory.m_pMemory[m_nRole].m_PassengerSeats.m_Memory.m_pMemory[m_nSeat].m_EntryTransitions;
}

//------------------------------------------------------------------------------
// Address: 0x102589F0
// Name: public: int CUtlVector<class CPassengerInfo,class CUtlMemory<class CPassengerInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>::InsertMultipleBefore(
        CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPassengerInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CPassengerInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_nRole = -1;
          v11->m_nSeat = -1;
          v11->m_strRoleName.pszValue = nullptr;
          v11->m_strSeatName.pszValue = nullptr;
          v11->m_hPassenger.m_Index = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10258DE0
// Name: public: int CUtlVector<struct vehicle_gear_t,class CUtlMemory<struct vehicle_gear_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>::InsertBefore(
        CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vehicle_gear_t *m_pMemory; // ecx
  int v6; // eax
  vehicle_gear_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->__vftable = (vehicle_gear_t_vtbl *)&vehicle_gear_t::`vftable';
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10258E50
// Name: public: int CUtlVector<struct vehicle_crashsound_t,class CUtlMemory<struct vehicle_crashsound_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>::InsertBefore(
        CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vehicle_crashsound_t *m_pMemory; // ecx
  int v6; // eax
  vehicle_crashsound_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->__vftable = (vehicle_crashsound_t_vtbl *)&vehicle_crashsound_t::`vftable';
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10258EC0
// Name: public: int CUtlVector<class CPassengerInfo,class CUtlMemory<class CPassengerInfo,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int>>::InsertBefore(
        CUtlVector<CPassengerInfo,CUtlMemory<CPassengerInfo,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPassengerInfo *m_pMemory; // ecx
  int v6; // eax
  CPassengerInfo *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_nRole = -1;
    v7->m_nSeat = -1;
    v7->m_strRoleName.pszValue = nullptr;
    v7->m_strSeatName.pszValue = nullptr;
    v7->m_hPassenger.m_Index = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1025A300
// Name: public: int CUtlVector<class CPassengerSeat,class CUtlMemory<class CPassengerSeat,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPassengerSeat,CUtlMemory<CPassengerSeat,int>>::InsertBefore(
        CUtlVector<CPassengerSeat,CUtlMemory<CPassengerSeat,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPassengerSeat *m_pMemory; // ecx
  int v6; // eax
  CPassengerSeat *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<AI_Waypoint_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_nAttachmentID = -1;
    v7->m_EntryTransitions.m_Memory.m_pMemory = nullptr;
    v7->m_EntryTransitions.m_Memory.m_nAllocationCount = 0;
    v7->m_EntryTransitions.m_Memory.m_nGrowSize = 0;
    v7->m_EntryTransitions.m_Size = 0;
    v7->m_EntryTransitions.m_pElements = nullptr;
    v7->m_ExitTransitions.m_Memory.m_pMemory = nullptr;
    v7->m_ExitTransitions.m_Memory.m_nAllocationCount = 0;
    v7->m_ExitTransitions.m_Memory.m_nGrowSize = 0;
    v7->m_ExitTransitions.m_Size = 0;
    v7->m_ExitTransitions.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1025AE00
// Name: public: void CUtlVector<class CPassengerSeat,class CUtlMemory<class CPassengerSeat,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CPassengerSeat,CUtlMemory<CPassengerSeat,int>>::RemoveAll(
        CUtlVector<CPassengerSeat,CUtlMemory<CPassengerSeat,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CPassengerSeat,CUtlMemory<CPassengerSeat,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 48 * v1;
    v7 = 48 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 10) = 0;
      if ( *((int *)v3 + 9) >= 0 )
      {
        if ( *((_DWORD *)v3 + 7) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 7));
          *((_DWORD *)v3 + 7) = 0;
        }
        *((_DWORD *)v3 + 8) = 0;
      }
      v4 = *((void **)v3 + 7);
      *((_DWORD *)v3 + 11) = v4;
      if ( *((int *)v3 + 9) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 7) = 0;
        }
        *((_DWORD *)v3 + 8) = 0;
      }
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v5 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v5;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 48;
      v7 -= 48;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025AEF0
// Name: public: void CUtlVector<class CPassengerRole,class CUtlMemory<class CPassengerRole,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CPassengerRole,CUtlMemory<CPassengerRole,int>>::RemoveAll(
        CUtlVector<CPassengerRole,CUtlMemory<CPassengerRole,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CPassengerRole *v3; // esi
  bool v4; // sf
  CPassengerSeat *m_pMemory; // eax
  CUtlVector<CPassengerRole,CUtlMemory<CPassengerRole,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<CPassengerSeat,CUtlMemory<CPassengerSeat,int>>::RemoveAll(this: &v3->m_PassengerSeats);
      if ( v3->m_PassengerSeats.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_PassengerSeats.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_PassengerSeats.m_Memory.m_pMemory);
          v3->m_PassengerSeats.m_Memory.m_pMemory = nullptr;
        }
        v3->m_PassengerSeats.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_PassengerSeats.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_PassengerSeats.m_Memory.m_pMemory;
      v3->m_PassengerSeats.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_PassengerSeats.m_Memory.m_pMemory = nullptr;
        }
        v3->m_PassengerSeats.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1025B560
// Name: public: CUtlVector<class CPassengerRole,class CUtlMemory<class CPassengerRole,int>>::~CUtlVector<class CPassengerRole,class CUtlMemory<class CPassengerRole,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CPassengerRole,CUtlMemory<CPassengerRole,int>>::~CUtlVector<CPassengerRole,CUtlMemory<CPassengerRole,int>>(
        CUtlVector<CPassengerRole,CUtlMemory<CPassengerRole,int> > *this)
{
  bool v2; // sf
  CPassengerRole *m_pMemory; // eax

  CUtlVector<CPassengerRole,CUtlMemory<CPassengerRole,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BF10
// Name: public: void CUtlVector<struct SWeaponHitData __near *,class CUtlMemory<struct SWeaponHitData __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<SWeaponHitData *,CUtlMemory<SWeaponHitData *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027CD70
// Name: public: virtual class CUtlVector<class IGameStatTracker::IStatContainer __near *,class CUtlMemory<class IGameStatTracker::IStatContainer __near *,int>> __near * CCSGameStats::GetStatContainerList(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<IGameStatTracker::IStatContainer *,CUtlMemory<IGameStatTracker::IStatContainer *,int> > *__thiscall CCSGameStats::GetStatContainerList(
        CCSGameStats *this)
{
  return CCSGameStats::s_StatLists;
}

//------------------------------------------------------------------------------
// Address: 0x10285BB0
// Name: public: int CUtlVector<float,class CUtlMemory<float,int>>::InsertBefore(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        float *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v7; // eax
  float *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102A1BE0
// Name: public: virtual class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> const __near * GameTypes::GetWeaponProgressionForCurrentModeCT(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *__thiscall GameTypes::GetWeaponProgressionForCurrentModeCT(
        GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return &v6->m_WeaponProgressionCT;
}

//------------------------------------------------------------------------------
// Address: 0x102A1C80
// Name: public: virtual class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> const __near * GameTypes::GetWeaponProgressionForCurrentModeT(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *__thiscall GameTypes::GetWeaponProgressionForCurrentModeT(
        GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return &v6->m_WeaponProgressionT;
}

//------------------------------------------------------------------------------
// Address: 0x102A21F0
// Name: public: void CUtlVector<struct GameTypes::FreestyleBotDifficulty __near *,class CUtlMemory<struct GameTypes::FreestyleBotDifficulty __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int> > *this)
{
  int i; // ebx
  GameTypes::FreestyleBotDifficulty *v3; // edi
  KeyValues *m_pConvars; // ecx
  bool v5; // sf
  GameTypes::FreestyleBotDifficulty **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      m_pConvars = v3->m_pConvars;
      if ( m_pConvars != nullptr )
        KeyValues::deleteThis(this: m_pConvars);
      free(pMem: v3);
    }
  }
  v5 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v5 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A24C0
// Name: public: void CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(
        CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  IGameTypes::WeaponProgression *v3; // esi
  CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A2680
// Name: public: void CUtlVector<struct GameTypes::Map __near *,class CUtlMemory<struct GameTypes::Map __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int> > *this)
{
  int v2; // eax
  GameTypes::Map *v3; // esi
  char **m_pMemory; // eax
  char **v5; // eax
  GameTypes::Map **v6; // ecx
  int i; // [esp+8h] [ebp-8h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<SWeaponHitData *,CUtlMemory<SWeaponHitData *,int>>::PurgeAndDeleteElements(this: &v3->m_CTModels);
      v3->m_CTModels.m_Size = 0;
      if ( v3->m_CTModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_CTModels.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_CTModels.m_Memory.m_pMemory);
          v3->m_CTModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_CTModels.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_CTModels.m_Memory.m_pMemory;
      v3->m_CTModels.m_pElements = m_pMemory;
      if ( v3->m_CTModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_CTModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_CTModels.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<SWeaponHitData *,CUtlMemory<SWeaponHitData *,int>>::PurgeAndDeleteElements(this: &v3->m_TModels);
      v3->m_TModels.m_Size = 0;
      if ( v3->m_TModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_TModels.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_TModels.m_Memory.m_pMemory);
          v3->m_TModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TModels.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v3->m_TModels.m_Memory.m_pMemory;
      v3->m_TModels.m_pElements = v5;
      if ( v3->m_TModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          v3->m_TModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TModels.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v6 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A2BD0
// Name: public: void CUtlVector<struct GameTypes::GameMode __near *,class CUtlMemory<struct GameTypes::GameMode __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int> > *this)
{
  CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int> > *v1; // esi
  int v2; // eax
  GameTypes::GameMode *v3; // ebx
  KeyValues *m_pConvarsSP; // ecx
  KeyValues *m_pConvarsMP; // ecx
  IGameTypes::WeaponProgression *m_pMemory; // eax
  IGameTypes::WeaponProgression *v7; // eax
  char **v8; // eax
  GameTypes::GameMode **v9; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  for ( i = 0; v2 < v1->m_Size; i = v2 )
  {
    v3 = v1->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      m_pConvarsSP = v3->m_pConvarsSP;
      if ( m_pConvarsSP != nullptr )
        KeyValues::deleteThis(this: m_pConvarsSP);
      m_pConvarsMP = v3->m_pConvarsMP;
      if ( m_pConvarsMP != nullptr )
        KeyValues::deleteThis(this: m_pConvarsMP);
      CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(this: &v3->m_WeaponProgressionT);
      if ( v3->m_WeaponProgressionT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_WeaponProgressionT.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_WeaponProgressionT.m_Memory.m_pMemory);
          v3->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_WeaponProgressionT.m_Memory.m_pMemory;
      v3->m_WeaponProgressionT.m_pElements = m_pMemory;
      if ( v3->m_WeaponProgressionT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(this: &v3->m_WeaponProgressionCT);
      if ( v3->m_WeaponProgressionCT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_WeaponProgressionCT.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_WeaponProgressionCT.m_Memory.m_pMemory);
          v3->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
      }
      v7 = v3->m_WeaponProgressionCT.m_Memory.m_pMemory;
      v3->m_WeaponProgressionCT.m_pElements = v7;
      if ( v3->m_WeaponProgressionCT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v7 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
          v3->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<SWeaponHitData *,CUtlMemory<SWeaponHitData *,int>>::PurgeAndDeleteElements(this: &v3->m_Maps);
      v3->m_Maps.m_Size = 0;
      if ( v3->m_Maps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Maps.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Maps.m_Memory.m_pMemory);
          v3->m_Maps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Maps.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v3->m_Maps.m_Memory.m_pMemory;
      v3->m_Maps.m_pElements = v8;
      if ( v3->m_Maps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v8 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
          v3->m_Maps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Maps.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v1 = this;
      v2 = i;
    }
    ++v2;
  }
  v1->m_Size = 0;
  if ( v1->m_Memory.m_nGrowSize < 0 )
  {
    v1->m_pElements = v1->m_Memory.m_pMemory;
  }
  else
  {
    if ( v1->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Memory.m_pMemory);
      v1->m_Memory.m_pMemory = nullptr;
    }
    v9 = v1->m_Memory.m_pMemory;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_pElements = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A2DA0
// Name: public: void CUtlVector<struct GameTypes::GameType __near *,class CUtlMemory<struct GameTypes::GameType __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int> > *this)
{
  int v2; // eax
  GameTypes::GameType *v3; // esi
  GameTypes::GameMode **m_pMemory; // eax
  GameTypes::GameType **v5; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int>>::PurgeAndDeleteElements(this: &v3->m_GameModes);
      v3->m_GameModes.m_Size = 0;
      if ( v3->m_GameModes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_GameModes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_GameModes.m_Memory.m_pMemory);
          v3->m_GameModes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_GameModes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_GameModes.m_Memory.m_pMemory;
      v3->m_GameModes.m_pElements = m_pMemory;
      if ( v3->m_GameModes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_GameModes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_GameModes.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v5 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DED20
// Name: protected: void CUtlVector<struct CNavArea::AreaBindInfo,class CUtlMemoryConservative<struct CNavArea::AreaBindInfo>>::GrowVector(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::GrowVector(
        CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo> > *this,
        int num)
{
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // edi
  unsigned int v6; // eax
  CNavArea::AreaBindInfo *m_pMemory; // eax

  if ( this->m_Memory.m_pMemory != nullptr )
    v3 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
  else
    v3 = 0;
  if ( num + this->m_Size > (int)(v3 >> 3) )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
      v4 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
    else
      v4 = 0;
    v5 = num + this->m_Size - (v4 >> 3);
    if ( this->m_Memory.m_pMemory != nullptr )
      v6 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
    else
      v6 = 0;
    this->m_Memory.m_pMemory = (CNavArea::AreaBindInfo *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: this->m_Memory.m_pMemory,
                                                           a3: 8 * (v5 + (v6 >> 3)));
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size += num;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x102F6C80
// Name: public: void CUtlVector<class CNavArea __near *,class CUtlMemory<class CNavArea __near *,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>::FastRemove(
        CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *this,
        int elem)
{
  int m_Size; // edx

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
      this->m_Memory.m_pMemory[elem].m_Index = this->m_Memory.m_pMemory[m_Size - 1].m_Index;
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F73A0
// Name: public: void CUtlVector<class CNavArea __near *,class CUtlMemory<class CNavArea __near *,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>::Remove(
        CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102FABB0
// Name: protected: bool CUtlHash<struct NavVisPair_t,class CVisPairHashFuncs,class CVisPairHashFuncs>::DoFind(struct NavVisPair_t const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<NavVisPair_t,CVisPairHashFuncs,CVisPairHashFuncs>::DoFind(
        CUtlHash<NavVisPair_t,CVisPairHashFuncs,CVisPairHashFuncs> *this,
        const NavVisPair_t *src,
        unsigned int *pBucket,
        int *pIndex)
{
  CNavArea *v4; // eax
  CNavArea *v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edx
  CUtlVector<NavVisPair_t,CUtlMemory<NavVisPair_t,int> > *v9; // ecx
  int m_Size; // edx
  int v11; // eax
  CNavArea **pAreas; // ecx
  _DWORD pKey[2]; // [esp+8h] [ebp-8h] BYREF

  v4 = src->pAreas[1];
  v6 = src->pAreas[0];
  pKey[0] = (char *)src->pAreas[0] + v4->m_id;
  pKey[1] = (char *)v4 + v6->m_id;
  v7 = Hash8(pKey);
  if ( this->m_bPowerOfTwo )
    v8 = v7 & this->m_ModMask;
  else
    v8 = v7 % this->m_Buckets.m_Size;
  *pBucket = v8;
  v9 = &this->m_Buckets.m_Memory.m_pMemory[v8];
  m_Size = v9->m_Size;
  v11 = 0;
  if ( m_Size > 0 )
  {
    pAreas = v9->m_Memory.m_pMemory->pAreas;
    do
    {
      if ( *pAreas == src->pAreas[0] && pAreas[1] == src->pAreas[1] )
        break;
      ++v11;
      pAreas += 2;
    }
    while ( v11 < m_Size );
  }
  if ( v11 == m_Size )
    return 0;
  *pIndex = v11;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102FF680
// Name: public: class CUtlVector<struct CNavArea::AreaBindInfo,class CUtlMemoryConservative<struct CNavArea::AreaBindInfo>> __near & CUtlVector<struct CNavArea::AreaBindInfo,class CUtlMemoryConservative<struct CNavArea::AreaBindInfo>>::operator=(class CUtlVector<struct CNavArea::AreaBindInfo,class CUtlMemoryConservative<struct CNavArea::AreaBindInfo>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo> > *__thiscall CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::operator=(
        CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo> > *this,
        const CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo> > *other)
{
  int m_Size; // esi
  int i; // eax

  m_Size = other->m_Size;
  this->m_Size = 0;
  if ( m_Size != 0 )
  {
    CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::GrowVector(this, num: m_Size);
    if ( this->m_Size - m_Size > 0 && m_Size > 0 )
      _V_memmove(
        dest: &this->m_Memory.m_pMemory[m_Size],
        src: this->m_Memory.m_pMemory,
        count: 8 * (this->m_Size - m_Size));
  }
  for ( i = 0; i < m_Size; ++i )
    this->m_Memory.m_pMemory[i] = other->m_Memory.m_pMemory[i];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10300EE0
// Name: public: class CUtlVector<class CNavArea __near *,class CUtlMemory<class CNavArea __near *,int>> const __near & CNavMesh::GetSelectedSet(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *__thiscall CNavMesh::GetSelectedSet(CNavMesh *this)
{
  return &this->m_selectedSet;
}

//------------------------------------------------------------------------------
// Address: 0x1030AB20
// Name: public: void CUtlVector<struct OneWayLink_t,class CUtlMemoryFixedGrowable<struct OneWayLink_t,512,int>>::Sort(int (*)(struct OneWayLink_t const __near *,struct OneWayLink_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<OneWayLink_t,CUtlMemoryFixedGrowable<OneWayLink_t,512,int>>::Sort(
        CUtlVector<OneWayLink_t,CUtlMemoryFixedGrowable<OneWayLink_t,512,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // eax
  OneWayLink_t *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  int j; // ebx
  __int64 v8; // xmm0_8
  OneWayLink_t *v9; // eax
  int backD; // ecx
  int i; // [esp+4h] [ebp-4h]

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 0xCu, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      for ( i = v5; v5 >= 0; i = v5 )
      {
        if ( v5 >= 1 )
        {
          v6 = 1;
          for ( j = v5; j != 0; --j )
          {
            if ( pfnCompare(a1: &this->m_Memory.m_pMemory[v6 - 1], a2: &this->m_Memory.m_pMemory[v6]) < 0 )
            {
              v8 = *(_QWORD *)&this->m_Memory.m_pMemory[v6 - 1].destArea;
              v9 = &this->m_Memory.m_pMemory[v6];
              backD = v9[-1].backD;
              *(_QWORD *)&v9[-1].destArea = *(_QWORD *)&v9->destArea;
              v9[-1].backD = v9->backD;
              *(_QWORD *)&v9->destArea = v8;
              v9->backD = backD;
            }
            ++v6;
          }
          v5 = i;
        }
        --v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030B0F0
// Name: public: int CUtlVector<struct OneWayLink_t,class CUtlMemoryFixedGrowable<struct OneWayLink_t,512,int>>::InsertBefore(int,struct OneWayLink_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<OneWayLink_t,CUtlMemoryFixedGrowable<OneWayLink_t,512,int>>::InsertBefore(
        CUtlVector<OneWayLink_t,CUtlMemoryFixedGrowable<OneWayLink_t,512,int> > *this,
        int elem,
        const OneWayLink_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  OneWayLink_t *m_pMemory; // ecx
  int v8; // eax
  OneWayLink_t *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<OneWayLink_t,int>::ConvertToGrowableMemory(
        this: &this->m_Memory,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: v6);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v8);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10316650
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  PanelAnimationMapEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103208A0
// Name: public: void CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>>::Sort(int (*)(char const __near * const __near *,char const __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char const *,CUtlMemory<char const *,int>>::Sort(
        CUtlVector<char const *,CUtlMemory<char const *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  const char *v6; // ecx
  const char **v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6 = this->m_Memory.m_pMemory[j - 1];
            v7 = &this->m_Memory.m_pMemory[j];
            *(v7 - 1) = *v7;
            *v7 = v6;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321E60
// Name: public: void CUtlVector<class CUtlVector<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,int>>,class CUtlMemory<class CUtlVector<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103233B0
// Name: public: float CNavNode::GetGroundHeightAboveNode(enum NavCornerType)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNavNode::GetGroundHeightAboveNode(CNavNode *this, unsigned int cornerType)
{
  float v3; // xmm0_4
  float blockedHeight; // [esp+8h] [ebp+8h]

  if ( cornerType <= 3 )
    return this->m_groundHeightAboveNode[cornerType];
  v3 = 0.0;
  blockedHeight = 0.0;
  if ( this->m_groundHeightAboveNode[0] >= 0.0 )
  {
    v3 = this->m_groundHeightAboveNode[0];
    blockedHeight = v3;
  }
  if ( v3 <= this->m_groundHeightAboveNode[1] )
  {
    v3 = this->m_groundHeightAboveNode[1];
    blockedHeight = v3;
  }
  if ( v3 <= this->m_groundHeightAboveNode[2] )
  {
    v3 = this->m_groundHeightAboveNode[2];
    blockedHeight = v3;
  }
  if ( v3 <= this->m_groundHeightAboveNode[3] )
    return this->m_groundHeightAboveNode[3];
  return blockedHeight;
}

//------------------------------------------------------------------------------
// Address: 0x10323430
// Name: public: void CNavNode::ConnectTo(class CNavNode __near *,enum NavDirType,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavNode::ConnectTo(
        CNavNode *this,
        CNavNode *node,
        NavDirType dir,
        float obstacleHeight,
        float obstacleStartDist,
        float obstacleEndDist)
{
  this->m_obstacleHeight[dir] = obstacleHeight;
  this->m_obstacleStartDist[dir] = obstacleStartDist;
  this->m_to[dir] = node;
  this->m_obstacleEndDist[dir] = obstacleEndDist;
}

//------------------------------------------------------------------------------
// Address: 0x10323470
// Name: public: int CNavNode::IsClosedCell(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNavNode::IsClosedCell(CNavNode *this)
{
  CNavNode *v1; // edx
  CNavNode *v2; // eax
  CNavNode *v3; // ecx
  CNavNode *v4; // ecx
  BOOL result; // eax

  v1 = this->m_to[2];
  result = false;
  if ( v1 != nullptr && v1->m_to[Opposite[2]] == this )
  {
    v2 = this->m_to[1];
    if ( v2 != nullptr && v2->m_to[Opposite[1]] == this )
    {
      v3 = v2->m_to[2];
      if ( v3 != nullptr && v3->m_to[Opposite[2]] == v2 )
      {
        v4 = v1->m_to[1];
        if ( v4 != nullptr && v4->m_to[Opposite[1]] == v1 && v2->m_to[2] == v4 )
          return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103234D0
// Name: private: bool CNavNode::TestForCrouchArea(enum NavCornerType,class Vector const __near &,class Vector const __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CNavNode::TestForCrouchArea@<al>(
        CNavNode *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        NavCornerType cornerNum,
        const Vector *mins,
        const Vector *maxs,
        float *groundHeightAboveNode)
{
  float z; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // edx
  float v14; // xmm1_4
  float x; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  float v18; // xmm1_4
  float y; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm0_4
  float v24; // xmm6_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm1_4
  int v30; // eax
  int m_nValue; // eax
  Vector v33; // [esp+44h] [ebp-ECh] BYREF
  CGameTrace tr; // [esp+50h] [ebp-E0h] BYREF
  CTraceFilterWalkableEntities filter; // [esp+A8h] [ebp-88h] BYREF
  float maxHeight; // [esp+BCh] [ebp-74h]
  float v37; // [esp+C4h] [ebp-6Ch]
  float v38; // [esp+C8h] [ebp-68h]
  float v39; // [esp+CCh] [ebp-64h]
  float v40; // [esp+D4h] [ebp-5Ch]
  float v41; // [esp+D8h] [ebp-58h]
  float v42; // [esp+DCh] [ebp-54h]
  float v43; // [esp+E4h] [ebp-4Ch]
  float v44; // [esp+E8h] [ebp-48h]
  float v45; // [esp+ECh] [ebp-44h]
  int v46; // [esp+F4h] [ebp-3Ch]
  bool v47; // [esp+F8h] [ebp-38h]
  bool v48; // [esp+F9h] [ebp-37h]
  float v49; // [esp+108h] [ebp-28h]
  __int64 v50; // [esp+10Ch] [ebp-24h]
  float height; // [esp+114h] [ebp-1Ch]
  Vector end; // [esp+118h] [ebp-18h] BYREF
  Vector start; // [esp+124h] [ebp-Ch]
  float retaddr; // [esp+130h] [ebp+0h]

  start.x = a2;
  start.y = retaddr;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&tr.m_pEnt,
    passedict: nullptr,
    collisionGroup: 8,
    pExtraShouldHitFunc: nullptr);
  z = this->m_pos.z;
  *(_QWORD *)&end.x = *(_QWORD *)&this->m_pos.x;
  v50 = *(_QWORD *)&end.x;
  height = z;
  end.z = z;
  v38 = end.y - end.y;
  v37 = end.x - end.x;
  v39 = (float)(z + 58.0) - z;
  tr.m_pEnt = (CBaseEntity *)&CTraceFilterWalkableEntities::`vftable';
  filter.m_pPassEnt = (const IHandleEntity *)15;
  v46 = 0;
  v48 = (float)((float)((float)(v38 * v38) + (float)(v37 * v37)) + (float)(v39 * v39)) != 0.0;
  v44 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
  v43 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
  v45 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
  v47 = (float)((float)((float)(v44 * v44) + (float)(v43 * v43)) + (float)(v45 * v45)) < 0.000001;
  v10 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
  v11 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
  v12 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
  *(float *)&filter.m_pExtraShouldHitCheckFunction = v10 + end.x;
  *(float *)&filter.m_flags = v11 + end.y;
  maxHeight = v12 + z;
  v40 = v10 * -1.0;
  v41 = v11 * -1.0;
  v42 = v12 * -1.0;
  ((void (__thiscall *)(IEngineTrace *, bool (__cdecl **)(IHandleEntity *, int), int, CBaseEntity **, Vector *, int, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: &filter.m_pExtraShouldHitCheckFunction,
    a3: 147467,
    a4: &tr.m_pEnt,
    a5: &v33,
    a6: a3,
    a7: a4);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v33, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
  v13 = maxs->z;
  v50 = *(_QWORD *)&maxs->x;
  v14 = 0.0;
  *(float *)&filter.m_collisionGroup = tr.startpos.z - end.z;
  height = v13;
  v49 = 0.0;
  if ( (float)(tr.startpos.z - end.z) < 0.0 )
  {
LABEL_10:
    *groundHeightAboveNode = 58.0;
    this->m_isBlocked[cornerNum] = true;
    return 0;
  }
  while ( 1 )
  {
    x = mins->x;
    v16 = mins->z;
    v17 = this->m_pos.z + v14;
    v18 = *((float *)&v50 + 1) - mins->y;
    end.x = this->m_pos.x;
    y = this->m_pos.y;
    v37 = 0.0;
    v38 = 0.0;
    v39 = 0.0;
    end.y = y;
    v44 = v18 * 0.5;
    v43 = (float)(*(float *)&v50 - x) * 0.5;
    v45 = (float)(55.0 - v16) * 0.5;
    end.z = v17;
    v46 = 0;
    v48 = false;
    v47 = (float)((float)((float)(v44 * v44) + (float)(v43 * v43)) + (float)(v45 * v45)) < 0.000001;
    v20 = x + *(float *)&v50;
    v21 = v16 + 55.0;
    v22 = (float)(*((float *)&v50 + 1) + mins->y) * 0.5;
    *(float *)&filter.m_pExtraShouldHitCheckFunction = (float)(v20 * 0.5) + end.x;
    *(float *)&filter.m_flags = v22 + y;
    maxHeight = (float)(v21 * 0.5) + v17;
    v40 = (float)(v20 * 0.5) * -1.0;
    v41 = v22 * -1.0;
    v42 = (float)(v21 * 0.5) * -1.0;
    enginetrace->TraceRay(
      this: enginetrace,
      a2: (const Ray_t *)&filter.m_pExtraShouldHitCheckFunction,
      a3: 147467u,
      a4: (ITraceFilter *)&tr.m_pEnt,
      a5: (CGameTrace *)&v33);
    if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      DebugDrawLine(vecAbsStart: &v33, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
    if ( tr.plane.pad[1] == 0 )
      break;
    v14 = v49 + 1.0;
    v49 = v14;
    if ( *(float *)&filter.m_collisionGroup < v14 )
      goto LABEL_10;
  }
  v24 = *((float *)&v50 + 1);
  *groundHeightAboveNode = end.z - this->m_pos.z;
  v25 = mins->x;
  v26 = mins->z;
  v37 = 0.0;
  v38 = 0.0;
  v39 = 0.0;
  v43 = (float)(*(float *)&v50 - v25) * 0.5;
  v44 = (float)(v24 - mins->y) * 0.5;
  v45 = (float)(71.0 - v26) * 0.5;
  v46 = 0;
  v48 = false;
  v47 = (float)((float)((float)(v44 * v44) + (float)(v43 * v43)) + (float)(v45 * v45)) < 0.000001;
  v27 = v25 + *(float *)&v50;
  v28 = v26 + 71.0;
  v29 = (float)(mins->y + v24) * 0.5;
  *(float *)&filter.m_pExtraShouldHitCheckFunction = (float)(v27 * 0.5) + end.x;
  *(float *)&filter.m_flags = v29 + end.y;
  LODWORD(end.y) = &v33;
  maxHeight = (float)(v28 * 0.5) + end.z;
  v40 = (float)(v27 * 0.5) * -1.0;
  v41 = v29 * -1.0;
  v42 = (float)(v28 * 0.5) * -1.0;
  enginetrace->TraceRay(
    this: enginetrace,
    a2: (const Ray_t *)&filter.m_pExtraShouldHitCheckFunction,
    a3: 147467u,
    a4: (ITraceFilter *)&tr.m_pEnt,
    a5: (CGameTrace *)&v33);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v33, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
  if ( tr.plane.pad[1] != 0 )
  {
    if ( nav_test_node_crouch.m_pParent != nullptr )
      m_nValue = nav_test_node_crouch.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( m_nValue == this->m_id )
    {
      NDebugOverlay::Box(origin: &end, mins, maxs, r: 255, g: 0, b: 0, a: 100, flDuration: 100.0);
      return 0;
    }
    return 0;
  }
  if ( nav_test_node_crouch.m_pParent != nullptr )
    v30 = nav_test_node_crouch.m_pParent->m_Value.m_nValue;
  else
    v30 = 0;
  if ( v30 == this->m_id )
    NDebugOverlay::Box(origin: &end, mins, maxs, r: 0, g: 255, b: 255, a: 100, flDuration: 100.0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10323B30
// Name: private: void CNavNode::CheckCrouch(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNavNode::CheckCrouch(CNavNode *this@<ecx>, float a2@<ebp>)
{
  float y; // xmm1_4
  float x; // xmm2_4
  NavCornerType i; // esi
  int m_nValue; // eax
  float v7; // xmm7_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  int j; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  char v13; // al
  Vector v14; // [esp-Ch] [ebp-2Ch] BYREF
  Vector mins; // [esp+0h] [ebp-20h] BYREF
  Vector maxs; // [esp+Ch] [ebp-14h] BYREF
  Vector2D cornerVec; // [esp+18h] [ebp-8h]
  float retaddr; // [esp+20h] [ebp+0h]

  maxs.z = a2;
  cornerVec.x = retaddr;
  y = maxs.y;
  x = maxs.x;
  for ( i = NORTH_WEST; i < NUM_CORNERS; ++i )
  {
    if ( nav_test_node_crouch_dir.m_pParent == nullptr )
    {
      m_nValue = 0;
LABEL_6:
      if ( i != m_nValue )
        continue;
      goto LABEL_7;
    }
    m_nValue = nav_test_node_crouch_dir.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 4 )
      goto LABEL_6;
LABEL_7:
    switch ( i )
    {
      case NORTH_WEST:
        y = -1.0;
        goto LABEL_12;
      case NORTH_EAST:
        x = 1.0;
        y = -1.0;
        break;
      case SOUTH_EAST:
        x = 1.0;
        y = 1.0;
        break;
      case SOUTH_WEST:
        y = 1.0;
LABEL_12:
        x = -1.0;
        break;
      default:
        break;
    }
    v7 = fsqrt((float)(x * x) + (float)(y * y));
    if ( v7 == 0.0 )
    {
      v9 = 0.0;
      v8 = 0.0;
    }
    else
    {
      v8 = (float)(1.0 / v7) * x;
      v9 = (float)(1.0 / v7) * y;
    }
    maxs.x = v8;
    maxs.y = v9;
    memset((void *)&v14, 0, sizeof(v14));
    mins.x = 0.0;
    mins.y = 0.0;
    if ( v8 >= 0.0 )
    {
      if ( v8 > 0.0 )
        mins.x = 16.0;
    }
    else
    {
      v14.x = -16.0;
    }
    if ( v9 >= 0.0 )
    {
      if ( v9 > 0.0 )
        mins.y = 16.0;
    }
    else
    {
      v14.y = -16.0;
    }
    mins.z = 71.0;
    for ( j = 0; j < 12; j += 4 )
    {
      v11 = *(float *)((char *)&v14.x + j);
      v12 = *(float *)((char *)&mins.x + j);
      if ( v11 > v12 )
      {
        *(float *)((char *)&v14.x + j) = v12;
        *(float *)((char *)&mins.x + j) = v11;
      }
    }
    v13 = CNavNode::TestForCrouchArea(
            this,
            a2: COERCE_FLOAT((Vector *)&maxs.z),
            a3: (int)this,
            a4: i,
            cornerNum: i,
            mins: &v14,
            maxs: &mins,
            groundHeightAboveNode: &this->m_groundHeightAboveNode[i]);
    y = maxs.y;
    x = maxs.x;
    if ( v13 == 0 )
    {
      this->m_attributeFlags = 1;
      this->m_crouch[i] = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10323D00
// Name: protected: bool CUtlHash<class CNavNode __near *,class CNodeHashFuncs,class CNodeHashFuncs>::DoFind(class CNavNode __near * const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs>::DoFind(
        CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs> *this,
        CNavNode **src,
        CUtlVector<CNavNode *,CUtlMemory<CNavNode *,int> > *pBucket,
        int *pIndex)
{
  float **v4; // edi
  unsigned int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // edx
  int m_Size; // ebx
  CUtlVector<CNavNode *,CUtlMemory<CNavNode *,int> > *v10; // eax
  int v11; // edx
  float *v12; // edi
  float x; // xmm0_4
  _DWORD *v14; // ecx
  float *v15; // esi
  float *v16; // esi
  float *v17; // esi
  bool v18; // zf
  float *v19; // edi
  int v20; // ecx

  v4 = (float **)src;
  v6 = Hash8(pKey: *src);
  if ( this->m_bPowerOfTwo )
    v7 = v6 & this->m_ModMask;
  else
    v7 = v6 % this->m_Buckets.m_Size;
  pBucket->m_Memory.m_pMemory = (CNavNode **)v7;
  v8 = v7;
  m_Size = this->m_Buckets.m_Memory.m_pMemory[v8].m_Size;
  v10 = &this->m_Buckets.m_Memory.m_pMemory[v8];
  v11 = 0;
  if ( m_Size < 4 )
  {
LABEL_16:
    v18 = v11 == m_Size;
    if ( v11 >= m_Size )
      goto LABEL_26;
    v19 = *v4;
    v20 = (int)&v10->m_Memory.m_pMemory[v11];
    do
    {
      if ( **(float **)v20 == *v19 && *(float *)(*(_DWORD *)v20 + 4) == v19[1] )
        break;
      ++v11;
      v20 += 4;
    }
    while ( v11 < m_Size );
  }
  else
  {
    v12 = (float *)*src;
    x = (*src)->m_pos.x;
    v14 = v10->m_Memory.m_pMemory + 2;
    while ( 1 )
    {
      v15 = (float *)*(v14 - 2);
      if ( *v15 == x && v15[1] == v12[1] )
        break;
      v16 = (float *)*(v14 - 1);
      if ( *v16 == x && v16[1] == v12[1] )
      {
        ++v11;
        break;
      }
      if ( *(float *)*v14 == x && *(float *)(*v14 + 4) == v12[1] )
      {
        v11 += 2;
        break;
      }
      v17 = (float *)v14[1];
      if ( *v17 == x && v17[1] == v12[1] )
      {
        v11 += 3;
        break;
      }
      v11 += 4;
      v14 += 4;
      if ( v11 >= m_Size - 3 )
      {
        v4 = (float **)src;
        goto LABEL_16;
      }
    }
  }
  v18 = v11 == m_Size;
LABEL_26:
  if ( v18 )
    return 0;
  *pIndex = v11;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10323E50
// Name: public: void CNavNode::Draw(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CNavNode::Draw(CNavNode *this@<ecx>, float a2@<ebp>)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int m_nValue; // eax
  int v7; // eax
  float y; // xmm2_4
  float x; // xmm0_4
  int i; // edi
  bool v11; // cl
  __int128 v12; // xmm7
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  int j; // edi
  CNavNode *v18; // eax
  float v19; // xmm1_4
  float v20; // edx
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  _BYTE v27[28]; // [esp+28h] [ebp-3Ch] OVERLAPPED BYREF
  Vector from; // [esp+44h] [ebp-20h] BYREF
  Vector to; // [esp+50h] [ebp-14h] BYREF
  float z; // [esp+5Ch] [ebp-8h]
  float retaddr; // [esp+64h] [ebp+0h]

  to.z = a2;
  z = retaddr;
  if ( nav_show_nodes.m_pParent == nullptr || nav_show_nodes.m_pParent->m_Value.m_nValue == 0 )
    return;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( this->m_isCovered )
  {
    if ( (this->m_attributeFlags & 1) != 0 )
      v3 = 255;
    else
      v4 = 255;
  }
  else
  {
    if ( (this->m_attributeFlags & 1) != 0 )
      v3 = 255;
    v5 = 255;
  }
  NDebugOverlay::Cross3D(position: &this->m_pos, size: 2.0, r: v4, g: v5, b: v3, noDepthTest: true, flDuration: 0.1);
  if ( !this->m_isCovered )
  {
    if ( nav_show_node_id.m_pParent == nullptr || nav_show_node_id.m_pParent->m_Value.m_nValue == 0 )
      goto LABEL_17;
LABEL_16:
    V_snprintf(pDest: v27, maxLen: 16, pFormat: "%d", this->m_id);
    NDebugOverlay::Text(origin: &this->m_pos, text: v27, bViewCheck: true, duration: 0.1);
    goto LABEL_17;
  }
  if ( nav_show_node_id.m_pParent != nullptr && nav_show_node_id.m_pParent->m_Value.m_nValue < 0 )
    goto LABEL_16;
LABEL_17:
  if ( nav_test_node.m_pParent != nullptr )
    m_nValue = nav_test_node.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( m_nValue == this->m_id )
  {
    CNavMesh::TestArea(this: TheNavMesh, node: this, width: 1, height: 1);
    CCollisionProperty::TestCollision(this: (ConVar *)&nav_test_node.IConVar, value: 0);
  }
  if ( nav_test_node_crouch.m_pParent != nullptr )
    v7 = nav_test_node_crouch.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  if ( v7 == this->m_id )
  {
    CNavNode::CheckCrouch(this, a2: COERCE_FLOAT((Vector *)&to.z));
    CCollisionProperty::TestCollision(this: (ConVar *)&nav_test_node_crouch.IConVar, value: 0);
  }
  if ( (this->m_attributeFlags & 1) != 0 )
  {
    y = to.y;
    x = to.x;
    for ( i = 0; i < 4; ++i )
    {
      v11 = this->m_isBlocked[i];
      if ( v11 || this->m_crouch[i] )
      {
        switch ( i )
        {
          case 0:
            y = -1.0;
            goto LABEL_36;
          case 1:
            x = 1.0;
            y = -1.0;
            break;
          case 2:
            x = 1.0;
            y = 1.0;
            break;
          case 3:
            y = 1.0;
LABEL_36:
            x = -1.0;
            break;
          default:
            break;
        }
        v12 = 0;
        *(float *)&v12 = fsqrt((float)(x * x) + (float)(y * y));
        *(_OWORD *)v27 = v12;
        if ( *(float *)&v12 == 0.0 )
        {
          v14 = 0.0;
          v13 = 0.0;
        }
        else
        {
          v13 = (float)(1.0 / *(float *)&v12) * x;
          v14 = (float)(1.0 / *(float *)&v12) * y;
        }
        to.x = v13;
        to.y = v14;
        v15 = (float)(v13 * 3.0) + this->m_pos.x;
        v16 = v14 * 3.0;
        if ( v11 )
        {
          *(float *)&v27[16] = v15;
          *(float *)&v27[20] = this->m_pos.y + v16;
          *(float *)&v27[24] = this->m_pos.z;
          NDebugOverlay::HorzArrow(
            startPos: &this->m_pos,
            endPos: (const Vector *)&v27[16],
            width: 0.5,
            r: 255,
            g: 0,
            b: 0,
            a: 255,
            noDepthTest: true,
            flDuration: 0.1);
        }
        else
        {
          from.x = v15;
          from.y = this->m_pos.y + v16;
          from.z = this->m_pos.z;
          NDebugOverlay::HorzArrow(
            startPos: &this->m_pos,
            endPos: &from,
            width: 0.5,
            r: 0,
            g: 0,
            b: 255,
            a: 255,
            noDepthTest: true,
            flDuration: 0.1);
        }
        x = to.x;
        y = to.y;
      }
    }
  }
  if ( nav_show_node_grid.m_pParent != nullptr && nav_show_node_grid.m_pParent->m_Value.m_nValue != 0 )
  {
    for ( j = 0; j < 4; ++j )
    {
      v18 = this->m_to[j];
      if ( v18 != nullptr )
      {
        NDebugOverlay::Line(
          origin: &this->m_pos,
          target: &v18->m_pos,
          r: 255,
          g: 255,
          b: 0,
          noDepthTest: false,
          duration: 0.1);
        v19 = this->m_obstacleHeight[j];
        if ( v19 > 0.0 )
        {
          v20 = this->m_pos.z;
          to.y = v20 + v19;
          *(_QWORD *)&v27[16] = *(_QWORD *)&this->m_pos.x;
          *(_QWORD *)&from.x = *(_QWORD *)&v27[16];
          v21 = this->m_obstacleStartDist[j];
          *(float *)&v27[24] = v20;
          from.z = v20;
          switch ( j )
          {
            case 0:
              from.y = from.y - v21;
              break;
            case 1:
              v22 = from.x + v21;
              goto LABEL_55;
            case 2:
              from.y = from.y + v21;
              break;
            case 3:
              v22 = from.x - v21;
LABEL_55:
              from.x = v22;
              break;
            default:
              break;
          }
          NDebugOverlay::Line(
            origin: (const Vector *)&v27[16],
            target: &from,
            r: 255,
            g: 0,
            b: 255,
            noDepthTest: false,
            duration: 0.1);
          *(Vector *)&v27[16] = from;
          from.z = to.y;
          NDebugOverlay::Line(
            origin: (const Vector *)&v27[16],
            target: &from,
            r: 255,
            g: 0,
            b: 255,
            noDepthTest: false,
            duration: 0.1);
          v23 = this->m_pos.y;
          *(Vector *)&v27[16] = from;
          v24 = this->m_pos.x;
          from.z = to.y;
          v25 = this->m_obstacleEndDist[j];
          from.x = v24;
          from.y = v23;
          switch ( j )
          {
            case 0:
              from.y = v23 - v25;
              break;
            case 1:
              v26 = v24 + v25;
              goto LABEL_61;
            case 2:
              from.y = v23 + v25;
              break;
            case 3:
              v26 = v24 - v25;
LABEL_61:
              from.x = v26;
              break;
            default:
              break;
          }
          NDebugOverlay::Line(
            origin: (const Vector *)&v27[16],
            target: &from,
            r: 255,
            g: 0,
            b: 255,
            noDepthTest: false,
            duration: 0.1);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324360
// Name: public: static class CNavNode __near * CNavNode::GetNode(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CNavNode *__cdecl CNavNode::GetNode(const Vector *pos)
{
  unsigned int v1; // eax
  CNavNode *result; // eax
  unsigned int pBucket; // [esp+4h] [ebp-Ch] BYREF
  CNavNode *src; // [esp+8h] [ebp-8h] BYREF
  int pIndex; // [esp+Ch] [ebp-4h] BYREF

  if ( g_pNavNodeHash == nullptr )
    return nullptr;
  if ( (_S2_311 & 1) == 0 )
  {
    _S2_311 |= 1u;
    atexit(func: CNavNode::GetNode_::_5_::_dynamic_atexit_destructor_for__lookup__);
  }
  lookup.m_pos = *pos;
  src = &lookup;
  pIndex = 0;
  if ( CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs>::DoFind(
         this: g_pNavNodeHash,
         &src,
         (CUtlVector<CNavNode *,CUtlMemory<CNavNode *,int> > *)&pBucket,
         &pIndex) == 0 )
    return nullptr;
  v1 = pIndex | (pBucket << 16);
  if ( v1 == -1 )
    return nullptr;
  for ( result = g_pNavNodeHash->m_Buckets.m_Memory.m_pMemory[HIWORD(v1)].m_Memory.m_pMemory[(unsigned __int16)pIndex];
        result != nullptr;
        result = result->m_nextAtXY )
  {
    if ( fabs(result->m_pos.z - pos->z) < 11.25 )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10324460
// Name: public: CUtlHash<class CNavNode __near *,class CNodeHashFuncs,class CNodeHashFuncs>::CUtlHash<class CNavNode __near *,class CNodeHashFuncs,class CNodeHashFuncs>(int,int,int,class CNodeHashFuncs,class CNodeHashFuncs)
// Source: json
//------------------------------------------------------------------------------
CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs> *__thiscall CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs>::CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs>(
        CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs> *this,
        int bucketCount,
        int growCount,
        int initCount,
        CNodeHashFuncs compareFunc,
        CNodeHashFuncs keyFunc)
{
  int v6; // esi
  int v8; // eax
  CUtlMemory<vgui::TreeNode *,int> *v9; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v12; // eax
  bool v13; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v6 = bucketCount;
  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_Size = 0;
  this->m_Buckets.m_pElements = nullptr;
  if ( bucketCount >= 0x10000 )
  {
    bucketCount = 0x10000;
    v6 = 0x10000;
  }
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll((CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)this);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)this,
    elem: this->m_Buckets.m_Size,
    num: v6);
  if ( v6 > 0 )
  {
    v8 = 0;
    v16 = 0;
    v15 = v6;
    do
    {
      v9 = (CUtlMemory<vgui::TreeNode *,int> *)((char *)this->m_Buckets.m_Memory.m_pMemory + v8);
      v9[1].m_pMemory = nullptr;
      if ( initCount != 0 )
      {
        m_nAllocationCount = v9->m_nAllocationCount;
        if ( initCount > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(this: v9, num: initCount - m_nAllocationCount);
        v9[1].m_pMemory = (vgui::TreeNode **)((char *)v9[1].m_pMemory + initCount);
        m_pMemory = v9->m_pMemory;
        v12 = (int)v9[1].m_pMemory - initCount;
        v9[1].m_nAllocationCount = (int)v9->m_pMemory;
        if ( v12 > 0 && initCount > 0 )
          _V_memmove(dest: &m_pMemory[initCount], src: m_pMemory, count: 4 * v12);
      }
      this->m_Buckets.m_Memory.m_pMemory[v16].m_Memory.m_nGrowSize = growCount;
      v8 = v16 * 20 + 20;
      v13 = v15-- == 1;
      ++v16;
    }
    while ( !v13 );
    v6 = bucketCount;
  }
  this->m_bPowerOfTwo = ((v6 - 1) & v6) == 0;
  this->m_ModMask = ((v6 - 1) & v6) == 0 ? v6 - 1 : 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10324540
// Name: public: CNavNode::CNavNode(class Vector const __near &,class Vector const __near &,class CNavNode __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CNavNode *__thiscall CNavNode::CNavNode(
        CNavNode *this,
        const Vector *pos,
        CNavNode *normal,
        CNavNode *parent,
        unsigned int isOnDisplacement)
{
  const Vector *v5; // eax
  int v7; // ecx
  double z; // st7
  CNavNode *v9; // eax
  bool *m_isBlocked; // eax
  bool v11; // cl
  CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs> *v12; // ecx
  CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs> *v13; // eax
  CNodeHashFuncs v14; // cl
  CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs> *v15; // ebx
  unsigned int v16; // ecx
  int v17; // eax
  CUtlVector<CNavNode *,CUtlMemory<CNavNode *,int> > *m_pMemory; // ecx
  int m_Size; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v21; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v23; // ecx
  int v24; // eax
  CNavNode **v25; // ebx
  int v26; // [esp-14h] [ebp-14h] BYREF

  v5 = pos;
  this->m_pos.x = pos->x;
  this->m_pos.y = v5->y;
  v7 = 4;
  z = v5->z;
  v9 = normal;
  this->m_pos.z = z;
  this->m_normal = v9->m_pos;
  this->m_id = CNavNode::m_nextID++;
  this->m_to[0] = nullptr;
  this->m_obstacleHeight[0] = 0.0;
  this->m_obstacleStartDist[0] = 0.0;
  this->m_obstacleEndDist[0] = 0.0;
  this->m_to[1] = nullptr;
  this->m_obstacleHeight[1] = 0.0;
  this->m_obstacleStartDist[1] = 0.0;
  this->m_obstacleEndDist[1] = 0.0;
  this->m_to[2] = nullptr;
  this->m_obstacleHeight[2] = 0.0;
  this->m_obstacleStartDist[2] = 0.0;
  this->m_obstacleEndDist[2] = 0.0;
  this->m_to[3] = nullptr;
  this->m_obstacleHeight[3] = 0.0;
  this->m_obstacleStartDist[3] = 0.0;
  this->m_obstacleEndDist[3] = 0.0;
  m_isBlocked = this->m_isBlocked;
  do
  {
    m_isBlocked[4] = false;
    *m_isBlocked++ = false;
    --v7;
  }
  while ( v7 != 0 );
  this->m_visited = 0;
  this->m_parent = parent;
  v11 = isOnDisplacement;
  this->m_next = CNavNode::m_list;
  ++CNavNode::m_listLength;
  CNavNode::m_list = this;
  this->m_isCovered = false;
  this->m_area = nullptr;
  this->m_attributeFlags = 0;
  this->m_isOnDisplacement = v11;
  v12 = g_pNavNodeHash;
  if ( g_pNavNodeHash == nullptr )
  {
    v13 = (CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs> *)operator new(nSize: 0x1Cu);
    if ( v13 != nullptr )
    {
      isOnDisplacement = (unsigned int)&v26;
      v12 = CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs>::CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs>(
              this: v13,
              bucketCount: 0x4000,
              growCount: 0,
              initCount: 0,
              compareFunc: v14,
              keyFunc: v14);
    }
    else
    {
      v12 = nullptr;
    }
    g_pNavNodeHash = v12;
  }
  normal = this;
  v15 = v12;
  isOnDisplacement = 0;
  if ( CUtlHash<CNavNode *,CNodeHashFuncs,CNodeHashFuncs>::DoFind(
         this: v12,
         src: &normal,
         pBucket: (CUtlVector<CNavNode *,CUtlMemory<CNavNode *,int> > *)&pos,
         pIndex: (int *)&isOnDisplacement) != 0 )
  {
    v16 = (isOnDisplacement | ((_DWORD)pos << 16)) >> 16;
    v17 = (unsigned __int16)isOnDisplacement;
    this->m_nextAtXY = g_pNavNodeHash->m_Buckets.m_Memory.m_pMemory[v16].m_Memory.m_pMemory[v17];
    g_pNavNodeHash->m_Buckets.m_Memory.m_pMemory[v16].m_Memory.m_pMemory[v17] = this;
    return this;
  }
  else
  {
    m_pMemory = v15->m_Buckets.m_Memory.m_pMemory;
    m_Size = v15->m_Buckets.m_Memory.m_pMemory[(_DWORD)pos].m_Size;
    v21 = (CUtlMemory<vgui::TreeNode *,int> *)&m_pMemory[(_DWORD)pos];
    m_nAllocationCount = v21->m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: v21, num: m_Size - m_nAllocationCount + 1);
    ++v21[1].m_pMemory;
    v23 = v21->m_pMemory;
    v24 = (int)v21[1].m_pMemory - m_Size - 1;
    v21[1].m_nAllocationCount = (int)v21->m_pMemory;
    if ( v24 > 0 )
      _V_memmove(dest: &v23[m_Size + 1], src: &v23[m_Size], count: 4 * v24);
    v25 = (CNavNode **)&v21->m_pMemory[m_Size];
    if ( v25 != nullptr )
      *v25 = this;
    this->m_nextAtXY = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324720
// Name: public: static void CNavNode::CleanupGeneration(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CNavNode::CleanupGeneration()
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *v0; // esi
  CNavNode *v1; // eax
  CNavNode *m_next; // esi

  v0 = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)g_pNavNodeHash;
  if ( g_pNavNodeHash != nullptr )
  {
    CUtlHash<CEntityDataInstantiator<physicspushlist_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &,CEntityDataInstantiator<physicspushlist_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &)>::Purge(this: (CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *)g_pNavNodeHash);
    CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: v0);
    free(pMem: v0);
  }
  v1 = CNavNode::m_list;
  g_pNavNodeHash = nullptr;
  if ( CNavNode::m_list != nullptr )
  {
    do
    {
      m_next = v1->m_next;
      free(pMem: v1);
      v1 = m_next;
    }
    while ( m_next != nullptr );
  }
  CNavNode::m_list = nullptr;
  CNavNode::m_listLength = 0;
  CNavNode::m_nextID = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10339420
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::InsertMultipleBefore(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ikcontextikrule_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 132 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1033A070
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::AddToTail(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  ikcontextikrule_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 132 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10349310
// Name: public: int CUtlVector<struct CExpressionSample,class CUtlMemory<struct CExpressionSample,int>>::InsertBefore(int,struct CExpressionSample const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertBefore(
        CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *this,
        int elem,
        const CExpressionSample *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpressionSample *m_pMemory; // ecx
  int v7; // eax
  CExpressionSample *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpressionSample,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 10 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103495A0
// Name: public: int CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::InsertBefore(int,class CEventRelativeTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::InsertBefore(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this,
        int elem,
        const CEventRelativeTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEventRelativeTag *m_pMemory; // ecx
  int v7; // eax
  CEventRelativeTag *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &v8->m_Name);
    CUtlString::operator=(this: &v8->m_Name, src: &src->m_Name);
    v8->m_flPercentage = src->m_flPercentage;
    v8->m_pOwner = src->m_pOwner;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10349630
// Name: public: int CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::InsertBefore(int,class CFlexTimingTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::InsertBefore(
        CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int> > *this,
        int elem,
        const CFlexTimingTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFlexTimingTag *m_pMemory; // ecx
  int v7; // eax
  CFlexTimingTag *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<constraint_anchor_t,int>::Grow(
      (CUtlMemory<CEventAbsoluteTag,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &v8->m_Name);
    CUtlString::operator=(this: &v8->m_Name, src: &src->m_Name);
    v8->m_flPercentage = src->m_flPercentage;
    v8->m_pOwner = src->m_pOwner;
    v8->m_bLocked = src->m_bLocked;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103496D0
// Name: public: int CUtlVector<class CEventAbsoluteTag,class CUtlMemory<class CEventAbsoluteTag,int>>::InsertBefore(int,class CEventAbsoluteTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int>>::InsertBefore(
        CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *this,
        int elem,
        const CEventAbsoluteTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEventAbsoluteTag *m_pMemory; // ecx
  int v7; // eax
  CEventAbsoluteTag *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<constraint_anchor_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CEventAbsoluteTag::CEventAbsoluteTag(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10349FE0
// Name: public: void CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CEventRelativeTag *v3; // esi
  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034A050
// Name: public: void CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::RemoveAll(
        CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CEventAbsoluteTag *v3; // esi
  CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034ACC0
// Name: public: CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::~CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this)
{
  bool v2; // sf
  CEventRelativeTag *m_pMemory; // eax

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034AD20
// Name: public: CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::~CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::~CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>(
        CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int> > *this)
{
  bool v2; // sf
  CFlexTimingTag *m_pMemory; // eax

  CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::RemoveAll((CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034CAC0
// Name: public: int CUtlVector<struct CExpressionSample,class CUtlMemory<struct CExpressionSample,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertBefore(
        CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpressionSample *m_pMemory; // ecx
  int v6; // eax
  CExpressionSample *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpressionSample,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 10 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->value = 0.0;
    v7->time = 0.0;
    *((_WORD *)v7 + 4) = 0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1035BE90
// Name: public: void CUtlVector<class CSheet __near *,class CUtlMemory<class CSheet __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CSheet *,CUtlMemory<CSheet *,int>>::PurgeAndDeleteElements(
        CUtlVector<CSheet *,CUtlMemory<CSheet *,int> > *this)
{
  int i; // edi
  CSheet *v3; // ebx
  bool v4; // sf
  CSheet **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CSheet::~CSheet(this: this->m_Memory.m_pMemory[i]);
      free(pMem: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035BF00
// Name: public: void CUtlVector<class CParticleOperatorInstance __near *,class CUtlMemory<class CParticleOperatorInstance __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleOperatorInstance *,CUtlMemory<CParticleOperatorInstance *,int>>::PurgeAndDeleteElements(
        CUtlVector<CParticleOperatorInstance *,CUtlMemory<CParticleOperatorInstance *,int> > *this)
{
  int i; // edi
  CParticleOperatorInstance *v3; // ecx
  bool v4; // sf
  CParticleOperatorInstance **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CParticleOperatorInstance *, int))v3->dtr_CParticleOperatorInstance)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035BF70
// Name: public: CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>>::CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int>>::CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int>>(
        CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *this,
        int growSize,
        int initSize)
{
  CDmxElement **m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (CDmxElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035BFC0
// Name: public: int CUtlVector<struct studiohdr_t const __near *,class CUtlMemory<struct studiohdr_t const __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int>>::InsertMultipleBefore(
        CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CParticleSystemDefinition **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1035C740
// Name: public: class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> const __near & CDmxAttribute::GetArray<class CDmxElement __near *>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CDmxAttribute::GetArray<CDmxElement *>(
        CDmxAttribute *this)
{
  if ( this->m_Type == AT_FIRST_ARRAY_TYPE )
    return (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x1035C790
// Name: public: class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> const __near & CDmxElement::GetArray<class CDmxElement __near *>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CDmxElement::GetArray<CDmxElement *>(
        CDmxElement *this,
        const char *pAttributeName)
{
  CDmxAttribute *Attribute; // eax

  Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
  if ( (`CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Size = 0;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_pElements = nullptr;
    atexit(func: `CDmxElement::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultValue'');
  }
  return &`CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x1035CF50
// Name: public: void CUtlVector<struct CParticleSystemMgr::RenderCache_t,class CUtlMemory<struct CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(
        CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035E370
// Name: public: CUtlVector<struct CParticleSystemMgr::RenderCache_t,class CUtlMemory<struct CParticleSystemMgr::RenderCache_t,int>>::~CUtlVector<struct CParticleSystemMgr::RenderCache_t,class CUtlMemory<struct CParticleSystemMgr::RenderCache_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::~CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>(
        CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *this)
{
  bool v2; // sf
  CParticleSystemMgr::RenderCache_t *m_pMemory; // eax

  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10366E60
// Name: public: int CUtlVector<struct ResponseRules::ParserResponse,class CUtlMemory<struct ResponseRules::ParserResponse,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ResponseRules::ParserResponse,CUtlMemory<ResponseRules::ParserResponse,int>>::InsertBefore(
        CUtlVector<ResponseRules::ParserResponse,CUtlMemory<ResponseRules::ParserResponse,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResponseRules::ParserResponse *m_pMemory; // ecx
  int v6; // eax
  ResponseRules::ParserResponse *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ResponseRules::ParserResponse,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 96 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    ResponseRules::ParserResponse::ParserResponse(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10367C70
// Name: protected: void CUtlVector<unsigned short,class CUtlMemoryConservative<unsigned short>>::GrowVector(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned short,CUtlMemoryConservative<unsigned short>>::GrowVector(
        CUtlVector<unsigned short,CUtlMemoryConservative<unsigned short> > *this,
        int num)
{
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // edi
  unsigned int v6; // eax
  unsigned __int16 *m_pMemory; // eax

  if ( this->m_Memory.m_pMemory != nullptr )
    v3 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
  else
    v3 = 0;
  if ( num + this->m_Size > (int)(v3 >> 1) )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
      v4 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
    else
      v4 = 0;
    v5 = num + this->m_Size - (v4 >> 1);
    if ( this->m_Memory.m_pMemory != nullptr )
      v6 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
    else
      v6 = 0;
    this->m_Memory.m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(
                                                     this: _g_pMemAlloc,
                                                     a2: this->m_Memory.m_pMemory,
                                                     a3: 2 * (v5 + (v6 >> 1)));
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size += num;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10380BA0
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10380C10
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  vgui::OverridableColorEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1038F070
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  vgui::BoundKey_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103A0410
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103AE410
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x103AEEA0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AF180
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  vgui::RichText::TFormatStream *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<masscenteroverride_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103B7590
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103BD080
// Name: public: int CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::AddToHead(class vgui::TreeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // eax
  int v6; // ecx
  vgui::TreeNode **v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = *src;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103BF650
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103C0DA0
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::ActiveAnimation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<template_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103C2030
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C2330
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C2A00
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x103C3FD0
// Name: public: int CUtlVector<class CHandle<class CFish>,class CUtlMemory<class CHandle<class CFish>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103C45B0
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103C7320
// Name: public: bool CUtlVector<class CHostage __near *,class CUtlMemory<class CHostage __near *,int>>::FindAndRemove(class CHostage __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F53B0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmxAttribute::GetArray<float>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmxAttribute::GetArray<float>(CDmxAttribute *this)
{
  if ( this->m_Type == AT_FLOAT_ARRAY )
    return (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<float>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<float>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<float>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<float>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x103F59D0
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  bool *m_pMemory; // eax
  bool *v4; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      v4 = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5A30
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int num)
{
  DmeTime_t *m_pMemory; // edx
  unsigned int v4; // eax
  DmeTime_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 4 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (DmeTime_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (DmeTime_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5A90
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int num)
{
  Vector2D *m_pMemory; // edx
  unsigned int v4; // eax
  Vector2D *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 8 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (Vector2D *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5AF0
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int num)
{
  QAngle *m_pMemory; // edx
  unsigned int v4; // eax
  QAngle *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (QAngle *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (QAngle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5B60
// Name: public: void CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::EnsureCapacity(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int num)
{
  VMatrix *m_pMemory; // edx
  unsigned int v4; // eax
  VMatrix *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = num << 6;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5BC0
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int num)
{
  CUtlString *m_pMemory; // edx
  unsigned int v4; // eax
  CUtlString *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5C20
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertBefore(int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        const Vector2D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  Vector2D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103F5C90
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertBefore(int,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        const Vector4D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v7; // eax
  Vector4D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103F5D10
// Name: public: int CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertBefore(int,struct CStudioHdr::CActivityToSequenceMapping::HashValueType const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertBefore(
        CUtlVector<ResponseRules::CResponseSystem::ScriptEntry,CUtlMemory<ResponseRules::CResponseSystem::ScriptEntry,int> > *this,
        int elem,
        const ResponseRules::CResponseSystem::ScriptEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResponseRules::CResponseSystem::ScriptEntry *m_pMemory; // ecx
  int v7; // eax
  ResponseRules::CResponseSystem::ScriptEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103F5D90
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        const CUtlBinaryBlock *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  CUtlBinaryBlock *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103F5E00
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v6; // eax
  CUtlBinaryBlock *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v7, growSize: 0, initSize: 0);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103F5E90
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlBinaryBlock *v3; // esi
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_nActualLength = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10421A00
// Name: _CNavNode::GetNode_::_5_::_dynamic_atexit_destructor_for__lookup__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CNavNode::GetNode_::_5_::_dynamic_atexit_destructor_for__lookup__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100425B0
// Name: class CAssaultPoint __near * _CreateEntityTemplate<class CAssaultPoint>(class CAssaultPoint __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAssaultPoint *__cdecl _CreateEntityTemplate<CAssaultPoint>(CAssaultPoint *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3ACu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CAssaultPoint::`vftable';
    v3[215] = 0;
    v3[218] = -1;
    v3[219] = 0;
    v3[229] = 0;
    v3[232] = -1;
    v3[233] = 0;
    v3[227] = 1108344832;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CAssaultPoint *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101126D0
// Name: class CEnvEffectsScript __near * _CreateEntityTemplate<class CEnvEffectsScript>(class CEnvEffectsScript __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvEffectsScript *__cdecl _CreateEntityTemplate<CEnvEffectsScript>(CEnvEffectsScript *newEnt, const char *className)
{
  CBaseAnimating *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x4A4u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    *v3 = &CEnvEffectsScript::`vftable';
    v3[292] = 0;
    v3[293] = 0;
    v3[294] = 0;
    v3[295] = 0;
    v3[296] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CEnvEffectsScript *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112770
// Name: struct datamap_t __near * DataMapInit<class CEnvEffectsScript>(class CEnvEffectsScript __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvEffectsScript>()
{
  if ( (_S2_83 & 1) == 0 )
  {
    _S2_83 |= 1u;
    nameHolder_160.m_pszBase = "CEnvEffectsScript";
    nameHolder_160.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_160.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_160.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_160.m_Names.m_Size = 0;
    nameHolder_160.m_Names.m_pElements = nullptr;
    nameHolder_160.m_nLenBase = 17;
    atexit(func: DataMapInit_CEnvEffectsScript__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvEffectsScript::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S2_83 & 2) == 0 )
  {
    _S2_83 |= 2u;
    dataDesc_151[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_160,
                                  pszIdentifier: "Think");
    dataDesc_151[3].fieldOffset = 0;
    *(_DWORD *)&dataDesc_151[3].fieldSize = 2097153;
    dataDesc_151[3].externalName = nullptr;
    dataDesc_151[3].pSaveRestoreOps = nullptr;
    dataDesc_151[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBaseEntity::`vcall'{200,{flat}};
    *(_QWORD *)&dataDesc_151[3].td = 0;
    *(_QWORD *)&dataDesc_151[3].override_field = 0;
    *(_QWORD *)&dataDesc_151[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_151[3].flatOffset[1] = 0;
  }
  CEnvEffectsScript::m_DataMap.dataNumFields = 3;
  CEnvEffectsScript::m_DataMap.dataDesc = &dataDesc_151[1];
  return &CEnvEffectsScript::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1018AEA0
// Name: struct vehiclescript_t __near * Construct<struct vehiclescript_t>(struct vehiclescript_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vehiclescript_t *__cdecl Construct<vehiclescript_t>(vehiclescript_t *pMemory)
{
  vehiclescript_t *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->sounds.__vftable = (vehiclesounds_t_vtbl *)&vehiclesounds_t::`vftable';
  pMemory->sounds.pGears.m_Memory.m_pMemory = nullptr;
  pMemory->sounds.pGears.m_Memory.m_nAllocationCount = 0;
  pMemory->sounds.pGears.m_Memory.m_nGrowSize = 0;
  pMemory->sounds.pGears.m_Size = 0;
  pMemory->sounds.pGears.m_pElements = nullptr;
  pMemory->sounds.crashSounds.m_Memory.m_pMemory = nullptr;
  pMemory->sounds.crashSounds.m_Memory.m_nAllocationCount = 0;
  pMemory->sounds.crashSounds.m_Memory.m_nGrowSize = 0;
  pMemory->sounds.crashSounds.m_Size = 0;
  pMemory->sounds.crashSounds.m_pElements = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421A10
// Name: _dynamic_atexit_destructor_for__nav_chop_selected_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_chop_selected_command__()
{
  ConCommand::~ConCommand(this: &nav_chop_selected_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421A20
// Name: _dynamic_atexit_destructor_for__nav_simplify_selected_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_simplify_selected_command__()
{
  ConCommand::~ConCommand(this: &nav_simplify_selected_command);
}
