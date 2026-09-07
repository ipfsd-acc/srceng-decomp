// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/subdbaker/scheduler/scheduleobject.cpp
// Functions: 47
// ============================================================

#include "utils\subdbaker\scheduler\scheduleobject.h"

//------------------------------------------------------------------------------
// Address: 0x00408030
// Name: public: virtual int CScheduleObject::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScheduleObject::AddRef(CScheduleObject *this)
{
  return ++this->m_iRef;
}

//------------------------------------------------------------------------------
// Address: 0x00408040
// Name: public: virtual int CScheduleObject::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScheduleObject::Release(CScheduleObject *this)
{
  bool v1; // zf
  int m_iRef; // esi

  v1 = this->m_iRef-- == 1;
  m_iRef = this->m_iRef;
  if ( v1 )
    ((void (__thiscall *)(CScheduleObject *, int))this->dtr_CScheduleObject)(a1: this, a2: 1);
  return m_iRef;
}

//------------------------------------------------------------------------------
// Address: 0x00408060
// Name: public: virtual void CScheduleObject::SetGlobalScheduleQueue(class IScheduleQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::SetGlobalScheduleQueue(CScheduleObject *this, IScheduleQueue *pScheduleQueue)
{
  this->m_pGlobalScheduleQueue = pScheduleQueue;
}

//------------------------------------------------------------------------------
// Address: 0x00408070
// Name: public: virtual class IScheduleQueue __near * CScheduleObject::GetGlobalScheduleQueue(void)
// Source: json
//------------------------------------------------------------------------------
IScheduleQueue *__thiscall CScheduleObject::GetGlobalScheduleQueue(CScheduleObject *this)
{
  return this->m_pGlobalScheduleQueue;
}

//------------------------------------------------------------------------------
// Address: 0x00408080
// Name: public: virtual void CScheduleObject::SetObjectType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::SetObjectType(CScheduleObject *this, int iObjectType)
{
  this->m_iObjectType = iObjectType;
}

//------------------------------------------------------------------------------
// Address: 0x00408090
// Name: public: virtual void CScheduleObject::SetAffinityQueue(class IScheduleQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::SetAffinityQueue(CScheduleObject *this, IScheduleQueue *pOptionalAffinityQueue)
{
  this->m_pAffinityScheduleQueue = pOptionalAffinityQueue;
}

//------------------------------------------------------------------------------
// Address: 0x004080A0
// Name: public: virtual void CScheduleObject::OverrideDependencyPullArray(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::OverrideDependencyPullArray(
        CScheduleObject *this,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyPullArray)
{
  this->m_pDependencyPullArray = pDependencyPullArray;
}

//------------------------------------------------------------------------------
// Address: 0x004080B0
// Name: public: virtual void CScheduleObject::SatisfyDependency(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::SatisfyDependency(CScheduleObject *this)
{
  volatile int *p_m_iOustandingDependencies; // edi
  volatile LONG v2; // ebx
  LONG v3; // esi

  p_m_iOustandingDependencies = &this->m_iOustandingDependencies;
  do
  {
    v2 = *p_m_iOustandingDependencies;
    v3 = *p_m_iOustandingDependencies - 1;
  }
  while ( v2 != InterlockedCompareExchange(
                  Destination: p_m_iOustandingDependencies,
                  Exchange: v3,
                  Comperand: *p_m_iOustandingDependencies) );
  if ( v3 == 0 )
  {
    if ( this->m_pAffinityScheduleQueue != nullptr )
      this->m_pAffinityScheduleQueue->AddAffinityJob(this: this->m_pAffinityScheduleQueue, a2: this);
    else
      this->m_pGlobalScheduleQueue->AddJobA(this: this->m_pGlobalScheduleQueue, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408100
// Name: public: virtual void CScheduleObject::SetFriendlyName(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::SetFriendlyName(CScheduleObject *this, char *pszName)
{
  strcpy_s(_Dst: this->m_szFriendlyName, _SizeInBytes: 0x100u, _Src: pszName);
}

//------------------------------------------------------------------------------
// Address: 0x00408120
// Name: public: virtual char __near * CScheduleObject::GetFriendlyName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScheduleObject::GetFriendlyName(CScheduleObject *this)
{
  return this->m_szFriendlyName;
}

//------------------------------------------------------------------------------
// Address: 0x00408130
// Name: public: virtual void CScheduleObject::Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::Execute(CScheduleObject *this)
{
  if ( this->m_pJob != nullptr )
    this->m_pJob->Execute(this: this->m_pJob, a2: this->m_pDependencyPullArray);
}

//------------------------------------------------------------------------------
// Address: 0x00408150
// Name: public: virtual class CJobResult __near * CScheduleObject::GetJobResult(void)
// Source: json
//------------------------------------------------------------------------------
CJobResult *__thiscall CScheduleObject::GetJobResult(CScheduleObject *this)
{
  if ( this->m_pJob != nullptr )
    return this->m_pJob->GetJobResult(this: this->m_pJob);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00408170
// Name: public: virtual void CScheduleObject::Schedule(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::Schedule(CScheduleBatch *this)
{
  this->m_pThreadPool->LockThreadPool(this: this->m_pThreadPool);
  this->InternalSchedule(this);
  this->m_pThreadPool->UnlockThreadPool(this: this->m_pThreadPool);
}

//------------------------------------------------------------------------------
// Address: 0x004081A0
// Name: public: virtual void CScheduleBatch::Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleBatch::Execute(CScheduleBatch *this)
{
  if ( this->m_pJob != nullptr )
    this->m_pJob->Execute(this: this->m_pJob, a2: &this->m_JobBatchArray);
}

//------------------------------------------------------------------------------
// Address: 0x004081C0
// Name: public: virtual void CScheduleObject::SetJobA(class CJob __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::SetJobA(CScheduleQueue *this, CScheduleQueue *pParent)
{
  this->m_pParentQueue = pParent;
}

//------------------------------------------------------------------------------
// Address: 0x004081D0
// Name: public: virtual void CScheduleQueue::SetPullGranularities(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleQueue::SetPullGranularities(
        CScheduleQueue *this,
        int iParentPullGranularity,
        int iSiblingPullGranularity)
{
  this->m_iParentPullGranularity = iParentPullGranularity;
  this->m_iSiblingPullGranularity = iSiblingPullGranularity;
}

//------------------------------------------------------------------------------
// Address: 0x004081F0
// Name: public: virtual int CScheduleQueue::GetExecutedJobs(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScheduleQueue::GetExecutedJobs(CScheduleQueue *this)
{
  return this->m_iCurrentScheduleObject;
}

//------------------------------------------------------------------------------
// Address: 0x00408200
// Name: public: virtual int CScheduleQueue::GetTotalJobs(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScheduleQueue::GetTotalJobs(CScheduleQueue *this)
{
  return this->m_ScheduleObjectArray.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00408210
// Name: public: virtual int CScheduleQueue::GetRemainingJobs(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScheduleQueue::GetRemainingJobs(CScheduleQueue *this)
{
  return this->m_ScheduleObjectArray.m_Size - this->m_iCurrentScheduleObject;
}

//------------------------------------------------------------------------------
// Address: 0x004082B0
// Name: private: virtual void CScheduleObject::InternalSchedule(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::InternalSchedule(CScheduleObject *this)
{
  IScheduleQueue *m_pAffinityScheduleQueue; // ecx
  int m_Size; // ebx
  int i; // edi
  IScheduleObject *v5; // ecx

  if ( !this->m_bScheduled )
  {
    this->m_iOustandingDependencies = this->m_DependencyArray.m_Size;
    if ( this->m_iOustandingDependencies != 0 )
    {
      m_Size = this->m_DependencyArray.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v5 = this->m_DependencyArray.m_Memory.m_pMemory[i];
        v5->InternalSchedule(this: v5);
      }
      this->m_bScheduled = true;
    }
    else
    {
      m_pAffinityScheduleQueue = this->m_pAffinityScheduleQueue;
      if ( m_pAffinityScheduleQueue != nullptr )
        m_pAffinityScheduleQueue->AddAffinityJob(this: m_pAffinityScheduleQueue, a2: this);
      else
        this->m_pGlobalScheduleQueue->AddJobA(this: this->m_pGlobalScheduleQueue, a2: this);
      this->m_bScheduled = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408320
// Name: public: virtual void CScheduleObject::CompleteJob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::CompleteJob(CScheduleObject *this)
{
  int m_Size; // ebx
  int i; // esi
  IScheduleObject *v4; // ecx

  m_Size = this->m_DependantArray.m_Size;
  ++this->m_iExecuteCounter;
  this->m_bScheduled = false;
  if ( m_Size > 0 )
  {
    for ( i = 0; i < m_Size; ++i )
    {
      v4 = this->m_DependantArray.m_Memory.m_pMemory[i];
      v4->SatisfyDependency(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408360
// Name: private: void CScheduleBatch::InternalAddBatchJobsToQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleBatch::InternalAddBatchJobsToQueue(CScheduleBatch *this)
{
  int m_Size; // edx
  IScheduleQueue *m_pAffinityScheduleQueue; // ecx
  IScheduleObject **m_pMemory; // esi

  m_Size = this->m_JobBatchArray.m_Size;
  if ( m_Size > 0 )
  {
    m_pAffinityScheduleQueue = this->m_pAffinityScheduleQueue;
    m_pMemory = this->m_JobBatchArray.m_Memory.m_pMemory;
    this->m_iOustandingDependencies = m_Size;
    this->m_bAddedBatchJobsToQueue = true;
    if ( m_pAffinityScheduleQueue != nullptr )
      m_pAffinityScheduleQueue->AddJobs(this: m_pAffinityScheduleQueue, a2: m_pMemory, a3: m_Size);
    else
      this->m_pGlobalScheduleQueue->AddJobs(this: this->m_pGlobalScheduleQueue, a2: m_pMemory, a3: m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004083B0
// Name: public: virtual void CScheduleBatch::SatisfyDependency(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleBatch::SatisfyDependency(CScheduleBatch *this)
{
  volatile int *p_m_iOustandingDependencies; // edi
  volatile LONG v2; // ebx
  LONG v3; // esi
  IScheduleQueue *m_pAffinityScheduleQueue; // ecx

  p_m_iOustandingDependencies = &this->m_iOustandingDependencies;
  do
  {
    v2 = *p_m_iOustandingDependencies;
    v3 = *p_m_iOustandingDependencies - 1;
  }
  while ( v2 == InterlockedCompareExchange(
                  Destination: p_m_iOustandingDependencies,
                  Exchange: v3,
                  Comperand: *p_m_iOustandingDependencies) );
  if ( v3 == 0 )
  {
    if ( this->m_bAddedBatchJobsToQueue )
    {
      m_pAffinityScheduleQueue = this->m_pAffinityScheduleQueue;
      if ( m_pAffinityScheduleQueue != nullptr )
        m_pAffinityScheduleQueue->AddAffinityJob(this: m_pAffinityScheduleQueue, a2: this);
      else
        this->m_pGlobalScheduleQueue->AddJobA(this: this->m_pGlobalScheduleQueue, a2: this);
      this->m_bAddedBatchJobsToQueue = false;
    }
    else
    {
      CScheduleBatch::InternalAddBatchJobsToQueue(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408430
// Name: private: bool CScheduleQueue::StealJobs(class IScheduleQueue __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScheduleQueue::StealJobs(CScheduleQueue *this, IScheduleQueue *pStealingQueue, int *pInOutNumToSteal)
{
  int v4; // edi
  _RTL_CRITICAL_SECTION *p_m_csSchedulObjectArray; // ebx
  int v6; // eax
  int v8; // eax
  int v9; // ecx
  _RTL_CRITICAL_SECTION *v10; // [esp+Ch] [ebp-4h]

  v4 = *pInOutNumToSteal;
  p_m_csSchedulObjectArray = &this->m_csSchedulObjectArray;
  v10 = &this->m_csSchedulObjectArray;
  EnterCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
  v6 = this->m_ScheduleObjectArray.m_Size - this->m_iCurrentScheduleObject;
  if ( v6 < 1 )
  {
    LeaveCriticalSection(lpCriticalSection: p_m_csSchedulObjectArray);
    return false;
  }
  v8 = v6 / 2;
  v9 = 1;
  if ( v8 >= 1 )
    v9 = v8;
  if ( v9 < v4 )
  {
    if ( v8 < 1 )
    {
      v4 = 1;
LABEL_10:
      pStealingQueue->AddJobs(
        this: pStealingQueue,
        a2: &this->m_ScheduleObjectArray.m_Memory.m_pMemory[this->m_iCurrentScheduleObject],
        a3: v4);
      this->m_iCurrentScheduleObject += v4;
      p_m_csSchedulObjectArray = v10;
      goto LABEL_11;
    }
    v4 = v8;
  }
  if ( v4 > 0 )
    goto LABEL_10;
LABEL_11:
  LeaveCriticalSection(lpCriticalSection: p_m_csSchedulObjectArray);
  *pInOutNumToSteal = v4;
  return v4 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004084D0
// Name: public: virtual void CScheduleQueue::RemoveFromSiblingQueues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleQueue::RemoveFromSiblingQueues(CScheduleQueue *this)
{
  int m_Size; // ebx
  int i; // esi
  CScheduleQueue *v4; // ecx
  LPCRITICAL_SECTION lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = &this->m_csSiblingQueueArray;
  EnterCriticalSection(lpCriticalSection: &this->m_csSiblingQueueArray);
  m_Size = this->m_SiblingQueues.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_SiblingQueues.m_Memory.m_pMemory[i];
    v4->RemoveSiblingQueue(this: v4, a2: this);
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x00408520
// Name: public: virtual void CScheduleQueue::ResetScheduleArrays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleQueue::ResetScheduleArrays(CScheduleQueue *this)
{
  _RTL_CRITICAL_SECTION *p_m_csAffinityScheduleObjectArray; // edi

  p_m_csAffinityScheduleObjectArray = &this->m_csAffinityScheduleObjectArray;
  EnterCriticalSection(lpCriticalSection: &this->m_csAffinityScheduleObjectArray);
  this->m_AffinityScheduleObjectArray.m_Size = 0;
  this->m_iCurrentAffinityScheduleObject = 0;
  LeaveCriticalSection(lpCriticalSection: p_m_csAffinityScheduleObjectArray);
  EnterCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
  this->m_ScheduleObjectArray.m_Size = 0;
  this->m_iCurrentScheduleObject = 0;
  LeaveCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
}

//------------------------------------------------------------------------------
// Address: 0x00408560
// Name: private: virtual void CScheduleBatch::InternalSchedule(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleBatch::InternalSchedule(CScheduleBatch *this)
{
  int m_Size; // ebx
  int i; // esi
  IScheduleObject *v4; // ecx

  if ( !this->m_bScheduled )
  {
    this->m_iOustandingDependencies = this->m_DependencyArray.m_Size;
    if ( this->m_iOustandingDependencies != 0 )
    {
      m_Size = this->m_DependencyArray.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v4 = this->m_DependencyArray.m_Memory.m_pMemory[i];
        v4->InternalSchedule(this: v4);
      }
      this->m_bScheduled = true;
    }
    else
    {
      CScheduleBatch::InternalAddBatchJobsToQueue(this);
      this->m_bScheduled = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004085C0
// Name: private: bool CScheduleQueue::EnsureJobsToSchedule(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScheduleQueue::EnsureJobsToSchedule(CScheduleQueue *this)
{
  _RTL_CRITICAL_SECTION *p_m_csAffinityScheduleObjectArray; // edi
  CScheduleQueue *m_pParentQueue; // ecx
  bool v5; // bl
  int v6; // edi
  CScheduleQueue *v7; // ecx
  _RTL_CRITICAL_SECTION *p_m_csSchedulObjectArray; // [esp-8h] [ebp-1Ch]
  int NumSiblings; // [esp+Ch] [ebp-8h]
  int InOutNumToSteal; // [esp+10h] [ebp-4h] BYREF

  p_m_csAffinityScheduleObjectArray = &this->m_csAffinityScheduleObjectArray;
  EnterCriticalSection(lpCriticalSection: &this->m_csAffinityScheduleObjectArray);
  if ( this->m_iCurrentAffinityScheduleObject >= this->m_AffinityScheduleObjectArray.m_Size )
  {
    LeaveCriticalSection(lpCriticalSection: p_m_csAffinityScheduleObjectArray);
    EnterCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
    p_m_csSchedulObjectArray = &this->m_csSchedulObjectArray;
    if ( this->m_iCurrentScheduleObject >= this->m_ScheduleObjectArray.m_Size )
    {
      LeaveCriticalSection(lpCriticalSection: p_m_csSchedulObjectArray);
      m_pParentQueue = this->m_pParentQueue;
      v5 = false;
      if ( m_pParentQueue == nullptr
        || (InOutNumToSteal = this->m_iParentPullGranularity,
            !(v5 = CScheduleQueue::StealJobs(
                     this: m_pParentQueue,
                     pStealingQueue: this,
                     pInOutNumToSteal: &InOutNumToSteal))) )
      {
        if ( this->m_iSiblingPullGranularity > 0 )
        {
          EnterCriticalSection(lpCriticalSection: &this->m_csSiblingQueueArray);
          v6 = 0;
          NumSiblings = this->m_SiblingQueues.m_Size;
          if ( NumSiblings > 0 )
          {
            do
            {
              if ( v5 )
                break;
              v7 = this->m_SiblingQueues.m_Memory.m_pMemory[v6];
              InOutNumToSteal = this->m_iSiblingPullGranularity;
              ++v6;
              v5 = CScheduleQueue::StealJobs(this: v7, pStealingQueue: this, pInOutNumToSteal: &InOutNumToSteal);
            }
            while ( v6 < NumSiblings );
          }
          LeaveCriticalSection(lpCriticalSection: &this->m_csSiblingQueueArray);
        }
      }
      return v5;
    }
    else
    {
      LeaveCriticalSection(lpCriticalSection: p_m_csSchedulObjectArray);
      return 1;
    }
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: p_m_csAffinityScheduleObjectArray);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408690
// Name: public: virtual class IScheduleObject __near * CScheduleQueue::GetNextJob(void)
// Source: json
//------------------------------------------------------------------------------
IScheduleObject *__thiscall CScheduleQueue::GetNextJob(CScheduleQueue *this)
{
  IScheduleObject *v2; // edi
  int m_iCurrentAffinityScheduleObject; // eax
  int m_iCurrentScheduleObject; // eax

  v2 = nullptr;
  if ( CScheduleQueue::EnsureJobsToSchedule(this) == 0 )
    return nullptr;
  EnterCriticalSection(lpCriticalSection: &this->m_csAffinityScheduleObjectArray);
  m_iCurrentAffinityScheduleObject = this->m_iCurrentAffinityScheduleObject;
  if ( m_iCurrentAffinityScheduleObject < this->m_AffinityScheduleObjectArray.m_Size )
  {
    v2 = this->m_AffinityScheduleObjectArray.m_Memory.m_pMemory[m_iCurrentAffinityScheduleObject];
    this->m_iCurrentAffinityScheduleObject = m_iCurrentAffinityScheduleObject + 1;
  }
  LeaveCriticalSection(lpCriticalSection: &this->m_csAffinityScheduleObjectArray);
  if ( v2 == nullptr )
  {
    EnterCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
    m_iCurrentScheduleObject = this->m_iCurrentScheduleObject;
    if ( m_iCurrentScheduleObject < this->m_ScheduleObjectArray.m_Size )
    {
      v2 = this->m_ScheduleObjectArray.m_Memory.m_pMemory[m_iCurrentScheduleObject];
      this->m_iCurrentScheduleObject = m_iCurrentScheduleObject + 1;
    }
    LeaveCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00408770
// Name: public: CScheduleObject::CScheduleObject(class ISchedulerThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
CScheduleObject *__thiscall CScheduleObject::CScheduleObject(CScheduleObject *this, ISchedulerThreadPool *pThreadPool)
{
  CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *p_m_DependencyArray; // edi

  this->m_pThreadPool = pThreadPool;
  this->__vftable = (CScheduleObject_vtbl *)&CScheduleObject::`vftable';
  this->m_iExecuteCounter = 0;
  this->m_iObjectType = 0;
  this->m_iOustandingDependencies = 0;
  p_m_DependencyArray = &this->m_DependencyArray;
  this->m_DependencyArray.m_Memory.m_pMemory = nullptr;
  this->m_DependencyArray.m_Memory.m_nAllocationCount = 0;
  this->m_DependencyArray.m_Memory.m_nGrowSize = 0;
  this->m_DependencyArray.m_Size = 0;
  this->m_DependencyArray.m_pElements = nullptr;
  this->m_DependantArray.m_Memory.m_pMemory = nullptr;
  this->m_DependantArray.m_Memory.m_nAllocationCount = 0;
  this->m_DependantArray.m_Memory.m_nGrowSize = 0;
  this->m_DependantArray.m_Size = 0;
  this->m_DependantArray.m_pElements = nullptr;
  this->m_pGlobalScheduleQueue = nullptr;
  this->m_pAffinityScheduleQueue = nullptr;
  this->m_bScheduled = false;
  this->m_iRef = 0;
  memset(dst: (unsigned __int8 *)this->m_szFriendlyName, value: 0, count: sizeof(this->m_szFriendlyName));
  this->m_pDependencyPullArray = p_m_DependencyArray;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408800
// Name: public: virtual void CScheduleObject::RemoveDependency(class IScheduleObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::RemoveDependency(CScheduleObject *this, CScheduleObject *pDependency)
{
  IScheduleObject *v2; // edi

  v2 = pDependency;
  CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int>>::FindAndRemove(
    this: (CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int> > *)&this->m_DependencyArray,
    src: (CScheduleQueue **)&pDependency);
  pDependency = this;
  CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int>>::FindAndRemove(
    this: (CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int> > *)&v2[12],
    src: (CScheduleQueue **)&pDependency);
}

//------------------------------------------------------------------------------
// Address: 0x00408830
// Name: public: virtual void CScheduleObject::RemoveDependant(class IScheduleObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::RemoveDependant(CScheduleObject *this, CScheduleObject *pDependant)
{
  IScheduleObject *v2; // edi

  v2 = pDependant;
  CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int>>::FindAndRemove(
    this: (CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int> > *)&this->m_DependantArray,
    src: (CScheduleQueue **)&pDependant);
  pDependant = this;
  CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int>>::FindAndRemove(
    this: (CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int> > *)&v2[6],
    src: (CScheduleQueue **)&pDependant);
}

//------------------------------------------------------------------------------
// Address: 0x00408860
// Name: public: virtual void CScheduleBatch::RemoveScheduleJobFromBatch(class IScheduleObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleBatch::RemoveScheduleJobFromBatch(CScheduleBatch *this, IScheduleObject *pScheduleObject)
{
  CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int>>::FindAndRemove(
    this: (CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int> > *)&this->m_JobBatchArray,
    src: (CScheduleQueue **)&pScheduleObject);
}

//------------------------------------------------------------------------------
// Address: 0x00408880
// Name: public: CScheduleQueue::CScheduleQueue(void)
// Source: json
//------------------------------------------------------------------------------
CScheduleQueue *__thiscall CScheduleQueue::CScheduleQueue(CScheduleQueue *this)
{
  this->__vftable = (CScheduleQueue_vtbl *)&CScheduleQueue::`vftable';
  this->m_pParentQueue = nullptr;
  this->m_SiblingQueues.m_Memory.m_pMemory = nullptr;
  this->m_SiblingQueues.m_Memory.m_nAllocationCount = 0;
  this->m_SiblingQueues.m_Memory.m_nGrowSize = 0;
  this->m_SiblingQueues.m_Size = 0;
  this->m_SiblingQueues.m_pElements = nullptr;
  this->m_ScheduleObjectArray.m_Memory.m_pMemory = nullptr;
  this->m_ScheduleObjectArray.m_Memory.m_nAllocationCount = 0;
  this->m_ScheduleObjectArray.m_Memory.m_nGrowSize = 0;
  this->m_ScheduleObjectArray.m_Size = 0;
  this->m_ScheduleObjectArray.m_pElements = nullptr;
  this->m_iCurrentScheduleObject = 0;
  this->m_AffinityScheduleObjectArray.m_Memory.m_pMemory = nullptr;
  this->m_AffinityScheduleObjectArray.m_Memory.m_nAllocationCount = 0;
  this->m_AffinityScheduleObjectArray.m_Memory.m_nGrowSize = 0;
  this->m_AffinityScheduleObjectArray.m_Size = 0;
  this->m_AffinityScheduleObjectArray.m_pElements = nullptr;
  this->m_iCurrentAffinityScheduleObject = 0;
  this->m_iParentPullGranularity = 10;
  this->m_iSiblingPullGranularity = 5;
  InitializeCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
  InitializeCriticalSection(lpCriticalSection: &this->m_csAffinityScheduleObjectArray);
  InitializeCriticalSection(lpCriticalSection: &this->m_csSiblingQueueArray);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408920
// Name: public: virtual CScheduleQueue::~CScheduleQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleQueue::~CScheduleQueue(CScheduleQueue *this)
{
  CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *p_m_AffinityScheduleObjectArray; // esi
  IScheduleObject **m_pMemory; // eax
  CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *p_m_ScheduleObjectArray; // esi
  IScheduleObject **v5; // eax
  CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int> > *p_m_SiblingQueues; // esi
  CScheduleQueue **v7; // eax

  this->__vftable = (CScheduleQueue_vtbl *)&CScheduleQueue::`vftable';
  CScheduleQueue::RemoveFromSiblingQueues(this);
  DeleteCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
  DeleteCriticalSection(lpCriticalSection: &this->m_csAffinityScheduleObjectArray);
  DeleteCriticalSection(lpCriticalSection: &this->m_csSiblingQueueArray);
  p_m_AffinityScheduleObjectArray = &this->m_AffinityScheduleObjectArray;
  this->m_AffinityScheduleObjectArray.m_Size = 0;
  if ( this->m_AffinityScheduleObjectArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_AffinityScheduleObjectArray->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_AffinityScheduleObjectArray->m_Memory.m_pMemory);
      p_m_AffinityScheduleObjectArray->m_Memory.m_pMemory = nullptr;
    }
    this->m_AffinityScheduleObjectArray.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_AffinityScheduleObjectArray->m_Memory.m_pMemory;
  this->m_AffinityScheduleObjectArray.m_pElements = this->m_AffinityScheduleObjectArray.m_Memory.m_pMemory;
  if ( this->m_AffinityScheduleObjectArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_AffinityScheduleObjectArray->m_Memory.m_pMemory = nullptr;
    }
    this->m_AffinityScheduleObjectArray.m_Memory.m_nAllocationCount = 0;
  }
  p_m_ScheduleObjectArray = &this->m_ScheduleObjectArray;
  this->m_ScheduleObjectArray.m_Size = 0;
  if ( this->m_ScheduleObjectArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ScheduleObjectArray->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ScheduleObjectArray->m_Memory.m_pMemory);
      p_m_ScheduleObjectArray->m_Memory.m_pMemory = nullptr;
    }
    this->m_ScheduleObjectArray.m_Memory.m_nAllocationCount = 0;
  }
  v5 = p_m_ScheduleObjectArray->m_Memory.m_pMemory;
  this->m_ScheduleObjectArray.m_pElements = this->m_ScheduleObjectArray.m_Memory.m_pMemory;
  if ( this->m_ScheduleObjectArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      p_m_ScheduleObjectArray->m_Memory.m_pMemory = nullptr;
    }
    this->m_ScheduleObjectArray.m_Memory.m_nAllocationCount = 0;
  }
  p_m_SiblingQueues = &this->m_SiblingQueues;
  this->m_SiblingQueues.m_Size = 0;
  if ( this->m_SiblingQueues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SiblingQueues->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_SiblingQueues->m_Memory.m_pMemory);
      p_m_SiblingQueues->m_Memory.m_pMemory = nullptr;
    }
    this->m_SiblingQueues.m_Memory.m_nAllocationCount = 0;
  }
  v7 = p_m_SiblingQueues->m_Memory.m_pMemory;
  this->m_SiblingQueues.m_pElements = this->m_SiblingQueues.m_Memory.m_pMemory;
  if ( this->m_SiblingQueues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      p_m_SiblingQueues->m_Memory.m_pMemory = nullptr;
    }
    this->m_SiblingQueues.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408A90
// Name: public: virtual void CScheduleQueue::RemoveSiblingQueue(class IScheduleQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleQueue::RemoveSiblingQueue(CScheduleQueue *this, IScheduleQueue *pSibling)
{
  _RTL_CRITICAL_SECTION *p_m_csSiblingQueueArray; // edi

  p_m_csSiblingQueueArray = &this->m_csSiblingQueueArray;
  EnterCriticalSection(lpCriticalSection: &this->m_csSiblingQueueArray);
  CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int>>::FindAndRemove(
    this: &this->m_SiblingQueues,
    src: (CScheduleQueue **)&pSibling);
  LeaveCriticalSection(lpCriticalSection: p_m_csSiblingQueueArray);
}

//------------------------------------------------------------------------------
// Address: 0x00408AD0
// Name: public: virtual CScheduleObject::~CScheduleObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::~CScheduleObject(CScheduleObject *this)
{
  int v2; // ebx
  IScheduleObject *v3; // esi
  int v4; // ecx
  int v5; // eax
  CScheduleObject **v6; // edx
  int v7; // ecx
  int v8; // eax
  IScheduleObject *v9; // esi
  int v10; // ecx
  int v11; // eax
  CScheduleObject **v12; // edx
  int v13; // ecx
  CJob *m_pJob; // ecx
  int v15; // eax
  CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *p_m_DependantArray; // esi
  IScheduleObject **m_pMemory; // eax
  CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *p_m_DependencyArray; // esi
  IScheduleObject **v19; // eax
  int NumDependants; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  int ia; // [esp+14h] [ebp-10h]

  this->__vftable = (CScheduleObject_vtbl *)&CScheduleObject::`vftable';
  v2 = 0;
  i = this->m_DependencyArray.m_Size;
  if ( i > 0 )
  {
    do
    {
      v3 = this->m_DependencyArray.m_Memory.m_pMemory[v2];
      v4 = (int)v3[15].__vftable;
      v5 = 0;
      if ( v4 > 0 )
      {
        v6 = (CScheduleObject **)v3[12].__vftable;
        while ( *v6 != this )
        {
          ++v5;
          ++v6;
          if ( v5 >= v4 )
            goto LABEL_11;
        }
        if ( v5 != -1 )
        {
          v7 = v4 - v5 - 1;
          if ( v7 > 0 )
            _V_memmove(dest: &v3[12].AddRef + v5, src: &v3[12].Release + v5, count: 4 * v7);
          --v3[15].__vftable;
        }
      }
LABEL_11:
      ++v2;
    }
    while ( v2 < i );
  }
  v8 = 0;
  NumDependants = this->m_DependantArray.m_Size;
  ia = 0;
  if ( NumDependants > 0 )
  {
    do
    {
      v9 = this->m_DependantArray.m_Memory.m_pMemory[v8];
      v10 = (int)v9[9].__vftable;
      v11 = 0;
      if ( v10 > 0 )
      {
        v12 = (CScheduleObject **)v9[6].__vftable;
        while ( *v12 != this )
        {
          ++v11;
          ++v12;
          if ( v11 >= v10 )
            goto LABEL_22;
        }
        if ( v11 != -1 )
        {
          v13 = v10 - v11 - 1;
          if ( v13 > 0 )
            _V_memmove(dest: &v9[6].AddRef + v11, src: &v9[6].Release + v11, count: 4 * v13);
          --v9[9].__vftable;
        }
      }
LABEL_22:
      v8 = ia + 1;
      ia = v8;
    }
    while ( v8 < NumDependants );
  }
  m_pJob = this->m_pJob;
  if ( m_pJob != nullptr )
  {
    v15 = m_pJob->m_iRef - 1;
    m_pJob->m_iRef = v15;
    if ( v15 == 0 )
      ((void (__thiscall *)(CJob *, int))m_pJob->dtr_CJob)(a1: m_pJob, a2: 1);
    this->m_pJob = nullptr;
  }
  p_m_DependantArray = &this->m_DependantArray;
  this->m_DependantArray.m_Size = 0;
  if ( this->m_DependantArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DependantArray->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DependantArray->m_Memory.m_pMemory);
      p_m_DependantArray->m_Memory.m_pMemory = nullptr;
    }
    this->m_DependantArray.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_DependantArray->m_Memory.m_pMemory;
  this->m_DependantArray.m_pElements = this->m_DependantArray.m_Memory.m_pMemory;
  if ( this->m_DependantArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_DependantArray->m_Memory.m_pMemory = nullptr;
    }
    this->m_DependantArray.m_Memory.m_nAllocationCount = 0;
  }
  p_m_DependencyArray = &this->m_DependencyArray;
  this->m_DependencyArray.m_Size = 0;
  if ( this->m_DependencyArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_DependencyArray->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DependencyArray->m_Memory.m_pMemory);
      p_m_DependencyArray->m_Memory.m_pMemory = nullptr;
    }
    this->m_DependencyArray.m_Memory.m_nAllocationCount = 0;
  }
  v19 = p_m_DependencyArray->m_Memory.m_pMemory;
  this->m_DependencyArray.m_pElements = this->m_DependencyArray.m_Memory.m_pMemory;
  if ( this->m_DependencyArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      p_m_DependencyArray->m_Memory.m_pMemory = nullptr;
    }
    this->m_DependencyArray.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408CC0
// Name: public: virtual void CScheduleObject::AddDependency(class IScheduleObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::AddDependency(CScheduleObject *this, IScheduleObject *pDependency)
{
  int m_nAllocationCount; // eax
  CUtlMemory<KeyValues *,int> *p_m_DependencyArray; // esi
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // eax
  IScheduleObject_vtbl *v8; // edi
  IScheduleObject_vtbl *v9; // eax
  IScheduleObject *v10; // esi
  IScheduleObject_vtbl *v11; // ecx
  int v12; // eax
  CScheduleObject **v13; // eax

  m_nAllocationCount = this->m_DependencyArray.m_Memory.m_nAllocationCount;
  p_m_DependencyArray = (CUtlMemory<KeyValues *,int> *)&this->m_DependencyArray;
  m_Size = this->m_DependencyArray.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: p_m_DependencyArray, num: m_Size - m_nAllocationCount + 1);
  ++p_m_DependencyArray[1].m_pMemory;
  m_pMemory = p_m_DependencyArray->m_pMemory;
  v6 = (int)p_m_DependencyArray[1].m_pMemory - m_Size - 1;
  p_m_DependencyArray[1].m_nAllocationCount = (int)p_m_DependencyArray->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_DependencyArray->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (KeyValues *)pDependency;
  v8 = pDependency[15].__vftable;
  v9 = pDependency[13].__vftable;
  v10 = pDependency + 12;
  if ( (int)((char *)&v8->AddRef + 1) > (int)v9 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<KeyValues *,int> *)&pDependency[12], num: (char *)v8 - (char *)v9 + 1);
  ++pDependency[15].__vftable;
  v11 = v10->__vftable;
  v12 = (char *)pDependency[15].__vftable - (char *)v8 - 1;
  pDependency[16].__vftable = pDependency[12].__vftable;
  if ( v12 > 0 )
    _V_memmove(dest: &v11->Release + (_DWORD)v8, src: &v11->AddRef + (_DWORD)v8, count: 4 * v12);
  v13 = (CScheduleObject **)(&v10->AddRef + (_DWORD)v8);
  if ( v13 != nullptr )
    *v13 = this;
}

//------------------------------------------------------------------------------
// Address: 0x00408D80
// Name: public: virtual void CScheduleObject::AddDependant(class IScheduleObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleObject::AddDependant(CScheduleObject *this, IScheduleObject *pDependant)
{
  int m_nAllocationCount; // eax
  CUtlMemory<KeyValues *,int> *p_m_DependantArray; // esi
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // eax
  IScheduleObject_vtbl *v8; // edi
  IScheduleObject_vtbl *v9; // eax
  IScheduleObject *v10; // esi
  IScheduleObject_vtbl *v11; // ecx
  int v12; // eax
  CScheduleObject **v13; // eax

  m_nAllocationCount = this->m_DependantArray.m_Memory.m_nAllocationCount;
  p_m_DependantArray = (CUtlMemory<KeyValues *,int> *)&this->m_DependantArray;
  m_Size = this->m_DependantArray.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: p_m_DependantArray, num: m_Size - m_nAllocationCount + 1);
  ++p_m_DependantArray[1].m_pMemory;
  m_pMemory = p_m_DependantArray->m_pMemory;
  v6 = (int)p_m_DependantArray[1].m_pMemory - m_Size - 1;
  p_m_DependantArray[1].m_nAllocationCount = (int)p_m_DependantArray->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_DependantArray->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (KeyValues *)pDependant;
  v8 = pDependant[9].__vftable;
  v9 = pDependant[7].__vftable;
  v10 = pDependant + 6;
  if ( (int)((char *)&v8->AddRef + 1) > (int)v9 )
    CUtlMemory<int,int>::Grow(this: (CUtlMemory<KeyValues *,int> *)&pDependant[6], num: (char *)v8 - (char *)v9 + 1);
  ++pDependant[9].__vftable;
  v11 = v10->__vftable;
  v12 = (char *)pDependant[9].__vftable - (char *)v8 - 1;
  pDependant[10].__vftable = pDependant[6].__vftable;
  if ( v12 > 0 )
    _V_memmove(dest: &v11->Release + (_DWORD)v8, src: &v11->AddRef + (_DWORD)v8, count: 4 * v12);
  v13 = (CScheduleObject **)(&v10->AddRef + (_DWORD)v8);
  if ( v13 != nullptr )
    *v13 = this;
}

//------------------------------------------------------------------------------
// Address: 0x00408E40
// Name: public: virtual void CScheduleBatch::AddScheduleJobToBatch(class IScheduleObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleBatch::AddScheduleJobToBatch(CScheduleBatch *this, IScheduleObject *pScheduleObject)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IScheduleObject **m_pMemory; // ecx
  int v6; // eax
  IScheduleObject **v7; // eax
  IScheduleObject_vtbl *v8; // edi
  IScheduleObject_vtbl *v9; // eax
  IScheduleObject_vtbl *v10; // ecx
  int v11; // eax
  CScheduleBatch **v12; // eax

  pScheduleObject->OverrideDependencyPullArray(this: pScheduleObject, a2: &this->m_DependencyArray);
  m_Size = this->m_JobBatchArray.m_Size;
  m_nAllocationCount = this->m_JobBatchArray.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<KeyValues *,int> *)&this->m_JobBatchArray,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_JobBatchArray.m_Size;
  m_pMemory = this->m_JobBatchArray.m_Memory.m_pMemory;
  v6 = this->m_JobBatchArray.m_Size - m_Size - 1;
  this->m_JobBatchArray.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_JobBatchArray.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pScheduleObject;
  v8 = pScheduleObject[15].__vftable;
  v9 = pScheduleObject[13].__vftable;
  if ( (int)((char *)&v8->AddRef + 1) > (int)v9 )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<KeyValues *,int> *)&pScheduleObject[12],
      num: (char *)v8 - (char *)v9 + 1);
  ++pScheduleObject[15].__vftable;
  v10 = pScheduleObject[12].__vftable;
  v11 = (char *)pScheduleObject[15].__vftable - (char *)v8 - 1;
  pScheduleObject[16].__vftable = v10;
  if ( v11 > 0 )
    _V_memmove(dest: &v10->Release + (_DWORD)v8, src: &v10->AddRef + (_DWORD)v8, count: 4 * v11);
  v12 = (CScheduleBatch **)(&pScheduleObject[12].AddRef + (_DWORD)v8);
  if ( v12 != nullptr )
    *v12 = this;
}

//------------------------------------------------------------------------------
// Address: 0x00408F30
// Name: public: CScheduleBatch::CScheduleBatch(class ISchedulerThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
CScheduleBatch *__thiscall CScheduleBatch::CScheduleBatch(CScheduleBatch *this, ISchedulerThreadPool *pThreadPool)
{
  this->__vftable = (CScheduleBatch_vtbl *)&CScheduleObject::`vftable';
  this->m_pThreadPool = pThreadPool;
  this->m_iExecuteCounter = 0;
  this->m_iObjectType = 0;
  this->m_iOustandingDependencies = 0;
  this->m_DependencyArray.m_Memory.m_pMemory = nullptr;
  this->m_DependencyArray.m_Memory.m_nAllocationCount = 0;
  this->m_DependencyArray.m_Memory.m_nGrowSize = 0;
  this->m_DependencyArray.m_Size = 0;
  this->m_DependencyArray.m_pElements = nullptr;
  this->m_DependantArray.m_Memory.m_pMemory = nullptr;
  this->m_DependantArray.m_Memory.m_nAllocationCount = 0;
  this->m_DependantArray.m_Memory.m_nGrowSize = 0;
  this->m_DependantArray.m_Size = 0;
  this->m_DependantArray.m_pElements = nullptr;
  this->m_pGlobalScheduleQueue = nullptr;
  this->m_pAffinityScheduleQueue = nullptr;
  this->m_bScheduled = false;
  this->m_iRef = 0;
  memset(dst: (unsigned __int8 *)this->m_szFriendlyName, value: 0, count: sizeof(this->m_szFriendlyName));
  this->__vftable = (CScheduleBatch_vtbl *)&CScheduleBatch::`vftable';
  this->m_JobBatchArray.m_Memory.m_pMemory = nullptr;
  this->m_JobBatchArray.m_Memory.m_nAllocationCount = 0;
  this->m_JobBatchArray.m_Memory.m_nGrowSize = 0;
  this->m_JobBatchArray.m_Size = 0;
  this->m_JobBatchArray.m_pElements = nullptr;
  this->m_pDependencyPullArray = &this->m_JobBatchArray;
  this->m_bAddedBatchJobsToQueue = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408FE0
// Name: public: virtual CScheduleBatch::~CScheduleBatch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleBatch::~CScheduleBatch(CScheduleBatch *this)
{
  CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *p_m_JobBatchArray; // esi
  IScheduleObject **m_pMemory; // eax

  this->__vftable = (CScheduleBatch_vtbl *)&CScheduleBatch::`vftable';
  p_m_JobBatchArray = &this->m_JobBatchArray;
  this->m_JobBatchArray.m_Size = 0;
  if ( this->m_JobBatchArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_JobBatchArray->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_JobBatchArray->m_Memory.m_pMemory);
      p_m_JobBatchArray->m_Memory.m_pMemory = nullptr;
    }
    p_m_JobBatchArray->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_JobBatchArray->m_Memory.m_pMemory;
  p_m_JobBatchArray->m_pElements = p_m_JobBatchArray->m_Memory.m_pMemory;
  if ( p_m_JobBatchArray->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_JobBatchArray->m_Memory.m_pMemory = nullptr;
    }
    p_m_JobBatchArray->m_Memory.m_nAllocationCount = 0;
  }
  CScheduleObject::~CScheduleObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x004090C0
// Name: public: virtual void CScheduleQueue::AddSiblingQueue(class IScheduleQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScheduleQueue::AddSiblingQueue(CScheduleQueue *this, CScheduleQueue *pSibling)
{
  _RTL_CRITICAL_SECTION *p_m_csSiblingQueueArray; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CScheduleQueue **m_pMemory; // ecx
  int v7; // eax
  CScheduleQueue **v8; // eax

  p_m_csSiblingQueueArray = &this->m_csSiblingQueueArray;
  EnterCriticalSection(lpCriticalSection: &this->m_csSiblingQueueArray);
  m_Size = this->m_SiblingQueues.m_Size;
  m_nAllocationCount = this->m_SiblingQueues.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<KeyValues *,int> *)&this->m_SiblingQueues,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_SiblingQueues.m_Size;
  m_pMemory = this->m_SiblingQueues.m_Memory.m_pMemory;
  v7 = this->m_SiblingQueues.m_Size - m_Size - 1;
  this->m_SiblingQueues.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_SiblingQueues.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = pSibling;
  LeaveCriticalSection(lpCriticalSection: p_m_csSiblingQueueArray);
}

//------------------------------------------------------------------------------
// Address: 0x00409140
// Name: public: virtual bool CScheduleQueue::AddJobA(class IScheduleObject __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScheduleQueue::AddJobA(CScheduleQueue *this, IScheduleObject *pJob)
{
  _RTL_CRITICAL_SECTION *p_m_csSchedulObjectArray; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IScheduleObject **m_pMemory; // ecx
  int v7; // eax
  IScheduleObject **v8; // eax

  p_m_csSchedulObjectArray = &this->m_csSchedulObjectArray;
  EnterCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
  m_Size = this->m_ScheduleObjectArray.m_Size;
  m_nAllocationCount = this->m_ScheduleObjectArray.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<KeyValues *,int> *)&this->m_ScheduleObjectArray,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_ScheduleObjectArray.m_Size;
  m_pMemory = this->m_ScheduleObjectArray.m_Memory.m_pMemory;
  v7 = this->m_ScheduleObjectArray.m_Size - m_Size - 1;
  this->m_ScheduleObjectArray.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_ScheduleObjectArray.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = pJob;
  LeaveCriticalSection(lpCriticalSection: p_m_csSchedulObjectArray);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004091C0
// Name: public: virtual bool CScheduleQueue::AddJobs(class IScheduleObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScheduleQueue::AddJobs(CScheduleQueue *this, IScheduleObject **ppJobArray, int NumJobs)
{
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IScheduleObject **m_pMemory; // ecx
  int v9; // eax
  IScheduleObject **v10; // eax
  _RTL_CRITICAL_SECTION *p_m_csSchedulObjectArray; // [esp+4h] [ebp-4h]

  if ( NumJobs < 1 )
    return 0;
  p_m_csSchedulObjectArray = &this->m_csSchedulObjectArray;
  EnterCriticalSection(lpCriticalSection: &this->m_csSchedulObjectArray);
  for ( i = 0; i < NumJobs; ++i )
  {
    m_Size = this->m_ScheduleObjectArray.m_Size;
    m_nAllocationCount = this->m_ScheduleObjectArray.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<KeyValues *,int> *)&this->m_ScheduleObjectArray,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ScheduleObjectArray.m_Size;
    m_pMemory = this->m_ScheduleObjectArray.m_Memory.m_pMemory;
    v9 = this->m_ScheduleObjectArray.m_Size - m_Size - 1;
    this->m_ScheduleObjectArray.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ScheduleObjectArray.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = ppJobArray[i];
  }
  LeaveCriticalSection(lpCriticalSection: p_m_csSchedulObjectArray);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409260
// Name: public: virtual bool CScheduleQueue::AddAffinityJob(class IScheduleObject __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScheduleQueue::AddAffinityJob(CScheduleQueue *this, IScheduleObject *pJob)
{
  _RTL_CRITICAL_SECTION *p_m_csAffinityScheduleObjectArray; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IScheduleObject **m_pMemory; // ecx
  int v7; // eax
  IScheduleObject **v8; // eax

  p_m_csAffinityScheduleObjectArray = &this->m_csAffinityScheduleObjectArray;
  EnterCriticalSection(lpCriticalSection: &this->m_csAffinityScheduleObjectArray);
  m_Size = this->m_AffinityScheduleObjectArray.m_Size;
  m_nAllocationCount = this->m_AffinityScheduleObjectArray.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<KeyValues *,int> *)&this->m_AffinityScheduleObjectArray,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_AffinityScheduleObjectArray.m_Size;
  m_pMemory = this->m_AffinityScheduleObjectArray.m_Memory.m_pMemory;
  v7 = this->m_AffinityScheduleObjectArray.m_Size - m_Size - 1;
  this->m_AffinityScheduleObjectArray.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_AffinityScheduleObjectArray.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = pJob;
  LeaveCriticalSection(lpCriticalSection: p_m_csAffinityScheduleObjectArray);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C8ED0
// Name: public: virtual int CScheduleObject::GetObjectType(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CScheduleObject::GetObjectType(ConCommandBase *this)
{
  return this->m_pszHelpString;
}
