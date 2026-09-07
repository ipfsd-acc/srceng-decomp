// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gthreads_win32.cpp
// Functions: 41
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gthreads_win32.h"

//------------------------------------------------------------------------------
// Address: 0x100D0C10
// Name: public: virtual bool GMutex_AreadyLockedAcquireInterface::TryAcquire(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *__thiscall GMutex_AreadyLockedAcquireInterface::TryAcquire(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this,
        const CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *a2)
{
  return (*(CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *(__thiscall **)(int, const CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *))(*(_DWORD *)(this->m_Memory.m_nAllocationCount + 12) + 8))(
           a1: this->m_Memory.m_nAllocationCount + 12,
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x100D0C20
// Name: public: virtual bool GMutex_AreadyLockedAcquireInterface::TryAcquireCommit(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *__thiscall GMutex_AreadyLockedAcquireInterface::TryAcquireCommit(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this,
        const CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *a2)
{
  return (*(CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *(__thiscall **)(int, const CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *))(*(_DWORD *)(this->m_Memory.m_nAllocationCount + 12) + 12))(
           a1: this->m_Memory.m_nAllocationCount + 12,
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x100D0C30
// Name: public: virtual bool GMutex_AreadyLockedAcquireInterface::TryAcquireCancel(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *__thiscall GMutex_AreadyLockedAcquireInterface::TryAcquireCancel(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this,
        const CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *a2)
{
  return (*(CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *(__thiscall **)(int, const CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *))(*(_DWORD *)(this->m_Memory.m_nAllocationCount + 12) + 16))(
           a1: this->m_Memory.m_nAllocationCount + 12,
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x100D0C40
// Name: public: void GMutex::Lock(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall GMutex::Lock(IMatRenderContextInternal *this)
{
  int v1; // esi
  IMaterialInternal *result; // eax

  v1 = *((_DWORD *)this + 4);
  result = (IMaterialInternal *)WaitForSingleObject(hHandle: *(HANDLE *)v1, dwMilliseconds: 0xFFFFFFFF);
  if ( result == nullptr )
    ++*(_DWORD *)(v1 + 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D0C60
// Name: public: virtual bool GMutex::IsSignaled(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GMutex::IsSignaled(IMatRenderContextInternal *this)
{
  return *(_DWORD *)(*((_DWORD *)this + 4) + 8) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D0C70
// Name: public: virtual bool GMutex::TryAcquire(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMutex::TryAcquire(IMatRenderContextInternal *this)
{
  int v1; // esi

  v1 = *((_DWORD *)this + 1);
  if ( WaitForSingleObject(hHandle: *(HANDLE *)v1, dwMilliseconds: 0) == 0 )
    ++*(_DWORD *)(v1 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x100D0CA0
// Name: private: void GWaitConditionImpl::QueueFindAndRemove(struct GWaitConditionImpl::EventPoolEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GWaitConditionImpl::QueueFindAndRemove(
        GWaitConditionImpl *this,
        struct GWaitConditionImpl::EventPoolEntry *pentry)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  v2 = *((_DWORD *)this + 7);
  if ( v2 != 0 )
  {
    while ( (struct GWaitConditionImpl::EventPoolEntry *)v2 != pentry )
    {
      v2 = *(_DWORD *)(v2 + 4);
      if ( v2 == 0 )
        return;
    }
    v3 = *((_DWORD *)pentry + 2);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 4) = *((_DWORD *)pentry + 1);
    else
      *((_DWORD *)this + 7) = *((_DWORD *)pentry + 1);
    v4 = *((_DWORD *)pentry + 1);
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 8) = *((_DWORD *)pentry + 2);
    else
      *((_DWORD *)this + 8) = *((_DWORD *)pentry + 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0D00
// Name: public: void GWaitConditionImpl::NotifyAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GWaitConditionImpl::NotifyAll(studiohdr2_t *this)
{
  int m_nBoneFlexDriverIndex; // eax
  int v3; // ecx
  int v4; // ecx

  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  m_nBoneFlexDriverIndex = this->m_nBoneFlexDriverIndex;
  if ( m_nBoneFlexDriverIndex != 0 )
  {
    if ( *(_DWORD *)(m_nBoneFlexDriverIndex + 4) != 0 )
    {
      v3 = *(_DWORD *)(m_nBoneFlexDriverIndex + 4);
      this->m_nBoneFlexDriverIndex = v3;
      *(_DWORD *)(v3 + 8) = 0;
    }
    else
    {
      this->m_nBoneFlexDriverIndex = 0;
      this->reserved[0] = 0;
    }
    while ( 1 )
    {
      SetEvent(hEvent: *(HANDLE *)m_nBoneFlexDriverIndex);
      m_nBoneFlexDriverIndex = this->m_nBoneFlexDriverIndex;
      if ( m_nBoneFlexDriverIndex == 0 )
        break;
      if ( *(_DWORD *)(m_nBoneFlexDriverIndex + 4) != 0 )
      {
        v4 = *(_DWORD *)(m_nBoneFlexDriverIndex + 4);
        this->m_nBoneFlexDriverIndex = v4;
        *(_DWORD *)(v4 + 8) = 0;
      }
      else
      {
        this->m_nBoneFlexDriverIndex = 0;
        this->reserved[0] = 0;
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x100D0D70
// Name: public: void GWaitCondition::Notify(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GWaitCondition::Notify(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  _RTL_CRITICAL_SECTION *m_pMemory; // esi
  int LockCount; // ecx
  int v3; // eax

  m_pMemory = (_RTL_CRITICAL_SECTION *)this->m_Memory.m_pMemory;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this->m_Memory.m_pMemory);
  LockCount = m_pMemory[1].LockCount;
  if ( LockCount != 0 )
  {
    if ( *(_DWORD *)(LockCount + 4) != 0 )
    {
      v3 = *(_DWORD *)(LockCount + 4);
      m_pMemory[1].LockCount = v3;
      *(_DWORD *)(v3 + 8) = 0;
      SetEvent(hEvent: *(HANDLE *)LockCount);
      LeaveCriticalSection(lpCriticalSection: m_pMemory);
      return;
    }
    m_pMemory[1].LockCount = 0;
    m_pMemory[1].RecursionCount = 0;
    SetEvent(hEvent: *(HANDLE *)LockCount);
  }
  LeaveCriticalSection(lpCriticalSection: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100D0DC0
// Name: public: void GWaitCondition::NotifyAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GWaitCondition::NotifyAll(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  GWaitConditionImpl::NotifyAll(this: (studiohdr2_t *)this->m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100D0DD0
// Name: public: virtual int GThread::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GThread::Run(GThread *this)
{
  int (__cdecl *ThreadFunction)(GThread *, void *); // eax

  ThreadFunction = this->ThreadFunction;
  if ( ThreadFunction != nullptr )
    return ThreadFunction(a1: this, a2: this->UserHandle);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D0DF0
// Name: public: static bool GThread::Sleep(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GThread::Sleep(unsigned int secs)
{
  Sleep(dwMilliseconds: 1000 * secs);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D0E10
// Name: public: static bool GThread::MSleep(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GThread::MSleep(DWORD msecs)
{
  Sleep(dwMilliseconds: msecs);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D0E40
// Name: public: GMutex::GMutex(bool,bool)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100D0EF0
// Name: public: GWaitConditionImpl::~GWaitConditionImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GWaitConditionImpl::~GWaitConditionImpl(studiohdr2_t *this)
{
  int m_nBoneFlexDriverCount; // esi
  void *v2; // edi
  void *v3; // eax
  studiohdr2_t *lpCriticalSection; // [esp+4h] [ebp-4h]

  m_nBoneFlexDriverCount = this->m_nBoneFlexDriverCount;
  lpCriticalSection = this;
  if ( m_nBoneFlexDriverCount != 0 )
  {
    do
    {
      v2 = (void *)m_nBoneFlexDriverCount;
      v3 = *(void **)m_nBoneFlexDriverCount;
      m_nBoneFlexDriverCount = *(_DWORD *)(m_nBoneFlexDriverCount + 4);
      CloseHandle(hObject: v3);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
    }
    while ( m_nBoneFlexDriverCount != 0 );
    this = lpCriticalSection;
  }
  this->m_nBoneFlexDriverCount = 0;
  this->reserved[0] = 0;
  this->m_nBoneFlexDriverIndex = 0;
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x100D0F50
// Name: private: struct GWaitConditionImpl::EventPoolEntry __near * GWaitConditionImpl::GetNewEvent(void)
// Source: json
//------------------------------------------------------------------------------
HANDLE *__usercall GWaitConditionImpl::GetNewEvent@<eax>(GWaitConditionImpl *this@<ecx>, int a2@<esi>)
{
  HANDLE *result; // eax
  HANDLE *v3; // esi
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = (int)this;
  result = *((HANDLE **)this + 6);
  if ( result != nullptr )
  {
    *((_DWORD *)this + 6) = result[1];
  }
  else
  {
    v4 = 2;
    v3 = (HANDLE *)((int (__thiscall *)(GMemoryHeap *, int, int *, int))GMemory::pGlobalHeap->Alloc_2)(
                     a1: GMemory::pGlobalHeap,
                     a2: 12,
                     a3: &v4,
                     a4: a2);
    v3[1] = nullptr;
    v3[2] = nullptr;
    *v3 = CreateEventA(lpEventAttributes: nullptr, bManualReset: true, bInitialState: false, lpName: nullptr);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D0FB0
// Name: public: bool GWaitConditionImpl::Wait(class GMutex __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GWaitConditionImpl::Wait(
        studiohdr2_t *this@<ecx>,
        const MaterialNonInteractiveMode_t *a2@<esi>,
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *a3,
        DWORD delay)
{
  HANDLE *NewEvent; // esi
  int v6; // eax
  CMatRenderContextBase *m_pObject; // eax
  bool v8; // zf
  DWORD v9; // ebx
  unsigned int j; // edi
  CMatRenderContextBase *v11; // esi
  unsigned int lockCount; // [esp+8h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-8h]

  lockCount = a3->m_pObject->m_iRefs;
  if ( lockCount != 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
    NewEvent = GWaitConditionImpl::GetNewEvent((GWaitConditionImpl *)this, (int)a2);
    v6 = this->reserved[0];
    if ( v6 != 0 )
    {
      NewEvent[2] = (HANDLE)v6;
      *(_DWORD *)(this->reserved[0] + 4) = NewEvent;
      NewEvent[1] = nullptr;
    }
    else
    {
      NewEvent[2] = nullptr;
      NewEvent[1] = nullptr;
      this->m_nBoneFlexDriverIndex = (int)NewEvent;
    }
    this->reserved[0] = (int)NewEvent;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
    m_pObject = a3->m_pObject;
    v8 = LOBYTE(m_pObject->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable) == 0;
    m_pObject->m_iRefs = 0;
    if ( v8 )
    {
      ReleaseSemaphore(hSemaphore: a3->m_pObject->__vftable, lReleaseCount: 1, lpPreviousCount: nullptr);
    }
    else
    {
      for ( i = lockCount; i != 0; --i )
        ReleaseMutex(hMutex: a3->m_pObject->__vftable);
    }
    GWaitable::CallWaitHandlers(this: a3, a2);
    v9 = WaitForSingleObject(hHandle: *NewEvent, dwMilliseconds: delay);
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
    if ( v9 == 0 || v9 == 128 )
    {
      ResetEvent(hEvent: *NewEvent);
      NewEvent[1] = (HANDLE)this->m_nBoneFlexDriverCount;
    }
    else
    {
      GWaitConditionImpl::QueueFindAndRemove(
        (GWaitConditionImpl *)this,
        pentry: (struct GWaitConditionImpl::EventPoolEntry *)NewEvent);
      ResetEvent(hEvent: *NewEvent);
      NewEvent[1] = (HANDLE)this->m_nBoneFlexDriverCount;
    }
    NewEvent[2] = nullptr;
    this->m_nBoneFlexDriverCount = (int)NewEvent;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
    for ( j = lockCount; j != 0; --j )
    {
      v11 = a3->m_pObject;
      if ( WaitForSingleObject(
             hHandle: v11->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable,
             dwMilliseconds: 0xFFFFFFFF) == 0 )
        ++v11->m_iRefs;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1100
// Name: public: GWaitCondition::GWaitCondition(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<int,CUtlMemory<int,int> > *__thiscall GWaitCondition::GWaitCondition(
        CUtlVector<int,CUtlMemory<int,int> > *this)
{
  _RTL_CRITICAL_SECTION *v2; // eax
  int *v3; // esi
  int v5; // [esp+8h] [ebp-4h] BYREF

  v5 = 2;
  v2 = (_RTL_CRITICAL_SECTION *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 36, a3: &v5);
  v3 = (int *)v2;
  if ( v2 != nullptr )
  {
    GLock::GLock(lpCriticalSection: v2, spinCount: 0);
    v3[6] = 0;
    v3[8] = 0;
    v3[7] = 0;
    this->m_Memory.m_pMemory = v3;
  }
  else
  {
    this->m_Memory.m_pMemory = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D1160
// Name: public: bool GWaitCondition::Wait(class GMutex __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GWaitCondition::Wait(
        GWaitCondition *this@<ecx>,
        const MaterialNonInteractiveMode_t *a2@<esi>,
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *a3,
        DWORD a4)
{
  GWaitConditionImpl::Wait(this: (studiohdr2_t *)this->pImpl, a2, a3, delay: a4);
}

//------------------------------------------------------------------------------
// Address: 0x100D1170
// Name: public: virtual class GAcquireInterface __near * GThread::GetAcquireInterface(void)
// Source: json
//------------------------------------------------------------------------------
const __m64 *__thiscall GThread::GetAcquireInterface(ShortVector *this)
{
  if ( this != nullptr )
    return (const __m64 *)((char *)this + 12);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D1190
// Name: public: bool GThread::IsFinished(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GThread::IsFinished(GThread *this)
{
  return (this->ThreadFlags.Value & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D13B0
// Name: public: virtual GMutex::~GMutex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMutex::~GMutex(IMatRenderContextInternal *this, const MaterialNonInteractiveMode_t *a2)
{
  int v3; // esi

  v3 = *((_DWORD *)this + 4);
  this->__vftable = (IMatRenderContextInternal_vtbl *)&GMutex::`vftable'{for `GWaitable'};
  *((_DWORD *)this + 3) = &GMutex::`vftable'{for `GAcquireInterface'};
  if ( v3 != 0 )
  {
    CloseHandle(hObject: *(HANDLE *)v3);
    *(_DWORD *)(v3 + 12) = &GAcquireInterface::`vftable';
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  }
  *((_DWORD *)this + 3) = &GAcquireInterface::`vftable';
  GWaitable::~GWaitable(
    (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *)this,
    a2);
}

//------------------------------------------------------------------------------
// Address: 0x100D1400
// Name: public: GWaitCondition::~GWaitCondition(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GWaitCondition::~GWaitCondition(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int *m_pMemory; // esi
  bool result; // al

  m_pMemory = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    GWaitConditionImpl::~GWaitConditionImpl(this: (studiohdr2_t *)this->m_Memory.m_pMemory);
    return ((bool (__thiscall *)(GMemoryHeap *, int *))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: m_pMemory);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D15D0
// Name: public: GThreadList::GThreadList(void)
// Source: json
//------------------------------------------------------------------------------
CFastTimer *__thiscall GThreadList::GThreadList(CFastTimer *this)
{
  _RTL_CRITICAL_SECTION *v2; // eax
  _RTL_CRITICAL_SECTION *v3; // esi
  int v5; // [esp+8h] [ebp-4h] BYREF

  LODWORD(this->m_Duration.m_Int64) = 0;
  GMutex::GMutex(this: (IMatRenderContextInternal *)&this->m_Duration.m_Int64 + 1, recursive: 1);
  v5 = 2;
  v2 = (_RTL_CRITICAL_SECTION *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 36, a3: &v5);
  v3 = v2;
  if ( v2 != nullptr )
  {
    GLock::GLock(lpCriticalSection: v2, spinCount: 0);
    v3[1].DebugInfo = nullptr;
    v3[1].RecursionCount = 0;
    v3[1].LockCount = 0;
    *((_DWORD *)this + 6) = v3;
  }
  else
  {
    *((_DWORD *)this + 6) = 0;
  }
  *((_DWORD *)this + 7) = GetCurrentThreadId();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D1660
// Name: public: GThreadList::~GThreadList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GThreadList::~GThreadList(CInternalFileSystemPassThru<IBaseFileSystem> *this)
{
  void *v2; // esi
  int v3; // edi
  const MaterialNonInteractiveMode_t *v4; // [esp+0h] [ebp-Ch]

  v2 = *((void **)this + 6);
  if ( v2 != nullptr )
  {
    GWaitConditionImpl::~GWaitConditionImpl(this: *((studiohdr2_t **)this + 6));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
  }
  v3 = *((_DWORD *)this + 5);
  this->m_pBaseFileSystemPassThru = (IBaseFileSystem *)&GMutex::`vftable'{for `GWaitable'};
  *((_DWORD *)this + 4) = &GMutex::`vftable'{for `GAcquireInterface'};
  if ( v3 != 0 )
  {
    CloseHandle(hObject: *(HANDLE *)v3);
    *(_DWORD *)(v3 + 12) = &GAcquireInterface::`vftable';
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  }
  *((_DWORD *)this + 4) = &GAcquireInterface::`vftable';
  GWaitable::~GWaitable(
    this: (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *)&this->m_pBaseFileSystemPassThru,
    a2: v4);
  GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D16D0
// Name: public: void GWaitable::GetCallableHandlers(class GWaitable::CallableHandlers __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GWaitable::GetCallableHandlers(
        GWaitable *this@<ecx>,
        CMatLightmaps *a2@<edi>,
        struct GWaitable::CallableHandlers *a3)
{
  GWaitable::HandlerArray *pHandlers; // esi

  pHandlers = this->pHandlers;
  if ( pHandlers != nullptr )
  {
    InterlockedExchangeAdd(Addend: &pHandlers->RefCount.Value, Value: 1);
    if ( a3->pArray.pObject != nullptr )
      GWaitable::HandlerArray::Release(result: a2);
    a3->pArray.pObject = pHandlers;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1700
// Name: public: void GMutexImpl::Unlock(class GMutex __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMutexImpl::Unlock(GMutexImpl *this, struct GMutex *a2)
{
  GWaitable::HandlerArray *pHandlers; // edi
  GWaitable::HandlerArray *v4; // ebx
  BOOL v5; // eax
  CMatLightmaps *v6; // [esp+0h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-4h]

  --*((_DWORD *)this + 2);
  pHandlers = a2->pHandlers;
  v4 = nullptr;
  v7 = *((_DWORD *)this + 2);
  if ( pHandlers != nullptr )
  {
    InterlockedExchangeAdd(Addend: &pHandlers->RefCount.Value, Value: 1);
    v4 = pHandlers;
  }
  if ( *((_BYTE *)this + 4) != 0 )
    v5 = ReleaseMutex(hMutex: *(HANDLE *)this);
  else
    v5 = ReleaseSemaphore(hSemaphore: *(HANDLE *)this, lReleaseCount: 1, lpPreviousCount: nullptr);
  if ( v5 && v7 == 0 )
  {
    if ( v4 == nullptr )
      return;
    GWaitable::HandlerArray::CallWaitHandlers(result: v6);
  }
  if ( v4 != nullptr )
    GWaitable::HandlerArray::Release(result: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100D1770
// Name: public: void GMutex::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMutex::Unlock(IMatRenderContextInternal *this)
{
  GMutexImpl::Unlock(this: *((GMutexImpl **)this + 4), a2: (struct GMutex *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100D1780
// Name: public: virtual class GAcquireInterface __near * GMutex::GetAcquireInterface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMutex::GetAcquireInterface(IMatRenderContextInternal *this)
{
  int v2; // esi

  v2 = *((_DWORD *)this + 4);
  if ( *(_DWORD *)(v2 + 8) != 0 && WaitForSingleObject(hHandle: *(HANDLE *)v2, dwMilliseconds: 0) == 0 )
  {
    ++*(_DWORD *)(v2 + 8);
    GMutexImpl::Unlock(this: (GMutexImpl *)v2, a2: (struct GMutex *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D17C0
// Name: public: virtual bool GMutex::CanAcquire(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMutex::CanAcquire(IMatRenderContextInternal *this)
{
  int v1; // esi
  struct GMutex *v2; // edi

  v1 = *((_DWORD *)this + 1);
  v2 = (struct GMutex *)(this - 3);
  if ( *(_DWORD *)(v1 + 8) != 0 && WaitForSingleObject(hHandle: *(HANDLE *)v1, dwMilliseconds: 0) == 0 )
  {
    ++*(_DWORD *)(v1 + 8);
    GMutexImpl::Unlock(this: (GMutexImpl *)v1, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1810
// Name: public: virtual bool GMutex::TryAcquireCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMutex::TryAcquireCancel(IMatRenderContextInternal *this)
{
  GMutexImpl::Unlock(this: *((GMutexImpl **)this + 1), a2: (struct GMutex *)(this - 3));
}

//------------------------------------------------------------------------------
// Address: 0x100D1820
// Name: protected: void GThread::FinishAndRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GThread::FinishAndRelease(GThread *this)
{
  GWaitable::HandlerArray *pHandlers; // edi
  GAtomicInt<unsigned long> *p_ThreadFlags; // esi
  volatile LONG Value; // edi
  volatile LONG v5; // edi
  CMatLightmaps *v6; // [esp+0h] [ebp-10h]
  CMatLightmaps *v7; // [esp+0h] [ebp-10h]
  GWaitable::HandlerArray *v9; // [esp+Ch] [ebp-4h]

  pHandlers = this->pHandlers;
  v9 = nullptr;
  if ( pHandlers != nullptr )
  {
    InterlockedExchangeAdd(Addend: &pHandlers->RefCount.Value, Value: 1);
    v9 = pHandlers;
  }
  p_ThreadFlags = &this->ThreadFlags;
  do
    Value = p_ThreadFlags->Value;
  while ( InterlockedCompareExchange(
            Destination: (volatile LONG *)p_ThreadFlags,
            Exchange: p_ThreadFlags->Value & 0xFFFFFFFE,
            Comperand: p_ThreadFlags->Value) != Value );
  do
    v5 = p_ThreadFlags->Value;
  while ( InterlockedCompareExchange(
            Destination: (volatile LONG *)p_ThreadFlags,
            Exchange: p_ThreadFlags->Value | 2,
            Comperand: p_ThreadFlags->Value) != v5 );
  GRefCountImpl::Release((IShaderAPI *)this);
  if ( v9 != nullptr )
  {
    GWaitable::HandlerArray::CallWaitHandlers(result: v6);
    GWaitable::HandlerArray::Release(result: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D18A0
// Name: protected: int GThread::PRun(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GThread::PRun(GThread *this)
{
  GThread *v1; // esi
  GAtomicInt<unsigned long> *p_ThreadFlags; // edi
  volatile unsigned int Value; // esi
  int result; // eax

  v1 = this;
  p_ThreadFlags = &this->ThreadFlags;
  if ( (this->ThreadFlags.Value & 8) != 0 )
  {
    if ( (p_ThreadFlags->Value & 1) != 0 && SuspendThread(hThread: this->ThreadHandle) != -1 )
      InterlockedExchangeAdd(Addend: &v1->SuspendCount.Value, Value: 1);
    do
      Value = p_ThreadFlags->Value;
    while ( InterlockedCompareExchange(
              Destination: (volatile LONG *)p_ThreadFlags,
              Exchange: p_ThreadFlags->Value & 0xFFFFFFF7,
              Comperand: p_ThreadFlags->Value) != Value );
    v1 = this;
  }
  result = v1->Run(this: v1);
  v1->ExitCode = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D1910
// Name: public: GThread::GThread(int (*)(class GThread __near *,void __near *),void __near *,unsigned int,int,enum GThread::ThreadState)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100D1990
// Name: private: void GThreadList::finishAllThreads(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GThreadList::finishAllThreads(CUtlMemory<virtualgroup_t,int> *this)
{
  int v2; // ebx
  int *p_m_nAllocationCount; // edi

  v2 = *((_DWORD *)this + 5);
  p_m_nAllocationCount = &this->m_nAllocationCount;
  if ( WaitForSingleObject(hHandle: *(HANDLE *)v2, dwMilliseconds: 0xFFFFFFFF) == 0 )
    ++*(_DWORD *)(v2 + 8);
  while ( GHashSetBase<GThread *,GThreadList::ThreadHashOp,GThreadList::ThreadHashOp,GAllocatorGH<GThread *,2>,GHashsetCachedEntry<GThread *,GThreadList::ThreadHashOp>>::GetSize(this) != nullptr )
    GWaitConditionImpl::Wait(
      this: *((studiohdr2_t **)this + 6),
      a2: (const MaterialNonInteractiveMode_t *)this,
      a3: (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CFuncMemPolicyNone> *)p_m_nAllocationCount,
      delay: 0xFFFFFFFF);
  GMutexImpl::Unlock(this: (GMutexImpl *)p_m_nAllocationCount[4], a2: (struct GMutex *)p_m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x100D19E0
// Name: public: static void GThreadList::AddRunningThread(class GThread __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GThreadList::AddRunningThread(unsigned int a1)
{
  CFastTimer *v1; // eax
  CFastTimer *v2; // eax
  mstudiolinearbone_t *v3; // esi
  int m_Int64_high; // ebx
  struct GMutex *v5; // edi
  void *v6; // [esp-14h] [ebp-1Ch]
  unsigned int v7; // [esp+0h] [ebp-8h] BYREF
  int v8; // [esp+4h] [ebp-4h] BYREF

  if ( GThreadList::pRunningThreads == nullptr )
  {
    v8 = 2;
    v1 = (CFastTimer *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 32, a3: &v8);
    if ( v1 != nullptr )
      v2 = GThreadList::GThreadList(this: v1);
    else
      v2 = nullptr;
    GThreadList::pRunningThreads = v2;
  }
  v3 = (mstudiolinearbone_t *)GThreadList::pRunningThreads;
  m_Int64_high = HIDWORD(GThreadList::pRunningThreads[2].m_Duration.m_Int64);
  v5 = (struct GMutex *)((char *)&GThreadList::pRunningThreads->m_Duration.m_Int64 + 4);
  v6 = *(void **)m_Int64_high;
  v7 = a1;
  if ( WaitForSingleObject(hHandle: v6, dwMilliseconds: 0xFFFFFFFF) == 0 )
    ++*(_DWORD *)(m_Int64_high + 8);
  GHashSetBase<GThread *,GThreadList::ThreadHashOp,GThreadList::ThreadHashOp,GAllocatorGH<GThread *,2>,GHashsetCachedEntry<GThread *,GThreadList::ThreadHashOp>>::add<GThread *>(
    this: v3,
    pmemAddr: v3,
    key: (const mstudiobone_t *)&v7,
    hashValue: a1 ^ (a1 >> 6));
  GMutexImpl::Unlock(this: v5->pImpl, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100D1A70
// Name: public: static void GThreadList::RemoveRunningThread(class GThread __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GThreadList::RemoveRunningThread(struct GThread *a1)
{
  CFastTimer *v1; // esi
  int m_Int64_high; // edi
  struct GMutex *v3; // ebx

  v1 = GThreadList::pRunningThreads;
  m_Int64_high = HIDWORD(GThreadList::pRunningThreads[2].m_Duration.m_Int64);
  v3 = (struct GMutex *)((char *)&GThreadList::pRunningThreads->m_Duration.m_Int64 + 4);
  if ( WaitForSingleObject(hHandle: *(HANDLE *)m_Int64_high, dwMilliseconds: 0xFFFFFFFF) == 0 )
    ++*(_DWORD *)(m_Int64_high + 8);
  GHashSetBase<GThread *,GThreadList::ThreadHashOp,GThreadList::ThreadHashOp,GAllocatorGH<GThread *,2>,GHashsetCachedEntry<GThread *,GThreadList::ThreadHashOp>>::RemoveAlt<GThread *>(
    this: v1,
    a2: &a1);
  if ( LODWORD(v1->m_Duration.m_Int64) == 0 || *(_DWORD *)LODWORD(v1->m_Duration.m_Int64) == 0 )
    GWaitCondition::Notify(this: (CUtlVector<int,CUtlMemory<int,int> > *)&v1[3]);
  GMutexImpl::Unlock(this: v3->pImpl, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100D1AD0
// Name: public: static void GThread::FinishAllThreads(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GThread::FinishAllThreads(
        int (__cdecl *this)(const CMaterialSystem::COnLevelShutdownFunc *, const CMaterialSystem::COnLevelShutdownFunc *))
{
  CFastTimer *v1; // [esp+0h] [ebp-4h]

  if ( GThreadList::pRunningThreads != nullptr )
  {
    GThreadList::finishAllThreads(this: (CUtlMemory<virtualgroup_t,int> *)GThreadList::pRunningThreads);
    v1 = GThreadList::pRunningThreads;
    if ( GThreadList::pRunningThreads != nullptr )
    {
      GThreadList::~GThreadList(this: (CInternalFileSystemPassThru<IBaseFileSystem> *)GThreadList::pRunningThreads);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v1);
    }
    GThreadList::pRunningThreads = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1B30
// Name: unsigned int GThread_Win32StartFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GThread_Win32StartFn(GThread *a1)
{
  GThread *v1; // esi
  HANDLE CurrentThread; // eax
  int v3; // eax
  HANDLE v4; // eax
  CFastTimer *v5; // esi
  int m_Int64_high; // edi
  struct GMutex *v7; // ebx
  DWORD_PTR Processor; // [esp-4h] [ebp-14h]
  int v10; // [esp-4h] [ebp-14h]
  int v11; // [esp+Ch] [ebp-4h]

  v1 = a1;
  if ( a1->Processor != -1 )
  {
    Processor = a1->Processor;
    CurrentThread = GetCurrentThread();
    SetThreadAffinityMask(hThread: CurrentThread, dwThreadAffinityMask: Processor);
  }
  switch ( v1->Priority )
  {
    case CriticalPriority:
      v3 = 15;
      break;
    case HighestPriority:
      v3 = 2;
      break;
    case AboveNormalPriority:
      v3 = 1;
      break;
    case BelowNormalPriority:
      v3 = -1;
      break;
    case LowestPriority:
      v3 = -2;
      break;
    case IdlePriority:
      v3 = -15;
      break;
    default:
      v3 = 0;
      break;
  }
  v10 = v3;
  v4 = GetCurrentThread();
  SetThreadPriority(hThread: v4, nPriority: v10);
  v11 = GThread::PRun(this: v1);
  GThread::FinishAndRelease(this: v1);
  a1 = v1;
  v5 = GThreadList::pRunningThreads;
  m_Int64_high = HIDWORD(GThreadList::pRunningThreads[2].m_Duration.m_Int64);
  v7 = (struct GMutex *)((char *)&GThreadList::pRunningThreads->m_Duration.m_Int64 + 4);
  if ( WaitForSingleObject(hHandle: *(HANDLE *)m_Int64_high, dwMilliseconds: 0xFFFFFFFF) == 0 )
    ++*(_DWORD *)(m_Int64_high + 8);
  GHashSetBase<GThread *,GThreadList::ThreadHashOp,GThreadList::ThreadHashOp,GAllocatorGH<GThread *,2>,GHashsetCachedEntry<GThread *,GThreadList::ThreadHashOp>>::RemoveAlt<GThread *>(
    this: v5,
    a2: &a1);
  if ( LODWORD(v5->m_Duration.m_Int64) == 0 || *(_DWORD *)LODWORD(v5->m_Duration.m_Int64) == 0 )
    GWaitCondition::Notify(this: (CUtlVector<int,CUtlMemory<int,int> > *)&v5[3]);
  GMutexImpl::Unlock(this: v7->pImpl, a2: v7);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x100D1C20
// Name: public: virtual bool GThread::Start(enum GThread::ThreadState)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GThread::Start(
        CUtlVector<CMaterialSystem::COnLevelShutdownFunc,CUtlMemory<CMaterialSystem::COnLevelShutdownFunc,int> > *this,
        unsigned int initialState)
{
  unsigned int v4; // eax

  if ( initialState == 0 )
    return 0;
  if ( (*((int *)this + 7) > 0 || (*((_DWORD *)this + 6) & 1) != 0)
    && !GWaitable::Wait((GWaitable *)this, result: 0xFFFFFFFF) )
  {
    return 0;
  }
  if ( *((_DWORD *)this + 11) != 0 )
  {
    CloseHandle(hObject: *((HANDLE *)this + 11));
    *((_DWORD *)this + 11) = 0;
  }
  GRefCountImpl::AddRef((IShaderDevice *)this);
  GThreadList::AddRunningThread(a1: (unsigned int)this);
  *((_DWORD *)this + 12) = 0;
  InterlockedExchange(Target: (volatile LONG *)this + 7, Value: 0);
  InterlockedExchange(Target: (volatile LONG *)this + 6, Value: initialState != 1 ? 8 : 0);
  v4 = _beginthreadex(
         security: nullptr,
         stacksize: *((_DWORD *)this + 8),
         initialcode: (unsigned int (__stdcall *)(void *))GThread_Win32StartFn,
         argument: this,
         createflag: 0,
         thrdaddr: nullptr);
  *((_DWORD *)this + 11) = v4;
  if ( v4 == 0 )
  {
    InterlockedExchange(Target: (volatile LONG *)this + 6, Value: 0);
    GRefCountImpl::Release((IShaderAPI *)this);
    GThreadList::RemoveRunningThread(a1: (struct GThread *)this);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D1CF0
// Name: public: virtual void GThread::Exit(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall __noreturn GThread::Exit(GThread *this, unsigned int retcode)
{
  CFastTimer *v3; // esi
  int m_Int64_high; // edi
  struct GMutex *v5; // ebx
  GThread *v6; // [esp+Ch] [ebp-4h] BYREF

  this->OnExit(this);
  GThread::FinishAndRelease(this);
  v6 = this;
  v3 = GThreadList::pRunningThreads;
  m_Int64_high = HIDWORD(GThreadList::pRunningThreads[2].m_Duration.m_Int64);
  v5 = (struct GMutex *)((char *)&GThreadList::pRunningThreads->m_Duration.m_Int64 + 4);
  if ( WaitForSingleObject(hHandle: *(HANDLE *)m_Int64_high, dwMilliseconds: 0xFFFFFFFF) == 0 )
    ++*(_DWORD *)(m_Int64_high + 8);
  GHashSetBase<GThread *,GThreadList::ThreadHashOp,GThreadList::ThreadHashOp,GAllocatorGH<GThread *,2>,GHashsetCachedEntry<GThread *,GThreadList::ThreadHashOp>>::RemoveAlt<GThread *>(
    this: v3,
    a2: &v6);
  if ( LODWORD(v3->m_Duration.m_Int64) == 0 || *(_DWORD *)LODWORD(v3->m_Duration.m_Int64) == 0 )
    GWaitCondition::Notify(this: (CUtlVector<int,CUtlMemory<int,int> > *)&v3[3]);
  GMutexImpl::Unlock(this: v5->pImpl, a2: v5);
  _endthreadex(retcode);
}
