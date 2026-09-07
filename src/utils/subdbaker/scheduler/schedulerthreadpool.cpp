// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/subdbaker/scheduler/schedulerthreadpool.cpp
// Functions: 39
// ============================================================

#include "utils\subdbaker\scheduler\schedulerthreadpool.h"

//------------------------------------------------------------------------------
// Address: 0x00409340
// Name: public: virtual void CSchedulerThread::LockThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThread::LockThread(CSchedulerThread *this)
{
  EnterCriticalSection(lpCriticalSection: &this->m_csThread);
}

//------------------------------------------------------------------------------
// Address: 0x00409350
// Name: public: virtual void CSchedulerThread::UnlockThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThread::UnlockThread(CSchedulerThread *this)
{
  LeaveCriticalSection(lpCriticalSection: &this->m_csThread);
}

//------------------------------------------------------------------------------
// Address: 0x00409360
// Name: public: virtual void CSchedulerThread::SetPullGranularities(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThread::SetPullGranularities(
        CSchedulerThread *this,
        int iParentPullGranularity,
        int iSiblingPullGranularity)
{
  if ( this->m_pScheduleQueue != nullptr )
    this->m_pScheduleQueue->SetPullGranularities(
      this: this->m_pScheduleQueue,
      a2: iParentPullGranularity,
      a3: iSiblingPullGranularity);
}

//------------------------------------------------------------------------------
// Address: 0x00409380
// Name: public: virtual void CSchedulerThread::ResetScheduleArrays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThread::ResetScheduleArrays(CSchedulerThread *this)
{
  if ( this->m_pScheduleQueue != nullptr )
    this->m_pScheduleQueue->ResetScheduleArrays(this: this->m_pScheduleQueue);
}

//------------------------------------------------------------------------------
// Address: 0x004093A0
// Name: private: unsigned int CSchedulerThread::ThreadLoop(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSchedulerThread::ThreadLoop(CSchedulerThread *this)
{
  IScheduleObject *v2; // eax
  IScheduleObject *v3; // edi

  while ( this->m_iRunning != 0 )
  {
    this->LockThread(this);
    v2 = this->m_pScheduleQueue->GetNextJob(this: this->m_pScheduleQueue);
    v3 = v2;
    if ( v2 != nullptr )
    {
      v2->Execute(this: v2);
      v3->CompleteJob(this: v3);
    }
    this->UnlockThread(this);
  }
  InterlockedIncrement(lpAddend: &this->m_iCanDestroyThread);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409410
// Name: public: virtual int CSchedulerThreadPool::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchedulerThreadPool::AddRef(CSchedulerThreadPool *this)
{
  return ++this->m_iRef;
}

//------------------------------------------------------------------------------
// Address: 0x00409420
// Name: public: virtual int CSchedulerThreadPool::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchedulerThreadPool::Release(CSchedulerThreadPool *this)
{
  bool v1; // zf
  int m_iRef; // esi

  v1 = this->m_iRef-- == 1;
  m_iRef = this->m_iRef;
  if ( v1 )
    ((void (__thiscall *)(CSchedulerThreadPool *, int))this->dtr_CSchedulerThreadPool)(a1: this, a2: 1);
  return m_iRef;
}

//------------------------------------------------------------------------------
// Address: 0x00409440
// Name: public: virtual void CSchedulerThreadPool::LockThreadPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThreadPool::LockThreadPool(CSchedulerThreadPool *this)
{
  int i; // esi
  CSchedulerThread **m_ppSchedulerThreads; // eax

  for ( i = 0; i < this->m_nNumSchedulerThreads; ++i )
  {
    m_ppSchedulerThreads = this->m_ppSchedulerThreads;
    if ( m_ppSchedulerThreads[i] != nullptr )
      m_ppSchedulerThreads[i]->LockThread(this: m_ppSchedulerThreads[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409470
// Name: public: virtual void CSchedulerThreadPool::UnlockThreadPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThreadPool::UnlockThreadPool(CSchedulerThreadPool *this)
{
  int i; // esi
  CSchedulerThread **m_ppSchedulerThreads; // eax

  for ( i = 0; i < this->m_nNumSchedulerThreads; ++i )
  {
    m_ppSchedulerThreads = this->m_ppSchedulerThreads;
    if ( m_ppSchedulerThreads[i] != nullptr )
      m_ppSchedulerThreads[i]->UnlockThread(this: m_ppSchedulerThreads[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004094A0
// Name: public: virtual bool CSchedulerThreadPool::RunThreads(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSchedulerThreadPool::RunThreads(CSchedulerThreadPool *this)
{
  int v2; // esi
  CSchedulerThread *v3; // ecx

  v2 = 0;
  if ( this->m_nNumSchedulerThreads <= 0 )
    return 1;
  while ( 1 )
  {
    v3 = this->m_ppSchedulerThreads[v2];
    if ( v3->Run(this: v3) == 0 )
      break;
    if ( ++v2 >= this->m_nNumSchedulerThreads )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004094D0
// Name: public: virtual void CSchedulerThreadPool::StopThreads(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThreadPool::StopThreads(CSchedulerThreadPool *this)
{
  int i; // esi
  CSchedulerThread *v3; // ecx

  for ( i = 0; i < this->m_nNumSchedulerThreads; ++i )
  {
    v3 = this->m_ppSchedulerThreads[i];
    v3->Stop(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409500
// Name: public: virtual class IScheduleQueue __near * CSchedulerThreadPool::GetThreadAffinityQueue(int)
// Source: json
//------------------------------------------------------------------------------
IScheduleQueue *__thiscall CSchedulerThreadPool::GetThreadAffinityQueue(CSchedulerThreadPool *this, int iThread)
{
  IScheduleQueue *result; // eax

  result = (IScheduleQueue *)this->GetSchedulerThreadByIndex(this, a2: iThread);
  if ( result != nullptr )
    return ((IScheduleQueue *(__thiscall *)(IScheduleQueue *))result->SetPullGranularities)(a1: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409530
// Name: public: virtual class IScheduleQueue __near * CSchedulerThreadPool::GetThreadAffinityQueue(char __near *)
// Source: json
//------------------------------------------------------------------------------
IScheduleQueue *__thiscall CSchedulerThreadPool::GetThreadAffinityQueue(CSchedulerThreadPool *this, char *pzsName)
{
  IScheduleQueue *result; // eax

  result = (IScheduleQueue *)this->GetSchedulerThreadByName(this, a2: pzsName);
  if ( result != nullptr )
    return ((IScheduleQueue *(__thiscall *)(IScheduleQueue *))result->SetPullGranularities)(a1: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409560
// Name: public: virtual void CSchedulerThreadPool::SetPullGranularities(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThreadPool::SetPullGranularities(
        CSchedulerThreadPool *this,
        int iParentPullGranularity,
        int iSiblingPullGranularity)
{
  int i; // esi
  CSchedulerThread *v5; // ecx

  for ( i = 0; i < this->m_nNumSchedulerThreads; ++i )
  {
    v5 = this->m_ppSchedulerThreads[i];
    v5->SetPullGranularities(this: v5, a2: iParentPullGranularity, a3: iSiblingPullGranularity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004095A0
// Name: public: virtual void CSchedulerThreadPool::ResetScheduleArrays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThreadPool::ResetScheduleArrays(CSchedulerThreadPool *this)
{
  int i; // esi
  CSchedulerThread *v3; // ecx

  this->m_pGlobalScheduleQueue->ResetScheduleArrays(this: this->m_pGlobalScheduleQueue);
  for ( i = 0; i < this->m_nNumSchedulerThreads; ++i )
  {
    v3 = this->m_ppSchedulerThreads[i];
    v3->ResetScheduleArrays(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004095D0
// Name: public: virtual class IScheduleObject __near * CSchedulerThreadPool::CreateScheduleJob(class CJob __near *)
// Source: json
//------------------------------------------------------------------------------
CScheduleObject *__thiscall CSchedulerThreadPool::CreateScheduleJob(CSchedulerThreadPool *this, CJob *pJob)
{
  CScheduleObject *v3; // eax
  CScheduleObject *v4; // esi

  v3 = (CScheduleObject *)operator new(nSize: 0x154u);
  v4 = nullptr;
  if ( v3 != nullptr )
    v4 = CScheduleObject::CScheduleObject(this: v3, pThreadPool: this);
  v4->AddRef(this: v4);
  v4->SetGlobalScheduleQueue(this: v4, a2: this->m_pGlobalScheduleQueue);
  v4->SetJobA(this: v4, a2: pJob);
  ++pJob->m_iRef;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00409650
// Name: public: virtual class IScheduleObject __near * CSchedulerThreadPool::CreateScheduleJobWithAffinity(class CJob __near *,int)
// Source: json
//------------------------------------------------------------------------------
CScheduleObject *__thiscall CSchedulerThreadPool::CreateScheduleJobWithAffinity(
        CSchedulerThreadPool *this,
        CJob *pJob,
        int iThread)
{
  ISchedulerThread *v4; // ebx
  CScheduleObject *v5; // esi
  CScheduleObject *v7; // eax
  CScheduleObject_vtbl *v8; // edi
  int v9; // eax

  v4 = this->GetSchedulerThreadByIndex(this, a2: iThread);
  v5 = nullptr;
  if ( v4 == nullptr )
    return nullptr;
  v7 = (CScheduleObject *)operator new(nSize: 0x154u);
  if ( v7 != nullptr )
    v5 = CScheduleObject::CScheduleObject(this: v7, pThreadPool: this);
  v5->AddRef(this: v5);
  v5->SetGlobalScheduleQueue(this: v5, a2: this->m_pGlobalScheduleQueue);
  v8 = v5->__vftable;
  v9 = (int)v4->GetScheduleQueue(this: v4);
  v8->SetAffinityQueue(this: v5, a2: (IScheduleQueue *)v9);
  v5->SetJobA(this: v5, a2: pJob);
  ++pJob->m_iRef;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00409710
// Name: public: virtual class IScheduleObject __near * CSchedulerThreadPool::CreateScheduleJobWithAffinity(class CJob __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
CScheduleObject *__thiscall CSchedulerThreadPool::CreateScheduleJobWithAffinity(
        CSchedulerThreadPool *this,
        CJob *pJob,
        char *pzsName)
{
  ISchedulerThread *v4; // ebx
  CScheduleObject *v5; // esi
  CScheduleObject *v7; // eax
  CScheduleObject_vtbl *v8; // edi
  int v9; // eax

  v4 = this->GetSchedulerThreadByName(this, a2: pzsName);
  v5 = nullptr;
  if ( v4 == nullptr )
    return nullptr;
  v7 = (CScheduleObject *)operator new(nSize: 0x154u);
  if ( v7 != nullptr )
    v5 = CScheduleObject::CScheduleObject(this: v7, pThreadPool: this);
  v5->AddRef(this: v5);
  v5->SetGlobalScheduleQueue(this: v5, a2: this->m_pGlobalScheduleQueue);
  v8 = v5->__vftable;
  v9 = (int)v4->GetScheduleQueue(this: v4);
  v8->SetAffinityQueue(this: v5, a2: (IScheduleQueue *)v9);
  v5->SetJobA(this: v5, a2: pJob);
  ++pJob->m_iRef;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004097D0
// Name: public: virtual class IScheduleObject __near * CSchedulerThreadPool::CreateScheduleBatch(class CJob __near *)
// Source: json
//------------------------------------------------------------------------------
CScheduleBatch *__thiscall CSchedulerThreadPool::CreateScheduleBatch(CSchedulerThreadPool *this, CJob *pJob)
{
  CScheduleBatch *v3; // eax
  CScheduleBatch *v4; // esi

  v3 = (CScheduleBatch *)operator new(nSize: 0x16Cu);
  v4 = nullptr;
  if ( v3 != nullptr )
    v4 = CScheduleBatch::CScheduleBatch(this: v3, pThreadPool: this);
  v4->AddRef(this: v4);
  v4->SetGlobalScheduleQueue(this: v4, a2: this->m_pGlobalScheduleQueue);
  v4->SetJobA(this: v4, a2: pJob);
  ++pJob->m_iRef;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00409850
// Name: public: virtual class IScheduleObject __near * CSchedulerThreadPool::CreateScheduleBatchWithAffinity(class CJob __near *,int)
// Source: json
//------------------------------------------------------------------------------
CScheduleBatch *__thiscall CSchedulerThreadPool::CreateScheduleBatchWithAffinity(
        CSchedulerThreadPool *this,
        CJob *pJob,
        int iThread)
{
  ISchedulerThread *v4; // ebx
  CScheduleBatch *v5; // esi
  CScheduleBatch *v7; // eax
  CScheduleBatch_vtbl *v8; // edi
  int v9; // eax

  v4 = this->GetSchedulerThreadByIndex(this, a2: iThread);
  v5 = nullptr;
  if ( v4 == nullptr )
    return nullptr;
  v7 = (CScheduleBatch *)operator new(nSize: 0x16Cu);
  if ( v7 != nullptr )
    v5 = CScheduleBatch::CScheduleBatch(this: v7, pThreadPool: this);
  v5->AddRef(this: v5);
  v5->SetGlobalScheduleQueue(this: v5, a2: this->m_pGlobalScheduleQueue);
  v8 = v5->__vftable;
  v9 = (int)v4->GetScheduleQueue(this: v4);
  v8->SetAffinityQueue(this: v5, a2: (IScheduleQueue *)v9);
  v5->SetJobA(this: v5, a2: pJob);
  ++pJob->m_iRef;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00409910
// Name: public: virtual class IScheduleObject __near * CSchedulerThreadPool::CreateScheduleBatchWithAffinity(class CJob __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
CScheduleBatch *__thiscall CSchedulerThreadPool::CreateScheduleBatchWithAffinity(
        CSchedulerThreadPool *this,
        CJob *pJob,
        char *pzsName)
{
  ISchedulerThread *v4; // ebx
  CScheduleBatch *v5; // esi
  CScheduleBatch *v7; // eax
  CScheduleBatch_vtbl *v8; // edi
  int v9; // eax

  v4 = this->GetSchedulerThreadByName(this, a2: pzsName);
  v5 = nullptr;
  if ( v4 == nullptr )
    return nullptr;
  v7 = (CScheduleBatch *)operator new(nSize: 0x16Cu);
  if ( v7 != nullptr )
    v5 = CScheduleBatch::CScheduleBatch(this: v7, pThreadPool: this);
  v5->AddRef(this: v5);
  v5->SetGlobalScheduleQueue(this: v5, a2: this->m_pGlobalScheduleQueue);
  v8 = v5->__vftable;
  v9 = (int)v4->GetScheduleQueue(this: v4);
  v8->SetAffinityQueue(this: v5, a2: (IScheduleQueue *)v9);
  v5->SetJobA(this: v5, a2: pJob);
  ++pJob->m_iRef;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004099D0
// Name: public: virtual class ISchedulerThread __near * CSchedulerThreadPool::GetSchedulerThreadByName(char __near *)
// Source: json
//------------------------------------------------------------------------------
CSchedulerThread *__thiscall CSchedulerThreadPool::GetSchedulerThreadByName(CSchedulerThreadPool *this, char *pzsName)
{
  int v3; // edi
  CSchedulerThread *v4; // ecx

  v3 = 0;
  if ( this->m_nNumSchedulerThreads <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_ppSchedulerThreads[v3];
    if ( strcmp(v4->GetFriendlyName(this: v4), pzsName) == 0 )
      break;
    if ( ++v3 >= this->m_nNumSchedulerThreads )
      return nullptr;
  }
  return this->m_ppSchedulerThreads[v3];
}

//------------------------------------------------------------------------------
// Address: 0x00409A40
// Name: unsigned int ScheduleThreadProc(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall ScheduleThreadProc(CSchedulerThread *pArg)
{
  return CSchedulerThread::ThreadLoop(this: pArg);
}

//------------------------------------------------------------------------------
// Address: 0x00409A50
// Name: public: CSchedulerThread::CSchedulerThread(void)
// Source: json
//------------------------------------------------------------------------------
CSchedulerThread *__thiscall CSchedulerThread::CSchedulerThread(CSchedulerThread *this)
{
  this->__vftable = (CSchedulerThread_vtbl *)&CSchedulerThread::`vftable';
  this->m_hThread = nullptr;
  this->m_pScheduleQueue = nullptr;
  this->m_bThreadCreated = false;
  this->m_iRunning = 0;
  this->m_iCanDestroyThread = 0;
  this->m_nProcessorAffinity = 0;
  InitializeCriticalSection(lpCriticalSection: &this->m_csThread);
  memset(dst: (unsigned __int8 *)this->m_szFriendlyName, value: 0, count: sizeof(this->m_szFriendlyName));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00409AB0
// Name: public: virtual void CSchedulerThread::SetFriendlyName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThread::SetFriendlyName(CSchedulerThread *this, const char *szFriendlyName)
{
  strcpy_s(_Dst: this->m_szFriendlyName, _SizeInBytes: 0x100u, _Src: szFriendlyName);
}

//------------------------------------------------------------------------------
// Address: 0x00409AD0
// Name: public: virtual char const __near * CSchedulerThread::GetFriendlyName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSchedulerThread::GetFriendlyName(CSchedulerThread *this)
{
  return this->m_szFriendlyName;
}

//------------------------------------------------------------------------------
// Address: 0x00409AE0
// Name: public: virtual void CSchedulerThread::SetScheduleQueue(class IScheduleQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThread::SetScheduleQueue(CSchedulerThread *this, IScheduleQueue *pScheduleQueue)
{
  this->m_pScheduleQueue = pScheduleQueue;
}

//------------------------------------------------------------------------------
// Address: 0x00409AF0
// Name: public: virtual class IScheduleQueue __near * CSchedulerThread::GetScheduleQueue(void)const
// Source: json
//------------------------------------------------------------------------------
IScheduleQueue *__thiscall CSchedulerThread::GetScheduleQueue(CSchedulerThread *this)
{
  return this->m_pScheduleQueue;
}

//------------------------------------------------------------------------------
// Address: 0x00409B00
// Name: public: virtual void CSchedulerThread::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThread::Stop(CSchedulerThread *this)
{
  if ( this->m_bThreadCreated )
  {
    InterlockedDecrement(lpAddend: &this->m_iRunning);
    while ( this->m_iCanDestroyThread == 0 )
      ;
    CloseHandle(hObject: this->m_hThread);
    this->m_pScheduleQueue->RemoveFromSiblingQueues(this: this->m_pScheduleQueue);
    this->m_bThreadCreated = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409B50
// Name: private: bool CSchedulerThread::CreateThread(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSchedulerThread::CreateThread(CSchedulerThread *this)
{
  void *v2; // eax
  unsigned int threadAddr; // [esp+4h] [ebp-4h] BYREF

  if ( !this->m_bThreadCreated )
  {
    v2 = (void *)_beginthreadex(
                   security: nullptr,
                   stacksize: 0,
                   initialcode: (unsigned int (__stdcall *)(void *))ScheduleThreadProc,
                   argument: this,
                   createflag: 4u,
                   thrdaddr: &threadAddr);
    this->m_hThread = v2;
    if ( v2 == (void *)-1 )
      return false;
    ResumeThread(hThread: v2);
    this->m_bThreadCreated = true;
  }
  return this->m_bThreadCreated;
}

//------------------------------------------------------------------------------
// Address: 0x00409BA0
// Name: public: virtual int CSchedulerThreadPool::GetNumSchedulerThreads(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSchedulerThreadPool::GetNumSchedulerThreads(CSchedulerThreadPool *this)
{
  return this->m_nNumSchedulerThreads;
}

//------------------------------------------------------------------------------
// Address: 0x00409BB0
// Name: public: virtual class ISchedulerThread __near * CSchedulerThreadPool::GetSchedulerThreadByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CSchedulerThread *__thiscall CSchedulerThreadPool::GetSchedulerThreadByIndex(CSchedulerThreadPool *this, int iThread)
{
  return this->m_ppSchedulerThreads[iThread];
}

//------------------------------------------------------------------------------
// Address: 0x00409BC0
// Name: public: virtual void CSchedulerThreadPool::SetThreadName(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThreadPool::SetThreadName(CSchedulerThreadPool *this, int iThread, char *pszName)
{
  ISchedulerThread *v3; // eax

  v3 = this->GetSchedulerThreadByIndex(this, a2: iThread);
  v3->SetFriendlyName(this: v3, a2: pszName);
}

//------------------------------------------------------------------------------
// Address: 0x00409BE0
// Name: public: virtual class IScheduleQueue __near * CSchedulerThreadPool::GetGlobalScheduleQueue(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSchedulerThreadPool::GetGlobalScheduleQueue(ConCommandBase *this)
{
  return this->m_pszName;
}

//------------------------------------------------------------------------------
// Address: 0x00409BF0
// Name: public: virtual bool CSchedulerThreadPool::CreateSchedulerThreads(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSchedulerThreadPool::CreateSchedulerThreads(CSchedulerThreadPool *this, int NumThreads)
{
  CScheduleQueue *v4; // eax
  int v5; // ebx
  CScheduleQueue *v6; // eax
  CSchedulerThread **v7; // eax
  CSchedulerThread *v8; // eax
  CSchedulerThread *v9; // eax
  CScheduleQueue *v10; // eax
  CScheduleQueue *v11; // edi
  CSchedulerThread *v12; // ecx
  int v13; // eax
  int v14; // ecx
  CSchedulerThread *v15; // ecx
  IScheduleQueue *v16; // eax
  CSchedulerThread *v17; // ecx
  IScheduleQueue *v18; // ebx
  IScheduleQueue_vtbl *v19; // edi
  int v20; // eax
  int i; // [esp+8h] [ebp-10h]
  int c; // [esp+20h] [ebp+8h]

  if ( NumThreads < 1 )
    return 0;
  this->DestroySchedulerThreads(this);
  v4 = (CScheduleQueue *)operator new(nSize: 0x9Cu);
  v5 = 0;
  if ( v4 != nullptr )
    v6 = CScheduleQueue::CScheduleQueue(this: v4);
  else
    v6 = nullptr;
  this->m_pGlobalScheduleQueue = v6;
  if ( v6 == nullptr )
    return 0;
  this->m_nNumSchedulerThreads = NumThreads;
  v7 = (CSchedulerThread **)operator new(nSize: 4 * NumThreads);
  this->m_ppSchedulerThreads = v7;
  if ( v7 == nullptr )
    return 0;
  if ( this->m_nNumSchedulerThreads > 0 )
  {
    do
    {
      v8 = (CSchedulerThread *)operator new(nSize: 0x138u);
      v9 = v8 != nullptr ? CSchedulerThread::CSchedulerThread(this: v8) : nullptr;
      this->m_ppSchedulerThreads[v5] = v9;
      if ( this->m_ppSchedulerThreads[v5] == nullptr )
        return 0;
      v10 = (CScheduleQueue *)operator new(nSize: 0x9Cu);
      if ( v10 != nullptr )
        v11 = CScheduleQueue::CScheduleQueue(this: v10);
      else
        v11 = nullptr;
      v11->SetParentQueue(this: v11, a2: this->m_pGlobalScheduleQueue);
      v12 = this->m_ppSchedulerThreads[v5];
      v12->SetScheduleQueue(this: v12, a2: v11);
    }
    while ( ++v5 < this->m_nNumSchedulerThreads );
  }
  v13 = 0;
  for ( i = 0; v13 < this->m_nNumSchedulerThreads; i = v13 )
  {
    v14 = 0;
    for ( c = 0; v14 < this->m_nNumSchedulerThreads; c = v14 )
    {
      if ( v13 != v14 )
      {
        v15 = this->m_ppSchedulerThreads[v13];
        v16 = v15->GetScheduleQueue(this: v15);
        v17 = this->m_ppSchedulerThreads[c];
        v18 = v16;
        v19 = v16->__vftable;
        v20 = (int)v17->GetScheduleQueue(this: v17);
        v19->AddSiblingQueue(this: v18, a2: (IScheduleQueue *)v20);
        v14 = c;
        v13 = i;
      }
      ++v14;
    }
    ++v13;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409DA0
// Name: class ISchedulerThreadPool __near * SchedulerCreateThreadPool(void)
// Source: json
//------------------------------------------------------------------------------
ISchedulerThreadPool *__cdecl SchedulerCreateThreadPool()
{
  _DWORD *v0; // eax
  void (__thiscall ***v1)(_DWORD); // esi

  v0 = operator new(nSize: 0x14u);
  v1 = nullptr;
  if ( v0 != nullptr )
  {
    v0[1] = 0;
    v0[2] = 0;
    v0[3] = 0;
    v0[4] = 0;
    *v0 = &CSchedulerThreadPool::`vftable';
    v1 = (void (__thiscall ***)(_DWORD))v0;
  }
  (**v1)(a1: v1);
  return (ISchedulerThreadPool *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x00409DE0
// Name: public: CSchedulerThread::~CSchedulerThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSchedulerThread::~CSchedulerThread(CSchedulerThread *this)
{
  bool v2; // zf

  v2 = !this->m_bThreadCreated;
  this->__vftable = (CSchedulerThread_vtbl *)&CSchedulerThread::`vftable';
  if ( !v2 )
  {
    InterlockedDecrement(lpAddend: &this->m_iRunning);
    while ( this->m_iCanDestroyThread == 0 )
      ;
    CloseHandle(hObject: this->m_hThread);
    this->m_pScheduleQueue->RemoveFromSiblingQueues(this: this->m_pScheduleQueue);
    this->m_bThreadCreated = false;
  }
  DeleteCriticalSection(lpCriticalSection: &this->m_csThread);
}

//------------------------------------------------------------------------------
// Address: 0x00409E40
// Name: public: virtual bool CSchedulerThread::Run(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSchedulerThread::Run(CSchedulerThread *this)
{
  if ( this->m_pScheduleQueue == nullptr )
    return 0;
  if ( !this->m_bThreadCreated )
  {
    InterlockedIncrement(lpAddend: &this->m_iRunning);
    CSchedulerThread::CreateThread(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409E80
// Name: public: virtual bool CSchedulerThreadPool::DestroySchedulerThreads(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSchedulerThreadPool::DestroySchedulerThreads(CSchedulerThreadPool *this)
{
  int v2; // edi
  CSchedulerThread **m_ppSchedulerThreads; // eax
  bool v4; // zf
  CSchedulerThread **v5; // eax
  int v6; // eax
  CSchedulerThread **v7; // ecx
  CSchedulerThread *v8; // ebx
  CScheduleQueue *m_pGlobalScheduleQueue; // ecx

  if ( this->m_nNumSchedulerThreads > 0 && this->m_ppSchedulerThreads != nullptr )
  {
    v2 = 0;
    do
    {
      m_ppSchedulerThreads = this->m_ppSchedulerThreads;
      v4 = m_ppSchedulerThreads[v2] == nullptr;
      v5 = &m_ppSchedulerThreads[v2];
      if ( !v4 )
      {
        v6 = (int)(*v5)->GetScheduleQueue(this: *v5);
        if ( v6 != 0 )
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 52))(a1: v6, a2: 1);
        v7 = this->m_ppSchedulerThreads;
        v8 = v7[v2];
        if ( v8 != nullptr )
        {
          CSchedulerThread::~CSchedulerThread(this: v7[v2]);
          free(pMem: v8);
        }
        this->m_ppSchedulerThreads[v2] = nullptr;
      }
      ++v2;
    }
    while ( v2 < this->m_nNumSchedulerThreads );
    free(pMem: this->m_ppSchedulerThreads);
    this->m_ppSchedulerThreads = nullptr;
    this->m_nNumSchedulerThreads = 0;
  }
  m_pGlobalScheduleQueue = this->m_pGlobalScheduleQueue;
  if ( m_pGlobalScheduleQueue != nullptr )
    ((void (__thiscall *)(CScheduleQueue *, int))m_pGlobalScheduleQueue->dtr_CScheduleQueue)(
      a1: m_pGlobalScheduleQueue,
      a2: 1);
  this->m_pGlobalScheduleQueue = nullptr;
  return 1;
}
