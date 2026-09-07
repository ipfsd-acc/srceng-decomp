// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/memstd.cpp
// Functions: 84
// ============================================================

#include "tier0\memstd.h"

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: public: virtual void CStdMemAlloc::CrtMemCheckpoint(struct _CrtMemState __near *)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?SetTrace@CThreadFullMutex@@QAEX_N@Z'
void __thiscall CStdMemAlloc::CrtMemCheckpoint(CThreadMutex *this, bool bTrace)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10006840
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  __int64 v5; // [esp-10h] [ebp-1Ch]
  __int64 v6; // [esp-10h] [ebp-1Ch]
  __int64 value64; // [esp-8h] [ebp-14h]
  __int64 v8; // [esp-8h] [ebp-14h]

  Next = this->m_Head.value.Next;
  value64 = this->m_Head.value64;
  HIDWORD(v5) = this->m_Head.value32.DepthAndSequence + 65537;
  LODWORD(v5) = pNode;
  pNode->Next = this->m_Head.value.Next;
  if ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)this, value: v5, comperand: value64) )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v8 = this->m_Head.value64;
      HIDWORD(v6) = this->m_Head.value32.DepthAndSequence + 65537;
      LODWORD(v6) = pNode;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)this, value: v6, comperand: v8) );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100068A0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  __int64 v5; // [esp-10h] [ebp-18h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( 1 )
  {
    HIDWORD(v5) = DepthAndSequence - 1;
    LODWORD(v5) = Next->Next;
    if ( ThreadInterlockedAssignIf64(
           pDest: (volatile __int64 *)this,
           value: v5,
           comperand: __SPAIR64__(DepthAndSequence, (unsigned int)Next)) )
    {
      break;
    }
    _mm_pause();
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100068E0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( ThreadInterlockedAssignIf64(
           pDest: (volatile __int64 *)this,
           value: this->m_Head.value64 & 0xFFFF000000000000uLL,
           comperand: this->m_Head.value64) )
    {
      return Next;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006920
// Name: unsigned int compact_internal(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl compact_internal()
{
  int v0; // edi
  int v1; // ebx
  unsigned int i; // esi
  unsigned int v3; // eax

  v0 = 0;
  v1 = 0;
  for ( i = 0; i < 2; ++i )
  {
    v0 += mspace_footprint(msp: g_AllocRegions[i]);
    mspace_trim(msp: g_AllocRegions[i], pad: 0);
    v3 = mspace_footprint(msp: g_AllocRegions[i]);
    v1 += v3;
  }
  return v0 - v1;
}

//------------------------------------------------------------------------------
// Address: 0x10006970
// Name: void heapstats_internal(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl heapstats_internal(_iobuf *pFile)
{
  unsigned int i; // esi
  mallinfo *v2; // eax
  void *v3; // edx
  unsigned int v4; // edi
  unsigned int v5; // eax
  const char *v6; // ecx
  char buf[1024]; // [esp+Ch] [ebp-450h] BYREF
  mallinfo result; // [esp+40Ch] [ebp-50h] BYREF
  mallinfo info; // [esp+434h] [ebp-28h]

  for ( i = 0; i < 2; ++i )
  {
    v2 = mspace_mallinfo(&result, msp: g_AllocRegions[i]);
    v3 = g_AllocRegions[i];
    info = *v2;
    v4 = mspace_footprint(msp: v3);
    v5 = mspace_max_footprint(msp: g_AllocRegions[i]);
    v6 = "medium-block";
    if ( i == 0 )
      v6 = "large-block";
    _snprintf(
      string: buf,
      count: 0x400u,
      format: "\n"
      "dlmalloc mspace %d (%s)\n"
      "     %d:footprint     -%10d (total space used by the mspace)\n"
      "     %d:footprint_max -%10d (maximum total space used by the mspace)\n"
      "     %d:arena         -%10d (non-mmapped space allocated from system)\n"
      "     %d:ordblks       -%10d (number of free chunks)\n"
      "     %d:hblkhd        -%10d (space in mmapped regions)\n"
      "     %d:usmblks       -%10d (maximum total allocated space)\n"
      "     %d:uordblks      -%10d (total allocated space)\n"
      "     %d:fordblks      -%10d (total free space)\n"
      "     %d:keepcost      -%10d (releasable (via malloc_trim) space)\n",
      i,
      v6,
      i,
      v4,
      i,
      v5,
      i,
      info.arena,
      i,
      info.ordblks,
      i,
      info.hblkhd,
      i,
      info.usmblks,
      i,
      info.uordblks,
      i,
      info.fordblks,
      i,
      info.keepcost);
    if ( pFile != nullptr )
      fprintf(str: pFile, format: "%s", buf);
    else
      Msg(pMsgFormat: "%s", buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006A80
// Name: public: virtual void __near * CStdMemAlloc::Expand_NoLongerSupported(void __near *,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CStdMemAlloc::Expand_NoLongerSupported(
        CStdMemAlloc *this,
        void *pMem,
        void *nSize,
        const char *pFileName,
        const char *nLine)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006A90
// Name: public: virtual void CStdMemAlloc::GetActualDbgInfo(char const __near * __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::GetActualDbgInfo(CStdMemAlloc *this, const char **pFileName, const char **nLine)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10006AA0
// Name: public: virtual int CStdMemAlloc::CrtIsValidPointer(void const __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdMemAlloc::CrtIsValidPointer(
        CStdMemAlloc *this,
        const void *pMem,
        const void *size,
        unsigned int access)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006AD0
// Name: public: virtual int CStdMemAlloc::heapchk(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdMemAlloc::heapchk(CStdMemAlloc *this)
{
  this->CrtCheckMemory(this);
  return -2;
}

//------------------------------------------------------------------------------
// Address: 0x10006AE0
// Name: public: virtual void CStdMemAlloc::DumpStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::DumpStats(CStdMemAlloc *this)
{
  this->DumpStatsFileBase(this, a2: "memstats");
}

//------------------------------------------------------------------------------
// Address: 0x10006AF0
// Name: public: virtual class IVirtualMemorySection __near * CStdMemAlloc::AllocateVirtualMemorySection(unsigned int)
// Source: json
//------------------------------------------------------------------------------
IVirtualMemorySection *__thiscall CStdMemAlloc::AllocateVirtualMemorySection(
        CStdMemAlloc *this,
        unsigned int numMaxBytes)
{
  return (IVirtualMemorySection *)VirtualMemoryManager_AllocateVirtualMemorySection((CpuidImpl *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10006B10
// Name: public: virtual void CStdMemAlloc::GlobalMemoryStatus(unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::GlobalMemoryStatus(
        CStdMemAlloc *this,
        unsigned int *pUsedMemory,
        unsigned int *pFreeMemory)
{
  mallinfo result; // [esp+4h] [ebp-28h] BYREF

  if ( pUsedMemory != nullptr && pFreeMemory != nullptr )
  {
    mspace_mallinfo(&result, msp: g_AllocRegions[0]);
    *pFreeMemory = 0;
    *pUsedMemory = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006B50
// Name: public: virtual unsigned int (*CStdMemAlloc::SetAllocFailHandler(unsigned int (*)(unsigned int)))(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int (__cdecl *__thiscall CStdMemAlloc::SetAllocFailHandler(
        CStdMemAlloc *this,
        unsigned int (__cdecl *pfnMemAllocFailHandler)(unsigned int)))(unsigned int)
{
  unsigned int (__cdecl *result)(unsigned int); // eax

  result = this->m_pfnFailHandler;
  this->m_pfnFailHandler = pfnMemAllocFailHandler;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006B70
// Name: public: virtual void CStdMemAlloc::OutOfMemory(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::OutOfMemory(CStdMemAlloc *this, unsigned int nBytesAttempted)
{
  char buffer[256]; // [esp+4h] [ebp-100h] BYREF

  this->m_sMemoryAllocFailed = nBytesAttempted;
  if ( Plat_IsInDebugSession() )
    __debugbreak();
  _snprintf(
    string: buffer,
    count: 0x100u,
    format: "***** OUT OF MEMORY! attempted allocation size: %u ****\n",
    nBytesAttempted);
  OutputDebugStringA(lpOutputString: buffer);
  if ( !Plat_IsInDebugSession() )
  {
    WriteMiniDump();
    abort();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006BD0
// Name: public: virtual unsigned int CStdMemAlloc::MemoryAllocFailed(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CStdMemAlloc::MemoryAllocFailed(CStdMemAlloc *this)
{
  return this->m_sMemoryAllocFailed;
}

//------------------------------------------------------------------------------
// Address: 0x10006BE0
// Name: public: bool CSmallBlockHeap<class CStdMemAlloc::CVirtualAllocator>::IsOwner(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::IsOwner(
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *this,
        unsigned __int8 *p)
{
  unsigned __int8 *m_pBase; // ecx

  m_pBase = this->m_pSharedData->m_pBase;
  return p >= m_pBase && (unsigned int)((p - m_pBase) / 0x10000) < 0x200;
}

//------------------------------------------------------------------------------
// Address: 0x10006C20
// Name: private: static int CSmallBlockPool<class CStdMemAlloc::CFixedAllocator<48,1>>::PageSort(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::PageSort(_DWORD *p1, _DWORD *p2)
{
  return CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[*p1].m_SortList.m_Head.value.Depth
       - CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[*p2].m_SortList.m_Head.value.Depth;
}

//------------------------------------------------------------------------------
// Address: 0x10006C50
// Name: private: static int CSmallBlockPool<class CStdMemAlloc::CVirtualAllocator>::PageSort(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageSort(_DWORD *p1, _DWORD *p2)
{
  return CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[*p1].m_SortList.m_Head.value.Depth
       - CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[*p2].m_SortList.m_Head.value.Depth;
}

//------------------------------------------------------------------------------
// Address: 0x10006C80
// Name: public: void CSmallBlockHeap<class CStdMemAlloc::CFixedAllocator<48,1>>::Usage(unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Usage(
        CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1> > *this,
        unsigned int *bytesCommitted,
        unsigned int *bytesAllocated)
{
  unsigned int *p_m_nCommittedPages; // ecx
  int i; // esi
  unsigned int v5; // edx
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edi

  *bytesCommitted = 0;
  *bytesAllocated = 0;
  p_m_nCommittedPages = &this->m_Pools[1].m_nCommittedPages;
  for ( i = 7; i != 0; --i )
  {
    *bytesCommitted += *(p_m_nCommittedPages - 8) << 14;
    v5 = (*p_m_nCommittedPages << 14) + *bytesCommitted;
    *bytesCommitted = v5;
    v6 = (p_m_nCommittedPages[8] << 14) + v5;
    *bytesCommitted = v6;
    v7 = (p_m_nCommittedPages[16] << 14) + v6;
    *bytesCommitted = v7;
    v8 = (p_m_nCommittedPages[24] << 14) + v7;
    *bytesCommitted = v8;
    v9 = v8 + (p_m_nCommittedPages[32] << 14);
    p_m_nCommittedPages += 48;
    *bytesCommitted = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006CF0
// Name: public: unsigned int CSmallBlockHeap<class CStdMemAlloc::CVirtualAllocator>::GetSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::GetSize(
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *this,
        void *p)
{
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::SharedData_t *m_pSharedData; // ecx
  unsigned int v3; // eax

  m_pSharedData = this->m_pSharedData;
  v3 = ((unsigned int)p - (unsigned int)m_pSharedData->m_pBase) >> 16;
  if ( v3 >= 0x200 )
    return MEMORY[0x10];
  else
    return *(_DWORD *)(*((_DWORD *)&m_pSharedData->m_PageStatus[v3].Next + 1) + 16);
}

//------------------------------------------------------------------------------
// Address: 0x10006D30
// Name: public: void CSmallBlockHeap<class CStdMemAlloc::CVirtualAllocator>::Usage(unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Usage(
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *this,
        unsigned int *bytesCommitted,
        unsigned int *bytesAllocated)
{
  unsigned int *p_m_nCommittedPages; // ecx
  int i; // esi
  unsigned int v5; // edx
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edi

  *bytesCommitted = 0;
  *bytesAllocated = 0;
  p_m_nCommittedPages = &this->m_Pools[1].m_nCommittedPages;
  for ( i = 7; i != 0; --i )
  {
    *bytesCommitted += *(p_m_nCommittedPages - 8) << 16;
    v5 = (*p_m_nCommittedPages << 16) + *bytesCommitted;
    *bytesCommitted = v5;
    v6 = (p_m_nCommittedPages[8] << 16) + v5;
    *bytesCommitted = v6;
    v7 = (p_m_nCommittedPages[16] << 16) + v6;
    *bytesCommitted = v7;
    v8 = (p_m_nCommittedPages[24] << 16) + v7;
    *bytesCommitted = v8;
    v9 = v8 + (p_m_nCommittedPages[32] << 16);
    p_m_nCommittedPages += 48;
    *bytesCommitted = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006DA0
// Name: public: void __near * CSmallBlockPool<class CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
signed __int32 __thiscall CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *this)
{
  int v2; // ecx
  int m_nReaders; // ecx
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  signed __int32 v6; // ecx
  volatile signed __int32 *p_m_pNextAlloc; // esi
  signed __int32 v8; // eax
  unsigned int v9; // eax
  DWORD CurrentThreadId; // eax
  __int64 value64; // kr00_8
  unsigned __int8 *m_pNextBlock; // ecx
  CThreadFastMutex *p_m_CommitMutex; // edi
  bool v14; // zf
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t *v16; // ecx
  unsigned int v17; // eax
  unsigned __int8 *v18; // eax
  int Priority; // eax
  __int64 v20; // [esp-10h] [ebp-28h]
  __int64 v21; // [esp-10h] [ebp-28h]
  unsigned int nBlockSize; // [esp+10h] [ebp-8h]
  int iThreadPriority; // [esp+14h] [ebp-4h]

  if ( (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (v2 = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders,
        _InterlockedCompareExchange(
          (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock,
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders + 1,
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders) != v2) )
  {
    if ( (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_nReaders = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders,
          _InterlockedCompareExchange(
            (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock,
            CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders + 1,
            CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders) != m_nReaders) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock);
    }
  }
  Next = this->m_FreeList.m_Head.value.Next;
  DepthAndSequence = this->m_FreeList.m_Head.value32.DepthAndSequence;
  iThreadPriority = 0x7FFFFFFF;
  if ( this->m_FreeList.m_Head.value.Next != nullptr )
  {
    while ( 1 )
    {
      HIDWORD(v20) = DepthAndSequence - 1;
      LODWORD(v20) = Next->Next;
      if ( ThreadInterlockedAssignIf64(
             pDest: (volatile __int64 *)this,
             value: v20,
             comperand: __SPAIR64__(DepthAndSequence, (unsigned int)Next)) )
      {
        break;
      }
      _mm_pause();
      Next = this->m_FreeList.m_Head.value.Next;
      DepthAndSequence = this->m_FreeList.m_Head.value32.DepthAndSequence;
      if ( this->m_FreeList.m_Head.value.Next == nullptr )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    Next = nullptr;
  }
  v6 = (signed __int32)Next;
  if ( Next == nullptr )
  {
    nBlockSize = this->m_nBlockSize;
    p_m_pNextAlloc = (volatile signed __int32 *)&this->m_pNextAlloc;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v6 = *p_m_pNextAlloc;
          if ( *p_m_pNextAlloc == 0 )
            break;
          v8 = nBlockSize + v6;
          if ( nBlockSize + (((_WORD)nBlockSize + (_WORD)v6 - 1) & 0x3FFF) > 0x4000 )
            v8 = 0;
          if ( _InterlockedCompareExchange(p_m_pNextAlloc, v8, v6) == v6 )
          {
            v9 = (v6 - (unsigned int)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase) >> 14;
            goto LABEL_40;
          }
        }
        CurrentThreadId = GetCurrentThreadId();
        if ( CurrentThreadId == this->m_CommitMutex.m_ownerID
          || _InterlockedCompareExchange((volatile signed __int32 *)&this->m_CommitMutex, CurrentThreadId, 0) == 0 )
        {
          break;
        }
        Priority = iThreadPriority;
        if ( iThreadPriority == 0x7FFFFFFF )
        {
          Priority = ThreadGetPriority(hThread: nullptr);
          iThreadPriority = Priority;
        }
        if ( Priority > 0 )
          ThreadSleep(duration: 0);
      }
      ++this->m_CommitMutex.m_depth;
      if ( *p_m_pNextAlloc == 0 )
      {
        value64 = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_FreePages.m_Head.value64;
        if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_FreePages.m_Head.value.Next != nullptr )
        {
          while ( 1 )
          {
            HIDWORD(v21) = HIDWORD(value64) - 1;
            LODWORD(v21) = *(_DWORD *)value64;
            if ( ThreadInterlockedAssignIf64(
                   pDest: (volatile __int64 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_FreePages,
                   value: v21,
                   comperand: value64) )
            {
              break;
            }
            _mm_pause();
            value64 = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_FreePages.m_Head.value64;
            if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_FreePages.m_Head.value.Next == nullptr )
              goto LABEL_23;
          }
          v16 = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t *)value64;
          v17 = ((int)value64 - (int)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData - 24) / 24;
        }
        else
        {
LABEL_23:
          m_pNextBlock = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock;
          if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock >= CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pLimit )
            goto LABEL_26;
          while ( (unsigned __int8 *)_InterlockedCompareExchange(
                                       (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock,
                                       (signed __int32)(m_pNextBlock + 0x4000),
                                       (signed __int32)m_pNextBlock) != m_pNextBlock )
          {
            m_pNextBlock = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock;
            if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock >= CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pLimit )
              goto LABEL_26;
          }
          v17 = (unsigned int)(m_pNextBlock - CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase) >> 14;
          v16 = &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[v17];
        }
        if ( v16 == nullptr )
        {
LABEL_26:
          _InterlockedExchange((volatile __int32 *)&this->m_pNextAlloc, 0);
          p_m_CommitMutex = &this->m_CommitMutex;
          v14 = p_m_CommitMutex->m_depth-- == 1;
          if ( v14 )
            _InterlockedExchange((volatile __int32 *)p_m_CommitMutex, 0);
          _InterlockedExchangeAdd(
            (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock,
            0xFFFFFFFF);
          return 0;
        }
        v18 = &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase[0x4000 * v17];
        *((_DWORD *)&v16->Next + 1) = this;
        _InterlockedExchange(&v16->m_nAllocated.m_value, 0);
        v16->m_pNextPageInPool = this->m_pFirstPage;
        ++this->m_nCommittedPages;
        p_m_pNextAlloc = (volatile signed __int32 *)&this->m_pNextAlloc;
        this->m_pFirstPage = v16;
        _InterlockedExchange((volatile __int32 *)&this->m_pNextAlloc, (__int32)v18);
      }
      v14 = this->m_CommitMutex.m_depth-- == 1;
      if ( v14 )
        _InterlockedExchange((volatile __int32 *)&this->m_CommitMutex, 0);
    }
  }
  v9 = (unsigned int)((char *)Next - (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase) >> 14;
LABEL_40:
  _InterlockedExchangeAdd(
    &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[v9].m_nAllocated.m_value,
    1u);
  _InterlockedExchangeAdd(
    (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock,
    0xFFFFFFFF);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10007040
// Name: public: void CSmallBlockPool<class CStdMemAlloc::CFixedAllocator<48,1>>::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Free(
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *this,
        TSLNodeBase_t *p)
{
  unsigned int v2; // esi
  int v4; // ecx
  int m_nReaders; // ecx

  v2 = (unsigned int)((char *)p - (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase) >> 14;
  if ( (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (v4 = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders,
        _InterlockedCompareExchange(
          (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock,
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders + 1,
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders) != v4) )
  {
    if ( (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_nReaders = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders,
          _InterlockedCompareExchange(
            (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock,
            CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders + 1,
            CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders) != m_nReaders) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock);
    }
  }
  _InterlockedExchangeAdd(
    &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[v2].m_nAllocated.m_value,
    0xFFFFFFFF);
  CTSListBase::Push(this: &this->m_FreeList, pNode: p);
  _InterlockedExchangeAdd(
    (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock,
    0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x100070F0
// Name: public: bool CSmallBlockPool<class CStdMemAlloc::CFixedAllocator<48,1>>::Validate(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Validate(
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *this)
{
  unsigned int v2; // ebx
  void *v3; // esp
  void *v4; // esp
  unsigned int *v5; // esi
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t *m_pFirstPage; // eax
  unsigned __int8 **v7; // ebx
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t *v8; // esi
  unsigned __int8 *v9; // eax
  TSLNodeBase_t *Next; // ebx
  unsigned int v11; // eax
  int v12; // ecx
  unsigned __int8 *v13; // edx
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t *v14; // edi
  unsigned int *v15; // edx
  int v16; // eax
  unsigned __int8 v18[12]; // [esp+0h] [ebp-20h] BYREF
  unsigned int blocksPerPage; // [esp+Ch] [ebp-14h]
  unsigned int *pageCounts; // [esp+10h] [ebp-10h]
  unsigned __int8 **pPageBases; // [esp+14h] [ebp-Ch]
  unsigned int nPages; // [esp+18h] [ebp-8h]
  int invalid; // [esp+1Ch] [ebp-4h]

  invalid = 0;
  if ( (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange(
         (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock,
         0x10000,
         0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock);
  }
  else
  {
    CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_writerId = GetCurrentThreadId();
  }
  v2 = 4 * this->m_nCommittedPages;
  v3 = alloca(v2);
  pPageBases = (unsigned __int8 **)v18;
  v4 = alloca(v2);
  v5 = (unsigned int *)v18;
  pageCounts = (unsigned int *)v18;
  memset(dst: v18, value: 0, count: v2);
  m_pFirstPage = this->m_pFirstPage;
  nPages = 0;
  if ( m_pFirstPage != nullptr )
  {
    v7 = pPageBases;
    v8 = m_pFirstPage;
    blocksPerPage = (char *)pageCounts - (char *)pPageBases;
    do
    {
      v9 = &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase[0x4000
                                                                                      * (((char *)v8
                                                                                        - (char *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData
                                                                                        - 24)
                                                                                       / 24)];
      *v7 = v9;
      if ( *((CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > **)&v8->Next + 1) != this )
      {
        invalid = 828;
        goto notValid;
      }
      if ( nPages > this->m_nCommittedPages )
      {
        invalid = 833;
        goto notValid;
      }
      if ( this->m_pNextAlloc.m_value >= v9 && this->m_pNextAlloc.m_value < (unsigned __int8 *volatile)v9 + 0x4000 )
        *(unsigned __int8 **)((char *)v7 + blocksPerPage) = (unsigned __int8 *)((v9 - this->m_pNextAlloc.m_value + 0x4000)
                                                                              / this->m_nBlockSize);
      v8 = v8->m_pNextPageInPool;
      ++nPages;
      ++v7;
    }
    while ( v8 != nullptr );
    if ( nPages != this->m_nCommittedPages )
    {
      invalid = 848;
      goto notValid;
    }
    v5 = pageCounts;
  }
  else if ( this->m_nCommittedPages != 0 )
  {
    invalid = 816;
    goto notValid;
  }
  Next = this->m_FreeList.m_Head.value.Next;
  blocksPerPage = 0x4000 / this->m_nBlockSize;
  if ( Next != nullptr )
  {
    while ( 1 )
    {
      v11 = nPages;
      v12 = 0;
      if ( nPages != 0 )
      {
        while ( 1 )
        {
          v13 = pPageBases[v12];
          if ( Next >= (TSLNodeBase_t *)v13 && Next < (TSLNodeBase_t *)v13 + 2048 )
            break;
          if ( ++v12 >= nPages )
            goto LABEL_27;
        }
        ++v5[v12];
      }
LABEL_27:
      if ( v12 == v11 )
        break;
      Next = Next->Next;
      if ( Next == nullptr )
        goto LABEL_29;
    }
    invalid = 875;
  }
  else
  {
LABEL_29:
    v14 = this->m_pFirstPage;
    if ( v14 != nullptr )
    {
      v15 = v5;
      while ( 1 )
      {
        v16 = *v15++;
        if ( blocksPerPage - v14->m_nAllocated.m_value != v16 )
          break;
        v14 = v14->m_pNextPageInPool;
        if ( v14 == nullptr )
          goto notValid;
      }
      invalid = 889;
    }
  }
notValid:
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_writerId = 0;
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_i32 = 0;
  return invalid == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100072E0
// Name: public: void __near * CSmallBlockPool<class CStdMemAlloc::CVirtualAllocator>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
signed __int32 __thiscall CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Alloc(
        CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *this)
{
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *v1; // ebx
  int v2; // ecx
  int m_nReaders; // ecx
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  signed __int32 m_value; // ecx
  volatile signed __int32 *p_m_pNextAlloc; // esi
  signed __int32 v8; // eax
  unsigned int v9; // eax
  DWORD CurrentThreadId; // eax
  __int64 value64; // kr00_8
  unsigned __int8 *m_pNextBlock; // ecx
  bool v13; // zf
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t *v15; // edi
  unsigned int v16; // eax
  unsigned __int8 *v17; // ebx
  __int64 v18; // [esp-10h] [ebp-2Ch]
  __int64 v19; // [esp-10h] [ebp-2Ch]
  int nBlockSize; // [esp+10h] [ebp-Ch]
  int iThreadPriority; // [esp+18h] [ebp-4h]

  v1 = this;
  if ( (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (v2 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders,
        _InterlockedCompareExchange(
          (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock,
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders + 1,
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders) != v2) )
  {
    if ( (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_nReaders = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders,
          _InterlockedCompareExchange(
            (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock,
            CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders + 1,
            CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders) != m_nReaders) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock);
    }
  }
  Next = v1->m_FreeList.m_Head.value.Next;
  DepthAndSequence = v1->m_FreeList.m_Head.value32.DepthAndSequence;
  iThreadPriority = 0x7FFFFFFF;
  if ( v1->m_FreeList.m_Head.value.Next != nullptr )
  {
    while ( 1 )
    {
      HIDWORD(v18) = DepthAndSequence - 1;
      LODWORD(v18) = Next->Next;
      if ( ThreadInterlockedAssignIf64(
             pDest: (volatile __int64 *)v1,
             value: v18,
             comperand: __SPAIR64__(DepthAndSequence, (unsigned int)Next)) )
      {
        break;
      }
      _mm_pause();
      Next = v1->m_FreeList.m_Head.value.Next;
      DepthAndSequence = v1->m_FreeList.m_Head.value32.DepthAndSequence;
      if ( v1->m_FreeList.m_Head.value.Next == nullptr )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    Next = nullptr;
  }
  m_value = (signed __int32)Next;
  if ( Next == nullptr )
  {
    nBlockSize = v1->m_nBlockSize;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          m_value = (signed __int32)v1->m_pNextAlloc.m_value;
          p_m_pNextAlloc = (volatile signed __int32 *)&v1->m_pNextAlloc;
          if ( m_value == 0 )
            break;
          v8 = nBlockSize + m_value;
          if ( nBlockSize + (unsigned int)(unsigned __int16)(nBlockSize + m_value - 1) > 0x10000 )
            v8 = 0;
          if ( _InterlockedCompareExchange(p_m_pNextAlloc, v8, m_value) == m_value )
          {
            v9 = (m_value - (unsigned int)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase) >> 16;
            goto LABEL_42;
          }
        }
        CurrentThreadId = GetCurrentThreadId();
        if ( CurrentThreadId == v1->m_CommitMutex.m_ownerID
          || _InterlockedCompareExchange((volatile signed __int32 *)&v1->m_CommitMutex, CurrentThreadId, 0) == 0 )
        {
          break;
        }
        if ( iThreadPriority == 0x7FFFFFFF )
          iThreadPriority = ThreadGetPriority(hThread: nullptr);
        if ( iThreadPriority > 0 )
          ThreadSleep(duration: 0);
      }
      ++v1->m_CommitMutex.m_depth;
      if ( *p_m_pNextAlloc == 0 )
      {
        value64 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value64;
        if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value.Next != nullptr )
        {
          while ( 1 )
          {
            HIDWORD(v19) = HIDWORD(value64) - 1;
            LODWORD(v19) = *(_DWORD *)value64;
            if ( ThreadInterlockedAssignIf64(
                   pDest: (volatile __int64 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages,
                   value: v19,
                   comperand: value64) )
            {
              break;
            }
            _mm_pause();
            value64 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value64;
            if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value.Next == nullptr )
              goto LABEL_23;
          }
          v15 = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t *)value64;
          v16 = ((int)value64 - (int)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData - 24) / 24;
        }
        else
        {
LABEL_23:
          m_pNextBlock = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock;
          if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock >= CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pLimit )
            goto LABEL_26;
          while ( (unsigned __int8 *)_InterlockedCompareExchange(
                                       (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock,
                                       (signed __int32)(m_pNextBlock + 0x10000),
                                       (signed __int32)m_pNextBlock) != m_pNextBlock )
          {
            m_pNextBlock = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock;
            if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock >= CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pLimit )
              goto LABEL_26;
          }
          v16 = (unsigned int)(m_pNextBlock - CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase) >> 16;
          v15 = &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[v16];
        }
        if ( v15 == nullptr )
        {
LABEL_26:
          _InterlockedExchange((volatile __int32 *)&v1->m_pNextAlloc, 0);
          v13 = v1->m_CommitMutex.m_depth-- == 1;
          if ( v13 )
            _InterlockedExchange((volatile __int32 *)&v1->m_CommitMutex, 0);
          _InterlockedExchangeAdd(
            (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock,
            0xFFFFFFFF);
          return 0;
        }
        v17 = &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase[0x10000 * v16];
        if ( v15->m_nAllocated.m_value == -1 )
          VirtualAlloc(lpAddress: v17, dwSize: 0x10000u, flAllocationType: 0x1000u, flProtect: 4u);
        *((_DWORD *)&v15->Next + 1) = this;
        _InterlockedExchange(&v15->m_nAllocated.m_value, 0);
        v15->m_pNextPageInPool = this->m_pFirstPage;
        ++this->m_nCommittedPages;
        this->m_pFirstPage = v15;
        _InterlockedExchange((volatile __int32 *)&this->m_pNextAlloc, (__int32)v17);
        v1 = this;
      }
      v13 = v1->m_CommitMutex.m_depth-- == 1;
      if ( v13 )
        _InterlockedExchange((volatile __int32 *)&v1->m_CommitMutex, 0);
    }
  }
  v9 = (unsigned int)((char *)Next - (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase) >> 16;
LABEL_42:
  _InterlockedExchangeAdd(
    &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[v9].m_nAllocated.m_value,
    1u);
  _InterlockedExchangeAdd(
    (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock,
    0xFFFFFFFF);
  return m_value;
}

//------------------------------------------------------------------------------
// Address: 0x100075A0
// Name: public: void CSmallBlockPool<class CStdMemAlloc::CVirtualAllocator>::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Free(
        CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *this,
        TSLNodeBase_t *p)
{
  unsigned int v2; // esi
  int v4; // ecx
  int m_nReaders; // ecx

  v2 = (unsigned int)((char *)p - (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase) >> 16;
  if ( (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (v4 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders,
        _InterlockedCompareExchange(
          (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock,
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders + 1,
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders) != v4) )
  {
    if ( (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_nReaders = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders,
          _InterlockedCompareExchange(
            (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock,
            CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders + 1,
            CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_nReaders) != m_nReaders) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock);
    }
  }
  _InterlockedExchangeAdd(
    &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[v2].m_nAllocated.m_value,
    0xFFFFFFFF);
  CTSListBase::Push(this: &this->m_FreeList, pNode: p);
  _InterlockedExchangeAdd(
    (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock,
    0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x10007650
// Name: public: bool CSmallBlockPool<class CStdMemAlloc::CVirtualAllocator>::Validate(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Validate(
        CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *this)
{
  unsigned int v2; // ebx
  void *v3; // esp
  void *v4; // esp
  unsigned int *v5; // esi
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t *m_pFirstPage; // eax
  unsigned __int8 **v7; // ebx
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t *v8; // esi
  unsigned __int8 *v9; // eax
  TSLNodeBase_t *Next; // ebx
  unsigned int v11; // eax
  int v12; // ecx
  unsigned __int8 *v13; // edx
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t *v14; // edi
  unsigned int *v15; // edx
  int v16; // eax
  unsigned __int8 v18[12]; // [esp+0h] [ebp-20h] BYREF
  unsigned int blocksPerPage; // [esp+Ch] [ebp-14h]
  unsigned int *pageCounts; // [esp+10h] [ebp-10h]
  unsigned __int8 **pPageBases; // [esp+14h] [ebp-Ch]
  unsigned int nPages; // [esp+18h] [ebp-8h]
  int invalid; // [esp+1Ch] [ebp-4h]

  invalid = 0;
  if ( (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange(
         (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock,
         0x10000,
         0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock);
  }
  else
  {
    CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_writerId = GetCurrentThreadId();
  }
  v2 = 4 * this->m_nCommittedPages;
  v3 = alloca(v2);
  pPageBases = (unsigned __int8 **)v18;
  v4 = alloca(v2);
  v5 = (unsigned int *)v18;
  pageCounts = (unsigned int *)v18;
  memset(dst: v18, value: 0, count: v2);
  m_pFirstPage = this->m_pFirstPage;
  nPages = 0;
  if ( m_pFirstPage != nullptr )
  {
    v7 = pPageBases;
    v8 = m_pFirstPage;
    blocksPerPage = (char *)pageCounts - (char *)pPageBases;
    do
    {
      v9 = &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase[0x10000
                                                                                  * (((char *)v8
                                                                                    - (char *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData
                                                                                    - 24)
                                                                                   / 24)];
      *v7 = v9;
      if ( *((CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> **)&v8->Next + 1) != this )
      {
        invalid = 828;
        goto notValid_0;
      }
      if ( nPages > this->m_nCommittedPages )
      {
        invalid = 833;
        goto notValid_0;
      }
      if ( this->m_pNextAlloc.m_value >= v9 && this->m_pNextAlloc.m_value < (unsigned __int8 *volatile)v9 + 0x10000 )
        *(unsigned __int8 **)((char *)v7 + blocksPerPage) = (unsigned __int8 *)((v9
                                                                               - this->m_pNextAlloc.m_value
                                                                               + 0x10000)
                                                                              / this->m_nBlockSize);
      v8 = v8->m_pNextPageInPool;
      ++nPages;
      ++v7;
    }
    while ( v8 != nullptr );
    if ( nPages != this->m_nCommittedPages )
    {
      invalid = 848;
      goto notValid_0;
    }
    v5 = pageCounts;
  }
  else if ( this->m_nCommittedPages != 0 )
  {
    invalid = 816;
    goto notValid_0;
  }
  Next = this->m_FreeList.m_Head.value.Next;
  blocksPerPage = 0x10000 / this->m_nBlockSize;
  if ( Next != nullptr )
  {
    while ( 1 )
    {
      v11 = nPages;
      v12 = 0;
      if ( nPages != 0 )
      {
        while ( 1 )
        {
          v13 = pPageBases[v12];
          if ( Next >= (TSLNodeBase_t *)v13 && Next < (TSLNodeBase_t *)v13 + 0x2000 )
            break;
          if ( ++v12 >= nPages )
            goto LABEL_27;
        }
        ++v5[v12];
      }
LABEL_27:
      if ( v12 == v11 )
        break;
      Next = Next->Next;
      if ( Next == nullptr )
        goto LABEL_29;
    }
    invalid = 875;
  }
  else
  {
LABEL_29:
    v14 = this->m_pFirstPage;
    if ( v14 != nullptr )
    {
      v15 = v5;
      while ( 1 )
      {
        v16 = *v15++;
        if ( blocksPerPage - v14->m_nAllocated.m_value != v16 )
          break;
        v14 = v14->m_pNextPageInPool;
        if ( v14 == nullptr )
          goto notValid_0;
      }
      invalid = 889;
    }
  }
notValid_0:
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_writerId = 0;
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_i32 = 0;
  return invalid == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007840
// Name: private: bool CSmallBlockPool<class CStdMemAlloc::CFixedAllocator<48,1>>::RemovePagesFromFreeList(unsigned char __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::RemovePagesFromFreeList(
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *this,
        unsigned __int8 **pPages,
        int nPages,
        bool bSortList)
{
  int v4; // esi
  void *v6; // esp
  unsigned __int8 **v7; // ecx
  int v8; // esi
  unsigned __int8 *volatile m_value; // eax
  unsigned __int8 *v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // edi
  TSLNodeBase_t *v13; // edi
  void *v14; // esp
  int v15; // ecx
  _DWORD *v16; // eax
  int v17; // eax
  CTSListBase *p_m_SortList; // esi
  int v19; // esi
  TSLNodeBase_t *v20; // esi
  int DepthAndSequence; // eax
  CTSListBase *v22; // edi
  TSLNodeBase_t *v24; // ebx
  int v25; // ecx
  _DWORD *v26; // eax
  TSLNodeBase_t *v27; // eax
  __int64 v28; // [esp-10h] [ebp-34h]
  __int64 v29; // [esp-10h] [ebp-34h]
  __int64 v30; // [esp-10h] [ebp-34h]
  __int64 v31; // [esp-10h] [ebp-34h]
  __int64 v32; // [esp-10h] [ebp-34h]
  __int64 value64; // [esp-8h] [ebp-2Ch]
  __int64 v34; // [esp-8h] [ebp-2Ch]
  __int64 v35; // [esp-8h] [ebp-2Ch]
  __int64 v36; // [esp-8h] [ebp-2Ch]
  _BYTE v37[12]; // [esp+0h] [ebp-24h] BYREF
  TSLNodeBase_t *Next; // [esp+Ch] [ebp-18h]
  unsigned __int8 *m_pBase; // [esp+10h] [ebp-14h]
  _BYTE *v40; // [esp+14h] [ebp-10h]
  void *base; // [esp+18h] [ebp-Ch]
  unsigned int v42; // [esp+1Ch] [ebp-8h]
  int v43; // [esp+20h] [ebp-4h]
  int v44; // [esp+30h] [ebp+Ch]
  int num; // [esp+34h] [ebp+10h]
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *numa; // [esp+34h] [ebp+10h]

  v4 = nPages;
  v6 = alloca(4 * nPages);
  v7 = (unsigned __int8 **)v37;
  v40 = v37;
  v42 = 0;
  if ( nPages > 0 )
  {
    v8 = (char *)pPages - v37;
    for ( base = (void *)nPages; base != nullptr; base = (char *)base - 1 )
    {
      m_value = this->m_pNextAlloc.m_value;
      v10 = *(unsigned __int8 **)((char *)v7 + v8) + 0x4000;
      *v7 = v10;
      if ( m_value >= *(unsigned __int8 **)((char *)v7 + v8) && this->m_pNextAlloc.m_value < v10 )
      {
        v42 = (v10 - this->m_pNextAlloc.m_value) / this->m_nBlockSize;
        _InterlockedExchange((volatile __int32 *)&this->m_pNextAlloc, 0);
      }
      ++v7;
    }
    v4 = nPages;
  }
  v11 = 0x4000 / this->m_nBlockSize;
  v43 = 0;
  v12 = v4 * v11 - v42;
  v42 = v12;
  if ( bSortList && this->m_nCommittedPages - v4 != 1 )
  {
    m_pBase = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase;
    v13 = CTSListBase::Detach(this: &this->m_FreeList);
    num = 0;
    v14 = alloca(4 * this->m_nCommittedPages);
    base = v37;
    if ( v13 != nullptr )
    {
      do
      {
        v15 = 0;
        Next = v13->Next;
        if ( v4 <= 0 )
        {
LABEL_16:
          v17 = ((char *)v13 - (char *)m_pBase) / 0x4000;
          if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[v17].m_SortList.m_Head.value.Depth == 0 )
            *((_DWORD *)base + num++) = v17;
          p_m_SortList = &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[v17].m_SortList;
          value64 = p_m_SortList->m_Head.value64;
          HIDWORD(v28) = p_m_SortList->m_Head.value32.DepthAndSequence + 65537;
          LODWORD(v28) = v13;
          v13->Next = p_m_SortList->m_Head.value.Next;
          if ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)p_m_SortList, value: v28, comperand: value64) )
          {
            do
            {
              _mm_pause();
              v34 = p_m_SortList->m_Head.value64;
              HIDWORD(v29) = p_m_SortList->m_Head.value32.DepthAndSequence + 65537;
              LODWORD(v29) = v13;
              v13->Next = p_m_SortList->m_Head.value.Next;
            }
            while ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)p_m_SortList, value: v29, comperand: v34) );
          }
          v4 = nPages;
        }
        else
        {
          v16 = v40;
          while ( (unsigned int)v13 < *(_DWORD *)((char *)v16 + (char *)pPages - v40) || (unsigned int)v13 >= *v16 )
          {
            ++v15;
            ++v16;
            if ( v15 >= v4 )
              goto LABEL_16;
          }
          ++v43;
        }
        v13 = Next;
      }
      while ( Next != nullptr );
      v19 = num;
      if ( num > 1 )
        qsort(
          base,
          num,
          width: 4u,
          comp: (int (__cdecl *)(const void *, const void *))CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::PageSort);
    }
    else
    {
      v19 = 0;
    }
    v44 = 0;
    if ( v19 > 0 )
    {
      do
      {
        while ( 1 )
        {
          v20 = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[*((_DWORD *)base + v44)].m_SortList.m_Head.value.Next;
          DepthAndSequence = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[*((_DWORD *)base + v44)].m_SortList.m_Head.value32.DepthAndSequence;
          v22 = &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_PageStatus[*((_DWORD *)base + v44)].m_SortList;
          if ( v20 == nullptr )
            break;
          while ( 1 )
          {
            HIDWORD(v30) = DepthAndSequence - 1;
            LODWORD(v30) = v20->Next;
            if ( ThreadInterlockedAssignIf64(
                   pDest: (volatile __int64 *)v22,
                   value: v30,
                   comperand: __SPAIR64__(DepthAndSequence, (unsigned int)v20)) )
            {
              break;
            }
            _mm_pause();
            v20 = v22->m_Head.value.Next;
            DepthAndSequence = v22->m_Head.value32.DepthAndSequence;
            if ( v22->m_Head.value.Next == nullptr )
              goto LABEL_30;
          }
          v35 = this->m_FreeList.m_Head.value64;
          HIDWORD(v31) = this->m_FreeList.m_Head.value32.DepthAndSequence + 65537;
          LODWORD(v31) = v20;
          v20->Next = this->m_FreeList.m_Head.value.Next;
          if ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)this, value: v31, comperand: v35) )
          {
            do
            {
              _mm_pause();
              v36 = this->m_FreeList.m_Head.value64;
              HIDWORD(v32) = this->m_FreeList.m_Head.value32.DepthAndSequence + 65537;
              LODWORD(v32) = v20;
              v20->Next = this->m_FreeList.m_Head.value.Next;
            }
            while ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)this, value: v32, comperand: v36) );
          }
        }
LABEL_30:
        ++v44;
      }
      while ( v44 < num );
    }
    v12 = v42;
    goto LABEL_32;
  }
  numa = this;
  v24 = this->m_FreeList.m_Head.value.Next;
  if ( v24 == nullptr )
  {
LABEL_32:
    if ( v12 != v43 && Plat_IsInDebugSession() )
      __debugbreak();
    return v12 == v43;
  }
  while ( v43 != v12 )
  {
    v25 = 0;
    if ( v4 <= 0 )
    {
LABEL_47:
      numa->m_FreeList.m_Head.value.Next = v24;
      numa = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *)v24;
    }
    else
    {
      v26 = v37;
      while ( (unsigned int)v24 < *(_DWORD *)((char *)v26 + (char *)pPages - v37) || (unsigned int)v24 >= *v26 )
      {
        ++v25;
        ++v26;
        if ( v25 >= v4 )
        {
          v12 = v42;
          goto LABEL_47;
        }
      }
      v27 = v24->Next;
      ++v43;
      v12 = v42;
      numa->m_FreeList.m_Head.value.Next = v27;
    }
    v24 = v24->Next;
    if ( v24 == nullptr )
      goto LABEL_32;
  }
  return v12 == v43;
}

//------------------------------------------------------------------------------
// Address: 0x10007B20
// Name: private: bool CSmallBlockPool<class CStdMemAlloc::CVirtualAllocator>::RemovePagesFromFreeList(unsigned char __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::RemovePagesFromFreeList(
        CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *this,
        unsigned __int8 **pPages,
        int nPages,
        bool bSortList)
{
  int v4; // esi
  void *v6; // esp
  unsigned __int8 **v7; // ecx
  int v8; // esi
  unsigned __int8 *volatile m_value; // eax
  unsigned __int8 *v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // edi
  TSLNodeBase_t *v13; // edi
  void *v14; // esp
  int v15; // ecx
  _DWORD *v16; // eax
  int v17; // eax
  CTSListBase *p_m_SortList; // esi
  int v19; // esi
  TSLNodeBase_t *v20; // esi
  int DepthAndSequence; // eax
  CTSListBase *v22; // edi
  TSLNodeBase_t *v24; // ebx
  int v25; // ecx
  _DWORD *v26; // eax
  TSLNodeBase_t *v27; // eax
  __int64 v28; // [esp-10h] [ebp-34h]
  __int64 v29; // [esp-10h] [ebp-34h]
  __int64 v30; // [esp-10h] [ebp-34h]
  __int64 v31; // [esp-10h] [ebp-34h]
  __int64 v32; // [esp-10h] [ebp-34h]
  __int64 value64; // [esp-8h] [ebp-2Ch]
  __int64 v34; // [esp-8h] [ebp-2Ch]
  __int64 v35; // [esp-8h] [ebp-2Ch]
  __int64 v36; // [esp-8h] [ebp-2Ch]
  _BYTE v37[12]; // [esp+0h] [ebp-24h] BYREF
  TSLNodeBase_t *Next; // [esp+Ch] [ebp-18h]
  unsigned __int8 *m_pBase; // [esp+10h] [ebp-14h]
  _BYTE *v40; // [esp+14h] [ebp-10h]
  void *base; // [esp+18h] [ebp-Ch]
  unsigned int v42; // [esp+1Ch] [ebp-8h]
  int v43; // [esp+20h] [ebp-4h]
  int v44; // [esp+30h] [ebp+Ch]
  int num; // [esp+34h] [ebp+10h]
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *numa; // [esp+34h] [ebp+10h]

  v4 = nPages;
  v6 = alloca(4 * nPages);
  v7 = (unsigned __int8 **)v37;
  v40 = v37;
  v42 = 0;
  if ( nPages > 0 )
  {
    v8 = (char *)pPages - v37;
    for ( base = (void *)nPages; base != nullptr; base = (char *)base - 1 )
    {
      m_value = this->m_pNextAlloc.m_value;
      v10 = *(unsigned __int8 **)((char *)v7 + v8) + 0x10000;
      *v7 = v10;
      if ( m_value >= *(unsigned __int8 **)((char *)v7 + v8) && this->m_pNextAlloc.m_value < v10 )
      {
        v42 = (v10 - this->m_pNextAlloc.m_value) / this->m_nBlockSize;
        _InterlockedExchange((volatile __int32 *)&this->m_pNextAlloc, 0);
      }
      ++v7;
    }
    v4 = nPages;
  }
  v11 = 0x10000 / this->m_nBlockSize;
  v43 = 0;
  v12 = v4 * v11 - v42;
  v42 = v12;
  if ( bSortList && this->m_nCommittedPages - v4 != 1 )
  {
    m_pBase = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase;
    v13 = CTSListBase::Detach(this: &this->m_FreeList);
    num = 0;
    v14 = alloca(4 * this->m_nCommittedPages);
    base = v37;
    if ( v13 != nullptr )
    {
      do
      {
        v15 = 0;
        Next = v13->Next;
        if ( v4 <= 0 )
        {
LABEL_16:
          v17 = ((char *)v13 - (char *)m_pBase) / 0x10000;
          if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[v17].m_SortList.m_Head.value.Depth == 0 )
            *((_DWORD *)base + num++) = v17;
          p_m_SortList = &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[v17].m_SortList;
          value64 = p_m_SortList->m_Head.value64;
          HIDWORD(v28) = p_m_SortList->m_Head.value32.DepthAndSequence + 65537;
          LODWORD(v28) = v13;
          v13->Next = p_m_SortList->m_Head.value.Next;
          if ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)p_m_SortList, value: v28, comperand: value64) )
          {
            do
            {
              _mm_pause();
              v34 = p_m_SortList->m_Head.value64;
              HIDWORD(v29) = p_m_SortList->m_Head.value32.DepthAndSequence + 65537;
              LODWORD(v29) = v13;
              v13->Next = p_m_SortList->m_Head.value.Next;
            }
            while ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)p_m_SortList, value: v29, comperand: v34) );
          }
          v4 = nPages;
        }
        else
        {
          v16 = v40;
          while ( (unsigned int)v13 < *(_DWORD *)((char *)v16 + (char *)pPages - v40) || (unsigned int)v13 >= *v16 )
          {
            ++v15;
            ++v16;
            if ( v15 >= v4 )
              goto LABEL_16;
          }
          ++v43;
        }
        v13 = Next;
      }
      while ( Next != nullptr );
      v19 = num;
      if ( num > 1 )
        qsort(
          base,
          num,
          width: 4u,
          comp: (int (__cdecl *)(const void *, const void *))CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageSort);
    }
    else
    {
      v19 = 0;
    }
    v44 = 0;
    if ( v19 > 0 )
    {
      do
      {
        while ( 1 )
        {
          v20 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[*((_DWORD *)base + v44)].m_SortList.m_Head.value.Next;
          DepthAndSequence = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[*((_DWORD *)base + v44)].m_SortList.m_Head.value32.DepthAndSequence;
          v22 = &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_PageStatus[*((_DWORD *)base + v44)].m_SortList;
          if ( v20 == nullptr )
            break;
          while ( 1 )
          {
            HIDWORD(v30) = DepthAndSequence - 1;
            LODWORD(v30) = v20->Next;
            if ( ThreadInterlockedAssignIf64(
                   pDest: (volatile __int64 *)v22,
                   value: v30,
                   comperand: __SPAIR64__(DepthAndSequence, (unsigned int)v20)) )
            {
              break;
            }
            _mm_pause();
            v20 = v22->m_Head.value.Next;
            DepthAndSequence = v22->m_Head.value32.DepthAndSequence;
            if ( v22->m_Head.value.Next == nullptr )
              goto LABEL_30;
          }
          v35 = this->m_FreeList.m_Head.value64;
          HIDWORD(v31) = this->m_FreeList.m_Head.value32.DepthAndSequence + 65537;
          LODWORD(v31) = v20;
          v20->Next = this->m_FreeList.m_Head.value.Next;
          if ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)this, value: v31, comperand: v35) )
          {
            do
            {
              _mm_pause();
              v36 = this->m_FreeList.m_Head.value64;
              HIDWORD(v32) = this->m_FreeList.m_Head.value32.DepthAndSequence + 65537;
              LODWORD(v32) = v20;
              v20->Next = this->m_FreeList.m_Head.value.Next;
            }
            while ( !ThreadInterlockedAssignIf64(pDest: (volatile __int64 *)this, value: v32, comperand: v36) );
          }
        }
LABEL_30:
        ++v44;
      }
      while ( v44 < num );
    }
    v12 = v42;
    goto LABEL_32;
  }
  numa = this;
  v24 = this->m_FreeList.m_Head.value.Next;
  if ( v24 == nullptr )
  {
LABEL_32:
    if ( v12 != v43 && Plat_IsInDebugSession() )
      __debugbreak();
    return v12 == v43;
  }
  while ( v43 != v12 )
  {
    v25 = 0;
    if ( v4 <= 0 )
    {
LABEL_47:
      numa->m_FreeList.m_Head.value.Next = v24;
      numa = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *)v24;
    }
    else
    {
      v26 = v37;
      while ( (unsigned int)v24 < *(_DWORD *)((char *)v26 + (char *)pPages - v37) || (unsigned int)v24 >= *v26 )
      {
        ++v25;
        ++v26;
        if ( v25 >= v4 )
        {
          v12 = v42;
          goto LABEL_47;
        }
      }
      v27 = v24->Next;
      ++v43;
      v12 = v42;
      numa->m_FreeList.m_Head.value.Next = v27;
    }
    v24 = v24->Next;
    if ( v24 == nullptr )
      goto LABEL_32;
  }
  return v12 == v43;
}

//------------------------------------------------------------------------------
// Address: 0x10007E00
// Name: public: CSmallBlockPool<class CStdMemAlloc::CFixedAllocator<48,1>>::SharedData_t::SharedData_t(void)
// Source: json
//------------------------------------------------------------------------------
CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::SharedData_t *__thiscall CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::SharedData_t::SharedData_t(
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::SharedData_t *this)
{
  CTSListBase *p_m_FreePages; // ebx
  CInterlockedIntT<int> *p_m_nAllocated; // esi
  int v6; // [esp+10h] [ebp-4h]

  p_m_FreePages = &this->m_FreePages;
  if ( (((_BYTE)this + 8) & 7) != 0 )
  {
    Error(pMsgFormat: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreePages->m_Head.value.Next = nullptr;
  p_m_FreePages->m_Head.value32.DepthAndSequence = 0;
  this->m_Lock.m_lockInfo.m_i32 = 0;
  this->m_Lock.m_writerId = 0;
  v6 = 3071;
  p_m_nAllocated = &this->m_PageStatus[0].m_nAllocated;
  do
  {
    p_m_nAllocated->m_value = 0;
    if ( (((_BYTE)p_m_nAllocated + 4) & 7) != 0 )
    {
      Error(pMsgFormat: "CTSListBase: Misaligned list\n");
      __debugbreak();
    }
    p_m_nAllocated[1].m_value = 0;
    p_m_nAllocated[2].m_value = 0;
    p_m_nAllocated[-2].m_value = 0;
    _InterlockedExchange(&p_m_nAllocated->m_value, -1);
    p_m_nAllocated[-1].m_value = 0;
    p_m_nAllocated += 6;
    --v6;
  }
  while ( v6 >= 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007E80
// Name: public: CSmallBlockPool<class CStdMemAlloc::CVirtualAllocator>::SharedData_t::SharedData_t(void)
// Source: json
//------------------------------------------------------------------------------
CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::SharedData_t *__thiscall CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::SharedData_t::SharedData_t(
        CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::SharedData_t *this)
{
  CTSListBase *p_m_FreePages; // ebx
  CInterlockedIntT<int> *p_m_nAllocated; // esi
  int v6; // [esp+10h] [ebp-4h]

  p_m_FreePages = &this->m_FreePages;
  if ( (((_BYTE)this + 8) & 7) != 0 )
  {
    Error(pMsgFormat: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreePages->m_Head.value.Next = nullptr;
  p_m_FreePages->m_Head.value32.DepthAndSequence = 0;
  this->m_Lock.m_lockInfo.m_i32 = 0;
  this->m_Lock.m_writerId = 0;
  v6 = 511;
  p_m_nAllocated = &this->m_PageStatus[0].m_nAllocated;
  do
  {
    p_m_nAllocated->m_value = 0;
    if ( (((_BYTE)p_m_nAllocated + 4) & 7) != 0 )
    {
      Error(pMsgFormat: "CTSListBase: Misaligned list\n");
      __debugbreak();
    }
    p_m_nAllocated[1].m_value = 0;
    p_m_nAllocated[2].m_value = 0;
    p_m_nAllocated[-2].m_value = 0;
    _InterlockedExchange(&p_m_nAllocated->m_value, -1);
    p_m_nAllocated[-1].m_value = 0;
    p_m_nAllocated += 6;
    --v6;
  }
  while ( v6 >= 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007F00
// Name: public: virtual unsigned int CStdMemAlloc::GetSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CStdMemAlloc::GetSize(CStdMemAlloc *this, unsigned __int8 *pMem)
{
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::SharedData_t *m_pSharedData; // ebx
  unsigned __int8 *m_pBase; // eax
  unsigned int v5; // esi
  CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *p_m_FallbackSBH; // esi

  if ( pMem == nullptr )
    return CalcHeapUsed();
  m_pSharedData = this->m_PrimarySBH.m_pSharedData;
  m_pBase = m_pSharedData->m_pBase;
  if ( pMem < m_pBase || (unsigned int)((pMem - m_pBase) / 0x4000) >= 0xC00 )
  {
    p_m_FallbackSBH = &this->m_FallbackSBH;
    if ( CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::IsOwner(this: &this->m_FallbackSBH, p: pMem) )
      return CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::GetSize(this: p_m_FallbackSBH, p: pMem);
    else
      return dlmalloc_usable_size(mem: pMem);
  }
  else
  {
    v5 = (unsigned int)(pMem - m_pBase) >> 14;
    if ( v5 >= 0xC00 )
      return MEMORY[0x10];
    else
      return *(_DWORD *)(*((_DWORD *)&m_pSharedData->m_PageStatus[v5].Next + 1) + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007FA0
// Name: public: virtual int CStdMemAlloc::GetGenericMemoryStats(struct GenericMemoryStat_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdMemAlloc::GetGenericMemoryStats(CStdMemAlloc *this, GenericMemoryStat_t **ppMemoryStats)
{
  GenericMemoryStat_t **v2; // ebx
  GenericMemoryStat_t **v5; // esi
  char *v6; // esi
  int v7; // eax
  mallinfo *v8; // eax
  unsigned int v9; // edx
  unsigned int uordblks; // ecx
  int v11; // eax
  int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  unsigned int arena; // edx
  int v19; // ecx
  unsigned int fordblks; // eax
  mallinfo v21; // [esp+8h] [ebp-54h] BYREF
  mallinfo infoLBH; // [esp+30h] [ebp-2Ch]
  unsigned int allocTmp; // [esp+58h] [ebp-4h] BYREF

  v2 = ppMemoryStats;
  if ( ppMemoryStats == nullptr )
    return 0;
  g_nMemStats = 0;
  CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Usage(
    this: &this->m_PrimarySBH,
    bytesCommitted: (unsigned int *)&ppMemoryStats,
    bytesAllocated: &allocTmp);
  v5 = ppMemoryStats;
  CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Usage(
    this: &this->m_FallbackSBH,
    bytesCommitted: (unsigned int *)&ppMemoryStats,
    bytesAllocated: &allocTmp);
  v6 = (char *)v5 + (_DWORD)ppMemoryStats;
  v7 = SBHMaxCommitted;
  if ( SBHMaxCommitted <= (unsigned int)v6 )
  {
    v7 = (int)v6;
    SBHMaxCommitted = (unsigned int)v6;
  }
  g_MemStats[0].name = "SBH_cur";
  dword_100421F4[0] = (int)v6;
  dword_100421F8 = (int)"SBH_max";
  dword_100421FC = v7;
  g_nMemStats = 2;
  v8 = mspace_mallinfo(result: &v21, msp: msp);
  v9 = nMBHMaxUsed;
  infoLBH = *v8;
  uordblks = infoLBH.uordblks;
  if ( nMBHMaxUsed <= infoLBH.uordblks )
  {
    v9 = infoLBH.uordblks;
    nMBHMaxUsed = infoLBH.uordblks;
  }
  v11 = g_nMemStats;
  if ( g_nMemStats < 64 )
  {
    g_MemStats[g_nMemStats].name = "MBH_cur";
    dword_100421F4[2 * v11] = uordblks;
    v12 = v11 + 1;
    g_nMemStats = v12;
    if ( v12 < 64 )
    {
      g_MemStats[v12].name = "MBH_max";
      dword_100421F4[2 * v12] = v9;
      g_nMemStats = v12 + 1;
    }
  }
  infoLBH = *mspace_mallinfo(result: &v21, msp: g_AllocRegions[0]);
  v13 = mspace_footprint(msp: g_AllocRegions[0]);
  v14 = mspace_max_footprint(msp: g_AllocRegions[0]);
  v15 = g_nMemStats;
  if ( g_nMemStats < 64 )
  {
    g_MemStats[g_nMemStats].name = "LBH_cur";
    dword_100421F4[2 * v15] = v13;
    v16 = v15 + 1;
    g_nMemStats = v16;
    if ( v16 < 64 )
    {
      g_MemStats[v16].name = "LBH_max";
      dword_100421F4[2 * v16] = v14;
      v17 = v16 + 1;
      g_nMemStats = v17;
      if ( v17 < 64 )
      {
        arena = infoLBH.arena;
        g_MemStats[v17].name = "LBH_arena";
        dword_100421F4[2 * v17] = arena;
        v19 = v17 + 1;
        g_nMemStats = v19;
        if ( v19 < 64 )
        {
          fordblks = infoLBH.fordblks;
          g_MemStats[v19].name = "LBH_free";
          dword_100421F4[2 * v19] = fordblks;
          g_nMemStats = v19 + 1;
        }
      }
    }
  }
  *v2 = g_MemStats;
  return g_nMemStats;
}

//------------------------------------------------------------------------------
// Address: 0x100081C0
// Name: public: void __near * CSmallBlockHeap<class CStdMemAlloc::CFixedAllocator<48,1>>::Realloc(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Realloc(
        CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1> > *this,
        unsigned __int8 *p,
        unsigned int nBytes)
{
  unsigned int v3; // esi
  unsigned __int8 *v4; // edi
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::SharedData_t *m_pSharedData; // edx
  unsigned int v6; // eax
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *v7; // ebx
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *v8; // eax
  unsigned int m_nBlockSize; // eax

  v3 = nBytes;
  if ( nBytes == 0 )
    v3 = 1;
  v4 = p;
  m_pSharedData = this->m_pSharedData;
  v6 = (unsigned int)(p - m_pSharedData->m_pBase) >> 14;
  if ( v6 >= 0xC00 )
    v7 = nullptr;
  else
    v7 = *((CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > **)&m_pSharedData->m_PageStatus[v6].Next + 1);
  if ( v3 > 0x800 )
    v8 = nullptr;
  else
    v8 = this->m_PoolLookup[(v3 - 1) >> 2];
  if ( v7 == v8 )
    return v4;
  v4 = (unsigned __int8 *)g_pMemAlloc->Alloc_2(this: g_pMemAlloc, a2: v3);
  if ( v4 != nullptr || (v4 = (unsigned __int8 *)mspace_malloc(msp: g_AllocRegions[v3 < 0x40000], bytes: v3)) != nullptr )
  {
    m_nBlockSize = v7->m_nBlockSize;
    if ( v3 < m_nBlockSize )
      m_nBlockSize = v3;
    memcpy(dst: v4, src: p, count: m_nBlockSize);
  }
  else if ( v3 < v7->m_nBlockSize )
  {
    return p;
  }
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Free(this: v7, (TSLNodeBase_t *)p);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10008280
// Name: public: void CSmallBlockHeap<class CStdMemAlloc::CFixedAllocator<48,1>>::DumpStats(char const __near *,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::DumpStats(
        CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1> > *this,
        const char *pszTag,
        _iobuf *pFile)
{
  int v4; // esi
  unsigned int *p_m_nCommittedPages; // edi
  unsigned int bytesCommitted; // [esp+Ch] [ebp-8h] BYREF
  unsigned int bytesAllocated; // [esp+10h] [ebp-4h] BYREF

  CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Usage(this, &bytesCommitted, &bytesAllocated);
  v4 = 0;
  p_m_nCommittedPages = &this->m_Pools[0].m_nCommittedPages;
  if ( pFile != nullptr )
  {
    do
    {
      fprintf(
        str: pFile,
        format: "Pool %2i: (size: %4u) blocks: allocated:%5i free:%5i committed:%5i (committed size:%4u kb)\n",
        v4++,
        *(p_m_nCommittedPages - 1),
        0,
        0,
        *p_m_nCommittedPages * (0x4000 / *(p_m_nCommittedPages - 1)),
        *p_m_nCommittedPages << 14);
      p_m_nCommittedPages += 8;
    }
    while ( v4 < 42 );
    fprintf(
      str: pFile,
      format: "Totals (%s): Committed:%5u kb Allocated:%5u kb\n",
      pszTag,
      bytesCommitted >> 10,
      bytesAllocated >> 10);
  }
  else
  {
    do
    {
      Msg(
        pMsgFormat: "Pool %2i: (size: %4u) blocks: allocated:%5i free:%5i committed:%5i (committed size:%4u kb)\n",
        v4++,
        *(p_m_nCommittedPages - 1),
        0,
        0,
        *p_m_nCommittedPages * (0x4000 / *(p_m_nCommittedPages - 1)),
        (int)(*p_m_nCommittedPages << 14) / 1024);
      p_m_nCommittedPages += 8;
    }
    while ( v4 < 42 );
    Msg(
      pMsgFormat: "Totals (%s): Committed:%5u kb Allocated:%5u kb\n",
      pszTag,
      bytesCommitted >> 10,
      bytesAllocated >> 10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008370
// Name: public: void __near * CSmallBlockHeap<class CStdMemAlloc::CVirtualAllocator>::Realloc(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Realloc(
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *this,
        unsigned __int8 *p,
        unsigned int nBytes)
{
  unsigned int v3; // esi
  unsigned __int8 *v4; // edi
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::SharedData_t *m_pSharedData; // edx
  unsigned int v6; // eax
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *v7; // ebx
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *v8; // eax
  unsigned int m_nBlockSize; // eax

  v3 = nBytes;
  if ( nBytes == 0 )
    v3 = 1;
  v4 = p;
  m_pSharedData = this->m_pSharedData;
  v6 = (unsigned int)(p - m_pSharedData->m_pBase) >> 16;
  if ( v6 >= 0x200 )
    v7 = nullptr;
  else
    v7 = *((CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> **)&m_pSharedData->m_PageStatus[v6].Next + 1);
  if ( v3 > 0x800 )
    v8 = nullptr;
  else
    v8 = this->m_PoolLookup[(v3 - 1) >> 2];
  if ( v7 == v8 )
    return v4;
  v4 = (unsigned __int8 *)g_pMemAlloc->Alloc_2(this: g_pMemAlloc, a2: v3);
  if ( v4 != nullptr || (v4 = (unsigned __int8 *)mspace_malloc(msp: g_AllocRegions[v3 < 0x40000], bytes: v3)) != nullptr )
  {
    m_nBlockSize = v7->m_nBlockSize;
    if ( v3 < m_nBlockSize )
      m_nBlockSize = v3;
    memcpy(dst: v4, src: p, count: m_nBlockSize);
  }
  else if ( v3 < v7->m_nBlockSize )
  {
    return p;
  }
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Free(this: v7, (TSLNodeBase_t *)p);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10008430
// Name: public: void CSmallBlockHeap<class CStdMemAlloc::CVirtualAllocator>::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Free(
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *this,
        TSLNodeBase_t *p)
{
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::SharedData_t *m_pSharedData; // ecx
  unsigned int v3; // eax
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *v4; // ecx

  m_pSharedData = this->m_pSharedData;
  v3 = (unsigned int)((char *)p - (char *)m_pSharedData->m_pBase) >> 16;
  if ( v3 < 0x200
    && (v4 = *((CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> **)&m_pSharedData->m_PageStatus[v3].Next + 1)) != nullptr )
  {
    CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Free(this: v4, p);
  }
  else if ( Plat_IsInDebugSession() )
  {
    __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008480
// Name: public: void CSmallBlockHeap<class CStdMemAlloc::CVirtualAllocator>::DumpStats(char const __near *,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::DumpStats(
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *this,
        const char *pszTag,
        _iobuf *pFile)
{
  int v4; // esi
  unsigned int *p_m_nCommittedPages; // edi
  unsigned int bytesCommitted; // [esp+Ch] [ebp-8h] BYREF
  unsigned int bytesAllocated; // [esp+10h] [ebp-4h] BYREF

  CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Usage(this, &bytesCommitted, &bytesAllocated);
  v4 = 0;
  p_m_nCommittedPages = &this->m_Pools[0].m_nCommittedPages;
  if ( pFile != nullptr )
  {
    do
    {
      fprintf(
        str: pFile,
        format: "Pool %2i: (size: %4u) blocks: allocated:%5i free:%5i committed:%5i (committed size:%4u kb)\n",
        v4++,
        *(p_m_nCommittedPages - 1),
        0,
        0,
        *p_m_nCommittedPages * (0x10000 / *(p_m_nCommittedPages - 1)),
        *p_m_nCommittedPages << 16);
      p_m_nCommittedPages += 8;
    }
    while ( v4 < 42 );
    fprintf(
      str: pFile,
      format: "Totals (%s): Committed:%5u kb Allocated:%5u kb\n",
      pszTag,
      bytesCommitted >> 10,
      bytesAllocated >> 10);
  }
  else
  {
    do
    {
      Msg(
        pMsgFormat: "Pool %2i: (size: %4u) blocks: allocated:%5i free:%5i committed:%5i (committed size:%4u kb)\n",
        v4++,
        *(p_m_nCommittedPages - 1),
        0,
        0,
        *p_m_nCommittedPages * (0x10000 / *(p_m_nCommittedPages - 1)),
        (int)(*p_m_nCommittedPages << 16) / 1024);
      p_m_nCommittedPages += 8;
    }
    while ( v4 < 42 );
    Msg(
      pMsgFormat: "Totals (%s): Committed:%5u kb Allocated:%5u kb\n",
      pszTag,
      bytesCommitted >> 10,
      bytesAllocated >> 10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008570
// Name: public: unsigned int CSmallBlockPool<class CStdMemAlloc::CFixedAllocator<48,1>>::Compact(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Compact(
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *this,
        bool bIncremental)
{
  int v2; // ebx
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *v3; // esi
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t *m_pFirstPage; // edi
  unsigned int v5; // esi
  void *v6; // esp
  void *v7; // esp
  void *v8; // esp
  unsigned __int8 **v9; // eax
  int v10; // ecx
  unsigned __int8 **v11; // esi
  unsigned __int8 *v12; // eax
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *v13; // esi
  int v14; // edx
  int v15; // eax
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t **v16; // ecx
  int v17; // edi
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t *v18; // eax
  int i; // esi
  _BYTE v21[12]; // [esp+0h] [ebp-30h] BYREF
  int v22; // [esp+Ch] [ebp-24h]
  int v23; // [esp+10h] [ebp-20h]
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t **pReleasedPagesPrevs; // [esp+14h] [ebp-1Ch]
  unsigned __int8 **pPageBases; // [esp+18h] [ebp-18h]
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t *pPagePrev; // [esp+1Ch] [ebp-14h]
  unsigned int nFreed; // [esp+20h] [ebp-10h]
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t **pReleasedPages; // [esp+24h] [ebp-Ch]
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *v29; // [esp+28h] [ebp-8h]
  bool bIsCorrupt; // [esp+2Fh] [ebp-1h]
  int bIncrementala; // [esp+38h] [ebp+8h]

  v2 = 0;
  v3 = this;
  v29 = this;
  bIsCorrupt = false;
  nFreed = 0;
  if ( (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange(
         (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock,
         0x10000,
         0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock);
  }
  else
  {
    CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_writerId = GetCurrentThreadId();
  }
  m_pFirstPage = v3->m_pFirstPage;
  if ( m_pFirstPage != nullptr )
  {
    v5 = (4 * v3->m_nCommittedPages + 15) & 0xFFFFFFF0;
    v6 = alloca(v5);
    pReleasedPages = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t **)v21;
    v7 = alloca(v5);
    pReleasedPagesPrevs = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::PageStatus_t **)v21;
    v8 = alloca(v5);
    v9 = (unsigned __int8 **)v21;
    v10 = 0;
    pPageBases = (unsigned __int8 **)v21;
    pPagePrev = nullptr;
    v11 = (unsigned __int8 **)v21;
    v22 = 0;
    v23 = 0;
    do
    {
      if ( m_pFirstPage->m_nAllocated.m_value == 0 )
      {
        *(unsigned __int8 **)((char *)v11 + v10) = (unsigned __int8 *)m_pFirstPage;
        v12 = &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase[0x4000
                                                                                         * (((char *)m_pFirstPage
                                                                                           - (char *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData
                                                                                           - 24)
                                                                                          / 24)];
        *(unsigned __int8 **)((char *)v11 + v23) = (unsigned __int8 *)pPagePrev;
        *v11 = v12;
        v9 = pPageBases;
        ++v2;
        ++v11;
        if ( bIncremental )
          break;
        v10 = v22;
      }
      pPagePrev = m_pFirstPage;
      m_pFirstPage = m_pFirstPage->m_pNextPageInPool;
    }
    while ( m_pFirstPage != nullptr );
    if ( v2 != 0 )
    {
      v13 = v29;
      if ( !CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::RemovePagesFromFreeList(
              this: v29,
              pPages: v9,
              nPages: v2,
              bSortList: !bIncremental)
        && !`CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Compact'::`2'::bWarnedCorruption )
      {
        `CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Compact'::`2'::bWarnedCorruption = true;
        bIsCorrupt = true;
      }
      v13->m_nCommittedPages -= v2;
      v14 = v2 - 1;
      nFreed = v2 << 14;
      if ( v2 - 1 >= 0 )
      {
        v15 = (char *)pReleasedPagesPrevs - (char *)pReleasedPages;
        v16 = &pReleasedPages[v14];
        for ( bIncrementala = (char *)pReleasedPagesPrevs - (char *)pReleasedPages; ; v15 = bIncrementala )
        {
          v17 = *(int *)((char *)v16 + v15);
          v18 = *v16;
          if ( v17 != 0 )
          {
            *(_DWORD *)(v17 + 8) = v18->m_pNextPageInPool;
            v13 = v29;
          }
          else
          {
            v13->m_pFirstPage = v18->m_pNextPageInPool;
          }
          --v14;
          --v16;
          v18->m_pNextPageInPool = nullptr;
          *((_DWORD *)&v18->Next + 1) = 0;
          if ( v14 < 0 )
            break;
        }
      }
      for ( i = 0; i < v2; ++i )
        CTSListBase::Push(
          this: &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_FreePages,
          pNode: pReleasedPages[i]);
    }
    v3 = v29;
  }
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_writerId = 0;
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_Lock.m_lockInfo.m_i32 = 0;
  if ( bIsCorrupt )
    Warning(
      pMsgFormat: "***** HEAP IS CORRUPT (free compromised for block size %d,in %s heap, possible write after free *****)\n",
      v3->m_nBlockSize,
      "physical");
  return nFreed;
}

//------------------------------------------------------------------------------
// Address: 0x10008750
// Name: public: unsigned int CSmallBlockPool<class CStdMemAlloc::CVirtualAllocator>::Compact(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Compact(
        CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *this,
        bool bIncremental)
{
  int v2; // ebx
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *v3; // esi
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t *m_pFirstPage; // edi
  unsigned int v5; // esi
  void *v6; // esp
  void *v7; // esp
  void *v8; // esp
  unsigned __int8 **v9; // eax
  char *v10; // ecx
  unsigned __int8 **v11; // esi
  unsigned __int8 *v12; // eax
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *v13; // esi
  int v14; // edx
  int v15; // eax
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t **v16; // ecx
  int v17; // edi
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t *v18; // eax
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t **v19; // esi
  int v20; // eax
  int j; // edi
  TSLNodeBase_t *v22; // edx
  TSLNodeBase_t *v23; // edi
  TSLNodeBase_t *v24; // ebx
  TSLNodeBase_t *v25; // eax
  TSLNodeBase_t *v26; // esi
  TSLNodeBase_t *Next; // ebx
  TSLNodeBase_t *v28; // esi
  __int64 v30; // [esp-10h] [ebp-40h]
  __int64 v31; // [esp-10h] [ebp-40h]
  __int64 v32; // [esp-10h] [ebp-40h]
  __int64 v33; // [esp-10h] [ebp-40h]
  __int64 value64; // [esp-8h] [ebp-38h]
  _BYTE v35[12]; // [esp+0h] [ebp-30h] BYREF
  char *i; // [esp+Ch] [ebp-24h]
  int v37; // [esp+10h] [ebp-20h]
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t **pReleasedPagesPrevs; // [esp+14h] [ebp-1Ch]
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t *pPagePrev; // [esp+18h] [ebp-18h]
  unsigned int nFreed; // [esp+1Ch] [ebp-14h]
  unsigned __int8 **pPageBases; // [esp+20h] [ebp-10h]
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *v42; // [esp+24h] [ebp-Ch]
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t **pReleasedPages; // [esp+28h] [ebp-8h]
  bool bIsCorrupt; // [esp+2Fh] [ebp-1h]
  int bIncrementala; // [esp+38h] [ebp+8h]

  v2 = 0;
  v3 = this;
  v42 = this;
  bIsCorrupt = false;
  nFreed = 0;
  if ( (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange(
         (volatile signed __int32 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock,
         0x10000,
         0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock);
  }
  else
  {
    CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_writerId = GetCurrentThreadId();
  }
  m_pFirstPage = v3->m_pFirstPage;
  if ( m_pFirstPage != nullptr )
  {
    v5 = (4 * v3->m_nCommittedPages + 15) & 0xFFFFFFF0;
    v6 = alloca(v5);
    pReleasedPages = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t **)v35;
    v7 = alloca(v5);
    pReleasedPagesPrevs = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::PageStatus_t **)v35;
    v8 = alloca(v5);
    v9 = (unsigned __int8 **)v35;
    v10 = nullptr;
    pPageBases = (unsigned __int8 **)v35;
    pPagePrev = nullptr;
    v11 = (unsigned __int8 **)v35;
    i = nullptr;
    v37 = 0;
    do
    {
      if ( m_pFirstPage->m_nAllocated.m_value == 0 )
      {
        *(unsigned __int8 **)((char *)v11 + (_DWORD)v10) = (unsigned __int8 *)m_pFirstPage;
        v12 = &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase[0x10000
                                                                                     * (((char *)m_pFirstPage
                                                                                       - (char *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData
                                                                                       - 24)
                                                                                      / 24)];
        *(unsigned __int8 **)((char *)v11 + v37) = (unsigned __int8 *)pPagePrev;
        *v11 = v12;
        v9 = pPageBases;
        ++v2;
        ++v11;
        if ( bIncremental )
          break;
        v10 = i;
      }
      pPagePrev = m_pFirstPage;
      m_pFirstPage = m_pFirstPage->m_pNextPageInPool;
    }
    while ( m_pFirstPage != nullptr );
    if ( v2 != 0 )
    {
      v13 = v42;
      if ( !CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::RemovePagesFromFreeList(
              this: v42,
              pPages: v9,
              nPages: v2,
              bSortList: !bIncremental)
        && !`CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Compact'::`2'::bWarnedCorruption )
      {
        `CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Compact'::`2'::bWarnedCorruption = true;
        bIsCorrupt = true;
      }
      v13->m_nCommittedPages -= v2;
      v14 = v2 - 1;
      nFreed = v2 << 16;
      if ( v2 - 1 >= 0 )
      {
        v15 = (char *)pReleasedPagesPrevs - (char *)pReleasedPages;
        v16 = &pReleasedPages[v14];
        for ( i = (char *)((char *)pReleasedPagesPrevs - (char *)pReleasedPages); ; v15 = (int)i )
        {
          v17 = *(int *)((char *)v16 + v15);
          v18 = *v16;
          if ( v17 != 0 )
          {
            *(_DWORD *)(v17 + 8) = v18->m_pNextPageInPool;
            v13 = v42;
          }
          else
          {
            v13->m_pFirstPage = v18->m_pNextPageInPool;
          }
          --v14;
          --v16;
          v18->m_pNextPageInPool = nullptr;
          *((_DWORD *)&v18->Next + 1) = 0;
          if ( v14 < 0 )
            break;
        }
      }
      v19 = pReleasedPages;
      v20 = (bIncremental ? 32 : 4)
          - CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value.Depth;
      if ( v20 > 0 )
      {
        if ( v20 >= v2 )
          v20 = v2;
        for ( j = v20; j != 0; --j )
        {
          v22 = v19[--v2];
          CTSListBase::Push(
            this: &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages,
            pNode: v22);
        }
      }
      if ( v2 != 0 )
      {
        v23 = CTSListBase::Detach(this: &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages);
        if ( v2 > 0 )
        {
          i = (char *)((char *)pPageBases - (char *)v19);
          for ( bIncrementala = v2; bIncrementala != 0; --bIncrementala )
          {
            v24 = *v19;
            _InterlockedExchange(&(*v19)->m_nAllocated.m_value, -1);
            VirtualFree(lpAddress: *(LPVOID *)((char *)v19 + (_DWORD)i), dwSize: 0x10000u, dwFreeType: 0x4000u);
            CTSListBase::Push(
              this: &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages,
              pNode: v24);
            ++v19;
          }
        }
        v25 = nullptr;
        v26 = v23;
        if ( v23 != nullptr )
        {
          while ( *((_DWORD *)&v26[1].Next + 1) != -1 )
          {
            v25 = v26;
            v26 = v26->Next;
            if ( v26 == nullptr )
              goto LABEL_42;
          }
          if ( v25 != nullptr )
            v25->Next = nullptr;
          else
            v23 = nullptr;
          if ( v26 != nullptr )
          {
            do
            {
              Next = v26->Next;
              value64 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value64;
              HIDWORD(v30) = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value32.DepthAndSequence
                           + 65537;
              LODWORD(v30) = v26;
              v26->Next = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value.Next;
              if ( !ThreadInterlockedAssignIf64(
                      pDest: (volatile __int64 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages,
                      value: v30,
                      comperand: value64) )
              {
                do
                {
                  _mm_pause();
                  value64 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value64;
                  HIDWORD(v31) = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value32.DepthAndSequence
                               + 65537;
                  LODWORD(v31) = v26;
                  v26->Next = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value.Next;
                }
                while ( !ThreadInterlockedAssignIf64(
                           pDest: (volatile __int64 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages,
                           value: v31,
                           comperand: value64) );
              }
              v26 = Next;
            }
            while ( Next != nullptr );
          }
LABEL_42:
          if ( v23 != nullptr )
          {
            do
            {
              v28 = v23->Next;
              value64 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value64;
              HIDWORD(v32) = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value32.DepthAndSequence
                           + 65537;
              LODWORD(v32) = v23;
              v23->Next = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value.Next;
              if ( !ThreadInterlockedAssignIf64(
                      pDest: (volatile __int64 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages,
                      value: v32,
                      comperand: value64) )
              {
                do
                {
                  _mm_pause();
                  value64 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value64;
                  HIDWORD(v33) = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value32.DepthAndSequence
                               + 65537;
                  LODWORD(v33) = v23;
                  v23->Next = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages.m_Head.value.Next;
                }
                while ( !ThreadInterlockedAssignIf64(
                           pDest: (volatile __int64 *)&CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages,
                           value: v33,
                           comperand: value64) );
              }
              v23 = v28;
            }
            while ( v28 != nullptr );
          }
        }
      }
    }
    v3 = v42;
  }
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_writerId = 0;
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_Lock.m_lockInfo.m_i32 = 0;
  if ( bIsCorrupt )
    Warning(
      pMsgFormat: "***** HEAP IS CORRUPT (free compromised for block size %d,in %s heap, possible write after free *****)\n",
      v3->m_nBlockSize,
      "virtual");
  return nFreed;
}

//------------------------------------------------------------------------------
// Address: 0x10008AB0
// Name: public: virtual void __near * CStdMemAlloc::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStdMemAlloc::Alloc(CStdMemAlloc *this, unsigned int nSize)
{
  unsigned int v4; // eax
  char *v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  char *v9; // ebx
  char *v11; // esi
  void **nSizea; // [esp+14h] [ebp+8h]

  if ( nSize > 0x800 )
  {
LABEL_16:
    nSizea = &g_AllocRegions[nSize < 0x40000];
    v9 = (char *)mspace_malloc(msp: *nSizea, bytes: nSize);
    if ( v9 != nullptr || (this->CompactHeap(this), (v9 = (char *)mspace_malloc(msp: *nSizea, bytes: nSize)) != nullptr) )
    {
      if ( g_bInitMemory )
        DoApplyMemoryInitializations(pMem: v9, nSize);
      return v9;
    }
    else
    {
      CStdMemAlloc::OutOfMemory(this, nBytesAttempted: nSize);
      return nullptr;
    }
  }
  v4 = nSize;
  if ( nSize == 0 )
    v4 = 1;
  v5 = (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(this: this->m_PrimarySBH.m_PoolLookup[(v4 - 1) >> 2]);
  if ( v5 == nullptr )
  {
    v6 = nSize;
    if ( nSize == 0 )
      v6 = 1;
    v5 = (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Alloc(this: this->m_FallbackSBH.m_PoolLookup[(v6 - 1) >> 2]);
    if ( v5 == nullptr )
    {
      this->m_pfnFailHandler(a1: nSize);
      this->CompactHeap(this);
      v7 = nSize;
      if ( nSize == 0 )
        v7 = 1;
      v5 = (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(this: this->m_PrimarySBH.m_PoolLookup[(v7 - 1) >> 2]);
      if ( v5 == nullptr )
      {
        v8 = nSize;
        if ( nSize == 0 )
          v8 = 1;
        v5 = (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Alloc(this: this->m_FallbackSBH.m_PoolLookup[(v8 - 1) >> 2]);
        if ( v5 == nullptr )
        {
          this->m_pfnFailHandler(a1: nSize);
          if ( `CStdMemAlloc::InternalAlloc'::`16'::__executeCount < 1 )
          {
            ++`CStdMemAlloc::InternalAlloc'::`16'::__executeCount;
            DevWarning(pMsgFormat: "\n\nDRASTIC MEMORY OVERFLOW: Fell out of small block heap!\n\n\n");
          }
          goto LABEL_16;
        }
      }
    }
  }
  v11 = v5;
  if ( g_bInitMemory )
    DoApplyMemoryInitializations(pMem: v5, nSize);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10008C20
// Name: public: virtual void __near * CStdMemAlloc::Realloc(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CStdMemAlloc::Realloc(CStdMemAlloc *this, unsigned __int8 *pMem, unsigned int nSize)
{
  unsigned __int8 *m_pBase; // edx
  CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1> > *p_m_PrimarySBH; // ecx
  unsigned __int8 *v7; // edx
  void *v8; // ebx

  if ( pMem == nullptr )
    return (unsigned __int8 *)this->RegionAlloc_2(this, a2: 0, a3: nSize);
  m_pBase = this->m_PrimarySBH.m_pSharedData->m_pBase;
  p_m_PrimarySBH = &this->m_PrimarySBH;
  if ( pMem >= m_pBase && (unsigned int)((pMem - m_pBase) / 0x4000) < 0xC00 )
    return CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Realloc(this: p_m_PrimarySBH, p: pMem, nBytes: nSize);
  v7 = this->m_FallbackSBH.m_pSharedData->m_pBase;
  if ( pMem >= v7 && (unsigned int)((pMem - v7) / 0x10000) < 0x200 )
    return CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Realloc(this: &this->m_FallbackSBH, p: pMem, nBytes: nSize);
  v8 = dlrealloc(oldmem: pMem, bytes: nSize);
  if ( v8 == nullptr )
  {
    this->CompactHeap(this);
    v8 = dlrealloc(oldmem: pMem, bytes: nSize);
    if ( v8 == nullptr )
      CStdMemAlloc::OutOfMemory(this, nBytesAttempted: nSize);
  }
  return (unsigned __int8 *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x10008D10
// Name: public: virtual void CStdMemAlloc::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::Free(CStdMemAlloc *this, TSLNodeBase_t *pMem)
{
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::SharedData_t *m_pSharedData; // ebx
  unsigned __int8 *m_pBase; // eax
  unsigned int v4; // esi
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *v5; // ecx
  unsigned __int8 *v6; // edx
  CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *p_m_FallbackSBH; // ecx

  if ( pMem != nullptr )
  {
    m_pSharedData = this->m_PrimarySBH.m_pSharedData;
    m_pBase = m_pSharedData->m_pBase;
    if ( pMem < (TSLNodeBase_t *)m_pBase || (unsigned int)(((char *)pMem - (char *)m_pBase) / 0x4000) >= 0xC00 )
    {
      v6 = this->m_FallbackSBH.m_pSharedData->m_pBase;
      p_m_FallbackSBH = &this->m_FallbackSBH;
      if ( pMem < (TSLNodeBase_t *)v6 || (unsigned int)(((char *)pMem - (char *)v6) / 0x10000) >= 0x200 )
        dlfree(mem: pMem);
      else
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Free(this: p_m_FallbackSBH, p: pMem);
    }
    else
    {
      v4 = (unsigned int)((char *)pMem - (char *)m_pBase) >> 14;
      if ( v4 < 0xC00
        && (v5 = *((CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > **)&m_pSharedData->m_PageStatus[v4].Next + 1)) != nullptr )
      {
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Free(this: v5, p: pMem);
      }
      else if ( Plat_IsInDebugSession() )
      {
        __debugbreak();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008DE0
// Name: public: virtual void __near * CStdMemAlloc::Alloc(unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStdMemAlloc::Alloc(CStdMemAlloc *this, unsigned int nSize, const char *pFileName, int nLine)
{
  unsigned int v6; // eax
  char *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  char *v11; // ebx
  char *v13; // esi
  void **nSizea; // [esp+14h] [ebp+8h]

  if ( nSize > 0x800 )
  {
LABEL_16:
    nSizea = &g_AllocRegions[nSize < 0x40000];
    v11 = (char *)mspace_malloc(msp: *nSizea, bytes: nSize);
    if ( v11 != nullptr
      || (this->CompactHeap(this), (v11 = (char *)mspace_malloc(msp: *nSizea, bytes: nSize)) != nullptr) )
    {
      if ( g_bInitMemory )
        DoApplyMemoryInitializations(pMem: v11, nSize);
      return v11;
    }
    else
    {
      CStdMemAlloc::OutOfMemory(this, nBytesAttempted: nSize);
      return nullptr;
    }
  }
  v6 = nSize;
  if ( nSize == 0 )
    v6 = 1;
  v7 = (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(this: this->m_PrimarySBH.m_PoolLookup[(v6 - 1) >> 2]);
  if ( v7 == nullptr )
  {
    v8 = nSize;
    if ( nSize == 0 )
      v8 = 1;
    v7 = (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Alloc(this: this->m_FallbackSBH.m_PoolLookup[(v8 - 1) >> 2]);
    if ( v7 == nullptr )
    {
      this->m_pfnFailHandler(a1: nSize);
      this->CompactHeap(this);
      v9 = nSize;
      if ( nSize == 0 )
        v9 = 1;
      v7 = (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(this: this->m_PrimarySBH.m_PoolLookup[(v9 - 1) >> 2]);
      if ( v7 == nullptr )
      {
        v10 = nSize;
        if ( nSize == 0 )
          v10 = 1;
        v7 = (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Alloc(this: this->m_FallbackSBH.m_PoolLookup[(v10 - 1) >> 2]);
        if ( v7 == nullptr )
        {
          this->m_pfnFailHandler(a1: nSize);
          if ( `CStdMemAlloc::InternalAlloc'::`16'::__executeCount < 1 )
          {
            ++`CStdMemAlloc::InternalAlloc'::`16'::__executeCount;
            DevWarning(pMsgFormat: "\n\nDRASTIC MEMORY OVERFLOW: Fell out of small block heap!\n\n\n");
          }
          goto LABEL_16;
        }
      }
    }
  }
  v13 = v7;
  if ( g_bInitMemory )
    DoApplyMemoryInitializations(pMem: v7, nSize);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x10008F50
// Name: public: virtual void __near * CStdMemAlloc::Realloc(void __near *,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CStdMemAlloc::Realloc(
        CStdMemAlloc *this,
        unsigned __int8 *pMem,
        unsigned int nSize,
        const char *pFileName,
        int nLine)
{
  unsigned __int8 *m_pBase; // edx
  CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1> > *p_m_PrimarySBH; // ecx
  unsigned __int8 *v9; // edx
  void *v10; // ebx

  if ( pMem == nullptr )
    return (unsigned __int8 *)this->RegionAlloc_2(this, a2: 0, a3: nSize);
  m_pBase = this->m_PrimarySBH.m_pSharedData->m_pBase;
  p_m_PrimarySBH = &this->m_PrimarySBH;
  if ( pMem >= m_pBase && (unsigned int)((pMem - m_pBase) / 0x4000) < 0xC00 )
    return CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Realloc(this: p_m_PrimarySBH, p: pMem, nBytes: nSize);
  v9 = this->m_FallbackSBH.m_pSharedData->m_pBase;
  if ( pMem >= v9 && (unsigned int)((pMem - v9) / 0x10000) < 0x200 )
    return CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Realloc(this: &this->m_FallbackSBH, p: pMem, nBytes: nSize);
  v10 = dlrealloc(oldmem: pMem, bytes: nSize);
  if ( v10 == nullptr )
  {
    this->CompactHeap(this);
    v10 = dlrealloc(oldmem: pMem, bytes: nSize);
    if ( v10 == nullptr )
      CStdMemAlloc::OutOfMemory(this, nBytesAttempted: nSize);
  }
  return (unsigned __int8 *)v10;
}

//------------------------------------------------------------------------------
// Address: 0x10009040
// Name: public: virtual void CStdMemAlloc::Free(void __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::Free(CStdMemAlloc *this, TSLNodeBase_t *pMem, const char *pFileName, int nLine)
{
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::SharedData_t *m_pSharedData; // ebx
  unsigned __int8 *m_pBase; // eax
  unsigned int v6; // esi
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *v7; // ecx
  unsigned __int8 *v8; // edx
  CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *p_m_FallbackSBH; // ecx

  if ( pMem != nullptr )
  {
    m_pSharedData = this->m_PrimarySBH.m_pSharedData;
    m_pBase = m_pSharedData->m_pBase;
    if ( pMem < (TSLNodeBase_t *)m_pBase || (unsigned int)(((char *)pMem - (char *)m_pBase) / 0x4000) >= 0xC00 )
    {
      v8 = this->m_FallbackSBH.m_pSharedData->m_pBase;
      p_m_FallbackSBH = &this->m_FallbackSBH;
      if ( pMem < (TSLNodeBase_t *)v8 || (unsigned int)(((char *)pMem - (char *)v8) / 0x10000) >= 0x200 )
        dlfree(mem: pMem);
      else
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Free(this: p_m_FallbackSBH, p: pMem);
    }
    else
    {
      v6 = (unsigned int)((char *)pMem - (char *)m_pBase) >> 14;
      if ( v6 < 0xC00
        && (v7 = *((CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > **)&m_pSharedData->m_PageStatus[v6].Next + 1)) != nullptr )
      {
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Free(this: v7, p: pMem);
      }
      else if ( Plat_IsInDebugSession() )
      {
        __debugbreak();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009110
// Name: public: virtual void __near * CStdMemAlloc::RegionAlloc(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStdMemAlloc::RegionAlloc(CStdMemAlloc *this, int region, unsigned int nSize)
{
  unsigned int v5; // eax
  char *v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  char *v10; // ebx
  char *v12; // esi
  void **nSizea; // [esp+18h] [ebp+Ch]

  if ( nSize > 0x800 )
  {
LABEL_16:
    nSizea = &g_AllocRegions[nSize < 0x40000];
    v10 = (char *)mspace_malloc(msp: *nSizea, bytes: nSize);
    if ( v10 != nullptr
      || (this->CompactHeap(this), (v10 = (char *)mspace_malloc(msp: *nSizea, bytes: nSize)) != nullptr) )
    {
      if ( g_bInitMemory )
        DoApplyMemoryInitializations(pMem: v10, nSize);
      return v10;
    }
    else
    {
      CStdMemAlloc::OutOfMemory(this, nBytesAttempted: nSize);
      return nullptr;
    }
  }
  v5 = nSize;
  if ( nSize == 0 )
    v5 = 1;
  v6 = (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(this: this->m_PrimarySBH.m_PoolLookup[(v5 - 1) >> 2]);
  if ( v6 == nullptr )
  {
    v7 = nSize;
    if ( nSize == 0 )
      v7 = 1;
    v6 = (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Alloc(this: this->m_FallbackSBH.m_PoolLookup[(v7 - 1) >> 2]);
    if ( v6 == nullptr )
    {
      this->m_pfnFailHandler(a1: nSize);
      this->CompactHeap(this);
      v8 = nSize;
      if ( nSize == 0 )
        v8 = 1;
      v6 = (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(this: this->m_PrimarySBH.m_PoolLookup[(v8 - 1) >> 2]);
      if ( v6 == nullptr )
      {
        v9 = nSize;
        if ( nSize == 0 )
          v9 = 1;
        v6 = (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Alloc(this: this->m_FallbackSBH.m_PoolLookup[(v9 - 1) >> 2]);
        if ( v6 == nullptr )
        {
          this->m_pfnFailHandler(a1: nSize);
          if ( `CStdMemAlloc::InternalAlloc'::`16'::__executeCount < 1 )
          {
            ++`CStdMemAlloc::InternalAlloc'::`16'::__executeCount;
            DevWarning(pMsgFormat: "\n\nDRASTIC MEMORY OVERFLOW: Fell out of small block heap!\n\n\n");
          }
          goto LABEL_16;
        }
      }
    }
  }
  v12 = v6;
  if ( g_bInitMemory )
    DoApplyMemoryInitializations(pMem: v6, nSize);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10009280
// Name: public: virtual void __near * CStdMemAlloc::RegionAlloc(int,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStdMemAlloc::RegionAlloc(
        CStdMemAlloc *this,
        int region,
        unsigned int nSize,
        const char *pFileName,
        int nLine)
{
  unsigned int v7; // eax
  char *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  char *v12; // ebx
  char *v14; // esi
  void **nSizea; // [esp+18h] [ebp+Ch]

  if ( nSize > 0x800 )
  {
LABEL_16:
    nSizea = &g_AllocRegions[nSize < 0x40000];
    v12 = (char *)mspace_malloc(msp: *nSizea, bytes: nSize);
    if ( v12 != nullptr
      || (this->CompactHeap(this), (v12 = (char *)mspace_malloc(msp: *nSizea, bytes: nSize)) != nullptr) )
    {
      if ( g_bInitMemory )
        DoApplyMemoryInitializations(pMem: v12, nSize);
      return v12;
    }
    else
    {
      CStdMemAlloc::OutOfMemory(this, nBytesAttempted: nSize);
      return nullptr;
    }
  }
  v7 = nSize;
  if ( nSize == 0 )
    v7 = 1;
  v8 = (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(this: this->m_PrimarySBH.m_PoolLookup[(v7 - 1) >> 2]);
  if ( v8 == nullptr )
  {
    v9 = nSize;
    if ( nSize == 0 )
      v9 = 1;
    v8 = (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Alloc(this: this->m_FallbackSBH.m_PoolLookup[(v9 - 1) >> 2]);
    if ( v8 == nullptr )
    {
      this->m_pfnFailHandler(a1: nSize);
      this->CompactHeap(this);
      v10 = nSize;
      if ( nSize == 0 )
        v10 = 1;
      v8 = (char *)CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Alloc(this: this->m_PrimarySBH.m_PoolLookup[(v10 - 1) >> 2]);
      if ( v8 == nullptr )
      {
        v11 = nSize;
        if ( nSize == 0 )
          v11 = 1;
        v8 = (char *)CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Alloc(this: this->m_FallbackSBH.m_PoolLookup[(v11 - 1) >> 2]);
        if ( v8 == nullptr )
        {
          this->m_pfnFailHandler(a1: nSize);
          if ( `CStdMemAlloc::InternalAlloc'::`16'::__executeCount < 1 )
          {
            ++`CStdMemAlloc::InternalAlloc'::`16'::__executeCount;
            DevWarning(pMsgFormat: "\n\nDRASTIC MEMORY OVERFLOW: Fell out of small block heap!\n\n\n");
          }
          goto LABEL_16;
        }
      }
    }
  }
  v14 = v8;
  if ( g_bInitMemory )
    DoApplyMemoryInitializations(pMem: v8, nSize);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x100093F0
// Name: public: virtual int CStdMemAlloc::CrtCheckMemory(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStdMemAlloc::CrtCheckMemory(CStdMemAlloc *this)
{
  bool v1; // bl
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *m_Pools; // esi
  int i; // edi
  bool v4; // bl
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *v5; // esi
  int j; // edi

  v1 = true;
  m_Pools = this->m_PrimarySBH.m_Pools;
  for ( i = 42; i != 0; --i )
    v1 = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Validate(this: m_Pools++) && v1;
  if ( !v1 && _executeCount_0 < 1 )
  {
    ++_executeCount_0;
    Msg(pMsgFormat: "Small block heap is corrupt (primary)\n ");
  }
  v4 = true;
  v5 = this->m_FallbackSBH.m_Pools;
  for ( j = 42; j != 0; --j )
    v4 = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Validate(this: v5++) && v4;
  if ( v4 )
    return 1;
  if ( _executeCount < 1 )
  {
    ++_executeCount;
    Msg(pMsgFormat: "Small block heap is corrupt (fallback)\n ");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100094B0
// Name: public: virtual void CStdMemAlloc::DumpStatsFileBase(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::DumpStatsFileBase(CStdMemAlloc *this, const char *pchFileBase)
{
  _iobuf *v3; // eax
  _iobuf *v4; // esi
  char filename[512]; // [esp+8h] [ebp-200h] BYREF

  _snprintf(string: filename, count: 0x1FFu, format: "%s.txt", pchFileBase);
  filename[511] = 0;
  v3 = fopen(file: filename, mode: "wt");
  v4 = v3;
  if ( v3 != nullptr )
    fprintf(str: v3, format: "Fixed Page SBH:\n");
  else
    Msg(pMsgFormat: "Fixed Page SBH:\n");
  CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::DumpStats(
    this: &this->m_PrimarySBH,
    pszTag: "Fixed Page SBH",
    pFile: v4);
  if ( v4 != nullptr )
    fprintf(str: v4, format: "\nFallback SBH:\n");
  else
    Msg(pMsgFormat: "\nFallback SBH:\n");
  CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::DumpStats(
    this: &this->m_FallbackSBH,
    pszTag: "Fallback SBH",
    pFile: v4);
  heapstats_internal(pFile: v4);
  if ( v4 != nullptr )
    fclose(stream: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10009570
// Name: public: CSmallBlockHeap<class CStdMemAlloc::CFixedAllocator<48,1>>::CSmallBlockHeap<class CStdMemAlloc::CFixedAllocator<48,1>>(void)
// Source: json
//------------------------------------------------------------------------------
CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1> > *__thiscall CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>(
        CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1> > *this)
{
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *m_Pools; // ebx
  int i; // edi
  CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1> > *result; // eax
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *v5; // edi
  CInterlockedPtr<unsigned char> *p_m_pNextAlloc; // ecx
  int v7; // esi
  unsigned int v8; // ebx
  int v9; // edx
  CInterlockedPtr<unsigned char> *v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // edx
  int v13; // edx
  CInterlockedPtr<unsigned char> *v14; // ecx
  unsigned __int8 *v15; // eax
  int v16; // edx
  CInterlockedPtr<unsigned char> *v17; // ecx
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // edx
  int v20; // edx
  CInterlockedPtr<unsigned char> *v21; // ecx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // edx
  int v24; // ecx
  CInterlockedPtr<unsigned char> *v25; // esi
  unsigned __int8 *v26; // eax
  unsigned __int8 *v27; // ecx
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > **v28; // edx
  int v29; // [esp+Ch] [ebp-10h]
  int v30; // [esp+Ch] [ebp-10h]
  CInterlockedPtr<unsigned char> *v31; // [esp+Ch] [ebp-10h]
  int v32; // [esp+Ch] [ebp-10h]
  int v33; // [esp+Ch] [ebp-10h]
  int v34; // [esp+Ch] [ebp-10h]
  CInterlockedPtr<unsigned char> *v35; // [esp+10h] [ebp-Ch]
  CInterlockedPtr<unsigned char> *v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+10h] [ebp-Ch]
  CInterlockedPtr<unsigned char> *v38; // [esp+10h] [ebp-Ch]
  CInterlockedPtr<unsigned char> *v39; // [esp+10h] [ebp-Ch]
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > **v40; // [esp+10h] [ebp-Ch]
  int iCurPool; // [esp+18h] [ebp-4h]

  m_Pools = this->m_Pools;
  for ( i = 41; i >= 0; --i )
  {
    if ( ((unsigned __int8)m_Pools & 7) != 0 )
    {
      Error(pMsgFormat: "CTSListBase: Misaligned list\n");
      __debugbreak();
    }
    m_Pools->m_FreeList.m_Head.value.Next = nullptr;
    m_Pools->m_FreeList.m_Head.value32.DepthAndSequence = 0;
    m_Pools->m_pNextAlloc.m_value = nullptr;
    m_Pools->m_CommitMutex.m_ownerID = 0;
    m_Pools->m_CommitMutex.m_depth = 0;
    m_Pools->m_nBlockSize = 0;
    m_Pools->m_nCommittedPages = 0;
    m_Pools->m_pFirstPage = nullptr;
    ++m_Pools;
  }
  result = this;
  v5 = nullptr;
  this->m_pSharedData = &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData;
  p_m_pNextAlloc = &this->m_Pools[0].m_pNextAlloc;
  v7 = 0;
  v8 = 0;
  iCurPool = 0;
  v35 = &this->m_Pools[0].m_pNextAlloc;
  do
  {
    v29 = v7 + 1;
    if ( (v7 + 1) % 2 == 1 )
    {
      v8 += 8;
      v5 = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *)&p_m_pNextAlloc[-2];
      if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase == nullptr )
      {
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase = (unsigned __int8 *)VirtualAlloc(lpAddress: nullptr, dwSize: 0x3000000u, flAllocationType: 0x1000u, flProtect: 4u);
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pLimit = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase
                                                                                     + 50331648;
        p_m_pNextAlloc = v35;
        CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase;
        result = this;
      }
      if ( (v8 & 7) != 0 || v8 < 8 )
        __debugbreak();
      p_m_pNextAlloc[2].m_value = (unsigned __int8 *volatile)v8;
      _InterlockedExchange((volatile __int32 *)p_m_pNextAlloc, 0);
      ++iCurPool;
      v35[3].m_value = nullptr;
      p_m_pNextAlloc = v35 + 8;
      v35 += 8;
    }
    result->m_PoolLookup[v7++] = v5;
  }
  while ( v29 < 32 );
  if ( v29 < 64 )
  {
    v9 = v29 + 1;
    v10 = &result->m_Pools[iCurPool].m_pNextAlloc;
    v30 = v29 + 1;
    v36 = v10;
    do
    {
      if ( v9 % 4 == 1 )
      {
        v8 += 16;
        v5 = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *)&v10[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase == nullptr )
        {
          v11 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x3000000u,
                                     flAllocationType: 0x1000u,
                                     flProtect: 4u);
          v10 = v36;
          v12 = v11 + 50331648;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase = v11;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock = v11;
          result = this;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pLimit = v12;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v10[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v10, 0);
        ++iCurPool;
        v36[3].m_value = nullptr;
        v10 = v36 + 8;
        v36 += 8;
      }
      v9 = v30 + 1;
      result->m_PoolLookup[v7++] = v5;
      v30 = v9;
    }
    while ( v9 < 65 );
  }
  if ( v7 < 128 )
  {
    v13 = v7 + 1;
    v14 = &result->m_Pools[iCurPool].m_pNextAlloc;
    v37 = v7 + 1;
    v31 = v14;
    do
    {
      if ( v13 % 8 == 1 )
      {
        v8 += 32;
        v5 = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *)&v14[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase == nullptr )
        {
          v15 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x3000000u,
                                     flAllocationType: 0x1000u,
                                     flProtect: 4u);
          v14 = v31;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase = v15;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pLimit = v15 + 50331648;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock = v15;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v14[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v14, 0);
        ++iCurPool;
        result = this;
        v14[3].m_value = nullptr;
        v14 += 8;
        v31 = v14;
      }
      v13 = v37 + 1;
      result->m_PoolLookup[v7++] = v5;
      v37 = v13;
    }
    while ( v13 < 129 );
  }
  if ( v7 < 192 )
  {
    v16 = v7 + 1;
    v17 = &result->m_Pools[iCurPool].m_pNextAlloc;
    v32 = v7 + 1;
    v38 = v17;
    do
    {
      if ( v16 % 16 == 1 )
      {
        v8 += 64;
        v5 = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *)&v17[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase == nullptr )
        {
          v18 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x3000000u,
                                     flAllocationType: 0x1000u,
                                     flProtect: 4u);
          v17 = v38;
          v19 = v18 + 50331648;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase = v18;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock = v18;
          result = this;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pLimit = v19;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v17[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v17, 0);
        ++iCurPool;
        v38[3].m_value = nullptr;
        v17 = v38 + 8;
        v38 += 8;
      }
      v16 = v32 + 1;
      result->m_PoolLookup[v7++] = v5;
      v32 = v16;
    }
    while ( v16 < 193 );
  }
  if ( v7 < 256 )
  {
    v20 = v7 + 1;
    v21 = &result->m_Pools[iCurPool].m_pNextAlloc;
    v33 = v7 + 1;
    v39 = v21;
    do
    {
      if ( v20 % 32 == 1 )
      {
        v8 += 128;
        v5 = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *)&v21[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase == nullptr )
        {
          v22 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x3000000u,
                                     flAllocationType: 0x1000u,
                                     flProtect: 4u);
          v21 = v39;
          v23 = v22 + 50331648;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase = v22;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock = v22;
          result = this;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pLimit = v23;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v21[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v21, 0);
        ++iCurPool;
        v39[3].m_value = nullptr;
        v21 = v39 + 8;
        v39 += 8;
      }
      v20 = v33 + 1;
      result->m_PoolLookup[v7++] = v5;
      v33 = v20;
    }
    while ( v20 < 257 );
  }
  if ( v7 < 512 )
  {
    v24 = v7 + 1;
    v34 = v7 + 1;
    v40 = &result->m_PoolLookup[v7];
    v25 = &result->m_Pools[iCurPool].m_pNextAlloc;
    do
    {
      if ( v24 % 64 == 1 )
      {
        v8 += 256;
        v5 = (CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *)&v25[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase == nullptr )
        {
          v26 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x3000000u,
                                     flAllocationType: 0x1000u,
                                     flProtect: 4u);
          v27 = v26 + 50331648;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pBase = v26;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pNextBlock = v26;
          result = this;
          CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_pLimit = v27;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v25[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v25, 0);
        v24 = v34;
        v25[3].m_value = nullptr;
        v25 += 8;
      }
      v28 = v40++;
      ++v24;
      *v28 = v5;
      v34 = v24;
    }
    while ( v24 < 513 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100099F0
// Name: public: unsigned int CSmallBlockHeap<class CStdMemAlloc::CFixedAllocator<48,1>>::Compact(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Compact(
        CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1> > *this,
        bool bIncremental)
{
  int v2; // edi
  int v4; // esi
  unsigned int result; // eax
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *m_Pools; // esi
  int i; // ebx

  v2 = 0;
  if ( bIncremental )
  {
    ++`CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Compact'::`5'::iLastIncremental;
    while ( 1 )
    {
      v4 = (v2 + `CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Compact'::`5'::iLastIncremental) % 42;
      result = CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Compact(this: &this->m_Pools[v4], bIncremental);
      if ( result != 0 )
        break;
      if ( ++v2 >= 42 )
        return result;
    }
    `CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Compact'::`5'::iLastIncremental = v4;
  }
  else
  {
    m_Pools = this->m_Pools;
    for ( i = 42; i != 0; --i )
      v2 += CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Compact(this: m_Pools++, bIncremental: false);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009A70
// Name: public: CSmallBlockHeap<class CStdMemAlloc::CVirtualAllocator>::CSmallBlockHeap<class CStdMemAlloc::CVirtualAllocator>(void)
// Source: json
//------------------------------------------------------------------------------
CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *__thiscall CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>(
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *this)
{
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *m_Pools; // ebx
  int i; // edi
  CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *result; // eax
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *v5; // edi
  CInterlockedPtr<unsigned char> *p_m_pNextAlloc; // ecx
  int v7; // esi
  unsigned int v8; // ebx
  int v9; // edx
  CInterlockedPtr<unsigned char> *v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // edx
  int v13; // edx
  CInterlockedPtr<unsigned char> *v14; // ecx
  unsigned __int8 *v15; // eax
  int v16; // edx
  CInterlockedPtr<unsigned char> *v17; // ecx
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // edx
  int v20; // edx
  CInterlockedPtr<unsigned char> *v21; // ecx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // edx
  int v24; // ecx
  CInterlockedPtr<unsigned char> *v25; // esi
  unsigned __int8 *v26; // eax
  unsigned __int8 *v27; // ecx
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> **v28; // edx
  int v29; // [esp+Ch] [ebp-10h]
  int v30; // [esp+Ch] [ebp-10h]
  CInterlockedPtr<unsigned char> *v31; // [esp+Ch] [ebp-10h]
  int v32; // [esp+Ch] [ebp-10h]
  int v33; // [esp+Ch] [ebp-10h]
  int v34; // [esp+Ch] [ebp-10h]
  CInterlockedPtr<unsigned char> *v35; // [esp+10h] [ebp-Ch]
  CInterlockedPtr<unsigned char> *v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+10h] [ebp-Ch]
  CInterlockedPtr<unsigned char> *v38; // [esp+10h] [ebp-Ch]
  CInterlockedPtr<unsigned char> *v39; // [esp+10h] [ebp-Ch]
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> **v40; // [esp+10h] [ebp-Ch]
  int iCurPool; // [esp+18h] [ebp-4h]

  m_Pools = this->m_Pools;
  for ( i = 41; i >= 0; --i )
  {
    if ( ((unsigned __int8)m_Pools & 7) != 0 )
    {
      Error(pMsgFormat: "CTSListBase: Misaligned list\n");
      __debugbreak();
    }
    m_Pools->m_FreeList.m_Head.value.Next = nullptr;
    m_Pools->m_FreeList.m_Head.value32.DepthAndSequence = 0;
    m_Pools->m_pNextAlloc.m_value = nullptr;
    m_Pools->m_CommitMutex.m_ownerID = 0;
    m_Pools->m_CommitMutex.m_depth = 0;
    m_Pools->m_nBlockSize = 0;
    m_Pools->m_nCommittedPages = 0;
    m_Pools->m_pFirstPage = nullptr;
    ++m_Pools;
  }
  result = this;
  v5 = nullptr;
  this->m_pSharedData = &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData;
  p_m_pNextAlloc = &this->m_Pools[0].m_pNextAlloc;
  v7 = 0;
  v8 = 0;
  iCurPool = 0;
  v35 = &this->m_Pools[0].m_pNextAlloc;
  do
  {
    v29 = v7 + 1;
    if ( (v7 + 1) % 2 == 1 )
    {
      v8 += 8;
      v5 = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *)&p_m_pNextAlloc[-2];
      if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase == nullptr )
      {
        CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase = (unsigned __int8 *)VirtualAlloc(lpAddress: nullptr, dwSize: 0x2000000u, flAllocationType: 0x2000u, flProtect: 1u);
        CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pLimit = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase
                                                                                 + 0x2000000;
        p_m_pNextAlloc = v35;
        CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase;
        result = this;
      }
      if ( (v8 & 7) != 0 || v8 < 8 )
        __debugbreak();
      p_m_pNextAlloc[2].m_value = (unsigned __int8 *volatile)v8;
      _InterlockedExchange((volatile __int32 *)p_m_pNextAlloc, 0);
      ++iCurPool;
      v35[3].m_value = nullptr;
      p_m_pNextAlloc = v35 + 8;
      v35 += 8;
    }
    result->m_PoolLookup[v7++] = v5;
  }
  while ( v29 < 32 );
  if ( v29 < 64 )
  {
    v9 = v29 + 1;
    v10 = &result->m_Pools[iCurPool].m_pNextAlloc;
    v30 = v29 + 1;
    v36 = v10;
    do
    {
      if ( v9 % 4 == 1 )
      {
        v8 += 16;
        v5 = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *)&v10[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase == nullptr )
        {
          v11 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x2000000u,
                                     flAllocationType: 0x2000u,
                                     flProtect: 1u);
          v10 = v36;
          v12 = v11 + 0x2000000;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase = v11;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock = v11;
          result = this;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pLimit = v12;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v10[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v10, 0);
        ++iCurPool;
        v36[3].m_value = nullptr;
        v10 = v36 + 8;
        v36 += 8;
      }
      v9 = v30 + 1;
      result->m_PoolLookup[v7++] = v5;
      v30 = v9;
    }
    while ( v9 < 65 );
  }
  if ( v7 < 128 )
  {
    v13 = v7 + 1;
    v14 = &result->m_Pools[iCurPool].m_pNextAlloc;
    v37 = v7 + 1;
    v31 = v14;
    do
    {
      if ( v13 % 8 == 1 )
      {
        v8 += 32;
        v5 = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *)&v14[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase == nullptr )
        {
          v15 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x2000000u,
                                     flAllocationType: 0x2000u,
                                     flProtect: 1u);
          v14 = v31;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase = v15;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pLimit = v15 + 0x2000000;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock = v15;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v14[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v14, 0);
        ++iCurPool;
        result = this;
        v14[3].m_value = nullptr;
        v14 += 8;
        v31 = v14;
      }
      v13 = v37 + 1;
      result->m_PoolLookup[v7++] = v5;
      v37 = v13;
    }
    while ( v13 < 129 );
  }
  if ( v7 < 192 )
  {
    v16 = v7 + 1;
    v17 = &result->m_Pools[iCurPool].m_pNextAlloc;
    v32 = v7 + 1;
    v38 = v17;
    do
    {
      if ( v16 % 16 == 1 )
      {
        v8 += 64;
        v5 = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *)&v17[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase == nullptr )
        {
          v18 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x2000000u,
                                     flAllocationType: 0x2000u,
                                     flProtect: 1u);
          v17 = v38;
          v19 = v18 + 0x2000000;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase = v18;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock = v18;
          result = this;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pLimit = v19;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v17[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v17, 0);
        ++iCurPool;
        v38[3].m_value = nullptr;
        v17 = v38 + 8;
        v38 += 8;
      }
      v16 = v32 + 1;
      result->m_PoolLookup[v7++] = v5;
      v32 = v16;
    }
    while ( v16 < 193 );
  }
  if ( v7 < 256 )
  {
    v20 = v7 + 1;
    v21 = &result->m_Pools[iCurPool].m_pNextAlloc;
    v33 = v7 + 1;
    v39 = v21;
    do
    {
      if ( v20 % 32 == 1 )
      {
        v8 += 128;
        v5 = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *)&v21[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase == nullptr )
        {
          v22 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x2000000u,
                                     flAllocationType: 0x2000u,
                                     flProtect: 1u);
          v21 = v39;
          v23 = v22 + 0x2000000;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase = v22;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock = v22;
          result = this;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pLimit = v23;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v21[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v21, 0);
        ++iCurPool;
        v39[3].m_value = nullptr;
        v21 = v39 + 8;
        v39 += 8;
      }
      v20 = v33 + 1;
      result->m_PoolLookup[v7++] = v5;
      v33 = v20;
    }
    while ( v20 < 257 );
  }
  if ( v7 < 512 )
  {
    v24 = v7 + 1;
    v34 = v7 + 1;
    v40 = &result->m_PoolLookup[v7];
    v25 = &result->m_Pools[iCurPool].m_pNextAlloc;
    do
    {
      if ( v24 % 64 == 1 )
      {
        v8 += 256;
        v5 = (CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *)&v25[-2];
        if ( CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase == nullptr )
        {
          v26 = (unsigned __int8 *)VirtualAlloc(
                                     lpAddress: nullptr,
                                     dwSize: 0x2000000u,
                                     flAllocationType: 0x2000u,
                                     flProtect: 1u);
          v27 = v26 + 0x2000000;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pBase = v26;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pNextBlock = v26;
          result = this;
          CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_pLimit = v27;
        }
        if ( (v8 & 7) != 0 || v8 < 8 )
          __debugbreak();
        v25[2].m_value = (unsigned __int8 *volatile)v8;
        _InterlockedExchange((volatile __int32 *)v25, 0);
        v24 = v34;
        v25[3].m_value = nullptr;
        v25 += 8;
      }
      v28 = v40++;
      ++v24;
      *v28 = v5;
      v34 = v24;
    }
    while ( v24 < 513 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009EF0
// Name: public: unsigned int CSmallBlockHeap<class CStdMemAlloc::CVirtualAllocator>::Compact(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Compact(
        CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator> *this,
        bool bIncremental)
{
  int v2; // edi
  int v4; // esi
  unsigned int result; // eax
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *m_Pools; // esi
  int i; // ebx

  v2 = 0;
  if ( bIncremental )
  {
    ++`CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Compact'::`5'::iLastIncremental;
    while ( 1 )
    {
      v4 = (v2 + `CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Compact'::`5'::iLastIncremental) % 42;
      result = CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Compact(this: &this->m_Pools[v4], bIncremental);
      if ( result != 0 )
        break;
      if ( ++v2 >= 42 )
        return result;
    }
    `CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Compact'::`5'::iLastIncremental = v4;
  }
  else
  {
    m_Pools = this->m_Pools;
    for ( i = 42; i != 0; --i )
      v2 += CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Compact(this: m_Pools++, bIncremental: false);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009F70
// Name: public: virtual CStdMemAlloc::~CStdMemAlloc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::~CStdMemAlloc(CStdMemAlloc *this)
{
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::SharedData_t **p_m_pSharedData; // esi
  int i; // edi
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> >::SharedData_t **v4; // esi
  int j; // edi

  p_m_pSharedData = &this->m_FallbackSBH.m_pSharedData;
  for ( i = 41; i >= 0; --i )
  {
    p_m_pSharedData -= 8;
    CTSListBase::Detach(this: (CTSListBase *)p_m_pSharedData);
  }
  v4 = &this->m_PrimarySBH.m_pSharedData;
  for ( j = 41; j >= 0; --j )
  {
    v4 -= 8;
    CTSListBase::Detach(this: (CTSListBase *)v4);
  }
  this->__vftable = (CStdMemAlloc_vtbl *)&IMemAlloc::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10009FC0
// Name: public: virtual bool CStdMemAlloc::IsDebugHeap(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStdMemAlloc::IsDebugHeap(CStdMemAlloc *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10009FD0
// Name: public: virtual void CStdMemAlloc::RegisterAllocation(char const __near *,int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::RegisterAllocation(
        CStdMemAlloc *this,
        const char *pFileName,
        const char *nLine,
        int nLogicalSize,
        unsigned int nActualSize,
        unsigned int nTime)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000A010
// Name: public: virtual void CStdMemAlloc::CompactHeap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::CompactHeap(CStdMemAlloc *this)
{
  DWORD CurrentThreadId; // eax
  CThreadFastMutex *p_m_CompactMutex; // ebx
  bool v4; // zf
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator> *m_Pools; // esi
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1> > *v6; // esi
  int i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]

  CurrentThreadId = GetCurrentThreadId();
  p_m_CompactMutex = &this->m_CompactMutex;
  if ( CurrentThreadId == this->m_CompactMutex.m_ownerID
    || _InterlockedCompareExchange((volatile signed __int32 *)p_m_CompactMutex, CurrentThreadId, 0) == 0 )
  {
    ++this->m_CompactMutex.m_depth;
    if ( this->m_bInCompact )
    {
      v4 = this->m_CompactMutex.m_depth-- == 1;
      if ( !v4 )
        return;
      goto LABEL_11;
    }
    this->m_bInCompact = true;
    m_Pools = this->m_FallbackSBH.m_Pools;
    for ( i = 42; i != 0; --i )
      CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::Compact(this: m_Pools++, bIncremental: false);
    v6 = this->m_PrimarySBH.m_Pools;
    for ( j = 42; j != 0; --j )
      CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::Compact(this: v6++, bIncremental: false);
    compact_internal();
    this->m_bInCompact = false;
    v4 = this->m_CompactMutex.m_depth-- == 1;
    if ( v4 )
LABEL_11:
      _InterlockedExchange((volatile __int32 *)p_m_CompactMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A0C0
// Name: public: virtual void CStdMemAlloc::CompactIncremental(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::CompactIncremental(CStdMemAlloc *this)
{
  DWORD CurrentThreadId; // eax
  CThreadFastMutex *p_m_CompactMutex; // esi
  bool v4; // zf

  CurrentThreadId = GetCurrentThreadId();
  p_m_CompactMutex = &this->m_CompactMutex;
  if ( CurrentThreadId == this->m_CompactMutex.m_ownerID
    || _InterlockedCompareExchange((volatile signed __int32 *)p_m_CompactMutex, CurrentThreadId, 0) == 0 )
  {
    ++this->m_CompactMutex.m_depth;
    if ( this->m_bInCompact )
    {
      v4 = this->m_CompactMutex.m_depth-- == 1;
      if ( !v4 )
        return;
    }
    else
    {
      this->m_bInCompact = true;
      CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::Compact(this: &this->m_FallbackSBH, bIncremental: true);
      CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::Compact(this: &this->m_PrimarySBH, bIncremental: true);
      this->m_bInCompact = false;
      v4 = this->m_CompactMutex.m_depth-- == 1;
      if ( !v4 )
        return;
    }
    _InterlockedExchange((volatile __int32 *)p_m_CompactMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B080
// Name: _dynamic_initializer_for__CSmallBlockPool_CStdMemAlloc::CFixedAllocator_48_1___::gm_SharedData__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSmallBlockPool_CStdMemAlloc::CFixedAllocator_48_1___::gm_SharedData__()
{
  CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::SharedData_t::SharedData_t(this: &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData);
  return atexit(func: dynamic_atexit_destructor_for__CSmallBlockPool_CStdMemAlloc::CFixedAllocator_48_1___::gm_SharedData__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B0A0
// Name: _dynamic_initializer_for__CSmallBlockPool_CStdMemAlloc::CVirtualAllocator_::gm_SharedData__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSmallBlockPool_CStdMemAlloc::CVirtualAllocator_::gm_SharedData__()
{
  CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::SharedData_t::SharedData_t(this: &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData);
  return atexit(func: dynamic_atexit_destructor_for__CSmallBlockPool_CStdMemAlloc::CVirtualAllocator_::gm_SharedData__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B5B0
// Name: _dynamic_atexit_destructor_for__CSmallBlockPool_CStdMemAlloc::CFixedAllocator_48_1___::gm_SharedData__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSmallBlockPool_CStdMemAlloc::CFixedAllocator_48_1___::gm_SharedData__()
{
  int v0; // edi
  CTSListBase *v1; // esi

  v0 = 3071;
  v1 = (CTSListBase *)&UNSPECIFIED_LOGGING_COLOR_10;
  do
  {
    v1 -= 3;
    CTSListBase::Detach(this: v1);
    --v0;
  }
  while ( v0 >= 0 );
  CTSListBase::Detach(this: &CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData.m_FreePages);
}

//------------------------------------------------------------------------------
// Address: 0x1002B5E0
// Name: _dynamic_atexit_destructor_for__CSmallBlockPool_CStdMemAlloc::CVirtualAllocator_::gm_SharedData__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSmallBlockPool_CStdMemAlloc::CVirtualAllocator_::gm_SharedData__()
{
  int v0; // edi
  CTSListBase *v1; // esi

  v0 = 511;
  v1 = (CTSListBase *)&CSmallBlockPool<CStdMemAlloc::CFixedAllocator<48,1>>::gm_SharedData;
  do
  {
    v1 -= 3;
    CTSListBase::Detach(this: v1);
    --v0;
  }
  while ( v0 >= 0 );
  CTSListBase::Detach(this: &CSmallBlockPool<CStdMemAlloc::CVirtualAllocator>::gm_SharedData.m_FreePages);
}

//------------------------------------------------------------------------------
// Address: 0x1002B0C0
// Name: _dynamic_initializer_for__s_StdMemAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StdMemAlloc__()
{
  CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>::CSmallBlockHeap<CStdMemAlloc::CFixedAllocator<48,1>>(this: &s_StdMemAlloc.m_PrimarySBH);
  CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>::CSmallBlockHeap<CStdMemAlloc::CVirtualAllocator>(this: &s_StdMemAlloc.m_FallbackSBH);
  s_StdMemAlloc.m_pfnFailHandler = (unsigned int (__cdecl *)(unsigned int))VirtualMemoryManager_AllocateVirtualMemorySection;
  s_StdMemAlloc.m_sMemoryAllocFailed = 0;
  s_StdMemAlloc.m_CompactMutex.m_ownerID = 0;
  s_StdMemAlloc.m_CompactMutex.m_depth = 0;
  s_StdMemAlloc.m_bInCompact = false;
  return atexit(func: dynamic_atexit_destructor_for__s_StdMemAlloc__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B100
// Name: _dynamic_initializer_for__g_AllocRegions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
malloc_state *dynamic_initializer_for__g_AllocRegions__()
{
  malloc_state *result; // eax

  g_AllocRegions[0] = create_mspace(capacity: 0, locked: 1);
  result = create_mspace(capacity: 0x2000000u, locked: 1);
  msp = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B130
// Name: _dynamic_initializer_for__VmmMsgFlag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__VmmMsgFlag__()
{
  VmmMsgFlag.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B140
// Name: _dynamic_initializer_for__g_LocalTimeMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_LocalTimeMutex__()
{
  g_LocalTimeMutex.m_ownerID = 0;
  g_LocalTimeMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B150
// Name: _dynamic_initializer_for__g_AllocCSInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_AllocCSInit__()
{
  InitializeCriticalSection(lpCriticalSection: &g_AllocCS);
}

//------------------------------------------------------------------------------
// Address: 0x1002B160
// Name: _dynamic_initializer_for__g_StackTop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StackTop__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &g_StackTop);
  return atexit(func: dynamic_atexit_destructor_for__g_StackTop__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B180
// Name: _dynamic_initializer_for__s_HelperFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_HelperFunctions__()
{
  s_HelperFunctions.m_Mutex.m_ownerID = 0;
  s_HelperFunctions.m_Mutex.m_depth = 0;
  *(_WORD *)&s_HelperFunctions.m_bIsInitialized = 0;
  s_HelperFunctions.m_hDbgHelpDll = nullptr;
  s_HelperFunctions.m_szPDBSearchPath = nullptr;
  s_HelperFunctions.m_pSymInitialize = (int (__stdcall *)(void *, char *, int))SymUnloadModule64_DummyFn;
  s_HelperFunctions.m_pSymCleanup = (int (__stdcall *)(void *))SymCleanup_DummyFn;
  s_HelperFunctions.m_pSymSetOptions = (unsigned int (__stdcall *)(unsigned int))SymSetOptions_DummyFn;
  s_HelperFunctions.m_pSymGetOptions = (unsigned int (__stdcall *)())VirtualMemoryManager_AllocateVirtualMemorySection;
  s_HelperFunctions.m_pSymSetSearchPath = (int (__stdcall *)(void *, char *))SymSetSearchPath_DummyFn;
  s_HelperFunctions.m_pSymEnumerateModules64 = (int (__stdcall *)(void *, int (__stdcall *)(const char *, unsigned __int64, void *), void *))SymUnloadModule64_DummyFn;
  s_HelperFunctions.m_pEnumerateLoadedModules64 = (int (__stdcall *)(void *, int (__stdcall *)(const char *, unsigned __int64, unsigned int, void *), void *))SymUnloadModule64_DummyFn;
  s_HelperFunctions.m_pSymLoadModule64 = SymLoadModule64_DummyFn;
  s_HelperFunctions.m_pSymUnloadModule64 = SymUnloadModule64_DummyFn;
  s_HelperFunctions.m_pSymFromAddr = (int (__stdcall *)(void *, unsigned __int64, unsigned __int64 *, _SYMBOL_INFO *))SymFromAddr_DummyFn;
  s_HelperFunctions.m_pSymGetLineFromAddr64 = (int (__stdcall *)(void *, unsigned __int64, unsigned int *, _IMAGEHLP_LINE64 *))SymFromAddr_DummyFn;
  s_HelperFunctions.m_pSymGetModuleInfo64 = (int (__stdcall *)(void *, unsigned __int64, _IMAGEHLP_MODULE64 *))CStdMemAlloc::Expand_NoLongerSupported;
  s_HelperFunctions.m_pStackWalk64 = (int (__stdcall *)(unsigned int, void *, void *, _tagSTACKFRAME64 *, void *, int (__stdcall *)(void *, unsigned __int64, void *, unsigned int, unsigned int *), void *(__stdcall *)(void *, unsigned __int64), unsigned __int64 (__stdcall *)(void *, unsigned __int64), unsigned __int64 (__stdcall *)(void *, void *, _tagADDRESS64 *)))StackWalk64_DummyFn;
  return atexit(func: dynamic_atexit_destructor_for__s_HelperFunctions__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B230
// Name: _dynamic_initializer_for__g_nThreadID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_nThreadID__()
{
  g_nThreadID.m_index = TlsAlloc();
  if ( g_nThreadID.m_index == -1 )
    Error(pMsgFormat: "Out of thread local storage!\n");
  return atexit(func: dynamic_atexit_destructor_for__g_nThreadID__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B260
// Name: _dynamic_initializer_for__s_ThreadIDMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ThreadIDMutex__()
{
  s_ThreadIDMutex.m_ownerID = 0;
  s_ThreadIDMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B270
// Name: _dynamic_initializer_for__g_ThreadHandleToIDMapMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ThreadHandleToIDMapMutex__()
{
  InitializeCriticalSectionAndSpinCount(
    lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex,
    dwSpinCount: 0xFA0u);
  g_ThreadHandleToIDMapMutex.m_lockCount = 0;
  g_ThreadHandleToIDMapMutex.m_currentOwnerID = 0;
  g_ThreadHandleToIDMapMutex.m_bTrace = false;
  return atexit(func: dynamic_atexit_destructor_for__g_ThreadHandleToIDMapMutex__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B2A0
// Name: _dynamic_initializer_for__g_ThreadMainThreadID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD dynamic_initializer_for__g_ThreadMainThreadID__()
{
  DWORD result; // eax

  ThreadSetDebugName(hThread: nullptr, pszName: "MainThrd");
  result = GetCurrentThreadId();
  g_ThreadMainThreadID = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B2C0
// Name: _dynamic_initializer_for__DynTryEnterCriticalSection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (__stdcall *dynamic_initializer_for__DynTryEnterCriticalSection__())(_RTL_CRITICAL_SECTION *)
{
  int (__stdcall *result)(_RTL_CRITICAL_SECTION *); // eax

  result = (int (__stdcall *)(_RTL_CRITICAL_SECTION *))Plat_GetProcAddress(
                                                         pszModule: "Kernel32.dll",
                                                         pszName: "TryEnterCriticalSection");
  if ( result != nullptr )
    DynTryEnterCriticalSection.m_pfn = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B2E0
// Name: _dynamic_initializer_for__g_pCurThread__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pCurThread__()
{
  g_pCurThread.m_index = TlsAlloc();
  if ( g_pCurThread.m_index == -1 )
    Error(pMsgFormat: "Out of thread local storage!\n");
  return atexit(func: dynamic_atexit_destructor_for__g_pCurThread__);
}

//------------------------------------------------------------------------------
// Address: 0x1002B610
// Name: _dynamic_atexit_destructor_for__s_StdMemAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_StdMemAlloc__()
{
  CStdMemAlloc::~CStdMemAlloc(this: &s_StdMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1002B620
// Name: _dynamic_atexit_destructor_for__s_HelperFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_HelperFunctions__()
{
  s_HelperFunctions.m_pSymCleanup(a1: s_HelperFunctions.m_hProcess);
  if ( s_HelperFunctions.m_hDbgHelpDll != nullptr )
    FreeLibrary(hLibModule: s_HelperFunctions.m_hDbgHelpDll);
  if ( s_HelperFunctions.m_szPDBSearchPath != nullptr )
    operator delete(p: s_HelperFunctions.m_szPDBSearchPath);
}

//------------------------------------------------------------------------------
// Address: 0x1002B650
// Name: _dynamic_atexit_destructor_for__g_StackTop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StackTop__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_StackTop);
}

//------------------------------------------------------------------------------
// Address: 0x1002B660
// Name: _Plat_GetPagedPoolInfo_::_2_::_dynamic_atexit_destructor_for__qsi__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl Plat_GetPagedPoolInfo_::_2_::_dynamic_atexit_destructor_for__qsi__()
{
  if ( qsi.m_bInitialized )
  {
    if ( qsi.m_bFreeModule && qsi.m_hModule != nullptr )
      FreeLibrary(hLibModule: qsi.m_hModule);
    qsi.m_eResult = SYSCALL_SUCCESS;
    qsi.m_hModule = nullptr;
    qsi.m_pfnSysCall = nullptr;
    *(_WORD *)&qsi.m_bInitialized = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B6A0
// Name: _dynamic_atexit_destructor_for__g_ThreadHandleToIDMapMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ThreadHandleToIDMapMutex__()
{
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ThreadHandleToIDMapMutex);
}

//------------------------------------------------------------------------------
// Address: 0x1002B6B0
// Name: _dynamic_atexit_destructor_for__g_pCurThread__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pCurThread__()
{
  if ( g_pCurThread.m_index != -1 )
    TlsFree(dwTlsIndex: g_pCurThread.m_index);
  g_pCurThread.m_index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B6D0
// Name: _dynamic_atexit_destructor_for__g_nThreadID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_nThreadID__()
{
  if ( g_nThreadID.m_index != -1 )
    TlsFree(dwTlsIndex: g_nThreadID.m_index);
  g_nThreadID.m_index = -1;
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F003B60
// Name: public: CDbgFmtMsg::CDbgFmtMsg(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CDbgFmtMsg *CDbgFmtMsg::CDbgFmtMsg(CDbgFmtMsg *this, const char *pszFormat, ...)
{
  char v2; // zf
  int v3; // ebx
  int v4; // ebp
  int v5; // edi
  _BYTE *v6; // esi
  char *v7; // edx
  _DWORD *v8; // eax
  CSmallBlockPool *v9; // ecx

  if ( !v2 )
  {
    v7 = *(char **)(v4 - 40);
    v8 = *(_DWORD **)(v4 - 8);
    v8[1] = *(_DWORD *)(v4 - 44);
    if ( v7 != nullptr )
    {
      *v8 = v6;
      sub_3F003A20(result: v6, a2: v7, a3: v4 - 2700);
      JUMPOUT(0x3F003B82);
    }
    *v8 = 0;
  }
  dword_3F03D3A0(
    a1: *(_DWORD *)(v4 - 12),
    a2: *(_DWORD *)(v5 + 8 * v3),
    a3: *(_DWORD *)(v5 + 8 * v3 + 4),
    a4: v4 - 68,
    a5: v4 - 412);
  return (CDbgFmtMsg *)CSmallBlockPool::Alloc(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x3F003BB0
// Name: public: void __near * CSmallBlockPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CSmallBlockPool::Alloc(
        CSmallBlockPool *this@<ecx>,
        int a2@<eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        _BYTE *a5@<esi>)
{
  const char *v5; // edi
  bool v6; // zf
  _BYTE *v7; // eax
  int v8; // edx
  const char *v9; // ecx
  int v10; // ebx
  bool v11; // cc
  int v12; // esi
  int v13; // edi

  v5 = (const char *)(a4 - 328);
  if ( a2 == 0 )
    v5 = "(Function name not found)";
  if ( sub_3F01A783(a1: v5, a2: "$E5") == 0 )
    v5 = "Global Constructor";
  v6 = *v5 == 0;
  *(_DWORD *)(*(_DWORD *)(a4 - 8) + 8) = a5;
  v7 = a5;
  if ( !v6 )
  {
    v8 = 1 - (a4 - 2700);
    *(_DWORD *)(a4 - 24) = v8;
    v9 = (const char *)(v5 - a5);
    while ( (int)&v7[v8] < 2048 )
    {
      *v7 = v7[(_DWORD)v9];
      if ( (++v7)[(_DWORD)v9] == 0 )
        break;
      v8 = *(_DWORD *)(a4 - 24);
    }
  }
  *(_DWORD *)(a4 - 8) += 12;
  v10 = a3 + 1;
  v11 = v10 < *(_DWORD *)(a4 - 16);
  *v7 = 0;
  if ( v11 )
    JUMPOUT(0x3F003B40);
  ((void (__cdecl *)(_DWORD))dword_3F03D3A4)(a1: *(_DWORD *)(a4 - 12));
  LeaveCriticalSection(lpCriticalSection: &stru_3F03D2D0);
  if ( v10 == 0 && *(_BYTE *)(a4 + 12) == 0 )
  {
    SetAssertDumpStack(bAssertDumpStack: (bool)"console");
    return;
  }
  v12 = 0;
  if ( v10 > 0 )
  {
    v13 = a4 - 652;
    do
    {
      if ( *(_DWORD *)v13 != 0 )
      {
        if ( *(_BYTE *)(a4 + 16) == 0 )
          goto LABEL_21;
        SpewMessage(
          a1: "Assertion Failed: stack%d: %s (%d): %s",
          v12,
          *(const char **)v13,
          *(_DWORD *)(v13 + 4),
          *(const char **)(v13 + 8));
      }
      else if ( *(_BYTE *)(a4 + 12) == 0 )
      {
LABEL_21:
        SetAssertDumpStack(bAssertDumpStack: (bool)"console");
      }
      ++v12;
      v13 += 12;
    }
    while ( v12 < v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F003D70
// Name: public: void CSmallBlockPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '?RenderLeaks@CValidator@@QAEXH@Z'
// Alternative name is '?SetTrace@CThreadFullMutex@@QAEX_N@Z'
void __thiscall CSmallBlockPool::Free(CSmallBlockPool *this, CAutoLockT<CThreadFastMutex> p)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F004400
// Name: public: CSmallBlockHeap::~CSmallBlockHeap(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CSmallBlockHeap::~CSmallBlockHeap(CSmallBlockHeap *this)
{
  _mm_pause();
  if ( this->m_PoolLookup[0] != nullptr )
    JUMPOUT(0x3F00441C);
}

//------------------------------------------------------------------------------
// Address: 0x3F004420
// Name: public: bool CSmallBlockHeap::ShouldUse(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSmallBlockHeap::ShouldUse(
        CSmallBlockHeap *this@<ecx>,
        unsigned int a2@<eax>,
        unsigned int a3@<edx>,
        unsigned int nBytes,
        int a5,
        volatile signed __int64 *a6,
        int a7,
        int a8,
        signed __int64 a9)
{
  _InterlockedCompareExchange64(a6, __SPAIR64__(a2, a3), a9);
  JUMPOUT(0x3F004442);
}

//------------------------------------------------------------------------------
// Address: 0x3F0044A0
// Name: public: void __near * CSmallBlockHeap::Realloc(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int __userpurge CSmallBlockHeap::Realloc@<eax>(
        CSmallBlockHeap *this@<ecx>,
        volatile signed __int64 *nBytes@<eax>,
        int a3@<esi>,
        void *p)
{
  unsigned int *v5; // [esp-8h] [ebp-8h]

  *(_DWORD *)(a3 + 4) = -168890355;
  return sub_3F0042F0(a1: nBytes, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x3F004550
// Name: public: void CSmallBlockHeap::DumpStats(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CSmallBlockHeap::DumpStats(
        CSmallBlockHeap *this@<ecx>,
        char a2@<cf>,
        int a3@<eax>,
        int a4@<ebx>,
        int a5@<ebp>)
{
  HMODULE v5; // eax

  v5 = (HMODULE)((char *)&LoadLibraryA + a2 + a3);
  dword_3F03F208 = (int)v5;
  if ( v5 != (HMODULE)a4 )
    GetProcessMemoryInfo = (int)GetProcAddress(hModule: v5, lpProcName: "GetProcessMemoryInfo");
  dword_3F03F22C = a4;
  dword_3F03F230 = a4;
  dword_3F03F234 = a4;
  dword_3F03F238 = a4;
  dword_3F03F23C = a4;
  dword_3F03F240 = a4;
  dword_3F03F244 = a4;
  dword_3F03F248 = a4;
  dword_3F03F24C = a4;
  dword_3F03F254 = a4;
  dword_3F03F258 = a4;
  *(_DWORD *)(a5 - 4) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F004600
// Name: public: virtual void CStdMemAlloc::DumpStats(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F004610
// Name: public: virtual bool CStdMemAlloc::IsDebugHeap(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStdMemAlloc::IsDebugHeap(CStdMemAlloc *this@<ecx>, int _EAX@<eax>)
{
  __asm { aas }
  dword_3F03F208 = 0;
  JUMPOUT(0x3F00461B);
}

//------------------------------------------------------------------------------
// Address: 0x3F004620
// Name: public: virtual void CStdMemAlloc::RegisterAllocation(char const __near *,int,int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStdMemAlloc::RegisterAllocation(
        CStdMemAlloc *this@<ecx>,
        int _EAX@<eax>,
        const char *pFileName,
        int nLine,
        int nLogicalSize,
        int nActualSize,
        unsigned int nTime)
{
  __asm { aas }
  JUMPOUT(0x3F004621);
}

//------------------------------------------------------------------------------
// Address: 0x3F004630
// Name: public: virtual unsigned int CStdMemAlloc::CpubAllocated(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStdMemAlloc::CpubAllocated(CStdMemAlloc *this@<ecx>, _DWORD *a2@<eax>)
{
  *a2 -= a2;
  JUMPOUT(0x3F004634);
}

//------------------------------------------------------------------------------
// Address: 0x3F004640
// Name: public: CStdMemAlloc::CStdMemAlloc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::CStdMemAlloc(CStdMemAlloc *this)
{
  JUMPOUT(0x3F004644);
}

//------------------------------------------------------------------------------
// Address: 0x3F0046E0
// Name: public: CStdMemAlloc::~CStdMemAlloc(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CStdMemAlloc::~CStdMemAlloc(CStdMemAlloc *this, int a2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F004770
// Name: public: virtual void __near * CStdMemAlloc::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStdMemAlloc::Alloc(CStdMemAlloc *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F004820
// Name: public: virtual void __near * CStdMemAlloc::Realloc(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__userpurge CStdMemAlloc::Realloc@<eax>(
        CStdMemAlloc *this@<ecx>,
        char a2@<dh>,
        int a3@<ebx>,
        int a4@<ebp>,
        size_t a5@<edi>,
        void *pMem,
        void *nSize)
{
  void *result; // eax
  int (__thiscall *v8)(int); // edx

  *(_BYTE *)(2 * a3 + 0x3B) |= a2;
  if ( a5 > MEMORY[0x3C34] || (result = (void *)CVProfNode::GetOrigNameAddress((CVProfNode *)this)) == nullptr )
  {
    dword_3F03D3BC += a5;
    if ( a5 > 0x400
      || (result = (void *)(*(int (__thiscall **)(int, size_t))(MEMORY[0x1E18] + 148))(a1: 7704, a2: a5)) == nullptr
      && (byte_3F041A35 != 0
       || ((*(void (__thiscall **)(int))(MEMORY[0x1E18] + 120))(a1: 7704),
           v8 = *(int (__thiscall **)(int))(MEMORY[0x1E18] + 148),
           byte_3F041A35 = 1,
           (result = (void *)v8(a1: 7704)) == nullptr)) )
    {
      result = malloc_0(Size: a5);
      if ( result == nullptr )
      {
        dword_3F03D3BC -= a5;
        if ( *(_BYTE *)(a4 + 12) == 0 )
        {
          CVProfNode::~CVProfNode(this: (CVProfNode *)a5);
          return nullptr;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F004900
// Name: public: virtual void CStdMemAlloc::Free(void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CStdMemAlloc::Free(CStdMemAlloc *this@<ecx>, int a2@<ebx>, void *pMem, bool bOperatorDelete)
{
  *(_BYTE *)(a2 + 95) += a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F004950
// Name: public: virtual void __near * CStdMemAlloc::Alloc(unsigned int,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge CStdMemAlloc::Alloc@<eax>(
        CStdMemAlloc *this@<ecx>,
        char a2@<cf>,
        _DWORD *a3@<eax>,
        int a4@<ebx>,
        int a5@<esi>,
        unsigned int nSize,
        const char *pFileName,
        int nLine,
        bool bOperatorNew)
{
  *a3 += (char *)a3 + a2;
  *(_BYTE *)(a4 + 95) += a4;
  return a5;
}

//------------------------------------------------------------------------------
// Address: 0x3F004960
// Name: public: virtual void __near * CStdMemAlloc::Realloc(void __near *,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::Realloc(
        CStdMemAlloc *this,
        unsigned int pMem,
        const char *nSize,
        const char *pFileName,
        int nLine)
{
  if ( pMem != 0 )
    JUMPOUT(0x3F004972);
  JUMPOUT(0x3F004A16);
}

//------------------------------------------------------------------------------
// Address: 0x3F004980
// Name: public: virtual void CStdMemAlloc::Free(void __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CStdMemAlloc::Free(
        CStdMemAlloc *this@<ecx>,
        int a2@<edi>,
        unsigned int a3@<esi>,
        void *pMem,
        const char *pFileName,
        int nLine,
        bool bOperatorDelete)
{
  int v7; // eax

  v7 = *(_DWORD *)(a2 + 2552);
  if ( a3 < *(_DWORD *)(v7 + 36) || a3 >= *(_DWORD *)(v7 + 40) )
    JUMPOUT(0x3F0049CF);
  ThreadWaitForObjects();
}

//------------------------------------------------------------------------------
// Address: 0x3F0049D0
// Name: public: virtual void __near * CStdMemAlloc::Expand_NoLongerSupported(void __near *,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStdMemAlloc::Expand_NoLongerSupported(
        CStdMemAlloc *this@<ecx>,
        char a2@<cf>,
        char a3@<of>,
        void *pMem,
        unsigned int nSize,
        const char *pFileName,
        int nLine)
{
  if ( !a3 )
  {
    if ( !a2 )
      JUMPOUT(0x3F0049D7);
    JUMPOUT(0x3F004A0D);
  }
  JUMPOUT(0x3F0049F6);
}

//------------------------------------------------------------------------------
// Address: 0x3F0049E0
// Name: public: virtual unsigned int CStdMemAlloc::GetSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge CStdMemAlloc::GetSize@<eax>(CStdMemAlloc *this@<ecx>, unsigned int a2@<eax>, int a3@<esi>, void *pMem)
{
  if ( HIWORD(a2) >= 0x4000u )
    return ((int (__cdecl *)(_DWORD, int))loc_3F008340)(a1: 0, a2: a3);
  else
    return ((int (*)(void))loc_3F008340)();
}

//------------------------------------------------------------------------------
// Address: 0x3F004A20
// Name: public: virtual void CStdMemAlloc::GetActualDbgInfo(char const __near * __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::GetActualDbgInfo(CStdMemAlloc *this, const char **pFileName, int *nLine)
{
  JUMPOUT(0x3F004A23);
}

//------------------------------------------------------------------------------
// Address: 0x3F004A30
// Name: public: virtual int CStdMemAlloc::CrtIsValidHeapPointer(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStdMemAlloc::CrtIsValidHeapPointer(
        CStdMemAlloc *this@<ecx>,
        char a2@<dh>,
        int a3@<ebx>,
        const void *pMem)
{
  *(_BYTE *)(2 * a3 + 0x3B) |= a2;
  JUMPOUT(0x3F004A39);
}

//------------------------------------------------------------------------------
// Address: 0x3F004A40
// Name: public: virtual int CStdMemAlloc::CrtIsValidPointer(void const __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStdMemAlloc::CrtIsValidPointer(
        CStdMemAlloc *this@<ecx>,
        char a2@<dh>,
        int a3@<edi>,
        const void *pMem,
        unsigned int size,
        int access)
{
  *(_BYTE *)(a3 + 11) += a2;
  CVProfNode::GetOrigNameAddress((CVProfNode *)this);
  JUMPOUT(0x3F004A4A);
}

//------------------------------------------------------------------------------
// Address: 0x3F004A50
// Name: public: virtual int CStdMemAlloc::CrtCheckMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStdMemAlloc::CrtCheckMemory(CStdMemAlloc *this@<ecx>, _DWORD *a2@<eax>)
{
  ++*a2;
  JUMPOUT(0x3F004A57);
}

//------------------------------------------------------------------------------
// Address: 0x3F004A60
// Name: public: virtual void CStdMemAlloc::CrtMemCheckpoint(struct _CrtMemState __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::CrtMemCheckpoint(CStdMemAlloc *this, _CrtMemState *pState)
{
  JUMPOUT(0x3F004A61);
}

//------------------------------------------------------------------------------
// Address: 0x3F004A70
// Name: public: virtual void __near * CStdMemAlloc::Expand_NoLongerSupported(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStdMemAlloc::Expand_NoLongerSupported(
        CStdMemAlloc *this@<ecx>,
        char a2@<cf>,
        char a3@<al>,
        size_t a4@<edi>,
        void *pMem,
        unsigned int nSize)
{
  if ( a3 == a2 + *(_BYTE *)(2 * a4) )
    JUMPOUT(0x3F004A75);
  malloc_0(Size: a4);
  JUMPOUT(0x3F004A9F);
}

//------------------------------------------------------------------------------
// Address: 0x3F004A80
// Name: public: virtual long CStdMemAlloc::CrtSetBreakAlloc(long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStdMemAlloc::CrtSetBreakAlloc(CStdMemAlloc *this, int lNewBreakAlloc)
{
  JUMPOUT(0x3F004A86);
}

//------------------------------------------------------------------------------
// Address: 0x3F004A90
// Name: public: virtual int CStdMemAlloc::CrtDbgReport(int,char const __near *,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __fastcall CStdMemAlloc::CrtDbgReport(
        CStdMemAlloc *this,
        int (__thiscall *a2)(CStdMemAlloc *),
        int nRptType,
        const char *szFile,
        int nLine,
        const char *szModule,
        const char *pMsg)
{
  int result; // eax

  result = a2(a1: this);
  if ( result == 0 )
    JUMPOUT(0x3F004A96);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F004AA0
// Name: public: virtual int CStdMemAlloc::heapchk(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStdMemAlloc::heapchk(CStdMemAlloc *this@<ecx>, int a2@<ebp>)
{
  *(_BYTE *)(a2 + 17) = 0;
  JUMPOUT(0x3F004AA9);
}

//------------------------------------------------------------------------------
// Address: 0x3F004470
// Name: sub_3F004470
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge sub_3F004470@<eax>(CSmallBlockHeap *a1@<ecx>, int a2@<esi>, volatile signed __int64 *a3)
{
  if ( *(_DWORD *)(a2 + 4) == -168890355 )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: pdw[1] != FREE_BLOCK_MARKER",
      a2: 0,
      a3: "d:\\buildslave\\steam_rel_client_win32\\build\\src\\tier0\\memstd.h",
      a4: 79,
      a5: &unk_3F041A32,
      a6: 0);
  return CSmallBlockHeap::Realloc(this: a1, nBytes: a3, a3: a2, p: (void *)a3);
}

} // namespace tier0_s
