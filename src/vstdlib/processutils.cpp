// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/processutils.cpp
// Functions: 56
// ============================================================

#include "vstdlib\processutils.h"

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: public: void CUtlLinkedList<class CCoroutine,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CCoroutine,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::RemoveAll(
        CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int> > *this)
{
  int m_Head; // ebx
  UtlLinkedListElem_t<CCoroutine,int> *v2; // esi
  int m_Next; // edi
  int m_FirstFree; // eax
  int v5; // eax
  CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int> > *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        if ( v2->m_Element.m_pSavedStack != nullptr )
        {
          free(pMem: v2->m_Element.m_pSavedStack);
          this = v6;
        }
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
// Address: 0x10001280
// Name: public: void CUtlLinkedList<class CCoroutine,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CCoroutine,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::Unlink(
        CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CCoroutine,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
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
// Address: 0x10001300
// Name: protected: int CUtlLinkedList<class CCoroutine,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CCoroutine,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::AllocInternal(
        CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CCoroutine,int> *m_pMemory; // ecx
  int v10; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result;
    if ( multilist )
    {
      m_pMemory[v10].m_Next = -1;
      m_pMemory[v10].m_Previous = -1;
    }
    else
    {
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
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
    CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x100014E0
// Name: public: int CUtlLinkedList<class CCoroutine,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CCoroutine,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::AddToTail(
        CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CCoroutine,int> *m_pMemory; // eax
  unsigned int v5; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<CCoroutine,int> *v7; // esi

  result = CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CCoroutine,int,0,int,CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>>::Unlink(this, elem: result);
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
      v7->m_Element.m_pSavedStack = nullptr;
      v7->m_Element.m_pStackLow = nullptr;
      v7->m_Element.m_pStackHigh = nullptr;
      v7->m_Element.m_cubSavedStack = 0;
      v7->m_Element.m_pFunc = nullptr;
      v7->m_Element.m_pchName = "(none)";
      v7->m_Element.m_iJumpCode = 0;
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100020A0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CEventId::SubscribedQueue_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: 16 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100021F0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CEventId::SubscribedQueue_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CEventId::SubscribedQueue_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[2 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[2 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[2 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10002660
// Name: public: virtual bool CBaseAppSystem<class ICvarQuery>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAppSystem<ICvarQuery>::Connect(
        CBaseAppSystem<ICvarQuery> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002670
// Name: public: virtual void CBaseAppSystem<class ICvarQuery>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseAppSystem<ICvarQuery>::Disconnect()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10002680
// Name: public: virtual enum AppSystemTier_t CTier1AppSystem<class IEventSystem,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier1AppSystem<IEventSystem,0>::GetTier(CBaseAppSystem<ICvarQuery> *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002690
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class ICvar>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<ICvar>::GetTier(CBaseAppSystem<ICvarQuery> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x100026A0
// Name: public: virtual void CBaseAppSystem<class ICvar>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<ICvar>::Reconnect(
        CBaseAppSystem<ICvarQuery> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10002960
// Name: protected: int CUtlLinkedList<struct CConCommandHash::HashEntry_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CConCommandHash::HashEntry_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::AllocInternal(
        CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[1].m_nBlockSize = 0;
      result[1].m_pNext = nullptr;
    }
    else
    {
      result[1].m_nBlockSize = (int)result;
      result[1].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>::Next(
           this: &this->m_Memory,
           result: &v13,
           it: &this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>::Next(
              this: &this->m_Memory,
              result: &v14,
              it: &this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003AB0
// Name: public: void CUtlLinkedList<struct CConCommandHash::HashEntry_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CConCommandHash::HashEntry_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::RemoveAll(
        CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > > *this)
{
  CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>::Next(
                this: &v1->m_Memory,
                &result,
                &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v1 = (CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v1 = (CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == v1->m_LastAlloc.m_pBlockHeader && m_nIndex == v1->m_LastAlloc.m_nIndex )
        break;
    }
    v1->m_Head = 0;
    v1->m_Tail = 0;
    v1->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003B80
// Name: public: void CUtlLinkedList<struct CConCommandHash::HashEntry_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CConCommandHash::HashEntry_t,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::Unlink(
        CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > > *this,
        int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc)
    && *(_DWORD *)(elem + 8) != elem )
  {
    v3 = *(_DWORD *)(elem + 8);
    v4 = *(_DWORD *)(elem + 12);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 12) = v4;
    else
      this->m_Head = v4;
    if ( v4 != 0 )
    {
      *(_DWORD *)(v4 + 8) = v3;
      --this->m_ElementCount;
    }
    else
    {
      --this->m_ElementCount;
      this->m_Tail = v3;
    }
    *(_DWORD *)(elem + 12) = elem;
    *(_DWORD *)(elem + 8) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005AF0
// Name: public: void CUtlLinkedList<struct CConCommandHash::HashEntry_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CConCommandHash::HashEntry_t,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::Purge(
        CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10005B40
// Name: public: void CUtlLinkedList<struct CConCommandHash::HashEntry_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CConCommandHash::HashEntry_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>>::LinkBefore(
        CUtlLinkedList<CConCommandHash::HashEntry_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 8);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Head = *(_DWORD *)(elem + 12);
      v5 = *(_DWORD *)(elem + 12);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Tail = *(_DWORD *)(elem + 8);
      *(_DWORD *)(elem + 12) = elem;
      *(_DWORD *)(elem + 8) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 12) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 8);
    *(_DWORD *)(before + 8) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 8) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 12) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007D40
// Name: protected: int CUtlLinkedList<struct CEventId::SubscribedQueue_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CEventId::SubscribedQueue_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CEventId::SubscribedQueue_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>>::AllocInternal(
        CUtlLinkedList<CEventId::SubscribedQueue_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[1].m_nBlockSize = 0;
      result[1].m_pNext = nullptr;
    }
    else
    {
      result[1].m_nBlockSize = (int)result;
      result[1].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CEventId::SubscribedQueue_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CEventId::SubscribedQueue_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CEventId::SubscribedQueue_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CEventId::SubscribedQueue_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventId::SubscribedQueue_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100080F0
// Name: public: virtual void CTier1AppSystem<class IProcessUtils,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTier1AppSystem<IProcessUtils,0>::Disconnect(CTier1AppSystem<IEventSystem,0> *this)
{
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10008100
// Name: public: virtual enum InitReturnVal_t CTier1AppSystem<class IEventSystem,0>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier1AppSystem<IEventSystem,0>::Init(CTier1AppSystem<IEventSystem,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008120
// Name: public: virtual void CTier1AppSystem<class IEventSystem,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier1AppSystem<IEventSystem,0>::Shutdown(CTier1AppSystem<IEventSystem,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10008F50
// Name: public: virtual class IPipeRead __near * CProcess::GetStdout(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CProcess::GetStdout(CFunctorJob *this)
{
  return this->m_szDescription;
}

//------------------------------------------------------------------------------
// Address: 0x1000D880
// Name: public: int CProcessPipeRead::GetActualProcessOutputSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CProcessPipeRead::GetActualProcessOutputSize(CProcessPipeRead *this)
{
  void *m_hRead; // eax
  DWORD LastError; // eax
  _BYTE *v4; // eax
  const char *v5; // eax
  char buf[512]; // [esp+4h] [ebp-204h] BYREF
  unsigned int dwCount; // [esp+204h] [ebp-4h] BYREF

  m_hRead = this->m_hRead;
  if ( m_hRead == (void *)-1 )
    return 0;
  dwCount = 0;
  if ( !PeekNamedPipe(
          hNamedPipe: m_hRead,
          lpBuffer: nullptr,
          nBufferSize: 0,
          lpBytesRead: nullptr,
          lpTotalBytesAvail: &dwCount,
          lpBytesLeftThisMessage: nullptr) )
  {
    LastError = GetLastError();
    FormatMessageA(
      dwFlags: 0x1000u,
      lpSource: nullptr,
      dwMessageId: LastError,
      dwLanguageId: 0,
      lpBuffer: buf,
      nSize: 0x200u,
      Arguments: nullptr);
    strchr(string: (unsigned __int8 *)buf, chr: 0xDu);
    if ( v4 != nullptr )
      *v4 = 0;
    v5 = CUtlString::Get(this: &this->m_pProcess->m_Info.m_CommandLine);
    _Warning(
      a1: "Could not read from pipe associated with command %s\nWindows gave the error message:\n   \"%s\"\n",
      v5,
      buf);
    return 0;
  }
  return dwCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000D920
// Name: public: virtual void CProcess::Abort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProcess::Abort(CProcess *this)
{
  if ( !this->IsComplete(this) )
    TerminateProcess(hProcess: this->m_Info.m_hProcess, uExitCode: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1000D940
// Name: public: virtual bool CProcess::IsComplete(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CProcess::IsComplete(CProcess *this)
{
  return WaitForSingleObject(hHandle: this->m_Info.m_hProcess, dwMilliseconds: 0) != 258;
}

//------------------------------------------------------------------------------
// Address: 0x1000D960
// Name: public: virtual int CProcess::WriteStdin(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CProcess::WriteStdin(CProcess *this, char *pBuf, DWORD nBufLen)
{
  void *m_hChildStdinWr; // eax
  BOOL v5; // eax
  unsigned int nBytesWritten; // [esp+0h] [ebp-4h] BYREF

  nBytesWritten = (unsigned int)this;
  m_hChildStdinWr = this->m_Info.m_hChildStdinWr;
  if ( m_hChildStdinWr == (void *)-1 )
    return 0;
  nBytesWritten = 0;
  v5 = WriteFile(
         hFile: m_hChildStdinWr,
         lpBuffer: pBuf,
         nNumberOfBytesToWrite: nBufLen,
         lpNumberOfBytesWritten: &nBytesWritten,
         lpOverlapped: nullptr);
  return v5 ? nBytesWritten : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D9A0
// Name: public: virtual class IPipeRead __near * CProcess::GetStderr(void)
// Source: json
//------------------------------------------------------------------------------
CProcessPipeRead *__thiscall CProcess::GetStderr(CProcess *this)
{
  return &this->m_StderrRead;
}

//------------------------------------------------------------------------------
// Address: 0x1000D9B0
// Name: public: virtual int CProcess::GetExitCode(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CProcess::GetExitCode(CProcess *this)
{
  unsigned int result; // eax
  unsigned int nExitCode; // [esp+0h] [ebp-4h] BYREF

  nExitCode = (unsigned int)this;
  if ( !GetExitCodeProcess(hProcess: this->m_Info.m_hProcess, lpExitCode: &nExitCode) )
    return -1;
  result = nExitCode;
  if ( nExitCode == 259 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D9E0
// Name: public: virtual int CProcessUtils::SimpleRunProcess(char const __near *,char const __near *,class CUtlString __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProcessUtils::SimpleRunProcess(
        CProcessUtils *this,
        const char *pCommandLine,
        const char *pWorkingDir,
        CUtlString *pStdout)
{
  IProcess *v4; // esi
  int v6; // ebx
  int v7; // eax

  v4 = this->StartProcess_2(this, a2: pCommandLine, a3: pStdout != nullptr, a4: pWorkingDir);
  if ( v4 == nullptr )
    return -1;
  v6 = v4->WaitUntilComplete(this: v4);
  if ( pStdout != nullptr )
  {
    v7 = (int)v4->GetStdout(this: v4);
    (*(void (__thiscall **)(int, CUtlString *, int))(*(_DWORD *)v7 + 16))(a1: v7, a2: pStdout, a3: 0x7FFFFFFF);
  }
  v4->Release(this: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1000DA50
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<class CProcess __near *,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 3;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: 12 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DAE0
// Name: public: virtual int CProcessPipeRead::GetNumBytesAvailable(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CProcessPipeRead::GetNumBytesAvailable(CProcessPipeRead *this)
{
  int m_Put; // esi

  m_Put = this->m_CachedOutput.m_Put;
  return m_Put + CProcessPipeRead::GetActualProcessOutputSize(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000DAF0
// Name: public: bool CProcessPipeRead::WaitForOutput(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CProcessPipeRead::WaitForOutput(CProcessPipeRead *this)
{
  void *m_hRead; // eax
  DWORD LastError; // eax
  _BYTE *v5; // eax
  const char *v6; // eax
  char Buffer[512]; // [esp+4h] [ebp-204h] BYREF
  unsigned int TotalBytesAvail; // [esp+204h] [ebp-4h] BYREF

  if ( this->m_hRead == (void *)-1 )
    return 0;
  while ( 1 )
  {
    m_hRead = this->m_hRead;
    if ( m_hRead != (void *)-1 )
    {
      TotalBytesAvail = 0;
      if ( PeekNamedPipe(
             hNamedPipe: m_hRead,
             lpBuffer: nullptr,
             nBufferSize: 0,
             lpBytesRead: nullptr,
             lpTotalBytesAvail: &TotalBytesAvail,
             lpBytesLeftThisMessage: nullptr) )
      {
        break;
      }
      LastError = GetLastError();
      FormatMessageA(
        dwFlags: 0x1000u,
        lpSource: nullptr,
        dwMessageId: LastError,
        dwLanguageId: 0,
        lpBuffer: Buffer,
        nSize: 0x200u,
        Arguments: nullptr);
      strchr(string: (unsigned __int8 *)Buffer, chr: 0xDu);
      if ( v5 != nullptr )
        *v5 = 0;
      v6 = CUtlString::Get(this: &this->m_pProcess->m_Info.m_CommandLine);
      _Warning(
        a1: "Could not read from pipe associated with command %s\nWindows gave the error message:\n   \"%s\"\n",
        v6,
        Buffer);
    }
LABEL_9:
    if ( this->m_pProcess->IsComplete(this: this->m_pProcess) )
      return 0;
    _ThreadSleep(a1: 1);
  }
  if ( TotalBytesAvail == 0 )
    goto LABEL_9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DBD0
// Name: public: void CProcessPipeRead::CacheOutput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProcessPipeRead::CacheOutput(CProcessPipeRead *this)
{
  DWORD ActualProcessOutputSize; // ebx
  CUtlBuffer *p_m_CachedOutput; // esi
  void *m_hRead; // edi
  unsigned __int8 *v5; // [esp-14h] [ebp-24h]
  int nPut; // [esp+8h] [ebp-8h]
  unsigned int NumberOfBytesRead; // [esp+Ch] [ebp-4h] BYREF

  ActualProcessOutputSize = CProcessPipeRead::GetActualProcessOutputSize(this);
  if ( ActualProcessOutputSize != 0 )
  {
    nPut = this->m_CachedOutput.m_Put;
    p_m_CachedOutput = &this->m_CachedOutput;
    CUtlBuffer::EnsureCapacity(this: &this->m_CachedOutput, num: ActualProcessOutputSize + nPut);
    m_hRead = this->m_hRead;
    if ( m_hRead == (void *)-1 )
    {
      CUtlBuffer::SeekPut(this: p_m_CachedOutput, type: SEEK_HEAD, offset: nPut);
    }
    else
    {
      v5 = &p_m_CachedOutput->m_Memory.m_pMemory[p_m_CachedOutput->m_Put - p_m_CachedOutput->m_nOffset];
      NumberOfBytesRead = 0;
      ReadFile(
        hFile: m_hRead,
        lpBuffer: v5,
        nNumberOfBytesToRead: ActualProcessOutputSize,
        lpNumberOfBytesRead: &NumberOfBytesRead,
        lpOverlapped: nullptr);
      CUtlBuffer::SeekPut(this: p_m_CachedOutput, type: SEEK_HEAD, offset: nPut + NumberOfBytesRead);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DC50
// Name: public: virtual int CProcess::WaitUntilComplete(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProcess::WaitUntilComplete(CProcess *this)
{
  CProcess *v1; // ebx
  CProcessPipeRead *p_m_StdoutRead; // esi
  int ActualProcessOutputSize; // eax
  DWORD v5; // edi
  int m_Put; // ebx
  void *m_hRead; // eax
  unsigned int v8; // eax
  unsigned __int8 *v9; // [esp-18h] [ebp-24h]
  unsigned int NumberOfBytesRead; // [esp+8h] [ebp-4h] BYREF

  v1 = this;
  if ( this->m_Info.m_hChildStdoutRd == (void *)-1 )
  {
    WaitForSingleObject(hHandle: this->m_Info.m_hProcess, dwMilliseconds: 0xFFFFFFFF);
    return v1->GetExitCode(this: v1);
  }
  else
  {
    if ( WaitForSingleObject(hHandle: this->m_Info.m_hProcess, dwMilliseconds: 0x32u) == 258 )
    {
      do
      {
        p_m_StdoutRead = &v1->m_StdoutRead;
        ActualProcessOutputSize = CProcessPipeRead::GetActualProcessOutputSize(this: &v1->m_StdoutRead);
        v5 = ActualProcessOutputSize;
        if ( ActualProcessOutputSize != 0 )
        {
          m_Put = v1->m_StdoutRead.m_CachedOutput.m_Put;
          CUtlBuffer::EnsureCapacity(this: &p_m_StdoutRead->m_CachedOutput, num: m_Put + ActualProcessOutputSize);
          m_hRead = this->m_StdoutRead.m_hRead;
          if ( m_hRead == (void *)-1 )
          {
            v8 = 0;
          }
          else
          {
            v9 = &p_m_StdoutRead->m_CachedOutput.m_Memory.m_pMemory[p_m_StdoutRead->m_CachedOutput.m_Put
                                                                  - p_m_StdoutRead->m_CachedOutput.m_nOffset];
            NumberOfBytesRead = 0;
            ReadFile(
              hFile: m_hRead,
              lpBuffer: v9,
              nNumberOfBytesToRead: v5,
              lpNumberOfBytesRead: &NumberOfBytesRead,
              lpOverlapped: nullptr);
            v8 = NumberOfBytesRead;
          }
          CUtlBuffer::SeekPut(this: &p_m_StdoutRead->m_CachedOutput, type: SEEK_HEAD, offset: m_Put + v8);
          v1 = this;
        }
        if ( v1->m_StderrRead.m_hRead != (void *)-1 )
          CProcessPipeRead::CacheOutput(this: &v1->m_StderrRead);
      }
      while ( WaitForSingleObject(hHandle: v1->m_Info.m_hProcess, dwMilliseconds: 0x32u) == 258 );
    }
    return v1->GetExitCode(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DD30
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CConCommandHash::HashEntry_t,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CConCommandHash::HashEntry_t,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CConCommandHash::HashEntry_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *(CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)m_pBlockHeader;
      result->m_nIndex = m_nIndex + 1;
      return result;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DDB0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<class CProcess __near *,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CProcess __near *,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 12 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 12 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 12 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE30
// Name: public: virtual void __near * CBaseAppSystem<class IProcessUtils>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseAppSystem<IProcessUtils>::QueryInterface(
        CBaseAppSystem<IEventSystem> *this,
        const char *pInterfaceName)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE40
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class ICvar>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<ICvar>::GetDependencies(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE50
// Name: public: int CProcessPipeRead::GetProcessOutput(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProcessPipeRead::GetProcessOutput(CProcessPipeRead *this, unsigned __int8 *pBuf, int nBytes)
{
  int m_Put; // edi
  DWORD v4; // ebx
  CUtlBuffer *p_m_CachedOutput; // esi
  void *m_hRead; // eax

  m_Put = this->m_CachedOutput.m_Put;
  if ( nBytes < m_Put )
    m_Put = nBytes;
  v4 = nBytes - m_Put;
  p_m_CachedOutput = &this->m_CachedOutput;
  CUtlBuffer::Get(this: &this->m_CachedOutput, pMem: pBuf, size: m_Put);
  if ( p_m_CachedOutput->m_nMaxPut == p_m_CachedOutput->m_Get )
  {
    p_m_CachedOutput->m_Get = 0;
    p_m_CachedOutput->m_Put = 0;
    p_m_CachedOutput->m_nOffset = 0;
    p_m_CachedOutput->m_nMaxPut = 0;
    p_m_CachedOutput->m_Error = 0;
    if ( p_m_CachedOutput->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_CachedOutput->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_CachedOutput->m_Memory.m_pMemory);
        p_m_CachedOutput->m_Memory.m_pMemory = nullptr;
      }
      p_m_CachedOutput->m_Memory.m_nAllocationCount = 0;
    }
  }
  m_hRead = this->m_hRead;
  if ( m_hRead == (void *)-1 || v4 == 0 )
    return m_Put;
  nBytes = 0;
  ReadFile(
    hFile: m_hRead,
    lpBuffer: &pBuf[m_Put],
    nNumberOfBytesToRead: v4,
    lpNumberOfBytesRead: (LPDWORD)&nBytes,
    lpOverlapped: nullptr);
  return m_Put + nBytes;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF00
// Name: public: virtual enum InitReturnVal_t CProcessUtils::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProcessUtils::Init(CProcessUtils *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  this->m_bInitialized = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF30
// Name: public: virtual void CProcessUtils::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProcessUtils::Shutdown(CProcessUtils *this)
{
  while ( this->m_Processes.m_ElementCount > 0 )
    (***(void (__thiscall ****)(_DWORD))this->m_Processes.m_Head)(a1: *(_DWORD *)this->m_Processes.m_Head);
  this->m_bInitialized = false;
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x1000DF70
// Name: protected: int CUtlLinkedList<class CProcess __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CProcess __near *,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::AllocInternal(
        CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 8);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 8) = 0;
      *(_DWORD *)(result + 4) = 0;
    }
    else
    {
      *(_DWORD *)(result + 8) = result;
      *(_DWORD *)(result + 4) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 12 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E100
// Name: public: virtual void CProcessPipeRead::ReadAvailable(class CUtlString __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProcessPipeRead::ReadAvailable(CProcessPipeRead *this, CUtlString *sStr, int nMaxBytes)
{
  int v4; // esi
  unsigned __int8 *v5; // edi

  v4 = this->GetNumBytesAvailable(this);
  if ( v4 >= nMaxBytes )
    v4 = nMaxBytes;
  CUtlString::SetLength(this: sStr, nLen: v4);
  if ( v4 > 0 )
  {
    v5 = (unsigned __int8 *)CUtlString::Get(this: sStr);
    v5[CProcessPipeRead::GetProcessOutput(this, pBuf: v5, nBytes: v4)] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E150
// Name: public: virtual void CProcessPipeRead::ReadAvailable(class CUtlBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProcessPipeRead::ReadAvailable(CProcessPipeRead *this, CUtlBuffer *pOutBuffer, int nMaxBytes)
{
  int v3; // esi
  unsigned __int8 *m_pMemory; // ebx

  v3 = ((int (__fastcall *)(CProcessPipeRead *))this->GetNumBytesAvailable)(a1: this);
  if ( v3 >= nMaxBytes )
    v3 = nMaxBytes;
  if ( v3 > 0 )
  {
    CUtlBuffer::EnsureCapacity(this: pOutBuffer, num: v3 + 1);
    pOutBuffer->m_nMaxPut = v3 + 1;
    m_pMemory = pOutBuffer->m_Memory.m_pMemory;
    m_pMemory[CProcessPipeRead::GetProcessOutput(this, pBuf: pOutBuffer->m_Memory.m_pMemory, nBytes: v3)] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E1A0
// Name: public: virtual void CProcessPipeRead::ReadLine(class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProcessPipeRead::ReadLine(CProcessPipeRead *this, CUtlString *sStr)
{
  CProcessPipeRead *v2; // edi
  CUtlBuffer *p_m_CachedOutput; // esi
  const char *v4; // ebx
  int v5; // edi
  CUtlString sTemp; // [esp+Ch] [ebp-18h] BYREF
  int nBytes; // [esp+1Ch] [ebp-8h]
  int nBytesToRead; // [esp+20h] [ebp-4h]

  v2 = this;
  nBytesToRead = (int)this;
  CUtlString::SetLength(this: sStr, nLen: 0);
  p_m_CachedOutput = &v2->m_CachedOutput;
  while ( p_m_CachedOutput->m_nMaxPut != p_m_CachedOutput->m_Get || CProcessPipeRead::WaitForOutput(this: v2) != 0 )
  {
    CProcessPipeRead::CacheOutput(this: v2);
    v4 = (const char *)&p_m_CachedOutput->m_Memory.m_pMemory[p_m_CachedOutput->m_Get - p_m_CachedOutput->m_nOffset];
    nBytes = p_m_CachedOutput->m_nMaxPut - p_m_CachedOutput->m_Get;
    if ( nBytes == 0 && v2->m_pProcess->IsComplete(this: v2->m_pProcess) )
      break;
    v5 = 0;
    if ( nBytes > 0 )
    {
      while ( v4[v5] != 10 )
      {
        if ( ++v5 >= nBytes )
          goto LABEL_2;
      }
      if ( v5 < nBytes )
      {
        nBytesToRead = v5;
        if ( v5 > 0 && v4[v5 - 1] == 13 )
          nBytesToRead = v5 - 1;
        CUtlString::CUtlString(this: &sTemp);
        CUtlString::SetDirect(this: &sTemp, pValue: v4, nChars: nBytesToRead);
        CUtlString::operator+=(this: sStr, rhs: &sTemp);
        CUtlBuffer::SeekGet(this: p_m_CachedOutput, type: SEEK_CURRENT, offset: v5 + 1);
        if ( p_m_CachedOutput->m_nMaxPut == p_m_CachedOutput->m_Get )
        {
          p_m_CachedOutput->m_Get = 0;
          p_m_CachedOutput->m_Put = 0;
          p_m_CachedOutput->m_nOffset = 0;
          p_m_CachedOutput->m_nMaxPut = 0;
          p_m_CachedOutput->m_Error = 0;
          if ( p_m_CachedOutput->m_Memory.m_nGrowSize >= 0 )
          {
            if ( p_m_CachedOutput->m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_CachedOutput->m_Memory.m_pMemory);
              p_m_CachedOutput->m_Memory.m_pMemory = nullptr;
            }
            p_m_CachedOutput->m_Memory.m_nAllocationCount = 0;
          }
        }
        sTemp.m_Storage.m_nActualLength = 0;
        if ( sTemp.m_Storage.m_Memory.m_nGrowSize >= 0 && sTemp.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sTemp.m_Storage.m_Memory.m_pMemory);
        return;
      }
    }
LABEL_2:
    v2 = (CProcessPipeRead *)nBytesToRead;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E2D0
// Name: public: ProcessInfo_t::~ProcessInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ProcessInfo_t::~ProcessInfo_t(ProcessInfo_t *this)
{
  bool v2; // sf

  v2 = this->m_CommandLine.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_CommandLine.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_CommandLine.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CommandLine.m_Storage.m_Memory.m_pMemory);
      this->m_CommandLine.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_CommandLine.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E310
// Name: public: virtual class IProcess __near * CProcessUtils::StartProcess(int,char const __near * __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IProcess *__thiscall CProcessUtils::StartProcess(
        CProcessUtils *this,
        int argc,
        const char **argv,
        int fFlags,
        const char *pWorkingDir)
{
  CProcessUtils *v5; // ebx
  int v6; // esi
  CProcessUtils_vtbl *v7; // esi
  char *v8; // eax
  int v9; // esi
  CUtlString commandLine; // [esp+Ch] [ebp-14h] BYREF
  CProcessUtils *v12; // [esp+1Ch] [ebp-4h]

  v5 = this;
  v12 = this;
  CUtlString::CUtlString(this: &commandLine);
  v6 = 0;
  if ( argc > 0 )
  {
    do
    {
      CUtlString::operator+=(this: &commandLine, rhs: argv[v6]);
      if ( v6 != argc - 1 )
        CUtlString::operator+=(this: &commandLine, rhs: " ");
      ++v6;
    }
    while ( v6 < argc );
    v5 = v12;
  }
  v7 = v5->__vftable;
  v8 = CUtlString::Get(this: &commandLine);
  v9 = (int)v7->StartProcess_2(this: v5, a2: v8, a3: fFlags, a4: pWorkingDir);
  commandLine.m_Storage.m_nActualLength = 0;
  if ( commandLine.m_Storage.m_Memory.m_nGrowSize >= 0 && commandLine.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: commandLine.m_Storage.m_Memory.m_pMemory);
  return (IProcess *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x1000E3B0
// Name: public: void CUtlLinkedList<class CProcess __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CProcess __near *,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::RemoveAll(
        CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)((char *)m_pBlockHeader
                                                                                      + 12 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[1] + 12 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t **)&m_pBlockHeader[1].m_nBlockSize
               + 3 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 12 * m_nIndex)
            && *(&m_pBlockHeader[2].m_pNext + 3 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 12 * m_nIndex) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[1].m_nBlockSize + 3 * m_nIndex) = (int)m_pBlockHeader + 12 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[2].m_pNext + 3 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 12 * m_nIndex;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CConCommandHash::HashEntry_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
      {
        break;
      }
    }
    v1[1].m_pBlocks = nullptr;
    v1[1].m_nAllocationCount = 0;
    v1[2].m_pBlocks = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E480
// Name: public: virtual bool CTier1AppSystem<class IEventSystem,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier1AppSystem<IEventSystem,0>::Connect(
        CTier1AppSystem<IEventSystem,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E4A0
// Name: public: virtual void CProcessPipeRead::Read(class CUtlString __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProcessPipeRead::Read(CProcessPipeRead *this, CUtlString *sStr, int nBytes)
{
  int v4; // ebx
  int v5; // eax
  int v6; // edi
  CUtlString sTemp; // [esp+8h] [ebp-10h] BYREF

  CUtlString::SetLength(this: sStr, nLen: 0);
  v4 = nBytes;
  while ( v4 > 0 )
  {
    v5 = this->GetNumBytesAvailable(this);
    if ( v5 != 0 )
    {
      v6 = v4;
      if ( v4 >= v5 )
        v6 = v5;
      CUtlString::CUtlString(this: &sTemp);
      this->ReadAvailable_2(this, a2: &sTemp, a3: v6);
      CUtlString::operator+=(this: sStr, rhs: &sTemp);
      v4 -= v6;
      sTemp.m_Storage.m_nActualLength = 0;
      if ( sTemp.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( sTemp.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sTemp.m_Storage.m_Memory.m_pMemory);
          sTemp.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        sTemp.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
    else
    {
      if ( this->m_pProcess->IsComplete(this: this->m_pProcess) )
        return;
      CProcessPipeRead::WaitForOutput(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E550
// Name: public: CProcess::~CProcess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProcess::~CProcess(CProcess *this)
{
  if ( this->m_StderrRead.m_CachedOutput.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_StderrRead.m_CachedOutput.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StderrRead.m_CachedOutput.m_Memory.m_pMemory);
      this->m_StderrRead.m_CachedOutput.m_Memory.m_pMemory = nullptr;
    }
    this->m_StderrRead.m_CachedOutput.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_StdoutRead.m_CachedOutput.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_StdoutRead.m_CachedOutput.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StdoutRead.m_CachedOutput.m_Memory.m_pMemory);
      this->m_StdoutRead.m_CachedOutput.m_Memory.m_pMemory = nullptr;
    }
    this->m_StdoutRead.m_CachedOutput.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Info.m_CommandLine.m_Storage.m_nActualLength = 0;
  if ( this->m_Info.m_CommandLine.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Info.m_CommandLine.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Info.m_CommandLine.m_Storage.m_Memory.m_pMemory);
      this->m_Info.m_CommandLine.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Info.m_CommandLine.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E5D0
// Name: public: void CUtlLinkedList<class CProcess __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CProcess __near *,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::Free(
        CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 4);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Head = *(_DWORD *)(elem + 8);
      v4 = *(_DWORD *)(elem + 8);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 4) = *(_DWORD *)(elem + 4);
      else
        this->m_Tail = *(_DWORD *)(elem + 4);
      *(_DWORD *)(elem + 8) = elem;
      *(_DWORD *)(elem + 4) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 8) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000E640
// Name: public: void CUtlLinkedList<class CProcess __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CProcess __near *,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::LinkBefore(
        CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 4);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Head = *(_DWORD *)(elem + 8);
      v5 = *(_DWORD *)(elem + 8);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 4) = *(_DWORD *)(elem + 4);
      else
        this->m_Tail = *(_DWORD *)(elem + 4);
      *(_DWORD *)(elem + 8) = elem;
      *(_DWORD *)(elem + 4) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 8) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 4);
    *(_DWORD *)(before + 4) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 4) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 8) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E6D0
// Name: public: CProcess::CProcess(class CProcessUtils __near *,struct ProcessInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CProcess *__thiscall CProcess::CProcess(CProcess *this, CProcessUtils *pProcessUtils, const ProcessInfo_t *info)
{
  this->__vftable = (CProcess_vtbl *)&CProcess::`vftable';
  CUtlString::CUtlString(this: &this->m_Info.m_CommandLine);
  this->m_StdoutRead.__vftable = (CProcessPipeRead_vtbl *)&CProcessPipeRead::`vftable';
  CUtlBuffer::CUtlBuffer(this: &this->m_StdoutRead.m_CachedOutput, growSize: 0, initSize: 0, nFlags: 0);
  this->m_StderrRead.__vftable = (CProcessPipeRead_vtbl *)&CProcessPipeRead::`vftable';
  CUtlBuffer::CUtlBuffer(this: &this->m_StderrRead.m_CachedOutput, growSize: 0, initSize: 0, nFlags: 0);
  this->m_pProcessUtils = pProcessUtils;
  this->m_Info.m_hChildStdinRd = info->m_hChildStdinRd;
  this->m_Info.m_hChildStdinWr = info->m_hChildStdinWr;
  this->m_Info.m_hChildStdoutRd = info->m_hChildStdoutRd;
  this->m_Info.m_hChildStdoutWr = info->m_hChildStdoutWr;
  this->m_Info.m_hChildStderrRd = info->m_hChildStderrRd;
  this->m_Info.m_hChildStderrWr = info->m_hChildStderrWr;
  this->m_Info.m_hProcess = info->m_hProcess;
  CUtlString::operator=(this: &this->m_Info.m_CommandLine, src: &info->m_CommandLine);
  this->m_Info.m_fFlags = info->m_fFlags;
  this->m_StdoutRead.m_pProcess = this;
  this->m_StdoutRead.m_hRead = info->m_hChildStdoutRd;
  this->m_StderrRead.m_pProcess = this;
  this->m_StderrRead.m_hRead = info->m_hChildStderrRd;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E770
// Name: public: virtual void CProcess::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProcess::Release(CProcess *this)
{
  if ( (this->m_Info.m_fFlags & 8) == 0 )
    this->Abort(this);
  CloseHandle(hObject: this->m_Info.m_hChildStderrRd);
  CloseHandle(hObject: this->m_Info.m_hChildStderrWr);
  CloseHandle(hObject: this->m_Info.m_hChildStdinRd);
  CloseHandle(hObject: this->m_Info.m_hChildStdinWr);
  CloseHandle(hObject: this->m_Info.m_hChildStdoutRd);
  CloseHandle(hObject: this->m_Info.m_hChildStdoutWr);
  CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::Free(
    this: &this->m_pProcessUtils->m_Processes,
    elem: this->m_nProcessesIndex);
  CProcess::~CProcess(this);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x1000E7E0
// Name: private: class CProcess __near * CProcessUtils::CreateProcessA(struct ProcessInfo_t __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CProcess *__thiscall CProcessUtils::CreateProcessA(
        CProcessUtils *this,
        ProcessInfo_t *info,
        char fFlags,
        const char *pWorkingDir)
{
  void *m_hChildStderrWr; // eax
  void *m_hChildStdoutWr; // edx
  int v7; // eax
  char *v8; // eax
  CProcess *v9; // eax
  CProcess *v10; // ebx
  int v11; // eax
  CProcess **v12; // esi
  DWORD LastError; // eax
  _BYTE *v15; // eax
  const char *v16; // eax
  DWORD v17; // [esp-14h] [ebp-274h]
  char buf[512]; // [esp+Ch] [ebp-254h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+20Ch] [ebp-54h] BYREF
  _PROCESS_INFORMATION pi; // [esp+250h] [ebp-10h] BYREF

  memset(dst: (int)&StartupInfo, value: 0, count: sizeof(StartupInfo));
  StartupInfo.cb = 68;
  if ( (fFlags & 1) != 0 )
  {
    m_hChildStderrWr = info->m_hChildStderrWr;
    StartupInfo.hStdInput = info->m_hChildStdinRd;
    m_hChildStdoutWr = info->m_hChildStdoutWr;
    StartupInfo.dwFlags = 256;
    StartupInfo.hStdError = m_hChildStderrWr;
    StartupInfo.hStdOutput = m_hChildStdoutWr;
  }
  v7 = 0;
  if ( (fFlags & 2) == 0 )
    v7 = 8;
  v17 = v7;
  v8 = CUtlString::Get(this: &info->m_CommandLine);
  if ( CreateProcessA(
         lpApplicationName: nullptr,
         lpCommandLine: v8,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: true,
         dwCreationFlags: v17,
         lpEnvironment: nullptr,
         lpCurrentDirectory: pWorkingDir,
         lpStartupInfo: &StartupInfo,
         lpProcessInformation: &pi) )
  {
    info->m_hProcess = pi.hProcess;
    v9 = (CProcess *)operator new(nSize: 0xB4u);
    if ( v9 != nullptr )
      v10 = CProcess::CProcess(this: v9, pProcessUtils: this, info);
    else
      v10 = nullptr;
    v11 = CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::AllocInternal(
            this: &this->m_Processes,
            multilist: false);
    v12 = (CProcess **)v11;
    if ( v11 != 0 )
    {
      CUtlLinkedList<CProcess *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CProcess *,int>>>::LinkBefore(
        this: &this->m_Processes,
        before: 0,
        elem: v11);
      *v12 = v10;
      v10->m_nProcessesIndex = (int)v12;
    }
    else
    {
      v10->m_nProcessesIndex = 0;
    }
    return v10;
  }
  else
  {
    LastError = GetLastError();
    FormatMessageA(
      dwFlags: 0x1000u,
      lpSource: nullptr,
      dwMessageId: LastError,
      dwLanguageId: 0,
      lpBuffer: buf,
      nSize: 0x200u,
      Arguments: nullptr);
    strchr(string: (unsigned __int8 *)buf, chr: 0xDu);
    if ( v15 != nullptr )
      *v15 = 0;
    v16 = CUtlString::Get(this: &info->m_CommandLine);
    _Warning(a1: "Could not execute the command:\n   %s\nWindows gave the error message:\n   \"%s\"\n", v16, buf);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E930
// Name: public: virtual class IProcess __near * CProcessUtils::StartProcess(char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CProcess *__thiscall CProcessUtils::StartProcess(
        CProcessUtils *this,
        const char *pCommandLine,
        char fFlags,
        const char *pWorkingDir)
{
  CProcess *v5; // esi
  DWORD v7; // esi
  BOOL v8; // eax
  HANDLE v9; // eax
  CProcess *v10; // esi
  void (__stdcall *v11)(HANDLE); // esi
  void *m_hChildStdoutWr; // [esp-1Ch] [ebp-64h]
  HANDLE CurrentProcess; // [esp-18h] [ebp-60h]
  ProcessInfo_t info; // [esp+8h] [ebp-40h] BYREF
  _SECURITY_ATTRIBUTES saAttr; // [esp+38h] [ebp-10h] BYREF
  CProcessUtils *v16; // [esp+44h] [ebp-4h]

  v16 = this;
  CUtlString::CUtlString(this: &info.m_CommandLine);
  CUtlString::operator=(this: &info.m_CommandLine, src: pCommandLine);
  if ( (fFlags & 1) != 0 )
  {
    v7 = 0;
    saAttr.nLength = 12;
    saAttr.bInheritHandle = 1;
    saAttr.lpSecurityDescriptor = nullptr;
    if ( (fFlags & 0x10) != 0 )
      v7 = 0x100000;
    if ( CreatePipe(
           hReadPipe: &info.m_hChildStdoutRd,
           hWritePipe: &info.m_hChildStdoutWr,
           lpPipeAttributes: &saAttr,
           nSize: v7) )
    {
      if ( CreatePipe(
             hReadPipe: &info.m_hChildStdinRd,
             hWritePipe: &info.m_hChildStdinWr,
             lpPipeAttributes: &saAttr,
             nSize: v7) )
      {
        if ( (fFlags & 4) != 0 )
        {
          v8 = CreatePipe(
                 hReadPipe: &info.m_hChildStderrRd,
                 hWritePipe: &info.m_hChildStderrWr,
                 lpPipeAttributes: &saAttr,
                 nSize: v7);
        }
        else
        {
          CurrentProcess = GetCurrentProcess();
          m_hChildStdoutWr = info.m_hChildStdoutWr;
          v9 = GetCurrentProcess();
          v8 = DuplicateHandle(
                 hSourceProcessHandle: v9,
                 hSourceHandle: m_hChildStdoutWr,
                 hTargetProcessHandle: CurrentProcess,
                 lpTargetHandle: &info.m_hChildStderrWr,
                 dwDesiredAccess: 0,
                 bInheritHandle: true,
                 dwOptions: 2u);
          info.m_hChildStderrRd = (void *)-1;
        }
        if ( v8 )
        {
          v10 = CProcessUtils::CreateProcessA(this: v16, &info, fFlags, pWorkingDir);
          if ( v10 != nullptr )
          {
            ProcessInfo_t::~ProcessInfo_t(this: &info);
            return v10;
          }
          v11 = (void (__stdcall *)(HANDLE))CloseHandle;
          CloseHandle(hObject: info.m_hChildStderrRd);
          CloseHandle(hObject: info.m_hChildStderrWr);
          CloseHandle(hObject: info.m_hChildStdinRd);
          CloseHandle(hObject: info.m_hChildStdinWr);
        }
        else
        {
          v11 = (void (__stdcall *)(HANDLE))CloseHandle;
          CloseHandle(hObject: info.m_hChildStdinRd);
          CloseHandle(hObject: info.m_hChildStdinWr);
        }
      }
      else
      {
        v11 = (void (__stdcall *)(HANDLE))CloseHandle;
      }
      v11(hObject: info.m_hChildStdoutRd);
      v11(hObject: info.m_hChildStdoutWr);
    }
    info.m_CommandLine.m_Storage.m_nActualLength = 0;
    if ( info.m_CommandLine.m_Storage.m_Memory.m_nGrowSize >= 0
      && info.m_CommandLine.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: info.m_CommandLine.m_Storage.m_Memory.m_pMemory);
    }
    return nullptr;
  }
  else
  {
    memset(&info, 255, 24);
    v5 = CProcessUtils::CreateProcessA(this, &info, fFlags, pWorkingDir);
    info.m_CommandLine.m_Storage.m_nActualLength = 0;
    if ( info.m_CommandLine.m_Storage.m_Memory.m_nGrowSize >= 0
      && info.m_CommandLine.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: info.m_CommandLine.m_Storage.m_Memory.m_pMemory);
    }
    return v5;
  }
}
