// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/threadtools.cpp
// Functions: 92
// ============================================================

#include "tier0\threadtools.h"

//------------------------------------------------------------------------------
// Address: 0x100010B0
// Name: public: class GenericThreadLocals::CThreadLocalBase __near & GenericThreadLocals::CThreadLocalBase::operator=(class GenericThreadLocals::CThreadLocalBase const __near &)
// Source: json
//------------------------------------------------------------------------------
GenericThreadLocals::CThreadLocalBase *__thiscall GenericThreadLocals::CThreadLocalBase::operator=(
        GenericThreadLocals::CThreadLocalBase *this,
        const GenericThreadLocals::CThreadLocalBase *__that)
{
  this->m_index = __that->m_index;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: public: bool CThreadMutex::TryLock(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThreadMutex::TryLock(CThreadMutex *this)
{
  return ?TryLock@CThreadMutex@@QAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001140
// Name: public: void CThreadRWLock::LockForWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadRWLock::LockForWrite(CThreadRWLock *this)
{
  ?LockForWrite@CThreadRWLock@@QAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001150
// Name: public: void CThreadRWLock::UnlockWrite(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadRWLock::UnlockWrite(CThreadRWLock *this)
{
  ?UnlockWrite@CThreadRWLock@@QAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000E240
// Name: _ThreadSleep
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?Sleep@CThread@@SAXI@Z'
void __cdecl ThreadSleep(DWORD duration)
{
  Sleep(dwMilliseconds: duration);
}

//------------------------------------------------------------------------------
// Address: 0x1000E250
// Name: _ThreadGetCurrentHandle
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
HANDLE __stdcall ThreadGetCurrentHandle()
{
  return GetCurrentThread();
}

//------------------------------------------------------------------------------
// Address: 0x1000E260
// Name: _ThreadGetPriority
// Source: json
//------------------------------------------------------------------------------
int __cdecl ThreadGetPriority(ThreadHandle_t__ *hThread)
{
  ThreadHandle_t__ *CurrentThread; // eax

  CurrentThread = hThread;
  if ( hThread == nullptr )
    CurrentThread = (ThreadHandle_t__ *)GetCurrentThread();
  return GetThreadPriority(hThread: CurrentThread);
}

//------------------------------------------------------------------------------
// Address: 0x1000E280
// Name: _ThreadSetPriority
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ThreadSetPriority(ThreadHandle_t__ *hThread, int priority)
{
  ThreadHandle_t__ *CurrentThread; // eax

  CurrentThread = hThread;
  if ( hThread == nullptr )
    CurrentThread = (ThreadHandle_t__ *)GetCurrentThread();
  return SetThreadPriority(hThread: CurrentThread, nPriority: priority);
}

//------------------------------------------------------------------------------
// Address: 0x1000E2B0
// Name: _ThreadSetAffinity
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadSetAffinity(ThreadHandle_t__ *hThread, DWORD_PTR nAffinityMask)
{
  ThreadHandle_t__ *CurrentThread; // eax

  CurrentThread = hThread;
  if ( hThread == nullptr )
    CurrentThread = (ThreadHandle_t__ *)GetCurrentThread();
  SetThreadAffinityMask(hThread: CurrentThread, dwThreadAffinityMask: nAffinityMask);
}

//------------------------------------------------------------------------------
// Address: 0x1000E2D0
// Name: _ThreadInMainThread
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ThreadInMainThread()
{
  return GetCurrentThreadId() == g_ThreadMainThreadID;
}

//------------------------------------------------------------------------------
// Address: 0x1000E2F0
// Name: _DeclareCurrentThreadIsMainThread
// Source: json
//------------------------------------------------------------------------------
DWORD DeclareCurrentThreadIsMainThread()
{
  DWORD result; // eax

  result = GetCurrentThreadId();
  g_ThreadMainThreadID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E300
// Name: _ThreadJoin
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ThreadJoin(ThreadHandle_t__ *hThread, DWORD timeout)
{
  bool result; // al
  DWORD v3; // eax

  result = false;
  if ( hThread != nullptr )
  {
    v3 = WaitForSingleObject(hHandle: hThread, dwMilliseconds: timeout);
    if ( v3 != 258 && (v3 == 0 || v3 == -1 || GetLastError() == 0) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E340
// Name: _SetThreadedLoadLibraryFunc
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetThreadedLoadLibraryFunc(int (__cdecl *func)())
{
  s_ThreadedLoadLibraryFunc = func;
}

//------------------------------------------------------------------------------
// Address: 0x1000E350
// Name: _GetThreadedLoadLibraryFunc
// Source: json
//------------------------------------------------------------------------------
int (__cdecl *__cdecl GetThreadedLoadLibraryFunc())()
{
  return s_ThreadedLoadLibraryFunc;
}

//------------------------------------------------------------------------------
// Address: 0x1000E360
// Name: protected: CThreadSyncObject::CThreadSyncObject(void)
// Source: json
//------------------------------------------------------------------------------
CThreadSyncObject *__thiscall CThreadSyncObject::CThreadSyncObject(CThreadSyncObject *this)
{
  this->m_hSyncObject = nullptr;
  this->m_bCreatedHandle = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E370
// Name: public: CThreadSyncObject::~CThreadSyncObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSyncObject::~CThreadSyncObject(CThreadSyncObject *this)
{
  if ( this->m_hSyncObject != nullptr && this->m_bCreatedHandle )
    CloseHandle(hObject: this->m_hSyncObject);
}

//------------------------------------------------------------------------------
// Address: 0x1000E390
// Name: public: bool CThreadSyncObject::operator!(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadSyncObject::operator!(CThreadSyncObject *this)
{
  return this->m_hSyncObject == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000E3A0
// Name: public: bool CThreadEvent::Wait(unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?Wait@CThreadEvent@@QAE_NI@Z'
BOOL __thiscall CThreadEvent::Wait(CThreadEvent *this, DWORD dwTimeout)
{
  return WaitForSingleObject(hHandle: this->m_hSyncObject, dwMilliseconds: dwTimeout) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E3C0
// Name: public: static unsigned int CThreadSyncObject::WaitForMultiple(int,class CThreadSyncObject __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
DWORD __cdecl CThreadSyncObject::WaitForMultiple(
        unsigned int nObjects,
        CThreadSyncObject *pObjects,
        bool bWaitAll,
        DWORD dwTimeout)
{
  void *v4; // esp
  signed int i; // eax
  DWORD result; // eax
  HANDLE v7[2]; // [esp+0h] [ebp-8h] BYREF

  v4 = alloca(4 * nObjects);
  for ( i = 0; i < (int)nObjects; ++i )
    v7[i] = pObjects[i].m_hSyncObject;
  result = WaitForMultipleObjects(nCount: nObjects, lpHandles: v7, bWaitAll, dwMilliseconds: dwTimeout);
  if ( result != 258 && result >= nObjects )
  {
    if ( result < 0x80 || result - 128 >= nObjects )
    {
      if ( result != -1 )
      {
        Error(pMsgFormat: "Unknown return value (%lu) from WaitForMultipleObjects", result);
        return 0;
      }
    }
    else
    {
      Error(pMsgFormat: "Unhandled WAIT_ABANDONED in WaitForMultipleObjects");
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E460
// Name: public: static unsigned int CThreadEvent::WaitForMultiple(int,class CThreadEvent __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
DWORD __cdecl CThreadEvent::WaitForMultiple(
        unsigned int nObjects,
        CThreadSyncObject *pObjects,
        bool bWaitAll,
        DWORD dwTimeout)
{
  return CThreadSyncObject::WaitForMultiple(nObjects, pObjects, bWaitAll, dwTimeout);
}

//------------------------------------------------------------------------------
// Address: 0x1000E470
// Name: public: CThreadEvent::CThreadEvent(bool)
// Source: json
//------------------------------------------------------------------------------
CThreadEvent *__thiscall CThreadEvent::CThreadEvent(CThreadEvent *this, bool bManualReset)
{
  this->m_hSyncObject = nullptr;
  this->m_bCreatedHandle = false;
  this->m_hSyncObject = CreateEventA(lpEventAttributes: nullptr, bManualReset, bInitialState: false, lpName: nullptr);
  this->m_bCreatedHandle = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E4A0
// Name: public: CThreadEvent::CThreadEvent(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CThreadEvent *__thiscall CThreadEvent::CThreadEvent(
        CThreadEvent *this,
        const char *name,
        bool initialState,
        bool bManualReset)
{
  this->m_hSyncObject = nullptr;
  this->m_bCreatedHandle = false;
  this->m_hSyncObject = CreateEventA(
                          lpEventAttributes: nullptr,
                          bManualReset,
                          bInitialState: initialState,
                          lpName: name);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E4D0
// Name: public: static enum NamedEventResult_t CThreadEvent::CheckNamedEvent(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HANDLE __cdecl CThreadEvent::CheckNamedEvent(const char *name, DWORD dwTimeout)
{
  HANDLE result; // eax

  result = OpenEventA(dwDesiredAccess: 0x100000u, bInheritHandle: false, lpName: name);
  if ( result != nullptr )
    return (HANDLE)(2 - (WaitForSingleObject(hHandle: result, dwMilliseconds: dwTimeout) != 0));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E500
// Name: public: bool CThreadEvent::Set(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadEvent::Set(CThreadEvent *this)
{
  return SetEvent(hEvent: this->m_hSyncObject);
}

//------------------------------------------------------------------------------
// Address: 0x1000E510
// Name: public: bool CThreadEvent::Reset(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadEvent::Reset(CThreadEvent *this)
{
  return ResetEvent(hEvent: this->m_hSyncObject);
}

//------------------------------------------------------------------------------
// Address: 0x1000E520
// Name: public: CThreadSemaphore::CThreadSemaphore(int,int)
// Source: json
//------------------------------------------------------------------------------
CThreadSemaphore *__thiscall CThreadSemaphore::CThreadSemaphore(
        CThreadSemaphore *this,
        LONG initialValue,
        LONG maxValue)
{
  this->m_hSyncObject = nullptr;
  this->m_bCreatedHandle = false;
  if ( maxValue != 0 )
  {
    this->m_hSyncObject = CreateSemaphoreA(
                            lpSemaphoreAttributes: nullptr,
                            lInitialCount: initialValue,
                            lMaximumCount: maxValue,
                            lpName: nullptr);
    return this;
  }
  else
  {
    this->m_hSyncObject = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E560
// Name: public: bool CThreadSemaphore::Release(int,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadSemaphore::Release(CThreadSemaphore *this, LONG releaseCount, int *pPreviousCount)
{
  return ReleaseSemaphore(hSemaphore: this->m_hSyncObject, lReleaseCount: releaseCount, lpPreviousCount: pPreviousCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000E580
// Name: public: CThreadFullMutex::CThreadFullMutex(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CThreadFullMutex *__thiscall CThreadFullMutex::CThreadFullMutex(
        CThreadFullMutex *this,
        bool bEstablishInitialOwnership,
        const char *pszName)
{
  this->m_hSyncObject = nullptr;
  this->m_bCreatedHandle = false;
  this->m_hSyncObject = CreateMutexA(
                          lpMutexAttributes: nullptr,
                          bInitialOwner: bEstablishInitialOwnership,
                          lpName: pszName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E5B0
// Name: public: bool CThreadFullMutex::Release(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadFullMutex::Release(CThreadFullMutex *this)
{
  return ReleaseMutex(hMutex: this->m_hSyncObject);
}

//------------------------------------------------------------------------------
// Address: 0x1000E5C0
// Name: public: GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(void)
// Source: json
//------------------------------------------------------------------------------
GenericThreadLocals::CThreadLocalBase *__thiscall GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(
        GenericThreadLocals::CThreadLocalBase *this)
{
  DWORD v2; // eax

  v2 = TlsAlloc();
  this->m_index = v2;
  if ( v2 == -1 )
    Error(pMsgFormat: "Out of thread local storage!\n");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E5F0
// Name: public: GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(GenericThreadLocals::CThreadLocalBase *this)
{
  if ( this->m_index != -1 )
    TlsFree(dwTlsIndex: this->m_index);
  this->m_index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E610
// Name: public: void __near * GenericThreadLocals::CThreadLocalBase::Get(void)const
// Source: json
//------------------------------------------------------------------------------
LPVOID __thiscall GenericThreadLocals::CThreadLocalBase::Get(GenericThreadLocals::CThreadLocalBase *this)
{
  if ( this->m_index == -1 )
    return nullptr;
  else
    return TlsGetValue(dwTlsIndex: this->m_index);
}

//------------------------------------------------------------------------------
// Address: 0x1000E630
// Name: public: void GenericThreadLocals::CThreadLocalBase::Set(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GenericThreadLocals::CThreadLocalBase::Set(GenericThreadLocals::CThreadLocalBase *this, void *value)
{
  if ( this->m_index != -1 )
    TlsSetValue(dwTlsIndex: this->m_index, lpTlsValue: value);
}

//------------------------------------------------------------------------------
// Address: 0x1000E650
// Name: _ThreadInterlockedCompareExchange64
// Source: json
//------------------------------------------------------------------------------
__int64 __cdecl ThreadInterlockedCompareExchange64(volatile __int64 *pDest, __int64 value, __int64 comperand)
{
  return _InterlockedCompareExchange64(pDest, value, comperand);
}

//------------------------------------------------------------------------------
// Address: 0x1000E680
// Name: _ThreadInterlockedAssignIf64
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ThreadInterlockedAssignIf64(volatile __int64 *pDest, __int64 value, __int64 comperand)
{
  return comperand == _InterlockedCompareExchange64(pDest, value, comperand);
}

//------------------------------------------------------------------------------
// Address: 0x1000E6B0
// Name: _ThreadInterlockedExchange64
// Source: json
//------------------------------------------------------------------------------
__int64 __cdecl ThreadInterlockedExchange64(volatile __int64 *pDest, __int64 value)
{
  __int64 Old; // [esp+Ch] [ebp-18h]

  do
    Old = *pDest;
  while ( _InterlockedCompareExchange64(pDest, value, *pDest) != Old );
  return Old;
}

//------------------------------------------------------------------------------
// Address: 0x1000E710
// Name: public: CThreadMutex::CThreadMutex(void)
// Source: json
//------------------------------------------------------------------------------
CThreadMutex *__thiscall CThreadMutex::CThreadMutex(CThreadMutex *this)
{
  InitializeCriticalSectionAndSpinCount(lpCriticalSection: (LPCRITICAL_SECTION)this, dwSpinCount: 0xFA0u);
  this->m_lockCount = 0;
  this->m_currentOwnerID = 0;
  this->m_bTrace = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E730
// Name: public: CThreadMutex::~CThreadMutex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadMutex::~CThreadMutex(CThreadMutex *this)
{
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x1000E740
// Name: private: void CThreadFastMutex::Lock(unsigned int,unsigned int)volatile
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadFastMutex::Lock(CThreadFastMutex *this, unsigned int threadId, DWORD nSpinSleepTime)
{
  int v4; // ecx
  int v5; // ebx
  DWORD v6; // ebx
  HANDLE CurrentThread; // eax
  int v8; // ebx

  if ( nSpinSleepTime == -1 )
  {
    while ( threadId != this->m_ownerID
         && _InterlockedCompareExchange((volatile signed __int32 *)this, threadId, 0) != 0 )
      _mm_pause();
    ++this->m_depth;
  }
  else
  {
    v4 = 0x2000;
    while ( threadId != this->m_ownerID
         && _InterlockedCompareExchange((volatile signed __int32 *)this, threadId, 0) != 0 )
    {
      _mm_pause();
      if ( --v4 == 0 )
      {
        v5 = 0x2000;
        while ( threadId != this->m_ownerID
             && _InterlockedCompareExchange((volatile signed __int32 *)this, threadId, 0) != 0 )
        {
          _mm_pause();
          if ( v5 % 1024 == 0 )
            Sleep(dwMilliseconds: 0);
          if ( --v5 == 0 )
          {
            v6 = nSpinSleepTime;
            if ( nSpinSleepTime == 0 )
            {
              CurrentThread = GetCurrentThread();
              if ( GetThreadPriority(hThread: CurrentThread) <= 0 )
              {
LABEL_20:
                while ( threadId != this->m_ownerID
                     && _InterlockedCompareExchange((volatile signed __int32 *)this, threadId, 0) != 0 )
                {
                  _mm_pause();
                  Sleep(dwMilliseconds: v6);
                }
                goto LABEL_23;
              }
              nSpinSleepTime = 1;
            }
            v8 = 0x2000;
            while ( threadId != this->m_ownerID
                 && _InterlockedCompareExchange((volatile signed __int32 *)this, threadId, 0) != 0 )
            {
              _mm_pause();
              Sleep(dwMilliseconds: 0);
              if ( --v8 == 0 )
              {
                v6 = nSpinSleepTime;
                goto LABEL_20;
              }
            }
            goto LABEL_23;
          }
        }
        break;
      }
    }
LABEL_23:
    ++this->m_depth;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E870
// Name: public: void CThreadSpinRWLock::SpinLockForWrite(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSpinRWLock::SpinLockForWrite(CThreadSpinRWLock *this)
{
  int v2; // ecx
  int v3; // edi
  int v4; // edi

  if ( (this->m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)this, 0x10000, 0) != 0 )
  {
    v2 = 0x2000;
    while ( (this->m_lockInfo.m_i32 & 0x10000) != 0
         || _InterlockedCompareExchange((volatile signed __int32 *)this, 0x10000, 0) != 0 )
    {
      _mm_pause();
      if ( --v2 == 0 )
      {
        v3 = 0x2000;
        while ( (this->m_lockInfo.m_i32 & 0x10000) != 0
             || _InterlockedCompareExchange((volatile signed __int32 *)this, 0x10000, 0) != 0 )
        {
          _mm_pause();
          if ( v3 % 1024 == 0 )
            Sleep(dwMilliseconds: 0);
          if ( --v3 == 0 )
          {
            v4 = 0x8000;
            while ( (this->m_lockInfo.m_i32 & 0x10000) != 0
                 || _InterlockedCompareExchange((volatile signed __int32 *)this, 0x10000, 0) != 0 )
            {
              _mm_pause();
              Sleep(dwMilliseconds: 0);
              if ( --v4 == 0 )
              {
                while ( (this->m_lockInfo.m_i32 & 0x10000) != 0
                     || _InterlockedCompareExchange((volatile signed __int32 *)this, 0x10000, 0) != 0 )
                {
                  _mm_pause();
                  Sleep(dwMilliseconds: 1u);
                }
                goto LABEL_20;
              }
            }
            goto LABEL_20;
          }
        }
        break;
      }
    }
  }
LABEL_20:
  this->m_writerId = GetCurrentThreadId();
}

//------------------------------------------------------------------------------
// Address: 0x1000E970
// Name: public: void CThreadSpinRWLock::SpinLockForRead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSpinRWLock::SpinLockForRead(CThreadSpinRWLock *this)
{
  int v2; // edx
  signed __int32 m_i32; // ecx
  void (__stdcall *v4)(DWORD); // ebx
  int i; // edi
  signed __int32 v6; // ecx
  int j; // edi
  signed __int32 v8; // ecx
  signed __int32 v9; // ecx

  v2 = 0x2000;
  while ( 1 )
  {
    if ( (this->m_lockInfo.m_i32 & 0x10000) == 0 )
    {
      m_i32 = (unsigned __int16)this->m_lockInfo.m_i32;
      if ( _InterlockedCompareExchange((volatile signed __int32 *)this, m_i32 + 1, m_i32) == m_i32 )
        break;
    }
    _mm_pause();
    if ( --v2 == 0 )
    {
      v4 = Sleep;
      for ( i = 0x2000; i != 0; --i )
      {
        if ( (this->m_lockInfo.m_i32 & 0x10000) == 0 )
        {
          v6 = (unsigned __int16)this->m_lockInfo.m_i32;
          if ( _InterlockedCompareExchange((volatile signed __int32 *)this, v6 + 1, v6) == v6 )
            return;
          v4 = Sleep;
        }
        _mm_pause();
        if ( i % 1024 == 0 )
          v4(dwMilliseconds: 0);
      }
      for ( j = 0x8000; j != 0; --j )
      {
        if ( (this->m_lockInfo.m_i32 & 0x10000) == 0 )
        {
          v8 = (unsigned __int16)this->m_lockInfo.m_i32;
          if ( _InterlockedCompareExchange((volatile signed __int32 *)this, v8 + 1, v8) == v8 )
            return;
          v4 = Sleep;
        }
        _mm_pause();
        v4(dwMilliseconds: 0);
      }
      while ( 1 )
      {
        if ( (this->m_lockInfo.m_i32 & 0x10000) == 0 )
        {
          v9 = (unsigned __int16)this->m_lockInfo.m_i32;
          if ( _InterlockedCompareExchange((volatile signed __int32 *)this, v9 + 1, v9) == v9 )
            break;
        }
        _mm_pause();
        v4(dwMilliseconds: 1u);
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EA60
// Name: public: bool CThread::IsAlive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThread::IsAlive(CThread *this)
{
  void *m_hThread; // eax
  unsigned int dwExitCode; // [esp+0h] [ebp-4h] BYREF

  dwExitCode = (unsigned int)this;
  m_hThread = this->m_hThread;
  return m_hThread != nullptr && GetExitCodeThread(hThread: m_hThread, lpExitCode: &dwExitCode) && dwExitCode == 259;
}

//------------------------------------------------------------------------------
// Address: 0x1000EAA0
// Name: public: bool CThread::Join(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThread::Join(CThread *this, DWORD timeout)
{
  void *m_hThread; // eax
  DWORD v3; // eax
  bool result; // al

  m_hThread = this->m_hThread;
  result = true;
  if ( m_hThread != nullptr )
  {
    v3 = WaitForSingleObject(hHandle: m_hThread, dwMilliseconds: timeout);
    if ( v3 == 258 || v3 != 0 && v3 != -1 && GetLastError() != 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EAE0
// Name: protected: struct ThreadHandle_t__ __near * CThread::GetThreadHandle(void)const
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?GetThreadHandle@CThread@@IBEQAUThreadHandle_t__@@XZ'
ThreadHandle_t__ *__thiscall CThread::GetThreadHandle(CThread *this)
{
  return (ThreadHandle_t__ *)this->m_hThread;
}

//------------------------------------------------------------------------------
// Address: 0x1000EAF0
// Name: public: int CThread::GetResult(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThread::GetResult(CThread *this)
{
  return this->m_result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EB00
// Name: public: int CThread::GetPriority(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThread::GetPriority(CThread *this)
{
  return GetThreadPriority(hThread: this->m_hThread);
}

//------------------------------------------------------------------------------
// Address: 0x1000EB10
// Name: public: bool CThread::SetPriority(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThread::SetPriority(CThread *this, int priority)
{
  void *m_hThread; // eax

  m_hThread = this->m_hThread;
  if ( m_hThread == nullptr )
    m_hThread = GetCurrentThread();
  return SetThreadPriority(hThread: m_hThread, nPriority: priority);
}

//------------------------------------------------------------------------------
// Address: 0x1000EB40
// Name: public: unsigned int CThread::Suspend(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThread::Suspend(CThread *this)
{
  if ( GetCurrentThreadId() != this->m_threadId && Plat_IsInDebugSession() )
    __debugbreak();
  ResetEvent(hEvent: this->m_NotSuspendedEvent.m_hSyncObject);
  WaitForSingleObject(hHandle: this->m_NotSuspendedEvent.m_hSyncObject, dwMilliseconds: 0xFFFFFFFF);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000EB80
// Name: public: static void CThread::Yield(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CThread::Yield()
{
  Sleep(dwMilliseconds: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000EB90
// Name: protected: virtual bool CThread::WaitForCreateComplete(class CThreadEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThread::WaitForCreateComplete(CThread *this, CThreadEvent *pEvent)
{
  return WaitForSingleObject(hHandle: pEvent->m_hSyncObject, dwMilliseconds: 0xEA60u) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000EBB0
// Name: public: class CThreadEvent __near & CWorkerThread::GetCallHandle(void)
// Source: json
//------------------------------------------------------------------------------
CThreadEvent *__thiscall CWorkerThread::GetCallHandle(CWorkerThread *this)
{
  return &this->m_EventSend;
}

//------------------------------------------------------------------------------
// Address: 0x1000EBC0
// Name: public: int CWorkerThread::BoostPriority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::BoostPriority(CWorkerThread *this)
{
  int ThreadPriority; // edi
  void *m_hThread; // eax
  int v4; // ebx
  void *CurrentThread; // eax

  ThreadPriority = GetThreadPriority(hThread: this->m_hThread);
  m_hThread = this->m_hThread;
  if ( m_hThread == nullptr )
    m_hThread = GetCurrentThread();
  v4 = GetThreadPriority(hThread: m_hThread);
  if ( v4 > ThreadPriority )
  {
    CurrentThread = this->m_hThread;
    if ( CurrentThread == nullptr )
      CurrentThread = GetCurrentThread();
    SetThreadPriority(hThread: CurrentThread, nPriority: v4);
  }
  return ThreadPriority;
}

//------------------------------------------------------------------------------
// Address: 0x1000EC10
// Name: public: bool CWorkerThread::WaitForCall(unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerThread::WaitForCall(CWorkerThread *this, DWORD dwTimeout, unsigned int *pResult)
{
  bool result; // al

  result = WaitForSingleObject(hHandle: this->m_EventSend.m_hSyncObject, dwMilliseconds: dwTimeout) == 0;
  if ( pResult != nullptr )
    *pResult = this->m_Param;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EC40
// Name: public: void CWorkerThread::Reply(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerThread::Reply(CWorkerThread *this, unsigned int dw)
{
  void *m_hSyncObject; // [esp-4h] [ebp-8h]

  m_hSyncObject = this->m_EventSend.m_hSyncObject;
  this->m_Param = 0;
  this->m_ReturnVal = dw;
  ResetEvent(hEvent: m_hSyncObject);
  SetEvent(hEvent: this->m_EventComplete.m_hSyncObject);
}

//------------------------------------------------------------------------------
// Address: 0x1000EC70
// Name: AddThreadHandleToIDMap
// Source: json
//------------------------------------------------------------------------------
void __usercall AddThreadHandleToIDMap(void *hThread@<edi>, unsigned int threadID)
{
  CThreadHandleToIDMap *v2; // esi

  if ( hThread != nullptr )
  {
    v2 = (CThreadHandleToIDMap *)operator new(size: 0xCu);
    v2->m_hThread = hThread;
    v2->m_ThreadID = threadID;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex);
    v2->m_pNext = g_pThreadHandleToIDMaps;
    g_pThreadHandleToIDMaps = v2;
    ++g_nThreadHandleToIDMaps;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex);
    if ( g_nThreadHandleToIDMaps > 500 )
      Error(pMsgFormat: "ThreadHandleToIDMap overflow.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ECE0
// Name: RemoveThreadHandleToIDMap
// Source: json
//------------------------------------------------------------------------------
void __usercall RemoveThreadHandleToIDMap(void *hThread@<esi>)
{
  CThreadHandleToIDMap *v1; // eax
  CThreadHandleToIDMap **p_m_pNext; // ecx

  if ( hThread != nullptr )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex);
    if ( g_nThreadHandleToIDMaps <= 0 )
      Error(pMsgFormat: "ThreadHandleToIDMap underflow.");
    v1 = g_pThreadHandleToIDMaps;
    p_m_pNext = &g_pThreadHandleToIDMaps;
    if ( g_pThreadHandleToIDMaps != nullptr )
    {
      while ( v1->m_hThread != hThread )
      {
        p_m_pNext = &v1->m_pNext;
        v1 = v1->m_pNext;
        if ( v1 == nullptr )
          goto LABEL_9;
      }
      *p_m_pNext = v1->m_pNext;
      operator delete(p: v1);
      --g_nThreadHandleToIDMaps;
    }
LABEL_9:
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ED50
// Name: LookupThreadIDFromHandle
// Source: json
//------------------------------------------------------------------------------
DWORD __cdecl LookupThreadIDFromHandle(HANDLE hThread)
{
  void *v1; // ebx
  CThreadHandleToIDMap *v2; // esi
  char v3; // bl
  float flStartTime; // [esp+4h] [ebp-4h]

  v1 = hThread;
  if ( hThread == nullptr || hThread == GetCurrentThread() )
    return GetCurrentThreadId();
  flStartTime = Plat_FloatTime();
  if ( Plat_FloatTime() - flStartTime >= 2.0 )
  {
LABEL_12:
    Warning(pMsgFormat: "LookupThreadIDFromHandle couldn't find thread ID for handle.");
    return 0;
  }
  else
  {
    while ( 1 )
    {
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex);
      v2 = g_pThreadHandleToIDMaps;
      if ( g_pThreadHandleToIDMaps != nullptr )
      {
        while ( v2->m_hThread != v1 )
        {
          v2 = v2->m_pNext;
          if ( v2 == nullptr )
            goto LABEL_9;
        }
        v3 = 1;
      }
      else
      {
LABEL_9:
        v3 = 0;
      }
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex);
      if ( v3 != 0 )
        return v2->m_ThreadID;
      Sleep(dwMilliseconds: 1u);
      if ( Plat_FloatTime() - flStartTime >= 2.0 )
        goto LABEL_12;
      v1 = hThread;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EE10
// Name: _ReleaseThreadHandle
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ReleaseThreadHandle(ThreadHandle_t__ *hThread)
{
  bool v1; // bl

  v1 = CloseHandle(hObject: hThread);
  RemoveThreadHandleToIDMap(hThread);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1000EE30
// Name: _ThreadSetDebugName
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadSetDebugName(ThreadHandle_t__ *hThread, const char *pszName)
{
  ThreadSetDebugName::__l5::tagTHREADNAME_INFO info; // [esp+Ch] [ebp-28h] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  if ( Plat_IsInDebugSession() )
  {
    info.dwType = 4096;
    info.szName = pszName;
    info.dwThreadID = LookupThreadIDFromHandle(hThread);
    if ( info.dwThreadID != 0 )
    {
      info.dwFlags = 0;
      ms_exc.registration.TryLevel = 0;
      RaiseException(
        dwExceptionCode: 0x406D1388u,
        dwExceptionFlags: 0,
        nNumberOfArguments: 4u,
        lpArguments: &info.dwType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EEC0
// Name: public: static unsigned int CThreadSyncObject::WaitForMultiple(int,class CThreadSyncObject __near * __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
DWORD __cdecl CThreadSyncObject::WaitForMultiple(
        int nObjects,
        CThreadSyncObject **ppObjects,
        bool bWaitAll,
        DWORD dwTimeout)
{
  void *v4; // esp
  int v6; // [esp+0h] [ebp-Ch] BYREF
  int i; // [esp+4h] [ebp-8h]
  CThreadSyncObject *pObjects; // [esp+8h] [ebp-4h]

  v4 = alloca(8 * nObjects);
  v6 = (int)&v6;
  pObjects = (CThreadSyncObject *)&v6;
  for ( i = 0; i < nObjects; ++i )
    pObjects[i].m_hSyncObject = ppObjects[i]->m_hSyncObject;
  return CThreadSyncObject::WaitForMultiple(nObjects, pObjects, bWaitAll, dwTimeout);
}

//------------------------------------------------------------------------------
// Address: 0x1000EF40
// Name: public: static unsigned int CThreadEvent::WaitForMultiple(int,class CThreadEvent __near * __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
DWORD __cdecl CThreadEvent::WaitForMultiple(
        int nObjects,
        CThreadSyncObject **ppObjects,
        bool bWaitAll,
        DWORD dwTimeout)
{
  return CThreadSyncObject::WaitForMultiple(nObjects, ppObjects, bWaitAll, dwTimeout);
}

//------------------------------------------------------------------------------
// Address: 0x1000EF50
// Name: public: bool CThreadEvent::Check(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadEvent::Check(CThreadEvent *this)
{
  return WaitForSingleObject(hHandle: this->m_hSyncObject, dwMilliseconds: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000EF70
// Name: public: bool CThreadMutex::TryLock(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadMutex::TryLock(CThreadMutex *this)
{
  if ( DynTryEnterCriticalSection.m_pfn != nullptr )
    return DynTryEnterCriticalSection.m_pfn(a1: (_RTL_CRITICAL_SECTION *)this) != 0;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1000EF90
// Name: private: void CThreadRWLock::WaitForRead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::WaitForRead(CThreadRWLock *this)
{
  DWORD CurrentThreadId; // eax

  ++this->m_nPendingReaders;
  do
  {
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    WaitForSingleObject(hHandle: this->m_CanRead.m_hSyncObject, dwMilliseconds: 0xFFFFFFFF);
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(this: &this->m_mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
  }
  while ( this->m_nWriters != 0 );
  --this->m_nPendingReaders;
}

//------------------------------------------------------------------------------
// Address: 0x1000F000
// Name: public: void CThreadRWLock::LockForWrite(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::LockForWrite(CThreadRWLock *this)
{
  DWORD CurrentThreadId; // ecx
  char v3; // bl
  int m_nWriters; // eax

  CurrentThreadId = GetCurrentThreadId();
  v3 = 1;
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &this->m_mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  m_nWriters = this->m_nWriters;
  if ( m_nWriters == 0 && this->m_nActiveReaders == 0 )
    v3 = 0;
  this->m_nWriters = m_nWriters + 1;
  ResetEvent(hEvent: this->m_CanRead.m_hSyncObject);
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
  if ( v3 != 0 )
    WaitForSingleObject(hHandle: this->m_CanWrite.m_hSyncObject, dwMilliseconds: 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x1000F080
// Name: public: void CThreadRWLock::UnlockWrite(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::UnlockWrite(CThreadRWLock *this)
{
  DWORD CurrentThreadId; // ecx
  bool v3; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &this->m_mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  v3 = this->m_nWriters-- == 1;
  if ( v3 )
  {
    if ( this->m_nPendingReaders != 0 )
      SetEvent(hEvent: this->m_CanRead.m_hSyncObject);
  }
  else
  {
    SetEvent(hEvent: this->m_CanWrite.m_hSyncObject);
  }
  v3 = this->m_mutex.m_depth-- == 1;
  if ( v3 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000F0F0
// Name: public: unsigned int CThread::Resume(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThread::Resume(CThread *this)
{
  if ( WaitForSingleObject(hHandle: this->m_NotSuspendedEvent.m_hSyncObject, dwMilliseconds: 0) == 0 )
    DevWarning(pMsgFormat: "Called Resume() on a thread that is not suspended!\n");
  SetEvent(hEvent: this->m_NotSuspendedEvent.m_hSyncObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F120
// Name: public: bool CThread::Terminate(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThread::Terminate(CThread *this, DWORD exitCode)
{
  if ( !TerminateThread(hThread: this->m_hThread, dwExitCode: exitCode) )
    return 0;
  CloseHandle(hObject: this->m_hThread);
  RemoveThreadHandleToIDMap(hThread: this->m_hThread);
  this->m_hThread = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F170
// Name: public: static class CThread __near * CThread::GetCurrentCThread(void)
// Source: json
//------------------------------------------------------------------------------
CThread *__cdecl CThread::GetCurrentCThread()
{
  if ( g_pCurThread.m_index == -1 )
    return nullptr;
  else
    return (CThread *)TlsGetValue(dwTlsIndex: g_pCurThread.m_index);
}

//------------------------------------------------------------------------------
// Address: 0x1000F190
// Name: DefaultWaitFunc
// Source: json
//------------------------------------------------------------------------------
DWORD __cdecl DefaultWaitFunc(unsigned int nHandles, CThreadSyncObject **ppHandles, int bWaitAll, DWORD timeout)
{
  return CThreadSyncObject::WaitForMultiple(
           nObjects: nHandles,
           ppObjects: ppHandles,
           bWaitAll: bWaitAll != 0,
           dwTimeout: timeout);
}

//------------------------------------------------------------------------------
// Address: 0x1000F1C0
// Name: protected: int CWorkerThread::WaitForReply(unsigned int,unsigned int (*)(unsigned int,class CThreadEvent __near * __near *,int,unsigned int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::WaitForReply(
        CWorkerThread *this,
        unsigned int timeout,
        unsigned int (__cdecl *pfnWait)(unsigned int, CThreadEvent **, int, unsigned int))
{
  unsigned int v4; // edi
  bool v5; // bl
  unsigned int v6; // eax
  CThreadEvent *waits[2]; // [esp+Ch] [ebp-8h] BYREF

  if ( pfnWait == nullptr )
    pfnWait = (unsigned int (__cdecl *)(unsigned int, CThreadEvent **, int, unsigned int))DefaultWaitFunc;
  waits[0] = &this->m_EventComplete;
  waits[1] = &this->m_ExitEvent;
  v4 = timeout;
  v5 = Plat_IsInDebugSession();
  if ( timeout == -1 )
    v4 = 30000;
  do
  {
    if ( this->m_hThread == nullptr )
      goto LABEL_12;
    v6 = pfnWait(a1: 2u, a2: waits, a3: 0, a4: v4);
  }
  while ( v5 && timeout == -1 && v6 == 258 );
  if ( v6 != 0 )
  {
    if ( v6 == 258 )
    {
LABEL_13:
      this->m_ReturnVal = -2;
      return this->m_ReturnVal;
    }
    if ( v6 == 1 )
    {
LABEL_12:
      DevMsg(level: 2, pMsgFormat: "Thread failed to respond, probably exited\n");
      ResetEvent(hEvent: this->m_EventSend.m_hSyncObject);
      goto LABEL_13;
    }
    ResetEvent(hEvent: this->m_EventSend.m_hSyncObject);
    this->m_ReturnVal = -3;
  }
  return this->m_ReturnVal;
}

//------------------------------------------------------------------------------
// Address: 0x1000F280
// Name: public: bool CWorkerThread::WaitForCall(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerThread::WaitForCall(CWorkerThread *this, unsigned int *pResult)
{
  bool result; // al

  result = WaitForSingleObject(hHandle: this->m_EventSend.m_hSyncObject, dwMilliseconds: 0xFFFFFFFF) == 0;
  if ( pResult != nullptr )
    *pResult = this->m_Param;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F2B0
// Name: public: bool CWorkerThread::PeekCall(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkerThread::PeekCall(CWorkerThread *this, unsigned int *pParam)
{
  if ( WaitForSingleObject(hHandle: this->m_EventSend.m_hSyncObject, dwMilliseconds: 0) != 0 )
    return 0;
  if ( pParam != nullptr )
    *pParam = this->m_Param;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F2E0
// Name: _AllocateThreadID
// Source: json
//------------------------------------------------------------------------------
void AllocateThreadID()
{
  DWORD CurrentThreadId; // ecx
  int v1; // esi

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_ThreadIDMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_ThreadIDMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &s_ThreadIDMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++s_ThreadIDMutex.m_depth;
  }
  v1 = 1;
  while ( s_bThreadIDAllocated[v1] )
  {
    if ( ++v1 >= 128 )
    {
      Error(pMsgFormat: "Out of thread ids. Decrease the number of threads or increase MAX_THREAD_IDS\n");
      goto LABEL_9;
    }
  }
  if ( g_nThreadID.m_index != -1 )
    TlsSetValue(dwTlsIndex: g_nThreadID.m_index, lpTlsValue: (LPVOID)v1);
  s_bThreadIDAllocated[v1] = true;
LABEL_9:
  if ( --s_ThreadIDMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_ThreadIDMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000F380
// Name: _FreeThreadID
// Source: json
//------------------------------------------------------------------------------
int FreeThreadID()
{
  DWORD CurrentThreadId; // ecx
  LPVOID Value; // eax
  bool v2; // zf
  int result; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_ThreadIDMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_ThreadIDMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &s_ThreadIDMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++s_ThreadIDMutex.m_depth;
  }
  if ( g_nThreadID.m_index != -1 )
  {
    Value = TlsGetValue(dwTlsIndex: g_nThreadID.m_index);
    if ( Value != nullptr )
      s_bThreadIDAllocated[(_DWORD)Value] = false;
  }
  v2 = s_ThreadIDMutex.m_depth-- == 1;
  result = s_ThreadIDMutex.m_depth;
  if ( v2 )
    _InterlockedExchange((volatile __int32 *)&s_ThreadIDMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F400
// Name: ThreadProcConvert
// Source: json
//------------------------------------------------------------------------------
int __stdcall ThreadProcConvert(int (__cdecl **pParam)(int))
{
  int (__cdecl *v1)(int); // ebx
  int (__cdecl *v2)(int); // edi
  int v3; // esi

  v1 = pParam[1];
  v2 = *pParam;
  AllocateThreadID();
  operator delete(p: pParam);
  v3 = v2(a1: (int)v1);
  FreeThreadID();
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000F430
// Name: void JoinTestThreads(struct ThreadHandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl JoinTestThreads(ThreadHandle_t__ **pHandles)
{
  ThreadHandle_t__ **v2; // eax
  int v3; // edi
  ThreadHandle_t__ *v4; // eax
  DWORD v5; // eax
  ThreadHandle_t__ *v6; // esi
  ThreadHandle_t__ **v7; // [esp+8h] [ebp-4h]
  int nCount; // [esp+14h] [ebp+8h]

  v2 = pHandles - 1;
  v3 = 0;
  v7 = pHandles - 1;
  nCount = (int)*(pHandles - 1);
  if ( nCount > 0 )
  {
    do
    {
      v4 = pHandles[v3];
      if ( v4 != nullptr )
      {
        v5 = WaitForSingleObject(hHandle: v4, dwMilliseconds: 0xFFFFFFFF);
        if ( v5 != 258 && v5 != 0 && v5 != -1 )
          GetLastError();
      }
      v6 = pHandles[v3];
      CloseHandle(hObject: v6);
      RemoveThreadHandleToIDMap(hThread: v6);
      ++v3;
    }
    while ( v3 < nCount );
    v2 = v7;
  }
  operator delete[](p: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1000F4A0
// Name: _CreateSimpleThread
// Source: json
//------------------------------------------------------------------------------
ThreadHandle_t__ *__cdecl CreateSimpleThread(unsigned int (__cdecl *pfnThread)(void *), void *pParam, SIZE_T stackSize)
{
  _DWORD *v3; // eax
  HANDLE v4; // edi
  unsigned int threadID; // [esp+0h] [ebp-4h] BYREF

  v3 = operator new(size: 8u);
  if ( v3 != nullptr )
  {
    *v3 = pfnThread;
    v3[1] = pParam;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = CreateThread(
         lpThreadAttributes: nullptr,
         dwStackSize: stackSize,
         lpStartAddress: (LPTHREAD_START_ROUTINE)ThreadProcConvert,
         lpParameter: v3,
         dwCreationFlags: 0,
         lpThreadId: &threadID);
  AddThreadHandleToIDMap(hThread: v4, threadID);
  return (ThreadHandle_t__ *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1000F4F0
// Name: public: CThread::CThread(void)
// Source: json
//------------------------------------------------------------------------------
CThread *__thiscall CThread::CThread(CThread *this)
{
  CThreadMutex *p_m_Lock; // edi
  void *m_hSyncObject; // [esp-4h] [ebp-10h]

  p_m_Lock = &this->m_Lock;
  this->__vftable = (CThread_vtbl *)&CThread::`vftable';
  InitializeCriticalSectionAndSpinCount(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock, dwSpinCount: 0xFA0u);
  p_m_Lock->m_lockCount = 0;
  p_m_Lock->m_currentOwnerID = 0;
  p_m_Lock->m_bTrace = false;
  this->m_ExitEvent.m_hSyncObject = nullptr;
  this->m_ExitEvent.m_bCreatedHandle = false;
  this->m_ExitEvent.m_hSyncObject = CreateEventA(
                                      lpEventAttributes: nullptr,
                                      bManualReset: false,
                                      bInitialState: false,
                                      lpName: nullptr);
  this->m_ExitEvent.m_bCreatedHandle = true;
  this->m_hThread = nullptr;
  this->m_threadId = 0;
  this->m_result = 0;
  this->m_NotSuspendedEvent.m_hSyncObject = nullptr;
  this->m_NotSuspendedEvent.m_bCreatedHandle = false;
  this->m_NotSuspendedEvent.m_hSyncObject = CreateEventA(
                                              lpEventAttributes: nullptr,
                                              bManualReset: true,
                                              bInitialState: false,
                                              lpName: nullptr);
  this->m_NotSuspendedEvent.m_bCreatedHandle = true;
  m_hSyncObject = this->m_NotSuspendedEvent.m_hSyncObject;
  this->m_szName[0] = 0;
  SetEvent(hEvent: m_hSyncObject);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F570
// Name: public: char const __near * CThread::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CThread::GetName(CThread *this)
{
  CThreadMutex *p_m_Lock; // ebx

  p_m_Lock = &this->m_Lock;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock);
  if ( this->m_szName[0] == 0 )
  {
    _snprintf(string: this->m_szName, count: 0x1Fu, format: "Thread(%p/%p)", this, this->m_hThread);
    this->m_szName[31] = 0;
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_Lock);
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x1000F5B0
// Name: public: void CThread::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThread::SetName(CThread *this, char *pszName)
{
  CThreadMutex *p_m_Lock; // edi

  p_m_Lock = &this->m_Lock;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock);
  strncpy(dest: (unsigned __int8 *)this->m_szName, source: (unsigned __int8 *)pszName, count: 0x1Fu);
  this->m_szName[31] = 0;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_Lock);
}

//------------------------------------------------------------------------------
// Address: 0x1000F5F0
// Name: public: virtual bool CThread::Start(unsigned int,enum CThread::ThreadPriorityEnum_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThread::Start(CThread *this, SIZE_T nBytesStack, CThread::ThreadPriorityEnum_t nPriority)
{
  CThreadMutex *p_m_Lock; // edi
  void *m_hThread; // eax
  _DWORD *v7; // eax
  unsigned int (__stdcall *v8)(void *); // eax
  HANDLE Thread; // eax
  void *m_hSyncObject; // eax
  void *v11; // eax
  void *v12; // [esp-Ch] [ebp-38h]
  CThreadEvent createComplete; // [esp+18h] [ebp-14h] BYREF
  unsigned int ExitCode; // [esp+20h] [ebp-Ch] BYREF
  CAutoLockT<CThreadMutex> generated_id_4; // [esp+24h] [ebp-8h]
  bool bInitSuccess; // [esp+2Bh] [ebp-1h] BYREF
  bool nBytesStack_3; // [esp+37h] [ebp+Bh]

  p_m_Lock = &this->m_Lock;
  generated_id_4.m_lock = &this->m_Lock;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock);
  m_hThread = this->m_hThread;
  if ( m_hThread != nullptr && GetExitCodeThread(hThread: m_hThread, lpExitCode: &ExitCode) && ExitCode == 259 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_Lock);
    return false;
  }
  bInitSuccess = false;
  createComplete.m_hSyncObject = CreateEventA(
                                   lpEventAttributes: nullptr,
                                   bManualReset: false,
                                   bInitialState: false,
                                   lpName: nullptr);
  createComplete.m_bCreatedHandle = true;
  v7 = operator new(size: 0xCu);
  if ( v7 != nullptr )
  {
    *(_QWORD *)v7 = __PAIR64__(&createComplete, (unsigned int)this);
    v7[2] = &bInitSuccess;
  }
  else
  {
    v7 = nullptr;
  }
  v12 = v7;
  v8 = this->GetThreadProc(this);
  Thread = CreateThread(
             lpThreadAttributes: nullptr,
             dwStackSize: nBytesStack,
             lpStartAddress: v8,
             lpParameter: v12,
             dwCreationFlags: 0,
             lpThreadId: &this->m_threadId);
  this->m_hThread = Thread;
  if ( nPriority != PRIORITY_DEFAULT )
    SetThreadPriority(hThread: Thread, nPriority);
  if ( this->m_hThread == nullptr )
  {
    if ( createComplete.m_hSyncObject != nullptr && createComplete.m_bCreatedHandle )
      CloseHandle(hObject: createComplete.m_hSyncObject);
LABEL_24:
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)generated_id_4.m_lock);
    return false;
  }
  if ( !this->WaitForCreateComplete(this, a2: &createComplete) )
  {
    Msg(pMsgFormat: "Thread failed to initialize\n");
    CloseHandle(hObject: this->m_hThread);
    m_hSyncObject = createComplete.m_hSyncObject;
    this->m_hThread = nullptr;
    if ( m_hSyncObject != nullptr && createComplete.m_bCreatedHandle )
      CloseHandle(hObject: m_hSyncObject);
    goto LABEL_24;
  }
  if ( !bInitSuccess )
  {
    Msg(pMsgFormat: "Thread failed to initialize\n");
    CloseHandle(hObject: this->m_hThread);
    v11 = createComplete.m_hSyncObject;
    this->m_hThread = nullptr;
    if ( v11 != nullptr && createComplete.m_bCreatedHandle )
      CloseHandle(hObject: v11);
    goto LABEL_24;
  }
  if ( this->m_hThread == nullptr )
    Msg(pMsgFormat: "Thread exited immediately\n");
  AddThreadHandleToIDMap(hThread: this->m_hThread, threadID: this->m_threadId);
  nBytesStack_3 = this->m_hThread != nullptr;
  if ( createComplete.m_hSyncObject != nullptr && createComplete.m_bCreatedHandle )
    CloseHandle(hObject: createComplete.m_hSyncObject);
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)generated_id_4.m_lock);
  return nBytesStack_3;
}

//------------------------------------------------------------------------------
// Address: 0x1000F7C0
// Name: public: void CThread::Stop(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThread::Stop(CThread *this, int exitCode)
{
  void *m_hThread; // eax
  CThread *v4; // eax
  bool v5; // zf
  int v6; // eax
  unsigned int ExitCode; // [esp+4h] [ebp-4h] BYREF

  m_hThread = this->m_hThread;
  if ( m_hThread != nullptr && GetExitCodeThread(hThread: m_hThread, lpExitCode: &ExitCode) && ExitCode == 259 )
  {
    v4 = g_pCurThread.m_index == -1 ? nullptr : (CThread *)TlsGetValue(dwTlsIndex: g_pCurThread.m_index);
    if ( v4 == this )
    {
      v5 = (this->m_flags & 1) == 0;
      v6 = exitCode;
      this->m_result = exitCode;
      if ( !v5 )
      {
        exitCode = v6;
        _CxxThrowException(pExceptionObject: &exitCode, pThrowInfo: &_TI1H);
      }
      this->OnExit(this);
      if ( g_pCurThread.m_index != -1 )
        TlsSetValue(dwTlsIndex: g_pCurThread.m_index, lpTlsValue: nullptr);
      CloseHandle(hObject: this->m_hThread);
      RemoveThreadHandleToIDMap(hThread: this->m_hThread);
      this->m_hThread = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F860
// Name: protected: static unsigned long CThread::ThreadProc(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CThread::ThreadProc(CThread **pv)
{
  CThread *v1; // eax
  CThread *v2; // eax
  bool v3; // bl
  CThread *v4; // eax
  CThreadMutex *p_m_Lock; // ebx
  int m_result; // esi
  int v8; // [esp+0h] [ebp-24h] BYREF
  CThread *pThread; // [esp+Ch] [ebp-18h]
  bool bInitSuccess; // [esp+13h] [ebp-11h]
  int *v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+20h] [ebp-4h]

  v11 = &v8;
  AllocateThreadID();
  v1 = *pv;
  pThread = *pv;
  if ( g_pCurThread.m_index != -1 )
  {
    TlsSetValue(dwTlsIndex: g_pCurThread.m_index, lpTlsValue: v1);
    v1 = pThread;
  }
  v1->m_pStackBase = (void *)((unsigned int)&STACK[0x100B] & 0xFFFFF000);
  (*pv)->m_result = -1;
  v2 = pv[2];
  if ( v2 != nullptr )
    LOBYTE(v2->__vftable) = 0;
  v12 = 0;
  v3 = (*pv)->Init(this: *pv);
  bInitSuccess = v3;
  v12 = -1;
  v4 = pv[2];
  if ( v4 != nullptr )
    LOBYTE(v4->__vftable) = v3;
  SetEvent(hEvent: pv[1]->__vftable);
  if ( v3 )
  {
    if ( Plat_IsInDebugSession() || ((*pv)->m_flags & 1) == 0 )
    {
      (*pv)->m_result = (*pv)->Run(this: *pv);
    }
    else
    {
      v12 = 2;
      (*pv)->m_result = (*pv)->Run(this: *pv);
      v12 = -1;
    }
    (*pv)->OnExit(this: *pv);
    if ( g_pCurThread.m_index != -1 )
      TlsSetValue(dwTlsIndex: g_pCurThread.m_index, lpTlsValue: nullptr);
    FreeThreadID();
    p_m_Lock = &pThread->m_Lock;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pThread->m_Lock);
    CloseHandle(hObject: pThread->m_hThread);
    RemoveThreadHandleToIDMap(hThread: pThread->m_hThread);
    pThread->m_hThread = nullptr;
    SetEvent(hEvent: pThread->m_ExitEvent.m_hSyncObject);
    m_result = (*pv)->m_result;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_Lock);
    operator delete(p: pv);
    return m_result;
  }
  else
  {
    operator delete(p: pv);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FA00
// Name: protected: int CWorkerThread::Call(unsigned int,unsigned int,bool,unsigned int (*)(unsigned int,class CThreadEvent __near * __near *,int,unsigned int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::Call(
        CWorkerThread *this,
        unsigned int dwParam,
        unsigned int timeout,
        bool fBoostPriority,
        unsigned int (__cdecl *waitFunc)(unsigned int, CThreadEvent **, int, unsigned int))
{
  CThreadMutex *p_m_Lock; // ebx
  void *m_hThread; // eax
  int v9; // edi
  int ThreadPriority; // ebx
  void *CurrentThread; // eax
  int v12; // edi
  void *v13; // eax
  void *v14; // eax
  int m_ReturnVal; // esi
  void *m_hSyncObject; // [esp-8h] [ebp-18h]
  CThreadMutex *generated_id_6; // [esp+8h] [ebp-8h]
  unsigned int ExitCode; // [esp+Ch] [ebp-4h] BYREF

  p_m_Lock = &this->m_Lock;
  generated_id_6 = &this->m_Lock;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock);
  m_hThread = this->m_hThread;
  if ( m_hThread != nullptr && GetExitCodeThread(hThread: m_hThread, lpExitCode: &ExitCode) && ExitCode == 259 )
  {
    v9 = 0;
    if ( fBoostPriority )
    {
      ThreadPriority = GetThreadPriority(hThread: this->m_hThread);
      CurrentThread = this->m_hThread;
      if ( CurrentThread == nullptr )
        CurrentThread = GetCurrentThread();
      v12 = GetThreadPriority(hThread: CurrentThread);
      if ( v12 > ThreadPriority )
      {
        v13 = this->m_hThread;
        if ( v13 == nullptr )
          v13 = GetCurrentThread();
        SetThreadPriority(hThread: v13, nPriority: v12);
      }
      v9 = ThreadPriority;
      p_m_Lock = generated_id_6;
    }
    m_hSyncObject = this->m_EventComplete.m_hSyncObject;
    this->m_Param = dwParam;
    ResetEvent(hEvent: m_hSyncObject);
    SetEvent(hEvent: this->m_EventSend.m_hSyncObject);
    CWorkerThread::WaitForReply(this, timeout, pfnWait: waitFunc);
    if ( fBoostPriority )
    {
      v14 = this->m_hThread;
      if ( v14 == nullptr )
        v14 = GetCurrentThread();
      SetThreadPriority(hThread: v14, nPriority: v9);
    }
    m_ReturnVal = this->m_ReturnVal;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_Lock);
    return m_ReturnVal;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_Lock);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FAF0
// Name: public: int CWorkerThread::WaitForReply(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::WaitForReply(CWorkerThread *this, unsigned int timeout)
{
  return CWorkerThread::WaitForReply(this, timeout, pfnWait: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000FB10
// Name: struct ThreadHandle_t__ __near * __near * CreateTestThreads(unsigned int (*)(void __near *),int,int)
// Source: json
//------------------------------------------------------------------------------
ThreadHandle_t__ **__cdecl CreateTestThreads(
        unsigned int (__cdecl *fnThread)(void *),
        ThreadHandle_t__ *numThreads,
        int nProcessorsToDistribute)
{
  ThreadHandle_t__ **result; // eax
  int v4; // esi
  _DWORD *v5; // eax
  ThreadHandle_t__ *v6; // eax
  unsigned int v7; // ebx
  ThreadHandle_t__ *v8; // edi
  CThreadHandleToIDMap *v9; // esi
  HANDLE CurrentThread; // eax
  DWORD_PTR v11; // esi
  ThreadHandle_t__ **v12; // edx
  unsigned int ThreadId; // [esp+8h] [ebp-Ch] BYREF
  ThreadHandle_t__ **pHandles; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  result = (ThreadHandle_t__ **)((char *)operator new[](cb: 4 * ((_DWORD)numThreads + 1)) + 4);
  v4 = 0;
  pHandles = result;
  *(result - 1) = numThreads;
  i = 0;
  if ( (int)numThreads > 0 )
  {
    do
    {
      v5 = operator new(size: 8u);
      if ( v5 != nullptr )
      {
        *v5 = fnThread;
        v5[1] = v4;
      }
      else
      {
        v5 = nullptr;
      }
      v6 = (ThreadHandle_t__ *)CreateThread(
                                 lpThreadAttributes: nullptr,
                                 dwStackSize: 0x10000u,
                                 lpStartAddress: (LPTHREAD_START_ROUTINE)ThreadProcConvert,
                                 lpParameter: v5,
                                 dwCreationFlags: 0,
                                 lpThreadId: &ThreadId);
      v7 = ThreadId;
      v8 = v6;
      if ( v6 != nullptr )
      {
        v9 = (CThreadHandleToIDMap *)operator new(size: 0xCu);
        v9->m_hThread = v8;
        v9->m_ThreadID = v7;
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex);
        v9->m_pNext = g_pThreadHandleToIDMaps;
        g_pThreadHandleToIDMaps = v9;
        ++g_nThreadHandleToIDMaps;
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex);
        if ( g_nThreadHandleToIDMaps > 500 )
          Error(pMsgFormat: "ThreadHandleToIDMap overflow.");
        v4 = i;
      }
      if ( nProcessorsToDistribute != 0 )
      {
        CurrentThread = v8;
        v11 = 1 << (v4 % nProcessorsToDistribute);
        if ( v8 == nullptr )
          CurrentThread = GetCurrentThread();
        SetThreadAffinityMask(hThread: CurrentThread, dwThreadAffinityMask: v11);
        v4 = i;
      }
      v12 = pHandles;
      pHandles[v4++] = v8;
      i = v4;
    }
    while ( v4 < (int)numThreads );
    return v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC30
// Name: public: virtual CThread::~CThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThread::~CThread(CThread *this)
{
  void *m_hThread; // eax
  CThread *v3; // eax
  unsigned int ExitCode; // [esp+8h] [ebp-4h] BYREF

  m_hThread = this->m_hThread;
  this->__vftable = (CThread_vtbl *)&CThread::`vftable';
  if ( m_hThread != nullptr && GetExitCodeThread(hThread: m_hThread, lpExitCode: &ExitCode) && ExitCode == 259 )
  {
    Msg(
      pMsgFormat: "Illegal termination of worker thread! Threads must negotiate an end to the thread before the CThread object is destroyed.\n");
    DoNewAssertDialog(
      pFilename: "c:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\tier0\\../public/tier0/threadtools.inl",
      line: 47,
      pExpression: "Illegal termination of worker thread! Threads must negotiate an end to the thread before the CThread object is destroyed.\n");
    v3 = g_pCurThread.m_index == -1 ? nullptr : (CThread *)TlsGetValue(dwTlsIndex: g_pCurThread.m_index);
    if ( v3 == this )
      CThread::Stop(this, exitCode: 0);
  }
  if ( this->m_NotSuspendedEvent.m_hSyncObject != nullptr && this->m_NotSuspendedEvent.m_bCreatedHandle )
    CloseHandle(hObject: this->m_NotSuspendedEvent.m_hSyncObject);
  if ( this->m_ExitEvent.m_hSyncObject != nullptr && this->m_ExitEvent.m_bCreatedHandle )
    CloseHandle(hObject: this->m_ExitEvent.m_hSyncObject);
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock);
}

//------------------------------------------------------------------------------
// Address: 0x1000FCE0
// Name: protected: virtual unsigned long (*CThread::GetThreadProc(void))(void __near *)
// Source: json
//------------------------------------------------------------------------------
int (__stdcall *__thiscall CThread::GetThreadProc(CThread *this))(CThread **pv)
{
  return CThread::ThreadProc;
}

//------------------------------------------------------------------------------
// Address: 0x1000FCF0
// Name: public: CWorkerThread::CWorkerThread(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerThread *__thiscall CWorkerThread::CWorkerThread(CWorkerThread *this)
{
  CThread::CThread(this);
  this->__vftable = (CWorkerThread_vtbl *)&CWorkerThread::`vftable';
  this->m_EventSend.m_hSyncObject = nullptr;
  this->m_EventSend.m_bCreatedHandle = false;
  this->m_EventSend.m_hSyncObject = CreateEventA(
                                      lpEventAttributes: nullptr,
                                      bManualReset: true,
                                      bInitialState: false,
                                      lpName: nullptr);
  this->m_EventSend.m_bCreatedHandle = true;
  this->m_EventComplete.m_hSyncObject = nullptr;
  this->m_EventComplete.m_bCreatedHandle = false;
  this->m_EventComplete.m_hSyncObject = CreateEventA(
                                          lpEventAttributes: nullptr,
                                          bManualReset: true,
                                          bInitialState: false,
                                          lpName: nullptr);
  this->m_EventComplete.m_bCreatedHandle = true;
  this->m_Param = 0;
  this->m_ReturnVal = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000FD40
// Name: public: int CWorkerThread::CallWorker(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::CallWorker(
        CWorkerThread *this,
        unsigned int dw,
        unsigned int timeout,
        bool fBoostWorkerPriorityToMaster)
{
  return CWorkerThread::Call(
           this,
           dwParam: dw,
           timeout,
           fBoostPriority: fBoostWorkerPriorityToMaster,
           waitFunc: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD60
// Name: public: int CWorkerThread::CallMaster(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::CallMaster(CWorkerThread *this, unsigned int dw, unsigned int timeout)
{
  CThreadMutex *p_m_Lock; // edi
  void *m_hThread; // eax
  int m_ReturnVal; // esi
  void *m_hSyncObject; // [esp-4h] [ebp-10h]
  unsigned int ExitCode; // [esp+8h] [ebp-4h] BYREF

  p_m_Lock = &this->m_Lock;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock);
  m_hThread = this->m_hThread;
  if ( m_hThread != nullptr && GetExitCodeThread(hThread: m_hThread, lpExitCode: &ExitCode) && ExitCode == 259 )
  {
    m_hSyncObject = this->m_EventComplete.m_hSyncObject;
    this->m_Param = dw;
    ResetEvent(hEvent: m_hSyncObject);
    SetEvent(hEvent: this->m_EventSend.m_hSyncObject);
    CWorkerThread::WaitForReply(this, timeout, pfnWait: nullptr);
    m_ReturnVal = this->m_ReturnVal;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_Lock);
    return m_ReturnVal;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_Lock);
    return -1;
  }
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F001060
// Name: public: bool CThreadEvent::Wait(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge __noreturn CThreadEvent::Wait(CThreadEvent *this@<ecx>, int a2@<eax>, unsigned int dwTimeout)
{
  _close(fh: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F0031B0
// Name: public: CAutoLockT<class CThreadFastMutex>::~CAutoLockT<class CThreadFastMutex>(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CAutoLockT<CThreadFastMutex>::~CAutoLockT<CThreadFastMutex>(
        CAutoLockT<CThreadFastMutex> *this@<ecx>,
        _DWORD *a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>)
{
  int v5; // [esp-14h] [ebp-14h]

  _ESI = v5;
  *a2 += a4;
  __asm { fistp   qword ptr [esi-36h] }
  **(_DWORD **)(a3 + 12) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F003FC0
// Name: protected: virtual bool CThread::Init(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?AssertOwnedByCurrentThread@CThreadFullMutex@@QAE_NXZ'
// Alternative name is '?AssertOwnedByCurrentThread@CThreadMutex@@QAE_NXZ'
char __thiscall CThread::Init(CThread *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F007780
// Name: ThreadProcConvert
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __stdcall ThreadProcConvert(void *pParam)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F007830
// Name: _ReleaseThreadHandle
// Source: json
//------------------------------------------------------------------------------
void __usercall ReleaseThreadHandle(
        __int64 a1@<edx:eax>,
        unsigned int a2@<ecx>,
        signed __int32 a3@<ebx>,
        int a4@<ebp>,
        signed __int32 a5@<edi>,
        unsigned int a6@<esi>)
{
  *(_DWORD *)(a4 - 32) = (a1 + __PAIR64__(a6, a2)) >> 32;
  if ( a1 + __PAIR64__(a6, a2) > 0x10000 )
    a3 = 0;
  _InterlockedCompareExchange(*(volatile signed __int32 **)(a4 - 12), a3, a5);
  JUMPOUT(0x3F00784E);
}

//------------------------------------------------------------------------------
// Address: 0x3F007850
// Name: _ThreadSleep
// Source: json
//------------------------------------------------------------------------------
void __usercall ThreadSleep(char a1@<zf>)
{
  if ( a1 )
    JUMPOUT(0x3F00785E);
  JUMPOUT(0x3F007809);
}

//------------------------------------------------------------------------------
// Address: 0x3F007860
// Name: _ThreadGetCurrentProcessId
// Source: json
//------------------------------------------------------------------------------
void __usercall ThreadGetCurrentProcessId(char a1@<al>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 267452361) &= a1;
  JUMPOUT(0x3F007866);
}

//------------------------------------------------------------------------------
// Address: 0x3F0078C0
// Name: _ThreadGetCurrentHandle
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadGetCurrentHandle()
{
  JUMPOUT(0x3F0078C9);
}

//------------------------------------------------------------------------------
// Address: 0x3F0078D0
// Name: _ThreadGetPriority
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge ThreadGetPriority@<eax>(int _ECX@<ecx>, int a2@<ebx>, ThreadHandle_t__ *hThread)
{
  int result; // eax
  char v4; // cl

  __asm { rcl     dword ptr [ecx], 8Bh }
  result = MEMORY[0x3F8DEFC1]();
  *(_BYTE *)(a2 + 1532911559) += v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0078F0
// Name: _ThreadSetPriority
// Source: json
//------------------------------------------------------------------------------
void __usercall ThreadSetPriority(char a1@<cf>, char a2@<al>, int a3@<ecx>, int a4@<ebx>, int a5@<ebp>)
{
  bool v5; // zf

  v5 = *(_BYTE *)(a4 - 1036314431) == (unsigned __int8)(a1 + a2);
  *(_BYTE *)(a4 - 1036314431) -= a1 + a2;
  *(_DWORD *)(a5 - 32) = a3;
  if ( v5 || _InterlockedCompareExchange((volatile signed __int32 *)a3, a2, 0) == 0 )
  {
    ++*(_DWORD *)(a3 + 4);
    JUMPOUT(0x3F007911);
  }
  JUMPOUT(0x3F007A23);
}

//------------------------------------------------------------------------------
// Address: 0x3F007920
// Name: _ThreadSetAffinity
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadSetAffinity()
{
  JUMPOUT(0x3F007922);
}

//------------------------------------------------------------------------------
// Address: 0x3F007940
// Name: _ThreadInMainThread
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl __noreturn ThreadInMainThread()
{
  JUMPOUT(0x3F0079AA);
}

//------------------------------------------------------------------------------
// Address: 0x3F007960
// Name: _DeclareCurrentThreadIsMainThread
// Source: json
//------------------------------------------------------------------------------
void __usercall DeclareCurrentThreadIsMainThread(int a1@<eax>, int a2@<ecx>, int _EBX@<ebx>, int _EDI@<edi>)
{
  __asm { cmpxchg [ebx], edi }
  if ( a1 != a2 )
    JUMPOUT(0x3F00796C);
  JUMPOUT(0x3F00799B);
}

//------------------------------------------------------------------------------
// Address: 0x3F007970
// Name: _ThreadJoin
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn ThreadJoin()
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F0079D0
// Name: _ThreadSetDebugName
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall ThreadSetDebugName(__int32 a1@<ebx>, int a2@<ebp>, volatile __int32 *a3@<edi>, int a4@<esi>)
{
  int v4; // ecx
  unsigned int v5; // eax
  int v6; // ecx
  void *v8; // [esp+18h] [ebp-10h]
  SIZE_T v9; // [esp+1Ch] [ebp-Ch]
  DWORD v10; // [esp+20h] [ebp-8h]
  DWORD v11; // [esp+24h] [ebp-4h]

  VirtualAlloc(lpAddress: v8, dwSize: v9, flAllocationType: v10, flProtect: v11);
  v4 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(a4 + 4) = v4;
  _InterlockedExchange(a3, 0);
  *(_DWORD *)(a4 + 8) = *(_DWORD *)(v4 + 12);
  v5 = 0x10000u / *(_DWORD *)(v4 + 16);
  *(_DWORD *)(v4 + 12) = a4;
  _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 32), v5);
  ++*(_DWORD *)(v4 + 20);
  _InterlockedExchange(*(volatile __int32 **)(a2 - 12), a1);
  v6 = *(_DWORD *)(a2 - 32);
  if ( (*(_DWORD *)(v6 + 4))-- == 1 )
    _InterlockedExchange((volatile __int32 *)v6, 0);
  JUMPOUT(0x3F007809);
}

//------------------------------------------------------------------------------
// Address: 0x3F007A60
// Name: _ThreadWaitForObjects
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadWaitForObjects()
{
  sub_3F007150();
  JUMPOUT(0x3F007A77);
}

//------------------------------------------------------------------------------
// Address: 0x3F007F50
// Name: _WaitForMultipleEvents
// Source: json
//------------------------------------------------------------------------------
void __usercall WaitForMultipleEvents(char a1@<ah>, int a2@<esi>)
{
  *(_BYTE *)(a2 - 385875966) |= a1;
  JUMPOUT(0x3F007F5B);
}

//------------------------------------------------------------------------------
// Address: 0x3F0083B0
// Name: _ThreadInterlockedCompareExchange64
// Source: json
//------------------------------------------------------------------------------
void __usercall ThreadInterlockedCompareExchange64(
        char a1@<zf>,
        CThreadSpinRWLock **a2@<eax>,
        int a3@<ebx>,
        int a4@<edi>)
{
  CThreadSpinRWLock *v4; // esi

  if ( !a1 )
  {
    v4 = *a2;
    if ( a3 != 0 )
    {
      CThreadSpinRWLock::LockForRead(this: v4 + 1);
      _InterlockedExchangeAdd((volatile signed __int32 *)&v4[3].m_nWriters + 6 * a4 + 1, 0xFFFFFFFF);
      JUMPOUT(0x3F0083D4);
    }
    JUMPOUT(0x3F00841D);
  }
  JUMPOUT(0x3F0083D6);
}

//------------------------------------------------------------------------------
// Address: 0x3F0083E0
// Name: _ThreadInterlockedAssignIf64
// Source: json
//------------------------------------------------------------------------------
void __usercall ThreadInterlockedAssignIf64(_DWORD *a1@<eax>, int a2@<ecx>, int a3@<ebx>)
{
  *a1 += a2;
  if ( *(_DWORD *)(a3 + 4) == -168890355 )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: pdw[1] != FREE_BLOCK_MARKER",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\tier0\\memstd.h",
      a4: 79,
      a5: &unk_3F041A32,
      a6: 0);
  *(_DWORD *)(a3 + 4) = -168890355;
  JUMPOUT(0x3F00840F);
}

//------------------------------------------------------------------------------
// Address: 0x3F008410
// Name: _ThreadInterlockedIncrement64
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge ThreadInterlockedIncrement64(
        CThreadSpinRWLock *a1@<ecx>,
        int _ESI@<esi>,
        volatile __int64 *pDest,
        volatile __int64 *pDesta)
{
  __asm { fdivr   qword ptr [esi+4C8BFFFFh] }
  CThreadSpinRWLock::UnlockRead(this: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F008480
// Name: _ThreadInterlockedDecrement64
// Source: json
//------------------------------------------------------------------------------
__int64 __usercall ThreadInterlockedDecrement64@<edx:eax>(
        int a1@<eax>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        volatile __int64 *pDest,
        __int64 a6)
{
  int v6; // esi
  void *v7; // esp
  void *v8; // esp
  void *v9; // esp
  int v10; // ecx
  int v11; // edx
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  if ( a4 == a2 )
    JUMPOUT(0x3F0086BE);
  v6 = 4 * *(_DWORD *)(a1 + 20);
  v7 = alloca(v6);
  *(_DWORD *)(a3 - 12) = &retaddr;
  v8 = alloca(v6);
  *(_DWORD *)(a3 - 28) = &retaddr;
  v9 = alloca(v6);
  v10 = *(_DWORD *)(a3 - 12) - (_DWORD)&retaddr;
  v11 = *(_DWORD *)(a3 - 28) - (_DWORD)&retaddr;
  *(_DWORD *)(a3 - 16) = &retaddr;
  *(_DWORD *)(a3 - 24) = a2;
  *(_DWORD *)(a3 - 40) = v10;
  *(_DWORD *)(a3 - 36) = v11;
  if ( *(_DWORD *)(a4 + 12) != 0 )
    JUMPOUT(0x3F00850D);
  *(_UNKNOWN **)((char *)&retaddr + v10) = (_UNKNOWN *)a4;
  return ThreadInterlockedExchange64(pDest, value: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F0084F0
// Name: _ThreadInterlockedExchange64
// Source: json
//------------------------------------------------------------------------------
void __usercall ThreadInterlockedExchange64(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        int a4@<ebx>,
        int a5@<ebp>,
        int a6@<edi>,
        _DWORD *a7@<esi>)
{
  int v7; // ebx
  int v8; // eax

  v7 = a4 + 1;
  *a7 = *(_DWORD *)(a3 + 36) + a1;
  *(_DWORD *)((char *)a7 + *(_DWORD *)(a5 - 36)) = a2;
  v8 = *(_DWORD *)(a5 - 16);
  if ( *(_BYTE *)(a5 + 12) != 0 || (a3 = *(_DWORD *)(a5 - 40), *(_DWORD *)(a5 - 24) = a6, *(_DWORD *)(a6 + 8) == 0) )
  {
    if ( v7 != 0 )
    {
      LOBYTE(a3) = *(_BYTE *)(a5 + 12) == 0;
      if ( (unsigned __int8)sub_3F008D00(a1: *(_DWORD *)(a5 + 8), a2: v8, a3: v7, a4: a3) == 0 && byte_3F0A3624 == 0 )
      {
        byte_3F0A3624 = 1;
        *(_BYTE *)(a5 - 1) = 1;
      }
      *(_DWORD *)(a5 - 20) = v7 << 16;
      JUMPOUT(0x3F00855B);
    }
    JUMPOUT(0x3F0086BB);
  }
  JUMPOUT(0x3F0084C4);
}

//------------------------------------------------------------------------------
// Address: 0x3F008560
// Name: _ThreadInterlockedExchangeAdd64
// Source: json
//------------------------------------------------------------------------------
void __usercall ThreadInterlockedExchangeAdd64(char a1@<cl>, _BYTE *a2@<edi>)
{
  *a2 &= a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F008620
// Name: private: void CThreadFastMutex::Lock(unsigned int,unsigned int)volatile
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CThreadFastMutex::Lock(
        CThreadFastMutex *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        volatile signed __int64 *a4@<edi>,
        int a5@<esi>,
        unsigned int threadId,
        unsigned int nSpinSleepTime)
{
  unsigned int *v8; // ecx
  unsigned int *v9; // edx
  unsigned int *v10; // eax
  unsigned int *v11; // esi
  unsigned int v12; // esi
  const char *v13; // [esp-4h] [ebp-4h]

  __asm { fmul    dword ptr [this+1E8BE45Dh] }
  _InterlockedExchange((volatile __int32 *)(a2 + 12), -1);
  VirtualFree(lpAddress: *(LPVOID *)(*(_DWORD *)(a3 - 40) + a5), dwSize: 0x10000u, dwFreeType: 0x4000u);
  sub_3F0042F0(a1: a4, (unsigned int *)a2);
  if ( (*(_DWORD *)(a3 - 28))-- != 1 )
    JUMPOUT(0x3F008624);
  v8 = *(unsigned int **)(a3 + 12);
  v9 = nullptr;
  v10 = v8;
  if ( v8 != nullptr )
  {
    while ( v10[3] != -1 )
    {
      v9 = v10;
      v10 = (unsigned int *)*v10;
      if ( v10 == nullptr )
        goto LABEL_12;
    }
    if ( v9 != nullptr )
    {
      *v9 = 0;
    }
    else
    {
      *(_DWORD *)(a3 + 12) = 0;
      v8 = *(unsigned int **)(a3 + 12);
    }
    if ( v10 != nullptr )
    {
      do
      {
        v11 = (unsigned int *)*v10;
        sub_3F0042F0(a1: a4, a2: v10);
        v10 = v11;
      }
      while ( v11 != nullptr );
      v8 = *(unsigned int **)(a3 + 12);
    }
LABEL_12:
    if ( v8 != nullptr )
    {
      while ( 1 )
      {
        v12 = *v8;
        sub_3F0042F0(a1: a4, a2: v8);
        *(_DWORD *)(a3 + 12) = v12;
        if ( v12 == 0 )
          break;
        v8 = *(unsigned int **)(a3 + 12);
      }
    }
  }
  CThreadSpinRWLock::UnlockWrite(this: *(CThreadSpinRWLock **)(a3 - 32), a2: v13);
  if ( *(_BYTE *)(a3 - 1) != 0 )
    Warning(
      a1: "***** HEAP IS CORRUPT (free compromised for block size %d,in %s heap, possible write after free *****)\n",
      *(_DWORD *)(*(_DWORD *)(a3 + 8) + 16),
      "virtual");
}

//------------------------------------------------------------------------------
// Address: 0x3F008F20
// Name: public: CThreadLocalPtr<class CThread>::~CThreadLocalPtr<class CThread>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadLocalPtr<CThread>::~CThreadLocalPtr<CThread>(CThreadLocalPtr<CThread> *this)
{
  if ( this == nullptr )
    JUMPOUT(0x3F008EB0);
  JUMPOUT(0x3F008EE9);
}

//------------------------------------------------------------------------------
// Address: 0x3F009220
// Name: public: virtual bool CThread::Start(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CThread::Start(
        CThread *this@<ecx>,
        bool a2@<zf>,
        void (__stdcall *a3)(LPCRITICAL_SECTION lpCriticalSection)@<edi>)
{
  char v3; // bl
  unsigned int v4; // esi
  unsigned int v5; // eax
  char v6; // al
  int v7; // esi
  LPSTR CommandLineA; // eax
  int v9; // eax
  _BYTE *retaddr; // [esp+222h] [ebp+0h]

  v3 = !a2;
  ((void (__cdecl *)(_RTL_CRITICAL_SECTION *))a3)(a1: &CriticalSection);
  if ( v3 == 0 )
  {
    byte_3F03D369 = 1;
    v4 = ((int (__cdecl *)(const char *, int))loc_3F01AB6B)(a1: ".\\minidump.cpp", a2: 92);
    v5 = ((int (__cdecl *)(const char *, int))loc_3F01AB6B)(a1: ".\\minidump.cpp", a2: 47);
    if ( v4 < v5 )
      v4 = v5;
    if ( v4 != 0 )
      dword_3F03D2A8 = v4 + 1;
    else
      dword_3F03D2A8 = (int)".\\minidump.cpp";
    dword_3F03D2A4 = 173;
    dword_3F03D2A0 = 2;
    v6 = sub_3F008FA0(
           a1: "Assertion Failed: %s",
           "Someone called SetWritingMinidump without holding the minidump lock.");
    v7 = SpewMessage(a1: &unk_3F030FBC, a2: v6);
    byte_3F0A3605 = 1;
    if ( dword_3F03D370 != nullptr )
      dword_3F03D370();
    if ( v7 == 0 )
    {
      CommandLineA = GetCommandLineA();
      if ( sub_3F01A2BB(a1: CommandLineA, a2: "-mpi_worker") == 0 && IsDebuggerPresent() )
      {
        sub_3F008FA0(a1: "Assertion Failed: %s", "Someone called SetWritingMinidump without holding the minidump lock.");
        if ( DoNewAssertDialog() != 0 )
          __debugbreak();
      }
    }
    if ( byte_3F041A4F == 0 && !IsDebuggerPresent() )
    {
      v9 = sub_3F008FA0(
             a1: "Assertion Failed: %s",
             "Someone called SetWritingMinidump without holding the minidump lock.");
      WriteMiniDump(a1: v9, a2: ".\\minidump.cpp", a3: 173, a4: 0, a5: 0);
      byte_3F041A4F = 1;
    }
    byte_3F03D369 = 0;
  }
  a3(lpCriticalSection: &CriticalSection);
  a2 = *(retaddr - 1) == 0;
  byte_3F03D3C4 = 1;
  byte_3F03D36B = 0;
  if ( !a2 )
    a3(lpCriticalSection: &CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F0096E0
// Name: protected: virtual void CThread::OnExit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThread::OnExit(CValidator *this)
{
  JUMPOUT(0x3F0096E2);
}

//------------------------------------------------------------------------------
// Address: 0x3F0096F0
// Name: protected: virtual bool CThread::WaitForCreateComplete(class CThreadEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CThread::WaitForCreateComplete(
        CThread *this@<ecx>,
        int a2@<eax>,
        int a3@<edx>,
        int a4@<ebx>,
        int a5@<ebp>,
        CThreadEvent *pEvent)
{
  bool v6; // zf
  int v7; // eax
  int i; // eax

  --*(_DWORD *)(a5 - 1973550768);
  v6 = ((unsigned __int8)a2 | *(_BYTE *)(a4 - 914095680)) == 0;
  *(_BYTE *)(a4 - 914095680) |= a2;
  if ( v6 )
  {
    v7 = a2 - a3;
    if ( v7 != 0 )
    {
      for ( i = v7 - 1; i != 0; --i )
      {
        if ( *(_BYTE *)(a5 + i - 131068) == 92 )
          break;
      }
      *(_BYTE *)(a5 + i - 131068) = 92;
      ((void (__cdecl *)(int, const char *, int))loc_3F01B3F0)(
        a1: a5 + i - 131067,
        a2: "crashhandler.dll",
        a3: 131067 - i);
    }
    (*(void (__fastcall **)(CThread *))byte_3F0098D0)(a1: this);
    JUMPOUT(0x3F00974D);
  }
  JUMPOUT(0x3F0096F5);
}

//------------------------------------------------------------------------------
// Address: 0x3F009A20
// Name: DefaultWaitFunc
// Source: json
//------------------------------------------------------------------------------
void __stdcall DefaultWaitFunc(
        void *const *nHandles,
        void *const *pHandles,
        unsigned int bWaitAll,
        unsigned int timeout)
{
  JUMPOUT(0x3F009A26);
}

//------------------------------------------------------------------------------
// Address: 0x3F009E70
// Name: public: int CThreadLocalPtr<class CThread>::operator=(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CThreadLocalPtr<CThread>::operator=(CThreadLocalPtr<CThread> *this)
{
  void (__cdecl *v2)(unsigned int, struct _EXCEPTION_POINTERS *); // [esp-14h] [ebp-14h]

  _set_se_translator(a1: v2);
  return sub_3F009DA0();
}

//------------------------------------------------------------------------------
// Address: 0x3F009ED0
// Name: public: CAutoLockT<class CThreadMutex>::~CAutoLockT<class CThreadMutex>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall __noreturn CAutoLockT<CThreadMutex>::~CAutoLockT<CThreadMutex>(CAutoLockT<CThreadMutex> *this)
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F009EE0
// Name: public: std::auto_ptr<struct CThread::ThreadInit_t>::~auto_ptr<struct CThread::ThreadInit_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall __noreturn std::auto_ptr<CThread::ThreadInit_t>::~auto_ptr<CThread::ThreadInit_t>(
        std::auto_ptr<CThread::ThreadInit_t> *this)
{
  _CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F0D0
// Name: struct ThreadHandle_t__ __near * CreateSimpleThread(unsigned int (*)(void __near *),void __near *,unsigned long __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct ThreadHandle_t__ *__cdecl CreateSimpleThread(
        unsigned int (__cdecl *a1)(void *),
        void *a2,
        LPDWORD lpThreadId,
        SIZE_T dwStackSize)
{
  unsigned int *p_lpThreadId; // esi
  _DWORD *v5; // eax

  p_lpThreadId = lpThreadId;
  if ( lpThreadId == nullptr )
    p_lpThreadId = (unsigned int *)&lpThreadId;
  v5 = operator new(Size: 8u);
  if ( v5 != nullptr )
  {
    *v5 = a1;
    v5[1] = a2;
  }
  else
  {
    v5 = nullptr;
  }
  return (struct ThreadHandle_t__ *)CreateThread(
                                      lpThreadAttributes: nullptr,
                                      dwStackSize,
                                      lpStartAddress: sub_3F00F0B0,
                                      lpParameter: v5,
                                      dwCreationFlags: 0,
                                      lpThreadId: p_lpThreadId);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F150
// Name: ReleaseThreadHandle
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ReleaseThreadHandle(HANDLE hObject)
{
  return CloseHandle(hObject);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F1A0
// Name: ThreadIsProcessActive
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F00F390
// Name: ThreadGetPriority
// Source: json
//------------------------------------------------------------------------------
int __cdecl ThreadGetPriority(HANDLE hThread)
{
  HANDLE CurrentThread; // eax

  CurrentThread = hThread;
  if ( hThread == nullptr )
    CurrentThread = GetCurrentThread();
  return GetThreadPriority(hThread: CurrentThread);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F3B0
// Name: ThreadSetPriority
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ThreadSetPriority(HANDLE hThread, int nPriority)
{
  HANDLE CurrentThread; // eax

  CurrentThread = hThread;
  if ( hThread == nullptr )
    CurrentThread = GetCurrentThread();
  return SetThreadPriority(hThread: CurrentThread, nPriority);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F3E0
// Name: ThreadSetAffinity
// Source: json
//------------------------------------------------------------------------------
DWORD_PTR __cdecl ThreadSetAffinity(HANDLE hThread, DWORD_PTR dwThreadAffinityMask)
{
  HANDLE CurrentThread; // eax

  CurrentThread = hThread;
  if ( hThread == nullptr )
    CurrentThread = GetCurrentThread();
  return SetThreadAffinityMask(hThread: CurrentThread, dwThreadAffinityMask);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F400
// Name: ThreadInMainThread
// Source: json
//------------------------------------------------------------------------------
bool ThreadInMainThread()
{
  return GetCurrentThreadId() == dword_3F0415CC;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F420
// Name: DeclareCurrentThreadIsMainThread
// Source: json
//------------------------------------------------------------------------------
DWORD DeclareCurrentThreadIsMainThread()
{
  DWORD result; // eax

  result = GetCurrentThreadId();
  dword_3F0415CC = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F430
// Name: ThreadSetDebugName
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadSetDebugName(ULONG_PTR a1, ULONG_PTR a2)
{
  ULONG_PTR Arguments[4]; // [esp+Ch] [ebp-28h] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  if ( IsDebuggerPresent() )
  {
    Arguments[0] = 4096;
    Arguments[1] = a2;
    Arguments[2] = a1;
    Arguments[3] = 0;
    ms_exc.registration.TryLevel = 0;
    RaiseException(dwExceptionCode: 0x406D1388u, dwExceptionFlags: 0, nNumberOfArguments: 4u, lpArguments: Arguments);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00F4B0
// Name: ThreadWaitForObjects
// Source: json
//------------------------------------------------------------------------------
int __cdecl ThreadWaitForObjects(int a1, int a2, unsigned __int8 a3, int a4)
{
  return (*((int (__cdecl **)(int, int, _DWORD, int))g_pVCR + 37))(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F4E0
// Name: protected: CThreadSyncObject::CThreadSyncObject(void)
// Source: json
//------------------------------------------------------------------------------
CThreadSyncObject *__thiscall CThreadSyncObject::CThreadSyncObject(CThreadSyncObject *this)
{
  this->m_hSyncObject = nullptr;
  this->m_bOwnEventHandle = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F4F0
// Name: public: CThreadSyncObject::~CThreadSyncObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSyncObject::~CThreadSyncObject(CThreadSyncObject *this)
{
  if ( this->m_hSyncObject != nullptr && this->m_bOwnEventHandle && !CloseHandle(hObject: this->m_hSyncObject) )
    ((void (__cdecl *)(unsigned __int8 *, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: &__initialmbcinfo.mbcasemap[127],
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 748,
      a5: &unk_3F041A6C,
      a6: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F530
// Name: public: bool CThreadSyncObject::operator!(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadSyncObject::operator!(_DWORD *this)
{
  return *this == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F540
// Name: protected: void CThreadSyncObject::AssertUseable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSyncObject::AssertUseable(CThreadSyncObject *this)
{
  int v1; // eax

  if ( this->m_hSyncObject == nullptr )
  {
    v1 = sub_3F008FA0(a1: "Assertion Failed: %s", (const char *)&__initialmbcinfo.mbcasemap[147]);
    ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: v1,
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 790,
      a5: &unk_3F041A6D,
      a6: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00F6A0
// Name: public: CThreadEvent::CThreadEvent(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CThreadEvent *__thiscall CThreadEvent::CThreadEvent(CThreadEvent *this, LPCSTR lpName, bool a3, bool a4)
{
  int v5; // eax
  _SECURITY_ATTRIBUTES *v6; // esi
  const char *v7; // eax
  HANDLE EventA; // eax
  DWORD LastError; // eax
  const char *v10; // eax
  int v11; // eax
  _BYTE v13[260]; // [esp+20Ch] [ebp-134h] BYREF
  _BYTE pSecurityDescriptor[20]; // [esp+310h] [ebp-30h] BYREF
  CThreadEvent *v15; // [esp+324h] [ebp-1Ch]
  int v16; // [esp+328h] [ebp-18h] BYREF
  PSECURITY_DESCRIPTOR v17; // [esp+32Ch] [ebp-14h]
  int v18; // [esp+330h] [ebp-10h]
  int v19; // [esp+33Ch] [ebp-4h]

  v15 = this;
  this->m_hSyncObject = nullptr;
  this->m_bOwnEventHandle = true;
  v19 = 0;
  if ( *lpName == 0 )
  {
    v5 = sub_3F008FA0(a1: "Assertion Failed: %s", (const char *)&__initialmbcinfo.mbcasemap[227]);
    ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: v5,
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 993,
      a5: &unk_3F041A6F,
      a6: 0);
  }
  v6 = nullptr;
  v7 = lpName;
  if ( a3 )
  {
    v16 = 12;
    v18 = 0;
    v17 = pSecurityDescriptor;
    InitializeSecurityDescriptor(pSecurityDescriptor, dwRevision: 1u);
    SetSecurityDescriptorDacl(pSecurityDescriptor: v17, bDaclPresent: true, pDacl: nullptr, bDaclDefaulted: false);
    v6 = (_SECURITY_ATTRIBUTES *)&v16;
    v13[0] = 0;
    ((void (__cdecl *)(_BYTE *, unsigned __int8 *, int))loc_3F01B3F0)(a1: v13, a2: &_mbctype[20], a3: 260);
    ((void (__cdecl *)(_BYTE *, LPCSTR, int))loc_3F01D520)(a1: v13, a2: lpName, a3: 253);
    v7 = v13;
  }
  EventA = CreateEventA(lpEventAttributes: v6, bManualReset: a4, bInitialState: false, lpName: v7);
  this->m_hSyncObject = EventA;
  if ( EventA == nullptr )
  {
    LastError = GetLastError();
    v10 = (const char *)sub_3F008FA0(a1: (const char *)&__initialmbcinfo.mbcasemap[191], LastError);
    v11 = sub_3F008FA0(a1: "Assertion Failed: %s", v10);
    ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: v11,
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 1019,
      a5: &unk_3F041A70,
      a6: 0);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F800
// Name: public: CThreadEvent::CThreadEvent(void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThreadEvent *__thiscall CThreadEvent::CThreadEvent(CThreadEvent *this, void *a2, bool a3)
{
  const char *v4; // eax
  int v5; // eax

  this->m_hSyncObject = nullptr;
  this->m_bOwnEventHandle = true;
  this->m_hSyncObject = a2;
  this->m_bOwnEventHandle = a3;
  if ( a2 != nullptr && a2 != (void *)-1 )
    return this;
  v4 = (const char *)sub_3F008FA0(a1: (const char *)&_mbctype[28], a2);
  v5 = sub_3F008FA0(a1: "Assertion Failed: %s", v4);
  ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
    a1: v5,
    a2: 0,
    a3: &__initialmbcinfo.mbcasemap[107],
    a4: 1078,
    a5: &unk_3F041A71,
    a6: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00F8C0
// Name: public: bool CThreadEvent::Set(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadEvent::Set(CThreadEvent *this)
{
  CThreadSyncObject::AssertUseable(this);
  return SetEvent(hEvent: this->m_hSyncObject);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F8E0
// Name: public: bool CThreadEvent::Reset(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadEvent::Reset(CThreadEvent *this)
{
  int v2; // eax

  if ( this->m_hSyncObject == nullptr )
  {
    v2 = sub_3F008FA0(a1: "Assertion Failed: %s", (const char *)&__initialmbcinfo.mbcasemap[147]);
    ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: v2,
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 790,
      a5: &unk_3F041A6D,
      a6: 0);
  }
  return ResetEvent(hEvent: this->m_hSyncObject);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F9A0
// Name: WaitForMultipleEvents
// Source: json
//------------------------------------------------------------------------------
DWORD __cdecl WaitForMultipleEvents(int a1, DWORD nCount, DWORD dwMilliseconds, unsigned __int8 a4)
{
  DWORD v4; // esi
  DWORD i; // eax
  DWORD v6; // eax
  DWORD v7; // edi
  HANDLE Handles[64]; // [esp+8h] [ebp-100h] BYREF

  v4 = nCount;
  if ( nCount >= 0x40 )
    v4 = 64;
  for ( i = 0; i < v4; ++i )
    Handles[i] = **(HANDLE **)((char *)&Handles[i] + a1 - (_DWORD)Handles);
  v6 = WaitForMultipleObjects(nCount: v4, lpHandles: Handles, bWaitAll: a4, dwMilliseconds);
  v7 = v6;
  if ( v6 == -1 || v6 == 258 || v6 >= 0x80 && v6 <= v4 + 128 )
    return -1;
  if ( v6 >= v4 )
    ((void (__cdecl *)(unsigned __int8 *, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: &_mbctype[60],
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 1542,
      a5: &unk_3F041A72,
      a6: 0);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x3F00FA60
// Name: public: CThreadSemaphore::CThreadSemaphore(long,long)
// Source: json
//------------------------------------------------------------------------------
CThreadSemaphore *__thiscall CThreadSemaphore::CThreadSemaphore(
        CThreadSemaphore *this,
        LONG lInitialCount,
        LONG lMaximumCount)
{
  int v4; // eax
  LONG v5; // eax
  int v6; // eax
  HANDLE SemaphoreA; // eax
  DWORD LastError; // eax
  const char *v9; // eax
  int v10; // eax

  this->m_hSyncObject = nullptr;
  this->m_bOwnEventHandle = true;
  if ( lMaximumCount != 0 )
  {
    if ( lMaximumCount <= 0 )
    {
      v4 = sub_3F008FA0(a1: "Assertion Failed: %s", (const char *)&_mbctype[124]);
      ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: v4,
        a2: 0,
        a3: &__initialmbcinfo.mbcasemap[107],
        a4: 1679,
        a5: &unk_3F041A73,
        a6: 0);
    }
    v5 = lInitialCount;
    if ( lInitialCount < 0 || lInitialCount > lMaximumCount )
    {
      v6 = sub_3F008FA0(a1: "Assertion Failed: %s", (const char *)&_mbctype[156]);
      ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: v6,
        a2: 0,
        a3: &__initialmbcinfo.mbcasemap[107],
        a4: 1680,
        a5: &unk_3F041A74,
        a6: 0);
      v5 = lInitialCount;
    }
    SemaphoreA = CreateSemaphoreA(lpSemaphoreAttributes: nullptr, lInitialCount: v5, lMaximumCount, lpName: nullptr);
    this->m_hSyncObject = SemaphoreA;
    if ( SemaphoreA == nullptr )
    {
      LastError = GetLastError();
      v9 = (const char *)sub_3F008FA0(a1: (const char *)&_mbctype[192], LastError);
      v10 = sub_3F008FA0(a1: "Assertion Failed: %s", v9);
      ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: v10,
        a2: 0,
        a3: &__initialmbcinfo.mbcasemap[107],
        a4: 1684,
        a5: &unk_3F041A75,
        a6: 0);
    }
    return this;
  }
  else
  {
    this->m_hSyncObject = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00FBB0
// Name: public: bool CThreadSemaphore::Release(long,long __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadSemaphore::Release(CThreadSemaphore *this, LONG lReleaseCount, int *lpPreviousCount)
{
  return ReleaseSemaphore(hSemaphore: this->m_hSyncObject, lReleaseCount, lpPreviousCount);
}

//------------------------------------------------------------------------------
// Address: 0x3F00FBD0
// Name: public: CThreadFullMutex::CThreadFullMutex(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CThreadFullMutex *__thiscall CThreadFullMutex::CThreadFullMutex(CThreadFullMutex *this, bool a2, const char *lpName)
{
  HANDLE MutexA; // eax
  DWORD LastError; // eax
  const char *v6; // eax
  int v7; // eax

  this->m_hSyncObject = nullptr;
  this->m_bOwnEventHandle = true;
  MutexA = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: a2, lpName);
  this->m_hSyncObject = MutexA;
  if ( MutexA == nullptr )
  {
    LastError = GetLastError();
    v6 = (const char *)sub_3F008FA0(a1: (const char *)&_mbctype[232], LastError);
    v7 = sub_3F008FA0(a1: "Assertion Failed: %s", v6);
    ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: v7,
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 1712,
      a5: &unk_3F041A76,
      a6: 0);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F00FCA0
// Name: public: bool CThreadFullMutex::Release(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThreadFullMutex::Release(CThreadFullMutex *this)
{
  return ReleaseMutex(hMutex: this->m_hSyncObject);
}

//------------------------------------------------------------------------------
// Address: 0x3F00FCB0
// Name: public: CThreadLocalBase::CThreadLocalBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadLocalBase::CThreadLocalBase(CThreadLocalBase *this, int a2, const char *a3, int a4)
{
  DWORD v5; // eax
  CVProfile *v6; // ecx

  v5 = TlsAlloc();
  this->m_index = v5;
  if ( v5 != -1 )
    JUMPOUT(0x3F00FD0E);
  sub_3F008FA0(a1: "Assertion Failed: %s", "Bad thread local");
  CVProfile::OutputReport(this: v6, type: a2, pszStartNode: a3, budgetGroupID: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F00FD20
// Name: public: CThreadLocalBase::~CThreadLocalBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadLocalBase::~CThreadLocalBase(CThreadLocalBase *this)
{
  if ( this->m_index != -1 )
    TlsFree(dwTlsIndex: this->m_index);
  this->m_index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00FD40
// Name: public: void __near * CThreadLocalBase::Get(void)const
// Source: json
//------------------------------------------------------------------------------
LPVOID __thiscall CThreadLocalBase::Get(CThreadLocalBase *this)
{
  int v2; // eax

  if ( this->m_index != -1 )
    return TlsGetValue(dwTlsIndex: this->m_index);
  v2 = sub_3F008FA0(a1: "Assertion Failed: %s", "Bad thread local");
  ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
    a1: v2,
    a2: 0,
    a3: &__initialmbcinfo.mbcasemap[107],
    a4: 1764,
    a5: &unk_3F041A78,
    a6: 0);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F00FDA0
// Name: public: void CThreadLocalBase::Set(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadLocalBase::Set(CThreadLocalBase *this, void *lpTlsValue)
{
  int v2; // eax

  if ( this->m_index == -1 )
  {
    v2 = sub_3F008FA0(a1: "Assertion Failed: %s", "Bad thread local");
    ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: v2,
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 1782,
      a5: &unk_3F041A79,
      a6: 0);
  }
  else
  {
    TlsSetValue(dwTlsIndex: this->m_index, lpTlsValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F00FE00
// Name: ThreadInterlockedCompareExchange64
// Source: json
//------------------------------------------------------------------------------
signed __int64 __cdecl ThreadInterlockedCompareExchange64(
        volatile signed __int64 *a1,
        signed __int64 a2,
        signed __int64 a3)
{
  return _InterlockedCompareExchange64(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F00FE30
// Name: ThreadInterlockedAssignIf64
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ThreadInterlockedAssignIf64(volatile signed __int64 *a1, signed __int64 a2, signed __int64 a3)
{
  return a3 == _InterlockedCompareExchange64(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F00FE60
// Name: ThreadInterlockedIncrement64
// Source: json
//------------------------------------------------------------------------------
signed __int64 __cdecl ThreadInterlockedIncrement64(volatile signed __int64 *a1)
{
  signed __int64 v2; // [esp+20h] [ebp-8h]

  do
    v2 = *a1;
  while ( _InterlockedCompareExchange64(a1, v2 + 1, v2) != v2 );
  return v2 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00FED0
// Name: ThreadInterlockedDecrement64
// Source: json
//------------------------------------------------------------------------------
signed __int64 __cdecl ThreadInterlockedDecrement64(volatile signed __int64 *a1)
{
  signed __int64 v2; // [esp+20h] [ebp-8h]

  do
    v2 = *a1;
  while ( _InterlockedCompareExchange64(a1, v2 - 1, v2) != v2 );
  return v2 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F00FF40
// Name: ThreadInterlockedExchange64
// Source: json
//------------------------------------------------------------------------------
signed __int64 __cdecl ThreadInterlockedExchange64(volatile signed __int64 *a1, signed __int64 a2)
{
  volatile signed __int64 v3; // [esp+20h] [ebp-8h]

  do
    v3 = *a1;
  while ( _InterlockedCompareExchange64(a1, a2, *a1) != v3 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F00FFB0
// Name: ThreadInterlockedExchangeAdd64
// Source: json
//------------------------------------------------------------------------------
signed __int64 __cdecl ThreadInterlockedExchangeAdd64(volatile signed __int64 *a1, __int64 a2)
{
  signed __int64 v3; // [esp+20h] [ebp-8h]

  do
    v3 = *a1;
  while ( _InterlockedCompareExchange64(a1, a2 + v3, v3) != v3 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F010020
// Name: public: CThreadMutex::CThreadMutex(void)
// Source: json
//------------------------------------------------------------------------------
CThreadMutex *__thiscall CThreadMutex::CThreadMutex(LPCRITICAL_SECTION lpCriticalSection)
{
  InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount: 0xFA0u);
  *((_WORD *)lpCriticalSection + 14) = 0;
  *((_DWORD *)lpCriticalSection + 6) = 0;
  *((_BYTE *)lpCriticalSection + 30) = 0;
  return (CThreadMutex *)lpCriticalSection;
}

//------------------------------------------------------------------------------
// Address: 0x3F010040
// Name: public: CThreadMutex::~CThreadMutex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadMutex::~CThreadMutex(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F010070
// Name: private: void CThreadFastMutex::Lock(unsigned long,unsigned int)volatile
// Source: json
//------------------------------------------------------------------------------
CVProfile *__thiscall CThreadFastMutex::Lock(int this, CVProfile *a2, DWORD dwMilliseconds)
{
  int v4; // ecx
  CVProfile *result; // eax
  DWORD v6; // ebx
  HANDLE CurrentThread; // eax
  int v8; // ebx

  if ( dwMilliseconds == -1 )
    return CVProfile::CVProfile(this: a2);
  v4 = 1000;
  while ( 1 )
  {
    result = *(CVProfile **)this;
    if ( a2 == *(CVProfile **)this )
      break;
    result = (CVProfile *)_InterlockedCompareExchange((volatile signed __int32 *)this, (signed __int32)a2, 0);
    if ( result == nullptr )
      break;
    _mm_pause();
    if ( --v4 == 0 )
    {
      v6 = dwMilliseconds;
      if ( dwMilliseconds != 0 )
      {
        v8 = 4000;
        while ( 1 )
        {
          result = *(CVProfile **)this;
          if ( a2 == *(CVProfile **)this )
            break;
          result = (CVProfile *)_InterlockedCompareExchange((volatile signed __int32 *)this, (signed __int32)a2, 0);
          if ( result == nullptr )
            break;
          _mm_pause();
          Sleep(dwMilliseconds: 0);
          if ( --v8 == 0 )
            goto LABEL_13;
        }
      }
      else
      {
        CurrentThread = GetCurrentThread();
        if ( GetThreadPriority(hThread: CurrentThread) > 0 )
        {
          dwMilliseconds = 1;
LABEL_13:
          v6 = dwMilliseconds;
        }
        while ( 1 )
        {
          result = *(CVProfile **)this;
          if ( a2 == *(CVProfile **)this )
            break;
          result = (CVProfile *)_InterlockedCompareExchange((volatile signed __int32 *)this, (signed __int32)a2, 0);
          if ( result == nullptr )
            break;
          _mm_pause();
          if ( v6 != 0 )
            Sleep(dwMilliseconds: v6);
          else
            Sleep(dwMilliseconds: 0);
        }
      }
      break;
    }
  }
  ++*(_DWORD *)(this + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F010170
// Name: private: void CThreadRWLock::WaitForRead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadRWLock::WaitForRead(CThreadRWLock *this)
{
  int v3; // eax
  CVProfile *CurrentThreadId; // eax
  CThreadLocal<int> *v5; // ecx

  ++this->m_nPendingReaders;
  do
  {
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    if ( this->m_CanRead.m_hSyncObject == nullptr )
    {
      v3 = sub_3F008FA0(a1: "Assertion Failed: %s", (const char *)&__initialmbcinfo.mbcasemap[147]);
      ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: v3,
        a2: 0,
        a3: &__initialmbcinfo.mbcasemap[107],
        a4: 790,
        a5: &unk_3F041A6D,
        a6: 0);
    }
    WaitForSingleObject(hHandle: this->m_CanRead.m_hSyncObject, dwMilliseconds: 0xFFFFFFFF);
    CurrentThreadId = (CVProfile *)GetCurrentThreadId();
    v5 = (CThreadLocal<int> *)CurrentThreadId;
    if ( CurrentThreadId != (CVProfile *)this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)this, (signed __int32)CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock((int)this, a2: CurrentThreadId, dwMilliseconds: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
  }
  while ( this->m_nWriters != 0 );
  CThreadLocal<int>::~CThreadLocal<int>(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x3F010310
// Name: private: void CThreadSpinRWLock::SpinLockForWrite(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSpinRWLock::SpinLockForWrite(CThreadSpinRWLock *this, unsigned int a2)
{
  CThreadSpinRWLock *v2; // esi
  unsigned int v3; // edi
  int v4; // [esp+Ch] [ebp-3Ch]
  int v5; // [esp+Ch] [ebp-3Ch]
  volatile signed __int64 *v7; // [esp+14h] [ebp-34h]

  v2 = this;
  v3 = a2;
  v4 = 1000;
  while ( 1 )
  {
    if ( v2->m_lockInfo.m_nReaders <= 0 && (v2->m_lockInfo.m_writerId == 0 || v2->m_lockInfo.m_writerId == v3) )
    {
      if ( _InterlockedCompareExchange64((volatile signed __int64 *)this, v3, 0) == 0 )
LABEL_16:
        JUMPOUT(0x3F01048A);
      v3 = a2;
      v2 = this;
    }
    _mm_pause();
    if ( --v4 == 0 )
    {
      v5 = 20000;
      v7 = (volatile signed __int64 *)v2;
      while ( 1 )
      {
        if ( v2->m_lockInfo.m_nReaders <= 0 && (v2->m_lockInfo.m_writerId == 0 || v2->m_lockInfo.m_writerId == v3) )
        {
          if ( _InterlockedCompareExchange64(v7, v3, 0) == 0 )
            goto LABEL_16;
          v3 = a2;
          v2 = this;
        }
        _mm_pause();
        Sleep(dwMilliseconds: 0);
        if ( --v5 == 0 )
          JUMPOUT(0x3F010420);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0108D0
// Name: public: CThread::CThread(void)
// Source: json
//------------------------------------------------------------------------------
CThread *__thiscall CThread::CThread(CThread *this)
{
  CThreadMutex *p_m_Lock; // edi

  p_m_Lock = &this->m_Lock;
  this->__vftable = (CThread_vtbl *)&errtable[2].errnocode;
  InitializeCriticalSectionAndSpinCount(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock, dwSpinCount: 0xFA0u);
  p_m_Lock->m_lockCount = 0;
  p_m_Lock->m_currentOwnerID = 0;
  p_m_Lock->m_bTrace = false;
  this->m_hThread = nullptr;
  this->m_result = 0;
  this->m_flags = 0;
  this->m_szName[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F010A30
// Name: public: char const __near * CThread::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CThread::GetName(CThread *this, int a2)
{
  return (const char *)CVProfile::GetCounterValue((CVProfile *)this, index: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F010AB0
// Name: public: void CThread::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThread::SetName(CThread *this, const char *a2)
{
  CVProfile::GetCounterGroup((CVProfile *)this, index: (int)a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F010B20
// Name: public: bool CThread::Start(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CThread::Start(CThread *this, SIZE_T dwStackSize)
{
  _RTL_CRITICAL_SECTION *p_m_Lock; // edi
  void *m_hThread; // eax
  int v5; // eax
  CThread **v7; // eax
  unsigned int (__stdcall *v8)(void *); // eax
  HANDLE Thread; // eax
  std::map<CVProfNode *,double> *v10; // ecx
  CThread **v11; // [esp-10h] [ebp-240h]
  char v12; // [esp+Ah] [ebp-226h] BYREF
  _BYTE v13[4]; // [esp+Ch] [ebp-224h] BYREF
  CThreadEvent v14; // [esp+10h] [ebp-220h] BYREF
  unsigned int ExitCode[2]; // [esp+18h] [ebp-218h] BYREF
  char v16; // [esp+228h] [ebp-8h]
  int v17; // [esp+22Ch] [ebp-4h]

  p_m_Lock = (_RTL_CRITICAL_SECTION *)&this->m_Lock;
  ExitCode[1] = (unsigned int)this->m_Lock.m_CriticalSection;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock);
  v17 = 0;
  m_hThread = this->m_hThread;
  if ( m_hThread != nullptr && GetExitCodeThread(hThread: m_hThread, lpExitCode: ExitCode) && ExitCode[0] == 259 )
  {
    v5 = sub_3F008FA0(a1: "Assertion Failed: %s", (const char *)_rgcode_page_info[1].mbulinfo);
    ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: v5,
      a2: 0,
      a3: &__initialmbcinfo.mbcasemap[107],
      a4: 2617,
      a5: &unk_3F041A7D,
      a6: 0);
    v17 = -1;
    LeaveCriticalSection(lpCriticalSection: p_m_Lock);
    return 0;
  }
  else
  {
    v13[2] = 0;
    CThreadEvent::CThreadEvent(this: &v14, a2: false);
    v16 = 1;
    v7 = (CThread **)operator new(Size: 0xCu);
    if ( v7 != nullptr )
    {
      *v7 = this;
      v7[1] = (CThread *)v13;
      v7[2] = (CThread *)&v12;
    }
    else
    {
      v7 = nullptr;
    }
    v11 = v7;
    v8 = (unsigned int (__stdcall *)(void *))((int (__thiscall *)(CThread *))this->WaitForCreateComplete)(a1: this);
    Thread = CreateThread(
               lpThreadAttributes: nullptr,
               dwStackSize,
               lpStartAddress: v8,
               lpParameter: v11,
               dwCreationFlags: 0,
               lpThreadId: &this->m_threadId);
    this->m_hThread = Thread;
    if ( Thread != nullptr )
      JUMPOUT(0x3F010C86);
    return (unsigned __int8)std::map<CVProfNode *,double>::map<CVProfNode *,double>(this: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F010EB0
// Name: public: void __near * CThread::GetThreadHandle(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?GetNumBudgetGroups@CVProfile@@QAEHXZ'
void *__thiscall CThread::GetThreadHandle(CThread *this)
{
  return this->m_hThread;
}

//------------------------------------------------------------------------------
// Address: 0x3F010EC0
// Name: public: unsigned int CThread::GetThreadId(void)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?GetL2CacheMisses@CVProfNode@@QAEHXZ'
unsigned int __thiscall CThread::GetThreadId(CThread *this)
{
  return this->m_threadId;
}

//------------------------------------------------------------------------------
// Address: 0x3F010ED0
// Name: public: int CThread::GetResult(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThread::GetResult(CThread *this)
{
  return this->m_result;
}

//------------------------------------------------------------------------------
// Address: 0x3F010FB0
// Name: public: int CThread::GetPriority(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThread::GetPriority(CThread *this)
{
  return GetThreadPriority(hThread: this->m_hThread);
}

//------------------------------------------------------------------------------
// Address: 0x3F010FC0
// Name: public: bool CThread::SetPriority(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThread::SetPriority(CThread *this, int nPriority)
{
  void *m_hThread; // eax

  m_hThread = this->m_hThread;
  if ( m_hThread == nullptr )
    m_hThread = GetCurrentThread();
  return SetThreadPriority(hThread: m_hThread, nPriority);
}

//------------------------------------------------------------------------------
// Address: 0x3F010FF0
// Name: public: unsigned int CThread::Suspend(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThread::Suspend(CThread *this)
{
  return SuspendThread(hThread: this->m_hThread) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F011010
// Name: public: unsigned int CThread::Resume(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThread::Resume(CThread *this)
{
  return ResumeThread(hThread: this->m_hThread) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F011030
// Name: public: bool CThread::Terminate(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThread::Terminate(CThread *this, DWORD dwExitCode)
{
  if ( !TerminateThread(hThread: this->m_hThread, dwExitCode) )
    return 0;
  CloseHandle(hObject: this->m_hThread);
  this->m_hThread = nullptr;
  this->m_threadId = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F011070
// Name: public: static class CThread __near * CThread::GetCurrentCThread(void)
// Source: json
//------------------------------------------------------------------------------
static struct CThread *__cdecl CThread::GetCurrentCThread()
{
  return (struct CThread *)CThreadLocalBase::Get(this: (CThreadLocalBase *)dwTlsIndex);
}

//------------------------------------------------------------------------------
// Address: 0x3F011080
// Name: public: static void CThread::Yield(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CThread::Yield()
{
  Sleep(dwMilliseconds: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F011090
// Name: public: void CThread::Sleep(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThread::Sleep(CThread *this, DWORD a2)
{
  Sleep(dwMilliseconds: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F0112D0
// Name: public: CWorkerThread::CWorkerThread(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerThread *__thiscall CWorkerThread::CWorkerThread(CWorkerThread *this)
{
  CThread::CThread(this);
  this->__vftable = (CWorkerThread_vtbl *)&errtable[6];
  CThreadEvent::CThreadEvent(this: &this->m_EventSend, a2: true);
  CThreadEvent::CThreadEvent(this: &this->m_EventComplete, a2: true);
  this->m_Param = 0;
  this->m_ReturnVal = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F011350
// Name: public: int CWorkerThread::CallWorker(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::CallWorker(CWorkerThread *this, unsigned int a2, unsigned int a3, bool a4)
{
  return CWorkerThread::Call(this, a2, a3, a4, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F011370
// Name: public: int CWorkerThread::CallMaster(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::CallMaster(CWorkerThread *this, unsigned int a2, unsigned int a3)
{
  return CWorkerThread::Call(this, a2, a3, a4: false, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F0113A0
// Name: public: unsigned int CWorkerThread::GetCallParam(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWorkerThread::GetCallParam(CWorkerThread *this)
{
  return this->m_Param;
}

//------------------------------------------------------------------------------
// Address: 0x3F0113B0
// Name: public: int CWorkerThread::BoostPriority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::BoostPriority(CWorkerThread *this)
{
  int ThreadPriority; // edi
  HANDLE CurrentThread; // eax
  int v4; // ebx
  void *m_hThread; // eax

  ThreadPriority = GetThreadPriority(hThread: this->m_hThread);
  CurrentThread = GetCurrentThread();
  v4 = GetThreadPriority(hThread: CurrentThread);
  if ( v4 > ThreadPriority )
  {
    m_hThread = this->m_hThread;
    if ( m_hThread == nullptr )
      m_hThread = GetCurrentThread();
    SetThreadPriority(hThread: m_hThread, nPriority: v4);
  }
  return ThreadPriority;
}

//------------------------------------------------------------------------------
// Address: 0x3F0115D0
// Name: public: int CWorkerThread::WaitForReply(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::WaitForReply(CWorkerThread *this, unsigned int a2)
{
  return CWorkerThread::WaitForReply(this, a2, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F0115F0
// Name: protected: int CWorkerThread::WaitForReply(unsigned int,unsigned int (*)(unsigned int,void __near * const __near *,int,unsigned int))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerThread::WaitForReply(
        CWorkerThread *this,
        unsigned int a2,
        unsigned int (__stdcall *a3)(unsigned int, void *const *, int, unsigned int))
{
  CWorkerThread *v3; // esi
  void *m_hSyncObject; // ecx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // eax
  bool v10; // [esp+13h] [ebp-10Dh]
  _DWORD v12[2]; // [esp+18h] [ebp-108h] BYREF

  v3 = this;
  if ( a3 == nullptr )
    a3 = (unsigned int (__stdcall *)(unsigned int, void *const *, int, unsigned int))sub_3F0113F0;
  m_hSyncObject = this->m_EventComplete.m_hSyncObject;
  v12[0] = v3->m_hThread;
  v12[1] = m_hSyncObject;
  v10 = IsDebuggerPresent();
  do
  {
    if ( v3->m_hThread == nullptr )
      return v3->m_ReturnVal;
    v5 = a2;
    if ( a2 == -1 )
      v5 = 30000;
    v6 = a3(a1: 2u, a2: (void *const *)v12, a3: 0, a4: v5);
    v7 = v6;
    if ( a2 == -1 && v6 == 258 )
    {
      v8 = sub_3F008FA0(a1: "Assertion Failed: %s", (const char *)&__initiallocinfo.lc_category[5].wrefcount);
      ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: v8,
        a2: 0,
        a3: &__initialmbcinfo.mbcasemap[107],
        a4: 3299,
        a5: &unk_3F041A84,
        a6: 0);
      v3 = this;
    }
  }
  while ( v10 && a2 == -1 && v7 == 258 );
  if ( v7 != 1 )
  {
    if ( v7 == 258 )
    {
LABEL_17:
      v3->m_ReturnVal = -2;
      return v3->m_ReturnVal;
    }
    if ( v7 == 0 )
    {
      SetAssertDumpStack(bAssertDumpStack: (bool)"console");
      CThreadEvent::Reset(this: &v3->m_EventSend);
      goto LABEL_17;
    }
    CThreadEvent::Reset(this: &v3->m_EventSend);
    v3->m_ReturnVal = -3;
  }
  return v3->m_ReturnVal;
}

//------------------------------------------------------------------------------
// Address: 0x3F011710
// Name: public: bool CWorkerThread::WaitForCall(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerThread::WaitForCall(CWorkerThread *this, unsigned int *a2)
{
  bool result; // al

  result = CThreadSyncObject::Wait(this: &this->m_EventSend, a2: 0xFFFFFFFF);
  if ( a2 != nullptr )
    *a2 = this->m_Param;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F011740
// Name: public: bool CWorkerThread::WaitForCall(unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerThread::WaitForCall(CWorkerThread *this, unsigned int a2, unsigned int *a3)
{
  bool result; // al

  result = CThreadSyncObject::Wait(this: &this->m_EventSend, a2);
  if ( a3 != nullptr )
    *a3 = this->m_Param;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F011770
// Name: public: bool CWorkerThread::PeekCall(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerThread::PeekCall(CWorkerThread *this, unsigned int *a2)
{
  bool result; // al

  result = CThreadEvent::Check(this: &this->m_EventSend);
  if ( result )
  {
    if ( a2 != nullptr )
      *a2 = this->m_Param;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F001070
// Name: ?Unlock@CThreadFullMutex@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadFullMutex::Unlock(CThreadFullMutex *this@<ecx>, _BYTE *a2@<eax>, int a3@<ebx>)
{
  char v3; // al
  bool v4; // zf

  v3 = *a2 + (_BYTE)a2;
  v4 = v3 + *(_BYTE *)(a3 + 28442616) == 0;
  *(_BYTE *)(a3 + 28442616) += v3;
  if ( v4 )
    JUMPOUT(0x3F00107A);
  JUMPOUT(0x3F001084);
}

//------------------------------------------------------------------------------
// Address: 0x3F001080
// Name: ??_FCThreadFullMutex@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadFullMutex::`default constructor closure'(
        CThreadFullMutex *this@<ecx>,
        int a2@<eax>,
        int a3@<ebp>)
{
  if ( *(_DWORD *)(a3 + 12) >= a2 )
    JUMPOUT(0x3F00108B);
  JUMPOUT(0x3F001093);
}

//------------------------------------------------------------------------------
// Address: 0x3F0077A0
// Name: ?CreateSimpleThread@@YAPAUThreadHandle_t__@@P6AIPAX@Z0PAKI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CreateSimpleThread(CThreadSpinRWLock *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<esi>)
{
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  int v6; // eax
  int v7; // [esp-4h] [ebp-4h]

  --*(_DWORD *)(a2 + 273583600);
  *(_DWORD *)(a3 - 8) = a4;
  *(_DWORD *)(a3 - 24) = a1;
  CThreadSpinRWLock::LockForRead(this: a1);
  v7 = *(_DWORD *)(a3 + 8);
  *(_DWORD *)(a3 - 16) = 0x7FFFFFFF;
  v4 = sub_3F004360(a1: v7);
  v5 = v4;
  if ( v4 != nullptr )
  {
    if ( v4[1] != -168890355 )
      ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: "Assertion Failed: pdw[1] == FREE_BLOCK_MARKER",
        a2: 0,
        a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\tier0\\memstd.h",
        a4: 95,
        a5: &unk_3F041A33,
        a6: 0);
    v5[1] = 0;
  }
  if ( v5 == nullptr )
  {
    v6 = *(_DWORD *)(a3 + 8);
    *(_DWORD *)(a3 - 20) = *(_DWORD *)(v6 + 16);
    *(_DWORD *)(a3 - 12) = v6 + 8;
    if ( **(_DWORD **)(a3 - 12) != 0 )
      JUMPOUT(0x3F007828);
    JUMPOUT(0x3F0078E5);
  }
  JUMPOUT(0x3F007855);
}

//------------------------------------------------------------------------------
// Address: 0x3F007A80
// Name: ??0CThreadSyncObject@@IAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F007A90
// Name: ??1CThreadSyncObject@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F007AD0
// Name: ??7CThreadSyncObject@@QBE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadSyncObject::operator!(CThreadSyncObject *this@<ecx>, char a2@<zf>)
{
  if ( !a2 )
    JUMPOUT(0x3F007AD8);
  JUMPOUT(0x3F007AF6);
}

//------------------------------------------------------------------------------
// Address: 0x3F007AE0
// Name: ?AssertUseable@CThreadSyncObject@@IAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadSyncObject::AssertUseable(
        CThreadSyncObject *this@<ecx>,
        int a2@<eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        int a5@<esi>)
{
  LOBYTE(a2) = (a2 | 0xE8) + 127;
  _InterlockedExchangeAdd((volatile signed __int32 *)(a5 + 8 * a2 + 60), 0xFFFFFFFF);
  _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)(a4 + 8) + 32), 1u);
  if ( *(_DWORD *)(a3 + 4) == -168890355 )
  {
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: pdw[1] != FREE_BLOCK_MARKER",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\tier0\\memstd.h",
      a4: 79,
      a5: &unk_3F041A32,
      a6: 0);
    JUMPOUT(0x3F007B27);
  }
  *(_DWORD *)(a3 + 4) = -168890355;
  JUMPOUT(0x3F007B2F);
}

//------------------------------------------------------------------------------
// Address: 0x3F007B30
// Name: ?Wait@CThreadSyncObject@@QAE_NI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThreadSyncObject::Wait(CThreadSyncObject *this, unsigned int dwTimeout, unsigned int dwTimeouta)
{
  CThreadSpinRWLock::UnlockRead((CThreadSpinRWLock *)this);
}

//------------------------------------------------------------------------------
// Address: 0x3F007B90
// Name: ??0CThreadEvent@@QAE@_N@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CThreadEvent *__userpurge CThreadEvent::CThreadEvent@<eax>(
        CThreadEvent *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        unsigned int a4@<edi>,
        CThreadSpinRWLock *a5@<esi>,
        bool bManualReset)
{
  int v6; // eax
  int v7; // edi
  int v8; // esi
  void *v9; // esp
  void *v10; // esp
  void *v11; // esp
  int v12; // ecx
  int v13; // edx
  const char **v14; // esi
  const char *v15; // edx
  const char *v17; // [esp-4h] [ebp-4h] BYREF

  _mm_pause();
  CThreadSpinRWLock::SpinLockForWrite(this: a5, a2: a4);
  v6 = *(_DWORD *)(a3 + 8);
  v7 = *(_DWORD *)(v6 + 12);
  if ( v7 != a2 )
  {
    v8 = 4 * *(_DWORD *)(v6 + 20);
    v9 = alloca(v8);
    *(_DWORD *)(a3 - 12) = &v17;
    v10 = alloca(v8);
    *(_DWORD *)(a3 - 28) = &v17;
    v11 = alloca(v8);
    v12 = *(_DWORD *)(a3 - 12) - (_DWORD)&v17;
    v13 = *(_DWORD *)(a3 - 28) - (_DWORD)&v17;
    *(_DWORD *)(a3 - 16) = &v17;
    *(_DWORD *)(a3 - 24) = a2;
    v14 = &v17;
    *(_DWORD *)(a3 - 40) = v12;
    *(_DWORD *)(a3 - 36) = v13;
    do
    {
      if ( *(_DWORD *)(v7 + 12) == 0 )
      {
        *(const char **)((char *)v14 + v12) = (const char *)v7;
        v15 = *(const char **)(a3 - 24);
        ++a2;
        *v14 = (const char *)(*(_DWORD *)(*(_DWORD *)(a3 - 8) + 36) + (((v7 - *(_DWORD *)(a3 - 8) - 48) / 24) << 16));
        *(const char **)((char *)v14++ + *(_DWORD *)(a3 - 36)) = v15;
        if ( *(_BYTE *)(a3 + 12) != 0 )
          break;
        v12 = *(_DWORD *)(a3 - 40);
      }
      *(_DWORD *)(a3 - 24) = v7;
      v7 = *(_DWORD *)(v7 + 8);
    }
    while ( v7 != 0 );
    if ( a2 != 0 )
    {
      if ( (unsigned __int8)((int (__stdcall *)(_DWORD))loc_3F008AC0)(a1: *(_DWORD *)(a3 + 8)) == 0 )
        JUMPOUT(0x3F007C5C);
      JUMPOUT(0x3F007C69);
    }
    a5 = *(CThreadSpinRWLock **)(a3 - 32);
  }
  CThreadSpinRWLock::UnlockWrite(this: a5, a2: v17);
  if ( *(_BYTE *)(a3 - 1) != 0 )
    Warning(
      a1: "***** HEAP IS CORRUPT (free compromised for block size %d,in %s heap, possible write after free *****)\n",
      *(_DWORD *)(*(_DWORD *)(a3 + 8) + 16),
      "virtual");
  return *(CThreadEvent **)(a3 - 20);
}

//------------------------------------------------------------------------------
// Address: 0x3F007C60
// Name: ??0CThreadEvent@@QAE@PAX_N@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CThreadEvent *__userpurge CThreadEvent::CThreadEvent@<eax>(
        CThreadEvent *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        void *hSyncObject,
        bool bOwnEventHandle)
{
  unsigned int v6; // eax
  int v7; // edx
  int v8; // esi
  int v9; // eax
  int *v10; // ecx
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  int v15; // edi
  volatile signed __int64 *v16; // esi
  unsigned int *v17; // eax
  const char *v19; // [esp-4h] [ebp-4h]

  *(_BYTE *)(a3 - 1) = 1;
  *(_DWORD *)(a3 - 20) = a2 << 16;
  v6 = 0x10000u / *(_DWORD *)(a4 + 16);
  *(_DWORD *)(a4 + 20) -= a2;
  _InterlockedExchangeAdd((volatile signed __int32 *)(a4 + 32), -(a2 * v6));
  v7 = a2 - 1;
  if ( a2 - 1 >= 0 )
  {
    v8 = *(_DWORD *)(a3 - 12);
    v9 = *(_DWORD *)(a3 - 28) - v8;
    v10 = (int *)(v8 + 4 * v7);
    for ( *(_DWORD *)(a3 - 40) = v9; ; v9 = *(_DWORD *)(a3 - 40) )
    {
      v11 = *(int *)((char *)v10 + v9);
      v12 = *v10;
      if ( v11 != 0 )
      {
        *(_DWORD *)(v11 + 8) = *(_DWORD *)(v12 + 8);
        a4 = *(_DWORD *)(a3 + 8);
      }
      else
      {
        *(_DWORD *)(a4 + 12) = *(_DWORD *)(v12 + 8);
      }
      --v7;
      --v10;
      *(_DWORD *)(v12 + 8) = 0;
      *(_DWORD *)(v12 + 4) = 0;
      if ( v7 < 0 )
        break;
    }
  }
  v13 = *(_DWORD *)(a3 - 8);
  v14 = *(__int16 *)(v13 + 12);
  if ( (*(_BYTE *)(a3 + 12) != 0 ? 32 : 4) - v14 > 0 )
  {
    v15 = (*(_BYTE *)(a3 + 12) != 0 ? 32 : 4) - v14;
    if ( v15 >= a2 )
      v15 = a2;
    if ( v15 != 0 )
    {
      v16 = (volatile signed __int64 *)(v13 + 8);
      do
      {
        v17 = *(unsigned int **)(*(_DWORD *)(a3 - 12) + 4 * a2-- - 4);
        --v15;
        sub_3F0042F0(a1: v16, a2: v17);
      }
      while ( v15 != 0 );
    }
  }
  if ( a2 != 0 )
    JUMPOUT(0x3F007D23);
  CThreadSpinRWLock::UnlockWrite(this: *(CThreadSpinRWLock **)(a3 - 32), a2: v19);
  if ( *(_BYTE *)(a3 - 1) != 0 )
    Warning(
      a1: "***** HEAP IS CORRUPT (free compromised for block size %d,in %s heap, possible write after free *****)\n",
      *(_DWORD *)(*(_DWORD *)(a3 + 8) + 16),
      "virtual");
  return *(CThreadEvent **)(a3 - 20);
}

//------------------------------------------------------------------------------
// Address: 0x3F007E70
// Name: ?Set@CThreadEvent@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F007E90
// Name: ?Reset@CThreadEvent@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CThreadEvent::Reset(
        CThreadEvent *this@<ecx>,
        __int16 _DX@<dx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  __asm { insb }
  this->m_hSyncObject = (char *)this->m_hSyncObject + 208898816;
  *(_DWORD *)(a3 - 4) = 0;
  if ( a5 == 0 )
  {
    if ( a4 != 0 )
    {
      *(_DWORD *)(a3 + 8) = 661;
      JUMPOUT(0x3F007FD9);
    }
    JUMPOUT(0x3F007F5D);
  }
  *(_DWORD *)(a3 - 20) = *(_DWORD *)(a3 - 12) - *(_DWORD *)(a3 - 8);
  JUMPOUT(0x3F007EE9);
}

//------------------------------------------------------------------------------
// Address: 0x3F007EF0
// Name: ?Check@CThreadEvent@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadEvent::Check(
        CThreadEvent *this@<ecx>,
        unsigned int a2@<edx>,
        _DWORD *a3@<ebx>,
        int a4@<ebp>,
        int *a5@<edi>,
        int a6@<esi>)
{
  int v6; // eax
  int v7; // esi

  if ( a2 <= a3[5] )
  {
    v6 = *a5;
    if ( a3[2] >= (unsigned int)*a5 && a3[2] < (unsigned int)(v6 + 0x10000) )
      *(int *)((char *)a5 + *(_DWORD *)(a4 - 20)) = (unsigned int)(v6 - a3[2] + 0x10000) / a3[4];
    v7 = *(_DWORD *)(a6 + 8);
    ++*(_DWORD *)(a4 - 4);
    if ( v7 == 0 )
    {
      if ( *(_DWORD *)(a4 - 4) != a3[5] )
      {
        *(_DWORD *)(a4 + 8) = 693;
        JUMPOUT(0x3F007FD9);
      }
      JUMPOUT(0x3F007F5D);
    }
    JUMPOUT(0x3F007EC4);
  }
  JUMPOUT(0x3F007F51);
}

//------------------------------------------------------------------------------
// Address: 0x3F008010
// Name: ??0CThreadSemaphore@@QAE@JJ@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CThreadSemaphore *__userpurge CThreadSemaphore::CThreadSemaphore@<eax>(
        CThreadSemaphore *this@<ecx>,
        char a2@<zf>,
        char a3@<sf>,
        char a4@<of>,
        char a5@<dh>,
        unsigned int a6@<ebx>,
        int a7@<ebp>,
        int a8@<edi>,
        _DWORD *a9@<esi>,
        int initialValue,
        int maxValue)
{
  char *v11; // eax
  char *v12; // ecx

  if ( a3 ^ a4 | a2 )
    JUMPOUT(0x3F008036);
  *(_BYTE *)(a7 + 46) += a5;
  v11 = (char *)VirtualAlloc(lpAddress: nullptr, dwSize: 0x40000000u, flAllocationType: 0x2000u, flProtect: 1u);
  v12 = nullptr;
  a9[9] = v11;
  if ( v11 != nullptr )
  {
    v12 = v11 + 0x40000000;
    a9[8] = v11;
  }
  else
  {
    a9[8] = 0;
  }
  a9[10] = v12;
  if ( (a6 & 7) != 0 || a6 < 8 )
    __debugbreak();
  *(_DWORD *)(a8 + 16) = a6;
  _InterlockedExchange((volatile __int32 *)(a8 + 8), 0);
  *(_DWORD *)(a8 + 20) = 0;
  return (CThreadSemaphore *)(a8 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F008160
// Name: ?Release@CThreadSemaphore@@QAE_NJPAJ@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F008180
// Name: ??0CThreadFullMutex@@QAE@_NPBD@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F008250
// Name: ?Release@CThreadFullMutex@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall __noreturn CThreadFullMutex::Release(CThreadFullMutex *this)
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F008260
// Name: ??0CThreadLocalBase@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CThreadLocalBase *__userpurge CThreadLocalBase::CThreadLocalBase@<eax>(
        CThreadLocalBase *this@<ecx>,
        int a2@<edi>,
        int a3)
{
  *(_BYTE *)(a2 - 397571312) = __ROL1__(*(_BYTE *)(a2 - 397571312), (char)this);
  CThreadSpinRWLock::UnlockRead((CThreadSpinRWLock *)this);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F0082D0
// Name: ??1CThreadLocalBase@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadLocalBase::~CThreadLocalBase(
        CThreadLocalBase *this@<ecx>,
        unsigned int a2@<eax>,
        char a3@<dh>,
        __int16 a4@<bx>,
        int a5@<ebp>,
        int a6@<esi>)
{
  bool v6; // of

  v6 = __OFADD__(a3, HIBYTE(a4));
  HIBYTE(a4) += a3;
  if ( v6 )
  {
    *((_DWORD *)this + 3) = a6;
    _InterlockedExchangeAdd((volatile signed __int32 *)this + 8, a2);
    ++*((_DWORD *)this + 5);
    _InterlockedExchange(*(volatile __int32 **)(a5 - 12), a4);
    JUMPOUT(0x3F0082EA);
  }
  JUMPOUT(0x3F0082E4);
}

//------------------------------------------------------------------------------
// Address: 0x3F0082F0
// Name: ?Get@CThreadLocalBase@@QBEPAXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadLocalBase::Get(
        CThreadLocalBase *this@<ecx>,
        unsigned int a2@<eax>,
        unsigned __int16 a3@<dx>,
        int a4@<ebx>)
{
  --*(_DWORD *)(a4 - 2062613423);
  __outdword(a3, a2);
  JUMPOUT(0x3F0082F8);
}

//------------------------------------------------------------------------------
// Address: 0x3F008350
// Name: ?Set@CThreadLocalBase@@QAEXPAX@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0085D0
// Name: ??0CThreadMutex@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadMutex::CThreadMutex(CThreadMutex *this@<ecx>, int a2@<ebx>)
{
  if ( a2 != 0 )
    JUMPOUT(0x3F0085EF);
  JUMPOUT(0x3F0086BB);
}

//------------------------------------------------------------------------------
// Address: 0x3F0085F0
// Name: ??1CThreadMutex@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadMutex::~CThreadMutex(CThreadMutex *this@<ecx>, char a2@<zf>)
{
  if ( a2 )
    JUMPOUT(0x3F0085F8);
  JUMPOUT(0x3F0085E0);
}

//------------------------------------------------------------------------------
// Address: 0x3F008890
// Name: ?LockForWrite@CThreadRWLock@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CThreadRWLock::LockForWrite(
        CThreadRWLock *this@<ecx>,
        int a2@<eax>,
        int *a3@<edx>,
        int a4@<ebx>,
        int a5@<ebp>,
        int a6)
{
  int v6; // esi
  const char *v7; // [esp-4h] [ebp-4h]

  while ( 1 )
  {
    v6 = *a3++;
    if ( a2 - *(_DWORD *)(a4 + 12) != v6 )
      break;
    a4 = *(_DWORD *)(a4 + 8);
    if ( a4 == 0 )
      goto LABEL_5;
  }
  *(_DWORD *)(a5 + 8) = 733;
LABEL_5:
  CThreadSpinRWLock::UnlockWrite(this: *(CThreadSpinRWLock **)(a5 - 24), a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x3F008A20
// Name: ?SpinLockForWrite@CThreadSpinRWLock@@AAEXI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CThreadSpinRWLock::SpinLockForWrite(
        CThreadSpinRWLock *this@<ecx>,
        unsigned __int64 a2@<edx:eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        _DWORD *a5@<esi>,
        const unsigned int threadId)
{
  int v6; // eax
  unsigned int v7; // edi
  int v8; // ecx
  unsigned int v9; // edx
  int v10; // ebx
  int *v11; // edx
  int v12; // esi
  const char *v13; // [esp-4h] [ebp-4h]

  *(char *)(a2 + 0x10000) >>= (char)this;
  v6 = a2 / *(unsigned int *)(a3 + 16);
  if ( a5 != nullptr )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(a4 - 4);
      v8 = 0;
      if ( v7 != 0 )
      {
        while ( 1 )
        {
          v9 = *(_DWORD *)(*(_DWORD *)(a4 - 8) + 4 * v8);
          if ( (unsigned int)a5 >= v9 && (unsigned int)a5 < v9 + 0x10000 )
            break;
          if ( ++v8 >= v7 )
            goto LABEL_8;
        }
        ++*(_DWORD *)(*(_DWORD *)(a4 - 12) + 4 * v8);
      }
LABEL_8:
      if ( v8 == v7 )
        break;
      a5 = (_DWORD *)*a5;
      if ( a5 == nullptr )
        goto LABEL_10;
    }
    *(_DWORD *)(a4 + 8) = 719;
  }
  else
  {
LABEL_10:
    v10 = *(_DWORD *)(a3 + 12);
    if ( v10 != 0 )
    {
      v11 = *(int **)(a4 - 12);
      while ( 1 )
      {
        v12 = *v11++;
        if ( v6 - *(_DWORD *)(v10 + 12) != v12 )
          break;
        v10 = *(_DWORD *)(v10 + 8);
        if ( v10 == 0 )
          goto LABEL_17;
      }
      *(_DWORD *)(a4 + 8) = 733;
    }
  }
LABEL_17:
  CThreadSpinRWLock::UnlockWrite(this: *(CThreadSpinRWLock **)(a4 - 24), a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x3F008B60
// Name: ?LockForRead@CThreadSpinRWLock@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThreadSpinRWLock::LockForRead(CThreadSpinRWLock *this@<ecx>, _DWORD *a2@<eax>)
{
  *a2 += a2;
  __outbyte(0xE5u, BYTE1(this) + (_BYTE)a2);
  JUMPOUT(0x3F008B68);
}

//------------------------------------------------------------------------------
// Address: 0x3F008CE0
// Name: ?UnlockRead@CThreadSpinRWLock@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThreadSpinRWLock::UnlockRead(CThreadSpinRWLock *this)
{
  if ( this == nullptr )
    JUMPOUT(0x3F008C70);
  JUMPOUT(0x3F008CA9);
}

//------------------------------------------------------------------------------
// Address: 0x3F008D00
// Name: sub_3F008D00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F008D00(volatile __int32 *this, CSmallBlockHeap *a2, volatile __int32 *a3, int a4, char a5)
{
  int v5; // ebx
  void *v6; // esp
  volatile __int32 *v7; // esi
  bool v8; // cf
  unsigned int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  unsigned int *v12; // eax
  unsigned int *v13; // esi
  void *v14; // esp
  int v15; // ecx
  _DWORD *v16; // eax
  int v17; // eax
  int v18; // ecx
  _DWORD v19[4]; // [esp+0h] [ebp-24h] BYREF
  int v20; // [esp+10h] [ebp-14h]
  _DWORD *v21; // [esp+14h] [ebp-10h]
  int v22; // [esp+18h] [ebp-Ch]
  int *i; // [esp+1Ch] [ebp-8h]
  unsigned int v24; // [esp+20h] [ebp-4h]

  v5 = a4;
  v6 = alloca(4 * a4);
  v21 = v19;
  v24 = 0;
  if ( a4 > 0 )
  {
    v7 = a3;
    this = (volatile __int32 *)&a2->m_PoolLookup[2];
    for ( i = (int *)a4; i != nullptr; i = (int *)((char *)i - 1) )
    {
      v8 = *this < (unsigned __int32)*v7;
      v9 = *v7 + 0x10000;
      *(volatile __int32 *)((char *)v7 + (char *)v19 - (char *)a3) = v9;
      if ( !v8 && *this < v9 )
      {
        v24 = (v9 - *this) / (unsigned __int32)a2->m_PoolLookup[4];
        _InterlockedExchange(this, 0);
      }
      ++v7;
    }
    v5 = a4;
  }
  v10 = 0x10000 % (unsigned int)a2->m_PoolLookup[4];
  v24 = v5 * (0x10000 / (unsigned int)a2->m_PoolLookup[4]) - v24;
  if ( a5 != 0 && (CSmallBlockPool *)((char *)a2->m_PoolLookup[5] - v5) != (CSmallBlockPool *)1 )
  {
    v11 = ((int (__fastcall *)(volatile __int32 *, unsigned int))loc_3F007220)(a1: this, a2: v10);
    v20 = *(_DWORD *)(v11 + 36);
    v22 = v11;
    sub_3F0043F0(this: a2);
    v13 = v12;
    v14 = alloca(4 * (int)a2->m_PoolLookup[5]);
    i = v19;
    if ( v12 != nullptr )
    {
      v15 = 0;
      v19[3] = *v12;
      if ( v5 > 0 )
      {
        v16 = v21;
        do
        {
          if ( (unsigned int)v13 >= *(_DWORD *)((char *)v16 + (char *)a3 - (char *)v21) && (unsigned int)v13 < *v16 )
            JUMPOUT(0x3F008ED4);
          ++v15;
          ++v16;
        }
        while ( v15 < v5 );
      }
      v17 = ((int)v13 - v20) / 0x10000;
      v18 = v22 + 24 * v17;
      if ( *(_WORD *)(v18 + 68) == 0 )
        *i = v17;
      sub_3F0042F0(a1: (volatile signed __int64 *)(v18 + 64), a2: v13);
      JUMPOUT(0x3F008E42);
    }
    JUMPOUT(0x3F008E62);
  }
  JUMPOUT(0x3F008EE0);
}

//------------------------------------------------------------------------------
// Address: 0x3F008E90
// Name: ?UnlockWrite@CThreadSpinRWLock@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CThreadSpinRWLock::UnlockWrite(
        CThreadSpinRWLock *this@<ecx>,
        int a2@<edx>,
        int a3@<ebx>,
        int a4@<ebp>,
        _DWORD *a5@<edi>,
        int a6,
        int a7,
        int a8,
        int a9)
{
  --*(_DWORD *)(a3 + 1075088647);
  if ( sub_3F004360(a1: a3 + 8 * a2 + 64) != nullptr )
LABEL_8:
    JUMPOUT(0x3F008E8C);
  while ( 1 )
  {
    ++a5;
    if ( (*(_DWORD *)(a4 + 20))-- == 1 )
      break;
    if ( sub_3F004360(a1: *(_DWORD *)(a4 - 12) + 24 * *a5 + 64) != nullptr )
      goto LABEL_8;
  }
  if ( *(_DWORD *)(a4 - 4) != *(_DWORD *)(a4 + 16) && IsDebuggerPresent() )
    __debugbreak();
}

//------------------------------------------------------------------------------
// Address: 0x3F008F80
// Name: ??0CThread@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CThread *__usercall CThread::CThread@<eax>(CThread *this@<ecx>, int a2@<edx>, int a3@<ebp>)
{
  return (CThread *)(*(__int16 *)&this->m_szName[8 * a2 + 20]
                   - *(__int16 *)&this->m_szName[24 * **(_DWORD **)(a3 + 12) + 20]);
}

//------------------------------------------------------------------------------
// Address: 0x3F008FA0
// Name: sub_3F008FA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall sub_3F008FA0@<eax>(char *a1@<esi>, char *Format, ...)
{
  va_list ArgList; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ArgList, Format);
  sub_3F01ACDC(Buffer: a1, BufferCount: 0xFFu, Format, ArgList);
  a1[255] = 0;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F009000
// Name: ??1CThread@@UAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThread::~CThread(CThread *this)
{
  if ( dword_3F0415D0 != nullptr )
    dword_3F0415D0(a1: &CriticalSection);
  else
    EnterCriticalSection(lpCriticalSection: &CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F009020
// Name: BBlockingGetMiniDumpLock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool BBlockingGetMiniDumpLock()
{
  int v0; // esi
  bool result; // al

  v0 = 10000;
  if ( dword_3F0415D0 != nullptr )
  {
    result = dword_3F0415D0(a1: &CriticalSection) != 0;
  }
  else
  {
    EnterCriticalSection(lpCriticalSection: &CriticalSection);
    result = true;
  }
  while ( !result )
  {
    if ( v0 <= 0 )
      break;
    _mm_pause();
    Sleep(dwMilliseconds: 0xAu);
    v0 -= 10;
    if ( dword_3F0415D0 != nullptr )
    {
      result = dword_3F0415D0(a1: &CriticalSection) != 0;
    }
    else
    {
      EnterCriticalSection(lpCriticalSection: &CriticalSection);
      result = true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F009450
// Name: ?IsAlive@CThread@@QAE_NXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThread::IsAlive(
        CThread *this@<ecx>,
        int a2@<eax>,
        int a3@<edx>,
        int a4@<ebx>,
        int a5@<ebp>,
        unsigned int _EDI@<edi>,
        int a7@<esi>)
{
  unsigned int dwExitCode; // [esp+0h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+8h] [ebp+0h] BYREF

  dwExitCode = _EDI;
  __asm { repne add edi, [edi] }
  _EDI(a1: this, a2, a3, a4: this, a5: a4, a6: &retaddr, a7: a5, a8: dwExitCode, a9: a7);
  if ( (_BYTE)a4 == 0 )
  {
    byte_3F03D369 = 1;
    ((void (__cdecl *)(const char *, int))loc_3F01AB6B)(a1: ".\\minidump.cpp", a2: 92);
    ((void (__cdecl *)(const char *, int))loc_3F01AB6B)(a1: ".\\minidump.cpp", a2: 47);
    JUMPOUT(0x3F00947F);
  }
  JUMPOUT(0x3F00958F);
}

//------------------------------------------------------------------------------
// Address: 0x3F009480
// Name: ?Join@CThread@@QAE_NI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CThread::Join(
        CThread *this@<ecx>,
        unsigned int a2@<eax>,
        unsigned int a3@<esi>,
        unsigned int timeout,
        unsigned int timeouta,
        int a6,
        char a7)
{
  char v7; // al
  int v8; // esi

  if ( a3 < a2 )
    a3 = a2;
  if ( a3 != 0 )
    dword_3F03D2A8 = a3 + 1;
  else
    dword_3F03D2A8 = (int)".\\minidump.cpp";
  dword_3F03D2A4 = 187;
  dword_3F03D2A0 = 2;
  v7 = (unsigned __int8)sub_3F008FA0(
                          a1: &a7,
                          Format: "Assertion Failed: %s",
                          "Someone called ClearWritingMinidump without holding the minidump lock.");
  v8 = SpewMessage(a1: &unk_3F030FBC, a2: v7);
  byte_3F0A3604 = 1;
  if ( dword_3F03D370 != nullptr )
    dword_3F03D370();
  if ( v8 == 0 )
    JUMPOUT(0x3F0094F4);
  JUMPOUT(0x3F009545);
}

//------------------------------------------------------------------------------
// Address: 0x3F009500
// Name: ?GetThreadHandle@CThread@@QAEPAXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F009510
// Name: ?GetResult@CThread@@QAEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThread::GetResult(CThread *this)
{
  JUMPOUT(0x3F009515);
}

//------------------------------------------------------------------------------
// Address: 0x3F009520
// Name: ?Stop@CThread@@QAEXH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CThread::Stop(
        CThread *this@<ecx>,
        int _EAX@<eax>,
        int (*a3)(void)@<ebx>,
        void (__cdecl *a4)(_RTL_CRITICAL_SECTION *)@<edi>)
{
  char *v5; // eax
  char *v6; // [esp-10h] [ebp-10h]
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h]

  __asm { aas }
  sub_3F008FA0(a1: (char *)&STACK[0x108], Format: v6);
  if ( DoNewAssertDialog() != 0 )
    __debugbreak();
  if ( byte_3F041A50 == 0 && a3() == 0 )
  {
    v5 = sub_3F008FA0(
           a1: (char *)&STACK[0x208],
           Format: "Assertion Failed: %s",
           "Someone called ClearWritingMinidump without holding the minidump lock.");
    WriteMiniDump(a1: v5, a2: ".\\minidump.cpp", a3: 187, a4: 0, a5: 0);
    byte_3F041A50 = 1;
  }
  byte_3F03D369 = 0;
  a4(a1: &CriticalSection);
  byte_3F03D3C4 = 0;
  byte_3F03D36B = 0;
  if ( HIBYTE(retaddr) != 0 )
    a4(a1: &CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F009600
// Name: ?SetPriority@CThread@@QAE_NH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CThread::SetPriority(CThread *this@<ecx>, int a2@<ebp>, _WORD *a3@<edi>, int a4@<esi>, int priority)
{
  int v5; // ebx
  int v6; // eax
  const char *v7; // [esp-10h] [ebp-10h]
  wchar_t *v8; // [esp-8h] [ebp-8h]
  int v9; // [esp-4h] [ebp-4h]

  v5 = a4 - 1;
  v7 = *(const char **)(a2 + 8);
  *a3 = 0;
  v6 = MultiByteToWideChar(
         CodePage: 0xFDE9u,
         dwFlags: 0,
         lpMultiByteStr: v7,
         cbMultiByte: a4 - 1,
         lpWideCharStr: v8,
         cchWideChar: v9);
  if ( v6 != 0 )
  {
    if ( v6 < v5 )
      JUMPOUT(0x3F009622);
    a3[v5] = 0;
    JUMPOUT(0x3F00962F);
  }
  JUMPOUT(0x3F00963B);
}

//------------------------------------------------------------------------------
// Address: 0x3F009630
// Name: ?Suspend@CThread@@QAEIXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThread::Suspend(CThread *this@<ecx>, char a2@<cf>, int a3@<eax>, void *a4@<edi>, const char *a5@<esi>)
{
  if ( (HMODULE (__stdcall **)(LPCWSTR, HANDLE, DWORD))((char *)&LoadLibraryExW + a2 + a3) == nullptr )
  {
    LoadLibraryExA(lpLibFileName: a5, hFile: nullptr, dwFlags: 8u);
    JUMPOUT(0x3F009646);
  }
  j_j__free(Block: a4);
  JUMPOUT(0x3F00964E);
}

//------------------------------------------------------------------------------
// Address: 0x3F009650
// Name: ?Resume@CThread@@QAEIXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int __usercall CThread::Resume@<eax>(CThread *this@<ecx>, int a2@<ebx>)
{
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F009670
// Name: ?Terminate@CThread@@QAE_NH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CThread::Terminate(CThread *this@<ecx>, char a2@<al>, int a3@<ebp>, int exitCode)
{
  if ( a2 == 0 )
  {
    *(_BYTE *)(a3 - 131068) = 0;
    byte_3F03F280 = 1;
    memset_0(a1: (void *)(a3 - 131067), Val: 0, Size: 0x1FFFBu);
    ((void (__cdecl *)(int))byte_3F01A077)(a1: 65534);
    JUMPOUT(0x3F0096A5);
  }
  JUMPOUT(0x3F009787);
}

//------------------------------------------------------------------------------
// Address: 0x3F0096B0
// Name: ?GetCurrentCThread@CThread@@SAPAV1@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CThread::GetCurrentCThread()
{
  GetModuleHandleA(lpModuleName: "tier0_s.dll");
  JUMPOUT(0x3F0096BC);
}

//------------------------------------------------------------------------------
// Address: 0x3F0096C0
// Name: ?Yield@CThread@@SAXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F009760
// Name: ?ThreadProc@CThread@@CGIPAX@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool CThread::ThreadProc()
{
  FARPROC ProcAddress; // eax
  const char *v4; // [esp+10h] [ebp-8h]

  __asm { aas }
  ProcAddress = GetProcAddress(hModule: _EAX, lpProcName: v4);
  dword_3F03F288 = (int)ProcAddress;
  if ( ProcAddress == nullptr )
    return false;
  dword_3F03F284 = ((int (__cdecl *)(const char *, _DWORD))ProcAddress)(a1: "crashhandler001", a2: 0);
  return dword_3F03F284 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F0098F0
// Name: ??0CWorkerThread@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWorkerThread *__usercall CWorkerThread::CWorkerThread@<eax>(CWorkerThread *this@<ecx>, char a2@<zf>)
{
  if ( a2 )
    LOBYTE(this->__vftable) = 92;
  if ( this != (CWorkerThread *)-1 )
    JUMPOUT(0x3F0098E8);
  return ((CWorkerThread *(__cdecl *)(void *))loc_3F0095C0)(a1: &unk_3F03F290);
}

//------------------------------------------------------------------------------
// Address: 0x3F009980
// Name: ?CallWorker@CWorkerThread@@QAEHII_N@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F0099A0
// Name: ?CallMaster@CWorkerThread@@QAEHII@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CWorkerThread::CallMaster(CWorkerThread *this, unsigned int dw, unsigned int timeout)
{
  sub_3F01C63B(a1: "2010");
  JUMPOUT(0x3F0099B7);
}

//------------------------------------------------------------------------------
// Address: 0x3F0099C0
// Name: ?GetTotalCalls@CVProfNode@@QAEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfNode::GetTotalCalls(CVProfNode *this)
{
  JUMPOUT(0x3F0099C4);
}

//------------------------------------------------------------------------------
// Address: 0x3F0099D0
// Name: ?GetCallParam@CWorkerThread@@QBEIXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CWorkerThread::GetCallParam(CWorkerThread *this@<ecx>, int _EAX@<eax>)
{
  __asm { aam     2Ch ; ',' }
  *_EAX += _EAX;
  JUMPOUT(0x3F0099D4);
}

//------------------------------------------------------------------------------
// Address: 0x3F0099E0
// Name: ?BoostPriority@CWorkerThread@@QAEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CWorkerThread::BoostPriority(CWorkerThread *this)
{
  int v2; // [esp-38h] [ebp-44h]
  int v3; // [esp-34h] [ebp-40h]
  int v4; // [esp-30h] [ebp-3Ch]
  int v5; // [esp-2Ch] [ebp-38h]
  int v6; // [esp-28h] [ebp-34h]
  int v7; // [esp-24h] [ebp-30h]

  return ((int (*)(char *, int, const char *, ...))_LN10_6)(
           a1: &byte_3F03F494,
           a2: 15,
           a3: "%04d%02d%02d%02d%02d%02d",
           v2,
           v3,
           v4,
           v5,
           v6,
           v7);
}

//------------------------------------------------------------------------------
// Address: 0x3F009A00
// Name: SetMiniDumpAppID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl SetMiniDumpAppID(int a1)
{
  dword_3F03D3C8 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F009A10
// Name: SetMiniDumpBuildID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl SetMiniDumpBuildID(int a1)
{
  dword_3F03D3CC = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F009A30
// Name: ?Call@CWorkerThread@@IAEHII_NP6GIIPBQAXHI@Z@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall CWorkerThread::Call@<eax>(CWorkerThread *this@<ecx>, int _EAX@<eax>)
{
  int result; // eax

  __asm { aam     0D3h }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F009A40
// Name: sub_3F009A40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F009A40(const char *a1, const char *a2, int a3, int a4)
{
  int result; // eax
  int v5; // esi
  FILE *v6; // eax
  int v7; // ebx
  int v8; // eax
  int (__thiscall **v9)(int); // edx
  int (__thiscall *v10)(int); // eax
  int v11; // edi
  const char *v12; // [esp-8h] [ebp-430h]
  char v13[1024]; // [esp+10h] [ebp-418h] BYREF
  int v14; // [esp+410h] [ebp-18h]
  int v15; // [esp+414h] [ebp-14h]
  int v16; // [esp+418h] [ebp-10h]
  int v17; // [esp+424h] [ebp-4h]

  result = ((int (*)(void))loc_3F009660)();
  v5 = dword_3F03F284;
  if ( dword_3F03F284 != 0 )
  {
    ((void (*)(char *, int, const char *, ...))_LN10_6)(a1: v13, a2: 1024, a3: "Assert( %s ):%s:%d\n", a1, a2, a3);
    v6 = (FILE *)sub_3F01C6C7(a1: "%s\n", v13);
    fprintf_0(Stream: v6 + 2, Format: v12);
    if ( byte_3F03F494 == 0 )
      ((void (*)(void))loc_3F009910)();
    v7 = ((int (*)(void))loc_3F009880)();
    v8 = ((int (*)(void))loc_3F009790)();
    v9 = *(int (__thiscall ***)(int))v5;
    v14 = v8;
    v10 = *v9;
    v15 = 0;
    v16 = v5;
    v11 = v10(a1: v5);
    v15 = v11;
    (*(void (__thiscall **)(int, int, int, int, char *, int, _DWORD, _DWORD))(*(_DWORD *)v5 + 4))(
      a1: v5,
      a2: v11,
      a3: v14,
      a4: v7,
      a5: &byte_3F03F494,
      a6: a4,
      a7: 0,
      a8: 0);
    v17 = 0;
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v5 + 20))(a1: v5, a2: dword_3F03D3D0, a3: dword_3F03D3D4);
    (*(void (__thiscall **)(int, char *))(*(_DWORD *)v5 + 16))(a1: v5, a2: v13);
    (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: v11, a3: 0, a4: 0);
    result = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 16))(a1: v5, a2: 0);
    v17 = -1;
    if ( v11 != 0 )
    {
      result = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 8))(a1: v5, a2: v11);
      v16 = 0;
      v15 = 0;
    }
  }
  byte_3F03D3C5 = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F009F00
// Name: ?ValidateGlobals@CTier0@@SAXAAVCValidator@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CTier0::ValidateGlobals(
        char a1@<zf>,
        int a2@<eax>,
        int a3@<edx>,
        CWorkerThread *a4@<ecx>,
        int a5@<ebp>)
{
  *(_BYTE *)(a5 + 1435307085) = __ROR1__(*(_BYTE *)(a5 + 1435307085), 16);
  *(_DWORD *)(a5 - 24) = 1;
  *(_DWORD *)(a5 - 20) = a2;
  *(_DWORD *)(a5 - 16) = a4;
  *(_DWORD *)(a5 - 12) = a3;
  *(_DWORD *)(a5 - 8) = 0;
  if ( a1 )
    ((void (__cdecl *)(const char *))Error)(a1: "CatchAndWriteContext_t::Set w/o a function pointer!");
  CWorkerThread::Reply(this: a4, dw: a5 - 24);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F5C0
// Name: ?FindNode@CVProfile@@QAEPAVCVProfNode@@PAV2@PBD@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CVProfNode *__userpurge CVProfile::FindNode@<eax>(
        CVProfile *this@<ecx>,
        _DWORD *a2@<eax>,
        _DWORD *a3@<ebx>,
        int a4@<ebp>,
        HANDLE *a5@<edi>,
        CVProfNode *pStartNode,
        const char *pszNode)
{
  _EAX = (unsigned int)a2 + *a2;
  *((_BYTE *)&unk_3F03AFFF + _EAX - 1057206319) += BYTE1(this);
  *a3 &= _EAX;
  __asm { aas }
  ((void (__cdecl *)(int, _DWORD, _DWORD))AssertMsgImplementation)(a1: _EAX, a2: 0, a3: (unsigned __int16)__SS__);
  return (CVProfNode *)(WaitForSingleObject(hHandle: *a5, dwMilliseconds: *(_DWORD *)(a4 + 8)) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F640
// Name: ?SumTimes@CVProfile@@IAEXPBDH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfile::SumTimes(
        CVProfile *this@<ecx>,
        int a2@<eax>,
        char _BH@<bh>,
        int a4@<ebp>,
        int _EDI@<edi>,
        const char *pszStartNode,
        int budgetGroupID)
{
  char *v13; // eax
  char *v14; // eax

  __asm { lock add bh, [edi] }
  v13 = sub_3F008FA0(a1: (char *)(a4 - 276), Format: (char *)&__initialmbcinfo.mbcasemap[191], a2);
  v14 = sub_3F008FA0(a1: (char *)(a4 - 532), Format: "Assertion Failed: %s", v13);
  ((void (__cdecl *)(char *, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
    a1: v14,
    a2: 0,
    a3: &__initialmbcinfo.mbcasemap[107],
    a4: 879,
    a5: &unk_3F041A6E,
    a6: 0);
  *(_DWORD *)(a4 - 4) = -1;
  JUMPOUT(0x3F00F68D);
}

//------------------------------------------------------------------------------
// Address: 0x3F00F690
// Name: ?DumpNodes@CVProfile@@IAEXPAVCVProfNode@@H_N@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CVProfile::DumpNodes(CVProfile *this@<ecx>, CVProfNode *pNode, int indent, bool bAverageAndCountOnly)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F00FCE0
// Name: ?OutputReport@CVProfile@@QAEXHPBDH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CVProfile::OutputReport(CVProfile *this@<ecx>, int a2@<eax>, _DWORD *a3@<edi>)
{
  ((void (__cdecl *)(int, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
    a1: a2,
    a2: 0,
    a3: &__initialmbcinfo.mbcasemap[107],
    a4: 1735,
    a5: &unk_3F041A77,
    a6: 0);
  if ( *a3 == -1 )
    ((void (__cdecl *)(const char *))Error)(a1: "Out of thread local storage!\n");
}

//------------------------------------------------------------------------------
// Address: 0x3F010140
// Name: ??0CVProfile@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CVProfile *__userpurge CVProfile::CVProfile@<eax>(CVProfile *this@<ecx>, int a2@<esi>, int a3, int a4)
{
  CVProfile *result; // eax

  while ( 1 )
  {
    result = *(CVProfile **)a2;
    if ( this == *(CVProfile **)a2 )
      break;
    result = (CVProfile *)_InterlockedCompareExchange((volatile signed __int32 *)a2, (signed __int32)this, 0);
    if ( result == nullptr )
      break;
    _mm_pause();
  }
  ++*(_DWORD *)(a2 + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F010430
// Name: ??1CVProfile@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CVProfile::~CVProfile(
        CVProfile *this@<ecx>,
        char a2@<zf>,
        char _AL@<al>,
        int _EBX@<ebx>,
        int a5@<ebp>,
        unsigned int a6@<edi>,
        _DWORD *a7@<esi>,
        volatile signed __int64 *a8)
{
  _DWORD *retaddr; // [esp+0h] [ebp+0h]

  __asm { xlat }
  if ( !a2 )
    goto LABEL_4;
  while ( _InterlockedCompareExchange64(a8, a6, 0) != 0 )
  {
    a6 = *(_DWORD *)(a5 + 8);
    a7 = retaddr;
    do
    {
LABEL_4:
      _mm_pause();
      Sleep(dwMilliseconds: 1u);
    }
    while ( (int)a7[1] > 0 );
    if ( *a7 != 0 )
      JUMPOUT(0x3F01042F);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0104C0
// Name: ?FreeNodes_R@CVProfile@@IAEXPAVCVProfNode@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfile::FreeNodes_R(
        CVProfile *this@<ecx>,
        unsigned int a2@<eax>,
        unsigned int a3@<edx>,
        unsigned int a4@<edi>,
        CVProfNode *pNode,
        int a6,
        int a7,
        volatile signed __int64 *a8)
{
  LOBYTE(a2) = a2 & 0x58;
  if ( (_BYTE)a2 != 0
    || __PAIR64__(a2, a3) != _InterlockedCompareExchange64(a8, __SPAIR64__(a2 + 1, a4), __SPAIR64__(a2, a3)) )
  {
    _mm_pause();
    JUMPOUT(0x3F01050E);
  }
  JUMPOUT(0x3F010640);
}

//------------------------------------------------------------------------------
// Address: 0x3F010510
// Name: ?Term@CVProfile@@QAEXXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CVProfile::Term(CVProfile *this@<ecx>, int a2@<eax>, int a3@<edi>, _BYTE *a4@<esi>)
{
  _BYTE *v4; // edi

  v4 = (_BYTE *)(a2 + a3);
  MEMORY[0xCC01051D](a1: this);
  *v4 = *a4;
  JUMPOUT(0x3F01051D);
}

//------------------------------------------------------------------------------
// Address: 0x3F0105D0
// Name: ?GetBudgetGroupColor@CVProfile@@QAEXHAAH000@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CVProfile::GetBudgetGroupColor(
        CVProfile *this@<ecx>,
        int a2@<esi>,
        int budgetGroupID,
        int *r,
        int *g,
        int *b,
        int *a,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        unsigned int a24,
        int a25,
        unsigned int a26)
{
  unsigned int v26; // eax

  if ( a == (int *)1 )
  {
    if ( *(_DWORD *)(a2 + 8) != 0
      || (v26 = *(_DWORD *)(a2 + 4),
          __PAIR64__(v26, a24) != _InterlockedCompareExchange64(
                                    (volatile signed __int64 *)b,
                                    __SPAIR64__(v26 + 1, a26),
                                    __SPAIR64__(v26, a24))) )
    {
      _mm_pause();
      Sleep(dwMilliseconds: 1u);
      JUMPOUT(0x3F010637);
    }
    JUMPOUT(0x3F010640);
  }
  JUMPOUT(0x3F010584);
}

//------------------------------------------------------------------------------
// Address: 0x3F010640
// Name: ?FindBudgetGroupName@CVProfile@@IAEHPBD@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CVProfile::FindBudgetGroupName(CVProfile *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0106A0
// Name: ?AddBudgetGroupName@CVProfile@@IAEHPBDH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CVProfile::AddBudgetGroupName(
        CVProfile *this@<ecx>,
        unsigned int a2@<eax>,
        unsigned int a3@<edx>,
        unsigned int a4@<esi>,
        const char *pBudgetGroupName,
        int budgetFlags,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        unsigned int a18,
        int a19,
        unsigned int a20)
{
  signed __int64 v20; // kr00_8
  int v21; // ecx
  bool v22; // zf
  int v23; // [esp+4h] [ebp-Ch]
  int v24; // [esp+4h] [ebp-Ch]
  _UNKNOWN *retaddr; // [esp+10h] [ebp+0h] BYREF

  v20 = __PAIR64__(a2, (unsigned int)this);
  if ( v20 != _InterlockedCompareExchange64((volatile signed __int64 *)&retaddr, __SPAIR64__(a3, a4), v20) )
  {
    _mm_pause();
    v21 = a2 - 1;
    v23 = 500;
    do
    {
      if ( __PAIR64__(a2, a18) == _InterlockedCompareExchange64(
                                    (volatile signed __int64 *)&retaddr,
                                    __SPAIR64__(v21, a20),
                                    __SPAIR64__(a2, a18)) )
        goto LABEL_9;
      _mm_pause();
      v22 = v23-- == 1;
      a2 = HIDWORD(v20);
      v21 = HIDWORD(v20) - 1;
    }
    while ( !v22 );
    v24 = 20000;
    while ( __PAIR64__(a2, a18) != _InterlockedCompareExchange64(
                                     (volatile signed __int64 *)&retaddr,
                                     __SPAIR64__(v21, a20),
                                     __SPAIR64__(a2, a18)) )
    {
      _mm_pause();
      Sleep(dwMilliseconds: 0);
      v22 = v24-- == 1;
      a2 = HIDWORD(v20);
      v21 = HIDWORD(v20) - 1;
      if ( v22 )
        JUMPOUT(0x3F0107CC);
    }
  }
LABEL_9:
  JUMPOUT(0x3F010804);
}

//------------------------------------------------------------------------------
// Address: 0x3F0107D0
// Name: ?BudgetGroupNameToBudgetGroupID@CVProfile@@QAEHPBDH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
BOOL __usercall CVProfile::BudgetGroupNameToBudgetGroupID@<eax>(
        CVProfile *this@<ecx>,
        signed __int64 *a2@<edi>,
        signed __int64 *a3@<esi>)
{
  signed __int64 v3; // rax
  BOOL result; // eax
  volatile signed __int64 *retaddr; // [esp+0h] [ebp+0h]

  v3 = *a3;
  result = v3 == _InterlockedCompareExchange64(retaddr, *a2, v3);
  if ( !result )
  {
    _mm_pause();
    Sleep(dwMilliseconds: 1u);
    JUMPOUT(0x3F0107B0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0109A0
// Name: ?ResetCounters@CVProfile@@QAEXW4CounterGroup_t@@@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CVProfile::ResetCounters(
        CVProfile *this@<ecx>,
        int (__cdecl *a2)(void *, int)@<ebx>,
        int a3@<ebp>,
        _DWORD *a4@<edi>,
        CounterGroup_t eCounterGroup)
{
  CThread *v5; // edi
  char *v6; // eax
  void *m_hThread; // eax
  char *v8; // [esp-Ch] [ebp-Ch]

  v5 = (CThread *)((char *)a4 + *a4);
  v6 = sub_3F008FA0(a1: (char *)(a3 - 276), Format: v8);
  ((void (__cdecl *)(char *, _DWORD, unsigned __int8 *, int, void *, _DWORD))AssertMsgImplementation)(
    a1: v6,
    a2: 0,
    a3: &__initialmbcinfo.mbcasemap[107],
    a4: 2567,
    a5: &unk_3F041A7C,
    a6: 0);
  CThread::Stop(this: v5, a2: 0);
  m_hThread = v5->m_hThread;
  if ( m_hThread != nullptr && a2(a1: m_hThread, a2: a3 - 16) != 0 )
    JUMPOUT(0x3F0109E5);
  JUMPOUT(0x3F010A05);
}

//------------------------------------------------------------------------------
// Address: 0x3F0109F0
// Name: ?GetNumCounters@CVProfile@@QBEHXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVProfile::GetNumCounters(CVProfile *this)
{
  JUMPOUT(0x3F0109F5);
}

//------------------------------------------------------------------------------
// Address: 0x3F010A00
// Name: ?GetCounterName@CVProfile@@QBEPBDH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CVProfile::GetCounterName(CVProfile *this@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  std::map<char const *,unsigned int>::map<char const *,unsigned int>((std::map<char const *,unsigned int> *)this);
  *(_DWORD *)(a2 - 4) = -1;
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(a3 + 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F010A40
// Name: ?GetCounterValue@CVProfile@@QBEHH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__usercall CVProfile::GetCounterValue@<eax>(CVProfile *this@<ecx>, int a2@<ebp>, int index, int *a4)
{
  CVProfile *v5; // ecx

  *(_DWORD *)(a2 - 16) = &this->m_nVTuneGroupID;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_nVTuneGroupID);
  *(_DWORD *)(a2 - 4) = 0;
  if ( LOBYTE(this->m_GroupIDStack[10]) != 0 )
    JUMPOUT(0x3F010A84);
  ((void (__cdecl *)(int *, int, unsigned __int8 *, CVProfile *, int))_LN10_6)(
    a1: &this->m_GroupIDStack[10],
    a2: 31,
    a3: _rgcode_page_info[0].rgrange[2],
    a4: this,
    a5: this->m_GroupIDStack[7]);
  return CVProfile::GetCounterNameAndValue(this: v5, index, val: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F010A80
// Name: ?GetCounterNameAndValue@CVProfile@@QBEPBDHAAH@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const char *__usercall CVProfile::GetCounterNameAndValue@<eax>(
        CVProfile *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  _RTL_CRITICAL_SECTION *v5; // [esp-10h] [ebp-14h]

  *(_BYTE *)(a4 + 79) = 0;
  *(_DWORD *)(a2 - 4) = -1;
  LeaveCriticalSection(lpCriticalSection: v5);
  return (const char *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x3F010AD0
// Name: ?GetCounterGroup@CVProfile@@QBE?AW4CounterGroup_t@@H@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CVProfile::GetCounterGroup(
        CVProfile *this@<ecx>,
        int a2@<ebp>,
        _RTL_CRITICAL_SECTION *a3@<edi>,
        int a4@<esi>,
        int index)
{
  _RTL_CRITICAL_SECTION *v5; // [esp-4h] [ebp-8h]

  *(_DWORD *)(a2 - 16) = a3;
  EnterCriticalSection(lpCriticalSection: v5);
  *(_DWORD *)(a2 - 4) = 0;
  ((void (__cdecl *)(int, _DWORD, int))loc_3F01B3F0)(a1: a4 + 48, a2: *(_DWORD *)(a2 + 8), a3: 31);
  *(_BYTE *)(a4 + 79) = 0;
  *(_DWORD *)(a2 - 4) = -1;
  LeaveCriticalSection(lpCriticalSection: a3);
  JUMPOUT(0x3F010B0A);
}

//------------------------------------------------------------------------------
// Address: 0x3F0113F0
// Name: sub_3F0113F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __stdcall sub_3F0113F0(DWORD a1, const HANDLE *a2, BOOL a3, DWORD a4)
{
  return WaitForMultipleObjects(nCount: a1, lpHandles: a2, bWaitAll: a3, dwMilliseconds: a4);
}

} // namespace tier0_s
