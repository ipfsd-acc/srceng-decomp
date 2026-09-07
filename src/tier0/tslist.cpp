// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/tslist.cpp
// Functions: 51
// ============================================================

#include "tier0\tslist.h"

//------------------------------------------------------------------------------
// Address: 0x1000FFA0
// Name: private: virtual bool TSListTests::CListOps::Validate(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?AssertOwnedByCurrentThread@CThreadFullMutex@@QAE_NXZ'
// Alternative name is '?AssertOwnedByCurrentThread@CThreadMutex@@QAE_NXZ'
// Alternative name is '?Init@CThread@@MAE_NXZ'
// Alternative name is 'Plat_FastVerifyHardwareKey'
// Alternative name is 'Plat_VerifyHardwareKey'
// Alternative name is 'Plat_VerifyHardwareKeyDriver'
char __thiscall TSListTests::CListOps::Validate(CThreadMutex *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000FFB0
// Name: private: virtual bool TSListTests::CListOps::IsEmpty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall TSListTests::CListOps::IsEmpty(TSListTests::CListOps *this)
{
  return TSListTests::g_TestList.m_Head.value.Depth == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000FFC0
// Name: private: virtual bool TSListTests::CQueueOps::IsEmpty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall TSListTests::CQueueOps::IsEmpty(TSListTests::CQueueOps *this)
{
  return TSListTests::g_TestQueue.m_Count.m_value == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000FFD0
// Name: void TSListTests::TestStart(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TSListTests::TestStart()
{
  _InterlockedExchange(&TSListTests::g_nTested.m_value, 0);
  _InterlockedExchange(&TSListTests::g_nThreads.m_value, 0);
  _InterlockedExchange(&TSListTests::g_nPushThreads.m_value, 0);
  _InterlockedExchange(&TSListTests::g_nPopThreads.m_value, 0);
  TSListTests::g_bStart = false;
  _InterlockedExchange(&TSListTests::g_nPushes.m_value, 0);
  _InterlockedExchange(&TSListTests::g_nPops.m_value, TSListTests::g_nPushes.m_value);
  memset(dst: TSListTests::g_pTestBuckets, value: 0, count: 4 * TSListTests::NUM_TEST);
}

//------------------------------------------------------------------------------
// Address: 0x10010050
// Name: void TSListTests::TestWait(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TSListTests::TestWait()
{
  while ( TSListTests::g_nThreads.m_value < TSListTests::NUM_THREADS )
    ThreadSleep(duration: 0);
  TSListTests::g_bStart = true;
  while ( TSListTests::g_nThreads.m_value > 0 )
    ThreadSleep(duration: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100100B0
// Name: void TSListTests::TestEnd(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TSListTests::TestEnd(bool bExpectEmpty)
{
  int v1; // eax

  v1 = 0;
  if ( TSListTests::NUM_TEST > 0 )
  {
    while ( *(_DWORD *)&TSListTests::g_pTestBuckets[4 * v1] == 0 )
    {
      if ( ++v1 >= TSListTests::NUM_TEST )
        goto LABEL_7;
    }
    Msg(pMsgFormat: "Test bucket %d has an invalid value %d\n", v1, *(_DWORD *)&TSListTests::g_pTestBuckets[4 * v1]);
    if ( Plat_IsInDebugSession() )
      __debugbreak();
  }
LABEL_7:
  if ( TSListTests::g_nPops.m_value == TSListTests::g_nPushes.m_value )
  {
    if ( TSListTests::g_pTestOps->Validate(this: TSListTests::g_pTestOps) )
    {
      if ( !bExpectEmpty || TSListTests::g_pTestOps->IsEmpty(this: TSListTests::g_pTestOps) )
        Msg(pMsgFormat: "pass\n");
      else
        Msg(pMsgFormat: "FAIL: !IsEmpty()\n");
    }
    else
    {
      Msg(pMsgFormat: "FAIL: !Validate()\n");
    }
  }
  else
  {
    Msg(pMsgFormat: "FAIL: Not all items popped\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010170
// Name: void TSListTests::PushPopTest(void)
// Source: json
//------------------------------------------------------------------------------
void __fastcall TSListTests::PushPopTest(int a1)
{
  bool (__thiscall *Pop)(TSListTests::CTestOps *, int *); // edx
  bool (__thiscall *v2)(TSListTests::CTestOps *, int *); // edx
  int value; // [esp+0h] [ebp-4h] BYREF

  value = a1;
  Msg(pMsgFormat: "%s test: single thread push/pop, in order... ", TSListTests::g_pListType);
  memset(dst: TSListTests::g_pTestBuckets, value: 0, count: 4 * TSListTests::NUM_TEST);
  _InterlockedExchange(&TSListTests::g_nTested.m_value, 0);
  while ( TSListTests::g_nTested.m_value < TSListTests::NUM_TEST )
  {
    value = _InterlockedIncrement(&TSListTests::g_nTested.m_value) - 1;
    TSListTests::g_pTestOps->Push(this: TSListTests::g_pTestOps, a2: value);
    if ( value < TSListTests::NUM_TEST )
      _InterlockedExchangeAdd((volatile signed __int32 *)&TSListTests::g_pTestBuckets[4 * value], 1u);
  }
  ((void (__thiscall *)(TSListTests::CTestOps *, int))TSListTests::g_pTestOps->Validate)(
    a1: TSListTests::g_pTestOps,
    a2: value);
  Pop = TSListTests::g_pTestOps->Pop;
  value = (int)&value;
  if ( ((unsigned __int8 (__thiscall *)(TSListTests::CTestOps *))Pop)(a1: TSListTests::g_pTestOps) != 0 )
  {
    do
    {
      if ( value < TSListTests::NUM_TEST )
        _InterlockedExchangeAdd((volatile signed __int32 *)&TSListTests::g_pTestBuckets[4 * value], 0xFFFFFFFF);
      v2 = TSListTests::g_pTestOps->Pop;
      value = (int)&value;
    }
    while ( ((unsigned __int8 (__thiscall *)(TSListTests::CTestOps *))v2)(a1: TSListTests::g_pTestOps) != 0 );
  }
  TSListTests::TestEnd(bExpectEmpty: true);
}

//------------------------------------------------------------------------------
// Address: 0x10010270
// Name: void TSListTests::PushPopInterleavedTestGuts(void)
// Source: json
//------------------------------------------------------------------------------
void __fastcall TSListTests::PushPopInterleavedTestGuts(int a1)
{
  bool v1; // zf
  signed int v2; // eax
  int v3; // eax
  int value; // [esp+0h] [ebp-4h] BYREF

  value = a1;
  do
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v2 = rand() & 0x80000001;
        v1 = v2 == 0;
        if ( v2 < 0 )
          v1 = (((_BYTE)v2 - 1) | 0xFFFFFFFE) == -1;
        if ( !v1 )
          break;
        v3 = _InterlockedExchangeAdd(&TSListTests::g_nTested.m_value, 1u);
        value = v3;
        if ( v3 >= TSListTests::NUM_TEST )
          break;
        TSListTests::g_pTestOps->Push(this: TSListTests::g_pTestOps, a2: v3);
        if ( value < TSListTests::NUM_TEST )
          _InterlockedExchangeAdd((volatile signed __int32 *)&TSListTests::g_pTestBuckets[4 * value], 1u);
      }
      if ( !TSListTests::g_pTestOps->Pop(this: TSListTests::g_pTestOps, a2: &value) )
        break;
      if ( value < TSListTests::NUM_TEST )
        _InterlockedExchangeAdd((volatile signed __int32 *)&TSListTests::g_pTestBuckets[4 * value], 0xFFFFFFFF);
    }
  }
  while ( TSListTests::g_nTested.m_value < TSListTests::NUM_TEST );
}

//------------------------------------------------------------------------------
// Address: 0x10010320
// Name: public: CTSQueue<int,1,1>::CTSQueue<int,1,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<int,1,1> *__thiscall CTSQueue<int,1,1>::CTSQueue<int,1,1>(CTSQueue<int,1,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<int,1,1>::Node_t *v3; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    Error(pMsgFormat: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  p_m_FreeNodes->m_Head.value32.DepthAndSequence = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    Error(pMsgFormat: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    Error(pMsgFormat: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&this->m_Count.m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v3 = (CTSQueue<int,1,1>::Node_t *)operator new(size: 8u);
  this->m_Tail.value.pNode = v3;
  this->m_Head.value.pNode = v3;
  v3->pNext = (CTSQueue<int,1,1>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100103A0
// Name: public: bool CTSQueue<int,1,1>::Validate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTSQueue<int,1,1>::Validate(CTSQueue<int,1,1> *this)
{
  int v2; // edi
  char v3; // bl
  CTSQueue<int,1,1> *i; // eax

  v2 = 0;
  v3 = 1;
  if ( this->m_Count.m_value == 0 && this->m_Head.value.pNode != this->m_Tail.value.pNode )
  {
    if ( Plat_IsInDebugSession() )
      __debugbreak();
    v3 = 0;
  }
  for ( i = (CTSQueue<int,1,1> *)this->m_Head.value.pNode; i != this; ++v2 )
    i = (CTSQueue<int,1,1> *)i->m_Head.value.pNode;
  if ( v2 - 1 == this->m_Count.m_value )
  {
    if ( v3 == 0 )
      Msg(pMsgFormat: "Corrupt CTSQueueDetected");
    return v3;
  }
  else
  {
    if ( Plat_IsInDebugSession() )
      __debugbreak();
    Msg(pMsgFormat: "Corrupt CTSQueueDetected");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010420
// Name: private: virtual bool TSListTests::CQueueOps::Validate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall TSListTests::CQueueOps::Validate(TSListTests::CQueueOps *this)
{
  return CTSQueue<int,1,1>::Validate(this: &TSListTests::g_TestQueue);
}

//------------------------------------------------------------------------------
// Address: 0x10010430
// Name: private: virtual void TSListTests::CListOps::Push(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TSListTests::CListOps::Push(TSListTests::CListOps *this, int item)
{
  DWORD CurrentThreadId; // ecx
  TSLNodeBase_t *v3; // eax

  if ( TSListTests::g_bUseMutex )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != TSListTests::g_TestLock.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&TSListTests::g_TestLock, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(this: &TSListTests::g_TestLock, threadId: CurrentThreadId, nSpinSleepTime: 0);
    }
    else
    {
      ++TSListTests::g_TestLock.m_depth;
    }
  }
  v3 = (TSLNodeBase_t *)operator new(size: 8u);
  if ( v3 != nullptr )
    *((_DWORD *)&v3->Next + 1) = item;
  else
    v3 = nullptr;
  CTSListBase::Push(this: &TSListTests::g_TestList, pNode: v3);
  _InterlockedExchangeAdd(&TSListTests::g_nPushes.m_value, 1u);
}

//------------------------------------------------------------------------------
// Address: 0x100104B0
// Name: private: virtual bool TSListTests::CListOps::Pop(int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall TSListTests::CListOps::Pop(TSListTests::CListOps *this, int *pResult)
{
  DWORD CurrentThreadId; // ecx
  TSLNodeBase_t *v3; // eax

  if ( TSListTests::g_bUseMutex )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != TSListTests::g_TestLock.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&TSListTests::g_TestLock, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(this: &TSListTests::g_TestLock, threadId: CurrentThreadId, nSpinSleepTime: 0);
    }
    else
    {
      ++TSListTests::g_TestLock.m_depth;
    }
  }
  v3 = CTSListBase::Pop(this: &TSListTests::g_TestList);
  if ( v3 != nullptr )
  {
    *pResult = *((_DWORD *)&v3->Next + 1);
    operator delete(p: v3);
    if ( TSListTests::g_bUseMutex && --TSListTests::g_TestLock.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&TSListTests::g_TestLock, 0);
    _InterlockedExchangeAdd(&TSListTests::g_nPops.m_value, 1u);
    return 1;
  }
  else
  {
    if ( TSListTests::g_bUseMutex && --TSListTests::g_TestLock.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&TSListTests::g_TestLock, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010570
// Name: unsigned int TSListTests::PopThreadFunc(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TSListTests::PopThreadFunc()
{
  int ignored; // [esp+0h] [ebp-4h] BYREF

  _InterlockedExchangeAdd(&TSListTests::g_nPopThreads.m_value, 1u);
  _InterlockedExchangeAdd(&TSListTests::g_nThreads.m_value, 1u);
  while ( !TSListTests::g_bStart )
    ThreadSleep(duration: 1u);
  do
  {
    while ( TSListTests::g_pTestOps->Pop(this: TSListTests::g_pTestOps, a2: &ignored) )
      ;
    _mm_pause();
    ThreadSleep(duration: 0);
  }
  while ( TSListTests::g_nPushThreads.m_value != 0 );
  while ( TSListTests::g_pTestOps->Pop(this: TSListTests::g_pTestOps, a2: &ignored) )
  {
    _mm_pause();
    ThreadSleep(duration: 0);
  }
  _InterlockedExchangeAdd(&TSListTests::g_nThreads.m_value, 0xFFFFFFFF);
  _InterlockedExchangeAdd(&TSListTests::g_nPopThreads.m_value, 0xFFFFFFFF);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010640
// Name: unsigned int TSListTests::PushThreadFunc(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TSListTests::PushThreadFunc()
{
  _InterlockedExchangeAdd(&TSListTests::g_nPushThreads.m_value, 1u);
  _InterlockedExchangeAdd(&TSListTests::g_nThreads.m_value, 1u);
  while ( !TSListTests::g_bStart )
  {
    _mm_pause();
    ThreadSleep(duration: 0);
  }
  while ( _InterlockedIncrement(&TSListTests::g_nTested.m_value) <= TSListTests::NUM_TEST )
    TSListTests::g_pTestOps->Push(this: TSListTests::g_pTestOps, a2: TSListTests::g_nTested.m_value);
  _InterlockedExchangeAdd(&TSListTests::g_nThreads.m_value, 0xFFFFFFFF);
  _InterlockedExchangeAdd(&TSListTests::g_nPushThreads.m_value, 0xFFFFFFFF);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100106F0
// Name: unsigned int TSListTests::PushPopInterleavedTestThreadFunc(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TSListTests::PushPopInterleavedTestThreadFunc()
{
  int v0; // ecx

  ThreadSetDebugName(hThread: nullptr, pszName: "PushPopThread");
  v0 = _InterlockedExchangeAdd(&TSListTests::g_nThreads.m_value, 1u);
  while ( !TSListTests::g_bStart )
    ThreadSleep(duration: 0);
  TSListTests::PushPopInterleavedTestGuts(a1: v0);
  _InterlockedExchangeAdd(&TSListTests::g_nThreads.m_value, 0xFFFFFFFF);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010740
// Name: void TSListTests::MTPushMTPop(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TSListTests::MTPushMTPop(bool bDistribute)
{
  const char *v1; // eax
  int v2; // edi
  int v3; // esi
  void *v4; // esp
  ThreadHandle_t__ *SimpleThread; // edi
  int v6; // edx
  ThreadHandle_t__ *v7; // edi
  int v8; // edx
  int j; // edi
  _DWORD v10[3]; // [esp+0h] [ebp-14h]
  int i; // [esp+Ch] [ebp-8h]
  int ct; // [esp+10h] [ebp-4h]

  v1 = "distributed...";
  if ( !bDistribute )
    v1 = "no affinity...";
  Msg(pMsgFormat: "%s test: multithread push, multithread pop, %s", TSListTests::g_pListType, v1);
  TSListTests::TestStart();
  v2 = TSListTests::NUM_THREADS;
  v3 = 0;
  ct = 0;
  v4 = alloca(4 * TSListTests::NUM_THREADS);
  for ( i = 0; i < TSListTests::NUM_THREADS / 2; ++i )
  {
    SimpleThread = CreateSimpleThread(
                     pfnThread: (unsigned int (__cdecl *)(void *))TSListTests::PopThreadFunc,
                     pParam: nullptr,
                     stackSize: 0);
    v10[v3++] = SimpleThread;
    if ( bDistribute )
    {
      v6 = ct % TSListTests::NUM_PROCESSORS;
      ++ct;
      ThreadSetAffinity(hThread: SimpleThread, nAffinityMask: 1 << v6);
    }
    v2 = TSListTests::NUM_THREADS;
  }
  i = 0;
  if ( v2 / 2 > 0 )
  {
    do
    {
      v7 = CreateSimpleThread(
             pfnThread: (unsigned int (__cdecl *)(void *))TSListTests::PushThreadFunc,
             pParam: nullptr,
             stackSize: 0);
      v10[v3++] = v7;
      if ( bDistribute )
      {
        v8 = ct % TSListTests::NUM_PROCESSORS;
        ++ct;
        ThreadSetAffinity(hThread: v7, nAffinityMask: 1 << v8);
      }
      ++i;
    }
    while ( i < TSListTests::NUM_THREADS / 2 );
  }
  while ( TSListTests::g_nThreads.m_value < TSListTests::NUM_THREADS )
    ThreadSleep(duration: 0);
  TSListTests::g_bStart = true;
  while ( TSListTests::g_nThreads.m_value > 0 )
    ThreadSleep(duration: 0);
  TSListTests::TestEnd(bExpectEmpty: true);
  for ( j = 0; j < v3; ++j )
    ReleaseThreadHandle(hThread: (ThreadHandle_t__ *)v10[j]);
}

//------------------------------------------------------------------------------
// Address: 0x100108D0
// Name: void TSListTests::MTPushSeqPop(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TSListTests::MTPushSeqPop(char bDistribute)
{
  char v1; // bl
  const char *v2; // eax
  ThreadHandle_t__ **TestThreads; // edi
  int i; // esi

  v1 = bDistribute;
  v2 = "distributed...";
  if ( bDistribute == 0 )
    v2 = "no affinity...";
  Msg(pMsgFormat: "%s test: multithread push, sequential pop, %s", TSListTests::g_pListType, v2);
  TSListTests::TestStart();
  TestThreads = CreateTestThreads(
                  fnThread: (unsigned int (__cdecl *)(void *))TSListTests::PushThreadFunc,
                  numThreads: (ThreadHandle_t__ *)TSListTests::NUM_THREADS,
                  nProcessorsToDistribute: v1 != 0 ? TSListTests::NUM_PROCESSORS : 0);
  TSListTests::TestWait();
  TSListTests::g_pTestOps->Validate(this: TSListTests::g_pTestOps);
  for ( i = 0; TSListTests::g_pTestOps->Pop(this: TSListTests::g_pTestOps, a2: (int *)&bDistribute); ++i )
    ;
  if ( i != TSListTests::NUM_TEST )
  {
    Msg(pMsgFormat: "Pops != pushes?\n");
    if ( Plat_IsInDebugSession() )
      __debugbreak();
  }
  TSListTests::TestEnd(bExpectEmpty: true);
  JoinTestThreads(pHandles: TestThreads);
}

//------------------------------------------------------------------------------
// Address: 0x100109A0
// Name: void TSListTests::SeqPushMTPop(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TSListTests::SeqPushMTPop(bool bDistribute)
{
  const char *v1; // eax
  ThreadHandle_t__ **TestThreads; // esi

  v1 = "distributed...";
  if ( !bDistribute )
    v1 = "no affinity...";
  Msg(pMsgFormat: "%s test: sequential push, multithread pop, %s", TSListTests::g_pListType, v1);
  TSListTests::TestStart();
  while ( _InterlockedExchangeAdd(&TSListTests::g_nTested.m_value, 1u) < TSListTests::NUM_TEST )
    TSListTests::g_pTestOps->Push(this: TSListTests::g_pTestOps, a2: TSListTests::g_nTested.m_value);
  TestThreads = CreateTestThreads(
                  fnThread: (unsigned int (__cdecl *)(void *))TSListTests::PopThreadFunc,
                  numThreads: (ThreadHandle_t__ *)TSListTests::NUM_THREADS,
                  nProcessorsToDistribute: bDistribute ? TSListTests::NUM_PROCESSORS : 0);
  TSListTests::TestWait();
  TSListTests::TestEnd(bExpectEmpty: true);
  JoinTestThreads(pHandles: TestThreads);
}

//------------------------------------------------------------------------------
// Address: 0x10010A60
// Name: void RunSharedTests(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunSharedTests(int nTests)
{
  int v1; // ecx
  int v2; // eax
  int v3; // ecx
  unsigned int v4; // eax
  int v5; // ecx
  ThreadHandle_t__ *SimpleThread; // esi
  ThreadHandle_t__ **TestThreads; // edi
  ThreadHandle_t__ *v8; // esi
  ThreadHandle_t__ **v9; // edi
  unsigned int v10; // eax
  ThreadHandle_t__ **v11; // esi
  ThreadHandle_t__ *v12; // esi
  ThreadHandle_t__ **v13; // edi
  ThreadHandle_t__ *v14; // esi
  ThreadHandle_t__ **v15; // edi
  unsigned int v16; // eax
  ThreadHandle_t__ **v17; // esi
  ICpuTopology savedregs; // [esp+4h] [ebp+0h] BYREF

  TSListTests::NUM_PROCESSORS = GetCPUInformation(a1: &savedregs)->m_nLogicalProcessors;
  TSListTests::MAX_THREADS = 2 * TSListTests::NUM_PROCESSORS;
  TSListTests::g_pTestBuckets = (unsigned __int8 *)operator new(size: 4 * TSListTests::NUM_TEST);
  if ( nTests != 0 )
  {
    v1 = TSListTests::MAX_THREADS;
    do
    {
      --nTests;
      v2 = 2;
      TSListTests::NUM_THREADS = 2;
      if ( v1 >= 2 )
      {
        do
        {
          Msg(pMsgFormat: "\nTesting %d threads:\n", v2);
          TSListTests::PushPopTest(a1: v3);
          Msg(pMsgFormat: "%s test: single thread push/pop, interleaved... ", TSListTests::g_pListType);
          v4 = Plat_MSTime();
          srand(seed: v4);
          _InterlockedExchange(&TSListTests::g_nTested.m_value, 0);
          memset(dst: TSListTests::g_pTestBuckets, value: 0, count: 4 * TSListTests::NUM_TEST);
          TSListTests::PushPopInterleavedTestGuts(a1: v5);
          TSListTests::TestEnd(bExpectEmpty: true);
          TSListTests::SeqPushMTPop(bDistribute: false);
          Msg(
            pMsgFormat: "%s test: single thread push, multithread pop, %s",
            TSListTests::g_pListType,
            "no affinity...");
          _InterlockedExchange(&TSListTests::g_nTested.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nThreads.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nPushThreads.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nPopThreads.m_value, 0);
          TSListTests::g_bStart = false;
          _InterlockedExchange(&TSListTests::g_nPushes.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nPops.m_value, TSListTests::g_nPushes.m_value);
          memset(dst: TSListTests::g_pTestBuckets, value: 0, count: 4 * TSListTests::NUM_TEST);
          SimpleThread = CreateSimpleThread(
                           pfnThread: (unsigned int (__cdecl *)(void *))TSListTests::PushThreadFunc,
                           pParam: nullptr,
                           stackSize: 0);
          TestThreads = CreateTestThreads(
                          fnThread: (unsigned int (__cdecl *)(void *))TSListTests::PopThreadFunc,
                          numThreads: (ThreadHandle_t__ *)(TSListTests::NUM_THREADS - 1),
                          nProcessorsToDistribute: 0);
          while ( TSListTests::g_nThreads.m_value < TSListTests::NUM_THREADS )
            ThreadSleep(duration: 0);
          TSListTests::g_bStart = true;
          while ( TSListTests::g_nThreads.m_value > 0 )
            ThreadSleep(duration: 0);
          TSListTests::TestEnd(bExpectEmpty: true);
          JoinTestThreads(pHandles: TestThreads);
          ThreadJoin(hThread: SimpleThread, timeout: 0xFFFFFFFF);
          ReleaseThreadHandle(hThread: SimpleThread);
          TSListTests::MTPushSeqPop(bDistribute: 0);
          Msg(
            pMsgFormat: "%s test: multithread push, single thread pop, %s",
            TSListTests::g_pListType,
            "no affinity...");
          _InterlockedExchange(&TSListTests::g_nTested.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nThreads.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nPushThreads.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nPopThreads.m_value, 0);
          TSListTests::g_bStart = false;
          _InterlockedExchange(&TSListTests::g_nPushes.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nPops.m_value, TSListTests::g_nPushes.m_value);
          memset(dst: TSListTests::g_pTestBuckets, value: 0, count: 4 * TSListTests::NUM_TEST);
          v8 = CreateSimpleThread(
                 pfnThread: (unsigned int (__cdecl *)(void *))TSListTests::PopThreadFunc,
                 pParam: nullptr,
                 stackSize: 0);
          v9 = CreateTestThreads(
                 fnThread: (unsigned int (__cdecl *)(void *))TSListTests::PushThreadFunc,
                 numThreads: (ThreadHandle_t__ *)(TSListTests::NUM_THREADS - 1),
                 nProcessorsToDistribute: 0);
          while ( TSListTests::g_nThreads.m_value < TSListTests::NUM_THREADS )
            ThreadSleep(duration: 0);
          TSListTests::g_bStart = true;
          while ( TSListTests::g_nThreads.m_value > 0 )
            ThreadSleep(duration: 0);
          TSListTests::TestEnd(bExpectEmpty: true);
          JoinTestThreads(pHandles: v9);
          ThreadJoin(hThread: v8, timeout: 0xFFFFFFFF);
          ReleaseThreadHandle(hThread: v8);
          TSListTests::MTPushMTPop(bDistribute: false);
          Msg(pMsgFormat: "%s test: multithread interleaved push/pop, %s", TSListTests::g_pListType, "no affinity...");
          v10 = Plat_MSTime();
          srand(seed: v10);
          _InterlockedExchange(&TSListTests::g_nTested.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nThreads.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nPushThreads.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nPopThreads.m_value, 0);
          TSListTests::g_bStart = false;
          _InterlockedExchange(&TSListTests::g_nPushes.m_value, 0);
          _InterlockedExchange(&TSListTests::g_nPops.m_value, TSListTests::g_nPushes.m_value);
          memset(dst: TSListTests::g_pTestBuckets, value: 0, count: 4 * TSListTests::NUM_TEST);
          v11 = CreateTestThreads(
                  fnThread: (unsigned int (__cdecl *)(void *))TSListTests::PushPopInterleavedTestThreadFunc,
                  numThreads: (ThreadHandle_t__ *)TSListTests::NUM_THREADS,
                  nProcessorsToDistribute: 0);
          while ( TSListTests::g_nThreads.m_value < TSListTests::NUM_THREADS )
            ThreadSleep(duration: 0);
          TSListTests::g_bStart = true;
          while ( TSListTests::g_nThreads.m_value > 0 )
            ThreadSleep(duration: 0);
          TSListTests::TestEnd(bExpectEmpty: true);
          JoinTestThreads(pHandles: v11);
          if ( TSListTests::NUM_PROCESSORS > 1 )
          {
            TSListTests::SeqPushMTPop(bDistribute: true);
            Msg(
              pMsgFormat: "%s test: single thread push, multithread pop, %s",
              TSListTests::g_pListType,
              "distributed...");
            _InterlockedExchange(&TSListTests::g_nTested.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nThreads.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nPushThreads.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nPopThreads.m_value, 0);
            TSListTests::g_bStart = false;
            _InterlockedExchange(&TSListTests::g_nPushes.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nPops.m_value, TSListTests::g_nPushes.m_value);
            memset(dst: TSListTests::g_pTestBuckets, value: 0, count: 4 * TSListTests::NUM_TEST);
            v12 = CreateSimpleThread(
                    pfnThread: (unsigned int (__cdecl *)(void *))TSListTests::PushThreadFunc,
                    pParam: nullptr,
                    stackSize: 0);
            v13 = CreateTestThreads(
                    fnThread: (unsigned int (__cdecl *)(void *))TSListTests::PopThreadFunc,
                    numThreads: (ThreadHandle_t__ *)(TSListTests::NUM_THREADS - 1),
                    nProcessorsToDistribute: TSListTests::NUM_PROCESSORS);
            while ( TSListTests::g_nThreads.m_value < TSListTests::NUM_THREADS )
              ThreadSleep(duration: 0);
            TSListTests::g_bStart = true;
            while ( TSListTests::g_nThreads.m_value > 0 )
              ThreadSleep(duration: 0);
            TSListTests::TestEnd(bExpectEmpty: true);
            JoinTestThreads(pHandles: v13);
            ThreadJoin(hThread: v12, timeout: 0xFFFFFFFF);
            ReleaseThreadHandle(hThread: v12);
            TSListTests::MTPushSeqPop(bDistribute: 1);
            Msg(
              pMsgFormat: "%s test: multithread push, single thread pop, %s",
              TSListTests::g_pListType,
              "distributed...");
            _InterlockedExchange(&TSListTests::g_nTested.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nThreads.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nPushThreads.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nPopThreads.m_value, 0);
            TSListTests::g_bStart = false;
            _InterlockedExchange(&TSListTests::g_nPushes.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nPops.m_value, TSListTests::g_nPushes.m_value);
            memset(dst: TSListTests::g_pTestBuckets, value: 0, count: 4 * TSListTests::NUM_TEST);
            v14 = CreateSimpleThread(
                    pfnThread: (unsigned int (__cdecl *)(void *))TSListTests::PopThreadFunc,
                    pParam: nullptr,
                    stackSize: 0);
            v15 = CreateTestThreads(
                    fnThread: (unsigned int (__cdecl *)(void *))TSListTests::PushThreadFunc,
                    numThreads: (ThreadHandle_t__ *)(TSListTests::NUM_THREADS - 1),
                    nProcessorsToDistribute: TSListTests::NUM_PROCESSORS);
            while ( TSListTests::g_nThreads.m_value < TSListTests::NUM_THREADS )
              ThreadSleep(duration: 0);
            TSListTests::g_bStart = true;
            while ( TSListTests::g_nThreads.m_value > 0 )
              ThreadSleep(duration: 0);
            TSListTests::TestEnd(bExpectEmpty: true);
            JoinTestThreads(pHandles: v15);
            ThreadJoin(hThread: v14, timeout: 0xFFFFFFFF);
            ReleaseThreadHandle(hThread: v14);
            TSListTests::MTPushMTPop(bDistribute: true);
            Msg(pMsgFormat: "%s test: multithread interleaved push/pop, %s", TSListTests::g_pListType, "distributed...");
            v16 = Plat_MSTime();
            srand(seed: v16);
            _InterlockedExchange(&TSListTests::g_nTested.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nThreads.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nPushThreads.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nPopThreads.m_value, 0);
            TSListTests::g_bStart = false;
            _InterlockedExchange(&TSListTests::g_nPushes.m_value, 0);
            _InterlockedExchange(&TSListTests::g_nPops.m_value, TSListTests::g_nPushes.m_value);
            memset(dst: TSListTests::g_pTestBuckets, value: 0, count: 4 * TSListTests::NUM_TEST);
            v17 = CreateTestThreads(
                    fnThread: (unsigned int (__cdecl *)(void *))TSListTests::PushPopInterleavedTestThreadFunc,
                    numThreads: (ThreadHandle_t__ *)TSListTests::NUM_THREADS,
                    nProcessorsToDistribute: TSListTests::NUM_PROCESSORS);
            while ( TSListTests::g_nThreads.m_value < TSListTests::NUM_THREADS )
              ThreadSleep(duration: 0);
            TSListTests::g_bStart = true;
            while ( TSListTests::g_nThreads.m_value > 0 )
              ThreadSleep(duration: 0);
            TSListTests::TestEnd(bExpectEmpty: true);
            JoinTestThreads(pHandles: v17);
          }
          v1 = TSListTests::MAX_THREADS;
          v2 = 2 * TSListTests::NUM_THREADS;
          TSListTests::NUM_THREADS = v2;
        }
        while ( v2 <= TSListTests::MAX_THREADS );
      }
    }
    while ( nTests != 0 );
  }
  operator delete(p: TSListTests::g_pTestBuckets);
}

//------------------------------------------------------------------------------
// Address: 0x10011220
// Name: _RunTSListTests
// Source: json
//------------------------------------------------------------------------------
char __cdecl RunTSListTests(int nListSize, int nTests)
{
  TSLNodeBase_t *v3; // eax
  TSLNodeBase_t *Next; // esi

  TSListTests::NUM_TEST = nListSize;
  if ( nListSize <= 0xFFFF )
  {
    TSListTests::g_pTestOps = &TSListTests::g_ListOps;
    TSListTests::g_pListType = "CTSList";
    RunSharedTests(nTests);
    Msg(pMsgFormat: "Tests done, purging test memory...");
    v3 = CTSListBase::Detach(this: &TSListTests::g_TestList);
    if ( v3 != nullptr )
    {
      do
      {
        Next = v3->Next;
        operator delete(p: v3);
        v3 = Next;
      }
      while ( Next != nullptr );
    }
    Msg(pMsgFormat: "done\n");
    return 1;
  }
  else
  {
    Msg(pMsgFormat: "TSList cannot hold more that %d nodes\n", 0xFFFF);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100112B0
// Name: public: struct CTSQueue<int,1,1>::Node_t __near * CTSQueue<int,1,1>::Push(struct CTSQueue<int,1,1>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<int,1,1>::Node_t *__thiscall CTSQueue<int,1,1>::Push(
        CTSQueue<int,1,1> *this,
        CTSQueue<int,1,1>::Node_t *pNode)
{
  volatile signed __int32 *v3; // edi
  __int64 v5; // [esp-20h] [ebp-2Ch]
  __int64 v6; // [esp-20h] [ebp-2Ch]
  int i; // [esp-4h] [ebp-10h]

  pNode->pNext = (CTSQueue<int,1,1>::Node_t *)this;
  v3 = (volatile signed __int32 *)this->m_Tail.value.pNode;
  for ( i = this->m_Tail.value.sequence;
        (CTSQueue<int,1,1> *)_InterlockedCompareExchange(v3, (signed __int32)pNode, (signed __int32)this) != this;
        i = this->m_Tail.value.sequence )
  {
    HIDWORD(v5) = i + 1;
    LODWORD(v5) = *v3;
    ThreadInterlockedAssignIf64(
      pDest: (volatile __int64 *)&this->m_Tail,
      value: v5,
      comperand: __SPAIR64__(i, (unsigned int)v3));
    v3 = (volatile signed __int32 *)this->m_Tail.value.pNode;
  }
  HIDWORD(v6) = i + 1;
  LODWORD(v6) = pNode;
  ThreadInterlockedAssignIf64(
    pDest: (volatile __int64 *)&this->m_Tail,
    value: v6,
    comperand: __SPAIR64__(i, (unsigned int)v3));
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return (CTSQueue<int,1,1>::Node_t *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10011360
// Name: public: struct CTSQueue<int,1,1>::Node_t __near * CTSQueue<int,1,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<int,1,1>::Node_t *__thiscall CTSQueue<int,1,1>::Pop(CTSQueue<int,1,1> *this)
{
  CTSQueue<int,1,1> *v1; // esi
  CTSQueue<int,1,1> *pNext; // eax
  int sequence; // ecx
  int v4; // edi
  __int64 v6; // [esp-24h] [ebp-44h]
  __int64 v7; // [esp-24h] [ebp-44h]
  __int64 v8; // [esp-Ch] [ebp-2Ch]
  CTSQueue<int,1,1>::NodeLink_t *head_4; // [esp+4h] [ebp-1Ch]
  int *pHead; // [esp+Ch] [ebp-14h]
  CTSQueue<int,1,1>::NodeLink_t *pTailNode; // [esp+10h] [ebp-10h]

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
        while ( 1 )
        {
          do
          {
            HIDWORD(v8) = *pHead;
            LODWORD(v8) = v1->m_Head.value.pNode;
            pNext = (CTSQueue<int,1,1> *)v1->m_Head.value.pNode->pNext;
            sequence = pTailNode->value.sequence;
          }
          while ( pNext == nullptr );
          if ( pNext != (CTSQueue<int,1,1> *)-559038737 )
            break;
          Msg(pMsgFormat: "Bad node link detected\n");
        }
        if ( (CTSQueue<int,1,1>::Node_t *)v8 != head_4->value.pNode )
          break;
        if ( pNext == v1 )
          return nullptr;
        HIDWORD(v6) = sequence + 1;
        LODWORD(v6) = v1->m_Head.value.pNode->pNext;
        ThreadInterlockedAssignIf64(
          pDest: (volatile __int64 *)&v1->m_Tail,
          value: v6,
          comperand: __SPAIR64__(sequence, v8));
      }
    }
    while ( pNext == v1 );
    v4 = pNext->m_Head.value.sequence;
    HIDWORD(v7) = HIDWORD(v8) + 1;
    LODWORD(v7) = v1->m_Head.value.pNode->pNext;
    if ( ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)this, value: v7, comperand: v8) )
      break;
    v1 = this;
  }
  *(_DWORD *)v8 = -559038737;
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  *(_DWORD *)(v8 + 4) = v4;
  return (CTSQueue<int,1,1>::Node_t *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x10011450
// Name: public: void CTSQueue<int,1,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<int,1,1>::Purge(CTSQueue<int,1,1> *this)
{
  CTSQueue<int,1,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  __int64 v6; // [esp-10h] [ebp-1Ch]

  for ( i = CTSQueue<int,1,1>::Pop(this); i != nullptr; i = CTSQueue<int,1,1>::Pop(this) )
    operator delete(p: i);
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    DepthAndSequence = this->m_FreeNodes.m_Head.value32.DepthAndSequence;
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( 1 )
    {
      HIDWORD(v6) = DepthAndSequence - 1;
      LODWORD(v6) = Next->Next;
      if ( ThreadInterlockedAssignIf64(
             pDest: (volatile __int64 *)&this->m_FreeNodes,
             value: v6,
             comperand: __SPAIR64__(DepthAndSequence, (unsigned int)Next)) )
      {
        break;
      }
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      DepthAndSequence = this->m_FreeNodes.m_Head.value32.DepthAndSequence;
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    operator delete(p: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100114C0
// Name: private: virtual void TSListTests::CQueueOps::Push(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TSListTests::CQueueOps::Push(TSListTests::CQueueOps *this, int item)
{
  DWORD CurrentThreadId; // ecx
  CTSQueue<int,1,1>::Node_t *v3; // eax

  if ( TSListTests::g_bUseMutex )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != TSListTests::g_TestLock.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&TSListTests::g_TestLock, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(this: &TSListTests::g_TestLock, threadId: CurrentThreadId, nSpinSleepTime: 0);
    }
    else
    {
      ++TSListTests::g_TestLock.m_depth;
    }
  }
  v3 = (CTSQueue<int,1,1>::Node_t *)CTSListBase::Pop(this: &TSListTests::g_TestQueue.m_FreeNodes);
  if ( v3 != nullptr )
  {
    v3->elem = item;
  }
  else
  {
    v3 = (CTSQueue<int,1,1>::Node_t *)operator new(size: 8u);
    if ( v3 != nullptr )
      v3->elem = item;
    else
      v3 = nullptr;
  }
  CTSQueue<int,1,1>::Push(this: &TSListTests::g_TestQueue, pNode: v3);
  if ( TSListTests::g_bUseMutex && --TSListTests::g_TestLock.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&TSListTests::g_TestLock, 0);
  _InterlockedExchangeAdd(&TSListTests::g_nPushes.m_value, 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10011580
// Name: private: virtual bool TSListTests::CQueueOps::Pop(int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall TSListTests::CQueueOps::Pop(TSListTests::CQueueOps *this, int *pResult)
{
  DWORD CurrentThreadId; // ecx
  CTSQueue<int,1,1>::Node_t *v3; // eax

  if ( TSListTests::g_bUseMutex )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != TSListTests::g_TestLock.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&TSListTests::g_TestLock, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(this: &TSListTests::g_TestLock, threadId: CurrentThreadId, nSpinSleepTime: 0);
    }
    else
    {
      ++TSListTests::g_TestLock.m_depth;
    }
  }
  v3 = CTSQueue<int,1,1>::Pop(this: &TSListTests::g_TestQueue);
  if ( v3 != nullptr )
  {
    *pResult = v3->elem;
    CTSListBase::Push(this: &TSListTests::g_TestQueue.m_FreeNodes, pNode: (TSLNodeBase_t *)v3);
    if ( TSListTests::g_bUseMutex && --TSListTests::g_TestLock.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&TSListTests::g_TestLock, 0);
    _InterlockedExchangeAdd(&TSListTests::g_nPops.m_value, 1u);
    return 1;
  }
  else
  {
    if ( TSListTests::g_bUseMutex && --TSListTests::g_TestLock.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&TSListTests::g_TestLock, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011650
// Name: _RunTSQueueTests
// Source: json
//------------------------------------------------------------------------------
char __cdecl RunTSQueueTests(int nListSize, int nTests)
{
  TSListTests::NUM_TEST = nListSize;
  TSListTests::g_pTestOps = &TSListTests::g_QueueOps;
  TSListTests::g_pListType = "CTSQueue";
  RunSharedTests(nTests);
  Msg(pMsgFormat: "Tests done, purging test memory...");
  CTSQueue<int,1,1>::Purge(this: &TSListTests::g_TestQueue);
  Msg(pMsgFormat: "done\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B310
// Name: TSListTests::_dynamic_initializer_for__g_nTested__
// Source: json
//------------------------------------------------------------------------------
void TSListTests::_dynamic_initializer_for__g_nTested__()
{
  TSListTests::g_nTested.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B320
// Name: TSListTests::_dynamic_initializer_for__g_nThreads__
// Source: json
//------------------------------------------------------------------------------
void TSListTests::_dynamic_initializer_for__g_nThreads__()
{
  TSListTests::g_nThreads.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B330
// Name: TSListTests::_dynamic_initializer_for__g_nPushThreads__
// Source: json
//------------------------------------------------------------------------------
void TSListTests::_dynamic_initializer_for__g_nPushThreads__()
{
  TSListTests::g_nPushThreads.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B340
// Name: TSListTests::_dynamic_initializer_for__g_nPopThreads__
// Source: json
//------------------------------------------------------------------------------
void TSListTests::_dynamic_initializer_for__g_nPopThreads__()
{
  TSListTests::g_nPopThreads.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B350
// Name: TSListTests::_dynamic_initializer_for__g_nPushes__
// Source: json
//------------------------------------------------------------------------------
void TSListTests::_dynamic_initializer_for__g_nPushes__()
{
  TSListTests::g_nPushes.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B360
// Name: TSListTests::_dynamic_initializer_for__g_nPops__
// Source: json
//------------------------------------------------------------------------------
void TSListTests::_dynamic_initializer_for__g_nPops__()
{
  TSListTests::g_nPops.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B370
// Name: TSListTests::_dynamic_initializer_for__g_TestQueue__
// Source: json
//------------------------------------------------------------------------------
int TSListTests::_dynamic_initializer_for__g_TestQueue__()
{
  CTSQueue<int,1,1>::CTSQueue<int,1,1>(this: &TSListTests::g_TestQueue);
  return atexit(func: TSListTests::_dynamic_atexit_destructor_for__g_TestQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B390
// Name: TSListTests::_dynamic_initializer_for__g_TestList__
// Source: json
//------------------------------------------------------------------------------
int TSListTests::_dynamic_initializer_for__g_TestList__()
{
  if ( ((unsigned __int8)&TSListTests::g_TestList & 7) != 0 )
  {
    Error(pMsgFormat: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  TSListTests::g_TestList = 0;
  return atexit(func: TSListTests::_dynamic_atexit_destructor_for__g_TestList__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B3C0
// Name: TSListTests::_dynamic_initializer_for__g_Test__
// Source: json
//------------------------------------------------------------------------------
int TSListTests::_dynamic_initializer_for__g_Test__()
{
  if ( ((unsigned __int8)&TSListTests::g_Test & 7) != 0 )
  {
    Error(pMsgFormat: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  TSListTests::g_Test = 0;
  return atexit(func: TSListTests::_dynamic_atexit_destructor_for__g_Test__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B3F0
// Name: TSListTests::_dynamic_initializer_for__g_TestLock__
// Source: json
//------------------------------------------------------------------------------
int TSListTests::_dynamic_initializer_for__g_TestLock__()
{
  TSListTests::g_TestLock.m_ownerID = 0;
  TSListTests::g_TestLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B6F0
// Name: TSListTests::_dynamic_atexit_destructor_for__g_Test__
// Source: json
//------------------------------------------------------------------------------
void __cdecl TSListTests::_dynamic_atexit_destructor_for__g_Test__()
{
  CTSListBase::Detach(this: &TSListTests::g_Test);
}

//------------------------------------------------------------------------------
// Address: 0x1002B700
// Name: TSListTests::_dynamic_atexit_destructor_for__g_TestList__
// Source: json
//------------------------------------------------------------------------------
void __cdecl TSListTests::_dynamic_atexit_destructor_for__g_TestList__()
{
  TSLNodeBase_t *v0; // eax
  TSLNodeBase_t *Next; // esi

  v0 = CTSListBase::Detach(this: &TSListTests::g_TestList);
  if ( v0 != nullptr )
  {
    do
    {
      Next = v0->Next;
      operator delete(p: v0);
      v0 = Next;
    }
    while ( Next != nullptr );
  }
  CTSListBase::Detach(this: &TSListTests::g_TestList);
}

//------------------------------------------------------------------------------
// Address: 0x1002B730
// Name: TSListTests::_dynamic_atexit_destructor_for__g_TestQueue__
// Source: json
//------------------------------------------------------------------------------
void __cdecl TSListTests::_dynamic_atexit_destructor_for__g_TestQueue__()
{
  CTSQueue<int,1,1>::Purge(this: &TSListTests::g_TestQueue);
  operator delete(p: TSListTests::g_TestQueue.m_Head.value.pNode);
  CTSListBase::Detach(this: &TSListTests::g_TestQueue.m_FreeNodes);
}

//------------------------------------------------------------------------------
// Address: 0x1002B400
// Name: _dynamic_initializer_for__g_VProfCurrentProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VProfCurrentProfile__()
{
  CVProfile::CVProfile(this: &g_VProfCurrentProfile);
  return atexit(func: dynamic_atexit_destructor_for__g_VProfCurrentProfile__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B420
// Name: _dynamic_initializer_for__g_TimesLessChildren__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TimesLessChildren__()
{
  std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *v0; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-10h] BYREF
  char *_What; // [esp+Ch] [ebp-4h] BYREF

  v0 = (std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *)operator new(size: 0x28u);
  if ( v0 == nullptr )
  {
    _What = nullptr;
    std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  g_TimesLessChildren._Myhead = v0;
  v0->_Left = v0;
  g_TimesLessChildren._Myhead->_Parent = g_TimesLessChildren._Myhead;
  g_TimesLessChildren._Myhead->_Right = g_TimesLessChildren._Myhead;
  g_TimesLessChildren._Myhead->_Color = 1;
  g_TimesLessChildren._Myhead->_Isnil = 1;
  return atexit(func: dynamic_atexit_destructor_for__g_TimesLessChildren__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B4A0
// Name: _dynamic_initializer_for__g_TimeSumsMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TimeSumsMap__()
{
  std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *v0; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-10h] BYREF
  char *_What; // [esp+Ch] [ebp-4h] BYREF

  v0 = (std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *)operator new(size: 0x18u);
  if ( v0 == nullptr )
  {
    _What = nullptr;
    std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  g_TimeSumsMap._Myhead = v0;
  v0->_Left = v0;
  g_TimeSumsMap._Myhead->_Parent = g_TimeSumsMap._Myhead;
  g_TimeSumsMap._Myhead->_Right = g_TimeSumsMap._Myhead;
  g_TimeSumsMap._Myhead->_Color = 1;
  g_TimeSumsMap._Myhead->_Isnil = 1;
  return atexit(func: dynamic_atexit_destructor_for__g_TimeSumsMap__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B520
// Name: _dynamic_initializer_for__g_TimeSums__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TimeSums__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_TimeSums__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B530
// Name: _dynamic_initializer_for__magic_init_mutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__magic_init_mutex__()
{
  magic_init_mutex.m_ownerID = 0;
  magic_init_mutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B540
// Name: dynamic_initializer_for___gm_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___gm_()
{
  gm_.mutex.m_ownerID = 0;
  gm_.mutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B760
// Name: _dynamic_atexit_destructor_for__g_VProfCurrentProfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VProfCurrentProfile__()
{
  CVProfile::Term(this: &g_VProfCurrentProfile);
  CL2Cache::~CL2Cache(this: &g_VProfCurrentProfile.m_Root.m_L2Cache);
}

//------------------------------------------------------------------------------
// Address: 0x1002B780
// Name: _dynamic_atexit_destructor_for__g_TimeSums__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TimeSums__()
{
  if ( g_TimeSums._Myfirst != nullptr )
    operator delete(p: g_TimeSums._Myfirst);
  g_TimeSums._Myfirst = nullptr;
  g_TimeSums._Mylast = nullptr;
  g_TimeSums._Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002B7C0
// Name: _dynamic_atexit_destructor_for__g_TimesLessChildren__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall dynamic_atexit_destructor_for__g_TimesLessChildren__(
        std::_Tree_nod<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> >::_Node *this)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > > result; // [esp+0h] [ebp-4h] BYREF

  result._Ptr = this;
  std::_Tree<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double>>,0>>::erase(
    this: &g_TimesLessChildren,
    &result,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > >)g_TimesLessChildren._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<CVProfNode *,double,std::less<CVProfNode *>,std::allocator<std::pair<CVProfNode * const,double> >,0> > >)g_TimesLessChildren._Myhead);
  operator delete(p: g_TimesLessChildren._Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x1002B7F0
// Name: _dynamic_atexit_destructor_for__g_TimeSumsMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall dynamic_atexit_destructor_for__g_TimeSumsMap__(
        std::_Tree_nod<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> >::_Node *this)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > > result; // [esp+0h] [ebp-4h] BYREF

  result._Ptr = this;
  std::_Tree<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int>>,0>>::erase(
    this: &g_TimeSumsMap,
    &result,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > >)g_TimeSumsMap._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<char const *,unsigned int,std::less<char const *>,std::allocator<std::pair<char const * const,unsigned int> >,0> > >)g_TimeSumsMap._Myhead);
  operator delete(p: g_TimeSumsMap._Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x1002B81E
// Name: _operator_new_::_6_::_dynamic_atexit_destructor_for__nomem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator_new_::_6_::_dynamic_atexit_destructor_for__nomem__()
{
  nomem.__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
  std::exception::~exception(this: &nomem);
}
