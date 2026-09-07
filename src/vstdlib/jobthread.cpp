// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/jobthread.cpp
// Functions: 79
// ============================================================

#include "vstdlib\jobthread.h"

//------------------------------------------------------------------------------
// Address: 0x10007A90
// Name: public: struct CTSQueue<class CFunctorCallback __near *,0,1>::Node_t __near * CTSQueue<class CFunctorCallback __near *,0,1>::Push(struct CTSQueue<class CFunctorCallback __near *,0,1>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *__thiscall CTSQueue<CFunctorCallback *,0,1>::Push(
        CTSQueue<CEventQueue::QueuedEvent_t,0,1> *this,
        CTSQueue<CJob *,0,1>::Node_t *pNode)
{
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *v3; // edi
  int i; // [esp-4h] [ebp-10h]

  pNode->pNext = (CTSQueue<CJob *,0,1>::Node_t *)this;
  v3 = this->m_Tail.value.pNode;
  for ( i = this->m_Tail.value.sequence;
        (CTSQueue<CEventQueue::QueuedEvent_t,0,1> *)_InterlockedCompareExchange(
                                                      (volatile signed __int32 *)v3,
                                                      (signed __int32)pNode,
                                                      (signed __int32)this) != this;
        i = this->m_Tail.value.sequence )
  {
    _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: v3->pNext, a3: i + 1, a4: v3, a5: i);
    v3 = this->m_Tail.value.pNode;
  }
  _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: pNode, a3: i + 1, a4: v3, a5: i);
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10008B30
// Name: public: virtual void IThreadPool::AddFunctor(class CFunctor __near *,class CJob __near * __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IThreadPool::AddFunctor(
        IThreadPool *this,
        CFunctor *pFunctor,
        CJob **ppJob,
        const char *pszDescription,
        unsigned int flags)
{
  pFunctor->AddRef(this: pFunctor);
  this->AddFunctorInternal(this, a2: pFunctor, a3: ppJob, a4: pszDescription, a5: flags);
}

//------------------------------------------------------------------------------
// Address: 0x10008B90
// Name: _DestroyThreadPool
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyThreadPool(IThreadPool *pPool)
{
  if ( pPool != nullptr )
    ((void (__thiscall *)(IThreadPool *, int))pPool->dtr_IThreadPool)(a1: pPool, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10008BB0
// Name: public: virtual void CThreadPool::Yield(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadPool::Yield(CThreadPool *this, unsigned int timeout)
{
  _ThreadInMainThread(a1: this);
  _ThreadSleep(a1: timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10008C40
// Name: public: int CJob::Execute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Execute(CJob *this)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int (__thiscall *DoExecute)(CJob *); // edx
  int v6; // eax
  int m_status; // ebx

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        DoExecute = this->DoExecute;
        this->m_status = 2;
        v6 = DoExecute(this);
        this->m_status = v6;
        m_status = v6;
        this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008D10
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008DE0
// Name: public: virtual int CThreadPool::NumThreads(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadPool::NumThreads(CThreadPool *this)
{
  return this->m_Threads.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10008DF0
// Name: public: virtual int CThreadPool::NumIdleThreads(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadPool::NumIdleThreads(CThreadPool *this)
{
  return this->m_nIdleThreads.m_value;
}

//------------------------------------------------------------------------------
// Address: 0x10008E00
// Name: public: CTSQueue<class CFunctorCallback __near *,0,1>::CTSQueue<class CFunctorCallback __near *,0,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CFunctorCallback *,0,1> *__thiscall CTSQueue<CFunctorCallback *,0,1>::CTSQueue<CFunctorCallback *,0,1>(
        CTSQueue<CFunctorCallback *,0,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<CFunctorCallback *,0,1>::Node_t *v3; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  p_m_FreeNodes->m_Head.value32.DepthAndSequence = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&this->m_Count.m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v3 = (CTSQueue<CFunctorCallback *,0,1>::Node_t *)operator new(nSize: 8u);
  this->m_Tail.value.pNode = v3;
  this->m_Head.value.pNode = v3;
  v3->pNext = (CTSQueue<CFunctorCallback *,0,1>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008E90
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x10008EA0
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10008EB0
// Name: protected: virtual bool CRefCountServiceBase<1,class CRefMT>::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRefCountServiceBase<1,CRefMT>::OnFinalRelease(ConCommand *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008EC0
// Name: public: CFunctorJob::CFunctorJob(class CFunctor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFunctorJob *__thiscall CFunctorJob::CFunctorJob(CFunctorJob *this, CFunctor *pFunctor, char *pszDescription)
{
  this->m_iRefs = 1;
  this->m_priority = JP_NORMAL;
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CFunctorJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctorJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pFunctor.m_pObject = pFunctor;
  if ( pszDescription != nullptr )
    V_strncpy(pDest: this->m_szDescription, pSrc: pszDescription, maxLen: 16);
  else
    this->m_szDescription[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008F70
// Name: public: virtual int CFunctorJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFunctorJob::DoExecute(CFunctorJob *this)
{
  this->m_pFunctor.m_pObject->operator()(this: this->m_pFunctor.m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008FC0
// Name: public: virtual int CThreadPool::SuspendExecution(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadPool::SuspendExecution(CThreadPool *this)
{
  CThreadFastMutex *p_m_SuspendMutex; // ebx
  DWORD CurrentThreadId; // ecx
  int i; // edi
  int j; // edi
  int v6; // edi
  int result; // eax
  CThreadFastMutex *generated_id_2; // [esp+Ch] [ebp-4h]

  p_m_SuspendMutex = &this->m_SuspendMutex;
  generated_id_2 = &this->m_SuspendMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_SuspendMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_SuspendMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_SuspendMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_SuspendMutex->m_depth;
  }
  if ( this->m_nSuspend == 0 )
  {
    for ( i = 0; i < this->m_Threads.m_Size; ++i )
      CWorkerThread::CallWorker(this: this->m_Threads.m_Memory.m_pMemory[i], a2: 1u, a3: 0, a4: true);
    for ( j = 0; j < this->m_Threads.m_Size; ++j )
      CWorkerThread::WaitForReply(this: this->m_Threads.m_Memory.m_pMemory[j], a2: 0xFFFFFFFF);
    v6 = 0;
    if ( this->m_Threads.m_Size > 0 )
    {
      do
      {
        while ( CThreadEvent::Check(this: &this->m_Threads.m_Memory.m_pMemory[v6]->m_NotSuspendedEvent) )
          _ThreadSleep(a1: 0);
        ++v6;
      }
      while ( v6 < this->m_Threads.m_Size );
      p_m_SuspendMutex = generated_id_2;
    }
  }
  result = this->m_nSuspend;
  this->m_nSuspend = result + 1;
  if ( p_m_SuspendMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_SuspendMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100090E0
// Name: public: virtual int CThreadPool::ResumeExecution(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadPool::ResumeExecution(CThreadPool *this)
{
  CThreadFastMutex *p_m_SuspendMutex; // ebx
  DWORD CurrentThreadId; // ecx
  int result; // eax
  int v5; // edi
  int v7; // [esp+Ch] [ebp-4h]

  p_m_SuspendMutex = &this->m_SuspendMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_SuspendMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_SuspendMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_SuspendMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_SuspendMutex->m_depth;
  }
  result = this->m_nSuspend;
  v7 = result;
  this->m_nSuspend = result - 1;
  if ( result == 1 )
  {
    v5 = 0;
    if ( this->m_Threads.m_Size > 0 )
    {
      do
        CThread::Resume(this: this->m_Threads.m_Memory.m_pMemory[v5++]);
      while ( v5 < this->m_Threads.m_Size );
      result = v7;
    }
  }
  if ( p_m_SuspendMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_SuspendMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009170
// Name: public: virtual int CThreadPool::YieldWaitPerFrameJobs(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadPool::YieldWaitPerFrameJobs(CThreadPool *this)
{
  DWORD CurrentThreadId; // eax
  CThreadPool *v2; // esi
  CThreadFastMutex *p_m_PerFrameJobListMutex; // edi
  int m_Size; // esi
  void *v5; // esp
  CThreadPool *v6; // ecx
  bool v7; // zf
  int v8; // edi
  _DWORD v10[3]; // [esp+0h] [ebp-14h] BYREF
  int nRetVal; // [esp+Ch] [ebp-8h]
  CThreadPool *v12; // [esp+10h] [ebp-4h]

  v12 = this;
  nRetVal = 0;
  while ( 1 )
  {
    CurrentThreadId = GetCurrentThreadId();
    v2 = v12;
    p_m_PerFrameJobListMutex = &v12->m_PerFrameJobListMutex;
    if ( CurrentThreadId != v12->m_PerFrameJobListMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_PerFrameJobListMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_PerFrameJobListMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++p_m_PerFrameJobListMutex->m_depth;
    }
    m_Size = v2->m_PerFrameJobs.m_Size;
    if ( m_Size == 0 )
      break;
    v5 = alloca(4 * m_Size);
    memcpy(
      dst: (unsigned __int8 *)v10,
      src: (unsigned __int8 *)v12->m_PerFrameJobs.m_Memory.m_pMemory,
      count: 4 * m_Size);
    v6 = v12;
    v12->m_PerFrameJobs.m_Size = 0;
    v7 = p_m_PerFrameJobListMutex->m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_PerFrameJobListMutex, 0);
    v8 = 0;
    for ( nRetVal = v6->YieldWait(this: v6, a2: (CJob **)v10, a3: m_Size, a4: true, a5: -1u); v8 < m_Size; ++v8 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v10[v8] + 4))(a1: v10[v8]);
  }
  v7 = p_m_PerFrameJobListMutex->m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_PerFrameJobListMutex, 0);
  return nRetVal;
}

//------------------------------------------------------------------------------
// Address: 0x10009260
// Name: public: virtual void CThreadPool::AddFunctorInternal(class CFunctor __near *,class CJob __near * __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadPool::AddFunctorInternal(
        CThreadPool *this,
        CFunctor *pFunctor,
        CJob **ppJob,
        const char *pszDescription,
        unsigned __int8 flags)
{
  CFunctorJob *v6; // eax
  CFunctorJob *v7; // esi

  v6 = (CFunctorJob *)operator new(nSize: 0x44u);
  if ( v6 != nullptr )
    v7 = CFunctorJob::CFunctorJob(this: v6, pFunctor, pszDescription);
  else
    v7 = nullptr;
  v7->m_flags = flags;
  this->AddJob(this, a2: v7);
  if ( ppJob != nullptr )
    *ppJob = v7;
  else
    v7->Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100092C0
// Name: public: virtual void CThreadPool::Distribute(bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadPool::Distribute(CThreadPool *this, signed int bDistribute, int *pAffinityTable)
{
  bool v4; // cc
  HMODULE LibraryA; // eax
  HMODULE v6; // ebx
  DWORD (__stdcall *SetThreadIdealProcessor)(HANDLE, DWORD); // edi
  void *CurrentHandle; // eax
  int v9; // ebx
  int j; // edi
  int m_nLogicalProcessors; // ecx
  struct ThreadHandle_t__ *v12; // eax
  int i; // edi
  struct ThreadHandle_t__ *ThreadHandle; // eax
  HANDLE CurrentProcess; // eax
  int k; // edi
  struct ThreadHandle_t__ *v17; // eax
  int v18; // [esp-4h] [ebp-18h]
  signed int v19; // [esp-4h] [ebp-18h]
  unsigned int (__stdcall *Thread_SetIdealProcessor)(ThreadHandle_t__ *, unsigned int); // [esp+Ch] [ebp-8h]
  const CPUInformation *ci; // [esp+10h] [ebp-4h]

  if ( (_BYTE)bDistribute != 0 )
  {
    ci = (const CPUInformation *)_GetCPUInformation();
    v4 = ci->m_nLogicalProcessors <= 1u;
    bDistribute = (*((char *)ci + 4) < 0) + 1;
    if ( !v4 )
    {
      if ( pAffinityTable != nullptr )
      {
        for ( i = 0; i < this->m_Threads.m_Size; ++i )
        {
          v18 = pAffinityTable[i];
          ThreadHandle = CThread::GetThreadHandle(this: this->m_Threads.m_Memory.m_pMemory[i]);
          _ThreadSetAffinity(a1: ThreadHandle, a2: v18);
        }
      }
      else
      {
        LibraryA = LoadLibraryA(lpLibFileName: "kernel32.dll");
        v6 = LibraryA;
        pAffinityTable = (int *)LibraryA;
        if ( LibraryA != nullptr )
        {
          SetThreadIdealProcessor = (DWORD (__stdcall *)(HANDLE, DWORD))GetProcAddress(
                                                                          hModule: LibraryA,
                                                                          lpProcName: "SetThreadIdealProcessor");
          Thread_SetIdealProcessor = (unsigned int (__stdcall *)(ThreadHandle_t__ *, unsigned int))SetThreadIdealProcessor;
          if ( SetThreadIdealProcessor != nullptr )
          {
            CurrentHandle = (void *)_ThreadGetCurrentHandle();
            SetThreadIdealProcessor(hThread: CurrentHandle, dwIdealProcessor: 0);
            v9 = 0;
            for ( j = 0; v9 < this->m_Threads.m_Size; ++v9 )
            {
              m_nLogicalProcessors = ci->m_nLogicalProcessors;
              j += bDistribute;
              if ( j >= m_nLogicalProcessors )
              {
                j %= m_nLogicalProcessors;
                if ( bDistribute > 1 )
                  j = (j + 1) % bDistribute;
              }
              v12 = CThread::GetThreadHandle(this: this->m_Threads.m_Memory.m_pMemory[v9]);
              ((void (__stdcall *)(struct ThreadHandle_t__ *))Thread_SetIdealProcessor)(a1: v12);
            }
            v6 = (HMODULE)pAffinityTable;
          }
          FreeLibrary(hLibModule: v6);
        }
      }
    }
  }
  else
  {
    CurrentProcess = GetCurrentProcess();
    if ( GetProcessAffinityMask(
           hProcess: CurrentProcess,
           lpProcessAffinityMask: (PDWORD_PTR)&bDistribute,
           lpSystemAffinityMask: (PDWORD_PTR)&pAffinityTable) )
    {
      for ( k = 0; k < this->m_Threads.m_Size; ++k )
      {
        v19 = bDistribute;
        v17 = CThread::GetThreadHandle(this: this->m_Threads.m_Memory.m_pMemory[k]);
        _ThreadSetAffinity(a1: v17, a2: v19);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009450
// Name: _CThreadPool::GetDummyJob_::_2_::CDummyJob::CDummyJob
// Source: json
//------------------------------------------------------------------------------
void __usercall CThreadPool::GetDummyJob_::_2_::CDummyJob::CDummyJob(
        CThreadPool::GetDummyJob::__l2::CDummyJob *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)(a2 + 8) = 1;
  *(_DWORD *)a2 = &CJob::`vftable'{for `IRefCounted'};
  *(_DWORD *)(a2 + 4) = &CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  *(_DWORD *)(a2 + 12) = 4;
  *(_DWORD *)(a2 + 16) = 1;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_BYTE *)(a2 + 29) = -1;
  *(_DWORD *)(a2 + 32) = -1;
  *(_BYTE *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  CThreadEvent::CThreadEvent(this: (CThreadEvent *)(a2 + 40), a2: true);
  *(_DWORD *)a2 = `CThreadPool::GetDummyJob'::`2'::CDummyJob::`vftable';
  *(_DWORD *)(a2 + 4) = &`CThreadPool::GetDummyJob'::`2'::CDummyJob::`vftable';
  CJob::Execute(this: (CJob *)a2);
}

//------------------------------------------------------------------------------
// Address: 0x10009570
// Name: public: virtual int ThreadPoolTest::CCountJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ThreadPoolTest::CCountJob::DoExecute(ThreadPoolTest::CCountJob *this)
{
  int i; // esi
  int j; // esi
  unsigned __int8 pMemory[1024]; // [esp+4h] [ebp-400h] BYREF

  _InterlockedExchangeAdd(&ThreadPoolTest::CCountJob::m_nCount.m_value, 1u);
  _mm_pause();
  if ( ThreadPoolTest::g_iSleep >= 0 )
    _ThreadSleep(a1: ThreadPoolTest::g_iSleep);
  if ( this->bDoWork )
  {
    for ( i = 0; i < 1024; ++i )
      pMemory[i] = rand();
    for ( j = 50; j != 0; --j )
    {
      HashBlock(pKey: pMemory, size: 0x400u);
      HashBlock(pKey: pMemory, size: 0x400u);
    }
    this->bDoWork = false;
  }
  if ( ThreadPoolTest::CCountJob::m_nCount.m_value == ThreadPoolTest::g_nTotalToComplete )
    CThreadEvent::Set(this: &ThreadPoolTest::g_done);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100096A0
// Name: public: virtual int ThreadPoolTest::CExecuteTestJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ThreadPoolTest::CExecuteTestJob::DoExecute(ThreadPoolTest::CExecuteTestJob *this)
{
  int i; // esi
  int j; // esi
  int m_status; // eax
  unsigned __int8 pMemory[1024]; // [esp+8h] [ebp-400h] BYREF

  for ( i = 0; i < 1024; ++i )
    pMemory[i] = rand();
  for ( j = 50; j != 0; --j )
  {
    HashBlock(pKey: pMemory, size: 0x400u);
    HashBlock(pKey: pMemory, size: 0x400u);
  }
  if ( (CThreadEvent::Check(this: &this->m_CompleteEvent)
     || (m_status = this->m_status) != 1 && m_status != 2 && m_status != 4)
    && !ThreadPoolTest::g_bOutputError )
  {
    _Msg(a1: "Forced execute test failed!\n");
    if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
      __debugbreak();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009740
// Name: public: virtual int ThreadPoolTest::CExecuteTestExecuteJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ThreadPoolTest::CExecuteTestExecuteJob::DoExecute(ThreadPoolTest::CExecuteTestExecuteJob *this)
{
  bool v2; // al
  ThreadPoolTest::CExecuteTestJob *m_pTestJob; // ecx

  v2 = RandomInt(iMinVal: 1, iMaxVal: 10) == 1;
  _InterlockedExchangeAdd(&ThreadPoolTest::g_nReady.m_value, 1u);
  while ( ThreadPoolTest::g_ReadyToExecute == 0 )
    _mm_pause();
  m_pTestJob = this->m_pTestJob;
  if ( v2 )
    CJob::Abort(this: m_pTestJob, bDiscard: true);
  else
    CJob::Execute(this: m_pTestJob);
  _InterlockedExchangeAdd(&ThreadPoolTest::g_nReady.m_value, 0xFFFFFFFF);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100097B0
// Name: public: struct CTSQueue<class CJob __near *,0,1>::Node_t __near * CTSQueue<class CJob __near *,0,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CFunctorCallback *,0,1>::Node_t *__thiscall CTSQueue<CJob *,0,1>::Pop(CTSQueue<CFunctorCallback *,0,1> *this)
{
  CTSQueue<CFunctorCallback *,0,1> *v1; // esi
  CTSQueue<CFunctorCallback *,0,1> *pNext; // eax
  CFunctorCallback *sequence; // edi
  CTSQueue<CFunctorCallback *,0,1>::Node_t *pNode; // [esp-Ch] [ebp-2Ch]
  CTSQueue<CFunctorCallback *,0,1>::NodeLink_t *head_4; // [esp+4h] [ebp-1Ch]
  int *pHead; // [esp+Ch] [ebp-14h]
  CTSQueue<CFunctorCallback *,0,1>::NodeLink_t *pTailNode; // [esp+10h] [ebp-10h]

  v1 = this;
  pTailNode = &this->m_Tail;
  pHead = &this->m_Head.value.sequence;
  head_4 = &this->m_Tail;
  while ( 1 )
  {
    do
    {
      while ( 1 )
      {
        do
        {
          pNode = v1->m_Head.value.pNode;
          pNext = (CTSQueue<CFunctorCallback *,0,1> *)v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( pNode != head_4->value.pNode )
          break;
        if ( pNext == v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: pTailNode->value.sequence + 1,
          a4: pNode,
          a5: pTailNode->value.sequence);
      }
    }
    while ( pNext == v1 );
    sequence = (CFunctorCallback *)pNext->m_Head.value.sequence;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNext, a3: *pHead + 1, a4: pNode, a5: *pHead) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  pNode->elem = sequence;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x100098B0
// Name: private: virtual class CJob __near * CThreadPool::GetDummyJob(void)
// Source: json
//------------------------------------------------------------------------------
CThreadPool::GetDummyJob::__l2::CDummyJob *__thiscall CThreadPool::GetDummyJob(CThreadPool *this)
{
  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    CThreadPool::GetDummyJob_::_2_::CDummyJob::CDummyJob(
      (CThreadPool::GetDummyJob::__l2::CDummyJob *)this,
      a2: (int)&dummyJob);
    atexit(func: CThreadPool::GetDummyJob_::_3_::_dynamic_atexit_destructor_for__dummyJob__);
  }
  _InterlockedExchangeAdd(&dummyJob.m_iRefs, 1u);
  return &dummyJob;
}

//------------------------------------------------------------------------------
// Address: 0x100098F0
// Name: void ThreadPoolTest::Test(bool,bool,bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadPoolTest::Test(
        bool bDistribute,
        bool bSleep,
        bool bFinishExecute,
        bool bDoWork,
        bool bIncludeMain,
        bool bPrioritized)
{
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  int v8; // ebx
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // ebx
  bool *p_bDoWork; // esi
  int v13; // ebx
  char *p_m_iServicingThread; // eax
  int j; // edx
  char v16; // cl
  char v17; // cl
  char v18; // cl
  char v19; // cl
  long double v20; // xmm2_8
  int v21; // esi
  ThreadPoolStartParams_t params; // [esp+64h] [ebp-1A8h] BYREF
  unsigned __int64 v23; // [esp+178h] [ebp-94h]
  unsigned __int64 v24; // [esp+180h] [ebp-8Ch]
  unsigned __int64 v25; // [esp+188h] [ebp-84h]
  unsigned __int64 v26; // [esp+190h] [ebp-7Ch]
  double m_Int64; // [esp+198h] [ebp-74h]
  CFastTimer *p_suspendTimer; // [esp+1A0h] [ebp-6Ch]
  __int64 *v29; // [esp+1A4h] [ebp-68h]
  CFastTimer *p_timer; // [esp+1A8h] [ebp-64h]
  CThreadEvent *pEvent; // [esp+1ACh] [ebp-60h] BYREF
  __int64 *v32; // [esp+1B0h] [ebp-5Ch]
  ThreeState_t v33; // [esp+1B4h] [ebp-58h]
  BOOL v34; // [esp+1B8h] [ebp-54h]
  __int64 v35; // [esp+1BCh] [ebp-50h] BYREF
  __int64 v36; // [esp+1C4h] [ebp-48h] BYREF
  int counts[9]; // [esp+1CCh] [ebp-40h] BYREF
  ThreadPoolTest::CCountJob *jobs; // [esp+1F0h] [ebp-1Ch]
  int i; // [esp+1F4h] [ebp-18h]
  int bInterleavePushPop; // [esp+1F8h] [ebp-14h]
  CFastTimer timer; // [esp+1FCh] [ebp-10h] BYREF
  CFastTimer suspendTimer; // [esp+204h] [ebp-8h] BYREF

  v6 = operator new(nSize: 0x32C84u);
  if ( v6 != nullptr )
  {
    v7 = v6 + 1;
    *v6 = 4000;
    i = (int)(v6 + 1);
    v8 = 3999;
    v9 = v6 + 7;
    do
    {
      *(v9 - 4) = 1;
      *v7 = &CJob::`vftable'{for `IRefCounted'};
      *(v9 - 5) = &CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *(v9 - 3) = 4;
      *(v9 - 2) = 1;
      *(v9 - 1) = 0;
      *v9 = 0;
      v9[3] = 0;
      *((_WORD *)v9 + 2) = -256;
      v9[2] = -1;
      CThreadEvent::CThreadEvent(this: (CThreadEvent *)v9 + 2, a2: true);
      *v7 = &ThreadPoolTest::CCountJob::`vftable'{for `IRefCounted'};
      *(v9 - 5) = &ThreadPoolTest::CCountJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v7 += 13;
      v9 += 13;
      --v8;
    }
    while ( v8 >= 0 );
    jobs = (ThreadPoolTest::CCountJob *)i;
  }
  else
  {
    jobs = nullptr;
  }
  bInterleavePushPop = 0;
  v34 = bPrioritized;
  p_suspendTimer = &suspendTimer;
  p_timer = &timer;
  v33 = bDistribute;
  v29 = &v36;
  v32 = &v35;
  do
  {
    v10 = -10;
    ThreadPoolTest::g_iSleep = -10;
    do
    {
      _Msg(
        a1: "ThreadPoolTest:         Testing! Sleep %d, interleave %d, prioritized %d \n",
        v10,
        bInterleavePushPop,
        v34);
      i = 1;
      do
      {
        _InterlockedExchange(&ThreadPoolTest::CCountJob::m_nCount.m_value, 0);
        v11 = 0;
        ThreadPoolTest::g_nTotalAtFinish = 0;
        params.nStackSize = -1;
        params.iThreadPriority = -32768;
        *((_BYTE *)&params + 272) &= 0xFCu;
        if ( (*((_BYTE *)&params + 272) & 2) != 0 )
          qmemcpy(params.iAffinityTable, nullptr, sizeof(params.iAffinityTable));
        params.fDistribute = v33;
        params.nThreads = i;
        ThreadPoolTest::g_pTestThreadPool->Start(this: ThreadPoolTest::g_pTestThreadPool, a2: &params, a3: "Tst");
        if ( bInterleavePushPop == 0 )
          ThreadPoolTest::g_pTestThreadPool->SuspendExecution(this: ThreadPoolTest::g_pTestThreadPool);
        timer.m_Duration.m_Int64 = 0;
        ThreadPoolTest::g_nTotalToComplete = 4000;
        suspendTimer.m_Duration.m_Int64 = 0;
        p_suspendTimer->m_Duration.m_Int64 = __rdtsc();
        p_timer->m_Duration.m_Int64 = __rdtsc();
        p_bDoWork = &jobs->bDoWork;
        do
        {
          *(p_bDoWork - 20) = 8;
          *p_bDoWork = bDoWork;
          if ( bPrioritized )
            *((_DWORD *)p_bDoWork - 8) = RandomInt(iMinVal: 0, iMaxVal: 3);
          ThreadPoolTest::g_pTestThreadPool->AddJob(
            this: ThreadPoolTest::g_pTestThreadPool,
            a2: (CJob *)(p_bDoWork - 48));
          if ( bSleep && (v11 & 0xF) == 0 )
            _ThreadSleep(a1: 0);
          ++v11;
          p_bDoWork += 52;
        }
        while ( v11 < 4000 );
        if ( bInterleavePushPop == 0 )
          ThreadPoolTest::g_pTestThreadPool->ResumeExecution(this: ThreadPoolTest::g_pTestThreadPool);
        if ( bFinishExecute && ThreadPoolTest::g_iSleep <= 1 )
        {
          if ( bDoWork && bIncludeMain )
          {
            do
            {
              if ( ThreadPoolTest::g_pTestThreadPool->GetJobCount(this: ThreadPoolTest::g_pTestThreadPool) == 0 )
                break;
              v13 = ThreadPoolTest::g_pTestThreadPool->NumIdleThreads(this: ThreadPoolTest::g_pTestThreadPool);
            }
            while ( v13 == ThreadPoolTest::g_pTestThreadPool->NumIdleThreads(this: ThreadPoolTest::g_pTestThreadPool) );
            pEvent = &ThreadPoolTest::g_done;
            ThreadPoolTest::g_pTestThreadPool->YieldWait_2(
              this: ThreadPoolTest::g_pTestThreadPool,
              a2: &pEvent,
              a3: 1,
              a4: true,
              a5: -1u);
          }
          else
          {
            CThreadEvent::Wait(this: &ThreadPoolTest::g_done, a2: 0xFFFFFFFF);
          }
        }
        ThreadPoolTest::g_nTotalAtFinish = ThreadPoolTest::CCountJob::m_nCount.m_value;
        v36 = 0;
        *v29 = __rdtsc();
        timer.m_Duration.m_Int64 = v36 - timer.m_Duration.m_Int64;
        ThreadPoolTest::g_pTestThreadPool->SuspendExecution(this: ThreadPoolTest::g_pTestThreadPool);
        v35 = 0;
        *v32 = __rdtsc();
        suspendTimer.m_Duration.m_Int64 = v35 - suspendTimer.m_Duration.m_Int64;
        ThreadPoolTest::g_pTestThreadPool->ResumeExecution(this: ThreadPoolTest::g_pTestThreadPool);
        ThreadPoolTest::g_pTestThreadPool->Stop(this: ThreadPoolTest::g_pTestThreadPool, a2: -1);
        CThreadEvent::Reset(this: &ThreadPoolTest::g_done);
        memset(counts, 0, sizeof(counts));
        p_m_iServicingThread = &jobs->m_iServicingThread;
        for ( j = 800; j != 0; --j )
        {
          if ( *p_m_iServicingThread == -1 )
          {
            if ( *(_DWORD *)(p_m_iServicingThread - 17) == 0 )
              ++counts[0];
          }
          else
          {
            ++counts[*p_m_iServicingThread + 1];
            *p_m_iServicingThread = -1;
          }
          v16 = p_m_iServicingThread[52];
          if ( v16 == -1 )
          {
            if ( *(_DWORD *)(p_m_iServicingThread + 35) == 0 )
              ++counts[0];
          }
          else
          {
            ++counts[v16 + 1];
            p_m_iServicingThread[52] = -1;
          }
          v17 = p_m_iServicingThread[104];
          if ( v17 == -1 )
          {
            if ( *(_DWORD *)(p_m_iServicingThread + 87) == 0 )
              ++counts[0];
          }
          else
          {
            ++counts[v17 + 1];
            p_m_iServicingThread[104] = -1;
          }
          v18 = p_m_iServicingThread[156];
          if ( v18 == -1 )
          {
            if ( *(_DWORD *)(p_m_iServicingThread + 139) == 0 )
              ++counts[0];
          }
          else
          {
            ++counts[v18 + 1];
            p_m_iServicingThread[156] = -1;
          }
          v19 = p_m_iServicingThread[208];
          if ( v19 == -1 )
          {
            if ( *(_DWORD *)(p_m_iServicingThread + 191) == 0 )
              ++counts[0];
          }
          else
          {
            ++counts[v19 + 1];
            p_m_iServicingThread[208] = -1;
          }
          p_m_iServicingThread += 260;
        }
        v26 = suspendTimer.m_Duration.m_Int64 & 0x7FFFFFFFFFFFFFFFLL;
        v25 = suspendTimer.m_Duration.m_Int64 & 0x8000000000000000uLL;
        v24 = timer.m_Duration.m_Int64 & 0x7FFFFFFFFFFFFFFFLL;
        v23 = timer.m_Duration.m_Int64 & 0x8000000000000000uLL;
        m_Int64 = (double)suspendTimer.m_Duration.m_Int64;
        v20 = m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
        v21 = i;
        m_Int64 = (double)timer.m_Duration.m_Int64;
        _Msg(
          a1: "ThreadPoolTest:         %d threads -- %d (%d) jobs processed in %fms, %fms to suspend (%f/%f) [ (main) %d, %d,"
          " %d, %d, %d, %d, %d, %d, %d]\n",
          i,
          ThreadPoolTest::g_nTotalAtFinish,
          ThreadPoolTest::CCountJob::m_nCount.m_value,
          (double)(m_Int64 * _g_ClockSpeedMillisecondsMultiplier),
          (double)(v20 - m_Int64 * _g_ClockSpeedMillisecondsMultiplier),
          (double)(m_Int64 * _g_ClockSpeedMillisecondsMultiplier / (float)ThreadPoolTest::CCountJob::m_nCount.m_value),
          (double)((double)suspendTimer.m_Duration.m_Int64
                 * _g_ClockSpeedMillisecondsMultiplier
                 / (float)ThreadPoolTest::g_nTotalAtFinish),
          counts[0],
          counts[1],
          counts[2],
          counts[3],
          counts[4],
          counts[5],
          counts[6],
          counts[7],
          counts[8]);
        i = v21 + 2;
      }
      while ( v21 + 2 <= 8 );
      v10 = ThreadPoolTest::g_iSleep + 10;
      ThreadPoolTest::g_iSleep = v10;
    }
    while ( v10 <= 10 );
    ++bInterleavePushPop;
  }
  while ( bInterleavePushPop < 2 );
  if ( jobs != nullptr )
  {
    if ( *(_DWORD *)&jobs[-1].bDoWork != 0 )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))jobs->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: &jobs->CRefCountServiceBase<1,CRefMT>,
        a2: 3);
    else
      free(pMem: &jobs[-1].bDoWork);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009EA0
// Name: void ThreadPoolTest::TestForcedExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadPoolTest::TestForcedExecute()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi
  int k; // edi
  ThreadPoolTest::CExecuteTestJob *v3; // edi
  volatile int v4; // esi
  CJob *v5; // esi
  ThreadPoolStartParams_t params; // [esp+Ch] [ebp-128h] BYREF
  int j; // [esp+120h] [ebp-14h]
  int n; // [esp+124h] [ebp-10h]
  ThreadPoolTest::CExecuteTestJob *jobs; // [esp+128h] [ebp-Ch]
  int m; // [esp+12Ch] [ebp-8h]
  int i; // [esp+130h] [ebp-4h]

  _Msg(a1: "TestForcedExecute\n");
  for ( j = 30; j != 0; --j )
  {
    i = 1;
    do
    {
      _InterlockedExchange(&ThreadPoolTest::g_nReady.m_value, 0);
      params.nStackSize = -1;
      params.iThreadPriority = -32768;
      *((_BYTE *)&params + 272) &= 0xFCu;
      if ( (*((_BYTE *)&params + 272) & 2) != 0 )
        qmemcpy(params.iAffinityTable, nullptr, sizeof(params.iAffinityTable));
      params.nThreads = i;
      params.fDistribute = TRS_TRUE;
      ThreadPoolTest::g_pTestThreadPool->Start(this: ThreadPoolTest::g_pTestThreadPool, a2: &params, a3: "Tst");
      v0 = operator new(nSize: 0x2EE04u);
      if ( v0 != nullptr )
      {
        v1 = v0 + 1;
        *v0 = 4000;
        m = (int)(v0 + 1);
        for ( k = 3999; k >= 0; --k )
        {
          v1[2] = 1;
          *v1 = &CJob::`vftable'{for `IRefCounted'};
          v1[1] = &CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v1[3] = 4;
          v1[4] = 1;
          v1[5] = 0;
          v1[6] = 0;
          *((_WORD *)v1 + 14) = -256;
          v1[8] = -1;
          v1[9] = 0;
          CThreadEvent::CThreadEvent(this: (CThreadEvent *)v1 + 5, a2: true);
          *v1 = &ThreadPoolTest::CExecuteTestJob::`vftable'{for `IRefCounted'};
          v1[1] = &ThreadPoolTest::CExecuteTestJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v1 += 12;
        }
        jobs = (ThreadPoolTest::CExecuteTestJob *)m;
      }
      else
      {
        jobs = nullptr;
      }
      v3 = jobs;
      for ( m = 4000; m != 0; --m )
      {
        v4 = i;
        ThreadPoolTest::g_ReadyToExecute = 0;
        if ( i > 0 )
        {
          for ( n = i; n != 0; --n )
          {
            v5 = (CJob *)operator new(nSize: 0x34u);
            if ( v5 != nullptr )
            {
              v5->m_iRefs = 1;
              v5->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
              v5->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
              v5->m_status = 4;
              v5->m_priority = JP_NORMAL;
              v5->m_mutex.m_ownerID = 0;
              v5->m_mutex.m_depth = 0;
              *(_WORD *)&v5->m_flags = -256;
              v5->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
              v5->m_pThreadPool = nullptr;
              CThreadEvent::CThreadEvent(this: &v5->m_CompleteEvent, a2: true);
              v5->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CJob_vtbl *)&ThreadPoolTest::CExecuteTestExecuteJob::`vftable'{for `IRefCounted'};
              v5->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&ThreadPoolTest::CExecuteTestExecuteJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
            }
            else
            {
              v5 = nullptr;
            }
            v5->m_flags = 8;
            v5[1].CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CJob_vtbl *)v3;
            ThreadPoolTest::g_pTestThreadPool->AddJob(this: ThreadPoolTest::g_pTestThreadPool, a2: v5);
            v5->Release(this: v5);
          }
          v4 = i;
        }
        while ( ThreadPoolTest::g_nReady.m_value < v4 )
          _mm_pause();
        ThreadPoolTest::g_ReadyToExecute = 1;
        _ThreadSleep(a1: 0);
        CJob::Execute(this: v3);
        while ( ThreadPoolTest::g_nReady.m_value > 0 )
          _mm_pause();
        ++v3;
      }
      ThreadPoolTest::g_pTestThreadPool->Stop(this: ThreadPoolTest::g_pTestThreadPool, a2: -1);
      if ( jobs != nullptr )
      {
        if ( *(_DWORD *)&jobs[-1].m_CompleteEvent.m_bCreatedHandle != 0 )
          ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))jobs->dtr_CRefCountServiceBase<1,CRefMT>)(
            a1: &jobs->CRefCountServiceBase<1,CRefMT>,
            a2: 3);
        else
          free(pMem: &jobs[-1].m_CompleteEvent.m_bCreatedHandle);
      }
      i = v4 + 2;
    }
    while ( v4 + 2 <= 5 );
  }
  _Msg(a1: "TestForcedExecute DONE\n");
}

//------------------------------------------------------------------------------
// Address: 0x1000A150
// Name: public: void CTSQueue<class CFunctorCallback __near *,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<CFunctorCallback *,0,1>::Purge(CTSQueue<CFunctorCallback *,0,1> *this)
{
  CTSQueue<CFunctorCallback *,0,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  for ( i = CTSQueue<CJob *,0,1>::Pop(this); i != nullptr; i = CTSQueue<CJob *,0,1>::Pop(this) )
    free(pMem: i);
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: p_m_FreeNodes,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    free(pMem: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A340
// Name: public: bool CJobQueue::Pop(class CJob __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CJobQueue::Pop(CJobQueue *this, CJob **ppJob)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  int m_nItems; // eax
  int v6; // eax
  bool v7; // zf
  CTSQueue<CFunctorCallback *,0,1> *v8; // edi
  CTSQueue<CFunctorCallback *,0,1>::Node_t *v9; // eax
  DWORD v10; // ecx
  int i; // [esp+Ch] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  m_nItems = this->m_nItems;
  if ( m_nItems == 0 )
    goto LABEL_21;
  v6 = m_nItems - 1;
  this->m_nItems = v6;
  if ( v6 == 0 )
    CThreadEvent::Reset(this: &this->m_JobAvailableEvent);
  v7 = p_m_mutex->m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  i = 3;
  if ( CJobQueue::m_MinPriority > 3 )
  {
LABEL_14:
    v10 = GetCurrentThreadId();
    if ( v10 != p_m_mutex->m_ownerID && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, v10, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: v10, a3: 0);
    }
    else
    {
      ++p_m_mutex->m_depth;
    }
    if ( ++this->m_nItems == 1 )
    {
      CThreadEvent::Set(this: &this->m_JobAvailableEvent);
      _ThreadSleep(a1: 0);
    }
LABEL_21:
    v7 = p_m_mutex->m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    *ppJob = nullptr;
    return 0;
  }
  v8 = (CTSQueue<CFunctorCallback *,0,1> *)&this->m_queues[3];
  while ( 1 )
  {
    v9 = CTSQueue<CJob *,0,1>::Pop(this: v8);
    if ( v9 != nullptr )
      break;
    --v8;
    if ( --i < CJobQueue::m_MinPriority )
      goto LABEL_14;
  }
  *ppJob = (CJob *)v9->elem;
  CTSListBase::Push(this: &v8->m_FreeNodes, pNode: (TSLNodeBase_t *)v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A480
// Name: public: void CJobQueue::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJobQueue::Flush(CJobQueue *this)
{
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  CTSListBase *p_m_FreeNodes; // esi
  CTSQueue<CFunctorCallback *,0,1>::Node_t *v5; // eax
  _DWORD *p_pNext; // edi
  TSLNodeBase_t *Next; // [esp-8h] [ebp-20h]
  TSLNodeBase_t *v9; // [esp-8h] [ebp-20h]
  int DepthAndSequence; // [esp-4h] [ebp-1Ch]
  int v11; // [esp-4h] [ebp-1Ch]
  CThreadFastMutex *v12; // [esp+Ch] [ebp-Ch]
  CJob *pJob; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  v12 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  this->m_nItems = 0;
  CThreadEvent::Reset(this: &this->m_JobAvailableEvent);
  i = 3;
  p_m_FreeNodes = &this->m_queues[3].m_FreeNodes;
  do
  {
    while ( 1 )
    {
      v5 = CTSQueue<CJob *,0,1>::Pop(this: (CTSQueue<CFunctorCallback *,0,1> *)&p_m_FreeNodes[-3]);
      p_pNext = &v5->pNext;
      if ( v5 == nullptr )
        break;
      DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
      pJob = (CJob *)v5->elem;
      Next = p_m_FreeNodes->m_Head.value.Next;
      v5->pNext = (CTSQueue<CFunctorCallback *,0,1>::Node_t *)p_m_FreeNodes->m_Head.value.Next;
      if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                              a1: p_m_FreeNodes,
                              a2: v5,
                              a3: DepthAndSequence + 65537,
                              a4: Next,
                              a5: DepthAndSequence) == 0 )
      {
        do
        {
          _mm_pause();
          v11 = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
          v9 = p_m_FreeNodes->m_Head.value.Next;
          *p_pNext = p_m_FreeNodes->m_Head.value.Next;
        }
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                   a1: p_m_FreeNodes,
                                   a2: p_pNext,
                                   a3: v11 + 65537,
                                   a4: v9,
                                   a5: v11) == 0 );
      }
      CJob::Abort(this: pJob, bDiscard: true);
      pJob->Release(this: pJob);
    }
    p_m_FreeNodes -= 4;
    --i;
  }
  while ( i >= 0 );
  if ( v12->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v12, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000A570
// Name: public: virtual int CThreadPool::YieldWait(class CThreadEvent __near * __near *,int,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadPool::YieldWait(
        CThreadPool *this,
        CThreadEvent **pEvents,
        int nEvents,
        CJob *bWaitAll,
        unsigned int timeout)
{
  bool v5; // di
  unsigned int result; // eax
  volatile __int32 *v7; // esi
  int m_status; // eax
  DWORD CurrentThreadId; // eax
  int v10; // edx
  volatile __int32 *v11; // esi
  CJob *v12; // ecx

  v5 = (char)bWaitAll;
  for ( result = CThreadEvent::WaitForMultiple(a1: nEvents, a2: pEvents, a3: (bool)bWaitAll, a4: 0);
        result == 258;
        result = CThreadEvent::WaitForMultiple(a1: nEvents, a2: pEvents, a3: v5, a4: 0) )
  {
    if ( CJobQueue::Pop(this: &this->m_SharedQueue, ppJob: &bWaitAll) )
    {
      v7 = (volatile __int32 *)bWaitAll;
      m_status = bWaitAll->m_status;
      if ( m_status == 1 || m_status == 2 || m_status == 4 )
      {
        CurrentThreadId = GetCurrentThreadId();
        v10 = *((_DWORD *)v7 + 5);
        v11 = v7 + 5;
        if ( CurrentThreadId == v10 || _InterlockedCompareExchange(v11, CurrentThreadId, 0) == 0 )
        {
          ++*((_DWORD *)v11 + 1);
          v12 = bWaitAll;
          bWaitAll->m_iServicingThread = -1;
          CJob::Execute(this: v12);
          if ( (*((_DWORD *)v11 + 1))-- == 1 )
            _InterlockedExchange(v11, 0);
        }
        v7 = (volatile __int32 *)bWaitAll;
      }
      (*(void (__thiscall **)(volatile __int32 *))(*v7 + 4))(a1: v7);
      _InterlockedExchangeAdd(&this->m_nJobs.m_value, 0xFFFFFFFF);
    }
    else
    {
      _mm_pause();
      _ThreadSleep(a1: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A660
// Name: public: virtual int CThreadPool::AbortAll(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadPool::AbortAll(CThreadPool *this)
{
  CJob *v2; // edi
  int v3; // esi
  CJobThread *v4; // edi
  CJob *v5; // esi
  int i; // [esp+Ch] [ebp-Ch]
  int iAborted; // [esp+10h] [ebp-8h]
  CJob *pJob; // [esp+14h] [ebp-4h] BYREF

  this->SuspendExecution(this);
  for ( iAborted = 0; CJobQueue::Pop(this: &this->m_SharedQueue, ppJob: &pJob); ++iAborted )
  {
    v2 = pJob;
    CJob::Abort(this: pJob, bDiscard: true);
    v2->Release(this: v2);
  }
  v3 = 0;
  for ( i = 0; v3 < this->m_Threads.m_Size; i = v3 )
  {
    v4 = this->m_Threads.m_Memory.m_pMemory[v3];
    if ( CJobQueue::Pop(this: &v4->m_DirectQueue, ppJob: &pJob) )
    {
      do
      {
        v5 = pJob;
        CJob::Abort(this: pJob, bDiscard: true);
        v5->Release(this: v5);
        ++iAborted;
      }
      while ( CJobQueue::Pop(this: &v4->m_DirectQueue, ppJob: &pJob) );
      v3 = i;
    }
    ++v3;
  }
  _InterlockedExchange(&this->m_nJobs.m_value, 0);
  this->ResumeExecution(this);
  return iAborted;
}

//------------------------------------------------------------------------------
// Address: 0x1000A7C0
// Name: public: CJobQueue::CJobQueue(void)
// Source: json
//------------------------------------------------------------------------------
CJobQueue *__thiscall CJobQueue::CJobQueue(CJobQueue *this)
{
  CJobQueue *v2; // edi
  int i; // ebx

  v2 = this;
  for ( i = 3; i >= 0; --i )
  {
    CTSQueue<CFunctorCallback *,0,1>::CTSQueue<CFunctorCallback *,0,1>(this: (CTSQueue<CFunctorCallback *,0,1> *)v2);
    v2 = (CJobQueue *)((char *)v2 + 32);
  }
  this->m_nItems = 0;
  this->m_nMaxItems = 0x7FFFFFFF;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  CThreadEvent::CThreadEvent(this: &this->m_JobAvailableEvent, a2: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A810
// Name: public: int CJobQueue::Push(class CJob __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJobQueue::Push(CJobQueue *this, int pJob, int iThread)
{
  int v5; // eax
  DWORD CurrentThreadId; // eax
  CThreadFastMutex *v7; // esi
  bool v8; // zf
  CTSQueue<CEventQueue::QueuedEvent_t,0,1> *v9; // esi
  CTSQueue<CJob *,0,1>::Node_t *v10; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD v12; // eax
  CJob *ppJob; // [esp+10h] [ebp-4h] BYREF
  int nOverflow; // [esp+1Ch] [ebp+8h]

  (**(void (__thiscall ***)(int))pJob)(a1: pJob);
  nOverflow = 0;
  while ( this->m_nItems >= this->m_nMaxItems && CJobQueue::Pop(this, &ppJob) != 0 && ppJob != nullptr )
  {
    v5 = *(_DWORD *)(pJob + 12);
    if ( v5 == 1 || v5 == 2 || v5 == 4 )
    {
      CurrentThreadId = GetCurrentThreadId();
      v7 = (CThreadFastMutex *)(pJob + 20);
      if ( CurrentThreadId == *(_DWORD *)(pJob + 20)
        || _InterlockedCompareExchange((volatile signed __int32 *)v7, CurrentThreadId, 0) == 0 )
      {
        ++*(_DWORD *)(pJob + 24);
        *(_BYTE *)(pJob + 29) = -1;
        CJob::Execute(this: (CJob *)pJob);
        v8 = (*(_DWORD *)(pJob + 24))-- == 1;
        if ( v8 )
          _InterlockedExchange((volatile __int32 *)v7, 0);
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)pJob + 4))(a1: pJob);
    ++nOverflow;
  }
  v9 = (CTSQueue<CEventQueue::QueuedEvent_t,0,1> *)&this->m_queues[*(_DWORD *)(pJob + 16)];
  v10 = (CTSQueue<CJob *,0,1>::Node_t *)CTSListBase::Pop(this: &v9->m_FreeNodes);
  if ( v10 != nullptr )
  {
    v10->elem = (CJob *)pJob;
  }
  else
  {
    v10 = (CTSQueue<CJob *,0,1>::Node_t *)operator new(nSize: 8u);
    if ( v10 != nullptr )
      v10->elem = (CJob *)pJob;
    else
      v10 = nullptr;
  }
  CTSQueue<CFunctorCallback *,0,1>::Push(this: v9, pNode: v10);
  p_m_mutex = &this->m_mutex;
  v12 = GetCurrentThreadId();
  if ( v12 != this->m_mutex.m_ownerID && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, v12, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mutex, a2: v12, a3: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  if ( ++this->m_nItems == 1 )
    CThreadEvent::Set(this: &this->m_JobAvailableEvent);
  v8 = this->m_mutex.m_depth-- == 1;
  if ( v8 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  return nOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x1000A960
// Name: public: CJobQueue::~CJobQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJobQueue::~CJobQueue(CJobQueue *this)
{
  CTSQueue<CFunctorCallback *,0,1> *p_m_nItems; // esi
  int i; // edi

  CThreadSyncObject::~CThreadSyncObject(this: &this->m_JobAvailableEvent);
  p_m_nItems = (CTSQueue<CFunctorCallback *,0,1> *)&this->m_nItems;
  for ( i = 3; i >= 0; --i )
  {
    CTSQueue<CFunctorCallback *,0,1>::Purge(this: --p_m_nItems);
    free(pMem: p_m_nItems->m_Head.value.pNode);
    CTSListBase::Detach(this: &p_m_nItems->m_FreeNodes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A9B0
// Name: public: virtual bool CThreadPool::Start(struct ThreadPoolStartParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadPool::Start(CThreadPool *this, const ThreadPoolStartParams_t *startParams)
{
  return this->Start(this, a2: startParams, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000A9D0
// Name: public: virtual unsigned int CThreadPool::GetJobCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadPool::GetJobCount(CThreadPool *this)
{
  return this->m_nJobs.m_value;
}

//------------------------------------------------------------------------------
// Address: 0x1000A9E0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x1000A9F0
// Name: public: virtual int CRefCounted1<class IThreadPool,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA20
// Name: public: virtual void CThreadPool::AddPerFrameJob(class CJob __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadPool::AddPerFrameJob(CThreadPool *this, CJob *pJob)
{
  CThreadFastMutex *p_m_PerFrameJobListMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_PerFrameJobListMutex = &this->m_PerFrameJobListMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_PerFrameJobListMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_PerFrameJobListMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_PerFrameJobListMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_PerFrameJobListMutex->m_depth;
  }
  pJob->AddRef(this: pJob);
  CUtlVector<CJob *,CUtlMemoryFixedGrowable<CJob *,2048,int>>::InsertBefore(
    this: &this->m_PerFrameJobs,
    elem: this->m_PerFrameJobs.m_Size,
    src: &pJob);
  if ( p_m_PerFrameJobListMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_PerFrameJobListMutex, 0);
  this->AddJob(this, a2: pJob);
}

//------------------------------------------------------------------------------
// Address: 0x1000AAA0
// Name: public: void CThreadPool::InsertJobInQueue(class CJob __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadPool::InsertJobInQueue(CThreadPool *this, CJob *pJob)
{
  int m_iServicingThread; // eax
  CJobThread *v4; // ecx
  CJobQueue *p_m_DirectQueue; // ecx

  if ( (pJob->m_flags & 4) != 0 )
  {
    v4 = *this->m_Threads.m_Memory.m_pMemory;
    goto LABEL_7;
  }
  m_iServicingThread = pJob->m_iServicingThread;
  if ( m_iServicingThread >= 0 && m_iServicingThread < this->m_Threads.m_Size )
  {
    v4 = this->m_Threads.m_Memory.m_pMemory[m_iServicingThread];
LABEL_7:
    p_m_DirectQueue = &v4->m_DirectQueue;
    goto LABEL_8;
  }
  p_m_DirectQueue = &this->m_SharedQueue;
LABEL_8:
  _InterlockedExchangeAdd(&this->m_nJobs.m_value, -CJobQueue::Push(this: p_m_DirectQueue, pJob, iThread: -1));
}

//------------------------------------------------------------------------------
// Address: 0x1000AB00
// Name: public: virtual void CThreadPool::ChangePriority(class CJob __near *,enum JobPriority_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadPool::ChangePriority(CThreadPool *this, CJob *pJob, JobPriority_t priority)
{
  JobPriority_t m_priority; // eax

  m_priority = pJob->m_priority;
  if ( m_priority >= priority )
  {
    if ( _executeCount < 1 )
    {
      ++_executeCount;
      if ( m_priority != priority )
        DevMsg(a1: "CThreadPool::RemoveJob not implemented right now");
    }
  }
  else
  {
    pJob->m_priority = priority;
    CJobQueue::Push(this: &this->m_SharedQueue, pJob, iThread: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AB50
// Name: private: virtual int CJobThread::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJobThread::Run(CJobThread *this)
{
  CThreadEvent *v2; // eax
  CThreadPool *m_pOwner; // edx
  CThreadManualEvent *p_m_IdleEvent; // esi
  unsigned int v5; // eax
  CJob *v6; // esi
  int m_status; // eax
  int m_iThread; // ebx
  DWORD CurrentThreadId; // eax
  volatile unsigned int m_ownerID; // ecx
  CThreadFastMutex *p_m_mutex; // esi
  CJob *v12; // ecx
  bool v14; // al
  CThreadEvent *waitHandles[3]; // [esp+Ch] [ebp-1Ch] BYREF
  CThreadManualEvent *v17; // [esp+1Ch] [ebp-Ch]
  CJob *pJob; // [esp+20h] [ebp-8h] BYREF
  bool bTookJob; // [esp+27h] [ebp-1h]

  v2 = CWorkerThread::GetCallHandle(this);
  m_pOwner = this->m_pOwner;
  waitHandles[0] = v2;
  waitHandles[1] = &this->m_SharedQueue->m_JobAvailableEvent;
  waitHandles[2] = &this->m_DirectQueue.m_JobAvailableEvent;
  _InterlockedExchangeAdd(&m_pOwner->m_nIdleThreads.m_value, 1u);
  p_m_IdleEvent = &this->m_IdleEvent;
  v17 = &this->m_IdleEvent;
LABEL_2:
  CThreadEvent::Set(this: p_m_IdleEvent);
  while ( CThreadEvent::WaitForMultiple(a1: 3, a2: waitHandles, a3: false, a4: 0xFFFFFFFF) != -1 )
  {
    if ( CWorkerThread::PeekCall(this, a2: nullptr) )
    {
      v5 = CWorkerThread::GetCallParam(this);
      if ( v5 == 0 )
      {
        CWorkerThread::Reply(this, a2: 1u);
        break;
      }
      if ( v5 == 1 )
      {
        CWorkerThread::Reply(this, a2: 1u);
        CThread::Suspend(this);
      }
      else
      {
        CWorkerThread::Reply(this, a2: 0);
      }
    }
    else
    {
      bTookJob = false;
      do
      {
        if ( CJobQueue::Pop(this: &this->m_DirectQueue, ppJob: &pJob) == 0
          && CJobQueue::Pop(this: this->m_SharedQueue, ppJob: &pJob) == 0 )
        {
          break;
        }
        if ( !bTookJob )
        {
          CThreadEvent::Reset(this: p_m_IdleEvent);
          _InterlockedExchangeAdd(&this->m_pOwner->m_nIdleThreads.m_value, 0xFFFFFFFF);
          bTookJob = true;
        }
        v6 = pJob;
        m_status = pJob->m_status;
        m_iThread = this->m_iThread;
        if ( m_status == 1 || m_status == 2 || m_status == 4 )
        {
          CurrentThreadId = GetCurrentThreadId();
          m_ownerID = v6->m_mutex.m_ownerID;
          p_m_mutex = &v6->m_mutex;
          if ( CurrentThreadId == m_ownerID
            || _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) == 0 )
          {
            ++p_m_mutex->m_depth;
            v12 = pJob;
            pJob->m_iServicingThread = m_iThread;
            CJob::Execute(this: v12);
            if ( p_m_mutex->m_depth-- == 1 )
              _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
          }
          v6 = pJob;
        }
        v6->Release(this: v6);
        _InterlockedExchangeAdd(&this->m_pOwner->m_nJobs.m_value, 0xFFFFFFFF);
        v14 = CWorkerThread::PeekCall(this, a2: nullptr);
        p_m_IdleEvent = v17;
      }
      while ( !v14 );
      if ( bTookJob )
      {
        _InterlockedExchangeAdd(&this->m_pOwner->m_nIdleThreads.m_value, 1u);
        goto LABEL_2;
      }
    }
  }
  _InterlockedExchangeAdd(&this->m_pOwner->m_nIdleThreads.m_value, 0xFFFFFFFF);
  CThreadEvent::Reset(this: p_m_IdleEvent);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD80
// Name: public: CThreadPool::CThreadPool(void)
// Source: json
//------------------------------------------------------------------------------
CThreadPool *__thiscall CThreadPool::CThreadPool(CThreadPool *this)
{
  this->m_iRefs = 1;
  this->CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT> >::IThreadPool::IRefCounted::__vftable = (CThreadPool_vtbl *)&CThreadPool::`vftable'{for `IThreadPool'};
  this->CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CThreadPool::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  CJobQueue::CJobQueue(this: &this->m_SharedQueue);
  this->m_nIdleThreads.m_value = 0;
  this->m_Threads.m_Memory.m_pMemory = nullptr;
  this->m_Threads.m_Memory.m_nAllocationCount = 0;
  this->m_Threads.m_Memory.m_nGrowSize = 0;
  this->m_Threads.m_Size = 0;
  this->m_Threads.m_pElements = nullptr;
  this->m_SuspendMutex.m_ownerID = 0;
  this->m_SuspendMutex.m_depth = 0;
  this->m_nSuspend = 0;
  this->m_nJobs.m_value = 0;
  this->m_PerFrameJobListMutex.m_ownerID = 0;
  this->m_PerFrameJobListMutex.m_depth = 0;
  this->m_PerFrameJobs.m_Memory.m_nMallocGrowSize = 0;
  this->m_PerFrameJobs.m_Size = 0;
  this->m_PerFrameJobs.m_Memory.m_pMemory = this->m_PerFrameJobs.m_Memory.m_pFixedMemory;
  this->m_PerFrameJobs.m_Memory.m_nAllocationCount = 2048;
  this->m_PerFrameJobs.m_Memory.m_nGrowSize = -1;
  this->m_PerFrameJobs.m_pElements = this->m_PerFrameJobs.m_Memory.m_pFixedMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE20
// Name: public: virtual int CThreadPool::YieldWait(class CJob __near * __near *,int,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadPool::YieldWait(CThreadPool *this, CJob **ppJobs, int nJobs, BOOL bWaitAll, unsigned int timeout)
{
  int v6; // edx
  int m_Size; // ecx
  int v9; // ebx
  CJob *v10; // edi
  int v11; // esi
  CThreadEvent *p_m_CompleteEvent; // edi
  char *v13; // esi
  CUtlVectorFixed<CThreadEvent *,64> handles; // [esp+0h] [ebp-10Ch] BYREF
  CThreadPool *v15; // [esp+108h] [ebp-4h]

  handles.m_pElements = (CThreadEvent **)&handles;
  v6 = nJobs;
  m_Size = 0;
  v15 = this;
  handles.m_Size = 0;
  if ( nJobs > 62 )
    return -1;
  v9 = 0;
  if ( nJobs > 0 )
  {
    do
    {
      v10 = ppJobs[v9];
      v11 = m_Size++;
      handles.m_pElements = (CThreadEvent **)&handles;
      p_m_CompleteEvent = &v10->m_CompleteEvent;
      handles.m_Size = m_Size;
      if ( m_Size - v11 - 1 > 0 )
      {
        _V_memmove(
          dest: &handles.m_Memory.m_Memory[4 * v11 + 4],
          src: (char *)&handles + 4 * v11,
          count: 4 * (m_Size - v11 - 1));
        m_Size = handles.m_Size;
        v6 = nJobs;
      }
      v13 = &handles.m_Memory.m_Memory[4 * v11];
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = p_m_CompleteEvent;
        m_Size = handles.m_Size;
      }
      ++v9;
    }
    while ( v9 < v6 );
    this = v15;
  }
  return this->YieldWait_2(this, a2: (CThreadEvent **)&handles, a3: m_Size, a4: bWaitAll, a5: timeout);
}

//------------------------------------------------------------------------------
// Address: 0x1000AEE0
// Name: public: virtual void CThreadPool::AddJob(class CJob __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadPool::AddJob(CThreadPool *this, CJob *pJob)
{
  int m_status; // eax

  if ( pJob != nullptr )
  {
    if ( pJob->m_ThreadPoolData != (ThreadPoolData_t__ *)-1 )
    {
      _Warning(a1: "Cannot add a thread job already committed to another thread pool\n");
      return;
    }
    if ( this->m_Threads.m_Size == 0 )
      goto LABEL_5;
    if ( (pJob->m_flags & 9) == 0 )
    {
      if ( this->NumIdleThreads(this) == 0 )
      {
LABEL_5:
        CJob::Execute(this: pJob);
        return;
      }
      pJob->m_priority = JP_IMMEDIATE;
    }
    m_status = pJob->m_status;
    if ( m_status == 1 || m_status == 4 )
    {
      pJob->m_pThreadPool = this;
      pJob->m_status = 1;
      CThreadPool::InsertJobInQueue(this, pJob);
      _InterlockedExchangeAdd(&this->m_nJobs.m_value, 1u);
    }
    else if ( _executeCount_0 < 1 )
    {
      ++_executeCount_0;
      _Warning(a1: "Attempted to add job to job queue that has already been completed\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AF90
// Name: public: virtual int CThreadPool::ExecuteToPriority(enum JobPriority_t,bool (*)(class CJob __near *))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadPool::ExecuteToPriority(
        CThreadPool *this,
        JobPriority_t iToPriority,
        bool (__cdecl *pfnFilter)(CJob *))
{
  CThreadPool *v3; // esi
  int (__thiscall *SuspendExecution)(struct CThreadPool *); // edx
  unsigned int (__thiscall *GetJobCount)(struct CThreadPool *); // edx
  CJob **v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // ebx
  CInterlockedIntT<int> *p_m_Count; // ecx
  int v11; // eax
  CJobThread *v12; // edi
  int v13; // edx
  CJobQueue *p_m_DirectQueue; // edi
  volatile __int32 *v15; // esi
  int v16; // eax
  int m_nAllocationCount; // ebx
  CJob **m_pMemory; // esi
  int m_Size; // eax
  int v20; // edi
  int v21; // eax
  CJob **v22; // eax
  int v23; // eax
  DWORD CurrentThreadId; // eax
  int v25; // ecx
  volatile __int32 *v26; // esi
  CJob *v27; // ecx
  bool v28; // zf
  volatile __int32 *v29; // esi
  int v30; // eax
  int v31; // edi
  CJob **v32; // esi
  int v33; // eax
  int v34; // ebx
  int v35; // eax
  CJob **v36; // esi
  int v37; // eax
  DWORD v38; // eax
  int v39; // ecx
  volatile __int32 *v40; // esi
  CJob *v41; // ecx
  int v42; // esi
  CJob *v43; // eax
  int m_iServicingThread; // ecx
  CJobThread *v45; // ecx
  CJobQueue *p_m_SharedQueue; // ecx
  int v47; // eax
  unsigned int v49; // [esp-4h] [ebp-54h]
  unsigned int v50; // [esp-4h] [ebp-54h]
  CUtlVector<CJob *,CUtlMemory<CJob *,int> > jobsToPutBack; // [esp+Ch] [ebp-44h] BYREF
  char *v52; // [esp+24h] [ebp-2Ch]
  char *v53; // [esp+28h] [ebp-28h]
  int v54; // [esp+2Ch] [ebp-24h]
  int v55; // [esp+30h] [ebp-20h]
  int v56; // [esp+34h] [ebp-1Ch]
  int nJobsTotal; // [esp+38h] [ebp-18h]
  int i; // [esp+3Ch] [ebp-14h]
  CJobQueue *queue; // [esp+40h] [ebp-10h]
  CInterlockedIntT<int> *v60; // [esp+44h] [ebp-Ch]
  int nExecuted; // [esp+48h] [ebp-8h]
  CThreadPool *v62; // [esp+4Ch] [ebp-4h]

  v3 = this;
  SuspendExecution = this->SuspendExecution;
  v62 = this;
  ((void (__fastcall *)(CThreadPool *))SuspendExecution)(a1: this);
  GetJobCount = v3->GetJobCount;
  v6 = nullptr;
  nExecuted = 0;
  nJobsTotal = GetJobCount(this: v3);
  v7 = 0;
  memset(&jobsToPutBack, 0, sizeof(jobsToPutBack));
  if ( iToPriority <= JP_IMMEDIATE )
  {
    v8 = -16 - (_DWORD)v3;
    v9 = -32 - (_DWORD)v3;
    p_m_Count = &v3->m_SharedQueue.m_queues[3].m_Count;
    v60 = &v3->m_SharedQueue.m_queues[3].m_Count;
    v55 = -16 - (_DWORD)v3;
    v54 = -32 - (_DWORD)v3;
    v56 = 4 - iToPriority;
    while ( 1 )
    {
      v11 = 0;
      i = 0;
      if ( v3->m_Threads.m_Size > 0 )
      {
        v53 = (char *)p_m_Count + v8;
        v52 = (char *)p_m_Count + v9;
        do
        {
          v12 = v3->m_Threads.m_Memory.m_pMemory[v11];
          v13 = *(int *)((char *)&v12->m_DirectQueue.m_queues[0].m_Head.value.pNode + (_DWORD)v53);
          p_m_DirectQueue = &v12->m_DirectQueue;
          queue = p_m_DirectQueue;
          if ( v13 != 0 )
          {
            do
            {
              CJobQueue::Pop(this: p_m_DirectQueue, ppJob: (CJob **)&iToPriority);
              v15 = (volatile __int32 *)iToPriority;
              if ( pfnFilter == nullptr || pfnFilter(a1: (CJob *)iToPriority) )
              {
                v23 = *((_DWORD *)v15 + 3);
                if ( v23 == 1 || v23 == 2 || v23 == 4 )
                {
                  CurrentThreadId = GetCurrentThreadId();
                  v25 = *((_DWORD *)v15 + 5);
                  v26 = v15 + 5;
                  if ( CurrentThreadId == v25 || _InterlockedCompareExchange(v26, CurrentThreadId, 0) == 0 )
                  {
                    ++*((_DWORD *)v26 + 1);
                    v27 = (CJob *)iToPriority;
                    *(_BYTE *)(iToPriority + 29) = -1;
                    CJob::Execute(this: v27);
                    v28 = (*((_DWORD *)v26 + 1))-- == 1;
                    if ( v28 )
                      _InterlockedExchange(v26, 0);
                  }
                  v15 = (volatile __int32 *)iToPriority;
                }
                (*(void (__thiscall **)(volatile __int32 *))(*v15 + 4))(a1: v15);
                _InterlockedExchangeAdd(&v62->m_nJobs.m_value, 0xFFFFFFFF);
                ++nExecuted;
              }
              else
              {
                v16 = *((_DWORD *)v15 + 3);
                if ( v16 == 1 || v16 == 4 )
                {
                  m_nAllocationCount = jobsToPutBack.m_Memory.m_nAllocationCount;
                  if ( jobsToPutBack.m_Memory.m_nAllocationCount >= nJobsTotal || jobsToPutBack.m_Memory.m_nGrowSize < 0 )
                  {
                    m_pMemory = jobsToPutBack.m_Memory.m_pMemory;
                  }
                  else
                  {
                    m_nAllocationCount = nJobsTotal;
                    jobsToPutBack.m_Memory.m_nAllocationCount = nJobsTotal;
                    v49 = 4 * nJobsTotal;
                    if ( jobsToPutBack.m_Memory.m_pMemory != nullptr )
                      m_pMemory = (CJob **)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: jobsToPutBack.m_Memory.m_pMemory,
                                             a3: v49);
                    else
                      m_pMemory = (CJob **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v49);
                    jobsToPutBack.m_Memory.m_pMemory = m_pMemory;
                  }
                  m_Size = jobsToPutBack.m_Size;
                  jobsToPutBack.m_pElements = m_pMemory;
                  v20 = jobsToPutBack.m_Size;
                  if ( jobsToPutBack.m_Size + 1 > m_nAllocationCount )
                  {
                    CUtlMemory<int,int>::Grow(
                      this: (CUtlMemory<CCoroutineMgr *,int> *)&jobsToPutBack,
                      num: jobsToPutBack.m_Size - m_nAllocationCount + 1);
                    m_Size = jobsToPutBack.m_Size;
                    m_pMemory = jobsToPutBack.m_Memory.m_pMemory;
                  }
                  jobsToPutBack.m_Size = m_Size + 1;
                  v21 = m_Size - v20;
                  jobsToPutBack.m_pElements = m_pMemory;
                  if ( v21 > 0 )
                    _V_memmove(dest: &m_pMemory[v20 + 1], src: &m_pMemory[v20], count: 4 * v21);
                  v22 = &m_pMemory[v20];
                  p_m_DirectQueue = queue;
                  if ( v22 != nullptr )
                    *v22 = (CJob *)iToPriority;
                }
                else
                {
                  _InterlockedExchangeAdd(&v62->m_nJobs.m_value, 0xFFFFFFFF);
                  (*(void (__thiscall **)(volatile __int32 *))(*v15 + 4))(a1: v15);
                }
              }
            }
            while ( *(volatile int *)((char *)&p_m_DirectQueue->m_queues[0].m_Count.m_value + (_DWORD)v52) != 0 );
            v3 = v62;
            v11 = i;
            p_m_Count = v60;
          }
          i = ++v11;
        }
        while ( v11 < v3->m_Threads.m_Size );
      }
      if ( p_m_Count->m_value != 0 )
      {
        do
        {
          CJobQueue::Pop(this: &v3->m_SharedQueue, ppJob: (CJob **)&iToPriority);
          v29 = (volatile __int32 *)iToPriority;
          if ( pfnFilter == nullptr || pfnFilter(a1: (CJob *)iToPriority) )
          {
            v37 = *((_DWORD *)v29 + 3);
            if ( v37 == 1 || v37 == 2 || v37 == 4 )
            {
              v38 = GetCurrentThreadId();
              v39 = *((_DWORD *)v29 + 5);
              v40 = v29 + 5;
              if ( v38 == v39 || _InterlockedCompareExchange(v40, v38, 0) == 0 )
              {
                ++*((_DWORD *)v40 + 1);
                v41 = (CJob *)iToPriority;
                *(_BYTE *)(iToPriority + 29) = -1;
                CJob::Execute(this: v41);
                v28 = (*((_DWORD *)v40 + 1))-- == 1;
                if ( v28 )
                  _InterlockedExchange(v40, 0);
              }
              v29 = (volatile __int32 *)iToPriority;
            }
            (*(void (__thiscall **)(volatile __int32 *))(*v29 + 4))(a1: v29);
            _InterlockedExchangeAdd(&v62->m_nJobs.m_value, 0xFFFFFFFF);
            ++nExecuted;
          }
          else
          {
            v30 = *((_DWORD *)v29 + 3);
            if ( v30 == 1 || v30 == 4 )
            {
              v31 = jobsToPutBack.m_Memory.m_nAllocationCount;
              if ( jobsToPutBack.m_Memory.m_nAllocationCount >= nJobsTotal || jobsToPutBack.m_Memory.m_nGrowSize < 0 )
              {
                v32 = jobsToPutBack.m_Memory.m_pMemory;
              }
              else
              {
                v31 = nJobsTotal;
                jobsToPutBack.m_Memory.m_nAllocationCount = nJobsTotal;
                v50 = 4 * nJobsTotal;
                if ( jobsToPutBack.m_Memory.m_pMemory != nullptr )
                  v32 = (CJob **)_g_pMemAlloc->Realloc_2(
                                   this: _g_pMemAlloc,
                                   a2: jobsToPutBack.m_Memory.m_pMemory,
                                   a3: v50);
                else
                  v32 = (CJob **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v50);
                jobsToPutBack.m_Memory.m_pMemory = v32;
              }
              v33 = jobsToPutBack.m_Size;
              jobsToPutBack.m_pElements = v32;
              v34 = jobsToPutBack.m_Size;
              if ( jobsToPutBack.m_Size + 1 > v31 )
              {
                CUtlMemory<int,int>::Grow(
                  this: (CUtlMemory<CCoroutineMgr *,int> *)&jobsToPutBack,
                  num: jobsToPutBack.m_Size - v31 + 1);
                v33 = jobsToPutBack.m_Size;
                v32 = jobsToPutBack.m_Memory.m_pMemory;
              }
              jobsToPutBack.m_Size = v33 + 1;
              v35 = v33 - v34;
              jobsToPutBack.m_pElements = v32;
              if ( v35 > 0 )
                _V_memmove(dest: &v32[v34 + 1], src: &v32[v34], count: 4 * v35);
              v36 = &v32[v34];
              if ( v36 != nullptr )
                *v36 = (CJob *)iToPriority;
            }
            else
            {
              _InterlockedExchangeAdd(&v62->m_nJobs.m_value, 0xFFFFFFFF);
              (*(void (__thiscall **)(volatile __int32 *))(*v29 + 4))(a1: v29);
            }
          }
          p_m_Count = v60;
          v3 = v62;
        }
        while ( v60->m_value != 0 );
      }
      p_m_Count -= 8;
      v28 = v56-- == 1;
      v60 = p_m_Count;
      if ( v28 )
        break;
      v8 = v55;
      v9 = v54;
    }
    v7 = jobsToPutBack.m_Size;
    v6 = jobsToPutBack.m_Memory.m_pMemory;
  }
  v42 = 0;
  if ( v7 > 0 )
  {
    while ( 1 )
    {
      v43 = v6[v42];
      if ( (v43->m_flags & 4) != 0 )
        break;
      m_iServicingThread = v43->m_iServicingThread;
      if ( m_iServicingThread >= 0 && m_iServicingThread < v62->m_Threads.m_Size )
      {
        v45 = v62->m_Threads.m_Memory.m_pMemory[m_iServicingThread];
LABEL_75:
        p_m_SharedQueue = &v45->m_DirectQueue;
        goto LABEL_76;
      }
      p_m_SharedQueue = &v62->m_SharedQueue;
LABEL_76:
      v47 = CJobQueue::Push(this: p_m_SharedQueue, pJob: v43, iThread: -1);
      _InterlockedExchangeAdd(&v62->m_nJobs.m_value, -v47);
      v6[v42]->Release(this: v6[v42]);
      if ( ++v42 >= v7 )
        goto LABEL_77;
    }
    v45 = *v62->m_Threads.m_Memory.m_pMemory;
    goto LABEL_75;
  }
LABEL_77:
  v62->ResumeExecution(this: v62);
  if ( jobsToPutBack.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  return nExecuted;
}

//------------------------------------------------------------------------------
// Address: 0x1000B410
// Name: public: virtual bool CThreadPool::Start(struct ThreadPoolStartParams_t const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadPool::Start(CThreadPool *this, const ThreadPoolStartParams_t *startParams, const char *pszName)
{
  int CPUInformation; // eax
  ThreeState_t fDistribute; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CJobThread **m_pMemory; // ecx
  int v9; // eax
  CWorkerThread *v10; // eax
  CJobThread *v11; // edi
  CJobThread *v12; // eax
  struct ThreadHandle_t__ *ThreadHandle; // eax
  struct ThreadHandle_t__ *v14; // eax
  int *iAffinityTable; // eax
  int v17; // [esp-8h] [ebp-130h]
  CFmtStrN<256> formattedName; // [esp+8h] [ebp-120h] BYREF
  BOOL bDistribute; // [esp+118h] [ebp-10h]
  int nStackSize; // [esp+11Ch] [ebp-Ch]
  int priority; // [esp+120h] [ebp-8h]
  int nThreads; // [esp+124h] [ebp-4h]

  nThreads = startParams->nThreads;
  if ( nThreads >= 0 )
    goto LABEL_4;
  CPUInformation = _GetCPUInformation();
  if ( (*((_BYTE *)startParams + 272) & 1) != 0 )
  {
    nThreads = *(unsigned __int8 *)(CPUInformation + 5);
    goto LABEL_4;
  }
  nThreads = *(unsigned __int8 *)(CPUInformation + 5) / ((*(char *)(CPUInformation + 4) < 0) + 1) - 1;
  if ( nThreads <= 3 )
  {
LABEL_4:
    if ( nThreads <= 0 )
      return 1;
    goto LABEL_5;
  }
  DevMsg(a1: "Defaulting to limit of 3 worker threads, use -threads on command line if want more\n");
  nThreads = 3;
LABEL_5:
  nStackSize = startParams->nStackSize;
  if ( nStackSize < 0 )
    nStackSize = (*((_BYTE *)startParams + 272) & 1) << 16;
  priority = startParams->iThreadPriority;
  if ( priority == -32768 )
  {
    if ( (*((_BYTE *)startParams + 272) & 1) != 0 )
      priority = 2;
    else
      priority = _ThreadGetPriority(a1: 0);
  }
  fDistribute = startParams->fDistribute;
  if ( fDistribute == TRS_NONE )
    LOBYTE(bDistribute) = (*((_BYTE *)startParams + 272) & 1) == 0;
  else
    LOBYTE(bDistribute) = fDistribute == TRS_TRUE;
  CUtlVector<CJobThread *,CUtlMemory<CJobThread *,int>>::EnsureCapacity(this: &this->m_Threads, num: nThreads);
  if ( pszName == nullptr )
  {
    pszName = "IOJob";
    if ( (*((_BYTE *)startParams + 272) & 1) == 0 )
      pszName = "CmpJob";
  }
  do
  {
    m_Size = this->m_Threads.m_Size;
    m_nAllocationCount = this->m_Threads.m_Memory.m_nAllocationCount;
    --nThreads;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CCoroutineMgr *,int> *)&this->m_Threads,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Threads.m_Size;
    m_pMemory = this->m_Threads.m_Memory.m_pMemory;
    v9 = this->m_Threads.m_Size - m_Size - 1;
    this->m_Threads.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = (CWorkerThread *)operator new(nSize: 0x140u);
    v11 = (CJobThread *)v10;
    if ( v10 != nullptr )
    {
      CWorkerThread::CWorkerThread(this: v10);
      v11->__vftable = (CJobThread_vtbl *)&CJobThread::`vftable';
      CJobQueue::CJobQueue(this: &v11->m_DirectQueue);
      v11->m_SharedQueue = &this->m_SharedQueue;
      v11->m_pOwner = this;
      CThreadEvent::CThreadEvent(this: &v11->m_IdleEvent, a2: true);
      v11->m_iThread = m_Size;
      v12 = v11;
    }
    else
    {
      v12 = nullptr;
    }
    this->m_Threads.m_Memory.m_pMemory[m_Size] = v12;
    CFmtStrN<256>::CFmtStrN<256>(this: &formattedName, pszFormat: "%s%d", pszName, m_Size);
    CThread::SetName(this: this->m_Threads.m_Memory.m_pMemory[m_Size], a2: formattedName.m_szBuf);
    this->m_Threads.m_Memory.m_pMemory[m_Size]->Start(
      this: this->m_Threads.m_Memory.m_pMemory[m_Size],
      a2: nStackSize,
      a3: PRIORITY_DEFAULT);
    CThreadEvent::Wait(this: &this->m_Threads.m_Memory.m_pMemory[m_Size]->m_IdleEvent, a2: 0xFFFFFFFF);
    ThreadHandle = CThread::GetThreadHandle(this: this->m_Threads.m_Memory.m_pMemory[m_Size]);
    _ThreadSetDebugName(a1: ThreadHandle, a2: formattedName.m_szBuf);
    v17 = priority;
    v14 = CThread::GetThreadHandle(this: this->m_Threads.m_Memory.m_pMemory[m_Size]);
    _ThreadSetPriority(a1: v14, a2: v17);
  }
  while ( nThreads != 0 );
  if ( (*((_BYTE *)startParams + 272) & 2) != 0 )
    iAffinityTable = startParams->iAffinityTable;
  else
    iAffinityTable = nullptr;
  this->Distribute(this, a2: bDistribute, a3: iAffinityTable);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B6B0
// Name: public: virtual bool CThreadPool::Stop(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadPool::Stop(CThreadPool *this, int timeout)
{
  int v3; // ebx
  int v4; // edi
  ThreadHandle_t__ *ThreadHandle; // eax
  HANDLE v6; // eax
  ThreadHandle_t__ **m_pMemory; // ebx
  int v8; // edi
  CJobThread *v9; // edi
  ThreadHandle_t__ *v11; // [esp-18h] [ebp-3Ch]
  HANDLE CurrentProcess; // [esp-14h] [ebp-38h]
  int m_Size; // [esp-4h] [ebp-28h]
  CUtlVector<ThreadHandle_t__ *,CUtlMemory<ThreadHandle_t__ *,int> > arrHandles; // [esp+Ch] [ebp-18h] BYREF
  int i; // [esp+20h] [ebp-4h] BYREF

  v3 = 0;
  m_Size = this->m_Threads.m_Size;
  memset(&arrHandles, 0, sizeof(arrHandles));
  CUtlVector<ThreadHandle_t__ *,CUtlMemory<ThreadHandle_t__ *,int>>::InsertMultipleBefore(
    this: &arrHandles,
    elem: 0,
    num: m_Size);
  if ( this->m_Threads.m_Size > 0 )
  {
    do
    {
      v4 = v3;
      ThreadHandle = CThread::GetThreadHandle(this: this->m_Threads.m_Memory.m_pMemory[v3]);
      arrHandles.m_Memory.m_pMemory[v3] = ThreadHandle;
      if ( ThreadHandle != nullptr )
      {
        CurrentProcess = GetCurrentProcess();
        v11 = arrHandles.m_Memory.m_pMemory[v4];
        v6 = GetCurrentProcess();
        DuplicateHandle(
          hSourceProcessHandle: v6,
          hSourceHandle: v11,
          hTargetProcessHandle: CurrentProcess,
          lpTargetHandle: (LPHANDLE)&i,
          dwDesiredAccess: 2u,
          bInheritHandle: false,
          dwOptions: 0);
        arrHandles.m_Memory.m_pMemory[v4] = (ThreadHandle_t__ *)i;
      }
      CWorkerThread::CallWorker(this: this->m_Threads.m_Memory.m_pMemory[v3++], a2: 0, a3: 0xFFFFFFFF, a4: true);
    }
    while ( v3 < this->m_Threads.m_Size );
  }
  for ( i = 0; i < this->m_Threads.m_Size; ++i )
  {
    m_pMemory = arrHandles.m_Memory.m_pMemory;
    v8 = i;
    if ( arrHandles.m_Memory.m_pMemory[i] != nullptr )
    {
      _ThreadJoin(a1: arrHandles.m_Memory.m_pMemory[v8], a2: -1);
      CloseHandle(hObject: m_pMemory[v8]);
    }
    while ( CThread::GetThreadHandle(this: this->m_Threads.m_Memory.m_pMemory[v8]) != nullptr )
      _ThreadSleep(a1: 0);
    v9 = this->m_Threads.m_Memory.m_pMemory[v8];
    if ( v9 != nullptr )
      ((void (__thiscall *)(CJobThread *, int))v9->dtr_CThread)(a1: v9, a2: 1);
  }
  _InterlockedExchange(&this->m_nJobs.m_value, 0);
  CJobQueue::Flush(this: &this->m_SharedQueue);
  _InterlockedExchange(&this->m_nIdleThreads.m_value, 0);
  this->m_Threads.m_Size = 0;
  if ( arrHandles.m_Memory.m_nGrowSize >= 0 && arrHandles.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrHandles.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B850
// Name: _RunThreadPoolTests
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
TSLNodeBase_t *__usercall RunThreadPoolTests@<eax>(int a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  void *v3; // esp
  HANDLE CurrentProcess; // eax
  const char *v5; // eax
  char v6; // di
  int v7; // edi
  const char *v8; // eax
  int k; // edi
  HANDLE v10; // eax
  CJob **m_pMemory; // eax
  CJobThread **v12; // eax
  CTSQueue<CFunctorCallback *,0,1> *p_m_nItems; // esi
  int m; // edi
  TSLNodeBase_t *result; // eax
  CThreadPool v16; // [esp-2110h] [ebp-211Ch] BYREF
  int v17; // [esp-10h] [ebp-1Ch] BYREF
  int v18; // [esp-Ch] [ebp-18h] BYREF
  int j; // [esp-8h] [ebp-14h]
  int i; // [esp-4h] [ebp-10h]
  int v21; // [esp+0h] [ebp-Ch]
  void *v22; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v21 = a1;
  v22 = retaddr;
  v3 = alloca(8472);
  CThreadPool::CThreadPool(this: &v16);
  ThreadPoolTest::g_pTestThreadPool = &v16;
  _RunTSQueueTests(a1: 10000, a2: 1, a3: a2, a4: a3);
  _RunTSListTests(a1: 10000, a2: 1);
  j = (int)&v18;
  v18 = -1;
  CurrentProcess = GetCurrentProcess();
  GetProcessAffinityMask(
    hProcess: CurrentProcess,
    lpProcessAffinityMask: (PDWORD_PTR)v18,
    lpSystemAffinityMask: (PDWORD_PTR)j);
  _Msg(a1: "ThreadPoolTest: Job distribution speed\n");
  for ( i = 0; i < 2; ++i )
  {
    LOBYTE(j) = i & 1;
    v5 = "ThreadPoolTest:   To completion\n";
    if ( (i & 1) == 0 )
      v5 = "ThreadPoolTest:   NOT to completion\n";
    _Msg(a1: v5);
    _Msg(a1: "ThreadPoolTest:     Non-distribute\n");
    v6 = j;
    ThreadPoolTest::Test(
      bDistribute: false,
      bSleep: true,
      bFinishExecute: j,
      bDoWork: false,
      bIncludeMain: false,
      bPrioritized: false);
    _Msg(a1: "ThreadPoolTest:     Distribute\n");
    ThreadPoolTest::Test(
      bDistribute: true,
      bSleep: true,
      bFinishExecute: v6,
      bDoWork: false,
      bIncludeMain: false,
      bPrioritized: false);
    _Msg(a1: "ThreadPoolTest:     NO Sleep\n");
    ThreadPoolTest::Test(
      bDistribute: false,
      bSleep: false,
      bFinishExecute: v6,
      bDoWork: false,
      bIncludeMain: false,
      bPrioritized: false);
    _Msg(a1: "ThreadPoolTest:     Distribute NO Sleep\n");
    ThreadPoolTest::Test(
      bDistribute: true,
      bSleep: false,
      bFinishExecute: v6,
      bDoWork: false,
      bIncludeMain: false,
      bPrioritized: false);
  }
  v7 = 0;
  for ( j = 0; ; v7 = j )
  {
    v8 = "WITH";
    if ( v7 == 0 )
      v8 = "without";
    _Msg(a1: "ThreadPoolTest: Jobs doing work, %s main thread\n", v8);
    LOBYTE(i) = v7 != 0;
    for ( k = 2; k != 0; --k )
    {
      _Msg(a1: "ThreadPoolTest:     Non-distribute\n");
      ThreadPoolTest::Test(
        bDistribute: false,
        bSleep: true,
        bFinishExecute: true,
        bDoWork: true,
        bIncludeMain: i,
        bPrioritized: false);
      _Msg(a1: "ThreadPoolTest:     Distribute\n");
      ThreadPoolTest::Test(
        bDistribute: true,
        bSleep: true,
        bFinishExecute: true,
        bDoWork: true,
        bIncludeMain: i,
        bPrioritized: false);
      _Msg(a1: "ThreadPoolTest:     NO Sleep\n");
      ThreadPoolTest::Test(
        bDistribute: false,
        bSleep: false,
        bFinishExecute: true,
        bDoWork: true,
        bIncludeMain: i,
        bPrioritized: false);
      _Msg(a1: "ThreadPoolTest:     Distribute NO Sleep\n");
      ThreadPoolTest::Test(
        bDistribute: true,
        bSleep: false,
        bFinishExecute: true,
        bDoWork: true,
        bIncludeMain: i,
        bPrioritized: false);
    }
    if ( ++j >= 2 )
      break;
  }
  j = (int)&v18;
  v18 = (int)&v17;
  v10 = GetCurrentProcess();
  GetProcessAffinityMask(hProcess: v10, lpProcessAffinityMask: (PDWORD_PTR)v18, lpSystemAffinityMask: (PDWORD_PTR)j);
  ThreadPoolTest::TestForcedExecute();
  m_pMemory = v16.m_PerFrameJobs.m_Memory.m_pMemory;
  v16.CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT> >::IThreadPool::IRefCounted::__vftable = (CThreadPool_vtbl *)&CThreadPool::`vftable'{for `IThreadPool'};
  v16.CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CThreadPool::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  v16.m_PerFrameJobs.m_Size = 0;
  if ( v16.m_PerFrameJobs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16.m_PerFrameJobs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16.m_PerFrameJobs.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      v16.m_PerFrameJobs.m_Memory.m_pMemory = nullptr;
    }
    v16.m_PerFrameJobs.m_Memory.m_nAllocationCount = 0;
  }
  v16.m_PerFrameJobs.m_pElements = m_pMemory;
  if ( v16.m_PerFrameJobs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      v16.m_PerFrameJobs.m_Memory.m_pMemory = nullptr;
    }
    v16.m_PerFrameJobs.m_Memory.m_nAllocationCount = 0;
  }
  v12 = v16.m_Threads.m_Memory.m_pMemory;
  v16.m_Threads.m_Size = 0;
  if ( v16.m_Threads.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16.m_Threads.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16.m_Threads.m_Memory.m_pMemory);
      v12 = nullptr;
      v16.m_Threads.m_Memory.m_pMemory = nullptr;
    }
    v16.m_Threads.m_Memory.m_nAllocationCount = 0;
  }
  v16.m_Threads.m_pElements = v12;
  if ( v16.m_Threads.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v12 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
      v16.m_Threads.m_Memory.m_pMemory = nullptr;
    }
    v16.m_Threads.m_Memory.m_nAllocationCount = 0;
  }
  CThreadSyncObject::~CThreadSyncObject(this: &v16.m_SharedQueue.m_JobAvailableEvent);
  p_m_nItems = (CTSQueue<CFunctorCallback *,0,1> *)&v16.m_SharedQueue.m_nItems;
  for ( m = 3; m >= 0; --m )
  {
    CTSQueue<CFunctorCallback *,0,1>::Purge(this: --p_m_nItems);
    free(pMem: p_m_nItems->m_Head.value.pNode);
    result = CTSListBase::Detach(this: &p_m_nItems->m_FreeNodes);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BB50
// Name: _CreateNewThreadPool
// Source: json
//------------------------------------------------------------------------------
CThreadPool *__cdecl CreateNewThreadPool()
{
  CThreadPool *v0; // eax

  v0 = (CThreadPool *)operator new(nSize: 0x2100u);
  if ( v0 != nullptr )
    return CThreadPool::CThreadPool(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000BBE0
// Name: public: virtual bool CGlobalThreadPool::Start(struct ThreadPoolStartParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGlobalThreadPool::Start(CGlobalThreadPool *this, const ThreadPoolStartParams_t *startParamsIn)
{
  int v3; // eax
  int v4; // eax
  ThreadPoolStartParams_t startParams; // [esp+Ch] [ebp-114h] BYREF

  v3 = _CommandLine();
  v4 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v3 + 28))(a1: v3, a2: "-threads", a3: -1) - 1;
  startParams = *startParamsIn;
  if ( v4 >= 0 )
    startParams.nThreads = v4;
  return CThreadPool::Start(this, &startParams, pszName: "GlobPool");
}

//------------------------------------------------------------------------------
// Address: 0x1000FA24
// Name: ?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Start(CThread *this, unsigned int a2, enum CThread::ThreadPriorityEnum_t a3)
{
  return __imp_?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1000FA2A
// Name: ?Init@CThread@@MAE_NXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Init(CThread *this)
{
  return __imp_?Init@CThread@@MAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000FA30
// Name: ?OnExit@CThread@@MAEXXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThread::OnExit(CThread *this)
{
  __imp_?OnExit@CThread@@MAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000FA36
// Name: ?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::WaitForCreateComplete(CThread *this, struct CThreadEvent *a2)
{
  return __imp_?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000FA3C
// Name: ?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int (__stdcall *__thiscall CThread::GetThreadProc(CThread *this))(void *)
{
  return __imp_?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x10022700
// Name: ThreadPoolTest::_dynamic_initializer_for__g_done__
// Source: json
//------------------------------------------------------------------------------
int ThreadPoolTest::_dynamic_initializer_for__g_done__()
{
  CThreadEvent::CThreadEvent(this: &ThreadPoolTest::g_done, a2: false);
  return atexit(func: ThreadPoolTest::_dynamic_atexit_destructor_for__g_done__);
}

//------------------------------------------------------------------------------
// Address: 0x10022720
// Name: _dynamic_initializer_for__ThreadPoolTest::CCountJob::m_nCount__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
void dynamic_initializer_for__ThreadPoolTest::CCountJob::m_nCount__()
{
  ThreadPoolTest::CCountJob::m_nCount.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10022730
// Name: ThreadPoolTest::_dynamic_initializer_for__g_nReady__
// Source: json
//------------------------------------------------------------------------------
void ThreadPoolTest::_dynamic_initializer_for__g_nReady__()
{
  ThreadPoolTest::g_nReady.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100229E0
// Name: ThreadPoolTest::_dynamic_atexit_destructor_for__g_done__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadPoolTest::_dynamic_atexit_destructor_for__g_done__()
{
  CThreadSyncObject::~CThreadSyncObject(this: &ThreadPoolTest::g_done);
}

//------------------------------------------------------------------------------
// Address: 0x100229F0
// Name: _CThreadPool::GetDummyJob_::_3_::_dynamic_atexit_destructor_for__dummyJob__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CThreadPool::GetDummyJob_::_3_::_dynamic_atexit_destructor_for__dummyJob__()
{
  CThreadSyncObject::~CThreadSyncObject(this: &dummyJob.m_CompleteEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10022740
// Name: _dynamic_initializer_for__g_KeyValuesSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValuesSystem__()
{
  CKeyValuesSystem::CKeyValuesSystem(this: &g_KeyValuesSystem);
  return atexit(func: dynamic_atexit_destructor_for__g_KeyValuesSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10022760
// Name: _dynamic_initializer_for__s_ProcessUtils__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ProcessUtils__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_ProcessUtils__);
}

//------------------------------------------------------------------------------
// Address: 0x10022770
// Name: _dynamic_initializer_for____g_CreateCProcessUtilsIProcessUtils_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCProcessUtilsIProcessUtils_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCProcessUtilsIProcessUtils_reg,
           fn: (void *(__cdecl *)())_CreateCProcessUtilsIProcessUtils_interface,
           pName: "VProcessUtils002");
}

//------------------------------------------------------------------------------
// Address: 0x10022790
// Name: _dynamic_initializer_for__s_UniformStream__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_UniformStream__()
{
  DWORD CurrentThreadId; // ecx
  bool v1; // zf
  int result; // eax

  s_UniformStream.m_mutex.m_ownerID = 0;
  s_UniformStream.m_mutex.m_depth = 0;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_UniformStream.m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_UniformStream.m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_UniformStream.m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_UniformStream.m_mutex.m_depth;
  }
  s_UniformStream.m_idum = 0;
  s_UniformStream.m_iy = 0;
  v1 = s_UniformStream.m_mutex.m_depth-- == 1;
  result = s_UniformStream.m_mutex.m_depth;
  if ( v1 )
    _InterlockedExchange((volatile __int32 *)&s_UniformStream.m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022820
// Name: _dynamic_initializer_for__s_GaussianStream__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GaussianStream__()
{
  DWORD CurrentThreadId; // ecx
  bool v1; // zf
  int result; // eax

  s_GaussianStream.m_mutex.m_ownerID = 0;
  s_GaussianStream.m_mutex.m_depth = 0;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_GaussianStream.m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_GaussianStream.m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_GaussianStream.m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_GaussianStream.m_mutex.m_depth;
  }
  s_GaussianStream.m_pUniformStream = nullptr;
  s_GaussianStream.m_bHaveValue = false;
  v1 = s_GaussianStream.m_mutex.m_depth-- == 1;
  result = s_GaussianStream.m_mutex.m_depth;
  if ( v1 )
    _InterlockedExchange((volatile __int32 *)&s_GaussianStream.m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100228A0
// Name: _dynamic_initializer_for__g_VCoverage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VCoverage__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VCoverage__);
}

//------------------------------------------------------------------------------
// Address: 0x100228B0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x100228D0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(dst: (int)s_StringCharConversion.m_pConversion, value: 0, count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022930
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022960
// Name: _dynamic_atexit_destructor_for__g_ThreadMutexCoroutineMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ThreadMutexCoroutineMgr__()
{
  CThreadMutex::~CThreadMutex(this: &g_ThreadMutexCoroutineMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10022970
// Name: _dynamic_atexit_destructor_for__g_ThreadLocalCoroutineMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ThreadLocalCoroutineMgr__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_ThreadLocalCoroutineMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10022980
// Name: _dynamic_atexit_destructor_for__g_VecPCoroutineMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VecPCoroutineMgr__()
{
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &g_VecPCoroutineMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10022A00
// Name: _dynamic_atexit_destructor_for__g_ThreadPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ThreadPool__()
{
  g_ThreadPool.CThreadPool::CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT> >::IThreadPool::IRefCounted::__vftable = (CGlobalThreadPool_vtbl *)&CThreadPool::`vftable'{for `IThreadPool'};
  g_ThreadPool.CThreadPool::CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CThreadPool::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  CUtlVector<CJob *,CUtlMemoryFixedGrowable<CJob *,2048,int>>::~CUtlVector<CJob *,CUtlMemoryFixedGrowable<CJob *,2048,int>>(this: &g_ThreadPool.m_PerFrameJobs);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *,int> > *)&g_ThreadPool.m_Threads);
  CJobQueue::~CJobQueue(this: &g_ThreadPool.m_SharedQueue);
  g_ThreadPool.CThreadPool::CRefCounted1<IThreadPool,CRefCountServiceBase<1,CRefMT> >::IThreadPool::IRefCounted::__vftable = (CGlobalThreadPool_vtbl *)&IThreadPool::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10022A40
// Name: _dynamic_atexit_destructor_for__g_KeyValuesSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KeyValuesSystem__()
{
  g_KeyValuesSystem.__vftable = (CKeyValuesSystem_vtbl *)&CKeyValuesSystem::`vftable';
  CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_KeyValuesSystem.m_KvConditionalSymbolTable.m_Tree);
  CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>::~CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>(this: &g_KeyValuesSystem.m_KeyValuesTrackingList);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *,int> > *)&g_KeyValuesSystem.m_HashTable);
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_KeyValuesSystem.m_HashItemMemPool);
  CMemoryStack::~CMemoryStack(this: &g_KeyValuesSystem.m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x10022A80
// Name: _dynamic_atexit_destructor_for__s_ProcessUtils__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ProcessUtils__()
{
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *v1; // [esp-4h] [ebp-8h]

  CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::RemoveAll(this: &s_ProcessUtils.m_Processes);
  m_pBlocks = s_ProcessUtils.m_Processes.m_Memory.m_pBlocks;
  if ( s_ProcessUtils.m_Processes.m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v1 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1);
    }
    while ( m_pBlocks != nullptr );
    s_ProcessUtils.m_Processes.m_Memory.m_pBlocks = nullptr;
    s_ProcessUtils.m_Processes.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022AC0
// Name: _dynamic_atexit_destructor_for__g_VCoverage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VCoverage__()
{
  CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::~CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>(this: &g_VCoverage.m_locations);
}

//------------------------------------------------------------------------------
// Address: 0x10022AD0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}
