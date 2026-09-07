// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/eventsystem.cpp
// Functions: 27
// ============================================================

#include "vstdlib\eventsystem.h"

//------------------------------------------------------------------------------
// Address: 0x10007780
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  TSLNodeBase_t *v5; // [esp-8h] [ebp-14h]
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v7 = this->m_Head.value32.DepthAndSequence;
      v5 = this->m_Head.value.Next;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100077E0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10007820
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
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: this->m_Head.value32.DepthAndSequence & 0xFFFF0000,
                            a4: Next,
                            a5: this->m_Head.value32.DepthAndSequence) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10007870
// Name: public: int CUtlTSHash<class CEventId,251,unsigned int,class CUtlTSHashGenericHash<251,unsigned int>,8>::GetElements(int,int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::GetElements(
        CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8> *this,
        int nFirstElement,
        int nCount,
        int *pHandles)
{
  int v4; // esi
  int v5; // ebx
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> **i; // edi
  int v7; // eax

  v4 = 0;
  v5 = 0;
  for ( i = &this->m_aBuckets[0].m_pFirstUncommitted; ; i += 4 )
  {
    CThreadSpinRWLock::LockForRead(this: (CThreadSpinRWLock *)(i + 1));
    v7 = (int)*i;
    if ( *i != nullptr )
      break;
LABEL_6:
    _InterlockedExchangeAdd((volatile signed __int32 *)i + 1, 0xFFFFFFFF);
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
  _InterlockedExchangeAdd((volatile signed __int32 *)i + 1, 0xFFFFFFFF);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100078E0
// Name: public: CTSQueue<struct CEventQueue::QueuedEvent_t,0,1>::CTSQueue<struct CEventQueue::QueuedEvent_t,0,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CEventQueue::QueuedEvent_t,0,1> *__thiscall CTSQueue<CEventQueue::QueuedEvent_t,0,1>::CTSQueue<CEventQueue::QueuedEvent_t,0,1>(
        CTSQueue<CEventQueue::QueuedEvent_t,0,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *v3; // eax

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
  v3 = (CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *)operator new(nSize: 0x10u);
  this->m_Tail.value.pNode = v3;
  this->m_Head.value.pNode = v3;
  v3->pNext = (CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007970
// Name: public: int CUtlTSHash<class CEventId,251,unsigned int,class CUtlTSHashGenericHash<251,unsigned int>,8>::Find(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *__thiscall CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::Find(
        CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8> *this,
        unsigned int uiKey)
{
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *result; // eax
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashBucket_t *v3; // esi
  CThreadSpinRWLock *p_m_AddLock; // edi
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *m_pFirst; // esi

  result = this->m_aBuckets[((unsigned __int8)(((HIBYTE(uiKey)
                                               + 33
                                               * (BYTE2(uiKey)
                                                + 33
                                                * (BYTE1(uiKey)
                                                 + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16)
                                             ^ (HIBYTE(uiKey)
                                              + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * (uiKey - 86)))))
                           ^ (unsigned __int8)((unsigned __int16)(((HIBYTE(uiKey)
                                                                  + 33
                                                                  * (BYTE2(uiKey)
                                                                   + 33
                                                                   * (BYTE1(uiKey)
                                                                    + 33
                                                                    * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16)
                                                                ^ (HIBYTE(uiKey)
                                                                 + 33
                                                                 * (BYTE2(uiKey)
                                                                  + 33
                                                                  * (BYTE1(uiKey) + 33
                                                                                  * ((unsigned __int8)uiKey - 21846))))) >> 8))
                          & 0xFA].m_pFirst;
  v3 = &this->m_aBuckets[((unsigned __int8)(((HIBYTE(uiKey)
                                            + 33
                                            * (BYTE2(uiKey)
                                             + 33
                                             * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16)
                                          ^ (HIBYTE(uiKey)
                                           + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * (uiKey - 86)))))
                        ^ (unsigned __int8)((unsigned __int16)(((HIBYTE(uiKey)
                                                               + 33
                                                               * (BYTE2(uiKey)
                                                                + 33
                                                                * (BYTE1(uiKey)
                                                                 + 33
                                                                 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16)
                                                             ^ (HIBYTE(uiKey)
                                                              + 33
                                                              * (BYTE2(uiKey)
                                                               + 33
                                                               * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))) >> 8))
                       & 0xFA];
  if ( result != nullptr )
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
    p_m_AddLock = &this->m_aBuckets[((unsigned __int8)(((HIBYTE(uiKey)
                                                       + 33
                                                       * (BYTE2(uiKey)
                                                        + 33
                                                        * (BYTE1(uiKey)
                                                         + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16)
                                                     ^ (HIBYTE(uiKey)
                                                      + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * (uiKey - 86)))))
                                   ^ (unsigned __int8)((unsigned __int16)(((HIBYTE(uiKey)
                                                                          + 33
                                                                          * (BYTE2(uiKey)
                                                                           + 33
                                                                           * (BYTE1(uiKey)
                                                                            + 33
                                                                            * ((unsigned int)(unsigned __int8)uiKey
                                                                             - 1431655766)))) >> 16)
                                                                        ^ (HIBYTE(uiKey)
                                                                         + 33
                                                                         * (BYTE2(uiKey)
                                                                          + 33
                                                                          * (BYTE1(uiKey)
                                                                           + 33 * ((unsigned __int8)uiKey - 21846))))) >> 8))
                                  & 0xFA].m_AddLock;
    CThreadSpinRWLock::LockForRead(this: p_m_AddLock);
    result = v3->m_pFirstUncommitted;
    m_pFirst = v3->m_pFirst;
    if ( result == m_pFirst )
    {
LABEL_7:
      result = nullptr;
    }
    else
    {
      while ( result->m_uiKey != uiKey )
      {
        result = result->m_pNext;
        if ( result == m_pFirst )
          goto LABEL_7;
      }
    }
    _InterlockedExchangeAdd((volatile signed __int32 *)p_m_AddLock, 0xFFFFFFFF);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007A20
// Name: private: int CUtlTSHash<class CEventId,251,unsigned int,class CUtlTSHashGenericHash<251,unsigned int>,8>::InsertUncommitted(unsigned int,struct CUtlTSHash<class CEventId,251,unsigned int,class CUtlTSHashGenericHash<251,unsigned int>,8>::HashBucket_t __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *__thiscall CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::InsertUncommitted(
        CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8> *this,
        unsigned int uiKey,
        CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashBucket_t *bucket)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *result; // eax

  this->m_bNeedsCommit = true;
  p_m_mutex = &this->m_EntryMemory.m_mutex;
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
  result = (CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *)CUtlMemoryPool::Alloc(this: &this->m_EntryMemory);
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  result->m_pNext = bucket->m_pFirstUncommitted;
  bucket->m_pFirstUncommitted = result;
  result->m_uiKey = uiKey;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007B40
// Name: public: struct CTSQueue<struct CEventQueue::QueuedEvent_t,0,1>::Node_t __near * CTSQueue<struct CEventQueue::QueuedEvent_t,0,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *__thiscall CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Pop(
        CTSQueue<CEventQueue::QueuedEvent_t,0,1> *this)
{
  CTSQueue<CEventQueue::QueuedEvent_t,0,1> *v1; // esi
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *pNext; // eax
  CFunctorCallback *m_pCallback; // edi
  __int64 v5; // [esp-Ch] [ebp-38h]
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *elem; // [esp+0h] [ebp-2Ch]
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::NodeLink_t *head_4; // [esp+10h] [ebp-1Ch]
  int *pHead; // [esp+18h] [ebp-14h]
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::NodeLink_t *pTailNode; // [esp+1Ch] [ebp-10h]

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
          elem = v1->m_Head.value.pNode;
          pNext = v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( elem != head_4->value.pNode )
          break;
        if ( pNext == (CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *)v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: pTailNode->value.sequence + 1,
          a4: elem,
          a5: pTailNode->value.sequence);
      }
    }
    while ( pNext == (CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *)v1 );
    m_pCallback = pNext->elem.m_pCallback;
    v5 = *(_QWORD *)&pNext->elem.m_pTarget;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNext, a3: *pHead + 1, a4: elem, a5: *pHead) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  *(_QWORD *)&elem->elem.m_pTarget = v5;
  elem->elem.m_pCallback = m_pCallback;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10007C30
// Name: public: int CUtlTSHash<class CEventId,251,unsigned int,class CUtlTSHashGenericHash<251,unsigned int>,8>::Insert(unsigned int,class ITSHashConstructor<class CEventId> __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *__thiscall CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::Insert(
        CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8> *this,
        unsigned int uiKey,
        ITSHashConstructor<CEventId> *pConstructor,
        bool *pDidInsert)
{
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *result; // eax
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashBucket_t *v6; // esi
  CThreadSpinRWLock *p_m_AddLock; // edi
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *m_pFirstUncommitted; // eax
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *inserted; // esi

  if ( pDidInsert != nullptr )
    *pDidInsert = false;
  result = CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::Find(this, uiKey);
  if ( result == nullptr )
  {
    v6 = &this->m_aBuckets[((unsigned __int8)(((HIBYTE(uiKey)
                                              + 33
                                              * (BYTE2(uiKey)
                                               + 33
                                               * (BYTE1(uiKey) + 33
                                                               * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16)
                                            ^ (HIBYTE(uiKey)
                                             + 33 * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * (uiKey - 86)))))
                          ^ (unsigned __int8)((unsigned __int16)(((HIBYTE(uiKey)
                                                                 + 33
                                                                 * (BYTE2(uiKey)
                                                                  + 33
                                                                  * (BYTE1(uiKey)
                                                                   + 33
                                                                   * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16)
                                                               ^ (HIBYTE(uiKey)
                                                                + 33
                                                                * (BYTE2(uiKey)
                                                                 + 33
                                                                 * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))) >> 8))
                         & 0xFA];
    p_m_AddLock = &v6->m_AddLock;
    if ( (v6->m_AddLock.m_lockInfo.m_i32 & 0x10000) != 0
      || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
    {
      CThreadSpinRWLock::SpinLockForWrite(this: &v6->m_AddLock);
    }
    else
    {
      v6->m_AddLock.m_writerId = GetCurrentThreadId();
    }
    m_pFirstUncommitted = v6->m_pFirstUncommitted;
    if ( m_pFirstUncommitted == v6->m_pFirst )
    {
LABEL_11:
      inserted = CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::InsertUncommitted(
                   this,
                   uiKey,
                   bucket: v6);
      pConstructor->Construct(this: pConstructor, a2: &inserted->m_Data);
      if ( pDidInsert != nullptr )
        *pDidInsert = true;
    }
    else
    {
      while ( m_pFirstUncommitted->m_uiKey != uiKey )
      {
        m_pFirstUncommitted = m_pFirstUncommitted->m_pNext;
        if ( m_pFirstUncommitted == v6->m_pFirst )
          goto LABEL_11;
      }
      inserted = m_pFirstUncommitted;
    }
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    return inserted;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007ED0
// Name: public: virtual struct EventId_t__ __near * CEventSystem::RegisterEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CEventId *__thiscall CEventSystem::RegisterEvent(CEventSystem *this, const char *pEventName)
{
  const char *v2; // edi
  int v4; // eax
  unsigned int v5; // eax

  v2 = pEventName;
  v4 = _V_strlen(str: pEventName);
  v5 = MurmurHash2(key: v2, len: v4, seed: 0xE1E47644);
  pEventName = (const char *)&CDefaultTSHashConstructor<CEventId>::`vftable';
  return &CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::Insert(
            this: &this->m_EventIds,
            uiKey: v5,
            pConstructor: (ITSHashConstructor<CEventId> *)&pEventName,
            pDidInsert: nullptr)->m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x10007F20
// Name: public: void CTSQueue<struct CEventQueue::QueuedEvent_t,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Purge(CTSQueue<CEventQueue::QueuedEvent_t,0,1> *this)
{
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  for ( i = CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Pop(this);
        i != nullptr;
        i = CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Pop(this) )
  {
    free(pMem: i);
  }
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
// Address: 0x10007FB0
// Name: private: void CEventQueue::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue::Cleanup(CEventQueue *this)
{
  CTSQueue<CEventQueue::QueuedEvent_t,0,1> *p_m_Queue; // edi
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *v2; // eax
  CFunctorCallback *m_pCallback; // esi
  __int64 event; // [esp+8h] [ebp-Ch]

  p_m_Queue = &this->m_Queue;
  while ( 1 )
  {
    v2 = CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Pop(this: p_m_Queue);
    if ( v2 == nullptr )
      break;
    m_pCallback = v2->elem.m_pCallback;
    event = *(_QWORD *)&v2->elem.m_pTarget;
    CTSListBase::Push(this: &p_m_Queue->m_FreeNodes, pNode: (TSLNodeBase_t *)v2);
    m_pCallback->Release(this: m_pCallback);
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(event) + 4))(a1: HIDWORD(event));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008000
// Name: public: void CEventId::PostEvent(class CEventQueue __near *,void const __near *,class CFunctorData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventId::PostEvent(
        CEventId *this,
        CEventQueue *pEventQueue,
        const void *pListener,
        CFunctorData *pData)
{
  CThreadSpinRWLock *p_m_ListenerLock; // ebx
  signed __int32 m_i32; // ecx
  CEventQueue **i; // edi
  CEventQueue *v8; // esi
  CEventQueue *v9; // ebx
  TSLNodeBase_t *v10; // eax
  TSLNodeBase_t v11; // [esp+Ch] [ebp-10h]
  CThreadSpinRWLock *v12; // [esp+18h] [ebp-4h]

  p_m_ListenerLock = &this->m_ListenerLock;
  v12 = &this->m_ListenerLock;
  if ( (this->m_ListenerLock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_ListenerLock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_ListenerLock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: p_m_ListenerLock);
  }
  for ( i = (CEventQueue **)this->m_SubscribedQueueList.m_Head; i != nullptr; i = (CEventQueue **)i[3] )
  {
    if ( (pEventQueue == nullptr || *i == pEventQueue)
      && (pListener == nullptr
       || pListener == (const void *)((int (__thiscall *)(CEventQueue *))i[1]->m_QueuedEventDiscards.m_Head.value.pNode[3].pNext)(a1: i[1])) )
    {
      v8 = i[1];
      v9 = *i;
      *((_DWORD *)&v11.Next + 1) = pData;
      ((void (__thiscall *)(CEventQueue *))v8->m_QueuedEventDiscards.m_Head.value.pNode->pNext)(a1: v8);
      pData->AddRef(this: pData);
      v10 = CTSListBase::Pop(this: &v9->m_Queue.m_FreeNodes);
      if ( v10 != nullptr )
      {
        *(TSLNodeBase_t *)((char *)v10 + 4) = v11;
        *((_DWORD *)&v10[1].Next + 1) = v8;
      }
      else
      {
        v10 = (TSLNodeBase_t *)operator new(nSize: 0x10u);
        if ( v10 != nullptr )
        {
          *(TSLNodeBase_t *)((char *)v10 + 4) = v11;
          *((_DWORD *)&v10[1].Next + 1) = v8;
        }
        else
        {
          v10 = nullptr;
        }
      }
      CTSQueue<CFunctorCallback *,0,1>::Push(this: &v9->m_Queue, pNode: (CTSQueue<CJob *,0,1>::Node_t *)v10);
      p_m_ListenerLock = v12;
    }
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_ListenerLock, 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x10008130
// Name: public: virtual void CEventSystem::PostEventInternal(struct EventId_t__ __near *,struct EventQueue_t__ __near *,void const __near *,class CFunctorData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventSystem::PostEventInternal(
        CEventSystem *this,
        EventId_t__ *nEventId,
        EventQueue_t__ *hQueue,
        const void *pListener,
        CFunctorData *pData)
{
  if ( nEventId != nullptr )
    CEventId::PostEvent(this: (CEventId *)nEventId, pEventQueue: (CEventQueue *)hQueue, pListener, pData);
  pData->Release(this: pData);
}

//------------------------------------------------------------------------------
// Address: 0x10008160
// Name: public: void CEventQueue::ProcessEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue::ProcessEvents(CEventQueue *this)
{
  CEventQueue *v1; // esi
  volatile int m_value; // eax
  CTSQueue<CEventQueue::QueuedEvent_t,0,1> *v3; // ebx
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *v4; // eax
  CFunctorCallback *v5; // esi
  volatile int v6; // eax
  int m_Size; // edi
  CFunctorCallback **m_pMemory; // ebx
  CTSQueue<CFunctorCallback *,0,1>::Node_t *v9; // eax
  int v10; // esi
  CFunctorCallback **v11; // esi
  CFunctorCallback *p_m_Queue; // esi
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *v13; // edi
  CFunctorCallback_vtbl *v14; // ecx
  CFunctorCallback_vtbl *v15; // eax
  CFunctorCallback *m_pCallback; // ebx
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t **v17; // esi
  CFunctorData *m_pData; // esi
  int v19; // eax
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *v20; // [esp-8h] [ebp-3Ch]
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *v21; // [esp-4h] [ebp-38h]
  CUtlVector<CFunctorCallback *,CUtlMemory<CFunctorCallback *,int> > callbacks; // [esp+Ch] [ebp-28h] BYREF
  CEventQueue::QueuedEvent_t event; // [esp+20h] [ebp-14h]
  CFunctorCallback *pCallback; // [esp+2Ch] [ebp-8h]
  CEventQueue *v25; // [esp+30h] [ebp-4h]

  v1 = this;
  m_value = this->m_QueuedEventDiscards.m_Count.m_value;
  v25 = this;
  if ( m_value != 0 )
  {
    v6 = this->m_QueuedEventDiscards.m_Count.m_value;
    m_Size = 0;
    m_pMemory = nullptr;
    callbacks.m_Memory.m_pMemory = nullptr;
    callbacks.m_Memory.m_nAllocationCount = v6;
    callbacks.m_Memory.m_nGrowSize = 0;
    if ( v6 != 0 )
    {
      callbacks.m_Memory.m_pMemory = (CFunctorCallback **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v6);
      m_pMemory = callbacks.m_Memory.m_pMemory;
    }
    callbacks.m_Size = 0;
    callbacks.m_pElements = m_pMemory;
    while ( 1 )
    {
      v9 = CTSQueue<CJob *,0,1>::Pop(this: &v1->m_QueuedEventDiscards);
      if ( v9 == nullptr )
        break;
      pCallback = v9->elem;
      CTSListBase::Push(this: &v1->m_QueuedEventDiscards.m_FreeNodes, pNode: (TSLNodeBase_t *)v9);
      v10 = m_Size;
      if ( m_Size + 1 > callbacks.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CCoroutineMgr *,int> *)&callbacks,
          num: m_Size - callbacks.m_Memory.m_nAllocationCount + 1);
        m_Size = callbacks.m_Size;
        m_pMemory = callbacks.m_Memory.m_pMemory;
      }
      callbacks.m_Size = ++m_Size;
      callbacks.m_pElements = m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
      v11 = &m_pMemory[v10];
      if ( v11 != nullptr )
        *v11 = pCallback;
      v1 = v25;
    }
    p_m_Queue = (CFunctorCallback *)&v1->m_Queue;
    for ( pCallback = p_m_Queue; ; p_m_Queue = pCallback )
    {
      v13 = CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Pop(this: (CTSQueue<CEventQueue::QueuedEvent_t,0,1> *)p_m_Queue);
      if ( v13 == nullptr )
        break;
      v14 = p_m_Queue[7].__vftable;
      v15 = p_m_Queue[6].__vftable;
      m_pCallback = v13->elem.m_pCallback;
      v17 = (CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t **)&p_m_Queue[6];
      *(_QWORD *)&event.m_pTarget = *(_QWORD *)&v13->elem.m_pTarget;
      v13->pNext = (CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Node_t *)v15;
      if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                              a1: v17,
                              a2: v13,
                              a3: (char *)&v14[2340].ComputeValidationString + 1,
                              a4: v15,
                              a5: v14) == 0 )
      {
        do
        {
          _mm_pause();
          v21 = v17[1];
          v20 = *v17;
          v13->pNext = *v17;
        }
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                   a1: v17,
                                   a2: v13,
                                   a3: (char *)&v21[4096].pNext + 1,
                                   a4: v20,
                                   a5: v21) == 0 );
      }
      m_pData = event.m_pData;
      v19 = 0;
      if ( callbacks.m_Size <= 0 )
      {
LABEL_23:
        m_pCallback->operator()(this: m_pCallback, a2: event.m_pData);
      }
      else
      {
        while ( m_pCallback != callbacks.m_Memory.m_pMemory[v19] )
        {
          if ( ++v19 >= callbacks.m_Size )
            goto LABEL_23;
        }
      }
      m_pData->Release(this: m_pData);
      m_pCallback->Release(this: m_pCallback);
      m_pMemory = callbacks.m_Memory.m_pMemory;
    }
    if ( callbacks.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else
  {
    v3 = &this->m_Queue;
    while ( 1 )
    {
      v4 = CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Pop(this: v3);
      if ( v4 == nullptr )
        break;
      v5 = v4->elem.m_pCallback;
      *(_QWORD *)&event.m_pTarget = *(_QWORD *)&v4->elem.m_pTarget;
      CTSListBase::Push(this: &v3->m_FreeNodes, pNode: (TSLNodeBase_t *)v4);
      v5->operator()(this: v5, a2: event.m_pData);
      event.m_pData->Release(this: event.m_pData);
      v5->Release(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008330
// Name: public: virtual struct EventQueue_t__ __near * CEventSystem::CreateEventQueue(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CEventQueue::QueuedEvent_t,0,1> *__thiscall CEventSystem::CreateEventQueue(CEventSystem *this)
{
  CTSQueue<CFunctorCallback *,0,1> *v1; // eax
  CTSQueue<CEventQueue::QueuedEvent_t,0,1> *v2; // esi

  v1 = (CTSQueue<CFunctorCallback *,0,1> *)operator new(nSize: 0x48u);
  v2 = (CTSQueue<CEventQueue::QueuedEvent_t,0,1> *)v1;
  if ( v1 == nullptr )
    return nullptr;
  CTSQueue<CFunctorCallback *,0,1>::CTSQueue<CFunctorCallback *,0,1>(this: v1);
  CTSQueue<CEventQueue::QueuedEvent_t,0,1>::CTSQueue<CEventQueue::QueuedEvent_t,0,1>(this: v2 + 1);
  v2[2].m_Head.value.pNode = nullptr;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10008360
// Name: public: virtual void CEventSystem::ProcessEvents(struct EventQueue_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventSystem::ProcessEvents(CEventSystem *this, EventQueue_t__ *hQueue)
{
  if ( hQueue != nullptr )
    CEventQueue::ProcessEvents(this: (CEventQueue *)hQueue);
}

//------------------------------------------------------------------------------
// Address: 0x10008380
// Name: public: void CEventId::UnregisterListener(class CEventQueue __near *,class CFunctorCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventId::UnregisterListener(CEventId *this, CEventQueue *pEventQueue, CFunctorCallback *pCallback)
{
  CThreadSpinRWLock *p_m_ListenerLock; // ebx
  int m_Head; // esi
  CJob *v6; // ebx
  int v7; // eax
  int v8; // eax
  CTSQueue<CJob *,0,1>::Node_t *v9; // eax
  CThreadSpinRWLock *v10; // [esp+Ch] [ebp-4h]

  p_m_ListenerLock = &this->m_ListenerLock;
  v10 = &this->m_ListenerLock;
  if ( (this->m_ListenerLock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)p_m_ListenerLock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: p_m_ListenerLock);
  }
  else
  {
    this->m_ListenerLock.m_writerId = GetCurrentThreadId();
  }
  m_Head = this->m_SubscribedQueueList.m_Head;
  if ( m_Head != 0 )
  {
    while ( *(CEventQueue **)m_Head != pEventQueue
         || (*(unsigned __int8 (__thiscall **)(_DWORD, CFunctorCallback *))(**(_DWORD **)(m_Head + 4) + 8))(
              a1: *(_DWORD *)(m_Head + 4),
              a2: pCallback) == 0 )
    {
      m_Head = *(_DWORD *)(m_Head + 12);
      if ( m_Head == 0 )
        goto LABEL_9;
    }
    v6 = *(CJob **)(m_Head + 4);
    if ( !CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
            (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)this,
            i: m_Head,
            it: (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&this->m_SubscribedQueueList.m_LastAlloc) )
    {
      v7 = *(_DWORD *)(m_Head + 8);
      if ( v7 != m_Head )
      {
        if ( v7 != 0 )
          *(_DWORD *)(v7 + 12) = *(_DWORD *)(m_Head + 12);
        else
          this->m_SubscribedQueueList.m_Head = *(_DWORD *)(m_Head + 12);
        v8 = *(_DWORD *)(m_Head + 12);
        if ( v8 != 0 )
          *(_DWORD *)(v8 + 8) = *(_DWORD *)(m_Head + 8);
        else
          this->m_SubscribedQueueList.m_Tail = *(_DWORD *)(m_Head + 8);
        *(_DWORD *)(m_Head + 12) = m_Head;
        *(_DWORD *)(m_Head + 8) = m_Head;
        --this->m_SubscribedQueueList.m_ElementCount;
      }
    }
    *(_DWORD *)(m_Head + 12) = this->m_SubscribedQueueList.m_FirstFree;
    this->m_SubscribedQueueList.m_FirstFree = m_Head;
    if ( v6->Release(this: v6) > 0 )
    {
      v9 = (CTSQueue<CJob *,0,1>::Node_t *)CTSListBase::Pop(this: &pEventQueue->m_QueuedEventDiscards.m_FreeNodes);
      if ( v9 != nullptr || (v9 = (CTSQueue<CJob *,0,1>::Node_t *)operator new(nSize: 8u)) != nullptr )
        v9->elem = v6;
      else
        v9 = nullptr;
      CTSQueue<CFunctorCallback *,0,1>::Push(this: (CTSQueue<CEventQueue::QueuedEvent_t,0,1> *)pEventQueue, pNode: v9);
    }
    _InterlockedExchangeAdd(&pEventQueue->m_nRefCount.m_value, 0xFFFFFFFF);
    v10->m_writerId = 0;
    v10->m_lockInfo.m_i32 = 0;
  }
  else
  {
LABEL_9:
    p_m_ListenerLock->m_lockInfo.m_i32 = 0;
    p_m_ListenerLock->m_writerId = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100084B0
// Name: public: void CEventId::UnregisterAllListeners(class CEventQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventId::UnregisterAllListeners(CEventId *this, CEventQueue *pEventQueue)
{
  CThreadSpinRWLock *p_m_ListenerLock; // ebx
  int m_Head; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  CThreadSpinRWLock *v8; // [esp+Ch] [ebp-4h]

  p_m_ListenerLock = &this->m_ListenerLock;
  v8 = &this->m_ListenerLock;
  if ( (this->m_ListenerLock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)p_m_ListenerLock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: p_m_ListenerLock);
  }
  else
  {
    this->m_ListenerLock.m_writerId = GetCurrentThreadId();
  }
  m_Head = this->m_SubscribedQueueList.m_Head;
  if ( m_Head != 0 )
  {
    do
    {
      v5 = *(_DWORD *)(m_Head + 12);
      if ( *(CEventQueue **)m_Head == pEventQueue )
      {
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(m_Head + 4) + 4))(a1: *(_DWORD *)(m_Head + 4));
        _InterlockedExchangeAdd(&pEventQueue->m_nRefCount.m_value, 0xFFFFFFFF);
        if ( !CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
                (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)this,
                i: m_Head,
                it: (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&this->m_SubscribedQueueList.m_LastAlloc) )
        {
          v6 = *(_DWORD *)(m_Head + 8);
          if ( v6 != m_Head )
          {
            if ( v6 != 0 )
              *(_DWORD *)(v6 + 12) = *(_DWORD *)(m_Head + 12);
            else
              this->m_SubscribedQueueList.m_Head = *(_DWORD *)(m_Head + 12);
            v7 = *(_DWORD *)(m_Head + 12);
            if ( v7 != 0 )
              *(_DWORD *)(v7 + 8) = *(_DWORD *)(m_Head + 8);
            else
              this->m_SubscribedQueueList.m_Tail = *(_DWORD *)(m_Head + 8);
            *(_DWORD *)(m_Head + 12) = m_Head;
            *(_DWORD *)(m_Head + 8) = m_Head;
            --this->m_SubscribedQueueList.m_ElementCount;
          }
        }
        *(_DWORD *)(m_Head + 12) = this->m_SubscribedQueueList.m_FirstFree;
        this->m_SubscribedQueueList.m_FirstFree = m_Head;
      }
      m_Head = v5;
    }
    while ( v5 != 0 );
    v8->m_writerId = 0;
    v8->m_lockInfo.m_i32 = 0;
  }
  else
  {
    p_m_ListenerLock->m_writerId = 0;
    p_m_ListenerLock->m_lockInfo.m_i32 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100085A0
// Name: public: virtual void CEventSystem::DestroyEventQueue(struct EventQueue_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventSystem::DestroyEventQueue(CEventSystem *this, CEventQueue *hQueue)
{
  int m_BlocksAllocated; // esi
  void *v5; // esp
  int Elements; // eax
  int v7; // esi
  int v8[3]; // [esp+0h] [ebp-10h] BYREF
  CEventSystem *v9; // [esp+Ch] [ebp-4h]
  int nCount; // [esp+18h] [ebp+8h]

  v9 = this;
  if ( hQueue != nullptr )
  {
    if ( hQueue->m_nRefCount.m_value != 0 )
    {
      _Warning(a1: "Perf warning: Forgot to unregister listeners on event queue %X\n", hQueue);
      m_BlocksAllocated = this->m_EventIds.m_EntryMemory.m_BlocksAllocated;
      v5 = alloca(4 * m_BlocksAllocated);
      Elements = CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::GetElements(
                   this: &v9->m_EventIds,
                   nFirstElement: 0,
                   nCount: m_BlocksAllocated,
                   pHandles: v8);
      v7 = 0;
      for ( nCount = Elements; v7 < nCount; ++v7 )
        CEventId::UnregisterAllListeners(this: (CEventId *)(v8[v7] + 8), pEventQueue: hQueue);
    }
    CEventQueue::Cleanup(this: hQueue);
    CTSQueue<CEventQueue::QueuedEvent_t,0,1>::Purge(this: &hQueue->m_Queue);
    free(pMem: hQueue->m_Queue.m_Head.value.pNode);
    CTSListBase::Detach(this: &hQueue->m_Queue.m_FreeNodes);
    CTSQueue<CFunctorCallback *,0,1>::Purge(this: &hQueue->m_QueuedEventDiscards);
    free(pMem: hQueue->m_QueuedEventDiscards.m_Head.value.pNode);
    CTSListBase::Detach(this: &hQueue->m_QueuedEventDiscards.m_FreeNodes);
    free(pMem: hQueue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008670
// Name: public: virtual void CEventSystem::UnregisterListener(struct EventId_t__ __near *,struct EventQueue_t__ __near *,class CFunctorCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventSystem::UnregisterListener(
        CEventSystem *this,
        EventId_t__ *nEventId,
        EventQueue_t__ *hQueue,
        CFunctorCallback *pCallback)
{
  if ( hQueue != nullptr && nEventId != nullptr )
    CEventId::UnregisterListener(this: (CEventId *)nEventId, pEventQueue: (CEventQueue *)hQueue, pCallback);
  pCallback->Release(this: pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x100086A0
// Name: public: void CEventId::RegisterListener(class CEventQueue __near *,class CFunctorCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventId::RegisterListener(CEventId *this, CEventQueue *pEventQueue, CFunctorCallback *pCallback)
{
  CThreadSpinRWLock *p_m_ListenerLock; // esi
  int m_Head; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *v6; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *m_pNext; // eax
  int m_nBlockSize; // eax
  int m_Tail; // eax
  CThreadSpinRWLock *v10; // [esp+Ch] [ebp-4h]

  p_m_ListenerLock = &this->m_ListenerLock;
  v10 = &this->m_ListenerLock;
  if ( (this->m_ListenerLock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)p_m_ListenerLock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: p_m_ListenerLock);
  }
  else
  {
    this->m_ListenerLock.m_writerId = GetCurrentThreadId();
  }
  m_Head = this->m_SubscribedQueueList.m_Head;
  if ( m_Head != 0 )
  {
    while ( *(CEventQueue **)m_Head != pEventQueue
         || (*(unsigned __int8 (__thiscall **)(_DWORD, CFunctorCallback *))(**(_DWORD **)(m_Head + 4) + 8))(
              a1: *(_DWORD *)(m_Head + 4),
              a2: pCallback) == 0 )
    {
      m_Head = *(_DWORD *)(m_Head + 12);
      if ( m_Head == 0 )
        goto LABEL_9;
    }
    _Warning(a1: "Tried to install the same listener on the same event id + queue twice!\n");
    goto LABEL_15;
  }
LABEL_9:
  pCallback->AddRef(this: pCallback);
  _InterlockedExchangeAdd(&pEventQueue->m_nRefCount.m_value, 1u);
  v6 = CUtlLinkedList<CEventId::SubscribedQueue_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>>::AllocInternal(
         this: &this->m_SubscribedQueueList,
         multilist: false);
  if ( v6 == nullptr )
  {
LABEL_15:
    v10->m_lockInfo.m_i32 = 0;
    v10->m_writerId = 0;
    return;
  }
  if ( !CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
          (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)this,
          i: (unsigned int)v6,
          it: (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&this->m_SubscribedQueueList.m_LastAlloc) )
  {
    m_pNext = v6[1].m_pNext;
    if ( m_pNext != v6 )
    {
      if ( m_pNext != nullptr )
        m_pNext[1].m_nBlockSize = v6[1].m_nBlockSize;
      else
        this->m_SubscribedQueueList.m_Head = v6[1].m_nBlockSize;
      m_nBlockSize = v6[1].m_nBlockSize;
      if ( m_nBlockSize != 0 )
        *(_DWORD *)(m_nBlockSize + 8) = v6[1].m_pNext;
      else
        this->m_SubscribedQueueList.m_Tail = (int)v6[1].m_pNext;
      v6[1].m_nBlockSize = (int)v6;
      v6[1].m_pNext = v6;
      --this->m_SubscribedQueueList.m_ElementCount;
    }
  }
  v6[1].m_nBlockSize = 0;
  m_Tail = this->m_SubscribedQueueList.m_Tail;
  v6[1].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *)m_Tail;
  this->m_SubscribedQueueList.m_Tail = (int)v6;
  if ( m_Tail != 0 )
    *(_DWORD *)(m_Tail + 12) = v6;
  else
    this->m_SubscribedQueueList.m_Head = (int)v6;
  ++this->m_SubscribedQueueList.m_ElementCount;
  v6->m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *)pEventQueue;
  v6->m_nBlockSize = (int)pCallback;
  v10->m_writerId = 0;
  v10->m_lockInfo.m_i32 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100087E0
// Name: public: virtual void CEventSystem::RegisterListener(struct EventId_t__ __near *,struct EventQueue_t__ __near *,class CFunctorCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventSystem::RegisterListener(
        CEventSystem *this,
        EventId_t__ *nEventId,
        EventQueue_t__ *hQueue,
        CFunctorCallback *pCallback)
{
  if ( hQueue != nullptr && nEventId != nullptr )
    CEventId::RegisterListener(this: (CEventId *)nEventId, pEventQueue: (CEventQueue *)hQueue, pCallback);
  pCallback->Release(this: pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10008810
// Name: public: virtual void CDefaultTSHashConstructor<class CEventId>::Construct(class CEventId __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultTSHashConstructor<CEventId>::Construct(
        CDefaultTSHashConstructor<CEventId> *this,
        CEventId *pElement)
{
  if ( pElement != nullptr )
  {
    pElement->m_SubscribedQueueList.m_Memory.m_pBlocks = nullptr;
    pElement->m_SubscribedQueueList.m_Memory.m_nAllocationCount = 0;
    pElement->m_SubscribedQueueList.m_Memory.m_nGrowSize = 0;
    pElement->m_SubscribedQueueList.m_LastAlloc.m_pBlockHeader = nullptr;
    pElement->m_SubscribedQueueList.m_LastAlloc.m_nIndex = -1;
    pElement->m_SubscribedQueueList.m_Head = 0;
    pElement->m_SubscribedQueueList.m_Tail = 0;
    pElement->m_SubscribedQueueList.m_FirstFree = 0;
    pElement->m_SubscribedQueueList.m_ElementCount = 0;
    pElement->m_SubscribedQueueList.m_NumAlloced = 0;
    pElement->m_SubscribedQueueList.m_pElements = nullptr;
    pElement->m_ListenerLock.m_lockInfo.m_i32 = 0;
    pElement->m_ListenerLock.m_writerId = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008850
// Name: public: void CUtlTSHash<class CEventId,251,unsigned int,class CUtlTSHashGenericHash<251,unsigned int>,8>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::RemoveAll(
        CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8> *this)
{
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8> *v1; // edi
  CThreadSpinRWLock *p_m_AddLock; // ebx
  CEventId *p_m_Data; // eax
  const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *p_m_LastAlloc; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t **v6; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v7; // edi
  int i; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *m_pBlocks; // edi
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *v10; // eax
  bool v11; // zf
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // eax
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *v14; // eax
  int m_nBlockSize; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *v16; // [esp-8h] [ebp-4Ch]
  _DWORD v17[2]; // [esp+18h] [ebp-2Ch] BYREF
  _DWORD v18[2]; // [esp+20h] [ebp-24h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v19; // [esp+28h] [ebp-1Ch]
  int v20; // [esp+2Ch] [ebp-18h]
  CUtlMemoryPool *p_m_EntryMemory; // [esp+30h] [ebp-14h]
  int v22; // [esp+34h] [ebp-10h]
  CThreadSpinRWLock *v23; // [esp+38h] [ebp-Ch]
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::Iterator_t *v24; // [esp+3Ch] [ebp-8h]
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *pElement; // [esp+40h] [ebp-4h]

  v1 = this;
  p_m_EntryMemory = &this->m_EntryMemory;
  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated == 0 )
    return;
  p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
  v23 = &this->m_aBuckets[0].m_AddLock;
  v22 = 251;
  do
  {
    if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
      || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
    {
      CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
    }
    else
    {
      p_m_AddLock->m_writerId = GetCurrentThreadId();
    }
    pElement = (CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashFixedDataInternal_t<CEventId> *)p_m_AddLock[-1].m_writerId;
    if ( pElement != nullptr )
    {
      while ( 1 )
      {
        p_m_Data = &pElement->m_Data;
        p_m_LastAlloc = (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&pElement->m_Data.m_SubscribedQueueList.m_LastAlloc;
        v24 = &pElement->m_Data.m_SubscribedQueueList.m_LastAlloc;
        if ( pElement->m_Data.m_SubscribedQueueList.m_LastAlloc.m_pBlockHeader != nullptr
          || pElement->m_Data.m_SubscribedQueueList.m_LastAlloc.m_nIndex != -1 )
        {
          break;
        }
LABEL_17:
        m_pBlocks = p_m_Data->m_SubscribedQueueList.m_Memory.m_pBlocks;
        if ( p_m_Data->m_SubscribedQueueList.m_Memory.m_pBlocks != nullptr )
        {
          do
          {
            v16 = m_pBlocks;
            m_pBlocks = m_pBlocks->m_pNext;
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
          }
          while ( m_pBlocks != nullptr );
          v10 = pElement;
          pElement->m_Data.m_SubscribedQueueList.m_Memory.m_pBlocks = nullptr;
          v10->m_Data.m_SubscribedQueueList.m_Memory.m_nAllocationCount = 0;
        }
        pElement = pElement->m_pNext;
        if ( pElement == nullptr )
        {
          v1 = (CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8> *)p_m_EntryMemory;
          goto LABEL_22;
        }
      }
      v5 = p_m_Data->m_SubscribedQueueList.m_Memory.m_pBlocks;
      if ( v5 != nullptr )
      {
        v18[0] = v5;
        v18[1] = 0;
        v6 = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t **)v18;
      }
      else
      {
        v17[0] = 0;
        v17[1] = -1;
        v6 = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t **)v17;
      }
      v7 = *v6;
      for ( i = (int)v6[1]; ; i = 0 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            if ( v7 != nullptr )
            {
              if ( i >= 0
                && i < v7->m_nBlockSize
                && &v7[2 * i] != (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)-8 )
              {
                if ( !CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
                        this: (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)&pElement->m_Data,
                        i: (unsigned int)&v7[2 * i + 1],
                        it: p_m_LastAlloc)
                  && (v7[2 * i + 2].m_pNext != &v7[2 * i + 1]
                   || (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)v7[2 * i + 2].m_nBlockSize == &v7[2 * i + 1]) )
                {
                  v14 = pElement;
                  v7[2 * i + 2].m_pNext = &v7[2 * i + 1];
                  v7[2 * i + 2].m_nBlockSize = v14->m_Data.m_SubscribedQueueList.m_FirstFree;
                  v14->m_Data.m_SubscribedQueueList.m_FirstFree = (int)&v7[2 * i + 1];
                }
                p_m_LastAlloc = (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)v24;
              }
            }
            else if ( i == -1 )
            {
              goto LABEL_16;
            }
            if ( v7 == p_m_LastAlloc->m_pBlockHeader && i == p_m_LastAlloc->m_nIndex )
            {
LABEL_16:
              p_m_AddLock = v23;
              p_m_Data = &pElement->m_Data;
              pElement->m_Data.m_SubscribedQueueList.m_Head = 0;
              p_m_Data->m_SubscribedQueueList.m_Tail = 0;
              p_m_Data->m_SubscribedQueueList.m_ElementCount = 0;
              goto LABEL_17;
            }
            if ( v7 != nullptr && i >= 0 )
            {
              m_nBlockSize = v7->m_nBlockSize;
              if ( i < m_nBlockSize )
                break;
            }
            v7 = nullptr;
            i = -1;
            v19 = nullptr;
            v20 = -1;
          }
          if ( ++i >= m_nBlockSize )
            break;
LABEL_44:
          v19 = v7;
          v20 = i;
        }
        v7 = v7->m_pNext;
        if ( v7 == nullptr )
        {
          v7 = nullptr;
          i = -1;
          goto LABEL_44;
        }
        v19 = v7;
        v20 = 0;
      }
    }
LABEL_22:
    p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
    p_m_AddLock[-1].m_writerId = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock += 2;
    v11 = v22-- == 1;
    v23 = p_m_AddLock;
  }
  while ( !v11 );
  p_m_mutex = &v1->m_EntryMemory.m_mutex;
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
  CUtlMemoryPool::Clear(this: p_m_EntryMemory);
  v11 = p_m_mutex->m_depth-- == 1;
  if ( v11 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10008A90
// Name: public: CEventSystem::CEventSystem(void)
// Source: json
//------------------------------------------------------------------------------
CEventSystem *__thiscall CEventSystem::CEventSystem(CEventSystem *this)
{
  CUtlTSHash<CEventId,251,unsigned int,CUtlTSHashGenericHash<251,unsigned int>,8>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  this->__vftable = (CEventSystem_vtbl *)&CEventSystem::`vftable';
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_EventIds.m_EntryMemory,
    blockSize: 64,
    numElements: 256,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 8);
  m_aBuckets = this->m_EventIds.m_aBuckets;
  this->m_EventIds.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_EventIds.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 250;
  p_m_AddLock = &this->m_EventIds.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_EventIds.m_bNeedsCommit = false;
  for ( i = 251; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007860
// Name: __CreateCEventSystemIEventSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEventSystem *__cdecl _CreateCEventSystemIEventSystem_interface()
{
  return &s_EventSystem;
}
