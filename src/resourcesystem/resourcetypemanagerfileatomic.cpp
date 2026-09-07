// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: resourcesystem/resourcetypemanagerfileatomic.cpp
// Functions: 99
// ============================================================

#include "resourcesystem\resourcetypemanagerfileatomic.h"

//------------------------------------------------------------------------------
// Address: 0x100012C0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x100012D0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
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
// Address: 0x10004470
// Name: public: void CUtlTSHash<struct ResourceFileData_t,251,void __near *,class CUtlTSHashGenericHash<251,void __near *>,0>::Commit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::Commit(
        CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi

  if ( this->m_bNeedsCommit )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 251; i != 0; --i )
    {
      CThreadSpinRWLock::LockForRead(this: p_m_AddLock);
      p_m_AddLock[-1].m_nWriters.m_value = *((_DWORD *)&p_m_AddLock[-1].m_nWriters + 1);
      CThreadSpinRWLock::UnlockRead(this: p_m_AddLock);
      p_m_AddLock = (CThreadSpinRWLock *)((char *)p_m_AddLock + 24);
    }
    this->m_bNeedsCommit = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100044C0
// Name: public: int CUtlTSHash<struct ResourceFileData_t,251,void __near *,class CUtlTSHashGenericHash<251,void __near *>,0>::GetElements(int,int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::GetElements(
        CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0> *this,
        int nFirstElement,
        int nCount,
        int *pHandles)
{
  int v4; // esi
  int v5; // ebx
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> **i; // edi
  int v7; // eax

  v4 = 0;
  v5 = 0;
  for ( i = &this->m_aBuckets[0].m_pFirstUncommitted; ; i += 6 )
  {
    CThreadSpinRWLock::LockForRead(this: (CThreadSpinRWLock *)(i + 1));
    v7 = (int)*i;
    if ( *i != nullptr )
      break;
LABEL_6:
    CThreadSpinRWLock::UnlockRead(this: (CThreadSpinRWLock *)(i + 1));
    if ( ++v5 >= 251 )
      return v4;
  }
  while ( 1 )
  {
    if ( --nFirstElement < 0 )
    {
      pHandles[v4++] = v7;
      if ( v4 >= nCount )
        break;
    }
    v7 = *(_DWORD *)(v7 + 4);
    if ( v7 == 0 )
      goto LABEL_6;
  }
  CThreadSpinRWLock::UnlockRead(this: (CThreadSpinRWLock *)(i + 1));
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100047C0
// Name: public: CTSQueue<struct CAsyncIOResult_t,0>::CTSQueue<struct CAsyncIOResult_t,0>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CAsyncIOResult_t,0> *__thiscall CTSQueue<CAsyncIOResult_t,0>::CTSQueue<CAsyncIOResult_t,0>(
        CTSQueue<CAsyncIOResult_t,0> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CInterlockedIntT<int> *p_m_Count; // edi
  CTSQueue<CAsyncIOResult_t,0>::Node_t *v4; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  p_m_Count = &this->m_Count;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  HIDWORD(p_m_FreeNodes->m_Head.value64) = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&p_m_Count->m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v4 = (CTSQueue<CAsyncIOResult_t,0>::Node_t *)operator new(nSize: 0x10u);
  if ( v4 != nullptr )
  {
    v4->elem.m_pRequest = nullptr;
    v4->elem.m_Status = ASYNC_REQUEST_STATUS_UNDEFINED;
    this->m_Tail.value.pNode = v4;
    this->m_Head.value.pNode = v4;
    v4->pNext = (CTSQueue<CAsyncIOResult_t,0>::Node_t *)this;
  }
  else
  {
    this->m_Tail.value.pNode = nullptr;
    this->m_Head.value.pNode = nullptr;
    MEMORY[0] = this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100048F0
// Name: public: CUtlTSHash<struct ResourceFileData_t,251,void __near *,class CUtlTSHashGenericHash<251,void __near *>,0>::CUtlTSHash<struct ResourceFileData_t,251,void __near *,class CUtlTSHashGenericHash<251,void __near *>,0>(int)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0> *__thiscall CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>(
        CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0> *this,
        int nAllocationCount)
{
  int v3; // ebp
  CThreadSpinRWLock *p_m_AddLock; // edi
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashBucket_t *m_aBuckets; // eax
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_EntryMemory,
    blockSize: 24,
    numElements: nAllocationCount,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 250;
  p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
  do
  {
    CThreadSpinRWLock::CThreadSpinRWLock(this: p_m_AddLock);
    p_m_AddLock = (CThreadSpinRWLock *)((char *)p_m_AddLock + 24);
    --v3;
  }
  while ( v3 >= 0 );
  this->m_bNeedsCommit = false;
  m_aBuckets = this->m_aBuckets;
  for ( i = 251; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004A00
// Name: public: void CUtlTSHash<struct ResourceFileData_t,251,void __near *,class CUtlTSHashGenericHash<251,void __near *>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::RemoveAll(
        CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0> *this)
{
  bool v1; // zf
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> **p_m_pFirstUncommitted; // esi
  int i; // edi
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> *j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  v1 = this->m_EntryMemory.m_BlocksAllocated == 0;
  this->m_bNeedsCommit = false;
  if ( !v1 )
  {
    p_m_pFirstUncommitted = &this->m_aBuckets[0].m_pFirstUncommitted;
    for ( i = 251; i != 0; --i )
    {
      CThreadSpinRWLock::LockForWrite(this: (CThreadSpinRWLock *)(p_m_pFirstUncommitted + 1));
      for ( j = *p_m_pFirstUncommitted; j != nullptr; j = j->m_pNext )
        ;
      *(p_m_pFirstUncommitted - 1) = nullptr;
      *p_m_pFirstUncommitted = nullptr;
      CThreadSpinRWLock::UnlockWrite(this: (CThreadSpinRWLock *)(p_m_pFirstUncommitted + 1));
      p_m_pFirstUncommitted += 6;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    v1 = this->m_EntryMemory.m_mutex.m_depth-- == 1;
    if ( v1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004DE0
// Name: public: virtual void __near * CDefaultFileAtomicConstructor::GetFallback(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDefaultFileAtomicConstructor::GetFallback(
        CBaseAppSystem<IResourceSystem> *this,
        const char *pInterfaceName)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10004E50
// Name: public: struct CTSQueue<struct CAsyncIOResult_t,0>::Node_t __near * CTSQueue<struct CAsyncIOResult_t,0>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CAsyncIOResult_t,0>::Node_t *__thiscall CTSQueue<CAsyncIOResult_t,0>::Pop(CTSQueue<CAsyncIOResult_t,0> *this)
{
  CTSQueue<CAsyncIOResult_t,0> *v1; // esi
  CTSQueue<CAsyncIOResult_t,0> *pNext; // eax
  IAsyncRequestBase *sequence; // edi
  CTSQueue<CAsyncIOResult_t,0>::Node_t *v4; // ebx
  CTSQueue<CAsyncIOResult_t,0>::NodeLink_t *p_m_Tail; // [esp+64h] [ebp-1Ch]
  int *p_sequence; // [esp+68h] [ebp-18h]
  CTSQueue<CAsyncIOResult_t,0>::NodeLink_t *v9; // [esp+70h] [ebp-10h]
  CTSQueue<CAsyncIOResult_t,0>::Node_t *pNode; // [esp+78h] [ebp-8h]

  v1 = this;
  p_m_Tail = &this->m_Tail;
  p_sequence = &this->m_Head.value.sequence;
  v9 = &this->m_Tail;
  while ( 1 )
  {
    do
    {
      while ( 1 )
      {
        do
        {
          pNode = v1->m_Head.value.pNode;
          pNext = (CTSQueue<CAsyncIOResult_t,0> *)v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( pNode != v9->value.pNode )
          break;
        if ( pNext == v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: p_m_Tail->value.sequence + 1,
          a4: pNode,
          a5: p_m_Tail->value.sequence);
      }
    }
    while ( pNext == v1 );
    sequence = (IAsyncRequestBase *)pNext->m_Head.value.sequence;
    v4 = pNext->m_Tail.value.pNode;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: pNext,
                            a3: *p_sequence + 1,
                            a4: pNode,
                            a5: *p_sequence) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  pNode->elem.m_pRequest = sequence;
  pNode->elem.m_Status = (AsyncRequestStatus_t)v4;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x10005030
// Name: public: bool CUtlVector<unsigned int __near *,class CUtlMemory<unsigned int __near *,int>>::FindAndRemove(unsigned int __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<unsigned int *,CUtlMemory<unsigned int *,int>>::FindAndRemove(
        CUtlVector<unsigned int *,CUtlMemory<unsigned int *,int> > *this,
        unsigned int **src)
{
  int m_Size; // edx
  int v4; // eax
  unsigned int **m_pMemory; // ebx
  unsigned int **i; // ecx
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
// Address: 0x10005090
// Name: public: int CUtlTSHash<struct ResourceFileData_t,251,void __near *,class CUtlTSHashGenericHash<251,void __near *>,0>::Find(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::Find(
        CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0> *this,
        void *uiKey)
{
  int v2; // edx
  int *v3; // esi
  int result; // eax
  CThreadSpinRWLock *p_m_AddLock; // edi
  int v6; // eax
  int v7; // esi
  int v8; // esi

  v2 = ((unsigned __int8)(((HIBYTE(uiKey)
                          + 33
                          * (BYTE2(uiKey)
                           + 33 * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16)
                        ^ (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * ((_BYTE)uiKey - 86)))))
      ^ (unsigned __int8)((unsigned __int16)(((HIBYTE(uiKey)
                                             + 33
                                             * (BYTE2(uiKey)
                                              + 33
                                              * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16)
                                           ^ (HIBYTE(uiKey)
                                            + 33
                                            * (BYTE2(uiKey) + 33
                                                            * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))) >> 8))
     & 0xFA;
  v3 = (int *)&this->m_aBuckets[v2];
  result = *v3;
  if ( *v3 != 0 )
  {
    while ( *(void **)result != uiKey )
    {
      result = *(_DWORD *)(result + 4);
      if ( result == 0 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    p_m_AddLock = &this->m_aBuckets[v2].m_AddLock;
    CThreadSpinRWLock::LockForRead(this: p_m_AddLock);
    v6 = v3[1];
    v7 = *v3;
    if ( v6 == v7 )
    {
LABEL_7:
      CThreadSpinRWLock::UnlockRead(this: p_m_AddLock);
      return 0;
    }
    else
    {
      while ( *(void **)v6 != uiKey )
      {
        v6 = *(_DWORD *)(v6 + 4);
        if ( v6 == v7 )
          goto LABEL_7;
      }
      v8 = v6;
      CThreadSpinRWLock::UnlockRead(this: p_m_AddLock);
      return v8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005150
// Name: public: int CUtlTSHash<struct ResourceFileData_t,251,void __near *,class CUtlTSHashGenericHash<251,void __near *>,0>::Insert(void __near *,struct ResourceFileData_t const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> *__thiscall CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::Insert(
        CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0> *this,
        void *uiKey,
        const ResourceFileData_t *data,
        bool *pDidInsert)
{
  int v5; // edx
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashBucket_t *v6; // esi
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> *result; // eax
  CThreadSpinRWLock *p_m_AddLock; // ebp
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> *m_pFirstUncommitted; // eax
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> *v10; // eax
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> *v11; // esi
  ResourceFileData_t *p_m_Data; // eax
  CThreadSpinRWLock *v13; // ecx
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> *v14; // esi

  if ( pDidInsert != nullptr )
    *pDidInsert = false;
  v5 = (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 1431655766)))) >> 16;
  v6 = &this->m_aBuckets[((unsigned __int8)(v5
                                          ^ (HIBYTE(uiKey)
                                           + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * ((_BYTE)uiKey - 86)))))
                        ^ (unsigned __int8)((unsigned __int16)(v5
                                                             ^ (HIBYTE(uiKey)
                                                              + 33
                                                              * (BYTE2(uiKey)
                                                               + 33
                                                               * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))) >> 8))
                       & 0xFA];
  result = (CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> *)CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::Find(this, uiKey);
  if ( result == nullptr )
  {
    p_m_AddLock = &v6->m_AddLock;
    CThreadSpinRWLock::LockForWrite(this: &v6->m_AddLock);
    m_pFirstUncommitted = v6->m_pFirstUncommitted;
    if ( m_pFirstUncommitted == v6->m_pFirst )
    {
LABEL_7:
      this->m_bNeedsCommit = true;
      v10 = (CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::HashFixedDataInternal_t<ResourceFileData_t> *)CMemoryPoolMT::Alloc(this: &this->m_EntryMemory);
      v10->m_pNext = v6->m_pFirstUncommitted;
      v6->m_pFirstUncommitted = v10;
      v10->m_uiKey = uiKey;
      v11 = v10;
      p_m_Data = &v10->m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = *data;
      if ( pDidInsert != nullptr )
        *pDidInsert = true;
      CThreadSpinRWLock::UnlockWrite(this: p_m_AddLock);
      return v11;
    }
    else
    {
      while ( m_pFirstUncommitted->m_uiKey != uiKey )
      {
        m_pFirstUncommitted = m_pFirstUncommitted->m_pNext;
        if ( m_pFirstUncommitted == v6->m_pFirst )
          goto LABEL_7;
      }
      v13 = &v6->m_AddLock;
      v14 = m_pFirstUncommitted;
      CThreadSpinRWLock::UnlockWrite(this: v13);
      return v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005C80
// Name: public: void CTSQueue<struct CAsyncIOResult_t,0>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<CAsyncIOResult_t,0>::Purge(CTSQueue<CAsyncIOResult_t,0> *this)
{
  CTSQueue<CAsyncIOResult_t,0>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int value64_high; // eax

  for ( i = CTSQueue<CAsyncIOResult_t,0>::Pop(this); i != nullptr; i = CTSQueue<CAsyncIOResult_t,0>::Pop(this) )
    free(pMem: i);
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &this->m_FreeNodes,
                               a2: Next->Next,
                               a3: value64_high - 1,
                               a4: Next,
                               a5: value64_high) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
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
// Address: 0x10006040
// Name: public: int CUtlVector<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,class CUtlMemory<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::InsertBefore(int,struct CResourceTypeManagerFileAtomic::ToCacheHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::InsertBefore(
        CUtlVector<CResourceSystem::PendingResourceIdResolution_t,CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> > *this,
        int elem,
        const CResourceSystem::PendingResourceIdResolution_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CResourceSystem::PendingResourceIdResolution_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CResourceSystem::PendingResourceIdResolution_t *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100060C0
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned short,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10006130
// Name: public: int CUtlVector<struct CCountedStringPoolBase<unsigned short>::hash_item_t,class CUtlMemory<struct CCountedStringPoolBase<unsigned short>::hash_item_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CCountedStringPoolBase<unsigned short>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>>::InsertBefore(
        CUtlVector<CCountedStringPoolBase<unsigned short>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CCountedStringPoolBase<unsigned short>::hash_item_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10006190
// Name: public: int CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned int,int>::Grow((CUtlMemory<KeyValues *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10006200
// Name: public: int CUtlVector<struct CCountedStringPoolBase<unsigned int>::hash_item_t,class CUtlMemory<struct CCountedStringPoolBase<unsigned int>::hash_item_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>>::InsertBefore(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CCountedStringPoolBase<unsigned int>::hash_item_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      (CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008870
// Name: void MemAlloc_FreeAligned(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MemAlloc_FreeAligned(unsigned int pMemBlock)
{
  if ( pMemBlock != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((pMemBlock & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x100088B0
// Name: public: virtual void CResourceTypeManagerFileAtomic::Init(int,class IResourceTypeConstructor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::Init(
        CResourceTypeManagerFileAtomic *this,
        int nType,
        IResourceTypeConstructor *pConstructor)
{
  CResourceTypeManagerBase::Init(this, nType, pConstructor);
  if ( this->m_pConstructor == nullptr )
  {
    this->m_pConstructor = &s_DefaultAtomicConstructor;
    this->m_nMemoryLimit = ((int (*)(void))s_DefaultAtomicConstructor.GetDefaultMemoryLimit)();
  }
  this->m_pConstructor->Init(this: this->m_pConstructor, a2: this);
  this->m_nAlignment = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10008900
// Name: private: bool CResourceTypeManagerFileAtomic::AutoconvertedAllocatePermanent(void const __near *,unsigned int,class CResourceIntrospection const __near *,int,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CResourceTypeManagerFileAtomic::AutoconvertedAllocatePermanent@<al>(
        CResourceTypeManagerFileAtomic *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const void *pPermanentData,
        unsigned int nSrcDataSize,
        const CResourceIntrospection *pSrcIntroDct,
        int nResourceType,
        void **pOutResult,
        int a9,
        _DWORD *a10)
{
  void *v11; // eax
  const CResourceStructIntrospection *v13; // edi
  int v14; // eax
  _DWORD *v15; // esi
  void *v16; // eax
  void *v17; // eax
  int v19; // [esp+2Ch] [ebp-4h]

  if ( pSrcIntroDct != nullptr )
  {
    v13 = CResourceIntrospection::FindPermanentStructIntrospectionForResourceType(
            this: pSrcIntroDct,
            nType: nResourceType);
    v14 = ((int (__thiscall *)(IResourceSystem *, int, int, int))g_pResourceSystem->FindPermanentStructIntrospectionForResourceType)(
            a1: g_pResourceSystem,
            a2: nResourceType,
            a3,
            a4: a2);
    if ( v14 != 0 )
    {
      pOutResult = nullptr;
      a9 = 0;
      if ( ((unsigned __int8 (__thiscall *)(IResourceSystem *, const CResourceIntrospection *, int, const CResourceIntrospection *, const CResourceStructIntrospection *, int, void ***))g_pResourceSystem->UnpackIntrospectedBlock)(
             a1: g_pResourceSystem,
             a2: pSrcIntroDct,
             a3: nResourceType,
             a4: pSrcIntroDct,
             a5: v13,
             a6: v14,
             a7: &pOutResult) != 0 )
      {
        v17 = this->m_pConstructor->AllocatePermanentData(
                this: this->m_pConstructor,
                a2: pSrcIntroDct,
                a3: nResourceType);
        *pOutResult = v17;
        if ( v19 != 1 )
          MemAlloc_FreeAligned(pMemBlock: (unsigned int)pSrcIntroDct);
        return 1;
      }
      else
      {
        *pOutResult = nullptr;
        return 0;
      }
    }
    else
    {
      v15 = a10;
      *a10 = 0;
      v16 = this->m_pConstructor->AllocatePermanentData(this: this->m_pConstructor, a2: pSrcIntroDct, a3: nResourceType);
      *v15 = v16;
      if ( v16 != nullptr )
        _Warning(
          a1: "AllocatePermanentData for resource type %d even though no dest struct is specified.\n",
          nResourceType);
      return 1;
    }
  }
  else
  {
    v11 = this->m_pConstructor->AllocatePermanentData(this: this->m_pConstructor, a2: pPermanentData, a3: nSrcDataSize);
    *pOutResult = v11;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008A10
// Name: private: bool CResourceTypeManagerFileAtomic::AutoconvertedAllocate(void const __near *,void const __near *,unsigned int,class CResourceIntrospection const __near *,int,struct ResourceBindingBase_t const __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourceTypeManagerFileAtomic::AutoconvertedAllocate(
        CResourceTypeManagerFileAtomic *this,
        const void *pPermanentData,
        const void *pResourceData,
        unsigned int nSrcDataSize,
        const CResourceIntrospection *pSrcIntroDct,
        void *nResourceType,
        const ResourceBindingBase_t *hResourceHandle,
        void **pOutResult)
{
  const CResourceIntrospection *v8; // esi
  void *v9; // eax
  int v11; // edi
  const CResourceStructIntrospection *StructIntrospectionForResourceType; // ebx
  const CResourceStructIntrospection *v13; // eax
  void *v14; // eax
  bool v15; // zf
  int v17; // [esp+34h] [ebp-4h] BYREF

  v8 = pSrcIntroDct;
  if ( pSrcIntroDct != nullptr )
  {
    v11 = (int)nResourceType;
    StructIntrospectionForResourceType = CResourceIntrospection::FindStructIntrospectionForResourceType(
                                           this: pSrcIntroDct,
                                           nType: (int)nResourceType);
    v13 = g_pResourceSystem->FindStructIntrospectionForResourceType(this: g_pResourceSystem, a2: v11);
    nResourceType = nullptr;
    pSrcIntroDct = nullptr;
    if ( g_pResourceSystem->UnpackIntrospectedBlock(
           this: g_pResourceSystem,
           a2: pResourceData,
           a3: nSrcDataSize,
           a4: v8,
           a5: StructIntrospectionForResourceType,
           a6: v13,
           a7: (const void **)&nResourceType,
           a8: (int *)&pSrcIntroDct,
           a9: (IntrospectionCompatibilityType_t *)&v17) )
    {
      v14 = this->m_pConstructor->Allocate(
              this: this->m_pConstructor,
              a2: pPermanentData,
              a3: pResourceData,
              a4: pSrcIntroDct,
              a5: hResourceHandle);
      v15 = v17 == 1;
      *pOutResult = v14;
      if ( !v15 )
        g_pAsyncFileSystem->ReleaseBuffer(this: g_pAsyncFileSystem, a2: nResourceType);
      return 1;
    }
    else
    {
      *pOutResult = nullptr;
      return 0;
    }
  }
  else
  {
    v9 = this->m_pConstructor->Allocate(
           this: this->m_pConstructor,
           a2: pPermanentData,
           a3: pResourceData,
           a4: nSrcDataSize,
           a5: hResourceHandle);
    *pOutResult = v9;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008B10
// Name: private: static int CResourceTypeManagerFileAtomic::ResourceSizeComparisonFunc(struct CResourceTypeManagerFileAtomic::ToCacheHandle_t const __near *,struct CResourceTypeManagerFileAtomic::ToCacheHandle_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CResourceTypeManagerFileAtomic::ResourceSizeComparisonFunc(
        const CResourceTypeManagerFileAtomic::ToCacheHandle_t *pLeft,
        const CResourceTypeManagerFileAtomic::ToCacheHandle_t *pRight)
{
  unsigned int m_nSize; // eax
  unsigned int v4; // ecx

  if ( pLeft->m_bWasRequested )
  {
    if ( !pRight->m_bWasRequested )
      return -1;
  }
  else if ( pRight->m_bWasRequested )
  {
    return 1;
  }
  m_nSize = pLeft->m_nSize;
  v4 = pRight->m_nSize;
  if ( v4 > m_nSize )
    return -1;
  return v4 < m_nSize;
}

//------------------------------------------------------------------------------
// Address: 0x10008B50
// Name: public: void CUtlTSHash<struct CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,class CUtlTSHashGenericHash<1021,unsigned int>,0>::Commit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Commit(
        CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi

  if ( this->m_bNeedsCommit )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 1021; i != 0; --i )
    {
      CThreadSpinRWLock::LockForRead(this: p_m_AddLock);
      p_m_AddLock[-1].m_nWriters.m_value = *((_DWORD *)&p_m_AddLock[-1].m_nWriters + 1);
      CThreadSpinRWLock::UnlockRead(this: p_m_AddLock);
      p_m_AddLock = (CThreadSpinRWLock *)((char *)p_m_AddLock + 24);
    }
    this->m_bNeedsCommit = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008BA0
// Name: public: int CUtlTSHash<struct CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,class CUtlTSHashGenericHash<1021,unsigned int>,0>::GetElements(int,int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::GetElements(
        CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0> *this,
        int nFirstElement,
        int nCount,
        int *pHandles)
{
  int v4; // esi
  int v5; // ebx
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> **i; // edi
  int v7; // eax

  v4 = 0;
  v5 = 0;
  for ( i = &this->m_aBuckets[0].m_pFirstUncommitted; ; i += 6 )
  {
    CThreadSpinRWLock::LockForRead(this: (CThreadSpinRWLock *)(i + 1));
    v7 = (int)*i;
    if ( *i != nullptr )
      break;
LABEL_6:
    CThreadSpinRWLock::UnlockRead(this: (CThreadSpinRWLock *)(i + 1));
    if ( ++v5 >= 1021 )
      return v4;
  }
  while ( 1 )
  {
    if ( --nFirstElement < 0 )
    {
      pHandles[v4++] = v7;
      if ( v4 >= nCount )
        break;
    }
    v7 = *(_DWORD *)(v7 + 4);
    if ( v7 == 0 )
      goto LABEL_6;
  }
  CThreadSpinRWLock::UnlockRead(this: (CThreadSpinRWLock *)(i + 1));
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10008C10
// Name: public: void CMemoryPoolMT::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryPoolMT::Free(CMemoryPoolMT *this, void *pMem)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

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
  CUtlMemoryPool::Free(this, memBlock: pMem);
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10008C70
// Name: public: virtual bool CDefaultFileAtomicConstructor::Init(class IResourceTypeManager __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDefaultFileAtomicConstructor::Init(
        CDefaultFileAtomicConstructor *this,
        IResourceTypeManager *pTypeManager)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008C80
// Name: public: virtual void __near * CDefaultFileAtomicConstructor::AllocatePermanentData(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDefaultFileAtomicConstructor::AllocatePermanentData(
        CDefaultFileAtomicConstructor *this,
        const void *pDataFromDisk,
        unsigned int nDataSize)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008C90
// Name: public: virtual unsigned int CDefaultFileAtomicConstructor::GetDefaultMemoryLimit(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDefaultFileAtomicConstructor::GetDefaultMemoryLimit(CDefaultFileAtomicConstructor *this)
{
  return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x10008CA0
// Name: public: virtual void __near * CDefaultFileAtomicConstructor::Allocate(void const __near *,void const __near *,unsigned int,struct ResourceBindingBase_t const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CDefaultFileAtomicConstructor::Allocate(
        CDefaultFileAtomicConstructor *this,
        const void *pPermanentData,
        unsigned __int8 *pResourceData,
        unsigned int nDataSize,
        const ResourceBindingBase_t *hResourceHandle)
{
  void *v5; // eax
  unsigned __int8 *v6; // esi

  v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nDataSize + 19);
  if ( v5 != nullptr )
  {
    *(_DWORD *)((((unsigned int)v5 + 19) & 0xFFFFFFF0) - 4) = v5;
    v6 = (unsigned __int8 *)(((unsigned int)v5 + 19) & 0xFFFFFFF0);
  }
  else
  {
    v6 = nullptr;
  }
  memcpy(dst: v6, src: pResourceData, count: nDataSize);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10008CF0
// Name: public: virtual void CDefaultFileAtomicConstructor::Deallocate(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultFileAtomicConstructor::Deallocate(CDefaultFileAtomicConstructor *this, unsigned int pClass)
{
  if ( pClass != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((pClass & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x10008D20
// Name: public: virtual unsigned int CResourceTypeManagerFileAtomic::GetResourceId(struct ResourceBindingBase_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
const ResourceBindingBase_t *__thiscall CResourceTypeManagerFileAtomic::GetResourceId(
        CResourceTypeManagerFileAtomic *this,
        const ResourceBindingBase_t *hResource)
{
  const ResourceBindingBase_t *result; // eax

  result = hResource;
  if ( hResource != nullptr )
    return (const ResourceBindingBase_t *)hResource[-1].m_nFlags;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008D40
// Name: public: virtual int CResourceTypeManagerFileAtomic::GetResourceCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceTypeManagerFileAtomic::GetResourceCount(CResourceTypeManagerFileAtomic *this)
{
  return this->m_IdMap.m_EntryMemory.m_BlocksAllocated;
}

//------------------------------------------------------------------------------
// Address: 0x10008D50
// Name: public: virtual int CResourceTypeManagerFileAtomic::GetResources(int,int,struct ResourceBindingBase_t const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceTypeManagerFileAtomic::GetResources(
        CResourceTypeManagerFileAtomic *this,
        int nFirst,
        int nCount,
        const ResourceBindingBase_t **pResources)
{
  int result; // eax
  int i; // ecx

  result = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::GetElements(
             this: &this->m_IdMap,
             nFirstElement: nFirst,
             nCount,
             pHandles: (int *)pResources);
  for ( i = 0; i < result; ++i )
    pResources[i] = (const ResourceBindingBase_t *)((char *)pResources[i] + 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008D80
// Name: private: void CResourceTypeManagerFileAtomic::M_UncacheResource(struct CResourceTypeManagerFileAtomic::ResourceData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::M_UncacheResource(
        CResourceTypeManagerFileAtomic *this,
        CResourceTypeManagerFileAtomic::ResourceData_t *pResourceData)
{
  if ( pResourceData->m_Resource.m_nRefCount.m_value <= 0 || (pResourceData->m_Resource.m_nFlags & 4) == 0 )
  {
    if ( pResourceData->m_Resource.m_pData != nullptr && (pResourceData->m_Resource.m_nFlags & 2) == 0 )
    {
      this->m_nMemoryUsed -= pResourceData->m_nSize;
      this->m_pConstructor->Deallocate(this: this->m_pConstructor, a2: pResourceData->m_Resource.m_pData);
    }
    pResourceData->m_Resource.m_nFlags &= 0xFFFFFFFC;
    pResourceData->m_Resource.m_pData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008DC0
// Name: private: static bool CResourceTypeManagerFileAtomic::SortLessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CResourceTypeManagerFileAtomic::SortLessFunc(const int *left, const int *right)
{
  bool result; // al

  result = *(_BYTE *)(*left + 16) & 1;
  if ( result == (*(_BYTE *)(*right + 16) & 1) )
  {
    if ( (*(_DWORD *)(*left + 20) != 0) == (*(_DWORD *)(*right + 20) != 0) )
      return *(_DWORD *)(*left + 12) < *(_DWORD *)(*right + 12);
    else
      return *(_DWORD *)(*left + 20) == 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008E10
// Name: public: CTSQueue<struct ResourceBindingBase_t const __near *,0>::CTSQueue<struct ResourceBindingBase_t const __near *,0>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<ResourceBindingBase_t const *,0> *__thiscall CTSQueue<ResourceBindingBase_t const *,0>::CTSQueue<ResourceBindingBase_t const *,0>(
        CTSQueue<ResourceBindingBase_t const *,0> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CInterlockedIntT<int> *p_m_Count; // edi
  CTSQueue<ResourceBindingBase_t const *,0>::Node_t *v4; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  p_m_Count = &this->m_Count;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  HIDWORD(p_m_FreeNodes->m_Head.value64) = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&p_m_Count->m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v4 = (CTSQueue<ResourceBindingBase_t const *,0>::Node_t *)operator new(nSize: 8u);
  this->m_Tail.value.pNode = v4;
  this->m_Head.value.pNode = v4;
  v4->pNext = (CTSQueue<ResourceBindingBase_t const *,0>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008EA0
// Name: public: CTSQueue<struct CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::CTSQueue<struct CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0> *__thiscall CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>(
        CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CInterlockedIntT<int> *p_m_Count; // edi
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *v4; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  p_m_Count = &this->m_Count;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  HIDWORD(p_m_FreeNodes->m_Head.value64) = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&p_m_Count->m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v4 = (CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *)operator new(nSize: 0x18u);
  this->m_Tail.value.pNode = v4;
  this->m_Head.value.pNode = v4;
  v4->pNext = (CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008F30
// Name: public: virtual void CResourceTypeManagerFactory<class CResourceTypeManagerFileAtomic>::Destroy(class CResourceTypeManagerBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFactory<CResourceTypeManagerFileAtomic>::Destroy(
        CResourceTypeManagerFactory<CResourceTypeManagerFileAtomic> *this,
        CResourceTypeManagerBase *pFactory)
{
  if ( pFactory != nullptr )
    ((void (__thiscall *)(CResourceTypeManagerBase *, int))pFactory->dtr_CResourceTypeManagerBase)(a1: pFactory, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10008F50
// Name: public: CUtlTSHash<struct CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,class CUtlTSHashGenericHash<1021,unsigned int>,0>::CUtlTSHash<struct CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,class CUtlTSHashGenericHash<1021,unsigned int>,0>(int)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0> *__thiscall CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>(
        CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0> *this,
        int nAllocationCount)
{
  int v3; // ebp
  CThreadSpinRWLock *p_m_AddLock; // edi
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashBucket_t *m_aBuckets; // eax
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_EntryMemory,
    blockSize: 36,
    numElements: nAllocationCount,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 1020;
  p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
  do
  {
    CThreadSpinRWLock::CThreadSpinRWLock(this: p_m_AddLock);
    p_m_AddLock = (CThreadSpinRWLock *)((char *)p_m_AddLock + 24);
    --v3;
  }
  while ( v3 >= 0 );
  this->m_bNeedsCommit = false;
  m_aBuckets = this->m_aBuckets;
  for ( i = 1021; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008FC0
// Name: public: int CUtlTSHash<struct CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,class CUtlTSHashGenericHash<1021,unsigned int>,0>::Find(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *__thiscall CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Find(
        CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0> *this,
        unsigned int uiKey)
{
  unsigned int v2; // edx
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashBucket_t *v3; // esi
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *result; // eax
  CThreadSpinRWLock *p_m_AddLock; // edi
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *m_pFirstUncommitted; // eax
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *m_pFirst; // esi
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v8; // esi

  v2 = ((unsigned __int16)(HIBYTE(uiKey)
                         + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))
      ^ ((HIBYTE(uiKey)
        + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16))
     & 0x3FC;
  v3 = &this->m_aBuckets[v2];
  result = v3->m_pFirst;
  if ( v3->m_pFirst != nullptr )
  {
    while ( result->m_uiKey != uiKey )
    {
      result = result->m_pNext;
      if ( result == nullptr )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    p_m_AddLock = &this->m_aBuckets[v2].m_AddLock;
    CThreadSpinRWLock::LockForRead(this: p_m_AddLock);
    m_pFirstUncommitted = v3->m_pFirstUncommitted;
    m_pFirst = v3->m_pFirst;
    if ( m_pFirstUncommitted == m_pFirst )
    {
LABEL_7:
      CThreadSpinRWLock::UnlockRead(this: p_m_AddLock);
      return nullptr;
    }
    else
    {
      while ( m_pFirstUncommitted->m_uiKey != uiKey )
      {
        m_pFirstUncommitted = m_pFirstUncommitted->m_pNext;
        if ( m_pFirstUncommitted == m_pFirst )
          goto LABEL_7;
      }
      v8 = m_pFirstUncommitted;
      CThreadSpinRWLock::UnlockRead(this: p_m_AddLock);
      return v8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009070
// Name: public: void CUtlTSHash<struct CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,class CUtlTSHashGenericHash<1021,unsigned int>,0>::FindAndRemove(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::FindAndRemove(
        CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0> *this,
        unsigned int uiKey)
{
  unsigned __int16 v3; // ax
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashBucket_t *v4; // esi
  CThreadSpinRWLock *p_m_AddLock; // edi
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *m_pFirstUncommitted; // eax
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v7; // ecx

  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    v3 = HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846)));
    v4 = &this->m_aBuckets[(v3
                          ^ ((HIBYTE(uiKey)
                            + 33
                            * (BYTE2(uiKey)
                             + 33 * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16))
                         & 0x3FC];
    p_m_AddLock = &this->m_aBuckets[(v3
                                   ^ ((HIBYTE(uiKey)
                                     + 33
                                     * (BYTE2(uiKey)
                                      + 33 * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16))
                                  & 0x3FC].m_AddLock;
    CThreadSpinRWLock::LockForWrite(this: p_m_AddLock);
    m_pFirstUncommitted = v4->m_pFirstUncommitted;
    v7 = nullptr;
    if ( m_pFirstUncommitted != nullptr )
    {
      while ( m_pFirstUncommitted->m_uiKey != uiKey )
      {
        v7 = m_pFirstUncommitted;
        m_pFirstUncommitted = m_pFirstUncommitted->m_pNext;
        if ( m_pFirstUncommitted == nullptr )
          goto LABEL_12;
      }
      if ( v7 != nullptr )
        v7->m_pNext = m_pFirstUncommitted->m_pNext;
      else
        v4->m_pFirstUncommitted = m_pFirstUncommitted->m_pNext;
      if ( v4->m_pFirst == m_pFirstUncommitted )
        v4->m_pFirst = v4->m_pFirst->m_pNext;
      CMemoryPoolMT::Free(this: &this->m_EntryMemory, pMem: m_pFirstUncommitted);
    }
LABEL_12:
    CThreadSpinRWLock::UnlockWrite(this: p_m_AddLock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009140
// Name: public: void CUtlTSHash<struct CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,class CUtlTSHashGenericHash<1021,unsigned int>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::RemoveAll(
        CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0> *this)
{
  bool v1; // zf
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> **p_m_pFirstUncommitted; // esi
  int i; // edi
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  v1 = this->m_EntryMemory.m_BlocksAllocated == 0;
  this->m_bNeedsCommit = false;
  if ( !v1 )
  {
    p_m_pFirstUncommitted = &this->m_aBuckets[0].m_pFirstUncommitted;
    for ( i = 1021; i != 0; --i )
    {
      CThreadSpinRWLock::LockForWrite(this: (CThreadSpinRWLock *)(p_m_pFirstUncommitted + 1));
      for ( j = *p_m_pFirstUncommitted; j != nullptr; j = j->m_pNext )
        ;
      *(p_m_pFirstUncommitted - 1) = nullptr;
      *p_m_pFirstUncommitted = nullptr;
      CThreadSpinRWLock::UnlockWrite(this: (CThreadSpinRWLock *)(p_m_pFirstUncommitted + 1));
      p_m_pFirstUncommitted += 6;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    v1 = this->m_EntryMemory.m_mutex.m_depth-- == 1;
    if ( v1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100091F0
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x10009200
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10009210
// Name: __heap_term
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall _heap_term(CResourceTypeManagerBase *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10009230
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x10009240
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
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
// Address: 0x100092A0
// Name: public: CFunctorJob::CFunctorJob(class CFunctor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFunctorJob *__thiscall CFunctorJob::CFunctorJob(CFunctorJob *this, CFunctor *pFunctor, const char *pszDescription)
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
// Address: 0x10009320
// Name: public: virtual char const __near * CFunctorJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFunctorJob::Describe(CFunctorJob *this)
{
  return this->m_szDescription;
}

//------------------------------------------------------------------------------
// Address: 0x10009340
// Name: public: virtual int CFunctorJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFunctorJob::DoExecute(CFunctorJob *this)
{
  this->m_pFunctor.m_pObject->operator()(this: this->m_pFunctor.m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009380
// Name: public: virtual struct ResourceBindingBase_t const __near * CResourceTypeManagerFileAtomic::FindResource(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *__thiscall CResourceTypeManagerFileAtomic::FindResource(
        CResourceTypeManagerFileAtomic *this,
        unsigned int nResourceId)
{
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *result; // eax

  result = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Find(
             this: &this->m_IdMap,
             uiKey: nResourceId);
  if ( result != nullptr )
    return (CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *)((char *)result + 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100093A0
// Name: public: virtual bool CResourceTypeManagerFileAtomic::IsFileHandleDefined(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CResourceTypeManagerFileAtomic::IsFileHandleDefined(
        CResourceTypeManagerFileAtomic *this,
        unsigned int id)
{
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v3; // eax

  return id != 0
      && (v3 = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Find(
                 this: &this->m_IdMap,
                 uiKey: id)) != nullptr
      && v3->m_Data.m_hFile != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100093D0
// Name: public: virtual void CResourceTypeManagerFileAtomic::MarkResourceIdNotResolveable(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::MarkResourceIdNotResolveable(
        CResourceTypeManagerFileAtomic *this,
        unsigned int id)
{
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v3; // esi

  v3 = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Find(
         this: &this->m_IdMap,
         uiKey: id);
  v3->m_Data.m_Resource.m_nFlags |= 0x22u;
  v3->m_Data.m_Resource.m_pData = this->m_pConstructor->GetErrorResource(
                                    this: this->m_pConstructor,
                                    a2: v3->m_Data.m_pPermanentData);
}

//------------------------------------------------------------------------------
// Address: 0x10009400
// Name: public: struct CTSQueue<struct ResourceBindingBase_t const __near *,0>::Node_t __near * CTSQueue<struct ResourceBindingBase_t const __near *,0>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<ResourceBindingBase_t const *,0>::Node_t *__thiscall CTSQueue<ResourceBindingBase_t const *,0>::Pop(
        CTSQueue<ResourceBindingBase_t const *,0> *this)
{
  CTSQueue<ResourceBindingBase_t const *,0> *v1; // esi
  CTSQueue<ResourceBindingBase_t const *,0> *pNext; // eax
  const ResourceBindingBase_t *sequence; // edi
  CTSQueue<ResourceBindingBase_t const *,0>::NodeLink_t *p_m_Tail; // [esp+64h] [ebp-1Ch]
  int *p_sequence; // [esp+68h] [ebp-18h]
  CTSQueue<ResourceBindingBase_t const *,0>::NodeLink_t *v8; // [esp+70h] [ebp-10h]
  CTSQueue<ResourceBindingBase_t const *,0>::Node_t *pNode; // [esp+78h] [ebp-8h]

  v1 = this;
  p_m_Tail = &this->m_Tail;
  p_sequence = &this->m_Head.value.sequence;
  v8 = &this->m_Tail;
  while ( 1 )
  {
    do
    {
      while ( 1 )
      {
        do
        {
          pNode = v1->m_Head.value.pNode;
          pNext = (CTSQueue<ResourceBindingBase_t const *,0> *)v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( pNode != v8->value.pNode )
          break;
        if ( pNext == v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: p_m_Tail->value.sequence + 1,
          a4: pNode,
          a5: p_m_Tail->value.sequence);
      }
    }
    while ( pNext == v1 );
    sequence = (const ResourceBindingBase_t *)pNext->m_Head.value.sequence;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: pNext,
                            a3: *p_sequence + 1,
                            a4: pNode,
                            a5: *p_sequence) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  pNode->elem = sequence;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x100094E0
// Name: public: struct CTSQueue<struct ResourceBindingBase_t const __near *,0>::Node_t __near * CTSQueue<struct ResourceBindingBase_t const __near *,0>::Push(struct CTSQueue<struct ResourceBindingBase_t const __near *,0>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *__thiscall CTSQueue<ResourceBindingBase_t const *,0>::Push(
        CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *this,
        CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *pNode)
{
  int sequence; // ecx
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *i; // edi

  pNode->pNext = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)this;
  sequence = this->m_Tail.value.sequence;
  for ( i = this->m_Tail.value.pNode;
        (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *)_InterlockedCompareExchange(
                                                                        (volatile signed __int32 *)i,
                                                                        (signed __int32)pNode,
                                                                        (signed __int32)this) != this;
        sequence = this->m_Tail.value.sequence )
  {
    _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: i->pNext, a3: sequence + 1, a4: i, a5: sequence);
    i = this->m_Tail.value.pNode;
  }
  _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: pNode, a3: sequence + 1, a4: i, a5: sequence);
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10009560
// Name: public: struct CTSQueue<struct CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t __near * CTSQueue<struct CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *__thiscall CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Pop(
        CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0> *this)
{
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *pNext; // eax
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::NodeLink_t *p_m_Tail; // [esp+C0h] [ebp-28h]
  int *p_sequence; // [esp+C4h] [ebp-24h]
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::NodeLink_t *v6; // [esp+C8h] [ebp-20h]
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *pNode; // [esp+D0h] [ebp-18h]
  __int64 v9; // [esp+D8h] [ebp-10h]
  __int64 v10; // [esp+E0h] [ebp-8h]

  p_m_Tail = &this->m_Tail;
  p_sequence = &this->m_Head.value.sequence;
  v6 = &this->m_Tail;
  while ( 1 )
  {
    while ( 1 )
    {
      do
      {
        pNode = this->m_Head.value.pNode;
        pNext = this->m_Head.value.pNode->pNext;
      }
      while ( pNext == nullptr );
      if ( pNode == v6->value.pNode )
        break;
      if ( pNext != (CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *)this )
      {
        v9 = *(_QWORD *)pNext->elem.m_pBuffer;
        v10 = *(_QWORD *)&pNext->elem.m_pBuffer[8];
        if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                a1: this,
                                a2: pNext,
                                a3: *p_sequence + 1,
                                a4: pNode,
                                a5: *p_sequence) != 0 )
        {
          _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
          *(_QWORD *)pNode->elem.m_pBuffer = v9;
          *(_QWORD *)&pNode->elem.m_pBuffer[8] = v10;
          return pNode;
        }
      }
    }
    if ( pNext == (CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *)this )
      break;
    _ThreadInterlockedAssignIf64(
      a1: &this->m_Tail,
      a2: pNext,
      a3: p_m_Tail->value.sequence + 1,
      a4: pNode,
      a5: p_m_Tail->value.sequence);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10009650
// Name: public: int CUtlTSHash<struct CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,class CUtlTSHashGenericHash<1021,unsigned int>,0>::Insert(unsigned int,struct CResourceTypeManagerFileAtomic::ResourceData_t const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *__thiscall CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Insert(
        CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0> *this,
        unsigned int uiKey,
        const CResourceTypeManagerFileAtomic::ResourceData_t *data,
        bool *pDidInsert)
{
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashBucket_t *v5; // esi
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *result; // eax
  CThreadSpinRWLock *p_m_AddLock; // ebp
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *m_pFirstUncommitted; // eax
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v9; // eax
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v10; // esi
  CResourceTypeManagerFileAtomic::ResourceData_t *p_m_Data; // eax
  CThreadSpinRWLock *v12; // ecx
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v13; // esi

  if ( pDidInsert != nullptr )
    *pDidInsert = false;
  v5 = &this->m_aBuckets[((unsigned __int16)(HIBYTE(uiKey)
                                           + 33
                                           * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))
                        ^ ((HIBYTE(uiKey)
                          + 33
                          * (BYTE2(uiKey)
                           + 33 * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16))
                       & 0x3FC];
  result = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Find(
             this,
             uiKey);
  if ( result == nullptr )
  {
    p_m_AddLock = &v5->m_AddLock;
    CThreadSpinRWLock::LockForWrite(this: &v5->m_AddLock);
    m_pFirstUncommitted = v5->m_pFirstUncommitted;
    if ( m_pFirstUncommitted == v5->m_pFirst )
    {
LABEL_7:
      this->m_bNeedsCommit = true;
      v9 = (CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *)CMemoryPoolMT::Alloc(this: &this->m_EntryMemory);
      v9->m_pNext = v5->m_pFirstUncommitted;
      v5->m_pFirstUncommitted = v9;
      v9->m_uiKey = uiKey;
      v10 = v9;
      p_m_Data = &v9->m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = *data;
      if ( pDidInsert != nullptr )
        *pDidInsert = true;
      CThreadSpinRWLock::UnlockWrite(this: p_m_AddLock);
      return v10;
    }
    else
    {
      while ( m_pFirstUncommitted->m_uiKey != uiKey )
      {
        m_pFirstUncommitted = m_pFirstUncommitted->m_pNext;
        if ( m_pFirstUncommitted == v5->m_pFirst )
          goto LABEL_7;
      }
      v12 = &v5->m_AddLock;
      v13 = m_pFirstUncommitted;
      CThreadSpinRWLock::UnlockWrite(this: v12);
      return v13;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009760
// Name: public: int CUtlVector<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,class CUtlMemory<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::Find(struct CResourceTypeManagerFileAtomic::ToCacheHandle_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::Find(
        CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int> > *this,
        const CResourceTypeManagerFileAtomic::ToCacheHandle_t *src)
{
  int m_Size; // edx
  int result; // eax
  CResourceTypeManagerFileAtomic::ToCacheHandle_t *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; src->m_hResource != i->m_hResource; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009790
// Name: public: void CUtlVector<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,class CUtlMemory<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::Sort(int (*)(struct CResourceTypeManagerFileAtomic::ToCacheHandle_t const __near *,struct CResourceTypeManagerFileAtomic::ToCacheHandle_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::Sort(
        CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // eax
  CResourceTypeManagerFileAtomic::ToCacheHandle_t *m_pMemory; // ecx
  bool v5; // sf
  int v6; // eax
  int v7; // esi
  int i; // ebx
  __int64 v9; // xmm0_8
  CResourceTypeManagerFileAtomic::ToCacheHandle_t *v10; // eax
  int v11; // ecx
  int v12; // [esp+4h] [ebp-4h]

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
      v5 = m_Size - 1 < 0;
      v6 = m_Size - 1;
      v12 = v6;
      if ( !v5 )
      {
        do
        {
          if ( v6 >= 1 )
          {
            v7 = 1;
            for ( i = v6; i != 0; --i )
            {
              if ( pfnCompare(a1: &this->m_Memory.m_pMemory[v7 - 1], a2: &this->m_Memory.m_pMemory[v7]) < 0 )
              {
                v9 = *(_QWORD *)&this->m_Memory.m_pMemory[v7 - 1].m_hResource;
                v10 = &this->m_Memory.m_pMemory[v7];
                v11 = *(_DWORD *)&v10[-1].m_bWasRequested;
                *(_QWORD *)&v10[-1].m_hResource = *(_QWORD *)&v10->m_hResource;
                *(_DWORD *)&v10[-1].m_bWasRequested = *(_DWORD *)&v10->m_bWasRequested;
                *(_QWORD *)&v10->m_hResource = v9;
                *(_DWORD *)&v10->m_bWasRequested = v11;
              }
              ++v7;
            }
            v6 = v12;
          }
          v12 = --v6;
        }
        while ( v6 >= 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009850
// Name: public: virtual void CMemberFunctor3<class CResourceTypeManagerFileAtomic __near *,void (CResourceTypeManagerFileAtomic::*)(class IAsyncFileRequest __near *,struct ResourceBindingBase_t const __near *,void __near *),class IAsyncFileRequest __near *,struct ResourceBindingBase_t const __near *,void __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor3<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(IAsyncFileRequest *,ResourceBindingBase_t const *,void *),IAsyncFileRequest *,ResourceBindingBase_t const *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor3<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(IAsyncFileRequest *,ResourceBindingBase_t const *,void *),IAsyncFileRequest *,ResourceBindingBase_t const *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1, a3: this->m_arg2, a4: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x10009870
// Name: public: virtual void CMemberFunctor4<class CResourceTypeManagerFileAtomic __near *,void (CResourceTypeManagerFileAtomic::*)(class IAsyncFileRequest __near *,struct ResourceBindingBase_t const __near *,void __near *,void __near *),class IAsyncFileRequest __near *,struct ResourceBindingBase_t const __near *,void __near *,void __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor4<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(IAsyncFileRequest *,ResourceBindingBase_t const *,void *,void *),IAsyncFileRequest *,ResourceBindingBase_t const *,void *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor4<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(ResourceBindingBase_t const *,void *,void const *,void const *),ResourceBindingBase_t const *,void *,void *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x100098B0
// Name: public: virtual struct ResourceBindingBase_t const __near * CResourceTypeManagerFileAtomic::FindOrCreateResource(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CResourceTypeManagerFileAtomic::ResourceData_t *__thiscall CResourceTypeManagerFileAtomic::FindOrCreateResource(
        CResourceTypeManagerFileAtomic *this,
        const char *pFileName,
        const char *pSubResourceName)
{
  unsigned int v4; // ebx
  CResourceTypeManagerFileAtomic::ResourceData_t *p_m_Data; // edi
  unsigned int v6; // eax

  v4 = ComputeResourceIdHash(pFileName, pSubResourceName);
  p_m_Data = &CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Insert(
                this: &this->m_IdMap,
                uiKey: v4,
                data: &CResourceTypeManagerFileAtomic::sm_DefaultResourceData,
                pDidInsert: (bool *)&pSubResourceName)->m_Data;
  if ( (_BYTE)pSubResourceName != 0 )
  {
    p_m_Data->m_Resource.m_pData = (void *)((int (__thiscall *)(IResourceTypeConstructor *))this->m_pConstructor->GetFallback)(a1: this->m_pConstructor);
    v6 = ((int (__thiscall *)(CResourceTypeManagerFileAtomic *, unsigned int))this->GetResourceType)(a1: this, a2: v4);
    CResourceSystem::SubmitFileIdResolutionRequest(this: g_pResourceSystemImp, pFileName, nType: v6, nId: 0);
  }
  return p_m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x10009920
// Name: public: virtual struct ResourceBindingBase_t const __near * CResourceTypeManagerFileAtomic::FindResourceForReferenceFixup(unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
CResourceTypeManagerFileAtomic::ResourceData_t *__thiscall CResourceTypeManagerFileAtomic::FindResourceForReferenceFixup(
        CResourceTypeManagerFileAtomic *this,
        unsigned int nResourceId,
        const ResourceFileHeader_t *pDct)
{
  CResourceTypeManagerFileAtomic *v3; // ebp
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v4; // eax
  int *Block; // eax
  int *v7; // ebx
  char *v8; // esi
  int v9; // edi
  int v10; // edx
  int v11; // ebx
  _DWORD *v12; // esi
  int v13; // ecx
  unsigned int *v14; // eax
  int v15; // esi
  int v16; // edi
  unsigned int v17; // eax
  unsigned int v18; // [esp-Ch] [ebp-24h]
  const ResourceExtRefList_t *pList; // [esp+8h] [ebp-10h]
  int *v20; // [esp+Ch] [ebp-Ch]
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0> *p_m_IdMap; // [esp+14h] [ebp-4h]
  char *pDcta; // [esp+20h] [ebp+8h]

  v3 = this;
  p_m_IdMap = &this->m_IdMap;
  v4 = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Find(
         this: &this->m_IdMap,
         uiKey: nResourceId);
  if ( v4 != nullptr )
    return &v4->m_Data;
  Block = (int *)Resource_GetBlock(pHeader: pDct, id: 0x4C524552u);
  v7 = Block;
  v20 = Block;
  if ( Block == nullptr )
    return nullptr;
  pList = nullptr;
  if ( Block[2] <= 0 )
    return nullptr;
  for ( pDcta = nullptr; ; pDcta += 12 )
  {
    v8 = &pDcta[v7[1] + (_DWORD)(v7 + 1)];
    if ( *(_DWORD *)v8 == v3->GetResourceType(this: v3) )
    {
      v9 = *((_DWORD *)v8 + 2);
      v10 = 0;
      if ( v9 > 0 )
        break;
    }
LABEL_13:
    pList = (const ResourceExtRefList_t *)((char *)pList + 1);
    if ( (int)pList >= v7[2] )
      return nullptr;
  }
  v11 = *((_DWORD *)v8 + 1);
  v12 = v8 + 4;
  v13 = 0;
  while ( 1 )
  {
    v14 = (_DWORD *)((char *)&v12[v13] + v11);
    if ( *v14 == nResourceId )
      break;
    ++v10;
    v13 += 3;
    if ( v10 >= v9 )
    {
      v3 = this;
      v7 = v20;
      goto LABEL_13;
    }
  }
  v15 = v20[3] + 4 * v14[1];
  v16 = *(int *)((char *)v20 + v15 + 12);
  v18 = *v14;
  v17 = this->GetResourceType(this);
  CResourceSystem::SubmitFileIdResolutionRequest(
    this: g_pResourceSystemImp,
    pFileName: (const char *)v20 + v15 + v16 + 12,
    nType: v17,
    nId: v18);
  return &CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Insert(
            this: p_m_IdMap,
            uiKey: nResourceId,
            data: &CResourceTypeManagerFileAtomic::sm_DefaultResourceData,
            pDidInsert: nullptr)->m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x10009A40
// Name: public: void CTSQueue<struct ResourceBindingBase_t const __near *,0>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<ResourceBindingBase_t const *,0>::Purge(CTSQueue<ResourceBindingBase_t const *,0> *this)
{
  CTSQueue<ResourceBindingBase_t const *,0>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int value64_high; // eax

  for ( i = CTSQueue<ResourceBindingBase_t const *,0>::Pop(this);
        i != nullptr;
        i = CTSQueue<ResourceBindingBase_t const *,0>::Pop(this) )
  {
    free(pMem: i);
  }
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &this->m_FreeNodes,
                               a2: Next->Next,
                               a3: value64_high - 1,
                               a4: Next,
                               a5: value64_high) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
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
// Address: 0x10009AC0
// Name: public: void CTSQueue<struct CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Purge(
        CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0> *this)
{
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int value64_high; // eax

  for ( i = CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Pop(this);
        i != nullptr;
        i = CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Pop(this) )
  {
    free(pMem: i);
  }
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &this->m_FreeNodes,
                               a2: Next->Next,
                               a3: value64_high - 1,
                               a4: Next,
                               a5: value64_high) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
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
// Address: 0x10009B40
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

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
// Address: 0x10009BB0
// Name: class CFunctor __near * CreateFunctor<class CResourceTypeManagerFileAtomic __near *,class CResourceTypeManagerFileAtomic,void,struct ResourceBindingBase_t const __near *,void __near *,void const __near *,void const __near *,struct ResourceBindingBase_t const __near *,void __near *,void __near *,void __near *>(class CResourceTypeManagerFileAtomic __near *,void (CResourceTypeManagerFileAtomic::*)(struct ResourceBindingBase_t const __near *,void __near *,void const __near *,void const __near *),struct ResourceBindingBase_t const __near * const __near &,void __near * const __near &,void __near * const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__cdecl CreateFunctor<CResourceTypeManagerFileAtomic *,CResourceTypeManagerFileAtomic,void,ResourceBindingBase_t const *,void *,void const *,void const *,ResourceBindingBase_t const *,void *,void *,void *>(
        CResourceTypeManagerFileAtomic *pObject,
        void (__thiscall *pfnProxied)(CResourceTypeManagerFileAtomic *this, const ResourceBindingBase_t *, void *, const void *, const void *),
        CFunctor_vtbl **arg1,
        void *const *arg2,
        CFunctor_vtbl **arg3,
        void *const *arg4)
{
  CFunctor *result; // eax

  result = (CFunctor *)operator new(nSize: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result[1].m_nUserID = 1;
  result->__vftable = (CFunctor_vtbl *)&CMemberFunctor4<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(ResourceBindingBase_t const *,void *,void const *,void const *),ResourceBindingBase_t const *,void *,void *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  result[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor4<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(ResourceBindingBase_t const *,void *,void const *,void const *),ResourceBindingBase_t const *,void *,void *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  result[2].__vftable = (CFunctor_vtbl *)pfnProxied;
  result[2].m_nUserID = (unsigned int)pObject;
  result[3].__vftable = *arg1;
  result[3].m_nUserID = (unsigned int)*arg2;
  result[4].__vftable = *arg3;
  result[4].m_nUserID = (unsigned int)*arg4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009C10
// Name: public: virtual void CResourceTypeManagerFileAtomic::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::Shutdown(CResourceTypeManagerFileAtomic *this)
{
  int m_BlocksAllocated; // ebx
  void *v3; // esp
  int *v4; // esi
  int Elements; // eax
  int v6; // ebx
  int v7; // esi
  const char *v8; // eax
  TSLNodeBase_t *i; // eax
  TSLNodeBase_t *j; // eax
  IResourceTypeConstructor *m_pConstructor; // ecx
  int v12[3]; // [esp+0h] [ebp-11Ch] BYREF
  char buf[260]; // [esp+Ch] [ebp-110h] BYREF
  int v14; // [esp+110h] [ebp-Ch]
  void *handle; // [esp+114h] [ebp-8h] BYREF
  int *v16; // [esp+118h] [ebp-4h]

  m_BlocksAllocated = this->m_IdMap.m_EntryMemory.m_BlocksAllocated;
  v3 = alloca(4 * m_BlocksAllocated);
  v4 = v12;
  v16 = v12;
  Elements = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::GetElements(
               this: &this->m_IdMap,
               nFirstElement: 0,
               nCount: m_BlocksAllocated,
               pHandles: v12);
  v6 = 0;
  v14 = Elements;
  if ( Elements > 0 )
  {
    while ( 1 )
    {
      v7 = v4[v6] + 8;
      if ( *(_DWORD *)v7 != 0 )
      {
        if ( *(int *)(v7 + 12) > 0 )
        {
          handle = *(void **)(v7 + 16);
          CUtlFilenameSymbolTable::String(this: &g_pResourceSystemImp->m_FileSymbols, &handle, buf, buflen: 260);
          V_SetExtension(path: buf, extension: "dct", pathStringLength: 260);
          v8 = g_pResourceSystemImp->FindEnumerationName(
                 this: g_pResourceSystemImp,
                 a2: "ResourceTypeEngine_t",
                 a3: this->m_nResourceType,
                 a4: "RESOURCE_TYPE_UNKNOWN");
          _Warning(
            a1: "*** Leaked resource! Refcount for %s resource \"%s\" (%X) is %d! Shutdown crash imminent!\n",
            v8 + 14,
            buf,
            *(_DWORD *)v16[v6],
            *(_DWORD *)(v7 + 12));
        }
        this->m_pConstructor->Deallocate(this: this->m_pConstructor, a2: *(void **)v7);
        this->m_pConstructor->DeallocatePermanentData(this: this->m_pConstructor, a2: *(void **)(v7 + 24));
        Elements = v14;
      }
      if ( ++v6 >= Elements )
        break;
      v4 = v16;
    }
  }
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::RemoveAll(this: &this->m_IdMap);
  for ( i = (TSLNodeBase_t *)CTSQueue<ResourceBindingBase_t const *,0>::Pop(this: &this->m_CacheRequests);
        i != nullptr;
        i = (TSLNodeBase_t *)CTSQueue<ResourceBindingBase_t const *,0>::Pop(this: &this->m_CacheRequests) )
  {
    CTSListBase::Push(this: &this->m_CacheRequests.m_FreeNodes, pNode: i);
  }
  for ( j = (TSLNodeBase_t *)CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Pop(this: &this->m_ResourceThreadEvents);
        j != nullptr;
        j = (TSLNodeBase_t *)CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Pop(this: &this->m_ResourceThreadEvents) )
  {
    CTSListBase::Push(this: &this->m_ResourceThreadEvents.m_FreeNodes, pNode: j);
  }
  m_pConstructor = this->m_pConstructor;
  this->m_nMemoryUsed = 0;
  m_pConstructor->Shutdown(this: m_pConstructor);
  _heap_term(this);
}

//------------------------------------------------------------------------------
// Address: 0x10009DA0
// Name: public: virtual void CResourceTypeManagerFileAtomic::DeleteResource(struct ResourceBindingBase_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::DeleteResource(
        CResourceTypeManagerFileAtomic *this,
        const ResourceBindingBase_t *hResource)
{
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *p_m_DeletionRequests; // esi
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *v3; // eax

  if ( hResource != nullptr )
  {
    p_m_DeletionRequests = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *)&this->m_DeletionRequests;
    v3 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)CTSListBase::Pop(this: &this->m_DeletionRequests.m_FreeNodes);
    if ( v3 != nullptr
      || (v3 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)operator new(nSize: 8u)) != nullptr )
    {
      v3->elem.m_hFile = (void *)hResource;
      CTSQueue<ResourceBindingBase_t const *,0>::Push(this: p_m_DeletionRequests, pNode: v3);
    }
    else
    {
      CTSQueue<ResourceBindingBase_t const *,0>::Push(this: p_m_DeletionRequests, pNode: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009DF0
// Name: public: virtual void CResourceTypeManagerFileAtomic::CacheResource(struct ResourceBindingBase_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::CacheResource(
        CResourceTypeManagerFileAtomic *this,
        const ResourceBindingBase_t *hResource)
{
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *p_m_CacheRequests; // edi
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *v3; // eax

  if ( hResource != nullptr )
  {
    p_m_CacheRequests = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *)&this->m_CacheRequests;
    hResource->m_nLastBindFrame = g_nResourceFrameCount;
    v3 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)CTSListBase::Pop(this: &this->m_CacheRequests.m_FreeNodes);
    if ( v3 != nullptr
      || (v3 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)operator new(nSize: 8u)) != nullptr )
    {
      v3->elem.m_hFile = (void *)hResource;
      CTSQueue<ResourceBindingBase_t const *,0>::Push(this: p_m_CacheRequests, pNode: v3);
    }
    else
    {
      CTSQueue<ResourceBindingBase_t const *,0>::Push(this: p_m_CacheRequests, pNode: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009E50
// Name: public: virtual void CResourceTypeManagerFileAtomic::UncacheResource(struct ResourceBindingBase_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::UncacheResource(
        CResourceTypeManagerFileAtomic *this,
        const ResourceBindingBase_t *hResource)
{
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *p_m_UncacheRequests; // esi
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *v3; // eax

  if ( hResource != nullptr )
  {
    p_m_UncacheRequests = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *)&this->m_UncacheRequests;
    v3 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)CTSListBase::Pop(this: &this->m_UncacheRequests.m_FreeNodes);
    if ( v3 != nullptr
      || (v3 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)operator new(nSize: 8u)) != nullptr )
    {
      v3->elem.m_hFile = (void *)hResource;
      CTSQueue<ResourceBindingBase_t const *,0>::Push(this: p_m_UncacheRequests, pNode: v3);
    }
    else
    {
      CTSQueue<ResourceBindingBase_t const *,0>::Push(this: p_m_UncacheRequests, pNode: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009EA0
// Name: private: void CResourceTypeManagerFileAtomic::PostResourceThreadEventInternal(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CResourceTypeManagerFileAtomic::PostResourceThreadEventInternal(
        CResourceTypeManagerFileAtomic *this,
        unsigned __int8 *pMsg,
        unsigned int nSize)
{
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *p_m_ResourceThreadEvents; // esi
  TSLNodeBase_t *v5; // eax
  CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t evtBuffer_4; // [esp+4h] [ebp-10h] OVERLAPPED BYREF

  memcpy(dst: evtBuffer_4.m_pBuffer, src: pMsg, count: nSize);
  p_m_ResourceThreadEvents = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *)&this->m_ResourceThreadEvents;
  v5 = CTSListBase::Pop(this: &p_m_ResourceThreadEvents->m_FreeNodes);
  if ( v5 != nullptr || (v5 = (TSLNodeBase_t *)operator new(nSize: 0x18u)) != nullptr )
  {
    *(CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t *)(&v5->Next + 1) = evtBuffer_4;
    CTSQueue<ResourceBindingBase_t const *,0>::Push(
      this: p_m_ResourceThreadEvents,
      pNode: (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)v5);
  }
  else
  {
    CTSQueue<ResourceBindingBase_t const *,0>::Push(this: p_m_ResourceThreadEvents, pNode: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009F20
// Name: private: void CResourceTypeManagerFileAtomic::M_ProcessResourceThreadEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::M_ProcessResourceThreadEvents(CResourceTypeManagerFileAtomic *this)
{
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0> *p_m_ResourceThreadEvents; // ebx
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Node_t *v3; // eax
  unsigned int v4; // edx
  const void *v5; // eax
  __int64 msg; // [esp+10h] [ebp-10h]
  __int64 msg_8; // [esp+18h] [ebp-8h]

  p_m_ResourceThreadEvents = &this->m_ResourceThreadEvents;
  while ( 1 )
  {
    v3 = CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Pop(this: p_m_ResourceThreadEvents);
    if ( v3 == nullptr )
      break;
    msg = *(_QWORD *)v3->elem.m_pBuffer;
    msg_8 = *(_QWORD *)&v3->elem.m_pBuffer[8];
    CTSListBase::Push(this: &p_m_ResourceThreadEvents->m_FreeNodes, pNode: (TSLNodeBase_t *)v3);
    if ( (_DWORD)msg != 0 )
    {
      if ( (_DWORD)msg == 1 )
      {
        *(_DWORD *)HIDWORD(msg) = msg_8;
        v4 = *(_DWORD *)(HIDWORD(msg) + 8) & 0xFFFFFFEE | 1;
        *(_DWORD *)(HIDWORD(msg) + 4) = g_nResourceFrameCount;
        *(_DWORD *)(HIDWORD(msg) + 8) = v4;
        this->m_nMemoryUsed += *(_DWORD *)(HIDWORD(msg) + 20);
      }
      else if ( (_DWORD)msg == 2 )
      {
        this->m_nMemoryUsed += *(_DWORD *)(HIDWORD(msg) + 20);
      }
    }
    else
    {
      v5 = *(const void **)(HIDWORD(msg) + 24);
      *(_DWORD *)(HIDWORD(msg) + 8) = *(_DWORD *)(HIDWORD(msg) + 8) & 0xFFFFFFEC | 3;
      *(_DWORD *)HIDWORD(msg) = this->m_pConstructor->GetErrorResource(this: this->m_pConstructor, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009FE0
// Name: private: void CResourceTypeManagerFileAtomic::M_UncacheRequestedResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::M_UncacheRequestedResources(CResourceTypeManagerFileAtomic *this)
{
  unsigned int v2; // eax
  void *v3; // esp
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *p_m_UncacheRequests; // ebx
  CTSQueue<ResourceBindingBase_t const *,0>::Node_t *v5; // eax
  const ResourceBindingBase_t *elem; // esi
  unsigned int m_nFlags; // eax
  int v8; // eax
  int v9; // edi
  int i; // esi
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *v11; // eax
  int v12; // [esp+0h] [ebp-14h] BYREF
  const ResourceBindingBase_t **pSaveForLater; // [esp+Ch] [ebp-8h]
  int nSaveCount; // [esp+10h] [ebp-4h]

  v2 = (4 * this->m_UncacheRequests.m_Count.m_value + 15) & 0xFFFFFFF0;
  nSaveCount = 0;
  v3 = alloca(v2);
  pSaveForLater = (const ResourceBindingBase_t **)&v12;
  p_m_UncacheRequests = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *)&this->m_UncacheRequests;
  while ( 1 )
  {
    v5 = CTSQueue<ResourceBindingBase_t const *,0>::Pop(this: &this->m_UncacheRequests);
    if ( v5 == nullptr )
      break;
    elem = v5->elem;
    CTSListBase::Push(this: &this->m_UncacheRequests.m_FreeNodes, pNode: (TSLNodeBase_t *)v5);
    m_nFlags = elem->m_nFlags;
    if ( (m_nFlags & 0x10) != 0 )
    {
      v8 = nSaveCount;
      pSaveForLater[nSaveCount] = elem;
      nSaveCount = v8 + 1;
    }
    else if ( (m_nFlags & 1) != 0 && (elem->m_nRefCount.m_value <= 0 || (elem->m_nFlags & 4) == 0) )
    {
      if ( elem->m_pData != nullptr && (elem->m_nFlags & 2) == 0 )
      {
        this->m_nMemoryUsed -= elem[1].m_nLastBindFrame;
        this->m_pConstructor->Deallocate(this: this->m_pConstructor, a2: elem->m_pData);
      }
      elem->m_nFlags &= 0xFFFFFFFC;
      elem->m_pData = nullptr;
    }
  }
  v9 = nSaveCount;
  for ( i = 0; i < v9; ++i )
  {
    v11 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)CTSListBase::Pop(this: &p_m_UncacheRequests->m_FreeNodes);
    if ( v11 != nullptr )
    {
      v11->elem.m_hFile = (void *)pSaveForLater[i];
    }
    else
    {
      v11 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)operator new(nSize: 8u);
      if ( v11 != nullptr )
        v11->elem.m_hFile = (void *)pSaveForLater[i];
      else
        v11 = nullptr;
    }
    CTSQueue<ResourceBindingBase_t const *,0>::Push(this: p_m_UncacheRequests, pNode: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A0D0
// Name: private: void CResourceTypeManagerFileAtomic::M_DeleteRequestedResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::M_DeleteRequestedResources(CResourceTypeManagerFileAtomic *this)
{
  CTSQueue<ResourceBindingBase_t const *,0> *p_m_DeletionRequests; // ebp
  CTSQueue<ResourceBindingBase_t const *,0>::Node_t *v3; // eax
  const ResourceBindingBase_t *elem; // esi
  unsigned int m_nFlags; // eax

  p_m_DeletionRequests = &this->m_DeletionRequests;
  while ( 1 )
  {
    v3 = CTSQueue<ResourceBindingBase_t const *,0>::Pop(this: p_m_DeletionRequests);
    if ( v3 == nullptr )
      break;
    elem = v3->elem;
    CTSListBase::Push(this: &p_m_DeletionRequests->m_FreeNodes, pNode: (TSLNodeBase_t *)v3);
    if ( elem->m_nRefCount.m_value <= 0 )
    {
      m_nFlags = elem->m_nFlags;
      if ( (m_nFlags & 0x10) != 0 )
      {
        _Warning(a1: "Bad deletion request: Pending Async Request!\n");
      }
      else
      {
        if ( (m_nFlags & 1) != 0 && (elem->m_nRefCount.m_value <= 0 || (elem->m_nFlags & 4) == 0) )
        {
          if ( elem->m_pData != nullptr && (elem->m_nFlags & 2) == 0 )
          {
            this->m_nMemoryUsed -= elem[1].m_nLastBindFrame;
            this->m_pConstructor->Deallocate(this: this->m_pConstructor, a2: elem->m_pData);
          }
          elem->m_nFlags &= 0xFFFFFFFC;
          elem->m_pData = nullptr;
        }
        if ( elem[1].m_nFlags != 0 )
          this->m_pConstructor->DeallocatePermanentData(this: this->m_pConstructor, a2: (void *)elem[1].m_nFlags);
        CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::FindAndRemove(
          this: &this->m_IdMap,
          uiKey: elem[-1].m_nFlags);
      }
    }
    else
    {
      _Warning(a1: "Bad deletion request: Refcount non-zero!\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A190
// Name: public: CResourceTypeManagerFileAtomic::CResourceTypeManagerFileAtomic(void)
// Source: json
//------------------------------------------------------------------------------
CResourceTypeManagerFileAtomic *__thiscall CResourceTypeManagerFileAtomic::CResourceTypeManagerFileAtomic(
        CResourceTypeManagerFileAtomic *this)
{
  CResourceTypeManagerBase::CResourceTypeManagerBase(this);
  this->__vftable = (CResourceTypeManagerFileAtomic_vtbl *)&CResourceTypeManagerFileAtomic::`vftable';
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>(
    this: &this->m_IdMap,
    nAllocationCount: 256);
  CTSQueue<ResourceBindingBase_t const *,0>::CTSQueue<ResourceBindingBase_t const *,0>(this: &this->m_CacheRequests);
  CTSQueue<ResourceBindingBase_t const *,0>::CTSQueue<ResourceBindingBase_t const *,0>(this: &this->m_UncacheRequests);
  CTSQueue<ResourceBindingBase_t const *,0>::CTSQueue<ResourceBindingBase_t const *,0>(this: &this->m_DeletionRequests);
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>(this: &this->m_ResourceThreadEvents);
  this->m_nAlignment = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A1F0
// Name: public: virtual CResourceTypeManagerFileAtomic::~CResourceTypeManagerFileAtomic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::~CResourceTypeManagerFileAtomic(CResourceTypeManagerFileAtomic *this)
{
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0> *p_m_ResourceThreadEvents; // edi

  p_m_ResourceThreadEvents = &this->m_ResourceThreadEvents;
  this->__vftable = (CResourceTypeManagerFileAtomic_vtbl *)&CResourceTypeManagerFileAtomic::`vftable';
  CTSQueue<CResourceTypeManagerFileAtomic::ResourceThreadEventBuffer_t,0>::Purge(this: &this->m_ResourceThreadEvents);
  free(pMem: p_m_ResourceThreadEvents->m_Head.value.pNode);
  CTSListBase::Detach(this: &p_m_ResourceThreadEvents->m_FreeNodes);
  CTSQueue<ResourceBindingBase_t const *,0>::Purge(this: &this->m_DeletionRequests);
  free(pMem: this->m_DeletionRequests.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_DeletionRequests.m_FreeNodes);
  CTSQueue<ResourceBindingBase_t const *,0>::Purge(this: &this->m_UncacheRequests);
  free(pMem: this->m_UncacheRequests.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_UncacheRequests.m_FreeNodes);
  CTSQueue<ResourceBindingBase_t const *,0>::Purge(this: &this->m_CacheRequests);
  free(pMem: this->m_CacheRequests.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_CacheRequests.m_FreeNodes);
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::RemoveAll(this: &this->m_IdMap);
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_IdMap.m_EntryMemory);
  CResourceTypeManagerBase::~CResourceTypeManagerBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000A2A0
// Name: public: virtual void CResourceTypeManagerFileAtomic::RegisterResources(int,struct ResourceIdInfo_t const __near *,struct ResourceFileHeader_t const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CResourceTypeManagerFileAtomic::RegisterResources(
        CResourceTypeManagerFileAtomic *this@<ecx>,
        int a2@<edi>,
        _DWORD *a3@<esi>,
        int nCount,
        const ResourceIdInfo_t *pIdInfo,
        const ResourceFileHeader_t *pHeader,
        const CResourceIntrospection *hFile)
{
  CResourcePointer<void> *p_m_PermanentData; // edi
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v9; // eax
  CResourceTypeManagerFileAtomic::ResourceData_t *p_m_Data; // esi
  const void **p_m_pPermanentData; // ebp
  int v12; // [esp-Ch] [ebp-128h]
  _DWORD *v13; // [esp-8h] [ebp-124h]
  int i; // [esp+4h] [ebp-118h]
  const CResourceIntrospection *pPermIntroDct; // [esp+8h] [ebp-114h] BYREF
  RSTEResourceLoadFailed_t failedCmd; // [esp+Ch] [ebp-110h] BYREF
  char pBuf[260]; // [esp+14h] [ebp-108h] BYREF

  failedCmd.m_nId = (ResourceThreadEventId_t)Resource_GetBlock(pHeader, id: 0x49534552u);
  if ( nCount > 0 )
  {
    v13 = a3;
    v12 = a2;
    p_m_PermanentData = &pIdInfo->m_PermanentData;
    for ( i = nCount; i != 0; --i )
    {
      v9 = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Insert(
             this: &this->m_IdMap,
             uiKey: p_m_PermanentData[-3].m_nOffset,
             data: &CResourceTypeManagerFileAtomic::sm_DefaultResourceData,
             pDidInsert: nullptr);
      p_m_Data = &v9->m_Data;
      if ( v9->m_Data.m_hFile == nullptr )
      {
        v9->m_Data.m_hFile = (void *)hFile;
        v9->m_Data.m_nSize = p_m_PermanentData[-2].m_nOffset;
        p_m_pPermanentData = (const void **)&v9->m_Data.m_pPermanentData;
        if ( p_m_PermanentData->m_nOffset != 0 )
        {
          if ( CResourceTypeManagerFileAtomic::AutoconvertedAllocatePermanent(
                 this,
                 a2: (int)this,
                 a3: (int)p_m_PermanentData,
                 pPermanentData: (char *)p_m_PermanentData + p_m_PermanentData->m_nOffset,
                 nSrcDataSize: p_m_PermanentData[-1].m_nOffset,
                 pSrcIntroDct: (const CResourceIntrospection *)failedCmd.m_nId,
                 nResourceType: this->m_nResourceType,
                 pOutResult: &v9->m_Data.m_pPermanentData,
                 a9: v12,
                 a10: v13) == 0 )
          {
            pPermIntroDct = hFile;
            CUtlFilenameSymbolTable::String(
              this: &g_pResourceSystemImp->m_FileSymbols,
              handle: (void *const *)&pPermIntroDct,
              buf: &pBuf[4],
              buflen: 260);
            V_SetExtension(path: &pBuf[4], extension: "ids", pathStringLength: 260);
            _Warning(
              a1: "ERROR: Problem allocating permanent data for resource in file '%s'. See above for reason(s)\n",
              &pBuf[4]);
            failedCmd.m_hResource = nullptr;
            *(_DWORD *)pBuf = p_m_Data;
            CResourceTypeManagerFileAtomic::PostResourceThreadEventInternal(
              this,
              pMsg: (unsigned __int8 *)&failedCmd.m_hResource,
              nSize: 8u);
          }
        }
        else
        {
          *p_m_pPermanentData = nullptr;
        }
        p_m_Data->m_Resource.m_pData = this->m_pConstructor->GetFallback(
                                         this: this->m_pConstructor,
                                         a2: *p_m_pPermanentData);
      }
      p_m_PermanentData += 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A3E0
// Name: public: virtual struct ResourceBindingBase_t const __near * CResourceTypeManagerFileAtomic::FindOrCreateProceduralResource(char const __near *,char const __near *,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CResourceTypeManagerFileAtomic::ResourceData_t *__thiscall CResourceTypeManagerFileAtomic::FindOrCreateProceduralResource(
        CResourceTypeManagerFileAtomic *this,
        const char *pGroupName,
        const char *pResourceName,
        const void *pPermanentData,
        unsigned int nDataSize)
{
  bool v6; // al
  unsigned int v7; // eax
  CResourceTypeManagerFileAtomic::ResourceData_t *p_m_Data; // esi
  void *v9; // eax
  RSTEResourceProceduralCreation_t creationCompleted; // [esp+18h] [ebp-12Ch] BYREF
  CResourceTypeManagerFileAtomic::ResourceData_t initData; // [esp+20h] [ebp-124h] BYREF
  char pActualResourceName[260]; // [esp+3Ch] [ebp-108h] BYREF

  v6 = pGroupName == nullptr && pResourceName == nullptr;
  *(_QWORD *)&initData.m_Resource.m_nLastBindFrame = *(_QWORD *)&CResourceTypeManagerFileAtomic::sm_DefaultResourceData.m_Resource.m_pData;
  initData.m_hFile = (void *)CResourceTypeManagerFileAtomic::sm_DefaultResourceData.m_Resource.m_nRefCount.m_value;
  initData.m_Resource.m_nRefCount.m_value = CResourceTypeManagerFileAtomic::sm_DefaultResourceData.m_Resource.m_nFlags
                                          | 4;
  HIBYTE(creationCompleted.m_nId) = 0;
  *(_QWORD *)&initData.m_nSize = *(_QWORD *)&CResourceTypeManagerFileAtomic::sm_DefaultResourceData.m_hFile;
  *(_DWORD *)pActualResourceName = CResourceTypeManagerFileAtomic::sm_DefaultResourceData.m_pPermanentData;
  if ( v6 )
  {
    V_snprintf(
      pDest: &pActualResourceName[4],
      maxLen: 260,
      pFormat: "<AnOnYmOuS>%d",
      _InterlockedIncrement(&s_nAnonymousCounter.m_value) - 1);
    initData.m_Resource.m_nRefCount.m_value |= 8u;
  }
  else
  {
    V_snprintf(pDest: &pActualResourceName[4], maxLen: 260, pFormat: "<%s>%s", pGroupName, pResourceName);
  }
  v7 = ComputeResourceIdHash(pFileName: ";procedural;", pSubResourceName: &pActualResourceName[4]);
  initData.m_nSize = (unsigned int)g_pResourceSystemImp->m_hProceduralFileHandle;
  p_m_Data = &CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Insert(
                this: &this->m_IdMap,
                uiKey: v7,
                data: (const CResourceTypeManagerFileAtomic::ResourceData_t *)&initData.m_Resource.m_nLastBindFrame,
                pDidInsert: (bool *)&creationCompleted.m_nId + 3)->m_Data;
  if ( HIBYTE(creationCompleted.m_nId) != 0 )
  {
    p_m_Data->m_pPermanentData = this->m_pConstructor->AllocatePermanentData(
                                   this: this->m_pConstructor,
                                   a2: pPermanentData,
                                   a3: nDataSize);
    p_m_Data->m_nSize = this->m_pConstructor->ComputeActualSize(
                          this: this->m_pConstructor,
                          a2: p_m_Data->m_pPermanentData);
    v9 = this->m_pConstructor->Allocate(
           this: this->m_pConstructor,
           a2: p_m_Data->m_pPermanentData,
           a3: 0,
           a4: 0,
           a5: p_m_Data);
    p_m_Data->m_Resource.m_nFlags |= 1u;
    p_m_Data->m_Resource.m_pData = v9;
    creationCompleted.m_hResource = (const ResourceBindingBase_t *)2;
    initData.m_Resource.m_pData = p_m_Data;
    CResourceTypeManagerFileAtomic::PostResourceThreadEventInternal(
      this,
      pMsg: (unsigned __int8 *)&creationCompleted.m_hResource,
      nSize: 8u);
  }
  return p_m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x1000A540
// Name: private: void CResourceTypeManagerFileAtomic::HookUpResourceData(struct ResourceBindingBase_t const __near *,void __near *,void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::HookUpResourceData(
        CResourceTypeManagerFileAtomic *this,
        const ResourceBindingBase_t *hResource,
        void *hFile,
        const ResourceFileHeader_t *pDct,
        char *pDta)
{
  _DWORD *Block; // edi
  const ResourceDictionary_t *v7; // eax
  bool v8; // cc
  _DWORD *v9; // eax
  int v10; // ecx
  _DWORD *m_nId; // eax
  int v12; // edi
  unsigned int v13; // edx
  _DWORD *v14; // edi
  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::HashFixedDataInternal_t<CResourceTypeManagerFileAtomic::ResourceData_t> *v15; // eax
  const CResourceIntrospection *p_m_Data; // ebp
  unsigned int m_nOffset; // eax
  char *v18; // ebx
  int v19; // eax
  const void *m_nCount; // [esp-20h] [ebp-170h]
  unsigned int v21; // [esp-18h] [ebp-168h]
  void *m_nResourceType; // [esp-10h] [ebp-160h]
  const CResourceIntrospection *v23; // [esp-8h] [ebp-158h]
  char pDstMemory_3; // [esp+Fh] [ebp-141h]
  void *pOutResult; // [esp+10h] [ebp-140h] BYREF
  unsigned int requestedId; // [esp+14h] [ebp-13Ch]
  unsigned int v27; // [esp+18h] [ebp-138h]
  int nMemoryLoaded; // [esp+1Ch] [ebp-134h]
  int v29; // [esp+20h] [ebp-130h]
  int i; // [esp+24h] [ebp-12Ch]
  RSTEResourceLoadFailed_t failedCmd; // [esp+28h] [ebp-128h] BYREF
  const CResourceIntrospection *pIntroDct; // [esp+30h] [ebp-120h]
  const ResourceDictionary_t *pDict; // [esp+34h] [ebp-11Ch]
  _DWORD *v34; // [esp+38h] [ebp-118h]
  RSTEResourceLoadCompleted_t loadCompleted; // [esp+3Ch] [ebp-114h] BYREF
  char pBuf[260]; // [esp+48h] [ebp-108h] BYREF

  v27 = this->GetResourceId(this, a2: hResource);
  pDstMemory_3 = 0;
  Block = Resource_GetBlock(pHeader: pDct, id: 0x44534552u);
  v34 = Block;
  v7 = (const ResourceDictionary_t *)Resource_GetBlock(pHeader: pDct, id: 0x49534552u);
  v8 = Block[5] <= 0;
  pDict = v7;
  v29 = 0;
  failedCmd.m_nId = RSTE_RESOURCE_LOAD_FAILED;
  if ( v8 )
  {
LABEL_21:
    failedCmd.m_hResource = nullptr;
    pIntroDct = (const CResourceIntrospection *)hResource;
    _Warning(a1: "Requested resource %08X does not exist in file!\n", v27);
    CResourceTypeManagerFileAtomic::PostResourceThreadEventInternal(
      this,
      pMsg: (unsigned __int8 *)&failedCmd.m_hResource,
      nSize: 8u);
    goto LABEL_22;
  }
  requestedId = 0;
  do
  {
    v9 = (_DWORD *)((char *)&Block[requestedId / 4 + 4] + Block[4]);
    if ( *v9 == this->m_nResourceType )
    {
      v10 = v9[3];
      if ( v10 > 0 )
      {
        m_nId = v9 + 2;
        loadCompleted.m_nId = (ResourceThreadEventId_t)m_nId;
        nMemoryLoaded = 0;
        i = v10;
        while ( 1 )
        {
          v12 = nMemoryLoaded + *m_nId;
          v13 = *(_DWORD *)((char *)m_nId + v12);
          v14 = (_DWORD *)((char *)m_nId + v12);
          v15 = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Find(
                  this: &this->m_IdMap,
                  uiKey: v13);
          p_m_Data = (const CResourceIntrospection *)&v15->m_Data;
          if ( (v15->m_Data.m_Resource.m_nFlags & 3) != 0 )
            goto LABEL_17;
          m_nOffset = this->m_pConstructor->ComputeActualSize(
                        this: this->m_pConstructor,
                        a2: v15->m_Data.m_pPermanentData);
          if ( m_nOffset == 0 )
            m_nOffset = p_m_Data->m_StructIntrospection.m_nOffset;
          if ( *v14 == v27 )
          {
            pDstMemory_3 = 1;
          }
          else if ( (signed int)(v29 + m_nOffset + this->m_nMemoryUsed) > this->m_nMemoryLimit )
          {
            goto LABEL_17;
          }
          v29 += m_nOffset;
          v18 = &pDta[v14[1]];
          v23 = (const CResourceIntrospection *)pDict;
          v19 = this->GetResourceType(this);
          CResourceTypeManagerBase::FixupResourceReferences(
            this,
            pResourceData: v18,
            pDct,
            nResourceType: v19,
            pIntroDct: v23);
          m_nResourceType = (void *)this->m_nResourceType;
          v21 = v14[3];
          m_nCount = (const void *)p_m_Data->m_StructIntrospection.m_nCount;
          pOutResult = nullptr;
          if ( CResourceTypeManagerFileAtomic::AutoconvertedAllocate(
                 this,
                 pPermanentData: m_nCount,
                 pResourceData: v18,
                 nSrcDataSize: v21,
                 pSrcIntroDct: (const CResourceIntrospection *)pDict,
                 nResourceType: m_nResourceType,
                 hResourceHandle: (const ResourceBindingBase_t *)p_m_Data,
                 &pOutResult) != 0 )
          {
            loadCompleted.m_hResource = (const ResourceBindingBase_t *)1;
            loadCompleted.m_pResourceData = (void *)p_m_Data;
            *(_DWORD *)pBuf = pOutResult;
            CResourceTypeManagerFileAtomic::PostResourceThreadEventInternal(
              this,
              pMsg: (unsigned __int8 *)&loadCompleted.m_hResource,
              nSize: 0xCu);
          }
          else
          {
            pOutResult = hFile;
            failedCmd.m_hResource = nullptr;
            pIntroDct = p_m_Data;
            CUtlFilenameSymbolTable::String(
              this: &g_pResourceSystemImp->m_FileSymbols,
              handle: &pOutResult,
              buf: &pBuf[4],
              buflen: 260);
            V_SetExtension(path: &pBuf[4], extension: "dta", pathStringLength: 260);
            _Warning(
              a1: "ERROR: Failed to construct resource %08X! (In file: %s) See above for reason(s).\n",
              v27,
              &pBuf[4]);
            CResourceTypeManagerFileAtomic::PostResourceThreadEventInternal(
              this,
              pMsg: (unsigned __int8 *)&failedCmd.m_hResource,
              nSize: 8u);
          }
LABEL_17:
          nMemoryLoaded += 16;
          if ( --i == 0 )
          {
            Block = v34;
            break;
          }
          m_nId = (_DWORD *)loadCompleted.m_nId;
        }
      }
    }
    requestedId += 16;
    v8 = ++failedCmd.m_nId < Block[5];
  }
  while ( v8 );
  if ( pDstMemory_3 == 0 )
    goto LABEL_21;
LABEL_22:
  g_pAsyncFileSystem->ReleaseBuffer(this: g_pAsyncFileSystem, a2: pDta);
  g_pAsyncFileSystem->ReleaseBuffer(this: g_pAsyncFileSystem, a2: (void *)pDct);
}

//------------------------------------------------------------------------------
// Address: 0x1000A7D0
// Name: private: int CResourceTypeManagerFileAtomic::M_BuildRequestedResourcesList(class CUtlVector<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,class CUtlMemory<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceTypeManagerFileAtomic::M_BuildRequestedResourcesList(
        CResourceTypeManagerFileAtomic *this,
        CUtlVector<CResourceSystem::PendingResourceIdResolution_t,CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> > *toCacheList)
{
  int v2; // edi
  void *v3; // esp
  CTSQueue<ResourceBindingBase_t const *,0> *p_m_CacheRequests; // ebx
  CTSQueue<ResourceBindingBase_t const *,0>::Node_t *v5; // eax
  const ResourceBindingBase_t *elem; // esi
  int i; // esi
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *v8; // eax
  int m_Size; // [esp-8h] [ebp-24h]
  int v11; // [esp+0h] [ebp-1Ch] BYREF
  CResourceSystem::PendingResourceIdResolution_t src; // [esp+Ch] [ebp-10h] BYREF
  int *v13; // [esp+18h] [ebp-4h]

  v2 = 0;
  v3 = alloca(4 * this->m_CacheRequests.m_Count.m_value);
  v13 = &v11;
  p_m_CacheRequests = &this->m_CacheRequests;
  while ( 1 )
  {
    v5 = CTSQueue<ResourceBindingBase_t const *,0>::Pop(this: p_m_CacheRequests);
    if ( v5 == nullptr )
      break;
    elem = v5->elem;
    CTSListBase::Push(this: &p_m_CacheRequests->m_FreeNodes, pNode: (TSLNodeBase_t *)v5);
    if ( elem[1].m_pData != nullptr )
    {
      if ( (elem->m_nFlags & 0x11) == 0 )
      {
        src.m_nType = elem[1].m_nLastBindFrame;
        m_Size = toCacheList->m_Size;
        LOBYTE(src.m_nId) = 1;
        src.m_hFile = (void *)elem;
        CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::InsertBefore(
          this: toCacheList,
          elem: m_Size,
          &src);
      }
    }
    else if ( (elem->m_nFlags & 0x20) == 0 )
    {
      v13[v2++] = (int)elem;
    }
  }
  for ( i = 0; i < v2; ++i )
  {
    v8 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)CTSListBase::Pop(this: &p_m_CacheRequests->m_FreeNodes);
    if ( v8 != nullptr )
    {
      v8->elem.m_hFile = (void *)v13[i];
    }
    else
    {
      v8 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)operator new(nSize: 8u);
      if ( v8 != nullptr )
        v8->elem.m_hFile = (void *)v13[i];
      else
        v8 = nullptr;
    }
    CTSQueue<ResourceBindingBase_t const *,0>::Push(
      this: (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *)p_m_CacheRequests,
      pNode: v8);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A8B0
// Name: private: int CResourceTypeManagerFileAtomic::M_BuildToCacheList(class CUtlVector<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,class CUtlMemory<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceTypeManagerFileAtomic::M_BuildToCacheList(
        CResourceTypeManagerFileAtomic *this,
        CUtlVector<CResourceSystem::PendingResourceIdResolution_t,CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> > *toCacheList,
        int nFinishedFrameCount)
{
  int m_BlocksAllocated; // esi
  void *v5; // esp
  int v6; // edi
  const ResourceBindingBase_t *v7; // esi
  unsigned int v8; // eax
  int v9[3]; // [esp+0h] [ebp-24h] BYREF
  CResourceTypeManagerFileAtomic::ToCacheHandle_t toCache; // [esp+Ch] [ebp-18h] BYREF
  int nCount; // [esp+18h] [ebp-Ch]
  int *pHandles; // [esp+1Ch] [ebp-8h]
  int nNeededBytes; // [esp+20h] [ebp-4h]

  m_BlocksAllocated = this->m_IdMap.m_EntryMemory.m_BlocksAllocated;
  if ( m_BlocksAllocated == 0 )
    return 0;
  nNeededBytes = 0;
  v5 = alloca(4 * m_BlocksAllocated);
  pHandles = v9;
  v6 = 0;
  nCount = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::GetElements(
             this: &this->m_IdMap,
             nFirstElement: 0,
             nCount: m_BlocksAllocated,
             pHandles: v9);
  if ( nCount > 0 )
  {
    do
    {
      v7 = (const ResourceBindingBase_t *)(pHandles[v6] + 8);
      if ( pHandles[v6] != -8
        && *(_DWORD *)(pHandles[v6] + 24) != 0
        && (*(_BYTE *)(pHandles[v6] + 16) & 0x11) == 0
        && *(int *)(pHandles[v6] + 20) > 0
        && *(_DWORD *)(pHandles[v6] + 12) == nFinishedFrameCount )
      {
        v8 = *(_DWORD *)(pHandles[v6] + 28);
        toCache.m_bWasRequested = false;
        toCache.m_hResource = v7;
        toCache.m_nSize = v8;
        if ( CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::Find(
               this: (CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int> > *)toCacheList,
               src: &toCache) == -1 )
        {
          CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::InsertBefore(
            this: toCacheList,
            elem: toCacheList->m_Size,
            src: (const CResourceSystem::PendingResourceIdResolution_t *)&toCache);
          nNeededBytes += v7[1].m_nLastBindFrame;
        }
      }
      ++v6;
    }
    while ( v6 < nCount );
  }
  return nNeededBytes;
}

//------------------------------------------------------------------------------
// Address: 0x1000A980
// Name: public: virtual class CResourceTypeManagerBase __near * CResourceTypeManagerFactory<class CResourceTypeManagerFileAtomic>::Create(void)
// Source: json
//------------------------------------------------------------------------------
CResourceTypeManagerFileAtomic *__thiscall CResourceTypeManagerFactory<CResourceTypeManagerFileAtomic>::Create(
        CResourceTypeManagerFactory<CResourceTypeManagerFileAtomic> *this)
{
  CResourceTypeManagerFileAtomic *v1; // eax

  v1 = (CResourceTypeManagerFileAtomic *)operator new(nSize: 0x6098u);
  if ( v1 != nullptr )
    return CResourceTypeManagerFileAtomic::CResourceTypeManagerFileAtomic(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000A9C0
// Name: private: void CResourceTypeManagerFileAtomic::IO_OnResourceFileDctLoaded(class IAsyncFileRequest __near *,struct ResourceBindingBase_t const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::IO_OnResourceFileDctLoaded(
        CResourceTypeManagerFileAtomic *this,
        IAsyncFileRequest *pRequest,
        const ResourceBindingBase_t *hResource,
        void *hFile,
        void *pDtaData)
{
  IAsyncFileRequest *v5; // esi
  AsyncRequestStatus_t v7; // eax
  IAsyncFileRequest_vtbl *v8; // edx
  const char *(__thiscall *GetFileName)(IAsyncFileRequest *); // eax
  const char *v10; // eax
  IAsyncFileRequest *v11; // eax
  IAsyncFileRequest_vtbl *v12; // edx
  CFunctorJob *v13; // esi
  CFunctor *v14; // eax
  CFunctorJob *v15; // esi
  RSTEResourceLoadFailed_t failedCmd; // [esp+4h] [ebp-Ch] BYREF
  const ResourceBindingBase_t *v17; // [esp+Ch] [ebp-4h]

  v5 = pRequest;
  v7 = pRequest->GetRequestStatus(this: pRequest);
  v8 = v5->__vftable;
  if ( v7 != ASYNC_REQUEST_OK )
  {
    v17 = hResource;
    GetFileName = v8->GetFileName;
    failedCmd.m_hResource = nullptr;
    v10 = GetFileName(this: v5);
    _Warning(a1: "Unable to stream in resource dict file \"%s\"", v10);
    CResourceTypeManagerFileAtomic::PostResourceThreadEventInternal(
      this,
      pMsg: (unsigned __int8 *)&failedCmd.m_hResource,
      nSize: 8u);
  }
  else
  {
    v11 = (IAsyncFileRequest *)v8->GetResultBuffer(this: v5);
    v12 = v5->__vftable;
    pRequest = v11;
    v12->KeepResultBuffer(this: v5);
    v13 = (CFunctorJob *)operator new(nSize: 0x44u);
    if ( v13 != nullptr )
    {
      v14 = CreateFunctor<CResourceTypeManagerFileAtomic *,CResourceTypeManagerFileAtomic,void,ResourceBindingBase_t const *,void *,void const *,void const *,ResourceBindingBase_t const *,void *,void *,void *>(
              pObject: this,
              pfnProxied: (void (__thiscall *)(CResourceTypeManagerFileAtomic *, const ResourceBindingBase_t *, void *, const void *, const void *))CResourceTypeManagerFileAtomic::HookUpResourceData,
              arg1: (CFunctor_vtbl **)&hResource,
              arg2: &hFile,
              arg3: (CFunctor_vtbl **)&pRequest,
              arg4: &pDtaData);
      v15 = CFunctorJob::CFunctorJob(this: v13, pFunctor: v14, pszDescription: nullptr);
    }
    else
    {
      v15 = nullptr;
    }
    v15->m_flags = 8;
    _g_pThreadPool->AddPerFrameJob(this: _g_pThreadPool, a2: v15);
    v15->Release(this: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AA90
// Name: private: void CResourceTypeManagerFileAtomic::M_EvictResources(class CUtlVector<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,class CUtlMemory<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::M_EvictResources(
        CResourceTypeManagerFileAtomic *this,
        CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> *toCacheList,
        CResourceTypeManagerFileAtomic::ToCacheHandle_t *nBytesNeeded)
{
  CResourceTypeManagerFileAtomic *v3; // edi
  int v4; // eax
  int m_BlocksAllocated; // eax
  void *v6; // esp
  int Elements; // eax
  int *v8; // ebx
  int v9; // ebx
  int v10; // edx
  int m_nMemoryLimit; // eax
  int m_pMemory; // esi
  int v14; // eax
  int v15; // ecx
  int v16; // ecx
  TSLNodeBase_t *Next; // esi
  int value64_high; // eax
  CTSListBase *p_m_FreeNodes; // edi
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *v20; // eax
  bool v21; // zf
  int v22; // esi
  int v23; // edi
  int m_nAllocationCount; // ecx
  int v25; // edx
  CResourceTypeManagerFileAtomic::ToCacheHandle_t *v26; // ecx
  int v27; // eax
  int v28[3]; // [esp+0h] [ebp-1Ch] BYREF
  int nToCache; // [esp+Ch] [ebp-10h]
  int m_nMemoryUsed; // [esp+10h] [ebp-Ch]
  int nCount; // [esp+14h] [ebp-8h]
  CResourceTypeManagerFileAtomic *v32; // [esp+18h] [ebp-4h]
  int nToRemove; // [esp+24h] [ebp+8h]
  CResourceTypeManagerFileAtomic::ToCacheHandle_t *toCache; // [esp+28h] [ebp+Ch]

  v3 = this;
  v4 = (int)nBytesNeeded + this->m_nMemoryUsed;
  v32 = this;
  if ( v4 > this->m_nMemoryLimit )
  {
    m_BlocksAllocated = this->m_IdMap.m_EntryMemory.m_BlocksAllocated;
    if ( m_BlocksAllocated != 0 )
    {
      v6 = alloca(4 * m_BlocksAllocated);
      Elements = CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::GetElements(
                   this: &this->m_IdMap,
                   nFirstElement: 0,
                   nCount: this->m_IdMap.m_EntryMemory.m_BlocksAllocated,
                   pHandles: v28);
      CResourceTypeManagerFileAtomic::sm_pIdHashTable = &v3->m_IdMap;
      v8 = &v28[Elements];
      nCount = Elements;
      if ( 4 * Elements > 4 )
        std::_Make_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
          _First: v28,
          _Last: &v28[Elements],
          _Pred: CResourceTypeManagerFileAtomic::SortLessFunc);
      std::_Sort_heap<int *,bool (__cdecl *)(int const &,int const &)>(
        _First: (char *)v28,
        _Last: v8,
        _Pred: CResourceTypeManagerFileAtomic::SortLessFunc);
      v9 = 0;
      for ( CResourceTypeManagerFileAtomic::sm_pIdHashTable = nullptr; v9 < nCount; ++v9 )
      {
        if ( (int)nBytesNeeded + v3->m_nMemoryUsed <= v3->m_nMemoryLimit )
          break;
        if ( (*(_BYTE *)(v28[v9] + 16) & 0x10) == 0 )
        {
          if ( *(_DWORD *)(v28[v9] + 8) == 0 )
            break;
          CResourceTypeManagerFileAtomic::M_UncacheResource(
            this: v3,
            pResourceData: (CResourceTypeManagerFileAtomic::ResourceData_t *)(v28[v9] + 8));
        }
      }
      m_nMemoryLimit = v3->m_nMemoryLimit;
      m_nMemoryUsed = v3->m_nMemoryUsed;
      v10 = m_nMemoryUsed;
      nCount = m_nMemoryLimit;
      if ( (int)nBytesNeeded + m_nMemoryUsed > m_nMemoryLimit )
      {
        m_pMemory = (int)toCacheList[1].m_pMemory;
        v14 = m_pMemory - 1;
        nToCache = m_pMemory;
        nToRemove = 0;
        if ( m_pMemory - 1 >= 0 )
        {
          v15 = v14;
          while ( (int)nBytesNeeded + v10 > nCount )
          {
            nBytesNeeded = (CResourceTypeManagerFileAtomic::ToCacheHandle_t *)((char *)nBytesNeeded
                                                                             - *((_DWORD *)toCacheList->m_pMemory[v15].m_hFile
                                                                               + 5));
            ++nToRemove;
            --v14;
            --v15;
            if ( v14 < 0 )
              break;
            v10 = m_nMemoryUsed;
          }
          v3 = v32;
        }
        if ( nToRemove > 0 )
        {
          v16 = 12 * m_pMemory;
          nCount = 12 * m_pMemory;
          m_nMemoryUsed = nToRemove;
          do
          {
            toCache = (CResourceTypeManagerFileAtomic::ToCacheHandle_t *)((char *)toCacheList->m_pMemory + v16);
            if ( toCache->m_bWasRequested )
            {
              Next = v3->m_CacheRequests.m_FreeNodes.m_Head.value.Next;
              value64_high = HIDWORD(v3->m_CacheRequests.m_FreeNodes.m_Head.value64);
              p_m_FreeNodes = &v3->m_CacheRequests.m_FreeNodes;
              if ( Next != nullptr )
              {
                while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                           a1: p_m_FreeNodes,
                                           a2: Next->Next,
                                           a3: value64_high - 1,
                                           a4: Next,
                                           a5: value64_high) == 0 )
                {
                  _mm_pause();
                  Next = p_m_FreeNodes->m_Head.value.Next;
                  value64_high = HIDWORD(p_m_FreeNodes->m_Head.value64);
                  if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
                    goto LABEL_24;
                }
                v20 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)Next;
                *((_DWORD *)&Next->Next + 1) = toCache->m_hResource;
              }
              else
              {
LABEL_24:
                v20 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)operator new(nSize: 8u);
                if ( v20 != nullptr )
                  v20->elem.m_hFile = (void *)toCache->m_hResource;
                else
                  v20 = nullptr;
              }
              CTSQueue<ResourceBindingBase_t const *,0>::Push(
                this: (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *)&v32->m_CacheRequests,
                pNode: v20);
              m_pMemory = nToCache;
              v16 = nCount;
              v3 = v32;
            }
            v16 -= 12;
            v21 = m_nMemoryUsed-- == 1;
            nCount = v16;
          }
          while ( !v21 );
        }
        v22 = m_pMemory - nToRemove - (unsigned int)toCacheList[1].m_pMemory;
        if ( v22 <= 0 )
        {
          if ( v22 < 0 )
            toCacheList[1].m_pMemory = (CResourceSystem::PendingResourceIdResolution_t *)((char *)toCacheList[1].m_pMemory
                                                                                        + v22);
        }
        else
        {
          v23 = (int)toCacheList[1].m_pMemory;
          m_nAllocationCount = toCacheList->m_nAllocationCount;
          v25 = v23 + v22;
          if ( v23 + v22 > m_nAllocationCount )
          {
            CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
              this: toCacheList,
              num: v22 + v23 - m_nAllocationCount);
            v25 = v23 + v22;
          }
          toCacheList[1].m_pMemory = (CResourceSystem::PendingResourceIdResolution_t *)((char *)toCacheList[1].m_pMemory
                                                                                      + v22);
          v26 = (CResourceTypeManagerFileAtomic::ToCacheHandle_t *)toCacheList->m_pMemory;
          v27 = (int)toCacheList[1].m_pMemory - v23 - v22;
          v21 = (CResourceSystem::PendingResourceIdResolution_t *)((char *)toCacheList[1].m_pMemory - v23) == (CResourceSystem::PendingResourceIdResolution_t *)v22;
          toCacheList[1].m_nAllocationCount = (int)toCacheList->m_pMemory;
          if ( v27 >= 0 && !v21 )
            _V_memmove(dest: &v26[v25], src: &v26[v23], count: 12 * v27);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ACE0
// Name: private: void CResourceTypeManagerFileAtomic::IO_OnResourceFileLoaded(class IAsyncFileRequest __near *,struct ResourceBindingBase_t const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CResourceTypeManagerFileAtomic::IO_OnResourceFileLoaded(
        CResourceTypeManagerFileAtomic *this@<ecx>,
        int a2@<edi>,
        IAsyncFileRequest *pRequest,
        const ResourceBindingBase_t *hResource,
        void *hFile,
        CFunctor_vtbl *a6)
{
  AsyncRequestStatus_t v7; // eax
  IAsyncFileRequest_vtbl *v8; // edx
  const char *(__thiscall *GetFileName)(IAsyncFileRequest *); // eax
  const char *v10; // eax
  int v11; // edi
  const char *v12; // eax
  IAsyncFileRequest *v13; // esi
  CFunctor *v14; // eax
  RSTEResourceLoadFailed_t failedCmd; // [esp+4h] [ebp-110h] BYREF
  char pDctFileName[260]; // [esp+Ch] [ebp-108h] BYREF

  v7 = pRequest->GetRequestStatus(this: pRequest);
  v8 = pRequest->__vftable;
  if ( v7 != ASYNC_REQUEST_OK )
  {
    *(_DWORD *)pDctFileName = hResource;
    GetFileName = v8->GetFileName;
    failedCmd.m_hResource = nullptr;
    v10 = GetFileName(this: pRequest);
    _Warning(a1: "Unable to stream in resource file \"%s\"", v10);
    CResourceTypeManagerFileAtomic::PostResourceThreadEventInternal(
      this,
      pMsg: (unsigned __int8 *)&failedCmd.m_hResource,
      nSize: 8u);
  }
  else
  {
    v11 = ((int (__thiscall *)(IAsyncFileRequest *, int))v8->GetResultBuffer)(a1: pRequest, a2);
    pRequest->KeepResultBuffer(this: pRequest);
    v12 = pRequest->GetFileName(this: pRequest);
    V_strncpy(pDest: &pDctFileName[8], pSrc: v12, maxLen: 260);
    V_SetExtension(path: &pDctFileName[8], extension: "dct", pathStringLength: 260);
    v13 = g_pAsyncFileSystem->CreateNewFileRequest(this: g_pAsyncFileSystem);
    v13->LoadFile(this: v13, a2: &pDctFileName[8]);
    v13->ProvideDataBuffer(this: v13);
    v14 = (CFunctor *)operator new(nSize: 0x28u);
    if ( v14 != nullptr )
    {
      v14[1].m_nUserID = 1;
      v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor4<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(IAsyncFileRequest *,ResourceBindingBase_t const *,void *,void *),IAsyncFileRequest *,ResourceBindingBase_t const *,void *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor4<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(IAsyncFileRequest *,ResourceBindingBase_t const *,void *,void *),IAsyncFileRequest *,ResourceBindingBase_t const *,void *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v14[2].__vftable = (CFunctor_vtbl *)CResourceTypeManagerFileAtomic::IO_OnResourceFileDctLoaded;
      v14[2].m_nUserID = (unsigned int)this;
      v14[3].__vftable = (CFunctor_vtbl *)v13;
      v14[3].m_nUserID = (unsigned int)hFile;
      v14[4].__vftable = a6;
      v14[4].m_nUserID = v11;
    }
    else
    {
      v14 = nullptr;
    }
    v13->AssignCallback(this: v13, a2: v14);
    g_pAsyncFileSystem->SubmitAsyncFileRequest(this: g_pAsyncFileSystem, a2: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AE20
// Name: private: void CResourceTypeManagerFileAtomic::M_CacheRequestedResources(class CUtlVector<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,class CUtlMemory<struct CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CResourceTypeManagerFileAtomic::M_CacheRequestedResources(
        CResourceTypeManagerFileAtomic *this@<ecx>,
        int a2@<edi>,
        _DWORD *a3@<esi>,
        CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int> > *toCacheList)
{
  int v5; // ebp
  const ResourceBindingBase_t *m_hResource; // edi
  _BYTE *m_pData; // eax
  int v8; // esi
  _DWORD *v9; // eax
  int m_Size; // [esp+Ch] [ebp-10Ch]
  char pDtaFileName[260]; // [esp+10h] [ebp-108h] BYREF

  if ( toCacheList->m_Size > 0 )
  {
    v5 = 0;
    m_Size = toCacheList->m_Size;
    do
    {
      m_hResource = toCacheList->m_Memory.m_pMemory[v5].m_hResource;
      m_pData = m_hResource[1].m_pData;
      m_hResource->m_nFlags |= 0x10u;
      if ( m_pData != nullptr )
        m_pData = (_BYTE *)(CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::Find(
                              this: &g_pResourceSystemImp->m_FileData,
                              uiKey: m_pData)
                          + 8);
      if ( (m_pData[8] & 4) != 0 )
      {
        *(_DWORD *)pDtaFileName = m_hResource[1].m_pData;
        CUtlFilenameSymbolTable::String(
          this: &g_pResourceSystemImp->m_FileSymbols,
          handle: (void *const *)pDtaFileName,
          buf: &pDtaFileName[4],
          buflen: 260);
        V_SetExtension(path: &pDtaFileName[4], extension: "dta", pathStringLength: 260);
        v8 = ((int (__thiscall *)(IAsyncFileSystem *, int, _DWORD *))g_pAsyncFileSystem->CreateNewFileRequest)(
               a1: g_pAsyncFileSystem,
               a2,
               a3);
        (*(void (__thiscall **)(int, char *))(*(_DWORD *)v8 + 52))(a1: v8, a2: &pDtaFileName[12]);
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
        v9 = operator new(nSize: 0x24u);
        if ( v9 != nullptr )
        {
          v9[3] = 1;
          *v9 = &CMemberFunctor3<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(IAsyncFileRequest *,ResourceBindingBase_t const *,void *),IAsyncFileRequest *,ResourceBindingBase_t const *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v9[2] = &CMemberFunctor3<CResourceTypeManagerFileAtomic *,void (__thiscall CResourceTypeManagerFileAtomic::*)(IAsyncFileRequest *,ResourceBindingBase_t const *,void *),IAsyncFileRequest *,ResourceBindingBase_t const *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v9[4] = CResourceTypeManagerFileAtomic::IO_OnResourceFileLoaded;
          v9[5] = this;
          v9[6] = v8;
          v9[7] = m_hResource;
          v9[8] = m_hResource[1].m_pData;
        }
        else
        {
          v9 = nullptr;
        }
        a3 = v9;
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
        a2 = v8;
        ((void (__thiscall *)(IAsyncFileSystem *))g_pAsyncFileSystem->SubmitAsyncFileRequest)(a1: g_pAsyncFileSystem);
      }
      ++v5;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AF50
// Name: public: virtual void CResourceTypeManagerFileAtomic::FrameUpdate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceTypeManagerFileAtomic::FrameUpdate(
        CResourceTypeManagerFileAtomic *this,
        int nFinishedFrameCount)
{
  int v3; // eax
  __int64 v4; // kr00_8
  CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int> > toCacheList; // [esp+8h] [ebp-18h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  CUtlTSHash<CResourceTypeManagerFileAtomic::ResourceData_t,1021,unsigned int,CUtlTSHashGenericHash<1021,unsigned int>,0>::Commit(this: &this->m_IdMap);
  CResourceTypeManagerFileAtomic::M_ProcessResourceThreadEvents(this);
  CResourceTypeManagerFileAtomic::M_DeleteRequestedResources(this);
  CResourceTypeManagerFileAtomic::M_UncacheRequestedResources(this);
  memset(&toCacheList.m_Memory.m_nAllocationCount, 0, 16);
  v6 = 0;
  v3 = CResourceTypeManagerFileAtomic::M_BuildRequestedResourcesList(
         this,
         toCacheList: (CUtlVector<CResourceSystem::PendingResourceIdResolution_t,CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> > *)&toCacheList.m_Memory.m_nAllocationCount);
  v4 = CResourceTypeManagerFileAtomic::M_BuildToCacheList(
         this,
         toCacheList: (CUtlVector<CResourceSystem::PendingResourceIdResolution_t,CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> > *)&toCacheList.m_Memory.m_nAllocationCount,
         nFinishedFrameCount)
     + (__int64)v3;
  CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::Sort(
    this: (CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int> > *)&toCacheList.m_Memory.m_nAllocationCount,
    pfnCompare: (int (__cdecl *)(const void *, const void *))CResourceTypeManagerFileAtomic::ResourceSizeComparisonFunc);
  CResourceTypeManagerFileAtomic::M_EvictResources(
    this,
    toCacheList: (CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> *)&toCacheList.m_Memory.m_nAllocationCount,
    nBytesNeeded: (CResourceTypeManagerFileAtomic::ToCacheHandle_t *)v4);
  CResourceTypeManagerFileAtomic::M_CacheRequestedResources(
    this,
    a2: v4,
    a3: this,
    toCacheList: (CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int> > *)&toCacheList.m_Memory.m_nAllocationCount);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&toCacheList.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000CD40
// Name: public: int CUtlVector<unsigned int __near *,class CUtlMemory<unsigned int __near *,int>>::InsertBefore(int,unsigned int __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned int *,CUtlMemory<unsigned int *,int>>::InsertBefore(
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *this,
        int elem,
        KeyValues **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  KeyValues **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  KeyValues **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned int,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF60
// Name: public: virtual void CDefaultFileAtomicConstructor::DeallocatePermanentData(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultFileAtomicConstructor::DeallocatePermanentData(
        CSchemaClassBinding<CResourceTypedefIntrospection> *this,
        void *pMemory)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1001D820
// Name: _dynamic_initializer_for__CResourceTypeManagerFileAtomic::sm_DefaultResourceData__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void dynamic_initializer_for__CResourceTypeManagerFileAtomic::sm_DefaultResourceData__()
{
  CResourceTypeManagerFileAtomic::sm_DefaultResourceData.m_Resource.m_nRefCount.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001D830
// Name: _dynamic_initializer_for__s_nAnonymousCounter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__s_nAnonymousCounter__()
{
  s_nAnonymousCounter.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001D840
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1001D850
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  s_EmptyConVar.m_Value.m_StringLength = strlen("0") + 1;
  s_EmptyConVar.m_Value.m_pszString = (char *)operator new(nSize: s_EmptyConVar.m_Value.m_StringLength);
  memcpy(
    dst: (unsigned __int8 *)s_EmptyConVar.m_Value.m_pszString,
    src: (unsigned __int8 *)s_EmptyConVar.m_pszDefaultValue,
    count: s_EmptyConVar.m_Value.m_StringLength);
  if ( !ConVar::InternalSetColorFromString(this: &s_EmptyConVar, value: s_EmptyConVar.m_Value.m_pszString) )
  {
    s_EmptyConVar.m_Value.m_fValue = atof(nptr: s_EmptyConVar.m_Value.m_pszString);
    if ( (LODWORD(s_EmptyConVar.m_Value.m_fValue) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "ConVar(%s) defined with infinite float value (%s)\n", &setName, s_EmptyConVar.m_Value.m_pszString);
      s_EmptyConVar.m_Value.m_fValue = 3.4028235e38;
    }
    s_EmptyConVar.m_Value.m_nValue = (int)s_EmptyConVar.m_Value.m_fValue;
  }
  s_EmptyConVar.m_bRegistered = false;
  s_EmptyConVar.m_pszName = &setName;
  s_EmptyConVar.m_pszHelpString = empty_string;
  s_EmptyConVar.m_nFlags = 0;
  s_EmptyConVar.m_pNext = ConCommandBase::s_pConCommandBases;
  ConCommandBase::s_pConCommandBases = &s_EmptyConVar;
  if ( ConCommandBase::s_pAccessor != nullptr )
    s_EmptyConVar.Init(this: &s_EmptyConVar);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&CEmptyConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&CEmptyConVar::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x1001D980
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x1001D9A0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001D9B0
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
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
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
// Address: 0x1001DA10
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
