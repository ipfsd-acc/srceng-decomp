// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/jobmgr.cpp
// Functions: 42
// ============================================================

#include "gcsdk\jobmgr.h"

//------------------------------------------------------------------------------
// Address: 0x1000E650
// Name: public: unsigned __int64 GCSDK::CJobMgr::GetNewJobID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall GCSDK::CJobMgr::GetNewJobID(GCSDK::CJobMgr *this)
{
  IGameCoordinatorHost *v2; // eax
  unsigned __int64 result; // rax

  if ( GCSDK::GGCHost() != nullptr )
  {
    v2 = GCSDK::GGCHost();
    return v2->GenerateGID(this: v2);
  }
  else
  {
    result = this->m_unNextJobID + 1;
    this->m_unNextJobID = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E690
// Name: public: void GCSDK::CJobMgr::CheckThreadID(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::CheckThreadID(GCSDK::CJobMgr *this)
{
  DWORD CurrentThreadId; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( this->m_unFrameFuncThreadID == 0 )
    this->m_unFrameFuncThreadID = CurrentThreadId;
}

//------------------------------------------------------------------------------
// Address: 0x1000E6B0
// Name: GCSDK::JobTypeSortFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl GCSDK::JobTypeSortFunc(const GCSDK::JobType_t *const *lhs, const GCSDK::JobType_t *const *rhs)
{
  unsigned int m_eCreationMsg; // edx
  unsigned int v3; // esi

  m_eCreationMsg = (*lhs)->m_eCreationMsg;
  v3 = (*rhs)->m_eCreationMsg;
  if ( m_eCreationMsg == v3 )
    return (*lhs)->m_eServerType < (*rhs)->m_eServerType;
  else
    return m_eCreationMsg < v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000E6E0
// Name: private: static bool GCSDK::CJobMgr::JobSleepingLessFunc(struct GCSDK::CJobMgr::JobSleeping_t const __near &,struct GCSDK::CJobMgr::JobSleeping_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl GCSDK::CJobMgr::JobSleepingLessFunc(
        const GCSDK::CJobMgr::JobSleeping_t *lhs,
        const GCSDK::CJobMgr::JobSleeping_t *rhs)
{
  return lhs->m_SWakeupTime.m_lTime > rhs->m_SWakeupTime.m_lTime;
}

//------------------------------------------------------------------------------
// Address: 0x1000E710
// Name: private: void GCSDK::CJobMgr::TimeoutJob(class GCSDK::CJob __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::TimeoutJob(GCSDK::CJobMgr *this, GCSDK::CJob *job)
{
  unsigned int m_JobID; // ebx
  const char *Name; // eax
  bool v5; // cf
  const char *PauseReasonDescription; // [esp-4h] [ebp-18h]
  unsigned int m_JobID_high; // [esp+10h] [ebp-4h]

  if ( job->m_ePauseReason == k_EJobPauseReasonNetworkMsg )
  {
    job->m_flags.m_uFlags |= 0x40u;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 1) != 0 )
    {
      m_JobID = job->m_JobID;
      m_JobID_high = HIDWORD(job->m_JobID);
      PauseReasonDescription = GCSDK::CJob::GetPauseReasonDescription(this: job);
      Name = GCSDK::CJob::GetName(this: job);
      _LoggingSystem_Log(
        a1: LOG_CONSOLE,
        a2: 1,
        a3: "job warning: Resuming job '%s (id: %lld)' due to timeout while paused for %s\n",
        Name,
        __PAIR64__(m_JobID_high, m_JobID),
        PauseReasonDescription);
    }
    job->m_flags.m_uFlags |= 0x80u;
  }
  v5 = __CFADD__(LODWORD(this->m_JobStats.m_cJobsTimedOut)++, 1);
  HIDWORD(this->m_JobStats.m_cJobsTimedOut) += v5;
  this->m_bJobTimedOut = true;
  GCSDK::CJob::Continue(this: job);
  this->m_bJobTimedOut = false;
}

//------------------------------------------------------------------------------
// Address: 0x1000E7B0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobTimeout_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: m_pMemory,
                                                                                   a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EB60
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct GCSDK::JobType_t const __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F4C0
// Name: protected: int CUtlLinkedList<struct GCSDK::CJobMgr::JobYielding_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobYielding_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::AllocInternal(
        CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x1000F5F0
// Name: protected: int CUtlLinkedList<struct GCSDK::CJobMgr::JobTimeout_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobTimeout_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::AllocInternal(
        CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x100110B0
// Name: public: void CUtlPriorityQueue<struct GCSDK::CJobMgr::JobSleeping_t,class CDefUtlPriorityQueueLessFunc<struct GCSDK::CJobMgr::JobSleeping_t>,class CUtlMemory<struct GCSDK::CJobMgr::JobSleeping_t,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<GCSDK::CJobMgr::JobSleeping_t,CDefUtlPriorityQueueLessFunc<GCSDK::CJobMgr::JobSleeping_t>,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int>>::RemoveAtHead(
        CUtlPriorityQueue<GCSDK::CJobMgr::JobSleeping_t,CDefUtlPriorityQueueLessFunc<GCSDK::CJobMgr::JobSleeping_t>,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int> > *this)
{
  int m_Size; // ecx
  GCSDK::CJobMgr::JobSleeping_t *m_pMemory; // eax
  int v4; // ecx
  unsigned __int64 m_JobID; // xmm0_8
  GCSDK::CJobMgr::JobSleeping_t *v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // ebx
  bool v11; // al
  int v12; // ebx
  bool v13; // al
  GCSDK::CJobMgr::JobSleeping_t *v14; // edx
  unsigned __int64 v15; // xmm0_8
  unsigned __int64 m_lTime; // xmm1_8
  unsigned __int64 v17; // xmm2_8
  GCSDK::CJobMgr::JobSleeping_t *v18; // eax
  int v19; // ecx
  GCSDK::CJobMgr::JobSleeping_t *v20; // eax
  int half; // [esp+4h] [ebp-Ch]
  int count; // [esp+8h] [ebp-8h]
  int index; // [esp+Ch] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
    {
      m_pMemory = this->m_heap.m_Memory.m_pMemory;
      v4 = m_Size;
      m_JobID = this->m_heap.m_Memory.m_pMemory[v4 - 1].m_JobID;
      v6 = &this->m_heap.m_Memory.m_pMemory[v4 - 1];
      m_pMemory->m_JobID = m_JobID;
      m_pMemory->m_SWakeupTime.m_lTime = v6->m_SWakeupTime.m_lTime;
      m_pMemory->m_STimeTouched.m_lTime = v6->m_STimeTouched.m_lTime;
    }
    --this->m_heap.m_Size;
  }
  v7 = this->m_heap.m_Size;
  v8 = 0;
  index = 0;
  count = v7;
  if ( v7 != 0 )
  {
    v9 = 0;
    half = v7 / 2;
    if ( v7 / 2 > 0 )
    {
      while ( 1 )
      {
        v10 = 2 * v8 + 1;
        if ( v10 < count )
        {
          v11 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v8], a2: &this->m_heap.m_Memory.m_pMemory[v10]);
          v8 = index;
          if ( v11 )
            v9 = v10;
        }
        v12 = v10 + 1;
        if ( v12 < count )
        {
          v13 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v9], a2: &this->m_heap.m_Memory.m_pMemory[v12]);
          v8 = index;
          if ( v13 )
            v9 = v12;
        }
        if ( v9 == v8 )
          break;
        v14 = this->m_heap.m_Memory.m_pMemory;
        v15 = this->m_heap.m_Memory.m_pMemory[v8].m_JobID;
        m_lTime = this->m_heap.m_Memory.m_pMemory[v8].m_SWakeupTime.m_lTime;
        v17 = this->m_heap.m_Memory.m_pMemory[v8].m_STimeTouched.m_lTime;
        v18 = &this->m_heap.m_Memory.m_pMemory[v8];
        v19 = v9;
        v18->m_JobID = this->m_heap.m_Memory.m_pMemory[v9].m_JobID;
        v18->m_SWakeupTime.m_lTime = v14[v9].m_SWakeupTime.m_lTime;
        v18->m_STimeTouched.m_lTime = v14[v9].m_STimeTouched.m_lTime;
        v20 = this->m_heap.m_Memory.m_pMemory;
        v20[v19].m_JobID = v15;
        v20[v19].m_SWakeupTime.m_lTime = m_lTime;
        v20[v19].m_STimeTouched.m_lTime = v17;
        index = v9;
        if ( v9 >= half )
          break;
        v8 = v9;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011760
// Name: public: void CUtlLinkedList<struct GCSDK::CJobMgr::JobYielding_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobYielding_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::RemoveAll(
        CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100117C0
// Name: public: void CUtlLinkedList<struct GCSDK::CJobMgr::JobTimeout_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobTimeout_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::RemoveAll(
        CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011820
// Name: public: void CUtlLinkedList<struct GCSDK::CJobMgr::JobYielding_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobYielding_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::Unlink(
        CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011920
// Name: public: void CUtlLinkedList<struct GCSDK::CJobMgr::JobTimeout_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobTimeout_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::Unlink(
        CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015000
// Name: public: bool GCSDK::CJobMgr::BJobExists(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CJobMgr::BJobExists(GCSDK::CJobMgr *this, unsigned __int64 jobID)
{
  CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t search; // [esp+0h] [ebp-10h] BYREF

  search.key = jobID;
  return CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Find(
           this: &this->m_MapJob.m_Tree,
           &search) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10015030
// Name: public: class GCSDK::CJob __near * GCSDK::CJobMgr::GetPJob(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__thiscall GCSDK::CJobMgr::GetPJob(GCSDK::CJobMgr *this, unsigned __int64 jobID)
{
  int v3; // eax
  CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t search; // [esp+4h] [ebp-10h] BYREF

  search.key = jobID;
  v3 = CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Find(
         this: &this->m_MapJob.m_Tree,
         &search);
  if ( v3 == -1 )
    return nullptr;
  else
    return this->m_MapJob.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10015070
// Name: private: bool GCSDK::CJobMgr::BResumeSleepingJobs(class CLimitTimer __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GCSDK::CJobMgr::BResumeSleepingJobs(GCSDK::CJobMgr *this, CLimitTimer *limitTimer)
{
  GCSDK::CJobMgr::JobSleeping_t *m_pMemory; // esi
  int m_JobID_high; // eax
  int v5; // esi
  GCSDK::CJob *elem; // ecx
  int m_JobID; // eax
  int v9; // eax
  CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t search; // [esp+4h] [ebp-1Ch] BYREF
  unsigned __int64 v11; // [esp+14h] [ebp-Ch] BYREF
  unsigned __int64 *v12; // [esp+1Ch] [ebp-4h]

  if ( this->m_QueueJobSleeping.m_heap.m_Size != 0 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_QueueJobSleeping.m_heap.m_Memory.m_pMemory;
      if ( m_pMemory->m_SWakeupTime.m_lTime > GCSDK::CJobTime::sm_lTimeCur )
        break;
      m_JobID_high = HIDWORD(m_pMemory->m_JobID);
      LODWORD(search.key) = m_pMemory->m_JobID;
      HIDWORD(search.key) = m_JobID_high;
      v5 = CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Find(
             this: &this->m_MapJob.m_Tree,
             &search);
      CUtlPriorityQueue<GCSDK::CJobMgr::JobSleeping_t,CDefUtlPriorityQueueLessFunc<GCSDK::CJobMgr::JobSleeping_t>,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int>>::RemoveAtHead(this: &this->m_QueueJobSleeping);
      if ( v5 != -1 )
      {
        elem = this->m_MapJob.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
        if ( elem->m_ePauseReason == k_EJobPauseReasonSleepForTime )
          GCSDK::CJob::Continue(this: elem);
        v12 = &v11;
        v11 = __rdtsc();
        if ( v11 >= limitTimer->m_lCycleLimit )
          return this->m_QueueJobSleeping.m_heap.m_Size > 0;
      }
      if ( this->m_QueueJobSleeping.m_heap.m_Size == 0 )
        return this->m_QueueJobSleeping.m_heap.m_Size > 0;
    }
    if ( GCSDK::CJobTime::CServerMicroSecsPassed(this: &m_pMemory->m_STimeTouched) >= 10000000 )
    {
      m_JobID = m_pMemory->m_JobID;
      HIDWORD(search.key) = HIDWORD(m_pMemory->m_JobID);
      LODWORD(search.key) = m_JobID;
      v9 = CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Find(
             this: &this->m_MapJob.m_Tree,
             &search);
      if ( v9 != -1 )
        GCSDK::CJob::Heartbeat(this: this->m_MapJob.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem);
    }
  }
  return this->m_QueueJobSleeping.m_heap.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015190
// Name: public: void CUtlPriorityQueue<struct GCSDK::CJobMgr::JobSleeping_t,class CDefUtlPriorityQueueLessFunc<struct GCSDK::CJobMgr::JobSleeping_t>,class CUtlMemory<struct GCSDK::CJobMgr::JobSleeping_t,int>>::Insert(struct GCSDK::CJobMgr::JobSleeping_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<GCSDK::CJobMgr::JobSleeping_t,CDefUtlPriorityQueueLessFunc<GCSDK::CJobMgr::JobSleeping_t>,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int>>::Insert(
        CUtlPriorityQueue<GCSDK::CJobMgr::JobSleeping_t,CDefUtlPriorityQueueLessFunc<GCSDK::CJobMgr::JobSleeping_t>,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int> > *this,
        const GCSDK::CJobMgr::JobSleeping_t *element)
{
  CUtlPriorityQueue<GCSDK::CJobMgr::JobSleeping_t,CDefUtlPriorityQueueLessFunc<GCSDK::CJobMgr::JobSleeping_t>,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int> > *v2; // ebx
  int v3; // ecx
  GCSDK::CJobMgr::JobSleeping_t *m_pMemory; // eax
  int v5; // edi
  int v6; // esi
  unsigned int v7; // ebx
  GCSDK::CJobMgr::JobSleeping_t *v8; // eax
  unsigned __int64 m_JobID; // xmm0_8
  unsigned __int64 m_lTime; // xmm1_8
  unsigned __int64 v11; // xmm2_8
  GCSDK::CJobMgr::JobSleeping_t *v12; // eax

  v2 = this;
  v3 = CUtlVector<GCSDK::CJobMgr::JobSleeping_t,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int>>::InsertBefore(
         this: &this->m_heap,
         elem: this->m_heap.m_Size);
  v2->m_heap.m_Memory.m_pMemory[v3] = *element;
  if ( v3 != 0 )
  {
    while ( 1 )
    {
      m_pMemory = v2->m_heap.m_Memory.m_pMemory;
      v5 = (v3 + 1) / 2 - 1;
      v6 = v5;
      v7 = v3;
      if ( this->m_LessFunc(a1: &m_pMemory[v3], a2: &m_pMemory[v5]) )
        break;
      v8 = this->m_heap.m_Memory.m_pMemory;
      m_JobID = this->m_heap.m_Memory.m_pMemory[v6].m_JobID;
      m_lTime = this->m_heap.m_Memory.m_pMemory[v6].m_SWakeupTime.m_lTime;
      v11 = this->m_heap.m_Memory.m_pMemory[v6].m_STimeTouched.m_lTime;
      v8[v6].m_JobID = this->m_heap.m_Memory.m_pMemory[v7].m_JobID;
      v8[v6].m_SWakeupTime.m_lTime = v8[v7].m_SWakeupTime.m_lTime;
      v8[v6].m_STimeTouched.m_lTime = v8[v7].m_STimeTouched.m_lTime;
      v12 = this->m_heap.m_Memory.m_pMemory;
      v12[v7].m_JobID = m_JobID;
      v12[v7].m_SWakeupTime.m_lTime = m_lTime;
      v12[v7].m_STimeTouched.m_lTime = v11;
      v3 = v5;
      if ( v5 == 0 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015400
// Name: public: GCSDK::CJobMgr::~CJobMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::~CJobMgr(GCSDK::CJobMgr *this)
{
  CUtlRBTree<CUtlMap<unsigned int,int,int>::Node_t,int,CUtlMap<unsigned int,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<unsigned int,int,int>::Node_t,int,CUtlMap<unsigned int,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int>,int>>(this: &this->m_mapOrphanMessages.m_Tree);
  CUtlRBTree<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int,CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int,CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int>,int>>(this: &this->m_mapStatsBucket.m_Tree);
  CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>(this: &this->m_MapJobTimeoutsIndexByJobID.m_Tree);
  CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::RemoveAll(this: &this->m_ListJobTimeouts);
  if ( this->m_ListJobTimeouts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ListJobTimeouts.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ListJobTimeouts.m_Memory.m_pMemory);
      this->m_ListJobTimeouts.m_Memory.m_pMemory = nullptr;
    }
    this->m_ListJobTimeouts.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_QueueJobSleeping);
  CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::RemoveAll(this: &this->m_ListJobsYieldingRegPri);
  if ( this->m_ListJobsYieldingRegPri.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ListJobsYieldingRegPri.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ListJobsYieldingRegPri.m_Memory.m_pMemory);
      this->m_ListJobsYieldingRegPri.m_Memory.m_pMemory = nullptr;
    }
    this->m_ListJobsYieldingRegPri.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>(this: &this->m_MapJob.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100154A0
// Name: private: bool GCSDK::CJobMgr::BResumeYieldingJobsFromList(class CUtlLinkedList<struct GCSDK::CJobMgr::JobYielding_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobYielding_t,int>,int>> __near &,unsigned int,class CLimitTimer __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GCSDK::CJobMgr::BResumeYieldingJobsFromList(
        GCSDK::CJobMgr *this,
        CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int> > *listJobsYielding,
        unsigned int nCurrentIteration,
        CLimitTimer *limitTimer)
{
  bool v5; // zf
  int m_Head; // edi
  unsigned int v7; // ebx
  int v8; // eax
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int> *m_pMemory; // ecx
  int m_Previous; // eax
  int *p_m_Previous; // edx
  CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int> > *p_m_Next; // ecx
  int m_Next; // eax
  GCSDK::CJob *elem; // ecx
  CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t search; // [esp+4h] [ebp-24h] BYREF
  unsigned __int64 v17; // [esp+14h] [ebp-14h]
  CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int> > *p_m_Tree; // [esp+1Ch] [ebp-Ch]
  int iJob; // [esp+20h] [ebp-8h]
  int *v20; // [esp+24h] [ebp-4h]
  CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int> > *listJobsYieldinga; // [esp+30h] [ebp+8h]

  v5 = listJobsYielding->m_ElementCount == 0;
  p_m_Tree = &this->m_MapJob.m_Tree;
  if ( !v5 )
  {
    do
    {
      m_Head = listJobsYielding->m_Head;
      v7 = m_Head;
      if ( listJobsYielding->m_Memory.m_pMemory[m_Head].m_Element.m_nIteration > nCurrentIteration )
        break;
      search.key = listJobsYielding->m_Memory.m_pMemory[m_Head].m_Element.m_JobID;
      v8 = CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Find(
             this: p_m_Tree,
             &search);
      iJob = v8;
      if ( m_Head >= 0
        && m_Head < listJobsYielding->m_Memory.m_nAllocationCount
        && m_Head <= listJobsYielding->m_LastAlloc.index )
      {
        m_pMemory = listJobsYielding->m_Memory.m_pMemory;
        if ( listJobsYielding->m_Memory.m_pMemory[v7].m_Previous != m_Head )
        {
          m_Previous = m_pMemory[v7].m_Previous;
          p_m_Previous = &m_pMemory[v7].m_Previous;
          v20 = p_m_Previous;
          if ( m_Previous == -1 )
          {
            m_Next = m_pMemory[v7].m_Next;
            p_m_Next = (CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int> > *)&m_pMemory[v7].m_Next;
            listJobsYieldinga = p_m_Next;
            listJobsYielding->m_Head = m_Next;
          }
          else
          {
            listJobsYieldinga = (CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int> > *)&m_pMemory[v7].m_Next;
            m_pMemory[m_Previous].m_Next = (int)listJobsYieldinga->m_Memory.m_pMemory;
            p_m_Previous = v20;
            p_m_Next = listJobsYieldinga;
          }
          if ( p_m_Next->m_Memory.m_pMemory == (UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int> *)-1 )
          {
            listJobsYielding->m_Tail = *p_m_Previous;
          }
          else
          {
            listJobsYielding->m_Memory.m_pMemory[(int)p_m_Next->m_Memory.m_pMemory].m_Previous = *p_m_Previous;
            p_m_Previous = v20;
            p_m_Next = listJobsYieldinga;
          }
          v8 = iJob;
          p_m_Next->m_Memory.m_pMemory = (UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int> *)m_Head;
          *p_m_Previous = m_Head;
          --listJobsYielding->m_ElementCount;
        }
      }
      listJobsYielding->m_Memory.m_pMemory[v7].m_Next = listJobsYielding->m_FirstFree;
      listJobsYielding->m_FirstFree = m_Head;
      if ( v8 != -1 )
      {
        elem = p_m_Tree->m_Elements.m_pMemory[v8].m_Data.elem;
        if ( elem->m_ePauseReason == k_EJobPauseReasonYield )
          GCSDK::CJob::Continue(this: elem);
        v17 = __rdtsc();
        if ( v17 >= limitTimer->m_lCycleLimit )
          break;
      }
    }
    while ( listJobsYielding->m_ElementCount != 0 );
  }
  return listJobsYielding->m_ElementCount > 0;
}

//------------------------------------------------------------------------------
// Address: 0x100155F0
// Name: public: int CUtlLinkedList<struct GCSDK::CJobMgr::JobYielding_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobYielding_t,int>,int>>::AddToTail(struct GCSDK::CJobMgr::JobYielding_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::AddToTail(
        CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int> > *this,
        const GCSDK::CJobMgr::JobYielding_t *src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int> *v8; // esi

  result = CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::Unlink(
      this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015670
// Name: public: int CUtlLinkedList<struct GCSDK::CJobMgr::JobTimeout_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct GCSDK::CJobMgr::JobTimeout_t,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::AddToTail(
        CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *m_pMemory; // eax
  unsigned int v5; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *v7; // esi

  result = CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::Unlink(
      this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = v3;
    m_pMemory[v5].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = v3;
    if ( m_Tail == -1 )
      this->m_Head = v3;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v3;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( v7 != nullptr )
    {
      GCSDK::CJobTime::CJobTime(this: &v7->m_Element.m_STimePaused);
      GCSDK::CJobTime::CJobTime(this: &v7->m_Element.m_STimeTouched);
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015840
// Name: public: GCSDK::CJobMgr::CJobMgr(void)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJobMgr *__thiscall GCSDK::CJobMgr::CJobMgr(GCSDK::CJobMgr *this)
{
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *m_pMemory; // edx

  this->m_MapJob.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned __int64 *, const unsigned __int64 *))CIgnoredSessionsMgr::XNKID_LessFunc;
  this->m_MapJob.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_MapJob.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_MapJob.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_MapJob.m_Tree.m_NumElements = 0;
  this->m_MapJob.m_Tree.m_Root = -1;
  this->m_MapJob.m_Tree.m_FirstFree = -1;
  this->m_MapJob.m_Tree.m_LastAlloc.index = -1;
  this->m_MapJob.m_Tree.m_pElements = this->m_MapJob.m_Tree.m_Elements.m_pMemory;
  this->m_ListJobsYieldingRegPri.m_Memory.m_pMemory = nullptr;
  this->m_ListJobsYieldingRegPri.m_Memory.m_nAllocationCount = 0;
  this->m_ListJobsYieldingRegPri.m_Memory.m_nGrowSize = 0;
  this->m_ListJobsYieldingRegPri.m_LastAlloc.index = -1;
  this->m_ListJobsYieldingRegPri.m_pElements = this->m_ListJobsYieldingRegPri.m_Memory.m_pMemory;
  this->m_ListJobsYieldingRegPri.m_Head = -1;
  this->m_ListJobsYieldingRegPri.m_Tail = -1;
  this->m_ListJobsYieldingRegPri.m_FirstFree = -1;
  this->m_ListJobsYieldingRegPri.m_ElementCount = 0;
  this->m_ListJobsYieldingRegPri.m_NumAlloced = 0;
  this->m_QueueJobSleeping.m_heap.m_Memory.m_pMemory = nullptr;
  this->m_QueueJobSleeping.m_heap.m_Memory.m_nAllocationCount = 0;
  this->m_QueueJobSleeping.m_heap.m_Memory.m_nGrowSize = 0;
  this->m_QueueJobSleeping.m_heap.m_Size = 0;
  this->m_QueueJobSleeping.m_heap.m_pElements = nullptr;
  this->m_QueueJobSleeping.m_LessFunc = (bool (__cdecl *)(const GCSDK::CJobMgr::JobSleeping_t *, const GCSDK::CJobMgr::JobSleeping_t *))GCSDK::CJobMgr::JobSleepingLessFunc;
  this->m_ListJobTimeouts.m_Memory.m_pMemory = nullptr;
  this->m_ListJobTimeouts.m_Memory.m_nAllocationCount = 0;
  this->m_ListJobTimeouts.m_Memory.m_nGrowSize = 0;
  this->m_ListJobTimeouts.m_LastAlloc.index = -1;
  m_pMemory = this->m_ListJobTimeouts.m_Memory.m_pMemory;
  this->m_ListJobTimeouts.m_Head = -1;
  this->m_ListJobTimeouts.m_Tail = -1;
  this->m_ListJobTimeouts.m_FirstFree = -1;
  this->m_ListJobTimeouts.m_ElementCount = 0;
  this->m_ListJobTimeouts.m_NumAlloced = 0;
  this->m_ListJobTimeouts.m_pElements = m_pMemory;
  this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Root = -1;
  this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_NumElements = 0;
  this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_FirstFree = -1;
  this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_LastAlloc.index = -1;
  this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_pElements = this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory;
  memset(dst: (unsigned __int8 *)&this->m_JobStats, value: 0, count: sizeof(this->m_JobStats));
  this->m_unNextJobID = 0;
  this->m_mapStatsBucket.m_Tree.m_LessFunc.m_LessFunc = CDefOps<void *>::LessFunc;
  this->m_mapStatsBucket.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapStatsBucket.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapStatsBucket.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_mapStatsBucket.m_Tree.m_Root = -1;
  this->m_mapStatsBucket.m_Tree.m_NumElements = 0;
  this->m_mapStatsBucket.m_Tree.m_FirstFree = -1;
  this->m_mapStatsBucket.m_Tree.m_LastAlloc.index = -1;
  this->m_mapStatsBucket.m_Tree.m_pElements = this->m_mapStatsBucket.m_Tree.m_Elements.m_pMemory;
  this->m_mapOrphanMessages.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_mapOrphanMessages.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapOrphanMessages.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapOrphanMessages.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_mapOrphanMessages.m_Tree.m_Root = -1;
  this->m_mapOrphanMessages.m_Tree.m_NumElements = 0;
  this->m_mapOrphanMessages.m_Tree.m_FirstFree = -1;
  this->m_mapOrphanMessages.m_Tree.m_LastAlloc.index = -1;
  this->m_mapOrphanMessages.m_Tree.m_pElements = this->m_mapOrphanMessages.m_Tree.m_Elements.m_pMemory;
  if ( this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned __int64 *, const unsigned __int64 *))CIgnoredSessionsMgr::XNKID_LessFunc;
  if ( this->m_mapOrphanMessages.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_mapOrphanMessages.m_Tree.m_LessFunc.m_LessFunc = CDefOps<void *>::LessFunc;
  this->m_bJobTimedOut = false;
  this->m_nCurrentYieldIterationRegPri = 0;
  this->m_bProfiling = false;
  this->m_cErrorsToReport = 0;
  this->m_unFrameFuncThreadID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100159F0
// Name: public: bool GCSDK::CJobMgr::BFrameFuncRunYieldingJobs(class CLimitTimer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CJobMgr::BFrameFuncRunYieldingJobs(GCSDK::CJobMgr *this, CLimitTimer *limitTimer)
{
  DWORD CurrentThreadId; // eax
  bool v4; // bl
  unsigned int m_nCurrentYieldIterationRegPri; // [esp-8h] [ebp-10h]

  CurrentThreadId = GetCurrentThreadId();
  if ( this->m_unFrameFuncThreadID == 0 )
    this->m_unFrameFuncThreadID = CurrentThreadId;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CJobMgr::BResumeYieldingJobs",
    a3: 0,
    a4: "Jobs/Coroutines",
    a5: false,
    a6: 4);
  m_nCurrentYieldIterationRegPri = this->m_nCurrentYieldIterationRegPri;
  this->m_nCurrentYieldIterationRegPri = m_nCurrentYieldIterationRegPri + 1;
  v4 = GCSDK::CJobMgr::BResumeYieldingJobsFromList(
         this,
         listJobsYielding: &this->m_ListJobsYieldingRegPri,
         nCurrentIteration: m_nCurrentYieldIterationRegPri,
         limitTimer);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  this->m_JobStats.m_cJobsCurrent = this->m_MapJob.m_Tree.m_NumElements;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10015A60
// Name: public: void GCSDK::CJobMgr::WakeupLockedJob(class GCSDK::CJob __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::WakeupLockedJob(GCSDK::CJobMgr *this, GCSDK::CJob *job)
{
  int m_JobID; // eax
  GCSDK::CJobMgr::JobYielding_t src; // [esp+4h] [ebp-10h] BYREF

  if ( job->m_ePauseReason == k_EJobPauseReasonWaitingForLock )
  {
    m_JobID = job->m_JobID;
    HIDWORD(src.m_JobID) = HIDWORD(job->m_JobID);
    LODWORD(src.m_JobID) = m_JobID;
    src.m_nIteration = this->m_nCurrentYieldIterationRegPri;
    CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::AddToTail(
      this: &this->m_ListJobsYieldingRegPri,
      &src);
    job->m_ePauseReason = k_EJobPauseReasonYield;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015B00
// Name: private: static void GCSDK::CJobMgr::RegisterJobType(struct GCSDK::JobType_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::CJobMgr::RegisterJobType(const GCSDK::JobType_t *pJobType)
{
  CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl*)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short> > *v1; // esi
  unsigned __int16 v2; // ax
  int v3; // edi
  unsigned __int16 parent[2]; // [esp+8h] [ebp-8h] BYREF
  bool leftchild[4]; // [esp+Ch] [ebp-4h] BYREF

  v1 = GCSDK::GMapJobTypes();
  *(_DWORD *)parent = 0xFFFF;
  leftchild[0] = false;
  CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl *)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: v1,
    insert: &pJobType,
    parent,
    leftchild);
  v2 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)v1);
  v3 = v2;
  CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl *)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short>>::LinkToParent(
    this: v1,
    i: v2,
    parent: parent[0],
    isLeft: leftchild[0]);
  ++v1->m_NumElements;
  if ( &v1->m_Elements.m_pMemory[v3] != (UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short> *)-8 )
    v1->m_Elements.m_pMemory[v3].m_Data = pJobType;
}

//------------------------------------------------------------------------------
// Address: 0x10015B70
// Name: private: bool GCSDK::CJobMgr::BLaunchJobFromNetworkMsg(void __near *,struct GCSDK::JobMsgInfo_t const __near &,class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CJobMgr::BLaunchJobFromNetworkMsg(
        GCSDK::CJobMgr *this,
        void *pParent,
        GCSDK::JobType_t *jobMsgInfo,
        GCSDK::CNetPacket *pNetPacket)
{
  GCSDK::JobType_t *v4; // ebx
  GCSDK::EServerType m_eServerType; // edx
  CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl*)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short> > *v6; // eax
  int v7; // edi
  CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl*)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short> > *v8; // eax
  CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl*)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short> > *v9; // eax
  GCSDK::CJob *v10; // eax
  GCSDK::JobType_t jobSearch; // [esp+Ch] [ebp-10h] BYREF

  v4 = jobMsgInfo;
  m_eServerType = jobMsgInfo[1].m_eServerType;
  jobSearch.m_eCreationMsg = (unsigned int)jobMsgInfo->m_pchName;
  jobSearch.m_pchName = nullptr;
  jobSearch.m_pJobFactory = nullptr;
  jobSearch.m_eServerType = m_eServerType;
  jobMsgInfo = &jobSearch;
  v6 = GCSDK::GMapJobTypes();
  v7 = CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl *)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short>>::Find(
         this: v6,
         search: &jobMsgInfo);
  v8 = GCSDK::GMapJobTypes();
  if ( v7 >= v8->m_Elements.m_nAllocationCount
    || (unsigned __int16)v7 > v8->m_LastAlloc.index
    || CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl *)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short>>::LeftChild(
         this: v8,
         i: v7) == (_WORD)v7 )
  {
    return 0;
  }
  v9 = GCSDK::GMapJobTypes();
  v10 = v9->m_Elements.m_pMemory[v7].m_Data->m_pJobFactory(a1: pParent, a2: nullptr);
  GCSDK::CJob::StartJobFromNetworkMsg(this: v10, pNetPacket, gidJobIDSrc: (const unsigned __int64 *)&v4->m_eServerType);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015C20
// Name: public: int CUtlMap<unsigned int,int,int>::Insert(unsigned int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<unsigned int,int,int>::Insert(
        CUtlMap<unsigned int,int,int> *this,
        unsigned int *key,
        int insert)
{
  int v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<unsigned int,int,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<unsigned int,int,int>::Node_t,int,CUtlMap<unsigned int,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<unsigned int,int,int>::Node_t,int,CUtlMap<unsigned int,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<unsigned int,int,int>::Node_t,int,CUtlMap<unsigned int,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10015CA0
// Name: public: void GCSDK::CJobMgr::InsertJob(class GCSDK::CJob __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::InsertJob(GCSDK::CJobMgr *this, GCSDK::CJob *job)
{
  int m_JobID_high; // edx
  CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t insert; // [esp+0h] [ebp-10h] BYREF

  LODWORD(insert.key) = job->m_JobID;
  m_JobID_high = HIDWORD(job->m_JobID);
  insert.elem = job;
  HIDWORD(insert.key) = m_JobID_high;
  CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Insert(
    this: &this->m_MapJob.m_Tree,
    &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10015CD0
// Name: private: void GCSDK::CJobMgr::AccumulateStatsofJob(class GCSDK::CJob __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::AccumulateStatsofJob(GCSDK::CJobMgr *this, GCSDK::CJob *job)
{
  GCSDK::CJobMgr *v2; // edi
  bool v3; // zf
  unsigned __int64 v4; // kr00_8
  bool v5; // cf
  const char *Name; // esi
  int v7; // eax
  const char *v8; // eax
  int m_rgchName; // esi
  int m_Int64; // eax
  CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t search; // [esp+8h] [ebp-2A4h] BYREF
  GCSDK::JobStatsBucket_t bucket; // [esp+E8h] [ebp-1C4h] BYREF
  CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t insert; // [esp+1C0h] [ebp-ECh] BYREF
  GCSDK::CJobMgr *v14; // [esp+2A0h] [ebp-Ch]
  unsigned __int64 v15; // [esp+2A4h] [ebp-8h]

  v2 = this;
  v3 = !this->m_bProfiling;
  v14 = this;
  if ( !v3 || job->m_flags.m_uFlags != 0 )
  {
    if ( job->m_flags.m_uFlags != 0 )
      ++this->m_cErrorsToReport;
    v15 = __rdtsc();
    v4 = v15 - job->m_FastTimerDelta.m_Duration.m_Int64;
    job->m_FastTimerDelta.m_Duration.m_Int64 = v4;
    v5 = __CFADD__((_DWORD)v4, job->m_cyclecountTotal.m_Int64);
    LODWORD(job->m_cyclecountTotal.m_Int64) += v4;
    HIDWORD(job->m_cyclecountTotal.m_Int64) += HIDWORD(job->m_FastTimerDelta.m_Duration.m_Int64) + v5;
    Name = GCSDK::CJob::GetName(this: job);
    memset(dst: (unsigned __int8 *)&search.elem, value: 0, count: sizeof(search.elem));
    search.key = (unsigned int)Name;
    v7 = CUtlRBTree<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int,CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int>,int>>::Find(
           this: &v2->m_mapStatsBucket.m_Tree,
           &search);
    if ( v7 == -1 )
    {
      memset(dst: (unsigned __int8 *)&bucket, value: 0, count: sizeof(bucket));
      v8 = GCSDK::CJob::GetName(this: job);
      V_strncpy(pDest: bucket.m_rgchName, pSrc: v8, maxLen: 64);
      insert.key = (unsigned int)Name;
      insert.elem = bucket;
      v7 = CUtlRBTree<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int,CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int>,int>>::Insert(
             this: &v14->m_mapStatsBucket.m_Tree,
             &insert);
      v2 = v14;
    }
    m_rgchName = (int)v2->m_mapStatsBucket.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.m_rgchName;
    v5 = __CFADD__(v2->m_mapStatsBucket.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.m_cCompletes, 1);
    ++*(_DWORD *)(m_rgchName + 64);
    *(_DWORD *)(m_rgchName + 68) += v5;
    *(_QWORD *)(m_rgchName + 96) += job->m_cLocksAttempted;
    *(_QWORD *)(m_rgchName + 104) += job->m_cLocksWaitedFor;
    *(_QWORD *)(m_rgchName + 112) += (job->m_flags.m_uFlags & 2) != 0;
    *(_QWORD *)(m_rgchName + 120) += (job->m_flags.m_uFlags & 4) != 0;
    *(_QWORD *)(m_rgchName + 128) += (job->m_flags.m_uFlags & 8) != 0;
    *(_QWORD *)(m_rgchName + 136) += (job->m_flags.m_uFlags & 0x10) != 0;
    *(_QWORD *)(m_rgchName + 160) += job->m_flags.m_uFlags & 1;
    *(_QWORD *)(m_rgchName + 88) += (job->m_flags.m_uFlags & 0x20) != 0;
    *(_QWORD *)(m_rgchName + 80) += (job->m_flags.m_uFlags & 0x40) != 0;
    *(_QWORD *)(m_rgchName + 144) += GCSDK::CJobTime::CServerMicroSecsPassed(this: &job->m_STimeStarted);
    m_Int64 = job->m_cyclecountTotal.m_Int64;
    v5 = __CFADD__(m_Int64, *(_DWORD *)(m_rgchName + 168));
    *(_DWORD *)(m_rgchName + 168) += m_Int64;
    *(_DWORD *)(m_rgchName + 172) += HIDWORD(job->m_cyclecountTotal.m_Int64) + v5;
    if ( job->m_cyclecountTotal.m_Int64 > *(_QWORD *)(m_rgchName + 72) )
      *(_QWORD *)(m_rgchName + 72) = job->m_cyclecountTotal.m_Int64;
    if ( LODWORD(job->m_STimeStarted.m_lTime) != LODWORD(job->m_STimeSwitched.m_lTime)
      || HIDWORD(job->m_STimeStarted.m_lTime) != HIDWORD(job->m_STimeSwitched.m_lTime) )
    {
      ++*(_QWORD *)(m_rgchName + 152);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015F00
// Name: private: void GCSDK::CJobMgr::RecordOrphanedMessage(unsigned int,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::RecordOrphanedMessage(
        GCSDK::CJobMgr *this,
        unsigned int eMsg,
        unsigned __int64 jobIDTarget)
{
  char IsChannelEnabled; // al
  unsigned int v5; // esi
  const char *v6; // eax
  int v7; // eax
  unsigned __int64 v8; // [esp-8h] [ebp-18h]
  CUtlMap<unsigned int,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  IsChannelEnabled = _LoggingSystem_IsChannelEnabled(a1: LOG_CONSOLE, a2: 0);
  v5 = eMsg;
  if ( IsChannelEnabled != 0 )
  {
    v8 = jobIDTarget;
    v6 = GCSDK::PchMsgNameFromEMsg(eMsg);
    _LoggingSystem_Log(
      a1: LOG_CONSOLE,
      a2: 0,
      a3: "Message %s arrived responding to job %lld which no longer exists, dropping message\n",
      v6,
      v8);
  }
  search.key = v5;
  v7 = CUtlRBTree<CUtlMap<unsigned int,int,int>::Node_t,int,CUtlMap<unsigned int,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int>,int>>::Find(
         this: &this->m_mapOrphanMessages.m_Tree,
         &search);
  if ( v7 == -1 )
  {
    HIDWORD(jobIDTarget) = 0;
    v7 = CUtlMap<unsigned int,int,int>::Insert(
           this: &this->m_mapOrphanMessages,
           key: &eMsg,
           insert: (int)&jobIDTarget + 4);
  }
  ++this->m_mapOrphanMessages.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10015FA0
// Name: public: void GCSDK::CJobMgr::RemoveJob(class GCSDK::CJob __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::RemoveJob(GCSDK::CJobMgr *this, GCSDK::CJob *job)
{
  int m_JobID; // eax
  int v4; // eax
  int v5; // edi
  int v6; // eax
  unsigned __int64 v7; // rax
  CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF

  m_JobID = job->m_JobID;
  HIDWORD(search.key) = HIDWORD(job->m_JobID);
  LODWORD(search.key) = m_JobID;
  v4 = CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Find(
         this: &this->m_MapJob.m_Tree,
         &search);
  v5 = v4;
  if ( v4 != -1 )
  {
    CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Unlink(
      this: &this->m_MapJob.m_Tree,
      elem: v4);
    v6 = v5;
    this->m_MapJob.m_Tree.m_Elements.m_pMemory[v6].m_Left = v5;
    this->m_MapJob.m_Tree.m_Elements.m_pMemory[v6].m_Right = this->m_MapJob.m_Tree.m_FirstFree;
    --this->m_MapJob.m_Tree.m_NumElements;
    this->m_MapJob.m_Tree.m_FirstFree = v5;
  }
  GCSDK::CJobMgr::AccumulateStatsofJob(this, job);
  ++this->m_JobStats.m_cJobsTotal;
  if ( (*(_BYTE *)&job->m_flags.m_bits & 1) != 0 )
    ++this->m_JobStats.m_cJobsFailed;
  v7 = GCSDK::CJobTime::CServerMicroSecsPassed(this: &job->m_STimeStarted);
  *((_DWORD *)&search.elem + 1) = HIDWORD(v7) & 0x80000000;
  search.elem = nullptr;
  this->m_JobStats.m_flSumJobTimeMicrosec = this->m_JobStats.m_flSumJobTimeMicrosec + (double)v7;
  this->m_JobStats.m_flSumSqJobTimeMicrosec = (double)v7 * (double)v7 + this->m_JobStats.m_flSumSqJobTimeMicrosec;
  if ( v7 > this->m_JobStats.m_unMaxJobTimeMicrosec )
    this->m_JobStats.m_unMaxJobTimeMicrosec = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10016090
// Name: public: void GCSDK::CJobMgr::PassMsgToJob(class GCSDK::CJob __near &,class GCSDK::CNetPacket __near *,struct GCSDK::JobMsgInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::PassMsgToJob(
        GCSDK::CJobMgr *this,
        GCSDK::CJob *job,
        GCSDK::CNetPacket *pNetPacket,
        const GCSDK::JobMsgInfo_t *jobMsgInfo)
{
  int m_JobID_high; // edx
  unsigned int m_nCurrentYieldIterationRegPri; // eax
  GCSDK::CJobMgr::JobYielding_t src; // [esp+8h] [ebp-10h] BYREF

  if ( job->m_ePauseReason == k_EJobPauseReasonNetworkMsg )
  {
    GCSDK::CJob::AddPacketToList(this: job, pNetPacket, gidJobIDSrc: jobMsgInfo->m_JobIDSource);
    GCSDK::CJob::EndPause(this: job, eExpectedState: k_EJobPauseReasonNetworkMsg);
    m_JobID_high = HIDWORD(job->m_JobID);
    m_nCurrentYieldIterationRegPri = this->m_nCurrentYieldIterationRegPri;
    LODWORD(src.m_JobID) = job->m_JobID;
    HIDWORD(src.m_JobID) = m_JobID_high;
    src.m_nIteration = m_nCurrentYieldIterationRegPri;
    CUtlLinkedList<GCSDK::CJobMgr::JobYielding_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobYielding_t,int>,int>>::AddToTail(
      this: &this->m_ListJobsYieldingRegPri,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100160F0
// Name: private: void GCSDK::CJobMgr::CheckForJobTimeouts(class CLimitTimer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::CheckForJobTimeouts(GCSDK::CJobMgr *this, CLimitTimer *limitTimer)
{
  GCSDK::CJobMgr *v2; // ebx
  int v3; // eax
  bool v4; // zf
  CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int> > *p_m_ListJobTimeouts; // esi
  GCSDK::CJobTime *v6; // edi
  int m_lTime_high; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // edi
  int v12; // eax
  int m_Head; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // edx
  GCSDK::CJob *elem; // eax
  int m_lTime; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // edi
  GCSDK::CJob *v24; // ecx
  GCSDK::EJobPauseReason m_ePauseReason; // eax
  int v26; // ebx
  int v27; // ecx
  int m_Tail; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // edi
  int v34; // eax
  int v35; // edi
  CUtlMap<unsigned __int64,int,int>::Node_t v36; // [esp+4h] [ebp-64h] BYREF
  CUtlMap<unsigned __int64,int,int>::Node_t v37; // [esp+14h] [ebp-54h] BYREF
  CUtlMap<unsigned __int64,int,int>::Node_t v38; // [esp+24h] [ebp-44h] BYREF
  CUtlMap<unsigned __int64,int,int>::Node_t v39; // [esp+34h] [ebp-34h] BYREF
  CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t search; // [esp+44h] [ebp-24h] BYREF
  unsigned __int64 v41; // [esp+54h] [ebp-14h] BYREF
  int cIter; // [esp+5Ch] [ebp-Ch]
  GCSDK::CJob *pJob; // [esp+60h] [ebp-8h]
  GCSDK::CJobMgr *v44; // [esp+64h] [ebp-4h]

  v2 = this;
  v3 = 0;
  v4 = this->m_ListJobTimeouts.m_Head == -1;
  v44 = this;
  if ( !v4 )
  {
    while ( 1 )
    {
      cIter = v3 + 1;
      if ( v3 + 1 > 1 )
      {
        pJob = (GCSDK::CJob *)&v41;
        v41 = __rdtsc();
        if ( v41 >= limitTimer->m_lCycleLimit )
          break;
      }
      p_m_ListJobTimeouts = &v2->m_ListJobTimeouts;
      v6 = (GCSDK::CJobTime *)&v2->m_ListJobTimeouts.m_Memory.m_pMemory[v2->m_ListJobTimeouts.m_Head];
      if ( GCSDK::CJobTime::CServerMicroSecsPassed(this: v6 + 2) < 10000000 )
        break;
      m_lTime_high = HIDWORD(v6->m_lTime);
      LODWORD(search.key) = v6->m_lTime;
      HIDWORD(search.key) = m_lTime_high;
      v8 = CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Find(
             this: &v2->m_MapJob.m_Tree,
             &search);
      if ( v8 == -1 )
      {
        v9 = HIDWORD(v6->m_lTime);
        LODWORD(v39.key) = v6->m_lTime;
        HIDWORD(v39.key) = v9;
        v10 = CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::Find(
                this: &v2->m_MapJobTimeoutsIndexByJobID.m_Tree,
                search: &v39);
        v11 = v10;
        if ( v10 != -1 )
        {
          CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::Unlink(
            this: &v2->m_MapJobTimeoutsIndexByJobID.m_Tree,
            elem: v10);
          v12 = v11;
          v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory[v12].m_Left = v11;
          v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory[v12].m_Right = v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_FirstFree;
          --v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_NumElements;
          v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_FirstFree = v11;
        }
        m_Head = v44->m_ListJobTimeouts.m_Head;
        if ( m_Head >= 0
          && m_Head < v2->m_ListJobTimeouts.m_Memory.m_nAllocationCount
          && m_Head <= v2->m_ListJobTimeouts.m_LastAlloc.index )
        {
          v14 = (int)&p_m_ListJobTimeouts->m_Memory.m_pMemory[m_Head];
          if ( *(_DWORD *)(v14 + 32) != m_Head )
          {
            v15 = *(_DWORD *)(v14 + 32);
            if ( v15 == -1 )
              v2->m_ListJobTimeouts.m_Head = *(_DWORD *)(v14 + 36);
            else
              p_m_ListJobTimeouts->m_Memory.m_pMemory[v15].m_Next = *(_DWORD *)(v14 + 36);
            v16 = *(_DWORD *)(v14 + 36);
            if ( v16 == -1 )
              v2->m_ListJobTimeouts.m_Tail = *(_DWORD *)(v14 + 32);
            else
              p_m_ListJobTimeouts->m_Memory.m_pMemory[v16].m_Previous = *(_DWORD *)(v14 + 32);
            *(_DWORD *)(v14 + 36) = m_Head;
            *(_DWORD *)(v14 + 32) = m_Head;
            --v2->m_ListJobTimeouts.m_ElementCount;
          }
        }
        v2->m_ListJobTimeouts.m_Memory.m_pMemory[m_Head].m_Next = v2->m_ListJobTimeouts.m_FirstFree;
        v2->m_ListJobTimeouts.m_FirstFree = m_Head;
      }
      else
      {
        elem = v2->m_MapJob.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
        m_lTime = elem->m_STimeSwitched.m_lTime;
        pJob = elem;
        if ( m_lTime == LODWORD(v6[1].m_lTime) && HIDWORD(elem->m_STimeSwitched.m_lTime) == HIDWORD(v6[1].m_lTime) )
        {
          --LODWORD(v6[3].m_lTime);
          GCSDK::CJob::Heartbeat(this: elem);
          if ( LODWORD(v6[3].m_lTime) != 0 )
          {
            GCSDK::CJobTime::SetToJobTime(this: v6 + 2);
            v26 = v2->m_ListJobTimeouts.m_Head;
            CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::Unlink(
              this: p_m_ListJobTimeouts,
              elem: v26);
            v27 = (int)&p_m_ListJobTimeouts->m_Memory.m_pMemory[v26];
            *(_DWORD *)(v27 + 36) = -1;
            m_Tail = p_m_ListJobTimeouts->m_Tail;
            *(_DWORD *)(v27 + 32) = m_Tail;
            p_m_ListJobTimeouts->m_Tail = v26;
            if ( m_Tail == -1 )
              p_m_ListJobTimeouts->m_Head = v26;
            else
              p_m_ListJobTimeouts->m_Memory.m_pMemory[m_Tail].m_Next = v26;
            ++p_m_ListJobTimeouts->m_ElementCount;
            v29 = HIDWORD(v6->m_lTime);
            LODWORD(v37.key) = v6->m_lTime;
            HIDWORD(v37.key) = v29;
            v30 = CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::Find(
                    this: &v44->m_MapJobTimeoutsIndexByJobID.m_Tree,
                    search: &v37);
            if ( v30 != -1 )
              v44->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory[v30].m_Data.elem = v44->m_ListJobTimeouts.m_Tail;
          }
          else
          {
            v19 = HIDWORD(v6->m_lTime);
            LODWORD(v38.key) = v6->m_lTime;
            HIDWORD(v38.key) = v19;
            v20 = CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::Find(
                    this: &v2->m_MapJobTimeoutsIndexByJobID.m_Tree,
                    search: &v38);
            v21 = v20;
            if ( v20 != -1 )
            {
              CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::Unlink(
                this: &v2->m_MapJobTimeoutsIndexByJobID.m_Tree,
                elem: v20);
              v22 = v21;
              v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory[v22].m_Left = v21;
              v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory[v22].m_Right = v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_FirstFree;
              --v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_NumElements;
              v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_FirstFree = v21;
            }
            v23 = v44->m_ListJobTimeouts.m_Head;
            CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::Unlink(
              this: &v2->m_ListJobTimeouts,
              elem: v23);
            v2->m_ListJobTimeouts.m_Memory.m_pMemory[v23].m_Next = v2->m_ListJobTimeouts.m_FirstFree;
            v24 = pJob;
            v2->m_ListJobTimeouts.m_FirstFree = v23;
            m_ePauseReason = v24->m_ePauseReason;
            if ( m_ePauseReason != k_EJobPauseReasonWaitingForLock
              && m_ePauseReason != k_EJobPauseReasonSleepForTime
              && m_ePauseReason != k_EJobPauseReasonYield
              && m_ePauseReason != k_EJobPauseReasonSQL )
            {
              GCSDK::CJobMgr::TimeoutJob(this: v44, job: v24);
            }
          }
        }
        else
        {
          if ( (((unsigned __int64)GCSDK::CJobTime::CServerMicroSecsPassed(this: &elem->m_STimeNextHeartbeat) >> 32)
              & 0x80000000) == 0LL )
            GCSDK::CJob::Heartbeat(this: pJob);
          v31 = HIDWORD(v6->m_lTime);
          LODWORD(v36.key) = v6->m_lTime;
          HIDWORD(v36.key) = v31;
          v32 = CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::Find(
                  this: &v2->m_MapJobTimeoutsIndexByJobID.m_Tree,
                  search: &v36);
          v33 = v32;
          if ( v32 != -1 )
          {
            CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::Unlink(
              this: &v2->m_MapJobTimeoutsIndexByJobID.m_Tree,
              elem: v32);
            v34 = v33;
            v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory[v34].m_Left = v33;
            v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory[v34].m_Right = v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_FirstFree;
            --v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_NumElements;
            v2->m_MapJobTimeoutsIndexByJobID.m_Tree.m_FirstFree = v33;
          }
          v35 = v44->m_ListJobTimeouts.m_Head;
          CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::Unlink(
            this: &v2->m_ListJobTimeouts,
            elem: v35);
          p_m_ListJobTimeouts->m_Memory.m_pMemory[v35].m_Next = v2->m_ListJobTimeouts.m_FirstFree;
          v2->m_ListJobTimeouts.m_FirstFree = v35;
        }
      }
      if ( v44->m_ListJobTimeouts.m_Head == -1 )
        break;
      v3 = cIter;
      v2 = v44;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016480
// Name: private: void GCSDK::CJobMgr::PauseJob(class GCSDK::CJob __near &,enum GCSDK::EJobPauseReason)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobMgr::PauseJob(
        GCSDK::CJobMgr *this,
        GCSDK::CJob *job,
        GCSDK::EJobPauseReason eJobPauseReason)
{
  GCSDK::CJob *v3; // esi
  int m_JobID; // eax
  int v6; // eax
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *v7; // edi
  int m_Tail; // ecx
  int m_JobID_high; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int> *m_pMemory; // ecx
  int v11; // eax
  int elem; // edi
  CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int> > *p_m_ListJobTimeouts; // esi
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *v14; // ecx
  int v15; // eax
  int v16; // ebx
  UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int> *v17; // edx
  int v18; // eax
  CUtlMap<unsigned __int64,int,int>::Node_t search; // [esp+Ch] [ebp-14h] BYREF
  int *iListIndex; // [esp+1Ch] [ebp-4h]

  v3 = job;
  m_JobID = job->m_JobID;
  HIDWORD(search.key) = HIDWORD(job->m_JobID);
  LODWORD(search.key) = m_JobID;
  iListIndex = (int *)&this->m_MapJobTimeoutsIndexByJobID;
  v6 = CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::Find(
         this: &this->m_MapJobTimeoutsIndexByJobID.m_Tree,
         &search);
  if ( v6 == -1 )
  {
    v7 = &this->m_ListJobTimeouts.m_Memory.m_pMemory[CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::AddToTail(this: &this->m_ListJobTimeouts)];
    m_Tail = this->m_ListJobTimeouts.m_Tail;
    m_JobID_high = HIDWORD(job->m_JobID);
    LODWORD(search.key) = job->m_JobID;
    search.elem = m_Tail;
    HIDWORD(search.key) = m_JobID_high;
    CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>>::Insert(
      this: (CUtlRBTree<CUtlMap<unsigned __int64,int,int>::Node_t,int,CUtlMap<unsigned __int64,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int> > *)iListIndex,
      insert: &search);
  }
  else
  {
    m_pMemory = this->m_MapJobTimeoutsIndexByJobID.m_Tree.m_Elements.m_pMemory;
    v11 = v6;
    elem = m_pMemory[v11].m_Data.elem;
    p_m_ListJobTimeouts = &this->m_ListJobTimeouts;
    iListIndex = &m_pMemory[v11].m_Data.elem;
    CUtlLinkedList<GCSDK::CJobMgr::JobTimeout_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CJobMgr::JobTimeout_t,int>,int>>::Unlink(
      this: &this->m_ListJobTimeouts,
      elem);
    v14 = &this->m_ListJobTimeouts.m_Memory.m_pMemory[elem];
    v14->m_Next = -1;
    v15 = this->m_ListJobTimeouts.m_Tail;
    v14->m_Previous = v15;
    this->m_ListJobTimeouts.m_Tail = elem;
    if ( v15 == -1 )
      this->m_ListJobTimeouts.m_Head = elem;
    else
      p_m_ListJobTimeouts->m_Memory.m_pMemory[v15].m_Next = elem;
    ++this->m_ListJobTimeouts.m_ElementCount;
    v16 = this->m_ListJobTimeouts.m_Tail;
    *iListIndex = v16;
    v17 = p_m_ListJobTimeouts->m_Memory.m_pMemory;
    v3 = job;
    v7 = &v17[v16];
  }
  LODWORD(v7->m_Element.m_JobID) = v3->m_JobID;
  HIDWORD(v7->m_Element.m_JobID) = HIDWORD(v3->m_JobID);
  GCSDK::CJobTime::SetToJobTime(this: &v7->m_Element.m_STimePaused);
  GCSDK::CJobTime::SetToJobTime(this: &v7->m_Element.m_STimeTouched);
  v18 = v3->CHeartbeatsBeforeTimeout(this: v3);
  v7->m_Element.m_cHeartbeatsBeforeTimeout = v18;
  if ( v18 == 0 )
    v7->m_Element.m_cHeartbeatsBeforeTimeout = 2;
  GCSDK::CJob::Pause(this: v3, eReason: eJobPauseReason);
}

//------------------------------------------------------------------------------
// Address: 0x10016590
// Name: public: bool GCSDK::CJobMgr::BFrameFuncRunSleepingJobs(class CLimitTimer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CJobMgr::BFrameFuncRunSleepingJobs(GCSDK::CJobMgr *this, CLimitTimer *limitTimer)
{
  DWORD CurrentThreadId; // eax
  bool v4; // bl

  CurrentThreadId = GetCurrentThreadId();
  if ( this->m_unFrameFuncThreadID == 0 )
    this->m_unFrameFuncThreadID = CurrentThreadId;
  v4 = GCSDK::CJobMgr::BResumeSleepingJobs(this, limitTimer);
  GCSDK::CJobMgr::CheckForJobTimeouts(this, limitTimer);
  this->m_JobStats.m_cJobsCurrent = this->m_MapJob.m_Tree.m_NumElements;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100165E0
// Name: public: bool GCSDK::CJobMgr::BRouteMsgToJob(void __near *,class GCSDK::CNetPacket __near *,struct GCSDK::JobMsgInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CJobMgr::BRouteMsgToJob(
        GCSDK::CJobMgr *this,
        void *pParent,
        GCSDK::CNetPacket *pNetPacket,
        GCSDK::JobMsgInfo_t *jobMsgInfo)
{
  int m_JobIDTarget_high; // edx
  int v6; // eax
  char v8; // bl
  CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t search; // [esp+8h] [ebp-10h] BYREF

  if ( (HIDWORD(jobMsgInfo->m_JobIDTarget) & jobMsgInfo->m_JobIDTarget) != -1 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CJobMgr::BRouteMsgToJob() - continue job",
      a3: 0,
      a4: "Jobs/Coroutines",
      a5: false,
      a6: 4);
    m_JobIDTarget_high = HIDWORD(jobMsgInfo->m_JobIDTarget);
    LODWORD(search.key) = jobMsgInfo->m_JobIDTarget;
    HIDWORD(search.key) = m_JobIDTarget_high;
    v6 = CUtlRBTree<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int,CUtlMap<unsigned __int64,GCSDK::CJob *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,GCSDK::CJob *,int>::Node_t,int>,int>>::Find(
           this: &this->m_MapJob.m_Tree,
           &search);
    if ( v6 != -1 )
    {
      GCSDK::CJobMgr::PassMsgToJob(
        this,
        job: this->m_MapJob.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem,
        pNetPacket,
        jobMsgInfo);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 1;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CJobMgr::BRouteMsgToJob() - job",
    a3: 0,
    a4: "Jobs/Coroutines",
    a5: false,
    a6: 4);
  v8 = GCSDK::CJobMgr::BLaunchJobFromNetworkMsg(this, pParent, (GCSDK::JobType_t *)jobMsgInfo, pNetPacket);
  if ( v8 != 0 || (HIDWORD(jobMsgInfo->m_JobIDTarget) & jobMsgInfo->m_JobIDTarget) == -1 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return v8;
  }
  else
  {
    GCSDK::CJobMgr::RecordOrphanedMessage(this, eMsg: jobMsgInfo->m_eMsg, jobIDTarget: jobMsgInfo->m_JobIDTarget);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100166F0
// Name: public: bool GCSDK::CJobMgr::BYieldingWaitForMsg(class GCSDK::CJob __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GCSDK::CJobMgr::BYieldingWaitForMsg(GCSDK::CJobMgr *this, GCSDK::CJob *job)
{
  GCSDK::CJobMgr::PauseJob(this, job, eJobPauseReason: k_EJobPauseReasonNetworkMsg);
  return !this->m_bJobTimedOut;
}

//------------------------------------------------------------------------------
// Address: 0x10016720
// Name: public: bool GCSDK::CJobMgr::BYieldingWaitTime(class GCSDK::CJob __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CJobMgr::BYieldingWaitTime(
        GCSDK::CJobMgr *this,
        GCSDK::CJob *job,
        unsigned int cMicrosecondsToSleep)
{
  int m_JobID; // eax
  GCSDK::CJobMgr::JobSleeping_t jobSleeping; // [esp+8h] [ebp-18h] BYREF

  GCSDK::CJobTime::CJobTime(this: &jobSleeping.m_SWakeupTime);
  GCSDK::CJobTime::CJobTime(this: &jobSleeping.m_STimeTouched);
  m_JobID = job->m_JobID;
  HIDWORD(jobSleeping.m_JobID) = HIDWORD(job->m_JobID);
  LODWORD(jobSleeping.m_JobID) = m_JobID;
  GCSDK::CJobTime::SetFromJobTime(this: &jobSleeping.m_SWakeupTime, dMicroSecOffset: cMicrosecondsToSleep);
  GCSDK::CJobTime::SetToJobTime(this: &jobSleeping.m_STimeTouched);
  CUtlPriorityQueue<GCSDK::CJobMgr::JobSleeping_t,CDefUtlPriorityQueueLessFunc<GCSDK::CJobMgr::JobSleeping_t>,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int>>::Insert(
    this: &this->m_QueueJobSleeping,
    element: &jobSleeping);
  GCSDK::CJobMgr::PauseJob(this, job, eJobPauseReason: k_EJobPauseReasonSleepForTime);
  return !this->m_bJobTimedOut;
}

//------------------------------------------------------------------------------
// Address: 0x10026A30
// Name: protected: unsigned int CUtlLinkedList<class GCSDK::CSharedObjectCache __near *,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class GCSDK::CSharedObjectCache __near *,unsigned int>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::AllocInternal(
        CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int> > *this,
        bool multilist)
{
  int result; // eax
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x10027820
// Name: public: void CUtlLinkedList<class GCSDK::CSharedObjectCache __near *,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class GCSDK::CSharedObjectCache __near *,unsigned int>,unsigned int>>::Unlink(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::Unlink(
        CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int> > *this,
        int elem)
{
  UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int> *v2; // eax
  unsigned int m_Next; // edx
  unsigned int m_Previous; // edi
  unsigned int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027C20
// Name: public: unsigned int CUtlLinkedList<class GCSDK::CSharedObjectCache __near *,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<class GCSDK::CSharedObjectCache __near *,unsigned int>,unsigned int>>::AddToTail(class GCSDK::CSharedObjectCache __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::AddToTail(
        CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int> > *this,
        GCSDK::CSharedObjectCache **src)
{
  int result; // eax
  unsigned int v4; // edi
  UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int> *m_pMemory; // eax
  unsigned int v6; // ecx
  unsigned int m_Tail; // edx
  UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int> *v8; // esi

  result = CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::Unlink(
      this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}
